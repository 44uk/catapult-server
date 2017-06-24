#include "catapult/consumers/BlockConsumers.h"
#include "catapult/consumers/TransactionConsumers.h"
#include "tests/catapult/consumers/utils/ConsumerTestUtils.h"
#include "tests/test/core/BlockTestUtils.h"
#include "tests/test/nodeps/ParamsCapture.h"
#include "tests/TestHarness.h"

namespace catapult { namespace consumers {

	namespace {
		constexpr auto Default_Options = HashCheckOptions(600'000, 60'000, 1'000);

		std::function<Timestamp ()> CreateTimeGenerator(const std::vector<Timestamp::ValueType>& times) {
			size_t index = 0;
			return [times, index]() mutable {
				auto timestamp = Timestamp(times[index] * 1000);
				if (index + 1 < times.size())
					++index;

				return timestamp;
			};
		}

		struct BlockTraits {
			static auto CreateSingleEntityElements() {
				return test::CreateBlockElements(1);
			}

			static auto CreateConsumer(const std::function<Timestamp ()>& timeGenerator, const HashCheckOptions& options) {
				return CreateBlockHashCheckConsumer(timeGenerator, options);
			}

			static void AssertContinued(ConsumerResult result, const disruptor::BlockElements& elements) {
				test::AssertContinued(result);
				EXPECT_EQ(1u, elements.size());
			}

			static void AssertSkipped(ConsumerResult result, const disruptor::BlockElements& elements) {
				test::AssertAborted(result, Failure_Consumer_Hash_In_Recency_Cache);
				EXPECT_EQ(1u, elements.size());
			}
		};

		struct TransactionTraits {
			static auto CreateSingleEntityElements() {
				return test::CreateTransactionElements(1);
			}

			static auto CreateConsumer(const std::function<Timestamp ()>& timeGenerator, const HashCheckOptions& options) {
				return CreateTransactionHashCheckConsumer(timeGenerator, options, [](auto, const auto&) { return false; });
			}

			static void AssertContinued(ConsumerResult result, const disruptor::TransactionElements& elements) {
				test::AssertContinued(result);
				ASSERT_EQ(1u, elements.size());
				EXPECT_FALSE(elements[0].Skip);
			}

			static void AssertSkipped(ConsumerResult result, const disruptor::TransactionElements& elements) {
				test::AssertAborted(result, Failure_Consumer_Hash_In_Recency_Cache);
				ASSERT_EQ(1u, elements.size());
				EXPECT_TRUE(elements[0].Skip);
			}
		};

		template<typename TTraits>
		static auto CreateDefaultConsumer() {
			return TTraits::CreateConsumer([]() { return Timestamp(1); }, Default_Options);
		}
	}

#define TEST_PREFIX HashCheckConsumerTests
#define SINGLE_ENTITY_BASED_TEST(TEST_NAME) \
	template<typename TTraits> void TRAITS_TEST_NAME(TEST_PREFIX, TEST_NAME)(); \
	TEST(BlockHashCheckConsumerTests, TEST_NAME) { TRAITS_TEST_NAME(TEST_PREFIX, TEST_NAME)<BlockTraits>(); } \
	TEST(TransactionHashCheckConsumerTests, TEST_NAME) { TRAITS_TEST_NAME(TEST_PREFIX, TEST_NAME)<TransactionTraits>(); } \
	template<typename TTraits> void TRAITS_TEST_NAME(TEST_PREFIX, TEST_NAME)()

	// region shared tests

	SINGLE_ENTITY_BASED_TEST(CanProcessZeroEntities) {
		// Assert:
		test::AssertPassthroughForEmptyInput(CreateDefaultConsumer<TTraits>());
	}

	SINGLE_ENTITY_BASED_TEST(SingleEntityNotPreviouslySeenIsNotSkippedWhenCacheIsEmpty) {
		// Arrange:
		auto elements = TTraits::CreateSingleEntityElements();
		auto consumer = CreateDefaultConsumer<TTraits>();

		// Act:
		auto result = consumer(elements);

		// Assert:
		TTraits::AssertContinued(result, elements);
	}

	SINGLE_ENTITY_BASED_TEST(SingleEntityNotPreviouslySeenIsNotSkippedWhenCacheIsNotEmpty) {
		// Arrange:
		auto elements1 = TTraits::CreateSingleEntityElements();
		auto elements2 = TTraits::CreateSingleEntityElements();
		auto consumer = CreateDefaultConsumer<TTraits>();

		// - cache only the first input
		consumer(elements1);

		// Act: the second input should still get processed
		auto result = consumer(elements2);

		// Assert:
		TTraits::AssertContinued(result, elements2);
	}

	SINGLE_ENTITY_BASED_TEST(SingleEntityPreviouslySeenIsSkipped) {
		// Arrange:
		auto elements = TTraits::CreateSingleEntityElements();
		auto consumer = CreateDefaultConsumer<TTraits>();

		// - cache the entity
		consumer(elements);

		// Act:
		auto result = consumer(elements);

		// Assert:
		TTraits::AssertSkipped(result, elements);
	}

	SINGLE_ENTITY_BASED_TEST(SingleEntityIsNotEvictedFromCacheAtCacheDuration) {
		// Arrange:
		auto elements1 = TTraits::CreateSingleEntityElements();
		auto elements2 = TTraits::CreateSingleEntityElements();

		auto consumer = TTraits::CreateConsumer(
				CreateTimeGenerator({ 10, 11, 611, 612 }),
				Default_Options);

		// - cache the entity
		consumer(elements1); // t11
		consumer(elements2); // t611 - triggers prune, but e1 is not evicted because (611 - 11) == 600

		// Act:
		auto result = consumer(elements1); // t612

		// Assert:
		TTraits::AssertSkipped(result, elements1);
	}

	SINGLE_ENTITY_BASED_TEST(SingleEntityIsEvictedFromCacheAfterCacheDuration) {
		// Arrange:
		auto elements1 = TTraits::CreateSingleEntityElements();
		auto elements2 = TTraits::CreateSingleEntityElements();

		auto consumer = TTraits::CreateConsumer(
				CreateTimeGenerator({ 10, 11, 612, 613 }),
				Default_Options);

		// - cache the entity
		consumer(elements1); // t11
		consumer(elements2); // t612 - triggers prune and evicts e1 because (612 - 11) > 600

		// Act:
		auto result = consumer(elements1);

		// Assert:
		TTraits::AssertContinued(result, elements1);
	}

	SINGLE_ENTITY_BASED_TEST(SingleEntityCannotSelfEvict) {
		// Arrange:
		auto elements = TTraits::CreateSingleEntityElements();

		auto consumer = TTraits::CreateConsumer(
				CreateTimeGenerator({ 10, 11, 612, 613 }),
				Default_Options);

		// - cache the entity
		consumer(elements); // t11
		consumer(elements); // t612 - triggers prune but does not evict e1 because e1 time is updated to t612

		// Act:
		auto result = consumer(elements);

		// Assert:
		TTraits::AssertSkipped(result, elements);
	}

	SINGLE_ENTITY_BASED_TEST(MultiplePruningsCannotOccurWithinPruneInterval) {
		// Arrange:
		auto elements1 = TTraits::CreateSingleEntityElements();
		auto elements2 = TTraits::CreateSingleEntityElements();

		auto consumer = TTraits::CreateConsumer(
				CreateTimeGenerator({ 10, 11, 553, 612, 613 }),
				Default_Options);

		// - cache the entity
		consumer(elements1); // t11
		consumer(elements2); // t553 - triggers a prune but does not evict e1
		consumer(elements2); // t612 - does not trigger a prune because (612 - 553) < 60

		// Act:
		auto result = consumer(elements1); // t613

		// Assert:
		TTraits::AssertSkipped(result, elements1);
	}

	SINGLE_ENTITY_BASED_TEST(MultiplePruningsCanOccurAtPruneInterval) {
		// Arrange:
		auto elements1 = TTraits::CreateSingleEntityElements();
		auto elements2 = TTraits::CreateSingleEntityElements();

		auto consumer = TTraits::CreateConsumer(
				CreateTimeGenerator({ 10, 11, 552, 612, 613 }),
				Default_Options);

		// - cache the entity
		consumer(elements1); // t11
		consumer(elements2); // t552 - triggers a prune but does not evict e1
		consumer(elements2); // t612 - triggers a prune and should evict e1

		// Act:
		auto result = consumer(elements1);

		// Assert:
		TTraits::AssertContinued(result, elements1);
	}

	SINGLE_ENTITY_BASED_TEST(SinglePruneCanEvictMultipleEntities) {
		// Arrange: create five entities
		auto elements1 = TTraits::CreateSingleEntityElements();
		auto elements2 = TTraits::CreateSingleEntityElements();
		auto elements3 = TTraits::CreateSingleEntityElements();
		auto elements4 = TTraits::CreateSingleEntityElements();
		auto elements5 = TTraits::CreateSingleEntityElements();

		auto consumer = TTraits::CreateConsumer(
				CreateTimeGenerator({ 10, 11, 12, 12, 14, 14, 613 }),
				Default_Options);

		// - cache the entities
		consumer(elements1); // t11
		consumer(elements2); // t12
		consumer(elements3); // t12
		consumer(elements4); // t14
		consumer(elements5); // t14

		// Act:
		consumer(elements2); // t613 - triggers a prune and should evict e1 and e3 (e2 extends itself)

		// Assert:
		test::AssertContinued(consumer(elements1));
		test::AssertAborted(consumer(elements2), Failure_Consumer_Hash_In_Recency_Cache);
		test::AssertContinued(consumer(elements3));
		test::AssertAborted(consumer(elements4), Failure_Consumer_Hash_In_Recency_Cache);
		test::AssertAborted(consumer(elements5), Failure_Consumer_Hash_In_Recency_Cache);
	}

	namespace {
		constexpr auto Max_Cache_Size = 5u;
		constexpr auto Max_Cache_Size_Options = HashCheckOptions(600'000, 60'000, Max_Cache_Size);

		template<typename TTraits, typename TConsumer>
		void FillConsumer(TConsumer& consumer, size_t count) {
			for (auto i = 0u; i < count; ++i) {
				auto elements = TTraits::CreateSingleEntityElements();
				consumer(elements);
			}
		}
	}

	SINGLE_ENTITY_BASED_TEST(SingleEntityPreviouslySeenThatFillsCacheIsSkipped) {
		// Arrange:
		auto consumer = TTraits::CreateConsumer(
				CreateTimeGenerator({ 10, 11, 12, 13, 14, 15 }),
				Max_Cache_Size_Options);

		// - fill the cache except for one entity
		FillConsumer<TTraits>(consumer, Max_Cache_Size - 1); // t11..t14

		// - consume an input that fills the cache
		auto elements = TTraits::CreateSingleEntityElements();
		consumer(elements); // t15

		// Act: consume the last input again
		auto result = consumer(elements);

		// Assert: it was cached because it filled the cache
		TTraits::AssertSkipped(result, elements);
	}

	SINGLE_ENTITY_BASED_TEST(SingleEntityPreviouslySeenWhenCacheIsFullIsNotSkipped) {
		// Arrange:
		auto consumer = TTraits::CreateConsumer(
				CreateTimeGenerator({ 10, 11, 12, 13, 14, 15, 16 }),
				Max_Cache_Size_Options);

		// - fill the cache
		FillConsumer<TTraits>(consumer, Max_Cache_Size); // t11..t15

		// - consume an input with a full cache
		auto elements = TTraits::CreateSingleEntityElements();
		consumer(elements); // t16

		// Act: consume the last input again
		auto result = consumer(elements);

		// Assert: it was not cached because the cache was full
		TTraits::AssertContinued(result, elements);
	}

	SINGLE_ENTITY_BASED_TEST(SingleEntityPreviouslySeenWhenCacheIsFullAndEvictedAtLeastOneEntityIsSkipped) {
		// Arrange:
		auto consumer = TTraits::CreateConsumer(
				CreateTimeGenerator({ 10, 11, 12, 13, 14, 15, 612 }),
				Max_Cache_Size_Options);

		// - fill the cache
		FillConsumer<TTraits>(consumer, Max_Cache_Size); // t11..t15

		// - consume an input with a full cache (it should evict the first input)
		auto elements = TTraits::CreateSingleEntityElements();
		consumer(elements); // t612

		// Act: consume the last input again
		auto result = consumer(elements);

		// Assert: it was cached because the consumption evicted an entity making room in the cache
		TTraits::AssertSkipped(result, elements);
	}

	// endregion

	// region block tests

	TEST(BlockHashCheckConsumerTests, MultipleEntitiesNotPreviouslySeenAreNotSkipped) {
		// Arrange:
		auto elements = test::CreateBlockElements(3);
		auto consumer = CreateDefaultConsumer<BlockTraits>();

		// Act:
		auto result = consumer(elements);

		// Assert:
		test::AssertContinued(result);
		EXPECT_EQ(3u, elements.size());
	}

	TEST(BlockHashCheckConsumerTests, MultipleEntitiesPreviouslySeenAreNotSkipped) {
		// Arrange:
		auto elements = test::CreateBlockElements(3);
		auto consumer = CreateDefaultConsumer<BlockTraits>();

		// - cache the entity
		consumer(elements);

		// Act:
		auto result = consumer(elements);

		// Assert:
		test::AssertContinued(result);
		EXPECT_EQ(3u, elements.size());
	}

	namespace {
		auto CreateElementsAroundFirstBlock(const disruptor::BlockElements& elements) {
			auto copyElements = test::CreateBlockElements({ &elements[0].Block });
			copyElements[0].EntityHash = elements[0].EntityHash;
			return copyElements;
		}
	}

	TEST(BlockHashCheckConsumerTests, SingleEntityPreviouslySeenAsPartOfMultipleEntitiesIsNotSkipped) {
		// Arrange:
		auto elements = test::CreateBlockElements(3);
		auto elementsWithFirstBlock = CreateElementsAroundFirstBlock(elements);
		auto consumer = CreateDefaultConsumer<BlockTraits>();

		// - cache the group of entities
		consumer(elements);

		// Act: consume only the first block of the multiple entities consumed previously
		auto result = consumer(elementsWithFirstBlock);

		// Assert:
		EXPECT_EQ(elements[0].EntityHash, elementsWithFirstBlock[0].EntityHash);
		BlockTraits::AssertContinued(result, elementsWithFirstBlock);
	}

	TEST(BlockHashCheckConsumerTests, MultipleEntitiesContainingSinglePreviouslySeenEntityIsNotSkipped) {
		// Arrange:
		auto elements = test::CreateBlockElements(3);
		auto elementsWithFirstBlock = CreateElementsAroundFirstBlock(elements);
		auto consumer = CreateDefaultConsumer<BlockTraits>();

		// - cache the single entity entity
		consumer(elementsWithFirstBlock);

		// Act: consume the group of entities
		auto result = consumer(elements);

		// Assert:
		EXPECT_EQ(elements[0].EntityHash, elementsWithFirstBlock[0].EntityHash);
		test::AssertContinued(result);
		EXPECT_EQ(3u, elements.size());
	}

	// endregion

	// region transaction tests

	namespace {
		auto CreateTransactionElements(const test::ConstTransactions& transactions) {
			std::vector<const model::Transaction*> rawTransactions;
			for (const auto& pTransaction : transactions)
				rawTransactions.push_back(pTransaction.get());

			return test::CreateTransactionElements(rawTransactions);
		}

		auto CreateTransactionElements(
				const test::ConstTransactions& transactions,
				const std::vector<long>& indexes) {
			std::vector<const model::Transaction*> rawTransactions;
			for (auto index : indexes)
				rawTransactions.push_back(std::next(transactions.cbegin(), index)->get());

			return test::CreateTransactionElements(rawTransactions);
		}
	}

	TEST(TransactionHashCheckConsumerTests, MultipleEntitiesCanBeProcessedAtOnce) {
		// Arrange: prepare an input with 6 elements
		auto transactions = test::MakeConst(test::GenerateRandomTransactions(6));
		auto elements = CreateTransactionElements(transactions);

		auto consumer = CreateDefaultConsumer<TransactionTraits>();

		// Act:
		auto result = consumer(elements);

		// Assert: no elements were skipped
		auto i = 0u;
		test::AssertContinued(result);
		for (const auto& element : elements)
			EXPECT_FALSE(element.Skip) << "element at " << i++;
	}

	TEST(TransactionHashCheckConsumerTests, PreviouslySeenEntitiesWithinMultipleEntitiesAreSkipped) {
		// Arrange: prepare an input with 6 elements (2) and a subset input with 3 elements (1)
		auto transactions = test::MakeConst(test::GenerateRandomTransactions(6));
		auto subsetElements = CreateTransactionElements(transactions, { 1, 3, 4 });
		auto elements = CreateTransactionElements(transactions);

		auto consumer = CreateDefaultConsumer<TransactionTraits>();

		// - process / cache the first (subset) input
		consumer(subsetElements);

		// Act: process the second (full) input
		auto result = consumer(elements);

		// Assert: only previously seen elements were skipped
		test::AssertContinued(result);
		for (auto i : { 1u, 3u, 4u })
			EXPECT_TRUE(elements[i].Skip) << "element at " << i;

		for (auto i : { 0u, 2u, 5u })
			EXPECT_FALSE(elements[i].Skip) << "element at " << i;
	}

	TEST(TransactionHashCheckConsumerTests, SkipResultIsReturnedIfAllEntitiesWithinMultipleEntitiesAreSkipped) {
		// Arrange: prepare an input with 6 elements
		auto transactions = test::MakeConst(test::GenerateRandomTransactions(6));
		auto elements = CreateTransactionElements(transactions);

		auto consumer = CreateDefaultConsumer<TransactionTraits>();

		// - process the input
		consumer(elements);

		// Act: process the input again
		auto result = consumer(elements);

		// Assert: all elements were skipped
		auto i = 0u;
		test::AssertAborted(result, Failure_Consumer_Hash_In_Recency_Cache);
		for (const auto& element : elements)
			EXPECT_TRUE(element.Skip) << "element at " << i++;
	}

	namespace {
		struct KnownHashPredicateParams {
		public:
			explicit KnownHashPredicateParams(Timestamp timestamp, const Hash256& hash)
					: Time(timestamp)
					, Hash(hash)
			{}

		public:
			const Timestamp Time;
			const Hash256 Hash;
		};

		class MockKnownHashPredicate : public test::ParamsCapture<KnownHashPredicateParams> {
		public:
			void markSeen(const Hash256& hash) {
				m_hashes.insert(hash);
			}

		public:
			bool operator()(Timestamp timestamp, const Hash256& hash) const {
				const_cast<MockKnownHashPredicate*>(this)->push(timestamp, hash);
				return m_hashes.cend() != m_hashes.find(hash);
			}

		private:
			utils::HashSet m_hashes;
		};

		static auto CreateTransactionConsumer(const MockKnownHashPredicate& predicate) {
			return CreateTransactionHashCheckConsumer(
					[]() { return Timestamp(1); },
					Default_Options,
					[&predicate](auto timestamp, const auto& hash) { return predicate(timestamp, hash); });
		}

		void AssertEqual(
				const TransactionElements& elements,
				size_t elementIndex,
				const std::vector<KnownHashPredicateParams>& params,
				size_t paramsIndex) {
			// Arrange:
			const auto& element = elements[elementIndex];
			const auto& elementParams = params[paramsIndex];
			std::ostringstream message;
			message << "element at " << elementIndex << ", params at " << paramsIndex;

			// Assert:
			EXPECT_EQ(element.Transaction.Deadline, elementParams.Time) << message.str();
			EXPECT_EQ(element.EntityHash, elementParams.Hash) << message.str();
		}
	}

	TEST(TransactionHashCheckConsumerTests, SingleEntityOnlyPreviouslySeenExternallyIsSkipped) {
		// Arrange: create a single entity input
		auto elements = TransactionTraits::CreateSingleEntityElements();

		// - mark the input element as externally seen
		MockKnownHashPredicate predicate;
		predicate.markSeen(elements[0].EntityHash);
		auto consumer = CreateTransactionConsumer(predicate);

		// Act:
		auto result = consumer(elements);

		// Assert:
		TransactionTraits::AssertSkipped(result, elements);

		// - the predicate was called
		ASSERT_EQ(1u, predicate.params().size());
		AssertEqual(elements, 0, predicate.params(), 0);
	}

	TEST(TransactionHashCheckConsumerTests, ExternallySeenEntitiesWithinMultipleEntitiesAreSkipped) {
		// Arrange: prepare an input with 6 elements
		constexpr auto Num_Transactions = 6u;
		auto transactions = test::MakeConst(test::GenerateRandomTransactions(Num_Transactions));
		auto elements = CreateTransactionElements(transactions);

		// - mark elements 1, 3, 4 as externally seen
		MockKnownHashPredicate predicate;
		predicate.markSeen(elements[1].EntityHash);
		predicate.markSeen(elements[3].EntityHash);
		predicate.markSeen(elements[4].EntityHash);
		auto consumer = CreateTransactionConsumer(predicate);

		// Act:
		auto result = consumer(elements);

		// Assert: only externally seen elements were skipped
		test::AssertContinued(result);
		for (auto i : { 1u, 3u, 4u })
			EXPECT_TRUE(elements[i].Skip) << "element at " << i;

		for (auto i : { 0u, 2u, 5u })
			EXPECT_FALSE(elements[i].Skip) << "element at " << i;

		// - the predicate was called
		ASSERT_EQ(Num_Transactions, predicate.params().size());
		for (auto i = 0u; i < Num_Transactions; ++i)
			AssertEqual(elements, i, predicate.params(), i);
	}

	TEST(TransactionHashCheckConsumerTests, PreviouslySeenAndExternallySeenEntitiesWithinMultipleEntitiesAreSkipped) {
		// Arrange: prepare an input with 9 elements (2) and a subset input with 4 elements (1)
		auto transactions = test::MakeConst(test::GenerateRandomTransactions(9));
		auto subsetElements = CreateTransactionElements(transactions, { 1, 4, 5, 6 });
		auto elements = CreateTransactionElements(transactions);

		// - mark elements 0, 5, 7 as externally seen
		MockKnownHashPredicate predicate;
		predicate.markSeen(elements[0].EntityHash);
		predicate.markSeen(elements[5].EntityHash);
		predicate.markSeen(elements[7].EntityHash);
		auto consumer = CreateTransactionConsumer(predicate);

		// - process / cache the first (subset) input
		consumer(subsetElements);

		// - clear any captured predicate calls
		predicate.clear();

		// Act: process the second (full) input
		auto result = consumer(elements);

		// Assert: only previously seen (1, 4, 5, 6) and/or externally seen (0, 5, 7) elements were skipped
		test::AssertContinued(result);
		for (auto i : { 0u, 1u, 4u, 5u, 6u, 7u })
			EXPECT_TRUE(elements[i].Skip) << "element at " << i;

		for (auto i : { 2u, 3u, 8u })
			EXPECT_FALSE(elements[i].Skip) << "element at " << i;

		// - the predicate was called only for elements not previously seen
		ASSERT_EQ(5u, predicate.params().size());
		AssertEqual(elements, 0, predicate.params(), 0);
		AssertEqual(elements, 2, predicate.params(), 1);
		AssertEqual(elements, 3, predicate.params(), 2);
		AssertEqual(elements, 7, predicate.params(), 3);
		AssertEqual(elements, 8, predicate.params(), 4);
	}

	// endregion
}}
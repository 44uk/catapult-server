#include "MemoryBasedStorage.h"

namespace catapult { namespace mocks {

	const unsigned char MemoryBasedStorage_NemesisBlockData[] = {
		0x71, 0x09, 0x00, 0x00, 0x66, 0xC1, 0x87, 0xC1, 0xA2, 0x12, 0xB9, 0xE1, 0x1C, 0x7C, 0x33, 0x58,
		0x80, 0x7B, 0xE4, 0x9B, 0xF9, 0x62, 0x7B, 0xCA, 0xF9, 0x9D, 0x6F, 0xAD, 0xF5, 0x62, 0xA9, 0xD8,
		0xFF, 0xB9, 0x85, 0xDE, 0x4A, 0x0D, 0xCB, 0x54, 0x11, 0xE3, 0xC2, 0x88, 0x1B, 0x41, 0xD2, 0xB7,
		0xDA, 0x9F, 0x76, 0xA0, 0x37, 0xA2, 0x5F, 0xB0, 0x09, 0x07, 0x9A, 0xAB, 0x45, 0xE0, 0x54, 0x4E,
		0x40, 0x87, 0x77, 0x0E, 0xB4, 0xF1, 0x2E, 0x7C, 0x9F, 0x69, 0x46, 0x09, 0x1E, 0x2C, 0xB8, 0xB6,
		0xD3, 0xA1, 0x2B, 0x50, 0xD1, 0x7C, 0xCB, 0xBF, 0x64, 0x63, 0x86, 0xEA, 0x27, 0xCE, 0x29, 0x46,
		0xA7, 0x42, 0x3D, 0xCF, 0x03, 0x90, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x7A, 0x10, 0xF3, 0x5A, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xB3, 0xE2, 0xA1, 0x35, 0x32, 0xD6, 0x2F, 0x01, 0x29, 0xBC, 0x45, 0xD8, 0xB0, 0x55, 0xF6, 0x28,
		0x17, 0x5E, 0xBA, 0xDF, 0xE8, 0x2D, 0x68, 0xC6, 0x93, 0xC1, 0x34, 0xCA, 0x4C, 0x13, 0x09, 0x4C,
		0x8D, 0x00, 0x00, 0x00, 0x61, 0x29, 0x07, 0x59, 0x77, 0x0F, 0x1B, 0x0A, 0x62, 0x22, 0x0B, 0x09,
		0xD3, 0x35, 0x17, 0x77, 0x66, 0x33, 0xCC, 0x88, 0x4D, 0x40, 0x63, 0x8C, 0x6E, 0x26, 0x53, 0x7D,
		0xBF, 0xD2, 0xD2, 0x9A, 0x37, 0xA3, 0x63, 0x17, 0x2C, 0xAF, 0x4C, 0x7B, 0x34, 0xE8, 0x03, 0x72,
		0x27, 0x98, 0x3F, 0x50, 0xF8, 0x30, 0x14, 0x93, 0xAF, 0x3A, 0x0A, 0xB3, 0x78, 0x2F, 0xD6, 0xAD,
		0xA7, 0x60, 0x58, 0x06, 0xB4, 0xF1, 0x2E, 0x7C, 0x9F, 0x69, 0x46, 0x09, 0x1E, 0x2C, 0xB8, 0xB6,
		0xD3, 0xA1, 0x2B, 0x50, 0xD1, 0x7C, 0xCB, 0xBF, 0x64, 0x63, 0x86, 0xEA, 0x27, 0xCE, 0x29, 0x46,
		0xA7, 0x42, 0x3D, 0xCF, 0x02, 0x90, 0x01, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x4B, 0xFA, 0x5F, 0x37, 0x2D, 0x55, 0xB3, 0x84, 0x03, 0x6E, 0x65, 0x6D, 0x8F, 0x00, 0x00,
		0x00, 0x7F, 0x8D, 0x11, 0x75, 0x47, 0xA3, 0xA3, 0x56, 0x7A, 0x05, 0xD4, 0xE0, 0x84, 0xE1, 0xA8,
		0xC3, 0x40, 0x89, 0xD1, 0xA4, 0x72, 0xBC, 0x19, 0x71, 0x05, 0xE5, 0xA8, 0x17, 0x20, 0x0A, 0x53,
		0x08, 0x87, 0x64, 0x29, 0x2A, 0x8F, 0xE8, 0x62, 0xB8, 0xD3, 0x69, 0x76, 0xDA, 0x87, 0xD9, 0x80,
		0xBD, 0x78, 0x6C, 0x40, 0xD9, 0xF9, 0x85, 0x2C, 0x9E, 0x4A, 0x2D, 0xE9, 0x65, 0x48, 0x0D, 0x63,
		0x03, 0xB4, 0xF1, 0x2E, 0x7C, 0x9F, 0x69, 0x46, 0x09, 0x1E, 0x2C, 0xB8, 0xB6, 0xD3, 0xA1, 0x2B,
		0x50, 0xD1, 0x7C, 0xCB, 0xBF, 0x64, 0x63, 0x86, 0xEA, 0x27, 0xCE, 0x29, 0x46, 0xA7, 0x42, 0x3D,
		0xCF, 0x02, 0x90, 0x02, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x4B, 0xFA, 0x5F, 0x37, 0x2D, 0x55, 0xB3, 0x84, 0x29, 0xCF, 0x5F,
		0xD9, 0x41, 0xAD, 0x25, 0xD5, 0x03, 0x00, 0x02, 0x06, 0x78, 0x65, 0x6D, 0x89, 0x00, 0x00, 0x00,
		0xA1, 0xC9, 0x77, 0x72, 0x60, 0xE2, 0x67, 0xDA, 0x28, 0xB1, 0x1B, 0x6C, 0xF2, 0xDE, 0xDF, 0x2E,
		0x9B, 0x3E, 0x0D, 0xD6, 0xDB, 0x59, 0x85, 0xCB, 0x4C, 0x6D, 0x67, 0xDB, 0x9C, 0x70, 0x8B, 0x16,
		0x5E, 0x9D, 0xE7, 0x74, 0x3C, 0x84, 0x19, 0xE7, 0xE6, 0x68, 0x82, 0xB6, 0x1A, 0x97, 0xCE, 0x44,
		0x4B, 0x2C, 0x16, 0xB2, 0xF5, 0x3C, 0xDD, 0x44, 0x32, 0x12, 0x2B, 0x97, 0x47, 0xD4, 0xFA, 0x03,
		0xB4, 0xF1, 0x2E, 0x7C, 0x9F, 0x69, 0x46, 0x09, 0x1E, 0x2C, 0xB8, 0xB6, 0xD3, 0xA1, 0x2B, 0x50,
		0xD1, 0x7C, 0xCB, 0xBF, 0x64, 0x63, 0x86, 0xEA, 0x27, 0xCE, 0x29, 0x46, 0xA7, 0x42, 0x3D, 0xCF,
		0x02, 0x90, 0x04, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x29, 0xCF, 0x5F, 0xD9, 0x41, 0xAD, 0x25, 0xD5, 0x01, 0x80, 0xFB, 0xDB,
		0xCA, 0x73, 0xF9, 0x1F, 0x00, 0xA4, 0x00, 0x00, 0x00, 0x99, 0x58, 0x66, 0x47, 0x0A, 0x4F, 0x13,
		0x90, 0x64, 0x13, 0x3F, 0x57, 0x7C, 0xD7, 0x88, 0x1B, 0xD0, 0x8C, 0xC4, 0x87, 0x4A, 0x7C, 0xA4,
		0xBE, 0x81, 0xFC, 0xD0, 0x18, 0xDE, 0x10, 0xE3, 0x13, 0xE8, 0x65, 0x69, 0x29, 0x9C, 0x5F, 0xB1,
		0x65, 0xF6, 0xCD, 0x3A, 0xC1, 0x5A, 0xB9, 0x49, 0x25, 0xCA, 0x80, 0x45, 0xBC, 0xA3, 0xD3, 0xCD,
		0x2D, 0x6C, 0xA1, 0x18, 0x91, 0xA8, 0xDB, 0xC9, 0x09, 0xB4, 0xF1, 0x2E, 0x7C, 0x9F, 0x69, 0x46,
		0x09, 0x1E, 0x2C, 0xB8, 0xB6, 0xD3, 0xA1, 0x2B, 0x50, 0xD1, 0x7C, 0xCB, 0xBF, 0x64, 0x63, 0x86,
		0xEA, 0x27, 0xCE, 0x29, 0x46, 0xA7, 0x42, 0x3D, 0xCF, 0x03, 0x90, 0x01, 0x41, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0x05,
		0x7C, 0xE8, 0x5C, 0xDC, 0xBF, 0x60, 0xE2, 0xD9, 0xEF, 0x09, 0x98, 0x02, 0x45, 0x90, 0x95, 0x0F,
		0xDD, 0x13, 0x0C, 0xAF, 0x87, 0xB6, 0x00, 0x00, 0x01, 0x29, 0xCF, 0x5F, 0xD9, 0x41, 0xAD, 0x25,
		0xD5, 0x80, 0xA2, 0x9F, 0xCC, 0x21, 0xE8, 0x02, 0x00, 0xA4, 0x00, 0x00, 0x00, 0xEE, 0x36, 0xB6,
		0x0C, 0xC6, 0xA2, 0xD2, 0x87, 0x66, 0x90, 0xC3, 0x12, 0x7D, 0xD0, 0x39, 0xAA, 0x52, 0x23, 0x3E,
		0x73, 0xDD, 0xF0, 0x30, 0xB7, 0x4C, 0x2B, 0x22, 0xDE, 0x67, 0x78, 0x67, 0x45, 0x06, 0x30, 0xAB,
		0x7B, 0x8F, 0x78, 0xC2, 0x1E, 0x8F, 0x1D, 0x01, 0xD2, 0xBD, 0x18, 0x2A, 0x87, 0x7B, 0x76, 0x50,
		0x76, 0xCD, 0xFF, 0xDC, 0x9F, 0x3B, 0x5D, 0xD5, 0xD5, 0x35, 0x64, 0x40, 0x05, 0xB4, 0xF1, 0x2E,
		0x7C, 0x9F, 0x69, 0x46, 0x09, 0x1E, 0x2C, 0xB8, 0xB6, 0xD3, 0xA1, 0x2B, 0x50, 0xD1, 0x7C, 0xCB,
		0xBF, 0x64, 0x63, 0x86, 0xEA, 0x27, 0xCE, 0x29, 0x46, 0xA7, 0x42, 0x3D, 0xCF, 0x03, 0x90, 0x01,
		0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x90, 0x00, 0x0E, 0x7B, 0xE6, 0xE6, 0x46, 0xD7, 0x10, 0xCB, 0x6D, 0xD6, 0x6B, 0x50, 0x17,
		0xCA, 0x85, 0xEA, 0x80, 0x92, 0xFF, 0x13, 0xF6, 0xEF, 0x83, 0x00, 0x00, 0x01, 0x29, 0xCF, 0x5F,
		0xD9, 0x41, 0xAD, 0x25, 0xD5, 0x80, 0xA2, 0x9F, 0xCC, 0x21, 0xE8, 0x02, 0x00, 0xA4, 0x00, 0x00,
		0x00, 0xDF, 0xEA, 0x2F, 0x71, 0x96, 0x57, 0xAD, 0x66, 0xE3, 0xF3, 0x55, 0x29, 0xF6, 0x4D, 0xC5,
		0xBD, 0x13, 0x88, 0x57, 0x91, 0x5E, 0x76, 0xE8, 0xF9, 0x7A, 0x98, 0x9C, 0xEA, 0x24, 0x37, 0x5F,
		0xD2, 0xF8, 0x6C, 0xEA, 0x04, 0xC0, 0xC1, 0x45, 0x17, 0xFC, 0x1C, 0xDB, 0x9D, 0xF1, 0x3A, 0xB5,
		0x2B, 0xC9, 0x9B, 0xCE, 0x27, 0xF1, 0x60, 0xF2, 0x23, 0x1C, 0x18, 0xFC, 0xFD, 0x0F, 0xB6, 0x12,
		0x0D, 0xB4, 0xF1, 0x2E, 0x7C, 0x9F, 0x69, 0x46, 0x09, 0x1E, 0x2C, 0xB8, 0xB6, 0xD3, 0xA1, 0x2B,
		0x50, 0xD1, 0x7C, 0xCB, 0xBF, 0x64, 0x63, 0x86, 0xEA, 0x27, 0xCE, 0x29, 0x46, 0xA7, 0x42, 0x3D,
		0xCF, 0x03, 0x90, 0x01, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0x0D, 0x73, 0x96, 0x60, 0x83, 0xA4, 0xDC, 0xCD, 0x84,
		0xE0, 0x78, 0x3A, 0x5C, 0xEC, 0xCC, 0x12, 0x97, 0x95, 0xD3, 0x12, 0x1A, 0xBA, 0x88, 0x00, 0x00,
		0x01, 0x29, 0xCF, 0x5F, 0xD9, 0x41, 0xAD, 0x25, 0xD5, 0x80, 0xA2, 0x9F, 0xCC, 0x21, 0xE8, 0x02,
		0x00, 0xA4, 0x00, 0x00, 0x00, 0x22, 0x2C, 0x4B, 0xA0, 0x89, 0x41, 0xEA, 0xD0, 0xBD, 0xF5, 0x02,
		0x40, 0x72, 0xD2, 0xD2, 0xF5, 0xDA, 0xAC, 0x42, 0x89, 0x17, 0x6A, 0xD3, 0x2F, 0xA2, 0x93, 0xB5,
		0xAA, 0xEB, 0x8B, 0x53, 0x36, 0xC3, 0x2E, 0x9F, 0xF5, 0xE6, 0xC9, 0xFA, 0xA9, 0x4D, 0x60, 0xAD,
		0x3E, 0xF6, 0x2C, 0x49, 0x6C, 0x88, 0xA0, 0x52, 0x88, 0xA5, 0x07, 0xBC, 0x01, 0x81, 0x25, 0x8F,
		0x40, 0x41, 0xF5, 0xA9, 0x0C, 0xB4, 0xF1, 0x2E, 0x7C, 0x9F, 0x69, 0x46, 0x09, 0x1E, 0x2C, 0xB8,
		0xB6, 0xD3, 0xA1, 0x2B, 0x50, 0xD1, 0x7C, 0xCB, 0xBF, 0x64, 0x63, 0x86, 0xEA, 0x27, 0xCE, 0x29,
		0x46, 0xA7, 0x42, 0x3D, 0xCF, 0x03, 0x90, 0x01, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0x0D, 0xF1, 0xE4, 0x1A, 0x92,
		0x75, 0x20, 0xE6, 0xAD, 0xEB, 0xB0, 0xC9, 0x41, 0x94, 0x1E, 0xF8, 0x0C, 0x6C, 0x76, 0x81, 0x3B,
		0x33, 0x1B, 0x00, 0x00, 0x01, 0x29, 0xCF, 0x5F, 0xD9, 0x41, 0xAD, 0x25, 0xD5, 0x80, 0xA2, 0x9F,
		0xCC, 0x21, 0xE8, 0x02, 0x00, 0xA4, 0x00, 0x00, 0x00, 0x19, 0x7B, 0x8A, 0x94, 0xFA, 0x49, 0x61,
		0x2D, 0xE2, 0x22, 0x4C, 0xB0, 0x8C, 0x2D, 0x48, 0x93, 0xED, 0xB3, 0x8E, 0x4B, 0x94, 0x7D, 0xE2,
		0x69, 0xC5, 0xEE, 0x8D, 0xCE, 0x11, 0x3D, 0xCC, 0x5C, 0x3B, 0x55, 0xEE, 0x83, 0x7B, 0x78, 0xCE,
		0xD8, 0x94, 0x1D, 0x0B, 0x00, 0x7C, 0xE7, 0xC2, 0xE0, 0x36, 0x69, 0x9C, 0xF0, 0xF9, 0x8D, 0x4D,
		0xEE, 0x95, 0x8C, 0x3A, 0xC7, 0x06, 0xA1, 0x45, 0x03, 0xB4, 0xF1, 0x2E, 0x7C, 0x9F, 0x69, 0x46,
		0x09, 0x1E, 0x2C, 0xB8, 0xB6, 0xD3, 0xA1, 0x2B, 0x50, 0xD1, 0x7C, 0xCB, 0xBF, 0x64, 0x63, 0x86,
		0xEA, 0x27, 0xCE, 0x29, 0x46, 0xA7, 0x42, 0x3D, 0xCF, 0x03, 0x90, 0x01, 0x41, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0x0E,
		0xFC, 0x71, 0x23, 0x9F, 0x85, 0x50, 0xB7, 0xE3, 0x8D, 0xF4, 0x42, 0xEA, 0x44, 0xD8, 0x1B, 0x28,
		0x7E, 0x55, 0xE7, 0x50, 0x86, 0x0F, 0x00, 0x00, 0x01, 0x29, 0xCF, 0x5F, 0xD9, 0x41, 0xAD, 0x25,
		0xD5, 0x80, 0xA2, 0x9F, 0xCC, 0x21, 0xE8, 0x02, 0x00, 0xA4, 0x00, 0x00, 0x00, 0x8D, 0x1A, 0x19,
		0x57, 0x04, 0x5B, 0xE7, 0xC3, 0x6E, 0x10, 0xA8, 0x1A, 0x83, 0x96, 0xA2, 0xE4, 0xB7, 0x8A, 0x58,
		0x19, 0xBA, 0x28, 0x33, 0x17, 0xB9, 0x14, 0xBB, 0x9D, 0xF6, 0xB3, 0x6C, 0x7C, 0x08, 0xF2, 0x6A,
		0x51, 0x00, 0xC8, 0x9B, 0x99, 0xDA, 0x53, 0x44, 0x54, 0xCC, 0xCD, 0x7B, 0x40, 0x8F, 0x9B, 0x9B,
		0xD5, 0xD6, 0x2A, 0x8B, 0x6D, 0x50, 0xD9, 0x36, 0xDD, 0xBA, 0x17, 0x6F, 0x03, 0xB4, 0xF1, 0x2E,
		0x7C, 0x9F, 0x69, 0x46, 0x09, 0x1E, 0x2C, 0xB8, 0xB6, 0xD3, 0xA1, 0x2B, 0x50, 0xD1, 0x7C, 0xCB,
		0xBF, 0x64, 0x63, 0x86, 0xEA, 0x27, 0xCE, 0x29, 0x46, 0xA7, 0x42, 0x3D, 0xCF, 0x03, 0x90, 0x01,
		0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x90, 0x00, 0x04, 0xF4, 0x38, 0xB6, 0x51, 0xD4, 0xEC, 0x12, 0x81, 0x14, 0x2A, 0x57, 0xC9,
		0x93, 0xD4, 0x8A, 0xE0, 0x22, 0x40, 0x15, 0x2E, 0x10, 0x41, 0x00, 0x00, 0x01, 0x29, 0xCF, 0x5F,
		0xD9, 0x41, 0xAD, 0x25, 0xD5, 0x80, 0xA2, 0x9F, 0xCC, 0x21, 0xE8, 0x02, 0x00, 0xA4, 0x00, 0x00,
		0x00, 0x67, 0xC7, 0xF0, 0x61, 0xB0, 0xE1, 0x36, 0x5A, 0x3E, 0xDD, 0x5D, 0xDE, 0x3C, 0x6C, 0xE0,
		0x37, 0x16, 0x5E, 0x82, 0xB7, 0x9A, 0x75, 0xC5, 0xB1, 0xC1, 0xC2, 0x38, 0xAE, 0x89, 0x99, 0xE3,
		0xFC, 0xFD, 0xEC, 0xB4, 0x71, 0x5F, 0x03, 0x0C, 0x52, 0x30, 0xF0, 0xB4, 0x4B, 0xBB, 0xAD, 0xDF,
		0xF1, 0x06, 0xA6, 0x39, 0x54, 0xC7, 0xFA, 0x30, 0x1B, 0x41, 0x35, 0xD5, 0x82, 0x68, 0xBE, 0x57,
		0x0F, 0xB4, 0xF1, 0x2E, 0x7C, 0x9F, 0x69, 0x46, 0x09, 0x1E, 0x2C, 0xB8, 0xB6, 0xD3, 0xA1, 0x2B,
		0x50, 0xD1, 0x7C, 0xCB, 0xBF, 0x64, 0x63, 0x86, 0xEA, 0x27, 0xCE, 0x29, 0x46, 0xA7, 0x42, 0x3D,
		0xCF, 0x03, 0x90, 0x01, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0x0F, 0x78, 0x84, 0xCA, 0x95, 0xB3, 0x98, 0x31, 0xAF,
		0x7E, 0x4F, 0x4D, 0xCA, 0xDE, 0xFA, 0xD5, 0x6B, 0x41, 0x2E, 0x94, 0x67, 0x10, 0x72, 0x00, 0x00,
		0x01, 0x29, 0xCF, 0x5F, 0xD9, 0x41, 0xAD, 0x25, 0xD5, 0x80, 0xA2, 0x9F, 0xCC, 0x21, 0xE8, 0x02,
		0x00, 0xA4, 0x00, 0x00, 0x00, 0x74, 0x4A, 0xF3, 0x09, 0xDD, 0xDA, 0x1A, 0xA7, 0x1D, 0x41, 0xD9,
		0xD2, 0x62, 0xF2, 0xE4, 0x41, 0x5D, 0x9F, 0x7E, 0x11, 0xD4, 0x64, 0x06, 0xE9, 0x21, 0x7F, 0xFC,
		0xAA, 0x30, 0x9E, 0xE9, 0x9D, 0xC6, 0xBD, 0x57, 0x4B, 0x00, 0x24, 0x0E, 0x59, 0x87, 0x64, 0x7F,
		0x34, 0x36, 0x45, 0x6C, 0x46, 0xB1, 0x13, 0xD2, 0x18, 0x38, 0x64, 0x9A, 0x23, 0x5F, 0xA4, 0xF2,
		0xE7, 0x83, 0xA3, 0x78, 0x08, 0xB4, 0xF1, 0x2E, 0x7C, 0x9F, 0x69, 0x46, 0x09, 0x1E, 0x2C, 0xB8,
		0xB6, 0xD3, 0xA1, 0x2B, 0x50, 0xD1, 0x7C, 0xCB, 0xBF, 0x64, 0x63, 0x86, 0xEA, 0x27, 0xCE, 0x29,
		0x46, 0xA7, 0x42, 0x3D, 0xCF, 0x03, 0x90, 0x01, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0x04, 0x04, 0x5F, 0x03, 0x3D,
		0xD3, 0xB8, 0xA3, 0x5E, 0x0C, 0x5A, 0x4F, 0x9E, 0x3F, 0x39, 0x38, 0xBB, 0x3F, 0x65, 0x2C, 0x2B,
		0x79, 0x99, 0x00, 0x00, 0x01, 0x29, 0xCF, 0x5F, 0xD9, 0x41, 0xAD, 0x25, 0xD5, 0x80, 0xA2, 0x9F,
		0xCC, 0x21, 0xE8, 0x02, 0x00, 0xA4, 0x00, 0x00, 0x00, 0x0A, 0x57, 0x6B, 0xF3, 0xE7, 0x19, 0x0F,
		0x5E, 0x5C, 0xD6, 0x9A, 0x0F, 0xB7, 0xE8, 0x99, 0x9A, 0xCF, 0x73, 0xE1, 0x16, 0x56, 0x10, 0xDF,
		0xE6, 0xB0, 0x83, 0x07, 0x43, 0xB7, 0x0E, 0xA3, 0x2E, 0x19, 0x32, 0x9F, 0xF0, 0x12, 0xAB, 0x23,
		0x71, 0x17, 0x2D, 0x61, 0xCB, 0x31, 0xF2, 0x1E, 0x6C, 0x72, 0x6E, 0x56, 0x45, 0x27, 0x86, 0x2C,
		0xC0, 0xAD, 0x5C, 0xAB, 0x99, 0x2E, 0x0D, 0xC7, 0x0C, 0xB4, 0xF1, 0x2E, 0x7C, 0x9F, 0x69, 0x46,
		0x09, 0x1E, 0x2C, 0xB8, 0xB6, 0xD3, 0xA1, 0x2B, 0x50, 0xD1, 0x7C, 0xCB, 0xBF, 0x64, 0x63, 0x86,
		0xEA, 0x27, 0xCE, 0x29, 0x46, 0xA7, 0x42, 0x3D, 0xCF, 0x03, 0x90, 0x01, 0x41, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0x05,
		0xF1, 0x2F, 0xA4, 0x16, 0xA1, 0x5A, 0x31, 0xB3, 0x2F, 0x09, 0xEE, 0x7A, 0x2E, 0xCC, 0xC3, 0xA0,
		0xDC, 0x8D, 0x15, 0x00, 0xEB, 0x8D, 0x00, 0x00, 0x01, 0x29, 0xCF, 0x5F, 0xD9, 0x41, 0xAD, 0x25,
		0xD5, 0x80, 0xA2, 0x9F, 0xCC, 0x21, 0xE8, 0x02, 0x00, 0xA4, 0x00, 0x00, 0x00, 0x0E, 0x64, 0x61,
		0xCD, 0x76, 0x4D, 0xE7, 0xF4, 0x58, 0x69, 0x83, 0xAE, 0x6D, 0x14, 0x0E, 0x50, 0xAE, 0x36, 0x9B,
		0x8E, 0xB6, 0xFC, 0x42, 0x08, 0xFF, 0x58, 0xC4, 0x29, 0x79, 0x71, 0x74, 0x59, 0xD9, 0x20, 0x4D,
		0x73, 0x7F, 0x65, 0xD0, 0xAF, 0xA3, 0xDD, 0xB6, 0xC2, 0x06, 0xDA, 0x52, 0xFB, 0xFC, 0x10, 0x6A,
		0xF2, 0xB5, 0x6D, 0x49, 0xC4, 0xD5, 0x9D, 0xF3, 0xC1, 0xA4, 0x82, 0xA8, 0x0F, 0xB4, 0xF1, 0x2E,
		0x7C, 0x9F, 0x69, 0x46, 0x09, 0x1E, 0x2C, 0xB8, 0xB6, 0xD3, 0xA1, 0x2B, 0x50, 0xD1, 0x7C, 0xCB,
		0xBF, 0x64, 0x63, 0x86, 0xEA, 0x27, 0xCE, 0x29, 0x46, 0xA7, 0x42, 0x3D, 0xCF, 0x03, 0x90, 0x01,
		0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x90, 0x00, 0x06, 0x67, 0x12, 0x79, 0x3B, 0x38, 0x82, 0xA7, 0xFA, 0x37, 0x59, 0x17, 0xF9,
		0x1F, 0x79, 0xA2, 0x54, 0x6B, 0x0F, 0xD3, 0x3F, 0xE7, 0x8A, 0x00, 0x00, 0x01, 0x29, 0xCF, 0x5F,
		0xD9, 0x41, 0xAD, 0x25, 0xD5, 0x80, 0xA2, 0x9F, 0xCC, 0x21, 0xE8, 0x02, 0x00, 0xA4, 0x00, 0x00,
		0x00, 0x65, 0xDA, 0xCB, 0x9C, 0x10, 0x1E, 0xA4, 0x62, 0x5C, 0x0C, 0x2B, 0x41, 0xA6, 0xA8, 0xCC,
		0x63, 0xED, 0x16, 0x98, 0x99, 0x17, 0x0B, 0x31, 0x90, 0x82, 0x7E, 0x05, 0x89, 0x91, 0xD0, 0xBD,
		0x48, 0xAB, 0x5D, 0xEC, 0xA8, 0x6B, 0x88, 0x1A, 0xA5, 0x8F, 0x28, 0xD1, 0xBB, 0x4E, 0x6F, 0xA3,
		0xF2, 0x6B, 0x12, 0xBD, 0x46, 0x24, 0x71, 0xF7, 0xE1, 0x33, 0x31, 0xF9, 0x5E, 0x21, 0x6A, 0x6D,
		0x07, 0xB4, 0xF1, 0x2E, 0x7C, 0x9F, 0x69, 0x46, 0x09, 0x1E, 0x2C, 0xB8, 0xB6, 0xD3, 0xA1, 0x2B,
		0x50, 0xD1, 0x7C, 0xCB, 0xBF, 0x64, 0x63, 0x86, 0xEA, 0x27, 0xCE, 0x29, 0x46, 0xA7, 0x42, 0x3D,
		0xCF, 0x03, 0x90, 0x01, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0x0C, 0xE3, 0xA2, 0xDA, 0xFC, 0xE6, 0xDE, 0x20, 0x79,
		0xF5, 0x6C, 0x01, 0xE2, 0xD9, 0x55, 0x82, 0xA1, 0xE1, 0x0B, 0xCA, 0xC5, 0x82, 0x5C, 0x00, 0x00,
		0x01, 0x29, 0xCF, 0x5F, 0xD9, 0x41, 0xAD, 0x25, 0xD5, 0x80, 0xA2, 0x9F, 0xCC, 0x21, 0xE8, 0x02,
		0x00,
	};
}}
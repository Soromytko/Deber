#ifndef MASK_H
#define MASK_H

#include <utility>
#include <functional>
#include <stdint.h>
#include "DataSizeType.h"
#include "ShiftType.h"
#include "ExtendType.h"

#define M1 0b1
#define M2 0b11
#define M3 0b111
#define M4 0b1111
#define M5 0b11111
#define M6 0b111111
#define M7 0b1111111
#define M8 0b11111111
#define M9 0b111111111
#define M10 0b1111111111
#define M11 0b11111111111
#define M12 0b111111111111
#define M16 0b1111111111111111
#define M19 0b1111111111111111111

namespace mask
{
	uint64_t ones(int bitSize);
	uint64_t zeroExtend(uint64_t x, int bitSize);
	uint64_t ror(uint64_t x, int esize, uint64_t rotate);
	uint64_t replicate(uint64_t x, int bitSize, int startBit, int repSize, int extSize);
	uint64_t signExtend(uint64_t x, int bitSize, int extSize);
	uint64_t replicate(int bit, int repSize);
	int highestSetBit(uint64_t x, int bitSize);
	bool decodeBitMasks(uint64_t immN, uint64_t imms, uint64_t immr, bool immediate, int mSize, std::pair<uint64_t, uint64_t>& result);
	DataSizeType decodeDataSizeType(uint8_t sf);
	ExtendType decodeRegExtend(uint8_t option);

	uint64_t shift(uint64_t imm, ShiftType shiftType, uint8_t shiftValue);
}

#endif
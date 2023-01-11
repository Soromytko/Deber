#include "mask.h"

namespace mask
{
	uint64_t ones(int bitSize)
	{
		int mask = 0x0;

		for (int i = 0; i < bitSize; i++) {
			mask = (mask << 1) | 1;
		}

		return mask;
	}

	uint64_t zeroExtend(uint64_t x, int bitSize)
	{
		uint64_t mask = ones(bitSize);

		x = x & mask;

		return x;
	}

	uint64_t ror(uint64_t x, int esize, uint64_t rotate)
	{
		uint64_t a = x << (esize - rotate) & ones(esize);
		uint64_t r = x >> (rotate)&ones(esize);
		return ((a | r) & ones(esize));
	}

	uint64_t replicate(uint64_t x, int bitSize, int startBit, int repSize, int extSize)
	{
		uint64_t repval = (x >> startBit) & ones(repSize);
		int times = extSize / repSize;
		uint64_t val = 0;
		for (int i = 0; i < times; i++) {
			val = (val << repSize) | repval;
		}
		repval = val << startBit;

		x = x | repval;
		return x;
	}

	uint64_t signExtend(uint64_t x, int bitSize, int extSize)
	{
		return (replicate(x >> (bitSize - 1), extSize - bitSize) << bitSize) | x;
	}

	uint64_t replicate(int bit, int repSize)
	{
		uint64_t result = bit;

		for (int i = 0; i < repSize - 1; i++)
		{
			result = (result << 1) | bit;
		}

		return result;
	}

	int highestSetBit(uint64_t x, int bitSize)
	{
		uint64_t mask = 0x1 << (bitSize - 1);
		for (int i = bitSize - 1; i >= 0; i--)
		{
			if ((mask & x) == mask) {
				return i;
			}
			mask = mask >> 1;
		}
		return -1;
	}

	bool decodeBitMasks(uint64_t immN, uint64_t imms, uint64_t immr, bool immediate, int mSize, std::pair<uint64_t, uint64_t>& result)
	{
		uint64_t tmask{};
		uint64_t wmask{};

		uint64_t levels{};

		// Compute log2 of element size
		// 2^len must be in range [2, M]
		//                   immN:NOT(imms));
		int len = highestSetBit(immN << 6 | ((~imms) & ones(6)), 7);

		if (len < 1) {
			return false;
		}

		//assert(M >= (1 << len));
		if (mSize < (1 << len))
		{
			return false;
		}

		// Determine S, R and S - R parameters
		levels = zeroExtend(ones(len), 6);

		// For logical immediates an all-ones value of S is reserved
		// since it would generate a useless all-ones result (many times)
		if (immediate && (imms & levels) == levels) {
			//System.out.println("All-Ones " + immN + ":" + immr + ":" + imms);
			return false;
		}

		uint64_t S = imms & levels;
		uint64_t R = immr & levels;

		uint64_t diff = S - R; // 6-bit subtract with borrow

		int esize = 1 << len;

		uint64_t d = diff & ones(len - 1);

		uint64_t welem = zeroExtend(ones((int)(S + 1)), esize);
		uint64_t telem = zeroExtend(ones((int)(d + 1)), esize);

		//wmask = Replicate(ROR(welem, R));

		wmask = replicate(ror(welem, esize, R), esize, 0, esize, mSize);

		// Replicate(telem);
		tmask = replicate(telem, esize, 0, esize, mSize);

		result = std::make_pair(wmask, tmask);

		return true;
	}

	DataSizeType decodeDataSizeType(uint8_t sf)
	{
		return (sf == 0) ? DataSizeType::b32 : DataSizeType::b64;
	}

	ExtendType decodeRegExtend(uint8_t option)
	{
		switch (option)
		{
		case 0b000: return ExtendType::uxtb;
		case 0b001: return ExtendType::uxth;
		case 0b010: return ExtendType::uxtw;
		case 0b011: return ExtendType::uxtx;
		case 0b100: return ExtendType::sxtb;
		case 0b101: return ExtendType::sxth;
		case 0b110: return ExtendType::sxtw;
		case 0b111: return ExtendType::sxtx;
		}
	}

	uint64_t shift(uint64_t imm, ShiftType shiftType, uint8_t shiftValue)
	{
		std::function<void()> shiftFuncs[4] = {
		   [&imm, &shiftValue]() { imm <<= shiftValue; },
		   [&imm, &shiftValue]() { imm >>= shiftValue; },
		   [&imm, &shiftValue]() {},
		   [&imm, &shiftValue]() {}
		};

		shiftFuncs[static_cast<uint32_t>(shiftType)]();
		return imm;
	}
	
}
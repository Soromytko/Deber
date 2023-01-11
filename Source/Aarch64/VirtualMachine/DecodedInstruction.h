#ifndef DECODED_INSTRUCTION_H
#define DECODED_INSTRUCTION_H

#include <stdint.h>
#include <string>
#include <functional>
#include <General/DataSizeType.h>
#include <General/Opcode.h>
#include <General/ShiftType.h>
#include <General/ExtendType.h>

namespace aarch64
{
	struct DecodedInstruction
	{
	public:
		bool trySetShiftType(uint8_t shiftType);

		Opcode opcode{};
		DataSizeType dataType{};
		DataSizeType dataTypeRm{};
		ShiftType shiftType{};
		ExtendType extendType{};
		uint8_t
			//sf{},
			sh{},
			rd{},
			rn{},
			rm{};
		uint64_t imm{};
		uint8_t uimm4{}, uimm6{};
		uint16_t immr{}, imms{};
		uint32_t shift{};
		uint32_t extend{};

	};
}

#endif
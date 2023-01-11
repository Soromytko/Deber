#include "DecodedInstruction.h"

namespace aarch64
{
	bool DecodedInstruction::trySetShiftType(uint8_t shiftType)
	{
		switch (shiftType)
		{
		case 0b00: this->shiftType = ShiftType::lsl; break;
		case 0b01: this->shiftType = ShiftType::lsr; break;
		case 0b11: this->shiftType = ShiftType::asr; break;
		default: return false;
		}
		this->shift = shiftType;

		return true;
	}

}
#include "AsmInstructor.h"

namespace aarch64
{
	AsmInstructor::AsmInstructor()
	{
		_initInstructions();
	}

	std::string AsmInstructor::getAsmCode()
	{
		return m_asmStream.str();
	}

	std::string AsmInstructor::m_getRegName(uint8_t regIndex, DataSizeType dataType)
	{
		if (regIndex == 31)
		{
			return "sp";
		}
		else
		{
			std::string result = (dataType == DataSizeType::b32) ? "w" : "x";

			if (regIndex == 30) return result + std::to_string(regIndex);
			if (regIndex == 31) return result + "zr";

			return result + std::to_string(regIndex);
		}
	}

	std::string AsmInstructor::m_getRdName()
	{
		return m_getRegName(_decInst->rd, _decInst->dataType);
	}

	std::string AsmInstructor::m_getRnName()
	{
		return m_getRegName(_decInst->rn, _decInst->dataType);
	}

	std::string AsmInstructor::m_getRmName()
	{
		return m_getRegName(_decInst->rm, _decInst->dataType);
	}

	std::string AsmInstructor::m_getRmNameX()
	{
		return m_getRegName(_decInst->rm, _decInst->dataTypeRm);
	}

	std::string AsmInstructor::m_getShift()
	{
		if (_decInst->shift == 0) return "";

		std::string result{};

		switch (_decInst->shiftType)
		{
		case ShiftType::lsl: result = ", lsl "; break;
		case ShiftType::lsr: result = ", lsr "; break;
		case ShiftType::asr: result = ", asr "; break;
		case ShiftType::ror: result = ", ror "; break;
		}

		return result + std::to_string(_decInst->shift);
	}

	std::string AsmInstructor::m_getExtend()
	{
		std::string result{};

		switch (_decInst->extendType)
		{
		case ExtendType::uxtb: result = ", uxtb "; break;
		case ExtendType::uxth: result = ", uxth "; break;
		case ExtendType::uxtw: result = ", uxtw "; break;
		case ExtendType::uxtx: result = ", uxtx "; break;
		case ExtendType::sxtb: result = ", sxtb "; break;
		case ExtendType::sxth: result = ", sxth "; break;
		case ExtendType::sxtw: result = ", sxtw "; break;
		case ExtendType::sxtx: result = ", sxtx "; break;
		}

		return "";
		//return result + std::to_string(_decInst->);
	}

}
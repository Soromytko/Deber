#include "ExeInstructor.h"

namespace aarch64
{
	ExeInstructor::ExeInstructor()
	{
		_initInstructions();
	}

	VMState ExeInstructor::getState()
	{
		return m_state;
	}

	void ExeInstructor::_initInstructions()
	{
		_initInstruction(Opcode::adc, []()
			{

			});

		_initInstruction(Opcode::addImm, [this]()
			{
				if (_decInst->dataType == DataSizeType::b32)
					*m_getLowerReg(_decInst->rd) = *m_getLowerReg(_decInst->rn) + (_decInst->imm << _decInst->shift);
				else
					m_state.regs[_decInst->rd] = m_state.regs[_decInst->rn] + (_decInst->imm << _decInst->shift);
			});
	}

	uint32_t* ExeInstructor::m_getLowerReg(uint32_t regIndex)
	{
		return reinterpret_cast<uint32_t*>(&m_state.regs[regIndex]);
	}
}
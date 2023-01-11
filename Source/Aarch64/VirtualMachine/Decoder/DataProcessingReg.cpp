#include "Decoder.h"

namespace aarch64
{
	bool Decoder::m_decodeAddSubShReg()
	{
		uint8_t sf = (m_byteCode >> 31) & M1;
		uint8_t op = (m_byteCode >> 30) & M1;
		uint8_t s = (m_byteCode >> 29) & M1;
		uint8_t shiftType = (m_byteCode >> 22) & M2;
		uint8_t imm6 = (m_byteCode >> 10) & M6;
		uint8_t rm = (m_byteCode >> 16) & M5;
		uint8_t rn = (m_byteCode >> 5) & M5;
		uint8_t rd = m_byteCode & M5;

		if (!m_decInst->trySetShiftType(shiftType) || sf == 0b0 && (imm6 >> 5) == 0b1) return false;
		
		m_decInst->dataType = mask::decodeDataSizeType(sf);
		m_decInst->rd = rd;
		m_decInst->rn = rn;
		m_decInst->rm = rm;
		m_decInst->shift = imm6;

		switch ((op << 1) | s)
		{
		case 0b00: m_decInst->opcode = Opcode::addSh; return true;
		case 0b01: m_decInst->opcode = Opcode::addsSh; return true;
		case 0b10: m_decInst->opcode = Opcode::subSh;	return true;
		case 0b11: m_decInst->opcode = Opcode::subsSh; return true;
		}

		return false;
	}
	
	bool Decoder::m_decodeAddSubExReg()
	{
		uint8_t sf = (m_byteCode >> 31) & M1;
		uint8_t op = (m_byteCode >> 30) & M1;
		uint8_t s = (m_byteCode >> 29) & M1;
		uint8_t opt = (m_byteCode >> 22) & M2;
		uint8_t option = (m_byteCode >> 13) & M3;
		uint8_t imm3 = (m_byteCode >> 10) & M3;
		uint8_t rm = (m_byteCode >> 16) & M5;
		uint8_t rn = (m_byteCode >> 5) & M5;
		uint8_t rd = m_byteCode & M5;

		//m_decInst->setDataSizeType(sf);
		m_decInst->dataType = mask::decodeDataSizeType(sf);
		m_decInst->extendType = mask::decodeRegExtend(option);
		m_decInst->rd = rd;
		m_decInst->rn = rn;
		m_decInst->rm = rm;
		m_decInst->imm;

		switch ((op << 3) | (s << 2) | opt)
		{
		case 0b0000: m_decInst->opcode = Opcode::addEx; return true;
		case 0b0100: m_decInst->opcode = Opcode::addsEx; return true;
		case 0b1000: m_decInst->opcode = Opcode::subEx; return true;
		case 0b1100: m_decInst->opcode = Opcode::subsEx; return true;
		}

		return false;
	}
}
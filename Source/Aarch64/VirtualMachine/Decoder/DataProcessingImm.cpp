#include "Decoder.h"

namespace aarch64
{
	bool Decoder::m_decodeAdressing()
	{
		uint8_t op = (m_byteCode >> 31) & M1;
		uint8_t immlo = (m_byteCode >> 29) & M2;
		uint32_t immhi = (m_byteCode >> 5) & M19;
		uint8_t rd = m_byteCode & M4;

		int64_t imm21 = (immhi << 2) | immlo;

		m_decInst->dataType = mask::decodeDataSizeType(1);
		m_decInst->rd = rd;

		if (op == 0)
		{
			int64_t imm = mask::signExtend(imm21, 21, 64);
			m_decInst->imm = imm;
			//m_asmStream << "adr " << m_getRegName(rd, 1) << ", " << imm << std::endl;
			m_decInst->opcode = Opcode::adr;
		}
		else if (op == 1)
		{
			int64_t imm = mask::signExtend(imm21 << 12, 33, 64);
			m_decInst->imm = imm;
			m_decInst->opcode = Opcode::adrp;
			//m_asmStream << "adrp " << m_getRegName(rd, 1) << ", " << imm << std::endl;
		}

		return true;
	}

	bool Decoder::m_decodeAddSubImm()
	{
		uint8_t sf = (m_byteCode >> 31) & M1;
		uint8_t op = (m_byteCode >> 30) & M1;
		uint8_t s = (m_byteCode >> 29) & M1;
		uint8_t sh = (m_byteCode >> 22) & M1;
		uint32_t imm12 = (m_byteCode >> 10) & M12;
		uint8_t rn = (m_byteCode >> 5) & M5;
		uint8_t rd = m_byteCode & M5;
		uint8_t dataSize = (sf == 0) ? 32 : 64;

		op = (op << 1) + s;

		int64_t imm = imm12;
		std::string shift{};
		if (sh == 1)
		{
			//imm <<= 12;
			shift = ", lsl " + std::to_string(12);
			m_decInst->shift = 12;
		}
		else m_decInst->shift = 0;

		m_decInst->shiftType = ShiftType::lsl;

		/*switch (op)
		{
		case 0b00: m_asmStream << "add " << m_getRegName(rd, sf) << ", " << m_getRegName(rn, sf) << ", " << imm << shift << std::endl; return true;
		case 0b01: m_asmStream << "adds " << m_getRegName(rd, sf) << ", " << m_getRegName(rn, sf) << ", " << imm << shift << std::endl; return true;
		case 0b10: m_asmStream << "sub " << m_getRegName(rd, sf) << ", " << m_getRegName(rn, sf) << ", " << imm << shift << std::endl; return true;
		case 0b11: m_asmStream << "subs " << m_getRegName(rd, sf) << ", " << m_getRegName(rn, sf) << ", " << imm << shift << std::endl;  return true;
		}*/

		m_decInst->dataType = mask::decodeDataSizeType(sf);
		m_decInst->rd = rd;
		m_decInst->rn = rn;
		m_decInst->imm = imm;

		switch (op)
		{
		case 0b00: m_decInst->opcode = Opcode::addImm; return true;
		case 0b01: m_decInst->opcode = Opcode::addsImm; return true;
		case 0b10: m_decInst->opcode = Opcode::subImm; return true;
		case 0b11: m_decInst->opcode = Opcode::subsImm; return true;
		}

		return false;
	}

	bool Decoder::m_decodeAddSubImmTags()
	{
		uint8_t sf = (m_byteCode >> 31) & M1;
		uint8_t op = (m_byteCode >> 30) & M1;
		uint8_t s = (m_byteCode >> 29) & M1;
		uint8_t o2 = (m_byteCode >> 22) & M1;

		uint8_t uimm6 = (m_byteCode >> 16) & M6;
		uint8_t uimm4 = (m_byteCode >> 10) & M4;
		uint8_t xn = (m_byteCode >> 5) & M5;
		uint8_t xd = m_byteCode & M5;

		uint8_t b = (sf << 3) | (op << 2) | (s << 1) | o2;

		/*switch (b)
		{
		case 0b1000: m_asmStream << "addg " << m_getRegName(xd, 1) << ", " << m_getRegName(xn, 1) << ", " << uimm6 << ", " << uimm4 << std::endl; return true;
		case 0b1100: m_asmStream << "subg " << m_getRegName(xd, 1) << ", " << m_getRegName(xn, 1) << ", " << uimm6 << ", " << uimm4 << std::endl; return true;
		}*/

		m_decInst->dataType = mask::decodeDataSizeType(1);
		m_decInst->rd = xd;
		m_decInst->rn = xn;
		m_decInst->uimm4 = uimm4;
		m_decInst->uimm6 = uimm6;

		switch (b)
		{
		case 0b1000: m_decInst->opcode = Opcode::addg; return true;
		case 0b1100: m_decInst->opcode = Opcode::subg; return true;
		}

		return false;
	}

	bool Decoder::m_decodeLogicalImm()
	{
		uint8_t sf = (m_byteCode >> 31);
		uint8_t opc = (m_byteCode >> 29) & M2;
		uint8_t n = (m_byteCode >> 22) & M1;

		uint8_t imms = (m_byteCode >> 10) & M6;
		uint8_t immr = (m_byteCode >> 16) & M6;
		uint8_t rn = (m_byteCode >> 5) & M5;
		uint8_t rd = m_byteCode & M5;

		uint8_t dataSize{};

		if (sf == 0)
		{
			if (n == 1) return false;
			dataSize = 32;
		}
		else dataSize = 64;

		std::pair<uint64_t, uint64_t> result;
		if (!mask::decodeBitMasks(0, imms, immr, true, dataSize, result)) return false;

		/*std::string rnName = m_getRegName(rn, sf);
		std::string rdName = m_getRegName(rd, sf);

		switch (opc)
		{
		case 0b00: m_asmStream << "and " << rdName << ", " << rnName << ", " << result.first << std::endl; return true;
		case 0b01: m_asmStream << "orr " << rdName << ", " << rnName << ", " << result.first << std::endl; return true;
		case 0b10: m_asmStream << "eor " << rdName << ", " << rnName << ", " << result.first << std::endl; return true;
		case 0b11: m_asmStream << "ands " << rdName << ", " << rnName << ", " << result.first << std::endl; return true;
		}*/

		m_decInst->dataType = mask::decodeDataSizeType(sf);
		m_decInst->rd = rd;
		m_decInst->rn = rn;
		m_decInst->imm = result.first;

		switch (opc)
		{
		case 0b00: m_decInst->opcode = Opcode::addImm;  return true;
		case 0b01: m_decInst->opcode = Opcode::orrImm; return true;
		case 0b10: m_decInst->opcode = Opcode::eorImm; return true;
		case 0b11: m_decInst->opcode = Opcode::andsImm; return true;
		}


		return false;
	}

	bool Decoder::m_decodeMoveWideImm()
	{
		uint8_t	sf = (m_byteCode >> 31) & M1;
		uint8_t opc = (m_byteCode >> 29) & M2;
		uint8_t hw = (m_byteCode >> 21) & M2;
		uint16_t imm16 = (m_byteCode >> 5) & M16;
		uint8_t rd = m_byteCode & M5;

		uint32_t imm = imm16;
		uint32_t shift = hw << 4;
		std::string shiftStr = (hw != 0) ? ", lsl " + std::to_string(shift) : "";

		if (sf == 0 && hw >> 1 == 1) return false;

		m_decInst->shiftType = ShiftType::lsl;

		/*switch (opc)
		{
		case 0b00: m_asmStream << "movn " << m_getRegName(rd, sf) << ", " << imm << shiftStr << std::endl; return true;
		case 0b10: m_asmStream << "movz " << m_getRegName(rd, sf) << ", " << imm << shiftStr << std::endl; return true;
		case 0b11: m_asmStream << "movk " << m_getRegName(rd, sf) << ", " << imm << shiftStr << std::endl; return true;
		}*/

		m_decInst->dataType = mask::decodeDataSizeType(sf);
		m_decInst->rd = rd;
		m_decInst->imm = imm;
		m_decInst->shift = shift;

		switch (opc)
		{
		case 0b00: m_decInst->opcode = Opcode::movn; return true;
		case 0b10: m_decInst->opcode = Opcode::movz; return true;
		case 0b11: m_decInst->opcode = Opcode::movk; return true;
		}

		return false;
	}

	bool Decoder::m_decodeBitfield()
	{
		uint8_t sf = (m_byteCode >> 31) & M1;
		uint8_t opc = (m_byteCode >> 29) & M2;
		uint8_t n = (m_byteCode >> 22) & M1;
		uint16_t immr = (m_byteCode >> 16) & M6;
		uint16_t imms = (m_byteCode >> 10) & M6;
		uint8_t rn = (m_byteCode >> 5) & M5;
		uint8_t rd = m_byteCode & M5;

		if (sf != n) return false;

		/*switch (opc)
		{
		case 0b00: m_asmStream << "sbfm " << m_getRegName(rd, sf) << ", " << m_getRegName(rn, sf) << ", " << immr << ", " << imms << std::endl; return true;
		case 0b01: m_asmStream << "bfm " << m_getRegName(rd, sf) << ", " << m_getRegName(rn, sf) << ", " << immr << ", " << imms << std::endl; return true;
		case 0b10: m_asmStream << "ubfm " << m_getRegName(rd, sf) << ", " << m_getRegName(rn, sf) << ", " << immr << ", " << imms << std::endl; return true;
		}*/

		m_decInst->dataType = mask::decodeDataSizeType(sf);
		m_decInst->rd = rd;
		m_decInst->rn = rn;
		m_decInst->immr = immr;
		m_decInst->imms = imms;

		switch (opc)
		{
		case 0b00: m_decInst->opcode = Opcode::sbfm; return true;
		case 0b01: m_decInst->opcode = Opcode::bfm; return true;
		case 0b10: m_decInst->opcode = Opcode::ubfm; return true;
		}

		return false;
	}

	bool Decoder::m_decodeExtract()
	{
		uint8_t sf = (m_byteCode >> 31) & M1;
		uint8_t op21 = (m_byteCode >> 29) & M2;
		uint8_t n = (m_byteCode >> 22) & M1;
		uint8_t o0 = (m_byteCode >> 21) & M1;
		uint8_t rm = (m_byteCode >> 16) & M5;
		uint16_t imms = (m_byteCode >> 10) & M6;
		uint8_t rn = (m_byteCode >> 5) & M5;
		uint8_t rd = m_byteCode & M5;

		uint8_t op = (op21 << 2) | (n << 1) | o0;

		if (sf != n || o0 != 0) return false;

		m_decInst->dataType = mask::decodeDataSizeType(sf);
		m_decInst->rd = rd;
		m_decInst->rn = rn;
		m_decInst->rm = rm;
		m_decInst->imms = imms;

		if (op21 == 0b00)
		{
			if (sf == 0 && imms >> 5 != 0) return false;
			m_decInst->opcode = Opcode::extr;
			//m_asmStream << "extr " << m_getRegName(rd, sf) << ", " << m_getRegName(rn, sf) << ", " << m_getRegName(rm, sf) << ", " << imms << std::endl;
			return true;
		}

		return false;
	}

}
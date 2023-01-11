#include "Decoder.h"

namespace aarch64
{
	bool Decoder::m_decodeReserved()
	{
		return false;
	}

	bool Decoder::m_decodeME()
	{
		return false;
	}

	bool Decoder::m_decodeSVE()
	{
		return false;
	}

	bool Decoder::m_decodeDataProcessingImm()
	{
		uint8_t op1 = (m_byteCode >> 23) & M3;

		switch (op1)
		{
		case 0b000: case 0b001: return m_decodeAdressing();
		case 0b010: return m_decodeAddSubImm();
		case 0b011: return m_decodeAddSubImmTags();
		case 0b100: return m_decodeLogicalImm();
		case 0b101: return m_decodeMoveWideImm();
		case 0b110: return m_decodeBitfield();
		case 0b111: return m_decodeExtract();
		}

		return false;
	}

	bool Decoder::m_decodeBranchesEGaSID()
	{
		return false;
	}

	bool Decoder::m_decodeLoadAndStore()
	{
		uint8_t op0 = (m_byteCode >> 28) & M4;
		uint8_t op1 = (m_byteCode >> 26) & M1;
		uint8_t op2 = (m_byteCode >> 23) & M2;
		uint8_t op3 = (m_byteCode >> 16) & M6;
		uint8_t op4 = (m_byteCode >> 10) && M2;

		if ((op0 & M2) == 0b00)
		{
			if (op0 >> 3 == 0b0)
			{
				if (op1 == 0b0)
				{
					if (op2 == 0b00 && op3 >> 5 == 0b1) {}
				}
				else
				{
					switch (op2)
					{
					case 0b00: if (op3 == 0b000000) {}
							 else break;
					case 0b01: if (op3 >> 5 == 0b0) {}
							 else break;
					case 0b10: if ((op3 & M5) == 0b00000) {}
							 else break;
					case 0b11: break;
					}
				}
			}
			else
			{
				if (op1 == 0b0 && op2 == 0b00 && op3 >> 5 == 0b1) {}
			}

			if (op1 == 0b0)
			{
				if (op2 == 0b00)
				{
					if (op3 >> 5 == 0) {}
				}
				else if (op2 == 0b01)
				{
					if (op3 >> 5 == 0) {}
					else {}
				}
			}
		}
		else if (op0 == 0b1101)
		{
			if (op1 == 0b0 && op2 >> 1 == 0b1 && op3 >> 5 == 0b1)
			{

			}
			return false;
		}
		else if ((op0 & M2) == 0b01)
		{
			if (op1 == 0b0)
			{
				if (op2 >> 1 == 0b1 && op3 >> 5 == 0b0 && op4 == 0b00) {}
			}
			if (op2 >> 1 == 0b0) {}
			else if (op2 >> 1 == 0b1 && op3 >> 5 == 0b0 && op4 == 0b01) {}
		}
		else if ((op0 & M2) == 0b10)
		{
			switch (op2)
			{
			case 0b00:
			case 0b01:
			case 0b10:
			case 0b11: break;
			}
		}
		else if ((op0 & M2) == 0b11)
		{
			if (op2 >> 1 == 0b0)
			{
				if (op3 >> 5 == 0b0)
				{
					switch (op4)
					{
					case 0b00:
					case 0b01:
					case 0b10:
					case 0b11: break;
					}
				}
				else
				{
					if (op4 == 0b00) {}
					else if (op4 == 0b10) {}
					else if ((op4 & M1) == 0b1) {}
				}
			}
			else
			{

			}
		}

		return false;
	}

	bool Decoder::m_decodeDataProcessingReg()
	{
		uint8_t op0 = (m_byteCode >> 30) & M1;
		uint8_t op1 = (m_byteCode >> 28) & M1;
		uint8_t op2 = (m_byteCode >> 21) & M4;
		uint8_t op3 = (m_byteCode >> 10) & M6;

		if (op1 == 1)
		{
			if (op2 == 0b0110)
			{
				if (op0 == 0b0) {}
				else {}
			}
			else if (op2 == 0b0000)
			{
				if (op3 == 0b000000) {}
				else if ((op3 & M5) == 0b00001) {}
				else if ((op3 & M4) == 0b0010) {}
			}
			else if (op3 == 0b0010)
			{
				if (((op3 >> 1) & M1) == 0b0) {}
				else {}
			}
			else if (op3 == 0b0100) {}
			else if (op3 >> 3 == 0b1) {}
		}
		else
		{
			if (op2 >> 3 == 0b0) {}
			else if (op2 >> 3 == 0b1)
			{
				if ((op2 & M1) == 0b0) return m_decodeAddSubShReg();
				else {}
			}
		}

		return false;
	}

	bool Decoder::m_decodeDataProcessingSFPaASIMD()
	{
		return false;
	}
}
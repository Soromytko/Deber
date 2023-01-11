#include "Decoder.h"

namespace aarch64
{
	Decoder::Decoder(DecodedInstruction* decodedInstruction)
	{
		m_decInst = decodedInstruction;
	}

	Decoder::~Decoder()
	{

	}

	bool Decoder::tryDecode(uint32_t instruction)
	{
		m_byteCode = instruction;

		uint8_t op0 = (m_byteCode) & 0b00000001;
		uint8_t op1 = (m_byteCode >> 25) & 0b00001111;

		switch (op1)
		{
		case 0b0000: return (op0 == 0) ? m_decodeReserved() : m_decodeME();
		case 0b0010: return m_decodeME();
		case 0b1000: case 0b1001: return m_decodeDataProcessingImm();
		case 0b1010: case 0b1011: return m_decodeBranchesEGaSID();
		case 0b0100: case 0b0110: case 0b1100: case 0b1110: return m_decodeLoadAndStore();
		case 0b0101: case 0b1101: return m_decodeDataProcessingReg();
		case 0b0111: case 0b1111: return m_decodeDataProcessingSFPaASIMD();
		}

		return false;
	}

	/*void Decoder::decode()
	{
		if (m_tryDecode())
		{

		}
		else
		{
			m_setError("Invalid instructions");
		}
	}*/
}
#include "Decoder.h"

namespace aarch64
{
	bool Decoder::m_decodeAdvancedSIMD_LSMS()
	{
		uint8_t l = (m_byteCode >> 22) & M1;
		uint8_t opcode = (m_byteCode >> 12) & M4;
		uint8_t op = (l << 4) | opcode;

		switch (op)
		{
		//case 0b00000: m_asmStream << "" << std::endl; return true;//ST4
		//case 0b00010: m_asmStream << "" << std::endl; return true;//ST1
		//case 0b00100: m_asmStream << "" << std::endl; return true;//ST3
		//case 0b00110: m_asmStream << "" << std::endl; return true;//ST1
		//case 0b00111: m_asmStream << "" << std::endl; return true;//ST1
		//case 0b01000: m_asmStream << "" << std::endl; return true;//St2
		//case 0b01010: m_asmStream << "" << std::endl; return true;//ST1
		//case 0b10000: m_asmStream << "" << std::endl; return true;//LD4
		//case 0b10010: m_asmStream << "" << std::endl; return true;//LD1
		//case 0b10100: m_asmStream << "" << std::endl; return true;//LD3
		//case 0b10110: m_asmStream << "" << std::endl; return true;//LD1
		//case 0b10111: m_asmStream << "" << std::endl; return true;//LD1
		//case 0b11000: m_asmStream << "" << std::endl; return true;//LD2
		//case 0b11010: m_asmStream << "" << std::endl; return true;//LD1
		}

		return false;
	}
}
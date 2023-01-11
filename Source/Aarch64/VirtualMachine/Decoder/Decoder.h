#ifndef DECODER_H
#define DECODER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <bitset>
#include <General/Opcode.h>
#include <General/mask.h>
#include <General/conversion.h>
#include "../DecodedInstruction.h"

namespace aarch64
{
	class Decoder
	{
	public:
		Decoder(DecodedInstruction* decodedInstruction);
		~Decoder();
		bool tryDecode(uint32_t instruction);

	private:
		//Main decoding
		bool m_decodeReserved();
		bool m_decodeME();
		bool m_decodeSVE();
		bool m_decodeDataProcessingImm();
		bool m_decodeBranchesEGaSID();
		bool m_decodeLoadAndStore();
		bool m_decodeDataProcessingReg();
		bool m_decodeDataProcessingSFPaASIMD();

		//Data Processing Immediate
		bool m_decodeAdressing();
		bool m_decodeAddSubImm();
		bool m_decodeAddSubImmTags();
		bool m_decodeLogicalImm();
		bool m_decodeMoveWideImm();
		bool m_decodeBitfield();
		bool m_decodeExtract();

		//Loads and Stores
		bool m_decodeAdvancedSIMD_LSMS();

		//Data Processing Register group
		bool m_decodeAddSubShReg();
		bool m_decodeAddSubExReg();

		uint32_t m_byteCode{}; //bytecode of the current instruction
		DecodedInstruction* m_decInst{};
	};
}

#endif
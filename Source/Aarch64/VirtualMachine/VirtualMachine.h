#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

#include <vector>
#include <General/error.h>
#include <General/Opcode.h>
#include <General/DataSizeType.h>
#include "Decoder/Decoder.h"
#include "DecodedInstruction.h"
#include "Instructor/Asm/AsmInstructor.h"
#include "Instructor/Exe/ExeInstructor.h"

namespace aarch64
{
	class VirtualMachine
	{
	public:
		VirtualMachine(int argc, char** argv);
		~VirtualMachine();
		void setDecMode();
		void setExeMode();
		uint32_t getErrorState();
		bool isEOF();
		bool tryStep();
		int run();
		void executeInstruction(Opcode opcode);
		std::string getAsmCode();
		VMState getState();

	private:
		void m_setError(std::string errorMessage);
		bool m_tryReadFile(std::string filePath);
		void m_readArgs(int& argc, char**& argv);
		void m_createInstructions();

		Decoder* m_decoder{};
		Instructor* m_instructor{};
		AsmInstructor m_asmInstructor{};
		ExeInstructor m_exeInstructor{};
		std::vector<uint8_t>* m_srcCode{};
		uint32_t m_curInstIndex{};
		bool m_isRun{};
		uint64_t m_registers[31]{};
		DecodedInstruction m_decInst{};
		std::vector<uint32_t>* m_srcInstructions{};
		std::stringstream m_asmStream{};
		int m_result{};
	};
}

#endif
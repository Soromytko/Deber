#include "Instructor.h"

namespace aarch64
{
	Instructor::Instructor()
	{
		_instructions = new std::vector<instPtr>(static_cast<uint32_t>(Opcode::count));
	}

	Instructor::~Instructor()
	{
		delete _instructions;
	}

	void Instructor::executeInstruction(DecodedInstruction* decodedInstruction)
	{
		_decInst = decodedInstruction;
		instPtr inst = (*_instructions)[static_cast<uint32_t>(decodedInstruction->opcode)];
		if (inst == nullptr)
			printError("Instructor null");
		else
			inst();
	}

	void Instructor::_initInstruction(Opcode opcode, instPtr inst)
	{
		(*_instructions)[static_cast<uint32_t>(opcode)] = inst;
	}
}
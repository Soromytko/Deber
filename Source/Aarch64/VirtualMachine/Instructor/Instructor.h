#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <vector>
#include <functional>
#include <General/error.h>
#include <General/Opcode.h>
#include "../DecodedInstruction.h"

typedef std::function<void()> instPtr;

namespace aarch64
{
	class Instructor
	{
	public:
		Instructor();
		~Instructor();
		void executeInstruction(DecodedInstruction* decodedInstruction);

	protected:
		void virtual _initInstructions() {}
		void _initInstruction(Opcode opcode, instPtr inst);

		std::vector<instPtr>* _instructions{};
		DecodedInstruction* _decInst{};

	};
}

#endif
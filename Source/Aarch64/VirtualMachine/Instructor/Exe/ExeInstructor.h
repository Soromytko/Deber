#ifndef EXECUTABLE_INSTRUCTOR_H
#define EXECUTABLE_INSTRUCTOR_H

#include <stdint.h>
#include "../Instructor.h"

namespace aarch64
{
	struct VMState
	{
	public:
		uint64_t regs[0b11111]{};

	};

	class ExeInstructor : public Instructor
	{
	public:
		ExeInstructor();
		VMState getState();

	protected:
		void _initInstructions() override;

	private:
		uint32_t* m_getLowerReg(uint32_t regIndex);
		VMState m_state{};
	};
}

#endif
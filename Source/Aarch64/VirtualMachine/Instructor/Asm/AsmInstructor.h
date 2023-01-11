#ifndef DECODABLE_INSTRUCTOR_H
#define DECODABLE_INSTRUCTOR_H

#include <stdint.h>
#include <sstream>

#include <iostream>

#include <General/DataSizeType.h>
#include "../Instructor.h"

namespace aarch64
{
	class AsmInstructor : public Instructor
	{
	public:
		AsmInstructor();
		std::string getAsmCode();

	protected:
		void _initInstructions() override;

	private:
		std::stringstream m_asmStream{};

		std::string m_getRegName(uint8_t regIndex, DataSizeType dataType);
		std::string m_getRdName();
		std::string m_getRnName();
		std::string m_getRmName();
		std::string m_getRmNameX();
		std::string m_getShift();
		std::string m_getExtend();
	};
}

#endif


#include "VirtualMachine.h"

namespace aarch64
{
	VirtualMachine::VirtualMachine(int argc, char** argv)
	{
		if (argc == 1)
		{
			std::cout << "Docoder" << std::endl;
		}
		else
		{
			if (m_tryReadFile(argv[1]))
			{
				m_readArgs(argc, argv);
				if (m_instructor == nullptr)
				{
					m_setError("The decoding mode is not specified");
				}
				m_createInstructions();
				m_decoder = new Decoder(&m_decInst);
			}
			else
			{
				m_setError("The file could not be read");
			}
		}
	}

	VirtualMachine::~VirtualMachine()
	{
		delete m_decoder;
	}

	void VirtualMachine::setDecMode()
	{
		m_instructor = &m_asmInstructor;
	}

	void VirtualMachine::setExeMode()
	{
		m_instructor = &m_exeInstructor;
	}

	uint32_t VirtualMachine::getErrorState()
	{
		return m_result;
	}

	bool VirtualMachine::isEOF()
	{
		return m_curInstIndex < m_srcInstructions->size();
	}

	bool VirtualMachine::tryStep()
	{
		bool result = false;
		if (m_decoder->tryDecode((*m_srcInstructions)[m_curInstIndex]))
		{
			m_instructor->executeInstruction(&m_decInst);
			result = true;
		}
		m_curInstIndex++;

		return result;
	}

	int VirtualMachine::run()
	{
		while (m_isRun)
		{

		}
		
		return m_result;
	}

	void VirtualMachine::executeInstruction(Opcode opcode)
	{
		//(this->*funcPtr)();
		//(this->*(*m_modePtr)[static_cast<uint32_t>(opcode)])();
	}

	std::string VirtualMachine::getAsmCode()
	{
		return m_asmInstructor.getAsmCode();
	}

	VMState VirtualMachine::getState()
	{
		return m_exeInstructor.getState();
	}

	void VirtualMachine::m_setError(std::string errorMessage)
	{
		m_isRun = false;
		m_result = -1;
		printError(errorMessage);
	}

	bool VirtualMachine::m_tryReadFile(std::string filePath)
	{
		std::ifstream input(filePath, std::ios::binary);

		if (input.is_open())
		{
			m_srcCode = new std::vector<uint8_t>{ std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>() };

			input.close();

			return true;
		}

		return false;
	}

	void VirtualMachine::m_readArgs(int& argc, char**& argv)
	{
		for (int i = 2; i < argc; i++)
		{
			std::string arg{ argv[i] };

			if (arg == "-asm")
			{
				setDecMode();
			}
			else if (arg == "-exe")
			{
				setExeMode();
			}
			else if (arg == "-hex")
			{
				m_srcCode->erase(std::remove(m_srcCode->begin(), m_srcCode->end(), 'x'), m_srcCode->end());
				m_srcCode->erase(std::remove(m_srcCode->begin(), m_srcCode->end(), '\\'), m_srcCode->end());
				m_srcCode->erase(std::remove(m_srcCode->begin(), m_srcCode->end(), '\"'), m_srcCode->end());

				std::vector<uint8_t>* srcCode = new std::vector<uint8_t>(m_srcCode->size() / 2);
				for (size_t i = 0; i < srcCode->size(); i++)
				{
					char c[2]{ (*m_srcCode)[i * 2], (*m_srcCode)[i * 2 + 1] };
					(*srcCode)[i] = conversion::hexStrToByte(c);
				}

				delete m_srcCode;
				m_srcCode = srcCode;
			}
			else if (arg == "-inv")
			{
				for (size_t j = 0; j < m_srcCode->size(); j += 4)
				{
					uint8_t c = (*m_srcCode)[j + 0];
					(*m_srcCode)[j + 0] = (*m_srcCode)[j + 3];
					(*m_srcCode)[j + 3] = c;

					c = (*m_srcCode)[j + 1];
					(*m_srcCode)[j + 1] = (*m_srcCode)[j + 2];
					(*m_srcCode)[j + 2] = c;
				}
			}
		}
	}

	void VirtualMachine::m_createInstructions()
	{
		m_srcInstructions = new std::vector<uint32_t>(m_srcCode->size() / 4); //instruction length 4 bytes

		for (int i = 0; i < m_srcInstructions->size(); i++)
		{
			(*m_srcInstructions)[i] = conversion::bytesToInt(
				(*m_srcCode)[i * 4 + 0],
				(*m_srcCode)[i * 4 + 1],
				(*m_srcCode)[i * 4 + 2],
				(*m_srcCode)[i * 4 + 3]);
		}
	}

}

#include "AsmInstructor.h"

namespace aarch64
{
	void AsmInstructor::_initInstructions()
	{
		_initInstruction(Opcode::adc, [this]() {});
		_initInstruction(Opcode::addcs, [this]() {});

		_initInstruction(Opcode::addEx, [this]()
			{
				m_asmStream << "add " << m_getRdName() << ", " << m_getRnName() << ", " << m_getRmName() << _decInst->extend << std::endl;
			});

		_initInstruction(Opcode::addImm, [this]()
			{
				//m_asmStream << "add " << m_getRdName() << ", " << m_getRnName() << ", " << _decInst->imm << ", lsl " << _decInst->shift << std::endl;
				m_asmStream << "add " << m_getRdName() << ", " << m_getRnName() << ", " << _decInst->imm << m_getShift() << std::endl;
			});

		_initInstruction(Opcode::addSh, [this]()
			{
				m_asmStream << "add " << m_getRdName() << ", " << m_getRnName() << ", " << m_getRmName() << m_getShift() << std::endl;
			});

		_initInstruction(Opcode::addg, [this]()
			{
				m_asmStream << "addg " << m_getRdName() << ", " << m_getRnName() << ", " << _decInst->uimm6 << ", " << _decInst->uimm4 << std::endl;
			});

		_initInstruction(Opcode::addsEx, [this]()
			{
				///m_asmStream << "add " << m_getRdName() << ", " << m_getRnName() << m_getRmNameX() << m_getExted() << std::endl;
			});

		_initInstruction(Opcode::addsImm, [this]()
			{
				//m_asmStream << "adds " << m_getRdName() << ", " << m_getRnName() << ", " << _decInst->imm << ", lsl " << _decInst->shift << std::endl;
				m_asmStream << "adds " << m_getRdName() << ", " << m_getRnName() << ", " << _decInst->imm << m_getShift() << std::endl;
			});

		_initInstruction(Opcode::addsSh, [this]()
			{
				m_asmStream << "adds " << m_getRdName() << ", " << m_getRnName() << ", " << m_getRmName() << m_getShift() << std::endl;
			});

		_initInstruction(Opcode::adr, [this]()
			{
				m_asmStream << "adr " << m_getRdName() << ", " << _decInst->imm << std::endl;
			});

		_initInstruction(Opcode::adrp, [this]()
			{
				m_asmStream << "adrp " << m_getRdName() << ", " << _decInst->imm << std::endl;
			});

		_initInstruction(Opcode::andImm, [this]()
			{
				m_asmStream << "and " << m_getRdName() << ", " << m_getRnName() << _decInst->imm << std::endl;
			});

		_initInstruction(Opcode::andReg, [this]()
			{

			});

		_initInstruction(Opcode::andsImm, [this]()
			{
				m_asmStream << "ands " << m_getRdName() << ", " << m_getRnName() << _decInst->imm << std::endl;
			});

		_initInstruction(Opcode::bfm, [this]()
			{
				m_asmStream << "bfm " << m_getRdName() << ", " << m_getRnName() << ", " << _decInst->immr << ", " << _decInst->imms << std::endl;
			});

		_initInstruction(Opcode::bfxil, [this]() {});
		_initInstruction(Opcode::bicReg, [this]() {});
		_initInstruction(Opcode::bicsReg, [this]() {});
		_initInstruction(Opcode::bl, [this]() {});
		_initInstruction(Opcode::blr, [this]() {});
		_initInstruction(Opcode::blraa, [this]() {});
		_initInstruction(Opcode::blraaz, [this]() {});
		_initInstruction(Opcode::blrab, [this]() {});
		_initInstruction(Opcode::blrabz, [this]() {});
		_initInstruction(Opcode::br, [this]() {});
		_initInstruction(Opcode::braa, [this]() {});
		_initInstruction(Opcode::braaz, [this]() {});
		_initInstruction(Opcode::brab, [this]() {});
		_initInstruction(Opcode::brabz, [this]() {});
		_initInstruction(Opcode::brk, [this]() {});
		_initInstruction(Opcode::bti, [this]() {});
		_initInstruction(Opcode::cbnz, [this]() {});
		_initInstruction(Opcode::cbz, [this]() {});
		_initInstruction(Opcode::ccmnImm, [this]() {});
		_initInstruction(Opcode::ccmnReg, [this]() {});
		_initInstruction(Opcode::ccmpImm, [this]() {});
		_initInstruction(Opcode::ccmpReg, [this]() {});
		_initInstruction(Opcode::cinc, [this]() {});
		_initInstruction(Opcode::cinv, [this]() {});
		_initInstruction(Opcode::clrex, [this]() {});
		_initInstruction(Opcode::cls, [this]() {});
		_initInstruction(Opcode::clz, [this]() {});
		_initInstruction(Opcode::cmnReg, [this]() {});
		_initInstruction(Opcode::cmnImm, [this]() {});
		_initInstruction(Opcode::cmpImm, [this]() {});
		_initInstruction(Opcode::cmpReg, [this]() {});
		_initInstruction(Opcode::cmpp, [this]() {});
		_initInstruction(Opcode::cneg, [this]() {});
		_initInstruction(Opcode::crc32b, [this]() {});
		_initInstruction(Opcode::crc32h, [this]() {});
		_initInstruction(Opcode::crc32w, [this]() {});
		_initInstruction(Opcode::crc32x, [this]() {});
		_initInstruction(Opcode::crc32cb, [this]() {});
		_initInstruction(Opcode::crc32ch, [this]() {});
		_initInstruction(Opcode::crc32cw, [this]() {});
		_initInstruction(Opcode::crc32cx, [this]() {});
		_initInstruction(Opcode::csdb, [this]() {});
		_initInstruction(Opcode::csel, [this]() {});
		_initInstruction(Opcode::cset, [this]() {});
		_initInstruction(Opcode::csetm, [this]() {});
		_initInstruction(Opcode::csinc, [this]() {});
		_initInstruction(Opcode::csinv, [this]() {});
		_initInstruction(Opcode::csneg, [this]() {});
		_initInstruction(Opcode::dc, [this]() {});
		_initInstruction(Opcode::dcps1, [this]() {});
		_initInstruction(Opcode::dcps2, [this]() {});
		_initInstruction(Opcode::dcps3, [this]() {});
		_initInstruction(Opcode::dmb, [this]() {});
		_initInstruction(Opcode::drps, [this]() {});
		_initInstruction(Opcode::dsb, [this]() {});
		_initInstruction(Opcode::eonReg, [this]() {});

		_initInstruction(Opcode::eorImm, [this]()
			{
				m_asmStream << "eor " << m_getRdName() << ", " << m_getRnName() << _decInst->imm << std::endl;
			});

		_initInstruction(Opcode::eorReg, [this]() {});
		_initInstruction(Opcode::eret, [this]() {});
		_initInstruction(Opcode::eretaa, [this]() {});
		_initInstruction(Opcode::eretab, [this]() {});
		_initInstruction(Opcode::esb, [this]() {});
		_initInstruction(Opcode::extr, [this]()
			{
				m_asmStream << "extr " << m_getRdName() << ", " << m_getRnName() << ", " << m_getRmName() << ", " << _decInst->imms << std::endl;
			});
		_initInstruction(Opcode::gmi, [this]() {});
		_initInstruction(Opcode::hint, [this]() {});
		_initInstruction(Opcode::hlt, [this]() {});
		_initInstruction(Opcode::hvc, [this]() {});
		_initInstruction(Opcode::ic, [this]() {});
		_initInstruction(Opcode::irg, [this]() {});
		_initInstruction(Opcode::isb, [this]() {});
		_initInstruction(Opcode::ldg, [this]() {});
		_initInstruction(Opcode::ldgv, [this]() {});
		_initInstruction(Opcode::lslReg, [this]() {});
		_initInstruction(Opcode::lslImm, [this]() {});
		_initInstruction(Opcode::lslv, [this]() {});
		_initInstruction(Opcode::lsrReg, [this]() {});
		_initInstruction(Opcode::lsrImm, [this]() {});
		_initInstruction(Opcode::lsrv, [this]() {});
		_initInstruction(Opcode::madd, [this]() {});
		_initInstruction(Opcode::mneg, [this]() {});
		_initInstruction(Opcode::movSP, [this]() {});
		_initInstruction(Opcode::movInvWideImm, [this]() {});
		_initInstruction(Opcode::movWideImm, [this]() {});
		_initInstruction(Opcode::movBitmaskImm, [this]() {});
		_initInstruction(Opcode::movReg, [this]() {});

		_initInstruction(Opcode::movk, [this]()
			{
				//m_asmStream << "movk " << m_getRdName() << ", " << _decInst->imm << ", lsl " << _decInst->shift << std::endl;
				m_asmStream << "movk " << m_getRdName() << ", " << _decInst->imm << m_getShift() << std::endl;
			});

		_initInstruction(Opcode::movn, [this]()
			{
				//m_asmStream << "movn " << m_getRdName() << ", " << _decInst->imm << ", lsl " << _decInst->shift << std::endl;
				m_asmStream << "movn " << m_getRdName() << ", " << _decInst->imm << m_getShift() << std::endl;
			});

		_initInstruction(Opcode::movz, [this]()
			{
				//m_asmStream << "movz " << m_getRdName() << ", " << _decInst->imm << ", lsl " << _decInst->shift << std::endl;
				m_asmStream << "movz " << m_getRdName() << ", " << _decInst->imm << m_getShift() << std::endl;
			});

		_initInstruction(Opcode::mrs, [this]() {});
		_initInstruction(Opcode::msrImm, [this]() {});
		_initInstruction(Opcode::msrReg, [this]() {});
		_initInstruction(Opcode::msub, [this]() {});
		_initInstruction(Opcode::mul, [this]() {});
		_initInstruction(Opcode::mvn, [this]() {});
		_initInstruction(Opcode::negReg, [this]() {});
		_initInstruction(Opcode::negs, [this]() {});
		_initInstruction(Opcode::ngc, [this]() {});
		_initInstruction(Opcode::ngcs, [this]() {});
		_initInstruction(Opcode::nop, [this]() {});
		_initInstruction(Opcode::ornReg, [this]() {});


		_initInstruction(Opcode::orrImm, [this]()
			{
				m_asmStream << "orr " << m_getRdName() << ", " << m_getRnName() << _decInst->imm << std::endl;
			});


		_initInstruction(Opcode::sbfm, [this]()
			{
				m_asmStream << "sbfm " << m_getRdName() << ", " << m_getRnName() << ", " << _decInst->immr << ", " << _decInst->imms << std::endl;
			});

		_initInstruction(Opcode::sbfx, [this]() {});
		_initInstruction(Opcode::sdiv, [this]() {});
		_initInstruction(Opcode::sev, [this]() {});
		_initInstruction(Opcode::sevl, [this]() {});
		_initInstruction(Opcode::smaddl, [this]() {});
		_initInstruction(Opcode::smc, [this]() {});
		_initInstruction(Opcode::smnegl, [this]() {});
		_initInstruction(Opcode::smsubl, [this]() {});
		_initInstruction(Opcode::smulh, [this]() {});
		_initInstruction(Opcode::smull, [this]() {});
		_initInstruction(Opcode::st2g, [this]() {});
		_initInstruction(Opcode::stg, [this]() {});
		_initInstruction(Opcode::stgp, [this]() {});
		_initInstruction(Opcode::stgv, [this]() {});
		_initInstruction(Opcode::stz2g, [this]() {});
		_initInstruction(Opcode::stzg, [this]() {});
		_initInstruction(Opcode::subEx, [this]() {});

		_initInstruction(Opcode::subImm, [this]()
			{
				//m_asmStream << "sub " << m_getRdName() << ", " << m_getRnName() << ", " << _decInst->imm << ", lsl " << _decInst->shift << std::endl;
				m_asmStream << "sub " << m_getRdName() << ", " << m_getRnName() << m_getShift() << std::endl;
			});

		_initInstruction(Opcode::subSh, [this]()
			{
				m_asmStream << "sub " << m_getRdName() << ", " << m_getRnName() << ", " << m_getRmName() << m_getShift() << std::endl;
			});

		_initInstruction(Opcode::subg, [this]()
			{
				m_asmStream << "subg " << m_getRdName() << ", " << m_getRnName() << ", " << _decInst->uimm6 << ", " << _decInst->uimm4 << std::endl;
			});

		_initInstruction(Opcode::subp, [this]() {});
		_initInstruction(Opcode::subps, [this]() {});
		_initInstruction(Opcode::subsEx, [this]() {});

		_initInstruction(Opcode::subsImm, [this]()
			{
				//m_asmStream << "subs " << m_getRdName() << ", " << m_getRnName() << ", " << _decInst->imm << ", lsl " << _decInst->shift << std::endl;
				m_asmStream << "subs " << m_getRdName() << ", " << m_getRnName() << m_getShift()  << std::endl;
			});

		_initInstruction(Opcode::subsSh, [this]()
			{
				m_asmStream << "subs " << m_getRdName() << ", " << m_getRnName() << ", " << m_getRmName() << m_getShift() << std::endl;

			});

		_initInstruction(Opcode::svc, [this]() {});
		_initInstruction(Opcode::sxtb, [this]() {});
		_initInstruction(Opcode::sxth, [this]() {});
		_initInstruction(Opcode::sxtw, [this]() {});
		_initInstruction(Opcode::sys, [this]() {});
		_initInstruction(Opcode::sysl, [this]() {});
		_initInstruction(Opcode::tbnz, [this]() {});
		_initInstruction(Opcode::tbz, [this]() {});
		_initInstruction(Opcode::tlbi, [this]() {});
		_initInstruction(Opcode::tstImm, [this]() {});
		_initInstruction(Opcode::tstReg, [this]() {});
		_initInstruction(Opcode::ubfiz, [this]() {});

		_initInstruction(Opcode::ubfm, [this]()
			{
				m_asmStream << "ubfm " << m_getRdName() << ", " << m_getRnName() << ", " << _decInst->immr << ", " << _decInst->imms << std::endl;
			});




	}
}
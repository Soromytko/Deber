#ifndef OPCODE_H
#define OPCODE_H

namespace aarch64
{
	enum class Opcode
	{
		adc,
		addcs,
		addEx,
		addImm,
		addSh,
		addg,
		addsEx,
		addsImm,
		addsSh,
		adr,
		adrp,
		andImm,
		andReg,
		andsImm,
		andsReg,
		asrReg,
		asrImm,
		asrv,
		at,
		autda, autdza,
		autdb, autdzb,
		autia, autiza, autia1716, autiasp, autiaz,
		autib, autizb, autib1716, autibsp, autibz,
		axFlag,
		b_cond,
		b,
		bfc,
		bfi,
		bfm,
		bfxil,
		bicReg,
		bicsReg,
		bl,
		blr,
		blraa, blraaz, blrab, blrabz,
		br,
		braa, braaz, brab, brabz,
		brk,
		bti,
		cbnz,
		cbz,
		ccmnImm,
		ccmnReg,
		ccmpImm,
		ccmpReg,
		cinc,
		cinv,
		clrex,
		cls,
		clz,
		cmnReg,
		cmnImm,
		cmpImm,
		cmpReg,
		cmpp,
		cneg,
		crc32b, crc32h, crc32w, crc32x,
		crc32cb, crc32ch, crc32cw, crc32cx,
		csdb,
		csel,
		cset,
		csetm,
		csinc,
		csinv,
		csneg,
		dc,
		dcps1,
		dcps2,
		dcps3,
		dmb,
		drps,
		dsb,
		eonReg,
		eorImm,
		eorReg,
		eret,
		eretaa, eretab,
		esb,
		extr,
		gmi,
		hint,
		hlt,
		hvc,
		ic,
		irg,
		isb,
		ldg,
		ldgv,
		lslReg,
		lslImm,
		lslv,
		lsrReg,
		lsrImm,
		lsrv,
		madd,
		mneg,
		movSP,
		movInvWideImm,
		movWideImm,
		movBitmaskImm,
		movReg,
		movk,
		movn,
		movz,
		mrs,
		msrImm,
		msrReg,
		msub,
		mul,
		mvn,
		negReg,
		negs,
		ngc,
		ngcs,
		nop,
		ornReg,
		orrImm,
		orrReg,
		pacda, pacdza,
		pacdb, pacdzb,
		pacga,
		pacia, paciza, pacia1716, paciasp, paciaz,
		pacib, pacizb, pacib1716, pacibsp, pacibz,
		psb,
		rbit,
		ret,
		retaa, retab,
		rev16,
		rev32,
		rev64,
		rev,
		rorImm,
		rorReg,
		rorv,
		sbc,
		sbcs,
		sbfiz,
		sbfm,
		sbfx,
		sdiv,
		sev,
		sevl,
		smaddl,
		smc,
		smnegl,
		smsubl,
		smulh,
		smull,
		st2g,
		stg,
		stgp,
		stgv,
		stz2g,
		stzg,
		subEx,
		subImm,
		subSh,
		subg,
		subp,
		subps,
		subsEx,
		subsImm,
		subsSh,
		svc,
		sxtb,
		sxth,
		sxtw,
		sys,
		sysl,
		tbnz,
		tbz,
		tlbi,
		tstImm,
		tstReg,
		ubfiz,
		ubfm,
		ubfx,
		udiv,




		umaddl,
		umnegl,
		umsubl,
		umulh,
		umull,
		uxtb,
		uxth,
		xaflag,
		wfe,
		wfi,
		xpacd, xpaci, xpaclri,
		yield,
		casa, //casal, cas, casl, casal, cas, casl,
		casab,// casalb, casb, caslb,
		casah,// casalh, cash, caslh,
		caspa, //caspal, casp, caspl, caspal, casp, caspl,
		ldadda, //ldaddal, ldadd, ldaddl, ldaddal, ldadd, ldaddl,
		ldaddab, //ldaddalb, ldaddb, ldaddlb,
		ldaddah, //ldaddalh, ldaddh, ldaddlh,
		ldapr,
		ldaprb,
		ldaprh,
		ldar,
		ldarb,
		ldarh,
		ldaxp,
		ldaxr,
		ldaxrb,
		ldaxrh,
		ldclra, //ldclral, ldclr, ldclrl, ldclral, ldclr, ldclrl,
		ldclrab, //ldclralb, ldclrb, ldclrlb,
		ldclrah, //ldclralh, ldclrh, ldclrlh,
		ldeora, //ldeoral, ldeor, ldeorl, ldeoral, ldeor, ldeorl,
		ldeorab,// ldeoralb, ldeorb, ldeorlb,
		ldeorah, //ldeoralh, ldeorh, ldeorlh,
		ldlar,
		ldlarb,
		ldlarh,
		ldnp,
		ldp,
		ldpsw,
		ldrImm,
		ldrLit,
		ldrReg,
		ldraa, //ldrab, ldrab,
		ldrbImm,
		ldrbReg,
		ldrhImm,
		ldrhReg,
		ldrsbImm,
		ldrsbReg,
		ldrshImm,
		ldrshReg,
		ldrswImm,
		ldrswLit,
		ldrswReg,
		ldseta, //ldsetal, ldset, ldsetl, ldsetal, ldset, ldsetl,
		ldsetab,// ldsetalb, ldsetb, ldsetlb,
		ldsetah, //ldsetalh, ldseth, ldsetlh,
		ldsmaxa, //ldsmaxal, ldsmax, ldsmaxl, ldsmaxal, ldsmax, ldsmaxl,
		ldsmaxab, //ldsmaxalb, ldsmaxb, ldsmaxlb,
		ldsmaxah, //ldsmaxalh, ldsmaxh, ldsmaxlh,
		ldsmina, //ldsminal, ldsmin, ldsminl, ldsminal, ldsmin, ldsminl,
		ldsminab, //ldsminalb, ldsminb, ldsminlb,
		ldsminah, //ldsminalh, ldsminh, ldsminlh,
		ldtr,
		ldtrb,
		ldtrh,
		ldtrsb,
		ldtrsh,
		ldtrsw,
		ldumaxa, //ldumaxal, ldumax, ldumaxl, ldumaxal, ldumax, ldumaxl,
		ldumaxab, //ldumaxalb, ldumaxb, ldumaxlb,
		ldumaxah, //ldumaxalh, ldumaxh, ldumaxlh,
		ldumina, //lduminal, ldumin, lduminl, lduminal, ldumin, lduminl,
		lduminab,// lduminalb, lduminb, lduminlb,
		lduminah, //lduminalh, lduminh, lduminlh,
		ldur,
		ldurb,
		ldurh,
		ldursb,
		ldursh,
		ldursw,
		ldxp,
		ldxr,
		ldxrb,
		ldxrh,
		prfmImm,
		prfmLit,
		prfmReg,
		prfum, //(unscaled offset)
		stadd, //staddl, staddl,
		staddb, //staddlb,
		staddh, //staddlh,
		stclr, //stclrl, stclrl,
		stclrb, //stclrlb,
		stclrh,// stclrlh,
		steor, //steorl, steorl,
		steorb,// steorlb,
		steorh, //steorlh,
		stllr,
		stllrb,
		stllrh,
		stlr,
		stlrb,
		stlrh,
		stlxp,
		stlxr,
		stlxrb,
		stlxrh,
		stnp,
		stp,
		strImm,
		strReg,
		strbImm,
		strbReg,
		strhImm,
		strhReg,
		stset, //stsetl, stsetl,
		stsetb, //stsetlb,
		stseth, //stsetlh,
		stsmax, //stsmaxl, stsmaxl,
		stsmaxb, //stsmaxlb,
		stsmaxh,// stsmaxlh,
		stsmin, //stsminl, stsminl,
		stsminb, //stsminlb,
		stsminh, //stsminlh,
		sttr,
		sttrb,
		sttrh,
		stumax, //stumaxl, stumaxl,
		stumaxb, //stumaxlb,
		stumaxh, //stumaxlh,
		stumin, //stuminl, stuminl,
		stuminb, //stuminlb,
		stuminh, //stuminlh,
		stur,
		sturb,
		sturh,
		stxp,
		stxr,
		stxrb,
		stxrh,
		swpa, //swpal, swp, swpl, swpal, swp, swpl,
		swpab, //swpalb, swpb, swplb,
		swpah, //swpalh, swph, swplh,


		//a64 floating - point instructions
		//a64 floating - point instructions in alphabetical order
		//register restrictions for a64 instructions
		//fabs(scalar)
		//fadd(scalar)
		//fccmp
		//fccmpe
		//fcmp
		//fcmpe
		//fcsel
		//fcvt
		//fcvtas(scalar)
		//fcvtau(scalar)
		//fcvtms(scalar)
		//fcvtmu(scalar)
		//fcvtns(scalar)
		//fcvtnu(scalar)
		//fcvtps(scalar)
		//fcvtpu(scalar)
		//fcvtzs(scalar, fixed - point)
		//fcvtzs(scalar, integer)
		//fcvtzu(scalar, fixed - point)
		//fcvtzu(scalar, integer)
		//fdiv(scalar)
		//fjcvtzs
		//fmadd
		//fmax(scalar)
		//fmaxnm(scalar)
		//fmin(scalar)
		//fminnm(scalar)
		//fmov(register)
		//fmov(general)
		//fmov(scalar, immediate)
		//fmsub
		//fmul(scalar)
		//fneg(scalar)
		//fnmadd
		//fnmsub
		//fnmul(scalar)
		//frinta(scalar)
		//frinti(scalar)
		//frintm(scalar)
		//frintn(scalar)
		//frintp(scalar)
		//frintx(scalar)
		//frintz(scalar)
		//fsqrt(scalar)
		//fsub(scalar)
		//ldnp(simd and fp)
		//ldp(simd and fp)
		//ldr(immediate, simd and fp)
		//ldr(literal, simd and fp)
		//ldr(register, simd and fp)
		//ldur(simd and fp)
		//scvtf(scalar, fixed - point)
		//scvtf(scalar, integer)
		//stnp(simd and fp)
		//stp(simd and fp)
		//str(immediate, simd and fp)
		//str(register, simd and fp)
		//stur(simd and fp)
		//ucvtf(scalar, fixed - point)
		//ucvtf(scalar, integer)
		//a64 simd scalar instructions
		//a64 simd scalar instructions in alphabetical order
		//abs(scalar)
		//add(scalar)
		//addp(scalar)
		//cmeq(scalar, register)
		//cmeq(scalar, zero)
		//cmge(scalar, register)
		//cmge(scalar, zero)
		//cmgt(scalar, register)
		//cmgt(scalar, zero)
		//cmhi(scalar, register)
		//cmhs(scalar, register)
		//cmle(scalar, zero)
		//cmlt(scalar, zero)
		//cmtst(scalar)
		//dup(scalar, element)
		//fabd(scalar)
		//facge(scalar)
		//facgt(scalar)
		//faddp(scalar)
		//fcmeq(scalar, register)
		//fcmeq(scalar, zero)
		//fcmge(scalar, register)
		//fcmge(scalar, zero)
		//fcmgt(scalar, register)
		//fcmgt(scalar, zero)
		//fcmla(scalar, by element)
		//fcmle(scalar, zero)
		//fcmlt(scalar, zero)
		//fcvtas(scalar)
		//fcvtau(scalar)
		//fcvtms(scalar)
		//fcvtmu(scalar)
		//fcvtns(scalar)
		//fcvtnu(scalar)
		//fcvtps(scalar)
		//fcvtpu(scalar)
		//fcvtxn(scalar)
		//fcvtzs(scalar, fixed - point)
		//fcvtzs(scalar, integer)
		//fcvtzu(scalar, fixed - point)
		//fcvtzu(scalar, integer)
		//fmaxnmp(scalar)
		//fmaxp(scalar)
		//fminnmp(scalar)
		//fminp(scalar)
		//fmla(scalar, by element)
		//fmlal, (scalar, by element)
		//fmls(scalar, by element)
		//fmlsl, (scalar, by element)
		//fmul(scalar, by element)
		//fmulx(scalar, by element)
		//fmulx(scalar)
		//frecpe(scalar)
		//frecps(scalar)
		//frsqrte(scalar)
		//frsqrts(scalar)
		//mov(scalar)
		//neg(scalar)
		//scvtf(scalar, fixed - point)
		//scvtf(scalar, integer)
		//shl(scalar)
		//sli(scalar)
		//sqabs(scalar)
		//sqadd(scalar)
		//sqdmlal(scalar, by element)
		//sqdmlal(scalar)
		//sqdmlsl(scalar, by element)
		//sqdmlsl(scalar)
		//sqdmulh(scalar, by element)
		//sqdmulh(scalar)
		//sqdmull(scalar, by element)
		//sqdmull(scalar)
		//sqneg(scalar)
		//sqrdmlah(scalar, by element)
		//sqrdmlah(scalar)
		//sqrdmlsh(scalar, by element)
		//sqrdmlsh(scalar)
		//sqrdmulh(scalar, by element)
		//sqrdmulh(scalar)
		//sqrshl(scalar)
		//sqrshrn(scalar)
		//sqrshrun(scalar)
		//sqshl(scalar, immediate)
		//sqshl(scalar, register)
		//sqshlu(scalar)
		//sqshrn(scalar)
		//sqshrun(scalar)
		//sqsub(scalar)
		//sqxtn(scalar)
		//sqxtun(scalar)
		//sri(scalar)
		//srshl(scalar)
		//srshr(scalar)
		//srsra(scalar)
		//sshl(scalar)
		//sshr(scalar)
		//ssra(scalar)
		//sub(scalar)
		//suqadd(scalar)
		//ucvtf(scalar, fixed - point)
		//ucvtf(scalar, integer)
		//uqadd(scalar)
		//uqrshl(scalar)
		//uqrshrn(scalar)
		//uqshl(scalar, immediate)
		//uqshl(scalar, register)
		//uqshrn(scalar)
		//uqsub(scalar)
		//uqxtn(scalar)
		//urshl(scalar)
		//urshr(scalar)
		//ursra(scalar)
		//ushl(scalar)
		//ushr(scalar)
		//usqadd(scalar)
		//usra(scalar)
		//a64 simd vector instructions
		//a64 simd vector instructions in alphabetical order
		//abs(vector)
		//add(vector)
		//addhn, addhn2(vector)
		//addp(vector)
		//addv(vector)
		//and(vector)
		//bic(vector, immediate)
		//bic(vector, register)
		//bif(vector)
		//bit(vector)
		//bsl(vector)
		//cls(vector)
		//clz(vector)
		//cmeq(vector, register)
		//cmeq(vector, zero)
		//cmge(vector, register)
		//cmge(vector, zero)
		//cmgt(vector, register)
		//cmgt(vector, zero)
		//cmhi(vector, register)
		//cmhs(vector, register)
		//cmle(vector, zero)
		//cmlt(vector, zero)
		//cmtst(vector)
		//cnt(vector)
		//dup(vector, element)
		//dup(vector, general)
		//eor(vector)
		//ext(vector)
		//fabd(vector)
		//fabs(vector)
		//facge(vector)
		//facgt(vector)
		//fadd(vector)
		//faddp(vector)
		//fcadd(vector)
		//fcmeq(vector, register)
		//fcmeq(vector, zero)
		//fcmge(vector, register)
		//fcmge(vector, zero)
		//fcmgt(vector, register)
		//fcmgt(vector, zero)
		//fcmla(vector)
		//fcmle(vector, zero)
		//fcmlt(vector, zero)
		//fcvtas(vector)
		//fcvtau(vector)
		//fcvtl, fcvtl2(vector)
		//fcvtms(vector)
		//fcvtmu(vector)
		//fcvtn, fcvtn2(vector)
		//fcvtns(vector)
		//fcvtnu(vector)
		//fcvtps(vector)
		//fcvtpu(vector)
		//fcvtxn, fcvtxn2(vector)
		//fcvtzs(vector, fixed - point)
		//fcvtzs(vector, integer)
		//fcvtzu(vector, fixed - point)
		//fcvtzu(vector, integer)
		//fdiv(vector)
		//fmax(vector)
		//fmaxnm(vector)
		//fmaxnmp(vector)
		//fmaxnmv(vector)
		//fmaxp(vector)
		//fmaxv(vector)
		//fmin(vector)
		//fminnm(vector)
		//fminnmp(vector)
		//fminnmv(vector)
		//fminp(vector)
		//fminv(vector)
		//fmla(vector, by element)
		//fmla(vector)
		//fmlal, (vector)
		//fmls(vector, by element)
		//fmls(vector)
		//fmlsl, (vector)
		//fmov(vector, immediate)
		//fmul(vector, by element)
		//fmul(vector)
		//fmulx(vector, by element)
		//fmulx(vector)
		//fneg(vector)
		//frecpe(vector)
		//frecps(vector)
		//frecpx(vector)
		//frinta(vector)
		//frinti(vector)
		//frintm(vector)
		//frintn(vector)
		//frintp(vector)
		//frintx(vector)
		//frintz(vector)
		//frsqrte(vector)
		//frsqrts(vector)
		//fsqrt(vector)
		//fsub(vector)
		//ins(vector, element)
		//ins(vector, general)
		//ld1(vector, multiple structures)
		//ld1(vector, single structure)
		//ld1r(vector)
		//ld2(vector, multiple structures)
		//ld2(vector, single structure)
		//ld2r(vector)
		//ld3(vector, multiple structures)
		//ld3(vector, single structure)
		//ld3r(vector)
		//ld4(vector, multiple structures)
		//ld4(vector, single structure)
		//ld4r(vector)
		//mla(vector, by element)
		//mla(vector)
		//mls(vector, by element)
		//mls(vector)
		//mov(vector, element)
		//mov(vector, from general)
		//mov(vector)
		//mov(vector, to general)
		//movi(vector)
		//mul(vector, by element)
		//mul(vector)
		//mvn(vector)
		//mvni(vector)
		//neg(vector)
		//not(vector)
		//orn(vector)
		//orr(vector, immediate)
		//orr(vector, register)
		//pmul(vector)
		//pmull, pmull2(vector)
		//raddhn, raddhn2(vector)
		//rbit(vector)
		//rev16(vector)
		//rev32(vector)
		//rev64(vector)
		//rshrn, rshrn2(vector)
		//rsubhn, rsubhn2(vector)
		//saba(vector)
		//sabal, sabal2(vector)
		//sabd(vector)
		//sabdl, sabdl2(vector)
		//sadalp(vector)
		//saddl, saddl2(vector)
		//saddlp(vector)
		//saddlv(vector)
		//saddw, saddw2(vector)
		//scvtf(vector, fixed - point)
		//scvtf(vector, integer)
		//sdot(vector, by element)
		//sdot(vector)
		//shadd(vector)
		//shl(vector)
		//shll, shll2(vector)
		//shrn, shrn2(vector)
		//shsub(vector)
		//sli(vector)
		//smax(vector)
		//smaxp(vector)
		//smaxv(vector)
		//smin(vector)
		//sminp(vector)
		//sminv(vector)
		//smlal, smlal2(vector, by element)
		//smlal, smlal2(vector)
		//smlsl, smlsl2(vector, by element)
		//smlsl, smlsl2(vector)
		//smov(vector)
		//smull, smull2(vector, by element)
		//smull, smull2(vector)
		//sqabs(vector)
		//sqadd(vector)
		//sqdmlal, sqdmlal2(vector, by element)
		//sqdmlal, sqdmlal2(vector)
		//sqdmlsl, sqdmlsl2(vector, by element)
		//sqdmlsl, sqdmlsl2(vector)
		//sqdmulh(vector, by element)
		//sqdmulh(vector)
		//sqdmull, sqdmull2(vector, by element)
		//sqdmull, sqdmull2(vector)
		//sqneg(vector)
		//sqrdmlah(vector, by element)
		//sqrdmlah(vector)
		//sqrdmlsh(vector, by element)
		//sqrdmlsh(vector)
		//sqrdmulh(vector, by element)
		//sqrdmulh(vector)
		//sqrshl(vector)
		//sqrshrn, sqrshrn2(vector)
		//sqrshrun, sqrshrun2(vector)
		//sqshl(vector, immediate)
		//sqshl(vector, register)
		//sqshlu(vector)
		//sqshrn, sqshrn2(vector)
		//sqshrun, sqshrun2(vector)
		//sqsub(vector)
		//sqxtn, sqxtn2(vector)
		//sqxtun, sqxtun2(vector)
		//srhadd(vector)
		//sri(vector)
		//srshl(vector)
		//srshr(vector)
		//srsra(vector)
		//sshl(vector)
		//sshll, sshll2(vector)
		//sshr(vector)
		//ssra(vector)
		//ssubl, ssubl2(vector)
		//ssubw, ssubw2(vector)
		//st1(vector, multiple structures)
		//st1(vector, single structure)
		//st2(vector, multiple structures)
		//st2(vector, single structure)
		//st3(vector, multiple structures)
		//st3(vector, single structure)
		//st4(vector, multiple structures)
		//st4(vector, single structure)
		//sub(vector)
		//subhn, subhn2(vector)
		//suqadd(vector)
		//sxtl, sxtl2(vector)
		//tbl(vector)
		//tbx(vector)
		//trn1(vector)
		//trn2(vector)
		//uaba(vector)
		//uabal, uabal2(vector)
		//uabd(vector)
		//uabdl, uabdl2(vector)
		//uadalp(vector)
		//uaddl, uaddl2(vector)
		//uaddlp(vector)
		//uaddlv(vector)
		//uaddw, uaddw2(vector)
		//ucvtf(vector, fixed - point)
		//ucvtf(vector, integer)
		//udot(vector, by element)
		//udot(vector)
		//uhadd(vector)
		//uhsub(vector)
		//umax(vector)
		//umaxp(vector)
		//umaxv(vector)
		//umin(vector)
		//uminp(vector)
		//uminv(vector)
		//umlal, umlal2(vector, by element)
		//umlal, umlal2(vector)
		//umlsl, umlsl2(vector, by element)
		//umlsl, umlsl2(vector)
		//umov(vector)
		//umull, umull2(vector, by element)
		//umull, umull2(vector)
		//uqadd(vector)
		//uqrshl(vector)
		//uqrshrn, uqrshrn2(vector)
		//uqshl(vector, immediate)
		//uqshl(vector, register)
		//uqshrn, uqshrn2(vector)
		//uqsub(vector)
		//uqxtn, uqxtn2(vector)
		//urecpe(vector)
		//urhadd(vector)
		//urshl(vector)
		//urshr(vector)
		//ursqrte(vector)
		//ursra(vector)
		//ushl(vector)
		//ushll, ushll2(vector)
		//ushr(vector)
		//usqadd(vector)
		//usra(vector)
		//usubl, usubl2(vector)
		//usubw, usubw2(vector)
		//uxtl, uxtl2(vector)
		//uzp1(vector)
		//uzp2(vector)
		//xtn, xtn2(vector)
		//zip1(vector)
		//zip2(vector)


		count
	};
}

#endif
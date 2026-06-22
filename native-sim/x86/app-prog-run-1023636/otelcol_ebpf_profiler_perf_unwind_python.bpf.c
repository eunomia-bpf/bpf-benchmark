extern char metrics;
extern char per_cpu_records;
extern char perf_progs;
extern char py_procs;
extern char tpbase_offset;
extern char with_debug_output;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 21ULL: goto x86_l_15;
	case 28ULL: goto x86_l_1c;
	case 33ULL: goto x86_l_21;
	case 38ULL: goto x86_l_26;
	case 40ULL: goto x86_l_28;
	case 43ULL: goto x86_l_2b;
	case 49ULL: goto x86_l_31;
	case 52ULL: goto x86_l_34;
	case 55ULL: goto x86_l_37;
	case 58ULL: goto x86_l_3a;
	case 65ULL: goto x86_l_41;
	case 72ULL: goto x86_l_48;
	case 76ULL: goto x86_l_4c;
	case 82ULL: goto x86_l_52;
	case 89ULL: goto x86_l_59;
	case 97ULL: goto x86_l_61;
	case 102ULL: goto x86_l_66;
	case 104ULL: goto x86_l_68;
	case 107ULL: goto x86_l_6b;
	case 110ULL: goto x86_l_6e;
	case 116ULL: goto x86_l_74;
	case 118ULL: goto x86_l_76;
	case 124ULL: goto x86_l_7c;
	case 131ULL: goto x86_l_83;
	case 138ULL: goto x86_l_8a;
	case 141ULL: goto x86_l_8d;
	case 147ULL: goto x86_l_93;
	case 149ULL: goto x86_l_95;
	case 153ULL: goto x86_l_99;
	case 159ULL: goto x86_l_9f;
	case 163ULL: goto x86_l_a3;
	case 169ULL: goto x86_l_a9;
	case 173ULL: goto x86_l_ad;
	case 179ULL: goto x86_l_b3;
	case 183ULL: goto x86_l_b7;
	case 189ULL: goto x86_l_bd;
	case 194ULL: goto x86_l_c2;
	case 198ULL: goto x86_l_c6;
	case 205ULL: goto x86_l_cd;
	case 210ULL: goto x86_l_d2;
	case 215ULL: goto x86_l_d7;
	case 218ULL: goto x86_l_da;
	case 223ULL: goto x86_l_df;
	case 226ULL: goto x86_l_e2;
	case 228ULL: goto x86_l_e4;
	case 231ULL: goto x86_l_e7;
	case 237ULL: goto x86_l_ed;
	case 241ULL: goto x86_l_f1;
	case 247ULL: goto x86_l_f7;
	case 255ULL: goto x86_l_ff;
	case 262ULL: goto x86_l_106;
	case 267ULL: goto x86_l_10b;
	case 272ULL: goto x86_l_110;
	case 274ULL: goto x86_l_112;
	case 277ULL: goto x86_l_115;
	case 283ULL: goto x86_l_11b;
	case 286ULL: goto x86_l_11e;
	case 291ULL: goto x86_l_123;
	case 293ULL: goto x86_l_125;
	case 299ULL: goto x86_l_12b;
	case 301ULL: goto x86_l_12d;
	case 303ULL: goto x86_l_12f;
	case 309ULL: goto x86_l_135;
	case 317ULL: goto x86_l_13d;
	case 324ULL: goto x86_l_144;
	case 329ULL: goto x86_l_149;
	case 334ULL: goto x86_l_14e;
	case 336ULL: goto x86_l_150;
	case 339ULL: goto x86_l_153;
	case 341ULL: goto x86_l_155;
	case 344ULL: goto x86_l_158;
	case 349ULL: goto x86_l_15d;
	case 354ULL: goto x86_l_162;
	case 360ULL: goto x86_l_168;
	case 367ULL: goto x86_l_16f;
	case 370ULL: goto x86_l_172;
	case 373ULL: goto x86_l_175;
	case 376ULL: goto x86_l_178;
	case 381ULL: goto x86_l_17d;
	case 385ULL: goto x86_l_181;
	case 391ULL: goto x86_l_187;
	case 396ULL: goto x86_l_18c;
	case 401ULL: goto x86_l_191;
	case 405ULL: goto x86_l_195;
	case 409ULL: goto x86_l_199;
	case 413ULL: goto x86_l_19d;
	case 417ULL: goto x86_l_1a1;
	case 421ULL: goto x86_l_1a5;
	case 425ULL: goto x86_l_1a9;
	case 428ULL: goto x86_l_1ac;
	case 430ULL: goto x86_l_1ae;
	case 433ULL: goto x86_l_1b1;
	case 435ULL: goto x86_l_1b3;
	case 440ULL: goto x86_l_1b8;
	case 443ULL: goto x86_l_1bb;
	case 448ULL: goto x86_l_1c0;
	case 451ULL: goto x86_l_1c3;
	case 457ULL: goto x86_l_1c9;
	case 463ULL: goto x86_l_1cf;
	case 465ULL: goto x86_l_1d1;
	case 469ULL: goto x86_l_1d5;
	case 474ULL: goto x86_l_1da;
	case 479ULL: goto x86_l_1df;
	case 485ULL: goto x86_l_1e5;
	case 491ULL: goto x86_l_1eb;
	case 496ULL: goto x86_l_1f0;
	case 500ULL: goto x86_l_1f4;
	case 504ULL: goto x86_l_1f8;
	case 509ULL: goto x86_l_1fd;
	case 514ULL: goto x86_l_202;
	case 516ULL: goto x86_l_204;
	case 520ULL: goto x86_l_208;
	case 525ULL: goto x86_l_20d;
	case 528ULL: goto x86_l_210;
	case 531ULL: goto x86_l_213;
	case 538ULL: goto x86_l_21a;
	case 540ULL: goto x86_l_21c;
	case 547ULL: goto x86_l_223;
	case 550ULL: goto x86_l_226;
	case 556ULL: goto x86_l_22c;
	case 560ULL: goto x86_l_230;
	case 564ULL: goto x86_l_234;
	case 569ULL: goto x86_l_239;
	case 572ULL: goto x86_l_23c;
	case 576ULL: goto x86_l_240;
	case 578ULL: goto x86_l_242;
	case 582ULL: goto x86_l_246;
	case 585ULL: goto x86_l_249;
	case 592ULL: goto x86_l_250;
	case 595ULL: goto x86_l_253;
	case 600ULL: goto x86_l_258;
	case 606ULL: goto x86_l_25e;
	case 610ULL: goto x86_l_262;
	case 616ULL: goto x86_l_268;
	case 620ULL: goto x86_l_26c;
	case 626ULL: goto x86_l_272;
	case 630ULL: goto x86_l_276;
	case 636ULL: goto x86_l_27c;
	case 640ULL: goto x86_l_280;
	case 646ULL: goto x86_l_286;
	case 651ULL: goto x86_l_28b;
	case 654ULL: goto x86_l_28e;
	case 659ULL: goto x86_l_293;
	case 664ULL: goto x86_l_298;
	case 667ULL: goto x86_l_29b;
	case 672ULL: goto x86_l_2a0;
	case 677ULL: goto x86_l_2a5;
	case 679ULL: goto x86_l_2a7;
	case 682ULL: goto x86_l_2aa;
	case 688ULL: goto x86_l_2b0;
	case 693ULL: goto x86_l_2b5;
	case 696ULL: goto x86_l_2b8;
	case 700ULL: goto x86_l_2bc;
	case 706ULL: goto x86_l_2c2;
	case 714ULL: goto x86_l_2ca;
	case 721ULL: goto x86_l_2d1;
	case 726ULL: goto x86_l_2d6;
	case 731ULL: goto x86_l_2db;
	case 733ULL: goto x86_l_2dd;
	case 736ULL: goto x86_l_2e0;
	case 742ULL: goto x86_l_2e6;
	case 745ULL: goto x86_l_2e9;
	case 750ULL: goto x86_l_2ee;
	case 755ULL: goto x86_l_2f3;
	case 758ULL: goto x86_l_2f6;
	case 762ULL: goto x86_l_2fa;
	case 768ULL: goto x86_l_300;
	case 776ULL: goto x86_l_308;
	case 783ULL: goto x86_l_30f;
	case 788ULL: goto x86_l_314;
	case 793ULL: goto x86_l_319;
	case 795ULL: goto x86_l_31b;
	case 798ULL: goto x86_l_31e;
	case 800ULL: goto x86_l_320;
	case 803ULL: goto x86_l_323;
	case 806ULL: goto x86_l_326;
	case 808ULL: goto x86_l_328;
	case 812ULL: goto x86_l_32c;
	case 815ULL: goto x86_l_32f;
	case 821ULL: goto x86_l_335;
	case 828ULL: goto x86_l_33c;
	case 830ULL: goto x86_l_33e;
	case 834ULL: goto x86_l_342;
	case 840ULL: goto x86_l_348;
	case 846ULL: goto x86_l_34e;
	case 850ULL: goto x86_l_352;
	case 856ULL: goto x86_l_358;
	case 860ULL: goto x86_l_35c;
	case 866ULL: goto x86_l_362;
	case 874ULL: goto x86_l_36a;
	case 881ULL: goto x86_l_371;
	case 886ULL: goto x86_l_376;
	case 891ULL: goto x86_l_37b;
	case 893ULL: goto x86_l_37d;
	case 896ULL: goto x86_l_380;
	case 902ULL: goto x86_l_386;
	case 905ULL: goto x86_l_389;
	case 910ULL: goto x86_l_38e;
	case 912ULL: goto x86_l_390;
	case 916ULL: goto x86_l_394;
	case 922ULL: goto x86_l_39a;
	case 928ULL: goto x86_l_3a0;
	case 938ULL: goto x86_l_3aa;
	case 943ULL: goto x86_l_3af;
	case 953ULL: goto x86_l_3b9;
	case 958ULL: goto x86_l_3be;
	case 968ULL: goto x86_l_3c8;
	case 973ULL: goto x86_l_3cd;
	case 983ULL: goto x86_l_3d7;
	case 988ULL: goto x86_l_3dc;
	case 993ULL: goto x86_l_3e1;
	case 998ULL: goto x86_l_3e6;
	case 1003ULL: goto x86_l_3eb;
	case 1008ULL: goto x86_l_3f0;
	case 1010ULL: goto x86_l_3f2;
	case 1012ULL: goto x86_l_3f4;
	case 1014ULL: goto x86_l_3f6;
	case 1019ULL: goto x86_l_3fb;
	case 1024ULL: goto x86_l_400;
	case 1034ULL: goto x86_l_40a;
	case 1039ULL: goto x86_l_40f;
	case 1049ULL: goto x86_l_419;
	case 1054ULL: goto x86_l_41e;
	case 1059ULL: goto x86_l_423;
	case 1064ULL: goto x86_l_428;
	case 1069ULL: goto x86_l_42d;
	case 1074ULL: goto x86_l_432;
	case 1079ULL: goto x86_l_437;
	case 1081ULL: goto x86_l_439;
	case 1083ULL: goto x86_l_43b;
	case 1088ULL: goto x86_l_440;
	case 1092ULL: goto x86_l_444;
	case 1097ULL: goto x86_l_449;
	case 1102ULL: goto x86_l_44e;
	case 1108ULL: goto x86_l_454;
	case 1114ULL: goto x86_l_45a;
	case 1119ULL: goto x86_l_45f;
	case 1129ULL: goto x86_l_469;
	case 1134ULL: goto x86_l_46e;
	case 1144ULL: goto x86_l_478;
	case 1149ULL: goto x86_l_47d;
	case 1159ULL: goto x86_l_487;
	case 1164ULL: goto x86_l_48c;
	case 1174ULL: goto x86_l_496;
	case 1179ULL: goto x86_l_49b;
	case 1184ULL: goto x86_l_4a0;
	case 1189ULL: goto x86_l_4a5;
	case 1195ULL: goto x86_l_4ab;
	case 1199ULL: goto x86_l_4af;
	case 1204ULL: goto x86_l_4b4;
	case 1207ULL: goto x86_l_4b7;
	case 1210ULL: goto x86_l_4ba;
	case 1213ULL: goto x86_l_4bd;
	case 1215ULL: goto x86_l_4bf;
	case 1218ULL: goto x86_l_4c2;
	case 1221ULL: goto x86_l_4c5;
	case 1224ULL: goto x86_l_4c8;
	case 1227ULL: goto x86_l_4cb;
	case 1234ULL: goto x86_l_4d2;
	case 1241ULL: goto x86_l_4d9;
	case 1244ULL: goto x86_l_4dc;
	case 1250ULL: goto x86_l_4e2;
	case 1255ULL: goto x86_l_4e7;
	case 1258ULL: goto x86_l_4ea;
	case 1266ULL: goto x86_l_4f2;
	case 1273ULL: goto x86_l_4f9;
	case 1278ULL: goto x86_l_4fe;
	case 1283ULL: goto x86_l_503;
	case 1285ULL: goto x86_l_505;
	case 1288ULL: goto x86_l_508;
	case 1290ULL: goto x86_l_50a;
	case 1293ULL: goto x86_l_50d;
	case 1295ULL: goto x86_l_50f;
	case 1299ULL: goto x86_l_513;
	case 1305ULL: goto x86_l_519;
	case 1310ULL: goto x86_l_51e;
	case 1312ULL: goto x86_l_520;
	case 1319ULL: goto x86_l_527;
	case 1322ULL: goto x86_l_52a;
	case 1330ULL: goto x86_l_532;
	case 1335ULL: goto x86_l_537;
	case 1341ULL: goto x86_l_53d;
	case 1346ULL: goto x86_l_542;
	case 1349ULL: goto x86_l_545;
	case 1352ULL: goto x86_l_548;
	case 1355ULL: goto x86_l_54b;
	case 1358ULL: goto x86_l_54e;
	case 1364ULL: goto x86_l_554;
	case 1366ULL: goto x86_l_556;
	case 1372ULL: goto x86_l_55c;
	case 1380ULL: goto x86_l_564;
	case 1387ULL: goto x86_l_56b;
	case 1392ULL: goto x86_l_570;
	case 1397ULL: goto x86_l_575;
	case 1399ULL: goto x86_l_577;
	case 1402ULL: goto x86_l_57a;
	case 1408ULL: goto x86_l_580;
	case 1411ULL: goto x86_l_583;
	case 1415ULL: goto x86_l_587;
	case 1421ULL: goto x86_l_58d;
	case 1431ULL: goto x86_l_597;
	case 1436ULL: goto x86_l_59c;
	case 1446ULL: goto x86_l_5a6;
	case 1451ULL: goto x86_l_5ab;
	case 1461ULL: goto x86_l_5b5;
	case 1466ULL: goto x86_l_5ba;
	case 1476ULL: goto x86_l_5c4;
	case 1481ULL: goto x86_l_5c9;
	case 1486ULL: goto x86_l_5ce;
	case 1491ULL: goto x86_l_5d3;
	case 1496ULL: goto x86_l_5d8;
	case 1501ULL: goto x86_l_5dd;
	case 1503ULL: goto x86_l_5df;
	case 1505ULL: goto x86_l_5e1;
	case 1510ULL: goto x86_l_5e6;
	case 1514ULL: goto x86_l_5ea;
	case 1517ULL: goto x86_l_5ed;
	case 1520ULL: goto x86_l_5f0;
	case 1522ULL: goto x86_l_5f2;
	case 1528ULL: goto x86_l_5f8;
	case 1536ULL: goto x86_l_600;
	case 1540ULL: goto x86_l_604;
	case 1548ULL: goto x86_l_60c;
	case 1553ULL: goto x86_l_611;
	case 1558ULL: goto x86_l_616;
	case 1563ULL: goto x86_l_61b;
	case 1566ULL: goto x86_l_61e;
	case 1568ULL: goto x86_l_620;
	case 1571ULL: goto x86_l_623;
	case 1577ULL: goto x86_l_629;
	case 1580ULL: goto x86_l_62c;
	case 1583ULL: goto x86_l_62f;
	case 1589ULL: goto x86_l_635;
	case 1597ULL: goto x86_l_63d;
	case 1604ULL: goto x86_l_644;
	case 1609ULL: goto x86_l_649;
	case 1614ULL: goto x86_l_64e;
	case 1616ULL: goto x86_l_650;
	case 1619ULL: goto x86_l_653;
	case 1622ULL: goto x86_l_656;
	case 1628ULL: goto x86_l_65c;
	case 1631ULL: goto x86_l_65f;
	case 1635ULL: goto x86_l_663;
	case 1640ULL: goto x86_l_668;
	case 1644ULL: goto x86_l_66c;
	case 1650ULL: goto x86_l_672;
	case 1658ULL: goto x86_l_67a;
	case 1665ULL: goto x86_l_681;
	case 1670ULL: goto x86_l_686;
	case 1675ULL: goto x86_l_68b;
	case 1677ULL: goto x86_l_68d;
	case 1680ULL: goto x86_l_690;
	case 1682ULL: goto x86_l_692;
	case 1685ULL: goto x86_l_695;
	case 1687ULL: goto x86_l_697;
	case 1691ULL: goto x86_l_69b;
	case 1697ULL: goto x86_l_6a1;
	case 1703ULL: goto x86_l_6a7;
	case 1709ULL: goto x86_l_6ad;
	case 1714ULL: goto x86_l_6b2;
	case 1722ULL: goto x86_l_6ba;
	case 1727ULL: goto x86_l_6bf;
	case 1730ULL: goto x86_l_6c2;
	case 1735ULL: goto x86_l_6c7;
	case 1740ULL: goto x86_l_6cc;
	case 1742ULL: goto x86_l_6ce;
	case 1747ULL: goto x86_l_6d3;
	case 1752ULL: goto x86_l_6d8;
	case 1757ULL: goto x86_l_6dd;
	case 1762ULL: goto x86_l_6e2;
	case 1767ULL: goto x86_l_6e7;
	case 1769ULL: goto x86_l_6e9;
	case 1772ULL: goto x86_l_6ec;
	case 1775ULL: goto x86_l_6ef;
	case 1777ULL: goto x86_l_6f1;
	case 1782ULL: goto x86_l_6f6;
	case 1785ULL: goto x86_l_6f9;
	case 1790ULL: goto x86_l_6fe;
	case 1794ULL: goto x86_l_702;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 152ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_15:
	/* 0x15: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&per_cpu_records)));
x86_l_1c:
	/* 0x1c: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21:
	/* 0x21: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26:
	/* 0x26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28:
	/* 0x28: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b:
	/* 0x2b: je     88b <perf_unwind_python+0x88b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2187ULL;
	}
x86_l_31:
	/* 0x31: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_34:
	/* 0x34: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_37:
	/* 0x37: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a:
	/* 0x3a: mov    DWORD PTR [rsp+0x88],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_41:
	/* 0x41: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_48:
	/* 0x48: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c:
	/* 0x4c: jne    400 <perf_unwind_python+0x400> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_400;
	}
x86_l_52:
	/* 0x52: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&py_procs)));
x86_l_59:
	/* 0x59: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_61:
	/* 0x61: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_66:
	/* 0x66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68:
	/* 0x68: mov    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6b:
	/* 0x6b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6e:
	/* 0x6e: je     12d <perf_unwind_python+0x12d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12d;
	}
x86_l_74:
	/* 0x74: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_76:
	/* 0x76: jne    45f <perf_unwind_python+0x45f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_45f;
	}
x86_l_7c:
	/* 0x7c: lea    rsi,[r15+0xf58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3928ULL);
x86_l_83:
	/* 0x83: mov    r13,QWORD PTR [rbp+0xf58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3928ULL);
x86_l_8a:
	/* 0x8a: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_8d:
	/* 0x8d: je     4e2 <perf_unwind_python+0x4e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e2;
	}
x86_l_93:
	/* 0x93: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_95:
	/* 0x95: cmp    BYTE PTR [rax+0x19],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 107374182520ULL);
x86_l_99:
	/* 0x99: ja     162 <perf_unwind_python+0x162> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_162;
	}
x86_l_9f:
	/* 0x9f: cmp    BYTE PTR [rax+0x18],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215224ULL);
x86_l_a3:
	/* 0xa3: ja     162 <perf_unwind_python+0x162> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_162;
	}
x86_l_a9:
	/* 0xa9: cmp    BYTE PTR [rax+0x1a],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 111669149816ULL);
x86_l_ad:
	/* 0xad: ja     162 <perf_unwind_python+0x162> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_162;
	}
x86_l_b3:
	/* 0xb3: cmp    BYTE PTR [rax+0x1b],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 115964116992ULL);
x86_l_b7:
	/* 0xb7: js     162 <perf_unwind_python+0x162> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_162;
	}
x86_l_bd:
	/* 0xbd: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c2:
	/* 0xc2: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c6:
	/* 0xc6: lea    r12,[r15+0xf80] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3968ULL);
x86_l_cd:
	/* 0xcd: mov    eax,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 128ULL);
x86_l_d2:
	/* 0xd2: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_d7:
	/* 0xd7: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_da:
	/* 0xda: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_df:
	/* 0xdf: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_e2:
	/* 0xe2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e4:
	/* 0xe4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e7:
	/* 0xe7: je     191 <perf_unwind_python+0x191> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_191;
	}
x86_l_ed:
	/* 0xed: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f1:
	/* 0xf1: jne    11a8 <perf_unwind_python+0x11a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4520ULL;
	}
x86_l_f7:
	/* 0xf7: mov    DWORD PTR [rsp+0x18],0x1b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215131ULL);
x86_l_ff:
	/* 0xff: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_106:
	/* 0x106: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10b:
	/* 0x10b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_110:
	/* 0x110: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_112:
	/* 0x112: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_115:
	/* 0x115: je     1d1 <perf_unwind_python+0x1d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d1;
	}
x86_l_11b:
	/* 0x11b: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_11e:
	/* 0x11e: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_123:
	/* 0x123: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_125:
	/* 0x125: mov    r12d,0x7d2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2002ULL);
x86_l_12b:
	/* 0x12b: jmp    168 <perf_unwind_python+0x168> */
	goto x86_l_168;
x86_l_12d:
	/* 0x12d: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_12f:
	/* 0x12f: jne    a47 <perf_unwind_python+0xa47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2631ULL;
	}
x86_l_135:
	/* 0x135: mov    DWORD PTR [rsp+0x18],0x45 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215173ULL);
x86_l_13d:
	/* 0x13d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_144:
	/* 0x144: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_149:
	/* 0x149: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14e:
	/* 0x14e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_150:
	/* 0x150: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_153:
	/* 0x153: je     17d <perf_unwind_python+0x17d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17d;
	}
x86_l_155:
	/* 0x155: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_158:
	/* 0x158: mov    eax,0x7d1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2001ULL);
x86_l_15d:
	/* 0x15d: jmp    890 <perf_unwind_python+0x890> */
	return 2192ULL;
x86_l_162:
	/* 0x162: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_168:
	/* 0x168: or     BYTE PTR [rbp+0x1380],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 21440476741648ULL);
x86_l_16f:
	/* 0x16f: mov    r15d,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_32);
x86_l_172:
	/* 0x172: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_175:
	/* 0x175: mov    QWORD PTR [rsi],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_178:
	/* 0x178: jmp    7da <perf_unwind_python+0x7da> */
	return 2010ULL;
x86_l_17d:
	/* 0x17d: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_181:
	/* 0x181: jne    c9a <perf_unwind_python+0xc9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3226ULL;
	}
x86_l_187:
	/* 0x187: mov    eax,0x7d1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2001ULL);
x86_l_18c:
	/* 0x18c: jmp    890 <perf_unwind_python+0x890> */
	return 2192ULL;
x86_l_191:
	/* 0x191: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_195:
	/* 0x195: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_199:
	/* 0x199: mov    rdx,QWORD PTR [r12+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_19d:
	/* 0x19d: movzx  ecx,BYTE PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_1a1:
	/* 0x1a1: mov    rdi,QWORD PTR [r12+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1a5:
	/* 0x1a5: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a9:
	/* 0x1a9: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1ac:
	/* 0x1ac: je     1f0 <perf_unwind_python+0x1f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f0;
	}
x86_l_1ae:
	/* 0x1ae: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1b1:
	/* 0x1b1: jne    1f0 <perf_unwind_python+0x1f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f0;
	}
x86_l_1b3:
	/* 0x1b3: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b8:
	/* 0x1b8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bb:
	/* 0x1bb: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1c0:
	/* 0x1c0: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_1c3:
	/* 0x1c3: je     c39 <perf_unwind_python+0xc39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3129ULL;
	}
x86_l_1c9:
	/* 0x1c9: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_1cf:
	/* 0x1cf: jmp    175 <perf_unwind_python+0x175> */
	goto x86_l_175;
x86_l_1d1:
	/* 0x1d1: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d5:
	/* 0x1d5: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1da:
	/* 0x1da: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_1df:
	/* 0x1df: jne    139d <perf_unwind_python+0x139d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5021ULL;
	}
x86_l_1e5:
	/* 0x1e5: mov    r12d,0x7d2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2002ULL);
x86_l_1eb:
	/* 0x1eb: jmp    168 <perf_unwind_python+0x168> */
	goto x86_l_168;
x86_l_1f0:
	/* 0x1f0: cmp    BYTE PTR [rax+0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_1f4:
	/* 0x1f4: movzx  ecx,BYTE PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 26ULL);
x86_l_1f8:
	/* 0x1f8: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fd:
	/* 0x1fd: mov    QWORD PTR [rsp+0x70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_202:
	/* 0x202: je     242 <perf_unwind_python+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_242;
	}
x86_l_204:
	/* 0x204: mov    rcx,QWORD PTR [r12+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_208:
	/* 0x208: movzx  r8d,BYTE PTR [rax+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_20d:
	/* 0x20d: add    r8,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_210:
	/* 0x210: sub    rcx,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_213:
	/* 0x213: lea    r8,[rcx-0x10000001] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073441116159ULL);
x86_l_21a:
	/* 0x21a: sar    ecx,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_21c:
	/* 0x21c: cmp    r8,0xffffffffeffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 18446744073441116157ULL);
x86_l_223:
	/* 0x223: mov    r8,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_64);
x86_l_226:
	/* 0x226: mov    r12d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_22c:
	/* 0x22c: cmovae r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_230:
	/* 0x230: movzx  ecx,BYTE PTR [rax+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_234:
	/* 0x234: movzx  ecx,BYTE PTR [r8+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_239:
	/* 0x239: cmp    cl,BYTE PTR [rax+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_23c:
	/* 0x23c: sete   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_E);
x86_l_240:
	/* 0x240: jmp    249 <perf_unwind_python+0x249> */
	goto x86_l_249;
x86_l_242:
	/* 0x242: mov    r12d,DWORD PTR [r12+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_246:
	/* 0x246: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_249:
	/* 0x249: add    r15,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_250:
	/* 0x250: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_253:
	/* 0x253: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_258:
	/* 0x258: je     2ee <perf_unwind_python+0x2ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ee;
	}
x86_l_25e:
	/* 0x25e: cmp    BYTE PTR [rax+0x1d],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051772ULL);
x86_l_262:
	/* 0x262: ja     c29 <perf_unwind_python+0xc29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3113ULL;
	}
x86_l_268:
	/* 0x268: cmp    BYTE PTR [rax+0x1e],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128849019068ULL);
x86_l_26c:
	/* 0x26c: ja     c29 <perf_unwind_python+0xc29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3113ULL;
	}
x86_l_272:
	/* 0x272: cmp    BYTE PTR [rax+0x1f],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133143986364ULL);
x86_l_276:
	/* 0x276: ja     c29 <perf_unwind_python+0xc29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3113ULL;
	}
x86_l_27c:
	/* 0x27c: cmp    BYTE PTR [rax+0x20],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953660ULL);
x86_l_280:
	/* 0x280: ja     c29 <perf_unwind_python+0xc29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3113ULL;
	}
x86_l_286:
	/* 0x286: mov    DWORD PTR [rsp+0x8],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28b:
	/* 0x28b: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_28e:
	/* 0x28e: mov    eax,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 192ULL);
x86_l_293:
	/* 0x293: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_298:
	/* 0x298: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_29b:
	/* 0x29b: mov    esi,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 192ULL);
x86_l_2a0:
	/* 0x2a0: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a5:
	/* 0x2a5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2a7:
	/* 0x2a7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2aa:
	/* 0x2aa: je     ab7 <perf_unwind_python+0xab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2743ULL;
	}
x86_l_2b0:
	/* 0x2b0: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b5:
	/* 0x2b5: mov    rbx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R14, X86_WIDTH_64);
x86_l_2b8:
	/* 0x2b8: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bc:
	/* 0x2bc: jne    1af5 <perf_unwind_python+0x1af5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6901ULL;
	}
x86_l_2c2:
	/* 0x2c2: mov    DWORD PTR [rsp+0x18],0x1e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215134ULL);
x86_l_2ca:
	/* 0x2ca: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_2d1:
	/* 0x2d1: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d6:
	/* 0x2d6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2db:
	/* 0x2db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dd:
	/* 0x2dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e0:
	/* 0x2e0: je     d65 <perf_unwind_python+0xd65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3429ULL;
	}
x86_l_2e6:
	/* 0x2e6: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2e9:
	/* 0x2e9: jmp    d6e <perf_unwind_python+0xd6e> */
	return 3438ULL;
x86_l_2ee:
	/* 0x2ee: mov    DWORD PTR [rsp+0x8],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f3:
	/* 0x2f3: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_2f6:
	/* 0x2f6: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fa:
	/* 0x2fa: jne    15d1 <perf_unwind_python+0x15d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5585ULL;
	}
x86_l_300:
	/* 0x300: mov    DWORD PTR [rsp+0x18],0x1c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215132ULL);
x86_l_308:
	/* 0x308: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_30f:
	/* 0x30f: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_314:
	/* 0x314: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_319:
	/* 0x319: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31b:
	/* 0x31b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31e:
	/* 0x31e: je     328 <perf_unwind_python+0x328> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_328;
	}
x86_l_320:
	/* 0x320: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_323:
	/* 0x323: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_326:
	/* 0x326: jmp    335 <perf_unwind_python+0x335> */
	goto x86_l_335;
x86_l_328:
	/* 0x328: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32c:
	/* 0x32c: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_32f:
	/* 0x32f: jne    17f2 <perf_unwind_python+0x17f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6130ULL;
	}
x86_l_335:
	/* 0x335: mov    r12,0xfffffffffffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_33c:
	/* 0x33c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33e:
	/* 0x33e: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_342:
	/* 0x342: jne    afe <perf_unwind_python+0xafe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2814ULL;
	}
x86_l_348:
	/* 0x348: mov    eax,DWORD PTR [rbp+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_34e:
	/* 0x34e: cmp    rax,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 127ULL);
x86_l_352:
	/* 0x352: jb     b68 <perf_unwind_python+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2920ULL;
	}
x86_l_358:
	/* 0x358: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35c:
	/* 0x35c: jne    1658 <perf_unwind_python+0x1658> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5720ULL;
	}
x86_l_362:
	/* 0x362: mov    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_36a:
	/* 0x36a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_371:
	/* 0x371: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_376:
	/* 0x376: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37b:
	/* 0x37b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37d:
	/* 0x37d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_380:
	/* 0x380: je     440 <perf_unwind_python+0x440> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_440;
	}
x86_l_386:
	/* 0x386: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_389:
	/* 0x389: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38e:
	/* 0x38e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_390:
	/* 0x390: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_394:
	/* 0x394: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_39a:
	/* 0x39a: je     168 <perf_unwind_python+0x168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_168;
	}
x86_l_3a0:
	/* 0x3a0: movabs rax,0xa656d61726620 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926270227834400ULL);
x86_l_3aa:
	/* 0x3aa: mov    QWORD PTR [rsp+0x45],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_3af:
	/* 0x3af: movabs rax,0x7266206e6f687479 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243311826635879545ULL);
x86_l_3b9:
	/* 0x3b9: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3be:
	/* 0x3be: movabs rax,0x702068737570206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8079572576603480175ULL);
x86_l_3c8:
	/* 0x3c8: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3cd:
	/* 0x3cd: movabs rax,0x742064656c696166 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701606ULL);
x86_l_3d7:
	/* 0x3d7: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3dc:
	/* 0x3dc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3e1:
	/* 0x3e1: mov    eax,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_3e6:
	/* 0x3e6: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3eb:
	/* 0x3eb: mov    esi,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 29ULL);
x86_l_3f0:
	/* 0x3f0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f2:
	/* 0x3f2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3f4:
	/* 0x3f4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f6:
	/* 0x3f6: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3fb:
	/* 0x3fb: jmp    168 <perf_unwind_python+0x168> */
	goto x86_l_168;
x86_l_400:
	/* 0x400: movabs rax,0xa29286e6f687479 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 732160869205046393ULL);
x86_l_40a:
	/* 0x40a: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_40f:
	/* 0x40f: movabs rax,0x705f646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8097301080414056053ULL);
x86_l_419:
	/* 0x419: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_41e:
	/* 0x41e: mov    BYTE PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_423:
	/* 0x423: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_428:
	/* 0x428: mov    eax,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_42d:
	/* 0x42d: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_432:
	/* 0x432: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_437:
	/* 0x437: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_439:
	/* 0x439: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_43b:
	/* 0x43b: jmp    52 <perf_unwind_python+0x52> */
	goto x86_l_52;
x86_l_440:
	/* 0x440: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_444:
	/* 0x444: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_449:
	/* 0x449: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_44e:
	/* 0x44e: jne    18f7 <perf_unwind_python+0x18f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6391ULL;
	}
x86_l_454:
	/* 0x454: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_45a:
	/* 0x45a: jmp    168 <perf_unwind_python+0x168> */
	goto x86_l_168;
x86_l_45f:
	/* 0x45f: movabs rcx,0xa782578302072 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2946852092649586ULL);
x86_l_469:
	/* 0x469: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_46e:
	/* 0x46e: movabs rcx,0x6f66206b63617473 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 8027139031435408499ULL);
x86_l_478:
	/* 0x478: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_47d:
	/* 0x47d: movabs rcx,0x206e6f6874795020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2336927751073255456ULL);
x86_l_487:
	/* 0x487: mov    QWORD PTR [rsp+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_48c:
	/* 0x48c: movabs rcx,0x676e69646c697542 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 7453010313381246274ULL);
x86_l_496:
	/* 0x496: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_49b:
	/* 0x49b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4a0:
	/* 0x4a0: mov    ecx,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_4a5:
	/* 0x4a5: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_4ab:
	/* 0x4ab: movzx  edx,WORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_4af:
	/* 0x4af: mov    esi,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32ULL);
x86_l_4b4:
	/* 0x4b4: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_4b7:
	/* 0x4b7: mov    rbx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R14, X86_WIDTH_64);
x86_l_4ba:
	/* 0x4ba: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_4bd:
	/* 0x4bd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bf:
	/* 0x4bf: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4c2:
	/* 0x4c2: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_4c5:
	/* 0x4c5: mov    r14,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBX, X86_WIDTH_64);
x86_l_4c8:
	/* 0x4c8: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_4cb:
	/* 0x4cb: lea    rsi,[r15+0xf58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3928ULL);
x86_l_4d2:
	/* 0x4d2: mov    r13,QWORD PTR [rbp+0xf58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3928ULL);
x86_l_4d9:
	/* 0x4d9: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_4dc:
	/* 0x4dc: jne    93 <perf_unwind_python+0x93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_93;
	}
x86_l_4e2:
	/* 0x4e2: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e7:
	/* 0x4e7: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_4ea:
	/* 0x4ea: mov    DWORD PTR [rsp+0x18],0x15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215125ULL);
x86_l_4f2:
	/* 0x4f2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_4f9:
	/* 0x4f9: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4fe:
	/* 0x4fe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_503:
	/* 0x503: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_505:
	/* 0x505: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_508:
	/* 0x508: je     50f <perf_unwind_python+0x50f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50f;
	}
x86_l_50a:
	/* 0x50a: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_50d:
	/* 0x50d: jmp    519 <perf_unwind_python+0x519> */
	goto x86_l_519;
x86_l_50f:
	/* 0x50f: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_513:
	/* 0x513: jne    d88 <perf_unwind_python+0xd88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3464ULL;
	}
x86_l_519:
	/* 0x519: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_51e:
	/* 0x51e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_520:
	/* 0x520: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&tpbase_offset)));
x86_l_527:
	/* 0x527: add    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_52a:
	/* 0x52a: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_532:
	/* 0x532: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_537:
	/* 0x537: mov    r8d,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 113ULL);
x86_l_53d:
	/* 0x53d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_542:
	/* 0x542: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_545:
	/* 0x545: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_548:
	/* 0x548: mov    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54b:
	/* 0x54b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_54e:
	/* 0x54e: je     5e6 <perf_unwind_python+0x5e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e6;
	}
x86_l_554:
	/* 0x554: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_556:
	/* 0x556: jne    c41 <perf_unwind_python+0xc41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3137ULL;
	}
x86_l_55c:
	/* 0x55c: mov    DWORD PTR [rsp+0x18],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215108ULL);
x86_l_564:
	/* 0x564: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_56b:
	/* 0x56b: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_570:
	/* 0x570: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_575:
	/* 0x575: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_577:
	/* 0x577: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_57a:
	/* 0x57a: je     668 <perf_unwind_python+0x668> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_668;
	}
x86_l_580:
	/* 0x580: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_583:
	/* 0x583: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_587:
	/* 0x587: je     672 <perf_unwind_python+0x672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_672;
	}
x86_l_58d:
	/* 0x58d: movabs rax,0xa737365726464 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2941689227535460ULL);
x86_l_597:
	/* 0x597: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_59c:
	/* 0x59c: movabs rax,0x6120657361622044 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 6998705367163215940ULL);
x86_l_5a6:
	/* 0x5a6: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5ab:
	/* 0x5ab: movabs rax,0x535420746567206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 6004459887481266287ULL);
x86_l_5b5:
	/* 0x5b5: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5ba:
	/* 0x5ba: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_5c4:
	/* 0x5c4: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5c9:
	/* 0x5c9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5ce:
	/* 0x5ce: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_5d3:
	/* 0x5d3: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5d8:
	/* 0x5d8: mov    esi,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32ULL);
x86_l_5dd:
	/* 0x5dd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5df:
	/* 0x5df: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5e1:
	/* 0x5e1: jmp    672 <perf_unwind_python+0x672> */
	goto x86_l_672;
x86_l_5e6:
	/* 0x5e6: mov    QWORD PTR [rsp],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ea:
	/* 0x5ea: mov    rbp,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RBX, X86_WIDTH_64);
x86_l_5ed:
	/* 0x5ed: mov    rbx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R14, X86_WIDTH_64);
x86_l_5f0:
	/* 0x5f0: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_5f2:
	/* 0x5f2: jne    e03 <perf_unwind_python+0xe03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3587ULL;
	}
x86_l_5f8:
	/* 0x5f8: mov    r14,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_600:
	/* 0x600: mov    r12,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_604:
	/* 0x604: lea    rdi,[rsp+0x8c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_60c:
	/* 0x60c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_611:
	/* 0x611: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_616:
	/* 0x616: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_61b:
	/* 0x61b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_61e:
	/* 0x61e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_620:
	/* 0x620: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_623:
	/* 0x623: je     6b2 <perf_unwind_python+0x6b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6b2;
	}
x86_l_629:
	/* 0x629: mov    r14,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBX, X86_WIDTH_64);
x86_l_62c:
	/* 0x62c: cmp    DWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62f:
	/* 0x62f: jne    ef4 <perf_unwind_python+0xef4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3828ULL;
	}
x86_l_635:
	/* 0x635: mov    DWORD PTR [rsp+0x18],0x46 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215174ULL);
x86_l_63d:
	/* 0x63d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_644:
	/* 0x644: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_649:
	/* 0x649: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_64e:
	/* 0x64e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_650:
	/* 0x650: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_653:
	/* 0x653: mov    rbx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RBP, X86_WIDTH_64);
x86_l_656:
	/* 0x656: je     775 <perf_unwind_python+0x775> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1909ULL;
	}
x86_l_65c:
	/* 0x65c: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_65f:
	/* 0x65f: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_663:
	/* 0x663: jmp    783 <perf_unwind_python+0x783> */
	return 1923ULL;
x86_l_668:
	/* 0x668: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66c:
	/* 0x66c: jne    f5f <perf_unwind_python+0xf5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3935ULL;
	}
x86_l_672:
	/* 0x672: mov    DWORD PTR [rsp+0x18],0x48 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215176ULL);
x86_l_67a:
	/* 0x67a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_681:
	/* 0x681: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_686:
	/* 0x686: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_68b:
	/* 0x68b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68d:
	/* 0x68d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_690:
	/* 0x690: je     697 <perf_unwind_python+0x697> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_697;
	}
x86_l_692:
	/* 0x692: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_695:
	/* 0x695: jmp    6a1 <perf_unwind_python+0x6a1> */
	goto x86_l_6a1;
x86_l_697:
	/* 0x697: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_69b:
	/* 0x69b: jne    fe4 <perf_unwind_python+0xfe4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4068ULL;
	}
x86_l_6a1:
	/* 0x6a1: mov    r12d,0x7d8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2008ULL);
x86_l_6a7:
	/* 0x6a7: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_6ad:
	/* 0x6ad: jmp    7da <perf_unwind_python+0x7da> */
	return 2010ULL;
x86_l_6b2:
	/* 0x6b2: movsxd r12,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 140ULL);
x86_l_6ba:
	/* 0x6ba: movsx  rcx,WORD PTR [r13+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_6bf:
	/* 0x6bf: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6c2:
	/* 0x6c2: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6c7:
	/* 0x6c7: cmp    BYTE PTR [r13+0x15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313216ULL);
x86_l_6cc:
	/* 0x6cc: je     6f6 <perf_unwind_python+0x6f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6f6;
	}
x86_l_6ce:
	/* 0x6ce: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6d3:
	/* 0x6d3: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6d8:
	/* 0x6d8: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_6dd:
	/* 0x6dd: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6e2:
	/* 0x6e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6e7:
	/* 0x6e7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6e9:
	/* 0x6e9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6ec:
	/* 0x6ec: mov    r14,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBX, X86_WIDTH_64);
x86_l_6ef:
	/* 0x6ef: jne    73f <perf_unwind_python+0x73f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1855ULL;
	}
x86_l_6f1:
	/* 0x6f1: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6f6:
	/* 0x6f6: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_6f9:
	/* 0x6f9: movzx  eax,BYTE PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_6fe:
	/* 0x6fe: imul   rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_702:
	/* 0x702: add    rax,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
	return 1797ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1797ULL: goto x86_l_705;
	case 1802ULL: goto x86_l_70a;
	case 1805ULL: goto x86_l_70d;
	case 1808ULL: goto x86_l_710;
	case 1814ULL: goto x86_l_716;
	case 1822ULL: goto x86_l_71e;
	case 1827ULL: goto x86_l_723;
	case 1833ULL: goto x86_l_729;
	case 1838ULL: goto x86_l_72e;
	case 1843ULL: goto x86_l_733;
	case 1846ULL: goto x86_l_736;
	case 1849ULL: goto x86_l_739;
	case 1855ULL: goto x86_l_73f;
	case 1859ULL: goto x86_l_743;
	case 1865ULL: goto x86_l_749;
	case 1873ULL: goto x86_l_751;
	case 1880ULL: goto x86_l_758;
	case 1885ULL: goto x86_l_75d;
	case 1890ULL: goto x86_l_762;
	case 1892ULL: goto x86_l_764;
	case 1895ULL: goto x86_l_767;
	case 1898ULL: goto x86_l_76a;
	case 1900ULL: goto x86_l_76c;
	case 1903ULL: goto x86_l_76f;
	case 1907ULL: goto x86_l_773;
	case 1909ULL: goto x86_l_775;
	case 1913ULL: goto x86_l_779;
	case 1917ULL: goto x86_l_77d;
	case 1923ULL: goto x86_l_783;
	case 1929ULL: goto x86_l_789;
	case 1935ULL: goto x86_l_78f;
	case 1937ULL: goto x86_l_791;
	case 1941ULL: goto x86_l_795;
	case 1945ULL: goto x86_l_799;
	case 1951ULL: goto x86_l_79f;
	case 1959ULL: goto x86_l_7a7;
	case 1966ULL: goto x86_l_7ae;
	case 1971ULL: goto x86_l_7b3;
	case 1976ULL: goto x86_l_7b8;
	case 1978ULL: goto x86_l_7ba;
	case 1981ULL: goto x86_l_7bd;
	case 1983ULL: goto x86_l_7bf;
	case 1986ULL: goto x86_l_7c2;
	case 1988ULL: goto x86_l_7c4;
	case 1992ULL: goto x86_l_7c8;
	case 1998ULL: goto x86_l_7ce;
	case 2004ULL: goto x86_l_7d4;
	case 2010ULL: goto x86_l_7da;
	case 2017ULL: goto x86_l_7e1;
	case 2025ULL: goto x86_l_7e9;
	case 2032ULL: goto x86_l_7f0;
	case 2037ULL: goto x86_l_7f5;
	case 2042ULL: goto x86_l_7fa;
	case 2044ULL: goto x86_l_7fc;
	case 2047ULL: goto x86_l_7ff;
	case 2049ULL: goto x86_l_801;
	case 2056ULL: goto x86_l_808;
	case 2059ULL: goto x86_l_80b;
	case 2061ULL: goto x86_l_80d;
	case 2064ULL: goto x86_l_810;
	case 2074ULL: goto x86_l_81a;
	case 2082ULL: goto x86_l_822;
	case 2089ULL: goto x86_l_829;
	case 2094ULL: goto x86_l_82e;
	case 2099ULL: goto x86_l_833;
	case 2101ULL: goto x86_l_835;
	case 2104ULL: goto x86_l_838;
	case 2106ULL: goto x86_l_83a;
	case 2109ULL: goto x86_l_83d;
	case 2111ULL: goto x86_l_83f;
	case 2118ULL: goto x86_l_846;
	case 2120ULL: goto x86_l_848;
	case 2125ULL: goto x86_l_84d;
	case 2128ULL: goto x86_l_850;
	case 2130ULL: goto x86_l_852;
	case 2132ULL: goto x86_l_854;
	case 2136ULL: goto x86_l_858;
	case 2142ULL: goto x86_l_85e;
	case 2145ULL: goto x86_l_861;
	case 2153ULL: goto x86_l_869;
	case 2156ULL: goto x86_l_86c;
	case 2158ULL: goto x86_l_86e;
	case 2164ULL: goto x86_l_874;
	case 2167ULL: goto x86_l_877;
	case 2174ULL: goto x86_l_87e;
	case 2179ULL: goto x86_l_883;
	case 2182ULL: goto x86_l_886;
	case 2185ULL: goto x86_l_889;
	case 2187ULL: goto x86_l_88b;
	case 2192ULL: goto x86_l_890;
	case 2199ULL: goto x86_l_897;
	case 2201ULL: goto x86_l_899;
	case 2202ULL: goto x86_l_89a;
	case 2207ULL: goto x86_l_89f;
	case 2215ULL: goto x86_l_8a7;
	case 2218ULL: goto x86_l_8aa;
	case 2220ULL: goto x86_l_8ac;
	case 2225ULL: goto x86_l_8b1;
	case 2228ULL: goto x86_l_8b4;
	case 2233ULL: goto x86_l_8b9;
	case 2239ULL: goto x86_l_8bf;
	case 2244ULL: goto x86_l_8c4;
	case 2249ULL: goto x86_l_8c9;
	case 2257ULL: goto x86_l_8d1;
	case 2262ULL: goto x86_l_8d6;
	case 2265ULL: goto x86_l_8d9;
	case 2268ULL: goto x86_l_8dc;
	case 2271ULL: goto x86_l_8df;
	case 2273ULL: goto x86_l_8e1;
	case 2277ULL: goto x86_l_8e5;
	case 2281ULL: goto x86_l_8e9;
	case 2287ULL: goto x86_l_8ef;
	case 2295ULL: goto x86_l_8f7;
	case 2302ULL: goto x86_l_8fe;
	case 2307ULL: goto x86_l_903;
	case 2312ULL: goto x86_l_908;
	case 2314ULL: goto x86_l_90a;
	case 2317ULL: goto x86_l_90d;
	case 2323ULL: goto x86_l_913;
	case 2326ULL: goto x86_l_916;
	case 2331ULL: goto x86_l_91b;
	case 2335ULL: goto x86_l_91f;
	case 2338ULL: goto x86_l_922;
	case 2344ULL: goto x86_l_928;
	case 2352ULL: goto x86_l_930;
	case 2359ULL: goto x86_l_937;
	case 2364ULL: goto x86_l_93c;
	case 2369ULL: goto x86_l_941;
	case 2371ULL: goto x86_l_943;
	case 2374ULL: goto x86_l_946;
	case 2378ULL: goto x86_l_94a;
	case 2384ULL: goto x86_l_950;
	case 2387ULL: goto x86_l_953;
	case 2392ULL: goto x86_l_958;
	case 2395ULL: goto x86_l_95b;
	case 2400ULL: goto x86_l_960;
	case 2404ULL: goto x86_l_964;
	case 2406ULL: goto x86_l_966;
	case 2410ULL: goto x86_l_96a;
	case 2415ULL: goto x86_l_96f;
	case 2418ULL: goto x86_l_972;
	case 2423ULL: goto x86_l_977;
	case 2429ULL: goto x86_l_97d;
	case 2433ULL: goto x86_l_981;
	case 2436ULL: goto x86_l_984;
	case 2441ULL: goto x86_l_989;
	case 2444ULL: goto x86_l_98c;
	case 2447ULL: goto x86_l_98f;
	case 2450ULL: goto x86_l_992;
	case 2453ULL: goto x86_l_995;
	case 2455ULL: goto x86_l_997;
	case 2459ULL: goto x86_l_99b;
	case 2465ULL: goto x86_l_9a1;
	case 2473ULL: goto x86_l_9a9;
	case 2480ULL: goto x86_l_9b0;
	case 2485ULL: goto x86_l_9b5;
	case 2490ULL: goto x86_l_9ba;
	case 2492ULL: goto x86_l_9bc;
	case 2495ULL: goto x86_l_9bf;
	case 2497ULL: goto x86_l_9c1;
	case 2500ULL: goto x86_l_9c4;
	case 2502ULL: goto x86_l_9c6;
	case 2506ULL: goto x86_l_9ca;
	case 2512ULL: goto x86_l_9d0;
	case 2518ULL: goto x86_l_9d6;
	case 2524ULL: goto x86_l_9dc;
	case 2529ULL: goto x86_l_9e1;
	case 2534ULL: goto x86_l_9e6;
	case 2537ULL: goto x86_l_9e9;
	case 2540ULL: goto x86_l_9ec;
	case 2546ULL: goto x86_l_9f2;
	case 2550ULL: goto x86_l_9f6;
	case 2556ULL: goto x86_l_9fc;
	case 2563ULL: goto x86_l_a03;
	case 2566ULL: goto x86_l_a06;
	case 2572ULL: goto x86_l_a0c;
	case 2577ULL: goto x86_l_a11;
	case 2581ULL: goto x86_l_a15;
	case 2587ULL: goto x86_l_a1b;
	case 2593ULL: goto x86_l_a21;
	case 2599ULL: goto x86_l_a27;
	case 2604ULL: goto x86_l_a2c;
	case 2608ULL: goto x86_l_a30;
	case 2614ULL: goto x86_l_a36;
	case 2620ULL: goto x86_l_a3c;
	case 2626ULL: goto x86_l_a42;
	case 2631ULL: goto x86_l_a47;
	case 2641ULL: goto x86_l_a51;
	case 2646ULL: goto x86_l_a56;
	case 2656ULL: goto x86_l_a60;
	case 2661ULL: goto x86_l_a65;
	case 2671ULL: goto x86_l_a6f;
	case 2676ULL: goto x86_l_a74;
	case 2686ULL: goto x86_l_a7e;
	case 2691ULL: goto x86_l_a83;
	case 2701ULL: goto x86_l_a8d;
	case 2706ULL: goto x86_l_a92;
	case 2714ULL: goto x86_l_a9a;
	case 2719ULL: goto x86_l_a9f;
	case 2724ULL: goto x86_l_aa4;
	case 2729ULL: goto x86_l_aa9;
	case 2734ULL: goto x86_l_aae;
	case 2736ULL: goto x86_l_ab0;
	case 2738ULL: goto x86_l_ab2;
	case 2743ULL: goto x86_l_ab7;
	case 2747ULL: goto x86_l_abb;
	case 2751ULL: goto x86_l_abf;
	case 2755ULL: goto x86_l_ac3;
	case 2759ULL: goto x86_l_ac7;
	case 2763ULL: goto x86_l_acb;
	case 2767ULL: goto x86_l_acf;
	case 2771ULL: goto x86_l_ad3;
	case 2775ULL: goto x86_l_ad7;
	case 2778ULL: goto x86_l_ada;
	case 2781ULL: goto x86_l_add;
	case 2783ULL: goto x86_l_adf;
	case 2786ULL: goto x86_l_ae2;
	case 2788ULL: goto x86_l_ae4;
	case 2792ULL: goto x86_l_ae8;
	case 2796ULL: goto x86_l_aec;
	case 2799ULL: goto x86_l_aef;
	case 2804ULL: goto x86_l_af4;
	case 2808ULL: goto x86_l_af8;
	case 2814ULL: goto x86_l_afe;
	case 2824ULL: goto x86_l_b08;
	case 2829ULL: goto x86_l_b0d;
	case 2839ULL: goto x86_l_b17;
	case 2844ULL: goto x86_l_b1c;
	case 2854ULL: goto x86_l_b26;
	case 2859ULL: goto x86_l_b2b;
	case 2864ULL: goto x86_l_b30;
	case 2869ULL: goto x86_l_b35;
	case 2874ULL: goto x86_l_b3a;
	case 2880ULL: goto x86_l_b40;
	case 2885ULL: goto x86_l_b45;
	case 2888ULL: goto x86_l_b48;
	case 2890ULL: goto x86_l_b4a;
	case 2893ULL: goto x86_l_b4d;
	case 2896ULL: goto x86_l_b50;
	case 2899ULL: goto x86_l_b53;
	case 2904ULL: goto x86_l_b58;
	case 2910ULL: goto x86_l_b5e;
	case 2914ULL: goto x86_l_b62;
	case 2920ULL: goto x86_l_b68;
	case 2925ULL: goto x86_l_b6d;
	case 2928ULL: goto x86_l_b70;
	case 2934ULL: goto x86_l_b76;
	case 2938ULL: goto x86_l_b7a;
	case 2946ULL: goto x86_l_b82;
	case 2954ULL: goto x86_l_b8a;
	case 2962ULL: goto x86_l_b92;
	case 2973ULL: goto x86_l_b9d;
	case 2984ULL: goto x86_l_ba8;
	case 2992ULL: goto x86_l_bb0;
	case 2999ULL: goto x86_l_bb7;
	case 3004ULL: goto x86_l_bbc;
	case 3009ULL: goto x86_l_bc1;
	case 3011ULL: goto x86_l_bc3;
	case 3014ULL: goto x86_l_bc6;
	case 3016ULL: goto x86_l_bc8;
	case 3019ULL: goto x86_l_bcb;
	case 3023ULL: goto x86_l_bcf;
	case 3028ULL: goto x86_l_bd4;
	case 3033ULL: goto x86_l_bd9;
	case 3036ULL: goto x86_l_bdc;
	case 3041ULL: goto x86_l_be1;
	case 3047ULL: goto x86_l_be7;
	case 3049ULL: goto x86_l_be9;
	case 3053ULL: goto x86_l_bed;
	case 3057ULL: goto x86_l_bf1;
	case 3062ULL: goto x86_l_bf6;
	case 3067ULL: goto x86_l_bfb;
	case 3073ULL: goto x86_l_c01;
	case 3076ULL: goto x86_l_c04;
	case 3081ULL: goto x86_l_c09;
	case 3087ULL: goto x86_l_c0f;
	case 3090ULL: goto x86_l_c12;
	case 3093ULL: goto x86_l_c15;
	case 3095ULL: goto x86_l_c17;
	case 3099ULL: goto x86_l_c1b;
	case 3101ULL: goto x86_l_c1d;
	case 3105ULL: goto x86_l_c21;
	case 3111ULL: goto x86_l_c27;
	case 3113ULL: goto x86_l_c29;
	case 3116ULL: goto x86_l_c2c;
	case 3122ULL: goto x86_l_c32;
	case 3127ULL: goto x86_l_c37;
	case 3129ULL: goto x86_l_c39;
	case 3132ULL: goto x86_l_c3c;
	case 3137ULL: goto x86_l_c41;
	case 3147ULL: goto x86_l_c4b;
	case 3152ULL: goto x86_l_c50;
	case 3162ULL: goto x86_l_c5a;
	case 3167ULL: goto x86_l_c5f;
	case 3177ULL: goto x86_l_c69;
	case 3182ULL: goto x86_l_c6e;
	case 3192ULL: goto x86_l_c78;
	case 3197ULL: goto x86_l_c7d;
	case 3202ULL: goto x86_l_c82;
	case 3207ULL: goto x86_l_c87;
	case 3212ULL: goto x86_l_c8c;
	case 3217ULL: goto x86_l_c91;
	case 3219ULL: goto x86_l_c93;
	case 3221ULL: goto x86_l_c95;
	case 3226ULL: goto x86_l_c9a;
	case 3236ULL: goto x86_l_ca4;
	case 3241ULL: goto x86_l_ca9;
	case 3251ULL: goto x86_l_cb3;
	case 3256ULL: goto x86_l_cb8;
	case 3266ULL: goto x86_l_cc2;
	case 3271ULL: goto x86_l_cc7;
	case 3281ULL: goto x86_l_cd1;
	case 3286ULL: goto x86_l_cd6;
	case 3296ULL: goto x86_l_ce0;
	case 3301ULL: goto x86_l_ce5;
	case 3311ULL: goto x86_l_cef;
	case 3316ULL: goto x86_l_cf4;
	case 3321ULL: goto x86_l_cf9;
	case 3326ULL: goto x86_l_cfe;
	case 3331ULL: goto x86_l_d03;
	case 3335ULL: goto x86_l_d07;
	case 3340ULL: goto x86_l_d0c;
	case 3342ULL: goto x86_l_d0e;
	case 3344ULL: goto x86_l_d10;
	case 3349ULL: goto x86_l_d15;
	case 3354ULL: goto x86_l_d1a;
	case 3358ULL: goto x86_l_d1e;
	case 3364ULL: goto x86_l_d24;
	case 3368ULL: goto x86_l_d28;
	case 3372ULL: goto x86_l_d2c;
	case 3378ULL: goto x86_l_d32;
	case 3383ULL: goto x86_l_d37;
	case 3388ULL: goto x86_l_d3c;
	case 3393ULL: goto x86_l_d41;
	case 3398ULL: goto x86_l_d46;
	case 3403ULL: goto x86_l_d4b;
	case 3405ULL: goto x86_l_d4d;
	case 3408ULL: goto x86_l_d50;
	case 3414ULL: goto x86_l_d56;
	case 3419ULL: goto x86_l_d5b;
	case 3424ULL: goto x86_l_d60;
	case 3429ULL: goto x86_l_d65;
	case 3432ULL: goto x86_l_d68;
	case 3438ULL: goto x86_l_d6e;
	case 3444ULL: goto x86_l_d74;
	case 3447ULL: goto x86_l_d77;
	case 3452ULL: goto x86_l_d7c;
	case 3457ULL: goto x86_l_d81;
	case 3459ULL: goto x86_l_d83;
	case 3464ULL: goto x86_l_d88;
	case 3474ULL: goto x86_l_d92;
	case 3479ULL: goto x86_l_d97;
	case 3489ULL: goto x86_l_da1;
	case 3494ULL: goto x86_l_da6;
	case 3504ULL: goto x86_l_db0;
	case 3509ULL: goto x86_l_db5;
	case 3519ULL: goto x86_l_dbf;
	case 3524ULL: goto x86_l_dc4;
	case 3534ULL: goto x86_l_dce;
	case 3539ULL: goto x86_l_dd3;
	case 3549ULL: goto x86_l_ddd;
	case 3554ULL: goto x86_l_de2;
	case 3559ULL: goto x86_l_de7;
	case 3564ULL: goto x86_l_dec;
	case 3569ULL: goto x86_l_df1;
	case 3573ULL: goto x86_l_df5;
	case 3578ULL: goto x86_l_dfa;
	case 3580ULL: goto x86_l_dfc;
	case 3582ULL: goto x86_l_dfe;
	case 3587ULL: goto x86_l_e03;
	case 3597ULL: goto x86_l_e0d;
	case 3602ULL: goto x86_l_e12;
	case 3612ULL: goto x86_l_e1c;
	case 3617ULL: goto x86_l_e21;
	case 3627ULL: goto x86_l_e2b;
	case 3632ULL: goto x86_l_e30;
	case 3642ULL: goto x86_l_e3a;
	case 3647ULL: goto x86_l_e3f;
	case 3657ULL: goto x86_l_e49;
	case 3662ULL: goto x86_l_e4e;
	case 3667ULL: goto x86_l_e53;
	case 3672ULL: goto x86_l_e58;
	case 3678ULL: goto x86_l_e5e;
	case 3686ULL: goto x86_l_e66;
	default: return 0xffffffffffffffffULL;
	}
x86_l_705:
	/* 0x705: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_70a:
	/* 0x70a: mov    r14,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBX, X86_WIDTH_64);
x86_l_70d:
	/* 0x70d: cmp    DWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_710:
	/* 0x710: jne    1138 <perf_unwind_python+0x1138> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4408ULL;
	}
x86_l_716:
	/* 0x716: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_71e:
	/* 0x71e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_723:
	/* 0x723: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_729:
	/* 0x729: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_72e:
	/* 0x72e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_733:
	/* 0x733: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_736:
	/* 0x736: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_739:
	/* 0x739: je     89f <perf_unwind_python+0x89f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_89f;
	}
x86_l_73f:
	/* 0x73f: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_743:
	/* 0x743: jne    105f <perf_unwind_python+0x105f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4191ULL;
	}
x86_l_749:
	/* 0x749: mov    DWORD PTR [rsp+0x7c],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 532575944707ULL);
x86_l_751:
	/* 0x751: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_758:
	/* 0x758: lea    rsi,[rsp+0x7c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_75d:
	/* 0x75d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_762:
	/* 0x762: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_764:
	/* 0x764: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_767:
	/* 0x767: mov    rbx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RBP, X86_WIDTH_64);
x86_l_76a:
	/* 0x76a: je     791 <perf_unwind_python+0x791> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_791;
	}
x86_l_76c:
	/* 0x76c: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_76f:
	/* 0x76f: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_773:
	/* 0x773: jmp    79f <perf_unwind_python+0x79f> */
	goto x86_l_79f;
x86_l_775:
	/* 0x775: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_779:
	/* 0x779: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_77d:
	/* 0x77d: jne    10bd <perf_unwind_python+0x10bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4285ULL;
	}
x86_l_783:
	/* 0x783: mov    r12d,0x7d7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2007ULL);
x86_l_789:
	/* 0x789: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_78f:
	/* 0x78f: jmp    7da <perf_unwind_python+0x7da> */
	goto x86_l_7da;
x86_l_791:
	/* 0x791: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_795:
	/* 0x795: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_799:
	/* 0x799: jne    124f <perf_unwind_python+0x124f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4687ULL;
	}
x86_l_79f:
	/* 0x79f: mov    DWORD PTR [rsp+0x18],0x47 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215175ULL);
x86_l_7a7:
	/* 0x7a7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_7ae:
	/* 0x7ae: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7b3:
	/* 0x7b3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7b8:
	/* 0x7b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ba:
	/* 0x7ba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7bd:
	/* 0x7bd: je     7c4 <perf_unwind_python+0x7c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7c4;
	}
x86_l_7bf:
	/* 0x7bf: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_7c2:
	/* 0x7c2: jmp    7ce <perf_unwind_python+0x7ce> */
	goto x86_l_7ce;
x86_l_7c4:
	/* 0x7c4: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7c8:
	/* 0x7c8: jne    12ca <perf_unwind_python+0x12ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4810ULL;
	}
x86_l_7ce:
	/* 0x7ce: mov    r12d,0x7d4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2004ULL);
x86_l_7d4:
	/* 0x7d4: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_7da:
	/* 0x7da: mov    DWORD PTR [rbp+0xf2c],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3884ULL);
x86_l_7e1:
	/* 0x7e1: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_7e9:
	/* 0x7e9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&per_cpu_records)));
x86_l_7f0:
	/* 0x7f0: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7f5:
	/* 0x7f5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7fa:
	/* 0x7fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7fc:
	/* 0x7fc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7ff:
	/* 0x7ff: je     83f <perf_unwind_python+0x83f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_83f;
	}
x86_l_801:
	/* 0x801: movzx  ecx,BYTE PTR [rax+0x1384] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4996ULL);
x86_l_808:
	/* 0x808: cmp    cl,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_80b:
	/* 0x80b: jb     86c <perf_unwind_python+0x86c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_86c;
	}
x86_l_80d:
	/* 0x80d: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_810:
	/* 0x810: mov    DWORD PTR [rax+0xf2c],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16681652977669ULL);
x86_l_81a:
	/* 0x81a: mov    DWORD PTR [rsp+0x18],0x44 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215172ULL);
x86_l_822:
	/* 0x822: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_829:
	/* 0x829: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_82e:
	/* 0x82e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_833:
	/* 0x833: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_835:
	/* 0x835: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_838:
	/* 0x838: je     854 <perf_unwind_python+0x854> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_854;
	}
x86_l_83a:
	/* 0x83a: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_83d:
	/* 0x83d: jmp    85e <perf_unwind_python+0x85e> */
	goto x86_l_85e;
x86_l_83f:
	/* 0x83f: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&perf_progs)));
x86_l_846:
	/* 0x846: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_848:
	/* 0x848: mov    ecx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_84d:
	/* 0x84d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_850:
	/* 0x850: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_852:
	/* 0x852: jmp    889 <perf_unwind_python+0x889> */
	goto x86_l_889;
x86_l_854:
	/* 0x854: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_858:
	/* 0x858: jne    e79 <perf_unwind_python+0xe79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3705ULL;
	}
x86_l_85e:
	/* 0x85e: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_861:
	/* 0x861: movzx  ecx,BYTE PTR [r15+0x1384] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4996ULL);
x86_l_869:
	/* 0x869: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_86c:
	/* 0x86c: inc    cl */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_INC, 1);
x86_l_86e:
	/* 0x86e: mov    BYTE PTR [rax+0x1384],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4996ULL);
x86_l_874:
	/* 0x874: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_877:
	/* 0x877: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&perf_progs)));
x86_l_87e:
	/* 0x87e: mov    ecx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_883:
	/* 0x883: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_886:
	/* 0x886: mov    edx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_32);
x86_l_889:
	/* 0x889: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_88b:
	/* 0x88b: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_890:
	/* 0x890: add    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_897:
	/* 0x897: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_899:
	/* 0x899: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_89a:
	/* 0x89a: jmp    491f <perf_unwind_python+0x491f> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_89f:
	/* 0x89f: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8a7:
	/* 0x8a7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8aa:
	/* 0x8aa: je     91b <perf_unwind_python+0x91b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_91b;
	}
x86_l_8ac:
	/* 0x8ac: movzx  edx,BYTE PTR [r13+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_8b1:
	/* 0x8b1: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_8b4:
	/* 0x8b4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_8b9:
	/* 0x8b9: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_8bf:
	/* 0x8bf: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8c4:
	/* 0x8c4: movzx  edx,BYTE PTR [r13+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_8c9:
	/* 0x8c9: add    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_8d1:
	/* 0x8d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8d6:
	/* 0x8d6: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_8d9:
	/* 0x8d9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8dc:
	/* 0x8dc: mov    rbx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RBP, X86_WIDTH_64);
x86_l_8df:
	/* 0x8df: je     958 <perf_unwind_python+0x958> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_958;
	}
x86_l_8e1:
	/* 0x8e1: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8e5:
	/* 0x8e5: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8e9:
	/* 0x8e9: jne    141f <perf_unwind_python+0x141f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5151ULL;
	}
x86_l_8ef:
	/* 0x8ef: mov    DWORD PTR [rsp+0x18],0x19 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215129ULL);
x86_l_8f7:
	/* 0x8f7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_8fe:
	/* 0x8fe: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_903:
	/* 0x903: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_908:
	/* 0x908: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_90a:
	/* 0x90a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_90d:
	/* 0x90d: je     9c6 <perf_unwind_python+0x9c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9c6;
	}
x86_l_913:
	/* 0x913: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_916:
	/* 0x916: jmp    9d0 <perf_unwind_python+0x9d0> */
	goto x86_l_9d0;
x86_l_91b:
	/* 0x91b: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_91f:
	/* 0x91f: mov    rbx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RBP, X86_WIDTH_64);
x86_l_922:
	/* 0x922: jne    1587 <perf_unwind_python+0x1587> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5511ULL;
	}
x86_l_928:
	/* 0x928: mov    DWORD PTR [rsp+0x18],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215128ULL);
x86_l_930:
	/* 0x930: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_937:
	/* 0x937: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_93c:
	/* 0x93c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_941:
	/* 0x941: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_943:
	/* 0x943: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_946:
	/* 0x946: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_94a:
	/* 0x94a: je     a11 <perf_unwind_python+0xa11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a11;
	}
x86_l_950:
	/* 0x950: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_953:
	/* 0x953: jmp    a1b <perf_unwind_python+0xa1b> */
	goto x86_l_a1b;
x86_l_958:
	/* 0x958: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_95b:
	/* 0x95b: cmp    BYTE PTR [r13+0x23],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 150323855360ULL);
x86_l_960:
	/* 0x960: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_964:
	/* 0x964: je     9e1 <perf_unwind_python+0x9e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9e1;
	}
x86_l_966:
	/* 0x966: movzx  ecx,BYTE PTR [rax+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_96a:
	/* 0x96a: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_96f:
	/* 0x96f: add    rcx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_972:
	/* 0x972: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_977:
	/* 0x977: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_97d:
	/* 0x97d: movzx  edx,BYTE PTR [rax+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_981:
	/* 0x981: add    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_984:
	/* 0x984: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_989:
	/* 0x989: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_98c:
	/* 0x98c: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_98f:
	/* 0x98f: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_992:
	/* 0x992: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_995:
	/* 0x995: je     9e1 <perf_unwind_python+0x9e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9e1;
	}
x86_l_997:
	/* 0x997: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_99b:
	/* 0x99b: jne    186d <perf_unwind_python+0x186d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6253ULL;
	}
x86_l_9a1:
	/* 0x9a1: mov    DWORD PTR [rsp+0x18],0x43 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215171ULL);
x86_l_9a9:
	/* 0x9a9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_9b0:
	/* 0x9b0: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9b5:
	/* 0x9b5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9ba:
	/* 0x9ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9bc:
	/* 0x9bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9bf:
	/* 0x9bf: je     a2c <perf_unwind_python+0xa2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a2c;
	}
x86_l_9c1:
	/* 0x9c1: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_9c4:
	/* 0x9c4: jmp    a36 <perf_unwind_python+0xa36> */
	goto x86_l_a36;
x86_l_9c6:
	/* 0x9c6: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ca:
	/* 0x9ca: jne    16c0 <perf_unwind_python+0x16c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5824ULL;
	}
x86_l_9d0:
	/* 0x9d0: mov    r12d,0x7d6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2006ULL);
x86_l_9d6:
	/* 0x9d6: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_9dc:
	/* 0x9dc: jmp    7da <perf_unwind_python+0x7da> */
	goto x86_l_7da;
x86_l_9e1:
	/* 0x9e1: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9e6:
	/* 0x9e6: mov    r13,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9e9:
	/* 0x9e9: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_9ec:
	/* 0x9ec: jne    93 <perf_unwind_python+0x93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 147ULL;
	}
x86_l_9f2:
	/* 0x9f2: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9f6:
	/* 0x9f6: jne    1a21 <perf_unwind_python+0x1a21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6689ULL;
	}
x86_l_9fc:
	/* 0x9fc: or     BYTE PTR [rbp+0x1380],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 21440476741648ULL);
x86_l_a03:
	/* 0xa03: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a06:
	/* 0xa06: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_a0c:
	/* 0xa0c: jmp    7da <perf_unwind_python+0x7da> */
	goto x86_l_7da;
x86_l_a11:
	/* 0xa11: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a15:
	/* 0xa15: jne    1777 <perf_unwind_python+0x1777> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6007ULL;
	}
x86_l_a1b:
	/* 0xa1b: mov    r12d,0x7d5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2005ULL);
x86_l_a21:
	/* 0xa21: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_a27:
	/* 0xa27: jmp    7da <perf_unwind_python+0x7da> */
	goto x86_l_7da;
x86_l_a2c:
	/* 0xa2c: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a30:
	/* 0xa30: jne    1a7a <perf_unwind_python+0x1a7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6778ULL;
	}
x86_l_a36:
	/* 0xa36: mov    r12d,0x7d3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2003ULL);
x86_l_a3c:
	/* 0xa3c: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_a42:
	/* 0xa42: jmp    7da <perf_unwind_python+0x7da> */
	goto x86_l_7da;
x86_l_a47:
	/* 0xa47: movabs rax,0x666e692073736572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7380952427403634034ULL);
x86_l_a51:
	/* 0xa51: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a56:
	/* 0xa56: movabs rax,0x646461206f6e202c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7234013693400195116ULL);
x86_l_a60:
	/* 0xa60: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a65:
	/* 0xa65: movabs rax,0x6b63617473206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7738135737528249967ULL);
x86_l_a6f:
	/* 0xa6f: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a74:
	/* 0xa74: movabs rax,0x6874795020646c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7526774262290738281ULL);
x86_l_a7e:
	/* 0xa7e: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a83:
	/* 0xa83: movabs rax,0x75622074276e6143 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8458358733405053251ULL);
x86_l_a8d:
	/* 0xa8d: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a92:
	/* 0xa92: mov    DWORD PTR [rsp+0x57],0xa6f66 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 373662838630ULL);
x86_l_a9a:
	/* 0xa9a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a9f:
	/* 0xa9f: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_aa4:
	/* 0xaa4: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_aa9:
	/* 0xaa9: mov    esi,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 43ULL);
x86_l_aae:
	/* 0xaae: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ab0:
	/* 0xab0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_ab2:
	/* 0xab2: jmp    135 <perf_unwind_python+0x135> */
	return 309ULL;
x86_l_ab7:
	/* 0xab7: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_abb:
	/* 0xabb: movzx  ecx,BYTE PTR [rax+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_abf:
	/* 0xabf: mov    ecx,DWORD PTR [r15+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_ac3:
	/* 0xac3: movzx  edx,BYTE PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_ac7:
	/* 0xac7: mov    edx,DWORD PTR [r15+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_acb:
	/* 0xacb: movzx  esi,BYTE PTR [rax+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_acf:
	/* 0xacf: mov    esi,DWORD PTR [r15+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_ad3:
	/* 0xad3: movzx  eax,BYTE PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_ad7:
	/* 0xad7: shl    ecx,0x19 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 25ULL);
x86_l_ada:
	/* 0xada: shl    edx,0x12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 18ULL);
x86_l_add:
	/* 0xadd: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_adf:
	/* 0xadf: shl    esi,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 10ULL);
x86_l_ae2:
	/* 0xae2: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ae4:
	/* 0xae4: add    esi,DWORD PTR [r15+rax*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R15, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_ae8:
	/* 0xae8: shl    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_aec:
	/* 0xaec: or     r12,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RSI, X86_WIDTH_64, X86_ALU_OR);
x86_l_aef:
	/* 0xaef: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_af4:
	/* 0xaf4: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af8:
	/* 0xaf8: je     348 <perf_unwind_python+0x348> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 840ULL;
	}
x86_l_afe:
	/* 0xafe: movabs rax,0xa756c2520786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2943857106909292ULL);
x86_l_b08:
	/* 0xb08: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b0d:
	/* 0xb0d: movabs rax,0x25206e6f68747950 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675259603430963536ULL);
x86_l_b17:
	/* 0xb17: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b1c:
	/* 0xb1c: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_b26:
	/* 0xb26: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b2b:
	/* 0xb2b: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b30:
	/* 0xb30: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b35:
	/* 0xb35: mov    eax,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_b3a:
	/* 0xb3a: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_b40:
	/* 0xb40: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_b45:
	/* 0xb45: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_b48:
	/* 0xb48: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b4a:
	/* 0xb4a: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_b4d:
	/* 0xb4d: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_b50:
	/* 0xb50: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_b53:
	/* 0xb53: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b58:
	/* 0xb58: mov    eax,DWORD PTR [rbp+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_b5e:
	/* 0xb5e: cmp    rax,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 127ULL);
x86_l_b62:
	/* 0xb62: jae    358 <perf_unwind_python+0x358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 856ULL;
	}
x86_l_b68:
	/* 0xb68: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b6d:
	/* 0xb6d: lea    ecx,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_b70:
	/* 0xb70: mov    DWORD PTR [rbp+0x2c0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_b76:
	/* 0xb76: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_b7a:
	/* 0xb7a: mov    QWORD PTR [rbp+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_b82:
	/* 0xb82: mov    QWORD PTR [rbp+rax*8+0x2d8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_b8a:
	/* 0xb8a: mov    BYTE PTR [rbp+rax*8+0x2e0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929857ULL);
x86_l_b92:
	/* 0xb92: mov    DWORD PTR [rbp+rax*8+0x2e1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3165390897152ULL);
x86_l_b9d:
	/* 0xb9d: mov    DWORD PTR [rbp+rax*8+0x2e4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3178275799040ULL);
x86_l_ba8:
	/* 0xba8: mov    DWORD PTR [rsp+0x18],0x16 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215126ULL);
x86_l_bb0:
	/* 0xbb0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_bb7:
	/* 0xbb7: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bbc:
	/* 0xbbc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bc1:
	/* 0xbc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bc3:
	/* 0xbc3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bc6:
	/* 0xbc6: je     be9 <perf_unwind_python+0xbe9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_be9;
	}
x86_l_bc8:
	/* 0xbc8: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_bcb:
	/* 0xbcb: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bcf:
	/* 0xbcf: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bd4:
	/* 0xbd4: mov    r8d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bd9:
	/* 0xbd9: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_bdc:
	/* 0xbdc: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_be1:
	/* 0xbe1: jne    1b8 <perf_unwind_python+0x1b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 440ULL;
	}
x86_l_be7:
	/* 0xbe7: jmp    c0f <perf_unwind_python+0xc0f> */
	goto x86_l_c0f;
x86_l_be9:
	/* 0xbe9: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bed:
	/* 0xbed: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bf1:
	/* 0xbf1: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bf6:
	/* 0xbf6: mov    r8d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bfb:
	/* 0xbfb: jne    1989 <perf_unwind_python+0x1989> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6537ULL;
	}
x86_l_c01:
	/* 0xc01: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_c04:
	/* 0xc04: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c09:
	/* 0xc09: jne    1b8 <perf_unwind_python+0x1b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 440ULL;
	}
x86_l_c0f:
	/* 0xc0f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c12:
	/* 0xc12: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_c15:
	/* 0xc15: je     c37 <perf_unwind_python+0xc37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c37;
	}
x86_l_c17:
	/* 0xc17: cmp    BYTE PTR [rax+0x19],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 107374182520ULL);
x86_l_c1b:
	/* 0xc1b: ja     c27 <perf_unwind_python+0xc27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c27;
	}
x86_l_c1d:
	/* 0xc1d: cmp    BYTE PTR [rax+0x18],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215224ULL);
x86_l_c21:
	/* 0xc21: jbe    d15 <perf_unwind_python+0xd15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_d15;
	}
x86_l_c27:
	/* 0xc27: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c29:
	/* 0xc29: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_c2c:
	/* 0xc2c: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_c32:
	/* 0xc32: jmp    168 <perf_unwind_python+0x168> */
	return 360ULL;
x86_l_c37:
	/* 0xc37: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c39:
	/* 0xc39: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c3c:
	/* 0xc3c: jmp    168 <perf_unwind_python+0x168> */
	return 360ULL;
x86_l_c41:
	/* 0xc41: movabs rax,0xa65756c617620 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926304771012128ULL);
x86_l_c4b:
	/* 0xc4b: mov    QWORD PTR [rsp+0x45],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_c50:
	/* 0xc50: movabs rax,0x6176206573616270 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7022836289030414960ULL);
x86_l_c5a:
	/* 0xc5a: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c5f:
	/* 0xc5f: movabs rax,0x742064616572206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798477130965103ULL);
x86_l_c69:
	/* 0xc69: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c6e:
	/* 0xc6e: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_c78:
	/* 0xc78: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c7d:
	/* 0xc7d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c82:
	/* 0xc82: mov    eax,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_c87:
	/* 0xc87: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_c8c:
	/* 0xc8c: mov    esi,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 29ULL);
x86_l_c91:
	/* 0xc91: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c93:
	/* 0xc93: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c95:
	/* 0xc95: jmp    55c <perf_unwind_python+0x55c> */
	return 1372ULL;
x86_l_c9a:
	/* 0xc9a: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_ca4:
	/* 0xca4: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_ca9:
	/* 0xca9: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_cb3:
	/* 0xcb3: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_cb8:
	/* 0xcb8: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_cc2:
	/* 0xcc2: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_cc7:
	/* 0xcc7: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_cd1:
	/* 0xcd1: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_cd6:
	/* 0xcd6: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_ce0:
	/* 0xce0: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ce5:
	/* 0xce5: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_cef:
	/* 0xcef: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cf4:
	/* 0xcf4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cf9:
	/* 0xcf9: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_cfe:
	/* 0xcfe: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_d03:
	/* 0xd03: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d07:
	/* 0xd07: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_d0c:
	/* 0xd0c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d0e:
	/* 0xd0e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d10:
	/* 0xd10: jmp    187 <perf_unwind_python+0x187> */
	return 391ULL;
x86_l_d15:
	/* 0xd15: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d1a:
	/* 0xd1a: cmp    BYTE PTR [rax+0x1a],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 111669149816ULL);
x86_l_d1e:
	/* 0xd1e: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_d24:
	/* 0xd24: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d28:
	/* 0xd28: cmp    BYTE PTR [rax+0x1b],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 115964116992ULL);
x86_l_d2c:
	/* 0xd2c: js     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 17816ULL;
	}
x86_l_d32:
	/* 0xd32: mov    eax,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 128ULL);
x86_l_d37:
	/* 0xd37: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_d3c:
	/* 0xd3c: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d41:
	/* 0xd41: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d46:
	/* 0xd46: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_d4b:
	/* 0xd4b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d4d:
	/* 0xd4d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d50:
	/* 0xd50: je     120c <perf_unwind_python+0x120c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4620ULL;
	}
x86_l_d56:
	/* 0xd56: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d5b:
	/* 0xd5b: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d60:
	/* 0xd60: jmp    ed <perf_unwind_python+0xed> */
	return 237ULL;
x86_l_d65:
	/* 0xd65: cmp    DWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d68:
	/* 0xd68: jne    1b62 <perf_unwind_python+0x1b62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7010ULL;
	}
x86_l_d6e:
	/* 0xd6e: mov    r12d,0x7d0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2000ULL);
x86_l_d74:
	/* 0xd74: mov    r14,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBX, X86_WIDTH_64);
x86_l_d77:
	/* 0xd77: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d7c:
	/* 0xd7c: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d81:
	/* 0xd81: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d83:
	/* 0xd83: jmp    168 <perf_unwind_python+0x168> */
	return 360ULL;
x86_l_d88:
	/* 0xd88: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_d92:
	/* 0xd92: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_d97:
	/* 0xd97: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_da1:
	/* 0xda1: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_da6:
	/* 0xda6: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_db0:
	/* 0xdb0: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_db5:
	/* 0xdb5: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_dbf:
	/* 0xdbf: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_dc4:
	/* 0xdc4: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_dce:
	/* 0xdce: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_dd3:
	/* 0xdd3: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_ddd:
	/* 0xddd: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_de2:
	/* 0xde2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_de7:
	/* 0xde7: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_dec:
	/* 0xdec: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_df1:
	/* 0xdf1: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_df5:
	/* 0xdf5: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_dfa:
	/* 0xdfa: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dfc:
	/* 0xdfc: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_dfe:
	/* 0xdfe: jmp    519 <perf_unwind_python+0x519> */
	return 1305ULL;
x86_l_e03:
	/* 0xe03: movabs rax,0xa786c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541280ULL);
x86_l_e0d:
	/* 0xe0d: mov    QWORD PTR [rsp+0x4e],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_e12:
	/* 0xe12: movabs rax,0x3020726464417965 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 3467897488579590501ULL);
x86_l_e1c:
	/* 0xe1c: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e21:
	/* 0xe21: movabs rax,0x4b534c546f747561 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5427765901442446689ULL);
x86_l_e2b:
	/* 0xe2b: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e30:
	/* 0xe30: movabs rax,0x202c786c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2318360314069397536ULL);
x86_l_e3a:
	/* 0xe3a: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e3f:
	/* 0xe3f: movabs rax,0x6573614220445354 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310293556789531476ULL);
x86_l_e49:
	/* 0xe49: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e4e:
	/* 0xe4e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e53:
	/* 0xe53: mov    eax,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 38ULL);
x86_l_e58:
	/* 0xe58: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_e5e:
	/* 0xe5e: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_e66:
	/* 0xe66: mov    rcx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 3690ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3690ULL: goto x86_l_e6a;
	case 3695ULL: goto x86_l_e6f;
	case 3697ULL: goto x86_l_e71;
	case 3700ULL: goto x86_l_e74;
	case 3705ULL: goto x86_l_e79;
	case 3715ULL: goto x86_l_e83;
	case 3720ULL: goto x86_l_e88;
	case 3730ULL: goto x86_l_e92;
	case 3735ULL: goto x86_l_e97;
	case 3745ULL: goto x86_l_ea1;
	case 3750ULL: goto x86_l_ea6;
	case 3760ULL: goto x86_l_eb0;
	case 3765ULL: goto x86_l_eb5;
	case 3775ULL: goto x86_l_ebf;
	case 3780ULL: goto x86_l_ec4;
	case 3790ULL: goto x86_l_ece;
	case 3795ULL: goto x86_l_ed3;
	case 3800ULL: goto x86_l_ed8;
	case 3805ULL: goto x86_l_edd;
	case 3810ULL: goto x86_l_ee2;
	case 3814ULL: goto x86_l_ee6;
	case 3819ULL: goto x86_l_eeb;
	case 3821ULL: goto x86_l_eed;
	case 3823ULL: goto x86_l_eef;
	case 3828ULL: goto x86_l_ef4;
	case 3838ULL: goto x86_l_efe;
	case 3843ULL: goto x86_l_f03;
	case 3853ULL: goto x86_l_f0d;
	case 3858ULL: goto x86_l_f12;
	case 3868ULL: goto x86_l_f1c;
	case 3873ULL: goto x86_l_f21;
	case 3883ULL: goto x86_l_f2b;
	case 3888ULL: goto x86_l_f30;
	case 3898ULL: goto x86_l_f3a;
	case 3903ULL: goto x86_l_f3f;
	case 3908ULL: goto x86_l_f44;
	case 3913ULL: goto x86_l_f49;
	case 3918ULL: goto x86_l_f4e;
	case 3923ULL: goto x86_l_f53;
	case 3926ULL: goto x86_l_f56;
	case 3928ULL: goto x86_l_f58;
	case 3930ULL: goto x86_l_f5a;
	case 3935ULL: goto x86_l_f5f;
	case 3945ULL: goto x86_l_f69;
	case 3950ULL: goto x86_l_f6e;
	case 3960ULL: goto x86_l_f78;
	case 3965ULL: goto x86_l_f7d;
	case 3975ULL: goto x86_l_f87;
	case 3980ULL: goto x86_l_f8c;
	case 3990ULL: goto x86_l_f96;
	case 3995ULL: goto x86_l_f9b;
	case 4005ULL: goto x86_l_fa5;
	case 4010ULL: goto x86_l_faa;
	case 4020ULL: goto x86_l_fb4;
	case 4025ULL: goto x86_l_fb9;
	case 4030ULL: goto x86_l_fbe;
	case 4035ULL: goto x86_l_fc3;
	case 4040ULL: goto x86_l_fc8;
	case 4044ULL: goto x86_l_fcc;
	case 4049ULL: goto x86_l_fd1;
	case 4051ULL: goto x86_l_fd3;
	case 4053ULL: goto x86_l_fd5;
	case 4057ULL: goto x86_l_fd9;
	case 4063ULL: goto x86_l_fdf;
	case 4068ULL: goto x86_l_fe4;
	case 4078ULL: goto x86_l_fee;
	case 4083ULL: goto x86_l_ff3;
	case 4093ULL: goto x86_l_ffd;
	case 4098ULL: goto x86_l_1002;
	case 4108ULL: goto x86_l_100c;
	case 4113ULL: goto x86_l_1011;
	case 4123ULL: goto x86_l_101b;
	case 4128ULL: goto x86_l_1020;
	case 4138ULL: goto x86_l_102a;
	case 4143ULL: goto x86_l_102f;
	case 4153ULL: goto x86_l_1039;
	case 4158ULL: goto x86_l_103e;
	case 4163ULL: goto x86_l_1043;
	case 4168ULL: goto x86_l_1048;
	case 4173ULL: goto x86_l_104d;
	case 4177ULL: goto x86_l_1051;
	case 4182ULL: goto x86_l_1056;
	case 4184ULL: goto x86_l_1058;
	case 4186ULL: goto x86_l_105a;
	case 4191ULL: goto x86_l_105f;
	case 4201ULL: goto x86_l_1069;
	case 4206ULL: goto x86_l_106e;
	case 4216ULL: goto x86_l_1078;
	case 4221ULL: goto x86_l_107d;
	case 4231ULL: goto x86_l_1087;
	case 4236ULL: goto x86_l_108c;
	case 4246ULL: goto x86_l_1096;
	case 4251ULL: goto x86_l_109b;
	case 4256ULL: goto x86_l_10a0;
	case 4261ULL: goto x86_l_10a5;
	case 4266ULL: goto x86_l_10aa;
	case 4271ULL: goto x86_l_10af;
	case 4276ULL: goto x86_l_10b4;
	case 4278ULL: goto x86_l_10b6;
	case 4280ULL: goto x86_l_10b8;
	case 4285ULL: goto x86_l_10bd;
	case 4295ULL: goto x86_l_10c7;
	case 4300ULL: goto x86_l_10cc;
	case 4310ULL: goto x86_l_10d6;
	case 4315ULL: goto x86_l_10db;
	case 4325ULL: goto x86_l_10e5;
	case 4330ULL: goto x86_l_10ea;
	case 4340ULL: goto x86_l_10f4;
	case 4345ULL: goto x86_l_10f9;
	case 4355ULL: goto x86_l_1103;
	case 4360ULL: goto x86_l_1108;
	case 4370ULL: goto x86_l_1112;
	case 4375ULL: goto x86_l_1117;
	case 4380ULL: goto x86_l_111c;
	case 4385ULL: goto x86_l_1121;
	case 4390ULL: goto x86_l_1126;
	case 4394ULL: goto x86_l_112a;
	case 4399ULL: goto x86_l_112f;
	case 4401ULL: goto x86_l_1131;
	case 4403ULL: goto x86_l_1133;
	case 4408ULL: goto x86_l_1138;
	case 4418ULL: goto x86_l_1142;
	case 4423ULL: goto x86_l_1147;
	case 4433ULL: goto x86_l_1151;
	case 4438ULL: goto x86_l_1156;
	case 4448ULL: goto x86_l_1160;
	case 4453ULL: goto x86_l_1165;
	case 4463ULL: goto x86_l_116f;
	case 4468ULL: goto x86_l_1174;
	case 4476ULL: goto x86_l_117c;
	case 4481ULL: goto x86_l_1181;
	case 4486ULL: goto x86_l_1186;
	case 4492ULL: goto x86_l_118c;
	case 4497ULL: goto x86_l_1191;
	case 4502ULL: goto x86_l_1196;
	case 4505ULL: goto x86_l_1199;
	case 4507ULL: goto x86_l_119b;
	case 4510ULL: goto x86_l_119e;
	case 4515ULL: goto x86_l_11a3;
	case 4520ULL: goto x86_l_11a8;
	case 4530ULL: goto x86_l_11b2;
	case 4535ULL: goto x86_l_11b7;
	case 4545ULL: goto x86_l_11c1;
	case 4550ULL: goto x86_l_11c6;
	case 4560ULL: goto x86_l_11d0;
	case 4565ULL: goto x86_l_11d5;
	case 4575ULL: goto x86_l_11df;
	case 4580ULL: goto x86_l_11e4;
	case 4588ULL: goto x86_l_11ec;
	case 4593ULL: goto x86_l_11f1;
	case 4598ULL: goto x86_l_11f6;
	case 4603ULL: goto x86_l_11fb;
	case 4608ULL: goto x86_l_1200;
	case 4611ULL: goto x86_l_1203;
	case 4613ULL: goto x86_l_1205;
	case 4615ULL: goto x86_l_1207;
	case 4620ULL: goto x86_l_120c;
	case 4624ULL: goto x86_l_1210;
	case 4628ULL: goto x86_l_1214;
	case 4633ULL: goto x86_l_1219;
	case 4637ULL: goto x86_l_121d;
	case 4642ULL: goto x86_l_1222;
	case 4646ULL: goto x86_l_1226;
	case 4650ULL: goto x86_l_122a;
	case 4654ULL: goto x86_l_122e;
	case 4657ULL: goto x86_l_1231;
	case 4663ULL: goto x86_l_1237;
	case 4668ULL: goto x86_l_123c;
	case 4674ULL: goto x86_l_1242;
	case 4677ULL: goto x86_l_1245;
	case 4682ULL: goto x86_l_124a;
	case 4687ULL: goto x86_l_124f;
	case 4697ULL: goto x86_l_1259;
	case 4702ULL: goto x86_l_125e;
	case 4712ULL: goto x86_l_1268;
	case 4717ULL: goto x86_l_126d;
	case 4727ULL: goto x86_l_1277;
	case 4732ULL: goto x86_l_127c;
	case 4742ULL: goto x86_l_1286;
	case 4747ULL: goto x86_l_128b;
	case 4757ULL: goto x86_l_1295;
	case 4762ULL: goto x86_l_129a;
	case 4772ULL: goto x86_l_12a4;
	case 4777ULL: goto x86_l_12a9;
	case 4782ULL: goto x86_l_12ae;
	case 4787ULL: goto x86_l_12b3;
	case 4792ULL: goto x86_l_12b8;
	case 4796ULL: goto x86_l_12bc;
	case 4801ULL: goto x86_l_12c1;
	case 4803ULL: goto x86_l_12c3;
	case 4805ULL: goto x86_l_12c5;
	case 4810ULL: goto x86_l_12ca;
	case 4820ULL: goto x86_l_12d4;
	case 4825ULL: goto x86_l_12d9;
	case 4835ULL: goto x86_l_12e3;
	case 4840ULL: goto x86_l_12e8;
	case 4850ULL: goto x86_l_12f2;
	case 4855ULL: goto x86_l_12f7;
	case 4865ULL: goto x86_l_1301;
	case 4870ULL: goto x86_l_1306;
	case 4880ULL: goto x86_l_1310;
	case 4885ULL: goto x86_l_1315;
	case 4895ULL: goto x86_l_131f;
	case 4900ULL: goto x86_l_1324;
	case 4905ULL: goto x86_l_1329;
	case 4910ULL: goto x86_l_132e;
	case 4915ULL: goto x86_l_1333;
	case 4919ULL: goto x86_l_1337;
	case 4924ULL: goto x86_l_133c;
	case 4926ULL: goto x86_l_133e;
	case 4928ULL: goto x86_l_1340;
	case 4933ULL: goto x86_l_1345;
	case 4937ULL: goto x86_l_1349;
	case 4941ULL: goto x86_l_134d;
	case 4945ULL: goto x86_l_1351;
	case 4951ULL: goto x86_l_1357;
	case 4956ULL: goto x86_l_135c;
	case 4960ULL: goto x86_l_1360;
	case 4964ULL: goto x86_l_1364;
	case 4968ULL: goto x86_l_1368;
	case 4973ULL: goto x86_l_136d;
	case 4976ULL: goto x86_l_1370;
	case 4983ULL: goto x86_l_1377;
	case 4985ULL: goto x86_l_1379;
	case 4992ULL: goto x86_l_1380;
	case 4998ULL: goto x86_l_1386;
	case 5002ULL: goto x86_l_138a;
	case 5006ULL: goto x86_l_138e;
	case 5010ULL: goto x86_l_1392;
	case 5013ULL: goto x86_l_1395;
	case 5016ULL: goto x86_l_1398;
	case 5021ULL: goto x86_l_139d;
	case 5031ULL: goto x86_l_13a7;
	case 5036ULL: goto x86_l_13ac;
	case 5046ULL: goto x86_l_13b6;
	case 5051ULL: goto x86_l_13bb;
	case 5061ULL: goto x86_l_13c5;
	case 5066ULL: goto x86_l_13ca;
	case 5076ULL: goto x86_l_13d4;
	case 5081ULL: goto x86_l_13d9;
	case 5091ULL: goto x86_l_13e3;
	case 5096ULL: goto x86_l_13e8;
	case 5106ULL: goto x86_l_13f2;
	case 5111ULL: goto x86_l_13f7;
	case 5116ULL: goto x86_l_13fc;
	case 5121ULL: goto x86_l_1401;
	case 5126ULL: goto x86_l_1406;
	case 5130ULL: goto x86_l_140a;
	case 5135ULL: goto x86_l_140f;
	case 5137ULL: goto x86_l_1411;
	case 5139ULL: goto x86_l_1413;
	case 5141ULL: goto x86_l_1415;
	case 5146ULL: goto x86_l_141a;
	case 5151ULL: goto x86_l_141f;
	case 5161ULL: goto x86_l_1429;
	case 5166ULL: goto x86_l_142e;
	case 5176ULL: goto x86_l_1438;
	case 5181ULL: goto x86_l_143d;
	case 5191ULL: goto x86_l_1447;
	case 5196ULL: goto x86_l_144c;
	case 5206ULL: goto x86_l_1456;
	case 5211ULL: goto x86_l_145b;
	case 5221ULL: goto x86_l_1465;
	case 5226ULL: goto x86_l_146a;
	case 5236ULL: goto x86_l_1474;
	case 5241ULL: goto x86_l_1479;
	case 5246ULL: goto x86_l_147e;
	case 5251ULL: goto x86_l_1483;
	case 5256ULL: goto x86_l_1488;
	case 5261ULL: goto x86_l_148d;
	case 5269ULL: goto x86_l_1495;
	case 5274ULL: goto x86_l_149a;
	case 5276ULL: goto x86_l_149c;
	case 5278ULL: goto x86_l_149e;
	case 5283ULL: goto x86_l_14a3;
	case 5288ULL: goto x86_l_14a8;
	case 5292ULL: goto x86_l_14ac;
	case 5294ULL: goto x86_l_14ae;
	case 5300ULL: goto x86_l_14b4;
	case 5306ULL: goto x86_l_14ba;
	case 5310ULL: goto x86_l_14be;
	case 5314ULL: goto x86_l_14c2;
	case 5320ULL: goto x86_l_14c8;
	case 5324ULL: goto x86_l_14cc;
	case 5328ULL: goto x86_l_14d0;
	case 5334ULL: goto x86_l_14d6;
	case 5338ULL: goto x86_l_14da;
	case 5342ULL: goto x86_l_14de;
	case 5348ULL: goto x86_l_14e4;
	case 5352ULL: goto x86_l_14e8;
	case 5356ULL: goto x86_l_14ec;
	case 5362ULL: goto x86_l_14f2;
	case 5367ULL: goto x86_l_14f7;
	case 5372ULL: goto x86_l_14fc;
	case 5377ULL: goto x86_l_1501;
	case 5380ULL: goto x86_l_1504;
	case 5385ULL: goto x86_l_1509;
	case 5387ULL: goto x86_l_150b;
	case 5390ULL: goto x86_l_150e;
	case 5396ULL: goto x86_l_1514;
	case 5400ULL: goto x86_l_1518;
	case 5404ULL: goto x86_l_151c;
	case 5408ULL: goto x86_l_1520;
	case 5412ULL: goto x86_l_1524;
	case 5416ULL: goto x86_l_1528;
	case 5420ULL: goto x86_l_152c;
	case 5424ULL: goto x86_l_1530;
	case 5428ULL: goto x86_l_1534;
	case 5431ULL: goto x86_l_1537;
	case 5434ULL: goto x86_l_153a;
	case 5436ULL: goto x86_l_153c;
	case 5439ULL: goto x86_l_153f;
	case 5441ULL: goto x86_l_1541;
	case 5445ULL: goto x86_l_1545;
	case 5449ULL: goto x86_l_1549;
	case 5452ULL: goto x86_l_154c;
	case 5457ULL: goto x86_l_1551;
	case 5461ULL: goto x86_l_1555;
	case 5467ULL: goto x86_l_155b;
	case 5475ULL: goto x86_l_1563;
	case 5482ULL: goto x86_l_156a;
	case 5487ULL: goto x86_l_156f;
	case 5492ULL: goto x86_l_1574;
	case 5494ULL: goto x86_l_1576;
	case 5497ULL: goto x86_l_1579;
	case 5503ULL: goto x86_l_157f;
	case 5506ULL: goto x86_l_1582;
	case 5511ULL: goto x86_l_1587;
	case 5521ULL: goto x86_l_1591;
	case 5526ULL: goto x86_l_1596;
	case 5536ULL: goto x86_l_15a0;
	case 5541ULL: goto x86_l_15a5;
	case 5551ULL: goto x86_l_15af;
	case 5556ULL: goto x86_l_15b4;
	case 5561ULL: goto x86_l_15b9;
	case 5566ULL: goto x86_l_15be;
	case 5571ULL: goto x86_l_15c3;
	case 5576ULL: goto x86_l_15c8;
	case 5578ULL: goto x86_l_15ca;
	case 5580ULL: goto x86_l_15cc;
	case 5585ULL: goto x86_l_15d1;
	case 5595ULL: goto x86_l_15db;
	case 5600ULL: goto x86_l_15e0;
	case 5610ULL: goto x86_l_15ea;
	case 5615ULL: goto x86_l_15ef;
	case 5625ULL: goto x86_l_15f9;
	case 5630ULL: goto x86_l_15fe;
	case 5640ULL: goto x86_l_1608;
	case 5645ULL: goto x86_l_160d;
	case 5655ULL: goto x86_l_1617;
	case 5660ULL: goto x86_l_161c;
	case 5670ULL: goto x86_l_1626;
	case 5675ULL: goto x86_l_162b;
	case 5680ULL: goto x86_l_1630;
	case 5685ULL: goto x86_l_1635;
	case 5691ULL: goto x86_l_163b;
	case 5695ULL: goto x86_l_163f;
	case 5699ULL: goto x86_l_1643;
	case 5702ULL: goto x86_l_1646;
	case 5707ULL: goto x86_l_164b;
	case 5710ULL: goto x86_l_164e;
	case 5712ULL: goto x86_l_1650;
	case 5715ULL: goto x86_l_1653;
	case 5720ULL: goto x86_l_1658;
	case 5730ULL: goto x86_l_1662;
	case 5735ULL: goto x86_l_1667;
	case 5745ULL: goto x86_l_1671;
	case 5750ULL: goto x86_l_1676;
	case 5760ULL: goto x86_l_1680;
	case 5765ULL: goto x86_l_1685;
	case 5775ULL: goto x86_l_168f;
	case 5780ULL: goto x86_l_1694;
	case 5790ULL: goto x86_l_169e;
	case 5795ULL: goto x86_l_16a3;
	case 5800ULL: goto x86_l_16a8;
	case 5805ULL: goto x86_l_16ad;
	case 5810ULL: goto x86_l_16b2;
	case 5815ULL: goto x86_l_16b7;
	case 5817ULL: goto x86_l_16b9;
	case 5819ULL: goto x86_l_16bb;
	case 5824ULL: goto x86_l_16c0;
	case 5834ULL: goto x86_l_16ca;
	case 5839ULL: goto x86_l_16cf;
	case 5849ULL: goto x86_l_16d9;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e6a:
	/* 0xe6a: mov    esi,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 38ULL);
x86_l_e6f:
	/* 0xe6f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e71:
	/* 0xe71: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_e74:
	/* 0xe74: jmp    5f8 <perf_unwind_python+0x5f8> */
	return 1528ULL;
x86_l_e79:
	/* 0xe79: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_e83:
	/* 0xe83: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_e88:
	/* 0xe88: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_e92:
	/* 0xe92: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e97:
	/* 0xe97: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_ea1:
	/* 0xea1: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_ea6:
	/* 0xea6: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_eb0:
	/* 0xeb0: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_eb5:
	/* 0xeb5: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_ebf:
	/* 0xebf: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ec4:
	/* 0xec4: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_ece:
	/* 0xece: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ed3:
	/* 0xed3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ed8:
	/* 0xed8: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_edd:
	/* 0xedd: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_ee2:
	/* 0xee2: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ee6:
	/* 0xee6: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_eeb:
	/* 0xeeb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_eed:
	/* 0xeed: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_eef:
	/* 0xeef: jmp    85e <perf_unwind_python+0x85e> */
	return 2142ULL;
x86_l_ef4:
	/* 0xef4: movabs rax,0xa786c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541280ULL);
x86_l_efe:
	/* 0xefe: mov    QWORD PTR [rsp+0x4e],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_f03:
	/* 0xf03: movabs rax,0x30206d6f72662079 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 3467892038503374969ULL);
x86_l_f0d:
	/* 0xf0d: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f12:
	/* 0xf12: movabs rax,0x656b534c546f7475 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7308026407637972085ULL);
x86_l_f1c:
	/* 0xf1c: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f21:
	/* 0xf21: movabs rax,0x612064616572206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 6998704190410334319ULL);
x86_l_f2b:
	/* 0xf2b: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f30:
	/* 0xf30: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_f3a:
	/* 0xf3a: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f3f:
	/* 0xf3f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f44:
	/* 0xf44: mov    eax,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 38ULL);
x86_l_f49:
	/* 0xf49: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_f4e:
	/* 0xf4e: mov    esi,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 38ULL);
x86_l_f53:
	/* 0xf53: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_f56:
	/* 0xf56: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f58:
	/* 0xf58: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f5a:
	/* 0xf5a: jmp    635 <perf_unwind_python+0x635> */
	return 1589ULL;
x86_l_f5f:
	/* 0xf5f: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_f69:
	/* 0xf69: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_f6e:
	/* 0xf6e: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_f78:
	/* 0xf78: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f7d:
	/* 0xf7d: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_f87:
	/* 0xf87: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f8c:
	/* 0xf8c: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_f96:
	/* 0xf96: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f9b:
	/* 0xf9b: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_fa5:
	/* 0xfa5: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_faa:
	/* 0xfaa: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_fb4:
	/* 0xfb4: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fb9:
	/* 0xfb9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fbe:
	/* 0xfbe: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_fc3:
	/* 0xfc3: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_fc8:
	/* 0xfc8: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_fcc:
	/* 0xfcc: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_fd1:
	/* 0xfd1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fd3:
	/* 0xfd3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_fd5:
	/* 0xfd5: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fd9:
	/* 0xfd9: je     672 <perf_unwind_python+0x672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1650ULL;
	}
x86_l_fdf:
	/* 0xfdf: jmp    58d <perf_unwind_python+0x58d> */
	return 1421ULL;
x86_l_fe4:
	/* 0xfe4: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_fee:
	/* 0xfee: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_ff3:
	/* 0xff3: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_ffd:
	/* 0xffd: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1002:
	/* 0x1002: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_100c:
	/* 0x100c: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1011:
	/* 0x1011: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_101b:
	/* 0x101b: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1020:
	/* 0x1020: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_102a:
	/* 0x102a: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_102f:
	/* 0x102f: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1039:
	/* 0x1039: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_103e:
	/* 0x103e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1043:
	/* 0x1043: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1048:
	/* 0x1048: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_104d:
	/* 0x104d: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1051:
	/* 0x1051: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1056:
	/* 0x1056: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1058:
	/* 0x1058: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_105a:
	/* 0x105a: jmp    6a1 <perf_unwind_python+0x6a1> */
	return 1697ULL;
x86_l_105f:
	/* 0x105f: movabs rax,0xa786c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541280ULL);
x86_l_1069:
	/* 0x1069: mov    QWORD PTR [rsp+0x47],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_106e:
	/* 0x106e: movabs rax,0x206d6f7266204453 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2336646318805501011ULL);
x86_l_1078:
	/* 0x1078: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_107d:
	/* 0x107d: movabs rax,0x542064616572206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 6061955467917271151ULL);
x86_l_1087:
	/* 0x1087: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_108c:
	/* 0x108c: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1096:
	/* 0x1096: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_109b:
	/* 0x109b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10a0:
	/* 0x10a0: mov    eax,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_10a5:
	/* 0x10a5: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_10aa:
	/* 0x10aa: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10af:
	/* 0x10af: mov    esi,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 31ULL);
x86_l_10b4:
	/* 0x10b4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10b6:
	/* 0x10b6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_10b8:
	/* 0x10b8: jmp    749 <perf_unwind_python+0x749> */
	return 1865ULL;
x86_l_10bd:
	/* 0x10bd: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_10c7:
	/* 0x10c7: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_10cc:
	/* 0x10cc: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_10d6:
	/* 0x10d6: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_10db:
	/* 0x10db: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_10e5:
	/* 0x10e5: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_10ea:
	/* 0x10ea: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_10f4:
	/* 0x10f4: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_10f9:
	/* 0x10f9: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1103:
	/* 0x1103: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1108:
	/* 0x1108: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1112:
	/* 0x1112: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1117:
	/* 0x1117: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_111c:
	/* 0x111c: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1121:
	/* 0x1121: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1126:
	/* 0x1126: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_112a:
	/* 0x112a: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_112f:
	/* 0x112f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1131:
	/* 0x1131: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1133:
	/* 0x1133: jmp    783 <perf_unwind_python+0x783> */
	return 1923ULL;
x86_l_1138:
	/* 0x1138: movabs rax,0x6c25783020737365 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792766878332711781ULL);
x86_l_1142:
	/* 0x1142: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1147:
	/* 0x1147: movabs rax,0x72646461206d6f72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8242823586313498482ULL);
x86_l_1151:
	/* 0x1151: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1156:
	/* 0x1156: movabs rax,0x662064252079656b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358991901744784747ULL);
x86_l_1160:
	/* 0x1160: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1165:
	/* 0x1165: movabs rax,0x2044535464616572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2325074929556481394ULL);
x86_l_116f:
	/* 0x116f: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1174:
	/* 0x1174: mov    DWORD PTR [rsp+0x4f],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 339303102572ULL);
x86_l_117c:
	/* 0x117c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1181:
	/* 0x1181: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_1186:
	/* 0x1186: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_118c:
	/* 0x118c: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1191:
	/* 0x1191: mov    esi,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 35ULL);
x86_l_1196:
	/* 0x1196: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_1199:
	/* 0x1199: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_119b:
	/* 0x119b: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_119e:
	/* 0x119e: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11a3:
	/* 0x11a3: jmp    716 <perf_unwind_python+0x716> */
	return 1814ULL;
x86_l_11a8:
	/* 0x11a8: movabs rax,0x257830207463656a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2699960892558370154ULL);
x86_l_11b2:
	/* 0x11b2: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_11b7:
	/* 0x11b7: movabs rax,0x624f656d61724679 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7083992259337799289ULL);
x86_l_11c1:
	/* 0x11c1: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_11c6:
	/* 0x11c6: movabs rax,0x502064616572206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5773725091765559407ULL);
x86_l_11d0:
	/* 0x11d0: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11d5:
	/* 0x11d5: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_11df:
	/* 0x11df: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11e4:
	/* 0x11e4: mov    DWORD PTR [rsp+0x50],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343598069868ULL);
x86_l_11ec:
	/* 0x11ec: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11f1:
	/* 0x11f1: mov    eax,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_11f6:
	/* 0x11f6: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_11fb:
	/* 0x11fb: mov    esi,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 36ULL);
x86_l_1200:
	/* 0x1200: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1203:
	/* 0x1203: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1205:
	/* 0x1205: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1207:
	/* 0x1207: jmp    f7 <perf_unwind_python+0xf7> */
	return 247ULL;
x86_l_120c:
	/* 0x120c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1210:
	/* 0x1210: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_1214:
	/* 0x1214: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1219:
	/* 0x1219: mov    rcx,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_121d:
	/* 0x121d: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1222:
	/* 0x1222: movzx  ecx,BYTE PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_1226:
	/* 0x1226: mov    r13,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_122a:
	/* 0x122a: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_122e:
	/* 0x122e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1231:
	/* 0x1231: je     1345 <perf_unwind_python+0x1345> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1345;
	}
x86_l_1237:
	/* 0x1237: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_123c:
	/* 0x123c: jne    1345 <perf_unwind_python+0x1345> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1345;
	}
x86_l_1242:
	/* 0x1242: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1245:
	/* 0x1245: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_124a:
	/* 0x124a: jmp    1b3 <perf_unwind_python+0x1b3> */
	return 435ULL;
x86_l_124f:
	/* 0x124f: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1259:
	/* 0x1259: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_125e:
	/* 0x125e: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1268:
	/* 0x1268: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_126d:
	/* 0x126d: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1277:
	/* 0x1277: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_127c:
	/* 0x127c: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1286:
	/* 0x1286: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_128b:
	/* 0x128b: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1295:
	/* 0x1295: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_129a:
	/* 0x129a: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_12a4:
	/* 0x12a4: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12a9:
	/* 0x12a9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12ae:
	/* 0x12ae: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_12b3:
	/* 0x12b3: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_12b8:
	/* 0x12b8: mov    edx,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_12bc:
	/* 0x12bc: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_12c1:
	/* 0x12c1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12c3:
	/* 0x12c3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_12c5:
	/* 0x12c5: jmp    79f <perf_unwind_python+0x79f> */
	return 1951ULL;
x86_l_12ca:
	/* 0x12ca: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_12d4:
	/* 0x12d4: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_12d9:
	/* 0x12d9: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_12e3:
	/* 0x12e3: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_12e8:
	/* 0x12e8: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_12f2:
	/* 0x12f2: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_12f7:
	/* 0x12f7: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1301:
	/* 0x1301: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1306:
	/* 0x1306: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1310:
	/* 0x1310: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1315:
	/* 0x1315: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_131f:
	/* 0x131f: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1324:
	/* 0x1324: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1329:
	/* 0x1329: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_132e:
	/* 0x132e: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1333:
	/* 0x1333: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1337:
	/* 0x1337: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_133c:
	/* 0x133c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_133e:
	/* 0x133e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1340:
	/* 0x1340: jmp    7ce <perf_unwind_python+0x7ce> */
	return 1998ULL;
x86_l_1345:
	/* 0x1345: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1349:
	/* 0x1349: cmp    BYTE PTR [rax+0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_134d:
	/* 0x134d: movzx  eax,BYTE PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 26ULL);
x86_l_1351:
	/* 0x1351: je     14a3 <perf_unwind_python+0x14a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14a3;
	}
x86_l_1357:
	/* 0x1357: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_135c:
	/* 0x135c: mov    rax,QWORD PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1360:
	/* 0x1360: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1364:
	/* 0x1364: movzx  edx,BYTE PTR [rcx+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_1368:
	/* 0x1368: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_136d:
	/* 0x136d: sub    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1370:
	/* 0x1370: lea    rdx,[rax-0x10000001] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073441116159ULL);
x86_l_1377:
	/* 0x1377: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_1379:
	/* 0x1379: cmp    rdx,0xffffffffeffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073441116157ULL);
x86_l_1380:
	/* 0x1380: mov    r12d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_1386:
	/* 0x1386: cmovae r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_138a:
	/* 0x138a: movzx  eax,BYTE PTR [rcx+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_138e:
	/* 0x138e: movzx  eax,BYTE PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1392:
	/* 0x1392: cmp    al,BYTE PTR [rcx+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_1395:
	/* 0x1395: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_1398:
	/* 0x1398: jmp    14ae <perf_unwind_python+0x14ae> */
	goto x86_l_14ae;
x86_l_139d:
	/* 0x139d: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_13a7:
	/* 0x13a7: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_13ac:
	/* 0x13ac: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_13b6:
	/* 0x13b6: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_13bb:
	/* 0x13bb: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_13c5:
	/* 0x13c5: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_13ca:
	/* 0x13ca: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_13d4:
	/* 0x13d4: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13d9:
	/* 0x13d9: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_13e3:
	/* 0x13e3: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_13e8:
	/* 0x13e8: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_13f2:
	/* 0x13f2: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13f7:
	/* 0x13f7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13fc:
	/* 0x13fc: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1401:
	/* 0x1401: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1406:
	/* 0x1406: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_140a:
	/* 0x140a: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_140f:
	/* 0x140f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1411:
	/* 0x1411: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1413:
	/* 0x1413: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1415:
	/* 0x1415: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_141a:
	/* 0x141a: jmp    1e5 <perf_unwind_python+0x1e5> */
	return 485ULL;
x86_l_141f:
	/* 0x141f: movabs rax,0xa786c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541280ULL);
x86_l_1429:
	/* 0x1429: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_142e:
	/* 0x142e: movabs rax,0x783020746120656d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8660457767651272045ULL);
x86_l_1438:
	/* 0x1438: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_143d:
	/* 0x143d: movabs rax,0x6172662e65746174 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7021787118480679284ULL);
x86_l_1447:
	/* 0x1447: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_144c:
	/* 0x144c: movabs rax,0x5364616572685479 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 6009034891158115449ULL);
x86_l_1456:
	/* 0x1456: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_145b:
	/* 0x145b: movabs rax,0x502064616572206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5773725091765559407ULL);
x86_l_1465:
	/* 0x1465: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_146a:
	/* 0x146a: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1474:
	/* 0x1474: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1479:
	/* 0x1479: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_147e:
	/* 0x147e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1483:
	/* 0x1483: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1488:
	/* 0x1488: movzx  edx,BYTE PTR [r13+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_148d:
	/* 0x148d: add    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_1495:
	/* 0x1495: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_149a:
	/* 0x149a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_149c:
	/* 0x149c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_149e:
	/* 0x149e: jmp    8ef <perf_unwind_python+0x8ef> */
	return 2287ULL;
x86_l_14a3:
	/* 0x14a3: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_14a8:
	/* 0x14a8: mov    r12d,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_14ac:
	/* 0x14ac: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14ae:
	/* 0x14ae: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_14b4:
	/* 0x14b4: je     1551 <perf_unwind_python+0x1551> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1551;
	}
x86_l_14ba:
	/* 0x14ba: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14be:
	/* 0x14be: cmp    BYTE PTR [rax+0x1d],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051772ULL);
x86_l_14c2:
	/* 0x14c2: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_14c8:
	/* 0x14c8: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14cc:
	/* 0x14cc: cmp    BYTE PTR [rax+0x1e],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128849019068ULL);
x86_l_14d0:
	/* 0x14d0: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_14d6:
	/* 0x14d6: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14da:
	/* 0x14da: cmp    BYTE PTR [rax+0x1f],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133143986364ULL);
x86_l_14de:
	/* 0x14de: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_14e4:
	/* 0x14e4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14e8:
	/* 0x14e8: cmp    BYTE PTR [rax+0x20],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953660ULL);
x86_l_14ec:
	/* 0x14ec: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_14f2:
	/* 0x14f2: mov    eax,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 192ULL);
x86_l_14f7:
	/* 0x14f7: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_14fc:
	/* 0x14fc: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1501:
	/* 0x1501: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1504:
	/* 0x1504: mov    esi,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 192ULL);
x86_l_1509:
	/* 0x1509: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_150b:
	/* 0x150b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_150e:
	/* 0x150e: jne    2b5 <perf_unwind_python+0x2b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 693ULL;
	}
x86_l_1514:
	/* 0x1514: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1518:
	/* 0x1518: movzx  ecx,BYTE PTR [rax+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_151c:
	/* 0x151c: mov    ecx,DWORD PTR [r15+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1520:
	/* 0x1520: movzx  edx,BYTE PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_1524:
	/* 0x1524: mov    edx,DWORD PTR [r15+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1528:
	/* 0x1528: movzx  esi,BYTE PTR [rax+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_152c:
	/* 0x152c: mov    esi,DWORD PTR [r15+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1530:
	/* 0x1530: movzx  eax,BYTE PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_1534:
	/* 0x1534: shl    ecx,0x19 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 25ULL);
x86_l_1537:
	/* 0x1537: shl    edx,0x12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 18ULL);
x86_l_153a:
	/* 0x153a: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_153c:
	/* 0x153c: shl    esi,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 10ULL);
x86_l_153f:
	/* 0x153f: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1541:
	/* 0x1541: add    esi,DWORD PTR [r15+rax*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R15, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1545:
	/* 0x1545: shl    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1549:
	/* 0x1549: or     r12,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RSI, X86_WIDTH_64, X86_ALU_OR);
x86_l_154c:
	/* 0x154c: jmp    1753 <perf_unwind_python+0x1753> */
	return 5971ULL;
x86_l_1551:
	/* 0x1551: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1555:
	/* 0x1555: jne    1e6c <perf_unwind_python+0x1e6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7788ULL;
	}
x86_l_155b:
	/* 0x155b: mov    DWORD PTR [rsp+0x18],0x1c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215132ULL);
x86_l_1563:
	/* 0x1563: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_156a:
	/* 0x156a: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_156f:
	/* 0x156f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1574:
	/* 0x1574: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1576:
	/* 0x1576: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1579:
	/* 0x1579: je     173b <perf_unwind_python+0x173b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5947ULL;
	}
x86_l_157f:
	/* 0x157f: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1582:
	/* 0x1582: jmp    1745 <perf_unwind_python+0x1745> */
	return 5957ULL;
x86_l_1587:
	/* 0x1587: movabs rax,0xa307830207369 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2868042528748393ULL);
x86_l_1591:
	/* 0x1591: mov    QWORD PTR [rsp+0x3e],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_1596:
	/* 0x1596: movabs rax,0x7369206574617453 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8316213807032661075ULL);
x86_l_15a0:
	/* 0x15a0: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15a5:
	/* 0x15a5: movabs rax,0x6461657268547950 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7233174018584770896ULL);
x86_l_15af:
	/* 0x15af: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15b4:
	/* 0x15b4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15b9:
	/* 0x15b9: mov    eax,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 22ULL);
x86_l_15be:
	/* 0x15be: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_15c3:
	/* 0x15c3: mov    esi,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 22ULL);
x86_l_15c8:
	/* 0x15c8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15ca:
	/* 0x15ca: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_15cc:
	/* 0x15cc: jmp    928 <perf_unwind_python+0x928> */
	return 2344ULL;
x86_l_15d1:
	/* 0x15d1: movabs rax,0xa786c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541280ULL);
x86_l_15db:
	/* 0x15db: mov    QWORD PTR [rsp+0x57],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_15e0:
	/* 0x15e0: movabs rax,0x20786c2578302074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2339738914604982388ULL);
x86_l_15ea:
	/* 0x15ea: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_15ef:
	/* 0x15ef: movabs rax,0x63656a624f656d61 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7162247752874028385ULL);
x86_l_15f9:
	/* 0x15f9: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15fe:
	/* 0x15fe: movabs rax,0x7246795020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8234402353742245734ULL);
x86_l_1608:
	/* 0x1608: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_160d:
	/* 0x160d: movabs rax,0x207463656a626f65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338603393739812709ULL);
x86_l_1617:
	/* 0x1617: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_161c:
	/* 0x161c: movabs rax,0x646f63206c6c754e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7237112117116826958ULL);
x86_l_1626:
	/* 0x1626: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_162b:
	/* 0x162b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1630:
	/* 0x1630: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_1635:
	/* 0x1635: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_163b:
	/* 0x163b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_163f:
	/* 0x163f: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_1643:
	/* 0x1643: add    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1646:
	/* 0x1646: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_164b:
	/* 0x164b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_164e:
	/* 0x164e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1650:
	/* 0x1650: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1653:
	/* 0x1653: jmp    300 <perf_unwind_python+0x300> */
	return 768ULL;
x86_l_1658:
	/* 0x1658: movabs rax,0xa6c6c75662073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2933962849001587ULL);
x86_l_1662:
	/* 0x1662: mov    QWORD PTR [rsp+0x4d],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_1667:
	/* 0x1667: movabs rax,0x66207369206b6361 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7359008686476059489ULL);
x86_l_1671:
	/* 0x1671: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1676:
	/* 0x1676: movabs rax,0x7473203a656d6172 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8391085965903225202ULL);
x86_l_1680:
	/* 0x1680: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1685:
	/* 0x1685: movabs rax,0x662068737570206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358996636224200815ULL);
x86_l_168f:
	/* 0x168f: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1694:
	/* 0x1694: movabs rax,0x7420656c62616e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367799623835807349ULL);
x86_l_169e:
	/* 0x169e: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16a3:
	/* 0x16a3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16a8:
	/* 0x16a8: mov    eax,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_16ad:
	/* 0x16ad: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_16b2:
	/* 0x16b2: mov    esi,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 37ULL);
x86_l_16b7:
	/* 0x16b7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16b9:
	/* 0x16b9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_16bb:
	/* 0x16bb: jmp    362 <perf_unwind_python+0x362> */
	return 866ULL;
x86_l_16c0:
	/* 0x16c0: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_16ca:
	/* 0x16ca: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_16cf:
	/* 0x16cf: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_16d9:
	/* 0x16d9: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
	return 5854ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5854ULL: goto x86_l_16de;
	case 5864ULL: goto x86_l_16e8;
	case 5869ULL: goto x86_l_16ed;
	case 5879ULL: goto x86_l_16f7;
	case 5884ULL: goto x86_l_16fc;
	case 5894ULL: goto x86_l_1706;
	case 5899ULL: goto x86_l_170b;
	case 5909ULL: goto x86_l_1715;
	case 5914ULL: goto x86_l_171a;
	case 5919ULL: goto x86_l_171f;
	case 5924ULL: goto x86_l_1724;
	case 5929ULL: goto x86_l_1729;
	case 5933ULL: goto x86_l_172d;
	case 5938ULL: goto x86_l_1732;
	case 5940ULL: goto x86_l_1734;
	case 5942ULL: goto x86_l_1736;
	case 5947ULL: goto x86_l_173b;
	case 5951ULL: goto x86_l_173f;
	case 5957ULL: goto x86_l_1745;
	case 5964ULL: goto x86_l_174c;
	case 5966ULL: goto x86_l_174e;
	case 5971ULL: goto x86_l_1753;
	case 5975ULL: goto x86_l_1757;
	case 5981ULL: goto x86_l_175d;
	case 5987ULL: goto x86_l_1763;
	case 5991ULL: goto x86_l_1767;
	case 5997ULL: goto x86_l_176d;
	case 6002ULL: goto x86_l_1772;
	case 6007ULL: goto x86_l_1777;
	case 6017ULL: goto x86_l_1781;
	case 6022ULL: goto x86_l_1786;
	case 6032ULL: goto x86_l_1790;
	case 6037ULL: goto x86_l_1795;
	case 6047ULL: goto x86_l_179f;
	case 6052ULL: goto x86_l_17a4;
	case 6062ULL: goto x86_l_17ae;
	case 6067ULL: goto x86_l_17b3;
	case 6077ULL: goto x86_l_17bd;
	case 6082ULL: goto x86_l_17c2;
	case 6092ULL: goto x86_l_17cc;
	case 6097ULL: goto x86_l_17d1;
	case 6102ULL: goto x86_l_17d6;
	case 6107ULL: goto x86_l_17db;
	case 6112ULL: goto x86_l_17e0;
	case 6116ULL: goto x86_l_17e4;
	case 6121ULL: goto x86_l_17e9;
	case 6123ULL: goto x86_l_17eb;
	case 6125ULL: goto x86_l_17ed;
	case 6130ULL: goto x86_l_17f2;
	case 6140ULL: goto x86_l_17fc;
	case 6145ULL: goto x86_l_1801;
	case 6155ULL: goto x86_l_180b;
	case 6160ULL: goto x86_l_1810;
	case 6170ULL: goto x86_l_181a;
	case 6175ULL: goto x86_l_181f;
	case 6185ULL: goto x86_l_1829;
	case 6190ULL: goto x86_l_182e;
	case 6200ULL: goto x86_l_1838;
	case 6205ULL: goto x86_l_183d;
	case 6215ULL: goto x86_l_1847;
	case 6220ULL: goto x86_l_184c;
	case 6225ULL: goto x86_l_1851;
	case 6230ULL: goto x86_l_1856;
	case 6235ULL: goto x86_l_185b;
	case 6239ULL: goto x86_l_185f;
	case 6244ULL: goto x86_l_1864;
	case 6246ULL: goto x86_l_1866;
	case 6248ULL: goto x86_l_1868;
	case 6253ULL: goto x86_l_186d;
	case 6263ULL: goto x86_l_1877;
	case 6268ULL: goto x86_l_187c;
	case 6278ULL: goto x86_l_1886;
	case 6283ULL: goto x86_l_188b;
	case 6293ULL: goto x86_l_1895;
	case 6298ULL: goto x86_l_189a;
	case 6308ULL: goto x86_l_18a4;
	case 6313ULL: goto x86_l_18a9;
	case 6323ULL: goto x86_l_18b3;
	case 6328ULL: goto x86_l_18b8;
	case 6338ULL: goto x86_l_18c2;
	case 6343ULL: goto x86_l_18c7;
	case 6348ULL: goto x86_l_18cc;
	case 6353ULL: goto x86_l_18d1;
	case 6358ULL: goto x86_l_18d6;
	case 6364ULL: goto x86_l_18dc;
	case 6368ULL: goto x86_l_18e0;
	case 6373ULL: goto x86_l_18e5;
	case 6376ULL: goto x86_l_18e8;
	case 6381ULL: goto x86_l_18ed;
	case 6383ULL: goto x86_l_18ef;
	case 6386ULL: goto x86_l_18f2;
	case 6391ULL: goto x86_l_18f7;
	case 6401ULL: goto x86_l_1901;
	case 6406ULL: goto x86_l_1906;
	case 6416ULL: goto x86_l_1910;
	case 6421ULL: goto x86_l_1915;
	case 6431ULL: goto x86_l_191f;
	case 6436ULL: goto x86_l_1924;
	case 6446ULL: goto x86_l_192e;
	case 6451ULL: goto x86_l_1933;
	case 6461ULL: goto x86_l_193d;
	case 6466ULL: goto x86_l_1942;
	case 6476ULL: goto x86_l_194c;
	case 6481ULL: goto x86_l_1951;
	case 6486ULL: goto x86_l_1956;
	case 6491ULL: goto x86_l_195b;
	case 6496ULL: goto x86_l_1960;
	case 6500ULL: goto x86_l_1964;
	case 6505ULL: goto x86_l_1969;
	case 6507ULL: goto x86_l_196b;
	case 6509ULL: goto x86_l_196d;
	case 6511ULL: goto x86_l_196f;
	case 6516ULL: goto x86_l_1974;
	case 6520ULL: goto x86_l_1978;
	case 6526ULL: goto x86_l_197e;
	case 6532ULL: goto x86_l_1984;
	case 6537ULL: goto x86_l_1989;
	case 6547ULL: goto x86_l_1993;
	case 6552ULL: goto x86_l_1998;
	case 6562ULL: goto x86_l_19a2;
	case 6567ULL: goto x86_l_19a7;
	case 6577ULL: goto x86_l_19b1;
	case 6582ULL: goto x86_l_19b6;
	case 6592ULL: goto x86_l_19c0;
	case 6597ULL: goto x86_l_19c5;
	case 6607ULL: goto x86_l_19cf;
	case 6612ULL: goto x86_l_19d4;
	case 6622ULL: goto x86_l_19de;
	case 6627ULL: goto x86_l_19e3;
	case 6632ULL: goto x86_l_19e8;
	case 6637ULL: goto x86_l_19ed;
	case 6642ULL: goto x86_l_19f2;
	case 6646ULL: goto x86_l_19f6;
	case 6651ULL: goto x86_l_19fb;
	case 6653ULL: goto x86_l_19fd;
	case 6656ULL: goto x86_l_1a00;
	case 6658ULL: goto x86_l_1a02;
	case 6661ULL: goto x86_l_1a05;
	case 6666ULL: goto x86_l_1a0a;
	case 6670ULL: goto x86_l_1a0e;
	case 6673ULL: goto x86_l_1a11;
	case 6678ULL: goto x86_l_1a16;
	case 6684ULL: goto x86_l_1a1c;
	case 6689ULL: goto x86_l_1a21;
	case 6699ULL: goto x86_l_1a2b;
	case 6704ULL: goto x86_l_1a30;
	case 6714ULL: goto x86_l_1a3a;
	case 6719ULL: goto x86_l_1a3f;
	case 6729ULL: goto x86_l_1a49;
	case 6734ULL: goto x86_l_1a4e;
	case 6744ULL: goto x86_l_1a58;
	case 6749ULL: goto x86_l_1a5d;
	case 6754ULL: goto x86_l_1a62;
	case 6759ULL: goto x86_l_1a67;
	case 6764ULL: goto x86_l_1a6c;
	case 6769ULL: goto x86_l_1a71;
	case 6771ULL: goto x86_l_1a73;
	case 6773ULL: goto x86_l_1a75;
	case 6778ULL: goto x86_l_1a7a;
	case 6788ULL: goto x86_l_1a84;
	case 6793ULL: goto x86_l_1a89;
	case 6803ULL: goto x86_l_1a93;
	case 6808ULL: goto x86_l_1a98;
	case 6818ULL: goto x86_l_1aa2;
	case 6823ULL: goto x86_l_1aa7;
	case 6833ULL: goto x86_l_1ab1;
	case 6838ULL: goto x86_l_1ab6;
	case 6848ULL: goto x86_l_1ac0;
	case 6853ULL: goto x86_l_1ac5;
	case 6863ULL: goto x86_l_1acf;
	case 6868ULL: goto x86_l_1ad4;
	case 6873ULL: goto x86_l_1ad9;
	case 6878ULL: goto x86_l_1ade;
	case 6883ULL: goto x86_l_1ae3;
	case 6887ULL: goto x86_l_1ae7;
	case 6892ULL: goto x86_l_1aec;
	case 6894ULL: goto x86_l_1aee;
	case 6896ULL: goto x86_l_1af0;
	case 6901ULL: goto x86_l_1af5;
	case 6911ULL: goto x86_l_1aff;
	case 6916ULL: goto x86_l_1b04;
	case 6926ULL: goto x86_l_1b0e;
	case 6931ULL: goto x86_l_1b13;
	case 6941ULL: goto x86_l_1b1d;
	case 6946ULL: goto x86_l_1b22;
	case 6956ULL: goto x86_l_1b2c;
	case 6961ULL: goto x86_l_1b31;
	case 6971ULL: goto x86_l_1b3b;
	case 6976ULL: goto x86_l_1b40;
	case 6981ULL: goto x86_l_1b45;
	case 6986ULL: goto x86_l_1b4a;
	case 6991ULL: goto x86_l_1b4f;
	case 6996ULL: goto x86_l_1b54;
	case 7001ULL: goto x86_l_1b59;
	case 7003ULL: goto x86_l_1b5b;
	case 7005ULL: goto x86_l_1b5d;
	case 7010ULL: goto x86_l_1b62;
	case 7020ULL: goto x86_l_1b6c;
	case 7025ULL: goto x86_l_1b71;
	case 7035ULL: goto x86_l_1b7b;
	case 7040ULL: goto x86_l_1b80;
	case 7050ULL: goto x86_l_1b8a;
	case 7055ULL: goto x86_l_1b8f;
	case 7065ULL: goto x86_l_1b99;
	case 7070ULL: goto x86_l_1b9e;
	case 7080ULL: goto x86_l_1ba8;
	case 7085ULL: goto x86_l_1bad;
	case 7095ULL: goto x86_l_1bb7;
	case 7100ULL: goto x86_l_1bbc;
	case 7105ULL: goto x86_l_1bc1;
	case 7110ULL: goto x86_l_1bc6;
	case 7115ULL: goto x86_l_1bcb;
	case 7119ULL: goto x86_l_1bcf;
	case 7124ULL: goto x86_l_1bd4;
	case 7126ULL: goto x86_l_1bd6;
	case 7128ULL: goto x86_l_1bd8;
	case 7133ULL: goto x86_l_1bdd;
	case 7143ULL: goto x86_l_1be7;
	case 7148ULL: goto x86_l_1bec;
	case 7158ULL: goto x86_l_1bf6;
	case 7163ULL: goto x86_l_1bfb;
	case 7173ULL: goto x86_l_1c05;
	case 7178ULL: goto x86_l_1c0a;
	case 7183ULL: goto x86_l_1c0f;
	case 7188ULL: goto x86_l_1c14;
	case 7194ULL: goto x86_l_1c1a;
	case 7199ULL: goto x86_l_1c1f;
	case 7204ULL: goto x86_l_1c24;
	case 7207ULL: goto x86_l_1c27;
	case 7209ULL: goto x86_l_1c29;
	case 7212ULL: goto x86_l_1c2c;
	case 7218ULL: goto x86_l_1c32;
	case 7222ULL: goto x86_l_1c36;
	case 7228ULL: goto x86_l_1c3c;
	case 7231ULL: goto x86_l_1c3f;
	case 7237ULL: goto x86_l_1c45;
	case 7241ULL: goto x86_l_1c49;
	case 7246ULL: goto x86_l_1c4e;
	case 7254ULL: goto x86_l_1c56;
	case 7262ULL: goto x86_l_1c5e;
	case 7270ULL: goto x86_l_1c66;
	case 7281ULL: goto x86_l_1c71;
	case 7292ULL: goto x86_l_1c7c;
	case 7300ULL: goto x86_l_1c84;
	case 7307ULL: goto x86_l_1c8b;
	case 7312ULL: goto x86_l_1c90;
	case 7317ULL: goto x86_l_1c95;
	case 7319ULL: goto x86_l_1c97;
	case 7322ULL: goto x86_l_1c9a;
	case 7324ULL: goto x86_l_1c9c;
	case 7327ULL: goto x86_l_1c9f;
	case 7329ULL: goto x86_l_1ca1;
	case 7335ULL: goto x86_l_1ca7;
	case 7337ULL: goto x86_l_1ca9;
	case 7341ULL: goto x86_l_1cad;
	case 7347ULL: goto x86_l_1cb3;
	case 7349ULL: goto x86_l_1cb5;
	case 7355ULL: goto x86_l_1cbb;
	case 7358ULL: goto x86_l_1cbe;
	case 7361ULL: goto x86_l_1cc1;
	case 7367ULL: goto x86_l_1cc7;
	case 7371ULL: goto x86_l_1ccb;
	case 7375ULL: goto x86_l_1ccf;
	case 7381ULL: goto x86_l_1cd5;
	case 7385ULL: goto x86_l_1cd9;
	case 7389ULL: goto x86_l_1cdd;
	case 7395ULL: goto x86_l_1ce3;
	case 7399ULL: goto x86_l_1ce7;
	case 7403ULL: goto x86_l_1ceb;
	case 7409ULL: goto x86_l_1cf1;
	case 7413ULL: goto x86_l_1cf5;
	case 7417ULL: goto x86_l_1cf9;
	case 7423ULL: goto x86_l_1cff;
	case 7428ULL: goto x86_l_1d04;
	case 7433ULL: goto x86_l_1d09;
	case 7438ULL: goto x86_l_1d0e;
	case 7443ULL: goto x86_l_1d13;
	case 7446ULL: goto x86_l_1d16;
	case 7448ULL: goto x86_l_1d18;
	case 7451ULL: goto x86_l_1d1b;
	case 7453ULL: goto x86_l_1d1d;
	case 7458ULL: goto x86_l_1d22;
	case 7463ULL: goto x86_l_1d27;
	case 7467ULL: goto x86_l_1d2b;
	case 7471ULL: goto x86_l_1d2f;
	case 7476ULL: goto x86_l_1d34;
	case 7480ULL: goto x86_l_1d38;
	case 7485ULL: goto x86_l_1d3d;
	case 7489ULL: goto x86_l_1d41;
	case 7493ULL: goto x86_l_1d45;
	case 7498ULL: goto x86_l_1d4a;
	case 7502ULL: goto x86_l_1d4e;
	case 7505ULL: goto x86_l_1d51;
	case 7507ULL: goto x86_l_1d53;
	case 7512ULL: goto x86_l_1d58;
	case 7514ULL: goto x86_l_1d5a;
	case 7519ULL: goto x86_l_1d5f;
	case 7524ULL: goto x86_l_1d64;
	case 7529ULL: goto x86_l_1d69;
	case 7534ULL: goto x86_l_1d6e;
	case 7538ULL: goto x86_l_1d72;
	case 7542ULL: goto x86_l_1d76;
	case 7546ULL: goto x86_l_1d7a;
	case 7548ULL: goto x86_l_1d7c;
	case 7553ULL: goto x86_l_1d81;
	case 7557ULL: goto x86_l_1d85;
	case 7561ULL: goto x86_l_1d89;
	case 7565ULL: goto x86_l_1d8d;
	case 7570ULL: goto x86_l_1d92;
	case 7573ULL: goto x86_l_1d95;
	case 7580ULL: goto x86_l_1d9c;
	case 7582ULL: goto x86_l_1d9e;
	case 7589ULL: goto x86_l_1da5;
	case 7595ULL: goto x86_l_1dab;
	case 7599ULL: goto x86_l_1daf;
	case 7603ULL: goto x86_l_1db3;
	case 7607ULL: goto x86_l_1db7;
	case 7610ULL: goto x86_l_1dba;
	case 7613ULL: goto x86_l_1dbd;
	case 7615ULL: goto x86_l_1dbf;
	case 7620ULL: goto x86_l_1dc4;
	case 7624ULL: goto x86_l_1dc8;
	case 7626ULL: goto x86_l_1dca;
	case 7632ULL: goto x86_l_1dd0;
	case 7634ULL: goto x86_l_1dd2;
	case 7638ULL: goto x86_l_1dd6;
	case 7642ULL: goto x86_l_1dda;
	case 7648ULL: goto x86_l_1de0;
	case 7652ULL: goto x86_l_1de4;
	case 7656ULL: goto x86_l_1de8;
	case 7662ULL: goto x86_l_1dee;
	case 7666ULL: goto x86_l_1df2;
	case 7670ULL: goto x86_l_1df6;
	case 7676ULL: goto x86_l_1dfc;
	case 7680ULL: goto x86_l_1e00;
	case 7684ULL: goto x86_l_1e04;
	case 7690ULL: goto x86_l_1e0a;
	case 7695ULL: goto x86_l_1e0f;
	case 7700ULL: goto x86_l_1e14;
	case 7705ULL: goto x86_l_1e19;
	case 7708ULL: goto x86_l_1e1c;
	case 7713ULL: goto x86_l_1e21;
	case 7715ULL: goto x86_l_1e23;
	case 7718ULL: goto x86_l_1e26;
	case 7724ULL: goto x86_l_1e2c;
	case 7729ULL: goto x86_l_1e31;
	case 7734ULL: goto x86_l_1e36;
	case 7738ULL: goto x86_l_1e3a;
	case 7744ULL: goto x86_l_1e40;
	case 7752ULL: goto x86_l_1e48;
	case 7759ULL: goto x86_l_1e4f;
	case 7764ULL: goto x86_l_1e54;
	case 7769ULL: goto x86_l_1e59;
	case 7771ULL: goto x86_l_1e5b;
	case 7774ULL: goto x86_l_1e5e;
	case 7780ULL: goto x86_l_1e64;
	case 7783ULL: goto x86_l_1e67;
	case 7788ULL: goto x86_l_1e6c;
	case 7798ULL: goto x86_l_1e76;
	case 7803ULL: goto x86_l_1e7b;
	case 7813ULL: goto x86_l_1e85;
	case 7818ULL: goto x86_l_1e8a;
	case 7828ULL: goto x86_l_1e94;
	case 7833ULL: goto x86_l_1e99;
	case 7843ULL: goto x86_l_1ea3;
	case 7848ULL: goto x86_l_1ea8;
	case 7858ULL: goto x86_l_1eb2;
	case 7863ULL: goto x86_l_1eb7;
	case 7873ULL: goto x86_l_1ec1;
	case 7878ULL: goto x86_l_1ec6;
	case 7883ULL: goto x86_l_1ecb;
	case 7888ULL: goto x86_l_1ed0;
	case 7894ULL: goto x86_l_1ed6;
	case 7898ULL: goto x86_l_1eda;
	case 7902ULL: goto x86_l_1ede;
	case 7907ULL: goto x86_l_1ee3;
	case 7910ULL: goto x86_l_1ee6;
	case 7915ULL: goto x86_l_1eeb;
	case 7917ULL: goto x86_l_1eed;
	case 7920ULL: goto x86_l_1ef0;
	case 7925ULL: goto x86_l_1ef5;
	case 7929ULL: goto x86_l_1ef9;
	case 7935ULL: goto x86_l_1eff;
	case 7942ULL: goto x86_l_1f06;
	default: return 0xffffffffffffffffULL;
	}
x86_l_16de:
	/* 0x16de: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_16e8:
	/* 0x16e8: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_16ed:
	/* 0x16ed: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_16f7:
	/* 0x16f7: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16fc:
	/* 0x16fc: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1706:
	/* 0x1706: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_170b:
	/* 0x170b: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1715:
	/* 0x1715: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_171a:
	/* 0x171a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_171f:
	/* 0x171f: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1724:
	/* 0x1724: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1729:
	/* 0x1729: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_172d:
	/* 0x172d: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1732:
	/* 0x1732: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1734:
	/* 0x1734: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1736:
	/* 0x1736: jmp    9d0 <perf_unwind_python+0x9d0> */
	return 2512ULL;
x86_l_173b:
	/* 0x173b: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_173f:
	/* 0x173f: jne    1f36 <perf_unwind_python+0x1f36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7990ULL;
	}
x86_l_1745:
	/* 0x1745: mov    r12,0xfffffffffffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_174c:
	/* 0x174c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_174e:
	/* 0x174e: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1753:
	/* 0x1753: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1757:
	/* 0x1757: jne    1bdd <perf_unwind_python+0x1bdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bdd;
	}
x86_l_175d:
	/* 0x175d: mov    eax,DWORD PTR [rbp+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_1763:
	/* 0x1763: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_1767:
	/* 0x1767: jbe    1c3c <perf_unwind_python+0x1c3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1c3c;
	}
x86_l_176d:
	/* 0x176d: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1772:
	/* 0x1772: jmp    358 <perf_unwind_python+0x358> */
	return 856ULL;
x86_l_1777:
	/* 0x1777: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1781:
	/* 0x1781: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1786:
	/* 0x1786: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1790:
	/* 0x1790: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1795:
	/* 0x1795: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_179f:
	/* 0x179f: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17a4:
	/* 0x17a4: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_17ae:
	/* 0x17ae: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_17b3:
	/* 0x17b3: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_17bd:
	/* 0x17bd: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17c2:
	/* 0x17c2: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_17cc:
	/* 0x17cc: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17d1:
	/* 0x17d1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17d6:
	/* 0x17d6: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_17db:
	/* 0x17db: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_17e0:
	/* 0x17e0: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17e4:
	/* 0x17e4: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_17e9:
	/* 0x17e9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17eb:
	/* 0x17eb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_17ed:
	/* 0x17ed: jmp    a1b <perf_unwind_python+0xa1b> */
	return 2587ULL;
x86_l_17f2:
	/* 0x17f2: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_17fc:
	/* 0x17fc: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1801:
	/* 0x1801: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_180b:
	/* 0x180b: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1810:
	/* 0x1810: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_181a:
	/* 0x181a: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_181f:
	/* 0x181f: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1829:
	/* 0x1829: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_182e:
	/* 0x182e: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1838:
	/* 0x1838: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_183d:
	/* 0x183d: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1847:
	/* 0x1847: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_184c:
	/* 0x184c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1851:
	/* 0x1851: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1856:
	/* 0x1856: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_185b:
	/* 0x185b: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_185f:
	/* 0x185f: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1864:
	/* 0x1864: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1866:
	/* 0x1866: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1868:
	/* 0x1868: jmp    323 <perf_unwind_python+0x323> */
	return 803ULL;
x86_l_186d:
	/* 0x186d: movabs rcx,0xa786c2578302074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 754471845770567796ULL);
x86_l_1877:
	/* 0x1877: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_187c:
	/* 0x187c: movabs rcx,0x6120656d6172665f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 6998705341394478687ULL);
x86_l_1886:
	/* 0x1886: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_188b:
	/* 0x188b: movabs rcx,0x746e65727275632e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 8389754698058785582ULL);
x86_l_1895:
	/* 0x1895: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_189a:
	/* 0x189a: movabs rcx,0x656d617246437950 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 7308604913725176144ULL);
x86_l_18a4:
	/* 0x18a4: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18a9:
	/* 0x18a9: movabs rcx,0x5f2064616572206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 6854589002334478447ULL);
x86_l_18b3:
	/* 0x18b3: mov    QWORD PTR [rsp+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18b8:
	/* 0x18b8: movabs rcx,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_18c2:
	/* 0x18c2: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18c7:
	/* 0x18c7: mov    BYTE PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_18cc:
	/* 0x18cc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18d1:
	/* 0x18d1: mov    ecx,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 49ULL);
x86_l_18d6:
	/* 0x18d6: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_18dc:
	/* 0x18dc: movzx  edx,BYTE PTR [rax+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_18e0:
	/* 0x18e0: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18e5:
	/* 0x18e5: add    rdx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_18e8:
	/* 0x18e8: mov    esi,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 49ULL);
x86_l_18ed:
	/* 0x18ed: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18ef:
	/* 0x18ef: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_18f2:
	/* 0x18f2: jmp    9a1 <perf_unwind_python+0x9a1> */
	return 2465ULL;
x86_l_18f7:
	/* 0x18f7: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1901:
	/* 0x1901: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1906:
	/* 0x1906: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1910:
	/* 0x1910: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1915:
	/* 0x1915: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_191f:
	/* 0x191f: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1924:
	/* 0x1924: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_192e:
	/* 0x192e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1933:
	/* 0x1933: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_193d:
	/* 0x193d: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1942:
	/* 0x1942: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_194c:
	/* 0x194c: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1951:
	/* 0x1951: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1956:
	/* 0x1956: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_195b:
	/* 0x195b: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1960:
	/* 0x1960: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1964:
	/* 0x1964: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1969:
	/* 0x1969: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_196b:
	/* 0x196b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_196d:
	/* 0x196d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_196f:
	/* 0x196f: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1974:
	/* 0x1974: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1978:
	/* 0x1978: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_197e:
	/* 0x197e: je     168 <perf_unwind_python+0x168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 360ULL;
	}
x86_l_1984:
	/* 0x1984: jmp    3a0 <perf_unwind_python+0x3a0> */
	return 928ULL;
x86_l_1989:
	/* 0x1989: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1993:
	/* 0x1993: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1998:
	/* 0x1998: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_19a2:
	/* 0x19a2: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_19a7:
	/* 0x19a7: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_19b1:
	/* 0x19b1: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19b6:
	/* 0x19b6: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_19c0:
	/* 0x19c0: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19c5:
	/* 0x19c5: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_19cf:
	/* 0x19cf: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19d4:
	/* 0x19d4: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_19de:
	/* 0x19de: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19e3:
	/* 0x19e3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19e8:
	/* 0x19e8: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_19ed:
	/* 0x19ed: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_19f2:
	/* 0x19f2: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19f6:
	/* 0x19f6: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_19fb:
	/* 0x19fb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19fd:
	/* 0x19fd: mov    r12d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_32);
x86_l_1a00:
	/* 0x1a00: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1a02:
	/* 0x1a02: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1a05:
	/* 0x1a05: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a0a:
	/* 0x1a0a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a0e:
	/* 0x1a0e: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_1a11:
	/* 0x1a11: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a16:
	/* 0x1a16: jne    1b8 <perf_unwind_python+0x1b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 440ULL;
	}
x86_l_1a1c:
	/* 0x1a1c: jmp    c0f <perf_unwind_python+0xc0f> */
	return 3087ULL;
x86_l_1a21:
	/* 0x1a21: movabs rax,0xa64656c646e61 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2925136540102241ULL);
x86_l_1a2b:
	/* 0x1a2b: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1a30:
	/* 0x1a30: movabs rax,0x6820657261207365 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7503108521129440101ULL);
x86_l_1a3a:
	/* 0x1a3a: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a3f:
	/* 0x1a3f: movabs rax,0x6d617266206e6f68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7881706605831417704ULL);
x86_l_1a49:
	/* 0x1a49: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a4e:
	/* 0x1a4e: movabs rax,0x747950203e2d2020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8392827479993950240ULL);
x86_l_1a58:
	/* 0x1a58: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a5d:
	/* 0x1a5d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a62:
	/* 0x1a62: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_1a67:
	/* 0x1a67: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1a6c:
	/* 0x1a6c: mov    esi,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32ULL);
x86_l_1a71:
	/* 0x1a71: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a73:
	/* 0x1a73: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1a75:
	/* 0x1a75: jmp    9fc <perf_unwind_python+0x9fc> */
	return 2556ULL;
x86_l_1a7a:
	/* 0x1a7a: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1a84:
	/* 0x1a84: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1a89:
	/* 0x1a89: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1a93:
	/* 0x1a93: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a98:
	/* 0x1a98: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1aa2:
	/* 0x1aa2: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1aa7:
	/* 0x1aa7: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1ab1:
	/* 0x1ab1: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ab6:
	/* 0x1ab6: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1ac0:
	/* 0x1ac0: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ac5:
	/* 0x1ac5: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1acf:
	/* 0x1acf: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ad4:
	/* 0x1ad4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ad9:
	/* 0x1ad9: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1ade:
	/* 0x1ade: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1ae3:
	/* 0x1ae3: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ae7:
	/* 0x1ae7: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1aec:
	/* 0x1aec: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aee:
	/* 0x1aee: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1af0:
	/* 0x1af0: jmp    a36 <perf_unwind_python+0xa36> */
	return 2614ULL;
x86_l_1af5:
	/* 0x1af5: movabs rax,0xa786c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541280ULL);
x86_l_1aff:
	/* 0x1aff: mov    QWORD PTR [rsp+0x4e],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_1b04:
	/* 0x1b04: movabs rax,0x3020746120746365 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 3467899673580430181ULL);
x86_l_1b0e:
	/* 0x1b0e: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b13:
	/* 0x1b13: movabs rax,0x6a624f65646f4379 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7665776812633310073ULL);
x86_l_1b1d:
	/* 0x1b1d: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b22:
	/* 0x1b22: movabs rax,0x502064616572206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5773725091765559407ULL);
x86_l_1b2c:
	/* 0x1b2c: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b31:
	/* 0x1b31: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1b3b:
	/* 0x1b3b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b40:
	/* 0x1b40: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b45:
	/* 0x1b45: mov    eax,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 38ULL);
x86_l_1b4a:
	/* 0x1b4a: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1b4f:
	/* 0x1b4f: mov    esi,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 38ULL);
x86_l_1b54:
	/* 0x1b54: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b59:
	/* 0x1b59: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b5b:
	/* 0x1b5b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b5d:
	/* 0x1b5d: jmp    2c2 <perf_unwind_python+0x2c2> */
	return 706ULL;
x86_l_1b62:
	/* 0x1b62: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1b6c:
	/* 0x1b6c: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1b71:
	/* 0x1b71: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1b7b:
	/* 0x1b7b: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b80:
	/* 0x1b80: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1b8a:
	/* 0x1b8a: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b8f:
	/* 0x1b8f: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1b99:
	/* 0x1b99: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b9e:
	/* 0x1b9e: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1ba8:
	/* 0x1ba8: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1bad:
	/* 0x1bad: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1bb7:
	/* 0x1bb7: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bbc:
	/* 0x1bbc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bc1:
	/* 0x1bc1: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1bc6:
	/* 0x1bc6: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1bcb:
	/* 0x1bcb: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bcf:
	/* 0x1bcf: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1bd4:
	/* 0x1bd4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bd6:
	/* 0x1bd6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1bd8:
	/* 0x1bd8: jmp    d6e <perf_unwind_python+0xd6e> */
	return 3438ULL;
x86_l_1bdd:
	/* 0x1bdd: movabs rax,0xa756c2520786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2943857106909292ULL);
x86_l_1be7:
	/* 0x1be7: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1bec:
	/* 0x1bec: movabs rax,0x25206e6f68747950 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675259603430963536ULL);
x86_l_1bf6:
	/* 0x1bf6: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1bfb:
	/* 0x1bfb: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_1c05:
	/* 0x1c05: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c0a:
	/* 0x1c0a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c0f:
	/* 0x1c0f: mov    eax,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_1c14:
	/* 0x1c14: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_1c1a:
	/* 0x1c1a: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_1c1f:
	/* 0x1c1f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c24:
	/* 0x1c24: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_1c27:
	/* 0x1c27: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c29:
	/* 0x1c29: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1c2c:
	/* 0x1c2c: mov    eax,DWORD PTR [rbp+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_1c32:
	/* 0x1c32: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_1c36:
	/* 0x1c36: ja     176d <perf_unwind_python+0x176d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_176d;
	}
x86_l_1c3c:
	/* 0x1c3c: lea    ecx,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1c3f:
	/* 0x1c3f: mov    DWORD PTR [rbp+0x2c0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_1c45:
	/* 0x1c45: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1c49:
	/* 0x1c49: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c4e:
	/* 0x1c4e: mov    QWORD PTR [rbp+rax*8+0x2d0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_1c56:
	/* 0x1c56: mov    QWORD PTR [rbp+rax*8+0x2d8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_1c5e:
	/* 0x1c5e: mov    BYTE PTR [rbp+rax*8+0x2e0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929857ULL);
x86_l_1c66:
	/* 0x1c66: mov    DWORD PTR [rbp+rax*8+0x2e1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3165390897152ULL);
x86_l_1c71:
	/* 0x1c71: mov    DWORD PTR [rbp+rax*8+0x2e4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3178275799040ULL);
x86_l_1c7c:
	/* 0x1c7c: mov    DWORD PTR [rsp+0x18],0x16 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215126ULL);
x86_l_1c84:
	/* 0x1c84: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_1c8b:
	/* 0x1c8b: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c90:
	/* 0x1c90: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c95:
	/* 0x1c95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c97:
	/* 0x1c97: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c9a:
	/* 0x1c9a: je     1ca9 <perf_unwind_python+0x1ca9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ca9;
	}
x86_l_1c9c:
	/* 0x1c9c: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1c9f:
	/* 0x1c9f: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
x86_l_1ca1:
	/* 0x1ca1: jne    1242 <perf_unwind_python+0x1242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4674ULL;
	}
x86_l_1ca7:
	/* 0x1ca7: jmp    1cbb <perf_unwind_python+0x1cbb> */
	goto x86_l_1cbb;
x86_l_1ca9:
	/* 0x1ca9: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cad:
	/* 0x1cad: jne    1fb1 <perf_unwind_python+0x1fb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8113ULL;
	}
x86_l_1cb3:
	/* 0x1cb3: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
x86_l_1cb5:
	/* 0x1cb5: jne    1242 <perf_unwind_python+0x1242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4674ULL;
	}
x86_l_1cbb:
	/* 0x1cbb: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cbe:
	/* 0x1cbe: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1cc1:
	/* 0x1cc1: je     45b4 <perf_unwind_python+0x45b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17844ULL;
	}
x86_l_1cc7:
	/* 0x1cc7: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ccb:
	/* 0x1ccb: cmp    BYTE PTR [rax+0x19],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 107374182520ULL);
x86_l_1ccf:
	/* 0x1ccf: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_1cd5:
	/* 0x1cd5: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cd9:
	/* 0x1cd9: cmp    BYTE PTR [rax+0x18],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215224ULL);
x86_l_1cdd:
	/* 0x1cdd: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_1ce3:
	/* 0x1ce3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ce7:
	/* 0x1ce7: cmp    BYTE PTR [rax+0x1a],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 111669149816ULL);
x86_l_1ceb:
	/* 0x1ceb: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_1cf1:
	/* 0x1cf1: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cf5:
	/* 0x1cf5: cmp    BYTE PTR [rax+0x1b],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 115964116992ULL);
x86_l_1cf9:
	/* 0x1cf9: js     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 17920ULL;
	}
x86_l_1cff:
	/* 0x1cff: mov    eax,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 128ULL);
x86_l_1d04:
	/* 0x1d04: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_1d09:
	/* 0x1d09: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1d0e:
	/* 0x1d0e: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_1d13:
	/* 0x1d13: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1d16:
	/* 0x1d16: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1d18:
	/* 0x1d18: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d1b:
	/* 0x1d1b: je     1d27 <perf_unwind_python+0x1d27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d27;
	}
x86_l_1d1d:
	/* 0x1d1d: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d22:
	/* 0x1d22: jmp    ed <perf_unwind_python+0xed> */
	return 237ULL;
x86_l_1d27:
	/* 0x1d27: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d2b:
	/* 0x1d2b: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_1d2f:
	/* 0x1d2f: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1d34:
	/* 0x1d34: mov    rcx,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1d38:
	/* 0x1d38: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d3d:
	/* 0x1d3d: movzx  ecx,BYTE PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_1d41:
	/* 0x1d41: mov    rcx,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1d45:
	/* 0x1d45: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d4a:
	/* 0x1d4a: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d4e:
	/* 0x1d4e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d51:
	/* 0x1d51: je     1d6e <perf_unwind_python+0x1d6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d6e;
	}
x86_l_1d53:
	/* 0x1d53: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d58:
	/* 0x1d58: jne    1d6e <perf_unwind_python+0x1d6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d6e;
	}
x86_l_1d5a:
	/* 0x1d5a: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d5f:
	/* 0x1d5f: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d64:
	/* 0x1d64: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d69:
	/* 0x1d69: jmp    1b8 <perf_unwind_python+0x1b8> */
	return 440ULL;
x86_l_1d6e:
	/* 0x1d6e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d72:
	/* 0x1d72: cmp    BYTE PTR [rax+0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_1d76:
	/* 0x1d76: movzx  eax,BYTE PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 26ULL);
x86_l_1d7a:
	/* 0x1d7a: je     1dbf <perf_unwind_python+0x1dbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dbf;
	}
x86_l_1d7c:
	/* 0x1d7c: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1d81:
	/* 0x1d81: mov    rax,QWORD PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1d85:
	/* 0x1d85: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d89:
	/* 0x1d89: movzx  edx,BYTE PTR [rcx+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_1d8d:
	/* 0x1d8d: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_1d92:
	/* 0x1d92: sub    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1d95:
	/* 0x1d95: lea    rdx,[rax-0x10000001] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073441116159ULL);
x86_l_1d9c:
	/* 0x1d9c: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_1d9e:
	/* 0x1d9e: cmp    rdx,0xffffffffeffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073441116157ULL);
x86_l_1da5:
	/* 0x1da5: mov    r12d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_1dab:
	/* 0x1dab: cmovae r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_1daf:
	/* 0x1daf: movzx  eax,BYTE PTR [rcx+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_1db3:
	/* 0x1db3: movzx  eax,BYTE PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1db7:
	/* 0x1db7: cmp    al,BYTE PTR [rcx+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_1dba:
	/* 0x1dba: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_1dbd:
	/* 0x1dbd: jmp    1dca <perf_unwind_python+0x1dca> */
	goto x86_l_1dca;
x86_l_1dbf:
	/* 0x1dbf: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1dc4:
	/* 0x1dc4: mov    r12d,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1dc8:
	/* 0x1dc8: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dca:
	/* 0x1dca: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1dd0:
	/* 0x1dd0: je     1e36 <perf_unwind_python+0x1e36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e36;
	}
x86_l_1dd2:
	/* 0x1dd2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dd6:
	/* 0x1dd6: cmp    BYTE PTR [rax+0x1d],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051772ULL);
x86_l_1dda:
	/* 0x1dda: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_1de0:
	/* 0x1de0: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1de4:
	/* 0x1de4: cmp    BYTE PTR [rax+0x1e],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128849019068ULL);
x86_l_1de8:
	/* 0x1de8: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_1dee:
	/* 0x1dee: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1df2:
	/* 0x1df2: cmp    BYTE PTR [rax+0x1f],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133143986364ULL);
x86_l_1df6:
	/* 0x1df6: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_1dfc:
	/* 0x1dfc: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e00:
	/* 0x1e00: cmp    BYTE PTR [rax+0x20],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953660ULL);
x86_l_1e04:
	/* 0x1e04: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_1e0a:
	/* 0x1e0a: mov    eax,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 192ULL);
x86_l_1e0f:
	/* 0x1e0f: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_1e14:
	/* 0x1e14: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e19:
	/* 0x1e19: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1e1c:
	/* 0x1e1c: mov    esi,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 192ULL);
x86_l_1e21:
	/* 0x1e21: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1e23:
	/* 0x1e23: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e26:
	/* 0x1e26: je     2034 <perf_unwind_python+0x2034> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8244ULL;
	}
x86_l_1e2c:
	/* 0x1e2c: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e31:
	/* 0x1e31: jmp    2b5 <perf_unwind_python+0x2b5> */
	return 693ULL;
x86_l_1e36:
	/* 0x1e36: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e3a:
	/* 0x1e3a: jne    2326 <perf_unwind_python+0x2326> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8998ULL;
	}
x86_l_1e40:
	/* 0x1e40: mov    DWORD PTR [rsp+0x18],0x1c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215132ULL);
x86_l_1e48:
	/* 0x1e48: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_1e4f:
	/* 0x1e4f: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e54:
	/* 0x1e54: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e59:
	/* 0x1e59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e5b:
	/* 0x1e5b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e5e:
	/* 0x1e5e: je     1ef5 <perf_unwind_python+0x1ef5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ef5;
	}
x86_l_1e64:
	/* 0x1e64: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1e67:
	/* 0x1e67: jmp    1eff <perf_unwind_python+0x1eff> */
	goto x86_l_1eff;
x86_l_1e6c:
	/* 0x1e6c: movabs rax,0xa786c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541280ULL);
x86_l_1e76:
	/* 0x1e76: mov    QWORD PTR [rsp+0x57],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_1e7b:
	/* 0x1e7b: movabs rax,0x20786c2578302074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2339738914604982388ULL);
x86_l_1e85:
	/* 0x1e85: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e8a:
	/* 0x1e8a: movabs rax,0x63656a624f656d61 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7162247752874028385ULL);
x86_l_1e94:
	/* 0x1e94: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1e99:
	/* 0x1e99: movabs rax,0x7246795020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8234402353742245734ULL);
x86_l_1ea3:
	/* 0x1ea3: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ea8:
	/* 0x1ea8: movabs rax,0x207463656a626f65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338603393739812709ULL);
x86_l_1eb2:
	/* 0x1eb2: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1eb7:
	/* 0x1eb7: movabs rax,0x646f63206c6c754e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7237112117116826958ULL);
x86_l_1ec1:
	/* 0x1ec1: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ec6:
	/* 0x1ec6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ecb:
	/* 0x1ecb: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_1ed0:
	/* 0x1ed0: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_1ed6:
	/* 0x1ed6: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eda:
	/* 0x1eda: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_1ede:
	/* 0x1ede: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ee3:
	/* 0x1ee3: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ee6:
	/* 0x1ee6: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_1eeb:
	/* 0x1eeb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1eed:
	/* 0x1eed: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1ef0:
	/* 0x1ef0: jmp    155b <perf_unwind_python+0x155b> */
	return 5467ULL;
x86_l_1ef5:
	/* 0x1ef5: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ef9:
	/* 0x1ef9: jne    2453 <perf_unwind_python+0x2453> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9299ULL;
	}
x86_l_1eff:
	/* 0x1eff: mov    r12,0xfffffffffffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1f06:
	/* 0x1f06: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
	return 7944ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7944ULL: goto x86_l_1f08;
	case 7949ULL: goto x86_l_1f0d;
	case 7953ULL: goto x86_l_1f11;
	case 7959ULL: goto x86_l_1f17;
	case 7965ULL: goto x86_l_1f1d;
	case 7969ULL: goto x86_l_1f21;
	case 7975ULL: goto x86_l_1f27;
	case 7980ULL: goto x86_l_1f2c;
	case 7985ULL: goto x86_l_1f31;
	case 7990ULL: goto x86_l_1f36;
	case 8000ULL: goto x86_l_1f40;
	case 8005ULL: goto x86_l_1f45;
	case 8015ULL: goto x86_l_1f4f;
	case 8020ULL: goto x86_l_1f54;
	case 8030ULL: goto x86_l_1f5e;
	case 8035ULL: goto x86_l_1f63;
	case 8045ULL: goto x86_l_1f6d;
	case 8050ULL: goto x86_l_1f72;
	case 8060ULL: goto x86_l_1f7c;
	case 8065ULL: goto x86_l_1f81;
	case 8075ULL: goto x86_l_1f8b;
	case 8080ULL: goto x86_l_1f90;
	case 8085ULL: goto x86_l_1f95;
	case 8090ULL: goto x86_l_1f9a;
	case 8095ULL: goto x86_l_1f9f;
	case 8099ULL: goto x86_l_1fa3;
	case 8104ULL: goto x86_l_1fa8;
	case 8106ULL: goto x86_l_1faa;
	case 8108ULL: goto x86_l_1fac;
	case 8113ULL: goto x86_l_1fb1;
	case 8123ULL: goto x86_l_1fbb;
	case 8128ULL: goto x86_l_1fc0;
	case 8138ULL: goto x86_l_1fca;
	case 8143ULL: goto x86_l_1fcf;
	case 8153ULL: goto x86_l_1fd9;
	case 8158ULL: goto x86_l_1fde;
	case 8168ULL: goto x86_l_1fe8;
	case 8173ULL: goto x86_l_1fed;
	case 8183ULL: goto x86_l_1ff7;
	case 8188ULL: goto x86_l_1ffc;
	case 8198ULL: goto x86_l_2006;
	case 8203ULL: goto x86_l_200b;
	case 8208ULL: goto x86_l_2010;
	case 8213ULL: goto x86_l_2015;
	case 8218ULL: goto x86_l_201a;
	case 8222ULL: goto x86_l_201e;
	case 8227ULL: goto x86_l_2023;
	case 8229ULL: goto x86_l_2025;
	case 8231ULL: goto x86_l_2027;
	case 8233ULL: goto x86_l_2029;
	case 8239ULL: goto x86_l_202f;
	case 8244ULL: goto x86_l_2034;
	case 8248ULL: goto x86_l_2038;
	case 8252ULL: goto x86_l_203c;
	case 8256ULL: goto x86_l_2040;
	case 8260ULL: goto x86_l_2044;
	case 8264ULL: goto x86_l_2048;
	case 8268ULL: goto x86_l_204c;
	case 8272ULL: goto x86_l_2050;
	case 8276ULL: goto x86_l_2054;
	case 8279ULL: goto x86_l_2057;
	case 8282ULL: goto x86_l_205a;
	case 8284ULL: goto x86_l_205c;
	case 8287ULL: goto x86_l_205f;
	case 8289ULL: goto x86_l_2061;
	case 8293ULL: goto x86_l_2065;
	case 8297ULL: goto x86_l_2069;
	case 8300ULL: goto x86_l_206c;
	case 8304ULL: goto x86_l_2070;
	case 8310ULL: goto x86_l_2076;
	case 8320ULL: goto x86_l_2080;
	case 8325ULL: goto x86_l_2085;
	case 8335ULL: goto x86_l_208f;
	case 8340ULL: goto x86_l_2094;
	case 8350ULL: goto x86_l_209e;
	case 8355ULL: goto x86_l_20a3;
	case 8360ULL: goto x86_l_20a8;
	case 8365ULL: goto x86_l_20ad;
	case 8371ULL: goto x86_l_20b3;
	case 8376ULL: goto x86_l_20b8;
	case 8381ULL: goto x86_l_20bd;
	case 8384ULL: goto x86_l_20c0;
	case 8386ULL: goto x86_l_20c2;
	case 8389ULL: goto x86_l_20c5;
	case 8395ULL: goto x86_l_20cb;
	case 8399ULL: goto x86_l_20cf;
	case 8405ULL: goto x86_l_20d5;
	case 8408ULL: goto x86_l_20d8;
	case 8414ULL: goto x86_l_20de;
	case 8418ULL: goto x86_l_20e2;
	case 8423ULL: goto x86_l_20e7;
	case 8431ULL: goto x86_l_20ef;
	case 8439ULL: goto x86_l_20f7;
	case 8447ULL: goto x86_l_20ff;
	case 8458ULL: goto x86_l_210a;
	case 8469ULL: goto x86_l_2115;
	case 8477ULL: goto x86_l_211d;
	case 8484ULL: goto x86_l_2124;
	case 8489ULL: goto x86_l_2129;
	case 8494ULL: goto x86_l_212e;
	case 8496ULL: goto x86_l_2130;
	case 8499ULL: goto x86_l_2133;
	case 8501ULL: goto x86_l_2135;
	case 8504ULL: goto x86_l_2138;
	case 8506ULL: goto x86_l_213a;
	case 8512ULL: goto x86_l_2140;
	case 8514ULL: goto x86_l_2142;
	case 8518ULL: goto x86_l_2146;
	case 8524ULL: goto x86_l_214c;
	case 8526ULL: goto x86_l_214e;
	case 8532ULL: goto x86_l_2154;
	case 8535ULL: goto x86_l_2157;
	case 8541ULL: goto x86_l_215d;
	case 8547ULL: goto x86_l_2163;
	case 8551ULL: goto x86_l_2167;
	case 8555ULL: goto x86_l_216b;
	case 8561ULL: goto x86_l_2171;
	case 8565ULL: goto x86_l_2175;
	case 8569ULL: goto x86_l_2179;
	case 8575ULL: goto x86_l_217f;
	case 8579ULL: goto x86_l_2183;
	case 8583ULL: goto x86_l_2187;
	case 8589ULL: goto x86_l_218d;
	case 8593ULL: goto x86_l_2191;
	case 8597ULL: goto x86_l_2195;
	case 8603ULL: goto x86_l_219b;
	case 8608ULL: goto x86_l_21a0;
	case 8613ULL: goto x86_l_21a5;
	case 8618ULL: goto x86_l_21aa;
	case 8623ULL: goto x86_l_21af;
	case 8628ULL: goto x86_l_21b4;
	case 8630ULL: goto x86_l_21b6;
	case 8633ULL: goto x86_l_21b9;
	case 8639ULL: goto x86_l_21bf;
	case 8643ULL: goto x86_l_21c3;
	case 8647ULL: goto x86_l_21c7;
	case 8652ULL: goto x86_l_21cc;
	case 8656ULL: goto x86_l_21d0;
	case 8661ULL: goto x86_l_21d5;
	case 8665ULL: goto x86_l_21d9;
	case 8669ULL: goto x86_l_21dd;
	case 8673ULL: goto x86_l_21e1;
	case 8676ULL: goto x86_l_21e4;
	case 8678ULL: goto x86_l_21e6;
	case 8683ULL: goto x86_l_21eb;
	case 8689ULL: goto x86_l_21f1;
	case 8693ULL: goto x86_l_21f5;
	case 8697ULL: goto x86_l_21f9;
	case 8701ULL: goto x86_l_21fd;
	case 8703ULL: goto x86_l_21ff;
	case 8708ULL: goto x86_l_2204;
	case 8712ULL: goto x86_l_2208;
	case 8716ULL: goto x86_l_220c;
	case 8720ULL: goto x86_l_2210;
	case 8725ULL: goto x86_l_2215;
	case 8728ULL: goto x86_l_2218;
	case 8735ULL: goto x86_l_221f;
	case 8737ULL: goto x86_l_2221;
	case 8744ULL: goto x86_l_2228;
	case 8750ULL: goto x86_l_222e;
	case 8754ULL: goto x86_l_2232;
	case 8758ULL: goto x86_l_2236;
	case 8762ULL: goto x86_l_223a;
	case 8765ULL: goto x86_l_223d;
	case 8768ULL: goto x86_l_2240;
	case 8770ULL: goto x86_l_2242;
	case 8775ULL: goto x86_l_2247;
	case 8779ULL: goto x86_l_224b;
	case 8781ULL: goto x86_l_224d;
	case 8787ULL: goto x86_l_2253;
	case 8793ULL: goto x86_l_2259;
	case 8797ULL: goto x86_l_225d;
	case 8801ULL: goto x86_l_2261;
	case 8807ULL: goto x86_l_2267;
	case 8811ULL: goto x86_l_226b;
	case 8815ULL: goto x86_l_226f;
	case 8821ULL: goto x86_l_2275;
	case 8825ULL: goto x86_l_2279;
	case 8829ULL: goto x86_l_227d;
	case 8835ULL: goto x86_l_2283;
	case 8839ULL: goto x86_l_2287;
	case 8843ULL: goto x86_l_228b;
	case 8849ULL: goto x86_l_2291;
	case 8854ULL: goto x86_l_2296;
	case 8859ULL: goto x86_l_229b;
	case 8864ULL: goto x86_l_22a0;
	case 8867ULL: goto x86_l_22a3;
	case 8872ULL: goto x86_l_22a8;
	case 8874ULL: goto x86_l_22aa;
	case 8877ULL: goto x86_l_22ad;
	case 8883ULL: goto x86_l_22b3;
	case 8887ULL: goto x86_l_22b7;
	case 8891ULL: goto x86_l_22bb;
	case 8895ULL: goto x86_l_22bf;
	case 8899ULL: goto x86_l_22c3;
	case 8903ULL: goto x86_l_22c7;
	case 8907ULL: goto x86_l_22cb;
	case 8911ULL: goto x86_l_22cf;
	case 8915ULL: goto x86_l_22d3;
	case 8918ULL: goto x86_l_22d6;
	case 8921ULL: goto x86_l_22d9;
	case 8923ULL: goto x86_l_22db;
	case 8926ULL: goto x86_l_22de;
	case 8928ULL: goto x86_l_22e0;
	case 8932ULL: goto x86_l_22e4;
	case 8936ULL: goto x86_l_22e8;
	case 8939ULL: goto x86_l_22eb;
	case 8944ULL: goto x86_l_22f0;
	case 8948ULL: goto x86_l_22f4;
	case 8954ULL: goto x86_l_22fa;
	case 8962ULL: goto x86_l_2302;
	case 8969ULL: goto x86_l_2309;
	case 8974ULL: goto x86_l_230e;
	case 8979ULL: goto x86_l_2313;
	case 8981ULL: goto x86_l_2315;
	case 8984ULL: goto x86_l_2318;
	case 8990ULL: goto x86_l_231e;
	case 8993ULL: goto x86_l_2321;
	case 8998ULL: goto x86_l_2326;
	case 9008ULL: goto x86_l_2330;
	case 9013ULL: goto x86_l_2335;
	case 9023ULL: goto x86_l_233f;
	case 9028ULL: goto x86_l_2344;
	case 9038ULL: goto x86_l_234e;
	case 9043ULL: goto x86_l_2353;
	case 9053ULL: goto x86_l_235d;
	case 9058ULL: goto x86_l_2362;
	case 9068ULL: goto x86_l_236c;
	case 9073ULL: goto x86_l_2371;
	case 9083ULL: goto x86_l_237b;
	case 9088ULL: goto x86_l_2380;
	case 9093ULL: goto x86_l_2385;
	case 9098ULL: goto x86_l_238a;
	case 9104ULL: goto x86_l_2390;
	case 9108ULL: goto x86_l_2394;
	case 9112ULL: goto x86_l_2398;
	case 9115ULL: goto x86_l_239b;
	case 9120ULL: goto x86_l_23a0;
	case 9123ULL: goto x86_l_23a3;
	case 9125ULL: goto x86_l_23a5;
	case 9128ULL: goto x86_l_23a8;
	case 9133ULL: goto x86_l_23ad;
	case 9137ULL: goto x86_l_23b1;
	case 9143ULL: goto x86_l_23b7;
	case 9150ULL: goto x86_l_23be;
	case 9152ULL: goto x86_l_23c0;
	case 9157ULL: goto x86_l_23c5;
	case 9161ULL: goto x86_l_23c9;
	case 9167ULL: goto x86_l_23cf;
	case 9173ULL: goto x86_l_23d5;
	case 9177ULL: goto x86_l_23d9;
	case 9183ULL: goto x86_l_23df;
	case 9186ULL: goto x86_l_23e2;
	case 9192ULL: goto x86_l_23e8;
	case 9196ULL: goto x86_l_23ec;
	case 9201ULL: goto x86_l_23f1;
	case 9209ULL: goto x86_l_23f9;
	case 9217ULL: goto x86_l_2401;
	case 9225ULL: goto x86_l_2409;
	case 9236ULL: goto x86_l_2414;
	case 9247ULL: goto x86_l_241f;
	case 9255ULL: goto x86_l_2427;
	case 9262ULL: goto x86_l_242e;
	case 9267ULL: goto x86_l_2433;
	case 9272ULL: goto x86_l_2438;
	case 9274ULL: goto x86_l_243a;
	case 9277ULL: goto x86_l_243d;
	case 9283ULL: goto x86_l_2443;
	case 9286ULL: goto x86_l_2446;
	case 9288ULL: goto x86_l_2448;
	case 9294ULL: goto x86_l_244e;
	case 9299ULL: goto x86_l_2453;
	case 9309ULL: goto x86_l_245d;
	case 9314ULL: goto x86_l_2462;
	case 9324ULL: goto x86_l_246c;
	case 9329ULL: goto x86_l_2471;
	case 9339ULL: goto x86_l_247b;
	case 9344ULL: goto x86_l_2480;
	case 9354ULL: goto x86_l_248a;
	case 9359ULL: goto x86_l_248f;
	case 9369ULL: goto x86_l_2499;
	case 9374ULL: goto x86_l_249e;
	case 9384ULL: goto x86_l_24a8;
	case 9389ULL: goto x86_l_24ad;
	case 9394ULL: goto x86_l_24b2;
	case 9399ULL: goto x86_l_24b7;
	case 9404ULL: goto x86_l_24bc;
	case 9408ULL: goto x86_l_24c0;
	case 9413ULL: goto x86_l_24c5;
	case 9415ULL: goto x86_l_24c7;
	case 9417ULL: goto x86_l_24c9;
	case 9422ULL: goto x86_l_24ce;
	case 9426ULL: goto x86_l_24d2;
	case 9432ULL: goto x86_l_24d8;
	case 9434ULL: goto x86_l_24da;
	case 9440ULL: goto x86_l_24e0;
	case 9443ULL: goto x86_l_24e3;
	case 9446ULL: goto x86_l_24e6;
	case 9452ULL: goto x86_l_24ec;
	case 9456ULL: goto x86_l_24f0;
	case 9460ULL: goto x86_l_24f4;
	case 9466ULL: goto x86_l_24fa;
	case 9470ULL: goto x86_l_24fe;
	case 9474ULL: goto x86_l_2502;
	case 9480ULL: goto x86_l_2508;
	case 9484ULL: goto x86_l_250c;
	case 9488ULL: goto x86_l_2510;
	case 9494ULL: goto x86_l_2516;
	case 9498ULL: goto x86_l_251a;
	case 9502ULL: goto x86_l_251e;
	case 9508ULL: goto x86_l_2524;
	case 9513ULL: goto x86_l_2529;
	case 9518ULL: goto x86_l_252e;
	case 9523ULL: goto x86_l_2533;
	case 9528ULL: goto x86_l_2538;
	case 9531ULL: goto x86_l_253b;
	case 9533ULL: goto x86_l_253d;
	case 9536ULL: goto x86_l_2540;
	case 9542ULL: goto x86_l_2546;
	case 9546ULL: goto x86_l_254a;
	case 9550ULL: goto x86_l_254e;
	case 9555ULL: goto x86_l_2553;
	case 9559ULL: goto x86_l_2557;
	case 9564ULL: goto x86_l_255c;
	case 9568ULL: goto x86_l_2560;
	case 9572ULL: goto x86_l_2564;
	case 9577ULL: goto x86_l_2569;
	case 9581ULL: goto x86_l_256d;
	case 9584ULL: goto x86_l_2570;
	case 9586ULL: goto x86_l_2572;
	case 9591ULL: goto x86_l_2577;
	case 9597ULL: goto x86_l_257d;
	case 9601ULL: goto x86_l_2581;
	case 9605ULL: goto x86_l_2585;
	case 9609ULL: goto x86_l_2589;
	case 9615ULL: goto x86_l_258f;
	case 9620ULL: goto x86_l_2594;
	case 9624ULL: goto x86_l_2598;
	case 9628ULL: goto x86_l_259c;
	case 9632ULL: goto x86_l_25a0;
	case 9637ULL: goto x86_l_25a5;
	case 9640ULL: goto x86_l_25a8;
	case 9647ULL: goto x86_l_25af;
	case 9649ULL: goto x86_l_25b1;
	case 9656ULL: goto x86_l_25b8;
	case 9662ULL: goto x86_l_25be;
	case 9666ULL: goto x86_l_25c2;
	case 9670ULL: goto x86_l_25c6;
	case 9674ULL: goto x86_l_25ca;
	case 9677ULL: goto x86_l_25cd;
	case 9680ULL: goto x86_l_25d0;
	case 9685ULL: goto x86_l_25d5;
	case 9695ULL: goto x86_l_25df;
	case 9700ULL: goto x86_l_25e4;
	case 9710ULL: goto x86_l_25ee;
	case 9715ULL: goto x86_l_25f3;
	case 9725ULL: goto x86_l_25fd;
	case 9730ULL: goto x86_l_2602;
	case 9740ULL: goto x86_l_260c;
	case 9745ULL: goto x86_l_2611;
	case 9755ULL: goto x86_l_261b;
	case 9760ULL: goto x86_l_2620;
	case 9770ULL: goto x86_l_262a;
	case 9775ULL: goto x86_l_262f;
	case 9780ULL: goto x86_l_2634;
	case 9785ULL: goto x86_l_2639;
	case 9790ULL: goto x86_l_263e;
	case 9794ULL: goto x86_l_2642;
	case 9799ULL: goto x86_l_2647;
	case 9801ULL: goto x86_l_2649;
	case 9803ULL: goto x86_l_264b;
	case 9805ULL: goto x86_l_264d;
	case 9811ULL: goto x86_l_2653;
	case 9816ULL: goto x86_l_2658;
	case 9821ULL: goto x86_l_265d;
	case 9825ULL: goto x86_l_2661;
	case 9827ULL: goto x86_l_2663;
	case 9833ULL: goto x86_l_2669;
	case 9839ULL: goto x86_l_266f;
	case 9843ULL: goto x86_l_2673;
	case 9847ULL: goto x86_l_2677;
	case 9853ULL: goto x86_l_267d;
	case 9857ULL: goto x86_l_2681;
	case 9861ULL: goto x86_l_2685;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1f08:
	/* 0x1f08: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f0d:
	/* 0x1f0d: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f11:
	/* 0x1f11: jne    2076 <perf_unwind_python+0x2076> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2076;
	}
x86_l_1f17:
	/* 0x1f17: mov    eax,DWORD PTR [rbp+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_1f1d:
	/* 0x1f1d: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_1f21:
	/* 0x1f21: jbe    20d5 <perf_unwind_python+0x20d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_20d5;
	}
x86_l_1f27:
	/* 0x1f27: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f2c:
	/* 0x1f2c: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f31:
	/* 0x1f31: jmp    358 <perf_unwind_python+0x358> */
	return 856ULL;
x86_l_1f36:
	/* 0x1f36: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1f40:
	/* 0x1f40: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1f45:
	/* 0x1f45: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1f4f:
	/* 0x1f4f: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f54:
	/* 0x1f54: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1f5e:
	/* 0x1f5e: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1f63:
	/* 0x1f63: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1f6d:
	/* 0x1f6d: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f72:
	/* 0x1f72: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1f7c:
	/* 0x1f7c: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f81:
	/* 0x1f81: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1f8b:
	/* 0x1f8b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f90:
	/* 0x1f90: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f95:
	/* 0x1f95: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1f9a:
	/* 0x1f9a: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1f9f:
	/* 0x1f9f: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fa3:
	/* 0x1fa3: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1fa8:
	/* 0x1fa8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1faa:
	/* 0x1faa: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1fac:
	/* 0x1fac: jmp    1745 <perf_unwind_python+0x1745> */
	return 5957ULL;
x86_l_1fb1:
	/* 0x1fb1: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1fbb:
	/* 0x1fbb: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1fc0:
	/* 0x1fc0: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1fca:
	/* 0x1fca: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1fcf:
	/* 0x1fcf: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1fd9:
	/* 0x1fd9: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1fde:
	/* 0x1fde: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1fe8:
	/* 0x1fe8: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1fed:
	/* 0x1fed: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1ff7:
	/* 0x1ff7: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ffc:
	/* 0x1ffc: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2006:
	/* 0x2006: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_200b:
	/* 0x200b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2010:
	/* 0x2010: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2015:
	/* 0x2015: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_201a:
	/* 0x201a: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_201e:
	/* 0x201e: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2023:
	/* 0x2023: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2025:
	/* 0x2025: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2027:
	/* 0x2027: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
x86_l_2029:
	/* 0x2029: jne    1242 <perf_unwind_python+0x1242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4674ULL;
	}
x86_l_202f:
	/* 0x202f: jmp    1cbb <perf_unwind_python+0x1cbb> */
	return 7355ULL;
x86_l_2034:
	/* 0x2034: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2038:
	/* 0x2038: movzx  ecx,BYTE PTR [rax+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_203c:
	/* 0x203c: mov    ecx,DWORD PTR [r15+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2040:
	/* 0x2040: movzx  edx,BYTE PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_2044:
	/* 0x2044: mov    edx,DWORD PTR [r15+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_2048:
	/* 0x2048: movzx  esi,BYTE PTR [rax+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_204c:
	/* 0x204c: mov    esi,DWORD PTR [r15+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_2050:
	/* 0x2050: movzx  eax,BYTE PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_2054:
	/* 0x2054: shl    ecx,0x19 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 25ULL);
x86_l_2057:
	/* 0x2057: shl    edx,0x12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 18ULL);
x86_l_205a:
	/* 0x205a: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_205c:
	/* 0x205c: shl    esi,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 10ULL);
x86_l_205f:
	/* 0x205f: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2061:
	/* 0x2061: add    esi,DWORD PTR [r15+rax*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R15, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2065:
	/* 0x2065: shl    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_2069:
	/* 0x2069: or     r12,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RSI, X86_WIDTH_64, X86_ALU_OR);
x86_l_206c:
	/* 0x206c: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2070:
	/* 0x2070: je     1f17 <perf_unwind_python+0x1f17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f17;
	}
x86_l_2076:
	/* 0x2076: movabs rax,0xa756c2520786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2943857106909292ULL);
x86_l_2080:
	/* 0x2080: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2085:
	/* 0x2085: movabs rax,0x25206e6f68747950 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675259603430963536ULL);
x86_l_208f:
	/* 0x208f: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2094:
	/* 0x2094: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_209e:
	/* 0x209e: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20a3:
	/* 0x20a3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20a8:
	/* 0x20a8: mov    eax,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_20ad:
	/* 0x20ad: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_20b3:
	/* 0x20b3: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_20b8:
	/* 0x20b8: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20bd:
	/* 0x20bd: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_20c0:
	/* 0x20c0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20c2:
	/* 0x20c2: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_20c5:
	/* 0x20c5: mov    eax,DWORD PTR [rbp+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_20cb:
	/* 0x20cb: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_20cf:
	/* 0x20cf: ja     1f27 <perf_unwind_python+0x1f27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f27;
	}
x86_l_20d5:
	/* 0x20d5: lea    ecx,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_20d8:
	/* 0x20d8: mov    DWORD PTR [rbp+0x2c0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_20de:
	/* 0x20de: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_20e2:
	/* 0x20e2: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20e7:
	/* 0x20e7: mov    QWORD PTR [rbp+rax*8+0x2d0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_20ef:
	/* 0x20ef: mov    QWORD PTR [rbp+rax*8+0x2d8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_20f7:
	/* 0x20f7: mov    BYTE PTR [rbp+rax*8+0x2e0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929857ULL);
x86_l_20ff:
	/* 0x20ff: mov    DWORD PTR [rbp+rax*8+0x2e1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3165390897152ULL);
x86_l_210a:
	/* 0x210a: mov    DWORD PTR [rbp+rax*8+0x2e4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3178275799040ULL);
x86_l_2115:
	/* 0x2115: mov    DWORD PTR [rsp+0x18],0x16 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215126ULL);
x86_l_211d:
	/* 0x211d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_2124:
	/* 0x2124: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2129:
	/* 0x2129: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_212e:
	/* 0x212e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2130:
	/* 0x2130: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2133:
	/* 0x2133: je     2142 <perf_unwind_python+0x2142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2142;
	}
x86_l_2135:
	/* 0x2135: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2138:
	/* 0x2138: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
x86_l_213a:
	/* 0x213a: jne    1d5a <perf_unwind_python+0x1d5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7514ULL;
	}
x86_l_2140:
	/* 0x2140: jmp    2154 <perf_unwind_python+0x2154> */
	goto x86_l_2154;
x86_l_2142:
	/* 0x2142: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2146:
	/* 0x2146: jne    25d5 <perf_unwind_python+0x25d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25d5;
	}
x86_l_214c:
	/* 0x214c: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
x86_l_214e:
	/* 0x214e: jne    1d5a <perf_unwind_python+0x1d5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7514ULL;
	}
x86_l_2154:
	/* 0x2154: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2157:
	/* 0x2157: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_215d:
	/* 0x215d: je     45b4 <perf_unwind_python+0x45b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17844ULL;
	}
x86_l_2163:
	/* 0x2163: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2167:
	/* 0x2167: cmp    BYTE PTR [rax+0x19],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 107374182520ULL);
x86_l_216b:
	/* 0x216b: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_2171:
	/* 0x2171: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2175:
	/* 0x2175: cmp    BYTE PTR [rax+0x18],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215224ULL);
x86_l_2179:
	/* 0x2179: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_217f:
	/* 0x217f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2183:
	/* 0x2183: cmp    BYTE PTR [rax+0x1a],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 111669149816ULL);
x86_l_2187:
	/* 0x2187: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_218d:
	/* 0x218d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2191:
	/* 0x2191: cmp    BYTE PTR [rax+0x1b],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 115964116992ULL);
x86_l_2195:
	/* 0x2195: js     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 17816ULL;
	}
x86_l_219b:
	/* 0x219b: mov    eax,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 128ULL);
x86_l_21a0:
	/* 0x21a0: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_21a5:
	/* 0x21a5: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_21aa:
	/* 0x21aa: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21af:
	/* 0x21af: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_21b4:
	/* 0x21b4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_21b6:
	/* 0x21b6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21b9:
	/* 0x21b9: jne    d56 <perf_unwind_python+0xd56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3414ULL;
	}
x86_l_21bf:
	/* 0x21bf: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21c3:
	/* 0x21c3: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_21c7:
	/* 0x21c7: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_21cc:
	/* 0x21cc: mov    rcx,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_21d0:
	/* 0x21d0: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21d5:
	/* 0x21d5: movzx  ecx,BYTE PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_21d9:
	/* 0x21d9: mov    r13,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_21dd:
	/* 0x21dd: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21e1:
	/* 0x21e1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21e4:
	/* 0x21e4: je     21f1 <perf_unwind_python+0x21f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21f1;
	}
x86_l_21e6:
	/* 0x21e6: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21eb:
	/* 0x21eb: je     1242 <perf_unwind_python+0x1242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4674ULL;
	}
x86_l_21f1:
	/* 0x21f1: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21f5:
	/* 0x21f5: cmp    BYTE PTR [rax+0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_21f9:
	/* 0x21f9: movzx  eax,BYTE PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 26ULL);
x86_l_21fd:
	/* 0x21fd: je     2242 <perf_unwind_python+0x2242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2242;
	}
x86_l_21ff:
	/* 0x21ff: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2204:
	/* 0x2204: mov    rax,QWORD PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2208:
	/* 0x2208: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_220c:
	/* 0x220c: movzx  edx,BYTE PTR [rcx+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_2210:
	/* 0x2210: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_2215:
	/* 0x2215: sub    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2218:
	/* 0x2218: lea    rdx,[rax-0x10000001] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073441116159ULL);
x86_l_221f:
	/* 0x221f: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_2221:
	/* 0x2221: cmp    rdx,0xffffffffeffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073441116157ULL);
x86_l_2228:
	/* 0x2228: mov    r12d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_222e:
	/* 0x222e: cmovae r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_2232:
	/* 0x2232: movzx  eax,BYTE PTR [rcx+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_2236:
	/* 0x2236: movzx  eax,BYTE PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_223a:
	/* 0x223a: cmp    al,BYTE PTR [rcx+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_223d:
	/* 0x223d: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_2240:
	/* 0x2240: jmp    224d <perf_unwind_python+0x224d> */
	goto x86_l_224d;
x86_l_2242:
	/* 0x2242: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2247:
	/* 0x2247: mov    r12d,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_224b:
	/* 0x224b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_224d:
	/* 0x224d: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2253:
	/* 0x2253: je     22f0 <perf_unwind_python+0x22f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22f0;
	}
x86_l_2259:
	/* 0x2259: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_225d:
	/* 0x225d: cmp    BYTE PTR [rax+0x1d],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051772ULL);
x86_l_2261:
	/* 0x2261: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_2267:
	/* 0x2267: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_226b:
	/* 0x226b: cmp    BYTE PTR [rax+0x1e],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128849019068ULL);
x86_l_226f:
	/* 0x226f: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_2275:
	/* 0x2275: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2279:
	/* 0x2279: cmp    BYTE PTR [rax+0x1f],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133143986364ULL);
x86_l_227d:
	/* 0x227d: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_2283:
	/* 0x2283: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2287:
	/* 0x2287: cmp    BYTE PTR [rax+0x20],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953660ULL);
x86_l_228b:
	/* 0x228b: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_2291:
	/* 0x2291: mov    eax,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 192ULL);
x86_l_2296:
	/* 0x2296: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_229b:
	/* 0x229b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22a0:
	/* 0x22a0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_22a3:
	/* 0x22a3: mov    esi,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 192ULL);
x86_l_22a8:
	/* 0x22a8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_22aa:
	/* 0x22aa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22ad:
	/* 0x22ad: jne    2b5 <perf_unwind_python+0x2b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 693ULL;
	}
x86_l_22b3:
	/* 0x22b3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22b7:
	/* 0x22b7: movzx  ecx,BYTE PTR [rax+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_22bb:
	/* 0x22bb: mov    ecx,DWORD PTR [r15+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_22bf:
	/* 0x22bf: movzx  edx,BYTE PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_22c3:
	/* 0x22c3: mov    edx,DWORD PTR [r15+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_22c7:
	/* 0x22c7: movzx  esi,BYTE PTR [rax+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_22cb:
	/* 0x22cb: mov    esi,DWORD PTR [r15+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_22cf:
	/* 0x22cf: movzx  eax,BYTE PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_22d3:
	/* 0x22d3: shl    ecx,0x19 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 25ULL);
x86_l_22d6:
	/* 0x22d6: shl    edx,0x12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 18ULL);
x86_l_22d9:
	/* 0x22d9: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_22db:
	/* 0x22db: shl    esi,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 10ULL);
x86_l_22de:
	/* 0x22de: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_22e0:
	/* 0x22e0: add    esi,DWORD PTR [r15+rax*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R15, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_22e4:
	/* 0x22e4: shl    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_22e8:
	/* 0x22e8: or     r12,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RSI, X86_WIDTH_64, X86_ALU_OR);
x86_l_22eb:
	/* 0x22eb: jmp    23c5 <perf_unwind_python+0x23c5> */
	goto x86_l_23c5;
x86_l_22f0:
	/* 0x22f0: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22f4:
	/* 0x22f4: jne    27be <perf_unwind_python+0x27be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10174ULL;
	}
x86_l_22fa:
	/* 0x22fa: mov    DWORD PTR [rsp+0x18],0x1c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215132ULL);
x86_l_2302:
	/* 0x2302: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_2309:
	/* 0x2309: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_230e:
	/* 0x230e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2313:
	/* 0x2313: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2315:
	/* 0x2315: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2318:
	/* 0x2318: je     23ad <perf_unwind_python+0x23ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23ad;
	}
x86_l_231e:
	/* 0x231e: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2321:
	/* 0x2321: jmp    23b7 <perf_unwind_python+0x23b7> */
	goto x86_l_23b7;
x86_l_2326:
	/* 0x2326: movabs rax,0xa786c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541280ULL);
x86_l_2330:
	/* 0x2330: mov    QWORD PTR [rsp+0x57],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_2335:
	/* 0x2335: movabs rax,0x20786c2578302074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2339738914604982388ULL);
x86_l_233f:
	/* 0x233f: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2344:
	/* 0x2344: movabs rax,0x63656a624f656d61 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7162247752874028385ULL);
x86_l_234e:
	/* 0x234e: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2353:
	/* 0x2353: movabs rax,0x7246795020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8234402353742245734ULL);
x86_l_235d:
	/* 0x235d: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2362:
	/* 0x2362: movabs rax,0x207463656a626f65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338603393739812709ULL);
x86_l_236c:
	/* 0x236c: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2371:
	/* 0x2371: movabs rax,0x646f63206c6c754e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7237112117116826958ULL);
x86_l_237b:
	/* 0x237b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2380:
	/* 0x2380: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2385:
	/* 0x2385: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_238a:
	/* 0x238a: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_2390:
	/* 0x2390: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2394:
	/* 0x2394: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_2398:
	/* 0x2398: add    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_239b:
	/* 0x239b: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_23a0:
	/* 0x23a0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_23a3:
	/* 0x23a3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23a5:
	/* 0x23a5: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_23a8:
	/* 0x23a8: jmp    1e40 <perf_unwind_python+0x1e40> */
	return 7744ULL;
x86_l_23ad:
	/* 0x23ad: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23b1:
	/* 0x23b1: jne    28ab <perf_unwind_python+0x28ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10411ULL;
	}
x86_l_23b7:
	/* 0x23b7: mov    r12,0xfffffffffffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_23be:
	/* 0x23be: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23c0:
	/* 0x23c0: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_23c5:
	/* 0x23c5: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23c9:
	/* 0x23c9: jne    2847 <perf_unwind_python+0x2847> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10311ULL;
	}
x86_l_23cf:
	/* 0x23cf: mov    eax,DWORD PTR [rbp+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_23d5:
	/* 0x23d5: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_23d9:
	/* 0x23d9: ja     176d <perf_unwind_python+0x176d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5997ULL;
	}
x86_l_23df:
	/* 0x23df: lea    ecx,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_23e2:
	/* 0x23e2: mov    DWORD PTR [rbp+0x2c0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_23e8:
	/* 0x23e8: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_23ec:
	/* 0x23ec: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_23f1:
	/* 0x23f1: mov    QWORD PTR [rbp+rax*8+0x2d0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_23f9:
	/* 0x23f9: mov    QWORD PTR [rbp+rax*8+0x2d8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_2401:
	/* 0x2401: mov    BYTE PTR [rbp+rax*8+0x2e0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929857ULL);
x86_l_2409:
	/* 0x2409: mov    DWORD PTR [rbp+rax*8+0x2e1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3165390897152ULL);
x86_l_2414:
	/* 0x2414: mov    DWORD PTR [rbp+rax*8+0x2e4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3178275799040ULL);
x86_l_241f:
	/* 0x241f: mov    DWORD PTR [rsp+0x18],0x16 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215126ULL);
x86_l_2427:
	/* 0x2427: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_242e:
	/* 0x242e: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2433:
	/* 0x2433: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2438:
	/* 0x2438: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_243a:
	/* 0x243a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_243d:
	/* 0x243d: je     24ce <perf_unwind_python+0x24ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24ce;
	}
x86_l_2443:
	/* 0x2443: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2446:
	/* 0x2446: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
x86_l_2448:
	/* 0x2448: jne    1242 <perf_unwind_python+0x1242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4674ULL;
	}
x86_l_244e:
	/* 0x244e: jmp    24e0 <perf_unwind_python+0x24e0> */
	goto x86_l_24e0;
x86_l_2453:
	/* 0x2453: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_245d:
	/* 0x245d: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2462:
	/* 0x2462: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_246c:
	/* 0x246c: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2471:
	/* 0x2471: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_247b:
	/* 0x247b: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2480:
	/* 0x2480: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_248a:
	/* 0x248a: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_248f:
	/* 0x248f: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2499:
	/* 0x2499: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_249e:
	/* 0x249e: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_24a8:
	/* 0x24a8: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24ad:
	/* 0x24ad: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24b2:
	/* 0x24b2: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_24b7:
	/* 0x24b7: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_24bc:
	/* 0x24bc: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24c0:
	/* 0x24c0: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_24c5:
	/* 0x24c5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24c7:
	/* 0x24c7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_24c9:
	/* 0x24c9: jmp    1eff <perf_unwind_python+0x1eff> */
	return 7935ULL;
x86_l_24ce:
	/* 0x24ce: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24d2:
	/* 0x24d2: jne    2926 <perf_unwind_python+0x2926> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10534ULL;
	}
x86_l_24d8:
	/* 0x24d8: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
x86_l_24da:
	/* 0x24da: jne    1242 <perf_unwind_python+0x1242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4674ULL;
	}
x86_l_24e0:
	/* 0x24e0: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24e3:
	/* 0x24e3: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_24e6:
	/* 0x24e6: je     45b4 <perf_unwind_python+0x45b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17844ULL;
	}
x86_l_24ec:
	/* 0x24ec: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24f0:
	/* 0x24f0: cmp    BYTE PTR [rax+0x19],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 107374182520ULL);
x86_l_24f4:
	/* 0x24f4: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_24fa:
	/* 0x24fa: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24fe:
	/* 0x24fe: cmp    BYTE PTR [rax+0x18],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215224ULL);
x86_l_2502:
	/* 0x2502: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_2508:
	/* 0x2508: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_250c:
	/* 0x250c: cmp    BYTE PTR [rax+0x1a],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 111669149816ULL);
x86_l_2510:
	/* 0x2510: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_2516:
	/* 0x2516: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_251a:
	/* 0x251a: cmp    BYTE PTR [rax+0x1b],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 115964116992ULL);
x86_l_251e:
	/* 0x251e: js     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 17920ULL;
	}
x86_l_2524:
	/* 0x2524: mov    eax,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 128ULL);
x86_l_2529:
	/* 0x2529: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_252e:
	/* 0x252e: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2533:
	/* 0x2533: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_2538:
	/* 0x2538: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_253b:
	/* 0x253b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_253d:
	/* 0x253d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2540:
	/* 0x2540: jne    1d1d <perf_unwind_python+0x1d1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7453ULL;
	}
x86_l_2546:
	/* 0x2546: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_254a:
	/* 0x254a: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_254e:
	/* 0x254e: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2553:
	/* 0x2553: mov    rcx,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2557:
	/* 0x2557: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_255c:
	/* 0x255c: movzx  ecx,BYTE PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_2560:
	/* 0x2560: mov    rcx,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2564:
	/* 0x2564: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2569:
	/* 0x2569: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_256d:
	/* 0x256d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2570:
	/* 0x2570: je     257d <perf_unwind_python+0x257d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_257d;
	}
x86_l_2572:
	/* 0x2572: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2577:
	/* 0x2577: je     1d5a <perf_unwind_python+0x1d5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7514ULL;
	}
x86_l_257d:
	/* 0x257d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2581:
	/* 0x2581: cmp    BYTE PTR [rax+0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_2585:
	/* 0x2585: movzx  eax,BYTE PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 26ULL);
x86_l_2589:
	/* 0x2589: je     2658 <perf_unwind_python+0x2658> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2658;
	}
x86_l_258f:
	/* 0x258f: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2594:
	/* 0x2594: mov    rax,QWORD PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2598:
	/* 0x2598: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_259c:
	/* 0x259c: movzx  edx,BYTE PTR [rcx+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_25a0:
	/* 0x25a0: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_25a5:
	/* 0x25a5: sub    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_25a8:
	/* 0x25a8: lea    rdx,[rax-0x10000001] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073441116159ULL);
x86_l_25af:
	/* 0x25af: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_25b1:
	/* 0x25b1: cmp    rdx,0xffffffffeffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073441116157ULL);
x86_l_25b8:
	/* 0x25b8: mov    r12d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_25be:
	/* 0x25be: cmovae r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_25c2:
	/* 0x25c2: movzx  eax,BYTE PTR [rcx+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_25c6:
	/* 0x25c6: movzx  eax,BYTE PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_25ca:
	/* 0x25ca: cmp    al,BYTE PTR [rcx+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_25cd:
	/* 0x25cd: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_25d0:
	/* 0x25d0: jmp    2663 <perf_unwind_python+0x2663> */
	goto x86_l_2663;
x86_l_25d5:
	/* 0x25d5: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_25df:
	/* 0x25df: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_25e4:
	/* 0x25e4: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_25ee:
	/* 0x25ee: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_25f3:
	/* 0x25f3: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_25fd:
	/* 0x25fd: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2602:
	/* 0x2602: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_260c:
	/* 0x260c: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2611:
	/* 0x2611: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_261b:
	/* 0x261b: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2620:
	/* 0x2620: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_262a:
	/* 0x262a: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_262f:
	/* 0x262f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2634:
	/* 0x2634: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2639:
	/* 0x2639: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_263e:
	/* 0x263e: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2642:
	/* 0x2642: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2647:
	/* 0x2647: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2649:
	/* 0x2649: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_264b:
	/* 0x264b: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
x86_l_264d:
	/* 0x264d: jne    1d5a <perf_unwind_python+0x1d5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7514ULL;
	}
x86_l_2653:
	/* 0x2653: jmp    2154 <perf_unwind_python+0x2154> */
	goto x86_l_2154;
x86_l_2658:
	/* 0x2658: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_265d:
	/* 0x265d: mov    r12d,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2661:
	/* 0x2661: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2663:
	/* 0x2663: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2669:
	/* 0x2669: je     2706 <perf_unwind_python+0x2706> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9990ULL;
	}
x86_l_266f:
	/* 0x266f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2673:
	/* 0x2673: cmp    BYTE PTR [rax+0x1d],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051772ULL);
x86_l_2677:
	/* 0x2677: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_267d:
	/* 0x267d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2681:
	/* 0x2681: cmp    BYTE PTR [rax+0x1e],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128849019068ULL);
x86_l_2685:
	/* 0x2685: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
	return 9867ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9867ULL: goto x86_l_268b;
	case 9871ULL: goto x86_l_268f;
	case 9875ULL: goto x86_l_2693;
	case 9881ULL: goto x86_l_2699;
	case 9885ULL: goto x86_l_269d;
	case 9889ULL: goto x86_l_26a1;
	case 9895ULL: goto x86_l_26a7;
	case 9900ULL: goto x86_l_26ac;
	case 9905ULL: goto x86_l_26b1;
	case 9910ULL: goto x86_l_26b6;
	case 9913ULL: goto x86_l_26b9;
	case 9918ULL: goto x86_l_26be;
	case 9920ULL: goto x86_l_26c0;
	case 9923ULL: goto x86_l_26c3;
	case 9929ULL: goto x86_l_26c9;
	case 9933ULL: goto x86_l_26cd;
	case 9937ULL: goto x86_l_26d1;
	case 9941ULL: goto x86_l_26d5;
	case 9945ULL: goto x86_l_26d9;
	case 9949ULL: goto x86_l_26dd;
	case 9953ULL: goto x86_l_26e1;
	case 9957ULL: goto x86_l_26e5;
	case 9961ULL: goto x86_l_26e9;
	case 9964ULL: goto x86_l_26ec;
	case 9967ULL: goto x86_l_26ef;
	case 9969ULL: goto x86_l_26f1;
	case 9972ULL: goto x86_l_26f4;
	case 9974ULL: goto x86_l_26f6;
	case 9978ULL: goto x86_l_26fa;
	case 9982ULL: goto x86_l_26fe;
	case 9985ULL: goto x86_l_2701;
	case 9990ULL: goto x86_l_2706;
	case 9994ULL: goto x86_l_270a;
	case 10000ULL: goto x86_l_2710;
	case 10010ULL: goto x86_l_271a;
	case 10015ULL: goto x86_l_271f;
	case 10025ULL: goto x86_l_2729;
	case 10030ULL: goto x86_l_272e;
	case 10040ULL: goto x86_l_2738;
	case 10045ULL: goto x86_l_273d;
	case 10055ULL: goto x86_l_2747;
	case 10060ULL: goto x86_l_274c;
	case 10070ULL: goto x86_l_2756;
	case 10075ULL: goto x86_l_275b;
	case 10085ULL: goto x86_l_2765;
	case 10090ULL: goto x86_l_276a;
	case 10095ULL: goto x86_l_276f;
	case 10100ULL: goto x86_l_2774;
	case 10106ULL: goto x86_l_277a;
	case 10110ULL: goto x86_l_277e;
	case 10114ULL: goto x86_l_2782;
	case 10117ULL: goto x86_l_2785;
	case 10122ULL: goto x86_l_278a;
	case 10125ULL: goto x86_l_278d;
	case 10127ULL: goto x86_l_278f;
	case 10130ULL: goto x86_l_2792;
	case 10138ULL: goto x86_l_279a;
	case 10145ULL: goto x86_l_27a1;
	case 10150ULL: goto x86_l_27a6;
	case 10155ULL: goto x86_l_27ab;
	case 10157ULL: goto x86_l_27ad;
	case 10160ULL: goto x86_l_27b0;
	case 10166ULL: goto x86_l_27b6;
	case 10169ULL: goto x86_l_27b9;
	case 10174ULL: goto x86_l_27be;
	case 10184ULL: goto x86_l_27c8;
	case 10189ULL: goto x86_l_27cd;
	case 10199ULL: goto x86_l_27d7;
	case 10204ULL: goto x86_l_27dc;
	case 10214ULL: goto x86_l_27e6;
	case 10219ULL: goto x86_l_27eb;
	case 10229ULL: goto x86_l_27f5;
	case 10234ULL: goto x86_l_27fa;
	case 10244ULL: goto x86_l_2804;
	case 10249ULL: goto x86_l_2809;
	case 10259ULL: goto x86_l_2813;
	case 10264ULL: goto x86_l_2818;
	case 10269ULL: goto x86_l_281d;
	case 10274ULL: goto x86_l_2822;
	case 10280ULL: goto x86_l_2828;
	case 10284ULL: goto x86_l_282c;
	case 10288ULL: goto x86_l_2830;
	case 10293ULL: goto x86_l_2835;
	case 10296ULL: goto x86_l_2838;
	case 10301ULL: goto x86_l_283d;
	case 10303ULL: goto x86_l_283f;
	case 10306ULL: goto x86_l_2842;
	case 10311ULL: goto x86_l_2847;
	case 10321ULL: goto x86_l_2851;
	case 10326ULL: goto x86_l_2856;
	case 10336ULL: goto x86_l_2860;
	case 10341ULL: goto x86_l_2865;
	case 10351ULL: goto x86_l_286f;
	case 10356ULL: goto x86_l_2874;
	case 10361ULL: goto x86_l_2879;
	case 10366ULL: goto x86_l_287e;
	case 10372ULL: goto x86_l_2884;
	case 10377ULL: goto x86_l_2889;
	case 10382ULL: goto x86_l_288e;
	case 10385ULL: goto x86_l_2891;
	case 10387ULL: goto x86_l_2893;
	case 10390ULL: goto x86_l_2896;
	case 10396ULL: goto x86_l_289c;
	case 10400ULL: goto x86_l_28a0;
	case 10406ULL: goto x86_l_28a6;
	case 10411ULL: goto x86_l_28ab;
	case 10421ULL: goto x86_l_28b5;
	case 10426ULL: goto x86_l_28ba;
	case 10436ULL: goto x86_l_28c4;
	case 10441ULL: goto x86_l_28c9;
	case 10451ULL: goto x86_l_28d3;
	case 10456ULL: goto x86_l_28d8;
	case 10466ULL: goto x86_l_28e2;
	case 10471ULL: goto x86_l_28e7;
	case 10481ULL: goto x86_l_28f1;
	case 10486ULL: goto x86_l_28f6;
	case 10496ULL: goto x86_l_2900;
	case 10501ULL: goto x86_l_2905;
	case 10506ULL: goto x86_l_290a;
	case 10511ULL: goto x86_l_290f;
	case 10516ULL: goto x86_l_2914;
	case 10520ULL: goto x86_l_2918;
	case 10525ULL: goto x86_l_291d;
	case 10527ULL: goto x86_l_291f;
	case 10529ULL: goto x86_l_2921;
	case 10534ULL: goto x86_l_2926;
	case 10544ULL: goto x86_l_2930;
	case 10549ULL: goto x86_l_2935;
	case 10559ULL: goto x86_l_293f;
	case 10564ULL: goto x86_l_2944;
	case 10574ULL: goto x86_l_294e;
	case 10579ULL: goto x86_l_2953;
	case 10589ULL: goto x86_l_295d;
	case 10594ULL: goto x86_l_2962;
	case 10604ULL: goto x86_l_296c;
	case 10609ULL: goto x86_l_2971;
	case 10619ULL: goto x86_l_297b;
	case 10624ULL: goto x86_l_2980;
	case 10629ULL: goto x86_l_2985;
	case 10634ULL: goto x86_l_298a;
	case 10639ULL: goto x86_l_298f;
	case 10643ULL: goto x86_l_2993;
	case 10648ULL: goto x86_l_2998;
	case 10650ULL: goto x86_l_299a;
	case 10652ULL: goto x86_l_299c;
	case 10654ULL: goto x86_l_299e;
	case 10660ULL: goto x86_l_29a4;
	case 10665ULL: goto x86_l_29a9;
	case 10669ULL: goto x86_l_29ad;
	case 10671ULL: goto x86_l_29af;
	case 10681ULL: goto x86_l_29b9;
	case 10686ULL: goto x86_l_29be;
	case 10696ULL: goto x86_l_29c8;
	case 10701ULL: goto x86_l_29cd;
	case 10711ULL: goto x86_l_29d7;
	case 10716ULL: goto x86_l_29dc;
	case 10726ULL: goto x86_l_29e6;
	case 10731ULL: goto x86_l_29eb;
	case 10741ULL: goto x86_l_29f5;
	case 10746ULL: goto x86_l_29fa;
	case 10756ULL: goto x86_l_2a04;
	case 10761ULL: goto x86_l_2a09;
	case 10766ULL: goto x86_l_2a0e;
	case 10771ULL: goto x86_l_2a13;
	case 10776ULL: goto x86_l_2a18;
	case 10780ULL: goto x86_l_2a1c;
	case 10785ULL: goto x86_l_2a21;
	case 10787ULL: goto x86_l_2a23;
	case 10789ULL: goto x86_l_2a25;
	case 10796ULL: goto x86_l_2a2c;
	case 10798ULL: goto x86_l_2a2e;
	case 10803ULL: goto x86_l_2a33;
	case 10807ULL: goto x86_l_2a37;
	case 10809ULL: goto x86_l_2a39;
	case 10819ULL: goto x86_l_2a43;
	case 10824ULL: goto x86_l_2a48;
	case 10834ULL: goto x86_l_2a52;
	case 10839ULL: goto x86_l_2a57;
	case 10849ULL: goto x86_l_2a61;
	case 10854ULL: goto x86_l_2a66;
	case 10859ULL: goto x86_l_2a6b;
	case 10864ULL: goto x86_l_2a70;
	case 10870ULL: goto x86_l_2a76;
	case 10875ULL: goto x86_l_2a7b;
	case 10880ULL: goto x86_l_2a80;
	case 10883ULL: goto x86_l_2a83;
	case 10885ULL: goto x86_l_2a85;
	case 10888ULL: goto x86_l_2a88;
	case 10894ULL: goto x86_l_2a8e;
	case 10898ULL: goto x86_l_2a92;
	case 10904ULL: goto x86_l_2a98;
	case 10907ULL: goto x86_l_2a9b;
	case 10913ULL: goto x86_l_2aa1;
	case 10917ULL: goto x86_l_2aa5;
	case 10922ULL: goto x86_l_2aaa;
	case 10930ULL: goto x86_l_2ab2;
	case 10938ULL: goto x86_l_2aba;
	case 10946ULL: goto x86_l_2ac2;
	case 10957ULL: goto x86_l_2acd;
	case 10968ULL: goto x86_l_2ad8;
	case 10976ULL: goto x86_l_2ae0;
	case 10983ULL: goto x86_l_2ae7;
	case 10988ULL: goto x86_l_2aec;
	case 10993ULL: goto x86_l_2af1;
	case 10995ULL: goto x86_l_2af3;
	case 10998ULL: goto x86_l_2af6;
	case 11000ULL: goto x86_l_2af8;
	case 11003ULL: goto x86_l_2afb;
	case 11005ULL: goto x86_l_2afd;
	case 11009ULL: goto x86_l_2b01;
	case 11011ULL: goto x86_l_2b03;
	case 11021ULL: goto x86_l_2b0d;
	case 11026ULL: goto x86_l_2b12;
	case 11036ULL: goto x86_l_2b1c;
	case 11041ULL: goto x86_l_2b21;
	case 11051ULL: goto x86_l_2b2b;
	case 11056ULL: goto x86_l_2b30;
	case 11066ULL: goto x86_l_2b3a;
	case 11071ULL: goto x86_l_2b3f;
	case 11081ULL: goto x86_l_2b49;
	case 11086ULL: goto x86_l_2b4e;
	case 11096ULL: goto x86_l_2b58;
	case 11101ULL: goto x86_l_2b5d;
	case 11106ULL: goto x86_l_2b62;
	case 11111ULL: goto x86_l_2b67;
	case 11116ULL: goto x86_l_2b6c;
	case 11120ULL: goto x86_l_2b70;
	case 11125ULL: goto x86_l_2b75;
	case 11127ULL: goto x86_l_2b77;
	case 11129ULL: goto x86_l_2b79;
	case 11131ULL: goto x86_l_2b7b;
	case 11137ULL: goto x86_l_2b81;
	case 11140ULL: goto x86_l_2b84;
	case 11146ULL: goto x86_l_2b8a;
	case 11152ULL: goto x86_l_2b90;
	case 11156ULL: goto x86_l_2b94;
	case 11160ULL: goto x86_l_2b98;
	case 11166ULL: goto x86_l_2b9e;
	case 11170ULL: goto x86_l_2ba2;
	case 11174ULL: goto x86_l_2ba6;
	case 11180ULL: goto x86_l_2bac;
	case 11184ULL: goto x86_l_2bb0;
	case 11188ULL: goto x86_l_2bb4;
	case 11194ULL: goto x86_l_2bba;
	case 11198ULL: goto x86_l_2bbe;
	case 11202ULL: goto x86_l_2bc2;
	case 11208ULL: goto x86_l_2bc8;
	case 11213ULL: goto x86_l_2bcd;
	case 11218ULL: goto x86_l_2bd2;
	case 11223ULL: goto x86_l_2bd7;
	case 11228ULL: goto x86_l_2bdc;
	case 11233ULL: goto x86_l_2be1;
	case 11235ULL: goto x86_l_2be3;
	case 11238ULL: goto x86_l_2be6;
	case 11244ULL: goto x86_l_2bec;
	case 11248ULL: goto x86_l_2bf0;
	case 11252ULL: goto x86_l_2bf4;
	case 11257ULL: goto x86_l_2bf9;
	case 11261ULL: goto x86_l_2bfd;
	case 11266ULL: goto x86_l_2c02;
	case 11270ULL: goto x86_l_2c06;
	case 11274ULL: goto x86_l_2c0a;
	case 11278ULL: goto x86_l_2c0e;
	case 11281ULL: goto x86_l_2c11;
	case 11283ULL: goto x86_l_2c13;
	case 11288ULL: goto x86_l_2c18;
	case 11294ULL: goto x86_l_2c1e;
	case 11298ULL: goto x86_l_2c22;
	case 11302ULL: goto x86_l_2c26;
	case 11306ULL: goto x86_l_2c2a;
	case 11308ULL: goto x86_l_2c2c;
	case 11313ULL: goto x86_l_2c31;
	case 11317ULL: goto x86_l_2c35;
	case 11321ULL: goto x86_l_2c39;
	case 11325ULL: goto x86_l_2c3d;
	case 11330ULL: goto x86_l_2c42;
	case 11333ULL: goto x86_l_2c45;
	case 11340ULL: goto x86_l_2c4c;
	case 11342ULL: goto x86_l_2c4e;
	case 11349ULL: goto x86_l_2c55;
	case 11354ULL: goto x86_l_2c5a;
	case 11357ULL: goto x86_l_2c5d;
	case 11361ULL: goto x86_l_2c61;
	case 11365ULL: goto x86_l_2c65;
	case 11368ULL: goto x86_l_2c68;
	case 11372ULL: goto x86_l_2c6c;
	case 11374ULL: goto x86_l_2c6e;
	case 11379ULL: goto x86_l_2c73;
	case 11382ULL: goto x86_l_2c76;
	case 11385ULL: goto x86_l_2c79;
	case 11391ULL: goto x86_l_2c7f;
	case 11397ULL: goto x86_l_2c85;
	case 11401ULL: goto x86_l_2c89;
	case 11405ULL: goto x86_l_2c8d;
	case 11411ULL: goto x86_l_2c93;
	case 11415ULL: goto x86_l_2c97;
	case 11419ULL: goto x86_l_2c9b;
	case 11425ULL: goto x86_l_2ca1;
	case 11429ULL: goto x86_l_2ca5;
	case 11433ULL: goto x86_l_2ca9;
	case 11439ULL: goto x86_l_2caf;
	case 11443ULL: goto x86_l_2cb3;
	case 11447ULL: goto x86_l_2cb7;
	case 11453ULL: goto x86_l_2cbd;
	case 11458ULL: goto x86_l_2cc2;
	case 11463ULL: goto x86_l_2cc7;
	case 11468ULL: goto x86_l_2ccc;
	case 11471ULL: goto x86_l_2ccf;
	case 11476ULL: goto x86_l_2cd4;
	case 11478ULL: goto x86_l_2cd6;
	case 11481ULL: goto x86_l_2cd9;
	case 11487ULL: goto x86_l_2cdf;
	case 11491ULL: goto x86_l_2ce3;
	case 11495ULL: goto x86_l_2ce7;
	case 11499ULL: goto x86_l_2ceb;
	case 11503ULL: goto x86_l_2cef;
	case 11507ULL: goto x86_l_2cf3;
	case 11511ULL: goto x86_l_2cf7;
	case 11515ULL: goto x86_l_2cfb;
	case 11519ULL: goto x86_l_2cff;
	case 11522ULL: goto x86_l_2d02;
	case 11525ULL: goto x86_l_2d05;
	case 11527ULL: goto x86_l_2d07;
	case 11530ULL: goto x86_l_2d0a;
	case 11532ULL: goto x86_l_2d0c;
	case 11536ULL: goto x86_l_2d10;
	case 11540ULL: goto x86_l_2d14;
	case 11543ULL: goto x86_l_2d17;
	case 11548ULL: goto x86_l_2d1c;
	case 11552ULL: goto x86_l_2d20;
	case 11558ULL: goto x86_l_2d26;
	case 11568ULL: goto x86_l_2d30;
	case 11573ULL: goto x86_l_2d35;
	case 11583ULL: goto x86_l_2d3f;
	case 11588ULL: goto x86_l_2d44;
	case 11598ULL: goto x86_l_2d4e;
	case 11603ULL: goto x86_l_2d53;
	case 11613ULL: goto x86_l_2d5d;
	case 11618ULL: goto x86_l_2d62;
	case 11628ULL: goto x86_l_2d6c;
	case 11633ULL: goto x86_l_2d71;
	case 11643ULL: goto x86_l_2d7b;
	case 11648ULL: goto x86_l_2d80;
	case 11653ULL: goto x86_l_2d85;
	case 11658ULL: goto x86_l_2d8a;
	case 11664ULL: goto x86_l_2d90;
	case 11668ULL: goto x86_l_2d94;
	case 11672ULL: goto x86_l_2d98;
	case 11677ULL: goto x86_l_2d9d;
	case 11680ULL: goto x86_l_2da0;
	case 11685ULL: goto x86_l_2da5;
	case 11687ULL: goto x86_l_2da7;
	case 11690ULL: goto x86_l_2daa;
	case 11698ULL: goto x86_l_2db2;
	case 11705ULL: goto x86_l_2db9;
	case 11710ULL: goto x86_l_2dbe;
	case 11715ULL: goto x86_l_2dc3;
	case 11717ULL: goto x86_l_2dc5;
	case 11720ULL: goto x86_l_2dc8;
	case 11722ULL: goto x86_l_2dca;
	case 11725ULL: goto x86_l_2dcd;
	case 11727ULL: goto x86_l_2dcf;
	case 11731ULL: goto x86_l_2dd3;
	case 11733ULL: goto x86_l_2dd5;
	case 11743ULL: goto x86_l_2ddf;
	case 11748ULL: goto x86_l_2de4;
	case 11758ULL: goto x86_l_2dee;
	case 11763ULL: goto x86_l_2df3;
	case 11773ULL: goto x86_l_2dfd;
	case 11778ULL: goto x86_l_2e02;
	case 11788ULL: goto x86_l_2e0c;
	case 11793ULL: goto x86_l_2e11;
	case 11803ULL: goto x86_l_2e1b;
	case 11808ULL: goto x86_l_2e20;
	case 11818ULL: goto x86_l_2e2a;
	case 11823ULL: goto x86_l_2e2f;
	case 11828ULL: goto x86_l_2e34;
	case 11833ULL: goto x86_l_2e39;
	case 11838ULL: goto x86_l_2e3e;
	case 11842ULL: goto x86_l_2e42;
	case 11847ULL: goto x86_l_2e47;
	case 11849ULL: goto x86_l_2e49;
	case 11851ULL: goto x86_l_2e4b;
	case 11858ULL: goto x86_l_2e52;
	default: return 0xffffffffffffffffULL;
	}
x86_l_268b:
	/* 0x268b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_268f:
	/* 0x268f: cmp    BYTE PTR [rax+0x1f],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133143986364ULL);
x86_l_2693:
	/* 0x2693: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_2699:
	/* 0x2699: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_269d:
	/* 0x269d: cmp    BYTE PTR [rax+0x20],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953660ULL);
x86_l_26a1:
	/* 0x26a1: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_26a7:
	/* 0x26a7: mov    eax,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 192ULL);
x86_l_26ac:
	/* 0x26ac: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_26b1:
	/* 0x26b1: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26b6:
	/* 0x26b6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_26b9:
	/* 0x26b9: mov    esi,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 192ULL);
x86_l_26be:
	/* 0x26be: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_26c0:
	/* 0x26c0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26c3:
	/* 0x26c3: jne    1e2c <perf_unwind_python+0x1e2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7724ULL;
	}
x86_l_26c9:
	/* 0x26c9: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26cd:
	/* 0x26cd: movzx  ecx,BYTE PTR [rax+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_26d1:
	/* 0x26d1: mov    ecx,DWORD PTR [r15+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_26d5:
	/* 0x26d5: movzx  edx,BYTE PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_26d9:
	/* 0x26d9: mov    edx,DWORD PTR [r15+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_26dd:
	/* 0x26dd: movzx  esi,BYTE PTR [rax+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_26e1:
	/* 0x26e1: mov    esi,DWORD PTR [r15+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_26e5:
	/* 0x26e5: movzx  eax,BYTE PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_26e9:
	/* 0x26e9: shl    ecx,0x19 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 25ULL);
x86_l_26ec:
	/* 0x26ec: shl    edx,0x12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 18ULL);
x86_l_26ef:
	/* 0x26ef: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_26f1:
	/* 0x26f1: shl    esi,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 10ULL);
x86_l_26f4:
	/* 0x26f4: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_26f6:
	/* 0x26f6: add    esi,DWORD PTR [r15+rax*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R15, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_26fa:
	/* 0x26fa: shl    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_26fe:
	/* 0x26fe: or     r12,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RSI, X86_WIDTH_64, X86_ALU_OR);
x86_l_2701:
	/* 0x2701: jmp    2a33 <perf_unwind_python+0x2a33> */
	goto x86_l_2a33;
x86_l_2706:
	/* 0x2706: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_270a:
	/* 0x270a: je     2792 <perf_unwind_python+0x2792> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2792;
	}
x86_l_2710:
	/* 0x2710: movabs rax,0xa786c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541280ULL);
x86_l_271a:
	/* 0x271a: mov    QWORD PTR [rsp+0x57],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_271f:
	/* 0x271f: movabs rax,0x20786c2578302074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2339738914604982388ULL);
x86_l_2729:
	/* 0x2729: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_272e:
	/* 0x272e: movabs rax,0x63656a624f656d61 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7162247752874028385ULL);
x86_l_2738:
	/* 0x2738: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_273d:
	/* 0x273d: movabs rax,0x7246795020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8234402353742245734ULL);
x86_l_2747:
	/* 0x2747: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_274c:
	/* 0x274c: movabs rax,0x207463656a626f65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338603393739812709ULL);
x86_l_2756:
	/* 0x2756: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_275b:
	/* 0x275b: movabs rax,0x646f63206c6c754e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7237112117116826958ULL);
x86_l_2765:
	/* 0x2765: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_276a:
	/* 0x276a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_276f:
	/* 0x276f: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_2774:
	/* 0x2774: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_277a:
	/* 0x277a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_277e:
	/* 0x277e: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_2782:
	/* 0x2782: add    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2785:
	/* 0x2785: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_278a:
	/* 0x278a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_278d:
	/* 0x278d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_278f:
	/* 0x278f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2792:
	/* 0x2792: mov    DWORD PTR [rsp+0x18],0x1c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215132ULL);
x86_l_279a:
	/* 0x279a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_27a1:
	/* 0x27a1: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27a6:
	/* 0x27a6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27ab:
	/* 0x27ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27ad:
	/* 0x27ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27b0:
	/* 0x27b0: je     29a9 <perf_unwind_python+0x29a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29a9;
	}
x86_l_27b6:
	/* 0x27b6: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_27b9:
	/* 0x27b9: jmp    2a25 <perf_unwind_python+0x2a25> */
	goto x86_l_2a25;
x86_l_27be:
	/* 0x27be: movabs rax,0xa786c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541280ULL);
x86_l_27c8:
	/* 0x27c8: mov    QWORD PTR [rsp+0x57],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_27cd:
	/* 0x27cd: movabs rax,0x20786c2578302074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2339738914604982388ULL);
x86_l_27d7:
	/* 0x27d7: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_27dc:
	/* 0x27dc: movabs rax,0x63656a624f656d61 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7162247752874028385ULL);
x86_l_27e6:
	/* 0x27e6: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_27eb:
	/* 0x27eb: movabs rax,0x7246795020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8234402353742245734ULL);
x86_l_27f5:
	/* 0x27f5: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_27fa:
	/* 0x27fa: movabs rax,0x207463656a626f65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338603393739812709ULL);
x86_l_2804:
	/* 0x2804: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2809:
	/* 0x2809: movabs rax,0x646f63206c6c754e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7237112117116826958ULL);
x86_l_2813:
	/* 0x2813: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2818:
	/* 0x2818: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_281d:
	/* 0x281d: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_2822:
	/* 0x2822: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_2828:
	/* 0x2828: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_282c:
	/* 0x282c: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_2830:
	/* 0x2830: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2835:
	/* 0x2835: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2838:
	/* 0x2838: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_283d:
	/* 0x283d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_283f:
	/* 0x283f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2842:
	/* 0x2842: jmp    22fa <perf_unwind_python+0x22fa> */
	return 8954ULL;
x86_l_2847:
	/* 0x2847: movabs rax,0xa756c2520786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2943857106909292ULL);
x86_l_2851:
	/* 0x2851: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2856:
	/* 0x2856: movabs rax,0x25206e6f68747950 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675259603430963536ULL);
x86_l_2860:
	/* 0x2860: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2865:
	/* 0x2865: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_286f:
	/* 0x286f: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2874:
	/* 0x2874: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2879:
	/* 0x2879: mov    eax,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_287e:
	/* 0x287e: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_2884:
	/* 0x2884: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_2889:
	/* 0x2889: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_288e:
	/* 0x288e: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2891:
	/* 0x2891: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2893:
	/* 0x2893: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2896:
	/* 0x2896: mov    eax,DWORD PTR [rbp+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_289c:
	/* 0x289c: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_28a0:
	/* 0x28a0: ja     176d <perf_unwind_python+0x176d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5997ULL;
	}
x86_l_28a6:
	/* 0x28a6: jmp    23df <perf_unwind_python+0x23df> */
	return 9183ULL;
x86_l_28ab:
	/* 0x28ab: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_28b5:
	/* 0x28b5: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_28ba:
	/* 0x28ba: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_28c4:
	/* 0x28c4: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_28c9:
	/* 0x28c9: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_28d3:
	/* 0x28d3: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_28d8:
	/* 0x28d8: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_28e2:
	/* 0x28e2: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_28e7:
	/* 0x28e7: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_28f1:
	/* 0x28f1: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_28f6:
	/* 0x28f6: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2900:
	/* 0x2900: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2905:
	/* 0x2905: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_290a:
	/* 0x290a: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_290f:
	/* 0x290f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2914:
	/* 0x2914: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2918:
	/* 0x2918: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_291d:
	/* 0x291d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_291f:
	/* 0x291f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2921:
	/* 0x2921: jmp    23b7 <perf_unwind_python+0x23b7> */
	return 9143ULL;
x86_l_2926:
	/* 0x2926: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_2930:
	/* 0x2930: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2935:
	/* 0x2935: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_293f:
	/* 0x293f: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2944:
	/* 0x2944: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_294e:
	/* 0x294e: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2953:
	/* 0x2953: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_295d:
	/* 0x295d: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2962:
	/* 0x2962: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_296c:
	/* 0x296c: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2971:
	/* 0x2971: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_297b:
	/* 0x297b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2980:
	/* 0x2980: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2985:
	/* 0x2985: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_298a:
	/* 0x298a: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_298f:
	/* 0x298f: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2993:
	/* 0x2993: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2998:
	/* 0x2998: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_299a:
	/* 0x299a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_299c:
	/* 0x299c: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
x86_l_299e:
	/* 0x299e: jne    1242 <perf_unwind_python+0x1242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4674ULL;
	}
x86_l_29a4:
	/* 0x29a4: jmp    24e0 <perf_unwind_python+0x24e0> */
	return 9440ULL;
x86_l_29a9:
	/* 0x29a9: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29ad:
	/* 0x29ad: je     2a25 <perf_unwind_python+0x2a25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a25;
	}
x86_l_29af:
	/* 0x29af: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_29b9:
	/* 0x29b9: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_29be:
	/* 0x29be: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_29c8:
	/* 0x29c8: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_29cd:
	/* 0x29cd: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_29d7:
	/* 0x29d7: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_29dc:
	/* 0x29dc: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_29e6:
	/* 0x29e6: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_29eb:
	/* 0x29eb: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_29f5:
	/* 0x29f5: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_29fa:
	/* 0x29fa: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2a04:
	/* 0x2a04: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a09:
	/* 0x2a09: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a0e:
	/* 0x2a0e: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2a13:
	/* 0x2a13: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2a18:
	/* 0x2a18: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a1c:
	/* 0x2a1c: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2a21:
	/* 0x2a21: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a23:
	/* 0x2a23: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2a25:
	/* 0x2a25: mov    r12,0xfffffffffffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_2a2c:
	/* 0x2a2c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a2e:
	/* 0x2a2e: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a33:
	/* 0x2a33: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a37:
	/* 0x2a37: je     2a88 <perf_unwind_python+0x2a88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a88;
	}
x86_l_2a39:
	/* 0x2a39: movabs rax,0xa756c2520786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2943857106909292ULL);
x86_l_2a43:
	/* 0x2a43: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a48:
	/* 0x2a48: movabs rax,0x25206e6f68747950 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675259603430963536ULL);
x86_l_2a52:
	/* 0x2a52: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a57:
	/* 0x2a57: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_2a61:
	/* 0x2a61: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a66:
	/* 0x2a66: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a6b:
	/* 0x2a6b: mov    eax,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_2a70:
	/* 0x2a70: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_2a76:
	/* 0x2a76: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_2a7b:
	/* 0x2a7b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a80:
	/* 0x2a80: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2a83:
	/* 0x2a83: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a85:
	/* 0x2a85: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2a88:
	/* 0x2a88: mov    eax,DWORD PTR [rbp+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_2a8e:
	/* 0x2a8e: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_2a92:
	/* 0x2a92: ja     1f27 <perf_unwind_python+0x1f27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7975ULL;
	}
x86_l_2a98:
	/* 0x2a98: lea    ecx,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2a9b:
	/* 0x2a9b: mov    DWORD PTR [rbp+0x2c0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_2aa1:
	/* 0x2aa1: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2aa5:
	/* 0x2aa5: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2aaa:
	/* 0x2aaa: mov    QWORD PTR [rbp+rax*8+0x2d0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_2ab2:
	/* 0x2ab2: mov    QWORD PTR [rbp+rax*8+0x2d8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_2aba:
	/* 0x2aba: mov    BYTE PTR [rbp+rax*8+0x2e0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929857ULL);
x86_l_2ac2:
	/* 0x2ac2: mov    DWORD PTR [rbp+rax*8+0x2e1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3165390897152ULL);
x86_l_2acd:
	/* 0x2acd: mov    DWORD PTR [rbp+rax*8+0x2e4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3178275799040ULL);
x86_l_2ad8:
	/* 0x2ad8: mov    DWORD PTR [rsp+0x18],0x16 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215126ULL);
x86_l_2ae0:
	/* 0x2ae0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_2ae7:
	/* 0x2ae7: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2aec:
	/* 0x2aec: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2af1:
	/* 0x2af1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2af3:
	/* 0x2af3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2af6:
	/* 0x2af6: je     2afd <perf_unwind_python+0x2afd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2afd;
	}
x86_l_2af8:
	/* 0x2af8: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2afb:
	/* 0x2afb: jmp    2b79 <perf_unwind_python+0x2b79> */
	goto x86_l_2b79;
x86_l_2afd:
	/* 0x2afd: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b01:
	/* 0x2b01: je     2b79 <perf_unwind_python+0x2b79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b79;
	}
x86_l_2b03:
	/* 0x2b03: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_2b0d:
	/* 0x2b0d: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2b12:
	/* 0x2b12: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_2b1c:
	/* 0x2b1c: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b21:
	/* 0x2b21: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_2b2b:
	/* 0x2b2b: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b30:
	/* 0x2b30: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_2b3a:
	/* 0x2b3a: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b3f:
	/* 0x2b3f: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2b49:
	/* 0x2b49: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b4e:
	/* 0x2b4e: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2b58:
	/* 0x2b58: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b5d:
	/* 0x2b5d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b62:
	/* 0x2b62: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2b67:
	/* 0x2b67: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2b6c:
	/* 0x2b6c: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b70:
	/* 0x2b70: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2b75:
	/* 0x2b75: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b77:
	/* 0x2b77: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2b79:
	/* 0x2b79: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
x86_l_2b7b:
	/* 0x2b7b: jne    1d5a <perf_unwind_python+0x1d5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7514ULL;
	}
x86_l_2b81:
	/* 0x2b81: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b84:
	/* 0x2b84: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2b8a:
	/* 0x2b8a: je     45b4 <perf_unwind_python+0x45b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17844ULL;
	}
x86_l_2b90:
	/* 0x2b90: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b94:
	/* 0x2b94: cmp    BYTE PTR [rax+0x19],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 107374182520ULL);
x86_l_2b98:
	/* 0x2b98: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_2b9e:
	/* 0x2b9e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ba2:
	/* 0x2ba2: cmp    BYTE PTR [rax+0x18],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215224ULL);
x86_l_2ba6:
	/* 0x2ba6: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_2bac:
	/* 0x2bac: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bb0:
	/* 0x2bb0: cmp    BYTE PTR [rax+0x1a],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 111669149816ULL);
x86_l_2bb4:
	/* 0x2bb4: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_2bba:
	/* 0x2bba: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bbe:
	/* 0x2bbe: cmp    BYTE PTR [rax+0x1b],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 115964116992ULL);
x86_l_2bc2:
	/* 0x2bc2: js     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 17816ULL;
	}
x86_l_2bc8:
	/* 0x2bc8: mov    eax,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 128ULL);
x86_l_2bcd:
	/* 0x2bcd: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_2bd2:
	/* 0x2bd2: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2bd7:
	/* 0x2bd7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2bdc:
	/* 0x2bdc: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_2be1:
	/* 0x2be1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2be3:
	/* 0x2be3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2be6:
	/* 0x2be6: jne    d56 <perf_unwind_python+0xd56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3414ULL;
	}
x86_l_2bec:
	/* 0x2bec: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bf0:
	/* 0x2bf0: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_2bf4:
	/* 0x2bf4: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2bf9:
	/* 0x2bf9: mov    rcx,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2bfd:
	/* 0x2bfd: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c02:
	/* 0x2c02: movzx  ecx,BYTE PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_2c06:
	/* 0x2c06: mov    r13,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2c0a:
	/* 0x2c0a: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c0e:
	/* 0x2c0e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c11:
	/* 0x2c11: je     2c1e <perf_unwind_python+0x2c1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c1e;
	}
x86_l_2c13:
	/* 0x2c13: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c18:
	/* 0x2c18: je     1242 <perf_unwind_python+0x1242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4674ULL;
	}
x86_l_2c1e:
	/* 0x2c1e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c22:
	/* 0x2c22: cmp    BYTE PTR [rax+0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_2c26:
	/* 0x2c26: movzx  eax,BYTE PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 26ULL);
x86_l_2c2a:
	/* 0x2c2a: je     2c6e <perf_unwind_python+0x2c6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c6e;
	}
x86_l_2c2c:
	/* 0x2c2c: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2c31:
	/* 0x2c31: mov    rax,QWORD PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2c35:
	/* 0x2c35: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c39:
	/* 0x2c39: movzx  edx,BYTE PTR [rcx+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_2c3d:
	/* 0x2c3d: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_2c42:
	/* 0x2c42: sub    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2c45:
	/* 0x2c45: lea    rdx,[rax-0x10000001] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073441116159ULL);
x86_l_2c4c:
	/* 0x2c4c: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_2c4e:
	/* 0x2c4e: cmp    rdx,0xffffffffeffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073441116157ULL);
x86_l_2c55:
	/* 0x2c55: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_2c5a:
	/* 0x2c5a: cmovae ebx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_2c5d:
	/* 0x2c5d: movzx  eax,BYTE PTR [rcx+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_2c61:
	/* 0x2c61: movzx  eax,BYTE PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2c65:
	/* 0x2c65: cmp    al,BYTE PTR [rcx+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_2c68:
	/* 0x2c68: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_2c6c:
	/* 0x2c6c: jmp    2c79 <perf_unwind_python+0x2c79> */
	goto x86_l_2c79;
x86_l_2c6e:
	/* 0x2c6e: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2c73:
	/* 0x2c73: mov    ebx,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2c76:
	/* 0x2c76: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c79:
	/* 0x2c79: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2c7f:
	/* 0x2c7f: je     2d1c <perf_unwind_python+0x2d1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d1c;
	}
x86_l_2c85:
	/* 0x2c85: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c89:
	/* 0x2c89: cmp    BYTE PTR [rax+0x1d],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051772ULL);
x86_l_2c8d:
	/* 0x2c8d: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_2c93:
	/* 0x2c93: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c97:
	/* 0x2c97: cmp    BYTE PTR [rax+0x1e],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128849019068ULL);
x86_l_2c9b:
	/* 0x2c9b: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_2ca1:
	/* 0x2ca1: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ca5:
	/* 0x2ca5: cmp    BYTE PTR [rax+0x1f],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133143986364ULL);
x86_l_2ca9:
	/* 0x2ca9: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_2caf:
	/* 0x2caf: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cb3:
	/* 0x2cb3: cmp    BYTE PTR [rax+0x20],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953660ULL);
x86_l_2cb7:
	/* 0x2cb7: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_2cbd:
	/* 0x2cbd: mov    eax,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 192ULL);
x86_l_2cc2:
	/* 0x2cc2: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_2cc7:
	/* 0x2cc7: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ccc:
	/* 0x2ccc: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2ccf:
	/* 0x2ccf: mov    esi,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 192ULL);
x86_l_2cd4:
	/* 0x2cd4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2cd6:
	/* 0x2cd6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cd9:
	/* 0x2cd9: jne    2b5 <perf_unwind_python+0x2b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 693ULL;
	}
x86_l_2cdf:
	/* 0x2cdf: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ce3:
	/* 0x2ce3: movzx  ecx,BYTE PTR [rax+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_2ce7:
	/* 0x2ce7: mov    ecx,DWORD PTR [r15+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2ceb:
	/* 0x2ceb: movzx  edx,BYTE PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_2cef:
	/* 0x2cef: mov    edx,DWORD PTR [r15+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_2cf3:
	/* 0x2cf3: movzx  esi,BYTE PTR [rax+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_2cf7:
	/* 0x2cf7: mov    esi,DWORD PTR [r15+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_2cfb:
	/* 0x2cfb: movzx  eax,BYTE PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_2cff:
	/* 0x2cff: shl    ecx,0x19 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 25ULL);
x86_l_2d02:
	/* 0x2d02: shl    edx,0x12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 18ULL);
x86_l_2d05:
	/* 0x2d05: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2d07:
	/* 0x2d07: shl    esi,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 10ULL);
x86_l_2d0a:
	/* 0x2d0a: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2d0c:
	/* 0x2d0c: add    esi,DWORD PTR [r15+rax*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R15, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2d10:
	/* 0x2d10: shl    rbx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_2d14:
	/* 0x2d14: or     rbx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RSI, X86_WIDTH_64, X86_ALU_OR);
x86_l_2d17:
	/* 0x2d17: jmp    2e59 <perf_unwind_python+0x2e59> */
	return 11865ULL;
x86_l_2d1c:
	/* 0x2d1c: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d20:
	/* 0x2d20: je     2daa <perf_unwind_python+0x2daa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2daa;
	}
x86_l_2d26:
	/* 0x2d26: movabs rax,0xa786c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541280ULL);
x86_l_2d30:
	/* 0x2d30: mov    QWORD PTR [rsp+0x57],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_2d35:
	/* 0x2d35: movabs rax,0x20786c2578302074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2339738914604982388ULL);
x86_l_2d3f:
	/* 0x2d3f: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2d44:
	/* 0x2d44: movabs rax,0x63656a624f656d61 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7162247752874028385ULL);
x86_l_2d4e:
	/* 0x2d4e: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2d53:
	/* 0x2d53: movabs rax,0x7246795020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8234402353742245734ULL);
x86_l_2d5d:
	/* 0x2d5d: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d62:
	/* 0x2d62: movabs rax,0x207463656a626f65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338603393739812709ULL);
x86_l_2d6c:
	/* 0x2d6c: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d71:
	/* 0x2d71: movabs rax,0x646f63206c6c754e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7237112117116826958ULL);
x86_l_2d7b:
	/* 0x2d7b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d80:
	/* 0x2d80: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d85:
	/* 0x2d85: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_2d8a:
	/* 0x2d8a: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_2d90:
	/* 0x2d90: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d94:
	/* 0x2d94: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_2d98:
	/* 0x2d98: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d9d:
	/* 0x2d9d: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2da0:
	/* 0x2da0: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_2da5:
	/* 0x2da5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2da7:
	/* 0x2da7: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2daa:
	/* 0x2daa: mov    DWORD PTR [rsp+0x18],0x1c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215132ULL);
x86_l_2db2:
	/* 0x2db2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_2db9:
	/* 0x2db9: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2dbe:
	/* 0x2dbe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2dc3:
	/* 0x2dc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dc5:
	/* 0x2dc5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2dc8:
	/* 0x2dc8: je     2dcf <perf_unwind_python+0x2dcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dcf;
	}
x86_l_2dca:
	/* 0x2dca: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2dcd:
	/* 0x2dcd: jmp    2e4b <perf_unwind_python+0x2e4b> */
	goto x86_l_2e4b;
x86_l_2dcf:
	/* 0x2dcf: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dd3:
	/* 0x2dd3: je     2e4b <perf_unwind_python+0x2e4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e4b;
	}
x86_l_2dd5:
	/* 0x2dd5: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_2ddf:
	/* 0x2ddf: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2de4:
	/* 0x2de4: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_2dee:
	/* 0x2dee: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2df3:
	/* 0x2df3: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_2dfd:
	/* 0x2dfd: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2e02:
	/* 0x2e02: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_2e0c:
	/* 0x2e0c: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e11:
	/* 0x2e11: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2e1b:
	/* 0x2e1b: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e20:
	/* 0x2e20: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2e2a:
	/* 0x2e2a: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e2f:
	/* 0x2e2f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e34:
	/* 0x2e34: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2e39:
	/* 0x2e39: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2e3e:
	/* 0x2e3e: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e42:
	/* 0x2e42: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2e47:
	/* 0x2e47: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e49:
	/* 0x2e49: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2e4b:
	/* 0x2e4b: mov    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_2e52:
	/* 0x2e52: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
	return 11860ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11860ULL: goto x86_l_2e54;
	case 11865ULL: goto x86_l_2e59;
	case 11869ULL: goto x86_l_2e5d;
	case 11871ULL: goto x86_l_2e5f;
	case 11881ULL: goto x86_l_2e69;
	case 11886ULL: goto x86_l_2e6e;
	case 11896ULL: goto x86_l_2e78;
	case 11901ULL: goto x86_l_2e7d;
	case 11911ULL: goto x86_l_2e87;
	case 11916ULL: goto x86_l_2e8c;
	case 11921ULL: goto x86_l_2e91;
	case 11926ULL: goto x86_l_2e96;
	case 11932ULL: goto x86_l_2e9c;
	case 11937ULL: goto x86_l_2ea1;
	case 11942ULL: goto x86_l_2ea6;
	case 11945ULL: goto x86_l_2ea9;
	case 11947ULL: goto x86_l_2eab;
	case 11950ULL: goto x86_l_2eae;
	case 11956ULL: goto x86_l_2eb4;
	case 11960ULL: goto x86_l_2eb8;
	case 11966ULL: goto x86_l_2ebe;
	case 11969ULL: goto x86_l_2ec1;
	case 11975ULL: goto x86_l_2ec7;
	case 11979ULL: goto x86_l_2ecb;
	case 11984ULL: goto x86_l_2ed0;
	case 11992ULL: goto x86_l_2ed8;
	case 12000ULL: goto x86_l_2ee0;
	case 12008ULL: goto x86_l_2ee8;
	case 12019ULL: goto x86_l_2ef3;
	case 12030ULL: goto x86_l_2efe;
	case 12038ULL: goto x86_l_2f06;
	case 12045ULL: goto x86_l_2f0d;
	case 12050ULL: goto x86_l_2f12;
	case 12055ULL: goto x86_l_2f17;
	case 12057ULL: goto x86_l_2f19;
	case 12060ULL: goto x86_l_2f1c;
	case 12062ULL: goto x86_l_2f1e;
	case 12065ULL: goto x86_l_2f21;
	case 12067ULL: goto x86_l_2f23;
	case 12071ULL: goto x86_l_2f27;
	case 12073ULL: goto x86_l_2f29;
	case 12083ULL: goto x86_l_2f33;
	case 12088ULL: goto x86_l_2f38;
	case 12098ULL: goto x86_l_2f42;
	case 12103ULL: goto x86_l_2f47;
	case 12113ULL: goto x86_l_2f51;
	case 12118ULL: goto x86_l_2f56;
	case 12128ULL: goto x86_l_2f60;
	case 12133ULL: goto x86_l_2f65;
	case 12143ULL: goto x86_l_2f6f;
	case 12148ULL: goto x86_l_2f74;
	case 12158ULL: goto x86_l_2f7e;
	case 12163ULL: goto x86_l_2f83;
	case 12168ULL: goto x86_l_2f88;
	case 12173ULL: goto x86_l_2f8d;
	case 12178ULL: goto x86_l_2f92;
	case 12182ULL: goto x86_l_2f96;
	case 12187ULL: goto x86_l_2f9b;
	case 12189ULL: goto x86_l_2f9d;
	case 12191ULL: goto x86_l_2f9f;
	case 12194ULL: goto x86_l_2fa2;
	case 12200ULL: goto x86_l_2fa8;
	case 12203ULL: goto x86_l_2fab;
	case 12206ULL: goto x86_l_2fae;
	case 12212ULL: goto x86_l_2fb4;
	case 12216ULL: goto x86_l_2fb8;
	case 12220ULL: goto x86_l_2fbc;
	case 12226ULL: goto x86_l_2fc2;
	case 12230ULL: goto x86_l_2fc6;
	case 12234ULL: goto x86_l_2fca;
	case 12240ULL: goto x86_l_2fd0;
	case 12244ULL: goto x86_l_2fd4;
	case 12248ULL: goto x86_l_2fd8;
	case 12254ULL: goto x86_l_2fde;
	case 12258ULL: goto x86_l_2fe2;
	case 12262ULL: goto x86_l_2fe6;
	case 12268ULL: goto x86_l_2fec;
	case 12273ULL: goto x86_l_2ff1;
	case 12278ULL: goto x86_l_2ff6;
	case 12283ULL: goto x86_l_2ffb;
	case 12288ULL: goto x86_l_3000;
	case 12291ULL: goto x86_l_3003;
	case 12293ULL: goto x86_l_3005;
	case 12296ULL: goto x86_l_3008;
	case 12302ULL: goto x86_l_300e;
	case 12306ULL: goto x86_l_3012;
	case 12310ULL: goto x86_l_3016;
	case 12315ULL: goto x86_l_301b;
	case 12319ULL: goto x86_l_301f;
	case 12324ULL: goto x86_l_3024;
	case 12328ULL: goto x86_l_3028;
	case 12332ULL: goto x86_l_302c;
	case 12337ULL: goto x86_l_3031;
	case 12341ULL: goto x86_l_3035;
	case 12344ULL: goto x86_l_3038;
	case 12346ULL: goto x86_l_303a;
	case 12351ULL: goto x86_l_303f;
	case 12357ULL: goto x86_l_3045;
	case 12361ULL: goto x86_l_3049;
	case 12365ULL: goto x86_l_304d;
	case 12369ULL: goto x86_l_3051;
	case 12371ULL: goto x86_l_3053;
	case 12376ULL: goto x86_l_3058;
	case 12380ULL: goto x86_l_305c;
	case 12384ULL: goto x86_l_3060;
	case 12388ULL: goto x86_l_3064;
	case 12393ULL: goto x86_l_3069;
	case 12396ULL: goto x86_l_306c;
	case 12403ULL: goto x86_l_3073;
	case 12405ULL: goto x86_l_3075;
	case 12412ULL: goto x86_l_307c;
	case 12418ULL: goto x86_l_3082;
	case 12422ULL: goto x86_l_3086;
	case 12426ULL: goto x86_l_308a;
	case 12430ULL: goto x86_l_308e;
	case 12433ULL: goto x86_l_3091;
	case 12436ULL: goto x86_l_3094;
	case 12440ULL: goto x86_l_3098;
	case 12442ULL: goto x86_l_309a;
	case 12447ULL: goto x86_l_309f;
	case 12451ULL: goto x86_l_30a3;
	case 12459ULL: goto x86_l_30ab;
	case 12465ULL: goto x86_l_30b1;
	case 12471ULL: goto x86_l_30b7;
	case 12475ULL: goto x86_l_30bb;
	case 12479ULL: goto x86_l_30bf;
	case 12485ULL: goto x86_l_30c5;
	case 12489ULL: goto x86_l_30c9;
	case 12493ULL: goto x86_l_30cd;
	case 12499ULL: goto x86_l_30d3;
	case 12503ULL: goto x86_l_30d7;
	case 12507ULL: goto x86_l_30db;
	case 12513ULL: goto x86_l_30e1;
	case 12517ULL: goto x86_l_30e5;
	case 12521ULL: goto x86_l_30e9;
	case 12527ULL: goto x86_l_30ef;
	case 12532ULL: goto x86_l_30f4;
	case 12537ULL: goto x86_l_30f9;
	case 12542ULL: goto x86_l_30fe;
	case 12545ULL: goto x86_l_3101;
	case 12550ULL: goto x86_l_3106;
	case 12552ULL: goto x86_l_3108;
	case 12555ULL: goto x86_l_310b;
	case 12561ULL: goto x86_l_3111;
	case 12565ULL: goto x86_l_3115;
	case 12569ULL: goto x86_l_3119;
	case 12573ULL: goto x86_l_311d;
	case 12577ULL: goto x86_l_3121;
	case 12581ULL: goto x86_l_3125;
	case 12585ULL: goto x86_l_3129;
	case 12589ULL: goto x86_l_312d;
	case 12593ULL: goto x86_l_3131;
	case 12596ULL: goto x86_l_3134;
	case 12599ULL: goto x86_l_3137;
	case 12601ULL: goto x86_l_3139;
	case 12604ULL: goto x86_l_313c;
	case 12606ULL: goto x86_l_313e;
	case 12610ULL: goto x86_l_3142;
	case 12614ULL: goto x86_l_3146;
	case 12617ULL: goto x86_l_3149;
	case 12622ULL: goto x86_l_314e;
	case 12626ULL: goto x86_l_3152;
	case 12632ULL: goto x86_l_3158;
	case 12642ULL: goto x86_l_3162;
	case 12647ULL: goto x86_l_3167;
	case 12657ULL: goto x86_l_3171;
	case 12662ULL: goto x86_l_3176;
	case 12672ULL: goto x86_l_3180;
	case 12677ULL: goto x86_l_3185;
	case 12687ULL: goto x86_l_318f;
	case 12692ULL: goto x86_l_3194;
	case 12702ULL: goto x86_l_319e;
	case 12707ULL: goto x86_l_31a3;
	case 12717ULL: goto x86_l_31ad;
	case 12722ULL: goto x86_l_31b2;
	case 12727ULL: goto x86_l_31b7;
	case 12732ULL: goto x86_l_31bc;
	case 12738ULL: goto x86_l_31c2;
	case 12742ULL: goto x86_l_31c6;
	case 12746ULL: goto x86_l_31ca;
	case 12749ULL: goto x86_l_31cd;
	case 12754ULL: goto x86_l_31d2;
	case 12757ULL: goto x86_l_31d5;
	case 12759ULL: goto x86_l_31d7;
	case 12762ULL: goto x86_l_31da;
	case 12770ULL: goto x86_l_31e2;
	case 12777ULL: goto x86_l_31e9;
	case 12782ULL: goto x86_l_31ee;
	case 12787ULL: goto x86_l_31f3;
	case 12789ULL: goto x86_l_31f5;
	case 12792ULL: goto x86_l_31f8;
	case 12794ULL: goto x86_l_31fa;
	case 12797ULL: goto x86_l_31fd;
	case 12799ULL: goto x86_l_31ff;
	case 12803ULL: goto x86_l_3203;
	case 12805ULL: goto x86_l_3205;
	case 12815ULL: goto x86_l_320f;
	case 12820ULL: goto x86_l_3214;
	case 12830ULL: goto x86_l_321e;
	case 12835ULL: goto x86_l_3223;
	case 12845ULL: goto x86_l_322d;
	case 12850ULL: goto x86_l_3232;
	case 12860ULL: goto x86_l_323c;
	case 12865ULL: goto x86_l_3241;
	case 12875ULL: goto x86_l_324b;
	case 12880ULL: goto x86_l_3250;
	case 12890ULL: goto x86_l_325a;
	case 12895ULL: goto x86_l_325f;
	case 12900ULL: goto x86_l_3264;
	case 12905ULL: goto x86_l_3269;
	case 12910ULL: goto x86_l_326e;
	case 12914ULL: goto x86_l_3272;
	case 12919ULL: goto x86_l_3277;
	case 12921ULL: goto x86_l_3279;
	case 12923ULL: goto x86_l_327b;
	case 12930ULL: goto x86_l_3282;
	case 12932ULL: goto x86_l_3284;
	case 12937ULL: goto x86_l_3289;
	case 12941ULL: goto x86_l_328d;
	case 12943ULL: goto x86_l_328f;
	case 12953ULL: goto x86_l_3299;
	case 12958ULL: goto x86_l_329e;
	case 12968ULL: goto x86_l_32a8;
	case 12973ULL: goto x86_l_32ad;
	case 12983ULL: goto x86_l_32b7;
	case 12988ULL: goto x86_l_32bc;
	case 12993ULL: goto x86_l_32c1;
	case 12998ULL: goto x86_l_32c6;
	case 13004ULL: goto x86_l_32cc;
	case 13009ULL: goto x86_l_32d1;
	case 13014ULL: goto x86_l_32d6;
	case 13017ULL: goto x86_l_32d9;
	case 13019ULL: goto x86_l_32db;
	case 13022ULL: goto x86_l_32de;
	case 13028ULL: goto x86_l_32e4;
	case 13032ULL: goto x86_l_32e8;
	case 13038ULL: goto x86_l_32ee;
	case 13041ULL: goto x86_l_32f1;
	case 13047ULL: goto x86_l_32f7;
	case 13051ULL: goto x86_l_32fb;
	case 13056ULL: goto x86_l_3300;
	case 13064ULL: goto x86_l_3308;
	case 13072ULL: goto x86_l_3310;
	case 13080ULL: goto x86_l_3318;
	case 13091ULL: goto x86_l_3323;
	case 13102ULL: goto x86_l_332e;
	case 13110ULL: goto x86_l_3336;
	case 13117ULL: goto x86_l_333d;
	case 13122ULL: goto x86_l_3342;
	case 13127ULL: goto x86_l_3347;
	case 13129ULL: goto x86_l_3349;
	case 13132ULL: goto x86_l_334c;
	case 13134ULL: goto x86_l_334e;
	case 13137ULL: goto x86_l_3351;
	case 13139ULL: goto x86_l_3353;
	case 13143ULL: goto x86_l_3357;
	case 13145ULL: goto x86_l_3359;
	case 13155ULL: goto x86_l_3363;
	case 13160ULL: goto x86_l_3368;
	case 13170ULL: goto x86_l_3372;
	case 13175ULL: goto x86_l_3377;
	case 13185ULL: goto x86_l_3381;
	case 13190ULL: goto x86_l_3386;
	case 13200ULL: goto x86_l_3390;
	case 13205ULL: goto x86_l_3395;
	case 13215ULL: goto x86_l_339f;
	case 13220ULL: goto x86_l_33a4;
	case 13230ULL: goto x86_l_33ae;
	case 13235ULL: goto x86_l_33b3;
	case 13240ULL: goto x86_l_33b8;
	case 13245ULL: goto x86_l_33bd;
	case 13250ULL: goto x86_l_33c2;
	case 13254ULL: goto x86_l_33c6;
	case 13259ULL: goto x86_l_33cb;
	case 13261ULL: goto x86_l_33cd;
	case 13263ULL: goto x86_l_33cf;
	case 13268ULL: goto x86_l_33d4;
	case 13274ULL: goto x86_l_33da;
	case 13277ULL: goto x86_l_33dd;
	case 13283ULL: goto x86_l_33e3;
	case 13289ULL: goto x86_l_33e9;
	case 13293ULL: goto x86_l_33ed;
	case 13297ULL: goto x86_l_33f1;
	case 13303ULL: goto x86_l_33f7;
	case 13307ULL: goto x86_l_33fb;
	case 13311ULL: goto x86_l_33ff;
	case 13317ULL: goto x86_l_3405;
	case 13321ULL: goto x86_l_3409;
	case 13325ULL: goto x86_l_340d;
	case 13331ULL: goto x86_l_3413;
	case 13335ULL: goto x86_l_3417;
	case 13339ULL: goto x86_l_341b;
	case 13345ULL: goto x86_l_3421;
	case 13350ULL: goto x86_l_3426;
	case 13355ULL: goto x86_l_342b;
	case 13360ULL: goto x86_l_3430;
	case 13365ULL: goto x86_l_3435;
	case 13370ULL: goto x86_l_343a;
	case 13372ULL: goto x86_l_343c;
	case 13375ULL: goto x86_l_343f;
	case 13381ULL: goto x86_l_3445;
	case 13385ULL: goto x86_l_3449;
	case 13389ULL: goto x86_l_344d;
	case 13394ULL: goto x86_l_3452;
	case 13398ULL: goto x86_l_3456;
	case 13403ULL: goto x86_l_345b;
	case 13407ULL: goto x86_l_345f;
	case 13411ULL: goto x86_l_3463;
	case 13415ULL: goto x86_l_3467;
	case 13418ULL: goto x86_l_346a;
	case 13420ULL: goto x86_l_346c;
	case 13425ULL: goto x86_l_3471;
	case 13431ULL: goto x86_l_3477;
	case 13435ULL: goto x86_l_347b;
	case 13439ULL: goto x86_l_347f;
	case 13443ULL: goto x86_l_3483;
	case 13445ULL: goto x86_l_3485;
	case 13450ULL: goto x86_l_348a;
	case 13454ULL: goto x86_l_348e;
	case 13458ULL: goto x86_l_3492;
	case 13462ULL: goto x86_l_3496;
	case 13467ULL: goto x86_l_349b;
	case 13470ULL: goto x86_l_349e;
	case 13477ULL: goto x86_l_34a5;
	case 13479ULL: goto x86_l_34a7;
	case 13486ULL: goto x86_l_34ae;
	case 13492ULL: goto x86_l_34b4;
	case 13496ULL: goto x86_l_34b8;
	case 13500ULL: goto x86_l_34bc;
	case 13504ULL: goto x86_l_34c0;
	case 13507ULL: goto x86_l_34c3;
	case 13510ULL: goto x86_l_34c6;
	case 13514ULL: goto x86_l_34ca;
	case 13516ULL: goto x86_l_34cc;
	case 13521ULL: goto x86_l_34d1;
	case 13525ULL: goto x86_l_34d5;
	case 13533ULL: goto x86_l_34dd;
	case 13539ULL: goto x86_l_34e3;
	case 13545ULL: goto x86_l_34e9;
	case 13549ULL: goto x86_l_34ed;
	case 13553ULL: goto x86_l_34f1;
	case 13559ULL: goto x86_l_34f7;
	case 13563ULL: goto x86_l_34fb;
	case 13567ULL: goto x86_l_34ff;
	case 13573ULL: goto x86_l_3505;
	case 13577ULL: goto x86_l_3509;
	case 13581ULL: goto x86_l_350d;
	case 13587ULL: goto x86_l_3513;
	case 13591ULL: goto x86_l_3517;
	case 13595ULL: goto x86_l_351b;
	case 13601ULL: goto x86_l_3521;
	case 13606ULL: goto x86_l_3526;
	case 13611ULL: goto x86_l_352b;
	case 13616ULL: goto x86_l_3530;
	case 13619ULL: goto x86_l_3533;
	case 13624ULL: goto x86_l_3538;
	case 13626ULL: goto x86_l_353a;
	case 13629ULL: goto x86_l_353d;
	case 13635ULL: goto x86_l_3543;
	case 13639ULL: goto x86_l_3547;
	case 13643ULL: goto x86_l_354b;
	case 13647ULL: goto x86_l_354f;
	case 13651ULL: goto x86_l_3553;
	case 13655ULL: goto x86_l_3557;
	case 13659ULL: goto x86_l_355b;
	case 13663ULL: goto x86_l_355f;
	case 13667ULL: goto x86_l_3563;
	case 13670ULL: goto x86_l_3566;
	case 13673ULL: goto x86_l_3569;
	case 13675ULL: goto x86_l_356b;
	case 13678ULL: goto x86_l_356e;
	case 13680ULL: goto x86_l_3570;
	case 13684ULL: goto x86_l_3574;
	case 13688ULL: goto x86_l_3578;
	case 13691ULL: goto x86_l_357b;
	case 13696ULL: goto x86_l_3580;
	case 13700ULL: goto x86_l_3584;
	case 13706ULL: goto x86_l_358a;
	case 13716ULL: goto x86_l_3594;
	case 13721ULL: goto x86_l_3599;
	case 13731ULL: goto x86_l_35a3;
	case 13736ULL: goto x86_l_35a8;
	case 13746ULL: goto x86_l_35b2;
	case 13751ULL: goto x86_l_35b7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2e54:
	/* 0x2e54: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e59:
	/* 0x2e59: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e5d:
	/* 0x2e5d: je     2eae <perf_unwind_python+0x2eae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2eae;
	}
x86_l_2e5f:
	/* 0x2e5f: movabs rax,0xa756c2520786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2943857106909292ULL);
x86_l_2e69:
	/* 0x2e69: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e6e:
	/* 0x2e6e: movabs rax,0x25206e6f68747950 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675259603430963536ULL);
x86_l_2e78:
	/* 0x2e78: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e7d:
	/* 0x2e7d: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_2e87:
	/* 0x2e87: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e8c:
	/* 0x2e8c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e91:
	/* 0x2e91: mov    eax,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_2e96:
	/* 0x2e96: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_2e9c:
	/* 0x2e9c: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_2ea1:
	/* 0x2ea1: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ea6:
	/* 0x2ea6: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_2ea9:
	/* 0x2ea9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2eab:
	/* 0x2eab: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2eae:
	/* 0x2eae: mov    eax,DWORD PTR [rbp+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_2eb4:
	/* 0x2eb4: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_2eb8:
	/* 0x2eb8: ja     176d <perf_unwind_python+0x176d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5997ULL;
	}
x86_l_2ebe:
	/* 0x2ebe: lea    ecx,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2ec1:
	/* 0x2ec1: mov    DWORD PTR [rbp+0x2c0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_2ec7:
	/* 0x2ec7: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2ecb:
	/* 0x2ecb: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ed0:
	/* 0x2ed0: mov    QWORD PTR [rbp+rax*8+0x2d0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_2ed8:
	/* 0x2ed8: mov    QWORD PTR [rbp+rax*8+0x2d8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_2ee0:
	/* 0x2ee0: mov    BYTE PTR [rbp+rax*8+0x2e0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929857ULL);
x86_l_2ee8:
	/* 0x2ee8: mov    DWORD PTR [rbp+rax*8+0x2e1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3165390897152ULL);
x86_l_2ef3:
	/* 0x2ef3: mov    DWORD PTR [rbp+rax*8+0x2e4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3178275799040ULL);
x86_l_2efe:
	/* 0x2efe: mov    DWORD PTR [rsp+0x18],0x16 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215126ULL);
x86_l_2f06:
	/* 0x2f06: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_2f0d:
	/* 0x2f0d: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f12:
	/* 0x2f12: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f17:
	/* 0x2f17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f19:
	/* 0x2f19: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f1c:
	/* 0x2f1c: je     2f23 <perf_unwind_python+0x2f23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f23;
	}
x86_l_2f1e:
	/* 0x2f1e: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2f21:
	/* 0x2f21: jmp    2f9f <perf_unwind_python+0x2f9f> */
	goto x86_l_2f9f;
x86_l_2f23:
	/* 0x2f23: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f27:
	/* 0x2f27: je     2f9f <perf_unwind_python+0x2f9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f9f;
	}
x86_l_2f29:
	/* 0x2f29: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_2f33:
	/* 0x2f33: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2f38:
	/* 0x2f38: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_2f42:
	/* 0x2f42: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2f47:
	/* 0x2f47: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_2f51:
	/* 0x2f51: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2f56:
	/* 0x2f56: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_2f60:
	/* 0x2f60: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f65:
	/* 0x2f65: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2f6f:
	/* 0x2f6f: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f74:
	/* 0x2f74: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2f7e:
	/* 0x2f7e: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f83:
	/* 0x2f83: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f88:
	/* 0x2f88: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2f8d:
	/* 0x2f8d: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2f92:
	/* 0x2f92: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f96:
	/* 0x2f96: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2f9b:
	/* 0x2f9b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f9d:
	/* 0x2f9d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2f9f:
	/* 0x2f9f: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_2fa2:
	/* 0x2fa2: jne    1242 <perf_unwind_python+0x1242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4674ULL;
	}
x86_l_2fa8:
	/* 0x2fa8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fab:
	/* 0x2fab: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2fae:
	/* 0x2fae: je     45b4 <perf_unwind_python+0x45b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17844ULL;
	}
x86_l_2fb4:
	/* 0x2fb4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fb8:
	/* 0x2fb8: cmp    BYTE PTR [rax+0x19],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 107374182520ULL);
x86_l_2fbc:
	/* 0x2fbc: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_2fc2:
	/* 0x2fc2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fc6:
	/* 0x2fc6: cmp    BYTE PTR [rax+0x18],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215224ULL);
x86_l_2fca:
	/* 0x2fca: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_2fd0:
	/* 0x2fd0: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fd4:
	/* 0x2fd4: cmp    BYTE PTR [rax+0x1a],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 111669149816ULL);
x86_l_2fd8:
	/* 0x2fd8: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_2fde:
	/* 0x2fde: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fe2:
	/* 0x2fe2: cmp    BYTE PTR [rax+0x1b],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 115964116992ULL);
x86_l_2fe6:
	/* 0x2fe6: js     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 17920ULL;
	}
x86_l_2fec:
	/* 0x2fec: mov    eax,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 128ULL);
x86_l_2ff1:
	/* 0x2ff1: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_2ff6:
	/* 0x2ff6: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2ffb:
	/* 0x2ffb: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_3000:
	/* 0x3000: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3003:
	/* 0x3003: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3005:
	/* 0x3005: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3008:
	/* 0x3008: jne    1d1d <perf_unwind_python+0x1d1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7453ULL;
	}
x86_l_300e:
	/* 0x300e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3012:
	/* 0x3012: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_3016:
	/* 0x3016: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_301b:
	/* 0x301b: mov    rcx,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_301f:
	/* 0x301f: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3024:
	/* 0x3024: movzx  ecx,BYTE PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_3028:
	/* 0x3028: mov    rcx,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_302c:
	/* 0x302c: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3031:
	/* 0x3031: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3035:
	/* 0x3035: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3038:
	/* 0x3038: je     3045 <perf_unwind_python+0x3045> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3045;
	}
x86_l_303a:
	/* 0x303a: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_303f:
	/* 0x303f: je     1d5a <perf_unwind_python+0x1d5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7514ULL;
	}
x86_l_3045:
	/* 0x3045: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3049:
	/* 0x3049: cmp    BYTE PTR [rax+0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_304d:
	/* 0x304d: movzx  eax,BYTE PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 26ULL);
x86_l_3051:
	/* 0x3051: je     309a <perf_unwind_python+0x309a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_309a;
	}
x86_l_3053:
	/* 0x3053: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3058:
	/* 0x3058: mov    rax,QWORD PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_305c:
	/* 0x305c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3060:
	/* 0x3060: movzx  edx,BYTE PTR [rcx+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_3064:
	/* 0x3064: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_3069:
	/* 0x3069: sub    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_306c:
	/* 0x306c: lea    rdx,[rax-0x10000001] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073441116159ULL);
x86_l_3073:
	/* 0x3073: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_3075:
	/* 0x3075: cmp    rdx,0xffffffffeffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073441116157ULL);
x86_l_307c:
	/* 0x307c: mov    r12d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_3082:
	/* 0x3082: cmovae r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_3086:
	/* 0x3086: movzx  eax,BYTE PTR [rcx+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_308a:
	/* 0x308a: movzx  eax,BYTE PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_308e:
	/* 0x308e: cmp    al,BYTE PTR [rcx+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_3091:
	/* 0x3091: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_3094:
	/* 0x3094: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3098:
	/* 0x3098: jmp    30ab <perf_unwind_python+0x30ab> */
	goto x86_l_30ab;
x86_l_309a:
	/* 0x309a: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_309f:
	/* 0x309f: mov    r12d,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_30a3:
	/* 0x30a3: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_30ab:
	/* 0x30ab: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_30b1:
	/* 0x30b1: je     314e <perf_unwind_python+0x314e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_314e;
	}
x86_l_30b7:
	/* 0x30b7: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30bb:
	/* 0x30bb: cmp    BYTE PTR [rax+0x1d],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051772ULL);
x86_l_30bf:
	/* 0x30bf: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_30c5:
	/* 0x30c5: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30c9:
	/* 0x30c9: cmp    BYTE PTR [rax+0x1e],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128849019068ULL);
x86_l_30cd:
	/* 0x30cd: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_30d3:
	/* 0x30d3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30d7:
	/* 0x30d7: cmp    BYTE PTR [rax+0x1f],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133143986364ULL);
x86_l_30db:
	/* 0x30db: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_30e1:
	/* 0x30e1: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30e5:
	/* 0x30e5: cmp    BYTE PTR [rax+0x20],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953660ULL);
x86_l_30e9:
	/* 0x30e9: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_30ef:
	/* 0x30ef: mov    eax,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 192ULL);
x86_l_30f4:
	/* 0x30f4: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_30f9:
	/* 0x30f9: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_30fe:
	/* 0x30fe: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3101:
	/* 0x3101: mov    esi,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 192ULL);
x86_l_3106:
	/* 0x3106: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3108:
	/* 0x3108: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_310b:
	/* 0x310b: jne    1e2c <perf_unwind_python+0x1e2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7724ULL;
	}
x86_l_3111:
	/* 0x3111: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3115:
	/* 0x3115: movzx  ecx,BYTE PTR [rax+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_3119:
	/* 0x3119: mov    ecx,DWORD PTR [r15+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_311d:
	/* 0x311d: movzx  edx,BYTE PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_3121:
	/* 0x3121: mov    edx,DWORD PTR [r15+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_3125:
	/* 0x3125: movzx  esi,BYTE PTR [rax+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_3129:
	/* 0x3129: mov    esi,DWORD PTR [r15+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_312d:
	/* 0x312d: movzx  eax,BYTE PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_3131:
	/* 0x3131: shl    ecx,0x19 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 25ULL);
x86_l_3134:
	/* 0x3134: shl    edx,0x12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 18ULL);
x86_l_3137:
	/* 0x3137: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3139:
	/* 0x3139: shl    esi,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 10ULL);
x86_l_313c:
	/* 0x313c: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_313e:
	/* 0x313e: add    esi,DWORD PTR [r15+rax*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R15, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3142:
	/* 0x3142: shl    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_3146:
	/* 0x3146: or     r12,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RSI, X86_WIDTH_64, X86_ALU_OR);
x86_l_3149:
	/* 0x3149: jmp    3289 <perf_unwind_python+0x3289> */
	goto x86_l_3289;
x86_l_314e:
	/* 0x314e: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3152:
	/* 0x3152: je     31da <perf_unwind_python+0x31da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31da;
	}
x86_l_3158:
	/* 0x3158: movabs rax,0xa786c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541280ULL);
x86_l_3162:
	/* 0x3162: mov    QWORD PTR [rsp+0x57],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_3167:
	/* 0x3167: movabs rax,0x20786c2578302074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2339738914604982388ULL);
x86_l_3171:
	/* 0x3171: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3176:
	/* 0x3176: movabs rax,0x63656a624f656d61 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7162247752874028385ULL);
x86_l_3180:
	/* 0x3180: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3185:
	/* 0x3185: movabs rax,0x7246795020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8234402353742245734ULL);
x86_l_318f:
	/* 0x318f: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3194:
	/* 0x3194: movabs rax,0x207463656a626f65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338603393739812709ULL);
x86_l_319e:
	/* 0x319e: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_31a3:
	/* 0x31a3: movabs rax,0x646f63206c6c754e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7237112117116826958ULL);
x86_l_31ad:
	/* 0x31ad: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31b2:
	/* 0x31b2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31b7:
	/* 0x31b7: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_31bc:
	/* 0x31bc: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_31c2:
	/* 0x31c2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31c6:
	/* 0x31c6: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_31ca:
	/* 0x31ca: add    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_31cd:
	/* 0x31cd: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_31d2:
	/* 0x31d2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_31d5:
	/* 0x31d5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31d7:
	/* 0x31d7: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_31da:
	/* 0x31da: mov    DWORD PTR [rsp+0x18],0x1c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215132ULL);
x86_l_31e2:
	/* 0x31e2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_31e9:
	/* 0x31e9: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31ee:
	/* 0x31ee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31f3:
	/* 0x31f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31f5:
	/* 0x31f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31f8:
	/* 0x31f8: je     31ff <perf_unwind_python+0x31ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31ff;
	}
x86_l_31fa:
	/* 0x31fa: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_31fd:
	/* 0x31fd: jmp    327b <perf_unwind_python+0x327b> */
	goto x86_l_327b;
x86_l_31ff:
	/* 0x31ff: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3203:
	/* 0x3203: je     327b <perf_unwind_python+0x327b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_327b;
	}
x86_l_3205:
	/* 0x3205: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_320f:
	/* 0x320f: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_3214:
	/* 0x3214: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_321e:
	/* 0x321e: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3223:
	/* 0x3223: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_322d:
	/* 0x322d: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3232:
	/* 0x3232: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_323c:
	/* 0x323c: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3241:
	/* 0x3241: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_324b:
	/* 0x324b: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3250:
	/* 0x3250: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_325a:
	/* 0x325a: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_325f:
	/* 0x325f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3264:
	/* 0x3264: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_3269:
	/* 0x3269: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_326e:
	/* 0x326e: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3272:
	/* 0x3272: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_3277:
	/* 0x3277: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3279:
	/* 0x3279: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_327b:
	/* 0x327b: mov    r12,0xfffffffffffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_3282:
	/* 0x3282: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3284:
	/* 0x3284: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3289:
	/* 0x3289: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_328d:
	/* 0x328d: je     32de <perf_unwind_python+0x32de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32de;
	}
x86_l_328f:
	/* 0x328f: movabs rax,0xa756c2520786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2943857106909292ULL);
x86_l_3299:
	/* 0x3299: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_329e:
	/* 0x329e: movabs rax,0x25206e6f68747950 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675259603430963536ULL);
x86_l_32a8:
	/* 0x32a8: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_32ad:
	/* 0x32ad: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_32b7:
	/* 0x32b7: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32bc:
	/* 0x32bc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32c1:
	/* 0x32c1: mov    eax,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_32c6:
	/* 0x32c6: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_32cc:
	/* 0x32cc: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_32d1:
	/* 0x32d1: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_32d6:
	/* 0x32d6: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_32d9:
	/* 0x32d9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32db:
	/* 0x32db: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_32de:
	/* 0x32de: mov    eax,DWORD PTR [rbp+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_32e4:
	/* 0x32e4: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_32e8:
	/* 0x32e8: ja     1f27 <perf_unwind_python+0x1f27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7975ULL;
	}
x86_l_32ee:
	/* 0x32ee: lea    ecx,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_32f1:
	/* 0x32f1: mov    DWORD PTR [rbp+0x2c0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_32f7:
	/* 0x32f7: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_32fb:
	/* 0x32fb: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3300:
	/* 0x3300: mov    QWORD PTR [rbp+rax*8+0x2d0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_3308:
	/* 0x3308: mov    QWORD PTR [rbp+rax*8+0x2d8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_3310:
	/* 0x3310: mov    BYTE PTR [rbp+rax*8+0x2e0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929857ULL);
x86_l_3318:
	/* 0x3318: mov    DWORD PTR [rbp+rax*8+0x2e1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3165390897152ULL);
x86_l_3323:
	/* 0x3323: mov    DWORD PTR [rbp+rax*8+0x2e4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3178275799040ULL);
x86_l_332e:
	/* 0x332e: mov    DWORD PTR [rsp+0x18],0x16 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215126ULL);
x86_l_3336:
	/* 0x3336: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_333d:
	/* 0x333d: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3342:
	/* 0x3342: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3347:
	/* 0x3347: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3349:
	/* 0x3349: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_334c:
	/* 0x334c: je     3353 <perf_unwind_python+0x3353> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3353;
	}
x86_l_334e:
	/* 0x334e: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3351:
	/* 0x3351: jmp    33cf <perf_unwind_python+0x33cf> */
	goto x86_l_33cf;
x86_l_3353:
	/* 0x3353: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3357:
	/* 0x3357: je     33cf <perf_unwind_python+0x33cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33cf;
	}
x86_l_3359:
	/* 0x3359: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_3363:
	/* 0x3363: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_3368:
	/* 0x3368: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_3372:
	/* 0x3372: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3377:
	/* 0x3377: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_3381:
	/* 0x3381: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3386:
	/* 0x3386: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_3390:
	/* 0x3390: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3395:
	/* 0x3395: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_339f:
	/* 0x339f: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_33a4:
	/* 0x33a4: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_33ae:
	/* 0x33ae: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_33b3:
	/* 0x33b3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_33b8:
	/* 0x33b8: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_33bd:
	/* 0x33bd: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_33c2:
	/* 0x33c2: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33c6:
	/* 0x33c6: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_33cb:
	/* 0x33cb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33cd:
	/* 0x33cd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_33cf:
	/* 0x33cf: cmp    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_33d4:
	/* 0x33d4: jne    1d5a <perf_unwind_python+0x1d5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7514ULL;
	}
x86_l_33da:
	/* 0x33da: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33dd:
	/* 0x33dd: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_33e3:
	/* 0x33e3: je     45b4 <perf_unwind_python+0x45b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17844ULL;
	}
x86_l_33e9:
	/* 0x33e9: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33ed:
	/* 0x33ed: cmp    BYTE PTR [rax+0x19],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 107374182520ULL);
x86_l_33f1:
	/* 0x33f1: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_33f7:
	/* 0x33f7: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33fb:
	/* 0x33fb: cmp    BYTE PTR [rax+0x18],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215224ULL);
x86_l_33ff:
	/* 0x33ff: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_3405:
	/* 0x3405: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3409:
	/* 0x3409: cmp    BYTE PTR [rax+0x1a],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 111669149816ULL);
x86_l_340d:
	/* 0x340d: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_3413:
	/* 0x3413: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3417:
	/* 0x3417: cmp    BYTE PTR [rax+0x1b],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 115964116992ULL);
x86_l_341b:
	/* 0x341b: js     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 17816ULL;
	}
x86_l_3421:
	/* 0x3421: mov    eax,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 128ULL);
x86_l_3426:
	/* 0x3426: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_342b:
	/* 0x342b: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3430:
	/* 0x3430: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3435:
	/* 0x3435: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_343a:
	/* 0x343a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_343c:
	/* 0x343c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_343f:
	/* 0x343f: jne    d56 <perf_unwind_python+0xd56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3414ULL;
	}
x86_l_3445:
	/* 0x3445: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3449:
	/* 0x3449: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_344d:
	/* 0x344d: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3452:
	/* 0x3452: mov    rcx,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3456:
	/* 0x3456: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_345b:
	/* 0x345b: movzx  ecx,BYTE PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_345f:
	/* 0x345f: mov    r13,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3463:
	/* 0x3463: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3467:
	/* 0x3467: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_346a:
	/* 0x346a: je     3477 <perf_unwind_python+0x3477> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3477;
	}
x86_l_346c:
	/* 0x346c: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3471:
	/* 0x3471: je     1242 <perf_unwind_python+0x1242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4674ULL;
	}
x86_l_3477:
	/* 0x3477: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_347b:
	/* 0x347b: cmp    BYTE PTR [rax+0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_347f:
	/* 0x347f: movzx  eax,BYTE PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 26ULL);
x86_l_3483:
	/* 0x3483: je     34cc <perf_unwind_python+0x34cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34cc;
	}
x86_l_3485:
	/* 0x3485: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_348a:
	/* 0x348a: mov    rax,QWORD PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_348e:
	/* 0x348e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3492:
	/* 0x3492: movzx  edx,BYTE PTR [rcx+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_3496:
	/* 0x3496: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_349b:
	/* 0x349b: sub    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_349e:
	/* 0x349e: lea    rdx,[rax-0x10000001] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073441116159ULL);
x86_l_34a5:
	/* 0x34a5: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_34a7:
	/* 0x34a7: cmp    rdx,0xffffffffeffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073441116157ULL);
x86_l_34ae:
	/* 0x34ae: mov    r12d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_34b4:
	/* 0x34b4: cmovae r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_34b8:
	/* 0x34b8: movzx  eax,BYTE PTR [rcx+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_34bc:
	/* 0x34bc: movzx  eax,BYTE PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_34c0:
	/* 0x34c0: cmp    al,BYTE PTR [rcx+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_34c3:
	/* 0x34c3: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_34c6:
	/* 0x34c6: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_34ca:
	/* 0x34ca: jmp    34dd <perf_unwind_python+0x34dd> */
	goto x86_l_34dd;
x86_l_34cc:
	/* 0x34cc: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_34d1:
	/* 0x34d1: mov    r12d,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_34d5:
	/* 0x34d5: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_34dd:
	/* 0x34dd: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_34e3:
	/* 0x34e3: je     3580 <perf_unwind_python+0x3580> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3580;
	}
x86_l_34e9:
	/* 0x34e9: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34ed:
	/* 0x34ed: cmp    BYTE PTR [rax+0x1d],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051772ULL);
x86_l_34f1:
	/* 0x34f1: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_34f7:
	/* 0x34f7: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34fb:
	/* 0x34fb: cmp    BYTE PTR [rax+0x1e],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128849019068ULL);
x86_l_34ff:
	/* 0x34ff: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_3505:
	/* 0x3505: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3509:
	/* 0x3509: cmp    BYTE PTR [rax+0x1f],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133143986364ULL);
x86_l_350d:
	/* 0x350d: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_3513:
	/* 0x3513: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3517:
	/* 0x3517: cmp    BYTE PTR [rax+0x20],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953660ULL);
x86_l_351b:
	/* 0x351b: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_3521:
	/* 0x3521: mov    eax,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 192ULL);
x86_l_3526:
	/* 0x3526: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_352b:
	/* 0x352b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3530:
	/* 0x3530: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3533:
	/* 0x3533: mov    esi,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 192ULL);
x86_l_3538:
	/* 0x3538: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_353a:
	/* 0x353a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_353d:
	/* 0x353d: jne    2b5 <perf_unwind_python+0x2b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 693ULL;
	}
x86_l_3543:
	/* 0x3543: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3547:
	/* 0x3547: movzx  ecx,BYTE PTR [rax+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_354b:
	/* 0x354b: mov    ecx,DWORD PTR [r15+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_354f:
	/* 0x354f: movzx  edx,BYTE PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_3553:
	/* 0x3553: mov    edx,DWORD PTR [r15+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_3557:
	/* 0x3557: movzx  esi,BYTE PTR [rax+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_355b:
	/* 0x355b: mov    esi,DWORD PTR [r15+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_355f:
	/* 0x355f: movzx  eax,BYTE PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_3563:
	/* 0x3563: shl    ecx,0x19 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 25ULL);
x86_l_3566:
	/* 0x3566: shl    edx,0x12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 18ULL);
x86_l_3569:
	/* 0x3569: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_356b:
	/* 0x356b: shl    esi,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 10ULL);
x86_l_356e:
	/* 0x356e: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3570:
	/* 0x3570: add    esi,DWORD PTR [r15+rax*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R15, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3574:
	/* 0x3574: shl    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_3578:
	/* 0x3578: or     r12,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RSI, X86_WIDTH_64, X86_ALU_OR);
x86_l_357b:
	/* 0x357b: jmp    36bd <perf_unwind_python+0x36bd> */
	return 14013ULL;
x86_l_3580:
	/* 0x3580: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3584:
	/* 0x3584: je     360e <perf_unwind_python+0x360e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13838ULL;
	}
x86_l_358a:
	/* 0x358a: movabs rax,0xa786c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541280ULL);
x86_l_3594:
	/* 0x3594: mov    QWORD PTR [rsp+0x57],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_3599:
	/* 0x3599: movabs rax,0x20786c2578302074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2339738914604982388ULL);
x86_l_35a3:
	/* 0x35a3: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_35a8:
	/* 0x35a8: movabs rax,0x63656a624f656d61 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7162247752874028385ULL);
x86_l_35b2:
	/* 0x35b2: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_35b7:
	/* 0x35b7: movabs rax,0x7246795020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8234402353742245734ULL);
	return 13761ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13761ULL: goto x86_l_35c1;
	case 13766ULL: goto x86_l_35c6;
	case 13776ULL: goto x86_l_35d0;
	case 13781ULL: goto x86_l_35d5;
	case 13791ULL: goto x86_l_35df;
	case 13796ULL: goto x86_l_35e4;
	case 13801ULL: goto x86_l_35e9;
	case 13806ULL: goto x86_l_35ee;
	case 13812ULL: goto x86_l_35f4;
	case 13816ULL: goto x86_l_35f8;
	case 13820ULL: goto x86_l_35fc;
	case 13825ULL: goto x86_l_3601;
	case 13828ULL: goto x86_l_3604;
	case 13833ULL: goto x86_l_3609;
	case 13835ULL: goto x86_l_360b;
	case 13838ULL: goto x86_l_360e;
	case 13846ULL: goto x86_l_3616;
	case 13853ULL: goto x86_l_361d;
	case 13858ULL: goto x86_l_3622;
	case 13863ULL: goto x86_l_3627;
	case 13865ULL: goto x86_l_3629;
	case 13868ULL: goto x86_l_362c;
	case 13870ULL: goto x86_l_362e;
	case 13873ULL: goto x86_l_3631;
	case 13875ULL: goto x86_l_3633;
	case 13879ULL: goto x86_l_3637;
	case 13881ULL: goto x86_l_3639;
	case 13891ULL: goto x86_l_3643;
	case 13896ULL: goto x86_l_3648;
	case 13906ULL: goto x86_l_3652;
	case 13911ULL: goto x86_l_3657;
	case 13921ULL: goto x86_l_3661;
	case 13926ULL: goto x86_l_3666;
	case 13936ULL: goto x86_l_3670;
	case 13941ULL: goto x86_l_3675;
	case 13951ULL: goto x86_l_367f;
	case 13956ULL: goto x86_l_3684;
	case 13966ULL: goto x86_l_368e;
	case 13971ULL: goto x86_l_3693;
	case 13976ULL: goto x86_l_3698;
	case 13981ULL: goto x86_l_369d;
	case 13986ULL: goto x86_l_36a2;
	case 13990ULL: goto x86_l_36a6;
	case 13995ULL: goto x86_l_36ab;
	case 13997ULL: goto x86_l_36ad;
	case 13999ULL: goto x86_l_36af;
	case 14006ULL: goto x86_l_36b6;
	case 14008ULL: goto x86_l_36b8;
	case 14013ULL: goto x86_l_36bd;
	case 14017ULL: goto x86_l_36c1;
	case 14019ULL: goto x86_l_36c3;
	case 14029ULL: goto x86_l_36cd;
	case 14034ULL: goto x86_l_36d2;
	case 14044ULL: goto x86_l_36dc;
	case 14049ULL: goto x86_l_36e1;
	case 14059ULL: goto x86_l_36eb;
	case 14064ULL: goto x86_l_36f0;
	case 14069ULL: goto x86_l_36f5;
	case 14074ULL: goto x86_l_36fa;
	case 14080ULL: goto x86_l_3700;
	case 14085ULL: goto x86_l_3705;
	case 14090ULL: goto x86_l_370a;
	case 14093ULL: goto x86_l_370d;
	case 14095ULL: goto x86_l_370f;
	case 14098ULL: goto x86_l_3712;
	case 14104ULL: goto x86_l_3718;
	case 14108ULL: goto x86_l_371c;
	case 14114ULL: goto x86_l_3722;
	case 14117ULL: goto x86_l_3725;
	case 14123ULL: goto x86_l_372b;
	case 14127ULL: goto x86_l_372f;
	case 14132ULL: goto x86_l_3734;
	case 14140ULL: goto x86_l_373c;
	case 14148ULL: goto x86_l_3744;
	case 14156ULL: goto x86_l_374c;
	case 14167ULL: goto x86_l_3757;
	case 14178ULL: goto x86_l_3762;
	case 14186ULL: goto x86_l_376a;
	case 14193ULL: goto x86_l_3771;
	case 14198ULL: goto x86_l_3776;
	case 14203ULL: goto x86_l_377b;
	case 14205ULL: goto x86_l_377d;
	case 14208ULL: goto x86_l_3780;
	case 14210ULL: goto x86_l_3782;
	case 14213ULL: goto x86_l_3785;
	case 14215ULL: goto x86_l_3787;
	case 14219ULL: goto x86_l_378b;
	case 14221ULL: goto x86_l_378d;
	case 14231ULL: goto x86_l_3797;
	case 14236ULL: goto x86_l_379c;
	case 14246ULL: goto x86_l_37a6;
	case 14251ULL: goto x86_l_37ab;
	case 14261ULL: goto x86_l_37b5;
	case 14266ULL: goto x86_l_37ba;
	case 14276ULL: goto x86_l_37c4;
	case 14281ULL: goto x86_l_37c9;
	case 14291ULL: goto x86_l_37d3;
	case 14296ULL: goto x86_l_37d8;
	case 14306ULL: goto x86_l_37e2;
	case 14311ULL: goto x86_l_37e7;
	case 14316ULL: goto x86_l_37ec;
	case 14321ULL: goto x86_l_37f1;
	case 14326ULL: goto x86_l_37f6;
	case 14330ULL: goto x86_l_37fa;
	case 14335ULL: goto x86_l_37ff;
	case 14337ULL: goto x86_l_3801;
	case 14339ULL: goto x86_l_3803;
	case 14344ULL: goto x86_l_3808;
	case 14350ULL: goto x86_l_380e;
	case 14353ULL: goto x86_l_3811;
	case 14356ULL: goto x86_l_3814;
	case 14362ULL: goto x86_l_381a;
	case 14366ULL: goto x86_l_381e;
	case 14370ULL: goto x86_l_3822;
	case 14376ULL: goto x86_l_3828;
	case 14380ULL: goto x86_l_382c;
	case 14384ULL: goto x86_l_3830;
	case 14390ULL: goto x86_l_3836;
	case 14394ULL: goto x86_l_383a;
	case 14398ULL: goto x86_l_383e;
	case 14404ULL: goto x86_l_3844;
	case 14408ULL: goto x86_l_3848;
	case 14412ULL: goto x86_l_384c;
	case 14418ULL: goto x86_l_3852;
	case 14423ULL: goto x86_l_3857;
	case 14428ULL: goto x86_l_385c;
	case 14433ULL: goto x86_l_3861;
	case 14438ULL: goto x86_l_3866;
	case 14441ULL: goto x86_l_3869;
	case 14443ULL: goto x86_l_386b;
	case 14446ULL: goto x86_l_386e;
	case 14452ULL: goto x86_l_3874;
	case 14456ULL: goto x86_l_3878;
	case 14460ULL: goto x86_l_387c;
	case 14465ULL: goto x86_l_3881;
	case 14469ULL: goto x86_l_3885;
	case 14474ULL: goto x86_l_388a;
	case 14478ULL: goto x86_l_388e;
	case 14482ULL: goto x86_l_3892;
	case 14487ULL: goto x86_l_3897;
	case 14491ULL: goto x86_l_389b;
	case 14494ULL: goto x86_l_389e;
	case 14496ULL: goto x86_l_38a0;
	case 14501ULL: goto x86_l_38a5;
	case 14507ULL: goto x86_l_38ab;
	case 14511ULL: goto x86_l_38af;
	case 14515ULL: goto x86_l_38b3;
	case 14519ULL: goto x86_l_38b7;
	case 14521ULL: goto x86_l_38b9;
	case 14526ULL: goto x86_l_38be;
	case 14530ULL: goto x86_l_38c2;
	case 14534ULL: goto x86_l_38c6;
	case 14538ULL: goto x86_l_38ca;
	case 14543ULL: goto x86_l_38cf;
	case 14546ULL: goto x86_l_38d2;
	case 14553ULL: goto x86_l_38d9;
	case 14555ULL: goto x86_l_38db;
	case 14562ULL: goto x86_l_38e2;
	case 14568ULL: goto x86_l_38e8;
	case 14572ULL: goto x86_l_38ec;
	case 14576ULL: goto x86_l_38f0;
	case 14580ULL: goto x86_l_38f4;
	case 14583ULL: goto x86_l_38f7;
	case 14586ULL: goto x86_l_38fa;
	case 14590ULL: goto x86_l_38fe;
	case 14592ULL: goto x86_l_3900;
	case 14597ULL: goto x86_l_3905;
	case 14601ULL: goto x86_l_3909;
	case 14609ULL: goto x86_l_3911;
	case 14615ULL: goto x86_l_3917;
	case 14621ULL: goto x86_l_391d;
	case 14625ULL: goto x86_l_3921;
	case 14629ULL: goto x86_l_3925;
	case 14635ULL: goto x86_l_392b;
	case 14639ULL: goto x86_l_392f;
	case 14643ULL: goto x86_l_3933;
	case 14649ULL: goto x86_l_3939;
	case 14653ULL: goto x86_l_393d;
	case 14657ULL: goto x86_l_3941;
	case 14663ULL: goto x86_l_3947;
	case 14667ULL: goto x86_l_394b;
	case 14671ULL: goto x86_l_394f;
	case 14677ULL: goto x86_l_3955;
	case 14682ULL: goto x86_l_395a;
	case 14687ULL: goto x86_l_395f;
	case 14692ULL: goto x86_l_3964;
	case 14695ULL: goto x86_l_3967;
	case 14700ULL: goto x86_l_396c;
	case 14702ULL: goto x86_l_396e;
	case 14705ULL: goto x86_l_3971;
	case 14711ULL: goto x86_l_3977;
	case 14715ULL: goto x86_l_397b;
	case 14719ULL: goto x86_l_397f;
	case 14723ULL: goto x86_l_3983;
	case 14727ULL: goto x86_l_3987;
	case 14731ULL: goto x86_l_398b;
	case 14735ULL: goto x86_l_398f;
	case 14739ULL: goto x86_l_3993;
	case 14743ULL: goto x86_l_3997;
	case 14746ULL: goto x86_l_399a;
	case 14749ULL: goto x86_l_399d;
	case 14751ULL: goto x86_l_399f;
	case 14754ULL: goto x86_l_39a2;
	case 14756ULL: goto x86_l_39a4;
	case 14760ULL: goto x86_l_39a8;
	case 14764ULL: goto x86_l_39ac;
	case 14767ULL: goto x86_l_39af;
	case 14772ULL: goto x86_l_39b4;
	case 14776ULL: goto x86_l_39b8;
	case 14782ULL: goto x86_l_39be;
	case 14792ULL: goto x86_l_39c8;
	case 14797ULL: goto x86_l_39cd;
	case 14807ULL: goto x86_l_39d7;
	case 14812ULL: goto x86_l_39dc;
	case 14822ULL: goto x86_l_39e6;
	case 14827ULL: goto x86_l_39eb;
	case 14837ULL: goto x86_l_39f5;
	case 14842ULL: goto x86_l_39fa;
	case 14852ULL: goto x86_l_3a04;
	case 14857ULL: goto x86_l_3a09;
	case 14867ULL: goto x86_l_3a13;
	case 14872ULL: goto x86_l_3a18;
	case 14877ULL: goto x86_l_3a1d;
	case 14882ULL: goto x86_l_3a22;
	case 14888ULL: goto x86_l_3a28;
	case 14892ULL: goto x86_l_3a2c;
	case 14896ULL: goto x86_l_3a30;
	case 14899ULL: goto x86_l_3a33;
	case 14904ULL: goto x86_l_3a38;
	case 14907ULL: goto x86_l_3a3b;
	case 14909ULL: goto x86_l_3a3d;
	case 14912ULL: goto x86_l_3a40;
	case 14920ULL: goto x86_l_3a48;
	case 14927ULL: goto x86_l_3a4f;
	case 14932ULL: goto x86_l_3a54;
	case 14937ULL: goto x86_l_3a59;
	case 14939ULL: goto x86_l_3a5b;
	case 14942ULL: goto x86_l_3a5e;
	case 14944ULL: goto x86_l_3a60;
	case 14947ULL: goto x86_l_3a63;
	case 14949ULL: goto x86_l_3a65;
	case 14953ULL: goto x86_l_3a69;
	case 14955ULL: goto x86_l_3a6b;
	case 14965ULL: goto x86_l_3a75;
	case 14970ULL: goto x86_l_3a7a;
	case 14980ULL: goto x86_l_3a84;
	case 14985ULL: goto x86_l_3a89;
	case 14995ULL: goto x86_l_3a93;
	case 15000ULL: goto x86_l_3a98;
	case 15010ULL: goto x86_l_3aa2;
	case 15015ULL: goto x86_l_3aa7;
	case 15025ULL: goto x86_l_3ab1;
	case 15030ULL: goto x86_l_3ab6;
	case 15040ULL: goto x86_l_3ac0;
	case 15045ULL: goto x86_l_3ac5;
	case 15050ULL: goto x86_l_3aca;
	case 15055ULL: goto x86_l_3acf;
	case 15060ULL: goto x86_l_3ad4;
	case 15064ULL: goto x86_l_3ad8;
	case 15069ULL: goto x86_l_3add;
	case 15071ULL: goto x86_l_3adf;
	case 15073ULL: goto x86_l_3ae1;
	case 15080ULL: goto x86_l_3ae8;
	case 15082ULL: goto x86_l_3aea;
	case 15087ULL: goto x86_l_3aef;
	case 15091ULL: goto x86_l_3af3;
	case 15093ULL: goto x86_l_3af5;
	case 15103ULL: goto x86_l_3aff;
	case 15108ULL: goto x86_l_3b04;
	case 15118ULL: goto x86_l_3b0e;
	case 15123ULL: goto x86_l_3b13;
	case 15133ULL: goto x86_l_3b1d;
	case 15138ULL: goto x86_l_3b22;
	case 15143ULL: goto x86_l_3b27;
	case 15148ULL: goto x86_l_3b2c;
	case 15154ULL: goto x86_l_3b32;
	case 15159ULL: goto x86_l_3b37;
	case 15164ULL: goto x86_l_3b3c;
	case 15167ULL: goto x86_l_3b3f;
	case 15169ULL: goto x86_l_3b41;
	case 15172ULL: goto x86_l_3b44;
	case 15178ULL: goto x86_l_3b4a;
	case 15182ULL: goto x86_l_3b4e;
	case 15188ULL: goto x86_l_3b54;
	case 15191ULL: goto x86_l_3b57;
	case 15197ULL: goto x86_l_3b5d;
	case 15201ULL: goto x86_l_3b61;
	case 15206ULL: goto x86_l_3b66;
	case 15214ULL: goto x86_l_3b6e;
	case 15222ULL: goto x86_l_3b76;
	case 15230ULL: goto x86_l_3b7e;
	case 15241ULL: goto x86_l_3b89;
	case 15252ULL: goto x86_l_3b94;
	case 15260ULL: goto x86_l_3b9c;
	case 15267ULL: goto x86_l_3ba3;
	case 15272ULL: goto x86_l_3ba8;
	case 15277ULL: goto x86_l_3bad;
	case 15279ULL: goto x86_l_3baf;
	case 15282ULL: goto x86_l_3bb2;
	case 15284ULL: goto x86_l_3bb4;
	case 15287ULL: goto x86_l_3bb7;
	case 15289ULL: goto x86_l_3bb9;
	case 15293ULL: goto x86_l_3bbd;
	case 15295ULL: goto x86_l_3bbf;
	case 15305ULL: goto x86_l_3bc9;
	case 15310ULL: goto x86_l_3bce;
	case 15320ULL: goto x86_l_3bd8;
	case 15325ULL: goto x86_l_3bdd;
	case 15335ULL: goto x86_l_3be7;
	case 15340ULL: goto x86_l_3bec;
	case 15350ULL: goto x86_l_3bf6;
	case 15355ULL: goto x86_l_3bfb;
	case 15365ULL: goto x86_l_3c05;
	case 15370ULL: goto x86_l_3c0a;
	case 15380ULL: goto x86_l_3c14;
	case 15385ULL: goto x86_l_3c19;
	case 15390ULL: goto x86_l_3c1e;
	case 15395ULL: goto x86_l_3c23;
	case 15400ULL: goto x86_l_3c28;
	case 15404ULL: goto x86_l_3c2c;
	case 15409ULL: goto x86_l_3c31;
	case 15411ULL: goto x86_l_3c33;
	case 15413ULL: goto x86_l_3c35;
	case 15418ULL: goto x86_l_3c3a;
	case 15424ULL: goto x86_l_3c40;
	case 15427ULL: goto x86_l_3c43;
	case 15433ULL: goto x86_l_3c49;
	case 15439ULL: goto x86_l_3c4f;
	case 15443ULL: goto x86_l_3c53;
	case 15447ULL: goto x86_l_3c57;
	case 15453ULL: goto x86_l_3c5d;
	case 15457ULL: goto x86_l_3c61;
	case 15461ULL: goto x86_l_3c65;
	case 15467ULL: goto x86_l_3c6b;
	case 15471ULL: goto x86_l_3c6f;
	case 15475ULL: goto x86_l_3c73;
	case 15481ULL: goto x86_l_3c79;
	case 15485ULL: goto x86_l_3c7d;
	case 15489ULL: goto x86_l_3c81;
	case 15495ULL: goto x86_l_3c87;
	case 15500ULL: goto x86_l_3c8c;
	case 15505ULL: goto x86_l_3c91;
	case 15510ULL: goto x86_l_3c96;
	case 15515ULL: goto x86_l_3c9b;
	case 15520ULL: goto x86_l_3ca0;
	case 15522ULL: goto x86_l_3ca2;
	case 15525ULL: goto x86_l_3ca5;
	case 15531ULL: goto x86_l_3cab;
	case 15535ULL: goto x86_l_3caf;
	case 15539ULL: goto x86_l_3cb3;
	case 15544ULL: goto x86_l_3cb8;
	case 15548ULL: goto x86_l_3cbc;
	case 15553ULL: goto x86_l_3cc1;
	case 15557ULL: goto x86_l_3cc5;
	case 15561ULL: goto x86_l_3cc9;
	case 15565ULL: goto x86_l_3ccd;
	case 15568ULL: goto x86_l_3cd0;
	case 15570ULL: goto x86_l_3cd2;
	case 15575ULL: goto x86_l_3cd7;
	case 15581ULL: goto x86_l_3cdd;
	case 15585ULL: goto x86_l_3ce1;
	case 15589ULL: goto x86_l_3ce5;
	case 15593ULL: goto x86_l_3ce9;
	case 15595ULL: goto x86_l_3ceb;
	case 15600ULL: goto x86_l_3cf0;
	case 15604ULL: goto x86_l_3cf4;
	case 15608ULL: goto x86_l_3cf8;
	case 15612ULL: goto x86_l_3cfc;
	case 15617ULL: goto x86_l_3d01;
	case 15620ULL: goto x86_l_3d04;
	case 15627ULL: goto x86_l_3d0b;
	case 15629ULL: goto x86_l_3d0d;
	case 15636ULL: goto x86_l_3d14;
	case 15642ULL: goto x86_l_3d1a;
	case 15646ULL: goto x86_l_3d1e;
	case 15650ULL: goto x86_l_3d22;
	case 15654ULL: goto x86_l_3d26;
	case 15657ULL: goto x86_l_3d29;
	case 15660ULL: goto x86_l_3d2c;
	case 15664ULL: goto x86_l_3d30;
	case 15666ULL: goto x86_l_3d32;
	case 15671ULL: goto x86_l_3d37;
	case 15675ULL: goto x86_l_3d3b;
	case 15683ULL: goto x86_l_3d43;
	default: return 0xffffffffffffffffULL;
	}
x86_l_35c1:
	/* 0x35c1: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_35c6:
	/* 0x35c6: movabs rax,0x207463656a626f65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338603393739812709ULL);
x86_l_35d0:
	/* 0x35d0: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_35d5:
	/* 0x35d5: movabs rax,0x646f63206c6c754e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7237112117116826958ULL);
x86_l_35df:
	/* 0x35df: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_35e4:
	/* 0x35e4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_35e9:
	/* 0x35e9: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_35ee:
	/* 0x35ee: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_35f4:
	/* 0x35f4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35f8:
	/* 0x35f8: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_35fc:
	/* 0x35fc: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3601:
	/* 0x3601: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3604:
	/* 0x3604: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_3609:
	/* 0x3609: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_360b:
	/* 0x360b: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_360e:
	/* 0x360e: mov    DWORD PTR [rsp+0x18],0x1c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215132ULL);
x86_l_3616:
	/* 0x3616: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_361d:
	/* 0x361d: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3622:
	/* 0x3622: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3627:
	/* 0x3627: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3629:
	/* 0x3629: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_362c:
	/* 0x362c: je     3633 <perf_unwind_python+0x3633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3633;
	}
x86_l_362e:
	/* 0x362e: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3631:
	/* 0x3631: jmp    36af <perf_unwind_python+0x36af> */
	goto x86_l_36af;
x86_l_3633:
	/* 0x3633: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3637:
	/* 0x3637: je     36af <perf_unwind_python+0x36af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36af;
	}
x86_l_3639:
	/* 0x3639: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_3643:
	/* 0x3643: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_3648:
	/* 0x3648: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_3652:
	/* 0x3652: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3657:
	/* 0x3657: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_3661:
	/* 0x3661: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3666:
	/* 0x3666: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_3670:
	/* 0x3670: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3675:
	/* 0x3675: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_367f:
	/* 0x367f: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3684:
	/* 0x3684: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_368e:
	/* 0x368e: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3693:
	/* 0x3693: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3698:
	/* 0x3698: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_369d:
	/* 0x369d: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_36a2:
	/* 0x36a2: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_36a6:
	/* 0x36a6: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_36ab:
	/* 0x36ab: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36ad:
	/* 0x36ad: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_36af:
	/* 0x36af: mov    r12,0xfffffffffffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_36b6:
	/* 0x36b6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36b8:
	/* 0x36b8: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_36bd:
	/* 0x36bd: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36c1:
	/* 0x36c1: je     3712 <perf_unwind_python+0x3712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3712;
	}
x86_l_36c3:
	/* 0x36c3: movabs rax,0xa756c2520786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2943857106909292ULL);
x86_l_36cd:
	/* 0x36cd: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_36d2:
	/* 0x36d2: movabs rax,0x25206e6f68747950 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675259603430963536ULL);
x86_l_36dc:
	/* 0x36dc: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_36e1:
	/* 0x36e1: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_36eb:
	/* 0x36eb: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_36f0:
	/* 0x36f0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_36f5:
	/* 0x36f5: mov    eax,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_36fa:
	/* 0x36fa: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_3700:
	/* 0x3700: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_3705:
	/* 0x3705: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_370a:
	/* 0x370a: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_370d:
	/* 0x370d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_370f:
	/* 0x370f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3712:
	/* 0x3712: mov    eax,DWORD PTR [rbp+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3718:
	/* 0x3718: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_371c:
	/* 0x371c: ja     176d <perf_unwind_python+0x176d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5997ULL;
	}
x86_l_3722:
	/* 0x3722: lea    ecx,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3725:
	/* 0x3725: mov    DWORD PTR [rbp+0x2c0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_372b:
	/* 0x372b: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_372f:
	/* 0x372f: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3734:
	/* 0x3734: mov    QWORD PTR [rbp+rax*8+0x2d0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_373c:
	/* 0x373c: mov    QWORD PTR [rbp+rax*8+0x2d8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_3744:
	/* 0x3744: mov    BYTE PTR [rbp+rax*8+0x2e0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929857ULL);
x86_l_374c:
	/* 0x374c: mov    DWORD PTR [rbp+rax*8+0x2e1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3165390897152ULL);
x86_l_3757:
	/* 0x3757: mov    DWORD PTR [rbp+rax*8+0x2e4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3178275799040ULL);
x86_l_3762:
	/* 0x3762: mov    DWORD PTR [rsp+0x18],0x16 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215126ULL);
x86_l_376a:
	/* 0x376a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_3771:
	/* 0x3771: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3776:
	/* 0x3776: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_377b:
	/* 0x377b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_377d:
	/* 0x377d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3780:
	/* 0x3780: je     3787 <perf_unwind_python+0x3787> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3787;
	}
x86_l_3782:
	/* 0x3782: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3785:
	/* 0x3785: jmp    3803 <perf_unwind_python+0x3803> */
	goto x86_l_3803;
x86_l_3787:
	/* 0x3787: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_378b:
	/* 0x378b: je     3803 <perf_unwind_python+0x3803> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3803;
	}
x86_l_378d:
	/* 0x378d: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_3797:
	/* 0x3797: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_379c:
	/* 0x379c: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_37a6:
	/* 0x37a6: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_37ab:
	/* 0x37ab: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_37b5:
	/* 0x37b5: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_37ba:
	/* 0x37ba: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_37c4:
	/* 0x37c4: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_37c9:
	/* 0x37c9: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_37d3:
	/* 0x37d3: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_37d8:
	/* 0x37d8: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_37e2:
	/* 0x37e2: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_37e7:
	/* 0x37e7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_37ec:
	/* 0x37ec: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_37f1:
	/* 0x37f1: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_37f6:
	/* 0x37f6: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_37fa:
	/* 0x37fa: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_37ff:
	/* 0x37ff: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3801:
	/* 0x3801: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3803:
	/* 0x3803: cmp    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_3808:
	/* 0x3808: jne    1242 <perf_unwind_python+0x1242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4674ULL;
	}
x86_l_380e:
	/* 0x380e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3811:
	/* 0x3811: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_3814:
	/* 0x3814: je     45b4 <perf_unwind_python+0x45b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17844ULL;
	}
x86_l_381a:
	/* 0x381a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_381e:
	/* 0x381e: cmp    BYTE PTR [rax+0x19],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 107374182520ULL);
x86_l_3822:
	/* 0x3822: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_3828:
	/* 0x3828: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_382c:
	/* 0x382c: cmp    BYTE PTR [rax+0x18],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215224ULL);
x86_l_3830:
	/* 0x3830: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_3836:
	/* 0x3836: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_383a:
	/* 0x383a: cmp    BYTE PTR [rax+0x1a],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 111669149816ULL);
x86_l_383e:
	/* 0x383e: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_3844:
	/* 0x3844: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3848:
	/* 0x3848: cmp    BYTE PTR [rax+0x1b],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 115964116992ULL);
x86_l_384c:
	/* 0x384c: js     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 17920ULL;
	}
x86_l_3852:
	/* 0x3852: mov    eax,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 128ULL);
x86_l_3857:
	/* 0x3857: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_385c:
	/* 0x385c: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3861:
	/* 0x3861: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_3866:
	/* 0x3866: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3869:
	/* 0x3869: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_386b:
	/* 0x386b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_386e:
	/* 0x386e: jne    1d1d <perf_unwind_python+0x1d1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7453ULL;
	}
x86_l_3874:
	/* 0x3874: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3878:
	/* 0x3878: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_387c:
	/* 0x387c: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3881:
	/* 0x3881: mov    rcx,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3885:
	/* 0x3885: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_388a:
	/* 0x388a: movzx  ecx,BYTE PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_388e:
	/* 0x388e: mov    rcx,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3892:
	/* 0x3892: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3897:
	/* 0x3897: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_389b:
	/* 0x389b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_389e:
	/* 0x389e: je     38ab <perf_unwind_python+0x38ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38ab;
	}
x86_l_38a0:
	/* 0x38a0: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_38a5:
	/* 0x38a5: je     1d5a <perf_unwind_python+0x1d5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7514ULL;
	}
x86_l_38ab:
	/* 0x38ab: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38af:
	/* 0x38af: cmp    BYTE PTR [rax+0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_38b3:
	/* 0x38b3: movzx  eax,BYTE PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 26ULL);
x86_l_38b7:
	/* 0x38b7: je     3900 <perf_unwind_python+0x3900> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3900;
	}
x86_l_38b9:
	/* 0x38b9: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_38be:
	/* 0x38be: mov    rax,QWORD PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_38c2:
	/* 0x38c2: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38c6:
	/* 0x38c6: movzx  edx,BYTE PTR [rcx+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_38ca:
	/* 0x38ca: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_38cf:
	/* 0x38cf: sub    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_38d2:
	/* 0x38d2: lea    rdx,[rax-0x10000001] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073441116159ULL);
x86_l_38d9:
	/* 0x38d9: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_38db:
	/* 0x38db: cmp    rdx,0xffffffffeffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073441116157ULL);
x86_l_38e2:
	/* 0x38e2: mov    r12d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_38e8:
	/* 0x38e8: cmovae r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_38ec:
	/* 0x38ec: movzx  eax,BYTE PTR [rcx+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_38f0:
	/* 0x38f0: movzx  eax,BYTE PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_38f4:
	/* 0x38f4: cmp    al,BYTE PTR [rcx+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_38f7:
	/* 0x38f7: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_38fa:
	/* 0x38fa: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_38fe:
	/* 0x38fe: jmp    3911 <perf_unwind_python+0x3911> */
	goto x86_l_3911;
x86_l_3900:
	/* 0x3900: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3905:
	/* 0x3905: mov    r12d,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3909:
	/* 0x3909: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_3911:
	/* 0x3911: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3917:
	/* 0x3917: je     39b4 <perf_unwind_python+0x39b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39b4;
	}
x86_l_391d:
	/* 0x391d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3921:
	/* 0x3921: cmp    BYTE PTR [rax+0x1d],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051772ULL);
x86_l_3925:
	/* 0x3925: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_392b:
	/* 0x392b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_392f:
	/* 0x392f: cmp    BYTE PTR [rax+0x1e],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128849019068ULL);
x86_l_3933:
	/* 0x3933: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_3939:
	/* 0x3939: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_393d:
	/* 0x393d: cmp    BYTE PTR [rax+0x1f],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133143986364ULL);
x86_l_3941:
	/* 0x3941: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_3947:
	/* 0x3947: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_394b:
	/* 0x394b: cmp    BYTE PTR [rax+0x20],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953660ULL);
x86_l_394f:
	/* 0x394f: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_3955:
	/* 0x3955: mov    eax,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 192ULL);
x86_l_395a:
	/* 0x395a: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_395f:
	/* 0x395f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3964:
	/* 0x3964: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3967:
	/* 0x3967: mov    esi,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 192ULL);
x86_l_396c:
	/* 0x396c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_396e:
	/* 0x396e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3971:
	/* 0x3971: jne    1e2c <perf_unwind_python+0x1e2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7724ULL;
	}
x86_l_3977:
	/* 0x3977: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_397b:
	/* 0x397b: movzx  ecx,BYTE PTR [rax+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_397f:
	/* 0x397f: mov    ecx,DWORD PTR [r15+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3983:
	/* 0x3983: movzx  edx,BYTE PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_3987:
	/* 0x3987: mov    edx,DWORD PTR [r15+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_398b:
	/* 0x398b: movzx  esi,BYTE PTR [rax+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_398f:
	/* 0x398f: mov    esi,DWORD PTR [r15+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_3993:
	/* 0x3993: movzx  eax,BYTE PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_3997:
	/* 0x3997: shl    ecx,0x19 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 25ULL);
x86_l_399a:
	/* 0x399a: shl    edx,0x12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 18ULL);
x86_l_399d:
	/* 0x399d: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_399f:
	/* 0x399f: shl    esi,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 10ULL);
x86_l_39a2:
	/* 0x39a2: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_39a4:
	/* 0x39a4: add    esi,DWORD PTR [r15+rax*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R15, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_39a8:
	/* 0x39a8: shl    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_39ac:
	/* 0x39ac: or     r12,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RSI, X86_WIDTH_64, X86_ALU_OR);
x86_l_39af:
	/* 0x39af: jmp    3aef <perf_unwind_python+0x3aef> */
	goto x86_l_3aef;
x86_l_39b4:
	/* 0x39b4: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39b8:
	/* 0x39b8: je     3a40 <perf_unwind_python+0x3a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a40;
	}
x86_l_39be:
	/* 0x39be: movabs rax,0xa786c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541280ULL);
x86_l_39c8:
	/* 0x39c8: mov    QWORD PTR [rsp+0x57],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_39cd:
	/* 0x39cd: movabs rax,0x20786c2578302074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2339738914604982388ULL);
x86_l_39d7:
	/* 0x39d7: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_39dc:
	/* 0x39dc: movabs rax,0x63656a624f656d61 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7162247752874028385ULL);
x86_l_39e6:
	/* 0x39e6: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_39eb:
	/* 0x39eb: movabs rax,0x7246795020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8234402353742245734ULL);
x86_l_39f5:
	/* 0x39f5: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_39fa:
	/* 0x39fa: movabs rax,0x207463656a626f65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338603393739812709ULL);
x86_l_3a04:
	/* 0x3a04: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3a09:
	/* 0x3a09: movabs rax,0x646f63206c6c754e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7237112117116826958ULL);
x86_l_3a13:
	/* 0x3a13: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3a18:
	/* 0x3a18: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3a1d:
	/* 0x3a1d: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_3a22:
	/* 0x3a22: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_3a28:
	/* 0x3a28: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a2c:
	/* 0x3a2c: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_3a30:
	/* 0x3a30: add    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3a33:
	/* 0x3a33: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_3a38:
	/* 0x3a38: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3a3b:
	/* 0x3a3b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3a3d:
	/* 0x3a3d: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3a40:
	/* 0x3a40: mov    DWORD PTR [rsp+0x18],0x1c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215132ULL);
x86_l_3a48:
	/* 0x3a48: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_3a4f:
	/* 0x3a4f: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a54:
	/* 0x3a54: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3a59:
	/* 0x3a59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a5b:
	/* 0x3a5b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a5e:
	/* 0x3a5e: je     3a65 <perf_unwind_python+0x3a65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a65;
	}
x86_l_3a60:
	/* 0x3a60: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3a63:
	/* 0x3a63: jmp    3ae1 <perf_unwind_python+0x3ae1> */
	goto x86_l_3ae1;
x86_l_3a65:
	/* 0x3a65: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a69:
	/* 0x3a69: je     3ae1 <perf_unwind_python+0x3ae1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ae1;
	}
x86_l_3a6b:
	/* 0x3a6b: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_3a75:
	/* 0x3a75: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_3a7a:
	/* 0x3a7a: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_3a84:
	/* 0x3a84: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3a89:
	/* 0x3a89: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_3a93:
	/* 0x3a93: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3a98:
	/* 0x3a98: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_3aa2:
	/* 0x3aa2: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3aa7:
	/* 0x3aa7: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_3ab1:
	/* 0x3ab1: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3ab6:
	/* 0x3ab6: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_3ac0:
	/* 0x3ac0: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ac5:
	/* 0x3ac5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3aca:
	/* 0x3aca: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_3acf:
	/* 0x3acf: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3ad4:
	/* 0x3ad4: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ad8:
	/* 0x3ad8: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_3add:
	/* 0x3add: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3adf:
	/* 0x3adf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3ae1:
	/* 0x3ae1: mov    r12,0xfffffffffffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_3ae8:
	/* 0x3ae8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3aea:
	/* 0x3aea: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3aef:
	/* 0x3aef: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3af3:
	/* 0x3af3: je     3b44 <perf_unwind_python+0x3b44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b44;
	}
x86_l_3af5:
	/* 0x3af5: movabs rax,0xa756c2520786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2943857106909292ULL);
x86_l_3aff:
	/* 0x3aff: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3b04:
	/* 0x3b04: movabs rax,0x25206e6f68747950 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675259603430963536ULL);
x86_l_3b0e:
	/* 0x3b0e: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3b13:
	/* 0x3b13: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_3b1d:
	/* 0x3b1d: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b22:
	/* 0x3b22: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b27:
	/* 0x3b27: mov    eax,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_3b2c:
	/* 0x3b2c: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_3b32:
	/* 0x3b32: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_3b37:
	/* 0x3b37: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3b3c:
	/* 0x3b3c: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_3b3f:
	/* 0x3b3f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b41:
	/* 0x3b41: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3b44:
	/* 0x3b44: mov    eax,DWORD PTR [rbp+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3b4a:
	/* 0x3b4a: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_3b4e:
	/* 0x3b4e: ja     1f27 <perf_unwind_python+0x1f27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7975ULL;
	}
x86_l_3b54:
	/* 0x3b54: lea    ecx,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3b57:
	/* 0x3b57: mov    DWORD PTR [rbp+0x2c0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3b5d:
	/* 0x3b5d: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_3b61:
	/* 0x3b61: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3b66:
	/* 0x3b66: mov    QWORD PTR [rbp+rax*8+0x2d0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_3b6e:
	/* 0x3b6e: mov    QWORD PTR [rbp+rax*8+0x2d8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_3b76:
	/* 0x3b76: mov    BYTE PTR [rbp+rax*8+0x2e0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929857ULL);
x86_l_3b7e:
	/* 0x3b7e: mov    DWORD PTR [rbp+rax*8+0x2e1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3165390897152ULL);
x86_l_3b89:
	/* 0x3b89: mov    DWORD PTR [rbp+rax*8+0x2e4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3178275799040ULL);
x86_l_3b94:
	/* 0x3b94: mov    DWORD PTR [rsp+0x18],0x16 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215126ULL);
x86_l_3b9c:
	/* 0x3b9c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_3ba3:
	/* 0x3ba3: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ba8:
	/* 0x3ba8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3bad:
	/* 0x3bad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3baf:
	/* 0x3baf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3bb2:
	/* 0x3bb2: je     3bb9 <perf_unwind_python+0x3bb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bb9;
	}
x86_l_3bb4:
	/* 0x3bb4: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3bb7:
	/* 0x3bb7: jmp    3c35 <perf_unwind_python+0x3c35> */
	goto x86_l_3c35;
x86_l_3bb9:
	/* 0x3bb9: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3bbd:
	/* 0x3bbd: je     3c35 <perf_unwind_python+0x3c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c35;
	}
x86_l_3bbf:
	/* 0x3bbf: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_3bc9:
	/* 0x3bc9: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_3bce:
	/* 0x3bce: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_3bd8:
	/* 0x3bd8: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3bdd:
	/* 0x3bdd: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_3be7:
	/* 0x3be7: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3bec:
	/* 0x3bec: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_3bf6:
	/* 0x3bf6: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3bfb:
	/* 0x3bfb: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_3c05:
	/* 0x3c05: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3c0a:
	/* 0x3c0a: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_3c14:
	/* 0x3c14: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c19:
	/* 0x3c19: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c1e:
	/* 0x3c1e: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_3c23:
	/* 0x3c23: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3c28:
	/* 0x3c28: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c2c:
	/* 0x3c2c: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_3c31:
	/* 0x3c31: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c33:
	/* 0x3c33: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3c35:
	/* 0x3c35: cmp    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_3c3a:
	/* 0x3c3a: jne    1d5a <perf_unwind_python+0x1d5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7514ULL;
	}
x86_l_3c40:
	/* 0x3c40: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c43:
	/* 0x3c43: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3c49:
	/* 0x3c49: je     45b4 <perf_unwind_python+0x45b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17844ULL;
	}
x86_l_3c4f:
	/* 0x3c4f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c53:
	/* 0x3c53: cmp    BYTE PTR [rax+0x19],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 107374182520ULL);
x86_l_3c57:
	/* 0x3c57: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_3c5d:
	/* 0x3c5d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c61:
	/* 0x3c61: cmp    BYTE PTR [rax+0x18],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215224ULL);
x86_l_3c65:
	/* 0x3c65: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_3c6b:
	/* 0x3c6b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c6f:
	/* 0x3c6f: cmp    BYTE PTR [rax+0x1a],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 111669149816ULL);
x86_l_3c73:
	/* 0x3c73: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_3c79:
	/* 0x3c79: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c7d:
	/* 0x3c7d: cmp    BYTE PTR [rax+0x1b],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 115964116992ULL);
x86_l_3c81:
	/* 0x3c81: js     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 17816ULL;
	}
x86_l_3c87:
	/* 0x3c87: mov    eax,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 128ULL);
x86_l_3c8c:
	/* 0x3c8c: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_3c91:
	/* 0x3c91: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3c96:
	/* 0x3c96: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3c9b:
	/* 0x3c9b: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_3ca0:
	/* 0x3ca0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3ca2:
	/* 0x3ca2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ca5:
	/* 0x3ca5: jne    d56 <perf_unwind_python+0xd56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3414ULL;
	}
x86_l_3cab:
	/* 0x3cab: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3caf:
	/* 0x3caf: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_3cb3:
	/* 0x3cb3: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3cb8:
	/* 0x3cb8: mov    rcx,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3cbc:
	/* 0x3cbc: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3cc1:
	/* 0x3cc1: movzx  ecx,BYTE PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_3cc5:
	/* 0x3cc5: mov    r13,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3cc9:
	/* 0x3cc9: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ccd:
	/* 0x3ccd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3cd0:
	/* 0x3cd0: je     3cdd <perf_unwind_python+0x3cdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cdd;
	}
x86_l_3cd2:
	/* 0x3cd2: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3cd7:
	/* 0x3cd7: je     1242 <perf_unwind_python+0x1242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4674ULL;
	}
x86_l_3cdd:
	/* 0x3cdd: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ce1:
	/* 0x3ce1: cmp    BYTE PTR [rax+0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_3ce5:
	/* 0x3ce5: movzx  eax,BYTE PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 26ULL);
x86_l_3ce9:
	/* 0x3ce9: je     3d32 <perf_unwind_python+0x3d32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d32;
	}
x86_l_3ceb:
	/* 0x3ceb: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3cf0:
	/* 0x3cf0: mov    rax,QWORD PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3cf4:
	/* 0x3cf4: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cf8:
	/* 0x3cf8: movzx  edx,BYTE PTR [rcx+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_3cfc:
	/* 0x3cfc: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_3d01:
	/* 0x3d01: sub    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3d04:
	/* 0x3d04: lea    rdx,[rax-0x10000001] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073441116159ULL);
x86_l_3d0b:
	/* 0x3d0b: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_3d0d:
	/* 0x3d0d: cmp    rdx,0xffffffffeffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073441116157ULL);
x86_l_3d14:
	/* 0x3d14: mov    r12d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_3d1a:
	/* 0x3d1a: cmovae r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_3d1e:
	/* 0x3d1e: movzx  eax,BYTE PTR [rcx+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_3d22:
	/* 0x3d22: movzx  eax,BYTE PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3d26:
	/* 0x3d26: cmp    al,BYTE PTR [rcx+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_3d29:
	/* 0x3d29: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_3d2c:
	/* 0x3d2c: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3d30:
	/* 0x3d30: jmp    3d43 <perf_unwind_python+0x3d43> */
	goto x86_l_3d43;
x86_l_3d32:
	/* 0x3d32: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3d37:
	/* 0x3d37: mov    r12d,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3d3b:
	/* 0x3d3b: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_3d43:
	/* 0x3d43: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
	return 15689ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15689ULL: goto x86_l_3d49;
	case 15695ULL: goto x86_l_3d4f;
	case 15699ULL: goto x86_l_3d53;
	case 15703ULL: goto x86_l_3d57;
	case 15709ULL: goto x86_l_3d5d;
	case 15713ULL: goto x86_l_3d61;
	case 15717ULL: goto x86_l_3d65;
	case 15723ULL: goto x86_l_3d6b;
	case 15727ULL: goto x86_l_3d6f;
	case 15731ULL: goto x86_l_3d73;
	case 15737ULL: goto x86_l_3d79;
	case 15741ULL: goto x86_l_3d7d;
	case 15745ULL: goto x86_l_3d81;
	case 15751ULL: goto x86_l_3d87;
	case 15756ULL: goto x86_l_3d8c;
	case 15761ULL: goto x86_l_3d91;
	case 15766ULL: goto x86_l_3d96;
	case 15769ULL: goto x86_l_3d99;
	case 15774ULL: goto x86_l_3d9e;
	case 15776ULL: goto x86_l_3da0;
	case 15779ULL: goto x86_l_3da3;
	case 15785ULL: goto x86_l_3da9;
	case 15789ULL: goto x86_l_3dad;
	case 15793ULL: goto x86_l_3db1;
	case 15797ULL: goto x86_l_3db5;
	case 15801ULL: goto x86_l_3db9;
	case 15805ULL: goto x86_l_3dbd;
	case 15809ULL: goto x86_l_3dc1;
	case 15813ULL: goto x86_l_3dc5;
	case 15817ULL: goto x86_l_3dc9;
	case 15820ULL: goto x86_l_3dcc;
	case 15823ULL: goto x86_l_3dcf;
	case 15825ULL: goto x86_l_3dd1;
	case 15828ULL: goto x86_l_3dd4;
	case 15830ULL: goto x86_l_3dd6;
	case 15834ULL: goto x86_l_3dda;
	case 15838ULL: goto x86_l_3dde;
	case 15841ULL: goto x86_l_3de1;
	case 15846ULL: goto x86_l_3de6;
	case 15850ULL: goto x86_l_3dea;
	case 15856ULL: goto x86_l_3df0;
	case 15866ULL: goto x86_l_3dfa;
	case 15871ULL: goto x86_l_3dff;
	case 15881ULL: goto x86_l_3e09;
	case 15886ULL: goto x86_l_3e0e;
	case 15896ULL: goto x86_l_3e18;
	case 15901ULL: goto x86_l_3e1d;
	case 15911ULL: goto x86_l_3e27;
	case 15916ULL: goto x86_l_3e2c;
	case 15926ULL: goto x86_l_3e36;
	case 15931ULL: goto x86_l_3e3b;
	case 15941ULL: goto x86_l_3e45;
	case 15946ULL: goto x86_l_3e4a;
	case 15951ULL: goto x86_l_3e4f;
	case 15956ULL: goto x86_l_3e54;
	case 15962ULL: goto x86_l_3e5a;
	case 15966ULL: goto x86_l_3e5e;
	case 15970ULL: goto x86_l_3e62;
	case 15975ULL: goto x86_l_3e67;
	case 15978ULL: goto x86_l_3e6a;
	case 15983ULL: goto x86_l_3e6f;
	case 15985ULL: goto x86_l_3e71;
	case 15988ULL: goto x86_l_3e74;
	case 15996ULL: goto x86_l_3e7c;
	case 16003ULL: goto x86_l_3e83;
	case 16008ULL: goto x86_l_3e88;
	case 16013ULL: goto x86_l_3e8d;
	case 16015ULL: goto x86_l_3e8f;
	case 16018ULL: goto x86_l_3e92;
	case 16020ULL: goto x86_l_3e94;
	case 16023ULL: goto x86_l_3e97;
	case 16025ULL: goto x86_l_3e99;
	case 16029ULL: goto x86_l_3e9d;
	case 16031ULL: goto x86_l_3e9f;
	case 16041ULL: goto x86_l_3ea9;
	case 16046ULL: goto x86_l_3eae;
	case 16056ULL: goto x86_l_3eb8;
	case 16061ULL: goto x86_l_3ebd;
	case 16071ULL: goto x86_l_3ec7;
	case 16076ULL: goto x86_l_3ecc;
	case 16086ULL: goto x86_l_3ed6;
	case 16091ULL: goto x86_l_3edb;
	case 16101ULL: goto x86_l_3ee5;
	case 16106ULL: goto x86_l_3eea;
	case 16116ULL: goto x86_l_3ef4;
	case 16121ULL: goto x86_l_3ef9;
	case 16126ULL: goto x86_l_3efe;
	case 16131ULL: goto x86_l_3f03;
	case 16136ULL: goto x86_l_3f08;
	case 16140ULL: goto x86_l_3f0c;
	case 16145ULL: goto x86_l_3f11;
	case 16147ULL: goto x86_l_3f13;
	case 16149ULL: goto x86_l_3f15;
	case 16156ULL: goto x86_l_3f1c;
	case 16158ULL: goto x86_l_3f1e;
	case 16163ULL: goto x86_l_3f23;
	case 16167ULL: goto x86_l_3f27;
	case 16169ULL: goto x86_l_3f29;
	case 16179ULL: goto x86_l_3f33;
	case 16184ULL: goto x86_l_3f38;
	case 16194ULL: goto x86_l_3f42;
	case 16199ULL: goto x86_l_3f47;
	case 16209ULL: goto x86_l_3f51;
	case 16214ULL: goto x86_l_3f56;
	case 16219ULL: goto x86_l_3f5b;
	case 16224ULL: goto x86_l_3f60;
	case 16230ULL: goto x86_l_3f66;
	case 16235ULL: goto x86_l_3f6b;
	case 16240ULL: goto x86_l_3f70;
	case 16243ULL: goto x86_l_3f73;
	case 16245ULL: goto x86_l_3f75;
	case 16248ULL: goto x86_l_3f78;
	case 16254ULL: goto x86_l_3f7e;
	case 16258ULL: goto x86_l_3f82;
	case 16264ULL: goto x86_l_3f88;
	case 16267ULL: goto x86_l_3f8b;
	case 16273ULL: goto x86_l_3f91;
	case 16277ULL: goto x86_l_3f95;
	case 16282ULL: goto x86_l_3f9a;
	case 16290ULL: goto x86_l_3fa2;
	case 16298ULL: goto x86_l_3faa;
	case 16306ULL: goto x86_l_3fb2;
	case 16317ULL: goto x86_l_3fbd;
	case 16328ULL: goto x86_l_3fc8;
	case 16336ULL: goto x86_l_3fd0;
	case 16343ULL: goto x86_l_3fd7;
	case 16348ULL: goto x86_l_3fdc;
	case 16353ULL: goto x86_l_3fe1;
	case 16355ULL: goto x86_l_3fe3;
	case 16358ULL: goto x86_l_3fe6;
	case 16360ULL: goto x86_l_3fe8;
	case 16363ULL: goto x86_l_3feb;
	case 16365ULL: goto x86_l_3fed;
	case 16369ULL: goto x86_l_3ff1;
	case 16371ULL: goto x86_l_3ff3;
	case 16381ULL: goto x86_l_3ffd;
	case 16386ULL: goto x86_l_4002;
	case 16396ULL: goto x86_l_400c;
	case 16401ULL: goto x86_l_4011;
	case 16411ULL: goto x86_l_401b;
	case 16416ULL: goto x86_l_4020;
	case 16426ULL: goto x86_l_402a;
	case 16431ULL: goto x86_l_402f;
	case 16441ULL: goto x86_l_4039;
	case 16446ULL: goto x86_l_403e;
	case 16456ULL: goto x86_l_4048;
	case 16461ULL: goto x86_l_404d;
	case 16466ULL: goto x86_l_4052;
	case 16471ULL: goto x86_l_4057;
	case 16476ULL: goto x86_l_405c;
	case 16480ULL: goto x86_l_4060;
	case 16485ULL: goto x86_l_4065;
	case 16487ULL: goto x86_l_4067;
	case 16489ULL: goto x86_l_4069;
	case 16494ULL: goto x86_l_406e;
	case 16500ULL: goto x86_l_4074;
	case 16503ULL: goto x86_l_4077;
	case 16506ULL: goto x86_l_407a;
	case 16512ULL: goto x86_l_4080;
	case 16516ULL: goto x86_l_4084;
	case 16520ULL: goto x86_l_4088;
	case 16526ULL: goto x86_l_408e;
	case 16530ULL: goto x86_l_4092;
	case 16534ULL: goto x86_l_4096;
	case 16540ULL: goto x86_l_409c;
	case 16544ULL: goto x86_l_40a0;
	case 16548ULL: goto x86_l_40a4;
	case 16554ULL: goto x86_l_40aa;
	case 16558ULL: goto x86_l_40ae;
	case 16562ULL: goto x86_l_40b2;
	case 16568ULL: goto x86_l_40b8;
	case 16573ULL: goto x86_l_40bd;
	case 16578ULL: goto x86_l_40c2;
	case 16583ULL: goto x86_l_40c7;
	case 16588ULL: goto x86_l_40cc;
	case 16591ULL: goto x86_l_40cf;
	case 16593ULL: goto x86_l_40d1;
	case 16596ULL: goto x86_l_40d4;
	case 16602ULL: goto x86_l_40da;
	case 16606ULL: goto x86_l_40de;
	case 16610ULL: goto x86_l_40e2;
	case 16615ULL: goto x86_l_40e7;
	case 16619ULL: goto x86_l_40eb;
	case 16624ULL: goto x86_l_40f0;
	case 16628ULL: goto x86_l_40f4;
	case 16632ULL: goto x86_l_40f8;
	case 16637ULL: goto x86_l_40fd;
	case 16641ULL: goto x86_l_4101;
	case 16644ULL: goto x86_l_4104;
	case 16646ULL: goto x86_l_4106;
	case 16651ULL: goto x86_l_410b;
	case 16657ULL: goto x86_l_4111;
	case 16661ULL: goto x86_l_4115;
	case 16665ULL: goto x86_l_4119;
	case 16669ULL: goto x86_l_411d;
	case 16671ULL: goto x86_l_411f;
	case 16676ULL: goto x86_l_4124;
	case 16680ULL: goto x86_l_4128;
	case 16684ULL: goto x86_l_412c;
	case 16688ULL: goto x86_l_4130;
	case 16693ULL: goto x86_l_4135;
	case 16696ULL: goto x86_l_4138;
	case 16703ULL: goto x86_l_413f;
	case 16705ULL: goto x86_l_4141;
	case 16712ULL: goto x86_l_4148;
	case 16718ULL: goto x86_l_414e;
	case 16722ULL: goto x86_l_4152;
	case 16726ULL: goto x86_l_4156;
	case 16730ULL: goto x86_l_415a;
	case 16733ULL: goto x86_l_415d;
	case 16736ULL: goto x86_l_4160;
	case 16740ULL: goto x86_l_4164;
	case 16742ULL: goto x86_l_4166;
	case 16747ULL: goto x86_l_416b;
	case 16751ULL: goto x86_l_416f;
	case 16759ULL: goto x86_l_4177;
	case 16765ULL: goto x86_l_417d;
	case 16771ULL: goto x86_l_4183;
	case 16775ULL: goto x86_l_4187;
	case 16779ULL: goto x86_l_418b;
	case 16785ULL: goto x86_l_4191;
	case 16789ULL: goto x86_l_4195;
	case 16793ULL: goto x86_l_4199;
	case 16799ULL: goto x86_l_419f;
	case 16803ULL: goto x86_l_41a3;
	case 16807ULL: goto x86_l_41a7;
	case 16813ULL: goto x86_l_41ad;
	case 16817ULL: goto x86_l_41b1;
	case 16821ULL: goto x86_l_41b5;
	case 16827ULL: goto x86_l_41bb;
	case 16832ULL: goto x86_l_41c0;
	case 16837ULL: goto x86_l_41c5;
	case 16842ULL: goto x86_l_41ca;
	case 16845ULL: goto x86_l_41cd;
	case 16850ULL: goto x86_l_41d2;
	case 16852ULL: goto x86_l_41d4;
	case 16855ULL: goto x86_l_41d7;
	case 16861ULL: goto x86_l_41dd;
	case 16865ULL: goto x86_l_41e1;
	case 16869ULL: goto x86_l_41e5;
	case 16873ULL: goto x86_l_41e9;
	case 16877ULL: goto x86_l_41ed;
	case 16881ULL: goto x86_l_41f1;
	case 16885ULL: goto x86_l_41f5;
	case 16889ULL: goto x86_l_41f9;
	case 16893ULL: goto x86_l_41fd;
	case 16896ULL: goto x86_l_4200;
	case 16899ULL: goto x86_l_4203;
	case 16901ULL: goto x86_l_4205;
	case 16904ULL: goto x86_l_4208;
	case 16906ULL: goto x86_l_420a;
	case 16910ULL: goto x86_l_420e;
	case 16914ULL: goto x86_l_4212;
	case 16917ULL: goto x86_l_4215;
	case 16922ULL: goto x86_l_421a;
	case 16926ULL: goto x86_l_421e;
	case 16932ULL: goto x86_l_4224;
	case 16942ULL: goto x86_l_422e;
	case 16947ULL: goto x86_l_4233;
	case 16957ULL: goto x86_l_423d;
	case 16962ULL: goto x86_l_4242;
	case 16972ULL: goto x86_l_424c;
	case 16977ULL: goto x86_l_4251;
	case 16987ULL: goto x86_l_425b;
	case 16992ULL: goto x86_l_4260;
	case 17002ULL: goto x86_l_426a;
	case 17007ULL: goto x86_l_426f;
	case 17017ULL: goto x86_l_4279;
	case 17022ULL: goto x86_l_427e;
	case 17027ULL: goto x86_l_4283;
	case 17032ULL: goto x86_l_4288;
	case 17038ULL: goto x86_l_428e;
	case 17042ULL: goto x86_l_4292;
	case 17046ULL: goto x86_l_4296;
	case 17049ULL: goto x86_l_4299;
	case 17054ULL: goto x86_l_429e;
	case 17057ULL: goto x86_l_42a1;
	case 17059ULL: goto x86_l_42a3;
	case 17062ULL: goto x86_l_42a6;
	case 17070ULL: goto x86_l_42ae;
	case 17077ULL: goto x86_l_42b5;
	case 17082ULL: goto x86_l_42ba;
	case 17087ULL: goto x86_l_42bf;
	case 17089ULL: goto x86_l_42c1;
	case 17092ULL: goto x86_l_42c4;
	case 17094ULL: goto x86_l_42c6;
	case 17097ULL: goto x86_l_42c9;
	case 17099ULL: goto x86_l_42cb;
	case 17103ULL: goto x86_l_42cf;
	case 17105ULL: goto x86_l_42d1;
	case 17115ULL: goto x86_l_42db;
	case 17120ULL: goto x86_l_42e0;
	case 17130ULL: goto x86_l_42ea;
	case 17135ULL: goto x86_l_42ef;
	case 17145ULL: goto x86_l_42f9;
	case 17150ULL: goto x86_l_42fe;
	case 17160ULL: goto x86_l_4308;
	case 17165ULL: goto x86_l_430d;
	case 17175ULL: goto x86_l_4317;
	case 17180ULL: goto x86_l_431c;
	case 17190ULL: goto x86_l_4326;
	case 17195ULL: goto x86_l_432b;
	case 17200ULL: goto x86_l_4330;
	case 17205ULL: goto x86_l_4335;
	case 17210ULL: goto x86_l_433a;
	case 17214ULL: goto x86_l_433e;
	case 17219ULL: goto x86_l_4343;
	case 17221ULL: goto x86_l_4345;
	case 17223ULL: goto x86_l_4347;
	case 17230ULL: goto x86_l_434e;
	case 17232ULL: goto x86_l_4350;
	case 17237ULL: goto x86_l_4355;
	case 17241ULL: goto x86_l_4359;
	case 17243ULL: goto x86_l_435b;
	case 17253ULL: goto x86_l_4365;
	case 17258ULL: goto x86_l_436a;
	case 17268ULL: goto x86_l_4374;
	case 17273ULL: goto x86_l_4379;
	case 17283ULL: goto x86_l_4383;
	case 17288ULL: goto x86_l_4388;
	case 17293ULL: goto x86_l_438d;
	case 17298ULL: goto x86_l_4392;
	case 17304ULL: goto x86_l_4398;
	case 17309ULL: goto x86_l_439d;
	case 17314ULL: goto x86_l_43a2;
	case 17317ULL: goto x86_l_43a5;
	case 17319ULL: goto x86_l_43a7;
	case 17322ULL: goto x86_l_43aa;
	case 17328ULL: goto x86_l_43b0;
	case 17332ULL: goto x86_l_43b4;
	case 17338ULL: goto x86_l_43ba;
	case 17341ULL: goto x86_l_43bd;
	case 17347ULL: goto x86_l_43c3;
	case 17351ULL: goto x86_l_43c7;
	case 17356ULL: goto x86_l_43cc;
	case 17364ULL: goto x86_l_43d4;
	case 17372ULL: goto x86_l_43dc;
	case 17380ULL: goto x86_l_43e4;
	case 17391ULL: goto x86_l_43ef;
	case 17402ULL: goto x86_l_43fa;
	case 17410ULL: goto x86_l_4402;
	case 17417ULL: goto x86_l_4409;
	case 17422ULL: goto x86_l_440e;
	case 17427ULL: goto x86_l_4413;
	case 17429ULL: goto x86_l_4415;
	case 17432ULL: goto x86_l_4418;
	case 17434ULL: goto x86_l_441a;
	case 17437ULL: goto x86_l_441d;
	case 17439ULL: goto x86_l_441f;
	case 17443ULL: goto x86_l_4423;
	case 17445ULL: goto x86_l_4425;
	case 17455ULL: goto x86_l_442f;
	case 17460ULL: goto x86_l_4434;
	case 17470ULL: goto x86_l_443e;
	case 17475ULL: goto x86_l_4443;
	case 17485ULL: goto x86_l_444d;
	case 17490ULL: goto x86_l_4452;
	case 17500ULL: goto x86_l_445c;
	case 17505ULL: goto x86_l_4461;
	case 17515ULL: goto x86_l_446b;
	case 17520ULL: goto x86_l_4470;
	case 17530ULL: goto x86_l_447a;
	case 17535ULL: goto x86_l_447f;
	case 17540ULL: goto x86_l_4484;
	case 17545ULL: goto x86_l_4489;
	case 17550ULL: goto x86_l_448e;
	case 17554ULL: goto x86_l_4492;
	case 17559ULL: goto x86_l_4497;
	case 17561ULL: goto x86_l_4499;
	case 17563ULL: goto x86_l_449b;
	case 17568ULL: goto x86_l_44a0;
	case 17574ULL: goto x86_l_44a6;
	case 17577ULL: goto x86_l_44a9;
	case 17583ULL: goto x86_l_44af;
	case 17589ULL: goto x86_l_44b5;
	case 17593ULL: goto x86_l_44b9;
	case 17597ULL: goto x86_l_44bd;
	case 17603ULL: goto x86_l_44c3;
	case 17607ULL: goto x86_l_44c7;
	case 17611ULL: goto x86_l_44cb;
	case 17617ULL: goto x86_l_44d1;
	case 17621ULL: goto x86_l_44d5;
	case 17625ULL: goto x86_l_44d9;
	case 17631ULL: goto x86_l_44df;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3d49:
	/* 0x3d49: je     3de6 <perf_unwind_python+0x3de6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3de6;
	}
x86_l_3d4f:
	/* 0x3d4f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d53:
	/* 0x3d53: cmp    BYTE PTR [rax+0x1d],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051772ULL);
x86_l_3d57:
	/* 0x3d57: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_3d5d:
	/* 0x3d5d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d61:
	/* 0x3d61: cmp    BYTE PTR [rax+0x1e],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128849019068ULL);
x86_l_3d65:
	/* 0x3d65: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_3d6b:
	/* 0x3d6b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d6f:
	/* 0x3d6f: cmp    BYTE PTR [rax+0x1f],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133143986364ULL);
x86_l_3d73:
	/* 0x3d73: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_3d79:
	/* 0x3d79: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d7d:
	/* 0x3d7d: cmp    BYTE PTR [rax+0x20],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953660ULL);
x86_l_3d81:
	/* 0x3d81: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_3d87:
	/* 0x3d87: mov    eax,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 192ULL);
x86_l_3d8c:
	/* 0x3d8c: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_3d91:
	/* 0x3d91: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3d96:
	/* 0x3d96: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3d99:
	/* 0x3d99: mov    esi,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 192ULL);
x86_l_3d9e:
	/* 0x3d9e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3da0:
	/* 0x3da0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3da3:
	/* 0x3da3: jne    2b5 <perf_unwind_python+0x2b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 693ULL;
	}
x86_l_3da9:
	/* 0x3da9: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3dad:
	/* 0x3dad: movzx  ecx,BYTE PTR [rax+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_3db1:
	/* 0x3db1: mov    ecx,DWORD PTR [r15+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3db5:
	/* 0x3db5: movzx  edx,BYTE PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_3db9:
	/* 0x3db9: mov    edx,DWORD PTR [r15+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_3dbd:
	/* 0x3dbd: movzx  esi,BYTE PTR [rax+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_3dc1:
	/* 0x3dc1: mov    esi,DWORD PTR [r15+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_3dc5:
	/* 0x3dc5: movzx  eax,BYTE PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_3dc9:
	/* 0x3dc9: shl    ecx,0x19 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 25ULL);
x86_l_3dcc:
	/* 0x3dcc: shl    edx,0x12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 18ULL);
x86_l_3dcf:
	/* 0x3dcf: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3dd1:
	/* 0x3dd1: shl    esi,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 10ULL);
x86_l_3dd4:
	/* 0x3dd4: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3dd6:
	/* 0x3dd6: add    esi,DWORD PTR [r15+rax*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R15, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3dda:
	/* 0x3dda: shl    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_3dde:
	/* 0x3dde: or     r12,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RSI, X86_WIDTH_64, X86_ALU_OR);
x86_l_3de1:
	/* 0x3de1: jmp    3f23 <perf_unwind_python+0x3f23> */
	goto x86_l_3f23;
x86_l_3de6:
	/* 0x3de6: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3dea:
	/* 0x3dea: je     3e74 <perf_unwind_python+0x3e74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e74;
	}
x86_l_3df0:
	/* 0x3df0: movabs rax,0xa786c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541280ULL);
x86_l_3dfa:
	/* 0x3dfa: mov    QWORD PTR [rsp+0x57],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_3dff:
	/* 0x3dff: movabs rax,0x20786c2578302074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2339738914604982388ULL);
x86_l_3e09:
	/* 0x3e09: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3e0e:
	/* 0x3e0e: movabs rax,0x63656a624f656d61 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7162247752874028385ULL);
x86_l_3e18:
	/* 0x3e18: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3e1d:
	/* 0x3e1d: movabs rax,0x7246795020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8234402353742245734ULL);
x86_l_3e27:
	/* 0x3e27: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3e2c:
	/* 0x3e2c: movabs rax,0x207463656a626f65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338603393739812709ULL);
x86_l_3e36:
	/* 0x3e36: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3e3b:
	/* 0x3e3b: movabs rax,0x646f63206c6c754e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7237112117116826958ULL);
x86_l_3e45:
	/* 0x3e45: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3e4a:
	/* 0x3e4a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3e4f:
	/* 0x3e4f: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_3e54:
	/* 0x3e54: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_3e5a:
	/* 0x3e5a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e5e:
	/* 0x3e5e: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_3e62:
	/* 0x3e62: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e67:
	/* 0x3e67: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3e6a:
	/* 0x3e6a: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_3e6f:
	/* 0x3e6f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e71:
	/* 0x3e71: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3e74:
	/* 0x3e74: mov    DWORD PTR [rsp+0x18],0x1c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215132ULL);
x86_l_3e7c:
	/* 0x3e7c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_3e83:
	/* 0x3e83: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e88:
	/* 0x3e88: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e8d:
	/* 0x3e8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e8f:
	/* 0x3e8f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e92:
	/* 0x3e92: je     3e99 <perf_unwind_python+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_3e94:
	/* 0x3e94: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3e97:
	/* 0x3e97: jmp    3f15 <perf_unwind_python+0x3f15> */
	goto x86_l_3f15;
x86_l_3e99:
	/* 0x3e99: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e9d:
	/* 0x3e9d: je     3f15 <perf_unwind_python+0x3f15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f15;
	}
x86_l_3e9f:
	/* 0x3e9f: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_3ea9:
	/* 0x3ea9: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_3eae:
	/* 0x3eae: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_3eb8:
	/* 0x3eb8: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3ebd:
	/* 0x3ebd: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_3ec7:
	/* 0x3ec7: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3ecc:
	/* 0x3ecc: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_3ed6:
	/* 0x3ed6: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3edb:
	/* 0x3edb: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_3ee5:
	/* 0x3ee5: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3eea:
	/* 0x3eea: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_3ef4:
	/* 0x3ef4: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ef9:
	/* 0x3ef9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3efe:
	/* 0x3efe: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_3f03:
	/* 0x3f03: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3f08:
	/* 0x3f08: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3f0c:
	/* 0x3f0c: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_3f11:
	/* 0x3f11: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f13:
	/* 0x3f13: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3f15:
	/* 0x3f15: mov    r12,0xfffffffffffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_3f1c:
	/* 0x3f1c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f1e:
	/* 0x3f1e: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3f23:
	/* 0x3f23: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f27:
	/* 0x3f27: je     3f78 <perf_unwind_python+0x3f78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f78;
	}
x86_l_3f29:
	/* 0x3f29: movabs rax,0xa756c2520786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2943857106909292ULL);
x86_l_3f33:
	/* 0x3f33: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3f38:
	/* 0x3f38: movabs rax,0x25206e6f68747950 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675259603430963536ULL);
x86_l_3f42:
	/* 0x3f42: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3f47:
	/* 0x3f47: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_3f51:
	/* 0x3f51: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f56:
	/* 0x3f56: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f5b:
	/* 0x3f5b: mov    eax,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_3f60:
	/* 0x3f60: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_3f66:
	/* 0x3f66: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_3f6b:
	/* 0x3f6b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3f70:
	/* 0x3f70: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_3f73:
	/* 0x3f73: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f75:
	/* 0x3f75: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3f78:
	/* 0x3f78: mov    eax,DWORD PTR [rbp+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3f7e:
	/* 0x3f7e: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_3f82:
	/* 0x3f82: ja     176d <perf_unwind_python+0x176d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5997ULL;
	}
x86_l_3f88:
	/* 0x3f88: lea    ecx,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3f8b:
	/* 0x3f8b: mov    DWORD PTR [rbp+0x2c0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3f91:
	/* 0x3f91: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_3f95:
	/* 0x3f95: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3f9a:
	/* 0x3f9a: mov    QWORD PTR [rbp+rax*8+0x2d0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_3fa2:
	/* 0x3fa2: mov    QWORD PTR [rbp+rax*8+0x2d8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_3faa:
	/* 0x3faa: mov    BYTE PTR [rbp+rax*8+0x2e0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929857ULL);
x86_l_3fb2:
	/* 0x3fb2: mov    DWORD PTR [rbp+rax*8+0x2e1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3165390897152ULL);
x86_l_3fbd:
	/* 0x3fbd: mov    DWORD PTR [rbp+rax*8+0x2e4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3178275799040ULL);
x86_l_3fc8:
	/* 0x3fc8: mov    DWORD PTR [rsp+0x18],0x16 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215126ULL);
x86_l_3fd0:
	/* 0x3fd0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_3fd7:
	/* 0x3fd7: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3fdc:
	/* 0x3fdc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3fe1:
	/* 0x3fe1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fe3:
	/* 0x3fe3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3fe6:
	/* 0x3fe6: je     3fed <perf_unwind_python+0x3fed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fed;
	}
x86_l_3fe8:
	/* 0x3fe8: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3feb:
	/* 0x3feb: jmp    4069 <perf_unwind_python+0x4069> */
	goto x86_l_4069;
x86_l_3fed:
	/* 0x3fed: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ff1:
	/* 0x3ff1: je     4069 <perf_unwind_python+0x4069> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4069;
	}
x86_l_3ff3:
	/* 0x3ff3: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_3ffd:
	/* 0x3ffd: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_4002:
	/* 0x4002: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_400c:
	/* 0x400c: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4011:
	/* 0x4011: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_401b:
	/* 0x401b: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4020:
	/* 0x4020: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_402a:
	/* 0x402a: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_402f:
	/* 0x402f: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_4039:
	/* 0x4039: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_403e:
	/* 0x403e: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_4048:
	/* 0x4048: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_404d:
	/* 0x404d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4052:
	/* 0x4052: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_4057:
	/* 0x4057: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_405c:
	/* 0x405c: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4060:
	/* 0x4060: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_4065:
	/* 0x4065: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4067:
	/* 0x4067: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4069:
	/* 0x4069: cmp    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_406e:
	/* 0x406e: jne    1242 <perf_unwind_python+0x1242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4674ULL;
	}
x86_l_4074:
	/* 0x4074: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4077:
	/* 0x4077: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_407a:
	/* 0x407a: je     45b4 <perf_unwind_python+0x45b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17844ULL;
	}
x86_l_4080:
	/* 0x4080: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4084:
	/* 0x4084: cmp    BYTE PTR [rax+0x19],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 107374182520ULL);
x86_l_4088:
	/* 0x4088: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_408e:
	/* 0x408e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4092:
	/* 0x4092: cmp    BYTE PTR [rax+0x18],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215224ULL);
x86_l_4096:
	/* 0x4096: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_409c:
	/* 0x409c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40a0:
	/* 0x40a0: cmp    BYTE PTR [rax+0x1a],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 111669149816ULL);
x86_l_40a4:
	/* 0x40a4: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17920ULL;
	}
x86_l_40aa:
	/* 0x40aa: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40ae:
	/* 0x40ae: cmp    BYTE PTR [rax+0x1b],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 115964116992ULL);
x86_l_40b2:
	/* 0x40b2: js     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 17920ULL;
	}
x86_l_40b8:
	/* 0x40b8: mov    eax,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 128ULL);
x86_l_40bd:
	/* 0x40bd: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_40c2:
	/* 0x40c2: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_40c7:
	/* 0x40c7: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_40cc:
	/* 0x40cc: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_40cf:
	/* 0x40cf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_40d1:
	/* 0x40d1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_40d4:
	/* 0x40d4: jne    1d1d <perf_unwind_python+0x1d1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7453ULL;
	}
x86_l_40da:
	/* 0x40da: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40de:
	/* 0x40de: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_40e2:
	/* 0x40e2: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_40e7:
	/* 0x40e7: mov    rcx,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_40eb:
	/* 0x40eb: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_40f0:
	/* 0x40f0: movzx  ecx,BYTE PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_40f4:
	/* 0x40f4: mov    rcx,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_40f8:
	/* 0x40f8: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_40fd:
	/* 0x40fd: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4101:
	/* 0x4101: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4104:
	/* 0x4104: je     4111 <perf_unwind_python+0x4111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4111;
	}
x86_l_4106:
	/* 0x4106: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_410b:
	/* 0x410b: je     1d5a <perf_unwind_python+0x1d5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7514ULL;
	}
x86_l_4111:
	/* 0x4111: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4115:
	/* 0x4115: cmp    BYTE PTR [rax+0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_4119:
	/* 0x4119: movzx  eax,BYTE PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 26ULL);
x86_l_411d:
	/* 0x411d: je     4166 <perf_unwind_python+0x4166> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4166;
	}
x86_l_411f:
	/* 0x411f: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4124:
	/* 0x4124: mov    rax,QWORD PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4128:
	/* 0x4128: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_412c:
	/* 0x412c: movzx  edx,BYTE PTR [rcx+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_4130:
	/* 0x4130: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_4135:
	/* 0x4135: sub    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_4138:
	/* 0x4138: lea    rdx,[rax-0x10000001] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073441116159ULL);
x86_l_413f:
	/* 0x413f: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_4141:
	/* 0x4141: cmp    rdx,0xffffffffeffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073441116157ULL);
x86_l_4148:
	/* 0x4148: mov    r12d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_414e:
	/* 0x414e: cmovae r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_4152:
	/* 0x4152: movzx  eax,BYTE PTR [rcx+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_4156:
	/* 0x4156: movzx  eax,BYTE PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_415a:
	/* 0x415a: cmp    al,BYTE PTR [rcx+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_415d:
	/* 0x415d: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_4160:
	/* 0x4160: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4164:
	/* 0x4164: jmp    4177 <perf_unwind_python+0x4177> */
	goto x86_l_4177;
x86_l_4166:
	/* 0x4166: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_416b:
	/* 0x416b: mov    r12d,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_416f:
	/* 0x416f: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_4177:
	/* 0x4177: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_417d:
	/* 0x417d: je     421a <perf_unwind_python+0x421a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_421a;
	}
x86_l_4183:
	/* 0x4183: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4187:
	/* 0x4187: cmp    BYTE PTR [rax+0x1d],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051772ULL);
x86_l_418b:
	/* 0x418b: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_4191:
	/* 0x4191: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4195:
	/* 0x4195: cmp    BYTE PTR [rax+0x1e],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128849019068ULL);
x86_l_4199:
	/* 0x4199: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_419f:
	/* 0x419f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41a3:
	/* 0x41a3: cmp    BYTE PTR [rax+0x1f],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133143986364ULL);
x86_l_41a7:
	/* 0x41a7: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_41ad:
	/* 0x41ad: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41b1:
	/* 0x41b1: cmp    BYTE PTR [rax+0x20],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953660ULL);
x86_l_41b5:
	/* 0x41b5: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_41bb:
	/* 0x41bb: mov    eax,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 192ULL);
x86_l_41c0:
	/* 0x41c0: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_41c5:
	/* 0x41c5: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_41ca:
	/* 0x41ca: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_41cd:
	/* 0x41cd: mov    esi,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 192ULL);
x86_l_41d2:
	/* 0x41d2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_41d4:
	/* 0x41d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_41d7:
	/* 0x41d7: jne    1e2c <perf_unwind_python+0x1e2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7724ULL;
	}
x86_l_41dd:
	/* 0x41dd: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41e1:
	/* 0x41e1: movzx  ecx,BYTE PTR [rax+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_41e5:
	/* 0x41e5: mov    ecx,DWORD PTR [r15+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_41e9:
	/* 0x41e9: movzx  edx,BYTE PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_41ed:
	/* 0x41ed: mov    edx,DWORD PTR [r15+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_41f1:
	/* 0x41f1: movzx  esi,BYTE PTR [rax+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_41f5:
	/* 0x41f5: mov    esi,DWORD PTR [r15+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_41f9:
	/* 0x41f9: movzx  eax,BYTE PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_41fd:
	/* 0x41fd: shl    ecx,0x19 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 25ULL);
x86_l_4200:
	/* 0x4200: shl    edx,0x12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 18ULL);
x86_l_4203:
	/* 0x4203: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4205:
	/* 0x4205: shl    esi,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 10ULL);
x86_l_4208:
	/* 0x4208: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_420a:
	/* 0x420a: add    esi,DWORD PTR [r15+rax*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R15, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_420e:
	/* 0x420e: shl    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_4212:
	/* 0x4212: or     r12,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RSI, X86_WIDTH_64, X86_ALU_OR);
x86_l_4215:
	/* 0x4215: jmp    4355 <perf_unwind_python+0x4355> */
	goto x86_l_4355;
x86_l_421a:
	/* 0x421a: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_421e:
	/* 0x421e: je     42a6 <perf_unwind_python+0x42a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42a6;
	}
x86_l_4224:
	/* 0x4224: movabs rax,0xa786c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541280ULL);
x86_l_422e:
	/* 0x422e: mov    QWORD PTR [rsp+0x57],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_4233:
	/* 0x4233: movabs rax,0x20786c2578302074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2339738914604982388ULL);
x86_l_423d:
	/* 0x423d: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4242:
	/* 0x4242: movabs rax,0x63656a624f656d61 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7162247752874028385ULL);
x86_l_424c:
	/* 0x424c: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4251:
	/* 0x4251: movabs rax,0x7246795020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8234402353742245734ULL);
x86_l_425b:
	/* 0x425b: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4260:
	/* 0x4260: movabs rax,0x207463656a626f65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338603393739812709ULL);
x86_l_426a:
	/* 0x426a: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_426f:
	/* 0x426f: movabs rax,0x646f63206c6c754e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7237112117116826958ULL);
x86_l_4279:
	/* 0x4279: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_427e:
	/* 0x427e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4283:
	/* 0x4283: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_4288:
	/* 0x4288: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_428e:
	/* 0x428e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4292:
	/* 0x4292: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_4296:
	/* 0x4296: add    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4299:
	/* 0x4299: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_429e:
	/* 0x429e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_42a1:
	/* 0x42a1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_42a3:
	/* 0x42a3: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_42a6:
	/* 0x42a6: mov    DWORD PTR [rsp+0x18],0x1c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215132ULL);
x86_l_42ae:
	/* 0x42ae: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_42b5:
	/* 0x42b5: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_42ba:
	/* 0x42ba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_42bf:
	/* 0x42bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42c1:
	/* 0x42c1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_42c4:
	/* 0x42c4: je     42cb <perf_unwind_python+0x42cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42cb;
	}
x86_l_42c6:
	/* 0x42c6: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_42c9:
	/* 0x42c9: jmp    4347 <perf_unwind_python+0x4347> */
	goto x86_l_4347;
x86_l_42cb:
	/* 0x42cb: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42cf:
	/* 0x42cf: je     4347 <perf_unwind_python+0x4347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4347;
	}
x86_l_42d1:
	/* 0x42d1: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_42db:
	/* 0x42db: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_42e0:
	/* 0x42e0: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_42ea:
	/* 0x42ea: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_42ef:
	/* 0x42ef: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_42f9:
	/* 0x42f9: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_42fe:
	/* 0x42fe: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_4308:
	/* 0x4308: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_430d:
	/* 0x430d: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_4317:
	/* 0x4317: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_431c:
	/* 0x431c: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_4326:
	/* 0x4326: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_432b:
	/* 0x432b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4330:
	/* 0x4330: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_4335:
	/* 0x4335: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_433a:
	/* 0x433a: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_433e:
	/* 0x433e: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_4343:
	/* 0x4343: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4345:
	/* 0x4345: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4347:
	/* 0x4347: mov    r12,0xfffffffffffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_434e:
	/* 0x434e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4350:
	/* 0x4350: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4355:
	/* 0x4355: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4359:
	/* 0x4359: je     43aa <perf_unwind_python+0x43aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43aa;
	}
x86_l_435b:
	/* 0x435b: movabs rax,0xa756c2520786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2943857106909292ULL);
x86_l_4365:
	/* 0x4365: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_436a:
	/* 0x436a: movabs rax,0x25206e6f68747950 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675259603430963536ULL);
x86_l_4374:
	/* 0x4374: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4379:
	/* 0x4379: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_4383:
	/* 0x4383: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4388:
	/* 0x4388: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_438d:
	/* 0x438d: mov    eax,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_4392:
	/* 0x4392: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_4398:
	/* 0x4398: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_439d:
	/* 0x439d: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_43a2:
	/* 0x43a2: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_43a5:
	/* 0x43a5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_43a7:
	/* 0x43a7: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_43aa:
	/* 0x43aa: mov    eax,DWORD PTR [rbp+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_43b0:
	/* 0x43b0: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_43b4:
	/* 0x43b4: ja     1f27 <perf_unwind_python+0x1f27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7975ULL;
	}
x86_l_43ba:
	/* 0x43ba: lea    ecx,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_43bd:
	/* 0x43bd: mov    DWORD PTR [rbp+0x2c0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_43c3:
	/* 0x43c3: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_43c7:
	/* 0x43c7: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_43cc:
	/* 0x43cc: mov    QWORD PTR [rbp+rax*8+0x2d0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_43d4:
	/* 0x43d4: mov    QWORD PTR [rbp+rax*8+0x2d8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_43dc:
	/* 0x43dc: mov    BYTE PTR [rbp+rax*8+0x2e0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929857ULL);
x86_l_43e4:
	/* 0x43e4: mov    DWORD PTR [rbp+rax*8+0x2e1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3165390897152ULL);
x86_l_43ef:
	/* 0x43ef: mov    DWORD PTR [rbp+rax*8+0x2e4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3178275799040ULL);
x86_l_43fa:
	/* 0x43fa: mov    DWORD PTR [rsp+0x18],0x16 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215126ULL);
x86_l_4402:
	/* 0x4402: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_4409:
	/* 0x4409: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_440e:
	/* 0x440e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4413:
	/* 0x4413: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4415:
	/* 0x4415: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4418:
	/* 0x4418: je     441f <perf_unwind_python+0x441f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_441f;
	}
x86_l_441a:
	/* 0x441a: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_441d:
	/* 0x441d: jmp    449b <perf_unwind_python+0x449b> */
	goto x86_l_449b;
x86_l_441f:
	/* 0x441f: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4423:
	/* 0x4423: je     449b <perf_unwind_python+0x449b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_449b;
	}
x86_l_4425:
	/* 0x4425: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_442f:
	/* 0x442f: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_4434:
	/* 0x4434: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_443e:
	/* 0x443e: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4443:
	/* 0x4443: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_444d:
	/* 0x444d: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4452:
	/* 0x4452: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_445c:
	/* 0x445c: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4461:
	/* 0x4461: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_446b:
	/* 0x446b: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4470:
	/* 0x4470: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_447a:
	/* 0x447a: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_447f:
	/* 0x447f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4484:
	/* 0x4484: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_4489:
	/* 0x4489: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_448e:
	/* 0x448e: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4492:
	/* 0x4492: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_4497:
	/* 0x4497: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4499:
	/* 0x4499: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_449b:
	/* 0x449b: cmp    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_44a0:
	/* 0x44a0: jne    1d5a <perf_unwind_python+0x1d5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7514ULL;
	}
x86_l_44a6:
	/* 0x44a6: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_44a9:
	/* 0x44a9: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_44af:
	/* 0x44af: je     45b4 <perf_unwind_python+0x45b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17844ULL;
	}
x86_l_44b5:
	/* 0x44b5: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44b9:
	/* 0x44b9: cmp    BYTE PTR [rax+0x19],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 107374182520ULL);
x86_l_44bd:
	/* 0x44bd: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_44c3:
	/* 0x44c3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44c7:
	/* 0x44c7: cmp    BYTE PTR [rax+0x18],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215224ULL);
x86_l_44cb:
	/* 0x44cb: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_44d1:
	/* 0x44d1: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44d5:
	/* 0x44d5: cmp    BYTE PTR [rax+0x1a],0x78 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 111669149816ULL);
x86_l_44d9:
	/* 0x44d9: ja     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 17816ULL;
	}
x86_l_44df:
	/* 0x44df: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 17635ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 17635ULL: goto x86_l_44e3;
	case 17639ULL: goto x86_l_44e7;
	case 17645ULL: goto x86_l_44ed;
	case 17650ULL: goto x86_l_44f2;
	case 17655ULL: goto x86_l_44f7;
	case 17660ULL: goto x86_l_44fc;
	case 17665ULL: goto x86_l_4501;
	case 17670ULL: goto x86_l_4506;
	case 17672ULL: goto x86_l_4508;
	case 17675ULL: goto x86_l_450b;
	case 17681ULL: goto x86_l_4511;
	case 17685ULL: goto x86_l_4515;
	case 17689ULL: goto x86_l_4519;
	case 17694ULL: goto x86_l_451e;
	case 17698ULL: goto x86_l_4522;
	case 17703ULL: goto x86_l_4527;
	case 17707ULL: goto x86_l_452b;
	case 17711ULL: goto x86_l_452f;
	case 17715ULL: goto x86_l_4533;
	case 17718ULL: goto x86_l_4536;
	case 17720ULL: goto x86_l_4538;
	case 17725ULL: goto x86_l_453d;
	case 17731ULL: goto x86_l_4543;
	case 17735ULL: goto x86_l_4547;
	case 17739ULL: goto x86_l_454b;
	case 17743ULL: goto x86_l_454f;
	case 17745ULL: goto x86_l_4551;
	case 17750ULL: goto x86_l_4556;
	case 17754ULL: goto x86_l_455a;
	case 17758ULL: goto x86_l_455e;
	case 17762ULL: goto x86_l_4562;
	case 17767ULL: goto x86_l_4567;
	case 17770ULL: goto x86_l_456a;
	case 17777ULL: goto x86_l_4571;
	case 17779ULL: goto x86_l_4573;
	case 17786ULL: goto x86_l_457a;
	case 17792ULL: goto x86_l_4580;
	case 17796ULL: goto x86_l_4584;
	case 17800ULL: goto x86_l_4588;
	case 17804ULL: goto x86_l_458c;
	case 17807ULL: goto x86_l_458f;
	case 17810ULL: goto x86_l_4592;
	case 17814ULL: goto x86_l_4596;
	case 17816ULL: goto x86_l_4598;
	case 17818ULL: goto x86_l_459a;
	case 17823ULL: goto x86_l_459f;
	case 17829ULL: goto x86_l_45a5;
	case 17834ULL: goto x86_l_45aa;
	case 17839ULL: goto x86_l_45af;
	case 17844ULL: goto x86_l_45b4;
	case 17846ULL: goto x86_l_45b6;
	case 17849ULL: goto x86_l_45b9;
	case 17851ULL: goto x86_l_45bb;
	case 17856ULL: goto x86_l_45c0;
	case 17860ULL: goto x86_l_45c4;
	case 17868ULL: goto x86_l_45cc;
	case 17874ULL: goto x86_l_45d2;
	case 17876ULL: goto x86_l_45d4;
	case 17880ULL: goto x86_l_45d8;
	case 17884ULL: goto x86_l_45dc;
	case 17886ULL: goto x86_l_45de;
	case 17890ULL: goto x86_l_45e2;
	case 17894ULL: goto x86_l_45e6;
	case 17896ULL: goto x86_l_45e8;
	case 17900ULL: goto x86_l_45ec;
	case 17904ULL: goto x86_l_45f0;
	case 17906ULL: goto x86_l_45f2;
	case 17910ULL: goto x86_l_45f6;
	case 17914ULL: goto x86_l_45fa;
	case 17920ULL: goto x86_l_4600;
	case 17922ULL: goto x86_l_4602;
	case 17924ULL: goto x86_l_4604;
	case 17928ULL: goto x86_l_4608;
	case 17934ULL: goto x86_l_460e;
	case 17944ULL: goto x86_l_4618;
	case 17949ULL: goto x86_l_461d;
	case 17959ULL: goto x86_l_4627;
	case 17964ULL: goto x86_l_462c;
	case 17974ULL: goto x86_l_4636;
	case 17979ULL: goto x86_l_463b;
	case 17989ULL: goto x86_l_4645;
	case 17994ULL: goto x86_l_464a;
	case 18004ULL: goto x86_l_4654;
	case 18009ULL: goto x86_l_4659;
	case 18019ULL: goto x86_l_4663;
	case 18024ULL: goto x86_l_4668;
	case 18029ULL: goto x86_l_466d;
	case 18034ULL: goto x86_l_4672;
	case 18040ULL: goto x86_l_4678;
	case 18044ULL: goto x86_l_467c;
	case 18048ULL: goto x86_l_4680;
	case 18053ULL: goto x86_l_4685;
	case 18056ULL: goto x86_l_4688;
	case 18061ULL: goto x86_l_468d;
	case 18063ULL: goto x86_l_468f;
	case 18066ULL: goto x86_l_4692;
	case 18074ULL: goto x86_l_469a;
	case 18081ULL: goto x86_l_46a1;
	case 18086ULL: goto x86_l_46a6;
	case 18091ULL: goto x86_l_46ab;
	case 18093ULL: goto x86_l_46ad;
	case 18096ULL: goto x86_l_46b0;
	case 18098ULL: goto x86_l_46b2;
	case 18101ULL: goto x86_l_46b5;
	case 18106ULL: goto x86_l_46ba;
	case 18111ULL: goto x86_l_46bf;
	case 18116ULL: goto x86_l_46c4;
	case 18121ULL: goto x86_l_46c9;
	case 18124ULL: goto x86_l_46cc;
	case 18129ULL: goto x86_l_46d1;
	case 18131ULL: goto x86_l_46d3;
	case 18134ULL: goto x86_l_46d6;
	case 18140ULL: goto x86_l_46dc;
	case 18144ULL: goto x86_l_46e0;
	case 18148ULL: goto x86_l_46e4;
	case 18152ULL: goto x86_l_46e8;
	case 18156ULL: goto x86_l_46ec;
	case 18160ULL: goto x86_l_46f0;
	case 18164ULL: goto x86_l_46f4;
	case 18168ULL: goto x86_l_46f8;
	case 18172ULL: goto x86_l_46fc;
	case 18175ULL: goto x86_l_46ff;
	case 18178ULL: goto x86_l_4702;
	case 18180ULL: goto x86_l_4704;
	case 18183ULL: goto x86_l_4707;
	case 18185ULL: goto x86_l_4709;
	case 18189ULL: goto x86_l_470d;
	case 18193ULL: goto x86_l_4711;
	case 18196ULL: goto x86_l_4714;
	case 18201ULL: goto x86_l_4719;
	case 18205ULL: goto x86_l_471d;
	case 18207ULL: goto x86_l_471f;
	case 18217ULL: goto x86_l_4729;
	case 18222ULL: goto x86_l_472e;
	case 18232ULL: goto x86_l_4738;
	case 18237ULL: goto x86_l_473d;
	case 18247ULL: goto x86_l_4747;
	case 18252ULL: goto x86_l_474c;
	case 18262ULL: goto x86_l_4756;
	case 18267ULL: goto x86_l_475b;
	case 18277ULL: goto x86_l_4765;
	case 18282ULL: goto x86_l_476a;
	case 18292ULL: goto x86_l_4774;
	case 18297ULL: goto x86_l_4779;
	case 18302ULL: goto x86_l_477e;
	case 18307ULL: goto x86_l_4783;
	case 18312ULL: goto x86_l_4788;
	case 18316ULL: goto x86_l_478c;
	case 18321ULL: goto x86_l_4791;
	case 18323ULL: goto x86_l_4793;
	case 18325ULL: goto x86_l_4795;
	case 18332ULL: goto x86_l_479c;
	case 18334ULL: goto x86_l_479e;
	case 18339ULL: goto x86_l_47a3;
	case 18343ULL: goto x86_l_47a7;
	case 18345ULL: goto x86_l_47a9;
	case 18355ULL: goto x86_l_47b3;
	case 18360ULL: goto x86_l_47b8;
	case 18370ULL: goto x86_l_47c2;
	case 18375ULL: goto x86_l_47c7;
	case 18385ULL: goto x86_l_47d1;
	case 18390ULL: goto x86_l_47d6;
	case 18395ULL: goto x86_l_47db;
	case 18400ULL: goto x86_l_47e0;
	case 18406ULL: goto x86_l_47e6;
	case 18411ULL: goto x86_l_47eb;
	case 18416ULL: goto x86_l_47f0;
	case 18419ULL: goto x86_l_47f3;
	case 18421ULL: goto x86_l_47f5;
	case 18424ULL: goto x86_l_47f8;
	case 18430ULL: goto x86_l_47fe;
	case 18434ULL: goto x86_l_4802;
	case 18440ULL: goto x86_l_4808;
	case 18443ULL: goto x86_l_480b;
	case 18449ULL: goto x86_l_4811;
	case 18453ULL: goto x86_l_4815;
	case 18458ULL: goto x86_l_481a;
	case 18466ULL: goto x86_l_4822;
	case 18474ULL: goto x86_l_482a;
	case 18482ULL: goto x86_l_4832;
	case 18493ULL: goto x86_l_483d;
	case 18504ULL: goto x86_l_4848;
	case 18512ULL: goto x86_l_4850;
	case 18519ULL: goto x86_l_4857;
	case 18524ULL: goto x86_l_485c;
	case 18529ULL: goto x86_l_4861;
	case 18531ULL: goto x86_l_4863;
	case 18534ULL: goto x86_l_4866;
	case 18536ULL: goto x86_l_4868;
	case 18539ULL: goto x86_l_486b;
	case 18541ULL: goto x86_l_486d;
	case 18545ULL: goto x86_l_4871;
	case 18547ULL: goto x86_l_4873;
	case 18557ULL: goto x86_l_487d;
	case 18562ULL: goto x86_l_4882;
	case 18572ULL: goto x86_l_488c;
	case 18577ULL: goto x86_l_4891;
	case 18587ULL: goto x86_l_489b;
	case 18592ULL: goto x86_l_48a0;
	case 18602ULL: goto x86_l_48aa;
	case 18607ULL: goto x86_l_48af;
	case 18617ULL: goto x86_l_48b9;
	case 18622ULL: goto x86_l_48be;
	case 18632ULL: goto x86_l_48c8;
	case 18637ULL: goto x86_l_48cd;
	case 18642ULL: goto x86_l_48d2;
	case 18647ULL: goto x86_l_48d7;
	case 18652ULL: goto x86_l_48dc;
	case 18656ULL: goto x86_l_48e0;
	case 18661ULL: goto x86_l_48e5;
	case 18663ULL: goto x86_l_48e7;
	case 18665ULL: goto x86_l_48e9;
	case 18670ULL: goto x86_l_48ee;
	case 18676ULL: goto x86_l_48f4;
	case 18682ULL: goto x86_l_48fa;
	case 18685ULL: goto x86_l_48fd;
	case 18687ULL: goto x86_l_48ff;
	case 18690ULL: goto x86_l_4902;
	case 18693ULL: goto x86_l_4905;
	case 18698ULL: goto x86_l_490a;
	case 18703ULL: goto x86_l_490f;
	case 18708ULL: goto x86_l_4914;
	case 18711ULL: goto x86_l_4917;
	case 18714ULL: goto x86_l_491a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_44e3:
	/* 0x44e3: cmp    BYTE PTR [rax+0x1b],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 115964116992ULL);
x86_l_44e7:
	/* 0x44e7: js     4598 <perf_unwind_python+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4598;
	}
x86_l_44ed:
	/* 0x44ed: mov    eax,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 128ULL);
x86_l_44f2:
	/* 0x44f2: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_44f7:
	/* 0x44f7: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_44fc:
	/* 0x44fc: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4501:
	/* 0x4501: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_4506:
	/* 0x4506: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4508:
	/* 0x4508: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_450b:
	/* 0x450b: jne    d56 <perf_unwind_python+0xd56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3414ULL;
	}
x86_l_4511:
	/* 0x4511: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4515:
	/* 0x4515: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_4519:
	/* 0x4519: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_451e:
	/* 0x451e: mov    rcx,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4522:
	/* 0x4522: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4527:
	/* 0x4527: movzx  ecx,BYTE PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_452b:
	/* 0x452b: mov    r13,QWORD PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_452f:
	/* 0x452f: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4533:
	/* 0x4533: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4536:
	/* 0x4536: je     4543 <perf_unwind_python+0x4543> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4543;
	}
x86_l_4538:
	/* 0x4538: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_453d:
	/* 0x453d: je     1242 <perf_unwind_python+0x1242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4674ULL;
	}
x86_l_4543:
	/* 0x4543: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4547:
	/* 0x4547: cmp    BYTE PTR [rax+0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_454b:
	/* 0x454b: movzx  eax,BYTE PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 26ULL);
x86_l_454f:
	/* 0x454f: je     45bb <perf_unwind_python+0x45bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45bb;
	}
x86_l_4551:
	/* 0x4551: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4556:
	/* 0x4556: mov    rax,QWORD PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_455a:
	/* 0x455a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_455e:
	/* 0x455e: movzx  edx,BYTE PTR [rcx+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_4562:
	/* 0x4562: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_4567:
	/* 0x4567: sub    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_456a:
	/* 0x456a: lea    rdx,[rax-0x10000001] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073441116159ULL);
x86_l_4571:
	/* 0x4571: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_4573:
	/* 0x4573: cmp    rdx,0xffffffffeffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073441116157ULL);
x86_l_457a:
	/* 0x457a: mov    r12d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_4580:
	/* 0x4580: cmovae r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_4584:
	/* 0x4584: movzx  eax,BYTE PTR [rcx+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_4588:
	/* 0x4588: movzx  eax,BYTE PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_458c:
	/* 0x458c: cmp    al,BYTE PTR [rcx+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_458f:
	/* 0x458f: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_4592:
	/* 0x4592: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4596:
	/* 0x4596: jmp    45cc <perf_unwind_python+0x45cc> */
	goto x86_l_45cc;
x86_l_4598:
	/* 0x4598: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_459a:
	/* 0x459a: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_459f:
	/* 0x459f: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_45a5:
	/* 0x45a5: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45aa:
	/* 0x45aa: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45af:
	/* 0x45af: jmp    168 <perf_unwind_python+0x168> */
	return 360ULL;
x86_l_45b4:
	/* 0x45b4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_45b6:
	/* 0x45b6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_45b9:
	/* 0x45b9: jmp    45a5 <perf_unwind_python+0x45a5> */
	goto x86_l_45a5;
x86_l_45bb:
	/* 0x45bb: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_45c0:
	/* 0x45c0: mov    r12d,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_45c4:
	/* 0x45c4: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_45cc:
	/* 0x45cc: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_45d2:
	/* 0x45d2: je     4604 <perf_unwind_python+0x4604> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4604;
	}
x86_l_45d4:
	/* 0x45d4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45d8:
	/* 0x45d8: cmp    BYTE PTR [rax+0x1d],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051772ULL);
x86_l_45dc:
	/* 0x45dc: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4600;
	}
x86_l_45de:
	/* 0x45de: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45e2:
	/* 0x45e2: cmp    BYTE PTR [rax+0x1e],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128849019068ULL);
x86_l_45e6:
	/* 0x45e6: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4600;
	}
x86_l_45e8:
	/* 0x45e8: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45ec:
	/* 0x45ec: cmp    BYTE PTR [rax+0x1f],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133143986364ULL);
x86_l_45f0:
	/* 0x45f0: ja     4600 <perf_unwind_python+0x4600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4600;
	}
x86_l_45f2:
	/* 0x45f2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45f6:
	/* 0x45f6: cmp    BYTE PTR [rax+0x20],0xbc */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953660ULL);
x86_l_45fa:
	/* 0x45fa: jbe    46ba <perf_unwind_python+0x46ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_46ba;
	}
x86_l_4600:
	/* 0x4600: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4602:
	/* 0x4602: jmp    459f <perf_unwind_python+0x459f> */
	goto x86_l_459f;
x86_l_4604:
	/* 0x4604: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4608:
	/* 0x4608: je     4692 <perf_unwind_python+0x4692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4692;
	}
x86_l_460e:
	/* 0x460e: movabs rax,0xa786c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541280ULL);
x86_l_4618:
	/* 0x4618: mov    QWORD PTR [rsp+0x57],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_461d:
	/* 0x461d: movabs rax,0x20786c2578302074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2339738914604982388ULL);
x86_l_4627:
	/* 0x4627: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_462c:
	/* 0x462c: movabs rax,0x63656a624f656d61 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7162247752874028385ULL);
x86_l_4636:
	/* 0x4636: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_463b:
	/* 0x463b: movabs rax,0x7246795020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8234402353742245734ULL);
x86_l_4645:
	/* 0x4645: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_464a:
	/* 0x464a: movabs rax,0x207463656a626f65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338603393739812709ULL);
x86_l_4654:
	/* 0x4654: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4659:
	/* 0x4659: movabs rax,0x646f63206c6c754e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7237112117116826958ULL);
x86_l_4663:
	/* 0x4663: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4668:
	/* 0x4668: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_466d:
	/* 0x466d: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_4672:
	/* 0x4672: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_4678:
	/* 0x4678: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_467c:
	/* 0x467c: movzx  ecx,BYTE PTR [rax+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_4680:
	/* 0x4680: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4685:
	/* 0x4685: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4688:
	/* 0x4688: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_468d:
	/* 0x468d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_468f:
	/* 0x468f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4692:
	/* 0x4692: mov    DWORD PTR [rsp+0x18],0x1c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215132ULL);
x86_l_469a:
	/* 0x469a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_46a1:
	/* 0x46a1: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_46a6:
	/* 0x46a6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_46ab:
	/* 0x46ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46ad:
	/* 0x46ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_46b0:
	/* 0x46b0: je     4719 <perf_unwind_python+0x4719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4719;
	}
x86_l_46b2:
	/* 0x46b2: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_46b5:
	/* 0x46b5: jmp    4795 <perf_unwind_python+0x4795> */
	goto x86_l_4795;
x86_l_46ba:
	/* 0x46ba: mov    eax,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 192ULL);
x86_l_46bf:
	/* 0x46bf: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_46c4:
	/* 0x46c4: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_46c9:
	/* 0x46c9: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_46cc:
	/* 0x46cc: mov    esi,0xc0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 192ULL);
x86_l_46d1:
	/* 0x46d1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_46d3:
	/* 0x46d3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_46d6:
	/* 0x46d6: jne    2b5 <perf_unwind_python+0x2b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 693ULL;
	}
x86_l_46dc:
	/* 0x46dc: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46e0:
	/* 0x46e0: movzx  ecx,BYTE PTR [rax+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_46e4:
	/* 0x46e4: mov    ecx,DWORD PTR [r15+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_46e8:
	/* 0x46e8: movzx  edx,BYTE PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_46ec:
	/* 0x46ec: mov    edx,DWORD PTR [r15+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_46f0:
	/* 0x46f0: movzx  esi,BYTE PTR [rax+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_46f4:
	/* 0x46f4: mov    esi,DWORD PTR [r15+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_46f8:
	/* 0x46f8: movzx  eax,BYTE PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_46fc:
	/* 0x46fc: shl    ecx,0x19 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 25ULL);
x86_l_46ff:
	/* 0x46ff: shl    edx,0x12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 18ULL);
x86_l_4702:
	/* 0x4702: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4704:
	/* 0x4704: shl    esi,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 10ULL);
x86_l_4707:
	/* 0x4707: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4709:
	/* 0x4709: add    esi,DWORD PTR [r15+rax*1] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R15, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_470d:
	/* 0x470d: shl    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_4711:
	/* 0x4711: or     r12,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RSI, X86_WIDTH_64, X86_ALU_OR);
x86_l_4714:
	/* 0x4714: jmp    47a3 <perf_unwind_python+0x47a3> */
	goto x86_l_47a3;
x86_l_4719:
	/* 0x4719: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_471d:
	/* 0x471d: je     4795 <perf_unwind_python+0x4795> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4795;
	}
x86_l_471f:
	/* 0x471f: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_4729:
	/* 0x4729: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_472e:
	/* 0x472e: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_4738:
	/* 0x4738: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_473d:
	/* 0x473d: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_4747:
	/* 0x4747: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_474c:
	/* 0x474c: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_4756:
	/* 0x4756: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_475b:
	/* 0x475b: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_4765:
	/* 0x4765: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_476a:
	/* 0x476a: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_4774:
	/* 0x4774: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4779:
	/* 0x4779: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_477e:
	/* 0x477e: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_4783:
	/* 0x4783: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4788:
	/* 0x4788: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_478c:
	/* 0x478c: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_4791:
	/* 0x4791: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4793:
	/* 0x4793: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4795:
	/* 0x4795: mov    r12,0xfffffffffffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_479c:
	/* 0x479c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_479e:
	/* 0x479e: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_47a3:
	/* 0x47a3: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47a7:
	/* 0x47a7: je     47f8 <perf_unwind_python+0x47f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47f8;
	}
x86_l_47a9:
	/* 0x47a9: movabs rax,0xa756c2520786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2943857106909292ULL);
x86_l_47b3:
	/* 0x47b3: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_47b8:
	/* 0x47b8: movabs rax,0x25206e6f68747950 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675259603430963536ULL);
x86_l_47c2:
	/* 0x47c2: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_47c7:
	/* 0x47c7: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_47d1:
	/* 0x47d1: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_47d6:
	/* 0x47d6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_47db:
	/* 0x47db: mov    eax,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_47e0:
	/* 0x47e0: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_47e6:
	/* 0x47e6: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_47eb:
	/* 0x47eb: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_47f0:
	/* 0x47f0: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_47f3:
	/* 0x47f3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_47f5:
	/* 0x47f5: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_47f8:
	/* 0x47f8: mov    eax,DWORD PTR [rbp+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_47fe:
	/* 0x47fe: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_4802:
	/* 0x4802: ja     176d <perf_unwind_python+0x176d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5997ULL;
	}
x86_l_4808:
	/* 0x4808: lea    ecx,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_480b:
	/* 0x480b: mov    DWORD PTR [rbp+0x2c0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_4811:
	/* 0x4811: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_4815:
	/* 0x4815: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_481a:
	/* 0x481a: mov    QWORD PTR [rbp+rax*8+0x2d0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_4822:
	/* 0x4822: mov    QWORD PTR [rbp+rax*8+0x2d8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_482a:
	/* 0x482a: mov    BYTE PTR [rbp+rax*8+0x2e0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929857ULL);
x86_l_4832:
	/* 0x4832: mov    DWORD PTR [rbp+rax*8+0x2e1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3165390897152ULL);
x86_l_483d:
	/* 0x483d: mov    DWORD PTR [rbp+rax*8+0x2e4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3178275799040ULL);
x86_l_4848:
	/* 0x4848: mov    DWORD PTR [rsp+0x18],0x16 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215126ULL);
x86_l_4850:
	/* 0x4850: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_4857:
	/* 0x4857: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_485c:
	/* 0x485c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4861:
	/* 0x4861: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4863:
	/* 0x4863: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4866:
	/* 0x4866: je     486d <perf_unwind_python+0x486d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_486d;
	}
x86_l_4868:
	/* 0x4868: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_486b:
	/* 0x486b: jmp    48e9 <perf_unwind_python+0x48e9> */
	goto x86_l_48e9;
x86_l_486d:
	/* 0x486d: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4871:
	/* 0x4871: je     48e9 <perf_unwind_python+0x48e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48e9;
	}
x86_l_4873:
	/* 0x4873: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_487d:
	/* 0x487d: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_4882:
	/* 0x4882: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_488c:
	/* 0x488c: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4891:
	/* 0x4891: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_489b:
	/* 0x489b: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_48a0:
	/* 0x48a0: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_48aa:
	/* 0x48aa: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_48af:
	/* 0x48af: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_48b9:
	/* 0x48b9: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_48be:
	/* 0x48be: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_48c8:
	/* 0x48c8: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_48cd:
	/* 0x48cd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_48d2:
	/* 0x48d2: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_48d7:
	/* 0x48d7: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_48dc:
	/* 0x48dc: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_48e0:
	/* 0x48e0: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_48e5:
	/* 0x48e5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_48e7:
	/* 0x48e7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_48e9:
	/* 0x48e9: cmp    BYTE PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_48ee:
	/* 0x48ee: jne    1242 <perf_unwind_python+0x1242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4674ULL;
	}
x86_l_48f4:
	/* 0x48f4: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_48fa:
	/* 0x48fa: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_48fd:
	/* 0x48fd: je     4914 <perf_unwind_python+0x4914> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4914;
	}
x86_l_48ff:
	/* 0x48ff: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_4902:
	/* 0x4902: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4905:
	/* 0x4905: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_490a:
	/* 0x490a: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_490f:
	/* 0x490f: jmp    175 <perf_unwind_python+0x175> */
	return 373ULL;
x86_l_4914:
	/* 0x4914: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4917:
	/* 0x4917: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_491a:
	/* 0x491a: jmp    d77 <perf_unwind_python+0xd77> */
	return 3447ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int otelcol_ebpf_profiler_perf_unwind_python_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 14720U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1794ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1797ULL && __x86_pc <= 3686ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3690ULL && __x86_pc <= 5849ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5854ULL && __x86_pc <= 7942ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7944ULL && __x86_pc <= 9861ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9867ULL && __x86_pc <= 11858ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 11860ULL && __x86_pc <= 13751ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 13761ULL && __x86_pc <= 15683ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 15689ULL && __x86_pc <= 17631ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 17635ULL && __x86_pc <= 18714ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_python_x86_chunk_9(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

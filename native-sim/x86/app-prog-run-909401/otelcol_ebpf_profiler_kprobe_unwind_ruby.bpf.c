extern char metrics;
extern char per_cpu_records;
extern char perf_progs;
extern char ruby_procs;
extern char tpbase_offset;
extern char with_debug_output;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_0(
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
	case 54ULL: goto x86_l_36;
	case 61ULL: goto x86_l_3d;
	case 68ULL: goto x86_l_44;
	case 76ULL: goto x86_l_4c;
	case 81ULL: goto x86_l_51;
	case 83ULL: goto x86_l_53;
	case 86ULL: goto x86_l_56;
	case 92ULL: goto x86_l_5c;
	case 95ULL: goto x86_l_5f;
	case 103ULL: goto x86_l_67;
	case 110ULL: goto x86_l_6e;
	case 115ULL: goto x86_l_73;
	case 120ULL: goto x86_l_78;
	case 122ULL: goto x86_l_7a;
	case 125ULL: goto x86_l_7d;
	case 131ULL: goto x86_l_83;
	case 134ULL: goto x86_l_86;
	case 143ULL: goto x86_l_8f;
	case 148ULL: goto x86_l_94;
	case 154ULL: goto x86_l_9a;
	case 161ULL: goto x86_l_a1;
	case 167ULL: goto x86_l_a7;
	case 176ULL: goto x86_l_b0;
	case 180ULL: goto x86_l_b4;
	case 185ULL: goto x86_l_b9;
	case 190ULL: goto x86_l_be;
	case 196ULL: goto x86_l_c4;
	case 200ULL: goto x86_l_c8;
	case 205ULL: goto x86_l_cd;
	case 208ULL: goto x86_l_d0;
	case 211ULL: goto x86_l_d3;
	case 217ULL: goto x86_l_d9;
	case 222ULL: goto x86_l_de;
	case 227ULL: goto x86_l_e3;
	case 232ULL: goto x86_l_e8;
	case 237ULL: goto x86_l_ed;
	case 243ULL: goto x86_l_f3;
	case 248ULL: goto x86_l_f8;
	case 253ULL: goto x86_l_fd;
	case 258ULL: goto x86_l_102;
	case 265ULL: goto x86_l_109;
	case 269ULL: goto x86_l_10d;
	case 275ULL: goto x86_l_113;
	case 283ULL: goto x86_l_11b;
	case 290ULL: goto x86_l_122;
	case 295ULL: goto x86_l_127;
	case 300ULL: goto x86_l_12c;
	case 302ULL: goto x86_l_12e;
	case 305ULL: goto x86_l_131;
	case 311ULL: goto x86_l_137;
	case 314ULL: goto x86_l_13a;
	case 319ULL: goto x86_l_13f;
	case 326ULL: goto x86_l_146;
	case 329ULL: goto x86_l_149;
	case 335ULL: goto x86_l_14f;
	case 344ULL: goto x86_l_158;
	case 349ULL: goto x86_l_15d;
	case 355ULL: goto x86_l_163;
	case 360ULL: goto x86_l_168;
	case 362ULL: goto x86_l_16a;
	case 369ULL: goto x86_l_171;
	case 372ULL: goto x86_l_174;
	case 377ULL: goto x86_l_179;
	case 382ULL: goto x86_l_17e;
	case 388ULL: goto x86_l_184;
	case 393ULL: goto x86_l_189;
	case 396ULL: goto x86_l_18c;
	case 399ULL: goto x86_l_18f;
	case 402ULL: goto x86_l_192;
	case 408ULL: goto x86_l_198;
	case 415ULL: goto x86_l_19f;
	case 418ULL: goto x86_l_1a2;
	case 424ULL: goto x86_l_1a8;
	case 432ULL: goto x86_l_1b0;
	case 439ULL: goto x86_l_1b7;
	case 444ULL: goto x86_l_1bc;
	case 449ULL: goto x86_l_1c1;
	case 451ULL: goto x86_l_1c3;
	case 454ULL: goto x86_l_1c6;
	case 460ULL: goto x86_l_1cc;
	case 463ULL: goto x86_l_1cf;
	case 466ULL: goto x86_l_1d2;
	case 472ULL: goto x86_l_1d8;
	case 482ULL: goto x86_l_1e2;
	case 487ULL: goto x86_l_1e7;
	case 497ULL: goto x86_l_1f1;
	case 502ULL: goto x86_l_1f6;
	case 512ULL: goto x86_l_200;
	case 517ULL: goto x86_l_205;
	case 527ULL: goto x86_l_20f;
	case 532ULL: goto x86_l_214;
	case 542ULL: goto x86_l_21e;
	case 547ULL: goto x86_l_223;
	case 557ULL: goto x86_l_22d;
	case 562ULL: goto x86_l_232;
	case 570ULL: goto x86_l_23a;
	case 575ULL: goto x86_l_23f;
	case 580ULL: goto x86_l_244;
	case 585ULL: goto x86_l_249;
	case 590ULL: goto x86_l_24e;
	case 592ULL: goto x86_l_250;
	case 594ULL: goto x86_l_252;
	case 599ULL: goto x86_l_257;
	case 603ULL: goto x86_l_25b;
	case 610ULL: goto x86_l_262;
	case 615ULL: goto x86_l_267;
	case 620ULL: goto x86_l_26c;
	case 626ULL: goto x86_l_272;
	case 631ULL: goto x86_l_277;
	case 636ULL: goto x86_l_27c;
	case 641ULL: goto x86_l_281;
	case 646ULL: goto x86_l_286;
	case 648ULL: goto x86_l_288;
	case 651ULL: goto x86_l_28b;
	case 657ULL: goto x86_l_291;
	case 660ULL: goto x86_l_294;
	case 662ULL: goto x86_l_296;
	case 666ULL: goto x86_l_29a;
	case 672ULL: goto x86_l_2a0;
	case 678ULL: goto x86_l_2a6;
	case 683ULL: goto x86_l_2ab;
	case 690ULL: goto x86_l_2b2;
	case 698ULL: goto x86_l_2ba;
	case 705ULL: goto x86_l_2c1;
	case 710ULL: goto x86_l_2c6;
	case 715ULL: goto x86_l_2cb;
	case 717ULL: goto x86_l_2cd;
	case 720ULL: goto x86_l_2d0;
	case 722ULL: goto x86_l_2d2;
	case 729ULL: goto x86_l_2d9;
	case 732ULL: goto x86_l_2dc;
	case 738ULL: goto x86_l_2e2;
	case 741ULL: goto x86_l_2e5;
	case 751ULL: goto x86_l_2ef;
	case 759ULL: goto x86_l_2f7;
	case 766ULL: goto x86_l_2fe;
	case 771ULL: goto x86_l_303;
	case 776ULL: goto x86_l_308;
	case 778ULL: goto x86_l_30a;
	case 781ULL: goto x86_l_30d;
	case 783ULL: goto x86_l_30f;
	case 786ULL: goto x86_l_312;
	case 788ULL: goto x86_l_314;
	case 795ULL: goto x86_l_31b;
	case 797ULL: goto x86_l_31d;
	case 802ULL: goto x86_l_322;
	case 805ULL: goto x86_l_325;
	case 807ULL: goto x86_l_327;
	case 812ULL: goto x86_l_32c;
	case 816ULL: goto x86_l_330;
	case 821ULL: goto x86_l_335;
	case 826ULL: goto x86_l_33a;
	case 832ULL: goto x86_l_340;
	case 836ULL: goto x86_l_344;
	case 841ULL: goto x86_l_349;
	case 844ULL: goto x86_l_34c;
	case 847ULL: goto x86_l_34f;
	case 852ULL: goto x86_l_354;
	case 855ULL: goto x86_l_357;
	case 861ULL: goto x86_l_35d;
	case 866ULL: goto x86_l_362;
	case 869ULL: goto x86_l_365;
	case 871ULL: goto x86_l_367;
	case 876ULL: goto x86_l_36c;
	case 879ULL: goto x86_l_36f;
	case 885ULL: goto x86_l_375;
	case 887ULL: goto x86_l_377;
	case 889ULL: goto x86_l_379;
	case 896ULL: goto x86_l_380;
	case 899ULL: goto x86_l_383;
	case 905ULL: goto x86_l_389;
	case 908ULL: goto x86_l_38c;
	case 916ULL: goto x86_l_394;
	case 918ULL: goto x86_l_396;
	case 920ULL: goto x86_l_398;
	case 926ULL: goto x86_l_39e;
	case 928ULL: goto x86_l_3a0;
	case 935ULL: goto x86_l_3a7;
	case 940ULL: goto x86_l_3ac;
	case 943ULL: goto x86_l_3af;
	case 945ULL: goto x86_l_3b1;
	case 947ULL: goto x86_l_3b3;
	case 952ULL: goto x86_l_3b8;
	case 959ULL: goto x86_l_3bf;
	case 961ULL: goto x86_l_3c1;
	case 962ULL: goto x86_l_3c2;
	case 967ULL: goto x86_l_3c7;
	case 972ULL: goto x86_l_3cc;
	case 978ULL: goto x86_l_3d2;
	case 983ULL: goto x86_l_3d7;
	case 986ULL: goto x86_l_3da;
	case 992ULL: goto x86_l_3e0;
	case 999ULL: goto x86_l_3e7;
	case 1004ULL: goto x86_l_3ec;
	case 1007ULL: goto x86_l_3ef;
	case 1013ULL: goto x86_l_3f5;
	case 1020ULL: goto x86_l_3fc;
	case 1023ULL: goto x86_l_3ff;
	case 1029ULL: goto x86_l_405;
	case 1032ULL: goto x86_l_408;
	case 1041ULL: goto x86_l_411;
	case 1050ULL: goto x86_l_41a;
	case 1055ULL: goto x86_l_41f;
	case 1058ULL: goto x86_l_422;
	case 1063ULL: goto x86_l_427;
	case 1068ULL: goto x86_l_42c;
	case 1074ULL: goto x86_l_432;
	case 1079ULL: goto x86_l_437;
	case 1084ULL: goto x86_l_43c;
	case 1089ULL: goto x86_l_441;
	case 1092ULL: goto x86_l_444;
	case 1097ULL: goto x86_l_449;
	case 1102ULL: goto x86_l_44e;
	case 1107ULL: goto x86_l_453;
	case 1112ULL: goto x86_l_458;
	case 1118ULL: goto x86_l_45e;
	case 1123ULL: goto x86_l_463;
	case 1128ULL: goto x86_l_468;
	case 1133ULL: goto x86_l_46d;
	case 1136ULL: goto x86_l_470;
	case 1142ULL: goto x86_l_476;
	case 1148ULL: goto x86_l_47c;
	case 1153ULL: goto x86_l_481;
	case 1156ULL: goto x86_l_484;
	case 1162ULL: goto x86_l_48a;
	case 1167ULL: goto x86_l_48f;
	case 1170ULL: goto x86_l_492;
	case 1175ULL: goto x86_l_497;
	case 1180ULL: goto x86_l_49c;
	case 1186ULL: goto x86_l_4a2;
	case 1191ULL: goto x86_l_4a7;
	case 1196ULL: goto x86_l_4ac;
	case 1201ULL: goto x86_l_4b1;
	case 1204ULL: goto x86_l_4b4;
	case 1207ULL: goto x86_l_4b7;
	case 1213ULL: goto x86_l_4bd;
	case 1220ULL: goto x86_l_4c4;
	case 1224ULL: goto x86_l_4c8;
	case 1230ULL: goto x86_l_4ce;
	case 1237ULL: goto x86_l_4d5;
	case 1244ULL: goto x86_l_4dc;
	case 1247ULL: goto x86_l_4df;
	case 1252ULL: goto x86_l_4e4;
	case 1254ULL: goto x86_l_4e6;
	case 1257ULL: goto x86_l_4e9;
	case 1263ULL: goto x86_l_4ef;
	case 1266ULL: goto x86_l_4f2;
	case 1271ULL: goto x86_l_4f7;
	case 1276ULL: goto x86_l_4fc;
	case 1279ULL: goto x86_l_4ff;
	case 1284ULL: goto x86_l_504;
	case 1289ULL: goto x86_l_509;
	case 1295ULL: goto x86_l_50f;
	case 1300ULL: goto x86_l_514;
	case 1303ULL: goto x86_l_517;
	case 1308ULL: goto x86_l_51c;
	case 1311ULL: goto x86_l_51f;
	case 1314ULL: goto x86_l_522;
	case 1320ULL: goto x86_l_528;
	case 1327ULL: goto x86_l_52f;
	case 1331ULL: goto x86_l_533;
	case 1337ULL: goto x86_l_539;
	case 1345ULL: goto x86_l_541;
	case 1352ULL: goto x86_l_548;
	case 1357ULL: goto x86_l_54d;
	case 1362ULL: goto x86_l_552;
	case 1364ULL: goto x86_l_554;
	case 1367ULL: goto x86_l_557;
	case 1373ULL: goto x86_l_55d;
	case 1376ULL: goto x86_l_560;
	case 1381ULL: goto x86_l_565;
	case 1388ULL: goto x86_l_56c;
	case 1394ULL: goto x86_l_572;
	case 1399ULL: goto x86_l_577;
	case 1402ULL: goto x86_l_57a;
	case 1407ULL: goto x86_l_57f;
	case 1410ULL: goto x86_l_582;
	case 1413ULL: goto x86_l_585;
	case 1419ULL: goto x86_l_58b;
	case 1424ULL: goto x86_l_590;
	case 1427ULL: goto x86_l_593;
	case 1432ULL: goto x86_l_598;
	case 1441ULL: goto x86_l_5a1;
	case 1450ULL: goto x86_l_5aa;
	case 1455ULL: goto x86_l_5af;
	case 1458ULL: goto x86_l_5b2;
	case 1463ULL: goto x86_l_5b7;
	case 1468ULL: goto x86_l_5bc;
	case 1474ULL: goto x86_l_5c2;
	case 1479ULL: goto x86_l_5c7;
	case 1484ULL: goto x86_l_5cc;
	case 1489ULL: goto x86_l_5d1;
	case 1492ULL: goto x86_l_5d4;
	case 1497ULL: goto x86_l_5d9;
	case 1502ULL: goto x86_l_5de;
	case 1507ULL: goto x86_l_5e3;
	case 1512ULL: goto x86_l_5e8;
	case 1518ULL: goto x86_l_5ee;
	case 1523ULL: goto x86_l_5f3;
	case 1528ULL: goto x86_l_5f8;
	case 1533ULL: goto x86_l_5fd;
	case 1536ULL: goto x86_l_600;
	case 1542ULL: goto x86_l_606;
	case 1548ULL: goto x86_l_60c;
	case 1553ULL: goto x86_l_611;
	case 1556ULL: goto x86_l_614;
	case 1562ULL: goto x86_l_61a;
	case 1567ULL: goto x86_l_61f;
	case 1570ULL: goto x86_l_622;
	case 1575ULL: goto x86_l_627;
	case 1580ULL: goto x86_l_62c;
	case 1586ULL: goto x86_l_632;
	case 1591ULL: goto x86_l_637;
	case 1596ULL: goto x86_l_63c;
	case 1601ULL: goto x86_l_641;
	case 1604ULL: goto x86_l_644;
	case 1607ULL: goto x86_l_647;
	case 1613ULL: goto x86_l_64d;
	case 1618ULL: goto x86_l_652;
	case 1623ULL: goto x86_l_657;
	case 1628ULL: goto x86_l_65c;
	case 1633ULL: goto x86_l_661;
	case 1639ULL: goto x86_l_667;
	case 1644ULL: goto x86_l_66c;
	case 1649ULL: goto x86_l_671;
	case 1654ULL: goto x86_l_676;
	case 1657ULL: goto x86_l_679;
	case 1660ULL: goto x86_l_67c;
	case 1666ULL: goto x86_l_682;
	case 1671ULL: goto x86_l_687;
	case 1676ULL: goto x86_l_68c;
	case 1681ULL: goto x86_l_691;
	case 1686ULL: goto x86_l_696;
	case 1692ULL: goto x86_l_69c;
	case 1697ULL: goto x86_l_6a1;
	case 1702ULL: goto x86_l_6a6;
	case 1707ULL: goto x86_l_6ab;
	case 1710ULL: goto x86_l_6ae;
	case 1713ULL: goto x86_l_6b1;
	case 1719ULL: goto x86_l_6b7;
	case 1724ULL: goto x86_l_6bc;
	case 1727ULL: goto x86_l_6bf;
	case 1732ULL: goto x86_l_6c4;
	case 1737ULL: goto x86_l_6c9;
	case 1740ULL: goto x86_l_6cc;
	case 1744ULL: goto x86_l_6d0;
	case 1750ULL: goto x86_l_6d6;
	case 1752ULL: goto x86_l_6d8;
	case 1755ULL: goto x86_l_6db;
	case 1760ULL: goto x86_l_6e0;
	case 1765ULL: goto x86_l_6e5;
	case 1768ULL: goto x86_l_6e8;
	case 1773ULL: goto x86_l_6ed;
	case 1778ULL: goto x86_l_6f2;
	case 1784ULL: goto x86_l_6f8;
	case 1789ULL: goto x86_l_6fd;
	case 1792ULL: goto x86_l_700;
	case 1797ULL: goto x86_l_705;
	case 1800ULL: goto x86_l_708;
	case 1803ULL: goto x86_l_70b;
	case 1809ULL: goto x86_l_711;
	case 1816ULL: goto x86_l_718;
	case 1820ULL: goto x86_l_71c;
	case 1826ULL: goto x86_l_722;
	case 1834ULL: goto x86_l_72a;
	case 1841ULL: goto x86_l_731;
	case 1846ULL: goto x86_l_736;
	case 1851ULL: goto x86_l_73b;
	case 1853ULL: goto x86_l_73d;
	case 1856ULL: goto x86_l_740;
	case 1862ULL: goto x86_l_746;
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
	/* 0x2b: je     3b3 <kprobe_unwind_ruby+0x3b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b3;
	}
x86_l_31:
	/* 0x31: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_34:
	/* 0x34: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36:
	/* 0x36: mov    DWORD PTR [rsp+0x84],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_3d:
	/* 0x3d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ruby_procs)));
x86_l_44:
	/* 0x44: lea    rsi,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_4c:
	/* 0x4c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_51:
	/* 0x51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53:
	/* 0x53: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_56:
	/* 0x56: je     102 <kprobe_unwind_ruby+0x102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_102;
	}
x86_l_5c:
	/* 0x5c: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_5f:
	/* 0x5f: mov    DWORD PTR [rsp+0x8],0x35 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738421ULL);
x86_l_67:
	/* 0x67: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_6e:
	/* 0x6e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_73:
	/* 0x73: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_78:
	/* 0x78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a:
	/* 0x7a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7d:
	/* 0x7d: je     13f <kprobe_unwind_ruby+0x13f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13f;
	}
x86_l_83:
	/* 0x83: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_86:
	/* 0x86: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_8f:
	/* 0x8f: cmp    QWORD PTR [r15+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_94:
	/* 0x94: jne    163 <kprobe_unwind_ruby+0x163> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_163;
	}
x86_l_9a:
	/* 0x9a: cmp    DWORD PTR [r15],0x30000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 196608ULL);
x86_l_a1:
	/* 0xa1: jb     32c <kprobe_unwind_ruby+0x32c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_32c;
	}
x86_l_a7:
	/* 0xa7: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_b0:
	/* 0xb0: mov    rax,QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b4:
	/* 0xb4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b9:
	/* 0xb9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_be:
	/* 0xbe: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_c4:
	/* 0xc4: mov    rdx,QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c8:
	/* 0xc8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cd:
	/* 0xcd: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_d0:
	/* 0xd0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d3:
	/* 0xd3: jne    291 <kprobe_unwind_ruby+0x291> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_291;
	}
x86_l_d9:
	/* 0xd9: movzx  eax,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_de:
	/* 0xde: add    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_e3:
	/* 0xe3: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e8:
	/* 0xe8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ed:
	/* 0xed: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_f3:
	/* 0xf3: movzx  edx,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_f8:
	/* 0xf8: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_fd:
	/* 0xfd: jmp    344 <kprobe_unwind_ruby+0x344> */
	goto x86_l_344;
x86_l_102:
	/* 0x102: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_109:
	/* 0x109: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10d:
	/* 0x10d: jne    fa2 <kprobe_unwind_ruby+0xfa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4002ULL;
	}
x86_l_113:
	/* 0x113: mov    DWORD PTR [rsp+0x8],0x49 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738441ULL);
x86_l_11b:
	/* 0x11b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_122:
	/* 0x122: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_127:
	/* 0x127: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12c:
	/* 0x12c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12e:
	/* 0x12e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_131:
	/* 0x131: je     296 <kprobe_unwind_ruby+0x296> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_296;
	}
x86_l_137:
	/* 0x137: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_13a:
	/* 0x13a: jmp    2a0 <kprobe_unwind_ruby+0x2a0> */
	goto x86_l_2a0;
x86_l_13f:
	/* 0x13f: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_146:
	/* 0x146: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_149:
	/* 0x149: jne    125e <kprobe_unwind_ruby+0x125e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4702ULL;
	}
x86_l_14f:
	/* 0x14f: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_158:
	/* 0x158: cmp    QWORD PTR [r15+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_15d:
	/* 0x15d: je     9a <kprobe_unwind_ruby+0x9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9a;
	}
x86_l_163:
	/* 0x163: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_168:
	/* 0x168: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a:
	/* 0x16a: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&tpbase_offset)));
x86_l_171:
	/* 0x171: add    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_174:
	/* 0x174: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_179:
	/* 0x179: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17e:
	/* 0x17e: mov    r8d,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 113ULL);
x86_l_184:
	/* 0x184: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_189:
	/* 0x189: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_18c:
	/* 0x18c: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_18f:
	/* 0x18f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_192:
	/* 0x192: je     257 <kprobe_unwind_ruby+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_257;
	}
x86_l_198:
	/* 0x198: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_19f:
	/* 0x19f: cmp    DWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a2:
	/* 0x1a2: jne    1095 <kprobe_unwind_ruby+0x1095> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4245ULL;
	}
x86_l_1a8:
	/* 0x1a8: mov    DWORD PTR [rsp+0x20],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953476ULL);
x86_l_1b0:
	/* 0x1b0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_1b7:
	/* 0x1b7: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bc:
	/* 0x1bc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c1:
	/* 0x1c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c3:
	/* 0x1c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c6:
	/* 0x1c6: je     36c <kprobe_unwind_ruby+0x36c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36c;
	}
x86_l_1cc:
	/* 0x1cc: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1cf:
	/* 0x1cf: cmp    DWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d2:
	/* 0x1d2: je     375 <kprobe_unwind_ruby+0x375> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_375;
	}
x86_l_1d8:
	/* 0x1d8: movabs rax,0x6b6f6f6c206c6f62 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7741528794664300386ULL);
x86_l_1e2:
	/* 0x1e2: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1e7:
	/* 0x1e7: movabs rax,0x6d797320534c5420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7888462804989793312ULL);
x86_l_1f1:
	/* 0x1f1: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f6:
	/* 0x1f6: movabs rax,0x726f662065736162 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732065714530ULL);
x86_l_200:
	/* 0x200: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_205:
	/* 0x205: movabs rax,0x2044535420746567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2325074928416875879ULL);
x86_l_20f:
	/* 0x20f: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_214:
	/* 0x214: movabs rax,0x206f742064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414100720745ULL);
x86_l_21e:
	/* 0x21e: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_223:
	/* 0x223: movabs rax,0x6166203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332504820184434ULL);
x86_l_22d:
	/* 0x22d: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_232:
	/* 0x232: mov    DWORD PTR [rsp+0x60],0xa7075 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412317544565ULL);
x86_l_23a:
	/* 0x23a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23f:
	/* 0x23f: mov    eax,0x34 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 52ULL);
x86_l_244:
	/* 0x244: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_249:
	/* 0x249: mov    esi,0x34 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 52ULL);
x86_l_24e:
	/* 0x24e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_250:
	/* 0x250: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_252:
	/* 0x252: jmp    375 <kprobe_unwind_ruby+0x375> */
	goto x86_l_375;
x86_l_257:
	/* 0x257: mov    rdx,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25b:
	/* 0x25b: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_262:
	/* 0x262: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_267:
	/* 0x267: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26c:
	/* 0x26c: jne    1414 <kprobe_unwind_ruby+0x1414> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5140ULL;
	}
x86_l_272:
	/* 0x272: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_277:
	/* 0x277: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_27c:
	/* 0x27c: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_281:
	/* 0x281: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_286:
	/* 0x286: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_288:
	/* 0x288: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28b:
	/* 0x28b: je     3c7 <kprobe_unwind_ruby+0x3c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c7;
	}
x86_l_291:
	/* 0x291: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_294:
	/* 0x294: jmp    2a6 <kprobe_unwind_ruby+0x2a6> */
	goto x86_l_2a6;
x86_l_296:
	/* 0x296: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29a:
	/* 0x29a: jne    149b <kprobe_unwind_ruby+0x149b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5275ULL;
	}
x86_l_2a0:
	/* 0x2a0: mov    r13d,0xbb8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3000ULL);
x86_l_2a6:
	/* 0x2a6: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2ab:
	/* 0x2ab: mov    DWORD PTR [r14+0xf2c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3884ULL);
x86_l_2b2:
	/* 0x2b2: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2ba:
	/* 0x2ba: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&per_cpu_records)));
x86_l_2c1:
	/* 0x2c1: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c6:
	/* 0x2c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cb:
	/* 0x2cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cd:
	/* 0x2cd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d0:
	/* 0x2d0: je     314 <kprobe_unwind_ruby+0x314> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_314;
	}
x86_l_2d2:
	/* 0x2d2: movzx  ecx,BYTE PTR [rax+0x1384] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4996ULL);
x86_l_2d9:
	/* 0x2d9: cmp    cl,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_2dc:
	/* 0x2dc: jb     396 <kprobe_unwind_ruby+0x396> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_396;
	}
x86_l_2e2:
	/* 0x2e2: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_2e5:
	/* 0x2e5: mov    DWORD PTR [rax+0xf2c],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16681652977669ULL);
x86_l_2ef:
	/* 0x2ef: mov    DWORD PTR [rsp+0x8],0x44 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738436ULL);
x86_l_2f7:
	/* 0x2f7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_2fe:
	/* 0x2fe: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_303:
	/* 0x303: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_308:
	/* 0x308: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30a:
	/* 0x30a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30d:
	/* 0x30d: je     379 <kprobe_unwind_ruby+0x379> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_379;
	}
x86_l_30f:
	/* 0x30f: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_312:
	/* 0x312: jmp    389 <kprobe_unwind_ruby+0x389> */
	goto x86_l_389;
x86_l_314:
	/* 0x314: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&perf_progs)));
x86_l_31b:
	/* 0x31b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31d:
	/* 0x31d: mov    ecx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_322:
	/* 0x322: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_325:
	/* 0x325: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_327:
	/* 0x327: jmp    3b1 <kprobe_unwind_ruby+0x3b1> */
	goto x86_l_3b1;
x86_l_32c:
	/* 0x32c: mov    rax,QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_330:
	/* 0x330: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_335:
	/* 0x335: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_33a:
	/* 0x33a: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_340:
	/* 0x340: mov    rdx,QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_344:
	/* 0x344: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_349:
	/* 0x349: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_34c:
	/* 0x34c: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34f:
	/* 0x34f: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_354:
	/* 0x354: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_357:
	/* 0x357: jne    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ab;
	}
x86_l_35d:
	/* 0x35d: mov    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_362:
	/* 0x362: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_365:
	/* 0x365: jne    3e0 <kprobe_unwind_ruby+0x3e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3e0;
	}
x86_l_367:
	/* 0x367: jmp    2ab <kprobe_unwind_ruby+0x2ab> */
	goto x86_l_2ab;
x86_l_36c:
	/* 0x36c: cmp    DWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36f:
	/* 0x36f: jne    1566 <kprobe_unwind_ruby+0x1566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5478ULL;
	}
x86_l_375:
	/* 0x375: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_377:
	/* 0x377: jmp    3b8 <kprobe_unwind_ruby+0x3b8> */
	goto x86_l_3b8;
x86_l_379:
	/* 0x379: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_380:
	/* 0x380: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_383:
	/* 0x383: jne    15ea <kprobe_unwind_ruby+0x15ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5610ULL;
	}
x86_l_389:
	/* 0x389: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_38c:
	/* 0x38c: movzx  ecx,BYTE PTR [r14+0x1384] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4996ULL);
x86_l_394:
	/* 0x394: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_396:
	/* 0x396: inc    cl */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_INC, 1);
x86_l_398:
	/* 0x398: mov    BYTE PTR [rax+0x1384],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4996ULL);
x86_l_39e:
	/* 0x39e: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_3a0:
	/* 0x3a0: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&perf_progs)));
x86_l_3a7:
	/* 0x3a7: mov    ecx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_3ac:
	/* 0x3ac: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3af:
	/* 0x3af: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_3b1:
	/* 0x3b1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3b3:
	/* 0x3b3: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_3b8:
	/* 0x3b8: add    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_3bf:
	/* 0x3bf: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3c1:
	/* 0x3c1: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3c2:
	/* 0x3c2: jmp    6e7d <kprobe_unwind_ruby+0x6e7d> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_3c7:
	/* 0x3c7: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cc:
	/* 0x3cc: jne    1665 <kprobe_unwind_ruby+0x1665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5733ULL;
	}
x86_l_3d2:
	/* 0x3d2: mov    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3d7:
	/* 0x3d7: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_3da:
	/* 0x3da: je     291 <kprobe_unwind_ruby+0x291> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_291;
	}
x86_l_3e0:
	/* 0x3e0: mov    rax,QWORD PTR [r14+0xf68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3944ULL);
x86_l_3e7:
	/* 0x3e7: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ec:
	/* 0x3ec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ef:
	/* 0x3ef: je     4f7 <kprobe_unwind_ruby+0x4f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f7;
	}
x86_l_3f5:
	/* 0x3f5: mov    r13,QWORD PTR [r14+0xf70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3952ULL);
x86_l_3fc:
	/* 0x3fc: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_3ff:
	/* 0x3ff: je     4f7 <kprobe_unwind_ruby+0x4f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f7;
	}
x86_l_405:
	/* 0x405: mov    r12,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_64);
x86_l_408:
	/* 0x408: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_411:
	/* 0x411: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_41a:
	/* 0x41a: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_41f:
	/* 0x41f: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_422:
	/* 0x422: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_427:
	/* 0x427: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_42c:
	/* 0x42c: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_432:
	/* 0x432: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_437:
	/* 0x437: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_43c:
	/* 0x43c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_441:
	/* 0x441: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_444:
	/* 0x444: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_449:
	/* 0x449: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_44e:
	/* 0x44e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_453:
	/* 0x453: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_458:
	/* 0x458: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_45e:
	/* 0x45e: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_463:
	/* 0x463: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_468:
	/* 0x468: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46d:
	/* 0x46d: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_470:
	/* 0x470: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_476:
	/* 0x476: je     565 <kprobe_unwind_ruby+0x565> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_565;
	}
x86_l_47c:
	/* 0x47c: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_481:
	/* 0x481: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_484:
	/* 0x484: je     565 <kprobe_unwind_ruby+0x565> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_565;
	}
x86_l_48a:
	/* 0x48a: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_48f:
	/* 0x48f: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_492:
	/* 0x492: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_497:
	/* 0x497: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_49c:
	/* 0x49c: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4a2:
	/* 0x4a2: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_4a7:
	/* 0x4a7: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_4ac:
	/* 0x4ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b1:
	/* 0x4b1: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4b4:
	/* 0x4b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b7:
	/* 0x4b7: je     7dd <kprobe_unwind_ruby+0x7dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2013ULL;
	}
x86_l_4bd:
	/* 0x4bd: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4c4:
	/* 0x4c4: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c8:
	/* 0x4c8: jne    1a5b <kprobe_unwind_ruby+0x1a5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6747ULL;
	}
x86_l_4ce:
	/* 0x4ce: mov    DWORD PTR [rsp],0x4e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_4d5:
	/* 0x4d5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_4dc:
	/* 0x4dc: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4df:
	/* 0x4df: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e4:
	/* 0x4e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e6:
	/* 0x4e6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e9:
	/* 0x4e9: je     84c <kprobe_unwind_ruby+0x84c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2124ULL;
	}
x86_l_4ef:
	/* 0x4ef: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4f2:
	/* 0x4f2: jmp    856 <kprobe_unwind_ruby+0x856> */
	return 2134ULL;
x86_l_4f7:
	/* 0x4f7: movzx  eax,BYTE PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_4fc:
	/* 0x4fc: add    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4ff:
	/* 0x4ff: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_504:
	/* 0x504: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_509:
	/* 0x509: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_50f:
	/* 0x50f: movzx  edx,BYTE PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_514:
	/* 0x514: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_517:
	/* 0x517: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51c:
	/* 0x51c: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_51f:
	/* 0x51f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_522:
	/* 0x522: je     6e0 <kprobe_unwind_ruby+0x6e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6e0;
	}
x86_l_528:
	/* 0x528: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_52f:
	/* 0x52f: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_533:
	/* 0x533: jne    18c4 <kprobe_unwind_ruby+0x18c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6340ULL;
	}
x86_l_539:
	/* 0x539: mov    DWORD PTR [rsp+0x18],0x4a */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215178ULL);
x86_l_541:
	/* 0x541: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_548:
	/* 0x548: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_54d:
	/* 0x54d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_552:
	/* 0x552: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_554:
	/* 0x554: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_557:
	/* 0x557: je     7c6 <kprobe_unwind_ruby+0x7c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1990ULL;
	}
x86_l_55d:
	/* 0x55d: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_560:
	/* 0x560: jmp    7d0 <kprobe_unwind_ruby+0x7d0> */
	return 2000ULL;
x86_l_565:
	/* 0x565: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_56c:
	/* 0x56c: jae    74e <kprobe_unwind_ruby+0x74e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 1870ULL;
	}
x86_l_572:
	/* 0x572: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_577:
	/* 0x577: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_57a:
	/* 0x57a: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_57f:
	/* 0x57f: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_582:
	/* 0x582: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_585:
	/* 0x585: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2ab;
	}
x86_l_58b:
	/* 0x58b: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_590:
	/* 0x590: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_593:
	/* 0x593: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_598:
	/* 0x598: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5a1:
	/* 0x5a1: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5aa:
	/* 0x5aa: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_5af:
	/* 0x5af: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5b2:
	/* 0x5b2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b7:
	/* 0x5b7: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_5bc:
	/* 0x5bc: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5c2:
	/* 0x5c2: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_5c7:
	/* 0x5c7: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5cc:
	/* 0x5cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d1:
	/* 0x5d1: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5d4:
	/* 0x5d4: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_5d9:
	/* 0x5d9: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5de:
	/* 0x5de: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e3:
	/* 0x5e3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5e8:
	/* 0x5e8: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5ee:
	/* 0x5ee: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_5f3:
	/* 0x5f3: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5f8:
	/* 0x5f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5fd:
	/* 0x5fd: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_600:
	/* 0x600: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_606:
	/* 0x606: je     946 <kprobe_unwind_ruby+0x946> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2374ULL;
	}
x86_l_60c:
	/* 0x60c: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_611:
	/* 0x611: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_614:
	/* 0x614: je     946 <kprobe_unwind_ruby+0x946> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2374ULL;
	}
x86_l_61a:
	/* 0x61a: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_61f:
	/* 0x61f: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_622:
	/* 0x622: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_627:
	/* 0x627: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_62c:
	/* 0x62c: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_632:
	/* 0x632: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_637:
	/* 0x637: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_63c:
	/* 0x63c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_641:
	/* 0x641: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_644:
	/* 0x644: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_647:
	/* 0x647: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4bd;
	}
x86_l_64d:
	/* 0x64d: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_652:
	/* 0x652: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_657:
	/* 0x657: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_65c:
	/* 0x65c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_661:
	/* 0x661: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_667:
	/* 0x667: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_66c:
	/* 0x66c: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_671:
	/* 0x671: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_676:
	/* 0x676: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_679:
	/* 0x679: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_67c:
	/* 0x67c: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_682:
	/* 0x682: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_687:
	/* 0x687: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_68c:
	/* 0x68c: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_691:
	/* 0x691: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_696:
	/* 0x696: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_69c:
	/* 0x69c: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_6a1:
	/* 0x6a1: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_6a6:
	/* 0x6a6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6ab:
	/* 0x6ab: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6ae:
	/* 0x6ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6b1:
	/* 0x6b1: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_6b7:
	/* 0x6b7: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6bc:
	/* 0x6bc: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_6bf:
	/* 0x6bf: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_6c4:
	/* 0x6c4: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_6c9:
	/* 0x6c9: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6cc:
	/* 0x6cc: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_6d0:
	/* 0x6d0: je     12ed <kprobe_unwind_ruby+0x12ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4845ULL;
	}
x86_l_6d6:
	/* 0x6d6: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6d8:
	/* 0x6d8: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_6db:
	/* 0x6db: jmp    12f1 <kprobe_unwind_ruby+0x12f1> */
	return 4849ULL;
x86_l_6e0:
	/* 0x6e0: movzx  eax,BYTE PTR [r15+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_6e5:
	/* 0x6e5: add    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6e8:
	/* 0x6e8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6ed:
	/* 0x6ed: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6f2:
	/* 0x6f2: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6f8:
	/* 0x6f8: movzx  edx,BYTE PTR [r15+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_6fd:
	/* 0x6fd: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_700:
	/* 0x700: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_705:
	/* 0x705: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_708:
	/* 0x708: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_70b:
	/* 0x70b: je     863 <kprobe_unwind_ruby+0x863> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2147ULL;
	}
x86_l_711:
	/* 0x711: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_718:
	/* 0x718: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_71c:
	/* 0x71c: jne    1b04 <kprobe_unwind_ruby+0x1b04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6916ULL;
	}
x86_l_722:
	/* 0x722: mov    DWORD PTR [rsp+0x18],0x4b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215179ULL);
x86_l_72a:
	/* 0x72a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_731:
	/* 0x731: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_736:
	/* 0x736: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_73b:
	/* 0x73b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_73d:
	/* 0x73d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_740:
	/* 0x740: je     92f <kprobe_unwind_ruby+0x92f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2351ULL;
	}
x86_l_746:
	/* 0x746: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
	return 1865ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1865ULL: goto x86_l_749;
	case 1870ULL: goto x86_l_74e;
	case 1878ULL: goto x86_l_756;
	case 1883ULL: goto x86_l_75b;
	case 1888ULL: goto x86_l_760;
	case 1891ULL: goto x86_l_763;
	case 1896ULL: goto x86_l_768;
	case 1902ULL: goto x86_l_76e;
	case 1907ULL: goto x86_l_773;
	case 1912ULL: goto x86_l_778;
	case 1917ULL: goto x86_l_77d;
	case 1920ULL: goto x86_l_780;
	case 1923ULL: goto x86_l_783;
	case 1929ULL: goto x86_l_789;
	case 1936ULL: goto x86_l_790;
	case 1940ULL: goto x86_l_794;
	case 1946ULL: goto x86_l_79a;
	case 1954ULL: goto x86_l_7a2;
	case 1961ULL: goto x86_l_7a9;
	case 1966ULL: goto x86_l_7ae;
	case 1971ULL: goto x86_l_7b3;
	case 1973ULL: goto x86_l_7b5;
	case 1976ULL: goto x86_l_7b8;
	case 1982ULL: goto x86_l_7be;
	case 1985ULL: goto x86_l_7c1;
	case 1990ULL: goto x86_l_7c6;
	case 1994ULL: goto x86_l_7ca;
	case 2000ULL: goto x86_l_7d0;
	case 2006ULL: goto x86_l_7d6;
	case 2008ULL: goto x86_l_7d8;
	case 2013ULL: goto x86_l_7dd;
	case 2018ULL: goto x86_l_7e2;
	case 2023ULL: goto x86_l_7e7;
	case 2028ULL: goto x86_l_7ec;
	case 2033ULL: goto x86_l_7f1;
	case 2039ULL: goto x86_l_7f7;
	case 2044ULL: goto x86_l_7fc;
	case 2049ULL: goto x86_l_801;
	case 2054ULL: goto x86_l_806;
	case 2057ULL: goto x86_l_809;
	case 2060ULL: goto x86_l_80c;
	case 2066ULL: goto x86_l_812;
	case 2073ULL: goto x86_l_819;
	case 2077ULL: goto x86_l_81d;
	case 2083ULL: goto x86_l_823;
	case 2090ULL: goto x86_l_82a;
	case 2097ULL: goto x86_l_831;
	case 2100ULL: goto x86_l_834;
	case 2105ULL: goto x86_l_839;
	case 2107ULL: goto x86_l_83b;
	case 2110ULL: goto x86_l_83e;
	case 2116ULL: goto x86_l_844;
	case 2119ULL: goto x86_l_847;
	case 2124ULL: goto x86_l_84c;
	case 2128ULL: goto x86_l_850;
	case 2134ULL: goto x86_l_856;
	case 2140ULL: goto x86_l_85c;
	case 2142ULL: goto x86_l_85e;
	case 2147ULL: goto x86_l_863;
	case 2152ULL: goto x86_l_868;
	case 2157ULL: goto x86_l_86d;
	case 2165ULL: goto x86_l_875;
	case 2170ULL: goto x86_l_87a;
	case 2175ULL: goto x86_l_87f;
	case 2183ULL: goto x86_l_887;
	case 2188ULL: goto x86_l_88c;
	case 2191ULL: goto x86_l_88f;
	case 2196ULL: goto x86_l_894;
	case 2201ULL: goto x86_l_899;
	case 2207ULL: goto x86_l_89f;
	case 2212ULL: goto x86_l_8a4;
	case 2215ULL: goto x86_l_8a7;
	case 2220ULL: goto x86_l_8ac;
	case 2223ULL: goto x86_l_8af;
	case 2226ULL: goto x86_l_8b2;
	case 2232ULL: goto x86_l_8b8;
	case 2239ULL: goto x86_l_8bf;
	case 2243ULL: goto x86_l_8c3;
	case 2249ULL: goto x86_l_8c9;
	case 2257ULL: goto x86_l_8d1;
	case 2264ULL: goto x86_l_8d8;
	case 2269ULL: goto x86_l_8dd;
	case 2274ULL: goto x86_l_8e2;
	case 2276ULL: goto x86_l_8e4;
	case 2279ULL: goto x86_l_8e7;
	case 2285ULL: goto x86_l_8ed;
	case 2288ULL: goto x86_l_8f0;
	case 2293ULL: goto x86_l_8f5;
	case 2296ULL: goto x86_l_8f8;
	case 2298ULL: goto x86_l_8fa;
	case 2303ULL: goto x86_l_8ff;
	case 2309ULL: goto x86_l_905;
	case 2314ULL: goto x86_l_90a;
	case 2319ULL: goto x86_l_90f;
	case 2324ULL: goto x86_l_914;
	case 2329ULL: goto x86_l_919;
	case 2336ULL: goto x86_l_920;
	case 2343ULL: goto x86_l_927;
	case 2346ULL: goto x86_l_92a;
	case 2351ULL: goto x86_l_92f;
	case 2355ULL: goto x86_l_933;
	case 2361ULL: goto x86_l_939;
	case 2367ULL: goto x86_l_93f;
	case 2369ULL: goto x86_l_941;
	case 2374ULL: goto x86_l_946;
	case 2381ULL: goto x86_l_94d;
	case 2387ULL: goto x86_l_953;
	case 2392ULL: goto x86_l_958;
	case 2395ULL: goto x86_l_95b;
	case 2398ULL: goto x86_l_95e;
	case 2404ULL: goto x86_l_964;
	case 2409ULL: goto x86_l_969;
	case 2412ULL: goto x86_l_96c;
	case 2417ULL: goto x86_l_971;
	case 2426ULL: goto x86_l_97a;
	case 2435ULL: goto x86_l_983;
	case 2440ULL: goto x86_l_988;
	case 2443ULL: goto x86_l_98b;
	case 2448ULL: goto x86_l_990;
	case 2453ULL: goto x86_l_995;
	case 2459ULL: goto x86_l_99b;
	case 2464ULL: goto x86_l_9a0;
	case 2469ULL: goto x86_l_9a5;
	case 2474ULL: goto x86_l_9aa;
	case 2477ULL: goto x86_l_9ad;
	case 2482ULL: goto x86_l_9b2;
	case 2487ULL: goto x86_l_9b7;
	case 2492ULL: goto x86_l_9bc;
	case 2497ULL: goto x86_l_9c1;
	case 2503ULL: goto x86_l_9c7;
	case 2508ULL: goto x86_l_9cc;
	case 2513ULL: goto x86_l_9d1;
	case 2518ULL: goto x86_l_9d6;
	case 2521ULL: goto x86_l_9d9;
	case 2527ULL: goto x86_l_9df;
	case 2533ULL: goto x86_l_9e5;
	case 2538ULL: goto x86_l_9ea;
	case 2541ULL: goto x86_l_9ed;
	case 2547ULL: goto x86_l_9f3;
	case 2552ULL: goto x86_l_9f8;
	case 2555ULL: goto x86_l_9fb;
	case 2560ULL: goto x86_l_a00;
	case 2565ULL: goto x86_l_a05;
	case 2571ULL: goto x86_l_a0b;
	case 2576ULL: goto x86_l_a10;
	case 2581ULL: goto x86_l_a15;
	case 2586ULL: goto x86_l_a1a;
	case 2589ULL: goto x86_l_a1d;
	case 2592ULL: goto x86_l_a20;
	case 2598ULL: goto x86_l_a26;
	case 2603ULL: goto x86_l_a2b;
	case 2608ULL: goto x86_l_a30;
	case 2613ULL: goto x86_l_a35;
	case 2618ULL: goto x86_l_a3a;
	case 2624ULL: goto x86_l_a40;
	case 2629ULL: goto x86_l_a45;
	case 2634ULL: goto x86_l_a4a;
	case 2639ULL: goto x86_l_a4f;
	case 2642ULL: goto x86_l_a52;
	case 2645ULL: goto x86_l_a55;
	case 2651ULL: goto x86_l_a5b;
	case 2656ULL: goto x86_l_a60;
	case 2661ULL: goto x86_l_a65;
	case 2666ULL: goto x86_l_a6a;
	case 2671ULL: goto x86_l_a6f;
	case 2677ULL: goto x86_l_a75;
	case 2682ULL: goto x86_l_a7a;
	case 2687ULL: goto x86_l_a7f;
	case 2692ULL: goto x86_l_a84;
	case 2695ULL: goto x86_l_a87;
	case 2698ULL: goto x86_l_a8a;
	case 2700ULL: goto x86_l_a8c;
	case 2705ULL: goto x86_l_a91;
	case 2708ULL: goto x86_l_a94;
	case 2713ULL: goto x86_l_a99;
	case 2718ULL: goto x86_l_a9e;
	case 2721ULL: goto x86_l_aa1;
	case 2725ULL: goto x86_l_aa5;
	case 2731ULL: goto x86_l_aab;
	case 2733ULL: goto x86_l_aad;
	case 2736ULL: goto x86_l_ab0;
	case 2741ULL: goto x86_l_ab5;
	case 2746ULL: goto x86_l_aba;
	case 2751ULL: goto x86_l_abf;
	case 2756ULL: goto x86_l_ac4;
	case 2761ULL: goto x86_l_ac9;
	case 2767ULL: goto x86_l_acf;
	case 2772ULL: goto x86_l_ad4;
	case 2777ULL: goto x86_l_ad9;
	case 2782ULL: goto x86_l_ade;
	case 2785ULL: goto x86_l_ae1;
	case 2788ULL: goto x86_l_ae4;
	case 2794ULL: goto x86_l_aea;
	case 2801ULL: goto x86_l_af1;
	case 2805ULL: goto x86_l_af5;
	case 2811ULL: goto x86_l_afb;
	case 2818ULL: goto x86_l_b02;
	case 2825ULL: goto x86_l_b09;
	case 2828ULL: goto x86_l_b0c;
	case 2833ULL: goto x86_l_b11;
	case 2835ULL: goto x86_l_b13;
	case 2838ULL: goto x86_l_b16;
	case 2844ULL: goto x86_l_b1c;
	case 2847ULL: goto x86_l_b1f;
	case 2852ULL: goto x86_l_b24;
	case 2856ULL: goto x86_l_b28;
	case 2862ULL: goto x86_l_b2e;
	case 2868ULL: goto x86_l_b34;
	case 2870ULL: goto x86_l_b36;
	case 2875ULL: goto x86_l_b3b;
	case 2879ULL: goto x86_l_b3f;
	case 2885ULL: goto x86_l_b45;
	case 2891ULL: goto x86_l_b4b;
	case 2893ULL: goto x86_l_b4d;
	case 2898ULL: goto x86_l_b52;
	case 2907ULL: goto x86_l_b5b;
	case 2910ULL: goto x86_l_b5e;
	case 2918ULL: goto x86_l_b66;
	case 2920ULL: goto x86_l_b68;
	case 2923ULL: goto x86_l_b6b;
	case 2928ULL: goto x86_l_b70;
	case 2933ULL: goto x86_l_b75;
	case 2941ULL: goto x86_l_b7d;
	case 2946ULL: goto x86_l_b82;
	case 2951ULL: goto x86_l_b87;
	case 2954ULL: goto x86_l_b8a;
	case 2959ULL: goto x86_l_b8f;
	case 2965ULL: goto x86_l_b95;
	case 2970ULL: goto x86_l_b9a;
	case 2975ULL: goto x86_l_b9f;
	case 2980ULL: goto x86_l_ba4;
	case 2983ULL: goto x86_l_ba7;
	case 2986ULL: goto x86_l_baa;
	case 2992ULL: goto x86_l_bb0;
	case 2995ULL: goto x86_l_bb3;
	case 2997ULL: goto x86_l_bb5;
	case 3002ULL: goto x86_l_bba;
	case 3008ULL: goto x86_l_bc0;
	case 3013ULL: goto x86_l_bc5;
	case 3017ULL: goto x86_l_bc9;
	case 3023ULL: goto x86_l_bcf;
	case 3029ULL: goto x86_l_bd5;
	case 3031ULL: goto x86_l_bd7;
	case 3036ULL: goto x86_l_bdc;
	case 3041ULL: goto x86_l_be1;
	case 3044ULL: goto x86_l_be4;
	case 3049ULL: goto x86_l_be9;
	case 3054ULL: goto x86_l_bee;
	case 3057ULL: goto x86_l_bf1;
	case 3061ULL: goto x86_l_bf5;
	case 3067ULL: goto x86_l_bfb;
	case 3069ULL: goto x86_l_bfd;
	case 3072ULL: goto x86_l_c00;
	case 3077ULL: goto x86_l_c05;
	case 3081ULL: goto x86_l_c09;
	case 3087ULL: goto x86_l_c0f;
	case 3093ULL: goto x86_l_c15;
	case 3095ULL: goto x86_l_c17;
	case 3100ULL: goto x86_l_c1c;
	case 3107ULL: goto x86_l_c23;
	case 3113ULL: goto x86_l_c29;
	case 3118ULL: goto x86_l_c2e;
	case 3121ULL: goto x86_l_c31;
	case 3124ULL: goto x86_l_c34;
	case 3130ULL: goto x86_l_c3a;
	case 3135ULL: goto x86_l_c3f;
	case 3138ULL: goto x86_l_c42;
	case 3143ULL: goto x86_l_c47;
	case 3152ULL: goto x86_l_c50;
	case 3161ULL: goto x86_l_c59;
	case 3166ULL: goto x86_l_c5e;
	case 3169ULL: goto x86_l_c61;
	case 3174ULL: goto x86_l_c66;
	case 3179ULL: goto x86_l_c6b;
	case 3185ULL: goto x86_l_c71;
	case 3190ULL: goto x86_l_c76;
	case 3195ULL: goto x86_l_c7b;
	case 3200ULL: goto x86_l_c80;
	case 3203ULL: goto x86_l_c83;
	case 3208ULL: goto x86_l_c88;
	case 3213ULL: goto x86_l_c8d;
	case 3218ULL: goto x86_l_c92;
	case 3223ULL: goto x86_l_c97;
	case 3229ULL: goto x86_l_c9d;
	case 3234ULL: goto x86_l_ca2;
	case 3239ULL: goto x86_l_ca7;
	case 3244ULL: goto x86_l_cac;
	case 3247ULL: goto x86_l_caf;
	case 3253ULL: goto x86_l_cb5;
	case 3259ULL: goto x86_l_cbb;
	case 3264ULL: goto x86_l_cc0;
	case 3267ULL: goto x86_l_cc3;
	case 3273ULL: goto x86_l_cc9;
	case 3278ULL: goto x86_l_cce;
	case 3281ULL: goto x86_l_cd1;
	case 3286ULL: goto x86_l_cd6;
	case 3291ULL: goto x86_l_cdb;
	case 3297ULL: goto x86_l_ce1;
	case 3302ULL: goto x86_l_ce6;
	case 3307ULL: goto x86_l_ceb;
	case 3312ULL: goto x86_l_cf0;
	case 3315ULL: goto x86_l_cf3;
	case 3318ULL: goto x86_l_cf6;
	case 3324ULL: goto x86_l_cfc;
	case 3329ULL: goto x86_l_d01;
	case 3334ULL: goto x86_l_d06;
	case 3339ULL: goto x86_l_d0b;
	case 3344ULL: goto x86_l_d10;
	case 3350ULL: goto x86_l_d16;
	case 3355ULL: goto x86_l_d1b;
	case 3360ULL: goto x86_l_d20;
	case 3365ULL: goto x86_l_d25;
	case 3368ULL: goto x86_l_d28;
	case 3371ULL: goto x86_l_d2b;
	case 3377ULL: goto x86_l_d31;
	case 3382ULL: goto x86_l_d36;
	case 3387ULL: goto x86_l_d3b;
	case 3392ULL: goto x86_l_d40;
	case 3397ULL: goto x86_l_d45;
	case 3403ULL: goto x86_l_d4b;
	case 3408ULL: goto x86_l_d50;
	case 3413ULL: goto x86_l_d55;
	case 3418ULL: goto x86_l_d5a;
	case 3421ULL: goto x86_l_d5d;
	case 3424ULL: goto x86_l_d60;
	case 3430ULL: goto x86_l_d66;
	case 3435ULL: goto x86_l_d6b;
	case 3438ULL: goto x86_l_d6e;
	case 3443ULL: goto x86_l_d73;
	case 3448ULL: goto x86_l_d78;
	case 3451ULL: goto x86_l_d7b;
	case 3455ULL: goto x86_l_d7f;
	case 3461ULL: goto x86_l_d85;
	case 3463ULL: goto x86_l_d87;
	case 3466ULL: goto x86_l_d8a;
	case 3471ULL: goto x86_l_d8f;
	case 3473ULL: goto x86_l_d91;
	case 3475ULL: goto x86_l_d93;
	case 3479ULL: goto x86_l_d97;
	case 3482ULL: goto x86_l_d9a;
	case 3488ULL: goto x86_l_da0;
	case 3495ULL: goto x86_l_da7;
	case 3498ULL: goto x86_l_daa;
	case 3504ULL: goto x86_l_db0;
	case 3514ULL: goto x86_l_dba;
	case 3519ULL: goto x86_l_dbf;
	case 3529ULL: goto x86_l_dc9;
	case 3534ULL: goto x86_l_dce;
	case 3544ULL: goto x86_l_dd8;
	case 3549ULL: goto x86_l_ddd;
	case 3559ULL: goto x86_l_de7;
	case 3564ULL: goto x86_l_dec;
	case 3574ULL: goto x86_l_df6;
	case 3579ULL: goto x86_l_dfb;
	case 3589ULL: goto x86_l_e05;
	case 3594ULL: goto x86_l_e0a;
	case 3599ULL: goto x86_l_e0f;
	case 3604ULL: goto x86_l_e14;
	case 3609ULL: goto x86_l_e19;
	case 3614ULL: goto x86_l_e1e;
	case 3616ULL: goto x86_l_e20;
	case 3618ULL: goto x86_l_e22;
	case 3623ULL: goto x86_l_e27;
	case 3630ULL: goto x86_l_e2e;
	case 3634ULL: goto x86_l_e32;
	case 3640ULL: goto x86_l_e38;
	case 3647ULL: goto x86_l_e3f;
	case 3651ULL: goto x86_l_e43;
	case 3657ULL: goto x86_l_e49;
	case 3665ULL: goto x86_l_e51;
	case 3672ULL: goto x86_l_e58;
	case 3677ULL: goto x86_l_e5d;
	case 3682ULL: goto x86_l_e62;
	case 3684ULL: goto x86_l_e64;
	case 3687ULL: goto x86_l_e67;
	case 3693ULL: goto x86_l_e6d;
	case 3696ULL: goto x86_l_e70;
	case 3700ULL: goto x86_l_e74;
	case 3706ULL: goto x86_l_e7a;
	case 3712ULL: goto x86_l_e80;
	case 3722ULL: goto x86_l_e8a;
	case 3727ULL: goto x86_l_e8f;
	case 3737ULL: goto x86_l_e99;
	case 3742ULL: goto x86_l_e9e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_749:
	/* 0x749: jmp    939 <kprobe_unwind_ruby+0x939> */
	goto x86_l_939;
x86_l_74e:
	/* 0x74e: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_756:
	/* 0x756: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_75b:
	/* 0x75b: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_760:
	/* 0x760: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_763:
	/* 0x763: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_768:
	/* 0x768: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_76e:
	/* 0x76e: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_773:
	/* 0x773: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_778:
	/* 0x778: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_77d:
	/* 0x77d: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_780:
	/* 0x780: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_783:
	/* 0x783: je     8f5 <kprobe_unwind_ruby+0x8f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8f5;
	}
x86_l_789:
	/* 0x789: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_790:
	/* 0x790: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_794:
	/* 0x794: jne    1bd8 <kprobe_unwind_ruby+0x1bd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7128ULL;
	}
x86_l_79a:
	/* 0x79a: mov    DWORD PTR [rsp+0x74],0x4d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206413ULL);
x86_l_7a2:
	/* 0x7a2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_7a9:
	/* 0x7a9: lea    rsi,[rsp+0x74] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_7ae:
	/* 0x7ae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7b3:
	/* 0x7b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b5:
	/* 0x7b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7b8:
	/* 0x7b8: je     b24 <kprobe_unwind_ruby+0xb24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b24;
	}
x86_l_7be:
	/* 0x7be: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_7c1:
	/* 0x7c1: jmp    b2e <kprobe_unwind_ruby+0xb2e> */
	goto x86_l_b2e;
x86_l_7c6:
	/* 0x7c6: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7ca:
	/* 0x7ca: jne    1b5d <kprobe_unwind_ruby+0x1b5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7005ULL;
	}
x86_l_7d0:
	/* 0x7d0: mov    r13d,0xbb9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3001ULL);
x86_l_7d6:
	/* 0x7d6: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7d8:
	/* 0x7d8: jmp    2ab <kprobe_unwind_ruby+0x2ab> */
	return 683ULL;
x86_l_7dd:
	/* 0x7dd: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_7e2:
	/* 0x7e2: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_7e7:
	/* 0x7e7: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_7ec:
	/* 0x7ec: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7f1:
	/* 0x7f1: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_7f7:
	/* 0x7f7: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_7fc:
	/* 0x7fc: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_801:
	/* 0x801: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_806:
	/* 0x806: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_809:
	/* 0x809: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_80c:
	/* 0x80c: je     ab5 <kprobe_unwind_ruby+0xab5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ab5;
	}
x86_l_812:
	/* 0x812: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_819:
	/* 0x819: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_81d:
	/* 0x81d: jne    1c22 <kprobe_unwind_ruby+0x1c22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7202ULL;
	}
x86_l_823:
	/* 0x823: mov    DWORD PTR [rsp],0x4f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_82a:
	/* 0x82a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_831:
	/* 0x831: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_834:
	/* 0x834: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_839:
	/* 0x839: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_83b:
	/* 0x83b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_83e:
	/* 0x83e: je     b3b <kprobe_unwind_ruby+0xb3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b3b;
	}
x86_l_844:
	/* 0x844: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_847:
	/* 0x847: jmp    b45 <kprobe_unwind_ruby+0xb45> */
	goto x86_l_b45;
x86_l_84c:
	/* 0x84c: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_850:
	/* 0x850: jne    1c82 <kprobe_unwind_ruby+0x1c82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7298ULL;
	}
x86_l_856:
	/* 0x856: mov    r13d,0xbbd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3005ULL);
x86_l_85c:
	/* 0x85c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_85e:
	/* 0x85e: jmp    2ab <kprobe_unwind_ruby+0x2ab> */
	return 683ULL;
x86_l_863:
	/* 0x863: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_868:
	/* 0x868: movzx  eax,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_86d:
	/* 0x86d: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_875:
	/* 0x875: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_87a:
	/* 0x87a: movzx  eax,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_87f:
	/* 0x87f: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_887:
	/* 0x887: movzx  eax,BYTE PTR [r15+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 26ULL);
x86_l_88c:
	/* 0x88c: add    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_88f:
	/* 0x88f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_894:
	/* 0x894: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_899:
	/* 0x899: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_89f:
	/* 0x89f: movzx  edx,BYTE PTR [r15+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 26ULL);
x86_l_8a4:
	/* 0x8a4: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_8a7:
	/* 0x8a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8ac:
	/* 0x8ac: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_8af:
	/* 0x8af: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8b2:
	/* 0x8b2: je     b52 <kprobe_unwind_ruby+0xb52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b52;
	}
x86_l_8b8:
	/* 0x8b8: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_8bf:
	/* 0x8bf: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8c3:
	/* 0x8c3: jne    1ef6 <kprobe_unwind_ruby+0x1ef6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7926ULL;
	}
x86_l_8c9:
	/* 0x8c9: mov    DWORD PTR [rsp+0x18],0x4c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215180ULL);
x86_l_8d1:
	/* 0x8d1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_8d8:
	/* 0x8d8: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8dd:
	/* 0x8dd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8e2:
	/* 0x8e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e4:
	/* 0x8e4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8e7:
	/* 0x8e7: je     bc5 <kprobe_unwind_ruby+0xbc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bc5;
	}
x86_l_8ed:
	/* 0x8ed: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_8f0:
	/* 0x8f0: jmp    bcf <kprobe_unwind_ruby+0xbcf> */
	goto x86_l_bcf;
x86_l_8f5:
	/* 0x8f5: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8f8:
	/* 0x8f8: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_8fa:
	/* 0x8fa: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_8ff:
	/* 0x8ff: je     572 <kprobe_unwind_ruby+0x572> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1394ULL;
	}
x86_l_905:
	/* 0x905: movzx  eax,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_90a:
	/* 0x90a: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_90f:
	/* 0x90f: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_914:
	/* 0x914: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_919:
	/* 0x919: mov    QWORD PTR [r14+0xf68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3944ULL);
x86_l_920:
	/* 0x920: mov    QWORD PTR [r14+0xf70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3952ULL);
x86_l_927:
	/* 0x927: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_92a:
	/* 0x92a: jmp    2ab <kprobe_unwind_ruby+0x2ab> */
	return 683ULL;
x86_l_92f:
	/* 0x92f: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_933:
	/* 0x933: jne    1f45 <kprobe_unwind_ruby+0x1f45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8005ULL;
	}
x86_l_939:
	/* 0x939: mov    r13d,0xbba */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3002ULL);
x86_l_93f:
	/* 0x93f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_941:
	/* 0x941: jmp    2ab <kprobe_unwind_ruby+0x2ab> */
	return 683ULL;
x86_l_946:
	/* 0x946: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_94d:
	/* 0x94d: jae    b75 <kprobe_unwind_ruby+0xb75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_b75;
	}
x86_l_953:
	/* 0x953: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_958:
	/* 0x958: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_95b:
	/* 0x95b: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_95e:
	/* 0x95e: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_964:
	/* 0x964: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_969:
	/* 0x969: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_96c:
	/* 0x96c: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_971:
	/* 0x971: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_97a:
	/* 0x97a: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_983:
	/* 0x983: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_988:
	/* 0x988: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_98b:
	/* 0x98b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_990:
	/* 0x990: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_995:
	/* 0x995: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_99b:
	/* 0x99b: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_9a0:
	/* 0x9a0: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_9a5:
	/* 0x9a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9aa:
	/* 0x9aa: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_9ad:
	/* 0x9ad: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_9b2:
	/* 0x9b2: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_9b7:
	/* 0x9b7: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9bc:
	/* 0x9bc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9c1:
	/* 0x9c1: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_9c7:
	/* 0x9c7: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_9cc:
	/* 0x9cc: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_9d1:
	/* 0x9d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9d6:
	/* 0x9d6: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_9d9:
	/* 0x9d9: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_9df:
	/* 0x9df: je     c1c <kprobe_unwind_ruby+0xc1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c1c;
	}
x86_l_9e5:
	/* 0x9e5: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9ea:
	/* 0x9ea: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9ed:
	/* 0x9ed: je     c1c <kprobe_unwind_ruby+0xc1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c1c;
	}
x86_l_9f3:
	/* 0x9f3: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_9f8:
	/* 0x9f8: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9fb:
	/* 0x9fb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a00:
	/* 0xa00: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a05:
	/* 0xa05: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_a0b:
	/* 0xa0b: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_a10:
	/* 0xa10: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_a15:
	/* 0xa15: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a1a:
	/* 0xa1a: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_a1d:
	/* 0xa1d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a20:
	/* 0xa20: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_a26:
	/* 0xa26: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_a2b:
	/* 0xa2b: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_a30:
	/* 0xa30: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a35:
	/* 0xa35: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a3a:
	/* 0xa3a: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_a40:
	/* 0xa40: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_a45:
	/* 0xa45: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_a4a:
	/* 0xa4a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a4f:
	/* 0xa4f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_a52:
	/* 0xa52: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a55:
	/* 0xa55: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_812;
	}
x86_l_a5b:
	/* 0xa5b: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_a60:
	/* 0xa60: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_a65:
	/* 0xa65: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_a6a:
	/* 0xa6a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a6f:
	/* 0xa6f: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_a75:
	/* 0xa75: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_a7a:
	/* 0xa7a: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_a7f:
	/* 0xa7f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a84:
	/* 0xa84: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_a87:
	/* 0xa87: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a8a:
	/* 0xa8a: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_aea;
	}
x86_l_a8c:
	/* 0xa8c: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a91:
	/* 0xa91: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_a94:
	/* 0xa94: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_a99:
	/* 0xa99: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_a9e:
	/* 0xa9e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_aa1:
	/* 0xaa1: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_aa5:
	/* 0xaa5: je     1934 <kprobe_unwind_ruby+0x1934> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6452ULL;
	}
x86_l_aab:
	/* 0xaab: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aad:
	/* 0xaad: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_ab0:
	/* 0xab0: jmp    1938 <kprobe_unwind_ruby+0x1938> */
	return 6456ULL;
x86_l_ab5:
	/* 0xab5: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_aba:
	/* 0xaba: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_abf:
	/* 0xabf: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_ac4:
	/* 0xac4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ac9:
	/* 0xac9: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_acf:
	/* 0xacf: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_ad4:
	/* 0xad4: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_ad9:
	/* 0xad9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ade:
	/* 0xade: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_ae1:
	/* 0xae1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ae4:
	/* 0xae4: je     bdc <kprobe_unwind_ruby+0xbdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bdc;
	}
x86_l_aea:
	/* 0xaea: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_af1:
	/* 0xaf1: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af5:
	/* 0xaf5: jne    2162 <kprobe_unwind_ruby+0x2162> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8546ULL;
	}
x86_l_afb:
	/* 0xafb: mov    DWORD PTR [rsp],0x50 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b02:
	/* 0xb02: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_b09:
	/* 0xb09: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_b0c:
	/* 0xb0c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b11:
	/* 0xb11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b13:
	/* 0xb13: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b16:
	/* 0xb16: je     c05 <kprobe_unwind_ruby+0xc05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c05;
	}
x86_l_b1c:
	/* 0xb1c: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_b1f:
	/* 0xb1f: jmp    c0f <kprobe_unwind_ruby+0xc0f> */
	goto x86_l_c0f;
x86_l_b24:
	/* 0xb24: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b28:
	/* 0xb28: jne    20e7 <kprobe_unwind_ruby+0x20e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8423ULL;
	}
x86_l_b2e:
	/* 0xb2e: mov    r13d,0xbbc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3004ULL);
x86_l_b34:
	/* 0xb34: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b36:
	/* 0xb36: jmp    2ab <kprobe_unwind_ruby+0x2ab> */
	return 683ULL;
x86_l_b3b:
	/* 0xb3b: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b3f:
	/* 0xb3f: jne    21bb <kprobe_unwind_ruby+0x21bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8635ULL;
	}
x86_l_b45:
	/* 0xb45: mov    r13d,0xbbe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3006ULL);
x86_l_b4b:
	/* 0xb4b: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b4d:
	/* 0xb4d: jmp    2ab <kprobe_unwind_ruby+0x2ab> */
	return 683ULL;
x86_l_b52:
	/* 0xb52: imul   rbp,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 136ULL);
x86_l_b5b:
	/* 0xb5b: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b5e:
	/* 0xb5e: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b66:
	/* 0xb66: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b68:
	/* 0xb68: sub    r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b6b:
	/* 0xb6b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b70:
	/* 0xb70: jmp    405 <kprobe_unwind_ruby+0x405> */
	return 1029ULL;
x86_l_b75:
	/* 0xb75: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b7d:
	/* 0xb7d: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_b82:
	/* 0xb82: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b87:
	/* 0xb87: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b8a:
	/* 0xb8a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b8f:
	/* 0xb8f: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_b95:
	/* 0xb95: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_b9a:
	/* 0xb9a: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b9f:
	/* 0xb9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ba4:
	/* 0xba4: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_ba7:
	/* 0xba7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_baa:
	/* 0xbaa: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_789;
	}
x86_l_bb0:
	/* 0xbb0: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bb3:
	/* 0xbb3: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_bb5:
	/* 0xbb5: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_bba:
	/* 0xbba: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_905;
	}
x86_l_bc0:
	/* 0xbc0: jmp    953 <kprobe_unwind_ruby+0x953> */
	goto x86_l_953;
x86_l_bc5:
	/* 0xbc5: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bc9:
	/* 0xbc9: jne    2285 <kprobe_unwind_ruby+0x2285> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8837ULL;
	}
x86_l_bcf:
	/* 0xbcf: mov    r13d,0xbbb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3003ULL);
x86_l_bd5:
	/* 0xbd5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bd7:
	/* 0xbd7: jmp    2ab <kprobe_unwind_ruby+0x2ab> */
	return 683ULL;
x86_l_bdc:
	/* 0xbdc: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_be1:
	/* 0xbe1: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_be4:
	/* 0xbe4: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_be9:
	/* 0xbe9: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_bee:
	/* 0xbee: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_bf1:
	/* 0xbf1: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_bf5:
	/* 0xbf5: je     d8f <kprobe_unwind_ruby+0xd8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d8f;
	}
x86_l_bfb:
	/* 0xbfb: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bfd:
	/* 0xbfd: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_c00:
	/* 0xc00: jmp    d93 <kprobe_unwind_ruby+0xd93> */
	goto x86_l_d93;
x86_l_c05:
	/* 0xc05: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c09:
	/* 0xc09: jne    238a <kprobe_unwind_ruby+0x238a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9098ULL;
	}
x86_l_c0f:
	/* 0xc0f: mov    r13d,0xbbf */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3007ULL);
x86_l_c15:
	/* 0xc15: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c17:
	/* 0xc17: jmp    2ab <kprobe_unwind_ruby+0x2ab> */
	return 683ULL;
x86_l_c1c:
	/* 0xc1c: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_c23:
	/* 0xc23: jae    f52 <kprobe_unwind_ruby+0xf52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3922ULL;
	}
x86_l_c29:
	/* 0xc29: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c2e:
	/* 0xc2e: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_c31:
	/* 0xc31: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_c34:
	/* 0xc34: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_c3a:
	/* 0xc3a: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_c3f:
	/* 0xc3f: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c42:
	/* 0xc42: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c47:
	/* 0xc47: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_c50:
	/* 0xc50: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_c59:
	/* 0xc59: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_c5e:
	/* 0xc5e: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c61:
	/* 0xc61: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c66:
	/* 0xc66: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_c6b:
	/* 0xc6b: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_c71:
	/* 0xc71: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_c76:
	/* 0xc76: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c7b:
	/* 0xc7b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c80:
	/* 0xc80: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_c83:
	/* 0xc83: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_c88:
	/* 0xc88: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c8d:
	/* 0xc8d: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c92:
	/* 0xc92: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c97:
	/* 0xc97: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_c9d:
	/* 0xc9d: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_ca2:
	/* 0xca2: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ca7:
	/* 0xca7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cac:
	/* 0xcac: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_caf:
	/* 0xcaf: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_cb5:
	/* 0xcb5: je     10ee <kprobe_unwind_ruby+0x10ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4334ULL;
	}
x86_l_cbb:
	/* 0xcbb: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cc0:
	/* 0xcc0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cc3:
	/* 0xcc3: je     10ee <kprobe_unwind_ruby+0x10ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4334ULL;
	}
x86_l_cc9:
	/* 0xcc9: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_cce:
	/* 0xcce: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_cd1:
	/* 0xcd1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cd6:
	/* 0xcd6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_cdb:
	/* 0xcdb: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_ce1:
	/* 0xce1: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_ce6:
	/* 0xce6: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_ceb:
	/* 0xceb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cf0:
	/* 0xcf0: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_cf3:
	/* 0xcf3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cf6:
	/* 0xcf6: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_cfc:
	/* 0xcfc: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_d01:
	/* 0xd01: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_d06:
	/* 0xd06: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d0b:
	/* 0xd0b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d10:
	/* 0xd10: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_d16:
	/* 0xd16: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_d1b:
	/* 0xd1b: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_d20:
	/* 0xd20: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d25:
	/* 0xd25: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_d28:
	/* 0xd28: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d2b:
	/* 0xd2b: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_812;
	}
x86_l_d31:
	/* 0xd31: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_d36:
	/* 0xd36: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_d3b:
	/* 0xd3b: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_d40:
	/* 0xd40: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d45:
	/* 0xd45: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_d4b:
	/* 0xd4b: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_d50:
	/* 0xd50: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_d55:
	/* 0xd55: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d5a:
	/* 0xd5a: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_d5d:
	/* 0xd5d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d60:
	/* 0xd60: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_aea;
	}
x86_l_d66:
	/* 0xd66: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d6b:
	/* 0xd6b: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_d6e:
	/* 0xd6e: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_d73:
	/* 0xd73: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_d78:
	/* 0xd78: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_d7b:
	/* 0xd7b: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_d7f:
	/* 0xd7f: je     1fc0 <kprobe_unwind_ruby+0x1fc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8128ULL;
	}
x86_l_d85:
	/* 0xd85: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d87:
	/* 0xd87: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_d8a:
	/* 0xd8a: jmp    1fc4 <kprobe_unwind_ruby+0x1fc4> */
	return 8132ULL;
x86_l_d8f:
	/* 0xd8f: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d91:
	/* 0xd91: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_d93:
	/* 0xd93: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_d97:
	/* 0xd97: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_d9a:
	/* 0xd9a: jbe    e27 <kprobe_unwind_ruby+0xe27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e27;
	}
x86_l_da0:
	/* 0xda0: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_da7:
	/* 0xda7: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_daa:
	/* 0xdaa: je     572 <kprobe_unwind_ruby+0x572> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1394ULL;
	}
x86_l_db0:
	/* 0xdb0: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_dba:
	/* 0xdba: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_dbf:
	/* 0xdbf: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_dc9:
	/* 0xdc9: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_dce:
	/* 0xdce: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_dd8:
	/* 0xdd8: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_ddd:
	/* 0xddd: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_de7:
	/* 0xde7: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_dec:
	/* 0xdec: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_df6:
	/* 0xdf6: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_dfb:
	/* 0xdfb: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_e05:
	/* 0xe05: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e0a:
	/* 0xe0a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e0f:
	/* 0xe0f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_e14:
	/* 0xe14: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_e19:
	/* 0xe19: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_e1e:
	/* 0xe1e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e20:
	/* 0xe20: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e22:
	/* 0xe22: jmp    572 <kprobe_unwind_ruby+0x572> */
	return 1394ULL;
x86_l_e27:
	/* 0xe27: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_e2e:
	/* 0xe2e: cmp    rax,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 127ULL);
x86_l_e32:
	/* 0xe32: jb     ed4 <kprobe_unwind_ruby+0xed4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3796ULL;
	}
x86_l_e38:
	/* 0xe38: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_e3f:
	/* 0xe3f: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e43:
	/* 0xe43: jne    26eb <kprobe_unwind_ruby+0x26eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9963ULL;
	}
x86_l_e49:
	/* 0xe49: mov    DWORD PTR [rsp+0x74],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206338ULL);
x86_l_e51:
	/* 0xe51: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_e58:
	/* 0xe58: lea    rsi,[rsp+0x74] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_e5d:
	/* 0xe5d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e62:
	/* 0xe62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e64:
	/* 0xe64: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e67:
	/* 0xe67: je     ff4 <kprobe_unwind_ruby+0xff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4084ULL;
	}
x86_l_e6d:
	/* 0xe6d: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_e70:
	/* 0xe70: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e74:
	/* 0xe74: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_e7a:
	/* 0xe7a: je     2863 <kprobe_unwind_ruby+0x2863> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10339ULL;
	}
x86_l_e80:
	/* 0xe80: movabs rax,0x6172662068737570 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7021787058401408368ULL);
x86_l_e8a:
	/* 0xe8a: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e8f:
	/* 0xe8f: movabs rax,0x206f742064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414100720745ULL);
x86_l_e99:
	/* 0xe99: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e9e:
	/* 0xe9e: movabs rax,0x6166203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332504820184434ULL);
	return 3752ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3752ULL: goto x86_l_ea8;
	case 3757ULL: goto x86_l_ead;
	case 3765ULL: goto x86_l_eb5;
	case 3770ULL: goto x86_l_eba;
	case 3775ULL: goto x86_l_ebf;
	case 3780ULL: goto x86_l_ec4;
	case 3782ULL: goto x86_l_ec6;
	case 3787ULL: goto x86_l_ecb;
	case 3789ULL: goto x86_l_ecd;
	case 3791ULL: goto x86_l_ecf;
	case 3796ULL: goto x86_l_ed4;
	case 3801ULL: goto x86_l_ed9;
	case 3804ULL: goto x86_l_edc;
	case 3811ULL: goto x86_l_ee3;
	case 3815ULL: goto x86_l_ee7;
	case 3822ULL: goto x86_l_eee;
	case 3829ULL: goto x86_l_ef5;
	case 3837ULL: goto x86_l_efd;
	case 3845ULL: goto x86_l_f05;
	case 3856ULL: goto x86_l_f10;
	case 3859ULL: goto x86_l_f13;
	case 3867ULL: goto x86_l_f1b;
	case 3872ULL: goto x86_l_f20;
	case 3881ULL: goto x86_l_f29;
	case 3888ULL: goto x86_l_f30;
	case 3895ULL: goto x86_l_f37;
	case 3898ULL: goto x86_l_f3a;
	case 3903ULL: goto x86_l_f3f;
	case 3905ULL: goto x86_l_f41;
	case 3908ULL: goto x86_l_f44;
	case 3914ULL: goto x86_l_f4a;
	case 3917ULL: goto x86_l_f4d;
	case 3922ULL: goto x86_l_f52;
	case 3930ULL: goto x86_l_f5a;
	case 3935ULL: goto x86_l_f5f;
	case 3940ULL: goto x86_l_f64;
	case 3943ULL: goto x86_l_f67;
	case 3948ULL: goto x86_l_f6c;
	case 3954ULL: goto x86_l_f72;
	case 3959ULL: goto x86_l_f77;
	case 3964ULL: goto x86_l_f7c;
	case 3969ULL: goto x86_l_f81;
	case 3972ULL: goto x86_l_f84;
	case 3975ULL: goto x86_l_f87;
	case 3981ULL: goto x86_l_f8d;
	case 3984ULL: goto x86_l_f90;
	case 3986ULL: goto x86_l_f92;
	case 3991ULL: goto x86_l_f97;
	case 3997ULL: goto x86_l_f9d;
	case 4002ULL: goto x86_l_fa2;
	case 4012ULL: goto x86_l_fac;
	case 4017ULL: goto x86_l_fb1;
	case 4027ULL: goto x86_l_fbb;
	case 4032ULL: goto x86_l_fc0;
	case 4042ULL: goto x86_l_fca;
	case 4047ULL: goto x86_l_fcf;
	case 4055ULL: goto x86_l_fd7;
	case 4060ULL: goto x86_l_fdc;
	case 4065ULL: goto x86_l_fe1;
	case 4070ULL: goto x86_l_fe6;
	case 4075ULL: goto x86_l_feb;
	case 4077ULL: goto x86_l_fed;
	case 4079ULL: goto x86_l_fef;
	case 4084ULL: goto x86_l_ff4;
	case 4088ULL: goto x86_l_ff8;
	case 4094ULL: goto x86_l_ffe;
	case 4100ULL: goto x86_l_1004;
	case 4102ULL: goto x86_l_1006;
	case 4107ULL: goto x86_l_100b;
	case 4114ULL: goto x86_l_1012;
	case 4117ULL: goto x86_l_1015;
	case 4123ULL: goto x86_l_101b;
	case 4133ULL: goto x86_l_1025;
	case 4138ULL: goto x86_l_102a;
	case 4148ULL: goto x86_l_1034;
	case 4153ULL: goto x86_l_1039;
	case 4163ULL: goto x86_l_1043;
	case 4168ULL: goto x86_l_1048;
	case 4178ULL: goto x86_l_1052;
	case 4183ULL: goto x86_l_1057;
	case 4193ULL: goto x86_l_1061;
	case 4198ULL: goto x86_l_1066;
	case 4208ULL: goto x86_l_1070;
	case 4213ULL: goto x86_l_1075;
	case 4218ULL: goto x86_l_107a;
	case 4223ULL: goto x86_l_107f;
	case 4228ULL: goto x86_l_1084;
	case 4231ULL: goto x86_l_1087;
	case 4236ULL: goto x86_l_108c;
	case 4238ULL: goto x86_l_108e;
	case 4240ULL: goto x86_l_1090;
	case 4245ULL: goto x86_l_1095;
	case 4255ULL: goto x86_l_109f;
	case 4260ULL: goto x86_l_10a4;
	case 4270ULL: goto x86_l_10ae;
	case 4275ULL: goto x86_l_10b3;
	case 4285ULL: goto x86_l_10bd;
	case 4290ULL: goto x86_l_10c2;
	case 4300ULL: goto x86_l_10cc;
	case 4305ULL: goto x86_l_10d1;
	case 4310ULL: goto x86_l_10d6;
	case 4315ULL: goto x86_l_10db;
	case 4320ULL: goto x86_l_10e0;
	case 4325ULL: goto x86_l_10e5;
	case 4327ULL: goto x86_l_10e7;
	case 4329ULL: goto x86_l_10e9;
	case 4334ULL: goto x86_l_10ee;
	case 4341ULL: goto x86_l_10f5;
	case 4347ULL: goto x86_l_10fb;
	case 4352ULL: goto x86_l_1100;
	case 4355ULL: goto x86_l_1103;
	case 4361ULL: goto x86_l_1109;
	case 4366ULL: goto x86_l_110e;
	case 4369ULL: goto x86_l_1111;
	case 4374ULL: goto x86_l_1116;
	case 4383ULL: goto x86_l_111f;
	case 4392ULL: goto x86_l_1128;
	case 4397ULL: goto x86_l_112d;
	case 4400ULL: goto x86_l_1130;
	case 4405ULL: goto x86_l_1135;
	case 4410ULL: goto x86_l_113a;
	case 4416ULL: goto x86_l_1140;
	case 4421ULL: goto x86_l_1145;
	case 4426ULL: goto x86_l_114a;
	case 4431ULL: goto x86_l_114f;
	case 4434ULL: goto x86_l_1152;
	case 4439ULL: goto x86_l_1157;
	case 4444ULL: goto x86_l_115c;
	case 4449ULL: goto x86_l_1161;
	case 4454ULL: goto x86_l_1166;
	case 4460ULL: goto x86_l_116c;
	case 4465ULL: goto x86_l_1171;
	case 4470ULL: goto x86_l_1176;
	case 4475ULL: goto x86_l_117b;
	case 4478ULL: goto x86_l_117e;
	case 4484ULL: goto x86_l_1184;
	case 4490ULL: goto x86_l_118a;
	case 4495ULL: goto x86_l_118f;
	case 4498ULL: goto x86_l_1192;
	case 4504ULL: goto x86_l_1198;
	case 4509ULL: goto x86_l_119d;
	case 4512ULL: goto x86_l_11a0;
	case 4517ULL: goto x86_l_11a5;
	case 4522ULL: goto x86_l_11aa;
	case 4528ULL: goto x86_l_11b0;
	case 4533ULL: goto x86_l_11b5;
	case 4538ULL: goto x86_l_11ba;
	case 4543ULL: goto x86_l_11bf;
	case 4546ULL: goto x86_l_11c2;
	case 4549ULL: goto x86_l_11c5;
	case 4555ULL: goto x86_l_11cb;
	case 4560ULL: goto x86_l_11d0;
	case 4565ULL: goto x86_l_11d5;
	case 4570ULL: goto x86_l_11da;
	case 4575ULL: goto x86_l_11df;
	case 4581ULL: goto x86_l_11e5;
	case 4586ULL: goto x86_l_11ea;
	case 4591ULL: goto x86_l_11ef;
	case 4596ULL: goto x86_l_11f4;
	case 4599ULL: goto x86_l_11f7;
	case 4602ULL: goto x86_l_11fa;
	case 4608ULL: goto x86_l_1200;
	case 4613ULL: goto x86_l_1205;
	case 4618ULL: goto x86_l_120a;
	case 4623ULL: goto x86_l_120f;
	case 4628ULL: goto x86_l_1214;
	case 4634ULL: goto x86_l_121a;
	case 4639ULL: goto x86_l_121f;
	case 4644ULL: goto x86_l_1224;
	case 4649ULL: goto x86_l_1229;
	case 4652ULL: goto x86_l_122c;
	case 4655ULL: goto x86_l_122f;
	case 4661ULL: goto x86_l_1235;
	case 4666ULL: goto x86_l_123a;
	case 4669ULL: goto x86_l_123d;
	case 4674ULL: goto x86_l_1242;
	case 4679ULL: goto x86_l_1247;
	case 4682ULL: goto x86_l_124a;
	case 4686ULL: goto x86_l_124e;
	case 4692ULL: goto x86_l_1254;
	case 4694ULL: goto x86_l_1256;
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
	case 4787ULL: goto x86_l_12b3;
	case 4792ULL: goto x86_l_12b8;
	case 4797ULL: goto x86_l_12bd;
	case 4802ULL: goto x86_l_12c2;
	case 4807ULL: goto x86_l_12c7;
	case 4811ULL: goto x86_l_12cb;
	case 4816ULL: goto x86_l_12d0;
	case 4818ULL: goto x86_l_12d2;
	case 4820ULL: goto x86_l_12d4;
	case 4829ULL: goto x86_l_12dd;
	case 4834ULL: goto x86_l_12e2;
	case 4840ULL: goto x86_l_12e8;
	case 4845ULL: goto x86_l_12ed;
	case 4847ULL: goto x86_l_12ef;
	case 4849ULL: goto x86_l_12f1;
	case 4853ULL: goto x86_l_12f5;
	case 4856ULL: goto x86_l_12f8;
	case 4862ULL: goto x86_l_12fe;
	case 4869ULL: goto x86_l_1305;
	case 4872ULL: goto x86_l_1308;
	case 4878ULL: goto x86_l_130e;
	case 4888ULL: goto x86_l_1318;
	case 4893ULL: goto x86_l_131d;
	case 4903ULL: goto x86_l_1327;
	case 4908ULL: goto x86_l_132c;
	case 4918ULL: goto x86_l_1336;
	case 4923ULL: goto x86_l_133b;
	case 4933ULL: goto x86_l_1345;
	case 4938ULL: goto x86_l_134a;
	case 4948ULL: goto x86_l_1354;
	case 4953ULL: goto x86_l_1359;
	case 4963ULL: goto x86_l_1363;
	case 4968ULL: goto x86_l_1368;
	case 4973ULL: goto x86_l_136d;
	case 4978ULL: goto x86_l_1372;
	case 4983ULL: goto x86_l_1377;
	case 4988ULL: goto x86_l_137c;
	case 4990ULL: goto x86_l_137e;
	case 4992ULL: goto x86_l_1380;
	case 4997ULL: goto x86_l_1385;
	case 5004ULL: goto x86_l_138c;
	case 5008ULL: goto x86_l_1390;
	case 5014ULL: goto x86_l_1396;
	case 5019ULL: goto x86_l_139b;
	case 5022ULL: goto x86_l_139e;
	case 5029ULL: goto x86_l_13a5;
	case 5033ULL: goto x86_l_13a9;
	case 5040ULL: goto x86_l_13b0;
	case 5047ULL: goto x86_l_13b7;
	case 5055ULL: goto x86_l_13bf;
	case 5063ULL: goto x86_l_13c7;
	case 5074ULL: goto x86_l_13d2;
	case 5077ULL: goto x86_l_13d5;
	case 5085ULL: goto x86_l_13dd;
	case 5090ULL: goto x86_l_13e2;
	case 5099ULL: goto x86_l_13eb;
	case 5106ULL: goto x86_l_13f2;
	case 5113ULL: goto x86_l_13f9;
	case 5116ULL: goto x86_l_13fc;
	case 5121ULL: goto x86_l_1401;
	case 5123ULL: goto x86_l_1403;
	case 5126ULL: goto x86_l_1406;
	case 5132ULL: goto x86_l_140c;
	case 5135ULL: goto x86_l_140f;
	case 5140ULL: goto x86_l_1414;
	case 5150ULL: goto x86_l_141e;
	case 5155ULL: goto x86_l_1423;
	case 5165ULL: goto x86_l_142d;
	case 5170ULL: goto x86_l_1432;
	case 5180ULL: goto x86_l_143c;
	case 5185ULL: goto x86_l_1441;
	case 5195ULL: goto x86_l_144b;
	case 5200ULL: goto x86_l_1450;
	case 5210ULL: goto x86_l_145a;
	case 5215ULL: goto x86_l_145f;
	case 5225ULL: goto x86_l_1469;
	case 5230ULL: goto x86_l_146e;
	case 5235ULL: goto x86_l_1473;
	case 5240ULL: goto x86_l_1478;
	case 5245ULL: goto x86_l_147d;
	case 5251ULL: goto x86_l_1483;
	case 5256ULL: goto x86_l_1488;
	case 5259ULL: goto x86_l_148b;
	case 5262ULL: goto x86_l_148e;
	case 5264ULL: goto x86_l_1490;
	case 5267ULL: goto x86_l_1493;
	case 5270ULL: goto x86_l_1496;
	case 5275ULL: goto x86_l_149b;
	case 5285ULL: goto x86_l_14a5;
	case 5290ULL: goto x86_l_14aa;
	case 5300ULL: goto x86_l_14b4;
	case 5305ULL: goto x86_l_14b9;
	case 5315ULL: goto x86_l_14c3;
	case 5320ULL: goto x86_l_14c8;
	case 5330ULL: goto x86_l_14d2;
	case 5335ULL: goto x86_l_14d7;
	case 5345ULL: goto x86_l_14e1;
	case 5350ULL: goto x86_l_14e6;
	case 5360ULL: goto x86_l_14f0;
	case 5365ULL: goto x86_l_14f5;
	case 5370ULL: goto x86_l_14fa;
	case 5375ULL: goto x86_l_14ff;
	case 5380ULL: goto x86_l_1504;
	case 5384ULL: goto x86_l_1508;
	case 5389ULL: goto x86_l_150d;
	case 5391ULL: goto x86_l_150f;
	case 5393ULL: goto x86_l_1511;
	case 5398ULL: goto x86_l_1516;
	case 5406ULL: goto x86_l_151e;
	case 5411ULL: goto x86_l_1523;
	case 5416ULL: goto x86_l_1528;
	case 5419ULL: goto x86_l_152b;
	case 5424ULL: goto x86_l_1530;
	case 5430ULL: goto x86_l_1536;
	case 5435ULL: goto x86_l_153b;
	case 5440ULL: goto x86_l_1540;
	case 5445ULL: goto x86_l_1545;
	case 5448ULL: goto x86_l_1548;
	case 5451ULL: goto x86_l_154b;
	case 5457ULL: goto x86_l_1551;
	case 5460ULL: goto x86_l_1554;
	case 5462ULL: goto x86_l_1556;
	case 5467ULL: goto x86_l_155b;
	case 5473ULL: goto x86_l_1561;
	case 5478ULL: goto x86_l_1566;
	case 5488ULL: goto x86_l_1570;
	case 5493ULL: goto x86_l_1575;
	case 5503ULL: goto x86_l_157f;
	case 5508ULL: goto x86_l_1584;
	case 5518ULL: goto x86_l_158e;
	case 5523ULL: goto x86_l_1593;
	case 5533ULL: goto x86_l_159d;
	case 5538ULL: goto x86_l_15a2;
	case 5548ULL: goto x86_l_15ac;
	case 5553ULL: goto x86_l_15b1;
	case 5563ULL: goto x86_l_15bb;
	case 5568ULL: goto x86_l_15c0;
	case 5573ULL: goto x86_l_15c5;
	case 5578ULL: goto x86_l_15ca;
	case 5583ULL: goto x86_l_15cf;
	case 5587ULL: goto x86_l_15d3;
	case 5592ULL: goto x86_l_15d8;
	case 5594ULL: goto x86_l_15da;
	case 5596ULL: goto x86_l_15dc;
	case 5599ULL: goto x86_l_15df;
	case 5605ULL: goto x86_l_15e5;
	case 5610ULL: goto x86_l_15ea;
	case 5620ULL: goto x86_l_15f4;
	case 5625ULL: goto x86_l_15f9;
	case 5635ULL: goto x86_l_1603;
	case 5640ULL: goto x86_l_1608;
	case 5650ULL: goto x86_l_1612;
	case 5655ULL: goto x86_l_1617;
	case 5665ULL: goto x86_l_1621;
	case 5670ULL: goto x86_l_1626;
	case 5680ULL: goto x86_l_1630;
	case 5685ULL: goto x86_l_1635;
	case 5695ULL: goto x86_l_163f;
	case 5700ULL: goto x86_l_1644;
	case 5705ULL: goto x86_l_1649;
	case 5710ULL: goto x86_l_164e;
	case 5715ULL: goto x86_l_1653;
	case 5719ULL: goto x86_l_1657;
	case 5724ULL: goto x86_l_165c;
	case 5726ULL: goto x86_l_165e;
	case 5728ULL: goto x86_l_1660;
	case 5733ULL: goto x86_l_1665;
	case 5743ULL: goto x86_l_166f;
	case 5748ULL: goto x86_l_1674;
	case 5758ULL: goto x86_l_167e;
	case 5763ULL: goto x86_l_1683;
	case 5773ULL: goto x86_l_168d;
	case 5778ULL: goto x86_l_1692;
	case 5786ULL: goto x86_l_169a;
	case 5791ULL: goto x86_l_169f;
	case 5796ULL: goto x86_l_16a4;
	case 5801ULL: goto x86_l_16a9;
	case 5806ULL: goto x86_l_16ae;
	case 5811ULL: goto x86_l_16b3;
	case 5813ULL: goto x86_l_16b5;
	case 5815ULL: goto x86_l_16b7;
	case 5820ULL: goto x86_l_16bc;
	case 5823ULL: goto x86_l_16bf;
	case 5829ULL: goto x86_l_16c5;
	case 5834ULL: goto x86_l_16ca;
	case 5841ULL: goto x86_l_16d1;
	case 5844ULL: goto x86_l_16d4;
	case 5850ULL: goto x86_l_16da;
	case 5860ULL: goto x86_l_16e4;
	case 5865ULL: goto x86_l_16e9;
	case 5875ULL: goto x86_l_16f3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_ea8:
	/* 0xea8: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ead:
	/* 0xead: mov    DWORD PTR [rsp+0x48],0xa656d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309238326637ULL);
x86_l_eb5:
	/* 0xeb5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_eba:
	/* 0xeba: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_ebf:
	/* 0xebf: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_ec4:
	/* 0xec4: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ec6:
	/* 0xec6: mov    esi,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 28ULL);
x86_l_ecb:
	/* 0xecb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ecd:
	/* 0xecd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_ecf:
	/* 0xecf: jmp    2ab <kprobe_unwind_ruby+0x2ab> */
	return 683ULL;
x86_l_ed4:
	/* 0xed4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ed9:
	/* 0xed9: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_edc:
	/* 0xedc: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_ee3:
	/* 0xee3: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_ee7:
	/* 0xee7: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_eee:
	/* 0xeee: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ef5:
	/* 0xef5: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_efd:
	/* 0xefd: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_f05:
	/* 0xf05: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_f10:
	/* 0xf10: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f13:
	/* 0xf13: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_f1b:
	/* 0xf1b: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_f20:
	/* 0xf20: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_f29:
	/* 0xf29: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_f30:
	/* 0xf30: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_f37:
	/* 0xf37: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_f3a:
	/* 0xf3a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f3f:
	/* 0xf3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f41:
	/* 0xf41: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f44:
	/* 0xf44: je     100b <kprobe_unwind_ruby+0x100b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_100b;
	}
x86_l_f4a:
	/* 0xf4a: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_f4d:
	/* 0xf4d: jmp    572 <kprobe_unwind_ruby+0x572> */
	return 1394ULL;
x86_l_f52:
	/* 0xf52: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f5a:
	/* 0xf5a: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_f5f:
	/* 0xf5f: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_f64:
	/* 0xf64: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_f67:
	/* 0xf67: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f6c:
	/* 0xf6c: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_f72:
	/* 0xf72: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_f77:
	/* 0xf77: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_f7c:
	/* 0xf7c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f81:
	/* 0xf81: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_f84:
	/* 0xf84: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f87:
	/* 0xf87: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_f8d:
	/* 0xf8d: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f90:
	/* 0xf90: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_f92:
	/* 0xf92: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_f97:
	/* 0xf97: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_f9d:
	/* 0xf9d: jmp    c29 <kprobe_unwind_ruby+0xc29> */
	return 3113ULL;
x86_l_fa2:
	/* 0xfa2: movabs rax,0x6164206e6f697463 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7017769778037748835ULL);
x86_l_fac:
	/* 0xfac: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_fb1:
	/* 0xfb1: movabs rax,0x6570736f72746e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7309469117721112169ULL);
x86_l_fbb:
	/* 0xfbb: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_fc0:
	/* 0xfc0: movabs rax,0x2079627552206f4e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2340009737424236366ULL);
x86_l_fca:
	/* 0xfca: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fcf:
	/* 0xfcf: mov    DWORD PTR [rsp+0x48],0xa6174 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309238325620ULL);
x86_l_fd7:
	/* 0xfd7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fdc:
	/* 0xfdc: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_fe1:
	/* 0xfe1: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_fe6:
	/* 0xfe6: mov    esi,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 28ULL);
x86_l_feb:
	/* 0xfeb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fed:
	/* 0xfed: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_fef:
	/* 0xfef: jmp    113 <kprobe_unwind_ruby+0x113> */
	return 275ULL;
x86_l_ff4:
	/* 0xff4: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ff8:
	/* 0xff8: jne    27dd <kprobe_unwind_ruby+0x27dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10205ULL;
	}
x86_l_ffe:
	/* 0xffe: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_1004:
	/* 0x1004: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1006:
	/* 0x1006: jmp    2ab <kprobe_unwind_ruby+0x2ab> */
	return 683ULL;
x86_l_100b:
	/* 0x100b: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1012:
	/* 0x1012: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1015:
	/* 0x1015: je     572 <kprobe_unwind_ruby+0x572> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1394ULL;
	}
x86_l_101b:
	/* 0x101b: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1025:
	/* 0x1025: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_102a:
	/* 0x102a: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1034:
	/* 0x1034: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1039:
	/* 0x1039: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1043:
	/* 0x1043: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1048:
	/* 0x1048: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1052:
	/* 0x1052: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1057:
	/* 0x1057: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1061:
	/* 0x1061: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1066:
	/* 0x1066: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1070:
	/* 0x1070: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1075:
	/* 0x1075: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_107a:
	/* 0x107a: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_107f:
	/* 0x107f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1084:
	/* 0x1084: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1087:
	/* 0x1087: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_108c:
	/* 0x108c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_108e:
	/* 0x108e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1090:
	/* 0x1090: jmp    572 <kprobe_unwind_ruby+0x572> */
	return 1394ULL;
x86_l_1095:
	/* 0x1095: movabs rax,0xa65756c617620 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926304771012128ULL);
x86_l_109f:
	/* 0x109f: mov    QWORD PTR [rsp+0x45],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_10a4:
	/* 0x10a4: movabs rax,0x6176206573616270 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7022836289030414960ULL);
x86_l_10ae:
	/* 0x10ae: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_10b3:
	/* 0x10b3: movabs rax,0x742064616572206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798477130965103ULL);
x86_l_10bd:
	/* 0x10bd: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_10c2:
	/* 0x10c2: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_10cc:
	/* 0x10cc: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10d1:
	/* 0x10d1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10d6:
	/* 0x10d6: mov    eax,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_10db:
	/* 0x10db: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_10e0:
	/* 0x10e0: mov    esi,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 29ULL);
x86_l_10e5:
	/* 0x10e5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10e7:
	/* 0x10e7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_10e9:
	/* 0x10e9: jmp    1a8 <kprobe_unwind_ruby+0x1a8> */
	return 424ULL;
x86_l_10ee:
	/* 0x10ee: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_10f5:
	/* 0x10f5: jae    1516 <kprobe_unwind_ruby+0x1516> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1516;
	}
x86_l_10fb:
	/* 0x10fb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1100:
	/* 0x1100: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1103:
	/* 0x1103: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_1109:
	/* 0x1109: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_110e:
	/* 0x110e: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1111:
	/* 0x1111: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1116:
	/* 0x1116: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_111f:
	/* 0x111f: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1128:
	/* 0x1128: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_112d:
	/* 0x112d: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1130:
	/* 0x1130: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1135:
	/* 0x1135: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_113a:
	/* 0x113a: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1140:
	/* 0x1140: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_1145:
	/* 0x1145: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_114a:
	/* 0x114a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_114f:
	/* 0x114f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1152:
	/* 0x1152: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_1157:
	/* 0x1157: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_115c:
	/* 0x115c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1161:
	/* 0x1161: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1166:
	/* 0x1166: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_116c:
	/* 0x116c: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_1171:
	/* 0x1171: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1176:
	/* 0x1176: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_117b:
	/* 0x117b: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_117e:
	/* 0x117e: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1184:
	/* 0x1184: je     1754 <kprobe_unwind_ruby+0x1754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5972ULL;
	}
x86_l_118a:
	/* 0x118a: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_118f:
	/* 0x118f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1192:
	/* 0x1192: je     1754 <kprobe_unwind_ruby+0x1754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5972ULL;
	}
x86_l_1198:
	/* 0x1198: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_119d:
	/* 0x119d: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_11a0:
	/* 0x11a0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11a5:
	/* 0x11a5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11aa:
	/* 0x11aa: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_11b0:
	/* 0x11b0: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_11b5:
	/* 0x11b5: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_11ba:
	/* 0x11ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11bf:
	/* 0x11bf: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_11c2:
	/* 0x11c2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11c5:
	/* 0x11c5: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_11cb:
	/* 0x11cb: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_11d0:
	/* 0x11d0: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_11d5:
	/* 0x11d5: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_11da:
	/* 0x11da: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11df:
	/* 0x11df: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_11e5:
	/* 0x11e5: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_11ea:
	/* 0x11ea: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_11ef:
	/* 0x11ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11f4:
	/* 0x11f4: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_11f7:
	/* 0x11f7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11fa:
	/* 0x11fa: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_1200:
	/* 0x1200: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_1205:
	/* 0x1205: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_120a:
	/* 0x120a: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_120f:
	/* 0x120f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1214:
	/* 0x1214: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_121a:
	/* 0x121a: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_121f:
	/* 0x121f: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1224:
	/* 0x1224: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1229:
	/* 0x1229: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_122c:
	/* 0x122c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_122f:
	/* 0x122f: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_1235:
	/* 0x1235: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_123a:
	/* 0x123a: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_123d:
	/* 0x123d: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_1242:
	/* 0x1242: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_1247:
	/* 0x1247: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_124a:
	/* 0x124a: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_124e:
	/* 0x124e: je     2574 <kprobe_unwind_ruby+0x2574> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9588ULL;
	}
x86_l_1254:
	/* 0x1254: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1256:
	/* 0x1256: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1259:
	/* 0x1259: jmp    2578 <kprobe_unwind_ruby+0x2578> */
	return 9592ULL;
x86_l_125e:
	/* 0x125e: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1268:
	/* 0x1268: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_126d:
	/* 0x126d: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1277:
	/* 0x1277: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_127c:
	/* 0x127c: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1286:
	/* 0x1286: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_128b:
	/* 0x128b: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1295:
	/* 0x1295: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_129a:
	/* 0x129a: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_12a4:
	/* 0x12a4: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12a9:
	/* 0x12a9: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_12b3:
	/* 0x12b3: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12b8:
	/* 0x12b8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12bd:
	/* 0x12bd: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_12c2:
	/* 0x12c2: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_12c7:
	/* 0x12c7: mov    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12cb:
	/* 0x12cb: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_12d0:
	/* 0x12d0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12d2:
	/* 0x12d2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_12d4:
	/* 0x12d4: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_12dd:
	/* 0x12dd: cmp    QWORD PTR [r15+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_12e2:
	/* 0x12e2: jne    163 <kprobe_unwind_ruby+0x163> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 355ULL;
	}
x86_l_12e8:
	/* 0x12e8: jmp    9a <kprobe_unwind_ruby+0x9a> */
	return 154ULL;
x86_l_12ed:
	/* 0x12ed: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12ef:
	/* 0x12ef: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_12f1:
	/* 0x12f1: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_12f5:
	/* 0x12f5: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_12f8:
	/* 0x12f8: jbe    1385 <kprobe_unwind_ruby+0x1385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1385;
	}
x86_l_12fe:
	/* 0x12fe: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1305:
	/* 0x1305: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1308:
	/* 0x1308: je     953 <kprobe_unwind_ruby+0x953> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2387ULL;
	}
x86_l_130e:
	/* 0x130e: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_1318:
	/* 0x1318: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_131d:
	/* 0x131d: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_1327:
	/* 0x1327: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_132c:
	/* 0x132c: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_1336:
	/* 0x1336: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_133b:
	/* 0x133b: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_1345:
	/* 0x1345: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_134a:
	/* 0x134a: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_1354:
	/* 0x1354: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1359:
	/* 0x1359: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_1363:
	/* 0x1363: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1368:
	/* 0x1368: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_136d:
	/* 0x136d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1372:
	/* 0x1372: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1377:
	/* 0x1377: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_137c:
	/* 0x137c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_137e:
	/* 0x137e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1380:
	/* 0x1380: jmp    953 <kprobe_unwind_ruby+0x953> */
	return 2387ULL;
x86_l_1385:
	/* 0x1385: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_138c:
	/* 0x138c: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_1390:
	/* 0x1390: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_1396:
	/* 0x1396: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_139b:
	/* 0x139b: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_139e:
	/* 0x139e: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_13a5:
	/* 0x13a5: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_13a9:
	/* 0x13a9: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_13b0:
	/* 0x13b0: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13b7:
	/* 0x13b7: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_13bf:
	/* 0x13bf: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_13c7:
	/* 0x13c7: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_13d2:
	/* 0x13d2: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13d5:
	/* 0x13d5: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_13dd:
	/* 0x13dd: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_13e2:
	/* 0x13e2: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_13eb:
	/* 0x13eb: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_13f2:
	/* 0x13f2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_13f9:
	/* 0x13f9: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_13fc:
	/* 0x13fc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1401:
	/* 0x1401: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1403:
	/* 0x1403: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1406:
	/* 0x1406: je     16ca <kprobe_unwind_ruby+0x16ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16ca;
	}
x86_l_140c:
	/* 0x140c: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_140f:
	/* 0x140f: jmp    953 <kprobe_unwind_ruby+0x953> */
	return 2387ULL;
x86_l_1414:
	/* 0x1414: movabs rax,0xa786c6c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 754472149325459488ULL);
x86_l_141e:
	/* 0x141e: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1423:
	/* 0x1423: movabs rax,0x6d6f726620786c6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7885647255506021484ULL);
x86_l_142d:
	/* 0x142d: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1432:
	/* 0x1432: movabs rax,0x2578302072646461 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2699960892524880993ULL);
x86_l_143c:
	/* 0x143c: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1441:
	/* 0x1441: movabs rax,0x206c6f626d797320 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2336364775232598816ULL);
x86_l_144b:
	/* 0x144b: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1450:
	/* 0x1450: movabs rax,0x434520534c542074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4847316116069163124ULL);
x86_l_145a:
	/* 0x145a: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_145f:
	/* 0x145f: movabs rax,0x6f67203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8027420296327886194ULL);
x86_l_1469:
	/* 0x1469: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_146e:
	/* 0x146e: mov    BYTE PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1473:
	/* 0x1473: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1478:
	/* 0x1478: mov    eax,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 49ULL);
x86_l_147d:
	/* 0x147d: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_1483:
	/* 0x1483: mov    esi,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 49ULL);
x86_l_1488:
	/* 0x1488: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_148b:
	/* 0x148b: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_148e:
	/* 0x148e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1490:
	/* 0x1490: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1493:
	/* 0x1493: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1496:
	/* 0x1496: jmp    272 <kprobe_unwind_ruby+0x272> */
	return 626ULL;
x86_l_149b:
	/* 0x149b: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_14a5:
	/* 0x14a5: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_14aa:
	/* 0x14aa: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_14b4:
	/* 0x14b4: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14b9:
	/* 0x14b9: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_14c3:
	/* 0x14c3: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_14c8:
	/* 0x14c8: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_14d2:
	/* 0x14d2: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14d7:
	/* 0x14d7: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_14e1:
	/* 0x14e1: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14e6:
	/* 0x14e6: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_14f0:
	/* 0x14f0: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14f5:
	/* 0x14f5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14fa:
	/* 0x14fa: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_14ff:
	/* 0x14ff: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1504:
	/* 0x1504: mov    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1508:
	/* 0x1508: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_150d:
	/* 0x150d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_150f:
	/* 0x150f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1511:
	/* 0x1511: jmp    2a0 <kprobe_unwind_ruby+0x2a0> */
	return 672ULL;
x86_l_1516:
	/* 0x1516: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_151e:
	/* 0x151e: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_1523:
	/* 0x1523: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1528:
	/* 0x1528: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_152b:
	/* 0x152b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1530:
	/* 0x1530: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1536:
	/* 0x1536: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_153b:
	/* 0x153b: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1540:
	/* 0x1540: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1545:
	/* 0x1545: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1548:
	/* 0x1548: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_154b:
	/* 0x154b: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_1551:
	/* 0x1551: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1554:
	/* 0x1554: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1556:
	/* 0x1556: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_155b:
	/* 0x155b: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_1561:
	/* 0x1561: jmp    10fb <kprobe_unwind_ruby+0x10fb> */
	goto x86_l_10fb;
x86_l_1566:
	/* 0x1566: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1570:
	/* 0x1570: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1575:
	/* 0x1575: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_157f:
	/* 0x157f: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1584:
	/* 0x1584: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_158e:
	/* 0x158e: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1593:
	/* 0x1593: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_159d:
	/* 0x159d: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15a2:
	/* 0x15a2: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_15ac:
	/* 0x15ac: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15b1:
	/* 0x15b1: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_15bb:
	/* 0x15bb: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15c0:
	/* 0x15c0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15c5:
	/* 0x15c5: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_15ca:
	/* 0x15ca: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_15cf:
	/* 0x15cf: mov    edx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15d3:
	/* 0x15d3: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_15d8:
	/* 0x15d8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15da:
	/* 0x15da: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_15dc:
	/* 0x15dc: cmp    DWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15df:
	/* 0x15df: je     375 <kprobe_unwind_ruby+0x375> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 885ULL;
	}
x86_l_15e5:
	/* 0x15e5: jmp    1d8 <kprobe_unwind_ruby+0x1d8> */
	return 472ULL;
x86_l_15ea:
	/* 0x15ea: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_15f4:
	/* 0x15f4: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_15f9:
	/* 0x15f9: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1603:
	/* 0x1603: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1608:
	/* 0x1608: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1612:
	/* 0x1612: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1617:
	/* 0x1617: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1621:
	/* 0x1621: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1626:
	/* 0x1626: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1630:
	/* 0x1630: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1635:
	/* 0x1635: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_163f:
	/* 0x163f: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1644:
	/* 0x1644: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1649:
	/* 0x1649: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_164e:
	/* 0x164e: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1653:
	/* 0x1653: mov    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1657:
	/* 0x1657: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_165c:
	/* 0x165c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_165e:
	/* 0x165e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1660:
	/* 0x1660: jmp    389 <kprobe_unwind_ruby+0x389> */
	return 905ULL;
x86_l_1665:
	/* 0x1665: movabs rax,0x6c6c257830203a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660651714689619ULL);
x86_l_166f:
	/* 0x166f: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1674:
	/* 0x1674: movabs rax,0x4c54206d6f726620 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5500056699319510560ULL);
x86_l_167e:
	/* 0x167e: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1683:
	/* 0x1683: movabs rax,0x4345203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4847316009450894706ULL);
x86_l_168d:
	/* 0x168d: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1692:
	/* 0x1692: mov    DWORD PTR [rsp+0x47],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304943364204ULL);
x86_l_169a:
	/* 0x169a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_169f:
	/* 0x169f: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_16a4:
	/* 0x16a4: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_16a9:
	/* 0x16a9: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_16ae:
	/* 0x16ae: mov    esi,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 27ULL);
x86_l_16b3:
	/* 0x16b3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16b5:
	/* 0x16b5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_16b7:
	/* 0x16b7: mov    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_16bc:
	/* 0x16bc: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_16bf:
	/* 0x16bf: jne    3e0 <kprobe_unwind_ruby+0x3e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 992ULL;
	}
x86_l_16c5:
	/* 0x16c5: jmp    291 <kprobe_unwind_ruby+0x291> */
	return 657ULL;
x86_l_16ca:
	/* 0x16ca: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_16d1:
	/* 0x16d1: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16d4:
	/* 0x16d4: je     953 <kprobe_unwind_ruby+0x953> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2387ULL;
	}
x86_l_16da:
	/* 0x16da: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_16e4:
	/* 0x16e4: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_16e9:
	/* 0x16e9: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_16f3:
	/* 0x16f3: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
	return 5880ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5880ULL: goto x86_l_16f8;
	case 5890ULL: goto x86_l_1702;
	case 5895ULL: goto x86_l_1707;
	case 5905ULL: goto x86_l_1711;
	case 5910ULL: goto x86_l_1716;
	case 5920ULL: goto x86_l_1720;
	case 5925ULL: goto x86_l_1725;
	case 5935ULL: goto x86_l_172f;
	case 5940ULL: goto x86_l_1734;
	case 5945ULL: goto x86_l_1739;
	case 5950ULL: goto x86_l_173e;
	case 5955ULL: goto x86_l_1743;
	case 5958ULL: goto x86_l_1746;
	case 5963ULL: goto x86_l_174b;
	case 5965ULL: goto x86_l_174d;
	case 5967ULL: goto x86_l_174f;
	case 5972ULL: goto x86_l_1754;
	case 5979ULL: goto x86_l_175b;
	case 5985ULL: goto x86_l_1761;
	case 5990ULL: goto x86_l_1766;
	case 5993ULL: goto x86_l_1769;
	case 5999ULL: goto x86_l_176f;
	case 6004ULL: goto x86_l_1774;
	case 6007ULL: goto x86_l_1777;
	case 6012ULL: goto x86_l_177c;
	case 6021ULL: goto x86_l_1785;
	case 6030ULL: goto x86_l_178e;
	case 6035ULL: goto x86_l_1793;
	case 6038ULL: goto x86_l_1796;
	case 6043ULL: goto x86_l_179b;
	case 6048ULL: goto x86_l_17a0;
	case 6054ULL: goto x86_l_17a6;
	case 6059ULL: goto x86_l_17ab;
	case 6064ULL: goto x86_l_17b0;
	case 6069ULL: goto x86_l_17b5;
	case 6072ULL: goto x86_l_17b8;
	case 6077ULL: goto x86_l_17bd;
	case 6082ULL: goto x86_l_17c2;
	case 6087ULL: goto x86_l_17c7;
	case 6092ULL: goto x86_l_17cc;
	case 6098ULL: goto x86_l_17d2;
	case 6103ULL: goto x86_l_17d7;
	case 6108ULL: goto x86_l_17dc;
	case 6113ULL: goto x86_l_17e1;
	case 6116ULL: goto x86_l_17e4;
	case 6122ULL: goto x86_l_17ea;
	case 6128ULL: goto x86_l_17f0;
	case 6133ULL: goto x86_l_17f5;
	case 6136ULL: goto x86_l_17f8;
	case 6142ULL: goto x86_l_17fe;
	case 6147ULL: goto x86_l_1803;
	case 6150ULL: goto x86_l_1806;
	case 6155ULL: goto x86_l_180b;
	case 6160ULL: goto x86_l_1810;
	case 6166ULL: goto x86_l_1816;
	case 6171ULL: goto x86_l_181b;
	case 6176ULL: goto x86_l_1820;
	case 6181ULL: goto x86_l_1825;
	case 6184ULL: goto x86_l_1828;
	case 6187ULL: goto x86_l_182b;
	case 6193ULL: goto x86_l_1831;
	case 6198ULL: goto x86_l_1836;
	case 6203ULL: goto x86_l_183b;
	case 6208ULL: goto x86_l_1840;
	case 6213ULL: goto x86_l_1845;
	case 6219ULL: goto x86_l_184b;
	case 6224ULL: goto x86_l_1850;
	case 6229ULL: goto x86_l_1855;
	case 6234ULL: goto x86_l_185a;
	case 6237ULL: goto x86_l_185d;
	case 6240ULL: goto x86_l_1860;
	case 6246ULL: goto x86_l_1866;
	case 6251ULL: goto x86_l_186b;
	case 6256ULL: goto x86_l_1870;
	case 6261ULL: goto x86_l_1875;
	case 6266ULL: goto x86_l_187a;
	case 6272ULL: goto x86_l_1880;
	case 6277ULL: goto x86_l_1885;
	case 6282ULL: goto x86_l_188a;
	case 6287ULL: goto x86_l_188f;
	case 6290ULL: goto x86_l_1892;
	case 6293ULL: goto x86_l_1895;
	case 6299ULL: goto x86_l_189b;
	case 6304ULL: goto x86_l_18a0;
	case 6307ULL: goto x86_l_18a3;
	case 6312ULL: goto x86_l_18a8;
	case 6317ULL: goto x86_l_18ad;
	case 6320ULL: goto x86_l_18b0;
	case 6324ULL: goto x86_l_18b4;
	case 6330ULL: goto x86_l_18ba;
	case 6332ULL: goto x86_l_18bc;
	case 6335ULL: goto x86_l_18bf;
	case 6340ULL: goto x86_l_18c4;
	case 6350ULL: goto x86_l_18ce;
	case 6355ULL: goto x86_l_18d3;
	case 6365ULL: goto x86_l_18dd;
	case 6370ULL: goto x86_l_18e2;
	case 6380ULL: goto x86_l_18ec;
	case 6385ULL: goto x86_l_18f1;
	case 6395ULL: goto x86_l_18fb;
	case 6400ULL: goto x86_l_1900;
	case 6410ULL: goto x86_l_190a;
	case 6415ULL: goto x86_l_190f;
	case 6423ULL: goto x86_l_1917;
	case 6428ULL: goto x86_l_191c;
	case 6433ULL: goto x86_l_1921;
	case 6438ULL: goto x86_l_1926;
	case 6443ULL: goto x86_l_192b;
	case 6445ULL: goto x86_l_192d;
	case 6447ULL: goto x86_l_192f;
	case 6452ULL: goto x86_l_1934;
	case 6454ULL: goto x86_l_1936;
	case 6456ULL: goto x86_l_1938;
	case 6460ULL: goto x86_l_193c;
	case 6463ULL: goto x86_l_193f;
	case 6469ULL: goto x86_l_1945;
	case 6476ULL: goto x86_l_194c;
	case 6479ULL: goto x86_l_194f;
	case 6485ULL: goto x86_l_1955;
	case 6495ULL: goto x86_l_195f;
	case 6500ULL: goto x86_l_1964;
	case 6510ULL: goto x86_l_196e;
	case 6515ULL: goto x86_l_1973;
	case 6525ULL: goto x86_l_197d;
	case 6530ULL: goto x86_l_1982;
	case 6540ULL: goto x86_l_198c;
	case 6545ULL: goto x86_l_1991;
	case 6555ULL: goto x86_l_199b;
	case 6560ULL: goto x86_l_19a0;
	case 6570ULL: goto x86_l_19aa;
	case 6575ULL: goto x86_l_19af;
	case 6580ULL: goto x86_l_19b4;
	case 6585ULL: goto x86_l_19b9;
	case 6590ULL: goto x86_l_19be;
	case 6595ULL: goto x86_l_19c3;
	case 6597ULL: goto x86_l_19c5;
	case 6599ULL: goto x86_l_19c7;
	case 6604ULL: goto x86_l_19cc;
	case 6611ULL: goto x86_l_19d3;
	case 6615ULL: goto x86_l_19d7;
	case 6621ULL: goto x86_l_19dd;
	case 6626ULL: goto x86_l_19e2;
	case 6629ULL: goto x86_l_19e5;
	case 6636ULL: goto x86_l_19ec;
	case 6640ULL: goto x86_l_19f0;
	case 6647ULL: goto x86_l_19f7;
	case 6654ULL: goto x86_l_19fe;
	case 6662ULL: goto x86_l_1a06;
	case 6670ULL: goto x86_l_1a0e;
	case 6681ULL: goto x86_l_1a19;
	case 6684ULL: goto x86_l_1a1c;
	case 6692ULL: goto x86_l_1a24;
	case 6697ULL: goto x86_l_1a29;
	case 6706ULL: goto x86_l_1a32;
	case 6713ULL: goto x86_l_1a39;
	case 6720ULL: goto x86_l_1a40;
	case 6723ULL: goto x86_l_1a43;
	case 6728ULL: goto x86_l_1a48;
	case 6730ULL: goto x86_l_1a4a;
	case 6733ULL: goto x86_l_1a4d;
	case 6739ULL: goto x86_l_1a53;
	case 6742ULL: goto x86_l_1a56;
	case 6747ULL: goto x86_l_1a5b;
	case 6757ULL: goto x86_l_1a65;
	case 6762ULL: goto x86_l_1a6a;
	case 6772ULL: goto x86_l_1a74;
	case 6777ULL: goto x86_l_1a79;
	case 6787ULL: goto x86_l_1a83;
	case 6792ULL: goto x86_l_1a88;
	case 6802ULL: goto x86_l_1a92;
	case 6807ULL: goto x86_l_1a97;
	case 6812ULL: goto x86_l_1a9c;
	case 6817ULL: goto x86_l_1aa1;
	case 6822ULL: goto x86_l_1aa6;
	case 6827ULL: goto x86_l_1aab;
	case 6829ULL: goto x86_l_1aad;
	case 6831ULL: goto x86_l_1aaf;
	case 6836ULL: goto x86_l_1ab4;
	case 6844ULL: goto x86_l_1abc;
	case 6849ULL: goto x86_l_1ac1;
	case 6854ULL: goto x86_l_1ac6;
	case 6857ULL: goto x86_l_1ac9;
	case 6862ULL: goto x86_l_1ace;
	case 6868ULL: goto x86_l_1ad4;
	case 6873ULL: goto x86_l_1ad9;
	case 6878ULL: goto x86_l_1ade;
	case 6883ULL: goto x86_l_1ae3;
	case 6886ULL: goto x86_l_1ae6;
	case 6889ULL: goto x86_l_1ae9;
	case 6895ULL: goto x86_l_1aef;
	case 6898ULL: goto x86_l_1af2;
	case 6900ULL: goto x86_l_1af4;
	case 6905ULL: goto x86_l_1af9;
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
	case 6998ULL: goto x86_l_1b56;
	case 7000ULL: goto x86_l_1b58;
	case 7005ULL: goto x86_l_1b5d;
	case 7015ULL: goto x86_l_1b67;
	case 7020ULL: goto x86_l_1b6c;
	case 7030ULL: goto x86_l_1b76;
	case 7035ULL: goto x86_l_1b7b;
	case 7045ULL: goto x86_l_1b85;
	case 7050ULL: goto x86_l_1b8a;
	case 7060ULL: goto x86_l_1b94;
	case 7065ULL: goto x86_l_1b99;
	case 7075ULL: goto x86_l_1ba3;
	case 7080ULL: goto x86_l_1ba8;
	case 7090ULL: goto x86_l_1bb2;
	case 7095ULL: goto x86_l_1bb7;
	case 7100ULL: goto x86_l_1bbc;
	case 7105ULL: goto x86_l_1bc1;
	case 7110ULL: goto x86_l_1bc6;
	case 7114ULL: goto x86_l_1bca;
	case 7119ULL: goto x86_l_1bcf;
	case 7121ULL: goto x86_l_1bd1;
	case 7123ULL: goto x86_l_1bd3;
	case 7128ULL: goto x86_l_1bd8;
	case 7138ULL: goto x86_l_1be2;
	case 7143ULL: goto x86_l_1be7;
	case 7153ULL: goto x86_l_1bf1;
	case 7158ULL: goto x86_l_1bf6;
	case 7168ULL: goto x86_l_1c00;
	case 7173ULL: goto x86_l_1c05;
	case 7178ULL: goto x86_l_1c0a;
	case 7183ULL: goto x86_l_1c0f;
	case 7188ULL: goto x86_l_1c14;
	case 7193ULL: goto x86_l_1c19;
	case 7195ULL: goto x86_l_1c1b;
	case 7197ULL: goto x86_l_1c1d;
	case 7202ULL: goto x86_l_1c22;
	case 7212ULL: goto x86_l_1c2c;
	case 7217ULL: goto x86_l_1c31;
	case 7227ULL: goto x86_l_1c3b;
	case 7232ULL: goto x86_l_1c40;
	case 7242ULL: goto x86_l_1c4a;
	case 7247ULL: goto x86_l_1c4f;
	case 7257ULL: goto x86_l_1c59;
	case 7262ULL: goto x86_l_1c5e;
	case 7269ULL: goto x86_l_1c65;
	case 7274ULL: goto x86_l_1c6a;
	case 7279ULL: goto x86_l_1c6f;
	case 7284ULL: goto x86_l_1c74;
	case 7289ULL: goto x86_l_1c79;
	case 7291ULL: goto x86_l_1c7b;
	case 7293ULL: goto x86_l_1c7d;
	case 7298ULL: goto x86_l_1c82;
	case 7308ULL: goto x86_l_1c8c;
	case 7313ULL: goto x86_l_1c91;
	case 7323ULL: goto x86_l_1c9b;
	case 7328ULL: goto x86_l_1ca0;
	case 7338ULL: goto x86_l_1caa;
	case 7343ULL: goto x86_l_1caf;
	case 7353ULL: goto x86_l_1cb9;
	case 7358ULL: goto x86_l_1cbe;
	case 7368ULL: goto x86_l_1cc8;
	case 7373ULL: goto x86_l_1ccd;
	case 7383ULL: goto x86_l_1cd7;
	case 7388ULL: goto x86_l_1cdc;
	case 7393ULL: goto x86_l_1ce1;
	case 7398ULL: goto x86_l_1ce6;
	case 7403ULL: goto x86_l_1ceb;
	case 7406ULL: goto x86_l_1cee;
	case 7411ULL: goto x86_l_1cf3;
	case 7413ULL: goto x86_l_1cf5;
	case 7415ULL: goto x86_l_1cf7;
	case 7420ULL: goto x86_l_1cfc;
	case 7427ULL: goto x86_l_1d03;
	case 7430ULL: goto x86_l_1d06;
	case 7436ULL: goto x86_l_1d0c;
	case 7446ULL: goto x86_l_1d16;
	case 7451ULL: goto x86_l_1d1b;
	case 7461ULL: goto x86_l_1d25;
	case 7466ULL: goto x86_l_1d2a;
	case 7476ULL: goto x86_l_1d34;
	case 7481ULL: goto x86_l_1d39;
	case 7491ULL: goto x86_l_1d43;
	case 7496ULL: goto x86_l_1d48;
	case 7506ULL: goto x86_l_1d52;
	case 7511ULL: goto x86_l_1d57;
	case 7521ULL: goto x86_l_1d61;
	case 7526ULL: goto x86_l_1d66;
	case 7531ULL: goto x86_l_1d6b;
	case 7536ULL: goto x86_l_1d70;
	case 7541ULL: goto x86_l_1d75;
	case 7544ULL: goto x86_l_1d78;
	case 7549ULL: goto x86_l_1d7d;
	case 7551ULL: goto x86_l_1d7f;
	case 7553ULL: goto x86_l_1d81;
	case 7558ULL: goto x86_l_1d86;
	case 7565ULL: goto x86_l_1d8d;
	case 7571ULL: goto x86_l_1d93;
	case 7576ULL: goto x86_l_1d98;
	case 7579ULL: goto x86_l_1d9b;
	case 7585ULL: goto x86_l_1da1;
	case 7590ULL: goto x86_l_1da6;
	case 7593ULL: goto x86_l_1da9;
	case 7598ULL: goto x86_l_1dae;
	case 7607ULL: goto x86_l_1db7;
	case 7616ULL: goto x86_l_1dc0;
	case 7621ULL: goto x86_l_1dc5;
	case 7624ULL: goto x86_l_1dc8;
	case 7629ULL: goto x86_l_1dcd;
	case 7634ULL: goto x86_l_1dd2;
	case 7640ULL: goto x86_l_1dd8;
	case 7645ULL: goto x86_l_1ddd;
	case 7650ULL: goto x86_l_1de2;
	case 7655ULL: goto x86_l_1de7;
	case 7658ULL: goto x86_l_1dea;
	case 7663ULL: goto x86_l_1def;
	case 7668ULL: goto x86_l_1df4;
	case 7673ULL: goto x86_l_1df9;
	case 7678ULL: goto x86_l_1dfe;
	case 7684ULL: goto x86_l_1e04;
	case 7689ULL: goto x86_l_1e09;
	case 7694ULL: goto x86_l_1e0e;
	case 7699ULL: goto x86_l_1e13;
	case 7702ULL: goto x86_l_1e16;
	case 7708ULL: goto x86_l_1e1c;
	case 7714ULL: goto x86_l_1e22;
	case 7719ULL: goto x86_l_1e27;
	case 7722ULL: goto x86_l_1e2a;
	case 7728ULL: goto x86_l_1e30;
	case 7733ULL: goto x86_l_1e35;
	case 7736ULL: goto x86_l_1e38;
	case 7741ULL: goto x86_l_1e3d;
	case 7746ULL: goto x86_l_1e42;
	case 7752ULL: goto x86_l_1e48;
	case 7757ULL: goto x86_l_1e4d;
	case 7762ULL: goto x86_l_1e52;
	case 7767ULL: goto x86_l_1e57;
	case 7770ULL: goto x86_l_1e5a;
	case 7773ULL: goto x86_l_1e5d;
	case 7779ULL: goto x86_l_1e63;
	case 7784ULL: goto x86_l_1e68;
	case 7789ULL: goto x86_l_1e6d;
	case 7794ULL: goto x86_l_1e72;
	case 7799ULL: goto x86_l_1e77;
	case 7805ULL: goto x86_l_1e7d;
	case 7810ULL: goto x86_l_1e82;
	case 7815ULL: goto x86_l_1e87;
	case 7820ULL: goto x86_l_1e8c;
	case 7823ULL: goto x86_l_1e8f;
	case 7826ULL: goto x86_l_1e92;
	case 7832ULL: goto x86_l_1e98;
	case 7837ULL: goto x86_l_1e9d;
	case 7842ULL: goto x86_l_1ea2;
	case 7847ULL: goto x86_l_1ea7;
	case 7852ULL: goto x86_l_1eac;
	case 7858ULL: goto x86_l_1eb2;
	case 7863ULL: goto x86_l_1eb7;
	case 7868ULL: goto x86_l_1ebc;
	case 7873ULL: goto x86_l_1ec1;
	case 7876ULL: goto x86_l_1ec4;
	case 7879ULL: goto x86_l_1ec7;
	case 7885ULL: goto x86_l_1ecd;
	case 7890ULL: goto x86_l_1ed2;
	case 7893ULL: goto x86_l_1ed5;
	case 7898ULL: goto x86_l_1eda;
	case 7903ULL: goto x86_l_1edf;
	case 7906ULL: goto x86_l_1ee2;
	case 7910ULL: goto x86_l_1ee6;
	case 7916ULL: goto x86_l_1eec;
	case 7918ULL: goto x86_l_1eee;
	case 7921ULL: goto x86_l_1ef1;
	case 7926ULL: goto x86_l_1ef6;
	case 7936ULL: goto x86_l_1f00;
	case 7941ULL: goto x86_l_1f05;
	case 7951ULL: goto x86_l_1f0f;
	case 7956ULL: goto x86_l_1f14;
	case 7966ULL: goto x86_l_1f1e;
	case 7971ULL: goto x86_l_1f23;
	default: return 0xffffffffffffffffULL;
	}
x86_l_16f8:
	/* 0x16f8: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1702:
	/* 0x1702: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1707:
	/* 0x1707: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1711:
	/* 0x1711: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1716:
	/* 0x1716: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1720:
	/* 0x1720: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1725:
	/* 0x1725: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_172f:
	/* 0x172f: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1734:
	/* 0x1734: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1739:
	/* 0x1739: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_173e:
	/* 0x173e: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1743:
	/* 0x1743: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1746:
	/* 0x1746: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_174b:
	/* 0x174b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_174d:
	/* 0x174d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_174f:
	/* 0x174f: jmp    953 <kprobe_unwind_ruby+0x953> */
	return 2387ULL;
x86_l_1754:
	/* 0x1754: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_175b:
	/* 0x175b: jae    1ab4 <kprobe_unwind_ruby+0x1ab4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1ab4;
	}
x86_l_1761:
	/* 0x1761: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1766:
	/* 0x1766: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1769:
	/* 0x1769: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_176f:
	/* 0x176f: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_1774:
	/* 0x1774: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1777:
	/* 0x1777: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_177c:
	/* 0x177c: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1785:
	/* 0x1785: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_178e:
	/* 0x178e: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_1793:
	/* 0x1793: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1796:
	/* 0x1796: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_179b:
	/* 0x179b: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_17a0:
	/* 0x17a0: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_17a6:
	/* 0x17a6: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_17ab:
	/* 0x17ab: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_17b0:
	/* 0x17b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17b5:
	/* 0x17b5: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_17b8:
	/* 0x17b8: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_17bd:
	/* 0x17bd: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_17c2:
	/* 0x17c2: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17c7:
	/* 0x17c7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17cc:
	/* 0x17cc: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_17d2:
	/* 0x17d2: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_17d7:
	/* 0x17d7: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_17dc:
	/* 0x17dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17e1:
	/* 0x17e1: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_17e4:
	/* 0x17e4: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_17ea:
	/* 0x17ea: je     1d86 <kprobe_unwind_ruby+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d86;
	}
x86_l_17f0:
	/* 0x17f0: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17f5:
	/* 0x17f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17f8:
	/* 0x17f8: je     1d86 <kprobe_unwind_ruby+0x1d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d86;
	}
x86_l_17fe:
	/* 0x17fe: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_1803:
	/* 0x1803: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1806:
	/* 0x1806: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_180b:
	/* 0x180b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1810:
	/* 0x1810: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1816:
	/* 0x1816: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_181b:
	/* 0x181b: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1820:
	/* 0x1820: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1825:
	/* 0x1825: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1828:
	/* 0x1828: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_182b:
	/* 0x182b: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_1831:
	/* 0x1831: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_1836:
	/* 0x1836: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_183b:
	/* 0x183b: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1840:
	/* 0x1840: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1845:
	/* 0x1845: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_184b:
	/* 0x184b: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_1850:
	/* 0x1850: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1855:
	/* 0x1855: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_185a:
	/* 0x185a: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_185d:
	/* 0x185d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1860:
	/* 0x1860: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_1866:
	/* 0x1866: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_186b:
	/* 0x186b: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1870:
	/* 0x1870: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1875:
	/* 0x1875: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_187a:
	/* 0x187a: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1880:
	/* 0x1880: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_1885:
	/* 0x1885: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_188a:
	/* 0x188a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_188f:
	/* 0x188f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1892:
	/* 0x1892: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1895:
	/* 0x1895: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_189b:
	/* 0x189b: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18a0:
	/* 0x18a0: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_18a3:
	/* 0x18a3: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_18a8:
	/* 0x18a8: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_18ad:
	/* 0x18ad: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_18b0:
	/* 0x18b0: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_18b4:
	/* 0x18b4: je     29da <kprobe_unwind_ruby+0x29da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10714ULL;
	}
x86_l_18ba:
	/* 0x18ba: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18bc:
	/* 0x18bc: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_18bf:
	/* 0x18bf: jmp    29de <kprobe_unwind_ruby+0x29de> */
	return 10718ULL;
x86_l_18c4:
	/* 0x18c4: movabs rax,0x746e696f70206b63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8389759083181271907ULL);
x86_l_18ce:
	/* 0x18ce: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_18d3:
	/* 0x18d3: movabs rax,0x61747320746e6572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7022364302206985586ULL);
x86_l_18dd:
	/* 0x18dd: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_18e2:
	/* 0x18e2: movabs rax,0x7275632064616572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8247607283373139314ULL);
x86_l_18ec:
	/* 0x18ec: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18f1:
	/* 0x18f1: movabs rax,0x206f742064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414100720745ULL);
x86_l_18fb:
	/* 0x18fb: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1900:
	/* 0x1900: movabs rax,0x6166203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332504820184434ULL);
x86_l_190a:
	/* 0x190a: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_190f:
	/* 0x190f: mov    DWORD PTR [rsp+0x58],0xa7265 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957806693ULL);
x86_l_1917:
	/* 0x1917: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_191c:
	/* 0x191c: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1921:
	/* 0x1921: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1926:
	/* 0x1926: mov    esi,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_192b:
	/* 0x192b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_192d:
	/* 0x192d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_192f:
	/* 0x192f: jmp    539 <kprobe_unwind_ruby+0x539> */
	return 1337ULL;
x86_l_1934:
	/* 0x1934: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1936:
	/* 0x1936: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_1938:
	/* 0x1938: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_193c:
	/* 0x193c: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_193f:
	/* 0x193f: jbe    19cc <kprobe_unwind_ruby+0x19cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_19cc;
	}
x86_l_1945:
	/* 0x1945: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_194c:
	/* 0x194c: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_194f:
	/* 0x194f: je     c29 <kprobe_unwind_ruby+0xc29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3113ULL;
	}
x86_l_1955:
	/* 0x1955: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_195f:
	/* 0x195f: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_1964:
	/* 0x1964: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_196e:
	/* 0x196e: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1973:
	/* 0x1973: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_197d:
	/* 0x197d: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1982:
	/* 0x1982: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_198c:
	/* 0x198c: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1991:
	/* 0x1991: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_199b:
	/* 0x199b: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19a0:
	/* 0x19a0: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_19aa:
	/* 0x19aa: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19af:
	/* 0x19af: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19b4:
	/* 0x19b4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_19b9:
	/* 0x19b9: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_19be:
	/* 0x19be: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_19c3:
	/* 0x19c3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19c5:
	/* 0x19c5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_19c7:
	/* 0x19c7: jmp    c29 <kprobe_unwind_ruby+0xc29> */
	return 3113ULL;
x86_l_19cc:
	/* 0x19cc: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_19d3:
	/* 0x19d3: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_19d7:
	/* 0x19d7: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_19dd:
	/* 0x19dd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19e2:
	/* 0x19e2: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_19e5:
	/* 0x19e5: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_19ec:
	/* 0x19ec: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_19f0:
	/* 0x19f0: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_19f7:
	/* 0x19f7: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19fe:
	/* 0x19fe: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_1a06:
	/* 0x1a06: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_1a0e:
	/* 0x1a0e: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_1a19:
	/* 0x1a19: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a1c:
	/* 0x1a1c: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_1a24:
	/* 0x1a24: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1a29:
	/* 0x1a29: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_1a32:
	/* 0x1a32: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_1a39:
	/* 0x1a39: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_1a40:
	/* 0x1a40: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1a43:
	/* 0x1a43: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a48:
	/* 0x1a48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a4a:
	/* 0x1a4a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a4d:
	/* 0x1a4d: je     1cfc <kprobe_unwind_ruby+0x1cfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cfc;
	}
x86_l_1a53:
	/* 0x1a53: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1a56:
	/* 0x1a56: jmp    c29 <kprobe_unwind_ruby+0xc29> */
	return 3113ULL;
x86_l_1a5b:
	/* 0x1a5b: movabs rax,0xa79646f622071 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2948222039498865ULL);
x86_l_1a65:
	/* 0x1a65: mov    QWORD PTR [rsp+0x47],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_1a6a:
	/* 0x1a6a: movabs rax,0x7165736920746567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8171063994286892391ULL);
x86_l_1a74:
	/* 0x1a74: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a79:
	/* 0x1a79: movabs rax,0x206f742064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414100720745ULL);
x86_l_1a83:
	/* 0x1a83: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a88:
	/* 0x1a88: movabs rax,0x6166203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332504820184434ULL);
x86_l_1a92:
	/* 0x1a92: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a97:
	/* 0x1a97: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a9c:
	/* 0x1a9c: mov    eax,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_1aa1:
	/* 0x1aa1: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1aa6:
	/* 0x1aa6: mov    esi,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 31ULL);
x86_l_1aab:
	/* 0x1aab: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aad:
	/* 0x1aad: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1aaf:
	/* 0x1aaf: jmp    4ce <kprobe_unwind_ruby+0x4ce> */
	return 1230ULL;
x86_l_1ab4:
	/* 0x1ab4: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1abc:
	/* 0x1abc: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_1ac1:
	/* 0x1ac1: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ac6:
	/* 0x1ac6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1ac9:
	/* 0x1ac9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ace:
	/* 0x1ace: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1ad4:
	/* 0x1ad4: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_1ad9:
	/* 0x1ad9: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ade:
	/* 0x1ade: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ae3:
	/* 0x1ae3: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1ae6:
	/* 0x1ae6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ae9:
	/* 0x1ae9: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_1aef:
	/* 0x1aef: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1af2:
	/* 0x1af2: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1af4:
	/* 0x1af4: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_1af9:
	/* 0x1af9: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_1aff:
	/* 0x1aff: jmp    1761 <kprobe_unwind_ruby+0x1761> */
	goto x86_l_1761;
x86_l_1b04:
	/* 0x1b04: movabs rax,0xa657a6973206b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926326196674667ULL);
x86_l_1b0e:
	/* 0x1b0e: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b13:
	/* 0x1b13: movabs rax,0x6361747320746567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7161132920310359399ULL);
x86_l_1b1d:
	/* 0x1b1d: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b22:
	/* 0x1b22: movabs rax,0x206f742064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414100720745ULL);
x86_l_1b2c:
	/* 0x1b2c: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b31:
	/* 0x1b31: movabs rax,0x6166203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332504820184434ULL);
x86_l_1b3b:
	/* 0x1b3b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b40:
	/* 0x1b40: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b45:
	/* 0x1b45: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_1b4a:
	/* 0x1b4a: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1b4f:
	/* 0x1b4f: mov    esi,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32ULL);
x86_l_1b54:
	/* 0x1b54: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b56:
	/* 0x1b56: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b58:
	/* 0x1b58: jmp    722 <kprobe_unwind_ruby+0x722> */
	return 1826ULL;
x86_l_1b5d:
	/* 0x1b5d: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1b67:
	/* 0x1b67: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1b6c:
	/* 0x1b6c: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1b76:
	/* 0x1b76: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b7b:
	/* 0x1b7b: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1b85:
	/* 0x1b85: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b8a:
	/* 0x1b8a: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1b94:
	/* 0x1b94: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b99:
	/* 0x1b99: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1ba3:
	/* 0x1ba3: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ba8:
	/* 0x1ba8: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1bb2:
	/* 0x1bb2: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bb7:
	/* 0x1bb7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bbc:
	/* 0x1bbc: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1bc1:
	/* 0x1bc1: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1bc6:
	/* 0x1bc6: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bca:
	/* 0x1bca: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1bcf:
	/* 0x1bcf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bd1:
	/* 0x1bd1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1bd3:
	/* 0x1bd3: jmp    7d0 <kprobe_unwind_ruby+0x7d0> */
	return 2000ULL;
x86_l_1bd8:
	/* 0x1bd8: movabs rax,0xa706520746567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2938329405613415ULL);
x86_l_1be2:
	/* 0x1be2: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1be7:
	/* 0x1be7: movabs rax,0x206f742064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414100720745ULL);
x86_l_1bf1:
	/* 0x1bf1: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1bf6:
	/* 0x1bf6: movabs rax,0x6166203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332504820184434ULL);
x86_l_1c00:
	/* 0x1c00: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c05:
	/* 0x1c05: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c0a:
	/* 0x1c0a: mov    eax,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_1c0f:
	/* 0x1c0f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1c14:
	/* 0x1c14: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_1c19:
	/* 0x1c19: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c1b:
	/* 0x1c1b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1c1d:
	/* 0x1c1d: jmp    79a <kprobe_unwind_ruby+0x79a> */
	return 1946ULL;
x86_l_1c22:
	/* 0x1c22: movabs rax,0x6465646f636e6520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7234298806012896544ULL);
x86_l_1c2c:
	/* 0x1c2c: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1c31:
	/* 0x1c31: movabs rax,0x7165736920746567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8171063994286892391ULL);
x86_l_1c3b:
	/* 0x1c3b: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c40:
	/* 0x1c40: movabs rax,0x206f742064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414100720745ULL);
x86_l_1c4a:
	/* 0x1c4a: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c4f:
	/* 0x1c4f: movabs rax,0x6166203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332504820184434ULL);
x86_l_1c59:
	/* 0x1c59: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c5e:
	/* 0x1c5e: mov    WORD PTR [rsp+0x50],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 343597383690ULL);
x86_l_1c65:
	/* 0x1c65: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c6a:
	/* 0x1c6a: mov    eax,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_1c6f:
	/* 0x1c6f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1c74:
	/* 0x1c74: mov    esi,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 34ULL);
x86_l_1c79:
	/* 0x1c79: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c7b:
	/* 0x1c7b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1c7d:
	/* 0x1c7d: jmp    823 <kprobe_unwind_ruby+0x823> */
	return 2083ULL;
x86_l_1c82:
	/* 0x1c82: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1c8c:
	/* 0x1c8c: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1c91:
	/* 0x1c91: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1c9b:
	/* 0x1c9b: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ca0:
	/* 0x1ca0: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1caa:
	/* 0x1caa: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1caf:
	/* 0x1caf: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1cb9:
	/* 0x1cb9: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1cbe:
	/* 0x1cbe: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1cc8:
	/* 0x1cc8: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ccd:
	/* 0x1ccd: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1cd7:
	/* 0x1cd7: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cdc:
	/* 0x1cdc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ce1:
	/* 0x1ce1: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1ce6:
	/* 0x1ce6: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1ceb:
	/* 0x1ceb: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cee:
	/* 0x1cee: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1cf3:
	/* 0x1cf3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cf5:
	/* 0x1cf5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1cf7:
	/* 0x1cf7: jmp    856 <kprobe_unwind_ruby+0x856> */
	return 2134ULL;
x86_l_1cfc:
	/* 0x1cfc: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1d03:
	/* 0x1d03: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d06:
	/* 0x1d06: je     c29 <kprobe_unwind_ruby+0xc29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3113ULL;
	}
x86_l_1d0c:
	/* 0x1d0c: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1d16:
	/* 0x1d16: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1d1b:
	/* 0x1d1b: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1d25:
	/* 0x1d25: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d2a:
	/* 0x1d2a: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1d34:
	/* 0x1d34: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d39:
	/* 0x1d39: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1d43:
	/* 0x1d43: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d48:
	/* 0x1d48: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1d52:
	/* 0x1d52: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d57:
	/* 0x1d57: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1d61:
	/* 0x1d61: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d66:
	/* 0x1d66: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d6b:
	/* 0x1d6b: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1d70:
	/* 0x1d70: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1d75:
	/* 0x1d75: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d78:
	/* 0x1d78: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1d7d:
	/* 0x1d7d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d7f:
	/* 0x1d7f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1d81:
	/* 0x1d81: jmp    c29 <kprobe_unwind_ruby+0xc29> */
	return 3113ULL;
x86_l_1d86:
	/* 0x1d86: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_1d8d:
	/* 0x1d8d: jae    2235 <kprobe_unwind_ruby+0x2235> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8757ULL;
	}
x86_l_1d93:
	/* 0x1d93: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d98:
	/* 0x1d98: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1d9b:
	/* 0x1d9b: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_1da1:
	/* 0x1da1: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_1da6:
	/* 0x1da6: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1da9:
	/* 0x1da9: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dae:
	/* 0x1dae: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1db7:
	/* 0x1db7: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1dc0:
	/* 0x1dc0: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_1dc5:
	/* 0x1dc5: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1dc8:
	/* 0x1dc8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dcd:
	/* 0x1dcd: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1dd2:
	/* 0x1dd2: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1dd8:
	/* 0x1dd8: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_1ddd:
	/* 0x1ddd: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1de2:
	/* 0x1de2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1de7:
	/* 0x1de7: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1dea:
	/* 0x1dea: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_1def:
	/* 0x1def: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1df4:
	/* 0x1df4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1df9:
	/* 0x1df9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1dfe:
	/* 0x1dfe: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1e04:
	/* 0x1e04: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_1e09:
	/* 0x1e09: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1e0e:
	/* 0x1e0e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e13:
	/* 0x1e13: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1e16:
	/* 0x1e16: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1e1c:
	/* 0x1e1c: je     2404 <kprobe_unwind_ruby+0x2404> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9220ULL;
	}
x86_l_1e22:
	/* 0x1e22: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e27:
	/* 0x1e27: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e2a:
	/* 0x1e2a: je     2404 <kprobe_unwind_ruby+0x2404> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9220ULL;
	}
x86_l_1e30:
	/* 0x1e30: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_1e35:
	/* 0x1e35: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e38:
	/* 0x1e38: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e3d:
	/* 0x1e3d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e42:
	/* 0x1e42: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1e48:
	/* 0x1e48: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_1e4d:
	/* 0x1e4d: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1e52:
	/* 0x1e52: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e57:
	/* 0x1e57: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1e5a:
	/* 0x1e5a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e5d:
	/* 0x1e5d: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_1e63:
	/* 0x1e63: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_1e68:
	/* 0x1e68: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1e6d:
	/* 0x1e6d: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1e72:
	/* 0x1e72: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e77:
	/* 0x1e77: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1e7d:
	/* 0x1e7d: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_1e82:
	/* 0x1e82: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1e87:
	/* 0x1e87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e8c:
	/* 0x1e8c: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1e8f:
	/* 0x1e8f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e92:
	/* 0x1e92: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_1e98:
	/* 0x1e98: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_1e9d:
	/* 0x1e9d: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1ea2:
	/* 0x1ea2: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1ea7:
	/* 0x1ea7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1eac:
	/* 0x1eac: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1eb2:
	/* 0x1eb2: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_1eb7:
	/* 0x1eb7: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1ebc:
	/* 0x1ebc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ec1:
	/* 0x1ec1: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1ec4:
	/* 0x1ec4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ec7:
	/* 0x1ec7: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_1ecd:
	/* 0x1ecd: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ed2:
	/* 0x1ed2: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_1ed5:
	/* 0x1ed5: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_1eda:
	/* 0x1eda: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_1edf:
	/* 0x1edf: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1ee2:
	/* 0x1ee2: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1ee6:
	/* 0x1ee6: je     2d47 <kprobe_unwind_ruby+0x2d47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11591ULL;
	}
x86_l_1eec:
	/* 0x1eec: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1eee:
	/* 0x1eee: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1ef1:
	/* 0x1ef1: jmp    2d4b <kprobe_unwind_ruby+0x2d4b> */
	return 11595ULL;
x86_l_1ef6:
	/* 0x1ef6: movabs rax,0xa70666320746567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 752213713703167335ULL);
x86_l_1f00:
	/* 0x1f00: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f05:
	/* 0x1f05: movabs rax,0x206f742064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414100720745ULL);
x86_l_1f0f:
	/* 0x1f0f: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f14:
	/* 0x1f14: movabs rax,0x6166203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332504820184434ULL);
x86_l_1f1e:
	/* 0x1f1e: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f23:
	/* 0x1f23: mov    BYTE PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
	return 7976ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7976ULL: goto x86_l_1f28;
	case 7981ULL: goto x86_l_1f2d;
	case 7986ULL: goto x86_l_1f32;
	case 7991ULL: goto x86_l_1f37;
	case 7996ULL: goto x86_l_1f3c;
	case 7998ULL: goto x86_l_1f3e;
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
	case 8090ULL: goto x86_l_1f9a;
	case 8095ULL: goto x86_l_1f9f;
	case 8100ULL: goto x86_l_1fa4;
	case 8105ULL: goto x86_l_1fa9;
	case 8110ULL: goto x86_l_1fae;
	case 8114ULL: goto x86_l_1fb2;
	case 8119ULL: goto x86_l_1fb7;
	case 8121ULL: goto x86_l_1fb9;
	case 8123ULL: goto x86_l_1fbb;
	case 8128ULL: goto x86_l_1fc0;
	case 8130ULL: goto x86_l_1fc2;
	case 8132ULL: goto x86_l_1fc4;
	case 8136ULL: goto x86_l_1fc8;
	case 8139ULL: goto x86_l_1fcb;
	case 8145ULL: goto x86_l_1fd1;
	case 8152ULL: goto x86_l_1fd8;
	case 8155ULL: goto x86_l_1fdb;
	case 8161ULL: goto x86_l_1fe1;
	case 8171ULL: goto x86_l_1feb;
	case 8176ULL: goto x86_l_1ff0;
	case 8186ULL: goto x86_l_1ffa;
	case 8191ULL: goto x86_l_1fff;
	case 8201ULL: goto x86_l_2009;
	case 8206ULL: goto x86_l_200e;
	case 8216ULL: goto x86_l_2018;
	case 8221ULL: goto x86_l_201d;
	case 8231ULL: goto x86_l_2027;
	case 8236ULL: goto x86_l_202c;
	case 8246ULL: goto x86_l_2036;
	case 8251ULL: goto x86_l_203b;
	case 8256ULL: goto x86_l_2040;
	case 8261ULL: goto x86_l_2045;
	case 8266ULL: goto x86_l_204a;
	case 8271ULL: goto x86_l_204f;
	case 8273ULL: goto x86_l_2051;
	case 8275ULL: goto x86_l_2053;
	case 8280ULL: goto x86_l_2058;
	case 8287ULL: goto x86_l_205f;
	case 8291ULL: goto x86_l_2063;
	case 8297ULL: goto x86_l_2069;
	case 8302ULL: goto x86_l_206e;
	case 8305ULL: goto x86_l_2071;
	case 8312ULL: goto x86_l_2078;
	case 8316ULL: goto x86_l_207c;
	case 8323ULL: goto x86_l_2083;
	case 8330ULL: goto x86_l_208a;
	case 8338ULL: goto x86_l_2092;
	case 8346ULL: goto x86_l_209a;
	case 8357ULL: goto x86_l_20a5;
	case 8360ULL: goto x86_l_20a8;
	case 8368ULL: goto x86_l_20b0;
	case 8373ULL: goto x86_l_20b5;
	case 8382ULL: goto x86_l_20be;
	case 8389ULL: goto x86_l_20c5;
	case 8396ULL: goto x86_l_20cc;
	case 8399ULL: goto x86_l_20cf;
	case 8404ULL: goto x86_l_20d4;
	case 8406ULL: goto x86_l_20d6;
	case 8409ULL: goto x86_l_20d9;
	case 8415ULL: goto x86_l_20df;
	case 8418ULL: goto x86_l_20e2;
	case 8423ULL: goto x86_l_20e7;
	case 8433ULL: goto x86_l_20f1;
	case 8438ULL: goto x86_l_20f6;
	case 8448ULL: goto x86_l_2100;
	case 8453ULL: goto x86_l_2105;
	case 8463ULL: goto x86_l_210f;
	case 8468ULL: goto x86_l_2114;
	case 8478ULL: goto x86_l_211e;
	case 8483ULL: goto x86_l_2123;
	case 8493ULL: goto x86_l_212d;
	case 8498ULL: goto x86_l_2132;
	case 8508ULL: goto x86_l_213c;
	case 8513ULL: goto x86_l_2141;
	case 8518ULL: goto x86_l_2146;
	case 8523ULL: goto x86_l_214b;
	case 8528ULL: goto x86_l_2150;
	case 8532ULL: goto x86_l_2154;
	case 8537ULL: goto x86_l_2159;
	case 8539ULL: goto x86_l_215b;
	case 8541ULL: goto x86_l_215d;
	case 8546ULL: goto x86_l_2162;
	case 8556ULL: goto x86_l_216c;
	case 8561ULL: goto x86_l_2171;
	case 8571ULL: goto x86_l_217b;
	case 8576ULL: goto x86_l_2180;
	case 8586ULL: goto x86_l_218a;
	case 8591ULL: goto x86_l_218f;
	case 8601ULL: goto x86_l_2199;
	case 8606ULL: goto x86_l_219e;
	case 8611ULL: goto x86_l_21a3;
	case 8616ULL: goto x86_l_21a8;
	case 8621ULL: goto x86_l_21ad;
	case 8626ULL: goto x86_l_21b2;
	case 8628ULL: goto x86_l_21b4;
	case 8630ULL: goto x86_l_21b6;
	case 8635ULL: goto x86_l_21bb;
	case 8645ULL: goto x86_l_21c5;
	case 8650ULL: goto x86_l_21ca;
	case 8660ULL: goto x86_l_21d4;
	case 8665ULL: goto x86_l_21d9;
	case 8675ULL: goto x86_l_21e3;
	case 8680ULL: goto x86_l_21e8;
	case 8690ULL: goto x86_l_21f2;
	case 8695ULL: goto x86_l_21f7;
	case 8705ULL: goto x86_l_2201;
	case 8710ULL: goto x86_l_2206;
	case 8720ULL: goto x86_l_2210;
	case 8725ULL: goto x86_l_2215;
	case 8730ULL: goto x86_l_221a;
	case 8735ULL: goto x86_l_221f;
	case 8740ULL: goto x86_l_2224;
	case 8743ULL: goto x86_l_2227;
	case 8748ULL: goto x86_l_222c;
	case 8750ULL: goto x86_l_222e;
	case 8752ULL: goto x86_l_2230;
	case 8757ULL: goto x86_l_2235;
	case 8765ULL: goto x86_l_223d;
	case 8770ULL: goto x86_l_2242;
	case 8775ULL: goto x86_l_2247;
	case 8778ULL: goto x86_l_224a;
	case 8783ULL: goto x86_l_224f;
	case 8789ULL: goto x86_l_2255;
	case 8794ULL: goto x86_l_225a;
	case 8799ULL: goto x86_l_225f;
	case 8804ULL: goto x86_l_2264;
	case 8807ULL: goto x86_l_2267;
	case 8810ULL: goto x86_l_226a;
	case 8816ULL: goto x86_l_2270;
	case 8819ULL: goto x86_l_2273;
	case 8821ULL: goto x86_l_2275;
	case 8826ULL: goto x86_l_227a;
	case 8832ULL: goto x86_l_2280;
	case 8837ULL: goto x86_l_2285;
	case 8847ULL: goto x86_l_228f;
	case 8852ULL: goto x86_l_2294;
	case 8862ULL: goto x86_l_229e;
	case 8867ULL: goto x86_l_22a3;
	case 8877ULL: goto x86_l_22ad;
	case 8882ULL: goto x86_l_22b2;
	case 8892ULL: goto x86_l_22bc;
	case 8897ULL: goto x86_l_22c1;
	case 8907ULL: goto x86_l_22cb;
	case 8912ULL: goto x86_l_22d0;
	case 8922ULL: goto x86_l_22da;
	case 8927ULL: goto x86_l_22df;
	case 8932ULL: goto x86_l_22e4;
	case 8937ULL: goto x86_l_22e9;
	case 8942ULL: goto x86_l_22ee;
	case 8946ULL: goto x86_l_22f2;
	case 8951ULL: goto x86_l_22f7;
	case 8953ULL: goto x86_l_22f9;
	case 8955ULL: goto x86_l_22fb;
	case 8960ULL: goto x86_l_2300;
	case 8967ULL: goto x86_l_2307;
	case 8970ULL: goto x86_l_230a;
	case 8976ULL: goto x86_l_2310;
	case 8986ULL: goto x86_l_231a;
	case 8991ULL: goto x86_l_231f;
	case 9001ULL: goto x86_l_2329;
	case 9006ULL: goto x86_l_232e;
	case 9016ULL: goto x86_l_2338;
	case 9021ULL: goto x86_l_233d;
	case 9031ULL: goto x86_l_2347;
	case 9036ULL: goto x86_l_234c;
	case 9046ULL: goto x86_l_2356;
	case 9051ULL: goto x86_l_235b;
	case 9061ULL: goto x86_l_2365;
	case 9066ULL: goto x86_l_236a;
	case 9071ULL: goto x86_l_236f;
	case 9076ULL: goto x86_l_2374;
	case 9081ULL: goto x86_l_2379;
	case 9084ULL: goto x86_l_237c;
	case 9089ULL: goto x86_l_2381;
	case 9091ULL: goto x86_l_2383;
	case 9093ULL: goto x86_l_2385;
	case 9098ULL: goto x86_l_238a;
	case 9108ULL: goto x86_l_2394;
	case 9113ULL: goto x86_l_2399;
	case 9123ULL: goto x86_l_23a3;
	case 9128ULL: goto x86_l_23a8;
	case 9138ULL: goto x86_l_23b2;
	case 9143ULL: goto x86_l_23b7;
	case 9153ULL: goto x86_l_23c1;
	case 9158ULL: goto x86_l_23c6;
	case 9168ULL: goto x86_l_23d0;
	case 9173ULL: goto x86_l_23d5;
	case 9183ULL: goto x86_l_23df;
	case 9188ULL: goto x86_l_23e4;
	case 9193ULL: goto x86_l_23e9;
	case 9198ULL: goto x86_l_23ee;
	case 9203ULL: goto x86_l_23f3;
	case 9206ULL: goto x86_l_23f6;
	case 9211ULL: goto x86_l_23fb;
	case 9213ULL: goto x86_l_23fd;
	case 9215ULL: goto x86_l_23ff;
	case 9220ULL: goto x86_l_2404;
	case 9227ULL: goto x86_l_240b;
	case 9233ULL: goto x86_l_2411;
	case 9238ULL: goto x86_l_2416;
	case 9241ULL: goto x86_l_2419;
	case 9247ULL: goto x86_l_241f;
	case 9252ULL: goto x86_l_2424;
	case 9255ULL: goto x86_l_2427;
	case 9260ULL: goto x86_l_242c;
	case 9269ULL: goto x86_l_2435;
	case 9278ULL: goto x86_l_243e;
	case 9283ULL: goto x86_l_2443;
	case 9286ULL: goto x86_l_2446;
	case 9291ULL: goto x86_l_244b;
	case 9296ULL: goto x86_l_2450;
	case 9302ULL: goto x86_l_2456;
	case 9307ULL: goto x86_l_245b;
	case 9312ULL: goto x86_l_2460;
	case 9317ULL: goto x86_l_2465;
	case 9320ULL: goto x86_l_2468;
	case 9325ULL: goto x86_l_246d;
	case 9330ULL: goto x86_l_2472;
	case 9335ULL: goto x86_l_2477;
	case 9340ULL: goto x86_l_247c;
	case 9346ULL: goto x86_l_2482;
	case 9351ULL: goto x86_l_2487;
	case 9356ULL: goto x86_l_248c;
	case 9361ULL: goto x86_l_2491;
	case 9364ULL: goto x86_l_2494;
	case 9370ULL: goto x86_l_249a;
	case 9376ULL: goto x86_l_24a0;
	case 9381ULL: goto x86_l_24a5;
	case 9384ULL: goto x86_l_24a8;
	case 9390ULL: goto x86_l_24ae;
	case 9395ULL: goto x86_l_24b3;
	case 9398ULL: goto x86_l_24b6;
	case 9403ULL: goto x86_l_24bb;
	case 9408ULL: goto x86_l_24c0;
	case 9414ULL: goto x86_l_24c6;
	case 9419ULL: goto x86_l_24cb;
	case 9424ULL: goto x86_l_24d0;
	case 9429ULL: goto x86_l_24d5;
	case 9432ULL: goto x86_l_24d8;
	case 9435ULL: goto x86_l_24db;
	case 9441ULL: goto x86_l_24e1;
	case 9446ULL: goto x86_l_24e6;
	case 9451ULL: goto x86_l_24eb;
	case 9456ULL: goto x86_l_24f0;
	case 9461ULL: goto x86_l_24f5;
	case 9467ULL: goto x86_l_24fb;
	case 9472ULL: goto x86_l_2500;
	case 9477ULL: goto x86_l_2505;
	case 9482ULL: goto x86_l_250a;
	case 9485ULL: goto x86_l_250d;
	case 9488ULL: goto x86_l_2510;
	case 9494ULL: goto x86_l_2516;
	case 9499ULL: goto x86_l_251b;
	case 9504ULL: goto x86_l_2520;
	case 9509ULL: goto x86_l_2525;
	case 9514ULL: goto x86_l_252a;
	case 9520ULL: goto x86_l_2530;
	case 9525ULL: goto x86_l_2535;
	case 9530ULL: goto x86_l_253a;
	case 9535ULL: goto x86_l_253f;
	case 9538ULL: goto x86_l_2542;
	case 9541ULL: goto x86_l_2545;
	case 9547ULL: goto x86_l_254b;
	case 9552ULL: goto x86_l_2550;
	case 9555ULL: goto x86_l_2553;
	case 9560ULL: goto x86_l_2558;
	case 9565ULL: goto x86_l_255d;
	case 9568ULL: goto x86_l_2560;
	case 9572ULL: goto x86_l_2564;
	case 9578ULL: goto x86_l_256a;
	case 9580ULL: goto x86_l_256c;
	case 9583ULL: goto x86_l_256f;
	case 9588ULL: goto x86_l_2574;
	case 9590ULL: goto x86_l_2576;
	case 9592ULL: goto x86_l_2578;
	case 9596ULL: goto x86_l_257c;
	case 9599ULL: goto x86_l_257f;
	case 9605ULL: goto x86_l_2585;
	case 9612ULL: goto x86_l_258c;
	case 9615ULL: goto x86_l_258f;
	case 9621ULL: goto x86_l_2595;
	case 9631ULL: goto x86_l_259f;
	case 9636ULL: goto x86_l_25a4;
	case 9646ULL: goto x86_l_25ae;
	case 9651ULL: goto x86_l_25b3;
	case 9661ULL: goto x86_l_25bd;
	case 9666ULL: goto x86_l_25c2;
	case 9676ULL: goto x86_l_25cc;
	case 9681ULL: goto x86_l_25d1;
	case 9691ULL: goto x86_l_25db;
	case 9696ULL: goto x86_l_25e0;
	case 9706ULL: goto x86_l_25ea;
	case 9711ULL: goto x86_l_25ef;
	case 9716ULL: goto x86_l_25f4;
	case 9721ULL: goto x86_l_25f9;
	case 9726ULL: goto x86_l_25fe;
	case 9731ULL: goto x86_l_2603;
	case 9733ULL: goto x86_l_2605;
	case 9735ULL: goto x86_l_2607;
	case 9740ULL: goto x86_l_260c;
	case 9747ULL: goto x86_l_2613;
	case 9751ULL: goto x86_l_2617;
	case 9757ULL: goto x86_l_261d;
	case 9762ULL: goto x86_l_2622;
	case 9765ULL: goto x86_l_2625;
	case 9772ULL: goto x86_l_262c;
	case 9776ULL: goto x86_l_2630;
	case 9783ULL: goto x86_l_2637;
	case 9790ULL: goto x86_l_263e;
	case 9798ULL: goto x86_l_2646;
	case 9806ULL: goto x86_l_264e;
	case 9817ULL: goto x86_l_2659;
	case 9820ULL: goto x86_l_265c;
	case 9828ULL: goto x86_l_2664;
	case 9833ULL: goto x86_l_2669;
	case 9842ULL: goto x86_l_2672;
	case 9849ULL: goto x86_l_2679;
	case 9856ULL: goto x86_l_2680;
	case 9859ULL: goto x86_l_2683;
	case 9864ULL: goto x86_l_2688;
	case 9866ULL: goto x86_l_268a;
	case 9869ULL: goto x86_l_268d;
	case 9875ULL: goto x86_l_2693;
	case 9878ULL: goto x86_l_2696;
	case 9883ULL: goto x86_l_269b;
	case 9891ULL: goto x86_l_26a3;
	case 9896ULL: goto x86_l_26a8;
	case 9901ULL: goto x86_l_26ad;
	case 9904ULL: goto x86_l_26b0;
	case 9909ULL: goto x86_l_26b5;
	case 9915ULL: goto x86_l_26bb;
	case 9920ULL: goto x86_l_26c0;
	case 9925ULL: goto x86_l_26c5;
	case 9930ULL: goto x86_l_26ca;
	case 9933ULL: goto x86_l_26cd;
	case 9936ULL: goto x86_l_26d0;
	case 9942ULL: goto x86_l_26d6;
	case 9945ULL: goto x86_l_26d9;
	case 9947ULL: goto x86_l_26db;
	case 9952ULL: goto x86_l_26e0;
	case 9958ULL: goto x86_l_26e6;
	case 9963ULL: goto x86_l_26eb;
	case 9973ULL: goto x86_l_26f5;
	case 9978ULL: goto x86_l_26fa;
	case 9988ULL: goto x86_l_2704;
	case 9993ULL: goto x86_l_2709;
	case 10003ULL: goto x86_l_2713;
	case 10008ULL: goto x86_l_2718;
	case 10018ULL: goto x86_l_2722;
	case 10023ULL: goto x86_l_2727;
	case 10033ULL: goto x86_l_2731;
	case 10038ULL: goto x86_l_2736;
	case 10043ULL: goto x86_l_273b;
	case 10048ULL: goto x86_l_2740;
	case 10053ULL: goto x86_l_2745;
	case 10058ULL: goto x86_l_274a;
	case 10060ULL: goto x86_l_274c;
	case 10062ULL: goto x86_l_274e;
	case 10067ULL: goto x86_l_2753;
	case 10074ULL: goto x86_l_275a;
	case 10077ULL: goto x86_l_275d;
	case 10083ULL: goto x86_l_2763;
	case 10093ULL: goto x86_l_276d;
	case 10098ULL: goto x86_l_2772;
	case 10108ULL: goto x86_l_277c;
	case 10113ULL: goto x86_l_2781;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1f28:
	/* 0x1f28: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f2d:
	/* 0x1f2d: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1f32:
	/* 0x1f32: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1f37:
	/* 0x1f37: mov    esi,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_1f3c:
	/* 0x1f3c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f3e:
	/* 0x1f3e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1f40:
	/* 0x1f40: jmp    8c9 <kprobe_unwind_ruby+0x8c9> */
	return 2249ULL;
x86_l_1f45:
	/* 0x1f45: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1f4f:
	/* 0x1f4f: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1f54:
	/* 0x1f54: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1f5e:
	/* 0x1f5e: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f63:
	/* 0x1f63: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1f6d:
	/* 0x1f6d: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1f72:
	/* 0x1f72: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1f7c:
	/* 0x1f7c: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f81:
	/* 0x1f81: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1f8b:
	/* 0x1f8b: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f90:
	/* 0x1f90: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1f9a:
	/* 0x1f9a: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f9f:
	/* 0x1f9f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fa4:
	/* 0x1fa4: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1fa9:
	/* 0x1fa9: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1fae:
	/* 0x1fae: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fb2:
	/* 0x1fb2: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1fb7:
	/* 0x1fb7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fb9:
	/* 0x1fb9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1fbb:
	/* 0x1fbb: jmp    939 <kprobe_unwind_ruby+0x939> */
	return 2361ULL;
x86_l_1fc0:
	/* 0x1fc0: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fc2:
	/* 0x1fc2: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_1fc4:
	/* 0x1fc4: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1fc8:
	/* 0x1fc8: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1fcb:
	/* 0x1fcb: jbe    2058 <kprobe_unwind_ruby+0x2058> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2058;
	}
x86_l_1fd1:
	/* 0x1fd1: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1fd8:
	/* 0x1fd8: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fdb:
	/* 0x1fdb: je     10fb <kprobe_unwind_ruby+0x10fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4347ULL;
	}
x86_l_1fe1:
	/* 0x1fe1: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_1feb:
	/* 0x1feb: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_1ff0:
	/* 0x1ff0: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_1ffa:
	/* 0x1ffa: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1fff:
	/* 0x1fff: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_2009:
	/* 0x2009: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_200e:
	/* 0x200e: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_2018:
	/* 0x2018: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_201d:
	/* 0x201d: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_2027:
	/* 0x2027: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_202c:
	/* 0x202c: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_2036:
	/* 0x2036: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_203b:
	/* 0x203b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2040:
	/* 0x2040: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2045:
	/* 0x2045: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_204a:
	/* 0x204a: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_204f:
	/* 0x204f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2051:
	/* 0x2051: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2053:
	/* 0x2053: jmp    10fb <kprobe_unwind_ruby+0x10fb> */
	return 4347ULL;
x86_l_2058:
	/* 0x2058: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_205f:
	/* 0x205f: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_2063:
	/* 0x2063: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_2069:
	/* 0x2069: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_206e:
	/* 0x206e: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2071:
	/* 0x2071: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_2078:
	/* 0x2078: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_207c:
	/* 0x207c: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_2083:
	/* 0x2083: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_208a:
	/* 0x208a: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_2092:
	/* 0x2092: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_209a:
	/* 0x209a: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_20a5:
	/* 0x20a5: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20a8:
	/* 0x20a8: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_20b0:
	/* 0x20b0: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_20b5:
	/* 0x20b5: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_20be:
	/* 0x20be: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_20c5:
	/* 0x20c5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_20cc:
	/* 0x20cc: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_20cf:
	/* 0x20cf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20d4:
	/* 0x20d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20d6:
	/* 0x20d6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20d9:
	/* 0x20d9: je     2300 <kprobe_unwind_ruby+0x2300> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2300;
	}
x86_l_20df:
	/* 0x20df: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_20e2:
	/* 0x20e2: jmp    10fb <kprobe_unwind_ruby+0x10fb> */
	return 4347ULL;
x86_l_20e7:
	/* 0x20e7: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_20f1:
	/* 0x20f1: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_20f6:
	/* 0x20f6: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_2100:
	/* 0x2100: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2105:
	/* 0x2105: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_210f:
	/* 0x210f: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2114:
	/* 0x2114: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_211e:
	/* 0x211e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2123:
	/* 0x2123: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_212d:
	/* 0x212d: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2132:
	/* 0x2132: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_213c:
	/* 0x213c: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2141:
	/* 0x2141: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2146:
	/* 0x2146: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_214b:
	/* 0x214b: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2150:
	/* 0x2150: mov    edx,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_2154:
	/* 0x2154: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2159:
	/* 0x2159: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_215b:
	/* 0x215b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_215d:
	/* 0x215d: jmp    b2e <kprobe_unwind_ruby+0xb2e> */
	return 2862ULL;
x86_l_2162:
	/* 0x2162: movabs rax,0xa657a69732071 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926326196674673ULL);
x86_l_216c:
	/* 0x216c: mov    QWORD PTR [rsp+0x47],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_2171:
	/* 0x2171: movabs rax,0x7165736920746567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8171063994286892391ULL);
x86_l_217b:
	/* 0x217b: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2180:
	/* 0x2180: movabs rax,0x206f742064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414100720745ULL);
x86_l_218a:
	/* 0x218a: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_218f:
	/* 0x218f: movabs rax,0x6166203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332504820184434ULL);
x86_l_2199:
	/* 0x2199: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_219e:
	/* 0x219e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21a3:
	/* 0x21a3: mov    eax,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_21a8:
	/* 0x21a8: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_21ad:
	/* 0x21ad: mov    esi,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 31ULL);
x86_l_21b2:
	/* 0x21b2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21b4:
	/* 0x21b4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_21b6:
	/* 0x21b6: jmp    afb <kprobe_unwind_ruby+0xafb> */
	return 2811ULL;
x86_l_21bb:
	/* 0x21bb: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_21c5:
	/* 0x21c5: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_21ca:
	/* 0x21ca: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_21d4:
	/* 0x21d4: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_21d9:
	/* 0x21d9: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_21e3:
	/* 0x21e3: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_21e8:
	/* 0x21e8: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_21f2:
	/* 0x21f2: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_21f7:
	/* 0x21f7: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2201:
	/* 0x2201: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2206:
	/* 0x2206: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2210:
	/* 0x2210: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2215:
	/* 0x2215: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_221a:
	/* 0x221a: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_221f:
	/* 0x221f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2224:
	/* 0x2224: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2227:
	/* 0x2227: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_222c:
	/* 0x222c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_222e:
	/* 0x222e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2230:
	/* 0x2230: jmp    b45 <kprobe_unwind_ruby+0xb45> */
	return 2885ULL;
x86_l_2235:
	/* 0x2235: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_223d:
	/* 0x223d: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_2242:
	/* 0x2242: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2247:
	/* 0x2247: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_224a:
	/* 0x224a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_224f:
	/* 0x224f: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2255:
	/* 0x2255: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_225a:
	/* 0x225a: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_225f:
	/* 0x225f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2264:
	/* 0x2264: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2267:
	/* 0x2267: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_226a:
	/* 0x226a: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_2270:
	/* 0x2270: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2273:
	/* 0x2273: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2275:
	/* 0x2275: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_227a:
	/* 0x227a: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_2280:
	/* 0x2280: jmp    1d93 <kprobe_unwind_ruby+0x1d93> */
	return 7571ULL;
x86_l_2285:
	/* 0x2285: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_228f:
	/* 0x228f: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2294:
	/* 0x2294: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_229e:
	/* 0x229e: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_22a3:
	/* 0x22a3: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_22ad:
	/* 0x22ad: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_22b2:
	/* 0x22b2: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_22bc:
	/* 0x22bc: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_22c1:
	/* 0x22c1: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_22cb:
	/* 0x22cb: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_22d0:
	/* 0x22d0: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_22da:
	/* 0x22da: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22df:
	/* 0x22df: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22e4:
	/* 0x22e4: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_22e9:
	/* 0x22e9: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_22ee:
	/* 0x22ee: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22f2:
	/* 0x22f2: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_22f7:
	/* 0x22f7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22f9:
	/* 0x22f9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_22fb:
	/* 0x22fb: jmp    bcf <kprobe_unwind_ruby+0xbcf> */
	return 3023ULL;
x86_l_2300:
	/* 0x2300: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2307:
	/* 0x2307: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_230a:
	/* 0x230a: je     10fb <kprobe_unwind_ruby+0x10fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4347ULL;
	}
x86_l_2310:
	/* 0x2310: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_231a:
	/* 0x231a: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_231f:
	/* 0x231f: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_2329:
	/* 0x2329: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_232e:
	/* 0x232e: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_2338:
	/* 0x2338: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_233d:
	/* 0x233d: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_2347:
	/* 0x2347: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_234c:
	/* 0x234c: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2356:
	/* 0x2356: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_235b:
	/* 0x235b: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2365:
	/* 0x2365: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_236a:
	/* 0x236a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_236f:
	/* 0x236f: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2374:
	/* 0x2374: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2379:
	/* 0x2379: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_237c:
	/* 0x237c: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2381:
	/* 0x2381: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2383:
	/* 0x2383: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2385:
	/* 0x2385: jmp    10fb <kprobe_unwind_ruby+0x10fb> */
	return 4347ULL;
x86_l_238a:
	/* 0x238a: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_2394:
	/* 0x2394: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2399:
	/* 0x2399: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_23a3:
	/* 0x23a3: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_23a8:
	/* 0x23a8: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_23b2:
	/* 0x23b2: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_23b7:
	/* 0x23b7: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_23c1:
	/* 0x23c1: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_23c6:
	/* 0x23c6: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_23d0:
	/* 0x23d0: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_23d5:
	/* 0x23d5: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_23df:
	/* 0x23df: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23e4:
	/* 0x23e4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23e9:
	/* 0x23e9: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_23ee:
	/* 0x23ee: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_23f3:
	/* 0x23f3: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23f6:
	/* 0x23f6: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_23fb:
	/* 0x23fb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23fd:
	/* 0x23fd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_23ff:
	/* 0x23ff: jmp    c0f <kprobe_unwind_ruby+0xc0f> */
	return 3087ULL;
x86_l_2404:
	/* 0x2404: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_240b:
	/* 0x240b: jae    269b <kprobe_unwind_ruby+0x269b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_269b;
	}
x86_l_2411:
	/* 0x2411: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2416:
	/* 0x2416: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2419:
	/* 0x2419: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_241f:
	/* 0x241f: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_2424:
	/* 0x2424: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2427:
	/* 0x2427: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_242c:
	/* 0x242c: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2435:
	/* 0x2435: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_243e:
	/* 0x243e: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_2443:
	/* 0x2443: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2446:
	/* 0x2446: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_244b:
	/* 0x244b: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_2450:
	/* 0x2450: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2456:
	/* 0x2456: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_245b:
	/* 0x245b: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2460:
	/* 0x2460: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2465:
	/* 0x2465: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2468:
	/* 0x2468: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_246d:
	/* 0x246d: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2472:
	/* 0x2472: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2477:
	/* 0x2477: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_247c:
	/* 0x247c: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2482:
	/* 0x2482: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_2487:
	/* 0x2487: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_248c:
	/* 0x248c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2491:
	/* 0x2491: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2494:
	/* 0x2494: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_249a:
	/* 0x249a: je     286a <kprobe_unwind_ruby+0x286a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10346ULL;
	}
x86_l_24a0:
	/* 0x24a0: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24a5:
	/* 0x24a5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24a8:
	/* 0x24a8: je     286a <kprobe_unwind_ruby+0x286a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10346ULL;
	}
x86_l_24ae:
	/* 0x24ae: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_24b3:
	/* 0x24b3: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_24b6:
	/* 0x24b6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24bb:
	/* 0x24bb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_24c0:
	/* 0x24c0: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_24c6:
	/* 0x24c6: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_24cb:
	/* 0x24cb: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_24d0:
	/* 0x24d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24d5:
	/* 0x24d5: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_24d8:
	/* 0x24d8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24db:
	/* 0x24db: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_24e1:
	/* 0x24e1: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_24e6:
	/* 0x24e6: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_24eb:
	/* 0x24eb: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_24f0:
	/* 0x24f0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_24f5:
	/* 0x24f5: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_24fb:
	/* 0x24fb: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_2500:
	/* 0x2500: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2505:
	/* 0x2505: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_250a:
	/* 0x250a: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_250d:
	/* 0x250d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2510:
	/* 0x2510: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_2516:
	/* 0x2516: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_251b:
	/* 0x251b: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2520:
	/* 0x2520: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2525:
	/* 0x2525: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_252a:
	/* 0x252a: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2530:
	/* 0x2530: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_2535:
	/* 0x2535: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_253a:
	/* 0x253a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_253f:
	/* 0x253f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2542:
	/* 0x2542: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2545:
	/* 0x2545: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_254b:
	/* 0x254b: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2550:
	/* 0x2550: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_2553:
	/* 0x2553: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_2558:
	/* 0x2558: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_255d:
	/* 0x255d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2560:
	/* 0x2560: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2564:
	/* 0x2564: je     30b4 <kprobe_unwind_ruby+0x30b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12468ULL;
	}
x86_l_256a:
	/* 0x256a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_256c:
	/* 0x256c: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_256f:
	/* 0x256f: jmp    30b8 <kprobe_unwind_ruby+0x30b8> */
	return 12472ULL;
x86_l_2574:
	/* 0x2574: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2576:
	/* 0x2576: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_2578:
	/* 0x2578: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_257c:
	/* 0x257c: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_257f:
	/* 0x257f: jbe    260c <kprobe_unwind_ruby+0x260c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_260c;
	}
x86_l_2585:
	/* 0x2585: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_258c:
	/* 0x258c: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_258f:
	/* 0x258f: je     1761 <kprobe_unwind_ruby+0x1761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5985ULL;
	}
x86_l_2595:
	/* 0x2595: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_259f:
	/* 0x259f: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_25a4:
	/* 0x25a4: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_25ae:
	/* 0x25ae: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_25b3:
	/* 0x25b3: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_25bd:
	/* 0x25bd: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_25c2:
	/* 0x25c2: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_25cc:
	/* 0x25cc: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25d1:
	/* 0x25d1: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_25db:
	/* 0x25db: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_25e0:
	/* 0x25e0: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_25ea:
	/* 0x25ea: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25ef:
	/* 0x25ef: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25f4:
	/* 0x25f4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_25f9:
	/* 0x25f9: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_25fe:
	/* 0x25fe: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_2603:
	/* 0x2603: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2605:
	/* 0x2605: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2607:
	/* 0x2607: jmp    1761 <kprobe_unwind_ruby+0x1761> */
	return 5985ULL;
x86_l_260c:
	/* 0x260c: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_2613:
	/* 0x2613: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_2617:
	/* 0x2617: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_261d:
	/* 0x261d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2622:
	/* 0x2622: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2625:
	/* 0x2625: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_262c:
	/* 0x262c: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2630:
	/* 0x2630: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_2637:
	/* 0x2637: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_263e:
	/* 0x263e: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_2646:
	/* 0x2646: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_264e:
	/* 0x264e: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_2659:
	/* 0x2659: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_265c:
	/* 0x265c: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_2664:
	/* 0x2664: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2669:
	/* 0x2669: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_2672:
	/* 0x2672: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_2679:
	/* 0x2679: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_2680:
	/* 0x2680: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2683:
	/* 0x2683: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2688:
	/* 0x2688: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268a:
	/* 0x268a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_268d:
	/* 0x268d: je     2753 <kprobe_unwind_ruby+0x2753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2753;
	}
x86_l_2693:
	/* 0x2693: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2696:
	/* 0x2696: jmp    1761 <kprobe_unwind_ruby+0x1761> */
	return 5985ULL;
x86_l_269b:
	/* 0x269b: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26a3:
	/* 0x26a3: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_26a8:
	/* 0x26a8: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_26ad:
	/* 0x26ad: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_26b0:
	/* 0x26b0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_26b5:
	/* 0x26b5: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_26bb:
	/* 0x26bb: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_26c0:
	/* 0x26c0: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_26c5:
	/* 0x26c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26ca:
	/* 0x26ca: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_26cd:
	/* 0x26cd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26d0:
	/* 0x26d0: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_26d6:
	/* 0x26d6: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26d9:
	/* 0x26d9: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_26db:
	/* 0x26db: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_26e0:
	/* 0x26e0: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_26e6:
	/* 0x26e6: jmp    2411 <kprobe_unwind_ruby+0x2411> */
	goto x86_l_2411;
x86_l_26eb:
	/* 0x26eb: movabs rax,0xa6c6c75662073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2933962849001587ULL);
x86_l_26f5:
	/* 0x26f5: mov    QWORD PTR [rsp+0x4d],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_26fa:
	/* 0x26fa: movabs rax,0x66207369206b6361 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7359008686476059489ULL);
x86_l_2704:
	/* 0x2704: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2709:
	/* 0x2709: movabs rax,0x7473203a656d6172 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8391085965903225202ULL);
x86_l_2713:
	/* 0x2713: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2718:
	/* 0x2718: movabs rax,0x662068737570206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358996636224200815ULL);
x86_l_2722:
	/* 0x2722: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2727:
	/* 0x2727: movabs rax,0x7420656c62616e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367799623835807349ULL);
x86_l_2731:
	/* 0x2731: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2736:
	/* 0x2736: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_273b:
	/* 0x273b: mov    eax,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_2740:
	/* 0x2740: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2745:
	/* 0x2745: mov    esi,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 37ULL);
x86_l_274a:
	/* 0x274a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_274c:
	/* 0x274c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_274e:
	/* 0x274e: jmp    e49 <kprobe_unwind_ruby+0xe49> */
	return 3657ULL;
x86_l_2753:
	/* 0x2753: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_275a:
	/* 0x275a: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_275d:
	/* 0x275d: je     1761 <kprobe_unwind_ruby+0x1761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5985ULL;
	}
x86_l_2763:
	/* 0x2763: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_276d:
	/* 0x276d: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2772:
	/* 0x2772: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_277c:
	/* 0x277c: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2781:
	/* 0x2781: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
	return 10123ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10123ULL: goto x86_l_278b;
	case 10128ULL: goto x86_l_2790;
	case 10138ULL: goto x86_l_279a;
	case 10143ULL: goto x86_l_279f;
	case 10153ULL: goto x86_l_27a9;
	case 10158ULL: goto x86_l_27ae;
	case 10168ULL: goto x86_l_27b8;
	case 10173ULL: goto x86_l_27bd;
	case 10178ULL: goto x86_l_27c2;
	case 10183ULL: goto x86_l_27c7;
	case 10188ULL: goto x86_l_27cc;
	case 10191ULL: goto x86_l_27cf;
	case 10196ULL: goto x86_l_27d4;
	case 10198ULL: goto x86_l_27d6;
	case 10200ULL: goto x86_l_27d8;
	case 10205ULL: goto x86_l_27dd;
	case 10215ULL: goto x86_l_27e7;
	case 10220ULL: goto x86_l_27ec;
	case 10230ULL: goto x86_l_27f6;
	case 10235ULL: goto x86_l_27fb;
	case 10245ULL: goto x86_l_2805;
	case 10250ULL: goto x86_l_280a;
	case 10260ULL: goto x86_l_2814;
	case 10265ULL: goto x86_l_2819;
	case 10275ULL: goto x86_l_2823;
	case 10280ULL: goto x86_l_2828;
	case 10290ULL: goto x86_l_2832;
	case 10295ULL: goto x86_l_2837;
	case 10300ULL: goto x86_l_283c;
	case 10305ULL: goto x86_l_2841;
	case 10310ULL: goto x86_l_2846;
	case 10314ULL: goto x86_l_284a;
	case 10319ULL: goto x86_l_284f;
	case 10321ULL: goto x86_l_2851;
	case 10323ULL: goto x86_l_2853;
	case 10327ULL: goto x86_l_2857;
	case 10333ULL: goto x86_l_285d;
	case 10339ULL: goto x86_l_2863;
	case 10341ULL: goto x86_l_2865;
	case 10346ULL: goto x86_l_286a;
	case 10353ULL: goto x86_l_2871;
	case 10359ULL: goto x86_l_2877;
	case 10364ULL: goto x86_l_287c;
	case 10367ULL: goto x86_l_287f;
	case 10373ULL: goto x86_l_2885;
	case 10378ULL: goto x86_l_288a;
	case 10381ULL: goto x86_l_288d;
	case 10386ULL: goto x86_l_2892;
	case 10395ULL: goto x86_l_289b;
	case 10404ULL: goto x86_l_28a4;
	case 10409ULL: goto x86_l_28a9;
	case 10412ULL: goto x86_l_28ac;
	case 10417ULL: goto x86_l_28b1;
	case 10422ULL: goto x86_l_28b6;
	case 10428ULL: goto x86_l_28bc;
	case 10433ULL: goto x86_l_28c1;
	case 10438ULL: goto x86_l_28c6;
	case 10443ULL: goto x86_l_28cb;
	case 10446ULL: goto x86_l_28ce;
	case 10451ULL: goto x86_l_28d3;
	case 10456ULL: goto x86_l_28d8;
	case 10461ULL: goto x86_l_28dd;
	case 10466ULL: goto x86_l_28e2;
	case 10472ULL: goto x86_l_28e8;
	case 10477ULL: goto x86_l_28ed;
	case 10482ULL: goto x86_l_28f2;
	case 10487ULL: goto x86_l_28f7;
	case 10490ULL: goto x86_l_28fa;
	case 10496ULL: goto x86_l_2900;
	case 10502ULL: goto x86_l_2906;
	case 10507ULL: goto x86_l_290b;
	case 10510ULL: goto x86_l_290e;
	case 10516ULL: goto x86_l_2914;
	case 10521ULL: goto x86_l_2919;
	case 10524ULL: goto x86_l_291c;
	case 10529ULL: goto x86_l_2921;
	case 10534ULL: goto x86_l_2926;
	case 10540ULL: goto x86_l_292c;
	case 10545ULL: goto x86_l_2931;
	case 10550ULL: goto x86_l_2936;
	case 10555ULL: goto x86_l_293b;
	case 10558ULL: goto x86_l_293e;
	case 10561ULL: goto x86_l_2941;
	case 10567ULL: goto x86_l_2947;
	case 10572ULL: goto x86_l_294c;
	case 10577ULL: goto x86_l_2951;
	case 10582ULL: goto x86_l_2956;
	case 10587ULL: goto x86_l_295b;
	case 10593ULL: goto x86_l_2961;
	case 10598ULL: goto x86_l_2966;
	case 10603ULL: goto x86_l_296b;
	case 10608ULL: goto x86_l_2970;
	case 10611ULL: goto x86_l_2973;
	case 10614ULL: goto x86_l_2976;
	case 10620ULL: goto x86_l_297c;
	case 10625ULL: goto x86_l_2981;
	case 10630ULL: goto x86_l_2986;
	case 10635ULL: goto x86_l_298b;
	case 10640ULL: goto x86_l_2990;
	case 10646ULL: goto x86_l_2996;
	case 10651ULL: goto x86_l_299b;
	case 10656ULL: goto x86_l_29a0;
	case 10661ULL: goto x86_l_29a5;
	case 10664ULL: goto x86_l_29a8;
	case 10667ULL: goto x86_l_29ab;
	case 10673ULL: goto x86_l_29b1;
	case 10678ULL: goto x86_l_29b6;
	case 10681ULL: goto x86_l_29b9;
	case 10686ULL: goto x86_l_29be;
	case 10691ULL: goto x86_l_29c3;
	case 10694ULL: goto x86_l_29c6;
	case 10698ULL: goto x86_l_29ca;
	case 10704ULL: goto x86_l_29d0;
	case 10706ULL: goto x86_l_29d2;
	case 10709ULL: goto x86_l_29d5;
	case 10714ULL: goto x86_l_29da;
	case 10716ULL: goto x86_l_29dc;
	case 10718ULL: goto x86_l_29de;
	case 10722ULL: goto x86_l_29e2;
	case 10725ULL: goto x86_l_29e5;
	case 10731ULL: goto x86_l_29eb;
	case 10738ULL: goto x86_l_29f2;
	case 10741ULL: goto x86_l_29f5;
	case 10747ULL: goto x86_l_29fb;
	case 10757ULL: goto x86_l_2a05;
	case 10762ULL: goto x86_l_2a0a;
	case 10772ULL: goto x86_l_2a14;
	case 10777ULL: goto x86_l_2a19;
	case 10787ULL: goto x86_l_2a23;
	case 10792ULL: goto x86_l_2a28;
	case 10802ULL: goto x86_l_2a32;
	case 10807ULL: goto x86_l_2a37;
	case 10817ULL: goto x86_l_2a41;
	case 10822ULL: goto x86_l_2a46;
	case 10832ULL: goto x86_l_2a50;
	case 10837ULL: goto x86_l_2a55;
	case 10842ULL: goto x86_l_2a5a;
	case 10847ULL: goto x86_l_2a5f;
	case 10852ULL: goto x86_l_2a64;
	case 10857ULL: goto x86_l_2a69;
	case 10859ULL: goto x86_l_2a6b;
	case 10861ULL: goto x86_l_2a6d;
	case 10866ULL: goto x86_l_2a72;
	case 10873ULL: goto x86_l_2a79;
	case 10877ULL: goto x86_l_2a7d;
	case 10883ULL: goto x86_l_2a83;
	case 10888ULL: goto x86_l_2a88;
	case 10891ULL: goto x86_l_2a8b;
	case 10898ULL: goto x86_l_2a92;
	case 10902ULL: goto x86_l_2a96;
	case 10909ULL: goto x86_l_2a9d;
	case 10916ULL: goto x86_l_2aa4;
	case 10924ULL: goto x86_l_2aac;
	case 10932ULL: goto x86_l_2ab4;
	case 10943ULL: goto x86_l_2abf;
	case 10946ULL: goto x86_l_2ac2;
	case 10954ULL: goto x86_l_2aca;
	case 10959ULL: goto x86_l_2acf;
	case 10968ULL: goto x86_l_2ad8;
	case 10975ULL: goto x86_l_2adf;
	case 10982ULL: goto x86_l_2ae6;
	case 10985ULL: goto x86_l_2ae9;
	case 10990ULL: goto x86_l_2aee;
	case 10992ULL: goto x86_l_2af0;
	case 10995ULL: goto x86_l_2af3;
	case 10997ULL: goto x86_l_2af5;
	case 11000ULL: goto x86_l_2af8;
	case 11005ULL: goto x86_l_2afd;
	case 11013ULL: goto x86_l_2b05;
	case 11018ULL: goto x86_l_2b0a;
	case 11023ULL: goto x86_l_2b0f;
	case 11026ULL: goto x86_l_2b12;
	case 11031ULL: goto x86_l_2b17;
	case 11037ULL: goto x86_l_2b1d;
	case 11042ULL: goto x86_l_2b22;
	case 11047ULL: goto x86_l_2b27;
	case 11052ULL: goto x86_l_2b2c;
	case 11055ULL: goto x86_l_2b2f;
	case 11058ULL: goto x86_l_2b32;
	case 11064ULL: goto x86_l_2b38;
	case 11067ULL: goto x86_l_2b3b;
	case 11069ULL: goto x86_l_2b3d;
	case 11074ULL: goto x86_l_2b42;
	case 11080ULL: goto x86_l_2b48;
	case 11085ULL: goto x86_l_2b4d;
	case 11092ULL: goto x86_l_2b54;
	case 11095ULL: goto x86_l_2b57;
	case 11101ULL: goto x86_l_2b5d;
	case 11111ULL: goto x86_l_2b67;
	case 11116ULL: goto x86_l_2b6c;
	case 11126ULL: goto x86_l_2b76;
	case 11131ULL: goto x86_l_2b7b;
	case 11141ULL: goto x86_l_2b85;
	case 11146ULL: goto x86_l_2b8a;
	case 11156ULL: goto x86_l_2b94;
	case 11161ULL: goto x86_l_2b99;
	case 11171ULL: goto x86_l_2ba3;
	case 11176ULL: goto x86_l_2ba8;
	case 11186ULL: goto x86_l_2bb2;
	case 11191ULL: goto x86_l_2bb7;
	case 11196ULL: goto x86_l_2bbc;
	case 11201ULL: goto x86_l_2bc1;
	case 11206ULL: goto x86_l_2bc6;
	case 11209ULL: goto x86_l_2bc9;
	case 11214ULL: goto x86_l_2bce;
	case 11216ULL: goto x86_l_2bd0;
	case 11218ULL: goto x86_l_2bd2;
	case 11223ULL: goto x86_l_2bd7;
	case 11230ULL: goto x86_l_2bde;
	case 11236ULL: goto x86_l_2be4;
	case 11241ULL: goto x86_l_2be9;
	case 11244ULL: goto x86_l_2bec;
	case 11250ULL: goto x86_l_2bf2;
	case 11255ULL: goto x86_l_2bf7;
	case 11258ULL: goto x86_l_2bfa;
	case 11263ULL: goto x86_l_2bff;
	case 11272ULL: goto x86_l_2c08;
	case 11281ULL: goto x86_l_2c11;
	case 11286ULL: goto x86_l_2c16;
	case 11289ULL: goto x86_l_2c19;
	case 11294ULL: goto x86_l_2c1e;
	case 11299ULL: goto x86_l_2c23;
	case 11305ULL: goto x86_l_2c29;
	case 11310ULL: goto x86_l_2c2e;
	case 11315ULL: goto x86_l_2c33;
	case 11320ULL: goto x86_l_2c38;
	case 11323ULL: goto x86_l_2c3b;
	case 11328ULL: goto x86_l_2c40;
	case 11333ULL: goto x86_l_2c45;
	case 11338ULL: goto x86_l_2c4a;
	case 11343ULL: goto x86_l_2c4f;
	case 11349ULL: goto x86_l_2c55;
	case 11354ULL: goto x86_l_2c5a;
	case 11359ULL: goto x86_l_2c5f;
	case 11364ULL: goto x86_l_2c64;
	case 11367ULL: goto x86_l_2c67;
	case 11373ULL: goto x86_l_2c6d;
	case 11379ULL: goto x86_l_2c73;
	case 11384ULL: goto x86_l_2c78;
	case 11387ULL: goto x86_l_2c7b;
	case 11393ULL: goto x86_l_2c81;
	case 11398ULL: goto x86_l_2c86;
	case 11401ULL: goto x86_l_2c89;
	case 11406ULL: goto x86_l_2c8e;
	case 11411ULL: goto x86_l_2c93;
	case 11417ULL: goto x86_l_2c99;
	case 11422ULL: goto x86_l_2c9e;
	case 11427ULL: goto x86_l_2ca3;
	case 11432ULL: goto x86_l_2ca8;
	case 11435ULL: goto x86_l_2cab;
	case 11438ULL: goto x86_l_2cae;
	case 11444ULL: goto x86_l_2cb4;
	case 11449ULL: goto x86_l_2cb9;
	case 11454ULL: goto x86_l_2cbe;
	case 11459ULL: goto x86_l_2cc3;
	case 11464ULL: goto x86_l_2cc8;
	case 11470ULL: goto x86_l_2cce;
	case 11475ULL: goto x86_l_2cd3;
	case 11480ULL: goto x86_l_2cd8;
	case 11485ULL: goto x86_l_2cdd;
	case 11488ULL: goto x86_l_2ce0;
	case 11491ULL: goto x86_l_2ce3;
	case 11497ULL: goto x86_l_2ce9;
	case 11502ULL: goto x86_l_2cee;
	case 11507ULL: goto x86_l_2cf3;
	case 11512ULL: goto x86_l_2cf8;
	case 11517ULL: goto x86_l_2cfd;
	case 11523ULL: goto x86_l_2d03;
	case 11528ULL: goto x86_l_2d08;
	case 11533ULL: goto x86_l_2d0d;
	case 11538ULL: goto x86_l_2d12;
	case 11541ULL: goto x86_l_2d15;
	case 11544ULL: goto x86_l_2d18;
	case 11550ULL: goto x86_l_2d1e;
	case 11555ULL: goto x86_l_2d23;
	case 11558ULL: goto x86_l_2d26;
	case 11563ULL: goto x86_l_2d2b;
	case 11568ULL: goto x86_l_2d30;
	case 11571ULL: goto x86_l_2d33;
	case 11575ULL: goto x86_l_2d37;
	case 11581ULL: goto x86_l_2d3d;
	case 11583ULL: goto x86_l_2d3f;
	case 11586ULL: goto x86_l_2d42;
	case 11591ULL: goto x86_l_2d47;
	case 11593ULL: goto x86_l_2d49;
	case 11595ULL: goto x86_l_2d4b;
	case 11599ULL: goto x86_l_2d4f;
	case 11602ULL: goto x86_l_2d52;
	case 11608ULL: goto x86_l_2d58;
	case 11615ULL: goto x86_l_2d5f;
	case 11618ULL: goto x86_l_2d62;
	case 11624ULL: goto x86_l_2d68;
	case 11634ULL: goto x86_l_2d72;
	case 11639ULL: goto x86_l_2d77;
	case 11649ULL: goto x86_l_2d81;
	case 11654ULL: goto x86_l_2d86;
	case 11664ULL: goto x86_l_2d90;
	case 11669ULL: goto x86_l_2d95;
	case 11679ULL: goto x86_l_2d9f;
	case 11684ULL: goto x86_l_2da4;
	case 11694ULL: goto x86_l_2dae;
	case 11699ULL: goto x86_l_2db3;
	case 11709ULL: goto x86_l_2dbd;
	case 11714ULL: goto x86_l_2dc2;
	case 11719ULL: goto x86_l_2dc7;
	case 11724ULL: goto x86_l_2dcc;
	case 11729ULL: goto x86_l_2dd1;
	case 11734ULL: goto x86_l_2dd6;
	case 11736ULL: goto x86_l_2dd8;
	case 11738ULL: goto x86_l_2dda;
	case 11743ULL: goto x86_l_2ddf;
	case 11750ULL: goto x86_l_2de6;
	case 11754ULL: goto x86_l_2dea;
	case 11760ULL: goto x86_l_2df0;
	case 11765ULL: goto x86_l_2df5;
	case 11768ULL: goto x86_l_2df8;
	case 11775ULL: goto x86_l_2dff;
	case 11779ULL: goto x86_l_2e03;
	case 11786ULL: goto x86_l_2e0a;
	case 11793ULL: goto x86_l_2e11;
	case 11801ULL: goto x86_l_2e19;
	case 11809ULL: goto x86_l_2e21;
	case 11820ULL: goto x86_l_2e2c;
	case 11823ULL: goto x86_l_2e2f;
	case 11831ULL: goto x86_l_2e37;
	case 11836ULL: goto x86_l_2e3c;
	case 11845ULL: goto x86_l_2e45;
	case 11852ULL: goto x86_l_2e4c;
	case 11859ULL: goto x86_l_2e53;
	case 11862ULL: goto x86_l_2e56;
	case 11867ULL: goto x86_l_2e5b;
	case 11869ULL: goto x86_l_2e5d;
	case 11872ULL: goto x86_l_2e60;
	case 11874ULL: goto x86_l_2e62;
	case 11877ULL: goto x86_l_2e65;
	case 11882ULL: goto x86_l_2e6a;
	case 11890ULL: goto x86_l_2e72;
	case 11895ULL: goto x86_l_2e77;
	case 11900ULL: goto x86_l_2e7c;
	case 11903ULL: goto x86_l_2e7f;
	case 11908ULL: goto x86_l_2e84;
	case 11914ULL: goto x86_l_2e8a;
	case 11919ULL: goto x86_l_2e8f;
	case 11924ULL: goto x86_l_2e94;
	case 11929ULL: goto x86_l_2e99;
	case 11932ULL: goto x86_l_2e9c;
	case 11935ULL: goto x86_l_2e9f;
	case 11941ULL: goto x86_l_2ea5;
	case 11944ULL: goto x86_l_2ea8;
	case 11946ULL: goto x86_l_2eaa;
	case 11951ULL: goto x86_l_2eaf;
	case 11957ULL: goto x86_l_2eb5;
	case 11962ULL: goto x86_l_2eba;
	case 11969ULL: goto x86_l_2ec1;
	case 11972ULL: goto x86_l_2ec4;
	case 11978ULL: goto x86_l_2eca;
	case 11988ULL: goto x86_l_2ed4;
	case 11993ULL: goto x86_l_2ed9;
	case 12003ULL: goto x86_l_2ee3;
	case 12008ULL: goto x86_l_2ee8;
	case 12018ULL: goto x86_l_2ef2;
	case 12023ULL: goto x86_l_2ef7;
	case 12033ULL: goto x86_l_2f01;
	case 12038ULL: goto x86_l_2f06;
	case 12048ULL: goto x86_l_2f10;
	case 12053ULL: goto x86_l_2f15;
	case 12063ULL: goto x86_l_2f1f;
	case 12068ULL: goto x86_l_2f24;
	case 12073ULL: goto x86_l_2f29;
	case 12078ULL: goto x86_l_2f2e;
	case 12083ULL: goto x86_l_2f33;
	case 12086ULL: goto x86_l_2f36;
	case 12091ULL: goto x86_l_2f3b;
	case 12093ULL: goto x86_l_2f3d;
	case 12095ULL: goto x86_l_2f3f;
	case 12100ULL: goto x86_l_2f44;
	case 12107ULL: goto x86_l_2f4b;
	case 12113ULL: goto x86_l_2f51;
	case 12118ULL: goto x86_l_2f56;
	case 12121ULL: goto x86_l_2f59;
	case 12127ULL: goto x86_l_2f5f;
	case 12132ULL: goto x86_l_2f64;
	case 12135ULL: goto x86_l_2f67;
	case 12140ULL: goto x86_l_2f6c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_278b:
	/* 0x278b: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2790:
	/* 0x2790: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_279a:
	/* 0x279a: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_279f:
	/* 0x279f: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_27a9:
	/* 0x27a9: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_27ae:
	/* 0x27ae: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_27b8:
	/* 0x27b8: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27bd:
	/* 0x27bd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27c2:
	/* 0x27c2: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_27c7:
	/* 0x27c7: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_27cc:
	/* 0x27cc: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27cf:
	/* 0x27cf: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_27d4:
	/* 0x27d4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27d6:
	/* 0x27d6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_27d8:
	/* 0x27d8: jmp    1761 <kprobe_unwind_ruby+0x1761> */
	return 5985ULL;
x86_l_27dd:
	/* 0x27dd: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_27e7:
	/* 0x27e7: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_27ec:
	/* 0x27ec: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_27f6:
	/* 0x27f6: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_27fb:
	/* 0x27fb: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_2805:
	/* 0x2805: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_280a:
	/* 0x280a: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_2814:
	/* 0x2814: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2819:
	/* 0x2819: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2823:
	/* 0x2823: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2828:
	/* 0x2828: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2832:
	/* 0x2832: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2837:
	/* 0x2837: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_283c:
	/* 0x283c: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2841:
	/* 0x2841: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2846:
	/* 0x2846: mov    edx,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_284a:
	/* 0x284a: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_284f:
	/* 0x284f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2851:
	/* 0x2851: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2853:
	/* 0x2853: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2857:
	/* 0x2857: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_285d:
	/* 0x285d: jne    e80 <kprobe_unwind_ruby+0xe80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3712ULL;
	}
x86_l_2863:
	/* 0x2863: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2865:
	/* 0x2865: jmp    2ab <kprobe_unwind_ruby+0x2ab> */
	return 683ULL;
x86_l_286a:
	/* 0x286a: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_2871:
	/* 0x2871: jae    2afd <kprobe_unwind_ruby+0x2afd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2afd;
	}
x86_l_2877:
	/* 0x2877: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_287c:
	/* 0x287c: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_287f:
	/* 0x287f: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_2885:
	/* 0x2885: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_288a:
	/* 0x288a: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_288d:
	/* 0x288d: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2892:
	/* 0x2892: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_289b:
	/* 0x289b: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_28a4:
	/* 0x28a4: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_28a9:
	/* 0x28a9: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28ac:
	/* 0x28ac: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28b1:
	/* 0x28b1: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_28b6:
	/* 0x28b6: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_28bc:
	/* 0x28bc: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_28c1:
	/* 0x28c1: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_28c6:
	/* 0x28c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28cb:
	/* 0x28cb: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_28ce:
	/* 0x28ce: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_28d3:
	/* 0x28d3: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_28d8:
	/* 0x28d8: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28dd:
	/* 0x28dd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_28e2:
	/* 0x28e2: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_28e8:
	/* 0x28e8: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_28ed:
	/* 0x28ed: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_28f2:
	/* 0x28f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28f7:
	/* 0x28f7: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_28fa:
	/* 0x28fa: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2900:
	/* 0x2900: je     2bd7 <kprobe_unwind_ruby+0x2bd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bd7;
	}
x86_l_2906:
	/* 0x2906: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_290b:
	/* 0x290b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_290e:
	/* 0x290e: je     2bd7 <kprobe_unwind_ruby+0x2bd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bd7;
	}
x86_l_2914:
	/* 0x2914: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_2919:
	/* 0x2919: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_291c:
	/* 0x291c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2921:
	/* 0x2921: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2926:
	/* 0x2926: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_292c:
	/* 0x292c: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_2931:
	/* 0x2931: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2936:
	/* 0x2936: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_293b:
	/* 0x293b: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_293e:
	/* 0x293e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2941:
	/* 0x2941: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_2947:
	/* 0x2947: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_294c:
	/* 0x294c: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2951:
	/* 0x2951: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2956:
	/* 0x2956: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_295b:
	/* 0x295b: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2961:
	/* 0x2961: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_2966:
	/* 0x2966: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_296b:
	/* 0x296b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2970:
	/* 0x2970: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2973:
	/* 0x2973: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2976:
	/* 0x2976: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_297c:
	/* 0x297c: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_2981:
	/* 0x2981: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2986:
	/* 0x2986: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_298b:
	/* 0x298b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2990:
	/* 0x2990: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2996:
	/* 0x2996: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_299b:
	/* 0x299b: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_29a0:
	/* 0x29a0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_29a5:
	/* 0x29a5: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_29a8:
	/* 0x29a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29ab:
	/* 0x29ab: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_29b1:
	/* 0x29b1: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29b6:
	/* 0x29b6: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_29b9:
	/* 0x29b9: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_29be:
	/* 0x29be: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_29c3:
	/* 0x29c3: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_29c6:
	/* 0x29c6: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_29ca:
	/* 0x29ca: je     3421 <kprobe_unwind_ruby+0x3421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13345ULL;
	}
x86_l_29d0:
	/* 0x29d0: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29d2:
	/* 0x29d2: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_29d5:
	/* 0x29d5: jmp    3425 <kprobe_unwind_ruby+0x3425> */
	return 13349ULL;
x86_l_29da:
	/* 0x29da: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29dc:
	/* 0x29dc: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_29de:
	/* 0x29de: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_29e2:
	/* 0x29e2: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_29e5:
	/* 0x29e5: jbe    2a72 <kprobe_unwind_ruby+0x2a72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2a72;
	}
x86_l_29eb:
	/* 0x29eb: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_29f2:
	/* 0x29f2: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29f5:
	/* 0x29f5: je     1d93 <kprobe_unwind_ruby+0x1d93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7571ULL;
	}
x86_l_29fb:
	/* 0x29fb: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_2a05:
	/* 0x2a05: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_2a0a:
	/* 0x2a0a: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_2a14:
	/* 0x2a14: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a19:
	/* 0x2a19: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_2a23:
	/* 0x2a23: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2a28:
	/* 0x2a28: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_2a32:
	/* 0x2a32: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a37:
	/* 0x2a37: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_2a41:
	/* 0x2a41: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a46:
	/* 0x2a46: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_2a50:
	/* 0x2a50: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a55:
	/* 0x2a55: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a5a:
	/* 0x2a5a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2a5f:
	/* 0x2a5f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2a64:
	/* 0x2a64: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_2a69:
	/* 0x2a69: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a6b:
	/* 0x2a6b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2a6d:
	/* 0x2a6d: jmp    1d93 <kprobe_unwind_ruby+0x1d93> */
	return 7571ULL;
x86_l_2a72:
	/* 0x2a72: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_2a79:
	/* 0x2a79: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_2a7d:
	/* 0x2a7d: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_2a83:
	/* 0x2a83: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a88:
	/* 0x2a88: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2a8b:
	/* 0x2a8b: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_2a92:
	/* 0x2a92: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2a96:
	/* 0x2a96: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_2a9d:
	/* 0x2a9d: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aa4:
	/* 0x2aa4: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_2aac:
	/* 0x2aac: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_2ab4:
	/* 0x2ab4: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_2abf:
	/* 0x2abf: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ac2:
	/* 0x2ac2: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_2aca:
	/* 0x2aca: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2acf:
	/* 0x2acf: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_2ad8:
	/* 0x2ad8: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_2adf:
	/* 0x2adf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_2ae6:
	/* 0x2ae6: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2ae9:
	/* 0x2ae9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2aee:
	/* 0x2aee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2af0:
	/* 0x2af0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2af3:
	/* 0x2af3: je     2b4d <kprobe_unwind_ruby+0x2b4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b4d;
	}
x86_l_2af5:
	/* 0x2af5: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2af8:
	/* 0x2af8: jmp    1d93 <kprobe_unwind_ruby+0x1d93> */
	return 7571ULL;
x86_l_2afd:
	/* 0x2afd: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b05:
	/* 0x2b05: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_2b0a:
	/* 0x2b0a: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2b0f:
	/* 0x2b0f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b12:
	/* 0x2b12: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b17:
	/* 0x2b17: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2b1d:
	/* 0x2b1d: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_2b22:
	/* 0x2b22: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2b27:
	/* 0x2b27: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b2c:
	/* 0x2b2c: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2b2f:
	/* 0x2b2f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b32:
	/* 0x2b32: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_2b38:
	/* 0x2b38: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b3b:
	/* 0x2b3b: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2b3d:
	/* 0x2b3d: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_2b42:
	/* 0x2b42: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_2b48:
	/* 0x2b48: jmp    2877 <kprobe_unwind_ruby+0x2877> */
	goto x86_l_2877;
x86_l_2b4d:
	/* 0x2b4d: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2b54:
	/* 0x2b54: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b57:
	/* 0x2b57: je     1d93 <kprobe_unwind_ruby+0x1d93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7571ULL;
	}
x86_l_2b5d:
	/* 0x2b5d: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_2b67:
	/* 0x2b67: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2b6c:
	/* 0x2b6c: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_2b76:
	/* 0x2b76: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b7b:
	/* 0x2b7b: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_2b85:
	/* 0x2b85: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b8a:
	/* 0x2b8a: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_2b94:
	/* 0x2b94: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b99:
	/* 0x2b99: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2ba3:
	/* 0x2ba3: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ba8:
	/* 0x2ba8: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2bb2:
	/* 0x2bb2: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bb7:
	/* 0x2bb7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bbc:
	/* 0x2bbc: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2bc1:
	/* 0x2bc1: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2bc6:
	/* 0x2bc6: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bc9:
	/* 0x2bc9: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2bce:
	/* 0x2bce: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bd0:
	/* 0x2bd0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2bd2:
	/* 0x2bd2: jmp    1d93 <kprobe_unwind_ruby+0x1d93> */
	return 7571ULL;
x86_l_2bd7:
	/* 0x2bd7: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_2bde:
	/* 0x2bde: jae    2e6a <kprobe_unwind_ruby+0x2e6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2e6a;
	}
x86_l_2be4:
	/* 0x2be4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2be9:
	/* 0x2be9: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2bec:
	/* 0x2bec: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_2bf2:
	/* 0x2bf2: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_2bf7:
	/* 0x2bf7: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2bfa:
	/* 0x2bfa: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bff:
	/* 0x2bff: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2c08:
	/* 0x2c08: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2c11:
	/* 0x2c11: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_2c16:
	/* 0x2c16: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c19:
	/* 0x2c19: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c1e:
	/* 0x2c1e: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_2c23:
	/* 0x2c23: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2c29:
	/* 0x2c29: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_2c2e:
	/* 0x2c2e: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2c33:
	/* 0x2c33: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c38:
	/* 0x2c38: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2c3b:
	/* 0x2c3b: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_2c40:
	/* 0x2c40: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2c45:
	/* 0x2c45: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c4a:
	/* 0x2c4a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c4f:
	/* 0x2c4f: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2c55:
	/* 0x2c55: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_2c5a:
	/* 0x2c5a: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2c5f:
	/* 0x2c5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c64:
	/* 0x2c64: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2c67:
	/* 0x2c67: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2c6d:
	/* 0x2c6d: je     2f44 <kprobe_unwind_ruby+0x2f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f44;
	}
x86_l_2c73:
	/* 0x2c73: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c78:
	/* 0x2c78: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c7b:
	/* 0x2c7b: je     2f44 <kprobe_unwind_ruby+0x2f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f44;
	}
x86_l_2c81:
	/* 0x2c81: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_2c86:
	/* 0x2c86: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c89:
	/* 0x2c89: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c8e:
	/* 0x2c8e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c93:
	/* 0x2c93: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2c99:
	/* 0x2c99: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_2c9e:
	/* 0x2c9e: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2ca3:
	/* 0x2ca3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ca8:
	/* 0x2ca8: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2cab:
	/* 0x2cab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cae:
	/* 0x2cae: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_2cb4:
	/* 0x2cb4: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_2cb9:
	/* 0x2cb9: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2cbe:
	/* 0x2cbe: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2cc3:
	/* 0x2cc3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2cc8:
	/* 0x2cc8: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2cce:
	/* 0x2cce: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_2cd3:
	/* 0x2cd3: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2cd8:
	/* 0x2cd8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cdd:
	/* 0x2cdd: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2ce0:
	/* 0x2ce0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ce3:
	/* 0x2ce3: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_2ce9:
	/* 0x2ce9: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_2cee:
	/* 0x2cee: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2cf3:
	/* 0x2cf3: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2cf8:
	/* 0x2cf8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2cfd:
	/* 0x2cfd: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2d03:
	/* 0x2d03: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_2d08:
	/* 0x2d08: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2d0d:
	/* 0x2d0d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d12:
	/* 0x2d12: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2d15:
	/* 0x2d15: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d18:
	/* 0x2d18: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_2d1e:
	/* 0x2d1e: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d23:
	/* 0x2d23: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_2d26:
	/* 0x2d26: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_2d2b:
	/* 0x2d2b: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_2d30:
	/* 0x2d30: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2d33:
	/* 0x2d33: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2d37:
	/* 0x2d37: je     378e <kprobe_unwind_ruby+0x378e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14222ULL;
	}
x86_l_2d3d:
	/* 0x2d3d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d3f:
	/* 0x2d3f: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_2d42:
	/* 0x2d42: jmp    3792 <kprobe_unwind_ruby+0x3792> */
	return 14226ULL;
x86_l_2d47:
	/* 0x2d47: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d49:
	/* 0x2d49: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_2d4b:
	/* 0x2d4b: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2d4f:
	/* 0x2d4f: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_2d52:
	/* 0x2d52: jbe    2ddf <kprobe_unwind_ruby+0x2ddf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2ddf;
	}
x86_l_2d58:
	/* 0x2d58: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2d5f:
	/* 0x2d5f: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d62:
	/* 0x2d62: je     2411 <kprobe_unwind_ruby+0x2411> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9233ULL;
	}
x86_l_2d68:
	/* 0x2d68: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_2d72:
	/* 0x2d72: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_2d77:
	/* 0x2d77: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_2d81:
	/* 0x2d81: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2d86:
	/* 0x2d86: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_2d90:
	/* 0x2d90: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2d95:
	/* 0x2d95: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_2d9f:
	/* 0x2d9f: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2da4:
	/* 0x2da4: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_2dae:
	/* 0x2dae: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2db3:
	/* 0x2db3: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_2dbd:
	/* 0x2dbd: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2dc2:
	/* 0x2dc2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2dc7:
	/* 0x2dc7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2dcc:
	/* 0x2dcc: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2dd1:
	/* 0x2dd1: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_2dd6:
	/* 0x2dd6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2dd8:
	/* 0x2dd8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2dda:
	/* 0x2dda: jmp    2411 <kprobe_unwind_ruby+0x2411> */
	return 9233ULL;
x86_l_2ddf:
	/* 0x2ddf: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_2de6:
	/* 0x2de6: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_2dea:
	/* 0x2dea: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_2df0:
	/* 0x2df0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2df5:
	/* 0x2df5: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2df8:
	/* 0x2df8: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_2dff:
	/* 0x2dff: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2e03:
	/* 0x2e03: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_2e0a:
	/* 0x2e0a: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e11:
	/* 0x2e11: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_2e19:
	/* 0x2e19: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_2e21:
	/* 0x2e21: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_2e2c:
	/* 0x2e2c: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e2f:
	/* 0x2e2f: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_2e37:
	/* 0x2e37: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2e3c:
	/* 0x2e3c: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_2e45:
	/* 0x2e45: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_2e4c:
	/* 0x2e4c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_2e53:
	/* 0x2e53: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2e56:
	/* 0x2e56: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e5b:
	/* 0x2e5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e5d:
	/* 0x2e5d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e60:
	/* 0x2e60: je     2eba <kprobe_unwind_ruby+0x2eba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2eba;
	}
x86_l_2e62:
	/* 0x2e62: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2e65:
	/* 0x2e65: jmp    2411 <kprobe_unwind_ruby+0x2411> */
	return 9233ULL;
x86_l_2e6a:
	/* 0x2e6a: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e72:
	/* 0x2e72: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_2e77:
	/* 0x2e77: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2e7c:
	/* 0x2e7c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e7f:
	/* 0x2e7f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e84:
	/* 0x2e84: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2e8a:
	/* 0x2e8a: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_2e8f:
	/* 0x2e8f: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2e94:
	/* 0x2e94: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e99:
	/* 0x2e99: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2e9c:
	/* 0x2e9c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e9f:
	/* 0x2e9f: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_2ea5:
	/* 0x2ea5: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ea8:
	/* 0x2ea8: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2eaa:
	/* 0x2eaa: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_2eaf:
	/* 0x2eaf: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_2eb5:
	/* 0x2eb5: jmp    2be4 <kprobe_unwind_ruby+0x2be4> */
	goto x86_l_2be4;
x86_l_2eba:
	/* 0x2eba: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2ec1:
	/* 0x2ec1: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ec4:
	/* 0x2ec4: je     2411 <kprobe_unwind_ruby+0x2411> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9233ULL;
	}
x86_l_2eca:
	/* 0x2eca: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_2ed4:
	/* 0x2ed4: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2ed9:
	/* 0x2ed9: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_2ee3:
	/* 0x2ee3: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2ee8:
	/* 0x2ee8: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_2ef2:
	/* 0x2ef2: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2ef7:
	/* 0x2ef7: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_2f01:
	/* 0x2f01: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f06:
	/* 0x2f06: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2f10:
	/* 0x2f10: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f15:
	/* 0x2f15: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2f1f:
	/* 0x2f1f: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f24:
	/* 0x2f24: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f29:
	/* 0x2f29: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2f2e:
	/* 0x2f2e: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2f33:
	/* 0x2f33: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f36:
	/* 0x2f36: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2f3b:
	/* 0x2f3b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f3d:
	/* 0x2f3d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2f3f:
	/* 0x2f3f: jmp    2411 <kprobe_unwind_ruby+0x2411> */
	return 9233ULL;
x86_l_2f44:
	/* 0x2f44: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_2f4b:
	/* 0x2f4b: jae    31d7 <kprobe_unwind_ruby+0x31d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12759ULL;
	}
x86_l_2f51:
	/* 0x2f51: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f56:
	/* 0x2f56: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2f59:
	/* 0x2f59: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_2f5f:
	/* 0x2f5f: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_2f64:
	/* 0x2f64: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f67:
	/* 0x2f67: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f6c:
	/* 0x2f6c: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
	return 12149ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12149ULL: goto x86_l_2f75;
	case 12158ULL: goto x86_l_2f7e;
	case 12163ULL: goto x86_l_2f83;
	case 12166ULL: goto x86_l_2f86;
	case 12171ULL: goto x86_l_2f8b;
	case 12176ULL: goto x86_l_2f90;
	case 12182ULL: goto x86_l_2f96;
	case 12187ULL: goto x86_l_2f9b;
	case 12192ULL: goto x86_l_2fa0;
	case 12197ULL: goto x86_l_2fa5;
	case 12200ULL: goto x86_l_2fa8;
	case 12205ULL: goto x86_l_2fad;
	case 12210ULL: goto x86_l_2fb2;
	case 12215ULL: goto x86_l_2fb7;
	case 12220ULL: goto x86_l_2fbc;
	case 12226ULL: goto x86_l_2fc2;
	case 12231ULL: goto x86_l_2fc7;
	case 12236ULL: goto x86_l_2fcc;
	case 12241ULL: goto x86_l_2fd1;
	case 12244ULL: goto x86_l_2fd4;
	case 12250ULL: goto x86_l_2fda;
	case 12256ULL: goto x86_l_2fe0;
	case 12261ULL: goto x86_l_2fe5;
	case 12264ULL: goto x86_l_2fe8;
	case 12270ULL: goto x86_l_2fee;
	case 12275ULL: goto x86_l_2ff3;
	case 12278ULL: goto x86_l_2ff6;
	case 12283ULL: goto x86_l_2ffb;
	case 12288ULL: goto x86_l_3000;
	case 12294ULL: goto x86_l_3006;
	case 12299ULL: goto x86_l_300b;
	case 12304ULL: goto x86_l_3010;
	case 12309ULL: goto x86_l_3015;
	case 12312ULL: goto x86_l_3018;
	case 12315ULL: goto x86_l_301b;
	case 12321ULL: goto x86_l_3021;
	case 12326ULL: goto x86_l_3026;
	case 12331ULL: goto x86_l_302b;
	case 12336ULL: goto x86_l_3030;
	case 12341ULL: goto x86_l_3035;
	case 12347ULL: goto x86_l_303b;
	case 12352ULL: goto x86_l_3040;
	case 12357ULL: goto x86_l_3045;
	case 12362ULL: goto x86_l_304a;
	case 12365ULL: goto x86_l_304d;
	case 12368ULL: goto x86_l_3050;
	case 12374ULL: goto x86_l_3056;
	case 12379ULL: goto x86_l_305b;
	case 12384ULL: goto x86_l_3060;
	case 12389ULL: goto x86_l_3065;
	case 12394ULL: goto x86_l_306a;
	case 12400ULL: goto x86_l_3070;
	case 12405ULL: goto x86_l_3075;
	case 12410ULL: goto x86_l_307a;
	case 12415ULL: goto x86_l_307f;
	case 12418ULL: goto x86_l_3082;
	case 12421ULL: goto x86_l_3085;
	case 12427ULL: goto x86_l_308b;
	case 12432ULL: goto x86_l_3090;
	case 12435ULL: goto x86_l_3093;
	case 12440ULL: goto x86_l_3098;
	case 12445ULL: goto x86_l_309d;
	case 12448ULL: goto x86_l_30a0;
	case 12452ULL: goto x86_l_30a4;
	case 12458ULL: goto x86_l_30aa;
	case 12460ULL: goto x86_l_30ac;
	case 12463ULL: goto x86_l_30af;
	case 12468ULL: goto x86_l_30b4;
	case 12470ULL: goto x86_l_30b6;
	case 12472ULL: goto x86_l_30b8;
	case 12476ULL: goto x86_l_30bc;
	case 12479ULL: goto x86_l_30bf;
	case 12485ULL: goto x86_l_30c5;
	case 12492ULL: goto x86_l_30cc;
	case 12495ULL: goto x86_l_30cf;
	case 12501ULL: goto x86_l_30d5;
	case 12511ULL: goto x86_l_30df;
	case 12516ULL: goto x86_l_30e4;
	case 12526ULL: goto x86_l_30ee;
	case 12531ULL: goto x86_l_30f3;
	case 12541ULL: goto x86_l_30fd;
	case 12546ULL: goto x86_l_3102;
	case 12556ULL: goto x86_l_310c;
	case 12561ULL: goto x86_l_3111;
	case 12571ULL: goto x86_l_311b;
	case 12576ULL: goto x86_l_3120;
	case 12586ULL: goto x86_l_312a;
	case 12591ULL: goto x86_l_312f;
	case 12596ULL: goto x86_l_3134;
	case 12601ULL: goto x86_l_3139;
	case 12606ULL: goto x86_l_313e;
	case 12611ULL: goto x86_l_3143;
	case 12613ULL: goto x86_l_3145;
	case 12615ULL: goto x86_l_3147;
	case 12620ULL: goto x86_l_314c;
	case 12627ULL: goto x86_l_3153;
	case 12631ULL: goto x86_l_3157;
	case 12637ULL: goto x86_l_315d;
	case 12642ULL: goto x86_l_3162;
	case 12645ULL: goto x86_l_3165;
	case 12652ULL: goto x86_l_316c;
	case 12656ULL: goto x86_l_3170;
	case 12663ULL: goto x86_l_3177;
	case 12670ULL: goto x86_l_317e;
	case 12678ULL: goto x86_l_3186;
	case 12686ULL: goto x86_l_318e;
	case 12697ULL: goto x86_l_3199;
	case 12700ULL: goto x86_l_319c;
	case 12708ULL: goto x86_l_31a4;
	case 12713ULL: goto x86_l_31a9;
	case 12722ULL: goto x86_l_31b2;
	case 12729ULL: goto x86_l_31b9;
	case 12736ULL: goto x86_l_31c0;
	case 12739ULL: goto x86_l_31c3;
	case 12744ULL: goto x86_l_31c8;
	case 12746ULL: goto x86_l_31ca;
	case 12749ULL: goto x86_l_31cd;
	case 12751ULL: goto x86_l_31cf;
	case 12754ULL: goto x86_l_31d2;
	case 12759ULL: goto x86_l_31d7;
	case 12767ULL: goto x86_l_31df;
	case 12772ULL: goto x86_l_31e4;
	case 12777ULL: goto x86_l_31e9;
	case 12780ULL: goto x86_l_31ec;
	case 12785ULL: goto x86_l_31f1;
	case 12791ULL: goto x86_l_31f7;
	case 12796ULL: goto x86_l_31fc;
	case 12801ULL: goto x86_l_3201;
	case 12806ULL: goto x86_l_3206;
	case 12809ULL: goto x86_l_3209;
	case 12812ULL: goto x86_l_320c;
	case 12818ULL: goto x86_l_3212;
	case 12821ULL: goto x86_l_3215;
	case 12823ULL: goto x86_l_3217;
	case 12828ULL: goto x86_l_321c;
	case 12834ULL: goto x86_l_3222;
	case 12839ULL: goto x86_l_3227;
	case 12846ULL: goto x86_l_322e;
	case 12849ULL: goto x86_l_3231;
	case 12855ULL: goto x86_l_3237;
	case 12865ULL: goto x86_l_3241;
	case 12870ULL: goto x86_l_3246;
	case 12880ULL: goto x86_l_3250;
	case 12885ULL: goto x86_l_3255;
	case 12895ULL: goto x86_l_325f;
	case 12900ULL: goto x86_l_3264;
	case 12910ULL: goto x86_l_326e;
	case 12915ULL: goto x86_l_3273;
	case 12925ULL: goto x86_l_327d;
	case 12930ULL: goto x86_l_3282;
	case 12940ULL: goto x86_l_328c;
	case 12945ULL: goto x86_l_3291;
	case 12950ULL: goto x86_l_3296;
	case 12955ULL: goto x86_l_329b;
	case 12960ULL: goto x86_l_32a0;
	case 12963ULL: goto x86_l_32a3;
	case 12968ULL: goto x86_l_32a8;
	case 12970ULL: goto x86_l_32aa;
	case 12972ULL: goto x86_l_32ac;
	case 12977ULL: goto x86_l_32b1;
	case 12984ULL: goto x86_l_32b8;
	case 12990ULL: goto x86_l_32be;
	case 12995ULL: goto x86_l_32c3;
	case 12998ULL: goto x86_l_32c6;
	case 13004ULL: goto x86_l_32cc;
	case 13009ULL: goto x86_l_32d1;
	case 13012ULL: goto x86_l_32d4;
	case 13017ULL: goto x86_l_32d9;
	case 13026ULL: goto x86_l_32e2;
	case 13035ULL: goto x86_l_32eb;
	case 13040ULL: goto x86_l_32f0;
	case 13043ULL: goto x86_l_32f3;
	case 13048ULL: goto x86_l_32f8;
	case 13053ULL: goto x86_l_32fd;
	case 13059ULL: goto x86_l_3303;
	case 13064ULL: goto x86_l_3308;
	case 13069ULL: goto x86_l_330d;
	case 13074ULL: goto x86_l_3312;
	case 13077ULL: goto x86_l_3315;
	case 13082ULL: goto x86_l_331a;
	case 13087ULL: goto x86_l_331f;
	case 13092ULL: goto x86_l_3324;
	case 13097ULL: goto x86_l_3329;
	case 13103ULL: goto x86_l_332f;
	case 13108ULL: goto x86_l_3334;
	case 13113ULL: goto x86_l_3339;
	case 13118ULL: goto x86_l_333e;
	case 13121ULL: goto x86_l_3341;
	case 13127ULL: goto x86_l_3347;
	case 13133ULL: goto x86_l_334d;
	case 13138ULL: goto x86_l_3352;
	case 13141ULL: goto x86_l_3355;
	case 13147ULL: goto x86_l_335b;
	case 13152ULL: goto x86_l_3360;
	case 13155ULL: goto x86_l_3363;
	case 13160ULL: goto x86_l_3368;
	case 13165ULL: goto x86_l_336d;
	case 13171ULL: goto x86_l_3373;
	case 13176ULL: goto x86_l_3378;
	case 13181ULL: goto x86_l_337d;
	case 13186ULL: goto x86_l_3382;
	case 13189ULL: goto x86_l_3385;
	case 13192ULL: goto x86_l_3388;
	case 13198ULL: goto x86_l_338e;
	case 13203ULL: goto x86_l_3393;
	case 13208ULL: goto x86_l_3398;
	case 13213ULL: goto x86_l_339d;
	case 13218ULL: goto x86_l_33a2;
	case 13224ULL: goto x86_l_33a8;
	case 13229ULL: goto x86_l_33ad;
	case 13234ULL: goto x86_l_33b2;
	case 13239ULL: goto x86_l_33b7;
	case 13242ULL: goto x86_l_33ba;
	case 13245ULL: goto x86_l_33bd;
	case 13251ULL: goto x86_l_33c3;
	case 13256ULL: goto x86_l_33c8;
	case 13261ULL: goto x86_l_33cd;
	case 13266ULL: goto x86_l_33d2;
	case 13271ULL: goto x86_l_33d7;
	case 13277ULL: goto x86_l_33dd;
	case 13282ULL: goto x86_l_33e2;
	case 13287ULL: goto x86_l_33e7;
	case 13292ULL: goto x86_l_33ec;
	case 13295ULL: goto x86_l_33ef;
	case 13298ULL: goto x86_l_33f2;
	case 13304ULL: goto x86_l_33f8;
	case 13309ULL: goto x86_l_33fd;
	case 13312ULL: goto x86_l_3400;
	case 13317ULL: goto x86_l_3405;
	case 13322ULL: goto x86_l_340a;
	case 13325ULL: goto x86_l_340d;
	case 13329ULL: goto x86_l_3411;
	case 13335ULL: goto x86_l_3417;
	case 13337ULL: goto x86_l_3419;
	case 13340ULL: goto x86_l_341c;
	case 13345ULL: goto x86_l_3421;
	case 13347ULL: goto x86_l_3423;
	case 13349ULL: goto x86_l_3425;
	case 13353ULL: goto x86_l_3429;
	case 13356ULL: goto x86_l_342c;
	case 13362ULL: goto x86_l_3432;
	case 13369ULL: goto x86_l_3439;
	case 13372ULL: goto x86_l_343c;
	case 13378ULL: goto x86_l_3442;
	case 13388ULL: goto x86_l_344c;
	case 13393ULL: goto x86_l_3451;
	case 13403ULL: goto x86_l_345b;
	case 13408ULL: goto x86_l_3460;
	case 13418ULL: goto x86_l_346a;
	case 13423ULL: goto x86_l_346f;
	case 13433ULL: goto x86_l_3479;
	case 13438ULL: goto x86_l_347e;
	case 13448ULL: goto x86_l_3488;
	case 13453ULL: goto x86_l_348d;
	case 13463ULL: goto x86_l_3497;
	case 13468ULL: goto x86_l_349c;
	case 13473ULL: goto x86_l_34a1;
	case 13478ULL: goto x86_l_34a6;
	case 13483ULL: goto x86_l_34ab;
	case 13488ULL: goto x86_l_34b0;
	case 13490ULL: goto x86_l_34b2;
	case 13492ULL: goto x86_l_34b4;
	case 13497ULL: goto x86_l_34b9;
	case 13504ULL: goto x86_l_34c0;
	case 13508ULL: goto x86_l_34c4;
	case 13514ULL: goto x86_l_34ca;
	case 13519ULL: goto x86_l_34cf;
	case 13522ULL: goto x86_l_34d2;
	case 13529ULL: goto x86_l_34d9;
	case 13533ULL: goto x86_l_34dd;
	case 13540ULL: goto x86_l_34e4;
	case 13547ULL: goto x86_l_34eb;
	case 13555ULL: goto x86_l_34f3;
	case 13563ULL: goto x86_l_34fb;
	case 13574ULL: goto x86_l_3506;
	case 13577ULL: goto x86_l_3509;
	case 13585ULL: goto x86_l_3511;
	case 13590ULL: goto x86_l_3516;
	case 13599ULL: goto x86_l_351f;
	case 13606ULL: goto x86_l_3526;
	case 13613ULL: goto x86_l_352d;
	case 13616ULL: goto x86_l_3530;
	case 13621ULL: goto x86_l_3535;
	case 13623ULL: goto x86_l_3537;
	case 13626ULL: goto x86_l_353a;
	case 13628ULL: goto x86_l_353c;
	case 13631ULL: goto x86_l_353f;
	case 13636ULL: goto x86_l_3544;
	case 13644ULL: goto x86_l_354c;
	case 13649ULL: goto x86_l_3551;
	case 13654ULL: goto x86_l_3556;
	case 13657ULL: goto x86_l_3559;
	case 13662ULL: goto x86_l_355e;
	case 13668ULL: goto x86_l_3564;
	case 13673ULL: goto x86_l_3569;
	case 13678ULL: goto x86_l_356e;
	case 13683ULL: goto x86_l_3573;
	case 13686ULL: goto x86_l_3576;
	case 13689ULL: goto x86_l_3579;
	case 13695ULL: goto x86_l_357f;
	case 13698ULL: goto x86_l_3582;
	case 13700ULL: goto x86_l_3584;
	case 13705ULL: goto x86_l_3589;
	case 13711ULL: goto x86_l_358f;
	case 13716ULL: goto x86_l_3594;
	case 13723ULL: goto x86_l_359b;
	case 13726ULL: goto x86_l_359e;
	case 13732ULL: goto x86_l_35a4;
	case 13742ULL: goto x86_l_35ae;
	case 13747ULL: goto x86_l_35b3;
	case 13757ULL: goto x86_l_35bd;
	case 13762ULL: goto x86_l_35c2;
	case 13772ULL: goto x86_l_35cc;
	case 13777ULL: goto x86_l_35d1;
	case 13787ULL: goto x86_l_35db;
	case 13792ULL: goto x86_l_35e0;
	case 13802ULL: goto x86_l_35ea;
	case 13807ULL: goto x86_l_35ef;
	case 13817ULL: goto x86_l_35f9;
	case 13822ULL: goto x86_l_35fe;
	case 13827ULL: goto x86_l_3603;
	case 13832ULL: goto x86_l_3608;
	case 13837ULL: goto x86_l_360d;
	case 13840ULL: goto x86_l_3610;
	case 13845ULL: goto x86_l_3615;
	case 13847ULL: goto x86_l_3617;
	case 13849ULL: goto x86_l_3619;
	case 13854ULL: goto x86_l_361e;
	case 13861ULL: goto x86_l_3625;
	case 13867ULL: goto x86_l_362b;
	case 13872ULL: goto x86_l_3630;
	case 13875ULL: goto x86_l_3633;
	case 13881ULL: goto x86_l_3639;
	case 13886ULL: goto x86_l_363e;
	case 13889ULL: goto x86_l_3641;
	case 13894ULL: goto x86_l_3646;
	case 13903ULL: goto x86_l_364f;
	case 13912ULL: goto x86_l_3658;
	case 13917ULL: goto x86_l_365d;
	case 13920ULL: goto x86_l_3660;
	case 13925ULL: goto x86_l_3665;
	case 13930ULL: goto x86_l_366a;
	case 13936ULL: goto x86_l_3670;
	case 13941ULL: goto x86_l_3675;
	case 13946ULL: goto x86_l_367a;
	case 13951ULL: goto x86_l_367f;
	case 13954ULL: goto x86_l_3682;
	case 13959ULL: goto x86_l_3687;
	case 13964ULL: goto x86_l_368c;
	case 13969ULL: goto x86_l_3691;
	case 13974ULL: goto x86_l_3696;
	case 13980ULL: goto x86_l_369c;
	case 13985ULL: goto x86_l_36a1;
	case 13990ULL: goto x86_l_36a6;
	case 13995ULL: goto x86_l_36ab;
	case 13998ULL: goto x86_l_36ae;
	case 14004ULL: goto x86_l_36b4;
	case 14010ULL: goto x86_l_36ba;
	case 14015ULL: goto x86_l_36bf;
	case 14018ULL: goto x86_l_36c2;
	case 14024ULL: goto x86_l_36c8;
	case 14029ULL: goto x86_l_36cd;
	case 14032ULL: goto x86_l_36d0;
	case 14037ULL: goto x86_l_36d5;
	case 14042ULL: goto x86_l_36da;
	case 14048ULL: goto x86_l_36e0;
	case 14053ULL: goto x86_l_36e5;
	case 14058ULL: goto x86_l_36ea;
	case 14063ULL: goto x86_l_36ef;
	case 14066ULL: goto x86_l_36f2;
	case 14069ULL: goto x86_l_36f5;
	case 14075ULL: goto x86_l_36fb;
	case 14080ULL: goto x86_l_3700;
	case 14085ULL: goto x86_l_3705;
	case 14090ULL: goto x86_l_370a;
	case 14095ULL: goto x86_l_370f;
	case 14101ULL: goto x86_l_3715;
	case 14106ULL: goto x86_l_371a;
	case 14111ULL: goto x86_l_371f;
	case 14116ULL: goto x86_l_3724;
	case 14119ULL: goto x86_l_3727;
	case 14122ULL: goto x86_l_372a;
	case 14128ULL: goto x86_l_3730;
	case 14133ULL: goto x86_l_3735;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2f75:
	/* 0x2f75: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2f7e:
	/* 0x2f7e: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_2f83:
	/* 0x2f83: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f86:
	/* 0x2f86: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f8b:
	/* 0x2f8b: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_2f90:
	/* 0x2f90: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2f96:
	/* 0x2f96: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_2f9b:
	/* 0x2f9b: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2fa0:
	/* 0x2fa0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fa5:
	/* 0x2fa5: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2fa8:
	/* 0x2fa8: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_2fad:
	/* 0x2fad: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2fb2:
	/* 0x2fb2: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fb7:
	/* 0x2fb7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2fbc:
	/* 0x2fbc: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2fc2:
	/* 0x2fc2: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_2fc7:
	/* 0x2fc7: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2fcc:
	/* 0x2fcc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fd1:
	/* 0x2fd1: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2fd4:
	/* 0x2fd4: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2fda:
	/* 0x2fda: je     32b1 <kprobe_unwind_ruby+0x32b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32b1;
	}
x86_l_2fe0:
	/* 0x2fe0: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fe5:
	/* 0x2fe5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2fe8:
	/* 0x2fe8: je     32b1 <kprobe_unwind_ruby+0x32b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32b1;
	}
x86_l_2fee:
	/* 0x2fee: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_2ff3:
	/* 0x2ff3: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ff6:
	/* 0x2ff6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ffb:
	/* 0x2ffb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3000:
	/* 0x3000: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3006:
	/* 0x3006: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_300b:
	/* 0x300b: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_3010:
	/* 0x3010: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3015:
	/* 0x3015: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3018:
	/* 0x3018: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_301b:
	/* 0x301b: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_3021:
	/* 0x3021: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_3026:
	/* 0x3026: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_302b:
	/* 0x302b: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3030:
	/* 0x3030: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3035:
	/* 0x3035: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_303b:
	/* 0x303b: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_3040:
	/* 0x3040: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3045:
	/* 0x3045: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_304a:
	/* 0x304a: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_304d:
	/* 0x304d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3050:
	/* 0x3050: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_3056:
	/* 0x3056: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_305b:
	/* 0x305b: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3060:
	/* 0x3060: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3065:
	/* 0x3065: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_306a:
	/* 0x306a: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3070:
	/* 0x3070: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_3075:
	/* 0x3075: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_307a:
	/* 0x307a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_307f:
	/* 0x307f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3082:
	/* 0x3082: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3085:
	/* 0x3085: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_308b:
	/* 0x308b: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3090:
	/* 0x3090: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_3093:
	/* 0x3093: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_3098:
	/* 0x3098: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_309d:
	/* 0x309d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_30a0:
	/* 0x30a0: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_30a4:
	/* 0x30a4: je     3afb <kprobe_unwind_ruby+0x3afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15099ULL;
	}
x86_l_30aa:
	/* 0x30aa: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30ac:
	/* 0x30ac: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_30af:
	/* 0x30af: jmp    3aff <kprobe_unwind_ruby+0x3aff> */
	return 15103ULL;
x86_l_30b4:
	/* 0x30b4: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30b6:
	/* 0x30b6: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_30b8:
	/* 0x30b8: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_30bc:
	/* 0x30bc: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_30bf:
	/* 0x30bf: jbe    314c <kprobe_unwind_ruby+0x314c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_314c;
	}
x86_l_30c5:
	/* 0x30c5: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_30cc:
	/* 0x30cc: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30cf:
	/* 0x30cf: je     2877 <kprobe_unwind_ruby+0x2877> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10359ULL;
	}
x86_l_30d5:
	/* 0x30d5: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_30df:
	/* 0x30df: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_30e4:
	/* 0x30e4: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_30ee:
	/* 0x30ee: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30f3:
	/* 0x30f3: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_30fd:
	/* 0x30fd: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3102:
	/* 0x3102: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_310c:
	/* 0x310c: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3111:
	/* 0x3111: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_311b:
	/* 0x311b: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3120:
	/* 0x3120: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_312a:
	/* 0x312a: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_312f:
	/* 0x312f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3134:
	/* 0x3134: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3139:
	/* 0x3139: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_313e:
	/* 0x313e: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_3143:
	/* 0x3143: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3145:
	/* 0x3145: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3147:
	/* 0x3147: jmp    2877 <kprobe_unwind_ruby+0x2877> */
	return 10359ULL;
x86_l_314c:
	/* 0x314c: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3153:
	/* 0x3153: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_3157:
	/* 0x3157: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_315d:
	/* 0x315d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3162:
	/* 0x3162: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3165:
	/* 0x3165: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_316c:
	/* 0x316c: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_3170:
	/* 0x3170: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3177:
	/* 0x3177: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_317e:
	/* 0x317e: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_3186:
	/* 0x3186: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_318e:
	/* 0x318e: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_3199:
	/* 0x3199: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_319c:
	/* 0x319c: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_31a4:
	/* 0x31a4: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_31a9:
	/* 0x31a9: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_31b2:
	/* 0x31b2: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_31b9:
	/* 0x31b9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_31c0:
	/* 0x31c0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_31c3:
	/* 0x31c3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31c8:
	/* 0x31c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31ca:
	/* 0x31ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31cd:
	/* 0x31cd: je     3227 <kprobe_unwind_ruby+0x3227> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3227;
	}
x86_l_31cf:
	/* 0x31cf: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_31d2:
	/* 0x31d2: jmp    2877 <kprobe_unwind_ruby+0x2877> */
	return 10359ULL;
x86_l_31d7:
	/* 0x31d7: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31df:
	/* 0x31df: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_31e4:
	/* 0x31e4: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_31e9:
	/* 0x31e9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_31ec:
	/* 0x31ec: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31f1:
	/* 0x31f1: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_31f7:
	/* 0x31f7: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_31fc:
	/* 0x31fc: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3201:
	/* 0x3201: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3206:
	/* 0x3206: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3209:
	/* 0x3209: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_320c:
	/* 0x320c: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_3212:
	/* 0x3212: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3215:
	/* 0x3215: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_3217:
	/* 0x3217: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_321c:
	/* 0x321c: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_3222:
	/* 0x3222: jmp    2f51 <kprobe_unwind_ruby+0x2f51> */
	return 12113ULL;
x86_l_3227:
	/* 0x3227: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_322e:
	/* 0x322e: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3231:
	/* 0x3231: je     2877 <kprobe_unwind_ruby+0x2877> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10359ULL;
	}
x86_l_3237:
	/* 0x3237: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_3241:
	/* 0x3241: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_3246:
	/* 0x3246: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_3250:
	/* 0x3250: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3255:
	/* 0x3255: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_325f:
	/* 0x325f: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3264:
	/* 0x3264: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_326e:
	/* 0x326e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3273:
	/* 0x3273: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_327d:
	/* 0x327d: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3282:
	/* 0x3282: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_328c:
	/* 0x328c: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3291:
	/* 0x3291: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3296:
	/* 0x3296: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_329b:
	/* 0x329b: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_32a0:
	/* 0x32a0: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32a3:
	/* 0x32a3: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_32a8:
	/* 0x32a8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32aa:
	/* 0x32aa: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_32ac:
	/* 0x32ac: jmp    2877 <kprobe_unwind_ruby+0x2877> */
	return 10359ULL;
x86_l_32b1:
	/* 0x32b1: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_32b8:
	/* 0x32b8: jae    3544 <kprobe_unwind_ruby+0x3544> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3544;
	}
x86_l_32be:
	/* 0x32be: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32c3:
	/* 0x32c3: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_32c6:
	/* 0x32c6: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_32cc:
	/* 0x32cc: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_32d1:
	/* 0x32d1: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_32d4:
	/* 0x32d4: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32d9:
	/* 0x32d9: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_32e2:
	/* 0x32e2: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_32eb:
	/* 0x32eb: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_32f0:
	/* 0x32f0: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_32f3:
	/* 0x32f3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32f8:
	/* 0x32f8: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_32fd:
	/* 0x32fd: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3303:
	/* 0x3303: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_3308:
	/* 0x3308: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_330d:
	/* 0x330d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3312:
	/* 0x3312: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3315:
	/* 0x3315: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_331a:
	/* 0x331a: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_331f:
	/* 0x331f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3324:
	/* 0x3324: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3329:
	/* 0x3329: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_332f:
	/* 0x332f: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_3334:
	/* 0x3334: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3339:
	/* 0x3339: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_333e:
	/* 0x333e: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3341:
	/* 0x3341: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3347:
	/* 0x3347: je     361e <kprobe_unwind_ruby+0x361e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_361e;
	}
x86_l_334d:
	/* 0x334d: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3352:
	/* 0x3352: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3355:
	/* 0x3355: je     361e <kprobe_unwind_ruby+0x361e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_361e;
	}
x86_l_335b:
	/* 0x335b: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_3360:
	/* 0x3360: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3363:
	/* 0x3363: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3368:
	/* 0x3368: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_336d:
	/* 0x336d: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3373:
	/* 0x3373: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_3378:
	/* 0x3378: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_337d:
	/* 0x337d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3382:
	/* 0x3382: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3385:
	/* 0x3385: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3388:
	/* 0x3388: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_338e:
	/* 0x338e: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_3393:
	/* 0x3393: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3398:
	/* 0x3398: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_339d:
	/* 0x339d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_33a2:
	/* 0x33a2: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_33a8:
	/* 0x33a8: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_33ad:
	/* 0x33ad: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_33b2:
	/* 0x33b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33b7:
	/* 0x33b7: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_33ba:
	/* 0x33ba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33bd:
	/* 0x33bd: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_33c3:
	/* 0x33c3: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_33c8:
	/* 0x33c8: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_33cd:
	/* 0x33cd: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_33d2:
	/* 0x33d2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_33d7:
	/* 0x33d7: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_33dd:
	/* 0x33dd: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_33e2:
	/* 0x33e2: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_33e7:
	/* 0x33e7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_33ec:
	/* 0x33ec: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_33ef:
	/* 0x33ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33f2:
	/* 0x33f2: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_33f8:
	/* 0x33f8: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33fd:
	/* 0x33fd: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_3400:
	/* 0x3400: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_3405:
	/* 0x3405: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_340a:
	/* 0x340a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_340d:
	/* 0x340d: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_3411:
	/* 0x3411: je     3e68 <kprobe_unwind_ruby+0x3e68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15976ULL;
	}
x86_l_3417:
	/* 0x3417: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3419:
	/* 0x3419: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_341c:
	/* 0x341c: jmp    3e6c <kprobe_unwind_ruby+0x3e6c> */
	return 15980ULL;
x86_l_3421:
	/* 0x3421: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3423:
	/* 0x3423: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_3425:
	/* 0x3425: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3429:
	/* 0x3429: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_342c:
	/* 0x342c: jbe    34b9 <kprobe_unwind_ruby+0x34b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_34b9;
	}
x86_l_3432:
	/* 0x3432: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3439:
	/* 0x3439: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_343c:
	/* 0x343c: je     2be4 <kprobe_unwind_ruby+0x2be4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11236ULL;
	}
x86_l_3442:
	/* 0x3442: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_344c:
	/* 0x344c: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_3451:
	/* 0x3451: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_345b:
	/* 0x345b: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3460:
	/* 0x3460: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_346a:
	/* 0x346a: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_346f:
	/* 0x346f: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_3479:
	/* 0x3479: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_347e:
	/* 0x347e: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_3488:
	/* 0x3488: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_348d:
	/* 0x348d: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_3497:
	/* 0x3497: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_349c:
	/* 0x349c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_34a1:
	/* 0x34a1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_34a6:
	/* 0x34a6: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_34ab:
	/* 0x34ab: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_34b0:
	/* 0x34b0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34b2:
	/* 0x34b2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_34b4:
	/* 0x34b4: jmp    2be4 <kprobe_unwind_ruby+0x2be4> */
	return 11236ULL;
x86_l_34b9:
	/* 0x34b9: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_34c0:
	/* 0x34c0: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_34c4:
	/* 0x34c4: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_34ca:
	/* 0x34ca: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34cf:
	/* 0x34cf: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_34d2:
	/* 0x34d2: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_34d9:
	/* 0x34d9: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_34dd:
	/* 0x34dd: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_34e4:
	/* 0x34e4: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34eb:
	/* 0x34eb: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_34f3:
	/* 0x34f3: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_34fb:
	/* 0x34fb: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_3506:
	/* 0x3506: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3509:
	/* 0x3509: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_3511:
	/* 0x3511: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3516:
	/* 0x3516: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_351f:
	/* 0x351f: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_3526:
	/* 0x3526: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_352d:
	/* 0x352d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_3530:
	/* 0x3530: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3535:
	/* 0x3535: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3537:
	/* 0x3537: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_353a:
	/* 0x353a: je     3594 <kprobe_unwind_ruby+0x3594> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3594;
	}
x86_l_353c:
	/* 0x353c: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_353f:
	/* 0x353f: jmp    2be4 <kprobe_unwind_ruby+0x2be4> */
	return 11236ULL;
x86_l_3544:
	/* 0x3544: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_354c:
	/* 0x354c: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_3551:
	/* 0x3551: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3556:
	/* 0x3556: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3559:
	/* 0x3559: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_355e:
	/* 0x355e: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3564:
	/* 0x3564: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_3569:
	/* 0x3569: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_356e:
	/* 0x356e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3573:
	/* 0x3573: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3576:
	/* 0x3576: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3579:
	/* 0x3579: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_357f:
	/* 0x357f: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3582:
	/* 0x3582: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_3584:
	/* 0x3584: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_3589:
	/* 0x3589: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_358f:
	/* 0x358f: jmp    32be <kprobe_unwind_ruby+0x32be> */
	goto x86_l_32be;
x86_l_3594:
	/* 0x3594: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_359b:
	/* 0x359b: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_359e:
	/* 0x359e: je     2be4 <kprobe_unwind_ruby+0x2be4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11236ULL;
	}
x86_l_35a4:
	/* 0x35a4: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_35ae:
	/* 0x35ae: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_35b3:
	/* 0x35b3: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_35bd:
	/* 0x35bd: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_35c2:
	/* 0x35c2: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_35cc:
	/* 0x35cc: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_35d1:
	/* 0x35d1: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_35db:
	/* 0x35db: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_35e0:
	/* 0x35e0: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_35ea:
	/* 0x35ea: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_35ef:
	/* 0x35ef: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_35f9:
	/* 0x35f9: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_35fe:
	/* 0x35fe: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3603:
	/* 0x3603: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_3608:
	/* 0x3608: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_360d:
	/* 0x360d: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3610:
	/* 0x3610: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_3615:
	/* 0x3615: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3617:
	/* 0x3617: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3619:
	/* 0x3619: jmp    2be4 <kprobe_unwind_ruby+0x2be4> */
	return 11236ULL;
x86_l_361e:
	/* 0x361e: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_3625:
	/* 0x3625: jae    38b1 <kprobe_unwind_ruby+0x38b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14513ULL;
	}
x86_l_362b:
	/* 0x362b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3630:
	/* 0x3630: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3633:
	/* 0x3633: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_3639:
	/* 0x3639: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_363e:
	/* 0x363e: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3641:
	/* 0x3641: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3646:
	/* 0x3646: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_364f:
	/* 0x364f: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3658:
	/* 0x3658: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_365d:
	/* 0x365d: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3660:
	/* 0x3660: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3665:
	/* 0x3665: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_366a:
	/* 0x366a: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3670:
	/* 0x3670: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_3675:
	/* 0x3675: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_367a:
	/* 0x367a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_367f:
	/* 0x367f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3682:
	/* 0x3682: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_3687:
	/* 0x3687: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_368c:
	/* 0x368c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3691:
	/* 0x3691: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3696:
	/* 0x3696: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_369c:
	/* 0x369c: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_36a1:
	/* 0x36a1: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_36a6:
	/* 0x36a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36ab:
	/* 0x36ab: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_36ae:
	/* 0x36ae: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_36b4:
	/* 0x36b4: je     398b <kprobe_unwind_ruby+0x398b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14731ULL;
	}
x86_l_36ba:
	/* 0x36ba: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_36bf:
	/* 0x36bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36c2:
	/* 0x36c2: je     398b <kprobe_unwind_ruby+0x398b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14731ULL;
	}
x86_l_36c8:
	/* 0x36c8: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_36cd:
	/* 0x36cd: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_36d0:
	/* 0x36d0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36d5:
	/* 0x36d5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_36da:
	/* 0x36da: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_36e0:
	/* 0x36e0: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_36e5:
	/* 0x36e5: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_36ea:
	/* 0x36ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36ef:
	/* 0x36ef: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_36f2:
	/* 0x36f2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36f5:
	/* 0x36f5: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_36fb:
	/* 0x36fb: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_3700:
	/* 0x3700: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3705:
	/* 0x3705: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_370a:
	/* 0x370a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_370f:
	/* 0x370f: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3715:
	/* 0x3715: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_371a:
	/* 0x371a: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_371f:
	/* 0x371f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3724:
	/* 0x3724: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3727:
	/* 0x3727: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_372a:
	/* 0x372a: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_3730:
	/* 0x3730: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_3735:
	/* 0x3735: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
	return 14138ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14138ULL: goto x86_l_373a;
	case 14143ULL: goto x86_l_373f;
	case 14148ULL: goto x86_l_3744;
	case 14154ULL: goto x86_l_374a;
	case 14159ULL: goto x86_l_374f;
	case 14164ULL: goto x86_l_3754;
	case 14169ULL: goto x86_l_3759;
	case 14172ULL: goto x86_l_375c;
	case 14175ULL: goto x86_l_375f;
	case 14181ULL: goto x86_l_3765;
	case 14186ULL: goto x86_l_376a;
	case 14189ULL: goto x86_l_376d;
	case 14194ULL: goto x86_l_3772;
	case 14199ULL: goto x86_l_3777;
	case 14202ULL: goto x86_l_377a;
	case 14206ULL: goto x86_l_377e;
	case 14212ULL: goto x86_l_3784;
	case 14214ULL: goto x86_l_3786;
	case 14217ULL: goto x86_l_3789;
	case 14222ULL: goto x86_l_378e;
	case 14224ULL: goto x86_l_3790;
	case 14226ULL: goto x86_l_3792;
	case 14230ULL: goto x86_l_3796;
	case 14233ULL: goto x86_l_3799;
	case 14239ULL: goto x86_l_379f;
	case 14246ULL: goto x86_l_37a6;
	case 14249ULL: goto x86_l_37a9;
	case 14255ULL: goto x86_l_37af;
	case 14265ULL: goto x86_l_37b9;
	case 14270ULL: goto x86_l_37be;
	case 14280ULL: goto x86_l_37c8;
	case 14285ULL: goto x86_l_37cd;
	case 14295ULL: goto x86_l_37d7;
	case 14300ULL: goto x86_l_37dc;
	case 14310ULL: goto x86_l_37e6;
	case 14315ULL: goto x86_l_37eb;
	case 14325ULL: goto x86_l_37f5;
	case 14330ULL: goto x86_l_37fa;
	case 14340ULL: goto x86_l_3804;
	case 14345ULL: goto x86_l_3809;
	case 14350ULL: goto x86_l_380e;
	case 14355ULL: goto x86_l_3813;
	case 14360ULL: goto x86_l_3818;
	case 14365ULL: goto x86_l_381d;
	case 14367ULL: goto x86_l_381f;
	case 14369ULL: goto x86_l_3821;
	case 14374ULL: goto x86_l_3826;
	case 14381ULL: goto x86_l_382d;
	case 14385ULL: goto x86_l_3831;
	case 14391ULL: goto x86_l_3837;
	case 14396ULL: goto x86_l_383c;
	case 14399ULL: goto x86_l_383f;
	case 14406ULL: goto x86_l_3846;
	case 14410ULL: goto x86_l_384a;
	case 14417ULL: goto x86_l_3851;
	case 14424ULL: goto x86_l_3858;
	case 14432ULL: goto x86_l_3860;
	case 14440ULL: goto x86_l_3868;
	case 14451ULL: goto x86_l_3873;
	case 14454ULL: goto x86_l_3876;
	case 14462ULL: goto x86_l_387e;
	case 14467ULL: goto x86_l_3883;
	case 14476ULL: goto x86_l_388c;
	case 14483ULL: goto x86_l_3893;
	case 14490ULL: goto x86_l_389a;
	case 14493ULL: goto x86_l_389d;
	case 14498ULL: goto x86_l_38a2;
	case 14500ULL: goto x86_l_38a4;
	case 14503ULL: goto x86_l_38a7;
	case 14505ULL: goto x86_l_38a9;
	case 14508ULL: goto x86_l_38ac;
	case 14513ULL: goto x86_l_38b1;
	case 14521ULL: goto x86_l_38b9;
	case 14526ULL: goto x86_l_38be;
	case 14531ULL: goto x86_l_38c3;
	case 14534ULL: goto x86_l_38c6;
	case 14539ULL: goto x86_l_38cb;
	case 14545ULL: goto x86_l_38d1;
	case 14550ULL: goto x86_l_38d6;
	case 14555ULL: goto x86_l_38db;
	case 14560ULL: goto x86_l_38e0;
	case 14563ULL: goto x86_l_38e3;
	case 14566ULL: goto x86_l_38e6;
	case 14572ULL: goto x86_l_38ec;
	case 14575ULL: goto x86_l_38ef;
	case 14577ULL: goto x86_l_38f1;
	case 14582ULL: goto x86_l_38f6;
	case 14588ULL: goto x86_l_38fc;
	case 14593ULL: goto x86_l_3901;
	case 14600ULL: goto x86_l_3908;
	case 14603ULL: goto x86_l_390b;
	case 14609ULL: goto x86_l_3911;
	case 14619ULL: goto x86_l_391b;
	case 14624ULL: goto x86_l_3920;
	case 14634ULL: goto x86_l_392a;
	case 14639ULL: goto x86_l_392f;
	case 14649ULL: goto x86_l_3939;
	case 14654ULL: goto x86_l_393e;
	case 14664ULL: goto x86_l_3948;
	case 14669ULL: goto x86_l_394d;
	case 14679ULL: goto x86_l_3957;
	case 14684ULL: goto x86_l_395c;
	case 14694ULL: goto x86_l_3966;
	case 14699ULL: goto x86_l_396b;
	case 14704ULL: goto x86_l_3970;
	case 14709ULL: goto x86_l_3975;
	case 14714ULL: goto x86_l_397a;
	case 14717ULL: goto x86_l_397d;
	case 14722ULL: goto x86_l_3982;
	case 14724ULL: goto x86_l_3984;
	case 14726ULL: goto x86_l_3986;
	case 14731ULL: goto x86_l_398b;
	case 14738ULL: goto x86_l_3992;
	case 14744ULL: goto x86_l_3998;
	case 14749ULL: goto x86_l_399d;
	case 14752ULL: goto x86_l_39a0;
	case 14758ULL: goto x86_l_39a6;
	case 14763ULL: goto x86_l_39ab;
	case 14766ULL: goto x86_l_39ae;
	case 14771ULL: goto x86_l_39b3;
	case 14780ULL: goto x86_l_39bc;
	case 14789ULL: goto x86_l_39c5;
	case 14794ULL: goto x86_l_39ca;
	case 14797ULL: goto x86_l_39cd;
	case 14802ULL: goto x86_l_39d2;
	case 14807ULL: goto x86_l_39d7;
	case 14813ULL: goto x86_l_39dd;
	case 14818ULL: goto x86_l_39e2;
	case 14823ULL: goto x86_l_39e7;
	case 14828ULL: goto x86_l_39ec;
	case 14831ULL: goto x86_l_39ef;
	case 14836ULL: goto x86_l_39f4;
	case 14841ULL: goto x86_l_39f9;
	case 14846ULL: goto x86_l_39fe;
	case 14851ULL: goto x86_l_3a03;
	case 14857ULL: goto x86_l_3a09;
	case 14862ULL: goto x86_l_3a0e;
	case 14867ULL: goto x86_l_3a13;
	case 14872ULL: goto x86_l_3a18;
	case 14875ULL: goto x86_l_3a1b;
	case 14881ULL: goto x86_l_3a21;
	case 14887ULL: goto x86_l_3a27;
	case 14892ULL: goto x86_l_3a2c;
	case 14895ULL: goto x86_l_3a2f;
	case 14901ULL: goto x86_l_3a35;
	case 14906ULL: goto x86_l_3a3a;
	case 14909ULL: goto x86_l_3a3d;
	case 14914ULL: goto x86_l_3a42;
	case 14919ULL: goto x86_l_3a47;
	case 14925ULL: goto x86_l_3a4d;
	case 14930ULL: goto x86_l_3a52;
	case 14935ULL: goto x86_l_3a57;
	case 14940ULL: goto x86_l_3a5c;
	case 14943ULL: goto x86_l_3a5f;
	case 14946ULL: goto x86_l_3a62;
	case 14952ULL: goto x86_l_3a68;
	case 14957ULL: goto x86_l_3a6d;
	case 14962ULL: goto x86_l_3a72;
	case 14967ULL: goto x86_l_3a77;
	case 14972ULL: goto x86_l_3a7c;
	case 14978ULL: goto x86_l_3a82;
	case 14983ULL: goto x86_l_3a87;
	case 14988ULL: goto x86_l_3a8c;
	case 14993ULL: goto x86_l_3a91;
	case 14996ULL: goto x86_l_3a94;
	case 14999ULL: goto x86_l_3a97;
	case 15005ULL: goto x86_l_3a9d;
	case 15010ULL: goto x86_l_3aa2;
	case 15015ULL: goto x86_l_3aa7;
	case 15020ULL: goto x86_l_3aac;
	case 15025ULL: goto x86_l_3ab1;
	case 15031ULL: goto x86_l_3ab7;
	case 15036ULL: goto x86_l_3abc;
	case 15041ULL: goto x86_l_3ac1;
	case 15046ULL: goto x86_l_3ac6;
	case 15049ULL: goto x86_l_3ac9;
	case 15052ULL: goto x86_l_3acc;
	case 15058ULL: goto x86_l_3ad2;
	case 15063ULL: goto x86_l_3ad7;
	case 15066ULL: goto x86_l_3ada;
	case 15071ULL: goto x86_l_3adf;
	case 15076ULL: goto x86_l_3ae4;
	case 15079ULL: goto x86_l_3ae7;
	case 15083ULL: goto x86_l_3aeb;
	case 15089ULL: goto x86_l_3af1;
	case 15091ULL: goto x86_l_3af3;
	case 15094ULL: goto x86_l_3af6;
	case 15099ULL: goto x86_l_3afb;
	case 15101ULL: goto x86_l_3afd;
	case 15103ULL: goto x86_l_3aff;
	case 15107ULL: goto x86_l_3b03;
	case 15110ULL: goto x86_l_3b06;
	case 15116ULL: goto x86_l_3b0c;
	case 15123ULL: goto x86_l_3b13;
	case 15126ULL: goto x86_l_3b16;
	case 15132ULL: goto x86_l_3b1c;
	case 15142ULL: goto x86_l_3b26;
	case 15147ULL: goto x86_l_3b2b;
	case 15157ULL: goto x86_l_3b35;
	case 15162ULL: goto x86_l_3b3a;
	case 15172ULL: goto x86_l_3b44;
	case 15177ULL: goto x86_l_3b49;
	case 15187ULL: goto x86_l_3b53;
	case 15192ULL: goto x86_l_3b58;
	case 15202ULL: goto x86_l_3b62;
	case 15207ULL: goto x86_l_3b67;
	case 15217ULL: goto x86_l_3b71;
	case 15222ULL: goto x86_l_3b76;
	case 15227ULL: goto x86_l_3b7b;
	case 15232ULL: goto x86_l_3b80;
	case 15237ULL: goto x86_l_3b85;
	case 15242ULL: goto x86_l_3b8a;
	case 15244ULL: goto x86_l_3b8c;
	case 15246ULL: goto x86_l_3b8e;
	case 15251ULL: goto x86_l_3b93;
	case 15258ULL: goto x86_l_3b9a;
	case 15262ULL: goto x86_l_3b9e;
	case 15268ULL: goto x86_l_3ba4;
	case 15273ULL: goto x86_l_3ba9;
	case 15276ULL: goto x86_l_3bac;
	case 15283ULL: goto x86_l_3bb3;
	case 15287ULL: goto x86_l_3bb7;
	case 15294ULL: goto x86_l_3bbe;
	case 15301ULL: goto x86_l_3bc5;
	case 15309ULL: goto x86_l_3bcd;
	case 15317ULL: goto x86_l_3bd5;
	case 15328ULL: goto x86_l_3be0;
	case 15331ULL: goto x86_l_3be3;
	case 15339ULL: goto x86_l_3beb;
	case 15344ULL: goto x86_l_3bf0;
	case 15353ULL: goto x86_l_3bf9;
	case 15360ULL: goto x86_l_3c00;
	case 15367ULL: goto x86_l_3c07;
	case 15370ULL: goto x86_l_3c0a;
	case 15375ULL: goto x86_l_3c0f;
	case 15377ULL: goto x86_l_3c11;
	case 15380ULL: goto x86_l_3c14;
	case 15382ULL: goto x86_l_3c16;
	case 15385ULL: goto x86_l_3c19;
	case 15390ULL: goto x86_l_3c1e;
	case 15398ULL: goto x86_l_3c26;
	case 15403ULL: goto x86_l_3c2b;
	case 15408ULL: goto x86_l_3c30;
	case 15411ULL: goto x86_l_3c33;
	case 15416ULL: goto x86_l_3c38;
	case 15422ULL: goto x86_l_3c3e;
	case 15427ULL: goto x86_l_3c43;
	case 15432ULL: goto x86_l_3c48;
	case 15437ULL: goto x86_l_3c4d;
	case 15440ULL: goto x86_l_3c50;
	case 15443ULL: goto x86_l_3c53;
	case 15449ULL: goto x86_l_3c59;
	case 15452ULL: goto x86_l_3c5c;
	case 15454ULL: goto x86_l_3c5e;
	case 15459ULL: goto x86_l_3c63;
	case 15465ULL: goto x86_l_3c69;
	case 15470ULL: goto x86_l_3c6e;
	case 15477ULL: goto x86_l_3c75;
	case 15480ULL: goto x86_l_3c78;
	case 15486ULL: goto x86_l_3c7e;
	case 15496ULL: goto x86_l_3c88;
	case 15501ULL: goto x86_l_3c8d;
	case 15511ULL: goto x86_l_3c97;
	case 15516ULL: goto x86_l_3c9c;
	case 15526ULL: goto x86_l_3ca6;
	case 15531ULL: goto x86_l_3cab;
	case 15541ULL: goto x86_l_3cb5;
	case 15546ULL: goto x86_l_3cba;
	case 15556ULL: goto x86_l_3cc4;
	case 15561ULL: goto x86_l_3cc9;
	case 15571ULL: goto x86_l_3cd3;
	case 15576ULL: goto x86_l_3cd8;
	case 15581ULL: goto x86_l_3cdd;
	case 15586ULL: goto x86_l_3ce2;
	case 15591ULL: goto x86_l_3ce7;
	case 15594ULL: goto x86_l_3cea;
	case 15599ULL: goto x86_l_3cef;
	case 15601ULL: goto x86_l_3cf1;
	case 15603ULL: goto x86_l_3cf3;
	case 15608ULL: goto x86_l_3cf8;
	case 15615ULL: goto x86_l_3cff;
	case 15621ULL: goto x86_l_3d05;
	case 15626ULL: goto x86_l_3d0a;
	case 15629ULL: goto x86_l_3d0d;
	case 15635ULL: goto x86_l_3d13;
	case 15640ULL: goto x86_l_3d18;
	case 15643ULL: goto x86_l_3d1b;
	case 15648ULL: goto x86_l_3d20;
	case 15657ULL: goto x86_l_3d29;
	case 15666ULL: goto x86_l_3d32;
	case 15671ULL: goto x86_l_3d37;
	case 15674ULL: goto x86_l_3d3a;
	case 15679ULL: goto x86_l_3d3f;
	case 15684ULL: goto x86_l_3d44;
	case 15690ULL: goto x86_l_3d4a;
	case 15695ULL: goto x86_l_3d4f;
	case 15700ULL: goto x86_l_3d54;
	case 15705ULL: goto x86_l_3d59;
	case 15708ULL: goto x86_l_3d5c;
	case 15713ULL: goto x86_l_3d61;
	case 15718ULL: goto x86_l_3d66;
	case 15723ULL: goto x86_l_3d6b;
	case 15728ULL: goto x86_l_3d70;
	case 15734ULL: goto x86_l_3d76;
	case 15739ULL: goto x86_l_3d7b;
	case 15744ULL: goto x86_l_3d80;
	case 15749ULL: goto x86_l_3d85;
	case 15752ULL: goto x86_l_3d88;
	case 15758ULL: goto x86_l_3d8e;
	case 15764ULL: goto x86_l_3d94;
	case 15769ULL: goto x86_l_3d99;
	case 15772ULL: goto x86_l_3d9c;
	case 15778ULL: goto x86_l_3da2;
	case 15783ULL: goto x86_l_3da7;
	case 15786ULL: goto x86_l_3daa;
	case 15791ULL: goto x86_l_3daf;
	case 15796ULL: goto x86_l_3db4;
	case 15802ULL: goto x86_l_3dba;
	case 15807ULL: goto x86_l_3dbf;
	case 15812ULL: goto x86_l_3dc4;
	case 15817ULL: goto x86_l_3dc9;
	case 15820ULL: goto x86_l_3dcc;
	case 15823ULL: goto x86_l_3dcf;
	case 15829ULL: goto x86_l_3dd5;
	case 15834ULL: goto x86_l_3dda;
	case 15839ULL: goto x86_l_3ddf;
	case 15844ULL: goto x86_l_3de4;
	case 15849ULL: goto x86_l_3de9;
	case 15855ULL: goto x86_l_3def;
	case 15860ULL: goto x86_l_3df4;
	case 15865ULL: goto x86_l_3df9;
	case 15870ULL: goto x86_l_3dfe;
	case 15873ULL: goto x86_l_3e01;
	case 15876ULL: goto x86_l_3e04;
	case 15882ULL: goto x86_l_3e0a;
	case 15887ULL: goto x86_l_3e0f;
	case 15892ULL: goto x86_l_3e14;
	case 15897ULL: goto x86_l_3e19;
	case 15902ULL: goto x86_l_3e1e;
	case 15908ULL: goto x86_l_3e24;
	case 15913ULL: goto x86_l_3e29;
	case 15918ULL: goto x86_l_3e2e;
	case 15923ULL: goto x86_l_3e33;
	case 15926ULL: goto x86_l_3e36;
	case 15929ULL: goto x86_l_3e39;
	case 15935ULL: goto x86_l_3e3f;
	case 15940ULL: goto x86_l_3e44;
	case 15943ULL: goto x86_l_3e47;
	case 15948ULL: goto x86_l_3e4c;
	case 15953ULL: goto x86_l_3e51;
	case 15956ULL: goto x86_l_3e54;
	case 15960ULL: goto x86_l_3e58;
	case 15966ULL: goto x86_l_3e5e;
	case 15968ULL: goto x86_l_3e60;
	case 15971ULL: goto x86_l_3e63;
	case 15976ULL: goto x86_l_3e68;
	case 15978ULL: goto x86_l_3e6a;
	case 15980ULL: goto x86_l_3e6c;
	case 15984ULL: goto x86_l_3e70;
	case 15987ULL: goto x86_l_3e73;
	case 15993ULL: goto x86_l_3e79;
	case 16000ULL: goto x86_l_3e80;
	case 16003ULL: goto x86_l_3e83;
	case 16009ULL: goto x86_l_3e89;
	case 16019ULL: goto x86_l_3e93;
	case 16024ULL: goto x86_l_3e98;
	case 16034ULL: goto x86_l_3ea2;
	case 16039ULL: goto x86_l_3ea7;
	case 16049ULL: goto x86_l_3eb1;
	case 16054ULL: goto x86_l_3eb6;
	case 16064ULL: goto x86_l_3ec0;
	case 16069ULL: goto x86_l_3ec5;
	case 16079ULL: goto x86_l_3ecf;
	case 16084ULL: goto x86_l_3ed4;
	case 16094ULL: goto x86_l_3ede;
	case 16099ULL: goto x86_l_3ee3;
	case 16104ULL: goto x86_l_3ee8;
	case 16109ULL: goto x86_l_3eed;
	case 16114ULL: goto x86_l_3ef2;
	case 16119ULL: goto x86_l_3ef7;
	case 16121ULL: goto x86_l_3ef9;
	case 16123ULL: goto x86_l_3efb;
	case 16128ULL: goto x86_l_3f00;
	case 16135ULL: goto x86_l_3f07;
	default: return 0xffffffffffffffffULL;
	}
x86_l_373a:
	/* 0x373a: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_373f:
	/* 0x373f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3744:
	/* 0x3744: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_374a:
	/* 0x374a: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_374f:
	/* 0x374f: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3754:
	/* 0x3754: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3759:
	/* 0x3759: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_375c:
	/* 0x375c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_375f:
	/* 0x375f: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_3765:
	/* 0x3765: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_376a:
	/* 0x376a: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_376d:
	/* 0x376d: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_3772:
	/* 0x3772: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_3777:
	/* 0x3777: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_377a:
	/* 0x377a: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_377e:
	/* 0x377e: je     41d5 <kprobe_unwind_ruby+0x41d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16853ULL;
	}
x86_l_3784:
	/* 0x3784: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3786:
	/* 0x3786: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_3789:
	/* 0x3789: jmp    41d9 <kprobe_unwind_ruby+0x41d9> */
	return 16857ULL;
x86_l_378e:
	/* 0x378e: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3790:
	/* 0x3790: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_3792:
	/* 0x3792: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3796:
	/* 0x3796: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_3799:
	/* 0x3799: jbe    3826 <kprobe_unwind_ruby+0x3826> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3826;
	}
x86_l_379f:
	/* 0x379f: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_37a6:
	/* 0x37a6: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37a9:
	/* 0x37a9: je     2f51 <kprobe_unwind_ruby+0x2f51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12113ULL;
	}
x86_l_37af:
	/* 0x37af: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_37b9:
	/* 0x37b9: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_37be:
	/* 0x37be: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_37c8:
	/* 0x37c8: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_37cd:
	/* 0x37cd: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_37d7:
	/* 0x37d7: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_37dc:
	/* 0x37dc: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_37e6:
	/* 0x37e6: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_37eb:
	/* 0x37eb: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_37f5:
	/* 0x37f5: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_37fa:
	/* 0x37fa: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_3804:
	/* 0x3804: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3809:
	/* 0x3809: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_380e:
	/* 0x380e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3813:
	/* 0x3813: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3818:
	/* 0x3818: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_381d:
	/* 0x381d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_381f:
	/* 0x381f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3821:
	/* 0x3821: jmp    2f51 <kprobe_unwind_ruby+0x2f51> */
	return 12113ULL;
x86_l_3826:
	/* 0x3826: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_382d:
	/* 0x382d: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_3831:
	/* 0x3831: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_3837:
	/* 0x3837: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_383c:
	/* 0x383c: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_383f:
	/* 0x383f: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3846:
	/* 0x3846: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_384a:
	/* 0x384a: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3851:
	/* 0x3851: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3858:
	/* 0x3858: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_3860:
	/* 0x3860: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_3868:
	/* 0x3868: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_3873:
	/* 0x3873: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3876:
	/* 0x3876: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_387e:
	/* 0x387e: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3883:
	/* 0x3883: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_388c:
	/* 0x388c: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_3893:
	/* 0x3893: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_389a:
	/* 0x389a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_389d:
	/* 0x389d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_38a2:
	/* 0x38a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38a4:
	/* 0x38a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38a7:
	/* 0x38a7: je     3901 <kprobe_unwind_ruby+0x3901> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3901;
	}
x86_l_38a9:
	/* 0x38a9: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_38ac:
	/* 0x38ac: jmp    2f51 <kprobe_unwind_ruby+0x2f51> */
	return 12113ULL;
x86_l_38b1:
	/* 0x38b1: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38b9:
	/* 0x38b9: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_38be:
	/* 0x38be: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_38c3:
	/* 0x38c3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_38c6:
	/* 0x38c6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_38cb:
	/* 0x38cb: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_38d1:
	/* 0x38d1: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_38d6:
	/* 0x38d6: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_38db:
	/* 0x38db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38e0:
	/* 0x38e0: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_38e3:
	/* 0x38e3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38e6:
	/* 0x38e6: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_38ec:
	/* 0x38ec: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38ef:
	/* 0x38ef: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_38f1:
	/* 0x38f1: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_38f6:
	/* 0x38f6: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_38fc:
	/* 0x38fc: jmp    362b <kprobe_unwind_ruby+0x362b> */
	return 13867ULL;
x86_l_3901:
	/* 0x3901: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3908:
	/* 0x3908: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_390b:
	/* 0x390b: je     2f51 <kprobe_unwind_ruby+0x2f51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12113ULL;
	}
x86_l_3911:
	/* 0x3911: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_391b:
	/* 0x391b: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_3920:
	/* 0x3920: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_392a:
	/* 0x392a: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_392f:
	/* 0x392f: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_3939:
	/* 0x3939: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_393e:
	/* 0x393e: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_3948:
	/* 0x3948: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_394d:
	/* 0x394d: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_3957:
	/* 0x3957: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_395c:
	/* 0x395c: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_3966:
	/* 0x3966: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_396b:
	/* 0x396b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3970:
	/* 0x3970: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_3975:
	/* 0x3975: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_397a:
	/* 0x397a: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_397d:
	/* 0x397d: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_3982:
	/* 0x3982: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3984:
	/* 0x3984: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3986:
	/* 0x3986: jmp    2f51 <kprobe_unwind_ruby+0x2f51> */
	return 12113ULL;
x86_l_398b:
	/* 0x398b: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_3992:
	/* 0x3992: jae    3c1e <kprobe_unwind_ruby+0x3c1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3c1e;
	}
x86_l_3998:
	/* 0x3998: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_399d:
	/* 0x399d: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_39a0:
	/* 0x39a0: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_39a6:
	/* 0x39a6: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_39ab:
	/* 0x39ab: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_39ae:
	/* 0x39ae: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39b3:
	/* 0x39b3: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_39bc:
	/* 0x39bc: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_39c5:
	/* 0x39c5: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_39ca:
	/* 0x39ca: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_39cd:
	/* 0x39cd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_39d2:
	/* 0x39d2: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_39d7:
	/* 0x39d7: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_39dd:
	/* 0x39dd: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_39e2:
	/* 0x39e2: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_39e7:
	/* 0x39e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39ec:
	/* 0x39ec: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_39ef:
	/* 0x39ef: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_39f4:
	/* 0x39f4: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_39f9:
	/* 0x39f9: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_39fe:
	/* 0x39fe: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3a03:
	/* 0x3a03: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3a09:
	/* 0x3a09: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_3a0e:
	/* 0x3a0e: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3a13:
	/* 0x3a13: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a18:
	/* 0x3a18: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3a1b:
	/* 0x3a1b: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3a21:
	/* 0x3a21: je     3cf8 <kprobe_unwind_ruby+0x3cf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cf8;
	}
x86_l_3a27:
	/* 0x3a27: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3a2c:
	/* 0x3a2c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a2f:
	/* 0x3a2f: je     3cf8 <kprobe_unwind_ruby+0x3cf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cf8;
	}
x86_l_3a35:
	/* 0x3a35: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_3a3a:
	/* 0x3a3a: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3a3d:
	/* 0x3a3d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a42:
	/* 0x3a42: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3a47:
	/* 0x3a47: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3a4d:
	/* 0x3a4d: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_3a52:
	/* 0x3a52: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_3a57:
	/* 0x3a57: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a5c:
	/* 0x3a5c: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3a5f:
	/* 0x3a5f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a62:
	/* 0x3a62: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_3a68:
	/* 0x3a68: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_3a6d:
	/* 0x3a6d: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3a72:
	/* 0x3a72: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3a77:
	/* 0x3a77: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3a7c:
	/* 0x3a7c: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3a82:
	/* 0x3a82: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_3a87:
	/* 0x3a87: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3a8c:
	/* 0x3a8c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a91:
	/* 0x3a91: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3a94:
	/* 0x3a94: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a97:
	/* 0x3a97: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_3a9d:
	/* 0x3a9d: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_3aa2:
	/* 0x3aa2: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3aa7:
	/* 0x3aa7: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3aac:
	/* 0x3aac: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3ab1:
	/* 0x3ab1: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3ab7:
	/* 0x3ab7: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_3abc:
	/* 0x3abc: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3ac1:
	/* 0x3ac1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ac6:
	/* 0x3ac6: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3ac9:
	/* 0x3ac9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3acc:
	/* 0x3acc: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_3ad2:
	/* 0x3ad2: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ad7:
	/* 0x3ad7: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_3ada:
	/* 0x3ada: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_3adf:
	/* 0x3adf: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_3ae4:
	/* 0x3ae4: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3ae7:
	/* 0x3ae7: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_3aeb:
	/* 0x3aeb: je     4542 <kprobe_unwind_ruby+0x4542> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17730ULL;
	}
x86_l_3af1:
	/* 0x3af1: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3af3:
	/* 0x3af3: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_3af6:
	/* 0x3af6: jmp    4546 <kprobe_unwind_ruby+0x4546> */
	return 17734ULL;
x86_l_3afb:
	/* 0x3afb: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3afd:
	/* 0x3afd: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_3aff:
	/* 0x3aff: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3b03:
	/* 0x3b03: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_3b06:
	/* 0x3b06: jbe    3b93 <kprobe_unwind_ruby+0x3b93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3b93;
	}
x86_l_3b0c:
	/* 0x3b0c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3b13:
	/* 0x3b13: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b16:
	/* 0x3b16: je     32be <kprobe_unwind_ruby+0x32be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12990ULL;
	}
x86_l_3b1c:
	/* 0x3b1c: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_3b26:
	/* 0x3b26: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_3b2b:
	/* 0x3b2b: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_3b35:
	/* 0x3b35: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3b3a:
	/* 0x3b3a: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_3b44:
	/* 0x3b44: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3b49:
	/* 0x3b49: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_3b53:
	/* 0x3b53: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3b58:
	/* 0x3b58: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_3b62:
	/* 0x3b62: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3b67:
	/* 0x3b67: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_3b71:
	/* 0x3b71: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b76:
	/* 0x3b76: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b7b:
	/* 0x3b7b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3b80:
	/* 0x3b80: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3b85:
	/* 0x3b85: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_3b8a:
	/* 0x3b8a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b8c:
	/* 0x3b8c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3b8e:
	/* 0x3b8e: jmp    32be <kprobe_unwind_ruby+0x32be> */
	return 12990ULL;
x86_l_3b93:
	/* 0x3b93: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3b9a:
	/* 0x3b9a: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_3b9e:
	/* 0x3b9e: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_3ba4:
	/* 0x3ba4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ba9:
	/* 0x3ba9: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3bac:
	/* 0x3bac: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3bb3:
	/* 0x3bb3: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_3bb7:
	/* 0x3bb7: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3bbe:
	/* 0x3bbe: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3bc5:
	/* 0x3bc5: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_3bcd:
	/* 0x3bcd: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_3bd5:
	/* 0x3bd5: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_3be0:
	/* 0x3be0: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3be3:
	/* 0x3be3: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_3beb:
	/* 0x3beb: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3bf0:
	/* 0x3bf0: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_3bf9:
	/* 0x3bf9: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_3c00:
	/* 0x3c00: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_3c07:
	/* 0x3c07: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_3c0a:
	/* 0x3c0a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c0f:
	/* 0x3c0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c11:
	/* 0x3c11: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3c14:
	/* 0x3c14: je     3c6e <kprobe_unwind_ruby+0x3c6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c6e;
	}
x86_l_3c16:
	/* 0x3c16: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3c19:
	/* 0x3c19: jmp    32be <kprobe_unwind_ruby+0x32be> */
	return 12990ULL;
x86_l_3c1e:
	/* 0x3c1e: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c26:
	/* 0x3c26: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_3c2b:
	/* 0x3c2b: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3c30:
	/* 0x3c30: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3c33:
	/* 0x3c33: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3c38:
	/* 0x3c38: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3c3e:
	/* 0x3c3e: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_3c43:
	/* 0x3c43: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3c48:
	/* 0x3c48: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c4d:
	/* 0x3c4d: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3c50:
	/* 0x3c50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3c53:
	/* 0x3c53: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_3c59:
	/* 0x3c59: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c5c:
	/* 0x3c5c: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_3c5e:
	/* 0x3c5e: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_3c63:
	/* 0x3c63: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_3c69:
	/* 0x3c69: jmp    3998 <kprobe_unwind_ruby+0x3998> */
	goto x86_l_3998;
x86_l_3c6e:
	/* 0x3c6e: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3c75:
	/* 0x3c75: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c78:
	/* 0x3c78: je     32be <kprobe_unwind_ruby+0x32be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12990ULL;
	}
x86_l_3c7e:
	/* 0x3c7e: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_3c88:
	/* 0x3c88: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_3c8d:
	/* 0x3c8d: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_3c97:
	/* 0x3c97: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3c9c:
	/* 0x3c9c: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_3ca6:
	/* 0x3ca6: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3cab:
	/* 0x3cab: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_3cb5:
	/* 0x3cb5: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3cba:
	/* 0x3cba: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_3cc4:
	/* 0x3cc4: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3cc9:
	/* 0x3cc9: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_3cd3:
	/* 0x3cd3: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3cd8:
	/* 0x3cd8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3cdd:
	/* 0x3cdd: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_3ce2:
	/* 0x3ce2: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3ce7:
	/* 0x3ce7: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cea:
	/* 0x3cea: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_3cef:
	/* 0x3cef: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3cf1:
	/* 0x3cf1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3cf3:
	/* 0x3cf3: jmp    32be <kprobe_unwind_ruby+0x32be> */
	return 12990ULL;
x86_l_3cf8:
	/* 0x3cf8: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_3cff:
	/* 0x3cff: jae    3f8b <kprobe_unwind_ruby+0x3f8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 16267ULL;
	}
x86_l_3d05:
	/* 0x3d05: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d0a:
	/* 0x3d0a: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3d0d:
	/* 0x3d0d: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_3d13:
	/* 0x3d13: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_3d18:
	/* 0x3d18: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3d1b:
	/* 0x3d1b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d20:
	/* 0x3d20: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3d29:
	/* 0x3d29: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3d32:
	/* 0x3d32: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_3d37:
	/* 0x3d37: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3d3a:
	/* 0x3d3a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3d3f:
	/* 0x3d3f: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3d44:
	/* 0x3d44: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3d4a:
	/* 0x3d4a: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_3d4f:
	/* 0x3d4f: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3d54:
	/* 0x3d54: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d59:
	/* 0x3d59: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3d5c:
	/* 0x3d5c: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_3d61:
	/* 0x3d61: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3d66:
	/* 0x3d66: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3d6b:
	/* 0x3d6b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3d70:
	/* 0x3d70: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3d76:
	/* 0x3d76: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_3d7b:
	/* 0x3d7b: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3d80:
	/* 0x3d80: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d85:
	/* 0x3d85: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3d88:
	/* 0x3d88: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3d8e:
	/* 0x3d8e: je     4065 <kprobe_unwind_ruby+0x4065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16485ULL;
	}
x86_l_3d94:
	/* 0x3d94: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3d99:
	/* 0x3d99: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3d9c:
	/* 0x3d9c: je     4065 <kprobe_unwind_ruby+0x4065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16485ULL;
	}
x86_l_3da2:
	/* 0x3da2: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_3da7:
	/* 0x3da7: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3daa:
	/* 0x3daa: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3daf:
	/* 0x3daf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3db4:
	/* 0x3db4: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3dba:
	/* 0x3dba: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_3dbf:
	/* 0x3dbf: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_3dc4:
	/* 0x3dc4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3dc9:
	/* 0x3dc9: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3dcc:
	/* 0x3dcc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3dcf:
	/* 0x3dcf: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_3dd5:
	/* 0x3dd5: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_3dda:
	/* 0x3dda: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3ddf:
	/* 0x3ddf: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3de4:
	/* 0x3de4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3de9:
	/* 0x3de9: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3def:
	/* 0x3def: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_3df4:
	/* 0x3df4: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3df9:
	/* 0x3df9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3dfe:
	/* 0x3dfe: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3e01:
	/* 0x3e01: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e04:
	/* 0x3e04: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_3e0a:
	/* 0x3e0a: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_3e0f:
	/* 0x3e0f: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3e14:
	/* 0x3e14: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3e19:
	/* 0x3e19: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3e1e:
	/* 0x3e1e: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3e24:
	/* 0x3e24: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_3e29:
	/* 0x3e29: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3e2e:
	/* 0x3e2e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e33:
	/* 0x3e33: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3e36:
	/* 0x3e36: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e39:
	/* 0x3e39: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_3e3f:
	/* 0x3e3f: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e44:
	/* 0x3e44: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_3e47:
	/* 0x3e47: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_3e4c:
	/* 0x3e4c: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_3e51:
	/* 0x3e51: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3e54:
	/* 0x3e54: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_3e58:
	/* 0x3e58: je     48af <kprobe_unwind_ruby+0x48af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18607ULL;
	}
x86_l_3e5e:
	/* 0x3e5e: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e60:
	/* 0x3e60: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_3e63:
	/* 0x3e63: jmp    48b3 <kprobe_unwind_ruby+0x48b3> */
	return 18611ULL;
x86_l_3e68:
	/* 0x3e68: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e6a:
	/* 0x3e6a: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_3e6c:
	/* 0x3e6c: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3e70:
	/* 0x3e70: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_3e73:
	/* 0x3e73: jbe    3f00 <kprobe_unwind_ruby+0x3f00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3f00;
	}
x86_l_3e79:
	/* 0x3e79: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3e80:
	/* 0x3e80: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e83:
	/* 0x3e83: je     362b <kprobe_unwind_ruby+0x362b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13867ULL;
	}
x86_l_3e89:
	/* 0x3e89: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_3e93:
	/* 0x3e93: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_3e98:
	/* 0x3e98: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_3ea2:
	/* 0x3ea2: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3ea7:
	/* 0x3ea7: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_3eb1:
	/* 0x3eb1: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3eb6:
	/* 0x3eb6: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_3ec0:
	/* 0x3ec0: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3ec5:
	/* 0x3ec5: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_3ecf:
	/* 0x3ecf: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3ed4:
	/* 0x3ed4: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_3ede:
	/* 0x3ede: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ee3:
	/* 0x3ee3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ee8:
	/* 0x3ee8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3eed:
	/* 0x3eed: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3ef2:
	/* 0x3ef2: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_3ef7:
	/* 0x3ef7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ef9:
	/* 0x3ef9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3efb:
	/* 0x3efb: jmp    362b <kprobe_unwind_ruby+0x362b> */
	return 13867ULL;
x86_l_3f00:
	/* 0x3f00: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3f07:
	/* 0x3f07: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
	return 16139ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 16139ULL: goto x86_l_3f0b;
	case 16145ULL: goto x86_l_3f11;
	case 16150ULL: goto x86_l_3f16;
	case 16153ULL: goto x86_l_3f19;
	case 16160ULL: goto x86_l_3f20;
	case 16164ULL: goto x86_l_3f24;
	case 16171ULL: goto x86_l_3f2b;
	case 16178ULL: goto x86_l_3f32;
	case 16186ULL: goto x86_l_3f3a;
	case 16194ULL: goto x86_l_3f42;
	case 16205ULL: goto x86_l_3f4d;
	case 16208ULL: goto x86_l_3f50;
	case 16216ULL: goto x86_l_3f58;
	case 16221ULL: goto x86_l_3f5d;
	case 16230ULL: goto x86_l_3f66;
	case 16237ULL: goto x86_l_3f6d;
	case 16244ULL: goto x86_l_3f74;
	case 16247ULL: goto x86_l_3f77;
	case 16252ULL: goto x86_l_3f7c;
	case 16254ULL: goto x86_l_3f7e;
	case 16257ULL: goto x86_l_3f81;
	case 16259ULL: goto x86_l_3f83;
	case 16262ULL: goto x86_l_3f86;
	case 16267ULL: goto x86_l_3f8b;
	case 16275ULL: goto x86_l_3f93;
	case 16280ULL: goto x86_l_3f98;
	case 16285ULL: goto x86_l_3f9d;
	case 16288ULL: goto x86_l_3fa0;
	case 16293ULL: goto x86_l_3fa5;
	case 16299ULL: goto x86_l_3fab;
	case 16304ULL: goto x86_l_3fb0;
	case 16309ULL: goto x86_l_3fb5;
	case 16314ULL: goto x86_l_3fba;
	case 16317ULL: goto x86_l_3fbd;
	case 16320ULL: goto x86_l_3fc0;
	case 16326ULL: goto x86_l_3fc6;
	case 16329ULL: goto x86_l_3fc9;
	case 16331ULL: goto x86_l_3fcb;
	case 16336ULL: goto x86_l_3fd0;
	case 16342ULL: goto x86_l_3fd6;
	case 16347ULL: goto x86_l_3fdb;
	case 16354ULL: goto x86_l_3fe2;
	case 16357ULL: goto x86_l_3fe5;
	case 16363ULL: goto x86_l_3feb;
	case 16373ULL: goto x86_l_3ff5;
	case 16378ULL: goto x86_l_3ffa;
	case 16388ULL: goto x86_l_4004;
	case 16393ULL: goto x86_l_4009;
	case 16403ULL: goto x86_l_4013;
	case 16408ULL: goto x86_l_4018;
	case 16418ULL: goto x86_l_4022;
	case 16423ULL: goto x86_l_4027;
	case 16433ULL: goto x86_l_4031;
	case 16438ULL: goto x86_l_4036;
	case 16448ULL: goto x86_l_4040;
	case 16453ULL: goto x86_l_4045;
	case 16458ULL: goto x86_l_404a;
	case 16463ULL: goto x86_l_404f;
	case 16468ULL: goto x86_l_4054;
	case 16471ULL: goto x86_l_4057;
	case 16476ULL: goto x86_l_405c;
	case 16478ULL: goto x86_l_405e;
	case 16480ULL: goto x86_l_4060;
	case 16485ULL: goto x86_l_4065;
	case 16492ULL: goto x86_l_406c;
	case 16498ULL: goto x86_l_4072;
	case 16503ULL: goto x86_l_4077;
	case 16506ULL: goto x86_l_407a;
	case 16512ULL: goto x86_l_4080;
	case 16517ULL: goto x86_l_4085;
	case 16520ULL: goto x86_l_4088;
	case 16525ULL: goto x86_l_408d;
	case 16534ULL: goto x86_l_4096;
	case 16543ULL: goto x86_l_409f;
	case 16548ULL: goto x86_l_40a4;
	case 16551ULL: goto x86_l_40a7;
	case 16556ULL: goto x86_l_40ac;
	case 16561ULL: goto x86_l_40b1;
	case 16567ULL: goto x86_l_40b7;
	case 16572ULL: goto x86_l_40bc;
	case 16577ULL: goto x86_l_40c1;
	case 16582ULL: goto x86_l_40c6;
	case 16585ULL: goto x86_l_40c9;
	case 16590ULL: goto x86_l_40ce;
	case 16595ULL: goto x86_l_40d3;
	case 16600ULL: goto x86_l_40d8;
	case 16605ULL: goto x86_l_40dd;
	case 16611ULL: goto x86_l_40e3;
	case 16616ULL: goto x86_l_40e8;
	case 16621ULL: goto x86_l_40ed;
	case 16626ULL: goto x86_l_40f2;
	case 16629ULL: goto x86_l_40f5;
	case 16635ULL: goto x86_l_40fb;
	case 16641ULL: goto x86_l_4101;
	case 16646ULL: goto x86_l_4106;
	case 16649ULL: goto x86_l_4109;
	case 16655ULL: goto x86_l_410f;
	case 16660ULL: goto x86_l_4114;
	case 16663ULL: goto x86_l_4117;
	case 16668ULL: goto x86_l_411c;
	case 16673ULL: goto x86_l_4121;
	case 16679ULL: goto x86_l_4127;
	case 16684ULL: goto x86_l_412c;
	case 16689ULL: goto x86_l_4131;
	case 16694ULL: goto x86_l_4136;
	case 16697ULL: goto x86_l_4139;
	case 16700ULL: goto x86_l_413c;
	case 16706ULL: goto x86_l_4142;
	case 16711ULL: goto x86_l_4147;
	case 16716ULL: goto x86_l_414c;
	case 16721ULL: goto x86_l_4151;
	case 16726ULL: goto x86_l_4156;
	case 16732ULL: goto x86_l_415c;
	case 16737ULL: goto x86_l_4161;
	case 16742ULL: goto x86_l_4166;
	case 16747ULL: goto x86_l_416b;
	case 16750ULL: goto x86_l_416e;
	case 16753ULL: goto x86_l_4171;
	case 16759ULL: goto x86_l_4177;
	case 16764ULL: goto x86_l_417c;
	case 16769ULL: goto x86_l_4181;
	case 16774ULL: goto x86_l_4186;
	case 16779ULL: goto x86_l_418b;
	case 16785ULL: goto x86_l_4191;
	case 16790ULL: goto x86_l_4196;
	case 16795ULL: goto x86_l_419b;
	case 16800ULL: goto x86_l_41a0;
	case 16803ULL: goto x86_l_41a3;
	case 16806ULL: goto x86_l_41a6;
	case 16812ULL: goto x86_l_41ac;
	case 16817ULL: goto x86_l_41b1;
	case 16820ULL: goto x86_l_41b4;
	case 16825ULL: goto x86_l_41b9;
	case 16830ULL: goto x86_l_41be;
	case 16833ULL: goto x86_l_41c1;
	case 16837ULL: goto x86_l_41c5;
	case 16843ULL: goto x86_l_41cb;
	case 16845ULL: goto x86_l_41cd;
	case 16848ULL: goto x86_l_41d0;
	case 16853ULL: goto x86_l_41d5;
	case 16855ULL: goto x86_l_41d7;
	case 16857ULL: goto x86_l_41d9;
	case 16861ULL: goto x86_l_41dd;
	case 16864ULL: goto x86_l_41e0;
	case 16870ULL: goto x86_l_41e6;
	case 16877ULL: goto x86_l_41ed;
	case 16880ULL: goto x86_l_41f0;
	case 16886ULL: goto x86_l_41f6;
	case 16896ULL: goto x86_l_4200;
	case 16901ULL: goto x86_l_4205;
	case 16911ULL: goto x86_l_420f;
	case 16916ULL: goto x86_l_4214;
	case 16926ULL: goto x86_l_421e;
	case 16931ULL: goto x86_l_4223;
	case 16941ULL: goto x86_l_422d;
	case 16946ULL: goto x86_l_4232;
	case 16956ULL: goto x86_l_423c;
	case 16961ULL: goto x86_l_4241;
	case 16971ULL: goto x86_l_424b;
	case 16976ULL: goto x86_l_4250;
	case 16981ULL: goto x86_l_4255;
	case 16986ULL: goto x86_l_425a;
	case 16991ULL: goto x86_l_425f;
	case 16996ULL: goto x86_l_4264;
	case 16998ULL: goto x86_l_4266;
	case 17000ULL: goto x86_l_4268;
	case 17005ULL: goto x86_l_426d;
	case 17012ULL: goto x86_l_4274;
	case 17016ULL: goto x86_l_4278;
	case 17022ULL: goto x86_l_427e;
	case 17027ULL: goto x86_l_4283;
	case 17030ULL: goto x86_l_4286;
	case 17037ULL: goto x86_l_428d;
	case 17041ULL: goto x86_l_4291;
	case 17048ULL: goto x86_l_4298;
	case 17055ULL: goto x86_l_429f;
	case 17063ULL: goto x86_l_42a7;
	case 17071ULL: goto x86_l_42af;
	case 17082ULL: goto x86_l_42ba;
	case 17085ULL: goto x86_l_42bd;
	case 17093ULL: goto x86_l_42c5;
	case 17098ULL: goto x86_l_42ca;
	case 17107ULL: goto x86_l_42d3;
	case 17114ULL: goto x86_l_42da;
	case 17121ULL: goto x86_l_42e1;
	case 17124ULL: goto x86_l_42e4;
	case 17129ULL: goto x86_l_42e9;
	case 17131ULL: goto x86_l_42eb;
	case 17134ULL: goto x86_l_42ee;
	case 17136ULL: goto x86_l_42f0;
	case 17139ULL: goto x86_l_42f3;
	case 17144ULL: goto x86_l_42f8;
	case 17152ULL: goto x86_l_4300;
	case 17157ULL: goto x86_l_4305;
	case 17162ULL: goto x86_l_430a;
	case 17165ULL: goto x86_l_430d;
	case 17170ULL: goto x86_l_4312;
	case 17176ULL: goto x86_l_4318;
	case 17181ULL: goto x86_l_431d;
	case 17186ULL: goto x86_l_4322;
	case 17191ULL: goto x86_l_4327;
	case 17194ULL: goto x86_l_432a;
	case 17197ULL: goto x86_l_432d;
	case 17203ULL: goto x86_l_4333;
	case 17206ULL: goto x86_l_4336;
	case 17208ULL: goto x86_l_4338;
	case 17213ULL: goto x86_l_433d;
	case 17219ULL: goto x86_l_4343;
	case 17224ULL: goto x86_l_4348;
	case 17231ULL: goto x86_l_434f;
	case 17234ULL: goto x86_l_4352;
	case 17240ULL: goto x86_l_4358;
	case 17250ULL: goto x86_l_4362;
	case 17255ULL: goto x86_l_4367;
	case 17265ULL: goto x86_l_4371;
	case 17270ULL: goto x86_l_4376;
	case 17280ULL: goto x86_l_4380;
	case 17285ULL: goto x86_l_4385;
	case 17295ULL: goto x86_l_438f;
	case 17300ULL: goto x86_l_4394;
	case 17310ULL: goto x86_l_439e;
	case 17315ULL: goto x86_l_43a3;
	case 17325ULL: goto x86_l_43ad;
	case 17330ULL: goto x86_l_43b2;
	case 17335ULL: goto x86_l_43b7;
	case 17340ULL: goto x86_l_43bc;
	case 17345ULL: goto x86_l_43c1;
	case 17348ULL: goto x86_l_43c4;
	case 17353ULL: goto x86_l_43c9;
	case 17355ULL: goto x86_l_43cb;
	case 17357ULL: goto x86_l_43cd;
	case 17362ULL: goto x86_l_43d2;
	case 17369ULL: goto x86_l_43d9;
	case 17375ULL: goto x86_l_43df;
	case 17380ULL: goto x86_l_43e4;
	case 17383ULL: goto x86_l_43e7;
	case 17389ULL: goto x86_l_43ed;
	case 17394ULL: goto x86_l_43f2;
	case 17397ULL: goto x86_l_43f5;
	case 17402ULL: goto x86_l_43fa;
	case 17411ULL: goto x86_l_4403;
	case 17420ULL: goto x86_l_440c;
	case 17425ULL: goto x86_l_4411;
	case 17428ULL: goto x86_l_4414;
	case 17433ULL: goto x86_l_4419;
	case 17438ULL: goto x86_l_441e;
	case 17444ULL: goto x86_l_4424;
	case 17449ULL: goto x86_l_4429;
	case 17454ULL: goto x86_l_442e;
	case 17459ULL: goto x86_l_4433;
	case 17462ULL: goto x86_l_4436;
	case 17467ULL: goto x86_l_443b;
	case 17472ULL: goto x86_l_4440;
	case 17477ULL: goto x86_l_4445;
	case 17482ULL: goto x86_l_444a;
	case 17488ULL: goto x86_l_4450;
	case 17493ULL: goto x86_l_4455;
	case 17498ULL: goto x86_l_445a;
	case 17503ULL: goto x86_l_445f;
	case 17506ULL: goto x86_l_4462;
	case 17512ULL: goto x86_l_4468;
	case 17518ULL: goto x86_l_446e;
	case 17523ULL: goto x86_l_4473;
	case 17526ULL: goto x86_l_4476;
	case 17532ULL: goto x86_l_447c;
	case 17537ULL: goto x86_l_4481;
	case 17540ULL: goto x86_l_4484;
	case 17545ULL: goto x86_l_4489;
	case 17550ULL: goto x86_l_448e;
	case 17556ULL: goto x86_l_4494;
	case 17561ULL: goto x86_l_4499;
	case 17566ULL: goto x86_l_449e;
	case 17571ULL: goto x86_l_44a3;
	case 17574ULL: goto x86_l_44a6;
	case 17577ULL: goto x86_l_44a9;
	case 17583ULL: goto x86_l_44af;
	case 17588ULL: goto x86_l_44b4;
	case 17593ULL: goto x86_l_44b9;
	case 17598ULL: goto x86_l_44be;
	case 17603ULL: goto x86_l_44c3;
	case 17609ULL: goto x86_l_44c9;
	case 17614ULL: goto x86_l_44ce;
	case 17619ULL: goto x86_l_44d3;
	case 17624ULL: goto x86_l_44d8;
	case 17627ULL: goto x86_l_44db;
	case 17630ULL: goto x86_l_44de;
	case 17636ULL: goto x86_l_44e4;
	case 17641ULL: goto x86_l_44e9;
	case 17646ULL: goto x86_l_44ee;
	case 17651ULL: goto x86_l_44f3;
	case 17656ULL: goto x86_l_44f8;
	case 17662ULL: goto x86_l_44fe;
	case 17667ULL: goto x86_l_4503;
	case 17672ULL: goto x86_l_4508;
	case 17677ULL: goto x86_l_450d;
	case 17680ULL: goto x86_l_4510;
	case 17683ULL: goto x86_l_4513;
	case 17689ULL: goto x86_l_4519;
	case 17694ULL: goto x86_l_451e;
	case 17697ULL: goto x86_l_4521;
	case 17702ULL: goto x86_l_4526;
	case 17707ULL: goto x86_l_452b;
	case 17710ULL: goto x86_l_452e;
	case 17714ULL: goto x86_l_4532;
	case 17720ULL: goto x86_l_4538;
	case 17722ULL: goto x86_l_453a;
	case 17725ULL: goto x86_l_453d;
	case 17730ULL: goto x86_l_4542;
	case 17732ULL: goto x86_l_4544;
	case 17734ULL: goto x86_l_4546;
	case 17738ULL: goto x86_l_454a;
	case 17741ULL: goto x86_l_454d;
	case 17747ULL: goto x86_l_4553;
	case 17754ULL: goto x86_l_455a;
	case 17757ULL: goto x86_l_455d;
	case 17763ULL: goto x86_l_4563;
	case 17773ULL: goto x86_l_456d;
	case 17778ULL: goto x86_l_4572;
	case 17788ULL: goto x86_l_457c;
	case 17793ULL: goto x86_l_4581;
	case 17803ULL: goto x86_l_458b;
	case 17808ULL: goto x86_l_4590;
	case 17818ULL: goto x86_l_459a;
	case 17823ULL: goto x86_l_459f;
	case 17833ULL: goto x86_l_45a9;
	case 17838ULL: goto x86_l_45ae;
	case 17848ULL: goto x86_l_45b8;
	case 17853ULL: goto x86_l_45bd;
	case 17858ULL: goto x86_l_45c2;
	case 17863ULL: goto x86_l_45c7;
	case 17868ULL: goto x86_l_45cc;
	case 17873ULL: goto x86_l_45d1;
	case 17875ULL: goto x86_l_45d3;
	case 17877ULL: goto x86_l_45d5;
	case 17882ULL: goto x86_l_45da;
	case 17889ULL: goto x86_l_45e1;
	case 17893ULL: goto x86_l_45e5;
	case 17899ULL: goto x86_l_45eb;
	case 17904ULL: goto x86_l_45f0;
	case 17907ULL: goto x86_l_45f3;
	case 17914ULL: goto x86_l_45fa;
	case 17918ULL: goto x86_l_45fe;
	case 17925ULL: goto x86_l_4605;
	case 17932ULL: goto x86_l_460c;
	case 17940ULL: goto x86_l_4614;
	case 17948ULL: goto x86_l_461c;
	case 17959ULL: goto x86_l_4627;
	case 17962ULL: goto x86_l_462a;
	case 17970ULL: goto x86_l_4632;
	case 17975ULL: goto x86_l_4637;
	case 17984ULL: goto x86_l_4640;
	case 17991ULL: goto x86_l_4647;
	case 17998ULL: goto x86_l_464e;
	case 18001ULL: goto x86_l_4651;
	case 18006ULL: goto x86_l_4656;
	case 18008ULL: goto x86_l_4658;
	case 18011ULL: goto x86_l_465b;
	case 18013ULL: goto x86_l_465d;
	case 18016ULL: goto x86_l_4660;
	case 18021ULL: goto x86_l_4665;
	case 18029ULL: goto x86_l_466d;
	case 18034ULL: goto x86_l_4672;
	case 18039ULL: goto x86_l_4677;
	case 18042ULL: goto x86_l_467a;
	case 18047ULL: goto x86_l_467f;
	case 18053ULL: goto x86_l_4685;
	case 18058ULL: goto x86_l_468a;
	case 18063ULL: goto x86_l_468f;
	case 18068ULL: goto x86_l_4694;
	case 18071ULL: goto x86_l_4697;
	case 18074ULL: goto x86_l_469a;
	case 18080ULL: goto x86_l_46a0;
	case 18083ULL: goto x86_l_46a3;
	case 18085ULL: goto x86_l_46a5;
	case 18090ULL: goto x86_l_46aa;
	case 18096ULL: goto x86_l_46b0;
	case 18101ULL: goto x86_l_46b5;
	case 18108ULL: goto x86_l_46bc;
	case 18111ULL: goto x86_l_46bf;
	case 18117ULL: goto x86_l_46c5;
	case 18127ULL: goto x86_l_46cf;
	case 18132ULL: goto x86_l_46d4;
	case 18142ULL: goto x86_l_46de;
	case 18147ULL: goto x86_l_46e3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3f0b:
	/* 0x3f0b: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_3f11:
	/* 0x3f11: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f16:
	/* 0x3f16: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3f19:
	/* 0x3f19: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3f20:
	/* 0x3f20: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_3f24:
	/* 0x3f24: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3f2b:
	/* 0x3f2b: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f32:
	/* 0x3f32: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_3f3a:
	/* 0x3f3a: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_3f42:
	/* 0x3f42: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_3f4d:
	/* 0x3f4d: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f50:
	/* 0x3f50: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_3f58:
	/* 0x3f58: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3f5d:
	/* 0x3f5d: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_3f66:
	/* 0x3f66: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_3f6d:
	/* 0x3f6d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_3f74:
	/* 0x3f74: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_3f77:
	/* 0x3f77: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3f7c:
	/* 0x3f7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f7e:
	/* 0x3f7e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f81:
	/* 0x3f81: je     3fdb <kprobe_unwind_ruby+0x3fdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fdb;
	}
x86_l_3f83:
	/* 0x3f83: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3f86:
	/* 0x3f86: jmp    362b <kprobe_unwind_ruby+0x362b> */
	return 13867ULL;
x86_l_3f8b:
	/* 0x3f8b: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f93:
	/* 0x3f93: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_3f98:
	/* 0x3f98: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3f9d:
	/* 0x3f9d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3fa0:
	/* 0x3fa0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3fa5:
	/* 0x3fa5: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3fab:
	/* 0x3fab: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_3fb0:
	/* 0x3fb0: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3fb5:
	/* 0x3fb5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3fba:
	/* 0x3fba: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3fbd:
	/* 0x3fbd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3fc0:
	/* 0x3fc0: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_3fc6:
	/* 0x3fc6: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fc9:
	/* 0x3fc9: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_3fcb:
	/* 0x3fcb: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_3fd0:
	/* 0x3fd0: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_3fd6:
	/* 0x3fd6: jmp    3d05 <kprobe_unwind_ruby+0x3d05> */
	return 15621ULL;
x86_l_3fdb:
	/* 0x3fdb: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3fe2:
	/* 0x3fe2: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fe5:
	/* 0x3fe5: je     362b <kprobe_unwind_ruby+0x362b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13867ULL;
	}
x86_l_3feb:
	/* 0x3feb: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_3ff5:
	/* 0x3ff5: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_3ffa:
	/* 0x3ffa: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_4004:
	/* 0x4004: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4009:
	/* 0x4009: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_4013:
	/* 0x4013: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4018:
	/* 0x4018: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_4022:
	/* 0x4022: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4027:
	/* 0x4027: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_4031:
	/* 0x4031: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4036:
	/* 0x4036: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_4040:
	/* 0x4040: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4045:
	/* 0x4045: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_404a:
	/* 0x404a: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_404f:
	/* 0x404f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4054:
	/* 0x4054: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4057:
	/* 0x4057: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_405c:
	/* 0x405c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_405e:
	/* 0x405e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4060:
	/* 0x4060: jmp    362b <kprobe_unwind_ruby+0x362b> */
	return 13867ULL;
x86_l_4065:
	/* 0x4065: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_406c:
	/* 0x406c: jae    42f8 <kprobe_unwind_ruby+0x42f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_42f8;
	}
x86_l_4072:
	/* 0x4072: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4077:
	/* 0x4077: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_407a:
	/* 0x407a: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_4080:
	/* 0x4080: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_4085:
	/* 0x4085: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4088:
	/* 0x4088: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_408d:
	/* 0x408d: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4096:
	/* 0x4096: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_409f:
	/* 0x409f: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_40a4:
	/* 0x40a4: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_40a7:
	/* 0x40a7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_40ac:
	/* 0x40ac: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_40b1:
	/* 0x40b1: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_40b7:
	/* 0x40b7: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_40bc:
	/* 0x40bc: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_40c1:
	/* 0x40c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40c6:
	/* 0x40c6: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_40c9:
	/* 0x40c9: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_40ce:
	/* 0x40ce: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_40d3:
	/* 0x40d3: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_40d8:
	/* 0x40d8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_40dd:
	/* 0x40dd: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_40e3:
	/* 0x40e3: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_40e8:
	/* 0x40e8: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_40ed:
	/* 0x40ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40f2:
	/* 0x40f2: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_40f5:
	/* 0x40f5: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_40fb:
	/* 0x40fb: je     43d2 <kprobe_unwind_ruby+0x43d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43d2;
	}
x86_l_4101:
	/* 0x4101: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4106:
	/* 0x4106: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4109:
	/* 0x4109: je     43d2 <kprobe_unwind_ruby+0x43d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43d2;
	}
x86_l_410f:
	/* 0x410f: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_4114:
	/* 0x4114: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4117:
	/* 0x4117: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_411c:
	/* 0x411c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4121:
	/* 0x4121: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4127:
	/* 0x4127: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_412c:
	/* 0x412c: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_4131:
	/* 0x4131: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4136:
	/* 0x4136: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4139:
	/* 0x4139: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_413c:
	/* 0x413c: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_4142:
	/* 0x4142: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_4147:
	/* 0x4147: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_414c:
	/* 0x414c: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4151:
	/* 0x4151: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4156:
	/* 0x4156: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_415c:
	/* 0x415c: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_4161:
	/* 0x4161: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4166:
	/* 0x4166: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_416b:
	/* 0x416b: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_416e:
	/* 0x416e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4171:
	/* 0x4171: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_4177:
	/* 0x4177: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_417c:
	/* 0x417c: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4181:
	/* 0x4181: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_4186:
	/* 0x4186: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_418b:
	/* 0x418b: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4191:
	/* 0x4191: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_4196:
	/* 0x4196: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_419b:
	/* 0x419b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_41a0:
	/* 0x41a0: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_41a3:
	/* 0x41a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_41a6:
	/* 0x41a6: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_41ac:
	/* 0x41ac: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_41b1:
	/* 0x41b1: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_41b4:
	/* 0x41b4: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_41b9:
	/* 0x41b9: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_41be:
	/* 0x41be: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_41c1:
	/* 0x41c1: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_41c5:
	/* 0x41c5: je     4b09 <kprobe_unwind_ruby+0x4b09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19209ULL;
	}
x86_l_41cb:
	/* 0x41cb: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_41cd:
	/* 0x41cd: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_41d0:
	/* 0x41d0: jmp    4b0d <kprobe_unwind_ruby+0x4b0d> */
	return 19213ULL;
x86_l_41d5:
	/* 0x41d5: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_41d7:
	/* 0x41d7: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_41d9:
	/* 0x41d9: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_41dd:
	/* 0x41dd: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_41e0:
	/* 0x41e0: jbe    426d <kprobe_unwind_ruby+0x426d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_426d;
	}
x86_l_41e6:
	/* 0x41e6: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_41ed:
	/* 0x41ed: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41f0:
	/* 0x41f0: je     3998 <kprobe_unwind_ruby+0x3998> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14744ULL;
	}
x86_l_41f6:
	/* 0x41f6: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_4200:
	/* 0x4200: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_4205:
	/* 0x4205: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_420f:
	/* 0x420f: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4214:
	/* 0x4214: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_421e:
	/* 0x421e: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4223:
	/* 0x4223: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_422d:
	/* 0x422d: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4232:
	/* 0x4232: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_423c:
	/* 0x423c: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4241:
	/* 0x4241: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_424b:
	/* 0x424b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4250:
	/* 0x4250: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4255:
	/* 0x4255: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_425a:
	/* 0x425a: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_425f:
	/* 0x425f: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_4264:
	/* 0x4264: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4266:
	/* 0x4266: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4268:
	/* 0x4268: jmp    3998 <kprobe_unwind_ruby+0x3998> */
	return 14744ULL;
x86_l_426d:
	/* 0x426d: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_4274:
	/* 0x4274: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_4278:
	/* 0x4278: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_427e:
	/* 0x427e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4283:
	/* 0x4283: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4286:
	/* 0x4286: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_428d:
	/* 0x428d: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_4291:
	/* 0x4291: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_4298:
	/* 0x4298: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_429f:
	/* 0x429f: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_42a7:
	/* 0x42a7: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_42af:
	/* 0x42af: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_42ba:
	/* 0x42ba: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42bd:
	/* 0x42bd: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_42c5:
	/* 0x42c5: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_42ca:
	/* 0x42ca: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_42d3:
	/* 0x42d3: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_42da:
	/* 0x42da: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_42e1:
	/* 0x42e1: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_42e4:
	/* 0x42e4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_42e9:
	/* 0x42e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42eb:
	/* 0x42eb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_42ee:
	/* 0x42ee: je     4348 <kprobe_unwind_ruby+0x4348> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4348;
	}
x86_l_42f0:
	/* 0x42f0: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_42f3:
	/* 0x42f3: jmp    3998 <kprobe_unwind_ruby+0x3998> */
	return 14744ULL;
x86_l_42f8:
	/* 0x42f8: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4300:
	/* 0x4300: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_4305:
	/* 0x4305: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_430a:
	/* 0x430a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_430d:
	/* 0x430d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4312:
	/* 0x4312: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4318:
	/* 0x4318: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_431d:
	/* 0x431d: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4322:
	/* 0x4322: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4327:
	/* 0x4327: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_432a:
	/* 0x432a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_432d:
	/* 0x432d: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_4333:
	/* 0x4333: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4336:
	/* 0x4336: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_4338:
	/* 0x4338: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_433d:
	/* 0x433d: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_4343:
	/* 0x4343: jmp    4072 <kprobe_unwind_ruby+0x4072> */
	goto x86_l_4072;
x86_l_4348:
	/* 0x4348: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_434f:
	/* 0x434f: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4352:
	/* 0x4352: je     3998 <kprobe_unwind_ruby+0x3998> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14744ULL;
	}
x86_l_4358:
	/* 0x4358: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_4362:
	/* 0x4362: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_4367:
	/* 0x4367: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_4371:
	/* 0x4371: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4376:
	/* 0x4376: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_4380:
	/* 0x4380: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4385:
	/* 0x4385: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_438f:
	/* 0x438f: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4394:
	/* 0x4394: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_439e:
	/* 0x439e: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_43a3:
	/* 0x43a3: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_43ad:
	/* 0x43ad: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_43b2:
	/* 0x43b2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_43b7:
	/* 0x43b7: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_43bc:
	/* 0x43bc: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_43c1:
	/* 0x43c1: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43c4:
	/* 0x43c4: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_43c9:
	/* 0x43c9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_43cb:
	/* 0x43cb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_43cd:
	/* 0x43cd: jmp    3998 <kprobe_unwind_ruby+0x3998> */
	return 14744ULL;
x86_l_43d2:
	/* 0x43d2: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_43d9:
	/* 0x43d9: jae    4665 <kprobe_unwind_ruby+0x4665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4665;
	}
x86_l_43df:
	/* 0x43df: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43e4:
	/* 0x43e4: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_43e7:
	/* 0x43e7: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_43ed:
	/* 0x43ed: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_43f2:
	/* 0x43f2: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_43f5:
	/* 0x43f5: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43fa:
	/* 0x43fa: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4403:
	/* 0x4403: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_440c:
	/* 0x440c: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_4411:
	/* 0x4411: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4414:
	/* 0x4414: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4419:
	/* 0x4419: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_441e:
	/* 0x441e: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4424:
	/* 0x4424: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_4429:
	/* 0x4429: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_442e:
	/* 0x442e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4433:
	/* 0x4433: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4436:
	/* 0x4436: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_443b:
	/* 0x443b: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4440:
	/* 0x4440: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4445:
	/* 0x4445: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_444a:
	/* 0x444a: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4450:
	/* 0x4450: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_4455:
	/* 0x4455: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_445a:
	/* 0x445a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_445f:
	/* 0x445f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4462:
	/* 0x4462: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4468:
	/* 0x4468: je     473f <kprobe_unwind_ruby+0x473f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18239ULL;
	}
x86_l_446e:
	/* 0x446e: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4473:
	/* 0x4473: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4476:
	/* 0x4476: je     473f <kprobe_unwind_ruby+0x473f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18239ULL;
	}
x86_l_447c:
	/* 0x447c: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_4481:
	/* 0x4481: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4484:
	/* 0x4484: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4489:
	/* 0x4489: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_448e:
	/* 0x448e: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4494:
	/* 0x4494: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_4499:
	/* 0x4499: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_449e:
	/* 0x449e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44a3:
	/* 0x44a3: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_44a6:
	/* 0x44a6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_44a9:
	/* 0x44a9: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_44af:
	/* 0x44af: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_44b4:
	/* 0x44b4: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_44b9:
	/* 0x44b9: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_44be:
	/* 0x44be: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_44c3:
	/* 0x44c3: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_44c9:
	/* 0x44c9: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_44ce:
	/* 0x44ce: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_44d3:
	/* 0x44d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44d8:
	/* 0x44d8: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_44db:
	/* 0x44db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_44de:
	/* 0x44de: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_44e4:
	/* 0x44e4: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_44e9:
	/* 0x44e9: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_44ee:
	/* 0x44ee: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_44f3:
	/* 0x44f3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_44f8:
	/* 0x44f8: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_44fe:
	/* 0x44fe: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_4503:
	/* 0x4503: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4508:
	/* 0x4508: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_450d:
	/* 0x450d: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4510:
	/* 0x4510: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4513:
	/* 0x4513: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_4519:
	/* 0x4519: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_451e:
	/* 0x451e: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_4521:
	/* 0x4521: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_4526:
	/* 0x4526: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_452b:
	/* 0x452b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_452e:
	/* 0x452e: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_4532:
	/* 0x4532: je     4c30 <kprobe_unwind_ruby+0x4c30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19504ULL;
	}
x86_l_4538:
	/* 0x4538: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_453a:
	/* 0x453a: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_453d:
	/* 0x453d: jmp    4c34 <kprobe_unwind_ruby+0x4c34> */
	return 19508ULL;
x86_l_4542:
	/* 0x4542: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4544:
	/* 0x4544: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_4546:
	/* 0x4546: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_454a:
	/* 0x454a: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_454d:
	/* 0x454d: jbe    45da <kprobe_unwind_ruby+0x45da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_45da;
	}
x86_l_4553:
	/* 0x4553: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_455a:
	/* 0x455a: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_455d:
	/* 0x455d: je     3d05 <kprobe_unwind_ruby+0x3d05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15621ULL;
	}
x86_l_4563:
	/* 0x4563: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_456d:
	/* 0x456d: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_4572:
	/* 0x4572: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_457c:
	/* 0x457c: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4581:
	/* 0x4581: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_458b:
	/* 0x458b: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4590:
	/* 0x4590: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_459a:
	/* 0x459a: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_459f:
	/* 0x459f: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_45a9:
	/* 0x45a9: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_45ae:
	/* 0x45ae: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_45b8:
	/* 0x45b8: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_45bd:
	/* 0x45bd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_45c2:
	/* 0x45c2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_45c7:
	/* 0x45c7: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_45cc:
	/* 0x45cc: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_45d1:
	/* 0x45d1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_45d3:
	/* 0x45d3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_45d5:
	/* 0x45d5: jmp    3d05 <kprobe_unwind_ruby+0x3d05> */
	return 15621ULL;
x86_l_45da:
	/* 0x45da: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_45e1:
	/* 0x45e1: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_45e5:
	/* 0x45e5: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_45eb:
	/* 0x45eb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45f0:
	/* 0x45f0: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_45f3:
	/* 0x45f3: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_45fa:
	/* 0x45fa: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_45fe:
	/* 0x45fe: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_4605:
	/* 0x4605: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_460c:
	/* 0x460c: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_4614:
	/* 0x4614: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_461c:
	/* 0x461c: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_4627:
	/* 0x4627: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_462a:
	/* 0x462a: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_4632:
	/* 0x4632: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4637:
	/* 0x4637: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_4640:
	/* 0x4640: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_4647:
	/* 0x4647: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_464e:
	/* 0x464e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4651:
	/* 0x4651: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4656:
	/* 0x4656: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4658:
	/* 0x4658: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_465b:
	/* 0x465b: je     46b5 <kprobe_unwind_ruby+0x46b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46b5;
	}
x86_l_465d:
	/* 0x465d: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4660:
	/* 0x4660: jmp    3d05 <kprobe_unwind_ruby+0x3d05> */
	return 15621ULL;
x86_l_4665:
	/* 0x4665: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_466d:
	/* 0x466d: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_4672:
	/* 0x4672: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4677:
	/* 0x4677: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_467a:
	/* 0x467a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_467f:
	/* 0x467f: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4685:
	/* 0x4685: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_468a:
	/* 0x468a: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_468f:
	/* 0x468f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4694:
	/* 0x4694: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4697:
	/* 0x4697: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_469a:
	/* 0x469a: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_46a0:
	/* 0x46a0: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46a3:
	/* 0x46a3: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_46a5:
	/* 0x46a5: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_46aa:
	/* 0x46aa: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_46b0:
	/* 0x46b0: jmp    43df <kprobe_unwind_ruby+0x43df> */
	goto x86_l_43df;
x86_l_46b5:
	/* 0x46b5: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_46bc:
	/* 0x46bc: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46bf:
	/* 0x46bf: je     3d05 <kprobe_unwind_ruby+0x3d05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15621ULL;
	}
x86_l_46c5:
	/* 0x46c5: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_46cf:
	/* 0x46cf: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_46d4:
	/* 0x46d4: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_46de:
	/* 0x46de: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_46e3:
	/* 0x46e3: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
	return 18157ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 18157ULL: goto x86_l_46ed;
	case 18162ULL: goto x86_l_46f2;
	case 18172ULL: goto x86_l_46fc;
	case 18177ULL: goto x86_l_4701;
	case 18187ULL: goto x86_l_470b;
	case 18192ULL: goto x86_l_4710;
	case 18202ULL: goto x86_l_471a;
	case 18207ULL: goto x86_l_471f;
	case 18212ULL: goto x86_l_4724;
	case 18217ULL: goto x86_l_4729;
	case 18222ULL: goto x86_l_472e;
	case 18225ULL: goto x86_l_4731;
	case 18230ULL: goto x86_l_4736;
	case 18232ULL: goto x86_l_4738;
	case 18234ULL: goto x86_l_473a;
	case 18239ULL: goto x86_l_473f;
	case 18246ULL: goto x86_l_4746;
	case 18252ULL: goto x86_l_474c;
	case 18257ULL: goto x86_l_4751;
	case 18260ULL: goto x86_l_4754;
	case 18266ULL: goto x86_l_475a;
	case 18271ULL: goto x86_l_475f;
	case 18274ULL: goto x86_l_4762;
	case 18279ULL: goto x86_l_4767;
	case 18288ULL: goto x86_l_4770;
	case 18297ULL: goto x86_l_4779;
	case 18302ULL: goto x86_l_477e;
	case 18305ULL: goto x86_l_4781;
	case 18310ULL: goto x86_l_4786;
	case 18315ULL: goto x86_l_478b;
	case 18321ULL: goto x86_l_4791;
	case 18326ULL: goto x86_l_4796;
	case 18331ULL: goto x86_l_479b;
	case 18336ULL: goto x86_l_47a0;
	case 18339ULL: goto x86_l_47a3;
	case 18344ULL: goto x86_l_47a8;
	case 18349ULL: goto x86_l_47ad;
	case 18354ULL: goto x86_l_47b2;
	case 18359ULL: goto x86_l_47b7;
	case 18365ULL: goto x86_l_47bd;
	case 18370ULL: goto x86_l_47c2;
	case 18375ULL: goto x86_l_47c7;
	case 18380ULL: goto x86_l_47cc;
	case 18383ULL: goto x86_l_47cf;
	case 18389ULL: goto x86_l_47d5;
	case 18395ULL: goto x86_l_47db;
	case 18400ULL: goto x86_l_47e0;
	case 18403ULL: goto x86_l_47e3;
	case 18409ULL: goto x86_l_47e9;
	case 18414ULL: goto x86_l_47ee;
	case 18417ULL: goto x86_l_47f1;
	case 18422ULL: goto x86_l_47f6;
	case 18427ULL: goto x86_l_47fb;
	case 18433ULL: goto x86_l_4801;
	case 18438ULL: goto x86_l_4806;
	case 18443ULL: goto x86_l_480b;
	case 18448ULL: goto x86_l_4810;
	case 18451ULL: goto x86_l_4813;
	case 18454ULL: goto x86_l_4816;
	case 18460ULL: goto x86_l_481c;
	case 18465ULL: goto x86_l_4821;
	case 18470ULL: goto x86_l_4826;
	case 18475ULL: goto x86_l_482b;
	case 18480ULL: goto x86_l_4830;
	case 18486ULL: goto x86_l_4836;
	case 18491ULL: goto x86_l_483b;
	case 18496ULL: goto x86_l_4840;
	case 18501ULL: goto x86_l_4845;
	case 18504ULL: goto x86_l_4848;
	case 18507ULL: goto x86_l_484b;
	case 18513ULL: goto x86_l_4851;
	case 18518ULL: goto x86_l_4856;
	case 18523ULL: goto x86_l_485b;
	case 18528ULL: goto x86_l_4860;
	case 18533ULL: goto x86_l_4865;
	case 18539ULL: goto x86_l_486b;
	case 18544ULL: goto x86_l_4870;
	case 18549ULL: goto x86_l_4875;
	case 18554ULL: goto x86_l_487a;
	case 18557ULL: goto x86_l_487d;
	case 18560ULL: goto x86_l_4880;
	case 18566ULL: goto x86_l_4886;
	case 18571ULL: goto x86_l_488b;
	case 18574ULL: goto x86_l_488e;
	case 18579ULL: goto x86_l_4893;
	case 18584ULL: goto x86_l_4898;
	case 18587ULL: goto x86_l_489b;
	case 18591ULL: goto x86_l_489f;
	case 18597ULL: goto x86_l_48a5;
	case 18599ULL: goto x86_l_48a7;
	case 18602ULL: goto x86_l_48aa;
	case 18607ULL: goto x86_l_48af;
	case 18609ULL: goto x86_l_48b1;
	case 18611ULL: goto x86_l_48b3;
	case 18615ULL: goto x86_l_48b7;
	case 18618ULL: goto x86_l_48ba;
	case 18624ULL: goto x86_l_48c0;
	case 18631ULL: goto x86_l_48c7;
	case 18634ULL: goto x86_l_48ca;
	case 18640ULL: goto x86_l_48d0;
	case 18650ULL: goto x86_l_48da;
	case 18655ULL: goto x86_l_48df;
	case 18665ULL: goto x86_l_48e9;
	case 18670ULL: goto x86_l_48ee;
	case 18680ULL: goto x86_l_48f8;
	case 18685ULL: goto x86_l_48fd;
	case 18695ULL: goto x86_l_4907;
	case 18700ULL: goto x86_l_490c;
	case 18710ULL: goto x86_l_4916;
	case 18715ULL: goto x86_l_491b;
	case 18725ULL: goto x86_l_4925;
	case 18730ULL: goto x86_l_492a;
	case 18735ULL: goto x86_l_492f;
	case 18740ULL: goto x86_l_4934;
	case 18745ULL: goto x86_l_4939;
	case 18750ULL: goto x86_l_493e;
	case 18752ULL: goto x86_l_4940;
	case 18754ULL: goto x86_l_4942;
	case 18759ULL: goto x86_l_4947;
	case 18766ULL: goto x86_l_494e;
	case 18770ULL: goto x86_l_4952;
	case 18776ULL: goto x86_l_4958;
	case 18781ULL: goto x86_l_495d;
	case 18784ULL: goto x86_l_4960;
	case 18791ULL: goto x86_l_4967;
	case 18795ULL: goto x86_l_496b;
	case 18802ULL: goto x86_l_4972;
	case 18809ULL: goto x86_l_4979;
	case 18817ULL: goto x86_l_4981;
	case 18825ULL: goto x86_l_4989;
	case 18836ULL: goto x86_l_4994;
	case 18839ULL: goto x86_l_4997;
	case 18847ULL: goto x86_l_499f;
	case 18852ULL: goto x86_l_49a4;
	case 18861ULL: goto x86_l_49ad;
	case 18868ULL: goto x86_l_49b4;
	case 18875ULL: goto x86_l_49bb;
	case 18878ULL: goto x86_l_49be;
	case 18883ULL: goto x86_l_49c3;
	case 18885ULL: goto x86_l_49c5;
	case 18888ULL: goto x86_l_49c8;
	case 18890ULL: goto x86_l_49ca;
	case 18893ULL: goto x86_l_49cd;
	case 18898ULL: goto x86_l_49d2;
	case 18906ULL: goto x86_l_49da;
	case 18911ULL: goto x86_l_49df;
	case 18916ULL: goto x86_l_49e4;
	case 18919ULL: goto x86_l_49e7;
	case 18924ULL: goto x86_l_49ec;
	case 18930ULL: goto x86_l_49f2;
	case 18935ULL: goto x86_l_49f7;
	case 18940ULL: goto x86_l_49fc;
	case 18945ULL: goto x86_l_4a01;
	case 18948ULL: goto x86_l_4a04;
	case 18951ULL: goto x86_l_4a07;
	case 18957ULL: goto x86_l_4a0d;
	case 18960ULL: goto x86_l_4a10;
	case 18962ULL: goto x86_l_4a12;
	case 18967ULL: goto x86_l_4a17;
	case 18973ULL: goto x86_l_4a1d;
	case 18978ULL: goto x86_l_4a22;
	case 18985ULL: goto x86_l_4a29;
	case 18988ULL: goto x86_l_4a2c;
	case 18994ULL: goto x86_l_4a32;
	case 19004ULL: goto x86_l_4a3c;
	case 19009ULL: goto x86_l_4a41;
	case 19019ULL: goto x86_l_4a4b;
	case 19024ULL: goto x86_l_4a50;
	case 19034ULL: goto x86_l_4a5a;
	case 19039ULL: goto x86_l_4a5f;
	case 19049ULL: goto x86_l_4a69;
	case 19054ULL: goto x86_l_4a6e;
	case 19064ULL: goto x86_l_4a78;
	case 19069ULL: goto x86_l_4a7d;
	case 19079ULL: goto x86_l_4a87;
	case 19084ULL: goto x86_l_4a8c;
	case 19089ULL: goto x86_l_4a91;
	case 19094ULL: goto x86_l_4a96;
	case 19099ULL: goto x86_l_4a9b;
	case 19102ULL: goto x86_l_4a9e;
	case 19107ULL: goto x86_l_4aa3;
	case 19109ULL: goto x86_l_4aa5;
	case 19111ULL: goto x86_l_4aa7;
	case 19116ULL: goto x86_l_4aac;
	case 19123ULL: goto x86_l_4ab3;
	case 19129ULL: goto x86_l_4ab9;
	case 19137ULL: goto x86_l_4ac1;
	case 19142ULL: goto x86_l_4ac6;
	case 19147ULL: goto x86_l_4acb;
	case 19150ULL: goto x86_l_4ace;
	case 19155ULL: goto x86_l_4ad3;
	case 19161ULL: goto x86_l_4ad9;
	case 19166ULL: goto x86_l_4ade;
	case 19171ULL: goto x86_l_4ae3;
	case 19176ULL: goto x86_l_4ae8;
	case 19179ULL: goto x86_l_4aeb;
	case 19182ULL: goto x86_l_4aee;
	case 19188ULL: goto x86_l_4af4;
	case 19191ULL: goto x86_l_4af7;
	case 19193ULL: goto x86_l_4af9;
	case 19198ULL: goto x86_l_4afe;
	case 19204ULL: goto x86_l_4b04;
	case 19209ULL: goto x86_l_4b09;
	case 19211ULL: goto x86_l_4b0b;
	case 19213ULL: goto x86_l_4b0d;
	case 19217ULL: goto x86_l_4b11;
	case 19220ULL: goto x86_l_4b14;
	case 19226ULL: goto x86_l_4b1a;
	case 19233ULL: goto x86_l_4b21;
	case 19236ULL: goto x86_l_4b24;
	case 19242ULL: goto x86_l_4b2a;
	case 19252ULL: goto x86_l_4b34;
	case 19257ULL: goto x86_l_4b39;
	case 19267ULL: goto x86_l_4b43;
	case 19272ULL: goto x86_l_4b48;
	case 19282ULL: goto x86_l_4b52;
	case 19287ULL: goto x86_l_4b57;
	case 19297ULL: goto x86_l_4b61;
	case 19302ULL: goto x86_l_4b66;
	case 19312ULL: goto x86_l_4b70;
	case 19317ULL: goto x86_l_4b75;
	case 19327ULL: goto x86_l_4b7f;
	case 19332ULL: goto x86_l_4b84;
	case 19337ULL: goto x86_l_4b89;
	case 19342ULL: goto x86_l_4b8e;
	case 19347ULL: goto x86_l_4b93;
	case 19352ULL: goto x86_l_4b98;
	case 19354ULL: goto x86_l_4b9a;
	case 19356ULL: goto x86_l_4b9c;
	case 19361ULL: goto x86_l_4ba1;
	case 19368ULL: goto x86_l_4ba8;
	case 19372ULL: goto x86_l_4bac;
	case 19378ULL: goto x86_l_4bb2;
	case 19383ULL: goto x86_l_4bb7;
	case 19386ULL: goto x86_l_4bba;
	case 19393ULL: goto x86_l_4bc1;
	case 19397ULL: goto x86_l_4bc5;
	case 19404ULL: goto x86_l_4bcc;
	case 19411ULL: goto x86_l_4bd3;
	case 19419ULL: goto x86_l_4bdb;
	case 19427ULL: goto x86_l_4be3;
	case 19438ULL: goto x86_l_4bee;
	case 19441ULL: goto x86_l_4bf1;
	case 19449ULL: goto x86_l_4bf9;
	case 19454ULL: goto x86_l_4bfe;
	case 19463ULL: goto x86_l_4c07;
	case 19470ULL: goto x86_l_4c0e;
	case 19477ULL: goto x86_l_4c15;
	case 19480ULL: goto x86_l_4c18;
	case 19485ULL: goto x86_l_4c1d;
	case 19487ULL: goto x86_l_4c1f;
	case 19490ULL: goto x86_l_4c22;
	case 19496ULL: goto x86_l_4c28;
	case 19499ULL: goto x86_l_4c2b;
	case 19504ULL: goto x86_l_4c30;
	case 19506ULL: goto x86_l_4c32;
	case 19508ULL: goto x86_l_4c34;
	case 19512ULL: goto x86_l_4c38;
	case 19515ULL: goto x86_l_4c3b;
	case 19521ULL: goto x86_l_4c41;
	case 19528ULL: goto x86_l_4c48;
	case 19531ULL: goto x86_l_4c4b;
	case 19537ULL: goto x86_l_4c51;
	case 19547ULL: goto x86_l_4c5b;
	case 19552ULL: goto x86_l_4c60;
	case 19562ULL: goto x86_l_4c6a;
	case 19567ULL: goto x86_l_4c6f;
	case 19577ULL: goto x86_l_4c79;
	case 19582ULL: goto x86_l_4c7e;
	case 19592ULL: goto x86_l_4c88;
	case 19597ULL: goto x86_l_4c8d;
	case 19607ULL: goto x86_l_4c97;
	case 19612ULL: goto x86_l_4c9c;
	case 19622ULL: goto x86_l_4ca6;
	case 19627ULL: goto x86_l_4cab;
	case 19632ULL: goto x86_l_4cb0;
	case 19637ULL: goto x86_l_4cb5;
	case 19642ULL: goto x86_l_4cba;
	case 19647ULL: goto x86_l_4cbf;
	case 19649ULL: goto x86_l_4cc1;
	case 19651ULL: goto x86_l_4cc3;
	case 19656ULL: goto x86_l_4cc8;
	case 19658ULL: goto x86_l_4cca;
	case 19660ULL: goto x86_l_4ccc;
	case 19664ULL: goto x86_l_4cd0;
	case 19667ULL: goto x86_l_4cd3;
	case 19673ULL: goto x86_l_4cd9;
	case 19680ULL: goto x86_l_4ce0;
	case 19683ULL: goto x86_l_4ce3;
	case 19689ULL: goto x86_l_4ce9;
	case 19699ULL: goto x86_l_4cf3;
	case 19704ULL: goto x86_l_4cf8;
	case 19714ULL: goto x86_l_4d02;
	case 19719ULL: goto x86_l_4d07;
	case 19729ULL: goto x86_l_4d11;
	case 19734ULL: goto x86_l_4d16;
	case 19744ULL: goto x86_l_4d20;
	case 19749ULL: goto x86_l_4d25;
	case 19759ULL: goto x86_l_4d2f;
	case 19764ULL: goto x86_l_4d34;
	case 19774ULL: goto x86_l_4d3e;
	case 19779ULL: goto x86_l_4d43;
	case 19784ULL: goto x86_l_4d48;
	case 19789ULL: goto x86_l_4d4d;
	case 19794ULL: goto x86_l_4d52;
	case 19799ULL: goto x86_l_4d57;
	case 19801ULL: goto x86_l_4d59;
	case 19803ULL: goto x86_l_4d5b;
	case 19808ULL: goto x86_l_4d60;
	case 19815ULL: goto x86_l_4d67;
	case 19818ULL: goto x86_l_4d6a;
	case 19824ULL: goto x86_l_4d70;
	case 19834ULL: goto x86_l_4d7a;
	case 19839ULL: goto x86_l_4d7f;
	case 19849ULL: goto x86_l_4d89;
	case 19854ULL: goto x86_l_4d8e;
	case 19864ULL: goto x86_l_4d98;
	case 19869ULL: goto x86_l_4d9d;
	case 19879ULL: goto x86_l_4da7;
	case 19884ULL: goto x86_l_4dac;
	case 19894ULL: goto x86_l_4db6;
	case 19899ULL: goto x86_l_4dbb;
	case 19909ULL: goto x86_l_4dc5;
	case 19914ULL: goto x86_l_4dca;
	case 19919ULL: goto x86_l_4dcf;
	case 19924ULL: goto x86_l_4dd4;
	case 19929ULL: goto x86_l_4dd9;
	case 19932ULL: goto x86_l_4ddc;
	case 19937ULL: goto x86_l_4de1;
	case 19939ULL: goto x86_l_4de3;
	case 19941ULL: goto x86_l_4de5;
	case 19946ULL: goto x86_l_4dea;
	case 19953ULL: goto x86_l_4df1;
	case 19957ULL: goto x86_l_4df5;
	case 19963ULL: goto x86_l_4dfb;
	case 19968ULL: goto x86_l_4e00;
	case 19971ULL: goto x86_l_4e03;
	case 19978ULL: goto x86_l_4e0a;
	case 19982ULL: goto x86_l_4e0e;
	case 19989ULL: goto x86_l_4e15;
	case 19996ULL: goto x86_l_4e1c;
	case 20004ULL: goto x86_l_4e24;
	case 20012ULL: goto x86_l_4e2c;
	case 20023ULL: goto x86_l_4e37;
	case 20026ULL: goto x86_l_4e3a;
	case 20034ULL: goto x86_l_4e42;
	case 20039ULL: goto x86_l_4e47;
	case 20048ULL: goto x86_l_4e50;
	case 20055ULL: goto x86_l_4e57;
	case 20062ULL: goto x86_l_4e5e;
	case 20065ULL: goto x86_l_4e61;
	case 20070ULL: goto x86_l_4e66;
	case 20072ULL: goto x86_l_4e68;
	case 20075ULL: goto x86_l_4e6b;
	case 20081ULL: goto x86_l_4e71;
	case 20084ULL: goto x86_l_4e74;
	case 20089ULL: goto x86_l_4e79;
	case 20096ULL: goto x86_l_4e80;
	case 20100ULL: goto x86_l_4e84;
	case 20106ULL: goto x86_l_4e8a;
	case 20111ULL: goto x86_l_4e8f;
	case 20114ULL: goto x86_l_4e92;
	case 20121ULL: goto x86_l_4e99;
	case 20125ULL: goto x86_l_4e9d;
	case 20132ULL: goto x86_l_4ea4;
	case 20139ULL: goto x86_l_4eab;
	case 20147ULL: goto x86_l_4eb3;
	case 20155ULL: goto x86_l_4ebb;
	case 20166ULL: goto x86_l_4ec6;
	case 20169ULL: goto x86_l_4ec9;
	case 20177ULL: goto x86_l_4ed1;
	case 20182ULL: goto x86_l_4ed6;
	case 20191ULL: goto x86_l_4edf;
	case 20198ULL: goto x86_l_4ee6;
	case 20205ULL: goto x86_l_4eed;
	case 20208ULL: goto x86_l_4ef0;
	case 20213ULL: goto x86_l_4ef5;
	case 20215ULL: goto x86_l_4ef7;
	case 20218ULL: goto x86_l_4efa;
	case 20224ULL: goto x86_l_4f00;
	case 20227ULL: goto x86_l_4f03;
	case 20232ULL: goto x86_l_4f08;
	case 20239ULL: goto x86_l_4f0f;
	case 20242ULL: goto x86_l_4f12;
	default: return 0xffffffffffffffffULL;
	}
x86_l_46ed:
	/* 0x46ed: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_46f2:
	/* 0x46f2: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_46fc:
	/* 0x46fc: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4701:
	/* 0x4701: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_470b:
	/* 0x470b: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4710:
	/* 0x4710: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_471a:
	/* 0x471a: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_471f:
	/* 0x471f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4724:
	/* 0x4724: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_4729:
	/* 0x4729: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_472e:
	/* 0x472e: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4731:
	/* 0x4731: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_4736:
	/* 0x4736: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4738:
	/* 0x4738: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_473a:
	/* 0x473a: jmp    3d05 <kprobe_unwind_ruby+0x3d05> */
	return 15621ULL;
x86_l_473f:
	/* 0x473f: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_4746:
	/* 0x4746: jae    49d2 <kprobe_unwind_ruby+0x49d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_49d2;
	}
x86_l_474c:
	/* 0x474c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4751:
	/* 0x4751: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_4754:
	/* 0x4754: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_475a:
	/* 0x475a: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_475f:
	/* 0x475f: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4762:
	/* 0x4762: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4767:
	/* 0x4767: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4770:
	/* 0x4770: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4779:
	/* 0x4779: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_477e:
	/* 0x477e: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4781:
	/* 0x4781: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4786:
	/* 0x4786: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_478b:
	/* 0x478b: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4791:
	/* 0x4791: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_4796:
	/* 0x4796: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_479b:
	/* 0x479b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47a0:
	/* 0x47a0: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_47a3:
	/* 0x47a3: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_47a8:
	/* 0x47a8: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_47ad:
	/* 0x47ad: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_47b2:
	/* 0x47b2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_47b7:
	/* 0x47b7: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_47bd:
	/* 0x47bd: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_47c2:
	/* 0x47c2: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_47c7:
	/* 0x47c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47cc:
	/* 0x47cc: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_47cf:
	/* 0x47cf: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_47d5:
	/* 0x47d5: je     4aac <kprobe_unwind_ruby+0x4aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4aac;
	}
x86_l_47db:
	/* 0x47db: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_47e0:
	/* 0x47e0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_47e3:
	/* 0x47e3: je     4aac <kprobe_unwind_ruby+0x4aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4aac;
	}
x86_l_47e9:
	/* 0x47e9: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_47ee:
	/* 0x47ee: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_47f1:
	/* 0x47f1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47f6:
	/* 0x47f6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_47fb:
	/* 0x47fb: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4801:
	/* 0x4801: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_4806:
	/* 0x4806: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_480b:
	/* 0x480b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4810:
	/* 0x4810: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4813:
	/* 0x4813: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4816:
	/* 0x4816: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_481c:
	/* 0x481c: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_4821:
	/* 0x4821: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4826:
	/* 0x4826: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_482b:
	/* 0x482b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4830:
	/* 0x4830: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4836:
	/* 0x4836: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_483b:
	/* 0x483b: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4840:
	/* 0x4840: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4845:
	/* 0x4845: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4848:
	/* 0x4848: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_484b:
	/* 0x484b: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_4851:
	/* 0x4851: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_4856:
	/* 0x4856: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_485b:
	/* 0x485b: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_4860:
	/* 0x4860: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_4865:
	/* 0x4865: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_486b:
	/* 0x486b: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_4870:
	/* 0x4870: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4875:
	/* 0x4875: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_487a:
	/* 0x487a: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_487d:
	/* 0x487d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4880:
	/* 0x4880: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_4886:
	/* 0x4886: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_488b:
	/* 0x488b: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_488e:
	/* 0x488e: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_4893:
	/* 0x4893: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_4898:
	/* 0x4898: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_489b:
	/* 0x489b: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_489f:
	/* 0x489f: je     4cc8 <kprobe_unwind_ruby+0x4cc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4cc8;
	}
x86_l_48a5:
	/* 0x48a5: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_48a7:
	/* 0x48a7: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_48aa:
	/* 0x48aa: jmp    4ccc <kprobe_unwind_ruby+0x4ccc> */
	goto x86_l_4ccc;
x86_l_48af:
	/* 0x48af: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_48b1:
	/* 0x48b1: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_48b3:
	/* 0x48b3: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_48b7:
	/* 0x48b7: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_48ba:
	/* 0x48ba: jbe    4947 <kprobe_unwind_ruby+0x4947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_4947;
	}
x86_l_48c0:
	/* 0x48c0: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_48c7:
	/* 0x48c7: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48ca:
	/* 0x48ca: je     4072 <kprobe_unwind_ruby+0x4072> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16498ULL;
	}
x86_l_48d0:
	/* 0x48d0: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_48da:
	/* 0x48da: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_48df:
	/* 0x48df: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_48e9:
	/* 0x48e9: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_48ee:
	/* 0x48ee: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_48f8:
	/* 0x48f8: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_48fd:
	/* 0x48fd: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_4907:
	/* 0x4907: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_490c:
	/* 0x490c: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_4916:
	/* 0x4916: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_491b:
	/* 0x491b: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_4925:
	/* 0x4925: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_492a:
	/* 0x492a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_492f:
	/* 0x492f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4934:
	/* 0x4934: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4939:
	/* 0x4939: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_493e:
	/* 0x493e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4940:
	/* 0x4940: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4942:
	/* 0x4942: jmp    4072 <kprobe_unwind_ruby+0x4072> */
	return 16498ULL;
x86_l_4947:
	/* 0x4947: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_494e:
	/* 0x494e: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_4952:
	/* 0x4952: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_4958:
	/* 0x4958: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_495d:
	/* 0x495d: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4960:
	/* 0x4960: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_4967:
	/* 0x4967: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_496b:
	/* 0x496b: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_4972:
	/* 0x4972: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4979:
	/* 0x4979: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_4981:
	/* 0x4981: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_4989:
	/* 0x4989: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_4994:
	/* 0x4994: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4997:
	/* 0x4997: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_499f:
	/* 0x499f: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_49a4:
	/* 0x49a4: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_49ad:
	/* 0x49ad: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_49b4:
	/* 0x49b4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_49bb:
	/* 0x49bb: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_49be:
	/* 0x49be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_49c3:
	/* 0x49c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49c5:
	/* 0x49c5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_49c8:
	/* 0x49c8: je     4a22 <kprobe_unwind_ruby+0x4a22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a22;
	}
x86_l_49ca:
	/* 0x49ca: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_49cd:
	/* 0x49cd: jmp    4072 <kprobe_unwind_ruby+0x4072> */
	return 16498ULL;
x86_l_49d2:
	/* 0x49d2: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49da:
	/* 0x49da: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_49df:
	/* 0x49df: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_49e4:
	/* 0x49e4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_49e7:
	/* 0x49e7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_49ec:
	/* 0x49ec: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_49f2:
	/* 0x49f2: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_49f7:
	/* 0x49f7: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_49fc:
	/* 0x49fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a01:
	/* 0x4a01: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4a04:
	/* 0x4a04: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4a07:
	/* 0x4a07: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_4a0d:
	/* 0x4a0d: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a10:
	/* 0x4a10: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_4a12:
	/* 0x4a12: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_4a17:
	/* 0x4a17: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_4a1d:
	/* 0x4a1d: jmp    474c <kprobe_unwind_ruby+0x474c> */
	goto x86_l_474c;
x86_l_4a22:
	/* 0x4a22: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4a29:
	/* 0x4a29: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a2c:
	/* 0x4a2c: je     4072 <kprobe_unwind_ruby+0x4072> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16498ULL;
	}
x86_l_4a32:
	/* 0x4a32: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_4a3c:
	/* 0x4a3c: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_4a41:
	/* 0x4a41: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_4a4b:
	/* 0x4a4b: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4a50:
	/* 0x4a50: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_4a5a:
	/* 0x4a5a: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4a5f:
	/* 0x4a5f: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_4a69:
	/* 0x4a69: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4a6e:
	/* 0x4a6e: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_4a78:
	/* 0x4a78: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4a7d:
	/* 0x4a7d: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_4a87:
	/* 0x4a87: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4a8c:
	/* 0x4a8c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4a91:
	/* 0x4a91: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_4a96:
	/* 0x4a96: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4a9b:
	/* 0x4a9b: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a9e:
	/* 0x4a9e: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_4aa3:
	/* 0x4aa3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4aa5:
	/* 0x4aa5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4aa7:
	/* 0x4aa7: jmp    4072 <kprobe_unwind_ruby+0x4072> */
	return 16498ULL;
x86_l_4aac:
	/* 0x4aac: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_4ab3:
	/* 0x4ab3: jb     5013 <kprobe_unwind_ruby+0x5013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 20499ULL;
	}
x86_l_4ab9:
	/* 0x4ab9: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ac1:
	/* 0x4ac1: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_4ac6:
	/* 0x4ac6: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4acb:
	/* 0x4acb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4ace:
	/* 0x4ace: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4ad3:
	/* 0x4ad3: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4ad9:
	/* 0x4ad9: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_4ade:
	/* 0x4ade: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4ae3:
	/* 0x4ae3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ae8:
	/* 0x4ae8: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4aeb:
	/* 0x4aeb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4aee:
	/* 0x4aee: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_4af4:
	/* 0x4af4: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4af7:
	/* 0x4af7: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_4af9:
	/* 0x4af9: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_4afe:
	/* 0x4afe: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_4b04:
	/* 0x4b04: jmp    5013 <kprobe_unwind_ruby+0x5013> */
	return 20499ULL;
x86_l_4b09:
	/* 0x4b09: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4b0b:
	/* 0x4b0b: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_4b0d:
	/* 0x4b0d: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_4b11:
	/* 0x4b11: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_4b14:
	/* 0x4b14: jbe    4ba1 <kprobe_unwind_ruby+0x4ba1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_4ba1;
	}
x86_l_4b1a:
	/* 0x4b1a: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4b21:
	/* 0x4b21: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b24:
	/* 0x4b24: je     43df <kprobe_unwind_ruby+0x43df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17375ULL;
	}
x86_l_4b2a:
	/* 0x4b2a: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_4b34:
	/* 0x4b34: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_4b39:
	/* 0x4b39: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_4b43:
	/* 0x4b43: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4b48:
	/* 0x4b48: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_4b52:
	/* 0x4b52: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4b57:
	/* 0x4b57: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_4b61:
	/* 0x4b61: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4b66:
	/* 0x4b66: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_4b70:
	/* 0x4b70: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4b75:
	/* 0x4b75: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_4b7f:
	/* 0x4b7f: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4b84:
	/* 0x4b84: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4b89:
	/* 0x4b89: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4b8e:
	/* 0x4b8e: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4b93:
	/* 0x4b93: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_4b98:
	/* 0x4b98: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4b9a:
	/* 0x4b9a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4b9c:
	/* 0x4b9c: jmp    43df <kprobe_unwind_ruby+0x43df> */
	return 17375ULL;
x86_l_4ba1:
	/* 0x4ba1: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_4ba8:
	/* 0x4ba8: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_4bac:
	/* 0x4bac: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_4bb2:
	/* 0x4bb2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4bb7:
	/* 0x4bb7: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4bba:
	/* 0x4bba: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_4bc1:
	/* 0x4bc1: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_4bc5:
	/* 0x4bc5: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_4bcc:
	/* 0x4bcc: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4bd3:
	/* 0x4bd3: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_4bdb:
	/* 0x4bdb: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_4be3:
	/* 0x4be3: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_4bee:
	/* 0x4bee: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4bf1:
	/* 0x4bf1: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_4bf9:
	/* 0x4bf9: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4bfe:
	/* 0x4bfe: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_4c07:
	/* 0x4c07: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_4c0e:
	/* 0x4c0e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_4c15:
	/* 0x4c15: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4c18:
	/* 0x4c18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c1d:
	/* 0x4c1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c1f:
	/* 0x4c1f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c22:
	/* 0x4c22: je     4d60 <kprobe_unwind_ruby+0x4d60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d60;
	}
x86_l_4c28:
	/* 0x4c28: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4c2b:
	/* 0x4c2b: jmp    43df <kprobe_unwind_ruby+0x43df> */
	return 17375ULL;
x86_l_4c30:
	/* 0x4c30: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c32:
	/* 0x4c32: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_4c34:
	/* 0x4c34: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_4c38:
	/* 0x4c38: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_4c3b:
	/* 0x4c3b: jbe    4dea <kprobe_unwind_ruby+0x4dea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_4dea;
	}
x86_l_4c41:
	/* 0x4c41: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4c48:
	/* 0x4c48: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c4b:
	/* 0x4c4b: je     474c <kprobe_unwind_ruby+0x474c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_474c;
	}
x86_l_4c51:
	/* 0x4c51: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_4c5b:
	/* 0x4c5b: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_4c60:
	/* 0x4c60: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_4c6a:
	/* 0x4c6a: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4c6f:
	/* 0x4c6f: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_4c79:
	/* 0x4c79: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4c7e:
	/* 0x4c7e: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_4c88:
	/* 0x4c88: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4c8d:
	/* 0x4c8d: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_4c97:
	/* 0x4c97: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4c9c:
	/* 0x4c9c: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_4ca6:
	/* 0x4ca6: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4cab:
	/* 0x4cab: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4cb0:
	/* 0x4cb0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4cb5:
	/* 0x4cb5: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4cba:
	/* 0x4cba: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_4cbf:
	/* 0x4cbf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4cc1:
	/* 0x4cc1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4cc3:
	/* 0x4cc3: jmp    474c <kprobe_unwind_ruby+0x474c> */
	goto x86_l_474c;
x86_l_4cc8:
	/* 0x4cc8: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4cca:
	/* 0x4cca: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_4ccc:
	/* 0x4ccc: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_4cd0:
	/* 0x4cd0: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_4cd3:
	/* 0x4cd3: jbe    4e79 <kprobe_unwind_ruby+0x4e79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_4e79;
	}
x86_l_4cd9:
	/* 0x4cd9: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4ce0:
	/* 0x4ce0: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ce3:
	/* 0x4ce3: je     5013 <kprobe_unwind_ruby+0x5013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20499ULL;
	}
x86_l_4ce9:
	/* 0x4ce9: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_4cf3:
	/* 0x4cf3: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_4cf8:
	/* 0x4cf8: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_4d02:
	/* 0x4d02: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4d07:
	/* 0x4d07: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_4d11:
	/* 0x4d11: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4d16:
	/* 0x4d16: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_4d20:
	/* 0x4d20: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4d25:
	/* 0x4d25: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_4d2f:
	/* 0x4d2f: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4d34:
	/* 0x4d34: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_4d3e:
	/* 0x4d3e: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4d43:
	/* 0x4d43: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4d48:
	/* 0x4d48: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4d4d:
	/* 0x4d4d: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4d52:
	/* 0x4d52: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_4d57:
	/* 0x4d57: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d59:
	/* 0x4d59: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4d5b:
	/* 0x4d5b: jmp    5013 <kprobe_unwind_ruby+0x5013> */
	return 20499ULL;
x86_l_4d60:
	/* 0x4d60: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4d67:
	/* 0x4d67: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d6a:
	/* 0x4d6a: je     43df <kprobe_unwind_ruby+0x43df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17375ULL;
	}
x86_l_4d70:
	/* 0x4d70: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_4d7a:
	/* 0x4d7a: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_4d7f:
	/* 0x4d7f: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_4d89:
	/* 0x4d89: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4d8e:
	/* 0x4d8e: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_4d98:
	/* 0x4d98: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4d9d:
	/* 0x4d9d: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_4da7:
	/* 0x4da7: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4dac:
	/* 0x4dac: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_4db6:
	/* 0x4db6: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4dbb:
	/* 0x4dbb: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_4dc5:
	/* 0x4dc5: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4dca:
	/* 0x4dca: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4dcf:
	/* 0x4dcf: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_4dd4:
	/* 0x4dd4: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4dd9:
	/* 0x4dd9: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ddc:
	/* 0x4ddc: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_4de1:
	/* 0x4de1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4de3:
	/* 0x4de3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4de5:
	/* 0x4de5: jmp    43df <kprobe_unwind_ruby+0x43df> */
	return 17375ULL;
x86_l_4dea:
	/* 0x4dea: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_4df1:
	/* 0x4df1: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_4df5:
	/* 0x4df5: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_4dfb:
	/* 0x4dfb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e00:
	/* 0x4e00: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4e03:
	/* 0x4e03: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_4e0a:
	/* 0x4e0a: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_4e0e:
	/* 0x4e0e: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_4e15:
	/* 0x4e15: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e1c:
	/* 0x4e1c: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_4e24:
	/* 0x4e24: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_4e2c:
	/* 0x4e2c: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_4e37:
	/* 0x4e37: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e3a:
	/* 0x4e3a: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_4e42:
	/* 0x4e42: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4e47:
	/* 0x4e47: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_4e50:
	/* 0x4e50: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_4e57:
	/* 0x4e57: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_4e5e:
	/* 0x4e5e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4e61:
	/* 0x4e61: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e66:
	/* 0x4e66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e68:
	/* 0x4e68: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e6b:
	/* 0x4e6b: je     4f08 <kprobe_unwind_ruby+0x4f08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f08;
	}
x86_l_4e71:
	/* 0x4e71: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4e74:
	/* 0x4e74: jmp    474c <kprobe_unwind_ruby+0x474c> */
	goto x86_l_474c;
x86_l_4e79:
	/* 0x4e79: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_4e80:
	/* 0x4e80: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_4e84:
	/* 0x4e84: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_4e8a:
	/* 0x4e8a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e8f:
	/* 0x4e8f: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4e92:
	/* 0x4e92: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_4e99:
	/* 0x4e99: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_4e9d:
	/* 0x4e9d: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_4ea4:
	/* 0x4ea4: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4eab:
	/* 0x4eab: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_4eb3:
	/* 0x4eb3: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_4ebb:
	/* 0x4ebb: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_4ec6:
	/* 0x4ec6: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ec9:
	/* 0x4ec9: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_4ed1:
	/* 0x4ed1: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4ed6:
	/* 0x4ed6: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_4edf:
	/* 0x4edf: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_4ee6:
	/* 0x4ee6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_4eed:
	/* 0x4eed: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4ef0:
	/* 0x4ef0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4ef5:
	/* 0x4ef5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ef7:
	/* 0x4ef7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4efa:
	/* 0x4efa: je     4f92 <kprobe_unwind_ruby+0x4f92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20370ULL;
	}
x86_l_4f00:
	/* 0x4f00: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4f03:
	/* 0x4f03: jmp    5013 <kprobe_unwind_ruby+0x5013> */
	return 20499ULL;
x86_l_4f08:
	/* 0x4f08: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4f0f:
	/* 0x4f0f: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f12:
	/* 0x4f12: je     474c <kprobe_unwind_ruby+0x474c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_474c;
	}
	return 20248ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20248ULL: goto x86_l_4f18;
	case 20258ULL: goto x86_l_4f22;
	case 20263ULL: goto x86_l_4f27;
	case 20273ULL: goto x86_l_4f31;
	case 20278ULL: goto x86_l_4f36;
	case 20288ULL: goto x86_l_4f40;
	case 20293ULL: goto x86_l_4f45;
	case 20303ULL: goto x86_l_4f4f;
	case 20308ULL: goto x86_l_4f54;
	case 20318ULL: goto x86_l_4f5e;
	case 20323ULL: goto x86_l_4f63;
	case 20333ULL: goto x86_l_4f6d;
	case 20338ULL: goto x86_l_4f72;
	case 20343ULL: goto x86_l_4f77;
	case 20348ULL: goto x86_l_4f7c;
	case 20353ULL: goto x86_l_4f81;
	case 20356ULL: goto x86_l_4f84;
	case 20361ULL: goto x86_l_4f89;
	case 20363ULL: goto x86_l_4f8b;
	case 20365ULL: goto x86_l_4f8d;
	case 20370ULL: goto x86_l_4f92;
	case 20377ULL: goto x86_l_4f99;
	case 20380ULL: goto x86_l_4f9c;
	case 20382ULL: goto x86_l_4f9e;
	case 20392ULL: goto x86_l_4fa8;
	case 20397ULL: goto x86_l_4fad;
	case 20407ULL: goto x86_l_4fb7;
	case 20412ULL: goto x86_l_4fbc;
	case 20422ULL: goto x86_l_4fc6;
	case 20427ULL: goto x86_l_4fcb;
	case 20437ULL: goto x86_l_4fd5;
	case 20442ULL: goto x86_l_4fda;
	case 20452ULL: goto x86_l_4fe4;
	case 20457ULL: goto x86_l_4fe9;
	case 20467ULL: goto x86_l_4ff3;
	case 20472ULL: goto x86_l_4ff8;
	case 20477ULL: goto x86_l_4ffd;
	case 20482ULL: goto x86_l_5002;
	case 20487ULL: goto x86_l_5007;
	case 20490ULL: goto x86_l_500a;
	case 20495ULL: goto x86_l_500f;
	case 20497ULL: goto x86_l_5011;
	case 20499ULL: goto x86_l_5013;
	case 20504ULL: goto x86_l_5018;
	case 20507ULL: goto x86_l_501b;
	case 20513ULL: goto x86_l_5021;
	case 20518ULL: goto x86_l_5026;
	case 20521ULL: goto x86_l_5029;
	case 20526ULL: goto x86_l_502e;
	case 20535ULL: goto x86_l_5037;
	case 20544ULL: goto x86_l_5040;
	case 20549ULL: goto x86_l_5045;
	case 20552ULL: goto x86_l_5048;
	case 20557ULL: goto x86_l_504d;
	case 20562ULL: goto x86_l_5052;
	case 20568ULL: goto x86_l_5058;
	case 20573ULL: goto x86_l_505d;
	case 20578ULL: goto x86_l_5062;
	case 20583ULL: goto x86_l_5067;
	case 20586ULL: goto x86_l_506a;
	case 20591ULL: goto x86_l_506f;
	case 20596ULL: goto x86_l_5074;
	case 20601ULL: goto x86_l_5079;
	case 20606ULL: goto x86_l_507e;
	case 20612ULL: goto x86_l_5084;
	case 20617ULL: goto x86_l_5089;
	case 20622ULL: goto x86_l_508e;
	case 20627ULL: goto x86_l_5093;
	case 20630ULL: goto x86_l_5096;
	case 20636ULL: goto x86_l_509c;
	case 20642ULL: goto x86_l_50a2;
	case 20647ULL: goto x86_l_50a7;
	case 20650ULL: goto x86_l_50aa;
	case 20656ULL: goto x86_l_50b0;
	case 20661ULL: goto x86_l_50b5;
	case 20664ULL: goto x86_l_50b8;
	case 20669ULL: goto x86_l_50bd;
	case 20674ULL: goto x86_l_50c2;
	case 20680ULL: goto x86_l_50c8;
	case 20685ULL: goto x86_l_50cd;
	case 20690ULL: goto x86_l_50d2;
	case 20695ULL: goto x86_l_50d7;
	case 20698ULL: goto x86_l_50da;
	case 20701ULL: goto x86_l_50dd;
	case 20707ULL: goto x86_l_50e3;
	case 20712ULL: goto x86_l_50e8;
	case 20717ULL: goto x86_l_50ed;
	case 20722ULL: goto x86_l_50f2;
	case 20727ULL: goto x86_l_50f7;
	case 20733ULL: goto x86_l_50fd;
	case 20738ULL: goto x86_l_5102;
	case 20743ULL: goto x86_l_5107;
	case 20748ULL: goto x86_l_510c;
	case 20751ULL: goto x86_l_510f;
	case 20754ULL: goto x86_l_5112;
	case 20760ULL: goto x86_l_5118;
	case 20765ULL: goto x86_l_511d;
	case 20770ULL: goto x86_l_5122;
	case 20775ULL: goto x86_l_5127;
	case 20780ULL: goto x86_l_512c;
	case 20786ULL: goto x86_l_5132;
	case 20791ULL: goto x86_l_5137;
	case 20796ULL: goto x86_l_513c;
	case 20801ULL: goto x86_l_5141;
	case 20804ULL: goto x86_l_5144;
	case 20807ULL: goto x86_l_5147;
	case 20813ULL: goto x86_l_514d;
	case 20818ULL: goto x86_l_5152;
	case 20821ULL: goto x86_l_5155;
	case 20826ULL: goto x86_l_515a;
	case 20831ULL: goto x86_l_515f;
	case 20834ULL: goto x86_l_5162;
	case 20838ULL: goto x86_l_5166;
	case 20840ULL: goto x86_l_5168;
	case 20842ULL: goto x86_l_516a;
	case 20845ULL: goto x86_l_516d;
	case 20847ULL: goto x86_l_516f;
	case 20854ULL: goto x86_l_5176;
	case 20860ULL: goto x86_l_517c;
	case 20868ULL: goto x86_l_5184;
	case 20873ULL: goto x86_l_5189;
	case 20878ULL: goto x86_l_518e;
	case 20881ULL: goto x86_l_5191;
	case 20886ULL: goto x86_l_5196;
	case 20892ULL: goto x86_l_519c;
	case 20897ULL: goto x86_l_51a1;
	case 20902ULL: goto x86_l_51a6;
	case 20907ULL: goto x86_l_51ab;
	case 20910ULL: goto x86_l_51ae;
	case 20913ULL: goto x86_l_51b1;
	case 20919ULL: goto x86_l_51b7;
	case 20922ULL: goto x86_l_51ba;
	case 20924ULL: goto x86_l_51bc;
	case 20929ULL: goto x86_l_51c1;
	case 20935ULL: goto x86_l_51c7;
	case 20940ULL: goto x86_l_51cc;
	case 20942ULL: goto x86_l_51ce;
	case 20944ULL: goto x86_l_51d0;
	case 20948ULL: goto x86_l_51d4;
	case 20951ULL: goto x86_l_51d7;
	case 20957ULL: goto x86_l_51dd;
	case 20964ULL: goto x86_l_51e4;
	case 20967ULL: goto x86_l_51e7;
	case 20973ULL: goto x86_l_51ed;
	case 20983ULL: goto x86_l_51f7;
	case 20988ULL: goto x86_l_51fc;
	case 20998ULL: goto x86_l_5206;
	case 21003ULL: goto x86_l_520b;
	case 21013ULL: goto x86_l_5215;
	case 21018ULL: goto x86_l_521a;
	case 21028ULL: goto x86_l_5224;
	case 21033ULL: goto x86_l_5229;
	case 21043ULL: goto x86_l_5233;
	case 21048ULL: goto x86_l_5238;
	case 21058ULL: goto x86_l_5242;
	case 21063ULL: goto x86_l_5247;
	case 21068ULL: goto x86_l_524c;
	case 21073ULL: goto x86_l_5251;
	case 21078ULL: goto x86_l_5256;
	case 21083ULL: goto x86_l_525b;
	case 21085ULL: goto x86_l_525d;
	case 21087ULL: goto x86_l_525f;
	case 21092ULL: goto x86_l_5264;
	case 21099ULL: goto x86_l_526b;
	case 21103ULL: goto x86_l_526f;
	case 21109ULL: goto x86_l_5275;
	case 21114ULL: goto x86_l_527a;
	case 21117ULL: goto x86_l_527d;
	case 21124ULL: goto x86_l_5284;
	case 21128ULL: goto x86_l_5288;
	case 21135ULL: goto x86_l_528f;
	case 21142ULL: goto x86_l_5296;
	case 21150ULL: goto x86_l_529e;
	case 21158ULL: goto x86_l_52a6;
	case 21169ULL: goto x86_l_52b1;
	case 21172ULL: goto x86_l_52b4;
	case 21180ULL: goto x86_l_52bc;
	case 21185ULL: goto x86_l_52c1;
	case 21194ULL: goto x86_l_52ca;
	case 21201ULL: goto x86_l_52d1;
	case 21208ULL: goto x86_l_52d8;
	case 21211ULL: goto x86_l_52db;
	case 21216ULL: goto x86_l_52e0;
	case 21218ULL: goto x86_l_52e2;
	case 21221ULL: goto x86_l_52e5;
	case 21223ULL: goto x86_l_52e7;
	case 21226ULL: goto x86_l_52ea;
	case 21231ULL: goto x86_l_52ef;
	case 21238ULL: goto x86_l_52f6;
	case 21241ULL: goto x86_l_52f9;
	case 21243ULL: goto x86_l_52fb;
	case 21253ULL: goto x86_l_5305;
	case 21258ULL: goto x86_l_530a;
	case 21268ULL: goto x86_l_5314;
	case 21273ULL: goto x86_l_5319;
	case 21283ULL: goto x86_l_5323;
	case 21288ULL: goto x86_l_5328;
	case 21298ULL: goto x86_l_5332;
	case 21303ULL: goto x86_l_5337;
	case 21313ULL: goto x86_l_5341;
	case 21318ULL: goto x86_l_5346;
	case 21328ULL: goto x86_l_5350;
	case 21333ULL: goto x86_l_5355;
	case 21338ULL: goto x86_l_535a;
	case 21343ULL: goto x86_l_535f;
	case 21348ULL: goto x86_l_5364;
	case 21351ULL: goto x86_l_5367;
	case 21356ULL: goto x86_l_536c;
	case 21358ULL: goto x86_l_536e;
	case 21360ULL: goto x86_l_5370;
	case 21365ULL: goto x86_l_5375;
	case 21368ULL: goto x86_l_5378;
	case 21374ULL: goto x86_l_537e;
	case 21379ULL: goto x86_l_5383;
	case 21382ULL: goto x86_l_5386;
	case 21387ULL: goto x86_l_538b;
	case 21396ULL: goto x86_l_5394;
	case 21405ULL: goto x86_l_539d;
	case 21410ULL: goto x86_l_53a2;
	case 21413ULL: goto x86_l_53a5;
	case 21418ULL: goto x86_l_53aa;
	case 21423ULL: goto x86_l_53af;
	case 21429ULL: goto x86_l_53b5;
	case 21434ULL: goto x86_l_53ba;
	case 21439ULL: goto x86_l_53bf;
	case 21444ULL: goto x86_l_53c4;
	case 21447ULL: goto x86_l_53c7;
	case 21452ULL: goto x86_l_53cc;
	case 21457ULL: goto x86_l_53d1;
	case 21462ULL: goto x86_l_53d6;
	case 21467ULL: goto x86_l_53db;
	case 21473ULL: goto x86_l_53e1;
	case 21478ULL: goto x86_l_53e6;
	case 21483ULL: goto x86_l_53eb;
	case 21488ULL: goto x86_l_53f0;
	case 21491ULL: goto x86_l_53f3;
	case 21497ULL: goto x86_l_53f9;
	case 21503ULL: goto x86_l_53ff;
	case 21508ULL: goto x86_l_5404;
	case 21511ULL: goto x86_l_5407;
	case 21517ULL: goto x86_l_540d;
	case 21522ULL: goto x86_l_5412;
	case 21525ULL: goto x86_l_5415;
	case 21530ULL: goto x86_l_541a;
	case 21535ULL: goto x86_l_541f;
	case 21541ULL: goto x86_l_5425;
	case 21546ULL: goto x86_l_542a;
	case 21551ULL: goto x86_l_542f;
	case 21556ULL: goto x86_l_5434;
	case 21559ULL: goto x86_l_5437;
	case 21562ULL: goto x86_l_543a;
	case 21568ULL: goto x86_l_5440;
	case 21573ULL: goto x86_l_5445;
	case 21578ULL: goto x86_l_544a;
	case 21583ULL: goto x86_l_544f;
	case 21588ULL: goto x86_l_5454;
	case 21594ULL: goto x86_l_545a;
	case 21599ULL: goto x86_l_545f;
	case 21604ULL: goto x86_l_5464;
	case 21609ULL: goto x86_l_5469;
	case 21612ULL: goto x86_l_546c;
	case 21615ULL: goto x86_l_546f;
	case 21621ULL: goto x86_l_5475;
	case 21626ULL: goto x86_l_547a;
	case 21631ULL: goto x86_l_547f;
	case 21636ULL: goto x86_l_5484;
	case 21641ULL: goto x86_l_5489;
	case 21647ULL: goto x86_l_548f;
	case 21652ULL: goto x86_l_5494;
	case 21657ULL: goto x86_l_5499;
	case 21662ULL: goto x86_l_549e;
	case 21665ULL: goto x86_l_54a1;
	case 21668ULL: goto x86_l_54a4;
	case 21674ULL: goto x86_l_54aa;
	case 21679ULL: goto x86_l_54af;
	case 21682ULL: goto x86_l_54b2;
	case 21687ULL: goto x86_l_54b7;
	case 21692ULL: goto x86_l_54bc;
	case 21695ULL: goto x86_l_54bf;
	case 21699ULL: goto x86_l_54c3;
	case 21701ULL: goto x86_l_54c5;
	case 21703ULL: goto x86_l_54c7;
	case 21706ULL: goto x86_l_54ca;
	case 21708ULL: goto x86_l_54cc;
	case 21715ULL: goto x86_l_54d3;
	case 21721ULL: goto x86_l_54d9;
	case 21729ULL: goto x86_l_54e1;
	case 21734ULL: goto x86_l_54e6;
	case 21739ULL: goto x86_l_54eb;
	case 21742ULL: goto x86_l_54ee;
	case 21747ULL: goto x86_l_54f3;
	case 21753ULL: goto x86_l_54f9;
	case 21758ULL: goto x86_l_54fe;
	case 21763ULL: goto x86_l_5503;
	case 21768ULL: goto x86_l_5508;
	case 21771ULL: goto x86_l_550b;
	case 21774ULL: goto x86_l_550e;
	case 21780ULL: goto x86_l_5514;
	case 21783ULL: goto x86_l_5517;
	case 21785ULL: goto x86_l_5519;
	case 21790ULL: goto x86_l_551e;
	case 21796ULL: goto x86_l_5524;
	case 21801ULL: goto x86_l_5529;
	case 21803ULL: goto x86_l_552b;
	case 21805ULL: goto x86_l_552d;
	case 21809ULL: goto x86_l_5531;
	case 21812ULL: goto x86_l_5534;
	case 21818ULL: goto x86_l_553a;
	case 21825ULL: goto x86_l_5541;
	case 21828ULL: goto x86_l_5544;
	case 21834ULL: goto x86_l_554a;
	case 21844ULL: goto x86_l_5554;
	case 21849ULL: goto x86_l_5559;
	case 21859ULL: goto x86_l_5563;
	case 21864ULL: goto x86_l_5568;
	case 21874ULL: goto x86_l_5572;
	case 21879ULL: goto x86_l_5577;
	case 21889ULL: goto x86_l_5581;
	case 21894ULL: goto x86_l_5586;
	case 21904ULL: goto x86_l_5590;
	case 21909ULL: goto x86_l_5595;
	case 21919ULL: goto x86_l_559f;
	case 21924ULL: goto x86_l_55a4;
	case 21929ULL: goto x86_l_55a9;
	case 21934ULL: goto x86_l_55ae;
	case 21939ULL: goto x86_l_55b3;
	case 21944ULL: goto x86_l_55b8;
	case 21946ULL: goto x86_l_55ba;
	case 21948ULL: goto x86_l_55bc;
	case 21953ULL: goto x86_l_55c1;
	case 21960ULL: goto x86_l_55c8;
	case 21964ULL: goto x86_l_55cc;
	case 21970ULL: goto x86_l_55d2;
	case 21975ULL: goto x86_l_55d7;
	case 21978ULL: goto x86_l_55da;
	case 21985ULL: goto x86_l_55e1;
	case 21989ULL: goto x86_l_55e5;
	case 21996ULL: goto x86_l_55ec;
	case 22003ULL: goto x86_l_55f3;
	case 22011ULL: goto x86_l_55fb;
	case 22019ULL: goto x86_l_5603;
	case 22030ULL: goto x86_l_560e;
	case 22033ULL: goto x86_l_5611;
	case 22041ULL: goto x86_l_5619;
	case 22046ULL: goto x86_l_561e;
	case 22055ULL: goto x86_l_5627;
	case 22062ULL: goto x86_l_562e;
	case 22069ULL: goto x86_l_5635;
	case 22072ULL: goto x86_l_5638;
	case 22077ULL: goto x86_l_563d;
	case 22079ULL: goto x86_l_563f;
	case 22082ULL: goto x86_l_5642;
	case 22084ULL: goto x86_l_5644;
	case 22087ULL: goto x86_l_5647;
	case 22092ULL: goto x86_l_564c;
	case 22099ULL: goto x86_l_5653;
	case 22102ULL: goto x86_l_5656;
	case 22104ULL: goto x86_l_5658;
	case 22114ULL: goto x86_l_5662;
	case 22119ULL: goto x86_l_5667;
	case 22129ULL: goto x86_l_5671;
	case 22134ULL: goto x86_l_5676;
	case 22144ULL: goto x86_l_5680;
	case 22149ULL: goto x86_l_5685;
	case 22159ULL: goto x86_l_568f;
	case 22164ULL: goto x86_l_5694;
	case 22174ULL: goto x86_l_569e;
	case 22179ULL: goto x86_l_56a3;
	case 22189ULL: goto x86_l_56ad;
	case 22194ULL: goto x86_l_56b2;
	case 22199ULL: goto x86_l_56b7;
	case 22204ULL: goto x86_l_56bc;
	case 22209ULL: goto x86_l_56c1;
	case 22212ULL: goto x86_l_56c4;
	case 22217ULL: goto x86_l_56c9;
	case 22219ULL: goto x86_l_56cb;
	case 22221ULL: goto x86_l_56cd;
	case 22226ULL: goto x86_l_56d2;
	case 22229ULL: goto x86_l_56d5;
	case 22235ULL: goto x86_l_56db;
	case 22240ULL: goto x86_l_56e0;
	case 22243ULL: goto x86_l_56e3;
	case 22248ULL: goto x86_l_56e8;
	case 22257ULL: goto x86_l_56f1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4f18:
	/* 0x4f18: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_4f22:
	/* 0x4f22: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_4f27:
	/* 0x4f27: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_4f31:
	/* 0x4f31: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4f36:
	/* 0x4f36: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_4f40:
	/* 0x4f40: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4f45:
	/* 0x4f45: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_4f4f:
	/* 0x4f4f: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4f54:
	/* 0x4f54: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_4f5e:
	/* 0x4f5e: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4f63:
	/* 0x4f63: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_4f6d:
	/* 0x4f6d: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4f72:
	/* 0x4f72: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4f77:
	/* 0x4f77: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_4f7c:
	/* 0x4f7c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4f81:
	/* 0x4f81: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f84:
	/* 0x4f84: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_4f89:
	/* 0x4f89: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f8b:
	/* 0x4f8b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4f8d:
	/* 0x4f8d: jmp    474c <kprobe_unwind_ruby+0x474c> */
	return 18252ULL;
x86_l_4f92:
	/* 0x4f92: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4f99:
	/* 0x4f99: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f9c:
	/* 0x4f9c: je     5013 <kprobe_unwind_ruby+0x5013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5013;
	}
x86_l_4f9e:
	/* 0x4f9e: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_4fa8:
	/* 0x4fa8: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_4fad:
	/* 0x4fad: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_4fb7:
	/* 0x4fb7: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4fbc:
	/* 0x4fbc: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_4fc6:
	/* 0x4fc6: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4fcb:
	/* 0x4fcb: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_4fd5:
	/* 0x4fd5: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4fda:
	/* 0x4fda: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_4fe4:
	/* 0x4fe4: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4fe9:
	/* 0x4fe9: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_4ff3:
	/* 0x4ff3: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4ff8:
	/* 0x4ff8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4ffd:
	/* 0x4ffd: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_5002:
	/* 0x5002: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5007:
	/* 0x5007: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_500a:
	/* 0x500a: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_500f:
	/* 0x500f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5011:
	/* 0x5011: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5013:
	/* 0x5013: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5018:
	/* 0x5018: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_501b:
	/* 0x501b: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_5021:
	/* 0x5021: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_5026:
	/* 0x5026: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5029:
	/* 0x5029: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_502e:
	/* 0x502e: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5037:
	/* 0x5037: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5040:
	/* 0x5040: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_5045:
	/* 0x5045: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5048:
	/* 0x5048: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_504d:
	/* 0x504d: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_5052:
	/* 0x5052: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5058:
	/* 0x5058: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_505d:
	/* 0x505d: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5062:
	/* 0x5062: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5067:
	/* 0x5067: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_506a:
	/* 0x506a: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_506f:
	/* 0x506f: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5074:
	/* 0x5074: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5079:
	/* 0x5079: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_507e:
	/* 0x507e: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5084:
	/* 0x5084: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_5089:
	/* 0x5089: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_508e:
	/* 0x508e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5093:
	/* 0x5093: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5096:
	/* 0x5096: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_509c:
	/* 0x509c: je     516f <kprobe_unwind_ruby+0x516f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_516f;
	}
x86_l_50a2:
	/* 0x50a2: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_50a7:
	/* 0x50a7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_50aa:
	/* 0x50aa: je     516f <kprobe_unwind_ruby+0x516f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_516f;
	}
x86_l_50b0:
	/* 0x50b0: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_50b5:
	/* 0x50b5: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_50b8:
	/* 0x50b8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_50bd:
	/* 0x50bd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_50c2:
	/* 0x50c2: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_50c8:
	/* 0x50c8: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_50cd:
	/* 0x50cd: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_50d2:
	/* 0x50d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50d7:
	/* 0x50d7: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_50da:
	/* 0x50da: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_50dd:
	/* 0x50dd: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_50e3:
	/* 0x50e3: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_50e8:
	/* 0x50e8: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_50ed:
	/* 0x50ed: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_50f2:
	/* 0x50f2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_50f7:
	/* 0x50f7: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_50fd:
	/* 0x50fd: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_5102:
	/* 0x5102: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5107:
	/* 0x5107: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_510c:
	/* 0x510c: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_510f:
	/* 0x510f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5112:
	/* 0x5112: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_5118:
	/* 0x5118: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_511d:
	/* 0x511d: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5122:
	/* 0x5122: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_5127:
	/* 0x5127: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_512c:
	/* 0x512c: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5132:
	/* 0x5132: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_5137:
	/* 0x5137: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_513c:
	/* 0x513c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5141:
	/* 0x5141: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5144:
	/* 0x5144: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5147:
	/* 0x5147: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_514d:
	/* 0x514d: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5152:
	/* 0x5152: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_5155:
	/* 0x5155: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_515a:
	/* 0x515a: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_515f:
	/* 0x515f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5162:
	/* 0x5162: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_5166:
	/* 0x5166: je     51cc <kprobe_unwind_ruby+0x51cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_51cc;
	}
x86_l_5168:
	/* 0x5168: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_516a:
	/* 0x516a: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_516d:
	/* 0x516d: jmp    51d0 <kprobe_unwind_ruby+0x51d0> */
	goto x86_l_51d0;
x86_l_516f:
	/* 0x516f: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_5176:
	/* 0x5176: jb     5370 <kprobe_unwind_ruby+0x5370> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5370;
	}
x86_l_517c:
	/* 0x517c: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5184:
	/* 0x5184: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_5189:
	/* 0x5189: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_518e:
	/* 0x518e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5191:
	/* 0x5191: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5196:
	/* 0x5196: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_519c:
	/* 0x519c: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_51a1:
	/* 0x51a1: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_51a6:
	/* 0x51a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51ab:
	/* 0x51ab: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_51ae:
	/* 0x51ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_51b1:
	/* 0x51b1: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_51b7:
	/* 0x51b7: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51ba:
	/* 0x51ba: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_51bc:
	/* 0x51bc: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_51c1:
	/* 0x51c1: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_51c7:
	/* 0x51c7: jmp    5370 <kprobe_unwind_ruby+0x5370> */
	goto x86_l_5370;
x86_l_51cc:
	/* 0x51cc: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_51ce:
	/* 0x51ce: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_51d0:
	/* 0x51d0: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_51d4:
	/* 0x51d4: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_51d7:
	/* 0x51d7: jbe    5264 <kprobe_unwind_ruby+0x5264> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_5264;
	}
x86_l_51dd:
	/* 0x51dd: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_51e4:
	/* 0x51e4: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51e7:
	/* 0x51e7: je     5370 <kprobe_unwind_ruby+0x5370> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5370;
	}
x86_l_51ed:
	/* 0x51ed: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_51f7:
	/* 0x51f7: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_51fc:
	/* 0x51fc: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_5206:
	/* 0x5206: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_520b:
	/* 0x520b: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_5215:
	/* 0x5215: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_521a:
	/* 0x521a: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_5224:
	/* 0x5224: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5229:
	/* 0x5229: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_5233:
	/* 0x5233: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5238:
	/* 0x5238: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_5242:
	/* 0x5242: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5247:
	/* 0x5247: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_524c:
	/* 0x524c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5251:
	/* 0x5251: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5256:
	/* 0x5256: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_525b:
	/* 0x525b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_525d:
	/* 0x525d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_525f:
	/* 0x525f: jmp    5370 <kprobe_unwind_ruby+0x5370> */
	goto x86_l_5370;
x86_l_5264:
	/* 0x5264: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_526b:
	/* 0x526b: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_526f:
	/* 0x526f: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_5275:
	/* 0x5275: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_527a:
	/* 0x527a: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_527d:
	/* 0x527d: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_5284:
	/* 0x5284: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_5288:
	/* 0x5288: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_528f:
	/* 0x528f: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5296:
	/* 0x5296: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_529e:
	/* 0x529e: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_52a6:
	/* 0x52a6: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_52b1:
	/* 0x52b1: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52b4:
	/* 0x52b4: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_52bc:
	/* 0x52bc: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_52c1:
	/* 0x52c1: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_52ca:
	/* 0x52ca: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_52d1:
	/* 0x52d1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_52d8:
	/* 0x52d8: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_52db:
	/* 0x52db: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_52e0:
	/* 0x52e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52e2:
	/* 0x52e2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_52e5:
	/* 0x52e5: je     52ef <kprobe_unwind_ruby+0x52ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_52ef;
	}
x86_l_52e7:
	/* 0x52e7: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_52ea:
	/* 0x52ea: jmp    5370 <kprobe_unwind_ruby+0x5370> */
	goto x86_l_5370;
x86_l_52ef:
	/* 0x52ef: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_52f6:
	/* 0x52f6: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52f9:
	/* 0x52f9: je     5370 <kprobe_unwind_ruby+0x5370> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5370;
	}
x86_l_52fb:
	/* 0x52fb: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_5305:
	/* 0x5305: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_530a:
	/* 0x530a: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_5314:
	/* 0x5314: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5319:
	/* 0x5319: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_5323:
	/* 0x5323: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5328:
	/* 0x5328: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_5332:
	/* 0x5332: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5337:
	/* 0x5337: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_5341:
	/* 0x5341: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5346:
	/* 0x5346: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_5350:
	/* 0x5350: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5355:
	/* 0x5355: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_535a:
	/* 0x535a: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_535f:
	/* 0x535f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5364:
	/* 0x5364: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5367:
	/* 0x5367: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_536c:
	/* 0x536c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_536e:
	/* 0x536e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5370:
	/* 0x5370: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5375:
	/* 0x5375: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_5378:
	/* 0x5378: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_537e:
	/* 0x537e: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_5383:
	/* 0x5383: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5386:
	/* 0x5386: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_538b:
	/* 0x538b: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5394:
	/* 0x5394: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_539d:
	/* 0x539d: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_53a2:
	/* 0x53a2: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_53a5:
	/* 0x53a5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_53aa:
	/* 0x53aa: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_53af:
	/* 0x53af: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_53b5:
	/* 0x53b5: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_53ba:
	/* 0x53ba: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_53bf:
	/* 0x53bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53c4:
	/* 0x53c4: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_53c7:
	/* 0x53c7: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_53cc:
	/* 0x53cc: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_53d1:
	/* 0x53d1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_53d6:
	/* 0x53d6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_53db:
	/* 0x53db: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_53e1:
	/* 0x53e1: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_53e6:
	/* 0x53e6: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_53eb:
	/* 0x53eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53f0:
	/* 0x53f0: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_53f3:
	/* 0x53f3: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_53f9:
	/* 0x53f9: je     54cc <kprobe_unwind_ruby+0x54cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54cc;
	}
x86_l_53ff:
	/* 0x53ff: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5404:
	/* 0x5404: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5407:
	/* 0x5407: je     54cc <kprobe_unwind_ruby+0x54cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54cc;
	}
x86_l_540d:
	/* 0x540d: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_5412:
	/* 0x5412: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5415:
	/* 0x5415: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_541a:
	/* 0x541a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_541f:
	/* 0x541f: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5425:
	/* 0x5425: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_542a:
	/* 0x542a: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_542f:
	/* 0x542f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5434:
	/* 0x5434: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5437:
	/* 0x5437: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_543a:
	/* 0x543a: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_5440:
	/* 0x5440: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_5445:
	/* 0x5445: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_544a:
	/* 0x544a: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_544f:
	/* 0x544f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5454:
	/* 0x5454: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_545a:
	/* 0x545a: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_545f:
	/* 0x545f: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5464:
	/* 0x5464: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5469:
	/* 0x5469: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_546c:
	/* 0x546c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_546f:
	/* 0x546f: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_5475:
	/* 0x5475: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_547a:
	/* 0x547a: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_547f:
	/* 0x547f: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_5484:
	/* 0x5484: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_5489:
	/* 0x5489: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_548f:
	/* 0x548f: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_5494:
	/* 0x5494: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5499:
	/* 0x5499: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_549e:
	/* 0x549e: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_54a1:
	/* 0x54a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_54a4:
	/* 0x54a4: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_54aa:
	/* 0x54aa: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_54af:
	/* 0x54af: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_54b2:
	/* 0x54b2: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_54b7:
	/* 0x54b7: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_54bc:
	/* 0x54bc: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_54bf:
	/* 0x54bf: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_54c3:
	/* 0x54c3: je     5529 <kprobe_unwind_ruby+0x5529> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5529;
	}
x86_l_54c5:
	/* 0x54c5: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_54c7:
	/* 0x54c7: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_54ca:
	/* 0x54ca: jmp    552d <kprobe_unwind_ruby+0x552d> */
	goto x86_l_552d;
x86_l_54cc:
	/* 0x54cc: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_54d3:
	/* 0x54d3: jb     56cd <kprobe_unwind_ruby+0x56cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_56cd;
	}
x86_l_54d9:
	/* 0x54d9: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54e1:
	/* 0x54e1: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_54e6:
	/* 0x54e6: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_54eb:
	/* 0x54eb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_54ee:
	/* 0x54ee: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_54f3:
	/* 0x54f3: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_54f9:
	/* 0x54f9: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_54fe:
	/* 0x54fe: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5503:
	/* 0x5503: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5508:
	/* 0x5508: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_550b:
	/* 0x550b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_550e:
	/* 0x550e: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_5514:
	/* 0x5514: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5517:
	/* 0x5517: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_5519:
	/* 0x5519: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_551e:
	/* 0x551e: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_5524:
	/* 0x5524: jmp    56cd <kprobe_unwind_ruby+0x56cd> */
	goto x86_l_56cd;
x86_l_5529:
	/* 0x5529: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_552b:
	/* 0x552b: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_552d:
	/* 0x552d: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_5531:
	/* 0x5531: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_5534:
	/* 0x5534: jbe    55c1 <kprobe_unwind_ruby+0x55c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_55c1;
	}
x86_l_553a:
	/* 0x553a: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5541:
	/* 0x5541: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5544:
	/* 0x5544: je     56cd <kprobe_unwind_ruby+0x56cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56cd;
	}
x86_l_554a:
	/* 0x554a: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_5554:
	/* 0x5554: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_5559:
	/* 0x5559: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_5563:
	/* 0x5563: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5568:
	/* 0x5568: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_5572:
	/* 0x5572: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5577:
	/* 0x5577: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_5581:
	/* 0x5581: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5586:
	/* 0x5586: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_5590:
	/* 0x5590: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5595:
	/* 0x5595: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_559f:
	/* 0x559f: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_55a4:
	/* 0x55a4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_55a9:
	/* 0x55a9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_55ae:
	/* 0x55ae: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_55b3:
	/* 0x55b3: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_55b8:
	/* 0x55b8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_55ba:
	/* 0x55ba: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_55bc:
	/* 0x55bc: jmp    56cd <kprobe_unwind_ruby+0x56cd> */
	goto x86_l_56cd;
x86_l_55c1:
	/* 0x55c1: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_55c8:
	/* 0x55c8: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_55cc:
	/* 0x55cc: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_55d2:
	/* 0x55d2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55d7:
	/* 0x55d7: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_55da:
	/* 0x55da: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_55e1:
	/* 0x55e1: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_55e5:
	/* 0x55e5: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_55ec:
	/* 0x55ec: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55f3:
	/* 0x55f3: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_55fb:
	/* 0x55fb: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_5603:
	/* 0x5603: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_560e:
	/* 0x560e: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5611:
	/* 0x5611: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_5619:
	/* 0x5619: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_561e:
	/* 0x561e: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_5627:
	/* 0x5627: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_562e:
	/* 0x562e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_5635:
	/* 0x5635: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_5638:
	/* 0x5638: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_563d:
	/* 0x563d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_563f:
	/* 0x563f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5642:
	/* 0x5642: je     564c <kprobe_unwind_ruby+0x564c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_564c;
	}
x86_l_5644:
	/* 0x5644: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_5647:
	/* 0x5647: jmp    56cd <kprobe_unwind_ruby+0x56cd> */
	goto x86_l_56cd;
x86_l_564c:
	/* 0x564c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5653:
	/* 0x5653: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5656:
	/* 0x5656: je     56cd <kprobe_unwind_ruby+0x56cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56cd;
	}
x86_l_5658:
	/* 0x5658: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_5662:
	/* 0x5662: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_5667:
	/* 0x5667: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_5671:
	/* 0x5671: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5676:
	/* 0x5676: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_5680:
	/* 0x5680: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5685:
	/* 0x5685: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_568f:
	/* 0x568f: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5694:
	/* 0x5694: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_569e:
	/* 0x569e: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_56a3:
	/* 0x56a3: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_56ad:
	/* 0x56ad: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_56b2:
	/* 0x56b2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_56b7:
	/* 0x56b7: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_56bc:
	/* 0x56bc: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_56c1:
	/* 0x56c1: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56c4:
	/* 0x56c4: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_56c9:
	/* 0x56c9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_56cb:
	/* 0x56cb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_56cd:
	/* 0x56cd: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56d2:
	/* 0x56d2: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_56d5:
	/* 0x56d5: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_56db:
	/* 0x56db: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_56e0:
	/* 0x56e0: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_56e3:
	/* 0x56e3: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56e8:
	/* 0x56e8: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_56f1:
	/* 0x56f1: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
	return 22266ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22266ULL: goto x86_l_56fa;
	case 22271ULL: goto x86_l_56ff;
	case 22274ULL: goto x86_l_5702;
	case 22279ULL: goto x86_l_5707;
	case 22284ULL: goto x86_l_570c;
	case 22290ULL: goto x86_l_5712;
	case 22295ULL: goto x86_l_5717;
	case 22300ULL: goto x86_l_571c;
	case 22305ULL: goto x86_l_5721;
	case 22308ULL: goto x86_l_5724;
	case 22313ULL: goto x86_l_5729;
	case 22318ULL: goto x86_l_572e;
	case 22323ULL: goto x86_l_5733;
	case 22328ULL: goto x86_l_5738;
	case 22334ULL: goto x86_l_573e;
	case 22339ULL: goto x86_l_5743;
	case 22344ULL: goto x86_l_5748;
	case 22349ULL: goto x86_l_574d;
	case 22352ULL: goto x86_l_5750;
	case 22358ULL: goto x86_l_5756;
	case 22364ULL: goto x86_l_575c;
	case 22369ULL: goto x86_l_5761;
	case 22372ULL: goto x86_l_5764;
	case 22378ULL: goto x86_l_576a;
	case 22383ULL: goto x86_l_576f;
	case 22386ULL: goto x86_l_5772;
	case 22391ULL: goto x86_l_5777;
	case 22396ULL: goto x86_l_577c;
	case 22402ULL: goto x86_l_5782;
	case 22407ULL: goto x86_l_5787;
	case 22412ULL: goto x86_l_578c;
	case 22417ULL: goto x86_l_5791;
	case 22420ULL: goto x86_l_5794;
	case 22423ULL: goto x86_l_5797;
	case 22429ULL: goto x86_l_579d;
	case 22434ULL: goto x86_l_57a2;
	case 22439ULL: goto x86_l_57a7;
	case 22444ULL: goto x86_l_57ac;
	case 22449ULL: goto x86_l_57b1;
	case 22455ULL: goto x86_l_57b7;
	case 22460ULL: goto x86_l_57bc;
	case 22465ULL: goto x86_l_57c1;
	case 22470ULL: goto x86_l_57c6;
	case 22473ULL: goto x86_l_57c9;
	case 22476ULL: goto x86_l_57cc;
	case 22482ULL: goto x86_l_57d2;
	case 22487ULL: goto x86_l_57d7;
	case 22492ULL: goto x86_l_57dc;
	case 22497ULL: goto x86_l_57e1;
	case 22502ULL: goto x86_l_57e6;
	case 22508ULL: goto x86_l_57ec;
	case 22513ULL: goto x86_l_57f1;
	case 22518ULL: goto x86_l_57f6;
	case 22523ULL: goto x86_l_57fb;
	case 22526ULL: goto x86_l_57fe;
	case 22529ULL: goto x86_l_5801;
	case 22535ULL: goto x86_l_5807;
	case 22540ULL: goto x86_l_580c;
	case 22543ULL: goto x86_l_580f;
	case 22548ULL: goto x86_l_5814;
	case 22553ULL: goto x86_l_5819;
	case 22556ULL: goto x86_l_581c;
	case 22560ULL: goto x86_l_5820;
	case 22562ULL: goto x86_l_5822;
	case 22564ULL: goto x86_l_5824;
	case 22567ULL: goto x86_l_5827;
	case 22569ULL: goto x86_l_5829;
	case 22576ULL: goto x86_l_5830;
	case 22582ULL: goto x86_l_5836;
	case 22590ULL: goto x86_l_583e;
	case 22595ULL: goto x86_l_5843;
	case 22600ULL: goto x86_l_5848;
	case 22603ULL: goto x86_l_584b;
	case 22608ULL: goto x86_l_5850;
	case 22614ULL: goto x86_l_5856;
	case 22619ULL: goto x86_l_585b;
	case 22624ULL: goto x86_l_5860;
	case 22629ULL: goto x86_l_5865;
	case 22632ULL: goto x86_l_5868;
	case 22635ULL: goto x86_l_586b;
	case 22641ULL: goto x86_l_5871;
	case 22644ULL: goto x86_l_5874;
	case 22646ULL: goto x86_l_5876;
	case 22651ULL: goto x86_l_587b;
	case 22657ULL: goto x86_l_5881;
	case 22662ULL: goto x86_l_5886;
	case 22664ULL: goto x86_l_5888;
	case 22666ULL: goto x86_l_588a;
	case 22670ULL: goto x86_l_588e;
	case 22673ULL: goto x86_l_5891;
	case 22679ULL: goto x86_l_5897;
	case 22686ULL: goto x86_l_589e;
	case 22689ULL: goto x86_l_58a1;
	case 22695ULL: goto x86_l_58a7;
	case 22705ULL: goto x86_l_58b1;
	case 22710ULL: goto x86_l_58b6;
	case 22720ULL: goto x86_l_58c0;
	case 22725ULL: goto x86_l_58c5;
	case 22735ULL: goto x86_l_58cf;
	case 22740ULL: goto x86_l_58d4;
	case 22750ULL: goto x86_l_58de;
	case 22755ULL: goto x86_l_58e3;
	case 22765ULL: goto x86_l_58ed;
	case 22770ULL: goto x86_l_58f2;
	case 22780ULL: goto x86_l_58fc;
	case 22785ULL: goto x86_l_5901;
	case 22790ULL: goto x86_l_5906;
	case 22795ULL: goto x86_l_590b;
	case 22800ULL: goto x86_l_5910;
	case 22805ULL: goto x86_l_5915;
	case 22807ULL: goto x86_l_5917;
	case 22809ULL: goto x86_l_5919;
	case 22814ULL: goto x86_l_591e;
	case 22821ULL: goto x86_l_5925;
	case 22825ULL: goto x86_l_5929;
	case 22831ULL: goto x86_l_592f;
	case 22836ULL: goto x86_l_5934;
	case 22839ULL: goto x86_l_5937;
	case 22846ULL: goto x86_l_593e;
	case 22850ULL: goto x86_l_5942;
	case 22857ULL: goto x86_l_5949;
	case 22864ULL: goto x86_l_5950;
	case 22872ULL: goto x86_l_5958;
	case 22880ULL: goto x86_l_5960;
	case 22891ULL: goto x86_l_596b;
	case 22894ULL: goto x86_l_596e;
	case 22902ULL: goto x86_l_5976;
	case 22907ULL: goto x86_l_597b;
	case 22916ULL: goto x86_l_5984;
	case 22923ULL: goto x86_l_598b;
	case 22930ULL: goto x86_l_5992;
	case 22933ULL: goto x86_l_5995;
	case 22938ULL: goto x86_l_599a;
	case 22940ULL: goto x86_l_599c;
	case 22943ULL: goto x86_l_599f;
	case 22945ULL: goto x86_l_59a1;
	case 22948ULL: goto x86_l_59a4;
	case 22953ULL: goto x86_l_59a9;
	case 22960ULL: goto x86_l_59b0;
	case 22963ULL: goto x86_l_59b3;
	case 22965ULL: goto x86_l_59b5;
	case 22975ULL: goto x86_l_59bf;
	case 22980ULL: goto x86_l_59c4;
	case 22990ULL: goto x86_l_59ce;
	case 22995ULL: goto x86_l_59d3;
	case 23005ULL: goto x86_l_59dd;
	case 23010ULL: goto x86_l_59e2;
	case 23020ULL: goto x86_l_59ec;
	case 23025ULL: goto x86_l_59f1;
	case 23035ULL: goto x86_l_59fb;
	case 23040ULL: goto x86_l_5a00;
	case 23050ULL: goto x86_l_5a0a;
	case 23055ULL: goto x86_l_5a0f;
	case 23060ULL: goto x86_l_5a14;
	case 23065ULL: goto x86_l_5a19;
	case 23070ULL: goto x86_l_5a1e;
	case 23073ULL: goto x86_l_5a21;
	case 23078ULL: goto x86_l_5a26;
	case 23080ULL: goto x86_l_5a28;
	case 23082ULL: goto x86_l_5a2a;
	case 23087ULL: goto x86_l_5a2f;
	case 23090ULL: goto x86_l_5a32;
	case 23096ULL: goto x86_l_5a38;
	case 23101ULL: goto x86_l_5a3d;
	case 23104ULL: goto x86_l_5a40;
	case 23109ULL: goto x86_l_5a45;
	case 23118ULL: goto x86_l_5a4e;
	case 23127ULL: goto x86_l_5a57;
	case 23132ULL: goto x86_l_5a5c;
	case 23135ULL: goto x86_l_5a5f;
	case 23140ULL: goto x86_l_5a64;
	case 23145ULL: goto x86_l_5a69;
	case 23151ULL: goto x86_l_5a6f;
	case 23156ULL: goto x86_l_5a74;
	case 23161ULL: goto x86_l_5a79;
	case 23166ULL: goto x86_l_5a7e;
	case 23169ULL: goto x86_l_5a81;
	case 23174ULL: goto x86_l_5a86;
	case 23179ULL: goto x86_l_5a8b;
	case 23184ULL: goto x86_l_5a90;
	case 23189ULL: goto x86_l_5a95;
	case 23195ULL: goto x86_l_5a9b;
	case 23200ULL: goto x86_l_5aa0;
	case 23205ULL: goto x86_l_5aa5;
	case 23210ULL: goto x86_l_5aaa;
	case 23213ULL: goto x86_l_5aad;
	case 23219ULL: goto x86_l_5ab3;
	case 23225ULL: goto x86_l_5ab9;
	case 23230ULL: goto x86_l_5abe;
	case 23233ULL: goto x86_l_5ac1;
	case 23239ULL: goto x86_l_5ac7;
	case 23244ULL: goto x86_l_5acc;
	case 23247ULL: goto x86_l_5acf;
	case 23252ULL: goto x86_l_5ad4;
	case 23257ULL: goto x86_l_5ad9;
	case 23263ULL: goto x86_l_5adf;
	case 23268ULL: goto x86_l_5ae4;
	case 23273ULL: goto x86_l_5ae9;
	case 23278ULL: goto x86_l_5aee;
	case 23281ULL: goto x86_l_5af1;
	case 23284ULL: goto x86_l_5af4;
	case 23290ULL: goto x86_l_5afa;
	case 23295ULL: goto x86_l_5aff;
	case 23300ULL: goto x86_l_5b04;
	case 23305ULL: goto x86_l_5b09;
	case 23310ULL: goto x86_l_5b0e;
	case 23316ULL: goto x86_l_5b14;
	case 23321ULL: goto x86_l_5b19;
	case 23326ULL: goto x86_l_5b1e;
	case 23331ULL: goto x86_l_5b23;
	case 23334ULL: goto x86_l_5b26;
	case 23337ULL: goto x86_l_5b29;
	case 23343ULL: goto x86_l_5b2f;
	case 23348ULL: goto x86_l_5b34;
	case 23353ULL: goto x86_l_5b39;
	case 23358ULL: goto x86_l_5b3e;
	case 23363ULL: goto x86_l_5b43;
	case 23369ULL: goto x86_l_5b49;
	case 23374ULL: goto x86_l_5b4e;
	case 23379ULL: goto x86_l_5b53;
	case 23384ULL: goto x86_l_5b58;
	case 23387ULL: goto x86_l_5b5b;
	case 23390ULL: goto x86_l_5b5e;
	case 23396ULL: goto x86_l_5b64;
	case 23401ULL: goto x86_l_5b69;
	case 23404ULL: goto x86_l_5b6c;
	case 23409ULL: goto x86_l_5b71;
	case 23414ULL: goto x86_l_5b76;
	case 23417ULL: goto x86_l_5b79;
	case 23421ULL: goto x86_l_5b7d;
	case 23423ULL: goto x86_l_5b7f;
	case 23425ULL: goto x86_l_5b81;
	case 23428ULL: goto x86_l_5b84;
	case 23430ULL: goto x86_l_5b86;
	case 23437ULL: goto x86_l_5b8d;
	case 23443ULL: goto x86_l_5b93;
	case 23451ULL: goto x86_l_5b9b;
	case 23456ULL: goto x86_l_5ba0;
	case 23461ULL: goto x86_l_5ba5;
	case 23464ULL: goto x86_l_5ba8;
	case 23469ULL: goto x86_l_5bad;
	case 23475ULL: goto x86_l_5bb3;
	case 23480ULL: goto x86_l_5bb8;
	case 23485ULL: goto x86_l_5bbd;
	case 23490ULL: goto x86_l_5bc2;
	case 23493ULL: goto x86_l_5bc5;
	case 23496ULL: goto x86_l_5bc8;
	case 23502ULL: goto x86_l_5bce;
	case 23505ULL: goto x86_l_5bd1;
	case 23507ULL: goto x86_l_5bd3;
	case 23512ULL: goto x86_l_5bd8;
	case 23518ULL: goto x86_l_5bde;
	case 23523ULL: goto x86_l_5be3;
	case 23525ULL: goto x86_l_5be5;
	case 23527ULL: goto x86_l_5be7;
	case 23531ULL: goto x86_l_5beb;
	case 23534ULL: goto x86_l_5bee;
	case 23540ULL: goto x86_l_5bf4;
	case 23547ULL: goto x86_l_5bfb;
	case 23550ULL: goto x86_l_5bfe;
	case 23556ULL: goto x86_l_5c04;
	case 23566ULL: goto x86_l_5c0e;
	case 23571ULL: goto x86_l_5c13;
	case 23581ULL: goto x86_l_5c1d;
	case 23586ULL: goto x86_l_5c22;
	case 23596ULL: goto x86_l_5c2c;
	case 23601ULL: goto x86_l_5c31;
	case 23611ULL: goto x86_l_5c3b;
	case 23616ULL: goto x86_l_5c40;
	case 23626ULL: goto x86_l_5c4a;
	case 23631ULL: goto x86_l_5c4f;
	case 23641ULL: goto x86_l_5c59;
	case 23646ULL: goto x86_l_5c5e;
	case 23651ULL: goto x86_l_5c63;
	case 23656ULL: goto x86_l_5c68;
	case 23661ULL: goto x86_l_5c6d;
	case 23666ULL: goto x86_l_5c72;
	case 23668ULL: goto x86_l_5c74;
	case 23670ULL: goto x86_l_5c76;
	case 23675ULL: goto x86_l_5c7b;
	case 23682ULL: goto x86_l_5c82;
	case 23686ULL: goto x86_l_5c86;
	case 23692ULL: goto x86_l_5c8c;
	case 23697ULL: goto x86_l_5c91;
	case 23700ULL: goto x86_l_5c94;
	case 23707ULL: goto x86_l_5c9b;
	case 23711ULL: goto x86_l_5c9f;
	case 23718ULL: goto x86_l_5ca6;
	case 23725ULL: goto x86_l_5cad;
	case 23733ULL: goto x86_l_5cb5;
	case 23741ULL: goto x86_l_5cbd;
	case 23752ULL: goto x86_l_5cc8;
	case 23755ULL: goto x86_l_5ccb;
	case 23763ULL: goto x86_l_5cd3;
	case 23768ULL: goto x86_l_5cd8;
	case 23777ULL: goto x86_l_5ce1;
	case 23784ULL: goto x86_l_5ce8;
	case 23791ULL: goto x86_l_5cef;
	case 23794ULL: goto x86_l_5cf2;
	case 23799ULL: goto x86_l_5cf7;
	case 23801ULL: goto x86_l_5cf9;
	case 23804ULL: goto x86_l_5cfc;
	case 23806ULL: goto x86_l_5cfe;
	case 23809ULL: goto x86_l_5d01;
	case 23814ULL: goto x86_l_5d06;
	case 23821ULL: goto x86_l_5d0d;
	case 23824ULL: goto x86_l_5d10;
	case 23826ULL: goto x86_l_5d12;
	case 23836ULL: goto x86_l_5d1c;
	case 23841ULL: goto x86_l_5d21;
	case 23851ULL: goto x86_l_5d2b;
	case 23856ULL: goto x86_l_5d30;
	case 23866ULL: goto x86_l_5d3a;
	case 23871ULL: goto x86_l_5d3f;
	case 23881ULL: goto x86_l_5d49;
	case 23886ULL: goto x86_l_5d4e;
	case 23896ULL: goto x86_l_5d58;
	case 23901ULL: goto x86_l_5d5d;
	case 23911ULL: goto x86_l_5d67;
	case 23916ULL: goto x86_l_5d6c;
	case 23921ULL: goto x86_l_5d71;
	case 23926ULL: goto x86_l_5d76;
	case 23931ULL: goto x86_l_5d7b;
	case 23934ULL: goto x86_l_5d7e;
	case 23939ULL: goto x86_l_5d83;
	case 23941ULL: goto x86_l_5d85;
	case 23943ULL: goto x86_l_5d87;
	case 23948ULL: goto x86_l_5d8c;
	case 23951ULL: goto x86_l_5d8f;
	case 23957ULL: goto x86_l_5d95;
	case 23962ULL: goto x86_l_5d9a;
	case 23965ULL: goto x86_l_5d9d;
	case 23970ULL: goto x86_l_5da2;
	case 23979ULL: goto x86_l_5dab;
	case 23988ULL: goto x86_l_5db4;
	case 23993ULL: goto x86_l_5db9;
	case 23996ULL: goto x86_l_5dbc;
	case 24001ULL: goto x86_l_5dc1;
	case 24006ULL: goto x86_l_5dc6;
	case 24012ULL: goto x86_l_5dcc;
	case 24017ULL: goto x86_l_5dd1;
	case 24022ULL: goto x86_l_5dd6;
	case 24027ULL: goto x86_l_5ddb;
	case 24030ULL: goto x86_l_5dde;
	case 24035ULL: goto x86_l_5de3;
	case 24040ULL: goto x86_l_5de8;
	case 24045ULL: goto x86_l_5ded;
	case 24050ULL: goto x86_l_5df2;
	case 24056ULL: goto x86_l_5df8;
	case 24061ULL: goto x86_l_5dfd;
	case 24066ULL: goto x86_l_5e02;
	case 24071ULL: goto x86_l_5e07;
	case 24074ULL: goto x86_l_5e0a;
	case 24080ULL: goto x86_l_5e10;
	case 24086ULL: goto x86_l_5e16;
	case 24091ULL: goto x86_l_5e1b;
	case 24094ULL: goto x86_l_5e1e;
	case 24100ULL: goto x86_l_5e24;
	case 24105ULL: goto x86_l_5e29;
	case 24108ULL: goto x86_l_5e2c;
	case 24113ULL: goto x86_l_5e31;
	case 24118ULL: goto x86_l_5e36;
	case 24124ULL: goto x86_l_5e3c;
	case 24129ULL: goto x86_l_5e41;
	case 24134ULL: goto x86_l_5e46;
	case 24139ULL: goto x86_l_5e4b;
	case 24142ULL: goto x86_l_5e4e;
	case 24145ULL: goto x86_l_5e51;
	case 24151ULL: goto x86_l_5e57;
	case 24156ULL: goto x86_l_5e5c;
	case 24161ULL: goto x86_l_5e61;
	case 24166ULL: goto x86_l_5e66;
	case 24171ULL: goto x86_l_5e6b;
	case 24177ULL: goto x86_l_5e71;
	case 24182ULL: goto x86_l_5e76;
	case 24187ULL: goto x86_l_5e7b;
	case 24192ULL: goto x86_l_5e80;
	case 24195ULL: goto x86_l_5e83;
	case 24198ULL: goto x86_l_5e86;
	case 24204ULL: goto x86_l_5e8c;
	case 24209ULL: goto x86_l_5e91;
	case 24214ULL: goto x86_l_5e96;
	case 24219ULL: goto x86_l_5e9b;
	case 24224ULL: goto x86_l_5ea0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_56fa:
	/* 0x56fa: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_56ff:
	/* 0x56ff: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5702:
	/* 0x5702: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5707:
	/* 0x5707: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_570c:
	/* 0x570c: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5712:
	/* 0x5712: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_5717:
	/* 0x5717: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_571c:
	/* 0x571c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5721:
	/* 0x5721: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5724:
	/* 0x5724: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_5729:
	/* 0x5729: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_572e:
	/* 0x572e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5733:
	/* 0x5733: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5738:
	/* 0x5738: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_573e:
	/* 0x573e: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_5743:
	/* 0x5743: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5748:
	/* 0x5748: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_574d:
	/* 0x574d: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5750:
	/* 0x5750: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5756:
	/* 0x5756: je     5829 <kprobe_unwind_ruby+0x5829> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5829;
	}
x86_l_575c:
	/* 0x575c: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5761:
	/* 0x5761: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5764:
	/* 0x5764: je     5829 <kprobe_unwind_ruby+0x5829> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5829;
	}
x86_l_576a:
	/* 0x576a: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_576f:
	/* 0x576f: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5772:
	/* 0x5772: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5777:
	/* 0x5777: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_577c:
	/* 0x577c: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5782:
	/* 0x5782: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_5787:
	/* 0x5787: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_578c:
	/* 0x578c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5791:
	/* 0x5791: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5794:
	/* 0x5794: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5797:
	/* 0x5797: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_579d:
	/* 0x579d: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_57a2:
	/* 0x57a2: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_57a7:
	/* 0x57a7: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_57ac:
	/* 0x57ac: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_57b1:
	/* 0x57b1: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_57b7:
	/* 0x57b7: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_57bc:
	/* 0x57bc: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_57c1:
	/* 0x57c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57c6:
	/* 0x57c6: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_57c9:
	/* 0x57c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_57cc:
	/* 0x57cc: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_57d2:
	/* 0x57d2: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_57d7:
	/* 0x57d7: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_57dc:
	/* 0x57dc: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_57e1:
	/* 0x57e1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_57e6:
	/* 0x57e6: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_57ec:
	/* 0x57ec: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_57f1:
	/* 0x57f1: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_57f6:
	/* 0x57f6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_57fb:
	/* 0x57fb: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_57fe:
	/* 0x57fe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5801:
	/* 0x5801: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_5807:
	/* 0x5807: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_580c:
	/* 0x580c: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_580f:
	/* 0x580f: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_5814:
	/* 0x5814: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_5819:
	/* 0x5819: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_581c:
	/* 0x581c: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_5820:
	/* 0x5820: je     5886 <kprobe_unwind_ruby+0x5886> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5886;
	}
x86_l_5822:
	/* 0x5822: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5824:
	/* 0x5824: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_5827:
	/* 0x5827: jmp    588a <kprobe_unwind_ruby+0x588a> */
	goto x86_l_588a;
x86_l_5829:
	/* 0x5829: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_5830:
	/* 0x5830: jb     5a2a <kprobe_unwind_ruby+0x5a2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5a2a;
	}
x86_l_5836:
	/* 0x5836: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_583e:
	/* 0x583e: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_5843:
	/* 0x5843: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5848:
	/* 0x5848: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_584b:
	/* 0x584b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5850:
	/* 0x5850: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5856:
	/* 0x5856: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_585b:
	/* 0x585b: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5860:
	/* 0x5860: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5865:
	/* 0x5865: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5868:
	/* 0x5868: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_586b:
	/* 0x586b: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_5871:
	/* 0x5871: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5874:
	/* 0x5874: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_5876:
	/* 0x5876: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_587b:
	/* 0x587b: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_5881:
	/* 0x5881: jmp    5a2a <kprobe_unwind_ruby+0x5a2a> */
	goto x86_l_5a2a;
x86_l_5886:
	/* 0x5886: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5888:
	/* 0x5888: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_588a:
	/* 0x588a: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_588e:
	/* 0x588e: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_5891:
	/* 0x5891: jbe    591e <kprobe_unwind_ruby+0x591e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_591e;
	}
x86_l_5897:
	/* 0x5897: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_589e:
	/* 0x589e: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58a1:
	/* 0x58a1: je     5a2a <kprobe_unwind_ruby+0x5a2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a2a;
	}
x86_l_58a7:
	/* 0x58a7: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_58b1:
	/* 0x58b1: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_58b6:
	/* 0x58b6: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_58c0:
	/* 0x58c0: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_58c5:
	/* 0x58c5: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_58cf:
	/* 0x58cf: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_58d4:
	/* 0x58d4: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_58de:
	/* 0x58de: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_58e3:
	/* 0x58e3: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_58ed:
	/* 0x58ed: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_58f2:
	/* 0x58f2: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_58fc:
	/* 0x58fc: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5901:
	/* 0x5901: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5906:
	/* 0x5906: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_590b:
	/* 0x590b: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5910:
	/* 0x5910: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_5915:
	/* 0x5915: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5917:
	/* 0x5917: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5919:
	/* 0x5919: jmp    5a2a <kprobe_unwind_ruby+0x5a2a> */
	goto x86_l_5a2a;
x86_l_591e:
	/* 0x591e: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_5925:
	/* 0x5925: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_5929:
	/* 0x5929: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_592f:
	/* 0x592f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5934:
	/* 0x5934: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5937:
	/* 0x5937: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_593e:
	/* 0x593e: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_5942:
	/* 0x5942: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_5949:
	/* 0x5949: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5950:
	/* 0x5950: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_5958:
	/* 0x5958: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_5960:
	/* 0x5960: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_596b:
	/* 0x596b: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_596e:
	/* 0x596e: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_5976:
	/* 0x5976: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_597b:
	/* 0x597b: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_5984:
	/* 0x5984: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_598b:
	/* 0x598b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_5992:
	/* 0x5992: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_5995:
	/* 0x5995: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_599a:
	/* 0x599a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_599c:
	/* 0x599c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_599f:
	/* 0x599f: je     59a9 <kprobe_unwind_ruby+0x59a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59a9;
	}
x86_l_59a1:
	/* 0x59a1: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_59a4:
	/* 0x59a4: jmp    5a2a <kprobe_unwind_ruby+0x5a2a> */
	goto x86_l_5a2a;
x86_l_59a9:
	/* 0x59a9: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_59b0:
	/* 0x59b0: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59b3:
	/* 0x59b3: je     5a2a <kprobe_unwind_ruby+0x5a2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a2a;
	}
x86_l_59b5:
	/* 0x59b5: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_59bf:
	/* 0x59bf: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_59c4:
	/* 0x59c4: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_59ce:
	/* 0x59ce: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_59d3:
	/* 0x59d3: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_59dd:
	/* 0x59dd: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_59e2:
	/* 0x59e2: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_59ec:
	/* 0x59ec: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_59f1:
	/* 0x59f1: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_59fb:
	/* 0x59fb: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5a00:
	/* 0x5a00: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_5a0a:
	/* 0x5a0a: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5a0f:
	/* 0x5a0f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5a14:
	/* 0x5a14: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_5a19:
	/* 0x5a19: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5a1e:
	/* 0x5a1e: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a21:
	/* 0x5a21: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_5a26:
	/* 0x5a26: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5a28:
	/* 0x5a28: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5a2a:
	/* 0x5a2a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a2f:
	/* 0x5a2f: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_5a32:
	/* 0x5a32: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_5a38:
	/* 0x5a38: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_5a3d:
	/* 0x5a3d: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5a40:
	/* 0x5a40: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a45:
	/* 0x5a45: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5a4e:
	/* 0x5a4e: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5a57:
	/* 0x5a57: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_5a5c:
	/* 0x5a5c: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5a5f:
	/* 0x5a5f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5a64:
	/* 0x5a64: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_5a69:
	/* 0x5a69: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5a6f:
	/* 0x5a6f: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_5a74:
	/* 0x5a74: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5a79:
	/* 0x5a79: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a7e:
	/* 0x5a7e: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5a81:
	/* 0x5a81: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_5a86:
	/* 0x5a86: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5a8b:
	/* 0x5a8b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5a90:
	/* 0x5a90: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5a95:
	/* 0x5a95: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5a9b:
	/* 0x5a9b: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_5aa0:
	/* 0x5aa0: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5aa5:
	/* 0x5aa5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5aaa:
	/* 0x5aaa: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5aad:
	/* 0x5aad: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5ab3:
	/* 0x5ab3: je     5b86 <kprobe_unwind_ruby+0x5b86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b86;
	}
x86_l_5ab9:
	/* 0x5ab9: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5abe:
	/* 0x5abe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5ac1:
	/* 0x5ac1: je     5b86 <kprobe_unwind_ruby+0x5b86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b86;
	}
x86_l_5ac7:
	/* 0x5ac7: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_5acc:
	/* 0x5acc: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5acf:
	/* 0x5acf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ad4:
	/* 0x5ad4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5ad9:
	/* 0x5ad9: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5adf:
	/* 0x5adf: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_5ae4:
	/* 0x5ae4: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_5ae9:
	/* 0x5ae9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5aee:
	/* 0x5aee: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5af1:
	/* 0x5af1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5af4:
	/* 0x5af4: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_5afa:
	/* 0x5afa: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_5aff:
	/* 0x5aff: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5b04:
	/* 0x5b04: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5b09:
	/* 0x5b09: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5b0e:
	/* 0x5b0e: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5b14:
	/* 0x5b14: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_5b19:
	/* 0x5b19: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5b1e:
	/* 0x5b1e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b23:
	/* 0x5b23: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5b26:
	/* 0x5b26: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b29:
	/* 0x5b29: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_5b2f:
	/* 0x5b2f: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_5b34:
	/* 0x5b34: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5b39:
	/* 0x5b39: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_5b3e:
	/* 0x5b3e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_5b43:
	/* 0x5b43: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5b49:
	/* 0x5b49: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_5b4e:
	/* 0x5b4e: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5b53:
	/* 0x5b53: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5b58:
	/* 0x5b58: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5b5b:
	/* 0x5b5b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b5e:
	/* 0x5b5e: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_5b64:
	/* 0x5b64: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b69:
	/* 0x5b69: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_5b6c:
	/* 0x5b6c: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_5b71:
	/* 0x5b71: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_5b76:
	/* 0x5b76: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5b79:
	/* 0x5b79: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_5b7d:
	/* 0x5b7d: je     5be3 <kprobe_unwind_ruby+0x5be3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5be3;
	}
x86_l_5b7f:
	/* 0x5b7f: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b81:
	/* 0x5b81: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_5b84:
	/* 0x5b84: jmp    5be7 <kprobe_unwind_ruby+0x5be7> */
	goto x86_l_5be7;
x86_l_5b86:
	/* 0x5b86: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_5b8d:
	/* 0x5b8d: jb     5d87 <kprobe_unwind_ruby+0x5d87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5d87;
	}
x86_l_5b93:
	/* 0x5b93: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b9b:
	/* 0x5b9b: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_5ba0:
	/* 0x5ba0: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5ba5:
	/* 0x5ba5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5ba8:
	/* 0x5ba8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5bad:
	/* 0x5bad: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5bb3:
	/* 0x5bb3: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_5bb8:
	/* 0x5bb8: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5bbd:
	/* 0x5bbd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5bc2:
	/* 0x5bc2: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5bc5:
	/* 0x5bc5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5bc8:
	/* 0x5bc8: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_5bce:
	/* 0x5bce: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bd1:
	/* 0x5bd1: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_5bd3:
	/* 0x5bd3: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_5bd8:
	/* 0x5bd8: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_5bde:
	/* 0x5bde: jmp    5d87 <kprobe_unwind_ruby+0x5d87> */
	goto x86_l_5d87;
x86_l_5be3:
	/* 0x5be3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5be5:
	/* 0x5be5: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_5be7:
	/* 0x5be7: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_5beb:
	/* 0x5beb: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_5bee:
	/* 0x5bee: jbe    5c7b <kprobe_unwind_ruby+0x5c7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_5c7b;
	}
x86_l_5bf4:
	/* 0x5bf4: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5bfb:
	/* 0x5bfb: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bfe:
	/* 0x5bfe: je     5d87 <kprobe_unwind_ruby+0x5d87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d87;
	}
x86_l_5c04:
	/* 0x5c04: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_5c0e:
	/* 0x5c0e: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_5c13:
	/* 0x5c13: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_5c1d:
	/* 0x5c1d: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5c22:
	/* 0x5c22: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_5c2c:
	/* 0x5c2c: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5c31:
	/* 0x5c31: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_5c3b:
	/* 0x5c3b: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5c40:
	/* 0x5c40: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_5c4a:
	/* 0x5c4a: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5c4f:
	/* 0x5c4f: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_5c59:
	/* 0x5c59: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5c5e:
	/* 0x5c5e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5c63:
	/* 0x5c63: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5c68:
	/* 0x5c68: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5c6d:
	/* 0x5c6d: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_5c72:
	/* 0x5c72: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c74:
	/* 0x5c74: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5c76:
	/* 0x5c76: jmp    5d87 <kprobe_unwind_ruby+0x5d87> */
	goto x86_l_5d87;
x86_l_5c7b:
	/* 0x5c7b: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_5c82:
	/* 0x5c82: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_5c86:
	/* 0x5c86: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_5c8c:
	/* 0x5c8c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c91:
	/* 0x5c91: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5c94:
	/* 0x5c94: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_5c9b:
	/* 0x5c9b: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_5c9f:
	/* 0x5c9f: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_5ca6:
	/* 0x5ca6: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cad:
	/* 0x5cad: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_5cb5:
	/* 0x5cb5: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_5cbd:
	/* 0x5cbd: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_5cc8:
	/* 0x5cc8: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ccb:
	/* 0x5ccb: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_5cd3:
	/* 0x5cd3: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_5cd8:
	/* 0x5cd8: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_5ce1:
	/* 0x5ce1: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_5ce8:
	/* 0x5ce8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_5cef:
	/* 0x5cef: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_5cf2:
	/* 0x5cf2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5cf7:
	/* 0x5cf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cf9:
	/* 0x5cf9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5cfc:
	/* 0x5cfc: je     5d06 <kprobe_unwind_ruby+0x5d06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d06;
	}
x86_l_5cfe:
	/* 0x5cfe: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_5d01:
	/* 0x5d01: jmp    5d87 <kprobe_unwind_ruby+0x5d87> */
	goto x86_l_5d87;
x86_l_5d06:
	/* 0x5d06: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5d0d:
	/* 0x5d0d: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d10:
	/* 0x5d10: je     5d87 <kprobe_unwind_ruby+0x5d87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d87;
	}
x86_l_5d12:
	/* 0x5d12: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_5d1c:
	/* 0x5d1c: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_5d21:
	/* 0x5d21: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_5d2b:
	/* 0x5d2b: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5d30:
	/* 0x5d30: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_5d3a:
	/* 0x5d3a: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5d3f:
	/* 0x5d3f: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_5d49:
	/* 0x5d49: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5d4e:
	/* 0x5d4e: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_5d58:
	/* 0x5d58: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5d5d:
	/* 0x5d5d: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_5d67:
	/* 0x5d67: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5d6c:
	/* 0x5d6c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5d71:
	/* 0x5d71: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_5d76:
	/* 0x5d76: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5d7b:
	/* 0x5d7b: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d7e:
	/* 0x5d7e: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_5d83:
	/* 0x5d83: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d85:
	/* 0x5d85: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5d87:
	/* 0x5d87: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d8c:
	/* 0x5d8c: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_5d8f:
	/* 0x5d8f: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_5d95:
	/* 0x5d95: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_5d9a:
	/* 0x5d9a: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5d9d:
	/* 0x5d9d: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5da2:
	/* 0x5da2: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5dab:
	/* 0x5dab: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5db4:
	/* 0x5db4: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_5db9:
	/* 0x5db9: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5dbc:
	/* 0x5dbc: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5dc1:
	/* 0x5dc1: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_5dc6:
	/* 0x5dc6: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5dcc:
	/* 0x5dcc: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_5dd1:
	/* 0x5dd1: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5dd6:
	/* 0x5dd6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ddb:
	/* 0x5ddb: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5dde:
	/* 0x5dde: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_5de3:
	/* 0x5de3: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5de8:
	/* 0x5de8: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ded:
	/* 0x5ded: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5df2:
	/* 0x5df2: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5df8:
	/* 0x5df8: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_5dfd:
	/* 0x5dfd: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5e02:
	/* 0x5e02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e07:
	/* 0x5e07: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5e0a:
	/* 0x5e0a: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5e10:
	/* 0x5e10: je     5ee3 <kprobe_unwind_ruby+0x5ee3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24291ULL;
	}
x86_l_5e16:
	/* 0x5e16: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e1b:
	/* 0x5e1b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5e1e:
	/* 0x5e1e: je     5ee3 <kprobe_unwind_ruby+0x5ee3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24291ULL;
	}
x86_l_5e24:
	/* 0x5e24: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_5e29:
	/* 0x5e29: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5e2c:
	/* 0x5e2c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e31:
	/* 0x5e31: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5e36:
	/* 0x5e36: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5e3c:
	/* 0x5e3c: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_5e41:
	/* 0x5e41: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_5e46:
	/* 0x5e46: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e4b:
	/* 0x5e4b: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5e4e:
	/* 0x5e4e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5e51:
	/* 0x5e51: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_5e57:
	/* 0x5e57: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_5e5c:
	/* 0x5e5c: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5e61:
	/* 0x5e61: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5e66:
	/* 0x5e66: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5e6b:
	/* 0x5e6b: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5e71:
	/* 0x5e71: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_5e76:
	/* 0x5e76: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5e7b:
	/* 0x5e7b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e80:
	/* 0x5e80: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5e83:
	/* 0x5e83: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5e86:
	/* 0x5e86: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_5e8c:
	/* 0x5e8c: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_5e91:
	/* 0x5e91: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5e96:
	/* 0x5e96: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_5e9b:
	/* 0x5e9b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_5ea0:
	/* 0x5ea0: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
	return 24230ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 24230ULL: goto x86_l_5ea6;
	case 24235ULL: goto x86_l_5eab;
	case 24240ULL: goto x86_l_5eb0;
	case 24245ULL: goto x86_l_5eb5;
	case 24248ULL: goto x86_l_5eb8;
	case 24251ULL: goto x86_l_5ebb;
	case 24257ULL: goto x86_l_5ec1;
	case 24262ULL: goto x86_l_5ec6;
	case 24265ULL: goto x86_l_5ec9;
	case 24270ULL: goto x86_l_5ece;
	case 24275ULL: goto x86_l_5ed3;
	case 24278ULL: goto x86_l_5ed6;
	case 24282ULL: goto x86_l_5eda;
	case 24284ULL: goto x86_l_5edc;
	case 24286ULL: goto x86_l_5ede;
	case 24289ULL: goto x86_l_5ee1;
	case 24291ULL: goto x86_l_5ee3;
	case 24298ULL: goto x86_l_5eea;
	case 24304ULL: goto x86_l_5ef0;
	case 24312ULL: goto x86_l_5ef8;
	case 24317ULL: goto x86_l_5efd;
	case 24322ULL: goto x86_l_5f02;
	case 24325ULL: goto x86_l_5f05;
	case 24330ULL: goto x86_l_5f0a;
	case 24336ULL: goto x86_l_5f10;
	case 24341ULL: goto x86_l_5f15;
	case 24346ULL: goto x86_l_5f1a;
	case 24351ULL: goto x86_l_5f1f;
	case 24354ULL: goto x86_l_5f22;
	case 24357ULL: goto x86_l_5f25;
	case 24363ULL: goto x86_l_5f2b;
	case 24366ULL: goto x86_l_5f2e;
	case 24368ULL: goto x86_l_5f30;
	case 24373ULL: goto x86_l_5f35;
	case 24379ULL: goto x86_l_5f3b;
	case 24384ULL: goto x86_l_5f40;
	case 24386ULL: goto x86_l_5f42;
	case 24388ULL: goto x86_l_5f44;
	case 24392ULL: goto x86_l_5f48;
	case 24395ULL: goto x86_l_5f4b;
	case 24401ULL: goto x86_l_5f51;
	case 24408ULL: goto x86_l_5f58;
	case 24411ULL: goto x86_l_5f5b;
	case 24417ULL: goto x86_l_5f61;
	case 24427ULL: goto x86_l_5f6b;
	case 24432ULL: goto x86_l_5f70;
	case 24442ULL: goto x86_l_5f7a;
	case 24447ULL: goto x86_l_5f7f;
	case 24457ULL: goto x86_l_5f89;
	case 24462ULL: goto x86_l_5f8e;
	case 24472ULL: goto x86_l_5f98;
	case 24477ULL: goto x86_l_5f9d;
	case 24487ULL: goto x86_l_5fa7;
	case 24492ULL: goto x86_l_5fac;
	case 24502ULL: goto x86_l_5fb6;
	case 24507ULL: goto x86_l_5fbb;
	case 24512ULL: goto x86_l_5fc0;
	case 24517ULL: goto x86_l_5fc5;
	case 24522ULL: goto x86_l_5fca;
	case 24527ULL: goto x86_l_5fcf;
	case 24529ULL: goto x86_l_5fd1;
	case 24531ULL: goto x86_l_5fd3;
	case 24536ULL: goto x86_l_5fd8;
	case 24543ULL: goto x86_l_5fdf;
	case 24547ULL: goto x86_l_5fe3;
	case 24553ULL: goto x86_l_5fe9;
	case 24558ULL: goto x86_l_5fee;
	case 24561ULL: goto x86_l_5ff1;
	case 24568ULL: goto x86_l_5ff8;
	case 24572ULL: goto x86_l_5ffc;
	case 24579ULL: goto x86_l_6003;
	case 24586ULL: goto x86_l_600a;
	case 24594ULL: goto x86_l_6012;
	case 24602ULL: goto x86_l_601a;
	case 24613ULL: goto x86_l_6025;
	case 24616ULL: goto x86_l_6028;
	case 24624ULL: goto x86_l_6030;
	case 24629ULL: goto x86_l_6035;
	case 24638ULL: goto x86_l_603e;
	case 24645ULL: goto x86_l_6045;
	case 24652ULL: goto x86_l_604c;
	case 24655ULL: goto x86_l_604f;
	case 24660ULL: goto x86_l_6054;
	case 24662ULL: goto x86_l_6056;
	case 24665ULL: goto x86_l_6059;
	case 24667ULL: goto x86_l_605b;
	case 24670ULL: goto x86_l_605e;
	case 24675ULL: goto x86_l_6063;
	case 24682ULL: goto x86_l_606a;
	case 24685ULL: goto x86_l_606d;
	case 24687ULL: goto x86_l_606f;
	case 24697ULL: goto x86_l_6079;
	case 24702ULL: goto x86_l_607e;
	case 24712ULL: goto x86_l_6088;
	case 24717ULL: goto x86_l_608d;
	case 24727ULL: goto x86_l_6097;
	case 24732ULL: goto x86_l_609c;
	case 24742ULL: goto x86_l_60a6;
	case 24747ULL: goto x86_l_60ab;
	case 24757ULL: goto x86_l_60b5;
	case 24762ULL: goto x86_l_60ba;
	case 24772ULL: goto x86_l_60c4;
	case 24777ULL: goto x86_l_60c9;
	case 24782ULL: goto x86_l_60ce;
	case 24787ULL: goto x86_l_60d3;
	case 24792ULL: goto x86_l_60d8;
	case 24795ULL: goto x86_l_60db;
	case 24800ULL: goto x86_l_60e0;
	case 24802ULL: goto x86_l_60e2;
	case 24804ULL: goto x86_l_60e4;
	case 24809ULL: goto x86_l_60e9;
	case 24812ULL: goto x86_l_60ec;
	case 24818ULL: goto x86_l_60f2;
	case 24823ULL: goto x86_l_60f7;
	case 24826ULL: goto x86_l_60fa;
	case 24831ULL: goto x86_l_60ff;
	case 24840ULL: goto x86_l_6108;
	case 24849ULL: goto x86_l_6111;
	case 24854ULL: goto x86_l_6116;
	case 24857ULL: goto x86_l_6119;
	case 24862ULL: goto x86_l_611e;
	case 24867ULL: goto x86_l_6123;
	case 24873ULL: goto x86_l_6129;
	case 24878ULL: goto x86_l_612e;
	case 24883ULL: goto x86_l_6133;
	case 24888ULL: goto x86_l_6138;
	case 24891ULL: goto x86_l_613b;
	case 24896ULL: goto x86_l_6140;
	case 24901ULL: goto x86_l_6145;
	case 24906ULL: goto x86_l_614a;
	case 24911ULL: goto x86_l_614f;
	case 24917ULL: goto x86_l_6155;
	case 24922ULL: goto x86_l_615a;
	case 24927ULL: goto x86_l_615f;
	case 24932ULL: goto x86_l_6164;
	case 24935ULL: goto x86_l_6167;
	case 24941ULL: goto x86_l_616d;
	case 24947ULL: goto x86_l_6173;
	case 24952ULL: goto x86_l_6178;
	case 24955ULL: goto x86_l_617b;
	case 24961ULL: goto x86_l_6181;
	case 24966ULL: goto x86_l_6186;
	case 24969ULL: goto x86_l_6189;
	case 24974ULL: goto x86_l_618e;
	case 24979ULL: goto x86_l_6193;
	case 24985ULL: goto x86_l_6199;
	case 24990ULL: goto x86_l_619e;
	case 24995ULL: goto x86_l_61a3;
	case 25000ULL: goto x86_l_61a8;
	case 25003ULL: goto x86_l_61ab;
	case 25006ULL: goto x86_l_61ae;
	case 25012ULL: goto x86_l_61b4;
	case 25017ULL: goto x86_l_61b9;
	case 25022ULL: goto x86_l_61be;
	case 25027ULL: goto x86_l_61c3;
	case 25032ULL: goto x86_l_61c8;
	case 25038ULL: goto x86_l_61ce;
	case 25043ULL: goto x86_l_61d3;
	case 25048ULL: goto x86_l_61d8;
	case 25053ULL: goto x86_l_61dd;
	case 25056ULL: goto x86_l_61e0;
	case 25059ULL: goto x86_l_61e3;
	case 25065ULL: goto x86_l_61e9;
	case 25070ULL: goto x86_l_61ee;
	case 25075ULL: goto x86_l_61f3;
	case 25080ULL: goto x86_l_61f8;
	case 25085ULL: goto x86_l_61fd;
	case 25091ULL: goto x86_l_6203;
	case 25096ULL: goto x86_l_6208;
	case 25101ULL: goto x86_l_620d;
	case 25106ULL: goto x86_l_6212;
	case 25109ULL: goto x86_l_6215;
	case 25112ULL: goto x86_l_6218;
	case 25118ULL: goto x86_l_621e;
	case 25123ULL: goto x86_l_6223;
	case 25126ULL: goto x86_l_6226;
	case 25131ULL: goto x86_l_622b;
	case 25136ULL: goto x86_l_6230;
	case 25139ULL: goto x86_l_6233;
	case 25143ULL: goto x86_l_6237;
	case 25145ULL: goto x86_l_6239;
	case 25147ULL: goto x86_l_623b;
	case 25150ULL: goto x86_l_623e;
	case 25152ULL: goto x86_l_6240;
	case 25159ULL: goto x86_l_6247;
	case 25165ULL: goto x86_l_624d;
	case 25173ULL: goto x86_l_6255;
	case 25178ULL: goto x86_l_625a;
	case 25183ULL: goto x86_l_625f;
	case 25186ULL: goto x86_l_6262;
	case 25191ULL: goto x86_l_6267;
	case 25197ULL: goto x86_l_626d;
	case 25202ULL: goto x86_l_6272;
	case 25207ULL: goto x86_l_6277;
	case 25212ULL: goto x86_l_627c;
	case 25215ULL: goto x86_l_627f;
	case 25218ULL: goto x86_l_6282;
	case 25224ULL: goto x86_l_6288;
	case 25227ULL: goto x86_l_628b;
	case 25229ULL: goto x86_l_628d;
	case 25234ULL: goto x86_l_6292;
	case 25240ULL: goto x86_l_6298;
	case 25245ULL: goto x86_l_629d;
	case 25247ULL: goto x86_l_629f;
	case 25249ULL: goto x86_l_62a1;
	case 25253ULL: goto x86_l_62a5;
	case 25256ULL: goto x86_l_62a8;
	case 25262ULL: goto x86_l_62ae;
	case 25269ULL: goto x86_l_62b5;
	case 25272ULL: goto x86_l_62b8;
	case 25278ULL: goto x86_l_62be;
	case 25288ULL: goto x86_l_62c8;
	case 25293ULL: goto x86_l_62cd;
	case 25303ULL: goto x86_l_62d7;
	case 25308ULL: goto x86_l_62dc;
	case 25318ULL: goto x86_l_62e6;
	case 25323ULL: goto x86_l_62eb;
	case 25333ULL: goto x86_l_62f5;
	case 25338ULL: goto x86_l_62fa;
	case 25348ULL: goto x86_l_6304;
	case 25353ULL: goto x86_l_6309;
	case 25363ULL: goto x86_l_6313;
	case 25368ULL: goto x86_l_6318;
	case 25373ULL: goto x86_l_631d;
	case 25378ULL: goto x86_l_6322;
	case 25383ULL: goto x86_l_6327;
	case 25388ULL: goto x86_l_632c;
	case 25390ULL: goto x86_l_632e;
	case 25392ULL: goto x86_l_6330;
	case 25397ULL: goto x86_l_6335;
	case 25404ULL: goto x86_l_633c;
	case 25408ULL: goto x86_l_6340;
	case 25414ULL: goto x86_l_6346;
	case 25419ULL: goto x86_l_634b;
	case 25422ULL: goto x86_l_634e;
	case 25429ULL: goto x86_l_6355;
	case 25433ULL: goto x86_l_6359;
	case 25440ULL: goto x86_l_6360;
	case 25447ULL: goto x86_l_6367;
	case 25455ULL: goto x86_l_636f;
	case 25463ULL: goto x86_l_6377;
	case 25474ULL: goto x86_l_6382;
	case 25477ULL: goto x86_l_6385;
	case 25485ULL: goto x86_l_638d;
	case 25490ULL: goto x86_l_6392;
	case 25499ULL: goto x86_l_639b;
	case 25506ULL: goto x86_l_63a2;
	case 25513ULL: goto x86_l_63a9;
	case 25516ULL: goto x86_l_63ac;
	case 25521ULL: goto x86_l_63b1;
	case 25523ULL: goto x86_l_63b3;
	case 25526ULL: goto x86_l_63b6;
	case 25528ULL: goto x86_l_63b8;
	case 25531ULL: goto x86_l_63bb;
	case 25536ULL: goto x86_l_63c0;
	case 25543ULL: goto x86_l_63c7;
	case 25546ULL: goto x86_l_63ca;
	case 25548ULL: goto x86_l_63cc;
	case 25558ULL: goto x86_l_63d6;
	case 25563ULL: goto x86_l_63db;
	case 25573ULL: goto x86_l_63e5;
	case 25578ULL: goto x86_l_63ea;
	case 25588ULL: goto x86_l_63f4;
	case 25593ULL: goto x86_l_63f9;
	case 25603ULL: goto x86_l_6403;
	case 25608ULL: goto x86_l_6408;
	case 25618ULL: goto x86_l_6412;
	case 25623ULL: goto x86_l_6417;
	case 25633ULL: goto x86_l_6421;
	case 25638ULL: goto x86_l_6426;
	case 25643ULL: goto x86_l_642b;
	case 25648ULL: goto x86_l_6430;
	case 25653ULL: goto x86_l_6435;
	case 25656ULL: goto x86_l_6438;
	case 25661ULL: goto x86_l_643d;
	case 25663ULL: goto x86_l_643f;
	case 25665ULL: goto x86_l_6441;
	case 25670ULL: goto x86_l_6446;
	case 25673ULL: goto x86_l_6449;
	case 25679ULL: goto x86_l_644f;
	case 25684ULL: goto x86_l_6454;
	case 25687ULL: goto x86_l_6457;
	case 25692ULL: goto x86_l_645c;
	case 25701ULL: goto x86_l_6465;
	case 25710ULL: goto x86_l_646e;
	case 25715ULL: goto x86_l_6473;
	case 25718ULL: goto x86_l_6476;
	case 25723ULL: goto x86_l_647b;
	case 25728ULL: goto x86_l_6480;
	case 25734ULL: goto x86_l_6486;
	case 25739ULL: goto x86_l_648b;
	case 25744ULL: goto x86_l_6490;
	case 25749ULL: goto x86_l_6495;
	case 25752ULL: goto x86_l_6498;
	case 25757ULL: goto x86_l_649d;
	case 25762ULL: goto x86_l_64a2;
	case 25767ULL: goto x86_l_64a7;
	case 25772ULL: goto x86_l_64ac;
	case 25778ULL: goto x86_l_64b2;
	case 25783ULL: goto x86_l_64b7;
	case 25788ULL: goto x86_l_64bc;
	case 25793ULL: goto x86_l_64c1;
	case 25796ULL: goto x86_l_64c4;
	case 25802ULL: goto x86_l_64ca;
	case 25808ULL: goto x86_l_64d0;
	case 25813ULL: goto x86_l_64d5;
	case 25816ULL: goto x86_l_64d8;
	case 25822ULL: goto x86_l_64de;
	case 25827ULL: goto x86_l_64e3;
	case 25830ULL: goto x86_l_64e6;
	case 25835ULL: goto x86_l_64eb;
	case 25840ULL: goto x86_l_64f0;
	case 25846ULL: goto x86_l_64f6;
	case 25851ULL: goto x86_l_64fb;
	case 25856ULL: goto x86_l_6500;
	case 25861ULL: goto x86_l_6505;
	case 25864ULL: goto x86_l_6508;
	case 25867ULL: goto x86_l_650b;
	case 25873ULL: goto x86_l_6511;
	case 25878ULL: goto x86_l_6516;
	case 25883ULL: goto x86_l_651b;
	case 25888ULL: goto x86_l_6520;
	case 25893ULL: goto x86_l_6525;
	case 25899ULL: goto x86_l_652b;
	case 25904ULL: goto x86_l_6530;
	case 25909ULL: goto x86_l_6535;
	case 25914ULL: goto x86_l_653a;
	case 25917ULL: goto x86_l_653d;
	case 25920ULL: goto x86_l_6540;
	case 25926ULL: goto x86_l_6546;
	case 25931ULL: goto x86_l_654b;
	case 25936ULL: goto x86_l_6550;
	case 25941ULL: goto x86_l_6555;
	case 25946ULL: goto x86_l_655a;
	case 25952ULL: goto x86_l_6560;
	case 25957ULL: goto x86_l_6565;
	case 25962ULL: goto x86_l_656a;
	case 25967ULL: goto x86_l_656f;
	case 25970ULL: goto x86_l_6572;
	case 25973ULL: goto x86_l_6575;
	case 25979ULL: goto x86_l_657b;
	case 25984ULL: goto x86_l_6580;
	case 25987ULL: goto x86_l_6583;
	case 25992ULL: goto x86_l_6588;
	case 25997ULL: goto x86_l_658d;
	case 26000ULL: goto x86_l_6590;
	case 26004ULL: goto x86_l_6594;
	case 26006ULL: goto x86_l_6596;
	case 26008ULL: goto x86_l_6598;
	case 26011ULL: goto x86_l_659b;
	case 26013ULL: goto x86_l_659d;
	case 26020ULL: goto x86_l_65a4;
	case 26026ULL: goto x86_l_65aa;
	case 26034ULL: goto x86_l_65b2;
	case 26039ULL: goto x86_l_65b7;
	case 26044ULL: goto x86_l_65bc;
	case 26047ULL: goto x86_l_65bf;
	case 26052ULL: goto x86_l_65c4;
	case 26058ULL: goto x86_l_65ca;
	case 26063ULL: goto x86_l_65cf;
	case 26068ULL: goto x86_l_65d4;
	case 26073ULL: goto x86_l_65d9;
	case 26076ULL: goto x86_l_65dc;
	case 26079ULL: goto x86_l_65df;
	case 26085ULL: goto x86_l_65e5;
	case 26088ULL: goto x86_l_65e8;
	case 26090ULL: goto x86_l_65ea;
	case 26095ULL: goto x86_l_65ef;
	case 26101ULL: goto x86_l_65f5;
	case 26106ULL: goto x86_l_65fa;
	case 26108ULL: goto x86_l_65fc;
	case 26110ULL: goto x86_l_65fe;
	case 26114ULL: goto x86_l_6602;
	case 26117ULL: goto x86_l_6605;
	case 26123ULL: goto x86_l_660b;
	case 26130ULL: goto x86_l_6612;
	case 26133ULL: goto x86_l_6615;
	case 26139ULL: goto x86_l_661b;
	case 26149ULL: goto x86_l_6625;
	case 26154ULL: goto x86_l_662a;
	case 26164ULL: goto x86_l_6634;
	case 26169ULL: goto x86_l_6639;
	case 26179ULL: goto x86_l_6643;
	case 26184ULL: goto x86_l_6648;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5ea6:
	/* 0x5ea6: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_5eab:
	/* 0x5eab: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5eb0:
	/* 0x5eb0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5eb5:
	/* 0x5eb5: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5eb8:
	/* 0x5eb8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5ebb:
	/* 0x5ebb: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_5ec1:
	/* 0x5ec1: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ec6:
	/* 0x5ec6: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_5ec9:
	/* 0x5ec9: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_5ece:
	/* 0x5ece: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_5ed3:
	/* 0x5ed3: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5ed6:
	/* 0x5ed6: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_5eda:
	/* 0x5eda: je     5f40 <kprobe_unwind_ruby+0x5f40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f40;
	}
x86_l_5edc:
	/* 0x5edc: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ede:
	/* 0x5ede: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_5ee1:
	/* 0x5ee1: jmp    5f44 <kprobe_unwind_ruby+0x5f44> */
	goto x86_l_5f44;
x86_l_5ee3:
	/* 0x5ee3: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_5eea:
	/* 0x5eea: jb     60e4 <kprobe_unwind_ruby+0x60e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_60e4;
	}
x86_l_5ef0:
	/* 0x5ef0: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ef8:
	/* 0x5ef8: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_5efd:
	/* 0x5efd: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5f02:
	/* 0x5f02: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5f05:
	/* 0x5f05: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5f0a:
	/* 0x5f0a: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5f10:
	/* 0x5f10: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_5f15:
	/* 0x5f15: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5f1a:
	/* 0x5f1a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f1f:
	/* 0x5f1f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5f22:
	/* 0x5f22: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5f25:
	/* 0x5f25: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_5f2b:
	/* 0x5f2b: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f2e:
	/* 0x5f2e: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_5f30:
	/* 0x5f30: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_5f35:
	/* 0x5f35: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_5f3b:
	/* 0x5f3b: jmp    60e4 <kprobe_unwind_ruby+0x60e4> */
	goto x86_l_60e4;
x86_l_5f40:
	/* 0x5f40: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f42:
	/* 0x5f42: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_5f44:
	/* 0x5f44: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_5f48:
	/* 0x5f48: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_5f4b:
	/* 0x5f4b: jbe    5fd8 <kprobe_unwind_ruby+0x5fd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_5fd8;
	}
x86_l_5f51:
	/* 0x5f51: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5f58:
	/* 0x5f58: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f5b:
	/* 0x5f5b: je     60e4 <kprobe_unwind_ruby+0x60e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_60e4;
	}
x86_l_5f61:
	/* 0x5f61: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_5f6b:
	/* 0x5f6b: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_5f70:
	/* 0x5f70: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_5f7a:
	/* 0x5f7a: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5f7f:
	/* 0x5f7f: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_5f89:
	/* 0x5f89: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5f8e:
	/* 0x5f8e: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_5f98:
	/* 0x5f98: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5f9d:
	/* 0x5f9d: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_5fa7:
	/* 0x5fa7: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5fac:
	/* 0x5fac: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_5fb6:
	/* 0x5fb6: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5fbb:
	/* 0x5fbb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5fc0:
	/* 0x5fc0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5fc5:
	/* 0x5fc5: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5fca:
	/* 0x5fca: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_5fcf:
	/* 0x5fcf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fd1:
	/* 0x5fd1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5fd3:
	/* 0x5fd3: jmp    60e4 <kprobe_unwind_ruby+0x60e4> */
	goto x86_l_60e4;
x86_l_5fd8:
	/* 0x5fd8: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_5fdf:
	/* 0x5fdf: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_5fe3:
	/* 0x5fe3: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_5fe9:
	/* 0x5fe9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5fee:
	/* 0x5fee: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5ff1:
	/* 0x5ff1: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_5ff8:
	/* 0x5ff8: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_5ffc:
	/* 0x5ffc: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_6003:
	/* 0x6003: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_600a:
	/* 0x600a: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_6012:
	/* 0x6012: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_601a:
	/* 0x601a: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_6025:
	/* 0x6025: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6028:
	/* 0x6028: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_6030:
	/* 0x6030: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_6035:
	/* 0x6035: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_603e:
	/* 0x603e: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_6045:
	/* 0x6045: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_604c:
	/* 0x604c: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_604f:
	/* 0x604f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6054:
	/* 0x6054: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6056:
	/* 0x6056: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6059:
	/* 0x6059: je     6063 <kprobe_unwind_ruby+0x6063> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6063;
	}
x86_l_605b:
	/* 0x605b: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_605e:
	/* 0x605e: jmp    60e4 <kprobe_unwind_ruby+0x60e4> */
	goto x86_l_60e4;
x86_l_6063:
	/* 0x6063: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_606a:
	/* 0x606a: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_606d:
	/* 0x606d: je     60e4 <kprobe_unwind_ruby+0x60e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_60e4;
	}
x86_l_606f:
	/* 0x606f: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_6079:
	/* 0x6079: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_607e:
	/* 0x607e: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_6088:
	/* 0x6088: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_608d:
	/* 0x608d: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_6097:
	/* 0x6097: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_609c:
	/* 0x609c: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_60a6:
	/* 0x60a6: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_60ab:
	/* 0x60ab: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_60b5:
	/* 0x60b5: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_60ba:
	/* 0x60ba: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_60c4:
	/* 0x60c4: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_60c9:
	/* 0x60c9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_60ce:
	/* 0x60ce: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_60d3:
	/* 0x60d3: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_60d8:
	/* 0x60d8: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60db:
	/* 0x60db: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_60e0:
	/* 0x60e0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_60e2:
	/* 0x60e2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_60e4:
	/* 0x60e4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60e9:
	/* 0x60e9: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_60ec:
	/* 0x60ec: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_60f2:
	/* 0x60f2: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_60f7:
	/* 0x60f7: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_60fa:
	/* 0x60fa: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60ff:
	/* 0x60ff: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_6108:
	/* 0x6108: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_6111:
	/* 0x6111: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_6116:
	/* 0x6116: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6119:
	/* 0x6119: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_611e:
	/* 0x611e: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6123:
	/* 0x6123: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6129:
	/* 0x6129: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_612e:
	/* 0x612e: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6133:
	/* 0x6133: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6138:
	/* 0x6138: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_613b:
	/* 0x613b: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_6140:
	/* 0x6140: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6145:
	/* 0x6145: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_614a:
	/* 0x614a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_614f:
	/* 0x614f: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6155:
	/* 0x6155: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_615a:
	/* 0x615a: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_615f:
	/* 0x615f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6164:
	/* 0x6164: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6167:
	/* 0x6167: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_616d:
	/* 0x616d: je     6240 <kprobe_unwind_ruby+0x6240> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6240;
	}
x86_l_6173:
	/* 0x6173: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6178:
	/* 0x6178: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_617b:
	/* 0x617b: je     6240 <kprobe_unwind_ruby+0x6240> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6240;
	}
x86_l_6181:
	/* 0x6181: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_6186:
	/* 0x6186: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6189:
	/* 0x6189: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_618e:
	/* 0x618e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6193:
	/* 0x6193: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6199:
	/* 0x6199: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_619e:
	/* 0x619e: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_61a3:
	/* 0x61a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_61a8:
	/* 0x61a8: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_61ab:
	/* 0x61ab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_61ae:
	/* 0x61ae: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_61b4:
	/* 0x61b4: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_61b9:
	/* 0x61b9: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_61be:
	/* 0x61be: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_61c3:
	/* 0x61c3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_61c8:
	/* 0x61c8: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_61ce:
	/* 0x61ce: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_61d3:
	/* 0x61d3: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_61d8:
	/* 0x61d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_61dd:
	/* 0x61dd: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_61e0:
	/* 0x61e0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_61e3:
	/* 0x61e3: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_61e9:
	/* 0x61e9: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_61ee:
	/* 0x61ee: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_61f3:
	/* 0x61f3: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_61f8:
	/* 0x61f8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_61fd:
	/* 0x61fd: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6203:
	/* 0x6203: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_6208:
	/* 0x6208: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_620d:
	/* 0x620d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6212:
	/* 0x6212: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6215:
	/* 0x6215: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6218:
	/* 0x6218: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_621e:
	/* 0x621e: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6223:
	/* 0x6223: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_6226:
	/* 0x6226: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_622b:
	/* 0x622b: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_6230:
	/* 0x6230: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6233:
	/* 0x6233: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_6237:
	/* 0x6237: je     629d <kprobe_unwind_ruby+0x629d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_629d;
	}
x86_l_6239:
	/* 0x6239: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_623b:
	/* 0x623b: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_623e:
	/* 0x623e: jmp    62a1 <kprobe_unwind_ruby+0x62a1> */
	goto x86_l_62a1;
x86_l_6240:
	/* 0x6240: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_6247:
	/* 0x6247: jb     6441 <kprobe_unwind_ruby+0x6441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_6441;
	}
x86_l_624d:
	/* 0x624d: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6255:
	/* 0x6255: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_625a:
	/* 0x625a: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_625f:
	/* 0x625f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6262:
	/* 0x6262: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6267:
	/* 0x6267: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_626d:
	/* 0x626d: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_6272:
	/* 0x6272: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6277:
	/* 0x6277: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_627c:
	/* 0x627c: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_627f:
	/* 0x627f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6282:
	/* 0x6282: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_6288:
	/* 0x6288: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_628b:
	/* 0x628b: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_628d:
	/* 0x628d: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_6292:
	/* 0x6292: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_6298:
	/* 0x6298: jmp    6441 <kprobe_unwind_ruby+0x6441> */
	goto x86_l_6441;
x86_l_629d:
	/* 0x629d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_629f:
	/* 0x629f: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_62a1:
	/* 0x62a1: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_62a5:
	/* 0x62a5: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_62a8:
	/* 0x62a8: jbe    6335 <kprobe_unwind_ruby+0x6335> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_6335;
	}
x86_l_62ae:
	/* 0x62ae: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_62b5:
	/* 0x62b5: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62b8:
	/* 0x62b8: je     6441 <kprobe_unwind_ruby+0x6441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6441;
	}
x86_l_62be:
	/* 0x62be: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_62c8:
	/* 0x62c8: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_62cd:
	/* 0x62cd: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_62d7:
	/* 0x62d7: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_62dc:
	/* 0x62dc: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_62e6:
	/* 0x62e6: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_62eb:
	/* 0x62eb: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_62f5:
	/* 0x62f5: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_62fa:
	/* 0x62fa: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_6304:
	/* 0x6304: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6309:
	/* 0x6309: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_6313:
	/* 0x6313: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6318:
	/* 0x6318: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_631d:
	/* 0x631d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_6322:
	/* 0x6322: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6327:
	/* 0x6327: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_632c:
	/* 0x632c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_632e:
	/* 0x632e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6330:
	/* 0x6330: jmp    6441 <kprobe_unwind_ruby+0x6441> */
	goto x86_l_6441;
x86_l_6335:
	/* 0x6335: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_633c:
	/* 0x633c: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_6340:
	/* 0x6340: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_6346:
	/* 0x6346: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_634b:
	/* 0x634b: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_634e:
	/* 0x634e: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_6355:
	/* 0x6355: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_6359:
	/* 0x6359: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_6360:
	/* 0x6360: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6367:
	/* 0x6367: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_636f:
	/* 0x636f: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_6377:
	/* 0x6377: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_6382:
	/* 0x6382: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6385:
	/* 0x6385: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_638d:
	/* 0x638d: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_6392:
	/* 0x6392: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_639b:
	/* 0x639b: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_63a2:
	/* 0x63a2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_63a9:
	/* 0x63a9: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_63ac:
	/* 0x63ac: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_63b1:
	/* 0x63b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63b3:
	/* 0x63b3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_63b6:
	/* 0x63b6: je     63c0 <kprobe_unwind_ruby+0x63c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_63c0;
	}
x86_l_63b8:
	/* 0x63b8: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_63bb:
	/* 0x63bb: jmp    6441 <kprobe_unwind_ruby+0x6441> */
	goto x86_l_6441;
x86_l_63c0:
	/* 0x63c0: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_63c7:
	/* 0x63c7: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_63ca:
	/* 0x63ca: je     6441 <kprobe_unwind_ruby+0x6441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6441;
	}
x86_l_63cc:
	/* 0x63cc: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_63d6:
	/* 0x63d6: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_63db:
	/* 0x63db: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_63e5:
	/* 0x63e5: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_63ea:
	/* 0x63ea: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_63f4:
	/* 0x63f4: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_63f9:
	/* 0x63f9: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_6403:
	/* 0x6403: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6408:
	/* 0x6408: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_6412:
	/* 0x6412: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6417:
	/* 0x6417: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_6421:
	/* 0x6421: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6426:
	/* 0x6426: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_642b:
	/* 0x642b: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_6430:
	/* 0x6430: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6435:
	/* 0x6435: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6438:
	/* 0x6438: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_643d:
	/* 0x643d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_643f:
	/* 0x643f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6441:
	/* 0x6441: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6446:
	/* 0x6446: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_6449:
	/* 0x6449: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_644f:
	/* 0x644f: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_6454:
	/* 0x6454: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6457:
	/* 0x6457: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_645c:
	/* 0x645c: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_6465:
	/* 0x6465: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_646e:
	/* 0x646e: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_6473:
	/* 0x6473: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6476:
	/* 0x6476: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_647b:
	/* 0x647b: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6480:
	/* 0x6480: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6486:
	/* 0x6486: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_648b:
	/* 0x648b: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6490:
	/* 0x6490: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6495:
	/* 0x6495: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6498:
	/* 0x6498: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_649d:
	/* 0x649d: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_64a2:
	/* 0x64a2: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_64a7:
	/* 0x64a7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_64ac:
	/* 0x64ac: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_64b2:
	/* 0x64b2: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_64b7:
	/* 0x64b7: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_64bc:
	/* 0x64bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64c1:
	/* 0x64c1: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_64c4:
	/* 0x64c4: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_64ca:
	/* 0x64ca: je     659d <kprobe_unwind_ruby+0x659d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_659d;
	}
x86_l_64d0:
	/* 0x64d0: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_64d5:
	/* 0x64d5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_64d8:
	/* 0x64d8: je     659d <kprobe_unwind_ruby+0x659d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_659d;
	}
x86_l_64de:
	/* 0x64de: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_64e3:
	/* 0x64e3: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_64e6:
	/* 0x64e6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64eb:
	/* 0x64eb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_64f0:
	/* 0x64f0: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_64f6:
	/* 0x64f6: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_64fb:
	/* 0x64fb: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_6500:
	/* 0x6500: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6505:
	/* 0x6505: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6508:
	/* 0x6508: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_650b:
	/* 0x650b: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_6511:
	/* 0x6511: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_6516:
	/* 0x6516: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_651b:
	/* 0x651b: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6520:
	/* 0x6520: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6525:
	/* 0x6525: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_652b:
	/* 0x652b: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_6530:
	/* 0x6530: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_6535:
	/* 0x6535: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_653a:
	/* 0x653a: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_653d:
	/* 0x653d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6540:
	/* 0x6540: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_6546:
	/* 0x6546: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_654b:
	/* 0x654b: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_6550:
	/* 0x6550: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6555:
	/* 0x6555: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_655a:
	/* 0x655a: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6560:
	/* 0x6560: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_6565:
	/* 0x6565: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_656a:
	/* 0x656a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_656f:
	/* 0x656f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6572:
	/* 0x6572: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6575:
	/* 0x6575: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_657b:
	/* 0x657b: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6580:
	/* 0x6580: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_6583:
	/* 0x6583: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_6588:
	/* 0x6588: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_658d:
	/* 0x658d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6590:
	/* 0x6590: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_6594:
	/* 0x6594: je     65fa <kprobe_unwind_ruby+0x65fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_65fa;
	}
x86_l_6596:
	/* 0x6596: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6598:
	/* 0x6598: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_659b:
	/* 0x659b: jmp    65fe <kprobe_unwind_ruby+0x65fe> */
	goto x86_l_65fe;
x86_l_659d:
	/* 0x659d: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_65a4:
	/* 0x65a4: jb     679e <kprobe_unwind_ruby+0x679e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 26526ULL;
	}
x86_l_65aa:
	/* 0x65aa: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_65b2:
	/* 0x65b2: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_65b7:
	/* 0x65b7: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_65bc:
	/* 0x65bc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_65bf:
	/* 0x65bf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_65c4:
	/* 0x65c4: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_65ca:
	/* 0x65ca: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_65cf:
	/* 0x65cf: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_65d4:
	/* 0x65d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_65d9:
	/* 0x65d9: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_65dc:
	/* 0x65dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_65df:
	/* 0x65df: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_65e5:
	/* 0x65e5: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_65e8:
	/* 0x65e8: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_65ea:
	/* 0x65ea: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_65ef:
	/* 0x65ef: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_65f5:
	/* 0x65f5: jmp    679e <kprobe_unwind_ruby+0x679e> */
	return 26526ULL;
x86_l_65fa:
	/* 0x65fa: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_65fc:
	/* 0x65fc: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_65fe:
	/* 0x65fe: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6602:
	/* 0x6602: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_6605:
	/* 0x6605: jbe    6692 <kprobe_unwind_ruby+0x6692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 26258ULL;
	}
x86_l_660b:
	/* 0x660b: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6612:
	/* 0x6612: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6615:
	/* 0x6615: je     679e <kprobe_unwind_ruby+0x679e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26526ULL;
	}
x86_l_661b:
	/* 0x661b: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_6625:
	/* 0x6625: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_662a:
	/* 0x662a: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_6634:
	/* 0x6634: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6639:
	/* 0x6639: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_6643:
	/* 0x6643: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6648:
	/* 0x6648: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
	return 26194ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 26194ULL: goto x86_l_6652;
	case 26199ULL: goto x86_l_6657;
	case 26209ULL: goto x86_l_6661;
	case 26214ULL: goto x86_l_6666;
	case 26224ULL: goto x86_l_6670;
	case 26229ULL: goto x86_l_6675;
	case 26234ULL: goto x86_l_667a;
	case 26239ULL: goto x86_l_667f;
	case 26244ULL: goto x86_l_6684;
	case 26249ULL: goto x86_l_6689;
	case 26251ULL: goto x86_l_668b;
	case 26253ULL: goto x86_l_668d;
	case 26258ULL: goto x86_l_6692;
	case 26265ULL: goto x86_l_6699;
	case 26269ULL: goto x86_l_669d;
	case 26275ULL: goto x86_l_66a3;
	case 26280ULL: goto x86_l_66a8;
	case 26283ULL: goto x86_l_66ab;
	case 26290ULL: goto x86_l_66b2;
	case 26294ULL: goto x86_l_66b6;
	case 26301ULL: goto x86_l_66bd;
	case 26308ULL: goto x86_l_66c4;
	case 26316ULL: goto x86_l_66cc;
	case 26324ULL: goto x86_l_66d4;
	case 26335ULL: goto x86_l_66df;
	case 26338ULL: goto x86_l_66e2;
	case 26346ULL: goto x86_l_66ea;
	case 26351ULL: goto x86_l_66ef;
	case 26360ULL: goto x86_l_66f8;
	case 26367ULL: goto x86_l_66ff;
	case 26374ULL: goto x86_l_6706;
	case 26377ULL: goto x86_l_6709;
	case 26382ULL: goto x86_l_670e;
	case 26384ULL: goto x86_l_6710;
	case 26387ULL: goto x86_l_6713;
	case 26389ULL: goto x86_l_6715;
	case 26392ULL: goto x86_l_6718;
	case 26397ULL: goto x86_l_671d;
	case 26404ULL: goto x86_l_6724;
	case 26407ULL: goto x86_l_6727;
	case 26409ULL: goto x86_l_6729;
	case 26419ULL: goto x86_l_6733;
	case 26424ULL: goto x86_l_6738;
	case 26434ULL: goto x86_l_6742;
	case 26439ULL: goto x86_l_6747;
	case 26449ULL: goto x86_l_6751;
	case 26454ULL: goto x86_l_6756;
	case 26464ULL: goto x86_l_6760;
	case 26469ULL: goto x86_l_6765;
	case 26479ULL: goto x86_l_676f;
	case 26484ULL: goto x86_l_6774;
	case 26494ULL: goto x86_l_677e;
	case 26499ULL: goto x86_l_6783;
	case 26504ULL: goto x86_l_6788;
	case 26509ULL: goto x86_l_678d;
	case 26514ULL: goto x86_l_6792;
	case 26517ULL: goto x86_l_6795;
	case 26522ULL: goto x86_l_679a;
	case 26524ULL: goto x86_l_679c;
	case 26526ULL: goto x86_l_679e;
	case 26531ULL: goto x86_l_67a3;
	case 26534ULL: goto x86_l_67a6;
	case 26540ULL: goto x86_l_67ac;
	case 26545ULL: goto x86_l_67b1;
	case 26548ULL: goto x86_l_67b4;
	case 26553ULL: goto x86_l_67b9;
	case 26562ULL: goto x86_l_67c2;
	case 26571ULL: goto x86_l_67cb;
	case 26576ULL: goto x86_l_67d0;
	case 26579ULL: goto x86_l_67d3;
	case 26584ULL: goto x86_l_67d8;
	case 26589ULL: goto x86_l_67dd;
	case 26595ULL: goto x86_l_67e3;
	case 26600ULL: goto x86_l_67e8;
	case 26605ULL: goto x86_l_67ed;
	case 26610ULL: goto x86_l_67f2;
	case 26613ULL: goto x86_l_67f5;
	case 26618ULL: goto x86_l_67fa;
	case 26623ULL: goto x86_l_67ff;
	case 26628ULL: goto x86_l_6804;
	case 26633ULL: goto x86_l_6809;
	case 26639ULL: goto x86_l_680f;
	case 26644ULL: goto x86_l_6814;
	case 26649ULL: goto x86_l_6819;
	case 26654ULL: goto x86_l_681e;
	case 26657ULL: goto x86_l_6821;
	case 26663ULL: goto x86_l_6827;
	case 26669ULL: goto x86_l_682d;
	case 26674ULL: goto x86_l_6832;
	case 26677ULL: goto x86_l_6835;
	case 26683ULL: goto x86_l_683b;
	case 26688ULL: goto x86_l_6840;
	case 26691ULL: goto x86_l_6843;
	case 26696ULL: goto x86_l_6848;
	case 26701ULL: goto x86_l_684d;
	case 26707ULL: goto x86_l_6853;
	case 26712ULL: goto x86_l_6858;
	case 26717ULL: goto x86_l_685d;
	case 26722ULL: goto x86_l_6862;
	case 26725ULL: goto x86_l_6865;
	case 26728ULL: goto x86_l_6868;
	case 26734ULL: goto x86_l_686e;
	case 26739ULL: goto x86_l_6873;
	case 26744ULL: goto x86_l_6878;
	case 26749ULL: goto x86_l_687d;
	case 26754ULL: goto x86_l_6882;
	case 26760ULL: goto x86_l_6888;
	case 26765ULL: goto x86_l_688d;
	case 26770ULL: goto x86_l_6892;
	case 26775ULL: goto x86_l_6897;
	case 26778ULL: goto x86_l_689a;
	case 26781ULL: goto x86_l_689d;
	case 26787ULL: goto x86_l_68a3;
	case 26792ULL: goto x86_l_68a8;
	case 26797ULL: goto x86_l_68ad;
	case 26802ULL: goto x86_l_68b2;
	case 26807ULL: goto x86_l_68b7;
	case 26813ULL: goto x86_l_68bd;
	case 26818ULL: goto x86_l_68c2;
	case 26823ULL: goto x86_l_68c7;
	case 26828ULL: goto x86_l_68cc;
	case 26831ULL: goto x86_l_68cf;
	case 26834ULL: goto x86_l_68d2;
	case 26840ULL: goto x86_l_68d8;
	case 26845ULL: goto x86_l_68dd;
	case 26848ULL: goto x86_l_68e0;
	case 26853ULL: goto x86_l_68e5;
	case 26858ULL: goto x86_l_68ea;
	case 26861ULL: goto x86_l_68ed;
	case 26865ULL: goto x86_l_68f1;
	case 26867ULL: goto x86_l_68f3;
	case 26869ULL: goto x86_l_68f5;
	case 26872ULL: goto x86_l_68f8;
	case 26874ULL: goto x86_l_68fa;
	case 26881ULL: goto x86_l_6901;
	case 26887ULL: goto x86_l_6907;
	case 26895ULL: goto x86_l_690f;
	case 26900ULL: goto x86_l_6914;
	case 26905ULL: goto x86_l_6919;
	case 26908ULL: goto x86_l_691c;
	case 26913ULL: goto x86_l_6921;
	case 26919ULL: goto x86_l_6927;
	case 26924ULL: goto x86_l_692c;
	case 26929ULL: goto x86_l_6931;
	case 26934ULL: goto x86_l_6936;
	case 26937ULL: goto x86_l_6939;
	case 26940ULL: goto x86_l_693c;
	case 26946ULL: goto x86_l_6942;
	case 26949ULL: goto x86_l_6945;
	case 26951ULL: goto x86_l_6947;
	case 26956ULL: goto x86_l_694c;
	case 26962ULL: goto x86_l_6952;
	case 26967ULL: goto x86_l_6957;
	case 26969ULL: goto x86_l_6959;
	case 26971ULL: goto x86_l_695b;
	case 26975ULL: goto x86_l_695f;
	case 26978ULL: goto x86_l_6962;
	case 26984ULL: goto x86_l_6968;
	case 26991ULL: goto x86_l_696f;
	case 26994ULL: goto x86_l_6972;
	case 27000ULL: goto x86_l_6978;
	case 27010ULL: goto x86_l_6982;
	case 27015ULL: goto x86_l_6987;
	case 27025ULL: goto x86_l_6991;
	case 27030ULL: goto x86_l_6996;
	case 27040ULL: goto x86_l_69a0;
	case 27045ULL: goto x86_l_69a5;
	case 27055ULL: goto x86_l_69af;
	case 27060ULL: goto x86_l_69b4;
	case 27070ULL: goto x86_l_69be;
	case 27075ULL: goto x86_l_69c3;
	case 27085ULL: goto x86_l_69cd;
	case 27090ULL: goto x86_l_69d2;
	case 27095ULL: goto x86_l_69d7;
	case 27100ULL: goto x86_l_69dc;
	case 27105ULL: goto x86_l_69e1;
	case 27110ULL: goto x86_l_69e6;
	case 27112ULL: goto x86_l_69e8;
	case 27114ULL: goto x86_l_69ea;
	case 27119ULL: goto x86_l_69ef;
	case 27126ULL: goto x86_l_69f6;
	case 27130ULL: goto x86_l_69fa;
	case 27136ULL: goto x86_l_6a00;
	case 27141ULL: goto x86_l_6a05;
	case 27144ULL: goto x86_l_6a08;
	case 27151ULL: goto x86_l_6a0f;
	case 27155ULL: goto x86_l_6a13;
	case 27162ULL: goto x86_l_6a1a;
	case 27169ULL: goto x86_l_6a21;
	case 27177ULL: goto x86_l_6a29;
	case 27185ULL: goto x86_l_6a31;
	case 27196ULL: goto x86_l_6a3c;
	case 27199ULL: goto x86_l_6a3f;
	case 27207ULL: goto x86_l_6a47;
	case 27212ULL: goto x86_l_6a4c;
	case 27221ULL: goto x86_l_6a55;
	case 27228ULL: goto x86_l_6a5c;
	case 27235ULL: goto x86_l_6a63;
	case 27238ULL: goto x86_l_6a66;
	case 27243ULL: goto x86_l_6a6b;
	case 27245ULL: goto x86_l_6a6d;
	case 27248ULL: goto x86_l_6a70;
	case 27250ULL: goto x86_l_6a72;
	case 27253ULL: goto x86_l_6a75;
	case 27258ULL: goto x86_l_6a7a;
	case 27265ULL: goto x86_l_6a81;
	case 27268ULL: goto x86_l_6a84;
	case 27270ULL: goto x86_l_6a86;
	case 27280ULL: goto x86_l_6a90;
	case 27285ULL: goto x86_l_6a95;
	case 27295ULL: goto x86_l_6a9f;
	case 27300ULL: goto x86_l_6aa4;
	case 27310ULL: goto x86_l_6aae;
	case 27315ULL: goto x86_l_6ab3;
	case 27325ULL: goto x86_l_6abd;
	case 27330ULL: goto x86_l_6ac2;
	case 27340ULL: goto x86_l_6acc;
	case 27345ULL: goto x86_l_6ad1;
	case 27355ULL: goto x86_l_6adb;
	case 27360ULL: goto x86_l_6ae0;
	case 27365ULL: goto x86_l_6ae5;
	case 27370ULL: goto x86_l_6aea;
	case 27375ULL: goto x86_l_6aef;
	case 27378ULL: goto x86_l_6af2;
	case 27383ULL: goto x86_l_6af7;
	case 27385ULL: goto x86_l_6af9;
	case 27387ULL: goto x86_l_6afb;
	case 27392ULL: goto x86_l_6b00;
	case 27395ULL: goto x86_l_6b03;
	case 27401ULL: goto x86_l_6b09;
	case 27406ULL: goto x86_l_6b0e;
	case 27409ULL: goto x86_l_6b11;
	case 27414ULL: goto x86_l_6b16;
	case 27423ULL: goto x86_l_6b1f;
	case 27432ULL: goto x86_l_6b28;
	case 27437ULL: goto x86_l_6b2d;
	case 27440ULL: goto x86_l_6b30;
	case 27445ULL: goto x86_l_6b35;
	case 27450ULL: goto x86_l_6b3a;
	case 27456ULL: goto x86_l_6b40;
	case 27461ULL: goto x86_l_6b45;
	case 27466ULL: goto x86_l_6b4a;
	case 27471ULL: goto x86_l_6b4f;
	case 27474ULL: goto x86_l_6b52;
	case 27479ULL: goto x86_l_6b57;
	case 27484ULL: goto x86_l_6b5c;
	case 27489ULL: goto x86_l_6b61;
	case 27494ULL: goto x86_l_6b66;
	case 27500ULL: goto x86_l_6b6c;
	case 27505ULL: goto x86_l_6b71;
	case 27510ULL: goto x86_l_6b76;
	case 27515ULL: goto x86_l_6b7b;
	case 27518ULL: goto x86_l_6b7e;
	case 27524ULL: goto x86_l_6b84;
	case 27530ULL: goto x86_l_6b8a;
	case 27535ULL: goto x86_l_6b8f;
	case 27538ULL: goto x86_l_6b92;
	case 27544ULL: goto x86_l_6b98;
	case 27549ULL: goto x86_l_6b9d;
	case 27552ULL: goto x86_l_6ba0;
	case 27557ULL: goto x86_l_6ba5;
	case 27562ULL: goto x86_l_6baa;
	case 27568ULL: goto x86_l_6bb0;
	case 27573ULL: goto x86_l_6bb5;
	case 27578ULL: goto x86_l_6bba;
	case 27583ULL: goto x86_l_6bbf;
	case 27586ULL: goto x86_l_6bc2;
	case 27589ULL: goto x86_l_6bc5;
	case 27595ULL: goto x86_l_6bcb;
	case 27600ULL: goto x86_l_6bd0;
	case 27605ULL: goto x86_l_6bd5;
	case 27610ULL: goto x86_l_6bda;
	case 27615ULL: goto x86_l_6bdf;
	case 27621ULL: goto x86_l_6be5;
	case 27626ULL: goto x86_l_6bea;
	case 27631ULL: goto x86_l_6bef;
	case 27636ULL: goto x86_l_6bf4;
	case 27639ULL: goto x86_l_6bf7;
	case 27642ULL: goto x86_l_6bfa;
	case 27648ULL: goto x86_l_6c00;
	case 27653ULL: goto x86_l_6c05;
	case 27658ULL: goto x86_l_6c0a;
	case 27663ULL: goto x86_l_6c0f;
	case 27668ULL: goto x86_l_6c14;
	case 27674ULL: goto x86_l_6c1a;
	case 27679ULL: goto x86_l_6c1f;
	case 27684ULL: goto x86_l_6c24;
	case 27689ULL: goto x86_l_6c29;
	case 27692ULL: goto x86_l_6c2c;
	case 27695ULL: goto x86_l_6c2f;
	case 27701ULL: goto x86_l_6c35;
	case 27706ULL: goto x86_l_6c3a;
	case 27709ULL: goto x86_l_6c3d;
	case 27714ULL: goto x86_l_6c42;
	case 27719ULL: goto x86_l_6c47;
	case 27722ULL: goto x86_l_6c4a;
	case 27726ULL: goto x86_l_6c4e;
	case 27728ULL: goto x86_l_6c50;
	case 27730ULL: goto x86_l_6c52;
	case 27733ULL: goto x86_l_6c55;
	case 27735ULL: goto x86_l_6c57;
	case 27742ULL: goto x86_l_6c5e;
	case 27748ULL: goto x86_l_6c64;
	case 27756ULL: goto x86_l_6c6c;
	case 27761ULL: goto x86_l_6c71;
	case 27766ULL: goto x86_l_6c76;
	case 27769ULL: goto x86_l_6c79;
	case 27774ULL: goto x86_l_6c7e;
	case 27780ULL: goto x86_l_6c84;
	case 27785ULL: goto x86_l_6c89;
	case 27790ULL: goto x86_l_6c8e;
	case 27795ULL: goto x86_l_6c93;
	case 27798ULL: goto x86_l_6c96;
	case 27801ULL: goto x86_l_6c99;
	case 27807ULL: goto x86_l_6c9f;
	case 27810ULL: goto x86_l_6ca2;
	case 27812ULL: goto x86_l_6ca4;
	case 27817ULL: goto x86_l_6ca9;
	case 27823ULL: goto x86_l_6caf;
	case 27828ULL: goto x86_l_6cb4;
	case 27830ULL: goto x86_l_6cb6;
	case 27832ULL: goto x86_l_6cb8;
	case 27836ULL: goto x86_l_6cbc;
	case 27839ULL: goto x86_l_6cbf;
	case 27845ULL: goto x86_l_6cc5;
	case 27852ULL: goto x86_l_6ccc;
	case 27855ULL: goto x86_l_6ccf;
	case 27861ULL: goto x86_l_6cd5;
	case 27871ULL: goto x86_l_6cdf;
	case 27876ULL: goto x86_l_6ce4;
	case 27886ULL: goto x86_l_6cee;
	case 27891ULL: goto x86_l_6cf3;
	case 27901ULL: goto x86_l_6cfd;
	case 27906ULL: goto x86_l_6d02;
	case 27916ULL: goto x86_l_6d0c;
	case 27921ULL: goto x86_l_6d11;
	case 27931ULL: goto x86_l_6d1b;
	case 27936ULL: goto x86_l_6d20;
	case 27946ULL: goto x86_l_6d2a;
	case 27951ULL: goto x86_l_6d2f;
	case 27956ULL: goto x86_l_6d34;
	case 27961ULL: goto x86_l_6d39;
	case 27966ULL: goto x86_l_6d3e;
	case 27971ULL: goto x86_l_6d43;
	case 27973ULL: goto x86_l_6d45;
	case 27975ULL: goto x86_l_6d47;
	case 27980ULL: goto x86_l_6d4c;
	case 27987ULL: goto x86_l_6d53;
	case 27991ULL: goto x86_l_6d57;
	case 27997ULL: goto x86_l_6d5d;
	case 28002ULL: goto x86_l_6d62;
	case 28005ULL: goto x86_l_6d65;
	case 28012ULL: goto x86_l_6d6c;
	case 28016ULL: goto x86_l_6d70;
	case 28023ULL: goto x86_l_6d77;
	case 28030ULL: goto x86_l_6d7e;
	case 28038ULL: goto x86_l_6d86;
	case 28046ULL: goto x86_l_6d8e;
	case 28057ULL: goto x86_l_6d99;
	case 28060ULL: goto x86_l_6d9c;
	case 28068ULL: goto x86_l_6da4;
	case 28073ULL: goto x86_l_6da9;
	case 28082ULL: goto x86_l_6db2;
	case 28089ULL: goto x86_l_6db9;
	case 28096ULL: goto x86_l_6dc0;
	case 28099ULL: goto x86_l_6dc3;
	case 28104ULL: goto x86_l_6dc8;
	case 28106ULL: goto x86_l_6dca;
	case 28109ULL: goto x86_l_6dcd;
	case 28111ULL: goto x86_l_6dcf;
	case 28114ULL: goto x86_l_6dd2;
	case 28119ULL: goto x86_l_6dd7;
	case 28126ULL: goto x86_l_6dde;
	case 28129ULL: goto x86_l_6de1;
	case 28131ULL: goto x86_l_6de3;
	case 28141ULL: goto x86_l_6ded;
	case 28146ULL: goto x86_l_6df2;
	case 28156ULL: goto x86_l_6dfc;
	case 28161ULL: goto x86_l_6e01;
	case 28171ULL: goto x86_l_6e0b;
	case 28176ULL: goto x86_l_6e10;
	case 28186ULL: goto x86_l_6e1a;
	case 28191ULL: goto x86_l_6e1f;
	case 28201ULL: goto x86_l_6e29;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6652:
	/* 0x6652: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6657:
	/* 0x6657: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_6661:
	/* 0x6661: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6666:
	/* 0x6666: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_6670:
	/* 0x6670: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6675:
	/* 0x6675: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_667a:
	/* 0x667a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_667f:
	/* 0x667f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6684:
	/* 0x6684: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_6689:
	/* 0x6689: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_668b:
	/* 0x668b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_668d:
	/* 0x668d: jmp    679e <kprobe_unwind_ruby+0x679e> */
	goto x86_l_679e;
x86_l_6692:
	/* 0x6692: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_6699:
	/* 0x6699: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_669d:
	/* 0x669d: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_66a3:
	/* 0x66a3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_66a8:
	/* 0x66a8: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_66ab:
	/* 0x66ab: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_66b2:
	/* 0x66b2: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_66b6:
	/* 0x66b6: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_66bd:
	/* 0x66bd: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66c4:
	/* 0x66c4: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_66cc:
	/* 0x66cc: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_66d4:
	/* 0x66d4: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_66df:
	/* 0x66df: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66e2:
	/* 0x66e2: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_66ea:
	/* 0x66ea: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_66ef:
	/* 0x66ef: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_66f8:
	/* 0x66f8: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_66ff:
	/* 0x66ff: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_6706:
	/* 0x6706: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_6709:
	/* 0x6709: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_670e:
	/* 0x670e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6710:
	/* 0x6710: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6713:
	/* 0x6713: je     671d <kprobe_unwind_ruby+0x671d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_671d;
	}
x86_l_6715:
	/* 0x6715: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6718:
	/* 0x6718: jmp    679e <kprobe_unwind_ruby+0x679e> */
	goto x86_l_679e;
x86_l_671d:
	/* 0x671d: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6724:
	/* 0x6724: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6727:
	/* 0x6727: je     679e <kprobe_unwind_ruby+0x679e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_679e;
	}
x86_l_6729:
	/* 0x6729: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_6733:
	/* 0x6733: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_6738:
	/* 0x6738: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_6742:
	/* 0x6742: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6747:
	/* 0x6747: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_6751:
	/* 0x6751: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6756:
	/* 0x6756: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_6760:
	/* 0x6760: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6765:
	/* 0x6765: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_676f:
	/* 0x676f: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6774:
	/* 0x6774: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_677e:
	/* 0x677e: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6783:
	/* 0x6783: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6788:
	/* 0x6788: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_678d:
	/* 0x678d: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6792:
	/* 0x6792: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6795:
	/* 0x6795: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_679a:
	/* 0x679a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_679c:
	/* 0x679c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_679e:
	/* 0x679e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_67a3:
	/* 0x67a3: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_67a6:
	/* 0x67a6: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_67ac:
	/* 0x67ac: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_67b1:
	/* 0x67b1: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_67b4:
	/* 0x67b4: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_67b9:
	/* 0x67b9: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_67c2:
	/* 0x67c2: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_67cb:
	/* 0x67cb: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_67d0:
	/* 0x67d0: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_67d3:
	/* 0x67d3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_67d8:
	/* 0x67d8: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_67dd:
	/* 0x67dd: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_67e3:
	/* 0x67e3: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_67e8:
	/* 0x67e8: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_67ed:
	/* 0x67ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_67f2:
	/* 0x67f2: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_67f5:
	/* 0x67f5: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_67fa:
	/* 0x67fa: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_67ff:
	/* 0x67ff: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6804:
	/* 0x6804: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6809:
	/* 0x6809: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_680f:
	/* 0x680f: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_6814:
	/* 0x6814: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6819:
	/* 0x6819: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_681e:
	/* 0x681e: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6821:
	/* 0x6821: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_6827:
	/* 0x6827: je     68fa <kprobe_unwind_ruby+0x68fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_68fa;
	}
x86_l_682d:
	/* 0x682d: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6832:
	/* 0x6832: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6835:
	/* 0x6835: je     68fa <kprobe_unwind_ruby+0x68fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_68fa;
	}
x86_l_683b:
	/* 0x683b: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_6840:
	/* 0x6840: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6843:
	/* 0x6843: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6848:
	/* 0x6848: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_684d:
	/* 0x684d: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6853:
	/* 0x6853: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_6858:
	/* 0x6858: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_685d:
	/* 0x685d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6862:
	/* 0x6862: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6865:
	/* 0x6865: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6868:
	/* 0x6868: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_686e:
	/* 0x686e: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_6873:
	/* 0x6873: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_6878:
	/* 0x6878: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_687d:
	/* 0x687d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6882:
	/* 0x6882: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6888:
	/* 0x6888: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_688d:
	/* 0x688d: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_6892:
	/* 0x6892: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6897:
	/* 0x6897: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_689a:
	/* 0x689a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_689d:
	/* 0x689d: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_68a3:
	/* 0x68a3: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_68a8:
	/* 0x68a8: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_68ad:
	/* 0x68ad: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_68b2:
	/* 0x68b2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_68b7:
	/* 0x68b7: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_68bd:
	/* 0x68bd: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_68c2:
	/* 0x68c2: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_68c7:
	/* 0x68c7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_68cc:
	/* 0x68cc: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_68cf:
	/* 0x68cf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_68d2:
	/* 0x68d2: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_68d8:
	/* 0x68d8: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_68dd:
	/* 0x68dd: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_68e0:
	/* 0x68e0: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_68e5:
	/* 0x68e5: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_68ea:
	/* 0x68ea: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_68ed:
	/* 0x68ed: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_68f1:
	/* 0x68f1: je     6957 <kprobe_unwind_ruby+0x6957> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6957;
	}
x86_l_68f3:
	/* 0x68f3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68f5:
	/* 0x68f5: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_68f8:
	/* 0x68f8: jmp    695b <kprobe_unwind_ruby+0x695b> */
	goto x86_l_695b;
x86_l_68fa:
	/* 0x68fa: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_6901:
	/* 0x6901: jb     6afb <kprobe_unwind_ruby+0x6afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_6afb;
	}
x86_l_6907:
	/* 0x6907: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_690f:
	/* 0x690f: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_6914:
	/* 0x6914: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6919:
	/* 0x6919: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_691c:
	/* 0x691c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6921:
	/* 0x6921: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6927:
	/* 0x6927: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_692c:
	/* 0x692c: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6931:
	/* 0x6931: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6936:
	/* 0x6936: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6939:
	/* 0x6939: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_693c:
	/* 0x693c: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_6942:
	/* 0x6942: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6945:
	/* 0x6945: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_6947:
	/* 0x6947: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_694c:
	/* 0x694c: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_6952:
	/* 0x6952: jmp    6afb <kprobe_unwind_ruby+0x6afb> */
	goto x86_l_6afb;
x86_l_6957:
	/* 0x6957: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6959:
	/* 0x6959: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_695b:
	/* 0x695b: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_695f:
	/* 0x695f: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_6962:
	/* 0x6962: jbe    69ef <kprobe_unwind_ruby+0x69ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_69ef;
	}
x86_l_6968:
	/* 0x6968: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_696f:
	/* 0x696f: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6972:
	/* 0x6972: je     6afb <kprobe_unwind_ruby+0x6afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6afb;
	}
x86_l_6978:
	/* 0x6978: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_6982:
	/* 0x6982: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_6987:
	/* 0x6987: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_6991:
	/* 0x6991: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6996:
	/* 0x6996: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_69a0:
	/* 0x69a0: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_69a5:
	/* 0x69a5: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_69af:
	/* 0x69af: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_69b4:
	/* 0x69b4: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_69be:
	/* 0x69be: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_69c3:
	/* 0x69c3: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_69cd:
	/* 0x69cd: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_69d2:
	/* 0x69d2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_69d7:
	/* 0x69d7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_69dc:
	/* 0x69dc: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_69e1:
	/* 0x69e1: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_69e6:
	/* 0x69e6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69e8:
	/* 0x69e8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_69ea:
	/* 0x69ea: jmp    6afb <kprobe_unwind_ruby+0x6afb> */
	goto x86_l_6afb;
x86_l_69ef:
	/* 0x69ef: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_69f6:
	/* 0x69f6: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_69fa:
	/* 0x69fa: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_6a00:
	/* 0x6a00: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6a05:
	/* 0x6a05: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_6a08:
	/* 0x6a08: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_6a0f:
	/* 0x6a0f: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_6a13:
	/* 0x6a13: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_6a1a:
	/* 0x6a1a: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a21:
	/* 0x6a21: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_6a29:
	/* 0x6a29: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_6a31:
	/* 0x6a31: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_6a3c:
	/* 0x6a3c: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a3f:
	/* 0x6a3f: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_6a47:
	/* 0x6a47: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_6a4c:
	/* 0x6a4c: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_6a55:
	/* 0x6a55: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_6a5c:
	/* 0x6a5c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_6a63:
	/* 0x6a63: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_6a66:
	/* 0x6a66: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6a6b:
	/* 0x6a6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a6d:
	/* 0x6a6d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6a70:
	/* 0x6a70: je     6a7a <kprobe_unwind_ruby+0x6a7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6a7a;
	}
x86_l_6a72:
	/* 0x6a72: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6a75:
	/* 0x6a75: jmp    6afb <kprobe_unwind_ruby+0x6afb> */
	goto x86_l_6afb;
x86_l_6a7a:
	/* 0x6a7a: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6a81:
	/* 0x6a81: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a84:
	/* 0x6a84: je     6afb <kprobe_unwind_ruby+0x6afb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6afb;
	}
x86_l_6a86:
	/* 0x6a86: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_6a90:
	/* 0x6a90: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_6a95:
	/* 0x6a95: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_6a9f:
	/* 0x6a9f: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6aa4:
	/* 0x6aa4: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_6aae:
	/* 0x6aae: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6ab3:
	/* 0x6ab3: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_6abd:
	/* 0x6abd: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6ac2:
	/* 0x6ac2: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_6acc:
	/* 0x6acc: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6ad1:
	/* 0x6ad1: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_6adb:
	/* 0x6adb: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6ae0:
	/* 0x6ae0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6ae5:
	/* 0x6ae5: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_6aea:
	/* 0x6aea: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6aef:
	/* 0x6aef: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6af2:
	/* 0x6af2: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_6af7:
	/* 0x6af7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6af9:
	/* 0x6af9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6afb:
	/* 0x6afb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6b00:
	/* 0x6b00: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_6b03:
	/* 0x6b03: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_6b09:
	/* 0x6b09: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_6b0e:
	/* 0x6b0e: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6b11:
	/* 0x6b11: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6b16:
	/* 0x6b16: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_6b1f:
	/* 0x6b1f: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_6b28:
	/* 0x6b28: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_6b2d:
	/* 0x6b2d: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6b30:
	/* 0x6b30: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6b35:
	/* 0x6b35: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6b3a:
	/* 0x6b3a: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6b40:
	/* 0x6b40: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_6b45:
	/* 0x6b45: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6b4a:
	/* 0x6b4a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6b4f:
	/* 0x6b4f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6b52:
	/* 0x6b52: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_6b57:
	/* 0x6b57: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6b5c:
	/* 0x6b5c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6b61:
	/* 0x6b61: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6b66:
	/* 0x6b66: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6b6c:
	/* 0x6b6c: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_6b71:
	/* 0x6b71: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6b76:
	/* 0x6b76: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6b7b:
	/* 0x6b7b: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6b7e:
	/* 0x6b7e: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_6b84:
	/* 0x6b84: je     6c57 <kprobe_unwind_ruby+0x6c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6c57;
	}
x86_l_6b8a:
	/* 0x6b8a: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6b8f:
	/* 0x6b8f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6b92:
	/* 0x6b92: je     6c57 <kprobe_unwind_ruby+0x6c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6c57;
	}
x86_l_6b98:
	/* 0x6b98: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_6b9d:
	/* 0x6b9d: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6ba0:
	/* 0x6ba0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6ba5:
	/* 0x6ba5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6baa:
	/* 0x6baa: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6bb0:
	/* 0x6bb0: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_6bb5:
	/* 0x6bb5: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_6bba:
	/* 0x6bba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6bbf:
	/* 0x6bbf: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6bc2:
	/* 0x6bc2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6bc5:
	/* 0x6bc5: jne    4bd <kprobe_unwind_ruby+0x4bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1213ULL;
	}
x86_l_6bcb:
	/* 0x6bcb: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_6bd0:
	/* 0x6bd0: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_6bd5:
	/* 0x6bd5: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6bda:
	/* 0x6bda: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6bdf:
	/* 0x6bdf: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6be5:
	/* 0x6be5: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_6bea:
	/* 0x6bea: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_6bef:
	/* 0x6bef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6bf4:
	/* 0x6bf4: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6bf7:
	/* 0x6bf7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6bfa:
	/* 0x6bfa: jne    812 <kprobe_unwind_ruby+0x812> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2066ULL;
	}
x86_l_6c00:
	/* 0x6c00: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_6c05:
	/* 0x6c05: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_6c0a:
	/* 0x6c0a: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6c0f:
	/* 0x6c0f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6c14:
	/* 0x6c14: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6c1a:
	/* 0x6c1a: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_6c1f:
	/* 0x6c1f: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_6c24:
	/* 0x6c24: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6c29:
	/* 0x6c29: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6c2c:
	/* 0x6c2c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6c2f:
	/* 0x6c2f: jne    aea <kprobe_unwind_ruby+0xaea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2794ULL;
	}
x86_l_6c35:
	/* 0x6c35: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6c3a:
	/* 0x6c3a: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_6c3d:
	/* 0x6c3d: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_6c42:
	/* 0x6c42: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_6c47:
	/* 0x6c47: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6c4a:
	/* 0x6c4a: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_6c4e:
	/* 0x6c4e: je     6cb4 <kprobe_unwind_ruby+0x6cb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6cb4;
	}
x86_l_6c50:
	/* 0x6c50: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6c52:
	/* 0x6c52: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_6c55:
	/* 0x6c55: jmp    6cb8 <kprobe_unwind_ruby+0x6cb8> */
	goto x86_l_6cb8;
x86_l_6c57:
	/* 0x6c57: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_6c5e:
	/* 0x6c5e: jb     6e58 <kprobe_unwind_ruby+0x6e58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 28248ULL;
	}
x86_l_6c64:
	/* 0x6c64: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6c6c:
	/* 0x6c6c: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_6c71:
	/* 0x6c71: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6c76:
	/* 0x6c76: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6c79:
	/* 0x6c79: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6c7e:
	/* 0x6c7e: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6c84:
	/* 0x6c84: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_6c89:
	/* 0x6c89: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6c8e:
	/* 0x6c8e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6c93:
	/* 0x6c93: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6c96:
	/* 0x6c96: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6c99:
	/* 0x6c99: jne    789 <kprobe_unwind_ruby+0x789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1929ULL;
	}
x86_l_6c9f:
	/* 0x6c9f: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ca2:
	/* 0x6ca2: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_6ca4:
	/* 0x6ca4: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_6ca9:
	/* 0x6ca9: jne    905 <kprobe_unwind_ruby+0x905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2309ULL;
	}
x86_l_6caf:
	/* 0x6caf: jmp    6e58 <kprobe_unwind_ruby+0x6e58> */
	return 28248ULL;
x86_l_6cb4:
	/* 0x6cb4: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6cb6:
	/* 0x6cb6: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_6cb8:
	/* 0x6cb8: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6cbc:
	/* 0x6cbc: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_6cbf:
	/* 0x6cbf: jbe    6d4c <kprobe_unwind_ruby+0x6d4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_6d4c;
	}
x86_l_6cc5:
	/* 0x6cc5: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6ccc:
	/* 0x6ccc: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ccf:
	/* 0x6ccf: je     6e58 <kprobe_unwind_ruby+0x6e58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28248ULL;
	}
x86_l_6cd5:
	/* 0x6cd5: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_6cdf:
	/* 0x6cdf: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_6ce4:
	/* 0x6ce4: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_6cee:
	/* 0x6cee: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6cf3:
	/* 0x6cf3: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_6cfd:
	/* 0x6cfd: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6d02:
	/* 0x6d02: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_6d0c:
	/* 0x6d0c: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6d11:
	/* 0x6d11: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_6d1b:
	/* 0x6d1b: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6d20:
	/* 0x6d20: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_6d2a:
	/* 0x6d2a: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6d2f:
	/* 0x6d2f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6d34:
	/* 0x6d34: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_6d39:
	/* 0x6d39: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6d3e:
	/* 0x6d3e: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_6d43:
	/* 0x6d43: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6d45:
	/* 0x6d45: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6d47:
	/* 0x6d47: jmp    6e58 <kprobe_unwind_ruby+0x6e58> */
	return 28248ULL;
x86_l_6d4c:
	/* 0x6d4c: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_6d53:
	/* 0x6d53: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_6d57:
	/* 0x6d57: ja     e38 <kprobe_unwind_ruby+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3640ULL;
	}
x86_l_6d5d:
	/* 0x6d5d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6d62:
	/* 0x6d62: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_6d65:
	/* 0x6d65: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_6d6c:
	/* 0x6d6c: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_6d70:
	/* 0x6d70: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_6d77:
	/* 0x6d77: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6d7e:
	/* 0x6d7e: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_6d86:
	/* 0x6d86: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_6d8e:
	/* 0x6d8e: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_6d99:
	/* 0x6d99: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6d9c:
	/* 0x6d9c: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_6da4:
	/* 0x6da4: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_6da9:
	/* 0x6da9: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_6db2:
	/* 0x6db2: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_6db9:
	/* 0x6db9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_6dc0:
	/* 0x6dc0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_6dc3:
	/* 0x6dc3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6dc8:
	/* 0x6dc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6dca:
	/* 0x6dca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6dcd:
	/* 0x6dcd: je     6dd7 <kprobe_unwind_ruby+0x6dd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6dd7;
	}
x86_l_6dcf:
	/* 0x6dcf: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6dd2:
	/* 0x6dd2: jmp    6e58 <kprobe_unwind_ruby+0x6e58> */
	return 28248ULL;
x86_l_6dd7:
	/* 0x6dd7: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6dde:
	/* 0x6dde: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6de1:
	/* 0x6de1: je     6e58 <kprobe_unwind_ruby+0x6e58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28248ULL;
	}
x86_l_6de3:
	/* 0x6de3: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_6ded:
	/* 0x6ded: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_6df2:
	/* 0x6df2: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_6dfc:
	/* 0x6dfc: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6e01:
	/* 0x6e01: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_6e0b:
	/* 0x6e0b: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6e10:
	/* 0x6e10: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_6e1a:
	/* 0x6e1a: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6e1f:
	/* 0x6e1f: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_6e29:
	/* 0x6e29: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
	return 28206ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_14(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 28206ULL: goto x86_l_6e2e;
	case 28216ULL: goto x86_l_6e38;
	case 28221ULL: goto x86_l_6e3d;
	case 28226ULL: goto x86_l_6e42;
	case 28231ULL: goto x86_l_6e47;
	case 28236ULL: goto x86_l_6e4c;
	case 28239ULL: goto x86_l_6e4f;
	case 28244ULL: goto x86_l_6e54;
	case 28246ULL: goto x86_l_6e56;
	case 28248ULL: goto x86_l_6e58;
	case 28253ULL: goto x86_l_6e5d;
	case 28256ULL: goto x86_l_6e60;
	case 28262ULL: goto x86_l_6e66;
	case 28267ULL: goto x86_l_6e6b;
	case 28270ULL: goto x86_l_6e6e;
	case 28275ULL: goto x86_l_6e73;
	case 28280ULL: goto x86_l_6e78;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6e2e:
	/* 0x6e2e: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_6e38:
	/* 0x6e38: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6e3d:
	/* 0x6e3d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6e42:
	/* 0x6e42: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_6e47:
	/* 0x6e47: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6e4c:
	/* 0x6e4c: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6e4f:
	/* 0x6e4f: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_6e54:
	/* 0x6e54: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6e56:
	/* 0x6e56: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6e58:
	/* 0x6e58: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6e5d:
	/* 0x6e5d: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_6e60:
	/* 0x6e60: jbe    2ab <kprobe_unwind_ruby+0x2ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 683ULL;
	}
x86_l_6e66:
	/* 0x6e66: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_6e6b:
	/* 0x6e6b: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6e6e:
	/* 0x6e6e: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6e73:
	/* 0x6e73: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_6e78:
	/* 0x6e78: jmp    919 <kprobe_unwind_ruby+0x919> */
	return 2329ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 21572U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1862ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1865ULL && __x86_pc <= 3742ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3752ULL && __x86_pc <= 5875ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5880ULL && __x86_pc <= 7971ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7976ULL && __x86_pc <= 10113ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 10123ULL && __x86_pc <= 12140ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 12149ULL && __x86_pc <= 14133ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 14138ULL && __x86_pc <= 16135ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 16139ULL && __x86_pc <= 18147ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 18157ULL && __x86_pc <= 20242ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 20248ULL && __x86_pc <= 22257ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 22266ULL && __x86_pc <= 24224ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 24230ULL && __x86_pc <= 26184ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 26194ULL && __x86_pc <= 28201ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_13(__x86_state, __x86_pc);
		else if (__x86_pc >= 28206ULL && __x86_pc <= 28280ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_ruby_x86_chunk_14(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

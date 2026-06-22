extern char buffer_heap_map;
extern char config_map;
extern char execve_map;
extern char fdinstall_map;
extern char fexit_calls;
extern char process_call_heap;
extern char retprobe_map;
extern char tg_ipv6_ext_heap;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_event_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 18ULL: goto x86_l_12;
	case 26ULL: goto x86_l_1a;
	case 28ULL: goto x86_l_1c;
	case 36ULL: goto x86_l_24;
	case 47ULL: goto x86_l_2f;
	case 52ULL: goto x86_l_34;
	case 59ULL: goto x86_l_3b;
	case 67ULL: goto x86_l_43;
	case 69ULL: goto x86_l_45;
	case 72ULL: goto x86_l_48;
	case 78ULL: goto x86_l_4e;
	case 81ULL: goto x86_l_51;
	case 84ULL: goto x86_l_54;
	case 91ULL: goto x86_l_5b;
	case 102ULL: goto x86_l_66;
	case 107ULL: goto x86_l_6b;
	case 114ULL: goto x86_l_72;
	case 116ULL: goto x86_l_74;
	case 119ULL: goto x86_l_77;
	case 125ULL: goto x86_l_7d;
	case 128ULL: goto x86_l_80;
	case 130ULL: goto x86_l_82;
	case 134ULL: goto x86_l_86;
	case 139ULL: goto x86_l_8b;
	case 141ULL: goto x86_l_8d;
	case 145ULL: goto x86_l_91;
	case 147ULL: goto x86_l_93;
	case 151ULL: goto x86_l_97;
	case 155ULL: goto x86_l_9b;
	case 160ULL: goto x86_l_a0;
	case 162ULL: goto x86_l_a2;
	case 166ULL: goto x86_l_a6;
	case 170ULL: goto x86_l_aa;
	case 174ULL: goto x86_l_ae;
	case 179ULL: goto x86_l_b3;
	case 184ULL: goto x86_l_b8;
	case 189ULL: goto x86_l_bd;
	case 196ULL: goto x86_l_c4;
	case 201ULL: goto x86_l_c9;
	case 203ULL: goto x86_l_cb;
	case 206ULL: goto x86_l_ce;
	case 212ULL: goto x86_l_d4;
	case 215ULL: goto x86_l_d7;
	case 219ULL: goto x86_l_db;
	case 227ULL: goto x86_l_e3;
	case 231ULL: goto x86_l_e7;
	case 239ULL: goto x86_l_ef;
	case 244ULL: goto x86_l_f4;
	case 251ULL: goto x86_l_fb;
	case 256ULL: goto x86_l_100;
	case 258ULL: goto x86_l_102;
	case 265ULL: goto x86_l_109;
	case 269ULL: goto x86_l_10d;
	case 273ULL: goto x86_l_111;
	case 275ULL: goto x86_l_113;
	case 277ULL: goto x86_l_115;
	case 284ULL: goto x86_l_11c;
	case 295ULL: goto x86_l_127;
	case 306ULL: goto x86_l_132;
	case 311ULL: goto x86_l_137;
	case 318ULL: goto x86_l_13e;
	case 326ULL: goto x86_l_146;
	case 328ULL: goto x86_l_148;
	case 331ULL: goto x86_l_14b;
	case 337ULL: goto x86_l_151;
	case 343ULL: goto x86_l_157;
	case 349ULL: goto x86_l_15d;
	case 360ULL: goto x86_l_168;
	case 362ULL: goto x86_l_16a;
	case 368ULL: goto x86_l_170;
	case 373ULL: goto x86_l_175;
	case 380ULL: goto x86_l_17c;
	case 385ULL: goto x86_l_181;
	case 390ULL: goto x86_l_186;
	case 397ULL: goto x86_l_18d;
	case 400ULL: goto x86_l_190;
	case 406ULL: goto x86_l_196;
	case 411ULL: goto x86_l_19b;
	case 419ULL: goto x86_l_1a3;
	case 423ULL: goto x86_l_1a7;
	case 432ULL: goto x86_l_1b0;
	case 440ULL: goto x86_l_1b8;
	case 446ULL: goto x86_l_1be;
	case 454ULL: goto x86_l_1c6;
	case 460ULL: goto x86_l_1cc;
	case 465ULL: goto x86_l_1d1;
	case 470ULL: goto x86_l_1d6;
	case 475ULL: goto x86_l_1db;
	case 483ULL: goto x86_l_1e3;
	case 485ULL: goto x86_l_1e5;
	case 490ULL: goto x86_l_1ea;
	case 492ULL: goto x86_l_1ec;
	case 498ULL: goto x86_l_1f2;
	case 503ULL: goto x86_l_1f7;
	case 506ULL: goto x86_l_1fa;
	case 509ULL: goto x86_l_1fd;
	case 513ULL: goto x86_l_201;
	case 516ULL: goto x86_l_204;
	case 520ULL: goto x86_l_208;
	case 525ULL: goto x86_l_20d;
	case 532ULL: goto x86_l_214;
	case 538ULL: goto x86_l_21a;
	case 541ULL: goto x86_l_21d;
	case 545ULL: goto x86_l_221;
	case 550ULL: goto x86_l_226;
	case 554ULL: goto x86_l_22a;
	case 559ULL: goto x86_l_22f;
	case 564ULL: goto x86_l_234;
	case 567ULL: goto x86_l_237;
	case 569ULL: goto x86_l_239;
	case 574ULL: goto x86_l_23e;
	case 576ULL: goto x86_l_240;
	case 582ULL: goto x86_l_246;
	case 585ULL: goto x86_l_249;
	case 588ULL: goto x86_l_24c;
	case 594ULL: goto x86_l_252;
	case 597ULL: goto x86_l_255;
	case 602ULL: goto x86_l_25a;
	case 610ULL: goto x86_l_262;
	case 616ULL: goto x86_l_268;
	case 618ULL: goto x86_l_26a;
	case 620ULL: goto x86_l_26c;
	case 627ULL: goto x86_l_273;
	case 632ULL: goto x86_l_278;
	case 639ULL: goto x86_l_27f;
	case 644ULL: goto x86_l_284;
	case 653ULL: goto x86_l_28d;
	case 656ULL: goto x86_l_290;
	case 660ULL: goto x86_l_294;
	case 668ULL: goto x86_l_29c;
	case 670ULL: goto x86_l_29e;
	case 673ULL: goto x86_l_2a1;
	case 679ULL: goto x86_l_2a7;
	case 682ULL: goto x86_l_2aa;
	case 684ULL: goto x86_l_2ac;
	case 686ULL: goto x86_l_2ae;
	case 689ULL: goto x86_l_2b1;
	case 693ULL: goto x86_l_2b5;
	case 698ULL: goto x86_l_2ba;
	case 702ULL: goto x86_l_2be;
	case 705ULL: goto x86_l_2c1;
	case 710ULL: goto x86_l_2c6;
	case 713ULL: goto x86_l_2c9;
	case 719ULL: goto x86_l_2cf;
	case 722ULL: goto x86_l_2d2;
	case 724ULL: goto x86_l_2d4;
	case 729ULL: goto x86_l_2d9;
	case 734ULL: goto x86_l_2de;
	case 739ULL: goto x86_l_2e3;
	case 744ULL: goto x86_l_2e8;
	case 746ULL: goto x86_l_2ea;
	case 751ULL: goto x86_l_2ef;
	case 756ULL: goto x86_l_2f4;
	case 761ULL: goto x86_l_2f9;
	case 766ULL: goto x86_l_2fe;
	case 771ULL: goto x86_l_303;
	case 776ULL: goto x86_l_308;
	case 778ULL: goto x86_l_30a;
	case 783ULL: goto x86_l_30f;
	case 787ULL: goto x86_l_313;
	case 792ULL: goto x86_l_318;
	case 797ULL: goto x86_l_31d;
	case 800ULL: goto x86_l_320;
	case 806ULL: goto x86_l_326;
	case 808ULL: goto x86_l_328;
	case 818ULL: goto x86_l_332;
	case 822ULL: goto x86_l_336;
	case 828ULL: goto x86_l_33c;
	case 833ULL: goto x86_l_341;
	case 844ULL: goto x86_l_34c;
	case 849ULL: goto x86_l_351;
	case 856ULL: goto x86_l_358;
	case 864ULL: goto x86_l_360;
	case 866ULL: goto x86_l_362;
	case 868ULL: goto x86_l_364;
	case 871ULL: goto x86_l_367;
	case 877ULL: goto x86_l_36d;
	case 880ULL: goto x86_l_370;
	case 886ULL: goto x86_l_376;
	case 889ULL: goto x86_l_379;
	case 895ULL: goto x86_l_37f;
	case 898ULL: goto x86_l_382;
	case 904ULL: goto x86_l_388;
	case 907ULL: goto x86_l_38b;
	case 913ULL: goto x86_l_391;
	case 916ULL: goto x86_l_394;
	case 922ULL: goto x86_l_39a;
	case 925ULL: goto x86_l_39d;
	case 929ULL: goto x86_l_3a1;
	case 935ULL: goto x86_l_3a7;
	case 940ULL: goto x86_l_3ac;
	case 945ULL: goto x86_l_3b1;
	case 950ULL: goto x86_l_3b6;
	case 955ULL: goto x86_l_3bb;
	case 960ULL: goto x86_l_3c0;
	case 965ULL: goto x86_l_3c5;
	case 967ULL: goto x86_l_3c7;
	case 972ULL: goto x86_l_3cc;
	case 977ULL: goto x86_l_3d1;
	case 980ULL: goto x86_l_3d4;
	case 986ULL: goto x86_l_3da;
	case 997ULL: goto x86_l_3e5;
	case 1002ULL: goto x86_l_3ea;
	case 1009ULL: goto x86_l_3f1;
	case 1017ULL: goto x86_l_3f9;
	case 1019ULL: goto x86_l_3fb;
	case 1022ULL: goto x86_l_3fe;
	case 1027ULL: goto x86_l_403;
	case 1033ULL: goto x86_l_409;
	case 1035ULL: goto x86_l_40b;
	case 1038ULL: goto x86_l_40e;
	case 1042ULL: goto x86_l_412;
	case 1048ULL: goto x86_l_418;
	case 1051ULL: goto x86_l_41b;
	case 1056ULL: goto x86_l_420;
	case 1062ULL: goto x86_l_426;
	case 1065ULL: goto x86_l_429;
	case 1071ULL: goto x86_l_42f;
	case 1074ULL: goto x86_l_432;
	case 1080ULL: goto x86_l_438;
	case 1083ULL: goto x86_l_43b;
	case 1089ULL: goto x86_l_441;
	case 1092ULL: goto x86_l_444;
	case 1098ULL: goto x86_l_44a;
	case 1108ULL: goto x86_l_454;
	case 1115ULL: goto x86_l_45b;
	case 1120ULL: goto x86_l_460;
	case 1132ULL: goto x86_l_46c;
	case 1140ULL: goto x86_l_474;
	case 1148ULL: goto x86_l_47c;
	case 1153ULL: goto x86_l_481;
	case 1158ULL: goto x86_l_486;
	case 1169ULL: goto x86_l_491;
	case 1174ULL: goto x86_l_496;
	case 1181ULL: goto x86_l_49d;
	case 1189ULL: goto x86_l_4a5;
	case 1191ULL: goto x86_l_4a7;
	case 1194ULL: goto x86_l_4aa;
	case 1200ULL: goto x86_l_4b0;
	case 1203ULL: goto x86_l_4b3;
	case 1208ULL: goto x86_l_4b8;
	case 1214ULL: goto x86_l_4be;
	case 1219ULL: goto x86_l_4c3;
	case 1224ULL: goto x86_l_4c8;
	case 1226ULL: goto x86_l_4ca;
	case 1233ULL: goto x86_l_4d1;
	case 1238ULL: goto x86_l_4d6;
	case 1246ULL: goto x86_l_4de;
	case 1251ULL: goto x86_l_4e3;
	case 1253ULL: goto x86_l_4e5;
	case 1261ULL: goto x86_l_4ed;
	case 1266ULL: goto x86_l_4f2;
	case 1274ULL: goto x86_l_4fa;
	case 1279ULL: goto x86_l_4ff;
	case 1283ULL: goto x86_l_503;
	case 1288ULL: goto x86_l_508;
	case 1296ULL: goto x86_l_510;
	case 1301ULL: goto x86_l_515;
	case 1309ULL: goto x86_l_51d;
	case 1311ULL: goto x86_l_51f;
	case 1319ULL: goto x86_l_527;
	case 1323ULL: goto x86_l_52b;
	case 1328ULL: goto x86_l_530;
	case 1333ULL: goto x86_l_535;
	case 1338ULL: goto x86_l_53a;
	case 1340ULL: goto x86_l_53c;
	case 1346ULL: goto x86_l_542;
	case 1351ULL: goto x86_l_547;
	case 1353ULL: goto x86_l_549;
	case 1358ULL: goto x86_l_54e;
	case 1360ULL: goto x86_l_550;
	case 1362ULL: goto x86_l_552;
	case 1367ULL: goto x86_l_557;
	case 1372ULL: goto x86_l_55c;
	case 1376ULL: goto x86_l_560;
	case 1381ULL: goto x86_l_565;
	case 1386ULL: goto x86_l_56a;
	case 1391ULL: goto x86_l_56f;
	case 1393ULL: goto x86_l_571;
	case 1398ULL: goto x86_l_576;
	case 1403ULL: goto x86_l_57b;
	case 1405ULL: goto x86_l_57d;
	case 1408ULL: goto x86_l_580;
	case 1415ULL: goto x86_l_587;
	case 1425ULL: goto x86_l_591;
	case 1432ULL: goto x86_l_598;
	case 1442ULL: goto x86_l_5a2;
	case 1447ULL: goto x86_l_5a7;
	case 1456ULL: goto x86_l_5b0;
	case 1465ULL: goto x86_l_5b9;
	case 1470ULL: goto x86_l_5be;
	case 1475ULL: goto x86_l_5c3;
	case 1480ULL: goto x86_l_5c8;
	case 1489ULL: goto x86_l_5d1;
	case 1498ULL: goto x86_l_5da;
	case 1507ULL: goto x86_l_5e3;
	case 1512ULL: goto x86_l_5e8;
	case 1517ULL: goto x86_l_5ed;
	case 1521ULL: goto x86_l_5f1;
	case 1526ULL: goto x86_l_5f6;
	case 1531ULL: goto x86_l_5fb;
	case 1535ULL: goto x86_l_5ff;
	case 1540ULL: goto x86_l_604;
	case 1545ULL: goto x86_l_609;
	case 1550ULL: goto x86_l_60e;
	case 1553ULL: goto x86_l_611;
	case 1555ULL: goto x86_l_613;
	case 1560ULL: goto x86_l_618;
	case 1563ULL: goto x86_l_61b;
	case 1568ULL: goto x86_l_620;
	case 1576ULL: goto x86_l_628;
	case 1578ULL: goto x86_l_62a;
	case 1583ULL: goto x86_l_62f;
	case 1586ULL: goto x86_l_632;
	case 1591ULL: goto x86_l_637;
	case 1599ULL: goto x86_l_63f;
	case 1601ULL: goto x86_l_641;
	case 1606ULL: goto x86_l_646;
	case 1609ULL: goto x86_l_649;
	case 1614ULL: goto x86_l_64e;
	case 1619ULL: goto x86_l_653;
	case 1621ULL: goto x86_l_655;
	case 1626ULL: goto x86_l_65a;
	case 1631ULL: goto x86_l_65f;
	case 1636ULL: goto x86_l_664;
	case 1641ULL: goto x86_l_669;
	case 1646ULL: goto x86_l_66e;
	case 1648ULL: goto x86_l_670;
	case 1653ULL: goto x86_l_675;
	case 1655ULL: goto x86_l_677;
	case 1660ULL: goto x86_l_67c;
	case 1665ULL: goto x86_l_681;
	case 1670ULL: goto x86_l_686;
	case 1674ULL: goto x86_l_68a;
	case 1679ULL: goto x86_l_68f;
	case 1684ULL: goto x86_l_694;
	case 1692ULL: goto x86_l_69c;
	case 1697ULL: goto x86_l_6a1;
	case 1700ULL: goto x86_l_6a4;
	case 1702ULL: goto x86_l_6a6;
	case 1710ULL: goto x86_l_6ae;
	case 1716ULL: goto x86_l_6b4;
	case 1720ULL: goto x86_l_6b8;
	case 1725ULL: goto x86_l_6bd;
	case 1730ULL: goto x86_l_6c2;
	case 1735ULL: goto x86_l_6c7;
	case 1738ULL: goto x86_l_6ca;
	case 1740ULL: goto x86_l_6cc;
	case 1745ULL: goto x86_l_6d1;
	case 1751ULL: goto x86_l_6d7;
	case 1756ULL: goto x86_l_6dc;
	case 1764ULL: goto x86_l_6e4;
	case 1769ULL: goto x86_l_6e9;
	case 1772ULL: goto x86_l_6ec;
	case 1774ULL: goto x86_l_6ee;
	case 1778ULL: goto x86_l_6f2;
	case 1783ULL: goto x86_l_6f7;
	case 1788ULL: goto x86_l_6fc;
	case 1793ULL: goto x86_l_701;
	case 1796ULL: goto x86_l_704;
	case 1798ULL: goto x86_l_706;
	case 1803ULL: goto x86_l_70b;
	case 1808ULL: goto x86_l_710;
	case 1812ULL: goto x86_l_714;
	case 1815ULL: goto x86_l_717;
	case 1819ULL: goto x86_l_71b;
	case 1821ULL: goto x86_l_71d;
	case 1823ULL: goto x86_l_71f;
	case 1825ULL: goto x86_l_721;
	case 1828ULL: goto x86_l_724;
	case 1833ULL: goto x86_l_729;
	case 1836ULL: goto x86_l_72c;
	case 1838ULL: goto x86_l_72e;
	case 1842ULL: goto x86_l_732;
	case 1844ULL: goto x86_l_734;
	case 1847ULL: goto x86_l_737;
	case 1850ULL: goto x86_l_73a;
	case 1853ULL: goto x86_l_73d;
	case 1856ULL: goto x86_l_740;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 248ULL);
x86_l_a:
	/* 0xa: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    eax,0xb8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 184ULL);
x86_l_12:
	/* 0x12: lea    rsi,[rsp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1a:
	/* 0x1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c:
	/* 0x1c: mov    r12,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_24:
	/* 0x24: mov    DWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_2f:
	/* 0x2f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34:
	/* 0x34: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_3b:
	/* 0x3b: lea    rsi,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_43:
	/* 0x43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45:
	/* 0x45: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_48:
	/* 0x48: je     3874 <generic_fexit_event+0x3874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14452ULL;
	}
x86_l_4e:
	/* 0x4e: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_51:
	/* 0x51: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_54:
	/* 0x54: lea    rsi,[rax+0x5ee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24296ULL);
x86_l_5b:
	/* 0x5b: mov    DWORD PTR [r15+0x5ee8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104350525423616ULL);
x86_l_66:
	/* 0x66: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6b:
	/* 0x6b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_72:
	/* 0x72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_74:
	/* 0x74: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_77:
	/* 0x77: je     3874 <generic_fexit_event+0x3874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14452ULL;
	}
x86_l_7d:
	/* 0x7d: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_80:
	/* 0x80: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_82:
	/* 0x82: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_86:
	/* 0x86: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_8b:
	/* 0x8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d:
	/* 0x8d: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_91:
	/* 0x91: jne    97 <generic_fexit_event+0x97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_97;
	}
x86_l_93:
	/* 0x93: mov    rax,QWORD PTR [rbp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_97:
	/* 0x97: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9b:
	/* 0x9b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_a0:
	/* 0xa0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a2:
	/* 0xa2: mov    DWORD PTR [r14+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_a6:
	/* 0xa6: mov    rax,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_aa:
	/* 0xaa: mov    rcx,QWORD PTR [r14+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_ae:
	/* 0xae: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b3:
	/* 0xb3: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b8:
	/* 0xb8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bd:
	/* 0xbd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_c4:
	/* 0xc4: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c9:
	/* 0xc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cb:
	/* 0xcb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ce:
	/* 0xce: je     3874 <generic_fexit_event+0x3874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14452ULL;
	}
x86_l_d4:
	/* 0xd4: mov    rbx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d7:
	/* 0xd7: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_db:
	/* 0xdb: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_e3:
	/* 0xe3: mov    rax,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e7:
	/* 0xe7: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_ef:
	/* 0xef: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_f4:
	/* 0xf4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_fb:
	/* 0xfb: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_100:
	/* 0x100: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_102:
	/* 0x102: mov    QWORD PTR [r14+0x90],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_109:
	/* 0x109: mov    eax,DWORD PTR [r13+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_10d:
	/* 0x10d: mov    ebx,DWORD PTR [r13+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_111:
	/* 0x111: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_113:
	/* 0x113: je     181 <generic_fexit_event+0x181> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_181;
	}
x86_l_115:
	/* 0x115: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_11c:
	/* 0x11c: mov    DWORD PTR [r14+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104041287778304ULL);
x86_l_127:
	/* 0x127: mov    DWORD PTR [rsp+0xdc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_132:
	/* 0x132: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_137:
	/* 0x137: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_13e:
	/* 0x13e: lea    rsi,[rsp+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_146:
	/* 0x146: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_148:
	/* 0x148: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14b:
	/* 0x14b: je     26a <generic_fexit_event+0x26a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26a;
	}
x86_l_151:
	/* 0x151: mov    ecx,DWORD PTR [rax+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24224ULL);
x86_l_157:
	/* 0x157: mov    DWORD PTR [rax+0x98],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_15d:
	/* 0x15d: mov    QWORD PTR [rax+0x5e78],0xc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103869489086476ULL);
x86_l_168:
	/* 0x168: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_16a:
	/* 0x16a: je     278 <generic_fexit_event+0x278> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_278;
	}
x86_l_170:
	/* 0x170: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_175:
	/* 0x175: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_17c:
	/* 0x17c: jmp    35ae <generic_fexit_event+0x35ae> */
	return 13742ULL;
x86_l_181:
	/* 0x181: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_186:
	/* 0x186: add    r15,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_18d:
	/* 0x18d: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_190:
	/* 0x190: jne    35c7 <generic_fexit_event+0x35c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13767ULL;
	}
x86_l_196:
	/* 0x196: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19b:
	/* 0x19b: mov    DWORD PTR [r15+rbx*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1a3:
	/* 0x1a3: lea    rax,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a7:
	/* 0x1a7: cmp    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_1b0:
	/* 0x1b0: mov    QWORD PTR [rsp+0xc0],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1b8:
	/* 0x1b8: je     2ae <generic_fexit_event+0x2ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ae;
	}
x86_l_1be:
	/* 0x1be: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c6:
	/* 0x1c6: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1cc:
	/* 0x1cc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d1:
	/* 0x1d1: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d6:
	/* 0x1d6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1db:
	/* 0x1db: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1e3:
	/* 0x1e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e5:
	/* 0x1e5: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1ea:
	/* 0x1ea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ec:
	/* 0x1ec: js     1717 <generic_fexit_event+0x1717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5911ULL;
	}
x86_l_1f2:
	/* 0x1f2: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f7:
	/* 0x1f7: cmp    rsi,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1fa:
	/* 0x1fa: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1fd:
	/* 0x1fd: cmovb  r12,rsi */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RSI, X86_WIDTH_64, X86_CC_B);
x86_l_201:
	/* 0x201: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_204:
	/* 0x204: cmovne rsi,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_208:
	/* 0x208: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_20d:
	/* 0x20d: cmp    rsi,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 4094ULL);
x86_l_214:
	/* 0x214: ja     1717 <generic_fexit_event+0x1717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5911ULL;
	}
x86_l_21a:
	/* 0x21a: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_21d:
	/* 0x21d: add    rbx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_221:
	/* 0x221: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_226:
	/* 0x226: lea    rdi,[r15+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_22a:
	/* 0x22a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22f:
	/* 0x22f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_234:
	/* 0x234: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_237:
	/* 0x237: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_239:
	/* 0x239: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_23e:
	/* 0x23e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_240:
	/* 0x240: js     1717 <generic_fexit_event+0x1717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5911ULL;
	}
x86_l_246:
	/* 0x246: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_249:
	/* 0x249: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_24c:
	/* 0x24c: je     922 <generic_fexit_event+0x922> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2338ULL;
	}
x86_l_252:
	/* 0x252: sub    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_255:
	/* 0x255: mov    QWORD PTR [rsp+0x18],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25a:
	/* 0x25a: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_262:
	/* 0x262: jne    931 <generic_fexit_event+0x931> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2353ULL;
	}
x86_l_268:
	/* 0x268: jmp    2b1 <generic_fexit_event+0x2b1> */
	goto x86_l_2b1;
x86_l_26a:
	/* 0x26a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26c:
	/* 0x26c: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_273:
	/* 0x273: jmp    35ae <generic_fexit_event+0x35ae> */
	return 13742ULL;
x86_l_278:
	/* 0x278: lea    rcx,[rax+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_27f:
	/* 0x27f: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_284:
	/* 0x284: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_28d:
	/* 0x28d: cmp    ebx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 23ULL);
x86_l_290:
	/* 0x290: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_294:
	/* 0x294: mov    QWORD PTR [rsp+0xc0],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_29c:
	/* 0x29c: jg     2c6 <generic_fexit_event+0x2c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2c6;
	}
x86_l_29e:
	/* 0x29e: cmp    ebx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 15ULL);
x86_l_2a1:
	/* 0x2a1: je     3ac <generic_fexit_event+0x3ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ac;
	}
x86_l_2a7:
	/* 0x2a7: cmp    ebx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_2aa:
	/* 0x2aa: je     2f4 <generic_fexit_event+0x2f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f4;
	}
x86_l_2ac:
	/* 0x2ac: jmp    318 <generic_fexit_event+0x318> */
	goto x86_l_318;
x86_l_2ae:
	/* 0x2ae: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b1:
	/* 0x2b1: mov    DWORD PTR [r15+rax*1],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2b5:
	/* 0x2b5: mov    DWORD PTR [r15+rax*1+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_2ba:
	/* 0x2ba: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2be:
	/* 0x2be: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_2c1:
	/* 0x2c1: jmp    1723 <generic_fexit_event+0x1723> */
	return 5923ULL;
x86_l_2c6:
	/* 0x2c6: cmp    ebx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 42ULL);
x86_l_2c9:
	/* 0x2c9: je     460 <generic_fexit_event+0x460> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_460;
	}
x86_l_2cf:
	/* 0x2cf: cmp    ebx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 24ULL);
x86_l_2d2:
	/* 0x2d2: jne    318 <generic_fexit_event+0x318> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_318;
	}
x86_l_2d4:
	/* 0x2d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d9:
	/* 0x2d9: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2de:
	/* 0x2de: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e3:
	/* 0x2e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e8:
	/* 0x2e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ea:
	/* 0x2ea: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ef:
	/* 0x2ef: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f4:
	/* 0x2f4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f9:
	/* 0x2f9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fe:
	/* 0x2fe: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_303:
	/* 0x303: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_308:
	/* 0x308: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30a:
	/* 0x30a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30f:
	/* 0x30f: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_313:
	/* 0x313: jmp    47c <generic_fexit_event+0x47c> */
	goto x86_l_47c;
x86_l_318:
	/* 0x318: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_31d:
	/* 0x31d: cmp    ebx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 40ULL);
x86_l_320:
	/* 0x320: ja     3da <generic_fexit_event+0x3da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3da;
	}
x86_l_326:
	/* 0x326: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_328:
	/* 0x328: movabs rcx,0x1c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1932500565234ULL);
x86_l_332:
	/* 0x332: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_336:
	/* 0x336: jae    3da <generic_fexit_event+0x3da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3da;
	}
x86_l_33c:
	/* 0x33c: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_341:
	/* 0x341: mov    DWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_34c:
	/* 0x34c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_351:
	/* 0x351: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_358:
	/* 0x358: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_360:
	/* 0x360: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_362:
	/* 0x362: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_364:
	/* 0x364: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_367:
	/* 0x367: je     1c28 <generic_fexit_event+0x1c28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7208ULL;
	}
x86_l_36d:
	/* 0x36d: cmp    ebx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 13ULL);
x86_l_370:
	/* 0x370: jle    9f2 <generic_fexit_event+0x9f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2546ULL;
	}
x86_l_376:
	/* 0x376: cmp    ebx,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 30ULL);
x86_l_379:
	/* 0x379: jg     b4b <generic_fexit_event+0xb4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2891ULL;
	}
x86_l_37f:
	/* 0x37f: cmp    ebx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 28ULL);
x86_l_382:
	/* 0x382: jg     d9f <generic_fexit_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3487ULL;
	}
x86_l_388:
	/* 0x388: cmp    ebx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 14ULL);
x86_l_38b:
	/* 0x38b: je     15b5 <generic_fexit_event+0x15b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5557ULL;
	}
x86_l_391:
	/* 0x391: cmp    ebx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 17ULL);
x86_l_394:
	/* 0x394: je     14f2 <generic_fexit_event+0x14f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5362ULL;
	}
x86_l_39a:
	/* 0x39a: cmp    ebx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 28ULL);
x86_l_39d:
	/* 0x39d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a1:
	/* 0x3a1: je     d17 <generic_fexit_event+0xd17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3351ULL;
	}
x86_l_3a7:
	/* 0x3a7: jmp    356a <generic_fexit_event+0x356a> */
	return 13674ULL;
x86_l_3ac:
	/* 0x3ac: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3b1:
	/* 0x3b1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b6:
	/* 0x3b6: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3bb:
	/* 0x3bb: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3c0:
	/* 0x3c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c5:
	/* 0x3c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c7:
	/* 0x3c7: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3cc:
	/* 0x3cc: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d1:
	/* 0x3d1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3d4:
	/* 0x3d4: jne    481 <generic_fexit_event+0x481> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_481;
	}
x86_l_3da:
	/* 0x3da: mov    DWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_3e5:
	/* 0x3e5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3ea:
	/* 0x3ea: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_3f1:
	/* 0x3f1: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3f9:
	/* 0x3f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fb:
	/* 0x3fb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3fe:
	/* 0x3fe: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_403:
	/* 0x403: je     10e1 <generic_fexit_event+0x10e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4321ULL;
	}
x86_l_409:
	/* 0x409: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_40b:
	/* 0x40b: cmp    ebx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 25ULL);
x86_l_40e:
	/* 0x40e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_412:
	/* 0x412: jg     d3b <generic_fexit_event+0xd3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3387ULL;
	}
x86_l_418:
	/* 0x418: cmp    ebx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 18ULL);
x86_l_41b:
	/* 0x41b: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_420:
	/* 0x420: jle    e6d <generic_fexit_event+0xe6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3693ULL;
	}
x86_l_426:
	/* 0x426: cmp    ebx,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 20ULL);
x86_l_429:
	/* 0x429: jle    1294 <generic_fexit_event+0x1294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4756ULL;
	}
x86_l_42f:
	/* 0x42f: cmp    ebx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 21ULL);
x86_l_432:
	/* 0x432: je     1a3b <generic_fexit_event+0x1a3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6715ULL;
	}
x86_l_438:
	/* 0x438: cmp    ebx,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 22ULL);
x86_l_43b:
	/* 0x43b: je     19bc <generic_fexit_event+0x19bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6588ULL;
	}
x86_l_441:
	/* 0x441: cmp    ebx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 23ULL);
x86_l_444:
	/* 0x444: jne    10e7 <generic_fexit_event+0x10e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4327ULL;
	}
x86_l_44a:
	/* 0x44a: mov    DWORD PTR [rcx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_454:
	/* 0x454: mov    DWORD PTR [rcx+0x9c],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_45b:
	/* 0x45b: jmp    e96 <generic_fexit_event+0xe96> */
	return 3734ULL;
x86_l_460:
	/* 0x460: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_46c:
	/* 0x46c: mov    QWORD PTR [rsp+0xb8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_474:
	/* 0x474: lea    rax,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_47c:
	/* 0x47c: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_481:
	/* 0x481: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_486:
	/* 0x486: mov    DWORD PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_491:
	/* 0x491: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_496:
	/* 0x496: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_49d:
	/* 0x49d: lea    rsi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_4a5:
	/* 0x4a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a7:
	/* 0x4a7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4aa:
	/* 0x4aa: je     550 <generic_fexit_event+0x550> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_550;
	}
x86_l_4b0:
	/* 0x4b0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_4b3:
	/* 0x4b3: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b8:
	/* 0x4b8: add    rax,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_4be:
	/* 0x4be: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4c3:
	/* 0x4c3: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_4c8:
	/* 0x4c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ca:
	/* 0x4ca: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_4d1:
	/* 0x4d1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4d6:
	/* 0x4d6: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_4de:
	/* 0x4de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e3:
	/* 0x4e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e5:
	/* 0x4e5: mov    r12,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_4ed:
	/* 0x4ed: lea    rax,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4f2:
	/* 0x4f2: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_4fa:
	/* 0x4fa: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ff:
	/* 0x4ff: lea    rdx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_503:
	/* 0x503: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_508:
	/* 0x508: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_510:
	/* 0x510: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_515:
	/* 0x515: mov    QWORD PTR [rsp+0xe0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_51d:
	/* 0x51d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51f:
	/* 0x51f: mov    rbp,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_527:
	/* 0x527: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52b:
	/* 0x52b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_530:
	/* 0x530: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_535:
	/* 0x535: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53a:
	/* 0x53a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53c:
	/* 0x53c: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_542:
	/* 0x542: mov    ebx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4096ULL);
x86_l_547:
	/* 0x547: je     55c <generic_fexit_event+0x55c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55c;
	}
x86_l_549:
	/* 0x549: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_54e:
	/* 0x54e: jmp    5a7 <generic_fexit_event+0x5a7> */
	goto x86_l_5a7;
x86_l_550:
	/* 0x550: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_552:
	/* 0x552: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_557:
	/* 0x557: jmp    3592 <generic_fexit_event+0x3592> */
	return 13714ULL;
x86_l_55c:
	/* 0x55c: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_560:
	/* 0x560: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_565:
	/* 0x565: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_56a:
	/* 0x56a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56f:
	/* 0x56f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_571:
	/* 0x571: cmp    QWORD PTR [rsp+0x28],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_576:
	/* 0x576: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_57b:
	/* 0x57b: je     5a7 <generic_fexit_event+0x5a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a7;
	}
x86_l_57d:
	/* 0x57d: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_580:
	/* 0x580: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_587:
	/* 0x587: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_591:
	/* 0x591: mov    QWORD PTR [r13+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_598:
	/* 0x598: mov    WORD PTR [r13+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_5a2:
	/* 0x5a2: mov    ebx,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4086ULL);
x86_l_5a7:
	/* 0x5a7: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_5b0:
	/* 0x5b0: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5b9:
	/* 0x5b9: mov    QWORD PTR [rsp+0x38],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5be:
	/* 0x5be: lea    r13,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5c3:
	/* 0x5c3: lea    rbp,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5c8:
	/* 0x5c8: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_5d1:
	/* 0x5d1: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_5da:
	/* 0x5da: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_5e3:
	/* 0x5e3: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5e8:
	/* 0x5e8: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5ed:
	/* 0x5ed: mov    DWORD PTR [rsp+0x60],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5f1:
	/* 0x5f1: lea    rbx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5f6:
	/* 0x5f6: mov    BYTE PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_5fb:
	/* 0x5fb: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_5ff:
	/* 0x5ff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_604:
	/* 0x604: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_609:
	/* 0x609: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60e:
	/* 0x60e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_611:
	/* 0x611: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_613:
	/* 0x613: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_618:
	/* 0x618: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_61b:
	/* 0x61b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_620:
	/* 0x620: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_628:
	/* 0x628: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62a:
	/* 0x62a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_62f:
	/* 0x62f: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_632:
	/* 0x632: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_637:
	/* 0x637: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_63f:
	/* 0x63f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_641:
	/* 0x641: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_646:
	/* 0x646: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_649:
	/* 0x649: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64e:
	/* 0x64e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_653:
	/* 0x653: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_655:
	/* 0x655: mov    r12,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_65a:
	/* 0x65a: lea    rax,[r12-0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551584ULL);
x86_l_65f:
	/* 0x65f: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_664:
	/* 0x664: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_669:
	/* 0x669: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_66e:
	/* 0x66e: jne    68f <generic_fexit_event+0x68f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_68f;
	}
x86_l_670:
	/* 0x670: cmp    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_675:
	/* 0x675: jne    68f <generic_fexit_event+0x68f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_68f;
	}
x86_l_677:
	/* 0x677: mov    BYTE PTR [rsp+0x64],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 429496729601ULL);
x86_l_67c:
	/* 0x67c: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_681:
	/* 0x681: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_686:
	/* 0x686: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_68a:
	/* 0x68a: jmp    34a9 <generic_fexit_event+0x34a9> */
	return 13481ULL;
x86_l_68f:
	/* 0x68f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_694:
	/* 0x694: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_69c:
	/* 0x69c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6a1:
	/* 0x6a1: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6a4:
	/* 0x6a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a6:
	/* 0x6a6: cmp    r13,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 136ULL);
x86_l_6ae:
	/* 0x6ae: je     7a4 <generic_fexit_event+0x7a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1956ULL;
	}
x86_l_6b4:
	/* 0x6b4: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6b8:
	/* 0x6b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6bd:
	/* 0x6bd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6c2:
	/* 0x6c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6c7:
	/* 0x6c7: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6ca:
	/* 0x6ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6cc:
	/* 0x6cc: cmp    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6d1:
	/* 0x6d1: je     7a4 <generic_fexit_event+0x7a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1956ULL;
	}
x86_l_6d7:
	/* 0x6d7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6dc:
	/* 0x6dc: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_6e4:
	/* 0x6e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6e9:
	/* 0x6e9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6ec:
	/* 0x6ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ee:
	/* 0x6ee: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_6f2:
	/* 0x6f2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6f7:
	/* 0x6f7: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6fc:
	/* 0x6fc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_701:
	/* 0x701: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_704:
	/* 0x704: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_706:
	/* 0x706: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_70b:
	/* 0x70b: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_710:
	/* 0x710: mov    esi,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_714:
	/* 0x714: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_717:
	/* 0x717: mov    edi,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_71b:
	/* 0x71b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_71d:
	/* 0x71d: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_71f:
	/* 0x71f: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_721:
	/* 0x721: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_724:
	/* 0x724: add    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_729:
	/* 0x729: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_72c:
	/* 0x72c: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_72e:
	/* 0x72e: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_732:
	/* 0x732: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_734:
	/* 0x734: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_737:
	/* 0x737: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_73a:
	/* 0x73a: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_73d:
	/* 0x73d: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_740:
	/* 0x740: mov    DWORD PTR [rsp+0x60],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
	return 1861ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1861ULL: goto x86_l_745;
	case 1864ULL: goto x86_l_748;
	case 1869ULL: goto x86_l_74d;
	case 1874ULL: goto x86_l_752;
	case 1880ULL: goto x86_l_758;
	case 1887ULL: goto x86_l_75f;
	case 1893ULL: goto x86_l_765;
	case 1895ULL: goto x86_l_767;
	case 1901ULL: goto x86_l_76d;
	case 1905ULL: goto x86_l_771;
	case 1909ULL: goto x86_l_775;
	case 1912ULL: goto x86_l_778;
	case 1916ULL: goto x86_l_77c;
	case 1919ULL: goto x86_l_77f;
	case 1924ULL: goto x86_l_784;
	case 1926ULL: goto x86_l_786;
	case 1931ULL: goto x86_l_78b;
	case 1939ULL: goto x86_l_793;
	case 1944ULL: goto x86_l_798;
	case 1949ULL: goto x86_l_79d;
	case 1954ULL: goto x86_l_7a2;
	case 1956ULL: goto x86_l_7a4;
	case 1961ULL: goto x86_l_7a9;
	case 1966ULL: goto x86_l_7ae;
	case 1971ULL: goto x86_l_7b3;
	case 1976ULL: goto x86_l_7b8;
	case 1978ULL: goto x86_l_7ba;
	case 1983ULL: goto x86_l_7bf;
	case 1988ULL: goto x86_l_7c4;
	case 1994ULL: goto x86_l_7ca;
	case 1998ULL: goto x86_l_7ce;
	case 2003ULL: goto x86_l_7d3;
	case 2008ULL: goto x86_l_7d8;
	case 2013ULL: goto x86_l_7dd;
	case 2016ULL: goto x86_l_7e0;
	case 2018ULL: goto x86_l_7e2;
	case 2023ULL: goto x86_l_7e7;
	case 2028ULL: goto x86_l_7ec;
	case 2033ULL: goto x86_l_7f1;
	case 2038ULL: goto x86_l_7f6;
	case 2043ULL: goto x86_l_7fb;
	case 2048ULL: goto x86_l_800;
	case 2050ULL: goto x86_l_802;
	case 2055ULL: goto x86_l_807;
	case 2061ULL: goto x86_l_80d;
	case 2066ULL: goto x86_l_812;
	case 2074ULL: goto x86_l_81a;
	case 2079ULL: goto x86_l_81f;
	case 2081ULL: goto x86_l_821;
	case 2089ULL: goto x86_l_829;
	case 2095ULL: goto x86_l_82f;
	case 2099ULL: goto x86_l_833;
	case 2104ULL: goto x86_l_838;
	case 2109ULL: goto x86_l_83d;
	case 2114ULL: goto x86_l_842;
	case 2117ULL: goto x86_l_845;
	case 2119ULL: goto x86_l_847;
	case 2124ULL: goto x86_l_84c;
	case 2130ULL: goto x86_l_852;
	case 2135ULL: goto x86_l_857;
	case 2143ULL: goto x86_l_85f;
	case 2148ULL: goto x86_l_864;
	case 2151ULL: goto x86_l_867;
	case 2153ULL: goto x86_l_869;
	case 2157ULL: goto x86_l_86d;
	case 2162ULL: goto x86_l_872;
	case 2167ULL: goto x86_l_877;
	case 2172ULL: goto x86_l_87c;
	case 2175ULL: goto x86_l_87f;
	case 2177ULL: goto x86_l_881;
	case 2182ULL: goto x86_l_886;
	case 2187ULL: goto x86_l_88b;
	case 2191ULL: goto x86_l_88f;
	case 2194ULL: goto x86_l_892;
	case 2198ULL: goto x86_l_896;
	case 2200ULL: goto x86_l_898;
	case 2202ULL: goto x86_l_89a;
	case 2204ULL: goto x86_l_89c;
	case 2207ULL: goto x86_l_89f;
	case 2212ULL: goto x86_l_8a4;
	case 2215ULL: goto x86_l_8a7;
	case 2217ULL: goto x86_l_8a9;
	case 2221ULL: goto x86_l_8ad;
	case 2223ULL: goto x86_l_8af;
	case 2226ULL: goto x86_l_8b2;
	case 2229ULL: goto x86_l_8b5;
	case 2232ULL: goto x86_l_8b8;
	case 2235ULL: goto x86_l_8bb;
	case 2240ULL: goto x86_l_8c0;
	case 2243ULL: goto x86_l_8c3;
	case 2248ULL: goto x86_l_8c8;
	case 2253ULL: goto x86_l_8cd;
	case 2259ULL: goto x86_l_8d3;
	case 2266ULL: goto x86_l_8da;
	case 2272ULL: goto x86_l_8e0;
	case 2274ULL: goto x86_l_8e2;
	case 2280ULL: goto x86_l_8e8;
	case 2284ULL: goto x86_l_8ec;
	case 2288ULL: goto x86_l_8f0;
	case 2291ULL: goto x86_l_8f3;
	case 2295ULL: goto x86_l_8f7;
	case 2298ULL: goto x86_l_8fa;
	case 2303ULL: goto x86_l_8ff;
	case 2305ULL: goto x86_l_901;
	case 2310ULL: goto x86_l_906;
	case 2318ULL: goto x86_l_90e;
	case 2323ULL: goto x86_l_913;
	case 2328ULL: goto x86_l_918;
	case 2333ULL: goto x86_l_91d;
	case 2338ULL: goto x86_l_922;
	case 2340ULL: goto x86_l_924;
	case 2345ULL: goto x86_l_929;
	case 2353ULL: goto x86_l_931;
	case 2362ULL: goto x86_l_93a;
	case 2364ULL: goto x86_l_93c;
	case 2367ULL: goto x86_l_93f;
	case 2372ULL: goto x86_l_944;
	case 2380ULL: goto x86_l_94c;
	case 2384ULL: goto x86_l_950;
	case 2390ULL: goto x86_l_956;
	case 2395ULL: goto x86_l_95b;
	case 2400ULL: goto x86_l_960;
	case 2405ULL: goto x86_l_965;
	case 2407ULL: goto x86_l_967;
	case 2412ULL: goto x86_l_96c;
	case 2414ULL: goto x86_l_96e;
	case 2420ULL: goto x86_l_974;
	case 2425ULL: goto x86_l_979;
	case 2430ULL: goto x86_l_97e;
	case 2433ULL: goto x86_l_981;
	case 2436ULL: goto x86_l_984;
	case 2440ULL: goto x86_l_988;
	case 2443ULL: goto x86_l_98b;
	case 2447ULL: goto x86_l_98f;
	case 2452ULL: goto x86_l_994;
	case 2459ULL: goto x86_l_99b;
	case 2465ULL: goto x86_l_9a1;
	case 2470ULL: goto x86_l_9a6;
	case 2473ULL: goto x86_l_9a9;
	case 2478ULL: goto x86_l_9ae;
	case 2482ULL: goto x86_l_9b2;
	case 2487ULL: goto x86_l_9b7;
	case 2492ULL: goto x86_l_9bc;
	case 2494ULL: goto x86_l_9be;
	case 2496ULL: goto x86_l_9c0;
	case 2501ULL: goto x86_l_9c5;
	case 2503ULL: goto x86_l_9c7;
	case 2509ULL: goto x86_l_9cd;
	case 2512ULL: goto x86_l_9d0;
	case 2515ULL: goto x86_l_9d3;
	case 2520ULL: goto x86_l_9d8;
	case 2523ULL: goto x86_l_9db;
	case 2529ULL: goto x86_l_9e1;
	case 2532ULL: goto x86_l_9e4;
	case 2535ULL: goto x86_l_9e7;
	case 2541ULL: goto x86_l_9ed;
	case 2546ULL: goto x86_l_9f2;
	case 2549ULL: goto x86_l_9f5;
	case 2555ULL: goto x86_l_9fb;
	case 2558ULL: goto x86_l_9fe;
	case 2561ULL: goto x86_l_a01;
	case 2565ULL: goto x86_l_a05;
	case 2571ULL: goto x86_l_a0b;
	case 2574ULL: goto x86_l_a0e;
	case 2577ULL: goto x86_l_a11;
	case 2583ULL: goto x86_l_a17;
	case 2586ULL: goto x86_l_a1a;
	case 2592ULL: goto x86_l_a20;
	case 2595ULL: goto x86_l_a23;
	case 2600ULL: goto x86_l_a28;
	case 2607ULL: goto x86_l_a2f;
	case 2614ULL: goto x86_l_a36;
	case 2618ULL: goto x86_l_a3a;
	case 2623ULL: goto x86_l_a3f;
	case 2628ULL: goto x86_l_a44;
	case 2630ULL: goto x86_l_a46;
	case 2634ULL: goto x86_l_a4a;
	case 2641ULL: goto x86_l_a51;
	case 2645ULL: goto x86_l_a55;
	case 2650ULL: goto x86_l_a5a;
	case 2655ULL: goto x86_l_a5f;
	case 2657ULL: goto x86_l_a61;
	case 2661ULL: goto x86_l_a65;
	case 2668ULL: goto x86_l_a6c;
	case 2675ULL: goto x86_l_a73;
	case 2680ULL: goto x86_l_a78;
	case 2685ULL: goto x86_l_a7d;
	case 2687ULL: goto x86_l_a7f;
	case 2691ULL: goto x86_l_a83;
	case 2698ULL: goto x86_l_a8a;
	case 2705ULL: goto x86_l_a91;
	case 2710ULL: goto x86_l_a96;
	case 2715ULL: goto x86_l_a9b;
	case 2717ULL: goto x86_l_a9d;
	case 2721ULL: goto x86_l_aa1;
	case 2728ULL: goto x86_l_aa8;
	case 2735ULL: goto x86_l_aaf;
	case 2740ULL: goto x86_l_ab4;
	case 2745ULL: goto x86_l_ab9;
	case 2747ULL: goto x86_l_abb;
	case 2751ULL: goto x86_l_abf;
	case 2758ULL: goto x86_l_ac6;
	case 2765ULL: goto x86_l_acd;
	case 2770ULL: goto x86_l_ad2;
	case 2775ULL: goto x86_l_ad7;
	case 2777ULL: goto x86_l_ad9;
	case 2781ULL: goto x86_l_add;
	case 2788ULL: goto x86_l_ae4;
	case 2793ULL: goto x86_l_ae9;
	case 2800ULL: goto x86_l_af0;
	case 2808ULL: goto x86_l_af8;
	case 2816ULL: goto x86_l_b00;
	case 2824ULL: goto x86_l_b08;
	case 2831ULL: goto x86_l_b0f;
	case 2834ULL: goto x86_l_b12;
	case 2840ULL: goto x86_l_b18;
	case 2843ULL: goto x86_l_b1b;
	case 2849ULL: goto x86_l_b21;
	case 2853ULL: goto x86_l_b25;
	case 2858ULL: goto x86_l_b2a;
	case 2863ULL: goto x86_l_b2f;
	case 2868ULL: goto x86_l_b34;
	case 2870ULL: goto x86_l_b36;
	case 2875ULL: goto x86_l_b3b;
	case 2878ULL: goto x86_l_b3e;
	case 2883ULL: goto x86_l_b43;
	case 2886ULL: goto x86_l_b46;
	case 2891ULL: goto x86_l_b4b;
	case 2894ULL: goto x86_l_b4e;
	case 2900ULL: goto x86_l_b54;
	case 2903ULL: goto x86_l_b57;
	case 2906ULL: goto x86_l_b5a;
	case 2912ULL: goto x86_l_b60;
	case 2917ULL: goto x86_l_b65;
	case 2922ULL: goto x86_l_b6a;
	case 2927ULL: goto x86_l_b6f;
	case 2932ULL: goto x86_l_b74;
	case 2937ULL: goto x86_l_b79;
	case 2942ULL: goto x86_l_b7e;
	case 2947ULL: goto x86_l_b83;
	case 2952ULL: goto x86_l_b88;
	case 2957ULL: goto x86_l_b8d;
	case 2962ULL: goto x86_l_b92;
	case 2964ULL: goto x86_l_b94;
	case 2969ULL: goto x86_l_b99;
	case 2974ULL: goto x86_l_b9e;
	case 2980ULL: goto x86_l_ba4;
	case 2984ULL: goto x86_l_ba8;
	case 2989ULL: goto x86_l_bad;
	case 2994ULL: goto x86_l_bb2;
	case 2999ULL: goto x86_l_bb7;
	case 3002ULL: goto x86_l_bba;
	case 3004ULL: goto x86_l_bbc;
	case 3009ULL: goto x86_l_bc1;
	case 3014ULL: goto x86_l_bc6;
	case 3019ULL: goto x86_l_bcb;
	case 3024ULL: goto x86_l_bd0;
	case 3029ULL: goto x86_l_bd5;
	case 3034ULL: goto x86_l_bda;
	case 3036ULL: goto x86_l_bdc;
	case 3041ULL: goto x86_l_be1;
	case 3047ULL: goto x86_l_be7;
	case 3052ULL: goto x86_l_bec;
	case 3060ULL: goto x86_l_bf4;
	case 3065ULL: goto x86_l_bf9;
	case 3067ULL: goto x86_l_bfb;
	case 3075ULL: goto x86_l_c03;
	case 3081ULL: goto x86_l_c09;
	case 3085ULL: goto x86_l_c0d;
	case 3090ULL: goto x86_l_c12;
	case 3095ULL: goto x86_l_c17;
	case 3100ULL: goto x86_l_c1c;
	case 3103ULL: goto x86_l_c1f;
	case 3105ULL: goto x86_l_c21;
	case 3110ULL: goto x86_l_c26;
	case 3116ULL: goto x86_l_c2c;
	case 3121ULL: goto x86_l_c31;
	case 3129ULL: goto x86_l_c39;
	case 3134ULL: goto x86_l_c3e;
	case 3137ULL: goto x86_l_c41;
	case 3139ULL: goto x86_l_c43;
	case 3143ULL: goto x86_l_c47;
	case 3148ULL: goto x86_l_c4c;
	case 3153ULL: goto x86_l_c51;
	case 3158ULL: goto x86_l_c56;
	case 3161ULL: goto x86_l_c59;
	case 3163ULL: goto x86_l_c5b;
	case 3168ULL: goto x86_l_c60;
	case 3173ULL: goto x86_l_c65;
	case 3177ULL: goto x86_l_c69;
	case 3180ULL: goto x86_l_c6c;
	case 3184ULL: goto x86_l_c70;
	case 3186ULL: goto x86_l_c72;
	case 3188ULL: goto x86_l_c74;
	case 3190ULL: goto x86_l_c76;
	case 3193ULL: goto x86_l_c79;
	case 3198ULL: goto x86_l_c7e;
	case 3201ULL: goto x86_l_c81;
	case 3203ULL: goto x86_l_c83;
	case 3207ULL: goto x86_l_c87;
	case 3209ULL: goto x86_l_c89;
	case 3212ULL: goto x86_l_c8c;
	case 3215ULL: goto x86_l_c8f;
	case 3218ULL: goto x86_l_c92;
	case 3221ULL: goto x86_l_c95;
	case 3226ULL: goto x86_l_c9a;
	case 3229ULL: goto x86_l_c9d;
	case 3234ULL: goto x86_l_ca2;
	case 3239ULL: goto x86_l_ca7;
	case 3245ULL: goto x86_l_cad;
	case 3252ULL: goto x86_l_cb4;
	case 3258ULL: goto x86_l_cba;
	case 3260ULL: goto x86_l_cbc;
	case 3266ULL: goto x86_l_cc2;
	case 3270ULL: goto x86_l_cc6;
	case 3274ULL: goto x86_l_cca;
	case 3277ULL: goto x86_l_ccd;
	case 3281ULL: goto x86_l_cd1;
	case 3284ULL: goto x86_l_cd4;
	case 3289ULL: goto x86_l_cd9;
	case 3291ULL: goto x86_l_cdb;
	case 3296ULL: goto x86_l_ce0;
	case 3304ULL: goto x86_l_ce8;
	case 3309ULL: goto x86_l_ced;
	case 3314ULL: goto x86_l_cf2;
	case 3319ULL: goto x86_l_cf7;
	case 3324ULL: goto x86_l_cfc;
	case 3327ULL: goto x86_l_cff;
	case 3331ULL: goto x86_l_d03;
	case 3337ULL: goto x86_l_d09;
	case 3340ULL: goto x86_l_d0c;
	case 3342ULL: goto x86_l_d0e;
	case 3345ULL: goto x86_l_d11;
	case 3351ULL: goto x86_l_d17;
	case 3356ULL: goto x86_l_d1c;
	case 3361ULL: goto x86_l_d21;
	case 3366ULL: goto x86_l_d26;
	case 3371ULL: goto x86_l_d2b;
	case 3373ULL: goto x86_l_d2d;
	case 3377ULL: goto x86_l_d31;
	case 3382ULL: goto x86_l_d36;
	case 3387ULL: goto x86_l_d3b;
	case 3390ULL: goto x86_l_d3e;
	case 3395ULL: goto x86_l_d43;
	case 3401ULL: goto x86_l_d49;
	case 3404ULL: goto x86_l_d4c;
	case 3407ULL: goto x86_l_d4f;
	case 3413ULL: goto x86_l_d55;
	case 3418ULL: goto x86_l_d5a;
	case 3423ULL: goto x86_l_d5f;
	case 3426ULL: goto x86_l_d62;
	case 3428ULL: goto x86_l_d64;
	case 3432ULL: goto x86_l_d68;
	case 3437ULL: goto x86_l_d6d;
	case 3442ULL: goto x86_l_d72;
	case 3447ULL: goto x86_l_d77;
	case 3452ULL: goto x86_l_d7c;
	case 3457ULL: goto x86_l_d81;
	case 3462ULL: goto x86_l_d86;
	case 3464ULL: goto x86_l_d88;
	case 3467ULL: goto x86_l_d8b;
	case 3473ULL: goto x86_l_d91;
	case 3476ULL: goto x86_l_d94;
	case 3482ULL: goto x86_l_d9a;
	case 3487ULL: goto x86_l_d9f;
	case 3492ULL: goto x86_l_da4;
	case 3497ULL: goto x86_l_da9;
	case 3502ULL: goto x86_l_dae;
	case 3507ULL: goto x86_l_db3;
	case 3512ULL: goto x86_l_db8;
	case 3514ULL: goto x86_l_dba;
	case 3518ULL: goto x86_l_dbe;
	case 3523ULL: goto x86_l_dc3;
	case 3526ULL: goto x86_l_dc6;
	case 3532ULL: goto x86_l_dcc;
	case 3535ULL: goto x86_l_dcf;
	case 3539ULL: goto x86_l_dd3;
	case 3545ULL: goto x86_l_dd9;
	case 3548ULL: goto x86_l_ddc;
	case 3553ULL: goto x86_l_de1;
	case 3558ULL: goto x86_l_de6;
	case 3566ULL: goto x86_l_dee;
	case 3574ULL: goto x86_l_df6;
	case 3582ULL: goto x86_l_dfe;
	default: return 0xffffffffffffffffULL;
	}
x86_l_745:
	/* 0x745: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_748:
	/* 0x748: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_74d:
	/* 0x74d: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_752:
	/* 0x752: jb     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8190ULL;
	}
x86_l_758:
	/* 0x758: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_75f:
	/* 0x75f: ja     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8190ULL;
	}
x86_l_765:
	/* 0x765: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_767:
	/* 0x767: jbe    1fe9 <generic_fexit_event+0x1fe9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 8169ULL;
	}
x86_l_76d:
	/* 0x76d: lea    rbx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_771:
	/* 0x771: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_775:
	/* 0x775: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_778:
	/* 0x778: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_77c:
	/* 0x77c: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_77f:
	/* 0x77f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_784:
	/* 0x784: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_786:
	/* 0x786: mov    QWORD PTR [rsp+0x58],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_78b:
	/* 0x78b: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_793:
	/* 0x793: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_798:
	/* 0x798: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_79d:
	/* 0x79d: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7a2:
	/* 0x7a2: jmp    7fb <generic_fexit_event+0x7fb> */
	goto x86_l_7fb;
x86_l_7a4:
	/* 0x7a4: lea    rdx,[r12-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_7a9:
	/* 0x7a9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7ae:
	/* 0x7ae: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7b3:
	/* 0x7b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7b8:
	/* 0x7b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ba:
	/* 0x7ba: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7bf:
	/* 0x7bf: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_7c4:
	/* 0x7c4: je     3496 <generic_fexit_event+0x3496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13462ULL;
	}
x86_l_7ca:
	/* 0x7ca: add    r12,0xfffffffffffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551608ULL);
x86_l_7ce:
	/* 0x7ce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7d3:
	/* 0x7d3: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7d8:
	/* 0x7d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7dd:
	/* 0x7dd: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_7e0:
	/* 0x7e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e2:
	/* 0x7e2: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7e7:
	/* 0x7e7: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7ec:
	/* 0x7ec: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7f1:
	/* 0x7f1: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7f6:
	/* 0x7f6: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7fb:
	/* 0x7fb: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_800:
	/* 0x800: jne    80d <generic_fexit_event+0x80d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_80d;
	}
x86_l_802:
	/* 0x802: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_807:
	/* 0x807: je     677 <generic_fexit_event+0x677> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1655ULL;
	}
x86_l_80d:
	/* 0x80d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_812:
	/* 0x812: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_81a:
	/* 0x81a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_81f:
	/* 0x81f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_821:
	/* 0x821: cmp    r13,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 136ULL);
x86_l_829:
	/* 0x829: je     b7e <generic_fexit_event+0xb7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b7e;
	}
x86_l_82f:
	/* 0x82f: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_833:
	/* 0x833: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_838:
	/* 0x838: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_83d:
	/* 0x83d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_842:
	/* 0x842: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_845:
	/* 0x845: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_847:
	/* 0x847: cmp    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_84c:
	/* 0x84c: je     b7e <generic_fexit_event+0xb7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b7e;
	}
x86_l_852:
	/* 0x852: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_857:
	/* 0x857: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_85f:
	/* 0x85f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_864:
	/* 0x864: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_867:
	/* 0x867: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_869:
	/* 0x869: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_86d:
	/* 0x86d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_872:
	/* 0x872: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_877:
	/* 0x877: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_87c:
	/* 0x87c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_87f:
	/* 0x87f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_881:
	/* 0x881: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_886:
	/* 0x886: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_88b:
	/* 0x88b: mov    esi,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_88f:
	/* 0x88f: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_892:
	/* 0x892: mov    edi,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_896:
	/* 0x896: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_898:
	/* 0x898: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_89a:
	/* 0x89a: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_89c:
	/* 0x89c: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_89f:
	/* 0x89f: add    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_8a4:
	/* 0x8a4: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8a7:
	/* 0x8a7: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_8a9:
	/* 0x8a9: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_8ad:
	/* 0x8ad: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_8af:
	/* 0x8af: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_8b2:
	/* 0x8b2: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_8b5:
	/* 0x8b5: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_8b8:
	/* 0x8b8: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_8bb:
	/* 0x8bb: mov    DWORD PTR [rsp+0x60],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8c0:
	/* 0x8c0: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_8c3:
	/* 0x8c3: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8c8:
	/* 0x8c8: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8cd:
	/* 0x8cd: jb     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8190ULL;
	}
x86_l_8d3:
	/* 0x8d3: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_8da:
	/* 0x8da: ja     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8190ULL;
	}
x86_l_8e0:
	/* 0x8e0: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_8e2:
	/* 0x8e2: jbe    1fe9 <generic_fexit_event+0x1fe9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 8169ULL;
	}
x86_l_8e8:
	/* 0x8e8: lea    rbx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_8ec:
	/* 0x8ec: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_8f0:
	/* 0x8f0: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_8f3:
	/* 0x8f3: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_8f7:
	/* 0x8f7: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_8fa:
	/* 0x8fa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8ff:
	/* 0x8ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_901:
	/* 0x901: mov    QWORD PTR [rsp+0x58],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_906:
	/* 0x906: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_90e:
	/* 0x90e: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_913:
	/* 0x913: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_918:
	/* 0x918: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_91d:
	/* 0x91d: jmp    bd5 <generic_fexit_event+0xbd5> */
	goto x86_l_bd5;
x86_l_922:
	/* 0x922: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_924:
	/* 0x924: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_929:
	/* 0x929: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_931:
	/* 0x931: cmp    QWORD PTR [rsp+0xa0],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767361ULL);
x86_l_93a:
	/* 0x93a: jne    944 <generic_fexit_event+0x944> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_944;
	}
x86_l_93c:
	/* 0x93c: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_93f:
	/* 0x93f: jmp    2b1 <generic_fexit_event+0x2b1> */
	return 689ULL;
x86_l_944:
	/* 0x944: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_94c:
	/* 0x94c: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_950:
	/* 0x950: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_956:
	/* 0x956: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_95b:
	/* 0x95b: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_960:
	/* 0x960: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_965:
	/* 0x965: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_967:
	/* 0x967: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_96c:
	/* 0x96c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_96e:
	/* 0x96e: js     1717 <generic_fexit_event+0x1717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5911ULL;
	}
x86_l_974:
	/* 0x974: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_979:
	/* 0x979: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_97e:
	/* 0x97e: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_981:
	/* 0x981: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_984:
	/* 0x984: cmovb  r12,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_64, X86_CC_B);
x86_l_988:
	/* 0x988: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_98b:
	/* 0x98b: cmovne rbp,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_98f:
	/* 0x98f: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_994:
	/* 0x994: cmp    rbp,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4094ULL);
x86_l_99b:
	/* 0x99b: ja     1717 <generic_fexit_event+0x1717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5911ULL;
	}
x86_l_9a1:
	/* 0x9a1: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9a6:
	/* 0x9a6: add    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9a9:
	/* 0x9a9: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9ae:
	/* 0x9ae: lea    rdi,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_9b2:
	/* 0x9b2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9b7:
	/* 0x9b7: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9bc:
	/* 0x9bc: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_9be:
	/* 0x9be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c0:
	/* 0x9c0: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_9c5:
	/* 0x9c5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9c7:
	/* 0x9c7: js     1717 <generic_fexit_event+0x1717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5911ULL;
	}
x86_l_9cd:
	/* 0x9cd: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_9d0:
	/* 0x9d0: add    rbx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9d3:
	/* 0x9d3: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9d8:
	/* 0x9d8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9db:
	/* 0x9db: je     1652 <generic_fexit_event+0x1652> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5714ULL;
	}
x86_l_9e1:
	/* 0x9e1: sub    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_9e4:
	/* 0x9e4: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_9e7:
	/* 0x9e7: jne    1655 <generic_fexit_event+0x1655> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5717ULL;
	}
x86_l_9ed:
	/* 0x9ed: jmp    173b <generic_fexit_event+0x173b> */
	return 5947ULL;
x86_l_9f2:
	/* 0x9f2: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_9f5:
	/* 0x9f5: jle    cfc <generic_fexit_event+0xcfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_cfc;
	}
x86_l_9fb:
	/* 0x9fb: lea    eax,[rbx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_9fe:
	/* 0x9fe: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a01:
	/* 0xa01: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a05:
	/* 0xa05: jb     d17 <generic_fexit_event+0xd17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d17;
	}
x86_l_a0b:
	/* 0xa0b: lea    eax,[rbx-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_a0e:
	/* 0xa0e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a11:
	/* 0xa11: jb     d6d <generic_fexit_event+0xd6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d6d;
	}
x86_l_a17:
	/* 0xa17: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_a1a:
	/* 0xa1a: jne    356a <generic_fexit_event+0x356a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13674ULL;
	}
x86_l_a20:
	/* 0xa20: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_a23:
	/* 0xa23: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a28:
	/* 0xa28: mov    QWORD PTR [rcx+0xc4],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_a2f:
	/* 0xa2f: lea    rdi,[rcx+0xc2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_a36:
	/* 0xa36: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a3a:
	/* 0xa3a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a3f:
	/* 0xa3f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_a44:
	/* 0xa44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a46:
	/* 0xa46: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a4a:
	/* 0xa4a: lea    rdi,[rax+0xd6] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_a51:
	/* 0xa51: lea    rdx,[rbp+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_a55:
	/* 0xa55: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a5a:
	/* 0xa5a: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_a5f:
	/* 0xa5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a61:
	/* 0xa61: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a65:
	/* 0xa65: lea    rdi,[rax+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_a6c:
	/* 0xa6c: lea    rdx,[rbp+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_a73:
	/* 0xa73: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a78:
	/* 0xa78: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_a7d:
	/* 0xa7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a7f:
	/* 0xa7f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a83:
	/* 0xa83: lea    rdi,[rax+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_a8a:
	/* 0xa8a: lea    rdx,[rbp+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_a91:
	/* 0xa91: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a96:
	/* 0xa96: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_a9b:
	/* 0xa9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a9d:
	/* 0xa9d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aa1:
	/* 0xaa1: lea    rdi,[rax+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_aa8:
	/* 0xaa8: lea    rdx,[rbp+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_aaf:
	/* 0xaaf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ab4:
	/* 0xab4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ab9:
	/* 0xab9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_abb:
	/* 0xabb: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_abf:
	/* 0xabf: lea    rdi,[rax+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_ac6:
	/* 0xac6: lea    rdx,[rbp+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_acd:
	/* 0xacd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ad2:
	/* 0xad2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ad7:
	/* 0xad7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad9:
	/* 0xad9: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_add:
	/* 0xadd: lea    r12,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_ae4:
	/* 0xae4: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_ae9:
	/* 0xae9: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af0:
	/* 0xaf0: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_af8:
	/* 0xaf8: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_b00:
	/* 0xb00: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_b08:
	/* 0xb08: movzx  ecx,WORD PTR [rax+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_b0f:
	/* 0xb0f: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_b12:
	/* 0xb12: je     1ce1 <generic_fexit_event+0x1ce1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7393ULL;
	}
x86_l_b18:
	/* 0xb18: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b1b:
	/* 0xb1b: jne    1d08 <generic_fexit_event+0x1d08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7432ULL;
	}
x86_l_b21:
	/* 0xb21: lea    rdx,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b25:
	/* 0xb25: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b2a:
	/* 0xb2a: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b2f:
	/* 0xb2f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_b34:
	/* 0xb34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b36:
	/* 0xb36: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b3b:
	/* 0xb3b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_b3e:
	/* 0xb3e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_b43:
	/* 0xb43: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_b46:
	/* 0xb46: jmp    1d02 <generic_fexit_event+0x1d02> */
	return 7426ULL;
x86_l_b4b:
	/* 0xb4b: cmp    ebx,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 38ULL);
x86_l_b4e:
	/* 0xb4e: jg     dc3 <generic_fexit_event+0xdc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_dc3;
	}
x86_l_b54:
	/* 0xb54: lea    eax,[rbx-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_b57:
	/* 0xb57: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b5a:
	/* 0xb5a: jae    ea0 <generic_fexit_event+0xea0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3744ULL;
	}
x86_l_b60:
	/* 0xb60: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_b65:
	/* 0xb65: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b6a:
	/* 0xb6a: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b6f:
	/* 0xb6f: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b74:
	/* 0xb74: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_b79:
	/* 0xb79: jmp    db8 <generic_fexit_event+0xdb8> */
	goto x86_l_db8;
x86_l_b7e:
	/* 0xb7e: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b83:
	/* 0xb83: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b88:
	/* 0xb88: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b8d:
	/* 0xb8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b92:
	/* 0xb92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b94:
	/* 0xb94: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b99:
	/* 0xb99: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_b9e:
	/* 0xb9e: je     3496 <generic_fexit_event+0x3496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13462ULL;
	}
x86_l_ba4:
	/* 0xba4: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_ba8:
	/* 0xba8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bad:
	/* 0xbad: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_bb2:
	/* 0xbb2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bb7:
	/* 0xbb7: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_bba:
	/* 0xbba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bbc:
	/* 0xbbc: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bc1:
	/* 0xbc1: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_bc6:
	/* 0xbc6: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bcb:
	/* 0xbcb: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_bd0:
	/* 0xbd0: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_bd5:
	/* 0xbd5: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_bda:
	/* 0xbda: jne    be7 <generic_fexit_event+0xbe7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_be7;
	}
x86_l_bdc:
	/* 0xbdc: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_be1:
	/* 0xbe1: je     677 <generic_fexit_event+0x677> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1655ULL;
	}
x86_l_be7:
	/* 0xbe7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bec:
	/* 0xbec: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_bf4:
	/* 0xbf4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bf9:
	/* 0xbf9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bfb:
	/* 0xbfb: cmp    r13,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 136ULL);
x86_l_c03:
	/* 0xc03: je     10f1 <generic_fexit_event+0x10f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4337ULL;
	}
x86_l_c09:
	/* 0xc09: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c0d:
	/* 0xc0d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c12:
	/* 0xc12: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c17:
	/* 0xc17: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c1c:
	/* 0xc1c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_c1f:
	/* 0xc1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c21:
	/* 0xc21: cmp    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c26:
	/* 0xc26: je     10f1 <generic_fexit_event+0x10f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4337ULL;
	}
x86_l_c2c:
	/* 0xc2c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c31:
	/* 0xc31: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_c39:
	/* 0xc39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c3e:
	/* 0xc3e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_c41:
	/* 0xc41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c43:
	/* 0xc43: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_c47:
	/* 0xc47: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c4c:
	/* 0xc4c: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c51:
	/* 0xc51: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_c56:
	/* 0xc56: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_c59:
	/* 0xc59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c5b:
	/* 0xc5b: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c60:
	/* 0xc60: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c65:
	/* 0xc65: mov    esi,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_c69:
	/* 0xc69: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_c6c:
	/* 0xc6c: mov    edi,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c70:
	/* 0xc70: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c72:
	/* 0xc72: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_c74:
	/* 0xc74: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_c76:
	/* 0xc76: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_c79:
	/* 0xc79: add    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_c7e:
	/* 0xc7e: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c81:
	/* 0xc81: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_c83:
	/* 0xc83: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_c87:
	/* 0xc87: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_c89:
	/* 0xc89: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_c8c:
	/* 0xc8c: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c8f:
	/* 0xc8f: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_c92:
	/* 0xc92: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_c95:
	/* 0xc95: mov    DWORD PTR [rsp+0x60],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c9a:
	/* 0xc9a: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_c9d:
	/* 0xc9d: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ca2:
	/* 0xca2: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ca7:
	/* 0xca7: jb     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8190ULL;
	}
x86_l_cad:
	/* 0xcad: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_cb4:
	/* 0xcb4: ja     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8190ULL;
	}
x86_l_cba:
	/* 0xcba: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_cbc:
	/* 0xcbc: jbe    1fdf <generic_fexit_event+0x1fdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 8159ULL;
	}
x86_l_cc2:
	/* 0xcc2: lea    rbx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_cc6:
	/* 0xcc6: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_cca:
	/* 0xcca: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ccd:
	/* 0xccd: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_cd1:
	/* 0xcd1: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_cd4:
	/* 0xcd4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cd9:
	/* 0xcd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cdb:
	/* 0xcdb: mov    QWORD PTR [rsp+0x58],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_ce0:
	/* 0xce0: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_ce8:
	/* 0xce8: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ced:
	/* 0xced: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_cf2:
	/* 0xcf2: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_cf7:
	/* 0xcf7: jmp    1148 <generic_fexit_event+0x1148> */
	return 4424ULL;
x86_l_cfc:
	/* 0xcfc: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_cff:
	/* 0xcff: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d03:
	/* 0xd03: jg     d88 <generic_fexit_event+0xd88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d88;
	}
x86_l_d09:
	/* 0xd09: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_d0c:
	/* 0xd0c: je     d6d <generic_fexit_event+0xd6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6d;
	}
x86_l_d0e:
	/* 0xd0e: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_d11:
	/* 0xd11: jne    356a <generic_fexit_event+0x356a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13674ULL;
	}
x86_l_d17:
	/* 0xd17: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d1c:
	/* 0xd1c: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d21:
	/* 0xd21: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d26:
	/* 0xd26: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d2b:
	/* 0xd2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d2d:
	/* 0xd2d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d31:
	/* 0xd31: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_d36:
	/* 0xd36: jmp    356a <generic_fexit_event+0x356a> */
	return 13674ULL;
x86_l_d3b:
	/* 0xd3b: cmp    ebx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 32ULL);
x86_l_d3e:
	/* 0xd3e: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d43:
	/* 0xd43: jle    1037 <generic_fexit_event+0x1037> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4151ULL;
	}
x86_l_d49:
	/* 0xd49: lea    eax,[rbx-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_d4c:
	/* 0xd4c: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d4f:
	/* 0xd4f: jae    eea <generic_fexit_event+0xeea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3818ULL;
	}
x86_l_d55:
	/* 0xd55: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d5a:
	/* 0xd5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d5f:
	/* 0xd5f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d62:
	/* 0xd62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d64:
	/* 0xd64: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d68:
	/* 0xd68: jmp    e96 <generic_fexit_event+0xe96> */
	return 3734ULL;
x86_l_d6d:
	/* 0xd6d: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_d72:
	/* 0xd72: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d77:
	/* 0xd77: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d7c:
	/* 0xd7c: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d81:
	/* 0xd81: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d86:
	/* 0xd86: jmp    db8 <generic_fexit_event+0xdb8> */
	goto x86_l_db8;
x86_l_d88:
	/* 0xd88: cmp    ebx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_d8b:
	/* 0xd8b: je     134f <generic_fexit_event+0x134f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4943ULL;
	}
x86_l_d91:
	/* 0xd91: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_d94:
	/* 0xd94: je     15e6 <generic_fexit_event+0x15e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5606ULL;
	}
x86_l_d9a:
	/* 0xd9a: jmp    356a <generic_fexit_event+0x356a> */
	return 13674ULL;
x86_l_d9f:
	/* 0xd9f: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_da4:
	/* 0xda4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_da9:
	/* 0xda9: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dae:
	/* 0xdae: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_db3:
	/* 0xdb3: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_db8:
	/* 0xdb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dba:
	/* 0xdba: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dbe:
	/* 0xdbe: jmp    356a <generic_fexit_event+0x356a> */
	return 13674ULL;
x86_l_dc3:
	/* 0xdc3: cmp    ebx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 39ULL);
x86_l_dc6:
	/* 0xdc6: je     160e <generic_fexit_event+0x160e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5646ULL;
	}
x86_l_dcc:
	/* 0xdcc: cmp    ebx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 40ULL);
x86_l_dcf:
	/* 0xdcf: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dd3:
	/* 0xdd3: jne    356a <generic_fexit_event+0x356a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13674ULL;
	}
x86_l_dd9:
	/* 0xdd9: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_ddc:
	/* 0xddc: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_de1:
	/* 0xde1: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_de6:
	/* 0xde6: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_dee:
	/* 0xdee: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_df6:
	/* 0xdf6: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dfe:
	/* 0xdfe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 3587ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3587ULL: goto x86_l_e03;
	case 3590ULL: goto x86_l_e06;
	case 3595ULL: goto x86_l_e0b;
	case 3598ULL: goto x86_l_e0e;
	case 3600ULL: goto x86_l_e10;
	case 3604ULL: goto x86_l_e14;
	case 3607ULL: goto x86_l_e17;
	case 3613ULL: goto x86_l_e1d;
	case 3617ULL: goto x86_l_e21;
	case 3620ULL: goto x86_l_e24;
	case 3626ULL: goto x86_l_e2a;
	case 3629ULL: goto x86_l_e2d;
	case 3635ULL: goto x86_l_e33;
	case 3640ULL: goto x86_l_e38;
	case 3645ULL: goto x86_l_e3d;
	case 3650ULL: goto x86_l_e42;
	case 3655ULL: goto x86_l_e47;
	case 3657ULL: goto x86_l_e49;
	case 3661ULL: goto x86_l_e4d;
	case 3665ULL: goto x86_l_e51;
	case 3672ULL: goto x86_l_e58;
	case 3679ULL: goto x86_l_e5f;
	case 3683ULL: goto x86_l_e63;
	case 3688ULL: goto x86_l_e68;
	case 3693ULL: goto x86_l_e6d;
	case 3696ULL: goto x86_l_e70;
	case 3702ULL: goto x86_l_e76;
	case 3705ULL: goto x86_l_e79;
	case 3708ULL: goto x86_l_e7c;
	case 3714ULL: goto x86_l_e82;
	case 3717ULL: goto x86_l_e85;
	case 3723ULL: goto x86_l_e8b;
	case 3734ULL: goto x86_l_e96;
	case 3739ULL: goto x86_l_e9b;
	case 3744ULL: goto x86_l_ea0;
	case 3747ULL: goto x86_l_ea3;
	case 3751ULL: goto x86_l_ea7;
	case 3757ULL: goto x86_l_ead;
	case 3762ULL: goto x86_l_eb2;
	case 3765ULL: goto x86_l_eb5;
	case 3773ULL: goto x86_l_ebd;
	case 3776ULL: goto x86_l_ec0;
	case 3782ULL: goto x86_l_ec6;
	case 3785ULL: goto x86_l_ec9;
	case 3792ULL: goto x86_l_ed0;
	case 3794ULL: goto x86_l_ed2;
	case 3799ULL: goto x86_l_ed7;
	case 3801ULL: goto x86_l_ed9;
	case 3804ULL: goto x86_l_edc;
	case 3807ULL: goto x86_l_edf;
	case 3813ULL: goto x86_l_ee5;
	case 3818ULL: goto x86_l_eea;
	case 3821ULL: goto x86_l_eed;
	case 3827ULL: goto x86_l_ef3;
	case 3830ULL: goto x86_l_ef6;
	case 3836ULL: goto x86_l_efc;
	case 3839ULL: goto x86_l_eff;
	case 3844ULL: goto x86_l_f04;
	case 3849ULL: goto x86_l_f09;
	case 3854ULL: goto x86_l_f0e;
	case 3859ULL: goto x86_l_f13;
	case 3864ULL: goto x86_l_f18;
	case 3866ULL: goto x86_l_f1a;
	case 3870ULL: goto x86_l_f1e;
	case 3875ULL: goto x86_l_f23;
	case 3878ULL: goto x86_l_f26;
	case 3884ULL: goto x86_l_f2c;
	case 3891ULL: goto x86_l_f33;
	case 3898ULL: goto x86_l_f3a;
	case 3902ULL: goto x86_l_f3e;
	case 3907ULL: goto x86_l_f43;
	case 3912ULL: goto x86_l_f48;
	case 3915ULL: goto x86_l_f4b;
	case 3917ULL: goto x86_l_f4d;
	case 3924ULL: goto x86_l_f54;
	case 3928ULL: goto x86_l_f58;
	case 3933ULL: goto x86_l_f5d;
	case 3938ULL: goto x86_l_f62;
	case 3940ULL: goto x86_l_f64;
	case 3947ULL: goto x86_l_f6b;
	case 3954ULL: goto x86_l_f72;
	case 3959ULL: goto x86_l_f77;
	case 3964ULL: goto x86_l_f7c;
	case 3966ULL: goto x86_l_f7e;
	case 3973ULL: goto x86_l_f85;
	case 3980ULL: goto x86_l_f8c;
	case 3985ULL: goto x86_l_f91;
	case 3990ULL: goto x86_l_f96;
	case 3992ULL: goto x86_l_f98;
	case 3999ULL: goto x86_l_f9f;
	case 4006ULL: goto x86_l_fa6;
	case 4011ULL: goto x86_l_fab;
	case 4016ULL: goto x86_l_fb0;
	case 4018ULL: goto x86_l_fb2;
	case 4025ULL: goto x86_l_fb9;
	case 4032ULL: goto x86_l_fc0;
	case 4037ULL: goto x86_l_fc5;
	case 4042ULL: goto x86_l_fca;
	case 4044ULL: goto x86_l_fcc;
	case 4051ULL: goto x86_l_fd3;
	case 4054ULL: goto x86_l_fd6;
	case 4062ULL: goto x86_l_fde;
	case 4070ULL: goto x86_l_fe6;
	case 4078ULL: goto x86_l_fee;
	case 4086ULL: goto x86_l_ff6;
	case 4093ULL: goto x86_l_ffd;
	case 4096ULL: goto x86_l_1000;
	case 4102ULL: goto x86_l_1006;
	case 4105ULL: goto x86_l_1009;
	case 4111ULL: goto x86_l_100f;
	case 4115ULL: goto x86_l_1013;
	case 4120ULL: goto x86_l_1018;
	case 4123ULL: goto x86_l_101b;
	case 4128ULL: goto x86_l_1020;
	case 4130ULL: goto x86_l_1022;
	case 4135ULL: goto x86_l_1027;
	case 4138ULL: goto x86_l_102a;
	case 4143ULL: goto x86_l_102f;
	case 4146ULL: goto x86_l_1032;
	case 4151ULL: goto x86_l_1037;
	case 4154ULL: goto x86_l_103a;
	case 4160ULL: goto x86_l_1040;
	case 4163ULL: goto x86_l_1043;
	case 4169ULL: goto x86_l_1049;
	case 4177ULL: goto x86_l_1051;
	case 4185ULL: goto x86_l_1059;
	case 4193ULL: goto x86_l_1061;
	case 4201ULL: goto x86_l_1069;
	case 4209ULL: goto x86_l_1071;
	case 4217ULL: goto x86_l_1079;
	case 4225ULL: goto x86_l_1081;
	case 4233ULL: goto x86_l_1089;
	case 4241ULL: goto x86_l_1091;
	case 4248ULL: goto x86_l_1098;
	case 4255ULL: goto x86_l_109f;
	case 4260ULL: goto x86_l_10a4;
	case 4265ULL: goto x86_l_10a9;
	case 4270ULL: goto x86_l_10ae;
	case 4272ULL: goto x86_l_10b0;
	case 4275ULL: goto x86_l_10b3;
	case 4277ULL: goto x86_l_10b5;
	case 4281ULL: goto x86_l_10b9;
	case 4284ULL: goto x86_l_10bc;
	case 4291ULL: goto x86_l_10c3;
	case 4299ULL: goto x86_l_10cb;
	case 4304ULL: goto x86_l_10d0;
	case 4309ULL: goto x86_l_10d5;
	case 4311ULL: goto x86_l_10d7;
	case 4314ULL: goto x86_l_10da;
	case 4319ULL: goto x86_l_10df;
	case 4321ULL: goto x86_l_10e1;
	case 4323ULL: goto x86_l_10e3;
	case 4327ULL: goto x86_l_10e7;
	case 4332ULL: goto x86_l_10ec;
	case 4337ULL: goto x86_l_10f1;
	case 4342ULL: goto x86_l_10f6;
	case 4347ULL: goto x86_l_10fb;
	case 4352ULL: goto x86_l_1100;
	case 4357ULL: goto x86_l_1105;
	case 4359ULL: goto x86_l_1107;
	case 4364ULL: goto x86_l_110c;
	case 4369ULL: goto x86_l_1111;
	case 4375ULL: goto x86_l_1117;
	case 4379ULL: goto x86_l_111b;
	case 4384ULL: goto x86_l_1120;
	case 4389ULL: goto x86_l_1125;
	case 4394ULL: goto x86_l_112a;
	case 4397ULL: goto x86_l_112d;
	case 4399ULL: goto x86_l_112f;
	case 4404ULL: goto x86_l_1134;
	case 4409ULL: goto x86_l_1139;
	case 4414ULL: goto x86_l_113e;
	case 4419ULL: goto x86_l_1143;
	case 4424ULL: goto x86_l_1148;
	case 4429ULL: goto x86_l_114d;
	case 4431ULL: goto x86_l_114f;
	case 4436ULL: goto x86_l_1154;
	case 4442ULL: goto x86_l_115a;
	case 4447ULL: goto x86_l_115f;
	case 4455ULL: goto x86_l_1167;
	case 4460ULL: goto x86_l_116c;
	case 4462ULL: goto x86_l_116e;
	case 4470ULL: goto x86_l_1176;
	case 4476ULL: goto x86_l_117c;
	case 4480ULL: goto x86_l_1180;
	case 4485ULL: goto x86_l_1185;
	case 4490ULL: goto x86_l_118a;
	case 4495ULL: goto x86_l_118f;
	case 4498ULL: goto x86_l_1192;
	case 4500ULL: goto x86_l_1194;
	case 4505ULL: goto x86_l_1199;
	case 4511ULL: goto x86_l_119f;
	case 4516ULL: goto x86_l_11a4;
	case 4524ULL: goto x86_l_11ac;
	case 4529ULL: goto x86_l_11b1;
	case 4532ULL: goto x86_l_11b4;
	case 4534ULL: goto x86_l_11b6;
	case 4538ULL: goto x86_l_11ba;
	case 4543ULL: goto x86_l_11bf;
	case 4548ULL: goto x86_l_11c4;
	case 4553ULL: goto x86_l_11c9;
	case 4556ULL: goto x86_l_11cc;
	case 4558ULL: goto x86_l_11ce;
	case 4563ULL: goto x86_l_11d3;
	case 4568ULL: goto x86_l_11d8;
	case 4572ULL: goto x86_l_11dc;
	case 4575ULL: goto x86_l_11df;
	case 4579ULL: goto x86_l_11e3;
	case 4581ULL: goto x86_l_11e5;
	case 4583ULL: goto x86_l_11e7;
	case 4585ULL: goto x86_l_11e9;
	case 4588ULL: goto x86_l_11ec;
	case 4593ULL: goto x86_l_11f1;
	case 4596ULL: goto x86_l_11f4;
	case 4598ULL: goto x86_l_11f6;
	case 4602ULL: goto x86_l_11fa;
	case 4604ULL: goto x86_l_11fc;
	case 4607ULL: goto x86_l_11ff;
	case 4610ULL: goto x86_l_1202;
	case 4613ULL: goto x86_l_1205;
	case 4616ULL: goto x86_l_1208;
	case 4621ULL: goto x86_l_120d;
	case 4624ULL: goto x86_l_1210;
	case 4629ULL: goto x86_l_1215;
	case 4634ULL: goto x86_l_121a;
	case 4640ULL: goto x86_l_1220;
	case 4647ULL: goto x86_l_1227;
	case 4653ULL: goto x86_l_122d;
	case 4655ULL: goto x86_l_122f;
	case 4661ULL: goto x86_l_1235;
	case 4665ULL: goto x86_l_1239;
	case 4669ULL: goto x86_l_123d;
	case 4672ULL: goto x86_l_1240;
	case 4676ULL: goto x86_l_1244;
	case 4679ULL: goto x86_l_1247;
	case 4684ULL: goto x86_l_124c;
	case 4686ULL: goto x86_l_124e;
	case 4691ULL: goto x86_l_1253;
	case 4699ULL: goto x86_l_125b;
	case 4704ULL: goto x86_l_1260;
	case 4709ULL: goto x86_l_1265;
	case 4714ULL: goto x86_l_126a;
	case 4719ULL: goto x86_l_126f;
	case 4722ULL: goto x86_l_1272;
	case 4728ULL: goto x86_l_1278;
	case 4731ULL: goto x86_l_127b;
	case 4737ULL: goto x86_l_1281;
	case 4742ULL: goto x86_l_1286;
	case 4744ULL: goto x86_l_1288;
	case 4746ULL: goto x86_l_128a;
	case 4749ULL: goto x86_l_128d;
	case 4751ULL: goto x86_l_128f;
	case 4756ULL: goto x86_l_1294;
	case 4759ULL: goto x86_l_1297;
	case 4765ULL: goto x86_l_129d;
	case 4768ULL: goto x86_l_12a0;
	case 4774ULL: goto x86_l_12a6;
	case 4783ULL: goto x86_l_12af;
	case 4786ULL: goto x86_l_12b2;
	case 4793ULL: goto x86_l_12b9;
	case 4796ULL: goto x86_l_12bc;
	case 4803ULL: goto x86_l_12c3;
	case 4808ULL: goto x86_l_12c8;
	case 4813ULL: goto x86_l_12cd;
	case 4818ULL: goto x86_l_12d2;
	case 4820ULL: goto x86_l_12d4;
	case 4825ULL: goto x86_l_12d9;
	case 4830ULL: goto x86_l_12de;
	case 4833ULL: goto x86_l_12e1;
	case 4838ULL: goto x86_l_12e6;
	case 4840ULL: goto x86_l_12e8;
	case 4844ULL: goto x86_l_12ec;
	case 4851ULL: goto x86_l_12f3;
	case 4856ULL: goto x86_l_12f8;
	case 4861ULL: goto x86_l_12fd;
	case 4864ULL: goto x86_l_1300;
	case 4867ULL: goto x86_l_1303;
	case 4869ULL: goto x86_l_1305;
	case 4873ULL: goto x86_l_1309;
	case 4880ULL: goto x86_l_1310;
	case 4887ULL: goto x86_l_1317;
	case 4892ULL: goto x86_l_131c;
	case 4897ULL: goto x86_l_1321;
	case 4899ULL: goto x86_l_1323;
	case 4903ULL: goto x86_l_1327;
	case 4910ULL: goto x86_l_132e;
	case 4917ULL: goto x86_l_1335;
	case 4922ULL: goto x86_l_133a;
	case 4927ULL: goto x86_l_133f;
	case 4929ULL: goto x86_l_1341;
	case 4933ULL: goto x86_l_1345;
	case 4938ULL: goto x86_l_134a;
	case 4943ULL: goto x86_l_134f;
	case 4948ULL: goto x86_l_1354;
	case 4953ULL: goto x86_l_1359;
	case 4960ULL: goto x86_l_1360;
	case 4968ULL: goto x86_l_1368;
	case 4973ULL: goto x86_l_136d;
	case 4978ULL: goto x86_l_1372;
	case 4981ULL: goto x86_l_1375;
	case 4983ULL: goto x86_l_1377;
	case 4990ULL: goto x86_l_137e;
	case 4995ULL: goto x86_l_1383;
	case 5000ULL: goto x86_l_1388;
	case 5005ULL: goto x86_l_138d;
	case 5007ULL: goto x86_l_138f;
	case 5014ULL: goto x86_l_1396;
	case 5022ULL: goto x86_l_139e;
	case 5027ULL: goto x86_l_13a3;
	case 5032ULL: goto x86_l_13a8;
	case 5034ULL: goto x86_l_13aa;
	case 5041ULL: goto x86_l_13b1;
	case 5049ULL: goto x86_l_13b9;
	case 5054ULL: goto x86_l_13be;
	case 5059ULL: goto x86_l_13c3;
	case 5061ULL: goto x86_l_13c5;
	case 5070ULL: goto x86_l_13ce;
	case 5078ULL: goto x86_l_13d6;
	case 5083ULL: goto x86_l_13db;
	case 5088ULL: goto x86_l_13e0;
	case 5093ULL: goto x86_l_13e5;
	case 5095ULL: goto x86_l_13e7;
	case 5098ULL: goto x86_l_13ea;
	case 5106ULL: goto x86_l_13f2;
	case 5111ULL: goto x86_l_13f7;
	case 5119ULL: goto x86_l_13ff;
	case 5124ULL: goto x86_l_1404;
	case 5126ULL: goto x86_l_1406;
	case 5135ULL: goto x86_l_140f;
	case 5140ULL: goto x86_l_1414;
	case 5145ULL: goto x86_l_1419;
	case 5153ULL: goto x86_l_1421;
	case 5158ULL: goto x86_l_1426;
	case 5161ULL: goto x86_l_1429;
	case 5163ULL: goto x86_l_142b;
	case 5171ULL: goto x86_l_1433;
	case 5174ULL: goto x86_l_1436;
	case 5177ULL: goto x86_l_1439;
	case 5183ULL: goto x86_l_143f;
	case 5186ULL: goto x86_l_1442;
	case 5192ULL: goto x86_l_1448;
	case 5197ULL: goto x86_l_144d;
	case 5202ULL: goto x86_l_1452;
	case 5207ULL: goto x86_l_1457;
	case 5215ULL: goto x86_l_145f;
	case 5220ULL: goto x86_l_1464;
	case 5222ULL: goto x86_l_1466;
	case 5230ULL: goto x86_l_146e;
	case 5234ULL: goto x86_l_1472;
	case 5241ULL: goto x86_l_1479;
	case 5250ULL: goto x86_l_1482;
	case 5257ULL: goto x86_l_1489;
	case 5262ULL: goto x86_l_148e;
	case 5267ULL: goto x86_l_1493;
	case 5274ULL: goto x86_l_149a;
	case 5282ULL: goto x86_l_14a2;
	case 5290ULL: goto x86_l_14aa;
	case 5298ULL: goto x86_l_14b2;
	case 5303ULL: goto x86_l_14b7;
	case 5308ULL: goto x86_l_14bc;
	case 5310ULL: goto x86_l_14be;
	case 5314ULL: goto x86_l_14c2;
	case 5319ULL: goto x86_l_14c7;
	case 5322ULL: goto x86_l_14ca;
	case 5327ULL: goto x86_l_14cf;
	case 5330ULL: goto x86_l_14d2;
	case 5332ULL: goto x86_l_14d4;
	case 5339ULL: goto x86_l_14db;
	case 5344ULL: goto x86_l_14e0;
	case 5352ULL: goto x86_l_14e8;
	case 5357ULL: goto x86_l_14ed;
	case 5362ULL: goto x86_l_14f2;
	case 5371ULL: goto x86_l_14fb;
	case 5380ULL: goto x86_l_1504;
	case 5385ULL: goto x86_l_1509;
	case 5387ULL: goto x86_l_150b;
	case 5391ULL: goto x86_l_150f;
	case 5396ULL: goto x86_l_1514;
	case 5401ULL: goto x86_l_1519;
	case 5406ULL: goto x86_l_151e;
	case 5411ULL: goto x86_l_1523;
	case 5416ULL: goto x86_l_1528;
	case 5418ULL: goto x86_l_152a;
	case 5422ULL: goto x86_l_152e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e03:
	/* 0xe03: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_e06:
	/* 0xe06: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e0b:
	/* 0xe0b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_e0e:
	/* 0xe0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e10:
	/* 0xe10: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e14:
	/* 0xe14: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e17:
	/* 0xe17: js     1f3b <generic_fexit_event+0x1f3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7995ULL;
	}
x86_l_e1d:
	/* 0xe1d: movzx  eax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_e21:
	/* 0xe21: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_e24:
	/* 0xe24: je     1eef <generic_fexit_event+0x1eef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7919ULL;
	}
x86_l_e2a:
	/* 0xe2a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e2d:
	/* 0xe2d: jne    1f27 <generic_fexit_event+0x1f27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7975ULL;
	}
x86_l_e33:
	/* 0xe33: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e38:
	/* 0xe38: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e3d:
	/* 0xe3d: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e42:
	/* 0xe42: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e47:
	/* 0xe47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e49:
	/* 0xe49: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e4d:
	/* 0xe4d: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e51:
	/* 0xe51: mov    QWORD PTR [rdi+0xa4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_e58:
	/* 0xe58: add    rdi,0x9e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 158ULL);
x86_l_e5f:
	/* 0xe5f: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_e63:
	/* 0xe63: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e68:
	/* 0xe68: jmp    1f1d <generic_fexit_event+0x1f1d> */
	return 7965ULL;
x86_l_e6d:
	/* 0xe6d: cmp    ebx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_e70:
	/* 0xe70: jg     126f <generic_fexit_event+0x126f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_126f;
	}
x86_l_e76:
	/* 0xe76: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_e79:
	/* 0xe79: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_e7c:
	/* 0xe7c: je     174b <generic_fexit_event+0x174b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5963ULL;
	}
x86_l_e82:
	/* 0xe82: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_e85:
	/* 0xe85: jne    10e7 <generic_fexit_event+0x10e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10e7;
	}
x86_l_e8b:
	/* 0xe8b: mov    QWORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_e96:
	/* 0xe96: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_e9b:
	/* 0xe9b: jmp    10e7 <generic_fexit_event+0x10e7> */
	goto x86_l_10e7;
x86_l_ea0:
	/* 0xea0: cmp    ebx,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 38ULL);
x86_l_ea3:
	/* 0xea3: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ea7:
	/* 0xea7: jne    356a <generic_fexit_event+0x356a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13674ULL;
	}
x86_l_ead:
	/* 0xead: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eb2:
	/* 0xeb2: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_eb5:
	/* 0xeb5: add    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 192ULL);
x86_l_ebd:
	/* 0xebd: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_ec0:
	/* 0xec0: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ec6:
	/* 0xec6: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_ec9:
	/* 0xec9: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_ed0:
	/* 0xed0: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_ed2:
	/* 0xed2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_ed7:
	/* 0xed7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed9:
	/* 0xed9: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_edc:
	/* 0xedc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_edf:
	/* 0xedf: jns    163b <generic_fexit_event+0x163b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 5691ULL;
	}
x86_l_ee5:
	/* 0xee5: jmp    1c28 <generic_fexit_event+0x1c28> */
	return 7208ULL;
x86_l_eea:
	/* 0xeea: cmp    ebx,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 43ULL);
x86_l_eed:
	/* 0xeed: je     1b0c <generic_fexit_event+0x1b0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6924ULL;
	}
x86_l_ef3:
	/* 0xef3: cmp    ebx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 41ULL);
x86_l_ef6:
	/* 0xef6: jne    10e7 <generic_fexit_event+0x10e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10e7;
	}
x86_l_efc:
	/* 0xefc: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_eff:
	/* 0xeff: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f04:
	/* 0xf04: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f09:
	/* 0xf09: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f0e:
	/* 0xf0e: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f13:
	/* 0xf13: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f18:
	/* 0xf18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f1a:
	/* 0xf1a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f1e:
	/* 0xf1e: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f23:
	/* 0xf23: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_f26:
	/* 0xf26: je     207b <generic_fexit_event+0x207b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8315ULL;
	}
x86_l_f2c:
	/* 0xf2c: mov    QWORD PTR [rcx+0xc4],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_f33:
	/* 0xf33: lea    rdi,[rcx+0xc2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_f3a:
	/* 0xf3a: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f3e:
	/* 0xf3e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f43:
	/* 0xf43: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f48:
	/* 0xf48: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_f4b:
	/* 0xf4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f4d:
	/* 0xf4d: lea    rdi,[rbx+0xd6] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_f54:
	/* 0xf54: lea    rdx,[rbp+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_f58:
	/* 0xf58: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f5d:
	/* 0xf5d: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_f62:
	/* 0xf62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f64:
	/* 0xf64: lea    rdi,[rbx+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_f6b:
	/* 0xf6b: lea    rdx,[rbp+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_f72:
	/* 0xf72: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f77:
	/* 0xf77: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f7c:
	/* 0xf7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f7e:
	/* 0xf7e: lea    rdi,[rbx+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_f85:
	/* 0xf85: lea    rdx,[rbp+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_f8c:
	/* 0xf8c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f91:
	/* 0xf91: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f96:
	/* 0xf96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f98:
	/* 0xf98: lea    rdi,[rbx+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_f9f:
	/* 0xf9f: lea    rdx,[rbp+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_fa6:
	/* 0xfa6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fab:
	/* 0xfab: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fb0:
	/* 0xfb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb2:
	/* 0xfb2: lea    rdi,[rbx+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_fb9:
	/* 0xfb9: lea    rdx,[rbp+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_fc0:
	/* 0xfc0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fc5:
	/* 0xfc5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fca:
	/* 0xfca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fcc:
	/* 0xfcc: lea    r12,[rbx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_fd3:
	/* 0xfd3: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_fd6:
	/* 0xfd6: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fde:
	/* 0xfde: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_fe6:
	/* 0xfe6: mov    QWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_fee:
	/* 0xfee: mov    QWORD PTR [r13+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_ff6:
	/* 0xff6: movzx  eax,WORD PTR [rbx+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_ffd:
	/* 0xffd: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1000:
	/* 0x1000: je     2007 <generic_fexit_event+0x2007> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8199ULL;
	}
x86_l_1006:
	/* 0x1006: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1009:
	/* 0x1009: jne    202d <generic_fexit_event+0x202d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8237ULL;
	}
x86_l_100f:
	/* 0x100f: lea    rdx,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1013:
	/* 0x1013: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1018:
	/* 0x1018: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_101b:
	/* 0x101b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1020:
	/* 0x1020: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1022:
	/* 0x1022: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1027:
	/* 0x1027: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_102a:
	/* 0x102a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_102f:
	/* 0x102f: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1032:
	/* 0x1032: jmp    202b <generic_fexit_event+0x202b> */
	return 8235ULL;
x86_l_1037:
	/* 0x1037: cmp    ebx,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 26ULL);
x86_l_103a:
	/* 0x103a: je     1b99 <generic_fexit_event+0x1b99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7065ULL;
	}
x86_l_1040:
	/* 0x1040: cmp    ebx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 27ULL);
x86_l_1043:
	/* 0x1043: jne    10e7 <generic_fexit_event+0x10e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10e7;
	}
x86_l_1049:
	/* 0x1049: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1051:
	/* 0x1051: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1059:
	/* 0x1059: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1061:
	/* 0x1061: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1069:
	/* 0x1069: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1071:
	/* 0x1071: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1079:
	/* 0x1079: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1081:
	/* 0x1081: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1089:
	/* 0x1089: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1091:
	/* 0x1091: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1098:
	/* 0x1098: lea    rdi,[rcx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_109f:
	/* 0x109f: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10a4:
	/* 0x10a4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_10a9:
	/* 0x10a9: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_10ae:
	/* 0x10ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b0:
	/* 0x10b0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10b3:
	/* 0x10b3: js     10e1 <generic_fexit_event+0x10e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_10e1;
	}
x86_l_10b5:
	/* 0x10b5: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10b9:
	/* 0x10b9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10bc:
	/* 0x10bc: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_10c3:
	/* 0x10c3: lea    rdx,[r12+0x348] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 840ULL);
x86_l_10cb:
	/* 0x10cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10d0:
	/* 0x10d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10d5:
	/* 0x10d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d7:
	/* 0x10d7: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_10da:
	/* 0x10da: mov    ebp,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 80ULL);
x86_l_10df:
	/* 0x10df: jmp    10e7 <generic_fexit_event+0x10e7> */
	goto x86_l_10e7;
x86_l_10e1:
	/* 0x10e1: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10e3:
	/* 0x10e3: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10e7:
	/* 0x10e7: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10ec:
	/* 0x10ec: jmp    356a <generic_fexit_event+0x356a> */
	return 13674ULL;
x86_l_10f1:
	/* 0x10f1: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10f6:
	/* 0x10f6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10fb:
	/* 0x10fb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1100:
	/* 0x1100: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1105:
	/* 0x1105: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1107:
	/* 0x1107: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_110c:
	/* 0x110c: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_1111:
	/* 0x1111: je     3496 <generic_fexit_event+0x3496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13462ULL;
	}
x86_l_1117:
	/* 0x1117: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_111b:
	/* 0x111b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1120:
	/* 0x1120: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1125:
	/* 0x1125: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_112a:
	/* 0x112a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_112d:
	/* 0x112d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_112f:
	/* 0x112f: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1134:
	/* 0x1134: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1139:
	/* 0x1139: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_113e:
	/* 0x113e: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1143:
	/* 0x1143: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1148:
	/* 0x1148: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_114d:
	/* 0x114d: jne    115a <generic_fexit_event+0x115a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_115a;
	}
x86_l_114f:
	/* 0x114f: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_1154:
	/* 0x1154: je     677 <generic_fexit_event+0x677> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1655ULL;
	}
x86_l_115a:
	/* 0x115a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_115f:
	/* 0x115f: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1167:
	/* 0x1167: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_116c:
	/* 0x116c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_116e:
	/* 0x116e: cmp    r13,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 136ULL);
x86_l_1176:
	/* 0x1176: je     1d61 <generic_fexit_event+0x1d61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7521ULL;
	}
x86_l_117c:
	/* 0x117c: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1180:
	/* 0x1180: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1185:
	/* 0x1185: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_118a:
	/* 0x118a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_118f:
	/* 0x118f: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1192:
	/* 0x1192: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1194:
	/* 0x1194: cmp    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1199:
	/* 0x1199: je     1d61 <generic_fexit_event+0x1d61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7521ULL;
	}
x86_l_119f:
	/* 0x119f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11a4:
	/* 0x11a4: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_11ac:
	/* 0x11ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11b1:
	/* 0x11b1: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_11b4:
	/* 0x11b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11b6:
	/* 0x11b6: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_11ba:
	/* 0x11ba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11bf:
	/* 0x11bf: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_11c4:
	/* 0x11c4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_11c9:
	/* 0x11c9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_11cc:
	/* 0x11cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ce:
	/* 0x11ce: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11d3:
	/* 0x11d3: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_11d8:
	/* 0x11d8: mov    esi,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_11dc:
	/* 0x11dc: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_11df:
	/* 0x11df: mov    edi,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_11e3:
	/* 0x11e3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11e5:
	/* 0x11e5: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_11e7:
	/* 0x11e7: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_11e9:
	/* 0x11e9: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_11ec:
	/* 0x11ec: add    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_11f1:
	/* 0x11f1: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11f4:
	/* 0x11f4: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_11f6:
	/* 0x11f6: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_11fa:
	/* 0x11fa: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_11fc:
	/* 0x11fc: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_11ff:
	/* 0x11ff: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1202:
	/* 0x1202: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_1205:
	/* 0x1205: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1208:
	/* 0x1208: mov    DWORD PTR [rsp+0x60],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_120d:
	/* 0x120d: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1210:
	/* 0x1210: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1215:
	/* 0x1215: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_121a:
	/* 0x121a: jb     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8190ULL;
	}
x86_l_1220:
	/* 0x1220: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_1227:
	/* 0x1227: ja     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8190ULL;
	}
x86_l_122d:
	/* 0x122d: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_122f:
	/* 0x122f: jbe    1fdf <generic_fexit_event+0x1fdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 8159ULL;
	}
x86_l_1235:
	/* 0x1235: lea    rbx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1239:
	/* 0x1239: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_123d:
	/* 0x123d: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1240:
	/* 0x1240: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1244:
	/* 0x1244: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1247:
	/* 0x1247: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_124c:
	/* 0x124c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_124e:
	/* 0x124e: mov    QWORD PTR [rsp+0x58],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1253:
	/* 0x1253: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_125b:
	/* 0x125b: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1260:
	/* 0x1260: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1265:
	/* 0x1265: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_126a:
	/* 0x126a: jmp    1db8 <generic_fexit_event+0x1db8> */
	return 7608ULL;
x86_l_126f:
	/* 0x126f: cmp    ebx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_1272:
	/* 0x1272: je     17de <generic_fexit_event+0x17de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6110ULL;
	}
x86_l_1278:
	/* 0x1278: cmp    ebx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 18ULL);
x86_l_127b:
	/* 0x127b: jne    10e7 <generic_fexit_event+0x10e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10e7;
	}
x86_l_1281:
	/* 0x1281: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1286:
	/* 0x1286: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1288:
	/* 0x1288: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_128a:
	/* 0x128a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_128d:
	/* 0x128d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_128f:
	/* 0x128f: jmp    10e3 <generic_fexit_event+0x10e3> */
	goto x86_l_10e3;
x86_l_1294:
	/* 0x1294: cmp    ebx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 19ULL);
x86_l_1297:
	/* 0x1297: je     1aca <generic_fexit_event+0x1aca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6858ULL;
	}
x86_l_129d:
	/* 0x129d: cmp    ebx,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 20ULL);
x86_l_12a0:
	/* 0x12a0: jne    10e7 <generic_fexit_event+0x10e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10e7;
	}
x86_l_12a6:
	/* 0x12a6: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_12af:
	/* 0x12af: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_12b2:
	/* 0x12b2: add    r12,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_12b9:
	/* 0x12b9: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_12bc:
	/* 0x12bc: lea    rdx,[rbx+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_12c3:
	/* 0x12c3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12c8:
	/* 0x12c8: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12cd:
	/* 0x12cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12d2:
	/* 0x12d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d4:
	/* 0x12d4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_12d9:
	/* 0x12d9: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12de:
	/* 0x12de: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_12e1:
	/* 0x12e1: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_12e6:
	/* 0x12e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12e8:
	/* 0x12e8: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12ec:
	/* 0x12ec: lea    rdi,[rax+0x12c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 300ULL);
x86_l_12f3:
	/* 0x12f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12f8:
	/* 0x12f8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12fd:
	/* 0x12fd: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1300:
	/* 0x1300: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_1303:
	/* 0x1303: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1305:
	/* 0x1305: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1309:
	/* 0x1309: lea    rdi,[rax+0x11c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 284ULL);
x86_l_1310:
	/* 0x1310: lea    rdx,[rbx+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1317:
	/* 0x1317: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_131c:
	/* 0x131c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1321:
	/* 0x1321: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1323:
	/* 0x1323: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1327:
	/* 0x1327: add    rdi,0x124 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 292ULL);
x86_l_132e:
	/* 0x132e: lea    rdx,[rbx+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_1335:
	/* 0x1335: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_133a:
	/* 0x133a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_133f:
	/* 0x133f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1341:
	/* 0x1341: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1345:
	/* 0x1345: mov    ebp,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 152ULL);
x86_l_134a:
	/* 0x134a: jmp    10e7 <generic_fexit_event+0x10e7> */
	goto x86_l_10e7;
x86_l_134f:
	/* 0x134f: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1354:
	/* 0x1354: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1359:
	/* 0x1359: lea    rdi,[rcx+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1360:
	/* 0x1360: lea    rdx,[r12+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1368:
	/* 0x1368: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_136d:
	/* 0x136d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1372:
	/* 0x1372: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_1375:
	/* 0x1375: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1377:
	/* 0x1377: lea    rdi,[rbx+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_137e:
	/* 0x137e: lea    rdx,[r12+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1383:
	/* 0x1383: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1388:
	/* 0x1388: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_138d:
	/* 0x138d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_138f:
	/* 0x138f: lea    rdi,[rbx+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1396:
	/* 0x1396: lea    rdx,[r12+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_139e:
	/* 0x139e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13a3:
	/* 0x13a3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13a8:
	/* 0x13a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13aa:
	/* 0x13aa: lea    rdi,[rbx+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_13b1:
	/* 0x13b1: lea    rdx,[r12+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_13b9:
	/* 0x13b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13be:
	/* 0x13be: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13c3:
	/* 0x13c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13c5:
	/* 0x13c5: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_13ce:
	/* 0x13ce: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_13d6:
	/* 0x13d6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13db:
	/* 0x13db: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13e0:
	/* 0x13e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13e5:
	/* 0x13e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e7:
	/* 0x13e7: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_13ea:
	/* 0x13ea: lea    rdx,[r12+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_13f2:
	/* 0x13f2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13f7:
	/* 0x13f7: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_13ff:
	/* 0x13ff: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1404:
	/* 0x1404: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1406:
	/* 0x1406: movzx  r12d,WORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 136ULL);
x86_l_140f:
	/* 0x140f: add    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_1414:
	/* 0x1414: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1419:
	/* 0x1419: lea    rdi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1421:
	/* 0x1421: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1426:
	/* 0x1426: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1429:
	/* 0x1429: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_142b:
	/* 0x142b: movzx  eax,BYTE PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 172ULL);
x86_l_1433:
	/* 0x1433: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_1436:
	/* 0x1436: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1439:
	/* 0x1439: je     1c31 <generic_fexit_event+0x1c31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7217ULL;
	}
x86_l_143f:
	/* 0x143f: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1442:
	/* 0x1442: jne    3025 <generic_fexit_event+0x3025> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12325ULL;
	}
x86_l_1448:
	/* 0x1448: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_144d:
	/* 0x144d: lea    rdx,[r12+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_1452:
	/* 0x1452: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1457:
	/* 0x1457: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_145f:
	/* 0x145f: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1464:
	/* 0x1464: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1466:
	/* 0x1466: movzx  eax,BYTE PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 200ULL);
x86_l_146e:
	/* 0x146e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1472:
	/* 0x1472: mov    WORD PTR [rcx+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1479:
	/* 0x1479: mov    WORD PTR [rcx+0xc2],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655426ULL);
x86_l_1482:
	/* 0x1482: lea    r13,[rcx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1489:
	/* 0x1489: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_148e:
	/* 0x148e: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1493:
	/* 0x1493: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_149a:
	/* 0x149a: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_14a2:
	/* 0x14a2: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_14aa:
	/* 0x14aa: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_14b2:
	/* 0x14b2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14b7:
	/* 0x14b7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14bc:
	/* 0x14bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14be:
	/* 0x14be: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_14c2:
	/* 0x14c2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14c7:
	/* 0x14c7: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_14ca:
	/* 0x14ca: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14cf:
	/* 0x14cf: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_14d2:
	/* 0x14d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d4:
	/* 0x14d4: lea    rdx,[rbp+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_14db:
	/* 0x14db: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14e0:
	/* 0x14e0: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_14e8:
	/* 0x14e8: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_14ed:
	/* 0x14ed: jmp    2ecb <generic_fexit_event+0x2ecb> */
	return 11979ULL;
x86_l_14f2:
	/* 0x14f2: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_14fb:
	/* 0x14fb: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1504:
	/* 0x1504: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1509:
	/* 0x1509: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_150b:
	/* 0x150b: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_150f:
	/* 0x150f: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1514:
	/* 0x1514: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1519:
	/* 0x1519: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_151e:
	/* 0x151e: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1523:
	/* 0x1523: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1528:
	/* 0x1528: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_152a:
	/* 0x152a: mov    eax,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_152e:
	/* 0x152e: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
	return 5426ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5426ULL: goto x86_l_1532;
	case 5431ULL: goto x86_l_1537;
	case 5438ULL: goto x86_l_153e;
	case 5443ULL: goto x86_l_1543;
	case 5445ULL: goto x86_l_1545;
	case 5448ULL: goto x86_l_1548;
	case 5454ULL: goto x86_l_154e;
	case 5456ULL: goto x86_l_1550;
	case 5461ULL: goto x86_l_1555;
	case 5466ULL: goto x86_l_155a;
	case 5471ULL: goto x86_l_155f;
	case 5476ULL: goto x86_l_1564;
	case 5479ULL: goto x86_l_1567;
	case 5481ULL: goto x86_l_1569;
	case 5487ULL: goto x86_l_156f;
	case 5491ULL: goto x86_l_1573;
	case 5498ULL: goto x86_l_157a;
	case 5501ULL: goto x86_l_157d;
	case 5506ULL: goto x86_l_1582;
	case 5509ULL: goto x86_l_1585;
	case 5511ULL: goto x86_l_1587;
	case 5516ULL: goto x86_l_158c;
	case 5520ULL: goto x86_l_1590;
	case 5524ULL: goto x86_l_1594;
	case 5528ULL: goto x86_l_1598;
	case 5532ULL: goto x86_l_159c;
	case 5537ULL: goto x86_l_15a1;
	case 5542ULL: goto x86_l_15a6;
	case 5544ULL: goto x86_l_15a8;
	case 5548ULL: goto x86_l_15ac;
	case 5552ULL: goto x86_l_15b0;
	case 5557ULL: goto x86_l_15b5;
	case 5562ULL: goto x86_l_15ba;
	case 5567ULL: goto x86_l_15bf;
	case 5572ULL: goto x86_l_15c4;
	case 5577ULL: goto x86_l_15c9;
	case 5580ULL: goto x86_l_15cc;
	case 5582ULL: goto x86_l_15ce;
	case 5587ULL: goto x86_l_15d3;
	case 5592ULL: goto x86_l_15d8;
	case 5595ULL: goto x86_l_15db;
	case 5600ULL: goto x86_l_15e0;
	case 5602ULL: goto x86_l_15e2;
	case 5606ULL: goto x86_l_15e6;
	case 5611ULL: goto x86_l_15eb;
	case 5614ULL: goto x86_l_15ee;
	case 5621ULL: goto x86_l_15f5;
	case 5626ULL: goto x86_l_15fa;
	case 5631ULL: goto x86_l_15ff;
	case 5633ULL: goto x86_l_1601;
	case 5636ULL: goto x86_l_1604;
	case 5639ULL: goto x86_l_1607;
	case 5641ULL: goto x86_l_1609;
	case 5646ULL: goto x86_l_160e;
	case 5651ULL: goto x86_l_1613;
	case 5656ULL: goto x86_l_1618;
	case 5660ULL: goto x86_l_161c;
	case 5667ULL: goto x86_l_1623;
	case 5672ULL: goto x86_l_1628;
	case 5677ULL: goto x86_l_162d;
	case 5679ULL: goto x86_l_162f;
	case 5682ULL: goto x86_l_1632;
	case 5685ULL: goto x86_l_1635;
	case 5691ULL: goto x86_l_163b;
	case 5694ULL: goto x86_l_163e;
	case 5699ULL: goto x86_l_1643;
	case 5701ULL: goto x86_l_1645;
	case 5705ULL: goto x86_l_1649;
	case 5709ULL: goto x86_l_164d;
	case 5714ULL: goto x86_l_1652;
	case 5717ULL: goto x86_l_1655;
	case 5726ULL: goto x86_l_165e;
	case 5732ULL: goto x86_l_1664;
	case 5736ULL: goto x86_l_1668;
	case 5744ULL: goto x86_l_1670;
	case 5748ULL: goto x86_l_1674;
	case 5754ULL: goto x86_l_167a;
	case 5759ULL: goto x86_l_167f;
	case 5764ULL: goto x86_l_1684;
	case 5769ULL: goto x86_l_1689;
	case 5771ULL: goto x86_l_168b;
	case 5776ULL: goto x86_l_1690;
	case 5778ULL: goto x86_l_1692;
	case 5784ULL: goto x86_l_1698;
	case 5789ULL: goto x86_l_169d;
	case 5792ULL: goto x86_l_16a0;
	case 5795ULL: goto x86_l_16a3;
	case 5799ULL: goto x86_l_16a7;
	case 5802ULL: goto x86_l_16aa;
	case 5807ULL: goto x86_l_16af;
	case 5810ULL: goto x86_l_16b2;
	case 5814ULL: goto x86_l_16b6;
	case 5819ULL: goto x86_l_16bb;
	case 5826ULL: goto x86_l_16c2;
	case 5828ULL: goto x86_l_16c4;
	case 5831ULL: goto x86_l_16c7;
	case 5836ULL: goto x86_l_16cc;
	case 5839ULL: goto x86_l_16cf;
	case 5845ULL: goto x86_l_16d5;
	case 5848ULL: goto x86_l_16d8;
	case 5853ULL: goto x86_l_16dd;
	case 5858ULL: goto x86_l_16e2;
	case 5860ULL: goto x86_l_16e4;
	case 5862ULL: goto x86_l_16e6;
	case 5867ULL: goto x86_l_16eb;
	case 5869ULL: goto x86_l_16ed;
	case 5871ULL: goto x86_l_16ef;
	case 5876ULL: goto x86_l_16f4;
	case 5879ULL: goto x86_l_16f7;
	case 5883ULL: goto x86_l_16fb;
	case 5889ULL: goto x86_l_1701;
	case 5895ULL: goto x86_l_1707;
	case 5900ULL: goto x86_l_170c;
	case 5906ULL: goto x86_l_1712;
	case 5911ULL: goto x86_l_1717;
	case 5919ULL: goto x86_l_171f;
	case 5923ULL: goto x86_l_1723;
	case 5926ULL: goto x86_l_1726;
	case 5929ULL: goto x86_l_1729;
	case 5937ULL: goto x86_l_1731;
	case 5942ULL: goto x86_l_1736;
	case 5947ULL: goto x86_l_173b;
	case 5950ULL: goto x86_l_173e;
	case 5958ULL: goto x86_l_1746;
	case 5963ULL: goto x86_l_174b;
	case 5968ULL: goto x86_l_1750;
	case 5977ULL: goto x86_l_1759;
	case 5986ULL: goto x86_l_1762;
	case 5991ULL: goto x86_l_1767;
	case 5996ULL: goto x86_l_176c;
	case 6001ULL: goto x86_l_1771;
	case 6006ULL: goto x86_l_1776;
	case 6011ULL: goto x86_l_177b;
	case 6013ULL: goto x86_l_177d;
	case 6018ULL: goto x86_l_1782;
	case 6025ULL: goto x86_l_1789;
	case 6028ULL: goto x86_l_178c;
	case 6034ULL: goto x86_l_1792;
	case 6038ULL: goto x86_l_1796;
	case 6041ULL: goto x86_l_1799;
	case 6048ULL: goto x86_l_17a0;
	case 6053ULL: goto x86_l_17a5;
	case 6056ULL: goto x86_l_17a8;
	case 6059ULL: goto x86_l_17ab;
	case 6061ULL: goto x86_l_17ad;
	case 6066ULL: goto x86_l_17b2;
	case 6068ULL: goto x86_l_17b4;
	case 6070ULL: goto x86_l_17b6;
	case 6077ULL: goto x86_l_17bd;
	case 6081ULL: goto x86_l_17c1;
	case 6083ULL: goto x86_l_17c3;
	case 6086ULL: goto x86_l_17c6;
	case 6093ULL: goto x86_l_17cd;
	case 6097ULL: goto x86_l_17d1;
	case 6100ULL: goto x86_l_17d4;
	case 6105ULL: goto x86_l_17d9;
	case 6110ULL: goto x86_l_17de;
	case 6117ULL: goto x86_l_17e5;
	case 6122ULL: goto x86_l_17ea;
	case 6127ULL: goto x86_l_17ef;
	case 6132ULL: goto x86_l_17f4;
	case 6134ULL: goto x86_l_17f6;
	case 6138ULL: goto x86_l_17fa;
	case 6145ULL: goto x86_l_1801;
	case 6150ULL: goto x86_l_1806;
	case 6155ULL: goto x86_l_180b;
	case 6160ULL: goto x86_l_1810;
	case 6162ULL: goto x86_l_1812;
	case 6166ULL: goto x86_l_1816;
	case 6173ULL: goto x86_l_181d;
	case 6178ULL: goto x86_l_1822;
	case 6183ULL: goto x86_l_1827;
	case 6188ULL: goto x86_l_182c;
	case 6190ULL: goto x86_l_182e;
	case 6194ULL: goto x86_l_1832;
	case 6201ULL: goto x86_l_1839;
	case 6206ULL: goto x86_l_183e;
	case 6211ULL: goto x86_l_1843;
	case 6216ULL: goto x86_l_1848;
	case 6218ULL: goto x86_l_184a;
	case 6222ULL: goto x86_l_184e;
	case 6229ULL: goto x86_l_1855;
	case 6234ULL: goto x86_l_185a;
	case 6239ULL: goto x86_l_185f;
	case 6244ULL: goto x86_l_1864;
	case 6246ULL: goto x86_l_1866;
	case 6250ULL: goto x86_l_186a;
	case 6257ULL: goto x86_l_1871;
	case 6262ULL: goto x86_l_1876;
	case 6267ULL: goto x86_l_187b;
	case 6272ULL: goto x86_l_1880;
	case 6274ULL: goto x86_l_1882;
	case 6278ULL: goto x86_l_1886;
	case 6285ULL: goto x86_l_188d;
	case 6290ULL: goto x86_l_1892;
	case 6295ULL: goto x86_l_1897;
	case 6300ULL: goto x86_l_189c;
	case 6302ULL: goto x86_l_189e;
	case 6306ULL: goto x86_l_18a2;
	case 6313ULL: goto x86_l_18a9;
	case 6318ULL: goto x86_l_18ae;
	case 6323ULL: goto x86_l_18b3;
	case 6328ULL: goto x86_l_18b8;
	case 6330ULL: goto x86_l_18ba;
	case 6334ULL: goto x86_l_18be;
	case 6344ULL: goto x86_l_18c8;
	case 6348ULL: goto x86_l_18cc;
	case 6355ULL: goto x86_l_18d3;
	case 6360ULL: goto x86_l_18d8;
	case 6365ULL: goto x86_l_18dd;
	case 6370ULL: goto x86_l_18e2;
	case 6372ULL: goto x86_l_18e4;
	case 6377ULL: goto x86_l_18e9;
	case 6381ULL: goto x86_l_18ed;
	case 6388ULL: goto x86_l_18f4;
	case 6393ULL: goto x86_l_18f9;
	case 6397ULL: goto x86_l_18fd;
	case 6404ULL: goto x86_l_1904;
	case 6409ULL: goto x86_l_1909;
	case 6413ULL: goto x86_l_190d;
	case 6420ULL: goto x86_l_1914;
	case 6428ULL: goto x86_l_191c;
	case 6433ULL: goto x86_l_1921;
	case 6438ULL: goto x86_l_1926;
	case 6443ULL: goto x86_l_192b;
	case 6445ULL: goto x86_l_192d;
	case 6448ULL: goto x86_l_1930;
	case 6453ULL: goto x86_l_1935;
	case 6461ULL: goto x86_l_193d;
	case 6466ULL: goto x86_l_1942;
	case 6469ULL: goto x86_l_1945;
	case 6474ULL: goto x86_l_194a;
	case 6476ULL: goto x86_l_194c;
	case 6480ULL: goto x86_l_1950;
	case 6487ULL: goto x86_l_1957;
	case 6495ULL: goto x86_l_195f;
	case 6500ULL: goto x86_l_1964;
	case 6505ULL: goto x86_l_1969;
	case 6507ULL: goto x86_l_196b;
	case 6511ULL: goto x86_l_196f;
	case 6518ULL: goto x86_l_1976;
	case 6526ULL: goto x86_l_197e;
	case 6531ULL: goto x86_l_1983;
	case 6536ULL: goto x86_l_1988;
	case 6538ULL: goto x86_l_198a;
	case 6542ULL: goto x86_l_198e;
	case 6549ULL: goto x86_l_1995;
	case 6556ULL: goto x86_l_199c;
	case 6561ULL: goto x86_l_19a1;
	case 6566ULL: goto x86_l_19a6;
	case 6569ULL: goto x86_l_19a9;
	case 6572ULL: goto x86_l_19ac;
	case 6574ULL: goto x86_l_19ae;
	case 6578ULL: goto x86_l_19b2;
	case 6583ULL: goto x86_l_19b7;
	case 6588ULL: goto x86_l_19bc;
	case 6596ULL: goto x86_l_19c4;
	case 6601ULL: goto x86_l_19c9;
	case 6606ULL: goto x86_l_19ce;
	case 6608ULL: goto x86_l_19d0;
	case 6612ULL: goto x86_l_19d4;
	case 6619ULL: goto x86_l_19db;
	case 6627ULL: goto x86_l_19e3;
	case 6632ULL: goto x86_l_19e8;
	case 6637ULL: goto x86_l_19ed;
	case 6639ULL: goto x86_l_19ef;
	case 6643ULL: goto x86_l_19f3;
	case 6650ULL: goto x86_l_19fa;
	case 6658ULL: goto x86_l_1a02;
	case 6663ULL: goto x86_l_1a07;
	case 6668ULL: goto x86_l_1a0c;
	case 6670ULL: goto x86_l_1a0e;
	case 6674ULL: goto x86_l_1a12;
	case 6681ULL: goto x86_l_1a19;
	case 6689ULL: goto x86_l_1a21;
	case 6694ULL: goto x86_l_1a26;
	case 6699ULL: goto x86_l_1a2b;
	case 6701ULL: goto x86_l_1a2d;
	case 6705ULL: goto x86_l_1a31;
	case 6710ULL: goto x86_l_1a36;
	case 6715ULL: goto x86_l_1a3b;
	case 6720ULL: goto x86_l_1a40;
	case 6725ULL: goto x86_l_1a45;
	case 6730ULL: goto x86_l_1a4a;
	case 6732ULL: goto x86_l_1a4c;
	case 6736ULL: goto x86_l_1a50;
	case 6743ULL: goto x86_l_1a57;
	case 6748ULL: goto x86_l_1a5c;
	case 6753ULL: goto x86_l_1a61;
	case 6758ULL: goto x86_l_1a66;
	case 6760ULL: goto x86_l_1a68;
	case 6764ULL: goto x86_l_1a6c;
	case 6771ULL: goto x86_l_1a73;
	case 6776ULL: goto x86_l_1a78;
	case 6781ULL: goto x86_l_1a7d;
	case 6786ULL: goto x86_l_1a82;
	case 6788ULL: goto x86_l_1a84;
	case 6792ULL: goto x86_l_1a88;
	case 6799ULL: goto x86_l_1a8f;
	case 6804ULL: goto x86_l_1a94;
	case 6809ULL: goto x86_l_1a99;
	case 6814ULL: goto x86_l_1a9e;
	case 6816ULL: goto x86_l_1aa0;
	case 6820ULL: goto x86_l_1aa4;
	case 6827ULL: goto x86_l_1aab;
	case 6832ULL: goto x86_l_1ab0;
	case 6837ULL: goto x86_l_1ab5;
	case 6842ULL: goto x86_l_1aba;
	case 6844ULL: goto x86_l_1abc;
	case 6848ULL: goto x86_l_1ac0;
	case 6853ULL: goto x86_l_1ac5;
	case 6858ULL: goto x86_l_1aca;
	case 6863ULL: goto x86_l_1acf;
	case 6868ULL: goto x86_l_1ad4;
	case 6871ULL: goto x86_l_1ad7;
	case 6873ULL: goto x86_l_1ad9;
	case 6877ULL: goto x86_l_1add;
	case 6884ULL: goto x86_l_1ae4;
	case 6889ULL: goto x86_l_1ae9;
	case 6894ULL: goto x86_l_1aee;
	case 6899ULL: goto x86_l_1af3;
	case 6901ULL: goto x86_l_1af5;
	case 6905ULL: goto x86_l_1af9;
	case 6912ULL: goto x86_l_1b00;
	case 6917ULL: goto x86_l_1b05;
	case 6922ULL: goto x86_l_1b0a;
	case 6924ULL: goto x86_l_1b0c;
	case 6929ULL: goto x86_l_1b11;
	case 6934ULL: goto x86_l_1b16;
	case 6939ULL: goto x86_l_1b1b;
	case 6944ULL: goto x86_l_1b20;
	case 6946ULL: goto x86_l_1b22;
	case 6950ULL: goto x86_l_1b26;
	case 6954ULL: goto x86_l_1b2a;
	case 6960ULL: goto x86_l_1b30;
	case 6965ULL: goto x86_l_1b35;
	case 6970ULL: goto x86_l_1b3a;
	case 6975ULL: goto x86_l_1b3f;
	case 6980ULL: goto x86_l_1b44;
	case 6982ULL: goto x86_l_1b46;
	case 6986ULL: goto x86_l_1b4a;
	case 6990ULL: goto x86_l_1b4e;
	case 6996ULL: goto x86_l_1b54;
	case 7001ULL: goto x86_l_1b59;
	case 7006ULL: goto x86_l_1b5e;
	case 7011ULL: goto x86_l_1b63;
	case 7016ULL: goto x86_l_1b68;
	case 7018ULL: goto x86_l_1b6a;
	case 7022ULL: goto x86_l_1b6e;
	case 7029ULL: goto x86_l_1b75;
	case 7034ULL: goto x86_l_1b7a;
	case 7039ULL: goto x86_l_1b7f;
	case 7044ULL: goto x86_l_1b84;
	case 7049ULL: goto x86_l_1b89;
	case 7051ULL: goto x86_l_1b8b;
	case 7055ULL: goto x86_l_1b8f;
	case 7060ULL: goto x86_l_1b94;
	case 7065ULL: goto x86_l_1b99;
	case 7068ULL: goto x86_l_1b9c;
	case 7076ULL: goto x86_l_1ba4;
	case 7084ULL: goto x86_l_1bac;
	case 7092ULL: goto x86_l_1bb4;
	case 7100ULL: goto x86_l_1bbc;
	case 7108ULL: goto x86_l_1bc4;
	case 7116ULL: goto x86_l_1bcc;
	case 7124ULL: goto x86_l_1bd4;
	case 7132ULL: goto x86_l_1bdc;
	case 7140ULL: goto x86_l_1be4;
	case 7145ULL: goto x86_l_1be9;
	case 7152ULL: goto x86_l_1bf0;
	case 7157ULL: goto x86_l_1bf5;
	case 7162ULL: goto x86_l_1bfa;
	case 7167ULL: goto x86_l_1bff;
	case 7170ULL: goto x86_l_1c02;
	case 7173ULL: goto x86_l_1c05;
	case 7175ULL: goto x86_l_1c07;
	case 7178ULL: goto x86_l_1c0a;
	case 7184ULL: goto x86_l_1c10;
	case 7186ULL: goto x86_l_1c12;
	case 7190ULL: goto x86_l_1c16;
	case 7193ULL: goto x86_l_1c19;
	case 7196ULL: goto x86_l_1c1c;
	case 7201ULL: goto x86_l_1c21;
	case 7208ULL: goto x86_l_1c28;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1532:
	/* 0x1532: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1537:
	/* 0x1537: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_153e:
	/* 0x153e: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1543:
	/* 0x1543: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1545:
	/* 0x1545: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1548:
	/* 0x1548: je     1c21 <generic_fexit_event+0x1c21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c21;
	}
x86_l_154e:
	/* 0x154e: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1550:
	/* 0x1550: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1555:
	/* 0x1555: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_155a:
	/* 0x155a: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_155f:
	/* 0x155f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1564:
	/* 0x1564: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1567:
	/* 0x1567: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1569:
	/* 0x1569: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_156f:
	/* 0x156f: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1573:
	/* 0x1573: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_157a:
	/* 0x157a: lea    esi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_157d:
	/* 0x157d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1582:
	/* 0x1582: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1585:
	/* 0x1585: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1587:
	/* 0x1587: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_158c:
	/* 0x158c: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1590:
	/* 0x1590: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1594:
	/* 0x1594: lea    rdx,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1598:
	/* 0x1598: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_159c:
	/* 0x159c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15a1:
	/* 0x15a1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15a6:
	/* 0x15a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15a8:
	/* 0x15a8: add    rbp,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_15ac:
	/* 0x15ac: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15b0:
	/* 0x15b0: jmp    356a <generic_fexit_event+0x356a> */
	return 13674ULL;
x86_l_15b5:
	/* 0x15b5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15ba:
	/* 0x15ba: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15bf:
	/* 0x15bf: lea    rbx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15c4:
	/* 0x15c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15c9:
	/* 0x15c9: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_15cc:
	/* 0x15cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ce:
	/* 0x15ce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15d3:
	/* 0x15d3: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15d8:
	/* 0x15d8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_15db:
	/* 0x15db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15e0:
	/* 0x15e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15e2:
	/* 0x15e2: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15e6:
	/* 0x15e6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15eb:
	/* 0x15eb: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_15ee:
	/* 0x15ee: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_15f5:
	/* 0x15f5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_15fa:
	/* 0x15fa: mov    esi,0x91 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 145ULL);
x86_l_15ff:
	/* 0x15ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1601:
	/* 0x1601: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1604:
	/* 0x1604: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1607:
	/* 0x1607: jns    163b <generic_fexit_event+0x163b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_163b;
	}
x86_l_1609:
	/* 0x1609: jmp    1c28 <generic_fexit_event+0x1c28> */
	goto x86_l_1c28;
x86_l_160e:
	/* 0x160e: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_1613:
	/* 0x1613: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1618:
	/* 0x1618: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_161c:
	/* 0x161c: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_1623:
	/* 0x1623: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1628:
	/* 0x1628: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_162d:
	/* 0x162d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_162f:
	/* 0x162f: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1632:
	/* 0x1632: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1635:
	/* 0x1635: js     1c28 <generic_fexit_event+0x1c28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1c28;
	}
x86_l_163b:
	/* 0x163b: lea    eax,[rbp-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_163e:
	/* 0x163e: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1643:
	/* 0x1643: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1645:
	/* 0x1645: add    rbp,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_1649:
	/* 0x1649: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_164d:
	/* 0x164d: jmp    356a <generic_fexit_event+0x356a> */
	return 13674ULL;
x86_l_1652:
	/* 0x1652: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1655:
	/* 0x1655: cmp    QWORD PTR [rsp+0xa0],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767363ULL);
x86_l_165e:
	/* 0x165e: jb     173b <generic_fexit_event+0x173b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_173b;
	}
x86_l_1664:
	/* 0x1664: mov    QWORD PTR [rsp],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1668:
	/* 0x1668: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1670:
	/* 0x1670: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1674:
	/* 0x1674: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_167a:
	/* 0x167a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_167f:
	/* 0x167f: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1684:
	/* 0x1684: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1689:
	/* 0x1689: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_168b:
	/* 0x168b: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1690:
	/* 0x1690: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1692:
	/* 0x1692: js     1717 <generic_fexit_event+0x1717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1717;
	}
x86_l_1698:
	/* 0x1698: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_169d:
	/* 0x169d: cmp    rbx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_16a0:
	/* 0x16a0: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_16a3:
	/* 0x16a3: cmovb  r12,rbx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBX, X86_WIDTH_64, X86_CC_B);
x86_l_16a7:
	/* 0x16a7: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_16aa:
	/* 0x16aa: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16af:
	/* 0x16af: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16b2:
	/* 0x16b2: cmovne rbx,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_16b6:
	/* 0x16b6: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_16bb:
	/* 0x16bb: cmp    rbx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 4094ULL);
x86_l_16c2:
	/* 0x16c2: ja     1717 <generic_fexit_event+0x1717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1717;
	}
x86_l_16c4:
	/* 0x16c4: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_16c7:
	/* 0x16c7: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_16cc:
	/* 0x16cc: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_16cf:
	/* 0x16cf: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_16d5:
	/* 0x16d5: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16d8:
	/* 0x16d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16dd:
	/* 0x16dd: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16e2:
	/* 0x16e2: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_16e4:
	/* 0x16e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16e6:
	/* 0x16e6: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_16eb:
	/* 0x16eb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16ed:
	/* 0x16ed: js     1717 <generic_fexit_event+0x1717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1717;
	}
x86_l_16ef:
	/* 0x16ef: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16f4:
	/* 0x16f4: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_16f7:
	/* 0x16f7: add    QWORD PTR [rsp],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_16fb:
	/* 0x16fb: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1701:
	/* 0x1701: je     225f <generic_fexit_event+0x225f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8799ULL;
	}
x86_l_1707:
	/* 0x1707: sub    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_170c:
	/* 0x170c: jne    2266 <generic_fexit_event+0x2266> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8806ULL;
	}
x86_l_1712:
	/* 0x1712: jmp    2271 <generic_fexit_event+0x2271> */
	return 8817ULL;
x86_l_1717:
	/* 0x1717: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_171f:
	/* 0x171f: mov    DWORD PTR [r15+rax*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1723:
	/* 0x1723: add    r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1726:
	/* 0x1726: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_1729:
	/* 0x1729: mov    rbp,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1731:
	/* 0x1731: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1736:
	/* 0x1736: jmp    364c <generic_fexit_event+0x364c> */
	return 13900ULL;
x86_l_173b:
	/* 0x173b: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_173e:
	/* 0x173e: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1746:
	/* 0x1746: jmp    2b1 <generic_fexit_event+0x2b1> */
	return 689ULL;
x86_l_174b:
	/* 0x174b: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1750:
	/* 0x1750: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1759:
	/* 0x1759: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1762:
	/* 0x1762: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1767:
	/* 0x1767: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_176c:
	/* 0x176c: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1771:
	/* 0x1771: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1776:
	/* 0x1776: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_177b:
	/* 0x177b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_177d:
	/* 0x177d: mov    rbx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1782:
	/* 0x1782: cmp    rbx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 4095ULL);
x86_l_1789:
	/* 0x1789: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_178c:
	/* 0x178c: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_1792:
	/* 0x1792: cmovb  r12,rbx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBX, X86_WIDTH_64, X86_CC_B);
x86_l_1796:
	/* 0x1796: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1799:
	/* 0x1799: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_17a0:
	/* 0x17a0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17a5:
	/* 0x17a5: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_17a8:
	/* 0x17a8: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_17ab:
	/* 0x17ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ad:
	/* 0x17ad: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_17b2:
	/* 0x17b2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17b4:
	/* 0x17b4: js     17c6 <generic_fexit_event+0x17c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_17c6;
	}
x86_l_17b6:
	/* 0x17b6: mov    DWORD PTR [r13+0xa0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_17bd:
	/* 0x17bd: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_17c1:
	/* 0x17c1: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_17c3:
	/* 0x17c3: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_17c6:
	/* 0x17c6: mov    DWORD PTR [r13+0x9c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_17cd:
	/* 0x17cd: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17d1:
	/* 0x17d1: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_17d4:
	/* 0x17d4: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17d9:
	/* 0x17d9: jmp    10e7 <generic_fexit_event+0x10e7> */
	return 4327ULL;
x86_l_17de:
	/* 0x17de: lea    rbp,[rcx+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_17e5:
	/* 0x17e5: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17ea:
	/* 0x17ea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17ef:
	/* 0x17ef: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17f4:
	/* 0x17f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f6:
	/* 0x17f6: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17fa:
	/* 0x17fa: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1801:
	/* 0x1801: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1806:
	/* 0x1806: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_180b:
	/* 0x180b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1810:
	/* 0x1810: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1812:
	/* 0x1812: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1816:
	/* 0x1816: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_181d:
	/* 0x181d: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1822:
	/* 0x1822: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1827:
	/* 0x1827: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_182c:
	/* 0x182c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_182e:
	/* 0x182e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1832:
	/* 0x1832: lea    rdi,[rax+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1839:
	/* 0x1839: lea    rdx,[r12+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_183e:
	/* 0x183e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1843:
	/* 0x1843: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1848:
	/* 0x1848: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_184a:
	/* 0x184a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_184e:
	/* 0x184e: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1855:
	/* 0x1855: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_185a:
	/* 0x185a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_185f:
	/* 0x185f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1864:
	/* 0x1864: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1866:
	/* 0x1866: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_186a:
	/* 0x186a: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1871:
	/* 0x1871: lea    rdx,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1876:
	/* 0x1876: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_187b:
	/* 0x187b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1880:
	/* 0x1880: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1882:
	/* 0x1882: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1886:
	/* 0x1886: lea    rdi,[rax+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_188d:
	/* 0x188d: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1892:
	/* 0x1892: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1897:
	/* 0x1897: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_189c:
	/* 0x189c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_189e:
	/* 0x189e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18a2:
	/* 0x18a2: lea    rdi,[rax+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_18a9:
	/* 0x18a9: lea    rdx,[r12+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_18ae:
	/* 0x18ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18b3:
	/* 0x18b3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18b8:
	/* 0x18b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ba:
	/* 0x18ba: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18be:
	/* 0x18be: mov    DWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_18c8:
	/* 0x18c8: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18cc:
	/* 0x18cc: lea    rdi,[rax+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_18d3:
	/* 0x18d3: lea    rdx,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18d8:
	/* 0x18d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18dd:
	/* 0x18dd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18e2:
	/* 0x18e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e4:
	/* 0x18e4: mov    rcx,QWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18e9:
	/* 0x18e9: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18ed:
	/* 0x18ed: mov    QWORD PTR [rax+0xcc],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_18f4:
	/* 0x18f4: mov    rcx,QWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18f9:
	/* 0x18f9: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18fd:
	/* 0x18fd: mov    QWORD PTR [rax+0xd4],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_1904:
	/* 0x1904: mov    rcx,QWORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1909:
	/* 0x1909: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_190d:
	/* 0x190d: mov    QWORD PTR [rax+0xc4],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1914:
	/* 0x1914: lea    rdx,[r12+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_191c:
	/* 0x191c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1921:
	/* 0x1921: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1926:
	/* 0x1926: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_192b:
	/* 0x192b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_192d:
	/* 0x192d: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_1930:
	/* 0x1930: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1935:
	/* 0x1935: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_193d:
	/* 0x193d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1942:
	/* 0x1942: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1945:
	/* 0x1945: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_194a:
	/* 0x194a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_194c:
	/* 0x194c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1950:
	/* 0x1950: lea    rdi,[rax+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1957:
	/* 0x1957: lea    rdx,[r12+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_195f:
	/* 0x195f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1964:
	/* 0x1964: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1969:
	/* 0x1969: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_196b:
	/* 0x196b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_196f:
	/* 0x196f: lea    rdi,[rax+0xe4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_1976:
	/* 0x1976: lea    rdx,[r12+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_197e:
	/* 0x197e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1983:
	/* 0x1983: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1988:
	/* 0x1988: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_198a:
	/* 0x198a: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_198e:
	/* 0x198e: add    rdi,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1995:
	/* 0x1995: add    r12,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_199c:
	/* 0x199c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19a1:
	/* 0x19a1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19a6:
	/* 0x19a6: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_19a9:
	/* 0x19a9: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_19ac:
	/* 0x19ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19ae:
	/* 0x19ae: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19b2:
	/* 0x19b2: mov    ebp,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 80ULL);
x86_l_19b7:
	/* 0x19b7: jmp    10e7 <generic_fexit_event+0x10e7> */
	return 4327ULL;
x86_l_19bc:
	/* 0x19bc: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_19c4:
	/* 0x19c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19c9:
	/* 0x19c9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19ce:
	/* 0x19ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d0:
	/* 0x19d0: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19d4:
	/* 0x19d4: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_19db:
	/* 0x19db: lea    rdx,[r12+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_19e3:
	/* 0x19e3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19e8:
	/* 0x19e8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19ed:
	/* 0x19ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19ef:
	/* 0x19ef: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19f3:
	/* 0x19f3: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_19fa:
	/* 0x19fa: lea    rdx,[r12+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1a02:
	/* 0x1a02: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a07:
	/* 0x1a07: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a0c:
	/* 0x1a0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a0e:
	/* 0x1a0e: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a12:
	/* 0x1a12: add    rdi,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_1a19:
	/* 0x1a19: lea    rdx,[r12+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1a21:
	/* 0x1a21: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a26:
	/* 0x1a26: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a2b:
	/* 0x1a2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a2d:
	/* 0x1a2d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a31:
	/* 0x1a31: mov    ebp,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_1a36:
	/* 0x1a36: jmp    10e7 <generic_fexit_event+0x10e7> */
	return 4327ULL;
x86_l_1a3b:
	/* 0x1a3b: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a40:
	/* 0x1a40: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a45:
	/* 0x1a45: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a4a:
	/* 0x1a4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a4c:
	/* 0x1a4c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a50:
	/* 0x1a50: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1a57:
	/* 0x1a57: lea    rdx,[r12+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a5c:
	/* 0x1a5c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a61:
	/* 0x1a61: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a66:
	/* 0x1a66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a68:
	/* 0x1a68: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a6c:
	/* 0x1a6c: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1a73:
	/* 0x1a73: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a78:
	/* 0x1a78: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a7d:
	/* 0x1a7d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a82:
	/* 0x1a82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a84:
	/* 0x1a84: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a88:
	/* 0x1a88: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1a8f:
	/* 0x1a8f: lea    rdx,[r12+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a94:
	/* 0x1a94: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a99:
	/* 0x1a99: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a9e:
	/* 0x1a9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa0:
	/* 0x1aa0: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aa4:
	/* 0x1aa4: add    rdi,0xac */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 172ULL);
x86_l_1aab:
	/* 0x1aab: lea    rdx,[r12+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1ab0:
	/* 0x1ab0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ab5:
	/* 0x1ab5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1aba:
	/* 0x1aba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1abc:
	/* 0x1abc: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ac0:
	/* 0x1ac0: mov    ebp,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 32ULL);
x86_l_1ac5:
	/* 0x1ac5: jmp    10e7 <generic_fexit_event+0x10e7> */
	return 4327ULL;
x86_l_1aca:
	/* 0x1aca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1acf:
	/* 0x1acf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ad4:
	/* 0x1ad4: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1ad7:
	/* 0x1ad7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad9:
	/* 0x1ad9: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1add:
	/* 0x1add: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1ae4:
	/* 0x1ae4: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ae9:
	/* 0x1ae9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1aee:
	/* 0x1aee: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1af3:
	/* 0x1af3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af5:
	/* 0x1af5: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1af9:
	/* 0x1af9: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1b00:
	/* 0x1b00: lea    rdx,[r12+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b05:
	/* 0x1b05: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b0a:
	/* 0x1b0a: jmp    1b84 <generic_fexit_event+0x1b84> */
	goto x86_l_1b84;
x86_l_1b0c:
	/* 0x1b0c: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b11:
	/* 0x1b11: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b16:
	/* 0x1b16: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b1b:
	/* 0x1b1b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b20:
	/* 0x1b20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b22:
	/* 0x1b22: mov    ecx,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b26:
	/* 0x1b26: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b2a:
	/* 0x1b2a: mov    DWORD PTR [rax+0x9c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1b30:
	/* 0x1b30: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b35:
	/* 0x1b35: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b3a:
	/* 0x1b3a: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b3f:
	/* 0x1b3f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b44:
	/* 0x1b44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b46:
	/* 0x1b46: mov    ecx,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b4a:
	/* 0x1b4a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b4e:
	/* 0x1b4e: mov    DWORD PTR [rax+0xa0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1b54:
	/* 0x1b54: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b59:
	/* 0x1b59: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b5e:
	/* 0x1b5e: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b63:
	/* 0x1b63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b68:
	/* 0x1b68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b6a:
	/* 0x1b6a: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b6e:
	/* 0x1b6e: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1b75:
	/* 0x1b75: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1b7a:
	/* 0x1b7a: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_1b7f:
	/* 0x1b7f: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_1b84:
	/* 0x1b84: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b89:
	/* 0x1b89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b8b:
	/* 0x1b8b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b8f:
	/* 0x1b8f: mov    ebp,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_1b94:
	/* 0x1b94: jmp    10e7 <generic_fexit_event+0x10e7> */
	return 4327ULL;
x86_l_1b99:
	/* 0x1b99: mov    r13,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_64);
x86_l_1b9c:
	/* 0x1b9c: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1ba4:
	/* 0x1ba4: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1bac:
	/* 0x1bac: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1bb4:
	/* 0x1bb4: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1bbc:
	/* 0x1bbc: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1bc4:
	/* 0x1bc4: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1bcc:
	/* 0x1bcc: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1bd4:
	/* 0x1bd4: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1bdc:
	/* 0x1bdc: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1be4:
	/* 0x1be4: mov    QWORD PTR [rsp+0x68],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1be9:
	/* 0x1be9: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bf0:
	/* 0x1bf0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bf5:
	/* 0x1bf5: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bfa:
	/* 0x1bfa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bff:
	/* 0x1bff: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_1c02:
	/* 0x1c02: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1c05:
	/* 0x1c05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c07:
	/* 0x1c07: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c0a:
	/* 0x1c0a: je     1f48 <generic_fexit_event+0x1f48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8008ULL;
	}
x86_l_1c10:
	/* 0x1c10: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c12:
	/* 0x1c12: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c16:
	/* 0x1c16: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_1c19:
	/* 0x1c19: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_1c1c:
	/* 0x1c1c: jmp    10e7 <generic_fexit_event+0x10e7> */
	return 4327ULL;
x86_l_1c21:
	/* 0x1c21: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1c28:
	/* 0x1c28: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 7212ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7212ULL: goto x86_l_1c2c;
	case 7217ULL: goto x86_l_1c31;
	case 7222ULL: goto x86_l_1c36;
	case 7227ULL: goto x86_l_1c3b;
	case 7235ULL: goto x86_l_1c43;
	case 7240ULL: goto x86_l_1c48;
	case 7244ULL: goto x86_l_1c4c;
	case 7252ULL: goto x86_l_1c54;
	case 7257ULL: goto x86_l_1c59;
	case 7264ULL: goto x86_l_1c60;
	case 7269ULL: goto x86_l_1c65;
	case 7271ULL: goto x86_l_1c67;
	case 7274ULL: goto x86_l_1c6a;
	case 7280ULL: goto x86_l_1c70;
	case 7283ULL: goto x86_l_1c73;
	case 7288ULL: goto x86_l_1c78;
	case 7294ULL: goto x86_l_1c7e;
	case 7300ULL: goto x86_l_1c84;
	case 7303ULL: goto x86_l_1c87;
	case 7307ULL: goto x86_l_1c8b;
	case 7311ULL: goto x86_l_1c8f;
	case 7316ULL: goto x86_l_1c94;
	case 7319ULL: goto x86_l_1c97;
	case 7324ULL: goto x86_l_1c9c;
	case 7326ULL: goto x86_l_1c9e;
	case 7329ULL: goto x86_l_1ca1;
	case 7335ULL: goto x86_l_1ca7;
	case 7341ULL: goto x86_l_1cad;
	case 7344ULL: goto x86_l_1cb0;
	case 7350ULL: goto x86_l_1cb6;
	case 7352ULL: goto x86_l_1cb8;
	case 7358ULL: goto x86_l_1cbe;
	case 7361ULL: goto x86_l_1cc1;
	case 7367ULL: goto x86_l_1cc7;
	case 7370ULL: goto x86_l_1cca;
	case 7376ULL: goto x86_l_1cd0;
	case 7384ULL: goto x86_l_1cd8;
	case 7388ULL: goto x86_l_1cdc;
	case 7393ULL: goto x86_l_1ce1;
	case 7397ULL: goto x86_l_1ce5;
	case 7402ULL: goto x86_l_1cea;
	case 7407ULL: goto x86_l_1cef;
	case 7409ULL: goto x86_l_1cf1;
	case 7413ULL: goto x86_l_1cf5;
	case 7418ULL: goto x86_l_1cfa;
	case 7421ULL: goto x86_l_1cfd;
	case 7426ULL: goto x86_l_1d02;
	case 7428ULL: goto x86_l_1d04;
	case 7432ULL: goto x86_l_1d08;
	case 7439ULL: goto x86_l_1d0f;
	case 7443ULL: goto x86_l_1d13;
	case 7447ULL: goto x86_l_1d17;
	case 7452ULL: goto x86_l_1d1c;
	case 7457ULL: goto x86_l_1d21;
	case 7460ULL: goto x86_l_1d24;
	case 7462ULL: goto x86_l_1d26;
	case 7466ULL: goto x86_l_1d2a;
	case 7473ULL: goto x86_l_1d31;
	case 7478ULL: goto x86_l_1d36;
	case 7483ULL: goto x86_l_1d3b;
	case 7486ULL: goto x86_l_1d3e;
	case 7488ULL: goto x86_l_1d40;
	case 7492ULL: goto x86_l_1d44;
	case 7499ULL: goto x86_l_1d4b;
	case 7508ULL: goto x86_l_1d54;
	case 7513ULL: goto x86_l_1d59;
	case 7516ULL: goto x86_l_1d5c;
	case 7521ULL: goto x86_l_1d61;
	case 7526ULL: goto x86_l_1d66;
	case 7531ULL: goto x86_l_1d6b;
	case 7536ULL: goto x86_l_1d70;
	case 7541ULL: goto x86_l_1d75;
	case 7543ULL: goto x86_l_1d77;
	case 7548ULL: goto x86_l_1d7c;
	case 7553ULL: goto x86_l_1d81;
	case 7559ULL: goto x86_l_1d87;
	case 7563ULL: goto x86_l_1d8b;
	case 7568ULL: goto x86_l_1d90;
	case 7573ULL: goto x86_l_1d95;
	case 7578ULL: goto x86_l_1d9a;
	case 7581ULL: goto x86_l_1d9d;
	case 7583ULL: goto x86_l_1d9f;
	case 7588ULL: goto x86_l_1da4;
	case 7593ULL: goto x86_l_1da9;
	case 7598ULL: goto x86_l_1dae;
	case 7603ULL: goto x86_l_1db3;
	case 7608ULL: goto x86_l_1db8;
	case 7613ULL: goto x86_l_1dbd;
	case 7615ULL: goto x86_l_1dbf;
	case 7620ULL: goto x86_l_1dc4;
	case 7626ULL: goto x86_l_1dca;
	case 7631ULL: goto x86_l_1dcf;
	case 7634ULL: goto x86_l_1dd2;
	case 7639ULL: goto x86_l_1dd7;
	case 7647ULL: goto x86_l_1ddf;
	case 7652ULL: goto x86_l_1de4;
	case 7654ULL: goto x86_l_1de6;
	case 7662ULL: goto x86_l_1dee;
	case 7668ULL: goto x86_l_1df4;
	case 7672ULL: goto x86_l_1df8;
	case 7677ULL: goto x86_l_1dfd;
	case 7682ULL: goto x86_l_1e02;
	case 7687ULL: goto x86_l_1e07;
	case 7690ULL: goto x86_l_1e0a;
	case 7692ULL: goto x86_l_1e0c;
	case 7697ULL: goto x86_l_1e11;
	case 7703ULL: goto x86_l_1e17;
	case 7708ULL: goto x86_l_1e1c;
	case 7716ULL: goto x86_l_1e24;
	case 7721ULL: goto x86_l_1e29;
	case 7724ULL: goto x86_l_1e2c;
	case 7726ULL: goto x86_l_1e2e;
	case 7730ULL: goto x86_l_1e32;
	case 7735ULL: goto x86_l_1e37;
	case 7740ULL: goto x86_l_1e3c;
	case 7745ULL: goto x86_l_1e41;
	case 7748ULL: goto x86_l_1e44;
	case 7750ULL: goto x86_l_1e46;
	case 7755ULL: goto x86_l_1e4b;
	case 7760ULL: goto x86_l_1e50;
	case 7764ULL: goto x86_l_1e54;
	case 7767ULL: goto x86_l_1e57;
	case 7771ULL: goto x86_l_1e5b;
	case 7773ULL: goto x86_l_1e5d;
	case 7775ULL: goto x86_l_1e5f;
	case 7777ULL: goto x86_l_1e61;
	case 7780ULL: goto x86_l_1e64;
	case 7785ULL: goto x86_l_1e69;
	case 7788ULL: goto x86_l_1e6c;
	case 7790ULL: goto x86_l_1e6e;
	case 7794ULL: goto x86_l_1e72;
	case 7796ULL: goto x86_l_1e74;
	case 7799ULL: goto x86_l_1e77;
	case 7802ULL: goto x86_l_1e7a;
	case 7805ULL: goto x86_l_1e7d;
	case 7808ULL: goto x86_l_1e80;
	case 7813ULL: goto x86_l_1e85;
	case 7816ULL: goto x86_l_1e88;
	case 7821ULL: goto x86_l_1e8d;
	case 7824ULL: goto x86_l_1e90;
	case 7829ULL: goto x86_l_1e95;
	case 7834ULL: goto x86_l_1e9a;
	case 7840ULL: goto x86_l_1ea0;
	case 7847ULL: goto x86_l_1ea7;
	case 7853ULL: goto x86_l_1ead;
	case 7855ULL: goto x86_l_1eaf;
	case 7861ULL: goto x86_l_1eb5;
	case 7865ULL: goto x86_l_1eb9;
	case 7869ULL: goto x86_l_1ebd;
	case 7872ULL: goto x86_l_1ec0;
	case 7876ULL: goto x86_l_1ec4;
	case 7879ULL: goto x86_l_1ec7;
	case 7884ULL: goto x86_l_1ecc;
	case 7886ULL: goto x86_l_1ece;
	case 7891ULL: goto x86_l_1ed3;
	case 7899ULL: goto x86_l_1edb;
	case 7904ULL: goto x86_l_1ee0;
	case 7909ULL: goto x86_l_1ee5;
	case 7914ULL: goto x86_l_1eea;
	case 7919ULL: goto x86_l_1eef;
	case 7926ULL: goto x86_l_1ef6;
	case 7931ULL: goto x86_l_1efb;
	case 7936ULL: goto x86_l_1f00;
	case 7941ULL: goto x86_l_1f05;
	case 7944ULL: goto x86_l_1f08;
	case 7946ULL: goto x86_l_1f0a;
	case 7949ULL: goto x86_l_1f0d;
	case 7956ULL: goto x86_l_1f14;
	case 7960ULL: goto x86_l_1f18;
	case 7965ULL: goto x86_l_1f1d;
	case 7970ULL: goto x86_l_1f22;
	case 7973ULL: goto x86_l_1f25;
	case 7975ULL: goto x86_l_1f27;
	case 7979ULL: goto x86_l_1f2b;
	case 7986ULL: goto x86_l_1f32;
	case 7995ULL: goto x86_l_1f3b;
	case 8000ULL: goto x86_l_1f40;
	case 8003ULL: goto x86_l_1f43;
	case 8008ULL: goto x86_l_1f48;
	case 8012ULL: goto x86_l_1f4c;
	case 8019ULL: goto x86_l_1f53;
	case 8024ULL: goto x86_l_1f58;
	case 8029ULL: goto x86_l_1f5d;
	case 8034ULL: goto x86_l_1f62;
	case 8036ULL: goto x86_l_1f64;
	case 8039ULL: goto x86_l_1f67;
	case 8045ULL: goto x86_l_1f6d;
	case 8048ULL: goto x86_l_1f70;
	case 8052ULL: goto x86_l_1f74;
	case 8057ULL: goto x86_l_1f79;
	case 8062ULL: goto x86_l_1f7e;
	case 8067ULL: goto x86_l_1f83;
	case 8069ULL: goto x86_l_1f85;
	case 8073ULL: goto x86_l_1f89;
	case 8080ULL: goto x86_l_1f90;
	case 8085ULL: goto x86_l_1f95;
	case 8090ULL: goto x86_l_1f9a;
	case 8095ULL: goto x86_l_1f9f;
	case 8100ULL: goto x86_l_1fa4;
	case 8102ULL: goto x86_l_1fa6;
	case 8106ULL: goto x86_l_1faa;
	case 8111ULL: goto x86_l_1faf;
	case 8116ULL: goto x86_l_1fb4;
	case 8121ULL: goto x86_l_1fb9;
	case 8123ULL: goto x86_l_1fbb;
	case 8128ULL: goto x86_l_1fc0;
	case 8131ULL: goto x86_l_1fc3;
	case 8137ULL: goto x86_l_1fc9;
	case 8139ULL: goto x86_l_1fcb;
	case 8144ULL: goto x86_l_1fd0;
	case 8147ULL: goto x86_l_1fd3;
	case 8152ULL: goto x86_l_1fd8;
	case 8154ULL: goto x86_l_1fda;
	case 8159ULL: goto x86_l_1fdf;
	case 8164ULL: goto x86_l_1fe4;
	case 8169ULL: goto x86_l_1fe9;
	case 8172ULL: goto x86_l_1fec;
	case 8175ULL: goto x86_l_1fef;
	case 8180ULL: goto x86_l_1ff4;
	case 8183ULL: goto x86_l_1ff7;
	case 8185ULL: goto x86_l_1ff9;
	case 8190ULL: goto x86_l_1ffe;
	case 8194ULL: goto x86_l_2002;
	case 8199ULL: goto x86_l_2007;
	case 8203ULL: goto x86_l_200b;
	case 8208ULL: goto x86_l_2010;
	case 8211ULL: goto x86_l_2013;
	case 8216ULL: goto x86_l_2018;
	case 8218ULL: goto x86_l_201a;
	case 8222ULL: goto x86_l_201e;
	case 8227ULL: goto x86_l_2023;
	case 8230ULL: goto x86_l_2026;
	case 8235ULL: goto x86_l_202b;
	case 8237ULL: goto x86_l_202d;
	case 8241ULL: goto x86_l_2031;
	case 8248ULL: goto x86_l_2038;
	case 8252ULL: goto x86_l_203c;
	case 8256ULL: goto x86_l_2040;
	case 8261ULL: goto x86_l_2045;
	case 8266ULL: goto x86_l_204a;
	case 8269ULL: goto x86_l_204d;
	case 8271ULL: goto x86_l_204f;
	case 8274ULL: goto x86_l_2052;
	case 8281ULL: goto x86_l_2059;
	case 8286ULL: goto x86_l_205e;
	case 8291ULL: goto x86_l_2063;
	case 8294ULL: goto x86_l_2066;
	case 8296ULL: goto x86_l_2068;
	case 8299ULL: goto x86_l_206b;
	case 8306ULL: goto x86_l_2072;
	case 8315ULL: goto x86_l_207b;
	case 8320ULL: goto x86_l_2080;
	case 8325ULL: goto x86_l_2085;
	case 8330ULL: goto x86_l_208a;
	case 8333ULL: goto x86_l_208d;
	case 8339ULL: goto x86_l_2093;
	case 8342ULL: goto x86_l_2096;
	case 8344ULL: goto x86_l_2098;
	case 8349ULL: goto x86_l_209d;
	case 8355ULL: goto x86_l_20a3;
	case 8363ULL: goto x86_l_20ab;
	case 8367ULL: goto x86_l_20af;
	case 8372ULL: goto x86_l_20b4;
	case 8375ULL: goto x86_l_20b7;
	case 8381ULL: goto x86_l_20bd;
	case 8388ULL: goto x86_l_20c4;
	case 8393ULL: goto x86_l_20c9;
	case 8398ULL: goto x86_l_20ce;
	case 8403ULL: goto x86_l_20d3;
	case 8408ULL: goto x86_l_20d8;
	case 8413ULL: goto x86_l_20dd;
	case 8415ULL: goto x86_l_20df;
	case 8420ULL: goto x86_l_20e4;
	case 8425ULL: goto x86_l_20e9;
	case 8428ULL: goto x86_l_20ec;
	case 8433ULL: goto x86_l_20f1;
	case 8439ULL: goto x86_l_20f7;
	case 8443ULL: goto x86_l_20fb;
	case 8448ULL: goto x86_l_2100;
	case 8453ULL: goto x86_l_2105;
	case 8458ULL: goto x86_l_210a;
	case 8461ULL: goto x86_l_210d;
	case 8463ULL: goto x86_l_210f;
	case 8468ULL: goto x86_l_2114;
	case 8473ULL: goto x86_l_2119;
	case 8478ULL: goto x86_l_211e;
	case 8483ULL: goto x86_l_2123;
	case 8488ULL: goto x86_l_2128;
	case 8493ULL: goto x86_l_212d;
	case 8498ULL: goto x86_l_2132;
	case 8500ULL: goto x86_l_2134;
	case 8503ULL: goto x86_l_2137;
	case 8508ULL: goto x86_l_213c;
	case 8514ULL: goto x86_l_2142;
	case 8519ULL: goto x86_l_2147;
	case 8527ULL: goto x86_l_214f;
	case 8532ULL: goto x86_l_2154;
	case 8534ULL: goto x86_l_2156;
	case 8542ULL: goto x86_l_215e;
	case 8548ULL: goto x86_l_2164;
	case 8552ULL: goto x86_l_2168;
	case 8557ULL: goto x86_l_216d;
	case 8562ULL: goto x86_l_2172;
	case 8567ULL: goto x86_l_2177;
	case 8570ULL: goto x86_l_217a;
	case 8572ULL: goto x86_l_217c;
	case 8577ULL: goto x86_l_2181;
	case 8583ULL: goto x86_l_2187;
	case 8588ULL: goto x86_l_218c;
	case 8596ULL: goto x86_l_2194;
	case 8601ULL: goto x86_l_2199;
	case 8604ULL: goto x86_l_219c;
	case 8606ULL: goto x86_l_219e;
	case 8610ULL: goto x86_l_21a2;
	case 8615ULL: goto x86_l_21a7;
	case 8620ULL: goto x86_l_21ac;
	case 8625ULL: goto x86_l_21b1;
	case 8628ULL: goto x86_l_21b4;
	case 8630ULL: goto x86_l_21b6;
	case 8635ULL: goto x86_l_21bb;
	case 8640ULL: goto x86_l_21c0;
	case 8644ULL: goto x86_l_21c4;
	case 8647ULL: goto x86_l_21c7;
	case 8651ULL: goto x86_l_21cb;
	case 8653ULL: goto x86_l_21cd;
	case 8655ULL: goto x86_l_21cf;
	case 8657ULL: goto x86_l_21d1;
	case 8660ULL: goto x86_l_21d4;
	case 8665ULL: goto x86_l_21d9;
	case 8668ULL: goto x86_l_21dc;
	case 8670ULL: goto x86_l_21de;
	case 8674ULL: goto x86_l_21e2;
	case 8676ULL: goto x86_l_21e4;
	case 8679ULL: goto x86_l_21e7;
	case 8682ULL: goto x86_l_21ea;
	case 8685ULL: goto x86_l_21ed;
	case 8688ULL: goto x86_l_21f0;
	case 8693ULL: goto x86_l_21f5;
	case 8696ULL: goto x86_l_21f8;
	case 8701ULL: goto x86_l_21fd;
	case 8704ULL: goto x86_l_2200;
	case 8709ULL: goto x86_l_2205;
	case 8714ULL: goto x86_l_220a;
	case 8720ULL: goto x86_l_2210;
	case 8727ULL: goto x86_l_2217;
	case 8733ULL: goto x86_l_221d;
	case 8735ULL: goto x86_l_221f;
	case 8741ULL: goto x86_l_2225;
	case 8745ULL: goto x86_l_2229;
	case 8749ULL: goto x86_l_222d;
	case 8752ULL: goto x86_l_2230;
	case 8756ULL: goto x86_l_2234;
	case 8759ULL: goto x86_l_2237;
	case 8764ULL: goto x86_l_223c;
	case 8766ULL: goto x86_l_223e;
	case 8771ULL: goto x86_l_2243;
	case 8779ULL: goto x86_l_224b;
	case 8784ULL: goto x86_l_2250;
	case 8789ULL: goto x86_l_2255;
	case 8794ULL: goto x86_l_225a;
	case 8799ULL: goto x86_l_225f;
	case 8801ULL: goto x86_l_2261;
	case 8806ULL: goto x86_l_2266;
	case 8815ULL: goto x86_l_226f;
	case 8817ULL: goto x86_l_2271;
	case 8821ULL: goto x86_l_2275;
	case 8826ULL: goto x86_l_227a;
	case 8831ULL: goto x86_l_227f;
	case 8839ULL: goto x86_l_2287;
	case 8843ULL: goto x86_l_228b;
	case 8849ULL: goto x86_l_2291;
	case 8854ULL: goto x86_l_2296;
	case 8859ULL: goto x86_l_229b;
	case 8864ULL: goto x86_l_22a0;
	case 8866ULL: goto x86_l_22a2;
	case 8871ULL: goto x86_l_22a7;
	case 8873ULL: goto x86_l_22a9;
	case 8879ULL: goto x86_l_22af;
	case 8884ULL: goto x86_l_22b4;
	case 8889ULL: goto x86_l_22b9;
	case 8892ULL: goto x86_l_22bc;
	case 8895ULL: goto x86_l_22bf;
	case 8899ULL: goto x86_l_22c3;
	case 8902ULL: goto x86_l_22c6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c2c:
	/* 0x1c2c: jmp    356a <generic_fexit_event+0x356a> */
	return 13674ULL;
x86_l_1c31:
	/* 0x1c31: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c36:
	/* 0x1c36: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c3b:
	/* 0x1c3b: movzx  ebx,WORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 136ULL);
x86_l_1c43:
	/* 0x1c43: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c48:
	/* 0x1c48: lea    r13,[rax+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1c4c:
	/* 0x1c4c: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1c54:
	/* 0x1c54: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c59:
	/* 0x1c59: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_1c60:
	/* 0x1c60: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1c65:
	/* 0x1c65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c67:
	/* 0x1c67: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c6a:
	/* 0x1c6a: je     2e7e <generic_fexit_event+0x2e7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11902ULL;
	}
x86_l_1c70:
	/* 0x1c70: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1c73:
	/* 0x1c73: mov    WORD PTR [r12],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c78:
	/* 0x1c78: mov    BYTE PTR [r12+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_1c7e:
	/* 0x1c7e: mov    BYTE PTR [r12+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_1c84:
	/* 0x1c84: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1c87:
	/* 0x1c87: add    rdi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1c8b:
	/* 0x1c8b: lea    rdx,[r13+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1c8f:
	/* 0x1c8f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c94:
	/* 0x1c94: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_1c97:
	/* 0x1c97: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1c9c:
	/* 0x1c9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c9e:
	/* 0x1c9e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ca1:
	/* 0x1ca1: js     2e7e <generic_fexit_event+0x2e7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11902ULL;
	}
x86_l_1ca7:
	/* 0x1ca7: movzx  eax,BYTE PTR [r12+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_1cad:
	/* 0x1cad: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_1cb0:
	/* 0x1cb0: jg     208a <generic_fexit_event+0x208a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_208a;
	}
x86_l_1cb6:
	/* 0x1cb6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cb8:
	/* 0x1cb8: je     20b4 <generic_fexit_event+0x20b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20b4;
	}
x86_l_1cbe:
	/* 0x1cbe: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1cc1:
	/* 0x1cc1: je     20b4 <generic_fexit_event+0x20b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20b4;
	}
x86_l_1cc7:
	/* 0x1cc7: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1cca:
	/* 0x1cca: jne    240f <generic_fexit_event+0x240f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9231ULL;
	}
x86_l_1cd0:
	/* 0x1cd0: mov    WORD PTR [r12+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_1cd8:
	/* 0x1cd8: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_1cdc:
	/* 0x1cdc: jmp    2344 <generic_fexit_event+0x2344> */
	return 9028ULL;
x86_l_1ce1:
	/* 0x1ce1: lea    rdx,[rbp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1ce5:
	/* 0x1ce5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cea:
	/* 0x1cea: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1cef:
	/* 0x1cef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cf1:
	/* 0x1cf1: lea    rdx,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1cf5:
	/* 0x1cf5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cfa:
	/* 0x1cfa: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1cfd:
	/* 0x1cfd: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d02:
	/* 0x1d02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d04:
	/* 0x1d04: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d08:
	/* 0x1d08: lea    rdi,[rax+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1d0f:
	/* 0x1d0f: lea    r12,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d13:
	/* 0x1d13: add    rbp,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_1d17:
	/* 0x1d17: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d1c:
	/* 0x1d1c: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1d21:
	/* 0x1d21: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1d24:
	/* 0x1d24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d26:
	/* 0x1d26: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d2a:
	/* 0x1d2a: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_1d31:
	/* 0x1d31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d36:
	/* 0x1d36: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1d3b:
	/* 0x1d3b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d3e:
	/* 0x1d3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d40:
	/* 0x1d40: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d44:
	/* 0x1d44: movzx  eax,WORD PTR [rcx+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1d4b:
	/* 0x1d4b: movbe  WORD PTR [rcx+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1d54:
	/* 0x1d54: mov    ebp,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_1d59:
	/* 0x1d59: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_1d5c:
	/* 0x1d5c: jmp    356a <generic_fexit_event+0x356a> */
	return 13674ULL;
x86_l_1d61:
	/* 0x1d61: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d66:
	/* 0x1d66: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d6b:
	/* 0x1d6b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d70:
	/* 0x1d70: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d75:
	/* 0x1d75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d77:
	/* 0x1d77: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d7c:
	/* 0x1d7c: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_1d81:
	/* 0x1d81: je     3496 <generic_fexit_event+0x3496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13462ULL;
	}
x86_l_1d87:
	/* 0x1d87: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1d8b:
	/* 0x1d8b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d90:
	/* 0x1d90: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d95:
	/* 0x1d95: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d9a:
	/* 0x1d9a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d9d:
	/* 0x1d9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d9f:
	/* 0x1d9f: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1da4:
	/* 0x1da4: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1da9:
	/* 0x1da9: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dae:
	/* 0x1dae: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1db3:
	/* 0x1db3: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1db8:
	/* 0x1db8: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1dbd:
	/* 0x1dbd: jne    1dca <generic_fexit_event+0x1dca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1dca;
	}
x86_l_1dbf:
	/* 0x1dbf: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_1dc4:
	/* 0x1dc4: je     677 <generic_fexit_event+0x677> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1655ULL;
	}
x86_l_1dca:
	/* 0x1dca: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dcf:
	/* 0x1dcf: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_1dd2:
	/* 0x1dd2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dd7:
	/* 0x1dd7: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1ddf:
	/* 0x1ddf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1de4:
	/* 0x1de4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de6:
	/* 0x1de6: cmp    r13,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 136ULL);
x86_l_1dee:
	/* 0x1dee: je     20c9 <generic_fexit_event+0x20c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20c9;
	}
x86_l_1df4:
	/* 0x1df4: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1df8:
	/* 0x1df8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dfd:
	/* 0x1dfd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e02:
	/* 0x1e02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e07:
	/* 0x1e07: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1e0a:
	/* 0x1e0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e0c:
	/* 0x1e0c: cmp    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e11:
	/* 0x1e11: je     20c9 <generic_fexit_event+0x20c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20c9;
	}
x86_l_1e17:
	/* 0x1e17: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e1c:
	/* 0x1e1c: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1e24:
	/* 0x1e24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e29:
	/* 0x1e29: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1e2c:
	/* 0x1e2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e2e:
	/* 0x1e2e: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1e32:
	/* 0x1e32: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e37:
	/* 0x1e37: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1e3c:
	/* 0x1e3c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e41:
	/* 0x1e41: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1e44:
	/* 0x1e44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e46:
	/* 0x1e46: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1e4b:
	/* 0x1e4b: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1e50:
	/* 0x1e50: mov    esi,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_1e54:
	/* 0x1e54: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1e57:
	/* 0x1e57: mov    edi,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1e5b:
	/* 0x1e5b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e5d:
	/* 0x1e5d: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1e5f:
	/* 0x1e5f: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1e61:
	/* 0x1e61: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1e64:
	/* 0x1e64: add    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_1e69:
	/* 0x1e69: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e6c:
	/* 0x1e6c: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1e6e:
	/* 0x1e6e: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_1e72:
	/* 0x1e72: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_1e74:
	/* 0x1e74: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_1e77:
	/* 0x1e77: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1e7a:
	/* 0x1e7a: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_1e7d:
	/* 0x1e7d: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1e80:
	/* 0x1e80: mov    DWORD PTR [rsp+0x60],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1e85:
	/* 0x1e85: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1e88:
	/* 0x1e88: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e8d:
	/* 0x1e8d: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_1e90:
	/* 0x1e90: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e95:
	/* 0x1e95: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e9a:
	/* 0x1e9a: jb     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ffe;
	}
x86_l_1ea0:
	/* 0x1ea0: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_1ea7:
	/* 0x1ea7: ja     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ffe;
	}
x86_l_1ead:
	/* 0x1ead: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1eaf:
	/* 0x1eaf: jbe    343b <generic_fexit_event+0x343b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13371ULL;
	}
x86_l_1eb5:
	/* 0x1eb5: lea    r15,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1eb9:
	/* 0x1eb9: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_1ebd:
	/* 0x1ebd: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1ec0:
	/* 0x1ec0: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1ec4:
	/* 0x1ec4: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1ec7:
	/* 0x1ec7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ecc:
	/* 0x1ecc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ece:
	/* 0x1ece: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1ed3:
	/* 0x1ed3: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1edb:
	/* 0x1edb: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ee0:
	/* 0x1ee0: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1ee5:
	/* 0x1ee5: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1eea:
	/* 0x1eea: jmp    2128 <generic_fexit_event+0x2128> */
	goto x86_l_2128;
x86_l_1eef:
	/* 0x1eef: lea    rdi,[rcx+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1ef6:
	/* 0x1ef6: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1efb:
	/* 0x1efb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f00:
	/* 0x1f00: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1f05:
	/* 0x1f05: mov    rbp,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_1f08:
	/* 0x1f08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f0a:
	/* 0x1f0a: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1f0d:
	/* 0x1f0d: add    rdi,0x9e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 158ULL);
x86_l_1f14:
	/* 0x1f14: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1f18:
	/* 0x1f18: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f1d:
	/* 0x1f1d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1f22:
	/* 0x1f22: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f25:
	/* 0x1f25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f27:
	/* 0x1f27: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f2b:
	/* 0x1f2b: movzx  eax,WORD PTR [rcx+0x9e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_1f32:
	/* 0x1f32: movbe  WORD PTR [rcx+0x9e],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_1f3b:
	/* 0x1f3b: mov    ebp,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_1f40:
	/* 0x1f40: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_1f43:
	/* 0x1f43: jmp    356a <generic_fexit_event+0x356a> */
	return 13674ULL;
x86_l_1f48:
	/* 0x1f48: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f4c:
	/* 0x1f4c: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1f53:
	/* 0x1f53: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1f58:
	/* 0x1f58: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f5d:
	/* 0x1f5d: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_1f62:
	/* 0x1f62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f64:
	/* 0x1f64: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f67:
	/* 0x1f67: js     1c10 <generic_fexit_event+0x1c10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7184ULL;
	}
x86_l_1f6d:
	/* 0x1f6d: mov    r14,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBX, X86_WIDTH_64);
x86_l_1f70:
	/* 0x1f70: lea    rdx,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f74:
	/* 0x1f74: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f79:
	/* 0x1f79: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1f7e:
	/* 0x1f7e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f83:
	/* 0x1f83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f85:
	/* 0x1f85: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f89:
	/* 0x1f89: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1f90:
	/* 0x1f90: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f95:
	/* 0x1f95: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_1f9a:
	/* 0x1f9a: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_1f9f:
	/* 0x1f9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fa4:
	/* 0x1fa4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fa6:
	/* 0x1fa6: lea    rdx,[rbx+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1faa:
	/* 0x1faa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1faf:
	/* 0x1faf: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1fb4:
	/* 0x1fb4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fb9:
	/* 0x1fb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fbb:
	/* 0x1fbb: mov    ebp,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 80ULL);
x86_l_1fc0:
	/* 0x1fc0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fc3:
	/* 0x1fc3: jne    1c12 <generic_fexit_event+0x1c12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7186ULL;
	}
x86_l_1fc9:
	/* 0x1fc9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fcb:
	/* 0x1fcb: cmp    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1fd0:
	/* 0x1fd0: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1fd3:
	/* 0x1fd3: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1fd8:
	/* 0x1fd8: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fda:
	/* 0x1fda: jmp    1c12 <generic_fexit_event+0x1c12> */
	return 7186ULL;
x86_l_1fdf:
	/* 0x1fdf: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fe4:
	/* 0x1fe4: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fe9:
	/* 0x1fe9: add    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1fec:
	/* 0x1fec: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1fef:
	/* 0x1fef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ff4:
	/* 0x1ff4: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1ff7:
	/* 0x1ff7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ff9:
	/* 0x1ff9: mov    QWORD PTR [rsp+0x58],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1ffe:
	/* 0x1ffe: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2002:
	/* 0x2002: jmp    34a9 <generic_fexit_event+0x34a9> */
	return 13481ULL;
x86_l_2007:
	/* 0x2007: lea    rdx,[rbp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_200b:
	/* 0x200b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2010:
	/* 0x2010: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2013:
	/* 0x2013: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2018:
	/* 0x2018: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_201a:
	/* 0x201a: lea    rdx,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_201e:
	/* 0x201e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2023:
	/* 0x2023: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2026:
	/* 0x2026: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_202b:
	/* 0x202b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_202d:
	/* 0x202d: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2031:
	/* 0x2031: lea    rdi,[rbx+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2038:
	/* 0x2038: lea    r12,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_203c:
	/* 0x203c: add    rbp,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_2040:
	/* 0x2040: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2045:
	/* 0x2045: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_204a:
	/* 0x204a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_204d:
	/* 0x204d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_204f:
	/* 0x204f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2052:
	/* 0x2052: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_2059:
	/* 0x2059: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_205e:
	/* 0x205e: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2063:
	/* 0x2063: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2066:
	/* 0x2066: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2068:
	/* 0x2068: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_206b:
	/* 0x206b: movzx  eax,WORD PTR [rbx+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_2072:
	/* 0x2072: movbe  WORD PTR [rbx+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_207b:
	/* 0x207b: mov    ebp,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_2080:
	/* 0x2080: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2085:
	/* 0x2085: jmp    10e7 <generic_fexit_event+0x10e7> */
	return 4327ULL;
x86_l_208a:
	/* 0x208a: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_208d:
	/* 0x208d: je     232e <generic_fexit_event+0x232e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9006ULL;
	}
x86_l_2093:
	/* 0x2093: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2096:
	/* 0x2096: je     20b4 <generic_fexit_event+0x20b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20b4;
	}
x86_l_2098:
	/* 0x2098: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_209d:
	/* 0x209d: jne    240f <generic_fexit_event+0x240f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9231ULL;
	}
x86_l_20a3:
	/* 0x20a3: mov    WORD PTR [r12+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_20ab:
	/* 0x20ab: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_20af:
	/* 0x20af: jmp    2344 <generic_fexit_event+0x2344> */
	return 9028ULL;
x86_l_20b4:
	/* 0x20b4: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_20b7:
	/* 0x20b7: movzx  eax,BYTE PTR [r12+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_20bd:
	/* 0x20bd: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_20c4:
	/* 0x20c4: jmp    233e <generic_fexit_event+0x233e> */
	return 9022ULL;
x86_l_20c9:
	/* 0x20c9: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20ce:
	/* 0x20ce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20d3:
	/* 0x20d3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20d8:
	/* 0x20d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20dd:
	/* 0x20dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20df:
	/* 0x20df: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_20e4:
	/* 0x20e4: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_20e9:
	/* 0x20e9: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_20ec:
	/* 0x20ec: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20f1:
	/* 0x20f1: je     3496 <generic_fexit_event+0x3496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13462ULL;
	}
x86_l_20f7:
	/* 0x20f7: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_20fb:
	/* 0x20fb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2100:
	/* 0x2100: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2105:
	/* 0x2105: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_210a:
	/* 0x210a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_210d:
	/* 0x210d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_210f:
	/* 0x210f: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2114:
	/* 0x2114: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2119:
	/* 0x2119: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_211e:
	/* 0x211e: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2123:
	/* 0x2123: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2128:
	/* 0x2128: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_212d:
	/* 0x212d: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2132:
	/* 0x2132: jne    2142 <generic_fexit_event+0x2142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2142;
	}
x86_l_2134:
	/* 0x2134: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_2137:
	/* 0x2137: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_213c:
	/* 0x213c: je     677 <generic_fexit_event+0x677> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1655ULL;
	}
x86_l_2142:
	/* 0x2142: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2147:
	/* 0x2147: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_214f:
	/* 0x214f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2154:
	/* 0x2154: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2156:
	/* 0x2156: cmp    r13,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 136ULL);
x86_l_215e:
	/* 0x215e: je     241a <generic_fexit_event+0x241a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9242ULL;
	}
x86_l_2164:
	/* 0x2164: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2168:
	/* 0x2168: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_216d:
	/* 0x216d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2172:
	/* 0x2172: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2177:
	/* 0x2177: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_217a:
	/* 0x217a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_217c:
	/* 0x217c: cmp    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2181:
	/* 0x2181: je     241a <generic_fexit_event+0x241a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9242ULL;
	}
x86_l_2187:
	/* 0x2187: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_218c:
	/* 0x218c: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2194:
	/* 0x2194: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2199:
	/* 0x2199: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_219c:
	/* 0x219c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_219e:
	/* 0x219e: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_21a2:
	/* 0x21a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21a7:
	/* 0x21a7: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_21ac:
	/* 0x21ac: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_21b1:
	/* 0x21b1: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_21b4:
	/* 0x21b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21b6:
	/* 0x21b6: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21bb:
	/* 0x21bb: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_21c0:
	/* 0x21c0: mov    esi,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_21c4:
	/* 0x21c4: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_21c7:
	/* 0x21c7: mov    edi,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_21cb:
	/* 0x21cb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21cd:
	/* 0x21cd: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_21cf:
	/* 0x21cf: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_21d1:
	/* 0x21d1: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_21d4:
	/* 0x21d4: add    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_21d9:
	/* 0x21d9: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21dc:
	/* 0x21dc: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_21de:
	/* 0x21de: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_21e2:
	/* 0x21e2: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_21e4:
	/* 0x21e4: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_21e7:
	/* 0x21e7: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_21ea:
	/* 0x21ea: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_21ed:
	/* 0x21ed: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_21f0:
	/* 0x21f0: mov    DWORD PTR [rsp+0x60],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_21f5:
	/* 0x21f5: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_21f8:
	/* 0x21f8: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21fd:
	/* 0x21fd: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_2200:
	/* 0x2200: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2205:
	/* 0x2205: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_220a:
	/* 0x220a: jb     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ffe;
	}
x86_l_2210:
	/* 0x2210: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_2217:
	/* 0x2217: ja     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ffe;
	}
x86_l_221d:
	/* 0x221d: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_221f:
	/* 0x221f: jbe    343b <generic_fexit_event+0x343b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13371ULL;
	}
x86_l_2225:
	/* 0x2225: lea    r15,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2229:
	/* 0x2229: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_222d:
	/* 0x222d: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2230:
	/* 0x2230: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2234:
	/* 0x2234: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2237:
	/* 0x2237: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_223c:
	/* 0x223c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_223e:
	/* 0x223e: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2243:
	/* 0x2243: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_224b:
	/* 0x224b: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2250:
	/* 0x2250: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2255:
	/* 0x2255: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_225a:
	/* 0x225a: jmp    2479 <generic_fexit_event+0x2479> */
	return 9337ULL;
x86_l_225f:
	/* 0x225f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2261:
	/* 0x2261: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2266:
	/* 0x2266: cmp    QWORD PTR [rsp+0xa0],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767363ULL);
x86_l_226f:
	/* 0x226f: jne    227f <generic_fexit_event+0x227f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_227f;
	}
x86_l_2271:
	/* 0x2271: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2275:
	/* 0x2275: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_227a:
	/* 0x227a: jmp    173e <generic_fexit_event+0x173e> */
	return 5950ULL;
x86_l_227f:
	/* 0x227f: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2287:
	/* 0x2287: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_228b:
	/* 0x228b: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2291:
	/* 0x2291: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2296:
	/* 0x2296: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_229b:
	/* 0x229b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_22a0:
	/* 0x22a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a2:
	/* 0x22a2: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_22a7:
	/* 0x22a7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22a9:
	/* 0x22a9: js     3923 <generic_fexit_event+0x3923> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14627ULL;
	}
x86_l_22af:
	/* 0x22af: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22b4:
	/* 0x22b4: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22b9:
	/* 0x22b9: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_22bc:
	/* 0x22bc: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_22bf:
	/* 0x22bf: cmovb  r12,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_22c3:
	/* 0x22c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22c6:
	/* 0x22c6: cmovne rdx,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R12, X86_WIDTH_64, X86_CC_NE);
	return 8906ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8906ULL: goto x86_l_22ca;
	case 8911ULL: goto x86_l_22cf;
	case 8918ULL: goto x86_l_22d6;
	case 8924ULL: goto x86_l_22dc;
	case 8927ULL: goto x86_l_22df;
	case 8930ULL: goto x86_l_22e2;
	case 8933ULL: goto x86_l_22e5;
	case 8936ULL: goto x86_l_22e8;
	case 8942ULL: goto x86_l_22ee;
	case 8947ULL: goto x86_l_22f3;
	case 8952ULL: goto x86_l_22f8;
	case 8957ULL: goto x86_l_22fd;
	case 8959ULL: goto x86_l_22ff;
	case 8961ULL: goto x86_l_2301;
	case 8966ULL: goto x86_l_2306;
	case 8968ULL: goto x86_l_2308;
	case 8974ULL: goto x86_l_230e;
	case 8978ULL: goto x86_l_2312;
	case 8984ULL: goto x86_l_2318;
	case 8990ULL: goto x86_l_231e;
	case 8995ULL: goto x86_l_2323;
	case 9001ULL: goto x86_l_2329;
	case 9006ULL: goto x86_l_232e;
	case 9009ULL: goto x86_l_2331;
	case 9015ULL: goto x86_l_2337;
	case 9022ULL: goto x86_l_233e;
	case 9028ULL: goto x86_l_2344;
	case 9031ULL: goto x86_l_2347;
	case 9036ULL: goto x86_l_234c;
	case 9041ULL: goto x86_l_2351;
	case 9047ULL: goto x86_l_2357;
	case 9051ULL: goto x86_l_235b;
	case 9057ULL: goto x86_l_2361;
	case 9067ULL: goto x86_l_236b;
	case 9071ULL: goto x86_l_236f;
	case 9077ULL: goto x86_l_2375;
	case 9082ULL: goto x86_l_237a;
	case 9087ULL: goto x86_l_237f;
	case 9092ULL: goto x86_l_2384;
	case 9097ULL: goto x86_l_2389;
	case 9100ULL: goto x86_l_238c;
	case 9105ULL: goto x86_l_2391;
	case 9107ULL: goto x86_l_2393;
	case 9110ULL: goto x86_l_2396;
	case 9116ULL: goto x86_l_239c;
	case 9122ULL: goto x86_l_23a2;
	case 9125ULL: goto x86_l_23a5;
	case 9127ULL: goto x86_l_23a7;
	case 9129ULL: goto x86_l_23a9;
	case 9131ULL: goto x86_l_23ab;
	case 9134ULL: goto x86_l_23ae;
	case 9136ULL: goto x86_l_23b0;
	case 9139ULL: goto x86_l_23b3;
	case 9145ULL: goto x86_l_23b9;
	case 9153ULL: goto x86_l_23c1;
	case 9157ULL: goto x86_l_23c5;
	case 9162ULL: goto x86_l_23ca;
	case 9165ULL: goto x86_l_23cd;
	case 9171ULL: goto x86_l_23d3;
	case 9174ULL: goto x86_l_23d6;
	case 9176ULL: goto x86_l_23d8;
	case 9181ULL: goto x86_l_23dd;
	case 9187ULL: goto x86_l_23e3;
	case 9195ULL: goto x86_l_23eb;
	case 9199ULL: goto x86_l_23ef;
	case 9204ULL: goto x86_l_23f4;
	case 9207ULL: goto x86_l_23f7;
	case 9213ULL: goto x86_l_23fd;
	case 9220ULL: goto x86_l_2404;
	case 9226ULL: goto x86_l_240a;
	case 9231ULL: goto x86_l_240f;
	case 9237ULL: goto x86_l_2415;
	case 9242ULL: goto x86_l_241a;
	case 9247ULL: goto x86_l_241f;
	case 9252ULL: goto x86_l_2424;
	case 9257ULL: goto x86_l_2429;
	case 9262ULL: goto x86_l_242e;
	case 9264ULL: goto x86_l_2430;
	case 9269ULL: goto x86_l_2435;
	case 9274ULL: goto x86_l_243a;
	case 9277ULL: goto x86_l_243d;
	case 9282ULL: goto x86_l_2442;
	case 9288ULL: goto x86_l_2448;
	case 9292ULL: goto x86_l_244c;
	case 9297ULL: goto x86_l_2451;
	case 9302ULL: goto x86_l_2456;
	case 9307ULL: goto x86_l_245b;
	case 9310ULL: goto x86_l_245e;
	case 9312ULL: goto x86_l_2460;
	case 9317ULL: goto x86_l_2465;
	case 9322ULL: goto x86_l_246a;
	case 9327ULL: goto x86_l_246f;
	case 9332ULL: goto x86_l_2474;
	case 9337ULL: goto x86_l_2479;
	case 9342ULL: goto x86_l_247e;
	case 9347ULL: goto x86_l_2483;
	case 9349ULL: goto x86_l_2485;
	case 9352ULL: goto x86_l_2488;
	case 9357ULL: goto x86_l_248d;
	case 9363ULL: goto x86_l_2493;
	case 9368ULL: goto x86_l_2498;
	case 9376ULL: goto x86_l_24a0;
	case 9381ULL: goto x86_l_24a5;
	case 9383ULL: goto x86_l_24a7;
	case 9391ULL: goto x86_l_24af;
	case 9397ULL: goto x86_l_24b5;
	case 9401ULL: goto x86_l_24b9;
	case 9406ULL: goto x86_l_24be;
	case 9411ULL: goto x86_l_24c3;
	case 9416ULL: goto x86_l_24c8;
	case 9419ULL: goto x86_l_24cb;
	case 9421ULL: goto x86_l_24cd;
	case 9426ULL: goto x86_l_24d2;
	case 9432ULL: goto x86_l_24d8;
	case 9437ULL: goto x86_l_24dd;
	case 9445ULL: goto x86_l_24e5;
	case 9450ULL: goto x86_l_24ea;
	case 9453ULL: goto x86_l_24ed;
	case 9455ULL: goto x86_l_24ef;
	case 9459ULL: goto x86_l_24f3;
	case 9464ULL: goto x86_l_24f8;
	case 9469ULL: goto x86_l_24fd;
	case 9474ULL: goto x86_l_2502;
	case 9477ULL: goto x86_l_2505;
	case 9479ULL: goto x86_l_2507;
	case 9484ULL: goto x86_l_250c;
	case 9489ULL: goto x86_l_2511;
	case 9493ULL: goto x86_l_2515;
	case 9496ULL: goto x86_l_2518;
	case 9500ULL: goto x86_l_251c;
	case 9502ULL: goto x86_l_251e;
	case 9504ULL: goto x86_l_2520;
	case 9506ULL: goto x86_l_2522;
	case 9509ULL: goto x86_l_2525;
	case 9514ULL: goto x86_l_252a;
	case 9517ULL: goto x86_l_252d;
	case 9519ULL: goto x86_l_252f;
	case 9523ULL: goto x86_l_2533;
	case 9525ULL: goto x86_l_2535;
	case 9528ULL: goto x86_l_2538;
	case 9531ULL: goto x86_l_253b;
	case 9534ULL: goto x86_l_253e;
	case 9537ULL: goto x86_l_2541;
	case 9542ULL: goto x86_l_2546;
	case 9545ULL: goto x86_l_2549;
	case 9550ULL: goto x86_l_254e;
	case 9553ULL: goto x86_l_2551;
	case 9558ULL: goto x86_l_2556;
	case 9563ULL: goto x86_l_255b;
	case 9569ULL: goto x86_l_2561;
	case 9576ULL: goto x86_l_2568;
	case 9582ULL: goto x86_l_256e;
	case 9584ULL: goto x86_l_2570;
	case 9590ULL: goto x86_l_2576;
	case 9594ULL: goto x86_l_257a;
	case 9598ULL: goto x86_l_257e;
	case 9601ULL: goto x86_l_2581;
	case 9605ULL: goto x86_l_2585;
	case 9608ULL: goto x86_l_2588;
	case 9613ULL: goto x86_l_258d;
	case 9615ULL: goto x86_l_258f;
	case 9620ULL: goto x86_l_2594;
	case 9628ULL: goto x86_l_259c;
	case 9633ULL: goto x86_l_25a1;
	case 9638ULL: goto x86_l_25a6;
	case 9643ULL: goto x86_l_25ab;
	case 9648ULL: goto x86_l_25b0;
	case 9651ULL: goto x86_l_25b3;
	case 9657ULL: goto x86_l_25b9;
	case 9664ULL: goto x86_l_25c0;
	case 9670ULL: goto x86_l_25c6;
	case 9672ULL: goto x86_l_25c8;
	case 9678ULL: goto x86_l_25ce;
	case 9681ULL: goto x86_l_25d1;
	case 9686ULL: goto x86_l_25d6;
	case 9691ULL: goto x86_l_25db;
	case 9697ULL: goto x86_l_25e1;
	case 9701ULL: goto x86_l_25e5;
	case 9707ULL: goto x86_l_25eb;
	case 9717ULL: goto x86_l_25f5;
	case 9721ULL: goto x86_l_25f9;
	case 9727ULL: goto x86_l_25ff;
	case 9732ULL: goto x86_l_2604;
	case 9737ULL: goto x86_l_2609;
	case 9742ULL: goto x86_l_260e;
	case 9747ULL: goto x86_l_2613;
	case 9750ULL: goto x86_l_2616;
	case 9755ULL: goto x86_l_261b;
	case 9757ULL: goto x86_l_261d;
	case 9760ULL: goto x86_l_2620;
	case 9766ULL: goto x86_l_2626;
	case 9772ULL: goto x86_l_262c;
	case 9775ULL: goto x86_l_262f;
	case 9777ULL: goto x86_l_2631;
	case 9779ULL: goto x86_l_2633;
	case 9781ULL: goto x86_l_2635;
	case 9784ULL: goto x86_l_2638;
	case 9786ULL: goto x86_l_263a;
	case 9789ULL: goto x86_l_263d;
	case 9791ULL: goto x86_l_263f;
	case 9799ULL: goto x86_l_2647;
	case 9803ULL: goto x86_l_264b;
	case 9805ULL: goto x86_l_264d;
	case 9808ULL: goto x86_l_2650;
	case 9810ULL: goto x86_l_2652;
	case 9813ULL: goto x86_l_2655;
	case 9815ULL: goto x86_l_2657;
	case 9820ULL: goto x86_l_265c;
	case 9822ULL: goto x86_l_265e;
	case 9830ULL: goto x86_l_2666;
	case 9834ULL: goto x86_l_266a;
	case 9836ULL: goto x86_l_266c;
	case 9839ULL: goto x86_l_266f;
	case 9845ULL: goto x86_l_2675;
	case 9852ULL: goto x86_l_267c;
	case 9858ULL: goto x86_l_2682;
	case 9860ULL: goto x86_l_2684;
	case 9863ULL: goto x86_l_2687;
	case 9869ULL: goto x86_l_268d;
	case 9876ULL: goto x86_l_2694;
	case 9882ULL: goto x86_l_269a;
	case 9884ULL: goto x86_l_269c;
	case 9890ULL: goto x86_l_26a2;
	case 9893ULL: goto x86_l_26a5;
	case 9898ULL: goto x86_l_26aa;
	case 9903ULL: goto x86_l_26af;
	case 9909ULL: goto x86_l_26b5;
	case 9913ULL: goto x86_l_26b9;
	case 9919ULL: goto x86_l_26bf;
	case 9929ULL: goto x86_l_26c9;
	case 9933ULL: goto x86_l_26cd;
	case 9939ULL: goto x86_l_26d3;
	case 9944ULL: goto x86_l_26d8;
	case 9949ULL: goto x86_l_26dd;
	case 9954ULL: goto x86_l_26e2;
	case 9959ULL: goto x86_l_26e7;
	case 9962ULL: goto x86_l_26ea;
	case 9967ULL: goto x86_l_26ef;
	case 9969ULL: goto x86_l_26f1;
	case 9972ULL: goto x86_l_26f4;
	case 9978ULL: goto x86_l_26fa;
	case 9984ULL: goto x86_l_2700;
	case 9987ULL: goto x86_l_2703;
	case 9989ULL: goto x86_l_2705;
	case 9991ULL: goto x86_l_2707;
	case 9993ULL: goto x86_l_2709;
	case 9996ULL: goto x86_l_270c;
	case 9998ULL: goto x86_l_270e;
	case 10001ULL: goto x86_l_2711;
	case 10003ULL: goto x86_l_2713;
	case 10011ULL: goto x86_l_271b;
	case 10015ULL: goto x86_l_271f;
	case 10017ULL: goto x86_l_2721;
	case 10020ULL: goto x86_l_2724;
	case 10022ULL: goto x86_l_2726;
	case 10025ULL: goto x86_l_2729;
	case 10027ULL: goto x86_l_272b;
	case 10032ULL: goto x86_l_2730;
	case 10034ULL: goto x86_l_2732;
	case 10042ULL: goto x86_l_273a;
	case 10046ULL: goto x86_l_273e;
	case 10048ULL: goto x86_l_2740;
	case 10051ULL: goto x86_l_2743;
	case 10057ULL: goto x86_l_2749;
	case 10064ULL: goto x86_l_2750;
	case 10070ULL: goto x86_l_2756;
	case 10072ULL: goto x86_l_2758;
	case 10075ULL: goto x86_l_275b;
	case 10081ULL: goto x86_l_2761;
	case 10088ULL: goto x86_l_2768;
	case 10094ULL: goto x86_l_276e;
	case 10096ULL: goto x86_l_2770;
	case 10102ULL: goto x86_l_2776;
	case 10105ULL: goto x86_l_2779;
	case 10110ULL: goto x86_l_277e;
	case 10115ULL: goto x86_l_2783;
	case 10121ULL: goto x86_l_2789;
	case 10125ULL: goto x86_l_278d;
	case 10131ULL: goto x86_l_2793;
	case 10141ULL: goto x86_l_279d;
	case 10145ULL: goto x86_l_27a1;
	case 10151ULL: goto x86_l_27a7;
	case 10156ULL: goto x86_l_27ac;
	case 10161ULL: goto x86_l_27b1;
	case 10166ULL: goto x86_l_27b6;
	case 10171ULL: goto x86_l_27bb;
	case 10174ULL: goto x86_l_27be;
	case 10179ULL: goto x86_l_27c3;
	case 10181ULL: goto x86_l_27c5;
	case 10184ULL: goto x86_l_27c8;
	case 10190ULL: goto x86_l_27ce;
	case 10196ULL: goto x86_l_27d4;
	case 10199ULL: goto x86_l_27d7;
	case 10201ULL: goto x86_l_27d9;
	case 10203ULL: goto x86_l_27db;
	case 10205ULL: goto x86_l_27dd;
	case 10208ULL: goto x86_l_27e0;
	case 10210ULL: goto x86_l_27e2;
	case 10213ULL: goto x86_l_27e5;
	case 10219ULL: goto x86_l_27eb;
	case 10227ULL: goto x86_l_27f3;
	case 10231ULL: goto x86_l_27f7;
	case 10236ULL: goto x86_l_27fc;
	case 10239ULL: goto x86_l_27ff;
	case 10245ULL: goto x86_l_2805;
	case 10248ULL: goto x86_l_2808;
	case 10250ULL: goto x86_l_280a;
	case 10255ULL: goto x86_l_280f;
	case 10261ULL: goto x86_l_2815;
	case 10269ULL: goto x86_l_281d;
	case 10273ULL: goto x86_l_2821;
	case 10278ULL: goto x86_l_2826;
	case 10281ULL: goto x86_l_2829;
	case 10287ULL: goto x86_l_282f;
	case 10294ULL: goto x86_l_2836;
	case 10300ULL: goto x86_l_283c;
	case 10305ULL: goto x86_l_2841;
	case 10310ULL: goto x86_l_2846;
	case 10315ULL: goto x86_l_284b;
	case 10320ULL: goto x86_l_2850;
	case 10325ULL: goto x86_l_2855;
	case 10327ULL: goto x86_l_2857;
	case 10332ULL: goto x86_l_285c;
	case 10337ULL: goto x86_l_2861;
	case 10340ULL: goto x86_l_2864;
	case 10345ULL: goto x86_l_2869;
	case 10351ULL: goto x86_l_286f;
	case 10355ULL: goto x86_l_2873;
	case 10360ULL: goto x86_l_2878;
	case 10365ULL: goto x86_l_287d;
	case 10370ULL: goto x86_l_2882;
	case 10373ULL: goto x86_l_2885;
	case 10375ULL: goto x86_l_2887;
	case 10380ULL: goto x86_l_288c;
	case 10385ULL: goto x86_l_2891;
	case 10390ULL: goto x86_l_2896;
	case 10395ULL: goto x86_l_289b;
	case 10400ULL: goto x86_l_28a0;
	case 10405ULL: goto x86_l_28a5;
	case 10410ULL: goto x86_l_28aa;
	case 10412ULL: goto x86_l_28ac;
	case 10415ULL: goto x86_l_28af;
	case 10420ULL: goto x86_l_28b4;
	case 10426ULL: goto x86_l_28ba;
	case 10431ULL: goto x86_l_28bf;
	case 10439ULL: goto x86_l_28c7;
	case 10444ULL: goto x86_l_28cc;
	case 10446ULL: goto x86_l_28ce;
	case 10454ULL: goto x86_l_28d6;
	case 10460ULL: goto x86_l_28dc;
	case 10464ULL: goto x86_l_28e0;
	case 10469ULL: goto x86_l_28e5;
	case 10474ULL: goto x86_l_28ea;
	case 10479ULL: goto x86_l_28ef;
	case 10482ULL: goto x86_l_28f2;
	case 10484ULL: goto x86_l_28f4;
	case 10489ULL: goto x86_l_28f9;
	case 10495ULL: goto x86_l_28ff;
	case 10500ULL: goto x86_l_2904;
	case 10508ULL: goto x86_l_290c;
	case 10513ULL: goto x86_l_2911;
	case 10516ULL: goto x86_l_2914;
	case 10518ULL: goto x86_l_2916;
	case 10522ULL: goto x86_l_291a;
	case 10527ULL: goto x86_l_291f;
	case 10532ULL: goto x86_l_2924;
	case 10537ULL: goto x86_l_2929;
	case 10540ULL: goto x86_l_292c;
	case 10542ULL: goto x86_l_292e;
	case 10547ULL: goto x86_l_2933;
	case 10552ULL: goto x86_l_2938;
	case 10556ULL: goto x86_l_293c;
	case 10559ULL: goto x86_l_293f;
	case 10563ULL: goto x86_l_2943;
	case 10565ULL: goto x86_l_2945;
	case 10567ULL: goto x86_l_2947;
	case 10569ULL: goto x86_l_2949;
	case 10572ULL: goto x86_l_294c;
	case 10577ULL: goto x86_l_2951;
	case 10580ULL: goto x86_l_2954;
	case 10582ULL: goto x86_l_2956;
	case 10586ULL: goto x86_l_295a;
	case 10588ULL: goto x86_l_295c;
	case 10591ULL: goto x86_l_295f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22ca:
	/* 0x22ca: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_22cf:
	/* 0x22cf: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_22d6:
	/* 0x22d6: ja     3923 <generic_fexit_event+0x3923> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14627ULL;
	}
x86_l_22dc:
	/* 0x22dc: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_22df:
	/* 0x22df: add    r15,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_22e2:
	/* 0x22e2: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_22e5:
	/* 0x22e5: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_22e8:
	/* 0x22e8: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_22ee:
	/* 0x22ee: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_22f3:
	/* 0x22f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22f8:
	/* 0x22f8: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22fd:
	/* 0x22fd: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_22ff:
	/* 0x22ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2301:
	/* 0x2301: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2306:
	/* 0x2306: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2308:
	/* 0x2308: js     3923 <generic_fexit_event+0x3923> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14627ULL;
	}
x86_l_230e:
	/* 0x230e: add    QWORD PTR [rsp],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2312:
	/* 0x2312: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2318:
	/* 0x2318: je     2ac0 <generic_fexit_event+0x2ac0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10944ULL;
	}
x86_l_231e:
	/* 0x231e: sub    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_2323:
	/* 0x2323: jne    2ac7 <generic_fexit_event+0x2ac7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10951ULL;
	}
x86_l_2329:
	/* 0x2329: jmp    2271 <generic_fexit_event+0x2271> */
	return 8817ULL;
x86_l_232e:
	/* 0x232e: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2331:
	/* 0x2331: movzx  eax,BYTE PTR [r12+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2337:
	/* 0x2337: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_233e:
	/* 0x233e: mov    WORD PTR [r12+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2344:
	/* 0x2344: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2347:
	/* 0x2347: add    ax,WORD PTR [r12] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_234c:
	/* 0x234c: mov    WORD PTR [r12],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2351:
	/* 0x2351: movzx  ecx,BYTE PTR [r12+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2357:
	/* 0x2357: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_235b:
	/* 0x235b: ja     3038 <generic_fexit_event+0x3038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12344ULL;
	}
x86_l_2361:
	/* 0x2361: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_236b:
	/* 0x236b: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_236f:
	/* 0x236f: jae    3038 <generic_fexit_event+0x3038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12344ULL;
	}
x86_l_2375:
	/* 0x2375: mov    BYTE PTR [r12+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_237a:
	/* 0x237a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_237f:
	/* 0x237f: movzx  edx,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2384:
	/* 0x2384: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2389:
	/* 0x2389: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_238c:
	/* 0x238c: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2391:
	/* 0x2391: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2393:
	/* 0x2393: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2396:
	/* 0x2396: js     2e7e <generic_fexit_event+0x2e7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11902ULL;
	}
x86_l_239c:
	/* 0x239c: movzx  eax,BYTE PTR [r12+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_23a2:
	/* 0x23a2: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_23a5:
	/* 0x23a5: jg     23ca <generic_fexit_event+0x23ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_23ca;
	}
x86_l_23a7:
	/* 0x23a7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23a9:
	/* 0x23a9: je     23f4 <generic_fexit_event+0x23f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23f4;
	}
x86_l_23ab:
	/* 0x23ab: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_23ae:
	/* 0x23ae: je     23f4 <generic_fexit_event+0x23f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23f4;
	}
x86_l_23b0:
	/* 0x23b0: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_23b3:
	/* 0x23b3: jne    25c8 <generic_fexit_event+0x25c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25c8;
	}
x86_l_23b9:
	/* 0x23b9: mov    WORD PTR [r12+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_23c1:
	/* 0x23c1: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_23c5:
	/* 0x23c5: jmp    25ce <generic_fexit_event+0x25ce> */
	goto x86_l_25ce;
x86_l_23ca:
	/* 0x23ca: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_23cd:
	/* 0x23cd: je     25b0 <generic_fexit_event+0x25b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25b0;
	}
x86_l_23d3:
	/* 0x23d3: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_23d6:
	/* 0x23d6: je     23f4 <generic_fexit_event+0x23f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23f4;
	}
x86_l_23d8:
	/* 0x23d8: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_23dd:
	/* 0x23dd: jne    25c8 <generic_fexit_event+0x25c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25c8;
	}
x86_l_23e3:
	/* 0x23e3: mov    WORD PTR [r12+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_23eb:
	/* 0x23eb: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_23ef:
	/* 0x23ef: jmp    25ce <generic_fexit_event+0x25ce> */
	goto x86_l_25ce;
x86_l_23f4:
	/* 0x23f4: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_23f7:
	/* 0x23f7: movzx  eax,BYTE PTR [r12+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_23fd:
	/* 0x23fd: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2404:
	/* 0x2404: mov    WORD PTR [r12+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_240a:
	/* 0x240a: jmp    25ce <generic_fexit_event+0x25ce> */
	goto x86_l_25ce;
x86_l_240f:
	/* 0x240f: movzx  eax,WORD PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2415:
	/* 0x2415: jmp    2344 <generic_fexit_event+0x2344> */
	goto x86_l_2344;
x86_l_241a:
	/* 0x241a: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_241f:
	/* 0x241f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2424:
	/* 0x2424: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2429:
	/* 0x2429: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_242e:
	/* 0x242e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2430:
	/* 0x2430: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2435:
	/* 0x2435: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_243a:
	/* 0x243a: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_243d:
	/* 0x243d: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2442:
	/* 0x2442: je     3496 <generic_fexit_event+0x3496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13462ULL;
	}
x86_l_2448:
	/* 0x2448: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_244c:
	/* 0x244c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2451:
	/* 0x2451: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2456:
	/* 0x2456: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_245b:
	/* 0x245b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_245e:
	/* 0x245e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2460:
	/* 0x2460: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2465:
	/* 0x2465: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_246a:
	/* 0x246a: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_246f:
	/* 0x246f: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2474:
	/* 0x2474: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2479:
	/* 0x2479: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_247e:
	/* 0x247e: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2483:
	/* 0x2483: jne    2493 <generic_fexit_event+0x2493> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2493;
	}
x86_l_2485:
	/* 0x2485: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_2488:
	/* 0x2488: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_248d:
	/* 0x248d: je     677 <generic_fexit_event+0x677> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1655ULL;
	}
x86_l_2493:
	/* 0x2493: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2498:
	/* 0x2498: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_24a0:
	/* 0x24a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24a5:
	/* 0x24a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a7:
	/* 0x24a7: cmp    r13,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 136ULL);
x86_l_24af:
	/* 0x24af: je     2841 <generic_fexit_event+0x2841> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2841;
	}
x86_l_24b5:
	/* 0x24b5: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24b9:
	/* 0x24b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24be:
	/* 0x24be: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24c3:
	/* 0x24c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24c8:
	/* 0x24c8: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_24cb:
	/* 0x24cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24cd:
	/* 0x24cd: cmp    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24d2:
	/* 0x24d2: je     2841 <generic_fexit_event+0x2841> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2841;
	}
x86_l_24d8:
	/* 0x24d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24dd:
	/* 0x24dd: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_24e5:
	/* 0x24e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24ea:
	/* 0x24ea: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_24ed:
	/* 0x24ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ef:
	/* 0x24ef: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_24f3:
	/* 0x24f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24f8:
	/* 0x24f8: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_24fd:
	/* 0x24fd: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2502:
	/* 0x2502: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2505:
	/* 0x2505: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2507:
	/* 0x2507: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_250c:
	/* 0x250c: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2511:
	/* 0x2511: mov    esi,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_2515:
	/* 0x2515: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2518:
	/* 0x2518: mov    edi,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_251c:
	/* 0x251c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_251e:
	/* 0x251e: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2520:
	/* 0x2520: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2522:
	/* 0x2522: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2525:
	/* 0x2525: add    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_252a:
	/* 0x252a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_252d:
	/* 0x252d: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_252f:
	/* 0x252f: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_2533:
	/* 0x2533: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2535:
	/* 0x2535: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_2538:
	/* 0x2538: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_253b:
	/* 0x253b: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_253e:
	/* 0x253e: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2541:
	/* 0x2541: mov    DWORD PTR [rsp+0x60],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2546:
	/* 0x2546: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2549:
	/* 0x2549: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_254e:
	/* 0x254e: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_2551:
	/* 0x2551: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2556:
	/* 0x2556: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_255b:
	/* 0x255b: jb     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8190ULL;
	}
x86_l_2561:
	/* 0x2561: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_2568:
	/* 0x2568: ja     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8190ULL;
	}
x86_l_256e:
	/* 0x256e: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2570:
	/* 0x2570: jbe    343b <generic_fexit_event+0x343b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13371ULL;
	}
x86_l_2576:
	/* 0x2576: lea    r15,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_257a:
	/* 0x257a: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_257e:
	/* 0x257e: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2581:
	/* 0x2581: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2585:
	/* 0x2585: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2588:
	/* 0x2588: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_258d:
	/* 0x258d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_258f:
	/* 0x258f: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2594:
	/* 0x2594: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_259c:
	/* 0x259c: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25a1:
	/* 0x25a1: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_25a6:
	/* 0x25a6: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_25ab:
	/* 0x25ab: jmp    28a0 <generic_fexit_event+0x28a0> */
	goto x86_l_28a0;
x86_l_25b0:
	/* 0x25b0: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_25b3:
	/* 0x25b3: movzx  eax,BYTE PTR [r12+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_25b9:
	/* 0x25b9: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_25c0:
	/* 0x25c0: mov    WORD PTR [r12+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_25c6:
	/* 0x25c6: jmp    25ce <generic_fexit_event+0x25ce> */
	goto x86_l_25ce;
x86_l_25c8:
	/* 0x25c8: movzx  eax,WORD PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_25ce:
	/* 0x25ce: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_25d1:
	/* 0x25d1: add    ax,WORD PTR [r12] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_25d6:
	/* 0x25d6: mov    WORD PTR [r12],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25db:
	/* 0x25db: movzx  ecx,BYTE PTR [r12+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_25e1:
	/* 0x25e1: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_25e5:
	/* 0x25e5: ja     3038 <generic_fexit_event+0x3038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12344ULL;
	}
x86_l_25eb:
	/* 0x25eb: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_25f5:
	/* 0x25f5: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_25f9:
	/* 0x25f9: jae    3038 <generic_fexit_event+0x3038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12344ULL;
	}
x86_l_25ff:
	/* 0x25ff: mov    BYTE PTR [r12+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2604:
	/* 0x2604: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2609:
	/* 0x2609: movzx  edx,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_260e:
	/* 0x260e: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2613:
	/* 0x2613: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2616:
	/* 0x2616: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_261b:
	/* 0x261b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_261d:
	/* 0x261d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2620:
	/* 0x2620: js     2e7e <generic_fexit_event+0x2e7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11902ULL;
	}
x86_l_2626:
	/* 0x2626: movzx  eax,BYTE PTR [r12+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_262c:
	/* 0x262c: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_262f:
	/* 0x262f: jg     264d <generic_fexit_event+0x264d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_264d;
	}
x86_l_2631:
	/* 0x2631: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2633:
	/* 0x2633: je     266c <generic_fexit_event+0x266c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_266c;
	}
x86_l_2635:
	/* 0x2635: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2638:
	/* 0x2638: je     266c <generic_fexit_event+0x266c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_266c;
	}
x86_l_263a:
	/* 0x263a: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_263d:
	/* 0x263d: jne    269c <generic_fexit_event+0x269c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_269c;
	}
x86_l_263f:
	/* 0x263f: mov    WORD PTR [r12+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2647:
	/* 0x2647: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_264b:
	/* 0x264b: jmp    26a2 <generic_fexit_event+0x26a2> */
	goto x86_l_26a2;
x86_l_264d:
	/* 0x264d: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2650:
	/* 0x2650: je     2684 <generic_fexit_event+0x2684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2684;
	}
x86_l_2652:
	/* 0x2652: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2655:
	/* 0x2655: je     266c <generic_fexit_event+0x266c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_266c;
	}
x86_l_2657:
	/* 0x2657: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_265c:
	/* 0x265c: jne    269c <generic_fexit_event+0x269c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_269c;
	}
x86_l_265e:
	/* 0x265e: mov    WORD PTR [r12+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2666:
	/* 0x2666: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_266a:
	/* 0x266a: jmp    26a2 <generic_fexit_event+0x26a2> */
	goto x86_l_26a2;
x86_l_266c:
	/* 0x266c: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_266f:
	/* 0x266f: movzx  eax,BYTE PTR [r12+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2675:
	/* 0x2675: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_267c:
	/* 0x267c: mov    WORD PTR [r12+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2682:
	/* 0x2682: jmp    26a2 <generic_fexit_event+0x26a2> */
	goto x86_l_26a2;
x86_l_2684:
	/* 0x2684: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2687:
	/* 0x2687: movzx  eax,BYTE PTR [r12+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_268d:
	/* 0x268d: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2694:
	/* 0x2694: mov    WORD PTR [r12+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_269a:
	/* 0x269a: jmp    26a2 <generic_fexit_event+0x26a2> */
	goto x86_l_26a2;
x86_l_269c:
	/* 0x269c: movzx  eax,WORD PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_26a2:
	/* 0x26a2: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_26a5:
	/* 0x26a5: add    ax,WORD PTR [r12] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_26aa:
	/* 0x26aa: mov    WORD PTR [r12],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26af:
	/* 0x26af: movzx  ecx,BYTE PTR [r12+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_26b5:
	/* 0x26b5: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_26b9:
	/* 0x26b9: ja     3038 <generic_fexit_event+0x3038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12344ULL;
	}
x86_l_26bf:
	/* 0x26bf: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_26c9:
	/* 0x26c9: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_26cd:
	/* 0x26cd: jae    3038 <generic_fexit_event+0x3038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12344ULL;
	}
x86_l_26d3:
	/* 0x26d3: mov    BYTE PTR [r12+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_26d8:
	/* 0x26d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26dd:
	/* 0x26dd: movzx  edx,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_26e2:
	/* 0x26e2: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_26e7:
	/* 0x26e7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_26ea:
	/* 0x26ea: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_26ef:
	/* 0x26ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f1:
	/* 0x26f1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26f4:
	/* 0x26f4: js     2e7e <generic_fexit_event+0x2e7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11902ULL;
	}
x86_l_26fa:
	/* 0x26fa: movzx  eax,BYTE PTR [r12+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2700:
	/* 0x2700: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2703:
	/* 0x2703: jg     2721 <generic_fexit_event+0x2721> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2721;
	}
x86_l_2705:
	/* 0x2705: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2707:
	/* 0x2707: je     2740 <generic_fexit_event+0x2740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2740;
	}
x86_l_2709:
	/* 0x2709: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_270c:
	/* 0x270c: je     2740 <generic_fexit_event+0x2740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2740;
	}
x86_l_270e:
	/* 0x270e: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2711:
	/* 0x2711: jne    2770 <generic_fexit_event+0x2770> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2770;
	}
x86_l_2713:
	/* 0x2713: mov    WORD PTR [r12+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_271b:
	/* 0x271b: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_271f:
	/* 0x271f: jmp    2776 <generic_fexit_event+0x2776> */
	goto x86_l_2776;
x86_l_2721:
	/* 0x2721: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2724:
	/* 0x2724: je     2758 <generic_fexit_event+0x2758> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2758;
	}
x86_l_2726:
	/* 0x2726: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2729:
	/* 0x2729: je     2740 <generic_fexit_event+0x2740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2740;
	}
x86_l_272b:
	/* 0x272b: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2730:
	/* 0x2730: jne    2770 <generic_fexit_event+0x2770> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2770;
	}
x86_l_2732:
	/* 0x2732: mov    WORD PTR [r12+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_273a:
	/* 0x273a: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_273e:
	/* 0x273e: jmp    2776 <generic_fexit_event+0x2776> */
	goto x86_l_2776;
x86_l_2740:
	/* 0x2740: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2743:
	/* 0x2743: movzx  eax,BYTE PTR [r12+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2749:
	/* 0x2749: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2750:
	/* 0x2750: mov    WORD PTR [r12+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2756:
	/* 0x2756: jmp    2776 <generic_fexit_event+0x2776> */
	goto x86_l_2776;
x86_l_2758:
	/* 0x2758: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_275b:
	/* 0x275b: movzx  eax,BYTE PTR [r12+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2761:
	/* 0x2761: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2768:
	/* 0x2768: mov    WORD PTR [r12+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_276e:
	/* 0x276e: jmp    2776 <generic_fexit_event+0x2776> */
	goto x86_l_2776;
x86_l_2770:
	/* 0x2770: movzx  eax,WORD PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2776:
	/* 0x2776: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2779:
	/* 0x2779: add    ax,WORD PTR [r12] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_277e:
	/* 0x277e: mov    WORD PTR [r12],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2783:
	/* 0x2783: movzx  ecx,BYTE PTR [r12+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2789:
	/* 0x2789: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_278d:
	/* 0x278d: ja     3038 <generic_fexit_event+0x3038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12344ULL;
	}
x86_l_2793:
	/* 0x2793: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_279d:
	/* 0x279d: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_27a1:
	/* 0x27a1: jae    3038 <generic_fexit_event+0x3038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12344ULL;
	}
x86_l_27a7:
	/* 0x27a7: mov    BYTE PTR [r12+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_27ac:
	/* 0x27ac: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27b1:
	/* 0x27b1: movzx  edx,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27b6:
	/* 0x27b6: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_27bb:
	/* 0x27bb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_27be:
	/* 0x27be: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_27c3:
	/* 0x27c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27c5:
	/* 0x27c5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27c8:
	/* 0x27c8: js     2e7e <generic_fexit_event+0x2e7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11902ULL;
	}
x86_l_27ce:
	/* 0x27ce: movzx  eax,BYTE PTR [r12+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_27d4:
	/* 0x27d4: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_27d7:
	/* 0x27d7: jg     27fc <generic_fexit_event+0x27fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_27fc;
	}
x86_l_27d9:
	/* 0x27d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27db:
	/* 0x27db: je     2826 <generic_fexit_event+0x2826> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2826;
	}
x86_l_27dd:
	/* 0x27dd: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_27e0:
	/* 0x27e0: je     2826 <generic_fexit_event+0x2826> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2826;
	}
x86_l_27e2:
	/* 0x27e2: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_27e5:
	/* 0x27e5: jne    29ef <generic_fexit_event+0x29ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10735ULL;
	}
x86_l_27eb:
	/* 0x27eb: mov    WORD PTR [r12+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_27f3:
	/* 0x27f3: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_27f7:
	/* 0x27f7: jmp    29f5 <generic_fexit_event+0x29f5> */
	return 10741ULL;
x86_l_27fc:
	/* 0x27fc: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_27ff:
	/* 0x27ff: je     29d7 <generic_fexit_event+0x29d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10711ULL;
	}
x86_l_2805:
	/* 0x2805: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2808:
	/* 0x2808: je     2826 <generic_fexit_event+0x2826> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2826;
	}
x86_l_280a:
	/* 0x280a: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_280f:
	/* 0x280f: jne    29ef <generic_fexit_event+0x29ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10735ULL;
	}
x86_l_2815:
	/* 0x2815: mov    WORD PTR [r12+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_281d:
	/* 0x281d: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2821:
	/* 0x2821: jmp    29f5 <generic_fexit_event+0x29f5> */
	return 10741ULL;
x86_l_2826:
	/* 0x2826: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2829:
	/* 0x2829: movzx  eax,BYTE PTR [r12+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_282f:
	/* 0x282f: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2836:
	/* 0x2836: mov    WORD PTR [r12+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_283c:
	/* 0x283c: jmp    29f5 <generic_fexit_event+0x29f5> */
	return 10741ULL;
x86_l_2841:
	/* 0x2841: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2846:
	/* 0x2846: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_284b:
	/* 0x284b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2850:
	/* 0x2850: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2855:
	/* 0x2855: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2857:
	/* 0x2857: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_285c:
	/* 0x285c: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2861:
	/* 0x2861: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_2864:
	/* 0x2864: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2869:
	/* 0x2869: je     3496 <generic_fexit_event+0x3496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13462ULL;
	}
x86_l_286f:
	/* 0x286f: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2873:
	/* 0x2873: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2878:
	/* 0x2878: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_287d:
	/* 0x287d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2882:
	/* 0x2882: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2885:
	/* 0x2885: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2887:
	/* 0x2887: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_288c:
	/* 0x288c: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2891:
	/* 0x2891: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2896:
	/* 0x2896: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_289b:
	/* 0x289b: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_28a0:
	/* 0x28a0: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_28a5:
	/* 0x28a5: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28aa:
	/* 0x28aa: jne    28ba <generic_fexit_event+0x28ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28ba;
	}
x86_l_28ac:
	/* 0x28ac: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_28af:
	/* 0x28af: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_28b4:
	/* 0x28b4: je     677 <generic_fexit_event+0x677> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1655ULL;
	}
x86_l_28ba:
	/* 0x28ba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28bf:
	/* 0x28bf: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_28c7:
	/* 0x28c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28cc:
	/* 0x28cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28ce:
	/* 0x28ce: cmp    r13,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 136ULL);
x86_l_28d6:
	/* 0x28d6: je     2c78 <generic_fexit_event+0x2c78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11384ULL;
	}
x86_l_28dc:
	/* 0x28dc: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28e0:
	/* 0x28e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28e5:
	/* 0x28e5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28ea:
	/* 0x28ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28ef:
	/* 0x28ef: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_28f2:
	/* 0x28f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28f4:
	/* 0x28f4: cmp    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28f9:
	/* 0x28f9: je     2c78 <generic_fexit_event+0x2c78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11384ULL;
	}
x86_l_28ff:
	/* 0x28ff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2904:
	/* 0x2904: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_290c:
	/* 0x290c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2911:
	/* 0x2911: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2914:
	/* 0x2914: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2916:
	/* 0x2916: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_291a:
	/* 0x291a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_291f:
	/* 0x291f: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2924:
	/* 0x2924: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2929:
	/* 0x2929: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_292c:
	/* 0x292c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_292e:
	/* 0x292e: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2933:
	/* 0x2933: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2938:
	/* 0x2938: mov    esi,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_293c:
	/* 0x293c: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_293f:
	/* 0x293f: mov    edi,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2943:
	/* 0x2943: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2945:
	/* 0x2945: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2947:
	/* 0x2947: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2949:
	/* 0x2949: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_294c:
	/* 0x294c: add    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_2951:
	/* 0x2951: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2954:
	/* 0x2954: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2956:
	/* 0x2956: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_295a:
	/* 0x295a: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_295c:
	/* 0x295c: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_295f:
	/* 0x295f: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
	return 10594ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10594ULL: goto x86_l_2962;
	case 10597ULL: goto x86_l_2965;
	case 10600ULL: goto x86_l_2968;
	case 10605ULL: goto x86_l_296d;
	case 10608ULL: goto x86_l_2970;
	case 10613ULL: goto x86_l_2975;
	case 10616ULL: goto x86_l_2978;
	case 10621ULL: goto x86_l_297d;
	case 10626ULL: goto x86_l_2982;
	case 10632ULL: goto x86_l_2988;
	case 10639ULL: goto x86_l_298f;
	case 10645ULL: goto x86_l_2995;
	case 10647ULL: goto x86_l_2997;
	case 10653ULL: goto x86_l_299d;
	case 10657ULL: goto x86_l_29a1;
	case 10661ULL: goto x86_l_29a5;
	case 10664ULL: goto x86_l_29a8;
	case 10668ULL: goto x86_l_29ac;
	case 10671ULL: goto x86_l_29af;
	case 10676ULL: goto x86_l_29b4;
	case 10678ULL: goto x86_l_29b6;
	case 10683ULL: goto x86_l_29bb;
	case 10691ULL: goto x86_l_29c3;
	case 10696ULL: goto x86_l_29c8;
	case 10701ULL: goto x86_l_29cd;
	case 10706ULL: goto x86_l_29d2;
	case 10711ULL: goto x86_l_29d7;
	case 10714ULL: goto x86_l_29da;
	case 10720ULL: goto x86_l_29e0;
	case 10727ULL: goto x86_l_29e7;
	case 10733ULL: goto x86_l_29ed;
	case 10735ULL: goto x86_l_29ef;
	case 10741ULL: goto x86_l_29f5;
	case 10744ULL: goto x86_l_29f8;
	case 10749ULL: goto x86_l_29fd;
	case 10754ULL: goto x86_l_2a02;
	case 10760ULL: goto x86_l_2a08;
	case 10764ULL: goto x86_l_2a0c;
	case 10770ULL: goto x86_l_2a12;
	case 10780ULL: goto x86_l_2a1c;
	case 10784ULL: goto x86_l_2a20;
	case 10790ULL: goto x86_l_2a26;
	case 10795ULL: goto x86_l_2a2b;
	case 10800ULL: goto x86_l_2a30;
	case 10805ULL: goto x86_l_2a35;
	case 10810ULL: goto x86_l_2a3a;
	case 10813ULL: goto x86_l_2a3d;
	case 10818ULL: goto x86_l_2a42;
	case 10820ULL: goto x86_l_2a44;
	case 10823ULL: goto x86_l_2a47;
	case 10829ULL: goto x86_l_2a4d;
	case 10835ULL: goto x86_l_2a53;
	case 10838ULL: goto x86_l_2a56;
	case 10840ULL: goto x86_l_2a58;
	case 10842ULL: goto x86_l_2a5a;
	case 10844ULL: goto x86_l_2a5c;
	case 10847ULL: goto x86_l_2a5f;
	case 10849ULL: goto x86_l_2a61;
	case 10852ULL: goto x86_l_2a64;
	case 10858ULL: goto x86_l_2a6a;
	case 10866ULL: goto x86_l_2a72;
	case 10870ULL: goto x86_l_2a76;
	case 10875ULL: goto x86_l_2a7b;
	case 10878ULL: goto x86_l_2a7e;
	case 10884ULL: goto x86_l_2a84;
	case 10887ULL: goto x86_l_2a87;
	case 10889ULL: goto x86_l_2a89;
	case 10894ULL: goto x86_l_2a8e;
	case 10900ULL: goto x86_l_2a94;
	case 10908ULL: goto x86_l_2a9c;
	case 10912ULL: goto x86_l_2aa0;
	case 10917ULL: goto x86_l_2aa5;
	case 10920ULL: goto x86_l_2aa8;
	case 10926ULL: goto x86_l_2aae;
	case 10933ULL: goto x86_l_2ab5;
	case 10939ULL: goto x86_l_2abb;
	case 10944ULL: goto x86_l_2ac0;
	case 10946ULL: goto x86_l_2ac2;
	case 10951ULL: goto x86_l_2ac7;
	case 10960ULL: goto x86_l_2ad0;
	case 10966ULL: goto x86_l_2ad6;
	case 10974ULL: goto x86_l_2ade;
	case 10978ULL: goto x86_l_2ae2;
	case 10984ULL: goto x86_l_2ae8;
	case 10989ULL: goto x86_l_2aed;
	case 10994ULL: goto x86_l_2af2;
	case 10999ULL: goto x86_l_2af7;
	case 11001ULL: goto x86_l_2af9;
	case 11006ULL: goto x86_l_2afe;
	case 11008ULL: goto x86_l_2b00;
	case 11014ULL: goto x86_l_2b06;
	case 11019ULL: goto x86_l_2b0b;
	case 11024ULL: goto x86_l_2b10;
	case 11027ULL: goto x86_l_2b13;
	case 11030ULL: goto x86_l_2b16;
	case 11034ULL: goto x86_l_2b1a;
	case 11037ULL: goto x86_l_2b1d;
	case 11041ULL: goto x86_l_2b21;
	case 11046ULL: goto x86_l_2b26;
	case 11051ULL: goto x86_l_2b2b;
	case 11058ULL: goto x86_l_2b32;
	case 11064ULL: goto x86_l_2b38;
	case 11067ULL: goto x86_l_2b3b;
	case 11070ULL: goto x86_l_2b3e;
	case 11073ULL: goto x86_l_2b41;
	case 11079ULL: goto x86_l_2b47;
	case 11084ULL: goto x86_l_2b4c;
	case 11089ULL: goto x86_l_2b51;
	case 11094ULL: goto x86_l_2b56;
	case 11099ULL: goto x86_l_2b5b;
	case 11101ULL: goto x86_l_2b5d;
	case 11106ULL: goto x86_l_2b62;
	case 11108ULL: goto x86_l_2b64;
	case 11114ULL: goto x86_l_2b6a;
	case 11119ULL: goto x86_l_2b6f;
	case 11123ULL: goto x86_l_2b73;
	case 11129ULL: goto x86_l_2b79;
	case 11135ULL: goto x86_l_2b7f;
	case 11140ULL: goto x86_l_2b84;
	case 11146ULL: goto x86_l_2b8a;
	case 11151ULL: goto x86_l_2b8f;
	case 11154ULL: goto x86_l_2b92;
	case 11160ULL: goto x86_l_2b98;
	case 11167ULL: goto x86_l_2b9f;
	case 11173ULL: goto x86_l_2ba5;
	case 11175ULL: goto x86_l_2ba7;
	case 11181ULL: goto x86_l_2bad;
	case 11184ULL: goto x86_l_2bb0;
	case 11189ULL: goto x86_l_2bb5;
	case 11194ULL: goto x86_l_2bba;
	case 11200ULL: goto x86_l_2bc0;
	case 11204ULL: goto x86_l_2bc4;
	case 11210ULL: goto x86_l_2bca;
	case 11220ULL: goto x86_l_2bd4;
	case 11224ULL: goto x86_l_2bd8;
	case 11230ULL: goto x86_l_2bde;
	case 11235ULL: goto x86_l_2be3;
	case 11240ULL: goto x86_l_2be8;
	case 11245ULL: goto x86_l_2bed;
	case 11250ULL: goto x86_l_2bf2;
	case 11253ULL: goto x86_l_2bf5;
	case 11258ULL: goto x86_l_2bfa;
	case 11260ULL: goto x86_l_2bfc;
	case 11263ULL: goto x86_l_2bff;
	case 11269ULL: goto x86_l_2c05;
	case 11275ULL: goto x86_l_2c0b;
	case 11278ULL: goto x86_l_2c0e;
	case 11280ULL: goto x86_l_2c10;
	case 11282ULL: goto x86_l_2c12;
	case 11284ULL: goto x86_l_2c14;
	case 11287ULL: goto x86_l_2c17;
	case 11289ULL: goto x86_l_2c19;
	case 11292ULL: goto x86_l_2c1c;
	case 11298ULL: goto x86_l_2c22;
	case 11306ULL: goto x86_l_2c2a;
	case 11310ULL: goto x86_l_2c2e;
	case 11315ULL: goto x86_l_2c33;
	case 11318ULL: goto x86_l_2c36;
	case 11324ULL: goto x86_l_2c3c;
	case 11327ULL: goto x86_l_2c3f;
	case 11329ULL: goto x86_l_2c41;
	case 11334ULL: goto x86_l_2c46;
	case 11340ULL: goto x86_l_2c4c;
	case 11348ULL: goto x86_l_2c54;
	case 11352ULL: goto x86_l_2c58;
	case 11357ULL: goto x86_l_2c5d;
	case 11360ULL: goto x86_l_2c60;
	case 11366ULL: goto x86_l_2c66;
	case 11373ULL: goto x86_l_2c6d;
	case 11379ULL: goto x86_l_2c73;
	case 11384ULL: goto x86_l_2c78;
	case 11389ULL: goto x86_l_2c7d;
	case 11394ULL: goto x86_l_2c82;
	case 11399ULL: goto x86_l_2c87;
	case 11404ULL: goto x86_l_2c8c;
	case 11406ULL: goto x86_l_2c8e;
	case 11411ULL: goto x86_l_2c93;
	case 11416ULL: goto x86_l_2c98;
	case 11419ULL: goto x86_l_2c9b;
	case 11424ULL: goto x86_l_2ca0;
	case 11430ULL: goto x86_l_2ca6;
	case 11434ULL: goto x86_l_2caa;
	case 11439ULL: goto x86_l_2caf;
	case 11444ULL: goto x86_l_2cb4;
	case 11449ULL: goto x86_l_2cb9;
	case 11452ULL: goto x86_l_2cbc;
	case 11454ULL: goto x86_l_2cbe;
	case 11459ULL: goto x86_l_2cc3;
	case 11464ULL: goto x86_l_2cc8;
	case 11469ULL: goto x86_l_2ccd;
	case 11474ULL: goto x86_l_2cd2;
	case 11479ULL: goto x86_l_2cd7;
	case 11484ULL: goto x86_l_2cdc;
	case 11489ULL: goto x86_l_2ce1;
	case 11491ULL: goto x86_l_2ce3;
	case 11494ULL: goto x86_l_2ce6;
	case 11499ULL: goto x86_l_2ceb;
	case 11505ULL: goto x86_l_2cf1;
	case 11510ULL: goto x86_l_2cf6;
	case 11518ULL: goto x86_l_2cfe;
	case 11523ULL: goto x86_l_2d03;
	case 11525ULL: goto x86_l_2d05;
	case 11533ULL: goto x86_l_2d0d;
	case 11539ULL: goto x86_l_2d13;
	case 11543ULL: goto x86_l_2d17;
	case 11548ULL: goto x86_l_2d1c;
	case 11553ULL: goto x86_l_2d21;
	case 11558ULL: goto x86_l_2d26;
	case 11561ULL: goto x86_l_2d29;
	case 11563ULL: goto x86_l_2d2b;
	case 11568ULL: goto x86_l_2d30;
	case 11574ULL: goto x86_l_2d36;
	case 11579ULL: goto x86_l_2d3b;
	case 11587ULL: goto x86_l_2d43;
	case 11592ULL: goto x86_l_2d48;
	case 11595ULL: goto x86_l_2d4b;
	case 11597ULL: goto x86_l_2d4d;
	case 11601ULL: goto x86_l_2d51;
	case 11606ULL: goto x86_l_2d56;
	case 11611ULL: goto x86_l_2d5b;
	case 11616ULL: goto x86_l_2d60;
	case 11619ULL: goto x86_l_2d63;
	case 11621ULL: goto x86_l_2d65;
	case 11626ULL: goto x86_l_2d6a;
	case 11631ULL: goto x86_l_2d6f;
	case 11635ULL: goto x86_l_2d73;
	case 11638ULL: goto x86_l_2d76;
	case 11642ULL: goto x86_l_2d7a;
	case 11644ULL: goto x86_l_2d7c;
	case 11646ULL: goto x86_l_2d7e;
	case 11648ULL: goto x86_l_2d80;
	case 11651ULL: goto x86_l_2d83;
	case 11656ULL: goto x86_l_2d88;
	case 11659ULL: goto x86_l_2d8b;
	case 11661ULL: goto x86_l_2d8d;
	case 11665ULL: goto x86_l_2d91;
	case 11667ULL: goto x86_l_2d93;
	case 11670ULL: goto x86_l_2d96;
	case 11673ULL: goto x86_l_2d99;
	case 11676ULL: goto x86_l_2d9c;
	case 11679ULL: goto x86_l_2d9f;
	case 11684ULL: goto x86_l_2da4;
	case 11687ULL: goto x86_l_2da7;
	case 11692ULL: goto x86_l_2dac;
	case 11695ULL: goto x86_l_2daf;
	case 11700ULL: goto x86_l_2db4;
	case 11705ULL: goto x86_l_2db9;
	case 11711ULL: goto x86_l_2dbf;
	case 11718ULL: goto x86_l_2dc6;
	case 11724ULL: goto x86_l_2dcc;
	case 11726ULL: goto x86_l_2dce;
	case 11732ULL: goto x86_l_2dd4;
	case 11736ULL: goto x86_l_2dd8;
	case 11740ULL: goto x86_l_2ddc;
	case 11743ULL: goto x86_l_2ddf;
	case 11747ULL: goto x86_l_2de3;
	case 11750ULL: goto x86_l_2de6;
	case 11755ULL: goto x86_l_2deb;
	case 11757ULL: goto x86_l_2ded;
	case 11762ULL: goto x86_l_2df2;
	case 11770ULL: goto x86_l_2dfa;
	case 11775ULL: goto x86_l_2dff;
	case 11780ULL: goto x86_l_2e04;
	case 11785ULL: goto x86_l_2e09;
	case 11790ULL: goto x86_l_2e0e;
	case 11793ULL: goto x86_l_2e11;
	case 11799ULL: goto x86_l_2e17;
	case 11806ULL: goto x86_l_2e1e;
	case 11812ULL: goto x86_l_2e24;
	case 11814ULL: goto x86_l_2e26;
	case 11820ULL: goto x86_l_2e2c;
	case 11823ULL: goto x86_l_2e2f;
	case 11828ULL: goto x86_l_2e34;
	case 11833ULL: goto x86_l_2e39;
	case 11839ULL: goto x86_l_2e3f;
	case 11843ULL: goto x86_l_2e43;
	case 11849ULL: goto x86_l_2e49;
	case 11859ULL: goto x86_l_2e53;
	case 11863ULL: goto x86_l_2e57;
	case 11869ULL: goto x86_l_2e5d;
	case 11874ULL: goto x86_l_2e62;
	case 11879ULL: goto x86_l_2e67;
	case 11884ULL: goto x86_l_2e6c;
	case 11889ULL: goto x86_l_2e71;
	case 11892ULL: goto x86_l_2e74;
	case 11895ULL: goto x86_l_2e77;
	case 11900ULL: goto x86_l_2e7c;
	case 11902ULL: goto x86_l_2e7e;
	case 11904ULL: goto x86_l_2e80;
	case 11911ULL: goto x86_l_2e87;
	case 11914ULL: goto x86_l_2e8a;
	case 11918ULL: goto x86_l_2e8e;
	case 11925ULL: goto x86_l_2e95;
	case 11934ULL: goto x86_l_2e9e;
	case 11938ULL: goto x86_l_2ea2;
	case 11943ULL: goto x86_l_2ea7;
	case 11948ULL: goto x86_l_2eac;
	case 11953ULL: goto x86_l_2eb1;
	case 11955ULL: goto x86_l_2eb3;
	case 11962ULL: goto x86_l_2eba;
	case 11966ULL: goto x86_l_2ebe;
	case 11971ULL: goto x86_l_2ec3;
	case 11976ULL: goto x86_l_2ec8;
	case 11979ULL: goto x86_l_2ecb;
	case 11981ULL: goto x86_l_2ecd;
	case 11989ULL: goto x86_l_2ed5;
	case 11992ULL: goto x86_l_2ed8;
	case 11994ULL: goto x86_l_2eda;
	case 11997ULL: goto x86_l_2edd;
	case 12003ULL: goto x86_l_2ee3;
	case 12008ULL: goto x86_l_2ee8;
	case 12017ULL: goto x86_l_2ef1;
	case 12021ULL: goto x86_l_2ef5;
	case 12025ULL: goto x86_l_2ef9;
	case 12032ULL: goto x86_l_2f00;
	case 12037ULL: goto x86_l_2f05;
	case 12042ULL: goto x86_l_2f0a;
	case 12044ULL: goto x86_l_2f0c;
	case 12051ULL: goto x86_l_2f13;
	case 12055ULL: goto x86_l_2f17;
	case 12059ULL: goto x86_l_2f1b;
	case 12064ULL: goto x86_l_2f20;
	case 12066ULL: goto x86_l_2f22;
	case 12071ULL: goto x86_l_2f27;
	case 12080ULL: goto x86_l_2f30;
	case 12084ULL: goto x86_l_2f34;
	case 12088ULL: goto x86_l_2f38;
	case 12095ULL: goto x86_l_2f3f;
	case 12100ULL: goto x86_l_2f44;
	case 12105ULL: goto x86_l_2f49;
	case 12107ULL: goto x86_l_2f4b;
	case 12114ULL: goto x86_l_2f52;
	case 12118ULL: goto x86_l_2f56;
	case 12122ULL: goto x86_l_2f5a;
	case 12127ULL: goto x86_l_2f5f;
	case 12132ULL: goto x86_l_2f64;
	case 12134ULL: goto x86_l_2f66;
	case 12136ULL: goto x86_l_2f68;
	case 12140ULL: goto x86_l_2f6c;
	case 12150ULL: goto x86_l_2f76;
	case 12154ULL: goto x86_l_2f7a;
	case 12161ULL: goto x86_l_2f81;
	case 12168ULL: goto x86_l_2f88;
	case 12177ULL: goto x86_l_2f91;
	case 12186ULL: goto x86_l_2f9a;
	case 12193ULL: goto x86_l_2fa1;
	case 12198ULL: goto x86_l_2fa6;
	case 12203ULL: goto x86_l_2fab;
	case 12208ULL: goto x86_l_2fb0;
	case 12211ULL: goto x86_l_2fb3;
	case 12213ULL: goto x86_l_2fb5;
	case 12219ULL: goto x86_l_2fbb;
	case 12221ULL: goto x86_l_2fbd;
	case 12226ULL: goto x86_l_2fc2;
	case 12231ULL: goto x86_l_2fc7;
	case 12235ULL: goto x86_l_2fcb;
	case 12243ULL: goto x86_l_2fd3;
	case 12248ULL: goto x86_l_2fd8;
	case 12250ULL: goto x86_l_2fda;
	case 12255ULL: goto x86_l_2fdf;
	case 12263ULL: goto x86_l_2fe7;
	case 12267ULL: goto x86_l_2feb;
	case 12271ULL: goto x86_l_2fef;
	case 12278ULL: goto x86_l_2ff6;
	case 12283ULL: goto x86_l_2ffb;
	case 12288ULL: goto x86_l_3000;
	case 12290ULL: goto x86_l_3002;
	case 12293ULL: goto x86_l_3005;
	case 12300ULL: goto x86_l_300c;
	case 12304ULL: goto x86_l_3010;
	case 12308ULL: goto x86_l_3014;
	case 12313ULL: goto x86_l_3019;
	case 12318ULL: goto x86_l_301e;
	case 12320ULL: goto x86_l_3020;
	case 12325ULL: goto x86_l_3025;
	case 12330ULL: goto x86_l_302a;
	case 12334ULL: goto x86_l_302e;
	case 12339ULL: goto x86_l_3033;
	case 12344ULL: goto x86_l_3038;
	case 12352ULL: goto x86_l_3040;
	case 12357ULL: goto x86_l_3045;
	case 12362ULL: goto x86_l_304a;
	case 12367ULL: goto x86_l_304f;
	case 12372ULL: goto x86_l_3054;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2962:
	/* 0x2962: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_2965:
	/* 0x2965: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2968:
	/* 0x2968: mov    DWORD PTR [rsp+0x60],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_296d:
	/* 0x296d: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2970:
	/* 0x2970: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2975:
	/* 0x2975: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_2978:
	/* 0x2978: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_297d:
	/* 0x297d: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2982:
	/* 0x2982: jb     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8190ULL;
	}
x86_l_2988:
	/* 0x2988: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_298f:
	/* 0x298f: ja     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8190ULL;
	}
x86_l_2995:
	/* 0x2995: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2997:
	/* 0x2997: jbe    343b <generic_fexit_event+0x343b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13371ULL;
	}
x86_l_299d:
	/* 0x299d: lea    r15,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_29a1:
	/* 0x29a1: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_29a5:
	/* 0x29a5: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_29a8:
	/* 0x29a8: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_29ac:
	/* 0x29ac: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_29af:
	/* 0x29af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29b4:
	/* 0x29b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b6:
	/* 0x29b6: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_29bb:
	/* 0x29bb: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_29c3:
	/* 0x29c3: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_29c8:
	/* 0x29c8: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_29cd:
	/* 0x29cd: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_29d2:
	/* 0x29d2: jmp    2cd7 <generic_fexit_event+0x2cd7> */
	goto x86_l_2cd7;
x86_l_29d7:
	/* 0x29d7: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_29da:
	/* 0x29da: movzx  eax,BYTE PTR [r12+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_29e0:
	/* 0x29e0: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_29e7:
	/* 0x29e7: mov    WORD PTR [r12+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_29ed:
	/* 0x29ed: jmp    29f5 <generic_fexit_event+0x29f5> */
	goto x86_l_29f5;
x86_l_29ef:
	/* 0x29ef: movzx  eax,WORD PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_29f5:
	/* 0x29f5: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_29f8:
	/* 0x29f8: add    ax,WORD PTR [r12] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_29fd:
	/* 0x29fd: mov    WORD PTR [r12],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a02:
	/* 0x2a02: movzx  ecx,BYTE PTR [r12+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2a08:
	/* 0x2a08: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2a0c:
	/* 0x2a0c: ja     3038 <generic_fexit_event+0x3038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3038;
	}
x86_l_2a12:
	/* 0x2a12: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2a1c:
	/* 0x2a1c: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2a20:
	/* 0x2a20: jae    3038 <generic_fexit_event+0x3038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3038;
	}
x86_l_2a26:
	/* 0x2a26: mov    BYTE PTR [r12+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2a2b:
	/* 0x2a2b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a30:
	/* 0x2a30: movzx  edx,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a35:
	/* 0x2a35: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2a3a:
	/* 0x2a3a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2a3d:
	/* 0x2a3d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2a42:
	/* 0x2a42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a44:
	/* 0x2a44: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a47:
	/* 0x2a47: js     2e7e <generic_fexit_event+0x2e7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e7e;
	}
x86_l_2a4d:
	/* 0x2a4d: movzx  eax,BYTE PTR [r12+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2a53:
	/* 0x2a53: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2a56:
	/* 0x2a56: jg     2a7b <generic_fexit_event+0x2a7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2a7b;
	}
x86_l_2a58:
	/* 0x2a58: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a5a:
	/* 0x2a5a: je     2aa5 <generic_fexit_event+0x2aa5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aa5;
	}
x86_l_2a5c:
	/* 0x2a5c: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2a5f:
	/* 0x2a5f: je     2aa5 <generic_fexit_event+0x2aa5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aa5;
	}
x86_l_2a61:
	/* 0x2a61: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2a64:
	/* 0x2a64: jne    2ba7 <generic_fexit_event+0x2ba7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ba7;
	}
x86_l_2a6a:
	/* 0x2a6a: mov    WORD PTR [r12+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2a72:
	/* 0x2a72: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2a76:
	/* 0x2a76: jmp    2bad <generic_fexit_event+0x2bad> */
	goto x86_l_2bad;
x86_l_2a7b:
	/* 0x2a7b: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2a7e:
	/* 0x2a7e: je     2b8f <generic_fexit_event+0x2b8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b8f;
	}
x86_l_2a84:
	/* 0x2a84: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2a87:
	/* 0x2a87: je     2aa5 <generic_fexit_event+0x2aa5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aa5;
	}
x86_l_2a89:
	/* 0x2a89: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2a8e:
	/* 0x2a8e: jne    2ba7 <generic_fexit_event+0x2ba7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ba7;
	}
x86_l_2a94:
	/* 0x2a94: mov    WORD PTR [r12+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2a9c:
	/* 0x2a9c: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2aa0:
	/* 0x2aa0: jmp    2bad <generic_fexit_event+0x2bad> */
	goto x86_l_2bad;
x86_l_2aa5:
	/* 0x2aa5: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2aa8:
	/* 0x2aa8: movzx  eax,BYTE PTR [r12+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2aae:
	/* 0x2aae: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2ab5:
	/* 0x2ab5: mov    WORD PTR [r12+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2abb:
	/* 0x2abb: jmp    2bad <generic_fexit_event+0x2bad> */
	goto x86_l_2bad;
x86_l_2ac0:
	/* 0x2ac0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ac2:
	/* 0x2ac2: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ac7:
	/* 0x2ac7: cmp    QWORD PTR [rsp+0xa0],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767365ULL);
x86_l_2ad0:
	/* 0x2ad0: jb     2271 <generic_fexit_event+0x2271> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8817ULL;
	}
x86_l_2ad6:
	/* 0x2ad6: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2ade:
	/* 0x2ade: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ae2:
	/* 0x2ae2: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2ae8:
	/* 0x2ae8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2aed:
	/* 0x2aed: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2af2:
	/* 0x2af2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2af7:
	/* 0x2af7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2af9:
	/* 0x2af9: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2afe:
	/* 0x2afe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b00:
	/* 0x2b00: js     3923 <generic_fexit_event+0x3923> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14627ULL;
	}
x86_l_2b06:
	/* 0x2b06: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b0b:
	/* 0x2b0b: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b10:
	/* 0x2b10: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2b13:
	/* 0x2b13: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2b16:
	/* 0x2b16: cmovb  r12,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_2b1a:
	/* 0x2b1a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b1d:
	/* 0x2b1d: cmovne rdx,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_2b21:
	/* 0x2b21: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2b26:
	/* 0x2b26: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2b2b:
	/* 0x2b2b: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_2b32:
	/* 0x2b32: ja     3923 <generic_fexit_event+0x3923> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14627ULL;
	}
x86_l_2b38:
	/* 0x2b38: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2b3b:
	/* 0x2b3b: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b3e:
	/* 0x2b3e: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_2b41:
	/* 0x2b41: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2b47:
	/* 0x2b47: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2b4c:
	/* 0x2b4c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b51:
	/* 0x2b51: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b56:
	/* 0x2b56: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2b5b:
	/* 0x2b5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b5d:
	/* 0x2b5d: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2b62:
	/* 0x2b62: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b64:
	/* 0x2b64: js     3923 <generic_fexit_event+0x3923> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14627ULL;
	}
x86_l_2b6a:
	/* 0x2b6a: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2b6f:
	/* 0x2b6f: add    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b73:
	/* 0x2b73: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2b79:
	/* 0x2b79: je     31db <generic_fexit_event+0x31db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12763ULL;
	}
x86_l_2b7f:
	/* 0x2b7f: sub    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_2b84:
	/* 0x2b84: jne    31e2 <generic_fexit_event+0x31e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12770ULL;
	}
x86_l_2b8a:
	/* 0x2b8a: jmp    2271 <generic_fexit_event+0x2271> */
	return 8817ULL;
x86_l_2b8f:
	/* 0x2b8f: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2b92:
	/* 0x2b92: movzx  eax,BYTE PTR [r12+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2b98:
	/* 0x2b98: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2b9f:
	/* 0x2b9f: mov    WORD PTR [r12+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2ba5:
	/* 0x2ba5: jmp    2bad <generic_fexit_event+0x2bad> */
	goto x86_l_2bad;
x86_l_2ba7:
	/* 0x2ba7: movzx  eax,WORD PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2bad:
	/* 0x2bad: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2bb0:
	/* 0x2bb0: add    ax,WORD PTR [r12] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2bb5:
	/* 0x2bb5: mov    WORD PTR [r12],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bba:
	/* 0x2bba: movzx  ecx,BYTE PTR [r12+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2bc0:
	/* 0x2bc0: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2bc4:
	/* 0x2bc4: ja     3038 <generic_fexit_event+0x3038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3038;
	}
x86_l_2bca:
	/* 0x2bca: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2bd4:
	/* 0x2bd4: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2bd8:
	/* 0x2bd8: jae    3038 <generic_fexit_event+0x3038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3038;
	}
x86_l_2bde:
	/* 0x2bde: mov    BYTE PTR [r12+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2be3:
	/* 0x2be3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2be8:
	/* 0x2be8: movzx  edx,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2bed:
	/* 0x2bed: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2bf2:
	/* 0x2bf2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2bf5:
	/* 0x2bf5: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2bfa:
	/* 0x2bfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bfc:
	/* 0x2bfc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bff:
	/* 0x2bff: js     2e7e <generic_fexit_event+0x2e7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e7e;
	}
x86_l_2c05:
	/* 0x2c05: movzx  eax,BYTE PTR [r12+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2c0b:
	/* 0x2c0b: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2c0e:
	/* 0x2c0e: jg     2c33 <generic_fexit_event+0x2c33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2c33;
	}
x86_l_2c10:
	/* 0x2c10: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c12:
	/* 0x2c12: je     2c5d <generic_fexit_event+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c5d;
	}
x86_l_2c14:
	/* 0x2c14: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2c17:
	/* 0x2c17: je     2c5d <generic_fexit_event+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c5d;
	}
x86_l_2c19:
	/* 0x2c19: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2c1c:
	/* 0x2c1c: jne    2e26 <generic_fexit_event+0x2e26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e26;
	}
x86_l_2c22:
	/* 0x2c22: mov    WORD PTR [r12+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2c2a:
	/* 0x2c2a: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2c2e:
	/* 0x2c2e: jmp    2e2c <generic_fexit_event+0x2e2c> */
	goto x86_l_2e2c;
x86_l_2c33:
	/* 0x2c33: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2c36:
	/* 0x2c36: je     2e0e <generic_fexit_event+0x2e0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e0e;
	}
x86_l_2c3c:
	/* 0x2c3c: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2c3f:
	/* 0x2c3f: je     2c5d <generic_fexit_event+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c5d;
	}
x86_l_2c41:
	/* 0x2c41: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2c46:
	/* 0x2c46: jne    2e26 <generic_fexit_event+0x2e26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e26;
	}
x86_l_2c4c:
	/* 0x2c4c: mov    WORD PTR [r12+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2c54:
	/* 0x2c54: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2c58:
	/* 0x2c58: jmp    2e2c <generic_fexit_event+0x2e2c> */
	goto x86_l_2e2c;
x86_l_2c5d:
	/* 0x2c5d: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2c60:
	/* 0x2c60: movzx  eax,BYTE PTR [r12+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2c66:
	/* 0x2c66: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2c6d:
	/* 0x2c6d: mov    WORD PTR [r12+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2c73:
	/* 0x2c73: jmp    2e2c <generic_fexit_event+0x2e2c> */
	goto x86_l_2e2c;
x86_l_2c78:
	/* 0x2c78: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c7d:
	/* 0x2c7d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c82:
	/* 0x2c82: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c87:
	/* 0x2c87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c8c:
	/* 0x2c8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c8e:
	/* 0x2c8e: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c93:
	/* 0x2c93: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2c98:
	/* 0x2c98: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_2c9b:
	/* 0x2c9b: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ca0:
	/* 0x2ca0: je     3496 <generic_fexit_event+0x3496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13462ULL;
	}
x86_l_2ca6:
	/* 0x2ca6: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2caa:
	/* 0x2caa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2caf:
	/* 0x2caf: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2cb4:
	/* 0x2cb4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cb9:
	/* 0x2cb9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2cbc:
	/* 0x2cbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cbe:
	/* 0x2cbe: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cc3:
	/* 0x2cc3: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2cc8:
	/* 0x2cc8: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ccd:
	/* 0x2ccd: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2cd2:
	/* 0x2cd2: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2cd7:
	/* 0x2cd7: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2cdc:
	/* 0x2cdc: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ce1:
	/* 0x2ce1: jne    2cf1 <generic_fexit_event+0x2cf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cf1;
	}
x86_l_2ce3:
	/* 0x2ce3: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_2ce6:
	/* 0x2ce6: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2ceb:
	/* 0x2ceb: je     677 <generic_fexit_event+0x677> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1655ULL;
	}
x86_l_2cf1:
	/* 0x2cf1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cf6:
	/* 0x2cf6: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2cfe:
	/* 0x2cfe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d03:
	/* 0x2d03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d05:
	/* 0x2d05: cmp    r13,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 136ULL);
x86_l_2d0d:
	/* 0x2d0d: je     3045 <generic_fexit_event+0x3045> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3045;
	}
x86_l_2d13:
	/* 0x2d13: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d17:
	/* 0x2d17: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d1c:
	/* 0x2d1c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d21:
	/* 0x2d21: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d26:
	/* 0x2d26: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2d29:
	/* 0x2d29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d2b:
	/* 0x2d2b: cmp    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d30:
	/* 0x2d30: je     3045 <generic_fexit_event+0x3045> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3045;
	}
x86_l_2d36:
	/* 0x2d36: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d3b:
	/* 0x2d3b: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2d43:
	/* 0x2d43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d48:
	/* 0x2d48: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2d4b:
	/* 0x2d4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d4d:
	/* 0x2d4d: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2d51:
	/* 0x2d51: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d56:
	/* 0x2d56: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2d5b:
	/* 0x2d5b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2d60:
	/* 0x2d60: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2d63:
	/* 0x2d63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d65:
	/* 0x2d65: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d6a:
	/* 0x2d6a: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2d6f:
	/* 0x2d6f: mov    esi,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_2d73:
	/* 0x2d73: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2d76:
	/* 0x2d76: mov    edi,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2d7a:
	/* 0x2d7a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d7c:
	/* 0x2d7c: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2d7e:
	/* 0x2d7e: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d80:
	/* 0x2d80: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2d83:
	/* 0x2d83: add    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_2d88:
	/* 0x2d88: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d8b:
	/* 0x2d8b: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2d8d:
	/* 0x2d8d: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_2d91:
	/* 0x2d91: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2d93:
	/* 0x2d93: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_2d96:
	/* 0x2d96: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2d99:
	/* 0x2d99: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_2d9c:
	/* 0x2d9c: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d9f:
	/* 0x2d9f: mov    DWORD PTR [rsp+0x60],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2da4:
	/* 0x2da4: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2da7:
	/* 0x2da7: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2dac:
	/* 0x2dac: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_2daf:
	/* 0x2daf: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2db4:
	/* 0x2db4: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2db9:
	/* 0x2db9: jb     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8190ULL;
	}
x86_l_2dbf:
	/* 0x2dbf: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_2dc6:
	/* 0x2dc6: ja     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8190ULL;
	}
x86_l_2dcc:
	/* 0x2dcc: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2dce:
	/* 0x2dce: jbe    343b <generic_fexit_event+0x343b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13371ULL;
	}
x86_l_2dd4:
	/* 0x2dd4: lea    r15,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2dd8:
	/* 0x2dd8: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_2ddc:
	/* 0x2ddc: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2ddf:
	/* 0x2ddf: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2de3:
	/* 0x2de3: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2de6:
	/* 0x2de6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2deb:
	/* 0x2deb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ded:
	/* 0x2ded: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2df2:
	/* 0x2df2: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2dfa:
	/* 0x2dfa: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2dff:
	/* 0x2dff: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2e04:
	/* 0x2e04: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e09:
	/* 0x2e09: jmp    30a4 <generic_fexit_event+0x30a4> */
	return 12452ULL;
x86_l_2e0e:
	/* 0x2e0e: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2e11:
	/* 0x2e11: movzx  eax,BYTE PTR [r12+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2e17:
	/* 0x2e17: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2e1e:
	/* 0x2e1e: mov    WORD PTR [r12+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2e24:
	/* 0x2e24: jmp    2e2c <generic_fexit_event+0x2e2c> */
	goto x86_l_2e2c;
x86_l_2e26:
	/* 0x2e26: movzx  eax,WORD PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2e2c:
	/* 0x2e2c: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2e2f:
	/* 0x2e2f: add    ax,WORD PTR [r12] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2e34:
	/* 0x2e34: mov    WORD PTR [r12],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e39:
	/* 0x2e39: movzx  ecx,BYTE PTR [r12+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2e3f:
	/* 0x2e3f: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2e43:
	/* 0x2e43: ja     3038 <generic_fexit_event+0x3038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3038;
	}
x86_l_2e49:
	/* 0x2e49: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2e53:
	/* 0x2e53: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2e57:
	/* 0x2e57: jae    3038 <generic_fexit_event+0x3038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3038;
	}
x86_l_2e5d:
	/* 0x2e5d: mov    BYTE PTR [r12+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2e62:
	/* 0x2e62: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e67:
	/* 0x2e67: movzx  ecx,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e6c:
	/* 0x2e6c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e71:
	/* 0x2e71: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e74:
	/* 0x2e74: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2e77:
	/* 0x2e77: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2e7c:
	/* 0x2e7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e7e:
	/* 0x2e7e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e80:
	/* 0x2e80: mov    BYTE PTR [rsp+0xc8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2e87:
	/* 0x2e87: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e8a:
	/* 0x2e8a: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e8e:
	/* 0x2e8e: mov    WORD PTR [rbx+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2e95:
	/* 0x2e95: mov    WORD PTR [rbx+0xc2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655434ULL);
x86_l_2e9e:
	/* 0x2e9e: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ea2:
	/* 0x2ea2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ea7:
	/* 0x2ea7: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2eac:
	/* 0x2eac: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2eb1:
	/* 0x2eb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eb3:
	/* 0x2eb3: lea    rdi,[rbx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_2eba:
	/* 0x2eba: add    r13,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2ebe:
	/* 0x2ebe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ec3:
	/* 0x2ec3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2ec8:
	/* 0x2ec8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2ecb:
	/* 0x2ecb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ecd:
	/* 0x2ecd: movzx  eax,BYTE PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 200ULL);
x86_l_2ed5:
	/* 0x2ed5: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2ed8:
	/* 0x2ed8: je     2f22 <generic_fexit_event+0x2f22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f22;
	}
x86_l_2eda:
	/* 0x2eda: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2edd:
	/* 0x2edd: jne    2f68 <generic_fexit_event+0x2f68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f68;
	}
x86_l_2ee3:
	/* 0x2ee3: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ee8:
	/* 0x2ee8: movzx  r12d,WORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 208ULL);
x86_l_2ef1:
	/* 0x2ef1: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2ef5:
	/* 0x2ef5: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ef9:
	/* 0x2ef9: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2f00:
	/* 0x2f00: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f05:
	/* 0x2f05: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2f0a:
	/* 0x2f0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f0c:
	/* 0x2f0c: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_2f13:
	/* 0x2f13: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2f17:
	/* 0x2f17: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2f1b:
	/* 0x2f1b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f20:
	/* 0x2f20: jmp    2f5f <generic_fexit_event+0x2f5f> */
	goto x86_l_2f5f;
x86_l_2f22:
	/* 0x2f22: mov    rbx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f27:
	/* 0x2f27: movzx  r12d,WORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 208ULL);
x86_l_2f30:
	/* 0x2f30: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2f34:
	/* 0x2f34: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f38:
	/* 0x2f38: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2f3f:
	/* 0x2f3f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f44:
	/* 0x2f44: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2f49:
	/* 0x2f49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f4b:
	/* 0x2f4b: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_2f52:
	/* 0x2f52: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2f56:
	/* 0x2f56: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2f5a:
	/* 0x2f5a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f5f:
	/* 0x2f5f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2f64:
	/* 0x2f64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f66:
	/* 0x2f66: jmp    2f76 <generic_fexit_event+0x2f76> */
	goto x86_l_2f76;
x86_l_2f68:
	/* 0x2f68: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f6c:
	/* 0x2f6c: mov    DWORD PTR [rax+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_2f76:
	/* 0x2f76: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f7a:
	/* 0x2f7a: movzx  ecx,WORD PTR [rax+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_2f81:
	/* 0x2f81: movzx  edx,WORD PTR [rax+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_2f88:
	/* 0x2f88: movbe  WORD PTR [rax+0xbc],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_2f91:
	/* 0x2f91: movbe  WORD PTR [rax+0xbe],dx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_2f9a:
	/* 0x2f9a: add    rbp,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_2fa1:
	/* 0x2fa1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fa6:
	/* 0x2fa6: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2fab:
	/* 0x2fab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fb0:
	/* 0x2fb0: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2fb3:
	/* 0x2fb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fb5:
	/* 0x2fb5: cmp    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_2fbb:
	/* 0x2fbb: je     3020 <generic_fexit_event+0x3020> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3020;
	}
x86_l_2fbd:
	/* 0x2fbd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fc2:
	/* 0x2fc2: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2fc7:
	/* 0x2fc7: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_2fcb:
	/* 0x2fcb: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2fd3:
	/* 0x2fd3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fd8:
	/* 0x2fd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fda:
	/* 0x2fda: mov    rbx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2fdf:
	/* 0x2fdf: mov    r12,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2fe7:
	/* 0x2fe7: lea    rdx,[rbx+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_2feb:
	/* 0x2feb: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fef:
	/* 0x2fef: lea    rdi,[r13+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_2ff6:
	/* 0x2ff6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ffb:
	/* 0x2ffb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3000:
	/* 0x3000: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3002:
	/* 0x3002: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_3005:
	/* 0x3005: add    rdi,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_300c:
	/* 0x300c: lea    rdx,[rbx+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_3010:
	/* 0x3010: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3014:
	/* 0x3014: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3019:
	/* 0x3019: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_301e:
	/* 0x301e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3020:
	/* 0x3020: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3025:
	/* 0x3025: mov    ebp,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_302a:
	/* 0x302a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_302e:
	/* 0x302e: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3033:
	/* 0x3033: jmp    356a <generic_fexit_event+0x356a> */
	return 13674ULL;
x86_l_3038:
	/* 0x3038: mov    WORD PTR [rsp+0xd0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_3040:
	/* 0x3040: jmp    2e80 <generic_fexit_event+0x2e80> */
	goto x86_l_2e80;
x86_l_3045:
	/* 0x3045: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_304a:
	/* 0x304a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_304f:
	/* 0x304f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3054:
	/* 0x3054: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 12377ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_event_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12377ULL: goto x86_l_3059;
	case 12379ULL: goto x86_l_305b;
	case 12384ULL: goto x86_l_3060;
	case 12389ULL: goto x86_l_3065;
	case 12392ULL: goto x86_l_3068;
	case 12397ULL: goto x86_l_306d;
	case 12403ULL: goto x86_l_3073;
	case 12407ULL: goto x86_l_3077;
	case 12412ULL: goto x86_l_307c;
	case 12417ULL: goto x86_l_3081;
	case 12422ULL: goto x86_l_3086;
	case 12425ULL: goto x86_l_3089;
	case 12427ULL: goto x86_l_308b;
	case 12432ULL: goto x86_l_3090;
	case 12437ULL: goto x86_l_3095;
	case 12442ULL: goto x86_l_309a;
	case 12447ULL: goto x86_l_309f;
	case 12452ULL: goto x86_l_30a4;
	case 12457ULL: goto x86_l_30a9;
	case 12462ULL: goto x86_l_30ae;
	case 12464ULL: goto x86_l_30b0;
	case 12467ULL: goto x86_l_30b3;
	case 12472ULL: goto x86_l_30b8;
	case 12478ULL: goto x86_l_30be;
	case 12483ULL: goto x86_l_30c3;
	case 12491ULL: goto x86_l_30cb;
	case 12496ULL: goto x86_l_30d0;
	case 12498ULL: goto x86_l_30d2;
	case 12506ULL: goto x86_l_30da;
	case 12512ULL: goto x86_l_30e0;
	case 12516ULL: goto x86_l_30e4;
	case 12521ULL: goto x86_l_30e9;
	case 12526ULL: goto x86_l_30ee;
	case 12531ULL: goto x86_l_30f3;
	case 12534ULL: goto x86_l_30f6;
	case 12536ULL: goto x86_l_30f8;
	case 12541ULL: goto x86_l_30fd;
	case 12547ULL: goto x86_l_3103;
	case 12552ULL: goto x86_l_3108;
	case 12560ULL: goto x86_l_3110;
	case 12565ULL: goto x86_l_3115;
	case 12568ULL: goto x86_l_3118;
	case 12570ULL: goto x86_l_311a;
	case 12574ULL: goto x86_l_311e;
	case 12579ULL: goto x86_l_3123;
	case 12584ULL: goto x86_l_3128;
	case 12589ULL: goto x86_l_312d;
	case 12592ULL: goto x86_l_3130;
	case 12594ULL: goto x86_l_3132;
	case 12599ULL: goto x86_l_3137;
	case 12604ULL: goto x86_l_313c;
	case 12608ULL: goto x86_l_3140;
	case 12611ULL: goto x86_l_3143;
	case 12615ULL: goto x86_l_3147;
	case 12617ULL: goto x86_l_3149;
	case 12619ULL: goto x86_l_314b;
	case 12621ULL: goto x86_l_314d;
	case 12624ULL: goto x86_l_3150;
	case 12629ULL: goto x86_l_3155;
	case 12632ULL: goto x86_l_3158;
	case 12634ULL: goto x86_l_315a;
	case 12638ULL: goto x86_l_315e;
	case 12640ULL: goto x86_l_3160;
	case 12643ULL: goto x86_l_3163;
	case 12646ULL: goto x86_l_3166;
	case 12649ULL: goto x86_l_3169;
	case 12652ULL: goto x86_l_316c;
	case 12657ULL: goto x86_l_3171;
	case 12660ULL: goto x86_l_3174;
	case 12665ULL: goto x86_l_3179;
	case 12668ULL: goto x86_l_317c;
	case 12673ULL: goto x86_l_3181;
	case 12678ULL: goto x86_l_3186;
	case 12684ULL: goto x86_l_318c;
	case 12691ULL: goto x86_l_3193;
	case 12697ULL: goto x86_l_3199;
	case 12699ULL: goto x86_l_319b;
	case 12705ULL: goto x86_l_31a1;
	case 12709ULL: goto x86_l_31a5;
	case 12713ULL: goto x86_l_31a9;
	case 12716ULL: goto x86_l_31ac;
	case 12720ULL: goto x86_l_31b0;
	case 12723ULL: goto x86_l_31b3;
	case 12728ULL: goto x86_l_31b8;
	case 12730ULL: goto x86_l_31ba;
	case 12735ULL: goto x86_l_31bf;
	case 12743ULL: goto x86_l_31c7;
	case 12748ULL: goto x86_l_31cc;
	case 12753ULL: goto x86_l_31d1;
	case 12758ULL: goto x86_l_31d6;
	case 12763ULL: goto x86_l_31db;
	case 12765ULL: goto x86_l_31dd;
	case 12770ULL: goto x86_l_31e2;
	case 12779ULL: goto x86_l_31eb;
	case 12785ULL: goto x86_l_31f1;
	case 12793ULL: goto x86_l_31f9;
	case 12797ULL: goto x86_l_31fd;
	case 12803ULL: goto x86_l_3203;
	case 12808ULL: goto x86_l_3208;
	case 12813ULL: goto x86_l_320d;
	case 12818ULL: goto x86_l_3212;
	case 12820ULL: goto x86_l_3214;
	case 12825ULL: goto x86_l_3219;
	case 12827ULL: goto x86_l_321b;
	case 12833ULL: goto x86_l_3221;
	case 12838ULL: goto x86_l_3226;
	case 12843ULL: goto x86_l_322b;
	case 12846ULL: goto x86_l_322e;
	case 12849ULL: goto x86_l_3231;
	case 12853ULL: goto x86_l_3235;
	case 12856ULL: goto x86_l_3238;
	case 12860ULL: goto x86_l_323c;
	case 12865ULL: goto x86_l_3241;
	case 12872ULL: goto x86_l_3248;
	case 12878ULL: goto x86_l_324e;
	case 12883ULL: goto x86_l_3253;
	case 12886ULL: goto x86_l_3256;
	case 12889ULL: goto x86_l_3259;
	case 12895ULL: goto x86_l_325f;
	case 12900ULL: goto x86_l_3264;
	case 12905ULL: goto x86_l_3269;
	case 12910ULL: goto x86_l_326e;
	case 12913ULL: goto x86_l_3271;
	case 12915ULL: goto x86_l_3273;
	case 12920ULL: goto x86_l_3278;
	case 12922ULL: goto x86_l_327a;
	case 12928ULL: goto x86_l_3280;
	case 12932ULL: goto x86_l_3284;
	case 12938ULL: goto x86_l_328a;
	case 12944ULL: goto x86_l_3290;
	case 12949ULL: goto x86_l_3295;
	case 12955ULL: goto x86_l_329b;
	case 12960ULL: goto x86_l_32a0;
	case 12965ULL: goto x86_l_32a5;
	case 12970ULL: goto x86_l_32aa;
	case 12975ULL: goto x86_l_32af;
	case 12980ULL: goto x86_l_32b4;
	case 12982ULL: goto x86_l_32b6;
	case 12987ULL: goto x86_l_32bb;
	case 12992ULL: goto x86_l_32c0;
	case 12995ULL: goto x86_l_32c3;
	case 13000ULL: goto x86_l_32c8;
	case 13006ULL: goto x86_l_32ce;
	case 13010ULL: goto x86_l_32d2;
	case 13015ULL: goto x86_l_32d7;
	case 13020ULL: goto x86_l_32dc;
	case 13025ULL: goto x86_l_32e1;
	case 13028ULL: goto x86_l_32e4;
	case 13030ULL: goto x86_l_32e6;
	case 13035ULL: goto x86_l_32eb;
	case 13040ULL: goto x86_l_32f0;
	case 13045ULL: goto x86_l_32f5;
	case 13050ULL: goto x86_l_32fa;
	case 13055ULL: goto x86_l_32ff;
	case 13060ULL: goto x86_l_3304;
	case 13065ULL: goto x86_l_3309;
	case 13067ULL: goto x86_l_330b;
	case 13070ULL: goto x86_l_330e;
	case 13075ULL: goto x86_l_3313;
	case 13081ULL: goto x86_l_3319;
	case 13086ULL: goto x86_l_331e;
	case 13094ULL: goto x86_l_3326;
	case 13099ULL: goto x86_l_332b;
	case 13101ULL: goto x86_l_332d;
	case 13109ULL: goto x86_l_3335;
	case 13115ULL: goto x86_l_333b;
	case 13119ULL: goto x86_l_333f;
	case 13124ULL: goto x86_l_3344;
	case 13129ULL: goto x86_l_3349;
	case 13134ULL: goto x86_l_334e;
	case 13137ULL: goto x86_l_3351;
	case 13139ULL: goto x86_l_3353;
	case 13144ULL: goto x86_l_3358;
	case 13150ULL: goto x86_l_335e;
	case 13155ULL: goto x86_l_3363;
	case 13163ULL: goto x86_l_336b;
	case 13168ULL: goto x86_l_3370;
	case 13171ULL: goto x86_l_3373;
	case 13173ULL: goto x86_l_3375;
	case 13177ULL: goto x86_l_3379;
	case 13182ULL: goto x86_l_337e;
	case 13187ULL: goto x86_l_3383;
	case 13192ULL: goto x86_l_3388;
	case 13195ULL: goto x86_l_338b;
	case 13197ULL: goto x86_l_338d;
	case 13202ULL: goto x86_l_3392;
	case 13207ULL: goto x86_l_3397;
	case 13211ULL: goto x86_l_339b;
	case 13214ULL: goto x86_l_339e;
	case 13218ULL: goto x86_l_33a2;
	case 13220ULL: goto x86_l_33a4;
	case 13222ULL: goto x86_l_33a6;
	case 13224ULL: goto x86_l_33a8;
	case 13227ULL: goto x86_l_33ab;
	case 13232ULL: goto x86_l_33b0;
	case 13235ULL: goto x86_l_33b3;
	case 13237ULL: goto x86_l_33b5;
	case 13241ULL: goto x86_l_33b9;
	case 13243ULL: goto x86_l_33bb;
	case 13246ULL: goto x86_l_33be;
	case 13249ULL: goto x86_l_33c1;
	case 13252ULL: goto x86_l_33c4;
	case 13255ULL: goto x86_l_33c7;
	case 13260ULL: goto x86_l_33cc;
	case 13263ULL: goto x86_l_33cf;
	case 13268ULL: goto x86_l_33d4;
	case 13271ULL: goto x86_l_33d7;
	case 13276ULL: goto x86_l_33dc;
	case 13281ULL: goto x86_l_33e1;
	case 13287ULL: goto x86_l_33e7;
	case 13294ULL: goto x86_l_33ee;
	case 13300ULL: goto x86_l_33f4;
	case 13302ULL: goto x86_l_33f6;
	case 13304ULL: goto x86_l_33f8;
	case 13308ULL: goto x86_l_33fc;
	case 13312ULL: goto x86_l_3400;
	case 13315ULL: goto x86_l_3403;
	case 13319ULL: goto x86_l_3407;
	case 13322ULL: goto x86_l_340a;
	case 13327ULL: goto x86_l_340f;
	case 13329ULL: goto x86_l_3411;
	case 13334ULL: goto x86_l_3416;
	case 13342ULL: goto x86_l_341e;
	case 13347ULL: goto x86_l_3423;
	case 13351ULL: goto x86_l_3427;
	case 13356ULL: goto x86_l_342c;
	case 13359ULL: goto x86_l_342f;
	case 13364ULL: goto x86_l_3434;
	case 13369ULL: goto x86_l_3439;
	case 13371ULL: goto x86_l_343b;
	case 13376ULL: goto x86_l_3440;
	case 13379ULL: goto x86_l_3443;
	case 13384ULL: goto x86_l_3448;
	case 13389ULL: goto x86_l_344d;
	case 13394ULL: goto x86_l_3452;
	case 13399ULL: goto x86_l_3457;
	case 13404ULL: goto x86_l_345c;
	case 13409ULL: goto x86_l_3461;
	case 13414ULL: goto x86_l_3466;
	case 13416ULL: goto x86_l_3468;
	case 13421ULL: goto x86_l_346d;
	case 13426ULL: goto x86_l_3472;
	case 13429ULL: goto x86_l_3475;
	case 13434ULL: goto x86_l_347a;
	case 13436ULL: goto x86_l_347c;
	case 13440ULL: goto x86_l_3480;
	case 13445ULL: goto x86_l_3485;
	case 13450ULL: goto x86_l_348a;
	case 13455ULL: goto x86_l_348f;
	case 13458ULL: goto x86_l_3492;
	case 13460ULL: goto x86_l_3494;
	case 13462ULL: goto x86_l_3496;
	case 13467ULL: goto x86_l_349b;
	case 13471ULL: goto x86_l_349f;
	case 13476ULL: goto x86_l_34a4;
	case 13481ULL: goto x86_l_34a9;
	case 13486ULL: goto x86_l_34ae;
	case 13491ULL: goto x86_l_34b3;
	case 13493ULL: goto x86_l_34b5;
	case 13496ULL: goto x86_l_34b8;
	case 13498ULL: goto x86_l_34ba;
	case 13503ULL: goto x86_l_34bf;
	case 13506ULL: goto x86_l_34c2;
	case 13510ULL: goto x86_l_34c6;
	case 13515ULL: goto x86_l_34cb;
	case 13517ULL: goto x86_l_34cd;
	case 13519ULL: goto x86_l_34cf;
	case 13522ULL: goto x86_l_34d2;
	case 13525ULL: goto x86_l_34d5;
	case 13531ULL: goto x86_l_34db;
	case 13533ULL: goto x86_l_34dd;
	case 13535ULL: goto x86_l_34df;
	case 13538ULL: goto x86_l_34e2;
	case 13540ULL: goto x86_l_34e4;
	case 13542ULL: goto x86_l_34e6;
	case 13549ULL: goto x86_l_34ed;
	case 13555ULL: goto x86_l_34f3;
	case 13560ULL: goto x86_l_34f8;
	case 13562ULL: goto x86_l_34fa;
	case 13564ULL: goto x86_l_34fc;
	case 13568ULL: goto x86_l_3500;
	case 13574ULL: goto x86_l_3506;
	case 13579ULL: goto x86_l_350b;
	case 13584ULL: goto x86_l_3510;
	case 13589ULL: goto x86_l_3515;
	case 13597ULL: goto x86_l_351d;
	case 13599ULL: goto x86_l_351f;
	case 13604ULL: goto x86_l_3524;
	case 13609ULL: goto x86_l_3529;
	case 13613ULL: goto x86_l_352d;
	case 13618ULL: goto x86_l_3532;
	case 13623ULL: goto x86_l_3537;
	case 13625ULL: goto x86_l_3539;
	case 13630ULL: goto x86_l_353e;
	case 13635ULL: goto x86_l_3543;
	case 13640ULL: goto x86_l_3548;
	case 13645ULL: goto x86_l_354d;
	case 13647ULL: goto x86_l_354f;
	case 13651ULL: goto x86_l_3553;
	case 13658ULL: goto x86_l_355a;
	case 13663ULL: goto x86_l_355f;
	case 13671ULL: goto x86_l_3567;
	case 13674ULL: goto x86_l_356a;
	case 13679ULL: goto x86_l_356f;
	case 13686ULL: goto x86_l_3576;
	case 13688ULL: goto x86_l_3578;
	case 13690ULL: goto x86_l_357a;
	case 13700ULL: goto x86_l_3584;
	case 13710ULL: goto x86_l_358e;
	case 13712ULL: goto x86_l_3590;
	case 13714ULL: goto x86_l_3592;
	case 13721ULL: goto x86_l_3599;
	case 13727ULL: goto x86_l_359f;
	case 13731ULL: goto x86_l_35a3;
	case 13734ULL: goto x86_l_35a6;
	case 13742ULL: goto x86_l_35ae;
	case 13745ULL: goto x86_l_35b1;
	case 13751ULL: goto x86_l_35b7;
	case 13758ULL: goto x86_l_35be;
	case 13761ULL: goto x86_l_35c1;
	case 13767ULL: goto x86_l_35c7;
	case 13770ULL: goto x86_l_35ca;
	case 13776ULL: goto x86_l_35d0;
	case 13781ULL: goto x86_l_35d5;
	case 13784ULL: goto x86_l_35d8;
	case 13789ULL: goto x86_l_35dd;
	case 13797ULL: goto x86_l_35e5;
	case 13801ULL: goto x86_l_35e9;
	case 13805ULL: goto x86_l_35ed;
	case 13809ULL: goto x86_l_35f1;
	case 13816ULL: goto x86_l_35f8;
	case 13819ULL: goto x86_l_35fb;
	case 13825ULL: goto x86_l_3601;
	case 13829ULL: goto x86_l_3605;
	case 13833ULL: goto x86_l_3609;
	case 13837ULL: goto x86_l_360d;
	case 13842ULL: goto x86_l_3612;
	case 13847ULL: goto x86_l_3617;
	case 13850ULL: goto x86_l_361a;
	case 13858ULL: goto x86_l_3622;
	case 13860ULL: goto x86_l_3624;
	case 13865ULL: goto x86_l_3629;
	case 13867ULL: goto x86_l_362b;
	case 13869ULL: goto x86_l_362d;
	case 13873ULL: goto x86_l_3631;
	case 13877ULL: goto x86_l_3635;
	case 13880ULL: goto x86_l_3638;
	case 13883ULL: goto x86_l_363b;
	case 13886ULL: goto x86_l_363e;
	case 13890ULL: goto x86_l_3642;
	case 13895ULL: goto x86_l_3647;
	case 13900ULL: goto x86_l_364c;
	case 13905ULL: goto x86_l_3651;
	case 13907ULL: goto x86_l_3653;
	case 13910ULL: goto x86_l_3656;
	case 13915ULL: goto x86_l_365b;
	case 13920ULL: goto x86_l_3660;
	case 13928ULL: goto x86_l_3668;
	case 13936ULL: goto x86_l_3670;
	case 13941ULL: goto x86_l_3675;
	case 13943ULL: goto x86_l_3677;
	case 13950ULL: goto x86_l_367e;
	case 13954ULL: goto x86_l_3682;
	case 13959ULL: goto x86_l_3687;
	case 13966ULL: goto x86_l_368e;
	case 13971ULL: goto x86_l_3693;
	case 13973ULL: goto x86_l_3695;
	case 13976ULL: goto x86_l_3698;
	case 13978ULL: goto x86_l_369a;
	case 13981ULL: goto x86_l_369d;
	case 13986ULL: goto x86_l_36a2;
	case 13992ULL: goto x86_l_36a8;
	case 13997ULL: goto x86_l_36ad;
	case 14004ULL: goto x86_l_36b4;
	case 14009ULL: goto x86_l_36b9;
	case 14014ULL: goto x86_l_36be;
	case 14017ULL: goto x86_l_36c1;
	case 14019ULL: goto x86_l_36c3;
	case 14025ULL: goto x86_l_36c9;
	case 14031ULL: goto x86_l_36cf;
	case 14036ULL: goto x86_l_36d4;
	case 14041ULL: goto x86_l_36d9;
	case 14046ULL: goto x86_l_36de;
	case 14054ULL: goto x86_l_36e6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3059:
	/* 0x3059: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_305b:
	/* 0x305b: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3060:
	/* 0x3060: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_3065:
	/* 0x3065: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_3068:
	/* 0x3068: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_306d:
	/* 0x306d: je     3496 <generic_fexit_event+0x3496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3496;
	}
x86_l_3073:
	/* 0x3073: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3077:
	/* 0x3077: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_307c:
	/* 0x307c: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3081:
	/* 0x3081: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3086:
	/* 0x3086: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3089:
	/* 0x3089: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_308b:
	/* 0x308b: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3090:
	/* 0x3090: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3095:
	/* 0x3095: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_309a:
	/* 0x309a: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_309f:
	/* 0x309f: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30a4:
	/* 0x30a4: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_30a9:
	/* 0x30a9: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30ae:
	/* 0x30ae: jne    30be <generic_fexit_event+0x30be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_30be;
	}
x86_l_30b0:
	/* 0x30b0: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_30b3:
	/* 0x30b3: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_30b8:
	/* 0x30b8: je     677 <generic_fexit_event+0x677> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1655ULL;
	}
x86_l_30be:
	/* 0x30be: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30c3:
	/* 0x30c3: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_30cb:
	/* 0x30cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30d0:
	/* 0x30d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30d2:
	/* 0x30d2: cmp    r13,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 136ULL);
x86_l_30da:
	/* 0x30da: je     32a0 <generic_fexit_event+0x32a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32a0;
	}
x86_l_30e0:
	/* 0x30e0: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30e4:
	/* 0x30e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30e9:
	/* 0x30e9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30ee:
	/* 0x30ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30f3:
	/* 0x30f3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_30f6:
	/* 0x30f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30f8:
	/* 0x30f8: cmp    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30fd:
	/* 0x30fd: je     32a0 <generic_fexit_event+0x32a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32a0;
	}
x86_l_3103:
	/* 0x3103: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3108:
	/* 0x3108: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3110:
	/* 0x3110: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3115:
	/* 0x3115: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3118:
	/* 0x3118: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_311a:
	/* 0x311a: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_311e:
	/* 0x311e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3123:
	/* 0x3123: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3128:
	/* 0x3128: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_312d:
	/* 0x312d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3130:
	/* 0x3130: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3132:
	/* 0x3132: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3137:
	/* 0x3137: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_313c:
	/* 0x313c: mov    esi,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_3140:
	/* 0x3140: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3143:
	/* 0x3143: mov    edi,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3147:
	/* 0x3147: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3149:
	/* 0x3149: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_314b:
	/* 0x314b: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_314d:
	/* 0x314d: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_3150:
	/* 0x3150: add    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_3155:
	/* 0x3155: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3158:
	/* 0x3158: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_315a:
	/* 0x315a: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_315e:
	/* 0x315e: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3160:
	/* 0x3160: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_3163:
	/* 0x3163: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3166:
	/* 0x3166: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_3169:
	/* 0x3169: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_316c:
	/* 0x316c: mov    DWORD PTR [rsp+0x60],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3171:
	/* 0x3171: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3174:
	/* 0x3174: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3179:
	/* 0x3179: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_317c:
	/* 0x317c: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3181:
	/* 0x3181: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3186:
	/* 0x3186: jb     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8190ULL;
	}
x86_l_318c:
	/* 0x318c: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_3193:
	/* 0x3193: ja     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8190ULL;
	}
x86_l_3199:
	/* 0x3199: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_319b:
	/* 0x319b: jbe    343b <generic_fexit_event+0x343b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_343b;
	}
x86_l_31a1:
	/* 0x31a1: lea    r15,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_31a5:
	/* 0x31a5: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_31a9:
	/* 0x31a9: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_31ac:
	/* 0x31ac: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_31b0:
	/* 0x31b0: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_31b3:
	/* 0x31b3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31b8:
	/* 0x31b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31ba:
	/* 0x31ba: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_31bf:
	/* 0x31bf: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_31c7:
	/* 0x31c7: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_31cc:
	/* 0x31cc: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_31d1:
	/* 0x31d1: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_31d6:
	/* 0x31d6: jmp    32ff <generic_fexit_event+0x32ff> */
	goto x86_l_32ff;
x86_l_31db:
	/* 0x31db: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31dd:
	/* 0x31dd: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31e2:
	/* 0x31e2: cmp    QWORD PTR [rsp+0xa0],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767365ULL);
x86_l_31eb:
	/* 0x31eb: je     2271 <generic_fexit_event+0x2271> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8817ULL;
	}
x86_l_31f1:
	/* 0x31f1: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_31f9:
	/* 0x31f9: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_31fd:
	/* 0x31fd: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_3203:
	/* 0x3203: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3208:
	/* 0x3208: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_320d:
	/* 0x320d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3212:
	/* 0x3212: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3214:
	/* 0x3214: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_3219:
	/* 0x3219: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_321b:
	/* 0x321b: js     3923 <generic_fexit_event+0x3923> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14627ULL;
	}
x86_l_3221:
	/* 0x3221: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3226:
	/* 0x3226: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_322b:
	/* 0x322b: cmp    r15,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_322e:
	/* 0x322e: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3231:
	/* 0x3231: cmovb  r12,r15 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R15, X86_WIDTH_64, X86_CC_B);
x86_l_3235:
	/* 0x3235: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3238:
	/* 0x3238: cmovne r15,r12 */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_323c:
	/* 0x323c: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_3241:
	/* 0x3241: cmp    r15,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 4094ULL);
x86_l_3248:
	/* 0x3248: ja     3923 <generic_fexit_event+0x3923> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14627ULL;
	}
x86_l_324e:
	/* 0x324e: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3253:
	/* 0x3253: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3256:
	/* 0x3256: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_3259:
	/* 0x3259: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_325f:
	/* 0x325f: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3264:
	/* 0x3264: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3269:
	/* 0x3269: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_326e:
	/* 0x326e: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_3271:
	/* 0x3271: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3273:
	/* 0x3273: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_3278:
	/* 0x3278: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_327a:
	/* 0x327a: js     3923 <generic_fexit_event+0x3923> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14627ULL;
	}
x86_l_3280:
	/* 0x3280: add    QWORD PTR [rsp],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3284:
	/* 0x3284: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_328a:
	/* 0x328a: je     3885 <generic_fexit_event+0x3885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14469ULL;
	}
x86_l_3290:
	/* 0x3290: sub    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_3295:
	/* 0x3295: jne    388c <generic_fexit_event+0x388c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14476ULL;
	}
x86_l_329b:
	/* 0x329b: jmp    2271 <generic_fexit_event+0x2271> */
	return 8817ULL;
x86_l_32a0:
	/* 0x32a0: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32a5:
	/* 0x32a5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32aa:
	/* 0x32aa: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32af:
	/* 0x32af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32b4:
	/* 0x32b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32b6:
	/* 0x32b6: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_32bb:
	/* 0x32bb: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_32c0:
	/* 0x32c0: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_32c3:
	/* 0x32c3: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32c8:
	/* 0x32c8: je     3496 <generic_fexit_event+0x3496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3496;
	}
x86_l_32ce:
	/* 0x32ce: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_32d2:
	/* 0x32d2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32d7:
	/* 0x32d7: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_32dc:
	/* 0x32dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32e1:
	/* 0x32e1: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_32e4:
	/* 0x32e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e6:
	/* 0x32e6: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32eb:
	/* 0x32eb: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_32f0:
	/* 0x32f0: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32f5:
	/* 0x32f5: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_32fa:
	/* 0x32fa: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_32ff:
	/* 0x32ff: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_3304:
	/* 0x3304: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3309:
	/* 0x3309: jne    3319 <generic_fexit_event+0x3319> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3319;
	}
x86_l_330b:
	/* 0x330b: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_330e:
	/* 0x330e: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_3313:
	/* 0x3313: je     677 <generic_fexit_event+0x677> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1655ULL;
	}
x86_l_3319:
	/* 0x3319: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_331e:
	/* 0x331e: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3326:
	/* 0x3326: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_332b:
	/* 0x332b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_332d:
	/* 0x332d: cmp    r13,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 136ULL);
x86_l_3335:
	/* 0x3335: je     3452 <generic_fexit_event+0x3452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3452;
	}
x86_l_333b:
	/* 0x333b: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_333f:
	/* 0x333f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3344:
	/* 0x3344: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3349:
	/* 0x3349: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_334e:
	/* 0x334e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3351:
	/* 0x3351: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3353:
	/* 0x3353: cmp    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3358:
	/* 0x3358: je     3452 <generic_fexit_event+0x3452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3452;
	}
x86_l_335e:
	/* 0x335e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3363:
	/* 0x3363: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_336b:
	/* 0x336b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3370:
	/* 0x3370: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3373:
	/* 0x3373: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3375:
	/* 0x3375: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3379:
	/* 0x3379: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_337e:
	/* 0x337e: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3383:
	/* 0x3383: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3388:
	/* 0x3388: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_338b:
	/* 0x338b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_338d:
	/* 0x338d: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3392:
	/* 0x3392: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3397:
	/* 0x3397: mov    esi,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_339b:
	/* 0x339b: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_339e:
	/* 0x339e: mov    edi,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_33a2:
	/* 0x33a2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33a4:
	/* 0x33a4: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_33a6:
	/* 0x33a6: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_33a8:
	/* 0x33a8: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_33ab:
	/* 0x33ab: add    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_33b0:
	/* 0x33b0: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33b3:
	/* 0x33b3: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_33b5:
	/* 0x33b5: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_33b9:
	/* 0x33b9: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_33bb:
	/* 0x33bb: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_33be:
	/* 0x33be: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_33c1:
	/* 0x33c1: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_33c4:
	/* 0x33c4: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_33c7:
	/* 0x33c7: mov    DWORD PTR [rsp+0x60],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_33cc:
	/* 0x33cc: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_33cf:
	/* 0x33cf: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33d4:
	/* 0x33d4: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_33d7:
	/* 0x33d7: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33dc:
	/* 0x33dc: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33e1:
	/* 0x33e1: jb     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8190ULL;
	}
x86_l_33e7:
	/* 0x33e7: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_33ee:
	/* 0x33ee: ja     1ffe <generic_fexit_event+0x1ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8190ULL;
	}
x86_l_33f4:
	/* 0x33f4: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_33f6:
	/* 0x33f6: jbe    343b <generic_fexit_event+0x343b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_343b;
	}
x86_l_33f8:
	/* 0x33f8: lea    r15,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_33fc:
	/* 0x33fc: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_3400:
	/* 0x3400: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3403:
	/* 0x3403: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3407:
	/* 0x3407: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_340a:
	/* 0x340a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_340f:
	/* 0x340f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3411:
	/* 0x3411: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3416:
	/* 0x3416: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_341e:
	/* 0x341e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3423:
	/* 0x3423: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3427:
	/* 0x3427: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_342c:
	/* 0x342c: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_342f:
	/* 0x342f: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3434:
	/* 0x3434: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3439:
	/* 0x3439: jmp    34a9 <generic_fexit_event+0x34a9> */
	goto x86_l_34a9;
x86_l_343b:
	/* 0x343b: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3440:
	/* 0x3440: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_3443:
	/* 0x3443: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3448:
	/* 0x3448: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_344d:
	/* 0x344d: jmp    1fe9 <generic_fexit_event+0x1fe9> */
	return 8169ULL;
x86_l_3452:
	/* 0x3452: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3457:
	/* 0x3457: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_345c:
	/* 0x345c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3461:
	/* 0x3461: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3466:
	/* 0x3466: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3468:
	/* 0x3468: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_346d:
	/* 0x346d: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_3472:
	/* 0x3472: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_3475:
	/* 0x3475: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_347a:
	/* 0x347a: je     3496 <generic_fexit_event+0x3496> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3496;
	}
x86_l_347c:
	/* 0x347c: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3480:
	/* 0x3480: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3485:
	/* 0x3485: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_348a:
	/* 0x348a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_348f:
	/* 0x348f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3492:
	/* 0x3492: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3494:
	/* 0x3494: jmp    349b <generic_fexit_event+0x349b> */
	goto x86_l_349b;
x86_l_3496:
	/* 0x3496: mov    BYTE PTR [rsp+0x64],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 429496729601ULL);
x86_l_349b:
	/* 0x349b: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_349f:
	/* 0x349f: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34a4:
	/* 0x34a4: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_34a9:
	/* 0x34a9: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_34ae:
	/* 0x34ae: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_34b3:
	/* 0x34b3: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34b5:
	/* 0x34b5: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_34b8:
	/* 0x34b8: je     34e4 <generic_fexit_event+0x34e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34e4;
	}
x86_l_34ba:
	/* 0x34ba: cmp    BYTE PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_34bf:
	/* 0x34bf: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_34c2:
	/* 0x34c2: mov    edx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_34c6:
	/* 0x34c6: mov    ebp,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_34cb:
	/* 0x34cb: sub    ebp,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_34cd:
	/* 0x34cd: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_34cf:
	/* 0x34cf: cmovle ebp,edx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_34d2:
	/* 0x34d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_34d5:
	/* 0x34d5: je     3590 <generic_fexit_event+0x3590> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3590;
	}
x86_l_34db:
	/* 0x34db: mov    bl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_8);
x86_l_34dd:
	/* 0x34dd: add    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_34df:
	/* 0x34df: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_34e2:
	/* 0x34e2: jmp    34e6 <generic_fexit_event+0x34e6> */
	goto x86_l_34e6;
x86_l_34e4:
	/* 0x34e4: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34e6:
	/* 0x34e6: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_34ed:
	/* 0x34ed: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_34f3:
	/* 0x34f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_34f8:
	/* 0x34f8: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_34fa:
	/* 0x34fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34fc:
	/* 0x34fc: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3500:
	/* 0x3500: mov    DWORD PTR [rax+0x9c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_3506:
	/* 0x3506: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_350b:
	/* 0x350b: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3510:
	/* 0x3510: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3515:
	/* 0x3515: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_351d:
	/* 0x351d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_351f:
	/* 0x351f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3524:
	/* 0x3524: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3529:
	/* 0x3529: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_352d:
	/* 0x352d: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3532:
	/* 0x3532: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3537:
	/* 0x3537: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3539:
	/* 0x3539: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_353e:
	/* 0x353e: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3543:
	/* 0x3543: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3548:
	/* 0x3548: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_354d:
	/* 0x354d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_354f:
	/* 0x354f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3553:
	/* 0x3553: mov    DWORD PTR [rcx+rbp*1+0xa0],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 160ULL);
x86_l_355a:
	/* 0x355a: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_355f:
	/* 0x355f: mov    WORD PTR [rcx+rbp*1+0xa4],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_RBP, 0), 164ULL);
x86_l_3567:
	/* 0x3567: add    ebp,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_356a:
	/* 0x356a: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_356f:
	/* 0x356f: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3576:
	/* 0x3576: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_3578:
	/* 0x3578: jns    3599 <generic_fexit_event+0x3599> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_3599;
	}
x86_l_357a:
	/* 0x357a: mov    DWORD PTR [rcx+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104045582745599ULL);
x86_l_3584:
	/* 0x3584: mov    DWORD PTR [rcx+0x98],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 657129996287ULL);
x86_l_358e:
	/* 0x358e: jmp    35a6 <generic_fexit_event+0x35a6> */
	goto x86_l_35a6;
x86_l_3590:
	/* 0x3590: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3592:
	/* 0x3592: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3599:
	/* 0x3599: and    ebp,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_359f:
	/* 0x359f: add    rbp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_35a3:
	/* 0x35a3: mov    rbx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RBP, X86_WIDTH_64);
x86_l_35a6:
	/* 0x35a6: mov    rbp,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_35ae:
	/* 0x35ae: add    ebx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_35b1:
	/* 0x35b1: and    ebx,0x1fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 8191ULL);
x86_l_35b7:
	/* 0x35b7: add    r15,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_35be:
	/* 0x35be: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_35c1:
	/* 0x35c1: je     196 <generic_fexit_event+0x196> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 406ULL;
	}
x86_l_35c7:
	/* 0x35c7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_35ca:
	/* 0x35ca: jne    364c <generic_fexit_event+0x364c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_364c;
	}
x86_l_35d0:
	/* 0x35d0: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35d5:
	/* 0x35d5: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_35d8:
	/* 0x35d8: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35dd:
	/* 0x35dd: mov    DWORD PTR [r15+rbx*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_35e5:
	/* 0x35e5: lea    r15,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_35e9:
	/* 0x35e9: lea    r13,[rax+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_35ed:
	/* 0x35ed: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_35f1:
	/* 0x35f1: cmp    r12,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4095ULL);
x86_l_35f8:
	/* 0x35f8: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_35fb:
	/* 0x35fb: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_3601:
	/* 0x3601: cmovb  r12,r14 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R14, X86_WIDTH_64, X86_CC_B);
x86_l_3605:
	/* 0x3605: lea    rdi,[rax+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_3609:
	/* 0x3609: add    rdi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_360d:
	/* 0x360d: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_3612:
	/* 0x3612: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3617:
	/* 0x3617: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_361a:
	/* 0x361a: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3622:
	/* 0x3622: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3624:
	/* 0x3624: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_3629:
	/* 0x3629: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_362b:
	/* 0x362b: js     363b <generic_fexit_event+0x363b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_363b;
	}
x86_l_362d:
	/* 0x362d: mov    DWORD PTR [r13+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3631:
	/* 0x3631: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3635:
	/* 0x3635: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_3638:
	/* 0x3638: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_363b:
	/* 0x363b: add    rbx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_363e:
	/* 0x363e: mov    DWORD PTR [r13+0x0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3642:
	/* 0x3642: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3647:
	/* 0x3647: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_364c:
	/* 0x364c: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_3651:
	/* 0x3651: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3653:
	/* 0x3653: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3656:
	/* 0x3656: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_365b:
	/* 0x365b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3660:
	/* 0x3660: lea    rdx,[r12+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_3668:
	/* 0x3668: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3670:
	/* 0x3670: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3675:
	/* 0x3675: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3677:
	/* 0x3677: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_367e:
	/* 0x367e: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3682:
	/* 0x3682: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3687:
	/* 0x3687: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_368e:
	/* 0x368e: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3693:
	/* 0x3693: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3695:
	/* 0x3695: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3698:
	/* 0x3698: je     36a8 <generic_fexit_event+0x36a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36a8;
	}
x86_l_369a:
	/* 0x369a: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_369d:
	/* 0x369d: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_36a2:
	/* 0x36a2: jne    3820 <generic_fexit_event+0x3820> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14368ULL;
	}
x86_l_36a8:
	/* 0x36a8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_36ad:
	/* 0x36ad: add    r12,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_36b4:
	/* 0x36b4: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_36b9:
	/* 0x36b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36be:
	/* 0x36be: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_36c1:
	/* 0x36c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36c3:
	/* 0x36c3: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_36c9:
	/* 0x36c9: je     381d <generic_fexit_event+0x381d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14365ULL;
	}
x86_l_36cf:
	/* 0x36cf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_36d4:
	/* 0x36d4: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_36d9:
	/* 0x36d9: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_36de:
	/* 0x36de: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_36e6:
	/* 0x36e6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
	return 14059ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_event_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14059ULL: goto x86_l_36eb;
	case 14061ULL: goto x86_l_36ed;
	case 14068ULL: goto x86_l_36f4;
	case 14072ULL: goto x86_l_36f8;
	case 14077ULL: goto x86_l_36fd;
	case 14084ULL: goto x86_l_3704;
	case 14089ULL: goto x86_l_3709;
	case 14091ULL: goto x86_l_370b;
	case 14094ULL: goto x86_l_370e;
	case 14096ULL: goto x86_l_3710;
	case 14099ULL: goto x86_l_3713;
	case 14104ULL: goto x86_l_3718;
	case 14110ULL: goto x86_l_371e;
	case 14115ULL: goto x86_l_3723;
	case 14120ULL: goto x86_l_3728;
	case 14125ULL: goto x86_l_372d;
	case 14130ULL: goto x86_l_3732;
	case 14135ULL: goto x86_l_3737;
	case 14137ULL: goto x86_l_3739;
	case 14143ULL: goto x86_l_373f;
	case 14149ULL: goto x86_l_3745;
	case 14154ULL: goto x86_l_374a;
	case 14159ULL: goto x86_l_374f;
	case 14164ULL: goto x86_l_3754;
	case 14172ULL: goto x86_l_375c;
	case 14177ULL: goto x86_l_3761;
	case 14179ULL: goto x86_l_3763;
	case 14186ULL: goto x86_l_376a;
	case 14190ULL: goto x86_l_376e;
	case 14195ULL: goto x86_l_3773;
	case 14202ULL: goto x86_l_377a;
	case 14207ULL: goto x86_l_377f;
	case 14209ULL: goto x86_l_3781;
	case 14212ULL: goto x86_l_3784;
	case 14214ULL: goto x86_l_3786;
	case 14217ULL: goto x86_l_3789;
	case 14222ULL: goto x86_l_378e;
	case 14228ULL: goto x86_l_3794;
	case 14233ULL: goto x86_l_3799;
	case 14238ULL: goto x86_l_379e;
	case 14243ULL: goto x86_l_37a3;
	case 14248ULL: goto x86_l_37a8;
	case 14253ULL: goto x86_l_37ad;
	case 14255ULL: goto x86_l_37af;
	case 14261ULL: goto x86_l_37b5;
	case 14263ULL: goto x86_l_37b7;
	case 14268ULL: goto x86_l_37bc;
	case 14273ULL: goto x86_l_37c1;
	case 14278ULL: goto x86_l_37c6;
	case 14286ULL: goto x86_l_37ce;
	case 14291ULL: goto x86_l_37d3;
	case 14293ULL: goto x86_l_37d5;
	case 14300ULL: goto x86_l_37dc;
	case 14304ULL: goto x86_l_37e0;
	case 14309ULL: goto x86_l_37e5;
	case 14316ULL: goto x86_l_37ec;
	case 14321ULL: goto x86_l_37f1;
	case 14323ULL: goto x86_l_37f3;
	case 14326ULL: goto x86_l_37f6;
	case 14328ULL: goto x86_l_37f8;
	case 14331ULL: goto x86_l_37fb;
	case 14336ULL: goto x86_l_3800;
	case 14338ULL: goto x86_l_3802;
	case 14343ULL: goto x86_l_3807;
	case 14348ULL: goto x86_l_380c;
	case 14353ULL: goto x86_l_3811;
	case 14358ULL: goto x86_l_3816;
	case 14363ULL: goto x86_l_381b;
	case 14365ULL: goto x86_l_381d;
	case 14368ULL: goto x86_l_3820;
	case 14375ULL: goto x86_l_3827;
	case 14379ULL: goto x86_l_382b;
	case 14384ULL: goto x86_l_3830;
	case 14386ULL: goto x86_l_3832;
	case 14390ULL: goto x86_l_3836;
	case 14393ULL: goto x86_l_3839;
	case 14395ULL: goto x86_l_383b;
	case 14398ULL: goto x86_l_383e;
	case 14402ULL: goto x86_l_3842;
	case 14406ULL: goto x86_l_3846;
	case 14410ULL: goto x86_l_384a;
	case 14418ULL: goto x86_l_3852;
	case 14422ULL: goto x86_l_3856;
	case 14426ULL: goto x86_l_385a;
	case 14430ULL: goto x86_l_385e;
	case 14435ULL: goto x86_l_3863;
	case 14442ULL: goto x86_l_386a;
	case 14445ULL: goto x86_l_386d;
	case 14450ULL: goto x86_l_3872;
	case 14452ULL: goto x86_l_3874;
	case 14454ULL: goto x86_l_3876;
	case 14461ULL: goto x86_l_387d;
	case 14463ULL: goto x86_l_387f;
	case 14464ULL: goto x86_l_3880;
	case 14469ULL: goto x86_l_3885;
	case 14471ULL: goto x86_l_3887;
	case 14476ULL: goto x86_l_388c;
	case 14485ULL: goto x86_l_3895;
	case 14491ULL: goto x86_l_389b;
	case 14499ULL: goto x86_l_38a3;
	case 14503ULL: goto x86_l_38a7;
	case 14509ULL: goto x86_l_38ad;
	case 14514ULL: goto x86_l_38b2;
	case 14519ULL: goto x86_l_38b7;
	case 14524ULL: goto x86_l_38bc;
	case 14526ULL: goto x86_l_38be;
	case 14531ULL: goto x86_l_38c3;
	case 14533ULL: goto x86_l_38c5;
	case 14535ULL: goto x86_l_38c7;
	case 14540ULL: goto x86_l_38cc;
	case 14545ULL: goto x86_l_38d1;
	case 14548ULL: goto x86_l_38d4;
	case 14551ULL: goto x86_l_38d7;
	case 14555ULL: goto x86_l_38db;
	case 14558ULL: goto x86_l_38de;
	case 14562ULL: goto x86_l_38e2;
	case 14567ULL: goto x86_l_38e7;
	case 14574ULL: goto x86_l_38ee;
	case 14576ULL: goto x86_l_38f0;
	case 14579ULL: goto x86_l_38f3;
	case 14586ULL: goto x86_l_38fa;
	case 14591ULL: goto x86_l_38ff;
	case 14596ULL: goto x86_l_3904;
	case 14601ULL: goto x86_l_3909;
	case 14604ULL: goto x86_l_390c;
	case 14607ULL: goto x86_l_390f;
	case 14609ULL: goto x86_l_3911;
	case 14614ULL: goto x86_l_3916;
	case 14616ULL: goto x86_l_3918;
	case 14618ULL: goto x86_l_391a;
	case 14622ULL: goto x86_l_391e;
	case 14627ULL: goto x86_l_3923;
	case 14635ULL: goto x86_l_392b;
	case 14640ULL: goto x86_l_3930;
	case 14643ULL: goto x86_l_3933;
	default: return 0xffffffffffffffffULL;
	}
x86_l_36eb:
	/* 0x36eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36ed:
	/* 0x36ed: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_36f4:
	/* 0x36f4: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_36f8:
	/* 0x36f8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36fd:
	/* 0x36fd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_3704:
	/* 0x3704: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3709:
	/* 0x3709: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_370b:
	/* 0x370b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_370e:
	/* 0x370e: je     371e <generic_fexit_event+0x371e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_371e;
	}
x86_l_3710:
	/* 0x3710: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_3713:
	/* 0x3713: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3718:
	/* 0x3718: jne    3820 <generic_fexit_event+0x3820> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3820;
	}
x86_l_371e:
	/* 0x371e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3723:
	/* 0x3723: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_3728:
	/* 0x3728: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_372d:
	/* 0x372d: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3732:
	/* 0x3732: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3737:
	/* 0x3737: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3739:
	/* 0x3739: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_373f:
	/* 0x373f: je     381d <generic_fexit_event+0x381d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_381d;
	}
x86_l_3745:
	/* 0x3745: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_374a:
	/* 0x374a: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_374f:
	/* 0x374f: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_3754:
	/* 0x3754: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_375c:
	/* 0x375c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3761:
	/* 0x3761: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3763:
	/* 0x3763: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_376a:
	/* 0x376a: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_376e:
	/* 0x376e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3773:
	/* 0x3773: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_377a:
	/* 0x377a: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_377f:
	/* 0x377f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3781:
	/* 0x3781: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3784:
	/* 0x3784: je     3794 <generic_fexit_event+0x3794> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3794;
	}
x86_l_3786:
	/* 0x3786: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_3789:
	/* 0x3789: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_378e:
	/* 0x378e: jne    3820 <generic_fexit_event+0x3820> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3820;
	}
x86_l_3794:
	/* 0x3794: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3799:
	/* 0x3799: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_379e:
	/* 0x379e: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_37a3:
	/* 0x37a3: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_37a8:
	/* 0x37a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37ad:
	/* 0x37ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37af:
	/* 0x37af: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_37b5:
	/* 0x37b5: je     381d <generic_fexit_event+0x381d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_381d;
	}
x86_l_37b7:
	/* 0x37b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37bc:
	/* 0x37bc: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_37c1:
	/* 0x37c1: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_37c6:
	/* 0x37c6: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_37ce:
	/* 0x37ce: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_37d3:
	/* 0x37d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37d5:
	/* 0x37d5: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_37dc:
	/* 0x37dc: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_37e0:
	/* 0x37e0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37e5:
	/* 0x37e5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_37ec:
	/* 0x37ec: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_37f1:
	/* 0x37f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37f3:
	/* 0x37f3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_37f6:
	/* 0x37f6: je     3802 <generic_fexit_event+0x3802> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3802;
	}
x86_l_37f8:
	/* 0x37f8: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_37fb:
	/* 0x37fb: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3800:
	/* 0x3800: jne    3820 <generic_fexit_event+0x3820> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3820;
	}
x86_l_3802:
	/* 0x3802: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3807:
	/* 0x3807: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_380c:
	/* 0x380c: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_3811:
	/* 0x3811: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3816:
	/* 0x3816: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_381b:
	/* 0x381b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_381d:
	/* 0x381d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3820:
	/* 0x3820: mov    DWORD PTR [r14],0x10d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 269ULL);
x86_l_3827:
	/* 0x3827: mov    DWORD PTR [r14+0x4],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_382b:
	/* 0x382b: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_3830:
	/* 0x3830: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3832:
	/* 0x3832: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3836:
	/* 0x3836: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_3839:
	/* 0x3839: je     384a <generic_fexit_event+0x384a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_384a;
	}
x86_l_383b:
	/* 0x383b: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_383e:
	/* 0x383e: mov    DWORD PTR [r14+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3842:
	/* 0x3842: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3846:
	/* 0x3846: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_384a:
	/* 0x384a: mov    DWORD PTR [r14+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_3852:
	/* 0x3852: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3856:
	/* 0x3856: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_385a:
	/* 0x385a: mov    DWORD PTR [r14+0x4],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_385e:
	/* 0x385e: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3863:
	/* 0x3863: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fexit_calls)));
x86_l_386a:
	/* 0x386a: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_386d:
	/* 0x386d: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3872:
	/* 0x3872: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3874:
	/* 0x3874: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3876:
	/* 0x3876: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_387d:
	/* 0x387d: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_387f:
	/* 0x387f: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3880:
	/* 0x3880: jmp    3938 <generic_fexit_event+0x3938> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3885:
	/* 0x3885: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3887:
	/* 0x3887: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_388c:
	/* 0x388c: cmp    QWORD PTR [rsp+0xa0],0x7 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767367ULL);
x86_l_3895:
	/* 0x3895: jb     2271 <generic_fexit_event+0x2271> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8817ULL;
	}
x86_l_389b:
	/* 0x389b: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_38a3:
	/* 0x38a3: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_38a7:
	/* 0x38a7: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_38ad:
	/* 0x38ad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38b2:
	/* 0x38b2: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_38b7:
	/* 0x38b7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_38bc:
	/* 0x38bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38be:
	/* 0x38be: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_38c3:
	/* 0x38c3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38c5:
	/* 0x38c5: js     3923 <generic_fexit_event+0x3923> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3923;
	}
x86_l_38c7:
	/* 0x38c7: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_38cc:
	/* 0x38cc: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_38d1:
	/* 0x38d1: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_38d4:
	/* 0x38d4: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_38d7:
	/* 0x38d7: cmovb  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_38db:
	/* 0x38db: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_38de:
	/* 0x38de: cmove  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_E);
x86_l_38e2:
	/* 0x38e2: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_38e7:
	/* 0x38e7: cmp    r12,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4094ULL);
x86_l_38ee:
	/* 0x38ee: ja     3923 <generic_fexit_event+0x3923> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3923;
	}
x86_l_38f0:
	/* 0x38f0: add    r15,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_38f3:
	/* 0x38f3: and    r15d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_38fa:
	/* 0x38fa: add    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_38ff:
	/* 0x38ff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3904:
	/* 0x3904: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3909:
	/* 0x3909: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_390c:
	/* 0x390c: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_390f:
	/* 0x390f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3911:
	/* 0x3911: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_3916:
	/* 0x3916: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3918:
	/* 0x3918: js     3923 <generic_fexit_event+0x3923> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3923;
	}
x86_l_391a:
	/* 0x391a: add    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_391e:
	/* 0x391e: jmp    2275 <generic_fexit_event+0x2275> */
	return 8821ULL;
x86_l_3923:
	/* 0x3923: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_392b:
	/* 0x392b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3930:
	/* 0x3930: mov    DWORD PTR [rdx+rax*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3933:
	/* 0x3933: jmp    1723 <generic_fexit_event+0x1723> */
	return 5923ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_fexit_generic_fexit_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 12828U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1856ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1861ULL && __x86_pc <= 3582ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3587ULL && __x86_pc <= 5422ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5426ULL && __x86_pc <= 7208ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7212ULL && __x86_pc <= 8902ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8906ULL && __x86_pc <= 10591ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10594ULL && __x86_pc <= 12372ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_event_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12377ULL && __x86_pc <= 14054ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_event_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14059ULL && __x86_pc <= 14643ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_event_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

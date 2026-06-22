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

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 5ULL: goto x86_l_5;
	case 7ULL: goto x86_l_7;
	case 9ULL: goto x86_l_9;
	case 10ULL: goto x86_l_a;
	case 17ULL: goto x86_l_11;
	case 20ULL: goto x86_l_14;
	case 28ULL: goto x86_l_1c;
	case 35ULL: goto x86_l_23;
	case 40ULL: goto x86_l_28;
	case 45ULL: goto x86_l_2d;
	case 47ULL: goto x86_l_2f;
	case 50ULL: goto x86_l_32;
	case 56ULL: goto x86_l_38;
	case 59ULL: goto x86_l_3b;
	case 61ULL: goto x86_l_3d;
	case 68ULL: goto x86_l_44;
	case 75ULL: goto x86_l_4b;
	case 83ULL: goto x86_l_53;
	case 88ULL: goto x86_l_58;
	case 90ULL: goto x86_l_5a;
	case 93ULL: goto x86_l_5d;
	case 99ULL: goto x86_l_63;
	case 102ULL: goto x86_l_66;
	case 110ULL: goto x86_l_6e;
	case 117ULL: goto x86_l_75;
	case 122ULL: goto x86_l_7a;
	case 127ULL: goto x86_l_7f;
	case 129ULL: goto x86_l_81;
	case 132ULL: goto x86_l_84;
	case 138ULL: goto x86_l_8a;
	case 141ULL: goto x86_l_8d;
	case 150ULL: goto x86_l_96;
	case 155ULL: goto x86_l_9b;
	case 161ULL: goto x86_l_a1;
	case 168ULL: goto x86_l_a8;
	case 174ULL: goto x86_l_ae;
	case 183ULL: goto x86_l_b7;
	case 187ULL: goto x86_l_bb;
	case 192ULL: goto x86_l_c0;
	case 197ULL: goto x86_l_c5;
	case 203ULL: goto x86_l_cb;
	case 207ULL: goto x86_l_cf;
	case 212ULL: goto x86_l_d4;
	case 215ULL: goto x86_l_d7;
	case 218ULL: goto x86_l_da;
	case 224ULL: goto x86_l_e0;
	case 229ULL: goto x86_l_e5;
	case 234ULL: goto x86_l_ea;
	case 239ULL: goto x86_l_ef;
	case 244ULL: goto x86_l_f4;
	case 250ULL: goto x86_l_fa;
	case 255ULL: goto x86_l_ff;
	case 260ULL: goto x86_l_104;
	case 265ULL: goto x86_l_109;
	case 272ULL: goto x86_l_110;
	case 276ULL: goto x86_l_114;
	case 282ULL: goto x86_l_11a;
	case 290ULL: goto x86_l_122;
	case 297ULL: goto x86_l_129;
	case 302ULL: goto x86_l_12e;
	case 307ULL: goto x86_l_133;
	case 309ULL: goto x86_l_135;
	case 312ULL: goto x86_l_138;
	case 318ULL: goto x86_l_13e;
	case 321ULL: goto x86_l_141;
	case 326ULL: goto x86_l_146;
	case 333ULL: goto x86_l_14d;
	case 336ULL: goto x86_l_150;
	case 342ULL: goto x86_l_156;
	case 351ULL: goto x86_l_15f;
	case 356ULL: goto x86_l_164;
	case 362ULL: goto x86_l_16a;
	case 367ULL: goto x86_l_16f;
	case 369ULL: goto x86_l_171;
	case 376ULL: goto x86_l_178;
	case 379ULL: goto x86_l_17b;
	case 384ULL: goto x86_l_180;
	case 389ULL: goto x86_l_185;
	case 395ULL: goto x86_l_18b;
	case 400ULL: goto x86_l_190;
	case 403ULL: goto x86_l_193;
	case 406ULL: goto x86_l_196;
	case 409ULL: goto x86_l_199;
	case 415ULL: goto x86_l_19f;
	case 422ULL: goto x86_l_1a6;
	case 425ULL: goto x86_l_1a9;
	case 431ULL: goto x86_l_1af;
	case 439ULL: goto x86_l_1b7;
	case 446ULL: goto x86_l_1be;
	case 451ULL: goto x86_l_1c3;
	case 456ULL: goto x86_l_1c8;
	case 458ULL: goto x86_l_1ca;
	case 461ULL: goto x86_l_1cd;
	case 467ULL: goto x86_l_1d3;
	case 470ULL: goto x86_l_1d6;
	case 473ULL: goto x86_l_1d9;
	case 479ULL: goto x86_l_1df;
	case 489ULL: goto x86_l_1e9;
	case 494ULL: goto x86_l_1ee;
	case 504ULL: goto x86_l_1f8;
	case 509ULL: goto x86_l_1fd;
	case 519ULL: goto x86_l_207;
	case 524ULL: goto x86_l_20c;
	case 534ULL: goto x86_l_216;
	case 539ULL: goto x86_l_21b;
	case 549ULL: goto x86_l_225;
	case 554ULL: goto x86_l_22a;
	case 564ULL: goto x86_l_234;
	case 569ULL: goto x86_l_239;
	case 577ULL: goto x86_l_241;
	case 582ULL: goto x86_l_246;
	case 587ULL: goto x86_l_24b;
	case 592ULL: goto x86_l_250;
	case 597ULL: goto x86_l_255;
	case 599ULL: goto x86_l_257;
	case 601ULL: goto x86_l_259;
	case 606ULL: goto x86_l_25e;
	case 610ULL: goto x86_l_262;
	case 617ULL: goto x86_l_269;
	case 622ULL: goto x86_l_26e;
	case 627ULL: goto x86_l_273;
	case 633ULL: goto x86_l_279;
	case 638ULL: goto x86_l_27e;
	case 643ULL: goto x86_l_283;
	case 648ULL: goto x86_l_288;
	case 653ULL: goto x86_l_28d;
	case 655ULL: goto x86_l_28f;
	case 658ULL: goto x86_l_292;
	case 664ULL: goto x86_l_298;
	case 667ULL: goto x86_l_29b;
	case 669ULL: goto x86_l_29d;
	case 673ULL: goto x86_l_2a1;
	case 679ULL: goto x86_l_2a7;
	case 685ULL: goto x86_l_2ad;
	case 690ULL: goto x86_l_2b2;
	case 697ULL: goto x86_l_2b9;
	case 705ULL: goto x86_l_2c1;
	case 712ULL: goto x86_l_2c8;
	case 717ULL: goto x86_l_2cd;
	case 722ULL: goto x86_l_2d2;
	case 724ULL: goto x86_l_2d4;
	case 727ULL: goto x86_l_2d7;
	case 729ULL: goto x86_l_2d9;
	case 736ULL: goto x86_l_2e0;
	case 739ULL: goto x86_l_2e3;
	case 745ULL: goto x86_l_2e9;
	case 748ULL: goto x86_l_2ec;
	case 758ULL: goto x86_l_2f6;
	case 766ULL: goto x86_l_2fe;
	case 773ULL: goto x86_l_305;
	case 778ULL: goto x86_l_30a;
	case 783ULL: goto x86_l_30f;
	case 785ULL: goto x86_l_311;
	case 788ULL: goto x86_l_314;
	case 790ULL: goto x86_l_316;
	case 793ULL: goto x86_l_319;
	case 795ULL: goto x86_l_31b;
	case 802ULL: goto x86_l_322;
	case 804ULL: goto x86_l_324;
	case 809ULL: goto x86_l_329;
	case 812ULL: goto x86_l_32c;
	case 814ULL: goto x86_l_32e;
	case 819ULL: goto x86_l_333;
	case 823ULL: goto x86_l_337;
	case 828ULL: goto x86_l_33c;
	case 833ULL: goto x86_l_341;
	case 839ULL: goto x86_l_347;
	case 843ULL: goto x86_l_34b;
	case 848ULL: goto x86_l_350;
	case 851ULL: goto x86_l_353;
	case 854ULL: goto x86_l_356;
	case 859ULL: goto x86_l_35b;
	case 862ULL: goto x86_l_35e;
	case 868ULL: goto x86_l_364;
	case 873ULL: goto x86_l_369;
	case 876ULL: goto x86_l_36c;
	case 882ULL: goto x86_l_372;
	case 887ULL: goto x86_l_377;
	case 890ULL: goto x86_l_37a;
	case 896ULL: goto x86_l_380;
	case 898ULL: goto x86_l_382;
	case 900ULL: goto x86_l_384;
	case 907ULL: goto x86_l_38b;
	case 910ULL: goto x86_l_38e;
	case 916ULL: goto x86_l_394;
	case 919ULL: goto x86_l_397;
	case 927ULL: goto x86_l_39f;
	case 929ULL: goto x86_l_3a1;
	case 931ULL: goto x86_l_3a3;
	case 937ULL: goto x86_l_3a9;
	case 939ULL: goto x86_l_3ab;
	case 946ULL: goto x86_l_3b2;
	case 951ULL: goto x86_l_3b7;
	case 954ULL: goto x86_l_3ba;
	case 956ULL: goto x86_l_3bc;
	case 958ULL: goto x86_l_3be;
	case 963ULL: goto x86_l_3c3;
	case 970ULL: goto x86_l_3ca;
	case 971ULL: goto x86_l_3cb;
	case 973ULL: goto x86_l_3cd;
	case 975ULL: goto x86_l_3cf;
	case 977ULL: goto x86_l_3d1;
	case 979ULL: goto x86_l_3d3;
	case 980ULL: goto x86_l_3d4;
	case 985ULL: goto x86_l_3d9;
	case 990ULL: goto x86_l_3de;
	case 996ULL: goto x86_l_3e4;
	case 1001ULL: goto x86_l_3e9;
	case 1004ULL: goto x86_l_3ec;
	case 1010ULL: goto x86_l_3f2;
	case 1017ULL: goto x86_l_3f9;
	case 1022ULL: goto x86_l_3fe;
	case 1025ULL: goto x86_l_401;
	case 1031ULL: goto x86_l_407;
	case 1038ULL: goto x86_l_40e;
	case 1041ULL: goto x86_l_411;
	case 1047ULL: goto x86_l_417;
	case 1050ULL: goto x86_l_41a;
	case 1059ULL: goto x86_l_423;
	case 1068ULL: goto x86_l_42c;
	case 1073ULL: goto x86_l_431;
	case 1076ULL: goto x86_l_434;
	case 1081ULL: goto x86_l_439;
	case 1086ULL: goto x86_l_43e;
	case 1092ULL: goto x86_l_444;
	case 1097ULL: goto x86_l_449;
	case 1102ULL: goto x86_l_44e;
	case 1107ULL: goto x86_l_453;
	case 1110ULL: goto x86_l_456;
	case 1115ULL: goto x86_l_45b;
	case 1120ULL: goto x86_l_460;
	case 1125ULL: goto x86_l_465;
	case 1130ULL: goto x86_l_46a;
	case 1136ULL: goto x86_l_470;
	case 1141ULL: goto x86_l_475;
	case 1146ULL: goto x86_l_47a;
	case 1151ULL: goto x86_l_47f;
	case 1154ULL: goto x86_l_482;
	case 1160ULL: goto x86_l_488;
	case 1166ULL: goto x86_l_48e;
	case 1171ULL: goto x86_l_493;
	case 1174ULL: goto x86_l_496;
	case 1180ULL: goto x86_l_49c;
	case 1185ULL: goto x86_l_4a1;
	case 1188ULL: goto x86_l_4a4;
	case 1193ULL: goto x86_l_4a9;
	case 1198ULL: goto x86_l_4ae;
	case 1204ULL: goto x86_l_4b4;
	case 1209ULL: goto x86_l_4b9;
	case 1214ULL: goto x86_l_4be;
	case 1219ULL: goto x86_l_4c3;
	case 1222ULL: goto x86_l_4c6;
	case 1225ULL: goto x86_l_4c9;
	case 1231ULL: goto x86_l_4cf;
	case 1238ULL: goto x86_l_4d6;
	case 1242ULL: goto x86_l_4da;
	case 1248ULL: goto x86_l_4e0;
	case 1255ULL: goto x86_l_4e7;
	case 1262ULL: goto x86_l_4ee;
	case 1265ULL: goto x86_l_4f1;
	case 1270ULL: goto x86_l_4f6;
	case 1272ULL: goto x86_l_4f8;
	case 1275ULL: goto x86_l_4fb;
	case 1281ULL: goto x86_l_501;
	case 1284ULL: goto x86_l_504;
	case 1289ULL: goto x86_l_509;
	case 1294ULL: goto x86_l_50e;
	case 1297ULL: goto x86_l_511;
	case 1302ULL: goto x86_l_516;
	case 1307ULL: goto x86_l_51b;
	case 1313ULL: goto x86_l_521;
	case 1318ULL: goto x86_l_526;
	case 1321ULL: goto x86_l_529;
	case 1326ULL: goto x86_l_52e;
	case 1329ULL: goto x86_l_531;
	case 1332ULL: goto x86_l_534;
	case 1338ULL: goto x86_l_53a;
	case 1345ULL: goto x86_l_541;
	case 1349ULL: goto x86_l_545;
	case 1355ULL: goto x86_l_54b;
	case 1363ULL: goto x86_l_553;
	case 1370ULL: goto x86_l_55a;
	case 1375ULL: goto x86_l_55f;
	case 1380ULL: goto x86_l_564;
	case 1382ULL: goto x86_l_566;
	case 1385ULL: goto x86_l_569;
	case 1391ULL: goto x86_l_56f;
	case 1394ULL: goto x86_l_572;
	case 1399ULL: goto x86_l_577;
	case 1406ULL: goto x86_l_57e;
	case 1412ULL: goto x86_l_584;
	case 1417ULL: goto x86_l_589;
	case 1420ULL: goto x86_l_58c;
	case 1425ULL: goto x86_l_591;
	case 1428ULL: goto x86_l_594;
	case 1431ULL: goto x86_l_597;
	case 1437ULL: goto x86_l_59d;
	case 1442ULL: goto x86_l_5a2;
	case 1445ULL: goto x86_l_5a5;
	case 1450ULL: goto x86_l_5aa;
	case 1459ULL: goto x86_l_5b3;
	case 1468ULL: goto x86_l_5bc;
	case 1473ULL: goto x86_l_5c1;
	case 1476ULL: goto x86_l_5c4;
	case 1481ULL: goto x86_l_5c9;
	case 1486ULL: goto x86_l_5ce;
	case 1492ULL: goto x86_l_5d4;
	case 1497ULL: goto x86_l_5d9;
	case 1502ULL: goto x86_l_5de;
	case 1507ULL: goto x86_l_5e3;
	case 1510ULL: goto x86_l_5e6;
	case 1515ULL: goto x86_l_5eb;
	case 1520ULL: goto x86_l_5f0;
	case 1525ULL: goto x86_l_5f5;
	case 1530ULL: goto x86_l_5fa;
	case 1536ULL: goto x86_l_600;
	case 1541ULL: goto x86_l_605;
	case 1546ULL: goto x86_l_60a;
	case 1551ULL: goto x86_l_60f;
	case 1554ULL: goto x86_l_612;
	case 1560ULL: goto x86_l_618;
	case 1566ULL: goto x86_l_61e;
	case 1571ULL: goto x86_l_623;
	case 1574ULL: goto x86_l_626;
	case 1580ULL: goto x86_l_62c;
	case 1585ULL: goto x86_l_631;
	case 1588ULL: goto x86_l_634;
	case 1593ULL: goto x86_l_639;
	case 1598ULL: goto x86_l_63e;
	case 1604ULL: goto x86_l_644;
	case 1609ULL: goto x86_l_649;
	case 1614ULL: goto x86_l_64e;
	case 1619ULL: goto x86_l_653;
	case 1622ULL: goto x86_l_656;
	case 1625ULL: goto x86_l_659;
	case 1631ULL: goto x86_l_65f;
	case 1636ULL: goto x86_l_664;
	case 1641ULL: goto x86_l_669;
	case 1646ULL: goto x86_l_66e;
	case 1651ULL: goto x86_l_673;
	case 1657ULL: goto x86_l_679;
	case 1662ULL: goto x86_l_67e;
	case 1667ULL: goto x86_l_683;
	case 1672ULL: goto x86_l_688;
	case 1675ULL: goto x86_l_68b;
	case 1678ULL: goto x86_l_68e;
	case 1684ULL: goto x86_l_694;
	case 1689ULL: goto x86_l_699;
	case 1694ULL: goto x86_l_69e;
	case 1699ULL: goto x86_l_6a3;
	case 1704ULL: goto x86_l_6a8;
	case 1710ULL: goto x86_l_6ae;
	case 1715ULL: goto x86_l_6b3;
	case 1720ULL: goto x86_l_6b8;
	case 1725ULL: goto x86_l_6bd;
	case 1728ULL: goto x86_l_6c0;
	case 1731ULL: goto x86_l_6c3;
	case 1737ULL: goto x86_l_6c9;
	case 1742ULL: goto x86_l_6ce;
	case 1745ULL: goto x86_l_6d1;
	case 1750ULL: goto x86_l_6d6;
	case 1755ULL: goto x86_l_6db;
	case 1758ULL: goto x86_l_6de;
	case 1762ULL: goto x86_l_6e2;
	case 1768ULL: goto x86_l_6e8;
	case 1770ULL: goto x86_l_6ea;
	case 1773ULL: goto x86_l_6ed;
	case 1778ULL: goto x86_l_6f2;
	case 1783ULL: goto x86_l_6f7;
	case 1786ULL: goto x86_l_6fa;
	case 1791ULL: goto x86_l_6ff;
	case 1796ULL: goto x86_l_704;
	case 1802ULL: goto x86_l_70a;
	case 1807ULL: goto x86_l_70f;
	case 1810ULL: goto x86_l_712;
	case 1815ULL: goto x86_l_717;
	case 1818ULL: goto x86_l_71a;
	case 1821ULL: goto x86_l_71d;
	case 1827ULL: goto x86_l_723;
	case 1834ULL: goto x86_l_72a;
	case 1838ULL: goto x86_l_72e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_3:
	/* 0x3: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_5:
	/* 0x5: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_7:
	/* 0x7: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_9:
	/* 0x9: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_a:
	/* 0xa: sub    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 152ULL);
x86_l_11:
	/* 0x11: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1c:
	/* 0x1c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&per_cpu_records)));
x86_l_23:
	/* 0x23: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28:
	/* 0x28: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d:
	/* 0x2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f:
	/* 0x2f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32:
	/* 0x32: je     3be <perf_unwind_ruby+0x3be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3be;
	}
x86_l_38:
	/* 0x38: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3b:
	/* 0x3b: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d:
	/* 0x3d: mov    DWORD PTR [rsp+0x84],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_44:
	/* 0x44: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ruby_procs)));
x86_l_4b:
	/* 0x4b: lea    rsi,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_53:
	/* 0x53: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_58:
	/* 0x58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a:
	/* 0x5a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5d:
	/* 0x5d: je     109 <perf_unwind_ruby+0x109> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_109;
	}
x86_l_63:
	/* 0x63: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_66:
	/* 0x66: mov    DWORD PTR [rsp+0x8],0x35 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738421ULL);
x86_l_6e:
	/* 0x6e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_75:
	/* 0x75: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7a:
	/* 0x7a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7f:
	/* 0x7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_81:
	/* 0x81: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_84:
	/* 0x84: je     146 <perf_unwind_ruby+0x146> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_146;
	}
x86_l_8a:
	/* 0x8a: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_8d:
	/* 0x8d: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_96:
	/* 0x96: cmp    QWORD PTR [r15+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_9b:
	/* 0x9b: jne    16a <perf_unwind_ruby+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16a;
	}
x86_l_a1:
	/* 0xa1: cmp    DWORD PTR [r15],0x30000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 196608ULL);
x86_l_a8:
	/* 0xa8: jb     333 <perf_unwind_ruby+0x333> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_333;
	}
x86_l_ae:
	/* 0xae: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_b7:
	/* 0xb7: mov    rax,QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bb:
	/* 0xbb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c0:
	/* 0xc0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c5:
	/* 0xc5: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_cb:
	/* 0xcb: mov    rdx,QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cf:
	/* 0xcf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d4:
	/* 0xd4: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_d7:
	/* 0xd7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_da:
	/* 0xda: jne    298 <perf_unwind_ruby+0x298> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_298;
	}
x86_l_e0:
	/* 0xe0: movzx  eax,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_e5:
	/* 0xe5: add    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_ea:
	/* 0xea: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ef:
	/* 0xef: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f4:
	/* 0xf4: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_fa:
	/* 0xfa: movzx  edx,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_ff:
	/* 0xff: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_104:
	/* 0x104: jmp    34b <perf_unwind_ruby+0x34b> */
	goto x86_l_34b;
x86_l_109:
	/* 0x109: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_110:
	/* 0x110: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_114:
	/* 0x114: jne    fb4 <perf_unwind_ruby+0xfb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4020ULL;
	}
x86_l_11a:
	/* 0x11a: mov    DWORD PTR [rsp+0x8],0x49 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738441ULL);
x86_l_122:
	/* 0x122: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_129:
	/* 0x129: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12e:
	/* 0x12e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_133:
	/* 0x133: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135:
	/* 0x135: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_138:
	/* 0x138: je     29d <perf_unwind_ruby+0x29d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29d;
	}
x86_l_13e:
	/* 0x13e: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_141:
	/* 0x141: jmp    2a7 <perf_unwind_ruby+0x2a7> */
	goto x86_l_2a7;
x86_l_146:
	/* 0x146: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_14d:
	/* 0x14d: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_150:
	/* 0x150: jne    1270 <perf_unwind_ruby+0x1270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4720ULL;
	}
x86_l_156:
	/* 0x156: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_15f:
	/* 0x15f: cmp    QWORD PTR [r15+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_164:
	/* 0x164: je     a1 <perf_unwind_ruby+0xa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a1;
	}
x86_l_16a:
	/* 0x16a: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_16f:
	/* 0x16f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_171:
	/* 0x171: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&tpbase_offset)));
x86_l_178:
	/* 0x178: add    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_17b:
	/* 0x17b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_180:
	/* 0x180: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_185:
	/* 0x185: mov    r8d,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 113ULL);
x86_l_18b:
	/* 0x18b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_190:
	/* 0x190: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_193:
	/* 0x193: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_196:
	/* 0x196: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_199:
	/* 0x199: je     25e <perf_unwind_ruby+0x25e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e;
	}
x86_l_19f:
	/* 0x19f: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1a6:
	/* 0x1a6: cmp    DWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a9:
	/* 0x1a9: jne    10a7 <perf_unwind_ruby+0x10a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4263ULL;
	}
x86_l_1af:
	/* 0x1af: mov    DWORD PTR [rsp+0x20],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953476ULL);
x86_l_1b7:
	/* 0x1b7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_1be:
	/* 0x1be: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c3:
	/* 0x1c3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c8:
	/* 0x1c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca:
	/* 0x1ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cd:
	/* 0x1cd: je     377 <perf_unwind_ruby+0x377> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_377;
	}
x86_l_1d3:
	/* 0x1d3: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1d6:
	/* 0x1d6: cmp    DWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d9:
	/* 0x1d9: je     380 <perf_unwind_ruby+0x380> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_380;
	}
x86_l_1df:
	/* 0x1df: movabs rax,0x6b6f6f6c206c6f62 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7741528794664300386ULL);
x86_l_1e9:
	/* 0x1e9: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1ee:
	/* 0x1ee: movabs rax,0x6d797320534c5420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7888462804989793312ULL);
x86_l_1f8:
	/* 0x1f8: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1fd:
	/* 0x1fd: movabs rax,0x726f662065736162 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732065714530ULL);
x86_l_207:
	/* 0x207: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_20c:
	/* 0x20c: movabs rax,0x2044535420746567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2325074928416875879ULL);
x86_l_216:
	/* 0x216: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_21b:
	/* 0x21b: movabs rax,0x206f742064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414100720745ULL);
x86_l_225:
	/* 0x225: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_22a:
	/* 0x22a: movabs rax,0x6166203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332504820184434ULL);
x86_l_234:
	/* 0x234: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_239:
	/* 0x239: mov    DWORD PTR [rsp+0x60],0xa7075 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412317544565ULL);
x86_l_241:
	/* 0x241: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_246:
	/* 0x246: mov    eax,0x34 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 52ULL);
x86_l_24b:
	/* 0x24b: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_250:
	/* 0x250: mov    esi,0x34 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 52ULL);
x86_l_255:
	/* 0x255: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_257:
	/* 0x257: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_259:
	/* 0x259: jmp    380 <perf_unwind_ruby+0x380> */
	goto x86_l_380;
x86_l_25e:
	/* 0x25e: mov    rdx,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_262:
	/* 0x262: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_269:
	/* 0x269: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_26e:
	/* 0x26e: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_273:
	/* 0x273: jne    1426 <perf_unwind_ruby+0x1426> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5158ULL;
	}
x86_l_279:
	/* 0x279: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_27e:
	/* 0x27e: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_283:
	/* 0x283: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_288:
	/* 0x288: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28d:
	/* 0x28d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_28f:
	/* 0x28f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_292:
	/* 0x292: je     3d9 <perf_unwind_ruby+0x3d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d9;
	}
x86_l_298:
	/* 0x298: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29b:
	/* 0x29b: jmp    2ad <perf_unwind_ruby+0x2ad> */
	goto x86_l_2ad;
x86_l_29d:
	/* 0x29d: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a1:
	/* 0x2a1: jne    14ad <perf_unwind_ruby+0x14ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5293ULL;
	}
x86_l_2a7:
	/* 0x2a7: mov    r13d,0xbb8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3000ULL);
x86_l_2ad:
	/* 0x2ad: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2b2:
	/* 0x2b2: mov    DWORD PTR [r14+0xf2c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3884ULL);
x86_l_2b9:
	/* 0x2b9: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2c1:
	/* 0x2c1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&per_cpu_records)));
x86_l_2c8:
	/* 0x2c8: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2cd:
	/* 0x2cd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d2:
	/* 0x2d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d4:
	/* 0x2d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d7:
	/* 0x2d7: je     31b <perf_unwind_ruby+0x31b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31b;
	}
x86_l_2d9:
	/* 0x2d9: movzx  ecx,BYTE PTR [rax+0x1384] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4996ULL);
x86_l_2e0:
	/* 0x2e0: cmp    cl,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_2e3:
	/* 0x2e3: jb     3a1 <perf_unwind_ruby+0x3a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3a1;
	}
x86_l_2e9:
	/* 0x2e9: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_2ec:
	/* 0x2ec: mov    DWORD PTR [rax+0xf2c],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16681652977669ULL);
x86_l_2f6:
	/* 0x2f6: mov    DWORD PTR [rsp+0x8],0x44 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738436ULL);
x86_l_2fe:
	/* 0x2fe: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_305:
	/* 0x305: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30a:
	/* 0x30a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30f:
	/* 0x30f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_311:
	/* 0x311: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_314:
	/* 0x314: je     384 <perf_unwind_ruby+0x384> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_384;
	}
x86_l_316:
	/* 0x316: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_319:
	/* 0x319: jmp    394 <perf_unwind_ruby+0x394> */
	goto x86_l_394;
x86_l_31b:
	/* 0x31b: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&perf_progs)));
x86_l_322:
	/* 0x322: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_324:
	/* 0x324: mov    ecx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_329:
	/* 0x329: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_32c:
	/* 0x32c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32e:
	/* 0x32e: jmp    3bc <perf_unwind_ruby+0x3bc> */
	goto x86_l_3bc;
x86_l_333:
	/* 0x333: mov    rax,QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_337:
	/* 0x337: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_33c:
	/* 0x33c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_341:
	/* 0x341: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_347:
	/* 0x347: mov    rdx,QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34b:
	/* 0x34b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_350:
	/* 0x350: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_353:
	/* 0x353: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_356:
	/* 0x356: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_35b:
	/* 0x35b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35e:
	/* 0x35e: jne    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b2;
	}
x86_l_364:
	/* 0x364: mov    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_369:
	/* 0x369: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_36c:
	/* 0x36c: jne    3f2 <perf_unwind_ruby+0x3f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3f2;
	}
x86_l_372:
	/* 0x372: jmp    2b2 <perf_unwind_ruby+0x2b2> */
	goto x86_l_2b2;
x86_l_377:
	/* 0x377: cmp    DWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37a:
	/* 0x37a: jne    1578 <perf_unwind_ruby+0x1578> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5496ULL;
	}
x86_l_380:
	/* 0x380: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_382:
	/* 0x382: jmp    3c3 <perf_unwind_ruby+0x3c3> */
	goto x86_l_3c3;
x86_l_384:
	/* 0x384: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_38b:
	/* 0x38b: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38e:
	/* 0x38e: jne    15fc <perf_unwind_ruby+0x15fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5628ULL;
	}
x86_l_394:
	/* 0x394: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_397:
	/* 0x397: movzx  ecx,BYTE PTR [r14+0x1384] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4996ULL);
x86_l_39f:
	/* 0x39f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3a1:
	/* 0x3a1: inc    cl */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_INC, 1);
x86_l_3a3:
	/* 0x3a3: mov    BYTE PTR [rax+0x1384],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4996ULL);
x86_l_3a9:
	/* 0x3a9: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_3ab:
	/* 0x3ab: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&perf_progs)));
x86_l_3b2:
	/* 0x3b2: mov    ecx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_3b7:
	/* 0x3b7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3ba:
	/* 0x3ba: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_3bc:
	/* 0x3bc: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3be:
	/* 0x3be: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_3c3:
	/* 0x3c3: add    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_3ca:
	/* 0x3ca: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3cb:
	/* 0x3cb: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3cd:
	/* 0x3cd: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_3cf:
	/* 0x3cf: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3d1:
	/* 0x3d1: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3d3:
	/* 0x3d3: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3d4:
	/* 0x3d4: jmp    6e8f <perf_unwind_ruby+0x6e8f> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3d9:
	/* 0x3d9: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3de:
	/* 0x3de: jne    1677 <perf_unwind_ruby+0x1677> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5751ULL;
	}
x86_l_3e4:
	/* 0x3e4: mov    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3e9:
	/* 0x3e9: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_3ec:
	/* 0x3ec: je     298 <perf_unwind_ruby+0x298> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_298;
	}
x86_l_3f2:
	/* 0x3f2: mov    rax,QWORD PTR [r14+0xf68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3944ULL);
x86_l_3f9:
	/* 0x3f9: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fe:
	/* 0x3fe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_401:
	/* 0x401: je     509 <perf_unwind_ruby+0x509> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_509;
	}
x86_l_407:
	/* 0x407: mov    r13,QWORD PTR [r14+0xf70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3952ULL);
x86_l_40e:
	/* 0x40e: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_411:
	/* 0x411: je     509 <perf_unwind_ruby+0x509> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_509;
	}
x86_l_417:
	/* 0x417: mov    r12,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_64);
x86_l_41a:
	/* 0x41a: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_423:
	/* 0x423: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_42c:
	/* 0x42c: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_431:
	/* 0x431: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_434:
	/* 0x434: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_439:
	/* 0x439: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_43e:
	/* 0x43e: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_444:
	/* 0x444: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_449:
	/* 0x449: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_44e:
	/* 0x44e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_453:
	/* 0x453: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_456:
	/* 0x456: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_45b:
	/* 0x45b: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_460:
	/* 0x460: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_465:
	/* 0x465: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_46a:
	/* 0x46a: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_470:
	/* 0x470: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_475:
	/* 0x475: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_47a:
	/* 0x47a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47f:
	/* 0x47f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_482:
	/* 0x482: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_488:
	/* 0x488: je     577 <perf_unwind_ruby+0x577> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_577;
	}
x86_l_48e:
	/* 0x48e: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_493:
	/* 0x493: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_496:
	/* 0x496: je     577 <perf_unwind_ruby+0x577> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_577;
	}
x86_l_49c:
	/* 0x49c: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_4a1:
	/* 0x4a1: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4a4:
	/* 0x4a4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a9:
	/* 0x4a9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4ae:
	/* 0x4ae: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4b4:
	/* 0x4b4: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_4b9:
	/* 0x4b9: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_4be:
	/* 0x4be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c3:
	/* 0x4c3: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4c6:
	/* 0x4c6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c9:
	/* 0x4c9: je     7ef <perf_unwind_ruby+0x7ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2031ULL;
	}
x86_l_4cf:
	/* 0x4cf: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4d6:
	/* 0x4d6: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4da:
	/* 0x4da: jne    1a6d <perf_unwind_ruby+0x1a6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6765ULL;
	}
x86_l_4e0:
	/* 0x4e0: mov    DWORD PTR [rsp],0x4e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_4e7:
	/* 0x4e7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_4ee:
	/* 0x4ee: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4f1:
	/* 0x4f1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4f6:
	/* 0x4f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f8:
	/* 0x4f8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4fb:
	/* 0x4fb: je     85e <perf_unwind_ruby+0x85e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2142ULL;
	}
x86_l_501:
	/* 0x501: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_504:
	/* 0x504: jmp    868 <perf_unwind_ruby+0x868> */
	return 2152ULL;
x86_l_509:
	/* 0x509: movzx  eax,BYTE PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_50e:
	/* 0x50e: add    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_511:
	/* 0x511: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_516:
	/* 0x516: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_51b:
	/* 0x51b: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_521:
	/* 0x521: movzx  edx,BYTE PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_526:
	/* 0x526: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_529:
	/* 0x529: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52e:
	/* 0x52e: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_531:
	/* 0x531: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_534:
	/* 0x534: je     6f2 <perf_unwind_ruby+0x6f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6f2;
	}
x86_l_53a:
	/* 0x53a: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_541:
	/* 0x541: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_545:
	/* 0x545: jne    18d6 <perf_unwind_ruby+0x18d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6358ULL;
	}
x86_l_54b:
	/* 0x54b: mov    DWORD PTR [rsp+0x18],0x4a */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215178ULL);
x86_l_553:
	/* 0x553: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_55a:
	/* 0x55a: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_55f:
	/* 0x55f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_564:
	/* 0x564: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_566:
	/* 0x566: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_569:
	/* 0x569: je     7d8 <perf_unwind_ruby+0x7d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2008ULL;
	}
x86_l_56f:
	/* 0x56f: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_572:
	/* 0x572: jmp    7e2 <perf_unwind_ruby+0x7e2> */
	return 2018ULL;
x86_l_577:
	/* 0x577: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_57e:
	/* 0x57e: jae    760 <perf_unwind_ruby+0x760> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 1888ULL;
	}
x86_l_584:
	/* 0x584: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_589:
	/* 0x589: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_58c:
	/* 0x58c: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_591:
	/* 0x591: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_594:
	/* 0x594: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_597:
	/* 0x597: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2b2;
	}
x86_l_59d:
	/* 0x59d: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_5a2:
	/* 0x5a2: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5a5:
	/* 0x5a5: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5aa:
	/* 0x5aa: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5b3:
	/* 0x5b3: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5bc:
	/* 0x5bc: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_5c1:
	/* 0x5c1: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5c4:
	/* 0x5c4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5c9:
	/* 0x5c9: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_5ce:
	/* 0x5ce: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5d4:
	/* 0x5d4: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_5d9:
	/* 0x5d9: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5de:
	/* 0x5de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e3:
	/* 0x5e3: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5e6:
	/* 0x5e6: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_5eb:
	/* 0x5eb: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5f0:
	/* 0x5f0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f5:
	/* 0x5f5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5fa:
	/* 0x5fa: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_600:
	/* 0x600: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_605:
	/* 0x605: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_60a:
	/* 0x60a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60f:
	/* 0x60f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_612:
	/* 0x612: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_618:
	/* 0x618: je     958 <perf_unwind_ruby+0x958> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2392ULL;
	}
x86_l_61e:
	/* 0x61e: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_623:
	/* 0x623: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_626:
	/* 0x626: je     958 <perf_unwind_ruby+0x958> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2392ULL;
	}
x86_l_62c:
	/* 0x62c: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_631:
	/* 0x631: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_634:
	/* 0x634: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_639:
	/* 0x639: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_63e:
	/* 0x63e: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_644:
	/* 0x644: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_649:
	/* 0x649: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_64e:
	/* 0x64e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_653:
	/* 0x653: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_656:
	/* 0x656: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_659:
	/* 0x659: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4cf;
	}
x86_l_65f:
	/* 0x65f: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_664:
	/* 0x664: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_669:
	/* 0x669: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_66e:
	/* 0x66e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_673:
	/* 0x673: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_679:
	/* 0x679: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_67e:
	/* 0x67e: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_683:
	/* 0x683: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_688:
	/* 0x688: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_68b:
	/* 0x68b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_68e:
	/* 0x68e: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_694:
	/* 0x694: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_699:
	/* 0x699: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_69e:
	/* 0x69e: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6a3:
	/* 0x6a3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6a8:
	/* 0x6a8: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6ae:
	/* 0x6ae: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_6b3:
	/* 0x6b3: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_6b8:
	/* 0x6b8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6bd:
	/* 0x6bd: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6c0:
	/* 0x6c0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6c3:
	/* 0x6c3: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_6c9:
	/* 0x6c9: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6ce:
	/* 0x6ce: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_6d1:
	/* 0x6d1: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_6d6:
	/* 0x6d6: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_6db:
	/* 0x6db: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6de:
	/* 0x6de: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_6e2:
	/* 0x6e2: je     12ff <perf_unwind_ruby+0x12ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4863ULL;
	}
x86_l_6e8:
	/* 0x6e8: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ea:
	/* 0x6ea: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_6ed:
	/* 0x6ed: jmp    1303 <perf_unwind_ruby+0x1303> */
	return 4867ULL;
x86_l_6f2:
	/* 0x6f2: movzx  eax,BYTE PTR [r15+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_6f7:
	/* 0x6f7: add    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6fa:
	/* 0x6fa: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6ff:
	/* 0x6ff: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_704:
	/* 0x704: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_70a:
	/* 0x70a: movzx  edx,BYTE PTR [r15+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_70f:
	/* 0x70f: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_712:
	/* 0x712: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_717:
	/* 0x717: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_71a:
	/* 0x71a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_71d:
	/* 0x71d: je     875 <perf_unwind_ruby+0x875> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2165ULL;
	}
x86_l_723:
	/* 0x723: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_72a:
	/* 0x72a: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_72e:
	/* 0x72e: jne    1b16 <perf_unwind_ruby+0x1b16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6934ULL;
	}
	return 1844ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1844ULL: goto x86_l_734;
	case 1852ULL: goto x86_l_73c;
	case 1859ULL: goto x86_l_743;
	case 1864ULL: goto x86_l_748;
	case 1869ULL: goto x86_l_74d;
	case 1871ULL: goto x86_l_74f;
	case 1874ULL: goto x86_l_752;
	case 1880ULL: goto x86_l_758;
	case 1883ULL: goto x86_l_75b;
	case 1888ULL: goto x86_l_760;
	case 1896ULL: goto x86_l_768;
	case 1901ULL: goto x86_l_76d;
	case 1906ULL: goto x86_l_772;
	case 1909ULL: goto x86_l_775;
	case 1914ULL: goto x86_l_77a;
	case 1920ULL: goto x86_l_780;
	case 1925ULL: goto x86_l_785;
	case 1930ULL: goto x86_l_78a;
	case 1935ULL: goto x86_l_78f;
	case 1938ULL: goto x86_l_792;
	case 1941ULL: goto x86_l_795;
	case 1947ULL: goto x86_l_79b;
	case 1954ULL: goto x86_l_7a2;
	case 1958ULL: goto x86_l_7a6;
	case 1964ULL: goto x86_l_7ac;
	case 1972ULL: goto x86_l_7b4;
	case 1979ULL: goto x86_l_7bb;
	case 1984ULL: goto x86_l_7c0;
	case 1989ULL: goto x86_l_7c5;
	case 1991ULL: goto x86_l_7c7;
	case 1994ULL: goto x86_l_7ca;
	case 2000ULL: goto x86_l_7d0;
	case 2003ULL: goto x86_l_7d3;
	case 2008ULL: goto x86_l_7d8;
	case 2012ULL: goto x86_l_7dc;
	case 2018ULL: goto x86_l_7e2;
	case 2024ULL: goto x86_l_7e8;
	case 2026ULL: goto x86_l_7ea;
	case 2031ULL: goto x86_l_7ef;
	case 2036ULL: goto x86_l_7f4;
	case 2041ULL: goto x86_l_7f9;
	case 2046ULL: goto x86_l_7fe;
	case 2051ULL: goto x86_l_803;
	case 2057ULL: goto x86_l_809;
	case 2062ULL: goto x86_l_80e;
	case 2067ULL: goto x86_l_813;
	case 2072ULL: goto x86_l_818;
	case 2075ULL: goto x86_l_81b;
	case 2078ULL: goto x86_l_81e;
	case 2084ULL: goto x86_l_824;
	case 2091ULL: goto x86_l_82b;
	case 2095ULL: goto x86_l_82f;
	case 2101ULL: goto x86_l_835;
	case 2108ULL: goto x86_l_83c;
	case 2115ULL: goto x86_l_843;
	case 2118ULL: goto x86_l_846;
	case 2123ULL: goto x86_l_84b;
	case 2125ULL: goto x86_l_84d;
	case 2128ULL: goto x86_l_850;
	case 2134ULL: goto x86_l_856;
	case 2137ULL: goto x86_l_859;
	case 2142ULL: goto x86_l_85e;
	case 2146ULL: goto x86_l_862;
	case 2152ULL: goto x86_l_868;
	case 2158ULL: goto x86_l_86e;
	case 2160ULL: goto x86_l_870;
	case 2165ULL: goto x86_l_875;
	case 2170ULL: goto x86_l_87a;
	case 2175ULL: goto x86_l_87f;
	case 2183ULL: goto x86_l_887;
	case 2188ULL: goto x86_l_88c;
	case 2193ULL: goto x86_l_891;
	case 2201ULL: goto x86_l_899;
	case 2206ULL: goto x86_l_89e;
	case 2209ULL: goto x86_l_8a1;
	case 2214ULL: goto x86_l_8a6;
	case 2219ULL: goto x86_l_8ab;
	case 2225ULL: goto x86_l_8b1;
	case 2230ULL: goto x86_l_8b6;
	case 2233ULL: goto x86_l_8b9;
	case 2238ULL: goto x86_l_8be;
	case 2241ULL: goto x86_l_8c1;
	case 2244ULL: goto x86_l_8c4;
	case 2250ULL: goto x86_l_8ca;
	case 2257ULL: goto x86_l_8d1;
	case 2261ULL: goto x86_l_8d5;
	case 2267ULL: goto x86_l_8db;
	case 2275ULL: goto x86_l_8e3;
	case 2282ULL: goto x86_l_8ea;
	case 2287ULL: goto x86_l_8ef;
	case 2292ULL: goto x86_l_8f4;
	case 2294ULL: goto x86_l_8f6;
	case 2297ULL: goto x86_l_8f9;
	case 2303ULL: goto x86_l_8ff;
	case 2306ULL: goto x86_l_902;
	case 2311ULL: goto x86_l_907;
	case 2314ULL: goto x86_l_90a;
	case 2316ULL: goto x86_l_90c;
	case 2321ULL: goto x86_l_911;
	case 2327ULL: goto x86_l_917;
	case 2332ULL: goto x86_l_91c;
	case 2337ULL: goto x86_l_921;
	case 2342ULL: goto x86_l_926;
	case 2347ULL: goto x86_l_92b;
	case 2354ULL: goto x86_l_932;
	case 2361ULL: goto x86_l_939;
	case 2364ULL: goto x86_l_93c;
	case 2369ULL: goto x86_l_941;
	case 2373ULL: goto x86_l_945;
	case 2379ULL: goto x86_l_94b;
	case 2385ULL: goto x86_l_951;
	case 2387ULL: goto x86_l_953;
	case 2392ULL: goto x86_l_958;
	case 2399ULL: goto x86_l_95f;
	case 2405ULL: goto x86_l_965;
	case 2410ULL: goto x86_l_96a;
	case 2413ULL: goto x86_l_96d;
	case 2416ULL: goto x86_l_970;
	case 2422ULL: goto x86_l_976;
	case 2427ULL: goto x86_l_97b;
	case 2430ULL: goto x86_l_97e;
	case 2435ULL: goto x86_l_983;
	case 2444ULL: goto x86_l_98c;
	case 2453ULL: goto x86_l_995;
	case 2458ULL: goto x86_l_99a;
	case 2461ULL: goto x86_l_99d;
	case 2466ULL: goto x86_l_9a2;
	case 2471ULL: goto x86_l_9a7;
	case 2477ULL: goto x86_l_9ad;
	case 2482ULL: goto x86_l_9b2;
	case 2487ULL: goto x86_l_9b7;
	case 2492ULL: goto x86_l_9bc;
	case 2495ULL: goto x86_l_9bf;
	case 2500ULL: goto x86_l_9c4;
	case 2505ULL: goto x86_l_9c9;
	case 2510ULL: goto x86_l_9ce;
	case 2515ULL: goto x86_l_9d3;
	case 2521ULL: goto x86_l_9d9;
	case 2526ULL: goto x86_l_9de;
	case 2531ULL: goto x86_l_9e3;
	case 2536ULL: goto x86_l_9e8;
	case 2539ULL: goto x86_l_9eb;
	case 2545ULL: goto x86_l_9f1;
	case 2551ULL: goto x86_l_9f7;
	case 2556ULL: goto x86_l_9fc;
	case 2559ULL: goto x86_l_9ff;
	case 2565ULL: goto x86_l_a05;
	case 2570ULL: goto x86_l_a0a;
	case 2573ULL: goto x86_l_a0d;
	case 2578ULL: goto x86_l_a12;
	case 2583ULL: goto x86_l_a17;
	case 2589ULL: goto x86_l_a1d;
	case 2594ULL: goto x86_l_a22;
	case 2599ULL: goto x86_l_a27;
	case 2604ULL: goto x86_l_a2c;
	case 2607ULL: goto x86_l_a2f;
	case 2610ULL: goto x86_l_a32;
	case 2616ULL: goto x86_l_a38;
	case 2621ULL: goto x86_l_a3d;
	case 2626ULL: goto x86_l_a42;
	case 2631ULL: goto x86_l_a47;
	case 2636ULL: goto x86_l_a4c;
	case 2642ULL: goto x86_l_a52;
	case 2647ULL: goto x86_l_a57;
	case 2652ULL: goto x86_l_a5c;
	case 2657ULL: goto x86_l_a61;
	case 2660ULL: goto x86_l_a64;
	case 2663ULL: goto x86_l_a67;
	case 2669ULL: goto x86_l_a6d;
	case 2674ULL: goto x86_l_a72;
	case 2679ULL: goto x86_l_a77;
	case 2684ULL: goto x86_l_a7c;
	case 2689ULL: goto x86_l_a81;
	case 2695ULL: goto x86_l_a87;
	case 2700ULL: goto x86_l_a8c;
	case 2705ULL: goto x86_l_a91;
	case 2710ULL: goto x86_l_a96;
	case 2713ULL: goto x86_l_a99;
	case 2716ULL: goto x86_l_a9c;
	case 2718ULL: goto x86_l_a9e;
	case 2723ULL: goto x86_l_aa3;
	case 2726ULL: goto x86_l_aa6;
	case 2731ULL: goto x86_l_aab;
	case 2736ULL: goto x86_l_ab0;
	case 2739ULL: goto x86_l_ab3;
	case 2743ULL: goto x86_l_ab7;
	case 2749ULL: goto x86_l_abd;
	case 2751ULL: goto x86_l_abf;
	case 2754ULL: goto x86_l_ac2;
	case 2759ULL: goto x86_l_ac7;
	case 2764ULL: goto x86_l_acc;
	case 2769ULL: goto x86_l_ad1;
	case 2774ULL: goto x86_l_ad6;
	case 2779ULL: goto x86_l_adb;
	case 2785ULL: goto x86_l_ae1;
	case 2790ULL: goto x86_l_ae6;
	case 2795ULL: goto x86_l_aeb;
	case 2800ULL: goto x86_l_af0;
	case 2803ULL: goto x86_l_af3;
	case 2806ULL: goto x86_l_af6;
	case 2812ULL: goto x86_l_afc;
	case 2819ULL: goto x86_l_b03;
	case 2823ULL: goto x86_l_b07;
	case 2829ULL: goto x86_l_b0d;
	case 2836ULL: goto x86_l_b14;
	case 2843ULL: goto x86_l_b1b;
	case 2846ULL: goto x86_l_b1e;
	case 2851ULL: goto x86_l_b23;
	case 2853ULL: goto x86_l_b25;
	case 2856ULL: goto x86_l_b28;
	case 2862ULL: goto x86_l_b2e;
	case 2865ULL: goto x86_l_b31;
	case 2870ULL: goto x86_l_b36;
	case 2874ULL: goto x86_l_b3a;
	case 2880ULL: goto x86_l_b40;
	case 2886ULL: goto x86_l_b46;
	case 2888ULL: goto x86_l_b48;
	case 2893ULL: goto x86_l_b4d;
	case 2897ULL: goto x86_l_b51;
	case 2903ULL: goto x86_l_b57;
	case 2909ULL: goto x86_l_b5d;
	case 2911ULL: goto x86_l_b5f;
	case 2916ULL: goto x86_l_b64;
	case 2925ULL: goto x86_l_b6d;
	case 2928ULL: goto x86_l_b70;
	case 2936ULL: goto x86_l_b78;
	case 2938ULL: goto x86_l_b7a;
	case 2941ULL: goto x86_l_b7d;
	case 2946ULL: goto x86_l_b82;
	case 2951ULL: goto x86_l_b87;
	case 2959ULL: goto x86_l_b8f;
	case 2964ULL: goto x86_l_b94;
	case 2969ULL: goto x86_l_b99;
	case 2972ULL: goto x86_l_b9c;
	case 2977ULL: goto x86_l_ba1;
	case 2983ULL: goto x86_l_ba7;
	case 2988ULL: goto x86_l_bac;
	case 2993ULL: goto x86_l_bb1;
	case 2998ULL: goto x86_l_bb6;
	case 3001ULL: goto x86_l_bb9;
	case 3004ULL: goto x86_l_bbc;
	case 3010ULL: goto x86_l_bc2;
	case 3013ULL: goto x86_l_bc5;
	case 3015ULL: goto x86_l_bc7;
	case 3020ULL: goto x86_l_bcc;
	case 3026ULL: goto x86_l_bd2;
	case 3031ULL: goto x86_l_bd7;
	case 3035ULL: goto x86_l_bdb;
	case 3041ULL: goto x86_l_be1;
	case 3047ULL: goto x86_l_be7;
	case 3049ULL: goto x86_l_be9;
	case 3054ULL: goto x86_l_bee;
	case 3059ULL: goto x86_l_bf3;
	case 3062ULL: goto x86_l_bf6;
	case 3067ULL: goto x86_l_bfb;
	case 3072ULL: goto x86_l_c00;
	case 3075ULL: goto x86_l_c03;
	case 3079ULL: goto x86_l_c07;
	case 3085ULL: goto x86_l_c0d;
	case 3087ULL: goto x86_l_c0f;
	case 3090ULL: goto x86_l_c12;
	case 3095ULL: goto x86_l_c17;
	case 3099ULL: goto x86_l_c1b;
	case 3105ULL: goto x86_l_c21;
	case 3111ULL: goto x86_l_c27;
	case 3113ULL: goto x86_l_c29;
	case 3118ULL: goto x86_l_c2e;
	case 3125ULL: goto x86_l_c35;
	case 3131ULL: goto x86_l_c3b;
	case 3136ULL: goto x86_l_c40;
	case 3139ULL: goto x86_l_c43;
	case 3142ULL: goto x86_l_c46;
	case 3148ULL: goto x86_l_c4c;
	case 3153ULL: goto x86_l_c51;
	case 3156ULL: goto x86_l_c54;
	case 3161ULL: goto x86_l_c59;
	case 3170ULL: goto x86_l_c62;
	case 3179ULL: goto x86_l_c6b;
	case 3184ULL: goto x86_l_c70;
	case 3187ULL: goto x86_l_c73;
	case 3192ULL: goto x86_l_c78;
	case 3197ULL: goto x86_l_c7d;
	case 3203ULL: goto x86_l_c83;
	case 3208ULL: goto x86_l_c88;
	case 3213ULL: goto x86_l_c8d;
	case 3218ULL: goto x86_l_c92;
	case 3221ULL: goto x86_l_c95;
	case 3226ULL: goto x86_l_c9a;
	case 3231ULL: goto x86_l_c9f;
	case 3236ULL: goto x86_l_ca4;
	case 3241ULL: goto x86_l_ca9;
	case 3247ULL: goto x86_l_caf;
	case 3252ULL: goto x86_l_cb4;
	case 3257ULL: goto x86_l_cb9;
	case 3262ULL: goto x86_l_cbe;
	case 3265ULL: goto x86_l_cc1;
	case 3271ULL: goto x86_l_cc7;
	case 3277ULL: goto x86_l_ccd;
	case 3282ULL: goto x86_l_cd2;
	case 3285ULL: goto x86_l_cd5;
	case 3291ULL: goto x86_l_cdb;
	case 3296ULL: goto x86_l_ce0;
	case 3299ULL: goto x86_l_ce3;
	case 3304ULL: goto x86_l_ce8;
	case 3309ULL: goto x86_l_ced;
	case 3315ULL: goto x86_l_cf3;
	case 3320ULL: goto x86_l_cf8;
	case 3325ULL: goto x86_l_cfd;
	case 3330ULL: goto x86_l_d02;
	case 3333ULL: goto x86_l_d05;
	case 3336ULL: goto x86_l_d08;
	case 3342ULL: goto x86_l_d0e;
	case 3347ULL: goto x86_l_d13;
	case 3352ULL: goto x86_l_d18;
	case 3357ULL: goto x86_l_d1d;
	case 3362ULL: goto x86_l_d22;
	case 3368ULL: goto x86_l_d28;
	case 3373ULL: goto x86_l_d2d;
	case 3378ULL: goto x86_l_d32;
	case 3383ULL: goto x86_l_d37;
	case 3386ULL: goto x86_l_d3a;
	case 3389ULL: goto x86_l_d3d;
	case 3395ULL: goto x86_l_d43;
	case 3400ULL: goto x86_l_d48;
	case 3405ULL: goto x86_l_d4d;
	case 3410ULL: goto x86_l_d52;
	case 3415ULL: goto x86_l_d57;
	case 3421ULL: goto x86_l_d5d;
	case 3426ULL: goto x86_l_d62;
	case 3431ULL: goto x86_l_d67;
	case 3436ULL: goto x86_l_d6c;
	case 3439ULL: goto x86_l_d6f;
	case 3442ULL: goto x86_l_d72;
	case 3448ULL: goto x86_l_d78;
	case 3453ULL: goto x86_l_d7d;
	case 3456ULL: goto x86_l_d80;
	case 3461ULL: goto x86_l_d85;
	case 3466ULL: goto x86_l_d8a;
	case 3469ULL: goto x86_l_d8d;
	case 3473ULL: goto x86_l_d91;
	case 3479ULL: goto x86_l_d97;
	case 3481ULL: goto x86_l_d99;
	case 3484ULL: goto x86_l_d9c;
	case 3489ULL: goto x86_l_da1;
	case 3491ULL: goto x86_l_da3;
	case 3493ULL: goto x86_l_da5;
	case 3497ULL: goto x86_l_da9;
	case 3500ULL: goto x86_l_dac;
	case 3506ULL: goto x86_l_db2;
	case 3513ULL: goto x86_l_db9;
	case 3516ULL: goto x86_l_dbc;
	case 3522ULL: goto x86_l_dc2;
	case 3532ULL: goto x86_l_dcc;
	case 3537ULL: goto x86_l_dd1;
	case 3547ULL: goto x86_l_ddb;
	case 3552ULL: goto x86_l_de0;
	case 3562ULL: goto x86_l_dea;
	case 3567ULL: goto x86_l_def;
	case 3577ULL: goto x86_l_df9;
	case 3582ULL: goto x86_l_dfe;
	case 3592ULL: goto x86_l_e08;
	case 3597ULL: goto x86_l_e0d;
	case 3607ULL: goto x86_l_e17;
	case 3612ULL: goto x86_l_e1c;
	case 3617ULL: goto x86_l_e21;
	case 3622ULL: goto x86_l_e26;
	case 3627ULL: goto x86_l_e2b;
	case 3632ULL: goto x86_l_e30;
	case 3634ULL: goto x86_l_e32;
	case 3636ULL: goto x86_l_e34;
	case 3641ULL: goto x86_l_e39;
	case 3648ULL: goto x86_l_e40;
	case 3652ULL: goto x86_l_e44;
	case 3658ULL: goto x86_l_e4a;
	case 3665ULL: goto x86_l_e51;
	case 3669ULL: goto x86_l_e55;
	case 3675ULL: goto x86_l_e5b;
	case 3683ULL: goto x86_l_e63;
	case 3690ULL: goto x86_l_e6a;
	case 3695ULL: goto x86_l_e6f;
	case 3700ULL: goto x86_l_e74;
	case 3702ULL: goto x86_l_e76;
	case 3705ULL: goto x86_l_e79;
	case 3711ULL: goto x86_l_e7f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_734:
	/* 0x734: mov    DWORD PTR [rsp+0x18],0x4b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215179ULL);
x86_l_73c:
	/* 0x73c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_743:
	/* 0x743: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_748:
	/* 0x748: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_74d:
	/* 0x74d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_74f:
	/* 0x74f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_752:
	/* 0x752: je     941 <perf_unwind_ruby+0x941> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_941;
	}
x86_l_758:
	/* 0x758: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_75b:
	/* 0x75b: jmp    94b <perf_unwind_ruby+0x94b> */
	goto x86_l_94b;
x86_l_760:
	/* 0x760: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_768:
	/* 0x768: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_76d:
	/* 0x76d: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_772:
	/* 0x772: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_775:
	/* 0x775: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_77a:
	/* 0x77a: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_780:
	/* 0x780: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_785:
	/* 0x785: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_78a:
	/* 0x78a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_78f:
	/* 0x78f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_792:
	/* 0x792: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_795:
	/* 0x795: je     907 <perf_unwind_ruby+0x907> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_907;
	}
x86_l_79b:
	/* 0x79b: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_7a2:
	/* 0x7a2: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7a6:
	/* 0x7a6: jne    1bea <perf_unwind_ruby+0x1bea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7146ULL;
	}
x86_l_7ac:
	/* 0x7ac: mov    DWORD PTR [rsp+0x74],0x4d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206413ULL);
x86_l_7b4:
	/* 0x7b4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_7bb:
	/* 0x7bb: lea    rsi,[rsp+0x74] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_7c0:
	/* 0x7c0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7c5:
	/* 0x7c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c7:
	/* 0x7c7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7ca:
	/* 0x7ca: je     b36 <perf_unwind_ruby+0xb36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b36;
	}
x86_l_7d0:
	/* 0x7d0: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_7d3:
	/* 0x7d3: jmp    b40 <perf_unwind_ruby+0xb40> */
	goto x86_l_b40;
x86_l_7d8:
	/* 0x7d8: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7dc:
	/* 0x7dc: jne    1b6f <perf_unwind_ruby+0x1b6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7023ULL;
	}
x86_l_7e2:
	/* 0x7e2: mov    r13d,0xbb9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3001ULL);
x86_l_7e8:
	/* 0x7e8: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7ea:
	/* 0x7ea: jmp    2b2 <perf_unwind_ruby+0x2b2> */
	return 690ULL;
x86_l_7ef:
	/* 0x7ef: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_7f4:
	/* 0x7f4: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_7f9:
	/* 0x7f9: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_7fe:
	/* 0x7fe: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_803:
	/* 0x803: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_809:
	/* 0x809: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_80e:
	/* 0x80e: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_813:
	/* 0x813: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_818:
	/* 0x818: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_81b:
	/* 0x81b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_81e:
	/* 0x81e: je     ac7 <perf_unwind_ruby+0xac7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ac7;
	}
x86_l_824:
	/* 0x824: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_82b:
	/* 0x82b: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_82f:
	/* 0x82f: jne    1c34 <perf_unwind_ruby+0x1c34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7220ULL;
	}
x86_l_835:
	/* 0x835: mov    DWORD PTR [rsp],0x4f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_83c:
	/* 0x83c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_843:
	/* 0x843: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_846:
	/* 0x846: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_84b:
	/* 0x84b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_84d:
	/* 0x84d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_850:
	/* 0x850: je     b4d <perf_unwind_ruby+0xb4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b4d;
	}
x86_l_856:
	/* 0x856: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_859:
	/* 0x859: jmp    b57 <perf_unwind_ruby+0xb57> */
	goto x86_l_b57;
x86_l_85e:
	/* 0x85e: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_862:
	/* 0x862: jne    1c94 <perf_unwind_ruby+0x1c94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7316ULL;
	}
x86_l_868:
	/* 0x868: mov    r13d,0xbbd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3005ULL);
x86_l_86e:
	/* 0x86e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_870:
	/* 0x870: jmp    2b2 <perf_unwind_ruby+0x2b2> */
	return 690ULL;
x86_l_875:
	/* 0x875: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_87a:
	/* 0x87a: movzx  eax,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_87f:
	/* 0x87f: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_887:
	/* 0x887: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_88c:
	/* 0x88c: movzx  eax,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_891:
	/* 0x891: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_899:
	/* 0x899: movzx  eax,BYTE PTR [r15+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 26ULL);
x86_l_89e:
	/* 0x89e: add    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_8a1:
	/* 0x8a1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8a6:
	/* 0x8a6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8ab:
	/* 0x8ab: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_8b1:
	/* 0x8b1: movzx  edx,BYTE PTR [r15+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 26ULL);
x86_l_8b6:
	/* 0x8b6: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_8b9:
	/* 0x8b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8be:
	/* 0x8be: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_8c1:
	/* 0x8c1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8c4:
	/* 0x8c4: je     b64 <perf_unwind_ruby+0xb64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b64;
	}
x86_l_8ca:
	/* 0x8ca: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_8d1:
	/* 0x8d1: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8d5:
	/* 0x8d5: jne    1f08 <perf_unwind_ruby+0x1f08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7944ULL;
	}
x86_l_8db:
	/* 0x8db: mov    DWORD PTR [rsp+0x18],0x4c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215180ULL);
x86_l_8e3:
	/* 0x8e3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_8ea:
	/* 0x8ea: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8ef:
	/* 0x8ef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8f4:
	/* 0x8f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f6:
	/* 0x8f6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8f9:
	/* 0x8f9: je     bd7 <perf_unwind_ruby+0xbd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bd7;
	}
x86_l_8ff:
	/* 0x8ff: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_902:
	/* 0x902: jmp    be1 <perf_unwind_ruby+0xbe1> */
	goto x86_l_be1;
x86_l_907:
	/* 0x907: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_90a:
	/* 0x90a: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_90c:
	/* 0x90c: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_911:
	/* 0x911: je     584 <perf_unwind_ruby+0x584> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1412ULL;
	}
x86_l_917:
	/* 0x917: movzx  eax,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_91c:
	/* 0x91c: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_921:
	/* 0x921: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_926:
	/* 0x926: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_92b:
	/* 0x92b: mov    QWORD PTR [r14+0xf68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3944ULL);
x86_l_932:
	/* 0x932: mov    QWORD PTR [r14+0xf70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3952ULL);
x86_l_939:
	/* 0x939: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_93c:
	/* 0x93c: jmp    2b2 <perf_unwind_ruby+0x2b2> */
	return 690ULL;
x86_l_941:
	/* 0x941: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_945:
	/* 0x945: jne    1f57 <perf_unwind_ruby+0x1f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8023ULL;
	}
x86_l_94b:
	/* 0x94b: mov    r13d,0xbba */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3002ULL);
x86_l_951:
	/* 0x951: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_953:
	/* 0x953: jmp    2b2 <perf_unwind_ruby+0x2b2> */
	return 690ULL;
x86_l_958:
	/* 0x958: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_95f:
	/* 0x95f: jae    b87 <perf_unwind_ruby+0xb87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_b87;
	}
x86_l_965:
	/* 0x965: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_96a:
	/* 0x96a: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_96d:
	/* 0x96d: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_970:
	/* 0x970: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_976:
	/* 0x976: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_97b:
	/* 0x97b: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_97e:
	/* 0x97e: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_983:
	/* 0x983: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_98c:
	/* 0x98c: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_995:
	/* 0x995: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_99a:
	/* 0x99a: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_99d:
	/* 0x99d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9a2:
	/* 0x9a2: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_9a7:
	/* 0x9a7: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_9ad:
	/* 0x9ad: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_9b2:
	/* 0x9b2: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_9b7:
	/* 0x9b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9bc:
	/* 0x9bc: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_9bf:
	/* 0x9bf: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_9c4:
	/* 0x9c4: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_9c9:
	/* 0x9c9: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9ce:
	/* 0x9ce: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9d3:
	/* 0x9d3: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_9d9:
	/* 0x9d9: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_9de:
	/* 0x9de: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_9e3:
	/* 0x9e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9e8:
	/* 0x9e8: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_9eb:
	/* 0x9eb: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_9f1:
	/* 0x9f1: je     c2e <perf_unwind_ruby+0xc2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c2e;
	}
x86_l_9f7:
	/* 0x9f7: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9fc:
	/* 0x9fc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9ff:
	/* 0x9ff: je     c2e <perf_unwind_ruby+0xc2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c2e;
	}
x86_l_a05:
	/* 0xa05: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_a0a:
	/* 0xa0a: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a0d:
	/* 0xa0d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a12:
	/* 0xa12: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a17:
	/* 0xa17: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_a1d:
	/* 0xa1d: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_a22:
	/* 0xa22: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_a27:
	/* 0xa27: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a2c:
	/* 0xa2c: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_a2f:
	/* 0xa2f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a32:
	/* 0xa32: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_a38:
	/* 0xa38: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_a3d:
	/* 0xa3d: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_a42:
	/* 0xa42: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a47:
	/* 0xa47: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a4c:
	/* 0xa4c: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_a52:
	/* 0xa52: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_a57:
	/* 0xa57: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_a5c:
	/* 0xa5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a61:
	/* 0xa61: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_a64:
	/* 0xa64: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a67:
	/* 0xa67: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_824;
	}
x86_l_a6d:
	/* 0xa6d: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_a72:
	/* 0xa72: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_a77:
	/* 0xa77: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_a7c:
	/* 0xa7c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a81:
	/* 0xa81: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_a87:
	/* 0xa87: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_a8c:
	/* 0xa8c: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_a91:
	/* 0xa91: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a96:
	/* 0xa96: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_a99:
	/* 0xa99: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a9c:
	/* 0xa9c: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_afc;
	}
x86_l_a9e:
	/* 0xa9e: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_aa3:
	/* 0xaa3: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_aa6:
	/* 0xaa6: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_aab:
	/* 0xaab: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_ab0:
	/* 0xab0: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_ab3:
	/* 0xab3: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_ab7:
	/* 0xab7: je     1946 <perf_unwind_ruby+0x1946> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6470ULL;
	}
x86_l_abd:
	/* 0xabd: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_abf:
	/* 0xabf: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_ac2:
	/* 0xac2: jmp    194a <perf_unwind_ruby+0x194a> */
	return 6474ULL;
x86_l_ac7:
	/* 0xac7: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_acc:
	/* 0xacc: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_ad1:
	/* 0xad1: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_ad6:
	/* 0xad6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_adb:
	/* 0xadb: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_ae1:
	/* 0xae1: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_ae6:
	/* 0xae6: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_aeb:
	/* 0xaeb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_af0:
	/* 0xaf0: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_af3:
	/* 0xaf3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_af6:
	/* 0xaf6: je     bee <perf_unwind_ruby+0xbee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bee;
	}
x86_l_afc:
	/* 0xafc: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_b03:
	/* 0xb03: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b07:
	/* 0xb07: jne    2174 <perf_unwind_ruby+0x2174> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8564ULL;
	}
x86_l_b0d:
	/* 0xb0d: mov    DWORD PTR [rsp],0x50 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b14:
	/* 0xb14: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_b1b:
	/* 0xb1b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_b1e:
	/* 0xb1e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b23:
	/* 0xb23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b25:
	/* 0xb25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b28:
	/* 0xb28: je     c17 <perf_unwind_ruby+0xc17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c17;
	}
x86_l_b2e:
	/* 0xb2e: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_b31:
	/* 0xb31: jmp    c21 <perf_unwind_ruby+0xc21> */
	goto x86_l_c21;
x86_l_b36:
	/* 0xb36: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b3a:
	/* 0xb3a: jne    20f9 <perf_unwind_ruby+0x20f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8441ULL;
	}
x86_l_b40:
	/* 0xb40: mov    r13d,0xbbc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3004ULL);
x86_l_b46:
	/* 0xb46: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b48:
	/* 0xb48: jmp    2b2 <perf_unwind_ruby+0x2b2> */
	return 690ULL;
x86_l_b4d:
	/* 0xb4d: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b51:
	/* 0xb51: jne    21cd <perf_unwind_ruby+0x21cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8653ULL;
	}
x86_l_b57:
	/* 0xb57: mov    r13d,0xbbe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3006ULL);
x86_l_b5d:
	/* 0xb5d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b5f:
	/* 0xb5f: jmp    2b2 <perf_unwind_ruby+0x2b2> */
	return 690ULL;
x86_l_b64:
	/* 0xb64: imul   rbp,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 136ULL);
x86_l_b6d:
	/* 0xb6d: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b70:
	/* 0xb70: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b78:
	/* 0xb78: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b7a:
	/* 0xb7a: sub    r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b7d:
	/* 0xb7d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b82:
	/* 0xb82: jmp    417 <perf_unwind_ruby+0x417> */
	return 1047ULL;
x86_l_b87:
	/* 0xb87: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b8f:
	/* 0xb8f: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_b94:
	/* 0xb94: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b99:
	/* 0xb99: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b9c:
	/* 0xb9c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ba1:
	/* 0xba1: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_ba7:
	/* 0xba7: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_bac:
	/* 0xbac: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_bb1:
	/* 0xbb1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bb6:
	/* 0xbb6: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_bb9:
	/* 0xbb9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bbc:
	/* 0xbbc: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_79b;
	}
x86_l_bc2:
	/* 0xbc2: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bc5:
	/* 0xbc5: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_bc7:
	/* 0xbc7: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_bcc:
	/* 0xbcc: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_917;
	}
x86_l_bd2:
	/* 0xbd2: jmp    965 <perf_unwind_ruby+0x965> */
	goto x86_l_965;
x86_l_bd7:
	/* 0xbd7: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bdb:
	/* 0xbdb: jne    2297 <perf_unwind_ruby+0x2297> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8855ULL;
	}
x86_l_be1:
	/* 0xbe1: mov    r13d,0xbbb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3003ULL);
x86_l_be7:
	/* 0xbe7: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_be9:
	/* 0xbe9: jmp    2b2 <perf_unwind_ruby+0x2b2> */
	return 690ULL;
x86_l_bee:
	/* 0xbee: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bf3:
	/* 0xbf3: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_bf6:
	/* 0xbf6: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_bfb:
	/* 0xbfb: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_c00:
	/* 0xc00: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_c03:
	/* 0xc03: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_c07:
	/* 0xc07: je     da1 <perf_unwind_ruby+0xda1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_da1;
	}
x86_l_c0d:
	/* 0xc0d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c0f:
	/* 0xc0f: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_c12:
	/* 0xc12: jmp    da5 <perf_unwind_ruby+0xda5> */
	goto x86_l_da5;
x86_l_c17:
	/* 0xc17: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c1b:
	/* 0xc1b: jne    239c <perf_unwind_ruby+0x239c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9116ULL;
	}
x86_l_c21:
	/* 0xc21: mov    r13d,0xbbf */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3007ULL);
x86_l_c27:
	/* 0xc27: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c29:
	/* 0xc29: jmp    2b2 <perf_unwind_ruby+0x2b2> */
	return 690ULL;
x86_l_c2e:
	/* 0xc2e: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_c35:
	/* 0xc35: jae    f64 <perf_unwind_ruby+0xf64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3940ULL;
	}
x86_l_c3b:
	/* 0xc3b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c40:
	/* 0xc40: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_c43:
	/* 0xc43: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_c46:
	/* 0xc46: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_c4c:
	/* 0xc4c: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_c51:
	/* 0xc51: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c54:
	/* 0xc54: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c59:
	/* 0xc59: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_c62:
	/* 0xc62: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_c6b:
	/* 0xc6b: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_c70:
	/* 0xc70: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c73:
	/* 0xc73: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c78:
	/* 0xc78: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_c7d:
	/* 0xc7d: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_c83:
	/* 0xc83: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_c88:
	/* 0xc88: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c8d:
	/* 0xc8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c92:
	/* 0xc92: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_c95:
	/* 0xc95: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_c9a:
	/* 0xc9a: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c9f:
	/* 0xc9f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ca4:
	/* 0xca4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ca9:
	/* 0xca9: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_caf:
	/* 0xcaf: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_cb4:
	/* 0xcb4: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_cb9:
	/* 0xcb9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cbe:
	/* 0xcbe: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_cc1:
	/* 0xcc1: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_cc7:
	/* 0xcc7: je     1100 <perf_unwind_ruby+0x1100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4352ULL;
	}
x86_l_ccd:
	/* 0xccd: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cd2:
	/* 0xcd2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cd5:
	/* 0xcd5: je     1100 <perf_unwind_ruby+0x1100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4352ULL;
	}
x86_l_cdb:
	/* 0xcdb: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_ce0:
	/* 0xce0: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ce3:
	/* 0xce3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ce8:
	/* 0xce8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ced:
	/* 0xced: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_cf3:
	/* 0xcf3: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_cf8:
	/* 0xcf8: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_cfd:
	/* 0xcfd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d02:
	/* 0xd02: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_d05:
	/* 0xd05: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d08:
	/* 0xd08: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_d0e:
	/* 0xd0e: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_d13:
	/* 0xd13: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_d18:
	/* 0xd18: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d1d:
	/* 0xd1d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d22:
	/* 0xd22: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_d28:
	/* 0xd28: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_d2d:
	/* 0xd2d: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_d32:
	/* 0xd32: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d37:
	/* 0xd37: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_d3a:
	/* 0xd3a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d3d:
	/* 0xd3d: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_824;
	}
x86_l_d43:
	/* 0xd43: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_d48:
	/* 0xd48: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_d4d:
	/* 0xd4d: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_d52:
	/* 0xd52: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d57:
	/* 0xd57: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_d5d:
	/* 0xd5d: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_d62:
	/* 0xd62: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_d67:
	/* 0xd67: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d6c:
	/* 0xd6c: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_d6f:
	/* 0xd6f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d72:
	/* 0xd72: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_afc;
	}
x86_l_d78:
	/* 0xd78: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d7d:
	/* 0xd7d: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_d80:
	/* 0xd80: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_d85:
	/* 0xd85: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_d8a:
	/* 0xd8a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_d8d:
	/* 0xd8d: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_d91:
	/* 0xd91: je     1fd2 <perf_unwind_ruby+0x1fd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8146ULL;
	}
x86_l_d97:
	/* 0xd97: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d99:
	/* 0xd99: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_d9c:
	/* 0xd9c: jmp    1fd6 <perf_unwind_ruby+0x1fd6> */
	return 8150ULL;
x86_l_da1:
	/* 0xda1: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_da3:
	/* 0xda3: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_da5:
	/* 0xda5: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_da9:
	/* 0xda9: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_dac:
	/* 0xdac: jbe    e39 <perf_unwind_ruby+0xe39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e39;
	}
x86_l_db2:
	/* 0xdb2: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_db9:
	/* 0xdb9: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dbc:
	/* 0xdbc: je     584 <perf_unwind_ruby+0x584> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1412ULL;
	}
x86_l_dc2:
	/* 0xdc2: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_dcc:
	/* 0xdcc: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_dd1:
	/* 0xdd1: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_ddb:
	/* 0xddb: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_de0:
	/* 0xde0: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_dea:
	/* 0xdea: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_def:
	/* 0xdef: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_df9:
	/* 0xdf9: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_dfe:
	/* 0xdfe: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_e08:
	/* 0xe08: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e0d:
	/* 0xe0d: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_e17:
	/* 0xe17: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e1c:
	/* 0xe1c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e21:
	/* 0xe21: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_e26:
	/* 0xe26: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_e2b:
	/* 0xe2b: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_e30:
	/* 0xe30: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e32:
	/* 0xe32: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e34:
	/* 0xe34: jmp    584 <perf_unwind_ruby+0x584> */
	return 1412ULL;
x86_l_e39:
	/* 0xe39: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_e40:
	/* 0xe40: cmp    rax,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 127ULL);
x86_l_e44:
	/* 0xe44: jb     ee6 <perf_unwind_ruby+0xee6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3814ULL;
	}
x86_l_e4a:
	/* 0xe4a: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_e51:
	/* 0xe51: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e55:
	/* 0xe55: jne    26fd <perf_unwind_ruby+0x26fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9981ULL;
	}
x86_l_e5b:
	/* 0xe5b: mov    DWORD PTR [rsp+0x74],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206338ULL);
x86_l_e63:
	/* 0xe63: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_e6a:
	/* 0xe6a: lea    rsi,[rsp+0x74] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_e6f:
	/* 0xe6f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e74:
	/* 0xe74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e76:
	/* 0xe76: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e79:
	/* 0xe79: je     1006 <perf_unwind_ruby+0x1006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4102ULL;
	}
x86_l_e7f:
	/* 0xe7f: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
	return 3714ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3714ULL: goto x86_l_e82;
	case 3718ULL: goto x86_l_e86;
	case 3724ULL: goto x86_l_e8c;
	case 3730ULL: goto x86_l_e92;
	case 3740ULL: goto x86_l_e9c;
	case 3745ULL: goto x86_l_ea1;
	case 3755ULL: goto x86_l_eab;
	case 3760ULL: goto x86_l_eb0;
	case 3770ULL: goto x86_l_eba;
	case 3775ULL: goto x86_l_ebf;
	case 3783ULL: goto x86_l_ec7;
	case 3788ULL: goto x86_l_ecc;
	case 3793ULL: goto x86_l_ed1;
	case 3798ULL: goto x86_l_ed6;
	case 3800ULL: goto x86_l_ed8;
	case 3805ULL: goto x86_l_edd;
	case 3807ULL: goto x86_l_edf;
	case 3809ULL: goto x86_l_ee1;
	case 3814ULL: goto x86_l_ee6;
	case 3819ULL: goto x86_l_eeb;
	case 3822ULL: goto x86_l_eee;
	case 3829ULL: goto x86_l_ef5;
	case 3833ULL: goto x86_l_ef9;
	case 3840ULL: goto x86_l_f00;
	case 3847ULL: goto x86_l_f07;
	case 3855ULL: goto x86_l_f0f;
	case 3863ULL: goto x86_l_f17;
	case 3874ULL: goto x86_l_f22;
	case 3877ULL: goto x86_l_f25;
	case 3885ULL: goto x86_l_f2d;
	case 3890ULL: goto x86_l_f32;
	case 3899ULL: goto x86_l_f3b;
	case 3906ULL: goto x86_l_f42;
	case 3913ULL: goto x86_l_f49;
	case 3916ULL: goto x86_l_f4c;
	case 3921ULL: goto x86_l_f51;
	case 3923ULL: goto x86_l_f53;
	case 3926ULL: goto x86_l_f56;
	case 3932ULL: goto x86_l_f5c;
	case 3935ULL: goto x86_l_f5f;
	case 3940ULL: goto x86_l_f64;
	case 3948ULL: goto x86_l_f6c;
	case 3953ULL: goto x86_l_f71;
	case 3958ULL: goto x86_l_f76;
	case 3961ULL: goto x86_l_f79;
	case 3966ULL: goto x86_l_f7e;
	case 3972ULL: goto x86_l_f84;
	case 3977ULL: goto x86_l_f89;
	case 3982ULL: goto x86_l_f8e;
	case 3987ULL: goto x86_l_f93;
	case 3990ULL: goto x86_l_f96;
	case 3993ULL: goto x86_l_f99;
	case 3999ULL: goto x86_l_f9f;
	case 4002ULL: goto x86_l_fa2;
	case 4004ULL: goto x86_l_fa4;
	case 4009ULL: goto x86_l_fa9;
	case 4015ULL: goto x86_l_faf;
	case 4020ULL: goto x86_l_fb4;
	case 4030ULL: goto x86_l_fbe;
	case 4035ULL: goto x86_l_fc3;
	case 4045ULL: goto x86_l_fcd;
	case 4050ULL: goto x86_l_fd2;
	case 4060ULL: goto x86_l_fdc;
	case 4065ULL: goto x86_l_fe1;
	case 4073ULL: goto x86_l_fe9;
	case 4078ULL: goto x86_l_fee;
	case 4083ULL: goto x86_l_ff3;
	case 4088ULL: goto x86_l_ff8;
	case 4093ULL: goto x86_l_ffd;
	case 4095ULL: goto x86_l_fff;
	case 4097ULL: goto x86_l_1001;
	case 4102ULL: goto x86_l_1006;
	case 4106ULL: goto x86_l_100a;
	case 4112ULL: goto x86_l_1010;
	case 4118ULL: goto x86_l_1016;
	case 4120ULL: goto x86_l_1018;
	case 4125ULL: goto x86_l_101d;
	case 4132ULL: goto x86_l_1024;
	case 4135ULL: goto x86_l_1027;
	case 4141ULL: goto x86_l_102d;
	case 4151ULL: goto x86_l_1037;
	case 4156ULL: goto x86_l_103c;
	case 4166ULL: goto x86_l_1046;
	case 4171ULL: goto x86_l_104b;
	case 4181ULL: goto x86_l_1055;
	case 4186ULL: goto x86_l_105a;
	case 4196ULL: goto x86_l_1064;
	case 4201ULL: goto x86_l_1069;
	case 4211ULL: goto x86_l_1073;
	case 4216ULL: goto x86_l_1078;
	case 4226ULL: goto x86_l_1082;
	case 4231ULL: goto x86_l_1087;
	case 4236ULL: goto x86_l_108c;
	case 4241ULL: goto x86_l_1091;
	case 4246ULL: goto x86_l_1096;
	case 4249ULL: goto x86_l_1099;
	case 4254ULL: goto x86_l_109e;
	case 4256ULL: goto x86_l_10a0;
	case 4258ULL: goto x86_l_10a2;
	case 4263ULL: goto x86_l_10a7;
	case 4273ULL: goto x86_l_10b1;
	case 4278ULL: goto x86_l_10b6;
	case 4288ULL: goto x86_l_10c0;
	case 4293ULL: goto x86_l_10c5;
	case 4303ULL: goto x86_l_10cf;
	case 4308ULL: goto x86_l_10d4;
	case 4318ULL: goto x86_l_10de;
	case 4323ULL: goto x86_l_10e3;
	case 4328ULL: goto x86_l_10e8;
	case 4333ULL: goto x86_l_10ed;
	case 4338ULL: goto x86_l_10f2;
	case 4343ULL: goto x86_l_10f7;
	case 4345ULL: goto x86_l_10f9;
	case 4347ULL: goto x86_l_10fb;
	case 4352ULL: goto x86_l_1100;
	case 4359ULL: goto x86_l_1107;
	case 4365ULL: goto x86_l_110d;
	case 4370ULL: goto x86_l_1112;
	case 4373ULL: goto x86_l_1115;
	case 4379ULL: goto x86_l_111b;
	case 4384ULL: goto x86_l_1120;
	case 4387ULL: goto x86_l_1123;
	case 4392ULL: goto x86_l_1128;
	case 4401ULL: goto x86_l_1131;
	case 4410ULL: goto x86_l_113a;
	case 4415ULL: goto x86_l_113f;
	case 4418ULL: goto x86_l_1142;
	case 4423ULL: goto x86_l_1147;
	case 4428ULL: goto x86_l_114c;
	case 4434ULL: goto x86_l_1152;
	case 4439ULL: goto x86_l_1157;
	case 4444ULL: goto x86_l_115c;
	case 4449ULL: goto x86_l_1161;
	case 4452ULL: goto x86_l_1164;
	case 4457ULL: goto x86_l_1169;
	case 4462ULL: goto x86_l_116e;
	case 4467ULL: goto x86_l_1173;
	case 4472ULL: goto x86_l_1178;
	case 4478ULL: goto x86_l_117e;
	case 4483ULL: goto x86_l_1183;
	case 4488ULL: goto x86_l_1188;
	case 4493ULL: goto x86_l_118d;
	case 4496ULL: goto x86_l_1190;
	case 4502ULL: goto x86_l_1196;
	case 4508ULL: goto x86_l_119c;
	case 4513ULL: goto x86_l_11a1;
	case 4516ULL: goto x86_l_11a4;
	case 4522ULL: goto x86_l_11aa;
	case 4527ULL: goto x86_l_11af;
	case 4530ULL: goto x86_l_11b2;
	case 4535ULL: goto x86_l_11b7;
	case 4540ULL: goto x86_l_11bc;
	case 4546ULL: goto x86_l_11c2;
	case 4551ULL: goto x86_l_11c7;
	case 4556ULL: goto x86_l_11cc;
	case 4561ULL: goto x86_l_11d1;
	case 4564ULL: goto x86_l_11d4;
	case 4567ULL: goto x86_l_11d7;
	case 4573ULL: goto x86_l_11dd;
	case 4578ULL: goto x86_l_11e2;
	case 4583ULL: goto x86_l_11e7;
	case 4588ULL: goto x86_l_11ec;
	case 4593ULL: goto x86_l_11f1;
	case 4599ULL: goto x86_l_11f7;
	case 4604ULL: goto x86_l_11fc;
	case 4609ULL: goto x86_l_1201;
	case 4614ULL: goto x86_l_1206;
	case 4617ULL: goto x86_l_1209;
	case 4620ULL: goto x86_l_120c;
	case 4626ULL: goto x86_l_1212;
	case 4631ULL: goto x86_l_1217;
	case 4636ULL: goto x86_l_121c;
	case 4641ULL: goto x86_l_1221;
	case 4646ULL: goto x86_l_1226;
	case 4652ULL: goto x86_l_122c;
	case 4657ULL: goto x86_l_1231;
	case 4662ULL: goto x86_l_1236;
	case 4667ULL: goto x86_l_123b;
	case 4670ULL: goto x86_l_123e;
	case 4673ULL: goto x86_l_1241;
	case 4679ULL: goto x86_l_1247;
	case 4684ULL: goto x86_l_124c;
	case 4687ULL: goto x86_l_124f;
	case 4692ULL: goto x86_l_1254;
	case 4697ULL: goto x86_l_1259;
	case 4700ULL: goto x86_l_125c;
	case 4704ULL: goto x86_l_1260;
	case 4710ULL: goto x86_l_1266;
	case 4712ULL: goto x86_l_1268;
	case 4715ULL: goto x86_l_126b;
	case 4720ULL: goto x86_l_1270;
	case 4730ULL: goto x86_l_127a;
	case 4735ULL: goto x86_l_127f;
	case 4745ULL: goto x86_l_1289;
	case 4750ULL: goto x86_l_128e;
	case 4760ULL: goto x86_l_1298;
	case 4765ULL: goto x86_l_129d;
	case 4775ULL: goto x86_l_12a7;
	case 4780ULL: goto x86_l_12ac;
	case 4790ULL: goto x86_l_12b6;
	case 4795ULL: goto x86_l_12bb;
	case 4805ULL: goto x86_l_12c5;
	case 4810ULL: goto x86_l_12ca;
	case 4815ULL: goto x86_l_12cf;
	case 4820ULL: goto x86_l_12d4;
	case 4825ULL: goto x86_l_12d9;
	case 4829ULL: goto x86_l_12dd;
	case 4834ULL: goto x86_l_12e2;
	case 4836ULL: goto x86_l_12e4;
	case 4838ULL: goto x86_l_12e6;
	case 4847ULL: goto x86_l_12ef;
	case 4852ULL: goto x86_l_12f4;
	case 4858ULL: goto x86_l_12fa;
	case 4863ULL: goto x86_l_12ff;
	case 4865ULL: goto x86_l_1301;
	case 4867ULL: goto x86_l_1303;
	case 4871ULL: goto x86_l_1307;
	case 4874ULL: goto x86_l_130a;
	case 4880ULL: goto x86_l_1310;
	case 4887ULL: goto x86_l_1317;
	case 4890ULL: goto x86_l_131a;
	case 4896ULL: goto x86_l_1320;
	case 4906ULL: goto x86_l_132a;
	case 4911ULL: goto x86_l_132f;
	case 4921ULL: goto x86_l_1339;
	case 4926ULL: goto x86_l_133e;
	case 4936ULL: goto x86_l_1348;
	case 4941ULL: goto x86_l_134d;
	case 4951ULL: goto x86_l_1357;
	case 4956ULL: goto x86_l_135c;
	case 4966ULL: goto x86_l_1366;
	case 4971ULL: goto x86_l_136b;
	case 4981ULL: goto x86_l_1375;
	case 4986ULL: goto x86_l_137a;
	case 4991ULL: goto x86_l_137f;
	case 4996ULL: goto x86_l_1384;
	case 5001ULL: goto x86_l_1389;
	case 5006ULL: goto x86_l_138e;
	case 5008ULL: goto x86_l_1390;
	case 5010ULL: goto x86_l_1392;
	case 5015ULL: goto x86_l_1397;
	case 5022ULL: goto x86_l_139e;
	case 5026ULL: goto x86_l_13a2;
	case 5032ULL: goto x86_l_13a8;
	case 5037ULL: goto x86_l_13ad;
	case 5040ULL: goto x86_l_13b0;
	case 5047ULL: goto x86_l_13b7;
	case 5051ULL: goto x86_l_13bb;
	case 5058ULL: goto x86_l_13c2;
	case 5065ULL: goto x86_l_13c9;
	case 5073ULL: goto x86_l_13d1;
	case 5081ULL: goto x86_l_13d9;
	case 5092ULL: goto x86_l_13e4;
	case 5095ULL: goto x86_l_13e7;
	case 5103ULL: goto x86_l_13ef;
	case 5108ULL: goto x86_l_13f4;
	case 5117ULL: goto x86_l_13fd;
	case 5124ULL: goto x86_l_1404;
	case 5131ULL: goto x86_l_140b;
	case 5134ULL: goto x86_l_140e;
	case 5139ULL: goto x86_l_1413;
	case 5141ULL: goto x86_l_1415;
	case 5144ULL: goto x86_l_1418;
	case 5150ULL: goto x86_l_141e;
	case 5153ULL: goto x86_l_1421;
	case 5158ULL: goto x86_l_1426;
	case 5168ULL: goto x86_l_1430;
	case 5173ULL: goto x86_l_1435;
	case 5183ULL: goto x86_l_143f;
	case 5188ULL: goto x86_l_1444;
	case 5198ULL: goto x86_l_144e;
	case 5203ULL: goto x86_l_1453;
	case 5213ULL: goto x86_l_145d;
	case 5218ULL: goto x86_l_1462;
	case 5228ULL: goto x86_l_146c;
	case 5233ULL: goto x86_l_1471;
	case 5243ULL: goto x86_l_147b;
	case 5248ULL: goto x86_l_1480;
	case 5253ULL: goto x86_l_1485;
	case 5258ULL: goto x86_l_148a;
	case 5263ULL: goto x86_l_148f;
	case 5269ULL: goto x86_l_1495;
	case 5274ULL: goto x86_l_149a;
	case 5277ULL: goto x86_l_149d;
	case 5280ULL: goto x86_l_14a0;
	case 5282ULL: goto x86_l_14a2;
	case 5285ULL: goto x86_l_14a5;
	case 5288ULL: goto x86_l_14a8;
	case 5293ULL: goto x86_l_14ad;
	case 5303ULL: goto x86_l_14b7;
	case 5308ULL: goto x86_l_14bc;
	case 5318ULL: goto x86_l_14c6;
	case 5323ULL: goto x86_l_14cb;
	case 5333ULL: goto x86_l_14d5;
	case 5338ULL: goto x86_l_14da;
	case 5348ULL: goto x86_l_14e4;
	case 5353ULL: goto x86_l_14e9;
	case 5363ULL: goto x86_l_14f3;
	case 5368ULL: goto x86_l_14f8;
	case 5378ULL: goto x86_l_1502;
	case 5383ULL: goto x86_l_1507;
	case 5388ULL: goto x86_l_150c;
	case 5393ULL: goto x86_l_1511;
	case 5398ULL: goto x86_l_1516;
	case 5402ULL: goto x86_l_151a;
	case 5407ULL: goto x86_l_151f;
	case 5409ULL: goto x86_l_1521;
	case 5411ULL: goto x86_l_1523;
	case 5416ULL: goto x86_l_1528;
	case 5424ULL: goto x86_l_1530;
	case 5429ULL: goto x86_l_1535;
	case 5434ULL: goto x86_l_153a;
	case 5437ULL: goto x86_l_153d;
	case 5442ULL: goto x86_l_1542;
	case 5448ULL: goto x86_l_1548;
	case 5453ULL: goto x86_l_154d;
	case 5458ULL: goto x86_l_1552;
	case 5463ULL: goto x86_l_1557;
	case 5466ULL: goto x86_l_155a;
	case 5469ULL: goto x86_l_155d;
	case 5475ULL: goto x86_l_1563;
	case 5478ULL: goto x86_l_1566;
	case 5480ULL: goto x86_l_1568;
	case 5485ULL: goto x86_l_156d;
	case 5491ULL: goto x86_l_1573;
	case 5496ULL: goto x86_l_1578;
	case 5506ULL: goto x86_l_1582;
	case 5511ULL: goto x86_l_1587;
	case 5521ULL: goto x86_l_1591;
	case 5526ULL: goto x86_l_1596;
	case 5536ULL: goto x86_l_15a0;
	case 5541ULL: goto x86_l_15a5;
	case 5551ULL: goto x86_l_15af;
	case 5556ULL: goto x86_l_15b4;
	case 5566ULL: goto x86_l_15be;
	case 5571ULL: goto x86_l_15c3;
	case 5581ULL: goto x86_l_15cd;
	case 5586ULL: goto x86_l_15d2;
	case 5591ULL: goto x86_l_15d7;
	case 5596ULL: goto x86_l_15dc;
	case 5601ULL: goto x86_l_15e1;
	case 5605ULL: goto x86_l_15e5;
	case 5610ULL: goto x86_l_15ea;
	case 5612ULL: goto x86_l_15ec;
	case 5614ULL: goto x86_l_15ee;
	case 5617ULL: goto x86_l_15f1;
	case 5623ULL: goto x86_l_15f7;
	case 5628ULL: goto x86_l_15fc;
	case 5638ULL: goto x86_l_1606;
	case 5643ULL: goto x86_l_160b;
	case 5653ULL: goto x86_l_1615;
	case 5658ULL: goto x86_l_161a;
	case 5668ULL: goto x86_l_1624;
	case 5673ULL: goto x86_l_1629;
	case 5683ULL: goto x86_l_1633;
	case 5688ULL: goto x86_l_1638;
	case 5698ULL: goto x86_l_1642;
	case 5703ULL: goto x86_l_1647;
	case 5713ULL: goto x86_l_1651;
	case 5718ULL: goto x86_l_1656;
	case 5723ULL: goto x86_l_165b;
	case 5728ULL: goto x86_l_1660;
	case 5733ULL: goto x86_l_1665;
	case 5737ULL: goto x86_l_1669;
	case 5742ULL: goto x86_l_166e;
	case 5744ULL: goto x86_l_1670;
	case 5746ULL: goto x86_l_1672;
	case 5751ULL: goto x86_l_1677;
	case 5761ULL: goto x86_l_1681;
	case 5766ULL: goto x86_l_1686;
	case 5776ULL: goto x86_l_1690;
	case 5781ULL: goto x86_l_1695;
	case 5791ULL: goto x86_l_169f;
	case 5796ULL: goto x86_l_16a4;
	case 5804ULL: goto x86_l_16ac;
	case 5809ULL: goto x86_l_16b1;
	case 5814ULL: goto x86_l_16b6;
	case 5819ULL: goto x86_l_16bb;
	case 5824ULL: goto x86_l_16c0;
	case 5829ULL: goto x86_l_16c5;
	case 5831ULL: goto x86_l_16c7;
	case 5833ULL: goto x86_l_16c9;
	case 5838ULL: goto x86_l_16ce;
	case 5841ULL: goto x86_l_16d1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e82:
	/* 0xe82: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e86:
	/* 0xe86: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_e8c:
	/* 0xe8c: je     2875 <perf_unwind_ruby+0x2875> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10357ULL;
	}
x86_l_e92:
	/* 0xe92: movabs rax,0x6172662068737570 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7021787058401408368ULL);
x86_l_e9c:
	/* 0xe9c: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ea1:
	/* 0xea1: movabs rax,0x206f742064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414100720745ULL);
x86_l_eab:
	/* 0xeab: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_eb0:
	/* 0xeb0: movabs rax,0x6166203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332504820184434ULL);
x86_l_eba:
	/* 0xeba: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ebf:
	/* 0xebf: mov    DWORD PTR [rsp+0x48],0xa656d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309238326637ULL);
x86_l_ec7:
	/* 0xec7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ecc:
	/* 0xecc: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_ed1:
	/* 0xed1: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_ed6:
	/* 0xed6: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ed8:
	/* 0xed8: mov    esi,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 28ULL);
x86_l_edd:
	/* 0xedd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_edf:
	/* 0xedf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_ee1:
	/* 0xee1: jmp    2b2 <perf_unwind_ruby+0x2b2> */
	return 690ULL;
x86_l_ee6:
	/* 0xee6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eeb:
	/* 0xeeb: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_eee:
	/* 0xeee: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_ef5:
	/* 0xef5: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_ef9:
	/* 0xef9: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_f00:
	/* 0xf00: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f07:
	/* 0xf07: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_f0f:
	/* 0xf0f: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_f17:
	/* 0xf17: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_f22:
	/* 0xf22: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f25:
	/* 0xf25: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_f2d:
	/* 0xf2d: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_f32:
	/* 0xf32: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_f3b:
	/* 0xf3b: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_f42:
	/* 0xf42: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_f49:
	/* 0xf49: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_f4c:
	/* 0xf4c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f51:
	/* 0xf51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f53:
	/* 0xf53: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f56:
	/* 0xf56: je     101d <perf_unwind_ruby+0x101d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_101d;
	}
x86_l_f5c:
	/* 0xf5c: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_f5f:
	/* 0xf5f: jmp    584 <perf_unwind_ruby+0x584> */
	return 1412ULL;
x86_l_f64:
	/* 0xf64: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f6c:
	/* 0xf6c: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_f71:
	/* 0xf71: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_f76:
	/* 0xf76: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_f79:
	/* 0xf79: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f7e:
	/* 0xf7e: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_f84:
	/* 0xf84: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_f89:
	/* 0xf89: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_f8e:
	/* 0xf8e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f93:
	/* 0xf93: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_f96:
	/* 0xf96: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f99:
	/* 0xf99: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_f9f:
	/* 0xf9f: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fa2:
	/* 0xfa2: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_fa4:
	/* 0xfa4: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_fa9:
	/* 0xfa9: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_faf:
	/* 0xfaf: jmp    c3b <perf_unwind_ruby+0xc3b> */
	return 3131ULL;
x86_l_fb4:
	/* 0xfb4: movabs rax,0x6164206e6f697463 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7017769778037748835ULL);
x86_l_fbe:
	/* 0xfbe: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_fc3:
	/* 0xfc3: movabs rax,0x6570736f72746e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7309469117721112169ULL);
x86_l_fcd:
	/* 0xfcd: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_fd2:
	/* 0xfd2: movabs rax,0x2079627552206f4e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2340009737424236366ULL);
x86_l_fdc:
	/* 0xfdc: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fe1:
	/* 0xfe1: mov    DWORD PTR [rsp+0x48],0xa6174 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309238325620ULL);
x86_l_fe9:
	/* 0xfe9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fee:
	/* 0xfee: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_ff3:
	/* 0xff3: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_ff8:
	/* 0xff8: mov    esi,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 28ULL);
x86_l_ffd:
	/* 0xffd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fff:
	/* 0xfff: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1001:
	/* 0x1001: jmp    11a <perf_unwind_ruby+0x11a> */
	return 282ULL;
x86_l_1006:
	/* 0x1006: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_100a:
	/* 0x100a: jne    27ef <perf_unwind_ruby+0x27ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10223ULL;
	}
x86_l_1010:
	/* 0x1010: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_1016:
	/* 0x1016: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1018:
	/* 0x1018: jmp    2b2 <perf_unwind_ruby+0x2b2> */
	return 690ULL;
x86_l_101d:
	/* 0x101d: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1024:
	/* 0x1024: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1027:
	/* 0x1027: je     584 <perf_unwind_ruby+0x584> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1412ULL;
	}
x86_l_102d:
	/* 0x102d: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1037:
	/* 0x1037: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_103c:
	/* 0x103c: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1046:
	/* 0x1046: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_104b:
	/* 0x104b: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1055:
	/* 0x1055: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_105a:
	/* 0x105a: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1064:
	/* 0x1064: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1069:
	/* 0x1069: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1073:
	/* 0x1073: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1078:
	/* 0x1078: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1082:
	/* 0x1082: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1087:
	/* 0x1087: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_108c:
	/* 0x108c: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1091:
	/* 0x1091: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1096:
	/* 0x1096: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1099:
	/* 0x1099: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_109e:
	/* 0x109e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10a0:
	/* 0x10a0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_10a2:
	/* 0x10a2: jmp    584 <perf_unwind_ruby+0x584> */
	return 1412ULL;
x86_l_10a7:
	/* 0x10a7: movabs rax,0xa65756c617620 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926304771012128ULL);
x86_l_10b1:
	/* 0x10b1: mov    QWORD PTR [rsp+0x45],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_10b6:
	/* 0x10b6: movabs rax,0x6176206573616270 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7022836289030414960ULL);
x86_l_10c0:
	/* 0x10c0: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_10c5:
	/* 0x10c5: movabs rax,0x742064616572206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798477130965103ULL);
x86_l_10cf:
	/* 0x10cf: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_10d4:
	/* 0x10d4: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_10de:
	/* 0x10de: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10e3:
	/* 0x10e3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10e8:
	/* 0x10e8: mov    eax,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_10ed:
	/* 0x10ed: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_10f2:
	/* 0x10f2: mov    esi,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 29ULL);
x86_l_10f7:
	/* 0x10f7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10f9:
	/* 0x10f9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_10fb:
	/* 0x10fb: jmp    1af <perf_unwind_ruby+0x1af> */
	return 431ULL;
x86_l_1100:
	/* 0x1100: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_1107:
	/* 0x1107: jae    1528 <perf_unwind_ruby+0x1528> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1528;
	}
x86_l_110d:
	/* 0x110d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1112:
	/* 0x1112: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1115:
	/* 0x1115: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_111b:
	/* 0x111b: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_1120:
	/* 0x1120: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1123:
	/* 0x1123: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1128:
	/* 0x1128: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1131:
	/* 0x1131: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_113a:
	/* 0x113a: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_113f:
	/* 0x113f: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1142:
	/* 0x1142: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1147:
	/* 0x1147: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_114c:
	/* 0x114c: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1152:
	/* 0x1152: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_1157:
	/* 0x1157: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_115c:
	/* 0x115c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1161:
	/* 0x1161: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1164:
	/* 0x1164: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_1169:
	/* 0x1169: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_116e:
	/* 0x116e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1173:
	/* 0x1173: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1178:
	/* 0x1178: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_117e:
	/* 0x117e: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_1183:
	/* 0x1183: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1188:
	/* 0x1188: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_118d:
	/* 0x118d: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1190:
	/* 0x1190: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1196:
	/* 0x1196: je     1766 <perf_unwind_ruby+0x1766> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5990ULL;
	}
x86_l_119c:
	/* 0x119c: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11a1:
	/* 0x11a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11a4:
	/* 0x11a4: je     1766 <perf_unwind_ruby+0x1766> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5990ULL;
	}
x86_l_11aa:
	/* 0x11aa: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_11af:
	/* 0x11af: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_11b2:
	/* 0x11b2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11b7:
	/* 0x11b7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11bc:
	/* 0x11bc: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_11c2:
	/* 0x11c2: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_11c7:
	/* 0x11c7: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_11cc:
	/* 0x11cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11d1:
	/* 0x11d1: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_11d4:
	/* 0x11d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11d7:
	/* 0x11d7: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_11dd:
	/* 0x11dd: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_11e2:
	/* 0x11e2: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_11e7:
	/* 0x11e7: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_11ec:
	/* 0x11ec: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11f1:
	/* 0x11f1: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_11f7:
	/* 0x11f7: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_11fc:
	/* 0x11fc: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1201:
	/* 0x1201: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1206:
	/* 0x1206: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1209:
	/* 0x1209: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_120c:
	/* 0x120c: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_1212:
	/* 0x1212: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_1217:
	/* 0x1217: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_121c:
	/* 0x121c: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1221:
	/* 0x1221: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1226:
	/* 0x1226: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_122c:
	/* 0x122c: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_1231:
	/* 0x1231: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1236:
	/* 0x1236: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_123b:
	/* 0x123b: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_123e:
	/* 0x123e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1241:
	/* 0x1241: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_1247:
	/* 0x1247: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_124c:
	/* 0x124c: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_124f:
	/* 0x124f: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_1254:
	/* 0x1254: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_1259:
	/* 0x1259: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_125c:
	/* 0x125c: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1260:
	/* 0x1260: je     2586 <perf_unwind_ruby+0x2586> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9606ULL;
	}
x86_l_1266:
	/* 0x1266: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1268:
	/* 0x1268: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_126b:
	/* 0x126b: jmp    258a <perf_unwind_ruby+0x258a> */
	return 9610ULL;
x86_l_1270:
	/* 0x1270: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_127a:
	/* 0x127a: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_127f:
	/* 0x127f: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1289:
	/* 0x1289: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_128e:
	/* 0x128e: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1298:
	/* 0x1298: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_129d:
	/* 0x129d: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_12a7:
	/* 0x12a7: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12ac:
	/* 0x12ac: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_12b6:
	/* 0x12b6: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12bb:
	/* 0x12bb: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_12c5:
	/* 0x12c5: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12ca:
	/* 0x12ca: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12cf:
	/* 0x12cf: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_12d4:
	/* 0x12d4: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_12d9:
	/* 0x12d9: mov    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12dd:
	/* 0x12dd: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_12e2:
	/* 0x12e2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12e4:
	/* 0x12e4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_12e6:
	/* 0x12e6: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_12ef:
	/* 0x12ef: cmp    QWORD PTR [r15+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_12f4:
	/* 0x12f4: jne    16a <perf_unwind_ruby+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 362ULL;
	}
x86_l_12fa:
	/* 0x12fa: jmp    a1 <perf_unwind_ruby+0xa1> */
	return 161ULL;
x86_l_12ff:
	/* 0x12ff: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1301:
	/* 0x1301: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_1303:
	/* 0x1303: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1307:
	/* 0x1307: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_130a:
	/* 0x130a: jbe    1397 <perf_unwind_ruby+0x1397> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1397;
	}
x86_l_1310:
	/* 0x1310: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1317:
	/* 0x1317: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_131a:
	/* 0x131a: je     965 <perf_unwind_ruby+0x965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2405ULL;
	}
x86_l_1320:
	/* 0x1320: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_132a:
	/* 0x132a: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_132f:
	/* 0x132f: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_1339:
	/* 0x1339: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_133e:
	/* 0x133e: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_1348:
	/* 0x1348: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_134d:
	/* 0x134d: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_1357:
	/* 0x1357: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_135c:
	/* 0x135c: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_1366:
	/* 0x1366: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_136b:
	/* 0x136b: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_1375:
	/* 0x1375: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_137a:
	/* 0x137a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_137f:
	/* 0x137f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1384:
	/* 0x1384: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1389:
	/* 0x1389: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_138e:
	/* 0x138e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1390:
	/* 0x1390: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1392:
	/* 0x1392: jmp    965 <perf_unwind_ruby+0x965> */
	return 2405ULL;
x86_l_1397:
	/* 0x1397: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_139e:
	/* 0x139e: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_13a2:
	/* 0x13a2: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_13a8:
	/* 0x13a8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13ad:
	/* 0x13ad: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_13b0:
	/* 0x13b0: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_13b7:
	/* 0x13b7: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_13bb:
	/* 0x13bb: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_13c2:
	/* 0x13c2: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13c9:
	/* 0x13c9: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_13d1:
	/* 0x13d1: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_13d9:
	/* 0x13d9: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_13e4:
	/* 0x13e4: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13e7:
	/* 0x13e7: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_13ef:
	/* 0x13ef: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_13f4:
	/* 0x13f4: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_13fd:
	/* 0x13fd: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_1404:
	/* 0x1404: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_140b:
	/* 0x140b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_140e:
	/* 0x140e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1413:
	/* 0x1413: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1415:
	/* 0x1415: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1418:
	/* 0x1418: je     16dc <perf_unwind_ruby+0x16dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5852ULL;
	}
x86_l_141e:
	/* 0x141e: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1421:
	/* 0x1421: jmp    965 <perf_unwind_ruby+0x965> */
	return 2405ULL;
x86_l_1426:
	/* 0x1426: movabs rax,0xa786c6c25783020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 754472149325459488ULL);
x86_l_1430:
	/* 0x1430: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1435:
	/* 0x1435: movabs rax,0x6d6f726620786c6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7885647255506021484ULL);
x86_l_143f:
	/* 0x143f: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1444:
	/* 0x1444: movabs rax,0x2578302072646461 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2699960892524880993ULL);
x86_l_144e:
	/* 0x144e: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1453:
	/* 0x1453: movabs rax,0x206c6f626d797320 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2336364775232598816ULL);
x86_l_145d:
	/* 0x145d: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1462:
	/* 0x1462: movabs rax,0x434520534c542074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4847316116069163124ULL);
x86_l_146c:
	/* 0x146c: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1471:
	/* 0x1471: movabs rax,0x6f67203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8027420296327886194ULL);
x86_l_147b:
	/* 0x147b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1480:
	/* 0x1480: mov    BYTE PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1485:
	/* 0x1485: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_148a:
	/* 0x148a: mov    eax,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 49ULL);
x86_l_148f:
	/* 0x148f: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_1495:
	/* 0x1495: mov    esi,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 49ULL);
x86_l_149a:
	/* 0x149a: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_149d:
	/* 0x149d: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_14a0:
	/* 0x14a0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14a2:
	/* 0x14a2: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_14a5:
	/* 0x14a5: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_14a8:
	/* 0x14a8: jmp    279 <perf_unwind_ruby+0x279> */
	return 633ULL;
x86_l_14ad:
	/* 0x14ad: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_14b7:
	/* 0x14b7: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_14bc:
	/* 0x14bc: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_14c6:
	/* 0x14c6: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14cb:
	/* 0x14cb: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_14d5:
	/* 0x14d5: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_14da:
	/* 0x14da: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_14e4:
	/* 0x14e4: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14e9:
	/* 0x14e9: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_14f3:
	/* 0x14f3: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14f8:
	/* 0x14f8: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1502:
	/* 0x1502: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1507:
	/* 0x1507: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_150c:
	/* 0x150c: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1511:
	/* 0x1511: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1516:
	/* 0x1516: mov    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_151a:
	/* 0x151a: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_151f:
	/* 0x151f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1521:
	/* 0x1521: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1523:
	/* 0x1523: jmp    2a7 <perf_unwind_ruby+0x2a7> */
	return 679ULL;
x86_l_1528:
	/* 0x1528: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1530:
	/* 0x1530: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_1535:
	/* 0x1535: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_153a:
	/* 0x153a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_153d:
	/* 0x153d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1542:
	/* 0x1542: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1548:
	/* 0x1548: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_154d:
	/* 0x154d: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1552:
	/* 0x1552: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1557:
	/* 0x1557: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_155a:
	/* 0x155a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_155d:
	/* 0x155d: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_1563:
	/* 0x1563: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1566:
	/* 0x1566: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1568:
	/* 0x1568: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_156d:
	/* 0x156d: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_1573:
	/* 0x1573: jmp    110d <perf_unwind_ruby+0x110d> */
	goto x86_l_110d;
x86_l_1578:
	/* 0x1578: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1582:
	/* 0x1582: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1587:
	/* 0x1587: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1591:
	/* 0x1591: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1596:
	/* 0x1596: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_15a0:
	/* 0x15a0: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15a5:
	/* 0x15a5: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_15af:
	/* 0x15af: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15b4:
	/* 0x15b4: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_15be:
	/* 0x15be: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15c3:
	/* 0x15c3: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_15cd:
	/* 0x15cd: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15d2:
	/* 0x15d2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15d7:
	/* 0x15d7: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_15dc:
	/* 0x15dc: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_15e1:
	/* 0x15e1: mov    edx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15e5:
	/* 0x15e5: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_15ea:
	/* 0x15ea: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15ec:
	/* 0x15ec: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_15ee:
	/* 0x15ee: cmp    DWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15f1:
	/* 0x15f1: je     380 <perf_unwind_ruby+0x380> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 896ULL;
	}
x86_l_15f7:
	/* 0x15f7: jmp    1df <perf_unwind_ruby+0x1df> */
	return 479ULL;
x86_l_15fc:
	/* 0x15fc: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1606:
	/* 0x1606: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_160b:
	/* 0x160b: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1615:
	/* 0x1615: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_161a:
	/* 0x161a: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1624:
	/* 0x1624: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1629:
	/* 0x1629: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1633:
	/* 0x1633: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1638:
	/* 0x1638: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1642:
	/* 0x1642: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1647:
	/* 0x1647: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1651:
	/* 0x1651: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1656:
	/* 0x1656: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_165b:
	/* 0x165b: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1660:
	/* 0x1660: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1665:
	/* 0x1665: mov    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1669:
	/* 0x1669: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_166e:
	/* 0x166e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1670:
	/* 0x1670: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1672:
	/* 0x1672: jmp    394 <perf_unwind_ruby+0x394> */
	return 916ULL;
x86_l_1677:
	/* 0x1677: movabs rax,0x6c6c257830203a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660651714689619ULL);
x86_l_1681:
	/* 0x1681: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1686:
	/* 0x1686: movabs rax,0x4c54206d6f726620 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5500056699319510560ULL);
x86_l_1690:
	/* 0x1690: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1695:
	/* 0x1695: movabs rax,0x4345203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4847316009450894706ULL);
x86_l_169f:
	/* 0x169f: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16a4:
	/* 0x16a4: mov    DWORD PTR [rsp+0x47],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304943364204ULL);
x86_l_16ac:
	/* 0x16ac: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16b1:
	/* 0x16b1: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_16b6:
	/* 0x16b6: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_16bb:
	/* 0x16bb: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_16c0:
	/* 0x16c0: mov    esi,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 27ULL);
x86_l_16c5:
	/* 0x16c5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16c7:
	/* 0x16c7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_16c9:
	/* 0x16c9: mov    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_16ce:
	/* 0x16ce: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_16d1:
	/* 0x16d1: jne    3f2 <perf_unwind_ruby+0x3f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1010ULL;
	}
	return 5847ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5847ULL: goto x86_l_16d7;
	case 5852ULL: goto x86_l_16dc;
	case 5859ULL: goto x86_l_16e3;
	case 5862ULL: goto x86_l_16e6;
	case 5868ULL: goto x86_l_16ec;
	case 5878ULL: goto x86_l_16f6;
	case 5883ULL: goto x86_l_16fb;
	case 5893ULL: goto x86_l_1705;
	case 5898ULL: goto x86_l_170a;
	case 5908ULL: goto x86_l_1714;
	case 5913ULL: goto x86_l_1719;
	case 5923ULL: goto x86_l_1723;
	case 5928ULL: goto x86_l_1728;
	case 5938ULL: goto x86_l_1732;
	case 5943ULL: goto x86_l_1737;
	case 5953ULL: goto x86_l_1741;
	case 5958ULL: goto x86_l_1746;
	case 5963ULL: goto x86_l_174b;
	case 5968ULL: goto x86_l_1750;
	case 5973ULL: goto x86_l_1755;
	case 5976ULL: goto x86_l_1758;
	case 5981ULL: goto x86_l_175d;
	case 5983ULL: goto x86_l_175f;
	case 5985ULL: goto x86_l_1761;
	case 5990ULL: goto x86_l_1766;
	case 5997ULL: goto x86_l_176d;
	case 6003ULL: goto x86_l_1773;
	case 6008ULL: goto x86_l_1778;
	case 6011ULL: goto x86_l_177b;
	case 6017ULL: goto x86_l_1781;
	case 6022ULL: goto x86_l_1786;
	case 6025ULL: goto x86_l_1789;
	case 6030ULL: goto x86_l_178e;
	case 6039ULL: goto x86_l_1797;
	case 6048ULL: goto x86_l_17a0;
	case 6053ULL: goto x86_l_17a5;
	case 6056ULL: goto x86_l_17a8;
	case 6061ULL: goto x86_l_17ad;
	case 6066ULL: goto x86_l_17b2;
	case 6072ULL: goto x86_l_17b8;
	case 6077ULL: goto x86_l_17bd;
	case 6082ULL: goto x86_l_17c2;
	case 6087ULL: goto x86_l_17c7;
	case 6090ULL: goto x86_l_17ca;
	case 6095ULL: goto x86_l_17cf;
	case 6100ULL: goto x86_l_17d4;
	case 6105ULL: goto x86_l_17d9;
	case 6110ULL: goto x86_l_17de;
	case 6116ULL: goto x86_l_17e4;
	case 6121ULL: goto x86_l_17e9;
	case 6126ULL: goto x86_l_17ee;
	case 6131ULL: goto x86_l_17f3;
	case 6134ULL: goto x86_l_17f6;
	case 6140ULL: goto x86_l_17fc;
	case 6146ULL: goto x86_l_1802;
	case 6151ULL: goto x86_l_1807;
	case 6154ULL: goto x86_l_180a;
	case 6160ULL: goto x86_l_1810;
	case 6165ULL: goto x86_l_1815;
	case 6168ULL: goto x86_l_1818;
	case 6173ULL: goto x86_l_181d;
	case 6178ULL: goto x86_l_1822;
	case 6184ULL: goto x86_l_1828;
	case 6189ULL: goto x86_l_182d;
	case 6194ULL: goto x86_l_1832;
	case 6199ULL: goto x86_l_1837;
	case 6202ULL: goto x86_l_183a;
	case 6205ULL: goto x86_l_183d;
	case 6211ULL: goto x86_l_1843;
	case 6216ULL: goto x86_l_1848;
	case 6221ULL: goto x86_l_184d;
	case 6226ULL: goto x86_l_1852;
	case 6231ULL: goto x86_l_1857;
	case 6237ULL: goto x86_l_185d;
	case 6242ULL: goto x86_l_1862;
	case 6247ULL: goto x86_l_1867;
	case 6252ULL: goto x86_l_186c;
	case 6255ULL: goto x86_l_186f;
	case 6258ULL: goto x86_l_1872;
	case 6264ULL: goto x86_l_1878;
	case 6269ULL: goto x86_l_187d;
	case 6274ULL: goto x86_l_1882;
	case 6279ULL: goto x86_l_1887;
	case 6284ULL: goto x86_l_188c;
	case 6290ULL: goto x86_l_1892;
	case 6295ULL: goto x86_l_1897;
	case 6300ULL: goto x86_l_189c;
	case 6305ULL: goto x86_l_18a1;
	case 6308ULL: goto x86_l_18a4;
	case 6311ULL: goto x86_l_18a7;
	case 6317ULL: goto x86_l_18ad;
	case 6322ULL: goto x86_l_18b2;
	case 6325ULL: goto x86_l_18b5;
	case 6330ULL: goto x86_l_18ba;
	case 6335ULL: goto x86_l_18bf;
	case 6338ULL: goto x86_l_18c2;
	case 6342ULL: goto x86_l_18c6;
	case 6348ULL: goto x86_l_18cc;
	case 6350ULL: goto x86_l_18ce;
	case 6353ULL: goto x86_l_18d1;
	case 6358ULL: goto x86_l_18d6;
	case 6368ULL: goto x86_l_18e0;
	case 6373ULL: goto x86_l_18e5;
	case 6383ULL: goto x86_l_18ef;
	case 6388ULL: goto x86_l_18f4;
	case 6398ULL: goto x86_l_18fe;
	case 6403ULL: goto x86_l_1903;
	case 6413ULL: goto x86_l_190d;
	case 6418ULL: goto x86_l_1912;
	case 6428ULL: goto x86_l_191c;
	case 6433ULL: goto x86_l_1921;
	case 6441ULL: goto x86_l_1929;
	case 6446ULL: goto x86_l_192e;
	case 6451ULL: goto x86_l_1933;
	case 6456ULL: goto x86_l_1938;
	case 6461ULL: goto x86_l_193d;
	case 6463ULL: goto x86_l_193f;
	case 6465ULL: goto x86_l_1941;
	case 6470ULL: goto x86_l_1946;
	case 6472ULL: goto x86_l_1948;
	case 6474ULL: goto x86_l_194a;
	case 6478ULL: goto x86_l_194e;
	case 6481ULL: goto x86_l_1951;
	case 6487ULL: goto x86_l_1957;
	case 6494ULL: goto x86_l_195e;
	case 6497ULL: goto x86_l_1961;
	case 6503ULL: goto x86_l_1967;
	case 6513ULL: goto x86_l_1971;
	case 6518ULL: goto x86_l_1976;
	case 6528ULL: goto x86_l_1980;
	case 6533ULL: goto x86_l_1985;
	case 6543ULL: goto x86_l_198f;
	case 6548ULL: goto x86_l_1994;
	case 6558ULL: goto x86_l_199e;
	case 6563ULL: goto x86_l_19a3;
	case 6573ULL: goto x86_l_19ad;
	case 6578ULL: goto x86_l_19b2;
	case 6588ULL: goto x86_l_19bc;
	case 6593ULL: goto x86_l_19c1;
	case 6598ULL: goto x86_l_19c6;
	case 6603ULL: goto x86_l_19cb;
	case 6608ULL: goto x86_l_19d0;
	case 6613ULL: goto x86_l_19d5;
	case 6615ULL: goto x86_l_19d7;
	case 6617ULL: goto x86_l_19d9;
	case 6622ULL: goto x86_l_19de;
	case 6629ULL: goto x86_l_19e5;
	case 6633ULL: goto x86_l_19e9;
	case 6639ULL: goto x86_l_19ef;
	case 6644ULL: goto x86_l_19f4;
	case 6647ULL: goto x86_l_19f7;
	case 6654ULL: goto x86_l_19fe;
	case 6658ULL: goto x86_l_1a02;
	case 6665ULL: goto x86_l_1a09;
	case 6672ULL: goto x86_l_1a10;
	case 6680ULL: goto x86_l_1a18;
	case 6688ULL: goto x86_l_1a20;
	case 6699ULL: goto x86_l_1a2b;
	case 6702ULL: goto x86_l_1a2e;
	case 6710ULL: goto x86_l_1a36;
	case 6715ULL: goto x86_l_1a3b;
	case 6724ULL: goto x86_l_1a44;
	case 6731ULL: goto x86_l_1a4b;
	case 6738ULL: goto x86_l_1a52;
	case 6741ULL: goto x86_l_1a55;
	case 6746ULL: goto x86_l_1a5a;
	case 6748ULL: goto x86_l_1a5c;
	case 6751ULL: goto x86_l_1a5f;
	case 6757ULL: goto x86_l_1a65;
	case 6760ULL: goto x86_l_1a68;
	case 6765ULL: goto x86_l_1a6d;
	case 6775ULL: goto x86_l_1a77;
	case 6780ULL: goto x86_l_1a7c;
	case 6790ULL: goto x86_l_1a86;
	case 6795ULL: goto x86_l_1a8b;
	case 6805ULL: goto x86_l_1a95;
	case 6810ULL: goto x86_l_1a9a;
	case 6820ULL: goto x86_l_1aa4;
	case 6825ULL: goto x86_l_1aa9;
	case 6830ULL: goto x86_l_1aae;
	case 6835ULL: goto x86_l_1ab3;
	case 6840ULL: goto x86_l_1ab8;
	case 6845ULL: goto x86_l_1abd;
	case 6847ULL: goto x86_l_1abf;
	case 6849ULL: goto x86_l_1ac1;
	case 6854ULL: goto x86_l_1ac6;
	case 6862ULL: goto x86_l_1ace;
	case 6867ULL: goto x86_l_1ad3;
	case 6872ULL: goto x86_l_1ad8;
	case 6875ULL: goto x86_l_1adb;
	case 6880ULL: goto x86_l_1ae0;
	case 6886ULL: goto x86_l_1ae6;
	case 6891ULL: goto x86_l_1aeb;
	case 6896ULL: goto x86_l_1af0;
	case 6901ULL: goto x86_l_1af5;
	case 6904ULL: goto x86_l_1af8;
	case 6907ULL: goto x86_l_1afb;
	case 6913ULL: goto x86_l_1b01;
	case 6916ULL: goto x86_l_1b04;
	case 6918ULL: goto x86_l_1b06;
	case 6923ULL: goto x86_l_1b0b;
	case 6929ULL: goto x86_l_1b11;
	case 6934ULL: goto x86_l_1b16;
	case 6944ULL: goto x86_l_1b20;
	case 6949ULL: goto x86_l_1b25;
	case 6959ULL: goto x86_l_1b2f;
	case 6964ULL: goto x86_l_1b34;
	case 6974ULL: goto x86_l_1b3e;
	case 6979ULL: goto x86_l_1b43;
	case 6989ULL: goto x86_l_1b4d;
	case 6994ULL: goto x86_l_1b52;
	case 6999ULL: goto x86_l_1b57;
	case 7004ULL: goto x86_l_1b5c;
	case 7009ULL: goto x86_l_1b61;
	case 7014ULL: goto x86_l_1b66;
	case 7016ULL: goto x86_l_1b68;
	case 7018ULL: goto x86_l_1b6a;
	case 7023ULL: goto x86_l_1b6f;
	case 7033ULL: goto x86_l_1b79;
	case 7038ULL: goto x86_l_1b7e;
	case 7048ULL: goto x86_l_1b88;
	case 7053ULL: goto x86_l_1b8d;
	case 7063ULL: goto x86_l_1b97;
	case 7068ULL: goto x86_l_1b9c;
	case 7078ULL: goto x86_l_1ba6;
	case 7083ULL: goto x86_l_1bab;
	case 7093ULL: goto x86_l_1bb5;
	case 7098ULL: goto x86_l_1bba;
	case 7108ULL: goto x86_l_1bc4;
	case 7113ULL: goto x86_l_1bc9;
	case 7118ULL: goto x86_l_1bce;
	case 7123ULL: goto x86_l_1bd3;
	case 7128ULL: goto x86_l_1bd8;
	case 7132ULL: goto x86_l_1bdc;
	case 7137ULL: goto x86_l_1be1;
	case 7139ULL: goto x86_l_1be3;
	case 7141ULL: goto x86_l_1be5;
	case 7146ULL: goto x86_l_1bea;
	case 7156ULL: goto x86_l_1bf4;
	case 7161ULL: goto x86_l_1bf9;
	case 7171ULL: goto x86_l_1c03;
	case 7176ULL: goto x86_l_1c08;
	case 7186ULL: goto x86_l_1c12;
	case 7191ULL: goto x86_l_1c17;
	case 7196ULL: goto x86_l_1c1c;
	case 7201ULL: goto x86_l_1c21;
	case 7206ULL: goto x86_l_1c26;
	case 7211ULL: goto x86_l_1c2b;
	case 7213ULL: goto x86_l_1c2d;
	case 7215ULL: goto x86_l_1c2f;
	case 7220ULL: goto x86_l_1c34;
	case 7230ULL: goto x86_l_1c3e;
	case 7235ULL: goto x86_l_1c43;
	case 7245ULL: goto x86_l_1c4d;
	case 7250ULL: goto x86_l_1c52;
	case 7260ULL: goto x86_l_1c5c;
	case 7265ULL: goto x86_l_1c61;
	case 7275ULL: goto x86_l_1c6b;
	case 7280ULL: goto x86_l_1c70;
	case 7287ULL: goto x86_l_1c77;
	case 7292ULL: goto x86_l_1c7c;
	case 7297ULL: goto x86_l_1c81;
	case 7302ULL: goto x86_l_1c86;
	case 7307ULL: goto x86_l_1c8b;
	case 7309ULL: goto x86_l_1c8d;
	case 7311ULL: goto x86_l_1c8f;
	case 7316ULL: goto x86_l_1c94;
	case 7326ULL: goto x86_l_1c9e;
	case 7331ULL: goto x86_l_1ca3;
	case 7341ULL: goto x86_l_1cad;
	case 7346ULL: goto x86_l_1cb2;
	case 7356ULL: goto x86_l_1cbc;
	case 7361ULL: goto x86_l_1cc1;
	case 7371ULL: goto x86_l_1ccb;
	case 7376ULL: goto x86_l_1cd0;
	case 7386ULL: goto x86_l_1cda;
	case 7391ULL: goto x86_l_1cdf;
	case 7401ULL: goto x86_l_1ce9;
	case 7406ULL: goto x86_l_1cee;
	case 7411ULL: goto x86_l_1cf3;
	case 7416ULL: goto x86_l_1cf8;
	case 7421ULL: goto x86_l_1cfd;
	case 7424ULL: goto x86_l_1d00;
	case 7429ULL: goto x86_l_1d05;
	case 7431ULL: goto x86_l_1d07;
	case 7433ULL: goto x86_l_1d09;
	case 7438ULL: goto x86_l_1d0e;
	case 7445ULL: goto x86_l_1d15;
	case 7448ULL: goto x86_l_1d18;
	case 7454ULL: goto x86_l_1d1e;
	case 7464ULL: goto x86_l_1d28;
	case 7469ULL: goto x86_l_1d2d;
	case 7479ULL: goto x86_l_1d37;
	case 7484ULL: goto x86_l_1d3c;
	case 7494ULL: goto x86_l_1d46;
	case 7499ULL: goto x86_l_1d4b;
	case 7509ULL: goto x86_l_1d55;
	case 7514ULL: goto x86_l_1d5a;
	case 7524ULL: goto x86_l_1d64;
	case 7529ULL: goto x86_l_1d69;
	case 7539ULL: goto x86_l_1d73;
	case 7544ULL: goto x86_l_1d78;
	case 7549ULL: goto x86_l_1d7d;
	case 7554ULL: goto x86_l_1d82;
	case 7559ULL: goto x86_l_1d87;
	case 7562ULL: goto x86_l_1d8a;
	case 7567ULL: goto x86_l_1d8f;
	case 7569ULL: goto x86_l_1d91;
	case 7571ULL: goto x86_l_1d93;
	case 7576ULL: goto x86_l_1d98;
	case 7583ULL: goto x86_l_1d9f;
	case 7589ULL: goto x86_l_1da5;
	case 7594ULL: goto x86_l_1daa;
	case 7597ULL: goto x86_l_1dad;
	case 7603ULL: goto x86_l_1db3;
	case 7608ULL: goto x86_l_1db8;
	case 7611ULL: goto x86_l_1dbb;
	case 7616ULL: goto x86_l_1dc0;
	case 7625ULL: goto x86_l_1dc9;
	case 7634ULL: goto x86_l_1dd2;
	case 7639ULL: goto x86_l_1dd7;
	case 7642ULL: goto x86_l_1dda;
	case 7647ULL: goto x86_l_1ddf;
	case 7652ULL: goto x86_l_1de4;
	case 7658ULL: goto x86_l_1dea;
	case 7663ULL: goto x86_l_1def;
	case 7668ULL: goto x86_l_1df4;
	case 7673ULL: goto x86_l_1df9;
	case 7676ULL: goto x86_l_1dfc;
	case 7681ULL: goto x86_l_1e01;
	case 7686ULL: goto x86_l_1e06;
	case 7691ULL: goto x86_l_1e0b;
	case 7696ULL: goto x86_l_1e10;
	case 7702ULL: goto x86_l_1e16;
	case 7707ULL: goto x86_l_1e1b;
	case 7712ULL: goto x86_l_1e20;
	case 7717ULL: goto x86_l_1e25;
	case 7720ULL: goto x86_l_1e28;
	case 7726ULL: goto x86_l_1e2e;
	case 7732ULL: goto x86_l_1e34;
	case 7737ULL: goto x86_l_1e39;
	case 7740ULL: goto x86_l_1e3c;
	case 7746ULL: goto x86_l_1e42;
	case 7751ULL: goto x86_l_1e47;
	case 7754ULL: goto x86_l_1e4a;
	case 7759ULL: goto x86_l_1e4f;
	case 7764ULL: goto x86_l_1e54;
	case 7770ULL: goto x86_l_1e5a;
	case 7775ULL: goto x86_l_1e5f;
	case 7780ULL: goto x86_l_1e64;
	case 7785ULL: goto x86_l_1e69;
	case 7788ULL: goto x86_l_1e6c;
	case 7791ULL: goto x86_l_1e6f;
	case 7797ULL: goto x86_l_1e75;
	case 7802ULL: goto x86_l_1e7a;
	case 7807ULL: goto x86_l_1e7f;
	case 7812ULL: goto x86_l_1e84;
	case 7817ULL: goto x86_l_1e89;
	case 7823ULL: goto x86_l_1e8f;
	case 7828ULL: goto x86_l_1e94;
	case 7833ULL: goto x86_l_1e99;
	case 7838ULL: goto x86_l_1e9e;
	case 7841ULL: goto x86_l_1ea1;
	case 7844ULL: goto x86_l_1ea4;
	case 7850ULL: goto x86_l_1eaa;
	case 7855ULL: goto x86_l_1eaf;
	case 7860ULL: goto x86_l_1eb4;
	case 7865ULL: goto x86_l_1eb9;
	case 7870ULL: goto x86_l_1ebe;
	case 7876ULL: goto x86_l_1ec4;
	case 7881ULL: goto x86_l_1ec9;
	case 7886ULL: goto x86_l_1ece;
	case 7891ULL: goto x86_l_1ed3;
	case 7894ULL: goto x86_l_1ed6;
	case 7897ULL: goto x86_l_1ed9;
	case 7903ULL: goto x86_l_1edf;
	case 7908ULL: goto x86_l_1ee4;
	case 7911ULL: goto x86_l_1ee7;
	case 7916ULL: goto x86_l_1eec;
	case 7921ULL: goto x86_l_1ef1;
	case 7924ULL: goto x86_l_1ef4;
	case 7928ULL: goto x86_l_1ef8;
	case 7934ULL: goto x86_l_1efe;
	case 7936ULL: goto x86_l_1f00;
	default: return 0xffffffffffffffffULL;
	}
x86_l_16d7:
	/* 0x16d7: jmp    298 <perf_unwind_ruby+0x298> */
	return 664ULL;
x86_l_16dc:
	/* 0x16dc: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_16e3:
	/* 0x16e3: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16e6:
	/* 0x16e6: je     965 <perf_unwind_ruby+0x965> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2405ULL;
	}
x86_l_16ec:
	/* 0x16ec: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_16f6:
	/* 0x16f6: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_16fb:
	/* 0x16fb: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1705:
	/* 0x1705: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_170a:
	/* 0x170a: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1714:
	/* 0x1714: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1719:
	/* 0x1719: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1723:
	/* 0x1723: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1728:
	/* 0x1728: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1732:
	/* 0x1732: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1737:
	/* 0x1737: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1741:
	/* 0x1741: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1746:
	/* 0x1746: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_174b:
	/* 0x174b: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1750:
	/* 0x1750: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1755:
	/* 0x1755: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1758:
	/* 0x1758: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_175d:
	/* 0x175d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_175f:
	/* 0x175f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1761:
	/* 0x1761: jmp    965 <perf_unwind_ruby+0x965> */
	return 2405ULL;
x86_l_1766:
	/* 0x1766: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_176d:
	/* 0x176d: jae    1ac6 <perf_unwind_ruby+0x1ac6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1ac6;
	}
x86_l_1773:
	/* 0x1773: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1778:
	/* 0x1778: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_177b:
	/* 0x177b: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_1781:
	/* 0x1781: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_1786:
	/* 0x1786: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1789:
	/* 0x1789: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_178e:
	/* 0x178e: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1797:
	/* 0x1797: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_17a0:
	/* 0x17a0: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_17a5:
	/* 0x17a5: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_17a8:
	/* 0x17a8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17ad:
	/* 0x17ad: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_17b2:
	/* 0x17b2: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_17b8:
	/* 0x17b8: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_17bd:
	/* 0x17bd: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_17c2:
	/* 0x17c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17c7:
	/* 0x17c7: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_17ca:
	/* 0x17ca: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_17cf:
	/* 0x17cf: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_17d4:
	/* 0x17d4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17d9:
	/* 0x17d9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17de:
	/* 0x17de: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_17e4:
	/* 0x17e4: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_17e9:
	/* 0x17e9: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_17ee:
	/* 0x17ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17f3:
	/* 0x17f3: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_17f6:
	/* 0x17f6: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_17fc:
	/* 0x17fc: je     1d98 <perf_unwind_ruby+0x1d98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d98;
	}
x86_l_1802:
	/* 0x1802: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1807:
	/* 0x1807: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_180a:
	/* 0x180a: je     1d98 <perf_unwind_ruby+0x1d98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d98;
	}
x86_l_1810:
	/* 0x1810: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_1815:
	/* 0x1815: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1818:
	/* 0x1818: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_181d:
	/* 0x181d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1822:
	/* 0x1822: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1828:
	/* 0x1828: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_182d:
	/* 0x182d: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1832:
	/* 0x1832: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1837:
	/* 0x1837: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_183a:
	/* 0x183a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_183d:
	/* 0x183d: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_1843:
	/* 0x1843: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_1848:
	/* 0x1848: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_184d:
	/* 0x184d: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1852:
	/* 0x1852: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1857:
	/* 0x1857: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_185d:
	/* 0x185d: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_1862:
	/* 0x1862: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1867:
	/* 0x1867: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_186c:
	/* 0x186c: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_186f:
	/* 0x186f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1872:
	/* 0x1872: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_1878:
	/* 0x1878: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_187d:
	/* 0x187d: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1882:
	/* 0x1882: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1887:
	/* 0x1887: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_188c:
	/* 0x188c: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1892:
	/* 0x1892: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_1897:
	/* 0x1897: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_189c:
	/* 0x189c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18a1:
	/* 0x18a1: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_18a4:
	/* 0x18a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18a7:
	/* 0x18a7: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_18ad:
	/* 0x18ad: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18b2:
	/* 0x18b2: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_18b5:
	/* 0x18b5: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_18ba:
	/* 0x18ba: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_18bf:
	/* 0x18bf: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_18c2:
	/* 0x18c2: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_18c6:
	/* 0x18c6: je     29ec <perf_unwind_ruby+0x29ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10732ULL;
	}
x86_l_18cc:
	/* 0x18cc: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18ce:
	/* 0x18ce: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_18d1:
	/* 0x18d1: jmp    29f0 <perf_unwind_ruby+0x29f0> */
	return 10736ULL;
x86_l_18d6:
	/* 0x18d6: movabs rax,0x746e696f70206b63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8389759083181271907ULL);
x86_l_18e0:
	/* 0x18e0: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_18e5:
	/* 0x18e5: movabs rax,0x61747320746e6572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7022364302206985586ULL);
x86_l_18ef:
	/* 0x18ef: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_18f4:
	/* 0x18f4: movabs rax,0x7275632064616572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8247607283373139314ULL);
x86_l_18fe:
	/* 0x18fe: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1903:
	/* 0x1903: movabs rax,0x206f742064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414100720745ULL);
x86_l_190d:
	/* 0x190d: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1912:
	/* 0x1912: movabs rax,0x6166203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332504820184434ULL);
x86_l_191c:
	/* 0x191c: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1921:
	/* 0x1921: mov    DWORD PTR [rsp+0x58],0xa7265 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957806693ULL);
x86_l_1929:
	/* 0x1929: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_192e:
	/* 0x192e: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1933:
	/* 0x1933: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1938:
	/* 0x1938: mov    esi,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_193d:
	/* 0x193d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_193f:
	/* 0x193f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1941:
	/* 0x1941: jmp    54b <perf_unwind_ruby+0x54b> */
	return 1355ULL;
x86_l_1946:
	/* 0x1946: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1948:
	/* 0x1948: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_194a:
	/* 0x194a: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_194e:
	/* 0x194e: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1951:
	/* 0x1951: jbe    19de <perf_unwind_ruby+0x19de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_19de;
	}
x86_l_1957:
	/* 0x1957: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_195e:
	/* 0x195e: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1961:
	/* 0x1961: je     c3b <perf_unwind_ruby+0xc3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3131ULL;
	}
x86_l_1967:
	/* 0x1967: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_1971:
	/* 0x1971: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_1976:
	/* 0x1976: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_1980:
	/* 0x1980: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1985:
	/* 0x1985: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_198f:
	/* 0x198f: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1994:
	/* 0x1994: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_199e:
	/* 0x199e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19a3:
	/* 0x19a3: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_19ad:
	/* 0x19ad: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19b2:
	/* 0x19b2: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_19bc:
	/* 0x19bc: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19c1:
	/* 0x19c1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19c6:
	/* 0x19c6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_19cb:
	/* 0x19cb: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_19d0:
	/* 0x19d0: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_19d5:
	/* 0x19d5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19d7:
	/* 0x19d7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_19d9:
	/* 0x19d9: jmp    c3b <perf_unwind_ruby+0xc3b> */
	return 3131ULL;
x86_l_19de:
	/* 0x19de: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_19e5:
	/* 0x19e5: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_19e9:
	/* 0x19e9: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_19ef:
	/* 0x19ef: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19f4:
	/* 0x19f4: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_19f7:
	/* 0x19f7: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_19fe:
	/* 0x19fe: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1a02:
	/* 0x1a02: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_1a09:
	/* 0x1a09: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a10:
	/* 0x1a10: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_1a18:
	/* 0x1a18: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_1a20:
	/* 0x1a20: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_1a2b:
	/* 0x1a2b: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a2e:
	/* 0x1a2e: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_1a36:
	/* 0x1a36: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1a3b:
	/* 0x1a3b: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_1a44:
	/* 0x1a44: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_1a4b:
	/* 0x1a4b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_1a52:
	/* 0x1a52: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1a55:
	/* 0x1a55: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a5a:
	/* 0x1a5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a5c:
	/* 0x1a5c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a5f:
	/* 0x1a5f: je     1d0e <perf_unwind_ruby+0x1d0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d0e;
	}
x86_l_1a65:
	/* 0x1a65: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1a68:
	/* 0x1a68: jmp    c3b <perf_unwind_ruby+0xc3b> */
	return 3131ULL;
x86_l_1a6d:
	/* 0x1a6d: movabs rax,0xa79646f622071 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2948222039498865ULL);
x86_l_1a77:
	/* 0x1a77: mov    QWORD PTR [rsp+0x47],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_1a7c:
	/* 0x1a7c: movabs rax,0x7165736920746567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8171063994286892391ULL);
x86_l_1a86:
	/* 0x1a86: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a8b:
	/* 0x1a8b: movabs rax,0x206f742064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414100720745ULL);
x86_l_1a95:
	/* 0x1a95: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a9a:
	/* 0x1a9a: movabs rax,0x6166203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332504820184434ULL);
x86_l_1aa4:
	/* 0x1aa4: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1aa9:
	/* 0x1aa9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1aae:
	/* 0x1aae: mov    eax,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_1ab3:
	/* 0x1ab3: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1ab8:
	/* 0x1ab8: mov    esi,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 31ULL);
x86_l_1abd:
	/* 0x1abd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1abf:
	/* 0x1abf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1ac1:
	/* 0x1ac1: jmp    4e0 <perf_unwind_ruby+0x4e0> */
	return 1248ULL;
x86_l_1ac6:
	/* 0x1ac6: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ace:
	/* 0x1ace: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_1ad3:
	/* 0x1ad3: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ad8:
	/* 0x1ad8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1adb:
	/* 0x1adb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ae0:
	/* 0x1ae0: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1ae6:
	/* 0x1ae6: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_1aeb:
	/* 0x1aeb: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1af0:
	/* 0x1af0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1af5:
	/* 0x1af5: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1af8:
	/* 0x1af8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1afb:
	/* 0x1afb: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_1b01:
	/* 0x1b01: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b04:
	/* 0x1b04: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1b06:
	/* 0x1b06: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_1b0b:
	/* 0x1b0b: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_1b11:
	/* 0x1b11: jmp    1773 <perf_unwind_ruby+0x1773> */
	goto x86_l_1773;
x86_l_1b16:
	/* 0x1b16: movabs rax,0xa657a6973206b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926326196674667ULL);
x86_l_1b20:
	/* 0x1b20: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b25:
	/* 0x1b25: movabs rax,0x6361747320746567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7161132920310359399ULL);
x86_l_1b2f:
	/* 0x1b2f: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b34:
	/* 0x1b34: movabs rax,0x206f742064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414100720745ULL);
x86_l_1b3e:
	/* 0x1b3e: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b43:
	/* 0x1b43: movabs rax,0x6166203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332504820184434ULL);
x86_l_1b4d:
	/* 0x1b4d: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b52:
	/* 0x1b52: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b57:
	/* 0x1b57: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_1b5c:
	/* 0x1b5c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1b61:
	/* 0x1b61: mov    esi,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32ULL);
x86_l_1b66:
	/* 0x1b66: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b68:
	/* 0x1b68: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b6a:
	/* 0x1b6a: jmp    734 <perf_unwind_ruby+0x734> */
	return 1844ULL;
x86_l_1b6f:
	/* 0x1b6f: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1b79:
	/* 0x1b79: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1b7e:
	/* 0x1b7e: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1b88:
	/* 0x1b88: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b8d:
	/* 0x1b8d: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1b97:
	/* 0x1b97: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b9c:
	/* 0x1b9c: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1ba6:
	/* 0x1ba6: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1bab:
	/* 0x1bab: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1bb5:
	/* 0x1bb5: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1bba:
	/* 0x1bba: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1bc4:
	/* 0x1bc4: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bc9:
	/* 0x1bc9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bce:
	/* 0x1bce: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1bd3:
	/* 0x1bd3: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1bd8:
	/* 0x1bd8: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bdc:
	/* 0x1bdc: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1be1:
	/* 0x1be1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1be3:
	/* 0x1be3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1be5:
	/* 0x1be5: jmp    7e2 <perf_unwind_ruby+0x7e2> */
	return 2018ULL;
x86_l_1bea:
	/* 0x1bea: movabs rax,0xa706520746567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2938329405613415ULL);
x86_l_1bf4:
	/* 0x1bf4: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1bf9:
	/* 0x1bf9: movabs rax,0x206f742064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414100720745ULL);
x86_l_1c03:
	/* 0x1c03: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c08:
	/* 0x1c08: movabs rax,0x6166203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332504820184434ULL);
x86_l_1c12:
	/* 0x1c12: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c17:
	/* 0x1c17: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c1c:
	/* 0x1c1c: mov    eax,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_1c21:
	/* 0x1c21: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1c26:
	/* 0x1c26: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_1c2b:
	/* 0x1c2b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c2d:
	/* 0x1c2d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1c2f:
	/* 0x1c2f: jmp    7ac <perf_unwind_ruby+0x7ac> */
	return 1964ULL;
x86_l_1c34:
	/* 0x1c34: movabs rax,0x6465646f636e6520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7234298806012896544ULL);
x86_l_1c3e:
	/* 0x1c3e: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1c43:
	/* 0x1c43: movabs rax,0x7165736920746567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8171063994286892391ULL);
x86_l_1c4d:
	/* 0x1c4d: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c52:
	/* 0x1c52: movabs rax,0x206f742064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414100720745ULL);
x86_l_1c5c:
	/* 0x1c5c: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c61:
	/* 0x1c61: movabs rax,0x6166203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332504820184434ULL);
x86_l_1c6b:
	/* 0x1c6b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c70:
	/* 0x1c70: mov    WORD PTR [rsp+0x50],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 343597383690ULL);
x86_l_1c77:
	/* 0x1c77: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c7c:
	/* 0x1c7c: mov    eax,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_1c81:
	/* 0x1c81: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1c86:
	/* 0x1c86: mov    esi,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 34ULL);
x86_l_1c8b:
	/* 0x1c8b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c8d:
	/* 0x1c8d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1c8f:
	/* 0x1c8f: jmp    835 <perf_unwind_ruby+0x835> */
	return 2101ULL;
x86_l_1c94:
	/* 0x1c94: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1c9e:
	/* 0x1c9e: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1ca3:
	/* 0x1ca3: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1cad:
	/* 0x1cad: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1cb2:
	/* 0x1cb2: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1cbc:
	/* 0x1cbc: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1cc1:
	/* 0x1cc1: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1ccb:
	/* 0x1ccb: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1cd0:
	/* 0x1cd0: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1cda:
	/* 0x1cda: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1cdf:
	/* 0x1cdf: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1ce9:
	/* 0x1ce9: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cee:
	/* 0x1cee: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cf3:
	/* 0x1cf3: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1cf8:
	/* 0x1cf8: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1cfd:
	/* 0x1cfd: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d00:
	/* 0x1d00: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1d05:
	/* 0x1d05: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d07:
	/* 0x1d07: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1d09:
	/* 0x1d09: jmp    868 <perf_unwind_ruby+0x868> */
	return 2152ULL;
x86_l_1d0e:
	/* 0x1d0e: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1d15:
	/* 0x1d15: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d18:
	/* 0x1d18: je     c3b <perf_unwind_ruby+0xc3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3131ULL;
	}
x86_l_1d1e:
	/* 0x1d1e: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1d28:
	/* 0x1d28: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1d2d:
	/* 0x1d2d: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1d37:
	/* 0x1d37: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d3c:
	/* 0x1d3c: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1d46:
	/* 0x1d46: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d4b:
	/* 0x1d4b: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1d55:
	/* 0x1d55: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d5a:
	/* 0x1d5a: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1d64:
	/* 0x1d64: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d69:
	/* 0x1d69: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1d73:
	/* 0x1d73: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d78:
	/* 0x1d78: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d7d:
	/* 0x1d7d: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1d82:
	/* 0x1d82: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1d87:
	/* 0x1d87: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d8a:
	/* 0x1d8a: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1d8f:
	/* 0x1d8f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d91:
	/* 0x1d91: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1d93:
	/* 0x1d93: jmp    c3b <perf_unwind_ruby+0xc3b> */
	return 3131ULL;
x86_l_1d98:
	/* 0x1d98: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_1d9f:
	/* 0x1d9f: jae    2247 <perf_unwind_ruby+0x2247> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8775ULL;
	}
x86_l_1da5:
	/* 0x1da5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1daa:
	/* 0x1daa: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1dad:
	/* 0x1dad: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_1db3:
	/* 0x1db3: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_1db8:
	/* 0x1db8: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1dbb:
	/* 0x1dbb: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dc0:
	/* 0x1dc0: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1dc9:
	/* 0x1dc9: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1dd2:
	/* 0x1dd2: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_1dd7:
	/* 0x1dd7: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1dda:
	/* 0x1dda: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ddf:
	/* 0x1ddf: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1de4:
	/* 0x1de4: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1dea:
	/* 0x1dea: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_1def:
	/* 0x1def: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1df4:
	/* 0x1df4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1df9:
	/* 0x1df9: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1dfc:
	/* 0x1dfc: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_1e01:
	/* 0x1e01: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1e06:
	/* 0x1e06: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e0b:
	/* 0x1e0b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e10:
	/* 0x1e10: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1e16:
	/* 0x1e16: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_1e1b:
	/* 0x1e1b: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1e20:
	/* 0x1e20: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e25:
	/* 0x1e25: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1e28:
	/* 0x1e28: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1e2e:
	/* 0x1e2e: je     2416 <perf_unwind_ruby+0x2416> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9238ULL;
	}
x86_l_1e34:
	/* 0x1e34: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e39:
	/* 0x1e39: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e3c:
	/* 0x1e3c: je     2416 <perf_unwind_ruby+0x2416> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9238ULL;
	}
x86_l_1e42:
	/* 0x1e42: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_1e47:
	/* 0x1e47: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e4a:
	/* 0x1e4a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e4f:
	/* 0x1e4f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e54:
	/* 0x1e54: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1e5a:
	/* 0x1e5a: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_1e5f:
	/* 0x1e5f: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1e64:
	/* 0x1e64: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e69:
	/* 0x1e69: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1e6c:
	/* 0x1e6c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e6f:
	/* 0x1e6f: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_1e75:
	/* 0x1e75: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_1e7a:
	/* 0x1e7a: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1e7f:
	/* 0x1e7f: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1e84:
	/* 0x1e84: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e89:
	/* 0x1e89: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1e8f:
	/* 0x1e8f: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_1e94:
	/* 0x1e94: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1e99:
	/* 0x1e99: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e9e:
	/* 0x1e9e: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1ea1:
	/* 0x1ea1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ea4:
	/* 0x1ea4: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_1eaa:
	/* 0x1eaa: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_1eaf:
	/* 0x1eaf: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1eb4:
	/* 0x1eb4: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1eb9:
	/* 0x1eb9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ebe:
	/* 0x1ebe: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_1ec4:
	/* 0x1ec4: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_1ec9:
	/* 0x1ec9: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1ece:
	/* 0x1ece: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ed3:
	/* 0x1ed3: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1ed6:
	/* 0x1ed6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ed9:
	/* 0x1ed9: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_1edf:
	/* 0x1edf: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ee4:
	/* 0x1ee4: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_1ee7:
	/* 0x1ee7: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_1eec:
	/* 0x1eec: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_1ef1:
	/* 0x1ef1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1ef4:
	/* 0x1ef4: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1ef8:
	/* 0x1ef8: je     2d59 <perf_unwind_ruby+0x2d59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11609ULL;
	}
x86_l_1efe:
	/* 0x1efe: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f00:
	/* 0x1f00: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
	return 7939ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7939ULL: goto x86_l_1f03;
	case 7944ULL: goto x86_l_1f08;
	case 7954ULL: goto x86_l_1f12;
	case 7959ULL: goto x86_l_1f17;
	case 7969ULL: goto x86_l_1f21;
	case 7974ULL: goto x86_l_1f26;
	case 7984ULL: goto x86_l_1f30;
	case 7989ULL: goto x86_l_1f35;
	case 7994ULL: goto x86_l_1f3a;
	case 7999ULL: goto x86_l_1f3f;
	case 8004ULL: goto x86_l_1f44;
	case 8009ULL: goto x86_l_1f49;
	case 8014ULL: goto x86_l_1f4e;
	case 8016ULL: goto x86_l_1f50;
	case 8018ULL: goto x86_l_1f52;
	case 8023ULL: goto x86_l_1f57;
	case 8033ULL: goto x86_l_1f61;
	case 8038ULL: goto x86_l_1f66;
	case 8048ULL: goto x86_l_1f70;
	case 8053ULL: goto x86_l_1f75;
	case 8063ULL: goto x86_l_1f7f;
	case 8068ULL: goto x86_l_1f84;
	case 8078ULL: goto x86_l_1f8e;
	case 8083ULL: goto x86_l_1f93;
	case 8093ULL: goto x86_l_1f9d;
	case 8098ULL: goto x86_l_1fa2;
	case 8108ULL: goto x86_l_1fac;
	case 8113ULL: goto x86_l_1fb1;
	case 8118ULL: goto x86_l_1fb6;
	case 8123ULL: goto x86_l_1fbb;
	case 8128ULL: goto x86_l_1fc0;
	case 8132ULL: goto x86_l_1fc4;
	case 8137ULL: goto x86_l_1fc9;
	case 8139ULL: goto x86_l_1fcb;
	case 8141ULL: goto x86_l_1fcd;
	case 8146ULL: goto x86_l_1fd2;
	case 8148ULL: goto x86_l_1fd4;
	case 8150ULL: goto x86_l_1fd6;
	case 8154ULL: goto x86_l_1fda;
	case 8157ULL: goto x86_l_1fdd;
	case 8163ULL: goto x86_l_1fe3;
	case 8170ULL: goto x86_l_1fea;
	case 8173ULL: goto x86_l_1fed;
	case 8179ULL: goto x86_l_1ff3;
	case 8189ULL: goto x86_l_1ffd;
	case 8194ULL: goto x86_l_2002;
	case 8204ULL: goto x86_l_200c;
	case 8209ULL: goto x86_l_2011;
	case 8219ULL: goto x86_l_201b;
	case 8224ULL: goto x86_l_2020;
	case 8234ULL: goto x86_l_202a;
	case 8239ULL: goto x86_l_202f;
	case 8249ULL: goto x86_l_2039;
	case 8254ULL: goto x86_l_203e;
	case 8264ULL: goto x86_l_2048;
	case 8269ULL: goto x86_l_204d;
	case 8274ULL: goto x86_l_2052;
	case 8279ULL: goto x86_l_2057;
	case 8284ULL: goto x86_l_205c;
	case 8289ULL: goto x86_l_2061;
	case 8291ULL: goto x86_l_2063;
	case 8293ULL: goto x86_l_2065;
	case 8298ULL: goto x86_l_206a;
	case 8305ULL: goto x86_l_2071;
	case 8309ULL: goto x86_l_2075;
	case 8315ULL: goto x86_l_207b;
	case 8320ULL: goto x86_l_2080;
	case 8323ULL: goto x86_l_2083;
	case 8330ULL: goto x86_l_208a;
	case 8334ULL: goto x86_l_208e;
	case 8341ULL: goto x86_l_2095;
	case 8348ULL: goto x86_l_209c;
	case 8356ULL: goto x86_l_20a4;
	case 8364ULL: goto x86_l_20ac;
	case 8375ULL: goto x86_l_20b7;
	case 8378ULL: goto x86_l_20ba;
	case 8386ULL: goto x86_l_20c2;
	case 8391ULL: goto x86_l_20c7;
	case 8400ULL: goto x86_l_20d0;
	case 8407ULL: goto x86_l_20d7;
	case 8414ULL: goto x86_l_20de;
	case 8417ULL: goto x86_l_20e1;
	case 8422ULL: goto x86_l_20e6;
	case 8424ULL: goto x86_l_20e8;
	case 8427ULL: goto x86_l_20eb;
	case 8433ULL: goto x86_l_20f1;
	case 8436ULL: goto x86_l_20f4;
	case 8441ULL: goto x86_l_20f9;
	case 8451ULL: goto x86_l_2103;
	case 8456ULL: goto x86_l_2108;
	case 8466ULL: goto x86_l_2112;
	case 8471ULL: goto x86_l_2117;
	case 8481ULL: goto x86_l_2121;
	case 8486ULL: goto x86_l_2126;
	case 8496ULL: goto x86_l_2130;
	case 8501ULL: goto x86_l_2135;
	case 8511ULL: goto x86_l_213f;
	case 8516ULL: goto x86_l_2144;
	case 8526ULL: goto x86_l_214e;
	case 8531ULL: goto x86_l_2153;
	case 8536ULL: goto x86_l_2158;
	case 8541ULL: goto x86_l_215d;
	case 8546ULL: goto x86_l_2162;
	case 8550ULL: goto x86_l_2166;
	case 8555ULL: goto x86_l_216b;
	case 8557ULL: goto x86_l_216d;
	case 8559ULL: goto x86_l_216f;
	case 8564ULL: goto x86_l_2174;
	case 8574ULL: goto x86_l_217e;
	case 8579ULL: goto x86_l_2183;
	case 8589ULL: goto x86_l_218d;
	case 8594ULL: goto x86_l_2192;
	case 8604ULL: goto x86_l_219c;
	case 8609ULL: goto x86_l_21a1;
	case 8619ULL: goto x86_l_21ab;
	case 8624ULL: goto x86_l_21b0;
	case 8629ULL: goto x86_l_21b5;
	case 8634ULL: goto x86_l_21ba;
	case 8639ULL: goto x86_l_21bf;
	case 8644ULL: goto x86_l_21c4;
	case 8646ULL: goto x86_l_21c6;
	case 8648ULL: goto x86_l_21c8;
	case 8653ULL: goto x86_l_21cd;
	case 8663ULL: goto x86_l_21d7;
	case 8668ULL: goto x86_l_21dc;
	case 8678ULL: goto x86_l_21e6;
	case 8683ULL: goto x86_l_21eb;
	case 8693ULL: goto x86_l_21f5;
	case 8698ULL: goto x86_l_21fa;
	case 8708ULL: goto x86_l_2204;
	case 8713ULL: goto x86_l_2209;
	case 8723ULL: goto x86_l_2213;
	case 8728ULL: goto x86_l_2218;
	case 8738ULL: goto x86_l_2222;
	case 8743ULL: goto x86_l_2227;
	case 8748ULL: goto x86_l_222c;
	case 8753ULL: goto x86_l_2231;
	case 8758ULL: goto x86_l_2236;
	case 8761ULL: goto x86_l_2239;
	case 8766ULL: goto x86_l_223e;
	case 8768ULL: goto x86_l_2240;
	case 8770ULL: goto x86_l_2242;
	case 8775ULL: goto x86_l_2247;
	case 8783ULL: goto x86_l_224f;
	case 8788ULL: goto x86_l_2254;
	case 8793ULL: goto x86_l_2259;
	case 8796ULL: goto x86_l_225c;
	case 8801ULL: goto x86_l_2261;
	case 8807ULL: goto x86_l_2267;
	case 8812ULL: goto x86_l_226c;
	case 8817ULL: goto x86_l_2271;
	case 8822ULL: goto x86_l_2276;
	case 8825ULL: goto x86_l_2279;
	case 8828ULL: goto x86_l_227c;
	case 8834ULL: goto x86_l_2282;
	case 8837ULL: goto x86_l_2285;
	case 8839ULL: goto x86_l_2287;
	case 8844ULL: goto x86_l_228c;
	case 8850ULL: goto x86_l_2292;
	case 8855ULL: goto x86_l_2297;
	case 8865ULL: goto x86_l_22a1;
	case 8870ULL: goto x86_l_22a6;
	case 8880ULL: goto x86_l_22b0;
	case 8885ULL: goto x86_l_22b5;
	case 8895ULL: goto x86_l_22bf;
	case 8900ULL: goto x86_l_22c4;
	case 8910ULL: goto x86_l_22ce;
	case 8915ULL: goto x86_l_22d3;
	case 8925ULL: goto x86_l_22dd;
	case 8930ULL: goto x86_l_22e2;
	case 8940ULL: goto x86_l_22ec;
	case 8945ULL: goto x86_l_22f1;
	case 8950ULL: goto x86_l_22f6;
	case 8955ULL: goto x86_l_22fb;
	case 8960ULL: goto x86_l_2300;
	case 8964ULL: goto x86_l_2304;
	case 8969ULL: goto x86_l_2309;
	case 8971ULL: goto x86_l_230b;
	case 8973ULL: goto x86_l_230d;
	case 8978ULL: goto x86_l_2312;
	case 8985ULL: goto x86_l_2319;
	case 8988ULL: goto x86_l_231c;
	case 8994ULL: goto x86_l_2322;
	case 9004ULL: goto x86_l_232c;
	case 9009ULL: goto x86_l_2331;
	case 9019ULL: goto x86_l_233b;
	case 9024ULL: goto x86_l_2340;
	case 9034ULL: goto x86_l_234a;
	case 9039ULL: goto x86_l_234f;
	case 9049ULL: goto x86_l_2359;
	case 9054ULL: goto x86_l_235e;
	case 9064ULL: goto x86_l_2368;
	case 9069ULL: goto x86_l_236d;
	case 9079ULL: goto x86_l_2377;
	case 9084ULL: goto x86_l_237c;
	case 9089ULL: goto x86_l_2381;
	case 9094ULL: goto x86_l_2386;
	case 9099ULL: goto x86_l_238b;
	case 9102ULL: goto x86_l_238e;
	case 9107ULL: goto x86_l_2393;
	case 9109ULL: goto x86_l_2395;
	case 9111ULL: goto x86_l_2397;
	case 9116ULL: goto x86_l_239c;
	case 9126ULL: goto x86_l_23a6;
	case 9131ULL: goto x86_l_23ab;
	case 9141ULL: goto x86_l_23b5;
	case 9146ULL: goto x86_l_23ba;
	case 9156ULL: goto x86_l_23c4;
	case 9161ULL: goto x86_l_23c9;
	case 9171ULL: goto x86_l_23d3;
	case 9176ULL: goto x86_l_23d8;
	case 9186ULL: goto x86_l_23e2;
	case 9191ULL: goto x86_l_23e7;
	case 9201ULL: goto x86_l_23f1;
	case 9206ULL: goto x86_l_23f6;
	case 9211ULL: goto x86_l_23fb;
	case 9216ULL: goto x86_l_2400;
	case 9221ULL: goto x86_l_2405;
	case 9224ULL: goto x86_l_2408;
	case 9229ULL: goto x86_l_240d;
	case 9231ULL: goto x86_l_240f;
	case 9233ULL: goto x86_l_2411;
	case 9238ULL: goto x86_l_2416;
	case 9245ULL: goto x86_l_241d;
	case 9251ULL: goto x86_l_2423;
	case 9256ULL: goto x86_l_2428;
	case 9259ULL: goto x86_l_242b;
	case 9265ULL: goto x86_l_2431;
	case 9270ULL: goto x86_l_2436;
	case 9273ULL: goto x86_l_2439;
	case 9278ULL: goto x86_l_243e;
	case 9287ULL: goto x86_l_2447;
	case 9296ULL: goto x86_l_2450;
	case 9301ULL: goto x86_l_2455;
	case 9304ULL: goto x86_l_2458;
	case 9309ULL: goto x86_l_245d;
	case 9314ULL: goto x86_l_2462;
	case 9320ULL: goto x86_l_2468;
	case 9325ULL: goto x86_l_246d;
	case 9330ULL: goto x86_l_2472;
	case 9335ULL: goto x86_l_2477;
	case 9338ULL: goto x86_l_247a;
	case 9343ULL: goto x86_l_247f;
	case 9348ULL: goto x86_l_2484;
	case 9353ULL: goto x86_l_2489;
	case 9358ULL: goto x86_l_248e;
	case 9364ULL: goto x86_l_2494;
	case 9369ULL: goto x86_l_2499;
	case 9374ULL: goto x86_l_249e;
	case 9379ULL: goto x86_l_24a3;
	case 9382ULL: goto x86_l_24a6;
	case 9388ULL: goto x86_l_24ac;
	case 9394ULL: goto x86_l_24b2;
	case 9399ULL: goto x86_l_24b7;
	case 9402ULL: goto x86_l_24ba;
	case 9408ULL: goto x86_l_24c0;
	case 9413ULL: goto x86_l_24c5;
	case 9416ULL: goto x86_l_24c8;
	case 9421ULL: goto x86_l_24cd;
	case 9426ULL: goto x86_l_24d2;
	case 9432ULL: goto x86_l_24d8;
	case 9437ULL: goto x86_l_24dd;
	case 9442ULL: goto x86_l_24e2;
	case 9447ULL: goto x86_l_24e7;
	case 9450ULL: goto x86_l_24ea;
	case 9453ULL: goto x86_l_24ed;
	case 9459ULL: goto x86_l_24f3;
	case 9464ULL: goto x86_l_24f8;
	case 9469ULL: goto x86_l_24fd;
	case 9474ULL: goto x86_l_2502;
	case 9479ULL: goto x86_l_2507;
	case 9485ULL: goto x86_l_250d;
	case 9490ULL: goto x86_l_2512;
	case 9495ULL: goto x86_l_2517;
	case 9500ULL: goto x86_l_251c;
	case 9503ULL: goto x86_l_251f;
	case 9506ULL: goto x86_l_2522;
	case 9512ULL: goto x86_l_2528;
	case 9517ULL: goto x86_l_252d;
	case 9522ULL: goto x86_l_2532;
	case 9527ULL: goto x86_l_2537;
	case 9532ULL: goto x86_l_253c;
	case 9538ULL: goto x86_l_2542;
	case 9543ULL: goto x86_l_2547;
	case 9548ULL: goto x86_l_254c;
	case 9553ULL: goto x86_l_2551;
	case 9556ULL: goto x86_l_2554;
	case 9559ULL: goto x86_l_2557;
	case 9565ULL: goto x86_l_255d;
	case 9570ULL: goto x86_l_2562;
	case 9573ULL: goto x86_l_2565;
	case 9578ULL: goto x86_l_256a;
	case 9583ULL: goto x86_l_256f;
	case 9586ULL: goto x86_l_2572;
	case 9590ULL: goto x86_l_2576;
	case 9596ULL: goto x86_l_257c;
	case 9598ULL: goto x86_l_257e;
	case 9601ULL: goto x86_l_2581;
	case 9606ULL: goto x86_l_2586;
	case 9608ULL: goto x86_l_2588;
	case 9610ULL: goto x86_l_258a;
	case 9614ULL: goto x86_l_258e;
	case 9617ULL: goto x86_l_2591;
	case 9623ULL: goto x86_l_2597;
	case 9630ULL: goto x86_l_259e;
	case 9633ULL: goto x86_l_25a1;
	case 9639ULL: goto x86_l_25a7;
	case 9649ULL: goto x86_l_25b1;
	case 9654ULL: goto x86_l_25b6;
	case 9664ULL: goto x86_l_25c0;
	case 9669ULL: goto x86_l_25c5;
	case 9679ULL: goto x86_l_25cf;
	case 9684ULL: goto x86_l_25d4;
	case 9694ULL: goto x86_l_25de;
	case 9699ULL: goto x86_l_25e3;
	case 9709ULL: goto x86_l_25ed;
	case 9714ULL: goto x86_l_25f2;
	case 9724ULL: goto x86_l_25fc;
	case 9729ULL: goto x86_l_2601;
	case 9734ULL: goto x86_l_2606;
	case 9739ULL: goto x86_l_260b;
	case 9744ULL: goto x86_l_2610;
	case 9749ULL: goto x86_l_2615;
	case 9751ULL: goto x86_l_2617;
	case 9753ULL: goto x86_l_2619;
	case 9758ULL: goto x86_l_261e;
	case 9765ULL: goto x86_l_2625;
	case 9769ULL: goto x86_l_2629;
	case 9775ULL: goto x86_l_262f;
	case 9780ULL: goto x86_l_2634;
	case 9783ULL: goto x86_l_2637;
	case 9790ULL: goto x86_l_263e;
	case 9794ULL: goto x86_l_2642;
	case 9801ULL: goto x86_l_2649;
	case 9808ULL: goto x86_l_2650;
	case 9816ULL: goto x86_l_2658;
	case 9824ULL: goto x86_l_2660;
	case 9835ULL: goto x86_l_266b;
	case 9838ULL: goto x86_l_266e;
	case 9846ULL: goto x86_l_2676;
	case 9851ULL: goto x86_l_267b;
	case 9860ULL: goto x86_l_2684;
	case 9867ULL: goto x86_l_268b;
	case 9874ULL: goto x86_l_2692;
	case 9877ULL: goto x86_l_2695;
	case 9882ULL: goto x86_l_269a;
	case 9884ULL: goto x86_l_269c;
	case 9887ULL: goto x86_l_269f;
	case 9893ULL: goto x86_l_26a5;
	case 9896ULL: goto x86_l_26a8;
	case 9901ULL: goto x86_l_26ad;
	case 9909ULL: goto x86_l_26b5;
	case 9914ULL: goto x86_l_26ba;
	case 9919ULL: goto x86_l_26bf;
	case 9922ULL: goto x86_l_26c2;
	case 9927ULL: goto x86_l_26c7;
	case 9933ULL: goto x86_l_26cd;
	case 9938ULL: goto x86_l_26d2;
	case 9943ULL: goto x86_l_26d7;
	case 9948ULL: goto x86_l_26dc;
	case 9951ULL: goto x86_l_26df;
	case 9954ULL: goto x86_l_26e2;
	case 9960ULL: goto x86_l_26e8;
	case 9963ULL: goto x86_l_26eb;
	case 9965ULL: goto x86_l_26ed;
	case 9970ULL: goto x86_l_26f2;
	case 9976ULL: goto x86_l_26f8;
	case 9981ULL: goto x86_l_26fd;
	case 9991ULL: goto x86_l_2707;
	case 9996ULL: goto x86_l_270c;
	case 10006ULL: goto x86_l_2716;
	case 10011ULL: goto x86_l_271b;
	case 10021ULL: goto x86_l_2725;
	case 10026ULL: goto x86_l_272a;
	case 10036ULL: goto x86_l_2734;
	case 10041ULL: goto x86_l_2739;
	case 10051ULL: goto x86_l_2743;
	case 10056ULL: goto x86_l_2748;
	case 10061ULL: goto x86_l_274d;
	case 10066ULL: goto x86_l_2752;
	case 10071ULL: goto x86_l_2757;
	case 10076ULL: goto x86_l_275c;
	case 10078ULL: goto x86_l_275e;
	case 10080ULL: goto x86_l_2760;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1f03:
	/* 0x1f03: jmp    2d5d <perf_unwind_ruby+0x2d5d> */
	return 11613ULL;
x86_l_1f08:
	/* 0x1f08: movabs rax,0xa70666320746567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 752213713703167335ULL);
x86_l_1f12:
	/* 0x1f12: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f17:
	/* 0x1f17: movabs rax,0x206f742064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414100720745ULL);
x86_l_1f21:
	/* 0x1f21: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f26:
	/* 0x1f26: movabs rax,0x6166203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332504820184434ULL);
x86_l_1f30:
	/* 0x1f30: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f35:
	/* 0x1f35: mov    BYTE PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1f3a:
	/* 0x1f3a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f3f:
	/* 0x1f3f: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1f44:
	/* 0x1f44: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1f49:
	/* 0x1f49: mov    esi,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_1f4e:
	/* 0x1f4e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f50:
	/* 0x1f50: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1f52:
	/* 0x1f52: jmp    8db <perf_unwind_ruby+0x8db> */
	return 2267ULL;
x86_l_1f57:
	/* 0x1f57: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1f61:
	/* 0x1f61: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1f66:
	/* 0x1f66: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1f70:
	/* 0x1f70: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f75:
	/* 0x1f75: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1f7f:
	/* 0x1f7f: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1f84:
	/* 0x1f84: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1f8e:
	/* 0x1f8e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f93:
	/* 0x1f93: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1f9d:
	/* 0x1f9d: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1fa2:
	/* 0x1fa2: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1fac:
	/* 0x1fac: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fb1:
	/* 0x1fb1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fb6:
	/* 0x1fb6: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1fbb:
	/* 0x1fbb: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1fc0:
	/* 0x1fc0: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fc4:
	/* 0x1fc4: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1fc9:
	/* 0x1fc9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fcb:
	/* 0x1fcb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1fcd:
	/* 0x1fcd: jmp    94b <perf_unwind_ruby+0x94b> */
	return 2379ULL;
x86_l_1fd2:
	/* 0x1fd2: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fd4:
	/* 0x1fd4: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_1fd6:
	/* 0x1fd6: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1fda:
	/* 0x1fda: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1fdd:
	/* 0x1fdd: jbe    206a <perf_unwind_ruby+0x206a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_206a;
	}
x86_l_1fe3:
	/* 0x1fe3: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1fea:
	/* 0x1fea: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fed:
	/* 0x1fed: je     110d <perf_unwind_ruby+0x110d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4365ULL;
	}
x86_l_1ff3:
	/* 0x1ff3: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_1ffd:
	/* 0x1ffd: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_2002:
	/* 0x2002: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_200c:
	/* 0x200c: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2011:
	/* 0x2011: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_201b:
	/* 0x201b: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2020:
	/* 0x2020: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_202a:
	/* 0x202a: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_202f:
	/* 0x202f: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_2039:
	/* 0x2039: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_203e:
	/* 0x203e: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_2048:
	/* 0x2048: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_204d:
	/* 0x204d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2052:
	/* 0x2052: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2057:
	/* 0x2057: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_205c:
	/* 0x205c: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_2061:
	/* 0x2061: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2063:
	/* 0x2063: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2065:
	/* 0x2065: jmp    110d <perf_unwind_ruby+0x110d> */
	return 4365ULL;
x86_l_206a:
	/* 0x206a: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_2071:
	/* 0x2071: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_2075:
	/* 0x2075: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_207b:
	/* 0x207b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2080:
	/* 0x2080: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2083:
	/* 0x2083: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_208a:
	/* 0x208a: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_208e:
	/* 0x208e: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_2095:
	/* 0x2095: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_209c:
	/* 0x209c: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_20a4:
	/* 0x20a4: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_20ac:
	/* 0x20ac: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_20b7:
	/* 0x20b7: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20ba:
	/* 0x20ba: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_20c2:
	/* 0x20c2: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_20c7:
	/* 0x20c7: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_20d0:
	/* 0x20d0: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_20d7:
	/* 0x20d7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_20de:
	/* 0x20de: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_20e1:
	/* 0x20e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20e6:
	/* 0x20e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20e8:
	/* 0x20e8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20eb:
	/* 0x20eb: je     2312 <perf_unwind_ruby+0x2312> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2312;
	}
x86_l_20f1:
	/* 0x20f1: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_20f4:
	/* 0x20f4: jmp    110d <perf_unwind_ruby+0x110d> */
	return 4365ULL;
x86_l_20f9:
	/* 0x20f9: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_2103:
	/* 0x2103: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2108:
	/* 0x2108: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_2112:
	/* 0x2112: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2117:
	/* 0x2117: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_2121:
	/* 0x2121: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2126:
	/* 0x2126: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_2130:
	/* 0x2130: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2135:
	/* 0x2135: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_213f:
	/* 0x213f: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2144:
	/* 0x2144: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_214e:
	/* 0x214e: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2153:
	/* 0x2153: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2158:
	/* 0x2158: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_215d:
	/* 0x215d: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2162:
	/* 0x2162: mov    edx,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_2166:
	/* 0x2166: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_216b:
	/* 0x216b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_216d:
	/* 0x216d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_216f:
	/* 0x216f: jmp    b40 <perf_unwind_ruby+0xb40> */
	return 2880ULL;
x86_l_2174:
	/* 0x2174: movabs rax,0xa657a69732071 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926326196674673ULL);
x86_l_217e:
	/* 0x217e: mov    QWORD PTR [rsp+0x47],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_2183:
	/* 0x2183: movabs rax,0x7165736920746567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8171063994286892391ULL);
x86_l_218d:
	/* 0x218d: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2192:
	/* 0x2192: movabs rax,0x206f742064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414100720745ULL);
x86_l_219c:
	/* 0x219c: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21a1:
	/* 0x21a1: movabs rax,0x6166203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332504820184434ULL);
x86_l_21ab:
	/* 0x21ab: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21b0:
	/* 0x21b0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21b5:
	/* 0x21b5: mov    eax,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_21ba:
	/* 0x21ba: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_21bf:
	/* 0x21bf: mov    esi,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 31ULL);
x86_l_21c4:
	/* 0x21c4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21c6:
	/* 0x21c6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_21c8:
	/* 0x21c8: jmp    b0d <perf_unwind_ruby+0xb0d> */
	return 2829ULL;
x86_l_21cd:
	/* 0x21cd: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_21d7:
	/* 0x21d7: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_21dc:
	/* 0x21dc: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_21e6:
	/* 0x21e6: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_21eb:
	/* 0x21eb: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_21f5:
	/* 0x21f5: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_21fa:
	/* 0x21fa: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_2204:
	/* 0x2204: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2209:
	/* 0x2209: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2213:
	/* 0x2213: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2218:
	/* 0x2218: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2222:
	/* 0x2222: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2227:
	/* 0x2227: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_222c:
	/* 0x222c: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2231:
	/* 0x2231: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2236:
	/* 0x2236: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2239:
	/* 0x2239: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_223e:
	/* 0x223e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2240:
	/* 0x2240: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2242:
	/* 0x2242: jmp    b57 <perf_unwind_ruby+0xb57> */
	return 2903ULL;
x86_l_2247:
	/* 0x2247: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_224f:
	/* 0x224f: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_2254:
	/* 0x2254: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2259:
	/* 0x2259: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_225c:
	/* 0x225c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2261:
	/* 0x2261: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2267:
	/* 0x2267: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_226c:
	/* 0x226c: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2271:
	/* 0x2271: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2276:
	/* 0x2276: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2279:
	/* 0x2279: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_227c:
	/* 0x227c: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_2282:
	/* 0x2282: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2285:
	/* 0x2285: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2287:
	/* 0x2287: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_228c:
	/* 0x228c: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_2292:
	/* 0x2292: jmp    1da5 <perf_unwind_ruby+0x1da5> */
	return 7589ULL;
x86_l_2297:
	/* 0x2297: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_22a1:
	/* 0x22a1: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_22a6:
	/* 0x22a6: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_22b0:
	/* 0x22b0: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_22b5:
	/* 0x22b5: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_22bf:
	/* 0x22bf: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_22c4:
	/* 0x22c4: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_22ce:
	/* 0x22ce: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_22d3:
	/* 0x22d3: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_22dd:
	/* 0x22dd: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_22e2:
	/* 0x22e2: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_22ec:
	/* 0x22ec: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22f1:
	/* 0x22f1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22f6:
	/* 0x22f6: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_22fb:
	/* 0x22fb: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2300:
	/* 0x2300: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2304:
	/* 0x2304: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2309:
	/* 0x2309: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_230b:
	/* 0x230b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_230d:
	/* 0x230d: jmp    be1 <perf_unwind_ruby+0xbe1> */
	return 3041ULL;
x86_l_2312:
	/* 0x2312: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2319:
	/* 0x2319: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_231c:
	/* 0x231c: je     110d <perf_unwind_ruby+0x110d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4365ULL;
	}
x86_l_2322:
	/* 0x2322: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_232c:
	/* 0x232c: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2331:
	/* 0x2331: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_233b:
	/* 0x233b: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2340:
	/* 0x2340: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_234a:
	/* 0x234a: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_234f:
	/* 0x234f: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_2359:
	/* 0x2359: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_235e:
	/* 0x235e: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2368:
	/* 0x2368: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_236d:
	/* 0x236d: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2377:
	/* 0x2377: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_237c:
	/* 0x237c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2381:
	/* 0x2381: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2386:
	/* 0x2386: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_238b:
	/* 0x238b: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_238e:
	/* 0x238e: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2393:
	/* 0x2393: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2395:
	/* 0x2395: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2397:
	/* 0x2397: jmp    110d <perf_unwind_ruby+0x110d> */
	return 4365ULL;
x86_l_239c:
	/* 0x239c: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_23a6:
	/* 0x23a6: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_23ab:
	/* 0x23ab: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_23b5:
	/* 0x23b5: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_23ba:
	/* 0x23ba: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_23c4:
	/* 0x23c4: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_23c9:
	/* 0x23c9: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_23d3:
	/* 0x23d3: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_23d8:
	/* 0x23d8: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_23e2:
	/* 0x23e2: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_23e7:
	/* 0x23e7: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_23f1:
	/* 0x23f1: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23f6:
	/* 0x23f6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23fb:
	/* 0x23fb: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2400:
	/* 0x2400: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2405:
	/* 0x2405: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2408:
	/* 0x2408: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_240d:
	/* 0x240d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_240f:
	/* 0x240f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2411:
	/* 0x2411: jmp    c21 <perf_unwind_ruby+0xc21> */
	return 3105ULL;
x86_l_2416:
	/* 0x2416: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_241d:
	/* 0x241d: jae    26ad <perf_unwind_ruby+0x26ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_26ad;
	}
x86_l_2423:
	/* 0x2423: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2428:
	/* 0x2428: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_242b:
	/* 0x242b: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_2431:
	/* 0x2431: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_2436:
	/* 0x2436: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2439:
	/* 0x2439: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_243e:
	/* 0x243e: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2447:
	/* 0x2447: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2450:
	/* 0x2450: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_2455:
	/* 0x2455: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2458:
	/* 0x2458: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_245d:
	/* 0x245d: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_2462:
	/* 0x2462: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2468:
	/* 0x2468: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_246d:
	/* 0x246d: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2472:
	/* 0x2472: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2477:
	/* 0x2477: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_247a:
	/* 0x247a: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_247f:
	/* 0x247f: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2484:
	/* 0x2484: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2489:
	/* 0x2489: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_248e:
	/* 0x248e: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2494:
	/* 0x2494: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_2499:
	/* 0x2499: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_249e:
	/* 0x249e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24a3:
	/* 0x24a3: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_24a6:
	/* 0x24a6: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_24ac:
	/* 0x24ac: je     287c <perf_unwind_ruby+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10364ULL;
	}
x86_l_24b2:
	/* 0x24b2: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24b7:
	/* 0x24b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24ba:
	/* 0x24ba: je     287c <perf_unwind_ruby+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10364ULL;
	}
x86_l_24c0:
	/* 0x24c0: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_24c5:
	/* 0x24c5: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_24c8:
	/* 0x24c8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24cd:
	/* 0x24cd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_24d2:
	/* 0x24d2: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_24d8:
	/* 0x24d8: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_24dd:
	/* 0x24dd: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_24e2:
	/* 0x24e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24e7:
	/* 0x24e7: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_24ea:
	/* 0x24ea: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24ed:
	/* 0x24ed: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_24f3:
	/* 0x24f3: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_24f8:
	/* 0x24f8: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_24fd:
	/* 0x24fd: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2502:
	/* 0x2502: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2507:
	/* 0x2507: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_250d:
	/* 0x250d: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_2512:
	/* 0x2512: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2517:
	/* 0x2517: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_251c:
	/* 0x251c: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_251f:
	/* 0x251f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2522:
	/* 0x2522: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_2528:
	/* 0x2528: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_252d:
	/* 0x252d: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2532:
	/* 0x2532: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2537:
	/* 0x2537: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_253c:
	/* 0x253c: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2542:
	/* 0x2542: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_2547:
	/* 0x2547: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_254c:
	/* 0x254c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2551:
	/* 0x2551: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2554:
	/* 0x2554: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2557:
	/* 0x2557: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_255d:
	/* 0x255d: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2562:
	/* 0x2562: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_2565:
	/* 0x2565: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_256a:
	/* 0x256a: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_256f:
	/* 0x256f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2572:
	/* 0x2572: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2576:
	/* 0x2576: je     30c6 <perf_unwind_ruby+0x30c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12486ULL;
	}
x86_l_257c:
	/* 0x257c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_257e:
	/* 0x257e: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_2581:
	/* 0x2581: jmp    30ca <perf_unwind_ruby+0x30ca> */
	return 12490ULL;
x86_l_2586:
	/* 0x2586: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2588:
	/* 0x2588: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_258a:
	/* 0x258a: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_258e:
	/* 0x258e: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_2591:
	/* 0x2591: jbe    261e <perf_unwind_ruby+0x261e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_261e;
	}
x86_l_2597:
	/* 0x2597: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_259e:
	/* 0x259e: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25a1:
	/* 0x25a1: je     1773 <perf_unwind_ruby+0x1773> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6003ULL;
	}
x86_l_25a7:
	/* 0x25a7: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_25b1:
	/* 0x25b1: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_25b6:
	/* 0x25b6: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_25c0:
	/* 0x25c0: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_25c5:
	/* 0x25c5: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_25cf:
	/* 0x25cf: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_25d4:
	/* 0x25d4: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_25de:
	/* 0x25de: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25e3:
	/* 0x25e3: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_25ed:
	/* 0x25ed: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_25f2:
	/* 0x25f2: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_25fc:
	/* 0x25fc: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2601:
	/* 0x2601: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2606:
	/* 0x2606: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_260b:
	/* 0x260b: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2610:
	/* 0x2610: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_2615:
	/* 0x2615: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2617:
	/* 0x2617: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2619:
	/* 0x2619: jmp    1773 <perf_unwind_ruby+0x1773> */
	return 6003ULL;
x86_l_261e:
	/* 0x261e: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_2625:
	/* 0x2625: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_2629:
	/* 0x2629: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_262f:
	/* 0x262f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2634:
	/* 0x2634: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2637:
	/* 0x2637: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_263e:
	/* 0x263e: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2642:
	/* 0x2642: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_2649:
	/* 0x2649: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2650:
	/* 0x2650: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_2658:
	/* 0x2658: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_2660:
	/* 0x2660: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_266b:
	/* 0x266b: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_266e:
	/* 0x266e: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_2676:
	/* 0x2676: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_267b:
	/* 0x267b: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_2684:
	/* 0x2684: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_268b:
	/* 0x268b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_2692:
	/* 0x2692: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2695:
	/* 0x2695: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_269a:
	/* 0x269a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_269c:
	/* 0x269c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_269f:
	/* 0x269f: je     2765 <perf_unwind_ruby+0x2765> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10085ULL;
	}
x86_l_26a5:
	/* 0x26a5: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_26a8:
	/* 0x26a8: jmp    1773 <perf_unwind_ruby+0x1773> */
	return 6003ULL;
x86_l_26ad:
	/* 0x26ad: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26b5:
	/* 0x26b5: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_26ba:
	/* 0x26ba: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_26bf:
	/* 0x26bf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_26c2:
	/* 0x26c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_26c7:
	/* 0x26c7: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_26cd:
	/* 0x26cd: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_26d2:
	/* 0x26d2: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_26d7:
	/* 0x26d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26dc:
	/* 0x26dc: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_26df:
	/* 0x26df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26e2:
	/* 0x26e2: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_26e8:
	/* 0x26e8: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26eb:
	/* 0x26eb: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_26ed:
	/* 0x26ed: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_26f2:
	/* 0x26f2: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_26f8:
	/* 0x26f8: jmp    2423 <perf_unwind_ruby+0x2423> */
	goto x86_l_2423;
x86_l_26fd:
	/* 0x26fd: movabs rax,0xa6c6c75662073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2933962849001587ULL);
x86_l_2707:
	/* 0x2707: mov    QWORD PTR [rsp+0x4d],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_270c:
	/* 0x270c: movabs rax,0x66207369206b6361 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7359008686476059489ULL);
x86_l_2716:
	/* 0x2716: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_271b:
	/* 0x271b: movabs rax,0x7473203a656d6172 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8391085965903225202ULL);
x86_l_2725:
	/* 0x2725: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_272a:
	/* 0x272a: movabs rax,0x662068737570206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358996636224200815ULL);
x86_l_2734:
	/* 0x2734: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2739:
	/* 0x2739: movabs rax,0x7420656c62616e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367799623835807349ULL);
x86_l_2743:
	/* 0x2743: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2748:
	/* 0x2748: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_274d:
	/* 0x274d: mov    eax,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_2752:
	/* 0x2752: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2757:
	/* 0x2757: mov    esi,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 37ULL);
x86_l_275c:
	/* 0x275c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_275e:
	/* 0x275e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2760:
	/* 0x2760: jmp    e5b <perf_unwind_ruby+0xe5b> */
	return 3675ULL;
	return 10085ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10085ULL: goto x86_l_2765;
	case 10092ULL: goto x86_l_276c;
	case 10095ULL: goto x86_l_276f;
	case 10101ULL: goto x86_l_2775;
	case 10111ULL: goto x86_l_277f;
	case 10116ULL: goto x86_l_2784;
	case 10126ULL: goto x86_l_278e;
	case 10131ULL: goto x86_l_2793;
	case 10141ULL: goto x86_l_279d;
	case 10146ULL: goto x86_l_27a2;
	case 10156ULL: goto x86_l_27ac;
	case 10161ULL: goto x86_l_27b1;
	case 10171ULL: goto x86_l_27bb;
	case 10176ULL: goto x86_l_27c0;
	case 10186ULL: goto x86_l_27ca;
	case 10191ULL: goto x86_l_27cf;
	case 10196ULL: goto x86_l_27d4;
	case 10201ULL: goto x86_l_27d9;
	case 10206ULL: goto x86_l_27de;
	case 10209ULL: goto x86_l_27e1;
	case 10214ULL: goto x86_l_27e6;
	case 10216ULL: goto x86_l_27e8;
	case 10218ULL: goto x86_l_27ea;
	case 10223ULL: goto x86_l_27ef;
	case 10233ULL: goto x86_l_27f9;
	case 10238ULL: goto x86_l_27fe;
	case 10248ULL: goto x86_l_2808;
	case 10253ULL: goto x86_l_280d;
	case 10263ULL: goto x86_l_2817;
	case 10268ULL: goto x86_l_281c;
	case 10278ULL: goto x86_l_2826;
	case 10283ULL: goto x86_l_282b;
	case 10293ULL: goto x86_l_2835;
	case 10298ULL: goto x86_l_283a;
	case 10308ULL: goto x86_l_2844;
	case 10313ULL: goto x86_l_2849;
	case 10318ULL: goto x86_l_284e;
	case 10323ULL: goto x86_l_2853;
	case 10328ULL: goto x86_l_2858;
	case 10332ULL: goto x86_l_285c;
	case 10337ULL: goto x86_l_2861;
	case 10339ULL: goto x86_l_2863;
	case 10341ULL: goto x86_l_2865;
	case 10345ULL: goto x86_l_2869;
	case 10351ULL: goto x86_l_286f;
	case 10357ULL: goto x86_l_2875;
	case 10359ULL: goto x86_l_2877;
	case 10364ULL: goto x86_l_287c;
	case 10371ULL: goto x86_l_2883;
	case 10377ULL: goto x86_l_2889;
	case 10382ULL: goto x86_l_288e;
	case 10385ULL: goto x86_l_2891;
	case 10391ULL: goto x86_l_2897;
	case 10396ULL: goto x86_l_289c;
	case 10399ULL: goto x86_l_289f;
	case 10404ULL: goto x86_l_28a4;
	case 10413ULL: goto x86_l_28ad;
	case 10422ULL: goto x86_l_28b6;
	case 10427ULL: goto x86_l_28bb;
	case 10430ULL: goto x86_l_28be;
	case 10435ULL: goto x86_l_28c3;
	case 10440ULL: goto x86_l_28c8;
	case 10446ULL: goto x86_l_28ce;
	case 10451ULL: goto x86_l_28d3;
	case 10456ULL: goto x86_l_28d8;
	case 10461ULL: goto x86_l_28dd;
	case 10464ULL: goto x86_l_28e0;
	case 10469ULL: goto x86_l_28e5;
	case 10474ULL: goto x86_l_28ea;
	case 10479ULL: goto x86_l_28ef;
	case 10484ULL: goto x86_l_28f4;
	case 10490ULL: goto x86_l_28fa;
	case 10495ULL: goto x86_l_28ff;
	case 10500ULL: goto x86_l_2904;
	case 10505ULL: goto x86_l_2909;
	case 10508ULL: goto x86_l_290c;
	case 10514ULL: goto x86_l_2912;
	case 10520ULL: goto x86_l_2918;
	case 10525ULL: goto x86_l_291d;
	case 10528ULL: goto x86_l_2920;
	case 10534ULL: goto x86_l_2926;
	case 10539ULL: goto x86_l_292b;
	case 10542ULL: goto x86_l_292e;
	case 10547ULL: goto x86_l_2933;
	case 10552ULL: goto x86_l_2938;
	case 10558ULL: goto x86_l_293e;
	case 10563ULL: goto x86_l_2943;
	case 10568ULL: goto x86_l_2948;
	case 10573ULL: goto x86_l_294d;
	case 10576ULL: goto x86_l_2950;
	case 10579ULL: goto x86_l_2953;
	case 10585ULL: goto x86_l_2959;
	case 10590ULL: goto x86_l_295e;
	case 10595ULL: goto x86_l_2963;
	case 10600ULL: goto x86_l_2968;
	case 10605ULL: goto x86_l_296d;
	case 10611ULL: goto x86_l_2973;
	case 10616ULL: goto x86_l_2978;
	case 10621ULL: goto x86_l_297d;
	case 10626ULL: goto x86_l_2982;
	case 10629ULL: goto x86_l_2985;
	case 10632ULL: goto x86_l_2988;
	case 10638ULL: goto x86_l_298e;
	case 10643ULL: goto x86_l_2993;
	case 10648ULL: goto x86_l_2998;
	case 10653ULL: goto x86_l_299d;
	case 10658ULL: goto x86_l_29a2;
	case 10664ULL: goto x86_l_29a8;
	case 10669ULL: goto x86_l_29ad;
	case 10674ULL: goto x86_l_29b2;
	case 10679ULL: goto x86_l_29b7;
	case 10682ULL: goto x86_l_29ba;
	case 10685ULL: goto x86_l_29bd;
	case 10691ULL: goto x86_l_29c3;
	case 10696ULL: goto x86_l_29c8;
	case 10699ULL: goto x86_l_29cb;
	case 10704ULL: goto x86_l_29d0;
	case 10709ULL: goto x86_l_29d5;
	case 10712ULL: goto x86_l_29d8;
	case 10716ULL: goto x86_l_29dc;
	case 10722ULL: goto x86_l_29e2;
	case 10724ULL: goto x86_l_29e4;
	case 10727ULL: goto x86_l_29e7;
	case 10732ULL: goto x86_l_29ec;
	case 10734ULL: goto x86_l_29ee;
	case 10736ULL: goto x86_l_29f0;
	case 10740ULL: goto x86_l_29f4;
	case 10743ULL: goto x86_l_29f7;
	case 10749ULL: goto x86_l_29fd;
	case 10756ULL: goto x86_l_2a04;
	case 10759ULL: goto x86_l_2a07;
	case 10765ULL: goto x86_l_2a0d;
	case 10775ULL: goto x86_l_2a17;
	case 10780ULL: goto x86_l_2a1c;
	case 10790ULL: goto x86_l_2a26;
	case 10795ULL: goto x86_l_2a2b;
	case 10805ULL: goto x86_l_2a35;
	case 10810ULL: goto x86_l_2a3a;
	case 10820ULL: goto x86_l_2a44;
	case 10825ULL: goto x86_l_2a49;
	case 10835ULL: goto x86_l_2a53;
	case 10840ULL: goto x86_l_2a58;
	case 10850ULL: goto x86_l_2a62;
	case 10855ULL: goto x86_l_2a67;
	case 10860ULL: goto x86_l_2a6c;
	case 10865ULL: goto x86_l_2a71;
	case 10870ULL: goto x86_l_2a76;
	case 10875ULL: goto x86_l_2a7b;
	case 10877ULL: goto x86_l_2a7d;
	case 10879ULL: goto x86_l_2a7f;
	case 10884ULL: goto x86_l_2a84;
	case 10891ULL: goto x86_l_2a8b;
	case 10895ULL: goto x86_l_2a8f;
	case 10901ULL: goto x86_l_2a95;
	case 10906ULL: goto x86_l_2a9a;
	case 10909ULL: goto x86_l_2a9d;
	case 10916ULL: goto x86_l_2aa4;
	case 10920ULL: goto x86_l_2aa8;
	case 10927ULL: goto x86_l_2aaf;
	case 10934ULL: goto x86_l_2ab6;
	case 10942ULL: goto x86_l_2abe;
	case 10950ULL: goto x86_l_2ac6;
	case 10961ULL: goto x86_l_2ad1;
	case 10964ULL: goto x86_l_2ad4;
	case 10972ULL: goto x86_l_2adc;
	case 10977ULL: goto x86_l_2ae1;
	case 10986ULL: goto x86_l_2aea;
	case 10993ULL: goto x86_l_2af1;
	case 11000ULL: goto x86_l_2af8;
	case 11003ULL: goto x86_l_2afb;
	case 11008ULL: goto x86_l_2b00;
	case 11010ULL: goto x86_l_2b02;
	case 11013ULL: goto x86_l_2b05;
	case 11015ULL: goto x86_l_2b07;
	case 11018ULL: goto x86_l_2b0a;
	case 11023ULL: goto x86_l_2b0f;
	case 11031ULL: goto x86_l_2b17;
	case 11036ULL: goto x86_l_2b1c;
	case 11041ULL: goto x86_l_2b21;
	case 11044ULL: goto x86_l_2b24;
	case 11049ULL: goto x86_l_2b29;
	case 11055ULL: goto x86_l_2b2f;
	case 11060ULL: goto x86_l_2b34;
	case 11065ULL: goto x86_l_2b39;
	case 11070ULL: goto x86_l_2b3e;
	case 11073ULL: goto x86_l_2b41;
	case 11076ULL: goto x86_l_2b44;
	case 11082ULL: goto x86_l_2b4a;
	case 11085ULL: goto x86_l_2b4d;
	case 11087ULL: goto x86_l_2b4f;
	case 11092ULL: goto x86_l_2b54;
	case 11098ULL: goto x86_l_2b5a;
	case 11103ULL: goto x86_l_2b5f;
	case 11110ULL: goto x86_l_2b66;
	case 11113ULL: goto x86_l_2b69;
	case 11119ULL: goto x86_l_2b6f;
	case 11129ULL: goto x86_l_2b79;
	case 11134ULL: goto x86_l_2b7e;
	case 11144ULL: goto x86_l_2b88;
	case 11149ULL: goto x86_l_2b8d;
	case 11159ULL: goto x86_l_2b97;
	case 11164ULL: goto x86_l_2b9c;
	case 11174ULL: goto x86_l_2ba6;
	case 11179ULL: goto x86_l_2bab;
	case 11189ULL: goto x86_l_2bb5;
	case 11194ULL: goto x86_l_2bba;
	case 11204ULL: goto x86_l_2bc4;
	case 11209ULL: goto x86_l_2bc9;
	case 11214ULL: goto x86_l_2bce;
	case 11219ULL: goto x86_l_2bd3;
	case 11224ULL: goto x86_l_2bd8;
	case 11227ULL: goto x86_l_2bdb;
	case 11232ULL: goto x86_l_2be0;
	case 11234ULL: goto x86_l_2be2;
	case 11236ULL: goto x86_l_2be4;
	case 11241ULL: goto x86_l_2be9;
	case 11248ULL: goto x86_l_2bf0;
	case 11254ULL: goto x86_l_2bf6;
	case 11259ULL: goto x86_l_2bfb;
	case 11262ULL: goto x86_l_2bfe;
	case 11268ULL: goto x86_l_2c04;
	case 11273ULL: goto x86_l_2c09;
	case 11276ULL: goto x86_l_2c0c;
	case 11281ULL: goto x86_l_2c11;
	case 11290ULL: goto x86_l_2c1a;
	case 11299ULL: goto x86_l_2c23;
	case 11304ULL: goto x86_l_2c28;
	case 11307ULL: goto x86_l_2c2b;
	case 11312ULL: goto x86_l_2c30;
	case 11317ULL: goto x86_l_2c35;
	case 11323ULL: goto x86_l_2c3b;
	case 11328ULL: goto x86_l_2c40;
	case 11333ULL: goto x86_l_2c45;
	case 11338ULL: goto x86_l_2c4a;
	case 11341ULL: goto x86_l_2c4d;
	case 11346ULL: goto x86_l_2c52;
	case 11351ULL: goto x86_l_2c57;
	case 11356ULL: goto x86_l_2c5c;
	case 11361ULL: goto x86_l_2c61;
	case 11367ULL: goto x86_l_2c67;
	case 11372ULL: goto x86_l_2c6c;
	case 11377ULL: goto x86_l_2c71;
	case 11382ULL: goto x86_l_2c76;
	case 11385ULL: goto x86_l_2c79;
	case 11391ULL: goto x86_l_2c7f;
	case 11397ULL: goto x86_l_2c85;
	case 11402ULL: goto x86_l_2c8a;
	case 11405ULL: goto x86_l_2c8d;
	case 11411ULL: goto x86_l_2c93;
	case 11416ULL: goto x86_l_2c98;
	case 11419ULL: goto x86_l_2c9b;
	case 11424ULL: goto x86_l_2ca0;
	case 11429ULL: goto x86_l_2ca5;
	case 11435ULL: goto x86_l_2cab;
	case 11440ULL: goto x86_l_2cb0;
	case 11445ULL: goto x86_l_2cb5;
	case 11450ULL: goto x86_l_2cba;
	case 11453ULL: goto x86_l_2cbd;
	case 11456ULL: goto x86_l_2cc0;
	case 11462ULL: goto x86_l_2cc6;
	case 11467ULL: goto x86_l_2ccb;
	case 11472ULL: goto x86_l_2cd0;
	case 11477ULL: goto x86_l_2cd5;
	case 11482ULL: goto x86_l_2cda;
	case 11488ULL: goto x86_l_2ce0;
	case 11493ULL: goto x86_l_2ce5;
	case 11498ULL: goto x86_l_2cea;
	case 11503ULL: goto x86_l_2cef;
	case 11506ULL: goto x86_l_2cf2;
	case 11509ULL: goto x86_l_2cf5;
	case 11515ULL: goto x86_l_2cfb;
	case 11520ULL: goto x86_l_2d00;
	case 11525ULL: goto x86_l_2d05;
	case 11530ULL: goto x86_l_2d0a;
	case 11535ULL: goto x86_l_2d0f;
	case 11541ULL: goto x86_l_2d15;
	case 11546ULL: goto x86_l_2d1a;
	case 11551ULL: goto x86_l_2d1f;
	case 11556ULL: goto x86_l_2d24;
	case 11559ULL: goto x86_l_2d27;
	case 11562ULL: goto x86_l_2d2a;
	case 11568ULL: goto x86_l_2d30;
	case 11573ULL: goto x86_l_2d35;
	case 11576ULL: goto x86_l_2d38;
	case 11581ULL: goto x86_l_2d3d;
	case 11586ULL: goto x86_l_2d42;
	case 11589ULL: goto x86_l_2d45;
	case 11593ULL: goto x86_l_2d49;
	case 11599ULL: goto x86_l_2d4f;
	case 11601ULL: goto x86_l_2d51;
	case 11604ULL: goto x86_l_2d54;
	case 11609ULL: goto x86_l_2d59;
	case 11611ULL: goto x86_l_2d5b;
	case 11613ULL: goto x86_l_2d5d;
	case 11617ULL: goto x86_l_2d61;
	case 11620ULL: goto x86_l_2d64;
	case 11626ULL: goto x86_l_2d6a;
	case 11633ULL: goto x86_l_2d71;
	case 11636ULL: goto x86_l_2d74;
	case 11642ULL: goto x86_l_2d7a;
	case 11652ULL: goto x86_l_2d84;
	case 11657ULL: goto x86_l_2d89;
	case 11667ULL: goto x86_l_2d93;
	case 11672ULL: goto x86_l_2d98;
	case 11682ULL: goto x86_l_2da2;
	case 11687ULL: goto x86_l_2da7;
	case 11697ULL: goto x86_l_2db1;
	case 11702ULL: goto x86_l_2db6;
	case 11712ULL: goto x86_l_2dc0;
	case 11717ULL: goto x86_l_2dc5;
	case 11727ULL: goto x86_l_2dcf;
	case 11732ULL: goto x86_l_2dd4;
	case 11737ULL: goto x86_l_2dd9;
	case 11742ULL: goto x86_l_2dde;
	case 11747ULL: goto x86_l_2de3;
	case 11752ULL: goto x86_l_2de8;
	case 11754ULL: goto x86_l_2dea;
	case 11756ULL: goto x86_l_2dec;
	case 11761ULL: goto x86_l_2df1;
	case 11768ULL: goto x86_l_2df8;
	case 11772ULL: goto x86_l_2dfc;
	case 11778ULL: goto x86_l_2e02;
	case 11783ULL: goto x86_l_2e07;
	case 11786ULL: goto x86_l_2e0a;
	case 11793ULL: goto x86_l_2e11;
	case 11797ULL: goto x86_l_2e15;
	case 11804ULL: goto x86_l_2e1c;
	case 11811ULL: goto x86_l_2e23;
	case 11819ULL: goto x86_l_2e2b;
	case 11827ULL: goto x86_l_2e33;
	case 11838ULL: goto x86_l_2e3e;
	case 11841ULL: goto x86_l_2e41;
	case 11849ULL: goto x86_l_2e49;
	case 11854ULL: goto x86_l_2e4e;
	case 11863ULL: goto x86_l_2e57;
	case 11870ULL: goto x86_l_2e5e;
	case 11877ULL: goto x86_l_2e65;
	case 11880ULL: goto x86_l_2e68;
	case 11885ULL: goto x86_l_2e6d;
	case 11887ULL: goto x86_l_2e6f;
	case 11890ULL: goto x86_l_2e72;
	case 11892ULL: goto x86_l_2e74;
	case 11895ULL: goto x86_l_2e77;
	case 11900ULL: goto x86_l_2e7c;
	case 11908ULL: goto x86_l_2e84;
	case 11913ULL: goto x86_l_2e89;
	case 11918ULL: goto x86_l_2e8e;
	case 11921ULL: goto x86_l_2e91;
	case 11926ULL: goto x86_l_2e96;
	case 11932ULL: goto x86_l_2e9c;
	case 11937ULL: goto x86_l_2ea1;
	case 11942ULL: goto x86_l_2ea6;
	case 11947ULL: goto x86_l_2eab;
	case 11950ULL: goto x86_l_2eae;
	case 11953ULL: goto x86_l_2eb1;
	case 11959ULL: goto x86_l_2eb7;
	case 11962ULL: goto x86_l_2eba;
	case 11964ULL: goto x86_l_2ebc;
	case 11969ULL: goto x86_l_2ec1;
	case 11975ULL: goto x86_l_2ec7;
	case 11980ULL: goto x86_l_2ecc;
	case 11987ULL: goto x86_l_2ed3;
	case 11990ULL: goto x86_l_2ed6;
	case 11996ULL: goto x86_l_2edc;
	case 12006ULL: goto x86_l_2ee6;
	case 12011ULL: goto x86_l_2eeb;
	case 12021ULL: goto x86_l_2ef5;
	case 12026ULL: goto x86_l_2efa;
	case 12036ULL: goto x86_l_2f04;
	case 12041ULL: goto x86_l_2f09;
	case 12051ULL: goto x86_l_2f13;
	case 12056ULL: goto x86_l_2f18;
	case 12066ULL: goto x86_l_2f22;
	case 12071ULL: goto x86_l_2f27;
	case 12081ULL: goto x86_l_2f31;
	case 12086ULL: goto x86_l_2f36;
	case 12091ULL: goto x86_l_2f3b;
	case 12096ULL: goto x86_l_2f40;
	case 12101ULL: goto x86_l_2f45;
	case 12104ULL: goto x86_l_2f48;
	case 12109ULL: goto x86_l_2f4d;
	case 12111ULL: goto x86_l_2f4f;
	case 12113ULL: goto x86_l_2f51;
	case 12118ULL: goto x86_l_2f56;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2765:
	/* 0x2765: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_276c:
	/* 0x276c: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_276f:
	/* 0x276f: je     1773 <perf_unwind_ruby+0x1773> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6003ULL;
	}
x86_l_2775:
	/* 0x2775: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_277f:
	/* 0x277f: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2784:
	/* 0x2784: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_278e:
	/* 0x278e: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2793:
	/* 0x2793: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_279d:
	/* 0x279d: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_27a2:
	/* 0x27a2: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_27ac:
	/* 0x27ac: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_27b1:
	/* 0x27b1: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_27bb:
	/* 0x27bb: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_27c0:
	/* 0x27c0: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_27ca:
	/* 0x27ca: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27cf:
	/* 0x27cf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27d4:
	/* 0x27d4: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_27d9:
	/* 0x27d9: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_27de:
	/* 0x27de: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27e1:
	/* 0x27e1: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_27e6:
	/* 0x27e6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27e8:
	/* 0x27e8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_27ea:
	/* 0x27ea: jmp    1773 <perf_unwind_ruby+0x1773> */
	return 6003ULL;
x86_l_27ef:
	/* 0x27ef: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_27f9:
	/* 0x27f9: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_27fe:
	/* 0x27fe: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_2808:
	/* 0x2808: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_280d:
	/* 0x280d: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_2817:
	/* 0x2817: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_281c:
	/* 0x281c: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_2826:
	/* 0x2826: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_282b:
	/* 0x282b: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2835:
	/* 0x2835: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_283a:
	/* 0x283a: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2844:
	/* 0x2844: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2849:
	/* 0x2849: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_284e:
	/* 0x284e: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2853:
	/* 0x2853: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2858:
	/* 0x2858: mov    edx,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_285c:
	/* 0x285c: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2861:
	/* 0x2861: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2863:
	/* 0x2863: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2865:
	/* 0x2865: cmp    DWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2869:
	/* 0x2869: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_286f:
	/* 0x286f: jne    e92 <perf_unwind_ruby+0xe92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3730ULL;
	}
x86_l_2875:
	/* 0x2875: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2877:
	/* 0x2877: jmp    2b2 <perf_unwind_ruby+0x2b2> */
	return 690ULL;
x86_l_287c:
	/* 0x287c: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_2883:
	/* 0x2883: jae    2b0f <perf_unwind_ruby+0x2b0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2b0f;
	}
x86_l_2889:
	/* 0x2889: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_288e:
	/* 0x288e: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2891:
	/* 0x2891: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_2897:
	/* 0x2897: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_289c:
	/* 0x289c: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_289f:
	/* 0x289f: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28a4:
	/* 0x28a4: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_28ad:
	/* 0x28ad: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_28b6:
	/* 0x28b6: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_28bb:
	/* 0x28bb: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28be:
	/* 0x28be: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28c3:
	/* 0x28c3: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_28c8:
	/* 0x28c8: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_28ce:
	/* 0x28ce: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_28d3:
	/* 0x28d3: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_28d8:
	/* 0x28d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28dd:
	/* 0x28dd: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_28e0:
	/* 0x28e0: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_28e5:
	/* 0x28e5: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_28ea:
	/* 0x28ea: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28ef:
	/* 0x28ef: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_28f4:
	/* 0x28f4: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_28fa:
	/* 0x28fa: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_28ff:
	/* 0x28ff: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2904:
	/* 0x2904: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2909:
	/* 0x2909: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_290c:
	/* 0x290c: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2912:
	/* 0x2912: je     2be9 <perf_unwind_ruby+0x2be9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2be9;
	}
x86_l_2918:
	/* 0x2918: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_291d:
	/* 0x291d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2920:
	/* 0x2920: je     2be9 <perf_unwind_ruby+0x2be9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2be9;
	}
x86_l_2926:
	/* 0x2926: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_292b:
	/* 0x292b: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_292e:
	/* 0x292e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2933:
	/* 0x2933: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2938:
	/* 0x2938: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_293e:
	/* 0x293e: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_2943:
	/* 0x2943: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2948:
	/* 0x2948: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_294d:
	/* 0x294d: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2950:
	/* 0x2950: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2953:
	/* 0x2953: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_2959:
	/* 0x2959: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_295e:
	/* 0x295e: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2963:
	/* 0x2963: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2968:
	/* 0x2968: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_296d:
	/* 0x296d: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2973:
	/* 0x2973: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_2978:
	/* 0x2978: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_297d:
	/* 0x297d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2982:
	/* 0x2982: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2985:
	/* 0x2985: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2988:
	/* 0x2988: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_298e:
	/* 0x298e: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_2993:
	/* 0x2993: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2998:
	/* 0x2998: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_299d:
	/* 0x299d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_29a2:
	/* 0x29a2: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_29a8:
	/* 0x29a8: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_29ad:
	/* 0x29ad: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_29b2:
	/* 0x29b2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_29b7:
	/* 0x29b7: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_29ba:
	/* 0x29ba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29bd:
	/* 0x29bd: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_29c3:
	/* 0x29c3: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29c8:
	/* 0x29c8: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_29cb:
	/* 0x29cb: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_29d0:
	/* 0x29d0: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_29d5:
	/* 0x29d5: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_29d8:
	/* 0x29d8: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_29dc:
	/* 0x29dc: je     3433 <perf_unwind_ruby+0x3433> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13363ULL;
	}
x86_l_29e2:
	/* 0x29e2: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29e4:
	/* 0x29e4: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_29e7:
	/* 0x29e7: jmp    3437 <perf_unwind_ruby+0x3437> */
	return 13367ULL;
x86_l_29ec:
	/* 0x29ec: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29ee:
	/* 0x29ee: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_29f0:
	/* 0x29f0: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_29f4:
	/* 0x29f4: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_29f7:
	/* 0x29f7: jbe    2a84 <perf_unwind_ruby+0x2a84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2a84;
	}
x86_l_29fd:
	/* 0x29fd: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2a04:
	/* 0x2a04: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a07:
	/* 0x2a07: je     1da5 <perf_unwind_ruby+0x1da5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7589ULL;
	}
x86_l_2a0d:
	/* 0x2a0d: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_2a17:
	/* 0x2a17: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_2a1c:
	/* 0x2a1c: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_2a26:
	/* 0x2a26: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a2b:
	/* 0x2a2b: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_2a35:
	/* 0x2a35: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2a3a:
	/* 0x2a3a: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_2a44:
	/* 0x2a44: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a49:
	/* 0x2a49: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_2a53:
	/* 0x2a53: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a58:
	/* 0x2a58: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_2a62:
	/* 0x2a62: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a67:
	/* 0x2a67: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a6c:
	/* 0x2a6c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2a71:
	/* 0x2a71: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2a76:
	/* 0x2a76: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_2a7b:
	/* 0x2a7b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a7d:
	/* 0x2a7d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2a7f:
	/* 0x2a7f: jmp    1da5 <perf_unwind_ruby+0x1da5> */
	return 7589ULL;
x86_l_2a84:
	/* 0x2a84: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_2a8b:
	/* 0x2a8b: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_2a8f:
	/* 0x2a8f: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_2a95:
	/* 0x2a95: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a9a:
	/* 0x2a9a: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2a9d:
	/* 0x2a9d: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_2aa4:
	/* 0x2aa4: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2aa8:
	/* 0x2aa8: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_2aaf:
	/* 0x2aaf: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ab6:
	/* 0x2ab6: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_2abe:
	/* 0x2abe: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_2ac6:
	/* 0x2ac6: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_2ad1:
	/* 0x2ad1: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ad4:
	/* 0x2ad4: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_2adc:
	/* 0x2adc: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2ae1:
	/* 0x2ae1: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_2aea:
	/* 0x2aea: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_2af1:
	/* 0x2af1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_2af8:
	/* 0x2af8: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2afb:
	/* 0x2afb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b00:
	/* 0x2b00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b02:
	/* 0x2b02: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b05:
	/* 0x2b05: je     2b5f <perf_unwind_ruby+0x2b5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b5f;
	}
x86_l_2b07:
	/* 0x2b07: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2b0a:
	/* 0x2b0a: jmp    1da5 <perf_unwind_ruby+0x1da5> */
	return 7589ULL;
x86_l_2b0f:
	/* 0x2b0f: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b17:
	/* 0x2b17: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_2b1c:
	/* 0x2b1c: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2b21:
	/* 0x2b21: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b24:
	/* 0x2b24: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b29:
	/* 0x2b29: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2b2f:
	/* 0x2b2f: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_2b34:
	/* 0x2b34: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2b39:
	/* 0x2b39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b3e:
	/* 0x2b3e: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2b41:
	/* 0x2b41: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b44:
	/* 0x2b44: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_2b4a:
	/* 0x2b4a: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b4d:
	/* 0x2b4d: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2b4f:
	/* 0x2b4f: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_2b54:
	/* 0x2b54: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_2b5a:
	/* 0x2b5a: jmp    2889 <perf_unwind_ruby+0x2889> */
	goto x86_l_2889;
x86_l_2b5f:
	/* 0x2b5f: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2b66:
	/* 0x2b66: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b69:
	/* 0x2b69: je     1da5 <perf_unwind_ruby+0x1da5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7589ULL;
	}
x86_l_2b6f:
	/* 0x2b6f: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_2b79:
	/* 0x2b79: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2b7e:
	/* 0x2b7e: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_2b88:
	/* 0x2b88: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b8d:
	/* 0x2b8d: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_2b97:
	/* 0x2b97: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b9c:
	/* 0x2b9c: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_2ba6:
	/* 0x2ba6: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bab:
	/* 0x2bab: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2bb5:
	/* 0x2bb5: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2bba:
	/* 0x2bba: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2bc4:
	/* 0x2bc4: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bc9:
	/* 0x2bc9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bce:
	/* 0x2bce: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2bd3:
	/* 0x2bd3: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2bd8:
	/* 0x2bd8: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bdb:
	/* 0x2bdb: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2be0:
	/* 0x2be0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2be2:
	/* 0x2be2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2be4:
	/* 0x2be4: jmp    1da5 <perf_unwind_ruby+0x1da5> */
	return 7589ULL;
x86_l_2be9:
	/* 0x2be9: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_2bf0:
	/* 0x2bf0: jae    2e7c <perf_unwind_ruby+0x2e7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2e7c;
	}
x86_l_2bf6:
	/* 0x2bf6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bfb:
	/* 0x2bfb: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2bfe:
	/* 0x2bfe: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_2c04:
	/* 0x2c04: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_2c09:
	/* 0x2c09: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c0c:
	/* 0x2c0c: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c11:
	/* 0x2c11: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2c1a:
	/* 0x2c1a: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2c23:
	/* 0x2c23: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_2c28:
	/* 0x2c28: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c2b:
	/* 0x2c2b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c30:
	/* 0x2c30: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_2c35:
	/* 0x2c35: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2c3b:
	/* 0x2c3b: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_2c40:
	/* 0x2c40: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2c45:
	/* 0x2c45: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c4a:
	/* 0x2c4a: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2c4d:
	/* 0x2c4d: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_2c52:
	/* 0x2c52: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2c57:
	/* 0x2c57: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c5c:
	/* 0x2c5c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c61:
	/* 0x2c61: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2c67:
	/* 0x2c67: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_2c6c:
	/* 0x2c6c: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2c71:
	/* 0x2c71: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c76:
	/* 0x2c76: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2c79:
	/* 0x2c79: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2c7f:
	/* 0x2c7f: je     2f56 <perf_unwind_ruby+0x2f56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f56;
	}
x86_l_2c85:
	/* 0x2c85: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c8a:
	/* 0x2c8a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c8d:
	/* 0x2c8d: je     2f56 <perf_unwind_ruby+0x2f56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f56;
	}
x86_l_2c93:
	/* 0x2c93: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_2c98:
	/* 0x2c98: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c9b:
	/* 0x2c9b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ca0:
	/* 0x2ca0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ca5:
	/* 0x2ca5: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2cab:
	/* 0x2cab: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_2cb0:
	/* 0x2cb0: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2cb5:
	/* 0x2cb5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cba:
	/* 0x2cba: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2cbd:
	/* 0x2cbd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cc0:
	/* 0x2cc0: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_2cc6:
	/* 0x2cc6: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_2ccb:
	/* 0x2ccb: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2cd0:
	/* 0x2cd0: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2cd5:
	/* 0x2cd5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2cda:
	/* 0x2cda: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2ce0:
	/* 0x2ce0: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_2ce5:
	/* 0x2ce5: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2cea:
	/* 0x2cea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cef:
	/* 0x2cef: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2cf2:
	/* 0x2cf2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cf5:
	/* 0x2cf5: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_2cfb:
	/* 0x2cfb: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_2d00:
	/* 0x2d00: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2d05:
	/* 0x2d05: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2d0a:
	/* 0x2d0a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2d0f:
	/* 0x2d0f: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2d15:
	/* 0x2d15: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_2d1a:
	/* 0x2d1a: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2d1f:
	/* 0x2d1f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d24:
	/* 0x2d24: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2d27:
	/* 0x2d27: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d2a:
	/* 0x2d2a: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_2d30:
	/* 0x2d30: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d35:
	/* 0x2d35: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_2d38:
	/* 0x2d38: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_2d3d:
	/* 0x2d3d: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_2d42:
	/* 0x2d42: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2d45:
	/* 0x2d45: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2d49:
	/* 0x2d49: je     37a0 <perf_unwind_ruby+0x37a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14240ULL;
	}
x86_l_2d4f:
	/* 0x2d4f: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d51:
	/* 0x2d51: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_2d54:
	/* 0x2d54: jmp    37a4 <perf_unwind_ruby+0x37a4> */
	return 14244ULL;
x86_l_2d59:
	/* 0x2d59: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d5b:
	/* 0x2d5b: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_2d5d:
	/* 0x2d5d: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2d61:
	/* 0x2d61: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_2d64:
	/* 0x2d64: jbe    2df1 <perf_unwind_ruby+0x2df1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2df1;
	}
x86_l_2d6a:
	/* 0x2d6a: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2d71:
	/* 0x2d71: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d74:
	/* 0x2d74: je     2423 <perf_unwind_ruby+0x2423> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9251ULL;
	}
x86_l_2d7a:
	/* 0x2d7a: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_2d84:
	/* 0x2d84: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_2d89:
	/* 0x2d89: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_2d93:
	/* 0x2d93: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2d98:
	/* 0x2d98: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_2da2:
	/* 0x2da2: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2da7:
	/* 0x2da7: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_2db1:
	/* 0x2db1: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2db6:
	/* 0x2db6: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_2dc0:
	/* 0x2dc0: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2dc5:
	/* 0x2dc5: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_2dcf:
	/* 0x2dcf: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2dd4:
	/* 0x2dd4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2dd9:
	/* 0x2dd9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2dde:
	/* 0x2dde: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2de3:
	/* 0x2de3: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_2de8:
	/* 0x2de8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2dea:
	/* 0x2dea: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2dec:
	/* 0x2dec: jmp    2423 <perf_unwind_ruby+0x2423> */
	return 9251ULL;
x86_l_2df1:
	/* 0x2df1: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_2df8:
	/* 0x2df8: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_2dfc:
	/* 0x2dfc: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_2e02:
	/* 0x2e02: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e07:
	/* 0x2e07: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2e0a:
	/* 0x2e0a: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_2e11:
	/* 0x2e11: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2e15:
	/* 0x2e15: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_2e1c:
	/* 0x2e1c: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e23:
	/* 0x2e23: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_2e2b:
	/* 0x2e2b: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_2e33:
	/* 0x2e33: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_2e3e:
	/* 0x2e3e: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e41:
	/* 0x2e41: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_2e49:
	/* 0x2e49: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2e4e:
	/* 0x2e4e: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_2e57:
	/* 0x2e57: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_2e5e:
	/* 0x2e5e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_2e65:
	/* 0x2e65: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2e68:
	/* 0x2e68: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e6d:
	/* 0x2e6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e6f:
	/* 0x2e6f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e72:
	/* 0x2e72: je     2ecc <perf_unwind_ruby+0x2ecc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ecc;
	}
x86_l_2e74:
	/* 0x2e74: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2e77:
	/* 0x2e77: jmp    2423 <perf_unwind_ruby+0x2423> */
	return 9251ULL;
x86_l_2e7c:
	/* 0x2e7c: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e84:
	/* 0x2e84: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_2e89:
	/* 0x2e89: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2e8e:
	/* 0x2e8e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e91:
	/* 0x2e91: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e96:
	/* 0x2e96: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2e9c:
	/* 0x2e9c: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_2ea1:
	/* 0x2ea1: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2ea6:
	/* 0x2ea6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2eab:
	/* 0x2eab: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2eae:
	/* 0x2eae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2eb1:
	/* 0x2eb1: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_2eb7:
	/* 0x2eb7: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2eba:
	/* 0x2eba: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2ebc:
	/* 0x2ebc: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_2ec1:
	/* 0x2ec1: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_2ec7:
	/* 0x2ec7: jmp    2bf6 <perf_unwind_ruby+0x2bf6> */
	goto x86_l_2bf6;
x86_l_2ecc:
	/* 0x2ecc: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2ed3:
	/* 0x2ed3: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ed6:
	/* 0x2ed6: je     2423 <perf_unwind_ruby+0x2423> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9251ULL;
	}
x86_l_2edc:
	/* 0x2edc: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_2ee6:
	/* 0x2ee6: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2eeb:
	/* 0x2eeb: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_2ef5:
	/* 0x2ef5: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2efa:
	/* 0x2efa: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_2f04:
	/* 0x2f04: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2f09:
	/* 0x2f09: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_2f13:
	/* 0x2f13: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f18:
	/* 0x2f18: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2f22:
	/* 0x2f22: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f27:
	/* 0x2f27: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2f31:
	/* 0x2f31: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f36:
	/* 0x2f36: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f3b:
	/* 0x2f3b: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2f40:
	/* 0x2f40: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2f45:
	/* 0x2f45: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f48:
	/* 0x2f48: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2f4d:
	/* 0x2f4d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f4f:
	/* 0x2f4f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2f51:
	/* 0x2f51: jmp    2423 <perf_unwind_ruby+0x2423> */
	return 9251ULL;
x86_l_2f56:
	/* 0x2f56: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
	return 12125ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12125ULL: goto x86_l_2f5d;
	case 12131ULL: goto x86_l_2f63;
	case 12136ULL: goto x86_l_2f68;
	case 12139ULL: goto x86_l_2f6b;
	case 12145ULL: goto x86_l_2f71;
	case 12150ULL: goto x86_l_2f76;
	case 12153ULL: goto x86_l_2f79;
	case 12158ULL: goto x86_l_2f7e;
	case 12167ULL: goto x86_l_2f87;
	case 12176ULL: goto x86_l_2f90;
	case 12181ULL: goto x86_l_2f95;
	case 12184ULL: goto x86_l_2f98;
	case 12189ULL: goto x86_l_2f9d;
	case 12194ULL: goto x86_l_2fa2;
	case 12200ULL: goto x86_l_2fa8;
	case 12205ULL: goto x86_l_2fad;
	case 12210ULL: goto x86_l_2fb2;
	case 12215ULL: goto x86_l_2fb7;
	case 12218ULL: goto x86_l_2fba;
	case 12223ULL: goto x86_l_2fbf;
	case 12228ULL: goto x86_l_2fc4;
	case 12233ULL: goto x86_l_2fc9;
	case 12238ULL: goto x86_l_2fce;
	case 12244ULL: goto x86_l_2fd4;
	case 12249ULL: goto x86_l_2fd9;
	case 12254ULL: goto x86_l_2fde;
	case 12259ULL: goto x86_l_2fe3;
	case 12262ULL: goto x86_l_2fe6;
	case 12268ULL: goto x86_l_2fec;
	case 12274ULL: goto x86_l_2ff2;
	case 12279ULL: goto x86_l_2ff7;
	case 12282ULL: goto x86_l_2ffa;
	case 12288ULL: goto x86_l_3000;
	case 12293ULL: goto x86_l_3005;
	case 12296ULL: goto x86_l_3008;
	case 12301ULL: goto x86_l_300d;
	case 12306ULL: goto x86_l_3012;
	case 12312ULL: goto x86_l_3018;
	case 12317ULL: goto x86_l_301d;
	case 12322ULL: goto x86_l_3022;
	case 12327ULL: goto x86_l_3027;
	case 12330ULL: goto x86_l_302a;
	case 12333ULL: goto x86_l_302d;
	case 12339ULL: goto x86_l_3033;
	case 12344ULL: goto x86_l_3038;
	case 12349ULL: goto x86_l_303d;
	case 12354ULL: goto x86_l_3042;
	case 12359ULL: goto x86_l_3047;
	case 12365ULL: goto x86_l_304d;
	case 12370ULL: goto x86_l_3052;
	case 12375ULL: goto x86_l_3057;
	case 12380ULL: goto x86_l_305c;
	case 12383ULL: goto x86_l_305f;
	case 12386ULL: goto x86_l_3062;
	case 12392ULL: goto x86_l_3068;
	case 12397ULL: goto x86_l_306d;
	case 12402ULL: goto x86_l_3072;
	case 12407ULL: goto x86_l_3077;
	case 12412ULL: goto x86_l_307c;
	case 12418ULL: goto x86_l_3082;
	case 12423ULL: goto x86_l_3087;
	case 12428ULL: goto x86_l_308c;
	case 12433ULL: goto x86_l_3091;
	case 12436ULL: goto x86_l_3094;
	case 12439ULL: goto x86_l_3097;
	case 12445ULL: goto x86_l_309d;
	case 12450ULL: goto x86_l_30a2;
	case 12453ULL: goto x86_l_30a5;
	case 12458ULL: goto x86_l_30aa;
	case 12463ULL: goto x86_l_30af;
	case 12466ULL: goto x86_l_30b2;
	case 12470ULL: goto x86_l_30b6;
	case 12476ULL: goto x86_l_30bc;
	case 12478ULL: goto x86_l_30be;
	case 12481ULL: goto x86_l_30c1;
	case 12486ULL: goto x86_l_30c6;
	case 12488ULL: goto x86_l_30c8;
	case 12490ULL: goto x86_l_30ca;
	case 12494ULL: goto x86_l_30ce;
	case 12497ULL: goto x86_l_30d1;
	case 12503ULL: goto x86_l_30d7;
	case 12510ULL: goto x86_l_30de;
	case 12513ULL: goto x86_l_30e1;
	case 12519ULL: goto x86_l_30e7;
	case 12529ULL: goto x86_l_30f1;
	case 12534ULL: goto x86_l_30f6;
	case 12544ULL: goto x86_l_3100;
	case 12549ULL: goto x86_l_3105;
	case 12559ULL: goto x86_l_310f;
	case 12564ULL: goto x86_l_3114;
	case 12574ULL: goto x86_l_311e;
	case 12579ULL: goto x86_l_3123;
	case 12589ULL: goto x86_l_312d;
	case 12594ULL: goto x86_l_3132;
	case 12604ULL: goto x86_l_313c;
	case 12609ULL: goto x86_l_3141;
	case 12614ULL: goto x86_l_3146;
	case 12619ULL: goto x86_l_314b;
	case 12624ULL: goto x86_l_3150;
	case 12629ULL: goto x86_l_3155;
	case 12631ULL: goto x86_l_3157;
	case 12633ULL: goto x86_l_3159;
	case 12638ULL: goto x86_l_315e;
	case 12645ULL: goto x86_l_3165;
	case 12649ULL: goto x86_l_3169;
	case 12655ULL: goto x86_l_316f;
	case 12660ULL: goto x86_l_3174;
	case 12663ULL: goto x86_l_3177;
	case 12670ULL: goto x86_l_317e;
	case 12674ULL: goto x86_l_3182;
	case 12681ULL: goto x86_l_3189;
	case 12688ULL: goto x86_l_3190;
	case 12696ULL: goto x86_l_3198;
	case 12704ULL: goto x86_l_31a0;
	case 12715ULL: goto x86_l_31ab;
	case 12718ULL: goto x86_l_31ae;
	case 12726ULL: goto x86_l_31b6;
	case 12731ULL: goto x86_l_31bb;
	case 12740ULL: goto x86_l_31c4;
	case 12747ULL: goto x86_l_31cb;
	case 12754ULL: goto x86_l_31d2;
	case 12757ULL: goto x86_l_31d5;
	case 12762ULL: goto x86_l_31da;
	case 12764ULL: goto x86_l_31dc;
	case 12767ULL: goto x86_l_31df;
	case 12769ULL: goto x86_l_31e1;
	case 12772ULL: goto x86_l_31e4;
	case 12777ULL: goto x86_l_31e9;
	case 12785ULL: goto x86_l_31f1;
	case 12790ULL: goto x86_l_31f6;
	case 12795ULL: goto x86_l_31fb;
	case 12798ULL: goto x86_l_31fe;
	case 12803ULL: goto x86_l_3203;
	case 12809ULL: goto x86_l_3209;
	case 12814ULL: goto x86_l_320e;
	case 12819ULL: goto x86_l_3213;
	case 12824ULL: goto x86_l_3218;
	case 12827ULL: goto x86_l_321b;
	case 12830ULL: goto x86_l_321e;
	case 12836ULL: goto x86_l_3224;
	case 12839ULL: goto x86_l_3227;
	case 12841ULL: goto x86_l_3229;
	case 12846ULL: goto x86_l_322e;
	case 12852ULL: goto x86_l_3234;
	case 12857ULL: goto x86_l_3239;
	case 12864ULL: goto x86_l_3240;
	case 12867ULL: goto x86_l_3243;
	case 12873ULL: goto x86_l_3249;
	case 12883ULL: goto x86_l_3253;
	case 12888ULL: goto x86_l_3258;
	case 12898ULL: goto x86_l_3262;
	case 12903ULL: goto x86_l_3267;
	case 12913ULL: goto x86_l_3271;
	case 12918ULL: goto x86_l_3276;
	case 12928ULL: goto x86_l_3280;
	case 12933ULL: goto x86_l_3285;
	case 12943ULL: goto x86_l_328f;
	case 12948ULL: goto x86_l_3294;
	case 12958ULL: goto x86_l_329e;
	case 12963ULL: goto x86_l_32a3;
	case 12968ULL: goto x86_l_32a8;
	case 12973ULL: goto x86_l_32ad;
	case 12978ULL: goto x86_l_32b2;
	case 12981ULL: goto x86_l_32b5;
	case 12986ULL: goto x86_l_32ba;
	case 12988ULL: goto x86_l_32bc;
	case 12990ULL: goto x86_l_32be;
	case 12995ULL: goto x86_l_32c3;
	case 13002ULL: goto x86_l_32ca;
	case 13008ULL: goto x86_l_32d0;
	case 13013ULL: goto x86_l_32d5;
	case 13016ULL: goto x86_l_32d8;
	case 13022ULL: goto x86_l_32de;
	case 13027ULL: goto x86_l_32e3;
	case 13030ULL: goto x86_l_32e6;
	case 13035ULL: goto x86_l_32eb;
	case 13044ULL: goto x86_l_32f4;
	case 13053ULL: goto x86_l_32fd;
	case 13058ULL: goto x86_l_3302;
	case 13061ULL: goto x86_l_3305;
	case 13066ULL: goto x86_l_330a;
	case 13071ULL: goto x86_l_330f;
	case 13077ULL: goto x86_l_3315;
	case 13082ULL: goto x86_l_331a;
	case 13087ULL: goto x86_l_331f;
	case 13092ULL: goto x86_l_3324;
	case 13095ULL: goto x86_l_3327;
	case 13100ULL: goto x86_l_332c;
	case 13105ULL: goto x86_l_3331;
	case 13110ULL: goto x86_l_3336;
	case 13115ULL: goto x86_l_333b;
	case 13121ULL: goto x86_l_3341;
	case 13126ULL: goto x86_l_3346;
	case 13131ULL: goto x86_l_334b;
	case 13136ULL: goto x86_l_3350;
	case 13139ULL: goto x86_l_3353;
	case 13145ULL: goto x86_l_3359;
	case 13151ULL: goto x86_l_335f;
	case 13156ULL: goto x86_l_3364;
	case 13159ULL: goto x86_l_3367;
	case 13165ULL: goto x86_l_336d;
	case 13170ULL: goto x86_l_3372;
	case 13173ULL: goto x86_l_3375;
	case 13178ULL: goto x86_l_337a;
	case 13183ULL: goto x86_l_337f;
	case 13189ULL: goto x86_l_3385;
	case 13194ULL: goto x86_l_338a;
	case 13199ULL: goto x86_l_338f;
	case 13204ULL: goto x86_l_3394;
	case 13207ULL: goto x86_l_3397;
	case 13210ULL: goto x86_l_339a;
	case 13216ULL: goto x86_l_33a0;
	case 13221ULL: goto x86_l_33a5;
	case 13226ULL: goto x86_l_33aa;
	case 13231ULL: goto x86_l_33af;
	case 13236ULL: goto x86_l_33b4;
	case 13242ULL: goto x86_l_33ba;
	case 13247ULL: goto x86_l_33bf;
	case 13252ULL: goto x86_l_33c4;
	case 13257ULL: goto x86_l_33c9;
	case 13260ULL: goto x86_l_33cc;
	case 13263ULL: goto x86_l_33cf;
	case 13269ULL: goto x86_l_33d5;
	case 13274ULL: goto x86_l_33da;
	case 13279ULL: goto x86_l_33df;
	case 13284ULL: goto x86_l_33e4;
	case 13289ULL: goto x86_l_33e9;
	case 13295ULL: goto x86_l_33ef;
	case 13300ULL: goto x86_l_33f4;
	case 13305ULL: goto x86_l_33f9;
	case 13310ULL: goto x86_l_33fe;
	case 13313ULL: goto x86_l_3401;
	case 13316ULL: goto x86_l_3404;
	case 13322ULL: goto x86_l_340a;
	case 13327ULL: goto x86_l_340f;
	case 13330ULL: goto x86_l_3412;
	case 13335ULL: goto x86_l_3417;
	case 13340ULL: goto x86_l_341c;
	case 13343ULL: goto x86_l_341f;
	case 13347ULL: goto x86_l_3423;
	case 13353ULL: goto x86_l_3429;
	case 13355ULL: goto x86_l_342b;
	case 13358ULL: goto x86_l_342e;
	case 13363ULL: goto x86_l_3433;
	case 13365ULL: goto x86_l_3435;
	case 13367ULL: goto x86_l_3437;
	case 13371ULL: goto x86_l_343b;
	case 13374ULL: goto x86_l_343e;
	case 13380ULL: goto x86_l_3444;
	case 13387ULL: goto x86_l_344b;
	case 13390ULL: goto x86_l_344e;
	case 13396ULL: goto x86_l_3454;
	case 13406ULL: goto x86_l_345e;
	case 13411ULL: goto x86_l_3463;
	case 13421ULL: goto x86_l_346d;
	case 13426ULL: goto x86_l_3472;
	case 13436ULL: goto x86_l_347c;
	case 13441ULL: goto x86_l_3481;
	case 13451ULL: goto x86_l_348b;
	case 13456ULL: goto x86_l_3490;
	case 13466ULL: goto x86_l_349a;
	case 13471ULL: goto x86_l_349f;
	case 13481ULL: goto x86_l_34a9;
	case 13486ULL: goto x86_l_34ae;
	case 13491ULL: goto x86_l_34b3;
	case 13496ULL: goto x86_l_34b8;
	case 13501ULL: goto x86_l_34bd;
	case 13506ULL: goto x86_l_34c2;
	case 13508ULL: goto x86_l_34c4;
	case 13510ULL: goto x86_l_34c6;
	case 13515ULL: goto x86_l_34cb;
	case 13522ULL: goto x86_l_34d2;
	case 13526ULL: goto x86_l_34d6;
	case 13532ULL: goto x86_l_34dc;
	case 13537ULL: goto x86_l_34e1;
	case 13540ULL: goto x86_l_34e4;
	case 13547ULL: goto x86_l_34eb;
	case 13551ULL: goto x86_l_34ef;
	case 13558ULL: goto x86_l_34f6;
	case 13565ULL: goto x86_l_34fd;
	case 13573ULL: goto x86_l_3505;
	case 13581ULL: goto x86_l_350d;
	case 13592ULL: goto x86_l_3518;
	case 13595ULL: goto x86_l_351b;
	case 13603ULL: goto x86_l_3523;
	case 13608ULL: goto x86_l_3528;
	case 13617ULL: goto x86_l_3531;
	case 13624ULL: goto x86_l_3538;
	case 13631ULL: goto x86_l_353f;
	case 13634ULL: goto x86_l_3542;
	case 13639ULL: goto x86_l_3547;
	case 13641ULL: goto x86_l_3549;
	case 13644ULL: goto x86_l_354c;
	case 13646ULL: goto x86_l_354e;
	case 13649ULL: goto x86_l_3551;
	case 13654ULL: goto x86_l_3556;
	case 13662ULL: goto x86_l_355e;
	case 13667ULL: goto x86_l_3563;
	case 13672ULL: goto x86_l_3568;
	case 13675ULL: goto x86_l_356b;
	case 13680ULL: goto x86_l_3570;
	case 13686ULL: goto x86_l_3576;
	case 13691ULL: goto x86_l_357b;
	case 13696ULL: goto x86_l_3580;
	case 13701ULL: goto x86_l_3585;
	case 13704ULL: goto x86_l_3588;
	case 13707ULL: goto x86_l_358b;
	case 13713ULL: goto x86_l_3591;
	case 13716ULL: goto x86_l_3594;
	case 13718ULL: goto x86_l_3596;
	case 13723ULL: goto x86_l_359b;
	case 13729ULL: goto x86_l_35a1;
	case 13734ULL: goto x86_l_35a6;
	case 13741ULL: goto x86_l_35ad;
	case 13744ULL: goto x86_l_35b0;
	case 13750ULL: goto x86_l_35b6;
	case 13760ULL: goto x86_l_35c0;
	case 13765ULL: goto x86_l_35c5;
	case 13775ULL: goto x86_l_35cf;
	case 13780ULL: goto x86_l_35d4;
	case 13790ULL: goto x86_l_35de;
	case 13795ULL: goto x86_l_35e3;
	case 13805ULL: goto x86_l_35ed;
	case 13810ULL: goto x86_l_35f2;
	case 13820ULL: goto x86_l_35fc;
	case 13825ULL: goto x86_l_3601;
	case 13835ULL: goto x86_l_360b;
	case 13840ULL: goto x86_l_3610;
	case 13845ULL: goto x86_l_3615;
	case 13850ULL: goto x86_l_361a;
	case 13855ULL: goto x86_l_361f;
	case 13858ULL: goto x86_l_3622;
	case 13863ULL: goto x86_l_3627;
	case 13865ULL: goto x86_l_3629;
	case 13867ULL: goto x86_l_362b;
	case 13872ULL: goto x86_l_3630;
	case 13879ULL: goto x86_l_3637;
	case 13885ULL: goto x86_l_363d;
	case 13890ULL: goto x86_l_3642;
	case 13893ULL: goto x86_l_3645;
	case 13899ULL: goto x86_l_364b;
	case 13904ULL: goto x86_l_3650;
	case 13907ULL: goto x86_l_3653;
	case 13912ULL: goto x86_l_3658;
	case 13921ULL: goto x86_l_3661;
	case 13930ULL: goto x86_l_366a;
	case 13935ULL: goto x86_l_366f;
	case 13938ULL: goto x86_l_3672;
	case 13943ULL: goto x86_l_3677;
	case 13948ULL: goto x86_l_367c;
	case 13954ULL: goto x86_l_3682;
	case 13959ULL: goto x86_l_3687;
	case 13964ULL: goto x86_l_368c;
	case 13969ULL: goto x86_l_3691;
	case 13972ULL: goto x86_l_3694;
	case 13977ULL: goto x86_l_3699;
	case 13982ULL: goto x86_l_369e;
	case 13987ULL: goto x86_l_36a3;
	case 13992ULL: goto x86_l_36a8;
	case 13998ULL: goto x86_l_36ae;
	case 14003ULL: goto x86_l_36b3;
	case 14008ULL: goto x86_l_36b8;
	case 14013ULL: goto x86_l_36bd;
	case 14016ULL: goto x86_l_36c0;
	case 14022ULL: goto x86_l_36c6;
	case 14028ULL: goto x86_l_36cc;
	case 14033ULL: goto x86_l_36d1;
	case 14036ULL: goto x86_l_36d4;
	case 14042ULL: goto x86_l_36da;
	case 14047ULL: goto x86_l_36df;
	case 14050ULL: goto x86_l_36e2;
	case 14055ULL: goto x86_l_36e7;
	case 14060ULL: goto x86_l_36ec;
	case 14066ULL: goto x86_l_36f2;
	case 14071ULL: goto x86_l_36f7;
	case 14076ULL: goto x86_l_36fc;
	case 14081ULL: goto x86_l_3701;
	case 14084ULL: goto x86_l_3704;
	case 14087ULL: goto x86_l_3707;
	case 14093ULL: goto x86_l_370d;
	case 14098ULL: goto x86_l_3712;
	case 14103ULL: goto x86_l_3717;
	case 14108ULL: goto x86_l_371c;
	case 14113ULL: goto x86_l_3721;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2f5d:
	/* 0x2f5d: jae    31e9 <perf_unwind_ruby+0x31e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_31e9;
	}
x86_l_2f63:
	/* 0x2f63: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f68:
	/* 0x2f68: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2f6b:
	/* 0x2f6b: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_2f71:
	/* 0x2f71: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_2f76:
	/* 0x2f76: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f79:
	/* 0x2f79: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f7e:
	/* 0x2f7e: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2f87:
	/* 0x2f87: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2f90:
	/* 0x2f90: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_2f95:
	/* 0x2f95: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f98:
	/* 0x2f98: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f9d:
	/* 0x2f9d: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_2fa2:
	/* 0x2fa2: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2fa8:
	/* 0x2fa8: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_2fad:
	/* 0x2fad: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2fb2:
	/* 0x2fb2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fb7:
	/* 0x2fb7: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2fba:
	/* 0x2fba: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_2fbf:
	/* 0x2fbf: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2fc4:
	/* 0x2fc4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fc9:
	/* 0x2fc9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2fce:
	/* 0x2fce: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_2fd4:
	/* 0x2fd4: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_2fd9:
	/* 0x2fd9: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2fde:
	/* 0x2fde: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fe3:
	/* 0x2fe3: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2fe6:
	/* 0x2fe6: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2fec:
	/* 0x2fec: je     32c3 <perf_unwind_ruby+0x32c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32c3;
	}
x86_l_2ff2:
	/* 0x2ff2: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ff7:
	/* 0x2ff7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ffa:
	/* 0x2ffa: je     32c3 <perf_unwind_ruby+0x32c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32c3;
	}
x86_l_3000:
	/* 0x3000: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_3005:
	/* 0x3005: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3008:
	/* 0x3008: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_300d:
	/* 0x300d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3012:
	/* 0x3012: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3018:
	/* 0x3018: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_301d:
	/* 0x301d: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_3022:
	/* 0x3022: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3027:
	/* 0x3027: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_302a:
	/* 0x302a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_302d:
	/* 0x302d: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_3033:
	/* 0x3033: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_3038:
	/* 0x3038: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_303d:
	/* 0x303d: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3042:
	/* 0x3042: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3047:
	/* 0x3047: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_304d:
	/* 0x304d: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_3052:
	/* 0x3052: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3057:
	/* 0x3057: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_305c:
	/* 0x305c: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_305f:
	/* 0x305f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3062:
	/* 0x3062: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_3068:
	/* 0x3068: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_306d:
	/* 0x306d: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3072:
	/* 0x3072: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3077:
	/* 0x3077: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_307c:
	/* 0x307c: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3082:
	/* 0x3082: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_3087:
	/* 0x3087: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_308c:
	/* 0x308c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3091:
	/* 0x3091: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3094:
	/* 0x3094: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3097:
	/* 0x3097: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_309d:
	/* 0x309d: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30a2:
	/* 0x30a2: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_30a5:
	/* 0x30a5: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_30aa:
	/* 0x30aa: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_30af:
	/* 0x30af: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_30b2:
	/* 0x30b2: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_30b6:
	/* 0x30b6: je     3b0d <perf_unwind_ruby+0x3b0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15117ULL;
	}
x86_l_30bc:
	/* 0x30bc: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30be:
	/* 0x30be: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_30c1:
	/* 0x30c1: jmp    3b11 <perf_unwind_ruby+0x3b11> */
	return 15121ULL;
x86_l_30c6:
	/* 0x30c6: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30c8:
	/* 0x30c8: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_30ca:
	/* 0x30ca: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_30ce:
	/* 0x30ce: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_30d1:
	/* 0x30d1: jbe    315e <perf_unwind_ruby+0x315e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_315e;
	}
x86_l_30d7:
	/* 0x30d7: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_30de:
	/* 0x30de: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30e1:
	/* 0x30e1: je     2889 <perf_unwind_ruby+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10377ULL;
	}
x86_l_30e7:
	/* 0x30e7: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_30f1:
	/* 0x30f1: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_30f6:
	/* 0x30f6: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_3100:
	/* 0x3100: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3105:
	/* 0x3105: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_310f:
	/* 0x310f: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3114:
	/* 0x3114: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_311e:
	/* 0x311e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3123:
	/* 0x3123: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_312d:
	/* 0x312d: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3132:
	/* 0x3132: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_313c:
	/* 0x313c: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3141:
	/* 0x3141: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3146:
	/* 0x3146: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_314b:
	/* 0x314b: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3150:
	/* 0x3150: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_3155:
	/* 0x3155: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3157:
	/* 0x3157: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3159:
	/* 0x3159: jmp    2889 <perf_unwind_ruby+0x2889> */
	return 10377ULL;
x86_l_315e:
	/* 0x315e: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3165:
	/* 0x3165: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_3169:
	/* 0x3169: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_316f:
	/* 0x316f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3174:
	/* 0x3174: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3177:
	/* 0x3177: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_317e:
	/* 0x317e: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_3182:
	/* 0x3182: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3189:
	/* 0x3189: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3190:
	/* 0x3190: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_3198:
	/* 0x3198: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_31a0:
	/* 0x31a0: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_31ab:
	/* 0x31ab: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31ae:
	/* 0x31ae: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_31b6:
	/* 0x31b6: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_31bb:
	/* 0x31bb: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_31c4:
	/* 0x31c4: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_31cb:
	/* 0x31cb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_31d2:
	/* 0x31d2: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_31d5:
	/* 0x31d5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31da:
	/* 0x31da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31dc:
	/* 0x31dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31df:
	/* 0x31df: je     3239 <perf_unwind_ruby+0x3239> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3239;
	}
x86_l_31e1:
	/* 0x31e1: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_31e4:
	/* 0x31e4: jmp    2889 <perf_unwind_ruby+0x2889> */
	return 10377ULL;
x86_l_31e9:
	/* 0x31e9: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31f1:
	/* 0x31f1: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_31f6:
	/* 0x31f6: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_31fb:
	/* 0x31fb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_31fe:
	/* 0x31fe: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3203:
	/* 0x3203: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3209:
	/* 0x3209: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_320e:
	/* 0x320e: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3213:
	/* 0x3213: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3218:
	/* 0x3218: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_321b:
	/* 0x321b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_321e:
	/* 0x321e: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_3224:
	/* 0x3224: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3227:
	/* 0x3227: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_3229:
	/* 0x3229: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_322e:
	/* 0x322e: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_3234:
	/* 0x3234: jmp    2f63 <perf_unwind_ruby+0x2f63> */
	goto x86_l_2f63;
x86_l_3239:
	/* 0x3239: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3240:
	/* 0x3240: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3243:
	/* 0x3243: je     2889 <perf_unwind_ruby+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10377ULL;
	}
x86_l_3249:
	/* 0x3249: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_3253:
	/* 0x3253: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_3258:
	/* 0x3258: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_3262:
	/* 0x3262: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3267:
	/* 0x3267: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_3271:
	/* 0x3271: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3276:
	/* 0x3276: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_3280:
	/* 0x3280: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3285:
	/* 0x3285: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_328f:
	/* 0x328f: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3294:
	/* 0x3294: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_329e:
	/* 0x329e: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32a3:
	/* 0x32a3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32a8:
	/* 0x32a8: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_32ad:
	/* 0x32ad: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_32b2:
	/* 0x32b2: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32b5:
	/* 0x32b5: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_32ba:
	/* 0x32ba: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32bc:
	/* 0x32bc: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_32be:
	/* 0x32be: jmp    2889 <perf_unwind_ruby+0x2889> */
	return 10377ULL;
x86_l_32c3:
	/* 0x32c3: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_32ca:
	/* 0x32ca: jae    3556 <perf_unwind_ruby+0x3556> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3556;
	}
x86_l_32d0:
	/* 0x32d0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32d5:
	/* 0x32d5: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_32d8:
	/* 0x32d8: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_32de:
	/* 0x32de: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_32e3:
	/* 0x32e3: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_32e6:
	/* 0x32e6: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32eb:
	/* 0x32eb: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_32f4:
	/* 0x32f4: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_32fd:
	/* 0x32fd: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_3302:
	/* 0x3302: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3305:
	/* 0x3305: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_330a:
	/* 0x330a: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_330f:
	/* 0x330f: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3315:
	/* 0x3315: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_331a:
	/* 0x331a: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_331f:
	/* 0x331f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3324:
	/* 0x3324: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3327:
	/* 0x3327: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_332c:
	/* 0x332c: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3331:
	/* 0x3331: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3336:
	/* 0x3336: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_333b:
	/* 0x333b: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3341:
	/* 0x3341: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_3346:
	/* 0x3346: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_334b:
	/* 0x334b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3350:
	/* 0x3350: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3353:
	/* 0x3353: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3359:
	/* 0x3359: je     3630 <perf_unwind_ruby+0x3630> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3630;
	}
x86_l_335f:
	/* 0x335f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3364:
	/* 0x3364: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3367:
	/* 0x3367: je     3630 <perf_unwind_ruby+0x3630> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3630;
	}
x86_l_336d:
	/* 0x336d: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_3372:
	/* 0x3372: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3375:
	/* 0x3375: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_337a:
	/* 0x337a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_337f:
	/* 0x337f: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3385:
	/* 0x3385: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_338a:
	/* 0x338a: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_338f:
	/* 0x338f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3394:
	/* 0x3394: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3397:
	/* 0x3397: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_339a:
	/* 0x339a: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_33a0:
	/* 0x33a0: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_33a5:
	/* 0x33a5: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_33aa:
	/* 0x33aa: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_33af:
	/* 0x33af: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_33b4:
	/* 0x33b4: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_33ba:
	/* 0x33ba: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_33bf:
	/* 0x33bf: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_33c4:
	/* 0x33c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33c9:
	/* 0x33c9: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_33cc:
	/* 0x33cc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33cf:
	/* 0x33cf: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_33d5:
	/* 0x33d5: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_33da:
	/* 0x33da: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_33df:
	/* 0x33df: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_33e4:
	/* 0x33e4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_33e9:
	/* 0x33e9: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_33ef:
	/* 0x33ef: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_33f4:
	/* 0x33f4: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_33f9:
	/* 0x33f9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_33fe:
	/* 0x33fe: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3401:
	/* 0x3401: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3404:
	/* 0x3404: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_340a:
	/* 0x340a: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_340f:
	/* 0x340f: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_3412:
	/* 0x3412: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_3417:
	/* 0x3417: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_341c:
	/* 0x341c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_341f:
	/* 0x341f: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_3423:
	/* 0x3423: je     3e7a <perf_unwind_ruby+0x3e7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15994ULL;
	}
x86_l_3429:
	/* 0x3429: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_342b:
	/* 0x342b: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_342e:
	/* 0x342e: jmp    3e7e <perf_unwind_ruby+0x3e7e> */
	return 15998ULL;
x86_l_3433:
	/* 0x3433: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3435:
	/* 0x3435: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_3437:
	/* 0x3437: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_343b:
	/* 0x343b: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_343e:
	/* 0x343e: jbe    34cb <perf_unwind_ruby+0x34cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_34cb;
	}
x86_l_3444:
	/* 0x3444: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_344b:
	/* 0x344b: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_344e:
	/* 0x344e: je     2bf6 <perf_unwind_ruby+0x2bf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11254ULL;
	}
x86_l_3454:
	/* 0x3454: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_345e:
	/* 0x345e: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_3463:
	/* 0x3463: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_346d:
	/* 0x346d: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3472:
	/* 0x3472: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_347c:
	/* 0x347c: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3481:
	/* 0x3481: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_348b:
	/* 0x348b: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3490:
	/* 0x3490: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_349a:
	/* 0x349a: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_349f:
	/* 0x349f: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_34a9:
	/* 0x34a9: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_34ae:
	/* 0x34ae: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_34b3:
	/* 0x34b3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_34b8:
	/* 0x34b8: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_34bd:
	/* 0x34bd: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_34c2:
	/* 0x34c2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34c4:
	/* 0x34c4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_34c6:
	/* 0x34c6: jmp    2bf6 <perf_unwind_ruby+0x2bf6> */
	return 11254ULL;
x86_l_34cb:
	/* 0x34cb: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_34d2:
	/* 0x34d2: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_34d6:
	/* 0x34d6: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_34dc:
	/* 0x34dc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34e1:
	/* 0x34e1: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_34e4:
	/* 0x34e4: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_34eb:
	/* 0x34eb: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_34ef:
	/* 0x34ef: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_34f6:
	/* 0x34f6: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34fd:
	/* 0x34fd: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_3505:
	/* 0x3505: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_350d:
	/* 0x350d: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_3518:
	/* 0x3518: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_351b:
	/* 0x351b: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_3523:
	/* 0x3523: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3528:
	/* 0x3528: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_3531:
	/* 0x3531: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_3538:
	/* 0x3538: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_353f:
	/* 0x353f: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_3542:
	/* 0x3542: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3547:
	/* 0x3547: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3549:
	/* 0x3549: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_354c:
	/* 0x354c: je     35a6 <perf_unwind_ruby+0x35a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35a6;
	}
x86_l_354e:
	/* 0x354e: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3551:
	/* 0x3551: jmp    2bf6 <perf_unwind_ruby+0x2bf6> */
	return 11254ULL;
x86_l_3556:
	/* 0x3556: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_355e:
	/* 0x355e: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_3563:
	/* 0x3563: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3568:
	/* 0x3568: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_356b:
	/* 0x356b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3570:
	/* 0x3570: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3576:
	/* 0x3576: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_357b:
	/* 0x357b: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3580:
	/* 0x3580: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3585:
	/* 0x3585: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3588:
	/* 0x3588: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_358b:
	/* 0x358b: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_3591:
	/* 0x3591: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3594:
	/* 0x3594: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_3596:
	/* 0x3596: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_359b:
	/* 0x359b: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_35a1:
	/* 0x35a1: jmp    32d0 <perf_unwind_ruby+0x32d0> */
	goto x86_l_32d0;
x86_l_35a6:
	/* 0x35a6: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_35ad:
	/* 0x35ad: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35b0:
	/* 0x35b0: je     2bf6 <perf_unwind_ruby+0x2bf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11254ULL;
	}
x86_l_35b6:
	/* 0x35b6: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_35c0:
	/* 0x35c0: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_35c5:
	/* 0x35c5: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_35cf:
	/* 0x35cf: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_35d4:
	/* 0x35d4: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_35de:
	/* 0x35de: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_35e3:
	/* 0x35e3: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_35ed:
	/* 0x35ed: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_35f2:
	/* 0x35f2: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_35fc:
	/* 0x35fc: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3601:
	/* 0x3601: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_360b:
	/* 0x360b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3610:
	/* 0x3610: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3615:
	/* 0x3615: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_361a:
	/* 0x361a: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_361f:
	/* 0x361f: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3622:
	/* 0x3622: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_3627:
	/* 0x3627: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3629:
	/* 0x3629: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_362b:
	/* 0x362b: jmp    2bf6 <perf_unwind_ruby+0x2bf6> */
	return 11254ULL;
x86_l_3630:
	/* 0x3630: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_3637:
	/* 0x3637: jae    38c3 <perf_unwind_ruby+0x38c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14531ULL;
	}
x86_l_363d:
	/* 0x363d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3642:
	/* 0x3642: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3645:
	/* 0x3645: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_364b:
	/* 0x364b: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_3650:
	/* 0x3650: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3653:
	/* 0x3653: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3658:
	/* 0x3658: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3661:
	/* 0x3661: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_366a:
	/* 0x366a: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_366f:
	/* 0x366f: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3672:
	/* 0x3672: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3677:
	/* 0x3677: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_367c:
	/* 0x367c: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3682:
	/* 0x3682: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_3687:
	/* 0x3687: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_368c:
	/* 0x368c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3691:
	/* 0x3691: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3694:
	/* 0x3694: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_3699:
	/* 0x3699: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_369e:
	/* 0x369e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_36a3:
	/* 0x36a3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_36a8:
	/* 0x36a8: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_36ae:
	/* 0x36ae: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_36b3:
	/* 0x36b3: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_36b8:
	/* 0x36b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36bd:
	/* 0x36bd: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_36c0:
	/* 0x36c0: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_36c6:
	/* 0x36c6: je     399d <perf_unwind_ruby+0x399d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14749ULL;
	}
x86_l_36cc:
	/* 0x36cc: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_36d1:
	/* 0x36d1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36d4:
	/* 0x36d4: je     399d <perf_unwind_ruby+0x399d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14749ULL;
	}
x86_l_36da:
	/* 0x36da: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_36df:
	/* 0x36df: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_36e2:
	/* 0x36e2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36e7:
	/* 0x36e7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_36ec:
	/* 0x36ec: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_36f2:
	/* 0x36f2: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_36f7:
	/* 0x36f7: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_36fc:
	/* 0x36fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3701:
	/* 0x3701: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3704:
	/* 0x3704: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3707:
	/* 0x3707: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_370d:
	/* 0x370d: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_3712:
	/* 0x3712: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3717:
	/* 0x3717: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_371c:
	/* 0x371c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3721:
	/* 0x3721: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
	return 14119ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14119ULL: goto x86_l_3727;
	case 14124ULL: goto x86_l_372c;
	case 14129ULL: goto x86_l_3731;
	case 14134ULL: goto x86_l_3736;
	case 14137ULL: goto x86_l_3739;
	case 14140ULL: goto x86_l_373c;
	case 14146ULL: goto x86_l_3742;
	case 14151ULL: goto x86_l_3747;
	case 14156ULL: goto x86_l_374c;
	case 14161ULL: goto x86_l_3751;
	case 14166ULL: goto x86_l_3756;
	case 14172ULL: goto x86_l_375c;
	case 14177ULL: goto x86_l_3761;
	case 14182ULL: goto x86_l_3766;
	case 14187ULL: goto x86_l_376b;
	case 14190ULL: goto x86_l_376e;
	case 14193ULL: goto x86_l_3771;
	case 14199ULL: goto x86_l_3777;
	case 14204ULL: goto x86_l_377c;
	case 14207ULL: goto x86_l_377f;
	case 14212ULL: goto x86_l_3784;
	case 14217ULL: goto x86_l_3789;
	case 14220ULL: goto x86_l_378c;
	case 14224ULL: goto x86_l_3790;
	case 14230ULL: goto x86_l_3796;
	case 14232ULL: goto x86_l_3798;
	case 14235ULL: goto x86_l_379b;
	case 14240ULL: goto x86_l_37a0;
	case 14242ULL: goto x86_l_37a2;
	case 14244ULL: goto x86_l_37a4;
	case 14248ULL: goto x86_l_37a8;
	case 14251ULL: goto x86_l_37ab;
	case 14257ULL: goto x86_l_37b1;
	case 14264ULL: goto x86_l_37b8;
	case 14267ULL: goto x86_l_37bb;
	case 14273ULL: goto x86_l_37c1;
	case 14283ULL: goto x86_l_37cb;
	case 14288ULL: goto x86_l_37d0;
	case 14298ULL: goto x86_l_37da;
	case 14303ULL: goto x86_l_37df;
	case 14313ULL: goto x86_l_37e9;
	case 14318ULL: goto x86_l_37ee;
	case 14328ULL: goto x86_l_37f8;
	case 14333ULL: goto x86_l_37fd;
	case 14343ULL: goto x86_l_3807;
	case 14348ULL: goto x86_l_380c;
	case 14358ULL: goto x86_l_3816;
	case 14363ULL: goto x86_l_381b;
	case 14368ULL: goto x86_l_3820;
	case 14373ULL: goto x86_l_3825;
	case 14378ULL: goto x86_l_382a;
	case 14383ULL: goto x86_l_382f;
	case 14385ULL: goto x86_l_3831;
	case 14387ULL: goto x86_l_3833;
	case 14392ULL: goto x86_l_3838;
	case 14399ULL: goto x86_l_383f;
	case 14403ULL: goto x86_l_3843;
	case 14409ULL: goto x86_l_3849;
	case 14414ULL: goto x86_l_384e;
	case 14417ULL: goto x86_l_3851;
	case 14424ULL: goto x86_l_3858;
	case 14428ULL: goto x86_l_385c;
	case 14435ULL: goto x86_l_3863;
	case 14442ULL: goto x86_l_386a;
	case 14450ULL: goto x86_l_3872;
	case 14458ULL: goto x86_l_387a;
	case 14469ULL: goto x86_l_3885;
	case 14472ULL: goto x86_l_3888;
	case 14480ULL: goto x86_l_3890;
	case 14485ULL: goto x86_l_3895;
	case 14494ULL: goto x86_l_389e;
	case 14501ULL: goto x86_l_38a5;
	case 14508ULL: goto x86_l_38ac;
	case 14511ULL: goto x86_l_38af;
	case 14516ULL: goto x86_l_38b4;
	case 14518ULL: goto x86_l_38b6;
	case 14521ULL: goto x86_l_38b9;
	case 14523ULL: goto x86_l_38bb;
	case 14526ULL: goto x86_l_38be;
	case 14531ULL: goto x86_l_38c3;
	case 14539ULL: goto x86_l_38cb;
	case 14544ULL: goto x86_l_38d0;
	case 14549ULL: goto x86_l_38d5;
	case 14552ULL: goto x86_l_38d8;
	case 14557ULL: goto x86_l_38dd;
	case 14563ULL: goto x86_l_38e3;
	case 14568ULL: goto x86_l_38e8;
	case 14573ULL: goto x86_l_38ed;
	case 14578ULL: goto x86_l_38f2;
	case 14581ULL: goto x86_l_38f5;
	case 14584ULL: goto x86_l_38f8;
	case 14590ULL: goto x86_l_38fe;
	case 14593ULL: goto x86_l_3901;
	case 14595ULL: goto x86_l_3903;
	case 14600ULL: goto x86_l_3908;
	case 14606ULL: goto x86_l_390e;
	case 14611ULL: goto x86_l_3913;
	case 14618ULL: goto x86_l_391a;
	case 14621ULL: goto x86_l_391d;
	case 14627ULL: goto x86_l_3923;
	case 14637ULL: goto x86_l_392d;
	case 14642ULL: goto x86_l_3932;
	case 14652ULL: goto x86_l_393c;
	case 14657ULL: goto x86_l_3941;
	case 14667ULL: goto x86_l_394b;
	case 14672ULL: goto x86_l_3950;
	case 14682ULL: goto x86_l_395a;
	case 14687ULL: goto x86_l_395f;
	case 14697ULL: goto x86_l_3969;
	case 14702ULL: goto x86_l_396e;
	case 14712ULL: goto x86_l_3978;
	case 14717ULL: goto x86_l_397d;
	case 14722ULL: goto x86_l_3982;
	case 14727ULL: goto x86_l_3987;
	case 14732ULL: goto x86_l_398c;
	case 14735ULL: goto x86_l_398f;
	case 14740ULL: goto x86_l_3994;
	case 14742ULL: goto x86_l_3996;
	case 14744ULL: goto x86_l_3998;
	case 14749ULL: goto x86_l_399d;
	case 14756ULL: goto x86_l_39a4;
	case 14762ULL: goto x86_l_39aa;
	case 14767ULL: goto x86_l_39af;
	case 14770ULL: goto x86_l_39b2;
	case 14776ULL: goto x86_l_39b8;
	case 14781ULL: goto x86_l_39bd;
	case 14784ULL: goto x86_l_39c0;
	case 14789ULL: goto x86_l_39c5;
	case 14798ULL: goto x86_l_39ce;
	case 14807ULL: goto x86_l_39d7;
	case 14812ULL: goto x86_l_39dc;
	case 14815ULL: goto x86_l_39df;
	case 14820ULL: goto x86_l_39e4;
	case 14825ULL: goto x86_l_39e9;
	case 14831ULL: goto x86_l_39ef;
	case 14836ULL: goto x86_l_39f4;
	case 14841ULL: goto x86_l_39f9;
	case 14846ULL: goto x86_l_39fe;
	case 14849ULL: goto x86_l_3a01;
	case 14854ULL: goto x86_l_3a06;
	case 14859ULL: goto x86_l_3a0b;
	case 14864ULL: goto x86_l_3a10;
	case 14869ULL: goto x86_l_3a15;
	case 14875ULL: goto x86_l_3a1b;
	case 14880ULL: goto x86_l_3a20;
	case 14885ULL: goto x86_l_3a25;
	case 14890ULL: goto x86_l_3a2a;
	case 14893ULL: goto x86_l_3a2d;
	case 14899ULL: goto x86_l_3a33;
	case 14905ULL: goto x86_l_3a39;
	case 14910ULL: goto x86_l_3a3e;
	case 14913ULL: goto x86_l_3a41;
	case 14919ULL: goto x86_l_3a47;
	case 14924ULL: goto x86_l_3a4c;
	case 14927ULL: goto x86_l_3a4f;
	case 14932ULL: goto x86_l_3a54;
	case 14937ULL: goto x86_l_3a59;
	case 14943ULL: goto x86_l_3a5f;
	case 14948ULL: goto x86_l_3a64;
	case 14953ULL: goto x86_l_3a69;
	case 14958ULL: goto x86_l_3a6e;
	case 14961ULL: goto x86_l_3a71;
	case 14964ULL: goto x86_l_3a74;
	case 14970ULL: goto x86_l_3a7a;
	case 14975ULL: goto x86_l_3a7f;
	case 14980ULL: goto x86_l_3a84;
	case 14985ULL: goto x86_l_3a89;
	case 14990ULL: goto x86_l_3a8e;
	case 14996ULL: goto x86_l_3a94;
	case 15001ULL: goto x86_l_3a99;
	case 15006ULL: goto x86_l_3a9e;
	case 15011ULL: goto x86_l_3aa3;
	case 15014ULL: goto x86_l_3aa6;
	case 15017ULL: goto x86_l_3aa9;
	case 15023ULL: goto x86_l_3aaf;
	case 15028ULL: goto x86_l_3ab4;
	case 15033ULL: goto x86_l_3ab9;
	case 15038ULL: goto x86_l_3abe;
	case 15043ULL: goto x86_l_3ac3;
	case 15049ULL: goto x86_l_3ac9;
	case 15054ULL: goto x86_l_3ace;
	case 15059ULL: goto x86_l_3ad3;
	case 15064ULL: goto x86_l_3ad8;
	case 15067ULL: goto x86_l_3adb;
	case 15070ULL: goto x86_l_3ade;
	case 15076ULL: goto x86_l_3ae4;
	case 15081ULL: goto x86_l_3ae9;
	case 15084ULL: goto x86_l_3aec;
	case 15089ULL: goto x86_l_3af1;
	case 15094ULL: goto x86_l_3af6;
	case 15097ULL: goto x86_l_3af9;
	case 15101ULL: goto x86_l_3afd;
	case 15107ULL: goto x86_l_3b03;
	case 15109ULL: goto x86_l_3b05;
	case 15112ULL: goto x86_l_3b08;
	case 15117ULL: goto x86_l_3b0d;
	case 15119ULL: goto x86_l_3b0f;
	case 15121ULL: goto x86_l_3b11;
	case 15125ULL: goto x86_l_3b15;
	case 15128ULL: goto x86_l_3b18;
	case 15134ULL: goto x86_l_3b1e;
	case 15141ULL: goto x86_l_3b25;
	case 15144ULL: goto x86_l_3b28;
	case 15150ULL: goto x86_l_3b2e;
	case 15160ULL: goto x86_l_3b38;
	case 15165ULL: goto x86_l_3b3d;
	case 15175ULL: goto x86_l_3b47;
	case 15180ULL: goto x86_l_3b4c;
	case 15190ULL: goto x86_l_3b56;
	case 15195ULL: goto x86_l_3b5b;
	case 15205ULL: goto x86_l_3b65;
	case 15210ULL: goto x86_l_3b6a;
	case 15220ULL: goto x86_l_3b74;
	case 15225ULL: goto x86_l_3b79;
	case 15235ULL: goto x86_l_3b83;
	case 15240ULL: goto x86_l_3b88;
	case 15245ULL: goto x86_l_3b8d;
	case 15250ULL: goto x86_l_3b92;
	case 15255ULL: goto x86_l_3b97;
	case 15260ULL: goto x86_l_3b9c;
	case 15262ULL: goto x86_l_3b9e;
	case 15264ULL: goto x86_l_3ba0;
	case 15269ULL: goto x86_l_3ba5;
	case 15276ULL: goto x86_l_3bac;
	case 15280ULL: goto x86_l_3bb0;
	case 15286ULL: goto x86_l_3bb6;
	case 15291ULL: goto x86_l_3bbb;
	case 15294ULL: goto x86_l_3bbe;
	case 15301ULL: goto x86_l_3bc5;
	case 15305ULL: goto x86_l_3bc9;
	case 15312ULL: goto x86_l_3bd0;
	case 15319ULL: goto x86_l_3bd7;
	case 15327ULL: goto x86_l_3bdf;
	case 15335ULL: goto x86_l_3be7;
	case 15346ULL: goto x86_l_3bf2;
	case 15349ULL: goto x86_l_3bf5;
	case 15357ULL: goto x86_l_3bfd;
	case 15362ULL: goto x86_l_3c02;
	case 15371ULL: goto x86_l_3c0b;
	case 15378ULL: goto x86_l_3c12;
	case 15385ULL: goto x86_l_3c19;
	case 15388ULL: goto x86_l_3c1c;
	case 15393ULL: goto x86_l_3c21;
	case 15395ULL: goto x86_l_3c23;
	case 15398ULL: goto x86_l_3c26;
	case 15400ULL: goto x86_l_3c28;
	case 15403ULL: goto x86_l_3c2b;
	case 15408ULL: goto x86_l_3c30;
	case 15416ULL: goto x86_l_3c38;
	case 15421ULL: goto x86_l_3c3d;
	case 15426ULL: goto x86_l_3c42;
	case 15429ULL: goto x86_l_3c45;
	case 15434ULL: goto x86_l_3c4a;
	case 15440ULL: goto x86_l_3c50;
	case 15445ULL: goto x86_l_3c55;
	case 15450ULL: goto x86_l_3c5a;
	case 15455ULL: goto x86_l_3c5f;
	case 15458ULL: goto x86_l_3c62;
	case 15461ULL: goto x86_l_3c65;
	case 15467ULL: goto x86_l_3c6b;
	case 15470ULL: goto x86_l_3c6e;
	case 15472ULL: goto x86_l_3c70;
	case 15477ULL: goto x86_l_3c75;
	case 15483ULL: goto x86_l_3c7b;
	case 15488ULL: goto x86_l_3c80;
	case 15495ULL: goto x86_l_3c87;
	case 15498ULL: goto x86_l_3c8a;
	case 15504ULL: goto x86_l_3c90;
	case 15514ULL: goto x86_l_3c9a;
	case 15519ULL: goto x86_l_3c9f;
	case 15529ULL: goto x86_l_3ca9;
	case 15534ULL: goto x86_l_3cae;
	case 15544ULL: goto x86_l_3cb8;
	case 15549ULL: goto x86_l_3cbd;
	case 15559ULL: goto x86_l_3cc7;
	case 15564ULL: goto x86_l_3ccc;
	case 15574ULL: goto x86_l_3cd6;
	case 15579ULL: goto x86_l_3cdb;
	case 15589ULL: goto x86_l_3ce5;
	case 15594ULL: goto x86_l_3cea;
	case 15599ULL: goto x86_l_3cef;
	case 15604ULL: goto x86_l_3cf4;
	case 15609ULL: goto x86_l_3cf9;
	case 15612ULL: goto x86_l_3cfc;
	case 15617ULL: goto x86_l_3d01;
	case 15619ULL: goto x86_l_3d03;
	case 15621ULL: goto x86_l_3d05;
	case 15626ULL: goto x86_l_3d0a;
	case 15633ULL: goto x86_l_3d11;
	case 15639ULL: goto x86_l_3d17;
	case 15644ULL: goto x86_l_3d1c;
	case 15647ULL: goto x86_l_3d1f;
	case 15653ULL: goto x86_l_3d25;
	case 15658ULL: goto x86_l_3d2a;
	case 15661ULL: goto x86_l_3d2d;
	case 15666ULL: goto x86_l_3d32;
	case 15675ULL: goto x86_l_3d3b;
	case 15684ULL: goto x86_l_3d44;
	case 15689ULL: goto x86_l_3d49;
	case 15692ULL: goto x86_l_3d4c;
	case 15697ULL: goto x86_l_3d51;
	case 15702ULL: goto x86_l_3d56;
	case 15708ULL: goto x86_l_3d5c;
	case 15713ULL: goto x86_l_3d61;
	case 15718ULL: goto x86_l_3d66;
	case 15723ULL: goto x86_l_3d6b;
	case 15726ULL: goto x86_l_3d6e;
	case 15731ULL: goto x86_l_3d73;
	case 15736ULL: goto x86_l_3d78;
	case 15741ULL: goto x86_l_3d7d;
	case 15746ULL: goto x86_l_3d82;
	case 15752ULL: goto x86_l_3d88;
	case 15757ULL: goto x86_l_3d8d;
	case 15762ULL: goto x86_l_3d92;
	case 15767ULL: goto x86_l_3d97;
	case 15770ULL: goto x86_l_3d9a;
	case 15776ULL: goto x86_l_3da0;
	case 15782ULL: goto x86_l_3da6;
	case 15787ULL: goto x86_l_3dab;
	case 15790ULL: goto x86_l_3dae;
	case 15796ULL: goto x86_l_3db4;
	case 15801ULL: goto x86_l_3db9;
	case 15804ULL: goto x86_l_3dbc;
	case 15809ULL: goto x86_l_3dc1;
	case 15814ULL: goto x86_l_3dc6;
	case 15820ULL: goto x86_l_3dcc;
	case 15825ULL: goto x86_l_3dd1;
	case 15830ULL: goto x86_l_3dd6;
	case 15835ULL: goto x86_l_3ddb;
	case 15838ULL: goto x86_l_3dde;
	case 15841ULL: goto x86_l_3de1;
	case 15847ULL: goto x86_l_3de7;
	case 15852ULL: goto x86_l_3dec;
	case 15857ULL: goto x86_l_3df1;
	case 15862ULL: goto x86_l_3df6;
	case 15867ULL: goto x86_l_3dfb;
	case 15873ULL: goto x86_l_3e01;
	case 15878ULL: goto x86_l_3e06;
	case 15883ULL: goto x86_l_3e0b;
	case 15888ULL: goto x86_l_3e10;
	case 15891ULL: goto x86_l_3e13;
	case 15894ULL: goto x86_l_3e16;
	case 15900ULL: goto x86_l_3e1c;
	case 15905ULL: goto x86_l_3e21;
	case 15910ULL: goto x86_l_3e26;
	case 15915ULL: goto x86_l_3e2b;
	case 15920ULL: goto x86_l_3e30;
	case 15926ULL: goto x86_l_3e36;
	case 15931ULL: goto x86_l_3e3b;
	case 15936ULL: goto x86_l_3e40;
	case 15941ULL: goto x86_l_3e45;
	case 15944ULL: goto x86_l_3e48;
	case 15947ULL: goto x86_l_3e4b;
	case 15953ULL: goto x86_l_3e51;
	case 15958ULL: goto x86_l_3e56;
	case 15961ULL: goto x86_l_3e59;
	case 15966ULL: goto x86_l_3e5e;
	case 15971ULL: goto x86_l_3e63;
	case 15974ULL: goto x86_l_3e66;
	case 15978ULL: goto x86_l_3e6a;
	case 15984ULL: goto x86_l_3e70;
	case 15986ULL: goto x86_l_3e72;
	case 15989ULL: goto x86_l_3e75;
	case 15994ULL: goto x86_l_3e7a;
	case 15996ULL: goto x86_l_3e7c;
	case 15998ULL: goto x86_l_3e7e;
	case 16002ULL: goto x86_l_3e82;
	case 16005ULL: goto x86_l_3e85;
	case 16011ULL: goto x86_l_3e8b;
	case 16018ULL: goto x86_l_3e92;
	case 16021ULL: goto x86_l_3e95;
	case 16027ULL: goto x86_l_3e9b;
	case 16037ULL: goto x86_l_3ea5;
	case 16042ULL: goto x86_l_3eaa;
	case 16052ULL: goto x86_l_3eb4;
	case 16057ULL: goto x86_l_3eb9;
	case 16067ULL: goto x86_l_3ec3;
	case 16072ULL: goto x86_l_3ec8;
	case 16082ULL: goto x86_l_3ed2;
	case 16087ULL: goto x86_l_3ed7;
	case 16097ULL: goto x86_l_3ee1;
	case 16102ULL: goto x86_l_3ee6;
	case 16112ULL: goto x86_l_3ef0;
	case 16117ULL: goto x86_l_3ef5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3727:
	/* 0x3727: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_372c:
	/* 0x372c: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3731:
	/* 0x3731: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3736:
	/* 0x3736: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3739:
	/* 0x3739: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_373c:
	/* 0x373c: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_3742:
	/* 0x3742: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_3747:
	/* 0x3747: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_374c:
	/* 0x374c: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3751:
	/* 0x3751: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3756:
	/* 0x3756: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_375c:
	/* 0x375c: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_3761:
	/* 0x3761: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3766:
	/* 0x3766: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_376b:
	/* 0x376b: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_376e:
	/* 0x376e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3771:
	/* 0x3771: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_3777:
	/* 0x3777: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_377c:
	/* 0x377c: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_377f:
	/* 0x377f: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_3784:
	/* 0x3784: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_3789:
	/* 0x3789: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_378c:
	/* 0x378c: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_3790:
	/* 0x3790: je     41e7 <perf_unwind_ruby+0x41e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16871ULL;
	}
x86_l_3796:
	/* 0x3796: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3798:
	/* 0x3798: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_379b:
	/* 0x379b: jmp    41eb <perf_unwind_ruby+0x41eb> */
	return 16875ULL;
x86_l_37a0:
	/* 0x37a0: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37a2:
	/* 0x37a2: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_37a4:
	/* 0x37a4: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_37a8:
	/* 0x37a8: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_37ab:
	/* 0x37ab: jbe    3838 <perf_unwind_ruby+0x3838> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3838;
	}
x86_l_37b1:
	/* 0x37b1: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_37b8:
	/* 0x37b8: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37bb:
	/* 0x37bb: je     2f63 <perf_unwind_ruby+0x2f63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12131ULL;
	}
x86_l_37c1:
	/* 0x37c1: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_37cb:
	/* 0x37cb: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_37d0:
	/* 0x37d0: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_37da:
	/* 0x37da: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_37df:
	/* 0x37df: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_37e9:
	/* 0x37e9: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_37ee:
	/* 0x37ee: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_37f8:
	/* 0x37f8: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_37fd:
	/* 0x37fd: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_3807:
	/* 0x3807: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_380c:
	/* 0x380c: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_3816:
	/* 0x3816: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_381b:
	/* 0x381b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3820:
	/* 0x3820: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3825:
	/* 0x3825: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_382a:
	/* 0x382a: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_382f:
	/* 0x382f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3831:
	/* 0x3831: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3833:
	/* 0x3833: jmp    2f63 <perf_unwind_ruby+0x2f63> */
	return 12131ULL;
x86_l_3838:
	/* 0x3838: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_383f:
	/* 0x383f: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_3843:
	/* 0x3843: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_3849:
	/* 0x3849: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_384e:
	/* 0x384e: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3851:
	/* 0x3851: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3858:
	/* 0x3858: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_385c:
	/* 0x385c: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3863:
	/* 0x3863: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_386a:
	/* 0x386a: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_3872:
	/* 0x3872: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_387a:
	/* 0x387a: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_3885:
	/* 0x3885: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3888:
	/* 0x3888: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_3890:
	/* 0x3890: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3895:
	/* 0x3895: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_389e:
	/* 0x389e: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_38a5:
	/* 0x38a5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_38ac:
	/* 0x38ac: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_38af:
	/* 0x38af: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_38b4:
	/* 0x38b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38b6:
	/* 0x38b6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38b9:
	/* 0x38b9: je     3913 <perf_unwind_ruby+0x3913> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3913;
	}
x86_l_38bb:
	/* 0x38bb: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_38be:
	/* 0x38be: jmp    2f63 <perf_unwind_ruby+0x2f63> */
	return 12131ULL;
x86_l_38c3:
	/* 0x38c3: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38cb:
	/* 0x38cb: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_38d0:
	/* 0x38d0: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_38d5:
	/* 0x38d5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_38d8:
	/* 0x38d8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_38dd:
	/* 0x38dd: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_38e3:
	/* 0x38e3: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_38e8:
	/* 0x38e8: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_38ed:
	/* 0x38ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38f2:
	/* 0x38f2: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_38f5:
	/* 0x38f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38f8:
	/* 0x38f8: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_38fe:
	/* 0x38fe: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3901:
	/* 0x3901: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_3903:
	/* 0x3903: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_3908:
	/* 0x3908: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_390e:
	/* 0x390e: jmp    363d <perf_unwind_ruby+0x363d> */
	return 13885ULL;
x86_l_3913:
	/* 0x3913: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_391a:
	/* 0x391a: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_391d:
	/* 0x391d: je     2f63 <perf_unwind_ruby+0x2f63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12131ULL;
	}
x86_l_3923:
	/* 0x3923: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_392d:
	/* 0x392d: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_3932:
	/* 0x3932: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_393c:
	/* 0x393c: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3941:
	/* 0x3941: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_394b:
	/* 0x394b: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3950:
	/* 0x3950: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_395a:
	/* 0x395a: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_395f:
	/* 0x395f: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_3969:
	/* 0x3969: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_396e:
	/* 0x396e: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_3978:
	/* 0x3978: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_397d:
	/* 0x397d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3982:
	/* 0x3982: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_3987:
	/* 0x3987: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_398c:
	/* 0x398c: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_398f:
	/* 0x398f: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_3994:
	/* 0x3994: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3996:
	/* 0x3996: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3998:
	/* 0x3998: jmp    2f63 <perf_unwind_ruby+0x2f63> */
	return 12131ULL;
x86_l_399d:
	/* 0x399d: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_39a4:
	/* 0x39a4: jae    3c30 <perf_unwind_ruby+0x3c30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3c30;
	}
x86_l_39aa:
	/* 0x39aa: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39af:
	/* 0x39af: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_39b2:
	/* 0x39b2: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_39b8:
	/* 0x39b8: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_39bd:
	/* 0x39bd: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_39c0:
	/* 0x39c0: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39c5:
	/* 0x39c5: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_39ce:
	/* 0x39ce: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_39d7:
	/* 0x39d7: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_39dc:
	/* 0x39dc: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_39df:
	/* 0x39df: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_39e4:
	/* 0x39e4: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_39e9:
	/* 0x39e9: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_39ef:
	/* 0x39ef: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_39f4:
	/* 0x39f4: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_39f9:
	/* 0x39f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39fe:
	/* 0x39fe: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3a01:
	/* 0x3a01: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_3a06:
	/* 0x3a06: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3a0b:
	/* 0x3a0b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a10:
	/* 0x3a10: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3a15:
	/* 0x3a15: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3a1b:
	/* 0x3a1b: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_3a20:
	/* 0x3a20: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3a25:
	/* 0x3a25: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a2a:
	/* 0x3a2a: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3a2d:
	/* 0x3a2d: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3a33:
	/* 0x3a33: je     3d0a <perf_unwind_ruby+0x3d0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d0a;
	}
x86_l_3a39:
	/* 0x3a39: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3a3e:
	/* 0x3a3e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a41:
	/* 0x3a41: je     3d0a <perf_unwind_ruby+0x3d0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d0a;
	}
x86_l_3a47:
	/* 0x3a47: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_3a4c:
	/* 0x3a4c: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3a4f:
	/* 0x3a4f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a54:
	/* 0x3a54: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3a59:
	/* 0x3a59: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3a5f:
	/* 0x3a5f: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_3a64:
	/* 0x3a64: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_3a69:
	/* 0x3a69: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a6e:
	/* 0x3a6e: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3a71:
	/* 0x3a71: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a74:
	/* 0x3a74: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_3a7a:
	/* 0x3a7a: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_3a7f:
	/* 0x3a7f: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3a84:
	/* 0x3a84: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3a89:
	/* 0x3a89: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3a8e:
	/* 0x3a8e: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3a94:
	/* 0x3a94: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_3a99:
	/* 0x3a99: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3a9e:
	/* 0x3a9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3aa3:
	/* 0x3aa3: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3aa6:
	/* 0x3aa6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3aa9:
	/* 0x3aa9: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_3aaf:
	/* 0x3aaf: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_3ab4:
	/* 0x3ab4: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3ab9:
	/* 0x3ab9: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3abe:
	/* 0x3abe: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3ac3:
	/* 0x3ac3: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3ac9:
	/* 0x3ac9: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_3ace:
	/* 0x3ace: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3ad3:
	/* 0x3ad3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ad8:
	/* 0x3ad8: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3adb:
	/* 0x3adb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ade:
	/* 0x3ade: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_3ae4:
	/* 0x3ae4: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ae9:
	/* 0x3ae9: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_3aec:
	/* 0x3aec: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_3af1:
	/* 0x3af1: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_3af6:
	/* 0x3af6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3af9:
	/* 0x3af9: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_3afd:
	/* 0x3afd: je     4554 <perf_unwind_ruby+0x4554> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17748ULL;
	}
x86_l_3b03:
	/* 0x3b03: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b05:
	/* 0x3b05: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_3b08:
	/* 0x3b08: jmp    4558 <perf_unwind_ruby+0x4558> */
	return 17752ULL;
x86_l_3b0d:
	/* 0x3b0d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b0f:
	/* 0x3b0f: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_3b11:
	/* 0x3b11: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3b15:
	/* 0x3b15: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_3b18:
	/* 0x3b18: jbe    3ba5 <perf_unwind_ruby+0x3ba5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3ba5;
	}
x86_l_3b1e:
	/* 0x3b1e: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3b25:
	/* 0x3b25: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b28:
	/* 0x3b28: je     32d0 <perf_unwind_ruby+0x32d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13008ULL;
	}
x86_l_3b2e:
	/* 0x3b2e: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_3b38:
	/* 0x3b38: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_3b3d:
	/* 0x3b3d: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_3b47:
	/* 0x3b47: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3b4c:
	/* 0x3b4c: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_3b56:
	/* 0x3b56: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3b5b:
	/* 0x3b5b: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_3b65:
	/* 0x3b65: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3b6a:
	/* 0x3b6a: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_3b74:
	/* 0x3b74: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3b79:
	/* 0x3b79: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_3b83:
	/* 0x3b83: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b88:
	/* 0x3b88: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b8d:
	/* 0x3b8d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3b92:
	/* 0x3b92: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3b97:
	/* 0x3b97: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_3b9c:
	/* 0x3b9c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b9e:
	/* 0x3b9e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3ba0:
	/* 0x3ba0: jmp    32d0 <perf_unwind_ruby+0x32d0> */
	return 13008ULL;
x86_l_3ba5:
	/* 0x3ba5: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3bac:
	/* 0x3bac: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_3bb0:
	/* 0x3bb0: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_3bb6:
	/* 0x3bb6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bbb:
	/* 0x3bbb: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3bbe:
	/* 0x3bbe: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3bc5:
	/* 0x3bc5: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_3bc9:
	/* 0x3bc9: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3bd0:
	/* 0x3bd0: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3bd7:
	/* 0x3bd7: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_3bdf:
	/* 0x3bdf: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_3be7:
	/* 0x3be7: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_3bf2:
	/* 0x3bf2: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3bf5:
	/* 0x3bf5: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_3bfd:
	/* 0x3bfd: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3c02:
	/* 0x3c02: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_3c0b:
	/* 0x3c0b: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_3c12:
	/* 0x3c12: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_3c19:
	/* 0x3c19: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_3c1c:
	/* 0x3c1c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c21:
	/* 0x3c21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c23:
	/* 0x3c23: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3c26:
	/* 0x3c26: je     3c80 <perf_unwind_ruby+0x3c80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c80;
	}
x86_l_3c28:
	/* 0x3c28: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3c2b:
	/* 0x3c2b: jmp    32d0 <perf_unwind_ruby+0x32d0> */
	return 13008ULL;
x86_l_3c30:
	/* 0x3c30: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c38:
	/* 0x3c38: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_3c3d:
	/* 0x3c3d: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3c42:
	/* 0x3c42: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3c45:
	/* 0x3c45: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3c4a:
	/* 0x3c4a: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3c50:
	/* 0x3c50: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_3c55:
	/* 0x3c55: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3c5a:
	/* 0x3c5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c5f:
	/* 0x3c5f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3c62:
	/* 0x3c62: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3c65:
	/* 0x3c65: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_3c6b:
	/* 0x3c6b: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c6e:
	/* 0x3c6e: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_3c70:
	/* 0x3c70: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_3c75:
	/* 0x3c75: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_3c7b:
	/* 0x3c7b: jmp    39aa <perf_unwind_ruby+0x39aa> */
	goto x86_l_39aa;
x86_l_3c80:
	/* 0x3c80: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3c87:
	/* 0x3c87: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c8a:
	/* 0x3c8a: je     32d0 <perf_unwind_ruby+0x32d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13008ULL;
	}
x86_l_3c90:
	/* 0x3c90: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_3c9a:
	/* 0x3c9a: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_3c9f:
	/* 0x3c9f: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_3ca9:
	/* 0x3ca9: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3cae:
	/* 0x3cae: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_3cb8:
	/* 0x3cb8: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3cbd:
	/* 0x3cbd: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_3cc7:
	/* 0x3cc7: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3ccc:
	/* 0x3ccc: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_3cd6:
	/* 0x3cd6: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3cdb:
	/* 0x3cdb: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_3ce5:
	/* 0x3ce5: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3cea:
	/* 0x3cea: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3cef:
	/* 0x3cef: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_3cf4:
	/* 0x3cf4: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3cf9:
	/* 0x3cf9: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cfc:
	/* 0x3cfc: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_3d01:
	/* 0x3d01: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d03:
	/* 0x3d03: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3d05:
	/* 0x3d05: jmp    32d0 <perf_unwind_ruby+0x32d0> */
	return 13008ULL;
x86_l_3d0a:
	/* 0x3d0a: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_3d11:
	/* 0x3d11: jae    3f9d <perf_unwind_ruby+0x3f9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 16285ULL;
	}
x86_l_3d17:
	/* 0x3d17: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d1c:
	/* 0x3d1c: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3d1f:
	/* 0x3d1f: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_3d25:
	/* 0x3d25: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_3d2a:
	/* 0x3d2a: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3d2d:
	/* 0x3d2d: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d32:
	/* 0x3d32: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3d3b:
	/* 0x3d3b: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3d44:
	/* 0x3d44: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_3d49:
	/* 0x3d49: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3d4c:
	/* 0x3d4c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3d51:
	/* 0x3d51: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3d56:
	/* 0x3d56: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3d5c:
	/* 0x3d5c: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_3d61:
	/* 0x3d61: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3d66:
	/* 0x3d66: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d6b:
	/* 0x3d6b: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3d6e:
	/* 0x3d6e: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_3d73:
	/* 0x3d73: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3d78:
	/* 0x3d78: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3d7d:
	/* 0x3d7d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3d82:
	/* 0x3d82: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3d88:
	/* 0x3d88: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_3d8d:
	/* 0x3d8d: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3d92:
	/* 0x3d92: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d97:
	/* 0x3d97: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3d9a:
	/* 0x3d9a: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3da0:
	/* 0x3da0: je     4077 <perf_unwind_ruby+0x4077> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16503ULL;
	}
x86_l_3da6:
	/* 0x3da6: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3dab:
	/* 0x3dab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3dae:
	/* 0x3dae: je     4077 <perf_unwind_ruby+0x4077> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16503ULL;
	}
x86_l_3db4:
	/* 0x3db4: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_3db9:
	/* 0x3db9: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3dbc:
	/* 0x3dbc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3dc1:
	/* 0x3dc1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3dc6:
	/* 0x3dc6: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3dcc:
	/* 0x3dcc: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_3dd1:
	/* 0x3dd1: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_3dd6:
	/* 0x3dd6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ddb:
	/* 0x3ddb: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3dde:
	/* 0x3dde: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3de1:
	/* 0x3de1: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_3de7:
	/* 0x3de7: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_3dec:
	/* 0x3dec: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3df1:
	/* 0x3df1: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3df6:
	/* 0x3df6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3dfb:
	/* 0x3dfb: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3e01:
	/* 0x3e01: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_3e06:
	/* 0x3e06: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3e0b:
	/* 0x3e0b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e10:
	/* 0x3e10: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3e13:
	/* 0x3e13: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e16:
	/* 0x3e16: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_3e1c:
	/* 0x3e1c: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_3e21:
	/* 0x3e21: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3e26:
	/* 0x3e26: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3e2b:
	/* 0x3e2b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3e30:
	/* 0x3e30: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3e36:
	/* 0x3e36: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_3e3b:
	/* 0x3e3b: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3e40:
	/* 0x3e40: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e45:
	/* 0x3e45: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3e48:
	/* 0x3e48: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e4b:
	/* 0x3e4b: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_3e51:
	/* 0x3e51: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e56:
	/* 0x3e56: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_3e59:
	/* 0x3e59: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_3e5e:
	/* 0x3e5e: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_3e63:
	/* 0x3e63: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3e66:
	/* 0x3e66: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_3e6a:
	/* 0x3e6a: je     48c1 <perf_unwind_ruby+0x48c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18625ULL;
	}
x86_l_3e70:
	/* 0x3e70: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e72:
	/* 0x3e72: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_3e75:
	/* 0x3e75: jmp    48c5 <perf_unwind_ruby+0x48c5> */
	return 18629ULL;
x86_l_3e7a:
	/* 0x3e7a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e7c:
	/* 0x3e7c: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_3e7e:
	/* 0x3e7e: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3e82:
	/* 0x3e82: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_3e85:
	/* 0x3e85: jbe    3f12 <perf_unwind_ruby+0x3f12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 16146ULL;
	}
x86_l_3e8b:
	/* 0x3e8b: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3e92:
	/* 0x3e92: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e95:
	/* 0x3e95: je     363d <perf_unwind_ruby+0x363d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13885ULL;
	}
x86_l_3e9b:
	/* 0x3e9b: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_3ea5:
	/* 0x3ea5: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_3eaa:
	/* 0x3eaa: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_3eb4:
	/* 0x3eb4: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3eb9:
	/* 0x3eb9: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_3ec3:
	/* 0x3ec3: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3ec8:
	/* 0x3ec8: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_3ed2:
	/* 0x3ed2: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3ed7:
	/* 0x3ed7: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_3ee1:
	/* 0x3ee1: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3ee6:
	/* 0x3ee6: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_3ef0:
	/* 0x3ef0: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ef5:
	/* 0x3ef5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
	return 16122ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 16122ULL: goto x86_l_3efa;
	case 16127ULL: goto x86_l_3eff;
	case 16132ULL: goto x86_l_3f04;
	case 16137ULL: goto x86_l_3f09;
	case 16139ULL: goto x86_l_3f0b;
	case 16141ULL: goto x86_l_3f0d;
	case 16146ULL: goto x86_l_3f12;
	case 16153ULL: goto x86_l_3f19;
	case 16157ULL: goto x86_l_3f1d;
	case 16163ULL: goto x86_l_3f23;
	case 16168ULL: goto x86_l_3f28;
	case 16171ULL: goto x86_l_3f2b;
	case 16178ULL: goto x86_l_3f32;
	case 16182ULL: goto x86_l_3f36;
	case 16189ULL: goto x86_l_3f3d;
	case 16196ULL: goto x86_l_3f44;
	case 16204ULL: goto x86_l_3f4c;
	case 16212ULL: goto x86_l_3f54;
	case 16223ULL: goto x86_l_3f5f;
	case 16226ULL: goto x86_l_3f62;
	case 16234ULL: goto x86_l_3f6a;
	case 16239ULL: goto x86_l_3f6f;
	case 16248ULL: goto x86_l_3f78;
	case 16255ULL: goto x86_l_3f7f;
	case 16262ULL: goto x86_l_3f86;
	case 16265ULL: goto x86_l_3f89;
	case 16270ULL: goto x86_l_3f8e;
	case 16272ULL: goto x86_l_3f90;
	case 16275ULL: goto x86_l_3f93;
	case 16277ULL: goto x86_l_3f95;
	case 16280ULL: goto x86_l_3f98;
	case 16285ULL: goto x86_l_3f9d;
	case 16293ULL: goto x86_l_3fa5;
	case 16298ULL: goto x86_l_3faa;
	case 16303ULL: goto x86_l_3faf;
	case 16306ULL: goto x86_l_3fb2;
	case 16311ULL: goto x86_l_3fb7;
	case 16317ULL: goto x86_l_3fbd;
	case 16322ULL: goto x86_l_3fc2;
	case 16327ULL: goto x86_l_3fc7;
	case 16332ULL: goto x86_l_3fcc;
	case 16335ULL: goto x86_l_3fcf;
	case 16338ULL: goto x86_l_3fd2;
	case 16344ULL: goto x86_l_3fd8;
	case 16347ULL: goto x86_l_3fdb;
	case 16349ULL: goto x86_l_3fdd;
	case 16354ULL: goto x86_l_3fe2;
	case 16360ULL: goto x86_l_3fe8;
	case 16365ULL: goto x86_l_3fed;
	case 16372ULL: goto x86_l_3ff4;
	case 16375ULL: goto x86_l_3ff7;
	case 16381ULL: goto x86_l_3ffd;
	case 16391ULL: goto x86_l_4007;
	case 16396ULL: goto x86_l_400c;
	case 16406ULL: goto x86_l_4016;
	case 16411ULL: goto x86_l_401b;
	case 16421ULL: goto x86_l_4025;
	case 16426ULL: goto x86_l_402a;
	case 16436ULL: goto x86_l_4034;
	case 16441ULL: goto x86_l_4039;
	case 16451ULL: goto x86_l_4043;
	case 16456ULL: goto x86_l_4048;
	case 16466ULL: goto x86_l_4052;
	case 16471ULL: goto x86_l_4057;
	case 16476ULL: goto x86_l_405c;
	case 16481ULL: goto x86_l_4061;
	case 16486ULL: goto x86_l_4066;
	case 16489ULL: goto x86_l_4069;
	case 16494ULL: goto x86_l_406e;
	case 16496ULL: goto x86_l_4070;
	case 16498ULL: goto x86_l_4072;
	case 16503ULL: goto x86_l_4077;
	case 16510ULL: goto x86_l_407e;
	case 16516ULL: goto x86_l_4084;
	case 16521ULL: goto x86_l_4089;
	case 16524ULL: goto x86_l_408c;
	case 16530ULL: goto x86_l_4092;
	case 16535ULL: goto x86_l_4097;
	case 16538ULL: goto x86_l_409a;
	case 16543ULL: goto x86_l_409f;
	case 16552ULL: goto x86_l_40a8;
	case 16561ULL: goto x86_l_40b1;
	case 16566ULL: goto x86_l_40b6;
	case 16569ULL: goto x86_l_40b9;
	case 16574ULL: goto x86_l_40be;
	case 16579ULL: goto x86_l_40c3;
	case 16585ULL: goto x86_l_40c9;
	case 16590ULL: goto x86_l_40ce;
	case 16595ULL: goto x86_l_40d3;
	case 16600ULL: goto x86_l_40d8;
	case 16603ULL: goto x86_l_40db;
	case 16608ULL: goto x86_l_40e0;
	case 16613ULL: goto x86_l_40e5;
	case 16618ULL: goto x86_l_40ea;
	case 16623ULL: goto x86_l_40ef;
	case 16629ULL: goto x86_l_40f5;
	case 16634ULL: goto x86_l_40fa;
	case 16639ULL: goto x86_l_40ff;
	case 16644ULL: goto x86_l_4104;
	case 16647ULL: goto x86_l_4107;
	case 16653ULL: goto x86_l_410d;
	case 16659ULL: goto x86_l_4113;
	case 16664ULL: goto x86_l_4118;
	case 16667ULL: goto x86_l_411b;
	case 16673ULL: goto x86_l_4121;
	case 16678ULL: goto x86_l_4126;
	case 16681ULL: goto x86_l_4129;
	case 16686ULL: goto x86_l_412e;
	case 16691ULL: goto x86_l_4133;
	case 16697ULL: goto x86_l_4139;
	case 16702ULL: goto x86_l_413e;
	case 16707ULL: goto x86_l_4143;
	case 16712ULL: goto x86_l_4148;
	case 16715ULL: goto x86_l_414b;
	case 16718ULL: goto x86_l_414e;
	case 16724ULL: goto x86_l_4154;
	case 16729ULL: goto x86_l_4159;
	case 16734ULL: goto x86_l_415e;
	case 16739ULL: goto x86_l_4163;
	case 16744ULL: goto x86_l_4168;
	case 16750ULL: goto x86_l_416e;
	case 16755ULL: goto x86_l_4173;
	case 16760ULL: goto x86_l_4178;
	case 16765ULL: goto x86_l_417d;
	case 16768ULL: goto x86_l_4180;
	case 16771ULL: goto x86_l_4183;
	case 16777ULL: goto x86_l_4189;
	case 16782ULL: goto x86_l_418e;
	case 16787ULL: goto x86_l_4193;
	case 16792ULL: goto x86_l_4198;
	case 16797ULL: goto x86_l_419d;
	case 16803ULL: goto x86_l_41a3;
	case 16808ULL: goto x86_l_41a8;
	case 16813ULL: goto x86_l_41ad;
	case 16818ULL: goto x86_l_41b2;
	case 16821ULL: goto x86_l_41b5;
	case 16824ULL: goto x86_l_41b8;
	case 16830ULL: goto x86_l_41be;
	case 16835ULL: goto x86_l_41c3;
	case 16838ULL: goto x86_l_41c6;
	case 16843ULL: goto x86_l_41cb;
	case 16848ULL: goto x86_l_41d0;
	case 16851ULL: goto x86_l_41d3;
	case 16855ULL: goto x86_l_41d7;
	case 16861ULL: goto x86_l_41dd;
	case 16863ULL: goto x86_l_41df;
	case 16866ULL: goto x86_l_41e2;
	case 16871ULL: goto x86_l_41e7;
	case 16873ULL: goto x86_l_41e9;
	case 16875ULL: goto x86_l_41eb;
	case 16879ULL: goto x86_l_41ef;
	case 16882ULL: goto x86_l_41f2;
	case 16888ULL: goto x86_l_41f8;
	case 16895ULL: goto x86_l_41ff;
	case 16898ULL: goto x86_l_4202;
	case 16904ULL: goto x86_l_4208;
	case 16914ULL: goto x86_l_4212;
	case 16919ULL: goto x86_l_4217;
	case 16929ULL: goto x86_l_4221;
	case 16934ULL: goto x86_l_4226;
	case 16944ULL: goto x86_l_4230;
	case 16949ULL: goto x86_l_4235;
	case 16959ULL: goto x86_l_423f;
	case 16964ULL: goto x86_l_4244;
	case 16974ULL: goto x86_l_424e;
	case 16979ULL: goto x86_l_4253;
	case 16989ULL: goto x86_l_425d;
	case 16994ULL: goto x86_l_4262;
	case 16999ULL: goto x86_l_4267;
	case 17004ULL: goto x86_l_426c;
	case 17009ULL: goto x86_l_4271;
	case 17014ULL: goto x86_l_4276;
	case 17016ULL: goto x86_l_4278;
	case 17018ULL: goto x86_l_427a;
	case 17023ULL: goto x86_l_427f;
	case 17030ULL: goto x86_l_4286;
	case 17034ULL: goto x86_l_428a;
	case 17040ULL: goto x86_l_4290;
	case 17045ULL: goto x86_l_4295;
	case 17048ULL: goto x86_l_4298;
	case 17055ULL: goto x86_l_429f;
	case 17059ULL: goto x86_l_42a3;
	case 17066ULL: goto x86_l_42aa;
	case 17073ULL: goto x86_l_42b1;
	case 17081ULL: goto x86_l_42b9;
	case 17089ULL: goto x86_l_42c1;
	case 17100ULL: goto x86_l_42cc;
	case 17103ULL: goto x86_l_42cf;
	case 17111ULL: goto x86_l_42d7;
	case 17116ULL: goto x86_l_42dc;
	case 17125ULL: goto x86_l_42e5;
	case 17132ULL: goto x86_l_42ec;
	case 17139ULL: goto x86_l_42f3;
	case 17142ULL: goto x86_l_42f6;
	case 17147ULL: goto x86_l_42fb;
	case 17149ULL: goto x86_l_42fd;
	case 17152ULL: goto x86_l_4300;
	case 17154ULL: goto x86_l_4302;
	case 17157ULL: goto x86_l_4305;
	case 17162ULL: goto x86_l_430a;
	case 17170ULL: goto x86_l_4312;
	case 17175ULL: goto x86_l_4317;
	case 17180ULL: goto x86_l_431c;
	case 17183ULL: goto x86_l_431f;
	case 17188ULL: goto x86_l_4324;
	case 17194ULL: goto x86_l_432a;
	case 17199ULL: goto x86_l_432f;
	case 17204ULL: goto x86_l_4334;
	case 17209ULL: goto x86_l_4339;
	case 17212ULL: goto x86_l_433c;
	case 17215ULL: goto x86_l_433f;
	case 17221ULL: goto x86_l_4345;
	case 17224ULL: goto x86_l_4348;
	case 17226ULL: goto x86_l_434a;
	case 17231ULL: goto x86_l_434f;
	case 17237ULL: goto x86_l_4355;
	case 17242ULL: goto x86_l_435a;
	case 17249ULL: goto x86_l_4361;
	case 17252ULL: goto x86_l_4364;
	case 17258ULL: goto x86_l_436a;
	case 17268ULL: goto x86_l_4374;
	case 17273ULL: goto x86_l_4379;
	case 17283ULL: goto x86_l_4383;
	case 17288ULL: goto x86_l_4388;
	case 17298ULL: goto x86_l_4392;
	case 17303ULL: goto x86_l_4397;
	case 17313ULL: goto x86_l_43a1;
	case 17318ULL: goto x86_l_43a6;
	case 17328ULL: goto x86_l_43b0;
	case 17333ULL: goto x86_l_43b5;
	case 17343ULL: goto x86_l_43bf;
	case 17348ULL: goto x86_l_43c4;
	case 17353ULL: goto x86_l_43c9;
	case 17358ULL: goto x86_l_43ce;
	case 17363ULL: goto x86_l_43d3;
	case 17366ULL: goto x86_l_43d6;
	case 17371ULL: goto x86_l_43db;
	case 17373ULL: goto x86_l_43dd;
	case 17375ULL: goto x86_l_43df;
	case 17380ULL: goto x86_l_43e4;
	case 17387ULL: goto x86_l_43eb;
	case 17393ULL: goto x86_l_43f1;
	case 17398ULL: goto x86_l_43f6;
	case 17401ULL: goto x86_l_43f9;
	case 17407ULL: goto x86_l_43ff;
	case 17412ULL: goto x86_l_4404;
	case 17415ULL: goto x86_l_4407;
	case 17420ULL: goto x86_l_440c;
	case 17429ULL: goto x86_l_4415;
	case 17438ULL: goto x86_l_441e;
	case 17443ULL: goto x86_l_4423;
	case 17446ULL: goto x86_l_4426;
	case 17451ULL: goto x86_l_442b;
	case 17456ULL: goto x86_l_4430;
	case 17462ULL: goto x86_l_4436;
	case 17467ULL: goto x86_l_443b;
	case 17472ULL: goto x86_l_4440;
	case 17477ULL: goto x86_l_4445;
	case 17480ULL: goto x86_l_4448;
	case 17485ULL: goto x86_l_444d;
	case 17490ULL: goto x86_l_4452;
	case 17495ULL: goto x86_l_4457;
	case 17500ULL: goto x86_l_445c;
	case 17506ULL: goto x86_l_4462;
	case 17511ULL: goto x86_l_4467;
	case 17516ULL: goto x86_l_446c;
	case 17521ULL: goto x86_l_4471;
	case 17524ULL: goto x86_l_4474;
	case 17530ULL: goto x86_l_447a;
	case 17536ULL: goto x86_l_4480;
	case 17541ULL: goto x86_l_4485;
	case 17544ULL: goto x86_l_4488;
	case 17550ULL: goto x86_l_448e;
	case 17555ULL: goto x86_l_4493;
	case 17558ULL: goto x86_l_4496;
	case 17563ULL: goto x86_l_449b;
	case 17568ULL: goto x86_l_44a0;
	case 17574ULL: goto x86_l_44a6;
	case 17579ULL: goto x86_l_44ab;
	case 17584ULL: goto x86_l_44b0;
	case 17589ULL: goto x86_l_44b5;
	case 17592ULL: goto x86_l_44b8;
	case 17595ULL: goto x86_l_44bb;
	case 17601ULL: goto x86_l_44c1;
	case 17606ULL: goto x86_l_44c6;
	case 17611ULL: goto x86_l_44cb;
	case 17616ULL: goto x86_l_44d0;
	case 17621ULL: goto x86_l_44d5;
	case 17627ULL: goto x86_l_44db;
	case 17632ULL: goto x86_l_44e0;
	case 17637ULL: goto x86_l_44e5;
	case 17642ULL: goto x86_l_44ea;
	case 17645ULL: goto x86_l_44ed;
	case 17648ULL: goto x86_l_44f0;
	case 17654ULL: goto x86_l_44f6;
	case 17659ULL: goto x86_l_44fb;
	case 17664ULL: goto x86_l_4500;
	case 17669ULL: goto x86_l_4505;
	case 17674ULL: goto x86_l_450a;
	case 17680ULL: goto x86_l_4510;
	case 17685ULL: goto x86_l_4515;
	case 17690ULL: goto x86_l_451a;
	case 17695ULL: goto x86_l_451f;
	case 17698ULL: goto x86_l_4522;
	case 17701ULL: goto x86_l_4525;
	case 17707ULL: goto x86_l_452b;
	case 17712ULL: goto x86_l_4530;
	case 17715ULL: goto x86_l_4533;
	case 17720ULL: goto x86_l_4538;
	case 17725ULL: goto x86_l_453d;
	case 17728ULL: goto x86_l_4540;
	case 17732ULL: goto x86_l_4544;
	case 17738ULL: goto x86_l_454a;
	case 17740ULL: goto x86_l_454c;
	case 17743ULL: goto x86_l_454f;
	case 17748ULL: goto x86_l_4554;
	case 17750ULL: goto x86_l_4556;
	case 17752ULL: goto x86_l_4558;
	case 17756ULL: goto x86_l_455c;
	case 17759ULL: goto x86_l_455f;
	case 17765ULL: goto x86_l_4565;
	case 17772ULL: goto x86_l_456c;
	case 17775ULL: goto x86_l_456f;
	case 17781ULL: goto x86_l_4575;
	case 17791ULL: goto x86_l_457f;
	case 17796ULL: goto x86_l_4584;
	case 17806ULL: goto x86_l_458e;
	case 17811ULL: goto x86_l_4593;
	case 17821ULL: goto x86_l_459d;
	case 17826ULL: goto x86_l_45a2;
	case 17836ULL: goto x86_l_45ac;
	case 17841ULL: goto x86_l_45b1;
	case 17851ULL: goto x86_l_45bb;
	case 17856ULL: goto x86_l_45c0;
	case 17866ULL: goto x86_l_45ca;
	case 17871ULL: goto x86_l_45cf;
	case 17876ULL: goto x86_l_45d4;
	case 17881ULL: goto x86_l_45d9;
	case 17886ULL: goto x86_l_45de;
	case 17891ULL: goto x86_l_45e3;
	case 17893ULL: goto x86_l_45e5;
	case 17895ULL: goto x86_l_45e7;
	case 17900ULL: goto x86_l_45ec;
	case 17907ULL: goto x86_l_45f3;
	case 17911ULL: goto x86_l_45f7;
	case 17917ULL: goto x86_l_45fd;
	case 17922ULL: goto x86_l_4602;
	case 17925ULL: goto x86_l_4605;
	case 17932ULL: goto x86_l_460c;
	case 17936ULL: goto x86_l_4610;
	case 17943ULL: goto x86_l_4617;
	case 17950ULL: goto x86_l_461e;
	case 17958ULL: goto x86_l_4626;
	case 17966ULL: goto x86_l_462e;
	case 17977ULL: goto x86_l_4639;
	case 17980ULL: goto x86_l_463c;
	case 17988ULL: goto x86_l_4644;
	case 17993ULL: goto x86_l_4649;
	case 18002ULL: goto x86_l_4652;
	case 18009ULL: goto x86_l_4659;
	case 18016ULL: goto x86_l_4660;
	case 18019ULL: goto x86_l_4663;
	case 18024ULL: goto x86_l_4668;
	case 18026ULL: goto x86_l_466a;
	case 18029ULL: goto x86_l_466d;
	case 18031ULL: goto x86_l_466f;
	case 18034ULL: goto x86_l_4672;
	case 18039ULL: goto x86_l_4677;
	case 18047ULL: goto x86_l_467f;
	case 18052ULL: goto x86_l_4684;
	case 18057ULL: goto x86_l_4689;
	case 18060ULL: goto x86_l_468c;
	case 18065ULL: goto x86_l_4691;
	case 18071ULL: goto x86_l_4697;
	case 18076ULL: goto x86_l_469c;
	case 18081ULL: goto x86_l_46a1;
	case 18086ULL: goto x86_l_46a6;
	case 18089ULL: goto x86_l_46a9;
	case 18092ULL: goto x86_l_46ac;
	case 18098ULL: goto x86_l_46b2;
	case 18101ULL: goto x86_l_46b5;
	case 18103ULL: goto x86_l_46b7;
	case 18108ULL: goto x86_l_46bc;
	case 18114ULL: goto x86_l_46c2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3efa:
	/* 0x3efa: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3eff:
	/* 0x3eff: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3f04:
	/* 0x3f04: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_3f09:
	/* 0x3f09: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f0b:
	/* 0x3f0b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3f0d:
	/* 0x3f0d: jmp    363d <perf_unwind_ruby+0x363d> */
	return 13885ULL;
x86_l_3f12:
	/* 0x3f12: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3f19:
	/* 0x3f19: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_3f1d:
	/* 0x3f1d: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_3f23:
	/* 0x3f23: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f28:
	/* 0x3f28: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3f2b:
	/* 0x3f2b: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3f32:
	/* 0x3f32: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_3f36:
	/* 0x3f36: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3f3d:
	/* 0x3f3d: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f44:
	/* 0x3f44: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_3f4c:
	/* 0x3f4c: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_3f54:
	/* 0x3f54: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_3f5f:
	/* 0x3f5f: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f62:
	/* 0x3f62: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_3f6a:
	/* 0x3f6a: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3f6f:
	/* 0x3f6f: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_3f78:
	/* 0x3f78: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_3f7f:
	/* 0x3f7f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_3f86:
	/* 0x3f86: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_3f89:
	/* 0x3f89: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3f8e:
	/* 0x3f8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f90:
	/* 0x3f90: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f93:
	/* 0x3f93: je     3fed <perf_unwind_ruby+0x3fed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fed;
	}
x86_l_3f95:
	/* 0x3f95: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3f98:
	/* 0x3f98: jmp    363d <perf_unwind_ruby+0x363d> */
	return 13885ULL;
x86_l_3f9d:
	/* 0x3f9d: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fa5:
	/* 0x3fa5: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_3faa:
	/* 0x3faa: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3faf:
	/* 0x3faf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3fb2:
	/* 0x3fb2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3fb7:
	/* 0x3fb7: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_3fbd:
	/* 0x3fbd: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_3fc2:
	/* 0x3fc2: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3fc7:
	/* 0x3fc7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3fcc:
	/* 0x3fcc: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3fcf:
	/* 0x3fcf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3fd2:
	/* 0x3fd2: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_3fd8:
	/* 0x3fd8: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fdb:
	/* 0x3fdb: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_3fdd:
	/* 0x3fdd: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_3fe2:
	/* 0x3fe2: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_3fe8:
	/* 0x3fe8: jmp    3d17 <perf_unwind_ruby+0x3d17> */
	return 15639ULL;
x86_l_3fed:
	/* 0x3fed: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3ff4:
	/* 0x3ff4: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ff7:
	/* 0x3ff7: je     363d <perf_unwind_ruby+0x363d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13885ULL;
	}
x86_l_3ffd:
	/* 0x3ffd: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_4007:
	/* 0x4007: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_400c:
	/* 0x400c: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_4016:
	/* 0x4016: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_401b:
	/* 0x401b: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_4025:
	/* 0x4025: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_402a:
	/* 0x402a: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_4034:
	/* 0x4034: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4039:
	/* 0x4039: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_4043:
	/* 0x4043: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4048:
	/* 0x4048: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_4052:
	/* 0x4052: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4057:
	/* 0x4057: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_405c:
	/* 0x405c: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_4061:
	/* 0x4061: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4066:
	/* 0x4066: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4069:
	/* 0x4069: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_406e:
	/* 0x406e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4070:
	/* 0x4070: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4072:
	/* 0x4072: jmp    363d <perf_unwind_ruby+0x363d> */
	return 13885ULL;
x86_l_4077:
	/* 0x4077: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_407e:
	/* 0x407e: jae    430a <perf_unwind_ruby+0x430a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_430a;
	}
x86_l_4084:
	/* 0x4084: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4089:
	/* 0x4089: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_408c:
	/* 0x408c: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_4092:
	/* 0x4092: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_4097:
	/* 0x4097: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_409a:
	/* 0x409a: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_409f:
	/* 0x409f: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_40a8:
	/* 0x40a8: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_40b1:
	/* 0x40b1: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_40b6:
	/* 0x40b6: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_40b9:
	/* 0x40b9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_40be:
	/* 0x40be: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_40c3:
	/* 0x40c3: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_40c9:
	/* 0x40c9: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_40ce:
	/* 0x40ce: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_40d3:
	/* 0x40d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40d8:
	/* 0x40d8: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_40db:
	/* 0x40db: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_40e0:
	/* 0x40e0: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_40e5:
	/* 0x40e5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_40ea:
	/* 0x40ea: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_40ef:
	/* 0x40ef: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_40f5:
	/* 0x40f5: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_40fa:
	/* 0x40fa: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_40ff:
	/* 0x40ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4104:
	/* 0x4104: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4107:
	/* 0x4107: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_410d:
	/* 0x410d: je     43e4 <perf_unwind_ruby+0x43e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43e4;
	}
x86_l_4113:
	/* 0x4113: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4118:
	/* 0x4118: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_411b:
	/* 0x411b: je     43e4 <perf_unwind_ruby+0x43e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43e4;
	}
x86_l_4121:
	/* 0x4121: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_4126:
	/* 0x4126: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4129:
	/* 0x4129: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_412e:
	/* 0x412e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4133:
	/* 0x4133: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4139:
	/* 0x4139: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_413e:
	/* 0x413e: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_4143:
	/* 0x4143: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4148:
	/* 0x4148: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_414b:
	/* 0x414b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_414e:
	/* 0x414e: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_4154:
	/* 0x4154: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_4159:
	/* 0x4159: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_415e:
	/* 0x415e: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4163:
	/* 0x4163: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4168:
	/* 0x4168: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_416e:
	/* 0x416e: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_4173:
	/* 0x4173: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4178:
	/* 0x4178: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_417d:
	/* 0x417d: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4180:
	/* 0x4180: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4183:
	/* 0x4183: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_4189:
	/* 0x4189: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_418e:
	/* 0x418e: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4193:
	/* 0x4193: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_4198:
	/* 0x4198: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_419d:
	/* 0x419d: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_41a3:
	/* 0x41a3: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_41a8:
	/* 0x41a8: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_41ad:
	/* 0x41ad: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_41b2:
	/* 0x41b2: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_41b5:
	/* 0x41b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_41b8:
	/* 0x41b8: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_41be:
	/* 0x41be: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_41c3:
	/* 0x41c3: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_41c6:
	/* 0x41c6: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_41cb:
	/* 0x41cb: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_41d0:
	/* 0x41d0: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_41d3:
	/* 0x41d3: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_41d7:
	/* 0x41d7: je     4b1b <perf_unwind_ruby+0x4b1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19227ULL;
	}
x86_l_41dd:
	/* 0x41dd: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_41df:
	/* 0x41df: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_41e2:
	/* 0x41e2: jmp    4b1f <perf_unwind_ruby+0x4b1f> */
	return 19231ULL;
x86_l_41e7:
	/* 0x41e7: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_41e9:
	/* 0x41e9: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_41eb:
	/* 0x41eb: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_41ef:
	/* 0x41ef: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_41f2:
	/* 0x41f2: jbe    427f <perf_unwind_ruby+0x427f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_427f;
	}
x86_l_41f8:
	/* 0x41f8: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_41ff:
	/* 0x41ff: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4202:
	/* 0x4202: je     39aa <perf_unwind_ruby+0x39aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14762ULL;
	}
x86_l_4208:
	/* 0x4208: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_4212:
	/* 0x4212: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_4217:
	/* 0x4217: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_4221:
	/* 0x4221: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4226:
	/* 0x4226: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_4230:
	/* 0x4230: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4235:
	/* 0x4235: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_423f:
	/* 0x423f: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4244:
	/* 0x4244: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_424e:
	/* 0x424e: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4253:
	/* 0x4253: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_425d:
	/* 0x425d: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4262:
	/* 0x4262: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4267:
	/* 0x4267: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_426c:
	/* 0x426c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4271:
	/* 0x4271: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_4276:
	/* 0x4276: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4278:
	/* 0x4278: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_427a:
	/* 0x427a: jmp    39aa <perf_unwind_ruby+0x39aa> */
	return 14762ULL;
x86_l_427f:
	/* 0x427f: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_4286:
	/* 0x4286: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_428a:
	/* 0x428a: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_4290:
	/* 0x4290: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4295:
	/* 0x4295: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4298:
	/* 0x4298: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_429f:
	/* 0x429f: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_42a3:
	/* 0x42a3: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_42aa:
	/* 0x42aa: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42b1:
	/* 0x42b1: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_42b9:
	/* 0x42b9: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_42c1:
	/* 0x42c1: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_42cc:
	/* 0x42cc: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42cf:
	/* 0x42cf: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_42d7:
	/* 0x42d7: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_42dc:
	/* 0x42dc: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_42e5:
	/* 0x42e5: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_42ec:
	/* 0x42ec: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_42f3:
	/* 0x42f3: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_42f6:
	/* 0x42f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_42fb:
	/* 0x42fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42fd:
	/* 0x42fd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4300:
	/* 0x4300: je     435a <perf_unwind_ruby+0x435a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_435a;
	}
x86_l_4302:
	/* 0x4302: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4305:
	/* 0x4305: jmp    39aa <perf_unwind_ruby+0x39aa> */
	return 14762ULL;
x86_l_430a:
	/* 0x430a: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4312:
	/* 0x4312: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_4317:
	/* 0x4317: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_431c:
	/* 0x431c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_431f:
	/* 0x431f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4324:
	/* 0x4324: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_432a:
	/* 0x432a: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_432f:
	/* 0x432f: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4334:
	/* 0x4334: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4339:
	/* 0x4339: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_433c:
	/* 0x433c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_433f:
	/* 0x433f: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_4345:
	/* 0x4345: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4348:
	/* 0x4348: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_434a:
	/* 0x434a: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_434f:
	/* 0x434f: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_4355:
	/* 0x4355: jmp    4084 <perf_unwind_ruby+0x4084> */
	goto x86_l_4084;
x86_l_435a:
	/* 0x435a: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4361:
	/* 0x4361: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4364:
	/* 0x4364: je     39aa <perf_unwind_ruby+0x39aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14762ULL;
	}
x86_l_436a:
	/* 0x436a: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_4374:
	/* 0x4374: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_4379:
	/* 0x4379: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_4383:
	/* 0x4383: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4388:
	/* 0x4388: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_4392:
	/* 0x4392: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4397:
	/* 0x4397: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_43a1:
	/* 0x43a1: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_43a6:
	/* 0x43a6: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_43b0:
	/* 0x43b0: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_43b5:
	/* 0x43b5: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_43bf:
	/* 0x43bf: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_43c4:
	/* 0x43c4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_43c9:
	/* 0x43c9: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_43ce:
	/* 0x43ce: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_43d3:
	/* 0x43d3: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43d6:
	/* 0x43d6: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_43db:
	/* 0x43db: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_43dd:
	/* 0x43dd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_43df:
	/* 0x43df: jmp    39aa <perf_unwind_ruby+0x39aa> */
	return 14762ULL;
x86_l_43e4:
	/* 0x43e4: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_43eb:
	/* 0x43eb: jae    4677 <perf_unwind_ruby+0x4677> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4677;
	}
x86_l_43f1:
	/* 0x43f1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43f6:
	/* 0x43f6: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_43f9:
	/* 0x43f9: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_43ff:
	/* 0x43ff: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_4404:
	/* 0x4404: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4407:
	/* 0x4407: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_440c:
	/* 0x440c: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4415:
	/* 0x4415: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_441e:
	/* 0x441e: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_4423:
	/* 0x4423: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4426:
	/* 0x4426: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_442b:
	/* 0x442b: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_4430:
	/* 0x4430: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4436:
	/* 0x4436: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_443b:
	/* 0x443b: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4440:
	/* 0x4440: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4445:
	/* 0x4445: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4448:
	/* 0x4448: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_444d:
	/* 0x444d: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4452:
	/* 0x4452: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4457:
	/* 0x4457: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_445c:
	/* 0x445c: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4462:
	/* 0x4462: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_4467:
	/* 0x4467: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_446c:
	/* 0x446c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4471:
	/* 0x4471: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4474:
	/* 0x4474: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_447a:
	/* 0x447a: je     4751 <perf_unwind_ruby+0x4751> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18257ULL;
	}
x86_l_4480:
	/* 0x4480: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4485:
	/* 0x4485: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4488:
	/* 0x4488: je     4751 <perf_unwind_ruby+0x4751> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18257ULL;
	}
x86_l_448e:
	/* 0x448e: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_4493:
	/* 0x4493: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4496:
	/* 0x4496: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_449b:
	/* 0x449b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_44a0:
	/* 0x44a0: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_44a6:
	/* 0x44a6: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_44ab:
	/* 0x44ab: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_44b0:
	/* 0x44b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44b5:
	/* 0x44b5: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_44b8:
	/* 0x44b8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_44bb:
	/* 0x44bb: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_44c1:
	/* 0x44c1: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_44c6:
	/* 0x44c6: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_44cb:
	/* 0x44cb: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_44d0:
	/* 0x44d0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_44d5:
	/* 0x44d5: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_44db:
	/* 0x44db: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_44e0:
	/* 0x44e0: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_44e5:
	/* 0x44e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44ea:
	/* 0x44ea: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_44ed:
	/* 0x44ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_44f0:
	/* 0x44f0: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_44f6:
	/* 0x44f6: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_44fb:
	/* 0x44fb: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4500:
	/* 0x4500: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_4505:
	/* 0x4505: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_450a:
	/* 0x450a: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4510:
	/* 0x4510: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_4515:
	/* 0x4515: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_451a:
	/* 0x451a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_451f:
	/* 0x451f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4522:
	/* 0x4522: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4525:
	/* 0x4525: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_452b:
	/* 0x452b: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4530:
	/* 0x4530: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_4533:
	/* 0x4533: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_4538:
	/* 0x4538: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_453d:
	/* 0x453d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4540:
	/* 0x4540: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_4544:
	/* 0x4544: je     4c42 <perf_unwind_ruby+0x4c42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19522ULL;
	}
x86_l_454a:
	/* 0x454a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_454c:
	/* 0x454c: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_454f:
	/* 0x454f: jmp    4c46 <perf_unwind_ruby+0x4c46> */
	return 19526ULL;
x86_l_4554:
	/* 0x4554: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4556:
	/* 0x4556: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_4558:
	/* 0x4558: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_455c:
	/* 0x455c: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_455f:
	/* 0x455f: jbe    45ec <perf_unwind_ruby+0x45ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_45ec;
	}
x86_l_4565:
	/* 0x4565: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_456c:
	/* 0x456c: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_456f:
	/* 0x456f: je     3d17 <perf_unwind_ruby+0x3d17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15639ULL;
	}
x86_l_4575:
	/* 0x4575: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_457f:
	/* 0x457f: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_4584:
	/* 0x4584: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_458e:
	/* 0x458e: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4593:
	/* 0x4593: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_459d:
	/* 0x459d: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_45a2:
	/* 0x45a2: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_45ac:
	/* 0x45ac: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_45b1:
	/* 0x45b1: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_45bb:
	/* 0x45bb: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_45c0:
	/* 0x45c0: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_45ca:
	/* 0x45ca: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_45cf:
	/* 0x45cf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_45d4:
	/* 0x45d4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_45d9:
	/* 0x45d9: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_45de:
	/* 0x45de: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_45e3:
	/* 0x45e3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_45e5:
	/* 0x45e5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_45e7:
	/* 0x45e7: jmp    3d17 <perf_unwind_ruby+0x3d17> */
	return 15639ULL;
x86_l_45ec:
	/* 0x45ec: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_45f3:
	/* 0x45f3: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_45f7:
	/* 0x45f7: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_45fd:
	/* 0x45fd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4602:
	/* 0x4602: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4605:
	/* 0x4605: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_460c:
	/* 0x460c: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_4610:
	/* 0x4610: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_4617:
	/* 0x4617: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_461e:
	/* 0x461e: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_4626:
	/* 0x4626: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_462e:
	/* 0x462e: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_4639:
	/* 0x4639: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_463c:
	/* 0x463c: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_4644:
	/* 0x4644: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4649:
	/* 0x4649: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_4652:
	/* 0x4652: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_4659:
	/* 0x4659: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_4660:
	/* 0x4660: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4663:
	/* 0x4663: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4668:
	/* 0x4668: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_466a:
	/* 0x466a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_466d:
	/* 0x466d: je     46c7 <perf_unwind_ruby+0x46c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18119ULL;
	}
x86_l_466f:
	/* 0x466f: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4672:
	/* 0x4672: jmp    3d17 <perf_unwind_ruby+0x3d17> */
	return 15639ULL;
x86_l_4677:
	/* 0x4677: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_467f:
	/* 0x467f: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_4684:
	/* 0x4684: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4689:
	/* 0x4689: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_468c:
	/* 0x468c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4691:
	/* 0x4691: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4697:
	/* 0x4697: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_469c:
	/* 0x469c: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_46a1:
	/* 0x46a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46a6:
	/* 0x46a6: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_46a9:
	/* 0x46a9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_46ac:
	/* 0x46ac: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_46b2:
	/* 0x46b2: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46b5:
	/* 0x46b5: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_46b7:
	/* 0x46b7: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_46bc:
	/* 0x46bc: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_46c2:
	/* 0x46c2: jmp    43f1 <perf_unwind_ruby+0x43f1> */
	goto x86_l_43f1;
	return 18119ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 18119ULL: goto x86_l_46c7;
	case 18126ULL: goto x86_l_46ce;
	case 18129ULL: goto x86_l_46d1;
	case 18135ULL: goto x86_l_46d7;
	case 18145ULL: goto x86_l_46e1;
	case 18150ULL: goto x86_l_46e6;
	case 18160ULL: goto x86_l_46f0;
	case 18165ULL: goto x86_l_46f5;
	case 18175ULL: goto x86_l_46ff;
	case 18180ULL: goto x86_l_4704;
	case 18190ULL: goto x86_l_470e;
	case 18195ULL: goto x86_l_4713;
	case 18205ULL: goto x86_l_471d;
	case 18210ULL: goto x86_l_4722;
	case 18220ULL: goto x86_l_472c;
	case 18225ULL: goto x86_l_4731;
	case 18230ULL: goto x86_l_4736;
	case 18235ULL: goto x86_l_473b;
	case 18240ULL: goto x86_l_4740;
	case 18243ULL: goto x86_l_4743;
	case 18248ULL: goto x86_l_4748;
	case 18250ULL: goto x86_l_474a;
	case 18252ULL: goto x86_l_474c;
	case 18257ULL: goto x86_l_4751;
	case 18264ULL: goto x86_l_4758;
	case 18270ULL: goto x86_l_475e;
	case 18275ULL: goto x86_l_4763;
	case 18278ULL: goto x86_l_4766;
	case 18284ULL: goto x86_l_476c;
	case 18289ULL: goto x86_l_4771;
	case 18292ULL: goto x86_l_4774;
	case 18297ULL: goto x86_l_4779;
	case 18306ULL: goto x86_l_4782;
	case 18315ULL: goto x86_l_478b;
	case 18320ULL: goto x86_l_4790;
	case 18323ULL: goto x86_l_4793;
	case 18328ULL: goto x86_l_4798;
	case 18333ULL: goto x86_l_479d;
	case 18339ULL: goto x86_l_47a3;
	case 18344ULL: goto x86_l_47a8;
	case 18349ULL: goto x86_l_47ad;
	case 18354ULL: goto x86_l_47b2;
	case 18357ULL: goto x86_l_47b5;
	case 18362ULL: goto x86_l_47ba;
	case 18367ULL: goto x86_l_47bf;
	case 18372ULL: goto x86_l_47c4;
	case 18377ULL: goto x86_l_47c9;
	case 18383ULL: goto x86_l_47cf;
	case 18388ULL: goto x86_l_47d4;
	case 18393ULL: goto x86_l_47d9;
	case 18398ULL: goto x86_l_47de;
	case 18401ULL: goto x86_l_47e1;
	case 18407ULL: goto x86_l_47e7;
	case 18413ULL: goto x86_l_47ed;
	case 18418ULL: goto x86_l_47f2;
	case 18421ULL: goto x86_l_47f5;
	case 18427ULL: goto x86_l_47fb;
	case 18432ULL: goto x86_l_4800;
	case 18435ULL: goto x86_l_4803;
	case 18440ULL: goto x86_l_4808;
	case 18445ULL: goto x86_l_480d;
	case 18451ULL: goto x86_l_4813;
	case 18456ULL: goto x86_l_4818;
	case 18461ULL: goto x86_l_481d;
	case 18466ULL: goto x86_l_4822;
	case 18469ULL: goto x86_l_4825;
	case 18472ULL: goto x86_l_4828;
	case 18478ULL: goto x86_l_482e;
	case 18483ULL: goto x86_l_4833;
	case 18488ULL: goto x86_l_4838;
	case 18493ULL: goto x86_l_483d;
	case 18498ULL: goto x86_l_4842;
	case 18504ULL: goto x86_l_4848;
	case 18509ULL: goto x86_l_484d;
	case 18514ULL: goto x86_l_4852;
	case 18519ULL: goto x86_l_4857;
	case 18522ULL: goto x86_l_485a;
	case 18525ULL: goto x86_l_485d;
	case 18531ULL: goto x86_l_4863;
	case 18536ULL: goto x86_l_4868;
	case 18541ULL: goto x86_l_486d;
	case 18546ULL: goto x86_l_4872;
	case 18551ULL: goto x86_l_4877;
	case 18557ULL: goto x86_l_487d;
	case 18562ULL: goto x86_l_4882;
	case 18567ULL: goto x86_l_4887;
	case 18572ULL: goto x86_l_488c;
	case 18575ULL: goto x86_l_488f;
	case 18578ULL: goto x86_l_4892;
	case 18584ULL: goto x86_l_4898;
	case 18589ULL: goto x86_l_489d;
	case 18592ULL: goto x86_l_48a0;
	case 18597ULL: goto x86_l_48a5;
	case 18602ULL: goto x86_l_48aa;
	case 18605ULL: goto x86_l_48ad;
	case 18609ULL: goto x86_l_48b1;
	case 18615ULL: goto x86_l_48b7;
	case 18617ULL: goto x86_l_48b9;
	case 18620ULL: goto x86_l_48bc;
	case 18625ULL: goto x86_l_48c1;
	case 18627ULL: goto x86_l_48c3;
	case 18629ULL: goto x86_l_48c5;
	case 18633ULL: goto x86_l_48c9;
	case 18636ULL: goto x86_l_48cc;
	case 18642ULL: goto x86_l_48d2;
	case 18649ULL: goto x86_l_48d9;
	case 18652ULL: goto x86_l_48dc;
	case 18658ULL: goto x86_l_48e2;
	case 18668ULL: goto x86_l_48ec;
	case 18673ULL: goto x86_l_48f1;
	case 18683ULL: goto x86_l_48fb;
	case 18688ULL: goto x86_l_4900;
	case 18698ULL: goto x86_l_490a;
	case 18703ULL: goto x86_l_490f;
	case 18713ULL: goto x86_l_4919;
	case 18718ULL: goto x86_l_491e;
	case 18728ULL: goto x86_l_4928;
	case 18733ULL: goto x86_l_492d;
	case 18743ULL: goto x86_l_4937;
	case 18748ULL: goto x86_l_493c;
	case 18753ULL: goto x86_l_4941;
	case 18758ULL: goto x86_l_4946;
	case 18763ULL: goto x86_l_494b;
	case 18768ULL: goto x86_l_4950;
	case 18770ULL: goto x86_l_4952;
	case 18772ULL: goto x86_l_4954;
	case 18777ULL: goto x86_l_4959;
	case 18784ULL: goto x86_l_4960;
	case 18788ULL: goto x86_l_4964;
	case 18794ULL: goto x86_l_496a;
	case 18799ULL: goto x86_l_496f;
	case 18802ULL: goto x86_l_4972;
	case 18809ULL: goto x86_l_4979;
	case 18813ULL: goto x86_l_497d;
	case 18820ULL: goto x86_l_4984;
	case 18827ULL: goto x86_l_498b;
	case 18835ULL: goto x86_l_4993;
	case 18843ULL: goto x86_l_499b;
	case 18854ULL: goto x86_l_49a6;
	case 18857ULL: goto x86_l_49a9;
	case 18865ULL: goto x86_l_49b1;
	case 18870ULL: goto x86_l_49b6;
	case 18879ULL: goto x86_l_49bf;
	case 18886ULL: goto x86_l_49c6;
	case 18893ULL: goto x86_l_49cd;
	case 18896ULL: goto x86_l_49d0;
	case 18901ULL: goto x86_l_49d5;
	case 18903ULL: goto x86_l_49d7;
	case 18906ULL: goto x86_l_49da;
	case 18908ULL: goto x86_l_49dc;
	case 18911ULL: goto x86_l_49df;
	case 18916ULL: goto x86_l_49e4;
	case 18924ULL: goto x86_l_49ec;
	case 18929ULL: goto x86_l_49f1;
	case 18934ULL: goto x86_l_49f6;
	case 18937ULL: goto x86_l_49f9;
	case 18942ULL: goto x86_l_49fe;
	case 18948ULL: goto x86_l_4a04;
	case 18953ULL: goto x86_l_4a09;
	case 18958ULL: goto x86_l_4a0e;
	case 18963ULL: goto x86_l_4a13;
	case 18966ULL: goto x86_l_4a16;
	case 18969ULL: goto x86_l_4a19;
	case 18975ULL: goto x86_l_4a1f;
	case 18978ULL: goto x86_l_4a22;
	case 18980ULL: goto x86_l_4a24;
	case 18985ULL: goto x86_l_4a29;
	case 18991ULL: goto x86_l_4a2f;
	case 18996ULL: goto x86_l_4a34;
	case 19003ULL: goto x86_l_4a3b;
	case 19006ULL: goto x86_l_4a3e;
	case 19012ULL: goto x86_l_4a44;
	case 19022ULL: goto x86_l_4a4e;
	case 19027ULL: goto x86_l_4a53;
	case 19037ULL: goto x86_l_4a5d;
	case 19042ULL: goto x86_l_4a62;
	case 19052ULL: goto x86_l_4a6c;
	case 19057ULL: goto x86_l_4a71;
	case 19067ULL: goto x86_l_4a7b;
	case 19072ULL: goto x86_l_4a80;
	case 19082ULL: goto x86_l_4a8a;
	case 19087ULL: goto x86_l_4a8f;
	case 19097ULL: goto x86_l_4a99;
	case 19102ULL: goto x86_l_4a9e;
	case 19107ULL: goto x86_l_4aa3;
	case 19112ULL: goto x86_l_4aa8;
	case 19117ULL: goto x86_l_4aad;
	case 19120ULL: goto x86_l_4ab0;
	case 19125ULL: goto x86_l_4ab5;
	case 19127ULL: goto x86_l_4ab7;
	case 19129ULL: goto x86_l_4ab9;
	case 19134ULL: goto x86_l_4abe;
	case 19141ULL: goto x86_l_4ac5;
	case 19147ULL: goto x86_l_4acb;
	case 19155ULL: goto x86_l_4ad3;
	case 19160ULL: goto x86_l_4ad8;
	case 19165ULL: goto x86_l_4add;
	case 19168ULL: goto x86_l_4ae0;
	case 19173ULL: goto x86_l_4ae5;
	case 19179ULL: goto x86_l_4aeb;
	case 19184ULL: goto x86_l_4af0;
	case 19189ULL: goto x86_l_4af5;
	case 19194ULL: goto x86_l_4afa;
	case 19197ULL: goto x86_l_4afd;
	case 19200ULL: goto x86_l_4b00;
	case 19206ULL: goto x86_l_4b06;
	case 19209ULL: goto x86_l_4b09;
	case 19211ULL: goto x86_l_4b0b;
	case 19216ULL: goto x86_l_4b10;
	case 19222ULL: goto x86_l_4b16;
	case 19227ULL: goto x86_l_4b1b;
	case 19229ULL: goto x86_l_4b1d;
	case 19231ULL: goto x86_l_4b1f;
	case 19235ULL: goto x86_l_4b23;
	case 19238ULL: goto x86_l_4b26;
	case 19244ULL: goto x86_l_4b2c;
	case 19251ULL: goto x86_l_4b33;
	case 19254ULL: goto x86_l_4b36;
	case 19260ULL: goto x86_l_4b3c;
	case 19270ULL: goto x86_l_4b46;
	case 19275ULL: goto x86_l_4b4b;
	case 19285ULL: goto x86_l_4b55;
	case 19290ULL: goto x86_l_4b5a;
	case 19300ULL: goto x86_l_4b64;
	case 19305ULL: goto x86_l_4b69;
	case 19315ULL: goto x86_l_4b73;
	case 19320ULL: goto x86_l_4b78;
	case 19330ULL: goto x86_l_4b82;
	case 19335ULL: goto x86_l_4b87;
	case 19345ULL: goto x86_l_4b91;
	case 19350ULL: goto x86_l_4b96;
	case 19355ULL: goto x86_l_4b9b;
	case 19360ULL: goto x86_l_4ba0;
	case 19365ULL: goto x86_l_4ba5;
	case 19370ULL: goto x86_l_4baa;
	case 19372ULL: goto x86_l_4bac;
	case 19374ULL: goto x86_l_4bae;
	case 19379ULL: goto x86_l_4bb3;
	case 19386ULL: goto x86_l_4bba;
	case 19390ULL: goto x86_l_4bbe;
	case 19396ULL: goto x86_l_4bc4;
	case 19401ULL: goto x86_l_4bc9;
	case 19404ULL: goto x86_l_4bcc;
	case 19411ULL: goto x86_l_4bd3;
	case 19415ULL: goto x86_l_4bd7;
	case 19422ULL: goto x86_l_4bde;
	case 19429ULL: goto x86_l_4be5;
	case 19437ULL: goto x86_l_4bed;
	case 19445ULL: goto x86_l_4bf5;
	case 19456ULL: goto x86_l_4c00;
	case 19459ULL: goto x86_l_4c03;
	case 19467ULL: goto x86_l_4c0b;
	case 19472ULL: goto x86_l_4c10;
	case 19481ULL: goto x86_l_4c19;
	case 19488ULL: goto x86_l_4c20;
	case 19495ULL: goto x86_l_4c27;
	case 19498ULL: goto x86_l_4c2a;
	case 19503ULL: goto x86_l_4c2f;
	case 19505ULL: goto x86_l_4c31;
	case 19508ULL: goto x86_l_4c34;
	case 19514ULL: goto x86_l_4c3a;
	case 19517ULL: goto x86_l_4c3d;
	case 19522ULL: goto x86_l_4c42;
	case 19524ULL: goto x86_l_4c44;
	case 19526ULL: goto x86_l_4c46;
	case 19530ULL: goto x86_l_4c4a;
	case 19533ULL: goto x86_l_4c4d;
	case 19539ULL: goto x86_l_4c53;
	case 19546ULL: goto x86_l_4c5a;
	case 19549ULL: goto x86_l_4c5d;
	case 19555ULL: goto x86_l_4c63;
	case 19565ULL: goto x86_l_4c6d;
	case 19570ULL: goto x86_l_4c72;
	case 19580ULL: goto x86_l_4c7c;
	case 19585ULL: goto x86_l_4c81;
	case 19595ULL: goto x86_l_4c8b;
	case 19600ULL: goto x86_l_4c90;
	case 19610ULL: goto x86_l_4c9a;
	case 19615ULL: goto x86_l_4c9f;
	case 19625ULL: goto x86_l_4ca9;
	case 19630ULL: goto x86_l_4cae;
	case 19640ULL: goto x86_l_4cb8;
	case 19645ULL: goto x86_l_4cbd;
	case 19650ULL: goto x86_l_4cc2;
	case 19655ULL: goto x86_l_4cc7;
	case 19660ULL: goto x86_l_4ccc;
	case 19665ULL: goto x86_l_4cd1;
	case 19667ULL: goto x86_l_4cd3;
	case 19669ULL: goto x86_l_4cd5;
	case 19674ULL: goto x86_l_4cda;
	case 19676ULL: goto x86_l_4cdc;
	case 19678ULL: goto x86_l_4cde;
	case 19682ULL: goto x86_l_4ce2;
	case 19685ULL: goto x86_l_4ce5;
	case 19691ULL: goto x86_l_4ceb;
	case 19698ULL: goto x86_l_4cf2;
	case 19701ULL: goto x86_l_4cf5;
	case 19707ULL: goto x86_l_4cfb;
	case 19717ULL: goto x86_l_4d05;
	case 19722ULL: goto x86_l_4d0a;
	case 19732ULL: goto x86_l_4d14;
	case 19737ULL: goto x86_l_4d19;
	case 19747ULL: goto x86_l_4d23;
	case 19752ULL: goto x86_l_4d28;
	case 19762ULL: goto x86_l_4d32;
	case 19767ULL: goto x86_l_4d37;
	case 19777ULL: goto x86_l_4d41;
	case 19782ULL: goto x86_l_4d46;
	case 19792ULL: goto x86_l_4d50;
	case 19797ULL: goto x86_l_4d55;
	case 19802ULL: goto x86_l_4d5a;
	case 19807ULL: goto x86_l_4d5f;
	case 19812ULL: goto x86_l_4d64;
	case 19817ULL: goto x86_l_4d69;
	case 19819ULL: goto x86_l_4d6b;
	case 19821ULL: goto x86_l_4d6d;
	case 19826ULL: goto x86_l_4d72;
	case 19833ULL: goto x86_l_4d79;
	case 19836ULL: goto x86_l_4d7c;
	case 19842ULL: goto x86_l_4d82;
	case 19852ULL: goto x86_l_4d8c;
	case 19857ULL: goto x86_l_4d91;
	case 19867ULL: goto x86_l_4d9b;
	case 19872ULL: goto x86_l_4da0;
	case 19882ULL: goto x86_l_4daa;
	case 19887ULL: goto x86_l_4daf;
	case 19897ULL: goto x86_l_4db9;
	case 19902ULL: goto x86_l_4dbe;
	case 19912ULL: goto x86_l_4dc8;
	case 19917ULL: goto x86_l_4dcd;
	case 19927ULL: goto x86_l_4dd7;
	case 19932ULL: goto x86_l_4ddc;
	case 19937ULL: goto x86_l_4de1;
	case 19942ULL: goto x86_l_4de6;
	case 19947ULL: goto x86_l_4deb;
	case 19950ULL: goto x86_l_4dee;
	case 19955ULL: goto x86_l_4df3;
	case 19957ULL: goto x86_l_4df5;
	case 19959ULL: goto x86_l_4df7;
	case 19964ULL: goto x86_l_4dfc;
	case 19971ULL: goto x86_l_4e03;
	case 19975ULL: goto x86_l_4e07;
	case 19981ULL: goto x86_l_4e0d;
	case 19986ULL: goto x86_l_4e12;
	case 19989ULL: goto x86_l_4e15;
	case 19996ULL: goto x86_l_4e1c;
	case 20000ULL: goto x86_l_4e20;
	case 20007ULL: goto x86_l_4e27;
	case 20014ULL: goto x86_l_4e2e;
	case 20022ULL: goto x86_l_4e36;
	case 20030ULL: goto x86_l_4e3e;
	case 20041ULL: goto x86_l_4e49;
	case 20044ULL: goto x86_l_4e4c;
	case 20052ULL: goto x86_l_4e54;
	case 20057ULL: goto x86_l_4e59;
	case 20066ULL: goto x86_l_4e62;
	case 20073ULL: goto x86_l_4e69;
	case 20080ULL: goto x86_l_4e70;
	case 20083ULL: goto x86_l_4e73;
	case 20088ULL: goto x86_l_4e78;
	case 20090ULL: goto x86_l_4e7a;
	case 20093ULL: goto x86_l_4e7d;
	case 20099ULL: goto x86_l_4e83;
	case 20102ULL: goto x86_l_4e86;
	case 20107ULL: goto x86_l_4e8b;
	case 20114ULL: goto x86_l_4e92;
	case 20118ULL: goto x86_l_4e96;
	case 20124ULL: goto x86_l_4e9c;
	case 20129ULL: goto x86_l_4ea1;
	case 20132ULL: goto x86_l_4ea4;
	case 20139ULL: goto x86_l_4eab;
	case 20143ULL: goto x86_l_4eaf;
	case 20150ULL: goto x86_l_4eb6;
	case 20157ULL: goto x86_l_4ebd;
	case 20165ULL: goto x86_l_4ec5;
	case 20173ULL: goto x86_l_4ecd;
	case 20184ULL: goto x86_l_4ed8;
	case 20187ULL: goto x86_l_4edb;
	case 20195ULL: goto x86_l_4ee3;
	case 20200ULL: goto x86_l_4ee8;
	case 20209ULL: goto x86_l_4ef1;
	case 20216ULL: goto x86_l_4ef8;
	case 20223ULL: goto x86_l_4eff;
	case 20226ULL: goto x86_l_4f02;
	default: return 0xffffffffffffffffULL;
	}
x86_l_46c7:
	/* 0x46c7: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_46ce:
	/* 0x46ce: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46d1:
	/* 0x46d1: je     3d17 <perf_unwind_ruby+0x3d17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15639ULL;
	}
x86_l_46d7:
	/* 0x46d7: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_46e1:
	/* 0x46e1: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_46e6:
	/* 0x46e6: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_46f0:
	/* 0x46f0: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_46f5:
	/* 0x46f5: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_46ff:
	/* 0x46ff: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4704:
	/* 0x4704: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_470e:
	/* 0x470e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4713:
	/* 0x4713: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_471d:
	/* 0x471d: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4722:
	/* 0x4722: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_472c:
	/* 0x472c: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4731:
	/* 0x4731: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4736:
	/* 0x4736: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_473b:
	/* 0x473b: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4740:
	/* 0x4740: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4743:
	/* 0x4743: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_4748:
	/* 0x4748: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_474a:
	/* 0x474a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_474c:
	/* 0x474c: jmp    3d17 <perf_unwind_ruby+0x3d17> */
	return 15639ULL;
x86_l_4751:
	/* 0x4751: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_4758:
	/* 0x4758: jae    49e4 <perf_unwind_ruby+0x49e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_49e4;
	}
x86_l_475e:
	/* 0x475e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4763:
	/* 0x4763: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_4766:
	/* 0x4766: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_476c:
	/* 0x476c: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_4771:
	/* 0x4771: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4774:
	/* 0x4774: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4779:
	/* 0x4779: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4782:
	/* 0x4782: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_478b:
	/* 0x478b: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_4790:
	/* 0x4790: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4793:
	/* 0x4793: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4798:
	/* 0x4798: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_479d:
	/* 0x479d: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_47a3:
	/* 0x47a3: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_47a8:
	/* 0x47a8: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_47ad:
	/* 0x47ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47b2:
	/* 0x47b2: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_47b5:
	/* 0x47b5: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_47ba:
	/* 0x47ba: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_47bf:
	/* 0x47bf: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_47c4:
	/* 0x47c4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_47c9:
	/* 0x47c9: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_47cf:
	/* 0x47cf: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_47d4:
	/* 0x47d4: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_47d9:
	/* 0x47d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47de:
	/* 0x47de: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_47e1:
	/* 0x47e1: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_47e7:
	/* 0x47e7: je     4abe <perf_unwind_ruby+0x4abe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4abe;
	}
x86_l_47ed:
	/* 0x47ed: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_47f2:
	/* 0x47f2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_47f5:
	/* 0x47f5: je     4abe <perf_unwind_ruby+0x4abe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4abe;
	}
x86_l_47fb:
	/* 0x47fb: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_4800:
	/* 0x4800: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4803:
	/* 0x4803: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4808:
	/* 0x4808: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_480d:
	/* 0x480d: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4813:
	/* 0x4813: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_4818:
	/* 0x4818: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_481d:
	/* 0x481d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4822:
	/* 0x4822: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4825:
	/* 0x4825: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4828:
	/* 0x4828: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_482e:
	/* 0x482e: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_4833:
	/* 0x4833: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4838:
	/* 0x4838: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_483d:
	/* 0x483d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4842:
	/* 0x4842: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4848:
	/* 0x4848: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_484d:
	/* 0x484d: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4852:
	/* 0x4852: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4857:
	/* 0x4857: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_485a:
	/* 0x485a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_485d:
	/* 0x485d: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_4863:
	/* 0x4863: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_4868:
	/* 0x4868: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_486d:
	/* 0x486d: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_4872:
	/* 0x4872: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_4877:
	/* 0x4877: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_487d:
	/* 0x487d: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_4882:
	/* 0x4882: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4887:
	/* 0x4887: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_488c:
	/* 0x488c: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_488f:
	/* 0x488f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4892:
	/* 0x4892: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_4898:
	/* 0x4898: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_489d:
	/* 0x489d: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_48a0:
	/* 0x48a0: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_48a5:
	/* 0x48a5: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_48aa:
	/* 0x48aa: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_48ad:
	/* 0x48ad: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_48b1:
	/* 0x48b1: je     4cda <perf_unwind_ruby+0x4cda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4cda;
	}
x86_l_48b7:
	/* 0x48b7: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_48b9:
	/* 0x48b9: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_48bc:
	/* 0x48bc: jmp    4cde <perf_unwind_ruby+0x4cde> */
	goto x86_l_4cde;
x86_l_48c1:
	/* 0x48c1: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_48c3:
	/* 0x48c3: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_48c5:
	/* 0x48c5: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_48c9:
	/* 0x48c9: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_48cc:
	/* 0x48cc: jbe    4959 <perf_unwind_ruby+0x4959> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_4959;
	}
x86_l_48d2:
	/* 0x48d2: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_48d9:
	/* 0x48d9: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48dc:
	/* 0x48dc: je     4084 <perf_unwind_ruby+0x4084> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16516ULL;
	}
x86_l_48e2:
	/* 0x48e2: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_48ec:
	/* 0x48ec: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_48f1:
	/* 0x48f1: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_48fb:
	/* 0x48fb: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4900:
	/* 0x4900: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_490a:
	/* 0x490a: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_490f:
	/* 0x490f: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_4919:
	/* 0x4919: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_491e:
	/* 0x491e: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_4928:
	/* 0x4928: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_492d:
	/* 0x492d: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_4937:
	/* 0x4937: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_493c:
	/* 0x493c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4941:
	/* 0x4941: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4946:
	/* 0x4946: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_494b:
	/* 0x494b: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_4950:
	/* 0x4950: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4952:
	/* 0x4952: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4954:
	/* 0x4954: jmp    4084 <perf_unwind_ruby+0x4084> */
	return 16516ULL;
x86_l_4959:
	/* 0x4959: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_4960:
	/* 0x4960: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_4964:
	/* 0x4964: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_496a:
	/* 0x496a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_496f:
	/* 0x496f: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4972:
	/* 0x4972: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_4979:
	/* 0x4979: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_497d:
	/* 0x497d: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_4984:
	/* 0x4984: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_498b:
	/* 0x498b: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_4993:
	/* 0x4993: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_499b:
	/* 0x499b: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_49a6:
	/* 0x49a6: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49a9:
	/* 0x49a9: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_49b1:
	/* 0x49b1: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_49b6:
	/* 0x49b6: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_49bf:
	/* 0x49bf: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_49c6:
	/* 0x49c6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_49cd:
	/* 0x49cd: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_49d0:
	/* 0x49d0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_49d5:
	/* 0x49d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49d7:
	/* 0x49d7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_49da:
	/* 0x49da: je     4a34 <perf_unwind_ruby+0x4a34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a34;
	}
x86_l_49dc:
	/* 0x49dc: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_49df:
	/* 0x49df: jmp    4084 <perf_unwind_ruby+0x4084> */
	return 16516ULL;
x86_l_49e4:
	/* 0x49e4: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49ec:
	/* 0x49ec: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_49f1:
	/* 0x49f1: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_49f6:
	/* 0x49f6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_49f9:
	/* 0x49f9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_49fe:
	/* 0x49fe: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4a04:
	/* 0x4a04: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_4a09:
	/* 0x4a09: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4a0e:
	/* 0x4a0e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a13:
	/* 0x4a13: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4a16:
	/* 0x4a16: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4a19:
	/* 0x4a19: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_4a1f:
	/* 0x4a1f: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a22:
	/* 0x4a22: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_4a24:
	/* 0x4a24: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_4a29:
	/* 0x4a29: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_4a2f:
	/* 0x4a2f: jmp    475e <perf_unwind_ruby+0x475e> */
	goto x86_l_475e;
x86_l_4a34:
	/* 0x4a34: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4a3b:
	/* 0x4a3b: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a3e:
	/* 0x4a3e: je     4084 <perf_unwind_ruby+0x4084> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16516ULL;
	}
x86_l_4a44:
	/* 0x4a44: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_4a4e:
	/* 0x4a4e: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_4a53:
	/* 0x4a53: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_4a5d:
	/* 0x4a5d: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4a62:
	/* 0x4a62: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_4a6c:
	/* 0x4a6c: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4a71:
	/* 0x4a71: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_4a7b:
	/* 0x4a7b: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4a80:
	/* 0x4a80: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_4a8a:
	/* 0x4a8a: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4a8f:
	/* 0x4a8f: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_4a99:
	/* 0x4a99: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4a9e:
	/* 0x4a9e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4aa3:
	/* 0x4aa3: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_4aa8:
	/* 0x4aa8: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4aad:
	/* 0x4aad: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ab0:
	/* 0x4ab0: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_4ab5:
	/* 0x4ab5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ab7:
	/* 0x4ab7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4ab9:
	/* 0x4ab9: jmp    4084 <perf_unwind_ruby+0x4084> */
	return 16516ULL;
x86_l_4abe:
	/* 0x4abe: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_4ac5:
	/* 0x4ac5: jb     5025 <perf_unwind_ruby+0x5025> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 20517ULL;
	}
x86_l_4acb:
	/* 0x4acb: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ad3:
	/* 0x4ad3: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_4ad8:
	/* 0x4ad8: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4add:
	/* 0x4add: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4ae0:
	/* 0x4ae0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4ae5:
	/* 0x4ae5: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4aeb:
	/* 0x4aeb: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_4af0:
	/* 0x4af0: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4af5:
	/* 0x4af5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4afa:
	/* 0x4afa: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4afd:
	/* 0x4afd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b00:
	/* 0x4b00: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_4b06:
	/* 0x4b06: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b09:
	/* 0x4b09: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_4b0b:
	/* 0x4b0b: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_4b10:
	/* 0x4b10: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_4b16:
	/* 0x4b16: jmp    5025 <perf_unwind_ruby+0x5025> */
	return 20517ULL;
x86_l_4b1b:
	/* 0x4b1b: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4b1d:
	/* 0x4b1d: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_4b1f:
	/* 0x4b1f: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_4b23:
	/* 0x4b23: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_4b26:
	/* 0x4b26: jbe    4bb3 <perf_unwind_ruby+0x4bb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_4bb3;
	}
x86_l_4b2c:
	/* 0x4b2c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4b33:
	/* 0x4b33: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b36:
	/* 0x4b36: je     43f1 <perf_unwind_ruby+0x43f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17393ULL;
	}
x86_l_4b3c:
	/* 0x4b3c: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_4b46:
	/* 0x4b46: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_4b4b:
	/* 0x4b4b: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_4b55:
	/* 0x4b55: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4b5a:
	/* 0x4b5a: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_4b64:
	/* 0x4b64: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4b69:
	/* 0x4b69: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_4b73:
	/* 0x4b73: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4b78:
	/* 0x4b78: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_4b82:
	/* 0x4b82: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4b87:
	/* 0x4b87: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_4b91:
	/* 0x4b91: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4b96:
	/* 0x4b96: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4b9b:
	/* 0x4b9b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4ba0:
	/* 0x4ba0: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4ba5:
	/* 0x4ba5: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_4baa:
	/* 0x4baa: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bac:
	/* 0x4bac: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4bae:
	/* 0x4bae: jmp    43f1 <perf_unwind_ruby+0x43f1> */
	return 17393ULL;
x86_l_4bb3:
	/* 0x4bb3: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_4bba:
	/* 0x4bba: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_4bbe:
	/* 0x4bbe: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_4bc4:
	/* 0x4bc4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4bc9:
	/* 0x4bc9: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4bcc:
	/* 0x4bcc: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_4bd3:
	/* 0x4bd3: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_4bd7:
	/* 0x4bd7: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_4bde:
	/* 0x4bde: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4be5:
	/* 0x4be5: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_4bed:
	/* 0x4bed: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_4bf5:
	/* 0x4bf5: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_4c00:
	/* 0x4c00: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c03:
	/* 0x4c03: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_4c0b:
	/* 0x4c0b: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4c10:
	/* 0x4c10: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_4c19:
	/* 0x4c19: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_4c20:
	/* 0x4c20: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_4c27:
	/* 0x4c27: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4c2a:
	/* 0x4c2a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c2f:
	/* 0x4c2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c31:
	/* 0x4c31: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c34:
	/* 0x4c34: je     4d72 <perf_unwind_ruby+0x4d72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d72;
	}
x86_l_4c3a:
	/* 0x4c3a: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4c3d:
	/* 0x4c3d: jmp    43f1 <perf_unwind_ruby+0x43f1> */
	return 17393ULL;
x86_l_4c42:
	/* 0x4c42: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c44:
	/* 0x4c44: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_4c46:
	/* 0x4c46: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_4c4a:
	/* 0x4c4a: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_4c4d:
	/* 0x4c4d: jbe    4dfc <perf_unwind_ruby+0x4dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_4dfc;
	}
x86_l_4c53:
	/* 0x4c53: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4c5a:
	/* 0x4c5a: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c5d:
	/* 0x4c5d: je     475e <perf_unwind_ruby+0x475e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_475e;
	}
x86_l_4c63:
	/* 0x4c63: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_4c6d:
	/* 0x4c6d: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_4c72:
	/* 0x4c72: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_4c7c:
	/* 0x4c7c: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4c81:
	/* 0x4c81: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_4c8b:
	/* 0x4c8b: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4c90:
	/* 0x4c90: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_4c9a:
	/* 0x4c9a: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4c9f:
	/* 0x4c9f: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_4ca9:
	/* 0x4ca9: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4cae:
	/* 0x4cae: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_4cb8:
	/* 0x4cb8: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4cbd:
	/* 0x4cbd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4cc2:
	/* 0x4cc2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4cc7:
	/* 0x4cc7: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4ccc:
	/* 0x4ccc: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_4cd1:
	/* 0x4cd1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4cd3:
	/* 0x4cd3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4cd5:
	/* 0x4cd5: jmp    475e <perf_unwind_ruby+0x475e> */
	goto x86_l_475e;
x86_l_4cda:
	/* 0x4cda: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4cdc:
	/* 0x4cdc: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_4cde:
	/* 0x4cde: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_4ce2:
	/* 0x4ce2: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_4ce5:
	/* 0x4ce5: jbe    4e8b <perf_unwind_ruby+0x4e8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_4e8b;
	}
x86_l_4ceb:
	/* 0x4ceb: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4cf2:
	/* 0x4cf2: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4cf5:
	/* 0x4cf5: je     5025 <perf_unwind_ruby+0x5025> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20517ULL;
	}
x86_l_4cfb:
	/* 0x4cfb: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_4d05:
	/* 0x4d05: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_4d0a:
	/* 0x4d0a: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_4d14:
	/* 0x4d14: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4d19:
	/* 0x4d19: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_4d23:
	/* 0x4d23: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4d28:
	/* 0x4d28: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_4d32:
	/* 0x4d32: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4d37:
	/* 0x4d37: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_4d41:
	/* 0x4d41: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4d46:
	/* 0x4d46: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_4d50:
	/* 0x4d50: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4d55:
	/* 0x4d55: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4d5a:
	/* 0x4d5a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4d5f:
	/* 0x4d5f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4d64:
	/* 0x4d64: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_4d69:
	/* 0x4d69: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d6b:
	/* 0x4d6b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4d6d:
	/* 0x4d6d: jmp    5025 <perf_unwind_ruby+0x5025> */
	return 20517ULL;
x86_l_4d72:
	/* 0x4d72: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4d79:
	/* 0x4d79: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d7c:
	/* 0x4d7c: je     43f1 <perf_unwind_ruby+0x43f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17393ULL;
	}
x86_l_4d82:
	/* 0x4d82: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_4d8c:
	/* 0x4d8c: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_4d91:
	/* 0x4d91: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_4d9b:
	/* 0x4d9b: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4da0:
	/* 0x4da0: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_4daa:
	/* 0x4daa: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4daf:
	/* 0x4daf: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_4db9:
	/* 0x4db9: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4dbe:
	/* 0x4dbe: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_4dc8:
	/* 0x4dc8: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4dcd:
	/* 0x4dcd: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_4dd7:
	/* 0x4dd7: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4ddc:
	/* 0x4ddc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4de1:
	/* 0x4de1: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_4de6:
	/* 0x4de6: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4deb:
	/* 0x4deb: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dee:
	/* 0x4dee: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_4df3:
	/* 0x4df3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4df5:
	/* 0x4df5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4df7:
	/* 0x4df7: jmp    43f1 <perf_unwind_ruby+0x43f1> */
	return 17393ULL;
x86_l_4dfc:
	/* 0x4dfc: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_4e03:
	/* 0x4e03: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_4e07:
	/* 0x4e07: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_4e0d:
	/* 0x4e0d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e12:
	/* 0x4e12: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4e15:
	/* 0x4e15: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_4e1c:
	/* 0x4e1c: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_4e20:
	/* 0x4e20: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_4e27:
	/* 0x4e27: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e2e:
	/* 0x4e2e: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_4e36:
	/* 0x4e36: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_4e3e:
	/* 0x4e3e: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_4e49:
	/* 0x4e49: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e4c:
	/* 0x4e4c: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_4e54:
	/* 0x4e54: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4e59:
	/* 0x4e59: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_4e62:
	/* 0x4e62: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_4e69:
	/* 0x4e69: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_4e70:
	/* 0x4e70: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4e73:
	/* 0x4e73: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e78:
	/* 0x4e78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e7a:
	/* 0x4e7a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e7d:
	/* 0x4e7d: je     4f1a <perf_unwind_ruby+0x4f1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20250ULL;
	}
x86_l_4e83:
	/* 0x4e83: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4e86:
	/* 0x4e86: jmp    475e <perf_unwind_ruby+0x475e> */
	goto x86_l_475e;
x86_l_4e8b:
	/* 0x4e8b: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_4e92:
	/* 0x4e92: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_4e96:
	/* 0x4e96: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_4e9c:
	/* 0x4e9c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ea1:
	/* 0x4ea1: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4ea4:
	/* 0x4ea4: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_4eab:
	/* 0x4eab: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_4eaf:
	/* 0x4eaf: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_4eb6:
	/* 0x4eb6: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ebd:
	/* 0x4ebd: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_4ec5:
	/* 0x4ec5: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_4ecd:
	/* 0x4ecd: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_4ed8:
	/* 0x4ed8: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4edb:
	/* 0x4edb: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_4ee3:
	/* 0x4ee3: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4ee8:
	/* 0x4ee8: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_4ef1:
	/* 0x4ef1: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_4ef8:
	/* 0x4ef8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_4eff:
	/* 0x4eff: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4f02:
	/* 0x4f02: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
	return 20231ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20231ULL: goto x86_l_4f07;
	case 20233ULL: goto x86_l_4f09;
	case 20236ULL: goto x86_l_4f0c;
	case 20242ULL: goto x86_l_4f12;
	case 20245ULL: goto x86_l_4f15;
	case 20250ULL: goto x86_l_4f1a;
	case 20257ULL: goto x86_l_4f21;
	case 20260ULL: goto x86_l_4f24;
	case 20266ULL: goto x86_l_4f2a;
	case 20276ULL: goto x86_l_4f34;
	case 20281ULL: goto x86_l_4f39;
	case 20291ULL: goto x86_l_4f43;
	case 20296ULL: goto x86_l_4f48;
	case 20306ULL: goto x86_l_4f52;
	case 20311ULL: goto x86_l_4f57;
	case 20321ULL: goto x86_l_4f61;
	case 20326ULL: goto x86_l_4f66;
	case 20336ULL: goto x86_l_4f70;
	case 20341ULL: goto x86_l_4f75;
	case 20351ULL: goto x86_l_4f7f;
	case 20356ULL: goto x86_l_4f84;
	case 20361ULL: goto x86_l_4f89;
	case 20366ULL: goto x86_l_4f8e;
	case 20371ULL: goto x86_l_4f93;
	case 20374ULL: goto x86_l_4f96;
	case 20379ULL: goto x86_l_4f9b;
	case 20381ULL: goto x86_l_4f9d;
	case 20383ULL: goto x86_l_4f9f;
	case 20388ULL: goto x86_l_4fa4;
	case 20395ULL: goto x86_l_4fab;
	case 20398ULL: goto x86_l_4fae;
	case 20400ULL: goto x86_l_4fb0;
	case 20410ULL: goto x86_l_4fba;
	case 20415ULL: goto x86_l_4fbf;
	case 20425ULL: goto x86_l_4fc9;
	case 20430ULL: goto x86_l_4fce;
	case 20440ULL: goto x86_l_4fd8;
	case 20445ULL: goto x86_l_4fdd;
	case 20455ULL: goto x86_l_4fe7;
	case 20460ULL: goto x86_l_4fec;
	case 20470ULL: goto x86_l_4ff6;
	case 20475ULL: goto x86_l_4ffb;
	case 20485ULL: goto x86_l_5005;
	case 20490ULL: goto x86_l_500a;
	case 20495ULL: goto x86_l_500f;
	case 20500ULL: goto x86_l_5014;
	case 20505ULL: goto x86_l_5019;
	case 20508ULL: goto x86_l_501c;
	case 20513ULL: goto x86_l_5021;
	case 20515ULL: goto x86_l_5023;
	case 20517ULL: goto x86_l_5025;
	case 20522ULL: goto x86_l_502a;
	case 20525ULL: goto x86_l_502d;
	case 20531ULL: goto x86_l_5033;
	case 20536ULL: goto x86_l_5038;
	case 20539ULL: goto x86_l_503b;
	case 20544ULL: goto x86_l_5040;
	case 20553ULL: goto x86_l_5049;
	case 20562ULL: goto x86_l_5052;
	case 20567ULL: goto x86_l_5057;
	case 20570ULL: goto x86_l_505a;
	case 20575ULL: goto x86_l_505f;
	case 20580ULL: goto x86_l_5064;
	case 20586ULL: goto x86_l_506a;
	case 20591ULL: goto x86_l_506f;
	case 20596ULL: goto x86_l_5074;
	case 20601ULL: goto x86_l_5079;
	case 20604ULL: goto x86_l_507c;
	case 20609ULL: goto x86_l_5081;
	case 20614ULL: goto x86_l_5086;
	case 20619ULL: goto x86_l_508b;
	case 20624ULL: goto x86_l_5090;
	case 20630ULL: goto x86_l_5096;
	case 20635ULL: goto x86_l_509b;
	case 20640ULL: goto x86_l_50a0;
	case 20645ULL: goto x86_l_50a5;
	case 20648ULL: goto x86_l_50a8;
	case 20654ULL: goto x86_l_50ae;
	case 20660ULL: goto x86_l_50b4;
	case 20665ULL: goto x86_l_50b9;
	case 20668ULL: goto x86_l_50bc;
	case 20674ULL: goto x86_l_50c2;
	case 20679ULL: goto x86_l_50c7;
	case 20682ULL: goto x86_l_50ca;
	case 20687ULL: goto x86_l_50cf;
	case 20692ULL: goto x86_l_50d4;
	case 20698ULL: goto x86_l_50da;
	case 20703ULL: goto x86_l_50df;
	case 20708ULL: goto x86_l_50e4;
	case 20713ULL: goto x86_l_50e9;
	case 20716ULL: goto x86_l_50ec;
	case 20719ULL: goto x86_l_50ef;
	case 20725ULL: goto x86_l_50f5;
	case 20730ULL: goto x86_l_50fa;
	case 20735ULL: goto x86_l_50ff;
	case 20740ULL: goto x86_l_5104;
	case 20745ULL: goto x86_l_5109;
	case 20751ULL: goto x86_l_510f;
	case 20756ULL: goto x86_l_5114;
	case 20761ULL: goto x86_l_5119;
	case 20766ULL: goto x86_l_511e;
	case 20769ULL: goto x86_l_5121;
	case 20772ULL: goto x86_l_5124;
	case 20778ULL: goto x86_l_512a;
	case 20783ULL: goto x86_l_512f;
	case 20788ULL: goto x86_l_5134;
	case 20793ULL: goto x86_l_5139;
	case 20798ULL: goto x86_l_513e;
	case 20804ULL: goto x86_l_5144;
	case 20809ULL: goto x86_l_5149;
	case 20814ULL: goto x86_l_514e;
	case 20819ULL: goto x86_l_5153;
	case 20822ULL: goto x86_l_5156;
	case 20825ULL: goto x86_l_5159;
	case 20831ULL: goto x86_l_515f;
	case 20836ULL: goto x86_l_5164;
	case 20839ULL: goto x86_l_5167;
	case 20844ULL: goto x86_l_516c;
	case 20849ULL: goto x86_l_5171;
	case 20852ULL: goto x86_l_5174;
	case 20856ULL: goto x86_l_5178;
	case 20858ULL: goto x86_l_517a;
	case 20860ULL: goto x86_l_517c;
	case 20863ULL: goto x86_l_517f;
	case 20865ULL: goto x86_l_5181;
	case 20872ULL: goto x86_l_5188;
	case 20878ULL: goto x86_l_518e;
	case 20886ULL: goto x86_l_5196;
	case 20891ULL: goto x86_l_519b;
	case 20896ULL: goto x86_l_51a0;
	case 20899ULL: goto x86_l_51a3;
	case 20904ULL: goto x86_l_51a8;
	case 20910ULL: goto x86_l_51ae;
	case 20915ULL: goto x86_l_51b3;
	case 20920ULL: goto x86_l_51b8;
	case 20925ULL: goto x86_l_51bd;
	case 20928ULL: goto x86_l_51c0;
	case 20931ULL: goto x86_l_51c3;
	case 20937ULL: goto x86_l_51c9;
	case 20940ULL: goto x86_l_51cc;
	case 20942ULL: goto x86_l_51ce;
	case 20947ULL: goto x86_l_51d3;
	case 20953ULL: goto x86_l_51d9;
	case 20958ULL: goto x86_l_51de;
	case 20960ULL: goto x86_l_51e0;
	case 20962ULL: goto x86_l_51e2;
	case 20966ULL: goto x86_l_51e6;
	case 20969ULL: goto x86_l_51e9;
	case 20975ULL: goto x86_l_51ef;
	case 20982ULL: goto x86_l_51f6;
	case 20985ULL: goto x86_l_51f9;
	case 20991ULL: goto x86_l_51ff;
	case 21001ULL: goto x86_l_5209;
	case 21006ULL: goto x86_l_520e;
	case 21016ULL: goto x86_l_5218;
	case 21021ULL: goto x86_l_521d;
	case 21031ULL: goto x86_l_5227;
	case 21036ULL: goto x86_l_522c;
	case 21046ULL: goto x86_l_5236;
	case 21051ULL: goto x86_l_523b;
	case 21061ULL: goto x86_l_5245;
	case 21066ULL: goto x86_l_524a;
	case 21076ULL: goto x86_l_5254;
	case 21081ULL: goto x86_l_5259;
	case 21086ULL: goto x86_l_525e;
	case 21091ULL: goto x86_l_5263;
	case 21096ULL: goto x86_l_5268;
	case 21101ULL: goto x86_l_526d;
	case 21103ULL: goto x86_l_526f;
	case 21105ULL: goto x86_l_5271;
	case 21110ULL: goto x86_l_5276;
	case 21117ULL: goto x86_l_527d;
	case 21121ULL: goto x86_l_5281;
	case 21127ULL: goto x86_l_5287;
	case 21132ULL: goto x86_l_528c;
	case 21135ULL: goto x86_l_528f;
	case 21142ULL: goto x86_l_5296;
	case 21146ULL: goto x86_l_529a;
	case 21153ULL: goto x86_l_52a1;
	case 21160ULL: goto x86_l_52a8;
	case 21168ULL: goto x86_l_52b0;
	case 21176ULL: goto x86_l_52b8;
	case 21187ULL: goto x86_l_52c3;
	case 21190ULL: goto x86_l_52c6;
	case 21198ULL: goto x86_l_52ce;
	case 21203ULL: goto x86_l_52d3;
	case 21212ULL: goto x86_l_52dc;
	case 21219ULL: goto x86_l_52e3;
	case 21226ULL: goto x86_l_52ea;
	case 21229ULL: goto x86_l_52ed;
	case 21234ULL: goto x86_l_52f2;
	case 21236ULL: goto x86_l_52f4;
	case 21239ULL: goto x86_l_52f7;
	case 21241ULL: goto x86_l_52f9;
	case 21244ULL: goto x86_l_52fc;
	case 21249ULL: goto x86_l_5301;
	case 21256ULL: goto x86_l_5308;
	case 21259ULL: goto x86_l_530b;
	case 21261ULL: goto x86_l_530d;
	case 21271ULL: goto x86_l_5317;
	case 21276ULL: goto x86_l_531c;
	case 21286ULL: goto x86_l_5326;
	case 21291ULL: goto x86_l_532b;
	case 21301ULL: goto x86_l_5335;
	case 21306ULL: goto x86_l_533a;
	case 21316ULL: goto x86_l_5344;
	case 21321ULL: goto x86_l_5349;
	case 21331ULL: goto x86_l_5353;
	case 21336ULL: goto x86_l_5358;
	case 21346ULL: goto x86_l_5362;
	case 21351ULL: goto x86_l_5367;
	case 21356ULL: goto x86_l_536c;
	case 21361ULL: goto x86_l_5371;
	case 21366ULL: goto x86_l_5376;
	case 21369ULL: goto x86_l_5379;
	case 21374ULL: goto x86_l_537e;
	case 21376ULL: goto x86_l_5380;
	case 21378ULL: goto x86_l_5382;
	case 21383ULL: goto x86_l_5387;
	case 21386ULL: goto x86_l_538a;
	case 21392ULL: goto x86_l_5390;
	case 21397ULL: goto x86_l_5395;
	case 21400ULL: goto x86_l_5398;
	case 21405ULL: goto x86_l_539d;
	case 21414ULL: goto x86_l_53a6;
	case 21423ULL: goto x86_l_53af;
	case 21428ULL: goto x86_l_53b4;
	case 21431ULL: goto x86_l_53b7;
	case 21436ULL: goto x86_l_53bc;
	case 21441ULL: goto x86_l_53c1;
	case 21447ULL: goto x86_l_53c7;
	case 21452ULL: goto x86_l_53cc;
	case 21457ULL: goto x86_l_53d1;
	case 21462ULL: goto x86_l_53d6;
	case 21465ULL: goto x86_l_53d9;
	case 21470ULL: goto x86_l_53de;
	case 21475ULL: goto x86_l_53e3;
	case 21480ULL: goto x86_l_53e8;
	case 21485ULL: goto x86_l_53ed;
	case 21491ULL: goto x86_l_53f3;
	case 21496ULL: goto x86_l_53f8;
	case 21501ULL: goto x86_l_53fd;
	case 21506ULL: goto x86_l_5402;
	case 21509ULL: goto x86_l_5405;
	case 21515ULL: goto x86_l_540b;
	case 21521ULL: goto x86_l_5411;
	case 21526ULL: goto x86_l_5416;
	case 21529ULL: goto x86_l_5419;
	case 21535ULL: goto x86_l_541f;
	case 21540ULL: goto x86_l_5424;
	case 21543ULL: goto x86_l_5427;
	case 21548ULL: goto x86_l_542c;
	case 21553ULL: goto x86_l_5431;
	case 21559ULL: goto x86_l_5437;
	case 21564ULL: goto x86_l_543c;
	case 21569ULL: goto x86_l_5441;
	case 21574ULL: goto x86_l_5446;
	case 21577ULL: goto x86_l_5449;
	case 21580ULL: goto x86_l_544c;
	case 21586ULL: goto x86_l_5452;
	case 21591ULL: goto x86_l_5457;
	case 21596ULL: goto x86_l_545c;
	case 21601ULL: goto x86_l_5461;
	case 21606ULL: goto x86_l_5466;
	case 21612ULL: goto x86_l_546c;
	case 21617ULL: goto x86_l_5471;
	case 21622ULL: goto x86_l_5476;
	case 21627ULL: goto x86_l_547b;
	case 21630ULL: goto x86_l_547e;
	case 21633ULL: goto x86_l_5481;
	case 21639ULL: goto x86_l_5487;
	case 21644ULL: goto x86_l_548c;
	case 21649ULL: goto x86_l_5491;
	case 21654ULL: goto x86_l_5496;
	case 21659ULL: goto x86_l_549b;
	case 21665ULL: goto x86_l_54a1;
	case 21670ULL: goto x86_l_54a6;
	case 21675ULL: goto x86_l_54ab;
	case 21680ULL: goto x86_l_54b0;
	case 21683ULL: goto x86_l_54b3;
	case 21686ULL: goto x86_l_54b6;
	case 21692ULL: goto x86_l_54bc;
	case 21697ULL: goto x86_l_54c1;
	case 21700ULL: goto x86_l_54c4;
	case 21705ULL: goto x86_l_54c9;
	case 21710ULL: goto x86_l_54ce;
	case 21713ULL: goto x86_l_54d1;
	case 21717ULL: goto x86_l_54d5;
	case 21719ULL: goto x86_l_54d7;
	case 21721ULL: goto x86_l_54d9;
	case 21724ULL: goto x86_l_54dc;
	case 21726ULL: goto x86_l_54de;
	case 21733ULL: goto x86_l_54e5;
	case 21739ULL: goto x86_l_54eb;
	case 21747ULL: goto x86_l_54f3;
	case 21752ULL: goto x86_l_54f8;
	case 21757ULL: goto x86_l_54fd;
	case 21760ULL: goto x86_l_5500;
	case 21765ULL: goto x86_l_5505;
	case 21771ULL: goto x86_l_550b;
	case 21776ULL: goto x86_l_5510;
	case 21781ULL: goto x86_l_5515;
	case 21786ULL: goto x86_l_551a;
	case 21789ULL: goto x86_l_551d;
	case 21792ULL: goto x86_l_5520;
	case 21798ULL: goto x86_l_5526;
	case 21801ULL: goto x86_l_5529;
	case 21803ULL: goto x86_l_552b;
	case 21808ULL: goto x86_l_5530;
	case 21814ULL: goto x86_l_5536;
	case 21819ULL: goto x86_l_553b;
	case 21821ULL: goto x86_l_553d;
	case 21823ULL: goto x86_l_553f;
	case 21827ULL: goto x86_l_5543;
	case 21830ULL: goto x86_l_5546;
	case 21836ULL: goto x86_l_554c;
	case 21843ULL: goto x86_l_5553;
	case 21846ULL: goto x86_l_5556;
	case 21852ULL: goto x86_l_555c;
	case 21862ULL: goto x86_l_5566;
	case 21867ULL: goto x86_l_556b;
	case 21877ULL: goto x86_l_5575;
	case 21882ULL: goto x86_l_557a;
	case 21892ULL: goto x86_l_5584;
	case 21897ULL: goto x86_l_5589;
	case 21907ULL: goto x86_l_5593;
	case 21912ULL: goto x86_l_5598;
	case 21922ULL: goto x86_l_55a2;
	case 21927ULL: goto x86_l_55a7;
	case 21937ULL: goto x86_l_55b1;
	case 21942ULL: goto x86_l_55b6;
	case 21947ULL: goto x86_l_55bb;
	case 21952ULL: goto x86_l_55c0;
	case 21957ULL: goto x86_l_55c5;
	case 21962ULL: goto x86_l_55ca;
	case 21964ULL: goto x86_l_55cc;
	case 21966ULL: goto x86_l_55ce;
	case 21971ULL: goto x86_l_55d3;
	case 21978ULL: goto x86_l_55da;
	case 21982ULL: goto x86_l_55de;
	case 21988ULL: goto x86_l_55e4;
	case 21993ULL: goto x86_l_55e9;
	case 21996ULL: goto x86_l_55ec;
	case 22003ULL: goto x86_l_55f3;
	case 22007ULL: goto x86_l_55f7;
	case 22014ULL: goto x86_l_55fe;
	case 22021ULL: goto x86_l_5605;
	case 22029ULL: goto x86_l_560d;
	case 22037ULL: goto x86_l_5615;
	case 22048ULL: goto x86_l_5620;
	case 22051ULL: goto x86_l_5623;
	case 22059ULL: goto x86_l_562b;
	case 22064ULL: goto x86_l_5630;
	case 22073ULL: goto x86_l_5639;
	case 22080ULL: goto x86_l_5640;
	case 22087ULL: goto x86_l_5647;
	case 22090ULL: goto x86_l_564a;
	case 22095ULL: goto x86_l_564f;
	case 22097ULL: goto x86_l_5651;
	case 22100ULL: goto x86_l_5654;
	case 22102ULL: goto x86_l_5656;
	case 22105ULL: goto x86_l_5659;
	case 22110ULL: goto x86_l_565e;
	case 22117ULL: goto x86_l_5665;
	case 22120ULL: goto x86_l_5668;
	case 22122ULL: goto x86_l_566a;
	case 22132ULL: goto x86_l_5674;
	case 22137ULL: goto x86_l_5679;
	case 22147ULL: goto x86_l_5683;
	case 22152ULL: goto x86_l_5688;
	case 22162ULL: goto x86_l_5692;
	case 22167ULL: goto x86_l_5697;
	case 22177ULL: goto x86_l_56a1;
	case 22182ULL: goto x86_l_56a6;
	case 22192ULL: goto x86_l_56b0;
	case 22197ULL: goto x86_l_56b5;
	case 22207ULL: goto x86_l_56bf;
	case 22212ULL: goto x86_l_56c4;
	case 22217ULL: goto x86_l_56c9;
	case 22222ULL: goto x86_l_56ce;
	case 22227ULL: goto x86_l_56d3;
	case 22230ULL: goto x86_l_56d6;
	case 22235ULL: goto x86_l_56db;
	case 22237ULL: goto x86_l_56dd;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4f07:
	/* 0x4f07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f09:
	/* 0x4f09: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4f0c:
	/* 0x4f0c: je     4fa4 <perf_unwind_ruby+0x4fa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fa4;
	}
x86_l_4f12:
	/* 0x4f12: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4f15:
	/* 0x4f15: jmp    5025 <perf_unwind_ruby+0x5025> */
	goto x86_l_5025;
x86_l_4f1a:
	/* 0x4f1a: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4f21:
	/* 0x4f21: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f24:
	/* 0x4f24: je     475e <perf_unwind_ruby+0x475e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18270ULL;
	}
x86_l_4f2a:
	/* 0x4f2a: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_4f34:
	/* 0x4f34: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_4f39:
	/* 0x4f39: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_4f43:
	/* 0x4f43: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4f48:
	/* 0x4f48: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_4f52:
	/* 0x4f52: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4f57:
	/* 0x4f57: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_4f61:
	/* 0x4f61: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4f66:
	/* 0x4f66: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_4f70:
	/* 0x4f70: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4f75:
	/* 0x4f75: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_4f7f:
	/* 0x4f7f: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4f84:
	/* 0x4f84: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4f89:
	/* 0x4f89: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_4f8e:
	/* 0x4f8e: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4f93:
	/* 0x4f93: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f96:
	/* 0x4f96: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_4f9b:
	/* 0x4f9b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f9d:
	/* 0x4f9d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4f9f:
	/* 0x4f9f: jmp    475e <perf_unwind_ruby+0x475e> */
	return 18270ULL;
x86_l_4fa4:
	/* 0x4fa4: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4fab:
	/* 0x4fab: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fae:
	/* 0x4fae: je     5025 <perf_unwind_ruby+0x5025> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5025;
	}
x86_l_4fb0:
	/* 0x4fb0: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_4fba:
	/* 0x4fba: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_4fbf:
	/* 0x4fbf: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_4fc9:
	/* 0x4fc9: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4fce:
	/* 0x4fce: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_4fd8:
	/* 0x4fd8: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4fdd:
	/* 0x4fdd: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_4fe7:
	/* 0x4fe7: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4fec:
	/* 0x4fec: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_4ff6:
	/* 0x4ff6: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4ffb:
	/* 0x4ffb: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_5005:
	/* 0x5005: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_500a:
	/* 0x500a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_500f:
	/* 0x500f: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_5014:
	/* 0x5014: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5019:
	/* 0x5019: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_501c:
	/* 0x501c: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_5021:
	/* 0x5021: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5023:
	/* 0x5023: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5025:
	/* 0x5025: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_502a:
	/* 0x502a: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_502d:
	/* 0x502d: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_5033:
	/* 0x5033: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_5038:
	/* 0x5038: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_503b:
	/* 0x503b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5040:
	/* 0x5040: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5049:
	/* 0x5049: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5052:
	/* 0x5052: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_5057:
	/* 0x5057: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_505a:
	/* 0x505a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_505f:
	/* 0x505f: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_5064:
	/* 0x5064: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_506a:
	/* 0x506a: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_506f:
	/* 0x506f: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5074:
	/* 0x5074: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5079:
	/* 0x5079: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_507c:
	/* 0x507c: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_5081:
	/* 0x5081: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5086:
	/* 0x5086: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_508b:
	/* 0x508b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5090:
	/* 0x5090: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5096:
	/* 0x5096: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_509b:
	/* 0x509b: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_50a0:
	/* 0x50a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50a5:
	/* 0x50a5: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_50a8:
	/* 0x50a8: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_50ae:
	/* 0x50ae: je     5181 <perf_unwind_ruby+0x5181> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5181;
	}
x86_l_50b4:
	/* 0x50b4: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_50b9:
	/* 0x50b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_50bc:
	/* 0x50bc: je     5181 <perf_unwind_ruby+0x5181> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5181;
	}
x86_l_50c2:
	/* 0x50c2: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_50c7:
	/* 0x50c7: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_50ca:
	/* 0x50ca: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_50cf:
	/* 0x50cf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_50d4:
	/* 0x50d4: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_50da:
	/* 0x50da: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_50df:
	/* 0x50df: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_50e4:
	/* 0x50e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50e9:
	/* 0x50e9: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_50ec:
	/* 0x50ec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_50ef:
	/* 0x50ef: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_50f5:
	/* 0x50f5: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_50fa:
	/* 0x50fa: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_50ff:
	/* 0x50ff: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5104:
	/* 0x5104: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5109:
	/* 0x5109: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_510f:
	/* 0x510f: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_5114:
	/* 0x5114: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5119:
	/* 0x5119: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_511e:
	/* 0x511e: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5121:
	/* 0x5121: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5124:
	/* 0x5124: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_512a:
	/* 0x512a: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_512f:
	/* 0x512f: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5134:
	/* 0x5134: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_5139:
	/* 0x5139: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_513e:
	/* 0x513e: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5144:
	/* 0x5144: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_5149:
	/* 0x5149: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_514e:
	/* 0x514e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5153:
	/* 0x5153: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5156:
	/* 0x5156: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5159:
	/* 0x5159: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_515f:
	/* 0x515f: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5164:
	/* 0x5164: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_5167:
	/* 0x5167: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_516c:
	/* 0x516c: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_5171:
	/* 0x5171: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5174:
	/* 0x5174: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_5178:
	/* 0x5178: je     51de <perf_unwind_ruby+0x51de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_51de;
	}
x86_l_517a:
	/* 0x517a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_517c:
	/* 0x517c: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_517f:
	/* 0x517f: jmp    51e2 <perf_unwind_ruby+0x51e2> */
	goto x86_l_51e2;
x86_l_5181:
	/* 0x5181: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_5188:
	/* 0x5188: jb     5382 <perf_unwind_ruby+0x5382> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5382;
	}
x86_l_518e:
	/* 0x518e: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5196:
	/* 0x5196: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_519b:
	/* 0x519b: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_51a0:
	/* 0x51a0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_51a3:
	/* 0x51a3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_51a8:
	/* 0x51a8: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_51ae:
	/* 0x51ae: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_51b3:
	/* 0x51b3: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_51b8:
	/* 0x51b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51bd:
	/* 0x51bd: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_51c0:
	/* 0x51c0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_51c3:
	/* 0x51c3: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_51c9:
	/* 0x51c9: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51cc:
	/* 0x51cc: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_51ce:
	/* 0x51ce: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_51d3:
	/* 0x51d3: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_51d9:
	/* 0x51d9: jmp    5382 <perf_unwind_ruby+0x5382> */
	goto x86_l_5382;
x86_l_51de:
	/* 0x51de: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_51e0:
	/* 0x51e0: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_51e2:
	/* 0x51e2: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_51e6:
	/* 0x51e6: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_51e9:
	/* 0x51e9: jbe    5276 <perf_unwind_ruby+0x5276> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_5276;
	}
x86_l_51ef:
	/* 0x51ef: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_51f6:
	/* 0x51f6: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51f9:
	/* 0x51f9: je     5382 <perf_unwind_ruby+0x5382> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5382;
	}
x86_l_51ff:
	/* 0x51ff: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_5209:
	/* 0x5209: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_520e:
	/* 0x520e: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_5218:
	/* 0x5218: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_521d:
	/* 0x521d: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_5227:
	/* 0x5227: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_522c:
	/* 0x522c: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_5236:
	/* 0x5236: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_523b:
	/* 0x523b: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_5245:
	/* 0x5245: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_524a:
	/* 0x524a: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_5254:
	/* 0x5254: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5259:
	/* 0x5259: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_525e:
	/* 0x525e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5263:
	/* 0x5263: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5268:
	/* 0x5268: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_526d:
	/* 0x526d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_526f:
	/* 0x526f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5271:
	/* 0x5271: jmp    5382 <perf_unwind_ruby+0x5382> */
	goto x86_l_5382;
x86_l_5276:
	/* 0x5276: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_527d:
	/* 0x527d: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_5281:
	/* 0x5281: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_5287:
	/* 0x5287: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_528c:
	/* 0x528c: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_528f:
	/* 0x528f: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_5296:
	/* 0x5296: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_529a:
	/* 0x529a: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_52a1:
	/* 0x52a1: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52a8:
	/* 0x52a8: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_52b0:
	/* 0x52b0: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_52b8:
	/* 0x52b8: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_52c3:
	/* 0x52c3: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52c6:
	/* 0x52c6: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_52ce:
	/* 0x52ce: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_52d3:
	/* 0x52d3: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_52dc:
	/* 0x52dc: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_52e3:
	/* 0x52e3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_52ea:
	/* 0x52ea: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_52ed:
	/* 0x52ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_52f2:
	/* 0x52f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52f4:
	/* 0x52f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_52f7:
	/* 0x52f7: je     5301 <perf_unwind_ruby+0x5301> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5301;
	}
x86_l_52f9:
	/* 0x52f9: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_52fc:
	/* 0x52fc: jmp    5382 <perf_unwind_ruby+0x5382> */
	goto x86_l_5382;
x86_l_5301:
	/* 0x5301: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5308:
	/* 0x5308: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_530b:
	/* 0x530b: je     5382 <perf_unwind_ruby+0x5382> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5382;
	}
x86_l_530d:
	/* 0x530d: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_5317:
	/* 0x5317: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_531c:
	/* 0x531c: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_5326:
	/* 0x5326: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_532b:
	/* 0x532b: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_5335:
	/* 0x5335: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_533a:
	/* 0x533a: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_5344:
	/* 0x5344: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5349:
	/* 0x5349: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_5353:
	/* 0x5353: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5358:
	/* 0x5358: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_5362:
	/* 0x5362: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5367:
	/* 0x5367: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_536c:
	/* 0x536c: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_5371:
	/* 0x5371: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5376:
	/* 0x5376: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5379:
	/* 0x5379: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_537e:
	/* 0x537e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5380:
	/* 0x5380: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5382:
	/* 0x5382: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5387:
	/* 0x5387: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_538a:
	/* 0x538a: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_5390:
	/* 0x5390: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_5395:
	/* 0x5395: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5398:
	/* 0x5398: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_539d:
	/* 0x539d: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_53a6:
	/* 0x53a6: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_53af:
	/* 0x53af: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_53b4:
	/* 0x53b4: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_53b7:
	/* 0x53b7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_53bc:
	/* 0x53bc: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_53c1:
	/* 0x53c1: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_53c7:
	/* 0x53c7: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_53cc:
	/* 0x53cc: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_53d1:
	/* 0x53d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53d6:
	/* 0x53d6: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_53d9:
	/* 0x53d9: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_53de:
	/* 0x53de: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_53e3:
	/* 0x53e3: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_53e8:
	/* 0x53e8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_53ed:
	/* 0x53ed: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_53f3:
	/* 0x53f3: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_53f8:
	/* 0x53f8: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_53fd:
	/* 0x53fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5402:
	/* 0x5402: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5405:
	/* 0x5405: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_540b:
	/* 0x540b: je     54de <perf_unwind_ruby+0x54de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54de;
	}
x86_l_5411:
	/* 0x5411: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5416:
	/* 0x5416: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5419:
	/* 0x5419: je     54de <perf_unwind_ruby+0x54de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54de;
	}
x86_l_541f:
	/* 0x541f: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_5424:
	/* 0x5424: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5427:
	/* 0x5427: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_542c:
	/* 0x542c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5431:
	/* 0x5431: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5437:
	/* 0x5437: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_543c:
	/* 0x543c: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_5441:
	/* 0x5441: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5446:
	/* 0x5446: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5449:
	/* 0x5449: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_544c:
	/* 0x544c: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_5452:
	/* 0x5452: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_5457:
	/* 0x5457: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_545c:
	/* 0x545c: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5461:
	/* 0x5461: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5466:
	/* 0x5466: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_546c:
	/* 0x546c: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_5471:
	/* 0x5471: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5476:
	/* 0x5476: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_547b:
	/* 0x547b: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_547e:
	/* 0x547e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5481:
	/* 0x5481: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_5487:
	/* 0x5487: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_548c:
	/* 0x548c: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5491:
	/* 0x5491: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_5496:
	/* 0x5496: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_549b:
	/* 0x549b: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_54a1:
	/* 0x54a1: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_54a6:
	/* 0x54a6: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_54ab:
	/* 0x54ab: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_54b0:
	/* 0x54b0: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_54b3:
	/* 0x54b3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_54b6:
	/* 0x54b6: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_54bc:
	/* 0x54bc: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_54c1:
	/* 0x54c1: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_54c4:
	/* 0x54c4: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_54c9:
	/* 0x54c9: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_54ce:
	/* 0x54ce: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_54d1:
	/* 0x54d1: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_54d5:
	/* 0x54d5: je     553b <perf_unwind_ruby+0x553b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_553b;
	}
x86_l_54d7:
	/* 0x54d7: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_54d9:
	/* 0x54d9: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_54dc:
	/* 0x54dc: jmp    553f <perf_unwind_ruby+0x553f> */
	goto x86_l_553f;
x86_l_54de:
	/* 0x54de: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_54e5:
	/* 0x54e5: jb     56df <perf_unwind_ruby+0x56df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 22239ULL;
	}
x86_l_54eb:
	/* 0x54eb: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54f3:
	/* 0x54f3: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_54f8:
	/* 0x54f8: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_54fd:
	/* 0x54fd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5500:
	/* 0x5500: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5505:
	/* 0x5505: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_550b:
	/* 0x550b: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_5510:
	/* 0x5510: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5515:
	/* 0x5515: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_551a:
	/* 0x551a: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_551d:
	/* 0x551d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5520:
	/* 0x5520: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_5526:
	/* 0x5526: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5529:
	/* 0x5529: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_552b:
	/* 0x552b: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_5530:
	/* 0x5530: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_5536:
	/* 0x5536: jmp    56df <perf_unwind_ruby+0x56df> */
	return 22239ULL;
x86_l_553b:
	/* 0x553b: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_553d:
	/* 0x553d: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_553f:
	/* 0x553f: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_5543:
	/* 0x5543: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_5546:
	/* 0x5546: jbe    55d3 <perf_unwind_ruby+0x55d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_55d3;
	}
x86_l_554c:
	/* 0x554c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5553:
	/* 0x5553: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5556:
	/* 0x5556: je     56df <perf_unwind_ruby+0x56df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22239ULL;
	}
x86_l_555c:
	/* 0x555c: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_5566:
	/* 0x5566: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_556b:
	/* 0x556b: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_5575:
	/* 0x5575: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_557a:
	/* 0x557a: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_5584:
	/* 0x5584: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5589:
	/* 0x5589: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_5593:
	/* 0x5593: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5598:
	/* 0x5598: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_55a2:
	/* 0x55a2: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_55a7:
	/* 0x55a7: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_55b1:
	/* 0x55b1: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_55b6:
	/* 0x55b6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_55bb:
	/* 0x55bb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_55c0:
	/* 0x55c0: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_55c5:
	/* 0x55c5: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_55ca:
	/* 0x55ca: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_55cc:
	/* 0x55cc: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_55ce:
	/* 0x55ce: jmp    56df <perf_unwind_ruby+0x56df> */
	return 22239ULL;
x86_l_55d3:
	/* 0x55d3: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_55da:
	/* 0x55da: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_55de:
	/* 0x55de: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_55e4:
	/* 0x55e4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55e9:
	/* 0x55e9: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_55ec:
	/* 0x55ec: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_55f3:
	/* 0x55f3: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_55f7:
	/* 0x55f7: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_55fe:
	/* 0x55fe: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5605:
	/* 0x5605: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_560d:
	/* 0x560d: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_5615:
	/* 0x5615: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_5620:
	/* 0x5620: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5623:
	/* 0x5623: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_562b:
	/* 0x562b: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_5630:
	/* 0x5630: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_5639:
	/* 0x5639: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_5640:
	/* 0x5640: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_5647:
	/* 0x5647: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_564a:
	/* 0x564a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_564f:
	/* 0x564f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5651:
	/* 0x5651: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5654:
	/* 0x5654: je     565e <perf_unwind_ruby+0x565e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_565e;
	}
x86_l_5656:
	/* 0x5656: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_5659:
	/* 0x5659: jmp    56df <perf_unwind_ruby+0x56df> */
	return 22239ULL;
x86_l_565e:
	/* 0x565e: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5665:
	/* 0x5665: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5668:
	/* 0x5668: je     56df <perf_unwind_ruby+0x56df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22239ULL;
	}
x86_l_566a:
	/* 0x566a: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_5674:
	/* 0x5674: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_5679:
	/* 0x5679: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_5683:
	/* 0x5683: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5688:
	/* 0x5688: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_5692:
	/* 0x5692: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5697:
	/* 0x5697: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_56a1:
	/* 0x56a1: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_56a6:
	/* 0x56a6: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_56b0:
	/* 0x56b0: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_56b5:
	/* 0x56b5: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_56bf:
	/* 0x56bf: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_56c4:
	/* 0x56c4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_56c9:
	/* 0x56c9: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_56ce:
	/* 0x56ce: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_56d3:
	/* 0x56d3: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56d6:
	/* 0x56d6: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_56db:
	/* 0x56db: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_56dd:
	/* 0x56dd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
	return 22239ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22239ULL: goto x86_l_56df;
	case 22244ULL: goto x86_l_56e4;
	case 22247ULL: goto x86_l_56e7;
	case 22253ULL: goto x86_l_56ed;
	case 22258ULL: goto x86_l_56f2;
	case 22261ULL: goto x86_l_56f5;
	case 22266ULL: goto x86_l_56fa;
	case 22275ULL: goto x86_l_5703;
	case 22284ULL: goto x86_l_570c;
	case 22289ULL: goto x86_l_5711;
	case 22292ULL: goto x86_l_5714;
	case 22297ULL: goto x86_l_5719;
	case 22302ULL: goto x86_l_571e;
	case 22308ULL: goto x86_l_5724;
	case 22313ULL: goto x86_l_5729;
	case 22318ULL: goto x86_l_572e;
	case 22323ULL: goto x86_l_5733;
	case 22326ULL: goto x86_l_5736;
	case 22331ULL: goto x86_l_573b;
	case 22336ULL: goto x86_l_5740;
	case 22341ULL: goto x86_l_5745;
	case 22346ULL: goto x86_l_574a;
	case 22352ULL: goto x86_l_5750;
	case 22357ULL: goto x86_l_5755;
	case 22362ULL: goto x86_l_575a;
	case 22367ULL: goto x86_l_575f;
	case 22370ULL: goto x86_l_5762;
	case 22376ULL: goto x86_l_5768;
	case 22382ULL: goto x86_l_576e;
	case 22387ULL: goto x86_l_5773;
	case 22390ULL: goto x86_l_5776;
	case 22396ULL: goto x86_l_577c;
	case 22401ULL: goto x86_l_5781;
	case 22404ULL: goto x86_l_5784;
	case 22409ULL: goto x86_l_5789;
	case 22414ULL: goto x86_l_578e;
	case 22420ULL: goto x86_l_5794;
	case 22425ULL: goto x86_l_5799;
	case 22430ULL: goto x86_l_579e;
	case 22435ULL: goto x86_l_57a3;
	case 22438ULL: goto x86_l_57a6;
	case 22441ULL: goto x86_l_57a9;
	case 22447ULL: goto x86_l_57af;
	case 22452ULL: goto x86_l_57b4;
	case 22457ULL: goto x86_l_57b9;
	case 22462ULL: goto x86_l_57be;
	case 22467ULL: goto x86_l_57c3;
	case 22473ULL: goto x86_l_57c9;
	case 22478ULL: goto x86_l_57ce;
	case 22483ULL: goto x86_l_57d3;
	case 22488ULL: goto x86_l_57d8;
	case 22491ULL: goto x86_l_57db;
	case 22494ULL: goto x86_l_57de;
	case 22500ULL: goto x86_l_57e4;
	case 22505ULL: goto x86_l_57e9;
	case 22510ULL: goto x86_l_57ee;
	case 22515ULL: goto x86_l_57f3;
	case 22520ULL: goto x86_l_57f8;
	case 22526ULL: goto x86_l_57fe;
	case 22531ULL: goto x86_l_5803;
	case 22536ULL: goto x86_l_5808;
	case 22541ULL: goto x86_l_580d;
	case 22544ULL: goto x86_l_5810;
	case 22547ULL: goto x86_l_5813;
	case 22553ULL: goto x86_l_5819;
	case 22558ULL: goto x86_l_581e;
	case 22561ULL: goto x86_l_5821;
	case 22566ULL: goto x86_l_5826;
	case 22571ULL: goto x86_l_582b;
	case 22574ULL: goto x86_l_582e;
	case 22578ULL: goto x86_l_5832;
	case 22580ULL: goto x86_l_5834;
	case 22582ULL: goto x86_l_5836;
	case 22585ULL: goto x86_l_5839;
	case 22587ULL: goto x86_l_583b;
	case 22594ULL: goto x86_l_5842;
	case 22600ULL: goto x86_l_5848;
	case 22608ULL: goto x86_l_5850;
	case 22613ULL: goto x86_l_5855;
	case 22618ULL: goto x86_l_585a;
	case 22621ULL: goto x86_l_585d;
	case 22626ULL: goto x86_l_5862;
	case 22632ULL: goto x86_l_5868;
	case 22637ULL: goto x86_l_586d;
	case 22642ULL: goto x86_l_5872;
	case 22647ULL: goto x86_l_5877;
	case 22650ULL: goto x86_l_587a;
	case 22653ULL: goto x86_l_587d;
	case 22659ULL: goto x86_l_5883;
	case 22662ULL: goto x86_l_5886;
	case 22664ULL: goto x86_l_5888;
	case 22669ULL: goto x86_l_588d;
	case 22675ULL: goto x86_l_5893;
	case 22680ULL: goto x86_l_5898;
	case 22682ULL: goto x86_l_589a;
	case 22684ULL: goto x86_l_589c;
	case 22688ULL: goto x86_l_58a0;
	case 22691ULL: goto x86_l_58a3;
	case 22697ULL: goto x86_l_58a9;
	case 22704ULL: goto x86_l_58b0;
	case 22707ULL: goto x86_l_58b3;
	case 22713ULL: goto x86_l_58b9;
	case 22723ULL: goto x86_l_58c3;
	case 22728ULL: goto x86_l_58c8;
	case 22738ULL: goto x86_l_58d2;
	case 22743ULL: goto x86_l_58d7;
	case 22753ULL: goto x86_l_58e1;
	case 22758ULL: goto x86_l_58e6;
	case 22768ULL: goto x86_l_58f0;
	case 22773ULL: goto x86_l_58f5;
	case 22783ULL: goto x86_l_58ff;
	case 22788ULL: goto x86_l_5904;
	case 22798ULL: goto x86_l_590e;
	case 22803ULL: goto x86_l_5913;
	case 22808ULL: goto x86_l_5918;
	case 22813ULL: goto x86_l_591d;
	case 22818ULL: goto x86_l_5922;
	case 22823ULL: goto x86_l_5927;
	case 22825ULL: goto x86_l_5929;
	case 22827ULL: goto x86_l_592b;
	case 22832ULL: goto x86_l_5930;
	case 22839ULL: goto x86_l_5937;
	case 22843ULL: goto x86_l_593b;
	case 22849ULL: goto x86_l_5941;
	case 22854ULL: goto x86_l_5946;
	case 22857ULL: goto x86_l_5949;
	case 22864ULL: goto x86_l_5950;
	case 22868ULL: goto x86_l_5954;
	case 22875ULL: goto x86_l_595b;
	case 22882ULL: goto x86_l_5962;
	case 22890ULL: goto x86_l_596a;
	case 22898ULL: goto x86_l_5972;
	case 22909ULL: goto x86_l_597d;
	case 22912ULL: goto x86_l_5980;
	case 22920ULL: goto x86_l_5988;
	case 22925ULL: goto x86_l_598d;
	case 22934ULL: goto x86_l_5996;
	case 22941ULL: goto x86_l_599d;
	case 22948ULL: goto x86_l_59a4;
	case 22951ULL: goto x86_l_59a7;
	case 22956ULL: goto x86_l_59ac;
	case 22958ULL: goto x86_l_59ae;
	case 22961ULL: goto x86_l_59b1;
	case 22963ULL: goto x86_l_59b3;
	case 22966ULL: goto x86_l_59b6;
	case 22971ULL: goto x86_l_59bb;
	case 22978ULL: goto x86_l_59c2;
	case 22981ULL: goto x86_l_59c5;
	case 22983ULL: goto x86_l_59c7;
	case 22993ULL: goto x86_l_59d1;
	case 22998ULL: goto x86_l_59d6;
	case 23008ULL: goto x86_l_59e0;
	case 23013ULL: goto x86_l_59e5;
	case 23023ULL: goto x86_l_59ef;
	case 23028ULL: goto x86_l_59f4;
	case 23038ULL: goto x86_l_59fe;
	case 23043ULL: goto x86_l_5a03;
	case 23053ULL: goto x86_l_5a0d;
	case 23058ULL: goto x86_l_5a12;
	case 23068ULL: goto x86_l_5a1c;
	case 23073ULL: goto x86_l_5a21;
	case 23078ULL: goto x86_l_5a26;
	case 23083ULL: goto x86_l_5a2b;
	case 23088ULL: goto x86_l_5a30;
	case 23091ULL: goto x86_l_5a33;
	case 23096ULL: goto x86_l_5a38;
	case 23098ULL: goto x86_l_5a3a;
	case 23100ULL: goto x86_l_5a3c;
	case 23105ULL: goto x86_l_5a41;
	case 23108ULL: goto x86_l_5a44;
	case 23114ULL: goto x86_l_5a4a;
	case 23119ULL: goto x86_l_5a4f;
	case 23122ULL: goto x86_l_5a52;
	case 23127ULL: goto x86_l_5a57;
	case 23136ULL: goto x86_l_5a60;
	case 23145ULL: goto x86_l_5a69;
	case 23150ULL: goto x86_l_5a6e;
	case 23153ULL: goto x86_l_5a71;
	case 23158ULL: goto x86_l_5a76;
	case 23163ULL: goto x86_l_5a7b;
	case 23169ULL: goto x86_l_5a81;
	case 23174ULL: goto x86_l_5a86;
	case 23179ULL: goto x86_l_5a8b;
	case 23184ULL: goto x86_l_5a90;
	case 23187ULL: goto x86_l_5a93;
	case 23192ULL: goto x86_l_5a98;
	case 23197ULL: goto x86_l_5a9d;
	case 23202ULL: goto x86_l_5aa2;
	case 23207ULL: goto x86_l_5aa7;
	case 23213ULL: goto x86_l_5aad;
	case 23218ULL: goto x86_l_5ab2;
	case 23223ULL: goto x86_l_5ab7;
	case 23228ULL: goto x86_l_5abc;
	case 23231ULL: goto x86_l_5abf;
	case 23237ULL: goto x86_l_5ac5;
	case 23243ULL: goto x86_l_5acb;
	case 23248ULL: goto x86_l_5ad0;
	case 23251ULL: goto x86_l_5ad3;
	case 23257ULL: goto x86_l_5ad9;
	case 23262ULL: goto x86_l_5ade;
	case 23265ULL: goto x86_l_5ae1;
	case 23270ULL: goto x86_l_5ae6;
	case 23275ULL: goto x86_l_5aeb;
	case 23281ULL: goto x86_l_5af1;
	case 23286ULL: goto x86_l_5af6;
	case 23291ULL: goto x86_l_5afb;
	case 23296ULL: goto x86_l_5b00;
	case 23299ULL: goto x86_l_5b03;
	case 23302ULL: goto x86_l_5b06;
	case 23308ULL: goto x86_l_5b0c;
	case 23313ULL: goto x86_l_5b11;
	case 23318ULL: goto x86_l_5b16;
	case 23323ULL: goto x86_l_5b1b;
	case 23328ULL: goto x86_l_5b20;
	case 23334ULL: goto x86_l_5b26;
	case 23339ULL: goto x86_l_5b2b;
	case 23344ULL: goto x86_l_5b30;
	case 23349ULL: goto x86_l_5b35;
	case 23352ULL: goto x86_l_5b38;
	case 23355ULL: goto x86_l_5b3b;
	case 23361ULL: goto x86_l_5b41;
	case 23366ULL: goto x86_l_5b46;
	case 23371ULL: goto x86_l_5b4b;
	case 23376ULL: goto x86_l_5b50;
	case 23381ULL: goto x86_l_5b55;
	case 23387ULL: goto x86_l_5b5b;
	case 23392ULL: goto x86_l_5b60;
	case 23397ULL: goto x86_l_5b65;
	case 23402ULL: goto x86_l_5b6a;
	case 23405ULL: goto x86_l_5b6d;
	case 23408ULL: goto x86_l_5b70;
	case 23414ULL: goto x86_l_5b76;
	case 23419ULL: goto x86_l_5b7b;
	case 23422ULL: goto x86_l_5b7e;
	case 23427ULL: goto x86_l_5b83;
	case 23432ULL: goto x86_l_5b88;
	case 23435ULL: goto x86_l_5b8b;
	case 23439ULL: goto x86_l_5b8f;
	case 23441ULL: goto x86_l_5b91;
	case 23443ULL: goto x86_l_5b93;
	case 23446ULL: goto x86_l_5b96;
	case 23448ULL: goto x86_l_5b98;
	case 23455ULL: goto x86_l_5b9f;
	case 23461ULL: goto x86_l_5ba5;
	case 23469ULL: goto x86_l_5bad;
	case 23474ULL: goto x86_l_5bb2;
	case 23479ULL: goto x86_l_5bb7;
	case 23482ULL: goto x86_l_5bba;
	case 23487ULL: goto x86_l_5bbf;
	case 23493ULL: goto x86_l_5bc5;
	case 23498ULL: goto x86_l_5bca;
	case 23503ULL: goto x86_l_5bcf;
	case 23508ULL: goto x86_l_5bd4;
	case 23511ULL: goto x86_l_5bd7;
	case 23514ULL: goto x86_l_5bda;
	case 23520ULL: goto x86_l_5be0;
	case 23523ULL: goto x86_l_5be3;
	case 23525ULL: goto x86_l_5be5;
	case 23530ULL: goto x86_l_5bea;
	case 23536ULL: goto x86_l_5bf0;
	case 23541ULL: goto x86_l_5bf5;
	case 23543ULL: goto x86_l_5bf7;
	case 23545ULL: goto x86_l_5bf9;
	case 23549ULL: goto x86_l_5bfd;
	case 23552ULL: goto x86_l_5c00;
	case 23558ULL: goto x86_l_5c06;
	case 23565ULL: goto x86_l_5c0d;
	case 23568ULL: goto x86_l_5c10;
	case 23574ULL: goto x86_l_5c16;
	case 23584ULL: goto x86_l_5c20;
	case 23589ULL: goto x86_l_5c25;
	case 23599ULL: goto x86_l_5c2f;
	case 23604ULL: goto x86_l_5c34;
	case 23614ULL: goto x86_l_5c3e;
	case 23619ULL: goto x86_l_5c43;
	case 23629ULL: goto x86_l_5c4d;
	case 23634ULL: goto x86_l_5c52;
	case 23644ULL: goto x86_l_5c5c;
	case 23649ULL: goto x86_l_5c61;
	case 23659ULL: goto x86_l_5c6b;
	case 23664ULL: goto x86_l_5c70;
	case 23669ULL: goto x86_l_5c75;
	case 23674ULL: goto x86_l_5c7a;
	case 23679ULL: goto x86_l_5c7f;
	case 23684ULL: goto x86_l_5c84;
	case 23686ULL: goto x86_l_5c86;
	case 23688ULL: goto x86_l_5c88;
	case 23693ULL: goto x86_l_5c8d;
	case 23700ULL: goto x86_l_5c94;
	case 23704ULL: goto x86_l_5c98;
	case 23710ULL: goto x86_l_5c9e;
	case 23715ULL: goto x86_l_5ca3;
	case 23718ULL: goto x86_l_5ca6;
	case 23725ULL: goto x86_l_5cad;
	case 23729ULL: goto x86_l_5cb1;
	case 23736ULL: goto x86_l_5cb8;
	case 23743ULL: goto x86_l_5cbf;
	case 23751ULL: goto x86_l_5cc7;
	case 23759ULL: goto x86_l_5ccf;
	case 23770ULL: goto x86_l_5cda;
	case 23773ULL: goto x86_l_5cdd;
	case 23781ULL: goto x86_l_5ce5;
	case 23786ULL: goto x86_l_5cea;
	case 23795ULL: goto x86_l_5cf3;
	case 23802ULL: goto x86_l_5cfa;
	case 23809ULL: goto x86_l_5d01;
	case 23812ULL: goto x86_l_5d04;
	case 23817ULL: goto x86_l_5d09;
	case 23819ULL: goto x86_l_5d0b;
	case 23822ULL: goto x86_l_5d0e;
	case 23824ULL: goto x86_l_5d10;
	case 23827ULL: goto x86_l_5d13;
	case 23832ULL: goto x86_l_5d18;
	case 23839ULL: goto x86_l_5d1f;
	case 23842ULL: goto x86_l_5d22;
	case 23844ULL: goto x86_l_5d24;
	case 23854ULL: goto x86_l_5d2e;
	case 23859ULL: goto x86_l_5d33;
	case 23869ULL: goto x86_l_5d3d;
	case 23874ULL: goto x86_l_5d42;
	case 23884ULL: goto x86_l_5d4c;
	case 23889ULL: goto x86_l_5d51;
	case 23899ULL: goto x86_l_5d5b;
	case 23904ULL: goto x86_l_5d60;
	case 23914ULL: goto x86_l_5d6a;
	case 23919ULL: goto x86_l_5d6f;
	case 23929ULL: goto x86_l_5d79;
	case 23934ULL: goto x86_l_5d7e;
	case 23939ULL: goto x86_l_5d83;
	case 23944ULL: goto x86_l_5d88;
	case 23949ULL: goto x86_l_5d8d;
	case 23952ULL: goto x86_l_5d90;
	case 23957ULL: goto x86_l_5d95;
	case 23959ULL: goto x86_l_5d97;
	case 23961ULL: goto x86_l_5d99;
	case 23966ULL: goto x86_l_5d9e;
	case 23969ULL: goto x86_l_5da1;
	case 23975ULL: goto x86_l_5da7;
	case 23980ULL: goto x86_l_5dac;
	case 23983ULL: goto x86_l_5daf;
	case 23988ULL: goto x86_l_5db4;
	case 23997ULL: goto x86_l_5dbd;
	case 24006ULL: goto x86_l_5dc6;
	case 24011ULL: goto x86_l_5dcb;
	case 24014ULL: goto x86_l_5dce;
	case 24019ULL: goto x86_l_5dd3;
	case 24024ULL: goto x86_l_5dd8;
	case 24030ULL: goto x86_l_5dde;
	case 24035ULL: goto x86_l_5de3;
	case 24040ULL: goto x86_l_5de8;
	case 24045ULL: goto x86_l_5ded;
	case 24048ULL: goto x86_l_5df0;
	case 24053ULL: goto x86_l_5df5;
	case 24058ULL: goto x86_l_5dfa;
	case 24063ULL: goto x86_l_5dff;
	case 24068ULL: goto x86_l_5e04;
	case 24074ULL: goto x86_l_5e0a;
	case 24079ULL: goto x86_l_5e0f;
	case 24084ULL: goto x86_l_5e14;
	case 24089ULL: goto x86_l_5e19;
	case 24092ULL: goto x86_l_5e1c;
	case 24098ULL: goto x86_l_5e22;
	case 24104ULL: goto x86_l_5e28;
	case 24109ULL: goto x86_l_5e2d;
	case 24112ULL: goto x86_l_5e30;
	case 24118ULL: goto x86_l_5e36;
	case 24123ULL: goto x86_l_5e3b;
	case 24126ULL: goto x86_l_5e3e;
	case 24131ULL: goto x86_l_5e43;
	case 24136ULL: goto x86_l_5e48;
	case 24142ULL: goto x86_l_5e4e;
	case 24147ULL: goto x86_l_5e53;
	case 24152ULL: goto x86_l_5e58;
	case 24157ULL: goto x86_l_5e5d;
	case 24160ULL: goto x86_l_5e60;
	case 24163ULL: goto x86_l_5e63;
	case 24169ULL: goto x86_l_5e69;
	case 24174ULL: goto x86_l_5e6e;
	case 24179ULL: goto x86_l_5e73;
	case 24184ULL: goto x86_l_5e78;
	case 24189ULL: goto x86_l_5e7d;
	case 24195ULL: goto x86_l_5e83;
	case 24200ULL: goto x86_l_5e88;
	case 24205ULL: goto x86_l_5e8d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_56df:
	/* 0x56df: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56e4:
	/* 0x56e4: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_56e7:
	/* 0x56e7: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_56ed:
	/* 0x56ed: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_56f2:
	/* 0x56f2: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_56f5:
	/* 0x56f5: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56fa:
	/* 0x56fa: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5703:
	/* 0x5703: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_570c:
	/* 0x570c: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_5711:
	/* 0x5711: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5714:
	/* 0x5714: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5719:
	/* 0x5719: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_571e:
	/* 0x571e: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5724:
	/* 0x5724: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_5729:
	/* 0x5729: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_572e:
	/* 0x572e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5733:
	/* 0x5733: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5736:
	/* 0x5736: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_573b:
	/* 0x573b: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5740:
	/* 0x5740: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5745:
	/* 0x5745: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_574a:
	/* 0x574a: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5750:
	/* 0x5750: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_5755:
	/* 0x5755: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_575a:
	/* 0x575a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_575f:
	/* 0x575f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5762:
	/* 0x5762: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5768:
	/* 0x5768: je     583b <perf_unwind_ruby+0x583b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_583b;
	}
x86_l_576e:
	/* 0x576e: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5773:
	/* 0x5773: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5776:
	/* 0x5776: je     583b <perf_unwind_ruby+0x583b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_583b;
	}
x86_l_577c:
	/* 0x577c: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_5781:
	/* 0x5781: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5784:
	/* 0x5784: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5789:
	/* 0x5789: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_578e:
	/* 0x578e: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5794:
	/* 0x5794: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_5799:
	/* 0x5799: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_579e:
	/* 0x579e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57a3:
	/* 0x57a3: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_57a6:
	/* 0x57a6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_57a9:
	/* 0x57a9: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_57af:
	/* 0x57af: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_57b4:
	/* 0x57b4: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_57b9:
	/* 0x57b9: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_57be:
	/* 0x57be: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_57c3:
	/* 0x57c3: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_57c9:
	/* 0x57c9: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_57ce:
	/* 0x57ce: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_57d3:
	/* 0x57d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57d8:
	/* 0x57d8: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_57db:
	/* 0x57db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_57de:
	/* 0x57de: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_57e4:
	/* 0x57e4: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_57e9:
	/* 0x57e9: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_57ee:
	/* 0x57ee: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_57f3:
	/* 0x57f3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_57f8:
	/* 0x57f8: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_57fe:
	/* 0x57fe: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_5803:
	/* 0x5803: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5808:
	/* 0x5808: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_580d:
	/* 0x580d: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5810:
	/* 0x5810: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5813:
	/* 0x5813: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_5819:
	/* 0x5819: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_581e:
	/* 0x581e: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_5821:
	/* 0x5821: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_5826:
	/* 0x5826: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_582b:
	/* 0x582b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_582e:
	/* 0x582e: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_5832:
	/* 0x5832: je     5898 <perf_unwind_ruby+0x5898> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5898;
	}
x86_l_5834:
	/* 0x5834: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5836:
	/* 0x5836: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_5839:
	/* 0x5839: jmp    589c <perf_unwind_ruby+0x589c> */
	goto x86_l_589c;
x86_l_583b:
	/* 0x583b: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_5842:
	/* 0x5842: jb     5a3c <perf_unwind_ruby+0x5a3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5a3c;
	}
x86_l_5848:
	/* 0x5848: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5850:
	/* 0x5850: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_5855:
	/* 0x5855: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_585a:
	/* 0x585a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_585d:
	/* 0x585d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5862:
	/* 0x5862: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5868:
	/* 0x5868: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_586d:
	/* 0x586d: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5872:
	/* 0x5872: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5877:
	/* 0x5877: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_587a:
	/* 0x587a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_587d:
	/* 0x587d: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_5883:
	/* 0x5883: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5886:
	/* 0x5886: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_5888:
	/* 0x5888: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_588d:
	/* 0x588d: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_5893:
	/* 0x5893: jmp    5a3c <perf_unwind_ruby+0x5a3c> */
	goto x86_l_5a3c;
x86_l_5898:
	/* 0x5898: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_589a:
	/* 0x589a: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_589c:
	/* 0x589c: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_58a0:
	/* 0x58a0: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_58a3:
	/* 0x58a3: jbe    5930 <perf_unwind_ruby+0x5930> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_5930;
	}
x86_l_58a9:
	/* 0x58a9: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_58b0:
	/* 0x58b0: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58b3:
	/* 0x58b3: je     5a3c <perf_unwind_ruby+0x5a3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a3c;
	}
x86_l_58b9:
	/* 0x58b9: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_58c3:
	/* 0x58c3: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_58c8:
	/* 0x58c8: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_58d2:
	/* 0x58d2: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_58d7:
	/* 0x58d7: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_58e1:
	/* 0x58e1: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_58e6:
	/* 0x58e6: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_58f0:
	/* 0x58f0: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_58f5:
	/* 0x58f5: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_58ff:
	/* 0x58ff: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5904:
	/* 0x5904: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_590e:
	/* 0x590e: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5913:
	/* 0x5913: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5918:
	/* 0x5918: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_591d:
	/* 0x591d: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5922:
	/* 0x5922: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_5927:
	/* 0x5927: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5929:
	/* 0x5929: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_592b:
	/* 0x592b: jmp    5a3c <perf_unwind_ruby+0x5a3c> */
	goto x86_l_5a3c;
x86_l_5930:
	/* 0x5930: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_5937:
	/* 0x5937: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_593b:
	/* 0x593b: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_5941:
	/* 0x5941: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5946:
	/* 0x5946: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5949:
	/* 0x5949: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_5950:
	/* 0x5950: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_5954:
	/* 0x5954: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_595b:
	/* 0x595b: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5962:
	/* 0x5962: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_596a:
	/* 0x596a: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_5972:
	/* 0x5972: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_597d:
	/* 0x597d: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5980:
	/* 0x5980: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_5988:
	/* 0x5988: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_598d:
	/* 0x598d: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_5996:
	/* 0x5996: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_599d:
	/* 0x599d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_59a4:
	/* 0x59a4: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_59a7:
	/* 0x59a7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_59ac:
	/* 0x59ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59ae:
	/* 0x59ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_59b1:
	/* 0x59b1: je     59bb <perf_unwind_ruby+0x59bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59bb;
	}
x86_l_59b3:
	/* 0x59b3: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_59b6:
	/* 0x59b6: jmp    5a3c <perf_unwind_ruby+0x5a3c> */
	goto x86_l_5a3c;
x86_l_59bb:
	/* 0x59bb: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_59c2:
	/* 0x59c2: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59c5:
	/* 0x59c5: je     5a3c <perf_unwind_ruby+0x5a3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a3c;
	}
x86_l_59c7:
	/* 0x59c7: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_59d1:
	/* 0x59d1: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_59d6:
	/* 0x59d6: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_59e0:
	/* 0x59e0: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_59e5:
	/* 0x59e5: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_59ef:
	/* 0x59ef: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_59f4:
	/* 0x59f4: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_59fe:
	/* 0x59fe: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5a03:
	/* 0x5a03: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_5a0d:
	/* 0x5a0d: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5a12:
	/* 0x5a12: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_5a1c:
	/* 0x5a1c: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5a21:
	/* 0x5a21: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5a26:
	/* 0x5a26: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_5a2b:
	/* 0x5a2b: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5a30:
	/* 0x5a30: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a33:
	/* 0x5a33: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_5a38:
	/* 0x5a38: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5a3a:
	/* 0x5a3a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5a3c:
	/* 0x5a3c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a41:
	/* 0x5a41: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_5a44:
	/* 0x5a44: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_5a4a:
	/* 0x5a4a: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_5a4f:
	/* 0x5a4f: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5a52:
	/* 0x5a52: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a57:
	/* 0x5a57: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5a60:
	/* 0x5a60: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5a69:
	/* 0x5a69: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_5a6e:
	/* 0x5a6e: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5a71:
	/* 0x5a71: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5a76:
	/* 0x5a76: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_5a7b:
	/* 0x5a7b: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5a81:
	/* 0x5a81: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_5a86:
	/* 0x5a86: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5a8b:
	/* 0x5a8b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a90:
	/* 0x5a90: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5a93:
	/* 0x5a93: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_5a98:
	/* 0x5a98: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5a9d:
	/* 0x5a9d: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5aa2:
	/* 0x5aa2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5aa7:
	/* 0x5aa7: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5aad:
	/* 0x5aad: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_5ab2:
	/* 0x5ab2: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5ab7:
	/* 0x5ab7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5abc:
	/* 0x5abc: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5abf:
	/* 0x5abf: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5ac5:
	/* 0x5ac5: je     5b98 <perf_unwind_ruby+0x5b98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b98;
	}
x86_l_5acb:
	/* 0x5acb: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5ad0:
	/* 0x5ad0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5ad3:
	/* 0x5ad3: je     5b98 <perf_unwind_ruby+0x5b98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b98;
	}
x86_l_5ad9:
	/* 0x5ad9: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_5ade:
	/* 0x5ade: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5ae1:
	/* 0x5ae1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ae6:
	/* 0x5ae6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5aeb:
	/* 0x5aeb: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5af1:
	/* 0x5af1: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_5af6:
	/* 0x5af6: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_5afb:
	/* 0x5afb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b00:
	/* 0x5b00: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5b03:
	/* 0x5b03: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b06:
	/* 0x5b06: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_5b0c:
	/* 0x5b0c: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_5b11:
	/* 0x5b11: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5b16:
	/* 0x5b16: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5b1b:
	/* 0x5b1b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5b20:
	/* 0x5b20: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5b26:
	/* 0x5b26: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_5b2b:
	/* 0x5b2b: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5b30:
	/* 0x5b30: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b35:
	/* 0x5b35: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5b38:
	/* 0x5b38: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b3b:
	/* 0x5b3b: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_5b41:
	/* 0x5b41: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_5b46:
	/* 0x5b46: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5b4b:
	/* 0x5b4b: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_5b50:
	/* 0x5b50: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_5b55:
	/* 0x5b55: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5b5b:
	/* 0x5b5b: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_5b60:
	/* 0x5b60: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5b65:
	/* 0x5b65: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5b6a:
	/* 0x5b6a: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5b6d:
	/* 0x5b6d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b70:
	/* 0x5b70: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_5b76:
	/* 0x5b76: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b7b:
	/* 0x5b7b: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_5b7e:
	/* 0x5b7e: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_5b83:
	/* 0x5b83: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_5b88:
	/* 0x5b88: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5b8b:
	/* 0x5b8b: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_5b8f:
	/* 0x5b8f: je     5bf5 <perf_unwind_ruby+0x5bf5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5bf5;
	}
x86_l_5b91:
	/* 0x5b91: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b93:
	/* 0x5b93: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_5b96:
	/* 0x5b96: jmp    5bf9 <perf_unwind_ruby+0x5bf9> */
	goto x86_l_5bf9;
x86_l_5b98:
	/* 0x5b98: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_5b9f:
	/* 0x5b9f: jb     5d99 <perf_unwind_ruby+0x5d99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5d99;
	}
x86_l_5ba5:
	/* 0x5ba5: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bad:
	/* 0x5bad: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_5bb2:
	/* 0x5bb2: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5bb7:
	/* 0x5bb7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5bba:
	/* 0x5bba: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5bbf:
	/* 0x5bbf: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5bc5:
	/* 0x5bc5: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_5bca:
	/* 0x5bca: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5bcf:
	/* 0x5bcf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5bd4:
	/* 0x5bd4: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5bd7:
	/* 0x5bd7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5bda:
	/* 0x5bda: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_5be0:
	/* 0x5be0: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5be3:
	/* 0x5be3: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_5be5:
	/* 0x5be5: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_5bea:
	/* 0x5bea: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_5bf0:
	/* 0x5bf0: jmp    5d99 <perf_unwind_ruby+0x5d99> */
	goto x86_l_5d99;
x86_l_5bf5:
	/* 0x5bf5: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bf7:
	/* 0x5bf7: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_5bf9:
	/* 0x5bf9: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_5bfd:
	/* 0x5bfd: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_5c00:
	/* 0x5c00: jbe    5c8d <perf_unwind_ruby+0x5c8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_5c8d;
	}
x86_l_5c06:
	/* 0x5c06: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5c0d:
	/* 0x5c0d: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c10:
	/* 0x5c10: je     5d99 <perf_unwind_ruby+0x5d99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d99;
	}
x86_l_5c16:
	/* 0x5c16: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_5c20:
	/* 0x5c20: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_5c25:
	/* 0x5c25: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_5c2f:
	/* 0x5c2f: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5c34:
	/* 0x5c34: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_5c3e:
	/* 0x5c3e: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5c43:
	/* 0x5c43: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_5c4d:
	/* 0x5c4d: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5c52:
	/* 0x5c52: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_5c5c:
	/* 0x5c5c: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5c61:
	/* 0x5c61: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_5c6b:
	/* 0x5c6b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5c70:
	/* 0x5c70: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5c75:
	/* 0x5c75: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5c7a:
	/* 0x5c7a: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5c7f:
	/* 0x5c7f: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_5c84:
	/* 0x5c84: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c86:
	/* 0x5c86: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5c88:
	/* 0x5c88: jmp    5d99 <perf_unwind_ruby+0x5d99> */
	goto x86_l_5d99;
x86_l_5c8d:
	/* 0x5c8d: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_5c94:
	/* 0x5c94: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_5c98:
	/* 0x5c98: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_5c9e:
	/* 0x5c9e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ca3:
	/* 0x5ca3: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5ca6:
	/* 0x5ca6: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_5cad:
	/* 0x5cad: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_5cb1:
	/* 0x5cb1: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_5cb8:
	/* 0x5cb8: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cbf:
	/* 0x5cbf: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_5cc7:
	/* 0x5cc7: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_5ccf:
	/* 0x5ccf: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_5cda:
	/* 0x5cda: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cdd:
	/* 0x5cdd: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_5ce5:
	/* 0x5ce5: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_5cea:
	/* 0x5cea: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_5cf3:
	/* 0x5cf3: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_5cfa:
	/* 0x5cfa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_5d01:
	/* 0x5d01: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_5d04:
	/* 0x5d04: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5d09:
	/* 0x5d09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d0b:
	/* 0x5d0b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5d0e:
	/* 0x5d0e: je     5d18 <perf_unwind_ruby+0x5d18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d18;
	}
x86_l_5d10:
	/* 0x5d10: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_5d13:
	/* 0x5d13: jmp    5d99 <perf_unwind_ruby+0x5d99> */
	goto x86_l_5d99;
x86_l_5d18:
	/* 0x5d18: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5d1f:
	/* 0x5d1f: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d22:
	/* 0x5d22: je     5d99 <perf_unwind_ruby+0x5d99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d99;
	}
x86_l_5d24:
	/* 0x5d24: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_5d2e:
	/* 0x5d2e: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_5d33:
	/* 0x5d33: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_5d3d:
	/* 0x5d3d: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5d42:
	/* 0x5d42: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_5d4c:
	/* 0x5d4c: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5d51:
	/* 0x5d51: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_5d5b:
	/* 0x5d5b: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5d60:
	/* 0x5d60: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_5d6a:
	/* 0x5d6a: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5d6f:
	/* 0x5d6f: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_5d79:
	/* 0x5d79: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5d7e:
	/* 0x5d7e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5d83:
	/* 0x5d83: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_5d88:
	/* 0x5d88: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5d8d:
	/* 0x5d8d: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d90:
	/* 0x5d90: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_5d95:
	/* 0x5d95: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d97:
	/* 0x5d97: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5d99:
	/* 0x5d99: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d9e:
	/* 0x5d9e: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_5da1:
	/* 0x5da1: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_5da7:
	/* 0x5da7: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_5dac:
	/* 0x5dac: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5daf:
	/* 0x5daf: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5db4:
	/* 0x5db4: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5dbd:
	/* 0x5dbd: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5dc6:
	/* 0x5dc6: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_5dcb:
	/* 0x5dcb: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5dce:
	/* 0x5dce: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5dd3:
	/* 0x5dd3: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_5dd8:
	/* 0x5dd8: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5dde:
	/* 0x5dde: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_5de3:
	/* 0x5de3: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5de8:
	/* 0x5de8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ded:
	/* 0x5ded: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5df0:
	/* 0x5df0: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_5df5:
	/* 0x5df5: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5dfa:
	/* 0x5dfa: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5dff:
	/* 0x5dff: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5e04:
	/* 0x5e04: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5e0a:
	/* 0x5e0a: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_5e0f:
	/* 0x5e0f: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5e14:
	/* 0x5e14: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e19:
	/* 0x5e19: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5e1c:
	/* 0x5e1c: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5e22:
	/* 0x5e22: je     5ef5 <perf_unwind_ruby+0x5ef5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24309ULL;
	}
x86_l_5e28:
	/* 0x5e28: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e2d:
	/* 0x5e2d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5e30:
	/* 0x5e30: je     5ef5 <perf_unwind_ruby+0x5ef5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24309ULL;
	}
x86_l_5e36:
	/* 0x5e36: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_5e3b:
	/* 0x5e3b: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5e3e:
	/* 0x5e3e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e43:
	/* 0x5e43: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5e48:
	/* 0x5e48: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5e4e:
	/* 0x5e4e: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_5e53:
	/* 0x5e53: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_5e58:
	/* 0x5e58: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e5d:
	/* 0x5e5d: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5e60:
	/* 0x5e60: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5e63:
	/* 0x5e63: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_5e69:
	/* 0x5e69: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_5e6e:
	/* 0x5e6e: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5e73:
	/* 0x5e73: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5e78:
	/* 0x5e78: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5e7d:
	/* 0x5e7d: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5e83:
	/* 0x5e83: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_5e88:
	/* 0x5e88: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5e8d:
	/* 0x5e8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 24210ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 24210ULL: goto x86_l_5e92;
	case 24213ULL: goto x86_l_5e95;
	case 24216ULL: goto x86_l_5e98;
	case 24222ULL: goto x86_l_5e9e;
	case 24227ULL: goto x86_l_5ea3;
	case 24232ULL: goto x86_l_5ea8;
	case 24237ULL: goto x86_l_5ead;
	case 24242ULL: goto x86_l_5eb2;
	case 24248ULL: goto x86_l_5eb8;
	case 24253ULL: goto x86_l_5ebd;
	case 24258ULL: goto x86_l_5ec2;
	case 24263ULL: goto x86_l_5ec7;
	case 24266ULL: goto x86_l_5eca;
	case 24269ULL: goto x86_l_5ecd;
	case 24275ULL: goto x86_l_5ed3;
	case 24280ULL: goto x86_l_5ed8;
	case 24283ULL: goto x86_l_5edb;
	case 24288ULL: goto x86_l_5ee0;
	case 24293ULL: goto x86_l_5ee5;
	case 24296ULL: goto x86_l_5ee8;
	case 24300ULL: goto x86_l_5eec;
	case 24302ULL: goto x86_l_5eee;
	case 24304ULL: goto x86_l_5ef0;
	case 24307ULL: goto x86_l_5ef3;
	case 24309ULL: goto x86_l_5ef5;
	case 24316ULL: goto x86_l_5efc;
	case 24322ULL: goto x86_l_5f02;
	case 24330ULL: goto x86_l_5f0a;
	case 24335ULL: goto x86_l_5f0f;
	case 24340ULL: goto x86_l_5f14;
	case 24343ULL: goto x86_l_5f17;
	case 24348ULL: goto x86_l_5f1c;
	case 24354ULL: goto x86_l_5f22;
	case 24359ULL: goto x86_l_5f27;
	case 24364ULL: goto x86_l_5f2c;
	case 24369ULL: goto x86_l_5f31;
	case 24372ULL: goto x86_l_5f34;
	case 24375ULL: goto x86_l_5f37;
	case 24381ULL: goto x86_l_5f3d;
	case 24384ULL: goto x86_l_5f40;
	case 24386ULL: goto x86_l_5f42;
	case 24391ULL: goto x86_l_5f47;
	case 24397ULL: goto x86_l_5f4d;
	case 24402ULL: goto x86_l_5f52;
	case 24404ULL: goto x86_l_5f54;
	case 24406ULL: goto x86_l_5f56;
	case 24410ULL: goto x86_l_5f5a;
	case 24413ULL: goto x86_l_5f5d;
	case 24419ULL: goto x86_l_5f63;
	case 24426ULL: goto x86_l_5f6a;
	case 24429ULL: goto x86_l_5f6d;
	case 24435ULL: goto x86_l_5f73;
	case 24445ULL: goto x86_l_5f7d;
	case 24450ULL: goto x86_l_5f82;
	case 24460ULL: goto x86_l_5f8c;
	case 24465ULL: goto x86_l_5f91;
	case 24475ULL: goto x86_l_5f9b;
	case 24480ULL: goto x86_l_5fa0;
	case 24490ULL: goto x86_l_5faa;
	case 24495ULL: goto x86_l_5faf;
	case 24505ULL: goto x86_l_5fb9;
	case 24510ULL: goto x86_l_5fbe;
	case 24520ULL: goto x86_l_5fc8;
	case 24525ULL: goto x86_l_5fcd;
	case 24530ULL: goto x86_l_5fd2;
	case 24535ULL: goto x86_l_5fd7;
	case 24540ULL: goto x86_l_5fdc;
	case 24545ULL: goto x86_l_5fe1;
	case 24547ULL: goto x86_l_5fe3;
	case 24549ULL: goto x86_l_5fe5;
	case 24554ULL: goto x86_l_5fea;
	case 24561ULL: goto x86_l_5ff1;
	case 24565ULL: goto x86_l_5ff5;
	case 24571ULL: goto x86_l_5ffb;
	case 24576ULL: goto x86_l_6000;
	case 24579ULL: goto x86_l_6003;
	case 24586ULL: goto x86_l_600a;
	case 24590ULL: goto x86_l_600e;
	case 24597ULL: goto x86_l_6015;
	case 24604ULL: goto x86_l_601c;
	case 24612ULL: goto x86_l_6024;
	case 24620ULL: goto x86_l_602c;
	case 24631ULL: goto x86_l_6037;
	case 24634ULL: goto x86_l_603a;
	case 24642ULL: goto x86_l_6042;
	case 24647ULL: goto x86_l_6047;
	case 24656ULL: goto x86_l_6050;
	case 24663ULL: goto x86_l_6057;
	case 24670ULL: goto x86_l_605e;
	case 24673ULL: goto x86_l_6061;
	case 24678ULL: goto x86_l_6066;
	case 24680ULL: goto x86_l_6068;
	case 24683ULL: goto x86_l_606b;
	case 24685ULL: goto x86_l_606d;
	case 24688ULL: goto x86_l_6070;
	case 24693ULL: goto x86_l_6075;
	case 24700ULL: goto x86_l_607c;
	case 24703ULL: goto x86_l_607f;
	case 24705ULL: goto x86_l_6081;
	case 24715ULL: goto x86_l_608b;
	case 24720ULL: goto x86_l_6090;
	case 24730ULL: goto x86_l_609a;
	case 24735ULL: goto x86_l_609f;
	case 24745ULL: goto x86_l_60a9;
	case 24750ULL: goto x86_l_60ae;
	case 24760ULL: goto x86_l_60b8;
	case 24765ULL: goto x86_l_60bd;
	case 24775ULL: goto x86_l_60c7;
	case 24780ULL: goto x86_l_60cc;
	case 24790ULL: goto x86_l_60d6;
	case 24795ULL: goto x86_l_60db;
	case 24800ULL: goto x86_l_60e0;
	case 24805ULL: goto x86_l_60e5;
	case 24810ULL: goto x86_l_60ea;
	case 24813ULL: goto x86_l_60ed;
	case 24818ULL: goto x86_l_60f2;
	case 24820ULL: goto x86_l_60f4;
	case 24822ULL: goto x86_l_60f6;
	case 24827ULL: goto x86_l_60fb;
	case 24830ULL: goto x86_l_60fe;
	case 24836ULL: goto x86_l_6104;
	case 24841ULL: goto x86_l_6109;
	case 24844ULL: goto x86_l_610c;
	case 24849ULL: goto x86_l_6111;
	case 24858ULL: goto x86_l_611a;
	case 24867ULL: goto x86_l_6123;
	case 24872ULL: goto x86_l_6128;
	case 24875ULL: goto x86_l_612b;
	case 24880ULL: goto x86_l_6130;
	case 24885ULL: goto x86_l_6135;
	case 24891ULL: goto x86_l_613b;
	case 24896ULL: goto x86_l_6140;
	case 24901ULL: goto x86_l_6145;
	case 24906ULL: goto x86_l_614a;
	case 24909ULL: goto x86_l_614d;
	case 24914ULL: goto x86_l_6152;
	case 24919ULL: goto x86_l_6157;
	case 24924ULL: goto x86_l_615c;
	case 24929ULL: goto x86_l_6161;
	case 24935ULL: goto x86_l_6167;
	case 24940ULL: goto x86_l_616c;
	case 24945ULL: goto x86_l_6171;
	case 24950ULL: goto x86_l_6176;
	case 24953ULL: goto x86_l_6179;
	case 24959ULL: goto x86_l_617f;
	case 24965ULL: goto x86_l_6185;
	case 24970ULL: goto x86_l_618a;
	case 24973ULL: goto x86_l_618d;
	case 24979ULL: goto x86_l_6193;
	case 24984ULL: goto x86_l_6198;
	case 24987ULL: goto x86_l_619b;
	case 24992ULL: goto x86_l_61a0;
	case 24997ULL: goto x86_l_61a5;
	case 25003ULL: goto x86_l_61ab;
	case 25008ULL: goto x86_l_61b0;
	case 25013ULL: goto x86_l_61b5;
	case 25018ULL: goto x86_l_61ba;
	case 25021ULL: goto x86_l_61bd;
	case 25024ULL: goto x86_l_61c0;
	case 25030ULL: goto x86_l_61c6;
	case 25035ULL: goto x86_l_61cb;
	case 25040ULL: goto x86_l_61d0;
	case 25045ULL: goto x86_l_61d5;
	case 25050ULL: goto x86_l_61da;
	case 25056ULL: goto x86_l_61e0;
	case 25061ULL: goto x86_l_61e5;
	case 25066ULL: goto x86_l_61ea;
	case 25071ULL: goto x86_l_61ef;
	case 25074ULL: goto x86_l_61f2;
	case 25077ULL: goto x86_l_61f5;
	case 25083ULL: goto x86_l_61fb;
	case 25088ULL: goto x86_l_6200;
	case 25093ULL: goto x86_l_6205;
	case 25098ULL: goto x86_l_620a;
	case 25103ULL: goto x86_l_620f;
	case 25109ULL: goto x86_l_6215;
	case 25114ULL: goto x86_l_621a;
	case 25119ULL: goto x86_l_621f;
	case 25124ULL: goto x86_l_6224;
	case 25127ULL: goto x86_l_6227;
	case 25130ULL: goto x86_l_622a;
	case 25136ULL: goto x86_l_6230;
	case 25141ULL: goto x86_l_6235;
	case 25144ULL: goto x86_l_6238;
	case 25149ULL: goto x86_l_623d;
	case 25154ULL: goto x86_l_6242;
	case 25157ULL: goto x86_l_6245;
	case 25161ULL: goto x86_l_6249;
	case 25163ULL: goto x86_l_624b;
	case 25165ULL: goto x86_l_624d;
	case 25168ULL: goto x86_l_6250;
	case 25170ULL: goto x86_l_6252;
	case 25177ULL: goto x86_l_6259;
	case 25183ULL: goto x86_l_625f;
	case 25191ULL: goto x86_l_6267;
	case 25196ULL: goto x86_l_626c;
	case 25201ULL: goto x86_l_6271;
	case 25204ULL: goto x86_l_6274;
	case 25209ULL: goto x86_l_6279;
	case 25215ULL: goto x86_l_627f;
	case 25220ULL: goto x86_l_6284;
	case 25225ULL: goto x86_l_6289;
	case 25230ULL: goto x86_l_628e;
	case 25233ULL: goto x86_l_6291;
	case 25236ULL: goto x86_l_6294;
	case 25242ULL: goto x86_l_629a;
	case 25245ULL: goto x86_l_629d;
	case 25247ULL: goto x86_l_629f;
	case 25252ULL: goto x86_l_62a4;
	case 25258ULL: goto x86_l_62aa;
	case 25263ULL: goto x86_l_62af;
	case 25265ULL: goto x86_l_62b1;
	case 25267ULL: goto x86_l_62b3;
	case 25271ULL: goto x86_l_62b7;
	case 25274ULL: goto x86_l_62ba;
	case 25280ULL: goto x86_l_62c0;
	case 25287ULL: goto x86_l_62c7;
	case 25290ULL: goto x86_l_62ca;
	case 25296ULL: goto x86_l_62d0;
	case 25306ULL: goto x86_l_62da;
	case 25311ULL: goto x86_l_62df;
	case 25321ULL: goto x86_l_62e9;
	case 25326ULL: goto x86_l_62ee;
	case 25336ULL: goto x86_l_62f8;
	case 25341ULL: goto x86_l_62fd;
	case 25351ULL: goto x86_l_6307;
	case 25356ULL: goto x86_l_630c;
	case 25366ULL: goto x86_l_6316;
	case 25371ULL: goto x86_l_631b;
	case 25381ULL: goto x86_l_6325;
	case 25386ULL: goto x86_l_632a;
	case 25391ULL: goto x86_l_632f;
	case 25396ULL: goto x86_l_6334;
	case 25401ULL: goto x86_l_6339;
	case 25406ULL: goto x86_l_633e;
	case 25408ULL: goto x86_l_6340;
	case 25410ULL: goto x86_l_6342;
	case 25415ULL: goto x86_l_6347;
	case 25422ULL: goto x86_l_634e;
	case 25426ULL: goto x86_l_6352;
	case 25432ULL: goto x86_l_6358;
	case 25437ULL: goto x86_l_635d;
	case 25440ULL: goto x86_l_6360;
	case 25447ULL: goto x86_l_6367;
	case 25451ULL: goto x86_l_636b;
	case 25458ULL: goto x86_l_6372;
	case 25465ULL: goto x86_l_6379;
	case 25473ULL: goto x86_l_6381;
	case 25481ULL: goto x86_l_6389;
	case 25492ULL: goto x86_l_6394;
	case 25495ULL: goto x86_l_6397;
	case 25503ULL: goto x86_l_639f;
	case 25508ULL: goto x86_l_63a4;
	case 25517ULL: goto x86_l_63ad;
	case 25524ULL: goto x86_l_63b4;
	case 25531ULL: goto x86_l_63bb;
	case 25534ULL: goto x86_l_63be;
	case 25539ULL: goto x86_l_63c3;
	case 25541ULL: goto x86_l_63c5;
	case 25544ULL: goto x86_l_63c8;
	case 25546ULL: goto x86_l_63ca;
	case 25549ULL: goto x86_l_63cd;
	case 25554ULL: goto x86_l_63d2;
	case 25561ULL: goto x86_l_63d9;
	case 25564ULL: goto x86_l_63dc;
	case 25566ULL: goto x86_l_63de;
	case 25576ULL: goto x86_l_63e8;
	case 25581ULL: goto x86_l_63ed;
	case 25591ULL: goto x86_l_63f7;
	case 25596ULL: goto x86_l_63fc;
	case 25606ULL: goto x86_l_6406;
	case 25611ULL: goto x86_l_640b;
	case 25621ULL: goto x86_l_6415;
	case 25626ULL: goto x86_l_641a;
	case 25636ULL: goto x86_l_6424;
	case 25641ULL: goto x86_l_6429;
	case 25651ULL: goto x86_l_6433;
	case 25656ULL: goto x86_l_6438;
	case 25661ULL: goto x86_l_643d;
	case 25666ULL: goto x86_l_6442;
	case 25671ULL: goto x86_l_6447;
	case 25674ULL: goto x86_l_644a;
	case 25679ULL: goto x86_l_644f;
	case 25681ULL: goto x86_l_6451;
	case 25683ULL: goto x86_l_6453;
	case 25688ULL: goto x86_l_6458;
	case 25691ULL: goto x86_l_645b;
	case 25697ULL: goto x86_l_6461;
	case 25702ULL: goto x86_l_6466;
	case 25705ULL: goto x86_l_6469;
	case 25710ULL: goto x86_l_646e;
	case 25719ULL: goto x86_l_6477;
	case 25728ULL: goto x86_l_6480;
	case 25733ULL: goto x86_l_6485;
	case 25736ULL: goto x86_l_6488;
	case 25741ULL: goto x86_l_648d;
	case 25746ULL: goto x86_l_6492;
	case 25752ULL: goto x86_l_6498;
	case 25757ULL: goto x86_l_649d;
	case 25762ULL: goto x86_l_64a2;
	case 25767ULL: goto x86_l_64a7;
	case 25770ULL: goto x86_l_64aa;
	case 25775ULL: goto x86_l_64af;
	case 25780ULL: goto x86_l_64b4;
	case 25785ULL: goto x86_l_64b9;
	case 25790ULL: goto x86_l_64be;
	case 25796ULL: goto x86_l_64c4;
	case 25801ULL: goto x86_l_64c9;
	case 25806ULL: goto x86_l_64ce;
	case 25811ULL: goto x86_l_64d3;
	case 25814ULL: goto x86_l_64d6;
	case 25820ULL: goto x86_l_64dc;
	case 25826ULL: goto x86_l_64e2;
	case 25831ULL: goto x86_l_64e7;
	case 25834ULL: goto x86_l_64ea;
	case 25840ULL: goto x86_l_64f0;
	case 25845ULL: goto x86_l_64f5;
	case 25848ULL: goto x86_l_64f8;
	case 25853ULL: goto x86_l_64fd;
	case 25858ULL: goto x86_l_6502;
	case 25864ULL: goto x86_l_6508;
	case 25869ULL: goto x86_l_650d;
	case 25874ULL: goto x86_l_6512;
	case 25879ULL: goto x86_l_6517;
	case 25882ULL: goto x86_l_651a;
	case 25885ULL: goto x86_l_651d;
	case 25891ULL: goto x86_l_6523;
	case 25896ULL: goto x86_l_6528;
	case 25901ULL: goto x86_l_652d;
	case 25906ULL: goto x86_l_6532;
	case 25911ULL: goto x86_l_6537;
	case 25917ULL: goto x86_l_653d;
	case 25922ULL: goto x86_l_6542;
	case 25927ULL: goto x86_l_6547;
	case 25932ULL: goto x86_l_654c;
	case 25935ULL: goto x86_l_654f;
	case 25938ULL: goto x86_l_6552;
	case 25944ULL: goto x86_l_6558;
	case 25949ULL: goto x86_l_655d;
	case 25954ULL: goto x86_l_6562;
	case 25959ULL: goto x86_l_6567;
	case 25964ULL: goto x86_l_656c;
	case 25970ULL: goto x86_l_6572;
	case 25975ULL: goto x86_l_6577;
	case 25980ULL: goto x86_l_657c;
	case 25985ULL: goto x86_l_6581;
	case 25988ULL: goto x86_l_6584;
	case 25991ULL: goto x86_l_6587;
	case 25997ULL: goto x86_l_658d;
	case 26002ULL: goto x86_l_6592;
	case 26005ULL: goto x86_l_6595;
	case 26010ULL: goto x86_l_659a;
	case 26015ULL: goto x86_l_659f;
	case 26018ULL: goto x86_l_65a2;
	case 26022ULL: goto x86_l_65a6;
	case 26024ULL: goto x86_l_65a8;
	case 26026ULL: goto x86_l_65aa;
	case 26029ULL: goto x86_l_65ad;
	case 26031ULL: goto x86_l_65af;
	case 26038ULL: goto x86_l_65b6;
	case 26044ULL: goto x86_l_65bc;
	case 26052ULL: goto x86_l_65c4;
	case 26057ULL: goto x86_l_65c9;
	case 26062ULL: goto x86_l_65ce;
	case 26065ULL: goto x86_l_65d1;
	case 26070ULL: goto x86_l_65d6;
	case 26076ULL: goto x86_l_65dc;
	case 26081ULL: goto x86_l_65e1;
	case 26086ULL: goto x86_l_65e6;
	case 26091ULL: goto x86_l_65eb;
	case 26094ULL: goto x86_l_65ee;
	case 26097ULL: goto x86_l_65f1;
	case 26103ULL: goto x86_l_65f7;
	case 26106ULL: goto x86_l_65fa;
	case 26108ULL: goto x86_l_65fc;
	case 26113ULL: goto x86_l_6601;
	case 26119ULL: goto x86_l_6607;
	case 26124ULL: goto x86_l_660c;
	case 26126ULL: goto x86_l_660e;
	case 26128ULL: goto x86_l_6610;
	case 26132ULL: goto x86_l_6614;
	case 26135ULL: goto x86_l_6617;
	case 26141ULL: goto x86_l_661d;
	case 26148ULL: goto x86_l_6624;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5e92:
	/* 0x5e92: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5e95:
	/* 0x5e95: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5e98:
	/* 0x5e98: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_5e9e:
	/* 0x5e9e: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_5ea3:
	/* 0x5ea3: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5ea8:
	/* 0x5ea8: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_5ead:
	/* 0x5ead: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_5eb2:
	/* 0x5eb2: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5eb8:
	/* 0x5eb8: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_5ebd:
	/* 0x5ebd: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5ec2:
	/* 0x5ec2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5ec7:
	/* 0x5ec7: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5eca:
	/* 0x5eca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5ecd:
	/* 0x5ecd: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_5ed3:
	/* 0x5ed3: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ed8:
	/* 0x5ed8: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_5edb:
	/* 0x5edb: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_5ee0:
	/* 0x5ee0: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_5ee5:
	/* 0x5ee5: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5ee8:
	/* 0x5ee8: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_5eec:
	/* 0x5eec: je     5f52 <perf_unwind_ruby+0x5f52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f52;
	}
x86_l_5eee:
	/* 0x5eee: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ef0:
	/* 0x5ef0: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_5ef3:
	/* 0x5ef3: jmp    5f56 <perf_unwind_ruby+0x5f56> */
	goto x86_l_5f56;
x86_l_5ef5:
	/* 0x5ef5: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_5efc:
	/* 0x5efc: jb     60f6 <perf_unwind_ruby+0x60f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_60f6;
	}
x86_l_5f02:
	/* 0x5f02: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f0a:
	/* 0x5f0a: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_5f0f:
	/* 0x5f0f: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5f14:
	/* 0x5f14: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5f17:
	/* 0x5f17: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5f1c:
	/* 0x5f1c: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_5f22:
	/* 0x5f22: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_5f27:
	/* 0x5f27: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5f2c:
	/* 0x5f2c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f31:
	/* 0x5f31: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5f34:
	/* 0x5f34: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5f37:
	/* 0x5f37: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_5f3d:
	/* 0x5f3d: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f40:
	/* 0x5f40: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_5f42:
	/* 0x5f42: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_5f47:
	/* 0x5f47: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_5f4d:
	/* 0x5f4d: jmp    60f6 <perf_unwind_ruby+0x60f6> */
	goto x86_l_60f6;
x86_l_5f52:
	/* 0x5f52: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f54:
	/* 0x5f54: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_5f56:
	/* 0x5f56: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_5f5a:
	/* 0x5f5a: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_5f5d:
	/* 0x5f5d: jbe    5fea <perf_unwind_ruby+0x5fea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_5fea;
	}
x86_l_5f63:
	/* 0x5f63: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5f6a:
	/* 0x5f6a: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f6d:
	/* 0x5f6d: je     60f6 <perf_unwind_ruby+0x60f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_60f6;
	}
x86_l_5f73:
	/* 0x5f73: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_5f7d:
	/* 0x5f7d: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_5f82:
	/* 0x5f82: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_5f8c:
	/* 0x5f8c: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5f91:
	/* 0x5f91: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_5f9b:
	/* 0x5f9b: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5fa0:
	/* 0x5fa0: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_5faa:
	/* 0x5faa: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5faf:
	/* 0x5faf: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_5fb9:
	/* 0x5fb9: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5fbe:
	/* 0x5fbe: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_5fc8:
	/* 0x5fc8: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5fcd:
	/* 0x5fcd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5fd2:
	/* 0x5fd2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5fd7:
	/* 0x5fd7: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5fdc:
	/* 0x5fdc: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_5fe1:
	/* 0x5fe1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fe3:
	/* 0x5fe3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5fe5:
	/* 0x5fe5: jmp    60f6 <perf_unwind_ruby+0x60f6> */
	goto x86_l_60f6;
x86_l_5fea:
	/* 0x5fea: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_5ff1:
	/* 0x5ff1: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_5ff5:
	/* 0x5ff5: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_5ffb:
	/* 0x5ffb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6000:
	/* 0x6000: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_6003:
	/* 0x6003: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_600a:
	/* 0x600a: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_600e:
	/* 0x600e: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_6015:
	/* 0x6015: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_601c:
	/* 0x601c: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_6024:
	/* 0x6024: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_602c:
	/* 0x602c: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_6037:
	/* 0x6037: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_603a:
	/* 0x603a: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_6042:
	/* 0x6042: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_6047:
	/* 0x6047: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_6050:
	/* 0x6050: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_6057:
	/* 0x6057: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_605e:
	/* 0x605e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_6061:
	/* 0x6061: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6066:
	/* 0x6066: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6068:
	/* 0x6068: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_606b:
	/* 0x606b: je     6075 <perf_unwind_ruby+0x6075> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6075;
	}
x86_l_606d:
	/* 0x606d: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6070:
	/* 0x6070: jmp    60f6 <perf_unwind_ruby+0x60f6> */
	goto x86_l_60f6;
x86_l_6075:
	/* 0x6075: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_607c:
	/* 0x607c: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_607f:
	/* 0x607f: je     60f6 <perf_unwind_ruby+0x60f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_60f6;
	}
x86_l_6081:
	/* 0x6081: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_608b:
	/* 0x608b: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_6090:
	/* 0x6090: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_609a:
	/* 0x609a: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_609f:
	/* 0x609f: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_60a9:
	/* 0x60a9: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_60ae:
	/* 0x60ae: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_60b8:
	/* 0x60b8: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_60bd:
	/* 0x60bd: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_60c7:
	/* 0x60c7: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_60cc:
	/* 0x60cc: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_60d6:
	/* 0x60d6: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_60db:
	/* 0x60db: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_60e0:
	/* 0x60e0: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_60e5:
	/* 0x60e5: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_60ea:
	/* 0x60ea: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60ed:
	/* 0x60ed: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_60f2:
	/* 0x60f2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_60f4:
	/* 0x60f4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_60f6:
	/* 0x60f6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60fb:
	/* 0x60fb: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_60fe:
	/* 0x60fe: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_6104:
	/* 0x6104: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_6109:
	/* 0x6109: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_610c:
	/* 0x610c: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6111:
	/* 0x6111: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_611a:
	/* 0x611a: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_6123:
	/* 0x6123: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_6128:
	/* 0x6128: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_612b:
	/* 0x612b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6130:
	/* 0x6130: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6135:
	/* 0x6135: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_613b:
	/* 0x613b: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_6140:
	/* 0x6140: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6145:
	/* 0x6145: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_614a:
	/* 0x614a: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_614d:
	/* 0x614d: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_6152:
	/* 0x6152: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6157:
	/* 0x6157: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_615c:
	/* 0x615c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6161:
	/* 0x6161: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6167:
	/* 0x6167: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_616c:
	/* 0x616c: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6171:
	/* 0x6171: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6176:
	/* 0x6176: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6179:
	/* 0x6179: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_617f:
	/* 0x617f: je     6252 <perf_unwind_ruby+0x6252> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6252;
	}
x86_l_6185:
	/* 0x6185: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_618a:
	/* 0x618a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_618d:
	/* 0x618d: je     6252 <perf_unwind_ruby+0x6252> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6252;
	}
x86_l_6193:
	/* 0x6193: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_6198:
	/* 0x6198: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_619b:
	/* 0x619b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_61a0:
	/* 0x61a0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_61a5:
	/* 0x61a5: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_61ab:
	/* 0x61ab: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_61b0:
	/* 0x61b0: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_61b5:
	/* 0x61b5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_61ba:
	/* 0x61ba: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_61bd:
	/* 0x61bd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_61c0:
	/* 0x61c0: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_61c6:
	/* 0x61c6: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_61cb:
	/* 0x61cb: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_61d0:
	/* 0x61d0: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_61d5:
	/* 0x61d5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_61da:
	/* 0x61da: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_61e0:
	/* 0x61e0: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_61e5:
	/* 0x61e5: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_61ea:
	/* 0x61ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_61ef:
	/* 0x61ef: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_61f2:
	/* 0x61f2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_61f5:
	/* 0x61f5: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_61fb:
	/* 0x61fb: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_6200:
	/* 0x6200: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_6205:
	/* 0x6205: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_620a:
	/* 0x620a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_620f:
	/* 0x620f: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6215:
	/* 0x6215: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_621a:
	/* 0x621a: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_621f:
	/* 0x621f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6224:
	/* 0x6224: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6227:
	/* 0x6227: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_622a:
	/* 0x622a: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_6230:
	/* 0x6230: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6235:
	/* 0x6235: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_6238:
	/* 0x6238: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_623d:
	/* 0x623d: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_6242:
	/* 0x6242: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6245:
	/* 0x6245: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_6249:
	/* 0x6249: je     62af <perf_unwind_ruby+0x62af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_62af;
	}
x86_l_624b:
	/* 0x624b: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_624d:
	/* 0x624d: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_6250:
	/* 0x6250: jmp    62b3 <perf_unwind_ruby+0x62b3> */
	goto x86_l_62b3;
x86_l_6252:
	/* 0x6252: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_6259:
	/* 0x6259: jb     6453 <perf_unwind_ruby+0x6453> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_6453;
	}
x86_l_625f:
	/* 0x625f: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6267:
	/* 0x6267: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_626c:
	/* 0x626c: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6271:
	/* 0x6271: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6274:
	/* 0x6274: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6279:
	/* 0x6279: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_627f:
	/* 0x627f: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_6284:
	/* 0x6284: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6289:
	/* 0x6289: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_628e:
	/* 0x628e: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6291:
	/* 0x6291: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6294:
	/* 0x6294: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_629a:
	/* 0x629a: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_629d:
	/* 0x629d: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_629f:
	/* 0x629f: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_62a4:
	/* 0x62a4: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_62aa:
	/* 0x62aa: jmp    6453 <perf_unwind_ruby+0x6453> */
	goto x86_l_6453;
x86_l_62af:
	/* 0x62af: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_62b1:
	/* 0x62b1: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_62b3:
	/* 0x62b3: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_62b7:
	/* 0x62b7: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_62ba:
	/* 0x62ba: jbe    6347 <perf_unwind_ruby+0x6347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_6347;
	}
x86_l_62c0:
	/* 0x62c0: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_62c7:
	/* 0x62c7: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62ca:
	/* 0x62ca: je     6453 <perf_unwind_ruby+0x6453> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6453;
	}
x86_l_62d0:
	/* 0x62d0: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_62da:
	/* 0x62da: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_62df:
	/* 0x62df: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_62e9:
	/* 0x62e9: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_62ee:
	/* 0x62ee: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_62f8:
	/* 0x62f8: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_62fd:
	/* 0x62fd: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_6307:
	/* 0x6307: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_630c:
	/* 0x630c: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_6316:
	/* 0x6316: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_631b:
	/* 0x631b: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_6325:
	/* 0x6325: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_632a:
	/* 0x632a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_632f:
	/* 0x632f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_6334:
	/* 0x6334: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6339:
	/* 0x6339: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_633e:
	/* 0x633e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6340:
	/* 0x6340: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6342:
	/* 0x6342: jmp    6453 <perf_unwind_ruby+0x6453> */
	goto x86_l_6453;
x86_l_6347:
	/* 0x6347: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_634e:
	/* 0x634e: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_6352:
	/* 0x6352: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_6358:
	/* 0x6358: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_635d:
	/* 0x635d: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_6360:
	/* 0x6360: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_6367:
	/* 0x6367: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_636b:
	/* 0x636b: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_6372:
	/* 0x6372: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6379:
	/* 0x6379: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_6381:
	/* 0x6381: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_6389:
	/* 0x6389: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_6394:
	/* 0x6394: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6397:
	/* 0x6397: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_639f:
	/* 0x639f: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_63a4:
	/* 0x63a4: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_63ad:
	/* 0x63ad: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_63b4:
	/* 0x63b4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_63bb:
	/* 0x63bb: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_63be:
	/* 0x63be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_63c3:
	/* 0x63c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63c5:
	/* 0x63c5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_63c8:
	/* 0x63c8: je     63d2 <perf_unwind_ruby+0x63d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_63d2;
	}
x86_l_63ca:
	/* 0x63ca: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_63cd:
	/* 0x63cd: jmp    6453 <perf_unwind_ruby+0x6453> */
	goto x86_l_6453;
x86_l_63d2:
	/* 0x63d2: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_63d9:
	/* 0x63d9: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_63dc:
	/* 0x63dc: je     6453 <perf_unwind_ruby+0x6453> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6453;
	}
x86_l_63de:
	/* 0x63de: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_63e8:
	/* 0x63e8: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_63ed:
	/* 0x63ed: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_63f7:
	/* 0x63f7: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_63fc:
	/* 0x63fc: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_6406:
	/* 0x6406: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_640b:
	/* 0x640b: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_6415:
	/* 0x6415: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_641a:
	/* 0x641a: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_6424:
	/* 0x6424: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6429:
	/* 0x6429: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_6433:
	/* 0x6433: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6438:
	/* 0x6438: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_643d:
	/* 0x643d: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_6442:
	/* 0x6442: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6447:
	/* 0x6447: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_644a:
	/* 0x644a: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_644f:
	/* 0x644f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6451:
	/* 0x6451: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6453:
	/* 0x6453: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6458:
	/* 0x6458: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_645b:
	/* 0x645b: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_6461:
	/* 0x6461: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_6466:
	/* 0x6466: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6469:
	/* 0x6469: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_646e:
	/* 0x646e: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_6477:
	/* 0x6477: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_6480:
	/* 0x6480: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_6485:
	/* 0x6485: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6488:
	/* 0x6488: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_648d:
	/* 0x648d: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6492:
	/* 0x6492: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6498:
	/* 0x6498: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_649d:
	/* 0x649d: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_64a2:
	/* 0x64a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64a7:
	/* 0x64a7: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_64aa:
	/* 0x64aa: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_64af:
	/* 0x64af: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_64b4:
	/* 0x64b4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_64b9:
	/* 0x64b9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_64be:
	/* 0x64be: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_64c4:
	/* 0x64c4: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_64c9:
	/* 0x64c9: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_64ce:
	/* 0x64ce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64d3:
	/* 0x64d3: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_64d6:
	/* 0x64d6: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_64dc:
	/* 0x64dc: je     65af <perf_unwind_ruby+0x65af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_65af;
	}
x86_l_64e2:
	/* 0x64e2: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_64e7:
	/* 0x64e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_64ea:
	/* 0x64ea: je     65af <perf_unwind_ruby+0x65af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_65af;
	}
x86_l_64f0:
	/* 0x64f0: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_64f5:
	/* 0x64f5: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_64f8:
	/* 0x64f8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64fd:
	/* 0x64fd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6502:
	/* 0x6502: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6508:
	/* 0x6508: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_650d:
	/* 0x650d: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_6512:
	/* 0x6512: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6517:
	/* 0x6517: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_651a:
	/* 0x651a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_651d:
	/* 0x651d: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_6523:
	/* 0x6523: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_6528:
	/* 0x6528: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_652d:
	/* 0x652d: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6532:
	/* 0x6532: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6537:
	/* 0x6537: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_653d:
	/* 0x653d: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_6542:
	/* 0x6542: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_6547:
	/* 0x6547: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_654c:
	/* 0x654c: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_654f:
	/* 0x654f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6552:
	/* 0x6552: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_6558:
	/* 0x6558: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_655d:
	/* 0x655d: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_6562:
	/* 0x6562: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6567:
	/* 0x6567: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_656c:
	/* 0x656c: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6572:
	/* 0x6572: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_6577:
	/* 0x6577: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_657c:
	/* 0x657c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6581:
	/* 0x6581: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6584:
	/* 0x6584: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6587:
	/* 0x6587: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_658d:
	/* 0x658d: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6592:
	/* 0x6592: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_6595:
	/* 0x6595: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_659a:
	/* 0x659a: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_659f:
	/* 0x659f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_65a2:
	/* 0x65a2: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_65a6:
	/* 0x65a6: je     660c <perf_unwind_ruby+0x660c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_660c;
	}
x86_l_65a8:
	/* 0x65a8: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_65aa:
	/* 0x65aa: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_65ad:
	/* 0x65ad: jmp    6610 <perf_unwind_ruby+0x6610> */
	goto x86_l_6610;
x86_l_65af:
	/* 0x65af: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_65b6:
	/* 0x65b6: jb     67b0 <perf_unwind_ruby+0x67b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 26544ULL;
	}
x86_l_65bc:
	/* 0x65bc: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_65c4:
	/* 0x65c4: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_65c9:
	/* 0x65c9: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_65ce:
	/* 0x65ce: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_65d1:
	/* 0x65d1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_65d6:
	/* 0x65d6: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_65dc:
	/* 0x65dc: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_65e1:
	/* 0x65e1: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_65e6:
	/* 0x65e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_65eb:
	/* 0x65eb: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_65ee:
	/* 0x65ee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_65f1:
	/* 0x65f1: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_65f7:
	/* 0x65f7: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_65fa:
	/* 0x65fa: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_65fc:
	/* 0x65fc: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_6601:
	/* 0x6601: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_6607:
	/* 0x6607: jmp    67b0 <perf_unwind_ruby+0x67b0> */
	return 26544ULL;
x86_l_660c:
	/* 0x660c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_660e:
	/* 0x660e: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_6610:
	/* 0x6610: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6614:
	/* 0x6614: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_6617:
	/* 0x6617: jbe    66a4 <perf_unwind_ruby+0x66a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 26276ULL;
	}
x86_l_661d:
	/* 0x661d: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6624:
	/* 0x6624: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 26151ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 26151ULL: goto x86_l_6627;
	case 26157ULL: goto x86_l_662d;
	case 26167ULL: goto x86_l_6637;
	case 26172ULL: goto x86_l_663c;
	case 26182ULL: goto x86_l_6646;
	case 26187ULL: goto x86_l_664b;
	case 26197ULL: goto x86_l_6655;
	case 26202ULL: goto x86_l_665a;
	case 26212ULL: goto x86_l_6664;
	case 26217ULL: goto x86_l_6669;
	case 26227ULL: goto x86_l_6673;
	case 26232ULL: goto x86_l_6678;
	case 26242ULL: goto x86_l_6682;
	case 26247ULL: goto x86_l_6687;
	case 26252ULL: goto x86_l_668c;
	case 26257ULL: goto x86_l_6691;
	case 26262ULL: goto x86_l_6696;
	case 26267ULL: goto x86_l_669b;
	case 26269ULL: goto x86_l_669d;
	case 26271ULL: goto x86_l_669f;
	case 26276ULL: goto x86_l_66a4;
	case 26283ULL: goto x86_l_66ab;
	case 26287ULL: goto x86_l_66af;
	case 26293ULL: goto x86_l_66b5;
	case 26298ULL: goto x86_l_66ba;
	case 26301ULL: goto x86_l_66bd;
	case 26308ULL: goto x86_l_66c4;
	case 26312ULL: goto x86_l_66c8;
	case 26319ULL: goto x86_l_66cf;
	case 26326ULL: goto x86_l_66d6;
	case 26334ULL: goto x86_l_66de;
	case 26342ULL: goto x86_l_66e6;
	case 26353ULL: goto x86_l_66f1;
	case 26356ULL: goto x86_l_66f4;
	case 26364ULL: goto x86_l_66fc;
	case 26369ULL: goto x86_l_6701;
	case 26378ULL: goto x86_l_670a;
	case 26385ULL: goto x86_l_6711;
	case 26392ULL: goto x86_l_6718;
	case 26395ULL: goto x86_l_671b;
	case 26400ULL: goto x86_l_6720;
	case 26402ULL: goto x86_l_6722;
	case 26405ULL: goto x86_l_6725;
	case 26407ULL: goto x86_l_6727;
	case 26410ULL: goto x86_l_672a;
	case 26415ULL: goto x86_l_672f;
	case 26422ULL: goto x86_l_6736;
	case 26425ULL: goto x86_l_6739;
	case 26427ULL: goto x86_l_673b;
	case 26437ULL: goto x86_l_6745;
	case 26442ULL: goto x86_l_674a;
	case 26452ULL: goto x86_l_6754;
	case 26457ULL: goto x86_l_6759;
	case 26467ULL: goto x86_l_6763;
	case 26472ULL: goto x86_l_6768;
	case 26482ULL: goto x86_l_6772;
	case 26487ULL: goto x86_l_6777;
	case 26497ULL: goto x86_l_6781;
	case 26502ULL: goto x86_l_6786;
	case 26512ULL: goto x86_l_6790;
	case 26517ULL: goto x86_l_6795;
	case 26522ULL: goto x86_l_679a;
	case 26527ULL: goto x86_l_679f;
	case 26532ULL: goto x86_l_67a4;
	case 26535ULL: goto x86_l_67a7;
	case 26540ULL: goto x86_l_67ac;
	case 26542ULL: goto x86_l_67ae;
	case 26544ULL: goto x86_l_67b0;
	case 26549ULL: goto x86_l_67b5;
	case 26552ULL: goto x86_l_67b8;
	case 26558ULL: goto x86_l_67be;
	case 26563ULL: goto x86_l_67c3;
	case 26566ULL: goto x86_l_67c6;
	case 26571ULL: goto x86_l_67cb;
	case 26580ULL: goto x86_l_67d4;
	case 26589ULL: goto x86_l_67dd;
	case 26594ULL: goto x86_l_67e2;
	case 26597ULL: goto x86_l_67e5;
	case 26602ULL: goto x86_l_67ea;
	case 26607ULL: goto x86_l_67ef;
	case 26613ULL: goto x86_l_67f5;
	case 26618ULL: goto x86_l_67fa;
	case 26623ULL: goto x86_l_67ff;
	case 26628ULL: goto x86_l_6804;
	case 26631ULL: goto x86_l_6807;
	case 26636ULL: goto x86_l_680c;
	case 26641ULL: goto x86_l_6811;
	case 26646ULL: goto x86_l_6816;
	case 26651ULL: goto x86_l_681b;
	case 26657ULL: goto x86_l_6821;
	case 26662ULL: goto x86_l_6826;
	case 26667ULL: goto x86_l_682b;
	case 26672ULL: goto x86_l_6830;
	case 26675ULL: goto x86_l_6833;
	case 26681ULL: goto x86_l_6839;
	case 26687ULL: goto x86_l_683f;
	case 26692ULL: goto x86_l_6844;
	case 26695ULL: goto x86_l_6847;
	case 26701ULL: goto x86_l_684d;
	case 26706ULL: goto x86_l_6852;
	case 26709ULL: goto x86_l_6855;
	case 26714ULL: goto x86_l_685a;
	case 26719ULL: goto x86_l_685f;
	case 26725ULL: goto x86_l_6865;
	case 26730ULL: goto x86_l_686a;
	case 26735ULL: goto x86_l_686f;
	case 26740ULL: goto x86_l_6874;
	case 26743ULL: goto x86_l_6877;
	case 26746ULL: goto x86_l_687a;
	case 26752ULL: goto x86_l_6880;
	case 26757ULL: goto x86_l_6885;
	case 26762ULL: goto x86_l_688a;
	case 26767ULL: goto x86_l_688f;
	case 26772ULL: goto x86_l_6894;
	case 26778ULL: goto x86_l_689a;
	case 26783ULL: goto x86_l_689f;
	case 26788ULL: goto x86_l_68a4;
	case 26793ULL: goto x86_l_68a9;
	case 26796ULL: goto x86_l_68ac;
	case 26799ULL: goto x86_l_68af;
	case 26805ULL: goto x86_l_68b5;
	case 26810ULL: goto x86_l_68ba;
	case 26815ULL: goto x86_l_68bf;
	case 26820ULL: goto x86_l_68c4;
	case 26825ULL: goto x86_l_68c9;
	case 26831ULL: goto x86_l_68cf;
	case 26836ULL: goto x86_l_68d4;
	case 26841ULL: goto x86_l_68d9;
	case 26846ULL: goto x86_l_68de;
	case 26849ULL: goto x86_l_68e1;
	case 26852ULL: goto x86_l_68e4;
	case 26858ULL: goto x86_l_68ea;
	case 26863ULL: goto x86_l_68ef;
	case 26866ULL: goto x86_l_68f2;
	case 26871ULL: goto x86_l_68f7;
	case 26876ULL: goto x86_l_68fc;
	case 26879ULL: goto x86_l_68ff;
	case 26883ULL: goto x86_l_6903;
	case 26885ULL: goto x86_l_6905;
	case 26887ULL: goto x86_l_6907;
	case 26890ULL: goto x86_l_690a;
	case 26892ULL: goto x86_l_690c;
	case 26899ULL: goto x86_l_6913;
	case 26905ULL: goto x86_l_6919;
	case 26913ULL: goto x86_l_6921;
	case 26918ULL: goto x86_l_6926;
	case 26923ULL: goto x86_l_692b;
	case 26926ULL: goto x86_l_692e;
	case 26931ULL: goto x86_l_6933;
	case 26937ULL: goto x86_l_6939;
	case 26942ULL: goto x86_l_693e;
	case 26947ULL: goto x86_l_6943;
	case 26952ULL: goto x86_l_6948;
	case 26955ULL: goto x86_l_694b;
	case 26958ULL: goto x86_l_694e;
	case 26964ULL: goto x86_l_6954;
	case 26967ULL: goto x86_l_6957;
	case 26969ULL: goto x86_l_6959;
	case 26974ULL: goto x86_l_695e;
	case 26980ULL: goto x86_l_6964;
	case 26985ULL: goto x86_l_6969;
	case 26987ULL: goto x86_l_696b;
	case 26989ULL: goto x86_l_696d;
	case 26993ULL: goto x86_l_6971;
	case 26996ULL: goto x86_l_6974;
	case 27002ULL: goto x86_l_697a;
	case 27009ULL: goto x86_l_6981;
	case 27012ULL: goto x86_l_6984;
	case 27018ULL: goto x86_l_698a;
	case 27028ULL: goto x86_l_6994;
	case 27033ULL: goto x86_l_6999;
	case 27043ULL: goto x86_l_69a3;
	case 27048ULL: goto x86_l_69a8;
	case 27058ULL: goto x86_l_69b2;
	case 27063ULL: goto x86_l_69b7;
	case 27073ULL: goto x86_l_69c1;
	case 27078ULL: goto x86_l_69c6;
	case 27088ULL: goto x86_l_69d0;
	case 27093ULL: goto x86_l_69d5;
	case 27103ULL: goto x86_l_69df;
	case 27108ULL: goto x86_l_69e4;
	case 27113ULL: goto x86_l_69e9;
	case 27118ULL: goto x86_l_69ee;
	case 27123ULL: goto x86_l_69f3;
	case 27128ULL: goto x86_l_69f8;
	case 27130ULL: goto x86_l_69fa;
	case 27132ULL: goto x86_l_69fc;
	case 27137ULL: goto x86_l_6a01;
	case 27144ULL: goto x86_l_6a08;
	case 27148ULL: goto x86_l_6a0c;
	case 27154ULL: goto x86_l_6a12;
	case 27159ULL: goto x86_l_6a17;
	case 27162ULL: goto x86_l_6a1a;
	case 27169ULL: goto x86_l_6a21;
	case 27173ULL: goto x86_l_6a25;
	case 27180ULL: goto x86_l_6a2c;
	case 27187ULL: goto x86_l_6a33;
	case 27195ULL: goto x86_l_6a3b;
	case 27203ULL: goto x86_l_6a43;
	case 27214ULL: goto x86_l_6a4e;
	case 27217ULL: goto x86_l_6a51;
	case 27225ULL: goto x86_l_6a59;
	case 27230ULL: goto x86_l_6a5e;
	case 27239ULL: goto x86_l_6a67;
	case 27246ULL: goto x86_l_6a6e;
	case 27253ULL: goto x86_l_6a75;
	case 27256ULL: goto x86_l_6a78;
	case 27261ULL: goto x86_l_6a7d;
	case 27263ULL: goto x86_l_6a7f;
	case 27266ULL: goto x86_l_6a82;
	case 27268ULL: goto x86_l_6a84;
	case 27271ULL: goto x86_l_6a87;
	case 27276ULL: goto x86_l_6a8c;
	case 27283ULL: goto x86_l_6a93;
	case 27286ULL: goto x86_l_6a96;
	case 27288ULL: goto x86_l_6a98;
	case 27298ULL: goto x86_l_6aa2;
	case 27303ULL: goto x86_l_6aa7;
	case 27313ULL: goto x86_l_6ab1;
	case 27318ULL: goto x86_l_6ab6;
	case 27328ULL: goto x86_l_6ac0;
	case 27333ULL: goto x86_l_6ac5;
	case 27343ULL: goto x86_l_6acf;
	case 27348ULL: goto x86_l_6ad4;
	case 27358ULL: goto x86_l_6ade;
	case 27363ULL: goto x86_l_6ae3;
	case 27373ULL: goto x86_l_6aed;
	case 27378ULL: goto x86_l_6af2;
	case 27383ULL: goto x86_l_6af7;
	case 27388ULL: goto x86_l_6afc;
	case 27393ULL: goto x86_l_6b01;
	case 27396ULL: goto x86_l_6b04;
	case 27401ULL: goto x86_l_6b09;
	case 27403ULL: goto x86_l_6b0b;
	case 27405ULL: goto x86_l_6b0d;
	case 27410ULL: goto x86_l_6b12;
	case 27413ULL: goto x86_l_6b15;
	case 27419ULL: goto x86_l_6b1b;
	case 27424ULL: goto x86_l_6b20;
	case 27427ULL: goto x86_l_6b23;
	case 27432ULL: goto x86_l_6b28;
	case 27441ULL: goto x86_l_6b31;
	case 27450ULL: goto x86_l_6b3a;
	case 27455ULL: goto x86_l_6b3f;
	case 27458ULL: goto x86_l_6b42;
	case 27463ULL: goto x86_l_6b47;
	case 27468ULL: goto x86_l_6b4c;
	case 27474ULL: goto x86_l_6b52;
	case 27479ULL: goto x86_l_6b57;
	case 27484ULL: goto x86_l_6b5c;
	case 27489ULL: goto x86_l_6b61;
	case 27492ULL: goto x86_l_6b64;
	case 27497ULL: goto x86_l_6b69;
	case 27502ULL: goto x86_l_6b6e;
	case 27507ULL: goto x86_l_6b73;
	case 27512ULL: goto x86_l_6b78;
	case 27518ULL: goto x86_l_6b7e;
	case 27523ULL: goto x86_l_6b83;
	case 27528ULL: goto x86_l_6b88;
	case 27533ULL: goto x86_l_6b8d;
	case 27536ULL: goto x86_l_6b90;
	case 27542ULL: goto x86_l_6b96;
	case 27548ULL: goto x86_l_6b9c;
	case 27553ULL: goto x86_l_6ba1;
	case 27556ULL: goto x86_l_6ba4;
	case 27562ULL: goto x86_l_6baa;
	case 27567ULL: goto x86_l_6baf;
	case 27570ULL: goto x86_l_6bb2;
	case 27575ULL: goto x86_l_6bb7;
	case 27580ULL: goto x86_l_6bbc;
	case 27586ULL: goto x86_l_6bc2;
	case 27591ULL: goto x86_l_6bc7;
	case 27596ULL: goto x86_l_6bcc;
	case 27601ULL: goto x86_l_6bd1;
	case 27604ULL: goto x86_l_6bd4;
	case 27607ULL: goto x86_l_6bd7;
	case 27613ULL: goto x86_l_6bdd;
	case 27618ULL: goto x86_l_6be2;
	case 27623ULL: goto x86_l_6be7;
	case 27628ULL: goto x86_l_6bec;
	case 27633ULL: goto x86_l_6bf1;
	case 27639ULL: goto x86_l_6bf7;
	case 27644ULL: goto x86_l_6bfc;
	case 27649ULL: goto x86_l_6c01;
	case 27654ULL: goto x86_l_6c06;
	case 27657ULL: goto x86_l_6c09;
	case 27660ULL: goto x86_l_6c0c;
	case 27666ULL: goto x86_l_6c12;
	case 27671ULL: goto x86_l_6c17;
	case 27676ULL: goto x86_l_6c1c;
	case 27681ULL: goto x86_l_6c21;
	case 27686ULL: goto x86_l_6c26;
	case 27692ULL: goto x86_l_6c2c;
	case 27697ULL: goto x86_l_6c31;
	case 27702ULL: goto x86_l_6c36;
	case 27707ULL: goto x86_l_6c3b;
	case 27710ULL: goto x86_l_6c3e;
	case 27713ULL: goto x86_l_6c41;
	case 27719ULL: goto x86_l_6c47;
	case 27724ULL: goto x86_l_6c4c;
	case 27727ULL: goto x86_l_6c4f;
	case 27732ULL: goto x86_l_6c54;
	case 27737ULL: goto x86_l_6c59;
	case 27740ULL: goto x86_l_6c5c;
	case 27744ULL: goto x86_l_6c60;
	case 27746ULL: goto x86_l_6c62;
	case 27748ULL: goto x86_l_6c64;
	case 27751ULL: goto x86_l_6c67;
	case 27753ULL: goto x86_l_6c69;
	case 27760ULL: goto x86_l_6c70;
	case 27766ULL: goto x86_l_6c76;
	case 27774ULL: goto x86_l_6c7e;
	case 27779ULL: goto x86_l_6c83;
	case 27784ULL: goto x86_l_6c88;
	case 27787ULL: goto x86_l_6c8b;
	case 27792ULL: goto x86_l_6c90;
	case 27798ULL: goto x86_l_6c96;
	case 27803ULL: goto x86_l_6c9b;
	case 27808ULL: goto x86_l_6ca0;
	case 27813ULL: goto x86_l_6ca5;
	case 27816ULL: goto x86_l_6ca8;
	case 27819ULL: goto x86_l_6cab;
	case 27825ULL: goto x86_l_6cb1;
	case 27828ULL: goto x86_l_6cb4;
	case 27830ULL: goto x86_l_6cb6;
	case 27835ULL: goto x86_l_6cbb;
	case 27841ULL: goto x86_l_6cc1;
	case 27846ULL: goto x86_l_6cc6;
	case 27848ULL: goto x86_l_6cc8;
	case 27850ULL: goto x86_l_6cca;
	case 27854ULL: goto x86_l_6cce;
	case 27857ULL: goto x86_l_6cd1;
	case 27863ULL: goto x86_l_6cd7;
	case 27870ULL: goto x86_l_6cde;
	case 27873ULL: goto x86_l_6ce1;
	case 27879ULL: goto x86_l_6ce7;
	case 27889ULL: goto x86_l_6cf1;
	case 27894ULL: goto x86_l_6cf6;
	case 27904ULL: goto x86_l_6d00;
	case 27909ULL: goto x86_l_6d05;
	case 27919ULL: goto x86_l_6d0f;
	case 27924ULL: goto x86_l_6d14;
	case 27934ULL: goto x86_l_6d1e;
	case 27939ULL: goto x86_l_6d23;
	case 27949ULL: goto x86_l_6d2d;
	case 27954ULL: goto x86_l_6d32;
	case 27964ULL: goto x86_l_6d3c;
	case 27969ULL: goto x86_l_6d41;
	case 27974ULL: goto x86_l_6d46;
	case 27979ULL: goto x86_l_6d4b;
	case 27984ULL: goto x86_l_6d50;
	case 27989ULL: goto x86_l_6d55;
	case 27991ULL: goto x86_l_6d57;
	case 27993ULL: goto x86_l_6d59;
	case 27998ULL: goto x86_l_6d5e;
	case 28005ULL: goto x86_l_6d65;
	case 28009ULL: goto x86_l_6d69;
	case 28015ULL: goto x86_l_6d6f;
	case 28020ULL: goto x86_l_6d74;
	case 28023ULL: goto x86_l_6d77;
	case 28030ULL: goto x86_l_6d7e;
	case 28034ULL: goto x86_l_6d82;
	case 28041ULL: goto x86_l_6d89;
	case 28048ULL: goto x86_l_6d90;
	case 28056ULL: goto x86_l_6d98;
	case 28064ULL: goto x86_l_6da0;
	case 28075ULL: goto x86_l_6dab;
	case 28078ULL: goto x86_l_6dae;
	case 28086ULL: goto x86_l_6db6;
	case 28091ULL: goto x86_l_6dbb;
	case 28100ULL: goto x86_l_6dc4;
	case 28107ULL: goto x86_l_6dcb;
	case 28114ULL: goto x86_l_6dd2;
	case 28117ULL: goto x86_l_6dd5;
	case 28122ULL: goto x86_l_6dda;
	case 28124ULL: goto x86_l_6ddc;
	case 28127ULL: goto x86_l_6ddf;
	case 28129ULL: goto x86_l_6de1;
	case 28132ULL: goto x86_l_6de4;
	case 28137ULL: goto x86_l_6de9;
	case 28144ULL: goto x86_l_6df0;
	case 28147ULL: goto x86_l_6df3;
	case 28149ULL: goto x86_l_6df5;
	case 28159ULL: goto x86_l_6dff;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6627:
	/* 0x6627: je     67b0 <perf_unwind_ruby+0x67b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_67b0;
	}
x86_l_662d:
	/* 0x662d: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_6637:
	/* 0x6637: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_663c:
	/* 0x663c: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_6646:
	/* 0x6646: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_664b:
	/* 0x664b: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_6655:
	/* 0x6655: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_665a:
	/* 0x665a: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_6664:
	/* 0x6664: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6669:
	/* 0x6669: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_6673:
	/* 0x6673: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6678:
	/* 0x6678: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_6682:
	/* 0x6682: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6687:
	/* 0x6687: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_668c:
	/* 0x668c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_6691:
	/* 0x6691: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6696:
	/* 0x6696: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_669b:
	/* 0x669b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_669d:
	/* 0x669d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_669f:
	/* 0x669f: jmp    67b0 <perf_unwind_ruby+0x67b0> */
	goto x86_l_67b0;
x86_l_66a4:
	/* 0x66a4: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_66ab:
	/* 0x66ab: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_66af:
	/* 0x66af: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_66b5:
	/* 0x66b5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_66ba:
	/* 0x66ba: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_66bd:
	/* 0x66bd: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_66c4:
	/* 0x66c4: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_66c8:
	/* 0x66c8: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_66cf:
	/* 0x66cf: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66d6:
	/* 0x66d6: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_66de:
	/* 0x66de: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_66e6:
	/* 0x66e6: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_66f1:
	/* 0x66f1: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66f4:
	/* 0x66f4: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_66fc:
	/* 0x66fc: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_6701:
	/* 0x6701: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_670a:
	/* 0x670a: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_6711:
	/* 0x6711: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_6718:
	/* 0x6718: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_671b:
	/* 0x671b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6720:
	/* 0x6720: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6722:
	/* 0x6722: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6725:
	/* 0x6725: je     672f <perf_unwind_ruby+0x672f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_672f;
	}
x86_l_6727:
	/* 0x6727: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_672a:
	/* 0x672a: jmp    67b0 <perf_unwind_ruby+0x67b0> */
	goto x86_l_67b0;
x86_l_672f:
	/* 0x672f: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6736:
	/* 0x6736: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6739:
	/* 0x6739: je     67b0 <perf_unwind_ruby+0x67b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_67b0;
	}
x86_l_673b:
	/* 0x673b: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_6745:
	/* 0x6745: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_674a:
	/* 0x674a: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_6754:
	/* 0x6754: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6759:
	/* 0x6759: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_6763:
	/* 0x6763: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6768:
	/* 0x6768: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_6772:
	/* 0x6772: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6777:
	/* 0x6777: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_6781:
	/* 0x6781: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6786:
	/* 0x6786: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_6790:
	/* 0x6790: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6795:
	/* 0x6795: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_679a:
	/* 0x679a: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_679f:
	/* 0x679f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_67a4:
	/* 0x67a4: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67a7:
	/* 0x67a7: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_67ac:
	/* 0x67ac: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67ae:
	/* 0x67ae: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_67b0:
	/* 0x67b0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_67b5:
	/* 0x67b5: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_67b8:
	/* 0x67b8: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_67be:
	/* 0x67be: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_67c3:
	/* 0x67c3: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_67c6:
	/* 0x67c6: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_67cb:
	/* 0x67cb: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_67d4:
	/* 0x67d4: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_67dd:
	/* 0x67dd: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_67e2:
	/* 0x67e2: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_67e5:
	/* 0x67e5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_67ea:
	/* 0x67ea: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_67ef:
	/* 0x67ef: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_67f5:
	/* 0x67f5: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_67fa:
	/* 0x67fa: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_67ff:
	/* 0x67ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6804:
	/* 0x6804: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6807:
	/* 0x6807: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_680c:
	/* 0x680c: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6811:
	/* 0x6811: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6816:
	/* 0x6816: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_681b:
	/* 0x681b: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6821:
	/* 0x6821: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_6826:
	/* 0x6826: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_682b:
	/* 0x682b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6830:
	/* 0x6830: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6833:
	/* 0x6833: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_6839:
	/* 0x6839: je     690c <perf_unwind_ruby+0x690c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_690c;
	}
x86_l_683f:
	/* 0x683f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6844:
	/* 0x6844: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6847:
	/* 0x6847: je     690c <perf_unwind_ruby+0x690c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_690c;
	}
x86_l_684d:
	/* 0x684d: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_6852:
	/* 0x6852: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6855:
	/* 0x6855: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_685a:
	/* 0x685a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_685f:
	/* 0x685f: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6865:
	/* 0x6865: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_686a:
	/* 0x686a: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_686f:
	/* 0x686f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6874:
	/* 0x6874: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6877:
	/* 0x6877: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_687a:
	/* 0x687a: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_6880:
	/* 0x6880: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_6885:
	/* 0x6885: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_688a:
	/* 0x688a: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_688f:
	/* 0x688f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6894:
	/* 0x6894: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_689a:
	/* 0x689a: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_689f:
	/* 0x689f: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_68a4:
	/* 0x68a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_68a9:
	/* 0x68a9: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_68ac:
	/* 0x68ac: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_68af:
	/* 0x68af: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_68b5:
	/* 0x68b5: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_68ba:
	/* 0x68ba: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_68bf:
	/* 0x68bf: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_68c4:
	/* 0x68c4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_68c9:
	/* 0x68c9: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_68cf:
	/* 0x68cf: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_68d4:
	/* 0x68d4: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_68d9:
	/* 0x68d9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_68de:
	/* 0x68de: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_68e1:
	/* 0x68e1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_68e4:
	/* 0x68e4: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_68ea:
	/* 0x68ea: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_68ef:
	/* 0x68ef: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_68f2:
	/* 0x68f2: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_68f7:
	/* 0x68f7: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_68fc:
	/* 0x68fc: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_68ff:
	/* 0x68ff: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_6903:
	/* 0x6903: je     6969 <perf_unwind_ruby+0x6969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6969;
	}
x86_l_6905:
	/* 0x6905: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6907:
	/* 0x6907: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_690a:
	/* 0x690a: jmp    696d <perf_unwind_ruby+0x696d> */
	goto x86_l_696d;
x86_l_690c:
	/* 0x690c: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_6913:
	/* 0x6913: jb     6b0d <perf_unwind_ruby+0x6b0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_6b0d;
	}
x86_l_6919:
	/* 0x6919: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6921:
	/* 0x6921: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_6926:
	/* 0x6926: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_692b:
	/* 0x692b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_692e:
	/* 0x692e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6933:
	/* 0x6933: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6939:
	/* 0x6939: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_693e:
	/* 0x693e: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6943:
	/* 0x6943: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6948:
	/* 0x6948: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_694b:
	/* 0x694b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_694e:
	/* 0x694e: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_6954:
	/* 0x6954: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6957:
	/* 0x6957: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_6959:
	/* 0x6959: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_695e:
	/* 0x695e: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_6964:
	/* 0x6964: jmp    6b0d <perf_unwind_ruby+0x6b0d> */
	goto x86_l_6b0d;
x86_l_6969:
	/* 0x6969: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_696b:
	/* 0x696b: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_696d:
	/* 0x696d: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6971:
	/* 0x6971: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_6974:
	/* 0x6974: jbe    6a01 <perf_unwind_ruby+0x6a01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_6a01;
	}
x86_l_697a:
	/* 0x697a: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6981:
	/* 0x6981: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6984:
	/* 0x6984: je     6b0d <perf_unwind_ruby+0x6b0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6b0d;
	}
x86_l_698a:
	/* 0x698a: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_6994:
	/* 0x6994: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_6999:
	/* 0x6999: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_69a3:
	/* 0x69a3: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_69a8:
	/* 0x69a8: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_69b2:
	/* 0x69b2: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_69b7:
	/* 0x69b7: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_69c1:
	/* 0x69c1: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_69c6:
	/* 0x69c6: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_69d0:
	/* 0x69d0: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_69d5:
	/* 0x69d5: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_69df:
	/* 0x69df: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_69e4:
	/* 0x69e4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_69e9:
	/* 0x69e9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_69ee:
	/* 0x69ee: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_69f3:
	/* 0x69f3: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_69f8:
	/* 0x69f8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69fa:
	/* 0x69fa: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_69fc:
	/* 0x69fc: jmp    6b0d <perf_unwind_ruby+0x6b0d> */
	goto x86_l_6b0d;
x86_l_6a01:
	/* 0x6a01: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_6a08:
	/* 0x6a08: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_6a0c:
	/* 0x6a0c: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_6a12:
	/* 0x6a12: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6a17:
	/* 0x6a17: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_6a1a:
	/* 0x6a1a: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_6a21:
	/* 0x6a21: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_6a25:
	/* 0x6a25: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_6a2c:
	/* 0x6a2c: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a33:
	/* 0x6a33: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_6a3b:
	/* 0x6a3b: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_6a43:
	/* 0x6a43: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_6a4e:
	/* 0x6a4e: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a51:
	/* 0x6a51: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_6a59:
	/* 0x6a59: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_6a5e:
	/* 0x6a5e: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_6a67:
	/* 0x6a67: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_6a6e:
	/* 0x6a6e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_6a75:
	/* 0x6a75: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_6a78:
	/* 0x6a78: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6a7d:
	/* 0x6a7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a7f:
	/* 0x6a7f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6a82:
	/* 0x6a82: je     6a8c <perf_unwind_ruby+0x6a8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6a8c;
	}
x86_l_6a84:
	/* 0x6a84: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6a87:
	/* 0x6a87: jmp    6b0d <perf_unwind_ruby+0x6b0d> */
	goto x86_l_6b0d;
x86_l_6a8c:
	/* 0x6a8c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6a93:
	/* 0x6a93: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a96:
	/* 0x6a96: je     6b0d <perf_unwind_ruby+0x6b0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6b0d;
	}
x86_l_6a98:
	/* 0x6a98: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_6aa2:
	/* 0x6aa2: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_6aa7:
	/* 0x6aa7: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_6ab1:
	/* 0x6ab1: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6ab6:
	/* 0x6ab6: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_6ac0:
	/* 0x6ac0: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6ac5:
	/* 0x6ac5: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_6acf:
	/* 0x6acf: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6ad4:
	/* 0x6ad4: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_6ade:
	/* 0x6ade: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6ae3:
	/* 0x6ae3: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_6aed:
	/* 0x6aed: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6af2:
	/* 0x6af2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6af7:
	/* 0x6af7: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_6afc:
	/* 0x6afc: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6b01:
	/* 0x6b01: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6b04:
	/* 0x6b04: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_6b09:
	/* 0x6b09: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b0b:
	/* 0x6b0b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6b0d:
	/* 0x6b0d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6b12:
	/* 0x6b12: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_6b15:
	/* 0x6b15: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_6b1b:
	/* 0x6b1b: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_6b20:
	/* 0x6b20: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6b23:
	/* 0x6b23: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6b28:
	/* 0x6b28: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_6b31:
	/* 0x6b31: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_6b3a:
	/* 0x6b3a: movzx  ecx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_6b3f:
	/* 0x6b3f: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6b42:
	/* 0x6b42: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6b47:
	/* 0x6b47: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6b4c:
	/* 0x6b4c: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6b52:
	/* 0x6b52: movzx  edx,BYTE PTR [r15+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_6b57:
	/* 0x6b57: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6b5c:
	/* 0x6b5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6b61:
	/* 0x6b61: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6b64:
	/* 0x6b64: movzx  eax,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_6b69:
	/* 0x6b69: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6b6e:
	/* 0x6b6e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6b73:
	/* 0x6b73: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6b78:
	/* 0x6b78: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6b7e:
	/* 0x6b7e: movzx  edx,BYTE PTR [r15+0x1b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 27ULL);
x86_l_6b83:
	/* 0x6b83: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6b88:
	/* 0x6b88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6b8d:
	/* 0x6b8d: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6b90:
	/* 0x6b90: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_6b96:
	/* 0x6b96: je     6c69 <perf_unwind_ruby+0x6c69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6c69;
	}
x86_l_6b9c:
	/* 0x6b9c: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6ba1:
	/* 0x6ba1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6ba4:
	/* 0x6ba4: je     6c69 <perf_unwind_ruby+0x6c69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6c69;
	}
x86_l_6baa:
	/* 0x6baa: movzx  ecx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_6baf:
	/* 0x6baf: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6bb2:
	/* 0x6bb2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6bb7:
	/* 0x6bb7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6bbc:
	/* 0x6bbc: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6bc2:
	/* 0x6bc2: movzx  edx,BYTE PTR [r15+0x1f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 31ULL);
x86_l_6bc7:
	/* 0x6bc7: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_6bcc:
	/* 0x6bcc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6bd1:
	/* 0x6bd1: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6bd4:
	/* 0x6bd4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6bd7:
	/* 0x6bd7: jne    4cf <perf_unwind_ruby+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1231ULL;
	}
x86_l_6bdd:
	/* 0x6bdd: movzx  eax,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_6be2:
	/* 0x6be2: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_6be7:
	/* 0x6be7: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6bec:
	/* 0x6bec: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6bf1:
	/* 0x6bf1: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6bf7:
	/* 0x6bf7: movzx  edx,BYTE PTR [r15+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_6bfc:
	/* 0x6bfc: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_6c01:
	/* 0x6c01: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6c06:
	/* 0x6c06: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6c09:
	/* 0x6c09: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6c0c:
	/* 0x6c0c: jne    824 <perf_unwind_ruby+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2084ULL;
	}
x86_l_6c12:
	/* 0x6c12: movzx  eax,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_6c17:
	/* 0x6c17: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_6c1c:
	/* 0x6c1c: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6c21:
	/* 0x6c21: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6c26:
	/* 0x6c26: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6c2c:
	/* 0x6c2c: movzx  edx,BYTE PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 34ULL);
x86_l_6c31:
	/* 0x6c31: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_6c36:
	/* 0x6c36: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6c3b:
	/* 0x6c3b: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6c3e:
	/* 0x6c3e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6c41:
	/* 0x6c41: jne    afc <perf_unwind_ruby+0xafc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2812ULL;
	}
x86_l_6c47:
	/* 0x6c47: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6c4c:
	/* 0x6c4c: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_6c4f:
	/* 0x6c4f: sub    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_6c54:
	/* 0x6c54: movzx  esi,BYTE PTR [r15+0x23] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 35ULL);
x86_l_6c59:
	/* 0x6c59: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6c5c:
	/* 0x6c5c: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_6c60:
	/* 0x6c60: je     6cc6 <perf_unwind_ruby+0x6cc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6cc6;
	}
x86_l_6c62:
	/* 0x6c62: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6c64:
	/* 0x6c64: div    rsi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_6c67:
	/* 0x6c67: jmp    6cca <perf_unwind_ruby+0x6cca> */
	goto x86_l_6cca;
x86_l_6c69:
	/* 0x6c69: cmp    DWORD PTR [r15],0x20600 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132608ULL);
x86_l_6c70:
	/* 0x6c70: jb     6e6a <perf_unwind_ruby+0x6e6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 28266ULL;
	}
x86_l_6c76:
	/* 0x6c76: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6c7e:
	/* 0x6c7e: movzx  eax,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_6c83:
	/* 0x6c83: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6c88:
	/* 0x6c88: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6c8b:
	/* 0x6c8b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6c90:
	/* 0x6c90: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_6c96:
	/* 0x6c96: movzx  edx,BYTE PTR [r15+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_6c9b:
	/* 0x6c9b: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6ca0:
	/* 0x6ca0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6ca5:
	/* 0x6ca5: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6ca8:
	/* 0x6ca8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6cab:
	/* 0x6cab: jne    79b <perf_unwind_ruby+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1947ULL;
	}
x86_l_6cb1:
	/* 0x6cb1: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6cb4:
	/* 0x6cb4: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_6cb6:
	/* 0x6cb6: test   eax,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 320ULL);
x86_l_6cbb:
	/* 0x6cbb: jne    917 <perf_unwind_ruby+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2327ULL;
	}
x86_l_6cc1:
	/* 0x6cc1: jmp    6e6a <perf_unwind_ruby+0x6e6a> */
	return 28266ULL;
x86_l_6cc6:
	/* 0x6cc6: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6cc8:
	/* 0x6cc8: div    esi */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_6cca:
	/* 0x6cca: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6cce:
	/* 0x6cce: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_6cd1:
	/* 0x6cd1: jbe    6d5e <perf_unwind_ruby+0x6d5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_6d5e;
	}
x86_l_6cd7:
	/* 0x6cd7: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6cde:
	/* 0x6cde: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ce1:
	/* 0x6ce1: je     6e6a <perf_unwind_ruby+0x6e6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28266ULL;
	}
x86_l_6ce7:
	/* 0x6ce7: movabs rax,0xa65636e657571 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926227495417201ULL);
x86_l_6cf1:
	/* 0x6cf1: mov    QWORD PTR [rsp+0x55],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_6cf6:
	/* 0x6cf6: movabs rax,0x6575716573206e6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310874250643009135ULL);
x86_l_6d00:
	/* 0x6d00: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6d05:
	/* 0x6d05: movabs rax,0x697463757274736e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598807827363427182ULL);
x86_l_6d0f:
	/* 0x6d0f: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6d14:
	/* 0x6d14: movabs rax,0x692064696c61766e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575164977189844590ULL);
x86_l_6d1e:
	/* 0x6d1e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6d23:
	/* 0x6d23: movabs rax,0x6920676e69707069 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575168297150214249ULL);
x86_l_6d2d:
	/* 0x6d2d: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6d32:
	/* 0x6d32: movabs rax,0x6b73203a79627572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7742567619896702322ULL);
x86_l_6d3c:
	/* 0x6d3c: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6d41:
	/* 0x6d41: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6d46:
	/* 0x6d46: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_6d4b:
	/* 0x6d4b: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6d50:
	/* 0x6d50: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_6d55:
	/* 0x6d55: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6d57:
	/* 0x6d57: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6d59:
	/* 0x6d59: jmp    6e6a <perf_unwind_ruby+0x6e6a> */
	return 28266ULL;
x86_l_6d5e:
	/* 0x6d5e: mov    eax,DWORD PTR [r14+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_6d65:
	/* 0x6d65: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_6d69:
	/* 0x6d69: ja     e4a <perf_unwind_ruby+0xe4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3658ULL;
	}
x86_l_6d6f:
	/* 0x6d6f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6d74:
	/* 0x6d74: lea    esi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_6d77:
	/* 0x6d77: mov    DWORD PTR [r14+0x2c0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_6d7e:
	/* 0x6d7e: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_6d82:
	/* 0x6d82: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_6d89:
	/* 0x6d89: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6d90:
	/* 0x6d90: mov    QWORD PTR [r14+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_6d98:
	/* 0x6d98: mov    QWORD PTR [r14+rax*8+0x2d8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_6da0:
	/* 0x6da0: mov    WORD PTR [r14+rax*8+0x2e0],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3161095929862ULL);
x86_l_6dab:
	/* 0x6dab: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6dae:
	/* 0x6dae: mov    DWORD PTR [r14+rax*8+0x2e2],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 738ULL);
x86_l_6db6:
	/* 0x6db6: movzx  ecx,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_6dbb:
	/* 0x6dbb: mov    WORD PTR [r14+rax*8+0x2e6],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 742ULL);
x86_l_6dc4:
	/* 0x6dc4: mov    DWORD PTR [rsp],0x36 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_6dcb:
	/* 0x6dcb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_6dd2:
	/* 0x6dd2: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_6dd5:
	/* 0x6dd5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6dda:
	/* 0x6dda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ddc:
	/* 0x6ddc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6ddf:
	/* 0x6ddf: je     6de9 <perf_unwind_ruby+0x6de9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6de9;
	}
x86_l_6de1:
	/* 0x6de1: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6de4:
	/* 0x6de4: jmp    6e6a <perf_unwind_ruby+0x6e6a> */
	return 28266ULL;
x86_l_6de9:
	/* 0x6de9: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6df0:
	/* 0x6df0: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6df3:
	/* 0x6df3: je     6e6a <perf_unwind_ruby+0x6e6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28266ULL;
	}
x86_l_6df5:
	/* 0x6df5: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_6dff:
	/* 0x6dff: mov    QWORD PTR [rsp+0x56],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
	return 28164ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_14(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 28164ULL: goto x86_l_6e04;
	case 28174ULL: goto x86_l_6e0e;
	case 28179ULL: goto x86_l_6e13;
	case 28189ULL: goto x86_l_6e1d;
	case 28194ULL: goto x86_l_6e22;
	case 28204ULL: goto x86_l_6e2c;
	case 28209ULL: goto x86_l_6e31;
	case 28219ULL: goto x86_l_6e3b;
	case 28224ULL: goto x86_l_6e40;
	case 28234ULL: goto x86_l_6e4a;
	case 28239ULL: goto x86_l_6e4f;
	case 28244ULL: goto x86_l_6e54;
	case 28249ULL: goto x86_l_6e59;
	case 28254ULL: goto x86_l_6e5e;
	case 28257ULL: goto x86_l_6e61;
	case 28262ULL: goto x86_l_6e66;
	case 28264ULL: goto x86_l_6e68;
	case 28266ULL: goto x86_l_6e6a;
	case 28271ULL: goto x86_l_6e6f;
	case 28274ULL: goto x86_l_6e72;
	case 28280ULL: goto x86_l_6e78;
	case 28285ULL: goto x86_l_6e7d;
	case 28288ULL: goto x86_l_6e80;
	case 28293ULL: goto x86_l_6e85;
	case 28298ULL: goto x86_l_6e8a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6e04:
	/* 0x6e04: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_6e0e:
	/* 0x6e0e: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6e13:
	/* 0x6e13: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_6e1d:
	/* 0x6e1d: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6e22:
	/* 0x6e22: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_6e2c:
	/* 0x6e2c: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6e31:
	/* 0x6e31: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_6e3b:
	/* 0x6e3b: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6e40:
	/* 0x6e40: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_6e4a:
	/* 0x6e4a: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6e4f:
	/* 0x6e4f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6e54:
	/* 0x6e54: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_6e59:
	/* 0x6e59: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6e5e:
	/* 0x6e5e: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6e61:
	/* 0x6e61: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_6e66:
	/* 0x6e66: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6e68:
	/* 0x6e68: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6e6a:
	/* 0x6e6a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6e6f:
	/* 0x6e6f: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_6e72:
	/* 0x6e72: jbe    2b2 <perf_unwind_ruby+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 690ULL;
	}
x86_l_6e78:
	/* 0x6e78: movzx  ecx,BYTE PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_6e7d:
	/* 0x6e7d: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6e80:
	/* 0x6e80: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6e85:
	/* 0x6e85: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_6e8a:
	/* 0x6e8a: jmp    92b <perf_unwind_ruby+0x92b> */
	return 2347ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int otelcol_ebpf_profiler_perf_unwind_ruby_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 21604U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1838ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1844ULL && __x86_pc <= 3711ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3714ULL && __x86_pc <= 5841ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5847ULL && __x86_pc <= 7936ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7939ULL && __x86_pc <= 10080ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 10085ULL && __x86_pc <= 12118ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 12125ULL && __x86_pc <= 14113ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 14119ULL && __x86_pc <= 16117ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 16122ULL && __x86_pc <= 18114ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 18119ULL && __x86_pc <= 20226ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 20231ULL && __x86_pc <= 22237ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 22239ULL && __x86_pc <= 24205ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 24210ULL && __x86_pc <= 26148ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 26151ULL && __x86_pc <= 28159ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_13(__x86_state, __x86_pc);
		else if (__x86_pc >= 28164ULL && __x86_pc <= 28298ULL)
			__x86_pc = otelcol_ebpf_profiler_perf_unwind_ruby_x86_chunk_14(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

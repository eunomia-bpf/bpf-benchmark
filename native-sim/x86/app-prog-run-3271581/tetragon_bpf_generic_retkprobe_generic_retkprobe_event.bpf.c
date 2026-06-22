extern char buffer_heap_map;
extern char config_map;
extern char execve_map;
extern char fdinstall_map;
extern char process_call_heap;
extern char retkprobe_calls;
extern char retprobe_map;
extern char tg_ipv6_ext_heap;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_0(
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
	case 24ULL: goto x86_l_18;
	case 35ULL: goto x86_l_23;
	case 42ULL: goto x86_l_2a;
	case 50ULL: goto x86_l_32;
	case 55ULL: goto x86_l_37;
	case 57ULL: goto x86_l_39;
	case 59ULL: goto x86_l_3b;
	case 62ULL: goto x86_l_3e;
	case 68ULL: goto x86_l_44;
	case 71ULL: goto x86_l_47;
	case 74ULL: goto x86_l_4a;
	case 81ULL: goto x86_l_51;
	case 91ULL: goto x86_l_5b;
	case 98ULL: goto x86_l_62;
	case 103ULL: goto x86_l_67;
	case 105ULL: goto x86_l_69;
	case 108ULL: goto x86_l_6c;
	case 114ULL: goto x86_l_72;
	case 117ULL: goto x86_l_75;
	case 119ULL: goto x86_l_77;
	case 123ULL: goto x86_l_7b;
	case 128ULL: goto x86_l_80;
	case 130ULL: goto x86_l_82;
	case 134ULL: goto x86_l_86;
	case 136ULL: goto x86_l_88;
	case 140ULL: goto x86_l_8c;
	case 144ULL: goto x86_l_90;
	case 149ULL: goto x86_l_95;
	case 151ULL: goto x86_l_97;
	case 155ULL: goto x86_l_9b;
	case 159ULL: goto x86_l_9f;
	case 163ULL: goto x86_l_a3;
	case 168ULL: goto x86_l_a8;
	case 173ULL: goto x86_l_ad;
	case 180ULL: goto x86_l_b4;
	case 185ULL: goto x86_l_b9;
	case 190ULL: goto x86_l_be;
	case 192ULL: goto x86_l_c0;
	case 195ULL: goto x86_l_c3;
	case 201ULL: goto x86_l_c9;
	case 206ULL: goto x86_l_ce;
	case 209ULL: goto x86_l_d1;
	case 213ULL: goto x86_l_d5;
	case 217ULL: goto x86_l_d9;
	case 225ULL: goto x86_l_e1;
	case 232ULL: goto x86_l_e8;
	case 237ULL: goto x86_l_ed;
	case 242ULL: goto x86_l_f2;
	case 244ULL: goto x86_l_f4;
	case 251ULL: goto x86_l_fb;
	case 256ULL: goto x86_l_100;
	case 261ULL: goto x86_l_105;
	case 264ULL: goto x86_l_108;
	case 272ULL: goto x86_l_110;
	case 278ULL: goto x86_l_116;
	case 282ULL: goto x86_l_11a;
	case 293ULL: goto x86_l_125;
	case 304ULL: goto x86_l_130;
	case 311ULL: goto x86_l_137;
	case 319ULL: goto x86_l_13f;
	case 324ULL: goto x86_l_144;
	case 326ULL: goto x86_l_146;
	case 329ULL: goto x86_l_149;
	case 335ULL: goto x86_l_14f;
	case 341ULL: goto x86_l_155;
	case 347ULL: goto x86_l_15b;
	case 358ULL: goto x86_l_166;
	case 364ULL: goto x86_l_16c;
	case 366ULL: goto x86_l_16e;
	case 372ULL: goto x86_l_174;
	case 379ULL: goto x86_l_17b;
	case 384ULL: goto x86_l_180;
	case 389ULL: goto x86_l_185;
	case 398ULL: goto x86_l_18e;
	case 402ULL: goto x86_l_192;
	case 407ULL: goto x86_l_197;
	case 415ULL: goto x86_l_19f;
	case 421ULL: goto x86_l_1a5;
	case 425ULL: goto x86_l_1a9;
	case 431ULL: goto x86_l_1af;
	case 435ULL: goto x86_l_1b3;
	case 441ULL: goto x86_l_1b9;
	case 446ULL: goto x86_l_1be;
	case 451ULL: goto x86_l_1c3;
	case 457ULL: goto x86_l_1c9;
	case 462ULL: goto x86_l_1ce;
	case 469ULL: goto x86_l_1d5;
	case 472ULL: goto x86_l_1d8;
	case 478ULL: goto x86_l_1de;
	case 486ULL: goto x86_l_1e6;
	case 490ULL: goto x86_l_1ea;
	case 499ULL: goto x86_l_1f3;
	case 507ULL: goto x86_l_1fb;
	case 513ULL: goto x86_l_201;
	case 518ULL: goto x86_l_206;
	case 523ULL: goto x86_l_20b;
	case 529ULL: goto x86_l_211;
	case 534ULL: goto x86_l_216;
	case 539ULL: goto x86_l_21b;
	case 544ULL: goto x86_l_220;
	case 547ULL: goto x86_l_223;
	case 549ULL: goto x86_l_225;
	case 554ULL: goto x86_l_22a;
	case 556ULL: goto x86_l_22c;
	case 562ULL: goto x86_l_232;
	case 570ULL: goto x86_l_23a;
	case 575ULL: goto x86_l_23f;
	case 580ULL: goto x86_l_244;
	case 583ULL: goto x86_l_247;
	case 586ULL: goto x86_l_24a;
	case 590ULL: goto x86_l_24e;
	case 593ULL: goto x86_l_251;
	case 597ULL: goto x86_l_255;
	case 602ULL: goto x86_l_25a;
	case 609ULL: goto x86_l_261;
	case 615ULL: goto x86_l_267;
	case 619ULL: goto x86_l_26b;
	case 624ULL: goto x86_l_270;
	case 628ULL: goto x86_l_274;
	case 633ULL: goto x86_l_279;
	case 638ULL: goto x86_l_27e;
	case 643ULL: goto x86_l_283;
	case 645ULL: goto x86_l_285;
	case 647ULL: goto x86_l_287;
	case 652ULL: goto x86_l_28c;
	case 654ULL: goto x86_l_28e;
	case 660ULL: goto x86_l_294;
	case 665ULL: goto x86_l_299;
	case 668ULL: goto x86_l_29c;
	case 674ULL: goto x86_l_2a2;
	case 677ULL: goto x86_l_2a5;
	case 682ULL: goto x86_l_2aa;
	case 687ULL: goto x86_l_2af;
	case 693ULL: goto x86_l_2b5;
	case 695ULL: goto x86_l_2b7;
	case 698ULL: goto x86_l_2ba;
	case 703ULL: goto x86_l_2bf;
	case 707ULL: goto x86_l_2c3;
	case 712ULL: goto x86_l_2c8;
	case 715ULL: goto x86_l_2cb;
	case 719ULL: goto x86_l_2cf;
	case 724ULL: goto x86_l_2d4;
	case 728ULL: goto x86_l_2d8;
	case 731ULL: goto x86_l_2db;
	case 736ULL: goto x86_l_2e0;
	case 740ULL: goto x86_l_2e4;
	case 746ULL: goto x86_l_2ea;
	case 750ULL: goto x86_l_2ee;
	case 752ULL: goto x86_l_2f0;
	case 764ULL: goto x86_l_2fc;
	case 769ULL: goto x86_l_301;
	case 777ULL: goto x86_l_309;
	case 785ULL: goto x86_l_311;
	case 790ULL: goto x86_l_316;
	case 798ULL: goto x86_l_31e;
	case 802ULL: goto x86_l_322;
	case 808ULL: goto x86_l_328;
	case 811ULL: goto x86_l_32b;
	case 821ULL: goto x86_l_335;
	case 825ULL: goto x86_l_339;
	case 831ULL: goto x86_l_33f;
	case 836ULL: goto x86_l_344;
	case 841ULL: goto x86_l_349;
	case 852ULL: goto x86_l_354;
	case 859ULL: goto x86_l_35b;
	case 867ULL: goto x86_l_363;
	case 872ULL: goto x86_l_368;
	case 874ULL: goto x86_l_36a;
	case 876ULL: goto x86_l_36c;
	case 879ULL: goto x86_l_36f;
	case 885ULL: goto x86_l_375;
	case 889ULL: goto x86_l_379;
	case 895ULL: goto x86_l_37f;
	case 899ULL: goto x86_l_383;
	case 905ULL: goto x86_l_389;
	case 909ULL: goto x86_l_38d;
	case 915ULL: goto x86_l_393;
	case 919ULL: goto x86_l_397;
	case 925ULL: goto x86_l_39d;
	case 929ULL: goto x86_l_3a1;
	case 935ULL: goto x86_l_3a7;
	case 939ULL: goto x86_l_3ab;
	case 944ULL: goto x86_l_3b0;
	case 950ULL: goto x86_l_3b6;
	case 955ULL: goto x86_l_3bb;
	case 963ULL: goto x86_l_3c3;
	case 968ULL: goto x86_l_3c8;
	case 973ULL: goto x86_l_3cd;
	case 978ULL: goto x86_l_3d2;
	case 983ULL: goto x86_l_3d7;
	case 988ULL: goto x86_l_3dc;
	case 990ULL: goto x86_l_3de;
	case 995ULL: goto x86_l_3e3;
	case 1000ULL: goto x86_l_3e8;
	case 1003ULL: goto x86_l_3eb;
	case 1009ULL: goto x86_l_3f1;
	case 1020ULL: goto x86_l_3fc;
	case 1027ULL: goto x86_l_403;
	case 1035ULL: goto x86_l_40b;
	case 1040ULL: goto x86_l_410;
	case 1042ULL: goto x86_l_412;
	case 1045ULL: goto x86_l_415;
	case 1053ULL: goto x86_l_41d;
	case 1059ULL: goto x86_l_423;
	case 1061ULL: goto x86_l_425;
	case 1065ULL: goto x86_l_429;
	case 1070ULL: goto x86_l_42e;
	case 1076ULL: goto x86_l_434;
	case 1080ULL: goto x86_l_438;
	case 1088ULL: goto x86_l_440;
	case 1094ULL: goto x86_l_446;
	case 1098ULL: goto x86_l_44a;
	case 1104ULL: goto x86_l_450;
	case 1108ULL: goto x86_l_454;
	case 1114ULL: goto x86_l_45a;
	case 1118ULL: goto x86_l_45e;
	case 1124ULL: goto x86_l_464;
	case 1128ULL: goto x86_l_468;
	case 1133ULL: goto x86_l_46d;
	case 1139ULL: goto x86_l_473;
	case 1149ULL: goto x86_l_47d;
	case 1156ULL: goto x86_l_484;
	case 1161ULL: goto x86_l_489;
	case 1166ULL: goto x86_l_48e;
	case 1171ULL: goto x86_l_493;
	case 1176ULL: goto x86_l_498;
	case 1181ULL: goto x86_l_49d;
	case 1186ULL: goto x86_l_4a2;
	case 1191ULL: goto x86_l_4a7;
	case 1194ULL: goto x86_l_4aa;
	case 1199ULL: goto x86_l_4af;
	case 1201ULL: goto x86_l_4b1;
	case 1206ULL: goto x86_l_4b6;
	case 1211ULL: goto x86_l_4bb;
	case 1216ULL: goto x86_l_4c0;
	case 1221ULL: goto x86_l_4c5;
	case 1226ULL: goto x86_l_4ca;
	case 1231ULL: goto x86_l_4cf;
	case 1236ULL: goto x86_l_4d4;
	case 1238ULL: goto x86_l_4d6;
	case 1243ULL: goto x86_l_4db;
	case 1247ULL: goto x86_l_4df;
	case 1252ULL: goto x86_l_4e4;
	case 1260ULL: goto x86_l_4ec;
	case 1271ULL: goto x86_l_4f7;
	case 1278ULL: goto x86_l_4fe;
	case 1286ULL: goto x86_l_506;
	case 1291ULL: goto x86_l_50b;
	case 1293ULL: goto x86_l_50d;
	case 1296ULL: goto x86_l_510;
	case 1302ULL: goto x86_l_516;
	case 1305ULL: goto x86_l_519;
	case 1311ULL: goto x86_l_51f;
	case 1319ULL: goto x86_l_527;
	case 1324ULL: goto x86_l_52c;
	case 1326ULL: goto x86_l_52e;
	case 1333ULL: goto x86_l_535;
	case 1341ULL: goto x86_l_53d;
	case 1346ULL: goto x86_l_542;
	case 1351ULL: goto x86_l_547;
	case 1356ULL: goto x86_l_54c;
	case 1358ULL: goto x86_l_54e;
	case 1366ULL: goto x86_l_556;
	case 1371ULL: goto x86_l_55b;
	case 1375ULL: goto x86_l_55f;
	case 1383ULL: goto x86_l_567;
	case 1388ULL: goto x86_l_56c;
	case 1393ULL: goto x86_l_571;
	case 1397ULL: goto x86_l_575;
	case 1405ULL: goto x86_l_57d;
	case 1410ULL: goto x86_l_582;
	case 1418ULL: goto x86_l_58a;
	case 1420ULL: goto x86_l_58c;
	case 1428ULL: goto x86_l_594;
	case 1432ULL: goto x86_l_598;
	case 1437ULL: goto x86_l_59d;
	case 1442ULL: goto x86_l_5a2;
	case 1447ULL: goto x86_l_5a7;
	case 1452ULL: goto x86_l_5ac;
	case 1454ULL: goto x86_l_5ae;
	case 1460ULL: goto x86_l_5b4;
	case 1466ULL: goto x86_l_5ba;
	case 1468ULL: goto x86_l_5bc;
	case 1476ULL: goto x86_l_5c4;
	case 1478ULL: goto x86_l_5c6;
	case 1480ULL: goto x86_l_5c8;
	case 1488ULL: goto x86_l_5d0;
	case 1493ULL: goto x86_l_5d5;
	case 1497ULL: goto x86_l_5d9;
	case 1502ULL: goto x86_l_5de;
	case 1507ULL: goto x86_l_5e3;
	case 1512ULL: goto x86_l_5e8;
	case 1517ULL: goto x86_l_5ed;
	case 1519ULL: goto x86_l_5ef;
	case 1524ULL: goto x86_l_5f4;
	case 1532ULL: goto x86_l_5fc;
	case 1534ULL: goto x86_l_5fe;
	case 1537ULL: goto x86_l_601;
	case 1544ULL: goto x86_l_608;
	case 1554ULL: goto x86_l_612;
	case 1562ULL: goto x86_l_61a;
	case 1573ULL: goto x86_l_625;
	case 1579ULL: goto x86_l_62b;
	case 1588ULL: goto x86_l_634;
	case 1597ULL: goto x86_l_63d;
	case 1602ULL: goto x86_l_642;
	case 1611ULL: goto x86_l_64b;
	case 1620ULL: goto x86_l_654;
	case 1629ULL: goto x86_l_65d;
	case 1637ULL: goto x86_l_665;
	case 1642ULL: goto x86_l_66a;
	case 1647ULL: goto x86_l_66f;
	case 1652ULL: goto x86_l_674;
	case 1656ULL: goto x86_l_678;
	case 1661ULL: goto x86_l_67d;
	case 1666ULL: goto x86_l_682;
	case 1671ULL: goto x86_l_687;
	case 1676ULL: goto x86_l_68c;
	case 1681ULL: goto x86_l_691;
	case 1686ULL: goto x86_l_696;
	case 1691ULL: goto x86_l_69b;
	case 1694ULL: goto x86_l_69e;
	case 1696ULL: goto x86_l_6a0;
	case 1701ULL: goto x86_l_6a5;
	case 1706ULL: goto x86_l_6aa;
	case 1714ULL: goto x86_l_6b2;
	case 1717ULL: goto x86_l_6b5;
	case 1722ULL: goto x86_l_6ba;
	case 1724ULL: goto x86_l_6bc;
	case 1729ULL: goto x86_l_6c1;
	case 1734ULL: goto x86_l_6c6;
	case 1742ULL: goto x86_l_6ce;
	case 1745ULL: goto x86_l_6d1;
	case 1750ULL: goto x86_l_6d6;
	case 1752ULL: goto x86_l_6d8;
	case 1757ULL: goto x86_l_6dd;
	case 1762ULL: goto x86_l_6e2;
	case 1767ULL: goto x86_l_6e7;
	case 1770ULL: goto x86_l_6ea;
	case 1775ULL: goto x86_l_6ef;
	case 1777ULL: goto x86_l_6f1;
	case 1782ULL: goto x86_l_6f6;
	case 1786ULL: goto x86_l_6fa;
	case 1791ULL: goto x86_l_6ff;
	case 1796ULL: goto x86_l_704;
	case 1801ULL: goto x86_l_709;
	case 1803ULL: goto x86_l_70b;
	case 1808ULL: goto x86_l_710;
	case 1810ULL: goto x86_l_712;
	case 1815ULL: goto x86_l_717;
	case 1821ULL: goto x86_l_71d;
	case 1826ULL: goto x86_l_722;
	case 1834ULL: goto x86_l_72a;
	case 1837ULL: goto x86_l_72d;
	case 1842ULL: goto x86_l_732;
	case 1850ULL: goto x86_l_73a;
	case 1856ULL: goto x86_l_740;
	case 1859ULL: goto x86_l_743;
	case 1864ULL: goto x86_l_748;
	case 1867ULL: goto x86_l_74b;
	case 1871ULL: goto x86_l_74f;
	case 1876ULL: goto x86_l_754;
	case 1878ULL: goto x86_l_756;
	case 1880ULL: goto x86_l_758;
	case 1883ULL: goto x86_l_75b;
	case 1886ULL: goto x86_l_75e;
	case 1892ULL: goto x86_l_764;
	case 1895ULL: goto x86_l_767;
	case 1898ULL: goto x86_l_76a;
	case 1901ULL: goto x86_l_76d;
	case 1906ULL: goto x86_l_772;
	case 1914ULL: goto x86_l_77a;
	case 1919ULL: goto x86_l_77f;
	case 1924ULL: goto x86_l_784;
	case 1929ULL: goto x86_l_789;
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
	/* 0xa: sub    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 248ULL);
x86_l_11:
	/* 0x11: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    r14,QWORD PTR [rdi+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_18:
	/* 0x18: mov    DWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_23:
	/* 0x23: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_2a:
	/* 0x2a: lea    rsi,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_32:
	/* 0x32: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37:
	/* 0x37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39:
	/* 0x39: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b:
	/* 0x3b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e:
	/* 0x3e: je     3f14 <generic_retkprobe_event+0x3f14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16148ULL;
	}
x86_l_44:
	/* 0x44: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_47:
	/* 0x47: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_4a:
	/* 0x4a: lea    rsi,[rax+0x5ee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24296ULL);
x86_l_51:
	/* 0x51: mov    DWORD PTR [rbx+0x5ee8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104350525423616ULL);
x86_l_5b:
	/* 0x5b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_62:
	/* 0x62: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_67:
	/* 0x67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69:
	/* 0x69: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6c:
	/* 0x6c: je     3f14 <generic_retkprobe_event+0x3f14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16148ULL;
	}
x86_l_72:
	/* 0x72: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_75:
	/* 0x75: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_77:
	/* 0x77: mov    QWORD PTR [r15+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7b:
	/* 0x7b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_80:
	/* 0x80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_82:
	/* 0x82: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_86:
	/* 0x86: jne    8c <generic_retkprobe_event+0x8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8c;
	}
x86_l_88:
	/* 0x88: mov    rax,QWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8c:
	/* 0x8c: mov    QWORD PTR [r15+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_90:
	/* 0x90: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_95:
	/* 0x95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_97:
	/* 0x97: mov    DWORD PTR [r15+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_9b:
	/* 0x9b: mov    rax,QWORD PTR [r15+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9f:
	/* 0x9f: mov    rcx,QWORD PTR [r15+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a3:
	/* 0xa3: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a8:
	/* 0xa8: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ad:
	/* 0xad: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_b4:
	/* 0xb4: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b9:
	/* 0xb9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_be:
	/* 0xbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c0:
	/* 0xc0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c3:
	/* 0xc3: je     3f14 <generic_retkprobe_event+0x3f14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16148ULL;
	}
x86_l_c9:
	/* 0xc9: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ce:
	/* 0xce: mov    r14,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d1:
	/* 0xd1: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d5:
	/* 0xd5: mov    rax,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d9:
	/* 0xd9: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_e1:
	/* 0xe1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_e8:
	/* 0xe8: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ed:
	/* 0xed: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_f2:
	/* 0xf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f4:
	/* 0xf4: mov    QWORD PTR [r15+0x90],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_fb:
	/* 0xfb: mov    eax,DWORD PTR [r12+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_100:
	/* 0x100: mov    r14d,DWORD PTR [r12+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_105:
	/* 0x105: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_108:
	/* 0x108: mov    QWORD PTR [rsp+0xe8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_110:
	/* 0x110: je     1c3 <generic_retkprobe_event+0x1c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c3;
	}
x86_l_116:
	/* 0x116: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_11a:
	/* 0x11a: mov    DWORD PTR [r15+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104041287778304ULL);
x86_l_125:
	/* 0x125: mov    DWORD PTR [rsp+0xdc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_130:
	/* 0x130: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_137:
	/* 0x137: lea    rsi,[rsp+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_13f:
	/* 0x13f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_144:
	/* 0x144: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_146:
	/* 0x146: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_149:
	/* 0x149: je     2b7 <generic_retkprobe_event+0x2b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b7;
	}
x86_l_14f:
	/* 0x14f: mov    ecx,DWORD PTR [rax+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24224ULL);
x86_l_155:
	/* 0x155: mov    DWORD PTR [rax+0x98],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_15b:
	/* 0x15b: mov    QWORD PTR [rax+0x5e78],0xc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103869489086476ULL);
x86_l_166:
	/* 0x166: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_16c:
	/* 0x16c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_16e:
	/* 0x16e: jne    2ba <generic_retkprobe_event+0x2ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ba;
	}
x86_l_174:
	/* 0x174: lea    rdx,[rax+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_17b:
	/* 0x17b: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_180:
	/* 0x180: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_185:
	/* 0x185: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_18e:
	/* 0x18e: cmp    r14d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 23ULL);
x86_l_192:
	/* 0x192: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_197:
	/* 0x197: mov    QWORD PTR [rsp+0xa0],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_19f:
	/* 0x19f: jg     2e0 <generic_retkprobe_event+0x2e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2e0;
	}
x86_l_1a5:
	/* 0x1a5: cmp    r14d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 15ULL);
x86_l_1a9:
	/* 0x1a9: je     3bb <generic_retkprobe_event+0x3bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bb;
	}
x86_l_1af:
	/* 0x1af: cmp    r14d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 16ULL);
x86_l_1b3:
	/* 0x1b3: jne    316 <generic_retkprobe_event+0x316> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_316;
	}
x86_l_1b9:
	/* 0x1b9: lea    r14,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1be:
	/* 0x1be: jmp    4bb <generic_retkprobe_event+0x4bb> */
	goto x86_l_4bb;
x86_l_1c3:
	/* 0x1c3: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_1c9:
	/* 0x1c9: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ce:
	/* 0x1ce: add    rbx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1d5:
	/* 0x1d5: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1d8:
	/* 0x1d8: jne    b5c <generic_retkprobe_event+0xb5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2908ULL;
	}
x86_l_1de:
	/* 0x1de: mov    DWORD PTR [rbx+r13*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1e6:
	/* 0x1e6: lea    rcx,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ea:
	/* 0x1ea: cmp    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_1f3:
	/* 0x1f3: mov    QWORD PTR [rsp+0x98],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1fb:
	/* 0x1fb: je     2c8 <generic_retkprobe_event+0x2c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c8;
	}
x86_l_201:
	/* 0x201: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_206:
	/* 0x206: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20b:
	/* 0x20b: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_211:
	/* 0x211: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_216:
	/* 0x216: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21b:
	/* 0x21b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_220:
	/* 0x220: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_223:
	/* 0x223: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_225:
	/* 0x225: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_22a:
	/* 0x22a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22c:
	/* 0x22c: js     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15444ULL;
	}
x86_l_232:
	/* 0x232: mov    QWORD PTR [rsp+0xa0],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_23a:
	/* 0x23a: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23f:
	/* 0x23f: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_244:
	/* 0x244: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_247:
	/* 0x247: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_24a:
	/* 0x24a: cmovb  r12,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_64, X86_CC_B);
x86_l_24e:
	/* 0x24e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_251:
	/* 0x251: cmovne rbp,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_255:
	/* 0x255: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_25a:
	/* 0x25a: cmp    rbp,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4094ULL);
x86_l_261:
	/* 0x261: ja     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 15444ULL;
	}
x86_l_267:
	/* 0x267: add    r13,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_26b:
	/* 0x26b: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_270:
	/* 0x270: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_274:
	/* 0x274: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_279:
	/* 0x279: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27e:
	/* 0x27e: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_283:
	/* 0x283: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_285:
	/* 0x285: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_287:
	/* 0x287: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_28c:
	/* 0x28c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28e:
	/* 0x28e: js     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15444ULL;
	}
x86_l_294:
	/* 0x294: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_299:
	/* 0x299: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29c:
	/* 0x29c: je     bd8 <generic_retkprobe_event+0xbd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3032ULL;
	}
x86_l_2a2:
	/* 0x2a2: sub    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2a5:
	/* 0x2a5: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2aa:
	/* 0x2aa: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2af:
	/* 0x2af: jne    be4 <generic_retkprobe_event+0xbe4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3044ULL;
	}
x86_l_2b5:
	/* 0x2b5: jmp    2cb <generic_retkprobe_event+0x2cb> */
	goto x86_l_2cb;
x86_l_2b7:
	/* 0x2b7: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ba:
	/* 0x2ba: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2bf:
	/* 0x2bf: mov    eax,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2c3:
	/* 0x2c3: jmp    b41 <generic_retkprobe_event+0xb41> */
	return 2881ULL;
x86_l_2c8:
	/* 0x2c8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cb:
	/* 0x2cb: mov    DWORD PTR [rbx+rcx*1],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2cf:
	/* 0x2cf: mov    DWORD PTR [rbx+rcx*1+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 4ULL);
x86_l_2d4:
	/* 0x2d4: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d8:
	/* 0x2d8: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_2db:
	/* 0x2db: jmp    3c5f <generic_retkprobe_event+0x3c5f> */
	return 15455ULL;
x86_l_2e0:
	/* 0x2e0: cmp    r14d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 24ULL);
x86_l_2e4:
	/* 0x2e4: je     48e <generic_retkprobe_event+0x48e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48e;
	}
x86_l_2ea:
	/* 0x2ea: cmp    r14d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 42ULL);
x86_l_2ee:
	/* 0x2ee: jne    316 <generic_retkprobe_event+0x316> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_316;
	}
x86_l_2f0:
	/* 0x2f0: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_2fc:
	/* 0x2fc: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_301:
	/* 0x301: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_309:
	/* 0x309: lea    rax,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_311:
	/* 0x311: jmp    4df <generic_retkprobe_event+0x4df> */
	goto x86_l_4df;
x86_l_316:
	/* 0x316: mov    QWORD PTR [rsp+0x90],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_31e:
	/* 0x31e: cmp    r14d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 40ULL);
x86_l_322:
	/* 0x322: ja     3f1 <generic_retkprobe_event+0x3f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3f1;
	}
x86_l_328:
	/* 0x328: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_32b:
	/* 0x32b: movabs rcx,0x1c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1932500565234ULL);
x86_l_335:
	/* 0x335: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_339:
	/* 0x339: jae    3f1 <generic_retkprobe_event+0x3f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3f1;
	}
x86_l_33f:
	/* 0x33f: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_344:
	/* 0x344: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_349:
	/* 0x349: mov    DWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_354:
	/* 0x354: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_35b:
	/* 0x35b: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_363:
	/* 0x363: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_368:
	/* 0x368: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36a:
	/* 0x36a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36c:
	/* 0x36c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36f:
	/* 0x36f: je     1ada <generic_retkprobe_event+0x1ada> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6874ULL;
	}
x86_l_375:
	/* 0x375: cmp    r14d,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 13ULL);
x86_l_379:
	/* 0x379: jle    caf <generic_retkprobe_event+0xcaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3247ULL;
	}
x86_l_37f:
	/* 0x37f: cmp    r14d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 30ULL);
x86_l_383:
	/* 0x383: jg     e4f <generic_retkprobe_event+0xe4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3663ULL;
	}
x86_l_389:
	/* 0x389: cmp    r14d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 28ULL);
x86_l_38d:
	/* 0x38d: jg     10ef <generic_retkprobe_event+0x10ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4335ULL;
	}
x86_l_393:
	/* 0x393: cmp    r14d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 14ULL);
x86_l_397:
	/* 0x397: je     1a27 <generic_retkprobe_event+0x1a27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6695ULL;
	}
x86_l_39d:
	/* 0x39d: cmp    r14d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 17ULL);
x86_l_3a1:
	/* 0x3a1: je     194e <generic_retkprobe_event+0x194e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6478ULL;
	}
x86_l_3a7:
	/* 0x3a7: cmp    r14d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 28ULL);
x86_l_3ab:
	/* 0x3ab: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b0:
	/* 0x3b0: je     1050 <generic_retkprobe_event+0x1050> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4176ULL;
	}
x86_l_3b6:
	/* 0x3b6: jmp    953 <generic_retkprobe_event+0x953> */
	return 2387ULL;
x86_l_3bb:
	/* 0x3bb: mov    QWORD PTR [rsp+0x90],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3c3:
	/* 0x3c3: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3c8:
	/* 0x3c8: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3cd:
	/* 0x3cd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3d2:
	/* 0x3d2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d7:
	/* 0x3d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3dc:
	/* 0x3dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3de:
	/* 0x3de: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3e3:
	/* 0x3e3: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e8:
	/* 0x3e8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3eb:
	/* 0x3eb: jne    4e4 <generic_retkprobe_event+0x4e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4e4;
	}
x86_l_3f1:
	/* 0x3f1: mov    DWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_3fc:
	/* 0x3fc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_403:
	/* 0x403: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_40b:
	/* 0x40b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_410:
	/* 0x410: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_412:
	/* 0x412: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_415:
	/* 0x415: mov    QWORD PTR [rsp+0x98],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_41d:
	/* 0x41d: je     e3e <generic_retkprobe_event+0xe3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3646ULL;
	}
x86_l_423:
	/* 0x423: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_425:
	/* 0x425: cmp    r14d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 25ULL);
x86_l_429:
	/* 0x429: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42e:
	/* 0x42e: jg     1076 <generic_retkprobe_event+0x1076> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4214ULL;
	}
x86_l_434:
	/* 0x434: cmp    r14d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 18ULL);
x86_l_438:
	/* 0x438: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_440:
	/* 0x440: jle    11d9 <generic_retkprobe_event+0x11d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4569ULL;
	}
x86_l_446:
	/* 0x446: cmp    r14d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 20ULL);
x86_l_44a:
	/* 0x44a: jle    1690 <generic_retkprobe_event+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5776ULL;
	}
x86_l_450:
	/* 0x450: cmp    r14d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 21ULL);
x86_l_454:
	/* 0x454: je     1f4f <generic_retkprobe_event+0x1f4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8015ULL;
	}
x86_l_45a:
	/* 0x45a: cmp    r14d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 22ULL);
x86_l_45e:
	/* 0x45e: je     1eb7 <generic_retkprobe_event+0x1eb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7863ULL;
	}
x86_l_464:
	/* 0x464: cmp    r14d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 23ULL);
x86_l_468:
	/* 0x468: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_46d:
	/* 0x46d: jne    2674 <generic_retkprobe_event+0x2674> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9844ULL;
	}
x86_l_473:
	/* 0x473: mov    DWORD PTR [rcx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_47d:
	/* 0x47d: mov    DWORD PTR [rcx+0x9c],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_484:
	/* 0x484: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_489:
	/* 0x489: jmp    2674 <generic_retkprobe_event+0x2674> */
	return 9844ULL;
x86_l_48e:
	/* 0x48e: lea    r14,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_493:
	/* 0x493: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_498:
	/* 0x498: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_49d:
	/* 0x49d: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a2:
	/* 0x4a2: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4a7:
	/* 0x4a7: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_4aa:
	/* 0x4aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4af:
	/* 0x4af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b1:
	/* 0x4b1: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b6:
	/* 0x4b6: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4bb:
	/* 0x4bb: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4c0:
	/* 0x4c0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4c5:
	/* 0x4c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4ca:
	/* 0x4ca: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4cf:
	/* 0x4cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d4:
	/* 0x4d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d6:
	/* 0x4d6: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4db:
	/* 0x4db: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_4df:
	/* 0x4df: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e4:
	/* 0x4e4: mov    QWORD PTR [rsp+0x98],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4ec:
	/* 0x4ec: mov    DWORD PTR [rsp+0xb4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_4f7:
	/* 0x4f7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_4fe:
	/* 0x4fe: lea    rsi,[rsp+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_506:
	/* 0x506: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_50b:
	/* 0x50b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50d:
	/* 0x50d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_510:
	/* 0x510: je     5c6 <generic_retkprobe_event+0x5c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c6;
	}
x86_l_516:
	/* 0x516: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_519:
	/* 0x519: add    rax,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_51f:
	/* 0x51f: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_527:
	/* 0x527: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_52c:
	/* 0x52c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52e:
	/* 0x52e: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_535:
	/* 0x535: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_53d:
	/* 0x53d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_542:
	/* 0x542: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_547:
	/* 0x547: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54c:
	/* 0x54c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54e:
	/* 0x54e: mov    r14,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_556:
	/* 0x556: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_55b:
	/* 0x55b: lea    rdx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55f:
	/* 0x55f: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_567:
	/* 0x567: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_56c:
	/* 0x56c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_571:
	/* 0x571: lea    rcx,[r14+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_575:
	/* 0x575: mov    QWORD PTR [rsp+0xf0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_57d:
	/* 0x57d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_582:
	/* 0x582: mov    QWORD PTR [rsp+0xe0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_58a:
	/* 0x58a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58c:
	/* 0x58c: mov    rbp,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_594:
	/* 0x594: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_598:
	/* 0x598: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_59d:
	/* 0x59d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5a2:
	/* 0x5a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5a7:
	/* 0x5a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ac:
	/* 0x5ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ae:
	/* 0x5ae: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5b4:
	/* 0x5b4: mov    r13d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4096ULL);
x86_l_5ba:
	/* 0x5ba: je     5d5 <generic_retkprobe_event+0x5d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d5;
	}
x86_l_5bc:
	/* 0x5bc: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_5c4:
	/* 0x5c4: jmp    62b <generic_retkprobe_event+0x62b> */
	goto x86_l_62b;
x86_l_5c6:
	/* 0x5c6: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c8:
	/* 0x5c8: mov    r12,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_5d0:
	/* 0x5d0: jmp    b23 <generic_retkprobe_event+0xb23> */
	return 2851ULL;
x86_l_5d5:
	/* 0x5d5: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d9:
	/* 0x5d9: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5de:
	/* 0x5de: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5e3:
	/* 0x5e3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5e8:
	/* 0x5e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ed:
	/* 0x5ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ef:
	/* 0x5ef: cmp    QWORD PTR [rsp+0x28],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5f4:
	/* 0x5f4: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_5fc:
	/* 0x5fc: je     62b <generic_retkprobe_event+0x62b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_62b;
	}
x86_l_5fe:
	/* 0x5fe: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_601:
	/* 0x601: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_608:
	/* 0x608: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_612:
	/* 0x612: mov    QWORD PTR [r12+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_61a:
	/* 0x61a: mov    WORD PTR [r12+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_625:
	/* 0x625: mov    r13d,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4086ULL);
x86_l_62b:
	/* 0x62b: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_634:
	/* 0x634: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_63d:
	/* 0x63d: mov    QWORD PTR [rsp+0x38],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_642:
	/* 0x642: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_64b:
	/* 0x64b: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_654:
	/* 0x654: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_65d:
	/* 0x65d: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_665:
	/* 0x665: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_66a:
	/* 0x66a: mov    DWORD PTR [rsp+0x60],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_66f:
	/* 0x66f: mov    BYTE PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_674:
	/* 0x674: add    r14,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_678:
	/* 0x678: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_67d:
	/* 0x67d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_682:
	/* 0x682: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_687:
	/* 0x687: lea    r12,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_68c:
	/* 0x68c: lea    rbp,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_691:
	/* 0x691: lea    r13,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_696:
	/* 0x696: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_69b:
	/* 0x69b: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_69e:
	/* 0x69e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a0:
	/* 0x6a0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6a5:
	/* 0x6a5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6aa:
	/* 0x6aa: mov    rdx,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_6b2:
	/* 0x6b2: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_6b5:
	/* 0x6b5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6ba:
	/* 0x6ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6bc:
	/* 0x6bc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6c1:
	/* 0x6c1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6c6:
	/* 0x6c6: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_6ce:
	/* 0x6ce: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_6d1:
	/* 0x6d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6d6:
	/* 0x6d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d8:
	/* 0x6d8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6dd:
	/* 0x6dd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6e2:
	/* 0x6e2: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6e7:
	/* 0x6e7: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_6ea:
	/* 0x6ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6ef:
	/* 0x6ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f1:
	/* 0x6f1: mov    r14,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6f6:
	/* 0x6f6: lea    rax,[r14-0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551584ULL);
x86_l_6fa:
	/* 0x6fa: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6ff:
	/* 0x6ff: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_704:
	/* 0x704: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_709:
	/* 0x709: jne    772 <generic_retkprobe_event+0x772> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_772;
	}
x86_l_70b:
	/* 0x70b: cmp    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_710:
	/* 0x710: jne    772 <generic_retkprobe_event+0x772> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_772;
	}
x86_l_712:
	/* 0x712: mov    BYTE PTR [rsp+0x64],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 429496729601ULL);
x86_l_717:
	/* 0x717: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_71d:
	/* 0x71d: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_722:
	/* 0x722: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_72a:
	/* 0x72a: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_72d:
	/* 0x72d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_732:
	/* 0x732: mov    r12,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_73a:
	/* 0x73a: je     8aa <generic_retkprobe_event+0x8aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2218ULL;
	}
x86_l_740:
	/* 0x740: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_743:
	/* 0x743: cmp    BYTE PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_748:
	/* 0x748: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_74b:
	/* 0x74b: mov    edx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_74f:
	/* 0x74f: mov    ebp,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_754:
	/* 0x754: sub    ebp,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_756:
	/* 0x756: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_758:
	/* 0x758: cmovle ebp,edx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_75b:
	/* 0x75b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_75e:
	/* 0x75e: je     b21 <generic_retkprobe_event+0xb21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2849ULL;
	}
x86_l_764:
	/* 0x764: mov    r14b,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_8);
x86_l_767:
	/* 0x767: add    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_76a:
	/* 0x76a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_76d:
	/* 0x76d: jmp    8af <generic_retkprobe_event+0x8af> */
	return 2223ULL;
x86_l_772:
	/* 0x772: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_77a:
	/* 0x77a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_77f:
	/* 0x77f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_784:
	/* 0x784: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_789:
	/* 0x789: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
	return 1932ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1932ULL: goto x86_l_78c;
	case 1934ULL: goto x86_l_78e;
	case 1942ULL: goto x86_l_796;
	case 1948ULL: goto x86_l_79c;
	case 1953ULL: goto x86_l_7a1;
	case 1958ULL: goto x86_l_7a6;
	case 1963ULL: goto x86_l_7ab;
	case 1968ULL: goto x86_l_7b0;
	case 1973ULL: goto x86_l_7b5;
	case 1976ULL: goto x86_l_7b8;
	case 1978ULL: goto x86_l_7ba;
	case 1983ULL: goto x86_l_7bf;
	case 1989ULL: goto x86_l_7c5;
	case 1997ULL: goto x86_l_7cd;
	case 2002ULL: goto x86_l_7d2;
	case 2007ULL: goto x86_l_7d7;
	case 2012ULL: goto x86_l_7dc;
	case 2015ULL: goto x86_l_7df;
	case 2017ULL: goto x86_l_7e1;
	case 2021ULL: goto x86_l_7e5;
	case 2026ULL: goto x86_l_7ea;
	case 2031ULL: goto x86_l_7ef;
	case 2036ULL: goto x86_l_7f4;
	case 2041ULL: goto x86_l_7f9;
	case 2044ULL: goto x86_l_7fc;
	case 2046ULL: goto x86_l_7fe;
	case 2051ULL: goto x86_l_803;
	case 2056ULL: goto x86_l_808;
	case 2060ULL: goto x86_l_80c;
	case 2063ULL: goto x86_l_80f;
	case 2068ULL: goto x86_l_814;
	case 2070ULL: goto x86_l_816;
	case 2072ULL: goto x86_l_818;
	case 2075ULL: goto x86_l_81b;
	case 2078ULL: goto x86_l_81e;
	case 2083ULL: goto x86_l_823;
	case 2085ULL: goto x86_l_825;
	case 2088ULL: goto x86_l_828;
	case 2092ULL: goto x86_l_82c;
	case 2094ULL: goto x86_l_82e;
	case 2098ULL: goto x86_l_832;
	case 2100ULL: goto x86_l_834;
	case 2103ULL: goto x86_l_837;
	case 2105ULL: goto x86_l_839;
	case 2109ULL: goto x86_l_83d;
	case 2112ULL: goto x86_l_840;
	case 2118ULL: goto x86_l_846;
	case 2124ULL: goto x86_l_84c;
	case 2130ULL: goto x86_l_852;
	case 2136ULL: goto x86_l_858;
	case 2139ULL: goto x86_l_85b;
	case 2141ULL: goto x86_l_85d;
	case 2146ULL: goto x86_l_862;
	case 2148ULL: goto x86_l_864;
	case 2151ULL: goto x86_l_867;
	case 2155ULL: goto x86_l_86b;
	case 2158ULL: goto x86_l_86e;
	case 2161ULL: goto x86_l_871;
	case 2164ULL: goto x86_l_874;
	case 2169ULL: goto x86_l_879;
	case 2171ULL: goto x86_l_87b;
	case 2176ULL: goto x86_l_880;
	case 2179ULL: goto x86_l_883;
	case 2185ULL: goto x86_l_889;
	case 2193ULL: goto x86_l_891;
	case 2198ULL: goto x86_l_896;
	case 2203ULL: goto x86_l_89b;
	case 2208ULL: goto x86_l_8a0;
	case 2213ULL: goto x86_l_8a5;
	case 2218ULL: goto x86_l_8aa;
	case 2221ULL: goto x86_l_8ad;
	case 2223ULL: goto x86_l_8af;
	case 2230ULL: goto x86_l_8b6;
	case 2236ULL: goto x86_l_8bc;
	case 2241ULL: goto x86_l_8c1;
	case 2243ULL: goto x86_l_8c3;
	case 2245ULL: goto x86_l_8c5;
	case 2250ULL: goto x86_l_8ca;
	case 2256ULL: goto x86_l_8d0;
	case 2261ULL: goto x86_l_8d5;
	case 2266ULL: goto x86_l_8da;
	case 2271ULL: goto x86_l_8df;
	case 2279ULL: goto x86_l_8e7;
	case 2284ULL: goto x86_l_8ec;
	case 2286ULL: goto x86_l_8ee;
	case 2291ULL: goto x86_l_8f3;
	case 2295ULL: goto x86_l_8f7;
	case 2300ULL: goto x86_l_8fc;
	case 2305ULL: goto x86_l_901;
	case 2310ULL: goto x86_l_906;
	case 2315ULL: goto x86_l_90b;
	case 2319ULL: goto x86_l_90f;
	case 2324ULL: goto x86_l_914;
	case 2326ULL: goto x86_l_916;
	case 2331ULL: goto x86_l_91b;
	case 2336ULL: goto x86_l_920;
	case 2341ULL: goto x86_l_925;
	case 2346ULL: goto x86_l_92a;
	case 2351ULL: goto x86_l_92f;
	case 2356ULL: goto x86_l_934;
	case 2358ULL: goto x86_l_936;
	case 2363ULL: goto x86_l_93b;
	case 2371ULL: goto x86_l_943;
	case 2376ULL: goto x86_l_948;
	case 2384ULL: goto x86_l_950;
	case 2387ULL: goto x86_l_953;
	case 2392ULL: goto x86_l_958;
	case 2396ULL: goto x86_l_95c;
	case 2398ULL: goto x86_l_95e;
	case 2404ULL: goto x86_l_964;
	case 2414ULL: goto x86_l_96e;
	case 2424ULL: goto x86_l_978;
	case 2429ULL: goto x86_l_97d;
	case 2433ULL: goto x86_l_981;
	case 2438ULL: goto x86_l_986;
	case 2443ULL: goto x86_l_98b;
	case 2448ULL: goto x86_l_990;
	case 2453ULL: goto x86_l_995;
	case 2455ULL: goto x86_l_997;
	case 2460ULL: goto x86_l_99c;
	case 2465ULL: goto x86_l_9a1;
	case 2471ULL: goto x86_l_9a7;
	case 2475ULL: goto x86_l_9ab;
	case 2480ULL: goto x86_l_9b0;
	case 2485ULL: goto x86_l_9b5;
	case 2488ULL: goto x86_l_9b8;
	case 2493ULL: goto x86_l_9bd;
	case 2496ULL: goto x86_l_9c0;
	case 2498ULL: goto x86_l_9c2;
	case 2503ULL: goto x86_l_9c7;
	case 2508ULL: goto x86_l_9cc;
	case 2512ULL: goto x86_l_9d0;
	case 2517ULL: goto x86_l_9d5;
	case 2522ULL: goto x86_l_9da;
	case 2527ULL: goto x86_l_9df;
	case 2529ULL: goto x86_l_9e1;
	case 2534ULL: goto x86_l_9e6;
	case 2540ULL: goto x86_l_9ec;
	case 2548ULL: goto x86_l_9f4;
	case 2553ULL: goto x86_l_9f9;
	case 2558ULL: goto x86_l_9fe;
	case 2563ULL: goto x86_l_a03;
	case 2565ULL: goto x86_l_a05;
	case 2573ULL: goto x86_l_a0d;
	case 2579ULL: goto x86_l_a13;
	case 2584ULL: goto x86_l_a18;
	case 2589ULL: goto x86_l_a1d;
	case 2594ULL: goto x86_l_a22;
	case 2599ULL: goto x86_l_a27;
	case 2604ULL: goto x86_l_a2c;
	case 2607ULL: goto x86_l_a2f;
	case 2609ULL: goto x86_l_a31;
	case 2614ULL: goto x86_l_a36;
	case 2620ULL: goto x86_l_a3c;
	case 2628ULL: goto x86_l_a44;
	case 2633ULL: goto x86_l_a49;
	case 2638ULL: goto x86_l_a4e;
	case 2643ULL: goto x86_l_a53;
	case 2646ULL: goto x86_l_a56;
	case 2648ULL: goto x86_l_a58;
	case 2652ULL: goto x86_l_a5c;
	case 2657ULL: goto x86_l_a61;
	case 2662ULL: goto x86_l_a66;
	case 2667ULL: goto x86_l_a6b;
	case 2672ULL: goto x86_l_a70;
	case 2675ULL: goto x86_l_a73;
	case 2677ULL: goto x86_l_a75;
	case 2682ULL: goto x86_l_a7a;
	case 2687ULL: goto x86_l_a7f;
	case 2691ULL: goto x86_l_a83;
	case 2694ULL: goto x86_l_a86;
	case 2699ULL: goto x86_l_a8b;
	case 2701ULL: goto x86_l_a8d;
	case 2703ULL: goto x86_l_a8f;
	case 2706ULL: goto x86_l_a92;
	case 2709ULL: goto x86_l_a95;
	case 2714ULL: goto x86_l_a9a;
	case 2716ULL: goto x86_l_a9c;
	case 2719ULL: goto x86_l_a9f;
	case 2723ULL: goto x86_l_aa3;
	case 2725ULL: goto x86_l_aa5;
	case 2729ULL: goto x86_l_aa9;
	case 2731ULL: goto x86_l_aab;
	case 2734ULL: goto x86_l_aae;
	case 2736ULL: goto x86_l_ab0;
	case 2740ULL: goto x86_l_ab4;
	case 2743ULL: goto x86_l_ab7;
	case 2749ULL: goto x86_l_abd;
	case 2755ULL: goto x86_l_ac3;
	case 2761ULL: goto x86_l_ac9;
	case 2767ULL: goto x86_l_acf;
	case 2770ULL: goto x86_l_ad2;
	case 2772ULL: goto x86_l_ad4;
	case 2777ULL: goto x86_l_ad9;
	case 2779ULL: goto x86_l_adb;
	case 2782ULL: goto x86_l_ade;
	case 2786ULL: goto x86_l_ae2;
	case 2789ULL: goto x86_l_ae5;
	case 2792ULL: goto x86_l_ae8;
	case 2795ULL: goto x86_l_aeb;
	case 2800ULL: goto x86_l_af0;
	case 2802ULL: goto x86_l_af2;
	case 2807ULL: goto x86_l_af7;
	case 2810ULL: goto x86_l_afa;
	case 2816ULL: goto x86_l_b00;
	case 2824ULL: goto x86_l_b08;
	case 2829ULL: goto x86_l_b0d;
	case 2834ULL: goto x86_l_b12;
	case 2839ULL: goto x86_l_b17;
	case 2844ULL: goto x86_l_b1c;
	case 2849ULL: goto x86_l_b21;
	case 2851ULL: goto x86_l_b23;
	case 2856ULL: goto x86_l_b28;
	case 2860ULL: goto x86_l_b2c;
	case 2866ULL: goto x86_l_b32;
	case 2870ULL: goto x86_l_b36;
	case 2873ULL: goto x86_l_b39;
	case 2881ULL: goto x86_l_b41;
	case 2885ULL: goto x86_l_b45;
	case 2892ULL: goto x86_l_b4c;
	case 2899ULL: goto x86_l_b53;
	case 2902ULL: goto x86_l_b56;
	case 2908ULL: goto x86_l_b5c;
	case 2911ULL: goto x86_l_b5f;
	case 2917ULL: goto x86_l_b65;
	case 2922ULL: goto x86_l_b6a;
	case 2925ULL: goto x86_l_b6d;
	case 2928ULL: goto x86_l_b70;
	case 2936ULL: goto x86_l_b78;
	case 2943ULL: goto x86_l_b7f;
	case 2946ULL: goto x86_l_b82;
	case 2952ULL: goto x86_l_b88;
	case 2956ULL: goto x86_l_b8c;
	case 2960ULL: goto x86_l_b90;
	case 2964ULL: goto x86_l_b94;
	case 2969ULL: goto x86_l_b99;
	case 2973ULL: goto x86_l_b9d;
	case 2976ULL: goto x86_l_ba0;
	case 2980ULL: goto x86_l_ba4;
	case 2986ULL: goto x86_l_baa;
	case 2989ULL: goto x86_l_bad;
	case 2991ULL: goto x86_l_baf;
	case 2996ULL: goto x86_l_bb4;
	case 2998ULL: goto x86_l_bb6;
	case 3000ULL: goto x86_l_bb8;
	case 3004ULL: goto x86_l_bbc;
	case 3008ULL: goto x86_l_bc0;
	case 3011ULL: goto x86_l_bc3;
	case 3014ULL: goto x86_l_bc6;
	case 3017ULL: goto x86_l_bc9;
	case 3019ULL: goto x86_l_bcb;
	case 3022ULL: goto x86_l_bce;
	case 3027ULL: goto x86_l_bd3;
	case 3032ULL: goto x86_l_bd8;
	case 3034ULL: goto x86_l_bda;
	case 3039ULL: goto x86_l_bdf;
	case 3044ULL: goto x86_l_be4;
	case 3053ULL: goto x86_l_bed;
	case 3055ULL: goto x86_l_bef;
	case 3058ULL: goto x86_l_bf2;
	case 3063ULL: goto x86_l_bf7;
	case 3071ULL: goto x86_l_bff;
	case 3075ULL: goto x86_l_c03;
	case 3080ULL: goto x86_l_c08;
	case 3086ULL: goto x86_l_c0e;
	case 3091ULL: goto x86_l_c13;
	case 3096ULL: goto x86_l_c18;
	case 3101ULL: goto x86_l_c1d;
	case 3103ULL: goto x86_l_c1f;
	case 3108ULL: goto x86_l_c24;
	case 3110ULL: goto x86_l_c26;
	case 3116ULL: goto x86_l_c2c;
	case 3121ULL: goto x86_l_c31;
	case 3126ULL: goto x86_l_c36;
	case 3129ULL: goto x86_l_c39;
	case 3132ULL: goto x86_l_c3c;
	case 3136ULL: goto x86_l_c40;
	case 3139ULL: goto x86_l_c43;
	case 3143ULL: goto x86_l_c47;
	case 3148ULL: goto x86_l_c4c;
	case 3155ULL: goto x86_l_c53;
	case 3161ULL: goto x86_l_c59;
	case 3166ULL: goto x86_l_c5e;
	case 3169ULL: goto x86_l_c61;
	case 3174ULL: goto x86_l_c66;
	case 3178ULL: goto x86_l_c6a;
	case 3183ULL: goto x86_l_c6f;
	case 3188ULL: goto x86_l_c74;
	case 3193ULL: goto x86_l_c79;
	case 3196ULL: goto x86_l_c7c;
	case 3198ULL: goto x86_l_c7e;
	case 3203ULL: goto x86_l_c83;
	case 3205ULL: goto x86_l_c85;
	case 3211ULL: goto x86_l_c8b;
	case 3214ULL: goto x86_l_c8e;
	case 3219ULL: goto x86_l_c93;
	case 3222ULL: goto x86_l_c96;
	case 3228ULL: goto x86_l_c9c;
	case 3231ULL: goto x86_l_c9f;
	case 3236ULL: goto x86_l_ca4;
	case 3242ULL: goto x86_l_caa;
	case 3247ULL: goto x86_l_caf;
	case 3251ULL: goto x86_l_cb3;
	case 3257ULL: goto x86_l_cb9;
	case 3261ULL: goto x86_l_cbd;
	case 3264ULL: goto x86_l_cc0;
	case 3269ULL: goto x86_l_cc5;
	case 3275ULL: goto x86_l_ccb;
	case 3279ULL: goto x86_l_ccf;
	case 3282ULL: goto x86_l_cd2;
	case 3288ULL: goto x86_l_cd8;
	case 3292ULL: goto x86_l_cdc;
	case 3298ULL: goto x86_l_ce2;
	case 3303ULL: goto x86_l_ce7;
	case 3310ULL: goto x86_l_cee;
	case 3317ULL: goto x86_l_cf5;
	case 3321ULL: goto x86_l_cf9;
	case 3326ULL: goto x86_l_cfe;
	case 3331ULL: goto x86_l_d03;
	case 3336ULL: goto x86_l_d08;
	case 3338ULL: goto x86_l_d0a;
	case 3343ULL: goto x86_l_d0f;
	case 3350ULL: goto x86_l_d16;
	case 3354ULL: goto x86_l_d1a;
	case 3359ULL: goto x86_l_d1f;
	case 3364ULL: goto x86_l_d24;
	case 3369ULL: goto x86_l_d29;
	case 3371ULL: goto x86_l_d2b;
	case 3376ULL: goto x86_l_d30;
	case 3383ULL: goto x86_l_d37;
	case 3390ULL: goto x86_l_d3e;
	case 3395ULL: goto x86_l_d43;
	case 3400ULL: goto x86_l_d48;
	case 3405ULL: goto x86_l_d4d;
	case 3407ULL: goto x86_l_d4f;
	case 3412ULL: goto x86_l_d54;
	case 3419ULL: goto x86_l_d5b;
	case 3426ULL: goto x86_l_d62;
	case 3431ULL: goto x86_l_d67;
	case 3436ULL: goto x86_l_d6c;
	case 3441ULL: goto x86_l_d71;
	case 3443ULL: goto x86_l_d73;
	case 3448ULL: goto x86_l_d78;
	case 3455ULL: goto x86_l_d7f;
	case 3462ULL: goto x86_l_d86;
	case 3467ULL: goto x86_l_d8b;
	case 3472ULL: goto x86_l_d90;
	case 3477ULL: goto x86_l_d95;
	case 3479ULL: goto x86_l_d97;
	case 3484ULL: goto x86_l_d9c;
	case 3491ULL: goto x86_l_da3;
	case 3498ULL: goto x86_l_daa;
	case 3503ULL: goto x86_l_daf;
	case 3508ULL: goto x86_l_db4;
	case 3513ULL: goto x86_l_db9;
	case 3515ULL: goto x86_l_dbb;
	case 3520ULL: goto x86_l_dc0;
	case 3527ULL: goto x86_l_dc7;
	case 3535ULL: goto x86_l_dcf;
	case 3542ULL: goto x86_l_dd6;
	case 3550ULL: goto x86_l_dde;
	case 3558ULL: goto x86_l_de6;
	case 3566ULL: goto x86_l_dee;
	case 3573ULL: goto x86_l_df5;
	case 3576ULL: goto x86_l_df8;
	case 3582ULL: goto x86_l_dfe;
	case 3585ULL: goto x86_l_e01;
	case 3591ULL: goto x86_l_e07;
	case 3595ULL: goto x86_l_e0b;
	case 3600ULL: goto x86_l_e10;
	case 3605ULL: goto x86_l_e15;
	case 3613ULL: goto x86_l_e1d;
	case 3618ULL: goto x86_l_e22;
	case 3620ULL: goto x86_l_e24;
	case 3625ULL: goto x86_l_e29;
	case 3630ULL: goto x86_l_e2e;
	case 3633ULL: goto x86_l_e31;
	case 3638ULL: goto x86_l_e36;
	case 3641ULL: goto x86_l_e39;
	case 3646ULL: goto x86_l_e3e;
	case 3648ULL: goto x86_l_e40;
	case 3653ULL: goto x86_l_e45;
	case 3658ULL: goto x86_l_e4a;
	case 3663ULL: goto x86_l_e4f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_78c:
	/* 0x78c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78e:
	/* 0x78e: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_796:
	/* 0x796: je     97d <generic_retkprobe_event+0x97d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_97d;
	}
x86_l_79c:
	/* 0x79c: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7a1:
	/* 0x7a1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7a6:
	/* 0x7a6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7ab:
	/* 0x7ab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7b0:
	/* 0x7b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7b5:
	/* 0x7b5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_7b8:
	/* 0x7b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ba:
	/* 0x7ba: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7bf:
	/* 0x7bf: je     97d <generic_retkprobe_event+0x97d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_97d;
	}
x86_l_7c5:
	/* 0x7c5: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_7cd:
	/* 0x7cd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7d2:
	/* 0x7d2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7d7:
	/* 0x7d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7dc:
	/* 0x7dc: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_7df:
	/* 0x7df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e1:
	/* 0x7e1: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_7e5:
	/* 0x7e5: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_7ea:
	/* 0x7ea: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_7ef:
	/* 0x7ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7f4:
	/* 0x7f4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_7f9:
	/* 0x7f9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_7fc:
	/* 0x7fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7fe:
	/* 0x7fe: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_803:
	/* 0x803: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_808:
	/* 0x808: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_80c:
	/* 0x80c: sub    rax,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_80f:
	/* 0x80f: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_814:
	/* 0x814: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_816:
	/* 0x816: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_818:
	/* 0x818: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_81b:
	/* 0x81b: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_81e:
	/* 0x81e: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_823:
	/* 0x823: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_825:
	/* 0x825: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_828:
	/* 0x828: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_82c:
	/* 0x82c: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_82e:
	/* 0x82e: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_832:
	/* 0x832: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_834:
	/* 0x834: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_837:
	/* 0x837: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_839:
	/* 0x839: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_83d:
	/* 0x83d: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_840:
	/* 0x840: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_846:
	/* 0x846: jb     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1821ULL;
	}
x86_l_84c:
	/* 0x84c: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_852:
	/* 0x852: ja     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1821ULL;
	}
x86_l_858:
	/* 0x858: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_85b:
	/* 0x85b: jbe    862 <generic_retkprobe_event+0x862> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_862;
	}
x86_l_85d:
	/* 0x85d: mov    BYTE PTR [r14+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_862:
	/* 0x862: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_864:
	/* 0x864: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_867:
	/* 0x867: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_86b:
	/* 0x86b: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_86e:
	/* 0x86e: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_871:
	/* 0x871: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_874:
	/* 0x874: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_879:
	/* 0x879: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_87b:
	/* 0x87b: mov    QWORD PTR [rsp+0x58],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_880:
	/* 0x880: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_883:
	/* 0x883: jbe    71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1821ULL;
	}
x86_l_889:
	/* 0x889: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_891:
	/* 0x891: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_896:
	/* 0x896: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_89b:
	/* 0x89b: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8a0:
	/* 0x8a0: lea    rbp,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8a5:
	/* 0x8a5: jmp    9da <generic_retkprobe_event+0x9da> */
	goto x86_l_9da;
x86_l_8aa:
	/* 0x8aa: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8ad:
	/* 0x8ad: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8af:
	/* 0x8af: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_8b6:
	/* 0x8b6: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8bc:
	/* 0x8bc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8c1:
	/* 0x8c1: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_8c3:
	/* 0x8c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c5:
	/* 0x8c5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8ca:
	/* 0x8ca: mov    DWORD PTR [rax+0x9c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_8d0:
	/* 0x8d0: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8d5:
	/* 0x8d5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8da:
	/* 0x8da: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8df:
	/* 0x8df: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_8e7:
	/* 0x8e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8ec:
	/* 0x8ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ee:
	/* 0x8ee: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8f3:
	/* 0x8f3: add    rcx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_8f7:
	/* 0x8f7: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_8fc:
	/* 0x8fc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_901:
	/* 0x901: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_906:
	/* 0x906: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_90b:
	/* 0x90b: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_90f:
	/* 0x90f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_914:
	/* 0x914: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_916:
	/* 0x916: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_91b:
	/* 0x91b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_920:
	/* 0x920: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_925:
	/* 0x925: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_92a:
	/* 0x92a: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_92f:
	/* 0x92f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_934:
	/* 0x934: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_936:
	/* 0x936: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_93b:
	/* 0x93b: mov    DWORD PTR [rcx+rbp*1+0xa0],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 160ULL);
x86_l_943:
	/* 0x943: movzx  eax,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_948:
	/* 0x948: mov    WORD PTR [rcx+rbp*1+0xa4],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_RBP, 0), 164ULL);
x86_l_950:
	/* 0x950: add    ebp,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_953:
	/* 0x953: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_958:
	/* 0x958: mov    eax,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_95c:
	/* 0x95c: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_95e:
	/* 0x95e: jns    b2c <generic_retkprobe_event+0xb2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_b2c;
	}
x86_l_964:
	/* 0x964: mov    DWORD PTR [rcx+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104045582745599ULL);
x86_l_96e:
	/* 0x96e: mov    DWORD PTR [rcx+0x98],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 657129996287ULL);
x86_l_978:
	/* 0x978: jmp    b39 <generic_retkprobe_event+0xb39> */
	goto x86_l_b39;
x86_l_97d:
	/* 0x97d: lea    rdx,[r14-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_981:
	/* 0x981: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_986:
	/* 0x986: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_98b:
	/* 0x98b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_990:
	/* 0x990: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_995:
	/* 0x995: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_997:
	/* 0x997: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_99c:
	/* 0x99c: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_9a1:
	/* 0x9a1: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_9a7:
	/* 0x9a7: add    r14,0xfffffffffffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551608ULL);
x86_l_9ab:
	/* 0x9ab: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9b0:
	/* 0x9b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9b5:
	/* 0x9b5: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_9b8:
	/* 0x9b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9bd:
	/* 0x9bd: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_9c0:
	/* 0x9c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c2:
	/* 0x9c2: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9c7:
	/* 0x9c7: mov    QWORD PTR [rsp+0x50],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9cc:
	/* 0x9cc: lea    rdx,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9d0:
	/* 0x9d0: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9d5:
	/* 0x9d5: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9da:
	/* 0x9da: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_9df:
	/* 0x9df: jne    9ec <generic_retkprobe_event+0x9ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9ec;
	}
x86_l_9e1:
	/* 0x9e1: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_9e6:
	/* 0x9e6: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_9ec:
	/* 0x9ec: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9f4:
	/* 0x9f4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9f9:
	/* 0x9f9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9fe:
	/* 0x9fe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a03:
	/* 0xa03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a05:
	/* 0xa05: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_a0d:
	/* 0xa0d: je     e8c <generic_retkprobe_event+0xe8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3724ULL;
	}
x86_l_a13:
	/* 0xa13: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a18:
	/* 0xa18: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a1d:
	/* 0xa1d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a22:
	/* 0xa22: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a27:
	/* 0xa27: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a2c:
	/* 0xa2c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_a2f:
	/* 0xa2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a31:
	/* 0xa31: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a36:
	/* 0xa36: je     e8c <generic_retkprobe_event+0xe8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3724ULL;
	}
x86_l_a3c:
	/* 0xa3c: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_a44:
	/* 0xa44: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a49:
	/* 0xa49: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a4e:
	/* 0xa4e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a53:
	/* 0xa53: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_a56:
	/* 0xa56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a58:
	/* 0xa58: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_a5c:
	/* 0xa5c: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a61:
	/* 0xa61: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_a66:
	/* 0xa66: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a6b:
	/* 0xa6b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_a70:
	/* 0xa70: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_a73:
	/* 0xa73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a75:
	/* 0xa75: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a7a:
	/* 0xa7a: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a7f:
	/* 0xa7f: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_a83:
	/* 0xa83: sub    rax,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_a86:
	/* 0xa86: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a8b:
	/* 0xa8b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a8d:
	/* 0xa8d: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_a8f:
	/* 0xa8f: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_a92:
	/* 0xa92: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_a95:
	/* 0xa95: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_a9a:
	/* 0xa9a: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a9c:
	/* 0xa9c: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_a9f:
	/* 0xa9f: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_aa3:
	/* 0xaa3: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_aa5:
	/* 0xaa5: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_aa9:
	/* 0xaa9: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_aab:
	/* 0xaab: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_aae:
	/* 0xaae: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_ab0:
	/* 0xab0: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ab4:
	/* 0xab4: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_ab7:
	/* 0xab7: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_abd:
	/* 0xabd: jb     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1821ULL;
	}
x86_l_ac3:
	/* 0xac3: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_ac9:
	/* 0xac9: ja     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1821ULL;
	}
x86_l_acf:
	/* 0xacf: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_ad2:
	/* 0xad2: jbe    ad9 <generic_retkprobe_event+0xad9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_ad9;
	}
x86_l_ad4:
	/* 0xad4: mov    BYTE PTR [r14+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_ad9:
	/* 0xad9: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_adb:
	/* 0xadb: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_ade:
	/* 0xade: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_ae2:
	/* 0xae2: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ae5:
	/* 0xae5: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ae8:
	/* 0xae8: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_aeb:
	/* 0xaeb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_af0:
	/* 0xaf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af2:
	/* 0xaf2: mov    QWORD PTR [rsp+0x58],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_af7:
	/* 0xaf7: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_afa:
	/* 0xafa: jbe    71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1821ULL;
	}
x86_l_b00:
	/* 0xb00: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b08:
	/* 0xb08: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b0d:
	/* 0xb0d: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b12:
	/* 0xb12: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b17:
	/* 0xb17: lea    rbp,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b1c:
	/* 0xb1c: jmp    ee9 <generic_retkprobe_event+0xee9> */
	return 3817ULL;
x86_l_b21:
	/* 0xb21: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b23:
	/* 0xb23: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b28:
	/* 0xb28: mov    eax,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_b2c:
	/* 0xb2c: and    ebp,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_b32:
	/* 0xb32: add    rbp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_b36:
	/* 0xb36: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_b39:
	/* 0xb39: mov    rbp,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_b41:
	/* 0xb41: add    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_b45:
	/* 0xb45: and    r13d,0x1fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 8191ULL);
x86_l_b4c:
	/* 0xb4c: add    rbx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_b53:
	/* 0xb53: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_b56:
	/* 0xb56: je     1de <generic_retkprobe_event+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 478ULL;
	}
x86_l_b5c:
	/* 0xb5c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b5f:
	/* 0xb5f: jne    3c6d <generic_retkprobe_event+0x3c6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15469ULL;
	}
x86_l_b65:
	/* 0xb65: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b6a:
	/* 0xb6a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_b6d:
	/* 0xb6d: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_b70:
	/* 0xb70: mov    DWORD PTR [rbx+r13*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_b78:
	/* 0xb78: cmp    r14,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 4095ULL);
x86_l_b7f:
	/* 0xb7f: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_b82:
	/* 0xb82: mov    r14d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4095ULL);
x86_l_b88:
	/* 0xb88: cmovb  r14,r15 */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_R15, X86_WIDTH_64, X86_CC_B);
x86_l_b8c:
	/* 0xb8c: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_b90:
	/* 0xb90: add    rdi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_b94:
	/* 0xb94: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b99:
	/* 0xb99: lea    r12,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b9d:
	/* 0xb9d: add    rbx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ba0:
	/* 0xba0: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_ba4:
	/* 0xba4: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_baa:
	/* 0xbaa: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_bad:
	/* 0xbad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_baf:
	/* 0xbaf: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_bb4:
	/* 0xbb4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bb6:
	/* 0xbb6: js     bc6 <generic_retkprobe_event+0xbc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_bc6;
	}
x86_l_bb8:
	/* 0xbb8: mov    DWORD PTR [rbx+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bbc:
	/* 0xbbc: add    r14,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_bc0:
	/* 0xbc0: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_bc3:
	/* 0xbc3: mov    r13,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_64);
x86_l_bc6:
	/* 0xbc6: add    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_bc9:
	/* 0xbc9: mov    DWORD PTR [rbx],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bcb:
	/* 0xbcb: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_bce:
	/* 0xbce: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bd3:
	/* 0xbd3: jmp    3c6d <generic_retkprobe_event+0x3c6d> */
	return 15469ULL;
x86_l_bd8:
	/* 0xbd8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bda:
	/* 0xbda: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bdf:
	/* 0xbdf: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_be4:
	/* 0xbe4: cmp    QWORD PTR [rsp+0xa8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505729ULL);
x86_l_bed:
	/* 0xbed: jne    bf7 <generic_retkprobe_event+0xbf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bf7;
	}
x86_l_bef:
	/* 0xbef: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_bf2:
	/* 0xbf2: jmp    2cb <generic_retkprobe_event+0x2cb> */
	return 715ULL;
x86_l_bf7:
	/* 0xbf7: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_bff:
	/* 0xbff: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c03:
	/* 0xc03: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c08:
	/* 0xc08: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_c0e:
	/* 0xc0e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_c13:
	/* 0xc13: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c18:
	/* 0xc18: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_c1d:
	/* 0xc1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c1f:
	/* 0xc1f: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_c24:
	/* 0xc24: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c26:
	/* 0xc26: js     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15444ULL;
	}
x86_l_c2c:
	/* 0xc2c: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c31:
	/* 0xc31: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c36:
	/* 0xc36: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_c39:
	/* 0xc39: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_c3c:
	/* 0xc3c: cmovb  r12,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_c40:
	/* 0xc40: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c43:
	/* 0xc43: cmovne r13,r12 */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_c47:
	/* 0xc47: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_c4c:
	/* 0xc4c: cmp    r13,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4094ULL);
x86_l_c53:
	/* 0xc53: ja     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 15444ULL;
	}
x86_l_c59:
	/* 0xc59: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c5e:
	/* 0xc5e: add    rax,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c61:
	/* 0xc61: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c66:
	/* 0xc66: lea    rdi,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_c6a:
	/* 0xc6a: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c6f:
	/* 0xc6f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c74:
	/* 0xc74: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c79:
	/* 0xc79: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_c7c:
	/* 0xc7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c7e:
	/* 0xc7e: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_c83:
	/* 0xc83: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c85:
	/* 0xc85: js     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15444ULL;
	}
x86_l_c8b:
	/* 0xc8b: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c8e:
	/* 0xc8e: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c93:
	/* 0xc93: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c96:
	/* 0xc96: je     1ae4 <generic_retkprobe_event+0x1ae4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6884ULL;
	}
x86_l_c9c:
	/* 0xc9c: sub    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_c9f:
	/* 0xc9f: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ca4:
	/* 0xca4: jne    1aeb <generic_retkprobe_event+0x1aeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6891ULL;
	}
x86_l_caa:
	/* 0xcaa: jmp    2897 <generic_retkprobe_event+0x2897> */
	return 10391ULL;
x86_l_caf:
	/* 0xcaf: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_cb3:
	/* 0xcb3: jle    1031 <generic_retkprobe_event+0x1031> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4145ULL;
	}
x86_l_cb9:
	/* 0xcb9: lea    eax,[r14-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_cbd:
	/* 0xcbd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cc0:
	/* 0xcc0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cc5:
	/* 0xcc5: jb     1050 <generic_retkprobe_event+0x1050> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4176ULL;
	}
x86_l_ccb:
	/* 0xccb: lea    eax,[r14-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_ccf:
	/* 0xccf: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cd2:
	/* 0xcd2: jb     10b3 <generic_retkprobe_event+0x10b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4275ULL;
	}
x86_l_cd8:
	/* 0xcd8: cmp    r14d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 7ULL);
x86_l_cdc:
	/* 0xcdc: jne    953 <generic_retkprobe_event+0x953> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_953;
	}
x86_l_ce2:
	/* 0xce2: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ce7:
	/* 0xce7: mov    QWORD PTR [rcx+0xc4],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_cee:
	/* 0xcee: lea    rdi,[rcx+0xc2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_cf5:
	/* 0xcf5: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cf9:
	/* 0xcf9: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_cfe:
	/* 0xcfe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d03:
	/* 0xd03: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_d08:
	/* 0xd08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d0a:
	/* 0xd0a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d0f:
	/* 0xd0f: lea    rdi,[rax+0xd6] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_d16:
	/* 0xd16: lea    rdx,[rbp+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_d1a:
	/* 0xd1a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d1f:
	/* 0xd1f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d24:
	/* 0xd24: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_d29:
	/* 0xd29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d2b:
	/* 0xd2b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d30:
	/* 0xd30: lea    rdi,[rax+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_d37:
	/* 0xd37: lea    rdx,[rbp+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_d3e:
	/* 0xd3e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d43:
	/* 0xd43: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d48:
	/* 0xd48: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_d4d:
	/* 0xd4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d4f:
	/* 0xd4f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d54:
	/* 0xd54: lea    rdi,[rax+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_d5b:
	/* 0xd5b: lea    rdx,[rbp+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_d62:
	/* 0xd62: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d67:
	/* 0xd67: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d6c:
	/* 0xd6c: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_d71:
	/* 0xd71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d73:
	/* 0xd73: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d78:
	/* 0xd78: lea    rdi,[rax+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_d7f:
	/* 0xd7f: lea    rdx,[rbp+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_d86:
	/* 0xd86: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d8b:
	/* 0xd8b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d90:
	/* 0xd90: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d95:
	/* 0xd95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d97:
	/* 0xd97: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d9c:
	/* 0xd9c: lea    rdi,[rax+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_da3:
	/* 0xda3: lea    rdx,[rbp+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_daa:
	/* 0xdaa: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_daf:
	/* 0xdaf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_db4:
	/* 0xdb4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_db9:
	/* 0xdb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dbb:
	/* 0xdbb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dc0:
	/* 0xdc0: lea    r14,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_dc7:
	/* 0xdc7: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_dcf:
	/* 0xdcf: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dd6:
	/* 0xdd6: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_dde:
	/* 0xdde: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_de6:
	/* 0xde6: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_dee:
	/* 0xdee: movzx  ecx,WORD PTR [rax+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_df5:
	/* 0xdf5: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_df8:
	/* 0xdf8: je     2253 <generic_retkprobe_event+0x2253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8787ULL;
	}
x86_l_dfe:
	/* 0xdfe: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e01:
	/* 0xe01: jne    2285 <generic_retkprobe_event+0x2285> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8837ULL;
	}
x86_l_e07:
	/* 0xe07: lea    rdx,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e0b:
	/* 0xe0b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e10:
	/* 0xe10: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e15:
	/* 0xe15: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_e1d:
	/* 0xe1d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e22:
	/* 0xe22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e24:
	/* 0xe24: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e29:
	/* 0xe29: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e2e:
	/* 0xe2e: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_e31:
	/* 0xe31: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e36:
	/* 0xe36: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_e39:
	/* 0xe39: jmp    227e <generic_retkprobe_event+0x227e> */
	return 8830ULL;
x86_l_e3e:
	/* 0xe3e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e40:
	/* 0xe40: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e45:
	/* 0xe45: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e4a:
	/* 0xe4a: jmp    2674 <generic_retkprobe_event+0x2674> */
	return 9844ULL;
x86_l_e4f:
	/* 0xe4f: cmp    r14d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 38ULL);
	return 3667ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3667ULL: goto x86_l_e53;
	case 3673ULL: goto x86_l_e59;
	case 3677ULL: goto x86_l_e5d;
	case 3680ULL: goto x86_l_e60;
	case 3686ULL: goto x86_l_e66;
	case 3691ULL: goto x86_l_e6b;
	case 3696ULL: goto x86_l_e70;
	case 3701ULL: goto x86_l_e75;
	case 3706ULL: goto x86_l_e7a;
	case 3714ULL: goto x86_l_e82;
	case 3719ULL: goto x86_l_e87;
	case 3724ULL: goto x86_l_e8c;
	case 3728ULL: goto x86_l_e90;
	case 3733ULL: goto x86_l_e95;
	case 3738ULL: goto x86_l_e9a;
	case 3743ULL: goto x86_l_e9f;
	case 3748ULL: goto x86_l_ea4;
	case 3750ULL: goto x86_l_ea6;
	case 3755ULL: goto x86_l_eab;
	case 3760ULL: goto x86_l_eb0;
	case 3766ULL: goto x86_l_eb6;
	case 3770ULL: goto x86_l_eba;
	case 3775ULL: goto x86_l_ebf;
	case 3780ULL: goto x86_l_ec4;
	case 3783ULL: goto x86_l_ec7;
	case 3788ULL: goto x86_l_ecc;
	case 3791ULL: goto x86_l_ecf;
	case 3793ULL: goto x86_l_ed1;
	case 3798ULL: goto x86_l_ed6;
	case 3803ULL: goto x86_l_edb;
	case 3807ULL: goto x86_l_edf;
	case 3812ULL: goto x86_l_ee4;
	case 3817ULL: goto x86_l_ee9;
	case 3822ULL: goto x86_l_eee;
	case 3824ULL: goto x86_l_ef0;
	case 3829ULL: goto x86_l_ef5;
	case 3835ULL: goto x86_l_efb;
	case 3843ULL: goto x86_l_f03;
	case 3848ULL: goto x86_l_f08;
	case 3853ULL: goto x86_l_f0d;
	case 3858ULL: goto x86_l_f12;
	case 3860ULL: goto x86_l_f14;
	case 3868ULL: goto x86_l_f1c;
	case 3874ULL: goto x86_l_f22;
	case 3879ULL: goto x86_l_f27;
	case 3884ULL: goto x86_l_f2c;
	case 3889ULL: goto x86_l_f31;
	case 3894ULL: goto x86_l_f36;
	case 3899ULL: goto x86_l_f3b;
	case 3902ULL: goto x86_l_f3e;
	case 3904ULL: goto x86_l_f40;
	case 3909ULL: goto x86_l_f45;
	case 3915ULL: goto x86_l_f4b;
	case 3923ULL: goto x86_l_f53;
	case 3928ULL: goto x86_l_f58;
	case 3933ULL: goto x86_l_f5d;
	case 3938ULL: goto x86_l_f62;
	case 3941ULL: goto x86_l_f65;
	case 3943ULL: goto x86_l_f67;
	case 3947ULL: goto x86_l_f6b;
	case 3952ULL: goto x86_l_f70;
	case 3957ULL: goto x86_l_f75;
	case 3962ULL: goto x86_l_f7a;
	case 3967ULL: goto x86_l_f7f;
	case 3970ULL: goto x86_l_f82;
	case 3972ULL: goto x86_l_f84;
	case 3977ULL: goto x86_l_f89;
	case 3982ULL: goto x86_l_f8e;
	case 3986ULL: goto x86_l_f92;
	case 3989ULL: goto x86_l_f95;
	case 3994ULL: goto x86_l_f9a;
	case 3996ULL: goto x86_l_f9c;
	case 3998ULL: goto x86_l_f9e;
	case 4001ULL: goto x86_l_fa1;
	case 4004ULL: goto x86_l_fa4;
	case 4009ULL: goto x86_l_fa9;
	case 4011ULL: goto x86_l_fab;
	case 4014ULL: goto x86_l_fae;
	case 4018ULL: goto x86_l_fb2;
	case 4020ULL: goto x86_l_fb4;
	case 4024ULL: goto x86_l_fb8;
	case 4026ULL: goto x86_l_fba;
	case 4029ULL: goto x86_l_fbd;
	case 4031ULL: goto x86_l_fbf;
	case 4035ULL: goto x86_l_fc3;
	case 4038ULL: goto x86_l_fc6;
	case 4044ULL: goto x86_l_fcc;
	case 4050ULL: goto x86_l_fd2;
	case 4056ULL: goto x86_l_fd8;
	case 4062ULL: goto x86_l_fde;
	case 4065ULL: goto x86_l_fe1;
	case 4067ULL: goto x86_l_fe3;
	case 4072ULL: goto x86_l_fe8;
	case 4074ULL: goto x86_l_fea;
	case 4077ULL: goto x86_l_fed;
	case 4081ULL: goto x86_l_ff1;
	case 4084ULL: goto x86_l_ff4;
	case 4087ULL: goto x86_l_ff7;
	case 4090ULL: goto x86_l_ffa;
	case 4095ULL: goto x86_l_fff;
	case 4097ULL: goto x86_l_1001;
	case 4102ULL: goto x86_l_1006;
	case 4105ULL: goto x86_l_1009;
	case 4111ULL: goto x86_l_100f;
	case 4117ULL: goto x86_l_1015;
	case 4125ULL: goto x86_l_101d;
	case 4130ULL: goto x86_l_1022;
	case 4135ULL: goto x86_l_1027;
	case 4140ULL: goto x86_l_102c;
	case 4145ULL: goto x86_l_1031;
	case 4149ULL: goto x86_l_1035;
	case 4154ULL: goto x86_l_103a;
	case 4160ULL: goto x86_l_1040;
	case 4164ULL: goto x86_l_1044;
	case 4166ULL: goto x86_l_1046;
	case 4170ULL: goto x86_l_104a;
	case 4176ULL: goto x86_l_1050;
	case 4181ULL: goto x86_l_1055;
	case 4186ULL: goto x86_l_105a;
	case 4191ULL: goto x86_l_105f;
	case 4196ULL: goto x86_l_1064;
	case 4204ULL: goto x86_l_106c;
	case 4209ULL: goto x86_l_1071;
	case 4214ULL: goto x86_l_1076;
	case 4218ULL: goto x86_l_107a;
	case 4226ULL: goto x86_l_1082;
	case 4232ULL: goto x86_l_1088;
	case 4236ULL: goto x86_l_108c;
	case 4239ULL: goto x86_l_108f;
	case 4245ULL: goto x86_l_1095;
	case 4250ULL: goto x86_l_109a;
	case 4255ULL: goto x86_l_109f;
	case 4260ULL: goto x86_l_10a4;
	case 4265ULL: goto x86_l_10a9;
	case 4270ULL: goto x86_l_10ae;
	case 4275ULL: goto x86_l_10b3;
	case 4280ULL: goto x86_l_10b8;
	case 4285ULL: goto x86_l_10bd;
	case 4290ULL: goto x86_l_10c2;
	case 4295ULL: goto x86_l_10c7;
	case 4303ULL: goto x86_l_10cf;
	case 4308ULL: goto x86_l_10d4;
	case 4310ULL: goto x86_l_10d6;
	case 4314ULL: goto x86_l_10da;
	case 4320ULL: goto x86_l_10e0;
	case 4324ULL: goto x86_l_10e4;
	case 4330ULL: goto x86_l_10ea;
	case 4335ULL: goto x86_l_10ef;
	case 4340ULL: goto x86_l_10f4;
	case 4345ULL: goto x86_l_10f9;
	case 4350ULL: goto x86_l_10fe;
	case 4355ULL: goto x86_l_1103;
	case 4363ULL: goto x86_l_110b;
	case 4368ULL: goto x86_l_1110;
	case 4370ULL: goto x86_l_1112;
	case 4375ULL: goto x86_l_1117;
	case 4380ULL: goto x86_l_111c;
	case 4384ULL: goto x86_l_1120;
	case 4390ULL: goto x86_l_1126;
	case 4394ULL: goto x86_l_112a;
	case 4399ULL: goto x86_l_112f;
	case 4405ULL: goto x86_l_1135;
	case 4410ULL: goto x86_l_113a;
	case 4418ULL: goto x86_l_1142;
	case 4426ULL: goto x86_l_114a;
	case 4434ULL: goto x86_l_1152;
	case 4442ULL: goto x86_l_115a;
	case 4447ULL: goto x86_l_115f;
	case 4452ULL: goto x86_l_1164;
	case 4455ULL: goto x86_l_1167;
	case 4460ULL: goto x86_l_116c;
	case 4463ULL: goto x86_l_116f;
	case 4465ULL: goto x86_l_1171;
	case 4470ULL: goto x86_l_1176;
	case 4473ULL: goto x86_l_1179;
	case 4479ULL: goto x86_l_117f;
	case 4483ULL: goto x86_l_1183;
	case 4486ULL: goto x86_l_1186;
	case 4492ULL: goto x86_l_118c;
	case 4495ULL: goto x86_l_118f;
	case 4501ULL: goto x86_l_1195;
	case 4505ULL: goto x86_l_1199;
	case 4510ULL: goto x86_l_119e;
	case 4515ULL: goto x86_l_11a3;
	case 4520ULL: goto x86_l_11a8;
	case 4525ULL: goto x86_l_11ad;
	case 4527ULL: goto x86_l_11af;
	case 4531ULL: goto x86_l_11b3;
	case 4536ULL: goto x86_l_11b8;
	case 4543ULL: goto x86_l_11bf;
	case 4550ULL: goto x86_l_11c6;
	case 4554ULL: goto x86_l_11ca;
	case 4559ULL: goto x86_l_11cf;
	case 4564ULL: goto x86_l_11d4;
	case 4569ULL: goto x86_l_11d9;
	case 4573ULL: goto x86_l_11dd;
	case 4579ULL: goto x86_l_11e3;
	case 4582ULL: goto x86_l_11e6;
	case 4586ULL: goto x86_l_11ea;
	case 4592ULL: goto x86_l_11f0;
	case 4596ULL: goto x86_l_11f4;
	case 4601ULL: goto x86_l_11f9;
	case 4607ULL: goto x86_l_11ff;
	case 4619ULL: goto x86_l_120b;
	case 4624ULL: goto x86_l_1210;
	case 4629ULL: goto x86_l_1215;
	case 4633ULL: goto x86_l_1219;
	case 4638ULL: goto x86_l_121e;
	case 4644ULL: goto x86_l_1224;
	case 4649ULL: goto x86_l_1229;
	case 4652ULL: goto x86_l_122c;
	case 4660ULL: goto x86_l_1234;
	case 4663ULL: goto x86_l_1237;
	case 4669ULL: goto x86_l_123d;
	case 4672ULL: goto x86_l_1240;
	case 4679ULL: goto x86_l_1247;
	case 4681ULL: goto x86_l_1249;
	case 4686ULL: goto x86_l_124e;
	case 4688ULL: goto x86_l_1250;
	case 4691ULL: goto x86_l_1253;
	case 4694ULL: goto x86_l_1256;
	case 4700ULL: goto x86_l_125c;
	case 4705ULL: goto x86_l_1261;
	case 4709ULL: goto x86_l_1265;
	case 4715ULL: goto x86_l_126b;
	case 4719ULL: goto x86_l_126f;
	case 4724ULL: goto x86_l_1274;
	case 4730ULL: goto x86_l_127a;
	case 4733ULL: goto x86_l_127d;
	case 4737ULL: goto x86_l_1281;
	case 4742ULL: goto x86_l_1286;
	case 4748ULL: goto x86_l_128c;
	case 4753ULL: goto x86_l_1291;
	case 4758ULL: goto x86_l_1296;
	case 4763ULL: goto x86_l_129b;
	case 4765ULL: goto x86_l_129d;
	case 4770ULL: goto x86_l_12a2;
	case 4775ULL: goto x86_l_12a7;
	case 4778ULL: goto x86_l_12aa;
	case 4784ULL: goto x86_l_12b0;
	case 4791ULL: goto x86_l_12b7;
	case 4798ULL: goto x86_l_12be;
	case 4802ULL: goto x86_l_12c2;
	case 4807ULL: goto x86_l_12c7;
	case 4810ULL: goto x86_l_12ca;
	case 4815ULL: goto x86_l_12cf;
	case 4820ULL: goto x86_l_12d4;
	case 4822ULL: goto x86_l_12d6;
	case 4830ULL: goto x86_l_12de;
	case 4834ULL: goto x86_l_12e2;
	case 4839ULL: goto x86_l_12e7;
	case 4844ULL: goto x86_l_12ec;
	case 4849ULL: goto x86_l_12f1;
	case 4851ULL: goto x86_l_12f3;
	case 4859ULL: goto x86_l_12fb;
	case 4866ULL: goto x86_l_1302;
	case 4871ULL: goto x86_l_1307;
	case 4876ULL: goto x86_l_130c;
	case 4881ULL: goto x86_l_1311;
	case 4883ULL: goto x86_l_1313;
	case 4891ULL: goto x86_l_131b;
	case 4898ULL: goto x86_l_1322;
	case 4903ULL: goto x86_l_1327;
	case 4908ULL: goto x86_l_132c;
	case 4913ULL: goto x86_l_1331;
	case 4915ULL: goto x86_l_1333;
	case 4923ULL: goto x86_l_133b;
	case 4930ULL: goto x86_l_1342;
	case 4935ULL: goto x86_l_1347;
	case 4940ULL: goto x86_l_134c;
	case 4942ULL: goto x86_l_134e;
	case 4950ULL: goto x86_l_1356;
	case 4957ULL: goto x86_l_135d;
	case 4962ULL: goto x86_l_1362;
	case 4967ULL: goto x86_l_1367;
	case 4969ULL: goto x86_l_1369;
	case 4977ULL: goto x86_l_1371;
	case 4980ULL: goto x86_l_1374;
	case 4988ULL: goto x86_l_137c;
	case 4996ULL: goto x86_l_1384;
	case 5004ULL: goto x86_l_138c;
	case 5012ULL: goto x86_l_1394;
	case 5021ULL: goto x86_l_139d;
	case 5024ULL: goto x86_l_13a0;
	case 5030ULL: goto x86_l_13a6;
	case 5033ULL: goto x86_l_13a9;
	case 5039ULL: goto x86_l_13af;
	case 5043ULL: goto x86_l_13b3;
	case 5048ULL: goto x86_l_13b8;
	case 5053ULL: goto x86_l_13bd;
	case 5056ULL: goto x86_l_13c0;
	case 5061ULL: goto x86_l_13c5;
	case 5063ULL: goto x86_l_13c7;
	case 5068ULL: goto x86_l_13cc;
	case 5073ULL: goto x86_l_13d1;
	case 5076ULL: goto x86_l_13d4;
	case 5081ULL: goto x86_l_13d9;
	case 5084ULL: goto x86_l_13dc;
	case 5089ULL: goto x86_l_13e1;
	case 5093ULL: goto x86_l_13e5;
	case 5099ULL: goto x86_l_13eb;
	case 5103ULL: goto x86_l_13ef;
	case 5108ULL: goto x86_l_13f4;
	case 5114ULL: goto x86_l_13fa;
	case 5117ULL: goto x86_l_13fd;
	case 5125ULL: goto x86_l_1405;
	case 5133ULL: goto x86_l_140d;
	case 5141ULL: goto x86_l_1415;
	case 5149ULL: goto x86_l_141d;
	case 5157ULL: goto x86_l_1425;
	case 5165ULL: goto x86_l_142d;
	case 5173ULL: goto x86_l_1435;
	case 5181ULL: goto x86_l_143d;
	case 5189ULL: goto x86_l_1445;
	case 5196ULL: goto x86_l_144c;
	case 5203ULL: goto x86_l_1453;
	case 5207ULL: goto x86_l_1457;
	case 5212ULL: goto x86_l_145c;
	case 5217ULL: goto x86_l_1461;
	case 5222ULL: goto x86_l_1466;
	case 5224ULL: goto x86_l_1468;
	case 5227ULL: goto x86_l_146b;
	case 5233ULL: goto x86_l_1471;
	case 5238ULL: goto x86_l_1476;
	case 5241ULL: goto x86_l_1479;
	case 5248ULL: goto x86_l_1480;
	case 5253ULL: goto x86_l_1485;
	case 5260ULL: goto x86_l_148c;
	case 5265ULL: goto x86_l_1491;
	case 5270ULL: goto x86_l_1496;
	case 5275ULL: goto x86_l_149b;
	case 5277ULL: goto x86_l_149d;
	case 5280ULL: goto x86_l_14a0;
	case 5283ULL: goto x86_l_14a3;
	case 5288ULL: goto x86_l_14a8;
	case 5291ULL: goto x86_l_14ab;
	case 5296ULL: goto x86_l_14b0;
	case 5300ULL: goto x86_l_14b4;
	case 5305ULL: goto x86_l_14b9;
	case 5310ULL: goto x86_l_14be;
	case 5315ULL: goto x86_l_14c3;
	case 5320ULL: goto x86_l_14c8;
	case 5322ULL: goto x86_l_14ca;
	case 5327ULL: goto x86_l_14cf;
	case 5332ULL: goto x86_l_14d4;
	case 5338ULL: goto x86_l_14da;
	case 5342ULL: goto x86_l_14de;
	case 5347ULL: goto x86_l_14e3;
	case 5352ULL: goto x86_l_14e8;
	case 5355ULL: goto x86_l_14eb;
	case 5360ULL: goto x86_l_14f0;
	case 5363ULL: goto x86_l_14f3;
	case 5365ULL: goto x86_l_14f5;
	case 5370ULL: goto x86_l_14fa;
	case 5375ULL: goto x86_l_14ff;
	case 5379ULL: goto x86_l_1503;
	case 5384ULL: goto x86_l_1508;
	case 5389ULL: goto x86_l_150d;
	case 5394ULL: goto x86_l_1512;
	case 5396ULL: goto x86_l_1514;
	case 5401ULL: goto x86_l_1519;
	case 5407ULL: goto x86_l_151f;
	case 5415ULL: goto x86_l_1527;
	case 5420ULL: goto x86_l_152c;
	case 5425ULL: goto x86_l_1531;
	case 5430ULL: goto x86_l_1536;
	case 5432ULL: goto x86_l_1538;
	case 5440ULL: goto x86_l_1540;
	case 5446ULL: goto x86_l_1546;
	case 5451ULL: goto x86_l_154b;
	case 5456ULL: goto x86_l_1550;
	case 5461ULL: goto x86_l_1555;
	case 5466ULL: goto x86_l_155a;
	case 5471ULL: goto x86_l_155f;
	case 5474ULL: goto x86_l_1562;
	case 5476ULL: goto x86_l_1564;
	case 5481ULL: goto x86_l_1569;
	case 5487ULL: goto x86_l_156f;
	case 5495ULL: goto x86_l_1577;
	case 5500ULL: goto x86_l_157c;
	case 5505ULL: goto x86_l_1581;
	case 5510ULL: goto x86_l_1586;
	case 5513ULL: goto x86_l_1589;
	case 5515ULL: goto x86_l_158b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e53:
	/* 0xe53: jg     111c <generic_retkprobe_event+0x111c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_111c;
	}
x86_l_e59:
	/* 0xe59: lea    eax,[r14-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_e5d:
	/* 0xe5d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e60:
	/* 0xe60: jae    1215 <generic_retkprobe_event+0x1215> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1215;
	}
x86_l_e66:
	/* 0xe66: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e6b:
	/* 0xe6b: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_e70:
	/* 0xe70: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e75:
	/* 0xe75: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e7a:
	/* 0xe7a: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_e82:
	/* 0xe82: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_e87:
	/* 0xe87: jmp    1110 <generic_retkprobe_event+0x1110> */
	goto x86_l_1110;
x86_l_e8c:
	/* 0xe8c: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e90:
	/* 0xe90: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e95:
	/* 0xe95: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e9a:
	/* 0xe9a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e9f:
	/* 0xe9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ea4:
	/* 0xea4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea6:
	/* 0xea6: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_eab:
	/* 0xeab: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_eb0:
	/* 0xeb0: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_eb6:
	/* 0xeb6: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_eba:
	/* 0xeba: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ebf:
	/* 0xebf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ec4:
	/* 0xec4: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_ec7:
	/* 0xec7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ecc:
	/* 0xecc: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_ecf:
	/* 0xecf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed1:
	/* 0xed1: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ed6:
	/* 0xed6: mov    QWORD PTR [rsp+0x50],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_edb:
	/* 0xedb: lea    rdx,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_edf:
	/* 0xedf: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_ee4:
	/* 0xee4: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ee9:
	/* 0xee9: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_eee:
	/* 0xeee: jne    efb <generic_retkprobe_event+0xefb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_efb;
	}
x86_l_ef0:
	/* 0xef0: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_ef5:
	/* 0xef5: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_efb:
	/* 0xefb: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_f03:
	/* 0xf03: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f08:
	/* 0xf08: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f0d:
	/* 0xf0d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f12:
	/* 0xf12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f14:
	/* 0xf14: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_f1c:
	/* 0xf1c: je     14b0 <generic_retkprobe_event+0x14b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14b0;
	}
x86_l_f22:
	/* 0xf22: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f27:
	/* 0xf27: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f2c:
	/* 0xf2c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f31:
	/* 0xf31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f36:
	/* 0xf36: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f3b:
	/* 0xf3b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_f3e:
	/* 0xf3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f40:
	/* 0xf40: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f45:
	/* 0xf45: je     14b0 <generic_retkprobe_event+0x14b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14b0;
	}
x86_l_f4b:
	/* 0xf4b: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_f53:
	/* 0xf53: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f58:
	/* 0xf58: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f5d:
	/* 0xf5d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f62:
	/* 0xf62: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_f65:
	/* 0xf65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f67:
	/* 0xf67: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_f6b:
	/* 0xf6b: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_f70:
	/* 0xf70: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_f75:
	/* 0xf75: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f7a:
	/* 0xf7a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_f7f:
	/* 0xf7f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_f82:
	/* 0xf82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f84:
	/* 0xf84: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f89:
	/* 0xf89: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_f8e:
	/* 0xf8e: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_f92:
	/* 0xf92: sub    rax,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_f95:
	/* 0xf95: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f9a:
	/* 0xf9a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f9c:
	/* 0xf9c: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_f9e:
	/* 0xf9e: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_fa1:
	/* 0xfa1: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_fa4:
	/* 0xfa4: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_fa9:
	/* 0xfa9: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fab:
	/* 0xfab: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_fae:
	/* 0xfae: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_fb2:
	/* 0xfb2: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_fb4:
	/* 0xfb4: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_fb8:
	/* 0xfb8: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fba:
	/* 0xfba: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_fbd:
	/* 0xfbd: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_fbf:
	/* 0xfbf: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_fc3:
	/* 0xfc3: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_fc6:
	/* 0xfc6: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_fcc:
	/* 0xfcc: jb     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1821ULL;
	}
x86_l_fd2:
	/* 0xfd2: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_fd8:
	/* 0xfd8: ja     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1821ULL;
	}
x86_l_fde:
	/* 0xfde: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_fe1:
	/* 0xfe1: jbe    fe8 <generic_retkprobe_event+0xfe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_fe8;
	}
x86_l_fe3:
	/* 0xfe3: mov    BYTE PTR [r14+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_fe8:
	/* 0xfe8: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fea:
	/* 0xfea: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_fed:
	/* 0xfed: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_ff1:
	/* 0xff1: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ff4:
	/* 0xff4: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ff7:
	/* 0xff7: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ffa:
	/* 0xffa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fff:
	/* 0xfff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1001:
	/* 0x1001: mov    QWORD PTR [rsp+0x58],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1006:
	/* 0x1006: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1009:
	/* 0x1009: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_100f:
	/* 0x100f: jbe    71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1821ULL;
	}
x86_l_1015:
	/* 0x1015: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_101d:
	/* 0x101d: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1022:
	/* 0x1022: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1027:
	/* 0x1027: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_102c:
	/* 0x102c: jmp    150d <generic_retkprobe_event+0x150d> */
	goto x86_l_150d;
x86_l_1031:
	/* 0x1031: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_1035:
	/* 0x1035: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_103a:
	/* 0x103a: jg     10d6 <generic_retkprobe_event+0x10d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_10d6;
	}
x86_l_1040:
	/* 0x1040: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_1044:
	/* 0x1044: je     10b3 <generic_retkprobe_event+0x10b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b3;
	}
x86_l_1046:
	/* 0x1046: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_104a:
	/* 0x104a: jne    953 <generic_retkprobe_event+0x953> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2387ULL;
	}
x86_l_1050:
	/* 0x1050: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_1055:
	/* 0x1055: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_105a:
	/* 0x105a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_105f:
	/* 0x105f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1064:
	/* 0x1064: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_106c:
	/* 0x106c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1071:
	/* 0x1071: jmp    1110 <generic_retkprobe_event+0x1110> */
	goto x86_l_1110;
x86_l_1076:
	/* 0x1076: cmp    r14d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 32ULL);
x86_l_107a:
	/* 0x107a: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1082:
	/* 0x1082: jle    13e1 <generic_retkprobe_event+0x13e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_13e1;
	}
x86_l_1088:
	/* 0x1088: lea    eax,[r14-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_108c:
	/* 0x108c: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_108f:
	/* 0x108f: jae    1261 <generic_retkprobe_event+0x1261> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1261;
	}
x86_l_1095:
	/* 0x1095: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_109a:
	/* 0x109a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_109f:
	/* 0x109f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10a4:
	/* 0x10a4: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10a9:
	/* 0x10a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10ae:
	/* 0x10ae: jmp    1681 <generic_retkprobe_event+0x1681> */
	return 5761ULL;
x86_l_10b3:
	/* 0x10b3: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10b8:
	/* 0x10b8: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_10bd:
	/* 0x10bd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10c2:
	/* 0x10c2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10c7:
	/* 0x10c7: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_10cf:
	/* 0x10cf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10d4:
	/* 0x10d4: jmp    1110 <generic_retkprobe_event+0x1110> */
	goto x86_l_1110;
x86_l_10d6:
	/* 0x10d6: cmp    r14d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 5ULL);
x86_l_10da:
	/* 0x10da: je     1778 <generic_retkprobe_event+0x1778> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6008ULL;
	}
x86_l_10e0:
	/* 0x10e0: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_10e4:
	/* 0x10e4: je     1a68 <generic_retkprobe_event+0x1a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6760ULL;
	}
x86_l_10ea:
	/* 0x10ea: jmp    953 <generic_retkprobe_event+0x953> */
	return 2387ULL;
x86_l_10ef:
	/* 0x10ef: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10f4:
	/* 0x10f4: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_10f9:
	/* 0x10f9: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_10fe:
	/* 0x10fe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1103:
	/* 0x1103: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_110b:
	/* 0x110b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1110:
	/* 0x1110: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1112:
	/* 0x1112: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1117:
	/* 0x1117: jmp    953 <generic_retkprobe_event+0x953> */
	return 2387ULL;
x86_l_111c:
	/* 0x111c: cmp    r14d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 39ULL);
x86_l_1120:
	/* 0x1120: je     1aab <generic_retkprobe_event+0x1aab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6827ULL;
	}
x86_l_1126:
	/* 0x1126: cmp    r14d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 40ULL);
x86_l_112a:
	/* 0x112a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_112f:
	/* 0x112f: jne    953 <generic_retkprobe_event+0x953> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2387ULL;
	}
x86_l_1135:
	/* 0x1135: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_113a:
	/* 0x113a: mov    rbp,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1142:
	/* 0x1142: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_114a:
	/* 0x114a: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1152:
	/* 0x1152: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_115a:
	/* 0x115a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_115f:
	/* 0x115f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1164:
	/* 0x1164: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1167:
	/* 0x1167: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_116c:
	/* 0x116c: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_116f:
	/* 0x116f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1171:
	/* 0x1171: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1176:
	/* 0x1176: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1179:
	/* 0x1179: js     24fe <generic_retkprobe_event+0x24fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9470ULL;
	}
x86_l_117f:
	/* 0x117f: movzx  eax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1183:
	/* 0x1183: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1186:
	/* 0x1186: je     24a2 <generic_retkprobe_event+0x24a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9378ULL;
	}
x86_l_118c:
	/* 0x118c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_118f:
	/* 0x118f: jne    24e9 <generic_retkprobe_event+0x24e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9449ULL;
	}
x86_l_1195:
	/* 0x1195: lea    rdx,[r14+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1199:
	/* 0x1199: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_119e:
	/* 0x119e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_11a3:
	/* 0x11a3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11a8:
	/* 0x11a8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11ad:
	/* 0x11ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11af:
	/* 0x11af: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11b3:
	/* 0x11b3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11b8:
	/* 0x11b8: mov    QWORD PTR [rdi+0xa4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_11bf:
	/* 0x11bf: add    rdi,0x9e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 158ULL);
x86_l_11c6:
	/* 0x11c6: add    r14,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_11ca:
	/* 0x11ca: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_11cf:
	/* 0x11cf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11d4:
	/* 0x11d4: jmp    24df <generic_retkprobe_event+0x24df> */
	return 9439ULL;
x86_l_11d9:
	/* 0x11d9: cmp    r14d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 7ULL);
x86_l_11dd:
	/* 0x11dd: jg     165f <generic_retkprobe_event+0x165f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5727ULL;
	}
x86_l_11e3:
	/* 0x11e3: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_11e6:
	/* 0x11e6: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_11ea:
	/* 0x11ea: je     1bbe <generic_retkprobe_event+0x1bbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7102ULL;
	}
x86_l_11f0:
	/* 0x11f0: cmp    r14d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 3ULL);
x86_l_11f4:
	/* 0x11f4: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11f9:
	/* 0x11f9: jne    2674 <generic_retkprobe_event+0x2674> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9844ULL;
	}
x86_l_11ff:
	/* 0x11ff: mov    QWORD PTR [r12+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_120b:
	/* 0x120b: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_1210:
	/* 0x1210: jmp    2674 <generic_retkprobe_event+0x2674> */
	return 9844ULL;
x86_l_1215:
	/* 0x1215: cmp    r14d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 38ULL);
x86_l_1219:
	/* 0x1219: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_121e:
	/* 0x121e: jne    953 <generic_retkprobe_event+0x953> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2387ULL;
	}
x86_l_1224:
	/* 0x1224: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1229:
	/* 0x1229: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_122c:
	/* 0x122c: add    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 232ULL);
x86_l_1234:
	/* 0x1234: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1237:
	/* 0x1237: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_123d:
	/* 0x123d: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_1240:
	/* 0x1240: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_1247:
	/* 0x1247: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1249:
	/* 0x1249: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_124e:
	/* 0x124e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1250:
	/* 0x1250: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1253:
	/* 0x1253: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1256:
	/* 0x1256: jns    1a90 <generic_retkprobe_event+0x1a90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 6800ULL;
	}
x86_l_125c:
	/* 0x125c: jmp    1ada <generic_retkprobe_event+0x1ada> */
	return 6874ULL;
x86_l_1261:
	/* 0x1261: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_1265:
	/* 0x1265: je     2055 <generic_retkprobe_event+0x2055> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8277ULL;
	}
x86_l_126b:
	/* 0x126b: cmp    r14d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 41ULL);
x86_l_126f:
	/* 0x126f: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1274:
	/* 0x1274: jne    2674 <generic_retkprobe_event+0x2674> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9844ULL;
	}
x86_l_127a:
	/* 0x127a: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_127d:
	/* 0x127d: lea    rdx,[r14+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1281:
	/* 0x1281: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1286:
	/* 0x1286: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_128c:
	/* 0x128c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1291:
	/* 0x1291: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1296:
	/* 0x1296: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_129b:
	/* 0x129b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_129d:
	/* 0x129d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12a2:
	/* 0x12a2: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12a7:
	/* 0x12a7: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_12aa:
	/* 0x12aa: je     2664 <generic_retkprobe_event+0x2664> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9828ULL;
	}
x86_l_12b0:
	/* 0x12b0: mov    QWORD PTR [rcx+0xc4],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_12b7:
	/* 0x12b7: lea    rdi,[rcx+0xc2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_12be:
	/* 0x12be: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12c2:
	/* 0x12c2: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_12c7:
	/* 0x12c7: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_12ca:
	/* 0x12ca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12cf:
	/* 0x12cf: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_12d4:
	/* 0x12d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d6:
	/* 0x12d6: lea    rdi,[r12+0xd6] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_12de:
	/* 0x12de: lea    rdx,[rbp+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_12e2:
	/* 0x12e2: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_12e7:
	/* 0x12e7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12ec:
	/* 0x12ec: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_12f1:
	/* 0x12f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f3:
	/* 0x12f3: lea    rdi,[r12+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_12fb:
	/* 0x12fb: lea    rdx,[rbp+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_1302:
	/* 0x1302: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1307:
	/* 0x1307: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_130c:
	/* 0x130c: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1311:
	/* 0x1311: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1313:
	/* 0x1313: lea    rdi,[r12+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_131b:
	/* 0x131b: lea    rdx,[rbp+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_1322:
	/* 0x1322: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1327:
	/* 0x1327: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_132c:
	/* 0x132c: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1331:
	/* 0x1331: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1333:
	/* 0x1333: lea    rdi,[r12+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_133b:
	/* 0x133b: lea    rdx,[rbp+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_1342:
	/* 0x1342: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1347:
	/* 0x1347: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_134c:
	/* 0x134c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_134e:
	/* 0x134e: lea    rdi,[r12+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1356:
	/* 0x1356: lea    rdx,[rbp+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_135d:
	/* 0x135d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1362:
	/* 0x1362: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1367:
	/* 0x1367: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1369:
	/* 0x1369: lea    r14,[r12+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1371:
	/* 0x1371: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_1374:
	/* 0x1374: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_137c:
	/* 0x137c: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1384:
	/* 0x1384: mov    QWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_138c:
	/* 0x138c: mov    QWORD PTR [r13+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1394:
	/* 0x1394: movzx  eax,WORD PTR [r12+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_139d:
	/* 0x139d: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_13a0:
	/* 0x13a0: je     25d6 <generic_retkprobe_event+0x25d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9686ULL;
	}
x86_l_13a6:
	/* 0x13a6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13a9:
	/* 0x13a9: jne    2606 <generic_retkprobe_event+0x2606> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9734ULL;
	}
x86_l_13af:
	/* 0x13af: lea    rdx,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13b3:
	/* 0x13b3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_13b8:
	/* 0x13b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13bd:
	/* 0x13bd: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_13c0:
	/* 0x13c0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13c5:
	/* 0x13c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13c7:
	/* 0x13c7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_13cc:
	/* 0x13cc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13d1:
	/* 0x13d1: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_13d4:
	/* 0x13d4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13d9:
	/* 0x13d9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_13dc:
	/* 0x13dc: jmp    2604 <generic_retkprobe_event+0x2604> */
	return 9732ULL;
x86_l_13e1:
	/* 0x13e1: cmp    r14d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 26ULL);
x86_l_13e5:
	/* 0x13e5: je     2104 <generic_retkprobe_event+0x2104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8452ULL;
	}
x86_l_13eb:
	/* 0x13eb: cmp    r14d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 27ULL);
x86_l_13ef:
	/* 0x13ef: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13f4:
	/* 0x13f4: jne    2674 <generic_retkprobe_event+0x2674> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9844ULL;
	}
x86_l_13fa:
	/* 0x13fa: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_13fd:
	/* 0x13fd: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1405:
	/* 0x1405: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_140d:
	/* 0x140d: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1415:
	/* 0x1415: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_141d:
	/* 0x141d: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1425:
	/* 0x1425: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_142d:
	/* 0x142d: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1435:
	/* 0x1435: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_143d:
	/* 0x143d: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1445:
	/* 0x1445: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_144c:
	/* 0x144c: lea    rdi,[rcx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1453:
	/* 0x1453: lea    rdx,[r14+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1457:
	/* 0x1457: mov    ecx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 63ULL);
x86_l_145c:
	/* 0x145c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1461:
	/* 0x1461: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_1466:
	/* 0x1466: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1468:
	/* 0x1468: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_146b:
	/* 0x146b: js     25c2 <generic_retkprobe_event+0x25c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9666ULL;
	}
x86_l_1471:
	/* 0x1471: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1476:
	/* 0x1476: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1479:
	/* 0x1479: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1480:
	/* 0x1480: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1485:
	/* 0x1485: lea    rdx,[r15+0x348] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 840ULL);
x86_l_148c:
	/* 0x148c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1491:
	/* 0x1491: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1496:
	/* 0x1496: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_149b:
	/* 0x149b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_149d:
	/* 0x149d: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_14a0:
	/* 0x14a0: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_14a3:
	/* 0x14a3: mov    ebp,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 80ULL);
x86_l_14a8:
	/* 0x14a8: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_14ab:
	/* 0x14ab: jmp    2674 <generic_retkprobe_event+0x2674> */
	return 9844ULL;
x86_l_14b0:
	/* 0x14b0: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14b4:
	/* 0x14b4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14b9:
	/* 0x14b9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14be:
	/* 0x14be: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14c3:
	/* 0x14c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14c8:
	/* 0x14c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14ca:
	/* 0x14ca: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14cf:
	/* 0x14cf: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_14d4:
	/* 0x14d4: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_14da:
	/* 0x14da: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_14de:
	/* 0x14de: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14e3:
	/* 0x14e3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14e8:
	/* 0x14e8: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_14eb:
	/* 0x14eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14f0:
	/* 0x14f0: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_14f3:
	/* 0x14f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14f5:
	/* 0x14f5: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14fa:
	/* 0x14fa: mov    QWORD PTR [rsp+0x50],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14ff:
	/* 0x14ff: lea    rdx,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1503:
	/* 0x1503: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1508:
	/* 0x1508: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_150d:
	/* 0x150d: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1512:
	/* 0x1512: jne    151f <generic_retkprobe_event+0x151f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_151f;
	}
x86_l_1514:
	/* 0x1514: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_1519:
	/* 0x1519: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_151f:
	/* 0x151f: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1527:
	/* 0x1527: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_152c:
	/* 0x152c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1531:
	/* 0x1531: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1536:
	/* 0x1536: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1538:
	/* 0x1538: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_1540:
	/* 0x1540: je     22e7 <generic_retkprobe_event+0x22e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8935ULL;
	}
x86_l_1546:
	/* 0x1546: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_154b:
	/* 0x154b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1550:
	/* 0x1550: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1555:
	/* 0x1555: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_155a:
	/* 0x155a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_155f:
	/* 0x155f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1562:
	/* 0x1562: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1564:
	/* 0x1564: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1569:
	/* 0x1569: je     22e7 <generic_retkprobe_event+0x22e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8935ULL;
	}
x86_l_156f:
	/* 0x156f: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1577:
	/* 0x1577: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_157c:
	/* 0x157c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1581:
	/* 0x1581: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1586:
	/* 0x1586: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1589:
	/* 0x1589: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_158b:
	/* 0x158b: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
	return 5519ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5519ULL: goto x86_l_158f;
	case 5524ULL: goto x86_l_1594;
	case 5529ULL: goto x86_l_1599;
	case 5534ULL: goto x86_l_159e;
	case 5539ULL: goto x86_l_15a3;
	case 5542ULL: goto x86_l_15a6;
	case 5544ULL: goto x86_l_15a8;
	case 5549ULL: goto x86_l_15ad;
	case 5554ULL: goto x86_l_15b2;
	case 5558ULL: goto x86_l_15b6;
	case 5561ULL: goto x86_l_15b9;
	case 5566ULL: goto x86_l_15be;
	case 5568ULL: goto x86_l_15c0;
	case 5570ULL: goto x86_l_15c2;
	case 5573ULL: goto x86_l_15c5;
	case 5576ULL: goto x86_l_15c8;
	case 5581ULL: goto x86_l_15cd;
	case 5583ULL: goto x86_l_15cf;
	case 5586ULL: goto x86_l_15d2;
	case 5590ULL: goto x86_l_15d6;
	case 5592ULL: goto x86_l_15d8;
	case 5596ULL: goto x86_l_15dc;
	case 5598ULL: goto x86_l_15de;
	case 5601ULL: goto x86_l_15e1;
	case 5603ULL: goto x86_l_15e3;
	case 5607ULL: goto x86_l_15e7;
	case 5610ULL: goto x86_l_15ea;
	case 5616ULL: goto x86_l_15f0;
	case 5622ULL: goto x86_l_15f6;
	case 5628ULL: goto x86_l_15fc;
	case 5634ULL: goto x86_l_1602;
	case 5639ULL: goto x86_l_1607;
	case 5642ULL: goto x86_l_160a;
	case 5644ULL: goto x86_l_160c;
	case 5649ULL: goto x86_l_1611;
	case 5651ULL: goto x86_l_1613;
	case 5654ULL: goto x86_l_1616;
	case 5658ULL: goto x86_l_161a;
	case 5661ULL: goto x86_l_161d;
	case 5664ULL: goto x86_l_1620;
	case 5667ULL: goto x86_l_1623;
	case 5672ULL: goto x86_l_1628;
	case 5674ULL: goto x86_l_162a;
	case 5679ULL: goto x86_l_162f;
	case 5682ULL: goto x86_l_1632;
	case 5687ULL: goto x86_l_1637;
	case 5693ULL: goto x86_l_163d;
	case 5699ULL: goto x86_l_1643;
	case 5707ULL: goto x86_l_164b;
	case 5712ULL: goto x86_l_1650;
	case 5717ULL: goto x86_l_1655;
	case 5722ULL: goto x86_l_165a;
	case 5727ULL: goto x86_l_165f;
	case 5731ULL: goto x86_l_1663;
	case 5737ULL: goto x86_l_1669;
	case 5741ULL: goto x86_l_166d;
	case 5746ULL: goto x86_l_1672;
	case 5752ULL: goto x86_l_1678;
	case 5754ULL: goto x86_l_167a;
	case 5759ULL: goto x86_l_167f;
	case 5761ULL: goto x86_l_1681;
	case 5764ULL: goto x86_l_1684;
	case 5766ULL: goto x86_l_1686;
	case 5771ULL: goto x86_l_168b;
	case 5776ULL: goto x86_l_1690;
	case 5780ULL: goto x86_l_1694;
	case 5786ULL: goto x86_l_169a;
	case 5790ULL: goto x86_l_169e;
	case 5795ULL: goto x86_l_16a3;
	case 5801ULL: goto x86_l_16a9;
	case 5810ULL: goto x86_l_16b2;
	case 5813ULL: goto x86_l_16b5;
	case 5820ULL: goto x86_l_16bc;
	case 5825ULL: goto x86_l_16c1;
	case 5830ULL: goto x86_l_16c6;
	case 5835ULL: goto x86_l_16cb;
	case 5840ULL: goto x86_l_16d0;
	case 5847ULL: goto x86_l_16d7;
	case 5852ULL: goto x86_l_16dc;
	case 5854ULL: goto x86_l_16de;
	case 5859ULL: goto x86_l_16e3;
	case 5864ULL: goto x86_l_16e8;
	case 5869ULL: goto x86_l_16ed;
	case 5874ULL: goto x86_l_16f2;
	case 5877ULL: goto x86_l_16f5;
	case 5882ULL: goto x86_l_16fa;
	case 5884ULL: goto x86_l_16fc;
	case 5889ULL: goto x86_l_1701;
	case 5896ULL: goto x86_l_1708;
	case 5901ULL: goto x86_l_170d;
	case 5906ULL: goto x86_l_1712;
	case 5911ULL: goto x86_l_1717;
	case 5914ULL: goto x86_l_171a;
	case 5919ULL: goto x86_l_171f;
	case 5921ULL: goto x86_l_1721;
	case 5926ULL: goto x86_l_1726;
	case 5933ULL: goto x86_l_172d;
	case 5940ULL: goto x86_l_1734;
	case 5945ULL: goto x86_l_1739;
	case 5950ULL: goto x86_l_173e;
	case 5955ULL: goto x86_l_1743;
	case 5957ULL: goto x86_l_1745;
	case 5962ULL: goto x86_l_174a;
	case 5969ULL: goto x86_l_1751;
	case 5976ULL: goto x86_l_1758;
	case 5981ULL: goto x86_l_175d;
	case 5986ULL: goto x86_l_1762;
	case 5991ULL: goto x86_l_1767;
	case 5993ULL: goto x86_l_1769;
	case 5998ULL: goto x86_l_176e;
	case 6003ULL: goto x86_l_1773;
	case 6008ULL: goto x86_l_1778;
	case 6013ULL: goto x86_l_177d;
	case 6020ULL: goto x86_l_1784;
	case 6027ULL: goto x86_l_178b;
	case 6032ULL: goto x86_l_1790;
	case 6035ULL: goto x86_l_1793;
	case 6040ULL: goto x86_l_1798;
	case 6045ULL: goto x86_l_179d;
	case 6047ULL: goto x86_l_179f;
	case 6054ULL: goto x86_l_17a6;
	case 6058ULL: goto x86_l_17aa;
	case 6063ULL: goto x86_l_17af;
	case 6068ULL: goto x86_l_17b4;
	case 6073ULL: goto x86_l_17b9;
	case 6075ULL: goto x86_l_17bb;
	case 6082ULL: goto x86_l_17c2;
	case 6089ULL: goto x86_l_17c9;
	case 6094ULL: goto x86_l_17ce;
	case 6099ULL: goto x86_l_17d3;
	case 6104ULL: goto x86_l_17d8;
	case 6106ULL: goto x86_l_17da;
	case 6113ULL: goto x86_l_17e1;
	case 6120ULL: goto x86_l_17e8;
	case 6125ULL: goto x86_l_17ed;
	case 6130ULL: goto x86_l_17f2;
	case 6135ULL: goto x86_l_17f7;
	case 6137ULL: goto x86_l_17f9;
	case 6146ULL: goto x86_l_1802;
	case 6153ULL: goto x86_l_1809;
	case 6158ULL: goto x86_l_180e;
	case 6163ULL: goto x86_l_1813;
	case 6168ULL: goto x86_l_1818;
	case 6173ULL: goto x86_l_181d;
	case 6175ULL: goto x86_l_181f;
	case 6182ULL: goto x86_l_1826;
	case 6190ULL: goto x86_l_182e;
	case 6195ULL: goto x86_l_1833;
	case 6200ULL: goto x86_l_1838;
	case 6205ULL: goto x86_l_183d;
	case 6207ULL: goto x86_l_183f;
	case 6216ULL: goto x86_l_1848;
	case 6221ULL: goto x86_l_184d;
	case 6229ULL: goto x86_l_1855;
	case 6234ULL: goto x86_l_185a;
	case 6239ULL: goto x86_l_185f;
	case 6244ULL: goto x86_l_1864;
	case 6247ULL: goto x86_l_1867;
	case 6249ULL: goto x86_l_1869;
	case 6257ULL: goto x86_l_1871;
	case 6260ULL: goto x86_l_1874;
	case 6263ULL: goto x86_l_1877;
	case 6269ULL: goto x86_l_187d;
	case 6272ULL: goto x86_l_1880;
	case 6278ULL: goto x86_l_1886;
	case 6283ULL: goto x86_l_188b;
	case 6291ULL: goto x86_l_1893;
	case 6295ULL: goto x86_l_1897;
	case 6303ULL: goto x86_l_189f;
	case 6308ULL: goto x86_l_18a4;
	case 6313ULL: goto x86_l_18a9;
	case 6318ULL: goto x86_l_18ae;
	case 6320ULL: goto x86_l_18b0;
	case 6328ULL: goto x86_l_18b8;
	case 6333ULL: goto x86_l_18bd;
	case 6340ULL: goto x86_l_18c4;
	case 6349ULL: goto x86_l_18cd;
	case 6353ULL: goto x86_l_18d1;
	case 6361ULL: goto x86_l_18d9;
	case 6368ULL: goto x86_l_18e0;
	case 6376ULL: goto x86_l_18e8;
	case 6384ULL: goto x86_l_18f0;
	case 6392ULL: goto x86_l_18f8;
	case 6397ULL: goto x86_l_18fd;
	case 6402ULL: goto x86_l_1902;
	case 6409ULL: goto x86_l_1909;
	case 6414ULL: goto x86_l_190e;
	case 6416ULL: goto x86_l_1910;
	case 6420ULL: goto x86_l_1914;
	case 6425ULL: goto x86_l_1919;
	case 6430ULL: goto x86_l_191e;
	case 6433ULL: goto x86_l_1921;
	case 6438ULL: goto x86_l_1926;
	case 6441ULL: goto x86_l_1929;
	case 6443ULL: goto x86_l_192b;
	case 6450ULL: goto x86_l_1932;
	case 6458ULL: goto x86_l_193a;
	case 6463ULL: goto x86_l_193f;
	case 6468ULL: goto x86_l_1944;
	case 6473ULL: goto x86_l_1949;
	case 6478ULL: goto x86_l_194e;
	case 6486ULL: goto x86_l_1956;
	case 6495ULL: goto x86_l_195f;
	case 6504ULL: goto x86_l_1968;
	case 6509ULL: goto x86_l_196d;
	case 6511ULL: goto x86_l_196f;
	case 6515ULL: goto x86_l_1973;
	case 6520ULL: goto x86_l_1978;
	case 6525ULL: goto x86_l_197d;
	case 6530ULL: goto x86_l_1982;
	case 6535ULL: goto x86_l_1987;
	case 6540ULL: goto x86_l_198c;
	case 6545ULL: goto x86_l_1991;
	case 6547ULL: goto x86_l_1993;
	case 6551ULL: goto x86_l_1997;
	case 6555ULL: goto x86_l_199b;
	case 6562ULL: goto x86_l_19a2;
	case 6567ULL: goto x86_l_19a7;
	case 6572ULL: goto x86_l_19ac;
	case 6574ULL: goto x86_l_19ae;
	case 6577ULL: goto x86_l_19b1;
	case 6583ULL: goto x86_l_19b7;
	case 6585ULL: goto x86_l_19b9;
	case 6590ULL: goto x86_l_19be;
	case 6593ULL: goto x86_l_19c1;
	case 6598ULL: goto x86_l_19c6;
	case 6606ULL: goto x86_l_19ce;
	case 6611ULL: goto x86_l_19d3;
	case 6614ULL: goto x86_l_19d6;
	case 6619ULL: goto x86_l_19db;
	case 6621ULL: goto x86_l_19dd;
	case 6627ULL: goto x86_l_19e3;
	case 6632ULL: goto x86_l_19e8;
	case 6639ULL: goto x86_l_19ef;
	case 6643ULL: goto x86_l_19f3;
	case 6648ULL: goto x86_l_19f8;
	case 6651ULL: goto x86_l_19fb;
	case 6653ULL: goto x86_l_19fd;
	case 6657ULL: goto x86_l_1a01;
	case 6661ULL: goto x86_l_1a05;
	case 6665ULL: goto x86_l_1a09;
	case 6669ULL: goto x86_l_1a0d;
	case 6674ULL: goto x86_l_1a12;
	case 6679ULL: goto x86_l_1a17;
	case 6684ULL: goto x86_l_1a1c;
	case 6686ULL: goto x86_l_1a1e;
	case 6690ULL: goto x86_l_1a22;
	case 6695ULL: goto x86_l_1a27;
	case 6700ULL: goto x86_l_1a2c;
	case 6705ULL: goto x86_l_1a31;
	case 6710ULL: goto x86_l_1a36;
	case 6715ULL: goto x86_l_1a3b;
	case 6720ULL: goto x86_l_1a40;
	case 6723ULL: goto x86_l_1a43;
	case 6725ULL: goto x86_l_1a45;
	case 6730ULL: goto x86_l_1a4a;
	case 6735ULL: goto x86_l_1a4f;
	case 6740ULL: goto x86_l_1a54;
	case 6745ULL: goto x86_l_1a59;
	case 6748ULL: goto x86_l_1a5c;
	case 6753ULL: goto x86_l_1a61;
	case 6755ULL: goto x86_l_1a63;
	case 6760ULL: goto x86_l_1a68;
	case 6765ULL: goto x86_l_1a6d;
	case 6768ULL: goto x86_l_1a70;
	case 6775ULL: goto x86_l_1a77;
	case 6780ULL: goto x86_l_1a7c;
	case 6785ULL: goto x86_l_1a81;
	case 6790ULL: goto x86_l_1a86;
	case 6792ULL: goto x86_l_1a88;
	case 6795ULL: goto x86_l_1a8b;
	case 6798ULL: goto x86_l_1a8e;
	case 6800ULL: goto x86_l_1a90;
	case 6803ULL: goto x86_l_1a93;
	case 6811ULL: goto x86_l_1a9b;
	case 6813ULL: goto x86_l_1a9d;
	case 6817ULL: goto x86_l_1aa1;
	case 6822ULL: goto x86_l_1aa6;
	case 6827ULL: goto x86_l_1aab;
	case 6832ULL: goto x86_l_1ab0;
	case 6837ULL: goto x86_l_1ab5;
	case 6842ULL: goto x86_l_1aba;
	case 6849ULL: goto x86_l_1ac1;
	case 6854ULL: goto x86_l_1ac6;
	case 6859ULL: goto x86_l_1acb;
	case 6864ULL: goto x86_l_1ad0;
	case 6866ULL: goto x86_l_1ad2;
	case 6869ULL: goto x86_l_1ad5;
	case 6872ULL: goto x86_l_1ad8;
	case 6874ULL: goto x86_l_1ada;
	case 6879ULL: goto x86_l_1adf;
	case 6884ULL: goto x86_l_1ae4;
	case 6886ULL: goto x86_l_1ae6;
	case 6891ULL: goto x86_l_1aeb;
	case 6900ULL: goto x86_l_1af4;
	case 6906ULL: goto x86_l_1afa;
	case 6911ULL: goto x86_l_1aff;
	case 6919ULL: goto x86_l_1b07;
	case 6923ULL: goto x86_l_1b0b;
	case 6928ULL: goto x86_l_1b10;
	case 6934ULL: goto x86_l_1b16;
	case 6939ULL: goto x86_l_1b1b;
	case 6944ULL: goto x86_l_1b20;
	case 6949ULL: goto x86_l_1b25;
	case 6951ULL: goto x86_l_1b27;
	case 6956ULL: goto x86_l_1b2c;
	case 6958ULL: goto x86_l_1b2e;
	case 6964ULL: goto x86_l_1b34;
	case 6969ULL: goto x86_l_1b39;
	case 6974ULL: goto x86_l_1b3e;
	case 6977ULL: goto x86_l_1b41;
	case 6980ULL: goto x86_l_1b44;
	case 6984ULL: goto x86_l_1b48;
	case 6987ULL: goto x86_l_1b4b;
	case 6991ULL: goto x86_l_1b4f;
	case 6996ULL: goto x86_l_1b54;
	case 7003ULL: goto x86_l_1b5b;
	case 7009ULL: goto x86_l_1b61;
	case 7014ULL: goto x86_l_1b66;
	case 7019ULL: goto x86_l_1b6b;
	case 7024ULL: goto x86_l_1b70;
	case 7030ULL: goto x86_l_1b76;
	case 7033ULL: goto x86_l_1b79;
	case 7038ULL: goto x86_l_1b7e;
	case 7043ULL: goto x86_l_1b83;
	case 7048ULL: goto x86_l_1b88;
	case 7051ULL: goto x86_l_1b8b;
	case 7053ULL: goto x86_l_1b8d;
	case 7058ULL: goto x86_l_1b92;
	case 7060ULL: goto x86_l_1b94;
	case 7066ULL: goto x86_l_1b9a;
	case 7071ULL: goto x86_l_1b9f;
	case 7074ULL: goto x86_l_1ba2;
	case 7080ULL: goto x86_l_1ba8;
	case 7086ULL: goto x86_l_1bae;
	case 7091ULL: goto x86_l_1bb3;
	case 7097ULL: goto x86_l_1bb9;
	case 7102ULL: goto x86_l_1bbe;
	case 7111ULL: goto x86_l_1bc7;
	case 7120ULL: goto x86_l_1bd0;
	case 7125ULL: goto x86_l_1bd5;
	case 7130ULL: goto x86_l_1bda;
	case 7135ULL: goto x86_l_1bdf;
	case 7140ULL: goto x86_l_1be4;
	case 7145ULL: goto x86_l_1be9;
	case 7150ULL: goto x86_l_1bee;
	case 7152ULL: goto x86_l_1bf0;
	case 7157ULL: goto x86_l_1bf5;
	case 7164ULL: goto x86_l_1bfc;
	case 7170ULL: goto x86_l_1c02;
	case 7174ULL: goto x86_l_1c06;
	case 7177ULL: goto x86_l_1c09;
	case 7184ULL: goto x86_l_1c10;
	case 7189ULL: goto x86_l_1c15;
	case 7194ULL: goto x86_l_1c1a;
	case 7197ULL: goto x86_l_1c1d;
	case 7199ULL: goto x86_l_1c1f;
	case 7204ULL: goto x86_l_1c24;
	case 7206ULL: goto x86_l_1c26;
	case 7208ULL: goto x86_l_1c28;
	case 7216ULL: goto x86_l_1c30;
	case 7220ULL: goto x86_l_1c34;
	case 7223ULL: goto x86_l_1c37;
	case 7226ULL: goto x86_l_1c3a;
	case 7234ULL: goto x86_l_1c42;
	case 7239ULL: goto x86_l_1c47;
	case 7244ULL: goto x86_l_1c4c;
	case 7251ULL: goto x86_l_1c53;
	case 7258ULL: goto x86_l_1c5a;
	case 7263ULL: goto x86_l_1c5f;
	case 7268ULL: goto x86_l_1c64;
	case 7273ULL: goto x86_l_1c69;
	case 7278ULL: goto x86_l_1c6e;
	case 7283ULL: goto x86_l_1c73;
	case 7288ULL: goto x86_l_1c78;
	case 7290ULL: goto x86_l_1c7a;
	case 7295ULL: goto x86_l_1c7f;
	case 7302ULL: goto x86_l_1c86;
	case 7307ULL: goto x86_l_1c8b;
	case 7312ULL: goto x86_l_1c90;
	case 7317ULL: goto x86_l_1c95;
	case 7322ULL: goto x86_l_1c9a;
	case 7324ULL: goto x86_l_1c9c;
	case 7329ULL: goto x86_l_1ca1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_158f:
	/* 0x158f: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1594:
	/* 0x1594: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1599:
	/* 0x1599: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_159e:
	/* 0x159e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_15a3:
	/* 0x15a3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_15a6:
	/* 0x15a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15a8:
	/* 0x15a8: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15ad:
	/* 0x15ad: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_15b2:
	/* 0x15b2: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_15b6:
	/* 0x15b6: sub    rax,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_15b9:
	/* 0x15b9: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_15be:
	/* 0x15be: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15c0:
	/* 0x15c0: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_15c2:
	/* 0x15c2: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_15c5:
	/* 0x15c5: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_15c8:
	/* 0x15c8: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_15cd:
	/* 0x15cd: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15cf:
	/* 0x15cf: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_15d2:
	/* 0x15d2: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_15d6:
	/* 0x15d6: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_15d8:
	/* 0x15d8: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_15dc:
	/* 0x15dc: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_15de:
	/* 0x15de: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_15e1:
	/* 0x15e1: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_15e3:
	/* 0x15e3: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_15e7:
	/* 0x15e7: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_15ea:
	/* 0x15ea: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_15f0:
	/* 0x15f0: jb     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1821ULL;
	}
x86_l_15f6:
	/* 0x15f6: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_15fc:
	/* 0x15fc: ja     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1821ULL;
	}
x86_l_1602:
	/* 0x1602: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1607:
	/* 0x1607: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_160a:
	/* 0x160a: jbe    1611 <generic_retkprobe_event+0x1611> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1611;
	}
x86_l_160c:
	/* 0x160c: mov    BYTE PTR [r14+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1611:
	/* 0x1611: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1613:
	/* 0x1613: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1616:
	/* 0x1616: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_161a:
	/* 0x161a: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_161d:
	/* 0x161d: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1620:
	/* 0x1620: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1623:
	/* 0x1623: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1628:
	/* 0x1628: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_162a:
	/* 0x162a: mov    QWORD PTR [rsp+0x58],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_162f:
	/* 0x162f: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1632:
	/* 0x1632: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1637:
	/* 0x1637: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_163d:
	/* 0x163d: jbe    71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1821ULL;
	}
x86_l_1643:
	/* 0x1643: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_164b:
	/* 0x164b: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1650:
	/* 0x1650: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1655:
	/* 0x1655: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_165a:
	/* 0x165a: jmp    234b <generic_retkprobe_event+0x234b> */
	return 9035ULL;
x86_l_165f:
	/* 0x165f: cmp    r14d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 8ULL);
x86_l_1663:
	/* 0x1663: je     1c4c <generic_retkprobe_event+0x1c4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c4c;
	}
x86_l_1669:
	/* 0x1669: cmp    r14d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 18ULL);
x86_l_166d:
	/* 0x166d: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1672:
	/* 0x1672: jne    2674 <generic_retkprobe_event+0x2674> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9844ULL;
	}
x86_l_1678:
	/* 0x1678: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_167a:
	/* 0x167a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_167f:
	/* 0x167f: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1681:
	/* 0x1681: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1684:
	/* 0x1684: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1686:
	/* 0x1686: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_168b:
	/* 0x168b: jmp    2674 <generic_retkprobe_event+0x2674> */
	return 9844ULL;
x86_l_1690:
	/* 0x1690: cmp    r14d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 19ULL);
x86_l_1694:
	/* 0x1694: je     1ffc <generic_retkprobe_event+0x1ffc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8188ULL;
	}
x86_l_169a:
	/* 0x169a: cmp    r14d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 20ULL);
x86_l_169e:
	/* 0x169e: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16a3:
	/* 0x16a3: jne    2674 <generic_retkprobe_event+0x2674> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9844ULL;
	}
x86_l_16a9:
	/* 0x16a9: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_16b2:
	/* 0x16b2: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_16b5:
	/* 0x16b5: lea    rdx,[r14+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_16bc:
	/* 0x16bc: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16c1:
	/* 0x16c1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16c6:
	/* 0x16c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16cb:
	/* 0x16cb: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16d0:
	/* 0x16d0: lea    r14,[rcx+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_16d7:
	/* 0x16d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16dc:
	/* 0x16dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16de:
	/* 0x16de: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16e3:
	/* 0x16e3: mov    edx,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 128ULL);
x86_l_16e8:
	/* 0x16e8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_16ed:
	/* 0x16ed: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16f2:
	/* 0x16f2: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_16f5:
	/* 0x16f5: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_16fa:
	/* 0x16fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16fc:
	/* 0x16fc: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1701:
	/* 0x1701: lea    rdi,[rax+0x12c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 300ULL);
x86_l_1708:
	/* 0x1708: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_170d:
	/* 0x170d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1712:
	/* 0x1712: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1717:
	/* 0x1717: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_171a:
	/* 0x171a: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_171f:
	/* 0x171f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1721:
	/* 0x1721: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1726:
	/* 0x1726: lea    rdi,[rax+0x11c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 284ULL);
x86_l_172d:
	/* 0x172d: lea    rdx,[r14+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1734:
	/* 0x1734: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1739:
	/* 0x1739: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_173e:
	/* 0x173e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1743:
	/* 0x1743: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1745:
	/* 0x1745: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_174a:
	/* 0x174a: add    rdi,0x124 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 292ULL);
x86_l_1751:
	/* 0x1751: lea    rdx,[r14+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_1758:
	/* 0x1758: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_175d:
	/* 0x175d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1762:
	/* 0x1762: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1767:
	/* 0x1767: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1769:
	/* 0x1769: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_176e:
	/* 0x176e: mov    ebp,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 152ULL);
x86_l_1773:
	/* 0x1773: jmp    2674 <generic_retkprobe_event+0x2674> */
	return 9844ULL;
x86_l_1778:
	/* 0x1778: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_177d:
	/* 0x177d: lea    rdi,[rcx+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1784:
	/* 0x1784: lea    rdx,[rbp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_178b:
	/* 0x178b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1790:
	/* 0x1790: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_1793:
	/* 0x1793: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1798:
	/* 0x1798: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_179d:
	/* 0x179d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_179f:
	/* 0x179f: lea    rdi,[r14+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_17a6:
	/* 0x17a6: lea    rdx,[rbp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_17aa:
	/* 0x17aa: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17af:
	/* 0x17af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17b4:
	/* 0x17b4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17b9:
	/* 0x17b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17bb:
	/* 0x17bb: lea    rdi,[r14+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_17c2:
	/* 0x17c2: lea    rdx,[rbp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_17c9:
	/* 0x17c9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17ce:
	/* 0x17ce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17d3:
	/* 0x17d3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17d8:
	/* 0x17d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17da:
	/* 0x17da: lea    rdi,[r14+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_17e1:
	/* 0x17e1: lea    rdx,[rbp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_17e8:
	/* 0x17e8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17ed:
	/* 0x17ed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17f2:
	/* 0x17f2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17f7:
	/* 0x17f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f9:
	/* 0x17f9: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1802:
	/* 0x1802: lea    rdx,[rbp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1809:
	/* 0x1809: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_180e:
	/* 0x180e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1813:
	/* 0x1813: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1818:
	/* 0x1818: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_181d:
	/* 0x181d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_181f:
	/* 0x181f: lea    rdx,[rbp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1826:
	/* 0x1826: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_182e:
	/* 0x182e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1833:
	/* 0x1833: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1838:
	/* 0x1838: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_183d:
	/* 0x183d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_183f:
	/* 0x183f: movzx  r14d,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_1848:
	/* 0x1848: add    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_184d:
	/* 0x184d: lea    rdi,[rsp+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_1855:
	/* 0x1855: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_185a:
	/* 0x185a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_185f:
	/* 0x185f: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1864:
	/* 0x1864: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1867:
	/* 0x1867: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1869:
	/* 0x1869: movzx  eax,BYTE PTR [rsp+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 180ULL);
x86_l_1871:
	/* 0x1871: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_1874:
	/* 0x1874: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1877:
	/* 0x1877: je     219f <generic_retkprobe_event+0x219f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8607ULL;
	}
x86_l_187d:
	/* 0x187d: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1880:
	/* 0x1880: jne    3700 <generic_retkprobe_event+0x3700> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14080ULL;
	}
x86_l_1886:
	/* 0x1886: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_188b:
	/* 0x188b: mov    QWORD PTR [rsp+0x98],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1893:
	/* 0x1893: lea    rdx,[r14+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_1897:
	/* 0x1897: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_189f:
	/* 0x189f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_18a4:
	/* 0x18a4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18a9:
	/* 0x18a9: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_18ae:
	/* 0x18ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b0:
	/* 0x18b0: movzx  eax,BYTE PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 200ULL);
x86_l_18b8:
	/* 0x18b8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18bd:
	/* 0x18bd: mov    WORD PTR [rcx+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_18c4:
	/* 0x18c4: mov    WORD PTR [rcx+0xc2],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655426ULL);
x86_l_18cd:
	/* 0x18cd: lea    rdx,[r14+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_18d1:
	/* 0x18d1: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_18d9:
	/* 0x18d9: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18e0:
	/* 0x18e0: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_18e8:
	/* 0x18e8: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_18f0:
	/* 0x18f0: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_18f8:
	/* 0x18f8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18fd:
	/* 0x18fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1902:
	/* 0x1902: lea    r12,[rcx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1909:
	/* 0x1909: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_190e:
	/* 0x190e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1910:
	/* 0x1910: add    r14,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1914:
	/* 0x1914: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1919:
	/* 0x1919: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_191e:
	/* 0x191e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1921:
	/* 0x1921: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1926:
	/* 0x1926: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1929:
	/* 0x1929: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_192b:
	/* 0x192b: lea    rdx,[rbp+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_1932:
	/* 0x1932: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_193a:
	/* 0x193a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_193f:
	/* 0x193f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1944:
	/* 0x1944: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1949:
	/* 0x1949: jmp    3569 <generic_retkprobe_event+0x3569> */
	return 13673ULL;
x86_l_194e:
	/* 0x194e: mov    QWORD PTR [rsp+0x98],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1956:
	/* 0x1956: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_195f:
	/* 0x195f: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1968:
	/* 0x1968: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_196d:
	/* 0x196d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_196f:
	/* 0x196f: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1973:
	/* 0x1973: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1978:
	/* 0x1978: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_197d:
	/* 0x197d: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1982:
	/* 0x1982: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1987:
	/* 0x1987: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_198c:
	/* 0x198c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1991:
	/* 0x1991: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1993:
	/* 0x1993: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1997:
	/* 0x1997: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_199b:
	/* 0x199b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_19a2:
	/* 0x19a2: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19a7:
	/* 0x19a7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19ac:
	/* 0x19ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19ae:
	/* 0x19ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19b1:
	/* 0x19b1: je     2186 <generic_retkprobe_event+0x2186> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8582ULL;
	}
x86_l_19b7:
	/* 0x19b7: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19b9:
	/* 0x19b9: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_19be:
	/* 0x19be: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_19c1:
	/* 0x19c1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19c6:
	/* 0x19c6: mov    r14,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_19ce:
	/* 0x19ce: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19d3:
	/* 0x19d3: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_19d6:
	/* 0x19d6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19db:
	/* 0x19db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19dd:
	/* 0x19dd: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19e3:
	/* 0x19e3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19e8:
	/* 0x19e8: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_19ef:
	/* 0x19ef: lea    rsi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19f3:
	/* 0x19f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19f8:
	/* 0x19f8: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_19fb:
	/* 0x19fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19fd:
	/* 0x19fd: lea    rdi,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1a01:
	/* 0x1a01: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1a05:
	/* 0x1a05: lea    rdx,[r12+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1a09:
	/* 0x1a09: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1a0d:
	/* 0x1a0d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a12:
	/* 0x1a12: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a17:
	/* 0x1a17: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a1c:
	/* 0x1a1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a1e:
	/* 0x1a1e: add    rbp,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1a22:
	/* 0x1a22: jmp    218d <generic_retkprobe_event+0x218d> */
	return 8589ULL;
x86_l_1a27:
	/* 0x1a27: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a2c:
	/* 0x1a2c: lea    r14,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a31:
	/* 0x1a31: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a36:
	/* 0x1a36: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a3b:
	/* 0x1a3b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a40:
	/* 0x1a40: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1a43:
	/* 0x1a43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a45:
	/* 0x1a45: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a4a:
	/* 0x1a4a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a4f:
	/* 0x1a4f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a54:
	/* 0x1a54: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a59:
	/* 0x1a59: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1a5c:
	/* 0x1a5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a61:
	/* 0x1a61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a63:
	/* 0x1a63: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a68:
	/* 0x1a68: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a6d:
	/* 0x1a6d: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_1a70:
	/* 0x1a70: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_1a77:
	/* 0x1a77: mov    ecx,0x91 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 145ULL);
x86_l_1a7c:
	/* 0x1a7c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1a81:
	/* 0x1a81: mov    esi,0x91 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 145ULL);
x86_l_1a86:
	/* 0x1a86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a88:
	/* 0x1a88: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1a8b:
	/* 0x1a8b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a8e:
	/* 0x1a8e: js     1ada <generic_retkprobe_event+0x1ada> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ada;
	}
x86_l_1a90:
	/* 0x1a90: lea    eax,[rbp-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1a93:
	/* 0x1a93: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1a9b:
	/* 0x1a9b: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a9d:
	/* 0x1a9d: add    rbp,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_1aa1:
	/* 0x1aa1: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aa6:
	/* 0x1aa6: jmp    953 <generic_retkprobe_event+0x953> */
	return 2387ULL;
x86_l_1aab:
	/* 0x1aab: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_1ab0:
	/* 0x1ab0: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1ab5:
	/* 0x1ab5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aba:
	/* 0x1aba: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_1ac1:
	/* 0x1ac1: mov    ecx,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_1ac6:
	/* 0x1ac6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1acb:
	/* 0x1acb: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1ad0:
	/* 0x1ad0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad2:
	/* 0x1ad2: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1ad5:
	/* 0x1ad5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ad8:
	/* 0x1ad8: jns    1a90 <generic_retkprobe_event+0x1a90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1a90;
	}
x86_l_1ada:
	/* 0x1ada: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1adf:
	/* 0x1adf: jmp    953 <generic_retkprobe_event+0x953> */
	return 2387ULL;
x86_l_1ae4:
	/* 0x1ae4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ae6:
	/* 0x1ae6: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1aeb:
	/* 0x1aeb: cmp    QWORD PTR [rsp+0xa8],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505731ULL);
x86_l_1af4:
	/* 0x1af4: jb     2897 <generic_retkprobe_event+0x2897> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10391ULL;
	}
x86_l_1afa:
	/* 0x1afa: mov    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aff:
	/* 0x1aff: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1b07:
	/* 0x1b07: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b0b:
	/* 0x1b0b: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b10:
	/* 0x1b10: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_1b16:
	/* 0x1b16: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1b1b:
	/* 0x1b1b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b20:
	/* 0x1b20: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b25:
	/* 0x1b25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b27:
	/* 0x1b27: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1b2c:
	/* 0x1b2c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b2e:
	/* 0x1b2e: js     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15444ULL;
	}
x86_l_1b34:
	/* 0x1b34: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b39:
	/* 0x1b39: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b3e:
	/* 0x1b3e: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1b41:
	/* 0x1b41: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1b44:
	/* 0x1b44: cmovb  r12,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_1b48:
	/* 0x1b48: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b4b:
	/* 0x1b4b: cmovne r13,r12 */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_1b4f:
	/* 0x1b4f: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_1b54:
	/* 0x1b54: cmp    r13,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4094ULL);
x86_l_1b5b:
	/* 0x1b5b: ja     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 15444ULL;
	}
x86_l_1b61:
	/* 0x1b61: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b66:
	/* 0x1b66: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1b6b:
	/* 0x1b6b: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b70:
	/* 0x1b70: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1b76:
	/* 0x1b76: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b79:
	/* 0x1b79: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b7e:
	/* 0x1b7e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b83:
	/* 0x1b83: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b88:
	/* 0x1b88: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_1b8b:
	/* 0x1b8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b8d:
	/* 0x1b8d: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1b92:
	/* 0x1b92: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b94:
	/* 0x1b94: js     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15444ULL;
	}
x86_l_1b9a:
	/* 0x1b9a: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b9f:
	/* 0x1b9f: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ba2:
	/* 0x1ba2: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1ba8:
	/* 0x1ba8: je     2885 <generic_retkprobe_event+0x2885> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10373ULL;
	}
x86_l_1bae:
	/* 0x1bae: sub    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_1bb3:
	/* 0x1bb3: jne    288c <generic_retkprobe_event+0x288c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10380ULL;
	}
x86_l_1bb9:
	/* 0x1bb9: jmp    2897 <generic_retkprobe_event+0x2897> */
	return 10391ULL;
x86_l_1bbe:
	/* 0x1bbe: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1bc7:
	/* 0x1bc7: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1bd0:
	/* 0x1bd0: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1bd5:
	/* 0x1bd5: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bda:
	/* 0x1bda: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1bdf:
	/* 0x1bdf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1be4:
	/* 0x1be4: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1be9:
	/* 0x1be9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bee:
	/* 0x1bee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bf0:
	/* 0x1bf0: mov    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1bf5:
	/* 0x1bf5: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_1bfc:
	/* 0x1bfc: mov    r14d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4095ULL);
x86_l_1c02:
	/* 0x1c02: cmovb  r14,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_1c06:
	/* 0x1c06: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1c09:
	/* 0x1c09: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1c10:
	/* 0x1c10: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c15:
	/* 0x1c15: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c1a:
	/* 0x1c1a: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_1c1d:
	/* 0x1c1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c1f:
	/* 0x1c1f: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1c24:
	/* 0x1c24: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c26:
	/* 0x1c26: js     1c3a <generic_retkprobe_event+0x1c3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1c3a;
	}
x86_l_1c28:
	/* 0x1c28: mov    DWORD PTR [r12+0xa0],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1c30:
	/* 0x1c30: add    r14,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1c34:
	/* 0x1c34: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_1c37:
	/* 0x1c37: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_1c3a:
	/* 0x1c3a: mov    DWORD PTR [r12+0x9c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1c42:
	/* 0x1c42: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c47:
	/* 0x1c47: jmp    2669 <generic_retkprobe_event+0x2669> */
	return 9833ULL;
x86_l_1c4c:
	/* 0x1c4c: lea    rbp,[rcx+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1c53:
	/* 0x1c53: lea    rax,[rcx+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_1c5a:
	/* 0x1c5a: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c5f:
	/* 0x1c5f: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c64:
	/* 0x1c64: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c69:
	/* 0x1c69: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c6e:
	/* 0x1c6e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c73:
	/* 0x1c73: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c78:
	/* 0x1c78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c7a:
	/* 0x1c7a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c7f:
	/* 0x1c7f: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1c86:
	/* 0x1c86: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1c8b:
	/* 0x1c8b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c90:
	/* 0x1c90: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c95:
	/* 0x1c95: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c9a:
	/* 0x1c9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c9c:
	/* 0x1c9c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ca1:
	/* 0x1ca1: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
	return 7336ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7336ULL: goto x86_l_1ca8;
	case 7341ULL: goto x86_l_1cad;
	case 7346ULL: goto x86_l_1cb2;
	case 7351ULL: goto x86_l_1cb7;
	case 7356ULL: goto x86_l_1cbc;
	case 7358ULL: goto x86_l_1cbe;
	case 7363ULL: goto x86_l_1cc3;
	case 7370ULL: goto x86_l_1cca;
	case 7375ULL: goto x86_l_1ccf;
	case 7380ULL: goto x86_l_1cd4;
	case 7385ULL: goto x86_l_1cd9;
	case 7390ULL: goto x86_l_1cde;
	case 7392ULL: goto x86_l_1ce0;
	case 7397ULL: goto x86_l_1ce5;
	case 7404ULL: goto x86_l_1cec;
	case 7409ULL: goto x86_l_1cf1;
	case 7414ULL: goto x86_l_1cf6;
	case 7419ULL: goto x86_l_1cfb;
	case 7424ULL: goto x86_l_1d00;
	case 7426ULL: goto x86_l_1d02;
	case 7431ULL: goto x86_l_1d07;
	case 7438ULL: goto x86_l_1d0e;
	case 7443ULL: goto x86_l_1d13;
	case 7448ULL: goto x86_l_1d18;
	case 7453ULL: goto x86_l_1d1d;
	case 7458ULL: goto x86_l_1d22;
	case 7460ULL: goto x86_l_1d24;
	case 7465ULL: goto x86_l_1d29;
	case 7472ULL: goto x86_l_1d30;
	case 7477ULL: goto x86_l_1d35;
	case 7482ULL: goto x86_l_1d3a;
	case 7487ULL: goto x86_l_1d3f;
	case 7492ULL: goto x86_l_1d44;
	case 7494ULL: goto x86_l_1d46;
	case 7499ULL: goto x86_l_1d4b;
	case 7506ULL: goto x86_l_1d52;
	case 7511ULL: goto x86_l_1d57;
	case 7516ULL: goto x86_l_1d5c;
	case 7521ULL: goto x86_l_1d61;
	case 7526ULL: goto x86_l_1d66;
	case 7528ULL: goto x86_l_1d68;
	case 7533ULL: goto x86_l_1d6d;
	case 7543ULL: goto x86_l_1d77;
	case 7548ULL: goto x86_l_1d7c;
	case 7555ULL: goto x86_l_1d83;
	case 7560ULL: goto x86_l_1d88;
	case 7565ULL: goto x86_l_1d8d;
	case 7570ULL: goto x86_l_1d92;
	case 7575ULL: goto x86_l_1d97;
	case 7577ULL: goto x86_l_1d99;
	case 7582ULL: goto x86_l_1d9e;
	case 7589ULL: goto x86_l_1da5;
	case 7594ULL: goto x86_l_1daa;
	case 7599ULL: goto x86_l_1daf;
	case 7604ULL: goto x86_l_1db4;
	case 7609ULL: goto x86_l_1db9;
	case 7611ULL: goto x86_l_1dbb;
	case 7616ULL: goto x86_l_1dc0;
	case 7623ULL: goto x86_l_1dc7;
	case 7628ULL: goto x86_l_1dcc;
	case 7633ULL: goto x86_l_1dd1;
	case 7638ULL: goto x86_l_1dd6;
	case 7643ULL: goto x86_l_1ddb;
	case 7645ULL: goto x86_l_1ddd;
	case 7650ULL: goto x86_l_1de2;
	case 7655ULL: goto x86_l_1de7;
	case 7660ULL: goto x86_l_1dec;
	case 7663ULL: goto x86_l_1def;
	case 7668ULL: goto x86_l_1df4;
	case 7670ULL: goto x86_l_1df6;
	case 7678ULL: goto x86_l_1dfe;
	case 7683ULL: goto x86_l_1e03;
	case 7688ULL: goto x86_l_1e08;
	case 7693ULL: goto x86_l_1e0d;
	case 7698ULL: goto x86_l_1e12;
	case 7700ULL: goto x86_l_1e14;
	case 7705ULL: goto x86_l_1e19;
	case 7712ULL: goto x86_l_1e20;
	case 7717ULL: goto x86_l_1e25;
	case 7722ULL: goto x86_l_1e2a;
	case 7727ULL: goto x86_l_1e2f;
	case 7732ULL: goto x86_l_1e34;
	case 7734ULL: goto x86_l_1e36;
	case 7739ULL: goto x86_l_1e3b;
	case 7746ULL: goto x86_l_1e42;
	case 7753ULL: goto x86_l_1e49;
	case 7758ULL: goto x86_l_1e4e;
	case 7763ULL: goto x86_l_1e53;
	case 7768ULL: goto x86_l_1e58;
	case 7770ULL: goto x86_l_1e5a;
	case 7775ULL: goto x86_l_1e5f;
	case 7782ULL: goto x86_l_1e66;
	case 7789ULL: goto x86_l_1e6d;
	case 7794ULL: goto x86_l_1e72;
	case 7799ULL: goto x86_l_1e77;
	case 7804ULL: goto x86_l_1e7c;
	case 7806ULL: goto x86_l_1e7e;
	case 7811ULL: goto x86_l_1e83;
	case 7818ULL: goto x86_l_1e8a;
	case 7825ULL: goto x86_l_1e91;
	case 7830ULL: goto x86_l_1e96;
	case 7835ULL: goto x86_l_1e9b;
	case 7840ULL: goto x86_l_1ea0;
	case 7843ULL: goto x86_l_1ea3;
	case 7846ULL: goto x86_l_1ea6;
	case 7848ULL: goto x86_l_1ea8;
	case 7853ULL: goto x86_l_1ead;
	case 7858ULL: goto x86_l_1eb2;
	case 7863ULL: goto x86_l_1eb7;
	case 7868ULL: goto x86_l_1ebc;
	case 7875ULL: goto x86_l_1ec3;
	case 7880ULL: goto x86_l_1ec8;
	case 7885ULL: goto x86_l_1ecd;
	case 7890ULL: goto x86_l_1ed2;
	case 7892ULL: goto x86_l_1ed4;
	case 7897ULL: goto x86_l_1ed9;
	case 7904ULL: goto x86_l_1ee0;
	case 7911ULL: goto x86_l_1ee7;
	case 7916ULL: goto x86_l_1eec;
	case 7921ULL: goto x86_l_1ef1;
	case 7926ULL: goto x86_l_1ef6;
	case 7928ULL: goto x86_l_1ef8;
	case 7933ULL: goto x86_l_1efd;
	case 7940ULL: goto x86_l_1f04;
	case 7947ULL: goto x86_l_1f0b;
	case 7952ULL: goto x86_l_1f10;
	case 7957ULL: goto x86_l_1f15;
	case 7962ULL: goto x86_l_1f1a;
	case 7964ULL: goto x86_l_1f1c;
	case 7969ULL: goto x86_l_1f21;
	case 7976ULL: goto x86_l_1f28;
	case 7983ULL: goto x86_l_1f2f;
	case 7988ULL: goto x86_l_1f34;
	case 7993ULL: goto x86_l_1f39;
	case 7998ULL: goto x86_l_1f3e;
	case 8000ULL: goto x86_l_1f40;
	case 8005ULL: goto x86_l_1f45;
	case 8010ULL: goto x86_l_1f4a;
	case 8015ULL: goto x86_l_1f4f;
	case 8020ULL: goto x86_l_1f54;
	case 8024ULL: goto x86_l_1f58;
	case 8029ULL: goto x86_l_1f5d;
	case 8034ULL: goto x86_l_1f62;
	case 8039ULL: goto x86_l_1f67;
	case 8041ULL: goto x86_l_1f69;
	case 8046ULL: goto x86_l_1f6e;
	case 8053ULL: goto x86_l_1f75;
	case 8057ULL: goto x86_l_1f79;
	case 8062ULL: goto x86_l_1f7e;
	case 8067ULL: goto x86_l_1f83;
	case 8072ULL: goto x86_l_1f88;
	case 8074ULL: goto x86_l_1f8a;
	case 8079ULL: goto x86_l_1f8f;
	case 8086ULL: goto x86_l_1f96;
	case 8090ULL: goto x86_l_1f9a;
	case 8095ULL: goto x86_l_1f9f;
	case 8100ULL: goto x86_l_1fa4;
	case 8105ULL: goto x86_l_1fa9;
	case 8107ULL: goto x86_l_1fab;
	case 8112ULL: goto x86_l_1fb0;
	case 8119ULL: goto x86_l_1fb7;
	case 8123ULL: goto x86_l_1fbb;
	case 8128ULL: goto x86_l_1fc0;
	case 8133ULL: goto x86_l_1fc5;
	case 8138ULL: goto x86_l_1fca;
	case 8140ULL: goto x86_l_1fcc;
	case 8145ULL: goto x86_l_1fd1;
	case 8152ULL: goto x86_l_1fd8;
	case 8156ULL: goto x86_l_1fdc;
	case 8161ULL: goto x86_l_1fe1;
	case 8166ULL: goto x86_l_1fe6;
	case 8171ULL: goto x86_l_1feb;
	case 8173ULL: goto x86_l_1fed;
	case 8178ULL: goto x86_l_1ff2;
	case 8183ULL: goto x86_l_1ff7;
	case 8188ULL: goto x86_l_1ffc;
	case 8193ULL: goto x86_l_2001;
	case 8198ULL: goto x86_l_2006;
	case 8203ULL: goto x86_l_200b;
	case 8208ULL: goto x86_l_2010;
	case 8211ULL: goto x86_l_2013;
	case 8213ULL: goto x86_l_2015;
	case 8218ULL: goto x86_l_201a;
	case 8225ULL: goto x86_l_2021;
	case 8229ULL: goto x86_l_2025;
	case 8234ULL: goto x86_l_202a;
	case 8239ULL: goto x86_l_202f;
	case 8244ULL: goto x86_l_2034;
	case 8246ULL: goto x86_l_2036;
	case 8251ULL: goto x86_l_203b;
	case 8258ULL: goto x86_l_2042;
	case 8262ULL: goto x86_l_2046;
	case 8267ULL: goto x86_l_204b;
	case 8272ULL: goto x86_l_2050;
	case 8277ULL: goto x86_l_2055;
	case 8282ULL: goto x86_l_205a;
	case 8286ULL: goto x86_l_205e;
	case 8291ULL: goto x86_l_2063;
	case 8296ULL: goto x86_l_2068;
	case 8301ULL: goto x86_l_206d;
	case 8306ULL: goto x86_l_2072;
	case 8308ULL: goto x86_l_2074;
	case 8312ULL: goto x86_l_2078;
	case 8317ULL: goto x86_l_207d;
	case 8323ULL: goto x86_l_2083;
	case 8327ULL: goto x86_l_2087;
	case 8332ULL: goto x86_l_208c;
	case 8337ULL: goto x86_l_2091;
	case 8342ULL: goto x86_l_2096;
	case 8347ULL: goto x86_l_209b;
	case 8349ULL: goto x86_l_209d;
	case 8353ULL: goto x86_l_20a1;
	case 8358ULL: goto x86_l_20a6;
	case 8364ULL: goto x86_l_20ac;
	case 8368ULL: goto x86_l_20b0;
	case 8373ULL: goto x86_l_20b5;
	case 8378ULL: goto x86_l_20ba;
	case 8383ULL: goto x86_l_20bf;
	case 8388ULL: goto x86_l_20c4;
	case 8390ULL: goto x86_l_20c6;
	case 8395ULL: goto x86_l_20cb;
	case 8402ULL: goto x86_l_20d2;
	case 8407ULL: goto x86_l_20d7;
	case 8412ULL: goto x86_l_20dc;
	case 8415ULL: goto x86_l_20df;
	case 8420ULL: goto x86_l_20e4;
	case 8425ULL: goto x86_l_20e9;
	case 8430ULL: goto x86_l_20ee;
	case 8435ULL: goto x86_l_20f3;
	case 8437ULL: goto x86_l_20f5;
	case 8442ULL: goto x86_l_20fa;
	case 8447ULL: goto x86_l_20ff;
	case 8452ULL: goto x86_l_2104;
	case 8460ULL: goto x86_l_210c;
	case 8468ULL: goto x86_l_2114;
	case 8476ULL: goto x86_l_211c;
	case 8484ULL: goto x86_l_2124;
	case 8492ULL: goto x86_l_212c;
	case 8500ULL: goto x86_l_2134;
	case 8508ULL: goto x86_l_213c;
	case 8516ULL: goto x86_l_2144;
	case 8524ULL: goto x86_l_214c;
	case 8527ULL: goto x86_l_214f;
	case 8534ULL: goto x86_l_2156;
	case 8539ULL: goto x86_l_215b;
	case 8544ULL: goto x86_l_2160;
	case 8549ULL: goto x86_l_2165;
	case 8554ULL: goto x86_l_216a;
	case 8559ULL: goto x86_l_216f;
	case 8561ULL: goto x86_l_2171;
	case 8564ULL: goto x86_l_2174;
	case 8570ULL: goto x86_l_217a;
	case 8572ULL: goto x86_l_217c;
	case 8577ULL: goto x86_l_2181;
	case 8582ULL: goto x86_l_2186;
	case 8589ULL: goto x86_l_218d;
	case 8594ULL: goto x86_l_2192;
	case 8602ULL: goto x86_l_219a;
	case 8607ULL: goto x86_l_219f;
	case 8612ULL: goto x86_l_21a4;
	case 8620ULL: goto x86_l_21ac;
	case 8625ULL: goto x86_l_21b1;
	case 8633ULL: goto x86_l_21b9;
	case 8642ULL: goto x86_l_21c2;
	case 8649ULL: goto x86_l_21c9;
	case 8654ULL: goto x86_l_21ce;
	case 8659ULL: goto x86_l_21d3;
	case 8663ULL: goto x86_l_21d7;
	case 8665ULL: goto x86_l_21d9;
	case 8668ULL: goto x86_l_21dc;
	case 8674ULL: goto x86_l_21e2;
	case 8677ULL: goto x86_l_21e5;
	case 8681ULL: goto x86_l_21e9;
	case 8686ULL: goto x86_l_21ee;
	case 8691ULL: goto x86_l_21f3;
	case 8694ULL: goto x86_l_21f6;
	case 8698ULL: goto x86_l_21fa;
	case 8702ULL: goto x86_l_21fe;
	case 8707ULL: goto x86_l_2203;
	case 8712ULL: goto x86_l_2208;
	case 8715ULL: goto x86_l_220b;
	case 8720ULL: goto x86_l_2210;
	case 8722ULL: goto x86_l_2212;
	case 8725ULL: goto x86_l_2215;
	case 8731ULL: goto x86_l_221b;
	case 8736ULL: goto x86_l_2220;
	case 8739ULL: goto x86_l_2223;
	case 8745ULL: goto x86_l_2229;
	case 8747ULL: goto x86_l_222b;
	case 8753ULL: goto x86_l_2231;
	case 8756ULL: goto x86_l_2234;
	case 8762ULL: goto x86_l_223a;
	case 8765ULL: goto x86_l_223d;
	case 8771ULL: goto x86_l_2243;
	case 8778ULL: goto x86_l_224a;
	case 8782ULL: goto x86_l_224e;
	case 8787ULL: goto x86_l_2253;
	case 8791ULL: goto x86_l_2257;
	case 8796ULL: goto x86_l_225c;
	case 8801ULL: goto x86_l_2261;
	case 8806ULL: goto x86_l_2266;
	case 8808ULL: goto x86_l_2268;
	case 8812ULL: goto x86_l_226c;
	case 8817ULL: goto x86_l_2271;
	case 8822ULL: goto x86_l_2276;
	case 8825ULL: goto x86_l_2279;
	case 8830ULL: goto x86_l_227e;
	case 8832ULL: goto x86_l_2280;
	case 8837ULL: goto x86_l_2285;
	case 8844ULL: goto x86_l_228c;
	case 8848ULL: goto x86_l_2290;
	case 8852ULL: goto x86_l_2294;
	case 8857ULL: goto x86_l_2299;
	case 8862ULL: goto x86_l_229e;
	case 8867ULL: goto x86_l_22a3;
	case 8870ULL: goto x86_l_22a6;
	case 8872ULL: goto x86_l_22a8;
	case 8877ULL: goto x86_l_22ad;
	case 8884ULL: goto x86_l_22b4;
	case 8889ULL: goto x86_l_22b9;
	case 8894ULL: goto x86_l_22be;
	case 8899ULL: goto x86_l_22c3;
	case 8902ULL: goto x86_l_22c6;
	case 8904ULL: goto x86_l_22c8;
	case 8909ULL: goto x86_l_22cd;
	case 8916ULL: goto x86_l_22d4;
	case 8925ULL: goto x86_l_22dd;
	case 8930ULL: goto x86_l_22e2;
	case 8935ULL: goto x86_l_22e7;
	case 8939ULL: goto x86_l_22eb;
	case 8944ULL: goto x86_l_22f0;
	case 8949ULL: goto x86_l_22f5;
	case 8954ULL: goto x86_l_22fa;
	case 8959ULL: goto x86_l_22ff;
	case 8961ULL: goto x86_l_2301;
	case 8966ULL: goto x86_l_2306;
	case 8971ULL: goto x86_l_230b;
	case 8976ULL: goto x86_l_2310;
	case 8982ULL: goto x86_l_2316;
	case 8987ULL: goto x86_l_231b;
	case 8991ULL: goto x86_l_231f;
	case 8996ULL: goto x86_l_2324;
	case 9001ULL: goto x86_l_2329;
	case 9006ULL: goto x86_l_232e;
	case 9009ULL: goto x86_l_2331;
	case 9011ULL: goto x86_l_2333;
	case 9016ULL: goto x86_l_2338;
	case 9021ULL: goto x86_l_233d;
	case 9025ULL: goto x86_l_2341;
	case 9030ULL: goto x86_l_2346;
	case 9035ULL: goto x86_l_234b;
	case 9040ULL: goto x86_l_2350;
	case 9045ULL: goto x86_l_2355;
	case 9047ULL: goto x86_l_2357;
	case 9052ULL: goto x86_l_235c;
	case 9058ULL: goto x86_l_2362;
	case 9066ULL: goto x86_l_236a;
	case 9071ULL: goto x86_l_236f;
	case 9076ULL: goto x86_l_2374;
	case 9081ULL: goto x86_l_2379;
	case 9083ULL: goto x86_l_237b;
	case 9091ULL: goto x86_l_2383;
	case 9097ULL: goto x86_l_2389;
	case 9102ULL: goto x86_l_238e;
	case 9107ULL: goto x86_l_2393;
	case 9112ULL: goto x86_l_2398;
	case 9117ULL: goto x86_l_239d;
	case 9122ULL: goto x86_l_23a2;
	case 9125ULL: goto x86_l_23a5;
	case 9127ULL: goto x86_l_23a7;
	case 9132ULL: goto x86_l_23ac;
	case 9138ULL: goto x86_l_23b2;
	case 9146ULL: goto x86_l_23ba;
	case 9151ULL: goto x86_l_23bf;
	case 9156ULL: goto x86_l_23c4;
	case 9161ULL: goto x86_l_23c9;
	case 9164ULL: goto x86_l_23cc;
	case 9166ULL: goto x86_l_23ce;
	case 9170ULL: goto x86_l_23d2;
	case 9175ULL: goto x86_l_23d7;
	case 9180ULL: goto x86_l_23dc;
	case 9185ULL: goto x86_l_23e1;
	case 9190ULL: goto x86_l_23e6;
	case 9193ULL: goto x86_l_23e9;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1ca8:
	/* 0x1ca8: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cad:
	/* 0x1cad: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cb2:
	/* 0x1cb2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cb7:
	/* 0x1cb7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cbc:
	/* 0x1cbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cbe:
	/* 0x1cbe: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cc3:
	/* 0x1cc3: lea    rdi,[rax+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1cca:
	/* 0x1cca: lea    rdx,[r12+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1ccf:
	/* 0x1ccf: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cd4:
	/* 0x1cd4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cd9:
	/* 0x1cd9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cde:
	/* 0x1cde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ce0:
	/* 0x1ce0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ce5:
	/* 0x1ce5: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1cec:
	/* 0x1cec: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cf1:
	/* 0x1cf1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cf6:
	/* 0x1cf6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cfb:
	/* 0x1cfb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d00:
	/* 0x1d00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d02:
	/* 0x1d02: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d07:
	/* 0x1d07: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1d0e:
	/* 0x1d0e: lea    rdx,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1d13:
	/* 0x1d13: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d18:
	/* 0x1d18: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d1d:
	/* 0x1d1d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d22:
	/* 0x1d22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d24:
	/* 0x1d24: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d29:
	/* 0x1d29: lea    rdi,[rax+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_1d30:
	/* 0x1d30: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d35:
	/* 0x1d35: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d3a:
	/* 0x1d3a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d3f:
	/* 0x1d3f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d44:
	/* 0x1d44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d46:
	/* 0x1d46: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d4b:
	/* 0x1d4b: lea    rdi,[rax+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1d52:
	/* 0x1d52: lea    rdx,[r12+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1d57:
	/* 0x1d57: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d5c:
	/* 0x1d5c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d61:
	/* 0x1d61: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d66:
	/* 0x1d66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d68:
	/* 0x1d68: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d6d:
	/* 0x1d6d: mov    DWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_1d77:
	/* 0x1d77: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d7c:
	/* 0x1d7c: lea    rdi,[rax+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1d83:
	/* 0x1d83: lea    rdx,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d88:
	/* 0x1d88: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d8d:
	/* 0x1d8d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d92:
	/* 0x1d92: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d97:
	/* 0x1d97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d99:
	/* 0x1d99: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d9e:
	/* 0x1d9e: lea    rdi,[rax+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1da5:
	/* 0x1da5: lea    rdx,[r12+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1daa:
	/* 0x1daa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1daf:
	/* 0x1daf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1db4:
	/* 0x1db4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1db9:
	/* 0x1db9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dbb:
	/* 0x1dbb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dc0:
	/* 0x1dc0: lea    rdi,[rax+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_1dc7:
	/* 0x1dc7: lea    rdx,[r12+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1dcc:
	/* 0x1dcc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1dd1:
	/* 0x1dd1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dd6:
	/* 0x1dd6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ddb:
	/* 0x1ddb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ddd:
	/* 0x1ddd: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1de2:
	/* 0x1de2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1de7:
	/* 0x1de7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dec:
	/* 0x1dec: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1def:
	/* 0x1def: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1df4:
	/* 0x1df4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1df6:
	/* 0x1df6: lea    rdx,[r12+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1dfe:
	/* 0x1dfe: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e03:
	/* 0x1e03: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e08:
	/* 0x1e08: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e0d:
	/* 0x1e0d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e12:
	/* 0x1e12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e14:
	/* 0x1e14: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e19:
	/* 0x1e19: lea    rdx,[r14+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1e20:
	/* 0x1e20: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e25:
	/* 0x1e25: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e2a:
	/* 0x1e2a: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e2f:
	/* 0x1e2f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e34:
	/* 0x1e34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e36:
	/* 0x1e36: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e3b:
	/* 0x1e3b: lea    rdi,[rax+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1e42:
	/* 0x1e42: lea    rdx,[r14+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1e49:
	/* 0x1e49: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e4e:
	/* 0x1e4e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e53:
	/* 0x1e53: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e58:
	/* 0x1e58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e5a:
	/* 0x1e5a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e5f:
	/* 0x1e5f: lea    rdi,[rax+0xe4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_1e66:
	/* 0x1e66: lea    rdx,[r14+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1e6d:
	/* 0x1e6d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e72:
	/* 0x1e72: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e77:
	/* 0x1e77: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e7c:
	/* 0x1e7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e7e:
	/* 0x1e7e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e83:
	/* 0x1e83: add    rdi,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1e8a:
	/* 0x1e8a: add    r14,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1e91:
	/* 0x1e91: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e96:
	/* 0x1e96: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e9b:
	/* 0x1e9b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ea0:
	/* 0x1ea0: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1ea3:
	/* 0x1ea3: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_1ea6:
	/* 0x1ea6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ea8:
	/* 0x1ea8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ead:
	/* 0x1ead: mov    ebp,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 80ULL);
x86_l_1eb2:
	/* 0x1eb2: jmp    2674 <generic_retkprobe_event+0x2674> */
	return 9844ULL;
x86_l_1eb7:
	/* 0x1eb7: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ebc:
	/* 0x1ebc: lea    rdx,[r14+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1ec3:
	/* 0x1ec3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ec8:
	/* 0x1ec8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ecd:
	/* 0x1ecd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ed2:
	/* 0x1ed2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ed4:
	/* 0x1ed4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ed9:
	/* 0x1ed9: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1ee0:
	/* 0x1ee0: lea    rdx,[r14+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1ee7:
	/* 0x1ee7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1eec:
	/* 0x1eec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ef1:
	/* 0x1ef1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ef6:
	/* 0x1ef6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ef8:
	/* 0x1ef8: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1efd:
	/* 0x1efd: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1f04:
	/* 0x1f04: lea    rdx,[r14+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1f0b:
	/* 0x1f0b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1f10:
	/* 0x1f10: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f15:
	/* 0x1f15: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f1a:
	/* 0x1f1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f1c:
	/* 0x1f1c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f21:
	/* 0x1f21: add    rdi,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_1f28:
	/* 0x1f28: lea    rdx,[r14+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1f2f:
	/* 0x1f2f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1f34:
	/* 0x1f34: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f39:
	/* 0x1f39: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f3e:
	/* 0x1f3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f40:
	/* 0x1f40: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f45:
	/* 0x1f45: mov    ebp,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_1f4a:
	/* 0x1f4a: jmp    2674 <generic_retkprobe_event+0x2674> */
	return 9844ULL;
x86_l_1f4f:
	/* 0x1f4f: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f54:
	/* 0x1f54: lea    rdx,[r14+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f58:
	/* 0x1f58: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1f5d:
	/* 0x1f5d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f62:
	/* 0x1f62: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f67:
	/* 0x1f67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f69:
	/* 0x1f69: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f6e:
	/* 0x1f6e: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1f75:
	/* 0x1f75: lea    rdx,[r14+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1f79:
	/* 0x1f79: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1f7e:
	/* 0x1f7e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f83:
	/* 0x1f83: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f88:
	/* 0x1f88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f8a:
	/* 0x1f8a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f8f:
	/* 0x1f8f: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1f96:
	/* 0x1f96: lea    rdx,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f9a:
	/* 0x1f9a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1f9f:
	/* 0x1f9f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fa4:
	/* 0x1fa4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fa9:
	/* 0x1fa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fab:
	/* 0x1fab: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fb0:
	/* 0x1fb0: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1fb7:
	/* 0x1fb7: lea    rdx,[r14+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1fbb:
	/* 0x1fbb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1fc0:
	/* 0x1fc0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fc5:
	/* 0x1fc5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fca:
	/* 0x1fca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fcc:
	/* 0x1fcc: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fd1:
	/* 0x1fd1: add    rdi,0xac */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 172ULL);
x86_l_1fd8:
	/* 0x1fd8: lea    rdx,[r14+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1fdc:
	/* 0x1fdc: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1fe1:
	/* 0x1fe1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fe6:
	/* 0x1fe6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1feb:
	/* 0x1feb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fed:
	/* 0x1fed: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ff2:
	/* 0x1ff2: mov    ebp,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 32ULL);
x86_l_1ff7:
	/* 0x1ff7: jmp    2674 <generic_retkprobe_event+0x2674> */
	return 9844ULL;
x86_l_1ffc:
	/* 0x1ffc: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2001:
	/* 0x2001: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2006:
	/* 0x2006: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_200b:
	/* 0x200b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2010:
	/* 0x2010: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2013:
	/* 0x2013: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2015:
	/* 0x2015: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_201a:
	/* 0x201a: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2021:
	/* 0x2021: lea    rdx,[r14+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2025:
	/* 0x2025: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_202a:
	/* 0x202a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_202f:
	/* 0x202f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2034:
	/* 0x2034: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2036:
	/* 0x2036: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_203b:
	/* 0x203b: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_2042:
	/* 0x2042: lea    rdx,[r14+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2046:
	/* 0x2046: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_204b:
	/* 0x204b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2050:
	/* 0x2050: jmp    20ee <generic_retkprobe_event+0x20ee> */
	goto x86_l_20ee;
x86_l_2055:
	/* 0x2055: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_205a:
	/* 0x205a: lea    rdx,[r14+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_205e:
	/* 0x205e: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2063:
	/* 0x2063: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2068:
	/* 0x2068: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_206d:
	/* 0x206d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2072:
	/* 0x2072: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2074:
	/* 0x2074: mov    ecx,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2078:
	/* 0x2078: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_207d:
	/* 0x207d: mov    DWORD PTR [rax+0x9c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_2083:
	/* 0x2083: lea    rdx,[r14+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2087:
	/* 0x2087: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_208c:
	/* 0x208c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2091:
	/* 0x2091: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2096:
	/* 0x2096: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_209b:
	/* 0x209b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_209d:
	/* 0x209d: mov    ecx,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20a1:
	/* 0x20a1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20a6:
	/* 0x20a6: mov    DWORD PTR [rax+0xa0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_20ac:
	/* 0x20ac: lea    rdx,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_20b0:
	/* 0x20b0: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20b5:
	/* 0x20b5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_20ba:
	/* 0x20ba: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_20bf:
	/* 0x20bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20c4:
	/* 0x20c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20c6:
	/* 0x20c6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20cb:
	/* 0x20cb: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_20d2:
	/* 0x20d2: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_20d7:
	/* 0x20d7: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20dc:
	/* 0x20dc: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_20df:
	/* 0x20df: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_20e4:
	/* 0x20e4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_20e9:
	/* 0x20e9: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_20ee:
	/* 0x20ee: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_20f3:
	/* 0x20f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20f5:
	/* 0x20f5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20fa:
	/* 0x20fa: mov    ebp,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_20ff:
	/* 0x20ff: jmp    2674 <generic_retkprobe_event+0x2674> */
	return 9844ULL;
x86_l_2104:
	/* 0x2104: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_210c:
	/* 0x210c: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2114:
	/* 0x2114: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_211c:
	/* 0x211c: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2124:
	/* 0x2124: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_212c:
	/* 0x212c: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2134:
	/* 0x2134: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_213c:
	/* 0x213c: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2144:
	/* 0x2144: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_214c:
	/* 0x214c: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_214f:
	/* 0x214f: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2156:
	/* 0x2156: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_215b:
	/* 0x215b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2160:
	/* 0x2160: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2165:
	/* 0x2165: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_216a:
	/* 0x216a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_216f:
	/* 0x216f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2171:
	/* 0x2171: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2174:
	/* 0x2174: je     2508 <generic_retkprobe_event+0x2508> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9480ULL;
	}
x86_l_217a:
	/* 0x217a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_217c:
	/* 0x217c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2181:
	/* 0x2181: jmp    2669 <generic_retkprobe_event+0x2669> */
	return 9833ULL;
x86_l_2186:
	/* 0x2186: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_218d:
	/* 0x218d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2192:
	/* 0x2192: mov    r12,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_219a:
	/* 0x219a: jmp    953 <generic_retkprobe_event+0x953> */
	return 2387ULL;
x86_l_219f:
	/* 0x219f: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21a4:
	/* 0x21a4: mov    QWORD PTR [rsp+0x98],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_21ac:
	/* 0x21ac: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21b1:
	/* 0x21b1: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_21b9:
	/* 0x21b9: movzx  r12d,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_21c2:
	/* 0x21c2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_21c9:
	/* 0x21c9: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_21ce:
	/* 0x21ce: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21d3:
	/* 0x21d3: lea    r13,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_21d7:
	/* 0x21d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21d9:
	/* 0x21d9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21dc:
	/* 0x21dc: je     350c <generic_retkprobe_event+0x350c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13580ULL;
	}
x86_l_21e2:
	/* 0x21e2: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_21e5:
	/* 0x21e5: mov    WORD PTR [r14],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21e9:
	/* 0x21e9: mov    BYTE PTR [r14+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_21ee:
	/* 0x21ee: mov    BYTE PTR [r14+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_21f3:
	/* 0x21f3: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_21f6:
	/* 0x21f6: add    rdi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_21fa:
	/* 0x21fa: lea    rdx,[r13+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_21fe:
	/* 0x21fe: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2203:
	/* 0x2203: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2208:
	/* 0x2208: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_220b:
	/* 0x220b: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_2210:
	/* 0x2210: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2212:
	/* 0x2212: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2215:
	/* 0x2215: js     350c <generic_retkprobe_event+0x350c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13580ULL;
	}
x86_l_221b:
	/* 0x221b: movzx  eax,BYTE PTR [r14+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2220:
	/* 0x2220: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2223:
	/* 0x2223: jg     268d <generic_retkprobe_event+0x268d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9869ULL;
	}
x86_l_2229:
	/* 0x2229: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_222b:
	/* 0x222b: je     26b6 <generic_retkprobe_event+0x26b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9910ULL;
	}
x86_l_2231:
	/* 0x2231: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2234:
	/* 0x2234: je     26b6 <generic_retkprobe_event+0x26b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9910ULL;
	}
x86_l_223a:
	/* 0x223a: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_223d:
	/* 0x223d: jne    2a3f <generic_retkprobe_event+0x2a3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10815ULL;
	}
x86_l_2243:
	/* 0x2243: mov    WORD PTR [r14+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_224a:
	/* 0x224a: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_224e:
	/* 0x224e: jmp    2975 <generic_retkprobe_event+0x2975> */
	return 10613ULL;
x86_l_2253:
	/* 0x2253: lea    rdx,[rbp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2257:
	/* 0x2257: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_225c:
	/* 0x225c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2261:
	/* 0x2261: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2266:
	/* 0x2266: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2268:
	/* 0x2268: lea    rdx,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_226c:
	/* 0x226c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2271:
	/* 0x2271: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2276:
	/* 0x2276: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2279:
	/* 0x2279: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_227e:
	/* 0x227e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2280:
	/* 0x2280: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2285:
	/* 0x2285: lea    rdi,[rax+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_228c:
	/* 0x228c: lea    r14,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2290:
	/* 0x2290: add    rbp,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_2294:
	/* 0x2294: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2299:
	/* 0x2299: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_229e:
	/* 0x229e: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_22a3:
	/* 0x22a3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_22a6:
	/* 0x22a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a8:
	/* 0x22a8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22ad:
	/* 0x22ad: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_22b4:
	/* 0x22b4: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_22b9:
	/* 0x22b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22be:
	/* 0x22be: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_22c3:
	/* 0x22c3: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_22c6:
	/* 0x22c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22c8:
	/* 0x22c8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22cd:
	/* 0x22cd: movzx  eax,WORD PTR [rcx+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_22d4:
	/* 0x22d4: movbe  WORD PTR [rcx+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_22dd:
	/* 0x22dd: mov    ebp,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_22e2:
	/* 0x22e2: jmp    953 <generic_retkprobe_event+0x953> */
	return 2387ULL;
x86_l_22e7:
	/* 0x22e7: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22eb:
	/* 0x22eb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22f0:
	/* 0x22f0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22f5:
	/* 0x22f5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22fa:
	/* 0x22fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22ff:
	/* 0x22ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2301:
	/* 0x2301: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2306:
	/* 0x2306: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_230b:
	/* 0x230b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2310:
	/* 0x2310: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_2316:
	/* 0x2316: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_231b:
	/* 0x231b: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_231f:
	/* 0x231f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2324:
	/* 0x2324: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2329:
	/* 0x2329: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_232e:
	/* 0x232e: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2331:
	/* 0x2331: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2333:
	/* 0x2333: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2338:
	/* 0x2338: mov    QWORD PTR [rsp+0x50],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_233d:
	/* 0x233d: lea    rdx,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2341:
	/* 0x2341: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2346:
	/* 0x2346: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_234b:
	/* 0x234b: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2350:
	/* 0x2350: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2355:
	/* 0x2355: jne    2362 <generic_retkprobe_event+0x2362> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2362;
	}
x86_l_2357:
	/* 0x2357: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_235c:
	/* 0x235c: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_2362:
	/* 0x2362: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_236a:
	/* 0x236a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_236f:
	/* 0x236f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2374:
	/* 0x2374: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2379:
	/* 0x2379: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_237b:
	/* 0x237b: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_2383:
	/* 0x2383: je     26ca <generic_retkprobe_event+0x26ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9930ULL;
	}
x86_l_2389:
	/* 0x2389: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_238e:
	/* 0x238e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2393:
	/* 0x2393: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2398:
	/* 0x2398: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_239d:
	/* 0x239d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23a2:
	/* 0x23a2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_23a5:
	/* 0x23a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23a7:
	/* 0x23a7: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23ac:
	/* 0x23ac: je     26ca <generic_retkprobe_event+0x26ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9930ULL;
	}
x86_l_23b2:
	/* 0x23b2: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_23ba:
	/* 0x23ba: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_23bf:
	/* 0x23bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23c4:
	/* 0x23c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23c9:
	/* 0x23c9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_23cc:
	/* 0x23cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23ce:
	/* 0x23ce: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_23d2:
	/* 0x23d2: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_23d7:
	/* 0x23d7: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_23dc:
	/* 0x23dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23e1:
	/* 0x23e1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_23e6:
	/* 0x23e6: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_23e9:
	/* 0x23e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 9195ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9195ULL: goto x86_l_23eb;
	case 9200ULL: goto x86_l_23f0;
	case 9205ULL: goto x86_l_23f5;
	case 9209ULL: goto x86_l_23f9;
	case 9212ULL: goto x86_l_23fc;
	case 9217ULL: goto x86_l_2401;
	case 9219ULL: goto x86_l_2403;
	case 9221ULL: goto x86_l_2405;
	case 9224ULL: goto x86_l_2408;
	case 9227ULL: goto x86_l_240b;
	case 9232ULL: goto x86_l_2410;
	case 9234ULL: goto x86_l_2412;
	case 9237ULL: goto x86_l_2415;
	case 9241ULL: goto x86_l_2419;
	case 9243ULL: goto x86_l_241b;
	case 9247ULL: goto x86_l_241f;
	case 9249ULL: goto x86_l_2421;
	case 9252ULL: goto x86_l_2424;
	case 9254ULL: goto x86_l_2426;
	case 9258ULL: goto x86_l_242a;
	case 9261ULL: goto x86_l_242d;
	case 9266ULL: goto x86_l_2432;
	case 9272ULL: goto x86_l_2438;
	case 9278ULL: goto x86_l_243e;
	case 9284ULL: goto x86_l_2444;
	case 9290ULL: goto x86_l_244a;
	case 9293ULL: goto x86_l_244d;
	case 9295ULL: goto x86_l_244f;
	case 9300ULL: goto x86_l_2454;
	case 9302ULL: goto x86_l_2456;
	case 9305ULL: goto x86_l_2459;
	case 9309ULL: goto x86_l_245d;
	case 9312ULL: goto x86_l_2460;
	case 9315ULL: goto x86_l_2463;
	case 9318ULL: goto x86_l_2466;
	case 9323ULL: goto x86_l_246b;
	case 9325ULL: goto x86_l_246d;
	case 9330ULL: goto x86_l_2472;
	case 9333ULL: goto x86_l_2475;
	case 9338ULL: goto x86_l_247a;
	case 9344ULL: goto x86_l_2480;
	case 9350ULL: goto x86_l_2486;
	case 9358ULL: goto x86_l_248e;
	case 9363ULL: goto x86_l_2493;
	case 9368ULL: goto x86_l_2498;
	case 9373ULL: goto x86_l_249d;
	case 9378ULL: goto x86_l_24a2;
	case 9385ULL: goto x86_l_24a9;
	case 9389ULL: goto x86_l_24ad;
	case 9394ULL: goto x86_l_24b2;
	case 9397ULL: goto x86_l_24b5;
	case 9400ULL: goto x86_l_24b8;
	case 9405ULL: goto x86_l_24bd;
	case 9410ULL: goto x86_l_24c2;
	case 9412ULL: goto x86_l_24c4;
	case 9415ULL: goto x86_l_24c7;
	case 9418ULL: goto x86_l_24ca;
	case 9425ULL: goto x86_l_24d1;
	case 9429ULL: goto x86_l_24d5;
	case 9434ULL: goto x86_l_24da;
	case 9439ULL: goto x86_l_24df;
	case 9444ULL: goto x86_l_24e4;
	case 9447ULL: goto x86_l_24e7;
	case 9449ULL: goto x86_l_24e9;
	case 9454ULL: goto x86_l_24ee;
	case 9461ULL: goto x86_l_24f5;
	case 9470ULL: goto x86_l_24fe;
	case 9475ULL: goto x86_l_2503;
	case 9480ULL: goto x86_l_2508;
	case 9485ULL: goto x86_l_250d;
	case 9492ULL: goto x86_l_2514;
	case 9497ULL: goto x86_l_2519;
	case 9502ULL: goto x86_l_251e;
	case 9507ULL: goto x86_l_2523;
	case 9512ULL: goto x86_l_2528;
	case 9517ULL: goto x86_l_252d;
	case 9519ULL: goto x86_l_252f;
	case 9522ULL: goto x86_l_2532;
	case 9528ULL: goto x86_l_2538;
	case 9533ULL: goto x86_l_253d;
	case 9537ULL: goto x86_l_2541;
	case 9542ULL: goto x86_l_2546;
	case 9547ULL: goto x86_l_254b;
	case 9552ULL: goto x86_l_2550;
	case 9557ULL: goto x86_l_2555;
	case 9559ULL: goto x86_l_2557;
	case 9564ULL: goto x86_l_255c;
	case 9571ULL: goto x86_l_2563;
	case 9576ULL: goto x86_l_2568;
	case 9581ULL: goto x86_l_256d;
	case 9584ULL: goto x86_l_2570;
	case 9589ULL: goto x86_l_2575;
	case 9594ULL: goto x86_l_257a;
	case 9599ULL: goto x86_l_257f;
	case 9604ULL: goto x86_l_2584;
	case 9606ULL: goto x86_l_2586;
	case 9610ULL: goto x86_l_258a;
	case 9615ULL: goto x86_l_258f;
	case 9620ULL: goto x86_l_2594;
	case 9625ULL: goto x86_l_2599;
	case 9630ULL: goto x86_l_259e;
	case 9632ULL: goto x86_l_25a0;
	case 9637ULL: goto x86_l_25a5;
	case 9640ULL: goto x86_l_25a8;
	case 9642ULL: goto x86_l_25aa;
	case 9644ULL: goto x86_l_25ac;
	case 9649ULL: goto x86_l_25b1;
	case 9652ULL: goto x86_l_25b4;
	case 9656ULL: goto x86_l_25b8;
	case 9661ULL: goto x86_l_25bd;
	case 9666ULL: goto x86_l_25c2;
	case 9668ULL: goto x86_l_25c4;
	case 9673ULL: goto x86_l_25c9;
	case 9678ULL: goto x86_l_25ce;
	case 9681ULL: goto x86_l_25d1;
	case 9686ULL: goto x86_l_25d6;
	case 9690ULL: goto x86_l_25da;
	case 9695ULL: goto x86_l_25df;
	case 9700ULL: goto x86_l_25e4;
	case 9703ULL: goto x86_l_25e7;
	case 9708ULL: goto x86_l_25ec;
	case 9710ULL: goto x86_l_25ee;
	case 9714ULL: goto x86_l_25f2;
	case 9719ULL: goto x86_l_25f7;
	case 9724ULL: goto x86_l_25fc;
	case 9727ULL: goto x86_l_25ff;
	case 9732ULL: goto x86_l_2604;
	case 9734ULL: goto x86_l_2606;
	case 9739ULL: goto x86_l_260b;
	case 9747ULL: goto x86_l_2613;
	case 9751ULL: goto x86_l_2617;
	case 9755ULL: goto x86_l_261b;
	case 9760ULL: goto x86_l_2620;
	case 9765ULL: goto x86_l_2625;
	case 9770ULL: goto x86_l_262a;
	case 9773ULL: goto x86_l_262d;
	case 9775ULL: goto x86_l_262f;
	case 9778ULL: goto x86_l_2632;
	case 9785ULL: goto x86_l_2639;
	case 9790ULL: goto x86_l_263e;
	case 9795ULL: goto x86_l_2643;
	case 9800ULL: goto x86_l_2648;
	case 9803ULL: goto x86_l_264b;
	case 9805ULL: goto x86_l_264d;
	case 9808ULL: goto x86_l_2650;
	case 9817ULL: goto x86_l_2659;
	case 9828ULL: goto x86_l_2664;
	case 9833ULL: goto x86_l_2669;
	case 9838ULL: goto x86_l_266e;
	case 9844ULL: goto x86_l_2674;
	case 9852ULL: goto x86_l_267c;
	case 9856ULL: goto x86_l_2680;
	case 9858ULL: goto x86_l_2682;
	case 9864ULL: goto x86_l_2688;
	case 9869ULL: goto x86_l_268d;
	case 9872ULL: goto x86_l_2690;
	case 9878ULL: goto x86_l_2696;
	case 9881ULL: goto x86_l_2699;
	case 9883ULL: goto x86_l_269b;
	case 9888ULL: goto x86_l_26a0;
	case 9894ULL: goto x86_l_26a6;
	case 9901ULL: goto x86_l_26ad;
	case 9905ULL: goto x86_l_26b1;
	case 9910ULL: goto x86_l_26b6;
	case 9913ULL: goto x86_l_26b9;
	case 9918ULL: goto x86_l_26be;
	case 9925ULL: goto x86_l_26c5;
	case 9930ULL: goto x86_l_26ca;
	case 9934ULL: goto x86_l_26ce;
	case 9939ULL: goto x86_l_26d3;
	case 9944ULL: goto x86_l_26d8;
	case 9949ULL: goto x86_l_26dd;
	case 9954ULL: goto x86_l_26e2;
	case 9956ULL: goto x86_l_26e4;
	case 9961ULL: goto x86_l_26e9;
	case 9966ULL: goto x86_l_26ee;
	case 9971ULL: goto x86_l_26f3;
	case 9976ULL: goto x86_l_26f8;
	case 9982ULL: goto x86_l_26fe;
	case 9986ULL: goto x86_l_2702;
	case 9991ULL: goto x86_l_2707;
	case 9996ULL: goto x86_l_270c;
	case 10001ULL: goto x86_l_2711;
	case 10004ULL: goto x86_l_2714;
	case 10006ULL: goto x86_l_2716;
	case 10011ULL: goto x86_l_271b;
	case 10016ULL: goto x86_l_2720;
	case 10020ULL: goto x86_l_2724;
	case 10025ULL: goto x86_l_2729;
	case 10030ULL: goto x86_l_272e;
	case 10035ULL: goto x86_l_2733;
	case 10040ULL: goto x86_l_2738;
	case 10042ULL: goto x86_l_273a;
	case 10047ULL: goto x86_l_273f;
	case 10053ULL: goto x86_l_2745;
	case 10061ULL: goto x86_l_274d;
	case 10066ULL: goto x86_l_2752;
	case 10071ULL: goto x86_l_2757;
	case 10076ULL: goto x86_l_275c;
	case 10078ULL: goto x86_l_275e;
	case 10086ULL: goto x86_l_2766;
	case 10092ULL: goto x86_l_276c;
	case 10097ULL: goto x86_l_2771;
	case 10102ULL: goto x86_l_2776;
	case 10107ULL: goto x86_l_277b;
	case 10112ULL: goto x86_l_2780;
	case 10117ULL: goto x86_l_2785;
	case 10120ULL: goto x86_l_2788;
	case 10122ULL: goto x86_l_278a;
	case 10127ULL: goto x86_l_278f;
	case 10133ULL: goto x86_l_2795;
	case 10141ULL: goto x86_l_279d;
	case 10146ULL: goto x86_l_27a2;
	case 10151ULL: goto x86_l_27a7;
	case 10156ULL: goto x86_l_27ac;
	case 10159ULL: goto x86_l_27af;
	case 10161ULL: goto x86_l_27b1;
	case 10165ULL: goto x86_l_27b5;
	case 10170ULL: goto x86_l_27ba;
	case 10175ULL: goto x86_l_27bf;
	case 10180ULL: goto x86_l_27c4;
	case 10185ULL: goto x86_l_27c9;
	case 10188ULL: goto x86_l_27cc;
	case 10190ULL: goto x86_l_27ce;
	case 10195ULL: goto x86_l_27d3;
	case 10200ULL: goto x86_l_27d8;
	case 10204ULL: goto x86_l_27dc;
	case 10207ULL: goto x86_l_27df;
	case 10212ULL: goto x86_l_27e4;
	case 10214ULL: goto x86_l_27e6;
	case 10216ULL: goto x86_l_27e8;
	case 10219ULL: goto x86_l_27eb;
	case 10222ULL: goto x86_l_27ee;
	case 10227ULL: goto x86_l_27f3;
	case 10229ULL: goto x86_l_27f5;
	case 10232ULL: goto x86_l_27f8;
	case 10236ULL: goto x86_l_27fc;
	case 10238ULL: goto x86_l_27fe;
	case 10242ULL: goto x86_l_2802;
	case 10244ULL: goto x86_l_2804;
	case 10247ULL: goto x86_l_2807;
	case 10249ULL: goto x86_l_2809;
	case 10253ULL: goto x86_l_280d;
	case 10256ULL: goto x86_l_2810;
	case 10261ULL: goto x86_l_2815;
	case 10267ULL: goto x86_l_281b;
	case 10273ULL: goto x86_l_2821;
	case 10279ULL: goto x86_l_2827;
	case 10285ULL: goto x86_l_282d;
	case 10288ULL: goto x86_l_2830;
	case 10290ULL: goto x86_l_2832;
	case 10295ULL: goto x86_l_2837;
	case 10297ULL: goto x86_l_2839;
	case 10300ULL: goto x86_l_283c;
	case 10304ULL: goto x86_l_2840;
	case 10307ULL: goto x86_l_2843;
	case 10310ULL: goto x86_l_2846;
	case 10313ULL: goto x86_l_2849;
	case 10318ULL: goto x86_l_284e;
	case 10320ULL: goto x86_l_2850;
	case 10325ULL: goto x86_l_2855;
	case 10328ULL: goto x86_l_2858;
	case 10333ULL: goto x86_l_285d;
	case 10339ULL: goto x86_l_2863;
	case 10345ULL: goto x86_l_2869;
	case 10353ULL: goto x86_l_2871;
	case 10358ULL: goto x86_l_2876;
	case 10363ULL: goto x86_l_287b;
	case 10368ULL: goto x86_l_2880;
	case 10373ULL: goto x86_l_2885;
	case 10375ULL: goto x86_l_2887;
	case 10380ULL: goto x86_l_288c;
	case 10389ULL: goto x86_l_2895;
	case 10391ULL: goto x86_l_2897;
	case 10394ULL: goto x86_l_289a;
	case 10399ULL: goto x86_l_289f;
	case 10404ULL: goto x86_l_28a4;
	case 10412ULL: goto x86_l_28ac;
	case 10416ULL: goto x86_l_28b0;
	case 10421ULL: goto x86_l_28b5;
	case 10427ULL: goto x86_l_28bb;
	case 10432ULL: goto x86_l_28c0;
	case 10437ULL: goto x86_l_28c5;
	case 10442ULL: goto x86_l_28ca;
	case 10444ULL: goto x86_l_28cc;
	case 10449ULL: goto x86_l_28d1;
	case 10451ULL: goto x86_l_28d3;
	case 10457ULL: goto x86_l_28d9;
	case 10462ULL: goto x86_l_28de;
	case 10467ULL: goto x86_l_28e3;
	case 10470ULL: goto x86_l_28e6;
	case 10473ULL: goto x86_l_28e9;
	case 10477ULL: goto x86_l_28ed;
	case 10480ULL: goto x86_l_28f0;
	case 10484ULL: goto x86_l_28f4;
	case 10489ULL: goto x86_l_28f9;
	case 10496ULL: goto x86_l_2900;
	case 10502ULL: goto x86_l_2906;
	case 10505ULL: goto x86_l_2909;
	case 10510ULL: goto x86_l_290e;
	case 10515ULL: goto x86_l_2913;
	case 10520ULL: goto x86_l_2918;
	case 10526ULL: goto x86_l_291e;
	case 10529ULL: goto x86_l_2921;
	case 10534ULL: goto x86_l_2926;
	case 10539ULL: goto x86_l_292b;
	case 10542ULL: goto x86_l_292e;
	case 10547ULL: goto x86_l_2933;
	case 10549ULL: goto x86_l_2935;
	case 10554ULL: goto x86_l_293a;
	case 10556ULL: goto x86_l_293c;
	case 10562ULL: goto x86_l_2942;
	case 10565ULL: goto x86_l_2945;
	case 10571ULL: goto x86_l_294b;
	case 10577ULL: goto x86_l_2951;
	case 10582ULL: goto x86_l_2956;
	case 10588ULL: goto x86_l_295c;
	case 10593ULL: goto x86_l_2961;
	case 10596ULL: goto x86_l_2964;
	case 10601ULL: goto x86_l_2969;
	case 10608ULL: goto x86_l_2970;
	case 10613ULL: goto x86_l_2975;
	case 10616ULL: goto x86_l_2978;
	case 10620ULL: goto x86_l_297c;
	case 10624ULL: goto x86_l_2980;
	case 10629ULL: goto x86_l_2985;
	case 10633ULL: goto x86_l_2989;
	case 10639ULL: goto x86_l_298f;
	case 10649ULL: goto x86_l_2999;
	case 10653ULL: goto x86_l_299d;
	case 10659ULL: goto x86_l_29a3;
	case 10663ULL: goto x86_l_29a7;
	case 10666ULL: goto x86_l_29aa;
	case 10669ULL: goto x86_l_29ad;
	case 10674ULL: goto x86_l_29b2;
	case 10679ULL: goto x86_l_29b7;
	case 10682ULL: goto x86_l_29ba;
	case 10686ULL: goto x86_l_29be;
	case 10689ULL: goto x86_l_29c1;
	case 10694ULL: goto x86_l_29c6;
	case 10696ULL: goto x86_l_29c8;
	case 10699ULL: goto x86_l_29cb;
	case 10705ULL: goto x86_l_29d1;
	case 10710ULL: goto x86_l_29d6;
	case 10713ULL: goto x86_l_29d9;
	case 10715ULL: goto x86_l_29db;
	case 10717ULL: goto x86_l_29dd;
	case 10719ULL: goto x86_l_29df;
	case 10722ULL: goto x86_l_29e2;
	case 10724ULL: goto x86_l_29e4;
	case 10727ULL: goto x86_l_29e7;
	case 10733ULL: goto x86_l_29ed;
	case 10740ULL: goto x86_l_29f4;
	case 10744ULL: goto x86_l_29f8;
	case 10749ULL: goto x86_l_29fd;
	case 10752ULL: goto x86_l_2a00;
	case 10758ULL: goto x86_l_2a06;
	case 10761ULL: goto x86_l_2a09;
	case 10763ULL: goto x86_l_2a0b;
	case 10768ULL: goto x86_l_2a10;
	case 10774ULL: goto x86_l_2a16;
	case 10781ULL: goto x86_l_2a1d;
	case 10785ULL: goto x86_l_2a21;
	case 10790ULL: goto x86_l_2a26;
	case 10793ULL: goto x86_l_2a29;
	case 10798ULL: goto x86_l_2a2e;
	case 10805ULL: goto x86_l_2a35;
	case 10810ULL: goto x86_l_2a3a;
	case 10815ULL: goto x86_l_2a3f;
	case 10820ULL: goto x86_l_2a44;
	case 10825ULL: goto x86_l_2a49;
	case 10829ULL: goto x86_l_2a4d;
	case 10834ULL: goto x86_l_2a52;
	case 10839ULL: goto x86_l_2a57;
	case 10844ULL: goto x86_l_2a5c;
	case 10849ULL: goto x86_l_2a61;
	case 10851ULL: goto x86_l_2a63;
	case 10856ULL: goto x86_l_2a68;
	case 10861ULL: goto x86_l_2a6d;
	case 10866ULL: goto x86_l_2a72;
	case 10871ULL: goto x86_l_2a77;
	case 10877ULL: goto x86_l_2a7d;
	case 10881ULL: goto x86_l_2a81;
	case 10886ULL: goto x86_l_2a86;
	default: return 0xffffffffffffffffULL;
	}
x86_l_23eb:
	/* 0x23eb: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_23f0:
	/* 0x23f0: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_23f5:
	/* 0x23f5: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_23f9:
	/* 0x23f9: sub    rax,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_23fc:
	/* 0x23fc: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2401:
	/* 0x2401: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2403:
	/* 0x2403: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_2405:
	/* 0x2405: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2408:
	/* 0x2408: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_240b:
	/* 0x240b: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_2410:
	/* 0x2410: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2412:
	/* 0x2412: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2415:
	/* 0x2415: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_2419:
	/* 0x2419: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_241b:
	/* 0x241b: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_241f:
	/* 0x241f: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2421:
	/* 0x2421: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_2424:
	/* 0x2424: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2426:
	/* 0x2426: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_242a:
	/* 0x242a: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_242d:
	/* 0x242d: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2432:
	/* 0x2432: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2438:
	/* 0x2438: jb     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1821ULL;
	}
x86_l_243e:
	/* 0x243e: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_2444:
	/* 0x2444: ja     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1821ULL;
	}
x86_l_244a:
	/* 0x244a: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_244d:
	/* 0x244d: jbe    2454 <generic_retkprobe_event+0x2454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2454;
	}
x86_l_244f:
	/* 0x244f: mov    BYTE PTR [r14+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2454:
	/* 0x2454: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2456:
	/* 0x2456: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2459:
	/* 0x2459: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_245d:
	/* 0x245d: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2460:
	/* 0x2460: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2463:
	/* 0x2463: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2466:
	/* 0x2466: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_246b:
	/* 0x246b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_246d:
	/* 0x246d: mov    QWORD PTR [rsp+0x58],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2472:
	/* 0x2472: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2475:
	/* 0x2475: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_247a:
	/* 0x247a: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2480:
	/* 0x2480: jbe    71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1821ULL;
	}
x86_l_2486:
	/* 0x2486: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_248e:
	/* 0x248e: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2493:
	/* 0x2493: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2498:
	/* 0x2498: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_249d:
	/* 0x249d: jmp    272e <generic_retkprobe_event+0x272e> */
	goto x86_l_272e;
x86_l_24a2:
	/* 0x24a2: lea    rdi,[rcx+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_24a9:
	/* 0x24a9: lea    rdx,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24ad:
	/* 0x24ad: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_24b2:
	/* 0x24b2: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_24b5:
	/* 0x24b5: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_24b8:
	/* 0x24b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24bd:
	/* 0x24bd: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_24c2:
	/* 0x24c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24c4:
	/* 0x24c4: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_24c7:
	/* 0x24c7: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_24ca:
	/* 0x24ca: add    rdi,0x9e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 158ULL);
x86_l_24d1:
	/* 0x24d1: add    r14,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_24d5:
	/* 0x24d5: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_24da:
	/* 0x24da: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24df:
	/* 0x24df: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_24e4:
	/* 0x24e4: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_24e7:
	/* 0x24e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24e9:
	/* 0x24e9: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24ee:
	/* 0x24ee: movzx  eax,WORD PTR [rcx+0x9e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_24f5:
	/* 0x24f5: movbe  WORD PTR [rcx+0x9e],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_24fe:
	/* 0x24fe: mov    ebp,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_2503:
	/* 0x2503: jmp    953 <generic_retkprobe_event+0x953> */
	return 2387ULL;
x86_l_2508:
	/* 0x2508: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_250d:
	/* 0x250d: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_2514:
	/* 0x2514: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2519:
	/* 0x2519: mov    edx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 63ULL);
x86_l_251e:
	/* 0x251e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2523:
	/* 0x2523: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2528:
	/* 0x2528: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_252d:
	/* 0x252d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_252f:
	/* 0x252f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2532:
	/* 0x2532: js     217a <generic_retkprobe_event+0x217a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8570ULL;
	}
x86_l_2538:
	/* 0x2538: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_253d:
	/* 0x253d: lea    rdx,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2541:
	/* 0x2541: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2546:
	/* 0x2546: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_254b:
	/* 0x254b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2550:
	/* 0x2550: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2555:
	/* 0x2555: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2557:
	/* 0x2557: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_255c:
	/* 0x255c: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_2563:
	/* 0x2563: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_2568:
	/* 0x2568: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_256d:
	/* 0x256d: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2570:
	/* 0x2570: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2575:
	/* 0x2575: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_257a:
	/* 0x257a: add    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 104ULL);
x86_l_257f:
	/* 0x257f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2584:
	/* 0x2584: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2586:
	/* 0x2586: lea    rdx,[r14+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_258a:
	/* 0x258a: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_258f:
	/* 0x258f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2594:
	/* 0x2594: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2599:
	/* 0x2599: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_259e:
	/* 0x259e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25a0:
	/* 0x25a0: mov    ebp,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 80ULL);
x86_l_25a5:
	/* 0x25a5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25a8:
	/* 0x25a8: jne    25b8 <generic_retkprobe_event+0x25b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25b8;
	}
x86_l_25aa:
	/* 0x25aa: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25ac:
	/* 0x25ac: cmp    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_25b1:
	/* 0x25b1: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_25b4:
	/* 0x25b4: mov    DWORD PTR [r12],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25b8:
	/* 0x25b8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25bd:
	/* 0x25bd: jmp    2669 <generic_retkprobe_event+0x2669> */
	goto x86_l_2669;
x86_l_25c2:
	/* 0x25c2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25c4:
	/* 0x25c4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25c9:
	/* 0x25c9: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25ce:
	/* 0x25ce: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_25d1:
	/* 0x25d1: jmp    2674 <generic_retkprobe_event+0x2674> */
	goto x86_l_2674;
x86_l_25d6:
	/* 0x25d6: lea    rdx,[rbp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_25da:
	/* 0x25da: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_25df:
	/* 0x25df: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25e4:
	/* 0x25e4: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_25e7:
	/* 0x25e7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_25ec:
	/* 0x25ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25ee:
	/* 0x25ee: lea    rdx,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_25f2:
	/* 0x25f2: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_25f7:
	/* 0x25f7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25fc:
	/* 0x25fc: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_25ff:
	/* 0x25ff: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2604:
	/* 0x2604: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2606:
	/* 0x2606: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_260b:
	/* 0x260b: lea    rdi,[r12+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2613:
	/* 0x2613: lea    r14,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2617:
	/* 0x2617: add    rbp,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_261b:
	/* 0x261b: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2620:
	/* 0x2620: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2625:
	/* 0x2625: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_262a:
	/* 0x262a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_262d:
	/* 0x262d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_262f:
	/* 0x262f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2632:
	/* 0x2632: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_2639:
	/* 0x2639: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_263e:
	/* 0x263e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2643:
	/* 0x2643: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2648:
	/* 0x2648: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_264b:
	/* 0x264b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_264d:
	/* 0x264d: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2650:
	/* 0x2650: movzx  eax,WORD PTR [r12+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_2659:
	/* 0x2659: movbe  WORD PTR [r12+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_2664:
	/* 0x2664: mov    ebp,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_2669:
	/* 0x2669: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_266e:
	/* 0x266e: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2674:
	/* 0x2674: mov    r12,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_267c:
	/* 0x267c: mov    eax,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2680:
	/* 0x2680: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_2682:
	/* 0x2682: jns    b2c <generic_retkprobe_event+0xb2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 2860ULL;
	}
x86_l_2688:
	/* 0x2688: jmp    964 <generic_retkprobe_event+0x964> */
	return 2404ULL;
x86_l_268d:
	/* 0x268d: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2690:
	/* 0x2690: je     2961 <generic_retkprobe_event+0x2961> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2961;
	}
x86_l_2696:
	/* 0x2696: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2699:
	/* 0x2699: je     26b6 <generic_retkprobe_event+0x26b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26b6;
	}
x86_l_269b:
	/* 0x269b: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_26a0:
	/* 0x26a0: jne    2a3f <generic_retkprobe_event+0x2a3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a3f;
	}
x86_l_26a6:
	/* 0x26a6: mov    WORD PTR [r14+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_26ad:
	/* 0x26ad: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_26b1:
	/* 0x26b1: jmp    2975 <generic_retkprobe_event+0x2975> */
	goto x86_l_2975;
x86_l_26b6:
	/* 0x26b6: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_26b9:
	/* 0x26b9: movzx  eax,BYTE PTR [r14+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_26be:
	/* 0x26be: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_26c5:
	/* 0x26c5: jmp    2970 <generic_retkprobe_event+0x2970> */
	goto x86_l_2970;
x86_l_26ca:
	/* 0x26ca: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26ce:
	/* 0x26ce: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26d3:
	/* 0x26d3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_26d8:
	/* 0x26d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26dd:
	/* 0x26dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26e2:
	/* 0x26e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26e4:
	/* 0x26e4: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_26e9:
	/* 0x26e9: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_26ee:
	/* 0x26ee: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26f3:
	/* 0x26f3: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_26f8:
	/* 0x26f8: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_26fe:
	/* 0x26fe: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2702:
	/* 0x2702: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2707:
	/* 0x2707: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_270c:
	/* 0x270c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2711:
	/* 0x2711: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2714:
	/* 0x2714: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2716:
	/* 0x2716: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_271b:
	/* 0x271b: mov    QWORD PTR [rsp+0x50],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2720:
	/* 0x2720: lea    rdx,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2724:
	/* 0x2724: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2729:
	/* 0x2729: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_272e:
	/* 0x272e: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2733:
	/* 0x2733: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2738:
	/* 0x2738: jne    2745 <generic_retkprobe_event+0x2745> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2745;
	}
x86_l_273a:
	/* 0x273a: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_273f:
	/* 0x273f: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_2745:
	/* 0x2745: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_274d:
	/* 0x274d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2752:
	/* 0x2752: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2757:
	/* 0x2757: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_275c:
	/* 0x275c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_275e:
	/* 0x275e: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_2766:
	/* 0x2766: je     2a49 <generic_retkprobe_event+0x2a49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a49;
	}
x86_l_276c:
	/* 0x276c: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2771:
	/* 0x2771: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2776:
	/* 0x2776: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_277b:
	/* 0x277b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2780:
	/* 0x2780: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2785:
	/* 0x2785: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2788:
	/* 0x2788: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_278a:
	/* 0x278a: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_278f:
	/* 0x278f: je     2a49 <generic_retkprobe_event+0x2a49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a49;
	}
x86_l_2795:
	/* 0x2795: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_279d:
	/* 0x279d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_27a2:
	/* 0x27a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27a7:
	/* 0x27a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27ac:
	/* 0x27ac: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_27af:
	/* 0x27af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27b1:
	/* 0x27b1: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_27b5:
	/* 0x27b5: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_27ba:
	/* 0x27ba: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_27bf:
	/* 0x27bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27c4:
	/* 0x27c4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_27c9:
	/* 0x27c9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_27cc:
	/* 0x27cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27ce:
	/* 0x27ce: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_27d3:
	/* 0x27d3: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_27d8:
	/* 0x27d8: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_27dc:
	/* 0x27dc: sub    rax,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_27df:
	/* 0x27df: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_27e4:
	/* 0x27e4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27e6:
	/* 0x27e6: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_27e8:
	/* 0x27e8: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_27eb:
	/* 0x27eb: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_27ee:
	/* 0x27ee: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_27f3:
	/* 0x27f3: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27f5:
	/* 0x27f5: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_27f8:
	/* 0x27f8: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_27fc:
	/* 0x27fc: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_27fe:
	/* 0x27fe: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_2802:
	/* 0x2802: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2804:
	/* 0x2804: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_2807:
	/* 0x2807: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2809:
	/* 0x2809: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_280d:
	/* 0x280d: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2810:
	/* 0x2810: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2815:
	/* 0x2815: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_281b:
	/* 0x281b: jb     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1821ULL;
	}
x86_l_2821:
	/* 0x2821: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_2827:
	/* 0x2827: ja     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1821ULL;
	}
x86_l_282d:
	/* 0x282d: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2830:
	/* 0x2830: jbe    2837 <generic_retkprobe_event+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2837;
	}
x86_l_2832:
	/* 0x2832: mov    BYTE PTR [r14+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2837:
	/* 0x2837: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2839:
	/* 0x2839: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_283c:
	/* 0x283c: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_2840:
	/* 0x2840: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2843:
	/* 0x2843: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2846:
	/* 0x2846: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2849:
	/* 0x2849: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_284e:
	/* 0x284e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2850:
	/* 0x2850: mov    QWORD PTR [rsp+0x58],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2855:
	/* 0x2855: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2858:
	/* 0x2858: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_285d:
	/* 0x285d: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2863:
	/* 0x2863: jbe    71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1821ULL;
	}
x86_l_2869:
	/* 0x2869: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2871:
	/* 0x2871: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2876:
	/* 0x2876: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_287b:
	/* 0x287b: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2880:
	/* 0x2880: jmp    2aad <generic_retkprobe_event+0x2aad> */
	return 10925ULL;
x86_l_2885:
	/* 0x2885: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2887:
	/* 0x2887: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_288c:
	/* 0x288c: cmp    QWORD PTR [rsp+0xa8],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505731ULL);
x86_l_2895:
	/* 0x2895: jne    28a4 <generic_retkprobe_event+0x28a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28a4;
	}
x86_l_2897:
	/* 0x2897: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_289a:
	/* 0x289a: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_289f:
	/* 0x289f: jmp    2cb <generic_retkprobe_event+0x2cb> */
	return 715ULL;
x86_l_28a4:
	/* 0x28a4: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_28ac:
	/* 0x28ac: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28b0:
	/* 0x28b0: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_28b5:
	/* 0x28b5: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_28bb:
	/* 0x28bb: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_28c0:
	/* 0x28c0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28c5:
	/* 0x28c5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_28ca:
	/* 0x28ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28cc:
	/* 0x28cc: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_28d1:
	/* 0x28d1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28d3:
	/* 0x28d3: js     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15444ULL;
	}
x86_l_28d9:
	/* 0x28d9: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28de:
	/* 0x28de: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28e3:
	/* 0x28e3: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_28e6:
	/* 0x28e6: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_28e9:
	/* 0x28e9: cmovb  r12,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_28ed:
	/* 0x28ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28f0:
	/* 0x28f0: cmovne rdx,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_28f4:
	/* 0x28f4: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_28f9:
	/* 0x28f9: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_2900:
	/* 0x2900: ja     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 15444ULL;
	}
x86_l_2906:
	/* 0x2906: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_2909:
	/* 0x2909: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_290e:
	/* 0x290e: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2913:
	/* 0x2913: mov    QWORD PTR [rsp+0x20],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2918:
	/* 0x2918: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_291e:
	/* 0x291e: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2921:
	/* 0x2921: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2926:
	/* 0x2926: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_292b:
	/* 0x292b: mov    rsi,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_292e:
	/* 0x292e: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2933:
	/* 0x2933: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2935:
	/* 0x2935: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_293a:
	/* 0x293a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_293c:
	/* 0x293c: js     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15444ULL;
	}
x86_l_2942:
	/* 0x2942: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2945:
	/* 0x2945: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_294b:
	/* 0x294b: je     3129 <generic_retkprobe_event+0x3129> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12585ULL;
	}
x86_l_2951:
	/* 0x2951: sub    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_2956:
	/* 0x2956: jne    3130 <generic_retkprobe_event+0x3130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12592ULL;
	}
x86_l_295c:
	/* 0x295c: jmp    2897 <generic_retkprobe_event+0x2897> */
	goto x86_l_2897;
x86_l_2961:
	/* 0x2961: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2964:
	/* 0x2964: movzx  eax,BYTE PTR [r14+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2969:
	/* 0x2969: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2970:
	/* 0x2970: mov    WORD PTR [r14+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2975:
	/* 0x2975: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2978:
	/* 0x2978: add    ax,WORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_297c:
	/* 0x297c: mov    WORD PTR [r14],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2980:
	/* 0x2980: movzx  ecx,BYTE PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2985:
	/* 0x2985: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2989:
	/* 0x2989: ja     370f <generic_retkprobe_event+0x370f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14095ULL;
	}
x86_l_298f:
	/* 0x298f: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2999:
	/* 0x2999: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_299d:
	/* 0x299d: jae    370f <generic_retkprobe_event+0x370f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14095ULL;
	}
x86_l_29a3:
	/* 0x29a3: mov    BYTE PTR [r14+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_29a7:
	/* 0x29a7: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_29aa:
	/* 0x29aa: add    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29ad:
	/* 0x29ad: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_29b2:
	/* 0x29b2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29b7:
	/* 0x29b7: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_29ba:
	/* 0x29ba: movzx  edx,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_29be:
	/* 0x29be: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29c1:
	/* 0x29c1: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_29c6:
	/* 0x29c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29c8:
	/* 0x29c8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29cb:
	/* 0x29cb: js     350c <generic_retkprobe_event+0x350c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13580ULL;
	}
x86_l_29d1:
	/* 0x29d1: movzx  eax,BYTE PTR [r14+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_29d6:
	/* 0x29d6: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_29d9:
	/* 0x29d9: jg     29fd <generic_retkprobe_event+0x29fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_29fd;
	}
x86_l_29db:
	/* 0x29db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29dd:
	/* 0x29dd: je     2a26 <generic_retkprobe_event+0x2a26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a26;
	}
x86_l_29df:
	/* 0x29df: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_29e2:
	/* 0x29e2: je     2a26 <generic_retkprobe_event+0x2a26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a26;
	}
x86_l_29e4:
	/* 0x29e4: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_29e7:
	/* 0x29e7: jne    2c1a <generic_retkprobe_event+0x2c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11290ULL;
	}
x86_l_29ed:
	/* 0x29ed: mov    WORD PTR [r14+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_29f4:
	/* 0x29f4: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_29f8:
	/* 0x29f8: jmp    2c1f <generic_retkprobe_event+0x2c1f> */
	return 11295ULL;
x86_l_29fd:
	/* 0x29fd: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2a00:
	/* 0x2a00: je     2c04 <generic_retkprobe_event+0x2c04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11268ULL;
	}
x86_l_2a06:
	/* 0x2a06: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2a09:
	/* 0x2a09: je     2a26 <generic_retkprobe_event+0x2a26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a26;
	}
x86_l_2a0b:
	/* 0x2a0b: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2a10:
	/* 0x2a10: jne    2c1a <generic_retkprobe_event+0x2c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11290ULL;
	}
x86_l_2a16:
	/* 0x2a16: mov    WORD PTR [r14+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2a1d:
	/* 0x2a1d: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2a21:
	/* 0x2a21: jmp    2c1f <generic_retkprobe_event+0x2c1f> */
	return 11295ULL;
x86_l_2a26:
	/* 0x2a26: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2a29:
	/* 0x2a29: movzx  eax,BYTE PTR [r14+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2a2e:
	/* 0x2a2e: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2a35:
	/* 0x2a35: mov    WORD PTR [r14+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2a3a:
	/* 0x2a3a: jmp    2c1f <generic_retkprobe_event+0x2c1f> */
	return 11295ULL;
x86_l_2a3f:
	/* 0x2a3f: movzx  eax,WORD PTR [r14+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2a44:
	/* 0x2a44: jmp    2975 <generic_retkprobe_event+0x2975> */
	goto x86_l_2975;
x86_l_2a49:
	/* 0x2a49: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a4d:
	/* 0x2a4d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a52:
	/* 0x2a52: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a57:
	/* 0x2a57: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a5c:
	/* 0x2a5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a61:
	/* 0x2a61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a63:
	/* 0x2a63: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a68:
	/* 0x2a68: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_2a6d:
	/* 0x2a6d: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a72:
	/* 0x2a72: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a77:
	/* 0x2a77: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_2a7d:
	/* 0x2a7d: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2a81:
	/* 0x2a81: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a86:
	/* 0x2a86: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 10891ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10891ULL: goto x86_l_2a8b;
	case 10896ULL: goto x86_l_2a90;
	case 10899ULL: goto x86_l_2a93;
	case 10901ULL: goto x86_l_2a95;
	case 10906ULL: goto x86_l_2a9a;
	case 10911ULL: goto x86_l_2a9f;
	case 10915ULL: goto x86_l_2aa3;
	case 10920ULL: goto x86_l_2aa8;
	case 10925ULL: goto x86_l_2aad;
	case 10930ULL: goto x86_l_2ab2;
	case 10935ULL: goto x86_l_2ab7;
	case 10937ULL: goto x86_l_2ab9;
	case 10942ULL: goto x86_l_2abe;
	case 10948ULL: goto x86_l_2ac4;
	case 10956ULL: goto x86_l_2acc;
	case 10961ULL: goto x86_l_2ad1;
	case 10966ULL: goto x86_l_2ad6;
	case 10971ULL: goto x86_l_2adb;
	case 10973ULL: goto x86_l_2add;
	case 10981ULL: goto x86_l_2ae5;
	case 10987ULL: goto x86_l_2aeb;
	case 10992ULL: goto x86_l_2af0;
	case 10997ULL: goto x86_l_2af5;
	case 11002ULL: goto x86_l_2afa;
	case 11007ULL: goto x86_l_2aff;
	case 11012ULL: goto x86_l_2b04;
	case 11015ULL: goto x86_l_2b07;
	case 11017ULL: goto x86_l_2b09;
	case 11022ULL: goto x86_l_2b0e;
	case 11028ULL: goto x86_l_2b14;
	case 11036ULL: goto x86_l_2b1c;
	case 11041ULL: goto x86_l_2b21;
	case 11046ULL: goto x86_l_2b26;
	case 11051ULL: goto x86_l_2b2b;
	case 11054ULL: goto x86_l_2b2e;
	case 11056ULL: goto x86_l_2b30;
	case 11060ULL: goto x86_l_2b34;
	case 11065ULL: goto x86_l_2b39;
	case 11070ULL: goto x86_l_2b3e;
	case 11075ULL: goto x86_l_2b43;
	case 11080ULL: goto x86_l_2b48;
	case 11083ULL: goto x86_l_2b4b;
	case 11085ULL: goto x86_l_2b4d;
	case 11090ULL: goto x86_l_2b52;
	case 11095ULL: goto x86_l_2b57;
	case 11099ULL: goto x86_l_2b5b;
	case 11102ULL: goto x86_l_2b5e;
	case 11107ULL: goto x86_l_2b63;
	case 11109ULL: goto x86_l_2b65;
	case 11111ULL: goto x86_l_2b67;
	case 11114ULL: goto x86_l_2b6a;
	case 11117ULL: goto x86_l_2b6d;
	case 11122ULL: goto x86_l_2b72;
	case 11124ULL: goto x86_l_2b74;
	case 11127ULL: goto x86_l_2b77;
	case 11131ULL: goto x86_l_2b7b;
	case 11133ULL: goto x86_l_2b7d;
	case 11137ULL: goto x86_l_2b81;
	case 11139ULL: goto x86_l_2b83;
	case 11142ULL: goto x86_l_2b86;
	case 11144ULL: goto x86_l_2b88;
	case 11148ULL: goto x86_l_2b8c;
	case 11151ULL: goto x86_l_2b8f;
	case 11156ULL: goto x86_l_2b94;
	case 11162ULL: goto x86_l_2b9a;
	case 11168ULL: goto x86_l_2ba0;
	case 11174ULL: goto x86_l_2ba6;
	case 11180ULL: goto x86_l_2bac;
	case 11183ULL: goto x86_l_2baf;
	case 11185ULL: goto x86_l_2bb1;
	case 11190ULL: goto x86_l_2bb6;
	case 11192ULL: goto x86_l_2bb8;
	case 11195ULL: goto x86_l_2bbb;
	case 11199ULL: goto x86_l_2bbf;
	case 11202ULL: goto x86_l_2bc2;
	case 11205ULL: goto x86_l_2bc5;
	case 11208ULL: goto x86_l_2bc8;
	case 11213ULL: goto x86_l_2bcd;
	case 11215ULL: goto x86_l_2bcf;
	case 11220ULL: goto x86_l_2bd4;
	case 11223ULL: goto x86_l_2bd7;
	case 11228ULL: goto x86_l_2bdc;
	case 11234ULL: goto x86_l_2be2;
	case 11240ULL: goto x86_l_2be8;
	case 11248ULL: goto x86_l_2bf0;
	case 11253ULL: goto x86_l_2bf5;
	case 11258ULL: goto x86_l_2bfa;
	case 11263ULL: goto x86_l_2bff;
	case 11268ULL: goto x86_l_2c04;
	case 11271ULL: goto x86_l_2c07;
	case 11276ULL: goto x86_l_2c0c;
	case 11283ULL: goto x86_l_2c13;
	case 11288ULL: goto x86_l_2c18;
	case 11290ULL: goto x86_l_2c1a;
	case 11295ULL: goto x86_l_2c1f;
	case 11298ULL: goto x86_l_2c22;
	case 11302ULL: goto x86_l_2c26;
	case 11306ULL: goto x86_l_2c2a;
	case 11311ULL: goto x86_l_2c2f;
	case 11315ULL: goto x86_l_2c33;
	case 11321ULL: goto x86_l_2c39;
	case 11331ULL: goto x86_l_2c43;
	case 11335ULL: goto x86_l_2c47;
	case 11341ULL: goto x86_l_2c4d;
	case 11345ULL: goto x86_l_2c51;
	case 11348ULL: goto x86_l_2c54;
	case 11351ULL: goto x86_l_2c57;
	case 11356ULL: goto x86_l_2c5c;
	case 11361ULL: goto x86_l_2c61;
	case 11364ULL: goto x86_l_2c64;
	case 11368ULL: goto x86_l_2c68;
	case 11371ULL: goto x86_l_2c6b;
	case 11376ULL: goto x86_l_2c70;
	case 11378ULL: goto x86_l_2c72;
	case 11381ULL: goto x86_l_2c75;
	case 11387ULL: goto x86_l_2c7b;
	case 11392ULL: goto x86_l_2c80;
	case 11395ULL: goto x86_l_2c83;
	case 11397ULL: goto x86_l_2c85;
	case 11399ULL: goto x86_l_2c87;
	case 11401ULL: goto x86_l_2c89;
	case 11404ULL: goto x86_l_2c8c;
	case 11406ULL: goto x86_l_2c8e;
	case 11409ULL: goto x86_l_2c91;
	case 11411ULL: goto x86_l_2c93;
	case 11418ULL: goto x86_l_2c9a;
	case 11422ULL: goto x86_l_2c9e;
	case 11424ULL: goto x86_l_2ca0;
	case 11427ULL: goto x86_l_2ca3;
	case 11429ULL: goto x86_l_2ca5;
	case 11432ULL: goto x86_l_2ca8;
	case 11434ULL: goto x86_l_2caa;
	case 11439ULL: goto x86_l_2caf;
	case 11441ULL: goto x86_l_2cb1;
	case 11448ULL: goto x86_l_2cb8;
	case 11452ULL: goto x86_l_2cbc;
	case 11454ULL: goto x86_l_2cbe;
	case 11457ULL: goto x86_l_2cc1;
	case 11462ULL: goto x86_l_2cc6;
	case 11469ULL: goto x86_l_2ccd;
	case 11474ULL: goto x86_l_2cd2;
	case 11476ULL: goto x86_l_2cd4;
	case 11479ULL: goto x86_l_2cd7;
	case 11484ULL: goto x86_l_2cdc;
	case 11491ULL: goto x86_l_2ce3;
	case 11496ULL: goto x86_l_2ce8;
	case 11498ULL: goto x86_l_2cea;
	case 11503ULL: goto x86_l_2cef;
	case 11506ULL: goto x86_l_2cf2;
	case 11510ULL: goto x86_l_2cf6;
	case 11514ULL: goto x86_l_2cfa;
	case 11519ULL: goto x86_l_2cff;
	case 11523ULL: goto x86_l_2d03;
	case 11529ULL: goto x86_l_2d09;
	case 11539ULL: goto x86_l_2d13;
	case 11543ULL: goto x86_l_2d17;
	case 11549ULL: goto x86_l_2d1d;
	case 11553ULL: goto x86_l_2d21;
	case 11556ULL: goto x86_l_2d24;
	case 11559ULL: goto x86_l_2d27;
	case 11564ULL: goto x86_l_2d2c;
	case 11569ULL: goto x86_l_2d31;
	case 11572ULL: goto x86_l_2d34;
	case 11576ULL: goto x86_l_2d38;
	case 11579ULL: goto x86_l_2d3b;
	case 11584ULL: goto x86_l_2d40;
	case 11586ULL: goto x86_l_2d42;
	case 11589ULL: goto x86_l_2d45;
	case 11595ULL: goto x86_l_2d4b;
	case 11600ULL: goto x86_l_2d50;
	case 11603ULL: goto x86_l_2d53;
	case 11605ULL: goto x86_l_2d55;
	case 11607ULL: goto x86_l_2d57;
	case 11609ULL: goto x86_l_2d59;
	case 11612ULL: goto x86_l_2d5c;
	case 11614ULL: goto x86_l_2d5e;
	case 11617ULL: goto x86_l_2d61;
	case 11619ULL: goto x86_l_2d63;
	case 11626ULL: goto x86_l_2d6a;
	case 11630ULL: goto x86_l_2d6e;
	case 11632ULL: goto x86_l_2d70;
	case 11635ULL: goto x86_l_2d73;
	case 11637ULL: goto x86_l_2d75;
	case 11640ULL: goto x86_l_2d78;
	case 11642ULL: goto x86_l_2d7a;
	case 11647ULL: goto x86_l_2d7f;
	case 11649ULL: goto x86_l_2d81;
	case 11656ULL: goto x86_l_2d88;
	case 11660ULL: goto x86_l_2d8c;
	case 11662ULL: goto x86_l_2d8e;
	case 11665ULL: goto x86_l_2d91;
	case 11670ULL: goto x86_l_2d96;
	case 11677ULL: goto x86_l_2d9d;
	case 11682ULL: goto x86_l_2da2;
	case 11684ULL: goto x86_l_2da4;
	case 11687ULL: goto x86_l_2da7;
	case 11692ULL: goto x86_l_2dac;
	case 11699ULL: goto x86_l_2db3;
	case 11704ULL: goto x86_l_2db8;
	case 11706ULL: goto x86_l_2dba;
	case 11711ULL: goto x86_l_2dbf;
	case 11714ULL: goto x86_l_2dc2;
	case 11718ULL: goto x86_l_2dc6;
	case 11722ULL: goto x86_l_2dca;
	case 11727ULL: goto x86_l_2dcf;
	case 11731ULL: goto x86_l_2dd3;
	case 11737ULL: goto x86_l_2dd9;
	case 11747ULL: goto x86_l_2de3;
	case 11751ULL: goto x86_l_2de7;
	case 11757ULL: goto x86_l_2ded;
	case 11761ULL: goto x86_l_2df1;
	case 11764ULL: goto x86_l_2df4;
	case 11767ULL: goto x86_l_2df7;
	case 11772ULL: goto x86_l_2dfc;
	case 11777ULL: goto x86_l_2e01;
	case 11780ULL: goto x86_l_2e04;
	case 11784ULL: goto x86_l_2e08;
	case 11787ULL: goto x86_l_2e0b;
	case 11792ULL: goto x86_l_2e10;
	case 11794ULL: goto x86_l_2e12;
	case 11797ULL: goto x86_l_2e15;
	case 11803ULL: goto x86_l_2e1b;
	case 11808ULL: goto x86_l_2e20;
	case 11811ULL: goto x86_l_2e23;
	case 11813ULL: goto x86_l_2e25;
	case 11815ULL: goto x86_l_2e27;
	case 11817ULL: goto x86_l_2e29;
	case 11820ULL: goto x86_l_2e2c;
	case 11822ULL: goto x86_l_2e2e;
	case 11825ULL: goto x86_l_2e31;
	case 11831ULL: goto x86_l_2e37;
	case 11838ULL: goto x86_l_2e3e;
	case 11842ULL: goto x86_l_2e42;
	case 11847ULL: goto x86_l_2e47;
	case 11850ULL: goto x86_l_2e4a;
	case 11856ULL: goto x86_l_2e50;
	case 11859ULL: goto x86_l_2e53;
	case 11861ULL: goto x86_l_2e55;
	case 11866ULL: goto x86_l_2e5a;
	case 11872ULL: goto x86_l_2e60;
	case 11879ULL: goto x86_l_2e67;
	case 11883ULL: goto x86_l_2e6b;
	case 11888ULL: goto x86_l_2e70;
	case 11891ULL: goto x86_l_2e73;
	case 11896ULL: goto x86_l_2e78;
	case 11903ULL: goto x86_l_2e7f;
	case 11908ULL: goto x86_l_2e84;
	case 11913ULL: goto x86_l_2e89;
	case 11917ULL: goto x86_l_2e8d;
	case 11922ULL: goto x86_l_2e92;
	case 11927ULL: goto x86_l_2e97;
	case 11932ULL: goto x86_l_2e9c;
	case 11937ULL: goto x86_l_2ea1;
	case 11939ULL: goto x86_l_2ea3;
	case 11944ULL: goto x86_l_2ea8;
	case 11949ULL: goto x86_l_2ead;
	case 11954ULL: goto x86_l_2eb2;
	case 11959ULL: goto x86_l_2eb7;
	case 11965ULL: goto x86_l_2ebd;
	case 11969ULL: goto x86_l_2ec1;
	case 11974ULL: goto x86_l_2ec6;
	case 11979ULL: goto x86_l_2ecb;
	case 11984ULL: goto x86_l_2ed0;
	case 11987ULL: goto x86_l_2ed3;
	case 11989ULL: goto x86_l_2ed5;
	case 11994ULL: goto x86_l_2eda;
	case 11999ULL: goto x86_l_2edf;
	case 12003ULL: goto x86_l_2ee3;
	case 12008ULL: goto x86_l_2ee8;
	case 12013ULL: goto x86_l_2eed;
	case 12018ULL: goto x86_l_2ef2;
	case 12023ULL: goto x86_l_2ef7;
	case 12025ULL: goto x86_l_2ef9;
	case 12030ULL: goto x86_l_2efe;
	case 12036ULL: goto x86_l_2f04;
	case 12044ULL: goto x86_l_2f0c;
	case 12049ULL: goto x86_l_2f11;
	case 12054ULL: goto x86_l_2f16;
	case 12059ULL: goto x86_l_2f1b;
	case 12061ULL: goto x86_l_2f1d;
	case 12069ULL: goto x86_l_2f25;
	case 12075ULL: goto x86_l_2f2b;
	case 12080ULL: goto x86_l_2f30;
	case 12085ULL: goto x86_l_2f35;
	case 12090ULL: goto x86_l_2f3a;
	case 12095ULL: goto x86_l_2f3f;
	case 12100ULL: goto x86_l_2f44;
	case 12103ULL: goto x86_l_2f47;
	case 12105ULL: goto x86_l_2f49;
	case 12110ULL: goto x86_l_2f4e;
	case 12116ULL: goto x86_l_2f54;
	case 12124ULL: goto x86_l_2f5c;
	case 12129ULL: goto x86_l_2f61;
	case 12134ULL: goto x86_l_2f66;
	case 12139ULL: goto x86_l_2f6b;
	case 12142ULL: goto x86_l_2f6e;
	case 12144ULL: goto x86_l_2f70;
	case 12148ULL: goto x86_l_2f74;
	case 12153ULL: goto x86_l_2f79;
	case 12158ULL: goto x86_l_2f7e;
	case 12163ULL: goto x86_l_2f83;
	case 12168ULL: goto x86_l_2f88;
	case 12171ULL: goto x86_l_2f8b;
	case 12173ULL: goto x86_l_2f8d;
	case 12178ULL: goto x86_l_2f92;
	case 12183ULL: goto x86_l_2f97;
	case 12187ULL: goto x86_l_2f9b;
	case 12190ULL: goto x86_l_2f9e;
	case 12195ULL: goto x86_l_2fa3;
	case 12197ULL: goto x86_l_2fa5;
	case 12199ULL: goto x86_l_2fa7;
	case 12202ULL: goto x86_l_2faa;
	case 12205ULL: goto x86_l_2fad;
	case 12210ULL: goto x86_l_2fb2;
	case 12212ULL: goto x86_l_2fb4;
	case 12215ULL: goto x86_l_2fb7;
	case 12219ULL: goto x86_l_2fbb;
	case 12221ULL: goto x86_l_2fbd;
	case 12225ULL: goto x86_l_2fc1;
	case 12227ULL: goto x86_l_2fc3;
	case 12230ULL: goto x86_l_2fc6;
	case 12232ULL: goto x86_l_2fc8;
	case 12236ULL: goto x86_l_2fcc;
	case 12239ULL: goto x86_l_2fcf;
	case 12244ULL: goto x86_l_2fd4;
	case 12250ULL: goto x86_l_2fda;
	case 12256ULL: goto x86_l_2fe0;
	case 12262ULL: goto x86_l_2fe6;
	case 12268ULL: goto x86_l_2fec;
	case 12271ULL: goto x86_l_2fef;
	case 12273ULL: goto x86_l_2ff1;
	case 12278ULL: goto x86_l_2ff6;
	case 12280ULL: goto x86_l_2ff8;
	case 12283ULL: goto x86_l_2ffb;
	case 12287ULL: goto x86_l_2fff;
	case 12290ULL: goto x86_l_3002;
	case 12293ULL: goto x86_l_3005;
	case 12296ULL: goto x86_l_3008;
	case 12301ULL: goto x86_l_300d;
	case 12303ULL: goto x86_l_300f;
	case 12308ULL: goto x86_l_3014;
	case 12311ULL: goto x86_l_3017;
	case 12316ULL: goto x86_l_301c;
	case 12322ULL: goto x86_l_3022;
	case 12328ULL: goto x86_l_3028;
	case 12336ULL: goto x86_l_3030;
	case 12341ULL: goto x86_l_3035;
	case 12346ULL: goto x86_l_303a;
	case 12351ULL: goto x86_l_303f;
	case 12356ULL: goto x86_l_3044;
	case 12359ULL: goto x86_l_3047;
	case 12364ULL: goto x86_l_304c;
	case 12371ULL: goto x86_l_3053;
	case 12376ULL: goto x86_l_3058;
	case 12378ULL: goto x86_l_305a;
	case 12383ULL: goto x86_l_305f;
	case 12386ULL: goto x86_l_3062;
	case 12390ULL: goto x86_l_3066;
	case 12394ULL: goto x86_l_306a;
	case 12399ULL: goto x86_l_306f;
	case 12403ULL: goto x86_l_3073;
	case 12409ULL: goto x86_l_3079;
	case 12419ULL: goto x86_l_3083;
	case 12423ULL: goto x86_l_3087;
	case 12429ULL: goto x86_l_308d;
	case 12433ULL: goto x86_l_3091;
	case 12436ULL: goto x86_l_3094;
	case 12439ULL: goto x86_l_3097;
	case 12444ULL: goto x86_l_309c;
	case 12449ULL: goto x86_l_30a1;
	case 12452ULL: goto x86_l_30a4;
	case 12456ULL: goto x86_l_30a8;
	case 12459ULL: goto x86_l_30ab;
	case 12464ULL: goto x86_l_30b0;
	case 12466ULL: goto x86_l_30b2;
	case 12469ULL: goto x86_l_30b5;
	case 12475ULL: goto x86_l_30bb;
	case 12480ULL: goto x86_l_30c0;
	case 12483ULL: goto x86_l_30c3;
	case 12485ULL: goto x86_l_30c5;
	case 12487ULL: goto x86_l_30c7;
	case 12489ULL: goto x86_l_30c9;
	case 12492ULL: goto x86_l_30cc;
	case 12494ULL: goto x86_l_30ce;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a8b:
	/* 0x2a8b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a90:
	/* 0x2a90: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2a93:
	/* 0x2a93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a95:
	/* 0x2a95: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a9a:
	/* 0x2a9a: mov    QWORD PTR [rsp+0x50],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a9f:
	/* 0x2a9f: lea    rdx,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2aa3:
	/* 0x2aa3: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2aa8:
	/* 0x2aa8: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2aad:
	/* 0x2aad: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2ab2:
	/* 0x2ab2: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ab7:
	/* 0x2ab7: jne    2ac4 <generic_retkprobe_event+0x2ac4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ac4;
	}
x86_l_2ab9:
	/* 0x2ab9: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2abe:
	/* 0x2abe: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_2ac4:
	/* 0x2ac4: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2acc:
	/* 0x2acc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ad1:
	/* 0x2ad1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ad6:
	/* 0x2ad6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2adb:
	/* 0x2adb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2add:
	/* 0x2add: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_2ae5:
	/* 0x2ae5: je     2e89 <generic_retkprobe_event+0x2e89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e89;
	}
x86_l_2aeb:
	/* 0x2aeb: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2af0:
	/* 0x2af0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2af5:
	/* 0x2af5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2afa:
	/* 0x2afa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2aff:
	/* 0x2aff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b04:
	/* 0x2b04: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2b07:
	/* 0x2b07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b09:
	/* 0x2b09: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b0e:
	/* 0x2b0e: je     2e89 <generic_retkprobe_event+0x2e89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e89;
	}
x86_l_2b14:
	/* 0x2b14: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2b1c:
	/* 0x2b1c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b21:
	/* 0x2b21: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b26:
	/* 0x2b26: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b2b:
	/* 0x2b2b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2b2e:
	/* 0x2b2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b30:
	/* 0x2b30: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2b34:
	/* 0x2b34: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2b39:
	/* 0x2b39: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2b3e:
	/* 0x2b3e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b43:
	/* 0x2b43: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2b48:
	/* 0x2b48: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2b4b:
	/* 0x2b4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b4d:
	/* 0x2b4d: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b52:
	/* 0x2b52: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2b57:
	/* 0x2b57: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_2b5b:
	/* 0x2b5b: sub    rax,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2b5e:
	/* 0x2b5e: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2b63:
	/* 0x2b63: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b65:
	/* 0x2b65: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_2b67:
	/* 0x2b67: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b6a:
	/* 0x2b6a: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2b6d:
	/* 0x2b6d: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_2b72:
	/* 0x2b72: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b74:
	/* 0x2b74: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2b77:
	/* 0x2b77: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_2b7b:
	/* 0x2b7b: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2b7d:
	/* 0x2b7d: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_2b81:
	/* 0x2b81: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2b83:
	/* 0x2b83: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_2b86:
	/* 0x2b86: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b88:
	/* 0x2b88: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2b8c:
	/* 0x2b8c: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2b8f:
	/* 0x2b8f: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b94:
	/* 0x2b94: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2b9a:
	/* 0x2b9a: jb     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1821ULL;
	}
x86_l_2ba0:
	/* 0x2ba0: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_2ba6:
	/* 0x2ba6: ja     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1821ULL;
	}
x86_l_2bac:
	/* 0x2bac: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2baf:
	/* 0x2baf: jbe    2bb6 <generic_retkprobe_event+0x2bb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2bb6;
	}
x86_l_2bb1:
	/* 0x2bb1: mov    BYTE PTR [r14+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2bb6:
	/* 0x2bb6: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bb8:
	/* 0x2bb8: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2bbb:
	/* 0x2bbb: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_2bbf:
	/* 0x2bbf: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2bc2:
	/* 0x2bc2: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2bc5:
	/* 0x2bc5: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2bc8:
	/* 0x2bc8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bcd:
	/* 0x2bcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bcf:
	/* 0x2bcf: mov    QWORD PTR [rsp+0x58],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2bd4:
	/* 0x2bd4: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2bd7:
	/* 0x2bd7: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2bdc:
	/* 0x2bdc: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2be2:
	/* 0x2be2: jbe    71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1821ULL;
	}
x86_l_2be8:
	/* 0x2be8: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2bf0:
	/* 0x2bf0: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bf5:
	/* 0x2bf5: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2bfa:
	/* 0x2bfa: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2bff:
	/* 0x2bff: jmp    2eed <generic_retkprobe_event+0x2eed> */
	goto x86_l_2eed;
x86_l_2c04:
	/* 0x2c04: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2c07:
	/* 0x2c07: movzx  eax,BYTE PTR [r14+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2c0c:
	/* 0x2c0c: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2c13:
	/* 0x2c13: mov    WORD PTR [r14+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2c18:
	/* 0x2c18: jmp    2c1f <generic_retkprobe_event+0x2c1f> */
	goto x86_l_2c1f;
x86_l_2c1a:
	/* 0x2c1a: movzx  eax,WORD PTR [r14+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2c1f:
	/* 0x2c1f: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2c22:
	/* 0x2c22: add    ax,WORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2c26:
	/* 0x2c26: mov    WORD PTR [r14],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c2a:
	/* 0x2c2a: movzx  ecx,BYTE PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2c2f:
	/* 0x2c2f: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2c33:
	/* 0x2c33: ja     370f <generic_retkprobe_event+0x370f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14095ULL;
	}
x86_l_2c39:
	/* 0x2c39: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2c43:
	/* 0x2c43: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2c47:
	/* 0x2c47: jae    370f <generic_retkprobe_event+0x370f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14095ULL;
	}
x86_l_2c4d:
	/* 0x2c4d: mov    BYTE PTR [r14+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2c51:
	/* 0x2c51: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2c54:
	/* 0x2c54: add    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c57:
	/* 0x2c57: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2c5c:
	/* 0x2c5c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c61:
	/* 0x2c61: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2c64:
	/* 0x2c64: movzx  edx,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c68:
	/* 0x2c68: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c6b:
	/* 0x2c6b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2c70:
	/* 0x2c70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c72:
	/* 0x2c72: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c75:
	/* 0x2c75: js     350c <generic_retkprobe_event+0x350c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13580ULL;
	}
x86_l_2c7b:
	/* 0x2c7b: movzx  eax,BYTE PTR [r14+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2c80:
	/* 0x2c80: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2c83:
	/* 0x2c83: jg     2ca0 <generic_retkprobe_event+0x2ca0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2ca0;
	}
x86_l_2c85:
	/* 0x2c85: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c87:
	/* 0x2c87: je     2cbe <generic_retkprobe_event+0x2cbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cbe;
	}
x86_l_2c89:
	/* 0x2c89: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2c8c:
	/* 0x2c8c: je     2cbe <generic_retkprobe_event+0x2cbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cbe;
	}
x86_l_2c8e:
	/* 0x2c8e: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2c91:
	/* 0x2c91: jne    2cea <generic_retkprobe_event+0x2cea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cea;
	}
x86_l_2c93:
	/* 0x2c93: mov    WORD PTR [r14+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2c9a:
	/* 0x2c9a: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2c9e:
	/* 0x2c9e: jmp    2cef <generic_retkprobe_event+0x2cef> */
	goto x86_l_2cef;
x86_l_2ca0:
	/* 0x2ca0: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2ca3:
	/* 0x2ca3: je     2cd4 <generic_retkprobe_event+0x2cd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cd4;
	}
x86_l_2ca5:
	/* 0x2ca5: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2ca8:
	/* 0x2ca8: je     2cbe <generic_retkprobe_event+0x2cbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cbe;
	}
x86_l_2caa:
	/* 0x2caa: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2caf:
	/* 0x2caf: jne    2cea <generic_retkprobe_event+0x2cea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cea;
	}
x86_l_2cb1:
	/* 0x2cb1: mov    WORD PTR [r14+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2cb8:
	/* 0x2cb8: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2cbc:
	/* 0x2cbc: jmp    2cef <generic_retkprobe_event+0x2cef> */
	goto x86_l_2cef;
x86_l_2cbe:
	/* 0x2cbe: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2cc1:
	/* 0x2cc1: movzx  eax,BYTE PTR [r14+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2cc6:
	/* 0x2cc6: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2ccd:
	/* 0x2ccd: mov    WORD PTR [r14+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2cd2:
	/* 0x2cd2: jmp    2cef <generic_retkprobe_event+0x2cef> */
	goto x86_l_2cef;
x86_l_2cd4:
	/* 0x2cd4: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2cd7:
	/* 0x2cd7: movzx  eax,BYTE PTR [r14+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2cdc:
	/* 0x2cdc: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2ce3:
	/* 0x2ce3: mov    WORD PTR [r14+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2ce8:
	/* 0x2ce8: jmp    2cef <generic_retkprobe_event+0x2cef> */
	goto x86_l_2cef;
x86_l_2cea:
	/* 0x2cea: movzx  eax,WORD PTR [r14+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2cef:
	/* 0x2cef: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2cf2:
	/* 0x2cf2: add    ax,WORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2cf6:
	/* 0x2cf6: mov    WORD PTR [r14],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cfa:
	/* 0x2cfa: movzx  ecx,BYTE PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2cff:
	/* 0x2cff: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2d03:
	/* 0x2d03: ja     370f <generic_retkprobe_event+0x370f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14095ULL;
	}
x86_l_2d09:
	/* 0x2d09: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2d13:
	/* 0x2d13: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2d17:
	/* 0x2d17: jae    370f <generic_retkprobe_event+0x370f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14095ULL;
	}
x86_l_2d1d:
	/* 0x2d1d: mov    BYTE PTR [r14+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2d21:
	/* 0x2d21: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2d24:
	/* 0x2d24: add    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d27:
	/* 0x2d27: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2d2c:
	/* 0x2d2c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d31:
	/* 0x2d31: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2d34:
	/* 0x2d34: movzx  edx,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d38:
	/* 0x2d38: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d3b:
	/* 0x2d3b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2d40:
	/* 0x2d40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d42:
	/* 0x2d42: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d45:
	/* 0x2d45: js     350c <generic_retkprobe_event+0x350c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13580ULL;
	}
x86_l_2d4b:
	/* 0x2d4b: movzx  eax,BYTE PTR [r14+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2d50:
	/* 0x2d50: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2d53:
	/* 0x2d53: jg     2d70 <generic_retkprobe_event+0x2d70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2d70;
	}
x86_l_2d55:
	/* 0x2d55: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d57:
	/* 0x2d57: je     2d8e <generic_retkprobe_event+0x2d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d8e;
	}
x86_l_2d59:
	/* 0x2d59: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2d5c:
	/* 0x2d5c: je     2d8e <generic_retkprobe_event+0x2d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d8e;
	}
x86_l_2d5e:
	/* 0x2d5e: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2d61:
	/* 0x2d61: jne    2dba <generic_retkprobe_event+0x2dba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2dba;
	}
x86_l_2d63:
	/* 0x2d63: mov    WORD PTR [r14+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2d6a:
	/* 0x2d6a: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2d6e:
	/* 0x2d6e: jmp    2dbf <generic_retkprobe_event+0x2dbf> */
	goto x86_l_2dbf;
x86_l_2d70:
	/* 0x2d70: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2d73:
	/* 0x2d73: je     2da4 <generic_retkprobe_event+0x2da4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2da4;
	}
x86_l_2d75:
	/* 0x2d75: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2d78:
	/* 0x2d78: je     2d8e <generic_retkprobe_event+0x2d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d8e;
	}
x86_l_2d7a:
	/* 0x2d7a: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2d7f:
	/* 0x2d7f: jne    2dba <generic_retkprobe_event+0x2dba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2dba;
	}
x86_l_2d81:
	/* 0x2d81: mov    WORD PTR [r14+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2d88:
	/* 0x2d88: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2d8c:
	/* 0x2d8c: jmp    2dbf <generic_retkprobe_event+0x2dbf> */
	goto x86_l_2dbf;
x86_l_2d8e:
	/* 0x2d8e: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2d91:
	/* 0x2d91: movzx  eax,BYTE PTR [r14+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2d96:
	/* 0x2d96: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2d9d:
	/* 0x2d9d: mov    WORD PTR [r14+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2da2:
	/* 0x2da2: jmp    2dbf <generic_retkprobe_event+0x2dbf> */
	goto x86_l_2dbf;
x86_l_2da4:
	/* 0x2da4: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2da7:
	/* 0x2da7: movzx  eax,BYTE PTR [r14+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2dac:
	/* 0x2dac: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2db3:
	/* 0x2db3: mov    WORD PTR [r14+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2db8:
	/* 0x2db8: jmp    2dbf <generic_retkprobe_event+0x2dbf> */
	goto x86_l_2dbf;
x86_l_2dba:
	/* 0x2dba: movzx  eax,WORD PTR [r14+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2dbf:
	/* 0x2dbf: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2dc2:
	/* 0x2dc2: add    ax,WORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2dc6:
	/* 0x2dc6: mov    WORD PTR [r14],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dca:
	/* 0x2dca: movzx  ecx,BYTE PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2dcf:
	/* 0x2dcf: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2dd3:
	/* 0x2dd3: ja     370f <generic_retkprobe_event+0x370f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14095ULL;
	}
x86_l_2dd9:
	/* 0x2dd9: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2de3:
	/* 0x2de3: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2de7:
	/* 0x2de7: jae    370f <generic_retkprobe_event+0x370f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14095ULL;
	}
x86_l_2ded:
	/* 0x2ded: mov    BYTE PTR [r14+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2df1:
	/* 0x2df1: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2df4:
	/* 0x2df4: add    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2df7:
	/* 0x2df7: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2dfc:
	/* 0x2dfc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e01:
	/* 0x2e01: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2e04:
	/* 0x2e04: movzx  edx,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e08:
	/* 0x2e08: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e0b:
	/* 0x2e0b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2e10:
	/* 0x2e10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e12:
	/* 0x2e12: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e15:
	/* 0x2e15: js     350c <generic_retkprobe_event+0x350c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13580ULL;
	}
x86_l_2e1b:
	/* 0x2e1b: movzx  eax,BYTE PTR [r14+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2e20:
	/* 0x2e20: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2e23:
	/* 0x2e23: jg     2e47 <generic_retkprobe_event+0x2e47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2e47;
	}
x86_l_2e25:
	/* 0x2e25: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e27:
	/* 0x2e27: je     2e70 <generic_retkprobe_event+0x2e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e70;
	}
x86_l_2e29:
	/* 0x2e29: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2e2c:
	/* 0x2e2c: je     2e70 <generic_retkprobe_event+0x2e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e70;
	}
x86_l_2e2e:
	/* 0x2e2e: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2e31:
	/* 0x2e31: jne    305a <generic_retkprobe_event+0x305a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_305a;
	}
x86_l_2e37:
	/* 0x2e37: mov    WORD PTR [r14+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2e3e:
	/* 0x2e3e: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2e42:
	/* 0x2e42: jmp    305f <generic_retkprobe_event+0x305f> */
	goto x86_l_305f;
x86_l_2e47:
	/* 0x2e47: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2e4a:
	/* 0x2e4a: je     3044 <generic_retkprobe_event+0x3044> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3044;
	}
x86_l_2e50:
	/* 0x2e50: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2e53:
	/* 0x2e53: je     2e70 <generic_retkprobe_event+0x2e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e70;
	}
x86_l_2e55:
	/* 0x2e55: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2e5a:
	/* 0x2e5a: jne    305a <generic_retkprobe_event+0x305a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_305a;
	}
x86_l_2e60:
	/* 0x2e60: mov    WORD PTR [r14+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2e67:
	/* 0x2e67: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2e6b:
	/* 0x2e6b: jmp    305f <generic_retkprobe_event+0x305f> */
	goto x86_l_305f;
x86_l_2e70:
	/* 0x2e70: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2e73:
	/* 0x2e73: movzx  eax,BYTE PTR [r14+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2e78:
	/* 0x2e78: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2e7f:
	/* 0x2e7f: mov    WORD PTR [r14+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2e84:
	/* 0x2e84: jmp    305f <generic_retkprobe_event+0x305f> */
	goto x86_l_305f;
x86_l_2e89:
	/* 0x2e89: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e8d:
	/* 0x2e8d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e92:
	/* 0x2e92: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e97:
	/* 0x2e97: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e9c:
	/* 0x2e9c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ea1:
	/* 0x2ea1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ea3:
	/* 0x2ea3: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2ea8:
	/* 0x2ea8: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_2ead:
	/* 0x2ead: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2eb2:
	/* 0x2eb2: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2eb7:
	/* 0x2eb7: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_2ebd:
	/* 0x2ebd: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2ec1:
	/* 0x2ec1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ec6:
	/* 0x2ec6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ecb:
	/* 0x2ecb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ed0:
	/* 0x2ed0: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2ed3:
	/* 0x2ed3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ed5:
	/* 0x2ed5: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eda:
	/* 0x2eda: mov    QWORD PTR [rsp+0x50],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2edf:
	/* 0x2edf: lea    rdx,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ee3:
	/* 0x2ee3: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2ee8:
	/* 0x2ee8: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2eed:
	/* 0x2eed: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2ef2:
	/* 0x2ef2: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ef7:
	/* 0x2ef7: jne    2f04 <generic_retkprobe_event+0x2f04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f04;
	}
x86_l_2ef9:
	/* 0x2ef9: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2efe:
	/* 0x2efe: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_2f04:
	/* 0x2f04: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2f0c:
	/* 0x2f0c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f11:
	/* 0x2f11: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f16:
	/* 0x2f16: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f1b:
	/* 0x2f1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f1d:
	/* 0x2f1d: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_2f25:
	/* 0x2f25: je     32e3 <generic_retkprobe_event+0x32e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13027ULL;
	}
x86_l_2f2b:
	/* 0x2f2b: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f30:
	/* 0x2f30: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f35:
	/* 0x2f35: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f3a:
	/* 0x2f3a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f3f:
	/* 0x2f3f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f44:
	/* 0x2f44: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2f47:
	/* 0x2f47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f49:
	/* 0x2f49: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f4e:
	/* 0x2f4e: je     32e3 <generic_retkprobe_event+0x32e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13027ULL;
	}
x86_l_2f54:
	/* 0x2f54: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2f5c:
	/* 0x2f5c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f61:
	/* 0x2f61: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f66:
	/* 0x2f66: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f6b:
	/* 0x2f6b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2f6e:
	/* 0x2f6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f70:
	/* 0x2f70: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2f74:
	/* 0x2f74: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2f79:
	/* 0x2f79: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2f7e:
	/* 0x2f7e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f83:
	/* 0x2f83: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2f88:
	/* 0x2f88: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2f8b:
	/* 0x2f8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f8d:
	/* 0x2f8d: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f92:
	/* 0x2f92: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2f97:
	/* 0x2f97: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_2f9b:
	/* 0x2f9b: sub    rax,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2f9e:
	/* 0x2f9e: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2fa3:
	/* 0x2fa3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fa5:
	/* 0x2fa5: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_2fa7:
	/* 0x2fa7: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2faa:
	/* 0x2faa: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2fad:
	/* 0x2fad: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_2fb2:
	/* 0x2fb2: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fb4:
	/* 0x2fb4: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2fb7:
	/* 0x2fb7: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_2fbb:
	/* 0x2fbb: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2fbd:
	/* 0x2fbd: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_2fc1:
	/* 0x2fc1: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2fc3:
	/* 0x2fc3: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_2fc6:
	/* 0x2fc6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2fc8:
	/* 0x2fc8: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2fcc:
	/* 0x2fcc: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2fcf:
	/* 0x2fcf: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fd4:
	/* 0x2fd4: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2fda:
	/* 0x2fda: jb     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1821ULL;
	}
x86_l_2fe0:
	/* 0x2fe0: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_2fe6:
	/* 0x2fe6: ja     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1821ULL;
	}
x86_l_2fec:
	/* 0x2fec: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2fef:
	/* 0x2fef: jbe    2ff6 <generic_retkprobe_event+0x2ff6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2ff6;
	}
x86_l_2ff1:
	/* 0x2ff1: mov    BYTE PTR [r14+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2ff6:
	/* 0x2ff6: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ff8:
	/* 0x2ff8: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2ffb:
	/* 0x2ffb: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_2fff:
	/* 0x2fff: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3002:
	/* 0x3002: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3005:
	/* 0x3005: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3008:
	/* 0x3008: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_300d:
	/* 0x300d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_300f:
	/* 0x300f: mov    QWORD PTR [rsp+0x58],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3014:
	/* 0x3014: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3017:
	/* 0x3017: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_301c:
	/* 0x301c: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_3022:
	/* 0x3022: jbe    71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1821ULL;
	}
x86_l_3028:
	/* 0x3028: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3030:
	/* 0x3030: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3035:
	/* 0x3035: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_303a:
	/* 0x303a: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_303f:
	/* 0x303f: jmp    3347 <generic_retkprobe_event+0x3347> */
	return 13127ULL;
x86_l_3044:
	/* 0x3044: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_3047:
	/* 0x3047: movzx  eax,BYTE PTR [r14+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_304c:
	/* 0x304c: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_3053:
	/* 0x3053: mov    WORD PTR [r14+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3058:
	/* 0x3058: jmp    305f <generic_retkprobe_event+0x305f> */
	goto x86_l_305f;
x86_l_305a:
	/* 0x305a: movzx  eax,WORD PTR [r14+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_305f:
	/* 0x305f: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_3062:
	/* 0x3062: add    ax,WORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3066:
	/* 0x3066: mov    WORD PTR [r14],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_306a:
	/* 0x306a: movzx  ecx,BYTE PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_306f:
	/* 0x306f: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_3073:
	/* 0x3073: ja     370f <generic_retkprobe_event+0x370f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14095ULL;
	}
x86_l_3079:
	/* 0x3079: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_3083:
	/* 0x3083: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_3087:
	/* 0x3087: jae    370f <generic_retkprobe_event+0x370f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14095ULL;
	}
x86_l_308d:
	/* 0x308d: mov    BYTE PTR [r14+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_3091:
	/* 0x3091: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3094:
	/* 0x3094: add    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3097:
	/* 0x3097: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_309c:
	/* 0x309c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30a1:
	/* 0x30a1: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_30a4:
	/* 0x30a4: movzx  edx,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_30a8:
	/* 0x30a8: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30ab:
	/* 0x30ab: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_30b0:
	/* 0x30b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30b2:
	/* 0x30b2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30b5:
	/* 0x30b5: js     350c <generic_retkprobe_event+0x350c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13580ULL;
	}
x86_l_30bb:
	/* 0x30bb: movzx  eax,BYTE PTR [r14+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_30c0:
	/* 0x30c0: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_30c3:
	/* 0x30c3: jg     30e7 <generic_retkprobe_event+0x30e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 12519ULL;
	}
x86_l_30c5:
	/* 0x30c5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30c7:
	/* 0x30c7: je     3110 <generic_retkprobe_event+0x3110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12560ULL;
	}
x86_l_30c9:
	/* 0x30c9: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_30cc:
	/* 0x30cc: je     3110 <generic_retkprobe_event+0x3110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12560ULL;
	}
x86_l_30ce:
	/* 0x30ce: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
	return 12497ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12497ULL: goto x86_l_30d1;
	case 12503ULL: goto x86_l_30d7;
	case 12510ULL: goto x86_l_30de;
	case 12514ULL: goto x86_l_30e2;
	case 12519ULL: goto x86_l_30e7;
	case 12522ULL: goto x86_l_30ea;
	case 12528ULL: goto x86_l_30f0;
	case 12531ULL: goto x86_l_30f3;
	case 12533ULL: goto x86_l_30f5;
	case 12538ULL: goto x86_l_30fa;
	case 12544ULL: goto x86_l_3100;
	case 12551ULL: goto x86_l_3107;
	case 12555ULL: goto x86_l_310b;
	case 12560ULL: goto x86_l_3110;
	case 12563ULL: goto x86_l_3113;
	case 12568ULL: goto x86_l_3118;
	case 12575ULL: goto x86_l_311f;
	case 12580ULL: goto x86_l_3124;
	case 12585ULL: goto x86_l_3129;
	case 12587ULL: goto x86_l_312b;
	case 12592ULL: goto x86_l_3130;
	case 12601ULL: goto x86_l_3139;
	case 12607ULL: goto x86_l_313f;
	case 12615ULL: goto x86_l_3147;
	case 12619ULL: goto x86_l_314b;
	case 12624ULL: goto x86_l_3150;
	case 12630ULL: goto x86_l_3156;
	case 12635ULL: goto x86_l_315b;
	case 12640ULL: goto x86_l_3160;
	case 12645ULL: goto x86_l_3165;
	case 12647ULL: goto x86_l_3167;
	case 12652ULL: goto x86_l_316c;
	case 12654ULL: goto x86_l_316e;
	case 12660ULL: goto x86_l_3174;
	case 12665ULL: goto x86_l_3179;
	case 12670ULL: goto x86_l_317e;
	case 12673ULL: goto x86_l_3181;
	case 12676ULL: goto x86_l_3184;
	case 12680ULL: goto x86_l_3188;
	case 12683ULL: goto x86_l_318b;
	case 12687ULL: goto x86_l_318f;
	case 12692ULL: goto x86_l_3194;
	case 12697ULL: goto x86_l_3199;
	case 12704ULL: goto x86_l_31a0;
	case 12710ULL: goto x86_l_31a6;
	case 12713ULL: goto x86_l_31a9;
	case 12718ULL: goto x86_l_31ae;
	case 12721ULL: goto x86_l_31b1;
	case 12727ULL: goto x86_l_31b7;
	case 12730ULL: goto x86_l_31ba;
	case 12735ULL: goto x86_l_31bf;
	case 12740ULL: goto x86_l_31c4;
	case 12745ULL: goto x86_l_31c9;
	case 12750ULL: goto x86_l_31ce;
	case 12752ULL: goto x86_l_31d0;
	case 12757ULL: goto x86_l_31d5;
	case 12759ULL: goto x86_l_31d7;
	case 12765ULL: goto x86_l_31dd;
	case 12770ULL: goto x86_l_31e2;
	case 12776ULL: goto x86_l_31e8;
	case 12782ULL: goto x86_l_31ee;
	case 12787ULL: goto x86_l_31f3;
	case 12793ULL: goto x86_l_31f9;
	case 12798ULL: goto x86_l_31fe;
	case 12801ULL: goto x86_l_3201;
	case 12806ULL: goto x86_l_3206;
	case 12813ULL: goto x86_l_320d;
	case 12818ULL: goto x86_l_3212;
	case 12820ULL: goto x86_l_3214;
	case 12825ULL: goto x86_l_3219;
	case 12828ULL: goto x86_l_321c;
	case 12832ULL: goto x86_l_3220;
	case 12836ULL: goto x86_l_3224;
	case 12841ULL: goto x86_l_3229;
	case 12845ULL: goto x86_l_322d;
	case 12851ULL: goto x86_l_3233;
	case 12861ULL: goto x86_l_323d;
	case 12865ULL: goto x86_l_3241;
	case 12871ULL: goto x86_l_3247;
	case 12875ULL: goto x86_l_324b;
	case 12878ULL: goto x86_l_324e;
	case 12881ULL: goto x86_l_3251;
	case 12886ULL: goto x86_l_3256;
	case 12891ULL: goto x86_l_325b;
	case 12894ULL: goto x86_l_325e;
	case 12898ULL: goto x86_l_3262;
	case 12901ULL: goto x86_l_3265;
	case 12906ULL: goto x86_l_326a;
	case 12908ULL: goto x86_l_326c;
	case 12911ULL: goto x86_l_326f;
	case 12917ULL: goto x86_l_3275;
	case 12922ULL: goto x86_l_327a;
	case 12925ULL: goto x86_l_327d;
	case 12927ULL: goto x86_l_327f;
	case 12929ULL: goto x86_l_3281;
	case 12931ULL: goto x86_l_3283;
	case 12934ULL: goto x86_l_3286;
	case 12936ULL: goto x86_l_3288;
	case 12939ULL: goto x86_l_328b;
	case 12945ULL: goto x86_l_3291;
	case 12952ULL: goto x86_l_3298;
	case 12956ULL: goto x86_l_329c;
	case 12961ULL: goto x86_l_32a1;
	case 12964ULL: goto x86_l_32a4;
	case 12970ULL: goto x86_l_32aa;
	case 12973ULL: goto x86_l_32ad;
	case 12975ULL: goto x86_l_32af;
	case 12980ULL: goto x86_l_32b4;
	case 12986ULL: goto x86_l_32ba;
	case 12993ULL: goto x86_l_32c1;
	case 12997ULL: goto x86_l_32c5;
	case 13002ULL: goto x86_l_32ca;
	case 13005ULL: goto x86_l_32cd;
	case 13010ULL: goto x86_l_32d2;
	case 13017ULL: goto x86_l_32d9;
	case 13022ULL: goto x86_l_32de;
	case 13027ULL: goto x86_l_32e3;
	case 13031ULL: goto x86_l_32e7;
	case 13036ULL: goto x86_l_32ec;
	case 13041ULL: goto x86_l_32f1;
	case 13046ULL: goto x86_l_32f6;
	case 13051ULL: goto x86_l_32fb;
	case 13053ULL: goto x86_l_32fd;
	case 13058ULL: goto x86_l_3302;
	case 13063ULL: goto x86_l_3307;
	case 13068ULL: goto x86_l_330c;
	case 13073ULL: goto x86_l_3311;
	case 13079ULL: goto x86_l_3317;
	case 13083ULL: goto x86_l_331b;
	case 13088ULL: goto x86_l_3320;
	case 13093ULL: goto x86_l_3325;
	case 13098ULL: goto x86_l_332a;
	case 13101ULL: goto x86_l_332d;
	case 13103ULL: goto x86_l_332f;
	case 13108ULL: goto x86_l_3334;
	case 13113ULL: goto x86_l_3339;
	case 13117ULL: goto x86_l_333d;
	case 13122ULL: goto x86_l_3342;
	case 13127ULL: goto x86_l_3347;
	case 13132ULL: goto x86_l_334c;
	case 13137ULL: goto x86_l_3351;
	case 13139ULL: goto x86_l_3353;
	case 13144ULL: goto x86_l_3358;
	case 13150ULL: goto x86_l_335e;
	case 13158ULL: goto x86_l_3366;
	case 13163ULL: goto x86_l_336b;
	case 13168ULL: goto x86_l_3370;
	case 13173ULL: goto x86_l_3375;
	case 13175ULL: goto x86_l_3377;
	case 13183ULL: goto x86_l_337f;
	case 13189ULL: goto x86_l_3385;
	case 13194ULL: goto x86_l_338a;
	case 13199ULL: goto x86_l_338f;
	case 13204ULL: goto x86_l_3394;
	case 13209ULL: goto x86_l_3399;
	case 13214ULL: goto x86_l_339e;
	case 13217ULL: goto x86_l_33a1;
	case 13219ULL: goto x86_l_33a3;
	case 13224ULL: goto x86_l_33a8;
	case 13230ULL: goto x86_l_33ae;
	case 13238ULL: goto x86_l_33b6;
	case 13243ULL: goto x86_l_33bb;
	case 13248ULL: goto x86_l_33c0;
	case 13253ULL: goto x86_l_33c5;
	case 13256ULL: goto x86_l_33c8;
	case 13258ULL: goto x86_l_33ca;
	case 13262ULL: goto x86_l_33ce;
	case 13267ULL: goto x86_l_33d3;
	case 13272ULL: goto x86_l_33d8;
	case 13277ULL: goto x86_l_33dd;
	case 13282ULL: goto x86_l_33e2;
	case 13285ULL: goto x86_l_33e5;
	case 13287ULL: goto x86_l_33e7;
	case 13292ULL: goto x86_l_33ec;
	case 13297ULL: goto x86_l_33f1;
	case 13301ULL: goto x86_l_33f5;
	case 13304ULL: goto x86_l_33f8;
	case 13309ULL: goto x86_l_33fd;
	case 13311ULL: goto x86_l_33ff;
	case 13313ULL: goto x86_l_3401;
	case 13316ULL: goto x86_l_3404;
	case 13319ULL: goto x86_l_3407;
	case 13324ULL: goto x86_l_340c;
	case 13326ULL: goto x86_l_340e;
	case 13329ULL: goto x86_l_3411;
	case 13333ULL: goto x86_l_3415;
	case 13335ULL: goto x86_l_3417;
	case 13339ULL: goto x86_l_341b;
	case 13341ULL: goto x86_l_341d;
	case 13344ULL: goto x86_l_3420;
	case 13346ULL: goto x86_l_3422;
	case 13350ULL: goto x86_l_3426;
	case 13353ULL: goto x86_l_3429;
	case 13358ULL: goto x86_l_342e;
	case 13364ULL: goto x86_l_3434;
	case 13370ULL: goto x86_l_343a;
	case 13376ULL: goto x86_l_3440;
	case 13382ULL: goto x86_l_3446;
	case 13385ULL: goto x86_l_3449;
	case 13387ULL: goto x86_l_344b;
	case 13392ULL: goto x86_l_3450;
	case 13394ULL: goto x86_l_3452;
	case 13397ULL: goto x86_l_3455;
	case 13401ULL: goto x86_l_3459;
	case 13404ULL: goto x86_l_345c;
	case 13407ULL: goto x86_l_345f;
	case 13410ULL: goto x86_l_3462;
	case 13415ULL: goto x86_l_3467;
	case 13417ULL: goto x86_l_3469;
	case 13422ULL: goto x86_l_346e;
	case 13425ULL: goto x86_l_3471;
	case 13430ULL: goto x86_l_3476;
	case 13436ULL: goto x86_l_347c;
	case 13442ULL: goto x86_l_3482;
	case 13450ULL: goto x86_l_348a;
	case 13455ULL: goto x86_l_348f;
	case 13460ULL: goto x86_l_3494;
	case 13465ULL: goto x86_l_3499;
	case 13470ULL: goto x86_l_349e;
	case 13473ULL: goto x86_l_34a1;
	case 13478ULL: goto x86_l_34a6;
	case 13485ULL: goto x86_l_34ad;
	case 13490ULL: goto x86_l_34b2;
	case 13492ULL: goto x86_l_34b4;
	case 13497ULL: goto x86_l_34b9;
	case 13500ULL: goto x86_l_34bc;
	case 13504ULL: goto x86_l_34c0;
	case 13508ULL: goto x86_l_34c4;
	case 13513ULL: goto x86_l_34c9;
	case 13517ULL: goto x86_l_34cd;
	case 13523ULL: goto x86_l_34d3;
	case 13533ULL: goto x86_l_34dd;
	case 13537ULL: goto x86_l_34e1;
	case 13543ULL: goto x86_l_34e7;
	case 13547ULL: goto x86_l_34eb;
	case 13550ULL: goto x86_l_34ee;
	case 13553ULL: goto x86_l_34f1;
	case 13558ULL: goto x86_l_34f6;
	case 13563ULL: goto x86_l_34fb;
	case 13567ULL: goto x86_l_34ff;
	case 13570ULL: goto x86_l_3502;
	case 13573ULL: goto x86_l_3505;
	case 13578ULL: goto x86_l_350a;
	case 13580ULL: goto x86_l_350c;
	case 13582ULL: goto x86_l_350e;
	case 13589ULL: goto x86_l_3515;
	case 13592ULL: goto x86_l_3518;
	case 13597ULL: goto x86_l_351d;
	case 13605ULL: goto x86_l_3525;
	case 13615ULL: goto x86_l_352f;
	case 13619ULL: goto x86_l_3533;
	case 13624ULL: goto x86_l_3538;
	case 13629ULL: goto x86_l_353d;
	case 13637ULL: goto x86_l_3545;
	case 13642ULL: goto x86_l_354a;
	case 13644ULL: goto x86_l_354c;
	case 13651ULL: goto x86_l_3553;
	case 13655ULL: goto x86_l_3557;
	case 13660ULL: goto x86_l_355c;
	case 13665ULL: goto x86_l_3561;
	case 13670ULL: goto x86_l_3566;
	case 13673ULL: goto x86_l_3569;
	case 13675ULL: goto x86_l_356b;
	case 13683ULL: goto x86_l_3573;
	case 13686ULL: goto x86_l_3576;
	case 13688ULL: goto x86_l_3578;
	case 13691ULL: goto x86_l_357b;
	case 13697ULL: goto x86_l_3581;
	case 13702ULL: goto x86_l_3586;
	case 13711ULL: goto x86_l_358f;
	case 13715ULL: goto x86_l_3593;
	case 13720ULL: goto x86_l_3598;
	case 13727ULL: goto x86_l_359f;
	case 13732ULL: goto x86_l_35a4;
	case 13737ULL: goto x86_l_35a9;
	case 13742ULL: goto x86_l_35ae;
	case 13744ULL: goto x86_l_35b0;
	case 13751ULL: goto x86_l_35b7;
	case 13755ULL: goto x86_l_35bb;
	case 13759ULL: goto x86_l_35bf;
	case 13764ULL: goto x86_l_35c4;
	case 13769ULL: goto x86_l_35c9;
	case 13771ULL: goto x86_l_35cb;
	case 13776ULL: goto x86_l_35d0;
	case 13785ULL: goto x86_l_35d9;
	case 13789ULL: goto x86_l_35dd;
	case 13794ULL: goto x86_l_35e2;
	case 13801ULL: goto x86_l_35e9;
	case 13806ULL: goto x86_l_35ee;
	case 13811ULL: goto x86_l_35f3;
	case 13816ULL: goto x86_l_35f8;
	case 13818ULL: goto x86_l_35fa;
	case 13825ULL: goto x86_l_3601;
	case 13829ULL: goto x86_l_3605;
	case 13833ULL: goto x86_l_3609;
	case 13838ULL: goto x86_l_360e;
	case 13843ULL: goto x86_l_3613;
	case 13848ULL: goto x86_l_3618;
	case 13850ULL: goto x86_l_361a;
	case 13852ULL: goto x86_l_361c;
	case 13857ULL: goto x86_l_3621;
	case 13867ULL: goto x86_l_362b;
	case 13872ULL: goto x86_l_3630;
	case 13877ULL: goto x86_l_3635;
	case 13884ULL: goto x86_l_363c;
	case 13891ULL: goto x86_l_3643;
	case 13900ULL: goto x86_l_364c;
	case 13909ULL: goto x86_l_3655;
	case 13916ULL: goto x86_l_365c;
	case 13921ULL: goto x86_l_3661;
	case 13926ULL: goto x86_l_3666;
	case 13931ULL: goto x86_l_366b;
	case 13937ULL: goto x86_l_3671;
	case 13942ULL: goto x86_l_3676;
	case 13945ULL: goto x86_l_3679;
	case 13947ULL: goto x86_l_367b;
	case 13952ULL: goto x86_l_3680;
	case 13955ULL: goto x86_l_3683;
	case 13957ULL: goto x86_l_3685;
	case 13961ULL: goto x86_l_3689;
	case 13969ULL: goto x86_l_3691;
	case 13974ULL: goto x86_l_3696;
	case 13979ULL: goto x86_l_369b;
	case 13984ULL: goto x86_l_36a0;
	case 13988ULL: goto x86_l_36a4;
	case 13993ULL: goto x86_l_36a9;
	case 13995ULL: goto x86_l_36ab;
	case 14000ULL: goto x86_l_36b0;
	case 14008ULL: goto x86_l_36b8;
	case 14012ULL: goto x86_l_36bc;
	case 14017ULL: goto x86_l_36c1;
	case 14024ULL: goto x86_l_36c8;
	case 14029ULL: goto x86_l_36cd;
	case 14034ULL: goto x86_l_36d2;
	case 14036ULL: goto x86_l_36d4;
	case 14039ULL: goto x86_l_36d7;
	case 14046ULL: goto x86_l_36de;
	case 14050ULL: goto x86_l_36e2;
	case 14054ULL: goto x86_l_36e6;
	case 14059ULL: goto x86_l_36eb;
	case 14064ULL: goto x86_l_36f0;
	case 14066ULL: goto x86_l_36f2;
	case 14074ULL: goto x86_l_36fa;
	case 14080ULL: goto x86_l_3700;
	case 14085ULL: goto x86_l_3705;
	case 14090ULL: goto x86_l_370a;
	case 14095ULL: goto x86_l_370f;
	case 14103ULL: goto x86_l_3717;
	case 14108ULL: goto x86_l_371c;
	case 14112ULL: goto x86_l_3720;
	case 14117ULL: goto x86_l_3725;
	case 14122ULL: goto x86_l_372a;
	case 14127ULL: goto x86_l_372f;
	case 14132ULL: goto x86_l_3734;
	case 14134ULL: goto x86_l_3736;
	case 14139ULL: goto x86_l_373b;
	case 14144ULL: goto x86_l_3740;
	case 14149ULL: goto x86_l_3745;
	case 14154ULL: goto x86_l_374a;
	case 14160ULL: goto x86_l_3750;
	case 14164ULL: goto x86_l_3754;
	case 14169ULL: goto x86_l_3759;
	case 14174ULL: goto x86_l_375e;
	case 14179ULL: goto x86_l_3763;
	case 14182ULL: goto x86_l_3766;
	case 14184ULL: goto x86_l_3768;
	case 14189ULL: goto x86_l_376d;
	case 14194ULL: goto x86_l_3772;
	case 14198ULL: goto x86_l_3776;
	case 14203ULL: goto x86_l_377b;
	case 14208ULL: goto x86_l_3780;
	case 14213ULL: goto x86_l_3785;
	case 14218ULL: goto x86_l_378a;
	case 14220ULL: goto x86_l_378c;
	case 14225ULL: goto x86_l_3791;
	case 14231ULL: goto x86_l_3797;
	case 14239ULL: goto x86_l_379f;
	case 14244ULL: goto x86_l_37a4;
	case 14249ULL: goto x86_l_37a9;
	case 14254ULL: goto x86_l_37ae;
	case 14256ULL: goto x86_l_37b0;
	case 14264ULL: goto x86_l_37b8;
	case 14270ULL: goto x86_l_37be;
	case 14275ULL: goto x86_l_37c3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_30d1:
	/* 0x30d1: jne    3214 <generic_retkprobe_event+0x3214> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3214;
	}
x86_l_30d7:
	/* 0x30d7: mov    WORD PTR [r14+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_30de:
	/* 0x30de: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_30e2:
	/* 0x30e2: jmp    3219 <generic_retkprobe_event+0x3219> */
	goto x86_l_3219;
x86_l_30e7:
	/* 0x30e7: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_30ea:
	/* 0x30ea: je     31fe <generic_retkprobe_event+0x31fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31fe;
	}
x86_l_30f0:
	/* 0x30f0: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_30f3:
	/* 0x30f3: je     3110 <generic_retkprobe_event+0x3110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3110;
	}
x86_l_30f5:
	/* 0x30f5: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_30fa:
	/* 0x30fa: jne    3214 <generic_retkprobe_event+0x3214> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3214;
	}
x86_l_3100:
	/* 0x3100: mov    WORD PTR [r14+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_3107:
	/* 0x3107: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_310b:
	/* 0x310b: jmp    3219 <generic_retkprobe_event+0x3219> */
	goto x86_l_3219;
x86_l_3110:
	/* 0x3110: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_3113:
	/* 0x3113: movzx  eax,BYTE PTR [r14+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3118:
	/* 0x3118: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_311f:
	/* 0x311f: mov    WORD PTR [r14+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3124:
	/* 0x3124: jmp    3219 <generic_retkprobe_event+0x3219> */
	goto x86_l_3219;
x86_l_3129:
	/* 0x3129: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_312b:
	/* 0x312b: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3130:
	/* 0x3130: cmp    QWORD PTR [rsp+0xa8],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505733ULL);
x86_l_3139:
	/* 0x3139: jb     2897 <generic_retkprobe_event+0x2897> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10391ULL;
	}
x86_l_313f:
	/* 0x313f: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3147:
	/* 0x3147: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_314b:
	/* 0x314b: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3150:
	/* 0x3150: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_3156:
	/* 0x3156: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_315b:
	/* 0x315b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3160:
	/* 0x3160: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3165:
	/* 0x3165: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3167:
	/* 0x3167: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_316c:
	/* 0x316c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_316e:
	/* 0x316e: js     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15444ULL;
	}
x86_l_3174:
	/* 0x3174: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3179:
	/* 0x3179: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_317e:
	/* 0x317e: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3181:
	/* 0x3181: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3184:
	/* 0x3184: cmovb  r12,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_3188:
	/* 0x3188: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_318b:
	/* 0x318b: cmovne rdx,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_318f:
	/* 0x318f: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_3194:
	/* 0x3194: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3199:
	/* 0x3199: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_31a0:
	/* 0x31a0: ja     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 15444ULL;
	}
x86_l_31a6:
	/* 0x31a6: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_31a9:
	/* 0x31a9: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_31ae:
	/* 0x31ae: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_31b1:
	/* 0x31b1: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_31b7:
	/* 0x31b7: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_31ba:
	/* 0x31ba: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31bf:
	/* 0x31bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31c4:
	/* 0x31c4: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31c9:
	/* 0x31c9: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31ce:
	/* 0x31ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31d0:
	/* 0x31d0: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_31d5:
	/* 0x31d5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31d7:
	/* 0x31d7: js     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15444ULL;
	}
x86_l_31dd:
	/* 0x31dd: add    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_31e2:
	/* 0x31e2: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_31e8:
	/* 0x31e8: je     38d7 <generic_retkprobe_event+0x38d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14551ULL;
	}
x86_l_31ee:
	/* 0x31ee: sub    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_31f3:
	/* 0x31f3: jne    38de <generic_retkprobe_event+0x38de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14558ULL;
	}
x86_l_31f9:
	/* 0x31f9: jmp    2897 <generic_retkprobe_event+0x2897> */
	return 10391ULL;
x86_l_31fe:
	/* 0x31fe: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_3201:
	/* 0x3201: movzx  eax,BYTE PTR [r14+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3206:
	/* 0x3206: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_320d:
	/* 0x320d: mov    WORD PTR [r14+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3212:
	/* 0x3212: jmp    3219 <generic_retkprobe_event+0x3219> */
	goto x86_l_3219;
x86_l_3214:
	/* 0x3214: movzx  eax,WORD PTR [r14+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_3219:
	/* 0x3219: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_321c:
	/* 0x321c: add    ax,WORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3220:
	/* 0x3220: mov    WORD PTR [r14],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3224:
	/* 0x3224: movzx  ecx,BYTE PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_3229:
	/* 0x3229: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_322d:
	/* 0x322d: ja     370f <generic_retkprobe_event+0x370f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_370f;
	}
x86_l_3233:
	/* 0x3233: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_323d:
	/* 0x323d: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_3241:
	/* 0x3241: jae    370f <generic_retkprobe_event+0x370f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_370f;
	}
x86_l_3247:
	/* 0x3247: mov    BYTE PTR [r14+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_324b:
	/* 0x324b: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_324e:
	/* 0x324e: add    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3251:
	/* 0x3251: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3256:
	/* 0x3256: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_325b:
	/* 0x325b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_325e:
	/* 0x325e: movzx  edx,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3262:
	/* 0x3262: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3265:
	/* 0x3265: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_326a:
	/* 0x326a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_326c:
	/* 0x326c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_326f:
	/* 0x326f: js     350c <generic_retkprobe_event+0x350c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_350c;
	}
x86_l_3275:
	/* 0x3275: movzx  eax,BYTE PTR [r14+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_327a:
	/* 0x327a: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_327d:
	/* 0x327d: jg     32a1 <generic_retkprobe_event+0x32a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_32a1;
	}
x86_l_327f:
	/* 0x327f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3281:
	/* 0x3281: je     32ca <generic_retkprobe_event+0x32ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32ca;
	}
x86_l_3283:
	/* 0x3283: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_3286:
	/* 0x3286: je     32ca <generic_retkprobe_event+0x32ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32ca;
	}
x86_l_3288:
	/* 0x3288: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_328b:
	/* 0x328b: jne    34b4 <generic_retkprobe_event+0x34b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_34b4;
	}
x86_l_3291:
	/* 0x3291: mov    WORD PTR [r14+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_3298:
	/* 0x3298: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_329c:
	/* 0x329c: jmp    34b9 <generic_retkprobe_event+0x34b9> */
	goto x86_l_34b9;
x86_l_32a1:
	/* 0x32a1: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_32a4:
	/* 0x32a4: je     349e <generic_retkprobe_event+0x349e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_349e;
	}
x86_l_32aa:
	/* 0x32aa: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_32ad:
	/* 0x32ad: je     32ca <generic_retkprobe_event+0x32ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32ca;
	}
x86_l_32af:
	/* 0x32af: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_32b4:
	/* 0x32b4: jne    34b4 <generic_retkprobe_event+0x34b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_34b4;
	}
x86_l_32ba:
	/* 0x32ba: mov    WORD PTR [r14+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_32c1:
	/* 0x32c1: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_32c5:
	/* 0x32c5: jmp    34b9 <generic_retkprobe_event+0x34b9> */
	goto x86_l_34b9;
x86_l_32ca:
	/* 0x32ca: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_32cd:
	/* 0x32cd: movzx  eax,BYTE PTR [r14+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_32d2:
	/* 0x32d2: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_32d9:
	/* 0x32d9: mov    WORD PTR [r14+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_32de:
	/* 0x32de: jmp    34b9 <generic_retkprobe_event+0x34b9> */
	goto x86_l_34b9;
x86_l_32e3:
	/* 0x32e3: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32e7:
	/* 0x32e7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32ec:
	/* 0x32ec: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32f1:
	/* 0x32f1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32f6:
	/* 0x32f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32fb:
	/* 0x32fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32fd:
	/* 0x32fd: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3302:
	/* 0x3302: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_3307:
	/* 0x3307: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_330c:
	/* 0x330c: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3311:
	/* 0x3311: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_3317:
	/* 0x3317: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_331b:
	/* 0x331b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3320:
	/* 0x3320: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3325:
	/* 0x3325: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_332a:
	/* 0x332a: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_332d:
	/* 0x332d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_332f:
	/* 0x332f: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3334:
	/* 0x3334: mov    QWORD PTR [rsp+0x50],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3339:
	/* 0x3339: lea    rdx,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_333d:
	/* 0x333d: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3342:
	/* 0x3342: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3347:
	/* 0x3347: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_334c:
	/* 0x334c: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3351:
	/* 0x3351: jne    335e <generic_retkprobe_event+0x335e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_335e;
	}
x86_l_3353:
	/* 0x3353: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_3358:
	/* 0x3358: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_335e:
	/* 0x335e: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3366:
	/* 0x3366: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_336b:
	/* 0x336b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3370:
	/* 0x3370: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3375:
	/* 0x3375: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3377:
	/* 0x3377: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_337f:
	/* 0x337f: je     371c <generic_retkprobe_event+0x371c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_371c;
	}
x86_l_3385:
	/* 0x3385: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_338a:
	/* 0x338a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_338f:
	/* 0x338f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3394:
	/* 0x3394: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3399:
	/* 0x3399: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_339e:
	/* 0x339e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_33a1:
	/* 0x33a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33a3:
	/* 0x33a3: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33a8:
	/* 0x33a8: je     371c <generic_retkprobe_event+0x371c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_371c;
	}
x86_l_33ae:
	/* 0x33ae: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_33b6:
	/* 0x33b6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_33bb:
	/* 0x33bb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33c0:
	/* 0x33c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33c5:
	/* 0x33c5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_33c8:
	/* 0x33c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33ca:
	/* 0x33ca: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_33ce:
	/* 0x33ce: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_33d3:
	/* 0x33d3: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_33d8:
	/* 0x33d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33dd:
	/* 0x33dd: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_33e2:
	/* 0x33e2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_33e5:
	/* 0x33e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33e7:
	/* 0x33e7: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_33ec:
	/* 0x33ec: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_33f1:
	/* 0x33f1: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_33f5:
	/* 0x33f5: sub    rax,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_33f8:
	/* 0x33f8: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_33fd:
	/* 0x33fd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33ff:
	/* 0x33ff: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_3401:
	/* 0x3401: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3404:
	/* 0x3404: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_3407:
	/* 0x3407: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_340c:
	/* 0x340c: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_340e:
	/* 0x340e: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3411:
	/* 0x3411: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_3415:
	/* 0x3415: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_3417:
	/* 0x3417: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_341b:
	/* 0x341b: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_341d:
	/* 0x341d: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_3420:
	/* 0x3420: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3422:
	/* 0x3422: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3426:
	/* 0x3426: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3429:
	/* 0x3429: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_342e:
	/* 0x342e: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_3434:
	/* 0x3434: jb     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1821ULL;
	}
x86_l_343a:
	/* 0x343a: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_3440:
	/* 0x3440: ja     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1821ULL;
	}
x86_l_3446:
	/* 0x3446: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3449:
	/* 0x3449: jbe    3450 <generic_retkprobe_event+0x3450> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3450;
	}
x86_l_344b:
	/* 0x344b: mov    BYTE PTR [r14+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_3450:
	/* 0x3450: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3452:
	/* 0x3452: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3455:
	/* 0x3455: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_3459:
	/* 0x3459: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_345c:
	/* 0x345c: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_345f:
	/* 0x345f: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3462:
	/* 0x3462: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3467:
	/* 0x3467: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3469:
	/* 0x3469: mov    QWORD PTR [rsp+0x58],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_346e:
	/* 0x346e: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3471:
	/* 0x3471: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3476:
	/* 0x3476: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_347c:
	/* 0x347c: jbe    71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1821ULL;
	}
x86_l_3482:
	/* 0x3482: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_348a:
	/* 0x348a: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_348f:
	/* 0x348f: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3494:
	/* 0x3494: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3499:
	/* 0x3499: jmp    3780 <generic_retkprobe_event+0x3780> */
	goto x86_l_3780;
x86_l_349e:
	/* 0x349e: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_34a1:
	/* 0x34a1: movzx  eax,BYTE PTR [r14+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_34a6:
	/* 0x34a6: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_34ad:
	/* 0x34ad: mov    WORD PTR [r14+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_34b2:
	/* 0x34b2: jmp    34b9 <generic_retkprobe_event+0x34b9> */
	goto x86_l_34b9;
x86_l_34b4:
	/* 0x34b4: movzx  eax,WORD PTR [r14+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_34b9:
	/* 0x34b9: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_34bc:
	/* 0x34bc: add    ax,WORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_34c0:
	/* 0x34c0: mov    WORD PTR [r14],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34c4:
	/* 0x34c4: movzx  ecx,BYTE PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_34c9:
	/* 0x34c9: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_34cd:
	/* 0x34cd: ja     370f <generic_retkprobe_event+0x370f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_370f;
	}
x86_l_34d3:
	/* 0x34d3: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_34dd:
	/* 0x34dd: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_34e1:
	/* 0x34e1: jae    370f <generic_retkprobe_event+0x370f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_370f;
	}
x86_l_34e7:
	/* 0x34e7: mov    BYTE PTR [r14+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_34eb:
	/* 0x34eb: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_34ee:
	/* 0x34ee: add    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_34f1:
	/* 0x34f1: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_34f6:
	/* 0x34f6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_34fb:
	/* 0x34fb: movzx  edx,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34ff:
	/* 0x34ff: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3502:
	/* 0x3502: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3505:
	/* 0x3505: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_350a:
	/* 0x350a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_350c:
	/* 0x350c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_350e:
	/* 0x350e: mov    BYTE PTR [rsp+0xc8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_3515:
	/* 0x3515: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3518:
	/* 0x3518: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_351d:
	/* 0x351d: mov    WORD PTR [r14+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_3525:
	/* 0x3525: mov    WORD PTR [r14+0xc2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655434ULL);
x86_l_352f:
	/* 0x352f: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3533:
	/* 0x3533: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3538:
	/* 0x3538: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_353d:
	/* 0x353d: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3545:
	/* 0x3545: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_354a:
	/* 0x354a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_354c:
	/* 0x354c: lea    rdi,[r14+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_3553:
	/* 0x3553: add    r13,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3557:
	/* 0x3557: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_355c:
	/* 0x355c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3561:
	/* 0x3561: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3566:
	/* 0x3566: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3569:
	/* 0x3569: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_356b:
	/* 0x356b: movzx  eax,BYTE PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 200ULL);
x86_l_3573:
	/* 0x3573: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_3576:
	/* 0x3576: je     35cb <generic_retkprobe_event+0x35cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35cb;
	}
x86_l_3578:
	/* 0x3578: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_357b:
	/* 0x357b: jne    361c <generic_retkprobe_event+0x361c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_361c;
	}
x86_l_3581:
	/* 0x3581: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3586:
	/* 0x3586: movzx  r12d,WORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 208ULL);
x86_l_358f:
	/* 0x358f: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3593:
	/* 0x3593: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3598:
	/* 0x3598: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_359f:
	/* 0x359f: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_35a4:
	/* 0x35a4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_35a9:
	/* 0x35a9: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_35ae:
	/* 0x35ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35b0:
	/* 0x35b0: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_35b7:
	/* 0x35b7: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_35bb:
	/* 0x35bb: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_35bf:
	/* 0x35bf: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_35c4:
	/* 0x35c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_35c9:
	/* 0x35c9: jmp    3613 <generic_retkprobe_event+0x3613> */
	goto x86_l_3613;
x86_l_35cb:
	/* 0x35cb: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_35d0:
	/* 0x35d0: movzx  r12d,WORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 208ULL);
x86_l_35d9:
	/* 0x35d9: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_35dd:
	/* 0x35dd: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35e2:
	/* 0x35e2: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_35e9:
	/* 0x35e9: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_35ee:
	/* 0x35ee: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_35f3:
	/* 0x35f3: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_35f8:
	/* 0x35f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35fa:
	/* 0x35fa: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_3601:
	/* 0x3601: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3605:
	/* 0x3605: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3609:
	/* 0x3609: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_360e:
	/* 0x360e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3613:
	/* 0x3613: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3618:
	/* 0x3618: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_361a:
	/* 0x361a: jmp    362b <generic_retkprobe_event+0x362b> */
	goto x86_l_362b;
x86_l_361c:
	/* 0x361c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3621:
	/* 0x3621: mov    DWORD PTR [rax+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_362b:
	/* 0x362b: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3630:
	/* 0x3630: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3635:
	/* 0x3635: movzx  ecx,WORD PTR [rax+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_363c:
	/* 0x363c: movzx  edx,WORD PTR [rax+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_3643:
	/* 0x3643: movbe  WORD PTR [rax+0xbc],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_364c:
	/* 0x364c: movbe  WORD PTR [rax+0xbe],dx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_3655:
	/* 0x3655: add    rbp,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_365c:
	/* 0x365c: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3661:
	/* 0x3661: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3666:
	/* 0x3666: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_366b:
	/* 0x366b: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_3671:
	/* 0x3671: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3676:
	/* 0x3676: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3679:
	/* 0x3679: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_367b:
	/* 0x367b: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3680:
	/* 0x3680: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_3683:
	/* 0x3683: je     36f2 <generic_retkprobe_event+0x36f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36f2;
	}
x86_l_3685:
	/* 0x3685: add    rcx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_3689:
	/* 0x3689: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3691:
	/* 0x3691: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3696:
	/* 0x3696: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_369b:
	/* 0x369b: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_36a0:
	/* 0x36a0: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_36a4:
	/* 0x36a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36a9:
	/* 0x36a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36ab:
	/* 0x36ab: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_36b0:
	/* 0x36b0: mov    r13,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_36b8:
	/* 0x36b8: lea    rdx,[r12+r13*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 0ULL);
x86_l_36bc:
	/* 0x36bc: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36c1:
	/* 0x36c1: lea    rdi,[rbp+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_36c8:
	/* 0x36c8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_36cd:
	/* 0x36cd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_36d2:
	/* 0x36d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36d4:
	/* 0x36d4: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_36d7:
	/* 0x36d7: add    rdi,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_36de:
	/* 0x36de: lea    rdx,[r12+r13*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 0ULL);
x86_l_36e2:
	/* 0x36e2: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_36e6:
	/* 0x36e6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_36eb:
	/* 0x36eb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_36f0:
	/* 0x36f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36f2:
	/* 0x36f2: mov    r12,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_36fa:
	/* 0x36fa: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_3700:
	/* 0x3700: mov    ebp,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_3705:
	/* 0x3705: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_370a:
	/* 0x370a: jmp    953 <generic_retkprobe_event+0x953> */
	return 2387ULL;
x86_l_370f:
	/* 0x370f: mov    WORD PTR [rsp+0xd0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_3717:
	/* 0x3717: jmp    350e <generic_retkprobe_event+0x350e> */
	goto x86_l_350e;
x86_l_371c:
	/* 0x371c: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3720:
	/* 0x3720: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3725:
	/* 0x3725: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_372a:
	/* 0x372a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_372f:
	/* 0x372f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3734:
	/* 0x3734: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3736:
	/* 0x3736: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_373b:
	/* 0x373b: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_3740:
	/* 0x3740: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3745:
	/* 0x3745: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_374a:
	/* 0x374a: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_3750:
	/* 0x3750: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3754:
	/* 0x3754: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3759:
	/* 0x3759: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_375e:
	/* 0x375e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3763:
	/* 0x3763: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3766:
	/* 0x3766: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3768:
	/* 0x3768: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_376d:
	/* 0x376d: mov    QWORD PTR [rsp+0x50],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3772:
	/* 0x3772: lea    rdx,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3776:
	/* 0x3776: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_377b:
	/* 0x377b: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3780:
	/* 0x3780: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_3785:
	/* 0x3785: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_378a:
	/* 0x378a: jne    3797 <generic_retkprobe_event+0x3797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3797;
	}
x86_l_378c:
	/* 0x378c: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_3791:
	/* 0x3791: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_3797:
	/* 0x3797: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_379f:
	/* 0x379f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_37a4:
	/* 0x37a4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37a9:
	/* 0x37a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37ae:
	/* 0x37ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37b0:
	/* 0x37b0: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_37b8:
	/* 0x37b8: je     39ac <generic_retkprobe_event+0x39ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14764ULL;
	}
x86_l_37be:
	/* 0x37be: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_37c3:
	/* 0x37c3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 14280ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14280ULL: goto x86_l_37c8;
	case 14285ULL: goto x86_l_37cd;
	case 14290ULL: goto x86_l_37d2;
	case 14295ULL: goto x86_l_37d7;
	case 14298ULL: goto x86_l_37da;
	case 14300ULL: goto x86_l_37dc;
	case 14305ULL: goto x86_l_37e1;
	case 14311ULL: goto x86_l_37e7;
	case 14319ULL: goto x86_l_37ef;
	case 14324ULL: goto x86_l_37f4;
	case 14329ULL: goto x86_l_37f9;
	case 14334ULL: goto x86_l_37fe;
	case 14337ULL: goto x86_l_3801;
	case 14339ULL: goto x86_l_3803;
	case 14343ULL: goto x86_l_3807;
	case 14348ULL: goto x86_l_380c;
	case 14353ULL: goto x86_l_3811;
	case 14358ULL: goto x86_l_3816;
	case 14363ULL: goto x86_l_381b;
	case 14366ULL: goto x86_l_381e;
	case 14368ULL: goto x86_l_3820;
	case 14373ULL: goto x86_l_3825;
	case 14378ULL: goto x86_l_382a;
	case 14382ULL: goto x86_l_382e;
	case 14385ULL: goto x86_l_3831;
	case 14390ULL: goto x86_l_3836;
	case 14392ULL: goto x86_l_3838;
	case 14394ULL: goto x86_l_383a;
	case 14397ULL: goto x86_l_383d;
	case 14400ULL: goto x86_l_3840;
	case 14405ULL: goto x86_l_3845;
	case 14407ULL: goto x86_l_3847;
	case 14410ULL: goto x86_l_384a;
	case 14414ULL: goto x86_l_384e;
	case 14416ULL: goto x86_l_3850;
	case 14420ULL: goto x86_l_3854;
	case 14422ULL: goto x86_l_3856;
	case 14425ULL: goto x86_l_3859;
	case 14427ULL: goto x86_l_385b;
	case 14431ULL: goto x86_l_385f;
	case 14434ULL: goto x86_l_3862;
	case 14439ULL: goto x86_l_3867;
	case 14445ULL: goto x86_l_386d;
	case 14451ULL: goto x86_l_3873;
	case 14457ULL: goto x86_l_3879;
	case 14463ULL: goto x86_l_387f;
	case 14466ULL: goto x86_l_3882;
	case 14468ULL: goto x86_l_3884;
	case 14473ULL: goto x86_l_3889;
	case 14475ULL: goto x86_l_388b;
	case 14478ULL: goto x86_l_388e;
	case 14482ULL: goto x86_l_3892;
	case 14485ULL: goto x86_l_3895;
	case 14488ULL: goto x86_l_3898;
	case 14491ULL: goto x86_l_389b;
	case 14496ULL: goto x86_l_38a0;
	case 14498ULL: goto x86_l_38a2;
	case 14503ULL: goto x86_l_38a7;
	case 14506ULL: goto x86_l_38aa;
	case 14511ULL: goto x86_l_38af;
	case 14517ULL: goto x86_l_38b5;
	case 14523ULL: goto x86_l_38bb;
	case 14531ULL: goto x86_l_38c3;
	case 14536ULL: goto x86_l_38c8;
	case 14541ULL: goto x86_l_38cd;
	case 14546ULL: goto x86_l_38d2;
	case 14551ULL: goto x86_l_38d7;
	case 14553ULL: goto x86_l_38d9;
	case 14558ULL: goto x86_l_38de;
	case 14567ULL: goto x86_l_38e7;
	case 14573ULL: goto x86_l_38ed;
	case 14581ULL: goto x86_l_38f5;
	case 14585ULL: goto x86_l_38f9;
	case 14590ULL: goto x86_l_38fe;
	case 14596ULL: goto x86_l_3904;
	case 14601ULL: goto x86_l_3909;
	case 14606ULL: goto x86_l_390e;
	case 14611ULL: goto x86_l_3913;
	case 14613ULL: goto x86_l_3915;
	case 14618ULL: goto x86_l_391a;
	case 14620ULL: goto x86_l_391c;
	case 14626ULL: goto x86_l_3922;
	case 14631ULL: goto x86_l_3927;
	case 14636ULL: goto x86_l_392c;
	case 14639ULL: goto x86_l_392f;
	case 14642ULL: goto x86_l_3932;
	case 14646ULL: goto x86_l_3936;
	case 14649ULL: goto x86_l_3939;
	case 14653ULL: goto x86_l_393d;
	case 14658ULL: goto x86_l_3942;
	case 14663ULL: goto x86_l_3947;
	case 14670ULL: goto x86_l_394e;
	case 14676ULL: goto x86_l_3954;
	case 14681ULL: goto x86_l_3959;
	case 14684ULL: goto x86_l_395c;
	case 14687ULL: goto x86_l_395f;
	case 14693ULL: goto x86_l_3965;
	case 14696ULL: goto x86_l_3968;
	case 14701ULL: goto x86_l_396d;
	case 14706ULL: goto x86_l_3972;
	case 14711ULL: goto x86_l_3977;
	case 14716ULL: goto x86_l_397c;
	case 14718ULL: goto x86_l_397e;
	case 14723ULL: goto x86_l_3983;
	case 14725ULL: goto x86_l_3985;
	case 14731ULL: goto x86_l_398b;
	case 14736ULL: goto x86_l_3990;
	case 14742ULL: goto x86_l_3996;
	case 14748ULL: goto x86_l_399c;
	case 14753ULL: goto x86_l_39a1;
	case 14759ULL: goto x86_l_39a7;
	case 14764ULL: goto x86_l_39ac;
	case 14768ULL: goto x86_l_39b0;
	case 14773ULL: goto x86_l_39b5;
	case 14778ULL: goto x86_l_39ba;
	case 14783ULL: goto x86_l_39bf;
	case 14788ULL: goto x86_l_39c4;
	case 14790ULL: goto x86_l_39c6;
	case 14795ULL: goto x86_l_39cb;
	case 14800ULL: goto x86_l_39d0;
	case 14805ULL: goto x86_l_39d5;
	case 14810ULL: goto x86_l_39da;
	case 14816ULL: goto x86_l_39e0;
	case 14820ULL: goto x86_l_39e4;
	case 14825ULL: goto x86_l_39e9;
	case 14830ULL: goto x86_l_39ee;
	case 14835ULL: goto x86_l_39f3;
	case 14838ULL: goto x86_l_39f6;
	case 14840ULL: goto x86_l_39f8;
	case 14845ULL: goto x86_l_39fd;
	case 14850ULL: goto x86_l_3a02;
	case 14854ULL: goto x86_l_3a06;
	case 14859ULL: goto x86_l_3a0b;
	case 14864ULL: goto x86_l_3a10;
	case 14869ULL: goto x86_l_3a15;
	case 14874ULL: goto x86_l_3a1a;
	case 14876ULL: goto x86_l_3a1c;
	case 14881ULL: goto x86_l_3a21;
	case 14887ULL: goto x86_l_3a27;
	case 14895ULL: goto x86_l_3a2f;
	case 14900ULL: goto x86_l_3a34;
	case 14905ULL: goto x86_l_3a39;
	case 14910ULL: goto x86_l_3a3e;
	case 14912ULL: goto x86_l_3a40;
	case 14920ULL: goto x86_l_3a48;
	case 14926ULL: goto x86_l_3a4e;
	case 14931ULL: goto x86_l_3a53;
	case 14936ULL: goto x86_l_3a58;
	case 14941ULL: goto x86_l_3a5d;
	case 14946ULL: goto x86_l_3a62;
	case 14951ULL: goto x86_l_3a67;
	case 14954ULL: goto x86_l_3a6a;
	case 14956ULL: goto x86_l_3a6c;
	case 14961ULL: goto x86_l_3a71;
	case 14967ULL: goto x86_l_3a77;
	case 14975ULL: goto x86_l_3a7f;
	case 14980ULL: goto x86_l_3a84;
	case 14985ULL: goto x86_l_3a89;
	case 14990ULL: goto x86_l_3a8e;
	case 14993ULL: goto x86_l_3a91;
	case 14995ULL: goto x86_l_3a93;
	case 14999ULL: goto x86_l_3a97;
	case 15004ULL: goto x86_l_3a9c;
	case 15009ULL: goto x86_l_3aa1;
	case 15014ULL: goto x86_l_3aa6;
	case 15019ULL: goto x86_l_3aab;
	case 15022ULL: goto x86_l_3aae;
	case 15024ULL: goto x86_l_3ab0;
	case 15029ULL: goto x86_l_3ab5;
	case 15034ULL: goto x86_l_3aba;
	case 15038ULL: goto x86_l_3abe;
	case 15041ULL: goto x86_l_3ac1;
	case 15046ULL: goto x86_l_3ac6;
	case 15048ULL: goto x86_l_3ac8;
	case 15050ULL: goto x86_l_3aca;
	case 15053ULL: goto x86_l_3acd;
	case 15056ULL: goto x86_l_3ad0;
	case 15061ULL: goto x86_l_3ad5;
	case 15063ULL: goto x86_l_3ad7;
	case 15066ULL: goto x86_l_3ada;
	case 15070ULL: goto x86_l_3ade;
	case 15072ULL: goto x86_l_3ae0;
	case 15076ULL: goto x86_l_3ae4;
	case 15078ULL: goto x86_l_3ae6;
	case 15081ULL: goto x86_l_3ae9;
	case 15083ULL: goto x86_l_3aeb;
	case 15087ULL: goto x86_l_3aef;
	case 15090ULL: goto x86_l_3af2;
	case 15095ULL: goto x86_l_3af7;
	case 15101ULL: goto x86_l_3afd;
	case 15107ULL: goto x86_l_3b03;
	case 15113ULL: goto x86_l_3b09;
	case 15119ULL: goto x86_l_3b0f;
	case 15122ULL: goto x86_l_3b12;
	case 15124ULL: goto x86_l_3b14;
	case 15129ULL: goto x86_l_3b19;
	case 15131ULL: goto x86_l_3b1b;
	case 15134ULL: goto x86_l_3b1e;
	case 15138ULL: goto x86_l_3b22;
	case 15141ULL: goto x86_l_3b25;
	case 15144ULL: goto x86_l_3b28;
	case 15147ULL: goto x86_l_3b2b;
	case 15152ULL: goto x86_l_3b30;
	case 15154ULL: goto x86_l_3b32;
	case 15159ULL: goto x86_l_3b37;
	case 15162ULL: goto x86_l_3b3a;
	case 15167ULL: goto x86_l_3b3f;
	case 15173ULL: goto x86_l_3b45;
	case 15179ULL: goto x86_l_3b4b;
	case 15187ULL: goto x86_l_3b53;
	case 15192ULL: goto x86_l_3b58;
	case 15197ULL: goto x86_l_3b5d;
	case 15201ULL: goto x86_l_3b61;
	case 15206ULL: goto x86_l_3b66;
	case 15211ULL: goto x86_l_3b6b;
	case 15216ULL: goto x86_l_3b70;
	case 15221ULL: goto x86_l_3b75;
	case 15223ULL: goto x86_l_3b77;
	case 15228ULL: goto x86_l_3b7c;
	case 15233ULL: goto x86_l_3b81;
	case 15238ULL: goto x86_l_3b86;
	case 15243ULL: goto x86_l_3b8b;
	case 15249ULL: goto x86_l_3b91;
	case 15253ULL: goto x86_l_3b95;
	case 15258ULL: goto x86_l_3b9a;
	case 15263ULL: goto x86_l_3b9f;
	case 15268ULL: goto x86_l_3ba4;
	case 15271ULL: goto x86_l_3ba7;
	case 15273ULL: goto x86_l_3ba9;
	case 15278ULL: goto x86_l_3bae;
	case 15280ULL: goto x86_l_3bb0;
	case 15285ULL: goto x86_l_3bb5;
	case 15294ULL: goto x86_l_3bbe;
	case 15300ULL: goto x86_l_3bc4;
	case 15308ULL: goto x86_l_3bcc;
	case 15312ULL: goto x86_l_3bd0;
	case 15317ULL: goto x86_l_3bd5;
	case 15323ULL: goto x86_l_3bdb;
	case 15328ULL: goto x86_l_3be0;
	case 15333ULL: goto x86_l_3be5;
	case 15338ULL: goto x86_l_3bea;
	case 15340ULL: goto x86_l_3bec;
	case 15345ULL: goto x86_l_3bf1;
	case 15347ULL: goto x86_l_3bf3;
	case 15349ULL: goto x86_l_3bf5;
	case 15354ULL: goto x86_l_3bfa;
	case 15359ULL: goto x86_l_3bff;
	case 15362ULL: goto x86_l_3c02;
	case 15365ULL: goto x86_l_3c05;
	case 15369ULL: goto x86_l_3c09;
	case 15372ULL: goto x86_l_3c0c;
	case 15376ULL: goto x86_l_3c10;
	case 15381ULL: goto x86_l_3c15;
	case 15388ULL: goto x86_l_3c1c;
	case 15390ULL: goto x86_l_3c1e;
	case 15395ULL: goto x86_l_3c23;
	case 15398ULL: goto x86_l_3c26;
	case 15404ULL: goto x86_l_3c2c;
	case 15407ULL: goto x86_l_3c2f;
	case 15412ULL: goto x86_l_3c34;
	case 15417ULL: goto x86_l_3c39;
	case 15422ULL: goto x86_l_3c3e;
	case 15425ULL: goto x86_l_3c41;
	case 15427ULL: goto x86_l_3c43;
	case 15432ULL: goto x86_l_3c48;
	case 15434ULL: goto x86_l_3c4a;
	case 15436ULL: goto x86_l_3c4c;
	case 15439ULL: goto x86_l_3c4f;
	case 15444ULL: goto x86_l_3c54;
	case 15449ULL: goto x86_l_3c59;
	case 15452ULL: goto x86_l_3c5c;
	case 15455ULL: goto x86_l_3c5f;
	case 15458ULL: goto x86_l_3c62;
	case 15461ULL: goto x86_l_3c65;
	case 15469ULL: goto x86_l_3c6d;
	case 15474ULL: goto x86_l_3c72;
	case 15476ULL: goto x86_l_3c74;
	case 15479ULL: goto x86_l_3c77;
	case 15484ULL: goto x86_l_3c7c;
	case 15491ULL: goto x86_l_3c83;
	case 15499ULL: goto x86_l_3c8b;
	case 15504ULL: goto x86_l_3c90;
	case 15509ULL: goto x86_l_3c95;
	case 15514ULL: goto x86_l_3c9a;
	case 15519ULL: goto x86_l_3c9f;
	case 15524ULL: goto x86_l_3ca4;
	case 15526ULL: goto x86_l_3ca6;
	case 15533ULL: goto x86_l_3cad;
	case 15537ULL: goto x86_l_3cb1;
	case 15544ULL: goto x86_l_3cb8;
	case 15549ULL: goto x86_l_3cbd;
	case 15554ULL: goto x86_l_3cc2;
	case 15556ULL: goto x86_l_3cc4;
	case 15559ULL: goto x86_l_3cc7;
	case 15561ULL: goto x86_l_3cc9;
	case 15564ULL: goto x86_l_3ccc;
	case 15569ULL: goto x86_l_3cd1;
	case 15575ULL: goto x86_l_3cd7;
	case 15580ULL: goto x86_l_3cdc;
	case 15585ULL: goto x86_l_3ce1;
	case 15588ULL: goto x86_l_3ce4;
	case 15593ULL: goto x86_l_3ce9;
	case 15598ULL: goto x86_l_3cee;
	case 15603ULL: goto x86_l_3cf3;
	case 15608ULL: goto x86_l_3cf8;
	case 15613ULL: goto x86_l_3cfd;
	case 15615ULL: goto x86_l_3cff;
	case 15620ULL: goto x86_l_3d04;
	case 15623ULL: goto x86_l_3d07;
	case 15629ULL: goto x86_l_3d0d;
	case 15636ULL: goto x86_l_3d14;
	case 15644ULL: goto x86_l_3d1c;
	case 15649ULL: goto x86_l_3d21;
	case 15654ULL: goto x86_l_3d26;
	case 15659ULL: goto x86_l_3d2b;
	case 15664ULL: goto x86_l_3d30;
	case 15669ULL: goto x86_l_3d35;
	case 15671ULL: goto x86_l_3d37;
	case 15678ULL: goto x86_l_3d3e;
	case 15682ULL: goto x86_l_3d42;
	case 15689ULL: goto x86_l_3d49;
	case 15694ULL: goto x86_l_3d4e;
	case 15699ULL: goto x86_l_3d53;
	case 15701ULL: goto x86_l_3d55;
	case 15704ULL: goto x86_l_3d58;
	case 15706ULL: goto x86_l_3d5a;
	case 15709ULL: goto x86_l_3d5d;
	case 15714ULL: goto x86_l_3d62;
	case 15720ULL: goto x86_l_3d68;
	case 15725ULL: goto x86_l_3d6d;
	case 15730ULL: goto x86_l_3d72;
	case 15733ULL: goto x86_l_3d75;
	case 15738ULL: goto x86_l_3d7a;
	case 15743ULL: goto x86_l_3d7f;
	case 15748ULL: goto x86_l_3d84;
	case 15753ULL: goto x86_l_3d89;
	case 15758ULL: goto x86_l_3d8e;
	case 15760ULL: goto x86_l_3d90;
	case 15765ULL: goto x86_l_3d95;
	case 15768ULL: goto x86_l_3d98;
	case 15774ULL: goto x86_l_3d9e;
	case 15781ULL: goto x86_l_3da5;
	case 15789ULL: goto x86_l_3dad;
	case 15794ULL: goto x86_l_3db2;
	case 15799ULL: goto x86_l_3db7;
	case 15804ULL: goto x86_l_3dbc;
	case 15809ULL: goto x86_l_3dc1;
	case 15814ULL: goto x86_l_3dc6;
	case 15816ULL: goto x86_l_3dc8;
	case 15823ULL: goto x86_l_3dcf;
	case 15827ULL: goto x86_l_3dd3;
	case 15834ULL: goto x86_l_3dda;
	case 15839ULL: goto x86_l_3ddf;
	case 15844ULL: goto x86_l_3de4;
	case 15846ULL: goto x86_l_3de6;
	case 15849ULL: goto x86_l_3de9;
	case 15851ULL: goto x86_l_3deb;
	case 15854ULL: goto x86_l_3dee;
	case 15859ULL: goto x86_l_3df3;
	case 15865ULL: goto x86_l_3df9;
	case 15870ULL: goto x86_l_3dfe;
	case 15875ULL: goto x86_l_3e03;
	case 15878ULL: goto x86_l_3e06;
	case 15883ULL: goto x86_l_3e0b;
	case 15888ULL: goto x86_l_3e10;
	case 15893ULL: goto x86_l_3e15;
	case 15898ULL: goto x86_l_3e1a;
	case 15903ULL: goto x86_l_3e1f;
	case 15905ULL: goto x86_l_3e21;
	case 15910ULL: goto x86_l_3e26;
	case 15913ULL: goto x86_l_3e29;
	case 15919ULL: goto x86_l_3e2f;
	case 15926ULL: goto x86_l_3e36;
	case 15934ULL: goto x86_l_3e3e;
	case 15939ULL: goto x86_l_3e43;
	case 15944ULL: goto x86_l_3e48;
	case 15949ULL: goto x86_l_3e4d;
	case 15954ULL: goto x86_l_3e52;
	case 15959ULL: goto x86_l_3e57;
	case 15961ULL: goto x86_l_3e59;
	case 15968ULL: goto x86_l_3e60;
	case 15972ULL: goto x86_l_3e64;
	case 15979ULL: goto x86_l_3e6b;
	case 15984ULL: goto x86_l_3e70;
	default: return 0xffffffffffffffffULL;
	}
x86_l_37c8:
	/* 0x37c8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_37cd:
	/* 0x37cd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37d2:
	/* 0x37d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37d7:
	/* 0x37d7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_37da:
	/* 0x37da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37dc:
	/* 0x37dc: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37e1:
	/* 0x37e1: je     39ac <generic_retkprobe_event+0x39ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39ac;
	}
x86_l_37e7:
	/* 0x37e7: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_37ef:
	/* 0x37ef: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_37f4:
	/* 0x37f4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37f9:
	/* 0x37f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37fe:
	/* 0x37fe: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3801:
	/* 0x3801: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3803:
	/* 0x3803: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3807:
	/* 0x3807: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_380c:
	/* 0x380c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3811:
	/* 0x3811: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3816:
	/* 0x3816: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_381b:
	/* 0x381b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_381e:
	/* 0x381e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3820:
	/* 0x3820: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3825:
	/* 0x3825: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_382a:
	/* 0x382a: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_382e:
	/* 0x382e: sub    rax,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3831:
	/* 0x3831: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3836:
	/* 0x3836: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3838:
	/* 0x3838: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_383a:
	/* 0x383a: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_383d:
	/* 0x383d: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_3840:
	/* 0x3840: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_3845:
	/* 0x3845: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3847:
	/* 0x3847: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_384a:
	/* 0x384a: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_384e:
	/* 0x384e: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_3850:
	/* 0x3850: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_3854:
	/* 0x3854: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3856:
	/* 0x3856: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_3859:
	/* 0x3859: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_385b:
	/* 0x385b: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_385f:
	/* 0x385f: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3862:
	/* 0x3862: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3867:
	/* 0x3867: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_386d:
	/* 0x386d: jb     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1821ULL;
	}
x86_l_3873:
	/* 0x3873: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_3879:
	/* 0x3879: ja     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1821ULL;
	}
x86_l_387f:
	/* 0x387f: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3882:
	/* 0x3882: jbe    3889 <generic_retkprobe_event+0x3889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3889;
	}
x86_l_3884:
	/* 0x3884: mov    BYTE PTR [r14+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_3889:
	/* 0x3889: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_388b:
	/* 0x388b: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_388e:
	/* 0x388e: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_3892:
	/* 0x3892: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3895:
	/* 0x3895: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3898:
	/* 0x3898: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_389b:
	/* 0x389b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38a0:
	/* 0x38a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38a2:
	/* 0x38a2: mov    QWORD PTR [rsp+0x58],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_38a7:
	/* 0x38a7: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_38aa:
	/* 0x38aa: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38af:
	/* 0x38af: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_38b5:
	/* 0x38b5: jbe    71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1821ULL;
	}
x86_l_38bb:
	/* 0x38bb: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_38c3:
	/* 0x38c3: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_38c8:
	/* 0x38c8: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_38cd:
	/* 0x38cd: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_38d2:
	/* 0x38d2: jmp    3a10 <generic_retkprobe_event+0x3a10> */
	goto x86_l_3a10;
x86_l_38d7:
	/* 0x38d7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38d9:
	/* 0x38d9: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_38de:
	/* 0x38de: cmp    QWORD PTR [rsp+0xa8],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505733ULL);
x86_l_38e7:
	/* 0x38e7: je     2897 <generic_retkprobe_event+0x2897> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10391ULL;
	}
x86_l_38ed:
	/* 0x38ed: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_38f5:
	/* 0x38f5: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_38f9:
	/* 0x38f9: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_38fe:
	/* 0x38fe: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_3904:
	/* 0x3904: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3909:
	/* 0x3909: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_390e:
	/* 0x390e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3913:
	/* 0x3913: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3915:
	/* 0x3915: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_391a:
	/* 0x391a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_391c:
	/* 0x391c: js     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c54;
	}
x86_l_3922:
	/* 0x3922: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3927:
	/* 0x3927: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_392c:
	/* 0x392c: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_392f:
	/* 0x392f: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3932:
	/* 0x3932: cmovb  r12,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_3936:
	/* 0x3936: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3939:
	/* 0x3939: cmovne rdx,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_393d:
	/* 0x393d: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_3942:
	/* 0x3942: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3947:
	/* 0x3947: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_394e:
	/* 0x394e: ja     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3c54;
	}
x86_l_3954:
	/* 0x3954: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3959:
	/* 0x3959: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_395c:
	/* 0x395c: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_395f:
	/* 0x395f: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3965:
	/* 0x3965: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3968:
	/* 0x3968: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_396d:
	/* 0x396d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3972:
	/* 0x3972: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3977:
	/* 0x3977: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_397c:
	/* 0x397c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_397e:
	/* 0x397e: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_3983:
	/* 0x3983: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3985:
	/* 0x3985: js     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c54;
	}
x86_l_398b:
	/* 0x398b: add    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_3990:
	/* 0x3990: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3996:
	/* 0x3996: je     3bae <generic_retkprobe_event+0x3bae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bae;
	}
x86_l_399c:
	/* 0x399c: sub    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 24ULL);
x86_l_39a1:
	/* 0x39a1: jne    3bb5 <generic_retkprobe_event+0x3bb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3bb5;
	}
x86_l_39a7:
	/* 0x39a7: jmp    2897 <generic_retkprobe_event+0x2897> */
	return 10391ULL;
x86_l_39ac:
	/* 0x39ac: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39b0:
	/* 0x39b0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39b5:
	/* 0x39b5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_39ba:
	/* 0x39ba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_39bf:
	/* 0x39bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39c4:
	/* 0x39c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39c6:
	/* 0x39c6: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_39cb:
	/* 0x39cb: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_39d0:
	/* 0x39d0: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_39d5:
	/* 0x39d5: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_39da:
	/* 0x39da: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_39e0:
	/* 0x39e0: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_39e4:
	/* 0x39e4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_39e9:
	/* 0x39e9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_39ee:
	/* 0x39ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39f3:
	/* 0x39f3: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_39f6:
	/* 0x39f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39f8:
	/* 0x39f8: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39fd:
	/* 0x39fd: mov    QWORD PTR [rsp+0x50],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3a02:
	/* 0x3a02: lea    rdx,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3a06:
	/* 0x3a06: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3a0b:
	/* 0x3a0b: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3a10:
	/* 0x3a10: cmp    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_3a15:
	/* 0x3a15: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3a1a:
	/* 0x3a1a: jne    3a27 <generic_retkprobe_event+0x3a27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3a27;
	}
x86_l_3a1c:
	/* 0x3a1c: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_3a21:
	/* 0x3a21: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_3a27:
	/* 0x3a27: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3a2f:
	/* 0x3a2f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3a34:
	/* 0x3a34: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a39:
	/* 0x3a39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a3e:
	/* 0x3a3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a40:
	/* 0x3a40: cmp    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_3a48:
	/* 0x3a48: je     3b5d <generic_retkprobe_event+0x3b5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b5d;
	}
x86_l_3a4e:
	/* 0x3a4e: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a53:
	/* 0x3a53: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a58:
	/* 0x3a58: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3a5d:
	/* 0x3a5d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a62:
	/* 0x3a62: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a67:
	/* 0x3a67: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3a6a:
	/* 0x3a6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a6c:
	/* 0x3a6c: cmp    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a71:
	/* 0x3a71: je     3b5d <generic_retkprobe_event+0x3b5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b5d;
	}
x86_l_3a77:
	/* 0x3a77: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3a7f:
	/* 0x3a7f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3a84:
	/* 0x3a84: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a89:
	/* 0x3a89: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a8e:
	/* 0x3a8e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3a91:
	/* 0x3a91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a93:
	/* 0x3a93: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3a97:
	/* 0x3a97: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3a9c:
	/* 0x3a9c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3aa1:
	/* 0x3aa1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3aa6:
	/* 0x3aa6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3aab:
	/* 0x3aab: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3aae:
	/* 0x3aae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ab0:
	/* 0x3ab0: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3ab5:
	/* 0x3ab5: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3aba:
	/* 0x3aba: mov    ebp,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_3abe:
	/* 0x3abe: sub    rax,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3ac1:
	/* 0x3ac1: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3ac6:
	/* 0x3ac6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ac8:
	/* 0x3ac8: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_3aca:
	/* 0x3aca: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3acd:
	/* 0x3acd: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_3ad0:
	/* 0x3ad0: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_3ad5:
	/* 0x3ad5: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ad7:
	/* 0x3ad7: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3ada:
	/* 0x3ada: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_3ade:
	/* 0x3ade: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_3ae0:
	/* 0x3ae0: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_3ae4:
	/* 0x3ae4: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3ae6:
	/* 0x3ae6: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_3ae9:
	/* 0x3ae9: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3aeb:
	/* 0x3aeb: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3aef:
	/* 0x3aef: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3af2:
	/* 0x3af2: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3af7:
	/* 0x3af7: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_3afd:
	/* 0x3afd: jb     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1821ULL;
	}
x86_l_3b03:
	/* 0x3b03: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_3b09:
	/* 0x3b09: ja     71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1821ULL;
	}
x86_l_3b0f:
	/* 0x3b0f: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3b12:
	/* 0x3b12: jbe    3b19 <generic_retkprobe_event+0x3b19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3b19;
	}
x86_l_3b14:
	/* 0x3b14: mov    BYTE PTR [r14+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_3b19:
	/* 0x3b19: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b1b:
	/* 0x3b1b: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3b1e:
	/* 0x3b1e: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_3b22:
	/* 0x3b22: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3b25:
	/* 0x3b25: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3b28:
	/* 0x3b28: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3b2b:
	/* 0x3b2b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b30:
	/* 0x3b30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b32:
	/* 0x3b32: mov    QWORD PTR [rsp+0x58],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3b37:
	/* 0x3b37: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3b3a:
	/* 0x3b3a: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3b3f:
	/* 0x3b3f: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_3b45:
	/* 0x3b45: jbe    71d <generic_retkprobe_event+0x71d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1821ULL;
	}
x86_l_3b4b:
	/* 0x3b4b: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3b53:
	/* 0x3b53: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3b58:
	/* 0x3b58: jmp    71d <generic_retkprobe_event+0x71d> */
	return 1821ULL;
x86_l_3b5d:
	/* 0x3b5d: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b61:
	/* 0x3b61: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b66:
	/* 0x3b66: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3b6b:
	/* 0x3b6b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b70:
	/* 0x3b70: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b75:
	/* 0x3b75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b77:
	/* 0x3b77: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3b7c:
	/* 0x3b7c: cmp    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_3b81:
	/* 0x3b81: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3b86:
	/* 0x3b86: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3b8b:
	/* 0x3b8b: je     712 <generic_retkprobe_event+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1810ULL;
	}
x86_l_3b91:
	/* 0x3b91: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3b95:
	/* 0x3b95: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3b9a:
	/* 0x3b9a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b9f:
	/* 0x3b9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ba4:
	/* 0x3ba4: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3ba7:
	/* 0x3ba7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ba9:
	/* 0x3ba9: jmp    717 <generic_retkprobe_event+0x717> */
	return 1815ULL;
x86_l_3bae:
	/* 0x3bae: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3bb0:
	/* 0x3bb0: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3bb5:
	/* 0x3bb5: cmp    QWORD PTR [rsp+0xa8],0x7 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505735ULL);
x86_l_3bbe:
	/* 0x3bbe: jb     2897 <generic_retkprobe_event+0x2897> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10391ULL;
	}
x86_l_3bc4:
	/* 0x3bc4: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3bcc:
	/* 0x3bcc: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_3bd0:
	/* 0x3bd0: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3bd5:
	/* 0x3bd5: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_3bdb:
	/* 0x3bdb: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3be0:
	/* 0x3be0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3be5:
	/* 0x3be5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3bea:
	/* 0x3bea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bec:
	/* 0x3bec: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_3bf1:
	/* 0x3bf1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3bf3:
	/* 0x3bf3: js     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c54;
	}
x86_l_3bf5:
	/* 0x3bf5: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3bfa:
	/* 0x3bfa: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3bff:
	/* 0x3bff: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_3c02:
	/* 0x3c02: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_3c05:
	/* 0x3c05: cmovb  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_3c09:
	/* 0x3c09: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_3c0c:
	/* 0x3c0c: cmove  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_E);
x86_l_3c10:
	/* 0x3c10: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_3c15:
	/* 0x3c15: cmp    r12,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4094ULL);
x86_l_3c1c:
	/* 0x3c1c: ja     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3c54;
	}
x86_l_3c1e:
	/* 0x3c1e: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3c23:
	/* 0x3c23: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3c26:
	/* 0x3c26: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3c2c:
	/* 0x3c2c: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3c2f:
	/* 0x3c2f: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3c34:
	/* 0x3c34: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c39:
	/* 0x3c39: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3c3e:
	/* 0x3c3e: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_3c41:
	/* 0x3c41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c43:
	/* 0x3c43: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_3c48:
	/* 0x3c48: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c4a:
	/* 0x3c4a: js     3c54 <generic_retkprobe_event+0x3c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c54;
	}
x86_l_3c4c:
	/* 0x3c4c: add    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3c4f:
	/* 0x3c4f: jmp    289a <generic_retkprobe_event+0x289a> */
	return 10394ULL;
x86_l_3c54:
	/* 0x3c54: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3c59:
	/* 0x3c59: mov    DWORD PTR [rbx+rax*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3c5c:
	/* 0x3c5c: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3c5f:
	/* 0x3c5f: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3c62:
	/* 0x3c62: mov    r13,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_64);
x86_l_3c65:
	/* 0x3c65: mov    r12,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3c6d:
	/* 0x3c6d: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_3c72:
	/* 0x3c72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c74:
	/* 0x3c74: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3c77:
	/* 0x3c77: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3c7c:
	/* 0x3c7c: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_3c83:
	/* 0x3c83: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3c8b:
	/* 0x3c8b: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3c90:
	/* 0x3c90: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c95:
	/* 0x3c95: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_3c9a:
	/* 0x3c9a: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_3c9f:
	/* 0x3c9f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ca4:
	/* 0x3ca4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ca6:
	/* 0x3ca6: mov    eax,DWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3cad:
	/* 0x3cad: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3cb1:
	/* 0x3cb1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_3cb8:
	/* 0x3cb8: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3cbd:
	/* 0x3cbd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3cc2:
	/* 0x3cc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cc4:
	/* 0x3cc4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3cc7:
	/* 0x3cc7: je     3cd7 <generic_retkprobe_event+0x3cd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cd7;
	}
x86_l_3cc9:
	/* 0x3cc9: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3ccc:
	/* 0x3ccc: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3cd1:
	/* 0x3cd1: jne    3eb1 <generic_retkprobe_event+0x3eb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 16049ULL;
	}
x86_l_3cd7:
	/* 0x3cd7: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_3cdc:
	/* 0x3cdc: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3ce1:
	/* 0x3ce1: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3ce4:
	/* 0x3ce4: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3ce9:
	/* 0x3ce9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cee:
	/* 0x3cee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3cf3:
	/* 0x3cf3: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_3cf8:
	/* 0x3cf8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cfd:
	/* 0x3cfd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cff:
	/* 0x3cff: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3d04:
	/* 0x3d04: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_3d07:
	/* 0x3d07: je     3eae <generic_retkprobe_event+0x3eae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16046ULL;
	}
x86_l_3d0d:
	/* 0x3d0d: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_3d14:
	/* 0x3d14: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3d1c:
	/* 0x3d1c: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3d21:
	/* 0x3d21: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d26:
	/* 0x3d26: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_3d2b:
	/* 0x3d2b: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_3d30:
	/* 0x3d30: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3d35:
	/* 0x3d35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d37:
	/* 0x3d37: mov    eax,DWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3d3e:
	/* 0x3d3e: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3d42:
	/* 0x3d42: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_3d49:
	/* 0x3d49: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3d4e:
	/* 0x3d4e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3d53:
	/* 0x3d53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d55:
	/* 0x3d55: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3d58:
	/* 0x3d58: je     3d68 <generic_retkprobe_event+0x3d68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d68;
	}
x86_l_3d5a:
	/* 0x3d5a: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3d5d:
	/* 0x3d5d: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3d62:
	/* 0x3d62: jne    3eb1 <generic_retkprobe_event+0x3eb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 16049ULL;
	}
x86_l_3d68:
	/* 0x3d68: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_3d6d:
	/* 0x3d6d: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3d72:
	/* 0x3d72: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3d75:
	/* 0x3d75: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3d7a:
	/* 0x3d7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d7f:
	/* 0x3d7f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d84:
	/* 0x3d84: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_3d89:
	/* 0x3d89: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d8e:
	/* 0x3d8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d90:
	/* 0x3d90: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3d95:
	/* 0x3d95: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_3d98:
	/* 0x3d98: je     3eae <generic_retkprobe_event+0x3eae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16046ULL;
	}
x86_l_3d9e:
	/* 0x3d9e: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_3da5:
	/* 0x3da5: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3dad:
	/* 0x3dad: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3db2:
	/* 0x3db2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3db7:
	/* 0x3db7: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_3dbc:
	/* 0x3dbc: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_3dc1:
	/* 0x3dc1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3dc6:
	/* 0x3dc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dc8:
	/* 0x3dc8: mov    eax,DWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3dcf:
	/* 0x3dcf: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3dd3:
	/* 0x3dd3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_3dda:
	/* 0x3dda: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3ddf:
	/* 0x3ddf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3de4:
	/* 0x3de4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3de6:
	/* 0x3de6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3de9:
	/* 0x3de9: je     3df9 <generic_retkprobe_event+0x3df9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3df9;
	}
x86_l_3deb:
	/* 0x3deb: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3dee:
	/* 0x3dee: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3df3:
	/* 0x3df3: jne    3eb1 <generic_retkprobe_event+0x3eb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 16049ULL;
	}
x86_l_3df9:
	/* 0x3df9: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_3dfe:
	/* 0x3dfe: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3e03:
	/* 0x3e03: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3e06:
	/* 0x3e06: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3e0b:
	/* 0x3e0b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e10:
	/* 0x3e10: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3e15:
	/* 0x3e15: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_3e1a:
	/* 0x3e1a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e1f:
	/* 0x3e1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e21:
	/* 0x3e21: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3e26:
	/* 0x3e26: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_3e29:
	/* 0x3e29: je     3eae <generic_retkprobe_event+0x3eae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16046ULL;
	}
x86_l_3e2f:
	/* 0x3e2f: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_3e36:
	/* 0x3e36: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3e3e:
	/* 0x3e3e: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3e43:
	/* 0x3e43: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3e48:
	/* 0x3e48: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_3e4d:
	/* 0x3e4d: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_3e52:
	/* 0x3e52: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e57:
	/* 0x3e57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e59:
	/* 0x3e59: mov    eax,DWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3e60:
	/* 0x3e60: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3e64:
	/* 0x3e64: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_3e6b:
	/* 0x3e6b: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3e70:
	/* 0x3e70: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
	return 15989ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15989ULL: goto x86_l_3e75;
	case 15991ULL: goto x86_l_3e77;
	case 15994ULL: goto x86_l_3e7a;
	case 15996ULL: goto x86_l_3e7c;
	case 15999ULL: goto x86_l_3e7f;
	case 16004ULL: goto x86_l_3e84;
	case 16006ULL: goto x86_l_3e86;
	case 16011ULL: goto x86_l_3e8b;
	case 16016ULL: goto x86_l_3e90;
	case 16019ULL: goto x86_l_3e93;
	case 16024ULL: goto x86_l_3e98;
	case 16029ULL: goto x86_l_3e9d;
	case 16034ULL: goto x86_l_3ea2;
	case 16039ULL: goto x86_l_3ea7;
	case 16044ULL: goto x86_l_3eac;
	case 16046ULL: goto x86_l_3eae;
	case 16049ULL: goto x86_l_3eb1;
	case 16056ULL: goto x86_l_3eb8;
	case 16060ULL: goto x86_l_3ebc;
	case 16065ULL: goto x86_l_3ec1;
	case 16067ULL: goto x86_l_3ec3;
	case 16071ULL: goto x86_l_3ec7;
	case 16074ULL: goto x86_l_3eca;
	case 16076ULL: goto x86_l_3ecc;
	case 16079ULL: goto x86_l_3ecf;
	case 16083ULL: goto x86_l_3ed3;
	case 16087ULL: goto x86_l_3ed7;
	case 16091ULL: goto x86_l_3edb;
	case 16099ULL: goto x86_l_3ee3;
	case 16103ULL: goto x86_l_3ee7;
	case 16107ULL: goto x86_l_3eeb;
	case 16111ULL: goto x86_l_3eef;
	case 16118ULL: goto x86_l_3ef6;
	case 16123ULL: goto x86_l_3efb;
	case 16128ULL: goto x86_l_3f00;
	case 16136ULL: goto x86_l_3f08;
	case 16141ULL: goto x86_l_3f0d;
	case 16143ULL: goto x86_l_3f0f;
	case 16148ULL: goto x86_l_3f14;
	case 16150ULL: goto x86_l_3f16;
	case 16157ULL: goto x86_l_3f1d;
	case 16158ULL: goto x86_l_3f1e;
	case 16160ULL: goto x86_l_3f20;
	case 16162ULL: goto x86_l_3f22;
	case 16164ULL: goto x86_l_3f24;
	case 16166ULL: goto x86_l_3f26;
	case 16167ULL: goto x86_l_3f27;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3e75:
	/* 0x3e75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e77:
	/* 0x3e77: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e7a:
	/* 0x3e7a: je     3e86 <generic_retkprobe_event+0x3e86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e86;
	}
x86_l_3e7c:
	/* 0x3e7c: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3e7f:
	/* 0x3e7f: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3e84:
	/* 0x3e84: jne    3eb1 <generic_retkprobe_event+0x3eb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3eb1;
	}
x86_l_3e86:
	/* 0x3e86: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_3e8b:
	/* 0x3e8b: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3e90:
	/* 0x3e90: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3e93:
	/* 0x3e93: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3e98:
	/* 0x3e98: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e9d:
	/* 0x3e9d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ea2:
	/* 0x3ea2: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_3ea7:
	/* 0x3ea7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3eac:
	/* 0x3eac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3eae:
	/* 0x3eae: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3eb1:
	/* 0x3eb1: mov    DWORD PTR [r15],0x10d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 269ULL);
x86_l_3eb8:
	/* 0x3eb8: mov    DWORD PTR [r15+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3ebc:
	/* 0x3ebc: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_3ec1:
	/* 0x3ec1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ec3:
	/* 0x3ec3: mov    QWORD PTR [r15+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ec7:
	/* 0x3ec7: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_3eca:
	/* 0x3eca: je     3edb <generic_retkprobe_event+0x3edb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3edb;
	}
x86_l_3ecc:
	/* 0x3ecc: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ecf:
	/* 0x3ecf: mov    DWORD PTR [r15+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ed3:
	/* 0x3ed3: mov    rax,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ed7:
	/* 0x3ed7: mov    QWORD PTR [r15+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3edb:
	/* 0x3edb: mov    DWORD PTR [r15+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_3ee3:
	/* 0x3ee3: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ee7:
	/* 0x3ee7: mov    QWORD PTR [r15+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3eeb:
	/* 0x3eeb: mov    DWORD PTR [r15+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3eef:
	/* 0x3eef: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_3ef6:
	/* 0x3ef6: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_3efb:
	/* 0x3efb: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3f00:
	/* 0x3f00: mov    rdi,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_3f08:
	/* 0x3f08: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3f0d:
	/* 0x3f0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f0f:
	/* 0x3f0f: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_3f14:
	/* 0x3f14: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_3f16:
	/* 0x3f16: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_3f1d:
	/* 0x3f1d: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3f1e:
	/* 0x3f1e: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3f20:
	/* 0x3f20: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_3f22:
	/* 0x3f22: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3f24:
	/* 0x3f24: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3f26:
	/* 0x3f26: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3f27:
	/* 0x3f27: jmp    3f2c <generic_retkprobe_event+0x3f2c> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 14012U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1929ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1932ULL && __x86_pc <= 3663ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3667ULL && __x86_pc <= 5515ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5519ULL && __x86_pc <= 7329ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7336ULL && __x86_pc <= 9193ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9195ULL && __x86_pc <= 10886ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10891ULL && __x86_pc <= 12494ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12497ULL && __x86_pc <= 14275ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14280ULL && __x86_pc <= 15984ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 15989ULL && __x86_pc <= 16167ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_generic_retkprobe_event_x86_chunk_9(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

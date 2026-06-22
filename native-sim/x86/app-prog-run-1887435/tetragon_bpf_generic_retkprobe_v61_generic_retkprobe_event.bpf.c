extern char CONFIG_ITER_NUM;
extern char buffer_heap_map;
extern char config_map;
extern char execve_map;
extern char fdinstall_map;
extern char process_call_heap;
extern char retkprobe_calls;
extern char retprobe_map;
extern char socktrack_map;
extern char tg_ipv6_ext_heap;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 17ULL: goto x86_l_11;
	case 25ULL: goto x86_l_19;
	case 36ULL: goto x86_l_24;
	case 41ULL: goto x86_l_29;
	case 48ULL: goto x86_l_30;
	case 56ULL: goto x86_l_38;
	case 58ULL: goto x86_l_3a;
	case 60ULL: goto x86_l_3c;
	case 63ULL: goto x86_l_3f;
	case 69ULL: goto x86_l_45;
	case 72ULL: goto x86_l_48;
	case 75ULL: goto x86_l_4b;
	case 82ULL: goto x86_l_52;
	case 93ULL: goto x86_l_5d;
	case 98ULL: goto x86_l_62;
	case 105ULL: goto x86_l_69;
	case 107ULL: goto x86_l_6b;
	case 110ULL: goto x86_l_6e;
	case 116ULL: goto x86_l_74;
	case 119ULL: goto x86_l_77;
	case 121ULL: goto x86_l_79;
	case 125ULL: goto x86_l_7d;
	case 130ULL: goto x86_l_82;
	case 132ULL: goto x86_l_84;
	case 136ULL: goto x86_l_88;
	case 138ULL: goto x86_l_8a;
	case 143ULL: goto x86_l_8f;
	case 147ULL: goto x86_l_93;
	case 152ULL: goto x86_l_98;
	case 154ULL: goto x86_l_9a;
	case 157ULL: goto x86_l_9d;
	case 161ULL: goto x86_l_a1;
	case 165ULL: goto x86_l_a5;
	case 170ULL: goto x86_l_aa;
	case 175ULL: goto x86_l_af;
	case 180ULL: goto x86_l_b4;
	case 187ULL: goto x86_l_bb;
	case 192ULL: goto x86_l_c0;
	case 194ULL: goto x86_l_c2;
	case 197ULL: goto x86_l_c5;
	case 203ULL: goto x86_l_cb;
	case 206ULL: goto x86_l_ce;
	case 210ULL: goto x86_l_d2;
	case 218ULL: goto x86_l_da;
	case 222ULL: goto x86_l_de;
	case 227ULL: goto x86_l_e3;
	case 234ULL: goto x86_l_ea;
	case 239ULL: goto x86_l_ef;
	case 241ULL: goto x86_l_f1;
	case 248ULL: goto x86_l_f8;
	case 252ULL: goto x86_l_fc;
	case 256ULL: goto x86_l_100;
	case 259ULL: goto x86_l_103;
	case 267ULL: goto x86_l_10b;
	case 272ULL: goto x86_l_110;
	case 278ULL: goto x86_l_116;
	case 282ULL: goto x86_l_11a;
	case 292ULL: goto x86_l_124;
	case 300ULL: goto x86_l_12c;
	case 311ULL: goto x86_l_137;
	case 316ULL: goto x86_l_13c;
	case 323ULL: goto x86_l_143;
	case 331ULL: goto x86_l_14b;
	case 333ULL: goto x86_l_14d;
	case 336ULL: goto x86_l_150;
	case 342ULL: goto x86_l_156;
	case 348ULL: goto x86_l_15c;
	case 354ULL: goto x86_l_162;
	case 365ULL: goto x86_l_16d;
	case 367ULL: goto x86_l_16f;
	case 373ULL: goto x86_l_175;
	case 378ULL: goto x86_l_17a;
	case 384ULL: goto x86_l_180;
	case 388ULL: goto x86_l_184;
	case 392ULL: goto x86_l_188;
	case 395ULL: goto x86_l_18b;
	case 401ULL: goto x86_l_191;
	case 404ULL: goto x86_l_194;
	case 410ULL: goto x86_l_19a;
	case 413ULL: goto x86_l_19d;
	case 417ULL: goto x86_l_1a1;
	case 420ULL: goto x86_l_1a4;
	case 424ULL: goto x86_l_1a8;
	case 428ULL: goto x86_l_1ac;
	case 433ULL: goto x86_l_1b1;
	case 438ULL: goto x86_l_1b6;
	case 445ULL: goto x86_l_1bd;
	case 453ULL: goto x86_l_1c5;
	case 458ULL: goto x86_l_1ca;
	case 460ULL: goto x86_l_1cc;
	case 462ULL: goto x86_l_1ce;
	case 467ULL: goto x86_l_1d3;
	case 473ULL: goto x86_l_1d9;
	case 480ULL: goto x86_l_1e0;
	case 483ULL: goto x86_l_1e3;
	case 489ULL: goto x86_l_1e9;
	case 497ULL: goto x86_l_1f1;
	case 500ULL: goto x86_l_1f4;
	case 504ULL: goto x86_l_1f8;
	case 512ULL: goto x86_l_200;
	case 515ULL: goto x86_l_203;
	case 521ULL: goto x86_l_209;
	case 526ULL: goto x86_l_20e;
	case 534ULL: goto x86_l_216;
	case 540ULL: goto x86_l_21c;
	case 545ULL: goto x86_l_221;
	case 550ULL: goto x86_l_226;
	case 555ULL: goto x86_l_22b;
	case 563ULL: goto x86_l_233;
	case 565ULL: goto x86_l_235;
	case 570ULL: goto x86_l_23a;
	case 572ULL: goto x86_l_23c;
	case 578ULL: goto x86_l_242;
	case 583ULL: goto x86_l_247;
	case 586ULL: goto x86_l_24a;
	case 589ULL: goto x86_l_24d;
	case 593ULL: goto x86_l_251;
	case 596ULL: goto x86_l_254;
	case 600ULL: goto x86_l_258;
	case 605ULL: goto x86_l_25d;
	case 612ULL: goto x86_l_264;
	case 618ULL: goto x86_l_26a;
	case 621ULL: goto x86_l_26d;
	case 625ULL: goto x86_l_271;
	case 630ULL: goto x86_l_276;
	case 634ULL: goto x86_l_27a;
	case 639ULL: goto x86_l_27f;
	case 644ULL: goto x86_l_284;
	case 647ULL: goto x86_l_287;
	case 649ULL: goto x86_l_289;
	case 654ULL: goto x86_l_28e;
	case 656ULL: goto x86_l_290;
	case 662ULL: goto x86_l_296;
	case 665ULL: goto x86_l_299;
	case 668ULL: goto x86_l_29c;
	case 674ULL: goto x86_l_2a2;
	case 677ULL: goto x86_l_2a5;
	case 682ULL: goto x86_l_2aa;
	case 687ULL: goto x86_l_2af;
	case 693ULL: goto x86_l_2b5;
	case 698ULL: goto x86_l_2ba;
	case 701ULL: goto x86_l_2bd;
	case 706ULL: goto x86_l_2c2;
	case 710ULL: goto x86_l_2c6;
	case 714ULL: goto x86_l_2ca;
	case 717ULL: goto x86_l_2cd;
	case 723ULL: goto x86_l_2d3;
	case 728ULL: goto x86_l_2d8;
	case 735ULL: goto x86_l_2df;
	case 743ULL: goto x86_l_2e7;
	case 745ULL: goto x86_l_2e9;
	case 752ULL: goto x86_l_2f0;
	case 756ULL: goto x86_l_2f4;
	case 763ULL: goto x86_l_2fb;
	case 766ULL: goto x86_l_2fe;
	case 772ULL: goto x86_l_304;
	case 775ULL: goto x86_l_307;
	case 781ULL: goto x86_l_30d;
	case 789ULL: goto x86_l_315;
	case 792ULL: goto x86_l_318;
	case 796ULL: goto x86_l_31c;
	case 804ULL: goto x86_l_324;
	case 808ULL: goto x86_l_328;
	case 812ULL: goto x86_l_32c;
	case 819ULL: goto x86_l_333;
	case 825ULL: goto x86_l_339;
	case 829ULL: goto x86_l_33d;
	case 833ULL: goto x86_l_341;
	case 837ULL: goto x86_l_345;
	case 843ULL: goto x86_l_34b;
	case 848ULL: goto x86_l_350;
	case 851ULL: goto x86_l_353;
	case 859ULL: goto x86_l_35b;
	case 861ULL: goto x86_l_35d;
	case 866ULL: goto x86_l_362;
	case 868ULL: goto x86_l_364;
	case 870ULL: goto x86_l_366;
	case 874ULL: goto x86_l_36a;
	case 878ULL: goto x86_l_36e;
	case 880ULL: goto x86_l_370;
	case 883ULL: goto x86_l_373;
	case 886ULL: goto x86_l_376;
	case 890ULL: goto x86_l_37a;
	case 895ULL: goto x86_l_37f;
	case 898ULL: goto x86_l_382;
	case 903ULL: goto x86_l_387;
	case 910ULL: goto x86_l_38e;
	case 915ULL: goto x86_l_393;
	case 924ULL: goto x86_l_39c;
	case 928ULL: goto x86_l_3a0;
	case 933ULL: goto x86_l_3a5;
	case 941ULL: goto x86_l_3ad;
	case 943ULL: goto x86_l_3af;
	case 947ULL: goto x86_l_3b3;
	case 949ULL: goto x86_l_3b5;
	case 953ULL: goto x86_l_3b9;
	case 959ULL: goto x86_l_3bf;
	case 963ULL: goto x86_l_3c3;
	case 969ULL: goto x86_l_3c9;
	case 974ULL: goto x86_l_3ce;
	case 979ULL: goto x86_l_3d3;
	case 984ULL: goto x86_l_3d8;
	case 989ULL: goto x86_l_3dd;
	case 991ULL: goto x86_l_3df;
	case 996ULL: goto x86_l_3e4;
	case 1001ULL: goto x86_l_3e9;
	case 1003ULL: goto x86_l_3eb;
	case 1006ULL: goto x86_l_3ee;
	case 1010ULL: goto x86_l_3f2;
	case 1015ULL: goto x86_l_3f7;
	case 1019ULL: goto x86_l_3fb;
	case 1022ULL: goto x86_l_3fe;
	case 1027ULL: goto x86_l_403;
	case 1031ULL: goto x86_l_407;
	case 1037ULL: goto x86_l_40d;
	case 1041ULL: goto x86_l_411;
	case 1047ULL: goto x86_l_417;
	case 1052ULL: goto x86_l_41c;
	case 1057ULL: goto x86_l_421;
	case 1062ULL: goto x86_l_426;
	case 1064ULL: goto x86_l_428;
	case 1076ULL: goto x86_l_434;
	case 1084ULL: goto x86_l_43c;
	case 1092ULL: goto x86_l_444;
	case 1094ULL: goto x86_l_446;
	case 1098ULL: goto x86_l_44a;
	case 1103ULL: goto x86_l_44f;
	case 1108ULL: goto x86_l_454;
	case 1113ULL: goto x86_l_459;
	case 1118ULL: goto x86_l_45e;
	case 1123ULL: goto x86_l_463;
	case 1125ULL: goto x86_l_465;
	case 1130ULL: goto x86_l_46a;
	case 1134ULL: goto x86_l_46e;
	case 1139ULL: goto x86_l_473;
	case 1150ULL: goto x86_l_47e;
	case 1155ULL: goto x86_l_483;
	case 1162ULL: goto x86_l_48a;
	case 1170ULL: goto x86_l_492;
	case 1172ULL: goto x86_l_494;
	case 1175ULL: goto x86_l_497;
	case 1181ULL: goto x86_l_49d;
	case 1184ULL: goto x86_l_4a0;
	case 1190ULL: goto x86_l_4a6;
	case 1195ULL: goto x86_l_4ab;
	case 1200ULL: goto x86_l_4b0;
	case 1202ULL: goto x86_l_4b2;
	case 1209ULL: goto x86_l_4b9;
	case 1214ULL: goto x86_l_4be;
	case 1222ULL: goto x86_l_4c6;
	case 1227ULL: goto x86_l_4cb;
	case 1229ULL: goto x86_l_4cd;
	case 1237ULL: goto x86_l_4d5;
	case 1241ULL: goto x86_l_4d9;
	case 1249ULL: goto x86_l_4e1;
	case 1254ULL: goto x86_l_4e6;
	case 1258ULL: goto x86_l_4ea;
	case 1263ULL: goto x86_l_4ef;
	case 1271ULL: goto x86_l_4f7;
	case 1276ULL: goto x86_l_4fc;
	case 1284ULL: goto x86_l_504;
	case 1286ULL: goto x86_l_506;
	case 1294ULL: goto x86_l_50e;
	case 1298ULL: goto x86_l_512;
	case 1303ULL: goto x86_l_517;
	case 1308ULL: goto x86_l_51c;
	case 1313ULL: goto x86_l_521;
	case 1315ULL: goto x86_l_523;
	case 1321ULL: goto x86_l_529;
	case 1327ULL: goto x86_l_52f;
	case 1329ULL: goto x86_l_531;
	case 1334ULL: goto x86_l_536;
	case 1336ULL: goto x86_l_538;
	case 1338ULL: goto x86_l_53a;
	case 1343ULL: goto x86_l_53f;
	case 1348ULL: goto x86_l_544;
	case 1352ULL: goto x86_l_548;
	case 1357ULL: goto x86_l_54d;
	case 1362ULL: goto x86_l_552;
	case 1367ULL: goto x86_l_557;
	case 1369ULL: goto x86_l_559;
	case 1374ULL: goto x86_l_55e;
	case 1379ULL: goto x86_l_563;
	case 1381ULL: goto x86_l_565;
	case 1384ULL: goto x86_l_568;
	case 1391ULL: goto x86_l_56f;
	case 1401ULL: goto x86_l_579;
	case 1409ULL: goto x86_l_581;
	case 1420ULL: goto x86_l_58c;
	case 1426ULL: goto x86_l_592;
	case 1435ULL: goto x86_l_59b;
	case 1444ULL: goto x86_l_5a4;
	case 1449ULL: goto x86_l_5a9;
	case 1454ULL: goto x86_l_5ae;
	case 1459ULL: goto x86_l_5b3;
	case 1468ULL: goto x86_l_5bc;
	case 1477ULL: goto x86_l_5c5;
	case 1486ULL: goto x86_l_5ce;
	case 1491ULL: goto x86_l_5d3;
	case 1496ULL: goto x86_l_5d8;
	case 1504ULL: goto x86_l_5e0;
	case 1509ULL: goto x86_l_5e5;
	case 1517ULL: goto x86_l_5ed;
	case 1521ULL: goto x86_l_5f1;
	case 1526ULL: goto x86_l_5f6;
	case 1531ULL: goto x86_l_5fb;
	case 1536ULL: goto x86_l_600;
	case 1539ULL: goto x86_l_603;
	case 1541ULL: goto x86_l_605;
	case 1546ULL: goto x86_l_60a;
	case 1549ULL: goto x86_l_60d;
	case 1554ULL: goto x86_l_612;
	case 1562ULL: goto x86_l_61a;
	case 1564ULL: goto x86_l_61c;
	case 1569ULL: goto x86_l_621;
	case 1572ULL: goto x86_l_624;
	case 1577ULL: goto x86_l_629;
	case 1585ULL: goto x86_l_631;
	case 1587ULL: goto x86_l_633;
	case 1592ULL: goto x86_l_638;
	case 1595ULL: goto x86_l_63b;
	case 1600ULL: goto x86_l_640;
	case 1605ULL: goto x86_l_645;
	case 1607ULL: goto x86_l_647;
	case 1612ULL: goto x86_l_64c;
	case 1616ULL: goto x86_l_650;
	case 1621ULL: goto x86_l_655;
	case 1628ULL: goto x86_l_65c;
	case 1631ULL: goto x86_l_65f;
	case 1637ULL: goto x86_l_665;
	case 1643ULL: goto x86_l_66b;
	case 1648ULL: goto x86_l_670;
	case 1653ULL: goto x86_l_675;
	case 1658ULL: goto x86_l_67a;
	case 1663ULL: goto x86_l_67f;
	case 1668ULL: goto x86_l_684;
	case 1670ULL: goto x86_l_686;
	case 1675ULL: goto x86_l_68b;
	case 1681ULL: goto x86_l_691;
	case 1686ULL: goto x86_l_696;
	case 1694ULL: goto x86_l_69e;
	case 1699ULL: goto x86_l_6a3;
	case 1701ULL: goto x86_l_6a5;
	case 1709ULL: goto x86_l_6ad;
	case 1715ULL: goto x86_l_6b3;
	case 1719ULL: goto x86_l_6b7;
	case 1724ULL: goto x86_l_6bc;
	case 1729ULL: goto x86_l_6c1;
	case 1734ULL: goto x86_l_6c6;
	case 1737ULL: goto x86_l_6c9;
	case 1739ULL: goto x86_l_6cb;
	case 1744ULL: goto x86_l_6d0;
	case 1750ULL: goto x86_l_6d6;
	case 1755ULL: goto x86_l_6db;
	case 1763ULL: goto x86_l_6e3;
	case 1768ULL: goto x86_l_6e8;
	case 1771ULL: goto x86_l_6eb;
	case 1773ULL: goto x86_l_6ed;
	case 1777ULL: goto x86_l_6f1;
	case 1782ULL: goto x86_l_6f6;
	case 1787ULL: goto x86_l_6fb;
	case 1792ULL: goto x86_l_700;
	case 1795ULL: goto x86_l_703;
	case 1797ULL: goto x86_l_705;
	case 1802ULL: goto x86_l_70a;
	case 1807ULL: goto x86_l_70f;
	case 1811ULL: goto x86_l_713;
	case 1814ULL: goto x86_l_716;
	case 1821ULL: goto x86_l_71d;
	case 1823ULL: goto x86_l_71f;
	case 1825ULL: goto x86_l_721;
	case 1830ULL: goto x86_l_726;
	case 1833ULL: goto x86_l_729;
	case 1838ULL: goto x86_l_72e;
	case 1841ULL: goto x86_l_731;
	case 1843ULL: goto x86_l_733;
	case 1847ULL: goto x86_l_737;
	case 1849ULL: goto x86_l_739;
	case 1852ULL: goto x86_l_73c;
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
	/* 0xa: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    rax,QWORD PTR [rdi+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_11:
	/* 0x11: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_19:
	/* 0x19: mov    DWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_24:
	/* 0x24: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29:
	/* 0x29: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_30:
	/* 0x30: lea    rsi,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_38:
	/* 0x38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a:
	/* 0x3a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c:
	/* 0x3c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f:
	/* 0x3f: je     2d6b <generic_retkprobe_event+0x2d6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11627ULL;
	}
x86_l_45:
	/* 0x45: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_48:
	/* 0x48: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_4b:
	/* 0x4b: lea    rsi,[rax+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_52:
	/* 0x52: mov    DWORD PTR [r15+0x5ef8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104419244900352ULL);
x86_l_5d:
	/* 0x5d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_62:
	/* 0x62: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_69:
	/* 0x69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b:
	/* 0x6b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6e:
	/* 0x6e: je     2d6b <generic_retkprobe_event+0x2d6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11627ULL;
	}
x86_l_74:
	/* 0x74: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_77:
	/* 0x77: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_79:
	/* 0x79: mov    QWORD PTR [rbx+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7d:
	/* 0x7d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_82:
	/* 0x82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_84:
	/* 0x84: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_88:
	/* 0x88: jne    8f <generic_retkprobe_event+0x8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8f;
	}
x86_l_8a:
	/* 0x8a: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8f:
	/* 0x8f: mov    QWORD PTR [rbx+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_93:
	/* 0x93: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_98:
	/* 0x98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a:
	/* 0x9a: mov    DWORD PTR [rbx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_9d:
	/* 0x9d: mov    rax,QWORD PTR [rbx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a1:
	/* 0xa1: mov    rcx,QWORD PTR [rbx+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a5:
	/* 0xa5: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_aa:
	/* 0xaa: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_af:
	/* 0xaf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b4:
	/* 0xb4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_bb:
	/* 0xbb: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c0:
	/* 0xc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2:
	/* 0xc2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c5:
	/* 0xc5: je     2d6b <generic_retkprobe_event+0x2d6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11627ULL;
	}
x86_l_cb:
	/* 0xcb: mov    r14,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce:
	/* 0xce: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d2:
	/* 0xd2: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_da:
	/* 0xda: mov    rbp,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_de:
	/* 0xde: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_e3:
	/* 0xe3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_ea:
	/* 0xea: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_ef:
	/* 0xef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f1:
	/* 0xf1: mov    QWORD PTR [rbx+0x90],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_f8:
	/* 0xf8: mov    eax,DWORD PTR [r13+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_fc:
	/* 0xfc: mov    r14d,DWORD PTR [r13+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_100:
	/* 0x100: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_103:
	/* 0x103: mov    QWORD PTR [rsp+0xe8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_10b:
	/* 0x10b: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_110:
	/* 0x110: je     1d3 <generic_retkprobe_event+0x1d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d3;
	}
x86_l_116:
	/* 0x116: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11a:
	/* 0x11a: mov    DWORD PTR [rbx+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104041287778304ULL);
x86_l_124:
	/* 0x124: mov    r13,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_12c:
	/* 0x12c: mov    DWORD PTR [rsp+0xdc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_137:
	/* 0x137: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13c:
	/* 0x13c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_143:
	/* 0x143: lea    rsi,[rsp+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_14b:
	/* 0x14b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d:
	/* 0x14d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_150:
	/* 0x150: je     2ba <generic_retkprobe_event+0x2ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ba;
	}
x86_l_156:
	/* 0x156: mov    ecx,DWORD PTR [rax+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24224ULL);
x86_l_15c:
	/* 0x15c: mov    DWORD PTR [rax+0x98],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_162:
	/* 0x162: mov    QWORD PTR [rax+0x5e78],0xc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103869489086476ULL);
x86_l_16d:
	/* 0x16d: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_16f:
	/* 0x16f: je     387 <generic_retkprobe_event+0x387> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_387;
	}
x86_l_175:
	/* 0x175: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17a:
	/* 0x17a: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_180:
	/* 0x180: add    r14,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_184:
	/* 0x184: mov    eax,DWORD PTR [r13+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_188:
	/* 0x188: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_18b:
	/* 0x18b: je     2d3 <generic_retkprobe_event+0x2d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d3;
	}
x86_l_191:
	/* 0x191: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_194:
	/* 0x194: jne    2e9 <generic_retkprobe_event+0x2e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e9;
	}
x86_l_19a:
	/* 0x19a: mov    eax,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19d:
	/* 0x19d: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1a1:
	/* 0x1a1: mov    eax,DWORD PTR [rbx+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1a4:
	/* 0x1a4: mov    DWORD PTR [rsp+0x4c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1a8:
	/* 0x1a8: mov    rax,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ac:
	/* 0x1ac: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b1:
	/* 0x1b1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b6:
	/* 0x1b6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_1bd:
	/* 0x1bd: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1c5:
	/* 0x1c5: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1ca:
	/* 0x1ca: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cc:
	/* 0x1cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ce:
	/* 0x1ce: jmp    2e9 <generic_retkprobe_event+0x2e9> */
	goto x86_l_2e9;
x86_l_1d3:
	/* 0x1d3: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_1d9:
	/* 0x1d9: add    r15,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1e0:
	/* 0x1e0: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1e3:
	/* 0x1e3: jne    304 <generic_retkprobe_event+0x304> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_304;
	}
x86_l_1e9:
	/* 0x1e9: mov    DWORD PTR [r15+r14*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1f1:
	/* 0x1f1: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_1f4:
	/* 0x1f4: lea    rbp,[r14+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f8:
	/* 0x1f8: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_200:
	/* 0x200: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_203:
	/* 0x203: je     3eb <generic_retkprobe_event+0x3eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3eb;
	}
x86_l_209:
	/* 0x209: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20e:
	/* 0x20e: mov    r12,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_216:
	/* 0x216: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_21c:
	/* 0x21c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_221:
	/* 0x221: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_226:
	/* 0x226: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_22b:
	/* 0x22b: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_233:
	/* 0x233: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_235:
	/* 0x235: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_23a:
	/* 0x23a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23c:
	/* 0x23c: js     2b28 <generic_retkprobe_event+0x2b28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11048ULL;
	}
x86_l_242:
	/* 0x242: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_247:
	/* 0x247: cmp    rsi,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_24a:
	/* 0x24a: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_24d:
	/* 0x24d: cmovb  r12,rsi */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RSI, X86_WIDTH_64, X86_CC_B);
x86_l_251:
	/* 0x251: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_254:
	/* 0x254: cmovne rsi,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_258:
	/* 0x258: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_25d:
	/* 0x25d: cmp    rsi,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 4094ULL);
x86_l_264:
	/* 0x264: ja     2b28 <generic_retkprobe_event+0x2b28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11048ULL;
	}
x86_l_26a:
	/* 0x26a: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_26d:
	/* 0x26d: add    r14,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_271:
	/* 0x271: mov    QWORD PTR [rsp+0x8],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_276:
	/* 0x276: lea    rdi,[r15+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_27a:
	/* 0x27a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27f:
	/* 0x27f: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_284:
	/* 0x284: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_287:
	/* 0x287: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_289:
	/* 0x289: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_28e:
	/* 0x28e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_290:
	/* 0x290: js     2b28 <generic_retkprobe_event+0x2b28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11048ULL;
	}
x86_l_296:
	/* 0x296: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_299:
	/* 0x299: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_29c:
	/* 0x29c: je     991 <generic_retkprobe_event+0x991> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2449ULL;
	}
x86_l_2a2:
	/* 0x2a2: sub    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2a5:
	/* 0x2a5: mov    QWORD PTR [rsp+0x10],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2aa:
	/* 0x2aa: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2af:
	/* 0x2af: jne    99d <generic_retkprobe_event+0x99d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2461ULL;
	}
x86_l_2b5:
	/* 0x2b5: jmp    3ee <generic_retkprobe_event+0x3ee> */
	goto x86_l_3ee;
x86_l_2ba:
	/* 0x2ba: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bd:
	/* 0x2bd: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c2:
	/* 0x2c2: add    r14,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c6:
	/* 0x2c6: mov    eax,DWORD PTR [r13+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2ca:
	/* 0x2ca: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_2cd:
	/* 0x2cd: jne    191 <generic_retkprobe_event+0x191> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_191;
	}
x86_l_2d3:
	/* 0x2d3: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2d8:
	/* 0x2d8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_2df:
	/* 0x2df: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2e7:
	/* 0x2e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e9:
	/* 0x2e9: and    r14d,0x1fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 8191ULL);
x86_l_2f0:
	/* 0x2f0: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f4:
	/* 0x2f4: add    r15,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2fb:
	/* 0x2fb: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2fe:
	/* 0x2fe: je     1e9 <generic_retkprobe_event+0x1e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e9;
	}
x86_l_304:
	/* 0x304: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_307:
	/* 0x307: jne    2b3c <generic_retkprobe_event+0x2b3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11068ULL;
	}
x86_l_30d:
	/* 0x30d: mov    DWORD PTR [r15+r14*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_315:
	/* 0x315: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_318:
	/* 0x318: add    r14,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_31c:
	/* 0x31c: mov    rbp,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_324:
	/* 0x324: lea    r13,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_328:
	/* 0x328: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_32c:
	/* 0x32c: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_333:
	/* 0x333: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_339:
	/* 0x339: cmovb  r12,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_64, X86_CC_B);
x86_l_33d:
	/* 0x33d: lea    rdi,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_341:
	/* 0x341: add    rdi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_345:
	/* 0x345: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_34b:
	/* 0x34b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_350:
	/* 0x350: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_353:
	/* 0x353: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_35b:
	/* 0x35b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35d:
	/* 0x35d: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_362:
	/* 0x362: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_364:
	/* 0x364: js     373 <generic_retkprobe_event+0x373> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_373;
	}
x86_l_366:
	/* 0x366: mov    DWORD PTR [r13+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_36a:
	/* 0x36a: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_36e:
	/* 0x36e: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_370:
	/* 0x370: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_373:
	/* 0x373: add    r15,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_376:
	/* 0x376: mov    DWORD PTR [r13+0x0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37a:
	/* 0x37a: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_37f:
	/* 0x37f: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_382:
	/* 0x382: jmp    2b3c <generic_retkprobe_event+0x2b3c> */
	return 11068ULL;
x86_l_387:
	/* 0x387: lea    r12,[rax+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_38e:
	/* 0x38e: mov    QWORD PTR [rsp+0x48],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_393:
	/* 0x393: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_39c:
	/* 0x39c: cmp    r14d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 23ULL);
x86_l_3a0:
	/* 0x3a0: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a5:
	/* 0x3a5: mov    QWORD PTR [rsp+0x88],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3ad:
	/* 0x3ad: jle    403 <generic_retkprobe_event+0x403> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_403;
	}
x86_l_3af:
	/* 0x3af: cmp    r14d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 42ULL);
x86_l_3b3:
	/* 0x3b3: je     428 <generic_retkprobe_event+0x428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_428;
	}
x86_l_3b5:
	/* 0x3b5: cmp    r14d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 37ULL);
x86_l_3b9:
	/* 0x3b9: je     446 <generic_retkprobe_event+0x446> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_446;
	}
x86_l_3bf:
	/* 0x3bf: cmp    r14d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 24ULL);
x86_l_3c3:
	/* 0x3c3: jne    8de <generic_retkprobe_event+0x8de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2270ULL;
	}
x86_l_3c9:
	/* 0x3c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ce:
	/* 0x3ce: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3d3:
	/* 0x3d3: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3d8:
	/* 0x3d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3dd:
	/* 0x3dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3df:
	/* 0x3df: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e4:
	/* 0x3e4: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3e9:
	/* 0x3e9: jmp    417 <generic_retkprobe_event+0x417> */
	goto x86_l_417;
x86_l_3eb:
	/* 0x3eb: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ee:
	/* 0x3ee: mov    DWORD PTR [r15+rbp*1],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3f2:
	/* 0x3f2: mov    DWORD PTR [r15+rbp*1+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 4ULL);
x86_l_3f7:
	/* 0x3f7: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3fb:
	/* 0x3fb: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_3fe:
	/* 0x3fe: jmp    2b31 <generic_retkprobe_event+0x2b31> */
	return 11057ULL;
x86_l_403:
	/* 0x403: cmp    r14d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 15ULL);
x86_l_407:
	/* 0x407: je     832 <generic_retkprobe_event+0x832> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2098ULL;
	}
x86_l_40d:
	/* 0x40d: cmp    r14d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 16ULL);
x86_l_411:
	/* 0x411: jne    8de <generic_retkprobe_event+0x8de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2270ULL;
	}
x86_l_417:
	/* 0x417: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_41c:
	/* 0x41c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_421:
	/* 0x421: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_426:
	/* 0x426: jmp    45e <generic_retkprobe_event+0x45e> */
	goto x86_l_45e;
x86_l_428:
	/* 0x428: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_434:
	/* 0x434: mov    QWORD PTR [rsp+0x98],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_43c:
	/* 0x43c: lea    rax,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_444:
	/* 0x444: jmp    46e <generic_retkprobe_event+0x46e> */
	goto x86_l_46e;
x86_l_446:
	/* 0x446: add    r13,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_44a:
	/* 0x44a: mov    QWORD PTR [rsp+0x48],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_44f:
	/* 0x44f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_454:
	/* 0x454: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_459:
	/* 0x459: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_45e:
	/* 0x45e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_463:
	/* 0x463: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_465:
	/* 0x465: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_46a:
	/* 0x46a: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_46e:
	/* 0x46e: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_473:
	/* 0x473: mov    DWORD PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_47e:
	/* 0x47e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_483:
	/* 0x483: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_48a:
	/* 0x48a: lea    rsi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_492:
	/* 0x492: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_494:
	/* 0x494: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_497:
	/* 0x497: je     538 <generic_retkprobe_event+0x538> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_538;
	}
x86_l_49d:
	/* 0x49d: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_4a0:
	/* 0x4a0: add    rax,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_4a6:
	/* 0x4a6: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ab:
	/* 0x4ab: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_4b0:
	/* 0x4b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b2:
	/* 0x4b2: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_4b9:
	/* 0x4b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4be:
	/* 0x4be: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_4c6:
	/* 0x4c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cb:
	/* 0x4cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cd:
	/* 0x4cd: mov    r13,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_4d5:
	/* 0x4d5: lea    rax,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d9:
	/* 0x4d9: mov    QWORD PTR [rsp+0xf0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_4e1:
	/* 0x4e1: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e6:
	/* 0x4e6: lea    rdx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ea:
	/* 0x4ea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4ef:
	/* 0x4ef: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_4f7:
	/* 0x4f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fc:
	/* 0x4fc: mov    QWORD PTR [rsp+0xe0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_504:
	/* 0x504: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_506:
	/* 0x506: mov    rbp,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_50e:
	/* 0x50e: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_512:
	/* 0x512: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_517:
	/* 0x517: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_51c:
	/* 0x51c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_521:
	/* 0x521: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_523:
	/* 0x523: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_529:
	/* 0x529: mov    r14d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4096ULL);
x86_l_52f:
	/* 0x52f: je     544 <generic_retkprobe_event+0x544> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_544;
	}
x86_l_531:
	/* 0x531: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_536:
	/* 0x536: jmp    592 <generic_retkprobe_event+0x592> */
	goto x86_l_592;
x86_l_538:
	/* 0x538: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_53a:
	/* 0x53a: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_53f:
	/* 0x53f: jmp    1ccc <generic_retkprobe_event+0x1ccc> */
	return 7372ULL;
x86_l_544:
	/* 0x544: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_548:
	/* 0x548: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_54d:
	/* 0x54d: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_552:
	/* 0x552: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_557:
	/* 0x557: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_559:
	/* 0x559: cmp    QWORD PTR [rsp+0x48],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_55e:
	/* 0x55e: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_563:
	/* 0x563: je     592 <generic_retkprobe_event+0x592> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_592;
	}
x86_l_565:
	/* 0x565: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_568:
	/* 0x568: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_56f:
	/* 0x56f: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_579:
	/* 0x579: mov    QWORD PTR [r12+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_581:
	/* 0x581: mov    WORD PTR [r12+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_58c:
	/* 0x58c: mov    r14d,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4086ULL);
x86_l_592:
	/* 0x592: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_59b:
	/* 0x59b: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_5a4:
	/* 0x5a4: mov    QWORD PTR [rsp+0x58],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5a9:
	/* 0x5a9: lea    r12,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5ae:
	/* 0x5ae: lea    rbp,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5b3:
	/* 0x5b3: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_5bc:
	/* 0x5bc: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_5c5:
	/* 0x5c5: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_5ce:
	/* 0x5ce: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d3:
	/* 0x5d3: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5d8:
	/* 0x5d8: mov    DWORD PTR [rsp+0x80],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5e0:
	/* 0x5e0: lea    r14,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5e5:
	/* 0x5e5: mov    BYTE PTR [rsp+0x84],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_5ed:
	/* 0x5ed: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_5f1:
	/* 0x5f1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5f6:
	/* 0x5f6: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5fb:
	/* 0x5fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_600:
	/* 0x600: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_603:
	/* 0x603: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_605:
	/* 0x605: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_60a:
	/* 0x60a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_60d:
	/* 0x60d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_612:
	/* 0x612: mov    rdx,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_61a:
	/* 0x61a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61c:
	/* 0x61c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_621:
	/* 0x621: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_624:
	/* 0x624: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_629:
	/* 0x629: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_631:
	/* 0x631: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_633:
	/* 0x633: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_638:
	/* 0x638: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_63b:
	/* 0x63b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_640:
	/* 0x640: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_645:
	/* 0x645: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_647:
	/* 0x647: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_64c:
	/* 0x64c: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_650:
	/* 0x650: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_655:
	/* 0x655: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_65c:
	/* 0x65c: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_65f:
	/* 0x65f: je     813 <generic_retkprobe_event+0x813> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2067ULL;
	}
x86_l_665:
	/* 0x665: mov    r14d,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2048ULL);
x86_l_66b:
	/* 0x66b: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_670:
	/* 0x670: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_675:
	/* 0x675: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_67a:
	/* 0x67a: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_67f:
	/* 0x67f: cmp    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_684:
	/* 0x684: jne    691 <generic_retkprobe_event+0x691> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_691;
	}
x86_l_686:
	/* 0x686: cmp    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 80ULL);
x86_l_68b:
	/* 0x68b: je     984 <generic_retkprobe_event+0x984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2436ULL;
	}
x86_l_691:
	/* 0x691: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_696:
	/* 0x696: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_69e:
	/* 0x69e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6a3:
	/* 0x6a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a5:
	/* 0x6a5: cmp    rbp,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 176ULL);
x86_l_6ad:
	/* 0x6ad: je     7af <generic_retkprobe_event+0x7af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1967ULL;
	}
x86_l_6b3:
	/* 0x6b3: lea    r13,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6b7:
	/* 0x6b7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6bc:
	/* 0x6bc: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6c1:
	/* 0x6c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6c6:
	/* 0x6c6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_6c9:
	/* 0x6c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6cb:
	/* 0x6cb: cmp    QWORD PTR [rsp+0x18],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6d0:
	/* 0x6d0: je     7af <generic_retkprobe_event+0x7af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1967ULL;
	}
x86_l_6d6:
	/* 0x6d6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6db:
	/* 0x6db: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_6e3:
	/* 0x6e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6e8:
	/* 0x6e8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_6eb:
	/* 0x6eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ed:
	/* 0x6ed: add    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_6f1:
	/* 0x6f1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6f6:
	/* 0x6f6: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6fb:
	/* 0x6fb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_700:
	/* 0x700: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_703:
	/* 0x703: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_705:
	/* 0x705: mov    r12,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_70a:
	/* 0x70a: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_70f:
	/* 0x70f: mov    ecx,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_713:
	/* 0x713: sub    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_716:
	/* 0x716: mov    esi,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_71d:
	/* 0x71d: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_71f:
	/* 0x71f: sub    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_721:
	/* 0x721: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_726:
	/* 0x726: cmovb  edx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_729:
	/* 0x729: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_72e:
	/* 0x72e: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_731:
	/* 0x731: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_733:
	/* 0x733: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_737:
	/* 0x737: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_739:
	/* 0x739: cmovb  edi,esi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_32, X86_CC_B);
x86_l_73c:
	/* 0x73c: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
	return 1855ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1855ULL: goto x86_l_73f;
	case 1858ULL: goto x86_l_742;
	case 1861ULL: goto x86_l_745;
	case 1869ULL: goto x86_l_74d;
	case 1872ULL: goto x86_l_750;
	case 1877ULL: goto x86_l_755;
	case 1883ULL: goto x86_l_75b;
	case 1889ULL: goto x86_l_761;
	case 1895ULL: goto x86_l_767;
	case 1897ULL: goto x86_l_769;
	case 1903ULL: goto x86_l_76f;
	case 1907ULL: goto x86_l_773;
	case 1912ULL: goto x86_l_778;
	case 1916ULL: goto x86_l_77c;
	case 1920ULL: goto x86_l_780;
	case 1923ULL: goto x86_l_783;
	case 1928ULL: goto x86_l_788;
	case 1930ULL: goto x86_l_78a;
	case 1935ULL: goto x86_l_78f;
	case 1940ULL: goto x86_l_794;
	case 1948ULL: goto x86_l_79c;
	case 1953ULL: goto x86_l_7a1;
	case 1956ULL: goto x86_l_7a4;
	case 1962ULL: goto x86_l_7aa;
	case 1967ULL: goto x86_l_7af;
	case 1972ULL: goto x86_l_7b4;
	case 1977ULL: goto x86_l_7b9;
	case 1982ULL: goto x86_l_7be;
	case 1987ULL: goto x86_l_7c3;
	case 1989ULL: goto x86_l_7c5;
	case 1994ULL: goto x86_l_7ca;
	case 1999ULL: goto x86_l_7cf;
	case 2005ULL: goto x86_l_7d5;
	case 2009ULL: goto x86_l_7d9;
	case 2014ULL: goto x86_l_7de;
	case 2019ULL: goto x86_l_7e3;
	case 2024ULL: goto x86_l_7e8;
	case 2027ULL: goto x86_l_7eb;
	case 2029ULL: goto x86_l_7ed;
	case 2034ULL: goto x86_l_7f2;
	case 2039ULL: goto x86_l_7f7;
	case 2043ULL: goto x86_l_7fb;
	case 2048ULL: goto x86_l_800;
	case 2053ULL: goto x86_l_805;
	case 2056ULL: goto x86_l_808;
	case 2062ULL: goto x86_l_80e;
	case 2067ULL: goto x86_l_813;
	case 2072ULL: goto x86_l_818;
	case 2079ULL: goto x86_l_81f;
	case 2084ULL: goto x86_l_824;
	case 2089ULL: goto x86_l_829;
	case 2091ULL: goto x86_l_82b;
	case 2093ULL: goto x86_l_82d;
	case 2098ULL: goto x86_l_832;
	case 2103ULL: goto x86_l_837;
	case 2108ULL: goto x86_l_83c;
	case 2113ULL: goto x86_l_841;
	case 2118ULL: goto x86_l_846;
	case 2120ULL: goto x86_l_848;
	case 2125ULL: goto x86_l_84d;
	case 2130ULL: goto x86_l_852;
	case 2133ULL: goto x86_l_855;
	case 2139ULL: goto x86_l_85b;
	case 2150ULL: goto x86_l_866;
	case 2155ULL: goto x86_l_86b;
	case 2162ULL: goto x86_l_872;
	case 2170ULL: goto x86_l_87a;
	case 2172ULL: goto x86_l_87c;
	case 2175ULL: goto x86_l_87f;
	case 2181ULL: goto x86_l_885;
	case 2183ULL: goto x86_l_887;
	case 2187ULL: goto x86_l_88b;
	case 2192ULL: goto x86_l_890;
	case 2198ULL: goto x86_l_896;
	case 2202ULL: goto x86_l_89a;
	case 2208ULL: goto x86_l_8a0;
	case 2212ULL: goto x86_l_8a4;
	case 2218ULL: goto x86_l_8aa;
	case 2222ULL: goto x86_l_8ae;
	case 2228ULL: goto x86_l_8b4;
	case 2232ULL: goto x86_l_8b8;
	case 2238ULL: goto x86_l_8be;
	case 2242ULL: goto x86_l_8c2;
	case 2248ULL: goto x86_l_8c8;
	case 2258ULL: goto x86_l_8d2;
	case 2265ULL: goto x86_l_8d9;
	case 2270ULL: goto x86_l_8de;
	case 2274ULL: goto x86_l_8e2;
	case 2280ULL: goto x86_l_8e8;
	case 2283ULL: goto x86_l_8eb;
	case 2293ULL: goto x86_l_8f5;
	case 2297ULL: goto x86_l_8f9;
	case 2303ULL: goto x86_l_8ff;
	case 2308ULL: goto x86_l_904;
	case 2319ULL: goto x86_l_90f;
	case 2324ULL: goto x86_l_914;
	case 2331ULL: goto x86_l_91b;
	case 2339ULL: goto x86_l_923;
	case 2341ULL: goto x86_l_925;
	case 2343ULL: goto x86_l_927;
	case 2346ULL: goto x86_l_92a;
	case 2352ULL: goto x86_l_930;
	case 2356ULL: goto x86_l_934;
	case 2364ULL: goto x86_l_93c;
	case 2370ULL: goto x86_l_942;
	case 2374ULL: goto x86_l_946;
	case 2379ULL: goto x86_l_94b;
	case 2385ULL: goto x86_l_951;
	case 2389ULL: goto x86_l_955;
	case 2395ULL: goto x86_l_95b;
	case 2399ULL: goto x86_l_95f;
	case 2402ULL: goto x86_l_962;
	case 2408ULL: goto x86_l_968;
	case 2413ULL: goto x86_l_96d;
	case 2418ULL: goto x86_l_972;
	case 2423ULL: goto x86_l_977;
	case 2426ULL: goto x86_l_97a;
	case 2431ULL: goto x86_l_97f;
	case 2436ULL: goto x86_l_984;
	case 2444ULL: goto x86_l_98c;
	case 2449ULL: goto x86_l_991;
	case 2451ULL: goto x86_l_993;
	case 2456ULL: goto x86_l_998;
	case 2461ULL: goto x86_l_99d;
	case 2470ULL: goto x86_l_9a6;
	case 2472ULL: goto x86_l_9a8;
	case 2475ULL: goto x86_l_9ab;
	case 2480ULL: goto x86_l_9b0;
	case 2488ULL: goto x86_l_9b8;
	case 2492ULL: goto x86_l_9bc;
	case 2498ULL: goto x86_l_9c2;
	case 2503ULL: goto x86_l_9c7;
	case 2508ULL: goto x86_l_9cc;
	case 2513ULL: goto x86_l_9d1;
	case 2515ULL: goto x86_l_9d3;
	case 2520ULL: goto x86_l_9d8;
	case 2522ULL: goto x86_l_9da;
	case 2528ULL: goto x86_l_9e0;
	case 2533ULL: goto x86_l_9e5;
	case 2538ULL: goto x86_l_9ea;
	case 2541ULL: goto x86_l_9ed;
	case 2544ULL: goto x86_l_9f0;
	case 2548ULL: goto x86_l_9f4;
	case 2551ULL: goto x86_l_9f7;
	case 2555ULL: goto x86_l_9fb;
	case 2560ULL: goto x86_l_a00;
	case 2567ULL: goto x86_l_a07;
	case 2573ULL: goto x86_l_a0d;
	case 2578ULL: goto x86_l_a12;
	case 2581ULL: goto x86_l_a15;
	case 2586ULL: goto x86_l_a1a;
	case 2590ULL: goto x86_l_a1e;
	case 2595ULL: goto x86_l_a23;
	case 2600ULL: goto x86_l_a28;
	case 2605ULL: goto x86_l_a2d;
	case 2610ULL: goto x86_l_a32;
	case 2612ULL: goto x86_l_a34;
	case 2617ULL: goto x86_l_a39;
	case 2622ULL: goto x86_l_a3e;
	case 2624ULL: goto x86_l_a40;
	case 2630ULL: goto x86_l_a46;
	case 2633ULL: goto x86_l_a49;
	case 2638ULL: goto x86_l_a4e;
	case 2641ULL: goto x86_l_a51;
	case 2647ULL: goto x86_l_a57;
	case 2650ULL: goto x86_l_a5a;
	case 2653ULL: goto x86_l_a5d;
	case 2659ULL: goto x86_l_a63;
	case 2664ULL: goto x86_l_a68;
	case 2672ULL: goto x86_l_a70;
	case 2677ULL: goto x86_l_a75;
	case 2682ULL: goto x86_l_a7a;
	case 2687ULL: goto x86_l_a7f;
	case 2690ULL: goto x86_l_a82;
	case 2693ULL: goto x86_l_a85;
	case 2695ULL: goto x86_l_a87;
	case 2703ULL: goto x86_l_a8f;
	case 2706ULL: goto x86_l_a92;
	case 2713ULL: goto x86_l_a99;
	case 2718ULL: goto x86_l_a9e;
	case 2720ULL: goto x86_l_aa0;
	case 2722ULL: goto x86_l_aa2;
	case 2725ULL: goto x86_l_aa5;
	case 2728ULL: goto x86_l_aa8;
	case 2733ULL: goto x86_l_aad;
	case 2739ULL: goto x86_l_ab3;
	case 2742ULL: goto x86_l_ab6;
	case 2745ULL: goto x86_l_ab9;
	case 2748ULL: goto x86_l_abc;
	case 2750ULL: goto x86_l_abe;
	case 2752ULL: goto x86_l_ac0;
	case 2757ULL: goto x86_l_ac5;
	case 2764ULL: goto x86_l_acc;
	case 2770ULL: goto x86_l_ad2;
	case 2775ULL: goto x86_l_ad7;
	case 2777ULL: goto x86_l_ad9;
	case 2779ULL: goto x86_l_adb;
	case 2784ULL: goto x86_l_ae0;
	case 2790ULL: goto x86_l_ae6;
	case 2795ULL: goto x86_l_aeb;
	case 2800ULL: goto x86_l_af0;
	case 2805ULL: goto x86_l_af5;
	case 2813ULL: goto x86_l_afd;
	case 2815ULL: goto x86_l_aff;
	case 2820ULL: goto x86_l_b04;
	case 2825ULL: goto x86_l_b09;
	case 2829ULL: goto x86_l_b0d;
	case 2834ULL: goto x86_l_b12;
	case 2839ULL: goto x86_l_b17;
	case 2841ULL: goto x86_l_b19;
	case 2846ULL: goto x86_l_b1e;
	case 2851ULL: goto x86_l_b23;
	case 2856ULL: goto x86_l_b28;
	case 2861ULL: goto x86_l_b2d;
	case 2863ULL: goto x86_l_b2f;
	case 2868ULL: goto x86_l_b34;
	case 2876ULL: goto x86_l_b3c;
	case 2881ULL: goto x86_l_b41;
	case 2889ULL: goto x86_l_b49;
	case 2892ULL: goto x86_l_b4c;
	case 2898ULL: goto x86_l_b52;
	case 2900ULL: goto x86_l_b54;
	case 2906ULL: goto x86_l_b5a;
	case 2911ULL: goto x86_l_b5f;
	case 2913ULL: goto x86_l_b61;
	case 2918ULL: goto x86_l_b66;
	case 2922ULL: goto x86_l_b6a;
	case 2927ULL: goto x86_l_b6f;
	case 2933ULL: goto x86_l_b75;
	case 2937ULL: goto x86_l_b79;
	case 2942ULL: goto x86_l_b7e;
	case 2948ULL: goto x86_l_b84;
	case 2952ULL: goto x86_l_b88;
	case 2958ULL: goto x86_l_b8e;
	case 2962ULL: goto x86_l_b92;
	case 2968ULL: goto x86_l_b98;
	case 2973ULL: goto x86_l_b9d;
	case 2977ULL: goto x86_l_ba1;
	case 2983ULL: goto x86_l_ba7;
	case 2986ULL: goto x86_l_baa;
	case 2991ULL: goto x86_l_baf;
	case 2998ULL: goto x86_l_bb6;
	case 3005ULL: goto x86_l_bbd;
	case 3010ULL: goto x86_l_bc2;
	case 3015ULL: goto x86_l_bc7;
	case 3020ULL: goto x86_l_bcc;
	case 3023ULL: goto x86_l_bcf;
	case 3025ULL: goto x86_l_bd1;
	case 3032ULL: goto x86_l_bd8;
	case 3037ULL: goto x86_l_bdd;
	case 3042ULL: goto x86_l_be2;
	case 3047ULL: goto x86_l_be7;
	case 3049ULL: goto x86_l_be9;
	case 3056ULL: goto x86_l_bf0;
	case 3064ULL: goto x86_l_bf8;
	case 3069ULL: goto x86_l_bfd;
	case 3074ULL: goto x86_l_c02;
	case 3076ULL: goto x86_l_c04;
	case 3083ULL: goto x86_l_c0b;
	case 3091ULL: goto x86_l_c13;
	case 3096ULL: goto x86_l_c18;
	case 3101ULL: goto x86_l_c1d;
	case 3103ULL: goto x86_l_c1f;
	case 3110ULL: goto x86_l_c26;
	case 3118ULL: goto x86_l_c2e;
	case 3123ULL: goto x86_l_c33;
	case 3128ULL: goto x86_l_c38;
	case 3130ULL: goto x86_l_c3a;
	case 3137ULL: goto x86_l_c41;
	case 3145ULL: goto x86_l_c49;
	case 3150ULL: goto x86_l_c4e;
	case 3155ULL: goto x86_l_c53;
	case 3157ULL: goto x86_l_c55;
	case 3164ULL: goto x86_l_c5c;
	case 3172ULL: goto x86_l_c64;
	case 3180ULL: goto x86_l_c6c;
	case 3188ULL: goto x86_l_c74;
	case 3191ULL: goto x86_l_c77;
	case 3199ULL: goto x86_l_c7f;
	case 3207ULL: goto x86_l_c87;
	case 3210ULL: goto x86_l_c8a;
	case 3216ULL: goto x86_l_c90;
	case 3219ULL: goto x86_l_c93;
	case 3225ULL: goto x86_l_c99;
	case 3230ULL: goto x86_l_c9e;
	case 3235ULL: goto x86_l_ca3;
	case 3240ULL: goto x86_l_ca8;
	case 3242ULL: goto x86_l_caa;
	case 3247ULL: goto x86_l_caf;
	case 3250ULL: goto x86_l_cb2;
	case 3255ULL: goto x86_l_cb7;
	case 3258ULL: goto x86_l_cba;
	case 3263ULL: goto x86_l_cbf;
	case 3267ULL: goto x86_l_cc3;
	case 3270ULL: goto x86_l_cc6;
	case 3275ULL: goto x86_l_ccb;
	case 3278ULL: goto x86_l_cce;
	case 3280ULL: goto x86_l_cd0;
	case 3285ULL: goto x86_l_cd5;
	case 3290ULL: goto x86_l_cda;
	case 3294ULL: goto x86_l_cde;
	case 3300ULL: goto x86_l_ce4;
	case 3304ULL: goto x86_l_ce8;
	case 3310ULL: goto x86_l_cee;
	case 3314ULL: goto x86_l_cf2;
	case 3320ULL: goto x86_l_cf8;
	case 3324ULL: goto x86_l_cfc;
	case 3329ULL: goto x86_l_d01;
	case 3335ULL: goto x86_l_d07;
	case 3340ULL: goto x86_l_d0c;
	case 3344ULL: goto x86_l_d10;
	case 3347ULL: goto x86_l_d13;
	case 3352ULL: goto x86_l_d18;
	case 3358ULL: goto x86_l_d1e;
	case 3362ULL: goto x86_l_d22;
	case 3365ULL: goto x86_l_d25;
	case 3371ULL: goto x86_l_d2b;
	case 3375ULL: goto x86_l_d2f;
	case 3381ULL: goto x86_l_d35;
	case 3386ULL: goto x86_l_d3a;
	case 3391ULL: goto x86_l_d3f;
	case 3394ULL: goto x86_l_d42;
	case 3399ULL: goto x86_l_d47;
	case 3404ULL: goto x86_l_d4c;
	case 3407ULL: goto x86_l_d4f;
	case 3409ULL: goto x86_l_d51;
	case 3414ULL: goto x86_l_d56;
	case 3419ULL: goto x86_l_d5b;
	case 3422ULL: goto x86_l_d5e;
	case 3425ULL: goto x86_l_d61;
	case 3430ULL: goto x86_l_d66;
	case 3432ULL: goto x86_l_d68;
	case 3437ULL: goto x86_l_d6d;
	case 3442ULL: goto x86_l_d72;
	case 3445ULL: goto x86_l_d75;
	case 3452ULL: goto x86_l_d7c;
	case 3457ULL: goto x86_l_d81;
	case 3462ULL: goto x86_l_d86;
	case 3464ULL: goto x86_l_d88;
	case 3467ULL: goto x86_l_d8b;
	case 3470ULL: goto x86_l_d8e;
	case 3476ULL: goto x86_l_d94;
	case 3481ULL: goto x86_l_d99;
	case 3485ULL: goto x86_l_d9d;
	case 3491ULL: goto x86_l_da3;
	case 3495ULL: goto x86_l_da7;
	case 3498ULL: goto x86_l_daa;
	case 3504ULL: goto x86_l_db0;
	case 3509ULL: goto x86_l_db5;
	case 3512ULL: goto x86_l_db8;
	case 3517ULL: goto x86_l_dbd;
	case 3520ULL: goto x86_l_dc0;
	case 3522ULL: goto x86_l_dc2;
	case 3527ULL: goto x86_l_dc7;
	case 3532ULL: goto x86_l_dcc;
	case 3536ULL: goto x86_l_dd0;
	case 3542ULL: goto x86_l_dd6;
	case 3546ULL: goto x86_l_dda;
	case 3552ULL: goto x86_l_de0;
	case 3556ULL: goto x86_l_de4;
	case 3561ULL: goto x86_l_de9;
	case 3567ULL: goto x86_l_def;
	case 3570ULL: goto x86_l_df2;
	case 3575ULL: goto x86_l_df7;
	case 3580ULL: goto x86_l_dfc;
	case 3588ULL: goto x86_l_e04;
	case 3596ULL: goto x86_l_e0c;
	case 3604ULL: goto x86_l_e14;
	case 3612ULL: goto x86_l_e1c;
	case 3620ULL: goto x86_l_e24;
	case 3628ULL: goto x86_l_e2c;
	case 3636ULL: goto x86_l_e34;
	case 3644ULL: goto x86_l_e3c;
	case 3652ULL: goto x86_l_e44;
	case 3660ULL: goto x86_l_e4c;
	case 3668ULL: goto x86_l_e54;
	case 3676ULL: goto x86_l_e5c;
	case 3684ULL: goto x86_l_e64;
	case 3691ULL: goto x86_l_e6b;
	case 3696ULL: goto x86_l_e70;
	case 3701ULL: goto x86_l_e75;
	case 3704ULL: goto x86_l_e78;
	case 3706ULL: goto x86_l_e7a;
	case 3709ULL: goto x86_l_e7d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_73f:
	/* 0x73f: mov    r9d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RSI, X86_WIDTH_32);
x86_l_742:
	/* 0x742: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_745:
	/* 0x745: mov    DWORD PTR [rsp+0x80],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_74d:
	/* 0x74d: sub    rax,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_750:
	/* 0x750: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_755:
	/* 0x755: jb     a75 <generic_retkprobe_event+0xa75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_a75;
	}
x86_l_75b:
	/* 0x75b: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_761:
	/* 0x761: ja     a75 <generic_retkprobe_event+0xa75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_a75;
	}
x86_l_767:
	/* 0x767: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_769:
	/* 0x769: jbe    cbf <generic_retkprobe_event+0xcbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_cbf;
	}
x86_l_76f:
	/* 0x76f: lea    r13,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_773:
	/* 0x773: mov    BYTE PTR [r12+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_778:
	/* 0x778: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_77c:
	/* 0x77c: lea    rdi,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_780:
	/* 0x780: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_783:
	/* 0x783: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_788:
	/* 0x788: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78a:
	/* 0x78a: mov    QWORD PTR [rsp+0x78],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_78f:
	/* 0x78f: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_794:
	/* 0x794: mov    rax,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_79c:
	/* 0x79c: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7a1:
	/* 0x7a1: dec    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_7a4:
	/* 0x7a4: jne    670 <generic_retkprobe_event+0x670> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1648ULL;
	}
x86_l_7aa:
	/* 0x7aa: jmp    a75 <generic_retkprobe_event+0xa75> */
	goto x86_l_a75;
x86_l_7af:
	/* 0x7af: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7b4:
	/* 0x7b4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7b9:
	/* 0x7b9: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7be:
	/* 0x7be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7c3:
	/* 0x7c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c5:
	/* 0x7c5: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7ca:
	/* 0x7ca: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_7cf:
	/* 0x7cf: je     a68 <generic_retkprobe_event+0xa68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a68;
	}
x86_l_7d5:
	/* 0x7d5: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_7d9:
	/* 0x7d9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7de:
	/* 0x7de: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7e3:
	/* 0x7e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7e8:
	/* 0x7e8: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_7eb:
	/* 0x7eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ed:
	/* 0x7ed: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7f2:
	/* 0x7f2: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7f7:
	/* 0x7f7: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_7fb:
	/* 0x7fb: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_800:
	/* 0x800: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_805:
	/* 0x805: dec    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_808:
	/* 0x808: jne    670 <generic_retkprobe_event+0x670> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1648ULL;
	}
x86_l_80e:
	/* 0x80e: jmp    a75 <generic_retkprobe_event+0xa75> */
	goto x86_l_a75;
x86_l_813:
	/* 0x813: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_818:
	/* 0x818: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_81f:
	/* 0x81f: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_824:
	/* 0x824: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_829:
	/* 0x829: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_82b:
	/* 0x82b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_82d:
	/* 0x82d: jmp    a70 <generic_retkprobe_event+0xa70> */
	goto x86_l_a70;
x86_l_832:
	/* 0x832: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_837:
	/* 0x837: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_83c:
	/* 0x83c: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_841:
	/* 0x841: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_846:
	/* 0x846: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_848:
	/* 0x848: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_84d:
	/* 0x84d: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_852:
	/* 0x852: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_855:
	/* 0x855: jne    473 <generic_retkprobe_event+0x473> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1139ULL;
	}
x86_l_85b:
	/* 0x85b: mov    DWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_866:
	/* 0x866: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_86b:
	/* 0x86b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_872:
	/* 0x872: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_87a:
	/* 0x87a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_87c:
	/* 0x87c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_87f:
	/* 0x87f: je     1cb2 <generic_retkprobe_event+0x1cb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7346ULL;
	}
x86_l_885:
	/* 0x885: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_887:
	/* 0x887: cmp    r14d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 25ULL);
x86_l_88b:
	/* 0x88b: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_890:
	/* 0x890: jg     d99 <generic_retkprobe_event+0xd99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d99;
	}
x86_l_896:
	/* 0x896: cmp    r14d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 18ULL);
x86_l_89a:
	/* 0x89a: jle    ee4 <generic_retkprobe_event+0xee4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3812ULL;
	}
x86_l_8a0:
	/* 0x8a0: cmp    r14d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 20ULL);
x86_l_8a4:
	/* 0x8a4: jle    11f1 <generic_retkprobe_event+0x11f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4593ULL;
	}
x86_l_8aa:
	/* 0x8aa: cmp    r14d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 21ULL);
x86_l_8ae:
	/* 0x8ae: je     1ac3 <generic_retkprobe_event+0x1ac3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6851ULL;
	}
x86_l_8b4:
	/* 0x8b4: cmp    r14d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 22ULL);
x86_l_8b8:
	/* 0x8b8: je     1a3e <generic_retkprobe_event+0x1a3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6718ULL;
	}
x86_l_8be:
	/* 0x8be: cmp    r14d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 23ULL);
x86_l_8c2:
	/* 0x8c2: jne    1cb9 <generic_retkprobe_event+0x1cb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7353ULL;
	}
x86_l_8c8:
	/* 0x8c8: mov    DWORD PTR [rcx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_8d2:
	/* 0x8d2: mov    DWORD PTR [rcx+0x9c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_8d9:
	/* 0x8d9: jmp    f0d <generic_retkprobe_event+0xf0d> */
	return 3853ULL;
x86_l_8de:
	/* 0x8de: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_8e2:
	/* 0x8e2: ja     85b <generic_retkprobe_event+0x85b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_85b;
	}
x86_l_8e8:
	/* 0x8e8: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_8eb:
	/* 0x8eb: movabs rcx,0x11c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19524686609650ULL);
x86_l_8f5:
	/* 0x8f5: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_8f9:
	/* 0x8f9: jae    85b <generic_retkprobe_event+0x85b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_85b;
	}
x86_l_8ff:
	/* 0x8ff: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_904:
	/* 0x904: mov    DWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_90f:
	/* 0x90f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_914:
	/* 0x914: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_91b:
	/* 0x91b: lea    rsi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_923:
	/* 0x923: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_925:
	/* 0x925: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_927:
	/* 0x927: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_92a:
	/* 0x92a: je     1cb4 <generic_retkprobe_event+0x1cb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7348ULL;
	}
x86_l_930:
	/* 0x930: cmp    r14d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 16ULL);
x86_l_934:
	/* 0x934: mov    rdi,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_93c:
	/* 0x93c: jle    b66 <generic_retkprobe_event+0xb66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_b66;
	}
x86_l_942:
	/* 0x942: cmp    r14d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 30ULL);
x86_l_946:
	/* 0x946: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_94b:
	/* 0x94b: jle    cda <generic_retkprobe_event+0xcda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_cda;
	}
x86_l_951:
	/* 0x951: cmp    r14d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 38ULL);
x86_l_955:
	/* 0x955: jg     dcc <generic_retkprobe_event+0xdcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_dcc;
	}
x86_l_95b:
	/* 0x95b: lea    eax,[r14-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_95f:
	/* 0x95f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_962:
	/* 0x962: jae    12af <generic_retkprobe_event+0x12af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4783ULL;
	}
x86_l_968:
	/* 0x968: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_96d:
	/* 0x96d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_972:
	/* 0x972: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_977:
	/* 0x977: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_97a:
	/* 0x97a: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_97f:
	/* 0x97f: jmp    f85 <generic_retkprobe_event+0xf85> */
	return 3973ULL;
x86_l_984:
	/* 0x984: mov    BYTE PTR [rsp+0x84],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 566935683073ULL);
x86_l_98c:
	/* 0x98c: jmp    a75 <generic_retkprobe_event+0xa75> */
	goto x86_l_a75;
x86_l_991:
	/* 0x991: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_993:
	/* 0x993: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_998:
	/* 0x998: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_99d:
	/* 0x99d: cmp    QWORD PTR [rsp+0x88],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552257ULL);
x86_l_9a6:
	/* 0x9a6: jne    9b0 <generic_retkprobe_event+0x9b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9b0;
	}
x86_l_9a8:
	/* 0x9a8: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_9ab:
	/* 0x9ab: jmp    3ee <generic_retkprobe_event+0x3ee> */
	return 1006ULL;
x86_l_9b0:
	/* 0x9b0: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_9b8:
	/* 0x9b8: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9bc:
	/* 0x9bc: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_9c2:
	/* 0x9c2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9c7:
	/* 0x9c7: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9cc:
	/* 0x9cc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_9d1:
	/* 0x9d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d3:
	/* 0x9d3: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_9d8:
	/* 0x9d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9da:
	/* 0x9da: js     2b2d <generic_retkprobe_event+0x2b2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11053ULL;
	}
x86_l_9e0:
	/* 0x9e0: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9e5:
	/* 0x9e5: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9ea:
	/* 0x9ea: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_9ed:
	/* 0x9ed: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_9f0:
	/* 0x9f0: cmovb  r12,rsi */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RSI, X86_WIDTH_64, X86_CC_B);
x86_l_9f4:
	/* 0x9f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9f7:
	/* 0x9f7: cmovne rsi,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_9fb:
	/* 0x9fb: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_a00:
	/* 0xa00: cmp    rsi,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 4094ULL);
x86_l_a07:
	/* 0xa07: ja     2b2d <generic_retkprobe_event+0x2b2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11053ULL;
	}
x86_l_a0d:
	/* 0xa0d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a12:
	/* 0xa12: add    rax,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a15:
	/* 0xa15: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a1a:
	/* 0xa1a: lea    rdi,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_a1e:
	/* 0xa1e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a23:
	/* 0xa23: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a28:
	/* 0xa28: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a2d:
	/* 0xa2d: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a32:
	/* 0xa32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a34:
	/* 0xa34: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a39:
	/* 0xa39: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_a3e:
	/* 0xa3e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a40:
	/* 0xa40: js     2b2d <generic_retkprobe_event+0x2b2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11053ULL;
	}
x86_l_a46:
	/* 0xa46: add    r14,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a49:
	/* 0xa49: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a4e:
	/* 0xa4e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a51:
	/* 0xa51: je     16f6 <generic_retkprobe_event+0x16f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5878ULL;
	}
x86_l_a57:
	/* 0xa57: sub    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_a5a:
	/* 0xa5a: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_a5d:
	/* 0xa5d: jne    16f9 <generic_retkprobe_event+0x16f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5881ULL;
	}
x86_l_a63:
	/* 0xa63: jmp    17bf <generic_retkprobe_event+0x17bf> */
	return 6079ULL;
x86_l_a68:
	/* 0xa68: mov    BYTE PTR [rsp+0x84],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 566935683073ULL);
x86_l_a70:
	/* 0xa70: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a75:
	/* 0xa75: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a7a:
	/* 0xa7a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a7f:
	/* 0xa7f: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a82:
	/* 0xa82: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_a85:
	/* 0xa85: je     abe <generic_retkprobe_event+0xabe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_abe;
	}
x86_l_a87:
	/* 0xa87: cmp    BYTE PTR [rsp+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_a8f:
	/* 0xa8f: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_a92:
	/* 0xa92: mov    edx,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a99:
	/* 0xa99: mov    ebp,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_a9e:
	/* 0xa9e: sub    ebp,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_aa0:
	/* 0xaa0: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_aa2:
	/* 0xaa2: cmovle ebp,edx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_aa5:
	/* 0xaa5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aa8:
	/* 0xaa8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aad:
	/* 0xaad: je     b5f <generic_retkprobe_event+0xb5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b5f;
	}
x86_l_ab3:
	/* 0xab3: mov    r14b,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_8);
x86_l_ab6:
	/* 0xab6: add    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ab9:
	/* 0xab9: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_abc:
	/* 0xabc: jmp    ac5 <generic_retkprobe_event+0xac5> */
	goto x86_l_ac5;
x86_l_abe:
	/* 0xabe: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ac0:
	/* 0xac0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ac5:
	/* 0xac5: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_acc:
	/* 0xacc: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ad2:
	/* 0xad2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ad7:
	/* 0xad7: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_ad9:
	/* 0xad9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_adb:
	/* 0xadb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ae0:
	/* 0xae0: mov    DWORD PTR [rax+0x9c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_ae6:
	/* 0xae6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_aeb:
	/* 0xaeb: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_af0:
	/* 0xaf0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_af5:
	/* 0xaf5: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_afd:
	/* 0xafd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aff:
	/* 0xaff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b04:
	/* 0xb04: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b09:
	/* 0xb09: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_b0d:
	/* 0xb0d: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b12:
	/* 0xb12: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b17:
	/* 0xb17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b19:
	/* 0xb19: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b1e:
	/* 0xb1e: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b23:
	/* 0xb23: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b28:
	/* 0xb28: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_b2d:
	/* 0xb2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b2f:
	/* 0xb2f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b34:
	/* 0xb34: mov    DWORD PTR [rcx+rbp*1+0xa0],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 160ULL);
x86_l_b3c:
	/* 0xb3c: movzx  eax,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_b41:
	/* 0xb41: mov    WORD PTR [rcx+rbp*1+0xa4],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_RBP, 0), 164ULL);
x86_l_b49:
	/* 0xb49: add    ebp,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_b4c:
	/* 0xb4c: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_b52:
	/* 0xb52: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_b54:
	/* 0xb54: jns    1ccc <generic_retkprobe_event+0x1ccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 7372ULL;
	}
x86_l_b5a:
	/* 0xb5a: jmp    f9a <generic_retkprobe_event+0xf9a> */
	return 3994ULL;
x86_l_b5f:
	/* 0xb5f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b61:
	/* 0xb61: jmp    1ccc <generic_retkprobe_event+0x1ccc> */
	return 7372ULL;
x86_l_b66:
	/* 0xb66: cmp    r14d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 9ULL);
x86_l_b6a:
	/* 0xb6a: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b6f:
	/* 0xb6f: jg     d0c <generic_retkprobe_event+0xd0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d0c;
	}
x86_l_b75:
	/* 0xb75: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_b79:
	/* 0xb79: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b7e:
	/* 0xb7e: jle    f30 <generic_retkprobe_event+0xf30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3888ULL;
	}
x86_l_b84:
	/* 0xb84: cmp    r14d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 5ULL);
x86_l_b88:
	/* 0xb88: je     147f <generic_retkprobe_event+0x147f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5247ULL;
	}
x86_l_b8e:
	/* 0xb8e: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_b92:
	/* 0xb92: je     d6d <generic_retkprobe_event+0xd6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6d;
	}
x86_l_b98:
	/* 0xb98: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b9d:
	/* 0xb9d: cmp    r14d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 7ULL);
x86_l_ba1:
	/* 0xba1: jne    1cbe <generic_retkprobe_event+0x1cbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7358ULL;
	}
x86_l_ba7:
	/* 0xba7: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_baa:
	/* 0xbaa: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_baf:
	/* 0xbaf: mov    QWORD PTR [rcx+0xc4],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_bb6:
	/* 0xbb6: lea    rdi,[rcx+0xc2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_bbd:
	/* 0xbbd: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bc2:
	/* 0xbc2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bc7:
	/* 0xbc7: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_bcc:
	/* 0xbcc: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_bcf:
	/* 0xbcf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd1:
	/* 0xbd1: lea    rdi,[r14+0xd6] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_bd8:
	/* 0xbd8: lea    rdx,[r12+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_bdd:
	/* 0xbdd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_be2:
	/* 0xbe2: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_be7:
	/* 0xbe7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_be9:
	/* 0xbe9: lea    rdi,[r14+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_bf0:
	/* 0xbf0: lea    rdx,[r12+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_bf8:
	/* 0xbf8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bfd:
	/* 0xbfd: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c02:
	/* 0xc02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c04:
	/* 0xc04: lea    rdi,[r14+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_c0b:
	/* 0xc0b: lea    rdx,[r12+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_c13:
	/* 0xc13: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c18:
	/* 0xc18: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c1d:
	/* 0xc1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c1f:
	/* 0xc1f: lea    rdi,[r14+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_c26:
	/* 0xc26: lea    rdx,[r12+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_c2e:
	/* 0xc2e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c33:
	/* 0xc33: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c38:
	/* 0xc38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c3a:
	/* 0xc3a: lea    rdi,[r14+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_c41:
	/* 0xc41: lea    rdx,[r12+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_c49:
	/* 0xc49: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c4e:
	/* 0xc4e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c53:
	/* 0xc53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c55:
	/* 0xc55: lea    r13,[r14+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_c5c:
	/* 0xc5c: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c64:
	/* 0xc64: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_c6c:
	/* 0xc6c: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_c74:
	/* 0xc74: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_c77:
	/* 0xc77: mov    QWORD PTR [rbp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_c7f:
	/* 0xc7f: movzx  eax,WORD PTR [r14+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_c87:
	/* 0xc87: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_c8a:
	/* 0xc8a: je     1e4e <generic_retkprobe_event+0x1e4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7758ULL;
	}
x86_l_c90:
	/* 0xc90: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c93:
	/* 0xc93: jne    1e73 <generic_retkprobe_event+0x1e73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7795ULL;
	}
x86_l_c99:
	/* 0xc99: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c9e:
	/* 0xc9e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ca3:
	/* 0xca3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ca8:
	/* 0xca8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_caa:
	/* 0xcaa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_caf:
	/* 0xcaf: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_cb2:
	/* 0xcb2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cb7:
	/* 0xcb7: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_cba:
	/* 0xcba: jmp    1e71 <generic_retkprobe_event+0x1e71> */
	return 7793ULL;
x86_l_cbf:
	/* 0xcbf: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_cc3:
	/* 0xcc3: add    r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_cc6:
	/* 0xcc6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ccb:
	/* 0xccb: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_cce:
	/* 0xcce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd0:
	/* 0xcd0: mov    QWORD PTR [rsp+0x78],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_cd5:
	/* 0xcd5: jmp    a75 <generic_retkprobe_event+0xa75> */
	goto x86_l_a75;
x86_l_cda:
	/* 0xcda: cmp    r14d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 28ULL);
x86_l_cde:
	/* 0xcde: jg     f17 <generic_retkprobe_event+0xf17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3863ULL;
	}
x86_l_ce4:
	/* 0xce4: cmp    r14d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 17ULL);
x86_l_ce8:
	/* 0xce8: je     12f6 <generic_retkprobe_event+0x12f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4854ULL;
	}
x86_l_cee:
	/* 0xcee: cmp    r14d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 25ULL);
x86_l_cf2:
	/* 0xcf2: je     13c5 <generic_retkprobe_event+0x13c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5061ULL;
	}
x86_l_cf8:
	/* 0xcf8: cmp    r14d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 28ULL);
x86_l_cfc:
	/* 0xcfc: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d01:
	/* 0xd01: je     f40 <generic_retkprobe_event+0xf40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3904ULL;
	}
x86_l_d07:
	/* 0xd07: jmp    1cbe <generic_retkprobe_event+0x1cbe> */
	return 7358ULL;
x86_l_d0c:
	/* 0xd0c: lea    eax,[r14-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_d10:
	/* 0xd10: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d13:
	/* 0xd13: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d18:
	/* 0xd18: jb     f40 <generic_retkprobe_event+0xf40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3904ULL;
	}
x86_l_d1e:
	/* 0xd1e: lea    eax,[r14-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_d22:
	/* 0xd22: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d25:
	/* 0xd25: jb     f6e <generic_retkprobe_event+0xf6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3950ULL;
	}
x86_l_d2b:
	/* 0xd2b: cmp    r14d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 14ULL);
x86_l_d2f:
	/* 0xd2f: jne    1cbe <generic_retkprobe_event+0x1cbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7358ULL;
	}
x86_l_d35:
	/* 0xd35: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d3a:
	/* 0xd3a: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d3f:
	/* 0xd3f: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_d42:
	/* 0xd42: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d47:
	/* 0xd47: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d4c:
	/* 0xd4c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d4f:
	/* 0xd4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d51:
	/* 0xd51: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d56:
	/* 0xd56: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d5b:
	/* 0xd5b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_d5e:
	/* 0xd5e: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_d61:
	/* 0xd61: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d66:
	/* 0xd66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d68:
	/* 0xd68: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d6d:
	/* 0xd6d: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d72:
	/* 0xd72: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_d75:
	/* 0xd75: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_d7c:
	/* 0xd7c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_d81:
	/* 0xd81: mov    esi,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4097ULL);
x86_l_d86:
	/* 0xd86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d88:
	/* 0xd88: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_d8b:
	/* 0xd8b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d8e:
	/* 0xd8e: jns    1643 <generic_retkprobe_event+0x1643> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 5699ULL;
	}
x86_l_d94:
	/* 0xd94: jmp    1cfe <generic_retkprobe_event+0x1cfe> */
	return 7422ULL;
x86_l_d99:
	/* 0xd99: cmp    r14d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 32ULL);
x86_l_d9d:
	/* 0xd9d: jle    1108 <generic_retkprobe_event+0x1108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4360ULL;
	}
x86_l_da3:
	/* 0xda3: lea    edx,[r14-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_da7:
	/* 0xda7: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_daa:
	/* 0xdaa: jae    fb3 <generic_retkprobe_event+0xfb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4019ULL;
	}
x86_l_db0:
	/* 0xdb0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_db5:
	/* 0xdb5: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_db8:
	/* 0xdb8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dbd:
	/* 0xdbd: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_dc0:
	/* 0xdc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc2:
	/* 0xdc2: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dc7:
	/* 0xdc7: jmp    f0d <generic_retkprobe_event+0xf0d> */
	return 3853ULL;
x86_l_dcc:
	/* 0xdcc: cmp    r14d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 39ULL);
x86_l_dd0:
	/* 0xdd0: je     1615 <generic_retkprobe_event+0x1615> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5653ULL;
	}
x86_l_dd6:
	/* 0xdd6: cmp    r14d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 40ULL);
x86_l_dda:
	/* 0xdda: je     1666 <generic_retkprobe_event+0x1666> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5734ULL;
	}
x86_l_de0:
	/* 0xde0: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_de4:
	/* 0xde4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_de9:
	/* 0xde9: jne    1cbe <generic_retkprobe_event+0x1cbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7358ULL;
	}
x86_l_def:
	/* 0xdef: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_df2:
	/* 0xdf2: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_df7:
	/* 0xdf7: mov    BYTE PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_dfc:
	/* 0xdfc: mov    QWORD PTR [rdi+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_e04:
	/* 0xe04: mov    QWORD PTR [rdi+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_e0c:
	/* 0xe0c: mov    QWORD PTR [rdi+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_e14:
	/* 0xe14: mov    QWORD PTR [rdi+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_e1c:
	/* 0xe1c: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_e24:
	/* 0xe24: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_e2c:
	/* 0xe2c: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_e34:
	/* 0xe34: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_e3c:
	/* 0xe3c: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_e44:
	/* 0xe44: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_e4c:
	/* 0xe4c: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_e54:
	/* 0xe54: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_e5c:
	/* 0xe5c: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_e64:
	/* 0xe64: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e6b:
	/* 0xe6b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e70:
	/* 0xe70: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e75:
	/* 0xe75: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_e78:
	/* 0xe78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e7a:
	/* 0xe7a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e7d:
	/* 0xe7d: js     2040 <generic_retkprobe_event+0x2040> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8256ULL;
	}
	return 3715ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3715ULL: goto x86_l_e83;
	case 3720ULL: goto x86_l_e88;
	case 3725ULL: goto x86_l_e8d;
	case 3730ULL: goto x86_l_e92;
	case 3735ULL: goto x86_l_e97;
	case 3738ULL: goto x86_l_e9a;
	case 3740ULL: goto x86_l_e9c;
	case 3743ULL: goto x86_l_e9f;
	case 3749ULL: goto x86_l_ea5;
	case 3754ULL: goto x86_l_eaa;
	case 3757ULL: goto x86_l_ead;
	case 3764ULL: goto x86_l_eb4;
	case 3769ULL: goto x86_l_eb9;
	case 3776ULL: goto x86_l_ec0;
	case 3782ULL: goto x86_l_ec6;
	case 3787ULL: goto x86_l_ecb;
	case 3792ULL: goto x86_l_ed0;
	case 3795ULL: goto x86_l_ed3;
	case 3797ULL: goto x86_l_ed5;
	case 3799ULL: goto x86_l_ed7;
	case 3805ULL: goto x86_l_edd;
	case 3807ULL: goto x86_l_edf;
	case 3812ULL: goto x86_l_ee4;
	case 3816ULL: goto x86_l_ee8;
	case 3822ULL: goto x86_l_eee;
	case 3826ULL: goto x86_l_ef2;
	case 3832ULL: goto x86_l_ef8;
	case 3836ULL: goto x86_l_efc;
	case 3842ULL: goto x86_l_f02;
	case 3853ULL: goto x86_l_f0d;
	case 3858ULL: goto x86_l_f12;
	case 3863ULL: goto x86_l_f17;
	case 3868ULL: goto x86_l_f1c;
	case 3873ULL: goto x86_l_f21;
	case 3878ULL: goto x86_l_f26;
	case 3881ULL: goto x86_l_f29;
	case 3886ULL: goto x86_l_f2e;
	case 3888ULL: goto x86_l_f30;
	case 3892ULL: goto x86_l_f34;
	case 3894ULL: goto x86_l_f36;
	case 3898ULL: goto x86_l_f3a;
	case 3904ULL: goto x86_l_f40;
	case 3909ULL: goto x86_l_f45;
	case 3914ULL: goto x86_l_f4a;
	case 3917ULL: goto x86_l_f4d;
	case 3922ULL: goto x86_l_f52;
	case 3924ULL: goto x86_l_f54;
	case 3929ULL: goto x86_l_f59;
	case 3934ULL: goto x86_l_f5e;
	case 3940ULL: goto x86_l_f64;
	case 3942ULL: goto x86_l_f66;
	case 3948ULL: goto x86_l_f6c;
	case 3950ULL: goto x86_l_f6e;
	case 3955ULL: goto x86_l_f73;
	case 3960ULL: goto x86_l_f78;
	case 3965ULL: goto x86_l_f7d;
	case 3968ULL: goto x86_l_f80;
	case 3973ULL: goto x86_l_f85;
	case 3975ULL: goto x86_l_f87;
	case 3980ULL: goto x86_l_f8c;
	case 3986ULL: goto x86_l_f92;
	case 3988ULL: goto x86_l_f94;
	case 3994ULL: goto x86_l_f9a;
	case 4004ULL: goto x86_l_fa4;
	case 4014ULL: goto x86_l_fae;
	case 4019ULL: goto x86_l_fb3;
	case 4023ULL: goto x86_l_fb7;
	case 4029ULL: goto x86_l_fbd;
	case 4033ULL: goto x86_l_fc1;
	case 4039ULL: goto x86_l_fc7;
	case 4042ULL: goto x86_l_fca;
	case 4047ULL: goto x86_l_fcf;
	case 4051ULL: goto x86_l_fd3;
	case 4056ULL: goto x86_l_fd8;
	case 4061ULL: goto x86_l_fdd;
	case 4066ULL: goto x86_l_fe2;
	case 4069ULL: goto x86_l_fe5;
	case 4071ULL: goto x86_l_fe7;
	case 4076ULL: goto x86_l_fec;
	case 4079ULL: goto x86_l_fef;
	case 4085ULL: goto x86_l_ff5;
	case 4090ULL: goto x86_l_ffa;
	case 4097ULL: goto x86_l_1001;
	case 4104ULL: goto x86_l_1008;
	case 4109ULL: goto x86_l_100d;
	case 4114ULL: goto x86_l_1012;
	case 4119ULL: goto x86_l_1017;
	case 4121ULL: goto x86_l_1019;
	case 4128ULL: goto x86_l_1020;
	case 4133ULL: goto x86_l_1025;
	case 4138ULL: goto x86_l_102a;
	case 4143ULL: goto x86_l_102f;
	case 4145ULL: goto x86_l_1031;
	case 4152ULL: goto x86_l_1038;
	case 4160ULL: goto x86_l_1040;
	case 4165ULL: goto x86_l_1045;
	case 4170ULL: goto x86_l_104a;
	case 4172ULL: goto x86_l_104c;
	case 4179ULL: goto x86_l_1053;
	case 4187ULL: goto x86_l_105b;
	case 4192ULL: goto x86_l_1060;
	case 4197ULL: goto x86_l_1065;
	case 4199ULL: goto x86_l_1067;
	case 4206ULL: goto x86_l_106e;
	case 4214ULL: goto x86_l_1076;
	case 4219ULL: goto x86_l_107b;
	case 4224ULL: goto x86_l_1080;
	case 4226ULL: goto x86_l_1082;
	case 4233ULL: goto x86_l_1089;
	case 4241ULL: goto x86_l_1091;
	case 4246ULL: goto x86_l_1096;
	case 4251ULL: goto x86_l_109b;
	case 4253ULL: goto x86_l_109d;
	case 4260ULL: goto x86_l_10a4;
	case 4263ULL: goto x86_l_10a7;
	case 4270ULL: goto x86_l_10ae;
	case 4278ULL: goto x86_l_10b6;
	case 4286ULL: goto x86_l_10be;
	case 4294ULL: goto x86_l_10c6;
	case 4301ULL: goto x86_l_10cd;
	case 4304ULL: goto x86_l_10d0;
	case 4310ULL: goto x86_l_10d6;
	case 4313ULL: goto x86_l_10d9;
	case 4319ULL: goto x86_l_10df;
	case 4324ULL: goto x86_l_10e4;
	case 4329ULL: goto x86_l_10e9;
	case 4332ULL: goto x86_l_10ec;
	case 4337ULL: goto x86_l_10f1;
	case 4339ULL: goto x86_l_10f3;
	case 4344ULL: goto x86_l_10f8;
	case 4347ULL: goto x86_l_10fb;
	case 4352ULL: goto x86_l_1100;
	case 4355ULL: goto x86_l_1103;
	case 4360ULL: goto x86_l_1108;
	case 4364ULL: goto x86_l_110c;
	case 4370ULL: goto x86_l_1112;
	case 4374ULL: goto x86_l_1116;
	case 4380ULL: goto x86_l_111c;
	case 4389ULL: goto x86_l_1125;
	case 4398ULL: goto x86_l_112e;
	case 4407ULL: goto x86_l_1137;
	case 4416ULL: goto x86_l_1140;
	case 4425ULL: goto x86_l_1149;
	case 4434ULL: goto x86_l_1152;
	case 4443ULL: goto x86_l_115b;
	case 4452ULL: goto x86_l_1164;
	case 4461ULL: goto x86_l_116d;
	case 4469ULL: goto x86_l_1175;
	case 4476ULL: goto x86_l_117c;
	case 4480ULL: goto x86_l_1180;
	case 4485ULL: goto x86_l_1185;
	case 4490ULL: goto x86_l_118a;
	case 4492ULL: goto x86_l_118c;
	case 4495ULL: goto x86_l_118f;
	case 4501ULL: goto x86_l_1195;
	case 4506ULL: goto x86_l_119a;
	case 4509ULL: goto x86_l_119d;
	case 4516ULL: goto x86_l_11a4;
	case 4523ULL: goto x86_l_11ab;
	case 4528ULL: goto x86_l_11b0;
	case 4533ULL: goto x86_l_11b5;
	case 4536ULL: goto x86_l_11b8;
	case 4538ULL: goto x86_l_11ba;
	case 4541ULL: goto x86_l_11bd;
	case 4546ULL: goto x86_l_11c2;
	case 4551ULL: goto x86_l_11c7;
	case 4555ULL: goto x86_l_11cb;
	case 4561ULL: goto x86_l_11d1;
	case 4565ULL: goto x86_l_11d5;
	case 4571ULL: goto x86_l_11db;
	case 4576ULL: goto x86_l_11e0;
	case 4578ULL: goto x86_l_11e2;
	case 4581ULL: goto x86_l_11e5;
	case 4583ULL: goto x86_l_11e7;
	case 4586ULL: goto x86_l_11ea;
	case 4588ULL: goto x86_l_11ec;
	case 4593ULL: goto x86_l_11f1;
	case 4597ULL: goto x86_l_11f5;
	case 4603ULL: goto x86_l_11fb;
	case 4607ULL: goto x86_l_11ff;
	case 4613ULL: goto x86_l_1205;
	case 4622ULL: goto x86_l_120e;
	case 4625ULL: goto x86_l_1211;
	case 4632ULL: goto x86_l_1218;
	case 4639ULL: goto x86_l_121f;
	case 4644ULL: goto x86_l_1224;
	case 4649ULL: goto x86_l_1229;
	case 4654ULL: goto x86_l_122e;
	case 4656ULL: goto x86_l_1230;
	case 4661ULL: goto x86_l_1235;
	case 4666ULL: goto x86_l_123a;
	case 4669ULL: goto x86_l_123d;
	case 4674ULL: goto x86_l_1242;
	case 4676ULL: goto x86_l_1244;
	case 4681ULL: goto x86_l_1249;
	case 4688ULL: goto x86_l_1250;
	case 4693ULL: goto x86_l_1255;
	case 4698ULL: goto x86_l_125a;
	case 4701ULL: goto x86_l_125d;
	case 4703ULL: goto x86_l_125f;
	case 4708ULL: goto x86_l_1264;
	case 4715ULL: goto x86_l_126b;
	case 4722ULL: goto x86_l_1272;
	case 4727ULL: goto x86_l_1277;
	case 4732ULL: goto x86_l_127c;
	case 4734ULL: goto x86_l_127e;
	case 4739ULL: goto x86_l_1283;
	case 4746ULL: goto x86_l_128a;
	case 4753ULL: goto x86_l_1291;
	case 4758ULL: goto x86_l_1296;
	case 4763ULL: goto x86_l_129b;
	case 4766ULL: goto x86_l_129e;
	case 4768ULL: goto x86_l_12a0;
	case 4773ULL: goto x86_l_12a5;
	case 4778ULL: goto x86_l_12aa;
	case 4783ULL: goto x86_l_12af;
	case 4787ULL: goto x86_l_12b3;
	case 4792ULL: goto x86_l_12b8;
	case 4798ULL: goto x86_l_12be;
	case 4803ULL: goto x86_l_12c3;
	case 4806ULL: goto x86_l_12c6;
	case 4809ULL: goto x86_l_12c9;
	case 4812ULL: goto x86_l_12cc;
	case 4818ULL: goto x86_l_12d2;
	case 4821ULL: goto x86_l_12d5;
	case 4828ULL: goto x86_l_12dc;
	case 4830ULL: goto x86_l_12de;
	case 4835ULL: goto x86_l_12e3;
	case 4837ULL: goto x86_l_12e5;
	case 4840ULL: goto x86_l_12e8;
	case 4843ULL: goto x86_l_12eb;
	case 4849ULL: goto x86_l_12f1;
	case 4854ULL: goto x86_l_12f6;
	case 4863ULL: goto x86_l_12ff;
	case 4872ULL: goto x86_l_1308;
	case 4877ULL: goto x86_l_130d;
	case 4879ULL: goto x86_l_130f;
	case 4883ULL: goto x86_l_1313;
	case 4888ULL: goto x86_l_1318;
	case 4893ULL: goto x86_l_131d;
	case 4898ULL: goto x86_l_1322;
	case 4903ULL: goto x86_l_1327;
	case 4908ULL: goto x86_l_132c;
	case 4910ULL: goto x86_l_132e;
	case 4914ULL: goto x86_l_1332;
	case 4918ULL: goto x86_l_1336;
	case 4923ULL: goto x86_l_133b;
	case 4930ULL: goto x86_l_1342;
	case 4935ULL: goto x86_l_1347;
	case 4937ULL: goto x86_l_1349;
	case 4940ULL: goto x86_l_134c;
	case 4946ULL: goto x86_l_1352;
	case 4948ULL: goto x86_l_1354;
	case 4953ULL: goto x86_l_1359;
	case 4958ULL: goto x86_l_135e;
	case 4961ULL: goto x86_l_1361;
	case 4966ULL: goto x86_l_1366;
	case 4969ULL: goto x86_l_1369;
	case 4972ULL: goto x86_l_136c;
	case 4974ULL: goto x86_l_136e;
	case 4980ULL: goto x86_l_1374;
	case 4985ULL: goto x86_l_1379;
	case 4992ULL: goto x86_l_1380;
	case 4995ULL: goto x86_l_1383;
	case 5000ULL: goto x86_l_1388;
	case 5003ULL: goto x86_l_138b;
	case 5005ULL: goto x86_l_138d;
	case 5009ULL: goto x86_l_1391;
	case 5013ULL: goto x86_l_1395;
	case 5017ULL: goto x86_l_1399;
	case 5021ULL: goto x86_l_139d;
	case 5026ULL: goto x86_l_13a2;
	case 5031ULL: goto x86_l_13a7;
	case 5033ULL: goto x86_l_13a9;
	case 5037ULL: goto x86_l_13ad;
	case 5042ULL: goto x86_l_13b2;
	case 5048ULL: goto x86_l_13b8;
	case 5050ULL: goto x86_l_13ba;
	case 5056ULL: goto x86_l_13c0;
	case 5061ULL: goto x86_l_13c5;
	case 5064ULL: goto x86_l_13c8;
	case 5069ULL: goto x86_l_13cd;
	case 5074ULL: goto x86_l_13d2;
	case 5082ULL: goto x86_l_13da;
	case 5087ULL: goto x86_l_13df;
	case 5090ULL: goto x86_l_13e2;
	case 5092ULL: goto x86_l_13e4;
	case 5100ULL: goto x86_l_13ec;
	case 5102ULL: goto x86_l_13ee;
	case 5108ULL: goto x86_l_13f4;
	case 5111ULL: goto x86_l_13f7;
	case 5117ULL: goto x86_l_13fd;
	case 5121ULL: goto x86_l_1401;
	case 5126ULL: goto x86_l_1406;
	case 5131ULL: goto x86_l_140b;
	case 5136ULL: goto x86_l_1410;
	case 5141ULL: goto x86_l_1415;
	case 5144ULL: goto x86_l_1418;
	case 5146ULL: goto x86_l_141a;
	case 5151ULL: goto x86_l_141f;
	case 5156ULL: goto x86_l_1424;
	case 5161ULL: goto x86_l_1429;
	case 5166ULL: goto x86_l_142e;
	case 5168ULL: goto x86_l_1430;
	case 5173ULL: goto x86_l_1435;
	case 5177ULL: goto x86_l_1439;
	case 5182ULL: goto x86_l_143e;
	case 5190ULL: goto x86_l_1446;
	case 5195ULL: goto x86_l_144b;
	case 5197ULL: goto x86_l_144d;
	case 5202ULL: goto x86_l_1452;
	case 5210ULL: goto x86_l_145a;
	case 5217ULL: goto x86_l_1461;
	case 5223ULL: goto x86_l_1467;
	case 5227ULL: goto x86_l_146b;
	case 5230ULL: goto x86_l_146e;
	case 5237ULL: goto x86_l_1475;
	case 5242ULL: goto x86_l_147a;
	case 5247ULL: goto x86_l_147f;
	case 5252ULL: goto x86_l_1484;
	case 5257ULL: goto x86_l_1489;
	case 5264ULL: goto x86_l_1490;
	case 5271ULL: goto x86_l_1497;
	case 5276ULL: goto x86_l_149c;
	case 5281ULL: goto x86_l_14a1;
	case 5284ULL: goto x86_l_14a4;
	case 5286ULL: goto x86_l_14a6;
	case 5293ULL: goto x86_l_14ad;
	case 5297ULL: goto x86_l_14b1;
	case 5302ULL: goto x86_l_14b6;
	case 5307ULL: goto x86_l_14bb;
	case 5309ULL: goto x86_l_14bd;
	case 5316ULL: goto x86_l_14c4;
	case 5323ULL: goto x86_l_14cb;
	case 5328ULL: goto x86_l_14d0;
	case 5333ULL: goto x86_l_14d5;
	case 5335ULL: goto x86_l_14d7;
	case 5342ULL: goto x86_l_14de;
	case 5349ULL: goto x86_l_14e5;
	case 5354ULL: goto x86_l_14ea;
	case 5359ULL: goto x86_l_14ef;
	case 5361ULL: goto x86_l_14f1;
	case 5370ULL: goto x86_l_14fa;
	case 5377ULL: goto x86_l_1501;
	case 5382ULL: goto x86_l_1506;
	case 5387ULL: goto x86_l_150b;
	case 5392ULL: goto x86_l_1510;
	case 5394ULL: goto x86_l_1512;
	case 5401ULL: goto x86_l_1519;
	case 5406ULL: goto x86_l_151e;
	case 5414ULL: goto x86_l_1526;
	case 5419ULL: goto x86_l_152b;
	case 5421ULL: goto x86_l_152d;
	case 5430ULL: goto x86_l_1536;
	case 5435ULL: goto x86_l_153b;
	case 5440ULL: goto x86_l_1540;
	case 5448ULL: goto x86_l_1548;
	case 5453ULL: goto x86_l_154d;
	case 5456ULL: goto x86_l_1550;
	case 5458ULL: goto x86_l_1552;
	case 5466ULL: goto x86_l_155a;
	case 5469ULL: goto x86_l_155d;
	case 5472ULL: goto x86_l_1560;
	case 5478ULL: goto x86_l_1566;
	case 5481ULL: goto x86_l_1569;
	case 5487ULL: goto x86_l_156f;
	case 5492ULL: goto x86_l_1574;
	case 5497ULL: goto x86_l_1579;
	case 5505ULL: goto x86_l_1581;
	case 5510ULL: goto x86_l_1586;
	case 5512ULL: goto x86_l_1588;
	case 5520ULL: goto x86_l_1590;
	case 5525ULL: goto x86_l_1595;
	case 5532ULL: goto x86_l_159c;
	case 5541ULL: goto x86_l_15a5;
	case 5548ULL: goto x86_l_15ac;
	case 5553ULL: goto x86_l_15b1;
	case 5558ULL: goto x86_l_15b6;
	case 5565ULL: goto x86_l_15bd;
	case 5573ULL: goto x86_l_15c5;
	case 5581ULL: goto x86_l_15cd;
	case 5589ULL: goto x86_l_15d5;
	case 5594ULL: goto x86_l_15da;
	case 5599ULL: goto x86_l_15df;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e83:
	/* 0xe83: lea    r13,[r12+0x2] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_e88:
	/* 0xe88: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e8d:
	/* 0xe8d: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e92:
	/* 0xe92: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_e97:
	/* 0xe97: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_e9a:
	/* 0xe9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e9c:
	/* 0xe9c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e9f:
	/* 0xe9f: js     2040 <generic_retkprobe_event+0x2040> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8256ULL;
	}
x86_l_ea5:
	/* 0xea5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eaa:
	/* 0xeaa: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_ead:
	/* 0xead: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_eb4:
	/* 0xeb4: cmp    BYTE PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_eb9:
	/* 0xeb9: sete   BYTE PTR [rax+0x9e] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RAX, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 158ULL);
x86_l_ec0:
	/* 0xec0: je     2019 <generic_retkprobe_event+0x2019> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8217ULL;
	}
x86_l_ec6:
	/* 0xec6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_ecb:
	/* 0xecb: mov    esi,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 108ULL);
x86_l_ed0:
	/* 0xed0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_ed3:
	/* 0xed3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed5:
	/* 0xed5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ed7:
	/* 0xed7: js     2040 <generic_retkprobe_event+0x2040> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8256ULL;
	}
x86_l_edd:
	/* 0xedd: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_edf:
	/* 0xedf: jmp    2035 <generic_retkprobe_event+0x2035> */
	return 8245ULL;
x86_l_ee4:
	/* 0xee4: cmp    r14d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 7ULL);
x86_l_ee8:
	/* 0xee8: jg     11c7 <generic_retkprobe_event+0x11c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_11c7;
	}
x86_l_eee:
	/* 0xeee: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_ef2:
	/* 0xef2: je     17c7 <generic_retkprobe_event+0x17c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6087ULL;
	}
x86_l_ef8:
	/* 0xef8: cmp    r14d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 3ULL);
x86_l_efc:
	/* 0xefc: jne    1cb9 <generic_retkprobe_event+0x1cb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7353ULL;
	}
x86_l_f02:
	/* 0xf02: mov    QWORD PTR [rax+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_f0d:
	/* 0xf0d: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_f12:
	/* 0xf12: jmp    1cb9 <generic_retkprobe_event+0x1cb9> */
	return 7353ULL;
x86_l_f17:
	/* 0xf17: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_f1c:
	/* 0xf1c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f21:
	/* 0xf21: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f26:
	/* 0xf26: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_f29:
	/* 0xf29: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f2e:
	/* 0xf2e: jmp    f85 <generic_retkprobe_event+0xf85> */
	goto x86_l_f85;
x86_l_f30:
	/* 0xf30: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_f34:
	/* 0xf34: je     f6e <generic_retkprobe_event+0xf6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f6e;
	}
x86_l_f36:
	/* 0xf36: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_f3a:
	/* 0xf3a: jne    1cbe <generic_retkprobe_event+0x1cbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7358ULL;
	}
x86_l_f40:
	/* 0xf40: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f45:
	/* 0xf45: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f4a:
	/* 0xf4a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_f4d:
	/* 0xf4d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f52:
	/* 0xf52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f54:
	/* 0xf54: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f59:
	/* 0xf59: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_f5e:
	/* 0xf5e: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_f64:
	/* 0xf64: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_f66:
	/* 0xf66: jns    1ccc <generic_retkprobe_event+0x1ccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 7372ULL;
	}
x86_l_f6c:
	/* 0xf6c: jmp    f9a <generic_retkprobe_event+0xf9a> */
	goto x86_l_f9a;
x86_l_f6e:
	/* 0xf6e: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_f73:
	/* 0xf73: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f78:
	/* 0xf78: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f7d:
	/* 0xf7d: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_f80:
	/* 0xf80: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f85:
	/* 0xf85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f87:
	/* 0xf87: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f8c:
	/* 0xf8c: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_f92:
	/* 0xf92: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_f94:
	/* 0xf94: jns    1ccc <generic_retkprobe_event+0x1ccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 7372ULL;
	}
x86_l_f9a:
	/* 0xf9a: mov    DWORD PTR [rcx+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104045582745599ULL);
x86_l_fa4:
	/* 0xfa4: mov    DWORD PTR [rcx+0x98],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 657129996287ULL);
x86_l_fae:
	/* 0xfae: jmp    1cd9 <generic_retkprobe_event+0x1cd9> */
	return 7385ULL;
x86_l_fb3:
	/* 0xfb3: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_fb7:
	/* 0xfb7: je     1ba8 <generic_retkprobe_event+0x1ba8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7080ULL;
	}
x86_l_fbd:
	/* 0xfbd: cmp    r14d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 41ULL);
x86_l_fc1:
	/* 0xfc1: jne    1cb9 <generic_retkprobe_event+0x1cb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7353ULL;
	}
x86_l_fc7:
	/* 0xfc7: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_fca:
	/* 0xfca: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fcf:
	/* 0xfcf: add    r13,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_fd3:
	/* 0xfd3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fd8:
	/* 0xfd8: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fdd:
	/* 0xfdd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fe2:
	/* 0xfe2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_fe5:
	/* 0xfe5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe7:
	/* 0xfe7: mov    r12,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fec:
	/* 0xfec: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_fef:
	/* 0xfef: je     20bf <generic_retkprobe_event+0x20bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8383ULL;
	}
x86_l_ff5:
	/* 0xff5: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ffa:
	/* 0xffa: mov    QWORD PTR [rbp+0xc4],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1001:
	/* 0x1001: lea    rdi,[rbp+0xc2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_1008:
	/* 0x1008: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_100d:
	/* 0x100d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1012:
	/* 0x1012: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1017:
	/* 0x1017: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1019:
	/* 0x1019: lea    rdi,[rbp+0xd6] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_1020:
	/* 0x1020: lea    rdx,[r12+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1025:
	/* 0x1025: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_102a:
	/* 0x102a: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_102f:
	/* 0x102f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1031:
	/* 0x1031: lea    rdi,[rbp+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_1038:
	/* 0x1038: lea    rdx,[r12+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_1040:
	/* 0x1040: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1045:
	/* 0x1045: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_104a:
	/* 0x104a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_104c:
	/* 0x104c: lea    rdi,[rbp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1053:
	/* 0x1053: lea    rdx,[r12+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_105b:
	/* 0x105b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1060:
	/* 0x1060: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1065:
	/* 0x1065: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1067:
	/* 0x1067: lea    rdi,[rbp+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_106e:
	/* 0x106e: lea    rdx,[r12+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_1076:
	/* 0x1076: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_107b:
	/* 0x107b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1080:
	/* 0x1080: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1082:
	/* 0x1082: lea    rdi,[rbp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1089:
	/* 0x1089: lea    rdx,[r12+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1091:
	/* 0x1091: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1096:
	/* 0x1096: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_109b:
	/* 0x109b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_109d:
	/* 0x109d: lea    r13,[rbp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_10a4:
	/* 0x10a4: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_10a7:
	/* 0x10a7: mov    QWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10ae:
	/* 0x10ae: mov    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_10b6:
	/* 0x10b6: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_10be:
	/* 0x10be: mov    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_10c6:
	/* 0x10c6: movzx  eax,WORD PTR [rbp+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_10cd:
	/* 0x10cd: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_10d0:
	/* 0x10d0: je     204a <generic_retkprobe_event+0x204a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8266ULL;
	}
x86_l_10d6:
	/* 0x10d6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10d9:
	/* 0x10d9: jne    2072 <generic_retkprobe_event+0x2072> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8306ULL;
	}
x86_l_10df:
	/* 0x10df: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10e4:
	/* 0x10e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10e9:
	/* 0x10e9: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_10ec:
	/* 0x10ec: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10f1:
	/* 0x10f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10f3:
	/* 0x10f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10f8:
	/* 0x10f8: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_10fb:
	/* 0x10fb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1100:
	/* 0x1100: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1103:
	/* 0x1103: jmp    2070 <generic_retkprobe_event+0x2070> */
	return 8304ULL;
x86_l_1108:
	/* 0x1108: cmp    r14d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 26ULL);
x86_l_110c:
	/* 0x110c: je     1c39 <generic_retkprobe_event+0x1c39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7225ULL;
	}
x86_l_1112:
	/* 0x1112: cmp    r14d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 27ULL);
x86_l_1116:
	/* 0x1116: jne    1cb9 <generic_retkprobe_event+0x1cb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7353ULL;
	}
x86_l_111c:
	/* 0x111c: mov    QWORD PTR [r12+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1125:
	/* 0x1125: mov    QWORD PTR [r12+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_112e:
	/* 0x112e: mov    QWORD PTR [r12+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1137:
	/* 0x1137: mov    QWORD PTR [r12+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1140:
	/* 0x1140: mov    QWORD PTR [r12+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1149:
	/* 0x1149: mov    QWORD PTR [r12+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1152:
	/* 0x1152: mov    QWORD PTR [r12+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_115b:
	/* 0x115b: mov    QWORD PTR [r12+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1164:
	/* 0x1164: mov    QWORD PTR [r12+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_116d:
	/* 0x116d: mov    QWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1175:
	/* 0x1175: lea    rdi,[rcx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_117c:
	/* 0x117c: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1180:
	/* 0x1180: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1185:
	/* 0x1185: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_118a:
	/* 0x118a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_118c:
	/* 0x118c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_118f:
	/* 0x118f: js     1cb2 <generic_retkprobe_event+0x1cb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7346ULL;
	}
x86_l_1195:
	/* 0x1195: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_119a:
	/* 0x119a: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_119d:
	/* 0x119d: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_11a4:
	/* 0x11a4: add    r13,0x348 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 840ULL);
x86_l_11ab:
	/* 0x11ab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11b0:
	/* 0x11b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11b5:
	/* 0x11b5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_11b8:
	/* 0x11b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ba:
	/* 0x11ba: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_11bd:
	/* 0x11bd: mov    ebp,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 80ULL);
x86_l_11c2:
	/* 0x11c2: jmp    1cb9 <generic_retkprobe_event+0x1cb9> */
	return 7353ULL;
x86_l_11c7:
	/* 0x11c7: cmp    r14d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 8ULL);
x86_l_11cb:
	/* 0x11cb: je     1860 <generic_retkprobe_event+0x1860> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6240ULL;
	}
x86_l_11d1:
	/* 0x11d1: cmp    r14d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 18ULL);
x86_l_11d5:
	/* 0x11d5: jne    1cb9 <generic_retkprobe_event+0x1cb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7353ULL;
	}
x86_l_11db:
	/* 0x11db: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11e0:
	/* 0x11e0: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11e2:
	/* 0x11e2: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_11e5:
	/* 0x11e5: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11e7:
	/* 0x11e7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_11ea:
	/* 0x11ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ec:
	/* 0x11ec: jmp    1cb4 <generic_retkprobe_event+0x1cb4> */
	return 7348ULL;
x86_l_11f1:
	/* 0x11f1: cmp    r14d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 19ULL);
x86_l_11f5:
	/* 0x11f5: je     1b58 <generic_retkprobe_event+0x1b58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7000ULL;
	}
x86_l_11fb:
	/* 0x11fb: cmp    r14d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 20ULL);
x86_l_11ff:
	/* 0x11ff: jne    1cb9 <generic_retkprobe_event+0x1cb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7353ULL;
	}
x86_l_1205:
	/* 0x1205: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_120e:
	/* 0x120e: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_1211:
	/* 0x1211: lea    r12,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1218:
	/* 0x1218: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_121f:
	/* 0x121f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1224:
	/* 0x1224: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1229:
	/* 0x1229: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_122e:
	/* 0x122e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1230:
	/* 0x1230: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1235:
	/* 0x1235: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_123a:
	/* 0x123a: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_123d:
	/* 0x123d: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_1242:
	/* 0x1242: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1244:
	/* 0x1244: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1249:
	/* 0x1249: lea    rdi,[rax+0x12c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 300ULL);
x86_l_1250:
	/* 0x1250: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1255:
	/* 0x1255: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_125a:
	/* 0x125a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_125d:
	/* 0x125d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_125f:
	/* 0x125f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1264:
	/* 0x1264: lea    rdi,[rax+0x11c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 284ULL);
x86_l_126b:
	/* 0x126b: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1272:
	/* 0x1272: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1277:
	/* 0x1277: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_127c:
	/* 0x127c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_127e:
	/* 0x127e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1283:
	/* 0x1283: add    rdi,0x124 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 292ULL);
x86_l_128a:
	/* 0x128a: add    r13,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_1291:
	/* 0x1291: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1296:
	/* 0x1296: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_129b:
	/* 0x129b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_129e:
	/* 0x129e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a0:
	/* 0x12a0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12a5:
	/* 0x12a5: mov    ebp,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 152ULL);
x86_l_12aa:
	/* 0x12aa: jmp    1cb9 <generic_retkprobe_event+0x1cb9> */
	return 7353ULL;
x86_l_12af:
	/* 0x12af: cmp    r14d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 38ULL);
x86_l_12b3:
	/* 0x12b3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12b8:
	/* 0x12b8: jne    1cbe <generic_retkprobe_event+0x1cbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7358ULL;
	}
x86_l_12be:
	/* 0x12be: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12c3:
	/* 0x12c3: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_12c6:
	/* 0x12c6: add    rdx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_12c9:
	/* 0x12c9: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_12cc:
	/* 0x12cc: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12d2:
	/* 0x12d2: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_12d5:
	/* 0x12d5: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_12dc:
	/* 0x12dc: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_12de:
	/* 0x12de: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_12e3:
	/* 0x12e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12e5:
	/* 0x12e5: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_12e8:
	/* 0x12e8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12eb:
	/* 0x12eb: jns    1643 <generic_retkprobe_event+0x1643> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 5699ULL;
	}
x86_l_12f1:
	/* 0x12f1: jmp    1cfe <generic_retkprobe_event+0x1cfe> */
	return 7422ULL;
x86_l_12f6:
	/* 0x12f6: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_12ff:
	/* 0x12ff: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1308:
	/* 0x1308: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_130d:
	/* 0x130d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_130f:
	/* 0x130f: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1313:
	/* 0x1313: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1318:
	/* 0x1318: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_131d:
	/* 0x131d: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1322:
	/* 0x1322: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1327:
	/* 0x1327: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_132c:
	/* 0x132c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_132e:
	/* 0x132e: mov    eax,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1332:
	/* 0x1332: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1336:
	/* 0x1336: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_133b:
	/* 0x133b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1342:
	/* 0x1342: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1347:
	/* 0x1347: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1349:
	/* 0x1349: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_134c:
	/* 0x134c: je     1cf7 <generic_retkprobe_event+0x1cf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7415ULL;
	}
x86_l_1352:
	/* 0x1352: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1354:
	/* 0x1354: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1359:
	/* 0x1359: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_135e:
	/* 0x135e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1361:
	/* 0x1361: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1366:
	/* 0x1366: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_1369:
	/* 0x1369: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_136c:
	/* 0x136c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_136e:
	/* 0x136e: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1374:
	/* 0x1374: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1379:
	/* 0x1379: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_1380:
	/* 0x1380: lea    esi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1383:
	/* 0x1383: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1388:
	/* 0x1388: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_138b:
	/* 0x138b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_138d:
	/* 0x138d: lea    rdi,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1391:
	/* 0x1391: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1395:
	/* 0x1395: lea    rdx,[r12+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1399:
	/* 0x1399: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_139d:
	/* 0x139d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13a2:
	/* 0x13a2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13a7:
	/* 0x13a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a9:
	/* 0x13a9: add    rbp,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_13ad:
	/* 0x13ad: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13b2:
	/* 0x13b2: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_13b8:
	/* 0x13b8: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_13ba:
	/* 0x13ba: jns    1ccc <generic_retkprobe_event+0x1ccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 7372ULL;
	}
x86_l_13c0:
	/* 0x13c0: jmp    f9a <generic_retkprobe_event+0xf9a> */
	goto x86_l_f9a;
x86_l_13c5:
	/* 0x13c5: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_13c8:
	/* 0x13c8: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13cd:
	/* 0x13cd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13d2:
	/* 0x13d2: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_13da:
	/* 0x13da: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_13df:
	/* 0x13df: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_13e2:
	/* 0x13e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e4:
	/* 0x13e4: movzx  eax,BYTE PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 176ULL);
x86_l_13ec:
	/* 0x13ec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13ee:
	/* 0x13ee: je     1d12 <generic_retkprobe_event+0x1d12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7442ULL;
	}
x86_l_13f4:
	/* 0x13f4: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13f7:
	/* 0x13f7: jne    1f05 <generic_retkprobe_event+0x1f05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7941ULL;
	}
x86_l_13fd:
	/* 0x13fd: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1401:
	/* 0x1401: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1406:
	/* 0x1406: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_140b:
	/* 0x140b: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1410:
	/* 0x1410: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1415:
	/* 0x1415: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1418:
	/* 0x1418: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_141a:
	/* 0x141a: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_141f:
	/* 0x141f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1424:
	/* 0x1424: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1429:
	/* 0x1429: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_142e:
	/* 0x142e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1430:
	/* 0x1430: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1435:
	/* 0x1435: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1439:
	/* 0x1439: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_143e:
	/* 0x143e: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1446:
	/* 0x1446: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_144b:
	/* 0x144b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_144d:
	/* 0x144d: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1452:
	/* 0x1452: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_145a:
	/* 0x145a: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_1461:
	/* 0x1461: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_1467:
	/* 0x1467: cmovb  r12,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_146b:
	/* 0x146b: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_146e:
	/* 0x146e: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1475:
	/* 0x1475: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_147a:
	/* 0x147a: jmp    1d75 <generic_retkprobe_event+0x1d75> */
	return 7541ULL;
x86_l_147f:
	/* 0x147f: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1484:
	/* 0x1484: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1489:
	/* 0x1489: lea    rdi,[rcx+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1490:
	/* 0x1490: lea    rdx,[rbp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1497:
	/* 0x1497: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_149c:
	/* 0x149c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14a1:
	/* 0x14a1: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_14a4:
	/* 0x14a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a6:
	/* 0x14a6: lea    rdi,[r14+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_14ad:
	/* 0x14ad: lea    rdx,[rbp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_14b1:
	/* 0x14b1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14b6:
	/* 0x14b6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14bb:
	/* 0x14bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14bd:
	/* 0x14bd: lea    rdi,[r14+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_14c4:
	/* 0x14c4: lea    rdx,[rbp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_14cb:
	/* 0x14cb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14d0:
	/* 0x14d0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14d5:
	/* 0x14d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d7:
	/* 0x14d7: lea    rdi,[r14+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_14de:
	/* 0x14de: lea    rdx,[rbp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_14e5:
	/* 0x14e5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14ea:
	/* 0x14ea: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14ef:
	/* 0x14ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14f1:
	/* 0x14f1: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_14fa:
	/* 0x14fa: lea    rdx,[rbp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1501:
	/* 0x1501: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1506:
	/* 0x1506: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_150b:
	/* 0x150b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1510:
	/* 0x1510: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1512:
	/* 0x1512: lea    rdx,[rbp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1519:
	/* 0x1519: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_151e:
	/* 0x151e: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1526:
	/* 0x1526: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_152b:
	/* 0x152b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_152d:
	/* 0x152d: movzx  r12d,WORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 176ULL);
x86_l_1536:
	/* 0x1536: add    r12,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_153b:
	/* 0x153b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1540:
	/* 0x1540: lea    rdi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1548:
	/* 0x1548: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_154d:
	/* 0x154d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1550:
	/* 0x1550: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1552:
	/* 0x1552: movzx  eax,BYTE PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 172ULL);
x86_l_155a:
	/* 0x155a: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_155d:
	/* 0x155d: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1560:
	/* 0x1560: je     1da8 <generic_retkprobe_event+0x1da8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7592ULL;
	}
x86_l_1566:
	/* 0x1566: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1569:
	/* 0x1569: jne    299b <generic_retkprobe_event+0x299b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10651ULL;
	}
x86_l_156f:
	/* 0x156f: lea    rdx,[r12+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_1574:
	/* 0x1574: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1579:
	/* 0x1579: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1581:
	/* 0x1581: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1586:
	/* 0x1586: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1588:
	/* 0x1588: movzx  eax,BYTE PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 192ULL);
x86_l_1590:
	/* 0x1590: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1595:
	/* 0x1595: mov    WORD PTR [rcx+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_159c:
	/* 0x159c: mov    WORD PTR [rcx+0xc2],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655426ULL);
x86_l_15a5:
	/* 0x15a5: lea    r13,[rcx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_15ac:
	/* 0x15ac: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_15b1:
	/* 0x15b1: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15b6:
	/* 0x15b6: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15bd:
	/* 0x15bd: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_15c5:
	/* 0x15c5: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_15cd:
	/* 0x15cd: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_15d5:
	/* 0x15d5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15da:
	/* 0x15da: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15df:
	/* 0x15df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 5601ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5601ULL: goto x86_l_15e1;
	case 5605ULL: goto x86_l_15e5;
	case 5610ULL: goto x86_l_15ea;
	case 5613ULL: goto x86_l_15ed;
	case 5618ULL: goto x86_l_15f2;
	case 5621ULL: goto x86_l_15f5;
	case 5623ULL: goto x86_l_15f7;
	case 5630ULL: goto x86_l_15fe;
	case 5635ULL: goto x86_l_1603;
	case 5643ULL: goto x86_l_160b;
	case 5648ULL: goto x86_l_1610;
	case 5653ULL: goto x86_l_1615;
	case 5658ULL: goto x86_l_161a;
	case 5663ULL: goto x86_l_161f;
	case 5668ULL: goto x86_l_1624;
	case 5675ULL: goto x86_l_162b;
	case 5680ULL: goto x86_l_1630;
	case 5685ULL: goto x86_l_1635;
	case 5687ULL: goto x86_l_1637;
	case 5690ULL: goto x86_l_163a;
	case 5693ULL: goto x86_l_163d;
	case 5699ULL: goto x86_l_1643;
	case 5702ULL: goto x86_l_1646;
	case 5706ULL: goto x86_l_164a;
	case 5710ULL: goto x86_l_164e;
	case 5715ULL: goto x86_l_1653;
	case 5721ULL: goto x86_l_1659;
	case 5723ULL: goto x86_l_165b;
	case 5729ULL: goto x86_l_1661;
	case 5734ULL: goto x86_l_1666;
	case 5737ULL: goto x86_l_1669;
	case 5742ULL: goto x86_l_166e;
	case 5750ULL: goto x86_l_1676;
	case 5758ULL: goto x86_l_167e;
	case 5765ULL: goto x86_l_1685;
	case 5770ULL: goto x86_l_168a;
	case 5773ULL: goto x86_l_168d;
	case 5778ULL: goto x86_l_1692;
	case 5781ULL: goto x86_l_1695;
	case 5783ULL: goto x86_l_1697;
	case 5786ULL: goto x86_l_169a;
	case 5791ULL: goto x86_l_169f;
	case 5797ULL: goto x86_l_16a5;
	case 5801ULL: goto x86_l_16a9;
	case 5804ULL: goto x86_l_16ac;
	case 5810ULL: goto x86_l_16b2;
	case 5813ULL: goto x86_l_16b5;
	case 5819ULL: goto x86_l_16bb;
	case 5824ULL: goto x86_l_16c0;
	case 5829ULL: goto x86_l_16c5;
	case 5834ULL: goto x86_l_16ca;
	case 5839ULL: goto x86_l_16cf;
	case 5841ULL: goto x86_l_16d1;
	case 5845ULL: goto x86_l_16d5;
	case 5850ULL: goto x86_l_16da;
	case 5857ULL: goto x86_l_16e1;
	case 5864ULL: goto x86_l_16e8;
	case 5868ULL: goto x86_l_16ec;
	case 5873ULL: goto x86_l_16f1;
	case 5878ULL: goto x86_l_16f6;
	case 5881ULL: goto x86_l_16f9;
	case 5890ULL: goto x86_l_1702;
	case 5896ULL: goto x86_l_1708;
	case 5904ULL: goto x86_l_1710;
	case 5908ULL: goto x86_l_1714;
	case 5914ULL: goto x86_l_171a;
	case 5919ULL: goto x86_l_171f;
	case 5924ULL: goto x86_l_1724;
	case 5929ULL: goto x86_l_1729;
	case 5931ULL: goto x86_l_172b;
	case 5936ULL: goto x86_l_1730;
	case 5938ULL: goto x86_l_1732;
	case 5944ULL: goto x86_l_1738;
	case 5949ULL: goto x86_l_173d;
	case 5952ULL: goto x86_l_1740;
	case 5955ULL: goto x86_l_1743;
	case 5959ULL: goto x86_l_1747;
	case 5964ULL: goto x86_l_174c;
	case 5967ULL: goto x86_l_174f;
	case 5971ULL: goto x86_l_1753;
	case 5976ULL: goto x86_l_1758;
	case 5983ULL: goto x86_l_175f;
	case 5989ULL: goto x86_l_1765;
	case 5992ULL: goto x86_l_1768;
	case 5997ULL: goto x86_l_176d;
	case 6002ULL: goto x86_l_1772;
	case 6007ULL: goto x86_l_1777;
	case 6013ULL: goto x86_l_177d;
	case 6016ULL: goto x86_l_1780;
	case 6021ULL: goto x86_l_1785;
	case 6026ULL: goto x86_l_178a;
	case 6028ULL: goto x86_l_178c;
	case 6030ULL: goto x86_l_178e;
	case 6035ULL: goto x86_l_1793;
	case 6037ULL: goto x86_l_1795;
	case 6043ULL: goto x86_l_179b;
	case 6048ULL: goto x86_l_17a0;
	case 6051ULL: goto x86_l_17a3;
	case 6057ULL: goto x86_l_17a9;
	case 6063ULL: goto x86_l_17af;
	case 6068ULL: goto x86_l_17b4;
	case 6074ULL: goto x86_l_17ba;
	case 6079ULL: goto x86_l_17bf;
	case 6082ULL: goto x86_l_17c2;
	case 6087ULL: goto x86_l_17c7;
	case 6096ULL: goto x86_l_17d0;
	case 6105ULL: goto x86_l_17d9;
	case 6110ULL: goto x86_l_17de;
	case 6115ULL: goto x86_l_17e3;
	case 6120ULL: goto x86_l_17e8;
	case 6125ULL: goto x86_l_17ed;
	case 6130ULL: goto x86_l_17f2;
	case 6133ULL: goto x86_l_17f5;
	case 6135ULL: goto x86_l_17f7;
	case 6140ULL: goto x86_l_17fc;
	case 6146ULL: goto x86_l_1802;
	case 6152ULL: goto x86_l_1808;
	case 6157ULL: goto x86_l_180d;
	case 6161ULL: goto x86_l_1811;
	case 6166ULL: goto x86_l_1816;
	case 6173ULL: goto x86_l_181d;
	case 6178ULL: goto x86_l_1822;
	case 6181ULL: goto x86_l_1825;
	case 6184ULL: goto x86_l_1828;
	case 6187ULL: goto x86_l_182b;
	case 6189ULL: goto x86_l_182d;
	case 6194ULL: goto x86_l_1832;
	case 6196ULL: goto x86_l_1834;
	case 6198ULL: goto x86_l_1836;
	case 6203ULL: goto x86_l_183b;
	case 6210ULL: goto x86_l_1842;
	case 6214ULL: goto x86_l_1846;
	case 6219ULL: goto x86_l_184b;
	case 6221ULL: goto x86_l_184d;
	case 6224ULL: goto x86_l_1850;
	case 6229ULL: goto x86_l_1855;
	case 6235ULL: goto x86_l_185b;
	case 6240ULL: goto x86_l_1860;
	case 6243ULL: goto x86_l_1863;
	case 6250ULL: goto x86_l_186a;
	case 6254ULL: goto x86_l_186e;
	case 6259ULL: goto x86_l_1873;
	case 6264ULL: goto x86_l_1878;
	case 6266ULL: goto x86_l_187a;
	case 6271ULL: goto x86_l_187f;
	case 6278ULL: goto x86_l_1886;
	case 6282ULL: goto x86_l_188a;
	case 6287ULL: goto x86_l_188f;
	case 6292ULL: goto x86_l_1894;
	case 6294ULL: goto x86_l_1896;
	case 6299ULL: goto x86_l_189b;
	case 6306ULL: goto x86_l_18a2;
	case 6310ULL: goto x86_l_18a6;
	case 6315ULL: goto x86_l_18ab;
	case 6320ULL: goto x86_l_18b0;
	case 6322ULL: goto x86_l_18b2;
	case 6327ULL: goto x86_l_18b7;
	case 6334ULL: goto x86_l_18be;
	case 6338ULL: goto x86_l_18c2;
	case 6343ULL: goto x86_l_18c7;
	case 6348ULL: goto x86_l_18cc;
	case 6350ULL: goto x86_l_18ce;
	case 6355ULL: goto x86_l_18d3;
	case 6362ULL: goto x86_l_18da;
	case 6366ULL: goto x86_l_18de;
	case 6371ULL: goto x86_l_18e3;
	case 6376ULL: goto x86_l_18e8;
	case 6378ULL: goto x86_l_18ea;
	case 6383ULL: goto x86_l_18ef;
	case 6390ULL: goto x86_l_18f6;
	case 6394ULL: goto x86_l_18fa;
	case 6399ULL: goto x86_l_18ff;
	case 6404ULL: goto x86_l_1904;
	case 6406ULL: goto x86_l_1906;
	case 6411ULL: goto x86_l_190b;
	case 6418ULL: goto x86_l_1912;
	case 6422ULL: goto x86_l_1916;
	case 6427ULL: goto x86_l_191b;
	case 6432ULL: goto x86_l_1920;
	case 6434ULL: goto x86_l_1922;
	case 6439ULL: goto x86_l_1927;
	case 6446ULL: goto x86_l_192e;
	case 6450ULL: goto x86_l_1932;
	case 6455ULL: goto x86_l_1937;
	case 6460ULL: goto x86_l_193c;
	case 6462ULL: goto x86_l_193e;
	case 6467ULL: goto x86_l_1943;
	case 6477ULL: goto x86_l_194d;
	case 6482ULL: goto x86_l_1952;
	case 6489ULL: goto x86_l_1959;
	case 6493ULL: goto x86_l_195d;
	case 6498ULL: goto x86_l_1962;
	case 6503ULL: goto x86_l_1967;
	case 6505ULL: goto x86_l_1969;
	case 6509ULL: goto x86_l_196d;
	case 6514ULL: goto x86_l_1972;
	case 6521ULL: goto x86_l_1979;
	case 6525ULL: goto x86_l_197d;
	case 6530ULL: goto x86_l_1982;
	case 6537ULL: goto x86_l_1989;
	case 6541ULL: goto x86_l_198d;
	case 6546ULL: goto x86_l_1992;
	case 6553ULL: goto x86_l_1999;
	case 6560ULL: goto x86_l_19a0;
	case 6565ULL: goto x86_l_19a5;
	case 6570ULL: goto x86_l_19aa;
	case 6575ULL: goto x86_l_19af;
	case 6578ULL: goto x86_l_19b2;
	case 6580ULL: goto x86_l_19b4;
	case 6585ULL: goto x86_l_19b9;
	case 6592ULL: goto x86_l_19c0;
	case 6597ULL: goto x86_l_19c5;
	case 6600ULL: goto x86_l_19c8;
	case 6605ULL: goto x86_l_19cd;
	case 6607ULL: goto x86_l_19cf;
	case 6612ULL: goto x86_l_19d4;
	case 6619ULL: goto x86_l_19db;
	case 6626ULL: goto x86_l_19e2;
	case 6631ULL: goto x86_l_19e7;
	case 6636ULL: goto x86_l_19ec;
	case 6638ULL: goto x86_l_19ee;
	case 6643ULL: goto x86_l_19f3;
	case 6650ULL: goto x86_l_19fa;
	case 6657ULL: goto x86_l_1a01;
	case 6662ULL: goto x86_l_1a06;
	case 6667ULL: goto x86_l_1a0b;
	case 6669ULL: goto x86_l_1a0d;
	case 6674ULL: goto x86_l_1a12;
	case 6681ULL: goto x86_l_1a19;
	case 6688ULL: goto x86_l_1a20;
	case 6693ULL: goto x86_l_1a25;
	case 6698ULL: goto x86_l_1a2a;
	case 6701ULL: goto x86_l_1a2d;
	case 6703ULL: goto x86_l_1a2f;
	case 6708ULL: goto x86_l_1a34;
	case 6713ULL: goto x86_l_1a39;
	case 6718ULL: goto x86_l_1a3e;
	case 6725ULL: goto x86_l_1a45;
	case 6730ULL: goto x86_l_1a4a;
	case 6733ULL: goto x86_l_1a4d;
	case 6738ULL: goto x86_l_1a52;
	case 6740ULL: goto x86_l_1a54;
	case 6745ULL: goto x86_l_1a59;
	case 6752ULL: goto x86_l_1a60;
	case 6759ULL: goto x86_l_1a67;
	case 6764ULL: goto x86_l_1a6c;
	case 6769ULL: goto x86_l_1a71;
	case 6771ULL: goto x86_l_1a73;
	case 6776ULL: goto x86_l_1a78;
	case 6783ULL: goto x86_l_1a7f;
	case 6790ULL: goto x86_l_1a86;
	case 6795ULL: goto x86_l_1a8b;
	case 6800ULL: goto x86_l_1a90;
	case 6802ULL: goto x86_l_1a92;
	case 6807ULL: goto x86_l_1a97;
	case 6814ULL: goto x86_l_1a9e;
	case 6821ULL: goto x86_l_1aa5;
	case 6826ULL: goto x86_l_1aaa;
	case 6831ULL: goto x86_l_1aaf;
	case 6834ULL: goto x86_l_1ab2;
	case 6836ULL: goto x86_l_1ab4;
	case 6841ULL: goto x86_l_1ab9;
	case 6846ULL: goto x86_l_1abe;
	case 6851ULL: goto x86_l_1ac3;
	case 6855ULL: goto x86_l_1ac7;
	case 6860ULL: goto x86_l_1acc;
	case 6863ULL: goto x86_l_1acf;
	case 6868ULL: goto x86_l_1ad4;
	case 6870ULL: goto x86_l_1ad6;
	case 6875ULL: goto x86_l_1adb;
	case 6882ULL: goto x86_l_1ae2;
	case 6886ULL: goto x86_l_1ae6;
	case 6891ULL: goto x86_l_1aeb;
	case 6896ULL: goto x86_l_1af0;
	case 6898ULL: goto x86_l_1af2;
	case 6903ULL: goto x86_l_1af7;
	case 6910ULL: goto x86_l_1afe;
	case 6914ULL: goto x86_l_1b02;
	case 6919ULL: goto x86_l_1b07;
	case 6924ULL: goto x86_l_1b0c;
	case 6926ULL: goto x86_l_1b0e;
	case 6931ULL: goto x86_l_1b13;
	case 6938ULL: goto x86_l_1b1a;
	case 6942ULL: goto x86_l_1b1e;
	case 6947ULL: goto x86_l_1b23;
	case 6952ULL: goto x86_l_1b28;
	case 6954ULL: goto x86_l_1b2a;
	case 6959ULL: goto x86_l_1b2f;
	case 6966ULL: goto x86_l_1b36;
	case 6970ULL: goto x86_l_1b3a;
	case 6975ULL: goto x86_l_1b3f;
	case 6980ULL: goto x86_l_1b44;
	case 6983ULL: goto x86_l_1b47;
	case 6985ULL: goto x86_l_1b49;
	case 6990ULL: goto x86_l_1b4e;
	case 6995ULL: goto x86_l_1b53;
	case 7000ULL: goto x86_l_1b58;
	case 7005ULL: goto x86_l_1b5d;
	case 7008ULL: goto x86_l_1b60;
	case 7013ULL: goto x86_l_1b65;
	case 7016ULL: goto x86_l_1b68;
	case 7018ULL: goto x86_l_1b6a;
	case 7023ULL: goto x86_l_1b6f;
	case 7030ULL: goto x86_l_1b76;
	case 7034ULL: goto x86_l_1b7a;
	case 7039ULL: goto x86_l_1b7f;
	case 7044ULL: goto x86_l_1b84;
	case 7046ULL: goto x86_l_1b86;
	case 7051ULL: goto x86_l_1b8b;
	case 7058ULL: goto x86_l_1b92;
	case 7062ULL: goto x86_l_1b96;
	case 7067ULL: goto x86_l_1b9b;
	case 7072ULL: goto x86_l_1ba0;
	case 7075ULL: goto x86_l_1ba3;
	case 7080ULL: goto x86_l_1ba8;
	case 7084ULL: goto x86_l_1bac;
	case 7089ULL: goto x86_l_1bb1;
	case 7094ULL: goto x86_l_1bb6;
	case 7099ULL: goto x86_l_1bbb;
	case 7101ULL: goto x86_l_1bbd;
	case 7105ULL: goto x86_l_1bc1;
	case 7110ULL: goto x86_l_1bc6;
	case 7116ULL: goto x86_l_1bcc;
	case 7120ULL: goto x86_l_1bd0;
	case 7125ULL: goto x86_l_1bd5;
	case 7130ULL: goto x86_l_1bda;
	case 7135ULL: goto x86_l_1bdf;
	case 7137ULL: goto x86_l_1be1;
	case 7141ULL: goto x86_l_1be5;
	case 7146ULL: goto x86_l_1bea;
	case 7152ULL: goto x86_l_1bf0;
	case 7156ULL: goto x86_l_1bf4;
	case 7161ULL: goto x86_l_1bf9;
	case 7166ULL: goto x86_l_1bfe;
	case 7171ULL: goto x86_l_1c03;
	case 7174ULL: goto x86_l_1c06;
	case 7176ULL: goto x86_l_1c08;
	case 7181ULL: goto x86_l_1c0d;
	case 7188ULL: goto x86_l_1c14;
	case 7193ULL: goto x86_l_1c19;
	case 7198ULL: goto x86_l_1c1e;
	case 7203ULL: goto x86_l_1c23;
	case 7208ULL: goto x86_l_1c28;
	case 7210ULL: goto x86_l_1c2a;
	case 7215ULL: goto x86_l_1c2f;
	case 7220ULL: goto x86_l_1c34;
	case 7225ULL: goto x86_l_1c39;
	case 7234ULL: goto x86_l_1c42;
	case 7243ULL: goto x86_l_1c4b;
	case 7252ULL: goto x86_l_1c54;
	case 7261ULL: goto x86_l_1c5d;
	case 7270ULL: goto x86_l_1c66;
	case 7279ULL: goto x86_l_1c6f;
	case 7288ULL: goto x86_l_1c78;
	case 7297ULL: goto x86_l_1c81;
	case 7306ULL: goto x86_l_1c8a;
	case 7309ULL: goto x86_l_1c8d;
	case 7317ULL: goto x86_l_1c95;
	case 7322ULL: goto x86_l_1c9a;
	case 7327ULL: goto x86_l_1c9f;
	case 7332ULL: goto x86_l_1ca4;
	case 7335ULL: goto x86_l_1ca7;
	case 7337ULL: goto x86_l_1ca9;
	case 7340ULL: goto x86_l_1cac;
	case 7346ULL: goto x86_l_1cb2;
	case 7348ULL: goto x86_l_1cb4;
	case 7353ULL: goto x86_l_1cb9;
	case 7358ULL: goto x86_l_1cbe;
	case 7364ULL: goto x86_l_1cc4;
	case 7366ULL: goto x86_l_1cc6;
	case 7372ULL: goto x86_l_1ccc;
	case 7378ULL: goto x86_l_1cd2;
	case 7382ULL: goto x86_l_1cd6;
	case 7385ULL: goto x86_l_1cd9;
	case 7393ULL: goto x86_l_1ce1;
	case 7397ULL: goto x86_l_1ce5;
	case 7401ULL: goto x86_l_1ce9;
	case 7404ULL: goto x86_l_1cec;
	case 7410ULL: goto x86_l_1cf2;
	case 7415ULL: goto x86_l_1cf7;
	case 7422ULL: goto x86_l_1cfe;
	case 7427ULL: goto x86_l_1d03;
	case 7433ULL: goto x86_l_1d09;
	case 7435ULL: goto x86_l_1d0b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_15e1:
	/* 0x15e1: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_15e5:
	/* 0x15e5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15ea:
	/* 0x15ea: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_15ed:
	/* 0x15ed: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15f2:
	/* 0x15f2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_15f5:
	/* 0x15f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f7:
	/* 0x15f7: lea    rdx,[rbp+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_15fe:
	/* 0x15fe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1603:
	/* 0x1603: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_160b:
	/* 0x160b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1610:
	/* 0x1610: jmp    283c <generic_retkprobe_event+0x283c> */
	return 10300ULL;
x86_l_1615:
	/* 0x1615: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_161a:
	/* 0x161a: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_161f:
	/* 0x161f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1624:
	/* 0x1624: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_162b:
	/* 0x162b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1630:
	/* 0x1630: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1635:
	/* 0x1635: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1637:
	/* 0x1637: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_163a:
	/* 0x163a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_163d:
	/* 0x163d: js     1cfe <generic_retkprobe_event+0x1cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1cfe;
	}
x86_l_1643:
	/* 0x1643: lea    eax,[rbp-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1646:
	/* 0x1646: mov    DWORD PTR [r12],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_164a:
	/* 0x164a: add    rbp,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_164e:
	/* 0x164e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1653:
	/* 0x1653: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_1659:
	/* 0x1659: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_165b:
	/* 0x165b: jns    1ccc <generic_retkprobe_event+0x1ccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1ccc;
	}
x86_l_1661:
	/* 0x1661: jmp    f9a <generic_retkprobe_event+0xf9a> */
	return 3994ULL;
x86_l_1666:
	/* 0x1666: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_1669:
	/* 0x1669: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_166e:
	/* 0x166e: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1676:
	/* 0x1676: mov    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_167e:
	/* 0x167e: mov    QWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1685:
	/* 0x1685: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_168a:
	/* 0x168a: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_168d:
	/* 0x168d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1692:
	/* 0x1692: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1695:
	/* 0x1695: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1697:
	/* 0x1697: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_169a:
	/* 0x169a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_169f:
	/* 0x169f: js     1f6c <generic_retkprobe_event+0x1f6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8044ULL;
	}
x86_l_16a5:
	/* 0x16a5: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16a9:
	/* 0x16a9: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_16ac:
	/* 0x16ac: je     1f1a <generic_retkprobe_event+0x1f1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7962ULL;
	}
x86_l_16b2:
	/* 0x16b2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16b5:
	/* 0x16b5: jne    1f52 <generic_retkprobe_event+0x1f52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8018ULL;
	}
x86_l_16bb:
	/* 0x16bb: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16c0:
	/* 0x16c0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16c5:
	/* 0x16c5: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_16ca:
	/* 0x16ca: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16cf:
	/* 0x16cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16d1:
	/* 0x16d1: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_16d5:
	/* 0x16d5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16da:
	/* 0x16da: mov    QWORD PTR [rdi+0xa4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_16e1:
	/* 0x16e1: add    rdi,0x9e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 158ULL);
x86_l_16e8:
	/* 0x16e8: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_16ec:
	/* 0x16ec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16f1:
	/* 0x16f1: jmp    1f48 <generic_retkprobe_event+0x1f48> */
	return 8008ULL;
x86_l_16f6:
	/* 0x16f6: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16f9:
	/* 0x16f9: cmp    QWORD PTR [rsp+0x88],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552259ULL);
x86_l_1702:
	/* 0x1702: jb     17bf <generic_retkprobe_event+0x17bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_17bf;
	}
x86_l_1708:
	/* 0x1708: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1710:
	/* 0x1710: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1714:
	/* 0x1714: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_171a:
	/* 0x171a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_171f:
	/* 0x171f: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1724:
	/* 0x1724: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1729:
	/* 0x1729: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_172b:
	/* 0x172b: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1730:
	/* 0x1730: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1732:
	/* 0x1732: js     2b28 <generic_retkprobe_event+0x2b28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11048ULL;
	}
x86_l_1738:
	/* 0x1738: mov    rbp,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_173d:
	/* 0x173d: cmp    rbp,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_1740:
	/* 0x1740: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1743:
	/* 0x1743: cmovb  rax,rbp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_64, X86_CC_B);
x86_l_1747:
	/* 0x1747: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_174c:
	/* 0x174c: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_174f:
	/* 0x174f: cmovne rbp,rax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_64, X86_CC_NE);
x86_l_1753:
	/* 0x1753: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_1758:
	/* 0x1758: cmp    rbp,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4094ULL);
x86_l_175f:
	/* 0x175f: ja     2b28 <generic_retkprobe_event+0x2b28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11048ULL;
	}
x86_l_1765:
	/* 0x1765: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1768:
	/* 0x1768: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_176d:
	/* 0x176d: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1772:
	/* 0x1772: mov    QWORD PTR [rsp+0x20],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1777:
	/* 0x1777: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_177d:
	/* 0x177d: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1780:
	/* 0x1780: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1785:
	/* 0x1785: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_178a:
	/* 0x178a: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_178c:
	/* 0x178c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_178e:
	/* 0x178e: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1793:
	/* 0x1793: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1795:
	/* 0x1795: js     2b28 <generic_retkprobe_event+0x2b28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11048ULL;
	}
x86_l_179b:
	/* 0x179b: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17a0:
	/* 0x17a0: add    r14,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_17a3:
	/* 0x17a3: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_17a9:
	/* 0x17a9: je     2146 <generic_retkprobe_event+0x2146> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8518ULL;
	}
x86_l_17af:
	/* 0x17af: sub    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 16ULL);
x86_l_17b4:
	/* 0x17b4: jne    214d <generic_retkprobe_event+0x214d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8525ULL;
	}
x86_l_17ba:
	/* 0x17ba: jmp    2158 <generic_retkprobe_event+0x2158> */
	return 8536ULL;
x86_l_17bf:
	/* 0x17bf: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_17c2:
	/* 0x17c2: jmp    3ee <generic_retkprobe_event+0x3ee> */
	return 1006ULL;
x86_l_17c7:
	/* 0x17c7: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_17d0:
	/* 0x17d0: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_17d9:
	/* 0x17d9: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_17de:
	/* 0x17de: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17e3:
	/* 0x17e3: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17e8:
	/* 0x17e8: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17ed:
	/* 0x17ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17f2:
	/* 0x17f2: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_17f5:
	/* 0x17f5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_17f7:
	/* 0x17f7: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17fc:
	/* 0x17fc: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_1802:
	/* 0x1802: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_1808:
	/* 0x1808: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_180d:
	/* 0x180d: cmovb  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_1811:
	/* 0x1811: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1816:
	/* 0x1816: add    r14,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_181d:
	/* 0x181d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1822:
	/* 0x1822: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1825:
	/* 0x1825: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_1828:
	/* 0x1828: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_182b:
	/* 0x182b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_182d:
	/* 0x182d: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1832:
	/* 0x1832: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1834:
	/* 0x1834: js     1850 <generic_retkprobe_event+0x1850> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1850;
	}
x86_l_1836:
	/* 0x1836: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_183b:
	/* 0x183b: mov    DWORD PTR [rax+0xa0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1842:
	/* 0x1842: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1846:
	/* 0x1846: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_184b:
	/* 0x184b: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_184d:
	/* 0x184d: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_1850:
	/* 0x1850: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1855:
	/* 0x1855: mov    DWORD PTR [rax+0x9c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_185b:
	/* 0x185b: jmp    1cb4 <generic_retkprobe_event+0x1cb4> */
	goto x86_l_1cb4;
x86_l_1860:
	/* 0x1860: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1863:
	/* 0x1863: lea    r12,[rcx+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_186a:
	/* 0x186a: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_186e:
	/* 0x186e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1873:
	/* 0x1873: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1878:
	/* 0x1878: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_187a:
	/* 0x187a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_187f:
	/* 0x187f: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1886:
	/* 0x1886: lea    rdx,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_188a:
	/* 0x188a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_188f:
	/* 0x188f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1894:
	/* 0x1894: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1896:
	/* 0x1896: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_189b:
	/* 0x189b: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_18a2:
	/* 0x18a2: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18a6:
	/* 0x18a6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18ab:
	/* 0x18ab: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18b0:
	/* 0x18b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b2:
	/* 0x18b2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18b7:
	/* 0x18b7: lea    rdi,[rax+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_18be:
	/* 0x18be: lea    rdx,[r13+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_18c2:
	/* 0x18c2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18c7:
	/* 0x18c7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18cc:
	/* 0x18cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ce:
	/* 0x18ce: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18d3:
	/* 0x18d3: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_18da:
	/* 0x18da: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18de:
	/* 0x18de: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18e3:
	/* 0x18e3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18e8:
	/* 0x18e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ea:
	/* 0x18ea: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18ef:
	/* 0x18ef: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_18f6:
	/* 0x18f6: lea    rdx,[r13+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_18fa:
	/* 0x18fa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18ff:
	/* 0x18ff: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1904:
	/* 0x1904: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1906:
	/* 0x1906: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_190b:
	/* 0x190b: lea    rdi,[rax+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_1912:
	/* 0x1912: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1916:
	/* 0x1916: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_191b:
	/* 0x191b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1920:
	/* 0x1920: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1922:
	/* 0x1922: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1927:
	/* 0x1927: lea    rdi,[rax+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_192e:
	/* 0x192e: lea    rdx,[r13+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1932:
	/* 0x1932: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1937:
	/* 0x1937: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_193c:
	/* 0x193c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_193e:
	/* 0x193e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1943:
	/* 0x1943: mov    DWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_194d:
	/* 0x194d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1952:
	/* 0x1952: lea    rdi,[rax+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1959:
	/* 0x1959: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_195d:
	/* 0x195d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1962:
	/* 0x1962: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1967:
	/* 0x1967: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1969:
	/* 0x1969: mov    rcx,QWORD PTR [r13+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_196d:
	/* 0x196d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1972:
	/* 0x1972: mov    QWORD PTR [rax+0xcc],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1979:
	/* 0x1979: mov    rcx,QWORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_197d:
	/* 0x197d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1982:
	/* 0x1982: mov    QWORD PTR [rax+0xd4],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_1989:
	/* 0x1989: mov    rcx,QWORD PTR [r13+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_198d:
	/* 0x198d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1992:
	/* 0x1992: mov    QWORD PTR [rax+0xc4],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1999:
	/* 0x1999: add    r13,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_19a0:
	/* 0x19a0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19a5:
	/* 0x19a5: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19aa:
	/* 0x19aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19af:
	/* 0x19af: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_19b2:
	/* 0x19b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b4:
	/* 0x19b4: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19b9:
	/* 0x19b9: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_19c0:
	/* 0x19c0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19c5:
	/* 0x19c5: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_19c8:
	/* 0x19c8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19cd:
	/* 0x19cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19cf:
	/* 0x19cf: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19d4:
	/* 0x19d4: lea    rdi,[rax+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_19db:
	/* 0x19db: lea    rdx,[r13+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_19e2:
	/* 0x19e2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19e7:
	/* 0x19e7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19ec:
	/* 0x19ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19ee:
	/* 0x19ee: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19f3:
	/* 0x19f3: lea    rdi,[rax+0xe4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_19fa:
	/* 0x19fa: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1a01:
	/* 0x1a01: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a06:
	/* 0x1a06: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a0b:
	/* 0x1a0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a0d:
	/* 0x1a0d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a12:
	/* 0x1a12: add    rdi,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1a19:
	/* 0x1a19: add    r13,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1a20:
	/* 0x1a20: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a25:
	/* 0x1a25: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a2a:
	/* 0x1a2a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1a2d:
	/* 0x1a2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a2f:
	/* 0x1a2f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a34:
	/* 0x1a34: mov    ebp,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 80ULL);
x86_l_1a39:
	/* 0x1a39: jmp    1cb9 <generic_retkprobe_event+0x1cb9> */
	goto x86_l_1cb9;
x86_l_1a3e:
	/* 0x1a3e: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1a45:
	/* 0x1a45: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a4a:
	/* 0x1a4a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1a4d:
	/* 0x1a4d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a52:
	/* 0x1a52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a54:
	/* 0x1a54: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a59:
	/* 0x1a59: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1a60:
	/* 0x1a60: lea    rdx,[r13+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1a67:
	/* 0x1a67: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a6c:
	/* 0x1a6c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a71:
	/* 0x1a71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a73:
	/* 0x1a73: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a78:
	/* 0x1a78: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1a7f:
	/* 0x1a7f: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1a86:
	/* 0x1a86: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a8b:
	/* 0x1a8b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a90:
	/* 0x1a90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a92:
	/* 0x1a92: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a97:
	/* 0x1a97: add    rdi,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_1a9e:
	/* 0x1a9e: add    r13,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1aa5:
	/* 0x1aa5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1aaa:
	/* 0x1aaa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1aaf:
	/* 0x1aaf: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1ab2:
	/* 0x1ab2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ab4:
	/* 0x1ab4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ab9:
	/* 0x1ab9: mov    ebp,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_1abe:
	/* 0x1abe: jmp    1cb9 <generic_retkprobe_event+0x1cb9> */
	goto x86_l_1cb9;
x86_l_1ac3:
	/* 0x1ac3: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ac7:
	/* 0x1ac7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1acc:
	/* 0x1acc: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1acf:
	/* 0x1acf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ad4:
	/* 0x1ad4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad6:
	/* 0x1ad6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1adb:
	/* 0x1adb: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1ae2:
	/* 0x1ae2: lea    rdx,[r13+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1ae6:
	/* 0x1ae6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1aeb:
	/* 0x1aeb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1af0:
	/* 0x1af0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af2:
	/* 0x1af2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1af7:
	/* 0x1af7: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1afe:
	/* 0x1afe: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b02:
	/* 0x1b02: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b07:
	/* 0x1b07: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b0c:
	/* 0x1b0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b0e:
	/* 0x1b0e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b13:
	/* 0x1b13: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1b1a:
	/* 0x1b1a: lea    rdx,[r13+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1b1e:
	/* 0x1b1e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b23:
	/* 0x1b23: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b28:
	/* 0x1b28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b2a:
	/* 0x1b2a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b2f:
	/* 0x1b2f: add    rdi,0xac */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 172ULL);
x86_l_1b36:
	/* 0x1b36: add    r13,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1b3a:
	/* 0x1b3a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b3f:
	/* 0x1b3f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b44:
	/* 0x1b44: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1b47:
	/* 0x1b47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b49:
	/* 0x1b49: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b4e:
	/* 0x1b4e: mov    ebp,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 32ULL);
x86_l_1b53:
	/* 0x1b53: jmp    1cb9 <generic_retkprobe_event+0x1cb9> */
	goto x86_l_1cb9;
x86_l_1b58:
	/* 0x1b58: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b5d:
	/* 0x1b5d: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1b60:
	/* 0x1b60: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b65:
	/* 0x1b65: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1b68:
	/* 0x1b68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b6a:
	/* 0x1b6a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b6f:
	/* 0x1b6f: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1b76:
	/* 0x1b76: lea    rdx,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b7a:
	/* 0x1b7a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b7f:
	/* 0x1b7f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b84:
	/* 0x1b84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b86:
	/* 0x1b86: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b8b:
	/* 0x1b8b: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1b92:
	/* 0x1b92: add    r13,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_1b96:
	/* 0x1b96: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b9b:
	/* 0x1b9b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1ba0:
	/* 0x1ba0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1ba3:
	/* 0x1ba3: jmp    1c28 <generic_retkprobe_event+0x1c28> */
	goto x86_l_1c28;
x86_l_1ba8:
	/* 0x1ba8: lea    rdx,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1bac:
	/* 0x1bac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bb1:
	/* 0x1bb1: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1bb6:
	/* 0x1bb6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bbb:
	/* 0x1bbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bbd:
	/* 0x1bbd: mov    ecx,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1bc1:
	/* 0x1bc1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bc6:
	/* 0x1bc6: mov    DWORD PTR [rax+0x9c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1bcc:
	/* 0x1bcc: lea    rdx,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1bd0:
	/* 0x1bd0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bd5:
	/* 0x1bd5: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1bda:
	/* 0x1bda: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bdf:
	/* 0x1bdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1be1:
	/* 0x1be1: mov    ecx,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1be5:
	/* 0x1be5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bea:
	/* 0x1bea: mov    DWORD PTR [rax+0xa0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1bf0:
	/* 0x1bf0: add    r13,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1bf4:
	/* 0x1bf4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bf9:
	/* 0x1bf9: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1bfe:
	/* 0x1bfe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c03:
	/* 0x1c03: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1c06:
	/* 0x1c06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c08:
	/* 0x1c08: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c0d:
	/* 0x1c0d: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1c14:
	/* 0x1c14: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1c19:
	/* 0x1c19: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_1c1e:
	/* 0x1c1e: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_1c23:
	/* 0x1c23: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1c28:
	/* 0x1c28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c2a:
	/* 0x1c2a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c2f:
	/* 0x1c2f: mov    ebp,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_1c34:
	/* 0x1c34: jmp    1cb9 <generic_retkprobe_event+0x1cb9> */
	goto x86_l_1cb9;
x86_l_1c39:
	/* 0x1c39: mov    QWORD PTR [r12+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1c42:
	/* 0x1c42: mov    QWORD PTR [r12+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1c4b:
	/* 0x1c4b: mov    QWORD PTR [r12+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1c54:
	/* 0x1c54: mov    QWORD PTR [r12+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1c5d:
	/* 0x1c5d: mov    QWORD PTR [r12+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1c66:
	/* 0x1c66: mov    QWORD PTR [r12+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1c6f:
	/* 0x1c6f: mov    QWORD PTR [r12+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1c78:
	/* 0x1c78: mov    QWORD PTR [r12+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1c81:
	/* 0x1c81: mov    QWORD PTR [r12+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1c8a:
	/* 0x1c8a: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_1c8d:
	/* 0x1c8d: mov    QWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c95:
	/* 0x1c95: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c9a:
	/* 0x1c9a: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1c9f:
	/* 0x1c9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ca4:
	/* 0x1ca4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1ca7:
	/* 0x1ca7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca9:
	/* 0x1ca9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cac:
	/* 0x1cac: je     1f84 <generic_retkprobe_event+0x1f84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8068ULL;
	}
x86_l_1cb2:
	/* 0x1cb2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cb4:
	/* 0x1cb4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cb9:
	/* 0x1cb9: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1cbe:
	/* 0x1cbe: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_1cc4:
	/* 0x1cc4: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1cc6:
	/* 0x1cc6: js     f9a <generic_retkprobe_event+0xf9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3994ULL;
	}
x86_l_1ccc:
	/* 0x1ccc: and    ebp,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_1cd2:
	/* 0x1cd2: add    rbp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1cd6:
	/* 0x1cd6: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_1cd9:
	/* 0x1cd9: mov    rbp,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1ce1:
	/* 0x1ce1: add    r14,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1ce5:
	/* 0x1ce5: mov    eax,DWORD PTR [r13+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1ce9:
	/* 0x1ce9: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1cec:
	/* 0x1cec: jne    191 <generic_retkprobe_event+0x191> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 401ULL;
	}
x86_l_1cf2:
	/* 0x1cf2: jmp    2d3 <generic_retkprobe_event+0x2d3> */
	return 723ULL;
x86_l_1cf7:
	/* 0x1cf7: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1cfe:
	/* 0x1cfe: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d03:
	/* 0x1d03: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_1d09:
	/* 0x1d09: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1d0b:
	/* 0x1d0b: jns    1ccc <generic_retkprobe_event+0x1ccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1ccc;
	}
	return 7437ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7437ULL: goto x86_l_1d0d;
	case 7442ULL: goto x86_l_1d12;
	case 7447ULL: goto x86_l_1d17;
	case 7452ULL: goto x86_l_1d1c;
	case 7457ULL: goto x86_l_1d21;
	case 7462ULL: goto x86_l_1d26;
	case 7467ULL: goto x86_l_1d2b;
	case 7469ULL: goto x86_l_1d2d;
	case 7473ULL: goto x86_l_1d31;
	case 7478ULL: goto x86_l_1d36;
	case 7486ULL: goto x86_l_1d3e;
	case 7491ULL: goto x86_l_1d43;
	case 7494ULL: goto x86_l_1d46;
	case 7496ULL: goto x86_l_1d48;
	case 7501ULL: goto x86_l_1d4d;
	case 7509ULL: goto x86_l_1d55;
	case 7516ULL: goto x86_l_1d5c;
	case 7522ULL: goto x86_l_1d62;
	case 7526ULL: goto x86_l_1d66;
	case 7529ULL: goto x86_l_1d69;
	case 7536ULL: goto x86_l_1d70;
	case 7541ULL: goto x86_l_1d75;
	case 7544ULL: goto x86_l_1d78;
	case 7546ULL: goto x86_l_1d7a;
	case 7548ULL: goto x86_l_1d7c;
	case 7550ULL: goto x86_l_1d7e;
	case 7557ULL: goto x86_l_1d85;
	case 7564ULL: goto x86_l_1d8c;
	case 7568ULL: goto x86_l_1d90;
	case 7571ULL: goto x86_l_1d93;
	case 7576ULL: goto x86_l_1d98;
	case 7587ULL: goto x86_l_1da3;
	case 7592ULL: goto x86_l_1da8;
	case 7597ULL: goto x86_l_1dad;
	case 7606ULL: goto x86_l_1db6;
	case 7611ULL: goto x86_l_1dbb;
	case 7615ULL: goto x86_l_1dbf;
	case 7623ULL: goto x86_l_1dc7;
	case 7628ULL: goto x86_l_1dcc;
	case 7635ULL: goto x86_l_1dd3;
	case 7640ULL: goto x86_l_1dd8;
	case 7642ULL: goto x86_l_1dda;
	case 7645ULL: goto x86_l_1ddd;
	case 7651ULL: goto x86_l_1de3;
	case 7654ULL: goto x86_l_1de6;
	case 7658ULL: goto x86_l_1dea;
	case 7662ULL: goto x86_l_1dee;
	case 7666ULL: goto x86_l_1df2;
	case 7669ULL: goto x86_l_1df5;
	case 7673ULL: goto x86_l_1df9;
	case 7678ULL: goto x86_l_1dfe;
	case 7683ULL: goto x86_l_1e03;
	case 7686ULL: goto x86_l_1e06;
	case 7691ULL: goto x86_l_1e0b;
	case 7693ULL: goto x86_l_1e0d;
	case 7696ULL: goto x86_l_1e10;
	case 7702ULL: goto x86_l_1e16;
	case 7707ULL: goto x86_l_1e1b;
	case 7710ULL: goto x86_l_1e1e;
	case 7716ULL: goto x86_l_1e24;
	case 7718ULL: goto x86_l_1e26;
	case 7724ULL: goto x86_l_1e2c;
	case 7727ULL: goto x86_l_1e2f;
	case 7733ULL: goto x86_l_1e35;
	case 7736ULL: goto x86_l_1e38;
	case 7742ULL: goto x86_l_1e3e;
	case 7749ULL: goto x86_l_1e45;
	case 7753ULL: goto x86_l_1e49;
	case 7758ULL: goto x86_l_1e4e;
	case 7763ULL: goto x86_l_1e53;
	case 7768ULL: goto x86_l_1e58;
	case 7773ULL: goto x86_l_1e5d;
	case 7775ULL: goto x86_l_1e5f;
	case 7780ULL: goto x86_l_1e64;
	case 7785ULL: goto x86_l_1e69;
	case 7788ULL: goto x86_l_1e6c;
	case 7793ULL: goto x86_l_1e71;
	case 7795ULL: goto x86_l_1e73;
	case 7800ULL: goto x86_l_1e78;
	case 7807ULL: goto x86_l_1e7f;
	case 7812ULL: goto x86_l_1e84;
	case 7816ULL: goto x86_l_1e88;
	case 7821ULL: goto x86_l_1e8d;
	case 7826ULL: goto x86_l_1e92;
	case 7829ULL: goto x86_l_1e95;
	case 7831ULL: goto x86_l_1e97;
	case 7834ULL: goto x86_l_1e9a;
	case 7841ULL: goto x86_l_1ea1;
	case 7846ULL: goto x86_l_1ea6;
	case 7851ULL: goto x86_l_1eab;
	case 7854ULL: goto x86_l_1eae;
	case 7856ULL: goto x86_l_1eb0;
	case 7864ULL: goto x86_l_1eb8;
	case 7874ULL: goto x86_l_1ec2;
	case 7879ULL: goto x86_l_1ec7;
	case 7884ULL: goto x86_l_1ecc;
	case 7889ULL: goto x86_l_1ed1;
	case 7896ULL: goto x86_l_1ed8;
	case 7901ULL: goto x86_l_1edd;
	case 7903ULL: goto x86_l_1edf;
	case 7906ULL: goto x86_l_1ee2;
	case 7912ULL: goto x86_l_1ee8;
	case 7914ULL: goto x86_l_1eea;
	case 7919ULL: goto x86_l_1eef;
	case 7922ULL: goto x86_l_1ef2;
	case 7926ULL: goto x86_l_1ef6;
	case 7930ULL: goto x86_l_1efa;
	case 7933ULL: goto x86_l_1efd;
	case 7936ULL: goto x86_l_1f00;
	case 7941ULL: goto x86_l_1f05;
	case 7952ULL: goto x86_l_1f10;
	case 7957ULL: goto x86_l_1f15;
	case 7962ULL: goto x86_l_1f1a;
	case 7969ULL: goto x86_l_1f21;
	case 7974ULL: goto x86_l_1f26;
	case 7979ULL: goto x86_l_1f2b;
	case 7984ULL: goto x86_l_1f30;
	case 7987ULL: goto x86_l_1f33;
	case 7989ULL: goto x86_l_1f35;
	case 7992ULL: goto x86_l_1f38;
	case 7999ULL: goto x86_l_1f3f;
	case 8003ULL: goto x86_l_1f43;
	case 8008ULL: goto x86_l_1f48;
	case 8013ULL: goto x86_l_1f4d;
	case 8016ULL: goto x86_l_1f50;
	case 8018ULL: goto x86_l_1f52;
	case 8023ULL: goto x86_l_1f57;
	case 8030ULL: goto x86_l_1f5e;
	case 8039ULL: goto x86_l_1f67;
	case 8044ULL: goto x86_l_1f6c;
	case 8049ULL: goto x86_l_1f71;
	case 8055ULL: goto x86_l_1f77;
	case 8057ULL: goto x86_l_1f79;
	case 8063ULL: goto x86_l_1f7f;
	case 8068ULL: goto x86_l_1f84;
	case 8073ULL: goto x86_l_1f89;
	case 8080ULL: goto x86_l_1f90;
	case 8085ULL: goto x86_l_1f95;
	case 8090ULL: goto x86_l_1f9a;
	case 8095ULL: goto x86_l_1f9f;
	case 8097ULL: goto x86_l_1fa1;
	case 8100ULL: goto x86_l_1fa4;
	case 8106ULL: goto x86_l_1faa;
	case 8110ULL: goto x86_l_1fae;
	case 8115ULL: goto x86_l_1fb3;
	case 8120ULL: goto x86_l_1fb8;
	case 8125ULL: goto x86_l_1fbd;
	case 8127ULL: goto x86_l_1fbf;
	case 8132ULL: goto x86_l_1fc4;
	case 8139ULL: goto x86_l_1fcb;
	case 8144ULL: goto x86_l_1fd0;
	case 8149ULL: goto x86_l_1fd5;
	case 8154ULL: goto x86_l_1fda;
	case 8159ULL: goto x86_l_1fdf;
	case 8161ULL: goto x86_l_1fe1;
	case 8165ULL: goto x86_l_1fe5;
	case 8170ULL: goto x86_l_1fea;
	case 8175ULL: goto x86_l_1fef;
	case 8180ULL: goto x86_l_1ff4;
	case 8183ULL: goto x86_l_1ff7;
	case 8185ULL: goto x86_l_1ff9;
	case 8190ULL: goto x86_l_1ffe;
	case 8193ULL: goto x86_l_2001;
	case 8199ULL: goto x86_l_2007;
	case 8201ULL: goto x86_l_2009;
	case 8206ULL: goto x86_l_200e;
	case 8209ULL: goto x86_l_2011;
	case 8212ULL: goto x86_l_2014;
	case 8217ULL: goto x86_l_2019;
	case 8221ULL: goto x86_l_201d;
	case 8226ULL: goto x86_l_2022;
	case 8231ULL: goto x86_l_2027;
	case 8234ULL: goto x86_l_202a;
	case 8236ULL: goto x86_l_202c;
	case 8239ULL: goto x86_l_202f;
	case 8241ULL: goto x86_l_2031;
	case 8243ULL: goto x86_l_2033;
	case 8245ULL: goto x86_l_2035;
	case 8250ULL: goto x86_l_203a;
	case 8256ULL: goto x86_l_2040;
	case 8261ULL: goto x86_l_2045;
	case 8266ULL: goto x86_l_204a;
	case 8271ULL: goto x86_l_204f;
	case 8276ULL: goto x86_l_2054;
	case 8279ULL: goto x86_l_2057;
	case 8284ULL: goto x86_l_205c;
	case 8286ULL: goto x86_l_205e;
	case 8291ULL: goto x86_l_2063;
	case 8296ULL: goto x86_l_2068;
	case 8299ULL: goto x86_l_206b;
	case 8304ULL: goto x86_l_2070;
	case 8306ULL: goto x86_l_2072;
	case 8311ULL: goto x86_l_2077;
	case 8318ULL: goto x86_l_207e;
	case 8323ULL: goto x86_l_2083;
	case 8327ULL: goto x86_l_2087;
	case 8332ULL: goto x86_l_208c;
	case 8337ULL: goto x86_l_2091;
	case 8340ULL: goto x86_l_2094;
	case 8342ULL: goto x86_l_2096;
	case 8345ULL: goto x86_l_2099;
	case 8352ULL: goto x86_l_20a0;
	case 8357ULL: goto x86_l_20a5;
	case 8362ULL: goto x86_l_20aa;
	case 8365ULL: goto x86_l_20ad;
	case 8367ULL: goto x86_l_20af;
	case 8374ULL: goto x86_l_20b6;
	case 8383ULL: goto x86_l_20bf;
	case 8388ULL: goto x86_l_20c4;
	case 8395ULL: goto x86_l_20cb;
	case 8400ULL: goto x86_l_20d0;
	case 8405ULL: goto x86_l_20d5;
	case 8412ULL: goto x86_l_20dc;
	case 8417ULL: goto x86_l_20e1;
	case 8419ULL: goto x86_l_20e3;
	case 8422ULL: goto x86_l_20e6;
	case 8424ULL: goto x86_l_20e8;
	case 8426ULL: goto x86_l_20ea;
	case 8431ULL: goto x86_l_20ef;
	case 8435ULL: goto x86_l_20f3;
	case 8439ULL: goto x86_l_20f7;
	case 8443ULL: goto x86_l_20fb;
	case 8446ULL: goto x86_l_20fe;
	case 8450ULL: goto x86_l_2102;
	case 8455ULL: goto x86_l_2107;
	case 8460ULL: goto x86_l_210c;
	case 8463ULL: goto x86_l_210f;
	case 8469ULL: goto x86_l_2115;
	case 8472ULL: goto x86_l_2118;
	case 8474ULL: goto x86_l_211a;
	case 8479ULL: goto x86_l_211f;
	case 8485ULL: goto x86_l_2125;
	case 8492ULL: goto x86_l_212c;
	case 8496ULL: goto x86_l_2130;
	case 8501ULL: goto x86_l_2135;
	case 8506ULL: goto x86_l_213a;
	case 8513ULL: goto x86_l_2141;
	case 8518ULL: goto x86_l_2146;
	case 8520ULL: goto x86_l_2148;
	case 8525ULL: goto x86_l_214d;
	case 8534ULL: goto x86_l_2156;
	case 8536ULL: goto x86_l_2158;
	case 8539ULL: goto x86_l_215b;
	case 8544ULL: goto x86_l_2160;
	case 8549ULL: goto x86_l_2165;
	case 8557ULL: goto x86_l_216d;
	case 8561ULL: goto x86_l_2171;
	case 8567ULL: goto x86_l_2177;
	case 8572ULL: goto x86_l_217c;
	case 8577ULL: goto x86_l_2181;
	case 8582ULL: goto x86_l_2186;
	case 8584ULL: goto x86_l_2188;
	case 8589ULL: goto x86_l_218d;
	case 8591ULL: goto x86_l_218f;
	case 8597ULL: goto x86_l_2195;
	case 8602ULL: goto x86_l_219a;
	case 8607ULL: goto x86_l_219f;
	case 8610ULL: goto x86_l_21a2;
	case 8613ULL: goto x86_l_21a5;
	case 8617ULL: goto x86_l_21a9;
	case 8620ULL: goto x86_l_21ac;
	case 8623ULL: goto x86_l_21af;
	case 8627ULL: goto x86_l_21b3;
	case 8632ULL: goto x86_l_21b8;
	case 8639ULL: goto x86_l_21bf;
	case 8645ULL: goto x86_l_21c5;
	case 8648ULL: goto x86_l_21c8;
	case 8653ULL: goto x86_l_21cd;
	case 8658ULL: goto x86_l_21d2;
	case 8663ULL: goto x86_l_21d7;
	case 8669ULL: goto x86_l_21dd;
	case 8672ULL: goto x86_l_21e0;
	case 8677ULL: goto x86_l_21e5;
	case 8682ULL: goto x86_l_21ea;
	case 8684ULL: goto x86_l_21ec;
	case 8686ULL: goto x86_l_21ee;
	case 8691ULL: goto x86_l_21f3;
	case 8693ULL: goto x86_l_21f5;
	case 8699ULL: goto x86_l_21fb;
	case 8702ULL: goto x86_l_21fe;
	case 8708ULL: goto x86_l_2204;
	case 8714ULL: goto x86_l_220a;
	case 8719ULL: goto x86_l_220f;
	case 8725ULL: goto x86_l_2215;
	case 8730ULL: goto x86_l_221a;
	case 8735ULL: goto x86_l_221f;
	case 8742ULL: goto x86_l_2226;
	case 8747ULL: goto x86_l_222b;
	case 8752ULL: goto x86_l_2230;
	case 8757ULL: goto x86_l_2235;
	case 8762ULL: goto x86_l_223a;
	case 8766ULL: goto x86_l_223e;
	case 8772ULL: goto x86_l_2244;
	case 8782ULL: goto x86_l_224e;
	case 8786ULL: goto x86_l_2252;
	case 8792ULL: goto x86_l_2258;
	case 8796ULL: goto x86_l_225c;
	case 8801ULL: goto x86_l_2261;
	case 8806ULL: goto x86_l_2266;
	case 8811ULL: goto x86_l_226b;
	case 8814ULL: goto x86_l_226e;
	case 8819ULL: goto x86_l_2273;
	case 8821ULL: goto x86_l_2275;
	case 8824ULL: goto x86_l_2278;
	case 8830ULL: goto x86_l_227e;
	case 8835ULL: goto x86_l_2283;
	case 8838ULL: goto x86_l_2286;
	case 8840ULL: goto x86_l_2288;
	case 8842ULL: goto x86_l_228a;
	case 8844ULL: goto x86_l_228c;
	case 8847ULL: goto x86_l_228f;
	case 8849ULL: goto x86_l_2291;
	case 8852ULL: goto x86_l_2294;
	case 8854ULL: goto x86_l_2296;
	case 8861ULL: goto x86_l_229d;
	case 8865ULL: goto x86_l_22a1;
	case 8867ULL: goto x86_l_22a3;
	case 8870ULL: goto x86_l_22a6;
	case 8872ULL: goto x86_l_22a8;
	case 8875ULL: goto x86_l_22ab;
	case 8877ULL: goto x86_l_22ad;
	case 8882ULL: goto x86_l_22b2;
	case 8884ULL: goto x86_l_22b4;
	case 8891ULL: goto x86_l_22bb;
	case 8895ULL: goto x86_l_22bf;
	case 8897ULL: goto x86_l_22c1;
	case 8902ULL: goto x86_l_22c6;
	case 8909ULL: goto x86_l_22cd;
	case 8914ULL: goto x86_l_22d2;
	case 8916ULL: goto x86_l_22d4;
	case 8921ULL: goto x86_l_22d9;
	case 8926ULL: goto x86_l_22de;
	case 8931ULL: goto x86_l_22e3;
	case 8938ULL: goto x86_l_22ea;
	case 8943ULL: goto x86_l_22ef;
	case 8945ULL: goto x86_l_22f1;
	case 8950ULL: goto x86_l_22f6;
	case 8955ULL: goto x86_l_22fb;
	case 8960ULL: goto x86_l_2300;
	case 8965ULL: goto x86_l_2305;
	case 8969ULL: goto x86_l_2309;
	case 8975ULL: goto x86_l_230f;
	case 8985ULL: goto x86_l_2319;
	case 8989ULL: goto x86_l_231d;
	case 8995ULL: goto x86_l_2323;
	case 8999ULL: goto x86_l_2327;
	case 9004ULL: goto x86_l_232c;
	case 9009ULL: goto x86_l_2331;
	case 9014ULL: goto x86_l_2336;
	case 9017ULL: goto x86_l_2339;
	case 9022ULL: goto x86_l_233e;
	case 9024ULL: goto x86_l_2340;
	case 9027ULL: goto x86_l_2343;
	case 9033ULL: goto x86_l_2349;
	case 9038ULL: goto x86_l_234e;
	case 9041ULL: goto x86_l_2351;
	case 9043ULL: goto x86_l_2353;
	case 9045ULL: goto x86_l_2355;
	case 9047ULL: goto x86_l_2357;
	case 9050ULL: goto x86_l_235a;
	case 9052ULL: goto x86_l_235c;
	case 9055ULL: goto x86_l_235f;
	case 9057ULL: goto x86_l_2361;
	case 9064ULL: goto x86_l_2368;
	case 9068ULL: goto x86_l_236c;
	case 9070ULL: goto x86_l_236e;
	case 9073ULL: goto x86_l_2371;
	case 9075ULL: goto x86_l_2373;
	case 9078ULL: goto x86_l_2376;
	case 9080ULL: goto x86_l_2378;
	case 9085ULL: goto x86_l_237d;
	case 9087ULL: goto x86_l_237f;
	case 9094ULL: goto x86_l_2386;
	case 9098ULL: goto x86_l_238a;
	case 9100ULL: goto x86_l_238c;
	case 9105ULL: goto x86_l_2391;
	case 9112ULL: goto x86_l_2398;
	case 9117ULL: goto x86_l_239d;
	case 9119ULL: goto x86_l_239f;
	case 9124ULL: goto x86_l_23a4;
	case 9131ULL: goto x86_l_23ab;
	case 9136ULL: goto x86_l_23b0;
	case 9138ULL: goto x86_l_23b2;
	case 9143ULL: goto x86_l_23b7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1d0d:
	/* 0x1d0d: jmp    f9a <generic_retkprobe_event+0xf9a> */
	return 3994ULL;
x86_l_1d12:
	/* 0x1d12: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d17:
	/* 0x1d17: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1d1c:
	/* 0x1d1c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d21:
	/* 0x1d21: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d26:
	/* 0x1d26: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d2b:
	/* 0x1d2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d2d:
	/* 0x1d2d: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1d31:
	/* 0x1d31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d36:
	/* 0x1d36: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1d3e:
	/* 0x1d3e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d43:
	/* 0x1d43: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d46:
	/* 0x1d46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d48:
	/* 0x1d48: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d4d:
	/* 0x1d4d: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1d55:
	/* 0x1d55: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_1d5c:
	/* 0x1d5c: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_1d62:
	/* 0x1d62: cmovb  r12,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_1d66:
	/* 0x1d66: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1d69:
	/* 0x1d69: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1d70:
	/* 0x1d70: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d75:
	/* 0x1d75: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_1d78:
	/* 0x1d78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d7a:
	/* 0x1d7a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d7c:
	/* 0x1d7c: js     1d98 <generic_retkprobe_event+0x1d98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1d98;
	}
x86_l_1d7e:
	/* 0x1d7e: mov    DWORD PTR [r14+0x9c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1d85:
	/* 0x1d85: mov    DWORD PTR [r14+0xa0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1d8c:
	/* 0x1d8c: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1d90:
	/* 0x1d90: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_1d93:
	/* 0x1d93: jmp    1cb4 <generic_retkprobe_event+0x1cb4> */
	return 7348ULL;
x86_l_1d98:
	/* 0x1d98: mov    DWORD PTR [r14+0x9c],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 674309865470ULL);
x86_l_1da3:
	/* 0x1da3: jmp    1cb4 <generic_retkprobe_event+0x1cb4> */
	return 7348ULL;
x86_l_1da8:
	/* 0x1da8: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1dad:
	/* 0x1dad: movzx  r14d,WORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 176ULL);
x86_l_1db6:
	/* 0x1db6: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dbb:
	/* 0x1dbb: lea    r12,[rax+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1dbf:
	/* 0x1dbf: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1dc7:
	/* 0x1dc7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dcc:
	/* 0x1dcc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_1dd3:
	/* 0x1dd3: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1dd8:
	/* 0x1dd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dda:
	/* 0x1dda: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ddd:
	/* 0x1ddd: je     27eb <generic_retkprobe_event+0x27eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10219ULL;
	}
x86_l_1de3:
	/* 0x1de3: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1de6:
	/* 0x1de6: mov    WORD PTR [rax],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dea:
	/* 0x1dea: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_1dee:
	/* 0x1dee: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_1df2:
	/* 0x1df2: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1df5:
	/* 0x1df5: add    rdi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1df9:
	/* 0x1df9: lea    rdx,[r12+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1dfe:
	/* 0x1dfe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e03:
	/* 0x1e03: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_1e06:
	/* 0x1e06: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1e0b:
	/* 0x1e0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e0d:
	/* 0x1e0d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e10:
	/* 0x1e10: js     27eb <generic_retkprobe_event+0x27eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10219ULL;
	}
x86_l_1e16:
	/* 0x1e16: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_1e1b:
	/* 0x1e1b: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_1e1e:
	/* 0x1e1e: jg     210c <generic_retkprobe_event+0x210c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_210c;
	}
x86_l_1e24:
	/* 0x1e24: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e26:
	/* 0x1e26: je     2135 <generic_retkprobe_event+0x2135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2135;
	}
x86_l_1e2c:
	/* 0x1e2c: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1e2f:
	/* 0x1e2f: je     2135 <generic_retkprobe_event+0x2135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2135;
	}
x86_l_1e35:
	/* 0x1e35: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1e38:
	/* 0x1e38: jne    22d4 <generic_retkprobe_event+0x22d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22d4;
	}
x86_l_1e3e:
	/* 0x1e3e: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_1e45:
	/* 0x1e45: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_1e49:
	/* 0x1e49: jmp    222b <generic_retkprobe_event+0x222b> */
	goto x86_l_222b;
x86_l_1e4e:
	/* 0x1e4e: lea    rdx,[r12+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1e53:
	/* 0x1e53: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e58:
	/* 0x1e58: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e5d:
	/* 0x1e5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e5f:
	/* 0x1e5f: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1e64:
	/* 0x1e64: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e69:
	/* 0x1e69: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1e6c:
	/* 0x1e6c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e71:
	/* 0x1e71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e73:
	/* 0x1e73: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e78:
	/* 0x1e78: lea    rdi,[r14+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1e7f:
	/* 0x1e7f: lea    r13,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e84:
	/* 0x1e84: add    r12,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_1e88:
	/* 0x1e88: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e8d:
	/* 0x1e8d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1e92:
	/* 0x1e92: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1e95:
	/* 0x1e95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e97:
	/* 0x1e97: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1e9a:
	/* 0x1e9a: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_1ea1:
	/* 0x1ea1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ea6:
	/* 0x1ea6: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1eab:
	/* 0x1eab: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1eae:
	/* 0x1eae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eb0:
	/* 0x1eb0: movzx  eax,WORD PTR [r14+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1eb8:
	/* 0x1eb8: movbe  WORD PTR [r14+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1ec2:
	/* 0x1ec2: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ec7:
	/* 0x1ec7: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1ecc:
	/* 0x1ecc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ed1:
	/* 0x1ed1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_1ed8:
	/* 0x1ed8: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1edd:
	/* 0x1edd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1edf:
	/* 0x1edf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ee2:
	/* 0x1ee2: je     2102 <generic_retkprobe_event+0x2102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2102;
	}
x86_l_1ee8:
	/* 0x1ee8: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eea:
	/* 0x1eea: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1eef:
	/* 0x1eef: mov    DWORD PTR [rdx+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ef2:
	/* 0x1ef2: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ef6:
	/* 0x1ef6: mov    QWORD PTR [rdx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1efa:
	/* 0x1efa: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1efd:
	/* 0x1efd: mov    DWORD PTR [rdx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1f00:
	/* 0x1f00: jmp    2102 <generic_retkprobe_event+0x2102> */
	goto x86_l_2102;
x86_l_1f05:
	/* 0x1f05: mov    QWORD PTR [r14+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1f10:
	/* 0x1f10: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_1f15:
	/* 0x1f15: jmp    1cb4 <generic_retkprobe_event+0x1cb4> */
	return 7348ULL;
x86_l_1f1a:
	/* 0x1f1a: lea    rdi,[rcx+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1f21:
	/* 0x1f21: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f26:
	/* 0x1f26: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f2b:
	/* 0x1f2b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1f30:
	/* 0x1f30: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_1f33:
	/* 0x1f33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f35:
	/* 0x1f35: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1f38:
	/* 0x1f38: add    rdi,0x9e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 158ULL);
x86_l_1f3f:
	/* 0x1f3f: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1f43:
	/* 0x1f43: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f48:
	/* 0x1f48: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1f4d:
	/* 0x1f4d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f50:
	/* 0x1f50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f52:
	/* 0x1f52: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f57:
	/* 0x1f57: movzx  eax,WORD PTR [rcx+0x9e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_1f5e:
	/* 0x1f5e: movbe  WORD PTR [rcx+0x9e],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_1f67:
	/* 0x1f67: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f6c:
	/* 0x1f6c: mov    ebp,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_1f71:
	/* 0x1f71: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_1f77:
	/* 0x1f77: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1f79:
	/* 0x1f79: jns    1ccc <generic_retkprobe_event+0x1ccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 7372ULL;
	}
x86_l_1f7f:
	/* 0x1f7f: jmp    f9a <generic_retkprobe_event+0xf9a> */
	return 3994ULL;
x86_l_1f84:
	/* 0x1f84: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f89:
	/* 0x1f89: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1f90:
	/* 0x1f90: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1f95:
	/* 0x1f95: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1f9a:
	/* 0x1f9a: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_1f9f:
	/* 0x1f9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fa1:
	/* 0x1fa1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fa4:
	/* 0x1fa4: js     1cb2 <generic_retkprobe_event+0x1cb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7346ULL;
	}
x86_l_1faa:
	/* 0x1faa: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fae:
	/* 0x1fae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fb3:
	/* 0x1fb3: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1fb8:
	/* 0x1fb8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fbd:
	/* 0x1fbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fbf:
	/* 0x1fbf: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fc4:
	/* 0x1fc4: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1fcb:
	/* 0x1fcb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fd0:
	/* 0x1fd0: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_1fd5:
	/* 0x1fd5: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_1fda:
	/* 0x1fda: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fdf:
	/* 0x1fdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fe1:
	/* 0x1fe1: add    r13,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_1fe5:
	/* 0x1fe5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fea:
	/* 0x1fea: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1fef:
	/* 0x1fef: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ff4:
	/* 0x1ff4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1ff7:
	/* 0x1ff7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ff9:
	/* 0x1ff9: mov    ebp,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 80ULL);
x86_l_1ffe:
	/* 0x1ffe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2001:
	/* 0x2001: jne    1cb4 <generic_retkprobe_event+0x1cb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7348ULL;
	}
x86_l_2007:
	/* 0x2007: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2009:
	/* 0x2009: cmp    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_200e:
	/* 0x200e: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_2011:
	/* 0x2011: mov    DWORD PTR [r14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2014:
	/* 0x2014: jmp    1cb4 <generic_retkprobe_event+0x1cb4> */
	return 7348ULL;
x86_l_2019:
	/* 0x2019: add    r12,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_201d:
	/* 0x201d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2022:
	/* 0x2022: mov    esi,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 107ULL);
x86_l_2027:
	/* 0x2027: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_202a:
	/* 0x202a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_202c:
	/* 0x202c: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_202f:
	/* 0x202f: mov    al,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 107ULL);
x86_l_2031:
	/* 0x2031: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2033:
	/* 0x2033: js     2040 <generic_retkprobe_event+0x2040> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2040;
	}
x86_l_2035:
	/* 0x2035: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_203a:
	/* 0x203a: mov    BYTE PTR [rcx+0x9f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 159ULL);
x86_l_2040:
	/* 0x2040: mov    ebp,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 112ULL);
x86_l_2045:
	/* 0x2045: jmp    1cb4 <generic_retkprobe_event+0x1cb4> */
	return 7348ULL;
x86_l_204a:
	/* 0x204a: lea    rdx,[r12+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_204f:
	/* 0x204f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2054:
	/* 0x2054: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2057:
	/* 0x2057: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_205c:
	/* 0x205c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_205e:
	/* 0x205e: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2063:
	/* 0x2063: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2068:
	/* 0x2068: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_206b:
	/* 0x206b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2070:
	/* 0x2070: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2072:
	/* 0x2072: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2077:
	/* 0x2077: lea    rdi,[rbp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_207e:
	/* 0x207e: lea    r13,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2083:
	/* 0x2083: add    r12,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_2087:
	/* 0x2087: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_208c:
	/* 0x208c: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2091:
	/* 0x2091: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2094:
	/* 0x2094: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2096:
	/* 0x2096: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_2099:
	/* 0x2099: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_20a0:
	/* 0x20a0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20a5:
	/* 0x20a5: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_20aa:
	/* 0x20aa: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_20ad:
	/* 0x20ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20af:
	/* 0x20af: movzx  eax,WORD PTR [rbp+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_20b6:
	/* 0x20b6: movbe  WORD PTR [rbp+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_20bf:
	/* 0x20bf: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20c4:
	/* 0x20c4: mov    rax,QWORD PTR [rax+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_20cb:
	/* 0x20cb: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_20d0:
	/* 0x20d0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20d5:
	/* 0x20d5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_20dc:
	/* 0x20dc: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_20e1:
	/* 0x20e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20e3:
	/* 0x20e3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20e6:
	/* 0x20e6: je     2102 <generic_retkprobe_event+0x2102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2102;
	}
x86_l_20e8:
	/* 0x20e8: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20ea:
	/* 0x20ea: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20ef:
	/* 0x20ef: mov    DWORD PTR [r14+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20f3:
	/* 0x20f3: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20f7:
	/* 0x20f7: mov    QWORD PTR [r14+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20fb:
	/* 0x20fb: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_20fe:
	/* 0x20fe: mov    DWORD PTR [r14+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2102:
	/* 0x2102: mov    ebp,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_2107:
	/* 0x2107: jmp    1cb4 <generic_retkprobe_event+0x1cb4> */
	return 7348ULL;
x86_l_210c:
	/* 0x210c: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_210f:
	/* 0x210f: je     221a <generic_retkprobe_event+0x221a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_221a;
	}
x86_l_2115:
	/* 0x2115: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2118:
	/* 0x2118: je     2135 <generic_retkprobe_event+0x2135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2135;
	}
x86_l_211a:
	/* 0x211a: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_211f:
	/* 0x211f: jne    22d4 <generic_retkprobe_event+0x22d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22d4;
	}
x86_l_2125:
	/* 0x2125: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_212c:
	/* 0x212c: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2130:
	/* 0x2130: jmp    222b <generic_retkprobe_event+0x222b> */
	goto x86_l_222b;
x86_l_2135:
	/* 0x2135: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_213a:
	/* 0x213a: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2141:
	/* 0x2141: jmp    2226 <generic_retkprobe_event+0x2226> */
	goto x86_l_2226;
x86_l_2146:
	/* 0x2146: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2148:
	/* 0x2148: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_214d:
	/* 0x214d: cmp    QWORD PTR [rsp+0x88],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552259ULL);
x86_l_2156:
	/* 0x2156: jne    2165 <generic_retkprobe_event+0x2165> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2165;
	}
x86_l_2158:
	/* 0x2158: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_215b:
	/* 0x215b: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2160:
	/* 0x2160: jmp    3ee <generic_retkprobe_event+0x3ee> */
	return 1006ULL;
x86_l_2165:
	/* 0x2165: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_216d:
	/* 0x216d: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2171:
	/* 0x2171: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2177:
	/* 0x2177: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_217c:
	/* 0x217c: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2181:
	/* 0x2181: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2186:
	/* 0x2186: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2188:
	/* 0x2188: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_218d:
	/* 0x218d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_218f:
	/* 0x218f: js     2b28 <generic_retkprobe_event+0x2b28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11048ULL;
	}
x86_l_2195:
	/* 0x2195: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_219a:
	/* 0x219a: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_219f:
	/* 0x219f: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_21a2:
	/* 0x21a2: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_21a5:
	/* 0x21a5: cmovb  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_21a9:
	/* 0x21a9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21ac:
	/* 0x21ac: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_21af:
	/* 0x21af: cmovne rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_NE);
x86_l_21b3:
	/* 0x21b3: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_21b8:
	/* 0x21b8: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_21bf:
	/* 0x21bf: ja     2b28 <generic_retkprobe_event+0x2b28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11048ULL;
	}
x86_l_21c5:
	/* 0x21c5: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_21c8:
	/* 0x21c8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21cd:
	/* 0x21cd: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_21d2:
	/* 0x21d2: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21d7:
	/* 0x21d7: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_21dd:
	/* 0x21dd: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_21e0:
	/* 0x21e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21e5:
	/* 0x21e5: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_21ea:
	/* 0x21ea: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_21ec:
	/* 0x21ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21ee:
	/* 0x21ee: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_21f3:
	/* 0x21f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21f5:
	/* 0x21f5: js     2b28 <generic_retkprobe_event+0x2b28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11048ULL;
	}
x86_l_21fb:
	/* 0x21fb: add    r14,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_21fe:
	/* 0x21fe: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2204:
	/* 0x2204: je     2536 <generic_retkprobe_event+0x2536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9526ULL;
	}
x86_l_220a:
	/* 0x220a: sub    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 16ULL);
x86_l_220f:
	/* 0x220f: jne    253d <generic_retkprobe_event+0x253d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9533ULL;
	}
x86_l_2215:
	/* 0x2215: jmp    2158 <generic_retkprobe_event+0x2158> */
	goto x86_l_2158;
x86_l_221a:
	/* 0x221a: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_221f:
	/* 0x221f: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2226:
	/* 0x2226: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_222b:
	/* 0x222b: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2230:
	/* 0x2230: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2235:
	/* 0x2235: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_223a:
	/* 0x223a: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_223e:
	/* 0x223e: ja     29b8 <generic_retkprobe_event+0x29b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10680ULL;
	}
x86_l_2244:
	/* 0x2244: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_224e:
	/* 0x224e: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2252:
	/* 0x2252: jae    29b8 <generic_retkprobe_event+0x29b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10680ULL;
	}
x86_l_2258:
	/* 0x2258: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_225c:
	/* 0x225c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2261:
	/* 0x2261: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2266:
	/* 0x2266: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_226b:
	/* 0x226b: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_226e:
	/* 0x226e: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2273:
	/* 0x2273: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2275:
	/* 0x2275: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2278:
	/* 0x2278: js     27eb <generic_retkprobe_event+0x27eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10219ULL;
	}
x86_l_227e:
	/* 0x227e: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2283:
	/* 0x2283: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2286:
	/* 0x2286: jg     22a3 <generic_retkprobe_event+0x22a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_22a3;
	}
x86_l_2288:
	/* 0x2288: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_228a:
	/* 0x228a: je     22c1 <generic_retkprobe_event+0x22c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22c1;
	}
x86_l_228c:
	/* 0x228c: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_228f:
	/* 0x228f: je     22c1 <generic_retkprobe_event+0x22c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22c1;
	}
x86_l_2291:
	/* 0x2291: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2294:
	/* 0x2294: jne    22f1 <generic_retkprobe_event+0x22f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22f1;
	}
x86_l_2296:
	/* 0x2296: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_229d:
	/* 0x229d: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_22a1:
	/* 0x22a1: jmp    22f6 <generic_retkprobe_event+0x22f6> */
	goto x86_l_22f6;
x86_l_22a3:
	/* 0x22a3: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_22a6:
	/* 0x22a6: je     22de <generic_retkprobe_event+0x22de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22de;
	}
x86_l_22a8:
	/* 0x22a8: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_22ab:
	/* 0x22ab: je     22c1 <generic_retkprobe_event+0x22c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22c1;
	}
x86_l_22ad:
	/* 0x22ad: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_22b2:
	/* 0x22b2: jne    22f1 <generic_retkprobe_event+0x22f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22f1;
	}
x86_l_22b4:
	/* 0x22b4: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_22bb:
	/* 0x22bb: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_22bf:
	/* 0x22bf: jmp    22f6 <generic_retkprobe_event+0x22f6> */
	goto x86_l_22f6;
x86_l_22c1:
	/* 0x22c1: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_22c6:
	/* 0x22c6: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_22cd:
	/* 0x22cd: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_22d2:
	/* 0x22d2: jmp    22f6 <generic_retkprobe_event+0x22f6> */
	goto x86_l_22f6;
x86_l_22d4:
	/* 0x22d4: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_22d9:
	/* 0x22d9: jmp    222b <generic_retkprobe_event+0x222b> */
	goto x86_l_222b;
x86_l_22de:
	/* 0x22de: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_22e3:
	/* 0x22e3: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_22ea:
	/* 0x22ea: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_22ef:
	/* 0x22ef: jmp    22f6 <generic_retkprobe_event+0x22f6> */
	goto x86_l_22f6;
x86_l_22f1:
	/* 0x22f1: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_22f6:
	/* 0x22f6: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_22fb:
	/* 0x22fb: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2300:
	/* 0x2300: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2305:
	/* 0x2305: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2309:
	/* 0x2309: ja     29b8 <generic_retkprobe_event+0x29b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10680ULL;
	}
x86_l_230f:
	/* 0x230f: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2319:
	/* 0x2319: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_231d:
	/* 0x231d: jae    29b8 <generic_retkprobe_event+0x29b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10680ULL;
	}
x86_l_2323:
	/* 0x2323: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2327:
	/* 0x2327: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_232c:
	/* 0x232c: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2331:
	/* 0x2331: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2336:
	/* 0x2336: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2339:
	/* 0x2339: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_233e:
	/* 0x233e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2340:
	/* 0x2340: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2343:
	/* 0x2343: js     27eb <generic_retkprobe_event+0x27eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10219ULL;
	}
x86_l_2349:
	/* 0x2349: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_234e:
	/* 0x234e: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2351:
	/* 0x2351: jg     236e <generic_retkprobe_event+0x236e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_236e;
	}
x86_l_2353:
	/* 0x2353: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2355:
	/* 0x2355: je     238c <generic_retkprobe_event+0x238c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_238c;
	}
x86_l_2357:
	/* 0x2357: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_235a:
	/* 0x235a: je     238c <generic_retkprobe_event+0x238c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_238c;
	}
x86_l_235c:
	/* 0x235c: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_235f:
	/* 0x235f: jne    23b2 <generic_retkprobe_event+0x23b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23b2;
	}
x86_l_2361:
	/* 0x2361: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2368:
	/* 0x2368: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_236c:
	/* 0x236c: jmp    23b7 <generic_retkprobe_event+0x23b7> */
	goto x86_l_23b7;
x86_l_236e:
	/* 0x236e: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2371:
	/* 0x2371: je     239f <generic_retkprobe_event+0x239f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_239f;
	}
x86_l_2373:
	/* 0x2373: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2376:
	/* 0x2376: je     238c <generic_retkprobe_event+0x238c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_238c;
	}
x86_l_2378:
	/* 0x2378: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_237d:
	/* 0x237d: jne    23b2 <generic_retkprobe_event+0x23b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23b2;
	}
x86_l_237f:
	/* 0x237f: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2386:
	/* 0x2386: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_238a:
	/* 0x238a: jmp    23b7 <generic_retkprobe_event+0x23b7> */
	goto x86_l_23b7;
x86_l_238c:
	/* 0x238c: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2391:
	/* 0x2391: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2398:
	/* 0x2398: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_239d:
	/* 0x239d: jmp    23b7 <generic_retkprobe_event+0x23b7> */
	goto x86_l_23b7;
x86_l_239f:
	/* 0x239f: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_23a4:
	/* 0x23a4: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_23ab:
	/* 0x23ab: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_23b0:
	/* 0x23b0: jmp    23b7 <generic_retkprobe_event+0x23b7> */
	goto x86_l_23b7;
x86_l_23b2:
	/* 0x23b2: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_23b7:
	/* 0x23b7: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
	return 9148ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9148ULL: goto x86_l_23bc;
	case 9153ULL: goto x86_l_23c1;
	case 9158ULL: goto x86_l_23c6;
	case 9162ULL: goto x86_l_23ca;
	case 9168ULL: goto x86_l_23d0;
	case 9178ULL: goto x86_l_23da;
	case 9182ULL: goto x86_l_23de;
	case 9188ULL: goto x86_l_23e4;
	case 9192ULL: goto x86_l_23e8;
	case 9197ULL: goto x86_l_23ed;
	case 9202ULL: goto x86_l_23f2;
	case 9207ULL: goto x86_l_23f7;
	case 9210ULL: goto x86_l_23fa;
	case 9215ULL: goto x86_l_23ff;
	case 9217ULL: goto x86_l_2401;
	case 9220ULL: goto x86_l_2404;
	case 9226ULL: goto x86_l_240a;
	case 9231ULL: goto x86_l_240f;
	case 9234ULL: goto x86_l_2412;
	case 9236ULL: goto x86_l_2414;
	case 9238ULL: goto x86_l_2416;
	case 9240ULL: goto x86_l_2418;
	case 9243ULL: goto x86_l_241b;
	case 9245ULL: goto x86_l_241d;
	case 9248ULL: goto x86_l_2420;
	case 9250ULL: goto x86_l_2422;
	case 9257ULL: goto x86_l_2429;
	case 9261ULL: goto x86_l_242d;
	case 9263ULL: goto x86_l_242f;
	case 9266ULL: goto x86_l_2432;
	case 9268ULL: goto x86_l_2434;
	case 9271ULL: goto x86_l_2437;
	case 9273ULL: goto x86_l_2439;
	case 9278ULL: goto x86_l_243e;
	case 9280ULL: goto x86_l_2440;
	case 9287ULL: goto x86_l_2447;
	case 9291ULL: goto x86_l_244b;
	case 9293ULL: goto x86_l_244d;
	case 9298ULL: goto x86_l_2452;
	case 9305ULL: goto x86_l_2459;
	case 9310ULL: goto x86_l_245e;
	case 9312ULL: goto x86_l_2460;
	case 9317ULL: goto x86_l_2465;
	case 9324ULL: goto x86_l_246c;
	case 9329ULL: goto x86_l_2471;
	case 9331ULL: goto x86_l_2473;
	case 9336ULL: goto x86_l_2478;
	case 9341ULL: goto x86_l_247d;
	case 9346ULL: goto x86_l_2482;
	case 9351ULL: goto x86_l_2487;
	case 9355ULL: goto x86_l_248b;
	case 9361ULL: goto x86_l_2491;
	case 9371ULL: goto x86_l_249b;
	case 9375ULL: goto x86_l_249f;
	case 9381ULL: goto x86_l_24a5;
	case 9385ULL: goto x86_l_24a9;
	case 9390ULL: goto x86_l_24ae;
	case 9395ULL: goto x86_l_24b3;
	case 9400ULL: goto x86_l_24b8;
	case 9403ULL: goto x86_l_24bb;
	case 9408ULL: goto x86_l_24c0;
	case 9410ULL: goto x86_l_24c2;
	case 9413ULL: goto x86_l_24c5;
	case 9419ULL: goto x86_l_24cb;
	case 9424ULL: goto x86_l_24d0;
	case 9427ULL: goto x86_l_24d3;
	case 9429ULL: goto x86_l_24d5;
	case 9431ULL: goto x86_l_24d7;
	case 9433ULL: goto x86_l_24d9;
	case 9436ULL: goto x86_l_24dc;
	case 9438ULL: goto x86_l_24de;
	case 9441ULL: goto x86_l_24e1;
	case 9447ULL: goto x86_l_24e7;
	case 9454ULL: goto x86_l_24ee;
	case 9458ULL: goto x86_l_24f2;
	case 9463ULL: goto x86_l_24f7;
	case 9466ULL: goto x86_l_24fa;
	case 9472ULL: goto x86_l_2500;
	case 9475ULL: goto x86_l_2503;
	case 9477ULL: goto x86_l_2505;
	case 9482ULL: goto x86_l_250a;
	case 9488ULL: goto x86_l_2510;
	case 9495ULL: goto x86_l_2517;
	case 9499ULL: goto x86_l_251b;
	case 9504ULL: goto x86_l_2520;
	case 9509ULL: goto x86_l_2525;
	case 9516ULL: goto x86_l_252c;
	case 9521ULL: goto x86_l_2531;
	case 9526ULL: goto x86_l_2536;
	case 9528ULL: goto x86_l_2538;
	case 9533ULL: goto x86_l_253d;
	case 9542ULL: goto x86_l_2546;
	case 9548ULL: goto x86_l_254c;
	case 9556ULL: goto x86_l_2554;
	case 9560ULL: goto x86_l_2558;
	case 9566ULL: goto x86_l_255e;
	case 9571ULL: goto x86_l_2563;
	case 9576ULL: goto x86_l_2568;
	case 9581ULL: goto x86_l_256d;
	case 9583ULL: goto x86_l_256f;
	case 9588ULL: goto x86_l_2574;
	case 9590ULL: goto x86_l_2576;
	case 9596ULL: goto x86_l_257c;
	case 9601ULL: goto x86_l_2581;
	case 9606ULL: goto x86_l_2586;
	case 9609ULL: goto x86_l_2589;
	case 9612ULL: goto x86_l_258c;
	case 9616ULL: goto x86_l_2590;
	case 9619ULL: goto x86_l_2593;
	case 9622ULL: goto x86_l_2596;
	case 9626ULL: goto x86_l_259a;
	case 9631ULL: goto x86_l_259f;
	case 9636ULL: goto x86_l_25a4;
	case 9643ULL: goto x86_l_25ab;
	case 9649ULL: goto x86_l_25b1;
	case 9652ULL: goto x86_l_25b4;
	case 9657ULL: goto x86_l_25b9;
	case 9660ULL: goto x86_l_25bc;
	case 9666ULL: goto x86_l_25c2;
	case 9669ULL: goto x86_l_25c5;
	case 9674ULL: goto x86_l_25ca;
	case 9679ULL: goto x86_l_25cf;
	case 9684ULL: goto x86_l_25d4;
	case 9686ULL: goto x86_l_25d6;
	case 9691ULL: goto x86_l_25db;
	case 9693ULL: goto x86_l_25dd;
	case 9699ULL: goto x86_l_25e3;
	case 9704ULL: goto x86_l_25e8;
	case 9710ULL: goto x86_l_25ee;
	case 9716ULL: goto x86_l_25f4;
	case 9721ULL: goto x86_l_25f9;
	case 9727ULL: goto x86_l_25ff;
	case 9732ULL: goto x86_l_2604;
	case 9737ULL: goto x86_l_2609;
	case 9744ULL: goto x86_l_2610;
	case 9749ULL: goto x86_l_2615;
	case 9751ULL: goto x86_l_2617;
	case 9756ULL: goto x86_l_261c;
	case 9761ULL: goto x86_l_2621;
	case 9766ULL: goto x86_l_2626;
	case 9771ULL: goto x86_l_262b;
	case 9775ULL: goto x86_l_262f;
	case 9781ULL: goto x86_l_2635;
	case 9791ULL: goto x86_l_263f;
	case 9795ULL: goto x86_l_2643;
	case 9801ULL: goto x86_l_2649;
	case 9805ULL: goto x86_l_264d;
	case 9810ULL: goto x86_l_2652;
	case 9815ULL: goto x86_l_2657;
	case 9820ULL: goto x86_l_265c;
	case 9823ULL: goto x86_l_265f;
	case 9828ULL: goto x86_l_2664;
	case 9830ULL: goto x86_l_2666;
	case 9833ULL: goto x86_l_2669;
	case 9839ULL: goto x86_l_266f;
	case 9844ULL: goto x86_l_2674;
	case 9847ULL: goto x86_l_2677;
	case 9849ULL: goto x86_l_2679;
	case 9851ULL: goto x86_l_267b;
	case 9853ULL: goto x86_l_267d;
	case 9856ULL: goto x86_l_2680;
	case 9858ULL: goto x86_l_2682;
	case 9861ULL: goto x86_l_2685;
	case 9863ULL: goto x86_l_2687;
	case 9870ULL: goto x86_l_268e;
	case 9874ULL: goto x86_l_2692;
	case 9876ULL: goto x86_l_2694;
	case 9879ULL: goto x86_l_2697;
	case 9881ULL: goto x86_l_2699;
	case 9884ULL: goto x86_l_269c;
	case 9886ULL: goto x86_l_269e;
	case 9891ULL: goto x86_l_26a3;
	case 9893ULL: goto x86_l_26a5;
	case 9900ULL: goto x86_l_26ac;
	case 9904ULL: goto x86_l_26b0;
	case 9906ULL: goto x86_l_26b2;
	case 9911ULL: goto x86_l_26b7;
	case 9918ULL: goto x86_l_26be;
	case 9923ULL: goto x86_l_26c3;
	case 9925ULL: goto x86_l_26c5;
	case 9930ULL: goto x86_l_26ca;
	case 9937ULL: goto x86_l_26d1;
	case 9942ULL: goto x86_l_26d6;
	case 9944ULL: goto x86_l_26d8;
	case 9949ULL: goto x86_l_26dd;
	case 9954ULL: goto x86_l_26e2;
	case 9959ULL: goto x86_l_26e7;
	case 9964ULL: goto x86_l_26ec;
	case 9968ULL: goto x86_l_26f0;
	case 9974ULL: goto x86_l_26f6;
	case 9984ULL: goto x86_l_2700;
	case 9988ULL: goto x86_l_2704;
	case 9994ULL: goto x86_l_270a;
	case 9998ULL: goto x86_l_270e;
	case 10003ULL: goto x86_l_2713;
	case 10008ULL: goto x86_l_2718;
	case 10013ULL: goto x86_l_271d;
	case 10016ULL: goto x86_l_2720;
	case 10021ULL: goto x86_l_2725;
	case 10023ULL: goto x86_l_2727;
	case 10026ULL: goto x86_l_272a;
	case 10032ULL: goto x86_l_2730;
	case 10037ULL: goto x86_l_2735;
	case 10040ULL: goto x86_l_2738;
	case 10042ULL: goto x86_l_273a;
	case 10044ULL: goto x86_l_273c;
	case 10046ULL: goto x86_l_273e;
	case 10049ULL: goto x86_l_2741;
	case 10051ULL: goto x86_l_2743;
	case 10054ULL: goto x86_l_2746;
	case 10056ULL: goto x86_l_2748;
	case 10063ULL: goto x86_l_274f;
	case 10067ULL: goto x86_l_2753;
	case 10069ULL: goto x86_l_2755;
	case 10072ULL: goto x86_l_2758;
	case 10074ULL: goto x86_l_275a;
	case 10077ULL: goto x86_l_275d;
	case 10079ULL: goto x86_l_275f;
	case 10084ULL: goto x86_l_2764;
	case 10086ULL: goto x86_l_2766;
	case 10093ULL: goto x86_l_276d;
	case 10097ULL: goto x86_l_2771;
	case 10099ULL: goto x86_l_2773;
	case 10104ULL: goto x86_l_2778;
	case 10111ULL: goto x86_l_277f;
	case 10116ULL: goto x86_l_2784;
	case 10118ULL: goto x86_l_2786;
	case 10123ULL: goto x86_l_278b;
	case 10130ULL: goto x86_l_2792;
	case 10135ULL: goto x86_l_2797;
	case 10137ULL: goto x86_l_2799;
	case 10142ULL: goto x86_l_279e;
	case 10147ULL: goto x86_l_27a3;
	case 10152ULL: goto x86_l_27a8;
	case 10157ULL: goto x86_l_27ad;
	case 10161ULL: goto x86_l_27b1;
	case 10167ULL: goto x86_l_27b7;
	case 10177ULL: goto x86_l_27c1;
	case 10181ULL: goto x86_l_27c5;
	case 10187ULL: goto x86_l_27cb;
	case 10191ULL: goto x86_l_27cf;
	case 10196ULL: goto x86_l_27d4;
	case 10201ULL: goto x86_l_27d9;
	case 10206ULL: goto x86_l_27de;
	case 10209ULL: goto x86_l_27e1;
	case 10212ULL: goto x86_l_27e4;
	case 10217ULL: goto x86_l_27e9;
	case 10219ULL: goto x86_l_27eb;
	case 10221ULL: goto x86_l_27ed;
	case 10228ULL: goto x86_l_27f4;
	case 10231ULL: goto x86_l_27f7;
	case 10236ULL: goto x86_l_27fc;
	case 10244ULL: goto x86_l_2804;
	case 10254ULL: goto x86_l_280e;
	case 10259ULL: goto x86_l_2813;
	case 10264ULL: goto x86_l_2818;
	case 10269ULL: goto x86_l_281d;
	case 10274ULL: goto x86_l_2822;
	case 10276ULL: goto x86_l_2824;
	case 10283ULL: goto x86_l_282b;
	case 10287ULL: goto x86_l_282f;
	case 10292ULL: goto x86_l_2834;
	case 10297ULL: goto x86_l_2839;
	case 10300ULL: goto x86_l_283c;
	case 10302ULL: goto x86_l_283e;
	case 10310ULL: goto x86_l_2846;
	case 10313ULL: goto x86_l_2849;
	case 10315ULL: goto x86_l_284b;
	case 10318ULL: goto x86_l_284e;
	case 10324ULL: goto x86_l_2854;
	case 10329ULL: goto x86_l_2859;
	case 10338ULL: goto x86_l_2862;
	case 10342ULL: goto x86_l_2866;
	case 10347ULL: goto x86_l_286b;
	case 10354ULL: goto x86_l_2872;
	case 10359ULL: goto x86_l_2877;
	case 10364ULL: goto x86_l_287c;
	case 10366ULL: goto x86_l_287e;
	case 10373ULL: goto x86_l_2885;
	case 10377ULL: goto x86_l_2889;
	case 10381ULL: goto x86_l_288d;
	case 10386ULL: goto x86_l_2892;
	case 10388ULL: goto x86_l_2894;
	case 10393ULL: goto x86_l_2899;
	case 10402ULL: goto x86_l_28a2;
	case 10406ULL: goto x86_l_28a6;
	case 10411ULL: goto x86_l_28ab;
	case 10418ULL: goto x86_l_28b2;
	case 10423ULL: goto x86_l_28b7;
	case 10428ULL: goto x86_l_28bc;
	case 10430ULL: goto x86_l_28be;
	case 10437ULL: goto x86_l_28c5;
	case 10441ULL: goto x86_l_28c9;
	case 10445ULL: goto x86_l_28cd;
	case 10450ULL: goto x86_l_28d2;
	case 10455ULL: goto x86_l_28d7;
	case 10457ULL: goto x86_l_28d9;
	case 10459ULL: goto x86_l_28db;
	case 10464ULL: goto x86_l_28e0;
	case 10474ULL: goto x86_l_28ea;
	case 10479ULL: goto x86_l_28ef;
	case 10486ULL: goto x86_l_28f6;
	case 10493ULL: goto x86_l_28fd;
	case 10502ULL: goto x86_l_2906;
	case 10511ULL: goto x86_l_290f;
	case 10518ULL: goto x86_l_2916;
	case 10523ULL: goto x86_l_291b;
	case 10528ULL: goto x86_l_2920;
	case 10533ULL: goto x86_l_2925;
	case 10536ULL: goto x86_l_2928;
	case 10538ULL: goto x86_l_292a;
	case 10544ULL: goto x86_l_2930;
	case 10546ULL: goto x86_l_2932;
	case 10551ULL: goto x86_l_2937;
	case 10556ULL: goto x86_l_293c;
	case 10560ULL: goto x86_l_2940;
	case 10568ULL: goto x86_l_2948;
	case 10573ULL: goto x86_l_294d;
	case 10575ULL: goto x86_l_294f;
	case 10580ULL: goto x86_l_2954;
	case 10588ULL: goto x86_l_295c;
	case 10592ULL: goto x86_l_2960;
	case 10597ULL: goto x86_l_2965;
	case 10604ULL: goto x86_l_296c;
	case 10609ULL: goto x86_l_2971;
	case 10614ULL: goto x86_l_2976;
	case 10616ULL: goto x86_l_2978;
	case 10619ULL: goto x86_l_297b;
	case 10626ULL: goto x86_l_2982;
	case 10630ULL: goto x86_l_2986;
	case 10634ULL: goto x86_l_298a;
	case 10639ULL: goto x86_l_298f;
	case 10644ULL: goto x86_l_2994;
	case 10646ULL: goto x86_l_2996;
	case 10651ULL: goto x86_l_299b;
	case 10656ULL: goto x86_l_29a0;
	case 10661ULL: goto x86_l_29a5;
	case 10667ULL: goto x86_l_29ab;
	case 10669ULL: goto x86_l_29ad;
	case 10675ULL: goto x86_l_29b3;
	case 10680ULL: goto x86_l_29b8;
	case 10688ULL: goto x86_l_29c0;
	case 10693ULL: goto x86_l_29c5;
	case 10695ULL: goto x86_l_29c7;
	case 10700ULL: goto x86_l_29cc;
	case 10709ULL: goto x86_l_29d5;
	case 10715ULL: goto x86_l_29db;
	case 10723ULL: goto x86_l_29e3;
	case 10727ULL: goto x86_l_29e7;
	case 10733ULL: goto x86_l_29ed;
	case 10738ULL: goto x86_l_29f2;
	case 10743ULL: goto x86_l_29f7;
	case 10748ULL: goto x86_l_29fc;
	case 10750ULL: goto x86_l_29fe;
	case 10755ULL: goto x86_l_2a03;
	case 10757ULL: goto x86_l_2a05;
	case 10763ULL: goto x86_l_2a0b;
	case 10768ULL: goto x86_l_2a10;
	case 10773ULL: goto x86_l_2a15;
	case 10776ULL: goto x86_l_2a18;
	case 10779ULL: goto x86_l_2a1b;
	case 10783ULL: goto x86_l_2a1f;
	case 10786ULL: goto x86_l_2a22;
	case 10790ULL: goto x86_l_2a26;
	case 10795ULL: goto x86_l_2a2b;
	case 10800ULL: goto x86_l_2a30;
	case 10807ULL: goto x86_l_2a37;
	case 10813ULL: goto x86_l_2a3d;
	case 10818ULL: goto x86_l_2a42;
	case 10821ULL: goto x86_l_2a45;
	case 10826ULL: goto x86_l_2a4a;
	case 10832ULL: goto x86_l_2a50;
	case 10835ULL: goto x86_l_2a53;
	case 10840ULL: goto x86_l_2a58;
	case 10845ULL: goto x86_l_2a5d;
	case 10850ULL: goto x86_l_2a62;
	case 10852ULL: goto x86_l_2a64;
	case 10857ULL: goto x86_l_2a69;
	case 10859ULL: goto x86_l_2a6b;
	case 10865ULL: goto x86_l_2a71;
	case 10870ULL: goto x86_l_2a76;
	case 10876ULL: goto x86_l_2a7c;
	case 10878ULL: goto x86_l_2a7e;
	case 10883ULL: goto x86_l_2a83;
	default: return 0xffffffffffffffffULL;
	}
x86_l_23bc:
	/* 0x23bc: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23c1:
	/* 0x23c1: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_23c6:
	/* 0x23c6: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_23ca:
	/* 0x23ca: ja     29b8 <generic_retkprobe_event+0x29b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29b8;
	}
x86_l_23d0:
	/* 0x23d0: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_23da:
	/* 0x23da: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_23de:
	/* 0x23de: jae    29b8 <generic_retkprobe_event+0x29b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_29b8;
	}
x86_l_23e4:
	/* 0x23e4: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_23e8:
	/* 0x23e8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23ed:
	/* 0x23ed: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_23f2:
	/* 0x23f2: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_23f7:
	/* 0x23f7: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_23fa:
	/* 0x23fa: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_23ff:
	/* 0x23ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2401:
	/* 0x2401: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2404:
	/* 0x2404: js     27eb <generic_retkprobe_event+0x27eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_27eb;
	}
x86_l_240a:
	/* 0x240a: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_240f:
	/* 0x240f: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2412:
	/* 0x2412: jg     242f <generic_retkprobe_event+0x242f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_242f;
	}
x86_l_2414:
	/* 0x2414: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2416:
	/* 0x2416: je     244d <generic_retkprobe_event+0x244d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_244d;
	}
x86_l_2418:
	/* 0x2418: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_241b:
	/* 0x241b: je     244d <generic_retkprobe_event+0x244d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_244d;
	}
x86_l_241d:
	/* 0x241d: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2420:
	/* 0x2420: jne    2473 <generic_retkprobe_event+0x2473> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2473;
	}
x86_l_2422:
	/* 0x2422: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2429:
	/* 0x2429: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_242d:
	/* 0x242d: jmp    2478 <generic_retkprobe_event+0x2478> */
	goto x86_l_2478;
x86_l_242f:
	/* 0x242f: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2432:
	/* 0x2432: je     2460 <generic_retkprobe_event+0x2460> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2460;
	}
x86_l_2434:
	/* 0x2434: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2437:
	/* 0x2437: je     244d <generic_retkprobe_event+0x244d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_244d;
	}
x86_l_2439:
	/* 0x2439: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_243e:
	/* 0x243e: jne    2473 <generic_retkprobe_event+0x2473> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2473;
	}
x86_l_2440:
	/* 0x2440: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2447:
	/* 0x2447: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_244b:
	/* 0x244b: jmp    2478 <generic_retkprobe_event+0x2478> */
	goto x86_l_2478;
x86_l_244d:
	/* 0x244d: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2452:
	/* 0x2452: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2459:
	/* 0x2459: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_245e:
	/* 0x245e: jmp    2478 <generic_retkprobe_event+0x2478> */
	goto x86_l_2478;
x86_l_2460:
	/* 0x2460: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2465:
	/* 0x2465: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_246c:
	/* 0x246c: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2471:
	/* 0x2471: jmp    2478 <generic_retkprobe_event+0x2478> */
	goto x86_l_2478;
x86_l_2473:
	/* 0x2473: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2478:
	/* 0x2478: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_247d:
	/* 0x247d: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2482:
	/* 0x2482: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2487:
	/* 0x2487: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_248b:
	/* 0x248b: ja     29b8 <generic_retkprobe_event+0x29b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29b8;
	}
x86_l_2491:
	/* 0x2491: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_249b:
	/* 0x249b: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_249f:
	/* 0x249f: jae    29b8 <generic_retkprobe_event+0x29b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_29b8;
	}
x86_l_24a5:
	/* 0x24a5: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_24a9:
	/* 0x24a9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24ae:
	/* 0x24ae: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_24b3:
	/* 0x24b3: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_24b8:
	/* 0x24b8: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_24bb:
	/* 0x24bb: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_24c0:
	/* 0x24c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24c2:
	/* 0x24c2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24c5:
	/* 0x24c5: js     27eb <generic_retkprobe_event+0x27eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_27eb;
	}
x86_l_24cb:
	/* 0x24cb: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_24d0:
	/* 0x24d0: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_24d3:
	/* 0x24d3: jg     24f7 <generic_retkprobe_event+0x24f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_24f7;
	}
x86_l_24d5:
	/* 0x24d5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24d7:
	/* 0x24d7: je     2520 <generic_retkprobe_event+0x2520> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2520;
	}
x86_l_24d9:
	/* 0x24d9: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_24dc:
	/* 0x24dc: je     2520 <generic_retkprobe_event+0x2520> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2520;
	}
x86_l_24de:
	/* 0x24de: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_24e1:
	/* 0x24e1: jne    2617 <generic_retkprobe_event+0x2617> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2617;
	}
x86_l_24e7:
	/* 0x24e7: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_24ee:
	/* 0x24ee: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_24f2:
	/* 0x24f2: jmp    261c <generic_retkprobe_event+0x261c> */
	goto x86_l_261c;
x86_l_24f7:
	/* 0x24f7: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_24fa:
	/* 0x24fa: je     2604 <generic_retkprobe_event+0x2604> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2604;
	}
x86_l_2500:
	/* 0x2500: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2503:
	/* 0x2503: je     2520 <generic_retkprobe_event+0x2520> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2520;
	}
x86_l_2505:
	/* 0x2505: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_250a:
	/* 0x250a: jne    2617 <generic_retkprobe_event+0x2617> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2617;
	}
x86_l_2510:
	/* 0x2510: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2517:
	/* 0x2517: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_251b:
	/* 0x251b: jmp    261c <generic_retkprobe_event+0x261c> */
	goto x86_l_261c;
x86_l_2520:
	/* 0x2520: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2525:
	/* 0x2525: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_252c:
	/* 0x252c: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2531:
	/* 0x2531: jmp    261c <generic_retkprobe_event+0x261c> */
	goto x86_l_261c;
x86_l_2536:
	/* 0x2536: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2538:
	/* 0x2538: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_253d:
	/* 0x253d: cmp    QWORD PTR [rsp+0x88],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552261ULL);
x86_l_2546:
	/* 0x2546: jb     2158 <generic_retkprobe_event+0x2158> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8536ULL;
	}
x86_l_254c:
	/* 0x254c: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2554:
	/* 0x2554: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2558:
	/* 0x2558: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_255e:
	/* 0x255e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2563:
	/* 0x2563: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2568:
	/* 0x2568: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_256d:
	/* 0x256d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_256f:
	/* 0x256f: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2574:
	/* 0x2574: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2576:
	/* 0x2576: js     2b28 <generic_retkprobe_event+0x2b28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11048ULL;
	}
x86_l_257c:
	/* 0x257c: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2581:
	/* 0x2581: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2586:
	/* 0x2586: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2589:
	/* 0x2589: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_258c:
	/* 0x258c: cmovb  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_2590:
	/* 0x2590: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2593:
	/* 0x2593: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_2596:
	/* 0x2596: cmovne rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_NE);
x86_l_259a:
	/* 0x259a: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_259f:
	/* 0x259f: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25a4:
	/* 0x25a4: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_25ab:
	/* 0x25ab: ja     2b28 <generic_retkprobe_event+0x2b28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11048ULL;
	}
x86_l_25b1:
	/* 0x25b1: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_25b4:
	/* 0x25b4: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_25b9:
	/* 0x25b9: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_25bc:
	/* 0x25bc: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_25c2:
	/* 0x25c2: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_25c5:
	/* 0x25c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25ca:
	/* 0x25ca: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_25cf:
	/* 0x25cf: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25d4:
	/* 0x25d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25d6:
	/* 0x25d6: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_25db:
	/* 0x25db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25dd:
	/* 0x25dd: js     2b28 <generic_retkprobe_event+0x2b28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11048ULL;
	}
x86_l_25e3:
	/* 0x25e3: add    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_25e8:
	/* 0x25e8: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_25ee:
	/* 0x25ee: je     29c5 <generic_retkprobe_event+0x29c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29c5;
	}
x86_l_25f4:
	/* 0x25f4: sub    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 16ULL);
x86_l_25f9:
	/* 0x25f9: jne    29cc <generic_retkprobe_event+0x29cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29cc;
	}
x86_l_25ff:
	/* 0x25ff: jmp    2158 <generic_retkprobe_event+0x2158> */
	return 8536ULL;
x86_l_2604:
	/* 0x2604: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2609:
	/* 0x2609: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2610:
	/* 0x2610: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2615:
	/* 0x2615: jmp    261c <generic_retkprobe_event+0x261c> */
	goto x86_l_261c;
x86_l_2617:
	/* 0x2617: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_261c:
	/* 0x261c: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2621:
	/* 0x2621: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2626:
	/* 0x2626: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_262b:
	/* 0x262b: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_262f:
	/* 0x262f: ja     29b8 <generic_retkprobe_event+0x29b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29b8;
	}
x86_l_2635:
	/* 0x2635: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_263f:
	/* 0x263f: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2643:
	/* 0x2643: jae    29b8 <generic_retkprobe_event+0x29b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_29b8;
	}
x86_l_2649:
	/* 0x2649: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_264d:
	/* 0x264d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2652:
	/* 0x2652: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2657:
	/* 0x2657: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_265c:
	/* 0x265c: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_265f:
	/* 0x265f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2664:
	/* 0x2664: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2666:
	/* 0x2666: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2669:
	/* 0x2669: js     27eb <generic_retkprobe_event+0x27eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_27eb;
	}
x86_l_266f:
	/* 0x266f: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2674:
	/* 0x2674: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2677:
	/* 0x2677: jg     2694 <generic_retkprobe_event+0x2694> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2694;
	}
x86_l_2679:
	/* 0x2679: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_267b:
	/* 0x267b: je     26b2 <generic_retkprobe_event+0x26b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26b2;
	}
x86_l_267d:
	/* 0x267d: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2680:
	/* 0x2680: je     26b2 <generic_retkprobe_event+0x26b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26b2;
	}
x86_l_2682:
	/* 0x2682: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2685:
	/* 0x2685: jne    26d8 <generic_retkprobe_event+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_26d8;
	}
x86_l_2687:
	/* 0x2687: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_268e:
	/* 0x268e: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2692:
	/* 0x2692: jmp    26dd <generic_retkprobe_event+0x26dd> */
	goto x86_l_26dd;
x86_l_2694:
	/* 0x2694: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2697:
	/* 0x2697: je     26c5 <generic_retkprobe_event+0x26c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26c5;
	}
x86_l_2699:
	/* 0x2699: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_269c:
	/* 0x269c: je     26b2 <generic_retkprobe_event+0x26b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26b2;
	}
x86_l_269e:
	/* 0x269e: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_26a3:
	/* 0x26a3: jne    26d8 <generic_retkprobe_event+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_26d8;
	}
x86_l_26a5:
	/* 0x26a5: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_26ac:
	/* 0x26ac: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_26b0:
	/* 0x26b0: jmp    26dd <generic_retkprobe_event+0x26dd> */
	goto x86_l_26dd;
x86_l_26b2:
	/* 0x26b2: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_26b7:
	/* 0x26b7: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_26be:
	/* 0x26be: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_26c3:
	/* 0x26c3: jmp    26dd <generic_retkprobe_event+0x26dd> */
	goto x86_l_26dd;
x86_l_26c5:
	/* 0x26c5: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_26ca:
	/* 0x26ca: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_26d1:
	/* 0x26d1: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_26d6:
	/* 0x26d6: jmp    26dd <generic_retkprobe_event+0x26dd> */
	goto x86_l_26dd;
x86_l_26d8:
	/* 0x26d8: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_26dd:
	/* 0x26dd: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_26e2:
	/* 0x26e2: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26e7:
	/* 0x26e7: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_26ec:
	/* 0x26ec: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_26f0:
	/* 0x26f0: ja     29b8 <generic_retkprobe_event+0x29b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29b8;
	}
x86_l_26f6:
	/* 0x26f6: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2700:
	/* 0x2700: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2704:
	/* 0x2704: jae    29b8 <generic_retkprobe_event+0x29b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_29b8;
	}
x86_l_270a:
	/* 0x270a: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_270e:
	/* 0x270e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2713:
	/* 0x2713: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2718:
	/* 0x2718: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_271d:
	/* 0x271d: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2720:
	/* 0x2720: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2725:
	/* 0x2725: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2727:
	/* 0x2727: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_272a:
	/* 0x272a: js     27eb <generic_retkprobe_event+0x27eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_27eb;
	}
x86_l_2730:
	/* 0x2730: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2735:
	/* 0x2735: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2738:
	/* 0x2738: jg     2755 <generic_retkprobe_event+0x2755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2755;
	}
x86_l_273a:
	/* 0x273a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_273c:
	/* 0x273c: je     2773 <generic_retkprobe_event+0x2773> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2773;
	}
x86_l_273e:
	/* 0x273e: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2741:
	/* 0x2741: je     2773 <generic_retkprobe_event+0x2773> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2773;
	}
x86_l_2743:
	/* 0x2743: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2746:
	/* 0x2746: jne    2799 <generic_retkprobe_event+0x2799> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2799;
	}
x86_l_2748:
	/* 0x2748: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_274f:
	/* 0x274f: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2753:
	/* 0x2753: jmp    279e <generic_retkprobe_event+0x279e> */
	goto x86_l_279e;
x86_l_2755:
	/* 0x2755: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2758:
	/* 0x2758: je     2786 <generic_retkprobe_event+0x2786> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2786;
	}
x86_l_275a:
	/* 0x275a: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_275d:
	/* 0x275d: je     2773 <generic_retkprobe_event+0x2773> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2773;
	}
x86_l_275f:
	/* 0x275f: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2764:
	/* 0x2764: jne    2799 <generic_retkprobe_event+0x2799> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2799;
	}
x86_l_2766:
	/* 0x2766: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_276d:
	/* 0x276d: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2771:
	/* 0x2771: jmp    279e <generic_retkprobe_event+0x279e> */
	goto x86_l_279e;
x86_l_2773:
	/* 0x2773: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2778:
	/* 0x2778: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_277f:
	/* 0x277f: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2784:
	/* 0x2784: jmp    279e <generic_retkprobe_event+0x279e> */
	goto x86_l_279e;
x86_l_2786:
	/* 0x2786: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_278b:
	/* 0x278b: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2792:
	/* 0x2792: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2797:
	/* 0x2797: jmp    279e <generic_retkprobe_event+0x279e> */
	goto x86_l_279e;
x86_l_2799:
	/* 0x2799: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_279e:
	/* 0x279e: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_27a3:
	/* 0x27a3: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27a8:
	/* 0x27a8: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_27ad:
	/* 0x27ad: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_27b1:
	/* 0x27b1: ja     29b8 <generic_retkprobe_event+0x29b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_29b8;
	}
x86_l_27b7:
	/* 0x27b7: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_27c1:
	/* 0x27c1: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_27c5:
	/* 0x27c5: jae    29b8 <generic_retkprobe_event+0x29b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_29b8;
	}
x86_l_27cb:
	/* 0x27cb: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_27cf:
	/* 0x27cf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27d4:
	/* 0x27d4: movzx  ecx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27d9:
	/* 0x27d9: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27de:
	/* 0x27de: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_27e1:
	/* 0x27e1: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_27e4:
	/* 0x27e4: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_27e9:
	/* 0x27e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27eb:
	/* 0x27eb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27ed:
	/* 0x27ed: mov    BYTE PTR [rsp+0xc0],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_27f4:
	/* 0x27f4: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_27f7:
	/* 0x27f7: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27fc:
	/* 0x27fc: mov    WORD PTR [r14+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2804:
	/* 0x2804: mov    WORD PTR [r14+0xc2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655434ULL);
x86_l_280e:
	/* 0x280e: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2813:
	/* 0x2813: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2818:
	/* 0x2818: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_281d:
	/* 0x281d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2822:
	/* 0x2822: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2824:
	/* 0x2824: lea    rdi,[r14+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_282b:
	/* 0x282b: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_282f:
	/* 0x282f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2834:
	/* 0x2834: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2839:
	/* 0x2839: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_283c:
	/* 0x283c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_283e:
	/* 0x283e: movzx  eax,BYTE PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 192ULL);
x86_l_2846:
	/* 0x2846: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2849:
	/* 0x2849: je     2894 <generic_retkprobe_event+0x2894> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2894;
	}
x86_l_284b:
	/* 0x284b: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_284e:
	/* 0x284e: jne    28db <generic_retkprobe_event+0x28db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28db;
	}
x86_l_2854:
	/* 0x2854: mov    r14,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2859:
	/* 0x2859: movzx  r12d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_2862:
	/* 0x2862: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2866:
	/* 0x2866: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_286b:
	/* 0x286b: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2872:
	/* 0x2872: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2877:
	/* 0x2877: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_287c:
	/* 0x287c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_287e:
	/* 0x287e: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_2885:
	/* 0x2885: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2889:
	/* 0x2889: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_288d:
	/* 0x288d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2892:
	/* 0x2892: jmp    28d2 <generic_retkprobe_event+0x28d2> */
	goto x86_l_28d2;
x86_l_2894:
	/* 0x2894: mov    r14,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2899:
	/* 0x2899: movzx  r12d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_28a2:
	/* 0x28a2: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_28a6:
	/* 0x28a6: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28ab:
	/* 0x28ab: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_28b2:
	/* 0x28b2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28b7:
	/* 0x28b7: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_28bc:
	/* 0x28bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28be:
	/* 0x28be: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_28c5:
	/* 0x28c5: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_28c9:
	/* 0x28c9: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_28cd:
	/* 0x28cd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28d2:
	/* 0x28d2: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_28d7:
	/* 0x28d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28d9:
	/* 0x28d9: jmp    28ea <generic_retkprobe_event+0x28ea> */
	goto x86_l_28ea;
x86_l_28db:
	/* 0x28db: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28e0:
	/* 0x28e0: mov    DWORD PTR [rax+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_28ea:
	/* 0x28ea: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28ef:
	/* 0x28ef: movzx  ecx,WORD PTR [rax+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_28f6:
	/* 0x28f6: movzx  edx,WORD PTR [rax+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_28fd:
	/* 0x28fd: movbe  WORD PTR [rax+0xbc],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_2906:
	/* 0x2906: movbe  WORD PTR [rax+0xbe],dx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_290f:
	/* 0x290f: add    rbp,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_2916:
	/* 0x2916: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_291b:
	/* 0x291b: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2920:
	/* 0x2920: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2925:
	/* 0x2925: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2928:
	/* 0x2928: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_292a:
	/* 0x292a: cmp    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2930:
	/* 0x2930: je     2996 <generic_retkprobe_event+0x2996> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2996;
	}
x86_l_2932:
	/* 0x2932: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2937:
	/* 0x2937: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_293c:
	/* 0x293c: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_2940:
	/* 0x2940: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2948:
	/* 0x2948: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_294d:
	/* 0x294d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_294f:
	/* 0x294f: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2954:
	/* 0x2954: mov    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_295c:
	/* 0x295c: lea    rdx,[r14+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_2960:
	/* 0x2960: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2965:
	/* 0x2965: lea    rdi,[r13+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_296c:
	/* 0x296c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2971:
	/* 0x2971: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2976:
	/* 0x2976: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2978:
	/* 0x2978: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_297b:
	/* 0x297b: add    rdi,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_2982:
	/* 0x2982: lea    rdx,[r14+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_2986:
	/* 0x2986: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_298a:
	/* 0x298a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_298f:
	/* 0x298f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2994:
	/* 0x2994: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2996:
	/* 0x2996: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_299b:
	/* 0x299b: mov    ebp,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 64ULL);
x86_l_29a0:
	/* 0x29a0: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29a5:
	/* 0x29a5: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_29ab:
	/* 0x29ab: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_29ad:
	/* 0x29ad: jns    1ccc <generic_retkprobe_event+0x1ccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 7372ULL;
	}
x86_l_29b3:
	/* 0x29b3: jmp    f9a <generic_retkprobe_event+0xf9a> */
	return 3994ULL;
x86_l_29b8:
	/* 0x29b8: mov    WORD PTR [rsp+0xc8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_29c0:
	/* 0x29c0: jmp    27ed <generic_retkprobe_event+0x27ed> */
	goto x86_l_27ed;
x86_l_29c5:
	/* 0x29c5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29c7:
	/* 0x29c7: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29cc:
	/* 0x29cc: cmp    QWORD PTR [rsp+0x88],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552261ULL);
x86_l_29d5:
	/* 0x29d5: je     2158 <generic_retkprobe_event+0x2158> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8536ULL;
	}
x86_l_29db:
	/* 0x29db: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_29e3:
	/* 0x29e3: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_29e7:
	/* 0x29e7: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_29ed:
	/* 0x29ed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29f2:
	/* 0x29f2: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_29f7:
	/* 0x29f7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_29fc:
	/* 0x29fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29fe:
	/* 0x29fe: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2a03:
	/* 0x2a03: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a05:
	/* 0x2a05: js     2b28 <generic_retkprobe_event+0x2b28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11048ULL;
	}
x86_l_2a0b:
	/* 0x2a0b: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a10:
	/* 0x2a10: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a15:
	/* 0x2a15: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2a18:
	/* 0x2a18: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2a1b:
	/* 0x2a1b: cmovb  r12,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_2a1f:
	/* 0x2a1f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a22:
	/* 0x2a22: cmovne rdx,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_2a26:
	/* 0x2a26: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2a2b:
	/* 0x2a2b: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a30:
	/* 0x2a30: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_2a37:
	/* 0x2a37: ja     2b28 <generic_retkprobe_event+0x2b28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11048ULL;
	}
x86_l_2a3d:
	/* 0x2a3d: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a42:
	/* 0x2a42: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a45:
	/* 0x2a45: mov    QWORD PTR [rsp+0x20],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a4a:
	/* 0x2a4a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2a50:
	/* 0x2a50: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a53:
	/* 0x2a53: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a58:
	/* 0x2a58: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2a5d:
	/* 0x2a5d: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a62:
	/* 0x2a62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a64:
	/* 0x2a64: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2a69:
	/* 0x2a69: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a6b:
	/* 0x2a6b: js     2b28 <generic_retkprobe_event+0x2b28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11048ULL;
	}
x86_l_2a71:
	/* 0x2a71: add    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2a76:
	/* 0x2a76: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2a7c:
	/* 0x2a7c: je     2a8a <generic_retkprobe_event+0x2a8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10890ULL;
	}
x86_l_2a7e:
	/* 0x2a7e: sub    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 16ULL);
x86_l_2a83:
	/* 0x2a83: jne    2a91 <generic_retkprobe_event+0x2a91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10897ULL;
	}
	return 10885ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10885ULL: goto x86_l_2a85;
	case 10890ULL: goto x86_l_2a8a;
	case 10892ULL: goto x86_l_2a8c;
	case 10897ULL: goto x86_l_2a91;
	case 10906ULL: goto x86_l_2a9a;
	case 10912ULL: goto x86_l_2aa0;
	case 10920ULL: goto x86_l_2aa8;
	case 10924ULL: goto x86_l_2aac;
	case 10930ULL: goto x86_l_2ab2;
	case 10935ULL: goto x86_l_2ab7;
	case 10940ULL: goto x86_l_2abc;
	case 10945ULL: goto x86_l_2ac1;
	case 10947ULL: goto x86_l_2ac3;
	case 10952ULL: goto x86_l_2ac8;
	case 10954ULL: goto x86_l_2aca;
	case 10956ULL: goto x86_l_2acc;
	case 10961ULL: goto x86_l_2ad1;
	case 10966ULL: goto x86_l_2ad6;
	case 10969ULL: goto x86_l_2ad9;
	case 10972ULL: goto x86_l_2adc;
	case 10976ULL: goto x86_l_2ae0;
	case 10979ULL: goto x86_l_2ae3;
	case 10983ULL: goto x86_l_2ae7;
	case 10988ULL: goto x86_l_2aec;
	case 10995ULL: goto x86_l_2af3;
	case 10997ULL: goto x86_l_2af5;
	case 11002ULL: goto x86_l_2afa;
	case 11007ULL: goto x86_l_2aff;
	case 11013ULL: goto x86_l_2b05;
	case 11016ULL: goto x86_l_2b08;
	case 11021ULL: goto x86_l_2b0d;
	case 11026ULL: goto x86_l_2b12;
	case 11029ULL: goto x86_l_2b15;
	case 11031ULL: goto x86_l_2b17;
	case 11036ULL: goto x86_l_2b1c;
	case 11038ULL: goto x86_l_2b1e;
	case 11040ULL: goto x86_l_2b20;
	case 11043ULL: goto x86_l_2b23;
	case 11048ULL: goto x86_l_2b28;
	case 11053ULL: goto x86_l_2b2d;
	case 11057ULL: goto x86_l_2b31;
	case 11060ULL: goto x86_l_2b34;
	case 11063ULL: goto x86_l_2b37;
	case 11068ULL: goto x86_l_2b3c;
	case 11073ULL: goto x86_l_2b41;
	case 11075ULL: goto x86_l_2b43;
	case 11078ULL: goto x86_l_2b46;
	case 11083ULL: goto x86_l_2b4b;
	case 11088ULL: goto x86_l_2b50;
	case 11096ULL: goto x86_l_2b58;
	case 11104ULL: goto x86_l_2b60;
	case 11109ULL: goto x86_l_2b65;
	case 11111ULL: goto x86_l_2b67;
	case 11118ULL: goto x86_l_2b6e;
	case 11122ULL: goto x86_l_2b72;
	case 11127ULL: goto x86_l_2b77;
	case 11134ULL: goto x86_l_2b7e;
	case 11139ULL: goto x86_l_2b83;
	case 11141ULL: goto x86_l_2b85;
	case 11144ULL: goto x86_l_2b88;
	case 11146ULL: goto x86_l_2b8a;
	case 11149ULL: goto x86_l_2b8d;
	case 11154ULL: goto x86_l_2b92;
	case 11160ULL: goto x86_l_2b98;
	case 11165ULL: goto x86_l_2b9d;
	case 11172ULL: goto x86_l_2ba4;
	case 11177ULL: goto x86_l_2ba9;
	case 11182ULL: goto x86_l_2bae;
	case 11185ULL: goto x86_l_2bb1;
	case 11187ULL: goto x86_l_2bb3;
	case 11193ULL: goto x86_l_2bb9;
	case 11199ULL: goto x86_l_2bbf;
	case 11204ULL: goto x86_l_2bc4;
	case 11209ULL: goto x86_l_2bc9;
	case 11214ULL: goto x86_l_2bce;
	case 11222ULL: goto x86_l_2bd6;
	case 11227ULL: goto x86_l_2bdb;
	case 11229ULL: goto x86_l_2bdd;
	case 11236ULL: goto x86_l_2be4;
	case 11240ULL: goto x86_l_2be8;
	case 11245ULL: goto x86_l_2bed;
	case 11252ULL: goto x86_l_2bf4;
	case 11257ULL: goto x86_l_2bf9;
	case 11259ULL: goto x86_l_2bfb;
	case 11262ULL: goto x86_l_2bfe;
	case 11264ULL: goto x86_l_2c00;
	case 11267ULL: goto x86_l_2c03;
	case 11272ULL: goto x86_l_2c08;
	case 11278ULL: goto x86_l_2c0e;
	case 11283ULL: goto x86_l_2c13;
	case 11288ULL: goto x86_l_2c18;
	case 11293ULL: goto x86_l_2c1d;
	case 11298ULL: goto x86_l_2c22;
	case 11303ULL: goto x86_l_2c27;
	case 11305ULL: goto x86_l_2c29;
	case 11311ULL: goto x86_l_2c2f;
	case 11317ULL: goto x86_l_2c35;
	case 11322ULL: goto x86_l_2c3a;
	case 11327ULL: goto x86_l_2c3f;
	case 11332ULL: goto x86_l_2c44;
	case 11340ULL: goto x86_l_2c4c;
	case 11345ULL: goto x86_l_2c51;
	case 11347ULL: goto x86_l_2c53;
	case 11354ULL: goto x86_l_2c5a;
	case 11358ULL: goto x86_l_2c5e;
	case 11363ULL: goto x86_l_2c63;
	case 11370ULL: goto x86_l_2c6a;
	case 11375ULL: goto x86_l_2c6f;
	case 11377ULL: goto x86_l_2c71;
	case 11380ULL: goto x86_l_2c74;
	case 11382ULL: goto x86_l_2c76;
	case 11385ULL: goto x86_l_2c79;
	case 11390ULL: goto x86_l_2c7e;
	case 11396ULL: goto x86_l_2c84;
	case 11401ULL: goto x86_l_2c89;
	case 11406ULL: goto x86_l_2c8e;
	case 11411ULL: goto x86_l_2c93;
	case 11416ULL: goto x86_l_2c98;
	case 11421ULL: goto x86_l_2c9d;
	case 11423ULL: goto x86_l_2c9f;
	case 11429ULL: goto x86_l_2ca5;
	case 11431ULL: goto x86_l_2ca7;
	case 11436ULL: goto x86_l_2cac;
	case 11441ULL: goto x86_l_2cb1;
	case 11446ULL: goto x86_l_2cb6;
	case 11454ULL: goto x86_l_2cbe;
	case 11459ULL: goto x86_l_2cc3;
	case 11461ULL: goto x86_l_2cc5;
	case 11468ULL: goto x86_l_2ccc;
	case 11472ULL: goto x86_l_2cd0;
	case 11477ULL: goto x86_l_2cd5;
	case 11484ULL: goto x86_l_2cdc;
	case 11489ULL: goto x86_l_2ce1;
	case 11491ULL: goto x86_l_2ce3;
	case 11494ULL: goto x86_l_2ce6;
	case 11496ULL: goto x86_l_2ce8;
	case 11499ULL: goto x86_l_2ceb;
	case 11504ULL: goto x86_l_2cf0;
	case 11506ULL: goto x86_l_2cf2;
	case 11511ULL: goto x86_l_2cf7;
	case 11516ULL: goto x86_l_2cfc;
	case 11521ULL: goto x86_l_2d01;
	case 11526ULL: goto x86_l_2d06;
	case 11531ULL: goto x86_l_2d0b;
	case 11533ULL: goto x86_l_2d0d;
	case 11536ULL: goto x86_l_2d10;
	case 11542ULL: goto x86_l_2d16;
	case 11546ULL: goto x86_l_2d1a;
	case 11551ULL: goto x86_l_2d1f;
	case 11553ULL: goto x86_l_2d21;
	case 11557ULL: goto x86_l_2d25;
	case 11560ULL: goto x86_l_2d28;
	case 11562ULL: goto x86_l_2d2a;
	case 11565ULL: goto x86_l_2d2d;
	case 11568ULL: goto x86_l_2d30;
	case 11572ULL: goto x86_l_2d34;
	case 11576ULL: goto x86_l_2d38;
	case 11583ULL: goto x86_l_2d3f;
	case 11587ULL: goto x86_l_2d43;
	case 11591ULL: goto x86_l_2d47;
	case 11595ULL: goto x86_l_2d4b;
	case 11600ULL: goto x86_l_2d50;
	case 11607ULL: goto x86_l_2d57;
	case 11615ULL: goto x86_l_2d5f;
	case 11620ULL: goto x86_l_2d64;
	case 11622ULL: goto x86_l_2d66;
	case 11627ULL: goto x86_l_2d6b;
	case 11629ULL: goto x86_l_2d6d;
	case 11636ULL: goto x86_l_2d74;
	case 11638ULL: goto x86_l_2d76;
	case 11639ULL: goto x86_l_2d77;
	case 11644ULL: goto x86_l_2d7c;
	case 11646ULL: goto x86_l_2d7e;
	case 11648ULL: goto x86_l_2d80;
	case 11650ULL: goto x86_l_2d82;
	case 11651ULL: goto x86_l_2d83;
	case 11655ULL: goto x86_l_2d87;
	case 11658ULL: goto x86_l_2d8a;
	case 11662ULL: goto x86_l_2d8e;
	case 11666ULL: goto x86_l_2d92;
	case 11670ULL: goto x86_l_2d96;
	case 11673ULL: goto x86_l_2d99;
	case 11675ULL: goto x86_l_2d9b;
	case 11679ULL: goto x86_l_2d9f;
	case 11685ULL: goto x86_l_2da5;
	case 11690ULL: goto x86_l_2daa;
	case 11695ULL: goto x86_l_2daf;
	case 11700ULL: goto x86_l_2db4;
	case 11702ULL: goto x86_l_2db6;
	case 11707ULL: goto x86_l_2dbb;
	case 11713ULL: goto x86_l_2dc1;
	case 11717ULL: goto x86_l_2dc5;
	case 11722ULL: goto x86_l_2dca;
	case 11727ULL: goto x86_l_2dcf;
	case 11732ULL: goto x86_l_2dd4;
	case 11735ULL: goto x86_l_2dd7;
	case 11737ULL: goto x86_l_2dd9;
	case 11742ULL: goto x86_l_2dde;
	case 11748ULL: goto x86_l_2de4;
	case 11753ULL: goto x86_l_2de9;
	case 11758ULL: goto x86_l_2dee;
	case 11763ULL: goto x86_l_2df3;
	case 11766ULL: goto x86_l_2df6;
	case 11768ULL: goto x86_l_2df8;
	case 11772ULL: goto x86_l_2dfc;
	case 11777ULL: goto x86_l_2e01;
	case 11782ULL: goto x86_l_2e06;
	case 11787ULL: goto x86_l_2e0b;
	case 11790ULL: goto x86_l_2e0e;
	case 11792ULL: goto x86_l_2e10;
	case 11796ULL: goto x86_l_2e14;
	case 11800ULL: goto x86_l_2e18;
	case 11804ULL: goto x86_l_2e1c;
	case 11807ULL: goto x86_l_2e1f;
	case 11810ULL: goto x86_l_2e22;
	case 11812ULL: goto x86_l_2e24;
	case 11814ULL: goto x86_l_2e26;
	case 11816ULL: goto x86_l_2e28;
	case 11819ULL: goto x86_l_2e2b;
	case 11824ULL: goto x86_l_2e30;
	case 11827ULL: goto x86_l_2e33;
	case 11829ULL: goto x86_l_2e35;
	case 11833ULL: goto x86_l_2e39;
	case 11836ULL: goto x86_l_2e3c;
	case 11840ULL: goto x86_l_2e40;
	case 11843ULL: goto x86_l_2e43;
	case 11845ULL: goto x86_l_2e45;
	case 11848ULL: goto x86_l_2e48;
	case 11851ULL: goto x86_l_2e4b;
	case 11856ULL: goto x86_l_2e50;
	case 11859ULL: goto x86_l_2e53;
	case 11865ULL: goto x86_l_2e59;
	case 11872ULL: goto x86_l_2e60;
	case 11878ULL: goto x86_l_2e66;
	case 11880ULL: goto x86_l_2e68;
	case 11886ULL: goto x86_l_2e6e;
	case 11890ULL: goto x86_l_2e72;
	case 11895ULL: goto x86_l_2e77;
	case 11899ULL: goto x86_l_2e7b;
	case 11903ULL: goto x86_l_2e7f;
	case 11906ULL: goto x86_l_2e82;
	case 11911ULL: goto x86_l_2e87;
	case 11913ULL: goto x86_l_2e89;
	case 11917ULL: goto x86_l_2e8d;
	case 11922ULL: goto x86_l_2e92;
	case 11926ULL: goto x86_l_2e96;
	case 11928ULL: goto x86_l_2e98;
	case 11930ULL: goto x86_l_2e9a;
	case 11934ULL: goto x86_l_2e9e;
	case 11939ULL: goto x86_l_2ea3;
	case 11944ULL: goto x86_l_2ea8;
	case 11949ULL: goto x86_l_2ead;
	case 11951ULL: goto x86_l_2eaf;
	case 11955ULL: goto x86_l_2eb3;
	case 11960ULL: goto x86_l_2eb8;
	case 11962ULL: goto x86_l_2eba;
	case 11966ULL: goto x86_l_2ebe;
	case 11970ULL: goto x86_l_2ec2;
	case 11975ULL: goto x86_l_2ec7;
	case 11980ULL: goto x86_l_2ecc;
	case 11983ULL: goto x86_l_2ecf;
	case 11985ULL: goto x86_l_2ed1;
	case 11990ULL: goto x86_l_2ed6;
	case 11994ULL: goto x86_l_2eda;
	case 11998ULL: goto x86_l_2ede;
	case 12002ULL: goto x86_l_2ee2;
	case 12004ULL: goto x86_l_2ee4;
	case 12006ULL: goto x86_l_2ee6;
	case 12010ULL: goto x86_l_2eea;
	case 12015ULL: goto x86_l_2eef;
	case 12019ULL: goto x86_l_2ef3;
	case 12020ULL: goto x86_l_2ef4;
	case 12022ULL: goto x86_l_2ef6;
	case 12024ULL: goto x86_l_2ef8;
	case 12026ULL: goto x86_l_2efa;
	case 12027ULL: goto x86_l_2efb;
	case 12031ULL: goto x86_l_2eff;
	case 12034ULL: goto x86_l_2f02;
	case 12039ULL: goto x86_l_2f07;
	case 12042ULL: goto x86_l_2f0a;
	case 12044ULL: goto x86_l_2f0c;
	case 12049ULL: goto x86_l_2f11;
	case 12053ULL: goto x86_l_2f15;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a85:
	/* 0x2a85: jmp    2158 <generic_retkprobe_event+0x2158> */
	return 8536ULL;
x86_l_2a8a:
	/* 0x2a8a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a8c:
	/* 0x2a8c: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a91:
	/* 0x2a91: cmp    QWORD PTR [rsp+0x88],0x7 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552263ULL);
x86_l_2a9a:
	/* 0x2a9a: jb     2158 <generic_retkprobe_event+0x2158> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8536ULL;
	}
x86_l_2aa0:
	/* 0x2aa0: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2aa8:
	/* 0x2aa8: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_2aac:
	/* 0x2aac: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2ab2:
	/* 0x2ab2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ab7:
	/* 0x2ab7: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2abc:
	/* 0x2abc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2ac1:
	/* 0x2ac1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ac3:
	/* 0x2ac3: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2ac8:
	/* 0x2ac8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2aca:
	/* 0x2aca: js     2b28 <generic_retkprobe_event+0x2b28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2b28;
	}
x86_l_2acc:
	/* 0x2acc: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2ad1:
	/* 0x2ad1: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ad6:
	/* 0x2ad6: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_2ad9:
	/* 0x2ad9: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_2adc:
	/* 0x2adc: cmovb  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_2ae0:
	/* 0x2ae0: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2ae3:
	/* 0x2ae3: cmove  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_E);
x86_l_2ae7:
	/* 0x2ae7: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2aec:
	/* 0x2aec: cmp    r12,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4094ULL);
x86_l_2af3:
	/* 0x2af3: ja     2b28 <generic_retkprobe_event+0x2b28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b28;
	}
x86_l_2af5:
	/* 0x2af5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2afa:
	/* 0x2afa: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2aff:
	/* 0x2aff: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2b05:
	/* 0x2b05: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b08:
	/* 0x2b08: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b0d:
	/* 0x2b0d: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b12:
	/* 0x2b12: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2b15:
	/* 0x2b15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b17:
	/* 0x2b17: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2b1c:
	/* 0x2b1c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b1e:
	/* 0x2b1e: js     2b28 <generic_retkprobe_event+0x2b28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2b28;
	}
x86_l_2b20:
	/* 0x2b20: add    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b23:
	/* 0x2b23: jmp    215b <generic_retkprobe_event+0x215b> */
	return 8539ULL;
x86_l_2b28:
	/* 0x2b28: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b2d:
	/* 0x2b2d: mov    DWORD PTR [r15+rbp*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2b31:
	/* 0x2b31: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b34:
	/* 0x2b34: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_2b37:
	/* 0x2b37: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b3c:
	/* 0x2b3c: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_2b41:
	/* 0x2b41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b43:
	/* 0x2b43: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2b46:
	/* 0x2b46: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b4b:
	/* 0x2b4b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b50:
	/* 0x2b50: lea    rdx,[r12+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_2b58:
	/* 0x2b58: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2b60:
	/* 0x2b60: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b65:
	/* 0x2b65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b67:
	/* 0x2b67: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2b6e:
	/* 0x2b6e: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b72:
	/* 0x2b72: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b77:
	/* 0x2b77: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2b7e:
	/* 0x2b7e: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b83:
	/* 0x2b83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b85:
	/* 0x2b85: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b88:
	/* 0x2b88: je     2b98 <generic_retkprobe_event+0x2b98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b98;
	}
x86_l_2b8a:
	/* 0x2b8a: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2b8d:
	/* 0x2b8d: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2b92:
	/* 0x2b92: jne    2d10 <generic_retkprobe_event+0x2d10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d10;
	}
x86_l_2b98:
	/* 0x2b98: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b9d:
	/* 0x2b9d: add    r12,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_2ba4:
	/* 0x2ba4: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2ba9:
	/* 0x2ba9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bae:
	/* 0x2bae: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2bb1:
	/* 0x2bb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bb3:
	/* 0x2bb3: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_2bb9:
	/* 0x2bb9: je     2d0d <generic_retkprobe_event+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d0d;
	}
x86_l_2bbf:
	/* 0x2bbf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bc4:
	/* 0x2bc4: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2bc9:
	/* 0x2bc9: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2bce:
	/* 0x2bce: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2bd6:
	/* 0x2bd6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2bdb:
	/* 0x2bdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bdd:
	/* 0x2bdd: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2be4:
	/* 0x2be4: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2be8:
	/* 0x2be8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bed:
	/* 0x2bed: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2bf4:
	/* 0x2bf4: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2bf9:
	/* 0x2bf9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bfb:
	/* 0x2bfb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bfe:
	/* 0x2bfe: je     2c0e <generic_retkprobe_event+0x2c0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c0e;
	}
x86_l_2c00:
	/* 0x2c00: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2c03:
	/* 0x2c03: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2c08:
	/* 0x2c08: jne    2d10 <generic_retkprobe_event+0x2d10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d10;
	}
x86_l_2c0e:
	/* 0x2c0e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c13:
	/* 0x2c13: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2c18:
	/* 0x2c18: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2c1d:
	/* 0x2c1d: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2c22:
	/* 0x2c22: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c27:
	/* 0x2c27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c29:
	/* 0x2c29: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_2c2f:
	/* 0x2c2f: je     2d0d <generic_retkprobe_event+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d0d;
	}
x86_l_2c35:
	/* 0x2c35: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c3a:
	/* 0x2c3a: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2c3f:
	/* 0x2c3f: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2c44:
	/* 0x2c44: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2c4c:
	/* 0x2c4c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c51:
	/* 0x2c51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c53:
	/* 0x2c53: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2c5a:
	/* 0x2c5a: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2c5e:
	/* 0x2c5e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c63:
	/* 0x2c63: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2c6a:
	/* 0x2c6a: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2c6f:
	/* 0x2c6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c71:
	/* 0x2c71: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c74:
	/* 0x2c74: je     2c84 <generic_retkprobe_event+0x2c84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c84;
	}
x86_l_2c76:
	/* 0x2c76: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2c79:
	/* 0x2c79: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2c7e:
	/* 0x2c7e: jne    2d10 <generic_retkprobe_event+0x2d10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d10;
	}
x86_l_2c84:
	/* 0x2c84: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c89:
	/* 0x2c89: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2c8e:
	/* 0x2c8e: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2c93:
	/* 0x2c93: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2c98:
	/* 0x2c98: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c9d:
	/* 0x2c9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c9f:
	/* 0x2c9f: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_2ca5:
	/* 0x2ca5: je     2d0d <generic_retkprobe_event+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d0d;
	}
x86_l_2ca7:
	/* 0x2ca7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cac:
	/* 0x2cac: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2cb1:
	/* 0x2cb1: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2cb6:
	/* 0x2cb6: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2cbe:
	/* 0x2cbe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2cc3:
	/* 0x2cc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cc5:
	/* 0x2cc5: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2ccc:
	/* 0x2ccc: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2cd0:
	/* 0x2cd0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cd5:
	/* 0x2cd5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2cdc:
	/* 0x2cdc: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ce1:
	/* 0x2ce1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ce3:
	/* 0x2ce3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ce6:
	/* 0x2ce6: je     2cf2 <generic_retkprobe_event+0x2cf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf2;
	}
x86_l_2ce8:
	/* 0x2ce8: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2ceb:
	/* 0x2ceb: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2cf0:
	/* 0x2cf0: jne    2d10 <generic_retkprobe_event+0x2d10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d10;
	}
x86_l_2cf2:
	/* 0x2cf2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cf7:
	/* 0x2cf7: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2cfc:
	/* 0x2cfc: add    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_2d01:
	/* 0x2d01: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2d06:
	/* 0x2d06: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d0b:
	/* 0x2d0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d0d:
	/* 0x2d0d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d10:
	/* 0x2d10: mov    DWORD PTR [rbx],0x10d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 269ULL);
x86_l_2d16:
	/* 0x2d16: mov    DWORD PTR [rbx+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d1a:
	/* 0x2d1a: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_2d1f:
	/* 0x2d1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d21:
	/* 0x2d21: mov    QWORD PTR [rbx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d25:
	/* 0x2d25: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_2d28:
	/* 0x2d28: je     2d38 <generic_retkprobe_event+0x2d38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d38;
	}
x86_l_2d2a:
	/* 0x2d2a: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d2d:
	/* 0x2d2d: mov    DWORD PTR [rbx+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d30:
	/* 0x2d30: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d34:
	/* 0x2d34: mov    QWORD PTR [rbx+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d38:
	/* 0x2d38: mov    DWORD PTR [rbx+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2d3f:
	/* 0x2d3f: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d43:
	/* 0x2d43: mov    QWORD PTR [rbx+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2d47:
	/* 0x2d47: mov    DWORD PTR [rbx+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d4b:
	/* 0x2d4b: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2d50:
	/* 0x2d50: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_2d57:
	/* 0x2d57: mov    rdi,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2d5f:
	/* 0x2d5f: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2d64:
	/* 0x2d64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d66:
	/* 0x2d66: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2d6b:
	/* 0x2d6b: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_2d6d:
	/* 0x2d6d: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_2d74:
	/* 0x2d74: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2d76:
	/* 0x2d76: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2d77:
	/* 0x2d77: jmp    2f17 <cwd_read_v61+0x19b> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2d7c:
	/* 0x2d7c: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2d7e:
	/* 0x2d7e: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2d80:
	/* 0x2d80: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2d82:
	/* 0x2d82: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2d83:
	/* 0x2d83: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_2d87:
	/* 0x2d87: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_2d8a:
	/* 0x2d8a: mov    r15,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d8e:
	/* 0x2d8e: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d92:
	/* 0x2d92: mov    r14,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d96:
	/* 0x2d96: cmp    r15,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2d99:
	/* 0x2d99: jne    2da5 <cwd_read_v61+0x29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2da5;
	}
x86_l_2d9b:
	/* 0x2d9b: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2d9f:
	/* 0x2d9f: je     2ee6 <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ee6;
	}
x86_l_2da5:
	/* 0x2da5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2daa:
	/* 0x2daa: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2daf:
	/* 0x2daf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2db4:
	/* 0x2db4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2db6:
	/* 0x2db6: cmp    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2dbb:
	/* 0x2dbb: je     2e9a <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e9a;
	}
x86_l_2dc1:
	/* 0x2dc1: lea    r12,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2dc5:
	/* 0x2dc5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2dca:
	/* 0x2dca: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dcf:
	/* 0x2dcf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dd4:
	/* 0x2dd4: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2dd7:
	/* 0x2dd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dd9:
	/* 0x2dd9: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dde:
	/* 0x2dde: je     2e9a <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e9a;
	}
x86_l_2de4:
	/* 0x2de4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2de9:
	/* 0x2de9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2dee:
	/* 0x2dee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2df3:
	/* 0x2df3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2df6:
	/* 0x2df6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2df8:
	/* 0x2df8: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2dfc:
	/* 0x2dfc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e01:
	/* 0x2e01: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e06:
	/* 0x2e06: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2e0b:
	/* 0x2e0b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2e0e:
	/* 0x2e0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e10:
	/* 0x2e10: mov    r14,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e14:
	/* 0x2e14: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e18:
	/* 0x2e18: mov    esi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2e1c:
	/* 0x2e1c: sub    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2e1f:
	/* 0x2e1f: mov    edi,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e22:
	/* 0x2e22: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e24:
	/* 0x2e24: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2e26:
	/* 0x2e26: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e28:
	/* 0x2e28: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2e2b:
	/* 0x2e2b: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2e30:
	/* 0x2e30: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e33:
	/* 0x2e33: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2e35:
	/* 0x2e35: seta   r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_A);
x86_l_2e39:
	/* 0x2e39: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_2e3c:
	/* 0x2e3c: cmovb  r8d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_2e40:
	/* 0x2e40: add    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2e43:
	/* 0x2e43: mov    eax,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_32);
x86_l_2e45:
	/* 0x2e45: sub    eax,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R9, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e48:
	/* 0x2e48: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e4b:
	/* 0x2e4b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e50:
	/* 0x2e50: sub    rcx,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R9, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2e53:
	/* 0x2e53: jb     2eef <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2eef;
	}
x86_l_2e59:
	/* 0x2e59: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_2e60:
	/* 0x2e60: ja     2eef <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2eef;
	}
x86_l_2e66:
	/* 0x2e66: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2e68:
	/* 0x2e68: jbe    2efb <cwd_read_v61+0x17f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2efb;
	}
x86_l_2e6e:
	/* 0x2e6e: lea    r15,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2e72:
	/* 0x2e72: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2e77:
	/* 0x2e77: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e7b:
	/* 0x2e7b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2e7f:
	/* 0x2e7f: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2e82:
	/* 0x2e82: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e87:
	/* 0x2e87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e89:
	/* 0x2e89: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e8d:
	/* 0x2e8d: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e92:
	/* 0x2e92: mov    QWORD PTR [rbx+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e96:
	/* 0x2e96: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e98:
	/* 0x2e98: jmp    2eef <cwd_read_v61+0x173> */
	goto x86_l_2eef;
x86_l_2e9a:
	/* 0x2e9a: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e9e:
	/* 0x2e9e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ea3:
	/* 0x2ea3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ea8:
	/* 0x2ea8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ead:
	/* 0x2ead: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eaf:
	/* 0x2eaf: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2eb3:
	/* 0x2eb3: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2eb8:
	/* 0x2eb8: je     2ee6 <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ee6;
	}
x86_l_2eba:
	/* 0x2eba: lea    rdi,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ebe:
	/* 0x2ebe: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2ec2:
	/* 0x2ec2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ec7:
	/* 0x2ec7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ecc:
	/* 0x2ecc: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2ecf:
	/* 0x2ecf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ed1:
	/* 0x2ed1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ed6:
	/* 0x2ed6: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2eda:
	/* 0x2eda: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2ede:
	/* 0x2ede: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ee2:
	/* 0x2ee2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ee4:
	/* 0x2ee4: jmp    2eef <cwd_read_v61+0x173> */
	goto x86_l_2eef;
x86_l_2ee6:
	/* 0x2ee6: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_2eea:
	/* 0x2eea: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2eef:
	/* 0x2eef: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_2ef3:
	/* 0x2ef3: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2ef4:
	/* 0x2ef4: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2ef6:
	/* 0x2ef6: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2ef8:
	/* 0x2ef8: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2efa:
	/* 0x2efa: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2efb:
	/* 0x2efb: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2eff:
	/* 0x2eff: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f02:
	/* 0x2f02: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f07:
	/* 0x2f07: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2f0a:
	/* 0x2f0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f0c:
	/* 0x2f0c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f11:
	/* 0x2f11: mov    QWORD PTR [rbx+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f15:
	/* 0x2f15: jmp    2eef <cwd_read_v61+0x173> */
	goto x86_l_2eef;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 10348U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1852ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1855ULL && __x86_pc <= 3709ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3715ULL && __x86_pc <= 5599ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5601ULL && __x86_pc <= 7435ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7437ULL && __x86_pc <= 9143ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9148ULL && __x86_pc <= 10883ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10885ULL && __x86_pc <= 12053ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_v61_generic_retkprobe_event_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

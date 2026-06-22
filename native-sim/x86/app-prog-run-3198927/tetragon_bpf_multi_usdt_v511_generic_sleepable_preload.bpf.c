extern char CONFIG_ITER_NUM;
extern char config_map;
extern char heap_ro_zero;
extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 15ULL: goto x86_l_f;
	case 20ULL: goto x86_l_14;
	case 22ULL: goto x86_l_16;
	case 29ULL: goto x86_l_1d;
	case 36ULL: goto x86_l_24;
	case 44ULL: goto x86_l_2c;
	case 49ULL: goto x86_l_31;
	case 51ULL: goto x86_l_33;
	case 54ULL: goto x86_l_36;
	case 60ULL: goto x86_l_3c;
	case 63ULL: goto x86_l_3f;
	case 70ULL: goto x86_l_46;
	case 75ULL: goto x86_l_4b;
	case 82ULL: goto x86_l_52;
	case 87ULL: goto x86_l_57;
	case 94ULL: goto x86_l_5e;
	case 99ULL: goto x86_l_63;
	case 103ULL: goto x86_l_67;
	case 111ULL: goto x86_l_6f;
	case 115ULL: goto x86_l_73;
	case 120ULL: goto x86_l_78;
	case 124ULL: goto x86_l_7c;
	case 132ULL: goto x86_l_84;
	case 136ULL: goto x86_l_88;
	case 141ULL: goto x86_l_8d;
	case 145ULL: goto x86_l_91;
	case 153ULL: goto x86_l_99;
	case 157ULL: goto x86_l_9d;
	case 162ULL: goto x86_l_a2;
	case 166ULL: goto x86_l_a6;
	case 174ULL: goto x86_l_ae;
	case 178ULL: goto x86_l_b2;
	case 183ULL: goto x86_l_b7;
	case 187ULL: goto x86_l_bb;
	case 195ULL: goto x86_l_c3;
	case 199ULL: goto x86_l_c7;
	case 204ULL: goto x86_l_cc;
	case 208ULL: goto x86_l_d0;
	case 216ULL: goto x86_l_d8;
	case 220ULL: goto x86_l_dc;
	case 225ULL: goto x86_l_e1;
	case 228ULL: goto x86_l_e4;
	case 232ULL: goto x86_l_e8;
	case 240ULL: goto x86_l_f0;
	case 244ULL: goto x86_l_f4;
	case 249ULL: goto x86_l_f9;
	case 254ULL: goto x86_l_fe;
	case 260ULL: goto x86_l_104;
	case 264ULL: goto x86_l_108;
	case 267ULL: goto x86_l_10b;
	case 274ULL: goto x86_l_112;
	case 280ULL: goto x86_l_118;
	case 285ULL: goto x86_l_11d;
	case 287ULL: goto x86_l_11f;
	case 290ULL: goto x86_l_122;
	case 295ULL: goto x86_l_127;
	case 300ULL: goto x86_l_12c;
	case 304ULL: goto x86_l_130;
	case 308ULL: goto x86_l_134;
	case 312ULL: goto x86_l_138;
	case 319ULL: goto x86_l_13f;
	case 325ULL: goto x86_l_145;
	case 329ULL: goto x86_l_149;
	case 334ULL: goto x86_l_14e;
	case 336ULL: goto x86_l_150;
	case 338ULL: goto x86_l_152;
	case 340ULL: goto x86_l_154;
	case 344ULL: goto x86_l_158;
	case 347ULL: goto x86_l_15b;
	case 353ULL: goto x86_l_161;
	case 356ULL: goto x86_l_164;
	case 362ULL: goto x86_l_16a;
	case 367ULL: goto x86_l_16f;
	case 370ULL: goto x86_l_172;
	case 376ULL: goto x86_l_178;
	case 379ULL: goto x86_l_17b;
	case 385ULL: goto x86_l_181;
	case 390ULL: goto x86_l_186;
	case 395ULL: goto x86_l_18b;
	case 400ULL: goto x86_l_190;
	case 403ULL: goto x86_l_193;
	case 408ULL: goto x86_l_198;
	case 410ULL: goto x86_l_19a;
	case 412ULL: goto x86_l_19c;
	case 418ULL: goto x86_l_1a2;
	case 420ULL: goto x86_l_1a4;
	case 425ULL: goto x86_l_1a9;
	case 433ULL: goto x86_l_1b1;
	case 441ULL: goto x86_l_1b9;
	case 447ULL: goto x86_l_1bf;
	case 450ULL: goto x86_l_1c2;
	case 456ULL: goto x86_l_1c8;
	case 459ULL: goto x86_l_1cb;
	case 465ULL: goto x86_l_1d1;
	case 468ULL: goto x86_l_1d4;
	case 474ULL: goto x86_l_1da;
	case 482ULL: goto x86_l_1e2;
	case 485ULL: goto x86_l_1e5;
	case 491ULL: goto x86_l_1eb;
	case 496ULL: goto x86_l_1f0;
	case 499ULL: goto x86_l_1f3;
	case 505ULL: goto x86_l_1f9;
	case 510ULL: goto x86_l_1fe;
	case 513ULL: goto x86_l_201;
	case 519ULL: goto x86_l_207;
	case 524ULL: goto x86_l_20c;
	case 529ULL: goto x86_l_211;
	case 532ULL: goto x86_l_214;
	case 538ULL: goto x86_l_21a;
	case 543ULL: goto x86_l_21f;
	case 546ULL: goto x86_l_222;
	case 552ULL: goto x86_l_228;
	case 555ULL: goto x86_l_22b;
	case 561ULL: goto x86_l_231;
	case 566ULL: goto x86_l_236;
	case 569ULL: goto x86_l_239;
	case 574ULL: goto x86_l_23e;
	case 579ULL: goto x86_l_243;
	case 582ULL: goto x86_l_246;
	case 587ULL: goto x86_l_24b;
	case 589ULL: goto x86_l_24d;
	case 591ULL: goto x86_l_24f;
	case 597ULL: goto x86_l_255;
	case 600ULL: goto x86_l_258;
	case 606ULL: goto x86_l_25e;
	case 609ULL: goto x86_l_261;
	case 614ULL: goto x86_l_266;
	case 619ULL: goto x86_l_26b;
	case 625ULL: goto x86_l_271;
	case 630ULL: goto x86_l_276;
	case 632ULL: goto x86_l_278;
	case 634ULL: goto x86_l_27a;
	case 640ULL: goto x86_l_280;
	case 644ULL: goto x86_l_284;
	case 651ULL: goto x86_l_28b;
	case 654ULL: goto x86_l_28e;
	case 659ULL: goto x86_l_293;
	case 662ULL: goto x86_l_296;
	case 667ULL: goto x86_l_29b;
	case 671ULL: goto x86_l_29f;
	case 678ULL: goto x86_l_2a6;
	case 681ULL: goto x86_l_2a9;
	case 686ULL: goto x86_l_2ae;
	case 689ULL: goto x86_l_2b1;
	case 694ULL: goto x86_l_2b6;
	case 697ULL: goto x86_l_2b9;
	case 699ULL: goto x86_l_2bb;
	case 702ULL: goto x86_l_2be;
	case 708ULL: goto x86_l_2c4;
	case 713ULL: goto x86_l_2c9;
	case 715ULL: goto x86_l_2cb;
	case 721ULL: goto x86_l_2d1;
	case 726ULL: goto x86_l_2d6;
	case 731ULL: goto x86_l_2db;
	case 734ULL: goto x86_l_2de;
	case 740ULL: goto x86_l_2e4;
	case 745ULL: goto x86_l_2e9;
	case 748ULL: goto x86_l_2ec;
	case 754ULL: goto x86_l_2f2;
	case 762ULL: goto x86_l_2fa;
	case 765ULL: goto x86_l_2fd;
	case 771ULL: goto x86_l_303;
	case 776ULL: goto x86_l_308;
	case 781ULL: goto x86_l_30d;
	case 784ULL: goto x86_l_310;
	case 790ULL: goto x86_l_316;
	case 795ULL: goto x86_l_31b;
	case 798ULL: goto x86_l_31e;
	case 804ULL: goto x86_l_324;
	case 812ULL: goto x86_l_32c;
	case 815ULL: goto x86_l_32f;
	case 821ULL: goto x86_l_335;
	case 826ULL: goto x86_l_33a;
	case 831ULL: goto x86_l_33f;
	case 834ULL: goto x86_l_342;
	case 840ULL: goto x86_l_348;
	case 845ULL: goto x86_l_34d;
	case 848ULL: goto x86_l_350;
	case 853ULL: goto x86_l_355;
	case 857ULL: goto x86_l_359;
	case 864ULL: goto x86_l_360;
	case 869ULL: goto x86_l_365;
	case 873ULL: goto x86_l_369;
	case 878ULL: goto x86_l_36e;
	case 883ULL: goto x86_l_373;
	case 887ULL: goto x86_l_377;
	case 889ULL: goto x86_l_379;
	case 892ULL: goto x86_l_37c;
	case 898ULL: goto x86_l_382;
	case 903ULL: goto x86_l_387;
	case 908ULL: goto x86_l_38c;
	case 914ULL: goto x86_l_392;
	case 917ULL: goto x86_l_395;
	case 922ULL: goto x86_l_39a;
	case 924ULL: goto x86_l_39c;
	case 926ULL: goto x86_l_39e;
	case 928ULL: goto x86_l_3a0;
	case 933ULL: goto x86_l_3a5;
	case 936ULL: goto x86_l_3a8;
	case 941ULL: goto x86_l_3ad;
	case 946ULL: goto x86_l_3b2;
	case 949ULL: goto x86_l_3b5;
	case 952ULL: goto x86_l_3b8;
	case 957ULL: goto x86_l_3bd;
	case 959ULL: goto x86_l_3bf;
	case 961ULL: goto x86_l_3c1;
	case 963ULL: goto x86_l_3c3;
	case 966ULL: goto x86_l_3c6;
	case 971ULL: goto x86_l_3cb;
	case 974ULL: goto x86_l_3ce;
	case 976ULL: goto x86_l_3d0;
	case 980ULL: goto x86_l_3d4;
	case 987ULL: goto x86_l_3db;
	case 993ULL: goto x86_l_3e1;
	case 1000ULL: goto x86_l_3e8;
	case 1003ULL: goto x86_l_3eb;
	case 1008ULL: goto x86_l_3f0;
	case 1011ULL: goto x86_l_3f3;
	case 1016ULL: goto x86_l_3f8;
	case 1022ULL: goto x86_l_3fe;
	case 1024ULL: goto x86_l_400;
	case 1029ULL: goto x86_l_405;
	case 1035ULL: goto x86_l_40b;
	case 1038ULL: goto x86_l_40e;
	case 1040ULL: goto x86_l_410;
	case 1045ULL: goto x86_l_415;
	case 1050ULL: goto x86_l_41a;
	case 1055ULL: goto x86_l_41f;
	case 1060ULL: goto x86_l_424;
	case 1062ULL: goto x86_l_426;
	case 1064ULL: goto x86_l_428;
	case 1070ULL: goto x86_l_42e;
	case 1077ULL: goto x86_l_435;
	case 1083ULL: goto x86_l_43b;
	case 1088ULL: goto x86_l_440;
	case 1093ULL: goto x86_l_445;
	case 1098ULL: goto x86_l_44a;
	case 1105ULL: goto x86_l_451;
	case 1107ULL: goto x86_l_453;
	case 1112ULL: goto x86_l_458;
	case 1117ULL: goto x86_l_45d;
	case 1122ULL: goto x86_l_462;
	case 1127ULL: goto x86_l_467;
	case 1129ULL: goto x86_l_469;
	case 1131ULL: goto x86_l_46b;
	case 1137ULL: goto x86_l_471;
	case 1144ULL: goto x86_l_478;
	case 1150ULL: goto x86_l_47e;
	case 1155ULL: goto x86_l_483;
	case 1160ULL: goto x86_l_488;
	case 1165ULL: goto x86_l_48d;
	case 1172ULL: goto x86_l_494;
	case 1174ULL: goto x86_l_496;
	case 1179ULL: goto x86_l_49b;
	case 1184ULL: goto x86_l_4a0;
	case 1189ULL: goto x86_l_4a5;
	case 1194ULL: goto x86_l_4aa;
	case 1196ULL: goto x86_l_4ac;
	case 1198ULL: goto x86_l_4ae;
	case 1204ULL: goto x86_l_4b4;
	case 1211ULL: goto x86_l_4bb;
	case 1217ULL: goto x86_l_4c1;
	case 1222ULL: goto x86_l_4c6;
	case 1227ULL: goto x86_l_4cb;
	case 1232ULL: goto x86_l_4d0;
	case 1239ULL: goto x86_l_4d7;
	case 1241ULL: goto x86_l_4d9;
	case 1246ULL: goto x86_l_4de;
	case 1251ULL: goto x86_l_4e3;
	case 1256ULL: goto x86_l_4e8;
	case 1261ULL: goto x86_l_4ed;
	case 1263ULL: goto x86_l_4ef;
	case 1265ULL: goto x86_l_4f1;
	case 1271ULL: goto x86_l_4f7;
	case 1278ULL: goto x86_l_4fe;
	case 1284ULL: goto x86_l_504;
	case 1289ULL: goto x86_l_509;
	case 1294ULL: goto x86_l_50e;
	case 1299ULL: goto x86_l_513;
	case 1306ULL: goto x86_l_51a;
	case 1308ULL: goto x86_l_51c;
	case 1313ULL: goto x86_l_521;
	case 1318ULL: goto x86_l_526;
	case 1323ULL: goto x86_l_52b;
	case 1328ULL: goto x86_l_530;
	case 1330ULL: goto x86_l_532;
	case 1332ULL: goto x86_l_534;
	case 1338ULL: goto x86_l_53a;
	case 1345ULL: goto x86_l_541;
	case 1351ULL: goto x86_l_547;
	case 1356ULL: goto x86_l_54c;
	case 1361ULL: goto x86_l_551;
	case 1366ULL: goto x86_l_556;
	case 1373ULL: goto x86_l_55d;
	case 1375ULL: goto x86_l_55f;
	case 1380ULL: goto x86_l_564;
	case 1385ULL: goto x86_l_569;
	case 1390ULL: goto x86_l_56e;
	case 1395ULL: goto x86_l_573;
	case 1397ULL: goto x86_l_575;
	case 1399ULL: goto x86_l_577;
	case 1405ULL: goto x86_l_57d;
	case 1412ULL: goto x86_l_584;
	case 1418ULL: goto x86_l_58a;
	case 1423ULL: goto x86_l_58f;
	case 1428ULL: goto x86_l_594;
	case 1433ULL: goto x86_l_599;
	case 1440ULL: goto x86_l_5a0;
	case 1442ULL: goto x86_l_5a2;
	case 1447ULL: goto x86_l_5a7;
	case 1452ULL: goto x86_l_5ac;
	case 1457ULL: goto x86_l_5b1;
	case 1462ULL: goto x86_l_5b6;
	case 1464ULL: goto x86_l_5b8;
	case 1466ULL: goto x86_l_5ba;
	case 1472ULL: goto x86_l_5c0;
	case 1479ULL: goto x86_l_5c7;
	case 1485ULL: goto x86_l_5cd;
	case 1490ULL: goto x86_l_5d2;
	case 1495ULL: goto x86_l_5d7;
	case 1500ULL: goto x86_l_5dc;
	case 1507ULL: goto x86_l_5e3;
	case 1509ULL: goto x86_l_5e5;
	case 1514ULL: goto x86_l_5ea;
	case 1519ULL: goto x86_l_5ef;
	case 1524ULL: goto x86_l_5f4;
	case 1529ULL: goto x86_l_5f9;
	case 1531ULL: goto x86_l_5fb;
	case 1533ULL: goto x86_l_5fd;
	case 1539ULL: goto x86_l_603;
	case 1546ULL: goto x86_l_60a;
	case 1552ULL: goto x86_l_610;
	case 1557ULL: goto x86_l_615;
	case 1562ULL: goto x86_l_61a;
	case 1567ULL: goto x86_l_61f;
	case 1574ULL: goto x86_l_626;
	case 1576ULL: goto x86_l_628;
	case 1581ULL: goto x86_l_62d;
	case 1586ULL: goto x86_l_632;
	case 1591ULL: goto x86_l_637;
	case 1596ULL: goto x86_l_63c;
	case 1598ULL: goto x86_l_63e;
	case 1600ULL: goto x86_l_640;
	case 1606ULL: goto x86_l_646;
	case 1613ULL: goto x86_l_64d;
	case 1619ULL: goto x86_l_653;
	case 1624ULL: goto x86_l_658;
	case 1629ULL: goto x86_l_65d;
	case 1634ULL: goto x86_l_662;
	case 1641ULL: goto x86_l_669;
	case 1647ULL: goto x86_l_66f;
	case 1652ULL: goto x86_l_674;
	case 1657ULL: goto x86_l_679;
	case 1662ULL: goto x86_l_67e;
	case 1667ULL: goto x86_l_683;
	case 1672ULL: goto x86_l_688;
	case 1675ULL: goto x86_l_68b;
	case 1677ULL: goto x86_l_68d;
	case 1682ULL: goto x86_l_692;
	case 1687ULL: goto x86_l_697;
	case 1692ULL: goto x86_l_69c;
	case 1697ULL: goto x86_l_6a1;
	case 1699ULL: goto x86_l_6a3;
	case 1701ULL: goto x86_l_6a5;
	case 1707ULL: goto x86_l_6ab;
	case 1714ULL: goto x86_l_6b2;
	case 1720ULL: goto x86_l_6b8;
	case 1725ULL: goto x86_l_6bd;
	case 1730ULL: goto x86_l_6c2;
	case 1735ULL: goto x86_l_6c7;
	case 1742ULL: goto x86_l_6ce;
	case 1744ULL: goto x86_l_6d0;
	case 1749ULL: goto x86_l_6d5;
	case 1754ULL: goto x86_l_6da;
	case 1759ULL: goto x86_l_6df;
	case 1764ULL: goto x86_l_6e4;
	case 1766ULL: goto x86_l_6e6;
	case 1768ULL: goto x86_l_6e8;
	case 1774ULL: goto x86_l_6ee;
	case 1781ULL: goto x86_l_6f5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 200ULL);
x86_l_a:
	/* 0xa: mov    eax,0xae */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 174ULL);
x86_l_f:
	/* 0xf: mov    QWORD PTR [rsp+0x30],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14:
	/* 0x14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16:
	/* 0x16: mov    DWORD PTR [rsp+0xc4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_24:
	/* 0x24: lea    rsi,[rsp+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_2c:
	/* 0x2c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31:
	/* 0x31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33:
	/* 0x33: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36:
	/* 0x36: je     11f6 <generic_sleepable_preload+0x11f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4598ULL;
	}
x86_l_3c:
	/* 0x3c: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3f:
	/* 0x3f: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_46:
	/* 0x46: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4b:
	/* 0x4b: lea    rcx,[r15+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_52:
	/* 0x52: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_57:
	/* 0x57: lea    rcx,[r15+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5e:
	/* 0x5e: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_63:
	/* 0x63: lea    rcx,[r15+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_67:
	/* 0x67: mov    QWORD PTR [rsp+0xb0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_6f:
	/* 0x6f: lea    rcx,[r15+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_73:
	/* 0x73: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_78:
	/* 0x78: lea    rcx,[r15+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7c:
	/* 0x7c: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_84:
	/* 0x84: lea    rcx,[r15+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_88:
	/* 0x88: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_8d:
	/* 0x8d: lea    rcx,[r15+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_91:
	/* 0x91: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_99:
	/* 0x99: lea    rcx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9d:
	/* 0x9d: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a2:
	/* 0xa2: lea    rcx,[r15+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a6:
	/* 0xa6: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ae:
	/* 0xae: lea    rcx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b2:
	/* 0xb2: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b7:
	/* 0xb7: lea    rcx,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bb:
	/* 0xbb: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_c3:
	/* 0xc3: lea    rcx,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c7:
	/* 0xc7: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_cc:
	/* 0xcc: lea    rcx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d0:
	/* 0xd0: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_d8:
	/* 0xd8: lea    rcx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dc:
	/* 0xdc: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e1:
	/* 0xe1: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e4:
	/* 0xe4: lea    rax,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e8:
	/* 0xe8: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_f0:
	/* 0xf0: lea    rax,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f4:
	/* 0xf4: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f9:
	/* 0xf9: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fe:
	/* 0xfe: je     11aa <generic_sleepable_preload+0x11aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4522ULL;
	}
x86_l_104:
	/* 0x104: lea    r14,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_108:
	/* 0x108: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_10b:
	/* 0x10b: add    rbx,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 512ULL);
x86_l_112:
	/* 0x112: mov    r15d,0xbe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 190ULL);
x86_l_118:
	/* 0x118: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11d:
	/* 0x11d: jmp    145 <generic_sleepable_preload+0x145> */
	goto x86_l_145;
x86_l_11f:
	/* 0x11f: mov    DWORD PTR [rax],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_122:
	/* 0x122: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_127:
	/* 0x127: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12c:
	/* 0x12c: add    r14,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_130:
	/* 0x130: add    rbx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_134:
	/* 0x134: add    r15,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_138:
	/* 0x138: cmp    r15,0x24e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 590ULL);
x86_l_13f:
	/* 0x13f: je     11f6 <generic_sleepable_preload+0x11f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4598ULL;
	}
x86_l_145:
	/* 0x145: mov    eax,DWORD PTR [r14+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_149:
	/* 0x149: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_14e:
	/* 0x14e: je     12c <generic_sleepable_preload+0x12c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12c;
	}
x86_l_150:
	/* 0x150: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_152:
	/* 0x152: js     1a9 <generic_sleepable_preload+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a9;
	}
x86_l_154:
	/* 0x154: movzx  eax,BYTE PTR [rbx+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_158:
	/* 0x158: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15b:
	/* 0x15b: jg     211 <generic_sleepable_preload+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_211;
	}
x86_l_161:
	/* 0x161: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_164:
	/* 0x164: je     34d <generic_sleepable_preload+0x34d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34d;
	}
x86_l_16a:
	/* 0x16a: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_16f:
	/* 0x16f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_172:
	/* 0x172: jne    3c6 <generic_sleepable_preload+0x3c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3c6;
	}
x86_l_178:
	/* 0x178: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17b:
	/* 0x17b: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_181:
	/* 0x181: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_186:
	/* 0x186: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18b:
	/* 0x18b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_190:
	/* 0x190: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_193:
	/* 0x193: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_198:
	/* 0x198: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19a:
	/* 0x19a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19c:
	/* 0x19c: je     355 <generic_sleepable_preload+0x355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_355;
	}
x86_l_1a2:
	/* 0x1a2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a4:
	/* 0x1a4: jmp    3c6 <generic_sleepable_preload+0x3c6> */
	goto x86_l_3c6;
x86_l_1a9:
	/* 0x1a9: movzx  eax,BYTE PTR [r14+0x2be] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 702ULL);
x86_l_1b1:
	/* 0x1b1: movzx  ecx,WORD PTR [r14+0x2bc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 700ULL);
x86_l_1b9:
	/* 0x1b9: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1bf:
	/* 0x1bf: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1c2:
	/* 0x1c2: jle    2b6 <generic_sleepable_preload+0x2b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2b6;
	}
x86_l_1c8:
	/* 0x1c8: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_1cb:
	/* 0x1cb: jle    2e9 <generic_sleepable_preload+0x2e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e9;
	}
x86_l_1d1:
	/* 0x1d1: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1d4:
	/* 0x1d4: jle    97a <generic_sleepable_preload+0x97a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2426ULL;
	}
x86_l_1da:
	/* 0x1da: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1e2:
	/* 0x1e2: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_1e5:
	/* 0x1e5: je     996 <generic_sleepable_preload+0x996> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2454ULL;
	}
x86_l_1eb:
	/* 0x1eb: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f0:
	/* 0x1f0: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1f3:
	/* 0x1f3: je     996 <generic_sleepable_preload+0x996> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2454ULL;
	}
x86_l_1f9:
	/* 0x1f9: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_1fe:
	/* 0x1fe: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_201:
	/* 0x201: jne    9a9 <generic_sleepable_preload+0x9a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2473ULL;
	}
x86_l_207:
	/* 0x207: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_20c:
	/* 0x20c: jmp    996 <generic_sleepable_preload+0x996> */
	return 2454ULL;
x86_l_211:
	/* 0x211: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_214:
	/* 0x214: je     379 <generic_sleepable_preload+0x379> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_379;
	}
x86_l_21a:
	/* 0x21a: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_21f:
	/* 0x21f: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_222:
	/* 0x222: jne    3c6 <generic_sleepable_preload+0x3c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3c6;
	}
x86_l_228:
	/* 0x228: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22b:
	/* 0x22b: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_231:
	/* 0x231: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_236:
	/* 0x236: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_239:
	/* 0x239: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23e:
	/* 0x23e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_243:
	/* 0x243: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_246:
	/* 0x246: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24b:
	/* 0x24b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24d:
	/* 0x24d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24f:
	/* 0x24f: jne    3c3 <generic_sleepable_preload+0x3c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3c3;
	}
x86_l_255:
	/* 0x255: mov    edx,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_258:
	/* 0x258: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25e:
	/* 0x25e: add    rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_261:
	/* 0x261: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_266:
	/* 0x266: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26b:
	/* 0x26b: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_271:
	/* 0x271: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_276:
	/* 0x276: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_278:
	/* 0x278: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27a:
	/* 0x27a: jne    3c3 <generic_sleepable_preload+0x3c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3c3;
	}
x86_l_280:
	/* 0x280: movzx  eax,BYTE PTR [rbx+0x13] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 19ULL);
x86_l_284:
	/* 0x284: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_28b:
	/* 0x28b: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28e:
	/* 0x28e: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_293:
	/* 0x293: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_296:
	/* 0x296: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_29b:
	/* 0x29b: movzx  ecx,BYTE PTR [rbx+0x13] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 19ULL);
x86_l_29f:
	/* 0x29f: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_2a6:
	/* 0x2a6: mov    rdx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a9:
	/* 0x2a9: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2ae:
	/* 0x2ae: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b1:
	/* 0x2b1: jmp    3b5 <generic_sleepable_preload+0x3b5> */
	goto x86_l_3b5;
x86_l_2b6:
	/* 0x2b6: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_2b9:
	/* 0x2b9: jg     31b <generic_sleepable_preload+0x31b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_31b;
	}
x86_l_2bb:
	/* 0x2bb: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2be:
	/* 0x2be: jg     93e <generic_sleepable_preload+0x93e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2366ULL;
	}
x86_l_2c4:
	/* 0x2c4: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c9:
	/* 0x2c9: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2cb:
	/* 0x2cb: je     996 <generic_sleepable_preload+0x996> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2454ULL;
	}
x86_l_2d1:
	/* 0x2d1: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d6:
	/* 0x2d6: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_2db:
	/* 0x2db: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2de:
	/* 0x2de: je     996 <generic_sleepable_preload+0x996> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2454ULL;
	}
x86_l_2e4:
	/* 0x2e4: jmp    9a9 <generic_sleepable_preload+0x9a9> */
	return 2473ULL;
x86_l_2e9:
	/* 0x2e9: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_2ec:
	/* 0x2ec: jg     920 <generic_sleepable_preload+0x920> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2336ULL;
	}
x86_l_2f2:
	/* 0x2f2: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2fa:
	/* 0x2fa: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2fd:
	/* 0x2fd: je     996 <generic_sleepable_preload+0x996> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2454ULL;
	}
x86_l_303:
	/* 0x303: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_308:
	/* 0x308: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_30d:
	/* 0x30d: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_310:
	/* 0x310: je     996 <generic_sleepable_preload+0x996> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2454ULL;
	}
x86_l_316:
	/* 0x316: jmp    9a9 <generic_sleepable_preload+0x9a9> */
	return 2473ULL;
x86_l_31b:
	/* 0x31b: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_31e:
	/* 0x31e: jg     95c <generic_sleepable_preload+0x95c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2396ULL;
	}
x86_l_324:
	/* 0x324: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_32c:
	/* 0x32c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_32f:
	/* 0x32f: je     996 <generic_sleepable_preload+0x996> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2454ULL;
	}
x86_l_335:
	/* 0x335: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_33a:
	/* 0x33a: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_33f:
	/* 0x33f: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_342:
	/* 0x342: je     996 <generic_sleepable_preload+0x996> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2454ULL;
	}
x86_l_348:
	/* 0x348: jmp    9a9 <generic_sleepable_preload+0x9a9> */
	return 2473ULL;
x86_l_34d:
	/* 0x34d: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_350:
	/* 0x350: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_355:
	/* 0x355: movzx  eax,BYTE PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_359:
	/* 0x359: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_360:
	/* 0x360: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_365:
	/* 0x365: cmp    BYTE PTR [rbx+0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77309411328ULL);
x86_l_369:
	/* 0x369: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_36e:
	/* 0x36e: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_373:
	/* 0x373: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_377:
	/* 0x377: jmp    3c6 <generic_sleepable_preload+0x3c6> */
	goto x86_l_3c6;
x86_l_379:
	/* 0x379: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37c:
	/* 0x37c: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_382:
	/* 0x382: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_387:
	/* 0x387: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_38c:
	/* 0x38c: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_392:
	/* 0x392: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_395:
	/* 0x395: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39a:
	/* 0x39a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39c:
	/* 0x39c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39e:
	/* 0x39e: jne    3c3 <generic_sleepable_preload+0x3c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3c3;
	}
x86_l_3a0:
	/* 0x3a0: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a5:
	/* 0x3a5: add    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3a8:
	/* 0x3a8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3ad:
	/* 0x3ad: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b2:
	/* 0x3b2: add    rdx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3b5:
	/* 0x3b5: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_3b8:
	/* 0x3b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bd:
	/* 0x3bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bf:
	/* 0x3bf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c1:
	/* 0x3c1: je     355 <generic_sleepable_preload+0x355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_355;
	}
x86_l_3c3:
	/* 0x3c3: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3c6:
	/* 0x3c6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3cb:
	/* 0x3cb: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ce:
	/* 0x3ce: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_3d0:
	/* 0x3d0: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3d4:
	/* 0x3d4: cmp    WORD PTR [r13+r15*1-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743764471906304ULL);
x86_l_3db:
	/* 0x3db: je     67e <generic_sleepable_preload+0x67e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_67e;
	}
x86_l_3e1:
	/* 0x3e1: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3e8:
	/* 0x3e8: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3eb:
	/* 0x3eb: mov    eax,DWORD PTR [r13+r15*1-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551538ULL);
x86_l_3f0:
	/* 0x3f0: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3f3:
	/* 0x3f3: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f8:
	/* 0x3f8: movzx  eax,WORD PTR [r13+r15*1-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R15, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_3fe:
	/* 0x3fe: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_400:
	/* 0x400: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_405:
	/* 0x405: je     688 <generic_sleepable_preload+0x688> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_688;
	}
x86_l_40b:
	/* 0x40b: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_40e:
	/* 0x40e: je     42e <generic_sleepable_preload+0x42e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42e;
	}
x86_l_410:
	/* 0x410: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_415:
	/* 0x415: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41a:
	/* 0x41a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41f:
	/* 0x41f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_424:
	/* 0x424: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_426:
	/* 0x426: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_428:
	/* 0x428: js     915 <generic_sleepable_preload+0x915> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2325ULL;
	}
x86_l_42e:
	/* 0x42e: cmp    WORD PTR [r13+r15*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743798831644672ULL);
x86_l_435:
	/* 0x435: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
x86_l_43b:
	/* 0x43b: mov    ecx,DWORD PTR [r13+r15*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551546ULL);
x86_l_440:
	/* 0x440: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_445:
	/* 0x445: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44a:
	/* 0x44a: cmp    WORD PTR [r13+r15*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743790241710080ULL);
x86_l_451:
	/* 0x451: je     471 <generic_sleepable_preload+0x471> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_471;
	}
x86_l_453:
	/* 0x453: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_458:
	/* 0x458: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45d:
	/* 0x45d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_462:
	/* 0x462: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_467:
	/* 0x467: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_469:
	/* 0x469: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46b:
	/* 0x46b: js     f5b <generic_sleepable_preload+0xf5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3931ULL;
	}
x86_l_471:
	/* 0x471: cmp    WORD PTR [r13+r15*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743833191383040ULL);
x86_l_478:
	/* 0x478: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
x86_l_47e:
	/* 0x47e: mov    ecx,DWORD PTR [r13+r15*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551554ULL);
x86_l_483:
	/* 0x483: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_488:
	/* 0x488: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48d:
	/* 0x48d: cmp    WORD PTR [r13+r15*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743824601448448ULL);
x86_l_494:
	/* 0x494: je     4b4 <generic_sleepable_preload+0x4b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b4;
	}
x86_l_496:
	/* 0x496: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_49b:
	/* 0x49b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a0:
	/* 0x4a0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a5:
	/* 0x4a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4aa:
	/* 0x4aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ac:
	/* 0x4ac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ae:
	/* 0x4ae: js     f6e <generic_sleepable_preload+0xf6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3950ULL;
	}
x86_l_4b4:
	/* 0x4b4: cmp    WORD PTR [r13+r15*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743867551121408ULL);
x86_l_4bb:
	/* 0x4bb: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
x86_l_4c1:
	/* 0x4c1: mov    ecx,DWORD PTR [r13+r15*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551562ULL);
x86_l_4c6:
	/* 0x4c6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4cb:
	/* 0x4cb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d0:
	/* 0x4d0: cmp    WORD PTR [r13+r15*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743858961186816ULL);
x86_l_4d7:
	/* 0x4d7: je     4f7 <generic_sleepable_preload+0x4f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f7;
	}
x86_l_4d9:
	/* 0x4d9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4de:
	/* 0x4de: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e3:
	/* 0x4e3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e8:
	/* 0x4e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ed:
	/* 0x4ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ef:
	/* 0x4ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f1:
	/* 0x4f1: js     f81 <generic_sleepable_preload+0xf81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3969ULL;
	}
x86_l_4f7:
	/* 0x4f7: cmp    WORD PTR [r13+r15*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743901910859776ULL);
x86_l_4fe:
	/* 0x4fe: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
x86_l_504:
	/* 0x504: mov    ecx,DWORD PTR [r13+r15*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551570ULL);
x86_l_509:
	/* 0x509: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_50e:
	/* 0x50e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_513:
	/* 0x513: cmp    WORD PTR [r13+r15*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743893320925184ULL);
x86_l_51a:
	/* 0x51a: je     53a <generic_sleepable_preload+0x53a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_53a;
	}
x86_l_51c:
	/* 0x51c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_521:
	/* 0x521: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_526:
	/* 0x526: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52b:
	/* 0x52b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_530:
	/* 0x530: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_532:
	/* 0x532: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_534:
	/* 0x534: js     f94 <generic_sleepable_preload+0xf94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3988ULL;
	}
x86_l_53a:
	/* 0x53a: cmp    WORD PTR [r13+r15*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743936270598144ULL);
x86_l_541:
	/* 0x541: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
x86_l_547:
	/* 0x547: mov    ecx,DWORD PTR [r13+r15*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551578ULL);
x86_l_54c:
	/* 0x54c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_551:
	/* 0x551: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_556:
	/* 0x556: cmp    WORD PTR [r13+r15*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743927680663552ULL);
x86_l_55d:
	/* 0x55d: je     57d <generic_sleepable_preload+0x57d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57d;
	}
x86_l_55f:
	/* 0x55f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_564:
	/* 0x564: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_569:
	/* 0x569: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56e:
	/* 0x56e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_573:
	/* 0x573: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_575:
	/* 0x575: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_577:
	/* 0x577: js     fa7 <generic_sleepable_preload+0xfa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4007ULL;
	}
x86_l_57d:
	/* 0x57d: cmp    WORD PTR [r13+r15*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743970630336512ULL);
x86_l_584:
	/* 0x584: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
x86_l_58a:
	/* 0x58a: mov    ecx,DWORD PTR [r13+r15*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551586ULL);
x86_l_58f:
	/* 0x58f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_594:
	/* 0x594: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_599:
	/* 0x599: cmp    WORD PTR [r13+r15*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743962040401920ULL);
x86_l_5a0:
	/* 0x5a0: je     5c0 <generic_sleepable_preload+0x5c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c0;
	}
x86_l_5a2:
	/* 0x5a2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5a7:
	/* 0x5a7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ac:
	/* 0x5ac: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b1:
	/* 0x5b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b6:
	/* 0x5b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b8:
	/* 0x5b8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5ba:
	/* 0x5ba: js     fba <generic_sleepable_preload+0xfba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4026ULL;
	}
x86_l_5c0:
	/* 0x5c0: cmp    WORD PTR [r13+r15*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744004990074880ULL);
x86_l_5c7:
	/* 0x5c7: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
x86_l_5cd:
	/* 0x5cd: mov    ecx,DWORD PTR [r13+r15*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551594ULL);
x86_l_5d2:
	/* 0x5d2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5d7:
	/* 0x5d7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dc:
	/* 0x5dc: cmp    WORD PTR [r13+r15*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743996400140288ULL);
x86_l_5e3:
	/* 0x5e3: je     603 <generic_sleepable_preload+0x603> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_603;
	}
x86_l_5e5:
	/* 0x5e5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5ea:
	/* 0x5ea: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ef:
	/* 0x5ef: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f4:
	/* 0x5f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f9:
	/* 0x5f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fb:
	/* 0x5fb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5fd:
	/* 0x5fd: js     1165 <generic_sleepable_preload+0x1165> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4453ULL;
	}
x86_l_603:
	/* 0x603: cmp    WORD PTR [r13+r15*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744039349813248ULL);
x86_l_60a:
	/* 0x60a: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
x86_l_610:
	/* 0x610: mov    ecx,DWORD PTR [r13+r15*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551602ULL);
x86_l_615:
	/* 0x615: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_61a:
	/* 0x61a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_61f:
	/* 0x61f: cmp    WORD PTR [r13+r15*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744030759878656ULL);
x86_l_626:
	/* 0x626: je     646 <generic_sleepable_preload+0x646> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_646;
	}
x86_l_628:
	/* 0x628: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_62d:
	/* 0x62d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_632:
	/* 0x632: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_637:
	/* 0x637: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_63c:
	/* 0x63c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63e:
	/* 0x63e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_640:
	/* 0x640: js     1194 <generic_sleepable_preload+0x1194> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4500ULL;
	}
x86_l_646:
	/* 0x646: cmp    WORD PTR [r13+r15*1+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_64d:
	/* 0x64d: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
x86_l_653:
	/* 0x653: mov    ecx,DWORD PTR [r13+r15*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551610ULL);
x86_l_658:
	/* 0x658: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_65d:
	/* 0x65d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_662:
	/* 0x662: cmp    WORD PTR [r13+r15*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744065119617024ULL);
x86_l_669:
	/* 0x669: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
x86_l_66f:
	/* 0x66f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_674:
	/* 0x674: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_679:
	/* 0x679: jmp    8f6 <generic_sleepable_preload+0x8f6> */
	return 2294ULL;
x86_l_67e:
	/* 0x67e: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_683:
	/* 0x683: jmp    fc8 <generic_sleepable_preload+0xfc8> */
	return 4040ULL;
x86_l_688:
	/* 0x688: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_68b:
	/* 0x68b: je     6ab <generic_sleepable_preload+0x6ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6ab;
	}
x86_l_68d:
	/* 0x68d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_692:
	/* 0x692: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_697:
	/* 0x697: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_69c:
	/* 0x69c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6a1:
	/* 0x6a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a3:
	/* 0x6a3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6a5:
	/* 0x6a5: js     915 <generic_sleepable_preload+0x915> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2325ULL;
	}
x86_l_6ab:
	/* 0x6ab: cmp    WORD PTR [r13+r15*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743798831644672ULL);
x86_l_6b2:
	/* 0x6b2: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
x86_l_6b8:
	/* 0x6b8: mov    ecx,DWORD PTR [r13+r15*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551546ULL);
x86_l_6bd:
	/* 0x6bd: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6c2:
	/* 0x6c2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6c7:
	/* 0x6c7: cmp    WORD PTR [r13+r15*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743790241710080ULL);
x86_l_6ce:
	/* 0x6ce: je     6ee <generic_sleepable_preload+0x6ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6ee;
	}
x86_l_6d0:
	/* 0x6d0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6d5:
	/* 0x6d5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6da:
	/* 0x6da: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6df:
	/* 0x6df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6e4:
	/* 0x6e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e6:
	/* 0x6e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6e8:
	/* 0x6e8: js     f5b <generic_sleepable_preload+0xf5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3931ULL;
	}
x86_l_6ee:
	/* 0x6ee: cmp    WORD PTR [r13+r15*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743833191383040ULL);
x86_l_6f5:
	/* 0x6f5: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
	return 1787ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1787ULL: goto x86_l_6fb;
	case 1792ULL: goto x86_l_700;
	case 1797ULL: goto x86_l_705;
	case 1802ULL: goto x86_l_70a;
	case 1809ULL: goto x86_l_711;
	case 1811ULL: goto x86_l_713;
	case 1816ULL: goto x86_l_718;
	case 1821ULL: goto x86_l_71d;
	case 1826ULL: goto x86_l_722;
	case 1831ULL: goto x86_l_727;
	case 1833ULL: goto x86_l_729;
	case 1835ULL: goto x86_l_72b;
	case 1841ULL: goto x86_l_731;
	case 1848ULL: goto x86_l_738;
	case 1854ULL: goto x86_l_73e;
	case 1859ULL: goto x86_l_743;
	case 1864ULL: goto x86_l_748;
	case 1869ULL: goto x86_l_74d;
	case 1876ULL: goto x86_l_754;
	case 1878ULL: goto x86_l_756;
	case 1883ULL: goto x86_l_75b;
	case 1888ULL: goto x86_l_760;
	case 1893ULL: goto x86_l_765;
	case 1898ULL: goto x86_l_76a;
	case 1900ULL: goto x86_l_76c;
	case 1902ULL: goto x86_l_76e;
	case 1908ULL: goto x86_l_774;
	case 1915ULL: goto x86_l_77b;
	case 1921ULL: goto x86_l_781;
	case 1926ULL: goto x86_l_786;
	case 1931ULL: goto x86_l_78b;
	case 1936ULL: goto x86_l_790;
	case 1943ULL: goto x86_l_797;
	case 1945ULL: goto x86_l_799;
	case 1950ULL: goto x86_l_79e;
	case 1955ULL: goto x86_l_7a3;
	case 1960ULL: goto x86_l_7a8;
	case 1965ULL: goto x86_l_7ad;
	case 1967ULL: goto x86_l_7af;
	case 1969ULL: goto x86_l_7b1;
	case 1975ULL: goto x86_l_7b7;
	case 1982ULL: goto x86_l_7be;
	case 1988ULL: goto x86_l_7c4;
	case 1993ULL: goto x86_l_7c9;
	case 1998ULL: goto x86_l_7ce;
	case 2003ULL: goto x86_l_7d3;
	case 2010ULL: goto x86_l_7da;
	case 2012ULL: goto x86_l_7dc;
	case 2017ULL: goto x86_l_7e1;
	case 2022ULL: goto x86_l_7e6;
	case 2027ULL: goto x86_l_7eb;
	case 2032ULL: goto x86_l_7f0;
	case 2034ULL: goto x86_l_7f2;
	case 2036ULL: goto x86_l_7f4;
	case 2042ULL: goto x86_l_7fa;
	case 2049ULL: goto x86_l_801;
	case 2055ULL: goto x86_l_807;
	case 2060ULL: goto x86_l_80c;
	case 2065ULL: goto x86_l_811;
	case 2070ULL: goto x86_l_816;
	case 2077ULL: goto x86_l_81d;
	case 2079ULL: goto x86_l_81f;
	case 2084ULL: goto x86_l_824;
	case 2089ULL: goto x86_l_829;
	case 2094ULL: goto x86_l_82e;
	case 2099ULL: goto x86_l_833;
	case 2101ULL: goto x86_l_835;
	case 2103ULL: goto x86_l_837;
	case 2109ULL: goto x86_l_83d;
	case 2116ULL: goto x86_l_844;
	case 2122ULL: goto x86_l_84a;
	case 2127ULL: goto x86_l_84f;
	case 2132ULL: goto x86_l_854;
	case 2137ULL: goto x86_l_859;
	case 2144ULL: goto x86_l_860;
	case 2146ULL: goto x86_l_862;
	case 2151ULL: goto x86_l_867;
	case 2156ULL: goto x86_l_86c;
	case 2161ULL: goto x86_l_871;
	case 2166ULL: goto x86_l_876;
	case 2168ULL: goto x86_l_878;
	case 2170ULL: goto x86_l_87a;
	case 2176ULL: goto x86_l_880;
	case 2183ULL: goto x86_l_887;
	case 2189ULL: goto x86_l_88d;
	case 2194ULL: goto x86_l_892;
	case 2199ULL: goto x86_l_897;
	case 2204ULL: goto x86_l_89c;
	case 2211ULL: goto x86_l_8a3;
	case 2213ULL: goto x86_l_8a5;
	case 2218ULL: goto x86_l_8aa;
	case 2223ULL: goto x86_l_8af;
	case 2228ULL: goto x86_l_8b4;
	case 2233ULL: goto x86_l_8b9;
	case 2235ULL: goto x86_l_8bb;
	case 2237ULL: goto x86_l_8bd;
	case 2243ULL: goto x86_l_8c3;
	case 2250ULL: goto x86_l_8ca;
	case 2256ULL: goto x86_l_8d0;
	case 2261ULL: goto x86_l_8d5;
	case 2266ULL: goto x86_l_8da;
	case 2271ULL: goto x86_l_8df;
	case 2278ULL: goto x86_l_8e6;
	case 2284ULL: goto x86_l_8ec;
	case 2289ULL: goto x86_l_8f1;
	case 2294ULL: goto x86_l_8f6;
	case 2299ULL: goto x86_l_8fb;
	case 2304ULL: goto x86_l_900;
	case 2306ULL: goto x86_l_902;
	case 2308ULL: goto x86_l_904;
	case 2314ULL: goto x86_l_90a;
	case 2320ULL: goto x86_l_910;
	case 2325ULL: goto x86_l_915;
	case 2331ULL: goto x86_l_91b;
	case 2336ULL: goto x86_l_920;
	case 2344ULL: goto x86_l_928;
	case 2347ULL: goto x86_l_92b;
	case 2349ULL: goto x86_l_92d;
	case 2354ULL: goto x86_l_932;
	case 2359ULL: goto x86_l_937;
	case 2362ULL: goto x86_l_93a;
	case 2364ULL: goto x86_l_93c;
	case 2366ULL: goto x86_l_93e;
	case 2374ULL: goto x86_l_946;
	case 2377ULL: goto x86_l_949;
	case 2379ULL: goto x86_l_94b;
	case 2384ULL: goto x86_l_950;
	case 2389ULL: goto x86_l_955;
	case 2392ULL: goto x86_l_958;
	case 2394ULL: goto x86_l_95a;
	case 2396ULL: goto x86_l_95c;
	case 2404ULL: goto x86_l_964;
	case 2407ULL: goto x86_l_967;
	case 2409ULL: goto x86_l_969;
	case 2414ULL: goto x86_l_96e;
	case 2419ULL: goto x86_l_973;
	case 2422ULL: goto x86_l_976;
	case 2424ULL: goto x86_l_978;
	case 2426ULL: goto x86_l_97a;
	case 2434ULL: goto x86_l_982;
	case 2437ULL: goto x86_l_985;
	case 2439ULL: goto x86_l_987;
	case 2444ULL: goto x86_l_98c;
	case 2449ULL: goto x86_l_991;
	case 2452ULL: goto x86_l_994;
	case 2454ULL: goto x86_l_996;
	case 2457ULL: goto x86_l_999;
	case 2459ULL: goto x86_l_99b;
	case 2461ULL: goto x86_l_99d;
	case 2466ULL: goto x86_l_9a2;
	case 2468ULL: goto x86_l_9a4;
	case 2473ULL: goto x86_l_9a9;
	case 2478ULL: goto x86_l_9ae;
	case 2481ULL: goto x86_l_9b1;
	case 2484ULL: goto x86_l_9b4;
	case 2486ULL: goto x86_l_9b6;
	case 2490ULL: goto x86_l_9ba;
	case 2497ULL: goto x86_l_9c1;
	case 2503ULL: goto x86_l_9c7;
	case 2510ULL: goto x86_l_9ce;
	case 2513ULL: goto x86_l_9d1;
	case 2518ULL: goto x86_l_9d6;
	case 2521ULL: goto x86_l_9d9;
	case 2526ULL: goto x86_l_9de;
	case 2532ULL: goto x86_l_9e4;
	case 2534ULL: goto x86_l_9e6;
	case 2540ULL: goto x86_l_9ec;
	case 2543ULL: goto x86_l_9ef;
	case 2545ULL: goto x86_l_9f1;
	case 2550ULL: goto x86_l_9f6;
	case 2555ULL: goto x86_l_9fb;
	case 2560ULL: goto x86_l_a00;
	case 2565ULL: goto x86_l_a05;
	case 2570ULL: goto x86_l_a0a;
	case 2572ULL: goto x86_l_a0c;
	case 2574ULL: goto x86_l_a0e;
	case 2580ULL: goto x86_l_a14;
	case 2587ULL: goto x86_l_a1b;
	case 2593ULL: goto x86_l_a21;
	case 2598ULL: goto x86_l_a26;
	case 2603ULL: goto x86_l_a2b;
	case 2608ULL: goto x86_l_a30;
	case 2615ULL: goto x86_l_a37;
	case 2617ULL: goto x86_l_a39;
	case 2622ULL: goto x86_l_a3e;
	case 2627ULL: goto x86_l_a43;
	case 2632ULL: goto x86_l_a48;
	case 2637ULL: goto x86_l_a4d;
	case 2642ULL: goto x86_l_a52;
	case 2644ULL: goto x86_l_a54;
	case 2646ULL: goto x86_l_a56;
	case 2652ULL: goto x86_l_a5c;
	case 2659ULL: goto x86_l_a63;
	case 2665ULL: goto x86_l_a69;
	case 2670ULL: goto x86_l_a6e;
	case 2675ULL: goto x86_l_a73;
	case 2680ULL: goto x86_l_a78;
	case 2687ULL: goto x86_l_a7f;
	case 2689ULL: goto x86_l_a81;
	case 2694ULL: goto x86_l_a86;
	case 2699ULL: goto x86_l_a8b;
	case 2704ULL: goto x86_l_a90;
	case 2709ULL: goto x86_l_a95;
	case 2714ULL: goto x86_l_a9a;
	case 2716ULL: goto x86_l_a9c;
	case 2718ULL: goto x86_l_a9e;
	case 2724ULL: goto x86_l_aa4;
	case 2731ULL: goto x86_l_aab;
	case 2737ULL: goto x86_l_ab1;
	case 2742ULL: goto x86_l_ab6;
	case 2747ULL: goto x86_l_abb;
	case 2752ULL: goto x86_l_ac0;
	case 2759ULL: goto x86_l_ac7;
	case 2761ULL: goto x86_l_ac9;
	case 2766ULL: goto x86_l_ace;
	case 2771ULL: goto x86_l_ad3;
	case 2776ULL: goto x86_l_ad8;
	case 2781ULL: goto x86_l_add;
	case 2786ULL: goto x86_l_ae2;
	case 2788ULL: goto x86_l_ae4;
	case 2790ULL: goto x86_l_ae6;
	case 2796ULL: goto x86_l_aec;
	case 2803ULL: goto x86_l_af3;
	case 2809ULL: goto x86_l_af9;
	case 2814ULL: goto x86_l_afe;
	case 2819ULL: goto x86_l_b03;
	case 2824ULL: goto x86_l_b08;
	case 2831ULL: goto x86_l_b0f;
	case 2833ULL: goto x86_l_b11;
	case 2838ULL: goto x86_l_b16;
	case 2843ULL: goto x86_l_b1b;
	case 2848ULL: goto x86_l_b20;
	case 2853ULL: goto x86_l_b25;
	case 2858ULL: goto x86_l_b2a;
	case 2860ULL: goto x86_l_b2c;
	case 2862ULL: goto x86_l_b2e;
	case 2868ULL: goto x86_l_b34;
	case 2875ULL: goto x86_l_b3b;
	case 2881ULL: goto x86_l_b41;
	case 2886ULL: goto x86_l_b46;
	case 2891ULL: goto x86_l_b4b;
	case 2896ULL: goto x86_l_b50;
	case 2903ULL: goto x86_l_b57;
	case 2905ULL: goto x86_l_b59;
	case 2910ULL: goto x86_l_b5e;
	case 2915ULL: goto x86_l_b63;
	case 2920ULL: goto x86_l_b68;
	case 2925ULL: goto x86_l_b6d;
	case 2930ULL: goto x86_l_b72;
	case 2932ULL: goto x86_l_b74;
	case 2934ULL: goto x86_l_b76;
	case 2940ULL: goto x86_l_b7c;
	case 2947ULL: goto x86_l_b83;
	case 2953ULL: goto x86_l_b89;
	case 2958ULL: goto x86_l_b8e;
	case 2963ULL: goto x86_l_b93;
	case 2968ULL: goto x86_l_b98;
	case 2975ULL: goto x86_l_b9f;
	case 2977ULL: goto x86_l_ba1;
	case 2982ULL: goto x86_l_ba6;
	case 2987ULL: goto x86_l_bab;
	case 2992ULL: goto x86_l_bb0;
	case 2997ULL: goto x86_l_bb5;
	case 3002ULL: goto x86_l_bba;
	case 3004ULL: goto x86_l_bbc;
	case 3006ULL: goto x86_l_bbe;
	case 3012ULL: goto x86_l_bc4;
	case 3019ULL: goto x86_l_bcb;
	case 3025ULL: goto x86_l_bd1;
	case 3030ULL: goto x86_l_bd6;
	case 3035ULL: goto x86_l_bdb;
	case 3040ULL: goto x86_l_be0;
	case 3047ULL: goto x86_l_be7;
	case 3049ULL: goto x86_l_be9;
	case 3054ULL: goto x86_l_bee;
	case 3059ULL: goto x86_l_bf3;
	case 3064ULL: goto x86_l_bf8;
	case 3069ULL: goto x86_l_bfd;
	case 3074ULL: goto x86_l_c02;
	case 3076ULL: goto x86_l_c04;
	case 3078ULL: goto x86_l_c06;
	case 3084ULL: goto x86_l_c0c;
	case 3091ULL: goto x86_l_c13;
	case 3097ULL: goto x86_l_c19;
	case 3102ULL: goto x86_l_c1e;
	case 3107ULL: goto x86_l_c23;
	case 3112ULL: goto x86_l_c28;
	case 3119ULL: goto x86_l_c2f;
	case 3121ULL: goto x86_l_c31;
	case 3126ULL: goto x86_l_c36;
	case 3131ULL: goto x86_l_c3b;
	case 3136ULL: goto x86_l_c40;
	case 3141ULL: goto x86_l_c45;
	case 3146ULL: goto x86_l_c4a;
	case 3148ULL: goto x86_l_c4c;
	case 3150ULL: goto x86_l_c4e;
	case 3156ULL: goto x86_l_c54;
	case 3163ULL: goto x86_l_c5b;
	case 3169ULL: goto x86_l_c61;
	case 3174ULL: goto x86_l_c66;
	case 3179ULL: goto x86_l_c6b;
	case 3184ULL: goto x86_l_c70;
	case 3191ULL: goto x86_l_c77;
	case 3197ULL: goto x86_l_c7d;
	case 3202ULL: goto x86_l_c82;
	case 3207ULL: goto x86_l_c87;
	case 3212ULL: goto x86_l_c8c;
	case 3217ULL: goto x86_l_c91;
	case 3220ULL: goto x86_l_c94;
	case 3222ULL: goto x86_l_c96;
	case 3227ULL: goto x86_l_c9b;
	case 3232ULL: goto x86_l_ca0;
	case 3237ULL: goto x86_l_ca5;
	case 3242ULL: goto x86_l_caa;
	case 3247ULL: goto x86_l_caf;
	case 3249ULL: goto x86_l_cb1;
	case 3251ULL: goto x86_l_cb3;
	case 3257ULL: goto x86_l_cb9;
	case 3264ULL: goto x86_l_cc0;
	case 3270ULL: goto x86_l_cc6;
	case 3275ULL: goto x86_l_ccb;
	case 3280ULL: goto x86_l_cd0;
	case 3285ULL: goto x86_l_cd5;
	case 3292ULL: goto x86_l_cdc;
	case 3294ULL: goto x86_l_cde;
	case 3299ULL: goto x86_l_ce3;
	case 3304ULL: goto x86_l_ce8;
	case 3309ULL: goto x86_l_ced;
	case 3314ULL: goto x86_l_cf2;
	case 3319ULL: goto x86_l_cf7;
	case 3321ULL: goto x86_l_cf9;
	case 3323ULL: goto x86_l_cfb;
	case 3329ULL: goto x86_l_d01;
	case 3336ULL: goto x86_l_d08;
	case 3342ULL: goto x86_l_d0e;
	case 3347ULL: goto x86_l_d13;
	case 3352ULL: goto x86_l_d18;
	case 3357ULL: goto x86_l_d1d;
	case 3364ULL: goto x86_l_d24;
	case 3366ULL: goto x86_l_d26;
	case 3371ULL: goto x86_l_d2b;
	case 3376ULL: goto x86_l_d30;
	case 3381ULL: goto x86_l_d35;
	case 3386ULL: goto x86_l_d3a;
	case 3391ULL: goto x86_l_d3f;
	case 3393ULL: goto x86_l_d41;
	case 3395ULL: goto x86_l_d43;
	case 3401ULL: goto x86_l_d49;
	case 3408ULL: goto x86_l_d50;
	case 3414ULL: goto x86_l_d56;
	case 3419ULL: goto x86_l_d5b;
	case 3424ULL: goto x86_l_d60;
	case 3429ULL: goto x86_l_d65;
	case 3436ULL: goto x86_l_d6c;
	case 3438ULL: goto x86_l_d6e;
	case 3443ULL: goto x86_l_d73;
	case 3448ULL: goto x86_l_d78;
	case 3453ULL: goto x86_l_d7d;
	case 3458ULL: goto x86_l_d82;
	case 3463ULL: goto x86_l_d87;
	case 3465ULL: goto x86_l_d89;
	case 3467ULL: goto x86_l_d8b;
	case 3473ULL: goto x86_l_d91;
	case 3480ULL: goto x86_l_d98;
	case 3486ULL: goto x86_l_d9e;
	case 3491ULL: goto x86_l_da3;
	case 3496ULL: goto x86_l_da8;
	case 3501ULL: goto x86_l_dad;
	case 3508ULL: goto x86_l_db4;
	case 3510ULL: goto x86_l_db6;
	case 3515ULL: goto x86_l_dbb;
	case 3520ULL: goto x86_l_dc0;
	case 3525ULL: goto x86_l_dc5;
	case 3530ULL: goto x86_l_dca;
	case 3535ULL: goto x86_l_dcf;
	case 3537ULL: goto x86_l_dd1;
	case 3539ULL: goto x86_l_dd3;
	case 3545ULL: goto x86_l_dd9;
	case 3552ULL: goto x86_l_de0;
	case 3558ULL: goto x86_l_de6;
	case 3563ULL: goto x86_l_deb;
	case 3568ULL: goto x86_l_df0;
	case 3573ULL: goto x86_l_df5;
	case 3580ULL: goto x86_l_dfc;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6fb:
	/* 0x6fb: mov    ecx,DWORD PTR [r13+r15*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551554ULL);
x86_l_700:
	/* 0x700: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_705:
	/* 0x705: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_70a:
	/* 0x70a: cmp    WORD PTR [r13+r15*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743824601448448ULL);
x86_l_711:
	/* 0x711: je     731 <generic_sleepable_preload+0x731> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_731;
	}
x86_l_713:
	/* 0x713: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_718:
	/* 0x718: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_71d:
	/* 0x71d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_722:
	/* 0x722: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_727:
	/* 0x727: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_729:
	/* 0x729: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_72b:
	/* 0x72b: js     f6e <generic_sleepable_preload+0xf6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3950ULL;
	}
x86_l_731:
	/* 0x731: cmp    WORD PTR [r13+r15*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743867551121408ULL);
x86_l_738:
	/* 0x738: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
x86_l_73e:
	/* 0x73e: mov    ecx,DWORD PTR [r13+r15*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551562ULL);
x86_l_743:
	/* 0x743: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_748:
	/* 0x748: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_74d:
	/* 0x74d: cmp    WORD PTR [r13+r15*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743858961186816ULL);
x86_l_754:
	/* 0x754: je     774 <generic_sleepable_preload+0x774> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_774;
	}
x86_l_756:
	/* 0x756: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_75b:
	/* 0x75b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_760:
	/* 0x760: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_765:
	/* 0x765: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_76a:
	/* 0x76a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76c:
	/* 0x76c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_76e:
	/* 0x76e: js     f81 <generic_sleepable_preload+0xf81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3969ULL;
	}
x86_l_774:
	/* 0x774: cmp    WORD PTR [r13+r15*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743901910859776ULL);
x86_l_77b:
	/* 0x77b: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
x86_l_781:
	/* 0x781: mov    ecx,DWORD PTR [r13+r15*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551570ULL);
x86_l_786:
	/* 0x786: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_78b:
	/* 0x78b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_790:
	/* 0x790: cmp    WORD PTR [r13+r15*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743893320925184ULL);
x86_l_797:
	/* 0x797: je     7b7 <generic_sleepable_preload+0x7b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7b7;
	}
x86_l_799:
	/* 0x799: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_79e:
	/* 0x79e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7a3:
	/* 0x7a3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7a8:
	/* 0x7a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7ad:
	/* 0x7ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7af:
	/* 0x7af: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7b1:
	/* 0x7b1: js     f94 <generic_sleepable_preload+0xf94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3988ULL;
	}
x86_l_7b7:
	/* 0x7b7: cmp    WORD PTR [r13+r15*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743936270598144ULL);
x86_l_7be:
	/* 0x7be: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
x86_l_7c4:
	/* 0x7c4: mov    ecx,DWORD PTR [r13+r15*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551578ULL);
x86_l_7c9:
	/* 0x7c9: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_7ce:
	/* 0x7ce: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7d3:
	/* 0x7d3: cmp    WORD PTR [r13+r15*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743927680663552ULL);
x86_l_7da:
	/* 0x7da: je     7fa <generic_sleepable_preload+0x7fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7fa;
	}
x86_l_7dc:
	/* 0x7dc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_7e1:
	/* 0x7e1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7e6:
	/* 0x7e6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7eb:
	/* 0x7eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7f0:
	/* 0x7f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f2:
	/* 0x7f2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7f4:
	/* 0x7f4: js     fa7 <generic_sleepable_preload+0xfa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4007ULL;
	}
x86_l_7fa:
	/* 0x7fa: cmp    WORD PTR [r13+r15*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743970630336512ULL);
x86_l_801:
	/* 0x801: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
x86_l_807:
	/* 0x807: mov    ecx,DWORD PTR [r13+r15*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551586ULL);
x86_l_80c:
	/* 0x80c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_811:
	/* 0x811: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_816:
	/* 0x816: cmp    WORD PTR [r13+r15*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743962040401920ULL);
x86_l_81d:
	/* 0x81d: je     83d <generic_sleepable_preload+0x83d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_83d;
	}
x86_l_81f:
	/* 0x81f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_824:
	/* 0x824: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_829:
	/* 0x829: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_82e:
	/* 0x82e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_833:
	/* 0x833: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_835:
	/* 0x835: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_837:
	/* 0x837: js     fba <generic_sleepable_preload+0xfba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4026ULL;
	}
x86_l_83d:
	/* 0x83d: cmp    WORD PTR [r13+r15*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744004990074880ULL);
x86_l_844:
	/* 0x844: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
x86_l_84a:
	/* 0x84a: mov    ecx,DWORD PTR [r13+r15*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551594ULL);
x86_l_84f:
	/* 0x84f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_854:
	/* 0x854: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_859:
	/* 0x859: cmp    WORD PTR [r13+r15*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743996400140288ULL);
x86_l_860:
	/* 0x860: je     880 <generic_sleepable_preload+0x880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_880;
	}
x86_l_862:
	/* 0x862: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_867:
	/* 0x867: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_86c:
	/* 0x86c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_871:
	/* 0x871: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_876:
	/* 0x876: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_878:
	/* 0x878: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_87a:
	/* 0x87a: js     1165 <generic_sleepable_preload+0x1165> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4453ULL;
	}
x86_l_880:
	/* 0x880: cmp    WORD PTR [r13+r15*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744039349813248ULL);
x86_l_887:
	/* 0x887: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
x86_l_88d:
	/* 0x88d: mov    ecx,DWORD PTR [r13+r15*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551602ULL);
x86_l_892:
	/* 0x892: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_897:
	/* 0x897: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_89c:
	/* 0x89c: cmp    WORD PTR [r13+r15*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744030759878656ULL);
x86_l_8a3:
	/* 0x8a3: je     8c3 <generic_sleepable_preload+0x8c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8c3;
	}
x86_l_8a5:
	/* 0x8a5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8aa:
	/* 0x8aa: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8af:
	/* 0x8af: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8b4:
	/* 0x8b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8b9:
	/* 0x8b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8bb:
	/* 0x8bb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8bd:
	/* 0x8bd: js     1194 <generic_sleepable_preload+0x1194> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4500ULL;
	}
x86_l_8c3:
	/* 0x8c3: cmp    WORD PTR [r13+r15*1+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_8ca:
	/* 0x8ca: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
x86_l_8d0:
	/* 0x8d0: mov    ecx,DWORD PTR [r13+r15*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551610ULL);
x86_l_8d5:
	/* 0x8d5: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_8da:
	/* 0x8da: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8df:
	/* 0x8df: cmp    WORD PTR [r13+r15*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744065119617024ULL);
x86_l_8e6:
	/* 0x8e6: je     fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4040ULL;
	}
x86_l_8ec:
	/* 0x8ec: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_8f1:
	/* 0x8f1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8f6:
	/* 0x8f6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8fb:
	/* 0x8fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_900:
	/* 0x900: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_902:
	/* 0x902: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_904:
	/* 0x904: jns    fc8 <generic_sleepable_preload+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 4040ULL;
	}
x86_l_90a:
	/* 0x90a: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_910:
	/* 0x910: jmp    fc0 <generic_sleepable_preload+0xfc0> */
	return 4032ULL;
x86_l_915:
	/* 0x915: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_91b:
	/* 0x91b: jmp    fc0 <generic_sleepable_preload+0xfc0> */
	return 4032ULL;
x86_l_920:
	/* 0x920: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_928:
	/* 0x928: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_92b:
	/* 0x92b: je     996 <generic_sleepable_preload+0x996> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_996;
	}
x86_l_92d:
	/* 0x92d: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_932:
	/* 0x932: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_937:
	/* 0x937: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_93a:
	/* 0x93a: je     996 <generic_sleepable_preload+0x996> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_996;
	}
x86_l_93c:
	/* 0x93c: jmp    9a9 <generic_sleepable_preload+0x9a9> */
	goto x86_l_9a9;
x86_l_93e:
	/* 0x93e: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_946:
	/* 0x946: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_949:
	/* 0x949: je     996 <generic_sleepable_preload+0x996> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_996;
	}
x86_l_94b:
	/* 0x94b: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_950:
	/* 0x950: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_955:
	/* 0x955: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_958:
	/* 0x958: je     996 <generic_sleepable_preload+0x996> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_996;
	}
x86_l_95a:
	/* 0x95a: jmp    9a9 <generic_sleepable_preload+0x9a9> */
	goto x86_l_9a9;
x86_l_95c:
	/* 0x95c: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_964:
	/* 0x964: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_967:
	/* 0x967: je     996 <generic_sleepable_preload+0x996> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_996;
	}
x86_l_969:
	/* 0x969: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_96e:
	/* 0x96e: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_973:
	/* 0x973: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_976:
	/* 0x976: je     996 <generic_sleepable_preload+0x996> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_996;
	}
x86_l_978:
	/* 0x978: jmp    9a9 <generic_sleepable_preload+0x9a9> */
	goto x86_l_9a9;
x86_l_97a:
	/* 0x97a: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_982:
	/* 0x982: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_985:
	/* 0x985: je     996 <generic_sleepable_preload+0x996> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_996;
	}
x86_l_987:
	/* 0x987: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_98c:
	/* 0x98c: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_991:
	/* 0x991: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_994:
	/* 0x994: jne    9a9 <generic_sleepable_preload+0x9a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9a9;
	}
x86_l_996:
	/* 0x996: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_999:
	/* 0x999: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_99b:
	/* 0x99b: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_99d:
	/* 0x99d: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_9a2:
	/* 0x9a2: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_9a4:
	/* 0x9a4: bzhi   rsi,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RSI, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_9a9:
	/* 0x9a9: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9ae:
	/* 0x9ae: mov    ebp,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9b1:
	/* 0x9b1: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9b4:
	/* 0x9b4: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_9b6:
	/* 0x9b6: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_9ba:
	/* 0x9ba: cmp    WORD PTR [r13+r15*1-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743764471906304ULL);
x86_l_9c1:
	/* 0x9c1: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4273ULL;
	}
x86_l_9c7:
	/* 0x9c7: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_9ce:
	/* 0x9ce: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_9d1:
	/* 0x9d1: mov    eax,DWORD PTR [r13+r15*1-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551538ULL);
x86_l_9d6:
	/* 0x9d6: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9d9:
	/* 0x9d9: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9de:
	/* 0x9de: movzx  eax,WORD PTR [r13+r15*1-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R15, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_9e4:
	/* 0x9e4: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_9e6:
	/* 0x9e6: je     c91 <generic_sleepable_preload+0xc91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c91;
	}
x86_l_9ec:
	/* 0x9ec: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_9ef:
	/* 0x9ef: je     a14 <generic_sleepable_preload+0xa14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a14;
	}
x86_l_9f1:
	/* 0x9f1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_9f6:
	/* 0x9f6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9fb:
	/* 0x9fb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a00:
	/* 0xa00: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a05:
	/* 0xa05: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a0a:
	/* 0xa0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0c:
	/* 0xa0c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a0e:
	/* 0xa0e: js     f50 <generic_sleepable_preload+0xf50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3920ULL;
	}
x86_l_a14:
	/* 0xa14: cmp    WORD PTR [r13+r15*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743798831644672ULL);
x86_l_a1b:
	/* 0xa1b: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4273ULL;
	}
x86_l_a21:
	/* 0xa21: mov    ecx,DWORD PTR [r13+r15*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551546ULL);
x86_l_a26:
	/* 0xa26: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a2b:
	/* 0xa2b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a30:
	/* 0xa30: cmp    WORD PTR [r13+r15*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743790241710080ULL);
x86_l_a37:
	/* 0xa37: je     a5c <generic_sleepable_preload+0xa5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a5c;
	}
x86_l_a39:
	/* 0xa39: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a3e:
	/* 0xa3e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a43:
	/* 0xa43: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a48:
	/* 0xa48: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a4d:
	/* 0xa4d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a52:
	/* 0xa52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a54:
	/* 0xa54: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a56:
	/* 0xa56: js     f63 <generic_sleepable_preload+0xf63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3939ULL;
	}
x86_l_a5c:
	/* 0xa5c: cmp    WORD PTR [r13+r15*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743833191383040ULL);
x86_l_a63:
	/* 0xa63: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4273ULL;
	}
x86_l_a69:
	/* 0xa69: mov    ecx,DWORD PTR [r13+r15*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551554ULL);
x86_l_a6e:
	/* 0xa6e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a73:
	/* 0xa73: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a78:
	/* 0xa78: cmp    WORD PTR [r13+r15*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743824601448448ULL);
x86_l_a7f:
	/* 0xa7f: je     aa4 <generic_sleepable_preload+0xaa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_aa4;
	}
x86_l_a81:
	/* 0xa81: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a86:
	/* 0xa86: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a8b:
	/* 0xa8b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a90:
	/* 0xa90: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a95:
	/* 0xa95: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a9a:
	/* 0xa9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a9c:
	/* 0xa9c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a9e:
	/* 0xa9e: js     f76 <generic_sleepable_preload+0xf76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3958ULL;
	}
x86_l_aa4:
	/* 0xaa4: cmp    WORD PTR [r13+r15*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743867551121408ULL);
x86_l_aab:
	/* 0xaab: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4273ULL;
	}
x86_l_ab1:
	/* 0xab1: mov    ecx,DWORD PTR [r13+r15*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551562ULL);
x86_l_ab6:
	/* 0xab6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_abb:
	/* 0xabb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ac0:
	/* 0xac0: cmp    WORD PTR [r13+r15*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743858961186816ULL);
x86_l_ac7:
	/* 0xac7: je     aec <generic_sleepable_preload+0xaec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_aec;
	}
x86_l_ac9:
	/* 0xac9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ace:
	/* 0xace: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ad3:
	/* 0xad3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ad8:
	/* 0xad8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_add:
	/* 0xadd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ae2:
	/* 0xae2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae4:
	/* 0xae4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ae6:
	/* 0xae6: js     f89 <generic_sleepable_preload+0xf89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3977ULL;
	}
x86_l_aec:
	/* 0xaec: cmp    WORD PTR [r13+r15*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743901910859776ULL);
x86_l_af3:
	/* 0xaf3: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4273ULL;
	}
x86_l_af9:
	/* 0xaf9: mov    ecx,DWORD PTR [r13+r15*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551570ULL);
x86_l_afe:
	/* 0xafe: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b03:
	/* 0xb03: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b08:
	/* 0xb08: cmp    WORD PTR [r13+r15*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743893320925184ULL);
x86_l_b0f:
	/* 0xb0f: je     b34 <generic_sleepable_preload+0xb34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b34;
	}
x86_l_b11:
	/* 0xb11: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b16:
	/* 0xb16: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b1b:
	/* 0xb1b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b20:
	/* 0xb20: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b25:
	/* 0xb25: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b2a:
	/* 0xb2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b2c:
	/* 0xb2c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b2e:
	/* 0xb2e: js     f9c <generic_sleepable_preload+0xf9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3996ULL;
	}
x86_l_b34:
	/* 0xb34: cmp    WORD PTR [r13+r15*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743936270598144ULL);
x86_l_b3b:
	/* 0xb3b: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4273ULL;
	}
x86_l_b41:
	/* 0xb41: mov    ecx,DWORD PTR [r13+r15*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551578ULL);
x86_l_b46:
	/* 0xb46: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b4b:
	/* 0xb4b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b50:
	/* 0xb50: cmp    WORD PTR [r13+r15*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743927680663552ULL);
x86_l_b57:
	/* 0xb57: je     b7c <generic_sleepable_preload+0xb7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b7c;
	}
x86_l_b59:
	/* 0xb59: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b5e:
	/* 0xb5e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b63:
	/* 0xb63: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b68:
	/* 0xb68: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b6d:
	/* 0xb6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b72:
	/* 0xb72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b74:
	/* 0xb74: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b76:
	/* 0xb76: js     faf <generic_sleepable_preload+0xfaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4015ULL;
	}
x86_l_b7c:
	/* 0xb7c: cmp    WORD PTR [r13+r15*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743970630336512ULL);
x86_l_b83:
	/* 0xb83: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4273ULL;
	}
x86_l_b89:
	/* 0xb89: mov    ecx,DWORD PTR [r13+r15*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551586ULL);
x86_l_b8e:
	/* 0xb8e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b93:
	/* 0xb93: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b98:
	/* 0xb98: cmp    WORD PTR [r13+r15*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743962040401920ULL);
x86_l_b9f:
	/* 0xb9f: je     bc4 <generic_sleepable_preload+0xbc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bc4;
	}
x86_l_ba1:
	/* 0xba1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ba6:
	/* 0xba6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_bab:
	/* 0xbab: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bb0:
	/* 0xbb0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bb5:
	/* 0xbb5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bba:
	/* 0xbba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bbc:
	/* 0xbbc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bbe:
	/* 0xbbe: js     10a3 <generic_sleepable_preload+0x10a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4259ULL;
	}
x86_l_bc4:
	/* 0xbc4: cmp    WORD PTR [r13+r15*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744004990074880ULL);
x86_l_bcb:
	/* 0xbcb: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4273ULL;
	}
x86_l_bd1:
	/* 0xbd1: mov    ecx,DWORD PTR [r13+r15*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551594ULL);
x86_l_bd6:
	/* 0xbd6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_bdb:
	/* 0xbdb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_be0:
	/* 0xbe0: cmp    WORD PTR [r13+r15*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743996400140288ULL);
x86_l_be7:
	/* 0xbe7: je     c0c <generic_sleepable_preload+0xc0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c0c;
	}
x86_l_be9:
	/* 0xbe9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_bee:
	/* 0xbee: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_bf3:
	/* 0xbf3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bf8:
	/* 0xbf8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bfd:
	/* 0xbfd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c02:
	/* 0xc02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c04:
	/* 0xc04: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c06:
	/* 0xc06: js     1178 <generic_sleepable_preload+0x1178> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4472ULL;
	}
x86_l_c0c:
	/* 0xc0c: cmp    WORD PTR [r13+r15*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744039349813248ULL);
x86_l_c13:
	/* 0xc13: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4273ULL;
	}
x86_l_c19:
	/* 0xc19: mov    ecx,DWORD PTR [r13+r15*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551602ULL);
x86_l_c1e:
	/* 0xc1e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c23:
	/* 0xc23: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c28:
	/* 0xc28: cmp    WORD PTR [r13+r15*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744030759878656ULL);
x86_l_c2f:
	/* 0xc2f: je     c54 <generic_sleepable_preload+0xc54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c54;
	}
x86_l_c31:
	/* 0xc31: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c36:
	/* 0xc36: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c3b:
	/* 0xc3b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c40:
	/* 0xc40: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c45:
	/* 0xc45: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c4a:
	/* 0xc4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c4c:
	/* 0xc4c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c4e:
	/* 0xc4e: js     119f <generic_sleepable_preload+0x119f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4511ULL;
	}
x86_l_c54:
	/* 0xc54: cmp    WORD PTR [r13+r15*1+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_c5b:
	/* 0xc5b: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4273ULL;
	}
x86_l_c61:
	/* 0xc61: mov    ecx,DWORD PTR [r13+r15*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551610ULL);
x86_l_c66:
	/* 0xc66: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c6b:
	/* 0xc6b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c70:
	/* 0xc70: cmp    WORD PTR [r13+r15*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744065119617024ULL);
x86_l_c77:
	/* 0xc77: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4273ULL;
	}
x86_l_c7d:
	/* 0xc7d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c82:
	/* 0xc82: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c87:
	/* 0xc87: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c8c:
	/* 0xc8c: jmp    f31 <generic_sleepable_preload+0xf31> */
	return 3889ULL;
x86_l_c91:
	/* 0xc91: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_c94:
	/* 0xc94: je     cb9 <generic_sleepable_preload+0xcb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cb9;
	}
x86_l_c96:
	/* 0xc96: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c9b:
	/* 0xc9b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ca0:
	/* 0xca0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ca5:
	/* 0xca5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_caa:
	/* 0xcaa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_caf:
	/* 0xcaf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cb1:
	/* 0xcb1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cb3:
	/* 0xcb3: js     f50 <generic_sleepable_preload+0xf50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3920ULL;
	}
x86_l_cb9:
	/* 0xcb9: cmp    WORD PTR [r13+r15*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743798831644672ULL);
x86_l_cc0:
	/* 0xcc0: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4273ULL;
	}
x86_l_cc6:
	/* 0xcc6: mov    ecx,DWORD PTR [r13+r15*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551546ULL);
x86_l_ccb:
	/* 0xccb: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_cd0:
	/* 0xcd0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cd5:
	/* 0xcd5: cmp    WORD PTR [r13+r15*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743790241710080ULL);
x86_l_cdc:
	/* 0xcdc: je     d01 <generic_sleepable_preload+0xd01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d01;
	}
x86_l_cde:
	/* 0xcde: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ce3:
	/* 0xce3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ce8:
	/* 0xce8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ced:
	/* 0xced: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cf2:
	/* 0xcf2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cf7:
	/* 0xcf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf9:
	/* 0xcf9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cfb:
	/* 0xcfb: js     f63 <generic_sleepable_preload+0xf63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3939ULL;
	}
x86_l_d01:
	/* 0xd01: cmp    WORD PTR [r13+r15*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743833191383040ULL);
x86_l_d08:
	/* 0xd08: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4273ULL;
	}
x86_l_d0e:
	/* 0xd0e: mov    ecx,DWORD PTR [r13+r15*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551554ULL);
x86_l_d13:
	/* 0xd13: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d18:
	/* 0xd18: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d1d:
	/* 0xd1d: cmp    WORD PTR [r13+r15*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743824601448448ULL);
x86_l_d24:
	/* 0xd24: je     d49 <generic_sleepable_preload+0xd49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d49;
	}
x86_l_d26:
	/* 0xd26: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d2b:
	/* 0xd2b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d30:
	/* 0xd30: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d35:
	/* 0xd35: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d3a:
	/* 0xd3a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d3f:
	/* 0xd3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d41:
	/* 0xd41: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d43:
	/* 0xd43: js     f76 <generic_sleepable_preload+0xf76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3958ULL;
	}
x86_l_d49:
	/* 0xd49: cmp    WORD PTR [r13+r15*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743867551121408ULL);
x86_l_d50:
	/* 0xd50: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4273ULL;
	}
x86_l_d56:
	/* 0xd56: mov    ecx,DWORD PTR [r13+r15*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551562ULL);
x86_l_d5b:
	/* 0xd5b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d60:
	/* 0xd60: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d65:
	/* 0xd65: cmp    WORD PTR [r13+r15*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743858961186816ULL);
x86_l_d6c:
	/* 0xd6c: je     d91 <generic_sleepable_preload+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d91;
	}
x86_l_d6e:
	/* 0xd6e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d73:
	/* 0xd73: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d78:
	/* 0xd78: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d7d:
	/* 0xd7d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d82:
	/* 0xd82: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d87:
	/* 0xd87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d89:
	/* 0xd89: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d8b:
	/* 0xd8b: js     f89 <generic_sleepable_preload+0xf89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3977ULL;
	}
x86_l_d91:
	/* 0xd91: cmp    WORD PTR [r13+r15*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743901910859776ULL);
x86_l_d98:
	/* 0xd98: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4273ULL;
	}
x86_l_d9e:
	/* 0xd9e: mov    ecx,DWORD PTR [r13+r15*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551570ULL);
x86_l_da3:
	/* 0xda3: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_da8:
	/* 0xda8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dad:
	/* 0xdad: cmp    WORD PTR [r13+r15*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743893320925184ULL);
x86_l_db4:
	/* 0xdb4: je     dd9 <generic_sleepable_preload+0xdd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dd9;
	}
x86_l_db6:
	/* 0xdb6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_dbb:
	/* 0xdbb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_dc0:
	/* 0xdc0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dc5:
	/* 0xdc5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dca:
	/* 0xdca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dcf:
	/* 0xdcf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd1:
	/* 0xdd1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dd3:
	/* 0xdd3: js     f9c <generic_sleepable_preload+0xf9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3996ULL;
	}
x86_l_dd9:
	/* 0xdd9: cmp    WORD PTR [r13+r15*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743936270598144ULL);
x86_l_de0:
	/* 0xde0: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4273ULL;
	}
x86_l_de6:
	/* 0xde6: mov    ecx,DWORD PTR [r13+r15*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551578ULL);
x86_l_deb:
	/* 0xdeb: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_df0:
	/* 0xdf0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_df5:
	/* 0xdf5: cmp    WORD PTR [r13+r15*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743927680663552ULL);
x86_l_dfc:
	/* 0xdfc: je     e21 <generic_sleepable_preload+0xe21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3617ULL;
	}
	return 3582ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3582ULL: goto x86_l_dfe;
	case 3587ULL: goto x86_l_e03;
	case 3592ULL: goto x86_l_e08;
	case 3597ULL: goto x86_l_e0d;
	case 3602ULL: goto x86_l_e12;
	case 3607ULL: goto x86_l_e17;
	case 3609ULL: goto x86_l_e19;
	case 3611ULL: goto x86_l_e1b;
	case 3617ULL: goto x86_l_e21;
	case 3624ULL: goto x86_l_e28;
	case 3630ULL: goto x86_l_e2e;
	case 3635ULL: goto x86_l_e33;
	case 3640ULL: goto x86_l_e38;
	case 3645ULL: goto x86_l_e3d;
	case 3652ULL: goto x86_l_e44;
	case 3654ULL: goto x86_l_e46;
	case 3659ULL: goto x86_l_e4b;
	case 3664ULL: goto x86_l_e50;
	case 3669ULL: goto x86_l_e55;
	case 3674ULL: goto x86_l_e5a;
	case 3679ULL: goto x86_l_e5f;
	case 3681ULL: goto x86_l_e61;
	case 3683ULL: goto x86_l_e63;
	case 3689ULL: goto x86_l_e69;
	case 3696ULL: goto x86_l_e70;
	case 3702ULL: goto x86_l_e76;
	case 3707ULL: goto x86_l_e7b;
	case 3712ULL: goto x86_l_e80;
	case 3717ULL: goto x86_l_e85;
	case 3724ULL: goto x86_l_e8c;
	case 3726ULL: goto x86_l_e8e;
	case 3731ULL: goto x86_l_e93;
	case 3736ULL: goto x86_l_e98;
	case 3741ULL: goto x86_l_e9d;
	case 3746ULL: goto x86_l_ea2;
	case 3751ULL: goto x86_l_ea7;
	case 3753ULL: goto x86_l_ea9;
	case 3755ULL: goto x86_l_eab;
	case 3761ULL: goto x86_l_eb1;
	case 3768ULL: goto x86_l_eb8;
	case 3774ULL: goto x86_l_ebe;
	case 3779ULL: goto x86_l_ec3;
	case 3784ULL: goto x86_l_ec8;
	case 3789ULL: goto x86_l_ecd;
	case 3796ULL: goto x86_l_ed4;
	case 3798ULL: goto x86_l_ed6;
	case 3803ULL: goto x86_l_edb;
	case 3808ULL: goto x86_l_ee0;
	case 3813ULL: goto x86_l_ee5;
	case 3818ULL: goto x86_l_eea;
	case 3823ULL: goto x86_l_eef;
	case 3825ULL: goto x86_l_ef1;
	case 3827ULL: goto x86_l_ef3;
	case 3833ULL: goto x86_l_ef9;
	case 3840ULL: goto x86_l_f00;
	case 3846ULL: goto x86_l_f06;
	case 3851ULL: goto x86_l_f0b;
	case 3856ULL: goto x86_l_f10;
	case 3861ULL: goto x86_l_f15;
	case 3868ULL: goto x86_l_f1c;
	case 3874ULL: goto x86_l_f22;
	case 3879ULL: goto x86_l_f27;
	case 3884ULL: goto x86_l_f2c;
	case 3889ULL: goto x86_l_f31;
	case 3894ULL: goto x86_l_f36;
	case 3899ULL: goto x86_l_f3b;
	case 3901ULL: goto x86_l_f3d;
	case 3903ULL: goto x86_l_f3f;
	case 3909ULL: goto x86_l_f45;
	case 3915ULL: goto x86_l_f4b;
	case 3920ULL: goto x86_l_f50;
	case 3926ULL: goto x86_l_f56;
	case 3931ULL: goto x86_l_f5b;
	case 3937ULL: goto x86_l_f61;
	case 3939ULL: goto x86_l_f63;
	case 3945ULL: goto x86_l_f69;
	case 3950ULL: goto x86_l_f6e;
	case 3956ULL: goto x86_l_f74;
	case 3958ULL: goto x86_l_f76;
	case 3964ULL: goto x86_l_f7c;
	case 3969ULL: goto x86_l_f81;
	case 3975ULL: goto x86_l_f87;
	case 3977ULL: goto x86_l_f89;
	case 3983ULL: goto x86_l_f8f;
	case 3988ULL: goto x86_l_f94;
	case 3994ULL: goto x86_l_f9a;
	case 3996ULL: goto x86_l_f9c;
	case 4002ULL: goto x86_l_fa2;
	case 4007ULL: goto x86_l_fa7;
	case 4013ULL: goto x86_l_fad;
	case 4015ULL: goto x86_l_faf;
	case 4021ULL: goto x86_l_fb5;
	case 4026ULL: goto x86_l_fba;
	case 4032ULL: goto x86_l_fc0;
	case 4040ULL: goto x86_l_fc8;
	case 4043ULL: goto x86_l_fcb;
	case 4048ULL: goto x86_l_fd0;
	case 4053ULL: goto x86_l_fd5;
	case 4058ULL: goto x86_l_fda;
	case 4061ULL: goto x86_l_fdd;
	case 4063ULL: goto x86_l_fdf;
	case 4067ULL: goto x86_l_fe3;
	case 4073ULL: goto x86_l_fe9;
	case 4078ULL: goto x86_l_fee;
	case 4086ULL: goto x86_l_ff6;
	case 4091ULL: goto x86_l_ffb;
	case 4093ULL: goto x86_l_ffd;
	case 4098ULL: goto x86_l_1002;
	case 4106ULL: goto x86_l_100a;
	case 4111ULL: goto x86_l_100f;
	case 4118ULL: goto x86_l_1016;
	case 4123ULL: goto x86_l_101b;
	case 4125ULL: goto x86_l_101d;
	case 4128ULL: goto x86_l_1020;
	case 4134ULL: goto x86_l_1026;
	case 4137ULL: goto x86_l_1029;
	case 4142ULL: goto x86_l_102e;
	case 4144ULL: goto x86_l_1030;
	case 4149ULL: goto x86_l_1035;
	case 4152ULL: goto x86_l_1038;
	case 4159ULL: goto x86_l_103f;
	case 4162ULL: goto x86_l_1042;
	case 4165ULL: goto x86_l_1045;
	case 4167ULL: goto x86_l_1047;
	case 4169ULL: goto x86_l_1049;
	case 4174ULL: goto x86_l_104e;
	case 4177ULL: goto x86_l_1051;
	case 4180ULL: goto x86_l_1054;
	case 4183ULL: goto x86_l_1057;
	case 4185ULL: goto x86_l_1059;
	case 4188ULL: goto x86_l_105c;
	case 4194ULL: goto x86_l_1062;
	case 4199ULL: goto x86_l_1067;
	case 4205ULL: goto x86_l_106d;
	case 4209ULL: goto x86_l_1071;
	case 4214ULL: goto x86_l_1076;
	case 4222ULL: goto x86_l_107e;
	case 4224ULL: goto x86_l_1080;
	case 4227ULL: goto x86_l_1083;
	case 4232ULL: goto x86_l_1088;
	case 4234ULL: goto x86_l_108a;
	case 4237ULL: goto x86_l_108d;
	case 4240ULL: goto x86_l_1090;
	case 4242ULL: goto x86_l_1092;
	case 4248ULL: goto x86_l_1098;
	case 4254ULL: goto x86_l_109e;
	case 4259ULL: goto x86_l_10a3;
	case 4265ULL: goto x86_l_10a9;
	case 4273ULL: goto x86_l_10b1;
	case 4276ULL: goto x86_l_10b4;
	case 4282ULL: goto x86_l_10ba;
	case 4287ULL: goto x86_l_10bf;
	case 4295ULL: goto x86_l_10c7;
	case 4300ULL: goto x86_l_10cc;
	case 4302ULL: goto x86_l_10ce;
	case 4307ULL: goto x86_l_10d3;
	case 4315ULL: goto x86_l_10db;
	case 4320ULL: goto x86_l_10e0;
	case 4327ULL: goto x86_l_10e7;
	case 4332ULL: goto x86_l_10ec;
	case 4334ULL: goto x86_l_10ee;
	case 4337ULL: goto x86_l_10f1;
	case 4343ULL: goto x86_l_10f7;
	case 4346ULL: goto x86_l_10fa;
	case 4351ULL: goto x86_l_10ff;
	case 4353ULL: goto x86_l_1101;
	case 4358ULL: goto x86_l_1106;
	case 4361ULL: goto x86_l_1109;
	case 4368ULL: goto x86_l_1110;
	case 4371ULL: goto x86_l_1113;
	case 4374ULL: goto x86_l_1116;
	case 4376ULL: goto x86_l_1118;
	case 4378ULL: goto x86_l_111a;
	case 4383ULL: goto x86_l_111f;
	case 4386ULL: goto x86_l_1122;
	case 4389ULL: goto x86_l_1125;
	case 4391ULL: goto x86_l_1127;
	case 4394ULL: goto x86_l_112a;
	case 4400ULL: goto x86_l_1130;
	case 4403ULL: goto x86_l_1133;
	case 4408ULL: goto x86_l_1138;
	case 4410ULL: goto x86_l_113a;
	case 4414ULL: goto x86_l_113e;
	case 4419ULL: goto x86_l_1143;
	case 4427ULL: goto x86_l_114b;
	case 4429ULL: goto x86_l_114d;
	case 4434ULL: goto x86_l_1152;
	case 4436ULL: goto x86_l_1154;
	case 4438ULL: goto x86_l_1156;
	case 4444ULL: goto x86_l_115c;
	case 4448ULL: goto x86_l_1160;
	case 4453ULL: goto x86_l_1165;
	case 4461ULL: goto x86_l_116d;
	case 4467ULL: goto x86_l_1173;
	case 4472ULL: goto x86_l_1178;
	case 4480ULL: goto x86_l_1180;
	case 4486ULL: goto x86_l_1186;
	case 4489ULL: goto x86_l_1189;
	case 4495ULL: goto x86_l_118f;
	case 4500ULL: goto x86_l_1194;
	case 4506ULL: goto x86_l_119a;
	case 4511ULL: goto x86_l_119f;
	case 4517ULL: goto x86_l_11a5;
	case 4522ULL: goto x86_l_11aa;
	case 4526ULL: goto x86_l_11ae;
	case 4531ULL: goto x86_l_11b3;
	case 4533ULL: goto x86_l_11b5;
	case 4537ULL: goto x86_l_11b9;
	case 4542ULL: goto x86_l_11be;
	case 4548ULL: goto x86_l_11c4;
	case 4552ULL: goto x86_l_11c8;
	case 4557ULL: goto x86_l_11cd;
	case 4562ULL: goto x86_l_11d2;
	case 4568ULL: goto x86_l_11d8;
	case 4572ULL: goto x86_l_11dc;
	case 4577ULL: goto x86_l_11e1;
	case 4583ULL: goto x86_l_11e7;
	case 4587ULL: goto x86_l_11eb;
	case 4592ULL: goto x86_l_11f0;
	case 4598ULL: goto x86_l_11f6;
	case 4600ULL: goto x86_l_11f8;
	case 4607ULL: goto x86_l_11ff;
	case 4609ULL: goto x86_l_1201;
	case 4610ULL: goto x86_l_1202;
	case 4615ULL: goto x86_l_1207;
	case 4617ULL: goto x86_l_1209;
	case 4623ULL: goto x86_l_120f;
	case 4631ULL: goto x86_l_1217;
	case 4633ULL: goto x86_l_1219;
	case 4636ULL: goto x86_l_121c;
	case 4642ULL: goto x86_l_1222;
	case 4645ULL: goto x86_l_1225;
	case 4651ULL: goto x86_l_122b;
	case 4654ULL: goto x86_l_122e;
	case 4660ULL: goto x86_l_1234;
	case 4667ULL: goto x86_l_123b;
	case 4673ULL: goto x86_l_1241;
	case 4676ULL: goto x86_l_1244;
	case 4681ULL: goto x86_l_1249;
	case 4686ULL: goto x86_l_124e;
	case 4691ULL: goto x86_l_1253;
	case 4696ULL: goto x86_l_1258;
	case 4698ULL: goto x86_l_125a;
	case 4700ULL: goto x86_l_125c;
	case 4706ULL: goto x86_l_1262;
	case 4708ULL: goto x86_l_1264;
	case 4713ULL: goto x86_l_1269;
	case 4715ULL: goto x86_l_126b;
	case 4721ULL: goto x86_l_1271;
	case 4729ULL: goto x86_l_1279;
	case 4731ULL: goto x86_l_127b;
	case 4734ULL: goto x86_l_127e;
	case 4740ULL: goto x86_l_1284;
	case 4743ULL: goto x86_l_1287;
	case 4749ULL: goto x86_l_128d;
	case 4752ULL: goto x86_l_1290;
	case 4758ULL: goto x86_l_1296;
	case 4765ULL: goto x86_l_129d;
	case 4771ULL: goto x86_l_12a3;
	case 4774ULL: goto x86_l_12a6;
	case 4779ULL: goto x86_l_12ab;
	case 4784ULL: goto x86_l_12b0;
	case 4789ULL: goto x86_l_12b5;
	case 4794ULL: goto x86_l_12ba;
	case 4796ULL: goto x86_l_12bc;
	case 4798ULL: goto x86_l_12be;
	case 4804ULL: goto x86_l_12c4;
	case 4806ULL: goto x86_l_12c6;
	case 4811ULL: goto x86_l_12cb;
	case 4813ULL: goto x86_l_12cd;
	case 4819ULL: goto x86_l_12d3;
	case 4827ULL: goto x86_l_12db;
	case 4829ULL: goto x86_l_12dd;
	case 4832ULL: goto x86_l_12e0;
	case 4838ULL: goto x86_l_12e6;
	case 4841ULL: goto x86_l_12e9;
	case 4846ULL: goto x86_l_12ee;
	case 4852ULL: goto x86_l_12f4;
	case 4855ULL: goto x86_l_12f7;
	case 4861ULL: goto x86_l_12fd;
	case 4868ULL: goto x86_l_1304;
	case 4874ULL: goto x86_l_130a;
	case 4877ULL: goto x86_l_130d;
	case 4882ULL: goto x86_l_1312;
	case 4887ULL: goto x86_l_1317;
	case 4892ULL: goto x86_l_131c;
	case 4897ULL: goto x86_l_1321;
	case 4899ULL: goto x86_l_1323;
	case 4901ULL: goto x86_l_1325;
	case 4907ULL: goto x86_l_132b;
	case 4909ULL: goto x86_l_132d;
	case 4914ULL: goto x86_l_1332;
	case 4916ULL: goto x86_l_1334;
	case 4922ULL: goto x86_l_133a;
	case 4930ULL: goto x86_l_1342;
	case 4932ULL: goto x86_l_1344;
	case 4935ULL: goto x86_l_1347;
	case 4940ULL: goto x86_l_134c;
	case 4946ULL: goto x86_l_1352;
	case 4949ULL: goto x86_l_1355;
	case 4955ULL: goto x86_l_135b;
	case 4958ULL: goto x86_l_135e;
	case 4964ULL: goto x86_l_1364;
	case 4971ULL: goto x86_l_136b;
	case 4977ULL: goto x86_l_1371;
	case 4980ULL: goto x86_l_1374;
	case 4985ULL: goto x86_l_1379;
	case 4990ULL: goto x86_l_137e;
	case 4995ULL: goto x86_l_1383;
	case 5000ULL: goto x86_l_1388;
	case 5002ULL: goto x86_l_138a;
	case 5004ULL: goto x86_l_138c;
	case 5010ULL: goto x86_l_1392;
	case 5012ULL: goto x86_l_1394;
	case 5017ULL: goto x86_l_1399;
	case 5019ULL: goto x86_l_139b;
	case 5025ULL: goto x86_l_13a1;
	case 5033ULL: goto x86_l_13a9;
	case 5035ULL: goto x86_l_13ab;
	case 5038ULL: goto x86_l_13ae;
	case 5044ULL: goto x86_l_13b4;
	case 5047ULL: goto x86_l_13b7;
	case 5052ULL: goto x86_l_13bc;
	case 5058ULL: goto x86_l_13c2;
	case 5061ULL: goto x86_l_13c5;
	case 5067ULL: goto x86_l_13cb;
	case 5074ULL: goto x86_l_13d2;
	case 5079ULL: goto x86_l_13d7;
	case 5082ULL: goto x86_l_13da;
	case 5087ULL: goto x86_l_13df;
	case 5092ULL: goto x86_l_13e4;
	case 5097ULL: goto x86_l_13e9;
	case 5102ULL: goto x86_l_13ee;
	case 5104ULL: goto x86_l_13f0;
	case 5106ULL: goto x86_l_13f2;
	case 5112ULL: goto x86_l_13f8;
	case 5114ULL: goto x86_l_13fa;
	case 5119ULL: goto x86_l_13ff;
	case 5127ULL: goto x86_l_1407;
	case 5135ULL: goto x86_l_140f;
	case 5141ULL: goto x86_l_1415;
	case 5143ULL: goto x86_l_1417;
	case 5146ULL: goto x86_l_141a;
	case 5152ULL: goto x86_l_1420;
	case 5155ULL: goto x86_l_1423;
	case 5161ULL: goto x86_l_1429;
	case 5164ULL: goto x86_l_142c;
	case 5170ULL: goto x86_l_1432;
	case 5178ULL: goto x86_l_143a;
	case 5181ULL: goto x86_l_143d;
	case 5187ULL: goto x86_l_1443;
	case 5192ULL: goto x86_l_1448;
	case 5195ULL: goto x86_l_144b;
	case 5201ULL: goto x86_l_1451;
	case 5204ULL: goto x86_l_1454;
	case 5210ULL: goto x86_l_145a;
	case 5215ULL: goto x86_l_145f;
	case 5220ULL: goto x86_l_1464;
	case 5228ULL: goto x86_l_146c;
	case 5236ULL: goto x86_l_1474;
	case 5242ULL: goto x86_l_147a;
	case 5244ULL: goto x86_l_147c;
	case 5247ULL: goto x86_l_147f;
	case 5253ULL: goto x86_l_1485;
	case 5256ULL: goto x86_l_1488;
	case 5262ULL: goto x86_l_148e;
	case 5265ULL: goto x86_l_1491;
	case 5271ULL: goto x86_l_1497;
	case 5279ULL: goto x86_l_149f;
	case 5282ULL: goto x86_l_14a2;
	case 5288ULL: goto x86_l_14a8;
	case 5293ULL: goto x86_l_14ad;
	case 5296ULL: goto x86_l_14b0;
	case 5302ULL: goto x86_l_14b6;
	case 5307ULL: goto x86_l_14bb;
	case 5310ULL: goto x86_l_14be;
	case 5316ULL: goto x86_l_14c4;
	case 5321ULL: goto x86_l_14c9;
	case 5329ULL: goto x86_l_14d1;
	case 5337ULL: goto x86_l_14d9;
	case 5343ULL: goto x86_l_14df;
	case 5345ULL: goto x86_l_14e1;
	case 5348ULL: goto x86_l_14e4;
	case 5354ULL: goto x86_l_14ea;
	default: return 0xffffffffffffffffULL;
	}
x86_l_dfe:
	/* 0xdfe: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e03:
	/* 0xe03: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e08:
	/* 0xe08: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e0d:
	/* 0xe0d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e12:
	/* 0xe12: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e17:
	/* 0xe17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e19:
	/* 0xe19: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e1b:
	/* 0xe1b: js     faf <generic_sleepable_preload+0xfaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_faf;
	}
x86_l_e21:
	/* 0xe21: cmp    WORD PTR [r13+r15*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743970630336512ULL);
x86_l_e28:
	/* 0xe28: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b1;
	}
x86_l_e2e:
	/* 0xe2e: mov    ecx,DWORD PTR [r13+r15*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551586ULL);
x86_l_e33:
	/* 0xe33: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e38:
	/* 0xe38: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e3d:
	/* 0xe3d: cmp    WORD PTR [r13+r15*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743962040401920ULL);
x86_l_e44:
	/* 0xe44: je     e69 <generic_sleepable_preload+0xe69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e69;
	}
x86_l_e46:
	/* 0xe46: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e4b:
	/* 0xe4b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e50:
	/* 0xe50: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e55:
	/* 0xe55: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e5a:
	/* 0xe5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e5f:
	/* 0xe5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e61:
	/* 0xe61: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e63:
	/* 0xe63: js     10a3 <generic_sleepable_preload+0x10a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_10a3;
	}
x86_l_e69:
	/* 0xe69: cmp    WORD PTR [r13+r15*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744004990074880ULL);
x86_l_e70:
	/* 0xe70: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b1;
	}
x86_l_e76:
	/* 0xe76: mov    ecx,DWORD PTR [r13+r15*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551594ULL);
x86_l_e7b:
	/* 0xe7b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e80:
	/* 0xe80: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e85:
	/* 0xe85: cmp    WORD PTR [r13+r15*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446743996400140288ULL);
x86_l_e8c:
	/* 0xe8c: je     eb1 <generic_sleepable_preload+0xeb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eb1;
	}
x86_l_e8e:
	/* 0xe8e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e93:
	/* 0xe93: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e98:
	/* 0xe98: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e9d:
	/* 0xe9d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ea2:
	/* 0xea2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ea7:
	/* 0xea7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea9:
	/* 0xea9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_eab:
	/* 0xeab: js     1178 <generic_sleepable_preload+0x1178> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1178;
	}
x86_l_eb1:
	/* 0xeb1: cmp    WORD PTR [r13+r15*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744039349813248ULL);
x86_l_eb8:
	/* 0xeb8: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b1;
	}
x86_l_ebe:
	/* 0xebe: mov    ecx,DWORD PTR [r13+r15*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551602ULL);
x86_l_ec3:
	/* 0xec3: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ec8:
	/* 0xec8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ecd:
	/* 0xecd: cmp    WORD PTR [r13+r15*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744030759878656ULL);
x86_l_ed4:
	/* 0xed4: je     ef9 <generic_sleepable_preload+0xef9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ef9;
	}
x86_l_ed6:
	/* 0xed6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_edb:
	/* 0xedb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ee0:
	/* 0xee0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ee5:
	/* 0xee5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eea:
	/* 0xeea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_eef:
	/* 0xeef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef1:
	/* 0xef1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ef3:
	/* 0xef3: js     119f <generic_sleepable_preload+0x119f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_119f;
	}
x86_l_ef9:
	/* 0xef9: cmp    WORD PTR [r13+r15*1+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_f00:
	/* 0xf00: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b1;
	}
x86_l_f06:
	/* 0xf06: mov    ecx,DWORD PTR [r13+r15*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 18446744073709551610ULL);
x86_l_f0b:
	/* 0xf0b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_f10:
	/* 0xf10: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f15:
	/* 0xf15: cmp    WORD PTR [r13+r15*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 18446744065119617024ULL);
x86_l_f1c:
	/* 0xf1c: je     10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b1;
	}
x86_l_f22:
	/* 0xf22: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_f27:
	/* 0xf27: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_f2c:
	/* 0xf2c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f31:
	/* 0xf31: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f36:
	/* 0xf36: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f3b:
	/* 0xf3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f3d:
	/* 0xf3d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f3f:
	/* 0xf3f: jns    10b1 <generic_sleepable_preload+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_10b1;
	}
x86_l_f45:
	/* 0xf45: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_f4b:
	/* 0xf4b: jmp    10a9 <generic_sleepable_preload+0x10a9> */
	goto x86_l_10a9;
x86_l_f50:
	/* 0xf50: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_f56:
	/* 0xf56: jmp    10a9 <generic_sleepable_preload+0x10a9> */
	goto x86_l_10a9;
x86_l_f5b:
	/* 0xf5b: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_f61:
	/* 0xf61: jmp    fc0 <generic_sleepable_preload+0xfc0> */
	goto x86_l_fc0;
x86_l_f63:
	/* 0xf63: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_f69:
	/* 0xf69: jmp    10a9 <generic_sleepable_preload+0x10a9> */
	goto x86_l_10a9;
x86_l_f6e:
	/* 0xf6e: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_f74:
	/* 0xf74: jmp    fc0 <generic_sleepable_preload+0xfc0> */
	goto x86_l_fc0;
x86_l_f76:
	/* 0xf76: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_f7c:
	/* 0xf7c: jmp    10a9 <generic_sleepable_preload+0x10a9> */
	goto x86_l_10a9;
x86_l_f81:
	/* 0xf81: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_f87:
	/* 0xf87: jmp    fc0 <generic_sleepable_preload+0xfc0> */
	goto x86_l_fc0;
x86_l_f89:
	/* 0xf89: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_f8f:
	/* 0xf8f: jmp    10a9 <generic_sleepable_preload+0x10a9> */
	goto x86_l_10a9;
x86_l_f94:
	/* 0xf94: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_f9a:
	/* 0xf9a: jmp    fc0 <generic_sleepable_preload+0xfc0> */
	goto x86_l_fc0;
x86_l_f9c:
	/* 0xf9c: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_fa2:
	/* 0xfa2: jmp    10a9 <generic_sleepable_preload+0x10a9> */
	goto x86_l_10a9;
x86_l_fa7:
	/* 0xfa7: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_fad:
	/* 0xfad: jmp    fc0 <generic_sleepable_preload+0xfc0> */
	goto x86_l_fc0;
x86_l_faf:
	/* 0xfaf: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_fb5:
	/* 0xfb5: jmp    10a9 <generic_sleepable_preload+0x10a9> */
	goto x86_l_10a9;
x86_l_fba:
	/* 0xfba: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_fc0:
	/* 0xfc0: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_fc8:
	/* 0xfc8: mov    r13d,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fcb:
	/* 0xfcb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fd0:
	/* 0xfd0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fd5:
	/* 0xfd5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fda:
	/* 0xfda: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_fdd:
	/* 0xfdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fdf:
	/* 0xfdf: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_fe3:
	/* 0xfe3: jne    122 <generic_sleepable_preload+0x122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 290ULL;
	}
x86_l_fe9:
	/* 0xfe9: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fee:
	/* 0xfee: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_ff6:
	/* 0xff6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_ffb:
	/* 0xffb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ffd:
	/* 0xffd: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1002:
	/* 0x1002: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_100a:
	/* 0x100a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_100f:
	/* 0x100f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1016:
	/* 0x1016: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_101b:
	/* 0x101b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_101d:
	/* 0x101d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1020:
	/* 0x1020: je     122 <generic_sleepable_preload+0x122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 290ULL;
	}
x86_l_1026:
	/* 0x1026: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1029:
	/* 0x1029: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_102e:
	/* 0x102e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1030:
	/* 0x1030: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1035:
	/* 0x1035: mov    r13d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_32);
x86_l_1038:
	/* 0x1038: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_103f:
	/* 0x103f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1042:
	/* 0x1042: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1045:
	/* 0x1045: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1047:
	/* 0x1047: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1049:
	/* 0x1049: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_104e:
	/* 0x104e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1051:
	/* 0x1051: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_1054:
	/* 0x1054: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1057:
	/* 0x1057: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1059:
	/* 0x1059: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_105c:
	/* 0x105c: je     122 <generic_sleepable_preload+0x122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 290ULL;
	}
x86_l_1062:
	/* 0x1062: cmp    BYTE PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1067:
	/* 0x1067: je     11f <generic_sleepable_preload+0x11f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 287ULL;
	}
x86_l_106d:
	/* 0x106d: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1071:
	/* 0x1071: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1076:
	/* 0x1076: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_107e:
	/* 0x107e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1080:
	/* 0x1080: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1083:
	/* 0x1083: call   1088 <generic_sleepable_preload+0x1088> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_1088:
	/* 0x1088: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_108a:
	/* 0x108a: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_108d:
	/* 0x108d: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_1090:
	/* 0x1090: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1092:
	/* 0x1092: jns    11f <generic_sleepable_preload+0x11f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 287ULL;
	}
x86_l_1098:
	/* 0x1098: mov    r12d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_109e:
	/* 0x109e: jmp    11f <generic_sleepable_preload+0x11f> */
	return 287ULL;
x86_l_10a3:
	/* 0x10a3: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_10a9:
	/* 0x10a9: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_10b1:
	/* 0x10b1: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_10b4:
	/* 0x10b4: jne    127 <generic_sleepable_preload+0x127> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 295ULL;
	}
x86_l_10ba:
	/* 0x10ba: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10bf:
	/* 0x10bf: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_10c7:
	/* 0x10c7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_10cc:
	/* 0x10cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ce:
	/* 0x10ce: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10d3:
	/* 0x10d3: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_10db:
	/* 0x10db: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10e0:
	/* 0x10e0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_10e7:
	/* 0x10e7: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10ec:
	/* 0x10ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ee:
	/* 0x10ee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10f1:
	/* 0x10f1: je     122 <generic_sleepable_preload+0x122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 290ULL;
	}
x86_l_10f7:
	/* 0x10f7: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_10fa:
	/* 0x10fa: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10ff:
	/* 0x10ff: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1101:
	/* 0x1101: lea    rbp,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1106:
	/* 0x1106: mov    r13d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_32);
x86_l_1109:
	/* 0x1109: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1110:
	/* 0x1110: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1113:
	/* 0x1113: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1116:
	/* 0x1116: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1118:
	/* 0x1118: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_111a:
	/* 0x111a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_111f:
	/* 0x111f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1122:
	/* 0x1122: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1125:
	/* 0x1125: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1127:
	/* 0x1127: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_112a:
	/* 0x112a: je     122 <generic_sleepable_preload+0x122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 290ULL;
	}
x86_l_1130:
	/* 0x1130: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1133:
	/* 0x1133: cmp    BYTE PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1138:
	/* 0x1138: je     115c <generic_sleepable_preload+0x115c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_115c;
	}
x86_l_113a:
	/* 0x113a: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_113e:
	/* 0x113e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1143:
	/* 0x1143: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_114b:
	/* 0x114b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_114d:
	/* 0x114d: call   1152 <generic_sleepable_preload+0x1152> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_1152:
	/* 0x1152: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1154:
	/* 0x1154: jns    115c <generic_sleepable_preload+0x115c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_115c;
	}
x86_l_1156:
	/* 0x1156: mov    r13d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967295ULL);
x86_l_115c:
	/* 0x115c: mov    DWORD PTR [rbp+0x0],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1160:
	/* 0x1160: jmp    122 <generic_sleepable_preload+0x122> */
	return 290ULL;
x86_l_1165:
	/* 0x1165: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_116d:
	/* 0x116d: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1173:
	/* 0x1173: jmp    fc8 <generic_sleepable_preload+0xfc8> */
	goto x86_l_fc8;
x86_l_1178:
	/* 0x1178: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1180:
	/* 0x1180: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1186:
	/* 0x1186: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1189:
	/* 0x1189: jne    127 <generic_sleepable_preload+0x127> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 295ULL;
	}
x86_l_118f:
	/* 0x118f: jmp    10ba <generic_sleepable_preload+0x10ba> */
	goto x86_l_10ba;
x86_l_1194:
	/* 0x1194: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_119a:
	/* 0x119a: jmp    fc0 <generic_sleepable_preload+0xfc0> */
	goto x86_l_fc0;
x86_l_119f:
	/* 0x119f: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_11a5:
	/* 0x11a5: jmp    10a9 <generic_sleepable_preload+0x10a9> */
	goto x86_l_10a9;
x86_l_11aa:
	/* 0x11aa: mov    eax,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11ae:
	/* 0x11ae: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11b3:
	/* 0x11b3: jne    1207 <generic_sleepable_preload+0x1207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1207;
	}
x86_l_11b5:
	/* 0x11b5: mov    eax,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_11b9:
	/* 0x11b9: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11be:
	/* 0x11be: jne    1269 <generic_sleepable_preload+0x1269> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1269;
	}
x86_l_11c4:
	/* 0x11c4: mov    eax,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11c8:
	/* 0x11c8: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11cd:
	/* 0x11cd: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11d2:
	/* 0x11d2: jne    12cb <generic_sleepable_preload+0x12cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_12cb;
	}
x86_l_11d8:
	/* 0x11d8: mov    eax,DWORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_11dc:
	/* 0x11dc: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11e1:
	/* 0x11e1: jne    1332 <generic_sleepable_preload+0x1332> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1332;
	}
x86_l_11e7:
	/* 0x11e7: mov    eax,DWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11eb:
	/* 0x11eb: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11f0:
	/* 0x11f0: jne    1399 <generic_sleepable_preload+0x1399> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1399;
	}
x86_l_11f6:
	/* 0x11f6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11f8:
	/* 0x11f8: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_11ff:
	/* 0x11ff: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1201:
	/* 0x1201: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1202:
	/* 0x1202: jmp    6a6d <generic_sleepable_preload+0x6a6d> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1207:
	/* 0x1207: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1209:
	/* 0x1209: js     13ff <generic_sleepable_preload+0x13ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_13ff;
	}
x86_l_120f:
	/* 0x120f: movzx  eax,BYTE PTR [r13+0x211] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 529ULL);
x86_l_1217:
	/* 0x1217: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1219:
	/* 0x1219: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_121c:
	/* 0x121c: jg     15f8 <generic_sleepable_preload+0x15f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5624ULL;
	}
x86_l_1222:
	/* 0x1222: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1225:
	/* 0x1225: je     1b69 <generic_sleepable_preload+0x1b69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7017ULL;
	}
x86_l_122b:
	/* 0x122b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_122e:
	/* 0x122e: jne    1ce4 <generic_sleepable_preload+0x1ce4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7396ULL;
	}
x86_l_1234:
	/* 0x1234: mov    edx,DWORD PTR [r13+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_123b:
	/* 0x123b: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1241:
	/* 0x1241: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1244:
	/* 0x1244: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1249:
	/* 0x1249: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_124e:
	/* 0x124e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1253:
	/* 0x1253: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1258:
	/* 0x1258: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_125a:
	/* 0x125a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_125c:
	/* 0x125c: je     1b75 <generic_sleepable_preload+0x1b75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7029ULL;
	}
x86_l_1262:
	/* 0x1262: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1264:
	/* 0x1264: jmp    1ce4 <generic_sleepable_preload+0x1ce4> */
	return 7396ULL;
x86_l_1269:
	/* 0x1269: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_126b:
	/* 0x126b: js     1464 <generic_sleepable_preload+0x1464> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1464;
	}
x86_l_1271:
	/* 0x1271: movzx  eax,BYTE PTR [r13+0x229] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 553ULL);
x86_l_1279:
	/* 0x1279: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_127b:
	/* 0x127b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_127e:
	/* 0x127e: jg     16c5 <generic_sleepable_preload+0x16c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5829ULL;
	}
x86_l_1284:
	/* 0x1284: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1287:
	/* 0x1287: je     1ba4 <generic_sleepable_preload+0x1ba4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7076ULL;
	}
x86_l_128d:
	/* 0x128d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1290:
	/* 0x1290: jne    23ad <generic_sleepable_preload+0x23ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9133ULL;
	}
x86_l_1296:
	/* 0x1296: mov    edx,DWORD PTR [r13+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_129d:
	/* 0x129d: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12a3:
	/* 0x12a3: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_12a6:
	/* 0x12a6: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12ab:
	/* 0x12ab: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12b0:
	/* 0x12b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12b5:
	/* 0x12b5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12ba:
	/* 0x12ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12bc:
	/* 0x12bc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12be:
	/* 0x12be: je     1bb0 <generic_sleepable_preload+0x1bb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7088ULL;
	}
x86_l_12c4:
	/* 0x12c4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12c6:
	/* 0x12c6: jmp    23ad <generic_sleepable_preload+0x23ad> */
	return 9133ULL;
x86_l_12cb:
	/* 0x12cb: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_12cd:
	/* 0x12cd: js     14c9 <generic_sleepable_preload+0x14c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_14c9;
	}
x86_l_12d3:
	/* 0x12d3: movzx  eax,BYTE PTR [r13+0x241] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 577ULL);
x86_l_12db:
	/* 0x12db: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12dd:
	/* 0x12dd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12e0:
	/* 0x12e0: jg     1740 <generic_sleepable_preload+0x1740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5952ULL;
	}
x86_l_12e6:
	/* 0x12e6: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12e9:
	/* 0x12e9: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12ee:
	/* 0x12ee: je     1bdf <generic_sleepable_preload+0x1bdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7135ULL;
	}
x86_l_12f4:
	/* 0x12f4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12f7:
	/* 0x12f7: jne    2a82 <generic_sleepable_preload+0x2a82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10882ULL;
	}
x86_l_12fd:
	/* 0x12fd: mov    edx,DWORD PTR [r13+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_1304:
	/* 0x1304: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_130a:
	/* 0x130a: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_130d:
	/* 0x130d: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1312:
	/* 0x1312: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1317:
	/* 0x1317: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_131c:
	/* 0x131c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1321:
	/* 0x1321: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1323:
	/* 0x1323: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1325:
	/* 0x1325: je     1beb <generic_sleepable_preload+0x1beb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7147ULL;
	}
x86_l_132b:
	/* 0x132b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_132d:
	/* 0x132d: jmp    2a82 <generic_sleepable_preload+0x2a82> */
	return 10882ULL;
x86_l_1332:
	/* 0x1332: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1334:
	/* 0x1334: js     152e <generic_sleepable_preload+0x152e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5422ULL;
	}
x86_l_133a:
	/* 0x133a: movzx  eax,BYTE PTR [r13+0x259] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 601ULL);
x86_l_1342:
	/* 0x1342: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1344:
	/* 0x1344: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1347:
	/* 0x1347: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_134c:
	/* 0x134c: jg     17c0 <generic_sleepable_preload+0x17c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6080ULL;
	}
x86_l_1352:
	/* 0x1352: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1355:
	/* 0x1355: je     1c15 <generic_sleepable_preload+0x1c15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7189ULL;
	}
x86_l_135b:
	/* 0x135b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_135e:
	/* 0x135e: jne    3166 <generic_sleepable_preload+0x3166> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12646ULL;
	}
x86_l_1364:
	/* 0x1364: mov    edx,DWORD PTR [r13+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_136b:
	/* 0x136b: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1371:
	/* 0x1371: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1374:
	/* 0x1374: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1379:
	/* 0x1379: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_137e:
	/* 0x137e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1383:
	/* 0x1383: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1388:
	/* 0x1388: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_138a:
	/* 0x138a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_138c:
	/* 0x138c: je     1c21 <generic_sleepable_preload+0x1c21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7201ULL;
	}
x86_l_1392:
	/* 0x1392: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1394:
	/* 0x1394: jmp    3166 <generic_sleepable_preload+0x3166> */
	return 12646ULL;
x86_l_1399:
	/* 0x1399: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_139b:
	/* 0x139b: js     1593 <generic_sleepable_preload+0x1593> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5523ULL;
	}
x86_l_13a1:
	/* 0x13a1: movzx  eax,BYTE PTR [r13+0x271] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 625ULL);
x86_l_13a9:
	/* 0x13a9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13ab:
	/* 0x13ab: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13ae:
	/* 0x13ae: jg     183b <generic_sleepable_preload+0x183b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6203ULL;
	}
x86_l_13b4:
	/* 0x13b4: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13b7:
	/* 0x13b7: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13bc:
	/* 0x13bc: je     1c4b <generic_sleepable_preload+0x1c4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7243ULL;
	}
x86_l_13c2:
	/* 0x13c2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13c5:
	/* 0x13c5: jne    383d <generic_sleepable_preload+0x383d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14397ULL;
	}
x86_l_13cb:
	/* 0x13cb: mov    eax,DWORD PTR [r13+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_13d2:
	/* 0x13d2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13d7:
	/* 0x13d7: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_13da:
	/* 0x13da: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13df:
	/* 0x13df: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13e4:
	/* 0x13e4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13e9:
	/* 0x13e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13ee:
	/* 0x13ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f0:
	/* 0x13f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13f2:
	/* 0x13f2: je     1c57 <generic_sleepable_preload+0x1c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7255ULL;
	}
x86_l_13f8:
	/* 0x13f8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13fa:
	/* 0x13fa: jmp    383d <generic_sleepable_preload+0x383d> */
	return 14397ULL;
x86_l_13ff:
	/* 0x13ff: movzx  eax,BYTE PTR [r13+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_1407:
	/* 0x1407: movzx  ecx,WORD PTR [r13+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_140f:
	/* 0x140f: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1415:
	/* 0x1415: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1417:
	/* 0x1417: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_141a:
	/* 0x141a: jle    18bd <generic_sleepable_preload+0x18bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6333ULL;
	}
x86_l_1420:
	/* 0x1420: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1423:
	/* 0x1423: jle    19a7 <generic_sleepable_preload+0x19a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6567ULL;
	}
x86_l_1429:
	/* 0x1429: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_142c:
	/* 0x142c: jle    40ab <generic_sleepable_preload+0x40ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 16555ULL;
	}
x86_l_1432:
	/* 0x1432: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_143a:
	/* 0x143a: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_143d:
	/* 0x143d: je     40c2 <generic_sleepable_preload+0x40c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16578ULL;
	}
x86_l_1443:
	/* 0x1443: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1448:
	/* 0x1448: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_144b:
	/* 0x144b: je     40c2 <generic_sleepable_preload+0x40c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16578ULL;
	}
x86_l_1451:
	/* 0x1451: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_1454:
	/* 0x1454: jne    40d5 <generic_sleepable_preload+0x40d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 16597ULL;
	}
x86_l_145a:
	/* 0x145a: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_145f:
	/* 0x145f: jmp    40c2 <generic_sleepable_preload+0x40c2> */
	return 16578ULL;
x86_l_1464:
	/* 0x1464: movzx  eax,BYTE PTR [r13+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_146c:
	/* 0x146c: movzx  ecx,WORD PTR [r13+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_1474:
	/* 0x1474: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_147a:
	/* 0x147a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_147c:
	/* 0x147c: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_147f:
	/* 0x147f: jle    18ed <generic_sleepable_preload+0x18ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6381ULL;
	}
x86_l_1485:
	/* 0x1485: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1488:
	/* 0x1488: jle    19d4 <generic_sleepable_preload+0x19d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6612ULL;
	}
x86_l_148e:
	/* 0x148e: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1491:
	/* 0x1491: jle    46f7 <generic_sleepable_preload+0x46f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 18167ULL;
	}
x86_l_1497:
	/* 0x1497: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_149f:
	/* 0x149f: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_14a2:
	/* 0x14a2: je     5451 <generic_sleepable_preload+0x5451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21585ULL;
	}
x86_l_14a8:
	/* 0x14a8: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14ad:
	/* 0x14ad: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_14b0:
	/* 0x14b0: je     5451 <generic_sleepable_preload+0x5451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21585ULL;
	}
x86_l_14b6:
	/* 0x14b6: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_14bb:
	/* 0x14bb: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_14be:
	/* 0x14be: je     5451 <generic_sleepable_preload+0x5451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21585ULL;
	}
x86_l_14c4:
	/* 0x14c4: jmp    5464 <generic_sleepable_preload+0x5464> */
	return 21604ULL;
x86_l_14c9:
	/* 0x14c9: movzx  eax,BYTE PTR [r13+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_14d1:
	/* 0x14d1: movzx  ecx,WORD PTR [r13+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_14d9:
	/* 0x14d9: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_14df:
	/* 0x14df: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14e1:
	/* 0x14e1: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_14e4:
	/* 0x14e4: jle    191a <generic_sleepable_preload+0x191a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6426ULL;
	}
x86_l_14ea:
	/* 0x14ea: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
	return 5357ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5357ULL: goto x86_l_14ed;
	case 5363ULL: goto x86_l_14f3;
	case 5366ULL: goto x86_l_14f6;
	case 5372ULL: goto x86_l_14fc;
	case 5380ULL: goto x86_l_1504;
	case 5383ULL: goto x86_l_1507;
	case 5389ULL: goto x86_l_150d;
	case 5394ULL: goto x86_l_1512;
	case 5397ULL: goto x86_l_1515;
	case 5403ULL: goto x86_l_151b;
	case 5408ULL: goto x86_l_1520;
	case 5411ULL: goto x86_l_1523;
	case 5417ULL: goto x86_l_1529;
	case 5422ULL: goto x86_l_152e;
	case 5430ULL: goto x86_l_1536;
	case 5438ULL: goto x86_l_153e;
	case 5444ULL: goto x86_l_1544;
	case 5446ULL: goto x86_l_1546;
	case 5449ULL: goto x86_l_1549;
	case 5455ULL: goto x86_l_154f;
	case 5458ULL: goto x86_l_1552;
	case 5464ULL: goto x86_l_1558;
	case 5467ULL: goto x86_l_155b;
	case 5473ULL: goto x86_l_1561;
	case 5481ULL: goto x86_l_1569;
	case 5484ULL: goto x86_l_156c;
	case 5490ULL: goto x86_l_1572;
	case 5495ULL: goto x86_l_1577;
	case 5498ULL: goto x86_l_157a;
	case 5504ULL: goto x86_l_1580;
	case 5509ULL: goto x86_l_1585;
	case 5512ULL: goto x86_l_1588;
	case 5518ULL: goto x86_l_158e;
	case 5523ULL: goto x86_l_1593;
	case 5531ULL: goto x86_l_159b;
	case 5539ULL: goto x86_l_15a3;
	case 5545ULL: goto x86_l_15a9;
	case 5547ULL: goto x86_l_15ab;
	case 5550ULL: goto x86_l_15ae;
	case 5556ULL: goto x86_l_15b4;
	case 5559ULL: goto x86_l_15b7;
	case 5565ULL: goto x86_l_15bd;
	case 5568ULL: goto x86_l_15c0;
	case 5574ULL: goto x86_l_15c6;
	case 5582ULL: goto x86_l_15ce;
	case 5585ULL: goto x86_l_15d1;
	case 5591ULL: goto x86_l_15d7;
	case 5596ULL: goto x86_l_15dc;
	case 5599ULL: goto x86_l_15df;
	case 5605ULL: goto x86_l_15e5;
	case 5610ULL: goto x86_l_15ea;
	case 5613ULL: goto x86_l_15ed;
	case 5619ULL: goto x86_l_15f3;
	case 5624ULL: goto x86_l_15f8;
	case 5627ULL: goto x86_l_15fb;
	case 5633ULL: goto x86_l_1601;
	case 5636ULL: goto x86_l_1604;
	case 5642ULL: goto x86_l_160a;
	case 5649ULL: goto x86_l_1611;
	case 5655ULL: goto x86_l_1617;
	case 5658ULL: goto x86_l_161a;
	case 5663ULL: goto x86_l_161f;
	case 5668ULL: goto x86_l_1624;
	case 5673ULL: goto x86_l_1629;
	case 5678ULL: goto x86_l_162e;
	case 5680ULL: goto x86_l_1630;
	case 5682ULL: goto x86_l_1632;
	case 5688ULL: goto x86_l_1638;
	case 5695ULL: goto x86_l_163f;
	case 5701ULL: goto x86_l_1645;
	case 5704ULL: goto x86_l_1648;
	case 5709ULL: goto x86_l_164d;
	case 5714ULL: goto x86_l_1652;
	case 5719ULL: goto x86_l_1657;
	case 5724ULL: goto x86_l_165c;
	case 5726ULL: goto x86_l_165e;
	case 5728ULL: goto x86_l_1660;
	case 5734ULL: goto x86_l_1666;
	case 5742ULL: goto x86_l_166e;
	case 5749ULL: goto x86_l_1675;
	case 5756ULL: goto x86_l_167c;
	case 5761ULL: goto x86_l_1681;
	case 5764ULL: goto x86_l_1684;
	case 5769ULL: goto x86_l_1689;
	case 5774ULL: goto x86_l_168e;
	case 5779ULL: goto x86_l_1693;
	case 5787ULL: goto x86_l_169b;
	case 5794ULL: goto x86_l_16a2;
	case 5801ULL: goto x86_l_16a9;
	case 5806ULL: goto x86_l_16ae;
	case 5809ULL: goto x86_l_16b1;
	case 5814ULL: goto x86_l_16b6;
	case 5816ULL: goto x86_l_16b8;
	case 5818ULL: goto x86_l_16ba;
	case 5824ULL: goto x86_l_16c0;
	case 5829ULL: goto x86_l_16c5;
	case 5832ULL: goto x86_l_16c8;
	case 5838ULL: goto x86_l_16ce;
	case 5841ULL: goto x86_l_16d1;
	case 5847ULL: goto x86_l_16d7;
	case 5854ULL: goto x86_l_16de;
	case 5860ULL: goto x86_l_16e4;
	case 5863ULL: goto x86_l_16e7;
	case 5868ULL: goto x86_l_16ec;
	case 5873ULL: goto x86_l_16f1;
	case 5878ULL: goto x86_l_16f6;
	case 5883ULL: goto x86_l_16fb;
	case 5885ULL: goto x86_l_16fd;
	case 5887ULL: goto x86_l_16ff;
	case 5893ULL: goto x86_l_1705;
	case 5898ULL: goto x86_l_170a;
	case 5905ULL: goto x86_l_1711;
	case 5910ULL: goto x86_l_1716;
	case 5915ULL: goto x86_l_171b;
	case 5920ULL: goto x86_l_1720;
	case 5925ULL: goto x86_l_1725;
	case 5932ULL: goto x86_l_172c;
	case 5937ULL: goto x86_l_1731;
	case 5939ULL: goto x86_l_1733;
	case 5941ULL: goto x86_l_1735;
	case 5947ULL: goto x86_l_173b;
	case 5952ULL: goto x86_l_1740;
	case 5955ULL: goto x86_l_1743;
	case 5960ULL: goto x86_l_1748;
	case 5966ULL: goto x86_l_174e;
	case 5969ULL: goto x86_l_1751;
	case 5975ULL: goto x86_l_1757;
	case 5982ULL: goto x86_l_175e;
	case 5988ULL: goto x86_l_1764;
	case 5991ULL: goto x86_l_1767;
	case 5996ULL: goto x86_l_176c;
	case 6001ULL: goto x86_l_1771;
	case 6006ULL: goto x86_l_1776;
	case 6011ULL: goto x86_l_177b;
	case 6013ULL: goto x86_l_177d;
	case 6015ULL: goto x86_l_177f;
	case 6021ULL: goto x86_l_1785;
	case 6026ULL: goto x86_l_178a;
	case 6033ULL: goto x86_l_1791;
	case 6038ULL: goto x86_l_1796;
	case 6043ULL: goto x86_l_179b;
	case 6048ULL: goto x86_l_17a0;
	case 6053ULL: goto x86_l_17a5;
	case 6060ULL: goto x86_l_17ac;
	case 6065ULL: goto x86_l_17b1;
	case 6067ULL: goto x86_l_17b3;
	case 6069ULL: goto x86_l_17b5;
	case 6075ULL: goto x86_l_17bb;
	case 6080ULL: goto x86_l_17c0;
	case 6083ULL: goto x86_l_17c3;
	case 6089ULL: goto x86_l_17c9;
	case 6092ULL: goto x86_l_17cc;
	case 6098ULL: goto x86_l_17d2;
	case 6105ULL: goto x86_l_17d9;
	case 6111ULL: goto x86_l_17df;
	case 6114ULL: goto x86_l_17e2;
	case 6119ULL: goto x86_l_17e7;
	case 6124ULL: goto x86_l_17ec;
	case 6129ULL: goto x86_l_17f1;
	case 6134ULL: goto x86_l_17f6;
	case 6136ULL: goto x86_l_17f8;
	case 6138ULL: goto x86_l_17fa;
	case 6144ULL: goto x86_l_1800;
	case 6149ULL: goto x86_l_1805;
	case 6156ULL: goto x86_l_180c;
	case 6161ULL: goto x86_l_1811;
	case 6166ULL: goto x86_l_1816;
	case 6171ULL: goto x86_l_181b;
	case 6176ULL: goto x86_l_1820;
	case 6183ULL: goto x86_l_1827;
	case 6188ULL: goto x86_l_182c;
	case 6190ULL: goto x86_l_182e;
	case 6192ULL: goto x86_l_1830;
	case 6198ULL: goto x86_l_1836;
	case 6203ULL: goto x86_l_183b;
	case 6206ULL: goto x86_l_183e;
	case 6211ULL: goto x86_l_1843;
	case 6217ULL: goto x86_l_1849;
	case 6220ULL: goto x86_l_184c;
	case 6226ULL: goto x86_l_1852;
	case 6233ULL: goto x86_l_1859;
	case 6238ULL: goto x86_l_185e;
	case 6241ULL: goto x86_l_1861;
	case 6246ULL: goto x86_l_1866;
	case 6251ULL: goto x86_l_186b;
	case 6256ULL: goto x86_l_1870;
	case 6261ULL: goto x86_l_1875;
	case 6264ULL: goto x86_l_1878;
	case 6266ULL: goto x86_l_187a;
	case 6268ULL: goto x86_l_187c;
	case 6274ULL: goto x86_l_1882;
	case 6279ULL: goto x86_l_1887;
	case 6286ULL: goto x86_l_188e;
	case 6291ULL: goto x86_l_1893;
	case 6296ULL: goto x86_l_1898;
	case 6301ULL: goto x86_l_189d;
	case 6306ULL: goto x86_l_18a2;
	case 6313ULL: goto x86_l_18a9;
	case 6318ULL: goto x86_l_18ae;
	case 6320ULL: goto x86_l_18b0;
	case 6322ULL: goto x86_l_18b2;
	case 6328ULL: goto x86_l_18b8;
	case 6333ULL: goto x86_l_18bd;
	case 6336ULL: goto x86_l_18c0;
	case 6342ULL: goto x86_l_18c6;
	case 6345ULL: goto x86_l_18c9;
	case 6351ULL: goto x86_l_18cf;
	case 6354ULL: goto x86_l_18d2;
	case 6356ULL: goto x86_l_18d4;
	case 6362ULL: goto x86_l_18da;
	case 6367ULL: goto x86_l_18df;
	case 6370ULL: goto x86_l_18e2;
	case 6376ULL: goto x86_l_18e8;
	case 6381ULL: goto x86_l_18ed;
	case 6384ULL: goto x86_l_18f0;
	case 6390ULL: goto x86_l_18f6;
	case 6393ULL: goto x86_l_18f9;
	case 6399ULL: goto x86_l_18ff;
	case 6401ULL: goto x86_l_1901;
	case 6407ULL: goto x86_l_1907;
	case 6412ULL: goto x86_l_190c;
	case 6415ULL: goto x86_l_190f;
	case 6421ULL: goto x86_l_1915;
	case 6426ULL: goto x86_l_191a;
	case 6429ULL: goto x86_l_191d;
	case 6434ULL: goto x86_l_1922;
	case 6440ULL: goto x86_l_1928;
	case 6443ULL: goto x86_l_192b;
	case 6449ULL: goto x86_l_1931;
	case 6451ULL: goto x86_l_1933;
	case 6457ULL: goto x86_l_1939;
	case 6460ULL: goto x86_l_193c;
	case 6463ULL: goto x86_l_193f;
	case 6469ULL: goto x86_l_1945;
	case 6474ULL: goto x86_l_194a;
	case 6477ULL: goto x86_l_194d;
	case 6482ULL: goto x86_l_1952;
	case 6488ULL: goto x86_l_1958;
	case 6491ULL: goto x86_l_195b;
	case 6497ULL: goto x86_l_1961;
	case 6499ULL: goto x86_l_1963;
	case 6505ULL: goto x86_l_1969;
	case 6508ULL: goto x86_l_196c;
	case 6511ULL: goto x86_l_196f;
	case 6517ULL: goto x86_l_1975;
	case 6522ULL: goto x86_l_197a;
	case 6525ULL: goto x86_l_197d;
	case 6531ULL: goto x86_l_1983;
	case 6534ULL: goto x86_l_1986;
	case 6540ULL: goto x86_l_198c;
	case 6542ULL: goto x86_l_198e;
	case 6548ULL: goto x86_l_1994;
	case 6551ULL: goto x86_l_1997;
	case 6556ULL: goto x86_l_199c;
	case 6562ULL: goto x86_l_19a2;
	case 6567ULL: goto x86_l_19a7;
	case 6570ULL: goto x86_l_19aa;
	case 6576ULL: goto x86_l_19b0;
	case 6584ULL: goto x86_l_19b8;
	case 6587ULL: goto x86_l_19bb;
	case 6593ULL: goto x86_l_19c1;
	case 6598ULL: goto x86_l_19c6;
	case 6601ULL: goto x86_l_19c9;
	case 6607ULL: goto x86_l_19cf;
	case 6612ULL: goto x86_l_19d4;
	case 6615ULL: goto x86_l_19d7;
	case 6621ULL: goto x86_l_19dd;
	case 6629ULL: goto x86_l_19e5;
	case 6632ULL: goto x86_l_19e8;
	case 6638ULL: goto x86_l_19ee;
	case 6643ULL: goto x86_l_19f3;
	case 6646ULL: goto x86_l_19f6;
	case 6652ULL: goto x86_l_19fc;
	case 6657ULL: goto x86_l_1a01;
	case 6660ULL: goto x86_l_1a04;
	case 6666ULL: goto x86_l_1a0a;
	case 6674ULL: goto x86_l_1a12;
	case 6677ULL: goto x86_l_1a15;
	case 6683ULL: goto x86_l_1a1b;
	case 6688ULL: goto x86_l_1a20;
	case 6691ULL: goto x86_l_1a23;
	case 6697ULL: goto x86_l_1a29;
	case 6702ULL: goto x86_l_1a2e;
	case 6705ULL: goto x86_l_1a31;
	case 6711ULL: goto x86_l_1a37;
	case 6719ULL: goto x86_l_1a3f;
	case 6722ULL: goto x86_l_1a42;
	case 6728ULL: goto x86_l_1a48;
	case 6733ULL: goto x86_l_1a4d;
	case 6736ULL: goto x86_l_1a50;
	case 6742ULL: goto x86_l_1a56;
	case 6747ULL: goto x86_l_1a5b;
	case 6750ULL: goto x86_l_1a5e;
	case 6756ULL: goto x86_l_1a64;
	case 6764ULL: goto x86_l_1a6c;
	case 6767ULL: goto x86_l_1a6f;
	case 6773ULL: goto x86_l_1a75;
	case 6778ULL: goto x86_l_1a7a;
	case 6781ULL: goto x86_l_1a7d;
	case 6787ULL: goto x86_l_1a83;
	case 6792ULL: goto x86_l_1a88;
	case 6795ULL: goto x86_l_1a8b;
	case 6801ULL: goto x86_l_1a91;
	case 6809ULL: goto x86_l_1a99;
	case 6812ULL: goto x86_l_1a9c;
	case 6818ULL: goto x86_l_1aa2;
	case 6823ULL: goto x86_l_1aa7;
	case 6826ULL: goto x86_l_1aaa;
	case 6832ULL: goto x86_l_1ab0;
	case 6837ULL: goto x86_l_1ab5;
	case 6840ULL: goto x86_l_1ab8;
	case 6846ULL: goto x86_l_1abe;
	case 6854ULL: goto x86_l_1ac6;
	case 6857ULL: goto x86_l_1ac9;
	case 6863ULL: goto x86_l_1acf;
	case 6868ULL: goto x86_l_1ad4;
	case 6871ULL: goto x86_l_1ad7;
	case 6877ULL: goto x86_l_1add;
	case 6882ULL: goto x86_l_1ae2;
	case 6885ULL: goto x86_l_1ae5;
	case 6891ULL: goto x86_l_1aeb;
	case 6899ULL: goto x86_l_1af3;
	case 6902ULL: goto x86_l_1af6;
	case 6908ULL: goto x86_l_1afc;
	case 6913ULL: goto x86_l_1b01;
	case 6916ULL: goto x86_l_1b04;
	case 6922ULL: goto x86_l_1b0a;
	case 6927ULL: goto x86_l_1b0f;
	case 6930ULL: goto x86_l_1b12;
	case 6936ULL: goto x86_l_1b18;
	case 6944ULL: goto x86_l_1b20;
	case 6947ULL: goto x86_l_1b23;
	case 6953ULL: goto x86_l_1b29;
	case 6958ULL: goto x86_l_1b2e;
	case 6961ULL: goto x86_l_1b31;
	case 6967ULL: goto x86_l_1b37;
	case 6972ULL: goto x86_l_1b3c;
	case 6975ULL: goto x86_l_1b3f;
	case 6981ULL: goto x86_l_1b45;
	case 6989ULL: goto x86_l_1b4d;
	case 6992ULL: goto x86_l_1b50;
	case 6998ULL: goto x86_l_1b56;
	case 7003ULL: goto x86_l_1b5b;
	case 7006ULL: goto x86_l_1b5e;
	case 7012ULL: goto x86_l_1b64;
	case 7017ULL: goto x86_l_1b69;
	case 7024ULL: goto x86_l_1b70;
	case 7029ULL: goto x86_l_1b75;
	case 7037ULL: goto x86_l_1b7d;
	case 7044ULL: goto x86_l_1b84;
	case 7049ULL: goto x86_l_1b89;
	case 7057ULL: goto x86_l_1b91;
	case 7062ULL: goto x86_l_1b96;
	case 7067ULL: goto x86_l_1b9b;
	case 7071ULL: goto x86_l_1b9f;
	case 7076ULL: goto x86_l_1ba4;
	case 7083ULL: goto x86_l_1bab;
	case 7088ULL: goto x86_l_1bb0;
	case 7096ULL: goto x86_l_1bb8;
	case 7103ULL: goto x86_l_1bbf;
	case 7108ULL: goto x86_l_1bc4;
	case 7116ULL: goto x86_l_1bcc;
	case 7121ULL: goto x86_l_1bd1;
	case 7126ULL: goto x86_l_1bd6;
	case 7130ULL: goto x86_l_1bda;
	case 7135ULL: goto x86_l_1bdf;
	case 7142ULL: goto x86_l_1be6;
	case 7147ULL: goto x86_l_1beb;
	case 7155ULL: goto x86_l_1bf3;
	case 7162ULL: goto x86_l_1bfa;
	case 7170ULL: goto x86_l_1c02;
	case 7175ULL: goto x86_l_1c07;
	case 7180ULL: goto x86_l_1c0c;
	case 7184ULL: goto x86_l_1c10;
	case 7189ULL: goto x86_l_1c15;
	case 7196ULL: goto x86_l_1c1c;
	case 7201ULL: goto x86_l_1c21;
	case 7209ULL: goto x86_l_1c29;
	case 7216ULL: goto x86_l_1c30;
	case 7224ULL: goto x86_l_1c38;
	case 7229ULL: goto x86_l_1c3d;
	case 7234ULL: goto x86_l_1c42;
	case 7238ULL: goto x86_l_1c46;
	case 7243ULL: goto x86_l_1c4b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_14ed:
	/* 0x14ed: jle    1a01 <generic_sleepable_preload+0x1a01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1a01;
	}
x86_l_14f3:
	/* 0x14f3: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_14f6:
	/* 0x14f6: jle    471b <generic_sleepable_preload+0x471b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 18203ULL;
	}
x86_l_14fc:
	/* 0x14fc: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1504:
	/* 0x1504: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_1507:
	/* 0x1507: je     4732 <generic_sleepable_preload+0x4732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18226ULL;
	}
x86_l_150d:
	/* 0x150d: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1512:
	/* 0x1512: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_1515:
	/* 0x1515: je     4732 <generic_sleepable_preload+0x4732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18226ULL;
	}
x86_l_151b:
	/* 0x151b: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1520:
	/* 0x1520: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1523:
	/* 0x1523: je     4732 <generic_sleepable_preload+0x4732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18226ULL;
	}
x86_l_1529:
	/* 0x1529: jmp    4745 <generic_sleepable_preload+0x4745> */
	return 18245ULL;
x86_l_152e:
	/* 0x152e: movzx  eax,BYTE PTR [r13+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_1536:
	/* 0x1536: movzx  ecx,WORD PTR [r13+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_153e:
	/* 0x153e: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1544:
	/* 0x1544: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1546:
	/* 0x1546: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1549:
	/* 0x1549: jle    194a <generic_sleepable_preload+0x194a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_194a;
	}
x86_l_154f:
	/* 0x154f: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1552:
	/* 0x1552: jle    1a2e <generic_sleepable_preload+0x1a2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1a2e;
	}
x86_l_1558:
	/* 0x1558: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_155b:
	/* 0x155b: jle    4d82 <generic_sleepable_preload+0x4d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 19842ULL;
	}
x86_l_1561:
	/* 0x1561: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1569:
	/* 0x1569: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_156c:
	/* 0x156c: je     4d99 <generic_sleepable_preload+0x4d99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19865ULL;
	}
x86_l_1572:
	/* 0x1572: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1577:
	/* 0x1577: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_157a:
	/* 0x157a: je     4d99 <generic_sleepable_preload+0x4d99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19865ULL;
	}
x86_l_1580:
	/* 0x1580: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1585:
	/* 0x1585: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_1588:
	/* 0x1588: je     4d99 <generic_sleepable_preload+0x4d99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19865ULL;
	}
x86_l_158e:
	/* 0x158e: jmp    4dac <generic_sleepable_preload+0x4dac> */
	return 19884ULL;
x86_l_1593:
	/* 0x1593: movzx  eax,BYTE PTR [r13+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_159b:
	/* 0x159b: movzx  ecx,WORD PTR [r13+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_15a3:
	/* 0x15a3: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_15a9:
	/* 0x15a9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15ab:
	/* 0x15ab: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_15ae:
	/* 0x15ae: jle    197a <generic_sleepable_preload+0x197a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_197a;
	}
x86_l_15b4:
	/* 0x15b4: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_15b7:
	/* 0x15b7: jle    1a5b <generic_sleepable_preload+0x1a5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1a5b;
	}
x86_l_15bd:
	/* 0x15bd: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_15c0:
	/* 0x15c0: jle    53da <generic_sleepable_preload+0x53da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 21466ULL;
	}
x86_l_15c6:
	/* 0x15c6: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_15ce:
	/* 0x15ce: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_15d1:
	/* 0x15d1: je     5aa1 <generic_sleepable_preload+0x5aa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23201ULL;
	}
x86_l_15d7:
	/* 0x15d7: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15dc:
	/* 0x15dc: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_15df:
	/* 0x15df: je     5aa1 <generic_sleepable_preload+0x5aa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23201ULL;
	}
x86_l_15e5:
	/* 0x15e5: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_15ea:
	/* 0x15ea: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_15ed:
	/* 0x15ed: je     5aa1 <generic_sleepable_preload+0x5aa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23201ULL;
	}
x86_l_15f3:
	/* 0x15f3: jmp    5ab4 <generic_sleepable_preload+0x5ab4> */
	return 23220ULL;
x86_l_15f8:
	/* 0x15f8: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_15fb:
	/* 0x15fb: je     1c81 <generic_sleepable_preload+0x1c81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7297ULL;
	}
x86_l_1601:
	/* 0x1601: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1604:
	/* 0x1604: jne    1ce4 <generic_sleepable_preload+0x1ce4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7396ULL;
	}
x86_l_160a:
	/* 0x160a: mov    edx,DWORD PTR [r13+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1611:
	/* 0x1611: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1617:
	/* 0x1617: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_161a:
	/* 0x161a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_161f:
	/* 0x161f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1624:
	/* 0x1624: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1629:
	/* 0x1629: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_162e:
	/* 0x162e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1630:
	/* 0x1630: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1632:
	/* 0x1632: jne    1ce1 <generic_sleepable_preload+0x1ce1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7393ULL;
	}
x86_l_1638:
	/* 0x1638: mov    edx,DWORD PTR [r13+0x20c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_163f:
	/* 0x163f: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1645:
	/* 0x1645: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1648:
	/* 0x1648: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_164d:
	/* 0x164d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1652:
	/* 0x1652: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1657:
	/* 0x1657: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_165c:
	/* 0x165c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_165e:
	/* 0x165e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1660:
	/* 0x1660: jne    1ce1 <generic_sleepable_preload+0x1ce1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7393ULL;
	}
x86_l_1666:
	/* 0x1666: movzx  eax,BYTE PTR [r13+0x213] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 531ULL);
x86_l_166e:
	/* 0x166e: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_1675:
	/* 0x1675: mov    rcx,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_167c:
	/* 0x167c: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_1681:
	/* 0x1681: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1684:
	/* 0x1684: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1689:
	/* 0x1689: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_168e:
	/* 0x168e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1693:
	/* 0x1693: movzx  ecx,BYTE PTR [r13+0x213] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 531ULL);
x86_l_169b:
	/* 0x169b: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_16a2:
	/* 0x16a2: mov    rdx,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_16a9:
	/* 0x16a9: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_16ae:
	/* 0x16ae: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16b1:
	/* 0x16b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16b6:
	/* 0x16b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16b8:
	/* 0x16b8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16ba:
	/* 0x16ba: jne    1ce1 <generic_sleepable_preload+0x1ce1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7393ULL;
	}
x86_l_16c0:
	/* 0x16c0: jmp    1b75 <generic_sleepable_preload+0x1b75> */
	goto x86_l_1b75;
x86_l_16c5:
	/* 0x16c5: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16c8:
	/* 0x16c8: je     22f8 <generic_sleepable_preload+0x22f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8952ULL;
	}
x86_l_16ce:
	/* 0x16ce: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_16d1:
	/* 0x16d1: jne    23ad <generic_sleepable_preload+0x23ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9133ULL;
	}
x86_l_16d7:
	/* 0x16d7: mov    edx,DWORD PTR [r13+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_16de:
	/* 0x16de: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16e4:
	/* 0x16e4: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16e7:
	/* 0x16e7: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16ec:
	/* 0x16ec: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16f1:
	/* 0x16f1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16f6:
	/* 0x16f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16fb:
	/* 0x16fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16fd:
	/* 0x16fd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16ff:
	/* 0x16ff: jne    23aa <generic_sleepable_preload+0x23aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9130ULL;
	}
x86_l_1705:
	/* 0x1705: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_170a:
	/* 0x170a: add    rcx,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 536ULL);
x86_l_1711:
	/* 0x1711: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1716:
	/* 0x1716: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_171b:
	/* 0x171b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1720:
	/* 0x1720: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1725:
	/* 0x1725: add    rdx,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 536ULL);
x86_l_172c:
	/* 0x172c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1731:
	/* 0x1731: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1733:
	/* 0x1733: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1735:
	/* 0x1735: jne    23aa <generic_sleepable_preload+0x23aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9130ULL;
	}
x86_l_173b:
	/* 0x173b: jmp    1bb0 <generic_sleepable_preload+0x1bb0> */
	goto x86_l_1bb0;
x86_l_1740:
	/* 0x1740: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1743:
	/* 0x1743: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1748:
	/* 0x1748: je     29cd <generic_sleepable_preload+0x29cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10701ULL;
	}
x86_l_174e:
	/* 0x174e: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1751:
	/* 0x1751: jne    2a82 <generic_sleepable_preload+0x2a82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10882ULL;
	}
x86_l_1757:
	/* 0x1757: mov    edx,DWORD PTR [r13+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_175e:
	/* 0x175e: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1764:
	/* 0x1764: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1767:
	/* 0x1767: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_176c:
	/* 0x176c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1771:
	/* 0x1771: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1776:
	/* 0x1776: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_177b:
	/* 0x177b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_177d:
	/* 0x177d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_177f:
	/* 0x177f: jne    2a7f <generic_sleepable_preload+0x2a7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10879ULL;
	}
x86_l_1785:
	/* 0x1785: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_178a:
	/* 0x178a: add    rcx,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 560ULL);
x86_l_1791:
	/* 0x1791: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1796:
	/* 0x1796: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_179b:
	/* 0x179b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_17a0:
	/* 0x17a0: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17a5:
	/* 0x17a5: add    rdx,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 560ULL);
x86_l_17ac:
	/* 0x17ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17b1:
	/* 0x17b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17b3:
	/* 0x17b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17b5:
	/* 0x17b5: jne    2a7f <generic_sleepable_preload+0x2a7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10879ULL;
	}
x86_l_17bb:
	/* 0x17bb: jmp    1beb <generic_sleepable_preload+0x1beb> */
	goto x86_l_1beb;
x86_l_17c0:
	/* 0x17c0: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17c3:
	/* 0x17c3: je     30b1 <generic_sleepable_preload+0x30b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12465ULL;
	}
x86_l_17c9:
	/* 0x17c9: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_17cc:
	/* 0x17cc: jne    3166 <generic_sleepable_preload+0x3166> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12646ULL;
	}
x86_l_17d2:
	/* 0x17d2: mov    edx,DWORD PTR [r13+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_17d9:
	/* 0x17d9: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17df:
	/* 0x17df: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_17e2:
	/* 0x17e2: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17e7:
	/* 0x17e7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17ec:
	/* 0x17ec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17f1:
	/* 0x17f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17f6:
	/* 0x17f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f8:
	/* 0x17f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17fa:
	/* 0x17fa: jne    3163 <generic_sleepable_preload+0x3163> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12643ULL;
	}
x86_l_1800:
	/* 0x1800: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1805:
	/* 0x1805: add    rcx,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 584ULL);
x86_l_180c:
	/* 0x180c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1811:
	/* 0x1811: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1816:
	/* 0x1816: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_181b:
	/* 0x181b: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1820:
	/* 0x1820: add    rdx,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 584ULL);
x86_l_1827:
	/* 0x1827: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_182c:
	/* 0x182c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_182e:
	/* 0x182e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1830:
	/* 0x1830: jne    3163 <generic_sleepable_preload+0x3163> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12643ULL;
	}
x86_l_1836:
	/* 0x1836: jmp    1c21 <generic_sleepable_preload+0x1c21> */
	goto x86_l_1c21;
x86_l_183b:
	/* 0x183b: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_183e:
	/* 0x183e: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1843:
	/* 0x1843: je     3786 <generic_sleepable_preload+0x3786> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14214ULL;
	}
x86_l_1849:
	/* 0x1849: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_184c:
	/* 0x184c: jne    383d <generic_sleepable_preload+0x383d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14397ULL;
	}
x86_l_1852:
	/* 0x1852: mov    eax,DWORD PTR [r13+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_1859:
	/* 0x1859: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_185e:
	/* 0x185e: add    rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1861:
	/* 0x1861: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1866:
	/* 0x1866: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_186b:
	/* 0x186b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1870:
	/* 0x1870: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1875:
	/* 0x1875: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1878:
	/* 0x1878: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_187a:
	/* 0x187a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_187c:
	/* 0x187c: jne    383a <generic_sleepable_preload+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14394ULL;
	}
x86_l_1882:
	/* 0x1882: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1887:
	/* 0x1887: add    rcx,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 608ULL);
x86_l_188e:
	/* 0x188e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1893:
	/* 0x1893: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1898:
	/* 0x1898: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_189d:
	/* 0x189d: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18a2:
	/* 0x18a2: add    rdx,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 608ULL);
x86_l_18a9:
	/* 0x18a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18ae:
	/* 0x18ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b0:
	/* 0x18b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18b2:
	/* 0x18b2: jne    383a <generic_sleepable_preload+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14394ULL;
	}
x86_l_18b8:
	/* 0x18b8: jmp    1c57 <generic_sleepable_preload+0x1c57> */
	return 7255ULL;
x86_l_18bd:
	/* 0x18bd: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_18c0:
	/* 0x18c0: jg     1a88 <generic_sleepable_preload+0x1a88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1a88;
	}
x86_l_18c6:
	/* 0x18c6: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_18c9:
	/* 0x18c9: jg     3f43 <generic_sleepable_preload+0x3f43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16195ULL;
	}
x86_l_18cf:
	/* 0x18cf: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_18d2:
	/* 0x18d2: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_18d4:
	/* 0x18d4: je     40c2 <generic_sleepable_preload+0x40c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16578ULL;
	}
x86_l_18da:
	/* 0x18da: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18df:
	/* 0x18df: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_18e2:
	/* 0x18e2: je     40c2 <generic_sleepable_preload+0x40c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16578ULL;
	}
x86_l_18e8:
	/* 0x18e8: jmp    40d5 <generic_sleepable_preload+0x40d5> */
	return 16597ULL;
x86_l_18ed:
	/* 0x18ed: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_18f0:
	/* 0x18f0: jg     1ab5 <generic_sleepable_preload+0x1ab5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1ab5;
	}
x86_l_18f6:
	/* 0x18f6: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_18f9:
	/* 0x18f9: jg     3f67 <generic_sleepable_preload+0x3f67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16231ULL;
	}
x86_l_18ff:
	/* 0x18ff: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1901:
	/* 0x1901: je     544e <generic_sleepable_preload+0x544e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21582ULL;
	}
x86_l_1907:
	/* 0x1907: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_190c:
	/* 0x190c: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_190f:
	/* 0x190f: je     5451 <generic_sleepable_preload+0x5451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21585ULL;
	}
x86_l_1915:
	/* 0x1915: jmp    5464 <generic_sleepable_preload+0x5464> */
	return 21604ULL;
x86_l_191a:
	/* 0x191a: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_191d:
	/* 0x191d: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1922:
	/* 0x1922: jg     1ae2 <generic_sleepable_preload+0x1ae2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1ae2;
	}
x86_l_1928:
	/* 0x1928: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_192b:
	/* 0x192b: jg     3f8b <generic_sleepable_preload+0x3f8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16267ULL;
	}
x86_l_1931:
	/* 0x1931: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1933:
	/* 0x1933: je     4732 <generic_sleepable_preload+0x4732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18226ULL;
	}
x86_l_1939:
	/* 0x1939: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_193c:
	/* 0x193c: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_193f:
	/* 0x193f: je     4732 <generic_sleepable_preload+0x4732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18226ULL;
	}
x86_l_1945:
	/* 0x1945: jmp    4745 <generic_sleepable_preload+0x4745> */
	return 18245ULL;
x86_l_194a:
	/* 0x194a: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_194d:
	/* 0x194d: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1952:
	/* 0x1952: jg     1b0f <generic_sleepable_preload+0x1b0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1b0f;
	}
x86_l_1958:
	/* 0x1958: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_195b:
	/* 0x195b: jg     3faf <generic_sleepable_preload+0x3faf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16303ULL;
	}
x86_l_1961:
	/* 0x1961: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1963:
	/* 0x1963: je     4d99 <generic_sleepable_preload+0x4d99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19865ULL;
	}
x86_l_1969:
	/* 0x1969: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_196c:
	/* 0x196c: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_196f:
	/* 0x196f: je     4d99 <generic_sleepable_preload+0x4d99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19865ULL;
	}
x86_l_1975:
	/* 0x1975: jmp    4dac <generic_sleepable_preload+0x4dac> */
	return 19884ULL;
x86_l_197a:
	/* 0x197a: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_197d:
	/* 0x197d: jg     1b3c <generic_sleepable_preload+0x1b3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1b3c;
	}
x86_l_1983:
	/* 0x1983: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1986:
	/* 0x1986: jg     3fd3 <generic_sleepable_preload+0x3fd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16339ULL;
	}
x86_l_198c:
	/* 0x198c: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_198e:
	/* 0x198e: je     5a9c <generic_sleepable_preload+0x5a9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23196ULL;
	}
x86_l_1994:
	/* 0x1994: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1997:
	/* 0x1997: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_199c:
	/* 0x199c: je     5aa1 <generic_sleepable_preload+0x5aa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23201ULL;
	}
x86_l_19a2:
	/* 0x19a2: jmp    5ab4 <generic_sleepable_preload+0x5ab4> */
	return 23220ULL;
x86_l_19a7:
	/* 0x19a7: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_19aa:
	/* 0x19aa: jg     3e8f <generic_sleepable_preload+0x3e8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16015ULL;
	}
x86_l_19b0:
	/* 0x19b0: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_19b8:
	/* 0x19b8: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19bb:
	/* 0x19bb: je     40c2 <generic_sleepable_preload+0x40c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16578ULL;
	}
x86_l_19c1:
	/* 0x19c1: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_19c6:
	/* 0x19c6: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_19c9:
	/* 0x19c9: je     40c2 <generic_sleepable_preload+0x40c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16578ULL;
	}
x86_l_19cf:
	/* 0x19cf: jmp    40d5 <generic_sleepable_preload+0x40d5> */
	return 16597ULL;
x86_l_19d4:
	/* 0x19d4: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_19d7:
	/* 0x19d7: jg     3eb3 <generic_sleepable_preload+0x3eb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16051ULL;
	}
x86_l_19dd:
	/* 0x19dd: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_19e5:
	/* 0x19e5: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19e8:
	/* 0x19e8: je     5451 <generic_sleepable_preload+0x5451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21585ULL;
	}
x86_l_19ee:
	/* 0x19ee: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_19f3:
	/* 0x19f3: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_19f6:
	/* 0x19f6: je     5451 <generic_sleepable_preload+0x5451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21585ULL;
	}
x86_l_19fc:
	/* 0x19fc: jmp    5464 <generic_sleepable_preload+0x5464> */
	return 21604ULL;
x86_l_1a01:
	/* 0x1a01: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a04:
	/* 0x1a04: jg     3ed7 <generic_sleepable_preload+0x3ed7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16087ULL;
	}
x86_l_1a0a:
	/* 0x1a0a: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a12:
	/* 0x1a12: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a15:
	/* 0x1a15: je     4732 <generic_sleepable_preload+0x4732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18226ULL;
	}
x86_l_1a1b:
	/* 0x1a1b: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a20:
	/* 0x1a20: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a23:
	/* 0x1a23: je     4732 <generic_sleepable_preload+0x4732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18226ULL;
	}
x86_l_1a29:
	/* 0x1a29: jmp    4745 <generic_sleepable_preload+0x4745> */
	return 18245ULL;
x86_l_1a2e:
	/* 0x1a2e: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a31:
	/* 0x1a31: jg     3efb <generic_sleepable_preload+0x3efb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16123ULL;
	}
x86_l_1a37:
	/* 0x1a37: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a3f:
	/* 0x1a3f: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a42:
	/* 0x1a42: je     4d99 <generic_sleepable_preload+0x4d99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19865ULL;
	}
x86_l_1a48:
	/* 0x1a48: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a4d:
	/* 0x1a4d: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a50:
	/* 0x1a50: je     4d99 <generic_sleepable_preload+0x4d99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19865ULL;
	}
x86_l_1a56:
	/* 0x1a56: jmp    4dac <generic_sleepable_preload+0x4dac> */
	return 19884ULL;
x86_l_1a5b:
	/* 0x1a5b: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a5e:
	/* 0x1a5e: jg     3f1f <generic_sleepable_preload+0x3f1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16159ULL;
	}
x86_l_1a64:
	/* 0x1a64: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a6c:
	/* 0x1a6c: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a6f:
	/* 0x1a6f: je     5aa1 <generic_sleepable_preload+0x5aa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23201ULL;
	}
x86_l_1a75:
	/* 0x1a75: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a7a:
	/* 0x1a7a: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1a7d:
	/* 0x1a7d: je     5aa1 <generic_sleepable_preload+0x5aa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23201ULL;
	}
x86_l_1a83:
	/* 0x1a83: jmp    5ab4 <generic_sleepable_preload+0x5ab4> */
	return 23220ULL;
x86_l_1a88:
	/* 0x1a88: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1a8b:
	/* 0x1a8b: jg     3ff7 <generic_sleepable_preload+0x3ff7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16375ULL;
	}
x86_l_1a91:
	/* 0x1a91: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1a99:
	/* 0x1a99: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1a9c:
	/* 0x1a9c: je     40c2 <generic_sleepable_preload+0x40c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16578ULL;
	}
x86_l_1aa2:
	/* 0x1aa2: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1aa7:
	/* 0x1aa7: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1aaa:
	/* 0x1aaa: je     40c2 <generic_sleepable_preload+0x40c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16578ULL;
	}
x86_l_1ab0:
	/* 0x1ab0: jmp    40d5 <generic_sleepable_preload+0x40d5> */
	return 16597ULL;
x86_l_1ab5:
	/* 0x1ab5: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1ab8:
	/* 0x1ab8: jg     401b <generic_sleepable_preload+0x401b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16411ULL;
	}
x86_l_1abe:
	/* 0x1abe: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1ac6:
	/* 0x1ac6: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1ac9:
	/* 0x1ac9: je     5451 <generic_sleepable_preload+0x5451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21585ULL;
	}
x86_l_1acf:
	/* 0x1acf: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ad4:
	/* 0x1ad4: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1ad7:
	/* 0x1ad7: je     5451 <generic_sleepable_preload+0x5451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21585ULL;
	}
x86_l_1add:
	/* 0x1add: jmp    5464 <generic_sleepable_preload+0x5464> */
	return 21604ULL;
x86_l_1ae2:
	/* 0x1ae2: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1ae5:
	/* 0x1ae5: jg     403f <generic_sleepable_preload+0x403f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16447ULL;
	}
x86_l_1aeb:
	/* 0x1aeb: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1af3:
	/* 0x1af3: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1af6:
	/* 0x1af6: je     4732 <generic_sleepable_preload+0x4732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18226ULL;
	}
x86_l_1afc:
	/* 0x1afc: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b01:
	/* 0x1b01: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1b04:
	/* 0x1b04: je     4732 <generic_sleepable_preload+0x4732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18226ULL;
	}
x86_l_1b0a:
	/* 0x1b0a: jmp    4745 <generic_sleepable_preload+0x4745> */
	return 18245ULL;
x86_l_1b0f:
	/* 0x1b0f: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1b12:
	/* 0x1b12: jg     4063 <generic_sleepable_preload+0x4063> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16483ULL;
	}
x86_l_1b18:
	/* 0x1b18: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1b20:
	/* 0x1b20: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1b23:
	/* 0x1b23: je     4d99 <generic_sleepable_preload+0x4d99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19865ULL;
	}
x86_l_1b29:
	/* 0x1b29: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b2e:
	/* 0x1b2e: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1b31:
	/* 0x1b31: je     4d99 <generic_sleepable_preload+0x4d99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19865ULL;
	}
x86_l_1b37:
	/* 0x1b37: jmp    4dac <generic_sleepable_preload+0x4dac> */
	return 19884ULL;
x86_l_1b3c:
	/* 0x1b3c: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1b3f:
	/* 0x1b3f: jg     4087 <generic_sleepable_preload+0x4087> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 16519ULL;
	}
x86_l_1b45:
	/* 0x1b45: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1b4d:
	/* 0x1b4d: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1b50:
	/* 0x1b50: je     5aa1 <generic_sleepable_preload+0x5aa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23201ULL;
	}
x86_l_1b56:
	/* 0x1b56: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b5b:
	/* 0x1b5b: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1b5e:
	/* 0x1b5e: je     5aa1 <generic_sleepable_preload+0x5aa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23201ULL;
	}
x86_l_1b64:
	/* 0x1b64: jmp    5ab4 <generic_sleepable_preload+0x5ab4> */
	return 23220ULL;
x86_l_1b69:
	/* 0x1b69: mov    rax,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_1b70:
	/* 0x1b70: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b75:
	/* 0x1b75: movzx  eax,BYTE PTR [r13+0x210] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 528ULL);
x86_l_1b7d:
	/* 0x1b7d: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1b84:
	/* 0x1b84: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b89:
	/* 0x1b89: cmp    BYTE PTR [r13+0x212],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2276332666880ULL);
x86_l_1b91:
	/* 0x1b91: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1b96:
	/* 0x1b96: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1b9b:
	/* 0x1b9b: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1b9f:
	/* 0x1b9f: jmp    1ce4 <generic_sleepable_preload+0x1ce4> */
	return 7396ULL;
x86_l_1ba4:
	/* 0x1ba4: mov    rax,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_1bab:
	/* 0x1bab: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bb0:
	/* 0x1bb0: movzx  eax,BYTE PTR [r13+0x228] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 552ULL);
x86_l_1bb8:
	/* 0x1bb8: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1bbf:
	/* 0x1bbf: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bc4:
	/* 0x1bc4: cmp    BYTE PTR [r13+0x22a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2379411881984ULL);
x86_l_1bcc:
	/* 0x1bcc: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1bd1:
	/* 0x1bd1: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1bd6:
	/* 0x1bd6: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1bda:
	/* 0x1bda: jmp    23ad <generic_sleepable_preload+0x23ad> */
	return 9133ULL;
x86_l_1bdf:
	/* 0x1bdf: mov    rax,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_1be6:
	/* 0x1be6: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1beb:
	/* 0x1beb: movzx  eax,BYTE PTR [r13+0x240] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 576ULL);
x86_l_1bf3:
	/* 0x1bf3: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1bfa:
	/* 0x1bfa: cmp    BYTE PTR [r13+0x242],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2482491097088ULL);
x86_l_1c02:
	/* 0x1c02: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1c07:
	/* 0x1c07: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1c0c:
	/* 0x1c0c: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1c10:
	/* 0x1c10: jmp    2a82 <generic_sleepable_preload+0x2a82> */
	return 10882ULL;
x86_l_1c15:
	/* 0x1c15: mov    rax,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_1c1c:
	/* 0x1c1c: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c21:
	/* 0x1c21: movzx  eax,BYTE PTR [r13+0x258] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 600ULL);
x86_l_1c29:
	/* 0x1c29: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1c30:
	/* 0x1c30: cmp    BYTE PTR [r13+0x25a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2585570312192ULL);
x86_l_1c38:
	/* 0x1c38: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1c3d:
	/* 0x1c3d: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1c42:
	/* 0x1c42: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1c46:
	/* 0x1c46: jmp    3166 <generic_sleepable_preload+0x3166> */
	return 12646ULL;
x86_l_1c4b:
	/* 0x1c4b: mov    rax,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
	return 7250ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7250ULL: goto x86_l_1c52;
	case 7255ULL: goto x86_l_1c57;
	case 7263ULL: goto x86_l_1c5f;
	case 7270ULL: goto x86_l_1c66;
	case 7278ULL: goto x86_l_1c6e;
	case 7283ULL: goto x86_l_1c73;
	case 7288ULL: goto x86_l_1c78;
	case 7292ULL: goto x86_l_1c7c;
	case 7297ULL: goto x86_l_1c81;
	case 7304ULL: goto x86_l_1c88;
	case 7310ULL: goto x86_l_1c8e;
	case 7313ULL: goto x86_l_1c91;
	case 7318ULL: goto x86_l_1c96;
	case 7323ULL: goto x86_l_1c9b;
	case 7328ULL: goto x86_l_1ca0;
	case 7333ULL: goto x86_l_1ca5;
	case 7335ULL: goto x86_l_1ca7;
	case 7337ULL: goto x86_l_1ca9;
	case 7339ULL: goto x86_l_1cab;
	case 7344ULL: goto x86_l_1cb0;
	case 7351ULL: goto x86_l_1cb7;
	case 7356ULL: goto x86_l_1cbc;
	case 7361ULL: goto x86_l_1cc1;
	case 7366ULL: goto x86_l_1cc6;
	case 7371ULL: goto x86_l_1ccb;
	case 7378ULL: goto x86_l_1cd2;
	case 7383ULL: goto x86_l_1cd7;
	case 7385ULL: goto x86_l_1cd9;
	case 7387ULL: goto x86_l_1cdb;
	case 7393ULL: goto x86_l_1ce1;
	case 7396ULL: goto x86_l_1ce4;
	case 7401ULL: goto x86_l_1ce9;
	case 7403ULL: goto x86_l_1ceb;
	case 7406ULL: goto x86_l_1cee;
	case 7412ULL: goto x86_l_1cf4;
	case 7418ULL: goto x86_l_1cfa;
	case 7425ULL: goto x86_l_1d01;
	case 7428ULL: goto x86_l_1d04;
	case 7432ULL: goto x86_l_1d08;
	case 7435ULL: goto x86_l_1d0b;
	case 7440ULL: goto x86_l_1d10;
	case 7445ULL: goto x86_l_1d15;
	case 7447ULL: goto x86_l_1d17;
	case 7453ULL: goto x86_l_1d1d;
	case 7456ULL: goto x86_l_1d20;
	case 7458ULL: goto x86_l_1d22;
	case 7463ULL: goto x86_l_1d27;
	case 7468ULL: goto x86_l_1d2c;
	case 7473ULL: goto x86_l_1d31;
	case 7478ULL: goto x86_l_1d36;
	case 7483ULL: goto x86_l_1d3b;
	case 7485ULL: goto x86_l_1d3d;
	case 7487ULL: goto x86_l_1d3f;
	case 7493ULL: goto x86_l_1d45;
	case 7499ULL: goto x86_l_1d4b;
	case 7505ULL: goto x86_l_1d51;
	case 7509ULL: goto x86_l_1d55;
	case 7514ULL: goto x86_l_1d5a;
	case 7519ULL: goto x86_l_1d5f;
	case 7525ULL: goto x86_l_1d65;
	case 7527ULL: goto x86_l_1d67;
	case 7532ULL: goto x86_l_1d6c;
	case 7537ULL: goto x86_l_1d71;
	case 7542ULL: goto x86_l_1d76;
	case 7547ULL: goto x86_l_1d7b;
	case 7552ULL: goto x86_l_1d80;
	case 7554ULL: goto x86_l_1d82;
	case 7556ULL: goto x86_l_1d84;
	case 7562ULL: goto x86_l_1d8a;
	case 7571ULL: goto x86_l_1d93;
	case 7577ULL: goto x86_l_1d99;
	case 7584ULL: goto x86_l_1da0;
	case 7589ULL: goto x86_l_1da5;
	case 7594ULL: goto x86_l_1daa;
	case 7603ULL: goto x86_l_1db3;
	case 7605ULL: goto x86_l_1db5;
	case 7610ULL: goto x86_l_1dba;
	case 7615ULL: goto x86_l_1dbf;
	case 7620ULL: goto x86_l_1dc4;
	case 7625ULL: goto x86_l_1dc9;
	case 7630ULL: goto x86_l_1dce;
	case 7632ULL: goto x86_l_1dd0;
	case 7634ULL: goto x86_l_1dd2;
	case 7640ULL: goto x86_l_1dd8;
	case 7649ULL: goto x86_l_1de1;
	case 7655ULL: goto x86_l_1de7;
	case 7662ULL: goto x86_l_1dee;
	case 7667ULL: goto x86_l_1df3;
	case 7672ULL: goto x86_l_1df8;
	case 7681ULL: goto x86_l_1e01;
	case 7683ULL: goto x86_l_1e03;
	case 7688ULL: goto x86_l_1e08;
	case 7693ULL: goto x86_l_1e0d;
	case 7698ULL: goto x86_l_1e12;
	case 7703ULL: goto x86_l_1e17;
	case 7708ULL: goto x86_l_1e1c;
	case 7710ULL: goto x86_l_1e1e;
	case 7712ULL: goto x86_l_1e20;
	case 7718ULL: goto x86_l_1e26;
	case 7727ULL: goto x86_l_1e2f;
	case 7733ULL: goto x86_l_1e35;
	case 7740ULL: goto x86_l_1e3c;
	case 7745ULL: goto x86_l_1e41;
	case 7750ULL: goto x86_l_1e46;
	case 7759ULL: goto x86_l_1e4f;
	case 7761ULL: goto x86_l_1e51;
	case 7766ULL: goto x86_l_1e56;
	case 7771ULL: goto x86_l_1e5b;
	case 7776ULL: goto x86_l_1e60;
	case 7781ULL: goto x86_l_1e65;
	case 7786ULL: goto x86_l_1e6a;
	case 7788ULL: goto x86_l_1e6c;
	case 7790ULL: goto x86_l_1e6e;
	case 7796ULL: goto x86_l_1e74;
	case 7805ULL: goto x86_l_1e7d;
	case 7811ULL: goto x86_l_1e83;
	case 7818ULL: goto x86_l_1e8a;
	case 7823ULL: goto x86_l_1e8f;
	case 7828ULL: goto x86_l_1e94;
	case 7837ULL: goto x86_l_1e9d;
	case 7839ULL: goto x86_l_1e9f;
	case 7844ULL: goto x86_l_1ea4;
	case 7849ULL: goto x86_l_1ea9;
	case 7854ULL: goto x86_l_1eae;
	case 7859ULL: goto x86_l_1eb3;
	case 7864ULL: goto x86_l_1eb8;
	case 7866ULL: goto x86_l_1eba;
	case 7868ULL: goto x86_l_1ebc;
	case 7874ULL: goto x86_l_1ec2;
	case 7883ULL: goto x86_l_1ecb;
	case 7889ULL: goto x86_l_1ed1;
	case 7896ULL: goto x86_l_1ed8;
	case 7901ULL: goto x86_l_1edd;
	case 7906ULL: goto x86_l_1ee2;
	case 7915ULL: goto x86_l_1eeb;
	case 7917ULL: goto x86_l_1eed;
	case 7922ULL: goto x86_l_1ef2;
	case 7927ULL: goto x86_l_1ef7;
	case 7932ULL: goto x86_l_1efc;
	case 7937ULL: goto x86_l_1f01;
	case 7942ULL: goto x86_l_1f06;
	case 7944ULL: goto x86_l_1f08;
	case 7946ULL: goto x86_l_1f0a;
	case 7952ULL: goto x86_l_1f10;
	case 7961ULL: goto x86_l_1f19;
	case 7967ULL: goto x86_l_1f1f;
	case 7974ULL: goto x86_l_1f26;
	case 7979ULL: goto x86_l_1f2b;
	case 7984ULL: goto x86_l_1f30;
	case 7993ULL: goto x86_l_1f39;
	case 7995ULL: goto x86_l_1f3b;
	case 8000ULL: goto x86_l_1f40;
	case 8005ULL: goto x86_l_1f45;
	case 8010ULL: goto x86_l_1f4a;
	case 8015ULL: goto x86_l_1f4f;
	case 8020ULL: goto x86_l_1f54;
	case 8022ULL: goto x86_l_1f56;
	case 8024ULL: goto x86_l_1f58;
	case 8030ULL: goto x86_l_1f5e;
	case 8039ULL: goto x86_l_1f67;
	case 8045ULL: goto x86_l_1f6d;
	case 8052ULL: goto x86_l_1f74;
	case 8057ULL: goto x86_l_1f79;
	case 8062ULL: goto x86_l_1f7e;
	case 8071ULL: goto x86_l_1f87;
	case 8073ULL: goto x86_l_1f89;
	case 8078ULL: goto x86_l_1f8e;
	case 8083ULL: goto x86_l_1f93;
	case 8088ULL: goto x86_l_1f98;
	case 8093ULL: goto x86_l_1f9d;
	case 8098ULL: goto x86_l_1fa2;
	case 8100ULL: goto x86_l_1fa4;
	case 8102ULL: goto x86_l_1fa6;
	case 8108ULL: goto x86_l_1fac;
	case 8113ULL: goto x86_l_1fb1;
	case 8122ULL: goto x86_l_1fba;
	case 8127ULL: goto x86_l_1fbf;
	case 8133ULL: goto x86_l_1fc5;
	case 8140ULL: goto x86_l_1fcc;
	case 8145ULL: goto x86_l_1fd1;
	case 8150ULL: goto x86_l_1fd6;
	case 8159ULL: goto x86_l_1fdf;
	case 8165ULL: goto x86_l_1fe5;
	case 8170ULL: goto x86_l_1fea;
	case 8175ULL: goto x86_l_1fef;
	case 8180ULL: goto x86_l_1ff4;
	case 8185ULL: goto x86_l_1ff9;
	case 8188ULL: goto x86_l_1ffc;
	case 8190ULL: goto x86_l_1ffe;
	case 8195ULL: goto x86_l_2003;
	case 8200ULL: goto x86_l_2008;
	case 8205ULL: goto x86_l_200d;
	case 8210ULL: goto x86_l_2012;
	case 8215ULL: goto x86_l_2017;
	case 8217ULL: goto x86_l_2019;
	case 8219ULL: goto x86_l_201b;
	case 8225ULL: goto x86_l_2021;
	case 8231ULL: goto x86_l_2027;
	case 8237ULL: goto x86_l_202d;
	case 8241ULL: goto x86_l_2031;
	case 8246ULL: goto x86_l_2036;
	case 8251ULL: goto x86_l_203b;
	case 8257ULL: goto x86_l_2041;
	case 8259ULL: goto x86_l_2043;
	case 8264ULL: goto x86_l_2048;
	case 8269ULL: goto x86_l_204d;
	case 8274ULL: goto x86_l_2052;
	case 8279ULL: goto x86_l_2057;
	case 8284ULL: goto x86_l_205c;
	case 8286ULL: goto x86_l_205e;
	case 8288ULL: goto x86_l_2060;
	case 8294ULL: goto x86_l_2066;
	case 8303ULL: goto x86_l_206f;
	case 8309ULL: goto x86_l_2075;
	case 8316ULL: goto x86_l_207c;
	case 8321ULL: goto x86_l_2081;
	case 8326ULL: goto x86_l_2086;
	case 8335ULL: goto x86_l_208f;
	case 8337ULL: goto x86_l_2091;
	case 8342ULL: goto x86_l_2096;
	case 8347ULL: goto x86_l_209b;
	case 8352ULL: goto x86_l_20a0;
	case 8357ULL: goto x86_l_20a5;
	case 8362ULL: goto x86_l_20aa;
	case 8364ULL: goto x86_l_20ac;
	case 8366ULL: goto x86_l_20ae;
	case 8372ULL: goto x86_l_20b4;
	case 8381ULL: goto x86_l_20bd;
	case 8387ULL: goto x86_l_20c3;
	case 8394ULL: goto x86_l_20ca;
	case 8399ULL: goto x86_l_20cf;
	case 8404ULL: goto x86_l_20d4;
	case 8413ULL: goto x86_l_20dd;
	case 8415ULL: goto x86_l_20df;
	case 8420ULL: goto x86_l_20e4;
	case 8425ULL: goto x86_l_20e9;
	case 8430ULL: goto x86_l_20ee;
	case 8435ULL: goto x86_l_20f3;
	case 8440ULL: goto x86_l_20f8;
	case 8442ULL: goto x86_l_20fa;
	case 8444ULL: goto x86_l_20fc;
	case 8450ULL: goto x86_l_2102;
	case 8459ULL: goto x86_l_210b;
	case 8465ULL: goto x86_l_2111;
	case 8472ULL: goto x86_l_2118;
	case 8477ULL: goto x86_l_211d;
	case 8482ULL: goto x86_l_2122;
	case 8491ULL: goto x86_l_212b;
	case 8493ULL: goto x86_l_212d;
	case 8498ULL: goto x86_l_2132;
	case 8503ULL: goto x86_l_2137;
	case 8508ULL: goto x86_l_213c;
	case 8513ULL: goto x86_l_2141;
	case 8518ULL: goto x86_l_2146;
	case 8520ULL: goto x86_l_2148;
	case 8522ULL: goto x86_l_214a;
	case 8528ULL: goto x86_l_2150;
	case 8537ULL: goto x86_l_2159;
	case 8543ULL: goto x86_l_215f;
	case 8550ULL: goto x86_l_2166;
	case 8555ULL: goto x86_l_216b;
	case 8560ULL: goto x86_l_2170;
	case 8569ULL: goto x86_l_2179;
	case 8571ULL: goto x86_l_217b;
	case 8576ULL: goto x86_l_2180;
	case 8581ULL: goto x86_l_2185;
	case 8586ULL: goto x86_l_218a;
	case 8591ULL: goto x86_l_218f;
	case 8596ULL: goto x86_l_2194;
	case 8598ULL: goto x86_l_2196;
	case 8600ULL: goto x86_l_2198;
	case 8606ULL: goto x86_l_219e;
	case 8615ULL: goto x86_l_21a7;
	case 8621ULL: goto x86_l_21ad;
	case 8628ULL: goto x86_l_21b4;
	case 8633ULL: goto x86_l_21b9;
	case 8638ULL: goto x86_l_21be;
	case 8647ULL: goto x86_l_21c7;
	case 8649ULL: goto x86_l_21c9;
	case 8654ULL: goto x86_l_21ce;
	case 8659ULL: goto x86_l_21d3;
	case 8664ULL: goto x86_l_21d8;
	case 8669ULL: goto x86_l_21dd;
	case 8674ULL: goto x86_l_21e2;
	case 8676ULL: goto x86_l_21e4;
	case 8678ULL: goto x86_l_21e6;
	case 8684ULL: goto x86_l_21ec;
	case 8693ULL: goto x86_l_21f5;
	case 8699ULL: goto x86_l_21fb;
	case 8706ULL: goto x86_l_2202;
	case 8711ULL: goto x86_l_2207;
	case 8716ULL: goto x86_l_220c;
	case 8725ULL: goto x86_l_2215;
	case 8727ULL: goto x86_l_2217;
	case 8732ULL: goto x86_l_221c;
	case 8737ULL: goto x86_l_2221;
	case 8742ULL: goto x86_l_2226;
	case 8747ULL: goto x86_l_222b;
	case 8752ULL: goto x86_l_2230;
	case 8754ULL: goto x86_l_2232;
	case 8756ULL: goto x86_l_2234;
	case 8762ULL: goto x86_l_223a;
	case 8767ULL: goto x86_l_223f;
	case 8776ULL: goto x86_l_2248;
	case 8781ULL: goto x86_l_224d;
	case 8787ULL: goto x86_l_2253;
	case 8794ULL: goto x86_l_225a;
	case 8799ULL: goto x86_l_225f;
	case 8804ULL: goto x86_l_2264;
	case 8813ULL: goto x86_l_226d;
	case 8815ULL: goto x86_l_226f;
	case 8820ULL: goto x86_l_2274;
	case 8825ULL: goto x86_l_2279;
	case 8830ULL: goto x86_l_227e;
	case 8835ULL: goto x86_l_2283;
	case 8840ULL: goto x86_l_2288;
	case 8842ULL: goto x86_l_228a;
	case 8844ULL: goto x86_l_228c;
	case 8850ULL: goto x86_l_2292;
	case 8855ULL: goto x86_l_2297;
	case 8864ULL: goto x86_l_22a0;
	case 8869ULL: goto x86_l_22a5;
	case 8875ULL: goto x86_l_22ab;
	case 8882ULL: goto x86_l_22b2;
	case 8887ULL: goto x86_l_22b7;
	case 8892ULL: goto x86_l_22bc;
	case 8901ULL: goto x86_l_22c5;
	case 8907ULL: goto x86_l_22cb;
	case 8912ULL: goto x86_l_22d0;
	case 8917ULL: goto x86_l_22d5;
	case 8922ULL: goto x86_l_22da;
	case 8927ULL: goto x86_l_22df;
	case 8932ULL: goto x86_l_22e4;
	case 8934ULL: goto x86_l_22e6;
	case 8936ULL: goto x86_l_22e8;
	case 8942ULL: goto x86_l_22ee;
	case 8947ULL: goto x86_l_22f3;
	case 8952ULL: goto x86_l_22f8;
	case 8959ULL: goto x86_l_22ff;
	case 8965ULL: goto x86_l_2305;
	case 8968ULL: goto x86_l_2308;
	case 8973ULL: goto x86_l_230d;
	case 8978ULL: goto x86_l_2312;
	case 8983ULL: goto x86_l_2317;
	case 8988ULL: goto x86_l_231c;
	case 8990ULL: goto x86_l_231e;
	case 8992ULL: goto x86_l_2320;
	case 8998ULL: goto x86_l_2326;
	case 9005ULL: goto x86_l_232d;
	case 9011ULL: goto x86_l_2333;
	case 9014ULL: goto x86_l_2336;
	case 9019ULL: goto x86_l_233b;
	case 9024ULL: goto x86_l_2340;
	case 9029ULL: goto x86_l_2345;
	case 9034ULL: goto x86_l_234a;
	case 9036ULL: goto x86_l_234c;
	case 9038ULL: goto x86_l_234e;
	case 9040ULL: goto x86_l_2350;
	case 9048ULL: goto x86_l_2358;
	case 9055ULL: goto x86_l_235f;
	case 9062ULL: goto x86_l_2366;
	case 9067ULL: goto x86_l_236b;
	case 9070ULL: goto x86_l_236e;
	case 9075ULL: goto x86_l_2373;
	case 9080ULL: goto x86_l_2378;
	case 9085ULL: goto x86_l_237d;
	case 9093ULL: goto x86_l_2385;
	case 9100ULL: goto x86_l_238c;
	case 9107ULL: goto x86_l_2393;
	case 9112ULL: goto x86_l_2398;
	case 9115ULL: goto x86_l_239b;
	case 9120ULL: goto x86_l_23a0;
	case 9122ULL: goto x86_l_23a2;
	case 9124ULL: goto x86_l_23a4;
	case 9130ULL: goto x86_l_23aa;
	case 9133ULL: goto x86_l_23ad;
	case 9138ULL: goto x86_l_23b2;
	case 9140ULL: goto x86_l_23b4;
	case 9143ULL: goto x86_l_23b7;
	case 9152ULL: goto x86_l_23c0;
	case 9158ULL: goto x86_l_23c6;
	case 9165ULL: goto x86_l_23cd;
	case 9168ULL: goto x86_l_23d0;
	case 9175ULL: goto x86_l_23d7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c52:
	/* 0x1c52: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c57:
	/* 0x1c57: movzx  eax,BYTE PTR [r13+0x270] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 624ULL);
x86_l_1c5f:
	/* 0x1c5f: shlx   rcx,QWORD PTR [rsp+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((24ULL << 32) | X86_ALU_SHL));
x86_l_1c66:
	/* 0x1c66: cmp    BYTE PTR [r13+0x272],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2688649527296ULL);
x86_l_1c6e:
	/* 0x1c6e: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1c73:
	/* 0x1c73: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_1c78:
	/* 0x1c78: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1c7c:
	/* 0x1c7c: jmp    383d <generic_sleepable_preload+0x383d> */
	return 14397ULL;
x86_l_1c81:
	/* 0x1c81: mov    edx,DWORD PTR [r13+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1c88:
	/* 0x1c88: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1c8e:
	/* 0x1c8e: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c91:
	/* 0x1c91: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c96:
	/* 0x1c96: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c9b:
	/* 0x1c9b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ca0:
	/* 0x1ca0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ca5:
	/* 0x1ca5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca7:
	/* 0x1ca7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ca9:
	/* 0x1ca9: jne    1ce1 <generic_sleepable_preload+0x1ce1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ce1;
	}
x86_l_1cab:
	/* 0x1cab: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cb0:
	/* 0x1cb0: add    rcx,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_1cb7:
	/* 0x1cb7: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cbc:
	/* 0x1cbc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1cc1:
	/* 0x1cc1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1cc6:
	/* 0x1cc6: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ccb:
	/* 0x1ccb: add    rdx,QWORD PTR [r13+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_1cd2:
	/* 0x1cd2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cd7:
	/* 0x1cd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd9:
	/* 0x1cd9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cdb:
	/* 0x1cdb: je     1b75 <generic_sleepable_preload+0x1b75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7029ULL;
	}
x86_l_1ce1:
	/* 0x1ce1: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_1ce4:
	/* 0x1ce4: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ce9:
	/* 0x1ce9: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ceb:
	/* 0x1ceb: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_1cee:
	/* 0x1cee: cmp    WORD PTR [r13+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_1cf4:
	/* 0x1cf4: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_1cfa:
	/* 0x1cfa: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1d01:
	/* 0x1d01: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1d04:
	/* 0x1d04: mov    eax,DWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1d08:
	/* 0x1d08: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1d0b:
	/* 0x1d0b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d10:
	/* 0x1d10: movzx  eax,WORD PTR [r13+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_1d15:
	/* 0x1d15: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1d17:
	/* 0x1d17: je     1ff9 <generic_sleepable_preload+0x1ff9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ff9;
	}
x86_l_1d1d:
	/* 0x1d1d: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1d20:
	/* 0x1d20: je     1d45 <generic_sleepable_preload+0x1d45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d45;
	}
x86_l_1d22:
	/* 0x1d22: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d27:
	/* 0x1d27: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d2c:
	/* 0x1d2c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d31:
	/* 0x1d31: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d36:
	/* 0x1d36: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d3b:
	/* 0x1d3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d3d:
	/* 0x1d3d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d3f:
	/* 0x1d3f: js     3e5d <generic_sleepable_preload+0x3e5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15965ULL;
	}
x86_l_1d45:
	/* 0x1d45: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_1d4b:
	/* 0x1d4b: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_1d51:
	/* 0x1d51: mov    ecx,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1d55:
	/* 0x1d55: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1d5a:
	/* 0x1d5a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d5f:
	/* 0x1d5f: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_1d65:
	/* 0x1d65: je     1d8a <generic_sleepable_preload+0x1d8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d8a;
	}
x86_l_1d67:
	/* 0x1d67: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d6c:
	/* 0x1d6c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d71:
	/* 0x1d71: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d76:
	/* 0x1d76: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d7b:
	/* 0x1d7b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d80:
	/* 0x1d80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d82:
	/* 0x1d82: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d84:
	/* 0x1d84: js     53fe <generic_sleepable_preload+0x53fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21502ULL;
	}
x86_l_1d8a:
	/* 0x1d8a: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_1d93:
	/* 0x1d93: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_1d99:
	/* 0x1d99: mov    ecx,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1da0:
	/* 0x1da0: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1da5:
	/* 0x1da5: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1daa:
	/* 0x1daa: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1db3:
	/* 0x1db3: je     1dd8 <generic_sleepable_preload+0x1dd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dd8;
	}
x86_l_1db5:
	/* 0x1db5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dba:
	/* 0x1dba: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1dbf:
	/* 0x1dbf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1dc4:
	/* 0x1dc4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dc9:
	/* 0x1dc9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dce:
	/* 0x1dce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd0:
	/* 0x1dd0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dd2:
	/* 0x1dd2: js     60e5 <generic_sleepable_preload+0x60e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24805ULL;
	}
x86_l_1dd8:
	/* 0x1dd8: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1de1:
	/* 0x1de1: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_1de7:
	/* 0x1de7: mov    ecx,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1dee:
	/* 0x1dee: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1df3:
	/* 0x1df3: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1df8:
	/* 0x1df8: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1e01:
	/* 0x1e01: je     1e26 <generic_sleepable_preload+0x1e26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e26;
	}
x86_l_1e03:
	/* 0x1e03: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e08:
	/* 0x1e08: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1e0d:
	/* 0x1e0d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e12:
	/* 0x1e12: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e17:
	/* 0x1e17: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e1c:
	/* 0x1e1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e1e:
	/* 0x1e1e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e20:
	/* 0x1e20: js     6149 <generic_sleepable_preload+0x6149> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24905ULL;
	}
x86_l_1e26:
	/* 0x1e26: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1e2f:
	/* 0x1e2f: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_1e35:
	/* 0x1e35: mov    ecx,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1e3c:
	/* 0x1e3c: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1e41:
	/* 0x1e41: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e46:
	/* 0x1e46: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1e4f:
	/* 0x1e4f: je     1e74 <generic_sleepable_preload+0x1e74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e74;
	}
x86_l_1e51:
	/* 0x1e51: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e56:
	/* 0x1e56: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1e5b:
	/* 0x1e5b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e60:
	/* 0x1e60: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e65:
	/* 0x1e65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e6a:
	/* 0x1e6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e6c:
	/* 0x1e6c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e6e:
	/* 0x1e6e: js     61ad <generic_sleepable_preload+0x61ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25005ULL;
	}
x86_l_1e74:
	/* 0x1e74: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1e7d:
	/* 0x1e7d: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_1e83:
	/* 0x1e83: mov    ecx,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1e8a:
	/* 0x1e8a: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1e8f:
	/* 0x1e8f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e94:
	/* 0x1e94: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1e9d:
	/* 0x1e9d: je     1ec2 <generic_sleepable_preload+0x1ec2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ec2;
	}
x86_l_1e9f:
	/* 0x1e9f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ea4:
	/* 0x1ea4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ea9:
	/* 0x1ea9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1eae:
	/* 0x1eae: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1eb3:
	/* 0x1eb3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1eb8:
	/* 0x1eb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eba:
	/* 0x1eba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ebc:
	/* 0x1ebc: js     6211 <generic_sleepable_preload+0x6211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25105ULL;
	}
x86_l_1ec2:
	/* 0x1ec2: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1ecb:
	/* 0x1ecb: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_1ed1:
	/* 0x1ed1: mov    ecx,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1ed8:
	/* 0x1ed8: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1edd:
	/* 0x1edd: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ee2:
	/* 0x1ee2: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1eeb:
	/* 0x1eeb: je     1f10 <generic_sleepable_preload+0x1f10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f10;
	}
x86_l_1eed:
	/* 0x1eed: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ef2:
	/* 0x1ef2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ef7:
	/* 0x1ef7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1efc:
	/* 0x1efc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f01:
	/* 0x1f01: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f06:
	/* 0x1f06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f08:
	/* 0x1f08: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f0a:
	/* 0x1f0a: js     6272 <generic_sleepable_preload+0x6272> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25202ULL;
	}
x86_l_1f10:
	/* 0x1f10: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1f19:
	/* 0x1f19: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_1f1f:
	/* 0x1f1f: mov    ecx,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1f26:
	/* 0x1f26: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1f2b:
	/* 0x1f2b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f30:
	/* 0x1f30: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1f39:
	/* 0x1f39: je     1f5e <generic_sleepable_preload+0x1f5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f5e;
	}
x86_l_1f3b:
	/* 0x1f3b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f40:
	/* 0x1f40: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f45:
	/* 0x1f45: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f4a:
	/* 0x1f4a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f4f:
	/* 0x1f4f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f54:
	/* 0x1f54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f56:
	/* 0x1f56: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f58:
	/* 0x1f58: js     68c2 <generic_sleepable_preload+0x68c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26818ULL;
	}
x86_l_1f5e:
	/* 0x1f5e: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1f67:
	/* 0x1f67: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_1f6d:
	/* 0x1f6d: mov    ecx,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1f74:
	/* 0x1f74: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1f79:
	/* 0x1f79: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f7e:
	/* 0x1f7e: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1f87:
	/* 0x1f87: je     1fac <generic_sleepable_preload+0x1fac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fac;
	}
x86_l_1f89:
	/* 0x1f89: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f8e:
	/* 0x1f8e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1f93:
	/* 0x1f93: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1f98:
	/* 0x1f98: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f9d:
	/* 0x1f9d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fa2:
	/* 0x1fa2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fa4:
	/* 0x1fa4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fa6:
	/* 0x1fa6: js     692f <generic_sleepable_preload+0x692f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26927ULL;
	}
x86_l_1fac:
	/* 0x1fac: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1fb1:
	/* 0x1fb1: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1fba:
	/* 0x1fba: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fbf:
	/* 0x1fbf: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_1fc5:
	/* 0x1fc5: mov    ecx,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1fcc:
	/* 0x1fcc: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1fd1:
	/* 0x1fd1: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fd6:
	/* 0x1fd6: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1fdf:
	/* 0x1fdf: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_1fe5:
	/* 0x1fe5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fea:
	/* 0x1fea: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1fef:
	/* 0x1fef: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1ff4:
	/* 0x1ff4: jmp    22da <generic_sleepable_preload+0x22da> */
	goto x86_l_22da;
x86_l_1ff9:
	/* 0x1ff9: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1ffc:
	/* 0x1ffc: je     2021 <generic_sleepable_preload+0x2021> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2021;
	}
x86_l_1ffe:
	/* 0x1ffe: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2003:
	/* 0x2003: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2008:
	/* 0x2008: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_200d:
	/* 0x200d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2012:
	/* 0x2012: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2017:
	/* 0x2017: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2019:
	/* 0x2019: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_201b:
	/* 0x201b: js     3e5d <generic_sleepable_preload+0x3e5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15965ULL;
	}
x86_l_2021:
	/* 0x2021: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_2027:
	/* 0x2027: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_202d:
	/* 0x202d: mov    ecx,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2031:
	/* 0x2031: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2036:
	/* 0x2036: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_203b:
	/* 0x203b: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_2041:
	/* 0x2041: je     2066 <generic_sleepable_preload+0x2066> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2066;
	}
x86_l_2043:
	/* 0x2043: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2048:
	/* 0x2048: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_204d:
	/* 0x204d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2052:
	/* 0x2052: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2057:
	/* 0x2057: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_205c:
	/* 0x205c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_205e:
	/* 0x205e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2060:
	/* 0x2060: js     53fe <generic_sleepable_preload+0x53fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21502ULL;
	}
x86_l_2066:
	/* 0x2066: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_206f:
	/* 0x206f: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_2075:
	/* 0x2075: mov    ecx,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_207c:
	/* 0x207c: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2081:
	/* 0x2081: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2086:
	/* 0x2086: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_208f:
	/* 0x208f: je     20b4 <generic_sleepable_preload+0x20b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20b4;
	}
x86_l_2091:
	/* 0x2091: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2096:
	/* 0x2096: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_209b:
	/* 0x209b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20a0:
	/* 0x20a0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20a5:
	/* 0x20a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20aa:
	/* 0x20aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ac:
	/* 0x20ac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20ae:
	/* 0x20ae: js     60e5 <generic_sleepable_preload+0x60e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24805ULL;
	}
x86_l_20b4:
	/* 0x20b4: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_20bd:
	/* 0x20bd: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_20c3:
	/* 0x20c3: mov    ecx,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_20ca:
	/* 0x20ca: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_20cf:
	/* 0x20cf: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20d4:
	/* 0x20d4: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_20dd:
	/* 0x20dd: je     2102 <generic_sleepable_preload+0x2102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2102;
	}
x86_l_20df:
	/* 0x20df: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20e4:
	/* 0x20e4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20e9:
	/* 0x20e9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20ee:
	/* 0x20ee: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20f3:
	/* 0x20f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20f8:
	/* 0x20f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20fa:
	/* 0x20fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20fc:
	/* 0x20fc: js     6149 <generic_sleepable_preload+0x6149> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24905ULL;
	}
x86_l_2102:
	/* 0x2102: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_210b:
	/* 0x210b: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_2111:
	/* 0x2111: mov    ecx,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2118:
	/* 0x2118: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_211d:
	/* 0x211d: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2122:
	/* 0x2122: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_212b:
	/* 0x212b: je     2150 <generic_sleepable_preload+0x2150> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2150;
	}
x86_l_212d:
	/* 0x212d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2132:
	/* 0x2132: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2137:
	/* 0x2137: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_213c:
	/* 0x213c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2141:
	/* 0x2141: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2146:
	/* 0x2146: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2148:
	/* 0x2148: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_214a:
	/* 0x214a: js     61ad <generic_sleepable_preload+0x61ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25005ULL;
	}
x86_l_2150:
	/* 0x2150: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_2159:
	/* 0x2159: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_215f:
	/* 0x215f: mov    ecx,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2166:
	/* 0x2166: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_216b:
	/* 0x216b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2170:
	/* 0x2170: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_2179:
	/* 0x2179: je     219e <generic_sleepable_preload+0x219e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_219e;
	}
x86_l_217b:
	/* 0x217b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2180:
	/* 0x2180: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2185:
	/* 0x2185: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_218a:
	/* 0x218a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_218f:
	/* 0x218f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2194:
	/* 0x2194: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2196:
	/* 0x2196: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2198:
	/* 0x2198: js     6211 <generic_sleepable_preload+0x6211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25105ULL;
	}
x86_l_219e:
	/* 0x219e: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_21a7:
	/* 0x21a7: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_21ad:
	/* 0x21ad: mov    ecx,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_21b4:
	/* 0x21b4: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_21b9:
	/* 0x21b9: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21be:
	/* 0x21be: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_21c7:
	/* 0x21c7: je     21ec <generic_sleepable_preload+0x21ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21ec;
	}
x86_l_21c9:
	/* 0x21c9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21ce:
	/* 0x21ce: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_21d3:
	/* 0x21d3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_21d8:
	/* 0x21d8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21dd:
	/* 0x21dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21e2:
	/* 0x21e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21e4:
	/* 0x21e4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21e6:
	/* 0x21e6: js     6272 <generic_sleepable_preload+0x6272> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25202ULL;
	}
x86_l_21ec:
	/* 0x21ec: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_21f5:
	/* 0x21f5: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_21fb:
	/* 0x21fb: mov    ecx,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2202:
	/* 0x2202: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2207:
	/* 0x2207: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_220c:
	/* 0x220c: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_2215:
	/* 0x2215: je     223a <generic_sleepable_preload+0x223a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_223a;
	}
x86_l_2217:
	/* 0x2217: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_221c:
	/* 0x221c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2221:
	/* 0x2221: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2226:
	/* 0x2226: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_222b:
	/* 0x222b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2230:
	/* 0x2230: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2232:
	/* 0x2232: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2234:
	/* 0x2234: js     69bf <generic_sleepable_preload+0x69bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27071ULL;
	}
x86_l_223a:
	/* 0x223a: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_223f:
	/* 0x223f: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_2248:
	/* 0x2248: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_224d:
	/* 0x224d: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_2253:
	/* 0x2253: mov    ecx,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_225a:
	/* 0x225a: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_225f:
	/* 0x225f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2264:
	/* 0x2264: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_226d:
	/* 0x226d: je     2292 <generic_sleepable_preload+0x2292> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2292;
	}
x86_l_226f:
	/* 0x226f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2274:
	/* 0x2274: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2279:
	/* 0x2279: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_227e:
	/* 0x227e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2283:
	/* 0x2283: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2288:
	/* 0x2288: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_228a:
	/* 0x228a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_228c:
	/* 0x228c: js     692f <generic_sleepable_preload+0x692f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26927ULL;
	}
x86_l_2292:
	/* 0x2292: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2297:
	/* 0x2297: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_22a0:
	/* 0x22a0: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22a5:
	/* 0x22a5: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_22ab:
	/* 0x22ab: mov    ecx,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_22b2:
	/* 0x22b2: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_22b7:
	/* 0x22b7: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22bc:
	/* 0x22bc: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_22c5:
	/* 0x22c5: je     6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25209ULL;
	}
x86_l_22cb:
	/* 0x22cb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22d0:
	/* 0x22d0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_22d5:
	/* 0x22d5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_22da:
	/* 0x22da: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22df:
	/* 0x22df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22e4:
	/* 0x22e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22e6:
	/* 0x22e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22e8:
	/* 0x22e8: jns    6279 <generic_sleepable_preload+0x6279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25209ULL;
	}
x86_l_22ee:
	/* 0x22ee: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_22f3:
	/* 0x22f3: jmp    6277 <generic_sleepable_preload+0x6277> */
	return 25207ULL;
x86_l_22f8:
	/* 0x22f8: mov    edx,DWORD PTR [r13+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_22ff:
	/* 0x22ff: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2305:
	/* 0x2305: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2308:
	/* 0x2308: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_230d:
	/* 0x230d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2312:
	/* 0x2312: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2317:
	/* 0x2317: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_231c:
	/* 0x231c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_231e:
	/* 0x231e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2320:
	/* 0x2320: jne    23aa <generic_sleepable_preload+0x23aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23aa;
	}
x86_l_2326:
	/* 0x2326: mov    edx,DWORD PTR [r13+0x224] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 548ULL);
x86_l_232d:
	/* 0x232d: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2333:
	/* 0x2333: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2336:
	/* 0x2336: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_233b:
	/* 0x233b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2340:
	/* 0x2340: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2345:
	/* 0x2345: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_234a:
	/* 0x234a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_234c:
	/* 0x234c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_234e:
	/* 0x234e: jne    23aa <generic_sleepable_preload+0x23aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23aa;
	}
x86_l_2350:
	/* 0x2350: movzx  eax,BYTE PTR [r13+0x22b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 555ULL);
x86_l_2358:
	/* 0x2358: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_235f:
	/* 0x235f: mov    rcx,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_2366:
	/* 0x2366: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_236b:
	/* 0x236b: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_236e:
	/* 0x236e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2373:
	/* 0x2373: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2378:
	/* 0x2378: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_237d:
	/* 0x237d: movzx  ecx,BYTE PTR [r13+0x22b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 555ULL);
x86_l_2385:
	/* 0x2385: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_238c:
	/* 0x238c: mov    rdx,QWORD PTR [r13+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_2393:
	/* 0x2393: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2398:
	/* 0x2398: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_239b:
	/* 0x239b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23a0:
	/* 0x23a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23a2:
	/* 0x23a2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23a4:
	/* 0x23a4: je     1bb0 <generic_sleepable_preload+0x1bb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7088ULL;
	}
x86_l_23aa:
	/* 0x23aa: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_23ad:
	/* 0x23ad: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23b2:
	/* 0x23b2: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23b4:
	/* 0x23b4: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_23b7:
	/* 0x23b7: cmp    WORD PTR [r13+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_23c0:
	/* 0x23c0: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_23c6:
	/* 0x23c6: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_23cd:
	/* 0x23cd: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_23d0:
	/* 0x23d0: mov    eax,DWORD PTR [r13+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_23d7:
	/* 0x23d7: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
	return 9178ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9178ULL: goto x86_l_23da;
	case 9183ULL: goto x86_l_23df;
	case 9191ULL: goto x86_l_23e7;
	case 9193ULL: goto x86_l_23e9;
	case 9199ULL: goto x86_l_23ef;
	case 9202ULL: goto x86_l_23f2;
	case 9204ULL: goto x86_l_23f4;
	case 9209ULL: goto x86_l_23f9;
	case 9214ULL: goto x86_l_23fe;
	case 9219ULL: goto x86_l_2403;
	case 9224ULL: goto x86_l_2408;
	case 9229ULL: goto x86_l_240d;
	case 9231ULL: goto x86_l_240f;
	case 9233ULL: goto x86_l_2411;
	case 9239ULL: goto x86_l_2417;
	case 9248ULL: goto x86_l_2420;
	case 9254ULL: goto x86_l_2426;
	case 9261ULL: goto x86_l_242d;
	case 9266ULL: goto x86_l_2432;
	case 9271ULL: goto x86_l_2437;
	case 9280ULL: goto x86_l_2440;
	case 9282ULL: goto x86_l_2442;
	case 9287ULL: goto x86_l_2447;
	case 9292ULL: goto x86_l_244c;
	case 9297ULL: goto x86_l_2451;
	case 9302ULL: goto x86_l_2456;
	case 9307ULL: goto x86_l_245b;
	case 9309ULL: goto x86_l_245d;
	case 9311ULL: goto x86_l_245f;
	case 9317ULL: goto x86_l_2465;
	case 9326ULL: goto x86_l_246e;
	case 9332ULL: goto x86_l_2474;
	case 9339ULL: goto x86_l_247b;
	case 9344ULL: goto x86_l_2480;
	case 9349ULL: goto x86_l_2485;
	case 9358ULL: goto x86_l_248e;
	case 9360ULL: goto x86_l_2490;
	case 9365ULL: goto x86_l_2495;
	case 9370ULL: goto x86_l_249a;
	case 9375ULL: goto x86_l_249f;
	case 9380ULL: goto x86_l_24a4;
	case 9385ULL: goto x86_l_24a9;
	case 9387ULL: goto x86_l_24ab;
	case 9389ULL: goto x86_l_24ad;
	case 9395ULL: goto x86_l_24b3;
	case 9404ULL: goto x86_l_24bc;
	case 9410ULL: goto x86_l_24c2;
	case 9417ULL: goto x86_l_24c9;
	case 9422ULL: goto x86_l_24ce;
	case 9427ULL: goto x86_l_24d3;
	case 9436ULL: goto x86_l_24dc;
	case 9438ULL: goto x86_l_24de;
	case 9443ULL: goto x86_l_24e3;
	case 9448ULL: goto x86_l_24e8;
	case 9453ULL: goto x86_l_24ed;
	case 9458ULL: goto x86_l_24f2;
	case 9463ULL: goto x86_l_24f7;
	case 9465ULL: goto x86_l_24f9;
	case 9467ULL: goto x86_l_24fb;
	case 9473ULL: goto x86_l_2501;
	case 9482ULL: goto x86_l_250a;
	case 9488ULL: goto x86_l_2510;
	case 9495ULL: goto x86_l_2517;
	case 9500ULL: goto x86_l_251c;
	case 9505ULL: goto x86_l_2521;
	case 9514ULL: goto x86_l_252a;
	case 9516ULL: goto x86_l_252c;
	case 9521ULL: goto x86_l_2531;
	case 9526ULL: goto x86_l_2536;
	case 9531ULL: goto x86_l_253b;
	case 9536ULL: goto x86_l_2540;
	case 9541ULL: goto x86_l_2545;
	case 9543ULL: goto x86_l_2547;
	case 9545ULL: goto x86_l_2549;
	case 9551ULL: goto x86_l_254f;
	case 9560ULL: goto x86_l_2558;
	case 9566ULL: goto x86_l_255e;
	case 9573ULL: goto x86_l_2565;
	case 9578ULL: goto x86_l_256a;
	case 9583ULL: goto x86_l_256f;
	case 9592ULL: goto x86_l_2578;
	case 9594ULL: goto x86_l_257a;
	case 9599ULL: goto x86_l_257f;
	case 9604ULL: goto x86_l_2584;
	case 9609ULL: goto x86_l_2589;
	case 9614ULL: goto x86_l_258e;
	case 9619ULL: goto x86_l_2593;
	case 9621ULL: goto x86_l_2595;
	case 9623ULL: goto x86_l_2597;
	case 9629ULL: goto x86_l_259d;
	case 9638ULL: goto x86_l_25a6;
	case 9644ULL: goto x86_l_25ac;
	case 9651ULL: goto x86_l_25b3;
	case 9656ULL: goto x86_l_25b8;
	case 9661ULL: goto x86_l_25bd;
	case 9670ULL: goto x86_l_25c6;
	case 9672ULL: goto x86_l_25c8;
	case 9677ULL: goto x86_l_25cd;
	case 9682ULL: goto x86_l_25d2;
	case 9687ULL: goto x86_l_25d7;
	case 9692ULL: goto x86_l_25dc;
	case 9697ULL: goto x86_l_25e1;
	case 9699ULL: goto x86_l_25e3;
	case 9701ULL: goto x86_l_25e5;
	case 9707ULL: goto x86_l_25eb;
	case 9716ULL: goto x86_l_25f4;
	case 9722ULL: goto x86_l_25fa;
	case 9729ULL: goto x86_l_2601;
	case 9734ULL: goto x86_l_2606;
	case 9739ULL: goto x86_l_260b;
	case 9748ULL: goto x86_l_2614;
	case 9750ULL: goto x86_l_2616;
	case 9755ULL: goto x86_l_261b;
	case 9760ULL: goto x86_l_2620;
	case 9765ULL: goto x86_l_2625;
	case 9770ULL: goto x86_l_262a;
	case 9775ULL: goto x86_l_262f;
	case 9777ULL: goto x86_l_2631;
	case 9779ULL: goto x86_l_2633;
	case 9785ULL: goto x86_l_2639;
	case 9794ULL: goto x86_l_2642;
	case 9800ULL: goto x86_l_2648;
	case 9807ULL: goto x86_l_264f;
	case 9812ULL: goto x86_l_2654;
	case 9817ULL: goto x86_l_2659;
	case 9826ULL: goto x86_l_2662;
	case 9828ULL: goto x86_l_2664;
	case 9833ULL: goto x86_l_2669;
	case 9838ULL: goto x86_l_266e;
	case 9843ULL: goto x86_l_2673;
	case 9848ULL: goto x86_l_2678;
	case 9853ULL: goto x86_l_267d;
	case 9855ULL: goto x86_l_267f;
	case 9857ULL: goto x86_l_2681;
	case 9863ULL: goto x86_l_2687;
	case 9868ULL: goto x86_l_268c;
	case 9877ULL: goto x86_l_2695;
	case 9883ULL: goto x86_l_269b;
	case 9890ULL: goto x86_l_26a2;
	case 9895ULL: goto x86_l_26a7;
	case 9900ULL: goto x86_l_26ac;
	case 9909ULL: goto x86_l_26b5;
	case 9915ULL: goto x86_l_26bb;
	case 9920ULL: goto x86_l_26c0;
	case 9925ULL: goto x86_l_26c5;
	case 9930ULL: goto x86_l_26ca;
	case 9935ULL: goto x86_l_26cf;
	case 9938ULL: goto x86_l_26d2;
	case 9940ULL: goto x86_l_26d4;
	case 9945ULL: goto x86_l_26d9;
	case 9950ULL: goto x86_l_26de;
	case 9955ULL: goto x86_l_26e3;
	case 9960ULL: goto x86_l_26e8;
	case 9965ULL: goto x86_l_26ed;
	case 9967ULL: goto x86_l_26ef;
	case 9969ULL: goto x86_l_26f1;
	case 9975ULL: goto x86_l_26f7;
	case 9984ULL: goto x86_l_2700;
	case 9990ULL: goto x86_l_2706;
	case 9997ULL: goto x86_l_270d;
	case 10002ULL: goto x86_l_2712;
	case 10007ULL: goto x86_l_2717;
	case 10016ULL: goto x86_l_2720;
	case 10018ULL: goto x86_l_2722;
	case 10023ULL: goto x86_l_2727;
	case 10028ULL: goto x86_l_272c;
	case 10033ULL: goto x86_l_2731;
	case 10038ULL: goto x86_l_2736;
	case 10043ULL: goto x86_l_273b;
	case 10045ULL: goto x86_l_273d;
	case 10047ULL: goto x86_l_273f;
	case 10053ULL: goto x86_l_2745;
	case 10062ULL: goto x86_l_274e;
	case 10068ULL: goto x86_l_2754;
	case 10075ULL: goto x86_l_275b;
	case 10080ULL: goto x86_l_2760;
	case 10085ULL: goto x86_l_2765;
	case 10094ULL: goto x86_l_276e;
	case 10096ULL: goto x86_l_2770;
	case 10101ULL: goto x86_l_2775;
	case 10106ULL: goto x86_l_277a;
	case 10111ULL: goto x86_l_277f;
	case 10116ULL: goto x86_l_2784;
	case 10121ULL: goto x86_l_2789;
	case 10123ULL: goto x86_l_278b;
	case 10125ULL: goto x86_l_278d;
	case 10131ULL: goto x86_l_2793;
	case 10140ULL: goto x86_l_279c;
	case 10146ULL: goto x86_l_27a2;
	case 10153ULL: goto x86_l_27a9;
	case 10158ULL: goto x86_l_27ae;
	case 10163ULL: goto x86_l_27b3;
	case 10172ULL: goto x86_l_27bc;
	case 10174ULL: goto x86_l_27be;
	case 10179ULL: goto x86_l_27c3;
	case 10184ULL: goto x86_l_27c8;
	case 10189ULL: goto x86_l_27cd;
	case 10194ULL: goto x86_l_27d2;
	case 10199ULL: goto x86_l_27d7;
	case 10201ULL: goto x86_l_27d9;
	case 10203ULL: goto x86_l_27db;
	case 10209ULL: goto x86_l_27e1;
	case 10218ULL: goto x86_l_27ea;
	case 10224ULL: goto x86_l_27f0;
	case 10231ULL: goto x86_l_27f7;
	case 10236ULL: goto x86_l_27fc;
	case 10241ULL: goto x86_l_2801;
	case 10250ULL: goto x86_l_280a;
	case 10252ULL: goto x86_l_280c;
	case 10257ULL: goto x86_l_2811;
	case 10262ULL: goto x86_l_2816;
	case 10267ULL: goto x86_l_281b;
	case 10272ULL: goto x86_l_2820;
	case 10277ULL: goto x86_l_2825;
	case 10279ULL: goto x86_l_2827;
	case 10281ULL: goto x86_l_2829;
	case 10287ULL: goto x86_l_282f;
	case 10296ULL: goto x86_l_2838;
	case 10302ULL: goto x86_l_283e;
	case 10309ULL: goto x86_l_2845;
	case 10314ULL: goto x86_l_284a;
	case 10319ULL: goto x86_l_284f;
	case 10328ULL: goto x86_l_2858;
	case 10330ULL: goto x86_l_285a;
	case 10335ULL: goto x86_l_285f;
	case 10340ULL: goto x86_l_2864;
	case 10345ULL: goto x86_l_2869;
	case 10350ULL: goto x86_l_286e;
	case 10355ULL: goto x86_l_2873;
	case 10357ULL: goto x86_l_2875;
	case 10359ULL: goto x86_l_2877;
	case 10365ULL: goto x86_l_287d;
	case 10374ULL: goto x86_l_2886;
	case 10380ULL: goto x86_l_288c;
	case 10387ULL: goto x86_l_2893;
	case 10392ULL: goto x86_l_2898;
	case 10397ULL: goto x86_l_289d;
	case 10406ULL: goto x86_l_28a6;
	case 10408ULL: goto x86_l_28a8;
	case 10413ULL: goto x86_l_28ad;
	case 10418ULL: goto x86_l_28b2;
	case 10423ULL: goto x86_l_28b7;
	case 10428ULL: goto x86_l_28bc;
	case 10433ULL: goto x86_l_28c1;
	case 10435ULL: goto x86_l_28c3;
	case 10437ULL: goto x86_l_28c5;
	case 10443ULL: goto x86_l_28cb;
	case 10452ULL: goto x86_l_28d4;
	case 10458ULL: goto x86_l_28da;
	case 10465ULL: goto x86_l_28e1;
	case 10470ULL: goto x86_l_28e6;
	case 10475ULL: goto x86_l_28eb;
	case 10484ULL: goto x86_l_28f4;
	case 10486ULL: goto x86_l_28f6;
	case 10491ULL: goto x86_l_28fb;
	case 10496ULL: goto x86_l_2900;
	case 10501ULL: goto x86_l_2905;
	case 10506ULL: goto x86_l_290a;
	case 10511ULL: goto x86_l_290f;
	case 10513ULL: goto x86_l_2911;
	case 10515ULL: goto x86_l_2913;
	case 10521ULL: goto x86_l_2919;
	case 10526ULL: goto x86_l_291e;
	case 10535ULL: goto x86_l_2927;
	case 10541ULL: goto x86_l_292d;
	case 10548ULL: goto x86_l_2934;
	case 10553ULL: goto x86_l_2939;
	case 10558ULL: goto x86_l_293e;
	case 10567ULL: goto x86_l_2947;
	case 10569ULL: goto x86_l_2949;
	case 10574ULL: goto x86_l_294e;
	case 10579ULL: goto x86_l_2953;
	case 10584ULL: goto x86_l_2958;
	case 10589ULL: goto x86_l_295d;
	case 10594ULL: goto x86_l_2962;
	case 10596ULL: goto x86_l_2964;
	case 10598ULL: goto x86_l_2966;
	case 10604ULL: goto x86_l_296c;
	case 10609ULL: goto x86_l_2971;
	case 10618ULL: goto x86_l_297a;
	case 10624ULL: goto x86_l_2980;
	case 10631ULL: goto x86_l_2987;
	case 10636ULL: goto x86_l_298c;
	case 10641ULL: goto x86_l_2991;
	case 10650ULL: goto x86_l_299a;
	case 10656ULL: goto x86_l_29a0;
	case 10661ULL: goto x86_l_29a5;
	case 10666ULL: goto x86_l_29aa;
	case 10671ULL: goto x86_l_29af;
	case 10676ULL: goto x86_l_29b4;
	case 10681ULL: goto x86_l_29b9;
	case 10683ULL: goto x86_l_29bb;
	case 10685ULL: goto x86_l_29bd;
	case 10691ULL: goto x86_l_29c3;
	case 10696ULL: goto x86_l_29c8;
	case 10701ULL: goto x86_l_29cd;
	case 10708ULL: goto x86_l_29d4;
	case 10714ULL: goto x86_l_29da;
	case 10717ULL: goto x86_l_29dd;
	case 10722ULL: goto x86_l_29e2;
	case 10727ULL: goto x86_l_29e7;
	case 10732ULL: goto x86_l_29ec;
	case 10737ULL: goto x86_l_29f1;
	case 10739ULL: goto x86_l_29f3;
	case 10741ULL: goto x86_l_29f5;
	case 10747ULL: goto x86_l_29fb;
	case 10754ULL: goto x86_l_2a02;
	case 10760ULL: goto x86_l_2a08;
	case 10763ULL: goto x86_l_2a0b;
	case 10768ULL: goto x86_l_2a10;
	case 10773ULL: goto x86_l_2a15;
	case 10778ULL: goto x86_l_2a1a;
	case 10783ULL: goto x86_l_2a1f;
	case 10785ULL: goto x86_l_2a21;
	case 10787ULL: goto x86_l_2a23;
	case 10789ULL: goto x86_l_2a25;
	case 10797ULL: goto x86_l_2a2d;
	case 10804ULL: goto x86_l_2a34;
	case 10811ULL: goto x86_l_2a3b;
	case 10816ULL: goto x86_l_2a40;
	case 10819ULL: goto x86_l_2a43;
	case 10824ULL: goto x86_l_2a48;
	case 10829ULL: goto x86_l_2a4d;
	case 10834ULL: goto x86_l_2a52;
	case 10842ULL: goto x86_l_2a5a;
	case 10849ULL: goto x86_l_2a61;
	case 10856ULL: goto x86_l_2a68;
	case 10861ULL: goto x86_l_2a6d;
	case 10864ULL: goto x86_l_2a70;
	case 10869ULL: goto x86_l_2a75;
	case 10871ULL: goto x86_l_2a77;
	case 10873ULL: goto x86_l_2a79;
	case 10879ULL: goto x86_l_2a7f;
	case 10882ULL: goto x86_l_2a82;
	case 10887ULL: goto x86_l_2a87;
	case 10889ULL: goto x86_l_2a89;
	case 10892ULL: goto x86_l_2a8c;
	case 10901ULL: goto x86_l_2a95;
	case 10907ULL: goto x86_l_2a9b;
	case 10914ULL: goto x86_l_2aa2;
	case 10917ULL: goto x86_l_2aa5;
	case 10924ULL: goto x86_l_2aac;
	case 10927ULL: goto x86_l_2aaf;
	case 10932ULL: goto x86_l_2ab4;
	case 10940ULL: goto x86_l_2abc;
	case 10942ULL: goto x86_l_2abe;
	case 10948ULL: goto x86_l_2ac4;
	case 10951ULL: goto x86_l_2ac7;
	case 10953ULL: goto x86_l_2ac9;
	case 10958ULL: goto x86_l_2ace;
	case 10963ULL: goto x86_l_2ad3;
	case 10968ULL: goto x86_l_2ad8;
	case 10973ULL: goto x86_l_2add;
	case 10978ULL: goto x86_l_2ae2;
	case 10980ULL: goto x86_l_2ae4;
	case 10982ULL: goto x86_l_2ae6;
	case 10988ULL: goto x86_l_2aec;
	case 10997ULL: goto x86_l_2af5;
	case 11003ULL: goto x86_l_2afb;
	case 11010ULL: goto x86_l_2b02;
	case 11015ULL: goto x86_l_2b07;
	case 11020ULL: goto x86_l_2b0c;
	case 11029ULL: goto x86_l_2b15;
	case 11031ULL: goto x86_l_2b17;
	case 11036ULL: goto x86_l_2b1c;
	case 11041ULL: goto x86_l_2b21;
	case 11046ULL: goto x86_l_2b26;
	case 11051ULL: goto x86_l_2b2b;
	case 11056ULL: goto x86_l_2b30;
	case 11058ULL: goto x86_l_2b32;
	case 11060ULL: goto x86_l_2b34;
	case 11066ULL: goto x86_l_2b3a;
	case 11075ULL: goto x86_l_2b43;
	case 11081ULL: goto x86_l_2b49;
	case 11088ULL: goto x86_l_2b50;
	case 11093ULL: goto x86_l_2b55;
	case 11098ULL: goto x86_l_2b5a;
	case 11107ULL: goto x86_l_2b63;
	case 11109ULL: goto x86_l_2b65;
	case 11114ULL: goto x86_l_2b6a;
	case 11119ULL: goto x86_l_2b6f;
	case 11124ULL: goto x86_l_2b74;
	case 11129ULL: goto x86_l_2b79;
	case 11134ULL: goto x86_l_2b7e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_23da:
	/* 0x23da: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23df:
	/* 0x23df: movzx  eax,WORD PTR [r13+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_23e7:
	/* 0x23e7: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_23e9:
	/* 0x23e9: je     26cf <generic_sleepable_preload+0x26cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26cf;
	}
x86_l_23ef:
	/* 0x23ef: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_23f2:
	/* 0x23f2: je     2417 <generic_sleepable_preload+0x2417> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2417;
	}
x86_l_23f4:
	/* 0x23f4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23f9:
	/* 0x23f9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23fe:
	/* 0x23fe: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2403:
	/* 0x2403: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2408:
	/* 0x2408: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_240d:
	/* 0x240d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_240f:
	/* 0x240f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2411:
	/* 0x2411: js     3e67 <generic_sleepable_preload+0x3e67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15975ULL;
	}
x86_l_2417:
	/* 0x2417: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_2420:
	/* 0x2420: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_2426:
	/* 0x2426: mov    ecx,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_242d:
	/* 0x242d: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2432:
	/* 0x2432: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2437:
	/* 0x2437: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_2440:
	/* 0x2440: je     2465 <generic_sleepable_preload+0x2465> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2465;
	}
x86_l_2442:
	/* 0x2442: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2447:
	/* 0x2447: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_244c:
	/* 0x244c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2451:
	/* 0x2451: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2456:
	/* 0x2456: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_245b:
	/* 0x245b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_245d:
	/* 0x245d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_245f:
	/* 0x245f: js     5408 <generic_sleepable_preload+0x5408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21512ULL;
	}
x86_l_2465:
	/* 0x2465: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_246e:
	/* 0x246e: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_2474:
	/* 0x2474: mov    ecx,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_247b:
	/* 0x247b: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2480:
	/* 0x2480: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2485:
	/* 0x2485: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_248e:
	/* 0x248e: je     24b3 <generic_sleepable_preload+0x24b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24b3;
	}
x86_l_2490:
	/* 0x2490: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2495:
	/* 0x2495: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_249a:
	/* 0x249a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_249f:
	/* 0x249f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24a4:
	/* 0x24a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24a9:
	/* 0x24a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ab:
	/* 0x24ab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24ad:
	/* 0x24ad: js     60ef <generic_sleepable_preload+0x60ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24815ULL;
	}
x86_l_24b3:
	/* 0x24b3: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_24bc:
	/* 0x24bc: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_24c2:
	/* 0x24c2: mov    ecx,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_24c9:
	/* 0x24c9: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_24ce:
	/* 0x24ce: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24d3:
	/* 0x24d3: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_24dc:
	/* 0x24dc: je     2501 <generic_sleepable_preload+0x2501> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2501;
	}
x86_l_24de:
	/* 0x24de: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24e3:
	/* 0x24e3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_24e8:
	/* 0x24e8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24ed:
	/* 0x24ed: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24f2:
	/* 0x24f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24f7:
	/* 0x24f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24f9:
	/* 0x24f9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24fb:
	/* 0x24fb: js     6153 <generic_sleepable_preload+0x6153> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24915ULL;
	}
x86_l_2501:
	/* 0x2501: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_250a:
	/* 0x250a: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_2510:
	/* 0x2510: mov    ecx,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2517:
	/* 0x2517: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_251c:
	/* 0x251c: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2521:
	/* 0x2521: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_252a:
	/* 0x252a: je     254f <generic_sleepable_preload+0x254f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_254f;
	}
x86_l_252c:
	/* 0x252c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2531:
	/* 0x2531: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2536:
	/* 0x2536: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_253b:
	/* 0x253b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2540:
	/* 0x2540: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2545:
	/* 0x2545: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2547:
	/* 0x2547: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2549:
	/* 0x2549: js     61b7 <generic_sleepable_preload+0x61b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25015ULL;
	}
x86_l_254f:
	/* 0x254f: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2558:
	/* 0x2558: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_255e:
	/* 0x255e: mov    ecx,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2565:
	/* 0x2565: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_256a:
	/* 0x256a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_256f:
	/* 0x256f: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2578:
	/* 0x2578: je     259d <generic_sleepable_preload+0x259d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_259d;
	}
x86_l_257a:
	/* 0x257a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_257f:
	/* 0x257f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2584:
	/* 0x2584: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2589:
	/* 0x2589: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_258e:
	/* 0x258e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2593:
	/* 0x2593: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2595:
	/* 0x2595: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2597:
	/* 0x2597: js     6218 <generic_sleepable_preload+0x6218> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25112ULL;
	}
x86_l_259d:
	/* 0x259d: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_25a6:
	/* 0x25a6: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_25ac:
	/* 0x25ac: mov    ecx,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_25b3:
	/* 0x25b3: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_25b8:
	/* 0x25b8: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25bd:
	/* 0x25bd: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_25c6:
	/* 0x25c6: je     25eb <generic_sleepable_preload+0x25eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25eb;
	}
x86_l_25c8:
	/* 0x25c8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25cd:
	/* 0x25cd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_25d2:
	/* 0x25d2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_25d7:
	/* 0x25d7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25dc:
	/* 0x25dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25e1:
	/* 0x25e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25e3:
	/* 0x25e3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25e5:
	/* 0x25e5: js     62ff <generic_sleepable_preload+0x62ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25343ULL;
	}
x86_l_25eb:
	/* 0x25eb: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_25f4:
	/* 0x25f4: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_25fa:
	/* 0x25fa: mov    ecx,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2601:
	/* 0x2601: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2606:
	/* 0x2606: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_260b:
	/* 0x260b: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2614:
	/* 0x2614: je     2639 <generic_sleepable_preload+0x2639> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2639;
	}
x86_l_2616:
	/* 0x2616: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_261b:
	/* 0x261b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2620:
	/* 0x2620: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2625:
	/* 0x2625: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_262a:
	/* 0x262a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_262f:
	/* 0x262f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2631:
	/* 0x2631: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2633:
	/* 0x2633: js     68ce <generic_sleepable_preload+0x68ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26830ULL;
	}
x86_l_2639:
	/* 0x2639: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2642:
	/* 0x2642: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_2648:
	/* 0x2648: mov    ecx,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_264f:
	/* 0x264f: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2654:
	/* 0x2654: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2659:
	/* 0x2659: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2662:
	/* 0x2662: je     2687 <generic_sleepable_preload+0x2687> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2687;
	}
x86_l_2664:
	/* 0x2664: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2669:
	/* 0x2669: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_266e:
	/* 0x266e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2673:
	/* 0x2673: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2678:
	/* 0x2678: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_267d:
	/* 0x267d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_267f:
	/* 0x267f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2681:
	/* 0x2681: js     693b <generic_sleepable_preload+0x693b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26939ULL;
	}
x86_l_2687:
	/* 0x2687: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_268c:
	/* 0x268c: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2695:
	/* 0x2695: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_269b:
	/* 0x269b: mov    ecx,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_26a2:
	/* 0x26a2: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_26a7:
	/* 0x26a7: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26ac:
	/* 0x26ac: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_26b5:
	/* 0x26b5: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_26bb:
	/* 0x26bb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26c0:
	/* 0x26c0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26c5:
	/* 0x26c5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26ca:
	/* 0x26ca: jmp    29af <generic_sleepable_preload+0x29af> */
	goto x86_l_29af;
x86_l_26cf:
	/* 0x26cf: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_26d2:
	/* 0x26d2: je     26f7 <generic_sleepable_preload+0x26f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26f7;
	}
x86_l_26d4:
	/* 0x26d4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26d9:
	/* 0x26d9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26de:
	/* 0x26de: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26e3:
	/* 0x26e3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26e8:
	/* 0x26e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26ed:
	/* 0x26ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26ef:
	/* 0x26ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26f1:
	/* 0x26f1: js     3e67 <generic_sleepable_preload+0x3e67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15975ULL;
	}
x86_l_26f7:
	/* 0x26f7: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_2700:
	/* 0x2700: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_2706:
	/* 0x2706: mov    ecx,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_270d:
	/* 0x270d: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2712:
	/* 0x2712: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2717:
	/* 0x2717: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_2720:
	/* 0x2720: je     2745 <generic_sleepable_preload+0x2745> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2745;
	}
x86_l_2722:
	/* 0x2722: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2727:
	/* 0x2727: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_272c:
	/* 0x272c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2731:
	/* 0x2731: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2736:
	/* 0x2736: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_273b:
	/* 0x273b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_273d:
	/* 0x273d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_273f:
	/* 0x273f: js     5408 <generic_sleepable_preload+0x5408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21512ULL;
	}
x86_l_2745:
	/* 0x2745: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_274e:
	/* 0x274e: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_2754:
	/* 0x2754: mov    ecx,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_275b:
	/* 0x275b: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2760:
	/* 0x2760: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2765:
	/* 0x2765: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_276e:
	/* 0x276e: je     2793 <generic_sleepable_preload+0x2793> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2793;
	}
x86_l_2770:
	/* 0x2770: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2775:
	/* 0x2775: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_277a:
	/* 0x277a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_277f:
	/* 0x277f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2784:
	/* 0x2784: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2789:
	/* 0x2789: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_278b:
	/* 0x278b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_278d:
	/* 0x278d: js     60ef <generic_sleepable_preload+0x60ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24815ULL;
	}
x86_l_2793:
	/* 0x2793: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_279c:
	/* 0x279c: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_27a2:
	/* 0x27a2: mov    ecx,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_27a9:
	/* 0x27a9: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_27ae:
	/* 0x27ae: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27b3:
	/* 0x27b3: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_27bc:
	/* 0x27bc: je     27e1 <generic_sleepable_preload+0x27e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e1;
	}
x86_l_27be:
	/* 0x27be: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27c3:
	/* 0x27c3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_27c8:
	/* 0x27c8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_27cd:
	/* 0x27cd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27d2:
	/* 0x27d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27d7:
	/* 0x27d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27d9:
	/* 0x27d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27db:
	/* 0x27db: js     6153 <generic_sleepable_preload+0x6153> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24915ULL;
	}
x86_l_27e1:
	/* 0x27e1: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_27ea:
	/* 0x27ea: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_27f0:
	/* 0x27f0: mov    ecx,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_27f7:
	/* 0x27f7: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_27fc:
	/* 0x27fc: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2801:
	/* 0x2801: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_280a:
	/* 0x280a: je     282f <generic_sleepable_preload+0x282f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_282f;
	}
x86_l_280c:
	/* 0x280c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2811:
	/* 0x2811: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2816:
	/* 0x2816: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_281b:
	/* 0x281b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2820:
	/* 0x2820: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2825:
	/* 0x2825: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2827:
	/* 0x2827: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2829:
	/* 0x2829: js     61b7 <generic_sleepable_preload+0x61b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25015ULL;
	}
x86_l_282f:
	/* 0x282f: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2838:
	/* 0x2838: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_283e:
	/* 0x283e: mov    ecx,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2845:
	/* 0x2845: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_284a:
	/* 0x284a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_284f:
	/* 0x284f: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2858:
	/* 0x2858: je     287d <generic_sleepable_preload+0x287d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_287d;
	}
x86_l_285a:
	/* 0x285a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_285f:
	/* 0x285f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2864:
	/* 0x2864: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2869:
	/* 0x2869: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_286e:
	/* 0x286e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2873:
	/* 0x2873: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2875:
	/* 0x2875: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2877:
	/* 0x2877: js     6218 <generic_sleepable_preload+0x6218> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25112ULL;
	}
x86_l_287d:
	/* 0x287d: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2886:
	/* 0x2886: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_288c:
	/* 0x288c: mov    ecx,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2893:
	/* 0x2893: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2898:
	/* 0x2898: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_289d:
	/* 0x289d: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_28a6:
	/* 0x28a6: je     28cb <generic_sleepable_preload+0x28cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28cb;
	}
x86_l_28a8:
	/* 0x28a8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28ad:
	/* 0x28ad: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_28b2:
	/* 0x28b2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28b7:
	/* 0x28b7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28bc:
	/* 0x28bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28c1:
	/* 0x28c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28c3:
	/* 0x28c3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28c5:
	/* 0x28c5: js     62ff <generic_sleepable_preload+0x62ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25343ULL;
	}
x86_l_28cb:
	/* 0x28cb: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_28d4:
	/* 0x28d4: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_28da:
	/* 0x28da: mov    ecx,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_28e1:
	/* 0x28e1: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_28e6:
	/* 0x28e6: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28eb:
	/* 0x28eb: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_28f4:
	/* 0x28f4: je     2919 <generic_sleepable_preload+0x2919> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2919;
	}
x86_l_28f6:
	/* 0x28f6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28fb:
	/* 0x28fb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2900:
	/* 0x2900: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2905:
	/* 0x2905: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_290a:
	/* 0x290a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_290f:
	/* 0x290f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2911:
	/* 0x2911: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2913:
	/* 0x2913: js     69d5 <generic_sleepable_preload+0x69d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27093ULL;
	}
x86_l_2919:
	/* 0x2919: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_291e:
	/* 0x291e: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2927:
	/* 0x2927: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_292d:
	/* 0x292d: mov    ecx,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2934:
	/* 0x2934: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2939:
	/* 0x2939: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_293e:
	/* 0x293e: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2947:
	/* 0x2947: je     296c <generic_sleepable_preload+0x296c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_296c;
	}
x86_l_2949:
	/* 0x2949: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_294e:
	/* 0x294e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2953:
	/* 0x2953: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2958:
	/* 0x2958: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_295d:
	/* 0x295d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2962:
	/* 0x2962: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2964:
	/* 0x2964: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2966:
	/* 0x2966: js     693b <generic_sleepable_preload+0x693b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26939ULL;
	}
x86_l_296c:
	/* 0x296c: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2971:
	/* 0x2971: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_297a:
	/* 0x297a: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_2980:
	/* 0x2980: mov    ecx,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2987:
	/* 0x2987: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_298c:
	/* 0x298c: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2991:
	/* 0x2991: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_299a:
	/* 0x299a: je     6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25350ULL;
	}
x86_l_29a0:
	/* 0x29a0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29a5:
	/* 0x29a5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_29aa:
	/* 0x29aa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_29af:
	/* 0x29af: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29b4:
	/* 0x29b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29b9:
	/* 0x29b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29bb:
	/* 0x29bb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29bd:
	/* 0x29bd: jns    6306 <generic_sleepable_preload+0x6306> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25350ULL;
	}
x86_l_29c3:
	/* 0x29c3: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_29c8:
	/* 0x29c8: jmp    6304 <generic_sleepable_preload+0x6304> */
	return 25348ULL;
x86_l_29cd:
	/* 0x29cd: mov    edx,DWORD PTR [r13+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_29d4:
	/* 0x29d4: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29da:
	/* 0x29da: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29dd:
	/* 0x29dd: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29e2:
	/* 0x29e2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29e7:
	/* 0x29e7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29ec:
	/* 0x29ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29f1:
	/* 0x29f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29f3:
	/* 0x29f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29f5:
	/* 0x29f5: jne    2a7f <generic_sleepable_preload+0x2a7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a7f;
	}
x86_l_29fb:
	/* 0x29fb: mov    edx,DWORD PTR [r13+0x23c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_2a02:
	/* 0x2a02: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a08:
	/* 0x2a08: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a0b:
	/* 0x2a0b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a10:
	/* 0x2a10: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a15:
	/* 0x2a15: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a1a:
	/* 0x2a1a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a1f:
	/* 0x2a1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a21:
	/* 0x2a21: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a23:
	/* 0x2a23: jne    2a7f <generic_sleepable_preload+0x2a7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a7f;
	}
x86_l_2a25:
	/* 0x2a25: movzx  eax,BYTE PTR [r13+0x243] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 579ULL);
x86_l_2a2d:
	/* 0x2a2d: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_2a34:
	/* 0x2a34: mov    rcx,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_2a3b:
	/* 0x2a3b: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2a40:
	/* 0x2a40: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a43:
	/* 0x2a43: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a48:
	/* 0x2a48: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a4d:
	/* 0x2a4d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a52:
	/* 0x2a52: movzx  ecx,BYTE PTR [r13+0x243] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 579ULL);
x86_l_2a5a:
	/* 0x2a5a: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_2a61:
	/* 0x2a61: mov    rdx,QWORD PTR [r13+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_2a68:
	/* 0x2a68: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2a6d:
	/* 0x2a6d: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a70:
	/* 0x2a70: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a75:
	/* 0x2a75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a77:
	/* 0x2a77: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a79:
	/* 0x2a79: je     1beb <generic_sleepable_preload+0x1beb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7147ULL;
	}
x86_l_2a7f:
	/* 0x2a7f: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_2a82:
	/* 0x2a82: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a87:
	/* 0x2a87: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a89:
	/* 0x2a89: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_2a8c:
	/* 0x2a8c: cmp    WORD PTR [r13+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_2a95:
	/* 0x2a95: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_2a9b:
	/* 0x2a9b: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_2aa2:
	/* 0x2aa2: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2aa5:
	/* 0x2aa5: mov    eax,DWORD PTR [r13+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2aac:
	/* 0x2aac: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2aaf:
	/* 0x2aaf: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ab4:
	/* 0x2ab4: movzx  eax,WORD PTR [r13+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_2abc:
	/* 0x2abc: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_2abe:
	/* 0x2abe: je     2da9 <generic_sleepable_preload+0x2da9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11689ULL;
	}
x86_l_2ac4:
	/* 0x2ac4: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2ac7:
	/* 0x2ac7: je     2aec <generic_sleepable_preload+0x2aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aec;
	}
x86_l_2ac9:
	/* 0x2ac9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ace:
	/* 0x2ace: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ad3:
	/* 0x2ad3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ad8:
	/* 0x2ad8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2add:
	/* 0x2add: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ae2:
	/* 0x2ae2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae4:
	/* 0x2ae4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ae6:
	/* 0x2ae6: js     3e71 <generic_sleepable_preload+0x3e71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15985ULL;
	}
x86_l_2aec:
	/* 0x2aec: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_2af5:
	/* 0x2af5: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_2afb:
	/* 0x2afb: mov    ecx,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2b02:
	/* 0x2b02: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2b07:
	/* 0x2b07: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b0c:
	/* 0x2b0c: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_2b15:
	/* 0x2b15: je     2b3a <generic_sleepable_preload+0x2b3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b3a;
	}
x86_l_2b17:
	/* 0x2b17: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b1c:
	/* 0x2b1c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b21:
	/* 0x2b21: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b26:
	/* 0x2b26: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b2b:
	/* 0x2b2b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b30:
	/* 0x2b30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b32:
	/* 0x2b32: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b34:
	/* 0x2b34: js     5412 <generic_sleepable_preload+0x5412> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21522ULL;
	}
x86_l_2b3a:
	/* 0x2b3a: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_2b43:
	/* 0x2b43: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_2b49:
	/* 0x2b49: mov    ecx,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2b50:
	/* 0x2b50: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2b55:
	/* 0x2b55: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b5a:
	/* 0x2b5a: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_2b63:
	/* 0x2b63: je     2b88 <generic_sleepable_preload+0x2b88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11144ULL;
	}
x86_l_2b65:
	/* 0x2b65: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b6a:
	/* 0x2b6a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b6f:
	/* 0x2b6f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b74:
	/* 0x2b74: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b79:
	/* 0x2b79: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b7e:
	/* 0x2b7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 11136ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11136ULL: goto x86_l_2b80;
	case 11138ULL: goto x86_l_2b82;
	case 11144ULL: goto x86_l_2b88;
	case 11153ULL: goto x86_l_2b91;
	case 11159ULL: goto x86_l_2b97;
	case 11166ULL: goto x86_l_2b9e;
	case 11171ULL: goto x86_l_2ba3;
	case 11176ULL: goto x86_l_2ba8;
	case 11185ULL: goto x86_l_2bb1;
	case 11187ULL: goto x86_l_2bb3;
	case 11192ULL: goto x86_l_2bb8;
	case 11197ULL: goto x86_l_2bbd;
	case 11202ULL: goto x86_l_2bc2;
	case 11207ULL: goto x86_l_2bc7;
	case 11212ULL: goto x86_l_2bcc;
	case 11214ULL: goto x86_l_2bce;
	case 11216ULL: goto x86_l_2bd0;
	case 11222ULL: goto x86_l_2bd6;
	case 11231ULL: goto x86_l_2bdf;
	case 11237ULL: goto x86_l_2be5;
	case 11244ULL: goto x86_l_2bec;
	case 11249ULL: goto x86_l_2bf1;
	case 11254ULL: goto x86_l_2bf6;
	case 11263ULL: goto x86_l_2bff;
	case 11265ULL: goto x86_l_2c01;
	case 11270ULL: goto x86_l_2c06;
	case 11275ULL: goto x86_l_2c0b;
	case 11280ULL: goto x86_l_2c10;
	case 11285ULL: goto x86_l_2c15;
	case 11290ULL: goto x86_l_2c1a;
	case 11292ULL: goto x86_l_2c1c;
	case 11294ULL: goto x86_l_2c1e;
	case 11300ULL: goto x86_l_2c24;
	case 11309ULL: goto x86_l_2c2d;
	case 11315ULL: goto x86_l_2c33;
	case 11322ULL: goto x86_l_2c3a;
	case 11327ULL: goto x86_l_2c3f;
	case 11332ULL: goto x86_l_2c44;
	case 11341ULL: goto x86_l_2c4d;
	case 11343ULL: goto x86_l_2c4f;
	case 11348ULL: goto x86_l_2c54;
	case 11353ULL: goto x86_l_2c59;
	case 11358ULL: goto x86_l_2c5e;
	case 11363ULL: goto x86_l_2c63;
	case 11368ULL: goto x86_l_2c68;
	case 11370ULL: goto x86_l_2c6a;
	case 11372ULL: goto x86_l_2c6c;
	case 11378ULL: goto x86_l_2c72;
	case 11387ULL: goto x86_l_2c7b;
	case 11393ULL: goto x86_l_2c81;
	case 11400ULL: goto x86_l_2c88;
	case 11405ULL: goto x86_l_2c8d;
	case 11410ULL: goto x86_l_2c92;
	case 11419ULL: goto x86_l_2c9b;
	case 11421ULL: goto x86_l_2c9d;
	case 11426ULL: goto x86_l_2ca2;
	case 11431ULL: goto x86_l_2ca7;
	case 11436ULL: goto x86_l_2cac;
	case 11441ULL: goto x86_l_2cb1;
	case 11446ULL: goto x86_l_2cb6;
	case 11448ULL: goto x86_l_2cb8;
	case 11450ULL: goto x86_l_2cba;
	case 11456ULL: goto x86_l_2cc0;
	case 11465ULL: goto x86_l_2cc9;
	case 11471ULL: goto x86_l_2ccf;
	case 11478ULL: goto x86_l_2cd6;
	case 11483ULL: goto x86_l_2cdb;
	case 11488ULL: goto x86_l_2ce0;
	case 11497ULL: goto x86_l_2ce9;
	case 11499ULL: goto x86_l_2ceb;
	case 11504ULL: goto x86_l_2cf0;
	case 11509ULL: goto x86_l_2cf5;
	case 11514ULL: goto x86_l_2cfa;
	case 11519ULL: goto x86_l_2cff;
	case 11524ULL: goto x86_l_2d04;
	case 11526ULL: goto x86_l_2d06;
	case 11528ULL: goto x86_l_2d08;
	case 11534ULL: goto x86_l_2d0e;
	case 11543ULL: goto x86_l_2d17;
	case 11549ULL: goto x86_l_2d1d;
	case 11556ULL: goto x86_l_2d24;
	case 11561ULL: goto x86_l_2d29;
	case 11566ULL: goto x86_l_2d2e;
	case 11575ULL: goto x86_l_2d37;
	case 11577ULL: goto x86_l_2d39;
	case 11582ULL: goto x86_l_2d3e;
	case 11587ULL: goto x86_l_2d43;
	case 11592ULL: goto x86_l_2d48;
	case 11597ULL: goto x86_l_2d4d;
	case 11602ULL: goto x86_l_2d52;
	case 11604ULL: goto x86_l_2d54;
	case 11606ULL: goto x86_l_2d56;
	case 11612ULL: goto x86_l_2d5c;
	case 11617ULL: goto x86_l_2d61;
	case 11626ULL: goto x86_l_2d6a;
	case 11631ULL: goto x86_l_2d6f;
	case 11637ULL: goto x86_l_2d75;
	case 11644ULL: goto x86_l_2d7c;
	case 11649ULL: goto x86_l_2d81;
	case 11654ULL: goto x86_l_2d86;
	case 11663ULL: goto x86_l_2d8f;
	case 11669ULL: goto x86_l_2d95;
	case 11674ULL: goto x86_l_2d9a;
	case 11679ULL: goto x86_l_2d9f;
	case 11684ULL: goto x86_l_2da4;
	case 11689ULL: goto x86_l_2da9;
	case 11692ULL: goto x86_l_2dac;
	case 11694ULL: goto x86_l_2dae;
	case 11699ULL: goto x86_l_2db3;
	case 11704ULL: goto x86_l_2db8;
	case 11709ULL: goto x86_l_2dbd;
	case 11714ULL: goto x86_l_2dc2;
	case 11719ULL: goto x86_l_2dc7;
	case 11721ULL: goto x86_l_2dc9;
	case 11723ULL: goto x86_l_2dcb;
	case 11729ULL: goto x86_l_2dd1;
	case 11738ULL: goto x86_l_2dda;
	case 11744ULL: goto x86_l_2de0;
	case 11751ULL: goto x86_l_2de7;
	case 11756ULL: goto x86_l_2dec;
	case 11761ULL: goto x86_l_2df1;
	case 11770ULL: goto x86_l_2dfa;
	case 11772ULL: goto x86_l_2dfc;
	case 11777ULL: goto x86_l_2e01;
	case 11782ULL: goto x86_l_2e06;
	case 11787ULL: goto x86_l_2e0b;
	case 11792ULL: goto x86_l_2e10;
	case 11797ULL: goto x86_l_2e15;
	case 11799ULL: goto x86_l_2e17;
	case 11801ULL: goto x86_l_2e19;
	case 11807ULL: goto x86_l_2e1f;
	case 11816ULL: goto x86_l_2e28;
	case 11822ULL: goto x86_l_2e2e;
	case 11829ULL: goto x86_l_2e35;
	case 11834ULL: goto x86_l_2e3a;
	case 11839ULL: goto x86_l_2e3f;
	case 11848ULL: goto x86_l_2e48;
	case 11850ULL: goto x86_l_2e4a;
	case 11855ULL: goto x86_l_2e4f;
	case 11860ULL: goto x86_l_2e54;
	case 11865ULL: goto x86_l_2e59;
	case 11870ULL: goto x86_l_2e5e;
	case 11875ULL: goto x86_l_2e63;
	case 11877ULL: goto x86_l_2e65;
	case 11879ULL: goto x86_l_2e67;
	case 11885ULL: goto x86_l_2e6d;
	case 11894ULL: goto x86_l_2e76;
	case 11900ULL: goto x86_l_2e7c;
	case 11907ULL: goto x86_l_2e83;
	case 11912ULL: goto x86_l_2e88;
	case 11917ULL: goto x86_l_2e8d;
	case 11926ULL: goto x86_l_2e96;
	case 11928ULL: goto x86_l_2e98;
	case 11933ULL: goto x86_l_2e9d;
	case 11938ULL: goto x86_l_2ea2;
	case 11943ULL: goto x86_l_2ea7;
	case 11948ULL: goto x86_l_2eac;
	case 11953ULL: goto x86_l_2eb1;
	case 11955ULL: goto x86_l_2eb3;
	case 11957ULL: goto x86_l_2eb5;
	case 11963ULL: goto x86_l_2ebb;
	case 11972ULL: goto x86_l_2ec4;
	case 11978ULL: goto x86_l_2eca;
	case 11985ULL: goto x86_l_2ed1;
	case 11990ULL: goto x86_l_2ed6;
	case 11995ULL: goto x86_l_2edb;
	case 12004ULL: goto x86_l_2ee4;
	case 12006ULL: goto x86_l_2ee6;
	case 12011ULL: goto x86_l_2eeb;
	case 12016ULL: goto x86_l_2ef0;
	case 12021ULL: goto x86_l_2ef5;
	case 12026ULL: goto x86_l_2efa;
	case 12031ULL: goto x86_l_2eff;
	case 12033ULL: goto x86_l_2f01;
	case 12035ULL: goto x86_l_2f03;
	case 12041ULL: goto x86_l_2f09;
	case 12050ULL: goto x86_l_2f12;
	case 12056ULL: goto x86_l_2f18;
	case 12063ULL: goto x86_l_2f1f;
	case 12068ULL: goto x86_l_2f24;
	case 12073ULL: goto x86_l_2f29;
	case 12082ULL: goto x86_l_2f32;
	case 12084ULL: goto x86_l_2f34;
	case 12089ULL: goto x86_l_2f39;
	case 12094ULL: goto x86_l_2f3e;
	case 12099ULL: goto x86_l_2f43;
	case 12104ULL: goto x86_l_2f48;
	case 12109ULL: goto x86_l_2f4d;
	case 12111ULL: goto x86_l_2f4f;
	case 12113ULL: goto x86_l_2f51;
	case 12119ULL: goto x86_l_2f57;
	case 12128ULL: goto x86_l_2f60;
	case 12134ULL: goto x86_l_2f66;
	case 12141ULL: goto x86_l_2f6d;
	case 12146ULL: goto x86_l_2f72;
	case 12151ULL: goto x86_l_2f77;
	case 12160ULL: goto x86_l_2f80;
	case 12162ULL: goto x86_l_2f82;
	case 12167ULL: goto x86_l_2f87;
	case 12172ULL: goto x86_l_2f8c;
	case 12177ULL: goto x86_l_2f91;
	case 12182ULL: goto x86_l_2f96;
	case 12187ULL: goto x86_l_2f9b;
	case 12189ULL: goto x86_l_2f9d;
	case 12191ULL: goto x86_l_2f9f;
	case 12197ULL: goto x86_l_2fa5;
	case 12206ULL: goto x86_l_2fae;
	case 12212ULL: goto x86_l_2fb4;
	case 12219ULL: goto x86_l_2fbb;
	case 12224ULL: goto x86_l_2fc0;
	case 12229ULL: goto x86_l_2fc5;
	case 12238ULL: goto x86_l_2fce;
	case 12240ULL: goto x86_l_2fd0;
	case 12245ULL: goto x86_l_2fd5;
	case 12250ULL: goto x86_l_2fda;
	case 12255ULL: goto x86_l_2fdf;
	case 12260ULL: goto x86_l_2fe4;
	case 12265ULL: goto x86_l_2fe9;
	case 12267ULL: goto x86_l_2feb;
	case 12269ULL: goto x86_l_2fed;
	case 12275ULL: goto x86_l_2ff3;
	case 12280ULL: goto x86_l_2ff8;
	case 12289ULL: goto x86_l_3001;
	case 12294ULL: goto x86_l_3006;
	case 12300ULL: goto x86_l_300c;
	case 12307ULL: goto x86_l_3013;
	case 12312ULL: goto x86_l_3018;
	case 12317ULL: goto x86_l_301d;
	case 12326ULL: goto x86_l_3026;
	case 12328ULL: goto x86_l_3028;
	case 12333ULL: goto x86_l_302d;
	case 12338ULL: goto x86_l_3032;
	case 12343ULL: goto x86_l_3037;
	case 12348ULL: goto x86_l_303c;
	case 12353ULL: goto x86_l_3041;
	case 12355ULL: goto x86_l_3043;
	case 12357ULL: goto x86_l_3045;
	case 12363ULL: goto x86_l_304b;
	case 12368ULL: goto x86_l_3050;
	case 12377ULL: goto x86_l_3059;
	case 12382ULL: goto x86_l_305e;
	case 12388ULL: goto x86_l_3064;
	case 12395ULL: goto x86_l_306b;
	case 12400ULL: goto x86_l_3070;
	case 12405ULL: goto x86_l_3075;
	case 12414ULL: goto x86_l_307e;
	case 12420ULL: goto x86_l_3084;
	case 12425ULL: goto x86_l_3089;
	case 12430ULL: goto x86_l_308e;
	case 12435ULL: goto x86_l_3093;
	case 12440ULL: goto x86_l_3098;
	case 12445ULL: goto x86_l_309d;
	case 12447ULL: goto x86_l_309f;
	case 12449ULL: goto x86_l_30a1;
	case 12455ULL: goto x86_l_30a7;
	case 12460ULL: goto x86_l_30ac;
	case 12465ULL: goto x86_l_30b1;
	case 12472ULL: goto x86_l_30b8;
	case 12478ULL: goto x86_l_30be;
	case 12481ULL: goto x86_l_30c1;
	case 12486ULL: goto x86_l_30c6;
	case 12491ULL: goto x86_l_30cb;
	case 12496ULL: goto x86_l_30d0;
	case 12501ULL: goto x86_l_30d5;
	case 12503ULL: goto x86_l_30d7;
	case 12505ULL: goto x86_l_30d9;
	case 12511ULL: goto x86_l_30df;
	case 12518ULL: goto x86_l_30e6;
	case 12524ULL: goto x86_l_30ec;
	case 12527ULL: goto x86_l_30ef;
	case 12532ULL: goto x86_l_30f4;
	case 12537ULL: goto x86_l_30f9;
	case 12542ULL: goto x86_l_30fe;
	case 12547ULL: goto x86_l_3103;
	case 12549ULL: goto x86_l_3105;
	case 12551ULL: goto x86_l_3107;
	case 12553ULL: goto x86_l_3109;
	case 12561ULL: goto x86_l_3111;
	case 12568ULL: goto x86_l_3118;
	case 12575ULL: goto x86_l_311f;
	case 12580ULL: goto x86_l_3124;
	case 12583ULL: goto x86_l_3127;
	case 12588ULL: goto x86_l_312c;
	case 12593ULL: goto x86_l_3131;
	case 12598ULL: goto x86_l_3136;
	case 12606ULL: goto x86_l_313e;
	case 12613ULL: goto x86_l_3145;
	case 12620ULL: goto x86_l_314c;
	case 12625ULL: goto x86_l_3151;
	case 12628ULL: goto x86_l_3154;
	case 12633ULL: goto x86_l_3159;
	case 12635ULL: goto x86_l_315b;
	case 12637ULL: goto x86_l_315d;
	case 12643ULL: goto x86_l_3163;
	case 12646ULL: goto x86_l_3166;
	case 12651ULL: goto x86_l_316b;
	case 12653ULL: goto x86_l_316d;
	case 12656ULL: goto x86_l_3170;
	case 12665ULL: goto x86_l_3179;
	case 12671ULL: goto x86_l_317f;
	case 12678ULL: goto x86_l_3186;
	case 12681ULL: goto x86_l_3189;
	case 12688ULL: goto x86_l_3190;
	case 12691ULL: goto x86_l_3193;
	case 12696ULL: goto x86_l_3198;
	case 12704ULL: goto x86_l_31a0;
	case 12706ULL: goto x86_l_31a2;
	case 12712ULL: goto x86_l_31a8;
	case 12715ULL: goto x86_l_31ab;
	case 12717ULL: goto x86_l_31ad;
	case 12722ULL: goto x86_l_31b2;
	case 12727ULL: goto x86_l_31b7;
	case 12732ULL: goto x86_l_31bc;
	case 12737ULL: goto x86_l_31c1;
	case 12742ULL: goto x86_l_31c6;
	case 12744ULL: goto x86_l_31c8;
	case 12746ULL: goto x86_l_31ca;
	case 12752ULL: goto x86_l_31d0;
	case 12761ULL: goto x86_l_31d9;
	case 12767ULL: goto x86_l_31df;
	case 12774ULL: goto x86_l_31e6;
	case 12779ULL: goto x86_l_31eb;
	case 12784ULL: goto x86_l_31f0;
	case 12793ULL: goto x86_l_31f9;
	case 12795ULL: goto x86_l_31fb;
	case 12800ULL: goto x86_l_3200;
	case 12805ULL: goto x86_l_3205;
	case 12810ULL: goto x86_l_320a;
	case 12815ULL: goto x86_l_320f;
	case 12820ULL: goto x86_l_3214;
	case 12822ULL: goto x86_l_3216;
	case 12824ULL: goto x86_l_3218;
	case 12830ULL: goto x86_l_321e;
	case 12839ULL: goto x86_l_3227;
	case 12845ULL: goto x86_l_322d;
	case 12852ULL: goto x86_l_3234;
	case 12857ULL: goto x86_l_3239;
	case 12862ULL: goto x86_l_323e;
	case 12871ULL: goto x86_l_3247;
	case 12873ULL: goto x86_l_3249;
	case 12878ULL: goto x86_l_324e;
	case 12883ULL: goto x86_l_3253;
	case 12888ULL: goto x86_l_3258;
	case 12893ULL: goto x86_l_325d;
	case 12898ULL: goto x86_l_3262;
	case 12900ULL: goto x86_l_3264;
	case 12902ULL: goto x86_l_3266;
	case 12908ULL: goto x86_l_326c;
	case 12917ULL: goto x86_l_3275;
	case 12923ULL: goto x86_l_327b;
	case 12930ULL: goto x86_l_3282;
	case 12935ULL: goto x86_l_3287;
	case 12940ULL: goto x86_l_328c;
	case 12949ULL: goto x86_l_3295;
	case 12951ULL: goto x86_l_3297;
	case 12956ULL: goto x86_l_329c;
	case 12961ULL: goto x86_l_32a1;
	case 12966ULL: goto x86_l_32a6;
	case 12971ULL: goto x86_l_32ab;
	case 12976ULL: goto x86_l_32b0;
	case 12978ULL: goto x86_l_32b2;
	case 12980ULL: goto x86_l_32b4;
	case 12986ULL: goto x86_l_32ba;
	case 12995ULL: goto x86_l_32c3;
	case 13001ULL: goto x86_l_32c9;
	case 13008ULL: goto x86_l_32d0;
	case 13013ULL: goto x86_l_32d5;
	case 13018ULL: goto x86_l_32da;
	case 13027ULL: goto x86_l_32e3;
	case 13029ULL: goto x86_l_32e5;
	case 13034ULL: goto x86_l_32ea;
	case 13039ULL: goto x86_l_32ef;
	case 13044ULL: goto x86_l_32f4;
	case 13049ULL: goto x86_l_32f9;
	case 13054ULL: goto x86_l_32fe;
	case 13056ULL: goto x86_l_3300;
	case 13058ULL: goto x86_l_3302;
	case 13064ULL: goto x86_l_3308;
	case 13073ULL: goto x86_l_3311;
	case 13079ULL: goto x86_l_3317;
	case 13086ULL: goto x86_l_331e;
	case 13091ULL: goto x86_l_3323;
	case 13096ULL: goto x86_l_3328;
	case 13105ULL: goto x86_l_3331;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2b80:
	/* 0x2b80: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b82:
	/* 0x2b82: js     60f9 <generic_sleepable_preload+0x60f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24825ULL;
	}
x86_l_2b88:
	/* 0x2b88: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_2b91:
	/* 0x2b91: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_2b97:
	/* 0x2b97: mov    ecx,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2b9e:
	/* 0x2b9e: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2ba3:
	/* 0x2ba3: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ba8:
	/* 0x2ba8: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_2bb1:
	/* 0x2bb1: je     2bd6 <generic_sleepable_preload+0x2bd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bd6;
	}
x86_l_2bb3:
	/* 0x2bb3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bb8:
	/* 0x2bb8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2bbd:
	/* 0x2bbd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2bc2:
	/* 0x2bc2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bc7:
	/* 0x2bc7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bcc:
	/* 0x2bcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bce:
	/* 0x2bce: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bd0:
	/* 0x2bd0: js     615d <generic_sleepable_preload+0x615d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24925ULL;
	}
x86_l_2bd6:
	/* 0x2bd6: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_2bdf:
	/* 0x2bdf: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_2be5:
	/* 0x2be5: mov    ecx,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_2bec:
	/* 0x2bec: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2bf1:
	/* 0x2bf1: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bf6:
	/* 0x2bf6: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_2bff:
	/* 0x2bff: je     2c24 <generic_sleepable_preload+0x2c24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c24;
	}
x86_l_2c01:
	/* 0x2c01: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c06:
	/* 0x2c06: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2c0b:
	/* 0x2c0b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c10:
	/* 0x2c10: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c15:
	/* 0x2c15: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c1a:
	/* 0x2c1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c1c:
	/* 0x2c1c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c1e:
	/* 0x2c1e: js     61c1 <generic_sleepable_preload+0x61c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25025ULL;
	}
x86_l_2c24:
	/* 0x2c24: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_2c2d:
	/* 0x2c2d: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_2c33:
	/* 0x2c33: mov    ecx,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_2c3a:
	/* 0x2c3a: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2c3f:
	/* 0x2c3f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c44:
	/* 0x2c44: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_2c4d:
	/* 0x2c4d: je     2c72 <generic_sleepable_preload+0x2c72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c72;
	}
x86_l_2c4f:
	/* 0x2c4f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c54:
	/* 0x2c54: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2c59:
	/* 0x2c59: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c5e:
	/* 0x2c5e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c63:
	/* 0x2c63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c68:
	/* 0x2c68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c6a:
	/* 0x2c6a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c6c:
	/* 0x2c6c: js     6222 <generic_sleepable_preload+0x6222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25122ULL;
	}
x86_l_2c72:
	/* 0x2c72: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_2c7b:
	/* 0x2c7b: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_2c81:
	/* 0x2c81: mov    ecx,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_2c88:
	/* 0x2c88: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2c8d:
	/* 0x2c8d: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c92:
	/* 0x2c92: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_2c9b:
	/* 0x2c9b: je     2cc0 <generic_sleepable_preload+0x2cc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cc0;
	}
x86_l_2c9d:
	/* 0x2c9d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ca2:
	/* 0x2ca2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ca7:
	/* 0x2ca7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2cac:
	/* 0x2cac: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cb1:
	/* 0x2cb1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cb6:
	/* 0x2cb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cb8:
	/* 0x2cb8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2cba:
	/* 0x2cba: js     638c <generic_sleepable_preload+0x638c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25484ULL;
	}
x86_l_2cc0:
	/* 0x2cc0: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_2cc9:
	/* 0x2cc9: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_2ccf:
	/* 0x2ccf: mov    ecx,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_2cd6:
	/* 0x2cd6: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2cdb:
	/* 0x2cdb: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ce0:
	/* 0x2ce0: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_2ce9:
	/* 0x2ce9: je     2d0e <generic_sleepable_preload+0x2d0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d0e;
	}
x86_l_2ceb:
	/* 0x2ceb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cf0:
	/* 0x2cf0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2cf5:
	/* 0x2cf5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2cfa:
	/* 0x2cfa: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cff:
	/* 0x2cff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d04:
	/* 0x2d04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d06:
	/* 0x2d06: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d08:
	/* 0x2d08: js     68da <generic_sleepable_preload+0x68da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26842ULL;
	}
x86_l_2d0e:
	/* 0x2d0e: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_2d17:
	/* 0x2d17: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_2d1d:
	/* 0x2d1d: mov    ecx,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_2d24:
	/* 0x2d24: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2d29:
	/* 0x2d29: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d2e:
	/* 0x2d2e: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_2d37:
	/* 0x2d37: je     2d5c <generic_sleepable_preload+0x2d5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d5c;
	}
x86_l_2d39:
	/* 0x2d39: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d3e:
	/* 0x2d3e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d43:
	/* 0x2d43: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d48:
	/* 0x2d48: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d4d:
	/* 0x2d4d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d52:
	/* 0x2d52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d54:
	/* 0x2d54: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d56:
	/* 0x2d56: js     694c <generic_sleepable_preload+0x694c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26956ULL;
	}
x86_l_2d5c:
	/* 0x2d5c: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d61:
	/* 0x2d61: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_2d6a:
	/* 0x2d6a: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d6f:
	/* 0x2d6f: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_2d75:
	/* 0x2d75: mov    ecx,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_2d7c:
	/* 0x2d7c: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2d81:
	/* 0x2d81: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d86:
	/* 0x2d86: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_2d8f:
	/* 0x2d8f: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_2d95:
	/* 0x2d95: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d9a:
	/* 0x2d9a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d9f:
	/* 0x2d9f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2da4:
	/* 0x2da4: jmp    3093 <generic_sleepable_preload+0x3093> */
	goto x86_l_3093;
x86_l_2da9:
	/* 0x2da9: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2dac:
	/* 0x2dac: je     2dd1 <generic_sleepable_preload+0x2dd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dd1;
	}
x86_l_2dae:
	/* 0x2dae: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2db3:
	/* 0x2db3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2db8:
	/* 0x2db8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2dbd:
	/* 0x2dbd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dc2:
	/* 0x2dc2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dc7:
	/* 0x2dc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dc9:
	/* 0x2dc9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2dcb:
	/* 0x2dcb: js     3e71 <generic_sleepable_preload+0x3e71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15985ULL;
	}
x86_l_2dd1:
	/* 0x2dd1: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_2dda:
	/* 0x2dda: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_2de0:
	/* 0x2de0: mov    ecx,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2de7:
	/* 0x2de7: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2dec:
	/* 0x2dec: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2df1:
	/* 0x2df1: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_2dfa:
	/* 0x2dfa: je     2e1f <generic_sleepable_preload+0x2e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e1f;
	}
x86_l_2dfc:
	/* 0x2dfc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e01:
	/* 0x2e01: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e06:
	/* 0x2e06: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2e0b:
	/* 0x2e0b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e10:
	/* 0x2e10: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e15:
	/* 0x2e15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e17:
	/* 0x2e17: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e19:
	/* 0x2e19: js     5412 <generic_sleepable_preload+0x5412> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21522ULL;
	}
x86_l_2e1f:
	/* 0x2e1f: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_2e28:
	/* 0x2e28: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_2e2e:
	/* 0x2e2e: mov    ecx,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2e35:
	/* 0x2e35: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2e3a:
	/* 0x2e3a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e3f:
	/* 0x2e3f: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_2e48:
	/* 0x2e48: je     2e6d <generic_sleepable_preload+0x2e6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e6d;
	}
x86_l_2e4a:
	/* 0x2e4a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e4f:
	/* 0x2e4f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e54:
	/* 0x2e54: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2e59:
	/* 0x2e59: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e5e:
	/* 0x2e5e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e63:
	/* 0x2e63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e65:
	/* 0x2e65: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e67:
	/* 0x2e67: js     60f9 <generic_sleepable_preload+0x60f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24825ULL;
	}
x86_l_2e6d:
	/* 0x2e6d: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_2e76:
	/* 0x2e76: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_2e7c:
	/* 0x2e7c: mov    ecx,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2e83:
	/* 0x2e83: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2e88:
	/* 0x2e88: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e8d:
	/* 0x2e8d: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_2e96:
	/* 0x2e96: je     2ebb <generic_sleepable_preload+0x2ebb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ebb;
	}
x86_l_2e98:
	/* 0x2e98: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e9d:
	/* 0x2e9d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ea2:
	/* 0x2ea2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ea7:
	/* 0x2ea7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eac:
	/* 0x2eac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2eb1:
	/* 0x2eb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eb3:
	/* 0x2eb3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2eb5:
	/* 0x2eb5: js     615d <generic_sleepable_preload+0x615d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24925ULL;
	}
x86_l_2ebb:
	/* 0x2ebb: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_2ec4:
	/* 0x2ec4: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_2eca:
	/* 0x2eca: mov    ecx,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_2ed1:
	/* 0x2ed1: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2ed6:
	/* 0x2ed6: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2edb:
	/* 0x2edb: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_2ee4:
	/* 0x2ee4: je     2f09 <generic_sleepable_preload+0x2f09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f09;
	}
x86_l_2ee6:
	/* 0x2ee6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eeb:
	/* 0x2eeb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ef0:
	/* 0x2ef0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ef5:
	/* 0x2ef5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2efa:
	/* 0x2efa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2eff:
	/* 0x2eff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f01:
	/* 0x2f01: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f03:
	/* 0x2f03: js     61c1 <generic_sleepable_preload+0x61c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25025ULL;
	}
x86_l_2f09:
	/* 0x2f09: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_2f12:
	/* 0x2f12: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_2f18:
	/* 0x2f18: mov    ecx,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_2f1f:
	/* 0x2f1f: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2f24:
	/* 0x2f24: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f29:
	/* 0x2f29: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_2f32:
	/* 0x2f32: je     2f57 <generic_sleepable_preload+0x2f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f57;
	}
x86_l_2f34:
	/* 0x2f34: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f39:
	/* 0x2f39: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f3e:
	/* 0x2f3e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f43:
	/* 0x2f43: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f48:
	/* 0x2f48: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f4d:
	/* 0x2f4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f4f:
	/* 0x2f4f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f51:
	/* 0x2f51: js     6222 <generic_sleepable_preload+0x6222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25122ULL;
	}
x86_l_2f57:
	/* 0x2f57: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_2f60:
	/* 0x2f60: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_2f66:
	/* 0x2f66: mov    ecx,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_2f6d:
	/* 0x2f6d: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2f72:
	/* 0x2f72: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f77:
	/* 0x2f77: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_2f80:
	/* 0x2f80: je     2fa5 <generic_sleepable_preload+0x2fa5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fa5;
	}
x86_l_2f82:
	/* 0x2f82: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f87:
	/* 0x2f87: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f8c:
	/* 0x2f8c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f91:
	/* 0x2f91: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f96:
	/* 0x2f96: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f9b:
	/* 0x2f9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f9d:
	/* 0x2f9d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f9f:
	/* 0x2f9f: js     638c <generic_sleepable_preload+0x638c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25484ULL;
	}
x86_l_2fa5:
	/* 0x2fa5: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_2fae:
	/* 0x2fae: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_2fb4:
	/* 0x2fb4: mov    ecx,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_2fbb:
	/* 0x2fbb: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2fc0:
	/* 0x2fc0: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fc5:
	/* 0x2fc5: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_2fce:
	/* 0x2fce: je     2ff3 <generic_sleepable_preload+0x2ff3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ff3;
	}
x86_l_2fd0:
	/* 0x2fd0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fd5:
	/* 0x2fd5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2fda:
	/* 0x2fda: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2fdf:
	/* 0x2fdf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fe4:
	/* 0x2fe4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fe9:
	/* 0x2fe9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2feb:
	/* 0x2feb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fed:
	/* 0x2fed: js     69e6 <generic_sleepable_preload+0x69e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27110ULL;
	}
x86_l_2ff3:
	/* 0x2ff3: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ff8:
	/* 0x2ff8: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3001:
	/* 0x3001: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3006:
	/* 0x3006: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_300c:
	/* 0x300c: mov    ecx,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3013:
	/* 0x3013: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3018:
	/* 0x3018: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_301d:
	/* 0x301d: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3026:
	/* 0x3026: je     304b <generic_sleepable_preload+0x304b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_304b;
	}
x86_l_3028:
	/* 0x3028: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_302d:
	/* 0x302d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3032:
	/* 0x3032: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3037:
	/* 0x3037: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_303c:
	/* 0x303c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3041:
	/* 0x3041: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3043:
	/* 0x3043: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3045:
	/* 0x3045: js     694c <generic_sleepable_preload+0x694c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26956ULL;
	}
x86_l_304b:
	/* 0x304b: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3050:
	/* 0x3050: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_3059:
	/* 0x3059: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_305e:
	/* 0x305e: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_3064:
	/* 0x3064: mov    ecx,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_306b:
	/* 0x306b: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3070:
	/* 0x3070: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3075:
	/* 0x3075: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_307e:
	/* 0x307e: je     6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25491ULL;
	}
x86_l_3084:
	/* 0x3084: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3089:
	/* 0x3089: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_308e:
	/* 0x308e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3093:
	/* 0x3093: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3098:
	/* 0x3098: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_309d:
	/* 0x309d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_309f:
	/* 0x309f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30a1:
	/* 0x30a1: jns    6393 <generic_sleepable_preload+0x6393> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25491ULL;
	}
x86_l_30a7:
	/* 0x30a7: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_30ac:
	/* 0x30ac: jmp    6391 <generic_sleepable_preload+0x6391> */
	return 25489ULL;
x86_l_30b1:
	/* 0x30b1: mov    edx,DWORD PTR [r13+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_30b8:
	/* 0x30b8: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_30be:
	/* 0x30be: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30c1:
	/* 0x30c1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30c6:
	/* 0x30c6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_30cb:
	/* 0x30cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30d0:
	/* 0x30d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30d5:
	/* 0x30d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30d7:
	/* 0x30d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30d9:
	/* 0x30d9: jne    3163 <generic_sleepable_preload+0x3163> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3163;
	}
x86_l_30df:
	/* 0x30df: mov    edx,DWORD PTR [r13+0x254] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 596ULL);
x86_l_30e6:
	/* 0x30e6: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_30ec:
	/* 0x30ec: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30ef:
	/* 0x30ef: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30f4:
	/* 0x30f4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_30f9:
	/* 0x30f9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30fe:
	/* 0x30fe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3103:
	/* 0x3103: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3105:
	/* 0x3105: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3107:
	/* 0x3107: jne    3163 <generic_sleepable_preload+0x3163> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3163;
	}
x86_l_3109:
	/* 0x3109: movzx  eax,BYTE PTR [r13+0x25b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 603ULL);
x86_l_3111:
	/* 0x3111: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_3118:
	/* 0x3118: mov    rcx,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_311f:
	/* 0x311f: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_3124:
	/* 0x3124: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3127:
	/* 0x3127: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_312c:
	/* 0x312c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3131:
	/* 0x3131: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3136:
	/* 0x3136: movzx  ecx,BYTE PTR [r13+0x25b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 603ULL);
x86_l_313e:
	/* 0x313e: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_3145:
	/* 0x3145: mov    rdx,QWORD PTR [r13+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_314c:
	/* 0x314c: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_3151:
	/* 0x3151: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3154:
	/* 0x3154: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3159:
	/* 0x3159: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_315b:
	/* 0x315b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_315d:
	/* 0x315d: je     1c21 <generic_sleepable_preload+0x1c21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7201ULL;
	}
x86_l_3163:
	/* 0x3163: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3166:
	/* 0x3166: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_316b:
	/* 0x316b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_316d:
	/* 0x316d: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_3170:
	/* 0x3170: cmp    WORD PTR [r13+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_3179:
	/* 0x3179: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_317f:
	/* 0x317f: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3186:
	/* 0x3186: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3189:
	/* 0x3189: mov    eax,DWORD PTR [r13+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_3190:
	/* 0x3190: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3193:
	/* 0x3193: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3198:
	/* 0x3198: movzx  eax,WORD PTR [r13+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_31a0:
	/* 0x31a0: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_31a2:
	/* 0x31a2: je     3488 <generic_sleepable_preload+0x3488> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13448ULL;
	}
x86_l_31a8:
	/* 0x31a8: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_31ab:
	/* 0x31ab: je     31d0 <generic_sleepable_preload+0x31d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31d0;
	}
x86_l_31ad:
	/* 0x31ad: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31b2:
	/* 0x31b2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_31b7:
	/* 0x31b7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_31bc:
	/* 0x31bc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31c1:
	/* 0x31c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31c6:
	/* 0x31c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31c8:
	/* 0x31c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31ca:
	/* 0x31ca: js     3e7b <generic_sleepable_preload+0x3e7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15995ULL;
	}
x86_l_31d0:
	/* 0x31d0: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_31d9:
	/* 0x31d9: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_31df:
	/* 0x31df: mov    ecx,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_31e6:
	/* 0x31e6: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_31eb:
	/* 0x31eb: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31f0:
	/* 0x31f0: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_31f9:
	/* 0x31f9: je     321e <generic_sleepable_preload+0x321e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_321e;
	}
x86_l_31fb:
	/* 0x31fb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3200:
	/* 0x3200: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3205:
	/* 0x3205: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_320a:
	/* 0x320a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_320f:
	/* 0x320f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3214:
	/* 0x3214: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3216:
	/* 0x3216: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3218:
	/* 0x3218: js     541c <generic_sleepable_preload+0x541c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21532ULL;
	}
x86_l_321e:
	/* 0x321e: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_3227:
	/* 0x3227: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_322d:
	/* 0x322d: mov    ecx,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_3234:
	/* 0x3234: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3239:
	/* 0x3239: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_323e:
	/* 0x323e: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_3247:
	/* 0x3247: je     326c <generic_sleepable_preload+0x326c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_326c;
	}
x86_l_3249:
	/* 0x3249: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_324e:
	/* 0x324e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3253:
	/* 0x3253: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3258:
	/* 0x3258: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_325d:
	/* 0x325d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3262:
	/* 0x3262: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3264:
	/* 0x3264: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3266:
	/* 0x3266: js     6103 <generic_sleepable_preload+0x6103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24835ULL;
	}
x86_l_326c:
	/* 0x326c: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_3275:
	/* 0x3275: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_327b:
	/* 0x327b: mov    ecx,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_3282:
	/* 0x3282: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3287:
	/* 0x3287: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_328c:
	/* 0x328c: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_3295:
	/* 0x3295: je     32ba <generic_sleepable_preload+0x32ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32ba;
	}
x86_l_3297:
	/* 0x3297: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_329c:
	/* 0x329c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32a1:
	/* 0x32a1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_32a6:
	/* 0x32a6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32ab:
	/* 0x32ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32b0:
	/* 0x32b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32b2:
	/* 0x32b2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32b4:
	/* 0x32b4: js     6167 <generic_sleepable_preload+0x6167> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24935ULL;
	}
x86_l_32ba:
	/* 0x32ba: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_32c3:
	/* 0x32c3: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_32c9:
	/* 0x32c9: mov    ecx,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_32d0:
	/* 0x32d0: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_32d5:
	/* 0x32d5: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32da:
	/* 0x32da: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_32e3:
	/* 0x32e3: je     3308 <generic_sleepable_preload+0x3308> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3308;
	}
x86_l_32e5:
	/* 0x32e5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32ea:
	/* 0x32ea: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32ef:
	/* 0x32ef: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_32f4:
	/* 0x32f4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32f9:
	/* 0x32f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32fe:
	/* 0x32fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3300:
	/* 0x3300: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3302:
	/* 0x3302: js     61cb <generic_sleepable_preload+0x61cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25035ULL;
	}
x86_l_3308:
	/* 0x3308: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_3311:
	/* 0x3311: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_3317:
	/* 0x3317: mov    ecx,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_331e:
	/* 0x331e: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3323:
	/* 0x3323: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3328:
	/* 0x3328: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_3331:
	/* 0x3331: je     3356 <generic_sleepable_preload+0x3356> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13142ULL;
	}
	return 13107ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13107ULL: goto x86_l_3333;
	case 13112ULL: goto x86_l_3338;
	case 13117ULL: goto x86_l_333d;
	case 13122ULL: goto x86_l_3342;
	case 13127ULL: goto x86_l_3347;
	case 13132ULL: goto x86_l_334c;
	case 13134ULL: goto x86_l_334e;
	case 13136ULL: goto x86_l_3350;
	case 13142ULL: goto x86_l_3356;
	case 13151ULL: goto x86_l_335f;
	case 13157ULL: goto x86_l_3365;
	case 13164ULL: goto x86_l_336c;
	case 13169ULL: goto x86_l_3371;
	case 13174ULL: goto x86_l_3376;
	case 13183ULL: goto x86_l_337f;
	case 13185ULL: goto x86_l_3381;
	case 13190ULL: goto x86_l_3386;
	case 13195ULL: goto x86_l_338b;
	case 13200ULL: goto x86_l_3390;
	case 13205ULL: goto x86_l_3395;
	case 13210ULL: goto x86_l_339a;
	case 13212ULL: goto x86_l_339c;
	case 13214ULL: goto x86_l_339e;
	case 13220ULL: goto x86_l_33a4;
	case 13229ULL: goto x86_l_33ad;
	case 13235ULL: goto x86_l_33b3;
	case 13242ULL: goto x86_l_33ba;
	case 13247ULL: goto x86_l_33bf;
	case 13252ULL: goto x86_l_33c4;
	case 13261ULL: goto x86_l_33cd;
	case 13263ULL: goto x86_l_33cf;
	case 13268ULL: goto x86_l_33d4;
	case 13273ULL: goto x86_l_33d9;
	case 13278ULL: goto x86_l_33de;
	case 13283ULL: goto x86_l_33e3;
	case 13288ULL: goto x86_l_33e8;
	case 13290ULL: goto x86_l_33ea;
	case 13292ULL: goto x86_l_33ec;
	case 13298ULL: goto x86_l_33f2;
	case 13307ULL: goto x86_l_33fb;
	case 13313ULL: goto x86_l_3401;
	case 13320ULL: goto x86_l_3408;
	case 13325ULL: goto x86_l_340d;
	case 13330ULL: goto x86_l_3412;
	case 13339ULL: goto x86_l_341b;
	case 13341ULL: goto x86_l_341d;
	case 13346ULL: goto x86_l_3422;
	case 13351ULL: goto x86_l_3427;
	case 13356ULL: goto x86_l_342c;
	case 13361ULL: goto x86_l_3431;
	case 13366ULL: goto x86_l_3436;
	case 13368ULL: goto x86_l_3438;
	case 13370ULL: goto x86_l_343a;
	case 13376ULL: goto x86_l_3440;
	case 13381ULL: goto x86_l_3445;
	case 13390ULL: goto x86_l_344e;
	case 13396ULL: goto x86_l_3454;
	case 13403ULL: goto x86_l_345b;
	case 13408ULL: goto x86_l_3460;
	case 13413ULL: goto x86_l_3465;
	case 13422ULL: goto x86_l_346e;
	case 13428ULL: goto x86_l_3474;
	case 13433ULL: goto x86_l_3479;
	case 13438ULL: goto x86_l_347e;
	case 13443ULL: goto x86_l_3483;
	case 13448ULL: goto x86_l_3488;
	case 13451ULL: goto x86_l_348b;
	case 13453ULL: goto x86_l_348d;
	case 13458ULL: goto x86_l_3492;
	case 13463ULL: goto x86_l_3497;
	case 13468ULL: goto x86_l_349c;
	case 13473ULL: goto x86_l_34a1;
	case 13478ULL: goto x86_l_34a6;
	case 13480ULL: goto x86_l_34a8;
	case 13482ULL: goto x86_l_34aa;
	case 13488ULL: goto x86_l_34b0;
	case 13497ULL: goto x86_l_34b9;
	case 13503ULL: goto x86_l_34bf;
	case 13510ULL: goto x86_l_34c6;
	case 13515ULL: goto x86_l_34cb;
	case 13520ULL: goto x86_l_34d0;
	case 13529ULL: goto x86_l_34d9;
	case 13531ULL: goto x86_l_34db;
	case 13536ULL: goto x86_l_34e0;
	case 13541ULL: goto x86_l_34e5;
	case 13546ULL: goto x86_l_34ea;
	case 13551ULL: goto x86_l_34ef;
	case 13556ULL: goto x86_l_34f4;
	case 13558ULL: goto x86_l_34f6;
	case 13560ULL: goto x86_l_34f8;
	case 13566ULL: goto x86_l_34fe;
	case 13575ULL: goto x86_l_3507;
	case 13581ULL: goto x86_l_350d;
	case 13588ULL: goto x86_l_3514;
	case 13593ULL: goto x86_l_3519;
	case 13598ULL: goto x86_l_351e;
	case 13607ULL: goto x86_l_3527;
	case 13609ULL: goto x86_l_3529;
	case 13614ULL: goto x86_l_352e;
	case 13619ULL: goto x86_l_3533;
	case 13624ULL: goto x86_l_3538;
	case 13629ULL: goto x86_l_353d;
	case 13634ULL: goto x86_l_3542;
	case 13636ULL: goto x86_l_3544;
	case 13638ULL: goto x86_l_3546;
	case 13644ULL: goto x86_l_354c;
	case 13653ULL: goto x86_l_3555;
	case 13659ULL: goto x86_l_355b;
	case 13666ULL: goto x86_l_3562;
	case 13671ULL: goto x86_l_3567;
	case 13676ULL: goto x86_l_356c;
	case 13685ULL: goto x86_l_3575;
	case 13687ULL: goto x86_l_3577;
	case 13692ULL: goto x86_l_357c;
	case 13697ULL: goto x86_l_3581;
	case 13702ULL: goto x86_l_3586;
	case 13707ULL: goto x86_l_358b;
	case 13712ULL: goto x86_l_3590;
	case 13714ULL: goto x86_l_3592;
	case 13716ULL: goto x86_l_3594;
	case 13722ULL: goto x86_l_359a;
	case 13731ULL: goto x86_l_35a3;
	case 13737ULL: goto x86_l_35a9;
	case 13744ULL: goto x86_l_35b0;
	case 13749ULL: goto x86_l_35b5;
	case 13754ULL: goto x86_l_35ba;
	case 13763ULL: goto x86_l_35c3;
	case 13765ULL: goto x86_l_35c5;
	case 13770ULL: goto x86_l_35ca;
	case 13775ULL: goto x86_l_35cf;
	case 13780ULL: goto x86_l_35d4;
	case 13785ULL: goto x86_l_35d9;
	case 13790ULL: goto x86_l_35de;
	case 13792ULL: goto x86_l_35e0;
	case 13794ULL: goto x86_l_35e2;
	case 13800ULL: goto x86_l_35e8;
	case 13809ULL: goto x86_l_35f1;
	case 13815ULL: goto x86_l_35f7;
	case 13822ULL: goto x86_l_35fe;
	case 13827ULL: goto x86_l_3603;
	case 13832ULL: goto x86_l_3608;
	case 13841ULL: goto x86_l_3611;
	case 13843ULL: goto x86_l_3613;
	case 13848ULL: goto x86_l_3618;
	case 13853ULL: goto x86_l_361d;
	case 13858ULL: goto x86_l_3622;
	case 13863ULL: goto x86_l_3627;
	case 13868ULL: goto x86_l_362c;
	case 13870ULL: goto x86_l_362e;
	case 13872ULL: goto x86_l_3630;
	case 13878ULL: goto x86_l_3636;
	case 13887ULL: goto x86_l_363f;
	case 13893ULL: goto x86_l_3645;
	case 13900ULL: goto x86_l_364c;
	case 13905ULL: goto x86_l_3651;
	case 13910ULL: goto x86_l_3656;
	case 13919ULL: goto x86_l_365f;
	case 13921ULL: goto x86_l_3661;
	case 13926ULL: goto x86_l_3666;
	case 13931ULL: goto x86_l_366b;
	case 13936ULL: goto x86_l_3670;
	case 13941ULL: goto x86_l_3675;
	case 13946ULL: goto x86_l_367a;
	case 13948ULL: goto x86_l_367c;
	case 13950ULL: goto x86_l_367e;
	case 13956ULL: goto x86_l_3684;
	case 13965ULL: goto x86_l_368d;
	case 13971ULL: goto x86_l_3693;
	case 13978ULL: goto x86_l_369a;
	case 13983ULL: goto x86_l_369f;
	case 13988ULL: goto x86_l_36a4;
	case 13997ULL: goto x86_l_36ad;
	case 13999ULL: goto x86_l_36af;
	case 14004ULL: goto x86_l_36b4;
	case 14009ULL: goto x86_l_36b9;
	case 14014ULL: goto x86_l_36be;
	case 14019ULL: goto x86_l_36c3;
	case 14024ULL: goto x86_l_36c8;
	case 14026ULL: goto x86_l_36ca;
	case 14028ULL: goto x86_l_36cc;
	case 14034ULL: goto x86_l_36d2;
	case 14039ULL: goto x86_l_36d7;
	case 14048ULL: goto x86_l_36e0;
	case 14054ULL: goto x86_l_36e6;
	case 14061ULL: goto x86_l_36ed;
	case 14066ULL: goto x86_l_36f2;
	case 14071ULL: goto x86_l_36f7;
	case 14080ULL: goto x86_l_3700;
	case 14082ULL: goto x86_l_3702;
	case 14087ULL: goto x86_l_3707;
	case 14092ULL: goto x86_l_370c;
	case 14097ULL: goto x86_l_3711;
	case 14102ULL: goto x86_l_3716;
	case 14107ULL: goto x86_l_371b;
	case 14109ULL: goto x86_l_371d;
	case 14111ULL: goto x86_l_371f;
	case 14117ULL: goto x86_l_3725;
	case 14122ULL: goto x86_l_372a;
	case 14131ULL: goto x86_l_3733;
	case 14137ULL: goto x86_l_3739;
	case 14144ULL: goto x86_l_3740;
	case 14149ULL: goto x86_l_3745;
	case 14154ULL: goto x86_l_374a;
	case 14163ULL: goto x86_l_3753;
	case 14169ULL: goto x86_l_3759;
	case 14174ULL: goto x86_l_375e;
	case 14179ULL: goto x86_l_3763;
	case 14184ULL: goto x86_l_3768;
	case 14189ULL: goto x86_l_376d;
	case 14194ULL: goto x86_l_3772;
	case 14196ULL: goto x86_l_3774;
	case 14198ULL: goto x86_l_3776;
	case 14204ULL: goto x86_l_377c;
	case 14209ULL: goto x86_l_3781;
	case 14214ULL: goto x86_l_3786;
	case 14221ULL: goto x86_l_378d;
	case 14227ULL: goto x86_l_3793;
	case 14230ULL: goto x86_l_3796;
	case 14235ULL: goto x86_l_379b;
	case 14240ULL: goto x86_l_37a0;
	case 14245ULL: goto x86_l_37a5;
	case 14250ULL: goto x86_l_37aa;
	case 14252ULL: goto x86_l_37ac;
	case 14254ULL: goto x86_l_37ae;
	case 14260ULL: goto x86_l_37b4;
	case 14267ULL: goto x86_l_37bb;
	case 14272ULL: goto x86_l_37c0;
	case 14275ULL: goto x86_l_37c3;
	case 14280ULL: goto x86_l_37c8;
	case 14285ULL: goto x86_l_37cd;
	case 14290ULL: goto x86_l_37d2;
	case 14295ULL: goto x86_l_37d7;
	case 14298ULL: goto x86_l_37da;
	case 14300ULL: goto x86_l_37dc;
	case 14302ULL: goto x86_l_37de;
	case 14304ULL: goto x86_l_37e0;
	case 14312ULL: goto x86_l_37e8;
	case 14319ULL: goto x86_l_37ef;
	case 14326ULL: goto x86_l_37f6;
	case 14331ULL: goto x86_l_37fb;
	case 14334ULL: goto x86_l_37fe;
	case 14339ULL: goto x86_l_3803;
	case 14344ULL: goto x86_l_3808;
	case 14349ULL: goto x86_l_380d;
	case 14357ULL: goto x86_l_3815;
	case 14364ULL: goto x86_l_381c;
	case 14371ULL: goto x86_l_3823;
	case 14376ULL: goto x86_l_3828;
	case 14379ULL: goto x86_l_382b;
	case 14384ULL: goto x86_l_3830;
	case 14386ULL: goto x86_l_3832;
	case 14388ULL: goto x86_l_3834;
	case 14394ULL: goto x86_l_383a;
	case 14397ULL: goto x86_l_383d;
	case 14402ULL: goto x86_l_3842;
	case 14404ULL: goto x86_l_3844;
	case 14407ULL: goto x86_l_3847;
	case 14416ULL: goto x86_l_3850;
	case 14422ULL: goto x86_l_3856;
	case 14429ULL: goto x86_l_385d;
	case 14432ULL: goto x86_l_3860;
	case 14439ULL: goto x86_l_3867;
	case 14442ULL: goto x86_l_386a;
	case 14447ULL: goto x86_l_386f;
	case 14455ULL: goto x86_l_3877;
	case 14457ULL: goto x86_l_3879;
	case 14463ULL: goto x86_l_387f;
	case 14466ULL: goto x86_l_3882;
	case 14468ULL: goto x86_l_3884;
	case 14473ULL: goto x86_l_3889;
	case 14478ULL: goto x86_l_388e;
	case 14483ULL: goto x86_l_3893;
	case 14488ULL: goto x86_l_3898;
	case 14493ULL: goto x86_l_389d;
	case 14495ULL: goto x86_l_389f;
	case 14497ULL: goto x86_l_38a1;
	case 14503ULL: goto x86_l_38a7;
	case 14512ULL: goto x86_l_38b0;
	case 14518ULL: goto x86_l_38b6;
	case 14525ULL: goto x86_l_38bd;
	case 14530ULL: goto x86_l_38c2;
	case 14535ULL: goto x86_l_38c7;
	case 14544ULL: goto x86_l_38d0;
	case 14546ULL: goto x86_l_38d2;
	case 14551ULL: goto x86_l_38d7;
	case 14556ULL: goto x86_l_38dc;
	case 14561ULL: goto x86_l_38e1;
	case 14566ULL: goto x86_l_38e6;
	case 14571ULL: goto x86_l_38eb;
	case 14573ULL: goto x86_l_38ed;
	case 14575ULL: goto x86_l_38ef;
	case 14581ULL: goto x86_l_38f5;
	case 14590ULL: goto x86_l_38fe;
	case 14596ULL: goto x86_l_3904;
	case 14603ULL: goto x86_l_390b;
	case 14608ULL: goto x86_l_3910;
	case 14613ULL: goto x86_l_3915;
	case 14622ULL: goto x86_l_391e;
	case 14624ULL: goto x86_l_3920;
	case 14629ULL: goto x86_l_3925;
	case 14634ULL: goto x86_l_392a;
	case 14639ULL: goto x86_l_392f;
	case 14644ULL: goto x86_l_3934;
	case 14649ULL: goto x86_l_3939;
	case 14651ULL: goto x86_l_393b;
	case 14653ULL: goto x86_l_393d;
	case 14659ULL: goto x86_l_3943;
	case 14668ULL: goto x86_l_394c;
	case 14674ULL: goto x86_l_3952;
	case 14681ULL: goto x86_l_3959;
	case 14686ULL: goto x86_l_395e;
	case 14691ULL: goto x86_l_3963;
	case 14700ULL: goto x86_l_396c;
	case 14702ULL: goto x86_l_396e;
	case 14707ULL: goto x86_l_3973;
	case 14712ULL: goto x86_l_3978;
	case 14717ULL: goto x86_l_397d;
	case 14722ULL: goto x86_l_3982;
	case 14727ULL: goto x86_l_3987;
	case 14729ULL: goto x86_l_3989;
	case 14731ULL: goto x86_l_398b;
	case 14737ULL: goto x86_l_3991;
	case 14746ULL: goto x86_l_399a;
	case 14752ULL: goto x86_l_39a0;
	case 14759ULL: goto x86_l_39a7;
	case 14764ULL: goto x86_l_39ac;
	case 14769ULL: goto x86_l_39b1;
	case 14778ULL: goto x86_l_39ba;
	case 14780ULL: goto x86_l_39bc;
	case 14785ULL: goto x86_l_39c1;
	case 14790ULL: goto x86_l_39c6;
	case 14795ULL: goto x86_l_39cb;
	case 14800ULL: goto x86_l_39d0;
	case 14805ULL: goto x86_l_39d5;
	case 14807ULL: goto x86_l_39d7;
	case 14809ULL: goto x86_l_39d9;
	case 14815ULL: goto x86_l_39df;
	case 14824ULL: goto x86_l_39e8;
	case 14830ULL: goto x86_l_39ee;
	case 14837ULL: goto x86_l_39f5;
	case 14842ULL: goto x86_l_39fa;
	case 14847ULL: goto x86_l_39ff;
	case 14856ULL: goto x86_l_3a08;
	case 14858ULL: goto x86_l_3a0a;
	case 14863ULL: goto x86_l_3a0f;
	case 14868ULL: goto x86_l_3a14;
	case 14873ULL: goto x86_l_3a19;
	case 14878ULL: goto x86_l_3a1e;
	case 14883ULL: goto x86_l_3a23;
	case 14885ULL: goto x86_l_3a25;
	case 14887ULL: goto x86_l_3a27;
	case 14893ULL: goto x86_l_3a2d;
	case 14902ULL: goto x86_l_3a36;
	case 14908ULL: goto x86_l_3a3c;
	case 14915ULL: goto x86_l_3a43;
	case 14920ULL: goto x86_l_3a48;
	case 14925ULL: goto x86_l_3a4d;
	case 14934ULL: goto x86_l_3a56;
	case 14936ULL: goto x86_l_3a58;
	case 14941ULL: goto x86_l_3a5d;
	case 14946ULL: goto x86_l_3a62;
	case 14951ULL: goto x86_l_3a67;
	case 14956ULL: goto x86_l_3a6c;
	case 14961ULL: goto x86_l_3a71;
	case 14963ULL: goto x86_l_3a73;
	case 14965ULL: goto x86_l_3a75;
	case 14971ULL: goto x86_l_3a7b;
	case 14980ULL: goto x86_l_3a84;
	case 14986ULL: goto x86_l_3a8a;
	case 14993ULL: goto x86_l_3a91;
	case 14998ULL: goto x86_l_3a96;
	case 15003ULL: goto x86_l_3a9b;
	case 15012ULL: goto x86_l_3aa4;
	case 15014ULL: goto x86_l_3aa6;
	case 15019ULL: goto x86_l_3aab;
	case 15024ULL: goto x86_l_3ab0;
	case 15029ULL: goto x86_l_3ab5;
	case 15034ULL: goto x86_l_3aba;
	case 15039ULL: goto x86_l_3abf;
	case 15041ULL: goto x86_l_3ac1;
	case 15043ULL: goto x86_l_3ac3;
	case 15049ULL: goto x86_l_3ac9;
	case 15058ULL: goto x86_l_3ad2;
	case 15064ULL: goto x86_l_3ad8;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3333:
	/* 0x3333: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3338:
	/* 0x3338: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_333d:
	/* 0x333d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3342:
	/* 0x3342: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3347:
	/* 0x3347: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_334c:
	/* 0x334c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_334e:
	/* 0x334e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3350:
	/* 0x3350: js     622c <generic_sleepable_preload+0x622c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25132ULL;
	}
x86_l_3356:
	/* 0x3356: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_335f:
	/* 0x335f: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_3365:
	/* 0x3365: mov    ecx,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_336c:
	/* 0x336c: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3371:
	/* 0x3371: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3376:
	/* 0x3376: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_337f:
	/* 0x337f: je     33a4 <generic_sleepable_preload+0x33a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33a4;
	}
x86_l_3381:
	/* 0x3381: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3386:
	/* 0x3386: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_338b:
	/* 0x338b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3390:
	/* 0x3390: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3395:
	/* 0x3395: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_339a:
	/* 0x339a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_339c:
	/* 0x339c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_339e:
	/* 0x339e: js     6419 <generic_sleepable_preload+0x6419> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25625ULL;
	}
x86_l_33a4:
	/* 0x33a4: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_33ad:
	/* 0x33ad: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_33b3:
	/* 0x33b3: mov    ecx,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_33ba:
	/* 0x33ba: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_33bf:
	/* 0x33bf: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33c4:
	/* 0x33c4: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_33cd:
	/* 0x33cd: je     33f2 <generic_sleepable_preload+0x33f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33f2;
	}
x86_l_33cf:
	/* 0x33cf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33d4:
	/* 0x33d4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33d9:
	/* 0x33d9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_33de:
	/* 0x33de: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33e3:
	/* 0x33e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33e8:
	/* 0x33e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33ea:
	/* 0x33ea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33ec:
	/* 0x33ec: js     68e6 <generic_sleepable_preload+0x68e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26854ULL;
	}
x86_l_33f2:
	/* 0x33f2: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_33fb:
	/* 0x33fb: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_3401:
	/* 0x3401: mov    ecx,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_3408:
	/* 0x3408: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_340d:
	/* 0x340d: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3412:
	/* 0x3412: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_341b:
	/* 0x341b: je     3440 <generic_sleepable_preload+0x3440> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3440;
	}
x86_l_341d:
	/* 0x341d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3422:
	/* 0x3422: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3427:
	/* 0x3427: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_342c:
	/* 0x342c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3431:
	/* 0x3431: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3436:
	/* 0x3436: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3438:
	/* 0x3438: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_343a:
	/* 0x343a: js     6958 <generic_sleepable_preload+0x6958> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26968ULL;
	}
x86_l_3440:
	/* 0x3440: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3445:
	/* 0x3445: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_344e:
	/* 0x344e: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_3454:
	/* 0x3454: mov    ecx,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_345b:
	/* 0x345b: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3460:
	/* 0x3460: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3465:
	/* 0x3465: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_346e:
	/* 0x346e: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_3474:
	/* 0x3474: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3479:
	/* 0x3479: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_347e:
	/* 0x347e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3483:
	/* 0x3483: jmp    3768 <generic_sleepable_preload+0x3768> */
	goto x86_l_3768;
x86_l_3488:
	/* 0x3488: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_348b:
	/* 0x348b: je     34b0 <generic_sleepable_preload+0x34b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34b0;
	}
x86_l_348d:
	/* 0x348d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3492:
	/* 0x3492: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3497:
	/* 0x3497: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_349c:
	/* 0x349c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34a1:
	/* 0x34a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34a6:
	/* 0x34a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34a8:
	/* 0x34a8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34aa:
	/* 0x34aa: js     3e7b <generic_sleepable_preload+0x3e7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15995ULL;
	}
x86_l_34b0:
	/* 0x34b0: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_34b9:
	/* 0x34b9: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_34bf:
	/* 0x34bf: mov    ecx,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_34c6:
	/* 0x34c6: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_34cb:
	/* 0x34cb: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34d0:
	/* 0x34d0: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_34d9:
	/* 0x34d9: je     34fe <generic_sleepable_preload+0x34fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34fe;
	}
x86_l_34db:
	/* 0x34db: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34e0:
	/* 0x34e0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_34e5:
	/* 0x34e5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_34ea:
	/* 0x34ea: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34ef:
	/* 0x34ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34f4:
	/* 0x34f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34f6:
	/* 0x34f6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34f8:
	/* 0x34f8: js     541c <generic_sleepable_preload+0x541c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21532ULL;
	}
x86_l_34fe:
	/* 0x34fe: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_3507:
	/* 0x3507: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_350d:
	/* 0x350d: mov    ecx,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_3514:
	/* 0x3514: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3519:
	/* 0x3519: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_351e:
	/* 0x351e: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_3527:
	/* 0x3527: je     354c <generic_sleepable_preload+0x354c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_354c;
	}
x86_l_3529:
	/* 0x3529: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_352e:
	/* 0x352e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3533:
	/* 0x3533: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3538:
	/* 0x3538: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_353d:
	/* 0x353d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3542:
	/* 0x3542: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3544:
	/* 0x3544: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3546:
	/* 0x3546: js     6103 <generic_sleepable_preload+0x6103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24835ULL;
	}
x86_l_354c:
	/* 0x354c: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_3555:
	/* 0x3555: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_355b:
	/* 0x355b: mov    ecx,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_3562:
	/* 0x3562: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3567:
	/* 0x3567: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_356c:
	/* 0x356c: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_3575:
	/* 0x3575: je     359a <generic_sleepable_preload+0x359a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_359a;
	}
x86_l_3577:
	/* 0x3577: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_357c:
	/* 0x357c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3581:
	/* 0x3581: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3586:
	/* 0x3586: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_358b:
	/* 0x358b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3590:
	/* 0x3590: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3592:
	/* 0x3592: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3594:
	/* 0x3594: js     6167 <generic_sleepable_preload+0x6167> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24935ULL;
	}
x86_l_359a:
	/* 0x359a: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_35a3:
	/* 0x35a3: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_35a9:
	/* 0x35a9: mov    ecx,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_35b0:
	/* 0x35b0: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_35b5:
	/* 0x35b5: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35ba:
	/* 0x35ba: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_35c3:
	/* 0x35c3: je     35e8 <generic_sleepable_preload+0x35e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35e8;
	}
x86_l_35c5:
	/* 0x35c5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35ca:
	/* 0x35ca: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_35cf:
	/* 0x35cf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_35d4:
	/* 0x35d4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35d9:
	/* 0x35d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35de:
	/* 0x35de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35e0:
	/* 0x35e0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35e2:
	/* 0x35e2: js     61cb <generic_sleepable_preload+0x61cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25035ULL;
	}
x86_l_35e8:
	/* 0x35e8: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_35f1:
	/* 0x35f1: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_35f7:
	/* 0x35f7: mov    ecx,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_35fe:
	/* 0x35fe: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3603:
	/* 0x3603: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3608:
	/* 0x3608: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_3611:
	/* 0x3611: je     3636 <generic_sleepable_preload+0x3636> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3636;
	}
x86_l_3613:
	/* 0x3613: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3618:
	/* 0x3618: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_361d:
	/* 0x361d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3622:
	/* 0x3622: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3627:
	/* 0x3627: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_362c:
	/* 0x362c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_362e:
	/* 0x362e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3630:
	/* 0x3630: js     622c <generic_sleepable_preload+0x622c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25132ULL;
	}
x86_l_3636:
	/* 0x3636: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_363f:
	/* 0x363f: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_3645:
	/* 0x3645: mov    ecx,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_364c:
	/* 0x364c: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3651:
	/* 0x3651: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3656:
	/* 0x3656: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_365f:
	/* 0x365f: je     3684 <generic_sleepable_preload+0x3684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3684;
	}
x86_l_3661:
	/* 0x3661: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3666:
	/* 0x3666: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_366b:
	/* 0x366b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3670:
	/* 0x3670: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3675:
	/* 0x3675: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_367a:
	/* 0x367a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_367c:
	/* 0x367c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_367e:
	/* 0x367e: js     6419 <generic_sleepable_preload+0x6419> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25625ULL;
	}
x86_l_3684:
	/* 0x3684: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_368d:
	/* 0x368d: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_3693:
	/* 0x3693: mov    ecx,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_369a:
	/* 0x369a: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_369f:
	/* 0x369f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36a4:
	/* 0x36a4: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_36ad:
	/* 0x36ad: je     36d2 <generic_sleepable_preload+0x36d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36d2;
	}
x86_l_36af:
	/* 0x36af: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36b4:
	/* 0x36b4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_36b9:
	/* 0x36b9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_36be:
	/* 0x36be: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36c3:
	/* 0x36c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36c8:
	/* 0x36c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36ca:
	/* 0x36ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36cc:
	/* 0x36cc: js     69fc <generic_sleepable_preload+0x69fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27132ULL;
	}
x86_l_36d2:
	/* 0x36d2: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_36d7:
	/* 0x36d7: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_36e0:
	/* 0x36e0: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_36e6:
	/* 0x36e6: mov    ecx,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_36ed:
	/* 0x36ed: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_36f2:
	/* 0x36f2: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36f7:
	/* 0x36f7: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_3700:
	/* 0x3700: je     3725 <generic_sleepable_preload+0x3725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3725;
	}
x86_l_3702:
	/* 0x3702: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3707:
	/* 0x3707: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_370c:
	/* 0x370c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3711:
	/* 0x3711: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3716:
	/* 0x3716: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_371b:
	/* 0x371b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_371d:
	/* 0x371d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_371f:
	/* 0x371f: js     6958 <generic_sleepable_preload+0x6958> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26968ULL;
	}
x86_l_3725:
	/* 0x3725: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_372a:
	/* 0x372a: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_3733:
	/* 0x3733: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_3739:
	/* 0x3739: mov    ecx,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_3740:
	/* 0x3740: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3745:
	/* 0x3745: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_374a:
	/* 0x374a: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_3753:
	/* 0x3753: je     6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25632ULL;
	}
x86_l_3759:
	/* 0x3759: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_375e:
	/* 0x375e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3763:
	/* 0x3763: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3768:
	/* 0x3768: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_376d:
	/* 0x376d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3772:
	/* 0x3772: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3774:
	/* 0x3774: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3776:
	/* 0x3776: jns    6420 <generic_sleepable_preload+0x6420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25632ULL;
	}
x86_l_377c:
	/* 0x377c: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_3781:
	/* 0x3781: jmp    641e <generic_sleepable_preload+0x641e> */
	return 25630ULL;
x86_l_3786:
	/* 0x3786: mov    edx,DWORD PTR [r13+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_378d:
	/* 0x378d: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3793:
	/* 0x3793: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3796:
	/* 0x3796: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_379b:
	/* 0x379b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_37a0:
	/* 0x37a0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37a5:
	/* 0x37a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37aa:
	/* 0x37aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37ac:
	/* 0x37ac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37ae:
	/* 0x37ae: jne    383a <generic_sleepable_preload+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_383a;
	}
x86_l_37b4:
	/* 0x37b4: mov    eax,DWORD PTR [r13+0x26c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 620ULL);
x86_l_37bb:
	/* 0x37bb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_37c0:
	/* 0x37c0: add    rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37c3:
	/* 0x37c3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37c8:
	/* 0x37c8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_37cd:
	/* 0x37cd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37d2:
	/* 0x37d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37d7:
	/* 0x37d7: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_37da:
	/* 0x37da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37dc:
	/* 0x37dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37de:
	/* 0x37de: jne    383a <generic_sleepable_preload+0x383a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_383a;
	}
x86_l_37e0:
	/* 0x37e0: movzx  eax,BYTE PTR [r13+0x273] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 627ULL);
x86_l_37e8:
	/* 0x37e8: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_37ef:
	/* 0x37ef: mov    rcx,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_37f6:
	/* 0x37f6: add    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_37fb:
	/* 0x37fb: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37fe:
	/* 0x37fe: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3803:
	/* 0x3803: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3808:
	/* 0x3808: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_380d:
	/* 0x380d: movzx  ecx,BYTE PTR [r13+0x273] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 627ULL);
x86_l_3815:
	/* 0x3815: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_381c:
	/* 0x381c: mov    rdx,QWORD PTR [r13+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_3823:
	/* 0x3823: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_3828:
	/* 0x3828: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_382b:
	/* 0x382b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3830:
	/* 0x3830: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3832:
	/* 0x3832: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3834:
	/* 0x3834: je     1c57 <generic_sleepable_preload+0x1c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7255ULL;
	}
x86_l_383a:
	/* 0x383a: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_383d:
	/* 0x383d: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3842:
	/* 0x3842: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3844:
	/* 0x3844: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_3847:
	/* 0x3847: cmp    WORD PTR [r13+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_3850:
	/* 0x3850: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_3856:
	/* 0x3856: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_385d:
	/* 0x385d: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3860:
	/* 0x3860: mov    eax,DWORD PTR [r13+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_3867:
	/* 0x3867: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_386a:
	/* 0x386a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_386f:
	/* 0x386f: movzx  eax,WORD PTR [r13+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_3877:
	/* 0x3877: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_3879:
	/* 0x3879: je     3b5f <generic_sleepable_preload+0x3b5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15199ULL;
	}
x86_l_387f:
	/* 0x387f: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3882:
	/* 0x3882: je     38a7 <generic_sleepable_preload+0x38a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a7;
	}
x86_l_3884:
	/* 0x3884: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3889:
	/* 0x3889: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_388e:
	/* 0x388e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3893:
	/* 0x3893: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3898:
	/* 0x3898: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_389d:
	/* 0x389d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_389f:
	/* 0x389f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38a1:
	/* 0x38a1: js     3e85 <generic_sleepable_preload+0x3e85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 16005ULL;
	}
x86_l_38a7:
	/* 0x38a7: cmp    WORD PTR [r13+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_38b0:
	/* 0x38b0: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_38b6:
	/* 0x38b6: mov    ecx,DWORD PTR [r13+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_38bd:
	/* 0x38bd: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_38c2:
	/* 0x38c2: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38c7:
	/* 0x38c7: cmp    WORD PTR [r13+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_38d0:
	/* 0x38d0: je     38f5 <generic_sleepable_preload+0x38f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38f5;
	}
x86_l_38d2:
	/* 0x38d2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38d7:
	/* 0x38d7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_38dc:
	/* 0x38dc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_38e1:
	/* 0x38e1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38e6:
	/* 0x38e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38eb:
	/* 0x38eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38ed:
	/* 0x38ed: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38ef:
	/* 0x38ef: js     5426 <generic_sleepable_preload+0x5426> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21542ULL;
	}
x86_l_38f5:
	/* 0x38f5: cmp    WORD PTR [r13+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_38fe:
	/* 0x38fe: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_3904:
	/* 0x3904: mov    ecx,DWORD PTR [r13+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_390b:
	/* 0x390b: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3910:
	/* 0x3910: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3915:
	/* 0x3915: cmp    WORD PTR [r13+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_391e:
	/* 0x391e: je     3943 <generic_sleepable_preload+0x3943> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3943;
	}
x86_l_3920:
	/* 0x3920: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3925:
	/* 0x3925: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_392a:
	/* 0x392a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_392f:
	/* 0x392f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3934:
	/* 0x3934: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3939:
	/* 0x3939: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_393b:
	/* 0x393b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_393d:
	/* 0x393d: js     610d <generic_sleepable_preload+0x610d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24845ULL;
	}
x86_l_3943:
	/* 0x3943: cmp    WORD PTR [r13+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_394c:
	/* 0x394c: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_3952:
	/* 0x3952: mov    ecx,DWORD PTR [r13+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_3959:
	/* 0x3959: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_395e:
	/* 0x395e: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3963:
	/* 0x3963: cmp    WORD PTR [r13+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_396c:
	/* 0x396c: je     3991 <generic_sleepable_preload+0x3991> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3991;
	}
x86_l_396e:
	/* 0x396e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3973:
	/* 0x3973: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3978:
	/* 0x3978: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_397d:
	/* 0x397d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3982:
	/* 0x3982: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3987:
	/* 0x3987: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3989:
	/* 0x3989: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_398b:
	/* 0x398b: js     6171 <generic_sleepable_preload+0x6171> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24945ULL;
	}
x86_l_3991:
	/* 0x3991: cmp    WORD PTR [r13+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_399a:
	/* 0x399a: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_39a0:
	/* 0x39a0: mov    ecx,DWORD PTR [r13+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_39a7:
	/* 0x39a7: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_39ac:
	/* 0x39ac: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39b1:
	/* 0x39b1: cmp    WORD PTR [r13+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_39ba:
	/* 0x39ba: je     39df <generic_sleepable_preload+0x39df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39df;
	}
x86_l_39bc:
	/* 0x39bc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39c1:
	/* 0x39c1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_39c6:
	/* 0x39c6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_39cb:
	/* 0x39cb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39d0:
	/* 0x39d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39d5:
	/* 0x39d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39d7:
	/* 0x39d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39d9:
	/* 0x39d9: js     61d5 <generic_sleepable_preload+0x61d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25045ULL;
	}
x86_l_39df:
	/* 0x39df: cmp    WORD PTR [r13+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_39e8:
	/* 0x39e8: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_39ee:
	/* 0x39ee: mov    ecx,DWORD PTR [r13+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_39f5:
	/* 0x39f5: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_39fa:
	/* 0x39fa: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39ff:
	/* 0x39ff: cmp    WORD PTR [r13+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_3a08:
	/* 0x3a08: je     3a2d <generic_sleepable_preload+0x3a2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a2d;
	}
x86_l_3a0a:
	/* 0x3a0a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a0f:
	/* 0x3a0f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a14:
	/* 0x3a14: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a19:
	/* 0x3a19: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a1e:
	/* 0x3a1e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a23:
	/* 0x3a23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a25:
	/* 0x3a25: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a27:
	/* 0x3a27: js     6236 <generic_sleepable_preload+0x6236> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25142ULL;
	}
x86_l_3a2d:
	/* 0x3a2d: cmp    WORD PTR [r13+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_3a36:
	/* 0x3a36: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_3a3c:
	/* 0x3a3c: mov    ecx,DWORD PTR [r13+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_3a43:
	/* 0x3a43: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3a48:
	/* 0x3a48: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a4d:
	/* 0x3a4d: cmp    WORD PTR [r13+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_3a56:
	/* 0x3a56: je     3a7b <generic_sleepable_preload+0x3a7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a7b;
	}
x86_l_3a58:
	/* 0x3a58: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a5d:
	/* 0x3a5d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a62:
	/* 0x3a62: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a67:
	/* 0x3a67: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a6c:
	/* 0x3a6c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a71:
	/* 0x3a71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a73:
	/* 0x3a73: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a75:
	/* 0x3a75: js     64a6 <generic_sleepable_preload+0x64a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25766ULL;
	}
x86_l_3a7b:
	/* 0x3a7b: cmp    WORD PTR [r13+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_3a84:
	/* 0x3a84: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_3a8a:
	/* 0x3a8a: mov    ecx,DWORD PTR [r13+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_3a91:
	/* 0x3a91: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3a96:
	/* 0x3a96: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a9b:
	/* 0x3a9b: cmp    WORD PTR [r13+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_3aa4:
	/* 0x3aa4: je     3ac9 <generic_sleepable_preload+0x3ac9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ac9;
	}
x86_l_3aa6:
	/* 0x3aa6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3aab:
	/* 0x3aab: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3ab0:
	/* 0x3ab0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3ab5:
	/* 0x3ab5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3aba:
	/* 0x3aba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3abf:
	/* 0x3abf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ac1:
	/* 0x3ac1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ac3:
	/* 0x3ac3: js     68f2 <generic_sleepable_preload+0x68f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26866ULL;
	}
x86_l_3ac9:
	/* 0x3ac9: cmp    WORD PTR [r13+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_3ad2:
	/* 0x3ad2: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_3ad8:
	/* 0x3ad8: mov    ecx,DWORD PTR [r13+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
	return 15071ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15071ULL: goto x86_l_3adf;
	case 15076ULL: goto x86_l_3ae4;
	case 15081ULL: goto x86_l_3ae9;
	case 15090ULL: goto x86_l_3af2;
	case 15092ULL: goto x86_l_3af4;
	case 15097ULL: goto x86_l_3af9;
	case 15102ULL: goto x86_l_3afe;
	case 15107ULL: goto x86_l_3b03;
	case 15112ULL: goto x86_l_3b08;
	case 15117ULL: goto x86_l_3b0d;
	case 15119ULL: goto x86_l_3b0f;
	case 15121ULL: goto x86_l_3b11;
	case 15127ULL: goto x86_l_3b17;
	case 15132ULL: goto x86_l_3b1c;
	case 15141ULL: goto x86_l_3b25;
	case 15147ULL: goto x86_l_3b2b;
	case 15154ULL: goto x86_l_3b32;
	case 15159ULL: goto x86_l_3b37;
	case 15164ULL: goto x86_l_3b3c;
	case 15173ULL: goto x86_l_3b45;
	case 15179ULL: goto x86_l_3b4b;
	case 15184ULL: goto x86_l_3b50;
	case 15189ULL: goto x86_l_3b55;
	case 15194ULL: goto x86_l_3b5a;
	case 15199ULL: goto x86_l_3b5f;
	case 15202ULL: goto x86_l_3b62;
	case 15204ULL: goto x86_l_3b64;
	case 15209ULL: goto x86_l_3b69;
	case 15214ULL: goto x86_l_3b6e;
	case 15219ULL: goto x86_l_3b73;
	case 15224ULL: goto x86_l_3b78;
	case 15229ULL: goto x86_l_3b7d;
	case 15231ULL: goto x86_l_3b7f;
	case 15233ULL: goto x86_l_3b81;
	case 15239ULL: goto x86_l_3b87;
	case 15248ULL: goto x86_l_3b90;
	case 15254ULL: goto x86_l_3b96;
	case 15261ULL: goto x86_l_3b9d;
	case 15266ULL: goto x86_l_3ba2;
	case 15271ULL: goto x86_l_3ba7;
	case 15280ULL: goto x86_l_3bb0;
	case 15282ULL: goto x86_l_3bb2;
	case 15287ULL: goto x86_l_3bb7;
	case 15292ULL: goto x86_l_3bbc;
	case 15297ULL: goto x86_l_3bc1;
	case 15302ULL: goto x86_l_3bc6;
	case 15307ULL: goto x86_l_3bcb;
	case 15309ULL: goto x86_l_3bcd;
	case 15311ULL: goto x86_l_3bcf;
	case 15317ULL: goto x86_l_3bd5;
	case 15326ULL: goto x86_l_3bde;
	case 15332ULL: goto x86_l_3be4;
	case 15339ULL: goto x86_l_3beb;
	case 15344ULL: goto x86_l_3bf0;
	case 15349ULL: goto x86_l_3bf5;
	case 15358ULL: goto x86_l_3bfe;
	case 15360ULL: goto x86_l_3c00;
	case 15365ULL: goto x86_l_3c05;
	case 15370ULL: goto x86_l_3c0a;
	case 15375ULL: goto x86_l_3c0f;
	case 15380ULL: goto x86_l_3c14;
	case 15385ULL: goto x86_l_3c19;
	case 15387ULL: goto x86_l_3c1b;
	case 15389ULL: goto x86_l_3c1d;
	case 15395ULL: goto x86_l_3c23;
	case 15404ULL: goto x86_l_3c2c;
	case 15410ULL: goto x86_l_3c32;
	case 15417ULL: goto x86_l_3c39;
	case 15422ULL: goto x86_l_3c3e;
	case 15427ULL: goto x86_l_3c43;
	case 15436ULL: goto x86_l_3c4c;
	case 15438ULL: goto x86_l_3c4e;
	case 15443ULL: goto x86_l_3c53;
	case 15448ULL: goto x86_l_3c58;
	case 15453ULL: goto x86_l_3c5d;
	case 15458ULL: goto x86_l_3c62;
	case 15463ULL: goto x86_l_3c67;
	case 15465ULL: goto x86_l_3c69;
	case 15467ULL: goto x86_l_3c6b;
	case 15473ULL: goto x86_l_3c71;
	case 15482ULL: goto x86_l_3c7a;
	case 15488ULL: goto x86_l_3c80;
	case 15495ULL: goto x86_l_3c87;
	case 15500ULL: goto x86_l_3c8c;
	case 15505ULL: goto x86_l_3c91;
	case 15514ULL: goto x86_l_3c9a;
	case 15516ULL: goto x86_l_3c9c;
	case 15521ULL: goto x86_l_3ca1;
	case 15526ULL: goto x86_l_3ca6;
	case 15531ULL: goto x86_l_3cab;
	case 15536ULL: goto x86_l_3cb0;
	case 15541ULL: goto x86_l_3cb5;
	case 15543ULL: goto x86_l_3cb7;
	case 15545ULL: goto x86_l_3cb9;
	case 15551ULL: goto x86_l_3cbf;
	case 15560ULL: goto x86_l_3cc8;
	case 15566ULL: goto x86_l_3cce;
	case 15573ULL: goto x86_l_3cd5;
	case 15578ULL: goto x86_l_3cda;
	case 15583ULL: goto x86_l_3cdf;
	case 15592ULL: goto x86_l_3ce8;
	case 15594ULL: goto x86_l_3cea;
	case 15599ULL: goto x86_l_3cef;
	case 15604ULL: goto x86_l_3cf4;
	case 15609ULL: goto x86_l_3cf9;
	case 15614ULL: goto x86_l_3cfe;
	case 15619ULL: goto x86_l_3d03;
	case 15621ULL: goto x86_l_3d05;
	case 15623ULL: goto x86_l_3d07;
	case 15629ULL: goto x86_l_3d0d;
	case 15638ULL: goto x86_l_3d16;
	case 15644ULL: goto x86_l_3d1c;
	case 15651ULL: goto x86_l_3d23;
	case 15656ULL: goto x86_l_3d28;
	case 15661ULL: goto x86_l_3d2d;
	case 15670ULL: goto x86_l_3d36;
	case 15672ULL: goto x86_l_3d38;
	case 15677ULL: goto x86_l_3d3d;
	case 15682ULL: goto x86_l_3d42;
	case 15687ULL: goto x86_l_3d47;
	case 15692ULL: goto x86_l_3d4c;
	case 15697ULL: goto x86_l_3d51;
	case 15699ULL: goto x86_l_3d53;
	case 15701ULL: goto x86_l_3d55;
	case 15707ULL: goto x86_l_3d5b;
	case 15716ULL: goto x86_l_3d64;
	case 15722ULL: goto x86_l_3d6a;
	case 15729ULL: goto x86_l_3d71;
	case 15734ULL: goto x86_l_3d76;
	case 15739ULL: goto x86_l_3d7b;
	case 15748ULL: goto x86_l_3d84;
	case 15750ULL: goto x86_l_3d86;
	case 15755ULL: goto x86_l_3d8b;
	case 15760ULL: goto x86_l_3d90;
	case 15765ULL: goto x86_l_3d95;
	case 15770ULL: goto x86_l_3d9a;
	case 15775ULL: goto x86_l_3d9f;
	case 15777ULL: goto x86_l_3da1;
	case 15779ULL: goto x86_l_3da3;
	case 15785ULL: goto x86_l_3da9;
	case 15790ULL: goto x86_l_3dae;
	case 15799ULL: goto x86_l_3db7;
	case 15805ULL: goto x86_l_3dbd;
	case 15812ULL: goto x86_l_3dc4;
	case 15817ULL: goto x86_l_3dc9;
	case 15822ULL: goto x86_l_3dce;
	case 15831ULL: goto x86_l_3dd7;
	case 15833ULL: goto x86_l_3dd9;
	case 15838ULL: goto x86_l_3dde;
	case 15843ULL: goto x86_l_3de3;
	case 15848ULL: goto x86_l_3de8;
	case 15853ULL: goto x86_l_3ded;
	case 15858ULL: goto x86_l_3df2;
	case 15860ULL: goto x86_l_3df4;
	case 15862ULL: goto x86_l_3df6;
	case 15868ULL: goto x86_l_3dfc;
	case 15873ULL: goto x86_l_3e01;
	case 15882ULL: goto x86_l_3e0a;
	case 15888ULL: goto x86_l_3e10;
	case 15895ULL: goto x86_l_3e17;
	case 15900ULL: goto x86_l_3e1c;
	case 15905ULL: goto x86_l_3e21;
	case 15914ULL: goto x86_l_3e2a;
	case 15920ULL: goto x86_l_3e30;
	case 15925ULL: goto x86_l_3e35;
	case 15930ULL: goto x86_l_3e3a;
	case 15935ULL: goto x86_l_3e3f;
	case 15940ULL: goto x86_l_3e44;
	case 15945ULL: goto x86_l_3e49;
	case 15947ULL: goto x86_l_3e4b;
	case 15949ULL: goto x86_l_3e4d;
	case 15955ULL: goto x86_l_3e53;
	case 15960ULL: goto x86_l_3e58;
	case 15965ULL: goto x86_l_3e5d;
	case 15970ULL: goto x86_l_3e62;
	case 15975ULL: goto x86_l_3e67;
	case 15980ULL: goto x86_l_3e6c;
	case 15985ULL: goto x86_l_3e71;
	case 15990ULL: goto x86_l_3e76;
	case 15995ULL: goto x86_l_3e7b;
	case 16000ULL: goto x86_l_3e80;
	case 16005ULL: goto x86_l_3e85;
	case 16010ULL: goto x86_l_3e8a;
	case 16015ULL: goto x86_l_3e8f;
	case 16023ULL: goto x86_l_3e97;
	case 16026ULL: goto x86_l_3e9a;
	case 16032ULL: goto x86_l_3ea0;
	case 16037ULL: goto x86_l_3ea5;
	case 16040ULL: goto x86_l_3ea8;
	case 16046ULL: goto x86_l_3eae;
	case 16051ULL: goto x86_l_3eb3;
	case 16059ULL: goto x86_l_3ebb;
	case 16062ULL: goto x86_l_3ebe;
	case 16068ULL: goto x86_l_3ec4;
	case 16073ULL: goto x86_l_3ec9;
	case 16076ULL: goto x86_l_3ecc;
	case 16082ULL: goto x86_l_3ed2;
	case 16087ULL: goto x86_l_3ed7;
	case 16095ULL: goto x86_l_3edf;
	case 16098ULL: goto x86_l_3ee2;
	case 16104ULL: goto x86_l_3ee8;
	case 16109ULL: goto x86_l_3eed;
	case 16112ULL: goto x86_l_3ef0;
	case 16118ULL: goto x86_l_3ef6;
	case 16123ULL: goto x86_l_3efb;
	case 16131ULL: goto x86_l_3f03;
	case 16134ULL: goto x86_l_3f06;
	case 16140ULL: goto x86_l_3f0c;
	case 16145ULL: goto x86_l_3f11;
	case 16148ULL: goto x86_l_3f14;
	case 16154ULL: goto x86_l_3f1a;
	case 16159ULL: goto x86_l_3f1f;
	case 16167ULL: goto x86_l_3f27;
	case 16170ULL: goto x86_l_3f2a;
	case 16176ULL: goto x86_l_3f30;
	case 16181ULL: goto x86_l_3f35;
	case 16184ULL: goto x86_l_3f38;
	case 16190ULL: goto x86_l_3f3e;
	case 16195ULL: goto x86_l_3f43;
	case 16203ULL: goto x86_l_3f4b;
	case 16206ULL: goto x86_l_3f4e;
	case 16212ULL: goto x86_l_3f54;
	case 16217ULL: goto x86_l_3f59;
	case 16220ULL: goto x86_l_3f5c;
	case 16226ULL: goto x86_l_3f62;
	case 16231ULL: goto x86_l_3f67;
	case 16239ULL: goto x86_l_3f6f;
	case 16242ULL: goto x86_l_3f72;
	case 16248ULL: goto x86_l_3f78;
	case 16253ULL: goto x86_l_3f7d;
	case 16256ULL: goto x86_l_3f80;
	case 16262ULL: goto x86_l_3f86;
	case 16267ULL: goto x86_l_3f8b;
	case 16275ULL: goto x86_l_3f93;
	case 16278ULL: goto x86_l_3f96;
	case 16284ULL: goto x86_l_3f9c;
	case 16289ULL: goto x86_l_3fa1;
	case 16292ULL: goto x86_l_3fa4;
	case 16298ULL: goto x86_l_3faa;
	case 16303ULL: goto x86_l_3faf;
	case 16311ULL: goto x86_l_3fb7;
	case 16314ULL: goto x86_l_3fba;
	case 16320ULL: goto x86_l_3fc0;
	case 16325ULL: goto x86_l_3fc5;
	case 16328ULL: goto x86_l_3fc8;
	case 16334ULL: goto x86_l_3fce;
	case 16339ULL: goto x86_l_3fd3;
	case 16347ULL: goto x86_l_3fdb;
	case 16350ULL: goto x86_l_3fde;
	case 16356ULL: goto x86_l_3fe4;
	case 16361ULL: goto x86_l_3fe9;
	case 16364ULL: goto x86_l_3fec;
	case 16370ULL: goto x86_l_3ff2;
	case 16375ULL: goto x86_l_3ff7;
	case 16383ULL: goto x86_l_3fff;
	case 16386ULL: goto x86_l_4002;
	case 16392ULL: goto x86_l_4008;
	case 16397ULL: goto x86_l_400d;
	case 16400ULL: goto x86_l_4010;
	case 16406ULL: goto x86_l_4016;
	case 16411ULL: goto x86_l_401b;
	case 16419ULL: goto x86_l_4023;
	case 16422ULL: goto x86_l_4026;
	case 16428ULL: goto x86_l_402c;
	case 16433ULL: goto x86_l_4031;
	case 16436ULL: goto x86_l_4034;
	case 16442ULL: goto x86_l_403a;
	case 16447ULL: goto x86_l_403f;
	case 16455ULL: goto x86_l_4047;
	case 16458ULL: goto x86_l_404a;
	case 16464ULL: goto x86_l_4050;
	case 16469ULL: goto x86_l_4055;
	case 16472ULL: goto x86_l_4058;
	case 16478ULL: goto x86_l_405e;
	case 16483ULL: goto x86_l_4063;
	case 16491ULL: goto x86_l_406b;
	case 16494ULL: goto x86_l_406e;
	case 16500ULL: goto x86_l_4074;
	case 16505ULL: goto x86_l_4079;
	case 16508ULL: goto x86_l_407c;
	case 16514ULL: goto x86_l_4082;
	case 16519ULL: goto x86_l_4087;
	case 16527ULL: goto x86_l_408f;
	case 16530ULL: goto x86_l_4092;
	case 16536ULL: goto x86_l_4098;
	case 16541ULL: goto x86_l_409d;
	case 16544ULL: goto x86_l_40a0;
	case 16550ULL: goto x86_l_40a6;
	case 16555ULL: goto x86_l_40ab;
	case 16563ULL: goto x86_l_40b3;
	case 16566ULL: goto x86_l_40b6;
	case 16568ULL: goto x86_l_40b8;
	case 16573ULL: goto x86_l_40bd;
	case 16576ULL: goto x86_l_40c0;
	case 16578ULL: goto x86_l_40c2;
	case 16581ULL: goto x86_l_40c5;
	case 16583ULL: goto x86_l_40c7;
	case 16585ULL: goto x86_l_40c9;
	case 16590ULL: goto x86_l_40ce;
	case 16592ULL: goto x86_l_40d0;
	case 16597ULL: goto x86_l_40d5;
	case 16602ULL: goto x86_l_40da;
	case 16606ULL: goto x86_l_40de;
	case 16608ULL: goto x86_l_40e0;
	case 16611ULL: goto x86_l_40e3;
	case 16617ULL: goto x86_l_40e9;
	case 16623ULL: goto x86_l_40ef;
	case 16630ULL: goto x86_l_40f6;
	case 16633ULL: goto x86_l_40f9;
	case 16637ULL: goto x86_l_40fd;
	case 16640ULL: goto x86_l_4100;
	case 16645ULL: goto x86_l_4105;
	case 16650ULL: goto x86_l_410a;
	case 16652ULL: goto x86_l_410c;
	case 16658ULL: goto x86_l_4112;
	case 16661ULL: goto x86_l_4115;
	case 16663ULL: goto x86_l_4117;
	case 16668ULL: goto x86_l_411c;
	case 16673ULL: goto x86_l_4121;
	case 16678ULL: goto x86_l_4126;
	case 16683ULL: goto x86_l_412b;
	case 16688ULL: goto x86_l_4130;
	case 16690ULL: goto x86_l_4132;
	case 16692ULL: goto x86_l_4134;
	case 16698ULL: goto x86_l_413a;
	case 16704ULL: goto x86_l_4140;
	case 16710ULL: goto x86_l_4146;
	case 16714ULL: goto x86_l_414a;
	case 16719ULL: goto x86_l_414f;
	case 16724ULL: goto x86_l_4154;
	case 16730ULL: goto x86_l_415a;
	case 16732ULL: goto x86_l_415c;
	case 16737ULL: goto x86_l_4161;
	case 16742ULL: goto x86_l_4166;
	case 16747ULL: goto x86_l_416b;
	case 16752ULL: goto x86_l_4170;
	case 16757ULL: goto x86_l_4175;
	case 16759ULL: goto x86_l_4177;
	case 16761ULL: goto x86_l_4179;
	case 16767ULL: goto x86_l_417f;
	case 16776ULL: goto x86_l_4188;
	case 16782ULL: goto x86_l_418e;
	case 16789ULL: goto x86_l_4195;
	case 16794ULL: goto x86_l_419a;
	case 16799ULL: goto x86_l_419f;
	case 16808ULL: goto x86_l_41a8;
	case 16810ULL: goto x86_l_41aa;
	case 16815ULL: goto x86_l_41af;
	case 16820ULL: goto x86_l_41b4;
	case 16825ULL: goto x86_l_41b9;
	case 16830ULL: goto x86_l_41be;
	case 16835ULL: goto x86_l_41c3;
	case 16837ULL: goto x86_l_41c5;
	case 16839ULL: goto x86_l_41c7;
	case 16845ULL: goto x86_l_41cd;
	case 16854ULL: goto x86_l_41d6;
	case 16860ULL: goto x86_l_41dc;
	case 16867ULL: goto x86_l_41e3;
	case 16872ULL: goto x86_l_41e8;
	case 16877ULL: goto x86_l_41ed;
	case 16886ULL: goto x86_l_41f6;
	case 16888ULL: goto x86_l_41f8;
	case 16893ULL: goto x86_l_41fd;
	case 16898ULL: goto x86_l_4202;
	case 16903ULL: goto x86_l_4207;
	case 16908ULL: goto x86_l_420c;
	case 16913ULL: goto x86_l_4211;
	case 16915ULL: goto x86_l_4213;
	case 16917ULL: goto x86_l_4215;
	case 16923ULL: goto x86_l_421b;
	case 16932ULL: goto x86_l_4224;
	case 16938ULL: goto x86_l_422a;
	case 16945ULL: goto x86_l_4231;
	case 16950ULL: goto x86_l_4236;
	case 16955ULL: goto x86_l_423b;
	case 16964ULL: goto x86_l_4244;
	case 16966ULL: goto x86_l_4246;
	case 16971ULL: goto x86_l_424b;
	case 16976ULL: goto x86_l_4250;
	case 16981ULL: goto x86_l_4255;
	case 16986ULL: goto x86_l_425a;
	case 16991ULL: goto x86_l_425f;
	case 16993ULL: goto x86_l_4261;
	case 16995ULL: goto x86_l_4263;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3adf:
	/* 0x3adf: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3ae4:
	/* 0x3ae4: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ae9:
	/* 0x3ae9: cmp    WORD PTR [r13+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_3af2:
	/* 0x3af2: je     3b17 <generic_sleepable_preload+0x3b17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b17;
	}
x86_l_3af4:
	/* 0x3af4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3af9:
	/* 0x3af9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3afe:
	/* 0x3afe: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b03:
	/* 0x3b03: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b08:
	/* 0x3b08: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b0d:
	/* 0x3b0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b0f:
	/* 0x3b0f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b11:
	/* 0x3b11: js     6969 <generic_sleepable_preload+0x6969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26985ULL;
	}
x86_l_3b17:
	/* 0x3b17: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3b1c:
	/* 0x3b1c: cmp    WORD PTR [r13+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_3b25:
	/* 0x3b25: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_3b2b:
	/* 0x3b2b: mov    ecx,DWORD PTR [r13+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_3b32:
	/* 0x3b32: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3b37:
	/* 0x3b37: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b3c:
	/* 0x3b3c: cmp    WORD PTR [r13+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_3b45:
	/* 0x3b45: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_3b4b:
	/* 0x3b4b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b50:
	/* 0x3b50: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3b55:
	/* 0x3b55: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b5a:
	/* 0x3b5a: jmp    3e3f <generic_sleepable_preload+0x3e3f> */
	goto x86_l_3e3f;
x86_l_3b5f:
	/* 0x3b5f: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3b62:
	/* 0x3b62: je     3b87 <generic_sleepable_preload+0x3b87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b87;
	}
x86_l_3b64:
	/* 0x3b64: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b69:
	/* 0x3b69: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3b6e:
	/* 0x3b6e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b73:
	/* 0x3b73: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b78:
	/* 0x3b78: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b7d:
	/* 0x3b7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b7f:
	/* 0x3b7f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b81:
	/* 0x3b81: js     3e85 <generic_sleepable_preload+0x3e85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3e85;
	}
x86_l_3b87:
	/* 0x3b87: cmp    WORD PTR [r13+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_3b90:
	/* 0x3b90: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_3b96:
	/* 0x3b96: mov    ecx,DWORD PTR [r13+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_3b9d:
	/* 0x3b9d: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3ba2:
	/* 0x3ba2: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ba7:
	/* 0x3ba7: cmp    WORD PTR [r13+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_3bb0:
	/* 0x3bb0: je     3bd5 <generic_sleepable_preload+0x3bd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bd5;
	}
x86_l_3bb2:
	/* 0x3bb2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bb7:
	/* 0x3bb7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3bbc:
	/* 0x3bbc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3bc1:
	/* 0x3bc1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bc6:
	/* 0x3bc6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bcb:
	/* 0x3bcb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bcd:
	/* 0x3bcd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3bcf:
	/* 0x3bcf: js     5426 <generic_sleepable_preload+0x5426> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21542ULL;
	}
x86_l_3bd5:
	/* 0x3bd5: cmp    WORD PTR [r13+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_3bde:
	/* 0x3bde: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_3be4:
	/* 0x3be4: mov    ecx,DWORD PTR [r13+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_3beb:
	/* 0x3beb: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3bf0:
	/* 0x3bf0: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bf5:
	/* 0x3bf5: cmp    WORD PTR [r13+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_3bfe:
	/* 0x3bfe: je     3c23 <generic_sleepable_preload+0x3c23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c23;
	}
x86_l_3c00:
	/* 0x3c00: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c05:
	/* 0x3c05: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c0a:
	/* 0x3c0a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c0f:
	/* 0x3c0f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c14:
	/* 0x3c14: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c19:
	/* 0x3c19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c1b:
	/* 0x3c1b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c1d:
	/* 0x3c1d: js     610d <generic_sleepable_preload+0x610d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24845ULL;
	}
x86_l_3c23:
	/* 0x3c23: cmp    WORD PTR [r13+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_3c2c:
	/* 0x3c2c: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_3c32:
	/* 0x3c32: mov    ecx,DWORD PTR [r13+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_3c39:
	/* 0x3c39: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3c3e:
	/* 0x3c3e: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c43:
	/* 0x3c43: cmp    WORD PTR [r13+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_3c4c:
	/* 0x3c4c: je     3c71 <generic_sleepable_preload+0x3c71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c71;
	}
x86_l_3c4e:
	/* 0x3c4e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c53:
	/* 0x3c53: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c58:
	/* 0x3c58: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c5d:
	/* 0x3c5d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c62:
	/* 0x3c62: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c67:
	/* 0x3c67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c69:
	/* 0x3c69: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c6b:
	/* 0x3c6b: js     6171 <generic_sleepable_preload+0x6171> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24945ULL;
	}
x86_l_3c71:
	/* 0x3c71: cmp    WORD PTR [r13+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_3c7a:
	/* 0x3c7a: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_3c80:
	/* 0x3c80: mov    ecx,DWORD PTR [r13+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_3c87:
	/* 0x3c87: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3c8c:
	/* 0x3c8c: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c91:
	/* 0x3c91: cmp    WORD PTR [r13+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_3c9a:
	/* 0x3c9a: je     3cbf <generic_sleepable_preload+0x3cbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cbf;
	}
x86_l_3c9c:
	/* 0x3c9c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ca1:
	/* 0x3ca1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3ca6:
	/* 0x3ca6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3cab:
	/* 0x3cab: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cb0:
	/* 0x3cb0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cb5:
	/* 0x3cb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cb7:
	/* 0x3cb7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3cb9:
	/* 0x3cb9: js     61d5 <generic_sleepable_preload+0x61d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25045ULL;
	}
x86_l_3cbf:
	/* 0x3cbf: cmp    WORD PTR [r13+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_3cc8:
	/* 0x3cc8: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_3cce:
	/* 0x3cce: mov    ecx,DWORD PTR [r13+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_3cd5:
	/* 0x3cd5: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3cda:
	/* 0x3cda: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cdf:
	/* 0x3cdf: cmp    WORD PTR [r13+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_3ce8:
	/* 0x3ce8: je     3d0d <generic_sleepable_preload+0x3d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d0d;
	}
x86_l_3cea:
	/* 0x3cea: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cef:
	/* 0x3cef: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3cf4:
	/* 0x3cf4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3cf9:
	/* 0x3cf9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cfe:
	/* 0x3cfe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d03:
	/* 0x3d03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d05:
	/* 0x3d05: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d07:
	/* 0x3d07: js     6236 <generic_sleepable_preload+0x6236> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25142ULL;
	}
x86_l_3d0d:
	/* 0x3d0d: cmp    WORD PTR [r13+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_3d16:
	/* 0x3d16: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_3d1c:
	/* 0x3d1c: mov    ecx,DWORD PTR [r13+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_3d23:
	/* 0x3d23: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3d28:
	/* 0x3d28: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d2d:
	/* 0x3d2d: cmp    WORD PTR [r13+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_3d36:
	/* 0x3d36: je     3d5b <generic_sleepable_preload+0x3d5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d5b;
	}
x86_l_3d38:
	/* 0x3d38: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d3d:
	/* 0x3d3d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3d42:
	/* 0x3d42: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3d47:
	/* 0x3d47: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d4c:
	/* 0x3d4c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d51:
	/* 0x3d51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d53:
	/* 0x3d53: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d55:
	/* 0x3d55: js     64a6 <generic_sleepable_preload+0x64a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25766ULL;
	}
x86_l_3d5b:
	/* 0x3d5b: cmp    WORD PTR [r13+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_3d64:
	/* 0x3d64: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_3d6a:
	/* 0x3d6a: mov    ecx,DWORD PTR [r13+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_3d71:
	/* 0x3d71: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3d76:
	/* 0x3d76: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d7b:
	/* 0x3d7b: cmp    WORD PTR [r13+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_3d84:
	/* 0x3d84: je     3da9 <generic_sleepable_preload+0x3da9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3da9;
	}
x86_l_3d86:
	/* 0x3d86: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d8b:
	/* 0x3d8b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3d90:
	/* 0x3d90: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3d95:
	/* 0x3d95: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d9a:
	/* 0x3d9a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d9f:
	/* 0x3d9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3da1:
	/* 0x3da1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3da3:
	/* 0x3da3: js     6a0d <generic_sleepable_preload+0x6a0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27149ULL;
	}
x86_l_3da9:
	/* 0x3da9: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3dae:
	/* 0x3dae: cmp    WORD PTR [r13+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_3db7:
	/* 0x3db7: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_3dbd:
	/* 0x3dbd: mov    ecx,DWORD PTR [r13+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_3dc4:
	/* 0x3dc4: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3dc9:
	/* 0x3dc9: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3dce:
	/* 0x3dce: cmp    WORD PTR [r13+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_3dd7:
	/* 0x3dd7: je     3dfc <generic_sleepable_preload+0x3dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3dfc;
	}
x86_l_3dd9:
	/* 0x3dd9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3dde:
	/* 0x3dde: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3de3:
	/* 0x3de3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3de8:
	/* 0x3de8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ded:
	/* 0x3ded: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3df2:
	/* 0x3df2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3df4:
	/* 0x3df4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3df6:
	/* 0x3df6: js     6969 <generic_sleepable_preload+0x6969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26985ULL;
	}
x86_l_3dfc:
	/* 0x3dfc: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3e01:
	/* 0x3e01: cmp    WORD PTR [r13+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_3e0a:
	/* 0x3e0a: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_3e10:
	/* 0x3e10: mov    ecx,DWORD PTR [r13+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_3e17:
	/* 0x3e17: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3e1c:
	/* 0x3e1c: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e21:
	/* 0x3e21: cmp    WORD PTR [r13+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_3e2a:
	/* 0x3e2a: je     64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25774ULL;
	}
x86_l_3e30:
	/* 0x3e30: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e35:
	/* 0x3e35: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3e3a:
	/* 0x3e3a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3e3f:
	/* 0x3e3f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e44:
	/* 0x3e44: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e49:
	/* 0x3e49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e4b:
	/* 0x3e4b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e4d:
	/* 0x3e4d: jns    64ae <generic_sleepable_preload+0x64ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25774ULL;
	}
x86_l_3e53:
	/* 0x3e53: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_3e58:
	/* 0x3e58: jmp    64ab <generic_sleepable_preload+0x64ab> */
	return 25771ULL;
x86_l_3e5d:
	/* 0x3e5d: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3e62:
	/* 0x3e62: jmp    6277 <generic_sleepable_preload+0x6277> */
	return 25207ULL;
x86_l_3e67:
	/* 0x3e67: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3e6c:
	/* 0x3e6c: jmp    6304 <generic_sleepable_preload+0x6304> */
	return 25348ULL;
x86_l_3e71:
	/* 0x3e71: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3e76:
	/* 0x3e76: jmp    6391 <generic_sleepable_preload+0x6391> */
	return 25489ULL;
x86_l_3e7b:
	/* 0x3e7b: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_3e80:
	/* 0x3e80: jmp    641e <generic_sleepable_preload+0x641e> */
	return 25630ULL;
x86_l_3e85:
	/* 0x3e85: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_3e8a:
	/* 0x3e8a: jmp    64ab <generic_sleepable_preload+0x64ab> */
	return 25771ULL;
x86_l_3e8f:
	/* 0x3e8f: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3e97:
	/* 0x3e97: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3e9a:
	/* 0x3e9a: je     40c2 <generic_sleepable_preload+0x40c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c2;
	}
x86_l_3ea0:
	/* 0x3ea0: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3ea5:
	/* 0x3ea5: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3ea8:
	/* 0x3ea8: je     40c2 <generic_sleepable_preload+0x40c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c2;
	}
x86_l_3eae:
	/* 0x3eae: jmp    40d5 <generic_sleepable_preload+0x40d5> */
	goto x86_l_40d5;
x86_l_3eb3:
	/* 0x3eb3: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3ebb:
	/* 0x3ebb: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3ebe:
	/* 0x3ebe: je     5451 <generic_sleepable_preload+0x5451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21585ULL;
	}
x86_l_3ec4:
	/* 0x3ec4: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3ec9:
	/* 0x3ec9: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3ecc:
	/* 0x3ecc: je     5451 <generic_sleepable_preload+0x5451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21585ULL;
	}
x86_l_3ed2:
	/* 0x3ed2: jmp    5464 <generic_sleepable_preload+0x5464> */
	return 21604ULL;
x86_l_3ed7:
	/* 0x3ed7: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3edf:
	/* 0x3edf: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3ee2:
	/* 0x3ee2: je     4732 <generic_sleepable_preload+0x4732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18226ULL;
	}
x86_l_3ee8:
	/* 0x3ee8: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3eed:
	/* 0x3eed: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3ef0:
	/* 0x3ef0: je     4732 <generic_sleepable_preload+0x4732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18226ULL;
	}
x86_l_3ef6:
	/* 0x3ef6: jmp    4745 <generic_sleepable_preload+0x4745> */
	return 18245ULL;
x86_l_3efb:
	/* 0x3efb: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3f03:
	/* 0x3f03: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3f06:
	/* 0x3f06: je     4d99 <generic_sleepable_preload+0x4d99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19865ULL;
	}
x86_l_3f0c:
	/* 0x3f0c: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3f11:
	/* 0x3f11: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3f14:
	/* 0x3f14: je     4d99 <generic_sleepable_preload+0x4d99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19865ULL;
	}
x86_l_3f1a:
	/* 0x3f1a: jmp    4dac <generic_sleepable_preload+0x4dac> */
	return 19884ULL;
x86_l_3f1f:
	/* 0x3f1f: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3f27:
	/* 0x3f27: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3f2a:
	/* 0x3f2a: je     5aa1 <generic_sleepable_preload+0x5aa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23201ULL;
	}
x86_l_3f30:
	/* 0x3f30: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3f35:
	/* 0x3f35: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3f38:
	/* 0x3f38: je     5aa1 <generic_sleepable_preload+0x5aa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23201ULL;
	}
x86_l_3f3e:
	/* 0x3f3e: jmp    5ab4 <generic_sleepable_preload+0x5ab4> */
	return 23220ULL;
x86_l_3f43:
	/* 0x3f43: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3f4b:
	/* 0x3f4b: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3f4e:
	/* 0x3f4e: je     40c2 <generic_sleepable_preload+0x40c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c2;
	}
x86_l_3f54:
	/* 0x3f54: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3f59:
	/* 0x3f59: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3f5c:
	/* 0x3f5c: je     40c2 <generic_sleepable_preload+0x40c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c2;
	}
x86_l_3f62:
	/* 0x3f62: jmp    40d5 <generic_sleepable_preload+0x40d5> */
	goto x86_l_40d5;
x86_l_3f67:
	/* 0x3f67: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3f6f:
	/* 0x3f6f: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3f72:
	/* 0x3f72: je     5451 <generic_sleepable_preload+0x5451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21585ULL;
	}
x86_l_3f78:
	/* 0x3f78: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3f7d:
	/* 0x3f7d: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3f80:
	/* 0x3f80: je     5451 <generic_sleepable_preload+0x5451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21585ULL;
	}
x86_l_3f86:
	/* 0x3f86: jmp    5464 <generic_sleepable_preload+0x5464> */
	return 21604ULL;
x86_l_3f8b:
	/* 0x3f8b: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3f93:
	/* 0x3f93: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3f96:
	/* 0x3f96: je     4732 <generic_sleepable_preload+0x4732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18226ULL;
	}
x86_l_3f9c:
	/* 0x3f9c: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3fa1:
	/* 0x3fa1: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3fa4:
	/* 0x3fa4: je     4732 <generic_sleepable_preload+0x4732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18226ULL;
	}
x86_l_3faa:
	/* 0x3faa: jmp    4745 <generic_sleepable_preload+0x4745> */
	return 18245ULL;
x86_l_3faf:
	/* 0x3faf: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3fb7:
	/* 0x3fb7: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3fba:
	/* 0x3fba: je     4d99 <generic_sleepable_preload+0x4d99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19865ULL;
	}
x86_l_3fc0:
	/* 0x3fc0: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3fc5:
	/* 0x3fc5: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3fc8:
	/* 0x3fc8: je     4d99 <generic_sleepable_preload+0x4d99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19865ULL;
	}
x86_l_3fce:
	/* 0x3fce: jmp    4dac <generic_sleepable_preload+0x4dac> */
	return 19884ULL;
x86_l_3fd3:
	/* 0x3fd3: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3fdb:
	/* 0x3fdb: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3fde:
	/* 0x3fde: je     5aa1 <generic_sleepable_preload+0x5aa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23201ULL;
	}
x86_l_3fe4:
	/* 0x3fe4: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3fe9:
	/* 0x3fe9: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3fec:
	/* 0x3fec: je     5aa1 <generic_sleepable_preload+0x5aa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23201ULL;
	}
x86_l_3ff2:
	/* 0x3ff2: jmp    5ab4 <generic_sleepable_preload+0x5ab4> */
	return 23220ULL;
x86_l_3ff7:
	/* 0x3ff7: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3fff:
	/* 0x3fff: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_4002:
	/* 0x4002: je     40c2 <generic_sleepable_preload+0x40c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c2;
	}
x86_l_4008:
	/* 0x4008: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_400d:
	/* 0x400d: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4010:
	/* 0x4010: je     40c2 <generic_sleepable_preload+0x40c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c2;
	}
x86_l_4016:
	/* 0x4016: jmp    40d5 <generic_sleepable_preload+0x40d5> */
	goto x86_l_40d5;
x86_l_401b:
	/* 0x401b: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4023:
	/* 0x4023: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_4026:
	/* 0x4026: je     5451 <generic_sleepable_preload+0x5451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21585ULL;
	}
x86_l_402c:
	/* 0x402c: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4031:
	/* 0x4031: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4034:
	/* 0x4034: je     5451 <generic_sleepable_preload+0x5451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21585ULL;
	}
x86_l_403a:
	/* 0x403a: jmp    5464 <generic_sleepable_preload+0x5464> */
	return 21604ULL;
x86_l_403f:
	/* 0x403f: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4047:
	/* 0x4047: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_404a:
	/* 0x404a: je     4732 <generic_sleepable_preload+0x4732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18226ULL;
	}
x86_l_4050:
	/* 0x4050: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4055:
	/* 0x4055: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4058:
	/* 0x4058: je     4732 <generic_sleepable_preload+0x4732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18226ULL;
	}
x86_l_405e:
	/* 0x405e: jmp    4745 <generic_sleepable_preload+0x4745> */
	return 18245ULL;
x86_l_4063:
	/* 0x4063: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_406b:
	/* 0x406b: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_406e:
	/* 0x406e: je     4d99 <generic_sleepable_preload+0x4d99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19865ULL;
	}
x86_l_4074:
	/* 0x4074: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4079:
	/* 0x4079: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_407c:
	/* 0x407c: je     4d99 <generic_sleepable_preload+0x4d99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19865ULL;
	}
x86_l_4082:
	/* 0x4082: jmp    4dac <generic_sleepable_preload+0x4dac> */
	return 19884ULL;
x86_l_4087:
	/* 0x4087: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_408f:
	/* 0x408f: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_4092:
	/* 0x4092: je     5aa1 <generic_sleepable_preload+0x5aa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23201ULL;
	}
x86_l_4098:
	/* 0x4098: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_409d:
	/* 0x409d: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_40a0:
	/* 0x40a0: je     5aa1 <generic_sleepable_preload+0x5aa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23201ULL;
	}
x86_l_40a6:
	/* 0x40a6: jmp    5ab4 <generic_sleepable_preload+0x5ab4> */
	return 23220ULL;
x86_l_40ab:
	/* 0x40ab: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_40b3:
	/* 0x40b3: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_40b6:
	/* 0x40b6: je     40c2 <generic_sleepable_preload+0x40c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c2;
	}
x86_l_40b8:
	/* 0x40b8: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_40bd:
	/* 0x40bd: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_40c0:
	/* 0x40c0: jne    40d5 <generic_sleepable_preload+0x40d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_40d5;
	}
x86_l_40c2:
	/* 0x40c2: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_40c5:
	/* 0x40c5: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_40c7:
	/* 0x40c7: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_40c9:
	/* 0x40c9: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_40ce:
	/* 0x40ce: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_40d0:
	/* 0x40d0: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_40d5:
	/* 0x40d5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40da:
	/* 0x40da: mov    r14d,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_40de:
	/* 0x40de: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_40e0:
	/* 0x40e0: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_40e3:
	/* 0x40e3: cmp    WORD PTR [r13+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_40e9:
	/* 0x40e9: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_40ef:
	/* 0x40ef: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_40f6:
	/* 0x40f6: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_40f9:
	/* 0x40f9: mov    eax,DWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_40fd:
	/* 0x40fd: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4100:
	/* 0x4100: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4105:
	/* 0x4105: movzx  eax,WORD PTR [r13+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_410a:
	/* 0x410a: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_410c:
	/* 0x410c: je     43ee <generic_sleepable_preload+0x43ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17390ULL;
	}
x86_l_4112:
	/* 0x4112: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4115:
	/* 0x4115: je     413a <generic_sleepable_preload+0x413a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_413a;
	}
x86_l_4117:
	/* 0x4117: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_411c:
	/* 0x411c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4121:
	/* 0x4121: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4126:
	/* 0x4126: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_412b:
	/* 0x412b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4130:
	/* 0x4130: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4132:
	/* 0x4132: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4134:
	/* 0x4134: js     46ed <generic_sleepable_preload+0x46ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 18157ULL;
	}
x86_l_413a:
	/* 0x413a: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_4140:
	/* 0x4140: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_4146:
	/* 0x4146: mov    ecx,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_414a:
	/* 0x414a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_414f:
	/* 0x414f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4154:
	/* 0x4154: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_415a:
	/* 0x415a: je     417f <generic_sleepable_preload+0x417f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_417f;
	}
x86_l_415c:
	/* 0x415c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4161:
	/* 0x4161: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4166:
	/* 0x4166: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_416b:
	/* 0x416b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4170:
	/* 0x4170: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4175:
	/* 0x4175: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4177:
	/* 0x4177: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4179:
	/* 0x4179: js     5430 <generic_sleepable_preload+0x5430> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21552ULL;
	}
x86_l_417f:
	/* 0x417f: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_4188:
	/* 0x4188: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_418e:
	/* 0x418e: mov    ecx,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4195:
	/* 0x4195: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_419a:
	/* 0x419a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_419f:
	/* 0x419f: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_41a8:
	/* 0x41a8: je     41cd <generic_sleepable_preload+0x41cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41cd;
	}
x86_l_41aa:
	/* 0x41aa: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41af:
	/* 0x41af: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_41b4:
	/* 0x41b4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_41b9:
	/* 0x41b9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41be:
	/* 0x41be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41c3:
	/* 0x41c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41c5:
	/* 0x41c5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_41c7:
	/* 0x41c7: js     6117 <generic_sleepable_preload+0x6117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24855ULL;
	}
x86_l_41cd:
	/* 0x41cd: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_41d6:
	/* 0x41d6: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_41dc:
	/* 0x41dc: mov    ecx,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_41e3:
	/* 0x41e3: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_41e8:
	/* 0x41e8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41ed:
	/* 0x41ed: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_41f6:
	/* 0x41f6: je     421b <generic_sleepable_preload+0x421b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_421b;
	}
x86_l_41f8:
	/* 0x41f8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41fd:
	/* 0x41fd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4202:
	/* 0x4202: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4207:
	/* 0x4207: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_420c:
	/* 0x420c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4211:
	/* 0x4211: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4213:
	/* 0x4213: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4215:
	/* 0x4215: js     617b <generic_sleepable_preload+0x617b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24955ULL;
	}
x86_l_421b:
	/* 0x421b: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_4224:
	/* 0x4224: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_422a:
	/* 0x422a: mov    ecx,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4231:
	/* 0x4231: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4236:
	/* 0x4236: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_423b:
	/* 0x423b: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_4244:
	/* 0x4244: je     4269 <generic_sleepable_preload+0x4269> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17001ULL;
	}
x86_l_4246:
	/* 0x4246: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_424b:
	/* 0x424b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4250:
	/* 0x4250: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4255:
	/* 0x4255: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_425a:
	/* 0x425a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_425f:
	/* 0x425f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4261:
	/* 0x4261: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4263:
	/* 0x4263: js     61df <generic_sleepable_preload+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25055ULL;
	}
	return 17001ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 17001ULL: goto x86_l_4269;
	case 17010ULL: goto x86_l_4272;
	case 17016ULL: goto x86_l_4278;
	case 17023ULL: goto x86_l_427f;
	case 17028ULL: goto x86_l_4284;
	case 17033ULL: goto x86_l_4289;
	case 17042ULL: goto x86_l_4292;
	case 17044ULL: goto x86_l_4294;
	case 17049ULL: goto x86_l_4299;
	case 17054ULL: goto x86_l_429e;
	case 17059ULL: goto x86_l_42a3;
	case 17064ULL: goto x86_l_42a8;
	case 17069ULL: goto x86_l_42ad;
	case 17071ULL: goto x86_l_42af;
	case 17073ULL: goto x86_l_42b1;
	case 17079ULL: goto x86_l_42b7;
	case 17088ULL: goto x86_l_42c0;
	case 17094ULL: goto x86_l_42c6;
	case 17101ULL: goto x86_l_42cd;
	case 17106ULL: goto x86_l_42d2;
	case 17111ULL: goto x86_l_42d7;
	case 17120ULL: goto x86_l_42e0;
	case 17122ULL: goto x86_l_42e2;
	case 17127ULL: goto x86_l_42e7;
	case 17132ULL: goto x86_l_42ec;
	case 17137ULL: goto x86_l_42f1;
	case 17142ULL: goto x86_l_42f6;
	case 17147ULL: goto x86_l_42fb;
	case 17149ULL: goto x86_l_42fd;
	case 17151ULL: goto x86_l_42ff;
	case 17157ULL: goto x86_l_4305;
	case 17166ULL: goto x86_l_430e;
	case 17172ULL: goto x86_l_4314;
	case 17179ULL: goto x86_l_431b;
	case 17184ULL: goto x86_l_4320;
	case 17189ULL: goto x86_l_4325;
	case 17198ULL: goto x86_l_432e;
	case 17200ULL: goto x86_l_4330;
	case 17205ULL: goto x86_l_4335;
	case 17210ULL: goto x86_l_433a;
	case 17215ULL: goto x86_l_433f;
	case 17220ULL: goto x86_l_4344;
	case 17225ULL: goto x86_l_4349;
	case 17227ULL: goto x86_l_434b;
	case 17229ULL: goto x86_l_434d;
	case 17235ULL: goto x86_l_4353;
	case 17244ULL: goto x86_l_435c;
	case 17250ULL: goto x86_l_4362;
	case 17257ULL: goto x86_l_4369;
	case 17262ULL: goto x86_l_436e;
	case 17267ULL: goto x86_l_4373;
	case 17276ULL: goto x86_l_437c;
	case 17278ULL: goto x86_l_437e;
	case 17283ULL: goto x86_l_4383;
	case 17288ULL: goto x86_l_4388;
	case 17293ULL: goto x86_l_438d;
	case 17298ULL: goto x86_l_4392;
	case 17303ULL: goto x86_l_4397;
	case 17305ULL: goto x86_l_4399;
	case 17307ULL: goto x86_l_439b;
	case 17313ULL: goto x86_l_43a1;
	case 17318ULL: goto x86_l_43a6;
	case 17327ULL: goto x86_l_43af;
	case 17332ULL: goto x86_l_43b4;
	case 17338ULL: goto x86_l_43ba;
	case 17345ULL: goto x86_l_43c1;
	case 17350ULL: goto x86_l_43c6;
	case 17355ULL: goto x86_l_43cb;
	case 17364ULL: goto x86_l_43d4;
	case 17370ULL: goto x86_l_43da;
	case 17375ULL: goto x86_l_43df;
	case 17380ULL: goto x86_l_43e4;
	case 17385ULL: goto x86_l_43e9;
	case 17390ULL: goto x86_l_43ee;
	case 17393ULL: goto x86_l_43f1;
	case 17395ULL: goto x86_l_43f3;
	case 17400ULL: goto x86_l_43f8;
	case 17405ULL: goto x86_l_43fd;
	case 17410ULL: goto x86_l_4402;
	case 17415ULL: goto x86_l_4407;
	case 17420ULL: goto x86_l_440c;
	case 17422ULL: goto x86_l_440e;
	case 17424ULL: goto x86_l_4410;
	case 17430ULL: goto x86_l_4416;
	case 17436ULL: goto x86_l_441c;
	case 17442ULL: goto x86_l_4422;
	case 17446ULL: goto x86_l_4426;
	case 17451ULL: goto x86_l_442b;
	case 17456ULL: goto x86_l_4430;
	case 17462ULL: goto x86_l_4436;
	case 17464ULL: goto x86_l_4438;
	case 17469ULL: goto x86_l_443d;
	case 17474ULL: goto x86_l_4442;
	case 17479ULL: goto x86_l_4447;
	case 17484ULL: goto x86_l_444c;
	case 17489ULL: goto x86_l_4451;
	case 17491ULL: goto x86_l_4453;
	case 17493ULL: goto x86_l_4455;
	case 17499ULL: goto x86_l_445b;
	case 17508ULL: goto x86_l_4464;
	case 17514ULL: goto x86_l_446a;
	case 17521ULL: goto x86_l_4471;
	case 17526ULL: goto x86_l_4476;
	case 17531ULL: goto x86_l_447b;
	case 17540ULL: goto x86_l_4484;
	case 17542ULL: goto x86_l_4486;
	case 17547ULL: goto x86_l_448b;
	case 17552ULL: goto x86_l_4490;
	case 17557ULL: goto x86_l_4495;
	case 17562ULL: goto x86_l_449a;
	case 17567ULL: goto x86_l_449f;
	case 17569ULL: goto x86_l_44a1;
	case 17571ULL: goto x86_l_44a3;
	case 17577ULL: goto x86_l_44a9;
	case 17586ULL: goto x86_l_44b2;
	case 17592ULL: goto x86_l_44b8;
	case 17599ULL: goto x86_l_44bf;
	case 17604ULL: goto x86_l_44c4;
	case 17609ULL: goto x86_l_44c9;
	case 17618ULL: goto x86_l_44d2;
	case 17620ULL: goto x86_l_44d4;
	case 17625ULL: goto x86_l_44d9;
	case 17630ULL: goto x86_l_44de;
	case 17635ULL: goto x86_l_44e3;
	case 17640ULL: goto x86_l_44e8;
	case 17645ULL: goto x86_l_44ed;
	case 17647ULL: goto x86_l_44ef;
	case 17649ULL: goto x86_l_44f1;
	case 17655ULL: goto x86_l_44f7;
	case 17664ULL: goto x86_l_4500;
	case 17670ULL: goto x86_l_4506;
	case 17677ULL: goto x86_l_450d;
	case 17682ULL: goto x86_l_4512;
	case 17687ULL: goto x86_l_4517;
	case 17696ULL: goto x86_l_4520;
	case 17698ULL: goto x86_l_4522;
	case 17703ULL: goto x86_l_4527;
	case 17708ULL: goto x86_l_452c;
	case 17713ULL: goto x86_l_4531;
	case 17718ULL: goto x86_l_4536;
	case 17723ULL: goto x86_l_453b;
	case 17725ULL: goto x86_l_453d;
	case 17727ULL: goto x86_l_453f;
	case 17733ULL: goto x86_l_4545;
	case 17742ULL: goto x86_l_454e;
	case 17748ULL: goto x86_l_4554;
	case 17755ULL: goto x86_l_455b;
	case 17760ULL: goto x86_l_4560;
	case 17765ULL: goto x86_l_4565;
	case 17774ULL: goto x86_l_456e;
	case 17776ULL: goto x86_l_4570;
	case 17781ULL: goto x86_l_4575;
	case 17786ULL: goto x86_l_457a;
	case 17791ULL: goto x86_l_457f;
	case 17796ULL: goto x86_l_4584;
	case 17801ULL: goto x86_l_4589;
	case 17803ULL: goto x86_l_458b;
	case 17805ULL: goto x86_l_458d;
	case 17811ULL: goto x86_l_4593;
	case 17820ULL: goto x86_l_459c;
	case 17826ULL: goto x86_l_45a2;
	case 17833ULL: goto x86_l_45a9;
	case 17838ULL: goto x86_l_45ae;
	case 17843ULL: goto x86_l_45b3;
	case 17852ULL: goto x86_l_45bc;
	case 17854ULL: goto x86_l_45be;
	case 17859ULL: goto x86_l_45c3;
	case 17864ULL: goto x86_l_45c8;
	case 17869ULL: goto x86_l_45cd;
	case 17874ULL: goto x86_l_45d2;
	case 17879ULL: goto x86_l_45d7;
	case 17881ULL: goto x86_l_45d9;
	case 17883ULL: goto x86_l_45db;
	case 17889ULL: goto x86_l_45e1;
	case 17898ULL: goto x86_l_45ea;
	case 17904ULL: goto x86_l_45f0;
	case 17911ULL: goto x86_l_45f7;
	case 17916ULL: goto x86_l_45fc;
	case 17921ULL: goto x86_l_4601;
	case 17930ULL: goto x86_l_460a;
	case 17932ULL: goto x86_l_460c;
	case 17937ULL: goto x86_l_4611;
	case 17942ULL: goto x86_l_4616;
	case 17947ULL: goto x86_l_461b;
	case 17952ULL: goto x86_l_4620;
	case 17957ULL: goto x86_l_4625;
	case 17959ULL: goto x86_l_4627;
	case 17961ULL: goto x86_l_4629;
	case 17967ULL: goto x86_l_462f;
	case 17972ULL: goto x86_l_4634;
	case 17981ULL: goto x86_l_463d;
	case 17986ULL: goto x86_l_4642;
	case 17992ULL: goto x86_l_4648;
	case 17999ULL: goto x86_l_464f;
	case 18004ULL: goto x86_l_4654;
	case 18009ULL: goto x86_l_4659;
	case 18018ULL: goto x86_l_4662;
	case 18020ULL: goto x86_l_4664;
	case 18025ULL: goto x86_l_4669;
	case 18030ULL: goto x86_l_466e;
	case 18035ULL: goto x86_l_4673;
	case 18040ULL: goto x86_l_4678;
	case 18045ULL: goto x86_l_467d;
	case 18047ULL: goto x86_l_467f;
	case 18049ULL: goto x86_l_4681;
	case 18055ULL: goto x86_l_4687;
	case 18060ULL: goto x86_l_468c;
	case 18069ULL: goto x86_l_4695;
	case 18074ULL: goto x86_l_469a;
	case 18080ULL: goto x86_l_46a0;
	case 18087ULL: goto x86_l_46a7;
	case 18092ULL: goto x86_l_46ac;
	case 18097ULL: goto x86_l_46b1;
	case 18106ULL: goto x86_l_46ba;
	case 18112ULL: goto x86_l_46c0;
	case 18117ULL: goto x86_l_46c5;
	case 18122ULL: goto x86_l_46ca;
	case 18127ULL: goto x86_l_46cf;
	case 18132ULL: goto x86_l_46d4;
	case 18137ULL: goto x86_l_46d9;
	case 18139ULL: goto x86_l_46db;
	case 18141ULL: goto x86_l_46dd;
	case 18147ULL: goto x86_l_46e3;
	case 18152ULL: goto x86_l_46e8;
	case 18157ULL: goto x86_l_46ed;
	case 18162ULL: goto x86_l_46f2;
	case 18167ULL: goto x86_l_46f7;
	case 18175ULL: goto x86_l_46ff;
	case 18178ULL: goto x86_l_4702;
	case 18184ULL: goto x86_l_4708;
	case 18189ULL: goto x86_l_470d;
	case 18192ULL: goto x86_l_4710;
	case 18198ULL: goto x86_l_4716;
	case 18203ULL: goto x86_l_471b;
	case 18211ULL: goto x86_l_4723;
	case 18214ULL: goto x86_l_4726;
	case 18216ULL: goto x86_l_4728;
	case 18221ULL: goto x86_l_472d;
	case 18224ULL: goto x86_l_4730;
	case 18226ULL: goto x86_l_4732;
	case 18229ULL: goto x86_l_4735;
	case 18231ULL: goto x86_l_4737;
	case 18233ULL: goto x86_l_4739;
	case 18238ULL: goto x86_l_473e;
	case 18240ULL: goto x86_l_4740;
	case 18245ULL: goto x86_l_4745;
	case 18250ULL: goto x86_l_474a;
	case 18254ULL: goto x86_l_474e;
	case 18256ULL: goto x86_l_4750;
	case 18259ULL: goto x86_l_4753;
	case 18268ULL: goto x86_l_475c;
	case 18274ULL: goto x86_l_4762;
	case 18281ULL: goto x86_l_4769;
	case 18284ULL: goto x86_l_476c;
	case 18291ULL: goto x86_l_4773;
	case 18294ULL: goto x86_l_4776;
	case 18299ULL: goto x86_l_477b;
	case 18307ULL: goto x86_l_4783;
	case 18309ULL: goto x86_l_4785;
	case 18315ULL: goto x86_l_478b;
	case 18318ULL: goto x86_l_478e;
	case 18320ULL: goto x86_l_4790;
	case 18325ULL: goto x86_l_4795;
	case 18330ULL: goto x86_l_479a;
	case 18335ULL: goto x86_l_479f;
	case 18340ULL: goto x86_l_47a4;
	case 18345ULL: goto x86_l_47a9;
	case 18347ULL: goto x86_l_47ab;
	case 18349ULL: goto x86_l_47ad;
	case 18355ULL: goto x86_l_47b3;
	case 18364ULL: goto x86_l_47bc;
	case 18370ULL: goto x86_l_47c2;
	case 18377ULL: goto x86_l_47c9;
	case 18382ULL: goto x86_l_47ce;
	case 18387ULL: goto x86_l_47d3;
	case 18396ULL: goto x86_l_47dc;
	case 18398ULL: goto x86_l_47de;
	case 18403ULL: goto x86_l_47e3;
	case 18408ULL: goto x86_l_47e8;
	case 18413ULL: goto x86_l_47ed;
	case 18418ULL: goto x86_l_47f2;
	case 18423ULL: goto x86_l_47f7;
	case 18425ULL: goto x86_l_47f9;
	case 18427ULL: goto x86_l_47fb;
	case 18433ULL: goto x86_l_4801;
	case 18442ULL: goto x86_l_480a;
	case 18448ULL: goto x86_l_4810;
	case 18455ULL: goto x86_l_4817;
	case 18460ULL: goto x86_l_481c;
	case 18465ULL: goto x86_l_4821;
	case 18474ULL: goto x86_l_482a;
	case 18476ULL: goto x86_l_482c;
	case 18481ULL: goto x86_l_4831;
	case 18486ULL: goto x86_l_4836;
	case 18491ULL: goto x86_l_483b;
	case 18496ULL: goto x86_l_4840;
	case 18501ULL: goto x86_l_4845;
	case 18503ULL: goto x86_l_4847;
	case 18505ULL: goto x86_l_4849;
	case 18511ULL: goto x86_l_484f;
	case 18520ULL: goto x86_l_4858;
	case 18526ULL: goto x86_l_485e;
	case 18533ULL: goto x86_l_4865;
	case 18538ULL: goto x86_l_486a;
	case 18543ULL: goto x86_l_486f;
	case 18552ULL: goto x86_l_4878;
	case 18554ULL: goto x86_l_487a;
	case 18559ULL: goto x86_l_487f;
	case 18564ULL: goto x86_l_4884;
	case 18569ULL: goto x86_l_4889;
	case 18574ULL: goto x86_l_488e;
	case 18579ULL: goto x86_l_4893;
	case 18581ULL: goto x86_l_4895;
	case 18583ULL: goto x86_l_4897;
	case 18589ULL: goto x86_l_489d;
	case 18598ULL: goto x86_l_48a6;
	case 18604ULL: goto x86_l_48ac;
	case 18611ULL: goto x86_l_48b3;
	case 18616ULL: goto x86_l_48b8;
	case 18621ULL: goto x86_l_48bd;
	case 18630ULL: goto x86_l_48c6;
	case 18632ULL: goto x86_l_48c8;
	case 18637ULL: goto x86_l_48cd;
	case 18642ULL: goto x86_l_48d2;
	case 18647ULL: goto x86_l_48d7;
	case 18652ULL: goto x86_l_48dc;
	case 18657ULL: goto x86_l_48e1;
	case 18659ULL: goto x86_l_48e3;
	case 18661ULL: goto x86_l_48e5;
	case 18667ULL: goto x86_l_48eb;
	case 18676ULL: goto x86_l_48f4;
	case 18682ULL: goto x86_l_48fa;
	case 18689ULL: goto x86_l_4901;
	case 18694ULL: goto x86_l_4906;
	case 18699ULL: goto x86_l_490b;
	case 18708ULL: goto x86_l_4914;
	case 18710ULL: goto x86_l_4916;
	case 18715ULL: goto x86_l_491b;
	case 18720ULL: goto x86_l_4920;
	case 18725ULL: goto x86_l_4925;
	case 18730ULL: goto x86_l_492a;
	case 18735ULL: goto x86_l_492f;
	case 18737ULL: goto x86_l_4931;
	case 18739ULL: goto x86_l_4933;
	case 18745ULL: goto x86_l_4939;
	case 18754ULL: goto x86_l_4942;
	case 18760ULL: goto x86_l_4948;
	case 18767ULL: goto x86_l_494f;
	case 18772ULL: goto x86_l_4954;
	case 18777ULL: goto x86_l_4959;
	case 18786ULL: goto x86_l_4962;
	case 18788ULL: goto x86_l_4964;
	case 18793ULL: goto x86_l_4969;
	case 18798ULL: goto x86_l_496e;
	case 18803ULL: goto x86_l_4973;
	case 18808ULL: goto x86_l_4978;
	case 18813ULL: goto x86_l_497d;
	case 18815ULL: goto x86_l_497f;
	case 18817ULL: goto x86_l_4981;
	case 18823ULL: goto x86_l_4987;
	case 18832ULL: goto x86_l_4990;
	case 18838ULL: goto x86_l_4996;
	case 18845ULL: goto x86_l_499d;
	case 18850ULL: goto x86_l_49a2;
	case 18855ULL: goto x86_l_49a7;
	case 18864ULL: goto x86_l_49b0;
	case 18866ULL: goto x86_l_49b2;
	case 18871ULL: goto x86_l_49b7;
	case 18876ULL: goto x86_l_49bc;
	case 18881ULL: goto x86_l_49c1;
	case 18886ULL: goto x86_l_49c6;
	case 18891ULL: goto x86_l_49cb;
	case 18893ULL: goto x86_l_49cd;
	case 18895ULL: goto x86_l_49cf;
	case 18901ULL: goto x86_l_49d5;
	case 18910ULL: goto x86_l_49de;
	case 18916ULL: goto x86_l_49e4;
	case 18923ULL: goto x86_l_49eb;
	case 18928ULL: goto x86_l_49f0;
	case 18933ULL: goto x86_l_49f5;
	case 18942ULL: goto x86_l_49fe;
	case 18944ULL: goto x86_l_4a00;
	case 18949ULL: goto x86_l_4a05;
	case 18954ULL: goto x86_l_4a0a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4269:
	/* 0x4269: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_4272:
	/* 0x4272: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_4278:
	/* 0x4278: mov    ecx,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_427f:
	/* 0x427f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4284:
	/* 0x4284: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4289:
	/* 0x4289: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_4292:
	/* 0x4292: je     42b7 <generic_sleepable_preload+0x42b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42b7;
	}
x86_l_4294:
	/* 0x4294: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4299:
	/* 0x4299: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_429e:
	/* 0x429e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_42a3:
	/* 0x42a3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42a8:
	/* 0x42a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42ad:
	/* 0x42ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42af:
	/* 0x42af: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42b1:
	/* 0x42b1: js     6240 <generic_sleepable_preload+0x6240> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25152ULL;
	}
x86_l_42b7:
	/* 0x42b7: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_42c0:
	/* 0x42c0: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_42c6:
	/* 0x42c6: mov    ecx,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_42cd:
	/* 0x42cd: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_42d2:
	/* 0x42d2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42d7:
	/* 0x42d7: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_42e0:
	/* 0x42e0: je     4305 <generic_sleepable_preload+0x4305> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4305;
	}
x86_l_42e2:
	/* 0x42e2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42e7:
	/* 0x42e7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42ec:
	/* 0x42ec: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_42f1:
	/* 0x42f1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42f6:
	/* 0x42f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42fb:
	/* 0x42fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42fd:
	/* 0x42fd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42ff:
	/* 0x42ff: js     6533 <generic_sleepable_preload+0x6533> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25907ULL;
	}
x86_l_4305:
	/* 0x4305: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_430e:
	/* 0x430e: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_4314:
	/* 0x4314: mov    ecx,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_431b:
	/* 0x431b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4320:
	/* 0x4320: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4325:
	/* 0x4325: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_432e:
	/* 0x432e: je     4353 <generic_sleepable_preload+0x4353> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4353;
	}
x86_l_4330:
	/* 0x4330: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4335:
	/* 0x4335: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_433a:
	/* 0x433a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_433f:
	/* 0x433f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4344:
	/* 0x4344: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4349:
	/* 0x4349: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_434b:
	/* 0x434b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_434d:
	/* 0x434d: js     68ff <generic_sleepable_preload+0x68ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26879ULL;
	}
x86_l_4353:
	/* 0x4353: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_435c:
	/* 0x435c: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_4362:
	/* 0x4362: mov    ecx,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_4369:
	/* 0x4369: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_436e:
	/* 0x436e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4373:
	/* 0x4373: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_437c:
	/* 0x437c: je     43a1 <generic_sleepable_preload+0x43a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43a1;
	}
x86_l_437e:
	/* 0x437e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4383:
	/* 0x4383: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4388:
	/* 0x4388: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_438d:
	/* 0x438d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4392:
	/* 0x4392: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4397:
	/* 0x4397: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4399:
	/* 0x4399: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_439b:
	/* 0x439b: js     697b <generic_sleepable_preload+0x697b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27003ULL;
	}
x86_l_43a1:
	/* 0x43a1: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_43a6:
	/* 0x43a6: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_43af:
	/* 0x43af: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_43b4:
	/* 0x43b4: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_43ba:
	/* 0x43ba: mov    ecx,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_43c1:
	/* 0x43c1: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_43c6:
	/* 0x43c6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43cb:
	/* 0x43cb: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_43d4:
	/* 0x43d4: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_43da:
	/* 0x43da: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43df:
	/* 0x43df: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_43e4:
	/* 0x43e4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_43e9:
	/* 0x43e9: jmp    46cf <generic_sleepable_preload+0x46cf> */
	goto x86_l_46cf;
x86_l_43ee:
	/* 0x43ee: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_43f1:
	/* 0x43f1: je     4416 <generic_sleepable_preload+0x4416> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4416;
	}
x86_l_43f3:
	/* 0x43f3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43f8:
	/* 0x43f8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_43fd:
	/* 0x43fd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4402:
	/* 0x4402: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4407:
	/* 0x4407: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_440c:
	/* 0x440c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_440e:
	/* 0x440e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4410:
	/* 0x4410: js     46ed <generic_sleepable_preload+0x46ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_46ed;
	}
x86_l_4416:
	/* 0x4416: cmp    WORD PTR [r13+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_441c:
	/* 0x441c: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_4422:
	/* 0x4422: mov    ecx,DWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4426:
	/* 0x4426: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_442b:
	/* 0x442b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4430:
	/* 0x4430: cmp    WORD PTR [r13+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_4436:
	/* 0x4436: je     445b <generic_sleepable_preload+0x445b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_445b;
	}
x86_l_4438:
	/* 0x4438: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_443d:
	/* 0x443d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4442:
	/* 0x4442: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4447:
	/* 0x4447: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_444c:
	/* 0x444c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4451:
	/* 0x4451: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4453:
	/* 0x4453: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4455:
	/* 0x4455: js     5430 <generic_sleepable_preload+0x5430> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21552ULL;
	}
x86_l_445b:
	/* 0x445b: cmp    WORD PTR [r13+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_4464:
	/* 0x4464: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_446a:
	/* 0x446a: mov    ecx,DWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4471:
	/* 0x4471: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4476:
	/* 0x4476: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_447b:
	/* 0x447b: cmp    WORD PTR [r13+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_4484:
	/* 0x4484: je     44a9 <generic_sleepable_preload+0x44a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44a9;
	}
x86_l_4486:
	/* 0x4486: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_448b:
	/* 0x448b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4490:
	/* 0x4490: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4495:
	/* 0x4495: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_449a:
	/* 0x449a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_449f:
	/* 0x449f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44a1:
	/* 0x44a1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_44a3:
	/* 0x44a3: js     6117 <generic_sleepable_preload+0x6117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24855ULL;
	}
x86_l_44a9:
	/* 0x44a9: cmp    WORD PTR [r13+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_44b2:
	/* 0x44b2: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_44b8:
	/* 0x44b8: mov    ecx,DWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_44bf:
	/* 0x44bf: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_44c4:
	/* 0x44c4: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44c9:
	/* 0x44c9: cmp    WORD PTR [r13+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_44d2:
	/* 0x44d2: je     44f7 <generic_sleepable_preload+0x44f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44f7;
	}
x86_l_44d4:
	/* 0x44d4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44d9:
	/* 0x44d9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_44de:
	/* 0x44de: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_44e3:
	/* 0x44e3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44e8:
	/* 0x44e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44ed:
	/* 0x44ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44ef:
	/* 0x44ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_44f1:
	/* 0x44f1: js     617b <generic_sleepable_preload+0x617b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24955ULL;
	}
x86_l_44f7:
	/* 0x44f7: cmp    WORD PTR [r13+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_4500:
	/* 0x4500: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_4506:
	/* 0x4506: mov    ecx,DWORD PTR [r13+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_450d:
	/* 0x450d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4512:
	/* 0x4512: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4517:
	/* 0x4517: cmp    WORD PTR [r13+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_4520:
	/* 0x4520: je     4545 <generic_sleepable_preload+0x4545> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4545;
	}
x86_l_4522:
	/* 0x4522: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4527:
	/* 0x4527: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_452c:
	/* 0x452c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4531:
	/* 0x4531: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4536:
	/* 0x4536: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_453b:
	/* 0x453b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_453d:
	/* 0x453d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_453f:
	/* 0x453f: js     61df <generic_sleepable_preload+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25055ULL;
	}
x86_l_4545:
	/* 0x4545: cmp    WORD PTR [r13+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_454e:
	/* 0x454e: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_4554:
	/* 0x4554: mov    ecx,DWORD PTR [r13+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_455b:
	/* 0x455b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4560:
	/* 0x4560: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4565:
	/* 0x4565: cmp    WORD PTR [r13+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_456e:
	/* 0x456e: je     4593 <generic_sleepable_preload+0x4593> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4593;
	}
x86_l_4570:
	/* 0x4570: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4575:
	/* 0x4575: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_457a:
	/* 0x457a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_457f:
	/* 0x457f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4584:
	/* 0x4584: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4589:
	/* 0x4589: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_458b:
	/* 0x458b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_458d:
	/* 0x458d: js     6240 <generic_sleepable_preload+0x6240> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25152ULL;
	}
x86_l_4593:
	/* 0x4593: cmp    WORD PTR [r13+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_459c:
	/* 0x459c: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_45a2:
	/* 0x45a2: mov    ecx,DWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_45a9:
	/* 0x45a9: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_45ae:
	/* 0x45ae: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45b3:
	/* 0x45b3: cmp    WORD PTR [r13+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_45bc:
	/* 0x45bc: je     45e1 <generic_sleepable_preload+0x45e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45e1;
	}
x86_l_45be:
	/* 0x45be: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45c3:
	/* 0x45c3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_45c8:
	/* 0x45c8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_45cd:
	/* 0x45cd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45d2:
	/* 0x45d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45d7:
	/* 0x45d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45d9:
	/* 0x45d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_45db:
	/* 0x45db: js     6533 <generic_sleepable_preload+0x6533> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25907ULL;
	}
x86_l_45e1:
	/* 0x45e1: cmp    WORD PTR [r13+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_45ea:
	/* 0x45ea: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_45f0:
	/* 0x45f0: mov    ecx,DWORD PTR [r13+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_45f7:
	/* 0x45f7: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_45fc:
	/* 0x45fc: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4601:
	/* 0x4601: cmp    WORD PTR [r13+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_460a:
	/* 0x460a: je     462f <generic_sleepable_preload+0x462f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_462f;
	}
x86_l_460c:
	/* 0x460c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4611:
	/* 0x4611: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4616:
	/* 0x4616: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_461b:
	/* 0x461b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4620:
	/* 0x4620: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4625:
	/* 0x4625: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4627:
	/* 0x4627: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4629:
	/* 0x4629: js     6a1f <generic_sleepable_preload+0x6a1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27167ULL;
	}
x86_l_462f:
	/* 0x462f: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4634:
	/* 0x4634: cmp    WORD PTR [r13+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_463d:
	/* 0x463d: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4642:
	/* 0x4642: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_4648:
	/* 0x4648: mov    ecx,DWORD PTR [r13+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_464f:
	/* 0x464f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4654:
	/* 0x4654: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4659:
	/* 0x4659: cmp    WORD PTR [r13+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_4662:
	/* 0x4662: je     4687 <generic_sleepable_preload+0x4687> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4687;
	}
x86_l_4664:
	/* 0x4664: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4669:
	/* 0x4669: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_466e:
	/* 0x466e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4673:
	/* 0x4673: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4678:
	/* 0x4678: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_467d:
	/* 0x467d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_467f:
	/* 0x467f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4681:
	/* 0x4681: js     697b <generic_sleepable_preload+0x697b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27003ULL;
	}
x86_l_4687:
	/* 0x4687: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_468c:
	/* 0x468c: cmp    WORD PTR [r13+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_4695:
	/* 0x4695: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_469a:
	/* 0x469a: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_46a0:
	/* 0x46a0: mov    ecx,DWORD PTR [r13+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_46a7:
	/* 0x46a7: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_46ac:
	/* 0x46ac: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46b1:
	/* 0x46b1: cmp    WORD PTR [r13+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_46ba:
	/* 0x46ba: je     653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25914ULL;
	}
x86_l_46c0:
	/* 0x46c0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46c5:
	/* 0x46c5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_46ca:
	/* 0x46ca: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46cf:
	/* 0x46cf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46d4:
	/* 0x46d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46d9:
	/* 0x46d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46db:
	/* 0x46db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46dd:
	/* 0x46dd: jns    653a <generic_sleepable_preload+0x653a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 25914ULL;
	}
x86_l_46e3:
	/* 0x46e3: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_46e8:
	/* 0x46e8: jmp    6538 <generic_sleepable_preload+0x6538> */
	return 25912ULL;
x86_l_46ed:
	/* 0x46ed: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_46f2:
	/* 0x46f2: jmp    6538 <generic_sleepable_preload+0x6538> */
	return 25912ULL;
x86_l_46f7:
	/* 0x46f7: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_46ff:
	/* 0x46ff: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_4702:
	/* 0x4702: je     5451 <generic_sleepable_preload+0x5451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21585ULL;
	}
x86_l_4708:
	/* 0x4708: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_470d:
	/* 0x470d: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4710:
	/* 0x4710: je     5451 <generic_sleepable_preload+0x5451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21585ULL;
	}
x86_l_4716:
	/* 0x4716: jmp    5464 <generic_sleepable_preload+0x5464> */
	return 21604ULL;
x86_l_471b:
	/* 0x471b: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4723:
	/* 0x4723: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_4726:
	/* 0x4726: je     4732 <generic_sleepable_preload+0x4732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4732;
	}
x86_l_4728:
	/* 0x4728: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_472d:
	/* 0x472d: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4730:
	/* 0x4730: jne    4745 <generic_sleepable_preload+0x4745> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4745;
	}
x86_l_4732:
	/* 0x4732: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_4735:
	/* 0x4735: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_4737:
	/* 0x4737: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_4739:
	/* 0x4739: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_473e:
	/* 0x473e: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4740:
	/* 0x4740: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_4745:
	/* 0x4745: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_474a:
	/* 0x474a: mov    r14d,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_474e:
	/* 0x474e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4750:
	/* 0x4750: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_4753:
	/* 0x4753: cmp    WORD PTR [r13+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_475c:
	/* 0x475c: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_4762:
	/* 0x4762: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_4769:
	/* 0x4769: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_476c:
	/* 0x476c: mov    eax,DWORD PTR [r13+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_4773:
	/* 0x4773: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4776:
	/* 0x4776: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_477b:
	/* 0x477b: movzx  eax,WORD PTR [r13+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_4783:
	/* 0x4783: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_4785:
	/* 0x4785: je     4a70 <generic_sleepable_preload+0x4a70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19056ULL;
	}
x86_l_478b:
	/* 0x478b: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_478e:
	/* 0x478e: je     47b3 <generic_sleepable_preload+0x47b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47b3;
	}
x86_l_4790:
	/* 0x4790: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4795:
	/* 0x4795: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_479a:
	/* 0x479a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_479f:
	/* 0x479f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47a4:
	/* 0x47a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47a9:
	/* 0x47a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47ab:
	/* 0x47ab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_47ad:
	/* 0x47ad: js     4d78 <generic_sleepable_preload+0x4d78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19832ULL;
	}
x86_l_47b3:
	/* 0x47b3: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_47bc:
	/* 0x47bc: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_47c2:
	/* 0x47c2: mov    ecx,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_47c9:
	/* 0x47c9: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_47ce:
	/* 0x47ce: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47d3:
	/* 0x47d3: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_47dc:
	/* 0x47dc: je     4801 <generic_sleepable_preload+0x4801> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4801;
	}
x86_l_47de:
	/* 0x47de: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47e3:
	/* 0x47e3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_47e8:
	/* 0x47e8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47ed:
	/* 0x47ed: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47f2:
	/* 0x47f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47f7:
	/* 0x47f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47f9:
	/* 0x47f9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_47fb:
	/* 0x47fb: js     543a <generic_sleepable_preload+0x543a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21562ULL;
	}
x86_l_4801:
	/* 0x4801: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_480a:
	/* 0x480a: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_4810:
	/* 0x4810: mov    ecx,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_4817:
	/* 0x4817: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_481c:
	/* 0x481c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4821:
	/* 0x4821: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_482a:
	/* 0x482a: je     484f <generic_sleepable_preload+0x484f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_484f;
	}
x86_l_482c:
	/* 0x482c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4831:
	/* 0x4831: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4836:
	/* 0x4836: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_483b:
	/* 0x483b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4840:
	/* 0x4840: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4845:
	/* 0x4845: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4847:
	/* 0x4847: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4849:
	/* 0x4849: js     6121 <generic_sleepable_preload+0x6121> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24865ULL;
	}
x86_l_484f:
	/* 0x484f: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_4858:
	/* 0x4858: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_485e:
	/* 0x485e: mov    ecx,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_4865:
	/* 0x4865: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_486a:
	/* 0x486a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_486f:
	/* 0x486f: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_4878:
	/* 0x4878: je     489d <generic_sleepable_preload+0x489d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_489d;
	}
x86_l_487a:
	/* 0x487a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_487f:
	/* 0x487f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4884:
	/* 0x4884: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4889:
	/* 0x4889: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_488e:
	/* 0x488e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4893:
	/* 0x4893: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4895:
	/* 0x4895: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4897:
	/* 0x4897: js     6185 <generic_sleepable_preload+0x6185> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24965ULL;
	}
x86_l_489d:
	/* 0x489d: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_48a6:
	/* 0x48a6: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_48ac:
	/* 0x48ac: mov    ecx,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_48b3:
	/* 0x48b3: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_48b8:
	/* 0x48b8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48bd:
	/* 0x48bd: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_48c6:
	/* 0x48c6: je     48eb <generic_sleepable_preload+0x48eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48eb;
	}
x86_l_48c8:
	/* 0x48c8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48cd:
	/* 0x48cd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_48d2:
	/* 0x48d2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_48d7:
	/* 0x48d7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48dc:
	/* 0x48dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48e1:
	/* 0x48e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48e3:
	/* 0x48e3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48e5:
	/* 0x48e5: js     61e9 <generic_sleepable_preload+0x61e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25065ULL;
	}
x86_l_48eb:
	/* 0x48eb: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_48f4:
	/* 0x48f4: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_48fa:
	/* 0x48fa: mov    ecx,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_4901:
	/* 0x4901: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4906:
	/* 0x4906: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_490b:
	/* 0x490b: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_4914:
	/* 0x4914: je     4939 <generic_sleepable_preload+0x4939> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4939;
	}
x86_l_4916:
	/* 0x4916: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_491b:
	/* 0x491b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4920:
	/* 0x4920: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4925:
	/* 0x4925: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_492a:
	/* 0x492a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_492f:
	/* 0x492f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4931:
	/* 0x4931: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4933:
	/* 0x4933: js     624a <generic_sleepable_preload+0x624a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25162ULL;
	}
x86_l_4939:
	/* 0x4939: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_4942:
	/* 0x4942: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_4948:
	/* 0x4948: mov    ecx,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_494f:
	/* 0x494f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4954:
	/* 0x4954: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4959:
	/* 0x4959: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_4962:
	/* 0x4962: je     4987 <generic_sleepable_preload+0x4987> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4987;
	}
x86_l_4964:
	/* 0x4964: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4969:
	/* 0x4969: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_496e:
	/* 0x496e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4973:
	/* 0x4973: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4978:
	/* 0x4978: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_497d:
	/* 0x497d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_497f:
	/* 0x497f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4981:
	/* 0x4981: js     65e7 <generic_sleepable_preload+0x65e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26087ULL;
	}
x86_l_4987:
	/* 0x4987: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_4990:
	/* 0x4990: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_4996:
	/* 0x4996: mov    ecx,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_499d:
	/* 0x499d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_49a2:
	/* 0x49a2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49a7:
	/* 0x49a7: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_49b0:
	/* 0x49b0: je     49d5 <generic_sleepable_preload+0x49d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49d5;
	}
x86_l_49b2:
	/* 0x49b2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49b7:
	/* 0x49b7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_49bc:
	/* 0x49bc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_49c1:
	/* 0x49c1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49c6:
	/* 0x49c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49cb:
	/* 0x49cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49cd:
	/* 0x49cd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_49cf:
	/* 0x49cf: js     690b <generic_sleepable_preload+0x690b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26891ULL;
	}
x86_l_49d5:
	/* 0x49d5: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_49de:
	/* 0x49de: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_49e4:
	/* 0x49e4: mov    ecx,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_49eb:
	/* 0x49eb: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_49f0:
	/* 0x49f0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49f5:
	/* 0x49f5: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_49fe:
	/* 0x49fe: je     4a23 <generic_sleepable_preload+0x4a23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18979ULL;
	}
x86_l_4a00:
	/* 0x4a00: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a05:
	/* 0x4a05: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a0a:
	/* 0x4a0a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
	return 18959ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 18959ULL: goto x86_l_4a0f;
	case 18964ULL: goto x86_l_4a14;
	case 18969ULL: goto x86_l_4a19;
	case 18971ULL: goto x86_l_4a1b;
	case 18973ULL: goto x86_l_4a1d;
	case 18979ULL: goto x86_l_4a23;
	case 18984ULL: goto x86_l_4a28;
	case 18993ULL: goto x86_l_4a31;
	case 18998ULL: goto x86_l_4a36;
	case 19004ULL: goto x86_l_4a3c;
	case 19011ULL: goto x86_l_4a43;
	case 19016ULL: goto x86_l_4a48;
	case 19021ULL: goto x86_l_4a4d;
	case 19030ULL: goto x86_l_4a56;
	case 19036ULL: goto x86_l_4a5c;
	case 19041ULL: goto x86_l_4a61;
	case 19046ULL: goto x86_l_4a66;
	case 19051ULL: goto x86_l_4a6b;
	case 19056ULL: goto x86_l_4a70;
	case 19059ULL: goto x86_l_4a73;
	case 19061ULL: goto x86_l_4a75;
	case 19066ULL: goto x86_l_4a7a;
	case 19071ULL: goto x86_l_4a7f;
	case 19076ULL: goto x86_l_4a84;
	case 19081ULL: goto x86_l_4a89;
	case 19086ULL: goto x86_l_4a8e;
	case 19088ULL: goto x86_l_4a90;
	case 19090ULL: goto x86_l_4a92;
	case 19096ULL: goto x86_l_4a98;
	case 19105ULL: goto x86_l_4aa1;
	case 19111ULL: goto x86_l_4aa7;
	case 19118ULL: goto x86_l_4aae;
	case 19123ULL: goto x86_l_4ab3;
	case 19128ULL: goto x86_l_4ab8;
	case 19137ULL: goto x86_l_4ac1;
	case 19139ULL: goto x86_l_4ac3;
	case 19144ULL: goto x86_l_4ac8;
	case 19149ULL: goto x86_l_4acd;
	case 19154ULL: goto x86_l_4ad2;
	case 19159ULL: goto x86_l_4ad7;
	case 19164ULL: goto x86_l_4adc;
	case 19166ULL: goto x86_l_4ade;
	case 19168ULL: goto x86_l_4ae0;
	case 19174ULL: goto x86_l_4ae6;
	case 19183ULL: goto x86_l_4aef;
	case 19189ULL: goto x86_l_4af5;
	case 19196ULL: goto x86_l_4afc;
	case 19201ULL: goto x86_l_4b01;
	case 19206ULL: goto x86_l_4b06;
	case 19215ULL: goto x86_l_4b0f;
	case 19217ULL: goto x86_l_4b11;
	case 19222ULL: goto x86_l_4b16;
	case 19227ULL: goto x86_l_4b1b;
	case 19232ULL: goto x86_l_4b20;
	case 19237ULL: goto x86_l_4b25;
	case 19242ULL: goto x86_l_4b2a;
	case 19244ULL: goto x86_l_4b2c;
	case 19246ULL: goto x86_l_4b2e;
	case 19252ULL: goto x86_l_4b34;
	case 19261ULL: goto x86_l_4b3d;
	case 19267ULL: goto x86_l_4b43;
	case 19274ULL: goto x86_l_4b4a;
	case 19279ULL: goto x86_l_4b4f;
	case 19284ULL: goto x86_l_4b54;
	case 19293ULL: goto x86_l_4b5d;
	case 19295ULL: goto x86_l_4b5f;
	case 19300ULL: goto x86_l_4b64;
	case 19305ULL: goto x86_l_4b69;
	case 19310ULL: goto x86_l_4b6e;
	case 19315ULL: goto x86_l_4b73;
	case 19320ULL: goto x86_l_4b78;
	case 19322ULL: goto x86_l_4b7a;
	case 19324ULL: goto x86_l_4b7c;
	case 19330ULL: goto x86_l_4b82;
	case 19339ULL: goto x86_l_4b8b;
	case 19345ULL: goto x86_l_4b91;
	case 19352ULL: goto x86_l_4b98;
	case 19357ULL: goto x86_l_4b9d;
	case 19362ULL: goto x86_l_4ba2;
	case 19371ULL: goto x86_l_4bab;
	case 19373ULL: goto x86_l_4bad;
	case 19378ULL: goto x86_l_4bb2;
	case 19383ULL: goto x86_l_4bb7;
	case 19388ULL: goto x86_l_4bbc;
	case 19393ULL: goto x86_l_4bc1;
	case 19398ULL: goto x86_l_4bc6;
	case 19400ULL: goto x86_l_4bc8;
	case 19402ULL: goto x86_l_4bca;
	case 19408ULL: goto x86_l_4bd0;
	case 19417ULL: goto x86_l_4bd9;
	case 19423ULL: goto x86_l_4bdf;
	case 19430ULL: goto x86_l_4be6;
	case 19435ULL: goto x86_l_4beb;
	case 19440ULL: goto x86_l_4bf0;
	case 19449ULL: goto x86_l_4bf9;
	case 19451ULL: goto x86_l_4bfb;
	case 19456ULL: goto x86_l_4c00;
	case 19461ULL: goto x86_l_4c05;
	case 19466ULL: goto x86_l_4c0a;
	case 19471ULL: goto x86_l_4c0f;
	case 19476ULL: goto x86_l_4c14;
	case 19478ULL: goto x86_l_4c16;
	case 19480ULL: goto x86_l_4c18;
	case 19486ULL: goto x86_l_4c1e;
	case 19495ULL: goto x86_l_4c27;
	case 19501ULL: goto x86_l_4c2d;
	case 19508ULL: goto x86_l_4c34;
	case 19513ULL: goto x86_l_4c39;
	case 19518ULL: goto x86_l_4c3e;
	case 19527ULL: goto x86_l_4c47;
	case 19529ULL: goto x86_l_4c49;
	case 19534ULL: goto x86_l_4c4e;
	case 19539ULL: goto x86_l_4c53;
	case 19544ULL: goto x86_l_4c58;
	case 19549ULL: goto x86_l_4c5d;
	case 19554ULL: goto x86_l_4c62;
	case 19556ULL: goto x86_l_4c64;
	case 19558ULL: goto x86_l_4c66;
	case 19564ULL: goto x86_l_4c6c;
	case 19573ULL: goto x86_l_4c75;
	case 19579ULL: goto x86_l_4c7b;
	case 19586ULL: goto x86_l_4c82;
	case 19591ULL: goto x86_l_4c87;
	case 19596ULL: goto x86_l_4c8c;
	case 19605ULL: goto x86_l_4c95;
	case 19607ULL: goto x86_l_4c97;
	case 19612ULL: goto x86_l_4c9c;
	case 19617ULL: goto x86_l_4ca1;
	case 19622ULL: goto x86_l_4ca6;
	case 19627ULL: goto x86_l_4cab;
	case 19632ULL: goto x86_l_4cb0;
	case 19634ULL: goto x86_l_4cb2;
	case 19636ULL: goto x86_l_4cb4;
	case 19642ULL: goto x86_l_4cba;
	case 19647ULL: goto x86_l_4cbf;
	case 19656ULL: goto x86_l_4cc8;
	case 19661ULL: goto x86_l_4ccd;
	case 19667ULL: goto x86_l_4cd3;
	case 19674ULL: goto x86_l_4cda;
	case 19679ULL: goto x86_l_4cdf;
	case 19684ULL: goto x86_l_4ce4;
	case 19693ULL: goto x86_l_4ced;
	case 19695ULL: goto x86_l_4cef;
	case 19700ULL: goto x86_l_4cf4;
	case 19705ULL: goto x86_l_4cf9;
	case 19710ULL: goto x86_l_4cfe;
	case 19715ULL: goto x86_l_4d03;
	case 19720ULL: goto x86_l_4d08;
	case 19722ULL: goto x86_l_4d0a;
	case 19724ULL: goto x86_l_4d0c;
	case 19730ULL: goto x86_l_4d12;
	case 19735ULL: goto x86_l_4d17;
	case 19744ULL: goto x86_l_4d20;
	case 19749ULL: goto x86_l_4d25;
	case 19755ULL: goto x86_l_4d2b;
	case 19762ULL: goto x86_l_4d32;
	case 19767ULL: goto x86_l_4d37;
	case 19772ULL: goto x86_l_4d3c;
	case 19781ULL: goto x86_l_4d45;
	case 19787ULL: goto x86_l_4d4b;
	case 19792ULL: goto x86_l_4d50;
	case 19797ULL: goto x86_l_4d55;
	case 19802ULL: goto x86_l_4d5a;
	case 19807ULL: goto x86_l_4d5f;
	case 19812ULL: goto x86_l_4d64;
	case 19814ULL: goto x86_l_4d66;
	case 19816ULL: goto x86_l_4d68;
	case 19822ULL: goto x86_l_4d6e;
	case 19827ULL: goto x86_l_4d73;
	case 19832ULL: goto x86_l_4d78;
	case 19837ULL: goto x86_l_4d7d;
	case 19842ULL: goto x86_l_4d82;
	case 19850ULL: goto x86_l_4d8a;
	case 19853ULL: goto x86_l_4d8d;
	case 19855ULL: goto x86_l_4d8f;
	case 19860ULL: goto x86_l_4d94;
	case 19863ULL: goto x86_l_4d97;
	case 19865ULL: goto x86_l_4d99;
	case 19868ULL: goto x86_l_4d9c;
	case 19870ULL: goto x86_l_4d9e;
	case 19872ULL: goto x86_l_4da0;
	case 19877ULL: goto x86_l_4da5;
	case 19879ULL: goto x86_l_4da7;
	case 19884ULL: goto x86_l_4dac;
	case 19889ULL: goto x86_l_4db1;
	case 19893ULL: goto x86_l_4db5;
	case 19895ULL: goto x86_l_4db7;
	case 19898ULL: goto x86_l_4dba;
	case 19907ULL: goto x86_l_4dc3;
	case 19913ULL: goto x86_l_4dc9;
	case 19920ULL: goto x86_l_4dd0;
	case 19923ULL: goto x86_l_4dd3;
	case 19930ULL: goto x86_l_4dda;
	case 19933ULL: goto x86_l_4ddd;
	case 19938ULL: goto x86_l_4de2;
	case 19946ULL: goto x86_l_4dea;
	case 19948ULL: goto x86_l_4dec;
	case 19954ULL: goto x86_l_4df2;
	case 19957ULL: goto x86_l_4df5;
	case 19959ULL: goto x86_l_4df7;
	case 19964ULL: goto x86_l_4dfc;
	case 19969ULL: goto x86_l_4e01;
	case 19974ULL: goto x86_l_4e06;
	case 19979ULL: goto x86_l_4e0b;
	case 19984ULL: goto x86_l_4e10;
	case 19986ULL: goto x86_l_4e12;
	case 19988ULL: goto x86_l_4e14;
	case 19994ULL: goto x86_l_4e1a;
	case 20003ULL: goto x86_l_4e23;
	case 20009ULL: goto x86_l_4e29;
	case 20016ULL: goto x86_l_4e30;
	case 20021ULL: goto x86_l_4e35;
	case 20026ULL: goto x86_l_4e3a;
	case 20035ULL: goto x86_l_4e43;
	case 20037ULL: goto x86_l_4e45;
	case 20042ULL: goto x86_l_4e4a;
	case 20047ULL: goto x86_l_4e4f;
	case 20052ULL: goto x86_l_4e54;
	case 20057ULL: goto x86_l_4e59;
	case 20062ULL: goto x86_l_4e5e;
	case 20064ULL: goto x86_l_4e60;
	case 20066ULL: goto x86_l_4e62;
	case 20072ULL: goto x86_l_4e68;
	case 20081ULL: goto x86_l_4e71;
	case 20087ULL: goto x86_l_4e77;
	case 20094ULL: goto x86_l_4e7e;
	case 20099ULL: goto x86_l_4e83;
	case 20104ULL: goto x86_l_4e88;
	case 20113ULL: goto x86_l_4e91;
	case 20115ULL: goto x86_l_4e93;
	case 20120ULL: goto x86_l_4e98;
	case 20125ULL: goto x86_l_4e9d;
	case 20130ULL: goto x86_l_4ea2;
	case 20135ULL: goto x86_l_4ea7;
	case 20140ULL: goto x86_l_4eac;
	case 20142ULL: goto x86_l_4eae;
	case 20144ULL: goto x86_l_4eb0;
	case 20150ULL: goto x86_l_4eb6;
	case 20159ULL: goto x86_l_4ebf;
	case 20165ULL: goto x86_l_4ec5;
	case 20172ULL: goto x86_l_4ecc;
	case 20177ULL: goto x86_l_4ed1;
	case 20182ULL: goto x86_l_4ed6;
	case 20191ULL: goto x86_l_4edf;
	case 20193ULL: goto x86_l_4ee1;
	case 20198ULL: goto x86_l_4ee6;
	case 20203ULL: goto x86_l_4eeb;
	case 20208ULL: goto x86_l_4ef0;
	case 20213ULL: goto x86_l_4ef5;
	case 20218ULL: goto x86_l_4efa;
	case 20220ULL: goto x86_l_4efc;
	case 20222ULL: goto x86_l_4efe;
	case 20228ULL: goto x86_l_4f04;
	case 20237ULL: goto x86_l_4f0d;
	case 20243ULL: goto x86_l_4f13;
	case 20250ULL: goto x86_l_4f1a;
	case 20255ULL: goto x86_l_4f1f;
	case 20260ULL: goto x86_l_4f24;
	case 20269ULL: goto x86_l_4f2d;
	case 20271ULL: goto x86_l_4f2f;
	case 20276ULL: goto x86_l_4f34;
	case 20281ULL: goto x86_l_4f39;
	case 20286ULL: goto x86_l_4f3e;
	case 20291ULL: goto x86_l_4f43;
	case 20296ULL: goto x86_l_4f48;
	case 20298ULL: goto x86_l_4f4a;
	case 20300ULL: goto x86_l_4f4c;
	case 20306ULL: goto x86_l_4f52;
	case 20315ULL: goto x86_l_4f5b;
	case 20321ULL: goto x86_l_4f61;
	case 20328ULL: goto x86_l_4f68;
	case 20333ULL: goto x86_l_4f6d;
	case 20338ULL: goto x86_l_4f72;
	case 20347ULL: goto x86_l_4f7b;
	case 20349ULL: goto x86_l_4f7d;
	case 20354ULL: goto x86_l_4f82;
	case 20359ULL: goto x86_l_4f87;
	case 20364ULL: goto x86_l_4f8c;
	case 20369ULL: goto x86_l_4f91;
	case 20374ULL: goto x86_l_4f96;
	case 20376ULL: goto x86_l_4f98;
	case 20378ULL: goto x86_l_4f9a;
	case 20384ULL: goto x86_l_4fa0;
	case 20393ULL: goto x86_l_4fa9;
	case 20399ULL: goto x86_l_4faf;
	case 20406ULL: goto x86_l_4fb6;
	case 20411ULL: goto x86_l_4fbb;
	case 20416ULL: goto x86_l_4fc0;
	case 20425ULL: goto x86_l_4fc9;
	case 20427ULL: goto x86_l_4fcb;
	case 20432ULL: goto x86_l_4fd0;
	case 20437ULL: goto x86_l_4fd5;
	case 20442ULL: goto x86_l_4fda;
	case 20447ULL: goto x86_l_4fdf;
	case 20452ULL: goto x86_l_4fe4;
	case 20454ULL: goto x86_l_4fe6;
	case 20456ULL: goto x86_l_4fe8;
	case 20462ULL: goto x86_l_4fee;
	case 20471ULL: goto x86_l_4ff7;
	case 20477ULL: goto x86_l_4ffd;
	case 20484ULL: goto x86_l_5004;
	case 20489ULL: goto x86_l_5009;
	case 20494ULL: goto x86_l_500e;
	case 20503ULL: goto x86_l_5017;
	case 20505ULL: goto x86_l_5019;
	case 20510ULL: goto x86_l_501e;
	case 20515ULL: goto x86_l_5023;
	case 20520ULL: goto x86_l_5028;
	case 20525ULL: goto x86_l_502d;
	case 20530ULL: goto x86_l_5032;
	case 20532ULL: goto x86_l_5034;
	case 20534ULL: goto x86_l_5036;
	case 20540ULL: goto x86_l_503c;
	case 20549ULL: goto x86_l_5045;
	case 20555ULL: goto x86_l_504b;
	case 20562ULL: goto x86_l_5052;
	case 20567ULL: goto x86_l_5057;
	case 20572ULL: goto x86_l_505c;
	case 20581ULL: goto x86_l_5065;
	case 20583ULL: goto x86_l_5067;
	case 20588ULL: goto x86_l_506c;
	case 20593ULL: goto x86_l_5071;
	case 20598ULL: goto x86_l_5076;
	case 20603ULL: goto x86_l_507b;
	case 20608ULL: goto x86_l_5080;
	case 20610ULL: goto x86_l_5082;
	case 20612ULL: goto x86_l_5084;
	case 20618ULL: goto x86_l_508a;
	case 20623ULL: goto x86_l_508f;
	case 20632ULL: goto x86_l_5098;
	case 20638ULL: goto x86_l_509e;
	case 20645ULL: goto x86_l_50a5;
	case 20650ULL: goto x86_l_50aa;
	case 20655ULL: goto x86_l_50af;
	case 20664ULL: goto x86_l_50b8;
	case 20670ULL: goto x86_l_50be;
	case 20675ULL: goto x86_l_50c3;
	case 20680ULL: goto x86_l_50c8;
	case 20685ULL: goto x86_l_50cd;
	case 20690ULL: goto x86_l_50d2;
	case 20693ULL: goto x86_l_50d5;
	case 20695ULL: goto x86_l_50d7;
	case 20700ULL: goto x86_l_50dc;
	case 20705ULL: goto x86_l_50e1;
	case 20710ULL: goto x86_l_50e6;
	case 20715ULL: goto x86_l_50eb;
	case 20720ULL: goto x86_l_50f0;
	case 20722ULL: goto x86_l_50f2;
	case 20724ULL: goto x86_l_50f4;
	case 20730ULL: goto x86_l_50fa;
	case 20739ULL: goto x86_l_5103;
	case 20745ULL: goto x86_l_5109;
	case 20752ULL: goto x86_l_5110;
	case 20757ULL: goto x86_l_5115;
	case 20762ULL: goto x86_l_511a;
	case 20771ULL: goto x86_l_5123;
	case 20773ULL: goto x86_l_5125;
	case 20778ULL: goto x86_l_512a;
	case 20783ULL: goto x86_l_512f;
	case 20788ULL: goto x86_l_5134;
	case 20793ULL: goto x86_l_5139;
	case 20798ULL: goto x86_l_513e;
	case 20800ULL: goto x86_l_5140;
	case 20802ULL: goto x86_l_5142;
	case 20808ULL: goto x86_l_5148;
	case 20817ULL: goto x86_l_5151;
	case 20823ULL: goto x86_l_5157;
	case 20830ULL: goto x86_l_515e;
	case 20835ULL: goto x86_l_5163;
	case 20840ULL: goto x86_l_5168;
	case 20849ULL: goto x86_l_5171;
	case 20851ULL: goto x86_l_5173;
	case 20856ULL: goto x86_l_5178;
	case 20861ULL: goto x86_l_517d;
	case 20866ULL: goto x86_l_5182;
	case 20871ULL: goto x86_l_5187;
	case 20876ULL: goto x86_l_518c;
	case 20878ULL: goto x86_l_518e;
	case 20880ULL: goto x86_l_5190;
	case 20886ULL: goto x86_l_5196;
	case 20895ULL: goto x86_l_519f;
	case 20901ULL: goto x86_l_51a5;
	case 20908ULL: goto x86_l_51ac;
	case 20913ULL: goto x86_l_51b1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4a0f:
	/* 0x4a0f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a14:
	/* 0x4a14: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a19:
	/* 0x4a19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a1b:
	/* 0x4a1b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a1d:
	/* 0x4a1d: js     6987 <generic_sleepable_preload+0x6987> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27015ULL;
	}
x86_l_4a23:
	/* 0x4a23: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4a28:
	/* 0x4a28: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_4a31:
	/* 0x4a31: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4a36:
	/* 0x4a36: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_4a3c:
	/* 0x4a3c: mov    ecx,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_4a43:
	/* 0x4a43: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4a48:
	/* 0x4a48: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a4d:
	/* 0x4a4d: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_4a56:
	/* 0x4a56: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_4a5c:
	/* 0x4a5c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a61:
	/* 0x4a61: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a66:
	/* 0x4a66: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a6b:
	/* 0x4a6b: jmp    4d5a <generic_sleepable_preload+0x4d5a> */
	goto x86_l_4d5a;
x86_l_4a70:
	/* 0x4a70: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4a73:
	/* 0x4a73: je     4a98 <generic_sleepable_preload+0x4a98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a98;
	}
x86_l_4a75:
	/* 0x4a75: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a7a:
	/* 0x4a7a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a7f:
	/* 0x4a7f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a84:
	/* 0x4a84: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a89:
	/* 0x4a89: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a8e:
	/* 0x4a8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a90:
	/* 0x4a90: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a92:
	/* 0x4a92: js     4d78 <generic_sleepable_preload+0x4d78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4d78;
	}
x86_l_4a98:
	/* 0x4a98: cmp    WORD PTR [r13+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_4aa1:
	/* 0x4aa1: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_4aa7:
	/* 0x4aa7: mov    ecx,DWORD PTR [r13+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_4aae:
	/* 0x4aae: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4ab3:
	/* 0x4ab3: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ab8:
	/* 0x4ab8: cmp    WORD PTR [r13+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_4ac1:
	/* 0x4ac1: je     4ae6 <generic_sleepable_preload+0x4ae6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ae6;
	}
x86_l_4ac3:
	/* 0x4ac3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ac8:
	/* 0x4ac8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4acd:
	/* 0x4acd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ad2:
	/* 0x4ad2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ad7:
	/* 0x4ad7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4adc:
	/* 0x4adc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ade:
	/* 0x4ade: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ae0:
	/* 0x4ae0: js     543a <generic_sleepable_preload+0x543a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21562ULL;
	}
x86_l_4ae6:
	/* 0x4ae6: cmp    WORD PTR [r13+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_4aef:
	/* 0x4aef: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_4af5:
	/* 0x4af5: mov    ecx,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_4afc:
	/* 0x4afc: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4b01:
	/* 0x4b01: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b06:
	/* 0x4b06: cmp    WORD PTR [r13+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_4b0f:
	/* 0x4b0f: je     4b34 <generic_sleepable_preload+0x4b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b34;
	}
x86_l_4b11:
	/* 0x4b11: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b16:
	/* 0x4b16: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4b1b:
	/* 0x4b1b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b20:
	/* 0x4b20: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b25:
	/* 0x4b25: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b2a:
	/* 0x4b2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b2c:
	/* 0x4b2c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b2e:
	/* 0x4b2e: js     6121 <generic_sleepable_preload+0x6121> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24865ULL;
	}
x86_l_4b34:
	/* 0x4b34: cmp    WORD PTR [r13+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_4b3d:
	/* 0x4b3d: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_4b43:
	/* 0x4b43: mov    ecx,DWORD PTR [r13+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_4b4a:
	/* 0x4b4a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4b4f:
	/* 0x4b4f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b54:
	/* 0x4b54: cmp    WORD PTR [r13+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_4b5d:
	/* 0x4b5d: je     4b82 <generic_sleepable_preload+0x4b82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b82;
	}
x86_l_4b5f:
	/* 0x4b5f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b64:
	/* 0x4b64: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4b69:
	/* 0x4b69: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b6e:
	/* 0x4b6e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b73:
	/* 0x4b73: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b78:
	/* 0x4b78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b7a:
	/* 0x4b7a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b7c:
	/* 0x4b7c: js     6185 <generic_sleepable_preload+0x6185> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24965ULL;
	}
x86_l_4b82:
	/* 0x4b82: cmp    WORD PTR [r13+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_4b8b:
	/* 0x4b8b: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_4b91:
	/* 0x4b91: mov    ecx,DWORD PTR [r13+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_4b98:
	/* 0x4b98: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4b9d:
	/* 0x4b9d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ba2:
	/* 0x4ba2: cmp    WORD PTR [r13+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_4bab:
	/* 0x4bab: je     4bd0 <generic_sleepable_preload+0x4bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bd0;
	}
x86_l_4bad:
	/* 0x4bad: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bb2:
	/* 0x4bb2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4bb7:
	/* 0x4bb7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4bbc:
	/* 0x4bbc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bc1:
	/* 0x4bc1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4bc6:
	/* 0x4bc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bc8:
	/* 0x4bc8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4bca:
	/* 0x4bca: js     61e9 <generic_sleepable_preload+0x61e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25065ULL;
	}
x86_l_4bd0:
	/* 0x4bd0: cmp    WORD PTR [r13+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_4bd9:
	/* 0x4bd9: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_4bdf:
	/* 0x4bdf: mov    ecx,DWORD PTR [r13+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_4be6:
	/* 0x4be6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4beb:
	/* 0x4beb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bf0:
	/* 0x4bf0: cmp    WORD PTR [r13+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_4bf9:
	/* 0x4bf9: je     4c1e <generic_sleepable_preload+0x4c1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c1e;
	}
x86_l_4bfb:
	/* 0x4bfb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c00:
	/* 0x4c00: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c05:
	/* 0x4c05: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c0a:
	/* 0x4c0a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c0f:
	/* 0x4c0f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c14:
	/* 0x4c14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c16:
	/* 0x4c16: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c18:
	/* 0x4c18: js     624a <generic_sleepable_preload+0x624a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25162ULL;
	}
x86_l_4c1e:
	/* 0x4c1e: cmp    WORD PTR [r13+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_4c27:
	/* 0x4c27: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_4c2d:
	/* 0x4c2d: mov    ecx,DWORD PTR [r13+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_4c34:
	/* 0x4c34: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4c39:
	/* 0x4c39: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c3e:
	/* 0x4c3e: cmp    WORD PTR [r13+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_4c47:
	/* 0x4c47: je     4c6c <generic_sleepable_preload+0x4c6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c6c;
	}
x86_l_4c49:
	/* 0x4c49: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c4e:
	/* 0x4c4e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c53:
	/* 0x4c53: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c58:
	/* 0x4c58: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c5d:
	/* 0x4c5d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c62:
	/* 0x4c62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c64:
	/* 0x4c64: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c66:
	/* 0x4c66: js     65e7 <generic_sleepable_preload+0x65e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26087ULL;
	}
x86_l_4c6c:
	/* 0x4c6c: cmp    WORD PTR [r13+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_4c75:
	/* 0x4c75: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_4c7b:
	/* 0x4c7b: mov    ecx,DWORD PTR [r13+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_4c82:
	/* 0x4c82: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4c87:
	/* 0x4c87: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c8c:
	/* 0x4c8c: cmp    WORD PTR [r13+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_4c95:
	/* 0x4c95: je     4cba <generic_sleepable_preload+0x4cba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4cba;
	}
x86_l_4c97:
	/* 0x4c97: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c9c:
	/* 0x4c9c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4ca1:
	/* 0x4ca1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ca6:
	/* 0x4ca6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cab:
	/* 0x4cab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cb0:
	/* 0x4cb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cb2:
	/* 0x4cb2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4cb4:
	/* 0x4cb4: js     6a35 <generic_sleepable_preload+0x6a35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27189ULL;
	}
x86_l_4cba:
	/* 0x4cba: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4cbf:
	/* 0x4cbf: cmp    WORD PTR [r13+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_4cc8:
	/* 0x4cc8: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4ccd:
	/* 0x4ccd: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_4cd3:
	/* 0x4cd3: mov    ecx,DWORD PTR [r13+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_4cda:
	/* 0x4cda: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4cdf:
	/* 0x4cdf: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ce4:
	/* 0x4ce4: cmp    WORD PTR [r13+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_4ced:
	/* 0x4ced: je     4d12 <generic_sleepable_preload+0x4d12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d12;
	}
x86_l_4cef:
	/* 0x4cef: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cf4:
	/* 0x4cf4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4cf9:
	/* 0x4cf9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4cfe:
	/* 0x4cfe: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d03:
	/* 0x4d03: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d08:
	/* 0x4d08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d0a:
	/* 0x4d0a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d0c:
	/* 0x4d0c: js     6987 <generic_sleepable_preload+0x6987> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27015ULL;
	}
x86_l_4d12:
	/* 0x4d12: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4d17:
	/* 0x4d17: cmp    WORD PTR [r13+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_4d20:
	/* 0x4d20: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4d25:
	/* 0x4d25: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_4d2b:
	/* 0x4d2b: mov    ecx,DWORD PTR [r13+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_4d32:
	/* 0x4d32: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4d37:
	/* 0x4d37: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d3c:
	/* 0x4d3c: cmp    WORD PTR [r13+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_4d45:
	/* 0x4d45: je     65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26094ULL;
	}
x86_l_4d4b:
	/* 0x4d4b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d50:
	/* 0x4d50: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4d55:
	/* 0x4d55: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4d5a:
	/* 0x4d5a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d5f:
	/* 0x4d5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d64:
	/* 0x4d64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d66:
	/* 0x4d66: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d68:
	/* 0x4d68: jns    65ee <generic_sleepable_preload+0x65ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 26094ULL;
	}
x86_l_4d6e:
	/* 0x4d6e: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_4d73:
	/* 0x4d73: jmp    65ec <generic_sleepable_preload+0x65ec> */
	return 26092ULL;
x86_l_4d78:
	/* 0x4d78: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_4d7d:
	/* 0x4d7d: jmp    65ec <generic_sleepable_preload+0x65ec> */
	return 26092ULL;
x86_l_4d82:
	/* 0x4d82: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4d8a:
	/* 0x4d8a: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_4d8d:
	/* 0x4d8d: je     4d99 <generic_sleepable_preload+0x4d99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d99;
	}
x86_l_4d8f:
	/* 0x4d8f: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4d94:
	/* 0x4d94: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4d97:
	/* 0x4d97: jne    4dac <generic_sleepable_preload+0x4dac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4dac;
	}
x86_l_4d99:
	/* 0x4d99: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_4d9c:
	/* 0x4d9c: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_4d9e:
	/* 0x4d9e: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_4da0:
	/* 0x4da0: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_4da5:
	/* 0x4da5: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4da7:
	/* 0x4da7: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_4dac:
	/* 0x4dac: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4db1:
	/* 0x4db1: mov    r14d,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4db5:
	/* 0x4db5: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4db7:
	/* 0x4db7: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_4dba:
	/* 0x4dba: cmp    WORD PTR [r13+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_4dc3:
	/* 0x4dc3: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_4dc9:
	/* 0x4dc9: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_4dd0:
	/* 0x4dd0: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_4dd3:
	/* 0x4dd3: mov    eax,DWORD PTR [r13+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_4dda:
	/* 0x4dda: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4ddd:
	/* 0x4ddd: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4de2:
	/* 0x4de2: movzx  eax,WORD PTR [r13+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_4dea:
	/* 0x4dea: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_4dec:
	/* 0x4dec: je     50d2 <generic_sleepable_preload+0x50d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50d2;
	}
x86_l_4df2:
	/* 0x4df2: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4df5:
	/* 0x4df5: je     4e1a <generic_sleepable_preload+0x4e1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e1a;
	}
x86_l_4df7:
	/* 0x4df7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4dfc:
	/* 0x4dfc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e01:
	/* 0x4e01: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e06:
	/* 0x4e06: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e0b:
	/* 0x4e0b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e10:
	/* 0x4e10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e12:
	/* 0x4e12: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e14:
	/* 0x4e14: js     53d0 <generic_sleepable_preload+0x53d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21456ULL;
	}
x86_l_4e1a:
	/* 0x4e1a: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_4e23:
	/* 0x4e23: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_4e29:
	/* 0x4e29: mov    ecx,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_4e30:
	/* 0x4e30: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4e35:
	/* 0x4e35: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e3a:
	/* 0x4e3a: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_4e43:
	/* 0x4e43: je     4e68 <generic_sleepable_preload+0x4e68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e68;
	}
x86_l_4e45:
	/* 0x4e45: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e4a:
	/* 0x4e4a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e4f:
	/* 0x4e4f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4e54:
	/* 0x4e54: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e59:
	/* 0x4e59: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e5e:
	/* 0x4e5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e60:
	/* 0x4e60: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e62:
	/* 0x4e62: js     5444 <generic_sleepable_preload+0x5444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21572ULL;
	}
x86_l_4e68:
	/* 0x4e68: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_4e71:
	/* 0x4e71: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_4e77:
	/* 0x4e77: mov    ecx,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_4e7e:
	/* 0x4e7e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4e83:
	/* 0x4e83: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e88:
	/* 0x4e88: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_4e91:
	/* 0x4e91: je     4eb6 <generic_sleepable_preload+0x4eb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4eb6;
	}
x86_l_4e93:
	/* 0x4e93: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e98:
	/* 0x4e98: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4e9d:
	/* 0x4e9d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ea2:
	/* 0x4ea2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ea7:
	/* 0x4ea7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4eac:
	/* 0x4eac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4eae:
	/* 0x4eae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4eb0:
	/* 0x4eb0: js     612b <generic_sleepable_preload+0x612b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24875ULL;
	}
x86_l_4eb6:
	/* 0x4eb6: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_4ebf:
	/* 0x4ebf: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_4ec5:
	/* 0x4ec5: mov    ecx,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_4ecc:
	/* 0x4ecc: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4ed1:
	/* 0x4ed1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ed6:
	/* 0x4ed6: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_4edf:
	/* 0x4edf: je     4f04 <generic_sleepable_preload+0x4f04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f04;
	}
x86_l_4ee1:
	/* 0x4ee1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ee6:
	/* 0x4ee6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4eeb:
	/* 0x4eeb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ef0:
	/* 0x4ef0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ef5:
	/* 0x4ef5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4efa:
	/* 0x4efa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4efc:
	/* 0x4efc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4efe:
	/* 0x4efe: js     618f <generic_sleepable_preload+0x618f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24975ULL;
	}
x86_l_4f04:
	/* 0x4f04: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_4f0d:
	/* 0x4f0d: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_4f13:
	/* 0x4f13: mov    ecx,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_4f1a:
	/* 0x4f1a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4f1f:
	/* 0x4f1f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f24:
	/* 0x4f24: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_4f2d:
	/* 0x4f2d: je     4f52 <generic_sleepable_preload+0x4f52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f52;
	}
x86_l_4f2f:
	/* 0x4f2f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f34:
	/* 0x4f34: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f39:
	/* 0x4f39: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4f3e:
	/* 0x4f3e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f43:
	/* 0x4f43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f48:
	/* 0x4f48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f4a:
	/* 0x4f4a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f4c:
	/* 0x4f4c: js     61f3 <generic_sleepable_preload+0x61f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25075ULL;
	}
x86_l_4f52:
	/* 0x4f52: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_4f5b:
	/* 0x4f5b: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_4f61:
	/* 0x4f61: mov    ecx,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_4f68:
	/* 0x4f68: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4f6d:
	/* 0x4f6d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f72:
	/* 0x4f72: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_4f7b:
	/* 0x4f7b: je     4fa0 <generic_sleepable_preload+0x4fa0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fa0;
	}
x86_l_4f7d:
	/* 0x4f7d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f82:
	/* 0x4f82: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4f87:
	/* 0x4f87: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4f8c:
	/* 0x4f8c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f91:
	/* 0x4f91: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f96:
	/* 0x4f96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f98:
	/* 0x4f98: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f9a:
	/* 0x4f9a: js     6254 <generic_sleepable_preload+0x6254> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25172ULL;
	}
x86_l_4fa0:
	/* 0x4fa0: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_4fa9:
	/* 0x4fa9: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_4faf:
	/* 0x4faf: mov    ecx,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_4fb6:
	/* 0x4fb6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4fbb:
	/* 0x4fbb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fc0:
	/* 0x4fc0: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_4fc9:
	/* 0x4fc9: je     4fee <generic_sleepable_preload+0x4fee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fee;
	}
x86_l_4fcb:
	/* 0x4fcb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fd0:
	/* 0x4fd0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4fd5:
	/* 0x4fd5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4fda:
	/* 0x4fda: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fdf:
	/* 0x4fdf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fe4:
	/* 0x4fe4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fe6:
	/* 0x4fe6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4fe8:
	/* 0x4fe8: js     669c <generic_sleepable_preload+0x669c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26268ULL;
	}
x86_l_4fee:
	/* 0x4fee: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_4ff7:
	/* 0x4ff7: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_4ffd:
	/* 0x4ffd: mov    ecx,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_5004:
	/* 0x5004: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5009:
	/* 0x5009: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_500e:
	/* 0x500e: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_5017:
	/* 0x5017: je     503c <generic_sleepable_preload+0x503c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_503c;
	}
x86_l_5019:
	/* 0x5019: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_501e:
	/* 0x501e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5023:
	/* 0x5023: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5028:
	/* 0x5028: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_502d:
	/* 0x502d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5032:
	/* 0x5032: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5034:
	/* 0x5034: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5036:
	/* 0x5036: js     6917 <generic_sleepable_preload+0x6917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26903ULL;
	}
x86_l_503c:
	/* 0x503c: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_5045:
	/* 0x5045: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_504b:
	/* 0x504b: mov    ecx,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_5052:
	/* 0x5052: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5057:
	/* 0x5057: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_505c:
	/* 0x505c: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_5065:
	/* 0x5065: je     508a <generic_sleepable_preload+0x508a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_508a;
	}
x86_l_5067:
	/* 0x5067: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_506c:
	/* 0x506c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5071:
	/* 0x5071: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5076:
	/* 0x5076: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_507b:
	/* 0x507b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5080:
	/* 0x5080: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5082:
	/* 0x5082: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5084:
	/* 0x5084: js     6993 <generic_sleepable_preload+0x6993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27027ULL;
	}
x86_l_508a:
	/* 0x508a: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_508f:
	/* 0x508f: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_5098:
	/* 0x5098: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_509e:
	/* 0x509e: mov    ecx,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_50a5:
	/* 0x50a5: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_50aa:
	/* 0x50aa: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50af:
	/* 0x50af: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_50b8:
	/* 0x50b8: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_50be:
	/* 0x50be: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50c3:
	/* 0x50c3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_50c8:
	/* 0x50c8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_50cd:
	/* 0x50cd: jmp    53b2 <generic_sleepable_preload+0x53b2> */
	return 21426ULL;
x86_l_50d2:
	/* 0x50d2: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_50d5:
	/* 0x50d5: je     50fa <generic_sleepable_preload+0x50fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50fa;
	}
x86_l_50d7:
	/* 0x50d7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50dc:
	/* 0x50dc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_50e1:
	/* 0x50e1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_50e6:
	/* 0x50e6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50eb:
	/* 0x50eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50f0:
	/* 0x50f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50f2:
	/* 0x50f2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_50f4:
	/* 0x50f4: js     53d0 <generic_sleepable_preload+0x53d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21456ULL;
	}
x86_l_50fa:
	/* 0x50fa: cmp    WORD PTR [r13+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_5103:
	/* 0x5103: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_5109:
	/* 0x5109: mov    ecx,DWORD PTR [r13+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_5110:
	/* 0x5110: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5115:
	/* 0x5115: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_511a:
	/* 0x511a: cmp    WORD PTR [r13+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_5123:
	/* 0x5123: je     5148 <generic_sleepable_preload+0x5148> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5148;
	}
x86_l_5125:
	/* 0x5125: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_512a:
	/* 0x512a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_512f:
	/* 0x512f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5134:
	/* 0x5134: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5139:
	/* 0x5139: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_513e:
	/* 0x513e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5140:
	/* 0x5140: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5142:
	/* 0x5142: js     5444 <generic_sleepable_preload+0x5444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 21572ULL;
	}
x86_l_5148:
	/* 0x5148: cmp    WORD PTR [r13+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_5151:
	/* 0x5151: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_5157:
	/* 0x5157: mov    ecx,DWORD PTR [r13+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_515e:
	/* 0x515e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5163:
	/* 0x5163: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5168:
	/* 0x5168: cmp    WORD PTR [r13+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_5171:
	/* 0x5171: je     5196 <generic_sleepable_preload+0x5196> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5196;
	}
x86_l_5173:
	/* 0x5173: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5178:
	/* 0x5178: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_517d:
	/* 0x517d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5182:
	/* 0x5182: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5187:
	/* 0x5187: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_518c:
	/* 0x518c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_518e:
	/* 0x518e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5190:
	/* 0x5190: js     612b <generic_sleepable_preload+0x612b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24875ULL;
	}
x86_l_5196:
	/* 0x5196: cmp    WORD PTR [r13+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_519f:
	/* 0x519f: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_51a5:
	/* 0x51a5: mov    ecx,DWORD PTR [r13+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_51ac:
	/* 0x51ac: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_51b1:
	/* 0x51b1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 20918ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20918ULL: goto x86_l_51b6;
	case 20927ULL: goto x86_l_51bf;
	case 20929ULL: goto x86_l_51c1;
	case 20934ULL: goto x86_l_51c6;
	case 20939ULL: goto x86_l_51cb;
	case 20944ULL: goto x86_l_51d0;
	case 20949ULL: goto x86_l_51d5;
	case 20954ULL: goto x86_l_51da;
	case 20956ULL: goto x86_l_51dc;
	case 20958ULL: goto x86_l_51de;
	case 20964ULL: goto x86_l_51e4;
	case 20973ULL: goto x86_l_51ed;
	case 20979ULL: goto x86_l_51f3;
	case 20986ULL: goto x86_l_51fa;
	case 20991ULL: goto x86_l_51ff;
	case 20996ULL: goto x86_l_5204;
	case 21005ULL: goto x86_l_520d;
	case 21007ULL: goto x86_l_520f;
	case 21012ULL: goto x86_l_5214;
	case 21017ULL: goto x86_l_5219;
	case 21022ULL: goto x86_l_521e;
	case 21027ULL: goto x86_l_5223;
	case 21032ULL: goto x86_l_5228;
	case 21034ULL: goto x86_l_522a;
	case 21036ULL: goto x86_l_522c;
	case 21042ULL: goto x86_l_5232;
	case 21051ULL: goto x86_l_523b;
	case 21057ULL: goto x86_l_5241;
	case 21064ULL: goto x86_l_5248;
	case 21069ULL: goto x86_l_524d;
	case 21074ULL: goto x86_l_5252;
	case 21083ULL: goto x86_l_525b;
	case 21085ULL: goto x86_l_525d;
	case 21090ULL: goto x86_l_5262;
	case 21095ULL: goto x86_l_5267;
	case 21100ULL: goto x86_l_526c;
	case 21105ULL: goto x86_l_5271;
	case 21110ULL: goto x86_l_5276;
	case 21112ULL: goto x86_l_5278;
	case 21114ULL: goto x86_l_527a;
	case 21120ULL: goto x86_l_5280;
	case 21129ULL: goto x86_l_5289;
	case 21135ULL: goto x86_l_528f;
	case 21142ULL: goto x86_l_5296;
	case 21147ULL: goto x86_l_529b;
	case 21152ULL: goto x86_l_52a0;
	case 21161ULL: goto x86_l_52a9;
	case 21163ULL: goto x86_l_52ab;
	case 21168ULL: goto x86_l_52b0;
	case 21173ULL: goto x86_l_52b5;
	case 21178ULL: goto x86_l_52ba;
	case 21183ULL: goto x86_l_52bf;
	case 21188ULL: goto x86_l_52c4;
	case 21190ULL: goto x86_l_52c6;
	case 21192ULL: goto x86_l_52c8;
	case 21198ULL: goto x86_l_52ce;
	case 21207ULL: goto x86_l_52d7;
	case 21213ULL: goto x86_l_52dd;
	case 21220ULL: goto x86_l_52e4;
	case 21225ULL: goto x86_l_52e9;
	case 21230ULL: goto x86_l_52ee;
	case 21239ULL: goto x86_l_52f7;
	case 21241ULL: goto x86_l_52f9;
	case 21246ULL: goto x86_l_52fe;
	case 21251ULL: goto x86_l_5303;
	case 21256ULL: goto x86_l_5308;
	case 21261ULL: goto x86_l_530d;
	case 21266ULL: goto x86_l_5312;
	case 21268ULL: goto x86_l_5314;
	case 21270ULL: goto x86_l_5316;
	case 21276ULL: goto x86_l_531c;
	case 21281ULL: goto x86_l_5321;
	case 21290ULL: goto x86_l_532a;
	case 21296ULL: goto x86_l_5330;
	case 21303ULL: goto x86_l_5337;
	case 21308ULL: goto x86_l_533c;
	case 21313ULL: goto x86_l_5341;
	case 21322ULL: goto x86_l_534a;
	case 21324ULL: goto x86_l_534c;
	case 21329ULL: goto x86_l_5351;
	case 21334ULL: goto x86_l_5356;
	case 21339ULL: goto x86_l_535b;
	case 21344ULL: goto x86_l_5360;
	case 21349ULL: goto x86_l_5365;
	case 21351ULL: goto x86_l_5367;
	case 21353ULL: goto x86_l_5369;
	case 21359ULL: goto x86_l_536f;
	case 21364ULL: goto x86_l_5374;
	case 21373ULL: goto x86_l_537d;
	case 21379ULL: goto x86_l_5383;
	case 21386ULL: goto x86_l_538a;
	case 21391ULL: goto x86_l_538f;
	case 21396ULL: goto x86_l_5394;
	case 21405ULL: goto x86_l_539d;
	case 21411ULL: goto x86_l_53a3;
	case 21416ULL: goto x86_l_53a8;
	case 21421ULL: goto x86_l_53ad;
	case 21426ULL: goto x86_l_53b2;
	case 21431ULL: goto x86_l_53b7;
	case 21436ULL: goto x86_l_53bc;
	case 21438ULL: goto x86_l_53be;
	case 21440ULL: goto x86_l_53c0;
	case 21446ULL: goto x86_l_53c6;
	case 21451ULL: goto x86_l_53cb;
	case 21456ULL: goto x86_l_53d0;
	case 21461ULL: goto x86_l_53d5;
	case 21466ULL: goto x86_l_53da;
	case 21474ULL: goto x86_l_53e2;
	case 21477ULL: goto x86_l_53e5;
	case 21483ULL: goto x86_l_53eb;
	case 21488ULL: goto x86_l_53f0;
	case 21491ULL: goto x86_l_53f3;
	case 21497ULL: goto x86_l_53f9;
	case 21502ULL: goto x86_l_53fe;
	case 21507ULL: goto x86_l_5403;
	case 21512ULL: goto x86_l_5408;
	case 21517ULL: goto x86_l_540d;
	case 21522ULL: goto x86_l_5412;
	case 21527ULL: goto x86_l_5417;
	case 21532ULL: goto x86_l_541c;
	case 21537ULL: goto x86_l_5421;
	case 21542ULL: goto x86_l_5426;
	case 21547ULL: goto x86_l_542b;
	case 21552ULL: goto x86_l_5430;
	case 21557ULL: goto x86_l_5435;
	case 21562ULL: goto x86_l_543a;
	case 21567ULL: goto x86_l_543f;
	case 21572ULL: goto x86_l_5444;
	case 21577ULL: goto x86_l_5449;
	case 21582ULL: goto x86_l_544e;
	case 21585ULL: goto x86_l_5451;
	case 21588ULL: goto x86_l_5454;
	case 21590ULL: goto x86_l_5456;
	case 21592ULL: goto x86_l_5458;
	case 21597ULL: goto x86_l_545d;
	case 21599ULL: goto x86_l_545f;
	case 21604ULL: goto x86_l_5464;
	case 21609ULL: goto x86_l_5469;
	case 21613ULL: goto x86_l_546d;
	case 21615ULL: goto x86_l_546f;
	case 21618ULL: goto x86_l_5472;
	case 21627ULL: goto x86_l_547b;
	case 21633ULL: goto x86_l_5481;
	case 21640ULL: goto x86_l_5488;
	case 21643ULL: goto x86_l_548b;
	case 21650ULL: goto x86_l_5492;
	case 21653ULL: goto x86_l_5495;
	case 21658ULL: goto x86_l_549a;
	case 21666ULL: goto x86_l_54a2;
	case 21668ULL: goto x86_l_54a4;
	case 21674ULL: goto x86_l_54aa;
	case 21677ULL: goto x86_l_54ad;
	case 21679ULL: goto x86_l_54af;
	case 21684ULL: goto x86_l_54b4;
	case 21689ULL: goto x86_l_54b9;
	case 21694ULL: goto x86_l_54be;
	case 21699ULL: goto x86_l_54c3;
	case 21704ULL: goto x86_l_54c8;
	case 21706ULL: goto x86_l_54ca;
	case 21708ULL: goto x86_l_54cc;
	case 21714ULL: goto x86_l_54d2;
	case 21723ULL: goto x86_l_54db;
	case 21729ULL: goto x86_l_54e1;
	case 21736ULL: goto x86_l_54e8;
	case 21741ULL: goto x86_l_54ed;
	case 21746ULL: goto x86_l_54f2;
	case 21755ULL: goto x86_l_54fb;
	case 21757ULL: goto x86_l_54fd;
	case 21762ULL: goto x86_l_5502;
	case 21767ULL: goto x86_l_5507;
	case 21772ULL: goto x86_l_550c;
	case 21777ULL: goto x86_l_5511;
	case 21782ULL: goto x86_l_5516;
	case 21784ULL: goto x86_l_5518;
	case 21786ULL: goto x86_l_551a;
	case 21792ULL: goto x86_l_5520;
	case 21801ULL: goto x86_l_5529;
	case 21807ULL: goto x86_l_552f;
	case 21814ULL: goto x86_l_5536;
	case 21819ULL: goto x86_l_553b;
	case 21824ULL: goto x86_l_5540;
	case 21833ULL: goto x86_l_5549;
	case 21835ULL: goto x86_l_554b;
	case 21840ULL: goto x86_l_5550;
	case 21845ULL: goto x86_l_5555;
	case 21850ULL: goto x86_l_555a;
	case 21855ULL: goto x86_l_555f;
	case 21860ULL: goto x86_l_5564;
	case 21862ULL: goto x86_l_5566;
	case 21864ULL: goto x86_l_5568;
	case 21870ULL: goto x86_l_556e;
	case 21879ULL: goto x86_l_5577;
	case 21885ULL: goto x86_l_557d;
	case 21892ULL: goto x86_l_5584;
	case 21897ULL: goto x86_l_5589;
	case 21902ULL: goto x86_l_558e;
	case 21911ULL: goto x86_l_5597;
	case 21913ULL: goto x86_l_5599;
	case 21918ULL: goto x86_l_559e;
	case 21923ULL: goto x86_l_55a3;
	case 21928ULL: goto x86_l_55a8;
	case 21933ULL: goto x86_l_55ad;
	case 21938ULL: goto x86_l_55b2;
	case 21940ULL: goto x86_l_55b4;
	case 21942ULL: goto x86_l_55b6;
	case 21948ULL: goto x86_l_55bc;
	case 21957ULL: goto x86_l_55c5;
	case 21963ULL: goto x86_l_55cb;
	case 21970ULL: goto x86_l_55d2;
	case 21975ULL: goto x86_l_55d7;
	case 21980ULL: goto x86_l_55dc;
	case 21989ULL: goto x86_l_55e5;
	case 21991ULL: goto x86_l_55e7;
	case 21996ULL: goto x86_l_55ec;
	case 22001ULL: goto x86_l_55f1;
	case 22006ULL: goto x86_l_55f6;
	case 22011ULL: goto x86_l_55fb;
	case 22016ULL: goto x86_l_5600;
	case 22018ULL: goto x86_l_5602;
	case 22020ULL: goto x86_l_5604;
	case 22026ULL: goto x86_l_560a;
	case 22035ULL: goto x86_l_5613;
	case 22041ULL: goto x86_l_5619;
	case 22048ULL: goto x86_l_5620;
	case 22053ULL: goto x86_l_5625;
	case 22058ULL: goto x86_l_562a;
	case 22067ULL: goto x86_l_5633;
	case 22069ULL: goto x86_l_5635;
	case 22074ULL: goto x86_l_563a;
	case 22079ULL: goto x86_l_563f;
	case 22084ULL: goto x86_l_5644;
	case 22089ULL: goto x86_l_5649;
	case 22094ULL: goto x86_l_564e;
	case 22096ULL: goto x86_l_5650;
	case 22098ULL: goto x86_l_5652;
	case 22104ULL: goto x86_l_5658;
	case 22113ULL: goto x86_l_5661;
	case 22119ULL: goto x86_l_5667;
	case 22126ULL: goto x86_l_566e;
	case 22131ULL: goto x86_l_5673;
	case 22136ULL: goto x86_l_5678;
	case 22145ULL: goto x86_l_5681;
	case 22147ULL: goto x86_l_5683;
	case 22152ULL: goto x86_l_5688;
	case 22157ULL: goto x86_l_568d;
	case 22162ULL: goto x86_l_5692;
	case 22167ULL: goto x86_l_5697;
	case 22172ULL: goto x86_l_569c;
	case 22174ULL: goto x86_l_569e;
	case 22176ULL: goto x86_l_56a0;
	case 22182ULL: goto x86_l_56a6;
	case 22191ULL: goto x86_l_56af;
	case 22197ULL: goto x86_l_56b5;
	case 22204ULL: goto x86_l_56bc;
	case 22209ULL: goto x86_l_56c1;
	case 22214ULL: goto x86_l_56c6;
	case 22223ULL: goto x86_l_56cf;
	case 22225ULL: goto x86_l_56d1;
	case 22230ULL: goto x86_l_56d6;
	case 22235ULL: goto x86_l_56db;
	case 22240ULL: goto x86_l_56e0;
	case 22245ULL: goto x86_l_56e5;
	case 22250ULL: goto x86_l_56ea;
	case 22252ULL: goto x86_l_56ec;
	case 22254ULL: goto x86_l_56ee;
	case 22260ULL: goto x86_l_56f4;
	case 22269ULL: goto x86_l_56fd;
	case 22275ULL: goto x86_l_5703;
	case 22282ULL: goto x86_l_570a;
	case 22287ULL: goto x86_l_570f;
	case 22292ULL: goto x86_l_5714;
	case 22301ULL: goto x86_l_571d;
	case 22303ULL: goto x86_l_571f;
	case 22308ULL: goto x86_l_5724;
	case 22313ULL: goto x86_l_5729;
	case 22318ULL: goto x86_l_572e;
	case 22323ULL: goto x86_l_5733;
	case 22328ULL: goto x86_l_5738;
	case 22330ULL: goto x86_l_573a;
	case 22332ULL: goto x86_l_573c;
	case 22338ULL: goto x86_l_5742;
	case 22343ULL: goto x86_l_5747;
	case 22352ULL: goto x86_l_5750;
	case 22358ULL: goto x86_l_5756;
	case 22365ULL: goto x86_l_575d;
	case 22370ULL: goto x86_l_5762;
	case 22375ULL: goto x86_l_5767;
	case 22384ULL: goto x86_l_5770;
	case 22390ULL: goto x86_l_5776;
	case 22395ULL: goto x86_l_577b;
	case 22400ULL: goto x86_l_5780;
	case 22405ULL: goto x86_l_5785;
	case 22410ULL: goto x86_l_578a;
	case 22413ULL: goto x86_l_578d;
	case 22415ULL: goto x86_l_578f;
	case 22420ULL: goto x86_l_5794;
	case 22425ULL: goto x86_l_5799;
	case 22430ULL: goto x86_l_579e;
	case 22435ULL: goto x86_l_57a3;
	case 22440ULL: goto x86_l_57a8;
	case 22442ULL: goto x86_l_57aa;
	case 22444ULL: goto x86_l_57ac;
	case 22450ULL: goto x86_l_57b2;
	case 22459ULL: goto x86_l_57bb;
	case 22465ULL: goto x86_l_57c1;
	case 22472ULL: goto x86_l_57c8;
	case 22477ULL: goto x86_l_57cd;
	case 22482ULL: goto x86_l_57d2;
	case 22491ULL: goto x86_l_57db;
	case 22493ULL: goto x86_l_57dd;
	case 22498ULL: goto x86_l_57e2;
	case 22503ULL: goto x86_l_57e7;
	case 22508ULL: goto x86_l_57ec;
	case 22513ULL: goto x86_l_57f1;
	case 22518ULL: goto x86_l_57f6;
	case 22520ULL: goto x86_l_57f8;
	case 22522ULL: goto x86_l_57fa;
	case 22528ULL: goto x86_l_5800;
	case 22537ULL: goto x86_l_5809;
	case 22543ULL: goto x86_l_580f;
	case 22550ULL: goto x86_l_5816;
	case 22555ULL: goto x86_l_581b;
	case 22560ULL: goto x86_l_5820;
	case 22569ULL: goto x86_l_5829;
	case 22571ULL: goto x86_l_582b;
	case 22576ULL: goto x86_l_5830;
	case 22581ULL: goto x86_l_5835;
	case 22586ULL: goto x86_l_583a;
	case 22591ULL: goto x86_l_583f;
	case 22596ULL: goto x86_l_5844;
	case 22598ULL: goto x86_l_5846;
	case 22600ULL: goto x86_l_5848;
	case 22606ULL: goto x86_l_584e;
	case 22615ULL: goto x86_l_5857;
	case 22621ULL: goto x86_l_585d;
	case 22628ULL: goto x86_l_5864;
	case 22633ULL: goto x86_l_5869;
	case 22638ULL: goto x86_l_586e;
	case 22647ULL: goto x86_l_5877;
	case 22649ULL: goto x86_l_5879;
	case 22654ULL: goto x86_l_587e;
	case 22659ULL: goto x86_l_5883;
	case 22664ULL: goto x86_l_5888;
	case 22669ULL: goto x86_l_588d;
	case 22674ULL: goto x86_l_5892;
	case 22676ULL: goto x86_l_5894;
	case 22678ULL: goto x86_l_5896;
	case 22684ULL: goto x86_l_589c;
	case 22693ULL: goto x86_l_58a5;
	case 22699ULL: goto x86_l_58ab;
	case 22706ULL: goto x86_l_58b2;
	case 22711ULL: goto x86_l_58b7;
	case 22716ULL: goto x86_l_58bc;
	case 22725ULL: goto x86_l_58c5;
	case 22727ULL: goto x86_l_58c7;
	case 22732ULL: goto x86_l_58cc;
	case 22737ULL: goto x86_l_58d1;
	case 22742ULL: goto x86_l_58d6;
	case 22747ULL: goto x86_l_58db;
	case 22752ULL: goto x86_l_58e0;
	case 22754ULL: goto x86_l_58e2;
	case 22756ULL: goto x86_l_58e4;
	case 22762ULL: goto x86_l_58ea;
	case 22771ULL: goto x86_l_58f3;
	case 22777ULL: goto x86_l_58f9;
	case 22784ULL: goto x86_l_5900;
	case 22789ULL: goto x86_l_5905;
	case 22794ULL: goto x86_l_590a;
	case 22803ULL: goto x86_l_5913;
	case 22805ULL: goto x86_l_5915;
	case 22810ULL: goto x86_l_591a;
	case 22815ULL: goto x86_l_591f;
	case 22820ULL: goto x86_l_5924;
	case 22825ULL: goto x86_l_5929;
	case 22830ULL: goto x86_l_592e;
	case 22832ULL: goto x86_l_5930;
	case 22834ULL: goto x86_l_5932;
	case 22840ULL: goto x86_l_5938;
	case 22849ULL: goto x86_l_5941;
	case 22855ULL: goto x86_l_5947;
	case 22862ULL: goto x86_l_594e;
	case 22867ULL: goto x86_l_5953;
	case 22872ULL: goto x86_l_5958;
	case 22881ULL: goto x86_l_5961;
	default: return 0xffffffffffffffffULL;
	}
x86_l_51b6:
	/* 0x51b6: cmp    WORD PTR [r13+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_51bf:
	/* 0x51bf: je     51e4 <generic_sleepable_preload+0x51e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_51e4;
	}
x86_l_51c1:
	/* 0x51c1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51c6:
	/* 0x51c6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_51cb:
	/* 0x51cb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_51d0:
	/* 0x51d0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51d5:
	/* 0x51d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51da:
	/* 0x51da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51dc:
	/* 0x51dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_51de:
	/* 0x51de: js     618f <generic_sleepable_preload+0x618f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24975ULL;
	}
x86_l_51e4:
	/* 0x51e4: cmp    WORD PTR [r13+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_51ed:
	/* 0x51ed: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_51f3:
	/* 0x51f3: mov    ecx,DWORD PTR [r13+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_51fa:
	/* 0x51fa: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_51ff:
	/* 0x51ff: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5204:
	/* 0x5204: cmp    WORD PTR [r13+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_520d:
	/* 0x520d: je     5232 <generic_sleepable_preload+0x5232> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5232;
	}
x86_l_520f:
	/* 0x520f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5214:
	/* 0x5214: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5219:
	/* 0x5219: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_521e:
	/* 0x521e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5223:
	/* 0x5223: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5228:
	/* 0x5228: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_522a:
	/* 0x522a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_522c:
	/* 0x522c: js     61f3 <generic_sleepable_preload+0x61f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25075ULL;
	}
x86_l_5232:
	/* 0x5232: cmp    WORD PTR [r13+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_523b:
	/* 0x523b: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_5241:
	/* 0x5241: mov    ecx,DWORD PTR [r13+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_5248:
	/* 0x5248: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_524d:
	/* 0x524d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5252:
	/* 0x5252: cmp    WORD PTR [r13+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_525b:
	/* 0x525b: je     5280 <generic_sleepable_preload+0x5280> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5280;
	}
x86_l_525d:
	/* 0x525d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5262:
	/* 0x5262: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5267:
	/* 0x5267: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_526c:
	/* 0x526c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5271:
	/* 0x5271: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5276:
	/* 0x5276: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5278:
	/* 0x5278: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_527a:
	/* 0x527a: js     6254 <generic_sleepable_preload+0x6254> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25172ULL;
	}
x86_l_5280:
	/* 0x5280: cmp    WORD PTR [r13+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_5289:
	/* 0x5289: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_528f:
	/* 0x528f: mov    ecx,DWORD PTR [r13+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_5296:
	/* 0x5296: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_529b:
	/* 0x529b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52a0:
	/* 0x52a0: cmp    WORD PTR [r13+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_52a9:
	/* 0x52a9: je     52ce <generic_sleepable_preload+0x52ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_52ce;
	}
x86_l_52ab:
	/* 0x52ab: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52b0:
	/* 0x52b0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_52b5:
	/* 0x52b5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_52ba:
	/* 0x52ba: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52bf:
	/* 0x52bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52c4:
	/* 0x52c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52c6:
	/* 0x52c6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52c8:
	/* 0x52c8: js     669c <generic_sleepable_preload+0x669c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26268ULL;
	}
x86_l_52ce:
	/* 0x52ce: cmp    WORD PTR [r13+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_52d7:
	/* 0x52d7: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_52dd:
	/* 0x52dd: mov    ecx,DWORD PTR [r13+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_52e4:
	/* 0x52e4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_52e9:
	/* 0x52e9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52ee:
	/* 0x52ee: cmp    WORD PTR [r13+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_52f7:
	/* 0x52f7: je     531c <generic_sleepable_preload+0x531c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_531c;
	}
x86_l_52f9:
	/* 0x52f9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52fe:
	/* 0x52fe: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5303:
	/* 0x5303: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5308:
	/* 0x5308: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_530d:
	/* 0x530d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5312:
	/* 0x5312: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5314:
	/* 0x5314: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5316:
	/* 0x5316: js     6a4b <generic_sleepable_preload+0x6a4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27211ULL;
	}
x86_l_531c:
	/* 0x531c: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5321:
	/* 0x5321: cmp    WORD PTR [r13+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_532a:
	/* 0x532a: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_5330:
	/* 0x5330: mov    ecx,DWORD PTR [r13+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_5337:
	/* 0x5337: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_533c:
	/* 0x533c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5341:
	/* 0x5341: cmp    WORD PTR [r13+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_534a:
	/* 0x534a: je     536f <generic_sleepable_preload+0x536f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_536f;
	}
x86_l_534c:
	/* 0x534c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5351:
	/* 0x5351: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5356:
	/* 0x5356: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_535b:
	/* 0x535b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5360:
	/* 0x5360: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5365:
	/* 0x5365: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5367:
	/* 0x5367: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5369:
	/* 0x5369: js     6993 <generic_sleepable_preload+0x6993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27027ULL;
	}
x86_l_536f:
	/* 0x536f: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5374:
	/* 0x5374: cmp    WORD PTR [r13+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_537d:
	/* 0x537d: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_5383:
	/* 0x5383: mov    ecx,DWORD PTR [r13+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_538a:
	/* 0x538a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_538f:
	/* 0x538f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5394:
	/* 0x5394: cmp    WORD PTR [r13+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_539d:
	/* 0x539d: je     66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26275ULL;
	}
x86_l_53a3:
	/* 0x53a3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53a8:
	/* 0x53a8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_53ad:
	/* 0x53ad: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_53b2:
	/* 0x53b2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53b7:
	/* 0x53b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53bc:
	/* 0x53bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53be:
	/* 0x53be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_53c0:
	/* 0x53c0: jns    66a3 <generic_sleepable_preload+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 26275ULL;
	}
x86_l_53c6:
	/* 0x53c6: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_53cb:
	/* 0x53cb: jmp    66a1 <generic_sleepable_preload+0x66a1> */
	return 26273ULL;
x86_l_53d0:
	/* 0x53d0: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_53d5:
	/* 0x53d5: jmp    66a1 <generic_sleepable_preload+0x66a1> */
	return 26273ULL;
x86_l_53da:
	/* 0x53da: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_53e2:
	/* 0x53e2: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_53e5:
	/* 0x53e5: je     5aa1 <generic_sleepable_preload+0x5aa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23201ULL;
	}
x86_l_53eb:
	/* 0x53eb: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_53f0:
	/* 0x53f0: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_53f3:
	/* 0x53f3: je     5aa1 <generic_sleepable_preload+0x5aa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23201ULL;
	}
x86_l_53f9:
	/* 0x53f9: jmp    5ab4 <generic_sleepable_preload+0x5ab4> */
	return 23220ULL;
x86_l_53fe:
	/* 0x53fe: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5403:
	/* 0x5403: jmp    6277 <generic_sleepable_preload+0x6277> */
	return 25207ULL;
x86_l_5408:
	/* 0x5408: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_540d:
	/* 0x540d: jmp    6304 <generic_sleepable_preload+0x6304> */
	return 25348ULL;
x86_l_5412:
	/* 0x5412: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5417:
	/* 0x5417: jmp    6391 <generic_sleepable_preload+0x6391> */
	return 25489ULL;
x86_l_541c:
	/* 0x541c: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5421:
	/* 0x5421: jmp    641e <generic_sleepable_preload+0x641e> */
	return 25630ULL;
x86_l_5426:
	/* 0x5426: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_542b:
	/* 0x542b: jmp    64ab <generic_sleepable_preload+0x64ab> */
	return 25771ULL;
x86_l_5430:
	/* 0x5430: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5435:
	/* 0x5435: jmp    6538 <generic_sleepable_preload+0x6538> */
	return 25912ULL;
x86_l_543a:
	/* 0x543a: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_543f:
	/* 0x543f: jmp    65ec <generic_sleepable_preload+0x65ec> */
	return 26092ULL;
x86_l_5444:
	/* 0x5444: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5449:
	/* 0x5449: jmp    66a1 <generic_sleepable_preload+0x66a1> */
	return 26273ULL;
x86_l_544e:
	/* 0x544e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5451:
	/* 0x5451: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_5454:
	/* 0x5454: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_5456:
	/* 0x5456: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_5458:
	/* 0x5458: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_545d:
	/* 0x545d: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_545f:
	/* 0x545f: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_5464:
	/* 0x5464: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5469:
	/* 0x5469: mov    r14d,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_546d:
	/* 0x546d: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_546f:
	/* 0x546f: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_5472:
	/* 0x5472: cmp    WORD PTR [r13+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_547b:
	/* 0x547b: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_5481:
	/* 0x5481: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_5488:
	/* 0x5488: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_548b:
	/* 0x548b: mov    eax,DWORD PTR [r13+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_5492:
	/* 0x5492: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5495:
	/* 0x5495: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_549a:
	/* 0x549a: movzx  eax,WORD PTR [r13+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_54a2:
	/* 0x54a2: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_54a4:
	/* 0x54a4: je     578a <generic_sleepable_preload+0x578a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_578a;
	}
x86_l_54aa:
	/* 0x54aa: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_54ad:
	/* 0x54ad: je     54d2 <generic_sleepable_preload+0x54d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54d2;
	}
x86_l_54af:
	/* 0x54af: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54b4:
	/* 0x54b4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_54b9:
	/* 0x54b9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_54be:
	/* 0x54be: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54c3:
	/* 0x54c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54c8:
	/* 0x54c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54ca:
	/* 0x54ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_54cc:
	/* 0x54cc: js     5a88 <generic_sleepable_preload+0x5a88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23176ULL;
	}
x86_l_54d2:
	/* 0x54d2: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_54db:
	/* 0x54db: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_54e1:
	/* 0x54e1: mov    ecx,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_54e8:
	/* 0x54e8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_54ed:
	/* 0x54ed: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54f2:
	/* 0x54f2: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_54fb:
	/* 0x54fb: je     5520 <generic_sleepable_preload+0x5520> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5520;
	}
x86_l_54fd:
	/* 0x54fd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5502:
	/* 0x5502: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5507:
	/* 0x5507: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_550c:
	/* 0x550c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5511:
	/* 0x5511: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5516:
	/* 0x5516: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5518:
	/* 0x5518: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_551a:
	/* 0x551a: js     5a92 <generic_sleepable_preload+0x5a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23186ULL;
	}
x86_l_5520:
	/* 0x5520: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_5529:
	/* 0x5529: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_552f:
	/* 0x552f: mov    ecx,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_5536:
	/* 0x5536: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_553b:
	/* 0x553b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5540:
	/* 0x5540: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_5549:
	/* 0x5549: je     556e <generic_sleepable_preload+0x556e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_556e;
	}
x86_l_554b:
	/* 0x554b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5550:
	/* 0x5550: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5555:
	/* 0x5555: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_555a:
	/* 0x555a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_555f:
	/* 0x555f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5564:
	/* 0x5564: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5566:
	/* 0x5566: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5568:
	/* 0x5568: js     6135 <generic_sleepable_preload+0x6135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24885ULL;
	}
x86_l_556e:
	/* 0x556e: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_5577:
	/* 0x5577: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_557d:
	/* 0x557d: mov    ecx,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_5584:
	/* 0x5584: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5589:
	/* 0x5589: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_558e:
	/* 0x558e: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_5597:
	/* 0x5597: je     55bc <generic_sleepable_preload+0x55bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55bc;
	}
x86_l_5599:
	/* 0x5599: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_559e:
	/* 0x559e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_55a3:
	/* 0x55a3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55a8:
	/* 0x55a8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55ad:
	/* 0x55ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55b2:
	/* 0x55b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55b4:
	/* 0x55b4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_55b6:
	/* 0x55b6: js     6199 <generic_sleepable_preload+0x6199> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24985ULL;
	}
x86_l_55bc:
	/* 0x55bc: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_55c5:
	/* 0x55c5: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_55cb:
	/* 0x55cb: mov    ecx,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_55d2:
	/* 0x55d2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_55d7:
	/* 0x55d7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55dc:
	/* 0x55dc: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_55e5:
	/* 0x55e5: je     560a <generic_sleepable_preload+0x560a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_560a;
	}
x86_l_55e7:
	/* 0x55e7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55ec:
	/* 0x55ec: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_55f1:
	/* 0x55f1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55f6:
	/* 0x55f6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55fb:
	/* 0x55fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5600:
	/* 0x5600: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5602:
	/* 0x5602: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5604:
	/* 0x5604: js     61fd <generic_sleepable_preload+0x61fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25085ULL;
	}
x86_l_560a:
	/* 0x560a: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_5613:
	/* 0x5613: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_5619:
	/* 0x5619: mov    ecx,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_5620:
	/* 0x5620: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5625:
	/* 0x5625: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_562a:
	/* 0x562a: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_5633:
	/* 0x5633: je     5658 <generic_sleepable_preload+0x5658> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5658;
	}
x86_l_5635:
	/* 0x5635: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_563a:
	/* 0x563a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_563f:
	/* 0x563f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5644:
	/* 0x5644: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5649:
	/* 0x5649: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_564e:
	/* 0x564e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5650:
	/* 0x5650: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5652:
	/* 0x5652: js     625e <generic_sleepable_preload+0x625e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25182ULL;
	}
x86_l_5658:
	/* 0x5658: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_5661:
	/* 0x5661: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_5667:
	/* 0x5667: mov    ecx,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_566e:
	/* 0x566e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5673:
	/* 0x5673: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5678:
	/* 0x5678: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_5681:
	/* 0x5681: je     56a6 <generic_sleepable_preload+0x56a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56a6;
	}
x86_l_5683:
	/* 0x5683: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5688:
	/* 0x5688: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_568d:
	/* 0x568d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5692:
	/* 0x5692: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5697:
	/* 0x5697: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_569c:
	/* 0x569c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_569e:
	/* 0x569e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56a0:
	/* 0x56a0: js     674c <generic_sleepable_preload+0x674c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26444ULL;
	}
x86_l_56a6:
	/* 0x56a6: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_56af:
	/* 0x56af: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_56b5:
	/* 0x56b5: mov    ecx,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_56bc:
	/* 0x56bc: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_56c1:
	/* 0x56c1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56c6:
	/* 0x56c6: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_56cf:
	/* 0x56cf: je     56f4 <generic_sleepable_preload+0x56f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56f4;
	}
x86_l_56d1:
	/* 0x56d1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56d6:
	/* 0x56d6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_56db:
	/* 0x56db: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_56e0:
	/* 0x56e0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56e5:
	/* 0x56e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56ea:
	/* 0x56ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56ec:
	/* 0x56ec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56ee:
	/* 0x56ee: js     6923 <generic_sleepable_preload+0x6923> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26915ULL;
	}
x86_l_56f4:
	/* 0x56f4: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_56fd:
	/* 0x56fd: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_5703:
	/* 0x5703: mov    ecx,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_570a:
	/* 0x570a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_570f:
	/* 0x570f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5714:
	/* 0x5714: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_571d:
	/* 0x571d: je     5742 <generic_sleepable_preload+0x5742> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5742;
	}
x86_l_571f:
	/* 0x571f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5724:
	/* 0x5724: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5729:
	/* 0x5729: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_572e:
	/* 0x572e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5733:
	/* 0x5733: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5738:
	/* 0x5738: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_573a:
	/* 0x573a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_573c:
	/* 0x573c: js     69a4 <generic_sleepable_preload+0x69a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27044ULL;
	}
x86_l_5742:
	/* 0x5742: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5747:
	/* 0x5747: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_5750:
	/* 0x5750: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_5756:
	/* 0x5756: mov    ecx,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_575d:
	/* 0x575d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5762:
	/* 0x5762: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5767:
	/* 0x5767: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_5770:
	/* 0x5770: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_5776:
	/* 0x5776: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_577b:
	/* 0x577b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5780:
	/* 0x5780: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5785:
	/* 0x5785: jmp    5a6a <generic_sleepable_preload+0x5a6a> */
	return 23146ULL;
x86_l_578a:
	/* 0x578a: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_578d:
	/* 0x578d: je     57b2 <generic_sleepable_preload+0x57b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57b2;
	}
x86_l_578f:
	/* 0x578f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5794:
	/* 0x5794: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5799:
	/* 0x5799: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_579e:
	/* 0x579e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57a3:
	/* 0x57a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57a8:
	/* 0x57a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57aa:
	/* 0x57aa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57ac:
	/* 0x57ac: js     5a88 <generic_sleepable_preload+0x5a88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23176ULL;
	}
x86_l_57b2:
	/* 0x57b2: cmp    WORD PTR [r13+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_57bb:
	/* 0x57bb: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_57c1:
	/* 0x57c1: mov    ecx,DWORD PTR [r13+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_57c8:
	/* 0x57c8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_57cd:
	/* 0x57cd: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57d2:
	/* 0x57d2: cmp    WORD PTR [r13+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_57db:
	/* 0x57db: je     5800 <generic_sleepable_preload+0x5800> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5800;
	}
x86_l_57dd:
	/* 0x57dd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57e2:
	/* 0x57e2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_57e7:
	/* 0x57e7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_57ec:
	/* 0x57ec: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57f1:
	/* 0x57f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57f6:
	/* 0x57f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57f8:
	/* 0x57f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57fa:
	/* 0x57fa: js     5a92 <generic_sleepable_preload+0x5a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23186ULL;
	}
x86_l_5800:
	/* 0x5800: cmp    WORD PTR [r13+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_5809:
	/* 0x5809: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_580f:
	/* 0x580f: mov    ecx,DWORD PTR [r13+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_5816:
	/* 0x5816: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_581b:
	/* 0x581b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5820:
	/* 0x5820: cmp    WORD PTR [r13+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_5829:
	/* 0x5829: je     584e <generic_sleepable_preload+0x584e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_584e;
	}
x86_l_582b:
	/* 0x582b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5830:
	/* 0x5830: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5835:
	/* 0x5835: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_583a:
	/* 0x583a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_583f:
	/* 0x583f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5844:
	/* 0x5844: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5846:
	/* 0x5846: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5848:
	/* 0x5848: js     6135 <generic_sleepable_preload+0x6135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24885ULL;
	}
x86_l_584e:
	/* 0x584e: cmp    WORD PTR [r13+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_5857:
	/* 0x5857: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_585d:
	/* 0x585d: mov    ecx,DWORD PTR [r13+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_5864:
	/* 0x5864: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5869:
	/* 0x5869: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_586e:
	/* 0x586e: cmp    WORD PTR [r13+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_5877:
	/* 0x5877: je     589c <generic_sleepable_preload+0x589c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_589c;
	}
x86_l_5879:
	/* 0x5879: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_587e:
	/* 0x587e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5883:
	/* 0x5883: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5888:
	/* 0x5888: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_588d:
	/* 0x588d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5892:
	/* 0x5892: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5894:
	/* 0x5894: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5896:
	/* 0x5896: js     6199 <generic_sleepable_preload+0x6199> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24985ULL;
	}
x86_l_589c:
	/* 0x589c: cmp    WORD PTR [r13+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_58a5:
	/* 0x58a5: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_58ab:
	/* 0x58ab: mov    ecx,DWORD PTR [r13+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_58b2:
	/* 0x58b2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_58b7:
	/* 0x58b7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58bc:
	/* 0x58bc: cmp    WORD PTR [r13+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_58c5:
	/* 0x58c5: je     58ea <generic_sleepable_preload+0x58ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58ea;
	}
x86_l_58c7:
	/* 0x58c7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58cc:
	/* 0x58cc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_58d1:
	/* 0x58d1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_58d6:
	/* 0x58d6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58db:
	/* 0x58db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58e0:
	/* 0x58e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58e2:
	/* 0x58e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_58e4:
	/* 0x58e4: js     61fd <generic_sleepable_preload+0x61fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25085ULL;
	}
x86_l_58ea:
	/* 0x58ea: cmp    WORD PTR [r13+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_58f3:
	/* 0x58f3: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_58f9:
	/* 0x58f9: mov    ecx,DWORD PTR [r13+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_5900:
	/* 0x5900: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5905:
	/* 0x5905: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_590a:
	/* 0x590a: cmp    WORD PTR [r13+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_5913:
	/* 0x5913: je     5938 <generic_sleepable_preload+0x5938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5938;
	}
x86_l_5915:
	/* 0x5915: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_591a:
	/* 0x591a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_591f:
	/* 0x591f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5924:
	/* 0x5924: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5929:
	/* 0x5929: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_592e:
	/* 0x592e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5930:
	/* 0x5930: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5932:
	/* 0x5932: js     625e <generic_sleepable_preload+0x625e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25182ULL;
	}
x86_l_5938:
	/* 0x5938: cmp    WORD PTR [r13+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_5941:
	/* 0x5941: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_5947:
	/* 0x5947: mov    ecx,DWORD PTR [r13+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_594e:
	/* 0x594e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5953:
	/* 0x5953: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5958:
	/* 0x5958: cmp    WORD PTR [r13+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_5961:
	/* 0x5961: je     5986 <generic_sleepable_preload+0x5986> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22918ULL;
	}
	return 22883ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22883ULL: goto x86_l_5963;
	case 22888ULL: goto x86_l_5968;
	case 22893ULL: goto x86_l_596d;
	case 22898ULL: goto x86_l_5972;
	case 22903ULL: goto x86_l_5977;
	case 22908ULL: goto x86_l_597c;
	case 22910ULL: goto x86_l_597e;
	case 22912ULL: goto x86_l_5980;
	case 22918ULL: goto x86_l_5986;
	case 22927ULL: goto x86_l_598f;
	case 22933ULL: goto x86_l_5995;
	case 22940ULL: goto x86_l_599c;
	case 22945ULL: goto x86_l_59a1;
	case 22950ULL: goto x86_l_59a6;
	case 22959ULL: goto x86_l_59af;
	case 22961ULL: goto x86_l_59b1;
	case 22966ULL: goto x86_l_59b6;
	case 22971ULL: goto x86_l_59bb;
	case 22976ULL: goto x86_l_59c0;
	case 22981ULL: goto x86_l_59c5;
	case 22986ULL: goto x86_l_59ca;
	case 22988ULL: goto x86_l_59cc;
	case 22990ULL: goto x86_l_59ce;
	case 22996ULL: goto x86_l_59d4;
	case 23001ULL: goto x86_l_59d9;
	case 23010ULL: goto x86_l_59e2;
	case 23016ULL: goto x86_l_59e8;
	case 23023ULL: goto x86_l_59ef;
	case 23028ULL: goto x86_l_59f4;
	case 23033ULL: goto x86_l_59f9;
	case 23042ULL: goto x86_l_5a02;
	case 23044ULL: goto x86_l_5a04;
	case 23049ULL: goto x86_l_5a09;
	case 23054ULL: goto x86_l_5a0e;
	case 23059ULL: goto x86_l_5a13;
	case 23064ULL: goto x86_l_5a18;
	case 23069ULL: goto x86_l_5a1d;
	case 23071ULL: goto x86_l_5a1f;
	case 23073ULL: goto x86_l_5a21;
	case 23079ULL: goto x86_l_5a27;
	case 23084ULL: goto x86_l_5a2c;
	case 23093ULL: goto x86_l_5a35;
	case 23099ULL: goto x86_l_5a3b;
	case 23106ULL: goto x86_l_5a42;
	case 23111ULL: goto x86_l_5a47;
	case 23116ULL: goto x86_l_5a4c;
	case 23125ULL: goto x86_l_5a55;
	case 23131ULL: goto x86_l_5a5b;
	case 23136ULL: goto x86_l_5a60;
	case 23141ULL: goto x86_l_5a65;
	case 23146ULL: goto x86_l_5a6a;
	case 23151ULL: goto x86_l_5a6f;
	case 23156ULL: goto x86_l_5a74;
	case 23158ULL: goto x86_l_5a76;
	case 23160ULL: goto x86_l_5a78;
	case 23166ULL: goto x86_l_5a7e;
	case 23171ULL: goto x86_l_5a83;
	case 23176ULL: goto x86_l_5a88;
	case 23181ULL: goto x86_l_5a8d;
	case 23186ULL: goto x86_l_5a92;
	case 23191ULL: goto x86_l_5a97;
	case 23196ULL: goto x86_l_5a9c;
	case 23201ULL: goto x86_l_5aa1;
	case 23204ULL: goto x86_l_5aa4;
	case 23206ULL: goto x86_l_5aa6;
	case 23208ULL: goto x86_l_5aa8;
	case 23213ULL: goto x86_l_5aad;
	case 23215ULL: goto x86_l_5aaf;
	case 23220ULL: goto x86_l_5ab4;
	case 23225ULL: goto x86_l_5ab9;
	case 23229ULL: goto x86_l_5abd;
	case 23231ULL: goto x86_l_5abf;
	case 23234ULL: goto x86_l_5ac2;
	case 23243ULL: goto x86_l_5acb;
	case 23249ULL: goto x86_l_5ad1;
	case 23256ULL: goto x86_l_5ad8;
	case 23259ULL: goto x86_l_5adb;
	case 23266ULL: goto x86_l_5ae2;
	case 23269ULL: goto x86_l_5ae5;
	case 23274ULL: goto x86_l_5aea;
	case 23282ULL: goto x86_l_5af2;
	case 23284ULL: goto x86_l_5af4;
	case 23290ULL: goto x86_l_5afa;
	case 23293ULL: goto x86_l_5afd;
	case 23295ULL: goto x86_l_5aff;
	case 23300ULL: goto x86_l_5b04;
	case 23305ULL: goto x86_l_5b09;
	case 23310ULL: goto x86_l_5b0e;
	case 23315ULL: goto x86_l_5b13;
	case 23320ULL: goto x86_l_5b18;
	case 23322ULL: goto x86_l_5b1a;
	case 23324ULL: goto x86_l_5b1c;
	case 23330ULL: goto x86_l_5b22;
	case 23339ULL: goto x86_l_5b2b;
	case 23345ULL: goto x86_l_5b31;
	case 23352ULL: goto x86_l_5b38;
	case 23357ULL: goto x86_l_5b3d;
	case 23362ULL: goto x86_l_5b42;
	case 23371ULL: goto x86_l_5b4b;
	case 23373ULL: goto x86_l_5b4d;
	case 23378ULL: goto x86_l_5b52;
	case 23383ULL: goto x86_l_5b57;
	case 23388ULL: goto x86_l_5b5c;
	case 23393ULL: goto x86_l_5b61;
	case 23398ULL: goto x86_l_5b66;
	case 23400ULL: goto x86_l_5b68;
	case 23402ULL: goto x86_l_5b6a;
	case 23408ULL: goto x86_l_5b70;
	case 23417ULL: goto x86_l_5b79;
	case 23423ULL: goto x86_l_5b7f;
	case 23430ULL: goto x86_l_5b86;
	case 23435ULL: goto x86_l_5b8b;
	case 23440ULL: goto x86_l_5b90;
	case 23449ULL: goto x86_l_5b99;
	case 23451ULL: goto x86_l_5b9b;
	case 23456ULL: goto x86_l_5ba0;
	case 23461ULL: goto x86_l_5ba5;
	case 23466ULL: goto x86_l_5baa;
	case 23471ULL: goto x86_l_5baf;
	case 23476ULL: goto x86_l_5bb4;
	case 23478ULL: goto x86_l_5bb6;
	case 23480ULL: goto x86_l_5bb8;
	case 23486ULL: goto x86_l_5bbe;
	case 23495ULL: goto x86_l_5bc7;
	case 23501ULL: goto x86_l_5bcd;
	case 23508ULL: goto x86_l_5bd4;
	case 23513ULL: goto x86_l_5bd9;
	case 23518ULL: goto x86_l_5bde;
	case 23527ULL: goto x86_l_5be7;
	case 23529ULL: goto x86_l_5be9;
	case 23534ULL: goto x86_l_5bee;
	case 23539ULL: goto x86_l_5bf3;
	case 23544ULL: goto x86_l_5bf8;
	case 23549ULL: goto x86_l_5bfd;
	case 23554ULL: goto x86_l_5c02;
	case 23556ULL: goto x86_l_5c04;
	case 23558ULL: goto x86_l_5c06;
	case 23564ULL: goto x86_l_5c0c;
	case 23573ULL: goto x86_l_5c15;
	case 23579ULL: goto x86_l_5c1b;
	case 23586ULL: goto x86_l_5c22;
	case 23591ULL: goto x86_l_5c27;
	case 23596ULL: goto x86_l_5c2c;
	case 23605ULL: goto x86_l_5c35;
	case 23607ULL: goto x86_l_5c37;
	case 23612ULL: goto x86_l_5c3c;
	case 23617ULL: goto x86_l_5c41;
	case 23622ULL: goto x86_l_5c46;
	case 23627ULL: goto x86_l_5c4b;
	case 23632ULL: goto x86_l_5c50;
	case 23634ULL: goto x86_l_5c52;
	case 23636ULL: goto x86_l_5c54;
	case 23642ULL: goto x86_l_5c5a;
	case 23651ULL: goto x86_l_5c63;
	case 23657ULL: goto x86_l_5c69;
	case 23664ULL: goto x86_l_5c70;
	case 23669ULL: goto x86_l_5c75;
	case 23674ULL: goto x86_l_5c7a;
	case 23683ULL: goto x86_l_5c83;
	case 23685ULL: goto x86_l_5c85;
	case 23690ULL: goto x86_l_5c8a;
	case 23695ULL: goto x86_l_5c8f;
	case 23700ULL: goto x86_l_5c94;
	case 23705ULL: goto x86_l_5c99;
	case 23710ULL: goto x86_l_5c9e;
	case 23712ULL: goto x86_l_5ca0;
	case 23714ULL: goto x86_l_5ca2;
	case 23720ULL: goto x86_l_5ca8;
	case 23729ULL: goto x86_l_5cb1;
	case 23735ULL: goto x86_l_5cb7;
	case 23742ULL: goto x86_l_5cbe;
	case 23747ULL: goto x86_l_5cc3;
	case 23752ULL: goto x86_l_5cc8;
	case 23761ULL: goto x86_l_5cd1;
	case 23763ULL: goto x86_l_5cd3;
	case 23768ULL: goto x86_l_5cd8;
	case 23773ULL: goto x86_l_5cdd;
	case 23778ULL: goto x86_l_5ce2;
	case 23783ULL: goto x86_l_5ce7;
	case 23788ULL: goto x86_l_5cec;
	case 23790ULL: goto x86_l_5cee;
	case 23792ULL: goto x86_l_5cf0;
	case 23798ULL: goto x86_l_5cf6;
	case 23807ULL: goto x86_l_5cff;
	case 23813ULL: goto x86_l_5d05;
	case 23820ULL: goto x86_l_5d0c;
	case 23825ULL: goto x86_l_5d11;
	case 23830ULL: goto x86_l_5d16;
	case 23839ULL: goto x86_l_5d1f;
	case 23841ULL: goto x86_l_5d21;
	case 23846ULL: goto x86_l_5d26;
	case 23851ULL: goto x86_l_5d2b;
	case 23856ULL: goto x86_l_5d30;
	case 23861ULL: goto x86_l_5d35;
	case 23866ULL: goto x86_l_5d3a;
	case 23868ULL: goto x86_l_5d3c;
	case 23870ULL: goto x86_l_5d3e;
	case 23876ULL: goto x86_l_5d44;
	case 23881ULL: goto x86_l_5d49;
	case 23889ULL: goto x86_l_5d51;
	case 23895ULL: goto x86_l_5d57;
	case 23901ULL: goto x86_l_5d5d;
	case 23906ULL: goto x86_l_5d62;
	case 23911ULL: goto x86_l_5d67;
	case 23919ULL: goto x86_l_5d6f;
	case 23921ULL: goto x86_l_5d71;
	case 23926ULL: goto x86_l_5d76;
	case 23931ULL: goto x86_l_5d7b;
	case 23936ULL: goto x86_l_5d80;
	case 23941ULL: goto x86_l_5d85;
	case 23946ULL: goto x86_l_5d8a;
	case 23948ULL: goto x86_l_5d8c;
	case 23950ULL: goto x86_l_5d8e;
	case 23956ULL: goto x86_l_5d94;
	case 23961ULL: goto x86_l_5d99;
	case 23969ULL: goto x86_l_5da1;
	case 23975ULL: goto x86_l_5da7;
	case 23981ULL: goto x86_l_5dad;
	case 23986ULL: goto x86_l_5db2;
	case 23991ULL: goto x86_l_5db7;
	case 23999ULL: goto x86_l_5dbf;
	case 24005ULL: goto x86_l_5dc5;
	case 24010ULL: goto x86_l_5dca;
	case 24015ULL: goto x86_l_5dcf;
	case 24020ULL: goto x86_l_5dd4;
	case 24025ULL: goto x86_l_5dd9;
	case 24028ULL: goto x86_l_5ddc;
	case 24030ULL: goto x86_l_5dde;
	case 24035ULL: goto x86_l_5de3;
	case 24040ULL: goto x86_l_5de8;
	case 24045ULL: goto x86_l_5ded;
	case 24050ULL: goto x86_l_5df2;
	case 24055ULL: goto x86_l_5df7;
	case 24057ULL: goto x86_l_5df9;
	case 24059ULL: goto x86_l_5dfb;
	case 24065ULL: goto x86_l_5e01;
	case 24074ULL: goto x86_l_5e0a;
	case 24080ULL: goto x86_l_5e10;
	case 24087ULL: goto x86_l_5e17;
	case 24092ULL: goto x86_l_5e1c;
	case 24097ULL: goto x86_l_5e21;
	case 24106ULL: goto x86_l_5e2a;
	case 24108ULL: goto x86_l_5e2c;
	case 24113ULL: goto x86_l_5e31;
	case 24118ULL: goto x86_l_5e36;
	case 24123ULL: goto x86_l_5e3b;
	case 24128ULL: goto x86_l_5e40;
	case 24133ULL: goto x86_l_5e45;
	case 24135ULL: goto x86_l_5e47;
	case 24137ULL: goto x86_l_5e49;
	case 24143ULL: goto x86_l_5e4f;
	case 24152ULL: goto x86_l_5e58;
	case 24158ULL: goto x86_l_5e5e;
	case 24165ULL: goto x86_l_5e65;
	case 24170ULL: goto x86_l_5e6a;
	case 24175ULL: goto x86_l_5e6f;
	case 24184ULL: goto x86_l_5e78;
	case 24186ULL: goto x86_l_5e7a;
	case 24191ULL: goto x86_l_5e7f;
	case 24196ULL: goto x86_l_5e84;
	case 24201ULL: goto x86_l_5e89;
	case 24206ULL: goto x86_l_5e8e;
	case 24211ULL: goto x86_l_5e93;
	case 24213ULL: goto x86_l_5e95;
	case 24215ULL: goto x86_l_5e97;
	case 24221ULL: goto x86_l_5e9d;
	case 24230ULL: goto x86_l_5ea6;
	case 24236ULL: goto x86_l_5eac;
	case 24243ULL: goto x86_l_5eb3;
	case 24248ULL: goto x86_l_5eb8;
	case 24253ULL: goto x86_l_5ebd;
	case 24262ULL: goto x86_l_5ec6;
	case 24264ULL: goto x86_l_5ec8;
	case 24269ULL: goto x86_l_5ecd;
	case 24274ULL: goto x86_l_5ed2;
	case 24279ULL: goto x86_l_5ed7;
	case 24284ULL: goto x86_l_5edc;
	case 24289ULL: goto x86_l_5ee1;
	case 24291ULL: goto x86_l_5ee3;
	case 24293ULL: goto x86_l_5ee5;
	case 24299ULL: goto x86_l_5eeb;
	case 24308ULL: goto x86_l_5ef4;
	case 24314ULL: goto x86_l_5efa;
	case 24321ULL: goto x86_l_5f01;
	case 24326ULL: goto x86_l_5f06;
	case 24331ULL: goto x86_l_5f0b;
	case 24340ULL: goto x86_l_5f14;
	case 24342ULL: goto x86_l_5f16;
	case 24347ULL: goto x86_l_5f1b;
	case 24352ULL: goto x86_l_5f20;
	case 24357ULL: goto x86_l_5f25;
	case 24362ULL: goto x86_l_5f2a;
	case 24367ULL: goto x86_l_5f2f;
	case 24369ULL: goto x86_l_5f31;
	case 24371ULL: goto x86_l_5f33;
	case 24377ULL: goto x86_l_5f39;
	case 24386ULL: goto x86_l_5f42;
	case 24392ULL: goto x86_l_5f48;
	case 24399ULL: goto x86_l_5f4f;
	case 24404ULL: goto x86_l_5f54;
	case 24409ULL: goto x86_l_5f59;
	case 24418ULL: goto x86_l_5f62;
	case 24420ULL: goto x86_l_5f64;
	case 24425ULL: goto x86_l_5f69;
	case 24430ULL: goto x86_l_5f6e;
	case 24435ULL: goto x86_l_5f73;
	case 24440ULL: goto x86_l_5f78;
	case 24445ULL: goto x86_l_5f7d;
	case 24447ULL: goto x86_l_5f7f;
	case 24449ULL: goto x86_l_5f81;
	case 24455ULL: goto x86_l_5f87;
	case 24464ULL: goto x86_l_5f90;
	case 24470ULL: goto x86_l_5f96;
	case 24477ULL: goto x86_l_5f9d;
	case 24482ULL: goto x86_l_5fa2;
	case 24487ULL: goto x86_l_5fa7;
	case 24496ULL: goto x86_l_5fb0;
	case 24498ULL: goto x86_l_5fb2;
	case 24503ULL: goto x86_l_5fb7;
	case 24508ULL: goto x86_l_5fbc;
	case 24513ULL: goto x86_l_5fc1;
	case 24518ULL: goto x86_l_5fc6;
	case 24523ULL: goto x86_l_5fcb;
	case 24525ULL: goto x86_l_5fcd;
	case 24527ULL: goto x86_l_5fcf;
	case 24533ULL: goto x86_l_5fd5;
	case 24542ULL: goto x86_l_5fde;
	case 24548ULL: goto x86_l_5fe4;
	case 24555ULL: goto x86_l_5feb;
	case 24560ULL: goto x86_l_5ff0;
	case 24565ULL: goto x86_l_5ff5;
	case 24574ULL: goto x86_l_5ffe;
	case 24576ULL: goto x86_l_6000;
	case 24581ULL: goto x86_l_6005;
	case 24586ULL: goto x86_l_600a;
	case 24591ULL: goto x86_l_600f;
	case 24596ULL: goto x86_l_6014;
	case 24601ULL: goto x86_l_6019;
	case 24603ULL: goto x86_l_601b;
	case 24605ULL: goto x86_l_601d;
	case 24611ULL: goto x86_l_6023;
	case 24616ULL: goto x86_l_6028;
	case 24624ULL: goto x86_l_6030;
	case 24630ULL: goto x86_l_6036;
	case 24636ULL: goto x86_l_603c;
	case 24641ULL: goto x86_l_6041;
	case 24646ULL: goto x86_l_6046;
	case 24654ULL: goto x86_l_604e;
	case 24656ULL: goto x86_l_6050;
	case 24661ULL: goto x86_l_6055;
	case 24666ULL: goto x86_l_605a;
	case 24671ULL: goto x86_l_605f;
	case 24676ULL: goto x86_l_6064;
	case 24681ULL: goto x86_l_6069;
	case 24683ULL: goto x86_l_606b;
	case 24685ULL: goto x86_l_606d;
	case 24691ULL: goto x86_l_6073;
	case 24696ULL: goto x86_l_6078;
	case 24704ULL: goto x86_l_6080;
	case 24710ULL: goto x86_l_6086;
	case 24716ULL: goto x86_l_608c;
	case 24721ULL: goto x86_l_6091;
	case 24726ULL: goto x86_l_6096;
	case 24734ULL: goto x86_l_609e;
	case 24740ULL: goto x86_l_60a4;
	case 24745ULL: goto x86_l_60a9;
	case 24750ULL: goto x86_l_60ae;
	case 24755ULL: goto x86_l_60b3;
	case 24760ULL: goto x86_l_60b8;
	case 24765ULL: goto x86_l_60bd;
	case 24767ULL: goto x86_l_60bf;
	case 24769ULL: goto x86_l_60c1;
	case 24775ULL: goto x86_l_60c7;
	case 24780ULL: goto x86_l_60cc;
	case 24785ULL: goto x86_l_60d1;
	case 24790ULL: goto x86_l_60d6;
	case 24795ULL: goto x86_l_60db;
	case 24800ULL: goto x86_l_60e0;
	case 24805ULL: goto x86_l_60e5;
	case 24810ULL: goto x86_l_60ea;
	case 24815ULL: goto x86_l_60ef;
	case 24820ULL: goto x86_l_60f4;
	case 24825ULL: goto x86_l_60f9;
	case 24830ULL: goto x86_l_60fe;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5963:
	/* 0x5963: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5968:
	/* 0x5968: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_596d:
	/* 0x596d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5972:
	/* 0x5972: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5977:
	/* 0x5977: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_597c:
	/* 0x597c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_597e:
	/* 0x597e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5980:
	/* 0x5980: js     674c <generic_sleepable_preload+0x674c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26444ULL;
	}
x86_l_5986:
	/* 0x5986: cmp    WORD PTR [r13+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_598f:
	/* 0x598f: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_5995:
	/* 0x5995: mov    ecx,DWORD PTR [r13+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_599c:
	/* 0x599c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_59a1:
	/* 0x59a1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59a6:
	/* 0x59a6: cmp    WORD PTR [r13+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_59af:
	/* 0x59af: je     59d4 <generic_sleepable_preload+0x59d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59d4;
	}
x86_l_59b1:
	/* 0x59b1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59b6:
	/* 0x59b6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_59bb:
	/* 0x59bb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_59c0:
	/* 0x59c0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59c5:
	/* 0x59c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59ca:
	/* 0x59ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59cc:
	/* 0x59cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_59ce:
	/* 0x59ce: js     6a5c <generic_sleepable_preload+0x6a5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27228ULL;
	}
x86_l_59d4:
	/* 0x59d4: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_59d9:
	/* 0x59d9: cmp    WORD PTR [r13+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_59e2:
	/* 0x59e2: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_59e8:
	/* 0x59e8: mov    ecx,DWORD PTR [r13+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_59ef:
	/* 0x59ef: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_59f4:
	/* 0x59f4: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59f9:
	/* 0x59f9: cmp    WORD PTR [r13+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_5a02:
	/* 0x5a02: je     5a27 <generic_sleepable_preload+0x5a27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a27;
	}
x86_l_5a04:
	/* 0x5a04: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a09:
	/* 0x5a09: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5a0e:
	/* 0x5a0e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5a13:
	/* 0x5a13: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a18:
	/* 0x5a18: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a1d:
	/* 0x5a1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a1f:
	/* 0x5a1f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5a21:
	/* 0x5a21: js     69a4 <generic_sleepable_preload+0x69a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27044ULL;
	}
x86_l_5a27:
	/* 0x5a27: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5a2c:
	/* 0x5a2c: cmp    WORD PTR [r13+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_5a35:
	/* 0x5a35: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_5a3b:
	/* 0x5a3b: mov    ecx,DWORD PTR [r13+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_5a42:
	/* 0x5a42: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5a47:
	/* 0x5a47: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a4c:
	/* 0x5a4c: cmp    WORD PTR [r13+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_5a55:
	/* 0x5a55: je     6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26451ULL;
	}
x86_l_5a5b:
	/* 0x5a5b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a60:
	/* 0x5a60: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5a65:
	/* 0x5a65: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5a6a:
	/* 0x5a6a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a6f:
	/* 0x5a6f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a74:
	/* 0x5a74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a76:
	/* 0x5a76: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5a78:
	/* 0x5a78: jns    6753 <generic_sleepable_preload+0x6753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 26451ULL;
	}
x86_l_5a7e:
	/* 0x5a7e: mov    ebx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 10ULL);
x86_l_5a83:
	/* 0x5a83: jmp    6751 <generic_sleepable_preload+0x6751> */
	return 26449ULL;
x86_l_5a88:
	/* 0x5a88: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_5a8d:
	/* 0x5a8d: jmp    6751 <generic_sleepable_preload+0x6751> */
	return 26449ULL;
x86_l_5a92:
	/* 0x5a92: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_5a97:
	/* 0x5a97: jmp    6751 <generic_sleepable_preload+0x6751> */
	return 26449ULL;
x86_l_5a9c:
	/* 0x5a9c: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5aa1:
	/* 0x5aa1: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_5aa4:
	/* 0x5aa4: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_5aa6:
	/* 0x5aa6: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_5aa8:
	/* 0x5aa8: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_5aad:
	/* 0x5aad: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5aaf:
	/* 0x5aaf: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_5ab4:
	/* 0x5ab4: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ab9:
	/* 0x5ab9: mov    ebx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5abd:
	/* 0x5abd: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5abf:
	/* 0x5abf: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_5ac2:
	/* 0x5ac2: cmp    WORD PTR [r13+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_5acb:
	/* 0x5acb: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_5ad1:
	/* 0x5ad1: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_5ad8:
	/* 0x5ad8: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_5adb:
	/* 0x5adb: mov    eax,DWORD PTR [r13+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_5ae2:
	/* 0x5ae2: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5ae5:
	/* 0x5ae5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5aea:
	/* 0x5aea: movzx  eax,WORD PTR [r13+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_5af2:
	/* 0x5af2: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_5af4:
	/* 0x5af4: je     5dd9 <generic_sleepable_preload+0x5dd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5dd9;
	}
x86_l_5afa:
	/* 0x5afa: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5afd:
	/* 0x5afd: je     5b22 <generic_sleepable_preload+0x5b22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b22;
	}
x86_l_5aff:
	/* 0x5aff: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b04:
	/* 0x5b04: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5b09:
	/* 0x5b09: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5b0e:
	/* 0x5b0e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b13:
	/* 0x5b13: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b18:
	/* 0x5b18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b1a:
	/* 0x5b1a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b1c:
	/* 0x5b1c: js     60d1 <generic_sleepable_preload+0x60d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_60d1;
	}
x86_l_5b22:
	/* 0x5b22: cmp    WORD PTR [r13+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_5b2b:
	/* 0x5b2b: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_5b31:
	/* 0x5b31: mov    ecx,DWORD PTR [r13+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_5b38:
	/* 0x5b38: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5b3d:
	/* 0x5b3d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b42:
	/* 0x5b42: cmp    WORD PTR [r13+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_5b4b:
	/* 0x5b4b: je     5b70 <generic_sleepable_preload+0x5b70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b70;
	}
x86_l_5b4d:
	/* 0x5b4d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b52:
	/* 0x5b52: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5b57:
	/* 0x5b57: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5b5c:
	/* 0x5b5c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b61:
	/* 0x5b61: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b66:
	/* 0x5b66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b68:
	/* 0x5b68: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b6a:
	/* 0x5b6a: js     60db <generic_sleepable_preload+0x60db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_60db;
	}
x86_l_5b70:
	/* 0x5b70: cmp    WORD PTR [r13+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_5b79:
	/* 0x5b79: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_5b7f:
	/* 0x5b7f: mov    ecx,DWORD PTR [r13+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_5b86:
	/* 0x5b86: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5b8b:
	/* 0x5b8b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b90:
	/* 0x5b90: cmp    WORD PTR [r13+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_5b99:
	/* 0x5b99: je     5bbe <generic_sleepable_preload+0x5bbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5bbe;
	}
x86_l_5b9b:
	/* 0x5b9b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ba0:
	/* 0x5ba0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5ba5:
	/* 0x5ba5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5baa:
	/* 0x5baa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5baf:
	/* 0x5baf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5bb4:
	/* 0x5bb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bb6:
	/* 0x5bb6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5bb8:
	/* 0x5bb8: js     613f <generic_sleepable_preload+0x613f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24895ULL;
	}
x86_l_5bbe:
	/* 0x5bbe: cmp    WORD PTR [r13+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_5bc7:
	/* 0x5bc7: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_5bcd:
	/* 0x5bcd: mov    ecx,DWORD PTR [r13+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_5bd4:
	/* 0x5bd4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5bd9:
	/* 0x5bd9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bde:
	/* 0x5bde: cmp    WORD PTR [r13+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_5be7:
	/* 0x5be7: je     5c0c <generic_sleepable_preload+0x5c0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c0c;
	}
x86_l_5be9:
	/* 0x5be9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bee:
	/* 0x5bee: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5bf3:
	/* 0x5bf3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5bf8:
	/* 0x5bf8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bfd:
	/* 0x5bfd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c02:
	/* 0x5c02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c04:
	/* 0x5c04: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5c06:
	/* 0x5c06: js     61a3 <generic_sleepable_preload+0x61a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24995ULL;
	}
x86_l_5c0c:
	/* 0x5c0c: cmp    WORD PTR [r13+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_5c15:
	/* 0x5c15: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_5c1b:
	/* 0x5c1b: mov    ecx,DWORD PTR [r13+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_5c22:
	/* 0x5c22: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5c27:
	/* 0x5c27: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c2c:
	/* 0x5c2c: cmp    WORD PTR [r13+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_5c35:
	/* 0x5c35: je     5c5a <generic_sleepable_preload+0x5c5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c5a;
	}
x86_l_5c37:
	/* 0x5c37: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c3c:
	/* 0x5c3c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5c41:
	/* 0x5c41: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5c46:
	/* 0x5c46: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c4b:
	/* 0x5c4b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c50:
	/* 0x5c50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c52:
	/* 0x5c52: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5c54:
	/* 0x5c54: js     6207 <generic_sleepable_preload+0x6207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25095ULL;
	}
x86_l_5c5a:
	/* 0x5c5a: cmp    WORD PTR [r13+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_5c63:
	/* 0x5c63: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_5c69:
	/* 0x5c69: mov    ecx,DWORD PTR [r13+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_5c70:
	/* 0x5c70: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5c75:
	/* 0x5c75: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c7a:
	/* 0x5c7a: cmp    WORD PTR [r13+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_5c83:
	/* 0x5c83: je     5ca8 <generic_sleepable_preload+0x5ca8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ca8;
	}
x86_l_5c85:
	/* 0x5c85: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c8a:
	/* 0x5c8a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5c8f:
	/* 0x5c8f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5c94:
	/* 0x5c94: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c99:
	/* 0x5c99: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c9e:
	/* 0x5c9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ca0:
	/* 0x5ca0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5ca2:
	/* 0x5ca2: js     6268 <generic_sleepable_preload+0x6268> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25192ULL;
	}
x86_l_5ca8:
	/* 0x5ca8: cmp    WORD PTR [r13+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_5cb1:
	/* 0x5cb1: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_5cb7:
	/* 0x5cb7: mov    ecx,DWORD PTR [r13+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_5cbe:
	/* 0x5cbe: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5cc3:
	/* 0x5cc3: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cc8:
	/* 0x5cc8: cmp    WORD PTR [r13+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_5cd1:
	/* 0x5cd1: je     5cf6 <generic_sleepable_preload+0x5cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5cf6;
	}
x86_l_5cd3:
	/* 0x5cd3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cd8:
	/* 0x5cd8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5cdd:
	/* 0x5cdd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5ce2:
	/* 0x5ce2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ce7:
	/* 0x5ce7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5cec:
	/* 0x5cec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cee:
	/* 0x5cee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5cf0:
	/* 0x5cf0: js     67fc <generic_sleepable_preload+0x67fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26620ULL;
	}
x86_l_5cf6:
	/* 0x5cf6: cmp    WORD PTR [r13+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5cff:
	/* 0x5cff: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_5d05:
	/* 0x5d05: mov    ecx,DWORD PTR [r13+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5d0c:
	/* 0x5d0c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5d11:
	/* 0x5d11: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d16:
	/* 0x5d16: cmp    WORD PTR [r13+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_5d1f:
	/* 0x5d1f: je     5d44 <generic_sleepable_preload+0x5d44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d44;
	}
x86_l_5d21:
	/* 0x5d21: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d26:
	/* 0x5d26: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5d2b:
	/* 0x5d2b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5d30:
	/* 0x5d30: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d35:
	/* 0x5d35: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d3a:
	/* 0x5d3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d3c:
	/* 0x5d3c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5d3e:
	/* 0x5d3e: js     68ac <generic_sleepable_preload+0x68ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26796ULL;
	}
x86_l_5d44:
	/* 0x5d44: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5d49:
	/* 0x5d49: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_5d51:
	/* 0x5d51: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_5d57:
	/* 0x5d57: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_5d5d:
	/* 0x5d5d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5d62:
	/* 0x5d62: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d67:
	/* 0x5d67: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_5d6f:
	/* 0x5d6f: je     5d94 <generic_sleepable_preload+0x5d94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d94;
	}
x86_l_5d71:
	/* 0x5d71: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d76:
	/* 0x5d76: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5d7b:
	/* 0x5d7b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5d80:
	/* 0x5d80: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d85:
	/* 0x5d85: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d8a:
	/* 0x5d8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d8c:
	/* 0x5d8c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5d8e:
	/* 0x5d8e: js     69b5 <generic_sleepable_preload+0x69b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27061ULL;
	}
x86_l_5d94:
	/* 0x5d94: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5d99:
	/* 0x5d99: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_5da1:
	/* 0x5da1: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_5da7:
	/* 0x5da7: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_5dad:
	/* 0x5dad: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5db2:
	/* 0x5db2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5db7:
	/* 0x5db7: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_5dbf:
	/* 0x5dbf: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_5dc5:
	/* 0x5dc5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dca:
	/* 0x5dca: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5dcf:
	/* 0x5dcf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5dd4:
	/* 0x5dd4: jmp    60b3 <generic_sleepable_preload+0x60b3> */
	goto x86_l_60b3;
x86_l_5dd9:
	/* 0x5dd9: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5ddc:
	/* 0x5ddc: je     5e01 <generic_sleepable_preload+0x5e01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e01;
	}
x86_l_5dde:
	/* 0x5dde: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5de3:
	/* 0x5de3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5de8:
	/* 0x5de8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5ded:
	/* 0x5ded: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5df2:
	/* 0x5df2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5df7:
	/* 0x5df7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5df9:
	/* 0x5df9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5dfb:
	/* 0x5dfb: js     60d1 <generic_sleepable_preload+0x60d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_60d1;
	}
x86_l_5e01:
	/* 0x5e01: cmp    WORD PTR [r13+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_5e0a:
	/* 0x5e0a: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_5e10:
	/* 0x5e10: mov    ecx,DWORD PTR [r13+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_5e17:
	/* 0x5e17: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5e1c:
	/* 0x5e1c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e21:
	/* 0x5e21: cmp    WORD PTR [r13+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_5e2a:
	/* 0x5e2a: je     5e4f <generic_sleepable_preload+0x5e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e4f;
	}
x86_l_5e2c:
	/* 0x5e2c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e31:
	/* 0x5e31: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5e36:
	/* 0x5e36: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5e3b:
	/* 0x5e3b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e40:
	/* 0x5e40: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e45:
	/* 0x5e45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e47:
	/* 0x5e47: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5e49:
	/* 0x5e49: js     60db <generic_sleepable_preload+0x60db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_60db;
	}
x86_l_5e4f:
	/* 0x5e4f: cmp    WORD PTR [r13+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_5e58:
	/* 0x5e58: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_5e5e:
	/* 0x5e5e: mov    ecx,DWORD PTR [r13+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_5e65:
	/* 0x5e65: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5e6a:
	/* 0x5e6a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e6f:
	/* 0x5e6f: cmp    WORD PTR [r13+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_5e78:
	/* 0x5e78: je     5e9d <generic_sleepable_preload+0x5e9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e9d;
	}
x86_l_5e7a:
	/* 0x5e7a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e7f:
	/* 0x5e7f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5e84:
	/* 0x5e84: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5e89:
	/* 0x5e89: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e8e:
	/* 0x5e8e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e93:
	/* 0x5e93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e95:
	/* 0x5e95: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5e97:
	/* 0x5e97: js     613f <generic_sleepable_preload+0x613f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24895ULL;
	}
x86_l_5e9d:
	/* 0x5e9d: cmp    WORD PTR [r13+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_5ea6:
	/* 0x5ea6: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_5eac:
	/* 0x5eac: mov    ecx,DWORD PTR [r13+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_5eb3:
	/* 0x5eb3: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5eb8:
	/* 0x5eb8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ebd:
	/* 0x5ebd: cmp    WORD PTR [r13+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_5ec6:
	/* 0x5ec6: je     5eeb <generic_sleepable_preload+0x5eeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5eeb;
	}
x86_l_5ec8:
	/* 0x5ec8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ecd:
	/* 0x5ecd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5ed2:
	/* 0x5ed2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5ed7:
	/* 0x5ed7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5edc:
	/* 0x5edc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ee1:
	/* 0x5ee1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ee3:
	/* 0x5ee3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5ee5:
	/* 0x5ee5: js     61a3 <generic_sleepable_preload+0x61a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24995ULL;
	}
x86_l_5eeb:
	/* 0x5eeb: cmp    WORD PTR [r13+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_5ef4:
	/* 0x5ef4: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_5efa:
	/* 0x5efa: mov    ecx,DWORD PTR [r13+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_5f01:
	/* 0x5f01: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5f06:
	/* 0x5f06: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f0b:
	/* 0x5f0b: cmp    WORD PTR [r13+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_5f14:
	/* 0x5f14: je     5f39 <generic_sleepable_preload+0x5f39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f39;
	}
x86_l_5f16:
	/* 0x5f16: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f1b:
	/* 0x5f1b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5f20:
	/* 0x5f20: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5f25:
	/* 0x5f25: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f2a:
	/* 0x5f2a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f2f:
	/* 0x5f2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f31:
	/* 0x5f31: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5f33:
	/* 0x5f33: js     6207 <generic_sleepable_preload+0x6207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25095ULL;
	}
x86_l_5f39:
	/* 0x5f39: cmp    WORD PTR [r13+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_5f42:
	/* 0x5f42: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_5f48:
	/* 0x5f48: mov    ecx,DWORD PTR [r13+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_5f4f:
	/* 0x5f4f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5f54:
	/* 0x5f54: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f59:
	/* 0x5f59: cmp    WORD PTR [r13+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_5f62:
	/* 0x5f62: je     5f87 <generic_sleepable_preload+0x5f87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f87;
	}
x86_l_5f64:
	/* 0x5f64: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f69:
	/* 0x5f69: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5f6e:
	/* 0x5f6e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5f73:
	/* 0x5f73: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f78:
	/* 0x5f78: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f7d:
	/* 0x5f7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f7f:
	/* 0x5f7f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5f81:
	/* 0x5f81: js     6268 <generic_sleepable_preload+0x6268> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25192ULL;
	}
x86_l_5f87:
	/* 0x5f87: cmp    WORD PTR [r13+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_5f90:
	/* 0x5f90: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_5f96:
	/* 0x5f96: mov    ecx,DWORD PTR [r13+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_5f9d:
	/* 0x5f9d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5fa2:
	/* 0x5fa2: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5fa7:
	/* 0x5fa7: cmp    WORD PTR [r13+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_5fb0:
	/* 0x5fb0: je     5fd5 <generic_sleepable_preload+0x5fd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5fd5;
	}
x86_l_5fb2:
	/* 0x5fb2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5fb7:
	/* 0x5fb7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5fbc:
	/* 0x5fbc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5fc1:
	/* 0x5fc1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5fc6:
	/* 0x5fc6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5fcb:
	/* 0x5fcb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fcd:
	/* 0x5fcd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5fcf:
	/* 0x5fcf: js     67fc <generic_sleepable_preload+0x67fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26620ULL;
	}
x86_l_5fd5:
	/* 0x5fd5: cmp    WORD PTR [r13+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5fde:
	/* 0x5fde: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_5fe4:
	/* 0x5fe4: mov    ecx,DWORD PTR [r13+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5feb:
	/* 0x5feb: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5ff0:
	/* 0x5ff0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ff5:
	/* 0x5ff5: cmp    WORD PTR [r13+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_5ffe:
	/* 0x5ffe: je     6023 <generic_sleepable_preload+0x6023> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6023;
	}
x86_l_6000:
	/* 0x6000: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6005:
	/* 0x6005: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_600a:
	/* 0x600a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_600f:
	/* 0x600f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6014:
	/* 0x6014: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6019:
	/* 0x6019: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_601b:
	/* 0x601b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_601d:
	/* 0x601d: js     68ac <generic_sleepable_preload+0x68ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 26796ULL;
	}
x86_l_6023:
	/* 0x6023: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6028:
	/* 0x6028: cmp    WORD PTR [rax+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_6030:
	/* 0x6030: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_6036:
	/* 0x6036: mov    ecx,DWORD PTR [rax+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_603c:
	/* 0x603c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6041:
	/* 0x6041: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6046:
	/* 0x6046: cmp    WORD PTR [rax+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_604e:
	/* 0x604e: je     6073 <generic_sleepable_preload+0x6073> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6073;
	}
x86_l_6050:
	/* 0x6050: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6055:
	/* 0x6055: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_605a:
	/* 0x605a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_605f:
	/* 0x605f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6064:
	/* 0x6064: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6069:
	/* 0x6069: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_606b:
	/* 0x606b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_606d:
	/* 0x606d: js     69b5 <generic_sleepable_preload+0x69b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 27061ULL;
	}
x86_l_6073:
	/* 0x6073: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6078:
	/* 0x6078: cmp    WORD PTR [rax+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_6080:
	/* 0x6080: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_6086:
	/* 0x6086: mov    ecx,DWORD PTR [rax+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_608c:
	/* 0x608c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6091:
	/* 0x6091: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6096:
	/* 0x6096: cmp    WORD PTR [rax+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_609e:
	/* 0x609e: je     6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26628ULL;
	}
x86_l_60a4:
	/* 0x60a4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60a9:
	/* 0x60a9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_60ae:
	/* 0x60ae: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_60b3:
	/* 0x60b3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60b8:
	/* 0x60b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60bd:
	/* 0x60bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60bf:
	/* 0x60bf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_60c1:
	/* 0x60c1: jns    6804 <generic_sleepable_preload+0x6804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 26628ULL;
	}
x86_l_60c7:
	/* 0x60c7: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_60cc:
	/* 0x60cc: jmp    6801 <generic_sleepable_preload+0x6801> */
	return 26625ULL;
x86_l_60d1:
	/* 0x60d1: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_60d6:
	/* 0x60d6: jmp    6801 <generic_sleepable_preload+0x6801> */
	return 26625ULL;
x86_l_60db:
	/* 0x60db: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_60e0:
	/* 0x60e0: jmp    6801 <generic_sleepable_preload+0x6801> */
	return 26625ULL;
x86_l_60e5:
	/* 0x60e5: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_60ea:
	/* 0x60ea: jmp    6277 <generic_sleepable_preload+0x6277> */
	return 25207ULL;
x86_l_60ef:
	/* 0x60ef: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_60f4:
	/* 0x60f4: jmp    6304 <generic_sleepable_preload+0x6304> */
	return 25348ULL;
x86_l_60f9:
	/* 0x60f9: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_60fe:
	/* 0x60fe: jmp    6391 <generic_sleepable_preload+0x6391> */
	return 25489ULL;
	return 24835ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 24835ULL: goto x86_l_6103;
	case 24840ULL: goto x86_l_6108;
	case 24845ULL: goto x86_l_610d;
	case 24850ULL: goto x86_l_6112;
	case 24855ULL: goto x86_l_6117;
	case 24860ULL: goto x86_l_611c;
	case 24865ULL: goto x86_l_6121;
	case 24870ULL: goto x86_l_6126;
	case 24875ULL: goto x86_l_612b;
	case 24880ULL: goto x86_l_6130;
	case 24885ULL: goto x86_l_6135;
	case 24890ULL: goto x86_l_613a;
	case 24895ULL: goto x86_l_613f;
	case 24900ULL: goto x86_l_6144;
	case 24905ULL: goto x86_l_6149;
	case 24910ULL: goto x86_l_614e;
	case 24915ULL: goto x86_l_6153;
	case 24920ULL: goto x86_l_6158;
	case 24925ULL: goto x86_l_615d;
	case 24930ULL: goto x86_l_6162;
	case 24935ULL: goto x86_l_6167;
	case 24940ULL: goto x86_l_616c;
	case 24945ULL: goto x86_l_6171;
	case 24950ULL: goto x86_l_6176;
	case 24955ULL: goto x86_l_617b;
	case 24960ULL: goto x86_l_6180;
	case 24965ULL: goto x86_l_6185;
	case 24970ULL: goto x86_l_618a;
	case 24975ULL: goto x86_l_618f;
	case 24980ULL: goto x86_l_6194;
	case 24985ULL: goto x86_l_6199;
	case 24990ULL: goto x86_l_619e;
	case 24995ULL: goto x86_l_61a3;
	case 25000ULL: goto x86_l_61a8;
	case 25005ULL: goto x86_l_61ad;
	case 25010ULL: goto x86_l_61b2;
	case 25015ULL: goto x86_l_61b7;
	case 25020ULL: goto x86_l_61bc;
	case 25025ULL: goto x86_l_61c1;
	case 25030ULL: goto x86_l_61c6;
	case 25035ULL: goto x86_l_61cb;
	case 25040ULL: goto x86_l_61d0;
	case 25045ULL: goto x86_l_61d5;
	case 25050ULL: goto x86_l_61da;
	case 25055ULL: goto x86_l_61df;
	case 25060ULL: goto x86_l_61e4;
	case 25065ULL: goto x86_l_61e9;
	case 25070ULL: goto x86_l_61ee;
	case 25075ULL: goto x86_l_61f3;
	case 25080ULL: goto x86_l_61f8;
	case 25085ULL: goto x86_l_61fd;
	case 25090ULL: goto x86_l_6202;
	case 25095ULL: goto x86_l_6207;
	case 25100ULL: goto x86_l_620c;
	case 25105ULL: goto x86_l_6211;
	case 25110ULL: goto x86_l_6216;
	case 25112ULL: goto x86_l_6218;
	case 25117ULL: goto x86_l_621d;
	case 25122ULL: goto x86_l_6222;
	case 25127ULL: goto x86_l_6227;
	case 25132ULL: goto x86_l_622c;
	case 25137ULL: goto x86_l_6231;
	case 25142ULL: goto x86_l_6236;
	case 25147ULL: goto x86_l_623b;
	case 25152ULL: goto x86_l_6240;
	case 25157ULL: goto x86_l_6245;
	case 25162ULL: goto x86_l_624a;
	case 25167ULL: goto x86_l_624f;
	case 25172ULL: goto x86_l_6254;
	case 25177ULL: goto x86_l_6259;
	case 25182ULL: goto x86_l_625e;
	case 25187ULL: goto x86_l_6263;
	case 25192ULL: goto x86_l_6268;
	case 25197ULL: goto x86_l_626d;
	case 25202ULL: goto x86_l_6272;
	case 25207ULL: goto x86_l_6277;
	case 25209ULL: goto x86_l_6279;
	case 25213ULL: goto x86_l_627d;
	case 25218ULL: goto x86_l_6282;
	case 25223ULL: goto x86_l_6287;
	case 25228ULL: goto x86_l_628c;
	case 25233ULL: goto x86_l_6291;
	case 25236ULL: goto x86_l_6294;
	case 25238ULL: goto x86_l_6296;
	case 25242ULL: goto x86_l_629a;
	case 25248ULL: goto x86_l_62a0;
	case 25253ULL: goto x86_l_62a5;
	case 25258ULL: goto x86_l_62aa;
	case 25260ULL: goto x86_l_62ac;
	case 25265ULL: goto x86_l_62b1;
	case 25273ULL: goto x86_l_62b9;
	case 25280ULL: goto x86_l_62c0;
	case 25285ULL: goto x86_l_62c5;
	case 25290ULL: goto x86_l_62ca;
	case 25292ULL: goto x86_l_62cc;
	case 25295ULL: goto x86_l_62cf;
	case 25301ULL: goto x86_l_62d5;
	case 25304ULL: goto x86_l_62d8;
	case 25311ULL: goto x86_l_62df;
	case 25313ULL: goto x86_l_62e1;
	case 25318ULL: goto x86_l_62e6;
	case 25323ULL: goto x86_l_62eb;
	case 25326ULL: goto x86_l_62ee;
	case 25329ULL: goto x86_l_62f1;
	case 25331ULL: goto x86_l_62f3;
	case 25333ULL: goto x86_l_62f5;
	case 25338ULL: goto x86_l_62fa;
	case 25343ULL: goto x86_l_62ff;
	case 25348ULL: goto x86_l_6304;
	case 25350ULL: goto x86_l_6306;
	case 25354ULL: goto x86_l_630a;
	case 25359ULL: goto x86_l_630f;
	case 25364ULL: goto x86_l_6314;
	case 25369ULL: goto x86_l_6319;
	case 25374ULL: goto x86_l_631e;
	case 25377ULL: goto x86_l_6321;
	case 25379ULL: goto x86_l_6323;
	case 25383ULL: goto x86_l_6327;
	case 25389ULL: goto x86_l_632d;
	case 25394ULL: goto x86_l_6332;
	case 25399ULL: goto x86_l_6337;
	case 25401ULL: goto x86_l_6339;
	case 25406ULL: goto x86_l_633e;
	case 25414ULL: goto x86_l_6346;
	case 25421ULL: goto x86_l_634d;
	case 25426ULL: goto x86_l_6352;
	case 25431ULL: goto x86_l_6357;
	case 25433ULL: goto x86_l_6359;
	case 25436ULL: goto x86_l_635c;
	case 25442ULL: goto x86_l_6362;
	case 25445ULL: goto x86_l_6365;
	case 25452ULL: goto x86_l_636c;
	case 25454ULL: goto x86_l_636e;
	case 25459ULL: goto x86_l_6373;
	case 25464ULL: goto x86_l_6378;
	case 25467ULL: goto x86_l_637b;
	case 25470ULL: goto x86_l_637e;
	case 25472ULL: goto x86_l_6380;
	case 25474ULL: goto x86_l_6382;
	case 25479ULL: goto x86_l_6387;
	case 25484ULL: goto x86_l_638c;
	case 25489ULL: goto x86_l_6391;
	case 25491ULL: goto x86_l_6393;
	case 25495ULL: goto x86_l_6397;
	case 25500ULL: goto x86_l_639c;
	case 25505ULL: goto x86_l_63a1;
	case 25510ULL: goto x86_l_63a6;
	case 25515ULL: goto x86_l_63ab;
	case 25518ULL: goto x86_l_63ae;
	case 25520ULL: goto x86_l_63b0;
	case 25524ULL: goto x86_l_63b4;
	case 25530ULL: goto x86_l_63ba;
	case 25535ULL: goto x86_l_63bf;
	case 25540ULL: goto x86_l_63c4;
	case 25542ULL: goto x86_l_63c6;
	case 25547ULL: goto x86_l_63cb;
	case 25555ULL: goto x86_l_63d3;
	case 25562ULL: goto x86_l_63da;
	case 25567ULL: goto x86_l_63df;
	case 25572ULL: goto x86_l_63e4;
	case 25574ULL: goto x86_l_63e6;
	case 25577ULL: goto x86_l_63e9;
	case 25583ULL: goto x86_l_63ef;
	case 25586ULL: goto x86_l_63f2;
	case 25593ULL: goto x86_l_63f9;
	case 25595ULL: goto x86_l_63fb;
	case 25600ULL: goto x86_l_6400;
	case 25605ULL: goto x86_l_6405;
	case 25608ULL: goto x86_l_6408;
	case 25611ULL: goto x86_l_640b;
	case 25613ULL: goto x86_l_640d;
	case 25615ULL: goto x86_l_640f;
	case 25620ULL: goto x86_l_6414;
	case 25625ULL: goto x86_l_6419;
	case 25630ULL: goto x86_l_641e;
	case 25632ULL: goto x86_l_6420;
	case 25636ULL: goto x86_l_6424;
	case 25641ULL: goto x86_l_6429;
	case 25646ULL: goto x86_l_642e;
	case 25651ULL: goto x86_l_6433;
	case 25656ULL: goto x86_l_6438;
	case 25659ULL: goto x86_l_643b;
	case 25661ULL: goto x86_l_643d;
	case 25665ULL: goto x86_l_6441;
	case 25671ULL: goto x86_l_6447;
	case 25676ULL: goto x86_l_644c;
	case 25681ULL: goto x86_l_6451;
	case 25683ULL: goto x86_l_6453;
	case 25688ULL: goto x86_l_6458;
	case 25696ULL: goto x86_l_6460;
	case 25703ULL: goto x86_l_6467;
	case 25708ULL: goto x86_l_646c;
	case 25713ULL: goto x86_l_6471;
	case 25715ULL: goto x86_l_6473;
	case 25718ULL: goto x86_l_6476;
	case 25724ULL: goto x86_l_647c;
	case 25727ULL: goto x86_l_647f;
	case 25734ULL: goto x86_l_6486;
	case 25736ULL: goto x86_l_6488;
	case 25741ULL: goto x86_l_648d;
	case 25746ULL: goto x86_l_6492;
	case 25749ULL: goto x86_l_6495;
	case 25752ULL: goto x86_l_6498;
	case 25754ULL: goto x86_l_649a;
	case 25756ULL: goto x86_l_649c;
	case 25761ULL: goto x86_l_64a1;
	case 25766ULL: goto x86_l_64a6;
	case 25771ULL: goto x86_l_64ab;
	case 25774ULL: goto x86_l_64ae;
	case 25778ULL: goto x86_l_64b2;
	case 25783ULL: goto x86_l_64b7;
	case 25788ULL: goto x86_l_64bc;
	case 25793ULL: goto x86_l_64c1;
	case 25798ULL: goto x86_l_64c6;
	case 25801ULL: goto x86_l_64c9;
	case 25803ULL: goto x86_l_64cb;
	case 25806ULL: goto x86_l_64ce;
	case 25812ULL: goto x86_l_64d4;
	case 25817ULL: goto x86_l_64d9;
	case 25822ULL: goto x86_l_64de;
	case 25824ULL: goto x86_l_64e0;
	case 25829ULL: goto x86_l_64e5;
	case 25837ULL: goto x86_l_64ed;
	case 25844ULL: goto x86_l_64f4;
	case 25849ULL: goto x86_l_64f9;
	case 25854ULL: goto x86_l_64fe;
	case 25856ULL: goto x86_l_6500;
	case 25859ULL: goto x86_l_6503;
	case 25865ULL: goto x86_l_6509;
	case 25868ULL: goto x86_l_650c;
	case 25875ULL: goto x86_l_6513;
	case 25877ULL: goto x86_l_6515;
	case 25882ULL: goto x86_l_651a;
	case 25887ULL: goto x86_l_651f;
	case 25890ULL: goto x86_l_6522;
	case 25893ULL: goto x86_l_6525;
	case 25895ULL: goto x86_l_6527;
	case 25897ULL: goto x86_l_6529;
	case 25902ULL: goto x86_l_652e;
	case 25907ULL: goto x86_l_6533;
	case 25912ULL: goto x86_l_6538;
	case 25914ULL: goto x86_l_653a;
	case 25918ULL: goto x86_l_653e;
	case 25924ULL: goto x86_l_6544;
	case 25929ULL: goto x86_l_6549;
	case 25934ULL: goto x86_l_654e;
	case 25936ULL: goto x86_l_6550;
	case 25941ULL: goto x86_l_6555;
	case 25949ULL: goto x86_l_655d;
	case 25956ULL: goto x86_l_6564;
	case 25961ULL: goto x86_l_6569;
	case 25966ULL: goto x86_l_656e;
	case 25968ULL: goto x86_l_6570;
	case 25971ULL: goto x86_l_6573;
	case 25977ULL: goto x86_l_6579;
	case 25980ULL: goto x86_l_657c;
	case 25987ULL: goto x86_l_6583;
	case 25989ULL: goto x86_l_6585;
	case 25994ULL: goto x86_l_658a;
	case 25999ULL: goto x86_l_658f;
	case 26002ULL: goto x86_l_6592;
	case 26005ULL: goto x86_l_6595;
	case 26007ULL: goto x86_l_6597;
	case 26009ULL: goto x86_l_6599;
	case 26014ULL: goto x86_l_659e;
	case 26017ULL: goto x86_l_65a1;
	case 26022ULL: goto x86_l_65a6;
	case 26025ULL: goto x86_l_65a9;
	case 26027ULL: goto x86_l_65ab;
	case 26030ULL: goto x86_l_65ae;
	case 26036ULL: goto x86_l_65b4;
	case 26039ULL: goto x86_l_65b7;
	case 26041ULL: goto x86_l_65b9;
	case 26044ULL: goto x86_l_65bc;
	case 26048ULL: goto x86_l_65c0;
	case 26053ULL: goto x86_l_65c5;
	case 26056ULL: goto x86_l_65c8;
	case 26058ULL: goto x86_l_65ca;
	case 26061ULL: goto x86_l_65cd;
	case 26066ULL: goto x86_l_65d2;
	case 26068ULL: goto x86_l_65d4;
	case 26071ULL: goto x86_l_65d7;
	case 26073ULL: goto x86_l_65d9;
	case 26075ULL: goto x86_l_65db;
	case 26080ULL: goto x86_l_65e0;
	case 26082ULL: goto x86_l_65e2;
	case 26087ULL: goto x86_l_65e7;
	case 26092ULL: goto x86_l_65ec;
	case 26094ULL: goto x86_l_65ee;
	case 26098ULL: goto x86_l_65f2;
	case 26104ULL: goto x86_l_65f8;
	case 26109ULL: goto x86_l_65fd;
	case 26114ULL: goto x86_l_6602;
	case 26116ULL: goto x86_l_6604;
	case 26121ULL: goto x86_l_6609;
	case 26129ULL: goto x86_l_6611;
	case 26136ULL: goto x86_l_6618;
	case 26141ULL: goto x86_l_661d;
	case 26146ULL: goto x86_l_6622;
	case 26148ULL: goto x86_l_6624;
	case 26151ULL: goto x86_l_6627;
	case 26157ULL: goto x86_l_662d;
	case 26160ULL: goto x86_l_6630;
	case 26167ULL: goto x86_l_6637;
	case 26169ULL: goto x86_l_6639;
	case 26174ULL: goto x86_l_663e;
	case 26179ULL: goto x86_l_6643;
	case 26182ULL: goto x86_l_6646;
	case 26185ULL: goto x86_l_6649;
	case 26187ULL: goto x86_l_664b;
	case 26189ULL: goto x86_l_664d;
	case 26194ULL: goto x86_l_6652;
	case 26197ULL: goto x86_l_6655;
	case 26202ULL: goto x86_l_665a;
	case 26205ULL: goto x86_l_665d;
	case 26207ULL: goto x86_l_665f;
	case 26210ULL: goto x86_l_6662;
	case 26216ULL: goto x86_l_6668;
	case 26219ULL: goto x86_l_666b;
	case 26221ULL: goto x86_l_666d;
	case 26224ULL: goto x86_l_6670;
	case 26228ULL: goto x86_l_6674;
	case 26233ULL: goto x86_l_6679;
	case 26236ULL: goto x86_l_667c;
	case 26238ULL: goto x86_l_667e;
	case 26241ULL: goto x86_l_6681;
	case 26246ULL: goto x86_l_6686;
	case 26248ULL: goto x86_l_6688;
	case 26251ULL: goto x86_l_668b;
	case 26253ULL: goto x86_l_668d;
	case 26258ULL: goto x86_l_6692;
	case 26261ULL: goto x86_l_6695;
	case 26263ULL: goto x86_l_6697;
	case 26268ULL: goto x86_l_669c;
	case 26273ULL: goto x86_l_66a1;
	case 26275ULL: goto x86_l_66a3;
	case 26279ULL: goto x86_l_66a7;
	case 26285ULL: goto x86_l_66ad;
	case 26290ULL: goto x86_l_66b2;
	case 26295ULL: goto x86_l_66b7;
	case 26297ULL: goto x86_l_66b9;
	case 26302ULL: goto x86_l_66be;
	case 26310ULL: goto x86_l_66c6;
	case 26317ULL: goto x86_l_66cd;
	case 26322ULL: goto x86_l_66d2;
	case 26327ULL: goto x86_l_66d7;
	case 26329ULL: goto x86_l_66d9;
	case 26332ULL: goto x86_l_66dc;
	case 26338ULL: goto x86_l_66e2;
	case 26341ULL: goto x86_l_66e5;
	case 26348ULL: goto x86_l_66ec;
	case 26350ULL: goto x86_l_66ee;
	case 26355ULL: goto x86_l_66f3;
	case 26360ULL: goto x86_l_66f8;
	case 26363ULL: goto x86_l_66fb;
	case 26366ULL: goto x86_l_66fe;
	case 26368ULL: goto x86_l_6700;
	case 26370ULL: goto x86_l_6702;
	case 26375ULL: goto x86_l_6707;
	case 26378ULL: goto x86_l_670a;
	case 26381ULL: goto x86_l_670d;
	case 26383ULL: goto x86_l_670f;
	case 26386ULL: goto x86_l_6712;
	case 26392ULL: goto x86_l_6718;
	case 26395ULL: goto x86_l_671b;
	case 26397ULL: goto x86_l_671d;
	case 26400ULL: goto x86_l_6720;
	case 26404ULL: goto x86_l_6724;
	case 26409ULL: goto x86_l_6729;
	case 26412ULL: goto x86_l_672c;
	case 26414ULL: goto x86_l_672e;
	case 26417ULL: goto x86_l_6731;
	case 26422ULL: goto x86_l_6736;
	case 26424ULL: goto x86_l_6738;
	case 26427ULL: goto x86_l_673b;
	case 26429ULL: goto x86_l_673d;
	case 26434ULL: goto x86_l_6742;
	case 26437ULL: goto x86_l_6745;
	case 26439ULL: goto x86_l_6747;
	case 26444ULL: goto x86_l_674c;
	case 26449ULL: goto x86_l_6751;
	case 26451ULL: goto x86_l_6753;
	case 26455ULL: goto x86_l_6757;
	case 26461ULL: goto x86_l_675d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6103:
	/* 0x6103: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_6108:
	/* 0x6108: jmp    641e <generic_sleepable_preload+0x641e> */
	goto x86_l_641e;
x86_l_610d:
	/* 0x610d: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_6112:
	/* 0x6112: jmp    64ab <generic_sleepable_preload+0x64ab> */
	goto x86_l_64ab;
x86_l_6117:
	/* 0x6117: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_611c:
	/* 0x611c: jmp    6538 <generic_sleepable_preload+0x6538> */
	goto x86_l_6538;
x86_l_6121:
	/* 0x6121: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_6126:
	/* 0x6126: jmp    65ec <generic_sleepable_preload+0x65ec> */
	goto x86_l_65ec;
x86_l_612b:
	/* 0x612b: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_6130:
	/* 0x6130: jmp    66a1 <generic_sleepable_preload+0x66a1> */
	goto x86_l_66a1;
x86_l_6135:
	/* 0x6135: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_613a:
	/* 0x613a: jmp    6751 <generic_sleepable_preload+0x6751> */
	goto x86_l_6751;
x86_l_613f:
	/* 0x613f: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_6144:
	/* 0x6144: jmp    6801 <generic_sleepable_preload+0x6801> */
	return 26625ULL;
x86_l_6149:
	/* 0x6149: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_614e:
	/* 0x614e: jmp    6277 <generic_sleepable_preload+0x6277> */
	goto x86_l_6277;
x86_l_6153:
	/* 0x6153: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_6158:
	/* 0x6158: jmp    6304 <generic_sleepable_preload+0x6304> */
	goto x86_l_6304;
x86_l_615d:
	/* 0x615d: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_6162:
	/* 0x6162: jmp    6391 <generic_sleepable_preload+0x6391> */
	goto x86_l_6391;
x86_l_6167:
	/* 0x6167: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_616c:
	/* 0x616c: jmp    641e <generic_sleepable_preload+0x641e> */
	goto x86_l_641e;
x86_l_6171:
	/* 0x6171: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_6176:
	/* 0x6176: jmp    64ab <generic_sleepable_preload+0x64ab> */
	goto x86_l_64ab;
x86_l_617b:
	/* 0x617b: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_6180:
	/* 0x6180: jmp    6538 <generic_sleepable_preload+0x6538> */
	goto x86_l_6538;
x86_l_6185:
	/* 0x6185: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_618a:
	/* 0x618a: jmp    65ec <generic_sleepable_preload+0x65ec> */
	goto x86_l_65ec;
x86_l_618f:
	/* 0x618f: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_6194:
	/* 0x6194: jmp    66a1 <generic_sleepable_preload+0x66a1> */
	goto x86_l_66a1;
x86_l_6199:
	/* 0x6199: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_619e:
	/* 0x619e: jmp    6751 <generic_sleepable_preload+0x6751> */
	goto x86_l_6751;
x86_l_61a3:
	/* 0x61a3: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_61a8:
	/* 0x61a8: jmp    6801 <generic_sleepable_preload+0x6801> */
	return 26625ULL;
x86_l_61ad:
	/* 0x61ad: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61b2:
	/* 0x61b2: jmp    6277 <generic_sleepable_preload+0x6277> */
	goto x86_l_6277;
x86_l_61b7:
	/* 0x61b7: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61bc:
	/* 0x61bc: jmp    6304 <generic_sleepable_preload+0x6304> */
	goto x86_l_6304;
x86_l_61c1:
	/* 0x61c1: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61c6:
	/* 0x61c6: jmp    6391 <generic_sleepable_preload+0x6391> */
	goto x86_l_6391;
x86_l_61cb:
	/* 0x61cb: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61d0:
	/* 0x61d0: jmp    641e <generic_sleepable_preload+0x641e> */
	goto x86_l_641e;
x86_l_61d5:
	/* 0x61d5: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_61da:
	/* 0x61da: jmp    64ab <generic_sleepable_preload+0x64ab> */
	goto x86_l_64ab;
x86_l_61df:
	/* 0x61df: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61e4:
	/* 0x61e4: jmp    6538 <generic_sleepable_preload+0x6538> */
	goto x86_l_6538;
x86_l_61e9:
	/* 0x61e9: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61ee:
	/* 0x61ee: jmp    65ec <generic_sleepable_preload+0x65ec> */
	goto x86_l_65ec;
x86_l_61f3:
	/* 0x61f3: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_61f8:
	/* 0x61f8: jmp    66a1 <generic_sleepable_preload+0x66a1> */
	goto x86_l_66a1;
x86_l_61fd:
	/* 0x61fd: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_6202:
	/* 0x6202: jmp    6751 <generic_sleepable_preload+0x6751> */
	goto x86_l_6751;
x86_l_6207:
	/* 0x6207: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_620c:
	/* 0x620c: jmp    6801 <generic_sleepable_preload+0x6801> */
	return 26625ULL;
x86_l_6211:
	/* 0x6211: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6216:
	/* 0x6216: jmp    6277 <generic_sleepable_preload+0x6277> */
	goto x86_l_6277;
x86_l_6218:
	/* 0x6218: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_621d:
	/* 0x621d: jmp    6304 <generic_sleepable_preload+0x6304> */
	goto x86_l_6304;
x86_l_6222:
	/* 0x6222: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6227:
	/* 0x6227: jmp    6391 <generic_sleepable_preload+0x6391> */
	goto x86_l_6391;
x86_l_622c:
	/* 0x622c: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6231:
	/* 0x6231: jmp    641e <generic_sleepable_preload+0x641e> */
	goto x86_l_641e;
x86_l_6236:
	/* 0x6236: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_623b:
	/* 0x623b: jmp    64ab <generic_sleepable_preload+0x64ab> */
	goto x86_l_64ab;
x86_l_6240:
	/* 0x6240: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6245:
	/* 0x6245: jmp    6538 <generic_sleepable_preload+0x6538> */
	goto x86_l_6538;
x86_l_624a:
	/* 0x624a: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_624f:
	/* 0x624f: jmp    65ec <generic_sleepable_preload+0x65ec> */
	goto x86_l_65ec;
x86_l_6254:
	/* 0x6254: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6259:
	/* 0x6259: jmp    66a1 <generic_sleepable_preload+0x66a1> */
	goto x86_l_66a1;
x86_l_625e:
	/* 0x625e: mov    ebx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6263:
	/* 0x6263: jmp    6751 <generic_sleepable_preload+0x6751> */
	goto x86_l_6751;
x86_l_6268:
	/* 0x6268: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_626d:
	/* 0x626d: jmp    6801 <generic_sleepable_preload+0x6801> */
	return 26625ULL;
x86_l_6272:
	/* 0x6272: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_6277:
	/* 0x6277: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6279:
	/* 0x6279: mov    r14d,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_627d:
	/* 0x627d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6282:
	/* 0x6282: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6287:
	/* 0x6287: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_628c:
	/* 0x628c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6291:
	/* 0x6291: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_6294:
	/* 0x6294: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6296:
	/* 0x6296: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_629a:
	/* 0x629a: jne    11b5 <generic_sleepable_preload+0x11b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4533ULL;
	}
x86_l_62a0:
	/* 0x62a0: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_62a5:
	/* 0x62a5: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_62aa:
	/* 0x62aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62ac:
	/* 0x62ac: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_62b1:
	/* 0x62b1: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_62b9:
	/* 0x62b9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_62c0:
	/* 0x62c0: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_62c5:
	/* 0x62c5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_62ca:
	/* 0x62ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62cc:
	/* 0x62cc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_62cf:
	/* 0x62cf: je     11b5 <generic_sleepable_preload+0x11b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4533ULL;
	}
x86_l_62d5:
	/* 0x62d5: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_62d8:
	/* 0x62d8: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_62df:
	/* 0x62df: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_62e1:
	/* 0x62e1: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_62e6:
	/* 0x62e6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_62eb:
	/* 0x62eb: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_62ee:
	/* 0x62ee: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_62f1:
	/* 0x62f1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_62f3:
	/* 0x62f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62f5:
	/* 0x62f5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_62fa:
	/* 0x62fa: jmp    659e <generic_sleepable_preload+0x659e> */
	goto x86_l_659e;
x86_l_62ff:
	/* 0x62ff: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_6304:
	/* 0x6304: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6306:
	/* 0x6306: mov    r14d,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_630a:
	/* 0x630a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_630f:
	/* 0x630f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6314:
	/* 0x6314: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6319:
	/* 0x6319: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_631e:
	/* 0x631e: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_6321:
	/* 0x6321: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6323:
	/* 0x6323: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_6327:
	/* 0x6327: jne    11c4 <generic_sleepable_preload+0x11c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4548ULL;
	}
x86_l_632d:
	/* 0x632d: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6332:
	/* 0x6332: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6337:
	/* 0x6337: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6339:
	/* 0x6339: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_633e:
	/* 0x633e: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_6346:
	/* 0x6346: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_634d:
	/* 0x634d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6352:
	/* 0x6352: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6357:
	/* 0x6357: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6359:
	/* 0x6359: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_635c:
	/* 0x635c: je     11c4 <generic_sleepable_preload+0x11c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4548ULL;
	}
x86_l_6362:
	/* 0x6362: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6365:
	/* 0x6365: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_636c:
	/* 0x636c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_636e:
	/* 0x636e: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6373:
	/* 0x6373: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6378:
	/* 0x6378: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_637b:
	/* 0x637b: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_637e:
	/* 0x637e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6380:
	/* 0x6380: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6382:
	/* 0x6382: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6387:
	/* 0x6387: jmp    67b7 <generic_sleepable_preload+0x67b7> */
	return 26551ULL;
x86_l_638c:
	/* 0x638c: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_6391:
	/* 0x6391: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6393:
	/* 0x6393: mov    r14d,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_6397:
	/* 0x6397: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_639c:
	/* 0x639c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_63a1:
	/* 0x63a1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_63a6:
	/* 0x63a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_63ab:
	/* 0x63ab: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_63ae:
	/* 0x63ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63b0:
	/* 0x63b0: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_63b4:
	/* 0x63b4: jne    11d8 <generic_sleepable_preload+0x11d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4568ULL;
	}
x86_l_63ba:
	/* 0x63ba: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_63bf:
	/* 0x63bf: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_63c4:
	/* 0x63c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63c6:
	/* 0x63c6: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_63cb:
	/* 0x63cb: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_63d3:
	/* 0x63d3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_63da:
	/* 0x63da: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_63df:
	/* 0x63df: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_63e4:
	/* 0x63e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63e6:
	/* 0x63e6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_63e9:
	/* 0x63e9: je     11d8 <generic_sleepable_preload+0x11d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4568ULL;
	}
x86_l_63ef:
	/* 0x63ef: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_63f2:
	/* 0x63f2: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_63f9:
	/* 0x63f9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_63fb:
	/* 0x63fb: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6400:
	/* 0x6400: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6405:
	/* 0x6405: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6408:
	/* 0x6408: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_640b:
	/* 0x640b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_640d:
	/* 0x640d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_640f:
	/* 0x640f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6414:
	/* 0x6414: jmp    6652 <generic_sleepable_preload+0x6652> */
	goto x86_l_6652;
x86_l_6419:
	/* 0x6419: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_641e:
	/* 0x641e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6420:
	/* 0x6420: mov    r14d,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6424:
	/* 0x6424: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6429:
	/* 0x6429: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_642e:
	/* 0x642e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6433:
	/* 0x6433: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6438:
	/* 0x6438: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_643b:
	/* 0x643b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_643d:
	/* 0x643d: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_6441:
	/* 0x6441: jne    11e7 <generic_sleepable_preload+0x11e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4583ULL;
	}
x86_l_6447:
	/* 0x6447: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_644c:
	/* 0x644c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6451:
	/* 0x6451: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6453:
	/* 0x6453: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6458:
	/* 0x6458: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_6460:
	/* 0x6460: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_6467:
	/* 0x6467: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_646c:
	/* 0x646c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6471:
	/* 0x6471: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6473:
	/* 0x6473: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6476:
	/* 0x6476: je     11e7 <generic_sleepable_preload+0x11e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4583ULL;
	}
x86_l_647c:
	/* 0x647c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_647f:
	/* 0x647f: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_6486:
	/* 0x6486: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6488:
	/* 0x6488: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_648d:
	/* 0x648d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6492:
	/* 0x6492: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6495:
	/* 0x6495: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_6498:
	/* 0x6498: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_649a:
	/* 0x649a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_649c:
	/* 0x649c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_64a1:
	/* 0x64a1: jmp    6707 <generic_sleepable_preload+0x6707> */
	goto x86_l_6707;
x86_l_64a6:
	/* 0x64a6: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_64ab:
	/* 0x64ab: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_64ae:
	/* 0x64ae: mov    ebx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_64b2:
	/* 0x64b2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64b7:
	/* 0x64b7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_64bc:
	/* 0x64bc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_64c1:
	/* 0x64c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64c6:
	/* 0x64c6: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_64c9:
	/* 0x64c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64cb:
	/* 0x64cb: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_64ce:
	/* 0x64ce: jne    11f6 <generic_sleepable_preload+0x11f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4598ULL;
	}
x86_l_64d4:
	/* 0x64d4: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64d9:
	/* 0x64d9: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_64de:
	/* 0x64de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64e0:
	/* 0x64e0: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_64e5:
	/* 0x64e5: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_64ed:
	/* 0x64ed: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_64f4:
	/* 0x64f4: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_64f9:
	/* 0x64f9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_64fe:
	/* 0x64fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6500:
	/* 0x6500: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6503:
	/* 0x6503: je     11f6 <generic_sleepable_preload+0x11f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4598ULL;
	}
x86_l_6509:
	/* 0x6509: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_650c:
	/* 0x650c: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_6513:
	/* 0x6513: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6515:
	/* 0x6515: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_651a:
	/* 0x651a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_651f:
	/* 0x651f: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_6522:
	/* 0x6522: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_6525:
	/* 0x6525: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6527:
	/* 0x6527: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6529:
	/* 0x6529: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_652e:
	/* 0x652e: jmp    6867 <generic_sleepable_preload+0x6867> */
	return 26727ULL;
x86_l_6533:
	/* 0x6533: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_6538:
	/* 0x6538: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_653a:
	/* 0x653a: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_653e:
	/* 0x653e: jne    11b5 <generic_sleepable_preload+0x11b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4533ULL;
	}
x86_l_6544:
	/* 0x6544: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6549:
	/* 0x6549: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_654e:
	/* 0x654e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6550:
	/* 0x6550: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6555:
	/* 0x6555: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_655d:
	/* 0x655d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_6564:
	/* 0x6564: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6569:
	/* 0x6569: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_656e:
	/* 0x656e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6570:
	/* 0x6570: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6573:
	/* 0x6573: je     11b5 <generic_sleepable_preload+0x11b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4533ULL;
	}
x86_l_6579:
	/* 0x6579: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_657c:
	/* 0x657c: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_6583:
	/* 0x6583: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6585:
	/* 0x6585: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_658a:
	/* 0x658a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_658f:
	/* 0x658f: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6592:
	/* 0x6592: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_6595:
	/* 0x6595: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6597:
	/* 0x6597: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6599:
	/* 0x6599: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_659e:
	/* 0x659e: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_65a1:
	/* 0x65a1: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_65a6:
	/* 0x65a6: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_65a9:
	/* 0x65a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65ab:
	/* 0x65ab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_65ae:
	/* 0x65ae: je     11b5 <generic_sleepable_preload+0x11b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4533ULL;
	}
x86_l_65b4:
	/* 0x65b4: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_65b7:
	/* 0x65b7: je     65e0 <generic_sleepable_preload+0x65e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_65e0;
	}
x86_l_65b9:
	/* 0x65b9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_65bc:
	/* 0x65bc: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_65c0:
	/* 0x65c0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_65c5:
	/* 0x65c5: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_65c8:
	/* 0x65c8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_65ca:
	/* 0x65ca: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_65cd:
	/* 0x65cd: call   65d2 <generic_sleepable_preload+0x65d2> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_65d2:
	/* 0x65d2: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_65d4:
	/* 0x65d4: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_65d7:
	/* 0x65d7: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_65d9:
	/* 0x65d9: jns    65e0 <generic_sleepable_preload+0x65e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_65e0;
	}
x86_l_65db:
	/* 0x65db: mov    ebx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_65e0:
	/* 0x65e0: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_65e2:
	/* 0x65e2: jmp    11b5 <generic_sleepable_preload+0x11b5> */
	return 4533ULL;
x86_l_65e7:
	/* 0x65e7: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_65ec:
	/* 0x65ec: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_65ee:
	/* 0x65ee: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_65f2:
	/* 0x65f2: jne    11d8 <generic_sleepable_preload+0x11d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4568ULL;
	}
x86_l_65f8:
	/* 0x65f8: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_65fd:
	/* 0x65fd: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6602:
	/* 0x6602: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6604:
	/* 0x6604: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6609:
	/* 0x6609: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_6611:
	/* 0x6611: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_6618:
	/* 0x6618: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_661d:
	/* 0x661d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6622:
	/* 0x6622: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6624:
	/* 0x6624: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6627:
	/* 0x6627: je     11d8 <generic_sleepable_preload+0x11d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4568ULL;
	}
x86_l_662d:
	/* 0x662d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6630:
	/* 0x6630: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_6637:
	/* 0x6637: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6639:
	/* 0x6639: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_663e:
	/* 0x663e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6643:
	/* 0x6643: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6646:
	/* 0x6646: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_6649:
	/* 0x6649: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_664b:
	/* 0x664b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_664d:
	/* 0x664d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6652:
	/* 0x6652: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6655:
	/* 0x6655: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_665a:
	/* 0x665a: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_665d:
	/* 0x665d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_665f:
	/* 0x665f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6662:
	/* 0x6662: je     11d8 <generic_sleepable_preload+0x11d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4568ULL;
	}
x86_l_6668:
	/* 0x6668: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_666b:
	/* 0x666b: je     6695 <generic_sleepable_preload+0x6695> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6695;
	}
x86_l_666d:
	/* 0x666d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_6670:
	/* 0x6670: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_6674:
	/* 0x6674: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_6679:
	/* 0x6679: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_667c:
	/* 0x667c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_667e:
	/* 0x667e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_6681:
	/* 0x6681: call   6686 <generic_sleepable_preload+0x6686> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_6686:
	/* 0x6686: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_6688:
	/* 0x6688: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_668b:
	/* 0x668b: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_668d:
	/* 0x668d: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_6692:
	/* 0x6692: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_6695:
	/* 0x6695: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6697:
	/* 0x6697: jmp    11d8 <generic_sleepable_preload+0x11d8> */
	return 4568ULL;
x86_l_669c:
	/* 0x669c: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_66a1:
	/* 0x66a1: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_66a3:
	/* 0x66a3: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_66a7:
	/* 0x66a7: jne    11e7 <generic_sleepable_preload+0x11e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4583ULL;
	}
x86_l_66ad:
	/* 0x66ad: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_66b2:
	/* 0x66b2: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_66b7:
	/* 0x66b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66b9:
	/* 0x66b9: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_66be:
	/* 0x66be: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_66c6:
	/* 0x66c6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_66cd:
	/* 0x66cd: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_66d2:
	/* 0x66d2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_66d7:
	/* 0x66d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66d9:
	/* 0x66d9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_66dc:
	/* 0x66dc: je     11e7 <generic_sleepable_preload+0x11e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4583ULL;
	}
x86_l_66e2:
	/* 0x66e2: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_66e5:
	/* 0x66e5: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_66ec:
	/* 0x66ec: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_66ee:
	/* 0x66ee: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_66f3:
	/* 0x66f3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_66f8:
	/* 0x66f8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_66fb:
	/* 0x66fb: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_66fe:
	/* 0x66fe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6700:
	/* 0x6700: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6702:
	/* 0x6702: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6707:
	/* 0x6707: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_670a:
	/* 0x670a: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_670d:
	/* 0x670d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_670f:
	/* 0x670f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6712:
	/* 0x6712: je     11e7 <generic_sleepable_preload+0x11e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4583ULL;
	}
x86_l_6718:
	/* 0x6718: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_671b:
	/* 0x671b: je     6745 <generic_sleepable_preload+0x6745> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6745;
	}
x86_l_671d:
	/* 0x671d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_6720:
	/* 0x6720: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_6724:
	/* 0x6724: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_6729:
	/* 0x6729: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_672c:
	/* 0x672c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_672e:
	/* 0x672e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_6731:
	/* 0x6731: call   6736 <generic_sleepable_preload+0x6736> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_6736:
	/* 0x6736: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_6738:
	/* 0x6738: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_673b:
	/* 0x673b: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_673d:
	/* 0x673d: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_6742:
	/* 0x6742: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_6745:
	/* 0x6745: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6747:
	/* 0x6747: jmp    11e7 <generic_sleepable_preload+0x11e7> */
	return 4583ULL;
x86_l_674c:
	/* 0x674c: mov    ebx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 7ULL);
x86_l_6751:
	/* 0x6751: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6753:
	/* 0x6753: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_6757:
	/* 0x6757: jne    11c4 <generic_sleepable_preload+0x11c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4548ULL;
	}
x86_l_675d:
	/* 0x675d: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 26466ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_14(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 26466ULL: goto x86_l_6762;
	case 26471ULL: goto x86_l_6767;
	case 26473ULL: goto x86_l_6769;
	case 26478ULL: goto x86_l_676e;
	case 26486ULL: goto x86_l_6776;
	case 26493ULL: goto x86_l_677d;
	case 26498ULL: goto x86_l_6782;
	case 26503ULL: goto x86_l_6787;
	case 26505ULL: goto x86_l_6789;
	case 26508ULL: goto x86_l_678c;
	case 26514ULL: goto x86_l_6792;
	case 26517ULL: goto x86_l_6795;
	case 26524ULL: goto x86_l_679c;
	case 26526ULL: goto x86_l_679e;
	case 26531ULL: goto x86_l_67a3;
	case 26536ULL: goto x86_l_67a8;
	case 26539ULL: goto x86_l_67ab;
	case 26542ULL: goto x86_l_67ae;
	case 26544ULL: goto x86_l_67b0;
	case 26546ULL: goto x86_l_67b2;
	case 26551ULL: goto x86_l_67b7;
	case 26554ULL: goto x86_l_67ba;
	case 26557ULL: goto x86_l_67bd;
	case 26559ULL: goto x86_l_67bf;
	case 26562ULL: goto x86_l_67c2;
	case 26568ULL: goto x86_l_67c8;
	case 26571ULL: goto x86_l_67cb;
	case 26573ULL: goto x86_l_67cd;
	case 26576ULL: goto x86_l_67d0;
	case 26580ULL: goto x86_l_67d4;
	case 26585ULL: goto x86_l_67d9;
	case 26588ULL: goto x86_l_67dc;
	case 26590ULL: goto x86_l_67de;
	case 26593ULL: goto x86_l_67e1;
	case 26598ULL: goto x86_l_67e6;
	case 26600ULL: goto x86_l_67e8;
	case 26603ULL: goto x86_l_67eb;
	case 26605ULL: goto x86_l_67ed;
	case 26610ULL: goto x86_l_67f2;
	case 26613ULL: goto x86_l_67f5;
	case 26615ULL: goto x86_l_67f7;
	case 26620ULL: goto x86_l_67fc;
	case 26625ULL: goto x86_l_6801;
	case 26628ULL: goto x86_l_6804;
	case 26631ULL: goto x86_l_6807;
	case 26637ULL: goto x86_l_680d;
	case 26642ULL: goto x86_l_6812;
	case 26647ULL: goto x86_l_6817;
	case 26649ULL: goto x86_l_6819;
	case 26654ULL: goto x86_l_681e;
	case 26662ULL: goto x86_l_6826;
	case 26669ULL: goto x86_l_682d;
	case 26674ULL: goto x86_l_6832;
	case 26679ULL: goto x86_l_6837;
	case 26681ULL: goto x86_l_6839;
	case 26684ULL: goto x86_l_683c;
	case 26690ULL: goto x86_l_6842;
	case 26693ULL: goto x86_l_6845;
	case 26700ULL: goto x86_l_684c;
	case 26702ULL: goto x86_l_684e;
	case 26707ULL: goto x86_l_6853;
	case 26712ULL: goto x86_l_6858;
	case 26715ULL: goto x86_l_685b;
	case 26718ULL: goto x86_l_685e;
	case 26720ULL: goto x86_l_6860;
	case 26722ULL: goto x86_l_6862;
	case 26727ULL: goto x86_l_6867;
	case 26730ULL: goto x86_l_686a;
	case 26733ULL: goto x86_l_686d;
	case 26735ULL: goto x86_l_686f;
	case 26738ULL: goto x86_l_6872;
	case 26744ULL: goto x86_l_6878;
	case 26747ULL: goto x86_l_687b;
	case 26749ULL: goto x86_l_687d;
	case 26752ULL: goto x86_l_6880;
	case 26756ULL: goto x86_l_6884;
	case 26761ULL: goto x86_l_6889;
	case 26764ULL: goto x86_l_688c;
	case 26766ULL: goto x86_l_688e;
	case 26769ULL: goto x86_l_6891;
	case 26774ULL: goto x86_l_6896;
	case 26776ULL: goto x86_l_6898;
	case 26779ULL: goto x86_l_689b;
	case 26781ULL: goto x86_l_689d;
	case 26786ULL: goto x86_l_68a2;
	case 26789ULL: goto x86_l_68a5;
	case 26791ULL: goto x86_l_68a7;
	case 26796ULL: goto x86_l_68ac;
	case 26799ULL: goto x86_l_68af;
	case 26804ULL: goto x86_l_68b4;
	case 26807ULL: goto x86_l_68b7;
	case 26813ULL: goto x86_l_68bd;
	case 26818ULL: goto x86_l_68c2;
	case 26820ULL: goto x86_l_68c4;
	case 26825ULL: goto x86_l_68c9;
	case 26830ULL: goto x86_l_68ce;
	case 26832ULL: goto x86_l_68d0;
	case 26837ULL: goto x86_l_68d5;
	case 26842ULL: goto x86_l_68da;
	case 26844ULL: goto x86_l_68dc;
	case 26849ULL: goto x86_l_68e1;
	case 26854ULL: goto x86_l_68e6;
	case 26856ULL: goto x86_l_68e8;
	case 26861ULL: goto x86_l_68ed;
	case 26866ULL: goto x86_l_68f2;
	case 26869ULL: goto x86_l_68f5;
	case 26874ULL: goto x86_l_68fa;
	case 26879ULL: goto x86_l_68ff;
	case 26881ULL: goto x86_l_6901;
	case 26886ULL: goto x86_l_6906;
	case 26891ULL: goto x86_l_690b;
	case 26893ULL: goto x86_l_690d;
	case 26898ULL: goto x86_l_6912;
	case 26903ULL: goto x86_l_6917;
	case 26905ULL: goto x86_l_6919;
	case 26910ULL: goto x86_l_691e;
	case 26915ULL: goto x86_l_6923;
	case 26917ULL: goto x86_l_6925;
	case 26922ULL: goto x86_l_692a;
	case 26927ULL: goto x86_l_692f;
	case 26932ULL: goto x86_l_6934;
	case 26934ULL: goto x86_l_6936;
	case 26939ULL: goto x86_l_693b;
	case 26944ULL: goto x86_l_6940;
	case 26946ULL: goto x86_l_6942;
	case 26951ULL: goto x86_l_6947;
	case 26956ULL: goto x86_l_694c;
	case 26961ULL: goto x86_l_6951;
	case 26963ULL: goto x86_l_6953;
	case 26968ULL: goto x86_l_6958;
	case 26973ULL: goto x86_l_695d;
	case 26975ULL: goto x86_l_695f;
	case 26980ULL: goto x86_l_6964;
	case 26985ULL: goto x86_l_6969;
	case 26990ULL: goto x86_l_696e;
	case 26993ULL: goto x86_l_6971;
	case 26998ULL: goto x86_l_6976;
	case 27003ULL: goto x86_l_697b;
	case 27008ULL: goto x86_l_6980;
	case 27010ULL: goto x86_l_6982;
	case 27015ULL: goto x86_l_6987;
	case 27020ULL: goto x86_l_698c;
	case 27022ULL: goto x86_l_698e;
	case 27027ULL: goto x86_l_6993;
	case 27032ULL: goto x86_l_6998;
	case 27034ULL: goto x86_l_699a;
	case 27039ULL: goto x86_l_699f;
	case 27044ULL: goto x86_l_69a4;
	case 27049ULL: goto x86_l_69a9;
	case 27051ULL: goto x86_l_69ab;
	case 27056ULL: goto x86_l_69b0;
	case 27061ULL: goto x86_l_69b5;
	case 27066ULL: goto x86_l_69ba;
	case 27071ULL: goto x86_l_69bf;
	case 27073ULL: goto x86_l_69c1;
	case 27078ULL: goto x86_l_69c6;
	case 27083ULL: goto x86_l_69cb;
	case 27088ULL: goto x86_l_69d0;
	case 27093ULL: goto x86_l_69d5;
	case 27095ULL: goto x86_l_69d7;
	case 27100ULL: goto x86_l_69dc;
	case 27105ULL: goto x86_l_69e1;
	case 27110ULL: goto x86_l_69e6;
	case 27112ULL: goto x86_l_69e8;
	case 27117ULL: goto x86_l_69ed;
	case 27122ULL: goto x86_l_69f2;
	case 27127ULL: goto x86_l_69f7;
	case 27132ULL: goto x86_l_69fc;
	case 27134ULL: goto x86_l_69fe;
	case 27139ULL: goto x86_l_6a03;
	case 27144ULL: goto x86_l_6a08;
	case 27149ULL: goto x86_l_6a0d;
	case 27152ULL: goto x86_l_6a10;
	case 27157ULL: goto x86_l_6a15;
	case 27162ULL: goto x86_l_6a1a;
	case 27167ULL: goto x86_l_6a1f;
	case 27169ULL: goto x86_l_6a21;
	case 27174ULL: goto x86_l_6a26;
	case 27179ULL: goto x86_l_6a2b;
	case 27184ULL: goto x86_l_6a30;
	case 27189ULL: goto x86_l_6a35;
	case 27191ULL: goto x86_l_6a37;
	case 27196ULL: goto x86_l_6a3c;
	case 27201ULL: goto x86_l_6a41;
	case 27206ULL: goto x86_l_6a46;
	case 27211ULL: goto x86_l_6a4b;
	case 27213ULL: goto x86_l_6a4d;
	case 27218ULL: goto x86_l_6a52;
	case 27223ULL: goto x86_l_6a57;
	case 27228ULL: goto x86_l_6a5c;
	case 27230ULL: goto x86_l_6a5e;
	case 27235ULL: goto x86_l_6a63;
	case 27240ULL: goto x86_l_6a68;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6762:
	/* 0x6762: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6767:
	/* 0x6767: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6769:
	/* 0x6769: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_676e:
	/* 0x676e: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_6776:
	/* 0x6776: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_677d:
	/* 0x677d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6782:
	/* 0x6782: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6787:
	/* 0x6787: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6789:
	/* 0x6789: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_678c:
	/* 0x678c: je     11c4 <generic_sleepable_preload+0x11c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4548ULL;
	}
x86_l_6792:
	/* 0x6792: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6795:
	/* 0x6795: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_679c:
	/* 0x679c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_679e:
	/* 0x679e: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_67a3:
	/* 0x67a3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_67a8:
	/* 0x67a8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_67ab:
	/* 0x67ab: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_67ae:
	/* 0x67ae: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67b0:
	/* 0x67b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67b2:
	/* 0x67b2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_67b7:
	/* 0x67b7: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_67ba:
	/* 0x67ba: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_67bd:
	/* 0x67bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67bf:
	/* 0x67bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_67c2:
	/* 0x67c2: je     11c4 <generic_sleepable_preload+0x11c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4548ULL;
	}
x86_l_67c8:
	/* 0x67c8: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_67cb:
	/* 0x67cb: je     67f5 <generic_sleepable_preload+0x67f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_67f5;
	}
x86_l_67cd:
	/* 0x67cd: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_67d0:
	/* 0x67d0: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_67d4:
	/* 0x67d4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_67d9:
	/* 0x67d9: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_67dc:
	/* 0x67dc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67de:
	/* 0x67de: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_67e1:
	/* 0x67e1: call   67e6 <generic_sleepable_preload+0x67e6> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_67e6:
	/* 0x67e6: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_67e8:
	/* 0x67e8: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_67eb:
	/* 0x67eb: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_67ed:
	/* 0x67ed: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_67f2:
	/* 0x67f2: cmovs  ebx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_67f5:
	/* 0x67f5: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67f7:
	/* 0x67f7: jmp    11c4 <generic_sleepable_preload+0x11c4> */
	return 4548ULL;
x86_l_67fc:
	/* 0x67fc: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_6801:
	/* 0x6801: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6804:
	/* 0x6804: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_6807:
	/* 0x6807: jne    11f6 <generic_sleepable_preload+0x11f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4598ULL;
	}
x86_l_680d:
	/* 0x680d: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6812:
	/* 0x6812: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6817:
	/* 0x6817: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6819:
	/* 0x6819: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_681e:
	/* 0x681e: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_6826:
	/* 0x6826: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_682d:
	/* 0x682d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6832:
	/* 0x6832: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6837:
	/* 0x6837: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6839:
	/* 0x6839: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_683c:
	/* 0x683c: je     11f6 <generic_sleepable_preload+0x11f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4598ULL;
	}
x86_l_6842:
	/* 0x6842: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6845:
	/* 0x6845: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_684c:
	/* 0x684c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_684e:
	/* 0x684e: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6853:
	/* 0x6853: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6858:
	/* 0x6858: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_685b:
	/* 0x685b: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_685e:
	/* 0x685e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6860:
	/* 0x6860: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6862:
	/* 0x6862: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6867:
	/* 0x6867: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_686a:
	/* 0x686a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_686d:
	/* 0x686d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_686f:
	/* 0x686f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6872:
	/* 0x6872: je     11f6 <generic_sleepable_preload+0x11f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4598ULL;
	}
x86_l_6878:
	/* 0x6878: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_687b:
	/* 0x687b: je     68a5 <generic_sleepable_preload+0x68a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_68a5;
	}
x86_l_687d:
	/* 0x687d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_6880:
	/* 0x6880: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_6884:
	/* 0x6884: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_6889:
	/* 0x6889: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_688c:
	/* 0x688c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_688e:
	/* 0x688e: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_6891:
	/* 0x6891: call   6896 <generic_sleepable_preload+0x6896> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_6896:
	/* 0x6896: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_6898:
	/* 0x6898: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_689b:
	/* 0x689b: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_689d:
	/* 0x689d: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_68a2:
	/* 0x68a2: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_68a5:
	/* 0x68a5: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_68a7:
	/* 0x68a7: jmp    11f6 <generic_sleepable_preload+0x11f6> */
	return 4598ULL;
x86_l_68ac:
	/* 0x68ac: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68af:
	/* 0x68af: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_68b4:
	/* 0x68b4: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_68b7:
	/* 0x68b7: jne    11f6 <generic_sleepable_preload+0x11f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4598ULL;
	}
x86_l_68bd:
	/* 0x68bd: jmp    680d <generic_sleepable_preload+0x680d> */
	goto x86_l_680d;
x86_l_68c2:
	/* 0x68c2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68c4:
	/* 0x68c4: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_68c9:
	/* 0x68c9: jmp    6279 <generic_sleepable_preload+0x6279> */
	return 25209ULL;
x86_l_68ce:
	/* 0x68ce: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68d0:
	/* 0x68d0: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_68d5:
	/* 0x68d5: jmp    6306 <generic_sleepable_preload+0x6306> */
	return 25350ULL;
x86_l_68da:
	/* 0x68da: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68dc:
	/* 0x68dc: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_68e1:
	/* 0x68e1: jmp    6393 <generic_sleepable_preload+0x6393> */
	return 25491ULL;
x86_l_68e6:
	/* 0x68e6: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68e8:
	/* 0x68e8: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_68ed:
	/* 0x68ed: jmp    6420 <generic_sleepable_preload+0x6420> */
	return 25632ULL;
x86_l_68f2:
	/* 0x68f2: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68f5:
	/* 0x68f5: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_68fa:
	/* 0x68fa: jmp    64ae <generic_sleepable_preload+0x64ae> */
	return 25774ULL;
x86_l_68ff:
	/* 0x68ff: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6901:
	/* 0x6901: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6906:
	/* 0x6906: jmp    653a <generic_sleepable_preload+0x653a> */
	return 25914ULL;
x86_l_690b:
	/* 0x690b: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_690d:
	/* 0x690d: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6912:
	/* 0x6912: jmp    65ee <generic_sleepable_preload+0x65ee> */
	return 26094ULL;
x86_l_6917:
	/* 0x6917: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6919:
	/* 0x6919: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_691e:
	/* 0x691e: jmp    66a3 <generic_sleepable_preload+0x66a3> */
	return 26275ULL;
x86_l_6923:
	/* 0x6923: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6925:
	/* 0x6925: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_692a:
	/* 0x692a: jmp    6753 <generic_sleepable_preload+0x6753> */
	return 26451ULL;
x86_l_692f:
	/* 0x692f: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_6934:
	/* 0x6934: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6936:
	/* 0x6936: jmp    69c6 <generic_sleepable_preload+0x69c6> */
	goto x86_l_69c6;
x86_l_693b:
	/* 0x693b: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_6940:
	/* 0x6940: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6942:
	/* 0x6942: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6947:
	/* 0x6947: jmp    6306 <generic_sleepable_preload+0x6306> */
	return 25350ULL;
x86_l_694c:
	/* 0x694c: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_6951:
	/* 0x6951: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6953:
	/* 0x6953: jmp    69ed <generic_sleepable_preload+0x69ed> */
	goto x86_l_69ed;
x86_l_6958:
	/* 0x6958: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_695d:
	/* 0x695d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_695f:
	/* 0x695f: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6964:
	/* 0x6964: jmp    6420 <generic_sleepable_preload+0x6420> */
	return 25632ULL;
x86_l_6969:
	/* 0x6969: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_696e:
	/* 0x696e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6971:
	/* 0x6971: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6976:
	/* 0x6976: jmp    64ae <generic_sleepable_preload+0x64ae> */
	return 25774ULL;
x86_l_697b:
	/* 0x697b: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_6980:
	/* 0x6980: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6982:
	/* 0x6982: jmp    6a26 <generic_sleepable_preload+0x6a26> */
	goto x86_l_6a26;
x86_l_6987:
	/* 0x6987: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_698c:
	/* 0x698c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_698e:
	/* 0x698e: jmp    6a3c <generic_sleepable_preload+0x6a3c> */
	goto x86_l_6a3c;
x86_l_6993:
	/* 0x6993: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_6998:
	/* 0x6998: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_699a:
	/* 0x699a: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_699f:
	/* 0x699f: jmp    66a3 <generic_sleepable_preload+0x66a3> */
	return 26275ULL;
x86_l_69a4:
	/* 0x69a4: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_69a9:
	/* 0x69a9: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69ab:
	/* 0x69ab: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69b0:
	/* 0x69b0: jmp    6753 <generic_sleepable_preload+0x6753> */
	return 26451ULL;
x86_l_69b5:
	/* 0x69b5: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_69ba:
	/* 0x69ba: jmp    6801 <generic_sleepable_preload+0x6801> */
	goto x86_l_6801;
x86_l_69bf:
	/* 0x69bf: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69c1:
	/* 0x69c1: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_69c6:
	/* 0x69c6: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69cb:
	/* 0x69cb: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_69d0:
	/* 0x69d0: jmp    6279 <generic_sleepable_preload+0x6279> */
	return 25209ULL;
x86_l_69d5:
	/* 0x69d5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69d7:
	/* 0x69d7: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_69dc:
	/* 0x69dc: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69e1:
	/* 0x69e1: jmp    6306 <generic_sleepable_preload+0x6306> */
	return 25350ULL;
x86_l_69e6:
	/* 0x69e6: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69e8:
	/* 0x69e8: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_69ed:
	/* 0x69ed: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69f2:
	/* 0x69f2: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_69f7:
	/* 0x69f7: jmp    6393 <generic_sleepable_preload+0x6393> */
	return 25491ULL;
x86_l_69fc:
	/* 0x69fc: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69fe:
	/* 0x69fe: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6a03:
	/* 0x6a03: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a08:
	/* 0x6a08: jmp    6420 <generic_sleepable_preload+0x6420> */
	return 25632ULL;
x86_l_6a0d:
	/* 0x6a0d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a10:
	/* 0x6a10: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_6a15:
	/* 0x6a15: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a1a:
	/* 0x6a1a: jmp    64ae <generic_sleepable_preload+0x64ae> */
	return 25774ULL;
x86_l_6a1f:
	/* 0x6a1f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a21:
	/* 0x6a21: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6a26:
	/* 0x6a26: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a2b:
	/* 0x6a2b: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6a30:
	/* 0x6a30: jmp    653a <generic_sleepable_preload+0x653a> */
	return 25914ULL;
x86_l_6a35:
	/* 0x6a35: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a37:
	/* 0x6a37: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6a3c:
	/* 0x6a3c: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a41:
	/* 0x6a41: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6a46:
	/* 0x6a46: jmp    65ee <generic_sleepable_preload+0x65ee> */
	return 26094ULL;
x86_l_6a4b:
	/* 0x6a4b: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a4d:
	/* 0x6a4d: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6a52:
	/* 0x6a52: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a57:
	/* 0x6a57: jmp    66a3 <generic_sleepable_preload+0x66a3> */
	return 26275ULL;
x86_l_6a5c:
	/* 0x6a5c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a5e:
	/* 0x6a5e: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_6a63:
	/* 0x6a63: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a68:
	/* 0x6a68: jmp    6753 <generic_sleepable_preload+0x6753> */
	return 26451ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 22276U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1781ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1787ULL && __x86_pc <= 3580ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3582ULL && __x86_pc <= 5354ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5357ULL && __x86_pc <= 7243ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7250ULL && __x86_pc <= 9175ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9178ULL && __x86_pc <= 11134ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 11136ULL && __x86_pc <= 13105ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 13107ULL && __x86_pc <= 15064ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 15071ULL && __x86_pc <= 16995ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 17001ULL && __x86_pc <= 18954ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 18959ULL && __x86_pc <= 20913ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 20918ULL && __x86_pc <= 22881ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 22883ULL && __x86_pc <= 24830ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 24835ULL && __x86_pc <= 26461ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_13(__x86_state, __x86_pc);
		else if (__x86_pc >= 26466ULL && __x86_pc <= 27240ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_14(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

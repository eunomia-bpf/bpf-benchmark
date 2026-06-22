extern char execve_map;
extern char filter_map;
extern char process_call_heap;
extern char tg_mb_paths;
extern char tg_mb_sel_opts;
extern char tp_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_rawtp_generic_rawtp_process_filter_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 7ULL: goto x86_l_7;
	case 10ULL: goto x86_l_a;
	case 18ULL: goto x86_l_12;
	case 25ULL: goto x86_l_19;
	case 30ULL: goto x86_l_1e;
	case 35ULL: goto x86_l_23;
	case 37ULL: goto x86_l_25;
	case 40ULL: goto x86_l_28;
	case 46ULL: goto x86_l_2e;
	case 49ULL: goto x86_l_31;
	case 54ULL: goto x86_l_36;
	case 56ULL: goto x86_l_38;
	case 59ULL: goto x86_l_3b;
	case 64ULL: goto x86_l_40;
	case 71ULL: goto x86_l_47;
	case 76ULL: goto x86_l_4c;
	case 81ULL: goto x86_l_51;
	case 86ULL: goto x86_l_56;
	case 91ULL: goto x86_l_5b;
	case 96ULL: goto x86_l_60;
	case 101ULL: goto x86_l_65;
	case 103ULL: goto x86_l_67;
	case 107ULL: goto x86_l_6b;
	case 111ULL: goto x86_l_6f;
	case 118ULL: goto x86_l_76;
	case 123ULL: goto x86_l_7b;
	case 128ULL: goto x86_l_80;
	case 130ULL: goto x86_l_82;
	case 133ULL: goto x86_l_85;
	case 135ULL: goto x86_l_87;
	case 140ULL: goto x86_l_8c;
	case 146ULL: goto x86_l_92;
	case 151ULL: goto x86_l_97;
	case 156ULL: goto x86_l_9c;
	case 159ULL: goto x86_l_9f;
	case 164ULL: goto x86_l_a4;
	case 169ULL: goto x86_l_a9;
	case 174ULL: goto x86_l_ae;
	case 179ULL: goto x86_l_b3;
	case 184ULL: goto x86_l_b8;
	case 186ULL: goto x86_l_ba;
	case 191ULL: goto x86_l_bf;
	case 194ULL: goto x86_l_c2;
	case 200ULL: goto x86_l_c8;
	case 207ULL: goto x86_l_cf;
	case 212ULL: goto x86_l_d4;
	case 217ULL: goto x86_l_d9;
	case 222ULL: goto x86_l_de;
	case 227ULL: goto x86_l_e3;
	case 232ULL: goto x86_l_e8;
	case 237ULL: goto x86_l_ed;
	case 239ULL: goto x86_l_ef;
	case 243ULL: goto x86_l_f3;
	case 247ULL: goto x86_l_f7;
	case 254ULL: goto x86_l_fe;
	case 259ULL: goto x86_l_103;
	case 264ULL: goto x86_l_108;
	case 266ULL: goto x86_l_10a;
	case 269ULL: goto x86_l_10d;
	case 271ULL: goto x86_l_10f;
	case 276ULL: goto x86_l_114;
	case 282ULL: goto x86_l_11a;
	case 287ULL: goto x86_l_11f;
	case 292ULL: goto x86_l_124;
	case 295ULL: goto x86_l_127;
	case 300ULL: goto x86_l_12c;
	case 305ULL: goto x86_l_131;
	case 310ULL: goto x86_l_136;
	case 315ULL: goto x86_l_13b;
	case 320ULL: goto x86_l_140;
	case 322ULL: goto x86_l_142;
	case 327ULL: goto x86_l_147;
	case 330ULL: goto x86_l_14a;
	case 336ULL: goto x86_l_150;
	case 343ULL: goto x86_l_157;
	case 348ULL: goto x86_l_15c;
	case 353ULL: goto x86_l_161;
	case 358ULL: goto x86_l_166;
	case 363ULL: goto x86_l_16b;
	case 368ULL: goto x86_l_170;
	case 373ULL: goto x86_l_175;
	case 375ULL: goto x86_l_177;
	case 379ULL: goto x86_l_17b;
	case 383ULL: goto x86_l_17f;
	case 390ULL: goto x86_l_186;
	case 395ULL: goto x86_l_18b;
	case 400ULL: goto x86_l_190;
	case 402ULL: goto x86_l_192;
	case 405ULL: goto x86_l_195;
	case 407ULL: goto x86_l_197;
	case 412ULL: goto x86_l_19c;
	case 418ULL: goto x86_l_1a2;
	case 423ULL: goto x86_l_1a7;
	case 428ULL: goto x86_l_1ac;
	case 431ULL: goto x86_l_1af;
	case 436ULL: goto x86_l_1b4;
	case 441ULL: goto x86_l_1b9;
	case 446ULL: goto x86_l_1be;
	case 451ULL: goto x86_l_1c3;
	case 456ULL: goto x86_l_1c8;
	case 458ULL: goto x86_l_1ca;
	case 463ULL: goto x86_l_1cf;
	case 466ULL: goto x86_l_1d2;
	case 472ULL: goto x86_l_1d8;
	case 479ULL: goto x86_l_1df;
	case 484ULL: goto x86_l_1e4;
	case 489ULL: goto x86_l_1e9;
	case 494ULL: goto x86_l_1ee;
	case 499ULL: goto x86_l_1f3;
	case 504ULL: goto x86_l_1f8;
	case 509ULL: goto x86_l_1fd;
	case 511ULL: goto x86_l_1ff;
	case 515ULL: goto x86_l_203;
	case 519ULL: goto x86_l_207;
	case 526ULL: goto x86_l_20e;
	case 531ULL: goto x86_l_213;
	case 536ULL: goto x86_l_218;
	case 538ULL: goto x86_l_21a;
	case 541ULL: goto x86_l_21d;
	case 547ULL: goto x86_l_223;
	case 552ULL: goto x86_l_228;
	case 558ULL: goto x86_l_22e;
	case 561ULL: goto x86_l_231;
	case 568ULL: goto x86_l_238;
	case 575ULL: goto x86_l_23f;
	case 580ULL: goto x86_l_244;
	case 582ULL: goto x86_l_246;
	case 585ULL: goto x86_l_249;
	case 591ULL: goto x86_l_24f;
	case 598ULL: goto x86_l_256;
	case 602ULL: goto x86_l_25a;
	case 604ULL: goto x86_l_25c;
	case 608ULL: goto x86_l_260;
	case 612ULL: goto x86_l_264;
	case 616ULL: goto x86_l_268;
	case 620ULL: goto x86_l_26c;
	case 628ULL: goto x86_l_274;
	case 634ULL: goto x86_l_27a;
	case 639ULL: goto x86_l_27f;
	case 642ULL: goto x86_l_282;
	case 645ULL: goto x86_l_285;
	case 648ULL: goto x86_l_288;
	case 654ULL: goto x86_l_28e;
	case 657ULL: goto x86_l_291;
	case 663ULL: goto x86_l_297;
	case 668ULL: goto x86_l_29c;
	case 673ULL: goto x86_l_2a1;
	case 680ULL: goto x86_l_2a8;
	case 685ULL: goto x86_l_2ad;
	case 690ULL: goto x86_l_2b2;
	case 692ULL: goto x86_l_2b4;
	case 695ULL: goto x86_l_2b7;
	case 701ULL: goto x86_l_2bd;
	case 703ULL: goto x86_l_2bf;
	case 705ULL: goto x86_l_2c1;
	case 711ULL: goto x86_l_2c7;
	case 714ULL: goto x86_l_2ca;
	case 717ULL: goto x86_l_2cd;
	case 720ULL: goto x86_l_2d0;
	case 726ULL: goto x86_l_2d6;
	case 730ULL: goto x86_l_2da;
	case 736ULL: goto x86_l_2e0;
	case 739ULL: goto x86_l_2e3;
	case 744ULL: goto x86_l_2e8;
	case 747ULL: goto x86_l_2eb;
	case 749ULL: goto x86_l_2ed;
	case 756ULL: goto x86_l_2f4;
	case 759ULL: goto x86_l_2f7;
	case 763ULL: goto x86_l_2fb;
	case 765ULL: goto x86_l_2fd;
	case 772ULL: goto x86_l_304;
	case 777ULL: goto x86_l_309;
	case 780ULL: goto x86_l_30c;
	case 785ULL: goto x86_l_311;
	case 787ULL: goto x86_l_313;
	case 790ULL: goto x86_l_316;
	case 793ULL: goto x86_l_319;
	case 799ULL: goto x86_l_31f;
	case 802ULL: goto x86_l_322;
	case 806ULL: goto x86_l_326;
	case 811ULL: goto x86_l_32b;
	case 813ULL: goto x86_l_32d;
	case 816ULL: goto x86_l_330;
	case 819ULL: goto x86_l_333;
	case 823ULL: goto x86_l_337;
	case 826ULL: goto x86_l_33a;
	case 829ULL: goto x86_l_33d;
	case 835ULL: goto x86_l_343;
	case 837ULL: goto x86_l_345;
	case 847ULL: goto x86_l_34f;
	case 851ULL: goto x86_l_353;
	case 857ULL: goto x86_l_359;
	case 860ULL: goto x86_l_35c;
	case 865ULL: goto x86_l_361;
	case 867ULL: goto x86_l_363;
	case 872ULL: goto x86_l_368;
	case 880ULL: goto x86_l_370;
	case 882ULL: goto x86_l_372;
	case 886ULL: goto x86_l_376;
	case 890ULL: goto x86_l_37a;
	case 894ULL: goto x86_l_37e;
	case 899ULL: goto x86_l_383;
	case 902ULL: goto x86_l_386;
	case 907ULL: goto x86_l_38b;
	case 910ULL: goto x86_l_38e;
	case 918ULL: goto x86_l_396;
	case 922ULL: goto x86_l_39a;
	case 925ULL: goto x86_l_39d;
	case 931ULL: goto x86_l_3a3;
	case 933ULL: goto x86_l_3a5;
	case 936ULL: goto x86_l_3a8;
	case 942ULL: goto x86_l_3ae;
	case 946ULL: goto x86_l_3b2;
	case 950ULL: goto x86_l_3b6;
	case 956ULL: goto x86_l_3bc;
	case 960ULL: goto x86_l_3c0;
	case 964ULL: goto x86_l_3c4;
	case 969ULL: goto x86_l_3c9;
	case 974ULL: goto x86_l_3ce;
	case 976ULL: goto x86_l_3d0;
	case 980ULL: goto x86_l_3d4;
	case 984ULL: goto x86_l_3d8;
	case 987ULL: goto x86_l_3db;
	case 989ULL: goto x86_l_3dd;
	case 993ULL: goto x86_l_3e1;
	case 996ULL: goto x86_l_3e4;
	case 1000ULL: goto x86_l_3e8;
	case 1005ULL: goto x86_l_3ed;
	case 1008ULL: goto x86_l_3f0;
	case 1012ULL: goto x86_l_3f4;
	case 1018ULL: goto x86_l_3fa;
	case 1020ULL: goto x86_l_3fc;
	case 1022ULL: goto x86_l_3fe;
	case 1024ULL: goto x86_l_400;
	case 1029ULL: goto x86_l_405;
	case 1034ULL: goto x86_l_40a;
	case 1037ULL: goto x86_l_40d;
	case 1042ULL: goto x86_l_412;
	case 1047ULL: goto x86_l_417;
	case 1052ULL: goto x86_l_41c;
	case 1057ULL: goto x86_l_421;
	case 1062ULL: goto x86_l_426;
	case 1064ULL: goto x86_l_428;
	case 1069ULL: goto x86_l_42d;
	case 1072ULL: goto x86_l_430;
	case 1075ULL: goto x86_l_433;
	case 1081ULL: goto x86_l_439;
	case 1084ULL: goto x86_l_43c;
	case 1090ULL: goto x86_l_442;
	case 1093ULL: goto x86_l_445;
	case 1095ULL: goto x86_l_447;
	case 1098ULL: goto x86_l_44a;
	case 1101ULL: goto x86_l_44d;
	case 1106ULL: goto x86_l_452;
	case 1109ULL: goto x86_l_455;
	case 1114ULL: goto x86_l_45a;
	case 1117ULL: goto x86_l_45d;
	case 1120ULL: goto x86_l_460;
	case 1123ULL: goto x86_l_463;
	case 1127ULL: goto x86_l_467;
	case 1129ULL: goto x86_l_469;
	case 1131ULL: goto x86_l_46b;
	case 1135ULL: goto x86_l_46f;
	case 1137ULL: goto x86_l_471;
	case 1140ULL: goto x86_l_474;
	case 1146ULL: goto x86_l_47a;
	case 1149ULL: goto x86_l_47d;
	case 1152ULL: goto x86_l_480;
	case 1156ULL: goto x86_l_484;
	case 1160ULL: goto x86_l_488;
	case 1165ULL: goto x86_l_48d;
	case 1171ULL: goto x86_l_493;
	case 1177ULL: goto x86_l_499;
	case 1179ULL: goto x86_l_49b;
	case 1182ULL: goto x86_l_49e;
	case 1185ULL: goto x86_l_4a1;
	case 1191ULL: goto x86_l_4a7;
	case 1194ULL: goto x86_l_4aa;
	case 1197ULL: goto x86_l_4ad;
	case 1203ULL: goto x86_l_4b3;
	case 1208ULL: goto x86_l_4b8;
	case 1213ULL: goto x86_l_4bd;
	case 1218ULL: goto x86_l_4c2;
	case 1223ULL: goto x86_l_4c7;
	case 1228ULL: goto x86_l_4cc;
	case 1232ULL: goto x86_l_4d0;
	case 1239ULL: goto x86_l_4d7;
	case 1244ULL: goto x86_l_4dc;
	case 1246ULL: goto x86_l_4de;
	case 1249ULL: goto x86_l_4e1;
	case 1255ULL: goto x86_l_4e7;
	case 1258ULL: goto x86_l_4ea;
	case 1260ULL: goto x86_l_4ec;
	case 1265ULL: goto x86_l_4f1;
	case 1268ULL: goto x86_l_4f4;
	case 1274ULL: goto x86_l_4fa;
	case 1277ULL: goto x86_l_4fd;
	case 1280ULL: goto x86_l_500;
	case 1286ULL: goto x86_l_506;
	case 1290ULL: goto x86_l_50a;
	case 1297ULL: goto x86_l_511;
	case 1302ULL: goto x86_l_516;
	case 1304ULL: goto x86_l_518;
	case 1307ULL: goto x86_l_51b;
	case 1313ULL: goto x86_l_521;
	case 1316ULL: goto x86_l_524;
	case 1318ULL: goto x86_l_526;
	case 1323ULL: goto x86_l_52b;
	case 1326ULL: goto x86_l_52e;
	case 1332ULL: goto x86_l_534;
	case 1335ULL: goto x86_l_537;
	case 1338ULL: goto x86_l_53a;
	case 1344ULL: goto x86_l_540;
	case 1348ULL: goto x86_l_544;
	case 1355ULL: goto x86_l_54b;
	case 1360ULL: goto x86_l_550;
	case 1362ULL: goto x86_l_552;
	case 1365ULL: goto x86_l_555;
	case 1371ULL: goto x86_l_55b;
	case 1374ULL: goto x86_l_55e;
	case 1376ULL: goto x86_l_560;
	case 1381ULL: goto x86_l_565;
	case 1387ULL: goto x86_l_56b;
	case 1390ULL: goto x86_l_56e;
	case 1395ULL: goto x86_l_573;
	case 1401ULL: goto x86_l_579;
	case 1405ULL: goto x86_l_57d;
	case 1412ULL: goto x86_l_584;
	case 1417ULL: goto x86_l_589;
	case 1419ULL: goto x86_l_58b;
	case 1422ULL: goto x86_l_58e;
	case 1428ULL: goto x86_l_594;
	case 1431ULL: goto x86_l_597;
	case 1433ULL: goto x86_l_599;
	case 1438ULL: goto x86_l_59e;
	case 1444ULL: goto x86_l_5a4;
	case 1447ULL: goto x86_l_5a7;
	case 1452ULL: goto x86_l_5ac;
	case 1458ULL: goto x86_l_5b2;
	case 1462ULL: goto x86_l_5b6;
	case 1469ULL: goto x86_l_5bd;
	case 1474ULL: goto x86_l_5c2;
	case 1476ULL: goto x86_l_5c4;
	case 1479ULL: goto x86_l_5c7;
	case 1485ULL: goto x86_l_5cd;
	case 1488ULL: goto x86_l_5d0;
	case 1490ULL: goto x86_l_5d2;
	case 1495ULL: goto x86_l_5d7;
	case 1501ULL: goto x86_l_5dd;
	case 1504ULL: goto x86_l_5e0;
	case 1509ULL: goto x86_l_5e5;
	case 1515ULL: goto x86_l_5eb;
	case 1519ULL: goto x86_l_5ef;
	case 1526ULL: goto x86_l_5f6;
	case 1531ULL: goto x86_l_5fb;
	case 1533ULL: goto x86_l_5fd;
	case 1536ULL: goto x86_l_600;
	case 1542ULL: goto x86_l_606;
	case 1545ULL: goto x86_l_609;
	case 1547ULL: goto x86_l_60b;
	case 1552ULL: goto x86_l_610;
	case 1558ULL: goto x86_l_616;
	case 1561ULL: goto x86_l_619;
	case 1566ULL: goto x86_l_61e;
	case 1572ULL: goto x86_l_624;
	case 1576ULL: goto x86_l_628;
	case 1583ULL: goto x86_l_62f;
	case 1588ULL: goto x86_l_634;
	case 1590ULL: goto x86_l_636;
	case 1593ULL: goto x86_l_639;
	case 1599ULL: goto x86_l_63f;
	case 1602ULL: goto x86_l_642;
	case 1604ULL: goto x86_l_644;
	case 1609ULL: goto x86_l_649;
	case 1615ULL: goto x86_l_64f;
	case 1618ULL: goto x86_l_652;
	case 1623ULL: goto x86_l_657;
	case 1629ULL: goto x86_l_65d;
	case 1633ULL: goto x86_l_661;
	case 1640ULL: goto x86_l_668;
	case 1645ULL: goto x86_l_66d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 88ULL);
x86_l_7:
	/* 0x7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    DWORD PTR [rsp+0x54],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_12:
	/* 0x12: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_19:
	/* 0x19: lea    rsi,[rsp+0x54] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_1e:
	/* 0x1e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23:
	/* 0x23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25:
	/* 0x25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28:
	/* 0x28: je     2057 <generic_rawtp_process_filter+0x2057> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8279ULL;
	}
x86_l_2e:
	/* 0x2e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_36:
	/* 0x36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38:
	/* 0x38: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3b:
	/* 0x3b: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_40:
	/* 0x40: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_47:
	/* 0x47: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4c:
	/* 0x4c: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_51:
	/* 0x51: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_56:
	/* 0x56: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_5b:
	/* 0x5b: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_60:
	/* 0x60: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_65:
	/* 0x65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67:
	/* 0x67: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6b:
	/* 0x6b: mov    DWORD PTR [rsp+0x44],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_6f:
	/* 0x6f: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_76:
	/* 0x76: lea    rsi,[rsp+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_7b:
	/* 0x7b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_80:
	/* 0x80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_82:
	/* 0x82: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_85:
	/* 0x85: je     92 <generic_rawtp_process_filter+0x92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_92;
	}
x86_l_87:
	/* 0x87: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_8c:
	/* 0x8c: jne    22e <generic_rawtp_process_filter+0x22e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22e;
	}
x86_l_92:
	/* 0x92: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_97:
	/* 0x97: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_9c:
	/* 0x9c: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9f:
	/* 0x9f: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a4:
	/* 0xa4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a9:
	/* 0xa9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ae:
	/* 0xae: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_b3:
	/* 0xb3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b8:
	/* 0xb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ba:
	/* 0xba: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bf:
	/* 0xbf: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_c2:
	/* 0xc2: je     2057 <generic_rawtp_process_filter+0x2057> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8279ULL;
	}
x86_l_c8:
	/* 0xc8: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_cf:
	/* 0xcf: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d4:
	/* 0xd4: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_d9:
	/* 0xd9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_de:
	/* 0xde: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_e3:
	/* 0xe3: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_e8:
	/* 0xe8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ed:
	/* 0xed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef:
	/* 0xef: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f3:
	/* 0xf3: mov    DWORD PTR [rsp+0x44],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_f7:
	/* 0xf7: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_fe:
	/* 0xfe: lea    rsi,[rsp+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_103:
	/* 0x103: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_108:
	/* 0x108: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a:
	/* 0x10a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10d:
	/* 0x10d: je     11a <generic_rawtp_process_filter+0x11a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11a;
	}
x86_l_10f:
	/* 0x10f: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_114:
	/* 0x114: jne    22e <generic_rawtp_process_filter+0x22e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22e;
	}
x86_l_11a:
	/* 0x11a: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_11f:
	/* 0x11f: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_124:
	/* 0x124: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_127:
	/* 0x127: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12c:
	/* 0x12c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_131:
	/* 0x131: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_136:
	/* 0x136: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_13b:
	/* 0x13b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_140:
	/* 0x140: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_142:
	/* 0x142: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_147:
	/* 0x147: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_14a:
	/* 0x14a: je     2057 <generic_rawtp_process_filter+0x2057> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8279ULL;
	}
x86_l_150:
	/* 0x150: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_157:
	/* 0x157: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15c:
	/* 0x15c: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_161:
	/* 0x161: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_166:
	/* 0x166: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_16b:
	/* 0x16b: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_170:
	/* 0x170: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_175:
	/* 0x175: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_177:
	/* 0x177: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_17b:
	/* 0x17b: mov    DWORD PTR [rsp+0x44],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_17f:
	/* 0x17f: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_186:
	/* 0x186: lea    rsi,[rsp+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_18b:
	/* 0x18b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_190:
	/* 0x190: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_192:
	/* 0x192: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_195:
	/* 0x195: je     1a2 <generic_rawtp_process_filter+0x1a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a2;
	}
x86_l_197:
	/* 0x197: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_19c:
	/* 0x19c: jne    22e <generic_rawtp_process_filter+0x22e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22e;
	}
x86_l_1a2:
	/* 0x1a2: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_1a7:
	/* 0x1a7: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ac:
	/* 0x1ac: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1af:
	/* 0x1af: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b4:
	/* 0x1b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b9:
	/* 0x1b9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1be:
	/* 0x1be: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_1c3:
	/* 0x1c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c8:
	/* 0x1c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca:
	/* 0x1ca: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1cf:
	/* 0x1cf: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1d2:
	/* 0x1d2: je     2057 <generic_rawtp_process_filter+0x2057> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8279ULL;
	}
x86_l_1d8:
	/* 0x1d8: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_1df:
	/* 0x1df: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e4:
	/* 0x1e4: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1e9:
	/* 0x1e9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ee:
	/* 0x1ee: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_1f3:
	/* 0x1f3: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_1f8:
	/* 0x1f8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fd:
	/* 0x1fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ff:
	/* 0x1ff: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_203:
	/* 0x203: mov    DWORD PTR [rsp+0x44],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_207:
	/* 0x207: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_20e:
	/* 0x20e: lea    rsi,[rsp+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_213:
	/* 0x213: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_218:
	/* 0x218: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21a:
	/* 0x21a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21d:
	/* 0x21d: je     400 <generic_rawtp_process_filter+0x400> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_400;
	}
x86_l_223:
	/* 0x223: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_228:
	/* 0x228: je     400 <generic_rawtp_process_filter+0x400> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_400;
	}
x86_l_22e:
	/* 0x22e: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_231:
	/* 0x231: lea    rsi,[r14+0x5ee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24296ULL);
x86_l_238:
	/* 0x238: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_23f:
	/* 0x23f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_244:
	/* 0x244: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_246:
	/* 0x246: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_249:
	/* 0x249: je     2057 <generic_rawtp_process_filter+0x2057> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8279ULL;
	}
x86_l_24f:
	/* 0x24f: mov    r12,QWORD PTR [r14+0x5eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_256:
	/* 0x256: cmp    r12,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 6ULL);
x86_l_25a:
	/* 0x25a: jb     27f <generic_rawtp_process_filter+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_27f;
	}
x86_l_25c:
	/* 0x25c: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_260:
	/* 0x260: mov    DWORD PTR [r14+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_264:
	/* 0x264: mov    rax,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_268:
	/* 0x268: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26c:
	/* 0x26c: cmp    BYTE PTR [r14+0x5ec0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731776ULL);
x86_l_274:
	/* 0x274: jne    2042 <generic_rawtp_process_filter+0x2042> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8258ULL;
	}
x86_l_27a:
	/* 0x27a: jmp    2057 <generic_rawtp_process_filter+0x2057> */
	return 8279ULL;
x86_l_27f:
	/* 0x27f: movsxd r15,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_282:
	/* 0x282: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_285:
	/* 0x285: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_288:
	/* 0x288: je     368 <generic_rawtp_process_filter+0x368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_368;
	}
x86_l_28e:
	/* 0x28e: cmp    r12,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R15, X86_WIDTH_64);
x86_l_291:
	/* 0x291: jae    202a <generic_rawtp_process_filter+0x202a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8234ULL;
	}
x86_l_297:
	/* 0x297: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29c:
	/* 0x29c: mov    DWORD PTR [rsp+0x38],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a1:
	/* 0x2a1: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mb_sel_opts)));
x86_l_2a8:
	/* 0x2a8: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ad:
	/* 0x2ad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b2:
	/* 0x2b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b4:
	/* 0x2b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b7:
	/* 0x2b7: je     383 <generic_rawtp_process_filter+0x383> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_383;
	}
x86_l_2bd:
	/* 0x2bd: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bf:
	/* 0x2bf: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2c1:
	/* 0x2c1: je     383 <generic_rawtp_process_filter+0x383> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_383;
	}
x86_l_2c7:
	/* 0x2c7: lea    ecx,[rdx-0x5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551611ULL);
x86_l_2ca:
	/* 0x2ca: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2cd:
	/* 0x2cd: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2d0:
	/* 0x2d0: ja     2014 <generic_rawtp_process_filter+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8212ULL;
	}
x86_l_2d6:
	/* 0x2d6: cmp    DWORD PTR [rcx+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_2da:
	/* 0x2da: js     2014 <generic_rawtp_process_filter+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8212ULL;
	}
x86_l_2e0:
	/* 0x2e0: mov    edi,DWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e3:
	/* 0x2e3: mov    esi,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967295ULL);
x86_l_2e8:
	/* 0x2e8: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_2eb:
	/* 0x2eb: je     2fd <generic_rawtp_process_filter+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fd;
	}
x86_l_2ed:
	/* 0x2ed: mov    r8,QWORD PTR [rcx+0x370] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 880ULL);
x86_l_2f4:
	/* 0x2f4: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_2f7:
	/* 0x2f7: bt     r8,rdi */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RDI, X86_WIDTH_64);
x86_l_2fb:
	/* 0x2fb: jb     33a <generic_rawtp_process_filter+0x33a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_33a;
	}
x86_l_2fd:
	/* 0x2fd: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_mb_paths)));
x86_l_304:
	/* 0x304: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_309:
	/* 0x309: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_30c:
	/* 0x30c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_311:
	/* 0x311: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_313:
	/* 0x313: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_316:
	/* 0x316: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_319:
	/* 0x319: je     2014 <generic_rawtp_process_filter+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_31f:
	/* 0x31f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_322:
	/* 0x322: lea    rsi,[rcx+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_326:
	/* 0x326: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32b:
	/* 0x32b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32d:
	/* 0x32d: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_330:
	/* 0x330: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_333:
	/* 0x333: setne  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_NE);
x86_l_337:
	/* 0x337: mov    edx,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33a:
	/* 0x33a: cmp    edx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 37ULL);
x86_l_33d:
	/* 0x33d: ja     87e <generic_rawtp_process_filter+0x87e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2174ULL;
	}
x86_l_343:
	/* 0x343: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_345:
	/* 0x345: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_34f:
	/* 0x34f: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_353:
	/* 0x353: jae    87e <generic_rawtp_process_filter+0x87e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2174ULL;
	}
x86_l_359:
	/* 0x359: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_35c:
	/* 0x35c: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_361:
	/* 0x361: je     38b <generic_rawtp_process_filter+0x38b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38b;
	}
x86_l_363:
	/* 0x363: jmp    2014 <generic_rawtp_process_filter+0x2014> */
	return 8212ULL;
x86_l_368:
	/* 0x368: mov    BYTE PTR [r14+0x5ec0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731777ULL);
x86_l_370:
	/* 0x370: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_372:
	/* 0x372: mov    DWORD PTR [r14+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_376:
	/* 0x376: mov    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37a:
	/* 0x37a: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_37e:
	/* 0x37e: jmp    2042 <generic_rawtp_process_filter+0x2042> */
	return 8258ULL;
x86_l_383:
	/* 0x383: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_386:
	/* 0x386: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38b:
	/* 0x38b: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_38e:
	/* 0x38e: lea    rsi,[rdx*4+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 2), 4ULL);
x86_l_396:
	/* 0x396: mov    edx,DWORD PTR [rax+rdx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 4ULL);
x86_l_39a:
	/* 0x39a: lea    ebp,[rdx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_39d:
	/* 0x39d: and    ebp,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_3a3:
	/* 0x3a3: add    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3a5:
	/* 0x3a5: add    edx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3a8:
	/* 0x3a8: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_3ae:
	/* 0x3ae: lea    r11,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b2:
	/* 0x3b2: cmp    DWORD PTR [rdx+rax*1],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 5ULL);
x86_l_3b6:
	/* 0x3b6: jb     17ae <generic_rawtp_process_filter+0x17ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6062ULL;
	}
x86_l_3bc:
	/* 0x3bc: lea    r8d,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3c0:
	/* 0x3c0: mov    r9d,DWORD PTR [r11+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3c4:
	/* 0x3c4: mov    r10d,DWORD PTR [r11+rax*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_3c9:
	/* 0x3c9: mov    edx,DWORD PTR [r11+rax*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 8ULL);
x86_l_3ce:
	/* 0x3ce: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d0:
	/* 0x3d0: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_3d4:
	/* 0x3d4: sete   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_E);
x86_l_3d8:
	/* 0x3d8: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3db:
	/* 0x3db: jbe    42d <generic_rawtp_process_filter+0x42d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_42d;
	}
x86_l_3dd:
	/* 0x3dd: lea    rdx,[rcx+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3e1:
	/* 0x3e1: mov    rsi,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R10, X86_WIDTH_64);
x86_l_3e4:
	/* 0x3e4: and    rsi,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_AND, 1ULL);
x86_l_3e8:
	/* 0x3e8: mov    QWORD PTR [rsp+0x48],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3ed:
	/* 0x3ed: mov    rsi,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3f0:
	/* 0x3f0: cmove  rsi,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_3f4:
	/* 0x3f4: cmp    ebp,0x3d4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 980ULL);
x86_l_3fa:
	/* 0x3fa: jbe    45a <generic_rawtp_process_filter+0x45a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_45a;
	}
x86_l_3fc:
	/* 0x3fc: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3fe:
	/* 0x3fe: jmp    463 <generic_rawtp_process_filter+0x463> */
	goto x86_l_463;
x86_l_400:
	/* 0x400: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_405:
	/* 0x405: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_40a:
	/* 0x40a: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_40d:
	/* 0x40d: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_412:
	/* 0x412: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_417:
	/* 0x417: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_41c:
	/* 0x41c: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_421:
	/* 0x421: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_426:
	/* 0x426: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_428:
	/* 0x428: jmp    2057 <generic_rawtp_process_filter+0x2057> */
	return 8279ULL;
x86_l_42d:
	/* 0x42d: mov    dil,sil */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_8);
x86_l_430:
	/* 0x430: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_433:
	/* 0x433: je     864 <generic_rawtp_process_filter+0x864> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2148ULL;
	}
x86_l_439:
	/* 0x439: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_43c:
	/* 0x43c: je     84d <generic_rawtp_process_filter+0x84d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2125ULL;
	}
x86_l_442:
	/* 0x442: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_445:
	/* 0x445: jne    3dd <generic_rawtp_process_filter+0x3dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3dd;
	}
x86_l_447:
	/* 0x447: mov    edx,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R10, X86_WIDTH_32);
x86_l_44a:
	/* 0x44a: and    edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_44d:
	/* 0x44d: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_452:
	/* 0x452: mov    ebp,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_32);
x86_l_455:
	/* 0x455: jmp    924 <generic_rawtp_process_filter+0x924> */
	return 2340ULL;
x86_l_45a:
	/* 0x45a: mov    edi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R8, X86_WIDTH_32);
x86_l_45d:
	/* 0x45d: and    edi,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_460:
	/* 0x460: mov    edi,DWORD PTR [rax+rdi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_463:
	/* 0x463: test   r10b,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R10, X86_WIDTH_8, 2ULL);
x86_l_467:
	/* 0x467: jne    48d <generic_rawtp_process_filter+0x48d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_48d;
	}
x86_l_469:
	/* 0x469: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46b:
	/* 0x46b: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_46f:
	/* 0x46f: jne    47a <generic_rawtp_process_filter+0x47a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_47a;
	}
x86_l_471:
	/* 0x471: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_474:
	/* 0x474: jne    845 <generic_rawtp_process_filter+0x845> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2117ULL;
	}
x86_l_47a:
	/* 0x47a: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_47d:
	/* 0x47d: setne  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_NE);
x86_l_480:
	/* 0x480: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_484:
	/* 0x484: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_488:
	/* 0x488: jmp    91a <generic_rawtp_process_filter+0x91a> */
	return 2330ULL;
x86_l_48d:
	/* 0x48d: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_493:
	/* 0x493: jne    6c7 <generic_rawtp_process_filter+0x6c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1735ULL;
	}
x86_l_499:
	/* 0x499: mov    edx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49b:
	/* 0x49b: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_49e:
	/* 0x49e: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_4a1:
	/* 0x4a1: je     90f <generic_rawtp_process_filter+0x90f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2319ULL;
	}
x86_l_4a7:
	/* 0x4a7: mov    edx,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4aa:
	/* 0x4aa: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_4ad:
	/* 0x4ad: je     90f <generic_rawtp_process_filter+0x90f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2319ULL;
	}
x86_l_4b3:
	/* 0x4b3: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4b8:
	/* 0x4b8: mov    QWORD PTR [rsp+0x30],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4bd:
	/* 0x4bd: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c2:
	/* 0x4c2: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c7:
	/* 0x4c7: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4cc:
	/* 0x4cc: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d0:
	/* 0x4d0: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_4d7:
	/* 0x4d7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4dc:
	/* 0x4dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4de:
	/* 0x4de: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e1:
	/* 0x4e1: je     8ea <generic_rawtp_process_filter+0x8ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2282ULL;
	}
x86_l_4e7:
	/* 0x4e7: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_4ea:
	/* 0x4ea: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ec:
	/* 0x4ec: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4f1:
	/* 0x4f1: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_4f4:
	/* 0x4f4: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2084ULL;
	}
x86_l_4fa:
	/* 0x4fa: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4fd:
	/* 0x4fd: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_500:
	/* 0x500: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2084ULL;
	}
x86_l_506:
	/* 0x506: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_50a:
	/* 0x50a: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_511:
	/* 0x511: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_516:
	/* 0x516: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_518:
	/* 0x518: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_51b:
	/* 0x51b: je     8ea <generic_rawtp_process_filter+0x8ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2282ULL;
	}
x86_l_521:
	/* 0x521: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_524:
	/* 0x524: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_526:
	/* 0x526: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_52b:
	/* 0x52b: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_52e:
	/* 0x52e: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2084ULL;
	}
x86_l_534:
	/* 0x534: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_537:
	/* 0x537: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_53a:
	/* 0x53a: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2084ULL;
	}
x86_l_540:
	/* 0x540: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_544:
	/* 0x544: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_54b:
	/* 0x54b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_550:
	/* 0x550: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_552:
	/* 0x552: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_555:
	/* 0x555: je     8ea <generic_rawtp_process_filter+0x8ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2282ULL;
	}
x86_l_55b:
	/* 0x55b: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_55e:
	/* 0x55e: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_560:
	/* 0x560: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_565:
	/* 0x565: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2084ULL;
	}
x86_l_56b:
	/* 0x56b: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_56e:
	/* 0x56e: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_573:
	/* 0x573: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2084ULL;
	}
x86_l_579:
	/* 0x579: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_57d:
	/* 0x57d: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_584:
	/* 0x584: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_589:
	/* 0x589: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58b:
	/* 0x58b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_58e:
	/* 0x58e: je     8ea <generic_rawtp_process_filter+0x8ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2282ULL;
	}
x86_l_594:
	/* 0x594: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_597:
	/* 0x597: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_599:
	/* 0x599: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_59e:
	/* 0x59e: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2084ULL;
	}
x86_l_5a4:
	/* 0x5a4: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a7:
	/* 0x5a7: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5ac:
	/* 0x5ac: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2084ULL;
	}
x86_l_5b2:
	/* 0x5b2: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5b6:
	/* 0x5b6: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_5bd:
	/* 0x5bd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5c2:
	/* 0x5c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c4:
	/* 0x5c4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5c7:
	/* 0x5c7: je     8ea <generic_rawtp_process_filter+0x8ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2282ULL;
	}
x86_l_5cd:
	/* 0x5cd: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_5d0:
	/* 0x5d0: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d2:
	/* 0x5d2: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5d7:
	/* 0x5d7: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2084ULL;
	}
x86_l_5dd:
	/* 0x5dd: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e0:
	/* 0x5e0: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5e5:
	/* 0x5e5: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2084ULL;
	}
x86_l_5eb:
	/* 0x5eb: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5ef:
	/* 0x5ef: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_5f6:
	/* 0x5f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5fb:
	/* 0x5fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fd:
	/* 0x5fd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_600:
	/* 0x600: je     8ea <generic_rawtp_process_filter+0x8ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2282ULL;
	}
x86_l_606:
	/* 0x606: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_609:
	/* 0x609: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60b:
	/* 0x60b: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_610:
	/* 0x610: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2084ULL;
	}
x86_l_616:
	/* 0x616: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_619:
	/* 0x619: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_61e:
	/* 0x61e: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2084ULL;
	}
x86_l_624:
	/* 0x624: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_628:
	/* 0x628: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_62f:
	/* 0x62f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_634:
	/* 0x634: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_636:
	/* 0x636: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_639:
	/* 0x639: je     8ea <generic_rawtp_process_filter+0x8ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2282ULL;
	}
x86_l_63f:
	/* 0x63f: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_642:
	/* 0x642: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_644:
	/* 0x644: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_649:
	/* 0x649: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2084ULL;
	}
x86_l_64f:
	/* 0x64f: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_652:
	/* 0x652: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_657:
	/* 0x657: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2084ULL;
	}
x86_l_65d:
	/* 0x65d: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_661:
	/* 0x661: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_668:
	/* 0x668: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_66d:
	/* 0x66d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 1647ULL;
}

static __noinline __u64 tetragon_bpf_generic_rawtp_generic_rawtp_process_filter_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1647ULL: goto x86_l_66f;
	case 1650ULL: goto x86_l_672;
	case 1656ULL: goto x86_l_678;
	case 1659ULL: goto x86_l_67b;
	case 1661ULL: goto x86_l_67d;
	case 1666ULL: goto x86_l_682;
	case 1672ULL: goto x86_l_688;
	case 1675ULL: goto x86_l_68b;
	case 1680ULL: goto x86_l_690;
	case 1683ULL: goto x86_l_693;
	case 1688ULL: goto x86_l_698;
	case 1693ULL: goto x86_l_69d;
	case 1698ULL: goto x86_l_6a2;
	case 1703ULL: goto x86_l_6a7;
	case 1708ULL: goto x86_l_6ac;
	case 1714ULL: goto x86_l_6b2;
	case 1718ULL: goto x86_l_6b6;
	case 1725ULL: goto x86_l_6bd;
	case 1730ULL: goto x86_l_6c2;
	case 1735ULL: goto x86_l_6c7;
	case 1737ULL: goto x86_l_6c9;
	case 1740ULL: goto x86_l_6cc;
	case 1746ULL: goto x86_l_6d2;
	case 1749ULL: goto x86_l_6d5;
	case 1752ULL: goto x86_l_6d8;
	case 1758ULL: goto x86_l_6de;
	case 1761ULL: goto x86_l_6e1;
	case 1767ULL: goto x86_l_6e7;
	case 1772ULL: goto x86_l_6ec;
	case 1777ULL: goto x86_l_6f1;
	case 1782ULL: goto x86_l_6f6;
	case 1787ULL: goto x86_l_6fb;
	case 1792ULL: goto x86_l_700;
	case 1796ULL: goto x86_l_704;
	case 1803ULL: goto x86_l_70b;
	case 1808ULL: goto x86_l_710;
	case 1810ULL: goto x86_l_712;
	case 1813ULL: goto x86_l_715;
	case 1819ULL: goto x86_l_71b;
	case 1822ULL: goto x86_l_71e;
	case 1825ULL: goto x86_l_721;
	case 1830ULL: goto x86_l_726;
	case 1836ULL: goto x86_l_72c;
	case 1840ULL: goto x86_l_730;
	case 1847ULL: goto x86_l_737;
	case 1852ULL: goto x86_l_73c;
	case 1854ULL: goto x86_l_73e;
	case 1857ULL: goto x86_l_741;
	case 1863ULL: goto x86_l_747;
	case 1866ULL: goto x86_l_74a;
	case 1869ULL: goto x86_l_74d;
	case 1874ULL: goto x86_l_752;
	case 1880ULL: goto x86_l_758;
	case 1884ULL: goto x86_l_75c;
	case 1891ULL: goto x86_l_763;
	case 1896ULL: goto x86_l_768;
	case 1898ULL: goto x86_l_76a;
	case 1901ULL: goto x86_l_76d;
	case 1907ULL: goto x86_l_773;
	case 1910ULL: goto x86_l_776;
	case 1913ULL: goto x86_l_779;
	case 1918ULL: goto x86_l_77e;
	case 1924ULL: goto x86_l_784;
	case 1928ULL: goto x86_l_788;
	case 1935ULL: goto x86_l_78f;
	case 1940ULL: goto x86_l_794;
	case 1942ULL: goto x86_l_796;
	case 1945ULL: goto x86_l_799;
	case 1951ULL: goto x86_l_79f;
	case 1954ULL: goto x86_l_7a2;
	case 1957ULL: goto x86_l_7a5;
	case 1962ULL: goto x86_l_7aa;
	case 1964ULL: goto x86_l_7ac;
	case 1968ULL: goto x86_l_7b0;
	case 1975ULL: goto x86_l_7b7;
	case 1980ULL: goto x86_l_7bc;
	case 1982ULL: goto x86_l_7be;
	case 1985ULL: goto x86_l_7c1;
	case 1991ULL: goto x86_l_7c7;
	case 1994ULL: goto x86_l_7ca;
	case 1997ULL: goto x86_l_7cd;
	case 2002ULL: goto x86_l_7d2;
	case 2004ULL: goto x86_l_7d4;
	case 2008ULL: goto x86_l_7d8;
	case 2015ULL: goto x86_l_7df;
	case 2020ULL: goto x86_l_7e4;
	case 2022ULL: goto x86_l_7e6;
	case 2025ULL: goto x86_l_7e9;
	case 2031ULL: goto x86_l_7ef;
	case 2034ULL: goto x86_l_7f2;
	case 2037ULL: goto x86_l_7f5;
	case 2042ULL: goto x86_l_7fa;
	case 2044ULL: goto x86_l_7fc;
	case 2048ULL: goto x86_l_800;
	case 2055ULL: goto x86_l_807;
	case 2060ULL: goto x86_l_80c;
	case 2062ULL: goto x86_l_80e;
	case 2065ULL: goto x86_l_811;
	case 2071ULL: goto x86_l_817;
	case 2074ULL: goto x86_l_81a;
	case 2077ULL: goto x86_l_81d;
	case 2082ULL: goto x86_l_822;
	case 2084ULL: goto x86_l_824;
	case 2087ULL: goto x86_l_827;
	case 2092ULL: goto x86_l_82c;
	case 2097ULL: goto x86_l_831;
	case 2102ULL: goto x86_l_836;
	case 2107ULL: goto x86_l_83b;
	case 2112ULL: goto x86_l_840;
	case 2117ULL: goto x86_l_845;
	case 2120ULL: goto x86_l_848;
	case 2125ULL: goto x86_l_84d;
	case 2128ULL: goto x86_l_850;
	case 2131ULL: goto x86_l_853;
	case 2136ULL: goto x86_l_858;
	case 2140ULL: goto x86_l_85c;
	case 2143ULL: goto x86_l_85f;
	case 2148ULL: goto x86_l_864;
	case 2151ULL: goto x86_l_867;
	case 2154ULL: goto x86_l_86a;
	case 2159ULL: goto x86_l_86f;
	case 2162ULL: goto x86_l_872;
	case 2166ULL: goto x86_l_876;
	case 2169ULL: goto x86_l_879;
	case 2174ULL: goto x86_l_87e;
	case 2177ULL: goto x86_l_881;
	case 2182ULL: goto x86_l_886;
	case 2188ULL: goto x86_l_88c;
	case 2193ULL: goto x86_l_891;
	case 2197ULL: goto x86_l_895;
	case 2204ULL: goto x86_l_89c;
	case 2209ULL: goto x86_l_8a1;
	case 2211ULL: goto x86_l_8a3;
	case 2214ULL: goto x86_l_8a6;
	case 2216ULL: goto x86_l_8a8;
	case 2219ULL: goto x86_l_8ab;
	case 2222ULL: goto x86_l_8ae;
	case 2227ULL: goto x86_l_8b3;
	case 2230ULL: goto x86_l_8b6;
	case 2235ULL: goto x86_l_8bb;
	case 2240ULL: goto x86_l_8c0;
	case 2245ULL: goto x86_l_8c5;
	case 2250ULL: goto x86_l_8ca;
	case 2255ULL: goto x86_l_8cf;
	case 2257ULL: goto x86_l_8d1;
	case 2261ULL: goto x86_l_8d5;
	case 2268ULL: goto x86_l_8dc;
	case 2273ULL: goto x86_l_8e1;
	case 2280ULL: goto x86_l_8e8;
	case 2282ULL: goto x86_l_8ea;
	case 2285ULL: goto x86_l_8ed;
	case 2290ULL: goto x86_l_8f2;
	case 2294ULL: goto x86_l_8f6;
	case 2297ULL: goto x86_l_8f9;
	case 2302ULL: goto x86_l_8fe;
	case 2307ULL: goto x86_l_903;
	case 2312ULL: goto x86_l_908;
	case 2317ULL: goto x86_l_90d;
	case 2319ULL: goto x86_l_90f;
	case 2323ULL: goto x86_l_913;
	case 2326ULL: goto x86_l_916;
	case 2330ULL: goto x86_l_91a;
	case 2333ULL: goto x86_l_91d;
	case 2337ULL: goto x86_l_921;
	case 2340ULL: goto x86_l_924;
	case 2344ULL: goto x86_l_928;
	case 2350ULL: goto x86_l_92e;
	case 2353ULL: goto x86_l_931;
	case 2357ULL: goto x86_l_935;
	case 2363ULL: goto x86_l_93b;
	case 2365ULL: goto x86_l_93d;
	case 2368ULL: goto x86_l_940;
	case 2373ULL: goto x86_l_945;
	case 2375ULL: goto x86_l_947;
	case 2378ULL: goto x86_l_94a;
	case 2380ULL: goto x86_l_94c;
	case 2383ULL: goto x86_l_94f;
	case 2386ULL: goto x86_l_952;
	case 2391ULL: goto x86_l_957;
	case 2394ULL: goto x86_l_95a;
	case 2398ULL: goto x86_l_95e;
	case 2400ULL: goto x86_l_960;
	case 2402ULL: goto x86_l_962;
	case 2406ULL: goto x86_l_966;
	case 2411ULL: goto x86_l_96b;
	case 2413ULL: goto x86_l_96d;
	case 2416ULL: goto x86_l_970;
	case 2422ULL: goto x86_l_976;
	case 2425ULL: goto x86_l_979;
	case 2428ULL: goto x86_l_97c;
	case 2432ULL: goto x86_l_980;
	case 2436ULL: goto x86_l_984;
	case 2441ULL: goto x86_l_989;
	case 2447ULL: goto x86_l_98f;
	case 2453ULL: goto x86_l_995;
	case 2455ULL: goto x86_l_997;
	case 2458ULL: goto x86_l_99a;
	case 2463ULL: goto x86_l_99f;
	case 2469ULL: goto x86_l_9a5;
	case 2472ULL: goto x86_l_9a8;
	case 2475ULL: goto x86_l_9ab;
	case 2481ULL: goto x86_l_9b1;
	case 2484ULL: goto x86_l_9b4;
	case 2490ULL: goto x86_l_9ba;
	case 2494ULL: goto x86_l_9be;
	case 2499ULL: goto x86_l_9c3;
	case 2504ULL: goto x86_l_9c8;
	case 2509ULL: goto x86_l_9cd;
	case 2514ULL: goto x86_l_9d2;
	case 2518ULL: goto x86_l_9d6;
	case 2525ULL: goto x86_l_9dd;
	case 2530ULL: goto x86_l_9e2;
	case 2532ULL: goto x86_l_9e4;
	case 2535ULL: goto x86_l_9e7;
	case 2541ULL: goto x86_l_9ed;
	case 2544ULL: goto x86_l_9f0;
	case 2547ULL: goto x86_l_9f3;
	case 2552ULL: goto x86_l_9f8;
	case 2558ULL: goto x86_l_9fe;
	case 2562ULL: goto x86_l_a02;
	case 2569ULL: goto x86_l_a09;
	case 2574ULL: goto x86_l_a0e;
	case 2576ULL: goto x86_l_a10;
	case 2579ULL: goto x86_l_a13;
	case 2585ULL: goto x86_l_a19;
	case 2588ULL: goto x86_l_a1c;
	case 2591ULL: goto x86_l_a1f;
	case 2596ULL: goto x86_l_a24;
	case 2602ULL: goto x86_l_a2a;
	case 2606ULL: goto x86_l_a2e;
	case 2613ULL: goto x86_l_a35;
	case 2618ULL: goto x86_l_a3a;
	case 2620ULL: goto x86_l_a3c;
	case 2623ULL: goto x86_l_a3f;
	case 2629ULL: goto x86_l_a45;
	case 2632ULL: goto x86_l_a48;
	case 2635ULL: goto x86_l_a4b;
	case 2640ULL: goto x86_l_a50;
	case 2646ULL: goto x86_l_a56;
	case 2650ULL: goto x86_l_a5a;
	case 2657ULL: goto x86_l_a61;
	case 2662ULL: goto x86_l_a66;
	case 2664ULL: goto x86_l_a68;
	case 2667ULL: goto x86_l_a6b;
	case 2673ULL: goto x86_l_a71;
	case 2676ULL: goto x86_l_a74;
	case 2679ULL: goto x86_l_a77;
	case 2684ULL: goto x86_l_a7c;
	case 2690ULL: goto x86_l_a82;
	case 2694ULL: goto x86_l_a86;
	case 2701ULL: goto x86_l_a8d;
	case 2706ULL: goto x86_l_a92;
	case 2708ULL: goto x86_l_a94;
	case 2711ULL: goto x86_l_a97;
	case 2717ULL: goto x86_l_a9d;
	case 2720ULL: goto x86_l_aa0;
	case 2723ULL: goto x86_l_aa3;
	case 2728ULL: goto x86_l_aa8;
	case 2734ULL: goto x86_l_aae;
	case 2738ULL: goto x86_l_ab2;
	case 2745ULL: goto x86_l_ab9;
	case 2750ULL: goto x86_l_abe;
	case 2752ULL: goto x86_l_ac0;
	case 2755ULL: goto x86_l_ac3;
	case 2761ULL: goto x86_l_ac9;
	case 2764ULL: goto x86_l_acc;
	case 2767ULL: goto x86_l_acf;
	case 2772ULL: goto x86_l_ad4;
	case 2778ULL: goto x86_l_ada;
	case 2782ULL: goto x86_l_ade;
	case 2789ULL: goto x86_l_ae5;
	case 2794ULL: goto x86_l_aea;
	case 2796ULL: goto x86_l_aec;
	case 2799ULL: goto x86_l_aef;
	case 2805ULL: goto x86_l_af5;
	case 2808ULL: goto x86_l_af8;
	case 2811ULL: goto x86_l_afb;
	case 2816ULL: goto x86_l_b00;
	case 2822ULL: goto x86_l_b06;
	case 2826ULL: goto x86_l_b0a;
	case 2833ULL: goto x86_l_b11;
	case 2838ULL: goto x86_l_b16;
	case 2840ULL: goto x86_l_b18;
	case 2843ULL: goto x86_l_b1b;
	case 2849ULL: goto x86_l_b21;
	case 2852ULL: goto x86_l_b24;
	case 2855ULL: goto x86_l_b27;
	case 2860ULL: goto x86_l_b2c;
	case 2863ULL: goto x86_l_b2f;
	case 2868ULL: goto x86_l_b34;
	case 2873ULL: goto x86_l_b39;
	case 2878ULL: goto x86_l_b3e;
	case 2883ULL: goto x86_l_b43;
	case 2888ULL: goto x86_l_b48;
	case 2892ULL: goto x86_l_b4c;
	case 2898ULL: goto x86_l_b52;
	case 2902ULL: goto x86_l_b56;
	case 2909ULL: goto x86_l_b5d;
	case 2914ULL: goto x86_l_b62;
	case 2919ULL: goto x86_l_b67;
	case 2922ULL: goto x86_l_b6a;
	case 2927ULL: goto x86_l_b6f;
	case 2929ULL: goto x86_l_b71;
	case 2932ULL: goto x86_l_b74;
	case 2937ULL: goto x86_l_b79;
	case 2940ULL: goto x86_l_b7c;
	case 2946ULL: goto x86_l_b82;
	case 2949ULL: goto x86_l_b85;
	case 2952ULL: goto x86_l_b88;
	case 2958ULL: goto x86_l_b8e;
	case 2962ULL: goto x86_l_b92;
	case 2967ULL: goto x86_l_b97;
	case 2972ULL: goto x86_l_b9c;
	case 2977ULL: goto x86_l_ba1;
	case 2982ULL: goto x86_l_ba6;
	case 2986ULL: goto x86_l_baa;
	case 2993ULL: goto x86_l_bb1;
	case 2998ULL: goto x86_l_bb6;
	case 3000ULL: goto x86_l_bb8;
	case 3003ULL: goto x86_l_bbb;
	case 3009ULL: goto x86_l_bc1;
	case 3012ULL: goto x86_l_bc4;
	case 3014ULL: goto x86_l_bc6;
	case 3019ULL: goto x86_l_bcb;
	case 3022ULL: goto x86_l_bce;
	case 3028ULL: goto x86_l_bd4;
	case 3031ULL: goto x86_l_bd7;
	case 3034ULL: goto x86_l_bda;
	case 3040ULL: goto x86_l_be0;
	case 3044ULL: goto x86_l_be4;
	case 3051ULL: goto x86_l_beb;
	case 3056ULL: goto x86_l_bf0;
	case 3058ULL: goto x86_l_bf2;
	case 3061ULL: goto x86_l_bf5;
	case 3067ULL: goto x86_l_bfb;
	case 3070ULL: goto x86_l_bfe;
	case 3072ULL: goto x86_l_c00;
	case 3077ULL: goto x86_l_c05;
	case 3080ULL: goto x86_l_c08;
	case 3086ULL: goto x86_l_c0e;
	case 3089ULL: goto x86_l_c11;
	case 3092ULL: goto x86_l_c14;
	case 3098ULL: goto x86_l_c1a;
	case 3102ULL: goto x86_l_c1e;
	case 3109ULL: goto x86_l_c25;
	case 3114ULL: goto x86_l_c2a;
	case 3116ULL: goto x86_l_c2c;
	case 3119ULL: goto x86_l_c2f;
	case 3125ULL: goto x86_l_c35;
	case 3128ULL: goto x86_l_c38;
	case 3130ULL: goto x86_l_c3a;
	case 3135ULL: goto x86_l_c3f;
	case 3141ULL: goto x86_l_c45;
	case 3144ULL: goto x86_l_c48;
	case 3149ULL: goto x86_l_c4d;
	case 3155ULL: goto x86_l_c53;
	case 3159ULL: goto x86_l_c57;
	case 3166ULL: goto x86_l_c5e;
	case 3171ULL: goto x86_l_c63;
	case 3173ULL: goto x86_l_c65;
	case 3176ULL: goto x86_l_c68;
	case 3182ULL: goto x86_l_c6e;
	case 3185ULL: goto x86_l_c71;
	case 3187ULL: goto x86_l_c73;
	case 3192ULL: goto x86_l_c78;
	case 3198ULL: goto x86_l_c7e;
	case 3201ULL: goto x86_l_c81;
	case 3206ULL: goto x86_l_c86;
	case 3212ULL: goto x86_l_c8c;
	case 3216ULL: goto x86_l_c90;
	case 3223ULL: goto x86_l_c97;
	case 3228ULL: goto x86_l_c9c;
	case 3230ULL: goto x86_l_c9e;
	case 3233ULL: goto x86_l_ca1;
	case 3239ULL: goto x86_l_ca7;
	case 3242ULL: goto x86_l_caa;
	case 3244ULL: goto x86_l_cac;
	case 3249ULL: goto x86_l_cb1;
	case 3255ULL: goto x86_l_cb7;
	case 3258ULL: goto x86_l_cba;
	case 3263ULL: goto x86_l_cbf;
	case 3269ULL: goto x86_l_cc5;
	case 3273ULL: goto x86_l_cc9;
	case 3280ULL: goto x86_l_cd0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_66f:
	/* 0x66f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_672:
	/* 0x672: je     8ea <generic_rawtp_process_filter+0x8ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ea;
	}
x86_l_678:
	/* 0x678: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_67b:
	/* 0x67b: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67d:
	/* 0x67d: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_682:
	/* 0x682: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_824;
	}
x86_l_688:
	/* 0x688: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_68b:
	/* 0x68b: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_690:
	/* 0x690: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_693:
	/* 0x693: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_698:
	/* 0x698: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_69d:
	/* 0x69d: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6a2:
	/* 0x6a2: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6a7:
	/* 0x6a7: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6ac:
	/* 0x6ac: je     90f <generic_rawtp_process_filter+0x90f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_90f;
	}
x86_l_6b2:
	/* 0x6b2: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6b6:
	/* 0x6b6: mov    rcx,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_6bd:
	/* 0x6bd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6c2:
	/* 0x6c2: jmp    8e1 <generic_rawtp_process_filter+0x8e1> */
	goto x86_l_8e1;
x86_l_6c7:
	/* 0x6c7: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6c9:
	/* 0x6c9: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_6cc:
	/* 0x6cc: je     845 <generic_rawtp_process_filter+0x845> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_845;
	}
x86_l_6d2:
	/* 0x6d2: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_6d5:
	/* 0x6d5: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_6d8:
	/* 0x6d8: je     90f <generic_rawtp_process_filter+0x90f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_90f;
	}
x86_l_6de:
	/* 0x6de: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_6e1:
	/* 0x6e1: je     90f <generic_rawtp_process_filter+0x90f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_90f;
	}
x86_l_6e7:
	/* 0x6e7: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6ec:
	/* 0x6ec: mov    QWORD PTR [rsp+0x30],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6f1:
	/* 0x6f1: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6f6:
	/* 0x6f6: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6fb:
	/* 0x6fb: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_700:
	/* 0x700: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_704:
	/* 0x704: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_70b:
	/* 0x70b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_710:
	/* 0x710: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_712:
	/* 0x712: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_715:
	/* 0x715: je     8ea <generic_rawtp_process_filter+0x8ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ea;
	}
x86_l_71b:
	/* 0x71b: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_71e:
	/* 0x71e: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_721:
	/* 0x721: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_726:
	/* 0x726: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_824;
	}
x86_l_72c:
	/* 0x72c: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_730:
	/* 0x730: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_737:
	/* 0x737: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_73c:
	/* 0x73c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_73e:
	/* 0x73e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_741:
	/* 0x741: je     8ea <generic_rawtp_process_filter+0x8ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ea;
	}
x86_l_747:
	/* 0x747: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_74a:
	/* 0x74a: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_74d:
	/* 0x74d: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_752:
	/* 0x752: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_824;
	}
x86_l_758:
	/* 0x758: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_75c:
	/* 0x75c: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_763:
	/* 0x763: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_768:
	/* 0x768: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76a:
	/* 0x76a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_76d:
	/* 0x76d: je     8ea <generic_rawtp_process_filter+0x8ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ea;
	}
x86_l_773:
	/* 0x773: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_776:
	/* 0x776: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_779:
	/* 0x779: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_77e:
	/* 0x77e: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_824;
	}
x86_l_784:
	/* 0x784: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_788:
	/* 0x788: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_78f:
	/* 0x78f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_794:
	/* 0x794: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_796:
	/* 0x796: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_799:
	/* 0x799: je     8ea <generic_rawtp_process_filter+0x8ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ea;
	}
x86_l_79f:
	/* 0x79f: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_7a2:
	/* 0x7a2: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_7a5:
	/* 0x7a5: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7aa:
	/* 0x7aa: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_824;
	}
x86_l_7ac:
	/* 0x7ac: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_7b0:
	/* 0x7b0: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_7b7:
	/* 0x7b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7bc:
	/* 0x7bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7be:
	/* 0x7be: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7c1:
	/* 0x7c1: je     8ea <generic_rawtp_process_filter+0x8ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ea;
	}
x86_l_7c7:
	/* 0x7c7: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_7ca:
	/* 0x7ca: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_7cd:
	/* 0x7cd: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7d2:
	/* 0x7d2: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_824;
	}
x86_l_7d4:
	/* 0x7d4: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_7d8:
	/* 0x7d8: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_7df:
	/* 0x7df: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7e4:
	/* 0x7e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e6:
	/* 0x7e6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7e9:
	/* 0x7e9: je     8ea <generic_rawtp_process_filter+0x8ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ea;
	}
x86_l_7ef:
	/* 0x7ef: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_7f2:
	/* 0x7f2: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_7f5:
	/* 0x7f5: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7fa:
	/* 0x7fa: je     824 <generic_rawtp_process_filter+0x824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_824;
	}
x86_l_7fc:
	/* 0x7fc: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_800:
	/* 0x800: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_807:
	/* 0x807: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_80c:
	/* 0x80c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80e:
	/* 0x80e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_811:
	/* 0x811: je     8ea <generic_rawtp_process_filter+0x8ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ea;
	}
x86_l_817:
	/* 0x817: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_81a:
	/* 0x81a: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_81d:
	/* 0x81d: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_822:
	/* 0x822: jne    891 <generic_rawtp_process_filter+0x891> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_891;
	}
x86_l_824:
	/* 0x824: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_827:
	/* 0x827: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_82c:
	/* 0x82c: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_831:
	/* 0x831: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_836:
	/* 0x836: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_83b:
	/* 0x83b: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_840:
	/* 0x840: jmp    90f <generic_rawtp_process_filter+0x90f> */
	goto x86_l_90f;
x86_l_845:
	/* 0x845: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_848:
	/* 0x848: jmp    91d <generic_rawtp_process_filter+0x91d> */
	goto x86_l_91d;
x86_l_84d:
	/* 0x84d: mov    edx,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R10, X86_WIDTH_32);
x86_l_850:
	/* 0x850: and    edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_853:
	/* 0x853: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_858:
	/* 0x858: mov    DWORD PTR [rsp+0x50],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_85c:
	/* 0x85c: mov    ebp,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_32);
x86_l_85f:
	/* 0x85f: jmp    e01 <generic_rawtp_process_filter+0xe01> */
	return 3585ULL;
x86_l_864:
	/* 0x864: mov    edx,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R10, X86_WIDTH_32);
x86_l_867:
	/* 0x867: and    edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_86a:
	/* 0x86a: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_86f:
	/* 0x86f: mov    r12d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_32);
x86_l_872:
	/* 0x872: mov    DWORD PTR [rsp+0x50],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_876:
	/* 0x876: mov    ebp,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_32);
x86_l_879:
	/* 0x879: jmp    12da <generic_rawtp_process_filter+0x12da> */
	return 4826ULL;
x86_l_87e:
	/* 0x87e: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_881:
	/* 0x881: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_886:
	/* 0x886: jne    38b <generic_rawtp_process_filter+0x38b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 907ULL;
	}
x86_l_88c:
	/* 0x88c: jmp    2014 <generic_rawtp_process_filter+0x2014> */
	return 8212ULL;
x86_l_891:
	/* 0x891: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_895:
	/* 0x895: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_89c:
	/* 0x89c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8a1:
	/* 0x8a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a3:
	/* 0x8a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8a6:
	/* 0x8a6: je     8ea <generic_rawtp_process_filter+0x8ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ea;
	}
x86_l_8a8:
	/* 0x8a8: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_8ab:
	/* 0x8ab: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_8ae:
	/* 0x8ae: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8b3:
	/* 0x8b3: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_8b6:
	/* 0x8b6: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8bb:
	/* 0x8bb: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8c0:
	/* 0x8c0: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8c5:
	/* 0x8c5: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8ca:
	/* 0x8ca: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8cf:
	/* 0x8cf: je     90f <generic_rawtp_process_filter+0x90f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_90f;
	}
x86_l_8d1:
	/* 0x8d1: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_8d5:
	/* 0x8d5: mov    rcx,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_8dc:
	/* 0x8dc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8e1:
	/* 0x8e1: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_8e8:
	/* 0x8e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ea:
	/* 0x8ea: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8ed:
	/* 0x8ed: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8f2:
	/* 0x8f2: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_8f6:
	/* 0x8f6: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_8f9:
	/* 0x8f9: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8fe:
	/* 0x8fe: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_903:
	/* 0x903: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_908:
	/* 0x908: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_90d:
	/* 0x90d: je     91d <generic_rawtp_process_filter+0x91d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_91d;
	}
x86_l_90f:
	/* 0x90f: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_913:
	/* 0x913: setne  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_NE);
x86_l_916:
	/* 0x916: xor    r12b,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_91a:
	/* 0x91a: or     r12b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_91d:
	/* 0x91d: movzx  edi,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_921:
	/* 0x921: add    ebp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_924:
	/* 0x924: lea    rdx,[rcx+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_928:
	/* 0x928: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_92e:
	/* 0x92e: mov    rsi,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_931:
	/* 0x931: cmove  rsi,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_935:
	/* 0x935: cmp    ebp,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1000ULL);
x86_l_93b:
	/* 0x93b: jbe    947 <generic_rawtp_process_filter+0x947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_947;
	}
x86_l_93d:
	/* 0x93d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_940:
	/* 0x940: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_945:
	/* 0x945: jmp    95a <generic_rawtp_process_filter+0x95a> */
	goto x86_l_95a;
x86_l_947:
	/* 0x947: mov    r12d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_32);
x86_l_94a:
	/* 0x94a: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_94c:
	/* 0x94c: and    edi,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_94f:
	/* 0x94f: mov    edi,DWORD PTR [rax+rdi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_952:
	/* 0x952: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_957:
	/* 0x957: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_95a:
	/* 0x95a: test   r10b,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R10, X86_WIDTH_8, 2ULL);
x86_l_95e:
	/* 0x95e: jne    989 <generic_rawtp_process_filter+0x989> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_989;
	}
x86_l_960:
	/* 0x960: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_962:
	/* 0x962: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_966:
	/* 0x966: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_96b:
	/* 0x96b: jne    976 <generic_rawtp_process_filter+0x976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_976;
	}
x86_l_96d:
	/* 0x96d: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_970:
	/* 0x970: jne    b67 <generic_rawtp_process_filter+0xb67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b67;
	}
x86_l_976:
	/* 0x976: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_979:
	/* 0x979: setne  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_NE);
x86_l_97c:
	/* 0x97c: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_980:
	/* 0x980: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_984:
	/* 0x984: jmp    df3 <generic_rawtp_process_filter+0xdf3> */
	return 3571ULL;
x86_l_989:
	/* 0x989: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_98f:
	/* 0x98f: je     b6f <generic_rawtp_process_filter+0xb6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b6f;
	}
x86_l_995:
	/* 0x995: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_997:
	/* 0x997: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_99a:
	/* 0x99a: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_99f:
	/* 0x99f: je     b67 <generic_rawtp_process_filter+0xb67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b67;
	}
x86_l_9a5:
	/* 0x9a5: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_9a8:
	/* 0x9a8: test   rsi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_64);
x86_l_9ab:
	/* 0x9ab: je     de8 <generic_rawtp_process_filter+0xde8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3560ULL;
	}
x86_l_9b1:
	/* 0x9b1: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_9b4:
	/* 0x9b4: je     de8 <generic_rawtp_process_filter+0xde8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3560ULL;
	}
x86_l_9ba:
	/* 0x9ba: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_9be:
	/* 0x9be: mov    QWORD PTR [rsp+0x30],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9c3:
	/* 0x9c3: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9c8:
	/* 0x9c8: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9cd:
	/* 0x9cd: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9d2:
	/* 0x9d2: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9d6:
	/* 0x9d6: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_9dd:
	/* 0x9dd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9e2:
	/* 0x9e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e4:
	/* 0x9e4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9e7:
	/* 0x9e7: je     d9d <generic_rawtp_process_filter+0xd9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3485ULL;
	}
x86_l_9ed:
	/* 0x9ed: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_9f0:
	/* 0x9f0: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_9f3:
	/* 0x9f3: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9f8:
	/* 0x9f8: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3528ULL;
	}
x86_l_9fe:
	/* 0x9fe: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_a02:
	/* 0xa02: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_a09:
	/* 0xa09: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a0e:
	/* 0xa0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a10:
	/* 0xa10: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a13:
	/* 0xa13: je     d9d <generic_rawtp_process_filter+0xd9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3485ULL;
	}
x86_l_a19:
	/* 0xa19: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_a1c:
	/* 0xa1c: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_a1f:
	/* 0xa1f: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a24:
	/* 0xa24: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3528ULL;
	}
x86_l_a2a:
	/* 0xa2a: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_a2e:
	/* 0xa2e: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_a35:
	/* 0xa35: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a3a:
	/* 0xa3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a3c:
	/* 0xa3c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a3f:
	/* 0xa3f: je     d9d <generic_rawtp_process_filter+0xd9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3485ULL;
	}
x86_l_a45:
	/* 0xa45: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_a48:
	/* 0xa48: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_a4b:
	/* 0xa4b: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a50:
	/* 0xa50: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3528ULL;
	}
x86_l_a56:
	/* 0xa56: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_a5a:
	/* 0xa5a: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_a61:
	/* 0xa61: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a66:
	/* 0xa66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a68:
	/* 0xa68: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a6b:
	/* 0xa6b: je     d9d <generic_rawtp_process_filter+0xd9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3485ULL;
	}
x86_l_a71:
	/* 0xa71: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_a74:
	/* 0xa74: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_a77:
	/* 0xa77: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a7c:
	/* 0xa7c: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3528ULL;
	}
x86_l_a82:
	/* 0xa82: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_a86:
	/* 0xa86: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_a8d:
	/* 0xa8d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a92:
	/* 0xa92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a94:
	/* 0xa94: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a97:
	/* 0xa97: je     d9d <generic_rawtp_process_filter+0xd9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3485ULL;
	}
x86_l_a9d:
	/* 0xa9d: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_aa0:
	/* 0xaa0: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_aa3:
	/* 0xaa3: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_aa8:
	/* 0xaa8: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3528ULL;
	}
x86_l_aae:
	/* 0xaae: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ab2:
	/* 0xab2: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_ab9:
	/* 0xab9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_abe:
	/* 0xabe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac0:
	/* 0xac0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ac3:
	/* 0xac3: je     d9d <generic_rawtp_process_filter+0xd9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3485ULL;
	}
x86_l_ac9:
	/* 0xac9: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_acc:
	/* 0xacc: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_acf:
	/* 0xacf: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ad4:
	/* 0xad4: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3528ULL;
	}
x86_l_ada:
	/* 0xada: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ade:
	/* 0xade: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_ae5:
	/* 0xae5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_aea:
	/* 0xaea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aec:
	/* 0xaec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aef:
	/* 0xaef: je     d9d <generic_rawtp_process_filter+0xd9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3485ULL;
	}
x86_l_af5:
	/* 0xaf5: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_af8:
	/* 0xaf8: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_afb:
	/* 0xafb: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b00:
	/* 0xb00: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3528ULL;
	}
x86_l_b06:
	/* 0xb06: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_b0a:
	/* 0xb0a: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_b11:
	/* 0xb11: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b16:
	/* 0xb16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b18:
	/* 0xb18: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b1b:
	/* 0xb1b: je     d9d <generic_rawtp_process_filter+0xd9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3485ULL;
	}
x86_l_b21:
	/* 0xb21: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_b24:
	/* 0xb24: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_b27:
	/* 0xb27: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b2c:
	/* 0xb2c: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_b2f:
	/* 0xb2f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b34:
	/* 0xb34: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b39:
	/* 0xb39: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b3e:
	/* 0xb3e: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b43:
	/* 0xb43: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b48:
	/* 0xb48: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b4c:
	/* 0xb4c: je     de8 <generic_rawtp_process_filter+0xde8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3560ULL;
	}
x86_l_b52:
	/* 0xb52: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_b56:
	/* 0xb56: mov    rcx,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_b5d:
	/* 0xb5d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b62:
	/* 0xb62: jmp    d94 <generic_rawtp_process_filter+0xd94> */
	return 3476ULL;
x86_l_b67:
	/* 0xb67: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b6a:
	/* 0xb6a: jmp    df6 <generic_rawtp_process_filter+0xdf6> */
	return 3574ULL;
x86_l_b6f:
	/* 0xb6f: mov    edx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b71:
	/* 0xb71: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_b74:
	/* 0xb74: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b79:
	/* 0xb79: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_b7c:
	/* 0xb7c: je     de8 <generic_rawtp_process_filter+0xde8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3560ULL;
	}
x86_l_b82:
	/* 0xb82: mov    edx,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b85:
	/* 0xb85: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_b88:
	/* 0xb88: je     de8 <generic_rawtp_process_filter+0xde8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3560ULL;
	}
x86_l_b8e:
	/* 0xb8e: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b92:
	/* 0xb92: mov    QWORD PTR [rsp+0x30],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b97:
	/* 0xb97: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b9c:
	/* 0xb9c: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ba1:
	/* 0xba1: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ba6:
	/* 0xba6: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_baa:
	/* 0xbaa: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_bb1:
	/* 0xbb1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bb6:
	/* 0xbb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb8:
	/* 0xbb8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bbb:
	/* 0xbbb: je     d9d <generic_rawtp_process_filter+0xd9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3485ULL;
	}
x86_l_bc1:
	/* 0xbc1: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_bc4:
	/* 0xbc4: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bc6:
	/* 0xbc6: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_bcb:
	/* 0xbcb: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_bce:
	/* 0xbce: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3528ULL;
	}
x86_l_bd4:
	/* 0xbd4: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bd7:
	/* 0xbd7: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_bda:
	/* 0xbda: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3528ULL;
	}
x86_l_be0:
	/* 0xbe0: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_be4:
	/* 0xbe4: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_beb:
	/* 0xbeb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bf0:
	/* 0xbf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf2:
	/* 0xbf2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bf5:
	/* 0xbf5: je     d9d <generic_rawtp_process_filter+0xd9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3485ULL;
	}
x86_l_bfb:
	/* 0xbfb: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_bfe:
	/* 0xbfe: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c00:
	/* 0xc00: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c05:
	/* 0xc05: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_c08:
	/* 0xc08: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3528ULL;
	}
x86_l_c0e:
	/* 0xc0e: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c11:
	/* 0xc11: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_c14:
	/* 0xc14: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3528ULL;
	}
x86_l_c1a:
	/* 0xc1a: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_c1e:
	/* 0xc1e: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_c25:
	/* 0xc25: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c2a:
	/* 0xc2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2c:
	/* 0xc2c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c2f:
	/* 0xc2f: je     d9d <generic_rawtp_process_filter+0xd9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3485ULL;
	}
x86_l_c35:
	/* 0xc35: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_c38:
	/* 0xc38: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c3a:
	/* 0xc3a: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c3f:
	/* 0xc3f: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3528ULL;
	}
x86_l_c45:
	/* 0xc45: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c48:
	/* 0xc48: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c4d:
	/* 0xc4d: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3528ULL;
	}
x86_l_c53:
	/* 0xc53: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_c57:
	/* 0xc57: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_c5e:
	/* 0xc5e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c63:
	/* 0xc63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c65:
	/* 0xc65: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c68:
	/* 0xc68: je     d9d <generic_rawtp_process_filter+0xd9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3485ULL;
	}
x86_l_c6e:
	/* 0xc6e: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_c71:
	/* 0xc71: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c73:
	/* 0xc73: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c78:
	/* 0xc78: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3528ULL;
	}
x86_l_c7e:
	/* 0xc7e: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c81:
	/* 0xc81: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c86:
	/* 0xc86: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3528ULL;
	}
x86_l_c8c:
	/* 0xc8c: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_c90:
	/* 0xc90: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_c97:
	/* 0xc97: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c9c:
	/* 0xc9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c9e:
	/* 0xc9e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ca1:
	/* 0xca1: je     d9d <generic_rawtp_process_filter+0xd9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3485ULL;
	}
x86_l_ca7:
	/* 0xca7: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_caa:
	/* 0xcaa: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cac:
	/* 0xcac: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cb1:
	/* 0xcb1: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3528ULL;
	}
x86_l_cb7:
	/* 0xcb7: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cba:
	/* 0xcba: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cbf:
	/* 0xcbf: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3528ULL;
	}
x86_l_cc5:
	/* 0xcc5: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_cc9:
	/* 0xcc9: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_cd0:
	/* 0xcd0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
	return 3285ULL;
}

static __noinline __u64 tetragon_bpf_generic_rawtp_generic_rawtp_process_filter_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3285ULL: goto x86_l_cd5;
	case 3287ULL: goto x86_l_cd7;
	case 3290ULL: goto x86_l_cda;
	case 3296ULL: goto x86_l_ce0;
	case 3299ULL: goto x86_l_ce3;
	case 3301ULL: goto x86_l_ce5;
	case 3306ULL: goto x86_l_cea;
	case 3312ULL: goto x86_l_cf0;
	case 3315ULL: goto x86_l_cf3;
	case 3320ULL: goto x86_l_cf8;
	case 3326ULL: goto x86_l_cfe;
	case 3330ULL: goto x86_l_d02;
	case 3337ULL: goto x86_l_d09;
	case 3342ULL: goto x86_l_d0e;
	case 3344ULL: goto x86_l_d10;
	case 3347ULL: goto x86_l_d13;
	case 3353ULL: goto x86_l_d19;
	case 3356ULL: goto x86_l_d1c;
	case 3358ULL: goto x86_l_d1e;
	case 3363ULL: goto x86_l_d23;
	case 3369ULL: goto x86_l_d29;
	case 3372ULL: goto x86_l_d2c;
	case 3377ULL: goto x86_l_d31;
	case 3383ULL: goto x86_l_d37;
	case 3387ULL: goto x86_l_d3b;
	case 3394ULL: goto x86_l_d42;
	case 3399ULL: goto x86_l_d47;
	case 3401ULL: goto x86_l_d49;
	case 3404ULL: goto x86_l_d4c;
	case 3406ULL: goto x86_l_d4e;
	case 3409ULL: goto x86_l_d51;
	case 3411ULL: goto x86_l_d53;
	case 3416ULL: goto x86_l_d58;
	case 3418ULL: goto x86_l_d5a;
	case 3421ULL: goto x86_l_d5d;
	case 3426ULL: goto x86_l_d62;
	case 3429ULL: goto x86_l_d65;
	case 3434ULL: goto x86_l_d6a;
	case 3439ULL: goto x86_l_d6f;
	case 3444ULL: goto x86_l_d74;
	case 3449ULL: goto x86_l_d79;
	case 3454ULL: goto x86_l_d7e;
	case 3458ULL: goto x86_l_d82;
	case 3460ULL: goto x86_l_d84;
	case 3464ULL: goto x86_l_d88;
	case 3471ULL: goto x86_l_d8f;
	case 3476ULL: goto x86_l_d94;
	case 3483ULL: goto x86_l_d9b;
	case 3485ULL: goto x86_l_d9d;
	case 3488ULL: goto x86_l_da0;
	case 3493ULL: goto x86_l_da5;
	case 3497ULL: goto x86_l_da9;
	case 3500ULL: goto x86_l_dac;
	case 3505ULL: goto x86_l_db1;
	case 3510ULL: goto x86_l_db6;
	case 3515ULL: goto x86_l_dbb;
	case 3520ULL: goto x86_l_dc0;
	case 3524ULL: goto x86_l_dc4;
	case 3526ULL: goto x86_l_dc6;
	case 3528ULL: goto x86_l_dc8;
	case 3531ULL: goto x86_l_dcb;
	case 3536ULL: goto x86_l_dd0;
	case 3541ULL: goto x86_l_dd5;
	case 3546ULL: goto x86_l_dda;
	case 3551ULL: goto x86_l_ddf;
	case 3556ULL: goto x86_l_de4;
	case 3560ULL: goto x86_l_de8;
	case 3564ULL: goto x86_l_dec;
	case 3567ULL: goto x86_l_def;
	case 3571ULL: goto x86_l_df3;
	case 3574ULL: goto x86_l_df6;
	case 3578ULL: goto x86_l_dfa;
	case 3582ULL: goto x86_l_dfe;
	case 3585ULL: goto x86_l_e01;
	case 3589ULL: goto x86_l_e05;
	case 3595ULL: goto x86_l_e0b;
	case 3598ULL: goto x86_l_e0e;
	case 3602ULL: goto x86_l_e12;
	case 3608ULL: goto x86_l_e18;
	case 3610ULL: goto x86_l_e1a;
	case 3613ULL: goto x86_l_e1d;
	case 3618ULL: goto x86_l_e22;
	case 3620ULL: goto x86_l_e24;
	case 3623ULL: goto x86_l_e27;
	case 3625ULL: goto x86_l_e29;
	case 3628ULL: goto x86_l_e2c;
	case 3631ULL: goto x86_l_e2f;
	case 3636ULL: goto x86_l_e34;
	case 3639ULL: goto x86_l_e37;
	case 3643ULL: goto x86_l_e3b;
	case 3645ULL: goto x86_l_e3d;
	case 3647ULL: goto x86_l_e3f;
	case 3651ULL: goto x86_l_e43;
	case 3656ULL: goto x86_l_e48;
	case 3658ULL: goto x86_l_e4a;
	case 3661ULL: goto x86_l_e4d;
	case 3667ULL: goto x86_l_e53;
	case 3670ULL: goto x86_l_e56;
	case 3673ULL: goto x86_l_e59;
	case 3677ULL: goto x86_l_e5d;
	case 3681ULL: goto x86_l_e61;
	case 3686ULL: goto x86_l_e66;
	case 3692ULL: goto x86_l_e6c;
	case 3698ULL: goto x86_l_e72;
	case 3700ULL: goto x86_l_e74;
	case 3703ULL: goto x86_l_e77;
	case 3708ULL: goto x86_l_e7c;
	case 3714ULL: goto x86_l_e82;
	case 3717ULL: goto x86_l_e85;
	case 3720ULL: goto x86_l_e88;
	case 3726ULL: goto x86_l_e8e;
	case 3729ULL: goto x86_l_e91;
	case 3735ULL: goto x86_l_e97;
	case 3739ULL: goto x86_l_e9b;
	case 3744ULL: goto x86_l_ea0;
	case 3749ULL: goto x86_l_ea5;
	case 3754ULL: goto x86_l_eaa;
	case 3759ULL: goto x86_l_eaf;
	case 3763ULL: goto x86_l_eb3;
	case 3770ULL: goto x86_l_eba;
	case 3775ULL: goto x86_l_ebf;
	case 3777ULL: goto x86_l_ec1;
	case 3780ULL: goto x86_l_ec4;
	case 3786ULL: goto x86_l_eca;
	case 3789ULL: goto x86_l_ecd;
	case 3792ULL: goto x86_l_ed0;
	case 3797ULL: goto x86_l_ed5;
	case 3803ULL: goto x86_l_edb;
	case 3807ULL: goto x86_l_edf;
	case 3814ULL: goto x86_l_ee6;
	case 3819ULL: goto x86_l_eeb;
	case 3821ULL: goto x86_l_eed;
	case 3824ULL: goto x86_l_ef0;
	case 3830ULL: goto x86_l_ef6;
	case 3833ULL: goto x86_l_ef9;
	case 3836ULL: goto x86_l_efc;
	case 3841ULL: goto x86_l_f01;
	case 3847ULL: goto x86_l_f07;
	case 3851ULL: goto x86_l_f0b;
	case 3858ULL: goto x86_l_f12;
	case 3863ULL: goto x86_l_f17;
	case 3865ULL: goto x86_l_f19;
	case 3868ULL: goto x86_l_f1c;
	case 3874ULL: goto x86_l_f22;
	case 3877ULL: goto x86_l_f25;
	case 3880ULL: goto x86_l_f28;
	case 3885ULL: goto x86_l_f2d;
	case 3891ULL: goto x86_l_f33;
	case 3895ULL: goto x86_l_f37;
	case 3902ULL: goto x86_l_f3e;
	case 3907ULL: goto x86_l_f43;
	case 3909ULL: goto x86_l_f45;
	case 3912ULL: goto x86_l_f48;
	case 3918ULL: goto x86_l_f4e;
	case 3921ULL: goto x86_l_f51;
	case 3924ULL: goto x86_l_f54;
	case 3929ULL: goto x86_l_f59;
	case 3935ULL: goto x86_l_f5f;
	case 3939ULL: goto x86_l_f63;
	case 3946ULL: goto x86_l_f6a;
	case 3951ULL: goto x86_l_f6f;
	case 3953ULL: goto x86_l_f71;
	case 3956ULL: goto x86_l_f74;
	case 3962ULL: goto x86_l_f7a;
	case 3965ULL: goto x86_l_f7d;
	case 3968ULL: goto x86_l_f80;
	case 3973ULL: goto x86_l_f85;
	case 3979ULL: goto x86_l_f8b;
	case 3983ULL: goto x86_l_f8f;
	case 3990ULL: goto x86_l_f96;
	case 3995ULL: goto x86_l_f9b;
	case 3997ULL: goto x86_l_f9d;
	case 4000ULL: goto x86_l_fa0;
	case 4006ULL: goto x86_l_fa6;
	case 4009ULL: goto x86_l_fa9;
	case 4012ULL: goto x86_l_fac;
	case 4017ULL: goto x86_l_fb1;
	case 4023ULL: goto x86_l_fb7;
	case 4027ULL: goto x86_l_fbb;
	case 4034ULL: goto x86_l_fc2;
	case 4039ULL: goto x86_l_fc7;
	case 4041ULL: goto x86_l_fc9;
	case 4044ULL: goto x86_l_fcc;
	case 4050ULL: goto x86_l_fd2;
	case 4053ULL: goto x86_l_fd5;
	case 4056ULL: goto x86_l_fd8;
	case 4061ULL: goto x86_l_fdd;
	case 4067ULL: goto x86_l_fe3;
	case 4071ULL: goto x86_l_fe7;
	case 4078ULL: goto x86_l_fee;
	case 4083ULL: goto x86_l_ff3;
	case 4085ULL: goto x86_l_ff5;
	case 4088ULL: goto x86_l_ff8;
	case 4094ULL: goto x86_l_ffe;
	case 4097ULL: goto x86_l_1001;
	case 4100ULL: goto x86_l_1004;
	case 4105ULL: goto x86_l_1009;
	case 4108ULL: goto x86_l_100c;
	case 4113ULL: goto x86_l_1011;
	case 4118ULL: goto x86_l_1016;
	case 4123ULL: goto x86_l_101b;
	case 4128ULL: goto x86_l_1020;
	case 4133ULL: goto x86_l_1025;
	case 4137ULL: goto x86_l_1029;
	case 4143ULL: goto x86_l_102f;
	case 4147ULL: goto x86_l_1033;
	case 4154ULL: goto x86_l_103a;
	case 4159ULL: goto x86_l_103f;
	case 4164ULL: goto x86_l_1044;
	case 4167ULL: goto x86_l_1047;
	case 4172ULL: goto x86_l_104c;
	case 4174ULL: goto x86_l_104e;
	case 4177ULL: goto x86_l_1051;
	case 4182ULL: goto x86_l_1056;
	case 4185ULL: goto x86_l_1059;
	case 4191ULL: goto x86_l_105f;
	case 4194ULL: goto x86_l_1062;
	case 4197ULL: goto x86_l_1065;
	case 4203ULL: goto x86_l_106b;
	case 4207ULL: goto x86_l_106f;
	case 4212ULL: goto x86_l_1074;
	case 4217ULL: goto x86_l_1079;
	case 4222ULL: goto x86_l_107e;
	case 4227ULL: goto x86_l_1083;
	case 4231ULL: goto x86_l_1087;
	case 4238ULL: goto x86_l_108e;
	case 4243ULL: goto x86_l_1093;
	case 4245ULL: goto x86_l_1095;
	case 4248ULL: goto x86_l_1098;
	case 4254ULL: goto x86_l_109e;
	case 4257ULL: goto x86_l_10a1;
	case 4259ULL: goto x86_l_10a3;
	case 4264ULL: goto x86_l_10a8;
	case 4267ULL: goto x86_l_10ab;
	case 4273ULL: goto x86_l_10b1;
	case 4276ULL: goto x86_l_10b4;
	case 4279ULL: goto x86_l_10b7;
	case 4285ULL: goto x86_l_10bd;
	case 4289ULL: goto x86_l_10c1;
	case 4296ULL: goto x86_l_10c8;
	case 4301ULL: goto x86_l_10cd;
	case 4303ULL: goto x86_l_10cf;
	case 4306ULL: goto x86_l_10d2;
	case 4312ULL: goto x86_l_10d8;
	case 4315ULL: goto x86_l_10db;
	case 4317ULL: goto x86_l_10dd;
	case 4322ULL: goto x86_l_10e2;
	case 4325ULL: goto x86_l_10e5;
	case 4331ULL: goto x86_l_10eb;
	case 4334ULL: goto x86_l_10ee;
	case 4337ULL: goto x86_l_10f1;
	case 4343ULL: goto x86_l_10f7;
	case 4347ULL: goto x86_l_10fb;
	case 4354ULL: goto x86_l_1102;
	case 4359ULL: goto x86_l_1107;
	case 4361ULL: goto x86_l_1109;
	case 4364ULL: goto x86_l_110c;
	case 4370ULL: goto x86_l_1112;
	case 4373ULL: goto x86_l_1115;
	case 4375ULL: goto x86_l_1117;
	case 4380ULL: goto x86_l_111c;
	case 4386ULL: goto x86_l_1122;
	case 4389ULL: goto x86_l_1125;
	case 4394ULL: goto x86_l_112a;
	case 4400ULL: goto x86_l_1130;
	case 4404ULL: goto x86_l_1134;
	case 4411ULL: goto x86_l_113b;
	case 4416ULL: goto x86_l_1140;
	case 4418ULL: goto x86_l_1142;
	case 4421ULL: goto x86_l_1145;
	case 4427ULL: goto x86_l_114b;
	case 4430ULL: goto x86_l_114e;
	case 4432ULL: goto x86_l_1150;
	case 4437ULL: goto x86_l_1155;
	case 4443ULL: goto x86_l_115b;
	case 4446ULL: goto x86_l_115e;
	case 4451ULL: goto x86_l_1163;
	case 4457ULL: goto x86_l_1169;
	case 4461ULL: goto x86_l_116d;
	case 4468ULL: goto x86_l_1174;
	case 4473ULL: goto x86_l_1179;
	case 4475ULL: goto x86_l_117b;
	case 4478ULL: goto x86_l_117e;
	case 4484ULL: goto x86_l_1184;
	case 4487ULL: goto x86_l_1187;
	case 4489ULL: goto x86_l_1189;
	case 4494ULL: goto x86_l_118e;
	case 4500ULL: goto x86_l_1194;
	case 4503ULL: goto x86_l_1197;
	case 4508ULL: goto x86_l_119c;
	case 4514ULL: goto x86_l_11a2;
	case 4518ULL: goto x86_l_11a6;
	case 4525ULL: goto x86_l_11ad;
	case 4530ULL: goto x86_l_11b2;
	case 4532ULL: goto x86_l_11b4;
	case 4535ULL: goto x86_l_11b7;
	case 4541ULL: goto x86_l_11bd;
	case 4544ULL: goto x86_l_11c0;
	case 4546ULL: goto x86_l_11c2;
	case 4551ULL: goto x86_l_11c7;
	case 4557ULL: goto x86_l_11cd;
	case 4560ULL: goto x86_l_11d0;
	case 4565ULL: goto x86_l_11d5;
	case 4571ULL: goto x86_l_11db;
	case 4575ULL: goto x86_l_11df;
	case 4582ULL: goto x86_l_11e6;
	case 4587ULL: goto x86_l_11eb;
	case 4589ULL: goto x86_l_11ed;
	case 4592ULL: goto x86_l_11f0;
	case 4598ULL: goto x86_l_11f6;
	case 4601ULL: goto x86_l_11f9;
	case 4603ULL: goto x86_l_11fb;
	case 4608ULL: goto x86_l_1200;
	case 4614ULL: goto x86_l_1206;
	case 4617ULL: goto x86_l_1209;
	case 4622ULL: goto x86_l_120e;
	case 4628ULL: goto x86_l_1214;
	case 4632ULL: goto x86_l_1218;
	case 4639ULL: goto x86_l_121f;
	case 4644ULL: goto x86_l_1224;
	case 4646ULL: goto x86_l_1226;
	case 4649ULL: goto x86_l_1229;
	case 4651ULL: goto x86_l_122b;
	case 4654ULL: goto x86_l_122e;
	case 4656ULL: goto x86_l_1230;
	case 4661ULL: goto x86_l_1235;
	case 4663ULL: goto x86_l_1237;
	case 4666ULL: goto x86_l_123a;
	case 4671ULL: goto x86_l_123f;
	case 4674ULL: goto x86_l_1242;
	case 4679ULL: goto x86_l_1247;
	case 4684ULL: goto x86_l_124c;
	case 4689ULL: goto x86_l_1251;
	case 4694ULL: goto x86_l_1256;
	case 4699ULL: goto x86_l_125b;
	case 4703ULL: goto x86_l_125f;
	case 4705ULL: goto x86_l_1261;
	case 4709ULL: goto x86_l_1265;
	case 4716ULL: goto x86_l_126c;
	case 4721ULL: goto x86_l_1271;
	case 4728ULL: goto x86_l_1278;
	case 4730ULL: goto x86_l_127a;
	case 4733ULL: goto x86_l_127d;
	case 4738ULL: goto x86_l_1282;
	case 4742ULL: goto x86_l_1286;
	case 4745ULL: goto x86_l_1289;
	case 4750ULL: goto x86_l_128e;
	case 4755ULL: goto x86_l_1293;
	case 4760ULL: goto x86_l_1298;
	case 4765ULL: goto x86_l_129d;
	case 4769ULL: goto x86_l_12a1;
	case 4771ULL: goto x86_l_12a3;
	case 4773ULL: goto x86_l_12a5;
	case 4776ULL: goto x86_l_12a8;
	case 4781ULL: goto x86_l_12ad;
	case 4786ULL: goto x86_l_12b2;
	case 4791ULL: goto x86_l_12b7;
	case 4796ULL: goto x86_l_12bc;
	case 4801ULL: goto x86_l_12c1;
	case 4805ULL: goto x86_l_12c5;
	case 4809ULL: goto x86_l_12c9;
	case 4812ULL: goto x86_l_12cc;
	case 4816ULL: goto x86_l_12d0;
	case 4819ULL: goto x86_l_12d3;
	case 4823ULL: goto x86_l_12d7;
	case 4826ULL: goto x86_l_12da;
	case 4830ULL: goto x86_l_12de;
	case 4836ULL: goto x86_l_12e4;
	case 4839ULL: goto x86_l_12e7;
	case 4843ULL: goto x86_l_12eb;
	case 4849ULL: goto x86_l_12f1;
	case 4851ULL: goto x86_l_12f3;
	case 4853ULL: goto x86_l_12f5;
	case 4855ULL: goto x86_l_12f7;
	case 4858ULL: goto x86_l_12fa;
	case 4861ULL: goto x86_l_12fd;
	case 4866ULL: goto x86_l_1302;
	case 4870ULL: goto x86_l_1306;
	case 4872ULL: goto x86_l_1308;
	case 4874ULL: goto x86_l_130a;
	case 4878ULL: goto x86_l_130e;
	case 4883ULL: goto x86_l_1313;
	case 4885ULL: goto x86_l_1315;
	case 4887ULL: goto x86_l_1317;
	default: return 0xffffffffffffffffULL;
	}
x86_l_cd5:
	/* 0xcd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd7:
	/* 0xcd7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cda:
	/* 0xcda: je     d9d <generic_rawtp_process_filter+0xd9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d9d;
	}
x86_l_ce0:
	/* 0xce0: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_ce3:
	/* 0xce3: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce5:
	/* 0xce5: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cea:
	/* 0xcea: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dc8;
	}
x86_l_cf0:
	/* 0xcf0: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cf3:
	/* 0xcf3: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cf8:
	/* 0xcf8: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dc8;
	}
x86_l_cfe:
	/* 0xcfe: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d02:
	/* 0xd02: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_d09:
	/* 0xd09: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d0e:
	/* 0xd0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d10:
	/* 0xd10: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d13:
	/* 0xd13: je     d9d <generic_rawtp_process_filter+0xd9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d9d;
	}
x86_l_d19:
	/* 0xd19: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d1c:
	/* 0xd1c: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d1e:
	/* 0xd1e: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d23:
	/* 0xd23: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dc8;
	}
x86_l_d29:
	/* 0xd29: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d2c:
	/* 0xd2c: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d31:
	/* 0xd31: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dc8;
	}
x86_l_d37:
	/* 0xd37: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d3b:
	/* 0xd3b: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_d42:
	/* 0xd42: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d47:
	/* 0xd47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d49:
	/* 0xd49: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d4c:
	/* 0xd4c: je     d9d <generic_rawtp_process_filter+0xd9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d9d;
	}
x86_l_d4e:
	/* 0xd4e: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d51:
	/* 0xd51: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d53:
	/* 0xd53: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d58:
	/* 0xd58: je     dc8 <generic_rawtp_process_filter+0xdc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dc8;
	}
x86_l_d5a:
	/* 0xd5a: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d5d:
	/* 0xd5d: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d62:
	/* 0xd62: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_d65:
	/* 0xd65: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d6a:
	/* 0xd6a: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d6f:
	/* 0xd6f: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d74:
	/* 0xd74: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d79:
	/* 0xd79: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d7e:
	/* 0xd7e: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_d82:
	/* 0xd82: je     de8 <generic_rawtp_process_filter+0xde8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_de8;
	}
x86_l_d84:
	/* 0xd84: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d88:
	/* 0xd88: mov    rcx,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_d8f:
	/* 0xd8f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d94:
	/* 0xd94: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_d9b:
	/* 0xd9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d9d:
	/* 0xd9d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_da0:
	/* 0xda0: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_da5:
	/* 0xda5: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_da9:
	/* 0xda9: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_dac:
	/* 0xdac: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_db1:
	/* 0xdb1: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_db6:
	/* 0xdb6: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dbb:
	/* 0xdbb: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_dc0:
	/* 0xdc0: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_dc4:
	/* 0xdc4: jne    de8 <generic_rawtp_process_filter+0xde8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_de8;
	}
x86_l_dc6:
	/* 0xdc6: jmp    df6 <generic_rawtp_process_filter+0xdf6> */
	goto x86_l_df6;
x86_l_dc8:
	/* 0xdc8: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_dcb:
	/* 0xdcb: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dd0:
	/* 0xdd0: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dd5:
	/* 0xdd5: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dda:
	/* 0xdda: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ddf:
	/* 0xddf: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_de4:
	/* 0xde4: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_de8:
	/* 0xde8: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_dec:
	/* 0xdec: setne  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_NE);
x86_l_def:
	/* 0xdef: xor    r12b,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_df3:
	/* 0xdf3: or     r12b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_df6:
	/* 0xdf6: movzx  edx,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_dfa:
	/* 0xdfa: mov    DWORD PTR [rsp+0x50],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_dfe:
	/* 0xdfe: add    ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_e01:
	/* 0xe01: lea    rdx,[rcx+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e05:
	/* 0xe05: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_e0b:
	/* 0xe0b: mov    rsi,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_e0e:
	/* 0xe0e: cmove  rsi,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_e12:
	/* 0xe12: cmp    ebp,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1000ULL);
x86_l_e18:
	/* 0xe18: jbe    e24 <generic_rawtp_process_filter+0xe24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e24;
	}
x86_l_e1a:
	/* 0xe1a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e1d:
	/* 0xe1d: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e22:
	/* 0xe22: jmp    e37 <generic_rawtp_process_filter+0xe37> */
	goto x86_l_e37;
x86_l_e24:
	/* 0xe24: mov    r12d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_32);
x86_l_e27:
	/* 0xe27: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_e29:
	/* 0xe29: and    edi,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_e2c:
	/* 0xe2c: mov    edi,DWORD PTR [rax+rdi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_e2f:
	/* 0xe2f: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e34:
	/* 0xe34: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_e37:
	/* 0xe37: test   r10b,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R10, X86_WIDTH_8, 2ULL);
x86_l_e3b:
	/* 0xe3b: jne    e66 <generic_rawtp_process_filter+0xe66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e66;
	}
x86_l_e3d:
	/* 0xe3d: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e3f:
	/* 0xe3f: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_e43:
	/* 0xe43: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e48:
	/* 0xe48: jne    e53 <generic_rawtp_process_filter+0xe53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e53;
	}
x86_l_e4a:
	/* 0xe4a: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_e4d:
	/* 0xe4d: jne    1044 <generic_rawtp_process_filter+0x1044> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1044;
	}
x86_l_e53:
	/* 0xe53: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_e56:
	/* 0xe56: setne  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_NE);
x86_l_e59:
	/* 0xe59: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_e5d:
	/* 0xe5d: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_e61:
	/* 0xe61: jmp    12d0 <generic_rawtp_process_filter+0x12d0> */
	goto x86_l_12d0;
x86_l_e66:
	/* 0xe66: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_e6c:
	/* 0xe6c: je     104c <generic_rawtp_process_filter+0x104c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_104c;
	}
x86_l_e72:
	/* 0xe72: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e74:
	/* 0xe74: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_e77:
	/* 0xe77: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e7c:
	/* 0xe7c: je     1044 <generic_rawtp_process_filter+0x1044> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1044;
	}
x86_l_e82:
	/* 0xe82: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_e85:
	/* 0xe85: test   rsi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_64);
x86_l_e88:
	/* 0xe88: je     12c5 <generic_rawtp_process_filter+0x12c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12c5;
	}
x86_l_e8e:
	/* 0xe8e: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_e91:
	/* 0xe91: je     12c5 <generic_rawtp_process_filter+0x12c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12c5;
	}
x86_l_e97:
	/* 0xe97: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_e9b:
	/* 0xe9b: mov    QWORD PTR [rsp+0x30],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ea0:
	/* 0xea0: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ea5:
	/* 0xea5: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eaa:
	/* 0xeaa: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_eaf:
	/* 0xeaf: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eb3:
	/* 0xeb3: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_eba:
	/* 0xeba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ebf:
	/* 0xebf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec1:
	/* 0xec1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ec4:
	/* 0xec4: je     127a <generic_rawtp_process_filter+0x127a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_127a;
	}
x86_l_eca:
	/* 0xeca: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_ecd:
	/* 0xecd: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ed0:
	/* 0xed0: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ed5:
	/* 0xed5: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_edb:
	/* 0xedb: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_edf:
	/* 0xedf: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_ee6:
	/* 0xee6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_eeb:
	/* 0xeeb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eed:
	/* 0xeed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ef0:
	/* 0xef0: je     127a <generic_rawtp_process_filter+0x127a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_127a;
	}
x86_l_ef6:
	/* 0xef6: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_ef9:
	/* 0xef9: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_efc:
	/* 0xefc: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f01:
	/* 0xf01: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_f07:
	/* 0xf07: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f0b:
	/* 0xf0b: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_f12:
	/* 0xf12: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f17:
	/* 0xf17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f19:
	/* 0xf19: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f1c:
	/* 0xf1c: je     127a <generic_rawtp_process_filter+0x127a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_127a;
	}
x86_l_f22:
	/* 0xf22: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f25:
	/* 0xf25: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f28:
	/* 0xf28: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f2d:
	/* 0xf2d: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_f33:
	/* 0xf33: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f37:
	/* 0xf37: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_f3e:
	/* 0xf3e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f43:
	/* 0xf43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f45:
	/* 0xf45: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f48:
	/* 0xf48: je     127a <generic_rawtp_process_filter+0x127a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_127a;
	}
x86_l_f4e:
	/* 0xf4e: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f51:
	/* 0xf51: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f54:
	/* 0xf54: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f59:
	/* 0xf59: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_f5f:
	/* 0xf5f: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f63:
	/* 0xf63: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_f6a:
	/* 0xf6a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f6f:
	/* 0xf6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f71:
	/* 0xf71: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f74:
	/* 0xf74: je     127a <generic_rawtp_process_filter+0x127a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_127a;
	}
x86_l_f7a:
	/* 0xf7a: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f7d:
	/* 0xf7d: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f80:
	/* 0xf80: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f85:
	/* 0xf85: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_f8b:
	/* 0xf8b: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f8f:
	/* 0xf8f: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_f96:
	/* 0xf96: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f9b:
	/* 0xf9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f9d:
	/* 0xf9d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fa0:
	/* 0xfa0: je     127a <generic_rawtp_process_filter+0x127a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_127a;
	}
x86_l_fa6:
	/* 0xfa6: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_fa9:
	/* 0xfa9: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_fac:
	/* 0xfac: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fb1:
	/* 0xfb1: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_fb7:
	/* 0xfb7: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_fbb:
	/* 0xfbb: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_fc2:
	/* 0xfc2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fc7:
	/* 0xfc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fc9:
	/* 0xfc9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fcc:
	/* 0xfcc: je     127a <generic_rawtp_process_filter+0x127a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_127a;
	}
x86_l_fd2:
	/* 0xfd2: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_fd5:
	/* 0xfd5: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_fd8:
	/* 0xfd8: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fdd:
	/* 0xfdd: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_fe3:
	/* 0xfe3: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_fe7:
	/* 0xfe7: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_fee:
	/* 0xfee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ff3:
	/* 0xff3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff5:
	/* 0xff5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ff8:
	/* 0xff8: je     127a <generic_rawtp_process_filter+0x127a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_127a;
	}
x86_l_ffe:
	/* 0xffe: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1001:
	/* 0x1001: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1004:
	/* 0x1004: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1009:
	/* 0x1009: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_100c:
	/* 0x100c: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1011:
	/* 0x1011: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1016:
	/* 0x1016: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_101b:
	/* 0x101b: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1020:
	/* 0x1020: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1025:
	/* 0x1025: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1029:
	/* 0x1029: je     12c5 <generic_rawtp_process_filter+0x12c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12c5;
	}
x86_l_102f:
	/* 0x102f: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1033:
	/* 0x1033: mov    rcx,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_103a:
	/* 0x103a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_103f:
	/* 0x103f: jmp    1271 <generic_rawtp_process_filter+0x1271> */
	goto x86_l_1271;
x86_l_1044:
	/* 0x1044: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1047:
	/* 0x1047: jmp    12d3 <generic_rawtp_process_filter+0x12d3> */
	goto x86_l_12d3;
x86_l_104c:
	/* 0x104c: mov    edx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_104e:
	/* 0x104e: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_1051:
	/* 0x1051: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1056:
	/* 0x1056: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1059:
	/* 0x1059: je     12c5 <generic_rawtp_process_filter+0x12c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12c5;
	}
x86_l_105f:
	/* 0x105f: mov    edx,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1062:
	/* 0x1062: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1065:
	/* 0x1065: je     12c5 <generic_rawtp_process_filter+0x12c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12c5;
	}
x86_l_106b:
	/* 0x106b: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_106f:
	/* 0x106f: mov    QWORD PTR [rsp+0x30],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1074:
	/* 0x1074: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1079:
	/* 0x1079: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_107e:
	/* 0x107e: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1083:
	/* 0x1083: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1087:
	/* 0x1087: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_108e:
	/* 0x108e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1093:
	/* 0x1093: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1095:
	/* 0x1095: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1098:
	/* 0x1098: je     127a <generic_rawtp_process_filter+0x127a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_127a;
	}
x86_l_109e:
	/* 0x109e: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_10a1:
	/* 0x10a1: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10a3:
	/* 0x10a3: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10a8:
	/* 0x10a8: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_10ab:
	/* 0x10ab: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_10b1:
	/* 0x10b1: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10b4:
	/* 0x10b4: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_10b7:
	/* 0x10b7: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_10bd:
	/* 0x10bd: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_10c1:
	/* 0x10c1: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_10c8:
	/* 0x10c8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10cd:
	/* 0x10cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10cf:
	/* 0x10cf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10d2:
	/* 0x10d2: je     127a <generic_rawtp_process_filter+0x127a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_127a;
	}
x86_l_10d8:
	/* 0x10d8: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_10db:
	/* 0x10db: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10dd:
	/* 0x10dd: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10e2:
	/* 0x10e2: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_10e5:
	/* 0x10e5: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_10eb:
	/* 0x10eb: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10ee:
	/* 0x10ee: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_10f1:
	/* 0x10f1: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_10f7:
	/* 0x10f7: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_10fb:
	/* 0x10fb: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1102:
	/* 0x1102: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1107:
	/* 0x1107: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1109:
	/* 0x1109: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_110c:
	/* 0x110c: je     127a <generic_rawtp_process_filter+0x127a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_127a;
	}
x86_l_1112:
	/* 0x1112: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1115:
	/* 0x1115: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1117:
	/* 0x1117: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_111c:
	/* 0x111c: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_1122:
	/* 0x1122: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1125:
	/* 0x1125: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_112a:
	/* 0x112a: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_1130:
	/* 0x1130: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1134:
	/* 0x1134: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_113b:
	/* 0x113b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1140:
	/* 0x1140: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1142:
	/* 0x1142: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1145:
	/* 0x1145: je     127a <generic_rawtp_process_filter+0x127a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_127a;
	}
x86_l_114b:
	/* 0x114b: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_114e:
	/* 0x114e: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1150:
	/* 0x1150: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1155:
	/* 0x1155: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_115b:
	/* 0x115b: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_115e:
	/* 0x115e: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1163:
	/* 0x1163: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_1169:
	/* 0x1169: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_116d:
	/* 0x116d: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1174:
	/* 0x1174: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1179:
	/* 0x1179: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_117b:
	/* 0x117b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_117e:
	/* 0x117e: je     127a <generic_rawtp_process_filter+0x127a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_127a;
	}
x86_l_1184:
	/* 0x1184: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1187:
	/* 0x1187: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1189:
	/* 0x1189: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_118e:
	/* 0x118e: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_1194:
	/* 0x1194: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1197:
	/* 0x1197: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_119c:
	/* 0x119c: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_11a2:
	/* 0x11a2: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_11a6:
	/* 0x11a6: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_11ad:
	/* 0x11ad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11b2:
	/* 0x11b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11b4:
	/* 0x11b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11b7:
	/* 0x11b7: je     127a <generic_rawtp_process_filter+0x127a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_127a;
	}
x86_l_11bd:
	/* 0x11bd: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_11c0:
	/* 0x11c0: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11c2:
	/* 0x11c2: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11c7:
	/* 0x11c7: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_11cd:
	/* 0x11cd: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11d0:
	/* 0x11d0: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11d5:
	/* 0x11d5: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_11db:
	/* 0x11db: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_11df:
	/* 0x11df: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_11e6:
	/* 0x11e6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11eb:
	/* 0x11eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ed:
	/* 0x11ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11f0:
	/* 0x11f0: je     127a <generic_rawtp_process_filter+0x127a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_127a;
	}
x86_l_11f6:
	/* 0x11f6: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_11f9:
	/* 0x11f9: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11fb:
	/* 0x11fb: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1200:
	/* 0x1200: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_1206:
	/* 0x1206: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1209:
	/* 0x1209: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_120e:
	/* 0x120e: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_1214:
	/* 0x1214: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1218:
	/* 0x1218: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_121f:
	/* 0x121f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1224:
	/* 0x1224: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1226:
	/* 0x1226: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1229:
	/* 0x1229: je     127a <generic_rawtp_process_filter+0x127a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_127a;
	}
x86_l_122b:
	/* 0x122b: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_122e:
	/* 0x122e: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1230:
	/* 0x1230: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1235:
	/* 0x1235: je     12a5 <generic_rawtp_process_filter+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a5;
	}
x86_l_1237:
	/* 0x1237: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_123a:
	/* 0x123a: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_123f:
	/* 0x123f: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1242:
	/* 0x1242: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1247:
	/* 0x1247: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_124c:
	/* 0x124c: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1251:
	/* 0x1251: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1256:
	/* 0x1256: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_125b:
	/* 0x125b: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_125f:
	/* 0x125f: je     12c5 <generic_rawtp_process_filter+0x12c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12c5;
	}
x86_l_1261:
	/* 0x1261: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1265:
	/* 0x1265: mov    rcx,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_126c:
	/* 0x126c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1271:
	/* 0x1271: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1278:
	/* 0x1278: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_127a:
	/* 0x127a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_127d:
	/* 0x127d: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1282:
	/* 0x1282: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1286:
	/* 0x1286: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1289:
	/* 0x1289: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_128e:
	/* 0x128e: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1293:
	/* 0x1293: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1298:
	/* 0x1298: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_129d:
	/* 0x129d: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_12a1:
	/* 0x12a1: jne    12c5 <generic_rawtp_process_filter+0x12c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_12c5;
	}
x86_l_12a3:
	/* 0x12a3: jmp    12d3 <generic_rawtp_process_filter+0x12d3> */
	goto x86_l_12d3;
x86_l_12a5:
	/* 0x12a5: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_12a8:
	/* 0x12a8: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12ad:
	/* 0x12ad: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12b2:
	/* 0x12b2: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12b7:
	/* 0x12b7: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12bc:
	/* 0x12bc: mov    r10,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12c1:
	/* 0x12c1: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_12c5:
	/* 0x12c5: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_12c9:
	/* 0x12c9: setne  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_NE);
x86_l_12cc:
	/* 0x12cc: xor    r12b,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_12d0:
	/* 0x12d0: or     r12b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_12d3:
	/* 0x12d3: movzx  r12d,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_12d7:
	/* 0x12d7: add    ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_12da:
	/* 0x12da: lea    rdx,[rcx+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_12de:
	/* 0x12de: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_12e4:
	/* 0x12e4: mov    rsi,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_12e7:
	/* 0x12e7: cmove  rsi,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_12eb:
	/* 0x12eb: cmp    ebp,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1000ULL);
x86_l_12f1:
	/* 0x12f1: jbe    12f7 <generic_rawtp_process_filter+0x12f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_12f7;
	}
x86_l_12f3:
	/* 0x12f3: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12f5:
	/* 0x12f5: jmp    12fd <generic_rawtp_process_filter+0x12fd> */
	goto x86_l_12fd;
x86_l_12f7:
	/* 0x12f7: and    ebp,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_12fa:
	/* 0x12fa: mov    ebp,DWORD PTR [rax+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_12fd:
	/* 0x12fd: mov    QWORD PTR [rsp+0x28],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1302:
	/* 0x1302: test   r10b,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R10, X86_WIDTH_8, 2ULL);
x86_l_1306:
	/* 0x1306: jne    1333 <generic_rawtp_process_filter+0x1333> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4915ULL;
	}
x86_l_1308:
	/* 0x1308: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_130a:
	/* 0x130a: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_130e:
	/* 0x130e: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1313:
	/* 0x1313: jne    1320 <generic_rawtp_process_filter+0x1320> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4896ULL;
	}
x86_l_1315:
	/* 0x1315: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1317:
	/* 0x1317: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
	return 4890ULL;
}

static __noinline __u64 tetragon_bpf_generic_rawtp_generic_rawtp_process_filter_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4890ULL: goto x86_l_131a;
	case 4896ULL: goto x86_l_1320;
	case 4899ULL: goto x86_l_1323;
	case 4902ULL: goto x86_l_1326;
	case 4906ULL: goto x86_l_132a;
	case 4910ULL: goto x86_l_132e;
	case 4915ULL: goto x86_l_1333;
	case 4921ULL: goto x86_l_1339;
	case 4926ULL: goto x86_l_133e;
	case 4932ULL: goto x86_l_1344;
	case 4934ULL: goto x86_l_1346;
	case 4937ULL: goto x86_l_1349;
	case 4943ULL: goto x86_l_134f;
	case 4946ULL: goto x86_l_1352;
	case 4949ULL: goto x86_l_1355;
	case 4955ULL: goto x86_l_135b;
	case 4958ULL: goto x86_l_135e;
	case 4964ULL: goto x86_l_1364;
	case 4968ULL: goto x86_l_1368;
	case 4973ULL: goto x86_l_136d;
	case 4978ULL: goto x86_l_1372;
	case 4983ULL: goto x86_l_1377;
	case 4987ULL: goto x86_l_137b;
	case 4994ULL: goto x86_l_1382;
	case 4999ULL: goto x86_l_1387;
	case 5001ULL: goto x86_l_1389;
	case 5004ULL: goto x86_l_138c;
	case 5010ULL: goto x86_l_1392;
	case 5013ULL: goto x86_l_1395;
	case 5016ULL: goto x86_l_1398;
	case 5021ULL: goto x86_l_139d;
	case 5027ULL: goto x86_l_13a3;
	case 5031ULL: goto x86_l_13a7;
	case 5038ULL: goto x86_l_13ae;
	case 5043ULL: goto x86_l_13b3;
	case 5045ULL: goto x86_l_13b5;
	case 5048ULL: goto x86_l_13b8;
	case 5054ULL: goto x86_l_13be;
	case 5057ULL: goto x86_l_13c1;
	case 5060ULL: goto x86_l_13c4;
	case 5065ULL: goto x86_l_13c9;
	case 5071ULL: goto x86_l_13cf;
	case 5075ULL: goto x86_l_13d3;
	case 5082ULL: goto x86_l_13da;
	case 5087ULL: goto x86_l_13df;
	case 5089ULL: goto x86_l_13e1;
	case 5092ULL: goto x86_l_13e4;
	case 5098ULL: goto x86_l_13ea;
	case 5101ULL: goto x86_l_13ed;
	case 5104ULL: goto x86_l_13f0;
	case 5109ULL: goto x86_l_13f5;
	case 5115ULL: goto x86_l_13fb;
	case 5119ULL: goto x86_l_13ff;
	case 5126ULL: goto x86_l_1406;
	case 5131ULL: goto x86_l_140b;
	case 5133ULL: goto x86_l_140d;
	case 5136ULL: goto x86_l_1410;
	case 5142ULL: goto x86_l_1416;
	case 5145ULL: goto x86_l_1419;
	case 5148ULL: goto x86_l_141c;
	case 5153ULL: goto x86_l_1421;
	case 5159ULL: goto x86_l_1427;
	case 5163ULL: goto x86_l_142b;
	case 5170ULL: goto x86_l_1432;
	case 5175ULL: goto x86_l_1437;
	case 5177ULL: goto x86_l_1439;
	case 5180ULL: goto x86_l_143c;
	case 5186ULL: goto x86_l_1442;
	case 5189ULL: goto x86_l_1445;
	case 5192ULL: goto x86_l_1448;
	case 5197ULL: goto x86_l_144d;
	case 5203ULL: goto x86_l_1453;
	case 5207ULL: goto x86_l_1457;
	case 5214ULL: goto x86_l_145e;
	case 5219ULL: goto x86_l_1463;
	case 5221ULL: goto x86_l_1465;
	case 5224ULL: goto x86_l_1468;
	case 5230ULL: goto x86_l_146e;
	case 5233ULL: goto x86_l_1471;
	case 5236ULL: goto x86_l_1474;
	case 5241ULL: goto x86_l_1479;
	case 5247ULL: goto x86_l_147f;
	case 5251ULL: goto x86_l_1483;
	case 5258ULL: goto x86_l_148a;
	case 5263ULL: goto x86_l_148f;
	case 5265ULL: goto x86_l_1491;
	case 5268ULL: goto x86_l_1494;
	case 5274ULL: goto x86_l_149a;
	case 5277ULL: goto x86_l_149d;
	case 5280ULL: goto x86_l_14a0;
	case 5285ULL: goto x86_l_14a5;
	case 5291ULL: goto x86_l_14ab;
	case 5295ULL: goto x86_l_14af;
	case 5302ULL: goto x86_l_14b6;
	case 5307ULL: goto x86_l_14bb;
	case 5309ULL: goto x86_l_14bd;
	case 5312ULL: goto x86_l_14c0;
	case 5318ULL: goto x86_l_14c6;
	case 5321ULL: goto x86_l_14c9;
	case 5324ULL: goto x86_l_14cc;
	case 5329ULL: goto x86_l_14d1;
	case 5332ULL: goto x86_l_14d4;
	case 5337ULL: goto x86_l_14d9;
	case 5342ULL: goto x86_l_14de;
	case 5347ULL: goto x86_l_14e3;
	case 5352ULL: goto x86_l_14e8;
	case 5356ULL: goto x86_l_14ec;
	case 5362ULL: goto x86_l_14f2;
	case 5366ULL: goto x86_l_14f6;
	case 5373ULL: goto x86_l_14fd;
	case 5378ULL: goto x86_l_1502;
	case 5383ULL: goto x86_l_1507;
	case 5385ULL: goto x86_l_1509;
	case 5388ULL: goto x86_l_150c;
	case 5391ULL: goto x86_l_150f;
	case 5397ULL: goto x86_l_1515;
	case 5400ULL: goto x86_l_1518;
	case 5403ULL: goto x86_l_151b;
	case 5409ULL: goto x86_l_1521;
	case 5413ULL: goto x86_l_1525;
	case 5418ULL: goto x86_l_152a;
	case 5423ULL: goto x86_l_152f;
	case 5428ULL: goto x86_l_1534;
	case 5432ULL: goto x86_l_1538;
	case 5439ULL: goto x86_l_153f;
	case 5444ULL: goto x86_l_1544;
	case 5446ULL: goto x86_l_1546;
	case 5449ULL: goto x86_l_1549;
	case 5455ULL: goto x86_l_154f;
	case 5458ULL: goto x86_l_1552;
	case 5460ULL: goto x86_l_1554;
	case 5465ULL: goto x86_l_1559;
	case 5468ULL: goto x86_l_155c;
	case 5474ULL: goto x86_l_1562;
	case 5477ULL: goto x86_l_1565;
	case 5480ULL: goto x86_l_1568;
	case 5486ULL: goto x86_l_156e;
	case 5490ULL: goto x86_l_1572;
	case 5497ULL: goto x86_l_1579;
	case 5502ULL: goto x86_l_157e;
	case 5504ULL: goto x86_l_1580;
	case 5507ULL: goto x86_l_1583;
	case 5513ULL: goto x86_l_1589;
	case 5516ULL: goto x86_l_158c;
	case 5518ULL: goto x86_l_158e;
	case 5523ULL: goto x86_l_1593;
	case 5526ULL: goto x86_l_1596;
	case 5532ULL: goto x86_l_159c;
	case 5535ULL: goto x86_l_159f;
	case 5538ULL: goto x86_l_15a2;
	case 5544ULL: goto x86_l_15a8;
	case 5548ULL: goto x86_l_15ac;
	case 5555ULL: goto x86_l_15b3;
	case 5560ULL: goto x86_l_15b8;
	case 5562ULL: goto x86_l_15ba;
	case 5565ULL: goto x86_l_15bd;
	case 5571ULL: goto x86_l_15c3;
	case 5574ULL: goto x86_l_15c6;
	case 5576ULL: goto x86_l_15c8;
	case 5581ULL: goto x86_l_15cd;
	case 5584ULL: goto x86_l_15d0;
	case 5590ULL: goto x86_l_15d6;
	case 5593ULL: goto x86_l_15d9;
	case 5596ULL: goto x86_l_15dc;
	case 5602ULL: goto x86_l_15e2;
	case 5606ULL: goto x86_l_15e6;
	case 5613ULL: goto x86_l_15ed;
	case 5618ULL: goto x86_l_15f2;
	case 5620ULL: goto x86_l_15f4;
	case 5623ULL: goto x86_l_15f7;
	case 5629ULL: goto x86_l_15fd;
	case 5632ULL: goto x86_l_1600;
	case 5634ULL: goto x86_l_1602;
	case 5639ULL: goto x86_l_1607;
	case 5645ULL: goto x86_l_160d;
	case 5648ULL: goto x86_l_1610;
	case 5653ULL: goto x86_l_1615;
	case 5659ULL: goto x86_l_161b;
	case 5663ULL: goto x86_l_161f;
	case 5670ULL: goto x86_l_1626;
	case 5675ULL: goto x86_l_162b;
	case 5677ULL: goto x86_l_162d;
	case 5680ULL: goto x86_l_1630;
	case 5686ULL: goto x86_l_1636;
	case 5689ULL: goto x86_l_1639;
	case 5691ULL: goto x86_l_163b;
	case 5696ULL: goto x86_l_1640;
	case 5702ULL: goto x86_l_1646;
	case 5705ULL: goto x86_l_1649;
	case 5710ULL: goto x86_l_164e;
	case 5716ULL: goto x86_l_1654;
	case 5720ULL: goto x86_l_1658;
	case 5727ULL: goto x86_l_165f;
	case 5732ULL: goto x86_l_1664;
	case 5734ULL: goto x86_l_1666;
	case 5737ULL: goto x86_l_1669;
	case 5743ULL: goto x86_l_166f;
	case 5746ULL: goto x86_l_1672;
	case 5748ULL: goto x86_l_1674;
	case 5753ULL: goto x86_l_1679;
	case 5759ULL: goto x86_l_167f;
	case 5762ULL: goto x86_l_1682;
	case 5767ULL: goto x86_l_1687;
	case 5773ULL: goto x86_l_168d;
	case 5777ULL: goto x86_l_1691;
	case 5784ULL: goto x86_l_1698;
	case 5789ULL: goto x86_l_169d;
	case 5791ULL: goto x86_l_169f;
	case 5794ULL: goto x86_l_16a2;
	case 5800ULL: goto x86_l_16a8;
	case 5803ULL: goto x86_l_16ab;
	case 5805ULL: goto x86_l_16ad;
	case 5810ULL: goto x86_l_16b2;
	case 5816ULL: goto x86_l_16b8;
	case 5819ULL: goto x86_l_16bb;
	case 5824ULL: goto x86_l_16c0;
	case 5830ULL: goto x86_l_16c6;
	case 5834ULL: goto x86_l_16ca;
	case 5841ULL: goto x86_l_16d1;
	case 5846ULL: goto x86_l_16d6;
	case 5848ULL: goto x86_l_16d8;
	case 5851ULL: goto x86_l_16db;
	case 5853ULL: goto x86_l_16dd;
	case 5856ULL: goto x86_l_16e0;
	case 5858ULL: goto x86_l_16e2;
	case 5863ULL: goto x86_l_16e7;
	case 5865ULL: goto x86_l_16e9;
	case 5868ULL: goto x86_l_16ec;
	case 5873ULL: goto x86_l_16f1;
	case 5876ULL: goto x86_l_16f4;
	case 5881ULL: goto x86_l_16f9;
	case 5886ULL: goto x86_l_16fe;
	case 5891ULL: goto x86_l_1703;
	case 5896ULL: goto x86_l_1708;
	case 5900ULL: goto x86_l_170c;
	case 5902ULL: goto x86_l_170e;
	case 5906ULL: goto x86_l_1712;
	case 5913ULL: goto x86_l_1719;
	case 5918ULL: goto x86_l_171e;
	case 5925ULL: goto x86_l_1725;
	case 5927ULL: goto x86_l_1727;
	case 5929ULL: goto x86_l_1729;
	case 5934ULL: goto x86_l_172e;
	case 5938ULL: goto x86_l_1732;
	case 5941ULL: goto x86_l_1735;
	case 5946ULL: goto x86_l_173a;
	case 5951ULL: goto x86_l_173f;
	case 5956ULL: goto x86_l_1744;
	case 5960ULL: goto x86_l_1748;
	case 5962ULL: goto x86_l_174a;
	case 5964ULL: goto x86_l_174c;
	case 5966ULL: goto x86_l_174e;
	case 5968ULL: goto x86_l_1750;
	case 5971ULL: goto x86_l_1753;
	case 5976ULL: goto x86_l_1758;
	case 5981ULL: goto x86_l_175d;
	case 5986ULL: goto x86_l_1762;
	case 5991ULL: goto x86_l_1767;
	case 5995ULL: goto x86_l_176b;
	case 5999ULL: goto x86_l_176f;
	case 6002ULL: goto x86_l_1772;
	case 6006ULL: goto x86_l_1776;
	case 6009ULL: goto x86_l_1779;
	case 6013ULL: goto x86_l_177d;
	case 6017ULL: goto x86_l_1781;
	case 6019ULL: goto x86_l_1783;
	case 6024ULL: goto x86_l_1788;
	case 6026ULL: goto x86_l_178a;
	case 6029ULL: goto x86_l_178d;
	case 6031ULL: goto x86_l_178f;
	case 6035ULL: goto x86_l_1793;
	case 6038ULL: goto x86_l_1796;
	case 6041ULL: goto x86_l_1799;
	case 6044ULL: goto x86_l_179c;
	case 6050ULL: goto x86_l_17a2;
	case 6055ULL: goto x86_l_17a7;
	case 6058ULL: goto x86_l_17aa;
	case 6062ULL: goto x86_l_17ae;
	case 6065ULL: goto x86_l_17b1;
	case 6071ULL: goto x86_l_17b7;
	case 6074ULL: goto x86_l_17ba;
	case 6078ULL: goto x86_l_17be;
	case 6081ULL: goto x86_l_17c1;
	case 6087ULL: goto x86_l_17c7;
	case 6093ULL: goto x86_l_17cd;
	case 6097ULL: goto x86_l_17d1;
	case 6101ULL: goto x86_l_17d5;
	case 6106ULL: goto x86_l_17da;
	case 6110ULL: goto x86_l_17de;
	case 6113ULL: goto x86_l_17e1;
	case 6118ULL: goto x86_l_17e6;
	case 6120ULL: goto x86_l_17e8;
	case 6122ULL: goto x86_l_17ea;
	case 6127ULL: goto x86_l_17ef;
	case 6130ULL: goto x86_l_17f2;
	case 6137ULL: goto x86_l_17f9;
	case 6139ULL: goto x86_l_17fb;
	case 6142ULL: goto x86_l_17fe;
	case 6145ULL: goto x86_l_1801;
	case 6148ULL: goto x86_l_1804;
	case 6151ULL: goto x86_l_1807;
	case 6155ULL: goto x86_l_180b;
	case 6159ULL: goto x86_l_180f;
	case 6161ULL: goto x86_l_1811;
	case 6166ULL: goto x86_l_1816;
	case 6170ULL: goto x86_l_181a;
	case 6172ULL: goto x86_l_181c;
	case 6175ULL: goto x86_l_181f;
	case 6177ULL: goto x86_l_1821;
	case 6180ULL: goto x86_l_1824;
	case 6183ULL: goto x86_l_1827;
	case 6187ULL: goto x86_l_182b;
	case 6189ULL: goto x86_l_182d;
	case 6192ULL: goto x86_l_1830;
	case 6196ULL: goto x86_l_1834;
	case 6200ULL: goto x86_l_1838;
	case 6203ULL: goto x86_l_183b;
	case 6208ULL: goto x86_l_1840;
	case 6215ULL: goto x86_l_1847;
	case 6217ULL: goto x86_l_1849;
	case 6220ULL: goto x86_l_184c;
	case 6224ULL: goto x86_l_1850;
	case 6228ULL: goto x86_l_1854;
	case 6230ULL: goto x86_l_1856;
	case 6232ULL: goto x86_l_1858;
	case 6234ULL: goto x86_l_185a;
	case 6238ULL: goto x86_l_185e;
	case 6242ULL: goto x86_l_1862;
	case 6245ULL: goto x86_l_1865;
	case 6251ULL: goto x86_l_186b;
	case 6254ULL: goto x86_l_186e;
	case 6260ULL: goto x86_l_1874;
	case 6263ULL: goto x86_l_1877;
	case 6266ULL: goto x86_l_187a;
	case 6272ULL: goto x86_l_1880;
	case 6274ULL: goto x86_l_1882;
	case 6277ULL: goto x86_l_1885;
	case 6280ULL: goto x86_l_1888;
	case 6283ULL: goto x86_l_188b;
	case 6286ULL: goto x86_l_188e;
	case 6290ULL: goto x86_l_1892;
	case 6294ULL: goto x86_l_1896;
	case 6296ULL: goto x86_l_1898;
	case 6301ULL: goto x86_l_189d;
	case 6305ULL: goto x86_l_18a1;
	case 6307ULL: goto x86_l_18a3;
	case 6309ULL: goto x86_l_18a5;
	case 6311ULL: goto x86_l_18a7;
	case 6313ULL: goto x86_l_18a9;
	case 6316ULL: goto x86_l_18ac;
	case 6319ULL: goto x86_l_18af;
	case 6322ULL: goto x86_l_18b2;
	case 6324ULL: goto x86_l_18b4;
	case 6328ULL: goto x86_l_18b8;
	case 6332ULL: goto x86_l_18bc;
	case 6334ULL: goto x86_l_18be;
	case 6339ULL: goto x86_l_18c3;
	case 6346ULL: goto x86_l_18ca;
	case 6348ULL: goto x86_l_18cc;
	case 6351ULL: goto x86_l_18cf;
	case 6354ULL: goto x86_l_18d2;
	case 6357ULL: goto x86_l_18d5;
	case 6360ULL: goto x86_l_18d8;
	case 6364ULL: goto x86_l_18dc;
	case 6368ULL: goto x86_l_18e0;
	case 6370ULL: goto x86_l_18e2;
	case 6375ULL: goto x86_l_18e7;
	case 6379ULL: goto x86_l_18eb;
	case 6381ULL: goto x86_l_18ed;
	case 6384ULL: goto x86_l_18f0;
	case 6386ULL: goto x86_l_18f2;
	case 6389ULL: goto x86_l_18f5;
	case 6392ULL: goto x86_l_18f8;
	case 6396ULL: goto x86_l_18fc;
	case 6398ULL: goto x86_l_18fe;
	case 6401ULL: goto x86_l_1901;
	case 6405ULL: goto x86_l_1905;
	case 6409ULL: goto x86_l_1909;
	case 6412ULL: goto x86_l_190c;
	case 6417ULL: goto x86_l_1911;
	case 6424ULL: goto x86_l_1918;
	case 6426ULL: goto x86_l_191a;
	case 6430ULL: goto x86_l_191e;
	case 6434ULL: goto x86_l_1922;
	default: return 0xffffffffffffffffULL;
	}
x86_l_131a:
	/* 0x131a: jne    178f <generic_rawtp_process_filter+0x178f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_178f;
	}
x86_l_1320:
	/* 0x1320: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1323:
	/* 0x1323: setne  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_NE);
x86_l_1326:
	/* 0x1326: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_132a:
	/* 0x132a: setne  bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_NE);
x86_l_132e:
	/* 0x132e: jmp    1776 <generic_rawtp_process_filter+0x1776> */
	goto x86_l_1776;
x86_l_1333:
	/* 0x1333: cmp    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1339:
	/* 0x1339: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_133e:
	/* 0x133e: je     1507 <generic_rawtp_process_filter+0x1507> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1507;
	}
x86_l_1344:
	/* 0x1344: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1346:
	/* 0x1346: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1349:
	/* 0x1349: je     174c <generic_rawtp_process_filter+0x174c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_174c;
	}
x86_l_134f:
	/* 0x134f: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_1352:
	/* 0x1352: test   rsi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_64);
x86_l_1355:
	/* 0x1355: je     176b <generic_rawtp_process_filter+0x176b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_176b;
	}
x86_l_135b:
	/* 0x135b: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_135e:
	/* 0x135e: je     176b <generic_rawtp_process_filter+0x176b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_176b;
	}
x86_l_1364:
	/* 0x1364: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1368:
	/* 0x1368: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_136d:
	/* 0x136d: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1372:
	/* 0x1372: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1377:
	/* 0x1377: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_137b:
	/* 0x137b: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1382:
	/* 0x1382: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1387:
	/* 0x1387: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1389:
	/* 0x1389: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_138c:
	/* 0x138c: je     1727 <generic_rawtp_process_filter+0x1727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1727;
	}
x86_l_1392:
	/* 0x1392: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1395:
	/* 0x1395: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1398:
	/* 0x1398: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_139d:
	/* 0x139d: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_13a3:
	/* 0x13a3: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_13a7:
	/* 0x13a7: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_13ae:
	/* 0x13ae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13b3:
	/* 0x13b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b5:
	/* 0x13b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13b8:
	/* 0x13b8: je     1727 <generic_rawtp_process_filter+0x1727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1727;
	}
x86_l_13be:
	/* 0x13be: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_13c1:
	/* 0x13c1: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_13c4:
	/* 0x13c4: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13c9:
	/* 0x13c9: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_13cf:
	/* 0x13cf: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_13d3:
	/* 0x13d3: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_13da:
	/* 0x13da: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13df:
	/* 0x13df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e1:
	/* 0x13e1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13e4:
	/* 0x13e4: je     1727 <generic_rawtp_process_filter+0x1727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1727;
	}
x86_l_13ea:
	/* 0x13ea: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_13ed:
	/* 0x13ed: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_13f0:
	/* 0x13f0: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13f5:
	/* 0x13f5: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_13fb:
	/* 0x13fb: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_13ff:
	/* 0x13ff: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1406:
	/* 0x1406: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_140b:
	/* 0x140b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_140d:
	/* 0x140d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1410:
	/* 0x1410: je     1727 <generic_rawtp_process_filter+0x1727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1727;
	}
x86_l_1416:
	/* 0x1416: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1419:
	/* 0x1419: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_141c:
	/* 0x141c: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1421:
	/* 0x1421: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_1427:
	/* 0x1427: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_142b:
	/* 0x142b: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1432:
	/* 0x1432: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1437:
	/* 0x1437: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1439:
	/* 0x1439: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_143c:
	/* 0x143c: je     1727 <generic_rawtp_process_filter+0x1727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1727;
	}
x86_l_1442:
	/* 0x1442: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1445:
	/* 0x1445: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1448:
	/* 0x1448: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_144d:
	/* 0x144d: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_1453:
	/* 0x1453: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1457:
	/* 0x1457: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_145e:
	/* 0x145e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1463:
	/* 0x1463: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1465:
	/* 0x1465: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1468:
	/* 0x1468: je     1727 <generic_rawtp_process_filter+0x1727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1727;
	}
x86_l_146e:
	/* 0x146e: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1471:
	/* 0x1471: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1474:
	/* 0x1474: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1479:
	/* 0x1479: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_147f:
	/* 0x147f: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1483:
	/* 0x1483: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_148a:
	/* 0x148a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_148f:
	/* 0x148f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1491:
	/* 0x1491: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1494:
	/* 0x1494: je     1727 <generic_rawtp_process_filter+0x1727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1727;
	}
x86_l_149a:
	/* 0x149a: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_149d:
	/* 0x149d: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_14a0:
	/* 0x14a0: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_14a5:
	/* 0x14a5: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_14ab:
	/* 0x14ab: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_14af:
	/* 0x14af: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_14b6:
	/* 0x14b6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14bb:
	/* 0x14bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14bd:
	/* 0x14bd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14c0:
	/* 0x14c0: je     1727 <generic_rawtp_process_filter+0x1727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1727;
	}
x86_l_14c6:
	/* 0x14c6: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_14c9:
	/* 0x14c9: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_14cc:
	/* 0x14cc: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_14d1:
	/* 0x14d1: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_14d4:
	/* 0x14d4: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14d9:
	/* 0x14d9: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14de:
	/* 0x14de: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14e3:
	/* 0x14e3: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14e8:
	/* 0x14e8: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_14ec:
	/* 0x14ec: je     176b <generic_rawtp_process_filter+0x176b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_176b;
	}
x86_l_14f2:
	/* 0x14f2: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_14f6:
	/* 0x14f6: mov    rcx,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_14fd:
	/* 0x14fd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1502:
	/* 0x1502: jmp    171e <generic_rawtp_process_filter+0x171e> */
	goto x86_l_171e;
x86_l_1507:
	/* 0x1507: mov    edx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1509:
	/* 0x1509: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_150c:
	/* 0x150c: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_150f:
	/* 0x150f: je     176b <generic_rawtp_process_filter+0x176b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_176b;
	}
x86_l_1515:
	/* 0x1515: mov    edx,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1518:
	/* 0x1518: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_151b:
	/* 0x151b: je     176b <generic_rawtp_process_filter+0x176b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_176b;
	}
x86_l_1521:
	/* 0x1521: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1525:
	/* 0x1525: mov    DWORD PTR [rsp+0x8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_152a:
	/* 0x152a: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_152f:
	/* 0x152f: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1534:
	/* 0x1534: lea    rsi,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1538:
	/* 0x1538: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_153f:
	/* 0x153f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1544:
	/* 0x1544: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1546:
	/* 0x1546: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1549:
	/* 0x1549: je     1727 <generic_rawtp_process_filter+0x1727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1727;
	}
x86_l_154f:
	/* 0x154f: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1552:
	/* 0x1552: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1554:
	/* 0x1554: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1559:
	/* 0x1559: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_155c:
	/* 0x155c: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_1562:
	/* 0x1562: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1565:
	/* 0x1565: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1568:
	/* 0x1568: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_156e:
	/* 0x156e: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1572:
	/* 0x1572: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1579:
	/* 0x1579: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_157e:
	/* 0x157e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1580:
	/* 0x1580: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1583:
	/* 0x1583: je     1727 <generic_rawtp_process_filter+0x1727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1727;
	}
x86_l_1589:
	/* 0x1589: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_158c:
	/* 0x158c: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_158e:
	/* 0x158e: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1593:
	/* 0x1593: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1596:
	/* 0x1596: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_159c:
	/* 0x159c: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_159f:
	/* 0x159f: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_15a2:
	/* 0x15a2: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_15a8:
	/* 0x15a8: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_15ac:
	/* 0x15ac: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_15b3:
	/* 0x15b3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15b8:
	/* 0x15b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ba:
	/* 0x15ba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15bd:
	/* 0x15bd: je     1727 <generic_rawtp_process_filter+0x1727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1727;
	}
x86_l_15c3:
	/* 0x15c3: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_15c6:
	/* 0x15c6: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15c8:
	/* 0x15c8: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15cd:
	/* 0x15cd: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_15d0:
	/* 0x15d0: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_15d6:
	/* 0x15d6: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15d9:
	/* 0x15d9: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_15dc:
	/* 0x15dc: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_15e2:
	/* 0x15e2: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_15e6:
	/* 0x15e6: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_15ed:
	/* 0x15ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15f2:
	/* 0x15f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f4:
	/* 0x15f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15f7:
	/* 0x15f7: je     1727 <generic_rawtp_process_filter+0x1727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1727;
	}
x86_l_15fd:
	/* 0x15fd: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1600:
	/* 0x1600: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1602:
	/* 0x1602: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1607:
	/* 0x1607: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_160d:
	/* 0x160d: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1610:
	/* 0x1610: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1615:
	/* 0x1615: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_161b:
	/* 0x161b: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_161f:
	/* 0x161f: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1626:
	/* 0x1626: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_162b:
	/* 0x162b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_162d:
	/* 0x162d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1630:
	/* 0x1630: je     1727 <generic_rawtp_process_filter+0x1727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1727;
	}
x86_l_1636:
	/* 0x1636: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1639:
	/* 0x1639: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_163b:
	/* 0x163b: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1640:
	/* 0x1640: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_1646:
	/* 0x1646: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1649:
	/* 0x1649: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_164e:
	/* 0x164e: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_1654:
	/* 0x1654: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1658:
	/* 0x1658: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_165f:
	/* 0x165f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1664:
	/* 0x1664: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1666:
	/* 0x1666: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1669:
	/* 0x1669: je     1727 <generic_rawtp_process_filter+0x1727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1727;
	}
x86_l_166f:
	/* 0x166f: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1672:
	/* 0x1672: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1674:
	/* 0x1674: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1679:
	/* 0x1679: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_167f:
	/* 0x167f: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1682:
	/* 0x1682: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1687:
	/* 0x1687: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_168d:
	/* 0x168d: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1691:
	/* 0x1691: mov    rdi,QWORD PTR [rip+0x41a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1698:
	/* 0x1698: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_169d:
	/* 0x169d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_169f:
	/* 0x169f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16a2:
	/* 0x16a2: je     1727 <generic_rawtp_process_filter+0x1727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1727;
	}
x86_l_16a8:
	/* 0x16a8: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_16ab:
	/* 0x16ab: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16ad:
	/* 0x16ad: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16b2:
	/* 0x16b2: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_16b8:
	/* 0x16b8: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16bb:
	/* 0x16bb: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16c0:
	/* 0x16c0: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_16c6:
	/* 0x16c6: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_16ca:
	/* 0x16ca: mov    rdi,QWORD PTR [rip+0x41a3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_16d1:
	/* 0x16d1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16d6:
	/* 0x16d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16d8:
	/* 0x16d8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16db:
	/* 0x16db: je     1727 <generic_rawtp_process_filter+0x1727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1727;
	}
x86_l_16dd:
	/* 0x16dd: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_16e0:
	/* 0x16e0: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16e2:
	/* 0x16e2: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16e7:
	/* 0x16e7: je     1750 <generic_rawtp_process_filter+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_16e9:
	/* 0x16e9: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16ec:
	/* 0x16ec: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16f1:
	/* 0x16f1: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_16f4:
	/* 0x16f4: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16f9:
	/* 0x16f9: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16fe:
	/* 0x16fe: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1703:
	/* 0x1703: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1708:
	/* 0x1708: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_170c:
	/* 0x170c: je     176b <generic_rawtp_process_filter+0x176b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_176b;
	}
x86_l_170e:
	/* 0x170e: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1712:
	/* 0x1712: mov    rcx,QWORD PTR [rip+0x41a3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1719:
	/* 0x1719: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_171e:
	/* 0x171e: mov    rdi,QWORD PTR [rip+0x41a3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1725:
	/* 0x1725: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1727:
	/* 0x1727: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1729:
	/* 0x1729: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_172e:
	/* 0x172e: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1732:
	/* 0x1732: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1735:
	/* 0x1735: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_173a:
	/* 0x173a: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_173f:
	/* 0x173f: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1744:
	/* 0x1744: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1748:
	/* 0x1748: jne    176b <generic_rawtp_process_filter+0x176b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_176b;
	}
x86_l_174a:
	/* 0x174a: jmp    178f <generic_rawtp_process_filter+0x178f> */
	goto x86_l_178f;
x86_l_174c:
	/* 0x174c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_174e:
	/* 0x174e: jmp    1779 <generic_rawtp_process_filter+0x1779> */
	goto x86_l_1779;
x86_l_1750:
	/* 0x1750: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1753:
	/* 0x1753: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1758:
	/* 0x1758: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_175d:
	/* 0x175d: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1762:
	/* 0x1762: mov    r9d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1767:
	/* 0x1767: mov    edi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_176b:
	/* 0x176b: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_176f:
	/* 0x176f: setne  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_NE);
x86_l_1772:
	/* 0x1772: xor    bpl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1776:
	/* 0x1776: or     bpl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1779:
	/* 0x1779: movzx  ebp,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_177d:
	/* 0x177d: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1781:
	/* 0x1781: jne    178f <generic_rawtp_process_filter+0x178f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_178f;
	}
x86_l_1783:
	/* 0x1783: and    r12d,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 80ULL);
x86_l_1788:
	/* 0x1788: and    edi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_32, X86_ALU_AND);
x86_l_178a:
	/* 0x178a: and    r12d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDI, X86_WIDTH_32, X86_ALU_AND);
x86_l_178d:
	/* 0x178d: jmp    1799 <generic_rawtp_process_filter+0x1799> */
	goto x86_l_1799;
x86_l_178f:
	/* 0x178f: or     ebp,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 80ULL);
x86_l_1793:
	/* 0x1793: or     r12d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_1796:
	/* 0x1796: or     r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_OR);
x86_l_1799:
	/* 0x1799: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_179c:
	/* 0x179c: je     2014 <generic_rawtp_process_filter+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_17a2:
	/* 0x17a2: mov    edx,DWORD PTR [rax+r11*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 0), 8ULL);
x86_l_17a7:
	/* 0x17a7: and    edx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_17aa:
	/* 0x17aa: lea    r11d,[r8+rdx*4] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 0ULL);
x86_l_17ae:
	/* 0x17ae: mov    edx,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R11, X86_WIDTH_32);
x86_l_17b1:
	/* 0x17b1: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_17b7:
	/* 0x17b7: mov    edx,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_17ba:
	/* 0x17ba: lea    edi,[r11+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_17be:
	/* 0x17be: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_17c1:
	/* 0x17c1: je     1fdf <generic_rawtp_process_filter+0x1fdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8159ULL;
	}
x86_l_17c7:
	/* 0x17c7: and    edi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_17cd:
	/* 0x17cd: lea    r8d,[r11+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17d1:
	/* 0x17d1: mov    r10d,DWORD PTR [rdi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_17d5:
	/* 0x17d5: mov    r9d,DWORD PTR [rdi+rax*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_17da:
	/* 0x17da: mov    esi,DWORD PTR [rdi+rax*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 8ULL);
x86_l_17de:
	/* 0x17de: cmp    esi,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 3ULL);
x86_l_17e1:
	/* 0x17e1: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17e6:
	/* 0x17e6: jbe    1858 <generic_rawtp_process_filter+0x1858> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1858;
	}
x86_l_17e8:
	/* 0x17e8: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17ea:
	/* 0x17ea: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_17ef:
	/* 0x17ef: mov    r12,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R11, X86_WIDTH_64);
x86_l_17f2:
	/* 0x17f2: cmp    r11d,0x3d8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 984ULL);
x86_l_17f9:
	/* 0x17f9: ja     1804 <generic_rawtp_process_filter+0x1804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1804;
	}
x86_l_17fb:
	/* 0x17fb: mov    edx,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_17fe:
	/* 0x17fe: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1801:
	/* 0x1801: mov    edx,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1804:
	/* 0x1804: mov    r11d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R10, X86_WIDTH_32);
x86_l_1807:
	/* 0x1807: and    r11d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_180b:
	/* 0x180b: cmp    r11,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_64, 9ULL);
x86_l_180f:
	/* 0x180f: ja     1834 <generic_rawtp_process_filter+0x1834> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1834;
	}
x86_l_1811:
	/* 0x1811: mov    r11d,DWORD PTR [r14+r11*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 2), 32ULL);
x86_l_1816:
	/* 0x1816: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_181a:
	/* 0x181a: jne    1821 <generic_rawtp_process_filter+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1821;
	}
x86_l_181c:
	/* 0x181c: cmp    edx,r11d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R11, X86_WIDTH_32);
x86_l_181f:
	/* 0x181f: jne    1834 <generic_rawtp_process_filter+0x1834> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1834;
	}
x86_l_1821:
	/* 0x1821: xor    edx,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1824:
	/* 0x1824: mov    r11d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R9, X86_WIDTH_32);
x86_l_1827:
	/* 0x1827: xor    r11d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_182b:
	/* 0x182b: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_182d:
	/* 0x182d: or     r11d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1830:
	/* 0x1830: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_1834:
	/* 0x1834: add    r12d,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 20ULL);
x86_l_1838:
	/* 0x1838: xor    r11d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_183b:
	/* 0x183b: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1840:
	/* 0x1840: cmp    r12d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1000ULL);
x86_l_1847:
	/* 0x1847: jbe    1882 <generic_rawtp_process_filter+0x1882> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1882;
	}
x86_l_1849:
	/* 0x1849: mov    r13d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R10, X86_WIDTH_32);
x86_l_184c:
	/* 0x184c: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1850:
	/* 0x1850: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_1854:
	/* 0x1854: jbe    1898 <generic_rawtp_process_filter+0x1898> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1898;
	}
x86_l_1856:
	/* 0x1856: jmp    18b8 <generic_rawtp_process_filter+0x18b8> */
	goto x86_l_18b8;
x86_l_1858:
	/* 0x1858: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_185a:
	/* 0x185a: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_185e:
	/* 0x185e: sete   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_E);
x86_l_1862:
	/* 0x1862: cmp    esi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1865:
	/* 0x1865: je     1a77 <generic_rawtp_process_filter+0x1a77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6775ULL;
	}
x86_l_186b:
	/* 0x186b: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_186e:
	/* 0x186e: je     1a58 <generic_rawtp_process_filter+0x1a58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6744ULL;
	}
x86_l_1874:
	/* 0x1874: mov    r12d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_32);
x86_l_1877:
	/* 0x1877: cmp    esi,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 3ULL);
x86_l_187a:
	/* 0x187a: jne    17e8 <generic_rawtp_process_filter+0x17e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_17e8;
	}
x86_l_1880:
	/* 0x1880: jmp    1838 <generic_rawtp_process_filter+0x1838> */
	goto x86_l_1838;
x86_l_1882:
	/* 0x1882: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_1885:
	/* 0x1885: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1888:
	/* 0x1888: mov    edx,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_188b:
	/* 0x188b: mov    r13d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R10, X86_WIDTH_32);
x86_l_188e:
	/* 0x188e: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1892:
	/* 0x1892: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_1896:
	/* 0x1896: ja     18b8 <generic_rawtp_process_filter+0x18b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18b8;
	}
x86_l_1898:
	/* 0x1898: mov    ebp,DWORD PTR [r14+r13*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 32ULL);
x86_l_189d:
	/* 0x189d: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_18a1:
	/* 0x18a1: jne    18a7 <generic_rawtp_process_filter+0x18a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18a7;
	}
x86_l_18a3:
	/* 0x18a3: cmp    edx,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_18a5:
	/* 0x18a5: jne    18b8 <generic_rawtp_process_filter+0x18b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18b8;
	}
x86_l_18a7:
	/* 0x18a7: xor    edx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18a9:
	/* 0x18a9: mov    ebp,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R9, X86_WIDTH_32);
x86_l_18ac:
	/* 0x18ac: xor    ebp,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_18af:
	/* 0x18af: xor    r11d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18b2:
	/* 0x18b2: or     ebp,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_18b4:
	/* 0x18b4: setne  r11b */
	X86_SIM_L_EXEC_SETCC(X86_R11, X86_CC_NE);
x86_l_18b8:
	/* 0x18b8: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_18bc:
	/* 0x18bc: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18be:
	/* 0x18be: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_18c3:
	/* 0x18c3: cmp    r12d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1000ULL);
x86_l_18ca:
	/* 0x18ca: ja     18d5 <generic_rawtp_process_filter+0x18d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18d5;
	}
x86_l_18cc:
	/* 0x18cc: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_18cf:
	/* 0x18cf: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_18d2:
	/* 0x18d2: mov    edx,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_18d5:
	/* 0x18d5: mov    r13d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R10, X86_WIDTH_32);
x86_l_18d8:
	/* 0x18d8: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_18dc:
	/* 0x18dc: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_18e0:
	/* 0x18e0: ja     1905 <generic_rawtp_process_filter+0x1905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1905;
	}
x86_l_18e2:
	/* 0x18e2: mov    r13d,DWORD PTR [r14+r13*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 32ULL);
x86_l_18e7:
	/* 0x18e7: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_18eb:
	/* 0x18eb: jne    18f2 <generic_rawtp_process_filter+0x18f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18f2;
	}
x86_l_18ed:
	/* 0x18ed: cmp    edx,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_18f0:
	/* 0x18f0: jne    1905 <generic_rawtp_process_filter+0x1905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1905;
	}
x86_l_18f2:
	/* 0x18f2: xor    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18f5:
	/* 0x18f5: mov    r13d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_32);
x86_l_18f8:
	/* 0x18f8: xor    r13d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_18fc:
	/* 0x18fc: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18fe:
	/* 0x18fe: or     r13d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1901:
	/* 0x1901: setne  bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_NE);
x86_l_1905:
	/* 0x1905: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1909:
	/* 0x1909: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_190c:
	/* 0x190c: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1911:
	/* 0x1911: cmp    r12d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1000ULL);
x86_l_1918:
	/* 0x1918: ja     1922 <generic_rawtp_process_filter+0x1922> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1922;
	}
x86_l_191a:
	/* 0x191a: and    r12d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_191e:
	/* 0x191e: mov    edx,DWORD PTR [rax+r12*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1922:
	/* 0x1922: and    r10d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 15ULL);
	return 6438ULL;
}

static __noinline __u64 tetragon_bpf_generic_rawtp_generic_rawtp_process_filter_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6438ULL: goto x86_l_1926;
	case 6442ULL: goto x86_l_192a;
	case 6444ULL: goto x86_l_192c;
	case 6449ULL: goto x86_l_1931;
	case 6453ULL: goto x86_l_1935;
	case 6455ULL: goto x86_l_1937;
	case 6458ULL: goto x86_l_193a;
	case 6461ULL: goto x86_l_193d;
	case 6463ULL: goto x86_l_193f;
	case 6466ULL: goto x86_l_1942;
	case 6469ULL: goto x86_l_1945;
	case 6473ULL: goto x86_l_1949;
	case 6476ULL: goto x86_l_194c;
	case 6479ULL: goto x86_l_194f;
	case 6483ULL: goto x86_l_1953;
	case 6487ULL: goto x86_l_1957;
	case 6489ULL: goto x86_l_1959;
	case 6492ULL: goto x86_l_195c;
	case 6495ULL: goto x86_l_195f;
	case 6497ULL: goto x86_l_1961;
	case 6499ULL: goto x86_l_1963;
	case 6502ULL: goto x86_l_1966;
	case 6504ULL: goto x86_l_1968;
	case 6507ULL: goto x86_l_196b;
	case 6509ULL: goto x86_l_196d;
	case 6515ULL: goto x86_l_1973;
	case 6518ULL: goto x86_l_1976;
	case 6520ULL: goto x86_l_1978;
	case 6523ULL: goto x86_l_197b;
	case 6526ULL: goto x86_l_197e;
	case 6531ULL: goto x86_l_1983;
	case 6534ULL: goto x86_l_1986;
	case 6536ULL: goto x86_l_1988;
	case 6542ULL: goto x86_l_198e;
	case 6544ULL: goto x86_l_1990;
	case 6550ULL: goto x86_l_1996;
	case 6553ULL: goto x86_l_1999;
	case 6557ULL: goto x86_l_199d;
	case 6562ULL: goto x86_l_19a2;
	case 6567ULL: goto x86_l_19a7;
	case 6571ULL: goto x86_l_19ab;
	case 6575ULL: goto x86_l_19af;
	case 6577ULL: goto x86_l_19b1;
	case 6580ULL: goto x86_l_19b4;
	case 6585ULL: goto x86_l_19b9;
	case 6591ULL: goto x86_l_19bf;
	case 6593ULL: goto x86_l_19c1;
	case 6595ULL: goto x86_l_19c3;
	case 6598ULL: goto x86_l_19c6;
	case 6601ULL: goto x86_l_19c9;
	case 6604ULL: goto x86_l_19cc;
	case 6608ULL: goto x86_l_19d0;
	case 6612ULL: goto x86_l_19d4;
	case 6614ULL: goto x86_l_19d6;
	case 6619ULL: goto x86_l_19db;
	case 6623ULL: goto x86_l_19df;
	case 6625ULL: goto x86_l_19e1;
	case 6628ULL: goto x86_l_19e4;
	case 6630ULL: goto x86_l_19e6;
	case 6633ULL: goto x86_l_19e9;
	case 6636ULL: goto x86_l_19ec;
	case 6640ULL: goto x86_l_19f0;
	case 6643ULL: goto x86_l_19f3;
	case 6646ULL: goto x86_l_19f6;
	case 6650ULL: goto x86_l_19fa;
	case 6653ULL: goto x86_l_19fd;
	case 6656ULL: goto x86_l_1a00;
	case 6658ULL: goto x86_l_1a02;
	case 6663ULL: goto x86_l_1a07;
	case 6670ULL: goto x86_l_1a0e;
	case 6676ULL: goto x86_l_1a14;
	case 6679ULL: goto x86_l_1a17;
	case 6683ULL: goto x86_l_1a1b;
	case 6687ULL: goto x86_l_1a1f;
	case 6693ULL: goto x86_l_1a25;
	case 6698ULL: goto x86_l_1a2a;
	case 6701ULL: goto x86_l_1a2d;
	case 6705ULL: goto x86_l_1a31;
	case 6709ULL: goto x86_l_1a35;
	case 6713ULL: goto x86_l_1a39;
	case 6719ULL: goto x86_l_1a3f;
	case 6723ULL: goto x86_l_1a43;
	case 6729ULL: goto x86_l_1a49;
	case 6732ULL: goto x86_l_1a4c;
	case 6736ULL: goto x86_l_1a50;
	case 6742ULL: goto x86_l_1a56;
	case 6744ULL: goto x86_l_1a58;
	case 6747ULL: goto x86_l_1a5b;
	case 6750ULL: goto x86_l_1a5e;
	case 6752ULL: goto x86_l_1a60;
	case 6757ULL: goto x86_l_1a65;
	case 6764ULL: goto x86_l_1a6c;
	case 6770ULL: goto x86_l_1a72;
	case 6775ULL: goto x86_l_1a77;
	case 6777ULL: goto x86_l_1a79;
	case 6780ULL: goto x86_l_1a7c;
	case 6783ULL: goto x86_l_1a7f;
	case 6786ULL: goto x86_l_1a82;
	case 6791ULL: goto x86_l_1a87;
	case 6798ULL: goto x86_l_1a8e;
	case 6804ULL: goto x86_l_1a94;
	case 6809ULL: goto x86_l_1a99;
	case 6812ULL: goto x86_l_1a9c;
	case 6815ULL: goto x86_l_1a9f;
	case 6818ULL: goto x86_l_1aa2;
	case 6821ULL: goto x86_l_1aa5;
	case 6825ULL: goto x86_l_1aa9;
	case 6829ULL: goto x86_l_1aad;
	case 6831ULL: goto x86_l_1aaf;
	case 6836ULL: goto x86_l_1ab4;
	case 6840ULL: goto x86_l_1ab8;
	case 6842ULL: goto x86_l_1aba;
	case 6845ULL: goto x86_l_1abd;
	case 6847ULL: goto x86_l_1abf;
	case 6850ULL: goto x86_l_1ac2;
	case 6853ULL: goto x86_l_1ac5;
	case 6857ULL: goto x86_l_1ac9;
	case 6859ULL: goto x86_l_1acb;
	case 6862ULL: goto x86_l_1ace;
	case 6866ULL: goto x86_l_1ad2;
	case 6870ULL: goto x86_l_1ad6;
	case 6872ULL: goto x86_l_1ad8;
	case 6877ULL: goto x86_l_1add;
	case 6884ULL: goto x86_l_1ae4;
	case 6886ULL: goto x86_l_1ae6;
	case 6889ULL: goto x86_l_1ae9;
	case 6892ULL: goto x86_l_1aec;
	case 6895ULL: goto x86_l_1aef;
	case 6898ULL: goto x86_l_1af2;
	case 6902ULL: goto x86_l_1af6;
	case 6906ULL: goto x86_l_1afa;
	case 6908ULL: goto x86_l_1afc;
	case 6913ULL: goto x86_l_1b01;
	case 6917ULL: goto x86_l_1b05;
	case 6919ULL: goto x86_l_1b07;
	case 6922ULL: goto x86_l_1b0a;
	case 6924ULL: goto x86_l_1b0c;
	case 6927ULL: goto x86_l_1b0f;
	case 6930ULL: goto x86_l_1b12;
	case 6934ULL: goto x86_l_1b16;
	case 6936ULL: goto x86_l_1b18;
	case 6939ULL: goto x86_l_1b1b;
	case 6943ULL: goto x86_l_1b1f;
	case 6947ULL: goto x86_l_1b23;
	case 6950ULL: goto x86_l_1b26;
	case 6955ULL: goto x86_l_1b2b;
	case 6962ULL: goto x86_l_1b32;
	case 6964ULL: goto x86_l_1b34;
	case 6968ULL: goto x86_l_1b38;
	case 6972ULL: goto x86_l_1b3c;
	case 6976ULL: goto x86_l_1b40;
	case 6980ULL: goto x86_l_1b44;
	case 6982ULL: goto x86_l_1b46;
	case 6987ULL: goto x86_l_1b4b;
	case 6991ULL: goto x86_l_1b4f;
	case 6993ULL: goto x86_l_1b51;
	case 6996ULL: goto x86_l_1b54;
	case 6999ULL: goto x86_l_1b57;
	case 7001ULL: goto x86_l_1b59;
	case 7004ULL: goto x86_l_1b5c;
	case 7007ULL: goto x86_l_1b5f;
	case 7011ULL: goto x86_l_1b63;
	case 7014ULL: goto x86_l_1b66;
	case 7017ULL: goto x86_l_1b69;
	case 7021ULL: goto x86_l_1b6d;
	case 7025ULL: goto x86_l_1b71;
	case 7027ULL: goto x86_l_1b73;
	case 7029ULL: goto x86_l_1b75;
	case 7032ULL: goto x86_l_1b78;
	case 7035ULL: goto x86_l_1b7b;
	case 7037ULL: goto x86_l_1b7d;
	case 7040ULL: goto x86_l_1b80;
	case 7043ULL: goto x86_l_1b83;
	case 7046ULL: goto x86_l_1b86;
	case 7048ULL: goto x86_l_1b88;
	case 7054ULL: goto x86_l_1b8e;
	case 7062ULL: goto x86_l_1b96;
	case 7065ULL: goto x86_l_1b99;
	case 7069ULL: goto x86_l_1b9d;
	case 7073ULL: goto x86_l_1ba1;
	case 7078ULL: goto x86_l_1ba6;
	case 7081ULL: goto x86_l_1ba9;
	case 7083ULL: goto x86_l_1bab;
	case 7089ULL: goto x86_l_1bb1;
	case 7091ULL: goto x86_l_1bb3;
	case 7097ULL: goto x86_l_1bb9;
	case 7100ULL: goto x86_l_1bbc;
	case 7104ULL: goto x86_l_1bc0;
	case 7109ULL: goto x86_l_1bc5;
	case 7114ULL: goto x86_l_1bca;
	case 7118ULL: goto x86_l_1bce;
	case 7122ULL: goto x86_l_1bd2;
	case 7124ULL: goto x86_l_1bd4;
	case 7127ULL: goto x86_l_1bd7;
	case 7132ULL: goto x86_l_1bdc;
	case 7138ULL: goto x86_l_1be2;
	case 7140ULL: goto x86_l_1be4;
	case 7142ULL: goto x86_l_1be6;
	case 7145ULL: goto x86_l_1be9;
	case 7148ULL: goto x86_l_1bec;
	case 7151ULL: goto x86_l_1bef;
	case 7155ULL: goto x86_l_1bf3;
	case 7159ULL: goto x86_l_1bf7;
	case 7161ULL: goto x86_l_1bf9;
	case 7166ULL: goto x86_l_1bfe;
	case 7170ULL: goto x86_l_1c02;
	case 7172ULL: goto x86_l_1c04;
	case 7175ULL: goto x86_l_1c07;
	case 7177ULL: goto x86_l_1c09;
	case 7180ULL: goto x86_l_1c0c;
	case 7183ULL: goto x86_l_1c0f;
	case 7187ULL: goto x86_l_1c13;
	case 7190ULL: goto x86_l_1c16;
	case 7193ULL: goto x86_l_1c19;
	case 7197ULL: goto x86_l_1c1d;
	case 7200ULL: goto x86_l_1c20;
	case 7203ULL: goto x86_l_1c23;
	case 7205ULL: goto x86_l_1c25;
	case 7210ULL: goto x86_l_1c2a;
	case 7217ULL: goto x86_l_1c31;
	case 7223ULL: goto x86_l_1c37;
	case 7226ULL: goto x86_l_1c3a;
	case 7230ULL: goto x86_l_1c3e;
	case 7234ULL: goto x86_l_1c42;
	case 7240ULL: goto x86_l_1c48;
	case 7245ULL: goto x86_l_1c4d;
	case 7248ULL: goto x86_l_1c50;
	case 7252ULL: goto x86_l_1c54;
	case 7256ULL: goto x86_l_1c58;
	case 7260ULL: goto x86_l_1c5c;
	case 7266ULL: goto x86_l_1c62;
	case 7270ULL: goto x86_l_1c66;
	case 7276ULL: goto x86_l_1c6c;
	case 7279ULL: goto x86_l_1c6f;
	case 7283ULL: goto x86_l_1c73;
	case 7289ULL: goto x86_l_1c79;
	case 7291ULL: goto x86_l_1c7b;
	case 7294ULL: goto x86_l_1c7e;
	case 7297ULL: goto x86_l_1c81;
	case 7299ULL: goto x86_l_1c83;
	case 7304ULL: goto x86_l_1c88;
	case 7311ULL: goto x86_l_1c8f;
	case 7317ULL: goto x86_l_1c95;
	case 7322ULL: goto x86_l_1c9a;
	case 7324ULL: goto x86_l_1c9c;
	case 7327ULL: goto x86_l_1c9f;
	case 7330ULL: goto x86_l_1ca2;
	case 7333ULL: goto x86_l_1ca5;
	case 7336ULL: goto x86_l_1ca8;
	case 7341ULL: goto x86_l_1cad;
	case 7348ULL: goto x86_l_1cb4;
	case 7354ULL: goto x86_l_1cba;
	case 7359ULL: goto x86_l_1cbf;
	case 7362ULL: goto x86_l_1cc2;
	case 7365ULL: goto x86_l_1cc5;
	case 7368ULL: goto x86_l_1cc8;
	case 7371ULL: goto x86_l_1ccb;
	case 7375ULL: goto x86_l_1ccf;
	case 7379ULL: goto x86_l_1cd3;
	case 7381ULL: goto x86_l_1cd5;
	case 7386ULL: goto x86_l_1cda;
	case 7390ULL: goto x86_l_1cde;
	case 7392ULL: goto x86_l_1ce0;
	case 7395ULL: goto x86_l_1ce3;
	case 7397ULL: goto x86_l_1ce5;
	case 7400ULL: goto x86_l_1ce8;
	case 7403ULL: goto x86_l_1ceb;
	case 7407ULL: goto x86_l_1cef;
	case 7409ULL: goto x86_l_1cf1;
	case 7412ULL: goto x86_l_1cf4;
	case 7416ULL: goto x86_l_1cf8;
	case 7420ULL: goto x86_l_1cfc;
	case 7422ULL: goto x86_l_1cfe;
	case 7427ULL: goto x86_l_1d03;
	case 7434ULL: goto x86_l_1d0a;
	case 7436ULL: goto x86_l_1d0c;
	case 7439ULL: goto x86_l_1d0f;
	case 7442ULL: goto x86_l_1d12;
	case 7445ULL: goto x86_l_1d15;
	case 7448ULL: goto x86_l_1d18;
	case 7452ULL: goto x86_l_1d1c;
	case 7456ULL: goto x86_l_1d20;
	case 7458ULL: goto x86_l_1d22;
	case 7463ULL: goto x86_l_1d27;
	case 7467ULL: goto x86_l_1d2b;
	case 7469ULL: goto x86_l_1d2d;
	case 7472ULL: goto x86_l_1d30;
	case 7474ULL: goto x86_l_1d32;
	case 7477ULL: goto x86_l_1d35;
	case 7480ULL: goto x86_l_1d38;
	case 7484ULL: goto x86_l_1d3c;
	case 7486ULL: goto x86_l_1d3e;
	case 7489ULL: goto x86_l_1d41;
	case 7493ULL: goto x86_l_1d45;
	case 7497ULL: goto x86_l_1d49;
	case 7500ULL: goto x86_l_1d4c;
	case 7505ULL: goto x86_l_1d51;
	case 7512ULL: goto x86_l_1d58;
	case 7514ULL: goto x86_l_1d5a;
	case 7518ULL: goto x86_l_1d5e;
	case 7522ULL: goto x86_l_1d62;
	case 7526ULL: goto x86_l_1d66;
	case 7530ULL: goto x86_l_1d6a;
	case 7532ULL: goto x86_l_1d6c;
	case 7537ULL: goto x86_l_1d71;
	case 7541ULL: goto x86_l_1d75;
	case 7543ULL: goto x86_l_1d77;
	case 7546ULL: goto x86_l_1d7a;
	case 7549ULL: goto x86_l_1d7d;
	case 7551ULL: goto x86_l_1d7f;
	case 7554ULL: goto x86_l_1d82;
	case 7557ULL: goto x86_l_1d85;
	case 7561ULL: goto x86_l_1d89;
	case 7564ULL: goto x86_l_1d8c;
	case 7567ULL: goto x86_l_1d8f;
	case 7571ULL: goto x86_l_1d93;
	case 7575ULL: goto x86_l_1d97;
	case 7577ULL: goto x86_l_1d99;
	case 7579ULL: goto x86_l_1d9b;
	case 7582ULL: goto x86_l_1d9e;
	case 7585ULL: goto x86_l_1da1;
	case 7587ULL: goto x86_l_1da3;
	case 7590ULL: goto x86_l_1da6;
	case 7593ULL: goto x86_l_1da9;
	case 7596ULL: goto x86_l_1dac;
	case 7598ULL: goto x86_l_1dae;
	case 7604ULL: goto x86_l_1db4;
	case 7608ULL: goto x86_l_1db8;
	case 7611ULL: goto x86_l_1dbb;
	case 7615ULL: goto x86_l_1dbf;
	case 7618ULL: goto x86_l_1dc2;
	case 7622ULL: goto x86_l_1dc6;
	case 7627ULL: goto x86_l_1dcb;
	case 7630ULL: goto x86_l_1dce;
	case 7632ULL: goto x86_l_1dd0;
	case 7638ULL: goto x86_l_1dd6;
	case 7640ULL: goto x86_l_1dd8;
	case 7646ULL: goto x86_l_1dde;
	case 7649ULL: goto x86_l_1de1;
	case 7653ULL: goto x86_l_1de5;
	case 7658ULL: goto x86_l_1dea;
	case 7662ULL: goto x86_l_1dee;
	case 7665ULL: goto x86_l_1df1;
	case 7671ULL: goto x86_l_1df7;
	case 7674ULL: goto x86_l_1dfa;
	case 7680ULL: goto x86_l_1e00;
	case 7686ULL: goto x86_l_1e06;
	case 7688ULL: goto x86_l_1e08;
	case 7691ULL: goto x86_l_1e0b;
	case 7695ULL: goto x86_l_1e0f;
	case 7699ULL: goto x86_l_1e13;
	case 7702ULL: goto x86_l_1e16;
	case 7706ULL: goto x86_l_1e1a;
	case 7710ULL: goto x86_l_1e1e;
	case 7712ULL: goto x86_l_1e20;
	case 7717ULL: goto x86_l_1e25;
	case 7721ULL: goto x86_l_1e29;
	case 7723ULL: goto x86_l_1e2b;
	case 7726ULL: goto x86_l_1e2e;
	case 7728ULL: goto x86_l_1e30;
	case 7731ULL: goto x86_l_1e33;
	case 7734ULL: goto x86_l_1e36;
	case 7737ULL: goto x86_l_1e39;
	case 7740ULL: goto x86_l_1e3c;
	case 7743ULL: goto x86_l_1e3f;
	case 7747ULL: goto x86_l_1e43;
	case 7750ULL: goto x86_l_1e46;
	case 7753ULL: goto x86_l_1e49;
	case 7755ULL: goto x86_l_1e4b;
	case 7760ULL: goto x86_l_1e50;
	case 7767ULL: goto x86_l_1e57;
	case 7773ULL: goto x86_l_1e5d;
	case 7776ULL: goto x86_l_1e60;
	case 7780ULL: goto x86_l_1e64;
	case 7784ULL: goto x86_l_1e68;
	case 7790ULL: goto x86_l_1e6e;
	case 7795ULL: goto x86_l_1e73;
	case 7798ULL: goto x86_l_1e76;
	case 7802ULL: goto x86_l_1e7a;
	case 7806ULL: goto x86_l_1e7e;
	case 7809ULL: goto x86_l_1e81;
	case 7815ULL: goto x86_l_1e87;
	case 7818ULL: goto x86_l_1e8a;
	case 7824ULL: goto x86_l_1e90;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1926:
	/* 0x1926: cmp    r10,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 9ULL);
x86_l_192a:
	/* 0x192a: ja     1953 <generic_rawtp_process_filter+0x1953> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1953;
	}
x86_l_192c:
	/* 0x192c: mov    r10d,DWORD PTR [r14+r10*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R10, 2), 32ULL);
x86_l_1931:
	/* 0x1931: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1935:
	/* 0x1935: jne    193f <generic_rawtp_process_filter+0x193f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_193f;
	}
x86_l_1937:
	/* 0x1937: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_193a:
	/* 0x193a: cmp    edx,r10d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R10, X86_WIDTH_32);
x86_l_193d:
	/* 0x193d: jne    1963 <generic_rawtp_process_filter+0x1963> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1963;
	}
x86_l_193f:
	/* 0x193f: xor    edx,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1942:
	/* 0x1942: mov    r10d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R9, X86_WIDTH_32);
x86_l_1945:
	/* 0x1945: xor    r10d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1949:
	/* 0x1949: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_194c:
	/* 0x194c: or     r10d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_194f:
	/* 0x194f: setne  r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_NE);
x86_l_1953:
	/* 0x1953: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1957:
	/* 0x1957: jne    1963 <generic_rawtp_process_filter+0x1963> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1963;
	}
x86_l_1959:
	/* 0x1959: and    ebp,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R11, X86_WIDTH_32, X86_ALU_AND);
x86_l_195c:
	/* 0x195c: and    edi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_32, X86_ALU_AND);
x86_l_195f:
	/* 0x195f: and    ebp,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDI, X86_WIDTH_32, X86_ALU_AND);
x86_l_1961:
	/* 0x1961: jmp    196b <generic_rawtp_process_filter+0x196b> */
	goto x86_l_196b;
x86_l_1963:
	/* 0x1963: or     r13d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R11, X86_WIDTH_32, X86_ALU_OR);
x86_l_1966:
	/* 0x1966: or     ebp,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_1968:
	/* 0x1968: or     ebp,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_32, X86_ALU_OR);
x86_l_196b:
	/* 0x196b: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_196d:
	/* 0x196d: je     2014 <generic_rawtp_process_filter+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_1973:
	/* 0x1973: shl    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_1976:
	/* 0x1976: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1978:
	/* 0x1978: and    edi,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 28ULL);
x86_l_197b:
	/* 0x197b: add    edi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_197e:
	/* 0x197e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1983:
	/* 0x1983: add    edx,0xfffffff0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 4294967280ULL);
x86_l_1986:
	/* 0x1986: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1988:
	/* 0x1988: je     1fdf <generic_rawtp_process_filter+0x1fdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8159ULL;
	}
x86_l_198e:
	/* 0x198e: mov    edx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_1990:
	/* 0x1990: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1996:
	/* 0x1996: lea    ebp,[rdi+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1999:
	/* 0x1999: mov    r12d,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_199d:
	/* 0x199d: mov    r11d,DWORD PTR [rdx+rax*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_19a2:
	/* 0x19a2: mov    r9d,DWORD PTR [rdx+rax*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 8ULL);
x86_l_19a7:
	/* 0x19a7: cmp    r9d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 3ULL);
x86_l_19ab:
	/* 0x19ab: mov    DWORD PTR [rsp+0x48],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19af:
	/* 0x19af: jbe    1a2a <generic_rawtp_process_filter+0x1a2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1a2a;
	}
x86_l_19b1:
	/* 0x19b1: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19b4:
	/* 0x19b4: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_19b9:
	/* 0x19b9: cmp    edi,0x3dc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 988ULL);
x86_l_19bf:
	/* 0x19bf: ja     19c9 <generic_rawtp_process_filter+0x19c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_19c9;
	}
x86_l_19c1:
	/* 0x19c1: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_19c3:
	/* 0x19c3: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_19c6:
	/* 0x19c6: mov    edx,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_19c9:
	/* 0x19c9: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_19cc:
	/* 0x19cc: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_19d0:
	/* 0x19d0: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_19d4:
	/* 0x19d4: ja     19fa <generic_rawtp_process_filter+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_19fa;
	}
x86_l_19d6:
	/* 0x19d6: mov    r8d,DWORD PTR [r14+r8*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 32ULL);
x86_l_19db:
	/* 0x19db: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_19df:
	/* 0x19df: jne    19e6 <generic_rawtp_process_filter+0x19e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19e6;
	}
x86_l_19e1:
	/* 0x19e1: cmp    edx,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_19e4:
	/* 0x19e4: jne    19fa <generic_rawtp_process_filter+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19fa;
	}
x86_l_19e6:
	/* 0x19e6: xor    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19e9:
	/* 0x19e9: mov    r8d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R11, X86_WIDTH_32);
x86_l_19ec:
	/* 0x19ec: xor    r8d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_19f0:
	/* 0x19f0: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19f3:
	/* 0x19f3: or     r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_19f6:
	/* 0x19f6: setne  r10b */
	X86_SIM_L_EXEC_SETCC(X86_R10, X86_CC_NE);
x86_l_19fa:
	/* 0x19fa: add    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_19fd:
	/* 0x19fd: mov    r13d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_32);
x86_l_1a00:
	/* 0x1a00: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a02:
	/* 0x1a02: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1a07:
	/* 0x1a07: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1a0e:
	/* 0x1a0e: jbe    1a99 <generic_rawtp_process_filter+0x1a99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1a99;
	}
x86_l_1a14:
	/* 0x1a14: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1a17:
	/* 0x1a17: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1a1b:
	/* 0x1a1b: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1a1f:
	/* 0x1a1f: jbe    1aaf <generic_rawtp_process_filter+0x1aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1aaf;
	}
x86_l_1a25:
	/* 0x1a25: jmp    1ad2 <generic_rawtp_process_filter+0x1ad2> */
	goto x86_l_1ad2;
x86_l_1a2a:
	/* 0x1a2a: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a2d:
	/* 0x1a2d: cmp    r11d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 6ULL);
x86_l_1a31:
	/* 0x1a31: sete   r10b */
	X86_SIM_L_EXEC_SETCC(X86_R10, X86_CC_E);
x86_l_1a35:
	/* 0x1a35: cmp    r9d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 1ULL);
x86_l_1a39:
	/* 0x1a39: je     1c9a <generic_rawtp_process_filter+0x1c9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c9a;
	}
x86_l_1a3f:
	/* 0x1a3f: cmp    r9d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 2ULL);
x86_l_1a43:
	/* 0x1a43: je     1c7b <generic_rawtp_process_filter+0x1c7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c7b;
	}
x86_l_1a49:
	/* 0x1a49: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_1a4c:
	/* 0x1a4c: cmp    r9d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 3ULL);
x86_l_1a50:
	/* 0x1a50: jne    19b1 <generic_rawtp_process_filter+0x19b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19b1;
	}
x86_l_1a56:
	/* 0x1a56: jmp    1a00 <generic_rawtp_process_filter+0x1a00> */
	goto x86_l_1a00;
x86_l_1a58:
	/* 0x1a58: mov    r11d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDI, X86_WIDTH_32);
x86_l_1a5b:
	/* 0x1a5b: mov    r12d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_32);
x86_l_1a5e:
	/* 0x1a5e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a60:
	/* 0x1a60: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1a65:
	/* 0x1a65: cmp    r12d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1000ULL);
x86_l_1a6c:
	/* 0x1a6c: jbe    18cc <generic_rawtp_process_filter+0x18cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 6348ULL;
	}
x86_l_1a72:
	/* 0x1a72: jmp    18d5 <generic_rawtp_process_filter+0x18d5> */
	return 6357ULL;
x86_l_1a77:
	/* 0x1a77: mov    ebp,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_32);
x86_l_1a79:
	/* 0x1a79: mov    r11d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDI, X86_WIDTH_32);
x86_l_1a7c:
	/* 0x1a7c: mov    r12d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_32);
x86_l_1a7f:
	/* 0x1a7f: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a82:
	/* 0x1a82: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1a87:
	/* 0x1a87: cmp    r12d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1000ULL);
x86_l_1a8e:
	/* 0x1a8e: jbe    191a <generic_rawtp_process_filter+0x191a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 6426ULL;
	}
x86_l_1a94:
	/* 0x1a94: jmp    1922 <generic_rawtp_process_filter+0x1922> */
	return 6434ULL;
x86_l_1a99:
	/* 0x1a99: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_1a9c:
	/* 0x1a9c: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1a9f:
	/* 0x1a9f: mov    edx,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1aa2:
	/* 0x1aa2: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1aa5:
	/* 0x1aa5: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1aa9:
	/* 0x1aa9: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1aad:
	/* 0x1aad: ja     1ad2 <generic_rawtp_process_filter+0x1ad2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ad2;
	}
x86_l_1aaf:
	/* 0x1aaf: mov    r8d,DWORD PTR [r14+r8*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 32ULL);
x86_l_1ab4:
	/* 0x1ab4: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1ab8:
	/* 0x1ab8: jne    1abf <generic_rawtp_process_filter+0x1abf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1abf;
	}
x86_l_1aba:
	/* 0x1aba: cmp    edx,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_1abd:
	/* 0x1abd: jne    1ad2 <generic_rawtp_process_filter+0x1ad2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ad2;
	}
x86_l_1abf:
	/* 0x1abf: xor    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ac2:
	/* 0x1ac2: mov    r8d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R11, X86_WIDTH_32);
x86_l_1ac5:
	/* 0x1ac5: xor    r8d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1ac9:
	/* 0x1ac9: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1acb:
	/* 0x1acb: or     r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1ace:
	/* 0x1ace: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_1ad2:
	/* 0x1ad2: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1ad6:
	/* 0x1ad6: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ad8:
	/* 0x1ad8: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1add:
	/* 0x1add: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1ae4:
	/* 0x1ae4: ja     1aef <generic_rawtp_process_filter+0x1aef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1aef;
	}
x86_l_1ae6:
	/* 0x1ae6: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_1ae9:
	/* 0x1ae9: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1aec:
	/* 0x1aec: mov    edx,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1aef:
	/* 0x1aef: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1af2:
	/* 0x1af2: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1af6:
	/* 0x1af6: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1afa:
	/* 0x1afa: ja     1b1f <generic_rawtp_process_filter+0x1b1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b1f;
	}
x86_l_1afc:
	/* 0x1afc: mov    r8d,DWORD PTR [r14+r8*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 32ULL);
x86_l_1b01:
	/* 0x1b01: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1b05:
	/* 0x1b05: jne    1b0c <generic_rawtp_process_filter+0x1b0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b0c;
	}
x86_l_1b07:
	/* 0x1b07: cmp    edx,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_1b0a:
	/* 0x1b0a: jne    1b1f <generic_rawtp_process_filter+0x1b1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b1f;
	}
x86_l_1b0c:
	/* 0x1b0c: xor    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b0f:
	/* 0x1b0f: mov    r8d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R11, X86_WIDTH_32);
x86_l_1b12:
	/* 0x1b12: xor    r8d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1b16:
	/* 0x1b16: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b18:
	/* 0x1b18: or     r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1b1b:
	/* 0x1b1b: setne  bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_NE);
x86_l_1b1f:
	/* 0x1b1f: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1b23:
	/* 0x1b23: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b26:
	/* 0x1b26: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1b2b:
	/* 0x1b2b: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1b32:
	/* 0x1b32: ja     1b3c <generic_rawtp_process_filter+0x1b3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b3c;
	}
x86_l_1b34:
	/* 0x1b34: and    r13d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1b38:
	/* 0x1b38: mov    edx,DWORD PTR [rax+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1b3c:
	/* 0x1b3c: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1b40:
	/* 0x1b40: cmp    r12,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 9ULL);
x86_l_1b44:
	/* 0x1b44: ja     1b6d <generic_rawtp_process_filter+0x1b6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b6d;
	}
x86_l_1b46:
	/* 0x1b46: mov    r12d,DWORD PTR [r14+r12*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 32ULL);
x86_l_1b4b:
	/* 0x1b4b: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1b4f:
	/* 0x1b4f: jne    1b59 <generic_rawtp_process_filter+0x1b59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b59;
	}
x86_l_1b51:
	/* 0x1b51: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b54:
	/* 0x1b54: cmp    edx,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_1b57:
	/* 0x1b57: jne    1b7d <generic_rawtp_process_filter+0x1b7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b7d;
	}
x86_l_1b59:
	/* 0x1b59: xor    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b5c:
	/* 0x1b5c: mov    r12d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R11, X86_WIDTH_32);
x86_l_1b5f:
	/* 0x1b5f: xor    r12d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1b63:
	/* 0x1b63: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b66:
	/* 0x1b66: or     r12d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1b69:
	/* 0x1b69: setne  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_NE);
x86_l_1b6d:
	/* 0x1b6d: cmp    r11d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 6ULL);
x86_l_1b71:
	/* 0x1b71: jne    1b7d <generic_rawtp_process_filter+0x1b7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b7d;
	}
x86_l_1b73:
	/* 0x1b73: and    ebp,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDI, X86_WIDTH_32, X86_ALU_AND);
x86_l_1b75:
	/* 0x1b75: and    r10d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R8, X86_WIDTH_32, X86_ALU_AND);
x86_l_1b78:
	/* 0x1b78: and    ebp,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R10, X86_WIDTH_32, X86_ALU_AND);
x86_l_1b7b:
	/* 0x1b7b: jmp    1b86 <generic_rawtp_process_filter+0x1b86> */
	goto x86_l_1b86;
x86_l_1b7d:
	/* 0x1b7d: or     r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_1b80:
	/* 0x1b80: or     ebp,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R10, X86_WIDTH_32, X86_ALU_OR);
x86_l_1b83:
	/* 0x1b83: or     ebp,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_32, X86_ALU_OR);
x86_l_1b86:
	/* 0x1b86: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1b88:
	/* 0x1b88: je     2014 <generic_rawtp_process_filter+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_1b8e:
	/* 0x1b8e: lea    edi,[r9*4+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 2), 0ULL);
x86_l_1b96:
	/* 0x1b96: and    edi,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 28ULL);
x86_l_1b99:
	/* 0x1b99: add    edi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_1b9d:
	/* 0x1b9d: lea    esi,[rsi+r9*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 2), 0ULL);
x86_l_1ba1:
	/* 0x1ba1: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ba6:
	/* 0x1ba6: add    edx,0xffffffe4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 4294967268ULL);
x86_l_1ba9:
	/* 0x1ba9: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1bab:
	/* 0x1bab: je     1fdf <generic_rawtp_process_filter+0x1fdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8159ULL;
	}
x86_l_1bb1:
	/* 0x1bb1: mov    edx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_1bb3:
	/* 0x1bb3: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1bb9:
	/* 0x1bb9: lea    ebp,[rdi+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1bbc:
	/* 0x1bbc: mov    r12d,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1bc0:
	/* 0x1bc0: mov    r11d,DWORD PTR [rdx+rax*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_1bc5:
	/* 0x1bc5: mov    r9d,DWORD PTR [rdx+rax*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 8ULL);
x86_l_1bca:
	/* 0x1bca: cmp    r9d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 3ULL);
x86_l_1bce:
	/* 0x1bce: mov    DWORD PTR [rsp+0x48],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1bd2:
	/* 0x1bd2: jbe    1c4d <generic_rawtp_process_filter+0x1c4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1c4d;
	}
x86_l_1bd4:
	/* 0x1bd4: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bd7:
	/* 0x1bd7: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1bdc:
	/* 0x1bdc: cmp    edi,0x3dc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 988ULL);
x86_l_1be2:
	/* 0x1be2: ja     1bec <generic_rawtp_process_filter+0x1bec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1bec;
	}
x86_l_1be4:
	/* 0x1be4: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1be6:
	/* 0x1be6: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1be9:
	/* 0x1be9: mov    edx,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1bec:
	/* 0x1bec: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1bef:
	/* 0x1bef: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1bf3:
	/* 0x1bf3: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1bf7:
	/* 0x1bf7: ja     1c1d <generic_rawtp_process_filter+0x1c1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c1d;
	}
x86_l_1bf9:
	/* 0x1bf9: mov    r8d,DWORD PTR [r14+r8*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 32ULL);
x86_l_1bfe:
	/* 0x1bfe: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1c02:
	/* 0x1c02: jne    1c09 <generic_rawtp_process_filter+0x1c09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c09;
	}
x86_l_1c04:
	/* 0x1c04: cmp    edx,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_1c07:
	/* 0x1c07: jne    1c1d <generic_rawtp_process_filter+0x1c1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c1d;
	}
x86_l_1c09:
	/* 0x1c09: xor    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c0c:
	/* 0x1c0c: mov    r8d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R11, X86_WIDTH_32);
x86_l_1c0f:
	/* 0x1c0f: xor    r8d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1c13:
	/* 0x1c13: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c16:
	/* 0x1c16: or     r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1c19:
	/* 0x1c19: setne  r10b */
	X86_SIM_L_EXEC_SETCC(X86_R10, X86_CC_NE);
x86_l_1c1d:
	/* 0x1c1d: add    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_1c20:
	/* 0x1c20: mov    r13d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_32);
x86_l_1c23:
	/* 0x1c23: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c25:
	/* 0x1c25: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1c2a:
	/* 0x1c2a: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1c31:
	/* 0x1c31: jbe    1cbf <generic_rawtp_process_filter+0x1cbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1cbf;
	}
x86_l_1c37:
	/* 0x1c37: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1c3a:
	/* 0x1c3a: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1c3e:
	/* 0x1c3e: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1c42:
	/* 0x1c42: jbe    1cd5 <generic_rawtp_process_filter+0x1cd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1cd5;
	}
x86_l_1c48:
	/* 0x1c48: jmp    1cf8 <generic_rawtp_process_filter+0x1cf8> */
	goto x86_l_1cf8;
x86_l_1c4d:
	/* 0x1c4d: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c50:
	/* 0x1c50: cmp    r11d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 6ULL);
x86_l_1c54:
	/* 0x1c54: sete   r10b */
	X86_SIM_L_EXEC_SETCC(X86_R10, X86_CC_E);
x86_l_1c58:
	/* 0x1c58: cmp    r9d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 1ULL);
x86_l_1c5c:
	/* 0x1c5c: je     1ebd <generic_rawtp_process_filter+0x1ebd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7869ULL;
	}
x86_l_1c62:
	/* 0x1c62: cmp    r9d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 2ULL);
x86_l_1c66:
	/* 0x1c66: je     1e9e <generic_rawtp_process_filter+0x1e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7838ULL;
	}
x86_l_1c6c:
	/* 0x1c6c: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_1c6f:
	/* 0x1c6f: cmp    r9d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 3ULL);
x86_l_1c73:
	/* 0x1c73: jne    1bd4 <generic_rawtp_process_filter+0x1bd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bd4;
	}
x86_l_1c79:
	/* 0x1c79: jmp    1c23 <generic_rawtp_process_filter+0x1c23> */
	goto x86_l_1c23;
x86_l_1c7b:
	/* 0x1c7b: mov    edi,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R10, X86_WIDTH_32);
x86_l_1c7e:
	/* 0x1c7e: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_1c81:
	/* 0x1c81: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c83:
	/* 0x1c83: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1c88:
	/* 0x1c88: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1c8f:
	/* 0x1c8f: jbe    1ae6 <generic_rawtp_process_filter+0x1ae6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1ae6;
	}
x86_l_1c95:
	/* 0x1c95: jmp    1aef <generic_rawtp_process_filter+0x1aef> */
	goto x86_l_1aef;
x86_l_1c9a:
	/* 0x1c9a: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1c9c:
	/* 0x1c9c: mov    ebp,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R10, X86_WIDTH_32);
x86_l_1c9f:
	/* 0x1c9f: mov    edi,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R10, X86_WIDTH_32);
x86_l_1ca2:
	/* 0x1ca2: mov    r13d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_32);
x86_l_1ca5:
	/* 0x1ca5: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ca8:
	/* 0x1ca8: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1cad:
	/* 0x1cad: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1cb4:
	/* 0x1cb4: jbe    1b34 <generic_rawtp_process_filter+0x1b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1b34;
	}
x86_l_1cba:
	/* 0x1cba: jmp    1b3c <generic_rawtp_process_filter+0x1b3c> */
	goto x86_l_1b3c;
x86_l_1cbf:
	/* 0x1cbf: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_1cc2:
	/* 0x1cc2: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1cc5:
	/* 0x1cc5: mov    edx,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1cc8:
	/* 0x1cc8: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1ccb:
	/* 0x1ccb: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1ccf:
	/* 0x1ccf: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1cd3:
	/* 0x1cd3: ja     1cf8 <generic_rawtp_process_filter+0x1cf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1cf8;
	}
x86_l_1cd5:
	/* 0x1cd5: mov    r8d,DWORD PTR [r14+r8*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 32ULL);
x86_l_1cda:
	/* 0x1cda: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1cde:
	/* 0x1cde: jne    1ce5 <generic_rawtp_process_filter+0x1ce5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ce5;
	}
x86_l_1ce0:
	/* 0x1ce0: cmp    edx,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_1ce3:
	/* 0x1ce3: jne    1cf8 <generic_rawtp_process_filter+0x1cf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1cf8;
	}
x86_l_1ce5:
	/* 0x1ce5: xor    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ce8:
	/* 0x1ce8: mov    r8d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R11, X86_WIDTH_32);
x86_l_1ceb:
	/* 0x1ceb: xor    r8d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1cef:
	/* 0x1cef: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cf1:
	/* 0x1cf1: or     r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1cf4:
	/* 0x1cf4: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_1cf8:
	/* 0x1cf8: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1cfc:
	/* 0x1cfc: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cfe:
	/* 0x1cfe: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1d03:
	/* 0x1d03: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1d0a:
	/* 0x1d0a: ja     1d15 <generic_rawtp_process_filter+0x1d15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d15;
	}
x86_l_1d0c:
	/* 0x1d0c: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_1d0f:
	/* 0x1d0f: and    edx,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1d12:
	/* 0x1d12: mov    edx,DWORD PTR [rax+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1d15:
	/* 0x1d15: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1d18:
	/* 0x1d18: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1d1c:
	/* 0x1d1c: cmp    r8,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 9ULL);
x86_l_1d20:
	/* 0x1d20: ja     1d45 <generic_rawtp_process_filter+0x1d45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d45;
	}
x86_l_1d22:
	/* 0x1d22: mov    r8d,DWORD PTR [r14+r8*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 32ULL);
x86_l_1d27:
	/* 0x1d27: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1d2b:
	/* 0x1d2b: jne    1d32 <generic_rawtp_process_filter+0x1d32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d32;
	}
x86_l_1d2d:
	/* 0x1d2d: cmp    edx,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_1d30:
	/* 0x1d30: jne    1d45 <generic_rawtp_process_filter+0x1d45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d45;
	}
x86_l_1d32:
	/* 0x1d32: xor    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d35:
	/* 0x1d35: mov    r8d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R11, X86_WIDTH_32);
x86_l_1d38:
	/* 0x1d38: xor    r8d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1d3c:
	/* 0x1d3c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d3e:
	/* 0x1d3e: or     r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1d41:
	/* 0x1d41: setne  bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_NE);
x86_l_1d45:
	/* 0x1d45: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1d49:
	/* 0x1d49: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d4c:
	/* 0x1d4c: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1d51:
	/* 0x1d51: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1d58:
	/* 0x1d58: ja     1d62 <generic_rawtp_process_filter+0x1d62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d62;
	}
x86_l_1d5a:
	/* 0x1d5a: and    r13d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1d5e:
	/* 0x1d5e: mov    edx,DWORD PTR [rax+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1d62:
	/* 0x1d62: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1d66:
	/* 0x1d66: cmp    r12,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 9ULL);
x86_l_1d6a:
	/* 0x1d6a: ja     1d93 <generic_rawtp_process_filter+0x1d93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d93;
	}
x86_l_1d6c:
	/* 0x1d6c: mov    r12d,DWORD PTR [r14+r12*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 32ULL);
x86_l_1d71:
	/* 0x1d71: cmp    r11d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 5ULL);
x86_l_1d75:
	/* 0x1d75: jne    1d7f <generic_rawtp_process_filter+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d7f;
	}
x86_l_1d77:
	/* 0x1d77: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d7a:
	/* 0x1d7a: cmp    edx,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_1d7d:
	/* 0x1d7d: jne    1da3 <generic_rawtp_process_filter+0x1da3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1da3;
	}
x86_l_1d7f:
	/* 0x1d7f: xor    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d82:
	/* 0x1d82: mov    r12d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R11, X86_WIDTH_32);
x86_l_1d85:
	/* 0x1d85: xor    r12d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1d89:
	/* 0x1d89: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d8c:
	/* 0x1d8c: or     r12d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1d8f:
	/* 0x1d8f: setne  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_NE);
x86_l_1d93:
	/* 0x1d93: cmp    r11d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 6ULL);
x86_l_1d97:
	/* 0x1d97: jne    1da3 <generic_rawtp_process_filter+0x1da3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1da3;
	}
x86_l_1d99:
	/* 0x1d99: and    ebp,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDI, X86_WIDTH_32, X86_ALU_AND);
x86_l_1d9b:
	/* 0x1d9b: and    r10d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R8, X86_WIDTH_32, X86_ALU_AND);
x86_l_1d9e:
	/* 0x1d9e: and    ebp,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R10, X86_WIDTH_32, X86_ALU_AND);
x86_l_1da1:
	/* 0x1da1: jmp    1dac <generic_rawtp_process_filter+0x1dac> */
	goto x86_l_1dac;
x86_l_1da3:
	/* 0x1da3: or     r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_1da6:
	/* 0x1da6: or     ebp,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R10, X86_WIDTH_32, X86_ALU_OR);
x86_l_1da9:
	/* 0x1da9: or     ebp,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_32, X86_ALU_OR);
x86_l_1dac:
	/* 0x1dac: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1dae:
	/* 0x1dae: je     2014 <generic_rawtp_process_filter+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8212ULL;
	}
x86_l_1db4:
	/* 0x1db4: shl    r9d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_1db8:
	/* 0x1db8: add    esi,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1dbb:
	/* 0x1dbb: and    r9d,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_AND, 28ULL);
x86_l_1dbf:
	/* 0x1dbf: mov    edi,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R9, X86_WIDTH_32);
x86_l_1dc2:
	/* 0x1dc2: add    edi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_1dc6:
	/* 0x1dc6: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dcb:
	/* 0x1dcb: add    edx,0xffffffd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 4294967256ULL);
x86_l_1dce:
	/* 0x1dce: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1dd0:
	/* 0x1dd0: je     1fdf <generic_rawtp_process_filter+0x1fdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8159ULL;
	}
x86_l_1dd6:
	/* 0x1dd6: mov    esi,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_1dd8:
	/* 0x1dd8: and    esi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1dde:
	/* 0x1dde: lea    edx,[rdi+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1de1:
	/* 0x1de1: mov    r10d,DWORD PTR [rsi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1de5:
	/* 0x1de5: mov    r9d,DWORD PTR [rsi+rax*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_1dea:
	/* 0x1dea: mov    esi,DWORD PTR [rsi+rax*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 8ULL);
x86_l_1dee:
	/* 0x1dee: cmp    esi,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 3ULL);
x86_l_1df1:
	/* 0x1df1: jbe    1e73 <generic_rawtp_process_filter+0x1e73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e73;
	}
x86_l_1df7:
	/* 0x1df7: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dfa:
	/* 0x1dfa: mov    r11d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_32, 0ULL);
x86_l_1e00:
	/* 0x1e00: cmp    edi,0x3dc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 988ULL);
x86_l_1e06:
	/* 0x1e06: ja     1e13 <generic_rawtp_process_filter+0x1e13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e13;
	}
x86_l_1e08:
	/* 0x1e08: mov    r11d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDX, X86_WIDTH_32);
x86_l_1e0b:
	/* 0x1e0b: and    r11d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1e0f:
	/* 0x1e0f: mov    r11d,DWORD PTR [rax+r11*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_1e13:
	/* 0x1e13: mov    r12d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R10, X86_WIDTH_32);
x86_l_1e16:
	/* 0x1e16: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1e1a:
	/* 0x1e1a: cmp    r12,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 9ULL);
x86_l_1e1e:
	/* 0x1e1e: ja     1e43 <generic_rawtp_process_filter+0x1e43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e43;
	}
x86_l_1e20:
	/* 0x1e20: mov    ebp,DWORD PTR [r14+r12*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 32ULL);
x86_l_1e25:
	/* 0x1e25: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1e29:
	/* 0x1e29: jne    1e30 <generic_rawtp_process_filter+0x1e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e30;
	}
x86_l_1e2b:
	/* 0x1e2b: cmp    r11d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R11, X86_RBP, X86_WIDTH_32);
x86_l_1e2e:
	/* 0x1e2e: jne    1e43 <generic_rawtp_process_filter+0x1e43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e43;
	}
x86_l_1e30:
	/* 0x1e30: xor    r11d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e33:
	/* 0x1e33: mov    ebp,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R9, X86_WIDTH_32);
x86_l_1e36:
	/* 0x1e36: xor    ebp,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1e39:
	/* 0x1e39: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e3c:
	/* 0x1e3c: or     ebp,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R11, X86_WIDTH_32, X86_ALU_OR);
x86_l_1e3f:
	/* 0x1e3f: setne  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_NE);
x86_l_1e43:
	/* 0x1e43: add    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_1e46:
	/* 0x1e46: mov    r11d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDI, X86_WIDTH_32);
x86_l_1e49:
	/* 0x1e49: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e4b:
	/* 0x1e4b: mov    ebp,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 0ULL);
x86_l_1e50:
	/* 0x1e50: cmp    r11d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 1000ULL);
x86_l_1e57:
	/* 0x1e57: jbe    1ee2 <generic_rawtp_process_filter+0x1ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 7906ULL;
	}
x86_l_1e5d:
	/* 0x1e5d: mov    r12d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R10, X86_WIDTH_32);
x86_l_1e60:
	/* 0x1e60: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1e64:
	/* 0x1e64: cmp    r12,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 9ULL);
x86_l_1e68:
	/* 0x1e68: jbe    1efa <generic_rawtp_process_filter+0x1efa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 7930ULL;
	}
x86_l_1e6e:
	/* 0x1e6e: jmp    1f1d <generic_rawtp_process_filter+0x1f1d> */
	return 7965ULL;
x86_l_1e73:
	/* 0x1e73: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e76:
	/* 0x1e76: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1e7a:
	/* 0x1e7a: sete   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_E);
x86_l_1e7e:
	/* 0x1e7e: cmp    esi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1e81:
	/* 0x1e81: je     2103 <generic_rawtp_process_filter+0x2103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8451ULL;
	}
x86_l_1e87:
	/* 0x1e87: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1e8a:
	/* 0x1e8a: je     20e3 <generic_rawtp_process_filter+0x20e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8419ULL;
	}
x86_l_1e90:
	/* 0x1e90: mov    r11d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDX, X86_WIDTH_32);
	return 7827ULL;
}

static __noinline __u64 tetragon_bpf_generic_rawtp_generic_rawtp_process_filter_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7827ULL: goto x86_l_1e93;
	case 7830ULL: goto x86_l_1e96;
	case 7836ULL: goto x86_l_1e9c;
	case 7838ULL: goto x86_l_1e9e;
	case 7841ULL: goto x86_l_1ea1;
	case 7844ULL: goto x86_l_1ea4;
	case 7846ULL: goto x86_l_1ea6;
	case 7851ULL: goto x86_l_1eab;
	case 7858ULL: goto x86_l_1eb2;
	case 7864ULL: goto x86_l_1eb8;
	case 7869ULL: goto x86_l_1ebd;
	case 7871ULL: goto x86_l_1ebf;
	case 7874ULL: goto x86_l_1ec2;
	case 7877ULL: goto x86_l_1ec5;
	case 7880ULL: goto x86_l_1ec8;
	case 7883ULL: goto x86_l_1ecb;
	case 7888ULL: goto x86_l_1ed0;
	case 7895ULL: goto x86_l_1ed7;
	case 7901ULL: goto x86_l_1edd;
	case 7906ULL: goto x86_l_1ee2;
	case 7909ULL: goto x86_l_1ee5;
	case 7913ULL: goto x86_l_1ee9;
	case 7917ULL: goto x86_l_1eed;
	case 7920ULL: goto x86_l_1ef0;
	case 7924ULL: goto x86_l_1ef4;
	case 7928ULL: goto x86_l_1ef8;
	case 7930ULL: goto x86_l_1efa;
	case 7935ULL: goto x86_l_1eff;
	case 7939ULL: goto x86_l_1f03;
	case 7941ULL: goto x86_l_1f05;
	case 7944ULL: goto x86_l_1f08;
	case 7946ULL: goto x86_l_1f0a;
	case 7949ULL: goto x86_l_1f0d;
	case 7952ULL: goto x86_l_1f10;
	case 7956ULL: goto x86_l_1f14;
	case 7958ULL: goto x86_l_1f16;
	case 7961ULL: goto x86_l_1f19;
	case 7965ULL: goto x86_l_1f1d;
	case 7969ULL: goto x86_l_1f21;
	case 7971ULL: goto x86_l_1f23;
	case 7977ULL: goto x86_l_1f29;
	case 7984ULL: goto x86_l_1f30;
	case 7986ULL: goto x86_l_1f32;
	case 7989ULL: goto x86_l_1f35;
	case 7993ULL: goto x86_l_1f39;
	case 7997ULL: goto x86_l_1f3d;
	case 8000ULL: goto x86_l_1f40;
	case 8004ULL: goto x86_l_1f44;
	case 8008ULL: goto x86_l_1f48;
	case 8010ULL: goto x86_l_1f4a;
	case 8015ULL: goto x86_l_1f4f;
	case 8019ULL: goto x86_l_1f53;
	case 8021ULL: goto x86_l_1f55;
	case 8024ULL: goto x86_l_1f58;
	case 8026ULL: goto x86_l_1f5a;
	case 8029ULL: goto x86_l_1f5d;
	case 8032ULL: goto x86_l_1f60;
	case 8036ULL: goto x86_l_1f64;
	case 8038ULL: goto x86_l_1f66;
	case 8041ULL: goto x86_l_1f69;
	case 8045ULL: goto x86_l_1f6d;
	case 8049ULL: goto x86_l_1f71;
	case 8052ULL: goto x86_l_1f74;
	case 8058ULL: goto x86_l_1f7a;
	case 8065ULL: goto x86_l_1f81;
	case 8067ULL: goto x86_l_1f83;
	case 8071ULL: goto x86_l_1f87;
	case 8075ULL: goto x86_l_1f8b;
	case 8079ULL: goto x86_l_1f8f;
	case 8083ULL: goto x86_l_1f93;
	case 8085ULL: goto x86_l_1f95;
	case 8090ULL: goto x86_l_1f9a;
	case 8094ULL: goto x86_l_1f9e;
	case 8096ULL: goto x86_l_1fa0;
	case 8099ULL: goto x86_l_1fa3;
	case 8102ULL: goto x86_l_1fa6;
	case 8104ULL: goto x86_l_1fa8;
	case 8107ULL: goto x86_l_1fab;
	case 8110ULL: goto x86_l_1fae;
	case 8114ULL: goto x86_l_1fb2;
	case 8117ULL: goto x86_l_1fb5;
	case 8120ULL: goto x86_l_1fb8;
	case 8124ULL: goto x86_l_1fbc;
	case 8128ULL: goto x86_l_1fc0;
	case 8130ULL: goto x86_l_1fc2;
	case 8132ULL: goto x86_l_1fc4;
	case 8135ULL: goto x86_l_1fc7;
	case 8138ULL: goto x86_l_1fca;
	case 8140ULL: goto x86_l_1fcc;
	case 8143ULL: goto x86_l_1fcf;
	case 8146ULL: goto x86_l_1fd2;
	case 8149ULL: goto x86_l_1fd5;
	case 8151ULL: goto x86_l_1fd7;
	case 8153ULL: goto x86_l_1fd9;
	case 8156ULL: goto x86_l_1fdc;
	case 8159ULL: goto x86_l_1fdf;
	case 8161ULL: goto x86_l_1fe1;
	case 8167ULL: goto x86_l_1fe7;
	case 8171ULL: goto x86_l_1feb;
	case 8177ULL: goto x86_l_1ff1;
	case 8184ULL: goto x86_l_1ff8;
	case 8187ULL: goto x86_l_1ffb;
	case 8196ULL: goto x86_l_2004;
	case 8204ULL: goto x86_l_200c;
	case 8212ULL: goto x86_l_2014;
	case 8219ULL: goto x86_l_201b;
	case 8222ULL: goto x86_l_201e;
	case 8229ULL: goto x86_l_2025;
	case 8232ULL: goto x86_l_2028;
	case 8234ULL: goto x86_l_202a;
	case 8236ULL: goto x86_l_202c;
	case 8240ULL: goto x86_l_2030;
	case 8244ULL: goto x86_l_2034;
	case 8248ULL: goto x86_l_2038;
	case 8256ULL: goto x86_l_2040;
	case 8258ULL: goto x86_l_2042;
	case 8265ULL: goto x86_l_2049;
	case 8267ULL: goto x86_l_204b;
	case 8272ULL: goto x86_l_2050;
	case 8275ULL: goto x86_l_2053;
	case 8277ULL: goto x86_l_2055;
	case 8279ULL: goto x86_l_2057;
	case 8281ULL: goto x86_l_2059;
	case 8285ULL: goto x86_l_205d;
	case 8287ULL: goto x86_l_205f;
	case 8288ULL: goto x86_l_2060;
	case 8293ULL: goto x86_l_2065;
	case 8300ULL: goto x86_l_206c;
	case 8305ULL: goto x86_l_2071;
	case 8310ULL: goto x86_l_2076;
	case 8313ULL: goto x86_l_2079;
	case 8318ULL: goto x86_l_207e;
	case 8320ULL: goto x86_l_2080;
	case 8323ULL: goto x86_l_2083;
	case 8329ULL: goto x86_l_2089;
	case 8332ULL: goto x86_l_208c;
	case 8336ULL: goto x86_l_2090;
	case 8341ULL: goto x86_l_2095;
	case 8346ULL: goto x86_l_209a;
	case 8349ULL: goto x86_l_209d;
	case 8351ULL: goto x86_l_209f;
	case 8354ULL: goto x86_l_20a2;
	case 8360ULL: goto x86_l_20a8;
	case 8364ULL: goto x86_l_20ac;
	case 8366ULL: goto x86_l_20ae;
	case 8371ULL: goto x86_l_20b3;
	case 8374ULL: goto x86_l_20b6;
	case 8380ULL: goto x86_l_20bc;
	case 8382ULL: goto x86_l_20be;
	case 8385ULL: goto x86_l_20c1;
	case 8390ULL: goto x86_l_20c6;
	case 8394ULL: goto x86_l_20ca;
	case 8398ULL: goto x86_l_20ce;
	case 8401ULL: goto x86_l_20d1;
	case 8405ULL: goto x86_l_20d5;
	case 8408ULL: goto x86_l_20d8;
	case 8414ULL: goto x86_l_20de;
	case 8419ULL: goto x86_l_20e3;
	case 8422ULL: goto x86_l_20e6;
	case 8425ULL: goto x86_l_20e9;
	case 8427ULL: goto x86_l_20eb;
	case 8433ULL: goto x86_l_20f1;
	case 8440ULL: goto x86_l_20f8;
	case 8446ULL: goto x86_l_20fe;
	case 8451ULL: goto x86_l_2103;
	case 8454ULL: goto x86_l_2106;
	case 8457ULL: goto x86_l_2109;
	case 8460ULL: goto x86_l_210c;
	case 8463ULL: goto x86_l_210f;
	case 8469ULL: goto x86_l_2115;
	case 8476ULL: goto x86_l_211c;
	case 8482ULL: goto x86_l_2122;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1e93:
	/* 0x1e93: cmp    esi,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 3ULL);
x86_l_1e96:
	/* 0x1e96: jne    1df7 <generic_rawtp_process_filter+0x1df7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7671ULL;
	}
x86_l_1e9c:
	/* 0x1e9c: jmp    1e49 <generic_rawtp_process_filter+0x1e49> */
	return 7753ULL;
x86_l_1e9e:
	/* 0x1e9e: mov    edi,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R10, X86_WIDTH_32);
x86_l_1ea1:
	/* 0x1ea1: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_1ea4:
	/* 0x1ea4: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ea6:
	/* 0x1ea6: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1eab:
	/* 0x1eab: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1eb2:
	/* 0x1eb2: jbe    1d0c <generic_rawtp_process_filter+0x1d0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 7436ULL;
	}
x86_l_1eb8:
	/* 0x1eb8: jmp    1d15 <generic_rawtp_process_filter+0x1d15> */
	return 7445ULL;
x86_l_1ebd:
	/* 0x1ebd: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1ebf:
	/* 0x1ebf: mov    ebp,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R10, X86_WIDTH_32);
x86_l_1ec2:
	/* 0x1ec2: mov    edi,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R10, X86_WIDTH_32);
x86_l_1ec5:
	/* 0x1ec5: mov    r13d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_32);
x86_l_1ec8:
	/* 0x1ec8: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ecb:
	/* 0x1ecb: mov    edx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 0ULL);
x86_l_1ed0:
	/* 0x1ed0: cmp    r13d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1000ULL);
x86_l_1ed7:
	/* 0x1ed7: jbe    1d5a <generic_rawtp_process_filter+0x1d5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 7514ULL;
	}
x86_l_1edd:
	/* 0x1edd: jmp    1d62 <generic_rawtp_process_filter+0x1d62> */
	return 7522ULL;
x86_l_1ee2:
	/* 0x1ee2: mov    r12d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R11, X86_WIDTH_32);
x86_l_1ee5:
	/* 0x1ee5: and    r12d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1ee9:
	/* 0x1ee9: mov    ebp,DWORD PTR [rax+r12*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1eed:
	/* 0x1eed: mov    r12d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R10, X86_WIDTH_32);
x86_l_1ef0:
	/* 0x1ef0: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1ef4:
	/* 0x1ef4: cmp    r12,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 9ULL);
x86_l_1ef8:
	/* 0x1ef8: ja     1f1d <generic_rawtp_process_filter+0x1f1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f1d;
	}
x86_l_1efa:
	/* 0x1efa: mov    r12d,DWORD PTR [r14+r12*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 32ULL);
x86_l_1eff:
	/* 0x1eff: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1f03:
	/* 0x1f03: jne    1f0a <generic_rawtp_process_filter+0x1f0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f0a;
	}
x86_l_1f05:
	/* 0x1f05: cmp    ebp,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R12, X86_WIDTH_32);
x86_l_1f08:
	/* 0x1f08: jne    1f1d <generic_rawtp_process_filter+0x1f1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f1d;
	}
x86_l_1f0a:
	/* 0x1f0a: xor    ebp,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f0d:
	/* 0x1f0d: mov    r12d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R9, X86_WIDTH_32);
x86_l_1f10:
	/* 0x1f10: xor    r12d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1f14:
	/* 0x1f14: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f16:
	/* 0x1f16: or     r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_OR);
x86_l_1f19:
	/* 0x1f19: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_1f1d:
	/* 0x1f1d: add    r11d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1f21:
	/* 0x1f21: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f23:
	/* 0x1f23: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_1f29:
	/* 0x1f29: cmp    r11d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 1000ULL);
x86_l_1f30:
	/* 0x1f30: ja     1f3d <generic_rawtp_process_filter+0x1f3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f3d;
	}
x86_l_1f32:
	/* 0x1f32: mov    r12d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R11, X86_WIDTH_32);
x86_l_1f35:
	/* 0x1f35: and    r12d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1f39:
	/* 0x1f39: mov    r12d,DWORD PTR [rax+r12*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1f3d:
	/* 0x1f3d: mov    r13d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R10, X86_WIDTH_32);
x86_l_1f40:
	/* 0x1f40: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1f44:
	/* 0x1f44: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_1f48:
	/* 0x1f48: ja     1f6d <generic_rawtp_process_filter+0x1f6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f6d;
	}
x86_l_1f4a:
	/* 0x1f4a: mov    r13d,DWORD PTR [r14+r13*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 32ULL);
x86_l_1f4f:
	/* 0x1f4f: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1f53:
	/* 0x1f53: jne    1f5a <generic_rawtp_process_filter+0x1f5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f5a;
	}
x86_l_1f55:
	/* 0x1f55: cmp    r12d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R13, X86_WIDTH_32);
x86_l_1f58:
	/* 0x1f58: jne    1f6d <generic_rawtp_process_filter+0x1f6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f6d;
	}
x86_l_1f5a:
	/* 0x1f5a: xor    r12d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f5d:
	/* 0x1f5d: mov    r13d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_32);
x86_l_1f60:
	/* 0x1f60: xor    r13d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1f64:
	/* 0x1f64: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f66:
	/* 0x1f66: or     r13d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_32, X86_ALU_OR);
x86_l_1f69:
	/* 0x1f69: setne  bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_NE);
x86_l_1f6d:
	/* 0x1f6d: add    r11d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1f71:
	/* 0x1f71: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f74:
	/* 0x1f74: mov    r13d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 0ULL);
x86_l_1f7a:
	/* 0x1f7a: cmp    r11d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 1000ULL);
x86_l_1f81:
	/* 0x1f81: ja     1f8b <generic_rawtp_process_filter+0x1f8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f8b;
	}
x86_l_1f83:
	/* 0x1f83: and    r11d,0xfffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 4294967292ULL);
x86_l_1f87:
	/* 0x1f87: mov    r13d,DWORD PTR [rax+r11*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_1f8b:
	/* 0x1f8b: and    r10d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1f8f:
	/* 0x1f8f: cmp    r10,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 9ULL);
x86_l_1f93:
	/* 0x1f93: ja     1fbc <generic_rawtp_process_filter+0x1fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1fbc;
	}
x86_l_1f95:
	/* 0x1f95: mov    r10d,DWORD PTR [r14+r10*4+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R10, 2), 32ULL);
x86_l_1f9a:
	/* 0x1f9a: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_1f9e:
	/* 0x1f9e: jne    1fa8 <generic_rawtp_process_filter+0x1fa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fa8;
	}
x86_l_1fa0:
	/* 0x1fa0: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fa3:
	/* 0x1fa3: cmp    r13d,r10d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R10, X86_WIDTH_32);
x86_l_1fa6:
	/* 0x1fa6: jne    1fcc <generic_rawtp_process_filter+0x1fcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fcc;
	}
x86_l_1fa8:
	/* 0x1fa8: xor    r13d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fab:
	/* 0x1fab: mov    r10d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R9, X86_WIDTH_32);
x86_l_1fae:
	/* 0x1fae: xor    r10d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_XOR, 6ULL);
x86_l_1fb2:
	/* 0x1fb2: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fb5:
	/* 0x1fb5: or     r10d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R13, X86_WIDTH_32, X86_ALU_OR);
x86_l_1fb8:
	/* 0x1fb8: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_1fbc:
	/* 0x1fbc: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1fc0:
	/* 0x1fc0: jne    1fcc <generic_rawtp_process_filter+0x1fcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fcc;
	}
x86_l_1fc2:
	/* 0x1fc2: and    ebp,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDI, X86_WIDTH_32, X86_ALU_AND);
x86_l_1fc4:
	/* 0x1fc4: and    r8d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R12, X86_WIDTH_32, X86_ALU_AND);
x86_l_1fc7:
	/* 0x1fc7: and    ebp,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_32, X86_ALU_AND);
x86_l_1fca:
	/* 0x1fca: jmp    1fd5 <generic_rawtp_process_filter+0x1fd5> */
	goto x86_l_1fd5;
x86_l_1fcc:
	/* 0x1fcc: or     r12d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_1fcf:
	/* 0x1fcf: or     ebp,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_32, X86_ALU_OR);
x86_l_1fd2:
	/* 0x1fd2: or     ebp,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_32, X86_ALU_OR);
x86_l_1fd5:
	/* 0x1fd5: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1fd7:
	/* 0x1fd7: je     2014 <generic_rawtp_process_filter+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2014;
	}
x86_l_1fd9:
	/* 0x1fd9: and    esi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1fdc:
	/* 0x1fdc: lea    edi,[rdx+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1fdf:
	/* 0x1fdf: mov    edx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_1fe1:
	/* 0x1fe1: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1fe7:
	/* 0x1fe7: cmp    DWORD PTR [rdx+rax*1],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_1feb:
	/* 0x1feb: jne    2080 <generic_rawtp_process_filter+0x2080> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2080;
	}
x86_l_1ff1:
	/* 0x1ff1: mov    rax,QWORD PTR [r14+0x5eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_1ff8:
	/* 0x1ff8: and    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 31ULL);
x86_l_1ffb:
	/* 0x1ffb: mov    BYTE PTR [r14+rax*1+0x5ec1],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 104183021699073ULL);
x86_l_2004:
	/* 0x2004: mov    BYTE PTR [r14+0x5ee0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685249ULL);
x86_l_200c:
	/* 0x200c: mov    BYTE PTR [r14+0x5ec0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731777ULL);
x86_l_2014:
	/* 0x2014: mov    rax,QWORD PTR [r14+0x5eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_201b:
	/* 0x201b: inc    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_201e:
	/* 0x201e: mov    QWORD PTR [r14+0x5eb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24248ULL);
x86_l_2025:
	/* 0x2025: cmp    rax,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_2028:
	/* 0x2028: jbe    2065 <generic_rawtp_process_filter+0x2065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2065;
	}
x86_l_202a:
	/* 0x202a: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_202c:
	/* 0x202c: mov    DWORD PTR [r14+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2030:
	/* 0x2030: mov    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2034:
	/* 0x2034: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2038:
	/* 0x2038: cmp    BYTE PTR [r14+0x5ec0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104178726731776ULL);
x86_l_2040:
	/* 0x2040: je     2057 <generic_rawtp_process_filter+0x2057> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2057;
	}
x86_l_2042:
	/* 0x2042: mov    rsi,QWORD PTR [rip+0x419f] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_2049:
	/* 0x2049: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_204b:
	/* 0x204b: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2050:
	/* 0x2050: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2053:
	/* 0x2053: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2055:
	/* 0x2055: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2057:
	/* 0x2057: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2059:
	/* 0x2059: add    rsp,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_205d:
	/* 0x205d: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_205f:
	/* 0x205f: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2060:
	/* 0x2060: jmp    2127 <generic_rawtp_process_filter+0x2127> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2065:
	/* 0x2065: mov    rsi,QWORD PTR [rip+0x41a2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_206c:
	/* 0x206c: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2071:
	/* 0x2071: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2076:
	/* 0x2076: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2079:
	/* 0x2079: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_207e:
	/* 0x207e: jmp    2055 <generic_rawtp_process_filter+0x2055> */
	goto x86_l_2055;
x86_l_2080:
	/* 0x2080: add    edi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2083:
	/* 0x2083: and    edi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_2089:
	/* 0x2089: mov    esi,DWORD PTR [rdi+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_208c:
	/* 0x208c: mov    edx,DWORD PTR [rdi+rax*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_2090:
	/* 0x2090: mov    r8d,DWORD PTR [rdi+rax*1+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 8ULL);
x86_l_2095:
	/* 0x2095: mov    rax,QWORD PTR [rdi+rax*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 12ULL);
x86_l_209a:
	/* 0x209a: test   r8d,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_32);
x86_l_209d:
	/* 0x209d: je     20b3 <generic_rawtp_process_filter+0x20b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20b3;
	}
x86_l_209f:
	/* 0x209f: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_20a2:
	/* 0x20a2: ja     2014 <generic_rawtp_process_filter+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2014;
	}
x86_l_20a8:
	/* 0x20a8: cmp    DWORD PTR [r14+0x44],r8d */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R14, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_20ac:
	/* 0x20ac: jne    20bc <generic_rawtp_process_filter+0x20bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_20bc;
	}
x86_l_20ae:
	/* 0x20ae: jmp    2014 <generic_rawtp_process_filter+0x2014> */
	goto x86_l_2014;
x86_l_20b3:
	/* 0x20b3: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_20b6:
	/* 0x20b6: ja     2014 <generic_rawtp_process_filter+0x2014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2014;
	}
x86_l_20bc:
	/* 0x20bc: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20be:
	/* 0x20be: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20c1:
	/* 0x20c1: test   QWORD PTR [r14+rsi*8+0x48],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 3), 72ULL);
x86_l_20c6:
	/* 0x20c6: sete   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_E);
x86_l_20ca:
	/* 0x20ca: setne  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_NE);
x86_l_20ce:
	/* 0x20ce: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_20d1:
	/* 0x20d1: cmove  r8d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDI, X86_WIDTH_32, X86_CC_E);
x86_l_20d5:
	/* 0x20d5: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_20d8:
	/* 0x20d8: je     1ff1 <generic_rawtp_process_filter+0x1ff1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ff1;
	}
x86_l_20de:
	/* 0x20de: jmp    2014 <generic_rawtp_process_filter+0x2014> */
	goto x86_l_2014;
x86_l_20e3:
	/* 0x20e3: mov    edi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R8, X86_WIDTH_32);
x86_l_20e6:
	/* 0x20e6: mov    r11d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDX, X86_WIDTH_32);
x86_l_20e9:
	/* 0x20e9: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20eb:
	/* 0x20eb: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_20f1:
	/* 0x20f1: cmp    r11d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 1000ULL);
x86_l_20f8:
	/* 0x20f8: jbe    1f32 <generic_rawtp_process_filter+0x1f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1f32;
	}
x86_l_20fe:
	/* 0x20fe: jmp    1f3d <generic_rawtp_process_filter+0x1f3d> */
	goto x86_l_1f3d;
x86_l_2103:
	/* 0x2103: mov    ebp,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_32);
x86_l_2106:
	/* 0x2106: mov    edi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R8, X86_WIDTH_32);
x86_l_2109:
	/* 0x2109: mov    r11d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDX, X86_WIDTH_32);
x86_l_210c:
	/* 0x210c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_210f:
	/* 0x210f: mov    r13d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 0ULL);
x86_l_2115:
	/* 0x2115: cmp    r11d,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 1000ULL);
x86_l_211c:
	/* 0x211c: jbe    1f83 <generic_rawtp_process_filter+0x1f83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1f83;
	}
x86_l_2122:
	/* 0x2122: jmp    1f8b <generic_rawtp_process_filter+0x1f8b> */
	goto x86_l_1f8b;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_rawtp_generic_rawtp_process_filter_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 8368U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1645ULL)
			__x86_pc = tetragon_bpf_generic_rawtp_generic_rawtp_process_filter_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1647ULL && __x86_pc <= 3280ULL)
			__x86_pc = tetragon_bpf_generic_rawtp_generic_rawtp_process_filter_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3285ULL && __x86_pc <= 4887ULL)
			__x86_pc = tetragon_bpf_generic_rawtp_generic_rawtp_process_filter_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4890ULL && __x86_pc <= 6434ULL)
			__x86_pc = tetragon_bpf_generic_rawtp_generic_rawtp_process_filter_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6438ULL && __x86_pc <= 7824ULL)
			__x86_pc = tetragon_bpf_generic_rawtp_generic_rawtp_process_filter_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 7827ULL && __x86_pc <= 8482ULL)
			__x86_pc = tetragon_bpf_generic_rawtp_generic_rawtp_process_filter_x86_chunk_5(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

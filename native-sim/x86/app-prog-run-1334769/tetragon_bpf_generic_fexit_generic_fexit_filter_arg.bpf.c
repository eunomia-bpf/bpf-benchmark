extern char addr4lpm_maps;
extern char addr6lpm_maps;
extern char argfilter_maps;
extern char fexit_calls;
extern char filter_map;
extern char heap_ro_zero;
extern char process_call_heap;
extern char retprobe_map;
extern char string_maps_0;
extern char string_maps_1;
extern char string_maps_2;
extern char string_maps_3;
extern char string_maps_4;
extern char string_maps_5;
extern char string_maps_heap;
extern char string_postfix_maps;
extern char string_postfix_maps_heap;
extern char string_prefix_maps;
extern char string_prefix_maps_heap;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 24ULL: goto x86_l_18;
	case 29ULL: goto x86_l_1d;
	case 36ULL: goto x86_l_24;
	case 44ULL: goto x86_l_2c;
	case 46ULL: goto x86_l_2e;
	case 49ULL: goto x86_l_31;
	case 55ULL: goto x86_l_37;
	case 58ULL: goto x86_l_3a;
	case 65ULL: goto x86_l_41;
	case 72ULL: goto x86_l_48;
	case 77ULL: goto x86_l_4d;
	case 84ULL: goto x86_l_54;
	case 86ULL: goto x86_l_56;
	case 89ULL: goto x86_l_59;
	case 95ULL: goto x86_l_5f;
	case 103ULL: goto x86_l_67;
	case 109ULL: goto x86_l_6d;
	case 112ULL: goto x86_l_70;
	case 115ULL: goto x86_l_73;
	case 124ULL: goto x86_l_7c;
	case 130ULL: goto x86_l_82;
	case 132ULL: goto x86_l_84;
	case 136ULL: goto x86_l_88;
	case 140ULL: goto x86_l_8c;
	case 144ULL: goto x86_l_90;
	case 146ULL: goto x86_l_92;
	case 152ULL: goto x86_l_98;
	case 156ULL: goto x86_l_9c;
	case 162ULL: goto x86_l_a2;
	case 166ULL: goto x86_l_a6;
	case 172ULL: goto x86_l_ac;
	case 178ULL: goto x86_l_b2;
	case 180ULL: goto x86_l_b4;
	case 186ULL: goto x86_l_ba;
	case 189ULL: goto x86_l_bd;
	case 193ULL: goto x86_l_c1;
	case 199ULL: goto x86_l_c7;
	case 208ULL: goto x86_l_d0;
	case 214ULL: goto x86_l_d6;
	case 217ULL: goto x86_l_d9;
	case 220ULL: goto x86_l_dc;
	case 224ULL: goto x86_l_e0;
	case 232ULL: goto x86_l_e8;
	case 238ULL: goto x86_l_ee;
	case 242ULL: goto x86_l_f2;
	case 249ULL: goto x86_l_f9;
	case 252ULL: goto x86_l_fc;
	case 254ULL: goto x86_l_fe;
	case 257ULL: goto x86_l_101;
	case 259ULL: goto x86_l_103;
	case 262ULL: goto x86_l_106;
	case 268ULL: goto x86_l_10c;
	case 271ULL: goto x86_l_10f;
	case 277ULL: goto x86_l_115;
	case 280ULL: goto x86_l_118;
	case 282ULL: goto x86_l_11a;
	case 285ULL: goto x86_l_11d;
	case 291ULL: goto x86_l_123;
	case 296ULL: goto x86_l_128;
	case 299ULL: goto x86_l_12b;
	case 301ULL: goto x86_l_12d;
	case 304ULL: goto x86_l_130;
	case 307ULL: goto x86_l_133;
	case 313ULL: goto x86_l_139;
	case 316ULL: goto x86_l_13c;
	case 322ULL: goto x86_l_142;
	case 325ULL: goto x86_l_145;
	case 331ULL: goto x86_l_14b;
	case 336ULL: goto x86_l_150;
	case 339ULL: goto x86_l_153;
	case 342ULL: goto x86_l_156;
	case 348ULL: goto x86_l_15c;
	case 351ULL: goto x86_l_15f;
	case 354ULL: goto x86_l_162;
	case 360ULL: goto x86_l_168;
	case 363ULL: goto x86_l_16b;
	case 365ULL: goto x86_l_16d;
	case 370ULL: goto x86_l_172;
	case 373ULL: goto x86_l_175;
	case 376ULL: goto x86_l_178;
	case 378ULL: goto x86_l_17a;
	case 381ULL: goto x86_l_17d;
	case 384ULL: goto x86_l_180;
	case 390ULL: goto x86_l_186;
	case 399ULL: goto x86_l_18f;
	case 408ULL: goto x86_l_198;
	case 417ULL: goto x86_l_1a1;
	case 426ULL: goto x86_l_1aa;
	case 435ULL: goto x86_l_1b3;
	case 438ULL: goto x86_l_1b6;
	case 441ULL: goto x86_l_1b9;
	case 447ULL: goto x86_l_1bf;
	case 450ULL: goto x86_l_1c2;
	case 456ULL: goto x86_l_1c8;
	case 459ULL: goto x86_l_1cb;
	case 462ULL: goto x86_l_1ce;
	case 468ULL: goto x86_l_1d4;
	case 473ULL: goto x86_l_1d9;
	case 477ULL: goto x86_l_1dd;
	case 480ULL: goto x86_l_1e0;
	case 483ULL: goto x86_l_1e3;
	case 489ULL: goto x86_l_1e9;
	case 491ULL: goto x86_l_1eb;
	case 495ULL: goto x86_l_1ef;
	case 500ULL: goto x86_l_1f4;
	case 503ULL: goto x86_l_1f7;
	case 507ULL: goto x86_l_1fb;
	case 512ULL: goto x86_l_200;
	case 518ULL: goto x86_l_206;
	case 523ULL: goto x86_l_20b;
	case 526ULL: goto x86_l_20e;
	case 531ULL: goto x86_l_213;
	case 537ULL: goto x86_l_219;
	case 542ULL: goto x86_l_21e;
	case 545ULL: goto x86_l_221;
	case 551ULL: goto x86_l_227;
	case 555ULL: goto x86_l_22b;
	case 559ULL: goto x86_l_22f;
	case 567ULL: goto x86_l_237;
	case 572ULL: goto x86_l_23c;
	case 579ULL: goto x86_l_243;
	case 584ULL: goto x86_l_248;
	case 586ULL: goto x86_l_24a;
	case 589ULL: goto x86_l_24d;
	case 594ULL: goto x86_l_252;
	case 600ULL: goto x86_l_258;
	case 603ULL: goto x86_l_25b;
	case 606ULL: goto x86_l_25e;
	case 612ULL: goto x86_l_264;
	case 617ULL: goto x86_l_269;
	case 624ULL: goto x86_l_270;
	case 629ULL: goto x86_l_275;
	case 631ULL: goto x86_l_277;
	case 634ULL: goto x86_l_27a;
	case 640ULL: goto x86_l_280;
	case 644ULL: goto x86_l_284;
	case 647ULL: goto x86_l_287;
	case 652ULL: goto x86_l_28c;
	case 655ULL: goto x86_l_28f;
	case 658ULL: goto x86_l_292;
	case 660ULL: goto x86_l_294;
	case 663ULL: goto x86_l_297;
	case 669ULL: goto x86_l_29d;
	case 674ULL: goto x86_l_2a2;
	case 678ULL: goto x86_l_2a6;
	case 681ULL: goto x86_l_2a9;
	case 685ULL: goto x86_l_2ad;
	case 691ULL: goto x86_l_2b3;
	case 697ULL: goto x86_l_2b9;
	case 703ULL: goto x86_l_2bf;
	case 707ULL: goto x86_l_2c3;
	case 710ULL: goto x86_l_2c6;
	case 714ULL: goto x86_l_2ca;
	case 720ULL: goto x86_l_2d0;
	case 726ULL: goto x86_l_2d6;
	case 732ULL: goto x86_l_2dc;
	case 736ULL: goto x86_l_2e0;
	case 739ULL: goto x86_l_2e3;
	case 743ULL: goto x86_l_2e7;
	case 749ULL: goto x86_l_2ed;
	case 755ULL: goto x86_l_2f3;
	case 761ULL: goto x86_l_2f9;
	case 765ULL: goto x86_l_2fd;
	case 768ULL: goto x86_l_300;
	case 772ULL: goto x86_l_304;
	case 778ULL: goto x86_l_30a;
	case 784ULL: goto x86_l_310;
	case 790ULL: goto x86_l_316;
	case 794ULL: goto x86_l_31a;
	case 797ULL: goto x86_l_31d;
	case 801ULL: goto x86_l_321;
	case 807ULL: goto x86_l_327;
	case 813ULL: goto x86_l_32d;
	case 819ULL: goto x86_l_333;
	case 823ULL: goto x86_l_337;
	case 826ULL: goto x86_l_33a;
	case 830ULL: goto x86_l_33e;
	case 836ULL: goto x86_l_344;
	case 842ULL: goto x86_l_34a;
	case 848ULL: goto x86_l_350;
	case 852ULL: goto x86_l_354;
	case 855ULL: goto x86_l_357;
	case 859ULL: goto x86_l_35b;
	case 865ULL: goto x86_l_361;
	case 871ULL: goto x86_l_367;
	case 877ULL: goto x86_l_36d;
	case 881ULL: goto x86_l_371;
	case 884ULL: goto x86_l_374;
	case 888ULL: goto x86_l_378;
	case 894ULL: goto x86_l_37e;
	case 900ULL: goto x86_l_384;
	case 906ULL: goto x86_l_38a;
	case 910ULL: goto x86_l_38e;
	case 913ULL: goto x86_l_391;
	case 917ULL: goto x86_l_395;
	case 923ULL: goto x86_l_39b;
	case 929ULL: goto x86_l_3a1;
	case 935ULL: goto x86_l_3a7;
	case 939ULL: goto x86_l_3ab;
	case 942ULL: goto x86_l_3ae;
	case 946ULL: goto x86_l_3b2;
	case 952ULL: goto x86_l_3b8;
	case 958ULL: goto x86_l_3be;
	case 964ULL: goto x86_l_3c4;
	case 968ULL: goto x86_l_3c8;
	case 971ULL: goto x86_l_3cb;
	case 975ULL: goto x86_l_3cf;
	case 981ULL: goto x86_l_3d5;
	case 987ULL: goto x86_l_3db;
	case 993ULL: goto x86_l_3e1;
	case 997ULL: goto x86_l_3e5;
	case 1000ULL: goto x86_l_3e8;
	case 1004ULL: goto x86_l_3ec;
	case 1010ULL: goto x86_l_3f2;
	case 1016ULL: goto x86_l_3f8;
	case 1022ULL: goto x86_l_3fe;
	case 1026ULL: goto x86_l_402;
	case 1029ULL: goto x86_l_405;
	case 1033ULL: goto x86_l_409;
	case 1039ULL: goto x86_l_40f;
	case 1045ULL: goto x86_l_415;
	case 1051ULL: goto x86_l_41b;
	case 1055ULL: goto x86_l_41f;
	case 1058ULL: goto x86_l_422;
	case 1062ULL: goto x86_l_426;
	case 1068ULL: goto x86_l_42c;
	case 1074ULL: goto x86_l_432;
	case 1080ULL: goto x86_l_438;
	case 1084ULL: goto x86_l_43c;
	case 1087ULL: goto x86_l_43f;
	case 1091ULL: goto x86_l_443;
	case 1097ULL: goto x86_l_449;
	case 1103ULL: goto x86_l_44f;
	case 1109ULL: goto x86_l_455;
	case 1113ULL: goto x86_l_459;
	case 1116ULL: goto x86_l_45c;
	case 1120ULL: goto x86_l_460;
	case 1126ULL: goto x86_l_466;
	case 1132ULL: goto x86_l_46c;
	case 1138ULL: goto x86_l_472;
	case 1142ULL: goto x86_l_476;
	case 1145ULL: goto x86_l_479;
	case 1149ULL: goto x86_l_47d;
	case 1155ULL: goto x86_l_483;
	case 1161ULL: goto x86_l_489;
	case 1167ULL: goto x86_l_48f;
	case 1171ULL: goto x86_l_493;
	case 1174ULL: goto x86_l_496;
	case 1178ULL: goto x86_l_49a;
	case 1184ULL: goto x86_l_4a0;
	case 1190ULL: goto x86_l_4a6;
	case 1196ULL: goto x86_l_4ac;
	case 1200ULL: goto x86_l_4b0;
	case 1203ULL: goto x86_l_4b3;
	case 1207ULL: goto x86_l_4b7;
	case 1213ULL: goto x86_l_4bd;
	case 1219ULL: goto x86_l_4c3;
	case 1225ULL: goto x86_l_4c9;
	case 1229ULL: goto x86_l_4cd;
	case 1232ULL: goto x86_l_4d0;
	case 1236ULL: goto x86_l_4d4;
	case 1242ULL: goto x86_l_4da;
	case 1248ULL: goto x86_l_4e0;
	case 1254ULL: goto x86_l_4e6;
	case 1258ULL: goto x86_l_4ea;
	case 1261ULL: goto x86_l_4ed;
	case 1265ULL: goto x86_l_4f1;
	case 1271ULL: goto x86_l_4f7;
	case 1277ULL: goto x86_l_4fd;
	case 1283ULL: goto x86_l_503;
	case 1287ULL: goto x86_l_507;
	case 1290ULL: goto x86_l_50a;
	case 1294ULL: goto x86_l_50e;
	case 1300ULL: goto x86_l_514;
	case 1306ULL: goto x86_l_51a;
	case 1312ULL: goto x86_l_520;
	case 1316ULL: goto x86_l_524;
	case 1319ULL: goto x86_l_527;
	case 1323ULL: goto x86_l_52b;
	case 1329ULL: goto x86_l_531;
	case 1335ULL: goto x86_l_537;
	case 1341ULL: goto x86_l_53d;
	case 1345ULL: goto x86_l_541;
	case 1348ULL: goto x86_l_544;
	case 1352ULL: goto x86_l_548;
	case 1358ULL: goto x86_l_54e;
	case 1364ULL: goto x86_l_554;
	case 1370ULL: goto x86_l_55a;
	case 1374ULL: goto x86_l_55e;
	case 1377ULL: goto x86_l_561;
	case 1381ULL: goto x86_l_565;
	case 1387ULL: goto x86_l_56b;
	case 1393ULL: goto x86_l_571;
	case 1399ULL: goto x86_l_577;
	case 1403ULL: goto x86_l_57b;
	case 1406ULL: goto x86_l_57e;
	case 1410ULL: goto x86_l_582;
	case 1416ULL: goto x86_l_588;
	case 1422ULL: goto x86_l_58e;
	case 1428ULL: goto x86_l_594;
	case 1432ULL: goto x86_l_598;
	case 1435ULL: goto x86_l_59b;
	case 1439ULL: goto x86_l_59f;
	case 1445ULL: goto x86_l_5a5;
	case 1451ULL: goto x86_l_5ab;
	case 1457ULL: goto x86_l_5b1;
	case 1461ULL: goto x86_l_5b5;
	case 1464ULL: goto x86_l_5b8;
	case 1468ULL: goto x86_l_5bc;
	case 1474ULL: goto x86_l_5c2;
	case 1480ULL: goto x86_l_5c8;
	case 1486ULL: goto x86_l_5ce;
	case 1490ULL: goto x86_l_5d2;
	case 1493ULL: goto x86_l_5d5;
	case 1497ULL: goto x86_l_5d9;
	case 1503ULL: goto x86_l_5df;
	case 1509ULL: goto x86_l_5e5;
	case 1515ULL: goto x86_l_5eb;
	case 1519ULL: goto x86_l_5ef;
	case 1522ULL: goto x86_l_5f2;
	case 1526ULL: goto x86_l_5f6;
	case 1532ULL: goto x86_l_5fc;
	case 1538ULL: goto x86_l_602;
	case 1544ULL: goto x86_l_608;
	case 1548ULL: goto x86_l_60c;
	case 1551ULL: goto x86_l_60f;
	case 1555ULL: goto x86_l_613;
	case 1561ULL: goto x86_l_619;
	case 1567ULL: goto x86_l_61f;
	case 1573ULL: goto x86_l_625;
	case 1577ULL: goto x86_l_629;
	case 1580ULL: goto x86_l_62c;
	case 1584ULL: goto x86_l_630;
	case 1590ULL: goto x86_l_636;
	case 1596ULL: goto x86_l_63c;
	case 1602ULL: goto x86_l_642;
	case 1606ULL: goto x86_l_646;
	case 1609ULL: goto x86_l_649;
	case 1613ULL: goto x86_l_64d;
	case 1619ULL: goto x86_l_653;
	case 1625ULL: goto x86_l_659;
	case 1631ULL: goto x86_l_65f;
	case 1635ULL: goto x86_l_663;
	case 1638ULL: goto x86_l_666;
	case 1642ULL: goto x86_l_66a;
	case 1648ULL: goto x86_l_670;
	case 1654ULL: goto x86_l_676;
	case 1660ULL: goto x86_l_67c;
	case 1664ULL: goto x86_l_680;
	case 1667ULL: goto x86_l_683;
	case 1671ULL: goto x86_l_687;
	case 1677ULL: goto x86_l_68d;
	case 1683ULL: goto x86_l_693;
	case 1689ULL: goto x86_l_699;
	case 1693ULL: goto x86_l_69d;
	case 1696ULL: goto x86_l_6a0;
	case 1700ULL: goto x86_l_6a4;
	case 1706ULL: goto x86_l_6aa;
	case 1712ULL: goto x86_l_6b0;
	case 1718ULL: goto x86_l_6b6;
	case 1722ULL: goto x86_l_6ba;
	case 1725ULL: goto x86_l_6bd;
	case 1729ULL: goto x86_l_6c1;
	case 1735ULL: goto x86_l_6c7;
	case 1741ULL: goto x86_l_6cd;
	case 1747ULL: goto x86_l_6d3;
	case 1751ULL: goto x86_l_6d7;
	case 1754ULL: goto x86_l_6da;
	case 1758ULL: goto x86_l_6de;
	case 1764ULL: goto x86_l_6e4;
	case 1770ULL: goto x86_l_6ea;
	case 1776ULL: goto x86_l_6f0;
	case 1780ULL: goto x86_l_6f4;
	case 1783ULL: goto x86_l_6f7;
	case 1787ULL: goto x86_l_6fb;
	case 1793ULL: goto x86_l_701;
	case 1799ULL: goto x86_l_707;
	case 1805ULL: goto x86_l_70d;
	case 1809ULL: goto x86_l_711;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 136ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0x84],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_18:
	/* 0x18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_24:
	/* 0x24: lea    rsi,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: je     387c <generic_fexit_filter_arg+0x387c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14460ULL;
	}
x86_l_37:
	/* 0x37: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    r12d,DWORD PTR [rax+0x5ef0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_41:
	/* 0x41: lea    rsi,[rax+0x5ee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24296ULL);
x86_l_48:
	/* 0x48: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4d:
	/* 0x4d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_54:
	/* 0x54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56:
	/* 0x56: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_59:
	/* 0x59: je     3866 <generic_fexit_filter_arg+0x3866> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14438ULL;
	}
x86_l_5f:
	/* 0x5f: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_67:
	/* 0x67: je     3866 <generic_fexit_filter_arg+0x3866> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14438ULL;
	}
x86_l_6d:
	/* 0x6d: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_70:
	/* 0x70: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_73:
	/* 0x73: cmp    BYTE PTR [r14+rcx*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 104183021699072ULL);
x86_l_7c:
	/* 0x7c: je     37f4 <generic_fexit_filter_arg+0x37f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14324ULL;
	}
x86_l_82:
	/* 0x82: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_84:
	/* 0x84: mov    edx,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_88:
	/* 0x88: lea    rcx,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_8c:
	/* 0x8c: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_90:
	/* 0x90: mov    ebp,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_32);
x86_l_92:
	/* 0x92: and    ebp,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_98:
	/* 0x98: cmp    DWORD PTR [rax+rbp*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 25ULL);
x86_l_9c:
	/* 0x9c: jb     37ea <generic_fexit_filter_arg+0x37ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 14314ULL;
	}
x86_l_a2:
	/* 0xa2: mov    edx,DWORD PTR [rax+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 4ULL);
x86_l_a6:
	/* 0xa6: test   edx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 1023ULL);
x86_l_ac:
	/* 0xac: je     37ea <generic_fexit_filter_arg+0x37ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14314ULL;
	}
x86_l_b2:
	/* 0xb2: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b4:
	/* 0xb4: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_ba:
	/* 0xba: mov    edx,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_bd:
	/* 0xbd: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_c1:
	/* 0xc1: ja     37f4 <generic_fexit_filter_arg+0x37f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14324ULL;
	}
x86_l_c7:
	/* 0xc7: cmp    DWORD PTR [r14+rdx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104041287778304ULL);
x86_l_d0:
	/* 0xd0: jne    37f4 <generic_fexit_filter_arg+0x37f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14324ULL;
	}
x86_l_d6:
	/* 0xd6: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_d9:
	/* 0xd9: add    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_dc:
	/* 0xdc: mov    eax,DWORD PTR [rax+rcx*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 12ULL);
x86_l_e0:
	/* 0xe0: mov    rcx,QWORD PTR [r14+rdx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_e8:
	/* 0xe8: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_ee:
	/* 0xee: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_f2:
	/* 0xf2: add    rdi,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_f9:
	/* 0xf9: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_fc:
	/* 0xfc: jg     128 <generic_fexit_filter_arg+0x128> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_128;
	}
x86_l_fe:
	/* 0xfe: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_101:
	/* 0x101: jg     150 <generic_fexit_filter_arg+0x150> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_150;
	}
x86_l_103:
	/* 0x103: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_106:
	/* 0x106: jle    d2e <generic_fexit_filter_arg+0xd2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3374ULL;
	}
x86_l_10c:
	/* 0x10c: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10f:
	/* 0x10f: je     1be3 <generic_fexit_filter_arg+0x1be3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7139ULL;
	}
x86_l_115:
	/* 0x115: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_118:
	/* 0x118: je     186 <generic_fexit_filter_arg+0x186> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_186;
	}
x86_l_11a:
	/* 0x11a: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_11d:
	/* 0x11d: je     1d9 <generic_fexit_filter_arg+0x1d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d9;
	}
x86_l_123:
	/* 0x123: jmp    37ea <generic_fexit_filter_arg+0x37ea> */
	return 14314ULL;
x86_l_128:
	/* 0x128: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_12b:
	/* 0x12b: jg     172 <generic_fexit_filter_arg+0x172> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_172;
	}
x86_l_12d:
	/* 0x12d: lea    ecx,[rax-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_130:
	/* 0x130: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_133:
	/* 0x133: jb     1be3 <generic_fexit_filter_arg+0x1be3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7139ULL;
	}
x86_l_139:
	/* 0x139: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_13c:
	/* 0x13c: je     1dc5 <generic_fexit_filter_arg+0x1dc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7621ULL;
	}
x86_l_142:
	/* 0x142: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_145:
	/* 0x145: je     1be3 <generic_fexit_filter_arg+0x1be3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7139ULL;
	}
x86_l_14b:
	/* 0x14b: jmp    37ea <generic_fexit_filter_arg+0x37ea> */
	return 14314ULL;
x86_l_150:
	/* 0x150: lea    ecx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_153:
	/* 0x153: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_156:
	/* 0x156: jb     1be3 <generic_fexit_filter_arg+0x1be3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7139ULL;
	}
x86_l_15c:
	/* 0x15c: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_15f:
	/* 0x15f: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_162:
	/* 0x162: jb     1dc9 <generic_fexit_filter_arg+0x1dc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7625ULL;
	}
x86_l_168:
	/* 0x168: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_16b:
	/* 0x16b: je     186 <generic_fexit_filter_arg+0x186> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_186;
	}
x86_l_16d:
	/* 0x16d: jmp    37ea <generic_fexit_filter_arg+0x37ea> */
	return 14314ULL;
x86_l_172:
	/* 0x172: lea    ecx,[rax-0x26] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_175:
	/* 0x175: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_178:
	/* 0x178: jb     1d9 <generic_fexit_filter_arg+0x1d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d9;
	}
x86_l_17a:
	/* 0x17a: lea    ecx,[rax-0x28] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551576ULL);
x86_l_17d:
	/* 0x17d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_180:
	/* 0x180: jae    1d36 <generic_fexit_filter_arg+0x1d36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7478ULL;
	}
x86_l_186:
	/* 0x186: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_18f:
	/* 0x18f: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_198:
	/* 0x198: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1a1:
	/* 0x1a1: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1aa:
	/* 0x1aa: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1b3:
	/* 0x1b3: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b6:
	/* 0x1b6: cmp    eax,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 39ULL);
x86_l_1b9:
	/* 0x1b9: jg     1c7e <generic_fexit_filter_arg+0x1c7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7294ULL;
	}
x86_l_1bf:
	/* 0x1bf: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_1c2:
	/* 0x1c2: je     1f40 <generic_fexit_filter_arg+0x1f40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8000ULL;
	}
x86_l_1c8:
	/* 0x1c8: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1cb:
	/* 0x1cb: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1ce:
	/* 0x1ce: je     1f42 <generic_fexit_filter_arg+0x1f42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8002ULL;
	}
x86_l_1d4:
	/* 0x1d4: jmp    37e5 <generic_fexit_filter_arg+0x37e5> */
	return 14309ULL;
x86_l_1d9:
	/* 0x1d9: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1dd:
	/* 0x1dd: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e0:
	/* 0x1e0: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1e3:
	/* 0x1e3: ja     37ca <generic_fexit_filter_arg+0x37ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14282ULL;
	}
x86_l_1e9:
	/* 0x1e9: mov    edx,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eb:
	/* 0x1eb: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1ef:
	/* 0x1ef: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_1f4:
	/* 0x1f4: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1f7:
	/* 0x1f7: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fb:
	/* 0x1fb: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_200:
	/* 0x200: jb     1ed8 <generic_fexit_filter_arg+0x1ed8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7896ULL;
	}
x86_l_206:
	/* 0x206: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_20b:
	/* 0x20b: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_20e:
	/* 0x20e: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_213:
	/* 0x213: jb     1e3c <generic_fexit_filter_arg+0x1e3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7740ULL;
	}
x86_l_219:
	/* 0x219: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_21e:
	/* 0x21e: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_221:
	/* 0x221: jae    37ca <generic_fexit_filter_arg+0x37ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14282ULL;
	}
x86_l_227:
	/* 0x227: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22b:
	/* 0x22b: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_22f:
	/* 0x22f: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_237:
	/* 0x237: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23c:
	/* 0x23c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_243:
	/* 0x243: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_248:
	/* 0x248: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a:
	/* 0x24a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24d:
	/* 0x24d: cmp    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_252:
	/* 0x252: je     36c7 <generic_fexit_filter_arg+0x36c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14023ULL;
	}
x86_l_258:
	/* 0x258: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_25b:
	/* 0x25b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25e:
	/* 0x25e: je     36c7 <generic_fexit_filter_arg+0x36c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14023ULL;
	}
x86_l_264:
	/* 0x264: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_269:
	/* 0x269: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_270:
	/* 0x270: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_275:
	/* 0x275: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_277:
	/* 0x277: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27a:
	/* 0x27a: je     36c4 <generic_fexit_filter_arg+0x36c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14020ULL;
	}
x86_l_280:
	/* 0x280: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_284:
	/* 0x284: cmp    esi,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 94ULL);
x86_l_287:
	/* 0x287: mov    ecx,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 94ULL);
x86_l_28c:
	/* 0x28c: cmovb  ecx,esi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RSI, X86_WIDTH_32, X86_CC_B);
x86_l_28f:
	/* 0x28f: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_292:
	/* 0x292: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_294:
	/* 0x294: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_297:
	/* 0x297: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29d:
	/* 0x29d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a2:
	/* 0x2a2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a6:
	/* 0x2a6: mov    BYTE PTR [rax+0x4],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2a9:
	/* 0x2a9: cmp    rsi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1ULL);
x86_l_2ad:
	/* 0x2ad: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_2b3:
	/* 0x2b3: lea    ecx,[rsi+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_2b9:
	/* 0x2b9: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2bf:
	/* 0x2bf: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2c3:
	/* 0x2c3: mov    BYTE PTR [rax+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2c6:
	/* 0x2c6: cmp    rsi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 2ULL);
x86_l_2ca:
	/* 0x2ca: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_2d0:
	/* 0x2d0: lea    ecx,[rsi+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_2d6:
	/* 0x2d6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2dc:
	/* 0x2dc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2e0:
	/* 0x2e0: mov    BYTE PTR [rax+0x6],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_2e3:
	/* 0x2e3: cmp    rsi,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 3ULL);
x86_l_2e7:
	/* 0x2e7: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_2ed:
	/* 0x2ed: lea    ecx,[rsi+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_2f3:
	/* 0x2f3: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2f9:
	/* 0x2f9: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2fd:
	/* 0x2fd: mov    BYTE PTR [rax+0x7],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_300:
	/* 0x300: cmp    rsi,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 4ULL);
x86_l_304:
	/* 0x304: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_30a:
	/* 0x30a: lea    ecx,[rsi+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_310:
	/* 0x310: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_316:
	/* 0x316: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_31a:
	/* 0x31a: mov    BYTE PTR [rax+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31d:
	/* 0x31d: cmp    rsi,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 5ULL);
x86_l_321:
	/* 0x321: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_327:
	/* 0x327: lea    ecx,[rsi+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_32d:
	/* 0x32d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_333:
	/* 0x333: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_337:
	/* 0x337: mov    BYTE PTR [rax+0x9],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_33a:
	/* 0x33a: cmp    rsi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 6ULL);
x86_l_33e:
	/* 0x33e: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_344:
	/* 0x344: lea    ecx,[rsi+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_34a:
	/* 0x34a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_350:
	/* 0x350: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_354:
	/* 0x354: mov    BYTE PTR [rax+0xa],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_357:
	/* 0x357: cmp    rsi,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 7ULL);
x86_l_35b:
	/* 0x35b: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_361:
	/* 0x361: lea    ecx,[rsi+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_367:
	/* 0x367: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_36d:
	/* 0x36d: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_371:
	/* 0x371: mov    BYTE PTR [rax+0xb],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_374:
	/* 0x374: cmp    rsi,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 8ULL);
x86_l_378:
	/* 0x378: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_37e:
	/* 0x37e: lea    ecx,[rsi+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_384:
	/* 0x384: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_38a:
	/* 0x38a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_38e:
	/* 0x38e: mov    BYTE PTR [rax+0xc],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_391:
	/* 0x391: cmp    rsi,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 9ULL);
x86_l_395:
	/* 0x395: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_39b:
	/* 0x39b: lea    ecx,[rsi+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_3a1:
	/* 0x3a1: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3a7:
	/* 0x3a7: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_3ab:
	/* 0x3ab: mov    BYTE PTR [rax+0xd],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_3ae:
	/* 0x3ae: cmp    rsi,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 10ULL);
x86_l_3b2:
	/* 0x3b2: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_3b8:
	/* 0x3b8: lea    ecx,[rsi+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_3be:
	/* 0x3be: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3c4:
	/* 0x3c4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_3c8:
	/* 0x3c8: mov    BYTE PTR [rax+0xe],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_3cb:
	/* 0x3cb: cmp    rsi,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 11ULL);
x86_l_3cf:
	/* 0x3cf: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_3d5:
	/* 0x3d5: lea    ecx,[rsi+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_3db:
	/* 0x3db: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3e1:
	/* 0x3e1: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_3e5:
	/* 0x3e5: mov    BYTE PTR [rax+0xf],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_3e8:
	/* 0x3e8: cmp    rsi,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 12ULL);
x86_l_3ec:
	/* 0x3ec: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_3f2:
	/* 0x3f2: lea    ecx,[rsi+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_3f8:
	/* 0x3f8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3fe:
	/* 0x3fe: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_402:
	/* 0x402: mov    BYTE PTR [rax+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_405:
	/* 0x405: cmp    rsi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 13ULL);
x86_l_409:
	/* 0x409: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_40f:
	/* 0x40f: lea    ecx,[rsi+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_415:
	/* 0x415: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_41b:
	/* 0x41b: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_41f:
	/* 0x41f: mov    BYTE PTR [rax+0x11],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_422:
	/* 0x422: cmp    rsi,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 14ULL);
x86_l_426:
	/* 0x426: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_42c:
	/* 0x42c: lea    ecx,[rsi+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_432:
	/* 0x432: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_438:
	/* 0x438: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_43c:
	/* 0x43c: mov    BYTE PTR [rax+0x12],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_43f:
	/* 0x43f: cmp    rsi,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 15ULL);
x86_l_443:
	/* 0x443: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_449:
	/* 0x449: lea    ecx,[rsi+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_44f:
	/* 0x44f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_455:
	/* 0x455: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_459:
	/* 0x459: mov    BYTE PTR [rax+0x13],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_45c:
	/* 0x45c: cmp    rsi,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 16ULL);
x86_l_460:
	/* 0x460: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_466:
	/* 0x466: lea    ecx,[rsi+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_46c:
	/* 0x46c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_472:
	/* 0x472: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_476:
	/* 0x476: mov    BYTE PTR [rax+0x14],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_479:
	/* 0x479: cmp    rsi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 17ULL);
x86_l_47d:
	/* 0x47d: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_483:
	/* 0x483: lea    ecx,[rsi+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_489:
	/* 0x489: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_48f:
	/* 0x48f: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_493:
	/* 0x493: mov    BYTE PTR [rax+0x15],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_496:
	/* 0x496: cmp    rsi,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18ULL);
x86_l_49a:
	/* 0x49a: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_4a0:
	/* 0x4a0: lea    ecx,[rsi+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_4a6:
	/* 0x4a6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4ac:
	/* 0x4ac: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_4b0:
	/* 0x4b0: mov    BYTE PTR [rax+0x16],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_4b3:
	/* 0x4b3: cmp    rsi,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 19ULL);
x86_l_4b7:
	/* 0x4b7: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_4bd:
	/* 0x4bd: lea    ecx,[rsi+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_4c3:
	/* 0x4c3: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4c9:
	/* 0x4c9: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_4cd:
	/* 0x4cd: mov    BYTE PTR [rax+0x17],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_4d0:
	/* 0x4d0: cmp    rsi,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 20ULL);
x86_l_4d4:
	/* 0x4d4: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_4da:
	/* 0x4da: lea    ecx,[rsi+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_4e0:
	/* 0x4e0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4e6:
	/* 0x4e6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_4ea:
	/* 0x4ea: mov    BYTE PTR [rax+0x18],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ed:
	/* 0x4ed: cmp    rsi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 21ULL);
x86_l_4f1:
	/* 0x4f1: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_4f7:
	/* 0x4f7: lea    ecx,[rsi+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_4fd:
	/* 0x4fd: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_503:
	/* 0x503: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_507:
	/* 0x507: mov    BYTE PTR [rax+0x19],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_50a:
	/* 0x50a: cmp    rsi,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 22ULL);
x86_l_50e:
	/* 0x50e: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_514:
	/* 0x514: lea    ecx,[rsi+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_51a:
	/* 0x51a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_520:
	/* 0x520: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_524:
	/* 0x524: mov    BYTE PTR [rax+0x1a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_527:
	/* 0x527: cmp    rsi,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 23ULL);
x86_l_52b:
	/* 0x52b: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_531:
	/* 0x531: lea    ecx,[rsi+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_537:
	/* 0x537: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_53d:
	/* 0x53d: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_541:
	/* 0x541: mov    BYTE PTR [rax+0x1b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_544:
	/* 0x544: cmp    rsi,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 24ULL);
x86_l_548:
	/* 0x548: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_54e:
	/* 0x54e: lea    ecx,[rsi+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_554:
	/* 0x554: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_55a:
	/* 0x55a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_55e:
	/* 0x55e: mov    BYTE PTR [rax+0x1c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_561:
	/* 0x561: cmp    rsi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 25ULL);
x86_l_565:
	/* 0x565: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_56b:
	/* 0x56b: lea    ecx,[rsi+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_571:
	/* 0x571: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_577:
	/* 0x577: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_57b:
	/* 0x57b: mov    BYTE PTR [rax+0x1d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_57e:
	/* 0x57e: cmp    rsi,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 26ULL);
x86_l_582:
	/* 0x582: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_588:
	/* 0x588: lea    ecx,[rsi+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_58e:
	/* 0x58e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_594:
	/* 0x594: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_598:
	/* 0x598: mov    BYTE PTR [rax+0x1e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_59b:
	/* 0x59b: cmp    rsi,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 27ULL);
x86_l_59f:
	/* 0x59f: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_5a5:
	/* 0x5a5: lea    ecx,[rsi+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_5ab:
	/* 0x5ab: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5b1:
	/* 0x5b1: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_5b5:
	/* 0x5b5: mov    BYTE PTR [rax+0x1f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_5b8:
	/* 0x5b8: cmp    rsi,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 28ULL);
x86_l_5bc:
	/* 0x5bc: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_5c2:
	/* 0x5c2: lea    ecx,[rsi+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_5c8:
	/* 0x5c8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5ce:
	/* 0x5ce: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_5d2:
	/* 0x5d2: mov    BYTE PTR [rax+0x20],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5d5:
	/* 0x5d5: cmp    rsi,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 29ULL);
x86_l_5d9:
	/* 0x5d9: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_5df:
	/* 0x5df: lea    ecx,[rsi+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_5e5:
	/* 0x5e5: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5eb:
	/* 0x5eb: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_5ef:
	/* 0x5ef: mov    BYTE PTR [rax+0x21],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_5f2:
	/* 0x5f2: cmp    rsi,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 30ULL);
x86_l_5f6:
	/* 0x5f6: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_5fc:
	/* 0x5fc: lea    ecx,[rsi+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_602:
	/* 0x602: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_608:
	/* 0x608: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_60c:
	/* 0x60c: mov    BYTE PTR [rax+0x22],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_60f:
	/* 0x60f: cmp    rsi,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 31ULL);
x86_l_613:
	/* 0x613: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_619:
	/* 0x619: lea    ecx,[rsi+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_61f:
	/* 0x61f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_625:
	/* 0x625: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_629:
	/* 0x629: mov    BYTE PTR [rax+0x23],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_62c:
	/* 0x62c: cmp    rsi,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 32ULL);
x86_l_630:
	/* 0x630: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_636:
	/* 0x636: lea    ecx,[rsi+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_63c:
	/* 0x63c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_642:
	/* 0x642: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_646:
	/* 0x646: mov    BYTE PTR [rax+0x24],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_649:
	/* 0x649: cmp    rsi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 33ULL);
x86_l_64d:
	/* 0x64d: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_653:
	/* 0x653: lea    ecx,[rsi+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_659:
	/* 0x659: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_65f:
	/* 0x65f: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_663:
	/* 0x663: mov    BYTE PTR [rax+0x25],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_666:
	/* 0x666: cmp    rsi,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 34ULL);
x86_l_66a:
	/* 0x66a: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_670:
	/* 0x670: lea    ecx,[rsi+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_676:
	/* 0x676: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_67c:
	/* 0x67c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_680:
	/* 0x680: mov    BYTE PTR [rax+0x26],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_683:
	/* 0x683: cmp    rsi,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 35ULL);
x86_l_687:
	/* 0x687: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_68d:
	/* 0x68d: lea    ecx,[rsi+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_693:
	/* 0x693: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_699:
	/* 0x699: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_69d:
	/* 0x69d: mov    BYTE PTR [rax+0x27],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_6a0:
	/* 0x6a0: cmp    rsi,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 36ULL);
x86_l_6a4:
	/* 0x6a4: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_6aa:
	/* 0x6aa: lea    ecx,[rsi+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_6b0:
	/* 0x6b0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6b6:
	/* 0x6b6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_6ba:
	/* 0x6ba: mov    BYTE PTR [rax+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6bd:
	/* 0x6bd: cmp    rsi,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 37ULL);
x86_l_6c1:
	/* 0x6c1: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_6c7:
	/* 0x6c7: lea    ecx,[rsi+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_6cd:
	/* 0x6cd: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6d3:
	/* 0x6d3: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_6d7:
	/* 0x6d7: mov    BYTE PTR [rax+0x29],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_6da:
	/* 0x6da: cmp    rsi,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 38ULL);
x86_l_6de:
	/* 0x6de: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_6e4:
	/* 0x6e4: lea    ecx,[rsi+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_6ea:
	/* 0x6ea: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6f0:
	/* 0x6f0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_6f4:
	/* 0x6f4: mov    BYTE PTR [rax+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_6f7:
	/* 0x6f7: cmp    rsi,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 39ULL);
x86_l_6fb:
	/* 0x6fb: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3358ULL;
	}
x86_l_701:
	/* 0x701: lea    ecx,[rsi+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_707:
	/* 0x707: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_70d:
	/* 0x70d: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_711:
	/* 0x711: mov    BYTE PTR [rax+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
	return 1812ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1812ULL: goto x86_l_714;
	case 1816ULL: goto x86_l_718;
	case 1822ULL: goto x86_l_71e;
	case 1828ULL: goto x86_l_724;
	case 1834ULL: goto x86_l_72a;
	case 1838ULL: goto x86_l_72e;
	case 1841ULL: goto x86_l_731;
	case 1845ULL: goto x86_l_735;
	case 1851ULL: goto x86_l_73b;
	case 1857ULL: goto x86_l_741;
	case 1863ULL: goto x86_l_747;
	case 1867ULL: goto x86_l_74b;
	case 1870ULL: goto x86_l_74e;
	case 1874ULL: goto x86_l_752;
	case 1880ULL: goto x86_l_758;
	case 1886ULL: goto x86_l_75e;
	case 1892ULL: goto x86_l_764;
	case 1896ULL: goto x86_l_768;
	case 1899ULL: goto x86_l_76b;
	case 1903ULL: goto x86_l_76f;
	case 1909ULL: goto x86_l_775;
	case 1915ULL: goto x86_l_77b;
	case 1921ULL: goto x86_l_781;
	case 1925ULL: goto x86_l_785;
	case 1928ULL: goto x86_l_788;
	case 1932ULL: goto x86_l_78c;
	case 1938ULL: goto x86_l_792;
	case 1944ULL: goto x86_l_798;
	case 1950ULL: goto x86_l_79e;
	case 1954ULL: goto x86_l_7a2;
	case 1957ULL: goto x86_l_7a5;
	case 1961ULL: goto x86_l_7a9;
	case 1967ULL: goto x86_l_7af;
	case 1973ULL: goto x86_l_7b5;
	case 1979ULL: goto x86_l_7bb;
	case 1983ULL: goto x86_l_7bf;
	case 1986ULL: goto x86_l_7c2;
	case 1990ULL: goto x86_l_7c6;
	case 1996ULL: goto x86_l_7cc;
	case 2002ULL: goto x86_l_7d2;
	case 2008ULL: goto x86_l_7d8;
	case 2012ULL: goto x86_l_7dc;
	case 2015ULL: goto x86_l_7df;
	case 2019ULL: goto x86_l_7e3;
	case 2025ULL: goto x86_l_7e9;
	case 2031ULL: goto x86_l_7ef;
	case 2037ULL: goto x86_l_7f5;
	case 2041ULL: goto x86_l_7f9;
	case 2044ULL: goto x86_l_7fc;
	case 2048ULL: goto x86_l_800;
	case 2054ULL: goto x86_l_806;
	case 2060ULL: goto x86_l_80c;
	case 2066ULL: goto x86_l_812;
	case 2070ULL: goto x86_l_816;
	case 2073ULL: goto x86_l_819;
	case 2077ULL: goto x86_l_81d;
	case 2083ULL: goto x86_l_823;
	case 2089ULL: goto x86_l_829;
	case 2095ULL: goto x86_l_82f;
	case 2099ULL: goto x86_l_833;
	case 2102ULL: goto x86_l_836;
	case 2106ULL: goto x86_l_83a;
	case 2112ULL: goto x86_l_840;
	case 2118ULL: goto x86_l_846;
	case 2124ULL: goto x86_l_84c;
	case 2128ULL: goto x86_l_850;
	case 2131ULL: goto x86_l_853;
	case 2135ULL: goto x86_l_857;
	case 2141ULL: goto x86_l_85d;
	case 2147ULL: goto x86_l_863;
	case 2153ULL: goto x86_l_869;
	case 2157ULL: goto x86_l_86d;
	case 2160ULL: goto x86_l_870;
	case 2164ULL: goto x86_l_874;
	case 2170ULL: goto x86_l_87a;
	case 2176ULL: goto x86_l_880;
	case 2182ULL: goto x86_l_886;
	case 2186ULL: goto x86_l_88a;
	case 2189ULL: goto x86_l_88d;
	case 2193ULL: goto x86_l_891;
	case 2199ULL: goto x86_l_897;
	case 2205ULL: goto x86_l_89d;
	case 2211ULL: goto x86_l_8a3;
	case 2215ULL: goto x86_l_8a7;
	case 2218ULL: goto x86_l_8aa;
	case 2222ULL: goto x86_l_8ae;
	case 2228ULL: goto x86_l_8b4;
	case 2234ULL: goto x86_l_8ba;
	case 2240ULL: goto x86_l_8c0;
	case 2244ULL: goto x86_l_8c4;
	case 2247ULL: goto x86_l_8c7;
	case 2251ULL: goto x86_l_8cb;
	case 2257ULL: goto x86_l_8d1;
	case 2263ULL: goto x86_l_8d7;
	case 2269ULL: goto x86_l_8dd;
	case 2273ULL: goto x86_l_8e1;
	case 2276ULL: goto x86_l_8e4;
	case 2280ULL: goto x86_l_8e8;
	case 2286ULL: goto x86_l_8ee;
	case 2292ULL: goto x86_l_8f4;
	case 2298ULL: goto x86_l_8fa;
	case 2302ULL: goto x86_l_8fe;
	case 2305ULL: goto x86_l_901;
	case 2309ULL: goto x86_l_905;
	case 2315ULL: goto x86_l_90b;
	case 2321ULL: goto x86_l_911;
	case 2327ULL: goto x86_l_917;
	case 2331ULL: goto x86_l_91b;
	case 2334ULL: goto x86_l_91e;
	case 2338ULL: goto x86_l_922;
	case 2344ULL: goto x86_l_928;
	case 2350ULL: goto x86_l_92e;
	case 2356ULL: goto x86_l_934;
	case 2360ULL: goto x86_l_938;
	case 2363ULL: goto x86_l_93b;
	case 2367ULL: goto x86_l_93f;
	case 2373ULL: goto x86_l_945;
	case 2379ULL: goto x86_l_94b;
	case 2385ULL: goto x86_l_951;
	case 2389ULL: goto x86_l_955;
	case 2392ULL: goto x86_l_958;
	case 2396ULL: goto x86_l_95c;
	case 2402ULL: goto x86_l_962;
	case 2408ULL: goto x86_l_968;
	case 2414ULL: goto x86_l_96e;
	case 2418ULL: goto x86_l_972;
	case 2421ULL: goto x86_l_975;
	case 2425ULL: goto x86_l_979;
	case 2431ULL: goto x86_l_97f;
	case 2437ULL: goto x86_l_985;
	case 2443ULL: goto x86_l_98b;
	case 2447ULL: goto x86_l_98f;
	case 2450ULL: goto x86_l_992;
	case 2454ULL: goto x86_l_996;
	case 2460ULL: goto x86_l_99c;
	case 2466ULL: goto x86_l_9a2;
	case 2472ULL: goto x86_l_9a8;
	case 2476ULL: goto x86_l_9ac;
	case 2479ULL: goto x86_l_9af;
	case 2483ULL: goto x86_l_9b3;
	case 2489ULL: goto x86_l_9b9;
	case 2495ULL: goto x86_l_9bf;
	case 2501ULL: goto x86_l_9c5;
	case 2505ULL: goto x86_l_9c9;
	case 2508ULL: goto x86_l_9cc;
	case 2512ULL: goto x86_l_9d0;
	case 2518ULL: goto x86_l_9d6;
	case 2524ULL: goto x86_l_9dc;
	case 2530ULL: goto x86_l_9e2;
	case 2534ULL: goto x86_l_9e6;
	case 2537ULL: goto x86_l_9e9;
	case 2541ULL: goto x86_l_9ed;
	case 2547ULL: goto x86_l_9f3;
	case 2553ULL: goto x86_l_9f9;
	case 2559ULL: goto x86_l_9ff;
	case 2563ULL: goto x86_l_a03;
	case 2566ULL: goto x86_l_a06;
	case 2570ULL: goto x86_l_a0a;
	case 2576ULL: goto x86_l_a10;
	case 2582ULL: goto x86_l_a16;
	case 2588ULL: goto x86_l_a1c;
	case 2592ULL: goto x86_l_a20;
	case 2595ULL: goto x86_l_a23;
	case 2599ULL: goto x86_l_a27;
	case 2605ULL: goto x86_l_a2d;
	case 2611ULL: goto x86_l_a33;
	case 2617ULL: goto x86_l_a39;
	case 2621ULL: goto x86_l_a3d;
	case 2624ULL: goto x86_l_a40;
	case 2628ULL: goto x86_l_a44;
	case 2634ULL: goto x86_l_a4a;
	case 2640ULL: goto x86_l_a50;
	case 2646ULL: goto x86_l_a56;
	case 2650ULL: goto x86_l_a5a;
	case 2653ULL: goto x86_l_a5d;
	case 2657ULL: goto x86_l_a61;
	case 2663ULL: goto x86_l_a67;
	case 2669ULL: goto x86_l_a6d;
	case 2675ULL: goto x86_l_a73;
	case 2679ULL: goto x86_l_a77;
	case 2682ULL: goto x86_l_a7a;
	case 2686ULL: goto x86_l_a7e;
	case 2692ULL: goto x86_l_a84;
	case 2698ULL: goto x86_l_a8a;
	case 2704ULL: goto x86_l_a90;
	case 2708ULL: goto x86_l_a94;
	case 2711ULL: goto x86_l_a97;
	case 2715ULL: goto x86_l_a9b;
	case 2721ULL: goto x86_l_aa1;
	case 2727ULL: goto x86_l_aa7;
	case 2733ULL: goto x86_l_aad;
	case 2737ULL: goto x86_l_ab1;
	case 2740ULL: goto x86_l_ab4;
	case 2744ULL: goto x86_l_ab8;
	case 2750ULL: goto x86_l_abe;
	case 2756ULL: goto x86_l_ac4;
	case 2762ULL: goto x86_l_aca;
	case 2766ULL: goto x86_l_ace;
	case 2769ULL: goto x86_l_ad1;
	case 2773ULL: goto x86_l_ad5;
	case 2779ULL: goto x86_l_adb;
	case 2785ULL: goto x86_l_ae1;
	case 2791ULL: goto x86_l_ae7;
	case 2795ULL: goto x86_l_aeb;
	case 2798ULL: goto x86_l_aee;
	case 2802ULL: goto x86_l_af2;
	case 2808ULL: goto x86_l_af8;
	case 2814ULL: goto x86_l_afe;
	case 2820ULL: goto x86_l_b04;
	case 2824ULL: goto x86_l_b08;
	case 2827ULL: goto x86_l_b0b;
	case 2831ULL: goto x86_l_b0f;
	case 2837ULL: goto x86_l_b15;
	case 2843ULL: goto x86_l_b1b;
	case 2849ULL: goto x86_l_b21;
	case 2853ULL: goto x86_l_b25;
	case 2856ULL: goto x86_l_b28;
	case 2860ULL: goto x86_l_b2c;
	case 2866ULL: goto x86_l_b32;
	case 2872ULL: goto x86_l_b38;
	case 2878ULL: goto x86_l_b3e;
	case 2882ULL: goto x86_l_b42;
	case 2885ULL: goto x86_l_b45;
	case 2889ULL: goto x86_l_b49;
	case 2895ULL: goto x86_l_b4f;
	case 2901ULL: goto x86_l_b55;
	case 2907ULL: goto x86_l_b5b;
	case 2911ULL: goto x86_l_b5f;
	case 2914ULL: goto x86_l_b62;
	case 2918ULL: goto x86_l_b66;
	case 2924ULL: goto x86_l_b6c;
	case 2930ULL: goto x86_l_b72;
	case 2936ULL: goto x86_l_b78;
	case 2940ULL: goto x86_l_b7c;
	case 2943ULL: goto x86_l_b7f;
	case 2947ULL: goto x86_l_b83;
	case 2953ULL: goto x86_l_b89;
	case 2959ULL: goto x86_l_b8f;
	case 2965ULL: goto x86_l_b95;
	case 2969ULL: goto x86_l_b99;
	case 2972ULL: goto x86_l_b9c;
	case 2976ULL: goto x86_l_ba0;
	case 2982ULL: goto x86_l_ba6;
	case 2988ULL: goto x86_l_bac;
	case 2994ULL: goto x86_l_bb2;
	case 2998ULL: goto x86_l_bb6;
	case 3001ULL: goto x86_l_bb9;
	case 3005ULL: goto x86_l_bbd;
	case 3011ULL: goto x86_l_bc3;
	case 3017ULL: goto x86_l_bc9;
	case 3023ULL: goto x86_l_bcf;
	case 3027ULL: goto x86_l_bd3;
	case 3030ULL: goto x86_l_bd6;
	case 3034ULL: goto x86_l_bda;
	case 3040ULL: goto x86_l_be0;
	case 3046ULL: goto x86_l_be6;
	case 3052ULL: goto x86_l_bec;
	case 3056ULL: goto x86_l_bf0;
	case 3059ULL: goto x86_l_bf3;
	case 3063ULL: goto x86_l_bf7;
	case 3069ULL: goto x86_l_bfd;
	case 3075ULL: goto x86_l_c03;
	case 3081ULL: goto x86_l_c09;
	case 3085ULL: goto x86_l_c0d;
	case 3088ULL: goto x86_l_c10;
	case 3092ULL: goto x86_l_c14;
	case 3098ULL: goto x86_l_c1a;
	case 3104ULL: goto x86_l_c20;
	case 3110ULL: goto x86_l_c26;
	case 3114ULL: goto x86_l_c2a;
	case 3117ULL: goto x86_l_c2d;
	case 3121ULL: goto x86_l_c31;
	case 3127ULL: goto x86_l_c37;
	case 3133ULL: goto x86_l_c3d;
	case 3139ULL: goto x86_l_c43;
	case 3143ULL: goto x86_l_c47;
	case 3146ULL: goto x86_l_c4a;
	case 3150ULL: goto x86_l_c4e;
	case 3156ULL: goto x86_l_c54;
	case 3162ULL: goto x86_l_c5a;
	case 3168ULL: goto x86_l_c60;
	case 3172ULL: goto x86_l_c64;
	case 3175ULL: goto x86_l_c67;
	case 3179ULL: goto x86_l_c6b;
	case 3185ULL: goto x86_l_c71;
	case 3191ULL: goto x86_l_c77;
	case 3197ULL: goto x86_l_c7d;
	case 3201ULL: goto x86_l_c81;
	case 3204ULL: goto x86_l_c84;
	case 3208ULL: goto x86_l_c88;
	case 3214ULL: goto x86_l_c8e;
	case 3220ULL: goto x86_l_c94;
	case 3226ULL: goto x86_l_c9a;
	case 3230ULL: goto x86_l_c9e;
	case 3233ULL: goto x86_l_ca1;
	case 3237ULL: goto x86_l_ca5;
	case 3239ULL: goto x86_l_ca7;
	case 3245ULL: goto x86_l_cad;
	case 3251ULL: goto x86_l_cb3;
	case 3255ULL: goto x86_l_cb7;
	case 3258ULL: goto x86_l_cba;
	case 3262ULL: goto x86_l_cbe;
	case 3264ULL: goto x86_l_cc0;
	case 3270ULL: goto x86_l_cc6;
	case 3276ULL: goto x86_l_ccc;
	case 3280ULL: goto x86_l_cd0;
	case 3283ULL: goto x86_l_cd3;
	case 3287ULL: goto x86_l_cd7;
	case 3289ULL: goto x86_l_cd9;
	case 3295ULL: goto x86_l_cdf;
	case 3301ULL: goto x86_l_ce5;
	case 3305ULL: goto x86_l_ce9;
	case 3308ULL: goto x86_l_cec;
	case 3312ULL: goto x86_l_cf0;
	case 3314ULL: goto x86_l_cf2;
	case 3320ULL: goto x86_l_cf8;
	case 3326ULL: goto x86_l_cfe;
	case 3330ULL: goto x86_l_d02;
	case 3333ULL: goto x86_l_d05;
	case 3337ULL: goto x86_l_d09;
	case 3339ULL: goto x86_l_d0b;
	case 3345ULL: goto x86_l_d11;
	case 3351ULL: goto x86_l_d17;
	case 3355ULL: goto x86_l_d1b;
	case 3358ULL: goto x86_l_d1e;
	case 3363ULL: goto x86_l_d23;
	case 3366ULL: goto x86_l_d26;
	case 3369ULL: goto x86_l_d29;
	case 3374ULL: goto x86_l_d2e;
	case 3377ULL: goto x86_l_d31;
	case 3383ULL: goto x86_l_d37;
	case 3386ULL: goto x86_l_d3a;
	case 3392ULL: goto x86_l_d40;
	case 3396ULL: goto x86_l_d44;
	case 3399ULL: goto x86_l_d47;
	case 3402ULL: goto x86_l_d4a;
	case 3408ULL: goto x86_l_d50;
	case 3411ULL: goto x86_l_d53;
	case 3415ULL: goto x86_l_d57;
	case 3420ULL: goto x86_l_d5c;
	case 3423ULL: goto x86_l_d5f;
	case 3427ULL: goto x86_l_d63;
	case 3433ULL: goto x86_l_d69;
	case 3438ULL: goto x86_l_d6e;
	case 3441ULL: goto x86_l_d71;
	case 3446ULL: goto x86_l_d76;
	case 3452ULL: goto x86_l_d7c;
	case 3457ULL: goto x86_l_d81;
	case 3460ULL: goto x86_l_d84;
	case 3466ULL: goto x86_l_d8a;
	case 3471ULL: goto x86_l_d8f;
	case 3475ULL: goto x86_l_d93;
	case 3479ULL: goto x86_l_d97;
	case 3487ULL: goto x86_l_d9f;
	case 3492ULL: goto x86_l_da4;
	case 3499ULL: goto x86_l_dab;
	case 3504ULL: goto x86_l_db0;
	case 3506ULL: goto x86_l_db2;
	case 3509ULL: goto x86_l_db5;
	case 3514ULL: goto x86_l_dba;
	case 3520ULL: goto x86_l_dc0;
	case 3523ULL: goto x86_l_dc3;
	case 3526ULL: goto x86_l_dc6;
	case 3532ULL: goto x86_l_dcc;
	case 3537ULL: goto x86_l_dd1;
	case 3544ULL: goto x86_l_dd8;
	case 3549ULL: goto x86_l_ddd;
	case 3551ULL: goto x86_l_ddf;
	case 3554ULL: goto x86_l_de2;
	case 3560ULL: goto x86_l_de8;
	case 3564ULL: goto x86_l_dec;
	case 3567ULL: goto x86_l_def;
	case 3572ULL: goto x86_l_df4;
	case 3575ULL: goto x86_l_df7;
	case 3578ULL: goto x86_l_dfa;
	case 3580ULL: goto x86_l_dfc;
	case 3583ULL: goto x86_l_dff;
	case 3589ULL: goto x86_l_e05;
	case 3594ULL: goto x86_l_e0a;
	case 3598ULL: goto x86_l_e0e;
	case 3601ULL: goto x86_l_e11;
	case 3605ULL: goto x86_l_e15;
	case 3611ULL: goto x86_l_e1b;
	case 3615ULL: goto x86_l_e1f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_714:
	/* 0x714: cmp    rsi,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 40ULL);
x86_l_718:
	/* 0x718: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_71e:
	/* 0x71e: lea    ecx,[rsi+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_724:
	/* 0x724: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_72a:
	/* 0x72a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_72e:
	/* 0x72e: mov    BYTE PTR [rax+0x2c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_731:
	/* 0x731: cmp    rsi,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 41ULL);
x86_l_735:
	/* 0x735: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_73b:
	/* 0x73b: lea    ecx,[rsi+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_741:
	/* 0x741: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_747:
	/* 0x747: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_74b:
	/* 0x74b: mov    BYTE PTR [rax+0x2d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_74e:
	/* 0x74e: cmp    rsi,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 42ULL);
x86_l_752:
	/* 0x752: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_758:
	/* 0x758: lea    ecx,[rsi+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_75e:
	/* 0x75e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_764:
	/* 0x764: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_768:
	/* 0x768: mov    BYTE PTR [rax+0x2e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_76b:
	/* 0x76b: cmp    rsi,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 43ULL);
x86_l_76f:
	/* 0x76f: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_775:
	/* 0x775: lea    ecx,[rsi+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_77b:
	/* 0x77b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_781:
	/* 0x781: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_785:
	/* 0x785: mov    BYTE PTR [rax+0x2f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_788:
	/* 0x788: cmp    rsi,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 44ULL);
x86_l_78c:
	/* 0x78c: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_792:
	/* 0x792: lea    ecx,[rsi+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_798:
	/* 0x798: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_79e:
	/* 0x79e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_7a2:
	/* 0x7a2: mov    BYTE PTR [rax+0x30],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7a5:
	/* 0x7a5: cmp    rsi,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 45ULL);
x86_l_7a9:
	/* 0x7a9: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_7af:
	/* 0x7af: lea    ecx,[rsi+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_7b5:
	/* 0x7b5: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7bb:
	/* 0x7bb: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_7bf:
	/* 0x7bf: mov    BYTE PTR [rax+0x31],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_7c2:
	/* 0x7c2: cmp    rsi,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 46ULL);
x86_l_7c6:
	/* 0x7c6: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_7cc:
	/* 0x7cc: lea    ecx,[rsi+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_7d2:
	/* 0x7d2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7d8:
	/* 0x7d8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_7dc:
	/* 0x7dc: mov    BYTE PTR [rax+0x32],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_7df:
	/* 0x7df: cmp    rsi,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 47ULL);
x86_l_7e3:
	/* 0x7e3: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_7e9:
	/* 0x7e9: lea    ecx,[rsi+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_7ef:
	/* 0x7ef: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7f5:
	/* 0x7f5: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_7f9:
	/* 0x7f9: mov    BYTE PTR [rax+0x33],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_7fc:
	/* 0x7fc: cmp    rsi,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 48ULL);
x86_l_800:
	/* 0x800: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_806:
	/* 0x806: lea    ecx,[rsi+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_80c:
	/* 0x80c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_812:
	/* 0x812: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_816:
	/* 0x816: mov    BYTE PTR [rax+0x34],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_819:
	/* 0x819: cmp    rsi,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 49ULL);
x86_l_81d:
	/* 0x81d: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_823:
	/* 0x823: lea    ecx,[rsi+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_829:
	/* 0x829: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_82f:
	/* 0x82f: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_833:
	/* 0x833: mov    BYTE PTR [rax+0x35],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_836:
	/* 0x836: cmp    rsi,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 50ULL);
x86_l_83a:
	/* 0x83a: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_840:
	/* 0x840: lea    ecx,[rsi+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_846:
	/* 0x846: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_84c:
	/* 0x84c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_850:
	/* 0x850: mov    BYTE PTR [rax+0x36],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_853:
	/* 0x853: cmp    rsi,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 51ULL);
x86_l_857:
	/* 0x857: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_85d:
	/* 0x85d: lea    ecx,[rsi+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_863:
	/* 0x863: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_869:
	/* 0x869: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_86d:
	/* 0x86d: mov    BYTE PTR [rax+0x37],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_870:
	/* 0x870: cmp    rsi,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 52ULL);
x86_l_874:
	/* 0x874: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_87a:
	/* 0x87a: lea    ecx,[rsi+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_880:
	/* 0x880: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_886:
	/* 0x886: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_88a:
	/* 0x88a: mov    BYTE PTR [rax+0x38],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_88d:
	/* 0x88d: cmp    rsi,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 53ULL);
x86_l_891:
	/* 0x891: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_897:
	/* 0x897: lea    ecx,[rsi+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_89d:
	/* 0x89d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8a3:
	/* 0x8a3: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_8a7:
	/* 0x8a7: mov    BYTE PTR [rax+0x39],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_8aa:
	/* 0x8aa: cmp    rsi,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 54ULL);
x86_l_8ae:
	/* 0x8ae: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_8b4:
	/* 0x8b4: lea    ecx,[rsi+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_8ba:
	/* 0x8ba: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8c0:
	/* 0x8c0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_8c4:
	/* 0x8c4: mov    BYTE PTR [rax+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_8c7:
	/* 0x8c7: cmp    rsi,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 55ULL);
x86_l_8cb:
	/* 0x8cb: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_8d1:
	/* 0x8d1: lea    ecx,[rsi+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_8d7:
	/* 0x8d7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8dd:
	/* 0x8dd: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_8e1:
	/* 0x8e1: mov    BYTE PTR [rax+0x3b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_8e4:
	/* 0x8e4: cmp    rsi,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 56ULL);
x86_l_8e8:
	/* 0x8e8: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_8ee:
	/* 0x8ee: lea    ecx,[rsi+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_8f4:
	/* 0x8f4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8fa:
	/* 0x8fa: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_8fe:
	/* 0x8fe: mov    BYTE PTR [rax+0x3c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_901:
	/* 0x901: cmp    rsi,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 57ULL);
x86_l_905:
	/* 0x905: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_90b:
	/* 0x90b: lea    ecx,[rsi+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_911:
	/* 0x911: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_917:
	/* 0x917: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_91b:
	/* 0x91b: mov    BYTE PTR [rax+0x3d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_91e:
	/* 0x91e: cmp    rsi,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 58ULL);
x86_l_922:
	/* 0x922: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_928:
	/* 0x928: lea    ecx,[rsi+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_92e:
	/* 0x92e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_934:
	/* 0x934: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_938:
	/* 0x938: mov    BYTE PTR [rax+0x3e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_93b:
	/* 0x93b: cmp    rsi,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 59ULL);
x86_l_93f:
	/* 0x93f: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_945:
	/* 0x945: lea    ecx,[rsi+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_94b:
	/* 0x94b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_951:
	/* 0x951: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_955:
	/* 0x955: mov    BYTE PTR [rax+0x3f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_958:
	/* 0x958: cmp    rsi,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 60ULL);
x86_l_95c:
	/* 0x95c: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_962:
	/* 0x962: lea    ecx,[rsi+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_968:
	/* 0x968: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_96e:
	/* 0x96e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_972:
	/* 0x972: mov    BYTE PTR [rax+0x40],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_975:
	/* 0x975: cmp    rsi,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 61ULL);
x86_l_979:
	/* 0x979: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_97f:
	/* 0x97f: lea    ecx,[rsi+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_985:
	/* 0x985: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_98b:
	/* 0x98b: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_98f:
	/* 0x98f: mov    BYTE PTR [rax+0x41],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_992:
	/* 0x992: cmp    rsi,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 62ULL);
x86_l_996:
	/* 0x996: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_99c:
	/* 0x99c: lea    ecx,[rsi+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_9a2:
	/* 0x9a2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9a8:
	/* 0x9a8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_9ac:
	/* 0x9ac: mov    BYTE PTR [rax+0x42],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_9af:
	/* 0x9af: cmp    rsi,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 63ULL);
x86_l_9b3:
	/* 0x9b3: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_9b9:
	/* 0x9b9: lea    ecx,[rsi+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_9bf:
	/* 0x9bf: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9c5:
	/* 0x9c5: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_9c9:
	/* 0x9c9: mov    BYTE PTR [rax+0x43],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_9cc:
	/* 0x9cc: cmp    rsi,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 64ULL);
x86_l_9d0:
	/* 0x9d0: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_9d6:
	/* 0x9d6: lea    ecx,[rsi+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_9dc:
	/* 0x9dc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9e2:
	/* 0x9e2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_9e6:
	/* 0x9e6: mov    BYTE PTR [rax+0x44],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_9e9:
	/* 0x9e9: cmp    rsi,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 65ULL);
x86_l_9ed:
	/* 0x9ed: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_9f3:
	/* 0x9f3: lea    ecx,[rsi+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_9f9:
	/* 0x9f9: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9ff:
	/* 0x9ff: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a03:
	/* 0xa03: mov    BYTE PTR [rax+0x45],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_a06:
	/* 0xa06: cmp    rsi,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 66ULL);
x86_l_a0a:
	/* 0xa0a: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_a10:
	/* 0xa10: lea    ecx,[rsi+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_a16:
	/* 0xa16: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a1c:
	/* 0xa1c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a20:
	/* 0xa20: mov    BYTE PTR [rax+0x46],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_a23:
	/* 0xa23: cmp    rsi,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 67ULL);
x86_l_a27:
	/* 0xa27: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_a2d:
	/* 0xa2d: lea    ecx,[rsi+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_a33:
	/* 0xa33: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a39:
	/* 0xa39: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a3d:
	/* 0xa3d: mov    BYTE PTR [rax+0x47],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_a40:
	/* 0xa40: cmp    rsi,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 68ULL);
x86_l_a44:
	/* 0xa44: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_a4a:
	/* 0xa4a: lea    ecx,[rsi+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_a50:
	/* 0xa50: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a56:
	/* 0xa56: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a5a:
	/* 0xa5a: mov    BYTE PTR [rax+0x48],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a5d:
	/* 0xa5d: cmp    rsi,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 69ULL);
x86_l_a61:
	/* 0xa61: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_a67:
	/* 0xa67: lea    ecx,[rsi+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_a6d:
	/* 0xa6d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a73:
	/* 0xa73: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a77:
	/* 0xa77: mov    BYTE PTR [rax+0x49],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_a7a:
	/* 0xa7a: cmp    rsi,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 70ULL);
x86_l_a7e:
	/* 0xa7e: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_a84:
	/* 0xa84: lea    ecx,[rsi+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_a8a:
	/* 0xa8a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a90:
	/* 0xa90: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a94:
	/* 0xa94: mov    BYTE PTR [rax+0x4a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_a97:
	/* 0xa97: cmp    rsi,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 71ULL);
x86_l_a9b:
	/* 0xa9b: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_aa1:
	/* 0xaa1: lea    ecx,[rsi+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_aa7:
	/* 0xaa7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_aad:
	/* 0xaad: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_ab1:
	/* 0xab1: mov    BYTE PTR [rax+0x4b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_ab4:
	/* 0xab4: cmp    rsi,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 72ULL);
x86_l_ab8:
	/* 0xab8: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_abe:
	/* 0xabe: lea    ecx,[rsi+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_ac4:
	/* 0xac4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_aca:
	/* 0xaca: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_ace:
	/* 0xace: mov    BYTE PTR [rax+0x4c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_ad1:
	/* 0xad1: cmp    rsi,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 73ULL);
x86_l_ad5:
	/* 0xad5: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_adb:
	/* 0xadb: lea    ecx,[rsi+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_ae1:
	/* 0xae1: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ae7:
	/* 0xae7: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_aeb:
	/* 0xaeb: mov    BYTE PTR [rax+0x4d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_aee:
	/* 0xaee: cmp    rsi,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 74ULL);
x86_l_af2:
	/* 0xaf2: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_af8:
	/* 0xaf8: lea    ecx,[rsi+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_afe:
	/* 0xafe: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b04:
	/* 0xb04: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b08:
	/* 0xb08: mov    BYTE PTR [rax+0x4e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_b0b:
	/* 0xb0b: cmp    rsi,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 75ULL);
x86_l_b0f:
	/* 0xb0f: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_b15:
	/* 0xb15: lea    ecx,[rsi+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_b1b:
	/* 0xb1b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b21:
	/* 0xb21: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b25:
	/* 0xb25: mov    BYTE PTR [rax+0x4f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_b28:
	/* 0xb28: cmp    rsi,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 76ULL);
x86_l_b2c:
	/* 0xb2c: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_b32:
	/* 0xb32: lea    ecx,[rsi+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_b38:
	/* 0xb38: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b3e:
	/* 0xb3e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b42:
	/* 0xb42: mov    BYTE PTR [rax+0x50],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b45:
	/* 0xb45: cmp    rsi,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 77ULL);
x86_l_b49:
	/* 0xb49: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_b4f:
	/* 0xb4f: lea    ecx,[rsi+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_b55:
	/* 0xb55: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b5b:
	/* 0xb5b: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b5f:
	/* 0xb5f: mov    BYTE PTR [rax+0x51],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_b62:
	/* 0xb62: cmp    rsi,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 78ULL);
x86_l_b66:
	/* 0xb66: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_b6c:
	/* 0xb6c: lea    ecx,[rsi+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_b72:
	/* 0xb72: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b78:
	/* 0xb78: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b7c:
	/* 0xb7c: mov    BYTE PTR [rax+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_b7f:
	/* 0xb7f: cmp    rsi,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 79ULL);
x86_l_b83:
	/* 0xb83: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_b89:
	/* 0xb89: lea    ecx,[rsi+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_b8f:
	/* 0xb8f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b95:
	/* 0xb95: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b99:
	/* 0xb99: mov    BYTE PTR [rax+0x53],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_b9c:
	/* 0xb9c: cmp    rsi,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 80ULL);
x86_l_ba0:
	/* 0xba0: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_ba6:
	/* 0xba6: lea    ecx,[rsi+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_bac:
	/* 0xbac: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bb2:
	/* 0xbb2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_bb6:
	/* 0xbb6: mov    BYTE PTR [rax+0x54],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_bb9:
	/* 0xbb9: cmp    rsi,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 81ULL);
x86_l_bbd:
	/* 0xbbd: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_bc3:
	/* 0xbc3: lea    ecx,[rsi+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_bc9:
	/* 0xbc9: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bcf:
	/* 0xbcf: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_bd3:
	/* 0xbd3: mov    BYTE PTR [rax+0x55],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_bd6:
	/* 0xbd6: cmp    rsi,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 82ULL);
x86_l_bda:
	/* 0xbda: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_be0:
	/* 0xbe0: lea    ecx,[rsi+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_be6:
	/* 0xbe6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bec:
	/* 0xbec: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_bf0:
	/* 0xbf0: mov    BYTE PTR [rax+0x56],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_bf3:
	/* 0xbf3: cmp    rsi,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 83ULL);
x86_l_bf7:
	/* 0xbf7: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_bfd:
	/* 0xbfd: lea    ecx,[rsi+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_c03:
	/* 0xc03: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c09:
	/* 0xc09: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c0d:
	/* 0xc0d: mov    BYTE PTR [rax+0x57],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_c10:
	/* 0xc10: cmp    rsi,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 84ULL);
x86_l_c14:
	/* 0xc14: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_c1a:
	/* 0xc1a: lea    ecx,[rsi+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_c20:
	/* 0xc20: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c26:
	/* 0xc26: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c2a:
	/* 0xc2a: mov    BYTE PTR [rax+0x58],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c2d:
	/* 0xc2d: cmp    rsi,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 85ULL);
x86_l_c31:
	/* 0xc31: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_c37:
	/* 0xc37: lea    ecx,[rsi+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_c3d:
	/* 0xc3d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c43:
	/* 0xc43: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c47:
	/* 0xc47: mov    BYTE PTR [rax+0x59],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_c4a:
	/* 0xc4a: cmp    rsi,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 86ULL);
x86_l_c4e:
	/* 0xc4e: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_c54:
	/* 0xc54: lea    ecx,[rsi+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_c5a:
	/* 0xc5a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c60:
	/* 0xc60: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c64:
	/* 0xc64: mov    BYTE PTR [rax+0x5a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_c67:
	/* 0xc67: cmp    rsi,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 87ULL);
x86_l_c6b:
	/* 0xc6b: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_c71:
	/* 0xc71: lea    ecx,[rsi+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_c77:
	/* 0xc77: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c7d:
	/* 0xc7d: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c81:
	/* 0xc81: mov    BYTE PTR [rax+0x5b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_c84:
	/* 0xc84: cmp    rsi,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 88ULL);
x86_l_c88:
	/* 0xc88: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_c8e:
	/* 0xc8e: lea    ecx,[rsi+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_c94:
	/* 0xc94: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c9a:
	/* 0xc9a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c9e:
	/* 0xc9e: mov    BYTE PTR [rax+0x5c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_ca1:
	/* 0xca1: cmp    rsi,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 89ULL);
x86_l_ca5:
	/* 0xca5: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_ca7:
	/* 0xca7: lea    ecx,[rsi+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_cad:
	/* 0xcad: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_cb3:
	/* 0xcb3: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_cb7:
	/* 0xcb7: mov    BYTE PTR [rax+0x5d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_cba:
	/* 0xcba: cmp    rsi,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 90ULL);
x86_l_cbe:
	/* 0xcbe: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_cc0:
	/* 0xcc0: lea    ecx,[rsi+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_cc6:
	/* 0xcc6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ccc:
	/* 0xccc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_cd0:
	/* 0xcd0: mov    BYTE PTR [rax+0x5e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_cd3:
	/* 0xcd3: cmp    rsi,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 91ULL);
x86_l_cd7:
	/* 0xcd7: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_cd9:
	/* 0xcd9: lea    ecx,[rsi+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_cdf:
	/* 0xcdf: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ce5:
	/* 0xce5: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_ce9:
	/* 0xce9: mov    BYTE PTR [rax+0x5f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_cec:
	/* 0xcec: cmp    rsi,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 92ULL);
x86_l_cf0:
	/* 0xcf0: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_cf2:
	/* 0xcf2: lea    ecx,[rsi+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_cf8:
	/* 0xcf8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_cfe:
	/* 0xcfe: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_d02:
	/* 0xd02: mov    BYTE PTR [rax+0x60],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_d05:
	/* 0xd05: cmp    rsi,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 93ULL);
x86_l_d09:
	/* 0xd09: je     d1e <generic_fexit_filter_arg+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_d0b:
	/* 0xd0b: add    esi,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_d11:
	/* 0xd11: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_d17:
	/* 0xd17: movzx  ecx,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_d1b:
	/* 0xd1b: mov    BYTE PTR [rax+0x61],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_d1e:
	/* 0xd1e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d23:
	/* 0xd23: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_d26:
	/* 0xd26: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d29:
	/* 0xd29: jmp    36b6 <generic_fexit_filter_arg+0x36b6> */
	return 14006ULL;
x86_l_d2e:
	/* 0xd2e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d31:
	/* 0xd31: je     1be3 <generic_fexit_filter_arg+0x1be3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7139ULL;
	}
x86_l_d37:
	/* 0xd37: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d3a:
	/* 0xd3a: jne    37ea <generic_fexit_filter_arg+0x37ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14314ULL;
	}
x86_l_d40:
	/* 0xd40: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d44:
	/* 0xd44: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d47:
	/* 0xd47: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_d4a:
	/* 0xd4a: ja     37ca <generic_fexit_filter_arg+0x37ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14282ULL;
	}
x86_l_d50:
	/* 0xd50: mov    edx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d53:
	/* 0xd53: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_d57:
	/* 0xd57: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_d5c:
	/* 0xd5c: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_d5f:
	/* 0xd5f: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d63:
	/* 0xd63: jb     2e74 <generic_fexit_filter_arg+0x2e74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11892ULL;
	}
x86_l_d69:
	/* 0xd69: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_d6e:
	/* 0xd6e: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_d71:
	/* 0xd71: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d76:
	/* 0xd76: jb     2dce <generic_fexit_filter_arg+0x2dce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11726ULL;
	}
x86_l_d7c:
	/* 0xd7c: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_d81:
	/* 0xd81: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_d84:
	/* 0xd84: jae    37ca <generic_fexit_filter_arg+0x37ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14282ULL;
	}
x86_l_d8a:
	/* 0xd8a: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d8f:
	/* 0xd8f: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d93:
	/* 0xd93: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d97:
	/* 0xd97: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_d9f:
	/* 0xd9f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_da4:
	/* 0xda4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_dab:
	/* 0xdab: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_db0:
	/* 0xdb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db2:
	/* 0xdb2: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_db5:
	/* 0xdb5: cmp    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dba:
	/* 0xdba: je     37c1 <generic_fexit_filter_arg+0x37c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14273ULL;
	}
x86_l_dc0:
	/* 0xdc0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_dc3:
	/* 0xdc3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dc6:
	/* 0xdc6: je     37c1 <generic_fexit_filter_arg+0x37c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14273ULL;
	}
x86_l_dcc:
	/* 0xdcc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dd1:
	/* 0xdd1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_dd8:
	/* 0xdd8: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ddd:
	/* 0xddd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ddf:
	/* 0xddf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_de2:
	/* 0xde2: je     37be <generic_fexit_filter_arg+0x37be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14270ULL;
	}
x86_l_de8:
	/* 0xde8: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dec:
	/* 0xdec: cmp    esi,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 94ULL);
x86_l_def:
	/* 0xdef: mov    ecx,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 94ULL);
x86_l_df4:
	/* 0xdf4: cmovb  ecx,esi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RSI, X86_WIDTH_32, X86_CC_B);
x86_l_df7:
	/* 0xdf7: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_dfa:
	/* 0xdfa: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dfc:
	/* 0xdfc: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_dff:
	/* 0xdff: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_e05:
	/* 0xe05: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e0a:
	/* 0xe0a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_e0e:
	/* 0xe0e: mov    BYTE PTR [rax+0x4],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e11:
	/* 0xe11: cmp    rsi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1ULL);
x86_l_e15:
	/* 0xe15: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_e1b:
	/* 0xe1b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e1f:
	/* 0xe1f: lea    ecx,[rsi+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
	return 3621ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3621ULL: goto x86_l_e25;
	case 3627ULL: goto x86_l_e2b;
	case 3632ULL: goto x86_l_e30;
	case 3636ULL: goto x86_l_e34;
	case 3639ULL: goto x86_l_e37;
	case 3643ULL: goto x86_l_e3b;
	case 3649ULL: goto x86_l_e41;
	case 3653ULL: goto x86_l_e45;
	case 3659ULL: goto x86_l_e4b;
	case 3665ULL: goto x86_l_e51;
	case 3670ULL: goto x86_l_e56;
	case 3674ULL: goto x86_l_e5a;
	case 3677ULL: goto x86_l_e5d;
	case 3681ULL: goto x86_l_e61;
	case 3687ULL: goto x86_l_e67;
	case 3691ULL: goto x86_l_e6b;
	case 3697ULL: goto x86_l_e71;
	case 3703ULL: goto x86_l_e77;
	case 3708ULL: goto x86_l_e7c;
	case 3712ULL: goto x86_l_e80;
	case 3715ULL: goto x86_l_e83;
	case 3719ULL: goto x86_l_e87;
	case 3725ULL: goto x86_l_e8d;
	case 3729ULL: goto x86_l_e91;
	case 3735ULL: goto x86_l_e97;
	case 3741ULL: goto x86_l_e9d;
	case 3746ULL: goto x86_l_ea2;
	case 3750ULL: goto x86_l_ea6;
	case 3753ULL: goto x86_l_ea9;
	case 3757ULL: goto x86_l_ead;
	case 3763ULL: goto x86_l_eb3;
	case 3767ULL: goto x86_l_eb7;
	case 3773ULL: goto x86_l_ebd;
	case 3779ULL: goto x86_l_ec3;
	case 3784ULL: goto x86_l_ec8;
	case 3788ULL: goto x86_l_ecc;
	case 3791ULL: goto x86_l_ecf;
	case 3795ULL: goto x86_l_ed3;
	case 3801ULL: goto x86_l_ed9;
	case 3805ULL: goto x86_l_edd;
	case 3811ULL: goto x86_l_ee3;
	case 3817ULL: goto x86_l_ee9;
	case 3822ULL: goto x86_l_eee;
	case 3826ULL: goto x86_l_ef2;
	case 3829ULL: goto x86_l_ef5;
	case 3833ULL: goto x86_l_ef9;
	case 3839ULL: goto x86_l_eff;
	case 3843ULL: goto x86_l_f03;
	case 3849ULL: goto x86_l_f09;
	case 3855ULL: goto x86_l_f0f;
	case 3860ULL: goto x86_l_f14;
	case 3864ULL: goto x86_l_f18;
	case 3867ULL: goto x86_l_f1b;
	case 3871ULL: goto x86_l_f1f;
	case 3877ULL: goto x86_l_f25;
	case 3881ULL: goto x86_l_f29;
	case 3887ULL: goto x86_l_f2f;
	case 3893ULL: goto x86_l_f35;
	case 3898ULL: goto x86_l_f3a;
	case 3902ULL: goto x86_l_f3e;
	case 3905ULL: goto x86_l_f41;
	case 3909ULL: goto x86_l_f45;
	case 3915ULL: goto x86_l_f4b;
	case 3919ULL: goto x86_l_f4f;
	case 3925ULL: goto x86_l_f55;
	case 3931ULL: goto x86_l_f5b;
	case 3936ULL: goto x86_l_f60;
	case 3940ULL: goto x86_l_f64;
	case 3943ULL: goto x86_l_f67;
	case 3947ULL: goto x86_l_f6b;
	case 3953ULL: goto x86_l_f71;
	case 3957ULL: goto x86_l_f75;
	case 3963ULL: goto x86_l_f7b;
	case 3969ULL: goto x86_l_f81;
	case 3974ULL: goto x86_l_f86;
	case 3978ULL: goto x86_l_f8a;
	case 3981ULL: goto x86_l_f8d;
	case 3985ULL: goto x86_l_f91;
	case 3991ULL: goto x86_l_f97;
	case 3995ULL: goto x86_l_f9b;
	case 4001ULL: goto x86_l_fa1;
	case 4007ULL: goto x86_l_fa7;
	case 4012ULL: goto x86_l_fac;
	case 4016ULL: goto x86_l_fb0;
	case 4019ULL: goto x86_l_fb3;
	case 4023ULL: goto x86_l_fb7;
	case 4029ULL: goto x86_l_fbd;
	case 4033ULL: goto x86_l_fc1;
	case 4039ULL: goto x86_l_fc7;
	case 4045ULL: goto x86_l_fcd;
	case 4050ULL: goto x86_l_fd2;
	case 4054ULL: goto x86_l_fd6;
	case 4057ULL: goto x86_l_fd9;
	case 4061ULL: goto x86_l_fdd;
	case 4067ULL: goto x86_l_fe3;
	case 4071ULL: goto x86_l_fe7;
	case 4077ULL: goto x86_l_fed;
	case 4083ULL: goto x86_l_ff3;
	case 4088ULL: goto x86_l_ff8;
	case 4092ULL: goto x86_l_ffc;
	case 4095ULL: goto x86_l_fff;
	case 4099ULL: goto x86_l_1003;
	case 4105ULL: goto x86_l_1009;
	case 4109ULL: goto x86_l_100d;
	case 4115ULL: goto x86_l_1013;
	case 4121ULL: goto x86_l_1019;
	case 4126ULL: goto x86_l_101e;
	case 4130ULL: goto x86_l_1022;
	case 4133ULL: goto x86_l_1025;
	case 4137ULL: goto x86_l_1029;
	case 4143ULL: goto x86_l_102f;
	case 4147ULL: goto x86_l_1033;
	case 4153ULL: goto x86_l_1039;
	case 4159ULL: goto x86_l_103f;
	case 4164ULL: goto x86_l_1044;
	case 4168ULL: goto x86_l_1048;
	case 4171ULL: goto x86_l_104b;
	case 4175ULL: goto x86_l_104f;
	case 4181ULL: goto x86_l_1055;
	case 4185ULL: goto x86_l_1059;
	case 4191ULL: goto x86_l_105f;
	case 4197ULL: goto x86_l_1065;
	case 4202ULL: goto x86_l_106a;
	case 4206ULL: goto x86_l_106e;
	case 4209ULL: goto x86_l_1071;
	case 4213ULL: goto x86_l_1075;
	case 4219ULL: goto x86_l_107b;
	case 4223ULL: goto x86_l_107f;
	case 4229ULL: goto x86_l_1085;
	case 4235ULL: goto x86_l_108b;
	case 4240ULL: goto x86_l_1090;
	case 4244ULL: goto x86_l_1094;
	case 4247ULL: goto x86_l_1097;
	case 4251ULL: goto x86_l_109b;
	case 4257ULL: goto x86_l_10a1;
	case 4261ULL: goto x86_l_10a5;
	case 4267ULL: goto x86_l_10ab;
	case 4273ULL: goto x86_l_10b1;
	case 4278ULL: goto x86_l_10b6;
	case 4282ULL: goto x86_l_10ba;
	case 4285ULL: goto x86_l_10bd;
	case 4289ULL: goto x86_l_10c1;
	case 4295ULL: goto x86_l_10c7;
	case 4299ULL: goto x86_l_10cb;
	case 4305ULL: goto x86_l_10d1;
	case 4311ULL: goto x86_l_10d7;
	case 4316ULL: goto x86_l_10dc;
	case 4320ULL: goto x86_l_10e0;
	case 4323ULL: goto x86_l_10e3;
	case 4327ULL: goto x86_l_10e7;
	case 4333ULL: goto x86_l_10ed;
	case 4337ULL: goto x86_l_10f1;
	case 4343ULL: goto x86_l_10f7;
	case 4349ULL: goto x86_l_10fd;
	case 4354ULL: goto x86_l_1102;
	case 4358ULL: goto x86_l_1106;
	case 4361ULL: goto x86_l_1109;
	case 4365ULL: goto x86_l_110d;
	case 4371ULL: goto x86_l_1113;
	case 4375ULL: goto x86_l_1117;
	case 4381ULL: goto x86_l_111d;
	case 4387ULL: goto x86_l_1123;
	case 4392ULL: goto x86_l_1128;
	case 4396ULL: goto x86_l_112c;
	case 4399ULL: goto x86_l_112f;
	case 4403ULL: goto x86_l_1133;
	case 4409ULL: goto x86_l_1139;
	case 4413ULL: goto x86_l_113d;
	case 4419ULL: goto x86_l_1143;
	case 4425ULL: goto x86_l_1149;
	case 4430ULL: goto x86_l_114e;
	case 4434ULL: goto x86_l_1152;
	case 4437ULL: goto x86_l_1155;
	case 4441ULL: goto x86_l_1159;
	case 4447ULL: goto x86_l_115f;
	case 4451ULL: goto x86_l_1163;
	case 4457ULL: goto x86_l_1169;
	case 4463ULL: goto x86_l_116f;
	case 4468ULL: goto x86_l_1174;
	case 4472ULL: goto x86_l_1178;
	case 4475ULL: goto x86_l_117b;
	case 4479ULL: goto x86_l_117f;
	case 4485ULL: goto x86_l_1185;
	case 4489ULL: goto x86_l_1189;
	case 4495ULL: goto x86_l_118f;
	case 4501ULL: goto x86_l_1195;
	case 4506ULL: goto x86_l_119a;
	case 4510ULL: goto x86_l_119e;
	case 4513ULL: goto x86_l_11a1;
	case 4517ULL: goto x86_l_11a5;
	case 4523ULL: goto x86_l_11ab;
	case 4527ULL: goto x86_l_11af;
	case 4533ULL: goto x86_l_11b5;
	case 4539ULL: goto x86_l_11bb;
	case 4544ULL: goto x86_l_11c0;
	case 4548ULL: goto x86_l_11c4;
	case 4551ULL: goto x86_l_11c7;
	case 4555ULL: goto x86_l_11cb;
	case 4561ULL: goto x86_l_11d1;
	case 4565ULL: goto x86_l_11d5;
	case 4571ULL: goto x86_l_11db;
	case 4577ULL: goto x86_l_11e1;
	case 4582ULL: goto x86_l_11e6;
	case 4586ULL: goto x86_l_11ea;
	case 4589ULL: goto x86_l_11ed;
	case 4593ULL: goto x86_l_11f1;
	case 4599ULL: goto x86_l_11f7;
	case 4603ULL: goto x86_l_11fb;
	case 4609ULL: goto x86_l_1201;
	case 4615ULL: goto x86_l_1207;
	case 4620ULL: goto x86_l_120c;
	case 4624ULL: goto x86_l_1210;
	case 4627ULL: goto x86_l_1213;
	case 4631ULL: goto x86_l_1217;
	case 4637ULL: goto x86_l_121d;
	case 4641ULL: goto x86_l_1221;
	case 4647ULL: goto x86_l_1227;
	case 4653ULL: goto x86_l_122d;
	case 4658ULL: goto x86_l_1232;
	case 4662ULL: goto x86_l_1236;
	case 4665ULL: goto x86_l_1239;
	case 4669ULL: goto x86_l_123d;
	case 4675ULL: goto x86_l_1243;
	case 4679ULL: goto x86_l_1247;
	case 4685ULL: goto x86_l_124d;
	case 4691ULL: goto x86_l_1253;
	case 4696ULL: goto x86_l_1258;
	case 4700ULL: goto x86_l_125c;
	case 4703ULL: goto x86_l_125f;
	case 4707ULL: goto x86_l_1263;
	case 4713ULL: goto x86_l_1269;
	case 4717ULL: goto x86_l_126d;
	case 4723ULL: goto x86_l_1273;
	case 4729ULL: goto x86_l_1279;
	case 4734ULL: goto x86_l_127e;
	case 4738ULL: goto x86_l_1282;
	case 4741ULL: goto x86_l_1285;
	case 4745ULL: goto x86_l_1289;
	case 4751ULL: goto x86_l_128f;
	case 4755ULL: goto x86_l_1293;
	case 4761ULL: goto x86_l_1299;
	case 4767ULL: goto x86_l_129f;
	case 4772ULL: goto x86_l_12a4;
	case 4776ULL: goto x86_l_12a8;
	case 4779ULL: goto x86_l_12ab;
	case 4783ULL: goto x86_l_12af;
	case 4789ULL: goto x86_l_12b5;
	case 4793ULL: goto x86_l_12b9;
	case 4799ULL: goto x86_l_12bf;
	case 4805ULL: goto x86_l_12c5;
	case 4810ULL: goto x86_l_12ca;
	case 4814ULL: goto x86_l_12ce;
	case 4817ULL: goto x86_l_12d1;
	case 4821ULL: goto x86_l_12d5;
	case 4827ULL: goto x86_l_12db;
	case 4831ULL: goto x86_l_12df;
	case 4837ULL: goto x86_l_12e5;
	case 4843ULL: goto x86_l_12eb;
	case 4848ULL: goto x86_l_12f0;
	case 4852ULL: goto x86_l_12f4;
	case 4855ULL: goto x86_l_12f7;
	case 4859ULL: goto x86_l_12fb;
	case 4865ULL: goto x86_l_1301;
	case 4869ULL: goto x86_l_1305;
	case 4875ULL: goto x86_l_130b;
	case 4881ULL: goto x86_l_1311;
	case 4886ULL: goto x86_l_1316;
	case 4890ULL: goto x86_l_131a;
	case 4893ULL: goto x86_l_131d;
	case 4897ULL: goto x86_l_1321;
	case 4903ULL: goto x86_l_1327;
	case 4907ULL: goto x86_l_132b;
	case 4913ULL: goto x86_l_1331;
	case 4919ULL: goto x86_l_1337;
	case 4924ULL: goto x86_l_133c;
	case 4928ULL: goto x86_l_1340;
	case 4931ULL: goto x86_l_1343;
	case 4935ULL: goto x86_l_1347;
	case 4941ULL: goto x86_l_134d;
	case 4945ULL: goto x86_l_1351;
	case 4951ULL: goto x86_l_1357;
	case 4957ULL: goto x86_l_135d;
	case 4962ULL: goto x86_l_1362;
	case 4966ULL: goto x86_l_1366;
	case 4969ULL: goto x86_l_1369;
	case 4973ULL: goto x86_l_136d;
	case 4979ULL: goto x86_l_1373;
	case 4983ULL: goto x86_l_1377;
	case 4989ULL: goto x86_l_137d;
	case 4995ULL: goto x86_l_1383;
	case 5000ULL: goto x86_l_1388;
	case 5004ULL: goto x86_l_138c;
	case 5007ULL: goto x86_l_138f;
	case 5011ULL: goto x86_l_1393;
	case 5017ULL: goto x86_l_1399;
	case 5021ULL: goto x86_l_139d;
	case 5027ULL: goto x86_l_13a3;
	case 5033ULL: goto x86_l_13a9;
	case 5038ULL: goto x86_l_13ae;
	case 5042ULL: goto x86_l_13b2;
	case 5045ULL: goto x86_l_13b5;
	case 5049ULL: goto x86_l_13b9;
	case 5055ULL: goto x86_l_13bf;
	case 5059ULL: goto x86_l_13c3;
	case 5065ULL: goto x86_l_13c9;
	case 5071ULL: goto x86_l_13cf;
	case 5076ULL: goto x86_l_13d4;
	case 5080ULL: goto x86_l_13d8;
	case 5083ULL: goto x86_l_13db;
	case 5087ULL: goto x86_l_13df;
	case 5093ULL: goto x86_l_13e5;
	case 5097ULL: goto x86_l_13e9;
	case 5103ULL: goto x86_l_13ef;
	case 5109ULL: goto x86_l_13f5;
	case 5114ULL: goto x86_l_13fa;
	case 5118ULL: goto x86_l_13fe;
	case 5121ULL: goto x86_l_1401;
	case 5125ULL: goto x86_l_1405;
	case 5131ULL: goto x86_l_140b;
	case 5135ULL: goto x86_l_140f;
	case 5141ULL: goto x86_l_1415;
	case 5147ULL: goto x86_l_141b;
	case 5152ULL: goto x86_l_1420;
	case 5156ULL: goto x86_l_1424;
	case 5159ULL: goto x86_l_1427;
	case 5163ULL: goto x86_l_142b;
	case 5169ULL: goto x86_l_1431;
	case 5173ULL: goto x86_l_1435;
	case 5179ULL: goto x86_l_143b;
	case 5185ULL: goto x86_l_1441;
	case 5190ULL: goto x86_l_1446;
	case 5194ULL: goto x86_l_144a;
	case 5197ULL: goto x86_l_144d;
	case 5201ULL: goto x86_l_1451;
	case 5207ULL: goto x86_l_1457;
	case 5211ULL: goto x86_l_145b;
	case 5217ULL: goto x86_l_1461;
	case 5223ULL: goto x86_l_1467;
	case 5228ULL: goto x86_l_146c;
	case 5232ULL: goto x86_l_1470;
	case 5235ULL: goto x86_l_1473;
	case 5239ULL: goto x86_l_1477;
	case 5245ULL: goto x86_l_147d;
	case 5249ULL: goto x86_l_1481;
	case 5255ULL: goto x86_l_1487;
	case 5261ULL: goto x86_l_148d;
	case 5266ULL: goto x86_l_1492;
	case 5270ULL: goto x86_l_1496;
	case 5273ULL: goto x86_l_1499;
	case 5277ULL: goto x86_l_149d;
	case 5283ULL: goto x86_l_14a3;
	case 5287ULL: goto x86_l_14a7;
	case 5293ULL: goto x86_l_14ad;
	case 5299ULL: goto x86_l_14b3;
	case 5304ULL: goto x86_l_14b8;
	case 5308ULL: goto x86_l_14bc;
	case 5311ULL: goto x86_l_14bf;
	case 5315ULL: goto x86_l_14c3;
	case 5321ULL: goto x86_l_14c9;
	case 5325ULL: goto x86_l_14cd;
	case 5331ULL: goto x86_l_14d3;
	case 5337ULL: goto x86_l_14d9;
	case 5342ULL: goto x86_l_14de;
	case 5346ULL: goto x86_l_14e2;
	case 5349ULL: goto x86_l_14e5;
	case 5353ULL: goto x86_l_14e9;
	case 5359ULL: goto x86_l_14ef;
	case 5363ULL: goto x86_l_14f3;
	case 5369ULL: goto x86_l_14f9;
	case 5375ULL: goto x86_l_14ff;
	case 5380ULL: goto x86_l_1504;
	case 5384ULL: goto x86_l_1508;
	case 5387ULL: goto x86_l_150b;
	case 5391ULL: goto x86_l_150f;
	case 5397ULL: goto x86_l_1515;
	case 5401ULL: goto x86_l_1519;
	case 5407ULL: goto x86_l_151f;
	case 5413ULL: goto x86_l_1525;
	case 5418ULL: goto x86_l_152a;
	case 5422ULL: goto x86_l_152e;
	case 5425ULL: goto x86_l_1531;
	case 5429ULL: goto x86_l_1535;
	case 5435ULL: goto x86_l_153b;
	case 5439ULL: goto x86_l_153f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e25:
	/* 0xe25: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_e2b:
	/* 0xe2b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e30:
	/* 0xe30: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_e34:
	/* 0xe34: mov    BYTE PTR [rax+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_e37:
	/* 0xe37: cmp    rsi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 2ULL);
x86_l_e3b:
	/* 0xe3b: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_e41:
	/* 0xe41: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e45:
	/* 0xe45: lea    ecx,[rsi+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_e4b:
	/* 0xe4b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_e51:
	/* 0xe51: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e56:
	/* 0xe56: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_e5a:
	/* 0xe5a: mov    BYTE PTR [rax+0x6],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_e5d:
	/* 0xe5d: cmp    rsi,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 3ULL);
x86_l_e61:
	/* 0xe61: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_e67:
	/* 0xe67: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e6b:
	/* 0xe6b: lea    ecx,[rsi+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_e71:
	/* 0xe71: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_e77:
	/* 0xe77: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e7c:
	/* 0xe7c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_e80:
	/* 0xe80: mov    BYTE PTR [rax+0x7],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_e83:
	/* 0xe83: cmp    rsi,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 4ULL);
x86_l_e87:
	/* 0xe87: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_e8d:
	/* 0xe8d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e91:
	/* 0xe91: lea    ecx,[rsi+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_e97:
	/* 0xe97: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_e9d:
	/* 0xe9d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ea2:
	/* 0xea2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_ea6:
	/* 0xea6: mov    BYTE PTR [rax+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ea9:
	/* 0xea9: cmp    rsi,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 5ULL);
x86_l_ead:
	/* 0xead: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_eb3:
	/* 0xeb3: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eb7:
	/* 0xeb7: lea    ecx,[rsi+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_ebd:
	/* 0xebd: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ec3:
	/* 0xec3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ec8:
	/* 0xec8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_ecc:
	/* 0xecc: mov    BYTE PTR [rax+0x9],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_ecf:
	/* 0xecf: cmp    rsi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 6ULL);
x86_l_ed3:
	/* 0xed3: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_ed9:
	/* 0xed9: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_edd:
	/* 0xedd: lea    ecx,[rsi+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_ee3:
	/* 0xee3: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ee9:
	/* 0xee9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eee:
	/* 0xeee: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_ef2:
	/* 0xef2: mov    BYTE PTR [rax+0xa],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_ef5:
	/* 0xef5: cmp    rsi,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 7ULL);
x86_l_ef9:
	/* 0xef9: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_eff:
	/* 0xeff: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f03:
	/* 0xf03: lea    ecx,[rsi+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_f09:
	/* 0xf09: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f0f:
	/* 0xf0f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f14:
	/* 0xf14: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_f18:
	/* 0xf18: mov    BYTE PTR [rax+0xb],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_f1b:
	/* 0xf1b: cmp    rsi,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 8ULL);
x86_l_f1f:
	/* 0xf1f: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_f25:
	/* 0xf25: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f29:
	/* 0xf29: lea    ecx,[rsi+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_f2f:
	/* 0xf2f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f35:
	/* 0xf35: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f3a:
	/* 0xf3a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_f3e:
	/* 0xf3e: mov    BYTE PTR [rax+0xc],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f41:
	/* 0xf41: cmp    rsi,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 9ULL);
x86_l_f45:
	/* 0xf45: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_f4b:
	/* 0xf4b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f4f:
	/* 0xf4f: lea    ecx,[rsi+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_f55:
	/* 0xf55: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f5b:
	/* 0xf5b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f60:
	/* 0xf60: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_f64:
	/* 0xf64: mov    BYTE PTR [rax+0xd],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_f67:
	/* 0xf67: cmp    rsi,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 10ULL);
x86_l_f6b:
	/* 0xf6b: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_f71:
	/* 0xf71: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f75:
	/* 0xf75: lea    ecx,[rsi+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_f7b:
	/* 0xf7b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f81:
	/* 0xf81: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f86:
	/* 0xf86: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_f8a:
	/* 0xf8a: mov    BYTE PTR [rax+0xe],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_f8d:
	/* 0xf8d: cmp    rsi,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 11ULL);
x86_l_f91:
	/* 0xf91: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_f97:
	/* 0xf97: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f9b:
	/* 0xf9b: lea    ecx,[rsi+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_fa1:
	/* 0xfa1: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fa7:
	/* 0xfa7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fac:
	/* 0xfac: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_fb0:
	/* 0xfb0: mov    BYTE PTR [rax+0xf],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_fb3:
	/* 0xfb3: cmp    rsi,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 12ULL);
x86_l_fb7:
	/* 0xfb7: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_fbd:
	/* 0xfbd: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fc1:
	/* 0xfc1: lea    ecx,[rsi+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_fc7:
	/* 0xfc7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fcd:
	/* 0xfcd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fd2:
	/* 0xfd2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_fd6:
	/* 0xfd6: mov    BYTE PTR [rax+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fd9:
	/* 0xfd9: cmp    rsi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 13ULL);
x86_l_fdd:
	/* 0xfdd: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_fe3:
	/* 0xfe3: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fe7:
	/* 0xfe7: lea    ecx,[rsi+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_fed:
	/* 0xfed: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ff3:
	/* 0xff3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ff8:
	/* 0xff8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_ffc:
	/* 0xffc: mov    BYTE PTR [rax+0x11],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_fff:
	/* 0xfff: cmp    rsi,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 14ULL);
x86_l_1003:
	/* 0x1003: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_1009:
	/* 0x1009: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_100d:
	/* 0x100d: lea    ecx,[rsi+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_1013:
	/* 0x1013: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1019:
	/* 0x1019: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_101e:
	/* 0x101e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1022:
	/* 0x1022: mov    BYTE PTR [rax+0x12],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1025:
	/* 0x1025: cmp    rsi,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 15ULL);
x86_l_1029:
	/* 0x1029: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_102f:
	/* 0x102f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1033:
	/* 0x1033: lea    ecx,[rsi+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_1039:
	/* 0x1039: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_103f:
	/* 0x103f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1044:
	/* 0x1044: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1048:
	/* 0x1048: mov    BYTE PTR [rax+0x13],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_104b:
	/* 0x104b: cmp    rsi,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 16ULL);
x86_l_104f:
	/* 0x104f: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_1055:
	/* 0x1055: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1059:
	/* 0x1059: lea    ecx,[rsi+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_105f:
	/* 0x105f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1065:
	/* 0x1065: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_106a:
	/* 0x106a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_106e:
	/* 0x106e: mov    BYTE PTR [rax+0x14],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1071:
	/* 0x1071: cmp    rsi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 17ULL);
x86_l_1075:
	/* 0x1075: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_107b:
	/* 0x107b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_107f:
	/* 0x107f: lea    ecx,[rsi+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_1085:
	/* 0x1085: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_108b:
	/* 0x108b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1090:
	/* 0x1090: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1094:
	/* 0x1094: mov    BYTE PTR [rax+0x15],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_1097:
	/* 0x1097: cmp    rsi,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18ULL);
x86_l_109b:
	/* 0x109b: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_10a1:
	/* 0x10a1: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10a5:
	/* 0x10a5: lea    ecx,[rsi+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_10ab:
	/* 0x10ab: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10b1:
	/* 0x10b1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10b6:
	/* 0x10b6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_10ba:
	/* 0x10ba: mov    BYTE PTR [rax+0x16],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_10bd:
	/* 0x10bd: cmp    rsi,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 19ULL);
x86_l_10c1:
	/* 0x10c1: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_10c7:
	/* 0x10c7: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10cb:
	/* 0x10cb: lea    ecx,[rsi+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_10d1:
	/* 0x10d1: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10d7:
	/* 0x10d7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10dc:
	/* 0x10dc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_10e0:
	/* 0x10e0: mov    BYTE PTR [rax+0x17],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_10e3:
	/* 0x10e3: cmp    rsi,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 20ULL);
x86_l_10e7:
	/* 0x10e7: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_10ed:
	/* 0x10ed: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10f1:
	/* 0x10f1: lea    ecx,[rsi+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_10f7:
	/* 0x10f7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10fd:
	/* 0x10fd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1102:
	/* 0x1102: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1106:
	/* 0x1106: mov    BYTE PTR [rax+0x18],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1109:
	/* 0x1109: cmp    rsi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 21ULL);
x86_l_110d:
	/* 0x110d: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_1113:
	/* 0x1113: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1117:
	/* 0x1117: lea    ecx,[rsi+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_111d:
	/* 0x111d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1123:
	/* 0x1123: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1128:
	/* 0x1128: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_112c:
	/* 0x112c: mov    BYTE PTR [rax+0x19],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_112f:
	/* 0x112f: cmp    rsi,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 22ULL);
x86_l_1133:
	/* 0x1133: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_1139:
	/* 0x1139: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_113d:
	/* 0x113d: lea    ecx,[rsi+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_1143:
	/* 0x1143: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1149:
	/* 0x1149: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_114e:
	/* 0x114e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1152:
	/* 0x1152: mov    BYTE PTR [rax+0x1a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_1155:
	/* 0x1155: cmp    rsi,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 23ULL);
x86_l_1159:
	/* 0x1159: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_115f:
	/* 0x115f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1163:
	/* 0x1163: lea    ecx,[rsi+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_1169:
	/* 0x1169: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_116f:
	/* 0x116f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1174:
	/* 0x1174: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1178:
	/* 0x1178: mov    BYTE PTR [rax+0x1b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_117b:
	/* 0x117b: cmp    rsi,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 24ULL);
x86_l_117f:
	/* 0x117f: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_1185:
	/* 0x1185: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1189:
	/* 0x1189: lea    ecx,[rsi+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_118f:
	/* 0x118f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1195:
	/* 0x1195: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_119a:
	/* 0x119a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_119e:
	/* 0x119e: mov    BYTE PTR [rax+0x1c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_11a1:
	/* 0x11a1: cmp    rsi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 25ULL);
x86_l_11a5:
	/* 0x11a5: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_11ab:
	/* 0x11ab: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11af:
	/* 0x11af: lea    ecx,[rsi+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_11b5:
	/* 0x11b5: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11bb:
	/* 0x11bb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11c0:
	/* 0x11c0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_11c4:
	/* 0x11c4: mov    BYTE PTR [rax+0x1d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_11c7:
	/* 0x11c7: cmp    rsi,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 26ULL);
x86_l_11cb:
	/* 0x11cb: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_11d1:
	/* 0x11d1: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11d5:
	/* 0x11d5: lea    ecx,[rsi+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_11db:
	/* 0x11db: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11e1:
	/* 0x11e1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11e6:
	/* 0x11e6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_11ea:
	/* 0x11ea: mov    BYTE PTR [rax+0x1e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_11ed:
	/* 0x11ed: cmp    rsi,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 27ULL);
x86_l_11f1:
	/* 0x11f1: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_11f7:
	/* 0x11f7: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11fb:
	/* 0x11fb: lea    ecx,[rsi+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_1201:
	/* 0x1201: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1207:
	/* 0x1207: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_120c:
	/* 0x120c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1210:
	/* 0x1210: mov    BYTE PTR [rax+0x1f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_1213:
	/* 0x1213: cmp    rsi,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 28ULL);
x86_l_1217:
	/* 0x1217: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_121d:
	/* 0x121d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1221:
	/* 0x1221: lea    ecx,[rsi+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_1227:
	/* 0x1227: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_122d:
	/* 0x122d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1232:
	/* 0x1232: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1236:
	/* 0x1236: mov    BYTE PTR [rax+0x20],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1239:
	/* 0x1239: cmp    rsi,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 29ULL);
x86_l_123d:
	/* 0x123d: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_1243:
	/* 0x1243: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1247:
	/* 0x1247: lea    ecx,[rsi+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_124d:
	/* 0x124d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1253:
	/* 0x1253: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1258:
	/* 0x1258: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_125c:
	/* 0x125c: mov    BYTE PTR [rax+0x21],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_125f:
	/* 0x125f: cmp    rsi,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 30ULL);
x86_l_1263:
	/* 0x1263: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_1269:
	/* 0x1269: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_126d:
	/* 0x126d: lea    ecx,[rsi+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_1273:
	/* 0x1273: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1279:
	/* 0x1279: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_127e:
	/* 0x127e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1282:
	/* 0x1282: mov    BYTE PTR [rax+0x22],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_1285:
	/* 0x1285: cmp    rsi,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 31ULL);
x86_l_1289:
	/* 0x1289: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_128f:
	/* 0x128f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1293:
	/* 0x1293: lea    ecx,[rsi+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_1299:
	/* 0x1299: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_129f:
	/* 0x129f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12a4:
	/* 0x12a4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_12a8:
	/* 0x12a8: mov    BYTE PTR [rax+0x23],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_12ab:
	/* 0x12ab: cmp    rsi,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 32ULL);
x86_l_12af:
	/* 0x12af: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_12b5:
	/* 0x12b5: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12b9:
	/* 0x12b9: lea    ecx,[rsi+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_12bf:
	/* 0x12bf: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12c5:
	/* 0x12c5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12ca:
	/* 0x12ca: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_12ce:
	/* 0x12ce: mov    BYTE PTR [rax+0x24],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_12d1:
	/* 0x12d1: cmp    rsi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 33ULL);
x86_l_12d5:
	/* 0x12d5: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_12db:
	/* 0x12db: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12df:
	/* 0x12df: lea    ecx,[rsi+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_12e5:
	/* 0x12e5: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12eb:
	/* 0x12eb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12f0:
	/* 0x12f0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_12f4:
	/* 0x12f4: mov    BYTE PTR [rax+0x25],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_12f7:
	/* 0x12f7: cmp    rsi,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 34ULL);
x86_l_12fb:
	/* 0x12fb: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_1301:
	/* 0x1301: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1305:
	/* 0x1305: lea    ecx,[rsi+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_130b:
	/* 0x130b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1311:
	/* 0x1311: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1316:
	/* 0x1316: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_131a:
	/* 0x131a: mov    BYTE PTR [rax+0x26],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_131d:
	/* 0x131d: cmp    rsi,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 35ULL);
x86_l_1321:
	/* 0x1321: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_1327:
	/* 0x1327: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_132b:
	/* 0x132b: lea    ecx,[rsi+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_1331:
	/* 0x1331: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1337:
	/* 0x1337: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_133c:
	/* 0x133c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1340:
	/* 0x1340: mov    BYTE PTR [rax+0x27],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_1343:
	/* 0x1343: cmp    rsi,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 36ULL);
x86_l_1347:
	/* 0x1347: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_134d:
	/* 0x134d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1351:
	/* 0x1351: lea    ecx,[rsi+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_1357:
	/* 0x1357: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_135d:
	/* 0x135d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1362:
	/* 0x1362: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1366:
	/* 0x1366: mov    BYTE PTR [rax+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1369:
	/* 0x1369: cmp    rsi,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 37ULL);
x86_l_136d:
	/* 0x136d: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_1373:
	/* 0x1373: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1377:
	/* 0x1377: lea    ecx,[rsi+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_137d:
	/* 0x137d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1383:
	/* 0x1383: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1388:
	/* 0x1388: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_138c:
	/* 0x138c: mov    BYTE PTR [rax+0x29],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_138f:
	/* 0x138f: cmp    rsi,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 38ULL);
x86_l_1393:
	/* 0x1393: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_1399:
	/* 0x1399: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_139d:
	/* 0x139d: lea    ecx,[rsi+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_13a3:
	/* 0x13a3: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13a9:
	/* 0x13a9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13ae:
	/* 0x13ae: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_13b2:
	/* 0x13b2: mov    BYTE PTR [rax+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_13b5:
	/* 0x13b5: cmp    rsi,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 39ULL);
x86_l_13b9:
	/* 0x13b9: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_13bf:
	/* 0x13bf: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13c3:
	/* 0x13c3: lea    ecx,[rsi+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_13c9:
	/* 0x13c9: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13cf:
	/* 0x13cf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13d4:
	/* 0x13d4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_13d8:
	/* 0x13d8: mov    BYTE PTR [rax+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_13db:
	/* 0x13db: cmp    rsi,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 40ULL);
x86_l_13df:
	/* 0x13df: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_13e5:
	/* 0x13e5: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13e9:
	/* 0x13e9: lea    ecx,[rsi+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_13ef:
	/* 0x13ef: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13f5:
	/* 0x13f5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13fa:
	/* 0x13fa: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_13fe:
	/* 0x13fe: mov    BYTE PTR [rax+0x2c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1401:
	/* 0x1401: cmp    rsi,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 41ULL);
x86_l_1405:
	/* 0x1405: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_140b:
	/* 0x140b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_140f:
	/* 0x140f: lea    ecx,[rsi+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_1415:
	/* 0x1415: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_141b:
	/* 0x141b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1420:
	/* 0x1420: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1424:
	/* 0x1424: mov    BYTE PTR [rax+0x2d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_1427:
	/* 0x1427: cmp    rsi,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 42ULL);
x86_l_142b:
	/* 0x142b: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_1431:
	/* 0x1431: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1435:
	/* 0x1435: lea    ecx,[rsi+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_143b:
	/* 0x143b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1441:
	/* 0x1441: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1446:
	/* 0x1446: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_144a:
	/* 0x144a: mov    BYTE PTR [rax+0x2e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_144d:
	/* 0x144d: cmp    rsi,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 43ULL);
x86_l_1451:
	/* 0x1451: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_1457:
	/* 0x1457: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_145b:
	/* 0x145b: lea    ecx,[rsi+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_1461:
	/* 0x1461: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1467:
	/* 0x1467: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_146c:
	/* 0x146c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1470:
	/* 0x1470: mov    BYTE PTR [rax+0x2f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_1473:
	/* 0x1473: cmp    rsi,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 44ULL);
x86_l_1477:
	/* 0x1477: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_147d:
	/* 0x147d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1481:
	/* 0x1481: lea    ecx,[rsi+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_1487:
	/* 0x1487: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_148d:
	/* 0x148d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1492:
	/* 0x1492: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1496:
	/* 0x1496: mov    BYTE PTR [rax+0x30],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1499:
	/* 0x1499: cmp    rsi,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 45ULL);
x86_l_149d:
	/* 0x149d: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_14a3:
	/* 0x14a3: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14a7:
	/* 0x14a7: lea    ecx,[rsi+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_14ad:
	/* 0x14ad: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14b3:
	/* 0x14b3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14b8:
	/* 0x14b8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_14bc:
	/* 0x14bc: mov    BYTE PTR [rax+0x31],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_14bf:
	/* 0x14bf: cmp    rsi,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 46ULL);
x86_l_14c3:
	/* 0x14c3: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_14c9:
	/* 0x14c9: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14cd:
	/* 0x14cd: lea    ecx,[rsi+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_14d3:
	/* 0x14d3: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14d9:
	/* 0x14d9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14de:
	/* 0x14de: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_14e2:
	/* 0x14e2: mov    BYTE PTR [rax+0x32],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_14e5:
	/* 0x14e5: cmp    rsi,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 47ULL);
x86_l_14e9:
	/* 0x14e9: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_14ef:
	/* 0x14ef: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14f3:
	/* 0x14f3: lea    ecx,[rsi+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_14f9:
	/* 0x14f9: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14ff:
	/* 0x14ff: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1504:
	/* 0x1504: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1508:
	/* 0x1508: mov    BYTE PTR [rax+0x33],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_150b:
	/* 0x150b: cmp    rsi,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 48ULL);
x86_l_150f:
	/* 0x150f: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_1515:
	/* 0x1515: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1519:
	/* 0x1519: lea    ecx,[rsi+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_151f:
	/* 0x151f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1525:
	/* 0x1525: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_152a:
	/* 0x152a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_152e:
	/* 0x152e: mov    BYTE PTR [rax+0x34],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1531:
	/* 0x1531: cmp    rsi,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 49ULL);
x86_l_1535:
	/* 0x1535: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7123ULL;
	}
x86_l_153b:
	/* 0x153b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_153f:
	/* 0x153f: lea    ecx,[rsi+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
	return 5445ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5445ULL: goto x86_l_1545;
	case 5451ULL: goto x86_l_154b;
	case 5456ULL: goto x86_l_1550;
	case 5460ULL: goto x86_l_1554;
	case 5463ULL: goto x86_l_1557;
	case 5467ULL: goto x86_l_155b;
	case 5473ULL: goto x86_l_1561;
	case 5477ULL: goto x86_l_1565;
	case 5483ULL: goto x86_l_156b;
	case 5489ULL: goto x86_l_1571;
	case 5494ULL: goto x86_l_1576;
	case 5498ULL: goto x86_l_157a;
	case 5501ULL: goto x86_l_157d;
	case 5505ULL: goto x86_l_1581;
	case 5511ULL: goto x86_l_1587;
	case 5515ULL: goto x86_l_158b;
	case 5521ULL: goto x86_l_1591;
	case 5527ULL: goto x86_l_1597;
	case 5532ULL: goto x86_l_159c;
	case 5536ULL: goto x86_l_15a0;
	case 5539ULL: goto x86_l_15a3;
	case 5543ULL: goto x86_l_15a7;
	case 5549ULL: goto x86_l_15ad;
	case 5553ULL: goto x86_l_15b1;
	case 5559ULL: goto x86_l_15b7;
	case 5565ULL: goto x86_l_15bd;
	case 5570ULL: goto x86_l_15c2;
	case 5574ULL: goto x86_l_15c6;
	case 5577ULL: goto x86_l_15c9;
	case 5581ULL: goto x86_l_15cd;
	case 5587ULL: goto x86_l_15d3;
	case 5591ULL: goto x86_l_15d7;
	case 5597ULL: goto x86_l_15dd;
	case 5603ULL: goto x86_l_15e3;
	case 5608ULL: goto x86_l_15e8;
	case 5612ULL: goto x86_l_15ec;
	case 5615ULL: goto x86_l_15ef;
	case 5619ULL: goto x86_l_15f3;
	case 5625ULL: goto x86_l_15f9;
	case 5629ULL: goto x86_l_15fd;
	case 5635ULL: goto x86_l_1603;
	case 5641ULL: goto x86_l_1609;
	case 5646ULL: goto x86_l_160e;
	case 5650ULL: goto x86_l_1612;
	case 5653ULL: goto x86_l_1615;
	case 5657ULL: goto x86_l_1619;
	case 5663ULL: goto x86_l_161f;
	case 5667ULL: goto x86_l_1623;
	case 5673ULL: goto x86_l_1629;
	case 5679ULL: goto x86_l_162f;
	case 5684ULL: goto x86_l_1634;
	case 5688ULL: goto x86_l_1638;
	case 5691ULL: goto x86_l_163b;
	case 5695ULL: goto x86_l_163f;
	case 5701ULL: goto x86_l_1645;
	case 5705ULL: goto x86_l_1649;
	case 5711ULL: goto x86_l_164f;
	case 5717ULL: goto x86_l_1655;
	case 5722ULL: goto x86_l_165a;
	case 5726ULL: goto x86_l_165e;
	case 5729ULL: goto x86_l_1661;
	case 5733ULL: goto x86_l_1665;
	case 5739ULL: goto x86_l_166b;
	case 5743ULL: goto x86_l_166f;
	case 5749ULL: goto x86_l_1675;
	case 5755ULL: goto x86_l_167b;
	case 5760ULL: goto x86_l_1680;
	case 5764ULL: goto x86_l_1684;
	case 5767ULL: goto x86_l_1687;
	case 5771ULL: goto x86_l_168b;
	case 5777ULL: goto x86_l_1691;
	case 5781ULL: goto x86_l_1695;
	case 5787ULL: goto x86_l_169b;
	case 5793ULL: goto x86_l_16a1;
	case 5798ULL: goto x86_l_16a6;
	case 5802ULL: goto x86_l_16aa;
	case 5805ULL: goto x86_l_16ad;
	case 5809ULL: goto x86_l_16b1;
	case 5815ULL: goto x86_l_16b7;
	case 5819ULL: goto x86_l_16bb;
	case 5825ULL: goto x86_l_16c1;
	case 5831ULL: goto x86_l_16c7;
	case 5836ULL: goto x86_l_16cc;
	case 5840ULL: goto x86_l_16d0;
	case 5843ULL: goto x86_l_16d3;
	case 5847ULL: goto x86_l_16d7;
	case 5853ULL: goto x86_l_16dd;
	case 5857ULL: goto x86_l_16e1;
	case 5863ULL: goto x86_l_16e7;
	case 5869ULL: goto x86_l_16ed;
	case 5874ULL: goto x86_l_16f2;
	case 5878ULL: goto x86_l_16f6;
	case 5881ULL: goto x86_l_16f9;
	case 5885ULL: goto x86_l_16fd;
	case 5891ULL: goto x86_l_1703;
	case 5895ULL: goto x86_l_1707;
	case 5901ULL: goto x86_l_170d;
	case 5907ULL: goto x86_l_1713;
	case 5912ULL: goto x86_l_1718;
	case 5916ULL: goto x86_l_171c;
	case 5919ULL: goto x86_l_171f;
	case 5923ULL: goto x86_l_1723;
	case 5929ULL: goto x86_l_1729;
	case 5933ULL: goto x86_l_172d;
	case 5939ULL: goto x86_l_1733;
	case 5945ULL: goto x86_l_1739;
	case 5950ULL: goto x86_l_173e;
	case 5954ULL: goto x86_l_1742;
	case 5957ULL: goto x86_l_1745;
	case 5961ULL: goto x86_l_1749;
	case 5967ULL: goto x86_l_174f;
	case 5971ULL: goto x86_l_1753;
	case 5977ULL: goto x86_l_1759;
	case 5983ULL: goto x86_l_175f;
	case 5988ULL: goto x86_l_1764;
	case 5992ULL: goto x86_l_1768;
	case 5995ULL: goto x86_l_176b;
	case 5999ULL: goto x86_l_176f;
	case 6005ULL: goto x86_l_1775;
	case 6009ULL: goto x86_l_1779;
	case 6015ULL: goto x86_l_177f;
	case 6021ULL: goto x86_l_1785;
	case 6026ULL: goto x86_l_178a;
	case 6030ULL: goto x86_l_178e;
	case 6033ULL: goto x86_l_1791;
	case 6037ULL: goto x86_l_1795;
	case 6043ULL: goto x86_l_179b;
	case 6047ULL: goto x86_l_179f;
	case 6053ULL: goto x86_l_17a5;
	case 6059ULL: goto x86_l_17ab;
	case 6064ULL: goto x86_l_17b0;
	case 6068ULL: goto x86_l_17b4;
	case 6071ULL: goto x86_l_17b7;
	case 6075ULL: goto x86_l_17bb;
	case 6081ULL: goto x86_l_17c1;
	case 6085ULL: goto x86_l_17c5;
	case 6091ULL: goto x86_l_17cb;
	case 6097ULL: goto x86_l_17d1;
	case 6102ULL: goto x86_l_17d6;
	case 6106ULL: goto x86_l_17da;
	case 6109ULL: goto x86_l_17dd;
	case 6113ULL: goto x86_l_17e1;
	case 6119ULL: goto x86_l_17e7;
	case 6123ULL: goto x86_l_17eb;
	case 6129ULL: goto x86_l_17f1;
	case 6135ULL: goto x86_l_17f7;
	case 6140ULL: goto x86_l_17fc;
	case 6144ULL: goto x86_l_1800;
	case 6147ULL: goto x86_l_1803;
	case 6151ULL: goto x86_l_1807;
	case 6157ULL: goto x86_l_180d;
	case 6161ULL: goto x86_l_1811;
	case 6167ULL: goto x86_l_1817;
	case 6173ULL: goto x86_l_181d;
	case 6178ULL: goto x86_l_1822;
	case 6182ULL: goto x86_l_1826;
	case 6185ULL: goto x86_l_1829;
	case 6189ULL: goto x86_l_182d;
	case 6195ULL: goto x86_l_1833;
	case 6199ULL: goto x86_l_1837;
	case 6205ULL: goto x86_l_183d;
	case 6211ULL: goto x86_l_1843;
	case 6216ULL: goto x86_l_1848;
	case 6220ULL: goto x86_l_184c;
	case 6223ULL: goto x86_l_184f;
	case 6227ULL: goto x86_l_1853;
	case 6233ULL: goto x86_l_1859;
	case 6237ULL: goto x86_l_185d;
	case 6243ULL: goto x86_l_1863;
	case 6249ULL: goto x86_l_1869;
	case 6254ULL: goto x86_l_186e;
	case 6258ULL: goto x86_l_1872;
	case 6261ULL: goto x86_l_1875;
	case 6265ULL: goto x86_l_1879;
	case 6271ULL: goto x86_l_187f;
	case 6275ULL: goto x86_l_1883;
	case 6281ULL: goto x86_l_1889;
	case 6287ULL: goto x86_l_188f;
	case 6292ULL: goto x86_l_1894;
	case 6296ULL: goto x86_l_1898;
	case 6299ULL: goto x86_l_189b;
	case 6303ULL: goto x86_l_189f;
	case 6309ULL: goto x86_l_18a5;
	case 6313ULL: goto x86_l_18a9;
	case 6319ULL: goto x86_l_18af;
	case 6325ULL: goto x86_l_18b5;
	case 6330ULL: goto x86_l_18ba;
	case 6334ULL: goto x86_l_18be;
	case 6337ULL: goto x86_l_18c1;
	case 6341ULL: goto x86_l_18c5;
	case 6347ULL: goto x86_l_18cb;
	case 6351ULL: goto x86_l_18cf;
	case 6357ULL: goto x86_l_18d5;
	case 6363ULL: goto x86_l_18db;
	case 6368ULL: goto x86_l_18e0;
	case 6372ULL: goto x86_l_18e4;
	case 6375ULL: goto x86_l_18e7;
	case 6379ULL: goto x86_l_18eb;
	case 6385ULL: goto x86_l_18f1;
	case 6389ULL: goto x86_l_18f5;
	case 6395ULL: goto x86_l_18fb;
	case 6401ULL: goto x86_l_1901;
	case 6406ULL: goto x86_l_1906;
	case 6410ULL: goto x86_l_190a;
	case 6413ULL: goto x86_l_190d;
	case 6417ULL: goto x86_l_1911;
	case 6423ULL: goto x86_l_1917;
	case 6427ULL: goto x86_l_191b;
	case 6433ULL: goto x86_l_1921;
	case 6439ULL: goto x86_l_1927;
	case 6444ULL: goto x86_l_192c;
	case 6448ULL: goto x86_l_1930;
	case 6451ULL: goto x86_l_1933;
	case 6455ULL: goto x86_l_1937;
	case 6461ULL: goto x86_l_193d;
	case 6465ULL: goto x86_l_1941;
	case 6471ULL: goto x86_l_1947;
	case 6477ULL: goto x86_l_194d;
	case 6482ULL: goto x86_l_1952;
	case 6486ULL: goto x86_l_1956;
	case 6489ULL: goto x86_l_1959;
	case 6493ULL: goto x86_l_195d;
	case 6499ULL: goto x86_l_1963;
	case 6503ULL: goto x86_l_1967;
	case 6509ULL: goto x86_l_196d;
	case 6515ULL: goto x86_l_1973;
	case 6520ULL: goto x86_l_1978;
	case 6524ULL: goto x86_l_197c;
	case 6527ULL: goto x86_l_197f;
	case 6531ULL: goto x86_l_1983;
	case 6537ULL: goto x86_l_1989;
	case 6541ULL: goto x86_l_198d;
	case 6547ULL: goto x86_l_1993;
	case 6553ULL: goto x86_l_1999;
	case 6558ULL: goto x86_l_199e;
	case 6562ULL: goto x86_l_19a2;
	case 6565ULL: goto x86_l_19a5;
	case 6569ULL: goto x86_l_19a9;
	case 6575ULL: goto x86_l_19af;
	case 6579ULL: goto x86_l_19b3;
	case 6585ULL: goto x86_l_19b9;
	case 6591ULL: goto x86_l_19bf;
	case 6596ULL: goto x86_l_19c4;
	case 6600ULL: goto x86_l_19c8;
	case 6603ULL: goto x86_l_19cb;
	case 6607ULL: goto x86_l_19cf;
	case 6613ULL: goto x86_l_19d5;
	case 6617ULL: goto x86_l_19d9;
	case 6623ULL: goto x86_l_19df;
	case 6629ULL: goto x86_l_19e5;
	case 6634ULL: goto x86_l_19ea;
	case 6638ULL: goto x86_l_19ee;
	case 6641ULL: goto x86_l_19f1;
	case 6645ULL: goto x86_l_19f5;
	case 6651ULL: goto x86_l_19fb;
	case 6655ULL: goto x86_l_19ff;
	case 6661ULL: goto x86_l_1a05;
	case 6667ULL: goto x86_l_1a0b;
	case 6672ULL: goto x86_l_1a10;
	case 6676ULL: goto x86_l_1a14;
	case 6679ULL: goto x86_l_1a17;
	case 6683ULL: goto x86_l_1a1b;
	case 6689ULL: goto x86_l_1a21;
	case 6693ULL: goto x86_l_1a25;
	case 6699ULL: goto x86_l_1a2b;
	case 6705ULL: goto x86_l_1a31;
	case 6710ULL: goto x86_l_1a36;
	case 6714ULL: goto x86_l_1a3a;
	case 6717ULL: goto x86_l_1a3d;
	case 6721ULL: goto x86_l_1a41;
	case 6727ULL: goto x86_l_1a47;
	case 6731ULL: goto x86_l_1a4b;
	case 6737ULL: goto x86_l_1a51;
	case 6743ULL: goto x86_l_1a57;
	case 6748ULL: goto x86_l_1a5c;
	case 6752ULL: goto x86_l_1a60;
	case 6755ULL: goto x86_l_1a63;
	case 6759ULL: goto x86_l_1a67;
	case 6765ULL: goto x86_l_1a6d;
	case 6769ULL: goto x86_l_1a71;
	case 6775ULL: goto x86_l_1a77;
	case 6781ULL: goto x86_l_1a7d;
	case 6786ULL: goto x86_l_1a82;
	case 6790ULL: goto x86_l_1a86;
	case 6793ULL: goto x86_l_1a89;
	case 6797ULL: goto x86_l_1a8d;
	case 6803ULL: goto x86_l_1a93;
	case 6807ULL: goto x86_l_1a97;
	case 6813ULL: goto x86_l_1a9d;
	case 6819ULL: goto x86_l_1aa3;
	case 6824ULL: goto x86_l_1aa8;
	case 6828ULL: goto x86_l_1aac;
	case 6831ULL: goto x86_l_1aaf;
	case 6835ULL: goto x86_l_1ab3;
	case 6841ULL: goto x86_l_1ab9;
	case 6845ULL: goto x86_l_1abd;
	case 6851ULL: goto x86_l_1ac3;
	case 6857ULL: goto x86_l_1ac9;
	case 6862ULL: goto x86_l_1ace;
	case 6866ULL: goto x86_l_1ad2;
	case 6869ULL: goto x86_l_1ad5;
	case 6873ULL: goto x86_l_1ad9;
	case 6879ULL: goto x86_l_1adf;
	case 6883ULL: goto x86_l_1ae3;
	case 6889ULL: goto x86_l_1ae9;
	case 6895ULL: goto x86_l_1aef;
	case 6900ULL: goto x86_l_1af4;
	case 6904ULL: goto x86_l_1af8;
	case 6907ULL: goto x86_l_1afb;
	case 6911ULL: goto x86_l_1aff;
	case 6917ULL: goto x86_l_1b05;
	case 6921ULL: goto x86_l_1b09;
	case 6927ULL: goto x86_l_1b0f;
	case 6933ULL: goto x86_l_1b15;
	case 6938ULL: goto x86_l_1b1a;
	case 6942ULL: goto x86_l_1b1e;
	case 6945ULL: goto x86_l_1b21;
	case 6949ULL: goto x86_l_1b25;
	case 6955ULL: goto x86_l_1b2b;
	case 6959ULL: goto x86_l_1b2f;
	case 6965ULL: goto x86_l_1b35;
	case 6971ULL: goto x86_l_1b3b;
	case 6976ULL: goto x86_l_1b40;
	case 6980ULL: goto x86_l_1b44;
	case 6983ULL: goto x86_l_1b47;
	case 6987ULL: goto x86_l_1b4b;
	case 6993ULL: goto x86_l_1b51;
	case 6997ULL: goto x86_l_1b55;
	case 7003ULL: goto x86_l_1b5b;
	case 7009ULL: goto x86_l_1b61;
	case 7014ULL: goto x86_l_1b66;
	case 7018ULL: goto x86_l_1b6a;
	case 7021ULL: goto x86_l_1b6d;
	case 7025ULL: goto x86_l_1b71;
	case 7027ULL: goto x86_l_1b73;
	case 7031ULL: goto x86_l_1b77;
	case 7037ULL: goto x86_l_1b7d;
	case 7043ULL: goto x86_l_1b83;
	case 7048ULL: goto x86_l_1b88;
	case 7052ULL: goto x86_l_1b8c;
	case 7055ULL: goto x86_l_1b8f;
	case 7059ULL: goto x86_l_1b93;
	case 7061ULL: goto x86_l_1b95;
	case 7065ULL: goto x86_l_1b99;
	case 7071ULL: goto x86_l_1b9f;
	case 7077ULL: goto x86_l_1ba5;
	case 7082ULL: goto x86_l_1baa;
	case 7086ULL: goto x86_l_1bae;
	case 7089ULL: goto x86_l_1bb1;
	case 7093ULL: goto x86_l_1bb5;
	case 7095ULL: goto x86_l_1bb7;
	case 7099ULL: goto x86_l_1bbb;
	case 7105ULL: goto x86_l_1bc1;
	case 7111ULL: goto x86_l_1bc7;
	case 7116ULL: goto x86_l_1bcc;
	case 7120ULL: goto x86_l_1bd0;
	case 7123ULL: goto x86_l_1bd3;
	case 7128ULL: goto x86_l_1bd8;
	case 7131ULL: goto x86_l_1bdb;
	case 7134ULL: goto x86_l_1bde;
	case 7139ULL: goto x86_l_1be3;
	case 7142ULL: goto x86_l_1be6;
	case 7148ULL: goto x86_l_1bec;
	case 7150ULL: goto x86_l_1bee;
	case 7160ULL: goto x86_l_1bf8;
	case 7164ULL: goto x86_l_1bfc;
	case 7166ULL: goto x86_l_1bfe;
	case 7170ULL: goto x86_l_1c02;
	case 7173ULL: goto x86_l_1c05;
	case 7179ULL: goto x86_l_1c0b;
	case 7184ULL: goto x86_l_1c10;
	case 7187ULL: goto x86_l_1c13;
	case 7193ULL: goto x86_l_1c19;
	case 7197ULL: goto x86_l_1c1d;
	case 7200ULL: goto x86_l_1c20;
	case 7203ULL: goto x86_l_1c23;
	case 7209ULL: goto x86_l_1c29;
	case 7212ULL: goto x86_l_1c2c;
	case 7218ULL: goto x86_l_1c32;
	case 7223ULL: goto x86_l_1c37;
	case 7228ULL: goto x86_l_1c3c;
	case 7232ULL: goto x86_l_1c40;
	case 7238ULL: goto x86_l_1c46;
	case 7242ULL: goto x86_l_1c4a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1545:
	/* 0x1545: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_154b:
	/* 0x154b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1550:
	/* 0x1550: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1554:
	/* 0x1554: mov    BYTE PTR [rax+0x35],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_1557:
	/* 0x1557: cmp    rsi,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 50ULL);
x86_l_155b:
	/* 0x155b: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1561:
	/* 0x1561: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1565:
	/* 0x1565: lea    ecx,[rsi+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_156b:
	/* 0x156b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1571:
	/* 0x1571: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1576:
	/* 0x1576: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_157a:
	/* 0x157a: mov    BYTE PTR [rax+0x36],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_157d:
	/* 0x157d: cmp    rsi,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 51ULL);
x86_l_1581:
	/* 0x1581: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1587:
	/* 0x1587: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_158b:
	/* 0x158b: lea    ecx,[rsi+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_1591:
	/* 0x1591: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1597:
	/* 0x1597: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_159c:
	/* 0x159c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_15a0:
	/* 0x15a0: mov    BYTE PTR [rax+0x37],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_15a3:
	/* 0x15a3: cmp    rsi,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 52ULL);
x86_l_15a7:
	/* 0x15a7: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_15ad:
	/* 0x15ad: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15b1:
	/* 0x15b1: lea    ecx,[rsi+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_15b7:
	/* 0x15b7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15bd:
	/* 0x15bd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15c2:
	/* 0x15c2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_15c6:
	/* 0x15c6: mov    BYTE PTR [rax+0x38],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15c9:
	/* 0x15c9: cmp    rsi,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 53ULL);
x86_l_15cd:
	/* 0x15cd: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_15d3:
	/* 0x15d3: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15d7:
	/* 0x15d7: lea    ecx,[rsi+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_15dd:
	/* 0x15dd: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15e3:
	/* 0x15e3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15e8:
	/* 0x15e8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_15ec:
	/* 0x15ec: mov    BYTE PTR [rax+0x39],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_15ef:
	/* 0x15ef: cmp    rsi,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 54ULL);
x86_l_15f3:
	/* 0x15f3: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_15f9:
	/* 0x15f9: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15fd:
	/* 0x15fd: lea    ecx,[rsi+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_1603:
	/* 0x1603: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1609:
	/* 0x1609: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_160e:
	/* 0x160e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1612:
	/* 0x1612: mov    BYTE PTR [rax+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_1615:
	/* 0x1615: cmp    rsi,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 55ULL);
x86_l_1619:
	/* 0x1619: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_161f:
	/* 0x161f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1623:
	/* 0x1623: lea    ecx,[rsi+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_1629:
	/* 0x1629: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_162f:
	/* 0x162f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1634:
	/* 0x1634: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1638:
	/* 0x1638: mov    BYTE PTR [rax+0x3b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_163b:
	/* 0x163b: cmp    rsi,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 56ULL);
x86_l_163f:
	/* 0x163f: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1645:
	/* 0x1645: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1649:
	/* 0x1649: lea    ecx,[rsi+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_164f:
	/* 0x164f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1655:
	/* 0x1655: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_165a:
	/* 0x165a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_165e:
	/* 0x165e: mov    BYTE PTR [rax+0x3c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1661:
	/* 0x1661: cmp    rsi,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 57ULL);
x86_l_1665:
	/* 0x1665: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_166b:
	/* 0x166b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_166f:
	/* 0x166f: lea    ecx,[rsi+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_1675:
	/* 0x1675: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_167b:
	/* 0x167b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1680:
	/* 0x1680: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1684:
	/* 0x1684: mov    BYTE PTR [rax+0x3d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_1687:
	/* 0x1687: cmp    rsi,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 58ULL);
x86_l_168b:
	/* 0x168b: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1691:
	/* 0x1691: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1695:
	/* 0x1695: lea    ecx,[rsi+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_169b:
	/* 0x169b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16a1:
	/* 0x16a1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16a6:
	/* 0x16a6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_16aa:
	/* 0x16aa: mov    BYTE PTR [rax+0x3e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_16ad:
	/* 0x16ad: cmp    rsi,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 59ULL);
x86_l_16b1:
	/* 0x16b1: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_16b7:
	/* 0x16b7: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16bb:
	/* 0x16bb: lea    ecx,[rsi+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_16c1:
	/* 0x16c1: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16c7:
	/* 0x16c7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16cc:
	/* 0x16cc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_16d0:
	/* 0x16d0: mov    BYTE PTR [rax+0x3f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_16d3:
	/* 0x16d3: cmp    rsi,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 60ULL);
x86_l_16d7:
	/* 0x16d7: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_16dd:
	/* 0x16dd: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16e1:
	/* 0x16e1: lea    ecx,[rsi+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_16e7:
	/* 0x16e7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16ed:
	/* 0x16ed: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16f2:
	/* 0x16f2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_16f6:
	/* 0x16f6: mov    BYTE PTR [rax+0x40],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16f9:
	/* 0x16f9: cmp    rsi,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 61ULL);
x86_l_16fd:
	/* 0x16fd: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1703:
	/* 0x1703: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1707:
	/* 0x1707: lea    ecx,[rsi+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_170d:
	/* 0x170d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1713:
	/* 0x1713: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1718:
	/* 0x1718: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_171c:
	/* 0x171c: mov    BYTE PTR [rax+0x41],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_171f:
	/* 0x171f: cmp    rsi,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 62ULL);
x86_l_1723:
	/* 0x1723: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1729:
	/* 0x1729: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_172d:
	/* 0x172d: lea    ecx,[rsi+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_1733:
	/* 0x1733: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1739:
	/* 0x1739: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_173e:
	/* 0x173e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1742:
	/* 0x1742: mov    BYTE PTR [rax+0x42],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_1745:
	/* 0x1745: cmp    rsi,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 63ULL);
x86_l_1749:
	/* 0x1749: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_174f:
	/* 0x174f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1753:
	/* 0x1753: lea    ecx,[rsi+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_1759:
	/* 0x1759: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_175f:
	/* 0x175f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1764:
	/* 0x1764: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1768:
	/* 0x1768: mov    BYTE PTR [rax+0x43],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_176b:
	/* 0x176b: cmp    rsi,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 64ULL);
x86_l_176f:
	/* 0x176f: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1775:
	/* 0x1775: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1779:
	/* 0x1779: lea    ecx,[rsi+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_177f:
	/* 0x177f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1785:
	/* 0x1785: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_178a:
	/* 0x178a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_178e:
	/* 0x178e: mov    BYTE PTR [rax+0x44],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1791:
	/* 0x1791: cmp    rsi,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 65ULL);
x86_l_1795:
	/* 0x1795: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_179b:
	/* 0x179b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_179f:
	/* 0x179f: lea    ecx,[rsi+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_17a5:
	/* 0x17a5: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17ab:
	/* 0x17ab: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17b0:
	/* 0x17b0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_17b4:
	/* 0x17b4: mov    BYTE PTR [rax+0x45],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_17b7:
	/* 0x17b7: cmp    rsi,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 66ULL);
x86_l_17bb:
	/* 0x17bb: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_17c1:
	/* 0x17c1: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17c5:
	/* 0x17c5: lea    ecx,[rsi+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_17cb:
	/* 0x17cb: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17d1:
	/* 0x17d1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17d6:
	/* 0x17d6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_17da:
	/* 0x17da: mov    BYTE PTR [rax+0x46],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_17dd:
	/* 0x17dd: cmp    rsi,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 67ULL);
x86_l_17e1:
	/* 0x17e1: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_17e7:
	/* 0x17e7: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17eb:
	/* 0x17eb: lea    ecx,[rsi+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_17f1:
	/* 0x17f1: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17f7:
	/* 0x17f7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17fc:
	/* 0x17fc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1800:
	/* 0x1800: mov    BYTE PTR [rax+0x47],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_1803:
	/* 0x1803: cmp    rsi,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 68ULL);
x86_l_1807:
	/* 0x1807: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_180d:
	/* 0x180d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1811:
	/* 0x1811: lea    ecx,[rsi+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_1817:
	/* 0x1817: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_181d:
	/* 0x181d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1822:
	/* 0x1822: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1826:
	/* 0x1826: mov    BYTE PTR [rax+0x48],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1829:
	/* 0x1829: cmp    rsi,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 69ULL);
x86_l_182d:
	/* 0x182d: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1833:
	/* 0x1833: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1837:
	/* 0x1837: lea    ecx,[rsi+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_183d:
	/* 0x183d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1843:
	/* 0x1843: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1848:
	/* 0x1848: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_184c:
	/* 0x184c: mov    BYTE PTR [rax+0x49],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_184f:
	/* 0x184f: cmp    rsi,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 70ULL);
x86_l_1853:
	/* 0x1853: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1859:
	/* 0x1859: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_185d:
	/* 0x185d: lea    ecx,[rsi+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_1863:
	/* 0x1863: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1869:
	/* 0x1869: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_186e:
	/* 0x186e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1872:
	/* 0x1872: mov    BYTE PTR [rax+0x4a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_1875:
	/* 0x1875: cmp    rsi,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 71ULL);
x86_l_1879:
	/* 0x1879: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_187f:
	/* 0x187f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1883:
	/* 0x1883: lea    ecx,[rsi+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_1889:
	/* 0x1889: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_188f:
	/* 0x188f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1894:
	/* 0x1894: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1898:
	/* 0x1898: mov    BYTE PTR [rax+0x4b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_189b:
	/* 0x189b: cmp    rsi,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 72ULL);
x86_l_189f:
	/* 0x189f: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_18a5:
	/* 0x18a5: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18a9:
	/* 0x18a9: lea    ecx,[rsi+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_18af:
	/* 0x18af: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18b5:
	/* 0x18b5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18ba:
	/* 0x18ba: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_18be:
	/* 0x18be: mov    BYTE PTR [rax+0x4c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_18c1:
	/* 0x18c1: cmp    rsi,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 73ULL);
x86_l_18c5:
	/* 0x18c5: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_18cb:
	/* 0x18cb: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18cf:
	/* 0x18cf: lea    ecx,[rsi+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_18d5:
	/* 0x18d5: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18db:
	/* 0x18db: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18e0:
	/* 0x18e0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_18e4:
	/* 0x18e4: mov    BYTE PTR [rax+0x4d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_18e7:
	/* 0x18e7: cmp    rsi,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 74ULL);
x86_l_18eb:
	/* 0x18eb: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_18f1:
	/* 0x18f1: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18f5:
	/* 0x18f5: lea    ecx,[rsi+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_18fb:
	/* 0x18fb: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1901:
	/* 0x1901: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1906:
	/* 0x1906: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_190a:
	/* 0x190a: mov    BYTE PTR [rax+0x4e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_190d:
	/* 0x190d: cmp    rsi,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 75ULL);
x86_l_1911:
	/* 0x1911: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1917:
	/* 0x1917: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_191b:
	/* 0x191b: lea    ecx,[rsi+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_1921:
	/* 0x1921: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1927:
	/* 0x1927: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_192c:
	/* 0x192c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1930:
	/* 0x1930: mov    BYTE PTR [rax+0x4f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_1933:
	/* 0x1933: cmp    rsi,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 76ULL);
x86_l_1937:
	/* 0x1937: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_193d:
	/* 0x193d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1941:
	/* 0x1941: lea    ecx,[rsi+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_1947:
	/* 0x1947: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_194d:
	/* 0x194d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1952:
	/* 0x1952: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1956:
	/* 0x1956: mov    BYTE PTR [rax+0x50],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1959:
	/* 0x1959: cmp    rsi,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 77ULL);
x86_l_195d:
	/* 0x195d: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1963:
	/* 0x1963: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1967:
	/* 0x1967: lea    ecx,[rsi+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_196d:
	/* 0x196d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1973:
	/* 0x1973: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1978:
	/* 0x1978: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_197c:
	/* 0x197c: mov    BYTE PTR [rax+0x51],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_197f:
	/* 0x197f: cmp    rsi,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 78ULL);
x86_l_1983:
	/* 0x1983: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1989:
	/* 0x1989: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_198d:
	/* 0x198d: lea    ecx,[rsi+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_1993:
	/* 0x1993: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1999:
	/* 0x1999: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_199e:
	/* 0x199e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_19a2:
	/* 0x19a2: mov    BYTE PTR [rax+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_19a5:
	/* 0x19a5: cmp    rsi,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 79ULL);
x86_l_19a9:
	/* 0x19a9: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_19af:
	/* 0x19af: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19b3:
	/* 0x19b3: lea    ecx,[rsi+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_19b9:
	/* 0x19b9: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19bf:
	/* 0x19bf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19c4:
	/* 0x19c4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_19c8:
	/* 0x19c8: mov    BYTE PTR [rax+0x53],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_19cb:
	/* 0x19cb: cmp    rsi,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 80ULL);
x86_l_19cf:
	/* 0x19cf: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_19d5:
	/* 0x19d5: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19d9:
	/* 0x19d9: lea    ecx,[rsi+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_19df:
	/* 0x19df: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19e5:
	/* 0x19e5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19ea:
	/* 0x19ea: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_19ee:
	/* 0x19ee: mov    BYTE PTR [rax+0x54],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_19f1:
	/* 0x19f1: cmp    rsi,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 81ULL);
x86_l_19f5:
	/* 0x19f5: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_19fb:
	/* 0x19fb: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19ff:
	/* 0x19ff: lea    ecx,[rsi+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_1a05:
	/* 0x1a05: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a0b:
	/* 0x1a0b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a10:
	/* 0x1a10: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a14:
	/* 0x1a14: mov    BYTE PTR [rax+0x55],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_1a17:
	/* 0x1a17: cmp    rsi,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 82ULL);
x86_l_1a1b:
	/* 0x1a1b: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1a21:
	/* 0x1a21: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a25:
	/* 0x1a25: lea    ecx,[rsi+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_1a2b:
	/* 0x1a2b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a31:
	/* 0x1a31: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a36:
	/* 0x1a36: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a3a:
	/* 0x1a3a: mov    BYTE PTR [rax+0x56],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1a3d:
	/* 0x1a3d: cmp    rsi,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 83ULL);
x86_l_1a41:
	/* 0x1a41: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1a47:
	/* 0x1a47: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a4b:
	/* 0x1a4b: lea    ecx,[rsi+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_1a51:
	/* 0x1a51: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a57:
	/* 0x1a57: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a5c:
	/* 0x1a5c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a60:
	/* 0x1a60: mov    BYTE PTR [rax+0x57],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_1a63:
	/* 0x1a63: cmp    rsi,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 84ULL);
x86_l_1a67:
	/* 0x1a67: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1a6d:
	/* 0x1a6d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a71:
	/* 0x1a71: lea    ecx,[rsi+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_1a77:
	/* 0x1a77: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a7d:
	/* 0x1a7d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a82:
	/* 0x1a82: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a86:
	/* 0x1a86: mov    BYTE PTR [rax+0x58],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1a89:
	/* 0x1a89: cmp    rsi,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 85ULL);
x86_l_1a8d:
	/* 0x1a8d: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1a93:
	/* 0x1a93: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a97:
	/* 0x1a97: lea    ecx,[rsi+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_1a9d:
	/* 0x1a9d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1aa3:
	/* 0x1aa3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aa8:
	/* 0x1aa8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1aac:
	/* 0x1aac: mov    BYTE PTR [rax+0x59],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_1aaf:
	/* 0x1aaf: cmp    rsi,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 86ULL);
x86_l_1ab3:
	/* 0x1ab3: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1ab9:
	/* 0x1ab9: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1abd:
	/* 0x1abd: lea    ecx,[rsi+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_1ac3:
	/* 0x1ac3: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ac9:
	/* 0x1ac9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ace:
	/* 0x1ace: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ad2:
	/* 0x1ad2: mov    BYTE PTR [rax+0x5a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_1ad5:
	/* 0x1ad5: cmp    rsi,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 87ULL);
x86_l_1ad9:
	/* 0x1ad9: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1adf:
	/* 0x1adf: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ae3:
	/* 0x1ae3: lea    ecx,[rsi+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_1ae9:
	/* 0x1ae9: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1aef:
	/* 0x1aef: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1af4:
	/* 0x1af4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1af8:
	/* 0x1af8: mov    BYTE PTR [rax+0x5b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_1afb:
	/* 0x1afb: cmp    rsi,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 88ULL);
x86_l_1aff:
	/* 0x1aff: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1b05:
	/* 0x1b05: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b09:
	/* 0x1b09: lea    ecx,[rsi+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_1b0f:
	/* 0x1b0f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1b15:
	/* 0x1b15: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b1a:
	/* 0x1b1a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1b1e:
	/* 0x1b1e: mov    BYTE PTR [rax+0x5c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_1b21:
	/* 0x1b21: cmp    rsi,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 89ULL);
x86_l_1b25:
	/* 0x1b25: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1b2b:
	/* 0x1b2b: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b2f:
	/* 0x1b2f: lea    ecx,[rsi+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_1b35:
	/* 0x1b35: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1b3b:
	/* 0x1b3b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b40:
	/* 0x1b40: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1b44:
	/* 0x1b44: mov    BYTE PTR [rax+0x5d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_1b47:
	/* 0x1b47: cmp    rsi,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 90ULL);
x86_l_1b4b:
	/* 0x1b4b: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1b51:
	/* 0x1b51: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b55:
	/* 0x1b55: lea    ecx,[rsi+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_1b5b:
	/* 0x1b5b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1b61:
	/* 0x1b61: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b66:
	/* 0x1b66: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1b6a:
	/* 0x1b6a: mov    BYTE PTR [rax+0x5e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_1b6d:
	/* 0x1b6d: cmp    rsi,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 91ULL);
x86_l_1b71:
	/* 0x1b71: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1b73:
	/* 0x1b73: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b77:
	/* 0x1b77: lea    ecx,[rsi+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_1b7d:
	/* 0x1b7d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1b83:
	/* 0x1b83: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b88:
	/* 0x1b88: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1b8c:
	/* 0x1b8c: mov    BYTE PTR [rax+0x5f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_1b8f:
	/* 0x1b8f: cmp    rsi,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 92ULL);
x86_l_1b93:
	/* 0x1b93: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1b95:
	/* 0x1b95: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b99:
	/* 0x1b99: lea    ecx,[rsi+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_1b9f:
	/* 0x1b9f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ba5:
	/* 0x1ba5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1baa:
	/* 0x1baa: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1bae:
	/* 0x1bae: mov    BYTE PTR [rax+0x60],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1bb1:
	/* 0x1bb1: cmp    rsi,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 93ULL);
x86_l_1bb5:
	/* 0x1bb5: je     1bd3 <generic_fexit_filter_arg+0x1bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd3;
	}
x86_l_1bb7:
	/* 0x1bb7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bbb:
	/* 0x1bbb: add    edx,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_1bc1:
	/* 0x1bc1: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1bc7:
	/* 0x1bc7: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bcc:
	/* 0x1bcc: movzx  ecx,BYTE PTR [rcx+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_8), 0ULL);
x86_l_1bd0:
	/* 0x1bd0: mov    BYTE PTR [rax+0x61],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_1bd3:
	/* 0x1bd3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1bd8:
	/* 0x1bd8: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1bdb:
	/* 0x1bdb: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1bde:
	/* 0x1bde: jmp    37b0 <generic_fexit_filter_arg+0x37b0> */
	return 14256ULL;
x86_l_1be3:
	/* 0x1be3: cmp    eax,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_1be6:
	/* 0x1be6: ja     37ea <generic_fexit_filter_arg+0x37ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14314ULL;
	}
x86_l_1bec:
	/* 0x1bec: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bee:
	/* 0x1bee: movabs rcx,0x1e10000c00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 129117457408ULL);
x86_l_1bf8:
	/* 0x1bf8: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1bfc:
	/* 0x1bfc: jae    1c37 <generic_fexit_filter_arg+0x1c37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1c37;
	}
x86_l_1bfe:
	/* 0x1bfe: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c02:
	/* 0x1c02: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1c05:
	/* 0x1c05: ja     37f4 <generic_fexit_filter_arg+0x37f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14324ULL;
	}
x86_l_1c0b:
	/* 0x1c0b: mov    ecx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4126ULL);
x86_l_1c10:
	/* 0x1c10: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1c13:
	/* 0x1c13: jae    1c98 <generic_fexit_filter_arg+0x1c98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7320ULL;
	}
x86_l_1c19:
	/* 0x1c19: mov    rdx,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c1d:
	/* 0x1c1d: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1c20:
	/* 0x1c20: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1c23:
	/* 0x1c23: jae    1d00 <generic_fexit_filter_arg+0x1d00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7424ULL;
	}
x86_l_1c29:
	/* 0x1c29: cmp    QWORD PTR [rdi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c2c:
	/* 0x1c2c: jne    1d0e <generic_fexit_filter_arg+0x1d0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7438ULL;
	}
x86_l_1c32:
	/* 0x1c32: jmp    35e2 <generic_fexit_filter_arg+0x35e2> */
	return 13794ULL;
x86_l_1c37:
	/* 0x1c37: mov    ecx,0x3012 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 12306ULL);
x86_l_1c3c:
	/* 0x1c3c: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1c40:
	/* 0x1c40: jae    37ea <generic_fexit_filter_arg+0x37ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14314ULL;
	}
x86_l_1c46:
	/* 0x1c46: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c4a:
	/* 0x1c4a: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
	return 7245ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7245ULL: goto x86_l_1c4d;
	case 7251ULL: goto x86_l_1c53;
	case 7256ULL: goto x86_l_1c58;
	case 7259ULL: goto x86_l_1c5b;
	case 7265ULL: goto x86_l_1c61;
	case 7269ULL: goto x86_l_1c65;
	case 7272ULL: goto x86_l_1c68;
	case 7275ULL: goto x86_l_1c6b;
	case 7281ULL: goto x86_l_1c71;
	case 7283ULL: goto x86_l_1c73;
	case 7289ULL: goto x86_l_1c79;
	case 7294ULL: goto x86_l_1c7e;
	case 7297ULL: goto x86_l_1c81;
	case 7303ULL: goto x86_l_1c87;
	case 7306ULL: goto x86_l_1c8a;
	case 7309ULL: goto x86_l_1c8d;
	case 7315ULL: goto x86_l_1c93;
	case 7320ULL: goto x86_l_1c98;
	case 7325ULL: goto x86_l_1c9d;
	case 7328ULL: goto x86_l_1ca0;
	case 7334ULL: goto x86_l_1ca6;
	case 7337ULL: goto x86_l_1ca9;
	case 7342ULL: goto x86_l_1cae;
	case 7346ULL: goto x86_l_1cb2;
	case 7351ULL: goto x86_l_1cb7;
	case 7358ULL: goto x86_l_1cbe;
	case 7363ULL: goto x86_l_1cc3;
	case 7365ULL: goto x86_l_1cc5;
	case 7368ULL: goto x86_l_1cc8;
	case 7374ULL: goto x86_l_1cce;
	case 7377ULL: goto x86_l_1cd1;
	case 7382ULL: goto x86_l_1cd6;
	case 7387ULL: goto x86_l_1cdb;
	case 7392ULL: goto x86_l_1ce0;
	case 7395ULL: goto x86_l_1ce3;
	case 7397ULL: goto x86_l_1ce5;
	case 7401ULL: goto x86_l_1ce9;
	case 7404ULL: goto x86_l_1cec;
	case 7410ULL: goto x86_l_1cf2;
	case 7413ULL: goto x86_l_1cf5;
	case 7419ULL: goto x86_l_1cfb;
	case 7424ULL: goto x86_l_1d00;
	case 7427ULL: goto x86_l_1d03;
	case 7429ULL: goto x86_l_1d05;
	case 7432ULL: goto x86_l_1d08;
	case 7438ULL: goto x86_l_1d0e;
	case 7442ULL: goto x86_l_1d12;
	case 7445ULL: goto x86_l_1d15;
	case 7451ULL: goto x86_l_1d1b;
	case 7455ULL: goto x86_l_1d1f;
	case 7458ULL: goto x86_l_1d22;
	case 7464ULL: goto x86_l_1d28;
	case 7467ULL: goto x86_l_1d2b;
	case 7473ULL: goto x86_l_1d31;
	case 7478ULL: goto x86_l_1d36;
	case 7481ULL: goto x86_l_1d39;
	case 7487ULL: goto x86_l_1d3f;
	case 7492ULL: goto x86_l_1d44;
	case 7497ULL: goto x86_l_1d49;
	case 7500ULL: goto x86_l_1d4c;
	case 7506ULL: goto x86_l_1d52;
	case 7509ULL: goto x86_l_1d55;
	case 7514ULL: goto x86_l_1d5a;
	case 7518ULL: goto x86_l_1d5e;
	case 7523ULL: goto x86_l_1d63;
	case 7530ULL: goto x86_l_1d6a;
	case 7535ULL: goto x86_l_1d6f;
	case 7537ULL: goto x86_l_1d71;
	case 7540ULL: goto x86_l_1d74;
	case 7546ULL: goto x86_l_1d7a;
	case 7549ULL: goto x86_l_1d7d;
	case 7554ULL: goto x86_l_1d82;
	case 7559ULL: goto x86_l_1d87;
	case 7564ULL: goto x86_l_1d8c;
	case 7569ULL: goto x86_l_1d91;
	case 7572ULL: goto x86_l_1d94;
	case 7574ULL: goto x86_l_1d96;
	case 7576ULL: goto x86_l_1d98;
	case 7582ULL: goto x86_l_1d9e;
	case 7586ULL: goto x86_l_1da2;
	case 7589ULL: goto x86_l_1da5;
	case 7595ULL: goto x86_l_1dab;
	case 7599ULL: goto x86_l_1daf;
	case 7602ULL: goto x86_l_1db2;
	case 7608ULL: goto x86_l_1db8;
	case 7610ULL: goto x86_l_1dba;
	case 7616ULL: goto x86_l_1dc0;
	case 7621ULL: goto x86_l_1dc5;
	case 7625ULL: goto x86_l_1dc9;
	case 7628ULL: goto x86_l_1dcc;
	case 7632ULL: goto x86_l_1dd0;
	case 7635ULL: goto x86_l_1dd3;
	case 7637ULL: goto x86_l_1dd5;
	case 7639ULL: goto x86_l_1dd7;
	case 7642ULL: goto x86_l_1dda;
	case 7645ULL: goto x86_l_1ddd;
	case 7651ULL: goto x86_l_1de3;
	case 7654ULL: goto x86_l_1de6;
	case 7660ULL: goto x86_l_1dec;
	case 7662ULL: goto x86_l_1dee;
	case 7667ULL: goto x86_l_1df3;
	case 7671ULL: goto x86_l_1df7;
	case 7677ULL: goto x86_l_1dfd;
	case 7682ULL: goto x86_l_1e02;
	case 7686ULL: goto x86_l_1e06;
	case 7692ULL: goto x86_l_1e0c;
	case 7702ULL: goto x86_l_1e16;
	case 7706ULL: goto x86_l_1e1a;
	case 7712ULL: goto x86_l_1e20;
	case 7719ULL: goto x86_l_1e27;
	case 7726ULL: goto x86_l_1e2e;
	case 7732ULL: goto x86_l_1e34;
	case 7735ULL: goto x86_l_1e37;
	case 7740ULL: goto x86_l_1e3c;
	case 7744ULL: goto x86_l_1e40;
	case 7748ULL: goto x86_l_1e44;
	case 7756ULL: goto x86_l_1e4c;
	case 7761ULL: goto x86_l_1e51;
	case 7768ULL: goto x86_l_1e58;
	case 7773ULL: goto x86_l_1e5d;
	case 7775ULL: goto x86_l_1e5f;
	case 7778ULL: goto x86_l_1e62;
	case 7783ULL: goto x86_l_1e67;
	case 7789ULL: goto x86_l_1e6d;
	case 7792ULL: goto x86_l_1e70;
	case 7795ULL: goto x86_l_1e73;
	case 7801ULL: goto x86_l_1e79;
	case 7806ULL: goto x86_l_1e7e;
	case 7813ULL: goto x86_l_1e85;
	case 7818ULL: goto x86_l_1e8a;
	case 7820ULL: goto x86_l_1e8c;
	case 7823ULL: goto x86_l_1e8f;
	case 7829ULL: goto x86_l_1e95;
	case 7833ULL: goto x86_l_1e99;
	case 7839ULL: goto x86_l_1e9f;
	case 7844ULL: goto x86_l_1ea4;
	case 7847ULL: goto x86_l_1ea7;
	case 7854ULL: goto x86_l_1eae;
	case 7856ULL: goto x86_l_1eb0;
	case 7859ULL: goto x86_l_1eb3;
	case 7863ULL: goto x86_l_1eb7;
	case 7868ULL: goto x86_l_1ebc;
	case 7873ULL: goto x86_l_1ec1;
	case 7876ULL: goto x86_l_1ec4;
	case 7878ULL: goto x86_l_1ec6;
	case 7883ULL: goto x86_l_1ecb;
	case 7886ULL: goto x86_l_1ece;
	case 7889ULL: goto x86_l_1ed1;
	case 7891ULL: goto x86_l_1ed3;
	case 7896ULL: goto x86_l_1ed8;
	case 7904ULL: goto x86_l_1ee0;
	case 7910ULL: goto x86_l_1ee6;
	case 7916ULL: goto x86_l_1eec;
	case 7919ULL: goto x86_l_1eef;
	case 7925ULL: goto x86_l_1ef5;
	case 7928ULL: goto x86_l_1ef8;
	case 7931ULL: goto x86_l_1efb;
	case 7934ULL: goto x86_l_1efe;
	case 7936ULL: goto x86_l_1f00;
	case 7938ULL: goto x86_l_1f02;
	case 7941ULL: goto x86_l_1f05;
	case 7947ULL: goto x86_l_1f0b;
	case 7949ULL: goto x86_l_1f0d;
	case 7955ULL: goto x86_l_1f13;
	case 7960ULL: goto x86_l_1f18;
	case 7963ULL: goto x86_l_1f1b;
	case 7968ULL: goto x86_l_1f20;
	case 7972ULL: goto x86_l_1f24;
	case 7977ULL: goto x86_l_1f29;
	case 7981ULL: goto x86_l_1f2d;
	case 7986ULL: goto x86_l_1f32;
	case 7990ULL: goto x86_l_1f36;
	case 7995ULL: goto x86_l_1f3b;
	case 8000ULL: goto x86_l_1f40;
	case 8002ULL: goto x86_l_1f42;
	case 8006ULL: goto x86_l_1f46;
	case 8009ULL: goto x86_l_1f49;
	case 8012ULL: goto x86_l_1f4c;
	case 8014ULL: goto x86_l_1f4e;
	case 8017ULL: goto x86_l_1f51;
	case 8019ULL: goto x86_l_1f53;
	case 8022ULL: goto x86_l_1f56;
	case 8025ULL: goto x86_l_1f59;
	case 8031ULL: goto x86_l_1f5f;
	case 8034ULL: goto x86_l_1f62;
	case 8037ULL: goto x86_l_1f65;
	case 8043ULL: goto x86_l_1f6b;
	case 8048ULL: goto x86_l_1f70;
	case 8051ULL: goto x86_l_1f73;
	case 8053ULL: goto x86_l_1f75;
	case 8056ULL: goto x86_l_1f78;
	case 8062ULL: goto x86_l_1f7e;
	case 8065ULL: goto x86_l_1f81;
	case 8071ULL: goto x86_l_1f87;
	case 8074ULL: goto x86_l_1f8a;
	case 8080ULL: goto x86_l_1f90;
	case 8085ULL: goto x86_l_1f95;
	case 8090ULL: goto x86_l_1f9a;
	case 8093ULL: goto x86_l_1f9d;
	case 8099ULL: goto x86_l_1fa3;
	case 8102ULL: goto x86_l_1fa6;
	case 8108ULL: goto x86_l_1fac;
	case 8111ULL: goto x86_l_1faf;
	case 8117ULL: goto x86_l_1fb5;
	case 8122ULL: goto x86_l_1fba;
	case 8125ULL: goto x86_l_1fbd;
	case 8131ULL: goto x86_l_1fc3;
	case 8134ULL: goto x86_l_1fc6;
	case 8140ULL: goto x86_l_1fcc;
	case 8143ULL: goto x86_l_1fcf;
	case 8149ULL: goto x86_l_1fd5;
	case 8154ULL: goto x86_l_1fda;
	case 8157ULL: goto x86_l_1fdd;
	case 8160ULL: goto x86_l_1fe0;
	case 8166ULL: goto x86_l_1fe6;
	case 8171ULL: goto x86_l_1feb;
	case 8179ULL: goto x86_l_1ff3;
	case 8186ULL: goto x86_l_1ffa;
	case 8192ULL: goto x86_l_2000;
	case 8197ULL: goto x86_l_2005;
	case 8201ULL: goto x86_l_2009;
	case 8207ULL: goto x86_l_200f;
	case 8210ULL: goto x86_l_2012;
	case 8213ULL: goto x86_l_2015;
	case 8216ULL: goto x86_l_2018;
	case 8219ULL: goto x86_l_201b;
	case 8221ULL: goto x86_l_201d;
	case 8225ULL: goto x86_l_2021;
	case 8230ULL: goto x86_l_2026;
	case 8236ULL: goto x86_l_202c;
	case 8238ULL: goto x86_l_202e;
	case 8244ULL: goto x86_l_2034;
	case 8247ULL: goto x86_l_2037;
	case 8252ULL: goto x86_l_203c;
	case 8255ULL: goto x86_l_203f;
	case 8257ULL: goto x86_l_2041;
	case 8260ULL: goto x86_l_2044;
	case 8266ULL: goto x86_l_204a;
	case 8269ULL: goto x86_l_204d;
	case 8275ULL: goto x86_l_2053;
	case 8279ULL: goto x86_l_2057;
	case 8282ULL: goto x86_l_205a;
	case 8288ULL: goto x86_l_2060;
	case 8291ULL: goto x86_l_2063;
	case 8297ULL: goto x86_l_2069;
	case 8302ULL: goto x86_l_206e;
	case 8305ULL: goto x86_l_2071;
	case 8307ULL: goto x86_l_2073;
	case 8310ULL: goto x86_l_2076;
	case 8316ULL: goto x86_l_207c;
	case 8321ULL: goto x86_l_2081;
	case 8325ULL: goto x86_l_2085;
	case 8327ULL: goto x86_l_2087;
	case 8332ULL: goto x86_l_208c;
	case 8336ULL: goto x86_l_2090;
	case 8338ULL: goto x86_l_2092;
	case 8341ULL: goto x86_l_2095;
	case 8344ULL: goto x86_l_2098;
	case 8349ULL: goto x86_l_209d;
	case 8352ULL: goto x86_l_20a0;
	case 8358ULL: goto x86_l_20a6;
	case 8361ULL: goto x86_l_20a9;
	case 8367ULL: goto x86_l_20af;
	case 8370ULL: goto x86_l_20b2;
	case 8376ULL: goto x86_l_20b8;
	case 8379ULL: goto x86_l_20bb;
	case 8385ULL: goto x86_l_20c1;
	case 8388ULL: goto x86_l_20c4;
	case 8393ULL: goto x86_l_20c9;
	case 8398ULL: goto x86_l_20ce;
	case 8403ULL: goto x86_l_20d3;
	case 8407ULL: goto x86_l_20d7;
	case 8411ULL: goto x86_l_20db;
	case 8419ULL: goto x86_l_20e3;
	case 8424ULL: goto x86_l_20e8;
	case 8431ULL: goto x86_l_20ef;
	case 8436ULL: goto x86_l_20f4;
	case 8439ULL: goto x86_l_20f7;
	case 8441ULL: goto x86_l_20f9;
	case 8444ULL: goto x86_l_20fc;
	case 8447ULL: goto x86_l_20ff;
	case 8450ULL: goto x86_l_2102;
	case 8456ULL: goto x86_l_2108;
	case 8460ULL: goto x86_l_210c;
	case 8463ULL: goto x86_l_210f;
	case 8469ULL: goto x86_l_2115;
	case 8474ULL: goto x86_l_211a;
	case 8481ULL: goto x86_l_2121;
	case 8486ULL: goto x86_l_2126;
	case 8488ULL: goto x86_l_2128;
	case 8491ULL: goto x86_l_212b;
	case 8497ULL: goto x86_l_2131;
	case 8502ULL: goto x86_l_2136;
	case 8506ULL: goto x86_l_213a;
	case 8510ULL: goto x86_l_213e;
	case 8515ULL: goto x86_l_2143;
	case 8519ULL: goto x86_l_2147;
	case 8522ULL: goto x86_l_214a;
	case 8524ULL: goto x86_l_214c;
	case 8528ULL: goto x86_l_2150;
	case 8534ULL: goto x86_l_2156;
	case 8538ULL: goto x86_l_215a;
	case 8541ULL: goto x86_l_215d;
	case 8545ULL: goto x86_l_2161;
	case 8551ULL: goto x86_l_2167;
	case 8558ULL: goto x86_l_216e;
	case 8564ULL: goto x86_l_2174;
	case 8568ULL: goto x86_l_2178;
	case 8571ULL: goto x86_l_217b;
	case 8575ULL: goto x86_l_217f;
	case 8581ULL: goto x86_l_2185;
	case 8588ULL: goto x86_l_218c;
	case 8594ULL: goto x86_l_2192;
	case 8598ULL: goto x86_l_2196;
	case 8601ULL: goto x86_l_2199;
	case 8605ULL: goto x86_l_219d;
	case 8611ULL: goto x86_l_21a3;
	case 8618ULL: goto x86_l_21aa;
	case 8624ULL: goto x86_l_21b0;
	case 8628ULL: goto x86_l_21b4;
	case 8631ULL: goto x86_l_21b7;
	case 8635ULL: goto x86_l_21bb;
	case 8641ULL: goto x86_l_21c1;
	case 8648ULL: goto x86_l_21c8;
	case 8654ULL: goto x86_l_21ce;
	case 8658ULL: goto x86_l_21d2;
	case 8661ULL: goto x86_l_21d5;
	case 8665ULL: goto x86_l_21d9;
	case 8671ULL: goto x86_l_21df;
	case 8678ULL: goto x86_l_21e6;
	case 8684ULL: goto x86_l_21ec;
	case 8688ULL: goto x86_l_21f0;
	case 8691ULL: goto x86_l_21f3;
	case 8695ULL: goto x86_l_21f7;
	case 8701ULL: goto x86_l_21fd;
	case 8708ULL: goto x86_l_2204;
	case 8714ULL: goto x86_l_220a;
	case 8718ULL: goto x86_l_220e;
	case 8721ULL: goto x86_l_2211;
	case 8725ULL: goto x86_l_2215;
	case 8731ULL: goto x86_l_221b;
	case 8738ULL: goto x86_l_2222;
	case 8744ULL: goto x86_l_2228;
	case 8748ULL: goto x86_l_222c;
	case 8751ULL: goto x86_l_222f;
	case 8755ULL: goto x86_l_2233;
	case 8761ULL: goto x86_l_2239;
	case 8768ULL: goto x86_l_2240;
	case 8774ULL: goto x86_l_2246;
	case 8778ULL: goto x86_l_224a;
	case 8781ULL: goto x86_l_224d;
	case 8785ULL: goto x86_l_2251;
	case 8791ULL: goto x86_l_2257;
	case 8798ULL: goto x86_l_225e;
	case 8804ULL: goto x86_l_2264;
	case 8808ULL: goto x86_l_2268;
	case 8811ULL: goto x86_l_226b;
	case 8815ULL: goto x86_l_226f;
	case 8821ULL: goto x86_l_2275;
	case 8828ULL: goto x86_l_227c;
	case 8834ULL: goto x86_l_2282;
	case 8838ULL: goto x86_l_2286;
	case 8841ULL: goto x86_l_2289;
	case 8845ULL: goto x86_l_228d;
	case 8851ULL: goto x86_l_2293;
	case 8858ULL: goto x86_l_229a;
	case 8864ULL: goto x86_l_22a0;
	case 8868ULL: goto x86_l_22a4;
	case 8871ULL: goto x86_l_22a7;
	case 8875ULL: goto x86_l_22ab;
	case 8881ULL: goto x86_l_22b1;
	case 8888ULL: goto x86_l_22b8;
	case 8894ULL: goto x86_l_22be;
	case 8898ULL: goto x86_l_22c2;
	case 8901ULL: goto x86_l_22c5;
	case 8905ULL: goto x86_l_22c9;
	case 8911ULL: goto x86_l_22cf;
	case 8918ULL: goto x86_l_22d6;
	case 8924ULL: goto x86_l_22dc;
	case 8928ULL: goto x86_l_22e0;
	case 8931ULL: goto x86_l_22e3;
	case 8935ULL: goto x86_l_22e7;
	case 8941ULL: goto x86_l_22ed;
	case 8948ULL: goto x86_l_22f4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c4d:
	/* 0x1c4d: ja     37f4 <generic_fexit_filter_arg+0x37f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14324ULL;
	}
x86_l_1c53:
	/* 0x1c53: mov    ecx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4126ULL);
x86_l_1c58:
	/* 0x1c58: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1c5b:
	/* 0x1c5b: jae    1d44 <generic_fexit_filter_arg+0x1d44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1d44;
	}
x86_l_1c61:
	/* 0x1c61: mov    edx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c65:
	/* 0x1c65: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1c68:
	/* 0x1c68: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1c6b:
	/* 0x1c6b: jae    1d91 <generic_fexit_filter_arg+0x1d91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1d91;
	}
x86_l_1c71:
	/* 0x1c71: cmp    DWORD PTR [rdi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c73:
	/* 0x1c73: jne    1d9e <generic_fexit_filter_arg+0x1d9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d9e;
	}
x86_l_1c79:
	/* 0x1c79: jmp    35e2 <generic_fexit_filter_arg+0x35e2> */
	return 13794ULL;
x86_l_1c7e:
	/* 0x1c7e: cmp    eax,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 40ULL);
x86_l_1c81:
	/* 0x1c81: je     1f18 <generic_fexit_filter_arg+0x1f18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f18;
	}
x86_l_1c87:
	/* 0x1c87: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1c8a:
	/* 0x1c8a: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_1c8d:
	/* 0x1c8d: je     1f42 <generic_fexit_filter_arg+0x1f42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f42;
	}
x86_l_1c93:
	/* 0x1c93: jmp    37e5 <generic_fexit_filter_arg+0x37e5> */
	return 14309ULL;
x86_l_1c98:
	/* 0x1c98: mov    ecx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3072ULL);
x86_l_1c9d:
	/* 0x1c9d: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1ca0:
	/* 0x1ca0: jae    37f4 <generic_fexit_filter_arg+0x37f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14324ULL;
	}
x86_l_1ca6:
	/* 0x1ca6: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_1ca9:
	/* 0x1ca9: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1cae:
	/* 0x1cae: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1cb2:
	/* 0x1cb2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cb7:
	/* 0x1cb7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1cbe:
	/* 0x1cbe: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1cc3:
	/* 0x1cc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cc5:
	/* 0x1cc5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cc8:
	/* 0x1cc8: je     341a <generic_fexit_filter_arg+0x341a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13338ULL;
	}
x86_l_1cce:
	/* 0x1cce: mov    rcx,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cd1:
	/* 0x1cd1: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1cd6:
	/* 0x1cd6: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1cdb:
	/* 0x1cdb: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ce0:
	/* 0x1ce0: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1ce3:
	/* 0x1ce3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1ce5:
	/* 0x1ce5: mov    ecx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ce9:
	/* 0x1ce9: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_1cec:
	/* 0x1cec: je     2f3a <generic_fexit_filter_arg+0x2f3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12090ULL;
	}
x86_l_1cf2:
	/* 0x1cf2: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1cf5:
	/* 0x1cf5: je     2fef <generic_fexit_filter_arg+0x2fef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12271ULL;
	}
x86_l_1cfb:
	/* 0x1cfb: jmp    2ffe <generic_fexit_filter_arg+0x2ffe> */
	return 12286ULL;
x86_l_1d00:
	/* 0x1d00: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1d03:
	/* 0x1d03: jne    1d0e <generic_fexit_filter_arg+0x1d0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d0e;
	}
x86_l_1d05:
	/* 0x1d05: test   QWORD PTR [rdi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d08:
	/* 0x1d08: jne    37ea <generic_fexit_filter_arg+0x37ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14314ULL;
	}
x86_l_1d0e:
	/* 0x1d0e: mov    edx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d12:
	/* 0x1d12: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1d15:
	/* 0x1d15: jb     3656 <generic_fexit_filter_arg+0x3656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13910ULL;
	}
x86_l_1d1b:
	/* 0x1d1b: mov    rsi,QWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d1f:
	/* 0x1d1f: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1d22:
	/* 0x1d22: jae    203c <generic_fexit_filter_arg+0x203c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_203c;
	}
x86_l_1d28:
	/* 0x1d28: cmp    QWORD PTR [rdi],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d2b:
	/* 0x1d2b: jne    204a <generic_fexit_filter_arg+0x204a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_204a;
	}
x86_l_1d31:
	/* 0x1d31: jmp    35e2 <generic_fexit_filter_arg+0x35e2> */
	return 13794ULL;
x86_l_1d36:
	/* 0x1d36: cmp    eax,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 42ULL);
x86_l_1d39:
	/* 0x1d39: je     1dc9 <generic_fexit_filter_arg+0x1dc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dc9;
	}
x86_l_1d3f:
	/* 0x1d3f: jmp    37ea <generic_fexit_filter_arg+0x37ea> */
	return 14314ULL;
x86_l_1d44:
	/* 0x1d44: mov    ecx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3072ULL);
x86_l_1d49:
	/* 0x1d49: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1d4c:
	/* 0x1d4c: jae    37f4 <generic_fexit_filter_arg+0x37f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14324ULL;
	}
x86_l_1d52:
	/* 0x1d52: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_1d55:
	/* 0x1d55: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1d5a:
	/* 0x1d5a: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d5e:
	/* 0x1d5e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d63:
	/* 0x1d63: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1d6a:
	/* 0x1d6a: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d6f:
	/* 0x1d6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d71:
	/* 0x1d71: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d74:
	/* 0x1d74: je     341a <generic_fexit_filter_arg+0x341a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13338ULL;
	}
x86_l_1d7a:
	/* 0x1d7a: mov    ecx,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d7d:
	/* 0x1d7d: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d82:
	/* 0x1d82: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1d87:
	/* 0x1d87: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d8c:
	/* 0x1d8c: jmp    3212 <generic_fexit_filter_arg+0x3212> */
	return 12818ULL;
x86_l_1d91:
	/* 0x1d91: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1d94:
	/* 0x1d94: jne    1d9e <generic_fexit_filter_arg+0x1d9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d9e;
	}
x86_l_1d96:
	/* 0x1d96: test   DWORD PTR [rdi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d98:
	/* 0x1d98: jne    37ea <generic_fexit_filter_arg+0x37ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14314ULL;
	}
x86_l_1d9e:
	/* 0x1d9e: mov    edx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1da2:
	/* 0x1da2: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1da5:
	/* 0x1da5: jb     3656 <generic_fexit_filter_arg+0x3656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13910ULL;
	}
x86_l_1dab:
	/* 0x1dab: mov    esi,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1daf:
	/* 0x1daf: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1db2:
	/* 0x1db2: jae    2ebe <generic_fexit_filter_arg+0x2ebe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11966ULL;
	}
x86_l_1db8:
	/* 0x1db8: cmp    DWORD PTR [rdi],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dba:
	/* 0x1dba: jne    2ecb <generic_fexit_filter_arg+0x2ecb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11979ULL;
	}
x86_l_1dc0:
	/* 0x1dc0: jmp    35e2 <generic_fexit_filter_arg+0x35e2> */
	return 13794ULL;
x86_l_1dc5:
	/* 0x1dc5: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1dc9:
	/* 0x1dc9: mov    r8d,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dcc:
	/* 0x1dcc: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1dd0:
	/* 0x1dd0: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_1dd3:
	/* 0x1dd3: jne    1de3 <generic_fexit_filter_arg+0x1de3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1de3;
	}
x86_l_1dd5:
	/* 0x1dd5: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1dd7:
	/* 0x1dd7: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_1dda:
	/* 0x1dda: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_1ddd:
	/* 0x1ddd: jne    37f4 <generic_fexit_filter_arg+0x37f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14324ULL;
	}
x86_l_1de3:
	/* 0x1de3: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_1de6:
	/* 0x1de6: ja     1fda <generic_fexit_filter_arg+0x1fda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1fda;
	}
x86_l_1dec:
	/* 0x1dec: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1dee:
	/* 0x1dee: mov    edx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 67109120ULL);
x86_l_1df3:
	/* 0x1df3: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1df7:
	/* 0x1df7: jb     2c46 <generic_fexit_filter_arg+0x2c46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11334ULL;
	}
x86_l_1dfd:
	/* 0x1dfd: mov    edx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 134218240ULL);
x86_l_1e02:
	/* 0x1e02: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1e06:
	/* 0x1e06: jb     20c9 <generic_fexit_filter_arg+0x20c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_20c9;
	}
x86_l_1e0c:
	/* 0x1e0c: movabs rdx,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 206158430208ULL);
x86_l_1e16:
	/* 0x1e16: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1e1a:
	/* 0x1e1a: jae    1fda <generic_fexit_filter_arg+0x1fda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1fda;
	}
x86_l_1e20:
	/* 0x1e20: mov    WORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1e27:
	/* 0x1e27: cmp    r8d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 144ULL);
x86_l_1e2e:
	/* 0x1e2e: jbe    3133 <generic_fexit_filter_arg+0x3133> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 12595ULL;
	}
x86_l_1e34:
	/* 0x1e34: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e37:
	/* 0x1e37: jmp    3739 <generic_fexit_filter_arg+0x3739> */
	return 14137ULL;
x86_l_1e3c:
	/* 0x1e3c: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e40:
	/* 0x1e40: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e44:
	/* 0x1e44: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1e4c:
	/* 0x1e4c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e51:
	/* 0x1e51: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1e58:
	/* 0x1e58: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e5d:
	/* 0x1e5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e5f:
	/* 0x1e5f: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e62:
	/* 0x1e62: cmp    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e67:
	/* 0x1e67: je     36c7 <generic_fexit_filter_arg+0x36c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14023ULL;
	}
x86_l_1e6d:
	/* 0x1e6d: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1e70:
	/* 0x1e70: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e73:
	/* 0x1e73: je     36c7 <generic_fexit_filter_arg+0x36c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14023ULL;
	}
x86_l_1e79:
	/* 0x1e79: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e7e:
	/* 0x1e7e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_1e85:
	/* 0x1e85: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e8a:
	/* 0x1e8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e8c:
	/* 0x1e8c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e8f:
	/* 0x1e8f: je     36c4 <generic_fexit_filter_arg+0x36c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14020ULL;
	}
x86_l_1e95:
	/* 0x1e95: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e99:
	/* 0x1e99: cmp    ecx,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_1e9f:
	/* 0x1e9f: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_1ea4:
	/* 0x1ea4: cmovb  esi,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1ea7:
	/* 0x1ea7: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_1eae:
	/* 0x1eae: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eb0:
	/* 0x1eb0: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1eb3:
	/* 0x1eb3: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1eb7:
	/* 0x1eb7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ebc:
	/* 0x1ebc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ec1:
	/* 0x1ec1: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1ec4:
	/* 0x1ec4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1ec6:
	/* 0x1ec6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ecb:
	/* 0x1ecb: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1ece:
	/* 0x1ece: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1ed1:
	/* 0x1ed1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ed3:
	/* 0x1ed3: jmp    36b8 <generic_fexit_filter_arg+0x36b8> */
	return 14008ULL;
x86_l_1ed8:
	/* 0x1ed8: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1ee0:
	/* 0x1ee0: cmp    edx,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1ee6:
	/* 0x1ee6: ja     36c4 <generic_fexit_filter_arg+0x36c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14020ULL;
	}
x86_l_1eec:
	/* 0x1eec: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1eef:
	/* 0x1eef: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1ef5:
	/* 0x1ef5: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1ef8:
	/* 0x1ef8: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1efb:
	/* 0x1efb: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1efe:
	/* 0x1efe: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_1f00:
	/* 0x1f00: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1f02:
	/* 0x1f02: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_1f05:
	/* 0x1f05: je     3009 <generic_fexit_filter_arg+0x3009> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12297ULL;
	}
x86_l_1f0b:
	/* 0x1f0b: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1f0d:
	/* 0x1f0d: jne    3009 <generic_fexit_filter_arg+0x3009> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12297ULL;
	}
x86_l_1f13:
	/* 0x1f13: jmp    3020 <generic_fexit_filter_arg+0x3020> */
	return 12320ULL;
x86_l_1f18:
	/* 0x1f18: movzx  ecx,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f1b:
	/* 0x1f1b: mov    WORD PTR [rsp+0x76],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 118ULL);
x86_l_1f20:
	/* 0x1f20: movzx  ecx,WORD PTR [rdi+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1f24:
	/* 0x1f24: mov    WORD PTR [rsp+0x70],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1f29:
	/* 0x1f29: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f2d:
	/* 0x1f2d: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f32:
	/* 0x1f32: mov    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f36:
	/* 0x1f36: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1f3b:
	/* 0x1f3b: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f40:
	/* 0x1f40: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f42:
	/* 0x1f42: mov    ecx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f46:
	/* 0x1f46: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f49:
	/* 0x1f49: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_1f4c:
	/* 0x1f4c: jle    1f70 <generic_fexit_filter_arg+0x1f70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1f70;
	}
x86_l_1f4e:
	/* 0x1f4e: cmp    ecx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 23ULL);
x86_l_1f51:
	/* 0x1f51: jg     1f9a <generic_fexit_filter_arg+0x1f9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f9a;
	}
x86_l_1f53:
	/* 0x1f53: lea    eax,[rcx-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_1f56:
	/* 0x1f56: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1f59:
	/* 0x1f59: jb     2087 <generic_fexit_filter_arg+0x2087> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2087;
	}
x86_l_1f5f:
	/* 0x1f5f: lea    eax,[rcx-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_1f62:
	/* 0x1f62: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1f65:
	/* 0x1f65: jb     207c <generic_fexit_filter_arg+0x207c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_207c;
	}
x86_l_1f6b:
	/* 0x1f6b: jmp    37e5 <generic_fexit_filter_arg+0x37e5> */
	return 14309ULL;
x86_l_1f70:
	/* 0x1f70: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_1f73:
	/* 0x1f73: jle    1fba <generic_fexit_filter_arg+0x1fba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1fba;
	}
x86_l_1f75:
	/* 0x1f75: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_1f78:
	/* 0x1f78: jg     206e <generic_fexit_filter_arg+0x206e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_206e;
	}
x86_l_1f7e:
	/* 0x1f7e: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1f81:
	/* 0x1f81: je     207c <generic_fexit_filter_arg+0x207c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_207c;
	}
x86_l_1f87:
	/* 0x1f87: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_1f8a:
	/* 0x1f8a: jne    37e5 <generic_fexit_filter_arg+0x37e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14309ULL;
	}
x86_l_1f90:
	/* 0x1f90: movzx  r15d,WORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1f95:
	/* 0x1f95: jmp    31da <generic_fexit_filter_arg+0x31da> */
	return 12762ULL;
x86_l_1f9a:
	/* 0x1f9a: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_1f9d:
	/* 0x1f9d: jg     209d <generic_fexit_filter_arg+0x209d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_209d;
	}
x86_l_1fa3:
	/* 0x1fa3: cmp    ecx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_1fa6:
	/* 0x1fa6: je     2d03 <generic_fexit_filter_arg+0x2d03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11523ULL;
	}
x86_l_1fac:
	/* 0x1fac: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_1faf:
	/* 0x1faf: je     2cf4 <generic_fexit_filter_arg+0x2cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11508ULL;
	}
x86_l_1fb5:
	/* 0x1fb5: jmp    37e5 <generic_fexit_filter_arg+0x37e5> */
	return 14309ULL;
x86_l_1fba:
	/* 0x1fba: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1fbd:
	/* 0x1fbd: je     2d03 <generic_fexit_filter_arg+0x2d03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11523ULL;
	}
x86_l_1fc3:
	/* 0x1fc3: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_1fc6:
	/* 0x1fc6: je     2cf4 <generic_fexit_filter_arg+0x2cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11508ULL;
	}
x86_l_1fcc:
	/* 0x1fcc: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_1fcf:
	/* 0x1fcf: je     2087 <generic_fexit_filter_arg+0x2087> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2087;
	}
x86_l_1fd5:
	/* 0x1fd5: jmp    37e5 <generic_fexit_filter_arg+0x37e5> */
	return 14309ULL;
x86_l_1fda:
	/* 0x1fda: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1fdd:
	/* 0x1fdd: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1fe0:
	/* 0x1fe0: jae    312b <generic_fexit_filter_arg+0x312b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12587ULL;
	}
x86_l_1fe6:
	/* 0x1fe6: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1feb:
	/* 0x1feb: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1ff3:
	/* 0x1ff3: cmp    r8d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 144ULL);
x86_l_1ffa:
	/* 0x1ffa: ja     3731 <generic_fexit_filter_arg+0x3731> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14129ULL;
	}
x86_l_2000:
	/* 0x2000: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2005:
	/* 0x2005: movzx  eax,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2009:
	/* 0x2009: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_200f:
	/* 0x200f: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_2012:
	/* 0x2012: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_2015:
	/* 0x2015: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2018:
	/* 0x2018: mov    eax,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R8, X86_WIDTH_32);
x86_l_201b:
	/* 0x201b: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_201d:
	/* 0x201d: test   r8w,r8w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_16);
x86_l_2021:
	/* 0x2021: mov    QWORD PTR [rsp+0x18],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2026:
	/* 0x2026: je     32a7 <generic_fexit_filter_arg+0x32a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12967ULL;
	}
x86_l_202c:
	/* 0x202c: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_202e:
	/* 0x202e: jne    32a7 <generic_fexit_filter_arg+0x32a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12967ULL;
	}
x86_l_2034:
	/* 0x2034: mov    edx,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_2037:
	/* 0x2037: jmp    32bf <generic_fexit_filter_arg+0x32bf> */
	return 12991ULL;
x86_l_203c:
	/* 0x203c: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_203f:
	/* 0x203f: jne    204a <generic_fexit_filter_arg+0x204a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_204a;
	}
x86_l_2041:
	/* 0x2041: test   QWORD PTR [rdi],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2044:
	/* 0x2044: jne    37ea <generic_fexit_filter_arg+0x37ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14314ULL;
	}
x86_l_204a:
	/* 0x204a: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_204d:
	/* 0x204d: jb     3656 <generic_fexit_filter_arg+0x3656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13910ULL;
	}
x86_l_2053:
	/* 0x2053: mov    rsi,QWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2057:
	/* 0x2057: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_205a:
	/* 0x205a: jae    324d <generic_fexit_filter_arg+0x324d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12877ULL;
	}
x86_l_2060:
	/* 0x2060: cmp    QWORD PTR [rdi],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2063:
	/* 0x2063: jne    325b <generic_fexit_filter_arg+0x325b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12891ULL;
	}
x86_l_2069:
	/* 0x2069: jmp    35e2 <generic_fexit_filter_arg+0x35e2> */
	return 13794ULL;
x86_l_206e:
	/* 0x206e: cmp    ecx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 18ULL);
x86_l_2071:
	/* 0x2071: je     2087 <generic_fexit_filter_arg+0x2087> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2087;
	}
x86_l_2073:
	/* 0x2073: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_2076:
	/* 0x2076: jne    37e5 <generic_fexit_filter_arg+0x37e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14309ULL;
	}
x86_l_207c:
	/* 0x207c: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2081:
	/* 0x2081: movzx  esi,WORD PTR [rdi+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2085:
	/* 0x2085: jmp    2090 <generic_fexit_filter_arg+0x2090> */
	goto x86_l_2090;
x86_l_2087:
	/* 0x2087: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_208c:
	/* 0x208c: movzx  esi,WORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_2090:
	/* 0x2090: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2092:
	/* 0x2092: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2095:
	/* 0x2095: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2098:
	/* 0x2098: jmp    2d18 <generic_fexit_filter_arg+0x2d18> */
	return 11544ULL;
x86_l_209d:
	/* 0x209d: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_20a0:
	/* 0x20a0: je     31d5 <generic_fexit_filter_arg+0x31d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12757ULL;
	}
x86_l_20a6:
	/* 0x20a6: cmp    ecx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 29ULL);
x86_l_20a9:
	/* 0x20a9: jne    37e5 <generic_fexit_filter_arg+0x37e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14309ULL;
	}
x86_l_20af:
	/* 0x20af: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_20b2:
	/* 0x20b2: jne    33cb <generic_fexit_filter_arg+0x33cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13259ULL;
	}
x86_l_20b8:
	/* 0x20b8: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_20bb:
	/* 0x20bb: jne    33d8 <generic_fexit_filter_arg+0x33d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13272ULL;
	}
x86_l_20c1:
	/* 0x20c1: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20c4:
	/* 0x20c4: jmp    33e7 <generic_fexit_filter_arg+0x33e7> */
	return 13287ULL;
x86_l_20c9:
	/* 0x20c9: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20ce:
	/* 0x20ce: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20d3:
	/* 0x20d3: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20d7:
	/* 0x20d7: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_20db:
	/* 0x20db: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_20e3:
	/* 0x20e3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20e8:
	/* 0x20e8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_20ef:
	/* 0x20ef: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_20f4:
	/* 0x20f4: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_20f7:
	/* 0x20f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20f9:
	/* 0x20f9: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_20fc:
	/* 0x20fc: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20ff:
	/* 0x20ff: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2102:
	/* 0x2102: je     3734 <generic_fexit_filter_arg+0x3734> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14132ULL;
	}
x86_l_2108:
	/* 0x2108: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_210c:
	/* 0x210c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_210f:
	/* 0x210f: je     3734 <generic_fexit_filter_arg+0x3734> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14132ULL;
	}
x86_l_2115:
	/* 0x2115: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_211a:
	/* 0x211a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_2121:
	/* 0x2121: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2126:
	/* 0x2126: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2128:
	/* 0x2128: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_212b:
	/* 0x212b: je     3731 <generic_fexit_filter_arg+0x3731> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14129ULL;
	}
x86_l_2131:
	/* 0x2131: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2136:
	/* 0x2136: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_213a:
	/* 0x213a: cmp    r13d,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 94ULL);
x86_l_213e:
	/* 0x213e: mov    ecx,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 94ULL);
x86_l_2143:
	/* 0x2143: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_2147:
	/* 0x2147: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_214a:
	/* 0x214a: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_214c:
	/* 0x214c: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2150:
	/* 0x2150: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2156:
	/* 0x2156: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_215a:
	/* 0x215a: mov    BYTE PTR [rax+0x4],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_215d:
	/* 0x215d: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_2161:
	/* 0x2161: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2167:
	/* 0x2167: lea    ecx,[r13+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_216e:
	/* 0x216e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2174:
	/* 0x2174: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2178:
	/* 0x2178: mov    BYTE PTR [rax+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_217b:
	/* 0x217b: cmp    r13,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 2ULL);
x86_l_217f:
	/* 0x217f: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2185:
	/* 0x2185: lea    ecx,[r13+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_218c:
	/* 0x218c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2192:
	/* 0x2192: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2196:
	/* 0x2196: mov    BYTE PTR [rax+0x6],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_2199:
	/* 0x2199: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_219d:
	/* 0x219d: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_21a3:
	/* 0x21a3: lea    ecx,[r13+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_21aa:
	/* 0x21aa: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21b0:
	/* 0x21b0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_21b4:
	/* 0x21b4: mov    BYTE PTR [rax+0x7],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_21b7:
	/* 0x21b7: cmp    r13,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4ULL);
x86_l_21bb:
	/* 0x21bb: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_21c1:
	/* 0x21c1: lea    ecx,[r13+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_21c8:
	/* 0x21c8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21ce:
	/* 0x21ce: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_21d2:
	/* 0x21d2: mov    BYTE PTR [rax+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21d5:
	/* 0x21d5: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_21d9:
	/* 0x21d9: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_21df:
	/* 0x21df: lea    ecx,[r13+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_21e6:
	/* 0x21e6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21ec:
	/* 0x21ec: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_21f0:
	/* 0x21f0: mov    BYTE PTR [rax+0x9],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_21f3:
	/* 0x21f3: cmp    r13,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 6ULL);
x86_l_21f7:
	/* 0x21f7: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_21fd:
	/* 0x21fd: lea    ecx,[r13+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_2204:
	/* 0x2204: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_220a:
	/* 0x220a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_220e:
	/* 0x220e: mov    BYTE PTR [rax+0xa],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_2211:
	/* 0x2211: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_2215:
	/* 0x2215: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_221b:
	/* 0x221b: lea    ecx,[r13+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_2222:
	/* 0x2222: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2228:
	/* 0x2228: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_222c:
	/* 0x222c: mov    BYTE PTR [rax+0xb],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_222f:
	/* 0x222f: cmp    r13,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 8ULL);
x86_l_2233:
	/* 0x2233: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2239:
	/* 0x2239: lea    ecx,[r13+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_2240:
	/* 0x2240: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2246:
	/* 0x2246: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_224a:
	/* 0x224a: mov    BYTE PTR [rax+0xc],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_224d:
	/* 0x224d: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_2251:
	/* 0x2251: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2257:
	/* 0x2257: lea    ecx,[r13+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_225e:
	/* 0x225e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2264:
	/* 0x2264: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2268:
	/* 0x2268: mov    BYTE PTR [rax+0xd],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_226b:
	/* 0x226b: cmp    r13,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 10ULL);
x86_l_226f:
	/* 0x226f: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2275:
	/* 0x2275: lea    ecx,[r13+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_227c:
	/* 0x227c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2282:
	/* 0x2282: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2286:
	/* 0x2286: mov    BYTE PTR [rax+0xe],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_2289:
	/* 0x2289: cmp    r13,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 11ULL);
x86_l_228d:
	/* 0x228d: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2293:
	/* 0x2293: lea    ecx,[r13+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_229a:
	/* 0x229a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22a0:
	/* 0x22a0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_22a4:
	/* 0x22a4: mov    BYTE PTR [rax+0xf],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_22a7:
	/* 0x22a7: cmp    r13,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 12ULL);
x86_l_22ab:
	/* 0x22ab: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_22b1:
	/* 0x22b1: lea    ecx,[r13+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_22b8:
	/* 0x22b8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22be:
	/* 0x22be: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_22c2:
	/* 0x22c2: mov    BYTE PTR [rax+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22c5:
	/* 0x22c5: cmp    r13,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 13ULL);
x86_l_22c9:
	/* 0x22c9: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_22cf:
	/* 0x22cf: lea    ecx,[r13+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_22d6:
	/* 0x22d6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22dc:
	/* 0x22dc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_22e0:
	/* 0x22e0: mov    BYTE PTR [rax+0x11],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_22e3:
	/* 0x22e3: cmp    r13,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 14ULL);
x86_l_22e7:
	/* 0x22e7: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_22ed:
	/* 0x22ed: lea    ecx,[r13+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_22f4:
	/* 0x22f4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
	return 8954ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8954ULL: goto x86_l_22fa;
	case 8958ULL: goto x86_l_22fe;
	case 8961ULL: goto x86_l_2301;
	case 8965ULL: goto x86_l_2305;
	case 8971ULL: goto x86_l_230b;
	case 8978ULL: goto x86_l_2312;
	case 8984ULL: goto x86_l_2318;
	case 8988ULL: goto x86_l_231c;
	case 8991ULL: goto x86_l_231f;
	case 8995ULL: goto x86_l_2323;
	case 9001ULL: goto x86_l_2329;
	case 9008ULL: goto x86_l_2330;
	case 9014ULL: goto x86_l_2336;
	case 9018ULL: goto x86_l_233a;
	case 9021ULL: goto x86_l_233d;
	case 9025ULL: goto x86_l_2341;
	case 9031ULL: goto x86_l_2347;
	case 9038ULL: goto x86_l_234e;
	case 9044ULL: goto x86_l_2354;
	case 9048ULL: goto x86_l_2358;
	case 9051ULL: goto x86_l_235b;
	case 9055ULL: goto x86_l_235f;
	case 9061ULL: goto x86_l_2365;
	case 9068ULL: goto x86_l_236c;
	case 9074ULL: goto x86_l_2372;
	case 9078ULL: goto x86_l_2376;
	case 9081ULL: goto x86_l_2379;
	case 9085ULL: goto x86_l_237d;
	case 9091ULL: goto x86_l_2383;
	case 9098ULL: goto x86_l_238a;
	case 9104ULL: goto x86_l_2390;
	case 9108ULL: goto x86_l_2394;
	case 9111ULL: goto x86_l_2397;
	case 9115ULL: goto x86_l_239b;
	case 9121ULL: goto x86_l_23a1;
	case 9128ULL: goto x86_l_23a8;
	case 9134ULL: goto x86_l_23ae;
	case 9138ULL: goto x86_l_23b2;
	case 9141ULL: goto x86_l_23b5;
	case 9145ULL: goto x86_l_23b9;
	case 9151ULL: goto x86_l_23bf;
	case 9158ULL: goto x86_l_23c6;
	case 9164ULL: goto x86_l_23cc;
	case 9168ULL: goto x86_l_23d0;
	case 9171ULL: goto x86_l_23d3;
	case 9175ULL: goto x86_l_23d7;
	case 9181ULL: goto x86_l_23dd;
	case 9188ULL: goto x86_l_23e4;
	case 9194ULL: goto x86_l_23ea;
	case 9198ULL: goto x86_l_23ee;
	case 9201ULL: goto x86_l_23f1;
	case 9205ULL: goto x86_l_23f5;
	case 9211ULL: goto x86_l_23fb;
	case 9218ULL: goto x86_l_2402;
	case 9224ULL: goto x86_l_2408;
	case 9228ULL: goto x86_l_240c;
	case 9231ULL: goto x86_l_240f;
	case 9235ULL: goto x86_l_2413;
	case 9241ULL: goto x86_l_2419;
	case 9248ULL: goto x86_l_2420;
	case 9254ULL: goto x86_l_2426;
	case 9258ULL: goto x86_l_242a;
	case 9261ULL: goto x86_l_242d;
	case 9265ULL: goto x86_l_2431;
	case 9271ULL: goto x86_l_2437;
	case 9278ULL: goto x86_l_243e;
	case 9284ULL: goto x86_l_2444;
	case 9288ULL: goto x86_l_2448;
	case 9291ULL: goto x86_l_244b;
	case 9295ULL: goto x86_l_244f;
	case 9301ULL: goto x86_l_2455;
	case 9308ULL: goto x86_l_245c;
	case 9314ULL: goto x86_l_2462;
	case 9318ULL: goto x86_l_2466;
	case 9321ULL: goto x86_l_2469;
	case 9325ULL: goto x86_l_246d;
	case 9331ULL: goto x86_l_2473;
	case 9338ULL: goto x86_l_247a;
	case 9344ULL: goto x86_l_2480;
	case 9348ULL: goto x86_l_2484;
	case 9351ULL: goto x86_l_2487;
	case 9355ULL: goto x86_l_248b;
	case 9361ULL: goto x86_l_2491;
	case 9368ULL: goto x86_l_2498;
	case 9374ULL: goto x86_l_249e;
	case 9378ULL: goto x86_l_24a2;
	case 9381ULL: goto x86_l_24a5;
	case 9385ULL: goto x86_l_24a9;
	case 9391ULL: goto x86_l_24af;
	case 9398ULL: goto x86_l_24b6;
	case 9404ULL: goto x86_l_24bc;
	case 9408ULL: goto x86_l_24c0;
	case 9411ULL: goto x86_l_24c3;
	case 9415ULL: goto x86_l_24c7;
	case 9421ULL: goto x86_l_24cd;
	case 9428ULL: goto x86_l_24d4;
	case 9434ULL: goto x86_l_24da;
	case 9438ULL: goto x86_l_24de;
	case 9441ULL: goto x86_l_24e1;
	case 9445ULL: goto x86_l_24e5;
	case 9451ULL: goto x86_l_24eb;
	case 9458ULL: goto x86_l_24f2;
	case 9464ULL: goto x86_l_24f8;
	case 9468ULL: goto x86_l_24fc;
	case 9471ULL: goto x86_l_24ff;
	case 9475ULL: goto x86_l_2503;
	case 9481ULL: goto x86_l_2509;
	case 9488ULL: goto x86_l_2510;
	case 9494ULL: goto x86_l_2516;
	case 9498ULL: goto x86_l_251a;
	case 9501ULL: goto x86_l_251d;
	case 9505ULL: goto x86_l_2521;
	case 9511ULL: goto x86_l_2527;
	case 9518ULL: goto x86_l_252e;
	case 9524ULL: goto x86_l_2534;
	case 9528ULL: goto x86_l_2538;
	case 9531ULL: goto x86_l_253b;
	case 9535ULL: goto x86_l_253f;
	case 9541ULL: goto x86_l_2545;
	case 9548ULL: goto x86_l_254c;
	case 9554ULL: goto x86_l_2552;
	case 9558ULL: goto x86_l_2556;
	case 9561ULL: goto x86_l_2559;
	case 9565ULL: goto x86_l_255d;
	case 9571ULL: goto x86_l_2563;
	case 9578ULL: goto x86_l_256a;
	case 9584ULL: goto x86_l_2570;
	case 9588ULL: goto x86_l_2574;
	case 9591ULL: goto x86_l_2577;
	case 9595ULL: goto x86_l_257b;
	case 9601ULL: goto x86_l_2581;
	case 9608ULL: goto x86_l_2588;
	case 9614ULL: goto x86_l_258e;
	case 9618ULL: goto x86_l_2592;
	case 9621ULL: goto x86_l_2595;
	case 9625ULL: goto x86_l_2599;
	case 9631ULL: goto x86_l_259f;
	case 9638ULL: goto x86_l_25a6;
	case 9644ULL: goto x86_l_25ac;
	case 9648ULL: goto x86_l_25b0;
	case 9651ULL: goto x86_l_25b3;
	case 9655ULL: goto x86_l_25b7;
	case 9661ULL: goto x86_l_25bd;
	case 9668ULL: goto x86_l_25c4;
	case 9674ULL: goto x86_l_25ca;
	case 9678ULL: goto x86_l_25ce;
	case 9681ULL: goto x86_l_25d1;
	case 9685ULL: goto x86_l_25d5;
	case 9691ULL: goto x86_l_25db;
	case 9698ULL: goto x86_l_25e2;
	case 9704ULL: goto x86_l_25e8;
	case 9708ULL: goto x86_l_25ec;
	case 9711ULL: goto x86_l_25ef;
	case 9715ULL: goto x86_l_25f3;
	case 9721ULL: goto x86_l_25f9;
	case 9728ULL: goto x86_l_2600;
	case 9734ULL: goto x86_l_2606;
	case 9738ULL: goto x86_l_260a;
	case 9741ULL: goto x86_l_260d;
	case 9745ULL: goto x86_l_2611;
	case 9751ULL: goto x86_l_2617;
	case 9758ULL: goto x86_l_261e;
	case 9764ULL: goto x86_l_2624;
	case 9768ULL: goto x86_l_2628;
	case 9771ULL: goto x86_l_262b;
	case 9775ULL: goto x86_l_262f;
	case 9781ULL: goto x86_l_2635;
	case 9788ULL: goto x86_l_263c;
	case 9794ULL: goto x86_l_2642;
	case 9798ULL: goto x86_l_2646;
	case 9801ULL: goto x86_l_2649;
	case 9805ULL: goto x86_l_264d;
	case 9811ULL: goto x86_l_2653;
	case 9818ULL: goto x86_l_265a;
	case 9824ULL: goto x86_l_2660;
	case 9828ULL: goto x86_l_2664;
	case 9831ULL: goto x86_l_2667;
	case 9835ULL: goto x86_l_266b;
	case 9841ULL: goto x86_l_2671;
	case 9848ULL: goto x86_l_2678;
	case 9854ULL: goto x86_l_267e;
	case 9858ULL: goto x86_l_2682;
	case 9861ULL: goto x86_l_2685;
	case 9865ULL: goto x86_l_2689;
	case 9871ULL: goto x86_l_268f;
	case 9878ULL: goto x86_l_2696;
	case 9884ULL: goto x86_l_269c;
	case 9888ULL: goto x86_l_26a0;
	case 9891ULL: goto x86_l_26a3;
	case 9895ULL: goto x86_l_26a7;
	case 9901ULL: goto x86_l_26ad;
	case 9908ULL: goto x86_l_26b4;
	case 9914ULL: goto x86_l_26ba;
	case 9918ULL: goto x86_l_26be;
	case 9921ULL: goto x86_l_26c1;
	case 9925ULL: goto x86_l_26c5;
	case 9931ULL: goto x86_l_26cb;
	case 9938ULL: goto x86_l_26d2;
	case 9944ULL: goto x86_l_26d8;
	case 9948ULL: goto x86_l_26dc;
	case 9951ULL: goto x86_l_26df;
	case 9955ULL: goto x86_l_26e3;
	case 9961ULL: goto x86_l_26e9;
	case 9968ULL: goto x86_l_26f0;
	case 9974ULL: goto x86_l_26f6;
	case 9978ULL: goto x86_l_26fa;
	case 9981ULL: goto x86_l_26fd;
	case 9985ULL: goto x86_l_2701;
	case 9991ULL: goto x86_l_2707;
	case 9998ULL: goto x86_l_270e;
	case 10004ULL: goto x86_l_2714;
	case 10008ULL: goto x86_l_2718;
	case 10011ULL: goto x86_l_271b;
	case 10015ULL: goto x86_l_271f;
	case 10021ULL: goto x86_l_2725;
	case 10028ULL: goto x86_l_272c;
	case 10034ULL: goto x86_l_2732;
	case 10038ULL: goto x86_l_2736;
	case 10041ULL: goto x86_l_2739;
	case 10045ULL: goto x86_l_273d;
	case 10051ULL: goto x86_l_2743;
	case 10058ULL: goto x86_l_274a;
	case 10064ULL: goto x86_l_2750;
	case 10068ULL: goto x86_l_2754;
	case 10071ULL: goto x86_l_2757;
	case 10075ULL: goto x86_l_275b;
	case 10081ULL: goto x86_l_2761;
	case 10088ULL: goto x86_l_2768;
	case 10094ULL: goto x86_l_276e;
	case 10098ULL: goto x86_l_2772;
	case 10101ULL: goto x86_l_2775;
	case 10105ULL: goto x86_l_2779;
	case 10111ULL: goto x86_l_277f;
	case 10118ULL: goto x86_l_2786;
	case 10124ULL: goto x86_l_278c;
	case 10128ULL: goto x86_l_2790;
	case 10131ULL: goto x86_l_2793;
	case 10135ULL: goto x86_l_2797;
	case 10141ULL: goto x86_l_279d;
	case 10148ULL: goto x86_l_27a4;
	case 10154ULL: goto x86_l_27aa;
	case 10158ULL: goto x86_l_27ae;
	case 10161ULL: goto x86_l_27b1;
	case 10165ULL: goto x86_l_27b5;
	case 10171ULL: goto x86_l_27bb;
	case 10178ULL: goto x86_l_27c2;
	case 10184ULL: goto x86_l_27c8;
	case 10188ULL: goto x86_l_27cc;
	case 10191ULL: goto x86_l_27cf;
	case 10195ULL: goto x86_l_27d3;
	case 10201ULL: goto x86_l_27d9;
	case 10208ULL: goto x86_l_27e0;
	case 10214ULL: goto x86_l_27e6;
	case 10218ULL: goto x86_l_27ea;
	case 10221ULL: goto x86_l_27ed;
	case 10225ULL: goto x86_l_27f1;
	case 10231ULL: goto x86_l_27f7;
	case 10238ULL: goto x86_l_27fe;
	case 10244ULL: goto x86_l_2804;
	case 10248ULL: goto x86_l_2808;
	case 10251ULL: goto x86_l_280b;
	case 10255ULL: goto x86_l_280f;
	case 10261ULL: goto x86_l_2815;
	case 10268ULL: goto x86_l_281c;
	case 10274ULL: goto x86_l_2822;
	case 10278ULL: goto x86_l_2826;
	case 10281ULL: goto x86_l_2829;
	case 10285ULL: goto x86_l_282d;
	case 10291ULL: goto x86_l_2833;
	case 10298ULL: goto x86_l_283a;
	case 10304ULL: goto x86_l_2840;
	case 10308ULL: goto x86_l_2844;
	case 10311ULL: goto x86_l_2847;
	case 10315ULL: goto x86_l_284b;
	case 10321ULL: goto x86_l_2851;
	case 10328ULL: goto x86_l_2858;
	case 10334ULL: goto x86_l_285e;
	case 10338ULL: goto x86_l_2862;
	case 10341ULL: goto x86_l_2865;
	case 10345ULL: goto x86_l_2869;
	case 10351ULL: goto x86_l_286f;
	case 10358ULL: goto x86_l_2876;
	case 10364ULL: goto x86_l_287c;
	case 10368ULL: goto x86_l_2880;
	case 10371ULL: goto x86_l_2883;
	case 10375ULL: goto x86_l_2887;
	case 10381ULL: goto x86_l_288d;
	case 10388ULL: goto x86_l_2894;
	case 10394ULL: goto x86_l_289a;
	case 10398ULL: goto x86_l_289e;
	case 10401ULL: goto x86_l_28a1;
	case 10405ULL: goto x86_l_28a5;
	case 10411ULL: goto x86_l_28ab;
	case 10418ULL: goto x86_l_28b2;
	case 10424ULL: goto x86_l_28b8;
	case 10428ULL: goto x86_l_28bc;
	case 10431ULL: goto x86_l_28bf;
	case 10435ULL: goto x86_l_28c3;
	case 10441ULL: goto x86_l_28c9;
	case 10448ULL: goto x86_l_28d0;
	case 10454ULL: goto x86_l_28d6;
	case 10458ULL: goto x86_l_28da;
	case 10461ULL: goto x86_l_28dd;
	case 10465ULL: goto x86_l_28e1;
	case 10471ULL: goto x86_l_28e7;
	case 10478ULL: goto x86_l_28ee;
	case 10484ULL: goto x86_l_28f4;
	case 10488ULL: goto x86_l_28f8;
	case 10491ULL: goto x86_l_28fb;
	case 10495ULL: goto x86_l_28ff;
	case 10501ULL: goto x86_l_2905;
	case 10508ULL: goto x86_l_290c;
	case 10514ULL: goto x86_l_2912;
	case 10518ULL: goto x86_l_2916;
	case 10521ULL: goto x86_l_2919;
	case 10525ULL: goto x86_l_291d;
	case 10531ULL: goto x86_l_2923;
	case 10538ULL: goto x86_l_292a;
	case 10544ULL: goto x86_l_2930;
	case 10548ULL: goto x86_l_2934;
	case 10551ULL: goto x86_l_2937;
	case 10555ULL: goto x86_l_293b;
	case 10561ULL: goto x86_l_2941;
	case 10568ULL: goto x86_l_2948;
	case 10574ULL: goto x86_l_294e;
	case 10578ULL: goto x86_l_2952;
	case 10581ULL: goto x86_l_2955;
	case 10585ULL: goto x86_l_2959;
	case 10591ULL: goto x86_l_295f;
	case 10598ULL: goto x86_l_2966;
	case 10604ULL: goto x86_l_296c;
	case 10608ULL: goto x86_l_2970;
	case 10611ULL: goto x86_l_2973;
	case 10615ULL: goto x86_l_2977;
	case 10621ULL: goto x86_l_297d;
	case 10628ULL: goto x86_l_2984;
	case 10634ULL: goto x86_l_298a;
	case 10638ULL: goto x86_l_298e;
	case 10641ULL: goto x86_l_2991;
	case 10645ULL: goto x86_l_2995;
	case 10651ULL: goto x86_l_299b;
	case 10658ULL: goto x86_l_29a2;
	case 10664ULL: goto x86_l_29a8;
	case 10668ULL: goto x86_l_29ac;
	case 10671ULL: goto x86_l_29af;
	case 10675ULL: goto x86_l_29b3;
	case 10681ULL: goto x86_l_29b9;
	case 10688ULL: goto x86_l_29c0;
	case 10694ULL: goto x86_l_29c6;
	case 10698ULL: goto x86_l_29ca;
	case 10701ULL: goto x86_l_29cd;
	case 10705ULL: goto x86_l_29d1;
	case 10711ULL: goto x86_l_29d7;
	case 10718ULL: goto x86_l_29de;
	case 10724ULL: goto x86_l_29e4;
	case 10728ULL: goto x86_l_29e8;
	case 10731ULL: goto x86_l_29eb;
	case 10735ULL: goto x86_l_29ef;
	case 10741ULL: goto x86_l_29f5;
	case 10748ULL: goto x86_l_29fc;
	case 10754ULL: goto x86_l_2a02;
	case 10758ULL: goto x86_l_2a06;
	case 10761ULL: goto x86_l_2a09;
	case 10765ULL: goto x86_l_2a0d;
	case 10771ULL: goto x86_l_2a13;
	case 10778ULL: goto x86_l_2a1a;
	case 10784ULL: goto x86_l_2a20;
	case 10788ULL: goto x86_l_2a24;
	case 10791ULL: goto x86_l_2a27;
	case 10795ULL: goto x86_l_2a2b;
	case 10801ULL: goto x86_l_2a31;
	case 10808ULL: goto x86_l_2a38;
	case 10814ULL: goto x86_l_2a3e;
	case 10818ULL: goto x86_l_2a42;
	case 10821ULL: goto x86_l_2a45;
	case 10825ULL: goto x86_l_2a49;
	case 10831ULL: goto x86_l_2a4f;
	case 10838ULL: goto x86_l_2a56;
	case 10844ULL: goto x86_l_2a5c;
	case 10848ULL: goto x86_l_2a60;
	case 10851ULL: goto x86_l_2a63;
	case 10855ULL: goto x86_l_2a67;
	case 10861ULL: goto x86_l_2a6d;
	case 10868ULL: goto x86_l_2a74;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22fa:
	/* 0x22fa: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_22fe:
	/* 0x22fe: mov    BYTE PTR [rax+0x12],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_2301:
	/* 0x2301: cmp    r13,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 15ULL);
x86_l_2305:
	/* 0x2305: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_230b:
	/* 0x230b: lea    ecx,[r13+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_2312:
	/* 0x2312: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2318:
	/* 0x2318: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_231c:
	/* 0x231c: mov    BYTE PTR [rax+0x13],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_231f:
	/* 0x231f: cmp    r13,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 16ULL);
x86_l_2323:
	/* 0x2323: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2329:
	/* 0x2329: lea    ecx,[r13+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_2330:
	/* 0x2330: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2336:
	/* 0x2336: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_233a:
	/* 0x233a: mov    BYTE PTR [rax+0x14],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_233d:
	/* 0x233d: cmp    r13,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 17ULL);
x86_l_2341:
	/* 0x2341: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2347:
	/* 0x2347: lea    ecx,[r13+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_234e:
	/* 0x234e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2354:
	/* 0x2354: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2358:
	/* 0x2358: mov    BYTE PTR [rax+0x15],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_235b:
	/* 0x235b: cmp    r13,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18ULL);
x86_l_235f:
	/* 0x235f: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2365:
	/* 0x2365: lea    ecx,[r13+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_236c:
	/* 0x236c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2372:
	/* 0x2372: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2376:
	/* 0x2376: mov    BYTE PTR [rax+0x16],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_2379:
	/* 0x2379: cmp    r13,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 19ULL);
x86_l_237d:
	/* 0x237d: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2383:
	/* 0x2383: lea    ecx,[r13+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_238a:
	/* 0x238a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2390:
	/* 0x2390: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2394:
	/* 0x2394: mov    BYTE PTR [rax+0x17],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_2397:
	/* 0x2397: cmp    r13,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 20ULL);
x86_l_239b:
	/* 0x239b: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_23a1:
	/* 0x23a1: lea    ecx,[r13+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_23a8:
	/* 0x23a8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23ae:
	/* 0x23ae: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_23b2:
	/* 0x23b2: mov    BYTE PTR [rax+0x18],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23b5:
	/* 0x23b5: cmp    r13,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 21ULL);
x86_l_23b9:
	/* 0x23b9: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_23bf:
	/* 0x23bf: lea    ecx,[r13+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_23c6:
	/* 0x23c6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23cc:
	/* 0x23cc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_23d0:
	/* 0x23d0: mov    BYTE PTR [rax+0x19],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_23d3:
	/* 0x23d3: cmp    r13,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 22ULL);
x86_l_23d7:
	/* 0x23d7: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_23dd:
	/* 0x23dd: lea    ecx,[r13+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_23e4:
	/* 0x23e4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23ea:
	/* 0x23ea: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_23ee:
	/* 0x23ee: mov    BYTE PTR [rax+0x1a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_23f1:
	/* 0x23f1: cmp    r13,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 23ULL);
x86_l_23f5:
	/* 0x23f5: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_23fb:
	/* 0x23fb: lea    ecx,[r13+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_2402:
	/* 0x2402: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2408:
	/* 0x2408: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_240c:
	/* 0x240c: mov    BYTE PTR [rax+0x1b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_240f:
	/* 0x240f: cmp    r13,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 24ULL);
x86_l_2413:
	/* 0x2413: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2419:
	/* 0x2419: lea    ecx,[r13+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_2420:
	/* 0x2420: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2426:
	/* 0x2426: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_242a:
	/* 0x242a: mov    BYTE PTR [rax+0x1c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_242d:
	/* 0x242d: cmp    r13,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 25ULL);
x86_l_2431:
	/* 0x2431: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2437:
	/* 0x2437: lea    ecx,[r13+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_243e:
	/* 0x243e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2444:
	/* 0x2444: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2448:
	/* 0x2448: mov    BYTE PTR [rax+0x1d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_244b:
	/* 0x244b: cmp    r13,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 26ULL);
x86_l_244f:
	/* 0x244f: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2455:
	/* 0x2455: lea    ecx,[r13+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_245c:
	/* 0x245c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2462:
	/* 0x2462: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2466:
	/* 0x2466: mov    BYTE PTR [rax+0x1e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_2469:
	/* 0x2469: cmp    r13,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 27ULL);
x86_l_246d:
	/* 0x246d: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2473:
	/* 0x2473: lea    ecx,[r13+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_247a:
	/* 0x247a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2480:
	/* 0x2480: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2484:
	/* 0x2484: mov    BYTE PTR [rax+0x1f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_2487:
	/* 0x2487: cmp    r13,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 28ULL);
x86_l_248b:
	/* 0x248b: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2491:
	/* 0x2491: lea    ecx,[r13+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_2498:
	/* 0x2498: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_249e:
	/* 0x249e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_24a2:
	/* 0x24a2: mov    BYTE PTR [rax+0x20],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24a5:
	/* 0x24a5: cmp    r13,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 29ULL);
x86_l_24a9:
	/* 0x24a9: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_24af:
	/* 0x24af: lea    ecx,[r13+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_24b6:
	/* 0x24b6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24bc:
	/* 0x24bc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_24c0:
	/* 0x24c0: mov    BYTE PTR [rax+0x21],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_24c3:
	/* 0x24c3: cmp    r13,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 30ULL);
x86_l_24c7:
	/* 0x24c7: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_24cd:
	/* 0x24cd: lea    ecx,[r13+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_24d4:
	/* 0x24d4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24da:
	/* 0x24da: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_24de:
	/* 0x24de: mov    BYTE PTR [rax+0x22],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_24e1:
	/* 0x24e1: cmp    r13,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 31ULL);
x86_l_24e5:
	/* 0x24e5: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_24eb:
	/* 0x24eb: lea    ecx,[r13+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_24f2:
	/* 0x24f2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24f8:
	/* 0x24f8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_24fc:
	/* 0x24fc: mov    BYTE PTR [rax+0x23],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_24ff:
	/* 0x24ff: cmp    r13,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 32ULL);
x86_l_2503:
	/* 0x2503: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2509:
	/* 0x2509: lea    ecx,[r13+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_2510:
	/* 0x2510: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2516:
	/* 0x2516: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_251a:
	/* 0x251a: mov    BYTE PTR [rax+0x24],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_251d:
	/* 0x251d: cmp    r13,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 33ULL);
x86_l_2521:
	/* 0x2521: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2527:
	/* 0x2527: lea    ecx,[r13+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_252e:
	/* 0x252e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2534:
	/* 0x2534: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2538:
	/* 0x2538: mov    BYTE PTR [rax+0x25],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_253b:
	/* 0x253b: cmp    r13,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 34ULL);
x86_l_253f:
	/* 0x253f: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2545:
	/* 0x2545: lea    ecx,[r13+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_254c:
	/* 0x254c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2552:
	/* 0x2552: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2556:
	/* 0x2556: mov    BYTE PTR [rax+0x26],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_2559:
	/* 0x2559: cmp    r13,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 35ULL);
x86_l_255d:
	/* 0x255d: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2563:
	/* 0x2563: lea    ecx,[r13+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_256a:
	/* 0x256a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2570:
	/* 0x2570: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2574:
	/* 0x2574: mov    BYTE PTR [rax+0x27],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_2577:
	/* 0x2577: cmp    r13,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 36ULL);
x86_l_257b:
	/* 0x257b: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2581:
	/* 0x2581: lea    ecx,[r13+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_2588:
	/* 0x2588: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_258e:
	/* 0x258e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2592:
	/* 0x2592: mov    BYTE PTR [rax+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2595:
	/* 0x2595: cmp    r13,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 37ULL);
x86_l_2599:
	/* 0x2599: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_259f:
	/* 0x259f: lea    ecx,[r13+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_25a6:
	/* 0x25a6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25ac:
	/* 0x25ac: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_25b0:
	/* 0x25b0: mov    BYTE PTR [rax+0x29],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_25b3:
	/* 0x25b3: cmp    r13,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 38ULL);
x86_l_25b7:
	/* 0x25b7: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_25bd:
	/* 0x25bd: lea    ecx,[r13+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_25c4:
	/* 0x25c4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25ca:
	/* 0x25ca: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_25ce:
	/* 0x25ce: mov    BYTE PTR [rax+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_25d1:
	/* 0x25d1: cmp    r13,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 39ULL);
x86_l_25d5:
	/* 0x25d5: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_25db:
	/* 0x25db: lea    ecx,[r13+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_25e2:
	/* 0x25e2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25e8:
	/* 0x25e8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_25ec:
	/* 0x25ec: mov    BYTE PTR [rax+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_25ef:
	/* 0x25ef: cmp    r13,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 40ULL);
x86_l_25f3:
	/* 0x25f3: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_25f9:
	/* 0x25f9: lea    ecx,[r13+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_2600:
	/* 0x2600: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2606:
	/* 0x2606: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_260a:
	/* 0x260a: mov    BYTE PTR [rax+0x2c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_260d:
	/* 0x260d: cmp    r13,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 41ULL);
x86_l_2611:
	/* 0x2611: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2617:
	/* 0x2617: lea    ecx,[r13+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_261e:
	/* 0x261e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2624:
	/* 0x2624: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2628:
	/* 0x2628: mov    BYTE PTR [rax+0x2d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_262b:
	/* 0x262b: cmp    r13,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 42ULL);
x86_l_262f:
	/* 0x262f: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2635:
	/* 0x2635: lea    ecx,[r13+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_263c:
	/* 0x263c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2642:
	/* 0x2642: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2646:
	/* 0x2646: mov    BYTE PTR [rax+0x2e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_2649:
	/* 0x2649: cmp    r13,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 43ULL);
x86_l_264d:
	/* 0x264d: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2653:
	/* 0x2653: lea    ecx,[r13+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_265a:
	/* 0x265a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2660:
	/* 0x2660: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2664:
	/* 0x2664: mov    BYTE PTR [rax+0x2f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_2667:
	/* 0x2667: cmp    r13,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 44ULL);
x86_l_266b:
	/* 0x266b: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2671:
	/* 0x2671: lea    ecx,[r13+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_2678:
	/* 0x2678: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_267e:
	/* 0x267e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2682:
	/* 0x2682: mov    BYTE PTR [rax+0x30],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2685:
	/* 0x2685: cmp    r13,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 45ULL);
x86_l_2689:
	/* 0x2689: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_268f:
	/* 0x268f: lea    ecx,[r13+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_2696:
	/* 0x2696: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_269c:
	/* 0x269c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_26a0:
	/* 0x26a0: mov    BYTE PTR [rax+0x31],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_26a3:
	/* 0x26a3: cmp    r13,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 46ULL);
x86_l_26a7:
	/* 0x26a7: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_26ad:
	/* 0x26ad: lea    ecx,[r13+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_26b4:
	/* 0x26b4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26ba:
	/* 0x26ba: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_26be:
	/* 0x26be: mov    BYTE PTR [rax+0x32],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_26c1:
	/* 0x26c1: cmp    r13,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 47ULL);
x86_l_26c5:
	/* 0x26c5: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_26cb:
	/* 0x26cb: lea    ecx,[r13+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_26d2:
	/* 0x26d2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26d8:
	/* 0x26d8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_26dc:
	/* 0x26dc: mov    BYTE PTR [rax+0x33],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_26df:
	/* 0x26df: cmp    r13,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 48ULL);
x86_l_26e3:
	/* 0x26e3: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_26e9:
	/* 0x26e9: lea    ecx,[r13+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_26f0:
	/* 0x26f0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26f6:
	/* 0x26f6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_26fa:
	/* 0x26fa: mov    BYTE PTR [rax+0x34],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_26fd:
	/* 0x26fd: cmp    r13,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 49ULL);
x86_l_2701:
	/* 0x2701: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2707:
	/* 0x2707: lea    ecx,[r13+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_270e:
	/* 0x270e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2714:
	/* 0x2714: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2718:
	/* 0x2718: mov    BYTE PTR [rax+0x35],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_271b:
	/* 0x271b: cmp    r13,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 50ULL);
x86_l_271f:
	/* 0x271f: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2725:
	/* 0x2725: lea    ecx,[r13+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_272c:
	/* 0x272c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2732:
	/* 0x2732: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2736:
	/* 0x2736: mov    BYTE PTR [rax+0x36],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_2739:
	/* 0x2739: cmp    r13,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 51ULL);
x86_l_273d:
	/* 0x273d: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2743:
	/* 0x2743: lea    ecx,[r13+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_274a:
	/* 0x274a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2750:
	/* 0x2750: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2754:
	/* 0x2754: mov    BYTE PTR [rax+0x37],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_2757:
	/* 0x2757: cmp    r13,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 52ULL);
x86_l_275b:
	/* 0x275b: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2761:
	/* 0x2761: lea    ecx,[r13+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_2768:
	/* 0x2768: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_276e:
	/* 0x276e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2772:
	/* 0x2772: mov    BYTE PTR [rax+0x38],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2775:
	/* 0x2775: cmp    r13,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 53ULL);
x86_l_2779:
	/* 0x2779: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_277f:
	/* 0x277f: lea    ecx,[r13+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_2786:
	/* 0x2786: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_278c:
	/* 0x278c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2790:
	/* 0x2790: mov    BYTE PTR [rax+0x39],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_2793:
	/* 0x2793: cmp    r13,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 54ULL);
x86_l_2797:
	/* 0x2797: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_279d:
	/* 0x279d: lea    ecx,[r13+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_27a4:
	/* 0x27a4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27aa:
	/* 0x27aa: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_27ae:
	/* 0x27ae: mov    BYTE PTR [rax+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_27b1:
	/* 0x27b1: cmp    r13,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 55ULL);
x86_l_27b5:
	/* 0x27b5: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_27bb:
	/* 0x27bb: lea    ecx,[r13+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_27c2:
	/* 0x27c2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27c8:
	/* 0x27c8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_27cc:
	/* 0x27cc: mov    BYTE PTR [rax+0x3b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_27cf:
	/* 0x27cf: cmp    r13,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 56ULL);
x86_l_27d3:
	/* 0x27d3: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_27d9:
	/* 0x27d9: lea    ecx,[r13+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_27e0:
	/* 0x27e0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27e6:
	/* 0x27e6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_27ea:
	/* 0x27ea: mov    BYTE PTR [rax+0x3c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_27ed:
	/* 0x27ed: cmp    r13,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 57ULL);
x86_l_27f1:
	/* 0x27f1: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_27f7:
	/* 0x27f7: lea    ecx,[r13+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_27fe:
	/* 0x27fe: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2804:
	/* 0x2804: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2808:
	/* 0x2808: mov    BYTE PTR [rax+0x3d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_280b:
	/* 0x280b: cmp    r13,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 58ULL);
x86_l_280f:
	/* 0x280f: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2815:
	/* 0x2815: lea    ecx,[r13+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_281c:
	/* 0x281c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2822:
	/* 0x2822: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2826:
	/* 0x2826: mov    BYTE PTR [rax+0x3e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_2829:
	/* 0x2829: cmp    r13,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 59ULL);
x86_l_282d:
	/* 0x282d: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2833:
	/* 0x2833: lea    ecx,[r13+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_283a:
	/* 0x283a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2840:
	/* 0x2840: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2844:
	/* 0x2844: mov    BYTE PTR [rax+0x3f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_2847:
	/* 0x2847: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_284b:
	/* 0x284b: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2851:
	/* 0x2851: lea    ecx,[r13+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_2858:
	/* 0x2858: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_285e:
	/* 0x285e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2862:
	/* 0x2862: mov    BYTE PTR [rax+0x40],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2865:
	/* 0x2865: cmp    r13,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 61ULL);
x86_l_2869:
	/* 0x2869: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_286f:
	/* 0x286f: lea    ecx,[r13+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_2876:
	/* 0x2876: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_287c:
	/* 0x287c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2880:
	/* 0x2880: mov    BYTE PTR [rax+0x41],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_2883:
	/* 0x2883: cmp    r13,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 62ULL);
x86_l_2887:
	/* 0x2887: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_288d:
	/* 0x288d: lea    ecx,[r13+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_2894:
	/* 0x2894: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_289a:
	/* 0x289a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_289e:
	/* 0x289e: mov    BYTE PTR [rax+0x42],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_28a1:
	/* 0x28a1: cmp    r13,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 63ULL);
x86_l_28a5:
	/* 0x28a5: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_28ab:
	/* 0x28ab: lea    ecx,[r13+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_28b2:
	/* 0x28b2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_28b8:
	/* 0x28b8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_28bc:
	/* 0x28bc: mov    BYTE PTR [rax+0x43],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_28bf:
	/* 0x28bf: cmp    r13,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 64ULL);
x86_l_28c3:
	/* 0x28c3: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_28c9:
	/* 0x28c9: lea    ecx,[r13+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_28d0:
	/* 0x28d0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_28d6:
	/* 0x28d6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_28da:
	/* 0x28da: mov    BYTE PTR [rax+0x44],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_28dd:
	/* 0x28dd: cmp    r13,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 65ULL);
x86_l_28e1:
	/* 0x28e1: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_28e7:
	/* 0x28e7: lea    ecx,[r13+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_28ee:
	/* 0x28ee: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_28f4:
	/* 0x28f4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_28f8:
	/* 0x28f8: mov    BYTE PTR [rax+0x45],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_28fb:
	/* 0x28fb: cmp    r13,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 66ULL);
x86_l_28ff:
	/* 0x28ff: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2905:
	/* 0x2905: lea    ecx,[r13+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_290c:
	/* 0x290c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2912:
	/* 0x2912: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2916:
	/* 0x2916: mov    BYTE PTR [rax+0x46],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_2919:
	/* 0x2919: cmp    r13,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 67ULL);
x86_l_291d:
	/* 0x291d: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2923:
	/* 0x2923: lea    ecx,[r13+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_292a:
	/* 0x292a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2930:
	/* 0x2930: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2934:
	/* 0x2934: mov    BYTE PTR [rax+0x47],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_2937:
	/* 0x2937: cmp    r13,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 68ULL);
x86_l_293b:
	/* 0x293b: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2941:
	/* 0x2941: lea    ecx,[r13+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_2948:
	/* 0x2948: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_294e:
	/* 0x294e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2952:
	/* 0x2952: mov    BYTE PTR [rax+0x48],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2955:
	/* 0x2955: cmp    r13,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 69ULL);
x86_l_2959:
	/* 0x2959: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_295f:
	/* 0x295f: lea    ecx,[r13+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_2966:
	/* 0x2966: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_296c:
	/* 0x296c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2970:
	/* 0x2970: mov    BYTE PTR [rax+0x49],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_2973:
	/* 0x2973: cmp    r13,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 70ULL);
x86_l_2977:
	/* 0x2977: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_297d:
	/* 0x297d: lea    ecx,[r13+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_2984:
	/* 0x2984: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_298a:
	/* 0x298a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_298e:
	/* 0x298e: mov    BYTE PTR [rax+0x4a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_2991:
	/* 0x2991: cmp    r13,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 71ULL);
x86_l_2995:
	/* 0x2995: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_299b:
	/* 0x299b: lea    ecx,[r13+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_29a2:
	/* 0x29a2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29a8:
	/* 0x29a8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_29ac:
	/* 0x29ac: mov    BYTE PTR [rax+0x4b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_29af:
	/* 0x29af: cmp    r13,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 72ULL);
x86_l_29b3:
	/* 0x29b3: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_29b9:
	/* 0x29b9: lea    ecx,[r13+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_29c0:
	/* 0x29c0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29c6:
	/* 0x29c6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_29ca:
	/* 0x29ca: mov    BYTE PTR [rax+0x4c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_29cd:
	/* 0x29cd: cmp    r13,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 73ULL);
x86_l_29d1:
	/* 0x29d1: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_29d7:
	/* 0x29d7: lea    ecx,[r13+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_29de:
	/* 0x29de: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29e4:
	/* 0x29e4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_29e8:
	/* 0x29e8: mov    BYTE PTR [rax+0x4d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_29eb:
	/* 0x29eb: cmp    r13,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 74ULL);
x86_l_29ef:
	/* 0x29ef: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_29f5:
	/* 0x29f5: lea    ecx,[r13+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_29fc:
	/* 0x29fc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a02:
	/* 0x2a02: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a06:
	/* 0x2a06: mov    BYTE PTR [rax+0x4e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_2a09:
	/* 0x2a09: cmp    r13,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 75ULL);
x86_l_2a0d:
	/* 0x2a0d: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2a13:
	/* 0x2a13: lea    ecx,[r13+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_2a1a:
	/* 0x2a1a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a20:
	/* 0x2a20: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a24:
	/* 0x2a24: mov    BYTE PTR [rax+0x4f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_2a27:
	/* 0x2a27: cmp    r13,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 76ULL);
x86_l_2a2b:
	/* 0x2a2b: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2a31:
	/* 0x2a31: lea    ecx,[r13+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_2a38:
	/* 0x2a38: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a3e:
	/* 0x2a3e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a42:
	/* 0x2a42: mov    BYTE PTR [rax+0x50],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a45:
	/* 0x2a45: cmp    r13,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 77ULL);
x86_l_2a49:
	/* 0x2a49: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2a4f:
	/* 0x2a4f: lea    ecx,[r13+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_2a56:
	/* 0x2a56: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a5c:
	/* 0x2a5c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a60:
	/* 0x2a60: mov    BYTE PTR [rax+0x51],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_2a63:
	/* 0x2a63: cmp    r13,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 78ULL);
x86_l_2a67:
	/* 0x2a67: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11317ULL;
	}
x86_l_2a6d:
	/* 0x2a6d: lea    ecx,[r13+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_2a74:
	/* 0x2a74: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
	return 10874ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10874ULL: goto x86_l_2a7a;
	case 10878ULL: goto x86_l_2a7e;
	case 10881ULL: goto x86_l_2a81;
	case 10885ULL: goto x86_l_2a85;
	case 10891ULL: goto x86_l_2a8b;
	case 10898ULL: goto x86_l_2a92;
	case 10904ULL: goto x86_l_2a98;
	case 10908ULL: goto x86_l_2a9c;
	case 10911ULL: goto x86_l_2a9f;
	case 10915ULL: goto x86_l_2aa3;
	case 10921ULL: goto x86_l_2aa9;
	case 10928ULL: goto x86_l_2ab0;
	case 10934ULL: goto x86_l_2ab6;
	case 10938ULL: goto x86_l_2aba;
	case 10941ULL: goto x86_l_2abd;
	case 10945ULL: goto x86_l_2ac1;
	case 10951ULL: goto x86_l_2ac7;
	case 10958ULL: goto x86_l_2ace;
	case 10964ULL: goto x86_l_2ad4;
	case 10968ULL: goto x86_l_2ad8;
	case 10971ULL: goto x86_l_2adb;
	case 10975ULL: goto x86_l_2adf;
	case 10981ULL: goto x86_l_2ae5;
	case 10988ULL: goto x86_l_2aec;
	case 10994ULL: goto x86_l_2af2;
	case 10998ULL: goto x86_l_2af6;
	case 11001ULL: goto x86_l_2af9;
	case 11005ULL: goto x86_l_2afd;
	case 11011ULL: goto x86_l_2b03;
	case 11018ULL: goto x86_l_2b0a;
	case 11024ULL: goto x86_l_2b10;
	case 11028ULL: goto x86_l_2b14;
	case 11031ULL: goto x86_l_2b17;
	case 11035ULL: goto x86_l_2b1b;
	case 11041ULL: goto x86_l_2b21;
	case 11048ULL: goto x86_l_2b28;
	case 11054ULL: goto x86_l_2b2e;
	case 11058ULL: goto x86_l_2b32;
	case 11061ULL: goto x86_l_2b35;
	case 11065ULL: goto x86_l_2b39;
	case 11071ULL: goto x86_l_2b3f;
	case 11078ULL: goto x86_l_2b46;
	case 11084ULL: goto x86_l_2b4c;
	case 11088ULL: goto x86_l_2b50;
	case 11091ULL: goto x86_l_2b53;
	case 11095ULL: goto x86_l_2b57;
	case 11101ULL: goto x86_l_2b5d;
	case 11108ULL: goto x86_l_2b64;
	case 11114ULL: goto x86_l_2b6a;
	case 11118ULL: goto x86_l_2b6e;
	case 11121ULL: goto x86_l_2b71;
	case 11125ULL: goto x86_l_2b75;
	case 11131ULL: goto x86_l_2b7b;
	case 11138ULL: goto x86_l_2b82;
	case 11144ULL: goto x86_l_2b88;
	case 11148ULL: goto x86_l_2b8c;
	case 11151ULL: goto x86_l_2b8f;
	case 11155ULL: goto x86_l_2b93;
	case 11161ULL: goto x86_l_2b99;
	case 11168ULL: goto x86_l_2ba0;
	case 11174ULL: goto x86_l_2ba6;
	case 11178ULL: goto x86_l_2baa;
	case 11181ULL: goto x86_l_2bad;
	case 11185ULL: goto x86_l_2bb1;
	case 11191ULL: goto x86_l_2bb7;
	case 11198ULL: goto x86_l_2bbe;
	case 11204ULL: goto x86_l_2bc4;
	case 11208ULL: goto x86_l_2bc8;
	case 11211ULL: goto x86_l_2bcb;
	case 11215ULL: goto x86_l_2bcf;
	case 11217ULL: goto x86_l_2bd1;
	case 11224ULL: goto x86_l_2bd8;
	case 11230ULL: goto x86_l_2bde;
	case 11234ULL: goto x86_l_2be2;
	case 11237ULL: goto x86_l_2be5;
	case 11241ULL: goto x86_l_2be9;
	case 11243ULL: goto x86_l_2beb;
	case 11250ULL: goto x86_l_2bf2;
	case 11256ULL: goto x86_l_2bf8;
	case 11260ULL: goto x86_l_2bfc;
	case 11263ULL: goto x86_l_2bff;
	case 11267ULL: goto x86_l_2c03;
	case 11269ULL: goto x86_l_2c05;
	case 11276ULL: goto x86_l_2c0c;
	case 11282ULL: goto x86_l_2c12;
	case 11286ULL: goto x86_l_2c16;
	case 11289ULL: goto x86_l_2c19;
	case 11293ULL: goto x86_l_2c1d;
	case 11295ULL: goto x86_l_2c1f;
	case 11302ULL: goto x86_l_2c26;
	case 11309ULL: goto x86_l_2c2d;
	case 11314ULL: goto x86_l_2c32;
	case 11317ULL: goto x86_l_2c35;
	case 11322ULL: goto x86_l_2c3a;
	case 11326ULL: goto x86_l_2c3e;
	case 11329ULL: goto x86_l_2c41;
	case 11334ULL: goto x86_l_2c46;
	case 11339ULL: goto x86_l_2c4b;
	case 11344ULL: goto x86_l_2c50;
	case 11348ULL: goto x86_l_2c54;
	case 11352ULL: goto x86_l_2c58;
	case 11360ULL: goto x86_l_2c60;
	case 11365ULL: goto x86_l_2c65;
	case 11372ULL: goto x86_l_2c6c;
	case 11377ULL: goto x86_l_2c71;
	case 11380ULL: goto x86_l_2c74;
	case 11382ULL: goto x86_l_2c76;
	case 11385ULL: goto x86_l_2c79;
	case 11388ULL: goto x86_l_2c7c;
	case 11391ULL: goto x86_l_2c7f;
	case 11397ULL: goto x86_l_2c85;
	case 11401ULL: goto x86_l_2c89;
	case 11404ULL: goto x86_l_2c8c;
	case 11410ULL: goto x86_l_2c92;
	case 11415ULL: goto x86_l_2c97;
	case 11422ULL: goto x86_l_2c9e;
	case 11427ULL: goto x86_l_2ca3;
	case 11429ULL: goto x86_l_2ca5;
	case 11432ULL: goto x86_l_2ca8;
	case 11438ULL: goto x86_l_2cae;
	case 11443ULL: goto x86_l_2cb3;
	case 11447ULL: goto x86_l_2cb7;
	case 11454ULL: goto x86_l_2cbe;
	case 11459ULL: goto x86_l_2cc3;
	case 11463ULL: goto x86_l_2cc7;
	case 11470ULL: goto x86_l_2cce;
	case 11472ULL: goto x86_l_2cd0;
	case 11475ULL: goto x86_l_2cd3;
	case 11479ULL: goto x86_l_2cd7;
	case 11484ULL: goto x86_l_2cdc;
	case 11487ULL: goto x86_l_2cdf;
	case 11489ULL: goto x86_l_2ce1;
	case 11494ULL: goto x86_l_2ce6;
	case 11498ULL: goto x86_l_2cea;
	case 11501ULL: goto x86_l_2ced;
	case 11503ULL: goto x86_l_2cef;
	case 11508ULL: goto x86_l_2cf4;
	case 11513ULL: goto x86_l_2cf9;
	case 11517ULL: goto x86_l_2cfd;
	case 11521ULL: goto x86_l_2d01;
	case 11523ULL: goto x86_l_2d03;
	case 11528ULL: goto x86_l_2d08;
	case 11531ULL: goto x86_l_2d0b;
	case 11535ULL: goto x86_l_2d0f;
	case 11538ULL: goto x86_l_2d12;
	case 11542ULL: goto x86_l_2d16;
	case 11544ULL: goto x86_l_2d18;
	case 11547ULL: goto x86_l_2d1b;
	case 11550ULL: goto x86_l_2d1e;
	case 11552ULL: goto x86_l_2d20;
	case 11555ULL: goto x86_l_2d23;
	case 11558ULL: goto x86_l_2d26;
	case 11560ULL: goto x86_l_2d28;
	case 11563ULL: goto x86_l_2d2b;
	case 11566ULL: goto x86_l_2d2e;
	case 11571ULL: goto x86_l_2d33;
	case 11577ULL: goto x86_l_2d39;
	case 11580ULL: goto x86_l_2d3c;
	case 11586ULL: goto x86_l_2d42;
	case 11591ULL: goto x86_l_2d47;
	case 11594ULL: goto x86_l_2d4a;
	case 11600ULL: goto x86_l_2d50;
	case 11605ULL: goto x86_l_2d55;
	case 11608ULL: goto x86_l_2d58;
	case 11614ULL: goto x86_l_2d5e;
	case 11619ULL: goto x86_l_2d63;
	case 11622ULL: goto x86_l_2d66;
	case 11628ULL: goto x86_l_2d6c;
	case 11633ULL: goto x86_l_2d71;
	case 11636ULL: goto x86_l_2d74;
	case 11642ULL: goto x86_l_2d7a;
	case 11646ULL: goto x86_l_2d7e;
	case 11649ULL: goto x86_l_2d81;
	case 11655ULL: goto x86_l_2d87;
	case 11658ULL: goto x86_l_2d8a;
	case 11664ULL: goto x86_l_2d90;
	case 11667ULL: goto x86_l_2d93;
	case 11672ULL: goto x86_l_2d98;
	case 11676ULL: goto x86_l_2d9c;
	case 11680ULL: goto x86_l_2da0;
	case 11685ULL: goto x86_l_2da5;
	case 11692ULL: goto x86_l_2dac;
	case 11697ULL: goto x86_l_2db1;
	case 11699ULL: goto x86_l_2db3;
	case 11702ULL: goto x86_l_2db6;
	case 11708ULL: goto x86_l_2dbc;
	case 11716ULL: goto x86_l_2dc4;
	case 11721ULL: goto x86_l_2dc9;
	case 11726ULL: goto x86_l_2dce;
	case 11730ULL: goto x86_l_2dd2;
	case 11734ULL: goto x86_l_2dd6;
	case 11742ULL: goto x86_l_2dde;
	case 11747ULL: goto x86_l_2de3;
	case 11754ULL: goto x86_l_2dea;
	case 11759ULL: goto x86_l_2def;
	case 11761ULL: goto x86_l_2df1;
	case 11764ULL: goto x86_l_2df4;
	case 11769ULL: goto x86_l_2df9;
	case 11775ULL: goto x86_l_2dff;
	case 11780ULL: goto x86_l_2e04;
	case 11783ULL: goto x86_l_2e07;
	case 11789ULL: goto x86_l_2e0d;
	case 11794ULL: goto x86_l_2e12;
	case 11799ULL: goto x86_l_2e17;
	case 11806ULL: goto x86_l_2e1e;
	case 11811ULL: goto x86_l_2e23;
	case 11813ULL: goto x86_l_2e25;
	case 11816ULL: goto x86_l_2e28;
	case 11822ULL: goto x86_l_2e2e;
	case 11825ULL: goto x86_l_2e31;
	case 11829ULL: goto x86_l_2e35;
	case 11834ULL: goto x86_l_2e3a;
	case 11839ULL: goto x86_l_2e3f;
	case 11842ULL: goto x86_l_2e42;
	case 11849ULL: goto x86_l_2e49;
	case 11853ULL: goto x86_l_2e4d;
	case 11856ULL: goto x86_l_2e50;
	case 11860ULL: goto x86_l_2e54;
	case 11865ULL: goto x86_l_2e59;
	case 11870ULL: goto x86_l_2e5e;
	case 11872ULL: goto x86_l_2e60;
	case 11877ULL: goto x86_l_2e65;
	case 11882ULL: goto x86_l_2e6a;
	case 11885ULL: goto x86_l_2e6d;
	case 11887ULL: goto x86_l_2e6f;
	case 11892ULL: goto x86_l_2e74;
	case 11897ULL: goto x86_l_2e79;
	case 11905ULL: goto x86_l_2e81;
	case 11911ULL: goto x86_l_2e87;
	case 11917ULL: goto x86_l_2e8d;
	case 11922ULL: goto x86_l_2e92;
	case 11925ULL: goto x86_l_2e95;
	case 11931ULL: goto x86_l_2e9b;
	case 11934ULL: goto x86_l_2e9e;
	case 11937ULL: goto x86_l_2ea1;
	case 11940ULL: goto x86_l_2ea4;
	case 11942ULL: goto x86_l_2ea6;
	case 11944ULL: goto x86_l_2ea8;
	case 11947ULL: goto x86_l_2eab;
	case 11953ULL: goto x86_l_2eb1;
	case 11955ULL: goto x86_l_2eb3;
	case 11961ULL: goto x86_l_2eb9;
	case 11966ULL: goto x86_l_2ebe;
	case 11969ULL: goto x86_l_2ec1;
	case 11971ULL: goto x86_l_2ec3;
	case 11973ULL: goto x86_l_2ec5;
	case 11979ULL: goto x86_l_2ecb;
	case 11982ULL: goto x86_l_2ece;
	case 11988ULL: goto x86_l_2ed4;
	case 11992ULL: goto x86_l_2ed8;
	case 11995ULL: goto x86_l_2edb;
	case 12001ULL: goto x86_l_2ee1;
	case 12003ULL: goto x86_l_2ee3;
	case 12009ULL: goto x86_l_2ee9;
	case 12014ULL: goto x86_l_2eee;
	case 12017ULL: goto x86_l_2ef1;
	case 12020ULL: goto x86_l_2ef4;
	case 12025ULL: goto x86_l_2ef9;
	case 12031ULL: goto x86_l_2eff;
	case 12034ULL: goto x86_l_2f02;
	case 12039ULL: goto x86_l_2f07;
	case 12043ULL: goto x86_l_2f0b;
	case 12048ULL: goto x86_l_2f10;
	case 12055ULL: goto x86_l_2f17;
	case 12060ULL: goto x86_l_2f1c;
	case 12062ULL: goto x86_l_2f1e;
	case 12065ULL: goto x86_l_2f21;
	case 12071ULL: goto x86_l_2f27;
	case 12075ULL: goto x86_l_2f2b;
	case 12080ULL: goto x86_l_2f30;
	case 12085ULL: goto x86_l_2f35;
	case 12090ULL: goto x86_l_2f3a;
	case 12093ULL: goto x86_l_2f3d;
	case 12096ULL: goto x86_l_2f40;
	case 12100ULL: goto x86_l_2f44;
	case 12105ULL: goto x86_l_2f49;
	case 12108ULL: goto x86_l_2f4c;
	case 12111ULL: goto x86_l_2f4f;
	case 12116ULL: goto x86_l_2f54;
	case 12120ULL: goto x86_l_2f58;
	case 12125ULL: goto x86_l_2f5d;
	case 12128ULL: goto x86_l_2f60;
	case 12131ULL: goto x86_l_2f63;
	case 12136ULL: goto x86_l_2f68;
	case 12140ULL: goto x86_l_2f6c;
	case 12145ULL: goto x86_l_2f71;
	case 12150ULL: goto x86_l_2f76;
	case 12153ULL: goto x86_l_2f79;
	case 12158ULL: goto x86_l_2f7e;
	case 12161ULL: goto x86_l_2f81;
	case 12165ULL: goto x86_l_2f85;
	case 12170ULL: goto x86_l_2f8a;
	case 12177ULL: goto x86_l_2f91;
	case 12182ULL: goto x86_l_2f96;
	case 12184ULL: goto x86_l_2f98;
	case 12187ULL: goto x86_l_2f9b;
	case 12193ULL: goto x86_l_2fa1;
	case 12201ULL: goto x86_l_2fa9;
	case 12206ULL: goto x86_l_2fae;
	case 12211ULL: goto x86_l_2fb3;
	case 12216ULL: goto x86_l_2fb8;
	case 12220ULL: goto x86_l_2fbc;
	case 12224ULL: goto x86_l_2fc0;
	case 12228ULL: goto x86_l_2fc4;
	case 12233ULL: goto x86_l_2fc9;
	case 12238ULL: goto x86_l_2fce;
	case 12241ULL: goto x86_l_2fd1;
	case 12243ULL: goto x86_l_2fd3;
	case 12248ULL: goto x86_l_2fd8;
	case 12251ULL: goto x86_l_2fdb;
	case 12254ULL: goto x86_l_2fde;
	case 12257ULL: goto x86_l_2fe1;
	case 12263ULL: goto x86_l_2fe7;
	case 12266ULL: goto x86_l_2fea;
	case 12269ULL: goto x86_l_2fed;
	case 12271ULL: goto x86_l_2fef;
	case 12274ULL: goto x86_l_2ff2;
	case 12277ULL: goto x86_l_2ff5;
	case 12281ULL: goto x86_l_2ff9;
	case 12286ULL: goto x86_l_2ffe;
	case 12288ULL: goto x86_l_3000;
	case 12292ULL: goto x86_l_3004;
	case 12297ULL: goto x86_l_3009;
	case 12300ULL: goto x86_l_300c;
	case 12302ULL: goto x86_l_300e;
	case 12304ULL: goto x86_l_3010;
	case 12306ULL: goto x86_l_3012;
	case 12309ULL: goto x86_l_3015;
	case 12314ULL: goto x86_l_301a;
	case 12318ULL: goto x86_l_301e;
	case 12320ULL: goto x86_l_3020;
	case 12323ULL: goto x86_l_3023;
	case 12329ULL: goto x86_l_3029;
	case 12332ULL: goto x86_l_302c;
	case 12334ULL: goto x86_l_302e;
	case 12338ULL: goto x86_l_3032;
	case 12343ULL: goto x86_l_3037;
	case 12347ULL: goto x86_l_303b;
	case 12350ULL: goto x86_l_303e;
	case 12355ULL: goto x86_l_3043;
	case 12359ULL: goto x86_l_3047;
	case 12363ULL: goto x86_l_304b;
	case 12366ULL: goto x86_l_304e;
	case 12372ULL: goto x86_l_3054;
	case 12377ULL: goto x86_l_3059;
	case 12384ULL: goto x86_l_3060;
	case 12389ULL: goto x86_l_3065;
	case 12392ULL: goto x86_l_3068;
	case 12394ULL: goto x86_l_306a;
	case 12397ULL: goto x86_l_306d;
	case 12402ULL: goto x86_l_3072;
	case 12409ULL: goto x86_l_3079;
	case 12412ULL: goto x86_l_307c;
	case 12414ULL: goto x86_l_307e;
	case 12417ULL: goto x86_l_3081;
	case 12422ULL: goto x86_l_3086;
	case 12425ULL: goto x86_l_3089;
	case 12431ULL: goto x86_l_308f;
	case 12434ULL: goto x86_l_3092;
	case 12440ULL: goto x86_l_3098;
	case 12443ULL: goto x86_l_309b;
	case 12447ULL: goto x86_l_309f;
	case 12452ULL: goto x86_l_30a4;
	case 12455ULL: goto x86_l_30a7;
	case 12459ULL: goto x86_l_30ab;
	case 12464ULL: goto x86_l_30b0;
	case 12467ULL: goto x86_l_30b3;
	case 12472ULL: goto x86_l_30b8;
	case 12474ULL: goto x86_l_30ba;
	case 12479ULL: goto x86_l_30bf;
	case 12482ULL: goto x86_l_30c2;
	case 12484ULL: goto x86_l_30c4;
	case 12488ULL: goto x86_l_30c8;
	case 12493ULL: goto x86_l_30cd;
	case 12497ULL: goto x86_l_30d1;
	case 12500ULL: goto x86_l_30d4;
	case 12502ULL: goto x86_l_30d6;
	case 12508ULL: goto x86_l_30dc;
	case 12513ULL: goto x86_l_30e1;
	case 12516ULL: goto x86_l_30e4;
	case 12518ULL: goto x86_l_30e6;
	case 12522ULL: goto x86_l_30ea;
	case 12526ULL: goto x86_l_30ee;
	case 12531ULL: goto x86_l_30f3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a7a:
	/* 0x2a7a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a7e:
	/* 0x2a7e: mov    BYTE PTR [rax+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_2a81:
	/* 0x2a81: cmp    r13,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 79ULL);
x86_l_2a85:
	/* 0x2a85: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c35;
	}
x86_l_2a8b:
	/* 0x2a8b: lea    ecx,[r13+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_2a92:
	/* 0x2a92: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a98:
	/* 0x2a98: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a9c:
	/* 0x2a9c: mov    BYTE PTR [rax+0x53],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_2a9f:
	/* 0x2a9f: cmp    r13,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 80ULL);
x86_l_2aa3:
	/* 0x2aa3: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c35;
	}
x86_l_2aa9:
	/* 0x2aa9: lea    ecx,[r13+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_2ab0:
	/* 0x2ab0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2ab6:
	/* 0x2ab6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2aba:
	/* 0x2aba: mov    BYTE PTR [rax+0x54],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_2abd:
	/* 0x2abd: cmp    r13,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 81ULL);
x86_l_2ac1:
	/* 0x2ac1: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c35;
	}
x86_l_2ac7:
	/* 0x2ac7: lea    ecx,[r13+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_2ace:
	/* 0x2ace: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2ad4:
	/* 0x2ad4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2ad8:
	/* 0x2ad8: mov    BYTE PTR [rax+0x55],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_2adb:
	/* 0x2adb: cmp    r13,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 82ULL);
x86_l_2adf:
	/* 0x2adf: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c35;
	}
x86_l_2ae5:
	/* 0x2ae5: lea    ecx,[r13+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_2aec:
	/* 0x2aec: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2af2:
	/* 0x2af2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2af6:
	/* 0x2af6: mov    BYTE PTR [rax+0x56],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2af9:
	/* 0x2af9: cmp    r13,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 83ULL);
x86_l_2afd:
	/* 0x2afd: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c35;
	}
x86_l_2b03:
	/* 0x2b03: lea    ecx,[r13+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_2b0a:
	/* 0x2b0a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b10:
	/* 0x2b10: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2b14:
	/* 0x2b14: mov    BYTE PTR [rax+0x57],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_2b17:
	/* 0x2b17: cmp    r13,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 84ULL);
x86_l_2b1b:
	/* 0x2b1b: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c35;
	}
x86_l_2b21:
	/* 0x2b21: lea    ecx,[r13+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_2b28:
	/* 0x2b28: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b2e:
	/* 0x2b2e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2b32:
	/* 0x2b32: mov    BYTE PTR [rax+0x58],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2b35:
	/* 0x2b35: cmp    r13,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 85ULL);
x86_l_2b39:
	/* 0x2b39: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c35;
	}
x86_l_2b3f:
	/* 0x2b3f: lea    ecx,[r13+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_2b46:
	/* 0x2b46: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b4c:
	/* 0x2b4c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2b50:
	/* 0x2b50: mov    BYTE PTR [rax+0x59],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_2b53:
	/* 0x2b53: cmp    r13,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 86ULL);
x86_l_2b57:
	/* 0x2b57: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c35;
	}
x86_l_2b5d:
	/* 0x2b5d: lea    ecx,[r13+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_2b64:
	/* 0x2b64: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b6a:
	/* 0x2b6a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2b6e:
	/* 0x2b6e: mov    BYTE PTR [rax+0x5a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_2b71:
	/* 0x2b71: cmp    r13,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 87ULL);
x86_l_2b75:
	/* 0x2b75: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c35;
	}
x86_l_2b7b:
	/* 0x2b7b: lea    ecx,[r13+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_2b82:
	/* 0x2b82: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b88:
	/* 0x2b88: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2b8c:
	/* 0x2b8c: mov    BYTE PTR [rax+0x5b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_2b8f:
	/* 0x2b8f: cmp    r13,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 88ULL);
x86_l_2b93:
	/* 0x2b93: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c35;
	}
x86_l_2b99:
	/* 0x2b99: lea    ecx,[r13+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_2ba0:
	/* 0x2ba0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2ba6:
	/* 0x2ba6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2baa:
	/* 0x2baa: mov    BYTE PTR [rax+0x5c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_2bad:
	/* 0x2bad: cmp    r13,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 89ULL);
x86_l_2bb1:
	/* 0x2bb1: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c35;
	}
x86_l_2bb7:
	/* 0x2bb7: lea    ecx,[r13+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_2bbe:
	/* 0x2bbe: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2bc4:
	/* 0x2bc4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2bc8:
	/* 0x2bc8: mov    BYTE PTR [rax+0x5d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_2bcb:
	/* 0x2bcb: cmp    r13,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 90ULL);
x86_l_2bcf:
	/* 0x2bcf: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c35;
	}
x86_l_2bd1:
	/* 0x2bd1: lea    ecx,[r13+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_2bd8:
	/* 0x2bd8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2bde:
	/* 0x2bde: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2be2:
	/* 0x2be2: mov    BYTE PTR [rax+0x5e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_2be5:
	/* 0x2be5: cmp    r13,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 91ULL);
x86_l_2be9:
	/* 0x2be9: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c35;
	}
x86_l_2beb:
	/* 0x2beb: lea    ecx,[r13+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_2bf2:
	/* 0x2bf2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2bf8:
	/* 0x2bf8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2bfc:
	/* 0x2bfc: mov    BYTE PTR [rax+0x5f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_2bff:
	/* 0x2bff: cmp    r13,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 92ULL);
x86_l_2c03:
	/* 0x2c03: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c35;
	}
x86_l_2c05:
	/* 0x2c05: lea    ecx,[r13+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_2c0c:
	/* 0x2c0c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c12:
	/* 0x2c12: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2c16:
	/* 0x2c16: mov    BYTE PTR [rax+0x60],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2c19:
	/* 0x2c19: cmp    r13,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 93ULL);
x86_l_2c1d:
	/* 0x2c1d: je     2c35 <generic_fexit_filter_arg+0x2c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c35;
	}
x86_l_2c1f:
	/* 0x2c1f: add    r13d,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_2c26:
	/* 0x2c26: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c2d:
	/* 0x2c2d: movzx  ecx,BYTE PTR [rdx+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_2c32:
	/* 0x2c32: mov    BYTE PTR [rax+0x61],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_2c35:
	/* 0x2c35: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2c3a:
	/* 0x2c3a: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c3e:
	/* 0x2c3e: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_2c41:
	/* 0x2c41: jmp    3723 <generic_fexit_filter_arg+0x3723> */
	return 14115ULL;
x86_l_2c46:
	/* 0x2c46: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c4b:
	/* 0x2c4b: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c50:
	/* 0x2c50: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c54:
	/* 0x2c54: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c58:
	/* 0x2c58: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2c60:
	/* 0x2c60: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c65:
	/* 0x2c65: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_2c6c:
	/* 0x2c6c: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c71:
	/* 0x2c71: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_2c74:
	/* 0x2c74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c76:
	/* 0x2c76: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2c79:
	/* 0x2c79: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c7c:
	/* 0x2c7c: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2c7f:
	/* 0x2c7f: je     3734 <generic_fexit_filter_arg+0x3734> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14132ULL;
	}
x86_l_2c85:
	/* 0x2c85: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c89:
	/* 0x2c89: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c8c:
	/* 0x2c8c: je     3734 <generic_fexit_filter_arg+0x3734> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14132ULL;
	}
x86_l_2c92:
	/* 0x2c92: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c97:
	/* 0x2c97: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_2c9e:
	/* 0x2c9e: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ca3:
	/* 0x2ca3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ca5:
	/* 0x2ca5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ca8:
	/* 0x2ca8: je     3731 <generic_fexit_filter_arg+0x3731> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14129ULL;
	}
x86_l_2cae:
	/* 0x2cae: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cb3:
	/* 0x2cb3: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2cb7:
	/* 0x2cb7: cmp    r13d,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 255ULL);
x86_l_2cbe:
	/* 0x2cbe: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_2cc3:
	/* 0x2cc3: cmovb  esi,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_2cc7:
	/* 0x2cc7: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_2cce:
	/* 0x2cce: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cd0:
	/* 0x2cd0: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2cd3:
	/* 0x2cd3: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2cd7:
	/* 0x2cd7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2cdc:
	/* 0x2cdc: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2cdf:
	/* 0x2cdf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2ce1:
	/* 0x2ce1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ce6:
	/* 0x2ce6: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cea:
	/* 0x2cea: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2ced:
	/* 0x2ced: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cef:
	/* 0x2cef: jmp    3725 <generic_fexit_filter_arg+0x3725> */
	return 14117ULL;
x86_l_2cf4:
	/* 0x2cf4: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cf9:
	/* 0x2cf9: mov    rdx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cfd:
	/* 0x2cfd: mov    r8,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d01:
	/* 0x2d01: jmp    2d0f <generic_fexit_filter_arg+0x2d0f> */
	goto x86_l_2d0f;
x86_l_2d03:
	/* 0x2d03: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d08:
	/* 0x2d08: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d0b:
	/* 0x2d0b: mov    r8,QWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d0f:
	/* 0x2d0f: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_2d12:
	/* 0x2d12: shr    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2d16:
	/* 0x2d16: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d18:
	/* 0x2d18: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d1b:
	/* 0x2d1b: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2d1e:
	/* 0x2d1e: jg     2d47 <generic_fexit_filter_arg+0x2d47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2d47;
	}
x86_l_2d20:
	/* 0x2d20: lea    eax,[rcx-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_2d23:
	/* 0x2d23: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d26:
	/* 0x2d26: jb     2d7a <generic_fexit_filter_arg+0x2d7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2d7a;
	}
x86_l_2d28:
	/* 0x2d28: lea    eax,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_2d2b:
	/* 0x2d2b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d2e:
	/* 0x2d2e: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d33:
	/* 0x2d33: jb     2eff <generic_fexit_filter_arg+0x2eff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2eff;
	}
x86_l_2d39:
	/* 0x2d39: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2d3c:
	/* 0x2d3c: je     31da <generic_fexit_filter_arg+0x31da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12762ULL;
	}
x86_l_2d42:
	/* 0x2d42: jmp    37e5 <generic_fexit_filter_arg+0x37e5> */
	return 14309ULL;
x86_l_2d47:
	/* 0x2d47: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_2d4a:
	/* 0x2d4a: ja     2eee <generic_fexit_filter_arg+0x2eee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2eee;
	}
x86_l_2d50:
	/* 0x2d50: mov    eax,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5242880ULL);
x86_l_2d55:
	/* 0x2d55: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2d58:
	/* 0x2d58: jb     2f49 <generic_fexit_filter_arg+0x2f49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2f49;
	}
x86_l_2d5e:
	/* 0x2d5e: mov    eax,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10485760ULL);
x86_l_2d63:
	/* 0x2d63: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2d66:
	/* 0x2d66: jb     2f5d <generic_fexit_filter_arg+0x2f5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2f5d;
	}
x86_l_2d6c:
	/* 0x2d6c: mov    eax,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 50331648ULL);
x86_l_2d71:
	/* 0x2d71: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2d74:
	/* 0x2d74: jae    2eee <generic_fexit_filter_arg+0x2eee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2eee;
	}
x86_l_2d7a:
	/* 0x2d7a: movzx  eax,WORD PTR [rdi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2d7e:
	/* 0x2d7e: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_2d81:
	/* 0x2d81: je     2f71 <generic_fexit_filter_arg+0x2f71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f71;
	}
x86_l_2d87:
	/* 0x2d87: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d8a:
	/* 0x2d8a: jne    2ffe <generic_fexit_filter_arg+0x2ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ffe;
	}
x86_l_2d90:
	/* 0x2d90: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_2d93:
	/* 0x2d93: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d98:
	/* 0x2d98: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d9c:
	/* 0x2d9c: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2da0:
	/* 0x2da0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2da5:
	/* 0x2da5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_2dac:
	/* 0x2dac: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2db1:
	/* 0x2db1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2db3:
	/* 0x2db3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2db6:
	/* 0x2db6: je     3467 <generic_fexit_filter_arg+0x3467> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13415ULL;
	}
x86_l_2dbc:
	/* 0x2dbc: mov    DWORD PTR [rsp+0x28],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691872ULL);
x86_l_2dc4:
	/* 0x2dc4: mov    DWORD PTR [rsp+0x2c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2dc9:
	/* 0x2dc9: jmp    2fc4 <generic_fexit_filter_arg+0x2fc4> */
	goto x86_l_2fc4;
x86_l_2dce:
	/* 0x2dce: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dd2:
	/* 0x2dd2: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2dd6:
	/* 0x2dd6: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2dde:
	/* 0x2dde: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2de3:
	/* 0x2de3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_2dea:
	/* 0x2dea: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2def:
	/* 0x2def: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2df1:
	/* 0x2df1: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2df4:
	/* 0x2df4: cmp    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2df9:
	/* 0x2df9: je     37c6 <generic_fexit_filter_arg+0x37c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14278ULL;
	}
x86_l_2dff:
	/* 0x2dff: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e04:
	/* 0x2e04: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e07:
	/* 0x2e07: je     37c6 <generic_fexit_filter_arg+0x37c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14278ULL;
	}
x86_l_2e0d:
	/* 0x2e0d: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e12:
	/* 0x2e12: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e17:
	/* 0x2e17: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_2e1e:
	/* 0x2e1e: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e23:
	/* 0x2e23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e25:
	/* 0x2e25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e28:
	/* 0x2e28: je     37be <generic_fexit_filter_arg+0x37be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14270ULL;
	}
x86_l_2e2e:
	/* 0x2e2e: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2e31:
	/* 0x2e31: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e35:
	/* 0x2e35: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2e3a:
	/* 0x2e3a: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_2e3f:
	/* 0x2e3f: cmovb  esi,eax */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2e42:
	/* 0x2e42: lea    eax,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_2e49:
	/* 0x2e49: mov    DWORD PTR [r13+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e4d:
	/* 0x2e4d: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2e50:
	/* 0x2e50: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2e54:
	/* 0x2e54: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e59:
	/* 0x2e59: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e5e:
	/* 0x2e5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e60:
	/* 0x2e60: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e65:
	/* 0x2e65: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e6a:
	/* 0x2e6a: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2e6d:
	/* 0x2e6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e6f:
	/* 0x2e6f: jmp    37b2 <generic_fexit_filter_arg+0x37b2> */
	return 14258ULL;
x86_l_2e74:
	/* 0x2e74: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e79:
	/* 0x2e79: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2e81:
	/* 0x2e81: cmp    edx,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_2e87:
	/* 0x2e87: ja     37be <generic_fexit_filter_arg+0x37be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 14270ULL;
	}
x86_l_2e8d:
	/* 0x2e8d: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e92:
	/* 0x2e92: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e95:
	/* 0x2e95: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2e9b:
	/* 0x2e9b: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_2e9e:
	/* 0x2e9e: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_2ea1:
	/* 0x2ea1: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2ea4:
	/* 0x2ea4: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2ea6:
	/* 0x2ea6: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2ea8:
	/* 0x2ea8: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_2eab:
	/* 0x2eab: je     3487 <generic_fexit_filter_arg+0x3487> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13447ULL;
	}
x86_l_2eb1:
	/* 0x2eb1: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2eb3:
	/* 0x2eb3: jne    3487 <generic_fexit_filter_arg+0x3487> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13447ULL;
	}
x86_l_2eb9:
	/* 0x2eb9: jmp    349e <generic_fexit_filter_arg+0x349e> */
	return 13470ULL;
x86_l_2ebe:
	/* 0x2ebe: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2ec1:
	/* 0x2ec1: jne    2ecb <generic_fexit_filter_arg+0x2ecb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ecb;
	}
x86_l_2ec3:
	/* 0x2ec3: test   DWORD PTR [rdi],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ec5:
	/* 0x2ec5: jne    37ea <generic_fexit_filter_arg+0x37ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14314ULL;
	}
x86_l_2ecb:
	/* 0x2ecb: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2ece:
	/* 0x2ece: jb     3656 <generic_fexit_filter_arg+0x3656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13910ULL;
	}
x86_l_2ed4:
	/* 0x2ed4: mov    esi,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ed8:
	/* 0x2ed8: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2edb:
	/* 0x2edb: jae    3422 <generic_fexit_filter_arg+0x3422> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13346ULL;
	}
x86_l_2ee1:
	/* 0x2ee1: cmp    DWORD PTR [rdi],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ee3:
	/* 0x2ee3: jne    342f <generic_fexit_filter_arg+0x342f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13359ULL;
	}
x86_l_2ee9:
	/* 0x2ee9: jmp    35e2 <generic_fexit_filter_arg+0x35e2> */
	return 13794ULL;
x86_l_2eee:
	/* 0x2eee: add    ecx,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_2ef1:
	/* 0x2ef1: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2ef4:
	/* 0x2ef4: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ef9:
	/* 0x2ef9: jae    37e5 <generic_fexit_filter_arg+0x37e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 14309ULL;
	}
x86_l_2eff:
	/* 0x2eff: mov    r15d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_32);
x86_l_2f02:
	/* 0x2f02: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2f07:
	/* 0x2f07: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2f0b:
	/* 0x2f0b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f10:
	/* 0x2f10: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2f17:
	/* 0x2f17: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2f1c:
	/* 0x2f1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f1e:
	/* 0x2f1e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f21:
	/* 0x2f21: je     341a <generic_fexit_filter_arg+0x341a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13338ULL;
	}
x86_l_2f27:
	/* 0x2f27: movzx  ecx,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2f2b:
	/* 0x2f2b: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f30:
	/* 0x2f30: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2f35:
	/* 0x2f35: jmp    320d <generic_fexit_filter_arg+0x320d> */
	return 12813ULL;
x86_l_2f3a:
	/* 0x2f3a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f3d:
	/* 0x2f3d: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2f40:
	/* 0x2f40: movzx  r15d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2f44:
	/* 0x2f44: jmp    37e5 <generic_fexit_filter_arg+0x37e5> */
	return 14309ULL;
x86_l_2f49:
	/* 0x2f49: movzx  eax,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2f4c:
	/* 0x2f4c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f4f:
	/* 0x2f4f: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_2f54:
	/* 0x2f54: setb   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_B);
x86_l_2f58:
	/* 0x2f58: jmp    37e5 <generic_fexit_filter_arg+0x37e5> */
	return 14309ULL;
x86_l_2f5d:
	/* 0x2f5d: movzx  eax,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2f60:
	/* 0x2f60: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f63:
	/* 0x2f63: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_2f68:
	/* 0x2f68: setae  r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_AE);
x86_l_2f6c:
	/* 0x2f6c: jmp    37e5 <generic_fexit_filter_arg+0x37e5> */
	return 14309ULL;
x86_l_2f71:
	/* 0x2f71: mov    QWORD PTR [rsp+0x8],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f76:
	/* 0x2f76: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_2f79:
	/* 0x2f79: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f7e:
	/* 0x2f7e: mov    eax,DWORD PTR [rax+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2f81:
	/* 0x2f81: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2f85:
	/* 0x2f85: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f8a:
	/* 0x2f8a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_2f91:
	/* 0x2f91: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2f96:
	/* 0x2f96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f98:
	/* 0x2f98: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f9b:
	/* 0x2f9b: je     346d <generic_fexit_filter_arg+0x346d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13421ULL;
	}
x86_l_2fa1:
	/* 0x2fa1: mov    DWORD PTR [rsp+0x28],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691968ULL);
x86_l_2fa9:
	/* 0x2fa9: mov    DWORD PTR [rsp+0x2c],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2fae:
	/* 0x2fae: mov    DWORD PTR [rsp+0x30],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fb3:
	/* 0x2fb3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fb8:
	/* 0x2fb8: mov    DWORD PTR [rsp+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2fbc:
	/* 0x2fbc: shr    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2fc0:
	/* 0x2fc0: mov    DWORD PTR [rsp+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2fc4:
	/* 0x2fc4: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2fc9:
	/* 0x2fc9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2fce:
	/* 0x2fce: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2fd1:
	/* 0x2fd1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2fd3:
	/* 0x2fd3: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fd8:
	/* 0x2fd8: mov    ecx,DWORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2fdb:
	/* 0x2fdb: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_2fde:
	/* 0x2fde: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2fe1:
	/* 0x2fe1: jb     329f <generic_fexit_filter_arg+0x329f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12959ULL;
	}
x86_l_2fe7:
	/* 0x2fe7: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_2fea:
	/* 0x2fea: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2fed:
	/* 0x2fed: ja     2ffe <generic_fexit_filter_arg+0x2ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2ffe;
	}
x86_l_2fef:
	/* 0x2fef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ff2:
	/* 0x2ff2: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_2ff5:
	/* 0x2ff5: movzx  r15d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2ff9:
	/* 0x2ff9: jmp    37e5 <generic_fexit_filter_arg+0x37e5> */
	return 14309ULL;
x86_l_2ffe:
	/* 0x2ffe: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3000:
	/* 0x3000: movzx  r15d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3004:
	/* 0x3004: jmp    37e5 <generic_fexit_filter_arg+0x37e5> */
	return 14309ULL;
x86_l_3009:
	/* 0x3009: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_300c:
	/* 0x300c: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_300e:
	/* 0x300e: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3010:
	/* 0x3010: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_3012:
	/* 0x3012: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_3015:
	/* 0x3015: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_301a:
	/* 0x301a: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_301e:
	/* 0x301e: ja     302e <generic_fexit_filter_arg+0x302e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_302e;
	}
x86_l_3020:
	/* 0x3020: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3023:
	/* 0x3023: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_3029:
	/* 0x3029: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_302c:
	/* 0x302c: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_302e:
	/* 0x302e: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_3032:
	/* 0x3032: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3037:
	/* 0x3037: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_303b:
	/* 0x303b: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_303e:
	/* 0x303e: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3043:
	/* 0x3043: mov    eax,DWORD PTR [rcx+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_3047:
	/* 0x3047: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_304b:
	/* 0x304b: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_304e:
	/* 0x304e: je     36c4 <generic_fexit_filter_arg+0x36c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14020ULL;
	}
x86_l_3054:
	/* 0x3054: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3059:
	/* 0x3059: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_3060:
	/* 0x3060: lea    r15,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3065:
	/* 0x3065: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3068:
	/* 0x3068: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_306a:
	/* 0x306a: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_306d:
	/* 0x306d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3072:
	/* 0x3072: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3079:
	/* 0x3079: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_307c:
	/* 0x307c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_307e:
	/* 0x307e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3081:
	/* 0x3081: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3086:
	/* 0x3086: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_3089:
	/* 0x3089: je     36c7 <generic_fexit_filter_arg+0x36c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14023ULL;
	}
x86_l_308f:
	/* 0x308f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3092:
	/* 0x3092: je     36c7 <generic_fexit_filter_arg+0x36c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14023ULL;
	}
x86_l_3098:
	/* 0x3098: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_309b:
	/* 0x309b: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_309f:
	/* 0x309f: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30a4:
	/* 0x30a4: mov    BYTE PTR [rax],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30a7:
	/* 0x30a7: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_30ab:
	/* 0x30ab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30b0:
	/* 0x30b0: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_30b3:
	/* 0x30b3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30b8:
	/* 0x30b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30ba:
	/* 0x30ba: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_30bf:
	/* 0x30bf: cmp    esi,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_30c2:
	/* 0x30c2: jbe    30e6 <generic_fexit_filter_arg+0x30e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_30e6;
	}
x86_l_30c4:
	/* 0x30c4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30c8:
	/* 0x30c8: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30cd:
	/* 0x30cd: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_30d1:
	/* 0x30d1: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_30d4:
	/* 0x30d4: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_30d6:
	/* 0x30d6: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_30dc:
	/* 0x30dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30e1:
	/* 0x30e1: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_30e4:
	/* 0x30e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30e6:
	/* 0x30e6: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_30ea:
	/* 0x30ea: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30ee:
	/* 0x30ee: cmp    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_30f3:
	/* 0x30f3: jg     35ab <generic_fexit_filter_arg+0x35ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 13739ULL;
	}
	return 12537ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12537ULL: goto x86_l_30f9;
	case 12542ULL: goto x86_l_30fe;
	case 12548ULL: goto x86_l_3104;
	case 12553ULL: goto x86_l_3109;
	case 12559ULL: goto x86_l_310f;
	case 12564ULL: goto x86_l_3114;
	case 12570ULL: goto x86_l_311a;
	case 12575ULL: goto x86_l_311f;
	case 12582ULL: goto x86_l_3126;
	case 12587ULL: goto x86_l_312b;
	case 12590ULL: goto x86_l_312e;
	case 12595ULL: goto x86_l_3133;
	case 12600ULL: goto x86_l_3138;
	case 12602ULL: goto x86_l_313a;
	case 12606ULL: goto x86_l_313e;
	case 12610ULL: goto x86_l_3142;
	case 12615ULL: goto x86_l_3147;
	case 12620ULL: goto x86_l_314c;
	case 12622ULL: goto x86_l_314e;
	case 12625ULL: goto x86_l_3151;
	case 12629ULL: goto x86_l_3155;
	case 12631ULL: goto x86_l_3157;
	case 12637ULL: goto x86_l_315d;
	case 12642ULL: goto x86_l_3162;
	case 12647ULL: goto x86_l_3167;
	case 12653ULL: goto x86_l_316d;
	case 12655ULL: goto x86_l_316f;
	case 12661ULL: goto x86_l_3175;
	case 12664ULL: goto x86_l_3178;
	case 12667ULL: goto x86_l_317b;
	case 12673ULL: goto x86_l_3181;
	case 12676ULL: goto x86_l_3184;
	case 12678ULL: goto x86_l_3186;
	case 12684ULL: goto x86_l_318c;
	case 12686ULL: goto x86_l_318e;
	case 12692ULL: goto x86_l_3194;
	case 12695ULL: goto x86_l_3197;
	case 12701ULL: goto x86_l_319d;
	case 12704ULL: goto x86_l_31a0;
	case 12706ULL: goto x86_l_31a2;
	case 12712ULL: goto x86_l_31a8;
	case 12714ULL: goto x86_l_31aa;
	case 12717ULL: goto x86_l_31ad;
	case 12723ULL: goto x86_l_31b3;
	case 12726ULL: goto x86_l_31b6;
	case 12732ULL: goto x86_l_31bc;
	case 12735ULL: goto x86_l_31bf;
	case 12737ULL: goto x86_l_31c1;
	case 12743ULL: goto x86_l_31c7;
	case 12746ULL: goto x86_l_31ca;
	case 12748ULL: goto x86_l_31cc;
	case 12752ULL: goto x86_l_31d0;
	case 12757ULL: goto x86_l_31d5;
	case 12762ULL: goto x86_l_31da;
	case 12767ULL: goto x86_l_31df;
	case 12771ULL: goto x86_l_31e3;
	case 12776ULL: goto x86_l_31e8;
	case 12783ULL: goto x86_l_31ef;
	case 12788ULL: goto x86_l_31f4;
	case 12790ULL: goto x86_l_31f6;
	case 12793ULL: goto x86_l_31f9;
	case 12799ULL: goto x86_l_31ff;
	case 12803ULL: goto x86_l_3203;
	case 12808ULL: goto x86_l_3208;
	case 12813ULL: goto x86_l_320d;
	case 12818ULL: goto x86_l_3212;
	case 12821ULL: goto x86_l_3215;
	case 12823ULL: goto x86_l_3217;
	case 12827ULL: goto x86_l_321b;
	case 12829ULL: goto x86_l_321d;
	case 12832ULL: goto x86_l_3220;
	case 12834ULL: goto x86_l_3222;
	case 12839ULL: goto x86_l_3227;
	case 12842ULL: goto x86_l_322a;
	case 12844ULL: goto x86_l_322c;
	case 12847ULL: goto x86_l_322f;
	case 12850ULL: goto x86_l_3232;
	case 12852ULL: goto x86_l_3234;
	case 12857ULL: goto x86_l_3239;
	case 12860ULL: goto x86_l_323c;
	case 12862ULL: goto x86_l_323e;
	case 12865ULL: goto x86_l_3241;
	case 12868ULL: goto x86_l_3244;
	case 12872ULL: goto x86_l_3248;
	case 12877ULL: goto x86_l_324d;
	case 12880ULL: goto x86_l_3250;
	case 12882ULL: goto x86_l_3252;
	case 12885ULL: goto x86_l_3255;
	case 12891ULL: goto x86_l_325b;
	case 12894ULL: goto x86_l_325e;
	case 12900ULL: goto x86_l_3264;
	case 12904ULL: goto x86_l_3268;
	case 12907ULL: goto x86_l_326b;
	case 12913ULL: goto x86_l_3271;
	case 12916ULL: goto x86_l_3274;
	case 12922ULL: goto x86_l_327a;
	case 12925ULL: goto x86_l_327d;
	case 12931ULL: goto x86_l_3283;
	case 12934ULL: goto x86_l_3286;
	case 12937ULL: goto x86_l_3289;
	case 12943ULL: goto x86_l_328f;
	case 12948ULL: goto x86_l_3294;
	case 12951ULL: goto x86_l_3297;
	case 12954ULL: goto x86_l_329a;
	case 12959ULL: goto x86_l_329f;
	case 12962ULL: goto x86_l_32a2;
	case 12967ULL: goto x86_l_32a7;
	case 12970ULL: goto x86_l_32aa;
	case 12973ULL: goto x86_l_32ad;
	case 12975ULL: goto x86_l_32af;
	case 12977ULL: goto x86_l_32b1;
	case 12980ULL: goto x86_l_32b4;
	case 12985ULL: goto x86_l_32b9;
	case 12989ULL: goto x86_l_32bd;
	case 12991ULL: goto x86_l_32bf;
	case 12994ULL: goto x86_l_32c2;
	case 13000ULL: goto x86_l_32c8;
	case 13003ULL: goto x86_l_32cb;
	case 13005ULL: goto x86_l_32cd;
	case 13009ULL: goto x86_l_32d1;
	case 13012ULL: goto x86_l_32d4;
	case 13015ULL: goto x86_l_32d7;
	case 13020ULL: goto x86_l_32dc;
	case 13024ULL: goto x86_l_32e0;
	case 13028ULL: goto x86_l_32e4;
	case 13031ULL: goto x86_l_32e7;
	case 13037ULL: goto x86_l_32ed;
	case 13042ULL: goto x86_l_32f2;
	case 13049ULL: goto x86_l_32f9;
	case 13054ULL: goto x86_l_32fe;
	case 13057ULL: goto x86_l_3301;
	case 13059ULL: goto x86_l_3303;
	case 13062ULL: goto x86_l_3306;
	case 13067ULL: goto x86_l_330b;
	case 13074ULL: goto x86_l_3312;
	case 13077ULL: goto x86_l_3315;
	case 13079ULL: goto x86_l_3317;
	case 13084ULL: goto x86_l_331c;
	case 13087ULL: goto x86_l_331f;
	case 13092ULL: goto x86_l_3324;
	case 13095ULL: goto x86_l_3327;
	case 13101ULL: goto x86_l_332d;
	case 13107ULL: goto x86_l_3333;
	case 13113ULL: goto x86_l_3339;
	case 13118ULL: goto x86_l_333e;
	case 13122ULL: goto x86_l_3342;
	case 13127ULL: goto x86_l_3347;
	case 13132ULL: goto x86_l_334c;
	case 13135ULL: goto x86_l_334f;
	case 13139ULL: goto x86_l_3353;
	case 13144ULL: goto x86_l_3358;
	case 13147ULL: goto x86_l_335b;
	case 13149ULL: goto x86_l_335d;
	case 13154ULL: goto x86_l_3362;
	case 13157ULL: goto x86_l_3365;
	case 13159ULL: goto x86_l_3367;
	case 13162ULL: goto x86_l_336a;
	case 13167ULL: goto x86_l_336f;
	case 13171ULL: goto x86_l_3373;
	case 13174ULL: goto x86_l_3376;
	case 13176ULL: goto x86_l_3378;
	case 13182ULL: goto x86_l_337e;
	case 13187ULL: goto x86_l_3383;
	case 13192ULL: goto x86_l_3388;
	case 13194ULL: goto x86_l_338a;
	case 13198ULL: goto x86_l_338e;
	case 13202ULL: goto x86_l_3392;
	case 13206ULL: goto x86_l_3396;
	case 13212ULL: goto x86_l_339c;
	case 13216ULL: goto x86_l_33a0;
	case 13222ULL: goto x86_l_33a6;
	case 13226ULL: goto x86_l_33aa;
	case 13232ULL: goto x86_l_33b0;
	case 13236ULL: goto x86_l_33b4;
	case 13242ULL: goto x86_l_33ba;
	case 13247ULL: goto x86_l_33bf;
	case 13254ULL: goto x86_l_33c6;
	case 13259ULL: goto x86_l_33cb;
	case 13262ULL: goto x86_l_33ce;
	case 13265ULL: goto x86_l_33d1;
	case 13267ULL: goto x86_l_33d3;
	case 13270ULL: goto x86_l_33d6;
	case 13272ULL: goto x86_l_33d8;
	case 13277ULL: goto x86_l_33dd;
	case 13280ULL: goto x86_l_33e0;
	case 13282ULL: goto x86_l_33e2;
	case 13285ULL: goto x86_l_33e5;
	case 13287ULL: goto x86_l_33e7;
	case 13292ULL: goto x86_l_33ec;
	case 13296ULL: goto x86_l_33f0;
	case 13301ULL: goto x86_l_33f5;
	case 13308ULL: goto x86_l_33fc;
	case 13313ULL: goto x86_l_3401;
	case 13315ULL: goto x86_l_3403;
	case 13318ULL: goto x86_l_3406;
	case 13320ULL: goto x86_l_3408;
	case 13323ULL: goto x86_l_340b;
	case 13328ULL: goto x86_l_3410;
	case 13333ULL: goto x86_l_3415;
	case 13338ULL: goto x86_l_341a;
	case 13341ULL: goto x86_l_341d;
	case 13346ULL: goto x86_l_3422;
	case 13349ULL: goto x86_l_3425;
	case 13351ULL: goto x86_l_3427;
	case 13353ULL: goto x86_l_3429;
	case 13359ULL: goto x86_l_342f;
	case 13362ULL: goto x86_l_3432;
	case 13368ULL: goto x86_l_3438;
	case 13372ULL: goto x86_l_343c;
	case 13375ULL: goto x86_l_343f;
	case 13381ULL: goto x86_l_3445;
	case 13384ULL: goto x86_l_3448;
	case 13390ULL: goto x86_l_344e;
	case 13393ULL: goto x86_l_3451;
	case 13399ULL: goto x86_l_3457;
	case 13402ULL: goto x86_l_345a;
	case 13404ULL: goto x86_l_345c;
	case 13410ULL: goto x86_l_3462;
	case 13415ULL: goto x86_l_3467;
	case 13419ULL: goto x86_l_346b;
	case 13421ULL: goto x86_l_346d;
	case 13426ULL: goto x86_l_3472;
	case 13429ULL: goto x86_l_3475;
	case 13432ULL: goto x86_l_3478;
	case 13435ULL: goto x86_l_347b;
	case 13438ULL: goto x86_l_347e;
	case 13442ULL: goto x86_l_3482;
	case 13447ULL: goto x86_l_3487;
	case 13450ULL: goto x86_l_348a;
	case 13452ULL: goto x86_l_348c;
	case 13454ULL: goto x86_l_348e;
	case 13456ULL: goto x86_l_3490;
	case 13459ULL: goto x86_l_3493;
	case 13464ULL: goto x86_l_3498;
	case 13468ULL: goto x86_l_349c;
	case 13470ULL: goto x86_l_349e;
	case 13473ULL: goto x86_l_34a1;
	case 13479ULL: goto x86_l_34a7;
	case 13482ULL: goto x86_l_34aa;
	case 13484ULL: goto x86_l_34ac;
	case 13488ULL: goto x86_l_34b0;
	case 13492ULL: goto x86_l_34b4;
	case 13495ULL: goto x86_l_34b7;
	case 13500ULL: goto x86_l_34bc;
	case 13504ULL: goto x86_l_34c0;
	case 13508ULL: goto x86_l_34c4;
	case 13511ULL: goto x86_l_34c7;
	case 13517ULL: goto x86_l_34cd;
	case 13522ULL: goto x86_l_34d2;
	case 13529ULL: goto x86_l_34d9;
	case 13534ULL: goto x86_l_34de;
	case 13537ULL: goto x86_l_34e1;
	case 13539ULL: goto x86_l_34e3;
	case 13542ULL: goto x86_l_34e6;
	case 13547ULL: goto x86_l_34eb;
	case 13554ULL: goto x86_l_34f2;
	case 13557ULL: goto x86_l_34f5;
	case 13559ULL: goto x86_l_34f7;
	case 13564ULL: goto x86_l_34fc;
	case 13567ULL: goto x86_l_34ff;
	case 13572ULL: goto x86_l_3504;
	case 13575ULL: goto x86_l_3507;
	case 13581ULL: goto x86_l_350d;
	case 13587ULL: goto x86_l_3513;
	case 13593ULL: goto x86_l_3519;
	case 13597ULL: goto x86_l_351d;
	case 13602ULL: goto x86_l_3522;
	case 13605ULL: goto x86_l_3525;
	case 13609ULL: goto x86_l_3529;
	case 13614ULL: goto x86_l_352e;
	case 13617ULL: goto x86_l_3531;
	case 13622ULL: goto x86_l_3536;
	case 13624ULL: goto x86_l_3538;
	case 13629ULL: goto x86_l_353d;
	case 13632ULL: goto x86_l_3540;
	case 13634ULL: goto x86_l_3542;
	case 13638ULL: goto x86_l_3546;
	case 13643ULL: goto x86_l_354b;
	case 13647ULL: goto x86_l_354f;
	case 13650ULL: goto x86_l_3552;
	case 13652ULL: goto x86_l_3554;
	case 13658ULL: goto x86_l_355a;
	case 13663ULL: goto x86_l_355f;
	case 13668ULL: goto x86_l_3564;
	case 13670ULL: goto x86_l_3566;
	case 13674ULL: goto x86_l_356a;
	case 13678ULL: goto x86_l_356e;
	case 13683ULL: goto x86_l_3573;
	case 13689ULL: goto x86_l_3579;
	case 13694ULL: goto x86_l_357e;
	case 13700ULL: goto x86_l_3584;
	case 13705ULL: goto x86_l_3589;
	case 13711ULL: goto x86_l_358f;
	case 13716ULL: goto x86_l_3594;
	case 13722ULL: goto x86_l_359a;
	case 13727ULL: goto x86_l_359f;
	case 13734ULL: goto x86_l_35a6;
	case 13739ULL: goto x86_l_35ab;
	case 13744ULL: goto x86_l_35b0;
	case 13750ULL: goto x86_l_35b6;
	case 13755ULL: goto x86_l_35bb;
	case 13761ULL: goto x86_l_35c1;
	case 13766ULL: goto x86_l_35c6;
	case 13772ULL: goto x86_l_35cc;
	case 13777ULL: goto x86_l_35d1;
	case 13784ULL: goto x86_l_35d8;
	case 13789ULL: goto x86_l_35dd;
	case 13792ULL: goto x86_l_35e0;
	case 13794ULL: goto x86_l_35e2;
	case 13797ULL: goto x86_l_35e5;
	case 13800ULL: goto x86_l_35e8;
	case 13804ULL: goto x86_l_35ec;
	case 13809ULL: goto x86_l_35f1;
	case 13813ULL: goto x86_l_35f5;
	case 13819ULL: goto x86_l_35fb;
	case 13823ULL: goto x86_l_35ff;
	case 13829ULL: goto x86_l_3605;
	case 13833ULL: goto x86_l_3609;
	case 13839ULL: goto x86_l_360f;
	case 13844ULL: goto x86_l_3614;
	case 13851ULL: goto x86_l_361b;
	case 13856ULL: goto x86_l_3620;
	case 13861ULL: goto x86_l_3625;
	case 13867ULL: goto x86_l_362b;
	case 13872ULL: goto x86_l_3630;
	case 13878ULL: goto x86_l_3636;
	case 13883ULL: goto x86_l_363b;
	case 13889ULL: goto x86_l_3641;
	case 13894ULL: goto x86_l_3646;
	case 13901ULL: goto x86_l_364d;
	case 13906ULL: goto x86_l_3652;
	case 13908ULL: goto x86_l_3654;
	case 13910ULL: goto x86_l_3656;
	case 13913ULL: goto x86_l_3659;
	case 13916ULL: goto x86_l_365c;
	case 13922ULL: goto x86_l_3662;
	case 13927ULL: goto x86_l_3667;
	case 13932ULL: goto x86_l_366c;
	case 13939ULL: goto x86_l_3673;
	case 13941ULL: goto x86_l_3675;
	case 13946ULL: goto x86_l_367a;
	case 13953ULL: goto x86_l_3681;
	case 13955ULL: goto x86_l_3683;
	case 13960ULL: goto x86_l_3688;
	case 13967ULL: goto x86_l_368f;
	case 13969ULL: goto x86_l_3691;
	case 13974ULL: goto x86_l_3696;
	case 13981ULL: goto x86_l_369d;
	case 13986ULL: goto x86_l_36a2;
	case 13988ULL: goto x86_l_36a4;
	case 13991ULL: goto x86_l_36a7;
	case 13993ULL: goto x86_l_36a9;
	case 13998ULL: goto x86_l_36ae;
	case 14001ULL: goto x86_l_36b1;
	case 14006ULL: goto x86_l_36b6;
	case 14008ULL: goto x86_l_36b8;
	case 14011ULL: goto x86_l_36bb;
	case 14014ULL: goto x86_l_36be;
	case 14018ULL: goto x86_l_36c2;
	case 14020ULL: goto x86_l_36c4;
	case 14023ULL: goto x86_l_36c7;
	case 14028ULL: goto x86_l_36cc;
	case 14031ULL: goto x86_l_36cf;
	case 14036ULL: goto x86_l_36d4;
	case 14041ULL: goto x86_l_36d9;
	case 14048ULL: goto x86_l_36e0;
	case 14050ULL: goto x86_l_36e2;
	case 14055ULL: goto x86_l_36e7;
	case 14062ULL: goto x86_l_36ee;
	case 14064ULL: goto x86_l_36f0;
	case 14069ULL: goto x86_l_36f5;
	case 14076ULL: goto x86_l_36fc;
	case 14078ULL: goto x86_l_36fe;
	case 14083ULL: goto x86_l_3703;
	case 14090ULL: goto x86_l_370a;
	case 14095ULL: goto x86_l_370f;
	case 14097ULL: goto x86_l_3711;
	case 14100ULL: goto x86_l_3714;
	case 14102ULL: goto x86_l_3716;
	case 14107ULL: goto x86_l_371b;
	case 14110ULL: goto x86_l_371e;
	case 14115ULL: goto x86_l_3723;
	case 14117ULL: goto x86_l_3725;
	case 14120ULL: goto x86_l_3728;
	default: return 0xffffffffffffffffULL;
	}
x86_l_30f9:
	/* 0x30f9: cmp    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_30fe:
	/* 0x30fe: je     3667 <generic_fexit_filter_arg+0x3667> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3667;
	}
x86_l_3104:
	/* 0x3104: cmp    DWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_3109:
	/* 0x3109: je     3683 <generic_fexit_filter_arg+0x3683> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3683;
	}
x86_l_310f:
	/* 0x310f: cmp    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_3114:
	/* 0x3114: jne    36c4 <generic_fexit_filter_arg+0x36c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_36c4;
	}
x86_l_311a:
	/* 0x311a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_311f:
	/* 0x311f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_3126:
	/* 0x3126: jmp    369d <generic_fexit_filter_arg+0x369d> */
	goto x86_l_369d;
x86_l_312b:
	/* 0x312b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_312e:
	/* 0x312e: jmp    373d <generic_fexit_filter_arg+0x373d> */
	return 14141ULL;
x86_l_3133:
	/* 0x3133: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3138:
	/* 0x3138: mov    ecx,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_313a:
	/* 0x313a: lea    rdx,[rdi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_313e:
	/* 0x313e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3142:
	/* 0x3142: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3147:
	/* 0x3147: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_314c:
	/* 0x314c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_314e:
	/* 0x314e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3151:
	/* 0x3151: mov    ecx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3155:
	/* 0x3155: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_3157:
	/* 0x3157: je     3294 <generic_fexit_filter_arg+0x3294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3294;
	}
x86_l_315d:
	/* 0x315d: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_3162:
	/* 0x3162: and    eax,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_3167:
	/* 0x3167: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_316d:
	/* 0x316d: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_316f:
	/* 0x316f: je     3297 <generic_fexit_filter_arg+0x3297> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3297;
	}
x86_l_3175:
	/* 0x3175: mov    ecx,DWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3178:
	/* 0x3178: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_317b:
	/* 0x317b: jbe    3294 <generic_fexit_filter_arg+0x3294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3294;
	}
x86_l_3181:
	/* 0x3181: mov    edx,DWORD PTR [rsi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3184:
	/* 0x3184: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_3186:
	/* 0x3186: je     3294 <generic_fexit_filter_arg+0x3294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3294;
	}
x86_l_318c:
	/* 0x318c: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_318e:
	/* 0x318e: je     3297 <generic_fexit_filter_arg+0x3297> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3297;
	}
x86_l_3194:
	/* 0x3194: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_3197:
	/* 0x3197: jb     3294 <generic_fexit_filter_arg+0x3294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3294;
	}
x86_l_319d:
	/* 0x319d: mov    edx,DWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31a0:
	/* 0x31a0: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_31a2:
	/* 0x31a2: je     3294 <generic_fexit_filter_arg+0x3294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3294;
	}
x86_l_31a8:
	/* 0x31a8: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_31aa:
	/* 0x31aa: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_31ad:
	/* 0x31ad: je     3739 <generic_fexit_filter_arg+0x3739> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14137ULL;
	}
x86_l_31b3:
	/* 0x31b3: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_31b6:
	/* 0x31b6: jb     3294 <generic_fexit_filter_arg+0x3294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3294;
	}
x86_l_31bc:
	/* 0x31bc: mov    ecx,DWORD PTR [rsi+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_31bf:
	/* 0x31bf: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_31c1:
	/* 0x31c1: je     3294 <generic_fexit_filter_arg+0x3294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3294;
	}
x86_l_31c7:
	/* 0x31c7: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31ca:
	/* 0x31ca: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_31cc:
	/* 0x31cc: sete   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_E);
x86_l_31d0:
	/* 0x31d0: jmp    3297 <generic_fexit_filter_arg+0x3297> */
	goto x86_l_3297;
x86_l_31d5:
	/* 0x31d5: movzx  r15d,WORD PTR [rdi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_31da:
	/* 0x31da: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_31df:
	/* 0x31df: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_31e3:
	/* 0x31e3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31e8:
	/* 0x31e8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_31ef:
	/* 0x31ef: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_31f4:
	/* 0x31f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31f6:
	/* 0x31f6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31f9:
	/* 0x31f9: je     341a <generic_fexit_filter_arg+0x341a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_341a;
	}
x86_l_31ff:
	/* 0x31ff: movzx  ecx,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3203:
	/* 0x3203: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3208:
	/* 0x3208: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_320d:
	/* 0x320d: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3212:
	/* 0x3212: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3215:
	/* 0x3215: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3217:
	/* 0x3217: mov    edx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_321b:
	/* 0x321b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_321d:
	/* 0x321d: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_3220:
	/* 0x3220: ja     3244 <generic_fexit_filter_arg+0x3244> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3244;
	}
x86_l_3222:
	/* 0x3222: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_3227:
	/* 0x3227: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_322a:
	/* 0x322a: jae    3234 <generic_fexit_filter_arg+0x3234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3234;
	}
x86_l_322c:
	/* 0x322c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_322f:
	/* 0x322f: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_3232:
	/* 0x3232: jmp    3244 <generic_fexit_filter_arg+0x3244> */
	goto x86_l_3244;
x86_l_3234:
	/* 0x3234: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_3239:
	/* 0x3239: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_323c:
	/* 0x323c: jae    3244 <generic_fexit_filter_arg+0x3244> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3244;
	}
x86_l_323e:
	/* 0x323e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3241:
	/* 0x3241: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_3244:
	/* 0x3244: movzx  r15d,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3248:
	/* 0x3248: jmp    37e5 <generic_fexit_filter_arg+0x37e5> */
	return 14309ULL;
x86_l_324d:
	/* 0x324d: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3250:
	/* 0x3250: jne    325b <generic_fexit_filter_arg+0x325b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_325b;
	}
x86_l_3252:
	/* 0x3252: test   QWORD PTR [rdi],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3255:
	/* 0x3255: jne    37ea <generic_fexit_filter_arg+0x37ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14314ULL;
	}
x86_l_325b:
	/* 0x325b: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_325e:
	/* 0x325e: jb     3656 <generic_fexit_filter_arg+0x3656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3656;
	}
x86_l_3264:
	/* 0x3264: mov    rdx,QWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3268:
	/* 0x3268: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_326b:
	/* 0x326b: jb     35dd <generic_fexit_filter_arg+0x35dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_35dd;
	}
x86_l_3271:
	/* 0x3271: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_3274:
	/* 0x3274: je     37ea <generic_fexit_filter_arg+0x37ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14314ULL;
	}
x86_l_327a:
	/* 0x327a: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_327d:
	/* 0x327d: jne    37f4 <generic_fexit_filter_arg+0x37f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14324ULL;
	}
x86_l_3283:
	/* 0x3283: mov    rcx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDI, X86_WIDTH_64);
x86_l_3286:
	/* 0x3286: test   QWORD PTR [rdi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3289:
	/* 0x3289: jne    37ea <generic_fexit_filter_arg+0x37ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14314ULL;
	}
x86_l_328f:
	/* 0x328f: jmp    3656 <generic_fexit_filter_arg+0x3656> */
	goto x86_l_3656;
x86_l_3294:
	/* 0x3294: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3297:
	/* 0x3297: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_329a:
	/* 0x329a: jmp    3739 <generic_fexit_filter_arg+0x3739> */
	return 14137ULL;
x86_l_329f:
	/* 0x329f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32a2:
	/* 0x32a2: jmp    347b <generic_fexit_filter_arg+0x347b> */
	goto x86_l_347b;
x86_l_32a7:
	/* 0x32a7: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_32aa:
	/* 0x32aa: mov    ecx,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R8, X86_WIDTH_32);
x86_l_32ad:
	/* 0x32ad: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_32af:
	/* 0x32af: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_32b1:
	/* 0x32b1: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_32b4:
	/* 0x32b4: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_32b9:
	/* 0x32b9: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_32bd:
	/* 0x32bd: ja     32cd <generic_fexit_filter_arg+0x32cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_32cd;
	}
x86_l_32bf:
	/* 0x32bf: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_32c2:
	/* 0x32c2: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_32c8:
	/* 0x32c8: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_32cb:
	/* 0x32cb: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_32cd:
	/* 0x32cd: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_32d1:
	/* 0x32d1: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32d4:
	/* 0x32d4: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_32d7:
	/* 0x32d7: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32dc:
	/* 0x32dc: mov    eax,DWORD PTR [rcx+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_32e0:
	/* 0x32e0: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_32e4:
	/* 0x32e4: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_32e7:
	/* 0x32e7: je     3731 <generic_fexit_filter_arg+0x3731> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14129ULL;
	}
x86_l_32ed:
	/* 0x32ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32f2:
	/* 0x32f2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_32f9:
	/* 0x32f9: lea    r15,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_32fe:
	/* 0x32fe: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3301:
	/* 0x3301: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3303:
	/* 0x3303: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3306:
	/* 0x3306: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_330b:
	/* 0x330b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3312:
	/* 0x3312: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3315:
	/* 0x3315: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3317:
	/* 0x3317: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_331c:
	/* 0x331c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_331f:
	/* 0x331f: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3324:
	/* 0x3324: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_3327:
	/* 0x3327: je     3734 <generic_fexit_filter_arg+0x3734> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14132ULL;
	}
x86_l_332d:
	/* 0x332d: cmp    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_3333:
	/* 0x3333: je     3734 <generic_fexit_filter_arg+0x3734> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14132ULL;
	}
x86_l_3339:
	/* 0x3339: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_333e:
	/* 0x333e: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3342:
	/* 0x3342: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3347:
	/* 0x3347: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_334c:
	/* 0x334c: mov    BYTE PTR [rax],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_334f:
	/* 0x334f: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3353:
	/* 0x3353: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3358:
	/* 0x3358: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_335b:
	/* 0x335b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_335d:
	/* 0x335d: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_3362:
	/* 0x3362: cmp    esi,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_3365:
	/* 0x3365: jbe    338a <generic_fexit_filter_arg+0x338a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_338a;
	}
x86_l_3367:
	/* 0x3367: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_336a:
	/* 0x336a: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_336f:
	/* 0x336f: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3373:
	/* 0x3373: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_3376:
	/* 0x3376: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3378:
	/* 0x3378: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_337e:
	/* 0x337e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3383:
	/* 0x3383: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3388:
	/* 0x3388: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_338a:
	/* 0x338a: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_338e:
	/* 0x338e: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3392:
	/* 0x3392: cmp    DWORD PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3396:
	/* 0x3396: jg     35f1 <generic_fexit_filter_arg+0x35f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_35f1;
	}
x86_l_339c:
	/* 0x339c: cmp    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33a0:
	/* 0x33a0: je     36d4 <generic_fexit_filter_arg+0x36d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36d4;
	}
x86_l_33a6:
	/* 0x33a6: cmp    DWORD PTR [rsp],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_33aa:
	/* 0x33aa: je     36f0 <generic_fexit_filter_arg+0x36f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36f0;
	}
x86_l_33b0:
	/* 0x33b0: cmp    DWORD PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_33b4:
	/* 0x33b4: jne    3731 <generic_fexit_filter_arg+0x3731> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14129ULL;
	}
x86_l_33ba:
	/* 0x33ba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33bf:
	/* 0x33bf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_33c6:
	/* 0x33c6: jmp    370a <generic_fexit_filter_arg+0x370a> */
	goto x86_l_370a;
x86_l_33cb:
	/* 0x33cb: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33ce:
	/* 0x33ce: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_33d1:
	/* 0x33d1: jne    33dd <generic_fexit_filter_arg+0x33dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_33dd;
	}
x86_l_33d3:
	/* 0x33d3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_33d6:
	/* 0x33d6: je     33dd <generic_fexit_filter_arg+0x33dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33dd;
	}
x86_l_33d8:
	/* 0x33d8: movzx  r15d,BYTE PTR [rdx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_33dd:
	/* 0x33dd: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_33e0:
	/* 0x33e0: je     33e7 <generic_fexit_filter_arg+0x33e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33e7;
	}
x86_l_33e2:
	/* 0x33e2: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_33e5:
	/* 0x33e5: jne    341a <generic_fexit_filter_arg+0x341a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_341a;
	}
x86_l_33e7:
	/* 0x33e7: movzx  eax,BYTE PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_33ec:
	/* 0x33ec: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_33f0:
	/* 0x33f0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33f5:
	/* 0x33f5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_33fc:
	/* 0x33fc: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3401:
	/* 0x3401: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3403:
	/* 0x3403: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3406:
	/* 0x3406: je     341a <generic_fexit_filter_arg+0x341a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_341a;
	}
x86_l_3408:
	/* 0x3408: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_340b:
	/* 0x340b: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3410:
	/* 0x3410: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3415:
	/* 0x3415: jmp    320d <generic_fexit_filter_arg+0x320d> */
	goto x86_l_320d;
x86_l_341a:
	/* 0x341a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_341d:
	/* 0x341d: jmp    37e5 <generic_fexit_filter_arg+0x37e5> */
	return 14309ULL;
x86_l_3422:
	/* 0x3422: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3425:
	/* 0x3425: jne    342f <generic_fexit_filter_arg+0x342f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_342f;
	}
x86_l_3427:
	/* 0x3427: test   DWORD PTR [rdi],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3429:
	/* 0x3429: jne    37ea <generic_fexit_filter_arg+0x37ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14314ULL;
	}
x86_l_342f:
	/* 0x342f: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_3432:
	/* 0x3432: jb     3656 <generic_fexit_filter_arg+0x3656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3656;
	}
x86_l_3438:
	/* 0x3438: mov    edx,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_343c:
	/* 0x343c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_343f:
	/* 0x343f: jb     3652 <generic_fexit_filter_arg+0x3652> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3652;
	}
x86_l_3445:
	/* 0x3445: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_3448:
	/* 0x3448: je     37ea <generic_fexit_filter_arg+0x37ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14314ULL;
	}
x86_l_344e:
	/* 0x344e: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3451:
	/* 0x3451: jne    37f4 <generic_fexit_filter_arg+0x37f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14324ULL;
	}
x86_l_3457:
	/* 0x3457: mov    rcx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDI, X86_WIDTH_64);
x86_l_345a:
	/* 0x345a: test   DWORD PTR [rdi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_345c:
	/* 0x345c: jne    37ea <generic_fexit_filter_arg+0x37ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14314ULL;
	}
x86_l_3462:
	/* 0x3462: jmp    3656 <generic_fexit_filter_arg+0x3656> */
	goto x86_l_3656;
x86_l_3467:
	/* 0x3467: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_346b:
	/* 0x346b: jmp    3475 <generic_fexit_filter_arg+0x3475> */
	goto x86_l_3475;
x86_l_346d:
	/* 0x346d: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3472:
	/* 0x3472: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3475:
	/* 0x3475: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_3478:
	/* 0x3478: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_347b:
	/* 0x347b: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_347e:
	/* 0x347e: movzx  r15d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3482:
	/* 0x3482: jmp    37e5 <generic_fexit_filter_arg+0x37e5> */
	return 14309ULL;
x86_l_3487:
	/* 0x3487: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_348a:
	/* 0x348a: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_348c:
	/* 0x348c: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_348e:
	/* 0x348e: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_3490:
	/* 0x3490: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_3493:
	/* 0x3493: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_3498:
	/* 0x3498: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_349c:
	/* 0x349c: ja     34ac <generic_fexit_filter_arg+0x34ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_34ac;
	}
x86_l_349e:
	/* 0x349e: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_34a1:
	/* 0x34a1: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_34a7:
	/* 0x34a7: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_34aa:
	/* 0x34aa: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_34ac:
	/* 0x34ac: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_34b0:
	/* 0x34b0: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_34b4:
	/* 0x34b4: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_34b7:
	/* 0x34b7: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34bc:
	/* 0x34bc: mov    eax,DWORD PTR [rcx+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_34c0:
	/* 0x34c0: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_34c4:
	/* 0x34c4: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_34c7:
	/* 0x34c7: je     37be <generic_fexit_filter_arg+0x37be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14270ULL;
	}
x86_l_34cd:
	/* 0x34cd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34d2:
	/* 0x34d2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_34d9:
	/* 0x34d9: lea    r15,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_34de:
	/* 0x34de: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_34e1:
	/* 0x34e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34e3:
	/* 0x34e3: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_34e6:
	/* 0x34e6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34eb:
	/* 0x34eb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_34f2:
	/* 0x34f2: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_34f5:
	/* 0x34f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34f7:
	/* 0x34f7: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_34fc:
	/* 0x34fc: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34ff:
	/* 0x34ff: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3504:
	/* 0x3504: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_3507:
	/* 0x3507: je     37c1 <generic_fexit_filter_arg+0x37c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14273ULL;
	}
x86_l_350d:
	/* 0x350d: cmp    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_3513:
	/* 0x3513: je     37c1 <generic_fexit_filter_arg+0x37c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14273ULL;
	}
x86_l_3519:
	/* 0x3519: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_351d:
	/* 0x351d: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3522:
	/* 0x3522: mov    BYTE PTR [rax],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3525:
	/* 0x3525: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3529:
	/* 0x3529: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_352e:
	/* 0x352e: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_3531:
	/* 0x3531: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3536:
	/* 0x3536: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3538:
	/* 0x3538: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_353d:
	/* 0x353d: cmp    esi,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_3540:
	/* 0x3540: jbe    3566 <generic_fexit_filter_arg+0x3566> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3566;
	}
x86_l_3542:
	/* 0x3542: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3546:
	/* 0x3546: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_354b:
	/* 0x354b: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_354f:
	/* 0x354f: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_3552:
	/* 0x3552: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3554:
	/* 0x3554: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_355a:
	/* 0x355a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_355f:
	/* 0x355f: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3564:
	/* 0x3564: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3566:
	/* 0x3566: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_356a:
	/* 0x356a: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_356e:
	/* 0x356e: cmp    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_3573:
	/* 0x3573: jg     3620 <generic_fexit_filter_arg+0x3620> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3620;
	}
x86_l_3579:
	/* 0x3579: cmp    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_357e:
	/* 0x357e: je     3761 <generic_fexit_filter_arg+0x3761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14177ULL;
	}
x86_l_3584:
	/* 0x3584: cmp    DWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_3589:
	/* 0x3589: je     377d <generic_fexit_filter_arg+0x377d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14205ULL;
	}
x86_l_358f:
	/* 0x358f: cmp    DWORD PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_3594:
	/* 0x3594: jne    37be <generic_fexit_filter_arg+0x37be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14270ULL;
	}
x86_l_359a:
	/* 0x359a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_359f:
	/* 0x359f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_35a6:
	/* 0x35a6: jmp    3797 <generic_fexit_filter_arg+0x3797> */
	return 14231ULL;
x86_l_35ab:
	/* 0x35ab: cmp    DWORD PTR [rsp+0x18],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215107ULL);
x86_l_35b0:
	/* 0x35b0: je     3675 <generic_fexit_filter_arg+0x3675> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3675;
	}
x86_l_35b6:
	/* 0x35b6: cmp    DWORD PTR [rsp+0x18],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215108ULL);
x86_l_35bb:
	/* 0x35bb: je     3691 <generic_fexit_filter_arg+0x3691> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3691;
	}
x86_l_35c1:
	/* 0x35c1: cmp    DWORD PTR [rsp+0x18],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215109ULL);
x86_l_35c6:
	/* 0x35c6: jne    36c4 <generic_fexit_filter_arg+0x36c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_36c4;
	}
x86_l_35cc:
	/* 0x35cc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35d1:
	/* 0x35d1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_35d8:
	/* 0x35d8: jmp    369d <generic_fexit_filter_arg+0x369d> */
	goto x86_l_369d;
x86_l_35dd:
	/* 0x35dd: cmp    QWORD PTR [rdi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35e0:
	/* 0x35e0: jne    3656 <generic_fexit_filter_arg+0x3656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3656;
	}
x86_l_35e2:
	/* 0x35e2: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35e5:
	/* 0x35e5: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_35e8:
	/* 0x35e8: sete   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_E);
x86_l_35ec:
	/* 0x35ec: jmp    37e5 <generic_fexit_filter_arg+0x37e5> */
	return 14309ULL;
x86_l_35f1:
	/* 0x35f1: cmp    DWORD PTR [rsp],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_35f5:
	/* 0x35f5: je     36e2 <generic_fexit_filter_arg+0x36e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36e2;
	}
x86_l_35fb:
	/* 0x35fb: cmp    DWORD PTR [rsp],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_35ff:
	/* 0x35ff: je     36fe <generic_fexit_filter_arg+0x36fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36fe;
	}
x86_l_3605:
	/* 0x3605: cmp    DWORD PTR [rsp],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_3609:
	/* 0x3609: jne    3731 <generic_fexit_filter_arg+0x3731> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14129ULL;
	}
x86_l_360f:
	/* 0x360f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3614:
	/* 0x3614: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_361b:
	/* 0x361b: jmp    370a <generic_fexit_filter_arg+0x370a> */
	goto x86_l_370a;
x86_l_3620:
	/* 0x3620: cmp    DWORD PTR [rsp+0x18],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215107ULL);
x86_l_3625:
	/* 0x3625: je     376f <generic_fexit_filter_arg+0x376f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14191ULL;
	}
x86_l_362b:
	/* 0x362b: cmp    DWORD PTR [rsp+0x18],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215108ULL);
x86_l_3630:
	/* 0x3630: je     378b <generic_fexit_filter_arg+0x378b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14219ULL;
	}
x86_l_3636:
	/* 0x3636: cmp    DWORD PTR [rsp+0x18],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215109ULL);
x86_l_363b:
	/* 0x363b: jne    37be <generic_fexit_filter_arg+0x37be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14270ULL;
	}
x86_l_3641:
	/* 0x3641: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3646:
	/* 0x3646: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_364d:
	/* 0x364d: jmp    3797 <generic_fexit_filter_arg+0x3797> */
	return 14231ULL;
x86_l_3652:
	/* 0x3652: cmp    DWORD PTR [rdi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3654:
	/* 0x3654: je     35e2 <generic_fexit_filter_arg+0x35e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35e2;
	}
x86_l_3656:
	/* 0x3656: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_3659:
	/* 0x3659: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_365c:
	/* 0x365c: je     37ea <generic_fexit_filter_arg+0x37ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14314ULL;
	}
x86_l_3662:
	/* 0x3662: jmp    37f4 <generic_fexit_filter_arg+0x37f4> */
	return 14324ULL;
x86_l_3667:
	/* 0x3667: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_366c:
	/* 0x366c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_3673:
	/* 0x3673: jmp    369d <generic_fexit_filter_arg+0x369d> */
	goto x86_l_369d;
x86_l_3675:
	/* 0x3675: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_367a:
	/* 0x367a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_3681:
	/* 0x3681: jmp    369d <generic_fexit_filter_arg+0x369d> */
	goto x86_l_369d;
x86_l_3683:
	/* 0x3683: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3688:
	/* 0x3688: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_368f:
	/* 0x368f: jmp    369d <generic_fexit_filter_arg+0x369d> */
	goto x86_l_369d;
x86_l_3691:
	/* 0x3691: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3696:
	/* 0x3696: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_369d:
	/* 0x369d: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_36a2:
	/* 0x36a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36a4:
	/* 0x36a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36a7:
	/* 0x36a7: je     36c4 <generic_fexit_filter_arg+0x36c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36c4;
	}
x86_l_36a9:
	/* 0x36a9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_36ae:
	/* 0x36ae: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_36b1:
	/* 0x36b1: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_36b6:
	/* 0x36b6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_36b8:
	/* 0x36b8: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36bb:
	/* 0x36bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36be:
	/* 0x36be: setne  r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_NE);
x86_l_36c2:
	/* 0x36c2: jmp    36c7 <generic_fexit_filter_arg+0x36c7> */
	goto x86_l_36c7;
x86_l_36c4:
	/* 0x36c4: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36c7:
	/* 0x36c7: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36cc:
	/* 0x36cc: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_36cf:
	/* 0x36cf: jmp    37ca <generic_fexit_filter_arg+0x37ca> */
	return 14282ULL;
x86_l_36d4:
	/* 0x36d4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36d9:
	/* 0x36d9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_36e0:
	/* 0x36e0: jmp    370a <generic_fexit_filter_arg+0x370a> */
	goto x86_l_370a;
x86_l_36e2:
	/* 0x36e2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36e7:
	/* 0x36e7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_36ee:
	/* 0x36ee: jmp    370a <generic_fexit_filter_arg+0x370a> */
	goto x86_l_370a;
x86_l_36f0:
	/* 0x36f0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36f5:
	/* 0x36f5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_36fc:
	/* 0x36fc: jmp    370a <generic_fexit_filter_arg+0x370a> */
	goto x86_l_370a;
x86_l_36fe:
	/* 0x36fe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3703:
	/* 0x3703: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_370a:
	/* 0x370a: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_370f:
	/* 0x370f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3711:
	/* 0x3711: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3714:
	/* 0x3714: je     3731 <generic_fexit_filter_arg+0x3731> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14129ULL;
	}
x86_l_3716:
	/* 0x3716: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_371b:
	/* 0x371b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_371e:
	/* 0x371e: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3723:
	/* 0x3723: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3725:
	/* 0x3725: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3728:
	/* 0x3728: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 14123ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14123ULL: goto x86_l_372b;
	case 14127ULL: goto x86_l_372f;
	case 14129ULL: goto x86_l_3731;
	case 14132ULL: goto x86_l_3734;
	case 14137ULL: goto x86_l_3739;
	case 14141ULL: goto x86_l_373d;
	case 14144ULL: goto x86_l_3740;
	case 14150ULL: goto x86_l_3746;
	case 14152ULL: goto x86_l_3748;
	case 14162ULL: goto x86_l_3752;
	case 14166ULL: goto x86_l_3756;
	case 14172ULL: goto x86_l_375c;
	case 14177ULL: goto x86_l_3761;
	case 14182ULL: goto x86_l_3766;
	case 14189ULL: goto x86_l_376d;
	case 14191ULL: goto x86_l_376f;
	case 14196ULL: goto x86_l_3774;
	case 14203ULL: goto x86_l_377b;
	case 14205ULL: goto x86_l_377d;
	case 14210ULL: goto x86_l_3782;
	case 14217ULL: goto x86_l_3789;
	case 14219ULL: goto x86_l_378b;
	case 14224ULL: goto x86_l_3790;
	case 14231ULL: goto x86_l_3797;
	case 14236ULL: goto x86_l_379c;
	case 14238ULL: goto x86_l_379e;
	case 14241ULL: goto x86_l_37a1;
	case 14243ULL: goto x86_l_37a3;
	case 14248ULL: goto x86_l_37a8;
	case 14251ULL: goto x86_l_37ab;
	case 14256ULL: goto x86_l_37b0;
	case 14258ULL: goto x86_l_37b2;
	case 14261ULL: goto x86_l_37b5;
	case 14264ULL: goto x86_l_37b8;
	case 14268ULL: goto x86_l_37bc;
	case 14270ULL: goto x86_l_37be;
	case 14273ULL: goto x86_l_37c1;
	case 14278ULL: goto x86_l_37c6;
	case 14282ULL: goto x86_l_37ca;
	case 14285ULL: goto x86_l_37cd;
	case 14287ULL: goto x86_l_37cf;
	case 14289ULL: goto x86_l_37d1;
	case 14299ULL: goto x86_l_37db;
	case 14303ULL: goto x86_l_37df;
	case 14305ULL: goto x86_l_37e1;
	case 14309ULL: goto x86_l_37e5;
	case 14312ULL: goto x86_l_37e8;
	case 14314ULL: goto x86_l_37ea;
	case 14318ULL: goto x86_l_37ee;
	case 14320ULL: goto x86_l_37f0;
	case 14322ULL: goto x86_l_37f2;
	case 14324ULL: goto x86_l_37f4;
	case 14328ULL: goto x86_l_37f8;
	case 14330ULL: goto x86_l_37fa;
	case 14334ULL: goto x86_l_37fe;
	case 14340ULL: goto x86_l_3804;
	case 14343ULL: goto x86_l_3807;
	case 14349ULL: goto x86_l_380d;
	case 14353ULL: goto x86_l_3811;
	case 14359ULL: goto x86_l_3817;
	case 14361ULL: goto x86_l_3819;
	case 14365ULL: goto x86_l_381d;
	case 14371ULL: goto x86_l_3823;
	case 14375ULL: goto x86_l_3827;
	case 14381ULL: goto x86_l_382d;
	case 14385ULL: goto x86_l_3831;
	case 14391ULL: goto x86_l_3837;
	case 14395ULL: goto x86_l_383b;
	case 14401ULL: goto x86_l_3841;
	case 14404ULL: goto x86_l_3844;
	case 14409ULL: goto x86_l_3849;
	case 14416ULL: goto x86_l_3850;
	case 14421ULL: goto x86_l_3855;
	case 14428ULL: goto x86_l_385c;
	case 14431ULL: goto x86_l_385f;
	case 14436ULL: goto x86_l_3864;
	case 14438ULL: goto x86_l_3866;
	case 14443ULL: goto x86_l_386b;
	case 14450ULL: goto x86_l_3872;
	case 14453ULL: goto x86_l_3875;
	case 14458ULL: goto x86_l_387a;
	case 14460ULL: goto x86_l_387c;
	case 14462ULL: goto x86_l_387e;
	case 14469ULL: goto x86_l_3885;
	case 14471ULL: goto x86_l_3887;
	case 14472ULL: goto x86_l_3888;
	case 14477ULL: goto x86_l_388d;
	case 14480ULL: goto x86_l_3890;
	case 14488ULL: goto x86_l_3898;
	case 14490ULL: goto x86_l_389a;
	case 14496ULL: goto x86_l_38a0;
	case 14504ULL: goto x86_l_38a8;
	case 14506ULL: goto x86_l_38aa;
	case 14512ULL: goto x86_l_38b0;
	case 14520ULL: goto x86_l_38b8;
	case 14522ULL: goto x86_l_38ba;
	case 14528ULL: goto x86_l_38c0;
	case 14536ULL: goto x86_l_38c8;
	case 14538ULL: goto x86_l_38ca;
	case 14544ULL: goto x86_l_38d0;
	case 14552ULL: goto x86_l_38d8;
	case 14554ULL: goto x86_l_38da;
	case 14560ULL: goto x86_l_38e0;
	case 14568ULL: goto x86_l_38e8;
	case 14570ULL: goto x86_l_38ea;
	case 14577ULL: goto x86_l_38f1;
	case 14582ULL: goto x86_l_38f6;
	case 14589ULL: goto x86_l_38fd;
	case 14592ULL: goto x86_l_3900;
	case 14597ULL: goto x86_l_3905;
	case 14599ULL: goto x86_l_3907;
	case 14603ULL: goto x86_l_390b;
	case 14608ULL: goto x86_l_3910;
	case 14610ULL: goto x86_l_3912;
	case 14615ULL: goto x86_l_3917;
	case 14620ULL: goto x86_l_391c;
	case 14625ULL: goto x86_l_3921;
	case 14632ULL: goto x86_l_3928;
	case 14637ULL: goto x86_l_392d;
	case 14639ULL: goto x86_l_392f;
	case 14642ULL: goto x86_l_3932;
	case 14648ULL: goto x86_l_3938;
	case 14653ULL: goto x86_l_393d;
	case 14660ULL: goto x86_l_3944;
	case 14665ULL: goto x86_l_3949;
	case 14667ULL: goto x86_l_394b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_372b:
	/* 0x372b: setne  r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_NE);
x86_l_372f:
	/* 0x372f: jmp    3734 <generic_fexit_filter_arg+0x3734> */
	goto x86_l_3734;
x86_l_3731:
	/* 0x3731: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3734:
	/* 0x3734: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3739:
	/* 0x3739: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_373d:
	/* 0x373d: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_3740:
	/* 0x3740: ja     37e5 <generic_fexit_filter_arg+0x37e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_37e5;
	}
x86_l_3746:
	/* 0x3746: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3748:
	/* 0x3748: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_3752:
	/* 0x3752: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3756:
	/* 0x3756: jb     37e1 <generic_fexit_filter_arg+0x37e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_37e1;
	}
x86_l_375c:
	/* 0x375c: jmp    37e5 <generic_fexit_filter_arg+0x37e5> */
	goto x86_l_37e5;
x86_l_3761:
	/* 0x3761: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3766:
	/* 0x3766: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_376d:
	/* 0x376d: jmp    3797 <generic_fexit_filter_arg+0x3797> */
	goto x86_l_3797;
x86_l_376f:
	/* 0x376f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3774:
	/* 0x3774: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_377b:
	/* 0x377b: jmp    3797 <generic_fexit_filter_arg+0x3797> */
	goto x86_l_3797;
x86_l_377d:
	/* 0x377d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3782:
	/* 0x3782: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_3789:
	/* 0x3789: jmp    3797 <generic_fexit_filter_arg+0x3797> */
	goto x86_l_3797;
x86_l_378b:
	/* 0x378b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3790:
	/* 0x3790: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_3797:
	/* 0x3797: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_379c:
	/* 0x379c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_379e:
	/* 0x379e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_37a1:
	/* 0x37a1: je     37be <generic_fexit_filter_arg+0x37be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37be;
	}
x86_l_37a3:
	/* 0x37a3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_37a8:
	/* 0x37a8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_37ab:
	/* 0x37ab: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_37b0:
	/* 0x37b0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_37b2:
	/* 0x37b2: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37b5:
	/* 0x37b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_37b8:
	/* 0x37b8: setne  r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_NE);
x86_l_37bc:
	/* 0x37bc: jmp    37c1 <generic_fexit_filter_arg+0x37c1> */
	goto x86_l_37c1;
x86_l_37be:
	/* 0x37be: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37c1:
	/* 0x37c1: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37c6:
	/* 0x37c6: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_37ca:
	/* 0x37ca: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_37cd:
	/* 0x37cd: ja     37e5 <generic_fexit_filter_arg+0x37e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_37e5;
	}
x86_l_37cf:
	/* 0x37cf: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37d1:
	/* 0x37d1: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_37db:
	/* 0x37db: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_37df:
	/* 0x37df: jae    37e5 <generic_fexit_filter_arg+0x37e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_37e5;
	}
x86_l_37e1:
	/* 0x37e1: xor    r15,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_37e5:
	/* 0x37e5: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_37e8:
	/* 0x37e8: je     37f4 <generic_fexit_filter_arg+0x37f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37f4;
	}
x86_l_37ea:
	/* 0x37ea: cmp    rbp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 1ULL);
x86_l_37ee:
	/* 0x37ee: je     3866 <generic_fexit_filter_arg+0x3866> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3866;
	}
x86_l_37f0:
	/* 0x37f0: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_37f2:
	/* 0x37f2: jne    3849 <generic_fexit_filter_arg+0x3849> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3849;
	}
x86_l_37f4:
	/* 0x37f4: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_37f8:
	/* 0x37f8: jg     3819 <generic_fexit_filter_arg+0x3819> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3819;
	}
x86_l_37fa:
	/* 0x37fa: cmp    r12d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_37fe:
	/* 0x37fe: je     388d <generic_fexit_filter_arg+0x388d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_388d;
	}
x86_l_3804:
	/* 0x3804: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_3807:
	/* 0x3807: je     389a <generic_fexit_filter_arg+0x389a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_389a;
	}
x86_l_380d:
	/* 0x380d: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_3811:
	/* 0x3811: je     38aa <generic_fexit_filter_arg+0x38aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38aa;
	}
x86_l_3817:
	/* 0x3817: jmp    3837 <generic_fexit_filter_arg+0x3837> */
	goto x86_l_3837;
x86_l_3819:
	/* 0x3819: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_381d:
	/* 0x381d: je     38ba <generic_fexit_filter_arg+0x38ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38ba;
	}
x86_l_3823:
	/* 0x3823: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_3827:
	/* 0x3827: je     38ca <generic_fexit_filter_arg+0x38ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38ca;
	}
x86_l_382d:
	/* 0x382d: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_3831:
	/* 0x3831: je     38da <generic_fexit_filter_arg+0x38da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38da;
	}
x86_l_3837:
	/* 0x3837: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_383b:
	/* 0x383b: jg     3907 <generic_fexit_filter_arg+0x3907> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3907;
	}
x86_l_3841:
	/* 0x3841: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3844:
	/* 0x3844: jmp    38ea <generic_fexit_filter_arg+0x38ea> */
	goto x86_l_38ea;
x86_l_3849:
	/* 0x3849: mov    DWORD PTR [r14+0x5ef4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_3850:
	/* 0x3850: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3855:
	/* 0x3855: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fexit_calls)));
x86_l_385c:
	/* 0x385c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_385f:
	/* 0x385f: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3864:
	/* 0x3864: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3866:
	/* 0x3866: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_386b:
	/* 0x386b: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fexit_calls)));
x86_l_3872:
	/* 0x3872: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3875:
	/* 0x3875: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_387a:
	/* 0x387a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_387c:
	/* 0x387c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_387e:
	/* 0x387e: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_3885:
	/* 0x3885: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3887:
	/* 0x3887: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3888:
	/* 0x3888: jmp    3950 <generic_fexit_filter_arg+0x3950> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_388d:
	/* 0x388d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3890:
	/* 0x3890: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_3898:
	/* 0x3898: jne    38ea <generic_fexit_filter_arg+0x38ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_38ea;
	}
x86_l_389a:
	/* 0x389a: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_38a0:
	/* 0x38a0: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_38a8:
	/* 0x38a8: jne    38ea <generic_fexit_filter_arg+0x38ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_38ea;
	}
x86_l_38aa:
	/* 0x38aa: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_38b0:
	/* 0x38b0: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_38b8:
	/* 0x38b8: jne    38ea <generic_fexit_filter_arg+0x38ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_38ea;
	}
x86_l_38ba:
	/* 0x38ba: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_38c0:
	/* 0x38c0: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_38c8:
	/* 0x38c8: jne    38ea <generic_fexit_filter_arg+0x38ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_38ea;
	}
x86_l_38ca:
	/* 0x38ca: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_38d0:
	/* 0x38d0: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_38d8:
	/* 0x38d8: jne    38ea <generic_fexit_filter_arg+0x38ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_38ea;
	}
x86_l_38da:
	/* 0x38da: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_38e0:
	/* 0x38e0: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_38e8:
	/* 0x38e8: je     3907 <generic_fexit_filter_arg+0x3907> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3907;
	}
x86_l_38ea:
	/* 0x38ea: mov    DWORD PTR [r14+0x5ef0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_38f1:
	/* 0x38f1: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_38f6:
	/* 0x38f6: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fexit_calls)));
x86_l_38fd:
	/* 0x38fd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3900:
	/* 0x3900: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3905:
	/* 0x3905: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3907:
	/* 0x3907: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_390b:
	/* 0x390b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3910:
	/* 0x3910: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3912:
	/* 0x3912: mov    QWORD PTR [rsp+0x50],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3917:
	/* 0x3917: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_391c:
	/* 0x391c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3921:
	/* 0x3921: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_3928:
	/* 0x3928: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_392d:
	/* 0x392d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_392f:
	/* 0x392f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3932:
	/* 0x3932: je     387c <generic_fexit_filter_arg+0x387c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_387c;
	}
x86_l_3938:
	/* 0x3938: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_393d:
	/* 0x393d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_3944:
	/* 0x3944: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3949:
	/* 0x3949: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_394b:
	/* 0x394b: jmp    387c <generic_fexit_filter_arg+0x387c> */
	goto x86_l_387c;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 12792U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1809ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1812ULL && __x86_pc <= 3615ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3621ULL && __x86_pc <= 5439ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5445ULL && __x86_pc <= 7242ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7245ULL && __x86_pc <= 8948ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8954ULL && __x86_pc <= 10868ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10874ULL && __x86_pc <= 12531ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12537ULL && __x86_pc <= 14120ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14123ULL && __x86_pc <= 14667ULL)
			__x86_pc = tetragon_bpf_generic_fexit_generic_fexit_filter_arg_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

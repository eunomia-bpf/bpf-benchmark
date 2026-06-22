extern char addr4lpm_maps;
extern char addr6lpm_maps;
extern char argfilter_maps;
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
extern char usdt_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 21ULL: goto x86_l_15;
	case 26ULL: goto x86_l_1a;
	case 33ULL: goto x86_l_21;
	case 38ULL: goto x86_l_26;
	case 40ULL: goto x86_l_28;
	case 43ULL: goto x86_l_2b;
	case 49ULL: goto x86_l_31;
	case 52ULL: goto x86_l_34;
	case 59ULL: goto x86_l_3b;
	case 66ULL: goto x86_l_42;
	case 71ULL: goto x86_l_47;
	case 78ULL: goto x86_l_4e;
	case 80ULL: goto x86_l_50;
	case 83ULL: goto x86_l_53;
	case 89ULL: goto x86_l_59;
	case 97ULL: goto x86_l_61;
	case 103ULL: goto x86_l_67;
	case 106ULL: goto x86_l_6a;
	case 109ULL: goto x86_l_6d;
	case 118ULL: goto x86_l_76;
	case 124ULL: goto x86_l_7c;
	case 126ULL: goto x86_l_7e;
	case 130ULL: goto x86_l_82;
	case 134ULL: goto x86_l_86;
	case 138ULL: goto x86_l_8a;
	case 142ULL: goto x86_l_8e;
	case 146ULL: goto x86_l_92;
	case 152ULL: goto x86_l_98;
	case 155ULL: goto x86_l_9b;
	case 158ULL: goto x86_l_9e;
	case 162ULL: goto x86_l_a2;
	case 164ULL: goto x86_l_a4;
	case 170ULL: goto x86_l_aa;
	case 173ULL: goto x86_l_ad;
	case 176ULL: goto x86_l_b0;
	case 178ULL: goto x86_l_b2;
	case 184ULL: goto x86_l_b8;
	case 187ULL: goto x86_l_bb;
	case 190ULL: goto x86_l_be;
	case 192ULL: goto x86_l_c0;
	case 198ULL: goto x86_l_c6;
	case 201ULL: goto x86_l_c9;
	case 204ULL: goto x86_l_cc;
	case 206ULL: goto x86_l_ce;
	case 212ULL: goto x86_l_d4;
	case 215ULL: goto x86_l_d7;
	case 218ULL: goto x86_l_da;
	case 220ULL: goto x86_l_dc;
	case 226ULL: goto x86_l_e2;
	case 230ULL: goto x86_l_e6;
	case 236ULL: goto x86_l_ec;
	case 240ULL: goto x86_l_f0;
	case 246ULL: goto x86_l_f6;
	case 252ULL: goto x86_l_fc;
	case 254ULL: goto x86_l_fe;
	case 260ULL: goto x86_l_104;
	case 263ULL: goto x86_l_107;
	case 267ULL: goto x86_l_10b;
	case 273ULL: goto x86_l_111;
	case 282ULL: goto x86_l_11a;
	case 288ULL: goto x86_l_120;
	case 291ULL: goto x86_l_123;
	case 294ULL: goto x86_l_126;
	case 298ULL: goto x86_l_12a;
	case 306ULL: goto x86_l_132;
	case 311ULL: goto x86_l_137;
	case 315ULL: goto x86_l_13b;
	case 322ULL: goto x86_l_142;
	case 325ULL: goto x86_l_145;
	case 327ULL: goto x86_l_147;
	case 330ULL: goto x86_l_14a;
	case 336ULL: goto x86_l_150;
	case 339ULL: goto x86_l_153;
	case 345ULL: goto x86_l_159;
	case 348ULL: goto x86_l_15c;
	case 354ULL: goto x86_l_162;
	case 357ULL: goto x86_l_165;
	case 359ULL: goto x86_l_167;
	case 364ULL: goto x86_l_16c;
	case 367ULL: goto x86_l_16f;
	case 373ULL: goto x86_l_175;
	case 376ULL: goto x86_l_178;
	case 379ULL: goto x86_l_17b;
	case 385ULL: goto x86_l_181;
	case 388ULL: goto x86_l_184;
	case 391ULL: goto x86_l_187;
	case 394ULL: goto x86_l_18a;
	case 400ULL: goto x86_l_190;
	case 403ULL: goto x86_l_193;
	case 407ULL: goto x86_l_197;
	case 412ULL: goto x86_l_19c;
	case 415ULL: goto x86_l_19f;
	case 421ULL: goto x86_l_1a5;
	case 426ULL: goto x86_l_1aa;
	case 429ULL: goto x86_l_1ad;
	case 435ULL: goto x86_l_1b3;
	case 440ULL: goto x86_l_1b8;
	case 443ULL: goto x86_l_1bb;
	case 449ULL: goto x86_l_1c1;
	case 454ULL: goto x86_l_1c6;
	case 458ULL: goto x86_l_1ca;
	case 461ULL: goto x86_l_1cd;
	case 465ULL: goto x86_l_1d1;
	case 473ULL: goto x86_l_1d9;
	case 478ULL: goto x86_l_1de;
	case 485ULL: goto x86_l_1e5;
	case 490ULL: goto x86_l_1ea;
	case 492ULL: goto x86_l_1ec;
	case 495ULL: goto x86_l_1ef;
	case 498ULL: goto x86_l_1f2;
	case 501ULL: goto x86_l_1f5;
	case 507ULL: goto x86_l_1fb;
	case 510ULL: goto x86_l_1fe;
	case 516ULL: goto x86_l_204;
	case 519ULL: goto x86_l_207;
	case 524ULL: goto x86_l_20c;
	case 531ULL: goto x86_l_213;
	case 536ULL: goto x86_l_218;
	case 538ULL: goto x86_l_21a;
	case 541ULL: goto x86_l_21d;
	case 547ULL: goto x86_l_223;
	case 551ULL: goto x86_l_227;
	case 556ULL: goto x86_l_22c;
	case 560ULL: goto x86_l_230;
	case 563ULL: goto x86_l_233;
	case 565ULL: goto x86_l_235;
	case 569ULL: goto x86_l_239;
	case 575ULL: goto x86_l_23f;
	case 580ULL: goto x86_l_244;
	case 584ULL: goto x86_l_248;
	case 587ULL: goto x86_l_24b;
	case 591ULL: goto x86_l_24f;
	case 597ULL: goto x86_l_255;
	case 604ULL: goto x86_l_25c;
	case 610ULL: goto x86_l_262;
	case 614ULL: goto x86_l_266;
	case 617ULL: goto x86_l_269;
	case 621ULL: goto x86_l_26d;
	case 627ULL: goto x86_l_273;
	case 634ULL: goto x86_l_27a;
	case 640ULL: goto x86_l_280;
	case 644ULL: goto x86_l_284;
	case 647ULL: goto x86_l_287;
	case 651ULL: goto x86_l_28b;
	case 657ULL: goto x86_l_291;
	case 664ULL: goto x86_l_298;
	case 670ULL: goto x86_l_29e;
	case 674ULL: goto x86_l_2a2;
	case 677ULL: goto x86_l_2a5;
	case 681ULL: goto x86_l_2a9;
	case 687ULL: goto x86_l_2af;
	case 694ULL: goto x86_l_2b6;
	case 700ULL: goto x86_l_2bc;
	case 704ULL: goto x86_l_2c0;
	case 707ULL: goto x86_l_2c3;
	case 711ULL: goto x86_l_2c7;
	case 717ULL: goto x86_l_2cd;
	case 724ULL: goto x86_l_2d4;
	case 730ULL: goto x86_l_2da;
	case 734ULL: goto x86_l_2de;
	case 737ULL: goto x86_l_2e1;
	case 741ULL: goto x86_l_2e5;
	case 747ULL: goto x86_l_2eb;
	case 754ULL: goto x86_l_2f2;
	case 760ULL: goto x86_l_2f8;
	case 764ULL: goto x86_l_2fc;
	case 767ULL: goto x86_l_2ff;
	case 771ULL: goto x86_l_303;
	case 777ULL: goto x86_l_309;
	case 784ULL: goto x86_l_310;
	case 790ULL: goto x86_l_316;
	case 794ULL: goto x86_l_31a;
	case 797ULL: goto x86_l_31d;
	case 801ULL: goto x86_l_321;
	case 807ULL: goto x86_l_327;
	case 814ULL: goto x86_l_32e;
	case 820ULL: goto x86_l_334;
	case 824ULL: goto x86_l_338;
	case 827ULL: goto x86_l_33b;
	case 831ULL: goto x86_l_33f;
	case 837ULL: goto x86_l_345;
	case 844ULL: goto x86_l_34c;
	case 850ULL: goto x86_l_352;
	case 854ULL: goto x86_l_356;
	case 857ULL: goto x86_l_359;
	case 861ULL: goto x86_l_35d;
	case 867ULL: goto x86_l_363;
	case 874ULL: goto x86_l_36a;
	case 880ULL: goto x86_l_370;
	case 884ULL: goto x86_l_374;
	case 887ULL: goto x86_l_377;
	case 891ULL: goto x86_l_37b;
	case 897ULL: goto x86_l_381;
	case 904ULL: goto x86_l_388;
	case 910ULL: goto x86_l_38e;
	case 914ULL: goto x86_l_392;
	case 917ULL: goto x86_l_395;
	case 921ULL: goto x86_l_399;
	case 927ULL: goto x86_l_39f;
	case 934ULL: goto x86_l_3a6;
	case 940ULL: goto x86_l_3ac;
	case 944ULL: goto x86_l_3b0;
	case 947ULL: goto x86_l_3b3;
	case 951ULL: goto x86_l_3b7;
	case 957ULL: goto x86_l_3bd;
	case 964ULL: goto x86_l_3c4;
	case 970ULL: goto x86_l_3ca;
	case 974ULL: goto x86_l_3ce;
	case 977ULL: goto x86_l_3d1;
	case 981ULL: goto x86_l_3d5;
	case 987ULL: goto x86_l_3db;
	case 994ULL: goto x86_l_3e2;
	case 1000ULL: goto x86_l_3e8;
	case 1004ULL: goto x86_l_3ec;
	case 1007ULL: goto x86_l_3ef;
	case 1011ULL: goto x86_l_3f3;
	case 1017ULL: goto x86_l_3f9;
	case 1024ULL: goto x86_l_400;
	case 1030ULL: goto x86_l_406;
	case 1034ULL: goto x86_l_40a;
	case 1037ULL: goto x86_l_40d;
	case 1041ULL: goto x86_l_411;
	case 1047ULL: goto x86_l_417;
	case 1054ULL: goto x86_l_41e;
	case 1060ULL: goto x86_l_424;
	case 1064ULL: goto x86_l_428;
	case 1067ULL: goto x86_l_42b;
	case 1071ULL: goto x86_l_42f;
	case 1077ULL: goto x86_l_435;
	case 1084ULL: goto x86_l_43c;
	case 1090ULL: goto x86_l_442;
	case 1094ULL: goto x86_l_446;
	case 1097ULL: goto x86_l_449;
	case 1101ULL: goto x86_l_44d;
	case 1107ULL: goto x86_l_453;
	case 1114ULL: goto x86_l_45a;
	case 1120ULL: goto x86_l_460;
	case 1124ULL: goto x86_l_464;
	case 1127ULL: goto x86_l_467;
	case 1131ULL: goto x86_l_46b;
	case 1137ULL: goto x86_l_471;
	case 1144ULL: goto x86_l_478;
	case 1150ULL: goto x86_l_47e;
	case 1154ULL: goto x86_l_482;
	case 1157ULL: goto x86_l_485;
	case 1161ULL: goto x86_l_489;
	case 1167ULL: goto x86_l_48f;
	case 1174ULL: goto x86_l_496;
	case 1180ULL: goto x86_l_49c;
	case 1184ULL: goto x86_l_4a0;
	case 1187ULL: goto x86_l_4a3;
	case 1191ULL: goto x86_l_4a7;
	case 1197ULL: goto x86_l_4ad;
	case 1204ULL: goto x86_l_4b4;
	case 1210ULL: goto x86_l_4ba;
	case 1214ULL: goto x86_l_4be;
	case 1217ULL: goto x86_l_4c1;
	case 1221ULL: goto x86_l_4c5;
	case 1227ULL: goto x86_l_4cb;
	case 1234ULL: goto x86_l_4d2;
	case 1240ULL: goto x86_l_4d8;
	case 1244ULL: goto x86_l_4dc;
	case 1247ULL: goto x86_l_4df;
	case 1251ULL: goto x86_l_4e3;
	case 1257ULL: goto x86_l_4e9;
	case 1264ULL: goto x86_l_4f0;
	case 1270ULL: goto x86_l_4f6;
	case 1274ULL: goto x86_l_4fa;
	case 1277ULL: goto x86_l_4fd;
	case 1281ULL: goto x86_l_501;
	case 1287ULL: goto x86_l_507;
	case 1294ULL: goto x86_l_50e;
	case 1300ULL: goto x86_l_514;
	case 1304ULL: goto x86_l_518;
	case 1307ULL: goto x86_l_51b;
	case 1311ULL: goto x86_l_51f;
	case 1317ULL: goto x86_l_525;
	case 1324ULL: goto x86_l_52c;
	case 1330ULL: goto x86_l_532;
	case 1334ULL: goto x86_l_536;
	case 1337ULL: goto x86_l_539;
	case 1341ULL: goto x86_l_53d;
	case 1347ULL: goto x86_l_543;
	case 1354ULL: goto x86_l_54a;
	case 1360ULL: goto x86_l_550;
	case 1364ULL: goto x86_l_554;
	case 1367ULL: goto x86_l_557;
	case 1371ULL: goto x86_l_55b;
	case 1377ULL: goto x86_l_561;
	case 1384ULL: goto x86_l_568;
	case 1390ULL: goto x86_l_56e;
	case 1394ULL: goto x86_l_572;
	case 1397ULL: goto x86_l_575;
	case 1401ULL: goto x86_l_579;
	case 1407ULL: goto x86_l_57f;
	case 1414ULL: goto x86_l_586;
	case 1420ULL: goto x86_l_58c;
	case 1424ULL: goto x86_l_590;
	case 1427ULL: goto x86_l_593;
	case 1431ULL: goto x86_l_597;
	case 1437ULL: goto x86_l_59d;
	case 1444ULL: goto x86_l_5a4;
	case 1450ULL: goto x86_l_5aa;
	case 1454ULL: goto x86_l_5ae;
	case 1457ULL: goto x86_l_5b1;
	case 1461ULL: goto x86_l_5b5;
	case 1467ULL: goto x86_l_5bb;
	case 1474ULL: goto x86_l_5c2;
	case 1480ULL: goto x86_l_5c8;
	case 1484ULL: goto x86_l_5cc;
	case 1487ULL: goto x86_l_5cf;
	case 1491ULL: goto x86_l_5d3;
	case 1497ULL: goto x86_l_5d9;
	case 1504ULL: goto x86_l_5e0;
	case 1510ULL: goto x86_l_5e6;
	case 1514ULL: goto x86_l_5ea;
	case 1517ULL: goto x86_l_5ed;
	case 1521ULL: goto x86_l_5f1;
	case 1527ULL: goto x86_l_5f7;
	case 1534ULL: goto x86_l_5fe;
	case 1540ULL: goto x86_l_604;
	case 1544ULL: goto x86_l_608;
	case 1547ULL: goto x86_l_60b;
	case 1551ULL: goto x86_l_60f;
	case 1557ULL: goto x86_l_615;
	case 1564ULL: goto x86_l_61c;
	case 1570ULL: goto x86_l_622;
	case 1574ULL: goto x86_l_626;
	case 1577ULL: goto x86_l_629;
	case 1581ULL: goto x86_l_62d;
	case 1587ULL: goto x86_l_633;
	case 1594ULL: goto x86_l_63a;
	case 1600ULL: goto x86_l_640;
	case 1604ULL: goto x86_l_644;
	case 1607ULL: goto x86_l_647;
	case 1611ULL: goto x86_l_64b;
	case 1617ULL: goto x86_l_651;
	case 1624ULL: goto x86_l_658;
	case 1630ULL: goto x86_l_65e;
	case 1634ULL: goto x86_l_662;
	case 1637ULL: goto x86_l_665;
	case 1641ULL: goto x86_l_669;
	case 1647ULL: goto x86_l_66f;
	case 1654ULL: goto x86_l_676;
	case 1660ULL: goto x86_l_67c;
	case 1664ULL: goto x86_l_680;
	case 1667ULL: goto x86_l_683;
	case 1671ULL: goto x86_l_687;
	case 1677ULL: goto x86_l_68d;
	case 1684ULL: goto x86_l_694;
	case 1690ULL: goto x86_l_69a;
	case 1694ULL: goto x86_l_69e;
	case 1697ULL: goto x86_l_6a1;
	case 1701ULL: goto x86_l_6a5;
	case 1707ULL: goto x86_l_6ab;
	case 1714ULL: goto x86_l_6b2;
	case 1720ULL: goto x86_l_6b8;
	case 1724ULL: goto x86_l_6bc;
	case 1727ULL: goto x86_l_6bf;
	case 1731ULL: goto x86_l_6c3;
	case 1737ULL: goto x86_l_6c9;
	case 1744ULL: goto x86_l_6d0;
	case 1750ULL: goto x86_l_6d6;
	case 1754ULL: goto x86_l_6da;
	case 1757ULL: goto x86_l_6dd;
	case 1761ULL: goto x86_l_6e1;
	case 1767ULL: goto x86_l_6e7;
	case 1774ULL: goto x86_l_6ee;
	case 1780ULL: goto x86_l_6f4;
	case 1784ULL: goto x86_l_6f8;
	case 1787ULL: goto x86_l_6fb;
	case 1791ULL: goto x86_l_6ff;
	case 1797ULL: goto x86_l_705;
	case 1804ULL: goto x86_l_70c;
	case 1810ULL: goto x86_l_712;
	case 1814ULL: goto x86_l_716;
	case 1817ULL: goto x86_l_719;
	case 1821ULL: goto x86_l_71d;
	case 1827ULL: goto x86_l_723;
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
	/* 0xd: mov    DWORD PTR [rsp+0x7c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_15:
	/* 0x15: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a:
	/* 0x1a: mov    rdi,QWORD PTR [rip+0xb1b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_21:
	/* 0x21: lea    rsi,[rsp+0x7c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_26:
	/* 0x26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28:
	/* 0x28: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b:
	/* 0x2b: je     3367 <generic_usdt_filter_arg_2+0x3367> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13159ULL;
	}
x86_l_31:
	/* 0x31: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_34:
	/* 0x34: mov    r12d,DWORD PTR [rax+0x5ef0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_3b:
	/* 0x3b: lea    rsi,[rax+0x5ee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24296ULL);
x86_l_42:
	/* 0x42: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_47:
	/* 0x47: mov    rdi,QWORD PTR [rip+0xb1b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_4e:
	/* 0x4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50:
	/* 0x50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_53:
	/* 0x53: je     3351 <generic_usdt_filter_arg_2+0x3351> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13137ULL;
	}
x86_l_59:
	/* 0x59: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_61:
	/* 0x61: je     3351 <generic_usdt_filter_arg_2+0x3351> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13137ULL;
	}
x86_l_67:
	/* 0x67: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_6a:
	/* 0x6a: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_6d:
	/* 0x6d: cmp    BYTE PTR [r14+rcx*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 104183021699072ULL);
x86_l_76:
	/* 0x76: je     32df <generic_usdt_filter_arg_2+0x32df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13023ULL;
	}
x86_l_7c:
	/* 0x7c: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_7e:
	/* 0x7e: mov    edx,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_82:
	/* 0x82: lea    rsi,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_86:
	/* 0x86: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_8a:
	/* 0x8a: lea    rcx,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_8e:
	/* 0x8e: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_92:
	/* 0x92: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_98:
	/* 0x98: mov    ecx,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_9b:
	/* 0x9b: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9e:
	/* 0x9e: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a2:
	/* 0xa2: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_a4:
	/* 0xa4: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_aa:
	/* 0xaa: mov    edx,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_ad:
	/* 0xad: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b0:
	/* 0xb0: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_b2:
	/* 0xb2: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_b8:
	/* 0xb8: mov    ecx,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_bb:
	/* 0xbb: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_be:
	/* 0xbe: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_c0:
	/* 0xc0: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_c6:
	/* 0xc6: mov    edx,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_c9:
	/* 0xc9: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_cc:
	/* 0xcc: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_ce:
	/* 0xce: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_d4:
	/* 0xd4: mov    ecx,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_d7:
	/* 0xd7: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_da:
	/* 0xda: mov    ebp,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_32);
x86_l_dc:
	/* 0xdc: and    ebp,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_e2:
	/* 0xe2: cmp    DWORD PTR [rax+rbp*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 25ULL);
x86_l_e6:
	/* 0xe6: jb     32d5 <generic_usdt_filter_arg_2+0x32d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13013ULL;
	}
x86_l_ec:
	/* 0xec: mov    edx,DWORD PTR [rax+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 4ULL);
x86_l_f0:
	/* 0xf0: test   edx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 1023ULL);
x86_l_f6:
	/* 0xf6: je     32d5 <generic_usdt_filter_arg_2+0x32d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13013ULL;
	}
x86_l_fc:
	/* 0xfc: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fe:
	/* 0xfe: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_104:
	/* 0x104: mov    edx,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_107:
	/* 0x107: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_10b:
	/* 0x10b: ja     32df <generic_usdt_filter_arg_2+0x32df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13023ULL;
	}
x86_l_111:
	/* 0x111: cmp    DWORD PTR [r14+rdx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104041287778304ULL);
x86_l_11a:
	/* 0x11a: jne    32df <generic_usdt_filter_arg_2+0x32df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13023ULL;
	}
x86_l_120:
	/* 0x120: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_123:
	/* 0x123: add    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_126:
	/* 0x126: mov    ecx,DWORD PTR [rax+rcx*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 12ULL);
x86_l_12a:
	/* 0x12a: mov    rax,QWORD PTR [r14+rdx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_132:
	/* 0x132: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_137:
	/* 0x137: lea    rdi,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_13b:
	/* 0x13b: add    rdi,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_142:
	/* 0x142: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_145:
	/* 0x145: jg     16c <generic_usdt_filter_arg_2+0x16c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_16c;
	}
x86_l_147:
	/* 0x147: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_14a:
	/* 0x14a: jg     d33 <generic_usdt_filter_arg_2+0xd33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3379ULL;
	}
x86_l_150:
	/* 0x150: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_153:
	/* 0x153: je     ee4 <generic_usdt_filter_arg_2+0xee4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3812ULL;
	}
x86_l_159:
	/* 0x159: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_15c:
	/* 0x15c: je     d51 <generic_usdt_filter_arg_2+0xd51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3409ULL;
	}
x86_l_162:
	/* 0x162: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_165:
	/* 0x165: je     181 <generic_usdt_filter_arg_2+0x181> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_181;
	}
x86_l_167:
	/* 0x167: jmp    32d5 <generic_usdt_filter_arg_2+0x32d5> */
	return 13013ULL;
x86_l_16c:
	/* 0x16c: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_16f:
	/* 0x16f: jg     d49 <generic_usdt_filter_arg_2+0xd49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3401ULL;
	}
x86_l_175:
	/* 0x175: lea    eax,[rcx-0x26] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_178:
	/* 0x178: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_17b:
	/* 0x17b: jae    dba <generic_usdt_filter_arg_2+0xdba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3514ULL;
	}
x86_l_181:
	/* 0x181: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_184:
	/* 0x184: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_187:
	/* 0x187: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_18a:
	/* 0x18a: ja     32b5 <generic_usdt_filter_arg_2+0x32b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12981ULL;
	}
x86_l_190:
	/* 0x190: mov    r13d,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_193:
	/* 0x193: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_197:
	/* 0x197: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_19c:
	/* 0x19c: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_19f:
	/* 0x19f: jb     1b9e <generic_usdt_filter_arg_2+0x1b9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7070ULL;
	}
x86_l_1a5:
	/* 0x1a5: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_1aa:
	/* 0x1aa: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1ad:
	/* 0x1ad: jb     1af7 <generic_usdt_filter_arg_2+0x1af7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6903ULL;
	}
x86_l_1b3:
	/* 0x1b3: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_1b8:
	/* 0x1b8: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1bb:
	/* 0x1bb: jae    32b5 <generic_usdt_filter_arg_2+0x32b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12981ULL;
	}
x86_l_1c1:
	/* 0x1c1: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c6:
	/* 0x1c6: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ca:
	/* 0x1ca: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cd:
	/* 0x1cd: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d1:
	/* 0x1d1: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1d9:
	/* 0x1d9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1de:
	/* 0x1de: mov    rdi,QWORD PTR [rip+0xb1b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_1e5:
	/* 0x1e5: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ea:
	/* 0x1ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ec:
	/* 0x1ec: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1ef:
	/* 0x1ef: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f2:
	/* 0x1f2: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1f5:
	/* 0x1f5: je     32ae <generic_usdt_filter_arg_2+0x32ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12974ULL;
	}
x86_l_1fb:
	/* 0x1fb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fe:
	/* 0x1fe: je     32ae <generic_usdt_filter_arg_2+0x32ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12974ULL;
	}
x86_l_204:
	/* 0x204: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_207:
	/* 0x207: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20c:
	/* 0x20c: mov    rdi,QWORD PTR [rip+0xb1b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_213:
	/* 0x213: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_218:
	/* 0x218: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21a:
	/* 0x21a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21d:
	/* 0x21d: je     32ab <generic_usdt_filter_arg_2+0x32ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12971ULL;
	}
x86_l_223:
	/* 0x223: cmp    r13d,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 94ULL);
x86_l_227:
	/* 0x227: mov    ecx,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 94ULL);
x86_l_22c:
	/* 0x22c: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_230:
	/* 0x230: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_233:
	/* 0x233: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_235:
	/* 0x235: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_239:
	/* 0x239: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23f:
	/* 0x23f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_244:
	/* 0x244: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_248:
	/* 0x248: mov    BYTE PTR [rax+0x4],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_24b:
	/* 0x24b: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_24f:
	/* 0x24f: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_255:
	/* 0x255: lea    ecx,[r13+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_25c:
	/* 0x25c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_262:
	/* 0x262: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_266:
	/* 0x266: mov    BYTE PTR [rax+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_269:
	/* 0x269: cmp    r13,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 2ULL);
x86_l_26d:
	/* 0x26d: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_273:
	/* 0x273: lea    ecx,[r13+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_27a:
	/* 0x27a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_280:
	/* 0x280: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_284:
	/* 0x284: mov    BYTE PTR [rax+0x6],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_287:
	/* 0x287: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_28b:
	/* 0x28b: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_291:
	/* 0x291: lea    ecx,[r13+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_298:
	/* 0x298: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29e:
	/* 0x29e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a2:
	/* 0x2a2: mov    BYTE PTR [rax+0x7],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_2a5:
	/* 0x2a5: cmp    r13,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4ULL);
x86_l_2a9:
	/* 0x2a9: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_2af:
	/* 0x2af: lea    ecx,[r13+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_2b6:
	/* 0x2b6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2bc:
	/* 0x2bc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2c0:
	/* 0x2c0: mov    BYTE PTR [rax+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c3:
	/* 0x2c3: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_2c7:
	/* 0x2c7: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_2cd:
	/* 0x2cd: lea    ecx,[r13+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_2d4:
	/* 0x2d4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2da:
	/* 0x2da: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2de:
	/* 0x2de: mov    BYTE PTR [rax+0x9],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_2e1:
	/* 0x2e1: cmp    r13,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 6ULL);
x86_l_2e5:
	/* 0x2e5: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_2eb:
	/* 0x2eb: lea    ecx,[r13+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_2f2:
	/* 0x2f2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2f8:
	/* 0x2f8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2fc:
	/* 0x2fc: mov    BYTE PTR [rax+0xa],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_2ff:
	/* 0x2ff: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_303:
	/* 0x303: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_309:
	/* 0x309: lea    ecx,[r13+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_310:
	/* 0x310: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_316:
	/* 0x316: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_31a:
	/* 0x31a: mov    BYTE PTR [rax+0xb],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_31d:
	/* 0x31d: cmp    r13,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 8ULL);
x86_l_321:
	/* 0x321: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_327:
	/* 0x327: lea    ecx,[r13+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_32e:
	/* 0x32e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_334:
	/* 0x334: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_338:
	/* 0x338: mov    BYTE PTR [rax+0xc],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_33b:
	/* 0x33b: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_33f:
	/* 0x33f: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_345:
	/* 0x345: lea    ecx,[r13+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_34c:
	/* 0x34c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_352:
	/* 0x352: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_356:
	/* 0x356: mov    BYTE PTR [rax+0xd],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_359:
	/* 0x359: cmp    r13,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 10ULL);
x86_l_35d:
	/* 0x35d: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_363:
	/* 0x363: lea    ecx,[r13+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_36a:
	/* 0x36a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_370:
	/* 0x370: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_374:
	/* 0x374: mov    BYTE PTR [rax+0xe],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_377:
	/* 0x377: cmp    r13,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 11ULL);
x86_l_37b:
	/* 0x37b: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_381:
	/* 0x381: lea    ecx,[r13+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_388:
	/* 0x388: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_38e:
	/* 0x38e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_392:
	/* 0x392: mov    BYTE PTR [rax+0xf],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_395:
	/* 0x395: cmp    r13,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 12ULL);
x86_l_399:
	/* 0x399: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_39f:
	/* 0x39f: lea    ecx,[r13+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_3a6:
	/* 0x3a6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3ac:
	/* 0x3ac: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_3b0:
	/* 0x3b0: mov    BYTE PTR [rax+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b3:
	/* 0x3b3: cmp    r13,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 13ULL);
x86_l_3b7:
	/* 0x3b7: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_3bd:
	/* 0x3bd: lea    ecx,[r13+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_3c4:
	/* 0x3c4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3ca:
	/* 0x3ca: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_3ce:
	/* 0x3ce: mov    BYTE PTR [rax+0x11],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_3d1:
	/* 0x3d1: cmp    r13,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 14ULL);
x86_l_3d5:
	/* 0x3d5: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_3db:
	/* 0x3db: lea    ecx,[r13+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_3e2:
	/* 0x3e2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3e8:
	/* 0x3e8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_3ec:
	/* 0x3ec: mov    BYTE PTR [rax+0x12],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_3ef:
	/* 0x3ef: cmp    r13,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 15ULL);
x86_l_3f3:
	/* 0x3f3: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_3f9:
	/* 0x3f9: lea    ecx,[r13+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_400:
	/* 0x400: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_406:
	/* 0x406: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_40a:
	/* 0x40a: mov    BYTE PTR [rax+0x13],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_40d:
	/* 0x40d: cmp    r13,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 16ULL);
x86_l_411:
	/* 0x411: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_417:
	/* 0x417: lea    ecx,[r13+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_41e:
	/* 0x41e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_424:
	/* 0x424: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_428:
	/* 0x428: mov    BYTE PTR [rax+0x14],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_42b:
	/* 0x42b: cmp    r13,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 17ULL);
x86_l_42f:
	/* 0x42f: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_435:
	/* 0x435: lea    ecx,[r13+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_43c:
	/* 0x43c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_442:
	/* 0x442: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_446:
	/* 0x446: mov    BYTE PTR [rax+0x15],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_449:
	/* 0x449: cmp    r13,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18ULL);
x86_l_44d:
	/* 0x44d: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_453:
	/* 0x453: lea    ecx,[r13+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_45a:
	/* 0x45a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_460:
	/* 0x460: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_464:
	/* 0x464: mov    BYTE PTR [rax+0x16],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_467:
	/* 0x467: cmp    r13,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 19ULL);
x86_l_46b:
	/* 0x46b: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_471:
	/* 0x471: lea    ecx,[r13+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_478:
	/* 0x478: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_47e:
	/* 0x47e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_482:
	/* 0x482: mov    BYTE PTR [rax+0x17],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_485:
	/* 0x485: cmp    r13,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 20ULL);
x86_l_489:
	/* 0x489: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_48f:
	/* 0x48f: lea    ecx,[r13+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_496:
	/* 0x496: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_49c:
	/* 0x49c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_4a0:
	/* 0x4a0: mov    BYTE PTR [rax+0x18],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a3:
	/* 0x4a3: cmp    r13,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 21ULL);
x86_l_4a7:
	/* 0x4a7: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_4ad:
	/* 0x4ad: lea    ecx,[r13+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_4b4:
	/* 0x4b4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4ba:
	/* 0x4ba: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_4be:
	/* 0x4be: mov    BYTE PTR [rax+0x19],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_4c1:
	/* 0x4c1: cmp    r13,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 22ULL);
x86_l_4c5:
	/* 0x4c5: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_4cb:
	/* 0x4cb: lea    ecx,[r13+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_4d2:
	/* 0x4d2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4d8:
	/* 0x4d8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_4dc:
	/* 0x4dc: mov    BYTE PTR [rax+0x1a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_4df:
	/* 0x4df: cmp    r13,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 23ULL);
x86_l_4e3:
	/* 0x4e3: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_4e9:
	/* 0x4e9: lea    ecx,[r13+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_4f0:
	/* 0x4f0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4f6:
	/* 0x4f6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_4fa:
	/* 0x4fa: mov    BYTE PTR [rax+0x1b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_4fd:
	/* 0x4fd: cmp    r13,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 24ULL);
x86_l_501:
	/* 0x501: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_507:
	/* 0x507: lea    ecx,[r13+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_50e:
	/* 0x50e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_514:
	/* 0x514: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_518:
	/* 0x518: mov    BYTE PTR [rax+0x1c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_51b:
	/* 0x51b: cmp    r13,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 25ULL);
x86_l_51f:
	/* 0x51f: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_525:
	/* 0x525: lea    ecx,[r13+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_52c:
	/* 0x52c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_532:
	/* 0x532: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_536:
	/* 0x536: mov    BYTE PTR [rax+0x1d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_539:
	/* 0x539: cmp    r13,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 26ULL);
x86_l_53d:
	/* 0x53d: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_543:
	/* 0x543: lea    ecx,[r13+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_54a:
	/* 0x54a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_550:
	/* 0x550: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_554:
	/* 0x554: mov    BYTE PTR [rax+0x1e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_557:
	/* 0x557: cmp    r13,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 27ULL);
x86_l_55b:
	/* 0x55b: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_561:
	/* 0x561: lea    ecx,[r13+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_568:
	/* 0x568: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_56e:
	/* 0x56e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_572:
	/* 0x572: mov    BYTE PTR [rax+0x1f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_575:
	/* 0x575: cmp    r13,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 28ULL);
x86_l_579:
	/* 0x579: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_57f:
	/* 0x57f: lea    ecx,[r13+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_586:
	/* 0x586: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_58c:
	/* 0x58c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_590:
	/* 0x590: mov    BYTE PTR [rax+0x20],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_593:
	/* 0x593: cmp    r13,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 29ULL);
x86_l_597:
	/* 0x597: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_59d:
	/* 0x59d: lea    ecx,[r13+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_5a4:
	/* 0x5a4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5aa:
	/* 0x5aa: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_5ae:
	/* 0x5ae: mov    BYTE PTR [rax+0x21],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_5b1:
	/* 0x5b1: cmp    r13,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 30ULL);
x86_l_5b5:
	/* 0x5b5: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_5bb:
	/* 0x5bb: lea    ecx,[r13+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_5c2:
	/* 0x5c2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5c8:
	/* 0x5c8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_5cc:
	/* 0x5cc: mov    BYTE PTR [rax+0x22],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_5cf:
	/* 0x5cf: cmp    r13,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 31ULL);
x86_l_5d3:
	/* 0x5d3: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_5d9:
	/* 0x5d9: lea    ecx,[r13+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_5e0:
	/* 0x5e0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5e6:
	/* 0x5e6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_5ea:
	/* 0x5ea: mov    BYTE PTR [rax+0x23],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_5ed:
	/* 0x5ed: cmp    r13,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 32ULL);
x86_l_5f1:
	/* 0x5f1: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_5f7:
	/* 0x5f7: lea    ecx,[r13+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_5fe:
	/* 0x5fe: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_604:
	/* 0x604: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_608:
	/* 0x608: mov    BYTE PTR [rax+0x24],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_60b:
	/* 0x60b: cmp    r13,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 33ULL);
x86_l_60f:
	/* 0x60f: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_615:
	/* 0x615: lea    ecx,[r13+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_61c:
	/* 0x61c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_622:
	/* 0x622: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_626:
	/* 0x626: mov    BYTE PTR [rax+0x25],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_629:
	/* 0x629: cmp    r13,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 34ULL);
x86_l_62d:
	/* 0x62d: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_633:
	/* 0x633: lea    ecx,[r13+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_63a:
	/* 0x63a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_640:
	/* 0x640: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_644:
	/* 0x644: mov    BYTE PTR [rax+0x26],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_647:
	/* 0x647: cmp    r13,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 35ULL);
x86_l_64b:
	/* 0x64b: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_651:
	/* 0x651: lea    ecx,[r13+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_658:
	/* 0x658: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_65e:
	/* 0x65e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_662:
	/* 0x662: mov    BYTE PTR [rax+0x27],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_665:
	/* 0x665: cmp    r13,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 36ULL);
x86_l_669:
	/* 0x669: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_66f:
	/* 0x66f: lea    ecx,[r13+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_676:
	/* 0x676: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_67c:
	/* 0x67c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_680:
	/* 0x680: mov    BYTE PTR [rax+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_683:
	/* 0x683: cmp    r13,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 37ULL);
x86_l_687:
	/* 0x687: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_68d:
	/* 0x68d: lea    ecx,[r13+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_694:
	/* 0x694: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_69a:
	/* 0x69a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_69e:
	/* 0x69e: mov    BYTE PTR [rax+0x29],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_6a1:
	/* 0x6a1: cmp    r13,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 38ULL);
x86_l_6a5:
	/* 0x6a5: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_6ab:
	/* 0x6ab: lea    ecx,[r13+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_6b2:
	/* 0x6b2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6b8:
	/* 0x6b8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_6bc:
	/* 0x6bc: mov    BYTE PTR [rax+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_6bf:
	/* 0x6bf: cmp    r13,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 39ULL);
x86_l_6c3:
	/* 0x6c3: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_6c9:
	/* 0x6c9: lea    ecx,[r13+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_6d0:
	/* 0x6d0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6d6:
	/* 0x6d6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_6da:
	/* 0x6da: mov    BYTE PTR [rax+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_6dd:
	/* 0x6dd: cmp    r13,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 40ULL);
x86_l_6e1:
	/* 0x6e1: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_6e7:
	/* 0x6e7: lea    ecx,[r13+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_6ee:
	/* 0x6ee: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6f4:
	/* 0x6f4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_6f8:
	/* 0x6f8: mov    BYTE PTR [rax+0x2c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6fb:
	/* 0x6fb: cmp    r13,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 41ULL);
x86_l_6ff:
	/* 0x6ff: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_705:
	/* 0x705: lea    ecx,[r13+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_70c:
	/* 0x70c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_712:
	/* 0x712: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_716:
	/* 0x716: mov    BYTE PTR [rax+0x2d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_719:
	/* 0x719: cmp    r13,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 42ULL);
x86_l_71d:
	/* 0x71d: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3363ULL;
	}
x86_l_723:
	/* 0x723: lea    ecx,[r13+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
	return 1834ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1834ULL: goto x86_l_72a;
	case 1840ULL: goto x86_l_730;
	case 1844ULL: goto x86_l_734;
	case 1847ULL: goto x86_l_737;
	case 1851ULL: goto x86_l_73b;
	case 1857ULL: goto x86_l_741;
	case 1864ULL: goto x86_l_748;
	case 1870ULL: goto x86_l_74e;
	case 1874ULL: goto x86_l_752;
	case 1877ULL: goto x86_l_755;
	case 1881ULL: goto x86_l_759;
	case 1887ULL: goto x86_l_75f;
	case 1894ULL: goto x86_l_766;
	case 1900ULL: goto x86_l_76c;
	case 1904ULL: goto x86_l_770;
	case 1907ULL: goto x86_l_773;
	case 1911ULL: goto x86_l_777;
	case 1917ULL: goto x86_l_77d;
	case 1924ULL: goto x86_l_784;
	case 1930ULL: goto x86_l_78a;
	case 1934ULL: goto x86_l_78e;
	case 1937ULL: goto x86_l_791;
	case 1941ULL: goto x86_l_795;
	case 1947ULL: goto x86_l_79b;
	case 1954ULL: goto x86_l_7a2;
	case 1960ULL: goto x86_l_7a8;
	case 1964ULL: goto x86_l_7ac;
	case 1967ULL: goto x86_l_7af;
	case 1971ULL: goto x86_l_7b3;
	case 1977ULL: goto x86_l_7b9;
	case 1984ULL: goto x86_l_7c0;
	case 1990ULL: goto x86_l_7c6;
	case 1994ULL: goto x86_l_7ca;
	case 1997ULL: goto x86_l_7cd;
	case 2001ULL: goto x86_l_7d1;
	case 2007ULL: goto x86_l_7d7;
	case 2014ULL: goto x86_l_7de;
	case 2020ULL: goto x86_l_7e4;
	case 2024ULL: goto x86_l_7e8;
	case 2027ULL: goto x86_l_7eb;
	case 2031ULL: goto x86_l_7ef;
	case 2037ULL: goto x86_l_7f5;
	case 2044ULL: goto x86_l_7fc;
	case 2050ULL: goto x86_l_802;
	case 2054ULL: goto x86_l_806;
	case 2057ULL: goto x86_l_809;
	case 2061ULL: goto x86_l_80d;
	case 2067ULL: goto x86_l_813;
	case 2074ULL: goto x86_l_81a;
	case 2080ULL: goto x86_l_820;
	case 2084ULL: goto x86_l_824;
	case 2087ULL: goto x86_l_827;
	case 2091ULL: goto x86_l_82b;
	case 2097ULL: goto x86_l_831;
	case 2104ULL: goto x86_l_838;
	case 2110ULL: goto x86_l_83e;
	case 2114ULL: goto x86_l_842;
	case 2117ULL: goto x86_l_845;
	case 2121ULL: goto x86_l_849;
	case 2127ULL: goto x86_l_84f;
	case 2134ULL: goto x86_l_856;
	case 2140ULL: goto x86_l_85c;
	case 2144ULL: goto x86_l_860;
	case 2147ULL: goto x86_l_863;
	case 2151ULL: goto x86_l_867;
	case 2157ULL: goto x86_l_86d;
	case 2164ULL: goto x86_l_874;
	case 2170ULL: goto x86_l_87a;
	case 2174ULL: goto x86_l_87e;
	case 2177ULL: goto x86_l_881;
	case 2181ULL: goto x86_l_885;
	case 2187ULL: goto x86_l_88b;
	case 2194ULL: goto x86_l_892;
	case 2200ULL: goto x86_l_898;
	case 2204ULL: goto x86_l_89c;
	case 2207ULL: goto x86_l_89f;
	case 2211ULL: goto x86_l_8a3;
	case 2217ULL: goto x86_l_8a9;
	case 2224ULL: goto x86_l_8b0;
	case 2230ULL: goto x86_l_8b6;
	case 2234ULL: goto x86_l_8ba;
	case 2237ULL: goto x86_l_8bd;
	case 2241ULL: goto x86_l_8c1;
	case 2247ULL: goto x86_l_8c7;
	case 2254ULL: goto x86_l_8ce;
	case 2260ULL: goto x86_l_8d4;
	case 2264ULL: goto x86_l_8d8;
	case 2267ULL: goto x86_l_8db;
	case 2271ULL: goto x86_l_8df;
	case 2277ULL: goto x86_l_8e5;
	case 2284ULL: goto x86_l_8ec;
	case 2290ULL: goto x86_l_8f2;
	case 2294ULL: goto x86_l_8f6;
	case 2297ULL: goto x86_l_8f9;
	case 2301ULL: goto x86_l_8fd;
	case 2307ULL: goto x86_l_903;
	case 2314ULL: goto x86_l_90a;
	case 2320ULL: goto x86_l_910;
	case 2324ULL: goto x86_l_914;
	case 2327ULL: goto x86_l_917;
	case 2331ULL: goto x86_l_91b;
	case 2337ULL: goto x86_l_921;
	case 2344ULL: goto x86_l_928;
	case 2350ULL: goto x86_l_92e;
	case 2354ULL: goto x86_l_932;
	case 2357ULL: goto x86_l_935;
	case 2361ULL: goto x86_l_939;
	case 2367ULL: goto x86_l_93f;
	case 2374ULL: goto x86_l_946;
	case 2380ULL: goto x86_l_94c;
	case 2384ULL: goto x86_l_950;
	case 2387ULL: goto x86_l_953;
	case 2391ULL: goto x86_l_957;
	case 2397ULL: goto x86_l_95d;
	case 2404ULL: goto x86_l_964;
	case 2410ULL: goto x86_l_96a;
	case 2414ULL: goto x86_l_96e;
	case 2417ULL: goto x86_l_971;
	case 2421ULL: goto x86_l_975;
	case 2427ULL: goto x86_l_97b;
	case 2434ULL: goto x86_l_982;
	case 2440ULL: goto x86_l_988;
	case 2444ULL: goto x86_l_98c;
	case 2447ULL: goto x86_l_98f;
	case 2451ULL: goto x86_l_993;
	case 2457ULL: goto x86_l_999;
	case 2464ULL: goto x86_l_9a0;
	case 2470ULL: goto x86_l_9a6;
	case 2474ULL: goto x86_l_9aa;
	case 2477ULL: goto x86_l_9ad;
	case 2481ULL: goto x86_l_9b1;
	case 2487ULL: goto x86_l_9b7;
	case 2494ULL: goto x86_l_9be;
	case 2500ULL: goto x86_l_9c4;
	case 2504ULL: goto x86_l_9c8;
	case 2507ULL: goto x86_l_9cb;
	case 2511ULL: goto x86_l_9cf;
	case 2517ULL: goto x86_l_9d5;
	case 2524ULL: goto x86_l_9dc;
	case 2530ULL: goto x86_l_9e2;
	case 2534ULL: goto x86_l_9e6;
	case 2537ULL: goto x86_l_9e9;
	case 2541ULL: goto x86_l_9ed;
	case 2547ULL: goto x86_l_9f3;
	case 2554ULL: goto x86_l_9fa;
	case 2560ULL: goto x86_l_a00;
	case 2564ULL: goto x86_l_a04;
	case 2567ULL: goto x86_l_a07;
	case 2571ULL: goto x86_l_a0b;
	case 2577ULL: goto x86_l_a11;
	case 2584ULL: goto x86_l_a18;
	case 2590ULL: goto x86_l_a1e;
	case 2594ULL: goto x86_l_a22;
	case 2597ULL: goto x86_l_a25;
	case 2601ULL: goto x86_l_a29;
	case 2607ULL: goto x86_l_a2f;
	case 2614ULL: goto x86_l_a36;
	case 2620ULL: goto x86_l_a3c;
	case 2624ULL: goto x86_l_a40;
	case 2627ULL: goto x86_l_a43;
	case 2631ULL: goto x86_l_a47;
	case 2637ULL: goto x86_l_a4d;
	case 2644ULL: goto x86_l_a54;
	case 2650ULL: goto x86_l_a5a;
	case 2654ULL: goto x86_l_a5e;
	case 2657ULL: goto x86_l_a61;
	case 2661ULL: goto x86_l_a65;
	case 2667ULL: goto x86_l_a6b;
	case 2674ULL: goto x86_l_a72;
	case 2680ULL: goto x86_l_a78;
	case 2684ULL: goto x86_l_a7c;
	case 2687ULL: goto x86_l_a7f;
	case 2691ULL: goto x86_l_a83;
	case 2697ULL: goto x86_l_a89;
	case 2704ULL: goto x86_l_a90;
	case 2710ULL: goto x86_l_a96;
	case 2714ULL: goto x86_l_a9a;
	case 2717ULL: goto x86_l_a9d;
	case 2721ULL: goto x86_l_aa1;
	case 2727ULL: goto x86_l_aa7;
	case 2734ULL: goto x86_l_aae;
	case 2740ULL: goto x86_l_ab4;
	case 2744ULL: goto x86_l_ab8;
	case 2747ULL: goto x86_l_abb;
	case 2751ULL: goto x86_l_abf;
	case 2757ULL: goto x86_l_ac5;
	case 2764ULL: goto x86_l_acc;
	case 2770ULL: goto x86_l_ad2;
	case 2774ULL: goto x86_l_ad6;
	case 2777ULL: goto x86_l_ad9;
	case 2781ULL: goto x86_l_add;
	case 2787ULL: goto x86_l_ae3;
	case 2794ULL: goto x86_l_aea;
	case 2800ULL: goto x86_l_af0;
	case 2804ULL: goto x86_l_af4;
	case 2807ULL: goto x86_l_af7;
	case 2811ULL: goto x86_l_afb;
	case 2817ULL: goto x86_l_b01;
	case 2824ULL: goto x86_l_b08;
	case 2830ULL: goto x86_l_b0e;
	case 2834ULL: goto x86_l_b12;
	case 2837ULL: goto x86_l_b15;
	case 2841ULL: goto x86_l_b19;
	case 2847ULL: goto x86_l_b1f;
	case 2854ULL: goto x86_l_b26;
	case 2860ULL: goto x86_l_b2c;
	case 2864ULL: goto x86_l_b30;
	case 2867ULL: goto x86_l_b33;
	case 2871ULL: goto x86_l_b37;
	case 2877ULL: goto x86_l_b3d;
	case 2884ULL: goto x86_l_b44;
	case 2890ULL: goto x86_l_b4a;
	case 2894ULL: goto x86_l_b4e;
	case 2897ULL: goto x86_l_b51;
	case 2901ULL: goto x86_l_b55;
	case 2907ULL: goto x86_l_b5b;
	case 2914ULL: goto x86_l_b62;
	case 2920ULL: goto x86_l_b68;
	case 2924ULL: goto x86_l_b6c;
	case 2927ULL: goto x86_l_b6f;
	case 2931ULL: goto x86_l_b73;
	case 2937ULL: goto x86_l_b79;
	case 2944ULL: goto x86_l_b80;
	case 2950ULL: goto x86_l_b86;
	case 2954ULL: goto x86_l_b8a;
	case 2957ULL: goto x86_l_b8d;
	case 2961ULL: goto x86_l_b91;
	case 2967ULL: goto x86_l_b97;
	case 2974ULL: goto x86_l_b9e;
	case 2980ULL: goto x86_l_ba4;
	case 2984ULL: goto x86_l_ba8;
	case 2987ULL: goto x86_l_bab;
	case 2991ULL: goto x86_l_baf;
	case 2997ULL: goto x86_l_bb5;
	case 3004ULL: goto x86_l_bbc;
	case 3010ULL: goto x86_l_bc2;
	case 3014ULL: goto x86_l_bc6;
	case 3017ULL: goto x86_l_bc9;
	case 3021ULL: goto x86_l_bcd;
	case 3027ULL: goto x86_l_bd3;
	case 3034ULL: goto x86_l_bda;
	case 3040ULL: goto x86_l_be0;
	case 3044ULL: goto x86_l_be4;
	case 3047ULL: goto x86_l_be7;
	case 3051ULL: goto x86_l_beb;
	case 3057ULL: goto x86_l_bf1;
	case 3064ULL: goto x86_l_bf8;
	case 3070ULL: goto x86_l_bfe;
	case 3074ULL: goto x86_l_c02;
	case 3077ULL: goto x86_l_c05;
	case 3081ULL: goto x86_l_c09;
	case 3087ULL: goto x86_l_c0f;
	case 3094ULL: goto x86_l_c16;
	case 3100ULL: goto x86_l_c1c;
	case 3104ULL: goto x86_l_c20;
	case 3107ULL: goto x86_l_c23;
	case 3111ULL: goto x86_l_c27;
	case 3117ULL: goto x86_l_c2d;
	case 3124ULL: goto x86_l_c34;
	case 3130ULL: goto x86_l_c3a;
	case 3134ULL: goto x86_l_c3e;
	case 3137ULL: goto x86_l_c41;
	case 3141ULL: goto x86_l_c45;
	case 3147ULL: goto x86_l_c4b;
	case 3154ULL: goto x86_l_c52;
	case 3160ULL: goto x86_l_c58;
	case 3164ULL: goto x86_l_c5c;
	case 3167ULL: goto x86_l_c5f;
	case 3171ULL: goto x86_l_c63;
	case 3177ULL: goto x86_l_c69;
	case 3184ULL: goto x86_l_c70;
	case 3190ULL: goto x86_l_c76;
	case 3194ULL: goto x86_l_c7a;
	case 3197ULL: goto x86_l_c7d;
	case 3201ULL: goto x86_l_c81;
	case 3207ULL: goto x86_l_c87;
	case 3214ULL: goto x86_l_c8e;
	case 3220ULL: goto x86_l_c94;
	case 3224ULL: goto x86_l_c98;
	case 3227ULL: goto x86_l_c9b;
	case 3231ULL: goto x86_l_c9f;
	case 3237ULL: goto x86_l_ca5;
	case 3244ULL: goto x86_l_cac;
	case 3250ULL: goto x86_l_cb2;
	case 3254ULL: goto x86_l_cb6;
	case 3257ULL: goto x86_l_cb9;
	case 3261ULL: goto x86_l_cbd;
	case 3263ULL: goto x86_l_cbf;
	case 3270ULL: goto x86_l_cc6;
	case 3276ULL: goto x86_l_ccc;
	case 3280ULL: goto x86_l_cd0;
	case 3283ULL: goto x86_l_cd3;
	case 3287ULL: goto x86_l_cd7;
	case 3289ULL: goto x86_l_cd9;
	case 3296ULL: goto x86_l_ce0;
	case 3302ULL: goto x86_l_ce6;
	case 3306ULL: goto x86_l_cea;
	case 3309ULL: goto x86_l_ced;
	case 3313ULL: goto x86_l_cf1;
	case 3315ULL: goto x86_l_cf3;
	case 3322ULL: goto x86_l_cfa;
	case 3328ULL: goto x86_l_d00;
	case 3332ULL: goto x86_l_d04;
	case 3335ULL: goto x86_l_d07;
	case 3339ULL: goto x86_l_d0b;
	case 3341ULL: goto x86_l_d0d;
	case 3348ULL: goto x86_l_d14;
	case 3355ULL: goto x86_l_d1b;
	case 3360ULL: goto x86_l_d20;
	case 3363ULL: goto x86_l_d23;
	case 3368ULL: goto x86_l_d28;
	case 3371ULL: goto x86_l_d2b;
	case 3374ULL: goto x86_l_d2e;
	case 3379ULL: goto x86_l_d33;
	case 3382ULL: goto x86_l_d36;
	case 3385ULL: goto x86_l_d39;
	case 3391ULL: goto x86_l_d3f;
	case 3394ULL: goto x86_l_d42;
	case 3396ULL: goto x86_l_d44;
	case 3401ULL: goto x86_l_d49;
	case 3404ULL: goto x86_l_d4c;
	case 3407ULL: goto x86_l_d4f;
	case 3409ULL: goto x86_l_d51;
	case 3418ULL: goto x86_l_d5a;
	case 3427ULL: goto x86_l_d63;
	case 3436ULL: goto x86_l_d6c;
	case 3445ULL: goto x86_l_d75;
	case 3454ULL: goto x86_l_d7e;
	case 3457ULL: goto x86_l_d81;
	case 3460ULL: goto x86_l_d84;
	case 3462ULL: goto x86_l_d86;
	case 3465ULL: goto x86_l_d89;
	case 3471ULL: goto x86_l_d8f;
	case 3474ULL: goto x86_l_d92;
	case 3477ULL: goto x86_l_d95;
	case 3483ULL: goto x86_l_d9b;
	case 3488ULL: goto x86_l_da0;
	case 3491ULL: goto x86_l_da3;
	case 3497ULL: goto x86_l_da9;
	case 3500ULL: goto x86_l_dac;
	case 3503ULL: goto x86_l_daf;
	case 3509ULL: goto x86_l_db5;
	case 3514ULL: goto x86_l_dba;
	case 3517ULL: goto x86_l_dbd;
	case 3523ULL: goto x86_l_dc3;
	case 3527ULL: goto x86_l_dc7;
	case 3529ULL: goto x86_l_dc9;
	case 3532ULL: goto x86_l_dcc;
	case 3538ULL: goto x86_l_dd2;
	case 3541ULL: goto x86_l_dd5;
	case 3544ULL: goto x86_l_dd8;
	case 3547ULL: goto x86_l_ddb;
	case 3549ULL: goto x86_l_ddd;
	case 3551ULL: goto x86_l_ddf;
	case 3554ULL: goto x86_l_de2;
	case 3557ULL: goto x86_l_de5;
	case 3563ULL: goto x86_l_deb;
	case 3566ULL: goto x86_l_dee;
	case 3572ULL: goto x86_l_df4;
	case 3574ULL: goto x86_l_df6;
	case 3579ULL: goto x86_l_dfb;
	case 3583ULL: goto x86_l_dff;
	case 3589ULL: goto x86_l_e05;
	case 3594ULL: goto x86_l_e0a;
	case 3598ULL: goto x86_l_e0e;
	case 3604ULL: goto x86_l_e14;
	case 3614ULL: goto x86_l_e1e;
	case 3618ULL: goto x86_l_e22;
	case 3624ULL: goto x86_l_e28;
	case 3631ULL: goto x86_l_e2f;
	case 3638ULL: goto x86_l_e36;
	case 3644ULL: goto x86_l_e3c;
	case 3649ULL: goto x86_l_e41;
	case 3651ULL: goto x86_l_e43;
	case 3655ULL: goto x86_l_e47;
	case 3659ULL: goto x86_l_e4b;
	case 3664ULL: goto x86_l_e50;
	case 3667ULL: goto x86_l_e53;
	case 3672ULL: goto x86_l_e58;
	case 3674ULL: goto x86_l_e5a;
	case 3677ULL: goto x86_l_e5d;
	case 3681ULL: goto x86_l_e61;
	case 3683ULL: goto x86_l_e63;
	case 3689ULL: goto x86_l_e69;
	default: return 0xffffffffffffffffULL;
	}
x86_l_72a:
	/* 0x72a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_730:
	/* 0x730: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_734:
	/* 0x734: mov    BYTE PTR [rax+0x2e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_737:
	/* 0x737: cmp    r13,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 43ULL);
x86_l_73b:
	/* 0x73b: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_741:
	/* 0x741: lea    ecx,[r13+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_748:
	/* 0x748: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_74e:
	/* 0x74e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_752:
	/* 0x752: mov    BYTE PTR [rax+0x2f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_755:
	/* 0x755: cmp    r13,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 44ULL);
x86_l_759:
	/* 0x759: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_75f:
	/* 0x75f: lea    ecx,[r13+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_766:
	/* 0x766: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_76c:
	/* 0x76c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_770:
	/* 0x770: mov    BYTE PTR [rax+0x30],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_773:
	/* 0x773: cmp    r13,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 45ULL);
x86_l_777:
	/* 0x777: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_77d:
	/* 0x77d: lea    ecx,[r13+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_784:
	/* 0x784: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_78a:
	/* 0x78a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_78e:
	/* 0x78e: mov    BYTE PTR [rax+0x31],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_791:
	/* 0x791: cmp    r13,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 46ULL);
x86_l_795:
	/* 0x795: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_79b:
	/* 0x79b: lea    ecx,[r13+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_7a2:
	/* 0x7a2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7a8:
	/* 0x7a8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_7ac:
	/* 0x7ac: mov    BYTE PTR [rax+0x32],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_7af:
	/* 0x7af: cmp    r13,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 47ULL);
x86_l_7b3:
	/* 0x7b3: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_7b9:
	/* 0x7b9: lea    ecx,[r13+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_7c0:
	/* 0x7c0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7c6:
	/* 0x7c6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_7ca:
	/* 0x7ca: mov    BYTE PTR [rax+0x33],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_7cd:
	/* 0x7cd: cmp    r13,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 48ULL);
x86_l_7d1:
	/* 0x7d1: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_7d7:
	/* 0x7d7: lea    ecx,[r13+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_7de:
	/* 0x7de: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7e4:
	/* 0x7e4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_7e8:
	/* 0x7e8: mov    BYTE PTR [rax+0x34],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_7eb:
	/* 0x7eb: cmp    r13,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 49ULL);
x86_l_7ef:
	/* 0x7ef: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_7f5:
	/* 0x7f5: lea    ecx,[r13+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_7fc:
	/* 0x7fc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_802:
	/* 0x802: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_806:
	/* 0x806: mov    BYTE PTR [rax+0x35],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_809:
	/* 0x809: cmp    r13,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 50ULL);
x86_l_80d:
	/* 0x80d: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_813:
	/* 0x813: lea    ecx,[r13+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_81a:
	/* 0x81a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_820:
	/* 0x820: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_824:
	/* 0x824: mov    BYTE PTR [rax+0x36],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_827:
	/* 0x827: cmp    r13,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 51ULL);
x86_l_82b:
	/* 0x82b: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_831:
	/* 0x831: lea    ecx,[r13+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_838:
	/* 0x838: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_83e:
	/* 0x83e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_842:
	/* 0x842: mov    BYTE PTR [rax+0x37],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_845:
	/* 0x845: cmp    r13,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 52ULL);
x86_l_849:
	/* 0x849: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_84f:
	/* 0x84f: lea    ecx,[r13+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_856:
	/* 0x856: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_85c:
	/* 0x85c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_860:
	/* 0x860: mov    BYTE PTR [rax+0x38],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_863:
	/* 0x863: cmp    r13,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 53ULL);
x86_l_867:
	/* 0x867: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_86d:
	/* 0x86d: lea    ecx,[r13+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_874:
	/* 0x874: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_87a:
	/* 0x87a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_87e:
	/* 0x87e: mov    BYTE PTR [rax+0x39],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_881:
	/* 0x881: cmp    r13,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 54ULL);
x86_l_885:
	/* 0x885: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_88b:
	/* 0x88b: lea    ecx,[r13+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_892:
	/* 0x892: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_898:
	/* 0x898: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_89c:
	/* 0x89c: mov    BYTE PTR [rax+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_89f:
	/* 0x89f: cmp    r13,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 55ULL);
x86_l_8a3:
	/* 0x8a3: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_8a9:
	/* 0x8a9: lea    ecx,[r13+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_8b0:
	/* 0x8b0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8b6:
	/* 0x8b6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_8ba:
	/* 0x8ba: mov    BYTE PTR [rax+0x3b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_8bd:
	/* 0x8bd: cmp    r13,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 56ULL);
x86_l_8c1:
	/* 0x8c1: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_8c7:
	/* 0x8c7: lea    ecx,[r13+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_8ce:
	/* 0x8ce: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8d4:
	/* 0x8d4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_8d8:
	/* 0x8d8: mov    BYTE PTR [rax+0x3c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_8db:
	/* 0x8db: cmp    r13,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 57ULL);
x86_l_8df:
	/* 0x8df: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_8e5:
	/* 0x8e5: lea    ecx,[r13+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_8ec:
	/* 0x8ec: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8f2:
	/* 0x8f2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_8f6:
	/* 0x8f6: mov    BYTE PTR [rax+0x3d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_8f9:
	/* 0x8f9: cmp    r13,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 58ULL);
x86_l_8fd:
	/* 0x8fd: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_903:
	/* 0x903: lea    ecx,[r13+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_90a:
	/* 0x90a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_910:
	/* 0x910: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_914:
	/* 0x914: mov    BYTE PTR [rax+0x3e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_917:
	/* 0x917: cmp    r13,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 59ULL);
x86_l_91b:
	/* 0x91b: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_921:
	/* 0x921: lea    ecx,[r13+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_928:
	/* 0x928: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_92e:
	/* 0x92e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_932:
	/* 0x932: mov    BYTE PTR [rax+0x3f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_935:
	/* 0x935: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_939:
	/* 0x939: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_93f:
	/* 0x93f: lea    ecx,[r13+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_946:
	/* 0x946: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_94c:
	/* 0x94c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_950:
	/* 0x950: mov    BYTE PTR [rax+0x40],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_953:
	/* 0x953: cmp    r13,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 61ULL);
x86_l_957:
	/* 0x957: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_95d:
	/* 0x95d: lea    ecx,[r13+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_964:
	/* 0x964: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_96a:
	/* 0x96a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_96e:
	/* 0x96e: mov    BYTE PTR [rax+0x41],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_971:
	/* 0x971: cmp    r13,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 62ULL);
x86_l_975:
	/* 0x975: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_97b:
	/* 0x97b: lea    ecx,[r13+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_982:
	/* 0x982: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_988:
	/* 0x988: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_98c:
	/* 0x98c: mov    BYTE PTR [rax+0x42],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_98f:
	/* 0x98f: cmp    r13,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 63ULL);
x86_l_993:
	/* 0x993: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_999:
	/* 0x999: lea    ecx,[r13+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_9a0:
	/* 0x9a0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9a6:
	/* 0x9a6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_9aa:
	/* 0x9aa: mov    BYTE PTR [rax+0x43],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_9ad:
	/* 0x9ad: cmp    r13,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 64ULL);
x86_l_9b1:
	/* 0x9b1: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_9b7:
	/* 0x9b7: lea    ecx,[r13+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_9be:
	/* 0x9be: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9c4:
	/* 0x9c4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_9c8:
	/* 0x9c8: mov    BYTE PTR [rax+0x44],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_9cb:
	/* 0x9cb: cmp    r13,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 65ULL);
x86_l_9cf:
	/* 0x9cf: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_9d5:
	/* 0x9d5: lea    ecx,[r13+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_9dc:
	/* 0x9dc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9e2:
	/* 0x9e2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_9e6:
	/* 0x9e6: mov    BYTE PTR [rax+0x45],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_9e9:
	/* 0x9e9: cmp    r13,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 66ULL);
x86_l_9ed:
	/* 0x9ed: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_9f3:
	/* 0x9f3: lea    ecx,[r13+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_9fa:
	/* 0x9fa: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a00:
	/* 0xa00: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a04:
	/* 0xa04: mov    BYTE PTR [rax+0x46],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_a07:
	/* 0xa07: cmp    r13,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 67ULL);
x86_l_a0b:
	/* 0xa0b: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_a11:
	/* 0xa11: lea    ecx,[r13+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_a18:
	/* 0xa18: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a1e:
	/* 0xa1e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a22:
	/* 0xa22: mov    BYTE PTR [rax+0x47],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_a25:
	/* 0xa25: cmp    r13,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 68ULL);
x86_l_a29:
	/* 0xa29: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_a2f:
	/* 0xa2f: lea    ecx,[r13+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_a36:
	/* 0xa36: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a3c:
	/* 0xa3c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a40:
	/* 0xa40: mov    BYTE PTR [rax+0x48],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a43:
	/* 0xa43: cmp    r13,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 69ULL);
x86_l_a47:
	/* 0xa47: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_a4d:
	/* 0xa4d: lea    ecx,[r13+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_a54:
	/* 0xa54: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a5a:
	/* 0xa5a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a5e:
	/* 0xa5e: mov    BYTE PTR [rax+0x49],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_a61:
	/* 0xa61: cmp    r13,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 70ULL);
x86_l_a65:
	/* 0xa65: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_a6b:
	/* 0xa6b: lea    ecx,[r13+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_a72:
	/* 0xa72: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a78:
	/* 0xa78: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a7c:
	/* 0xa7c: mov    BYTE PTR [rax+0x4a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_a7f:
	/* 0xa7f: cmp    r13,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 71ULL);
x86_l_a83:
	/* 0xa83: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_a89:
	/* 0xa89: lea    ecx,[r13+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_a90:
	/* 0xa90: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a96:
	/* 0xa96: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_a9a:
	/* 0xa9a: mov    BYTE PTR [rax+0x4b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_a9d:
	/* 0xa9d: cmp    r13,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 72ULL);
x86_l_aa1:
	/* 0xaa1: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_aa7:
	/* 0xaa7: lea    ecx,[r13+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_aae:
	/* 0xaae: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ab4:
	/* 0xab4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_ab8:
	/* 0xab8: mov    BYTE PTR [rax+0x4c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_abb:
	/* 0xabb: cmp    r13,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 73ULL);
x86_l_abf:
	/* 0xabf: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_ac5:
	/* 0xac5: lea    ecx,[r13+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_acc:
	/* 0xacc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ad2:
	/* 0xad2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_ad6:
	/* 0xad6: mov    BYTE PTR [rax+0x4d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_ad9:
	/* 0xad9: cmp    r13,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 74ULL);
x86_l_add:
	/* 0xadd: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_ae3:
	/* 0xae3: lea    ecx,[r13+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_aea:
	/* 0xaea: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_af0:
	/* 0xaf0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_af4:
	/* 0xaf4: mov    BYTE PTR [rax+0x4e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_af7:
	/* 0xaf7: cmp    r13,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 75ULL);
x86_l_afb:
	/* 0xafb: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_b01:
	/* 0xb01: lea    ecx,[r13+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_b08:
	/* 0xb08: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b0e:
	/* 0xb0e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b12:
	/* 0xb12: mov    BYTE PTR [rax+0x4f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_b15:
	/* 0xb15: cmp    r13,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 76ULL);
x86_l_b19:
	/* 0xb19: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_b1f:
	/* 0xb1f: lea    ecx,[r13+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_b26:
	/* 0xb26: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b2c:
	/* 0xb2c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b30:
	/* 0xb30: mov    BYTE PTR [rax+0x50],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b33:
	/* 0xb33: cmp    r13,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 77ULL);
x86_l_b37:
	/* 0xb37: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_b3d:
	/* 0xb3d: lea    ecx,[r13+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_b44:
	/* 0xb44: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b4a:
	/* 0xb4a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b4e:
	/* 0xb4e: mov    BYTE PTR [rax+0x51],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_b51:
	/* 0xb51: cmp    r13,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 78ULL);
x86_l_b55:
	/* 0xb55: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_b5b:
	/* 0xb5b: lea    ecx,[r13+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_b62:
	/* 0xb62: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b68:
	/* 0xb68: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b6c:
	/* 0xb6c: mov    BYTE PTR [rax+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_b6f:
	/* 0xb6f: cmp    r13,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 79ULL);
x86_l_b73:
	/* 0xb73: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_b79:
	/* 0xb79: lea    ecx,[r13+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_b80:
	/* 0xb80: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b86:
	/* 0xb86: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_b8a:
	/* 0xb8a: mov    BYTE PTR [rax+0x53],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_b8d:
	/* 0xb8d: cmp    r13,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 80ULL);
x86_l_b91:
	/* 0xb91: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_b97:
	/* 0xb97: lea    ecx,[r13+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_b9e:
	/* 0xb9e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ba4:
	/* 0xba4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_ba8:
	/* 0xba8: mov    BYTE PTR [rax+0x54],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_bab:
	/* 0xbab: cmp    r13,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 81ULL);
x86_l_baf:
	/* 0xbaf: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_bb5:
	/* 0xbb5: lea    ecx,[r13+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_bbc:
	/* 0xbbc: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bc2:
	/* 0xbc2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_bc6:
	/* 0xbc6: mov    BYTE PTR [rax+0x55],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_bc9:
	/* 0xbc9: cmp    r13,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 82ULL);
x86_l_bcd:
	/* 0xbcd: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_bd3:
	/* 0xbd3: lea    ecx,[r13+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_bda:
	/* 0xbda: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_be0:
	/* 0xbe0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_be4:
	/* 0xbe4: mov    BYTE PTR [rax+0x56],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_be7:
	/* 0xbe7: cmp    r13,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 83ULL);
x86_l_beb:
	/* 0xbeb: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_bf1:
	/* 0xbf1: lea    ecx,[r13+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_bf8:
	/* 0xbf8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bfe:
	/* 0xbfe: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c02:
	/* 0xc02: mov    BYTE PTR [rax+0x57],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_c05:
	/* 0xc05: cmp    r13,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 84ULL);
x86_l_c09:
	/* 0xc09: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_c0f:
	/* 0xc0f: lea    ecx,[r13+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_c16:
	/* 0xc16: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c1c:
	/* 0xc1c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c20:
	/* 0xc20: mov    BYTE PTR [rax+0x58],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c23:
	/* 0xc23: cmp    r13,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 85ULL);
x86_l_c27:
	/* 0xc27: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_c2d:
	/* 0xc2d: lea    ecx,[r13+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_c34:
	/* 0xc34: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c3a:
	/* 0xc3a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c3e:
	/* 0xc3e: mov    BYTE PTR [rax+0x59],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_c41:
	/* 0xc41: cmp    r13,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 86ULL);
x86_l_c45:
	/* 0xc45: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_c4b:
	/* 0xc4b: lea    ecx,[r13+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_c52:
	/* 0xc52: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c58:
	/* 0xc58: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c5c:
	/* 0xc5c: mov    BYTE PTR [rax+0x5a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_c5f:
	/* 0xc5f: cmp    r13,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 87ULL);
x86_l_c63:
	/* 0xc63: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_c69:
	/* 0xc69: lea    ecx,[r13+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_c70:
	/* 0xc70: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c76:
	/* 0xc76: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c7a:
	/* 0xc7a: mov    BYTE PTR [rax+0x5b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_c7d:
	/* 0xc7d: cmp    r13,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 88ULL);
x86_l_c81:
	/* 0xc81: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_c87:
	/* 0xc87: lea    ecx,[r13+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_c8e:
	/* 0xc8e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c94:
	/* 0xc94: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_c98:
	/* 0xc98: mov    BYTE PTR [rax+0x5c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_c9b:
	/* 0xc9b: cmp    r13,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 89ULL);
x86_l_c9f:
	/* 0xc9f: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_ca5:
	/* 0xca5: lea    ecx,[r13+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_cac:
	/* 0xcac: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_cb2:
	/* 0xcb2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_cb6:
	/* 0xcb6: mov    BYTE PTR [rax+0x5d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_cb9:
	/* 0xcb9: cmp    r13,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 90ULL);
x86_l_cbd:
	/* 0xcbd: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_cbf:
	/* 0xcbf: lea    ecx,[r13+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
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
	/* 0xcd3: cmp    r13,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 91ULL);
x86_l_cd7:
	/* 0xcd7: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_cd9:
	/* 0xcd9: lea    ecx,[r13+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_ce0:
	/* 0xce0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ce6:
	/* 0xce6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_cea:
	/* 0xcea: mov    BYTE PTR [rax+0x5f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_ced:
	/* 0xced: cmp    r13,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 92ULL);
x86_l_cf1:
	/* 0xcf1: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_cf3:
	/* 0xcf3: lea    ecx,[r13+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_cfa:
	/* 0xcfa: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_d00:
	/* 0xd00: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_d04:
	/* 0xd04: mov    BYTE PTR [rax+0x60],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_d07:
	/* 0xd07: cmp    r13,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 93ULL);
x86_l_d0b:
	/* 0xd0b: je     d23 <generic_usdt_filter_arg_2+0xd23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d23;
	}
x86_l_d0d:
	/* 0xd0d: add    r13d,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_d14:
	/* 0xd14: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_d1b:
	/* 0xd1b: movzx  ecx,BYTE PTR [rdx+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_d20:
	/* 0xd20: mov    BYTE PTR [rax+0x61],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_d23:
	/* 0xd23: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d28:
	/* 0xd28: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_d2b:
	/* 0xd2b: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d2e:
	/* 0xd2e: jmp    329d <generic_usdt_filter_arg_2+0x329d> */
	return 12957ULL;
x86_l_d33:
	/* 0xd33: lea    eax,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_d36:
	/* 0xd36: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d39:
	/* 0xd39: jb     dd2 <generic_usdt_filter_arg_2+0xdd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_dd2;
	}
x86_l_d3f:
	/* 0xd3f: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_d42:
	/* 0xd42: je     d51 <generic_usdt_filter_arg_2+0xd51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d51;
	}
x86_l_d44:
	/* 0xd44: jmp    32d5 <generic_usdt_filter_arg_2+0x32d5> */
	return 13013ULL;
x86_l_d49:
	/* 0xd49: lea    eax,[rcx-0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551576ULL);
x86_l_d4c:
	/* 0xd4c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d4f:
	/* 0xd4f: jae    dc9 <generic_usdt_filter_arg_2+0xdc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_dc9;
	}
x86_l_d51:
	/* 0xd51: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_d5a:
	/* 0xd5a: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_d63:
	/* 0xd63: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_d6c:
	/* 0xd6c: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_d75:
	/* 0xd75: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_d7e:
	/* 0xd7e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d81:
	/* 0xd81: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_d84:
	/* 0xd84: jg     da0 <generic_usdt_filter_arg_2+0xda0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_da0;
	}
x86_l_d86:
	/* 0xd86: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_d89:
	/* 0xd89: je     1c0d <generic_usdt_filter_arg_2+0x1c0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7181ULL;
	}
x86_l_d8f:
	/* 0xd8f: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_d92:
	/* 0xd92: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_d95:
	/* 0xd95: je     1c0f <generic_usdt_filter_arg_2+0x1c0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7183ULL;
	}
x86_l_d9b:
	/* 0xd9b: jmp    32d0 <generic_usdt_filter_arg_2+0x32d0> */
	return 13008ULL;
x86_l_da0:
	/* 0xda0: cmp    ecx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_da3:
	/* 0xda3: je     1be5 <generic_usdt_filter_arg_2+0x1be5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7141ULL;
	}
x86_l_da9:
	/* 0xda9: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_dac:
	/* 0xdac: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_daf:
	/* 0xdaf: je     1c0f <generic_usdt_filter_arg_2+0x1c0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7183ULL;
	}
x86_l_db5:
	/* 0xdb5: jmp    32d0 <generic_usdt_filter_arg_2+0x32d0> */
	return 13008ULL;
x86_l_dba:
	/* 0xdba: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_dbd:
	/* 0xdbd: jne    32d5 <generic_usdt_filter_arg_2+0x32d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13013ULL;
	}
x86_l_dc3:
	/* 0xdc3: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_dc7:
	/* 0xdc7: jmp    dd2 <generic_usdt_filter_arg_2+0xdd2> */
	goto x86_l_dd2;
x86_l_dc9:
	/* 0xdc9: cmp    ecx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 42ULL);
x86_l_dcc:
	/* 0xdcc: jne    32d5 <generic_usdt_filter_arg_2+0x32d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13013ULL;
	}
x86_l_dd2:
	/* 0xdd2: mov    r13d,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dd5:
	/* 0xdd5: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_dd8:
	/* 0xdd8: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_ddb:
	/* 0xddb: jne    deb <generic_usdt_filter_arg_2+0xdeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_deb;
	}
x86_l_ddd:
	/* 0xddd: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_ddf:
	/* 0xddf: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_de2:
	/* 0xde2: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_de5:
	/* 0xde5: jne    32df <generic_usdt_filter_arg_2+0x32df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13023ULL;
	}
x86_l_deb:
	/* 0xdeb: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_dee:
	/* 0xdee: ja     1c86 <generic_usdt_filter_arg_2+0x1c86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7302ULL;
	}
x86_l_df4:
	/* 0xdf4: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_df6:
	/* 0xdf6: mov    edx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 67109120ULL);
x86_l_dfb:
	/* 0xdfb: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_dff:
	/* 0xdff: jb     2849 <generic_usdt_filter_arg_2+0x2849> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10313ULL;
	}
x86_l_e05:
	/* 0xe05: mov    edx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 134218240ULL);
x86_l_e0a:
	/* 0xe0a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_e0e:
	/* 0xe0e: jb     1ccf <generic_usdt_filter_arg_2+0x1ccf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7375ULL;
	}
x86_l_e14:
	/* 0xe14: movabs rdx,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 206158430208ULL);
x86_l_e1e:
	/* 0xe1e: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_e22:
	/* 0xe22: jae    1c86 <generic_usdt_filter_arg_2+0x1c86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7302ULL;
	}
x86_l_e28:
	/* 0xe28: mov    WORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_e2f:
	/* 0xe2f: cmp    r13d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 144ULL);
x86_l_e36:
	/* 0xe36: ja     1ca7 <generic_usdt_filter_arg_2+0x1ca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7335ULL;
	}
x86_l_e3c:
	/* 0xe3c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e41:
	/* 0xe41: mov    ecx,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e43:
	/* 0xe43: lea    rdx,[rdi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_e47:
	/* 0xe47: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_e4b:
	/* 0xe4b: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e50:
	/* 0xe50: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_e53:
	/* 0xe53: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e58:
	/* 0xe58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e5a:
	/* 0xe5a: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_e5d:
	/* 0xe5d: mov    ecx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e61:
	/* 0xe61: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_e63:
	/* 0xe63: je     1ca7 <generic_usdt_filter_arg_2+0x1ca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7335ULL;
	}
x86_l_e69:
	/* 0xe69: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
	return 3694ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3694ULL: goto x86_l_e6e;
	case 3699ULL: goto x86_l_e73;
	case 3705ULL: goto x86_l_e79;
	case 3707ULL: goto x86_l_e7b;
	case 3713ULL: goto x86_l_e81;
	case 3716ULL: goto x86_l_e84;
	case 3719ULL: goto x86_l_e87;
	case 3725ULL: goto x86_l_e8d;
	case 3729ULL: goto x86_l_e91;
	case 3731ULL: goto x86_l_e93;
	case 3737ULL: goto x86_l_e99;
	case 3739ULL: goto x86_l_e9b;
	case 3745ULL: goto x86_l_ea1;
	case 3748ULL: goto x86_l_ea4;
	case 3754ULL: goto x86_l_eaa;
	case 3758ULL: goto x86_l_eae;
	case 3760ULL: goto x86_l_eb0;
	case 3766ULL: goto x86_l_eb6;
	case 3768ULL: goto x86_l_eb8;
	case 3771ULL: goto x86_l_ebb;
	case 3777ULL: goto x86_l_ec1;
	case 3780ULL: goto x86_l_ec4;
	case 3786ULL: goto x86_l_eca;
	case 3790ULL: goto x86_l_ece;
	case 3792ULL: goto x86_l_ed0;
	case 3798ULL: goto x86_l_ed6;
	case 3801ULL: goto x86_l_ed9;
	case 3803ULL: goto x86_l_edb;
	case 3807ULL: goto x86_l_edf;
	case 3812ULL: goto x86_l_ee4;
	case 3815ULL: goto x86_l_ee7;
	case 3818ULL: goto x86_l_eea;
	case 3821ULL: goto x86_l_eed;
	case 3827ULL: goto x86_l_ef3;
	case 3830ULL: goto x86_l_ef6;
	case 3834ULL: goto x86_l_efa;
	case 3839ULL: goto x86_l_eff;
	case 3842ULL: goto x86_l_f02;
	case 3847ULL: goto x86_l_f07;
	case 3853ULL: goto x86_l_f0d;
	case 3858ULL: goto x86_l_f12;
	case 3861ULL: goto x86_l_f15;
	case 3867ULL: goto x86_l_f1b;
	case 3872ULL: goto x86_l_f20;
	case 3875ULL: goto x86_l_f23;
	case 3881ULL: goto x86_l_f29;
	case 3884ULL: goto x86_l_f2c;
	case 3888ULL: goto x86_l_f30;
	case 3891ULL: goto x86_l_f33;
	case 3895ULL: goto x86_l_f37;
	case 3903ULL: goto x86_l_f3f;
	case 3908ULL: goto x86_l_f44;
	case 3915ULL: goto x86_l_f4b;
	case 3920ULL: goto x86_l_f50;
	case 3922ULL: goto x86_l_f52;
	case 3925ULL: goto x86_l_f55;
	case 3931ULL: goto x86_l_f5b;
	case 3937ULL: goto x86_l_f61;
	case 3942ULL: goto x86_l_f66;
	case 3945ULL: goto x86_l_f69;
	case 3951ULL: goto x86_l_f6f;
	case 3956ULL: goto x86_l_f74;
	case 3963ULL: goto x86_l_f7b;
	case 3968ULL: goto x86_l_f80;
	case 3970ULL: goto x86_l_f82;
	case 3973ULL: goto x86_l_f85;
	case 3979ULL: goto x86_l_f8b;
	case 3984ULL: goto x86_l_f90;
	case 3987ULL: goto x86_l_f93;
	case 3992ULL: goto x86_l_f98;
	case 3995ULL: goto x86_l_f9b;
	case 3998ULL: goto x86_l_f9e;
	case 4000ULL: goto x86_l_fa0;
	case 4003ULL: goto x86_l_fa3;
	case 4009ULL: goto x86_l_fa9;
	case 4015ULL: goto x86_l_faf;
	case 4018ULL: goto x86_l_fb2;
	case 4022ULL: goto x86_l_fb6;
	case 4028ULL: goto x86_l_fbc;
	case 4034ULL: goto x86_l_fc2;
	case 4040ULL: goto x86_l_fc8;
	case 4046ULL: goto x86_l_fce;
	case 4049ULL: goto x86_l_fd1;
	case 4053ULL: goto x86_l_fd5;
	case 4059ULL: goto x86_l_fdb;
	case 4065ULL: goto x86_l_fe1;
	case 4071ULL: goto x86_l_fe7;
	case 4077ULL: goto x86_l_fed;
	case 4080ULL: goto x86_l_ff0;
	case 4084ULL: goto x86_l_ff4;
	case 4090ULL: goto x86_l_ffa;
	case 4096ULL: goto x86_l_1000;
	case 4102ULL: goto x86_l_1006;
	case 4108ULL: goto x86_l_100c;
	case 4111ULL: goto x86_l_100f;
	case 4115ULL: goto x86_l_1013;
	case 4121ULL: goto x86_l_1019;
	case 4127ULL: goto x86_l_101f;
	case 4133ULL: goto x86_l_1025;
	case 4139ULL: goto x86_l_102b;
	case 4142ULL: goto x86_l_102e;
	case 4146ULL: goto x86_l_1032;
	case 4152ULL: goto x86_l_1038;
	case 4158ULL: goto x86_l_103e;
	case 4164ULL: goto x86_l_1044;
	case 4170ULL: goto x86_l_104a;
	case 4173ULL: goto x86_l_104d;
	case 4177ULL: goto x86_l_1051;
	case 4183ULL: goto x86_l_1057;
	case 4189ULL: goto x86_l_105d;
	case 4195ULL: goto x86_l_1063;
	case 4201ULL: goto x86_l_1069;
	case 4204ULL: goto x86_l_106c;
	case 4208ULL: goto x86_l_1070;
	case 4214ULL: goto x86_l_1076;
	case 4220ULL: goto x86_l_107c;
	case 4226ULL: goto x86_l_1082;
	case 4232ULL: goto x86_l_1088;
	case 4235ULL: goto x86_l_108b;
	case 4239ULL: goto x86_l_108f;
	case 4245ULL: goto x86_l_1095;
	case 4251ULL: goto x86_l_109b;
	case 4257ULL: goto x86_l_10a1;
	case 4263ULL: goto x86_l_10a7;
	case 4266ULL: goto x86_l_10aa;
	case 4270ULL: goto x86_l_10ae;
	case 4276ULL: goto x86_l_10b4;
	case 4282ULL: goto x86_l_10ba;
	case 4288ULL: goto x86_l_10c0;
	case 4294ULL: goto x86_l_10c6;
	case 4297ULL: goto x86_l_10c9;
	case 4301ULL: goto x86_l_10cd;
	case 4307ULL: goto x86_l_10d3;
	case 4313ULL: goto x86_l_10d9;
	case 4319ULL: goto x86_l_10df;
	case 4325ULL: goto x86_l_10e5;
	case 4328ULL: goto x86_l_10e8;
	case 4332ULL: goto x86_l_10ec;
	case 4338ULL: goto x86_l_10f2;
	case 4344ULL: goto x86_l_10f8;
	case 4350ULL: goto x86_l_10fe;
	case 4356ULL: goto x86_l_1104;
	case 4359ULL: goto x86_l_1107;
	case 4363ULL: goto x86_l_110b;
	case 4369ULL: goto x86_l_1111;
	case 4375ULL: goto x86_l_1117;
	case 4381ULL: goto x86_l_111d;
	case 4387ULL: goto x86_l_1123;
	case 4390ULL: goto x86_l_1126;
	case 4394ULL: goto x86_l_112a;
	case 4400ULL: goto x86_l_1130;
	case 4406ULL: goto x86_l_1136;
	case 4412ULL: goto x86_l_113c;
	case 4418ULL: goto x86_l_1142;
	case 4421ULL: goto x86_l_1145;
	case 4425ULL: goto x86_l_1149;
	case 4431ULL: goto x86_l_114f;
	case 4437ULL: goto x86_l_1155;
	case 4443ULL: goto x86_l_115b;
	case 4449ULL: goto x86_l_1161;
	case 4452ULL: goto x86_l_1164;
	case 4456ULL: goto x86_l_1168;
	case 4462ULL: goto x86_l_116e;
	case 4468ULL: goto x86_l_1174;
	case 4474ULL: goto x86_l_117a;
	case 4480ULL: goto x86_l_1180;
	case 4483ULL: goto x86_l_1183;
	case 4487ULL: goto x86_l_1187;
	case 4493ULL: goto x86_l_118d;
	case 4499ULL: goto x86_l_1193;
	case 4505ULL: goto x86_l_1199;
	case 4511ULL: goto x86_l_119f;
	case 4514ULL: goto x86_l_11a2;
	case 4518ULL: goto x86_l_11a6;
	case 4524ULL: goto x86_l_11ac;
	case 4530ULL: goto x86_l_11b2;
	case 4536ULL: goto x86_l_11b8;
	case 4542ULL: goto x86_l_11be;
	case 4545ULL: goto x86_l_11c1;
	case 4549ULL: goto x86_l_11c5;
	case 4555ULL: goto x86_l_11cb;
	case 4561ULL: goto x86_l_11d1;
	case 4567ULL: goto x86_l_11d7;
	case 4573ULL: goto x86_l_11dd;
	case 4576ULL: goto x86_l_11e0;
	case 4580ULL: goto x86_l_11e4;
	case 4586ULL: goto x86_l_11ea;
	case 4592ULL: goto x86_l_11f0;
	case 4598ULL: goto x86_l_11f6;
	case 4604ULL: goto x86_l_11fc;
	case 4607ULL: goto x86_l_11ff;
	case 4611ULL: goto x86_l_1203;
	case 4617ULL: goto x86_l_1209;
	case 4623ULL: goto x86_l_120f;
	case 4629ULL: goto x86_l_1215;
	case 4635ULL: goto x86_l_121b;
	case 4638ULL: goto x86_l_121e;
	case 4642ULL: goto x86_l_1222;
	case 4648ULL: goto x86_l_1228;
	case 4654ULL: goto x86_l_122e;
	case 4660ULL: goto x86_l_1234;
	case 4666ULL: goto x86_l_123a;
	case 4669ULL: goto x86_l_123d;
	case 4673ULL: goto x86_l_1241;
	case 4679ULL: goto x86_l_1247;
	case 4685ULL: goto x86_l_124d;
	case 4691ULL: goto x86_l_1253;
	case 4697ULL: goto x86_l_1259;
	case 4700ULL: goto x86_l_125c;
	case 4704ULL: goto x86_l_1260;
	case 4710ULL: goto x86_l_1266;
	case 4716ULL: goto x86_l_126c;
	case 4722ULL: goto x86_l_1272;
	case 4728ULL: goto x86_l_1278;
	case 4731ULL: goto x86_l_127b;
	case 4735ULL: goto x86_l_127f;
	case 4741ULL: goto x86_l_1285;
	case 4747ULL: goto x86_l_128b;
	case 4753ULL: goto x86_l_1291;
	case 4759ULL: goto x86_l_1297;
	case 4762ULL: goto x86_l_129a;
	case 4766ULL: goto x86_l_129e;
	case 4772ULL: goto x86_l_12a4;
	case 4778ULL: goto x86_l_12aa;
	case 4784ULL: goto x86_l_12b0;
	case 4790ULL: goto x86_l_12b6;
	case 4793ULL: goto x86_l_12b9;
	case 4797ULL: goto x86_l_12bd;
	case 4803ULL: goto x86_l_12c3;
	case 4809ULL: goto x86_l_12c9;
	case 4815ULL: goto x86_l_12cf;
	case 4821ULL: goto x86_l_12d5;
	case 4824ULL: goto x86_l_12d8;
	case 4828ULL: goto x86_l_12dc;
	case 4834ULL: goto x86_l_12e2;
	case 4840ULL: goto x86_l_12e8;
	case 4846ULL: goto x86_l_12ee;
	case 4852ULL: goto x86_l_12f4;
	case 4855ULL: goto x86_l_12f7;
	case 4859ULL: goto x86_l_12fb;
	case 4865ULL: goto x86_l_1301;
	case 4871ULL: goto x86_l_1307;
	case 4877ULL: goto x86_l_130d;
	case 4883ULL: goto x86_l_1313;
	case 4886ULL: goto x86_l_1316;
	case 4890ULL: goto x86_l_131a;
	case 4896ULL: goto x86_l_1320;
	case 4902ULL: goto x86_l_1326;
	case 4908ULL: goto x86_l_132c;
	case 4914ULL: goto x86_l_1332;
	case 4917ULL: goto x86_l_1335;
	case 4921ULL: goto x86_l_1339;
	case 4927ULL: goto x86_l_133f;
	case 4933ULL: goto x86_l_1345;
	case 4939ULL: goto x86_l_134b;
	case 4945ULL: goto x86_l_1351;
	case 4948ULL: goto x86_l_1354;
	case 4952ULL: goto x86_l_1358;
	case 4958ULL: goto x86_l_135e;
	case 4964ULL: goto x86_l_1364;
	case 4970ULL: goto x86_l_136a;
	case 4976ULL: goto x86_l_1370;
	case 4979ULL: goto x86_l_1373;
	case 4983ULL: goto x86_l_1377;
	case 4989ULL: goto x86_l_137d;
	case 4995ULL: goto x86_l_1383;
	case 5001ULL: goto x86_l_1389;
	case 5007ULL: goto x86_l_138f;
	case 5010ULL: goto x86_l_1392;
	case 5014ULL: goto x86_l_1396;
	case 5020ULL: goto x86_l_139c;
	case 5026ULL: goto x86_l_13a2;
	case 5032ULL: goto x86_l_13a8;
	case 5038ULL: goto x86_l_13ae;
	case 5041ULL: goto x86_l_13b1;
	case 5045ULL: goto x86_l_13b5;
	case 5051ULL: goto x86_l_13bb;
	case 5057ULL: goto x86_l_13c1;
	case 5063ULL: goto x86_l_13c7;
	case 5069ULL: goto x86_l_13cd;
	case 5072ULL: goto x86_l_13d0;
	case 5076ULL: goto x86_l_13d4;
	case 5082ULL: goto x86_l_13da;
	case 5088ULL: goto x86_l_13e0;
	case 5094ULL: goto x86_l_13e6;
	case 5100ULL: goto x86_l_13ec;
	case 5103ULL: goto x86_l_13ef;
	case 5107ULL: goto x86_l_13f3;
	case 5113ULL: goto x86_l_13f9;
	case 5119ULL: goto x86_l_13ff;
	case 5125ULL: goto x86_l_1405;
	case 5131ULL: goto x86_l_140b;
	case 5134ULL: goto x86_l_140e;
	case 5138ULL: goto x86_l_1412;
	case 5144ULL: goto x86_l_1418;
	case 5150ULL: goto x86_l_141e;
	case 5156ULL: goto x86_l_1424;
	case 5162ULL: goto x86_l_142a;
	case 5165ULL: goto x86_l_142d;
	case 5169ULL: goto x86_l_1431;
	case 5175ULL: goto x86_l_1437;
	case 5181ULL: goto x86_l_143d;
	case 5187ULL: goto x86_l_1443;
	case 5193ULL: goto x86_l_1449;
	case 5196ULL: goto x86_l_144c;
	case 5200ULL: goto x86_l_1450;
	case 5206ULL: goto x86_l_1456;
	case 5212ULL: goto x86_l_145c;
	case 5218ULL: goto x86_l_1462;
	case 5224ULL: goto x86_l_1468;
	case 5227ULL: goto x86_l_146b;
	case 5231ULL: goto x86_l_146f;
	case 5237ULL: goto x86_l_1475;
	case 5243ULL: goto x86_l_147b;
	case 5249ULL: goto x86_l_1481;
	case 5255ULL: goto x86_l_1487;
	case 5258ULL: goto x86_l_148a;
	case 5262ULL: goto x86_l_148e;
	case 5268ULL: goto x86_l_1494;
	case 5274ULL: goto x86_l_149a;
	case 5280ULL: goto x86_l_14a0;
	case 5286ULL: goto x86_l_14a6;
	case 5289ULL: goto x86_l_14a9;
	case 5293ULL: goto x86_l_14ad;
	case 5299ULL: goto x86_l_14b3;
	case 5305ULL: goto x86_l_14b9;
	case 5311ULL: goto x86_l_14bf;
	case 5317ULL: goto x86_l_14c5;
	case 5320ULL: goto x86_l_14c8;
	case 5324ULL: goto x86_l_14cc;
	case 5330ULL: goto x86_l_14d2;
	case 5336ULL: goto x86_l_14d8;
	case 5342ULL: goto x86_l_14de;
	case 5348ULL: goto x86_l_14e4;
	case 5351ULL: goto x86_l_14e7;
	case 5355ULL: goto x86_l_14eb;
	case 5361ULL: goto x86_l_14f1;
	case 5367ULL: goto x86_l_14f7;
	case 5373ULL: goto x86_l_14fd;
	case 5379ULL: goto x86_l_1503;
	case 5382ULL: goto x86_l_1506;
	case 5386ULL: goto x86_l_150a;
	case 5392ULL: goto x86_l_1510;
	case 5398ULL: goto x86_l_1516;
	case 5404ULL: goto x86_l_151c;
	case 5410ULL: goto x86_l_1522;
	case 5413ULL: goto x86_l_1525;
	case 5417ULL: goto x86_l_1529;
	case 5423ULL: goto x86_l_152f;
	case 5429ULL: goto x86_l_1535;
	case 5435ULL: goto x86_l_153b;
	case 5441ULL: goto x86_l_1541;
	case 5444ULL: goto x86_l_1544;
	case 5448ULL: goto x86_l_1548;
	case 5454ULL: goto x86_l_154e;
	case 5460ULL: goto x86_l_1554;
	case 5466ULL: goto x86_l_155a;
	case 5472ULL: goto x86_l_1560;
	case 5475ULL: goto x86_l_1563;
	case 5479ULL: goto x86_l_1567;
	case 5485ULL: goto x86_l_156d;
	case 5491ULL: goto x86_l_1573;
	case 5497ULL: goto x86_l_1579;
	case 5503ULL: goto x86_l_157f;
	case 5506ULL: goto x86_l_1582;
	case 5510ULL: goto x86_l_1586;
	case 5516ULL: goto x86_l_158c;
	case 5522ULL: goto x86_l_1592;
	case 5528ULL: goto x86_l_1598;
	case 5534ULL: goto x86_l_159e;
	case 5537ULL: goto x86_l_15a1;
	case 5541ULL: goto x86_l_15a5;
	case 5547ULL: goto x86_l_15ab;
	case 5553ULL: goto x86_l_15b1;
	case 5559ULL: goto x86_l_15b7;
	case 5565ULL: goto x86_l_15bd;
	case 5568ULL: goto x86_l_15c0;
	case 5572ULL: goto x86_l_15c4;
	case 5578ULL: goto x86_l_15ca;
	case 5584ULL: goto x86_l_15d0;
	case 5590ULL: goto x86_l_15d6;
	case 5596ULL: goto x86_l_15dc;
	case 5599ULL: goto x86_l_15df;
	case 5603ULL: goto x86_l_15e3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e6e:
	/* 0xe6e: and    eax,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_e73:
	/* 0xe73: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_e79:
	/* 0xe79: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_e7b:
	/* 0xe7b: je     3227 <generic_usdt_filter_arg_2+0x3227> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12839ULL;
	}
x86_l_e81:
	/* 0xe81: mov    ecx,DWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e84:
	/* 0xe84: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_e87:
	/* 0xe87: jbe    3104 <generic_usdt_filter_arg_2+0x3104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 12548ULL;
	}
x86_l_e8d:
	/* 0xe8d: mov    edx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_e91:
	/* 0xe91: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_e93:
	/* 0xe93: je     3104 <generic_usdt_filter_arg_2+0x3104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12548ULL;
	}
x86_l_e99:
	/* 0xe99: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_e9b:
	/* 0xe9b: je     3107 <generic_usdt_filter_arg_2+0x3107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12551ULL;
	}
x86_l_ea1:
	/* 0xea1: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_ea4:
	/* 0xea4: jb     3104 <generic_usdt_filter_arg_2+0x3104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12548ULL;
	}
x86_l_eaa:
	/* 0xeaa: mov    edx,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_eae:
	/* 0xeae: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_eb0:
	/* 0xeb0: je     3104 <generic_usdt_filter_arg_2+0x3104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12548ULL;
	}
x86_l_eb6:
	/* 0xeb6: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_eb8:
	/* 0xeb8: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_ebb:
	/* 0xebb: je     3227 <generic_usdt_filter_arg_2+0x3227> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12839ULL;
	}
x86_l_ec1:
	/* 0xec1: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_ec4:
	/* 0xec4: jb     3104 <generic_usdt_filter_arg_2+0x3104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12548ULL;
	}
x86_l_eca:
	/* 0xeca: mov    ecx,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_ece:
	/* 0xece: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_ed0:
	/* 0xed0: je     3104 <generic_usdt_filter_arg_2+0x3104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12548ULL;
	}
x86_l_ed6:
	/* 0xed6: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ed9:
	/* 0xed9: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_edb:
	/* 0xedb: sete   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_E);
x86_l_edf:
	/* 0xedf: jmp    3107 <generic_usdt_filter_arg_2+0x3107> */
	return 12551ULL;
x86_l_ee4:
	/* 0xee4: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ee7:
	/* 0xee7: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_eea:
	/* 0xeea: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_eed:
	/* 0xeed: ja     32b5 <generic_usdt_filter_arg_2+0x32b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12981ULL;
	}
x86_l_ef3:
	/* 0xef3: mov    edx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ef6:
	/* 0xef6: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_efa:
	/* 0xefa: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_eff:
	/* 0xeff: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_f02:
	/* 0xf02: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f07:
	/* 0xf07: jb     2b0c <generic_usdt_filter_arg_2+0x2b0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11020ULL;
	}
x86_l_f0d:
	/* 0xf0d: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_f12:
	/* 0xf12: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_f15:
	/* 0xf15: jb     2a66 <generic_usdt_filter_arg_2+0x2a66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10854ULL;
	}
x86_l_f1b:
	/* 0xf1b: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_f20:
	/* 0xf20: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_f23:
	/* 0xf23: jae    32b5 <generic_usdt_filter_arg_2+0x32b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12981ULL;
	}
x86_l_f29:
	/* 0xf29: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_f2c:
	/* 0xf2c: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f30:
	/* 0xf30: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f33:
	/* 0xf33: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f37:
	/* 0xf37: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_f3f:
	/* 0xf3f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f44:
	/* 0xf44: mov    rdi,QWORD PTR [rip+0xb1b3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_f4b:
	/* 0xf4b: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f50:
	/* 0xf50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f52:
	/* 0xf52: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f55:
	/* 0xf55: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_f5b:
	/* 0xf5b: je     32ae <generic_usdt_filter_arg_2+0x32ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12974ULL;
	}
x86_l_f61:
	/* 0xf61: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f66:
	/* 0xf66: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f69:
	/* 0xf69: je     32ae <generic_usdt_filter_arg_2+0x32ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12974ULL;
	}
x86_l_f6f:
	/* 0xf6f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f74:
	/* 0xf74: mov    rdi,QWORD PTR [rip+0xb1b3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_f7b:
	/* 0xf7b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f80:
	/* 0xf80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f82:
	/* 0xf82: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f85:
	/* 0xf85: je     32ab <generic_usdt_filter_arg_2+0x32ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12971ULL;
	}
x86_l_f8b:
	/* 0xf8b: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f90:
	/* 0xf90: cmp    esi,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 94ULL);
x86_l_f93:
	/* 0xf93: mov    ecx,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 94ULL);
x86_l_f98:
	/* 0xf98: cmovb  ecx,esi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RSI, X86_WIDTH_32, X86_CC_B);
x86_l_f9b:
	/* 0xf9b: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_f9e:
	/* 0xf9e: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fa0:
	/* 0xfa0: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_fa3:
	/* 0xfa3: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fa9:
	/* 0xfa9: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_faf:
	/* 0xfaf: mov    BYTE PTR [rax+0x4],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_fb2:
	/* 0xfb2: cmp    rsi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1ULL);
x86_l_fb6:
	/* 0xfb6: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_fbc:
	/* 0xfbc: lea    ecx,[rsi+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_fc2:
	/* 0xfc2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fc8:
	/* 0xfc8: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_fce:
	/* 0xfce: mov    BYTE PTR [rax+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_fd1:
	/* 0xfd1: cmp    rsi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 2ULL);
x86_l_fd5:
	/* 0xfd5: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_fdb:
	/* 0xfdb: lea    ecx,[rsi+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_fe1:
	/* 0xfe1: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fe7:
	/* 0xfe7: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_fed:
	/* 0xfed: mov    BYTE PTR [rax+0x6],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_ff0:
	/* 0xff0: cmp    rsi,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 3ULL);
x86_l_ff4:
	/* 0xff4: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_ffa:
	/* 0xffa: lea    ecx,[rsi+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_1000:
	/* 0x1000: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1006:
	/* 0x1006: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_100c:
	/* 0x100c: mov    BYTE PTR [rax+0x7],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_100f:
	/* 0x100f: cmp    rsi,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 4ULL);
x86_l_1013:
	/* 0x1013: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1019:
	/* 0x1019: lea    ecx,[rsi+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_101f:
	/* 0x101f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1025:
	/* 0x1025: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_102b:
	/* 0x102b: mov    BYTE PTR [rax+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_102e:
	/* 0x102e: cmp    rsi,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 5ULL);
x86_l_1032:
	/* 0x1032: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1038:
	/* 0x1038: lea    ecx,[rsi+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_103e:
	/* 0x103e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1044:
	/* 0x1044: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_104a:
	/* 0x104a: mov    BYTE PTR [rax+0x9],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_104d:
	/* 0x104d: cmp    rsi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 6ULL);
x86_l_1051:
	/* 0x1051: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1057:
	/* 0x1057: lea    ecx,[rsi+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_105d:
	/* 0x105d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1063:
	/* 0x1063: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1069:
	/* 0x1069: mov    BYTE PTR [rax+0xa],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_106c:
	/* 0x106c: cmp    rsi,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 7ULL);
x86_l_1070:
	/* 0x1070: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1076:
	/* 0x1076: lea    ecx,[rsi+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_107c:
	/* 0x107c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1082:
	/* 0x1082: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1088:
	/* 0x1088: mov    BYTE PTR [rax+0xb],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_108b:
	/* 0x108b: cmp    rsi,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 8ULL);
x86_l_108f:
	/* 0x108f: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1095:
	/* 0x1095: lea    ecx,[rsi+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_109b:
	/* 0x109b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10a1:
	/* 0x10a1: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_10a7:
	/* 0x10a7: mov    BYTE PTR [rax+0xc],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_10aa:
	/* 0x10aa: cmp    rsi,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 9ULL);
x86_l_10ae:
	/* 0x10ae: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_10b4:
	/* 0x10b4: lea    ecx,[rsi+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_10ba:
	/* 0x10ba: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10c0:
	/* 0x10c0: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_10c6:
	/* 0x10c6: mov    BYTE PTR [rax+0xd],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_10c9:
	/* 0x10c9: cmp    rsi,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 10ULL);
x86_l_10cd:
	/* 0x10cd: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_10d3:
	/* 0x10d3: lea    ecx,[rsi+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_10d9:
	/* 0x10d9: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10df:
	/* 0x10df: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_10e5:
	/* 0x10e5: mov    BYTE PTR [rax+0xe],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_10e8:
	/* 0x10e8: cmp    rsi,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 11ULL);
x86_l_10ec:
	/* 0x10ec: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_10f2:
	/* 0x10f2: lea    ecx,[rsi+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_10f8:
	/* 0x10f8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10fe:
	/* 0x10fe: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1104:
	/* 0x1104: mov    BYTE PTR [rax+0xf],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_1107:
	/* 0x1107: cmp    rsi,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 12ULL);
x86_l_110b:
	/* 0x110b: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1111:
	/* 0x1111: lea    ecx,[rsi+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_1117:
	/* 0x1117: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_111d:
	/* 0x111d: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1123:
	/* 0x1123: mov    BYTE PTR [rax+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1126:
	/* 0x1126: cmp    rsi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 13ULL);
x86_l_112a:
	/* 0x112a: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1130:
	/* 0x1130: lea    ecx,[rsi+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_1136:
	/* 0x1136: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_113c:
	/* 0x113c: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1142:
	/* 0x1142: mov    BYTE PTR [rax+0x11],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_1145:
	/* 0x1145: cmp    rsi,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 14ULL);
x86_l_1149:
	/* 0x1149: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_114f:
	/* 0x114f: lea    ecx,[rsi+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_1155:
	/* 0x1155: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_115b:
	/* 0x115b: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1161:
	/* 0x1161: mov    BYTE PTR [rax+0x12],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1164:
	/* 0x1164: cmp    rsi,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 15ULL);
x86_l_1168:
	/* 0x1168: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_116e:
	/* 0x116e: lea    ecx,[rsi+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_1174:
	/* 0x1174: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_117a:
	/* 0x117a: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1180:
	/* 0x1180: mov    BYTE PTR [rax+0x13],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_1183:
	/* 0x1183: cmp    rsi,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 16ULL);
x86_l_1187:
	/* 0x1187: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_118d:
	/* 0x118d: lea    ecx,[rsi+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_1193:
	/* 0x1193: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1199:
	/* 0x1199: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_119f:
	/* 0x119f: mov    BYTE PTR [rax+0x14],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_11a2:
	/* 0x11a2: cmp    rsi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 17ULL);
x86_l_11a6:
	/* 0x11a6: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_11ac:
	/* 0x11ac: lea    ecx,[rsi+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_11b2:
	/* 0x11b2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11b8:
	/* 0x11b8: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_11be:
	/* 0x11be: mov    BYTE PTR [rax+0x15],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_11c1:
	/* 0x11c1: cmp    rsi,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18ULL);
x86_l_11c5:
	/* 0x11c5: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_11cb:
	/* 0x11cb: lea    ecx,[rsi+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_11d1:
	/* 0x11d1: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11d7:
	/* 0x11d7: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_11dd:
	/* 0x11dd: mov    BYTE PTR [rax+0x16],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_11e0:
	/* 0x11e0: cmp    rsi,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 19ULL);
x86_l_11e4:
	/* 0x11e4: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_11ea:
	/* 0x11ea: lea    ecx,[rsi+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_11f0:
	/* 0x11f0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11f6:
	/* 0x11f6: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_11fc:
	/* 0x11fc: mov    BYTE PTR [rax+0x17],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_11ff:
	/* 0x11ff: cmp    rsi,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 20ULL);
x86_l_1203:
	/* 0x1203: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1209:
	/* 0x1209: lea    ecx,[rsi+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_120f:
	/* 0x120f: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1215:
	/* 0x1215: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_121b:
	/* 0x121b: mov    BYTE PTR [rax+0x18],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_121e:
	/* 0x121e: cmp    rsi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 21ULL);
x86_l_1222:
	/* 0x1222: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1228:
	/* 0x1228: lea    ecx,[rsi+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_122e:
	/* 0x122e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1234:
	/* 0x1234: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_123a:
	/* 0x123a: mov    BYTE PTR [rax+0x19],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_123d:
	/* 0x123d: cmp    rsi,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 22ULL);
x86_l_1241:
	/* 0x1241: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1247:
	/* 0x1247: lea    ecx,[rsi+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_124d:
	/* 0x124d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1253:
	/* 0x1253: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1259:
	/* 0x1259: mov    BYTE PTR [rax+0x1a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_125c:
	/* 0x125c: cmp    rsi,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 23ULL);
x86_l_1260:
	/* 0x1260: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1266:
	/* 0x1266: lea    ecx,[rsi+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_126c:
	/* 0x126c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1272:
	/* 0x1272: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1278:
	/* 0x1278: mov    BYTE PTR [rax+0x1b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_127b:
	/* 0x127b: cmp    rsi,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 24ULL);
x86_l_127f:
	/* 0x127f: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1285:
	/* 0x1285: lea    ecx,[rsi+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_128b:
	/* 0x128b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1291:
	/* 0x1291: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1297:
	/* 0x1297: mov    BYTE PTR [rax+0x1c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_129a:
	/* 0x129a: cmp    rsi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 25ULL);
x86_l_129e:
	/* 0x129e: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_12a4:
	/* 0x12a4: lea    ecx,[rsi+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_12aa:
	/* 0x12aa: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12b0:
	/* 0x12b0: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_12b6:
	/* 0x12b6: mov    BYTE PTR [rax+0x1d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_12b9:
	/* 0x12b9: cmp    rsi,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 26ULL);
x86_l_12bd:
	/* 0x12bd: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_12c3:
	/* 0x12c3: lea    ecx,[rsi+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_12c9:
	/* 0x12c9: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12cf:
	/* 0x12cf: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_12d5:
	/* 0x12d5: mov    BYTE PTR [rax+0x1e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_12d8:
	/* 0x12d8: cmp    rsi,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 27ULL);
x86_l_12dc:
	/* 0x12dc: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_12e2:
	/* 0x12e2: lea    ecx,[rsi+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_12e8:
	/* 0x12e8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12ee:
	/* 0x12ee: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_12f4:
	/* 0x12f4: mov    BYTE PTR [rax+0x1f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_12f7:
	/* 0x12f7: cmp    rsi,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 28ULL);
x86_l_12fb:
	/* 0x12fb: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1301:
	/* 0x1301: lea    ecx,[rsi+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_1307:
	/* 0x1307: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_130d:
	/* 0x130d: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1313:
	/* 0x1313: mov    BYTE PTR [rax+0x20],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1316:
	/* 0x1316: cmp    rsi,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 29ULL);
x86_l_131a:
	/* 0x131a: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1320:
	/* 0x1320: lea    ecx,[rsi+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_1326:
	/* 0x1326: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_132c:
	/* 0x132c: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1332:
	/* 0x1332: mov    BYTE PTR [rax+0x21],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_1335:
	/* 0x1335: cmp    rsi,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 30ULL);
x86_l_1339:
	/* 0x1339: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_133f:
	/* 0x133f: lea    ecx,[rsi+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_1345:
	/* 0x1345: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_134b:
	/* 0x134b: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1351:
	/* 0x1351: mov    BYTE PTR [rax+0x22],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_1354:
	/* 0x1354: cmp    rsi,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 31ULL);
x86_l_1358:
	/* 0x1358: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_135e:
	/* 0x135e: lea    ecx,[rsi+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_1364:
	/* 0x1364: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_136a:
	/* 0x136a: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1370:
	/* 0x1370: mov    BYTE PTR [rax+0x23],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_1373:
	/* 0x1373: cmp    rsi,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 32ULL);
x86_l_1377:
	/* 0x1377: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_137d:
	/* 0x137d: lea    ecx,[rsi+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_1383:
	/* 0x1383: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1389:
	/* 0x1389: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_138f:
	/* 0x138f: mov    BYTE PTR [rax+0x24],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1392:
	/* 0x1392: cmp    rsi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 33ULL);
x86_l_1396:
	/* 0x1396: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_139c:
	/* 0x139c: lea    ecx,[rsi+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_13a2:
	/* 0x13a2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13a8:
	/* 0x13a8: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_13ae:
	/* 0x13ae: mov    BYTE PTR [rax+0x25],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_13b1:
	/* 0x13b1: cmp    rsi,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 34ULL);
x86_l_13b5:
	/* 0x13b5: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_13bb:
	/* 0x13bb: lea    ecx,[rsi+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_13c1:
	/* 0x13c1: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13c7:
	/* 0x13c7: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_13cd:
	/* 0x13cd: mov    BYTE PTR [rax+0x26],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_13d0:
	/* 0x13d0: cmp    rsi,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 35ULL);
x86_l_13d4:
	/* 0x13d4: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_13da:
	/* 0x13da: lea    ecx,[rsi+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_13e0:
	/* 0x13e0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13e6:
	/* 0x13e6: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_13ec:
	/* 0x13ec: mov    BYTE PTR [rax+0x27],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_13ef:
	/* 0x13ef: cmp    rsi,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 36ULL);
x86_l_13f3:
	/* 0x13f3: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_13f9:
	/* 0x13f9: lea    ecx,[rsi+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_13ff:
	/* 0x13ff: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1405:
	/* 0x1405: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_140b:
	/* 0x140b: mov    BYTE PTR [rax+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_140e:
	/* 0x140e: cmp    rsi,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 37ULL);
x86_l_1412:
	/* 0x1412: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1418:
	/* 0x1418: lea    ecx,[rsi+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_141e:
	/* 0x141e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1424:
	/* 0x1424: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_142a:
	/* 0x142a: mov    BYTE PTR [rax+0x29],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_142d:
	/* 0x142d: cmp    rsi,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 38ULL);
x86_l_1431:
	/* 0x1431: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1437:
	/* 0x1437: lea    ecx,[rsi+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_143d:
	/* 0x143d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1443:
	/* 0x1443: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1449:
	/* 0x1449: mov    BYTE PTR [rax+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_144c:
	/* 0x144c: cmp    rsi,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 39ULL);
x86_l_1450:
	/* 0x1450: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1456:
	/* 0x1456: lea    ecx,[rsi+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_145c:
	/* 0x145c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1462:
	/* 0x1462: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1468:
	/* 0x1468: mov    BYTE PTR [rax+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_146b:
	/* 0x146b: cmp    rsi,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 40ULL);
x86_l_146f:
	/* 0x146f: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1475:
	/* 0x1475: lea    ecx,[rsi+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_147b:
	/* 0x147b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1481:
	/* 0x1481: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1487:
	/* 0x1487: mov    BYTE PTR [rax+0x2c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_148a:
	/* 0x148a: cmp    rsi,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 41ULL);
x86_l_148e:
	/* 0x148e: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1494:
	/* 0x1494: lea    ecx,[rsi+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_149a:
	/* 0x149a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14a0:
	/* 0x14a0: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_14a6:
	/* 0x14a6: mov    BYTE PTR [rax+0x2d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_14a9:
	/* 0x14a9: cmp    rsi,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 42ULL);
x86_l_14ad:
	/* 0x14ad: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_14b3:
	/* 0x14b3: lea    ecx,[rsi+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_14b9:
	/* 0x14b9: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14bf:
	/* 0x14bf: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_14c5:
	/* 0x14c5: mov    BYTE PTR [rax+0x2e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_14c8:
	/* 0x14c8: cmp    rsi,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 43ULL);
x86_l_14cc:
	/* 0x14cc: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_14d2:
	/* 0x14d2: lea    ecx,[rsi+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_14d8:
	/* 0x14d8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14de:
	/* 0x14de: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_14e4:
	/* 0x14e4: mov    BYTE PTR [rax+0x2f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_14e7:
	/* 0x14e7: cmp    rsi,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 44ULL);
x86_l_14eb:
	/* 0x14eb: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_14f1:
	/* 0x14f1: lea    ecx,[rsi+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_14f7:
	/* 0x14f7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14fd:
	/* 0x14fd: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1503:
	/* 0x1503: mov    BYTE PTR [rax+0x30],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1506:
	/* 0x1506: cmp    rsi,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 45ULL);
x86_l_150a:
	/* 0x150a: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_1510:
	/* 0x1510: lea    ecx,[rsi+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_1516:
	/* 0x1516: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_151c:
	/* 0x151c: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1522:
	/* 0x1522: mov    BYTE PTR [rax+0x31],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_1525:
	/* 0x1525: cmp    rsi,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 46ULL);
x86_l_1529:
	/* 0x1529: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_152f:
	/* 0x152f: lea    ecx,[rsi+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_1535:
	/* 0x1535: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_153b:
	/* 0x153b: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1541:
	/* 0x1541: mov    BYTE PTR [rax+0x32],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_1544:
	/* 0x1544: cmp    rsi,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 47ULL);
x86_l_1548:
	/* 0x1548: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_154e:
	/* 0x154e: lea    ecx,[rsi+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_1554:
	/* 0x1554: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_155a:
	/* 0x155a: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1560:
	/* 0x1560: mov    BYTE PTR [rax+0x33],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_1563:
	/* 0x1563: cmp    rsi,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 48ULL);
x86_l_1567:
	/* 0x1567: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_156d:
	/* 0x156d: lea    ecx,[rsi+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_1573:
	/* 0x1573: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1579:
	/* 0x1579: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_157f:
	/* 0x157f: mov    BYTE PTR [rax+0x34],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1582:
	/* 0x1582: cmp    rsi,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 49ULL);
x86_l_1586:
	/* 0x1586: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_158c:
	/* 0x158c: lea    ecx,[rsi+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_1592:
	/* 0x1592: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1598:
	/* 0x1598: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_159e:
	/* 0x159e: mov    BYTE PTR [rax+0x35],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_15a1:
	/* 0x15a1: cmp    rsi,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 50ULL);
x86_l_15a5:
	/* 0x15a5: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_15ab:
	/* 0x15ab: lea    ecx,[rsi+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_15b1:
	/* 0x15b1: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15b7:
	/* 0x15b7: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_15bd:
	/* 0x15bd: mov    BYTE PTR [rax+0x36],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_15c0:
	/* 0x15c0: cmp    rsi,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 51ULL);
x86_l_15c4:
	/* 0x15c4: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
x86_l_15ca:
	/* 0x15ca: lea    ecx,[rsi+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_15d0:
	/* 0x15d0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15d6:
	/* 0x15d6: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_15dc:
	/* 0x15dc: mov    BYTE PTR [rax+0x37],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_15df:
	/* 0x15df: cmp    rsi,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 52ULL);
x86_l_15e3:
	/* 0x15e3: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6885ULL;
	}
	return 5609ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5609ULL: goto x86_l_15e9;
	case 5615ULL: goto x86_l_15ef;
	case 5621ULL: goto x86_l_15f5;
	case 5627ULL: goto x86_l_15fb;
	case 5630ULL: goto x86_l_15fe;
	case 5634ULL: goto x86_l_1602;
	case 5640ULL: goto x86_l_1608;
	case 5646ULL: goto x86_l_160e;
	case 5652ULL: goto x86_l_1614;
	case 5658ULL: goto x86_l_161a;
	case 5661ULL: goto x86_l_161d;
	case 5665ULL: goto x86_l_1621;
	case 5671ULL: goto x86_l_1627;
	case 5677ULL: goto x86_l_162d;
	case 5683ULL: goto x86_l_1633;
	case 5689ULL: goto x86_l_1639;
	case 5692ULL: goto x86_l_163c;
	case 5696ULL: goto x86_l_1640;
	case 5702ULL: goto x86_l_1646;
	case 5708ULL: goto x86_l_164c;
	case 5714ULL: goto x86_l_1652;
	case 5720ULL: goto x86_l_1658;
	case 5723ULL: goto x86_l_165b;
	case 5727ULL: goto x86_l_165f;
	case 5733ULL: goto x86_l_1665;
	case 5739ULL: goto x86_l_166b;
	case 5745ULL: goto x86_l_1671;
	case 5751ULL: goto x86_l_1677;
	case 5754ULL: goto x86_l_167a;
	case 5758ULL: goto x86_l_167e;
	case 5764ULL: goto x86_l_1684;
	case 5770ULL: goto x86_l_168a;
	case 5776ULL: goto x86_l_1690;
	case 5782ULL: goto x86_l_1696;
	case 5785ULL: goto x86_l_1699;
	case 5789ULL: goto x86_l_169d;
	case 5795ULL: goto x86_l_16a3;
	case 5801ULL: goto x86_l_16a9;
	case 5807ULL: goto x86_l_16af;
	case 5813ULL: goto x86_l_16b5;
	case 5816ULL: goto x86_l_16b8;
	case 5820ULL: goto x86_l_16bc;
	case 5826ULL: goto x86_l_16c2;
	case 5832ULL: goto x86_l_16c8;
	case 5838ULL: goto x86_l_16ce;
	case 5844ULL: goto x86_l_16d4;
	case 5847ULL: goto x86_l_16d7;
	case 5851ULL: goto x86_l_16db;
	case 5857ULL: goto x86_l_16e1;
	case 5863ULL: goto x86_l_16e7;
	case 5869ULL: goto x86_l_16ed;
	case 5875ULL: goto x86_l_16f3;
	case 5878ULL: goto x86_l_16f6;
	case 5882ULL: goto x86_l_16fa;
	case 5888ULL: goto x86_l_1700;
	case 5894ULL: goto x86_l_1706;
	case 5900ULL: goto x86_l_170c;
	case 5906ULL: goto x86_l_1712;
	case 5909ULL: goto x86_l_1715;
	case 5913ULL: goto x86_l_1719;
	case 5919ULL: goto x86_l_171f;
	case 5925ULL: goto x86_l_1725;
	case 5931ULL: goto x86_l_172b;
	case 5937ULL: goto x86_l_1731;
	case 5940ULL: goto x86_l_1734;
	case 5944ULL: goto x86_l_1738;
	case 5950ULL: goto x86_l_173e;
	case 5956ULL: goto x86_l_1744;
	case 5962ULL: goto x86_l_174a;
	case 5968ULL: goto x86_l_1750;
	case 5971ULL: goto x86_l_1753;
	case 5975ULL: goto x86_l_1757;
	case 5981ULL: goto x86_l_175d;
	case 5987ULL: goto x86_l_1763;
	case 5993ULL: goto x86_l_1769;
	case 5999ULL: goto x86_l_176f;
	case 6002ULL: goto x86_l_1772;
	case 6006ULL: goto x86_l_1776;
	case 6012ULL: goto x86_l_177c;
	case 6018ULL: goto x86_l_1782;
	case 6024ULL: goto x86_l_1788;
	case 6030ULL: goto x86_l_178e;
	case 6033ULL: goto x86_l_1791;
	case 6037ULL: goto x86_l_1795;
	case 6043ULL: goto x86_l_179b;
	case 6049ULL: goto x86_l_17a1;
	case 6055ULL: goto x86_l_17a7;
	case 6061ULL: goto x86_l_17ad;
	case 6064ULL: goto x86_l_17b0;
	case 6068ULL: goto x86_l_17b4;
	case 6074ULL: goto x86_l_17ba;
	case 6080ULL: goto x86_l_17c0;
	case 6086ULL: goto x86_l_17c6;
	case 6092ULL: goto x86_l_17cc;
	case 6095ULL: goto x86_l_17cf;
	case 6099ULL: goto x86_l_17d3;
	case 6105ULL: goto x86_l_17d9;
	case 6111ULL: goto x86_l_17df;
	case 6117ULL: goto x86_l_17e5;
	case 6123ULL: goto x86_l_17eb;
	case 6126ULL: goto x86_l_17ee;
	case 6130ULL: goto x86_l_17f2;
	case 6136ULL: goto x86_l_17f8;
	case 6142ULL: goto x86_l_17fe;
	case 6148ULL: goto x86_l_1804;
	case 6154ULL: goto x86_l_180a;
	case 6157ULL: goto x86_l_180d;
	case 6161ULL: goto x86_l_1811;
	case 6167ULL: goto x86_l_1817;
	case 6173ULL: goto x86_l_181d;
	case 6179ULL: goto x86_l_1823;
	case 6185ULL: goto x86_l_1829;
	case 6188ULL: goto x86_l_182c;
	case 6192ULL: goto x86_l_1830;
	case 6198ULL: goto x86_l_1836;
	case 6204ULL: goto x86_l_183c;
	case 6210ULL: goto x86_l_1842;
	case 6216ULL: goto x86_l_1848;
	case 6219ULL: goto x86_l_184b;
	case 6223ULL: goto x86_l_184f;
	case 6229ULL: goto x86_l_1855;
	case 6235ULL: goto x86_l_185b;
	case 6241ULL: goto x86_l_1861;
	case 6247ULL: goto x86_l_1867;
	case 6250ULL: goto x86_l_186a;
	case 6254ULL: goto x86_l_186e;
	case 6260ULL: goto x86_l_1874;
	case 6266ULL: goto x86_l_187a;
	case 6272ULL: goto x86_l_1880;
	case 6278ULL: goto x86_l_1886;
	case 6281ULL: goto x86_l_1889;
	case 6285ULL: goto x86_l_188d;
	case 6291ULL: goto x86_l_1893;
	case 6297ULL: goto x86_l_1899;
	case 6303ULL: goto x86_l_189f;
	case 6309ULL: goto x86_l_18a5;
	case 6312ULL: goto x86_l_18a8;
	case 6316ULL: goto x86_l_18ac;
	case 6322ULL: goto x86_l_18b2;
	case 6328ULL: goto x86_l_18b8;
	case 6334ULL: goto x86_l_18be;
	case 6340ULL: goto x86_l_18c4;
	case 6343ULL: goto x86_l_18c7;
	case 6347ULL: goto x86_l_18cb;
	case 6353ULL: goto x86_l_18d1;
	case 6359ULL: goto x86_l_18d7;
	case 6365ULL: goto x86_l_18dd;
	case 6371ULL: goto x86_l_18e3;
	case 6374ULL: goto x86_l_18e6;
	case 6378ULL: goto x86_l_18ea;
	case 6384ULL: goto x86_l_18f0;
	case 6390ULL: goto x86_l_18f6;
	case 6396ULL: goto x86_l_18fc;
	case 6402ULL: goto x86_l_1902;
	case 6405ULL: goto x86_l_1905;
	case 6409ULL: goto x86_l_1909;
	case 6415ULL: goto x86_l_190f;
	case 6421ULL: goto x86_l_1915;
	case 6427ULL: goto x86_l_191b;
	case 6433ULL: goto x86_l_1921;
	case 6436ULL: goto x86_l_1924;
	case 6440ULL: goto x86_l_1928;
	case 6446ULL: goto x86_l_192e;
	case 6452ULL: goto x86_l_1934;
	case 6458ULL: goto x86_l_193a;
	case 6464ULL: goto x86_l_1940;
	case 6467ULL: goto x86_l_1943;
	case 6471ULL: goto x86_l_1947;
	case 6477ULL: goto x86_l_194d;
	case 6483ULL: goto x86_l_1953;
	case 6489ULL: goto x86_l_1959;
	case 6495ULL: goto x86_l_195f;
	case 6498ULL: goto x86_l_1962;
	case 6502ULL: goto x86_l_1966;
	case 6508ULL: goto x86_l_196c;
	case 6514ULL: goto x86_l_1972;
	case 6520ULL: goto x86_l_1978;
	case 6526ULL: goto x86_l_197e;
	case 6529ULL: goto x86_l_1981;
	case 6533ULL: goto x86_l_1985;
	case 6539ULL: goto x86_l_198b;
	case 6545ULL: goto x86_l_1991;
	case 6551ULL: goto x86_l_1997;
	case 6557ULL: goto x86_l_199d;
	case 6560ULL: goto x86_l_19a0;
	case 6564ULL: goto x86_l_19a4;
	case 6570ULL: goto x86_l_19aa;
	case 6576ULL: goto x86_l_19b0;
	case 6582ULL: goto x86_l_19b6;
	case 6588ULL: goto x86_l_19bc;
	case 6591ULL: goto x86_l_19bf;
	case 6595ULL: goto x86_l_19c3;
	case 6601ULL: goto x86_l_19c9;
	case 6607ULL: goto x86_l_19cf;
	case 6613ULL: goto x86_l_19d5;
	case 6619ULL: goto x86_l_19db;
	case 6622ULL: goto x86_l_19de;
	case 6626ULL: goto x86_l_19e2;
	case 6632ULL: goto x86_l_19e8;
	case 6638ULL: goto x86_l_19ee;
	case 6644ULL: goto x86_l_19f4;
	case 6650ULL: goto x86_l_19fa;
	case 6653ULL: goto x86_l_19fd;
	case 6657ULL: goto x86_l_1a01;
	case 6663ULL: goto x86_l_1a07;
	case 6669ULL: goto x86_l_1a0d;
	case 6675ULL: goto x86_l_1a13;
	case 6681ULL: goto x86_l_1a19;
	case 6684ULL: goto x86_l_1a1c;
	case 6688ULL: goto x86_l_1a20;
	case 6694ULL: goto x86_l_1a26;
	case 6700ULL: goto x86_l_1a2c;
	case 6706ULL: goto x86_l_1a32;
	case 6712ULL: goto x86_l_1a38;
	case 6715ULL: goto x86_l_1a3b;
	case 6719ULL: goto x86_l_1a3f;
	case 6725ULL: goto x86_l_1a45;
	case 6731ULL: goto x86_l_1a4b;
	case 6737ULL: goto x86_l_1a51;
	case 6743ULL: goto x86_l_1a57;
	case 6746ULL: goto x86_l_1a5a;
	case 6750ULL: goto x86_l_1a5e;
	case 6756ULL: goto x86_l_1a64;
	case 6762ULL: goto x86_l_1a6a;
	case 6768ULL: goto x86_l_1a70;
	case 6774ULL: goto x86_l_1a76;
	case 6777ULL: goto x86_l_1a79;
	case 6781ULL: goto x86_l_1a7d;
	case 6783ULL: goto x86_l_1a7f;
	case 6789ULL: goto x86_l_1a85;
	case 6795ULL: goto x86_l_1a8b;
	case 6801ULL: goto x86_l_1a91;
	case 6804ULL: goto x86_l_1a94;
	case 6808ULL: goto x86_l_1a98;
	case 6810ULL: goto x86_l_1a9a;
	case 6816ULL: goto x86_l_1aa0;
	case 6822ULL: goto x86_l_1aa6;
	case 6828ULL: goto x86_l_1aac;
	case 6831ULL: goto x86_l_1aaf;
	case 6835ULL: goto x86_l_1ab3;
	case 6837ULL: goto x86_l_1ab5;
	case 6843ULL: goto x86_l_1abb;
	case 6849ULL: goto x86_l_1ac1;
	case 6855ULL: goto x86_l_1ac7;
	case 6858ULL: goto x86_l_1aca;
	case 6862ULL: goto x86_l_1ace;
	case 6864ULL: goto x86_l_1ad0;
	case 6870ULL: goto x86_l_1ad6;
	case 6876ULL: goto x86_l_1adc;
	case 6882ULL: goto x86_l_1ae2;
	case 6885ULL: goto x86_l_1ae5;
	case 6890ULL: goto x86_l_1aea;
	case 6895ULL: goto x86_l_1aef;
	case 6898ULL: goto x86_l_1af2;
	case 6903ULL: goto x86_l_1af7;
	case 6908ULL: goto x86_l_1afc;
	case 6912ULL: goto x86_l_1b00;
	case 6915ULL: goto x86_l_1b03;
	case 6919ULL: goto x86_l_1b07;
	case 6927ULL: goto x86_l_1b0f;
	case 6932ULL: goto x86_l_1b14;
	case 6939ULL: goto x86_l_1b1b;
	case 6944ULL: goto x86_l_1b20;
	case 6946ULL: goto x86_l_1b22;
	case 6949ULL: goto x86_l_1b25;
	case 6952ULL: goto x86_l_1b28;
	case 6955ULL: goto x86_l_1b2b;
	case 6961ULL: goto x86_l_1b31;
	case 6964ULL: goto x86_l_1b34;
	case 6970ULL: goto x86_l_1b3a;
	case 6975ULL: goto x86_l_1b3f;
	case 6980ULL: goto x86_l_1b44;
	case 6987ULL: goto x86_l_1b4b;
	case 6992ULL: goto x86_l_1b50;
	case 6994ULL: goto x86_l_1b52;
	case 6997ULL: goto x86_l_1b55;
	case 7003ULL: goto x86_l_1b5b;
	case 7010ULL: goto x86_l_1b62;
	case 7015ULL: goto x86_l_1b67;
	case 7019ULL: goto x86_l_1b6b;
	case 7026ULL: goto x86_l_1b72;
	case 7028ULL: goto x86_l_1b74;
	case 7031ULL: goto x86_l_1b77;
	case 7035ULL: goto x86_l_1b7b;
	case 7040ULL: goto x86_l_1b80;
	case 7045ULL: goto x86_l_1b85;
	case 7048ULL: goto x86_l_1b88;
	case 7050ULL: goto x86_l_1b8a;
	case 7055ULL: goto x86_l_1b8f;
	case 7060ULL: goto x86_l_1b94;
	case 7063ULL: goto x86_l_1b97;
	case 7065ULL: goto x86_l_1b99;
	case 7070ULL: goto x86_l_1b9e;
	case 7078ULL: goto x86_l_1ba6;
	case 7085ULL: goto x86_l_1bad;
	case 7091ULL: goto x86_l_1bb3;
	case 7095ULL: goto x86_l_1bb7;
	case 7101ULL: goto x86_l_1bbd;
	case 7104ULL: goto x86_l_1bc0;
	case 7107ULL: goto x86_l_1bc3;
	case 7110ULL: goto x86_l_1bc6;
	case 7113ULL: goto x86_l_1bc9;
	case 7115ULL: goto x86_l_1bcb;
	case 7119ULL: goto x86_l_1bcf;
	case 7125ULL: goto x86_l_1bd5;
	case 7127ULL: goto x86_l_1bd7;
	case 7133ULL: goto x86_l_1bdd;
	case 7136ULL: goto x86_l_1be0;
	case 7141ULL: goto x86_l_1be5;
	case 7144ULL: goto x86_l_1be8;
	case 7149ULL: goto x86_l_1bed;
	case 7153ULL: goto x86_l_1bf1;
	case 7158ULL: goto x86_l_1bf6;
	case 7162ULL: goto x86_l_1bfa;
	case 7167ULL: goto x86_l_1bff;
	case 7171ULL: goto x86_l_1c03;
	case 7176ULL: goto x86_l_1c08;
	case 7181ULL: goto x86_l_1c0d;
	case 7183ULL: goto x86_l_1c0f;
	case 7186ULL: goto x86_l_1c12;
	case 7189ULL: goto x86_l_1c15;
	case 7192ULL: goto x86_l_1c18;
	case 7194ULL: goto x86_l_1c1a;
	case 7197ULL: goto x86_l_1c1d;
	case 7199ULL: goto x86_l_1c1f;
	case 7202ULL: goto x86_l_1c22;
	case 7205ULL: goto x86_l_1c25;
	case 7211ULL: goto x86_l_1c2b;
	case 7214ULL: goto x86_l_1c2e;
	case 7217ULL: goto x86_l_1c31;
	case 7223ULL: goto x86_l_1c37;
	case 7228ULL: goto x86_l_1c3c;
	case 7231ULL: goto x86_l_1c3f;
	case 7233ULL: goto x86_l_1c41;
	case 7236ULL: goto x86_l_1c44;
	case 7242ULL: goto x86_l_1c4a;
	case 7245ULL: goto x86_l_1c4d;
	case 7251ULL: goto x86_l_1c53;
	case 7254ULL: goto x86_l_1c56;
	case 7260ULL: goto x86_l_1c5c;
	case 7265ULL: goto x86_l_1c61;
	case 7270ULL: goto x86_l_1c66;
	case 7273ULL: goto x86_l_1c69;
	case 7279ULL: goto x86_l_1c6f;
	case 7282ULL: goto x86_l_1c72;
	case 7288ULL: goto x86_l_1c78;
	case 7291ULL: goto x86_l_1c7b;
	case 7297ULL: goto x86_l_1c81;
	case 7302ULL: goto x86_l_1c86;
	case 7305ULL: goto x86_l_1c89;
	case 7308ULL: goto x86_l_1c8c;
	case 7314ULL: goto x86_l_1c92;
	case 7322ULL: goto x86_l_1c9a;
	case 7329ULL: goto x86_l_1ca1;
	case 7335ULL: goto x86_l_1ca7;
	case 7338ULL: goto x86_l_1caa;
	case 7343ULL: goto x86_l_1caf;
	case 7346ULL: goto x86_l_1cb2;
	case 7352ULL: goto x86_l_1cb8;
	case 7355ULL: goto x86_l_1cbb;
	case 7361ULL: goto x86_l_1cc1;
	case 7364ULL: goto x86_l_1cc4;
	case 7370ULL: goto x86_l_1cca;
	case 7375ULL: goto x86_l_1ccf;
	case 7380ULL: goto x86_l_1cd4;
	case 7384ULL: goto x86_l_1cd8;
	case 7387ULL: goto x86_l_1cdb;
	case 7391ULL: goto x86_l_1cdf;
	case 7399ULL: goto x86_l_1ce7;
	case 7404ULL: goto x86_l_1cec;
	case 7411ULL: goto x86_l_1cf3;
	case 7416ULL: goto x86_l_1cf8;
	case 7418ULL: goto x86_l_1cfa;
	case 7421ULL: goto x86_l_1cfd;
	case 7424ULL: goto x86_l_1d00;
	case 7427ULL: goto x86_l_1d03;
	case 7433ULL: goto x86_l_1d09;
	case 7438ULL: goto x86_l_1d0e;
	case 7441ULL: goto x86_l_1d11;
	case 7447ULL: goto x86_l_1d17;
	case 7452ULL: goto x86_l_1d1c;
	case 7459ULL: goto x86_l_1d23;
	case 7464ULL: goto x86_l_1d28;
	case 7466ULL: goto x86_l_1d2a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_15e9:
	/* 0x15e9: lea    ecx,[rsi+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_15ef:
	/* 0x15ef: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15f5:
	/* 0x15f5: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_15fb:
	/* 0x15fb: mov    BYTE PTR [rax+0x38],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15fe:
	/* 0x15fe: cmp    rsi,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 53ULL);
x86_l_1602:
	/* 0x1602: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_1608:
	/* 0x1608: lea    ecx,[rsi+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_160e:
	/* 0x160e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1614:
	/* 0x1614: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_161a:
	/* 0x161a: mov    BYTE PTR [rax+0x39],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_161d:
	/* 0x161d: cmp    rsi,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 54ULL);
x86_l_1621:
	/* 0x1621: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_1627:
	/* 0x1627: lea    ecx,[rsi+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_162d:
	/* 0x162d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1633:
	/* 0x1633: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1639:
	/* 0x1639: mov    BYTE PTR [rax+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_163c:
	/* 0x163c: cmp    rsi,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 55ULL);
x86_l_1640:
	/* 0x1640: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_1646:
	/* 0x1646: lea    ecx,[rsi+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_164c:
	/* 0x164c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1652:
	/* 0x1652: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1658:
	/* 0x1658: mov    BYTE PTR [rax+0x3b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_165b:
	/* 0x165b: cmp    rsi,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 56ULL);
x86_l_165f:
	/* 0x165f: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_1665:
	/* 0x1665: lea    ecx,[rsi+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_166b:
	/* 0x166b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1671:
	/* 0x1671: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1677:
	/* 0x1677: mov    BYTE PTR [rax+0x3c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_167a:
	/* 0x167a: cmp    rsi,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 57ULL);
x86_l_167e:
	/* 0x167e: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_1684:
	/* 0x1684: lea    ecx,[rsi+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_168a:
	/* 0x168a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1690:
	/* 0x1690: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1696:
	/* 0x1696: mov    BYTE PTR [rax+0x3d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_1699:
	/* 0x1699: cmp    rsi,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 58ULL);
x86_l_169d:
	/* 0x169d: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_16a3:
	/* 0x16a3: lea    ecx,[rsi+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_16a9:
	/* 0x16a9: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16af:
	/* 0x16af: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_16b5:
	/* 0x16b5: mov    BYTE PTR [rax+0x3e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_16b8:
	/* 0x16b8: cmp    rsi,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 59ULL);
x86_l_16bc:
	/* 0x16bc: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_16c2:
	/* 0x16c2: lea    ecx,[rsi+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_16c8:
	/* 0x16c8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16ce:
	/* 0x16ce: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_16d4:
	/* 0x16d4: mov    BYTE PTR [rax+0x3f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_16d7:
	/* 0x16d7: cmp    rsi,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 60ULL);
x86_l_16db:
	/* 0x16db: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_16e1:
	/* 0x16e1: lea    ecx,[rsi+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_16e7:
	/* 0x16e7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16ed:
	/* 0x16ed: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_16f3:
	/* 0x16f3: mov    BYTE PTR [rax+0x40],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16f6:
	/* 0x16f6: cmp    rsi,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 61ULL);
x86_l_16fa:
	/* 0x16fa: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_1700:
	/* 0x1700: lea    ecx,[rsi+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_1706:
	/* 0x1706: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_170c:
	/* 0x170c: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1712:
	/* 0x1712: mov    BYTE PTR [rax+0x41],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_1715:
	/* 0x1715: cmp    rsi,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 62ULL);
x86_l_1719:
	/* 0x1719: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_171f:
	/* 0x171f: lea    ecx,[rsi+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_1725:
	/* 0x1725: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_172b:
	/* 0x172b: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1731:
	/* 0x1731: mov    BYTE PTR [rax+0x42],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_1734:
	/* 0x1734: cmp    rsi,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 63ULL);
x86_l_1738:
	/* 0x1738: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_173e:
	/* 0x173e: lea    ecx,[rsi+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_1744:
	/* 0x1744: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_174a:
	/* 0x174a: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1750:
	/* 0x1750: mov    BYTE PTR [rax+0x43],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_1753:
	/* 0x1753: cmp    rsi,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 64ULL);
x86_l_1757:
	/* 0x1757: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_175d:
	/* 0x175d: lea    ecx,[rsi+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_1763:
	/* 0x1763: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1769:
	/* 0x1769: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_176f:
	/* 0x176f: mov    BYTE PTR [rax+0x44],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1772:
	/* 0x1772: cmp    rsi,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 65ULL);
x86_l_1776:
	/* 0x1776: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_177c:
	/* 0x177c: lea    ecx,[rsi+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_1782:
	/* 0x1782: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1788:
	/* 0x1788: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_178e:
	/* 0x178e: mov    BYTE PTR [rax+0x45],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_1791:
	/* 0x1791: cmp    rsi,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 66ULL);
x86_l_1795:
	/* 0x1795: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_179b:
	/* 0x179b: lea    ecx,[rsi+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_17a1:
	/* 0x17a1: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17a7:
	/* 0x17a7: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_17ad:
	/* 0x17ad: mov    BYTE PTR [rax+0x46],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_17b0:
	/* 0x17b0: cmp    rsi,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 67ULL);
x86_l_17b4:
	/* 0x17b4: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_17ba:
	/* 0x17ba: lea    ecx,[rsi+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_17c0:
	/* 0x17c0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17c6:
	/* 0x17c6: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_17cc:
	/* 0x17cc: mov    BYTE PTR [rax+0x47],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_17cf:
	/* 0x17cf: cmp    rsi,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 68ULL);
x86_l_17d3:
	/* 0x17d3: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_17d9:
	/* 0x17d9: lea    ecx,[rsi+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_17df:
	/* 0x17df: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17e5:
	/* 0x17e5: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_17eb:
	/* 0x17eb: mov    BYTE PTR [rax+0x48],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17ee:
	/* 0x17ee: cmp    rsi,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 69ULL);
x86_l_17f2:
	/* 0x17f2: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_17f8:
	/* 0x17f8: lea    ecx,[rsi+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_17fe:
	/* 0x17fe: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1804:
	/* 0x1804: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_180a:
	/* 0x180a: mov    BYTE PTR [rax+0x49],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_180d:
	/* 0x180d: cmp    rsi,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 70ULL);
x86_l_1811:
	/* 0x1811: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_1817:
	/* 0x1817: lea    ecx,[rsi+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_181d:
	/* 0x181d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1823:
	/* 0x1823: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1829:
	/* 0x1829: mov    BYTE PTR [rax+0x4a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_182c:
	/* 0x182c: cmp    rsi,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 71ULL);
x86_l_1830:
	/* 0x1830: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_1836:
	/* 0x1836: lea    ecx,[rsi+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_183c:
	/* 0x183c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1842:
	/* 0x1842: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1848:
	/* 0x1848: mov    BYTE PTR [rax+0x4b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_184b:
	/* 0x184b: cmp    rsi,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 72ULL);
x86_l_184f:
	/* 0x184f: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_1855:
	/* 0x1855: lea    ecx,[rsi+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_185b:
	/* 0x185b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1861:
	/* 0x1861: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1867:
	/* 0x1867: mov    BYTE PTR [rax+0x4c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_186a:
	/* 0x186a: cmp    rsi,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 73ULL);
x86_l_186e:
	/* 0x186e: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_1874:
	/* 0x1874: lea    ecx,[rsi+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_187a:
	/* 0x187a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1880:
	/* 0x1880: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1886:
	/* 0x1886: mov    BYTE PTR [rax+0x4d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_1889:
	/* 0x1889: cmp    rsi,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 74ULL);
x86_l_188d:
	/* 0x188d: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_1893:
	/* 0x1893: lea    ecx,[rsi+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_1899:
	/* 0x1899: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_189f:
	/* 0x189f: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_18a5:
	/* 0x18a5: mov    BYTE PTR [rax+0x4e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_18a8:
	/* 0x18a8: cmp    rsi,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 75ULL);
x86_l_18ac:
	/* 0x18ac: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_18b2:
	/* 0x18b2: lea    ecx,[rsi+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_18b8:
	/* 0x18b8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18be:
	/* 0x18be: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_18c4:
	/* 0x18c4: mov    BYTE PTR [rax+0x4f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_18c7:
	/* 0x18c7: cmp    rsi,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 76ULL);
x86_l_18cb:
	/* 0x18cb: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_18d1:
	/* 0x18d1: lea    ecx,[rsi+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_18d7:
	/* 0x18d7: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18dd:
	/* 0x18dd: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_18e3:
	/* 0x18e3: mov    BYTE PTR [rax+0x50],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_18e6:
	/* 0x18e6: cmp    rsi,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 77ULL);
x86_l_18ea:
	/* 0x18ea: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_18f0:
	/* 0x18f0: lea    ecx,[rsi+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_18f6:
	/* 0x18f6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18fc:
	/* 0x18fc: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1902:
	/* 0x1902: mov    BYTE PTR [rax+0x51],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_1905:
	/* 0x1905: cmp    rsi,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 78ULL);
x86_l_1909:
	/* 0x1909: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_190f:
	/* 0x190f: lea    ecx,[rsi+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_1915:
	/* 0x1915: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_191b:
	/* 0x191b: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1921:
	/* 0x1921: mov    BYTE PTR [rax+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_1924:
	/* 0x1924: cmp    rsi,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 79ULL);
x86_l_1928:
	/* 0x1928: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_192e:
	/* 0x192e: lea    ecx,[rsi+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_1934:
	/* 0x1934: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_193a:
	/* 0x193a: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1940:
	/* 0x1940: mov    BYTE PTR [rax+0x53],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_1943:
	/* 0x1943: cmp    rsi,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 80ULL);
x86_l_1947:
	/* 0x1947: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_194d:
	/* 0x194d: lea    ecx,[rsi+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_1953:
	/* 0x1953: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1959:
	/* 0x1959: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_195f:
	/* 0x195f: mov    BYTE PTR [rax+0x54],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_1962:
	/* 0x1962: cmp    rsi,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 81ULL);
x86_l_1966:
	/* 0x1966: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_196c:
	/* 0x196c: lea    ecx,[rsi+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_1972:
	/* 0x1972: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1978:
	/* 0x1978: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_197e:
	/* 0x197e: mov    BYTE PTR [rax+0x55],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_1981:
	/* 0x1981: cmp    rsi,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 82ULL);
x86_l_1985:
	/* 0x1985: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_198b:
	/* 0x198b: lea    ecx,[rsi+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_1991:
	/* 0x1991: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1997:
	/* 0x1997: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_199d:
	/* 0x199d: mov    BYTE PTR [rax+0x56],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_19a0:
	/* 0x19a0: cmp    rsi,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 83ULL);
x86_l_19a4:
	/* 0x19a4: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_19aa:
	/* 0x19aa: lea    ecx,[rsi+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_19b0:
	/* 0x19b0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19b6:
	/* 0x19b6: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_19bc:
	/* 0x19bc: mov    BYTE PTR [rax+0x57],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_19bf:
	/* 0x19bf: cmp    rsi,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 84ULL);
x86_l_19c3:
	/* 0x19c3: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_19c9:
	/* 0x19c9: lea    ecx,[rsi+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_19cf:
	/* 0x19cf: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19d5:
	/* 0x19d5: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_19db:
	/* 0x19db: mov    BYTE PTR [rax+0x58],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_19de:
	/* 0x19de: cmp    rsi,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 85ULL);
x86_l_19e2:
	/* 0x19e2: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_19e8:
	/* 0x19e8: lea    ecx,[rsi+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_19ee:
	/* 0x19ee: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19f4:
	/* 0x19f4: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_19fa:
	/* 0x19fa: mov    BYTE PTR [rax+0x59],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_19fd:
	/* 0x19fd: cmp    rsi,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 86ULL);
x86_l_1a01:
	/* 0x1a01: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_1a07:
	/* 0x1a07: lea    ecx,[rsi+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_1a0d:
	/* 0x1a0d: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a13:
	/* 0x1a13: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a19:
	/* 0x1a19: mov    BYTE PTR [rax+0x5a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_1a1c:
	/* 0x1a1c: cmp    rsi,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 87ULL);
x86_l_1a20:
	/* 0x1a20: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_1a26:
	/* 0x1a26: lea    ecx,[rsi+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_1a2c:
	/* 0x1a2c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a32:
	/* 0x1a32: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a38:
	/* 0x1a38: mov    BYTE PTR [rax+0x5b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_1a3b:
	/* 0x1a3b: cmp    rsi,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 88ULL);
x86_l_1a3f:
	/* 0x1a3f: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_1a45:
	/* 0x1a45: lea    ecx,[rsi+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_1a4b:
	/* 0x1a4b: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a51:
	/* 0x1a51: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a57:
	/* 0x1a57: mov    BYTE PTR [rax+0x5c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_1a5a:
	/* 0x1a5a: cmp    rsi,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 89ULL);
x86_l_1a5e:
	/* 0x1a5e: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_1a64:
	/* 0x1a64: lea    ecx,[rsi+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_1a6a:
	/* 0x1a6a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a70:
	/* 0x1a70: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a76:
	/* 0x1a76: mov    BYTE PTR [rax+0x5d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_1a79:
	/* 0x1a79: cmp    rsi,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 90ULL);
x86_l_1a7d:
	/* 0x1a7d: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_1a7f:
	/* 0x1a7f: lea    ecx,[rsi+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_1a85:
	/* 0x1a85: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a8b:
	/* 0x1a8b: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a91:
	/* 0x1a91: mov    BYTE PTR [rax+0x5e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_1a94:
	/* 0x1a94: cmp    rsi,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 91ULL);
x86_l_1a98:
	/* 0x1a98: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_1a9a:
	/* 0x1a9a: lea    ecx,[rsi+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_1aa0:
	/* 0x1aa0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1aa6:
	/* 0x1aa6: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1aac:
	/* 0x1aac: mov    BYTE PTR [rax+0x5f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_1aaf:
	/* 0x1aaf: cmp    rsi,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 92ULL);
x86_l_1ab3:
	/* 0x1ab3: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_1ab5:
	/* 0x1ab5: lea    ecx,[rsi+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_1abb:
	/* 0x1abb: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ac1:
	/* 0x1ac1: movzx  ecx,BYTE PTR [r13+rcx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ac7:
	/* 0x1ac7: mov    BYTE PTR [rax+0x60],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1aca:
	/* 0x1aca: cmp    rsi,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 93ULL);
x86_l_1ace:
	/* 0x1ace: je     1ae5 <generic_usdt_filter_arg_2+0x1ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae5;
	}
x86_l_1ad0:
	/* 0x1ad0: add    esi,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_1ad6:
	/* 0x1ad6: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1adc:
	/* 0x1adc: movzx  ecx,BYTE PTR [r13+rsi*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_1ae2:
	/* 0x1ae2: mov    BYTE PTR [rax+0x61],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_1ae5:
	/* 0x1ae5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1aea:
	/* 0x1aea: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1aef:
	/* 0x1aef: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1af2:
	/* 0x1af2: jmp    329d <generic_usdt_filter_arg_2+0x329d> */
	return 12957ULL;
x86_l_1af7:
	/* 0x1af7: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1afc:
	/* 0x1afc: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b00:
	/* 0x1b00: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b03:
	/* 0x1b03: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b07:
	/* 0x1b07: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1b0f:
	/* 0x1b0f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b14:
	/* 0x1b14: mov    rdi,QWORD PTR [rip+0xb1b3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1b1b:
	/* 0x1b1b: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b20:
	/* 0x1b20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b22:
	/* 0x1b22: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1b25:
	/* 0x1b25: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b28:
	/* 0x1b28: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1b2b:
	/* 0x1b2b: je     32ae <generic_usdt_filter_arg_2+0x32ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12974ULL;
	}
x86_l_1b31:
	/* 0x1b31: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b34:
	/* 0x1b34: je     32ae <generic_usdt_filter_arg_2+0x32ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12974ULL;
	}
x86_l_1b3a:
	/* 0x1b3a: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b3f:
	/* 0x1b3f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b44:
	/* 0x1b44: mov    rdi,QWORD PTR [rip+0xb1b3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_1b4b:
	/* 0x1b4b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b50:
	/* 0x1b50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b52:
	/* 0x1b52: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b55:
	/* 0x1b55: je     32ab <generic_usdt_filter_arg_2+0x32ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12971ULL;
	}
x86_l_1b5b:
	/* 0x1b5b: cmp    r13d,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 255ULL);
x86_l_1b62:
	/* 0x1b62: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_1b67:
	/* 0x1b67: cmovb  esi,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_1b6b:
	/* 0x1b6b: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_1b72:
	/* 0x1b72: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b74:
	/* 0x1b74: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1b77:
	/* 0x1b77: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1b7b:
	/* 0x1b7b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b80:
	/* 0x1b80: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b85:
	/* 0x1b85: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1b88:
	/* 0x1b88: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b8a:
	/* 0x1b8a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b8f:
	/* 0x1b8f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b94:
	/* 0x1b94: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1b97:
	/* 0x1b97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b99:
	/* 0x1b99: jmp    329f <generic_usdt_filter_arg_2+0x329f> */
	return 12959ULL;
x86_l_1b9e:
	/* 0x1b9e: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1ba6:
	/* 0x1ba6: cmp    r13d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 144ULL);
x86_l_1bad:
	/* 0x1bad: ja     2d7b <generic_usdt_filter_arg_2+0x2d7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11643ULL;
	}
x86_l_1bb3:
	/* 0x1bb3: movzx  eax,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1bb7:
	/* 0x1bb7: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1bbd:
	/* 0x1bbd: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1bc0:
	/* 0x1bc0: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1bc3:
	/* 0x1bc3: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1bc6:
	/* 0x1bc6: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_1bc9:
	/* 0x1bc9: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1bcb:
	/* 0x1bcb: test   r13w,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_16);
x86_l_1bcf:
	/* 0x1bcf: je     2c4f <generic_usdt_filter_arg_2+0x2c4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11343ULL;
	}
x86_l_1bd5:
	/* 0x1bd5: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1bd7:
	/* 0x1bd7: jne    2c4f <generic_usdt_filter_arg_2+0x2c4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11343ULL;
	}
x86_l_1bdd:
	/* 0x1bdd: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_1be0:
	/* 0x1be0: jmp    2c69 <generic_usdt_filter_arg_2+0x2c69> */
	return 11369ULL;
x86_l_1be5:
	/* 0x1be5: movzx  eax,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1be8:
	/* 0x1be8: mov    WORD PTR [rsp+0x76],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 118ULL);
x86_l_1bed:
	/* 0x1bed: movzx  eax,WORD PTR [rdi+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1bf1:
	/* 0x1bf1: mov    WORD PTR [rsp+0x70],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1bf6:
	/* 0x1bf6: mov    rax,QWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bfa:
	/* 0x1bfa: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1bff:
	/* 0x1bff: mov    rax,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c03:
	/* 0x1c03: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1c08:
	/* 0x1c08: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1c0d:
	/* 0x1c0d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c0f:
	/* 0x1c0f: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c12:
	/* 0x1c12: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c15:
	/* 0x1c15: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_1c18:
	/* 0x1c18: jle    1c3c <generic_usdt_filter_arg_2+0x1c3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1c3c;
	}
x86_l_1c1a:
	/* 0x1c1a: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_1c1d:
	/* 0x1c1d: jg     1c66 <generic_usdt_filter_arg_2+0x1c66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1c66;
	}
x86_l_1c1f:
	/* 0x1c1f: lea    ecx,[rax-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_1c22:
	/* 0x1c22: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1c25:
	/* 0x1c25: jb     2913 <generic_usdt_filter_arg_2+0x2913> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10515ULL;
	}
x86_l_1c2b:
	/* 0x1c2b: lea    ecx,[rax-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_1c2e:
	/* 0x1c2e: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1c31:
	/* 0x1c31: jb     290c <generic_usdt_filter_arg_2+0x290c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10508ULL;
	}
x86_l_1c37:
	/* 0x1c37: jmp    32d0 <generic_usdt_filter_arg_2+0x32d0> */
	return 13008ULL;
x86_l_1c3c:
	/* 0x1c3c: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1c3f:
	/* 0x1c3f: jle    1caf <generic_usdt_filter_arg_2+0x1caf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1caf;
	}
x86_l_1c41:
	/* 0x1c41: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1c44:
	/* 0x1c44: jg     28fe <generic_usdt_filter_arg_2+0x28fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10494ULL;
	}
x86_l_1c4a:
	/* 0x1c4a: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1c4d:
	/* 0x1c4d: je     290c <generic_usdt_filter_arg_2+0x290c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10508ULL;
	}
x86_l_1c53:
	/* 0x1c53: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1c56:
	/* 0x1c56: jne    32d0 <generic_usdt_filter_arg_2+0x32d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13008ULL;
	}
x86_l_1c5c:
	/* 0x1c5c: movzx  r15d,WORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1c61:
	/* 0x1c61: jmp    2d88 <generic_usdt_filter_arg_2+0x2d88> */
	return 11656ULL;
x86_l_1c66:
	/* 0x1c66: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1c69:
	/* 0x1c69: jg     2922 <generic_usdt_filter_arg_2+0x2922> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10530ULL;
	}
x86_l_1c6f:
	/* 0x1c6f: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_1c72:
	/* 0x1c72: je     2958 <generic_usdt_filter_arg_2+0x2958> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10584ULL;
	}
x86_l_1c78:
	/* 0x1c78: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1c7b:
	/* 0x1c7b: je     294e <generic_usdt_filter_arg_2+0x294e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10574ULL;
	}
x86_l_1c81:
	/* 0x1c81: jmp    32d0 <generic_usdt_filter_arg_2+0x32d0> */
	return 13008ULL;
x86_l_1c86:
	/* 0x1c86: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1c89:
	/* 0x1c89: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1c8c:
	/* 0x1c8c: jae    2c15 <generic_usdt_filter_arg_2+0x2c15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11285ULL;
	}
x86_l_1c92:
	/* 0x1c92: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1c9a:
	/* 0x1c9a: cmp    r13d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 144ULL);
x86_l_1ca1:
	/* 0x1ca1: jbe    2c1d <generic_usdt_filter_arg_2+0x2c1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11293ULL;
	}
x86_l_1ca7:
	/* 0x1ca7: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1caa:
	/* 0x1caa: jmp    3227 <generic_usdt_filter_arg_2+0x3227> */
	return 12839ULL;
x86_l_1caf:
	/* 0x1caf: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1cb2:
	/* 0x1cb2: je     2958 <generic_usdt_filter_arg_2+0x2958> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10584ULL;
	}
x86_l_1cb8:
	/* 0x1cb8: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1cbb:
	/* 0x1cbb: je     294e <generic_usdt_filter_arg_2+0x294e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10574ULL;
	}
x86_l_1cc1:
	/* 0x1cc1: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1cc4:
	/* 0x1cc4: je     2913 <generic_usdt_filter_arg_2+0x2913> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10515ULL;
	}
x86_l_1cca:
	/* 0x1cca: jmp    32d0 <generic_usdt_filter_arg_2+0x32d0> */
	return 13008ULL;
x86_l_1ccf:
	/* 0x1ccf: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cd4:
	/* 0x1cd4: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cd8:
	/* 0x1cd8: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cdb:
	/* 0x1cdb: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1cdf:
	/* 0x1cdf: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1ce7:
	/* 0x1ce7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cec:
	/* 0x1cec: mov    rdi,QWORD PTR [rip+0xb1b3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_1cf3:
	/* 0x1cf3: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1cf8:
	/* 0x1cf8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cfa:
	/* 0x1cfa: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1cfd:
	/* 0x1cfd: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d00:
	/* 0x1d00: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1d03:
	/* 0x1d03: je     3223 <generic_usdt_filter_arg_2+0x3223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12835ULL;
	}
x86_l_1d09:
	/* 0x1d09: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d0e:
	/* 0x1d0e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d11:
	/* 0x1d11: je     3223 <generic_usdt_filter_arg_2+0x3223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12835ULL;
	}
x86_l_1d17:
	/* 0x1d17: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d1c:
	/* 0x1d1c: mov    rdi,QWORD PTR [rip+0xb1b3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_1d23:
	/* 0x1d23: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d28:
	/* 0x1d28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d2a:
	/* 0x1d2a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 7469ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7469ULL: goto x86_l_1d2d;
	case 7475ULL: goto x86_l_1d33;
	case 7480ULL: goto x86_l_1d38;
	case 7484ULL: goto x86_l_1d3c;
	case 7488ULL: goto x86_l_1d40;
	case 7493ULL: goto x86_l_1d45;
	case 7497ULL: goto x86_l_1d49;
	case 7500ULL: goto x86_l_1d4c;
	case 7502ULL: goto x86_l_1d4e;
	case 7506ULL: goto x86_l_1d52;
	case 7512ULL: goto x86_l_1d58;
	case 7516ULL: goto x86_l_1d5c;
	case 7519ULL: goto x86_l_1d5f;
	case 7523ULL: goto x86_l_1d63;
	case 7529ULL: goto x86_l_1d69;
	case 7536ULL: goto x86_l_1d70;
	case 7542ULL: goto x86_l_1d76;
	case 7546ULL: goto x86_l_1d7a;
	case 7549ULL: goto x86_l_1d7d;
	case 7553ULL: goto x86_l_1d81;
	case 7559ULL: goto x86_l_1d87;
	case 7566ULL: goto x86_l_1d8e;
	case 7572ULL: goto x86_l_1d94;
	case 7576ULL: goto x86_l_1d98;
	case 7579ULL: goto x86_l_1d9b;
	case 7583ULL: goto x86_l_1d9f;
	case 7589ULL: goto x86_l_1da5;
	case 7596ULL: goto x86_l_1dac;
	case 7602ULL: goto x86_l_1db2;
	case 7606ULL: goto x86_l_1db6;
	case 7609ULL: goto x86_l_1db9;
	case 7613ULL: goto x86_l_1dbd;
	case 7619ULL: goto x86_l_1dc3;
	case 7626ULL: goto x86_l_1dca;
	case 7632ULL: goto x86_l_1dd0;
	case 7636ULL: goto x86_l_1dd4;
	case 7639ULL: goto x86_l_1dd7;
	case 7643ULL: goto x86_l_1ddb;
	case 7649ULL: goto x86_l_1de1;
	case 7656ULL: goto x86_l_1de8;
	case 7662ULL: goto x86_l_1dee;
	case 7666ULL: goto x86_l_1df2;
	case 7669ULL: goto x86_l_1df5;
	case 7673ULL: goto x86_l_1df9;
	case 7679ULL: goto x86_l_1dff;
	case 7686ULL: goto x86_l_1e06;
	case 7692ULL: goto x86_l_1e0c;
	case 7696ULL: goto x86_l_1e10;
	case 7699ULL: goto x86_l_1e13;
	case 7703ULL: goto x86_l_1e17;
	case 7709ULL: goto x86_l_1e1d;
	case 7716ULL: goto x86_l_1e24;
	case 7722ULL: goto x86_l_1e2a;
	case 7726ULL: goto x86_l_1e2e;
	case 7729ULL: goto x86_l_1e31;
	case 7733ULL: goto x86_l_1e35;
	case 7739ULL: goto x86_l_1e3b;
	case 7746ULL: goto x86_l_1e42;
	case 7752ULL: goto x86_l_1e48;
	case 7756ULL: goto x86_l_1e4c;
	case 7759ULL: goto x86_l_1e4f;
	case 7763ULL: goto x86_l_1e53;
	case 7769ULL: goto x86_l_1e59;
	case 7776ULL: goto x86_l_1e60;
	case 7782ULL: goto x86_l_1e66;
	case 7786ULL: goto x86_l_1e6a;
	case 7789ULL: goto x86_l_1e6d;
	case 7793ULL: goto x86_l_1e71;
	case 7799ULL: goto x86_l_1e77;
	case 7806ULL: goto x86_l_1e7e;
	case 7812ULL: goto x86_l_1e84;
	case 7816ULL: goto x86_l_1e88;
	case 7819ULL: goto x86_l_1e8b;
	case 7823ULL: goto x86_l_1e8f;
	case 7829ULL: goto x86_l_1e95;
	case 7836ULL: goto x86_l_1e9c;
	case 7842ULL: goto x86_l_1ea2;
	case 7846ULL: goto x86_l_1ea6;
	case 7849ULL: goto x86_l_1ea9;
	case 7853ULL: goto x86_l_1ead;
	case 7859ULL: goto x86_l_1eb3;
	case 7866ULL: goto x86_l_1eba;
	case 7872ULL: goto x86_l_1ec0;
	case 7876ULL: goto x86_l_1ec4;
	case 7879ULL: goto x86_l_1ec7;
	case 7883ULL: goto x86_l_1ecb;
	case 7889ULL: goto x86_l_1ed1;
	case 7896ULL: goto x86_l_1ed8;
	case 7902ULL: goto x86_l_1ede;
	case 7906ULL: goto x86_l_1ee2;
	case 7909ULL: goto x86_l_1ee5;
	case 7913ULL: goto x86_l_1ee9;
	case 7919ULL: goto x86_l_1eef;
	case 7926ULL: goto x86_l_1ef6;
	case 7932ULL: goto x86_l_1efc;
	case 7936ULL: goto x86_l_1f00;
	case 7939ULL: goto x86_l_1f03;
	case 7943ULL: goto x86_l_1f07;
	case 7949ULL: goto x86_l_1f0d;
	case 7956ULL: goto x86_l_1f14;
	case 7962ULL: goto x86_l_1f1a;
	case 7966ULL: goto x86_l_1f1e;
	case 7969ULL: goto x86_l_1f21;
	case 7973ULL: goto x86_l_1f25;
	case 7979ULL: goto x86_l_1f2b;
	case 7986ULL: goto x86_l_1f32;
	case 7992ULL: goto x86_l_1f38;
	case 7996ULL: goto x86_l_1f3c;
	case 7999ULL: goto x86_l_1f3f;
	case 8003ULL: goto x86_l_1f43;
	case 8009ULL: goto x86_l_1f49;
	case 8016ULL: goto x86_l_1f50;
	case 8022ULL: goto x86_l_1f56;
	case 8026ULL: goto x86_l_1f5a;
	case 8029ULL: goto x86_l_1f5d;
	case 8033ULL: goto x86_l_1f61;
	case 8039ULL: goto x86_l_1f67;
	case 8046ULL: goto x86_l_1f6e;
	case 8052ULL: goto x86_l_1f74;
	case 8056ULL: goto x86_l_1f78;
	case 8059ULL: goto x86_l_1f7b;
	case 8063ULL: goto x86_l_1f7f;
	case 8069ULL: goto x86_l_1f85;
	case 8076ULL: goto x86_l_1f8c;
	case 8082ULL: goto x86_l_1f92;
	case 8086ULL: goto x86_l_1f96;
	case 8089ULL: goto x86_l_1f99;
	case 8093ULL: goto x86_l_1f9d;
	case 8099ULL: goto x86_l_1fa3;
	case 8106ULL: goto x86_l_1faa;
	case 8112ULL: goto x86_l_1fb0;
	case 8116ULL: goto x86_l_1fb4;
	case 8119ULL: goto x86_l_1fb7;
	case 8123ULL: goto x86_l_1fbb;
	case 8129ULL: goto x86_l_1fc1;
	case 8136ULL: goto x86_l_1fc8;
	case 8142ULL: goto x86_l_1fce;
	case 8146ULL: goto x86_l_1fd2;
	case 8149ULL: goto x86_l_1fd5;
	case 8153ULL: goto x86_l_1fd9;
	case 8159ULL: goto x86_l_1fdf;
	case 8166ULL: goto x86_l_1fe6;
	case 8172ULL: goto x86_l_1fec;
	case 8176ULL: goto x86_l_1ff0;
	case 8179ULL: goto x86_l_1ff3;
	case 8183ULL: goto x86_l_1ff7;
	case 8189ULL: goto x86_l_1ffd;
	case 8196ULL: goto x86_l_2004;
	case 8202ULL: goto x86_l_200a;
	case 8206ULL: goto x86_l_200e;
	case 8209ULL: goto x86_l_2011;
	case 8213ULL: goto x86_l_2015;
	case 8219ULL: goto x86_l_201b;
	case 8226ULL: goto x86_l_2022;
	case 8232ULL: goto x86_l_2028;
	case 8236ULL: goto x86_l_202c;
	case 8239ULL: goto x86_l_202f;
	case 8243ULL: goto x86_l_2033;
	case 8249ULL: goto x86_l_2039;
	case 8256ULL: goto x86_l_2040;
	case 8262ULL: goto x86_l_2046;
	case 8266ULL: goto x86_l_204a;
	case 8269ULL: goto x86_l_204d;
	case 8273ULL: goto x86_l_2051;
	case 8279ULL: goto x86_l_2057;
	case 8286ULL: goto x86_l_205e;
	case 8292ULL: goto x86_l_2064;
	case 8296ULL: goto x86_l_2068;
	case 8299ULL: goto x86_l_206b;
	case 8303ULL: goto x86_l_206f;
	case 8309ULL: goto x86_l_2075;
	case 8316ULL: goto x86_l_207c;
	case 8322ULL: goto x86_l_2082;
	case 8326ULL: goto x86_l_2086;
	case 8329ULL: goto x86_l_2089;
	case 8333ULL: goto x86_l_208d;
	case 8339ULL: goto x86_l_2093;
	case 8346ULL: goto x86_l_209a;
	case 8352ULL: goto x86_l_20a0;
	case 8356ULL: goto x86_l_20a4;
	case 8359ULL: goto x86_l_20a7;
	case 8363ULL: goto x86_l_20ab;
	case 8369ULL: goto x86_l_20b1;
	case 8376ULL: goto x86_l_20b8;
	case 8382ULL: goto x86_l_20be;
	case 8386ULL: goto x86_l_20c2;
	case 8389ULL: goto x86_l_20c5;
	case 8393ULL: goto x86_l_20c9;
	case 8399ULL: goto x86_l_20cf;
	case 8406ULL: goto x86_l_20d6;
	case 8412ULL: goto x86_l_20dc;
	case 8416ULL: goto x86_l_20e0;
	case 8419ULL: goto x86_l_20e3;
	case 8423ULL: goto x86_l_20e7;
	case 8429ULL: goto x86_l_20ed;
	case 8436ULL: goto x86_l_20f4;
	case 8442ULL: goto x86_l_20fa;
	case 8446ULL: goto x86_l_20fe;
	case 8449ULL: goto x86_l_2101;
	case 8453ULL: goto x86_l_2105;
	case 8459ULL: goto x86_l_210b;
	case 8466ULL: goto x86_l_2112;
	case 8472ULL: goto x86_l_2118;
	case 8476ULL: goto x86_l_211c;
	case 8479ULL: goto x86_l_211f;
	case 8483ULL: goto x86_l_2123;
	case 8489ULL: goto x86_l_2129;
	case 8496ULL: goto x86_l_2130;
	case 8502ULL: goto x86_l_2136;
	case 8506ULL: goto x86_l_213a;
	case 8509ULL: goto x86_l_213d;
	case 8513ULL: goto x86_l_2141;
	case 8519ULL: goto x86_l_2147;
	case 8526ULL: goto x86_l_214e;
	case 8532ULL: goto x86_l_2154;
	case 8536ULL: goto x86_l_2158;
	case 8539ULL: goto x86_l_215b;
	case 8543ULL: goto x86_l_215f;
	case 8549ULL: goto x86_l_2165;
	case 8556ULL: goto x86_l_216c;
	case 8562ULL: goto x86_l_2172;
	case 8566ULL: goto x86_l_2176;
	case 8569ULL: goto x86_l_2179;
	case 8573ULL: goto x86_l_217d;
	case 8579ULL: goto x86_l_2183;
	case 8586ULL: goto x86_l_218a;
	case 8592ULL: goto x86_l_2190;
	case 8596ULL: goto x86_l_2194;
	case 8599ULL: goto x86_l_2197;
	case 8603ULL: goto x86_l_219b;
	case 8609ULL: goto x86_l_21a1;
	case 8616ULL: goto x86_l_21a8;
	case 8622ULL: goto x86_l_21ae;
	case 8626ULL: goto x86_l_21b2;
	case 8629ULL: goto x86_l_21b5;
	case 8633ULL: goto x86_l_21b9;
	case 8639ULL: goto x86_l_21bf;
	case 8646ULL: goto x86_l_21c6;
	case 8652ULL: goto x86_l_21cc;
	case 8656ULL: goto x86_l_21d0;
	case 8659ULL: goto x86_l_21d3;
	case 8663ULL: goto x86_l_21d7;
	case 8669ULL: goto x86_l_21dd;
	case 8676ULL: goto x86_l_21e4;
	case 8682ULL: goto x86_l_21ea;
	case 8686ULL: goto x86_l_21ee;
	case 8689ULL: goto x86_l_21f1;
	case 8693ULL: goto x86_l_21f5;
	case 8699ULL: goto x86_l_21fb;
	case 8706ULL: goto x86_l_2202;
	case 8712ULL: goto x86_l_2208;
	case 8716ULL: goto x86_l_220c;
	case 8719ULL: goto x86_l_220f;
	case 8723ULL: goto x86_l_2213;
	case 8729ULL: goto x86_l_2219;
	case 8736ULL: goto x86_l_2220;
	case 8742ULL: goto x86_l_2226;
	case 8746ULL: goto x86_l_222a;
	case 8749ULL: goto x86_l_222d;
	case 8753ULL: goto x86_l_2231;
	case 8759ULL: goto x86_l_2237;
	case 8766ULL: goto x86_l_223e;
	case 8772ULL: goto x86_l_2244;
	case 8776ULL: goto x86_l_2248;
	case 8779ULL: goto x86_l_224b;
	case 8783ULL: goto x86_l_224f;
	case 8789ULL: goto x86_l_2255;
	case 8796ULL: goto x86_l_225c;
	case 8802ULL: goto x86_l_2262;
	case 8806ULL: goto x86_l_2266;
	case 8809ULL: goto x86_l_2269;
	case 8813ULL: goto x86_l_226d;
	case 8819ULL: goto x86_l_2273;
	case 8826ULL: goto x86_l_227a;
	case 8832ULL: goto x86_l_2280;
	case 8836ULL: goto x86_l_2284;
	case 8839ULL: goto x86_l_2287;
	case 8843ULL: goto x86_l_228b;
	case 8849ULL: goto x86_l_2291;
	case 8856ULL: goto x86_l_2298;
	case 8862ULL: goto x86_l_229e;
	case 8866ULL: goto x86_l_22a2;
	case 8869ULL: goto x86_l_22a5;
	case 8873ULL: goto x86_l_22a9;
	case 8879ULL: goto x86_l_22af;
	case 8886ULL: goto x86_l_22b6;
	case 8892ULL: goto x86_l_22bc;
	case 8896ULL: goto x86_l_22c0;
	case 8899ULL: goto x86_l_22c3;
	case 8903ULL: goto x86_l_22c7;
	case 8909ULL: goto x86_l_22cd;
	case 8916ULL: goto x86_l_22d4;
	case 8922ULL: goto x86_l_22da;
	case 8926ULL: goto x86_l_22de;
	case 8929ULL: goto x86_l_22e1;
	case 8933ULL: goto x86_l_22e5;
	case 8939ULL: goto x86_l_22eb;
	case 8946ULL: goto x86_l_22f2;
	case 8952ULL: goto x86_l_22f8;
	case 8956ULL: goto x86_l_22fc;
	case 8959ULL: goto x86_l_22ff;
	case 8963ULL: goto x86_l_2303;
	case 8969ULL: goto x86_l_2309;
	case 8976ULL: goto x86_l_2310;
	case 8982ULL: goto x86_l_2316;
	case 8986ULL: goto x86_l_231a;
	case 8989ULL: goto x86_l_231d;
	case 8993ULL: goto x86_l_2321;
	case 8999ULL: goto x86_l_2327;
	case 9006ULL: goto x86_l_232e;
	case 9012ULL: goto x86_l_2334;
	case 9016ULL: goto x86_l_2338;
	case 9019ULL: goto x86_l_233b;
	case 9023ULL: goto x86_l_233f;
	case 9029ULL: goto x86_l_2345;
	case 9036ULL: goto x86_l_234c;
	case 9042ULL: goto x86_l_2352;
	case 9046ULL: goto x86_l_2356;
	case 9049ULL: goto x86_l_2359;
	case 9053ULL: goto x86_l_235d;
	case 9059ULL: goto x86_l_2363;
	case 9066ULL: goto x86_l_236a;
	case 9072ULL: goto x86_l_2370;
	case 9076ULL: goto x86_l_2374;
	case 9079ULL: goto x86_l_2377;
	case 9083ULL: goto x86_l_237b;
	case 9089ULL: goto x86_l_2381;
	case 9096ULL: goto x86_l_2388;
	case 9102ULL: goto x86_l_238e;
	case 9106ULL: goto x86_l_2392;
	case 9109ULL: goto x86_l_2395;
	case 9113ULL: goto x86_l_2399;
	case 9119ULL: goto x86_l_239f;
	case 9126ULL: goto x86_l_23a6;
	case 9132ULL: goto x86_l_23ac;
	case 9136ULL: goto x86_l_23b0;
	case 9139ULL: goto x86_l_23b3;
	case 9143ULL: goto x86_l_23b7;
	case 9149ULL: goto x86_l_23bd;
	case 9156ULL: goto x86_l_23c4;
	case 9162ULL: goto x86_l_23ca;
	case 9166ULL: goto x86_l_23ce;
	case 9169ULL: goto x86_l_23d1;
	case 9173ULL: goto x86_l_23d5;
	case 9179ULL: goto x86_l_23db;
	case 9186ULL: goto x86_l_23e2;
	case 9192ULL: goto x86_l_23e8;
	case 9196ULL: goto x86_l_23ec;
	case 9199ULL: goto x86_l_23ef;
	case 9203ULL: goto x86_l_23f3;
	case 9209ULL: goto x86_l_23f9;
	case 9216ULL: goto x86_l_2400;
	case 9222ULL: goto x86_l_2406;
	case 9226ULL: goto x86_l_240a;
	case 9229ULL: goto x86_l_240d;
	case 9233ULL: goto x86_l_2411;
	case 9239ULL: goto x86_l_2417;
	case 9246ULL: goto x86_l_241e;
	case 9252ULL: goto x86_l_2424;
	case 9256ULL: goto x86_l_2428;
	case 9259ULL: goto x86_l_242b;
	case 9263ULL: goto x86_l_242f;
	case 9269ULL: goto x86_l_2435;
	case 9276ULL: goto x86_l_243c;
	case 9282ULL: goto x86_l_2442;
	case 9286ULL: goto x86_l_2446;
	case 9289ULL: goto x86_l_2449;
	case 9293ULL: goto x86_l_244d;
	case 9299ULL: goto x86_l_2453;
	case 9306ULL: goto x86_l_245a;
	case 9312ULL: goto x86_l_2460;
	case 9316ULL: goto x86_l_2464;
	case 9319ULL: goto x86_l_2467;
	case 9323ULL: goto x86_l_246b;
	case 9329ULL: goto x86_l_2471;
	case 9336ULL: goto x86_l_2478;
	case 9342ULL: goto x86_l_247e;
	case 9346ULL: goto x86_l_2482;
	case 9349ULL: goto x86_l_2485;
	case 9353ULL: goto x86_l_2489;
	case 9359ULL: goto x86_l_248f;
	case 9366ULL: goto x86_l_2496;
	case 9372ULL: goto x86_l_249c;
	case 9376ULL: goto x86_l_24a0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1d2d:
	/* 0x1d2d: je     3220 <generic_usdt_filter_arg_2+0x3220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12832ULL;
	}
x86_l_1d33:
	/* 0x1d33: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d38:
	/* 0x1d38: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1d3c:
	/* 0x1d3c: cmp    r13d,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 94ULL);
x86_l_1d40:
	/* 0x1d40: mov    ecx,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 94ULL);
x86_l_1d45:
	/* 0x1d45: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_1d49:
	/* 0x1d49: shl    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1d4c:
	/* 0x1d4c: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d4e:
	/* 0x1d4e: lea    ecx,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1d52:
	/* 0x1d52: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d58:
	/* 0x1d58: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d5c:
	/* 0x1d5c: mov    BYTE PTR [rax+0x4],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d5f:
	/* 0x1d5f: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_1d63:
	/* 0x1d63: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1d69:
	/* 0x1d69: lea    ecx,[r13+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_1d70:
	/* 0x1d70: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d76:
	/* 0x1d76: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d7a:
	/* 0x1d7a: mov    BYTE PTR [rax+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_1d7d:
	/* 0x1d7d: cmp    r13,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 2ULL);
x86_l_1d81:
	/* 0x1d81: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1d87:
	/* 0x1d87: lea    ecx,[r13+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_1d8e:
	/* 0x1d8e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d94:
	/* 0x1d94: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d98:
	/* 0x1d98: mov    BYTE PTR [rax+0x6],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1d9b:
	/* 0x1d9b: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_1d9f:
	/* 0x1d9f: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1da5:
	/* 0x1da5: lea    ecx,[r13+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_1dac:
	/* 0x1dac: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1db2:
	/* 0x1db2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1db6:
	/* 0x1db6: mov    BYTE PTR [rax+0x7],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_1db9:
	/* 0x1db9: cmp    r13,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4ULL);
x86_l_1dbd:
	/* 0x1dbd: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1dc3:
	/* 0x1dc3: lea    ecx,[r13+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_1dca:
	/* 0x1dca: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1dd0:
	/* 0x1dd0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1dd4:
	/* 0x1dd4: mov    BYTE PTR [rax+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dd7:
	/* 0x1dd7: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_1ddb:
	/* 0x1ddb: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1de1:
	/* 0x1de1: lea    ecx,[r13+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_1de8:
	/* 0x1de8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1dee:
	/* 0x1dee: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1df2:
	/* 0x1df2: mov    BYTE PTR [rax+0x9],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_1df5:
	/* 0x1df5: cmp    r13,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 6ULL);
x86_l_1df9:
	/* 0x1df9: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1dff:
	/* 0x1dff: lea    ecx,[r13+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_1e06:
	/* 0x1e06: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e0c:
	/* 0x1e0c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e10:
	/* 0x1e10: mov    BYTE PTR [rax+0xa],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_1e13:
	/* 0x1e13: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_1e17:
	/* 0x1e17: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1e1d:
	/* 0x1e1d: lea    ecx,[r13+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_1e24:
	/* 0x1e24: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e2a:
	/* 0x1e2a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e2e:
	/* 0x1e2e: mov    BYTE PTR [rax+0xb],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_1e31:
	/* 0x1e31: cmp    r13,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 8ULL);
x86_l_1e35:
	/* 0x1e35: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1e3b:
	/* 0x1e3b: lea    ecx,[r13+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_1e42:
	/* 0x1e42: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e48:
	/* 0x1e48: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e4c:
	/* 0x1e4c: mov    BYTE PTR [rax+0xc],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e4f:
	/* 0x1e4f: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_1e53:
	/* 0x1e53: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1e59:
	/* 0x1e59: lea    ecx,[r13+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_1e60:
	/* 0x1e60: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e66:
	/* 0x1e66: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e6a:
	/* 0x1e6a: mov    BYTE PTR [rax+0xd],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_1e6d:
	/* 0x1e6d: cmp    r13,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 10ULL);
x86_l_1e71:
	/* 0x1e71: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1e77:
	/* 0x1e77: lea    ecx,[r13+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_1e7e:
	/* 0x1e7e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e84:
	/* 0x1e84: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e88:
	/* 0x1e88: mov    BYTE PTR [rax+0xe],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_1e8b:
	/* 0x1e8b: cmp    r13,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 11ULL);
x86_l_1e8f:
	/* 0x1e8f: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1e95:
	/* 0x1e95: lea    ecx,[r13+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_1e9c:
	/* 0x1e9c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ea2:
	/* 0x1ea2: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ea6:
	/* 0x1ea6: mov    BYTE PTR [rax+0xf],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_1ea9:
	/* 0x1ea9: cmp    r13,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 12ULL);
x86_l_1ead:
	/* 0x1ead: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1eb3:
	/* 0x1eb3: lea    ecx,[r13+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_1eba:
	/* 0x1eba: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ec0:
	/* 0x1ec0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ec4:
	/* 0x1ec4: mov    BYTE PTR [rax+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ec7:
	/* 0x1ec7: cmp    r13,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 13ULL);
x86_l_1ecb:
	/* 0x1ecb: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1ed1:
	/* 0x1ed1: lea    ecx,[r13+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_1ed8:
	/* 0x1ed8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ede:
	/* 0x1ede: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ee2:
	/* 0x1ee2: mov    BYTE PTR [rax+0x11],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_1ee5:
	/* 0x1ee5: cmp    r13,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 14ULL);
x86_l_1ee9:
	/* 0x1ee9: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1eef:
	/* 0x1eef: lea    ecx,[r13+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_1ef6:
	/* 0x1ef6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1efc:
	/* 0x1efc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f00:
	/* 0x1f00: mov    BYTE PTR [rax+0x12],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1f03:
	/* 0x1f03: cmp    r13,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 15ULL);
x86_l_1f07:
	/* 0x1f07: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1f0d:
	/* 0x1f0d: lea    ecx,[r13+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_1f14:
	/* 0x1f14: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f1a:
	/* 0x1f1a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f1e:
	/* 0x1f1e: mov    BYTE PTR [rax+0x13],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_1f21:
	/* 0x1f21: cmp    r13,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 16ULL);
x86_l_1f25:
	/* 0x1f25: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1f2b:
	/* 0x1f2b: lea    ecx,[r13+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_1f32:
	/* 0x1f32: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f38:
	/* 0x1f38: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f3c:
	/* 0x1f3c: mov    BYTE PTR [rax+0x14],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1f3f:
	/* 0x1f3f: cmp    r13,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 17ULL);
x86_l_1f43:
	/* 0x1f43: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1f49:
	/* 0x1f49: lea    ecx,[r13+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_1f50:
	/* 0x1f50: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f56:
	/* 0x1f56: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f5a:
	/* 0x1f5a: mov    BYTE PTR [rax+0x15],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_1f5d:
	/* 0x1f5d: cmp    r13,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18ULL);
x86_l_1f61:
	/* 0x1f61: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1f67:
	/* 0x1f67: lea    ecx,[r13+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_1f6e:
	/* 0x1f6e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f74:
	/* 0x1f74: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f78:
	/* 0x1f78: mov    BYTE PTR [rax+0x16],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_1f7b:
	/* 0x1f7b: cmp    r13,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 19ULL);
x86_l_1f7f:
	/* 0x1f7f: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1f85:
	/* 0x1f85: lea    ecx,[r13+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_1f8c:
	/* 0x1f8c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f92:
	/* 0x1f92: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f96:
	/* 0x1f96: mov    BYTE PTR [rax+0x17],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_1f99:
	/* 0x1f99: cmp    r13,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 20ULL);
x86_l_1f9d:
	/* 0x1f9d: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1fa3:
	/* 0x1fa3: lea    ecx,[r13+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_1faa:
	/* 0x1faa: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1fb0:
	/* 0x1fb0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1fb4:
	/* 0x1fb4: mov    BYTE PTR [rax+0x18],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fb7:
	/* 0x1fb7: cmp    r13,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 21ULL);
x86_l_1fbb:
	/* 0x1fbb: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1fc1:
	/* 0x1fc1: lea    ecx,[r13+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_1fc8:
	/* 0x1fc8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1fce:
	/* 0x1fce: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1fd2:
	/* 0x1fd2: mov    BYTE PTR [rax+0x19],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_1fd5:
	/* 0x1fd5: cmp    r13,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 22ULL);
x86_l_1fd9:
	/* 0x1fd9: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1fdf:
	/* 0x1fdf: lea    ecx,[r13+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_1fe6:
	/* 0x1fe6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1fec:
	/* 0x1fec: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ff0:
	/* 0x1ff0: mov    BYTE PTR [rax+0x1a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_1ff3:
	/* 0x1ff3: cmp    r13,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 23ULL);
x86_l_1ff7:
	/* 0x1ff7: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1ffd:
	/* 0x1ffd: lea    ecx,[r13+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_2004:
	/* 0x2004: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_200a:
	/* 0x200a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_200e:
	/* 0x200e: mov    BYTE PTR [rax+0x1b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_2011:
	/* 0x2011: cmp    r13,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 24ULL);
x86_l_2015:
	/* 0x2015: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_201b:
	/* 0x201b: lea    ecx,[r13+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_2022:
	/* 0x2022: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2028:
	/* 0x2028: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_202c:
	/* 0x202c: mov    BYTE PTR [rax+0x1c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_202f:
	/* 0x202f: cmp    r13,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 25ULL);
x86_l_2033:
	/* 0x2033: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2039:
	/* 0x2039: lea    ecx,[r13+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_2040:
	/* 0x2040: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2046:
	/* 0x2046: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_204a:
	/* 0x204a: mov    BYTE PTR [rax+0x1d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_204d:
	/* 0x204d: cmp    r13,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 26ULL);
x86_l_2051:
	/* 0x2051: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2057:
	/* 0x2057: lea    ecx,[r13+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_205e:
	/* 0x205e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2064:
	/* 0x2064: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2068:
	/* 0x2068: mov    BYTE PTR [rax+0x1e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_206b:
	/* 0x206b: cmp    r13,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 27ULL);
x86_l_206f:
	/* 0x206f: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2075:
	/* 0x2075: lea    ecx,[r13+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_207c:
	/* 0x207c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2082:
	/* 0x2082: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2086:
	/* 0x2086: mov    BYTE PTR [rax+0x1f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_2089:
	/* 0x2089: cmp    r13,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 28ULL);
x86_l_208d:
	/* 0x208d: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2093:
	/* 0x2093: lea    ecx,[r13+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_209a:
	/* 0x209a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20a0:
	/* 0x20a0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_20a4:
	/* 0x20a4: mov    BYTE PTR [rax+0x20],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20a7:
	/* 0x20a7: cmp    r13,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 29ULL);
x86_l_20ab:
	/* 0x20ab: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_20b1:
	/* 0x20b1: lea    ecx,[r13+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_20b8:
	/* 0x20b8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20be:
	/* 0x20be: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_20c2:
	/* 0x20c2: mov    BYTE PTR [rax+0x21],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_20c5:
	/* 0x20c5: cmp    r13,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 30ULL);
x86_l_20c9:
	/* 0x20c9: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_20cf:
	/* 0x20cf: lea    ecx,[r13+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_20d6:
	/* 0x20d6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20dc:
	/* 0x20dc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_20e0:
	/* 0x20e0: mov    BYTE PTR [rax+0x22],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_20e3:
	/* 0x20e3: cmp    r13,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 31ULL);
x86_l_20e7:
	/* 0x20e7: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_20ed:
	/* 0x20ed: lea    ecx,[r13+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_20f4:
	/* 0x20f4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20fa:
	/* 0x20fa: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_20fe:
	/* 0x20fe: mov    BYTE PTR [rax+0x23],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_2101:
	/* 0x2101: cmp    r13,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 32ULL);
x86_l_2105:
	/* 0x2105: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_210b:
	/* 0x210b: lea    ecx,[r13+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_2112:
	/* 0x2112: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2118:
	/* 0x2118: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_211c:
	/* 0x211c: mov    BYTE PTR [rax+0x24],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_211f:
	/* 0x211f: cmp    r13,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 33ULL);
x86_l_2123:
	/* 0x2123: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2129:
	/* 0x2129: lea    ecx,[r13+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_2130:
	/* 0x2130: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2136:
	/* 0x2136: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_213a:
	/* 0x213a: mov    BYTE PTR [rax+0x25],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_213d:
	/* 0x213d: cmp    r13,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 34ULL);
x86_l_2141:
	/* 0x2141: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2147:
	/* 0x2147: lea    ecx,[r13+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_214e:
	/* 0x214e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2154:
	/* 0x2154: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2158:
	/* 0x2158: mov    BYTE PTR [rax+0x26],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_215b:
	/* 0x215b: cmp    r13,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 35ULL);
x86_l_215f:
	/* 0x215f: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2165:
	/* 0x2165: lea    ecx,[r13+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_216c:
	/* 0x216c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2172:
	/* 0x2172: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2176:
	/* 0x2176: mov    BYTE PTR [rax+0x27],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_2179:
	/* 0x2179: cmp    r13,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 36ULL);
x86_l_217d:
	/* 0x217d: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2183:
	/* 0x2183: lea    ecx,[r13+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_218a:
	/* 0x218a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2190:
	/* 0x2190: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2194:
	/* 0x2194: mov    BYTE PTR [rax+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2197:
	/* 0x2197: cmp    r13,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 37ULL);
x86_l_219b:
	/* 0x219b: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_21a1:
	/* 0x21a1: lea    ecx,[r13+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_21a8:
	/* 0x21a8: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21ae:
	/* 0x21ae: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_21b2:
	/* 0x21b2: mov    BYTE PTR [rax+0x29],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_21b5:
	/* 0x21b5: cmp    r13,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 38ULL);
x86_l_21b9:
	/* 0x21b9: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_21bf:
	/* 0x21bf: lea    ecx,[r13+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_21c6:
	/* 0x21c6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21cc:
	/* 0x21cc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_21d0:
	/* 0x21d0: mov    BYTE PTR [rax+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_21d3:
	/* 0x21d3: cmp    r13,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 39ULL);
x86_l_21d7:
	/* 0x21d7: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_21dd:
	/* 0x21dd: lea    ecx,[r13+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_21e4:
	/* 0x21e4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21ea:
	/* 0x21ea: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_21ee:
	/* 0x21ee: mov    BYTE PTR [rax+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_21f1:
	/* 0x21f1: cmp    r13,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 40ULL);
x86_l_21f5:
	/* 0x21f5: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_21fb:
	/* 0x21fb: lea    ecx,[r13+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_2202:
	/* 0x2202: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2208:
	/* 0x2208: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_220c:
	/* 0x220c: mov    BYTE PTR [rax+0x2c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_220f:
	/* 0x220f: cmp    r13,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 41ULL);
x86_l_2213:
	/* 0x2213: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2219:
	/* 0x2219: lea    ecx,[r13+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_2220:
	/* 0x2220: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2226:
	/* 0x2226: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_222a:
	/* 0x222a: mov    BYTE PTR [rax+0x2d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_222d:
	/* 0x222d: cmp    r13,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 42ULL);
x86_l_2231:
	/* 0x2231: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2237:
	/* 0x2237: lea    ecx,[r13+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_223e:
	/* 0x223e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2244:
	/* 0x2244: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2248:
	/* 0x2248: mov    BYTE PTR [rax+0x2e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_224b:
	/* 0x224b: cmp    r13,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 43ULL);
x86_l_224f:
	/* 0x224f: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2255:
	/* 0x2255: lea    ecx,[r13+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_225c:
	/* 0x225c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2262:
	/* 0x2262: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2266:
	/* 0x2266: mov    BYTE PTR [rax+0x2f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_2269:
	/* 0x2269: cmp    r13,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 44ULL);
x86_l_226d:
	/* 0x226d: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2273:
	/* 0x2273: lea    ecx,[r13+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_227a:
	/* 0x227a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2280:
	/* 0x2280: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2284:
	/* 0x2284: mov    BYTE PTR [rax+0x30],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2287:
	/* 0x2287: cmp    r13,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 45ULL);
x86_l_228b:
	/* 0x228b: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2291:
	/* 0x2291: lea    ecx,[r13+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_2298:
	/* 0x2298: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_229e:
	/* 0x229e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_22a2:
	/* 0x22a2: mov    BYTE PTR [rax+0x31],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_22a5:
	/* 0x22a5: cmp    r13,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 46ULL);
x86_l_22a9:
	/* 0x22a9: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_22af:
	/* 0x22af: lea    ecx,[r13+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_22b6:
	/* 0x22b6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22bc:
	/* 0x22bc: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_22c0:
	/* 0x22c0: mov    BYTE PTR [rax+0x32],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_22c3:
	/* 0x22c3: cmp    r13,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 47ULL);
x86_l_22c7:
	/* 0x22c7: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_22cd:
	/* 0x22cd: lea    ecx,[r13+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_22d4:
	/* 0x22d4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22da:
	/* 0x22da: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_22de:
	/* 0x22de: mov    BYTE PTR [rax+0x33],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_22e1:
	/* 0x22e1: cmp    r13,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 48ULL);
x86_l_22e5:
	/* 0x22e5: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_22eb:
	/* 0x22eb: lea    ecx,[r13+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_22f2:
	/* 0x22f2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22f8:
	/* 0x22f8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_22fc:
	/* 0x22fc: mov    BYTE PTR [rax+0x34],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_22ff:
	/* 0x22ff: cmp    r13,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 49ULL);
x86_l_2303:
	/* 0x2303: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2309:
	/* 0x2309: lea    ecx,[r13+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_2310:
	/* 0x2310: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2316:
	/* 0x2316: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_231a:
	/* 0x231a: mov    BYTE PTR [rax+0x35],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_231d:
	/* 0x231d: cmp    r13,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 50ULL);
x86_l_2321:
	/* 0x2321: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2327:
	/* 0x2327: lea    ecx,[r13+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_232e:
	/* 0x232e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2334:
	/* 0x2334: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2338:
	/* 0x2338: mov    BYTE PTR [rax+0x36],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_233b:
	/* 0x233b: cmp    r13,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 51ULL);
x86_l_233f:
	/* 0x233f: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2345:
	/* 0x2345: lea    ecx,[r13+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_234c:
	/* 0x234c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2352:
	/* 0x2352: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2356:
	/* 0x2356: mov    BYTE PTR [rax+0x37],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_2359:
	/* 0x2359: cmp    r13,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 52ULL);
x86_l_235d:
	/* 0x235d: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2363:
	/* 0x2363: lea    ecx,[r13+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_236a:
	/* 0x236a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2370:
	/* 0x2370: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2374:
	/* 0x2374: mov    BYTE PTR [rax+0x38],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2377:
	/* 0x2377: cmp    r13,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 53ULL);
x86_l_237b:
	/* 0x237b: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2381:
	/* 0x2381: lea    ecx,[r13+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_2388:
	/* 0x2388: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_238e:
	/* 0x238e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2392:
	/* 0x2392: mov    BYTE PTR [rax+0x39],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_2395:
	/* 0x2395: cmp    r13,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 54ULL);
x86_l_2399:
	/* 0x2399: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_239f:
	/* 0x239f: lea    ecx,[r13+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_23a6:
	/* 0x23a6: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23ac:
	/* 0x23ac: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_23b0:
	/* 0x23b0: mov    BYTE PTR [rax+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_23b3:
	/* 0x23b3: cmp    r13,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 55ULL);
x86_l_23b7:
	/* 0x23b7: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_23bd:
	/* 0x23bd: lea    ecx,[r13+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_23c4:
	/* 0x23c4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23ca:
	/* 0x23ca: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_23ce:
	/* 0x23ce: mov    BYTE PTR [rax+0x3b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_23d1:
	/* 0x23d1: cmp    r13,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 56ULL);
x86_l_23d5:
	/* 0x23d5: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_23db:
	/* 0x23db: lea    ecx,[r13+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_23e2:
	/* 0x23e2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23e8:
	/* 0x23e8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_23ec:
	/* 0x23ec: mov    BYTE PTR [rax+0x3c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_23ef:
	/* 0x23ef: cmp    r13,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 57ULL);
x86_l_23f3:
	/* 0x23f3: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_23f9:
	/* 0x23f9: lea    ecx,[r13+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_2400:
	/* 0x2400: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2406:
	/* 0x2406: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_240a:
	/* 0x240a: mov    BYTE PTR [rax+0x3d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_240d:
	/* 0x240d: cmp    r13,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 58ULL);
x86_l_2411:
	/* 0x2411: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2417:
	/* 0x2417: lea    ecx,[r13+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_241e:
	/* 0x241e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2424:
	/* 0x2424: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2428:
	/* 0x2428: mov    BYTE PTR [rax+0x3e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_242b:
	/* 0x242b: cmp    r13,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 59ULL);
x86_l_242f:
	/* 0x242f: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2435:
	/* 0x2435: lea    ecx,[r13+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_243c:
	/* 0x243c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2442:
	/* 0x2442: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2446:
	/* 0x2446: mov    BYTE PTR [rax+0x3f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_2449:
	/* 0x2449: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_244d:
	/* 0x244d: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2453:
	/* 0x2453: lea    ecx,[r13+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_245a:
	/* 0x245a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2460:
	/* 0x2460: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2464:
	/* 0x2464: mov    BYTE PTR [rax+0x40],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2467:
	/* 0x2467: cmp    r13,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 61ULL);
x86_l_246b:
	/* 0x246b: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_2471:
	/* 0x2471: lea    ecx,[r13+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_2478:
	/* 0x2478: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_247e:
	/* 0x247e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2482:
	/* 0x2482: mov    BYTE PTR [rax+0x41],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_2485:
	/* 0x2485: cmp    r13,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 62ULL);
x86_l_2489:
	/* 0x2489: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_248f:
	/* 0x248f: lea    ecx,[r13+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_2496:
	/* 0x2496: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_249c:
	/* 0x249c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_24a0:
	/* 0x24a0: mov    BYTE PTR [rax+0x42],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
	return 9379ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9379ULL: goto x86_l_24a3;
	case 9383ULL: goto x86_l_24a7;
	case 9389ULL: goto x86_l_24ad;
	case 9396ULL: goto x86_l_24b4;
	case 9402ULL: goto x86_l_24ba;
	case 9406ULL: goto x86_l_24be;
	case 9409ULL: goto x86_l_24c1;
	case 9413ULL: goto x86_l_24c5;
	case 9419ULL: goto x86_l_24cb;
	case 9426ULL: goto x86_l_24d2;
	case 9432ULL: goto x86_l_24d8;
	case 9436ULL: goto x86_l_24dc;
	case 9439ULL: goto x86_l_24df;
	case 9443ULL: goto x86_l_24e3;
	case 9449ULL: goto x86_l_24e9;
	case 9456ULL: goto x86_l_24f0;
	case 9462ULL: goto x86_l_24f6;
	case 9466ULL: goto x86_l_24fa;
	case 9469ULL: goto x86_l_24fd;
	case 9473ULL: goto x86_l_2501;
	case 9479ULL: goto x86_l_2507;
	case 9486ULL: goto x86_l_250e;
	case 9492ULL: goto x86_l_2514;
	case 9496ULL: goto x86_l_2518;
	case 9499ULL: goto x86_l_251b;
	case 9503ULL: goto x86_l_251f;
	case 9509ULL: goto x86_l_2525;
	case 9516ULL: goto x86_l_252c;
	case 9522ULL: goto x86_l_2532;
	case 9526ULL: goto x86_l_2536;
	case 9529ULL: goto x86_l_2539;
	case 9533ULL: goto x86_l_253d;
	case 9539ULL: goto x86_l_2543;
	case 9546ULL: goto x86_l_254a;
	case 9552ULL: goto x86_l_2550;
	case 9556ULL: goto x86_l_2554;
	case 9559ULL: goto x86_l_2557;
	case 9563ULL: goto x86_l_255b;
	case 9569ULL: goto x86_l_2561;
	case 9576ULL: goto x86_l_2568;
	case 9582ULL: goto x86_l_256e;
	case 9586ULL: goto x86_l_2572;
	case 9589ULL: goto x86_l_2575;
	case 9593ULL: goto x86_l_2579;
	case 9599ULL: goto x86_l_257f;
	case 9606ULL: goto x86_l_2586;
	case 9612ULL: goto x86_l_258c;
	case 9616ULL: goto x86_l_2590;
	case 9619ULL: goto x86_l_2593;
	case 9623ULL: goto x86_l_2597;
	case 9629ULL: goto x86_l_259d;
	case 9636ULL: goto x86_l_25a4;
	case 9642ULL: goto x86_l_25aa;
	case 9646ULL: goto x86_l_25ae;
	case 9649ULL: goto x86_l_25b1;
	case 9653ULL: goto x86_l_25b5;
	case 9659ULL: goto x86_l_25bb;
	case 9666ULL: goto x86_l_25c2;
	case 9672ULL: goto x86_l_25c8;
	case 9676ULL: goto x86_l_25cc;
	case 9679ULL: goto x86_l_25cf;
	case 9683ULL: goto x86_l_25d3;
	case 9689ULL: goto x86_l_25d9;
	case 9696ULL: goto x86_l_25e0;
	case 9702ULL: goto x86_l_25e6;
	case 9706ULL: goto x86_l_25ea;
	case 9709ULL: goto x86_l_25ed;
	case 9713ULL: goto x86_l_25f1;
	case 9719ULL: goto x86_l_25f7;
	case 9726ULL: goto x86_l_25fe;
	case 9732ULL: goto x86_l_2604;
	case 9736ULL: goto x86_l_2608;
	case 9739ULL: goto x86_l_260b;
	case 9743ULL: goto x86_l_260f;
	case 9749ULL: goto x86_l_2615;
	case 9756ULL: goto x86_l_261c;
	case 9762ULL: goto x86_l_2622;
	case 9766ULL: goto x86_l_2626;
	case 9769ULL: goto x86_l_2629;
	case 9773ULL: goto x86_l_262d;
	case 9779ULL: goto x86_l_2633;
	case 9786ULL: goto x86_l_263a;
	case 9792ULL: goto x86_l_2640;
	case 9796ULL: goto x86_l_2644;
	case 9799ULL: goto x86_l_2647;
	case 9803ULL: goto x86_l_264b;
	case 9809ULL: goto x86_l_2651;
	case 9816ULL: goto x86_l_2658;
	case 9822ULL: goto x86_l_265e;
	case 9826ULL: goto x86_l_2662;
	case 9829ULL: goto x86_l_2665;
	case 9833ULL: goto x86_l_2669;
	case 9839ULL: goto x86_l_266f;
	case 9846ULL: goto x86_l_2676;
	case 9852ULL: goto x86_l_267c;
	case 9856ULL: goto x86_l_2680;
	case 9859ULL: goto x86_l_2683;
	case 9863ULL: goto x86_l_2687;
	case 9869ULL: goto x86_l_268d;
	case 9876ULL: goto x86_l_2694;
	case 9882ULL: goto x86_l_269a;
	case 9886ULL: goto x86_l_269e;
	case 9889ULL: goto x86_l_26a1;
	case 9893ULL: goto x86_l_26a5;
	case 9899ULL: goto x86_l_26ab;
	case 9906ULL: goto x86_l_26b2;
	case 9912ULL: goto x86_l_26b8;
	case 9916ULL: goto x86_l_26bc;
	case 9919ULL: goto x86_l_26bf;
	case 9923ULL: goto x86_l_26c3;
	case 9929ULL: goto x86_l_26c9;
	case 9936ULL: goto x86_l_26d0;
	case 9942ULL: goto x86_l_26d6;
	case 9946ULL: goto x86_l_26da;
	case 9949ULL: goto x86_l_26dd;
	case 9953ULL: goto x86_l_26e1;
	case 9959ULL: goto x86_l_26e7;
	case 9966ULL: goto x86_l_26ee;
	case 9972ULL: goto x86_l_26f4;
	case 9976ULL: goto x86_l_26f8;
	case 9979ULL: goto x86_l_26fb;
	case 9983ULL: goto x86_l_26ff;
	case 9989ULL: goto x86_l_2705;
	case 9996ULL: goto x86_l_270c;
	case 10002ULL: goto x86_l_2712;
	case 10006ULL: goto x86_l_2716;
	case 10009ULL: goto x86_l_2719;
	case 10013ULL: goto x86_l_271d;
	case 10019ULL: goto x86_l_2723;
	case 10026ULL: goto x86_l_272a;
	case 10032ULL: goto x86_l_2730;
	case 10036ULL: goto x86_l_2734;
	case 10039ULL: goto x86_l_2737;
	case 10043ULL: goto x86_l_273b;
	case 10049ULL: goto x86_l_2741;
	case 10056ULL: goto x86_l_2748;
	case 10062ULL: goto x86_l_274e;
	case 10066ULL: goto x86_l_2752;
	case 10069ULL: goto x86_l_2755;
	case 10073ULL: goto x86_l_2759;
	case 10079ULL: goto x86_l_275f;
	case 10086ULL: goto x86_l_2766;
	case 10092ULL: goto x86_l_276c;
	case 10096ULL: goto x86_l_2770;
	case 10099ULL: goto x86_l_2773;
	case 10103ULL: goto x86_l_2777;
	case 10109ULL: goto x86_l_277d;
	case 10116ULL: goto x86_l_2784;
	case 10122ULL: goto x86_l_278a;
	case 10126ULL: goto x86_l_278e;
	case 10129ULL: goto x86_l_2791;
	case 10133ULL: goto x86_l_2795;
	case 10139ULL: goto x86_l_279b;
	case 10146ULL: goto x86_l_27a2;
	case 10152ULL: goto x86_l_27a8;
	case 10156ULL: goto x86_l_27ac;
	case 10159ULL: goto x86_l_27af;
	case 10163ULL: goto x86_l_27b3;
	case 10169ULL: goto x86_l_27b9;
	case 10176ULL: goto x86_l_27c0;
	case 10182ULL: goto x86_l_27c6;
	case 10186ULL: goto x86_l_27ca;
	case 10189ULL: goto x86_l_27cd;
	case 10193ULL: goto x86_l_27d1;
	case 10195ULL: goto x86_l_27d3;
	case 10202ULL: goto x86_l_27da;
	case 10208ULL: goto x86_l_27e0;
	case 10212ULL: goto x86_l_27e4;
	case 10215ULL: goto x86_l_27e7;
	case 10219ULL: goto x86_l_27eb;
	case 10221ULL: goto x86_l_27ed;
	case 10228ULL: goto x86_l_27f4;
	case 10234ULL: goto x86_l_27fa;
	case 10238ULL: goto x86_l_27fe;
	case 10241ULL: goto x86_l_2801;
	case 10245ULL: goto x86_l_2805;
	case 10247ULL: goto x86_l_2807;
	case 10254ULL: goto x86_l_280e;
	case 10260ULL: goto x86_l_2814;
	case 10264ULL: goto x86_l_2818;
	case 10267ULL: goto x86_l_281b;
	case 10271ULL: goto x86_l_281f;
	case 10273ULL: goto x86_l_2821;
	case 10280ULL: goto x86_l_2828;
	case 10287ULL: goto x86_l_282f;
	case 10292ULL: goto x86_l_2834;
	case 10295ULL: goto x86_l_2837;
	case 10300ULL: goto x86_l_283c;
	case 10305ULL: goto x86_l_2841;
	case 10308ULL: goto x86_l_2844;
	case 10313ULL: goto x86_l_2849;
	case 10318ULL: goto x86_l_284e;
	case 10322ULL: goto x86_l_2852;
	case 10325ULL: goto x86_l_2855;
	case 10329ULL: goto x86_l_2859;
	case 10337ULL: goto x86_l_2861;
	case 10342ULL: goto x86_l_2866;
	case 10349ULL: goto x86_l_286d;
	case 10354ULL: goto x86_l_2872;
	case 10356ULL: goto x86_l_2874;
	case 10359ULL: goto x86_l_2877;
	case 10362ULL: goto x86_l_287a;
	case 10365ULL: goto x86_l_287d;
	case 10371ULL: goto x86_l_2883;
	case 10376ULL: goto x86_l_2888;
	case 10379ULL: goto x86_l_288b;
	case 10385ULL: goto x86_l_2891;
	case 10390ULL: goto x86_l_2896;
	case 10397ULL: goto x86_l_289d;
	case 10402ULL: goto x86_l_28a2;
	case 10404ULL: goto x86_l_28a4;
	case 10407ULL: goto x86_l_28a7;
	case 10413ULL: goto x86_l_28ad;
	case 10418ULL: goto x86_l_28b2;
	case 10422ULL: goto x86_l_28b6;
	case 10429ULL: goto x86_l_28bd;
	case 10434ULL: goto x86_l_28c2;
	case 10438ULL: goto x86_l_28c6;
	case 10445ULL: goto x86_l_28cd;
	case 10447ULL: goto x86_l_28cf;
	case 10450ULL: goto x86_l_28d2;
	case 10454ULL: goto x86_l_28d6;
	case 10459ULL: goto x86_l_28db;
	case 10462ULL: goto x86_l_28de;
	case 10464ULL: goto x86_l_28e0;
	case 10469ULL: goto x86_l_28e5;
	case 10474ULL: goto x86_l_28ea;
	case 10477ULL: goto x86_l_28ed;
	case 10479ULL: goto x86_l_28ef;
	case 10482ULL: goto x86_l_28f2;
	case 10485ULL: goto x86_l_28f5;
	case 10489ULL: goto x86_l_28f9;
	case 10494ULL: goto x86_l_28fe;
	case 10497ULL: goto x86_l_2901;
	case 10499ULL: goto x86_l_2903;
	case 10502ULL: goto x86_l_2906;
	case 10508ULL: goto x86_l_290c;
	case 10513ULL: goto x86_l_2911;
	case 10515ULL: goto x86_l_2913;
	case 10520ULL: goto x86_l_2918;
	case 10522ULL: goto x86_l_291a;
	case 10525ULL: goto x86_l_291d;
	case 10528ULL: goto x86_l_2920;
	case 10530ULL: goto x86_l_2922;
	case 10533ULL: goto x86_l_2925;
	case 10539ULL: goto x86_l_292b;
	case 10542ULL: goto x86_l_292e;
	case 10548ULL: goto x86_l_2934;
	case 10551ULL: goto x86_l_2937;
	case 10557ULL: goto x86_l_293d;
	case 10560ULL: goto x86_l_2940;
	case 10566ULL: goto x86_l_2946;
	case 10569ULL: goto x86_l_2949;
	case 10574ULL: goto x86_l_294e;
	case 10578ULL: goto x86_l_2952;
	case 10582ULL: goto x86_l_2956;
	case 10584ULL: goto x86_l_2958;
	case 10587ULL: goto x86_l_295b;
	case 10591ULL: goto x86_l_295f;
	case 10594ULL: goto x86_l_2962;
	case 10598ULL: goto x86_l_2966;
	case 10601ULL: goto x86_l_2969;
	case 10604ULL: goto x86_l_296c;
	case 10607ULL: goto x86_l_296f;
	case 10609ULL: goto x86_l_2971;
	case 10612ULL: goto x86_l_2974;
	case 10615ULL: goto x86_l_2977;
	case 10617ULL: goto x86_l_2979;
	case 10620ULL: goto x86_l_297c;
	case 10623ULL: goto x86_l_297f;
	case 10629ULL: goto x86_l_2985;
	case 10632ULL: goto x86_l_2988;
	case 10638ULL: goto x86_l_298e;
	case 10643ULL: goto x86_l_2993;
	case 10646ULL: goto x86_l_2996;
	case 10648ULL: goto x86_l_2998;
	case 10653ULL: goto x86_l_299d;
	case 10656ULL: goto x86_l_29a0;
	case 10662ULL: goto x86_l_29a6;
	case 10667ULL: goto x86_l_29ab;
	case 10670ULL: goto x86_l_29ae;
	case 10676ULL: goto x86_l_29b4;
	case 10681ULL: goto x86_l_29b9;
	case 10684ULL: goto x86_l_29bc;
	case 10686ULL: goto x86_l_29be;
	case 10690ULL: goto x86_l_29c2;
	case 10693ULL: goto x86_l_29c5;
	case 10699ULL: goto x86_l_29cb;
	case 10702ULL: goto x86_l_29ce;
	case 10708ULL: goto x86_l_29d4;
	case 10711ULL: goto x86_l_29d7;
	case 10714ULL: goto x86_l_29da;
	case 10717ULL: goto x86_l_29dd;
	case 10721ULL: goto x86_l_29e1;
	case 10726ULL: goto x86_l_29e6;
	case 10733ULL: goto x86_l_29ed;
	case 10738ULL: goto x86_l_29f2;
	case 10740ULL: goto x86_l_29f4;
	case 10743ULL: goto x86_l_29f7;
	case 10749ULL: goto x86_l_29fd;
	case 10757ULL: goto x86_l_2a05;
	case 10762ULL: goto x86_l_2a0a;
	case 10767ULL: goto x86_l_2a0f;
	case 10770ULL: goto x86_l_2a12;
	case 10773ULL: goto x86_l_2a15;
	case 10779ULL: goto x86_l_2a1b;
	case 10782ULL: goto x86_l_2a1e;
	case 10786ULL: goto x86_l_2a22;
	case 10790ULL: goto x86_l_2a26;
	case 10795ULL: goto x86_l_2a2b;
	case 10802ULL: goto x86_l_2a32;
	case 10805ULL: goto x86_l_2a35;
	case 10810ULL: goto x86_l_2a3a;
	case 10812ULL: goto x86_l_2a3c;
	case 10815ULL: goto x86_l_2a3f;
	case 10821ULL: goto x86_l_2a45;
	case 10825ULL: goto x86_l_2a49;
	case 10830ULL: goto x86_l_2a4e;
	case 10835ULL: goto x86_l_2a53;
	case 10840ULL: goto x86_l_2a58;
	case 10843ULL: goto x86_l_2a5b;
	case 10845ULL: goto x86_l_2a5d;
	case 10849ULL: goto x86_l_2a61;
	case 10854ULL: goto x86_l_2a66;
	case 10859ULL: goto x86_l_2a6b;
	case 10863ULL: goto x86_l_2a6f;
	case 10866ULL: goto x86_l_2a72;
	case 10870ULL: goto x86_l_2a76;
	case 10878ULL: goto x86_l_2a7e;
	case 10883ULL: goto x86_l_2a83;
	case 10890ULL: goto x86_l_2a8a;
	case 10895ULL: goto x86_l_2a8f;
	case 10897ULL: goto x86_l_2a91;
	case 10900ULL: goto x86_l_2a94;
	case 10906ULL: goto x86_l_2a9a;
	case 10912ULL: goto x86_l_2aa0;
	case 10915ULL: goto x86_l_2aa3;
	case 10918ULL: goto x86_l_2aa6;
	case 10924ULL: goto x86_l_2aac;
	case 10929ULL: goto x86_l_2ab1;
	case 10936ULL: goto x86_l_2ab8;
	case 10941ULL: goto x86_l_2abd;
	case 10943ULL: goto x86_l_2abf;
	case 10946ULL: goto x86_l_2ac2;
	case 10952ULL: goto x86_l_2ac8;
	case 10957ULL: goto x86_l_2acd;
	case 10963ULL: goto x86_l_2ad3;
	case 10968ULL: goto x86_l_2ad8;
	case 10971ULL: goto x86_l_2adb;
	case 10978ULL: goto x86_l_2ae2;
	case 10980ULL: goto x86_l_2ae4;
	case 10983ULL: goto x86_l_2ae7;
	case 10987ULL: goto x86_l_2aeb;
	case 10992ULL: goto x86_l_2af0;
	case 10997ULL: goto x86_l_2af5;
	case 11000ULL: goto x86_l_2af8;
	case 11002ULL: goto x86_l_2afa;
	case 11007ULL: goto x86_l_2aff;
	case 11010ULL: goto x86_l_2b02;
	case 11013ULL: goto x86_l_2b05;
	case 11015ULL: goto x86_l_2b07;
	case 11020ULL: goto x86_l_2b0c;
	case 11028ULL: goto x86_l_2b14;
	case 11034ULL: goto x86_l_2b1a;
	case 11040ULL: goto x86_l_2b20;
	case 11045ULL: goto x86_l_2b25;
	case 11049ULL: goto x86_l_2b29;
	case 11052ULL: goto x86_l_2b2c;
	case 11058ULL: goto x86_l_2b32;
	case 11061ULL: goto x86_l_2b35;
	case 11064ULL: goto x86_l_2b38;
	case 11067ULL: goto x86_l_2b3b;
	case 11069ULL: goto x86_l_2b3d;
	case 11071ULL: goto x86_l_2b3f;
	case 11074ULL: goto x86_l_2b42;
	case 11080ULL: goto x86_l_2b48;
	case 11082ULL: goto x86_l_2b4a;
	case 11088ULL: goto x86_l_2b50;
	case 11093ULL: goto x86_l_2b55;
	case 11097ULL: goto x86_l_2b59;
	case 11100ULL: goto x86_l_2b5c;
	case 11105ULL: goto x86_l_2b61;
	case 11109ULL: goto x86_l_2b65;
	case 11114ULL: goto x86_l_2b6a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_24a3:
	/* 0x24a3: cmp    r13,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 63ULL);
x86_l_24a7:
	/* 0x24a7: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_24ad:
	/* 0x24ad: lea    ecx,[r13+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_24b4:
	/* 0x24b4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24ba:
	/* 0x24ba: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_24be:
	/* 0x24be: mov    BYTE PTR [rax+0x43],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_24c1:
	/* 0x24c1: cmp    r13,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 64ULL);
x86_l_24c5:
	/* 0x24c5: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_24cb:
	/* 0x24cb: lea    ecx,[r13+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_24d2:
	/* 0x24d2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24d8:
	/* 0x24d8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_24dc:
	/* 0x24dc: mov    BYTE PTR [rax+0x44],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_24df:
	/* 0x24df: cmp    r13,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 65ULL);
x86_l_24e3:
	/* 0x24e3: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_24e9:
	/* 0x24e9: lea    ecx,[r13+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_24f0:
	/* 0x24f0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24f6:
	/* 0x24f6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_24fa:
	/* 0x24fa: mov    BYTE PTR [rax+0x45],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_24fd:
	/* 0x24fd: cmp    r13,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 66ULL);
x86_l_2501:
	/* 0x2501: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_2507:
	/* 0x2507: lea    ecx,[r13+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_250e:
	/* 0x250e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2514:
	/* 0x2514: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2518:
	/* 0x2518: mov    BYTE PTR [rax+0x46],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_251b:
	/* 0x251b: cmp    r13,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 67ULL);
x86_l_251f:
	/* 0x251f: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_2525:
	/* 0x2525: lea    ecx,[r13+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_252c:
	/* 0x252c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2532:
	/* 0x2532: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2536:
	/* 0x2536: mov    BYTE PTR [rax+0x47],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_2539:
	/* 0x2539: cmp    r13,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 68ULL);
x86_l_253d:
	/* 0x253d: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_2543:
	/* 0x2543: lea    ecx,[r13+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_254a:
	/* 0x254a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2550:
	/* 0x2550: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2554:
	/* 0x2554: mov    BYTE PTR [rax+0x48],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2557:
	/* 0x2557: cmp    r13,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 69ULL);
x86_l_255b:
	/* 0x255b: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_2561:
	/* 0x2561: lea    ecx,[r13+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_2568:
	/* 0x2568: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_256e:
	/* 0x256e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2572:
	/* 0x2572: mov    BYTE PTR [rax+0x49],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_2575:
	/* 0x2575: cmp    r13,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 70ULL);
x86_l_2579:
	/* 0x2579: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_257f:
	/* 0x257f: lea    ecx,[r13+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_2586:
	/* 0x2586: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_258c:
	/* 0x258c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2590:
	/* 0x2590: mov    BYTE PTR [rax+0x4a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_2593:
	/* 0x2593: cmp    r13,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 71ULL);
x86_l_2597:
	/* 0x2597: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_259d:
	/* 0x259d: lea    ecx,[r13+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_25a4:
	/* 0x25a4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25aa:
	/* 0x25aa: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_25ae:
	/* 0x25ae: mov    BYTE PTR [rax+0x4b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_25b1:
	/* 0x25b1: cmp    r13,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 72ULL);
x86_l_25b5:
	/* 0x25b5: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_25bb:
	/* 0x25bb: lea    ecx,[r13+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_25c2:
	/* 0x25c2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25c8:
	/* 0x25c8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_25cc:
	/* 0x25cc: mov    BYTE PTR [rax+0x4c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_25cf:
	/* 0x25cf: cmp    r13,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 73ULL);
x86_l_25d3:
	/* 0x25d3: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_25d9:
	/* 0x25d9: lea    ecx,[r13+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_25e0:
	/* 0x25e0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25e6:
	/* 0x25e6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_25ea:
	/* 0x25ea: mov    BYTE PTR [rax+0x4d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_25ed:
	/* 0x25ed: cmp    r13,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 74ULL);
x86_l_25f1:
	/* 0x25f1: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_25f7:
	/* 0x25f7: lea    ecx,[r13+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_25fe:
	/* 0x25fe: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2604:
	/* 0x2604: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2608:
	/* 0x2608: mov    BYTE PTR [rax+0x4e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_260b:
	/* 0x260b: cmp    r13,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 75ULL);
x86_l_260f:
	/* 0x260f: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_2615:
	/* 0x2615: lea    ecx,[r13+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_261c:
	/* 0x261c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2622:
	/* 0x2622: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2626:
	/* 0x2626: mov    BYTE PTR [rax+0x4f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_2629:
	/* 0x2629: cmp    r13,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 76ULL);
x86_l_262d:
	/* 0x262d: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_2633:
	/* 0x2633: lea    ecx,[r13+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_263a:
	/* 0x263a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2640:
	/* 0x2640: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2644:
	/* 0x2644: mov    BYTE PTR [rax+0x50],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2647:
	/* 0x2647: cmp    r13,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 77ULL);
x86_l_264b:
	/* 0x264b: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_2651:
	/* 0x2651: lea    ecx,[r13+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_2658:
	/* 0x2658: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_265e:
	/* 0x265e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2662:
	/* 0x2662: mov    BYTE PTR [rax+0x51],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_2665:
	/* 0x2665: cmp    r13,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 78ULL);
x86_l_2669:
	/* 0x2669: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_266f:
	/* 0x266f: lea    ecx,[r13+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_2676:
	/* 0x2676: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_267c:
	/* 0x267c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2680:
	/* 0x2680: mov    BYTE PTR [rax+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_2683:
	/* 0x2683: cmp    r13,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 79ULL);
x86_l_2687:
	/* 0x2687: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_268d:
	/* 0x268d: lea    ecx,[r13+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_2694:
	/* 0x2694: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_269a:
	/* 0x269a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_269e:
	/* 0x269e: mov    BYTE PTR [rax+0x53],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_26a1:
	/* 0x26a1: cmp    r13,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 80ULL);
x86_l_26a5:
	/* 0x26a5: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_26ab:
	/* 0x26ab: lea    ecx,[r13+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_26b2:
	/* 0x26b2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26b8:
	/* 0x26b8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_26bc:
	/* 0x26bc: mov    BYTE PTR [rax+0x54],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_26bf:
	/* 0x26bf: cmp    r13,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 81ULL);
x86_l_26c3:
	/* 0x26c3: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_26c9:
	/* 0x26c9: lea    ecx,[r13+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_26d0:
	/* 0x26d0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26d6:
	/* 0x26d6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_26da:
	/* 0x26da: mov    BYTE PTR [rax+0x55],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_26dd:
	/* 0x26dd: cmp    r13,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 82ULL);
x86_l_26e1:
	/* 0x26e1: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_26e7:
	/* 0x26e7: lea    ecx,[r13+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_26ee:
	/* 0x26ee: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26f4:
	/* 0x26f4: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_26f8:
	/* 0x26f8: mov    BYTE PTR [rax+0x56],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_26fb:
	/* 0x26fb: cmp    r13,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 83ULL);
x86_l_26ff:
	/* 0x26ff: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_2705:
	/* 0x2705: lea    ecx,[r13+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_270c:
	/* 0x270c: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2712:
	/* 0x2712: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2716:
	/* 0x2716: mov    BYTE PTR [rax+0x57],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_2719:
	/* 0x2719: cmp    r13,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 84ULL);
x86_l_271d:
	/* 0x271d: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_2723:
	/* 0x2723: lea    ecx,[r13+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_272a:
	/* 0x272a: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2730:
	/* 0x2730: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2734:
	/* 0x2734: mov    BYTE PTR [rax+0x58],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2737:
	/* 0x2737: cmp    r13,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 85ULL);
x86_l_273b:
	/* 0x273b: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_2741:
	/* 0x2741: lea    ecx,[r13+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_2748:
	/* 0x2748: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_274e:
	/* 0x274e: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2752:
	/* 0x2752: mov    BYTE PTR [rax+0x59],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_2755:
	/* 0x2755: cmp    r13,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 86ULL);
x86_l_2759:
	/* 0x2759: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_275f:
	/* 0x275f: lea    ecx,[r13+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_2766:
	/* 0x2766: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_276c:
	/* 0x276c: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2770:
	/* 0x2770: mov    BYTE PTR [rax+0x5a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_2773:
	/* 0x2773: cmp    r13,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 87ULL);
x86_l_2777:
	/* 0x2777: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_277d:
	/* 0x277d: lea    ecx,[r13+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_2784:
	/* 0x2784: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_278a:
	/* 0x278a: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_278e:
	/* 0x278e: mov    BYTE PTR [rax+0x5b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_2791:
	/* 0x2791: cmp    r13,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 88ULL);
x86_l_2795:
	/* 0x2795: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_279b:
	/* 0x279b: lea    ecx,[r13+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_27a2:
	/* 0x27a2: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27a8:
	/* 0x27a8: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_27ac:
	/* 0x27ac: mov    BYTE PTR [rax+0x5c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_27af:
	/* 0x27af: cmp    r13,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 89ULL);
x86_l_27b3:
	/* 0x27b3: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_27b9:
	/* 0x27b9: lea    ecx,[r13+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_27c0:
	/* 0x27c0: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27c6:
	/* 0x27c6: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_27ca:
	/* 0x27ca: mov    BYTE PTR [rax+0x5d],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_27cd:
	/* 0x27cd: cmp    r13,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 90ULL);
x86_l_27d1:
	/* 0x27d1: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_27d3:
	/* 0x27d3: lea    ecx,[r13+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_27da:
	/* 0x27da: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27e0:
	/* 0x27e0: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_27e4:
	/* 0x27e4: mov    BYTE PTR [rax+0x5e],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_27e7:
	/* 0x27e7: cmp    r13,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 91ULL);
x86_l_27eb:
	/* 0x27eb: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_27ed:
	/* 0x27ed: lea    ecx,[r13+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_27f4:
	/* 0x27f4: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27fa:
	/* 0x27fa: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_27fe:
	/* 0x27fe: mov    BYTE PTR [rax+0x5f],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_2801:
	/* 0x2801: cmp    r13,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 92ULL);
x86_l_2805:
	/* 0x2805: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_2807:
	/* 0x2807: lea    ecx,[r13+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_280e:
	/* 0x280e: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2814:
	/* 0x2814: movzx  ecx,BYTE PTR [rdx+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_8), 0ULL);
x86_l_2818:
	/* 0x2818: mov    BYTE PTR [rax+0x60],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_281b:
	/* 0x281b: cmp    r13,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 93ULL);
x86_l_281f:
	/* 0x281f: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2837;
	}
x86_l_2821:
	/* 0x2821: add    r13d,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_2828:
	/* 0x2828: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_282f:
	/* 0x282f: movzx  ecx,BYTE PTR [rdx+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_2834:
	/* 0x2834: mov    BYTE PTR [rax+0x61],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_2837:
	/* 0x2837: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_283c:
	/* 0x283c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2841:
	/* 0x2841: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_2844:
	/* 0x2844: jmp    3212 <generic_usdt_filter_arg_2+0x3212> */
	return 12818ULL;
x86_l_2849:
	/* 0x2849: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_284e:
	/* 0x284e: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2852:
	/* 0x2852: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2855:
	/* 0x2855: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2859:
	/* 0x2859: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2861:
	/* 0x2861: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2866:
	/* 0x2866: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_286d:
	/* 0x286d: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2872:
	/* 0x2872: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2874:
	/* 0x2874: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2877:
	/* 0x2877: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_287a:
	/* 0x287a: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_287d:
	/* 0x287d: je     3223 <generic_usdt_filter_arg_2+0x3223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12835ULL;
	}
x86_l_2883:
	/* 0x2883: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2888:
	/* 0x2888: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_288b:
	/* 0x288b: je     3223 <generic_usdt_filter_arg_2+0x3223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12835ULL;
	}
x86_l_2891:
	/* 0x2891: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2896:
	/* 0x2896: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_289d:
	/* 0x289d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28a2:
	/* 0x28a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28a4:
	/* 0x28a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28a7:
	/* 0x28a7: je     3220 <generic_usdt_filter_arg_2+0x3220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12832ULL;
	}
x86_l_28ad:
	/* 0x28ad: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28b2:
	/* 0x28b2: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_28b6:
	/* 0x28b6: cmp    r13d,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 255ULL);
x86_l_28bd:
	/* 0x28bd: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_28c2:
	/* 0x28c2: cmovb  esi,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_28c6:
	/* 0x28c6: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_28cd:
	/* 0x28cd: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28cf:
	/* 0x28cf: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_28d2:
	/* 0x28d2: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_28d6:
	/* 0x28d6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_28db:
	/* 0x28db: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_28de:
	/* 0x28de: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_28e0:
	/* 0x28e0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28e5:
	/* 0x28e5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28ea:
	/* 0x28ea: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_28ed:
	/* 0x28ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28ef:
	/* 0x28ef: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28f2:
	/* 0x28f2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28f5:
	/* 0x28f5: setne  r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_NE);
x86_l_28f9:
	/* 0x28f9: jmp    3223 <generic_usdt_filter_arg_2+0x3223> */
	return 12835ULL;
x86_l_28fe:
	/* 0x28fe: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_2901:
	/* 0x2901: je     2913 <generic_usdt_filter_arg_2+0x2913> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2913;
	}
x86_l_2903:
	/* 0x2903: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_2906:
	/* 0x2906: jne    32d0 <generic_usdt_filter_arg_2+0x32d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13008ULL;
	}
x86_l_290c:
	/* 0x290c: movzx  r8d,WORD PTR [rdi+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2911:
	/* 0x2911: jmp    2918 <generic_usdt_filter_arg_2+0x2918> */
	goto x86_l_2918;
x86_l_2913:
	/* 0x2913: movzx  r8d,WORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_2918:
	/* 0x2918: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_291a:
	/* 0x291a: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_291d:
	/* 0x291d: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2920:
	/* 0x2920: jmp    2969 <generic_usdt_filter_arg_2+0x2969> */
	goto x86_l_2969;
x86_l_2922:
	/* 0x2922: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_2925:
	/* 0x2925: je     2d83 <generic_usdt_filter_arg_2+0x2d83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11651ULL;
	}
x86_l_292b:
	/* 0x292b: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_292e:
	/* 0x292e: jne    32d0 <generic_usdt_filter_arg_2+0x32d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13008ULL;
	}
x86_l_2934:
	/* 0x2934: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2937:
	/* 0x2937: jne    2f49 <generic_usdt_filter_arg_2+0x2f49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12105ULL;
	}
x86_l_293d:
	/* 0x293d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2940:
	/* 0x2940: jne    2f56 <generic_usdt_filter_arg_2+0x2f56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12118ULL;
	}
x86_l_2946:
	/* 0x2946: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2949:
	/* 0x2949: jmp    2f65 <generic_usdt_filter_arg_2+0x2f65> */
	return 12133ULL;
x86_l_294e:
	/* 0x294e: mov    rdx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2952:
	/* 0x2952: mov    r9,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2956:
	/* 0x2956: jmp    295f <generic_usdt_filter_arg_2+0x295f> */
	goto x86_l_295f;
x86_l_2958:
	/* 0x2958: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_295b:
	/* 0x295b: mov    r9,QWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_295f:
	/* 0x295f: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_2962:
	/* 0x2962: shr    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2966:
	/* 0x2966: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2969:
	/* 0x2969: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_296c:
	/* 0x296c: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_296f:
	/* 0x296f: jg     2993 <generic_usdt_filter_arg_2+0x2993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2993;
	}
x86_l_2971:
	/* 0x2971: lea    ecx,[rax-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_2974:
	/* 0x2974: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2977:
	/* 0x2977: jb     29be <generic_usdt_filter_arg_2+0x29be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_29be;
	}
x86_l_2979:
	/* 0x2979: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_297c:
	/* 0x297c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_297f:
	/* 0x297f: jb     2a1b <generic_usdt_filter_arg_2+0x2a1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2a1b;
	}
x86_l_2985:
	/* 0x2985: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2988:
	/* 0x2988: je     2d88 <generic_usdt_filter_arg_2+0x2d88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11656ULL;
	}
x86_l_298e:
	/* 0x298e: jmp    32d0 <generic_usdt_filter_arg_2+0x32d0> */
	return 13008ULL;
x86_l_2993:
	/* 0x2993: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2996:
	/* 0x2996: ja     2a0f <generic_usdt_filter_arg_2+0x2a0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2a0f;
	}
x86_l_2998:
	/* 0x2998: mov    ecx,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5242880ULL);
x86_l_299d:
	/* 0x299d: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_29a0:
	/* 0x29a0: jb     2b55 <generic_usdt_filter_arg_2+0x2b55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2b55;
	}
x86_l_29a6:
	/* 0x29a6: mov    ecx,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10485760ULL);
x86_l_29ab:
	/* 0x29ab: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_29ae:
	/* 0x29ae: jb     2b6a <generic_usdt_filter_arg_2+0x2b6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2b6a;
	}
x86_l_29b4:
	/* 0x29b4: mov    ecx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 50331648ULL);
x86_l_29b9:
	/* 0x29b9: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_29bc:
	/* 0x29bc: jae    2a0f <generic_usdt_filter_arg_2+0x2a0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2a0f;
	}
x86_l_29be:
	/* 0x29be: movzx  eax,WORD PTR [rdi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_29c2:
	/* 0x29c2: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_29c5:
	/* 0x29c5: je     2b7f <generic_usdt_filter_arg_2+0x2b7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11135ULL;
	}
x86_l_29cb:
	/* 0x29cb: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_29ce:
	/* 0x29ce: jne    2c0a <generic_usdt_filter_arg_2+0x2c0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11274ULL;
	}
x86_l_29d4:
	/* 0x29d4: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_29d7:
	/* 0x29d7: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_29da:
	/* 0x29da: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29dd:
	/* 0x29dd: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_29e1:
	/* 0x29e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29e6:
	/* 0x29e6: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_29ed:
	/* 0x29ed: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_29f2:
	/* 0x29f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29f4:
	/* 0x29f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29f7:
	/* 0x29f7: je     2dfd <generic_usdt_filter_arg_2+0x2dfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11773ULL;
	}
x86_l_29fd:
	/* 0x29fd: mov    DWORD PTR [rsp+0x20],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953504ULL);
x86_l_2a05:
	/* 0x2a05: mov    DWORD PTR [rsp+0x24],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2a0a:
	/* 0x2a0a: jmp    2bd4 <generic_usdt_filter_arg_2+0x2bd4> */
	return 11220ULL;
x86_l_2a0f:
	/* 0x2a0f: add    eax,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_2a12:
	/* 0x2a12: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a15:
	/* 0x2a15: jae    32d0 <generic_usdt_filter_arg_2+0x32d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13008ULL;
	}
x86_l_2a1b:
	/* 0x2a1b: mov    r13d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_32);
x86_l_2a1e:
	/* 0x2a1e: movzx  eax,BYTE PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2a22:
	/* 0x2a22: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2a26:
	/* 0x2a26: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a2b:
	/* 0x2a2b: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2a32:
	/* 0x2a32: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_2a35:
	/* 0x2a35: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2a3a:
	/* 0x2a3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a3c:
	/* 0x2a3c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a3f:
	/* 0x2a3f: je     2f9a <generic_usdt_filter_arg_2+0x2f9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12186ULL;
	}
x86_l_2a45:
	/* 0x2a45: movzx  ecx,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2a49:
	/* 0x2a49: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a4e:
	/* 0x2a4e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2a53:
	/* 0x2a53: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a58:
	/* 0x2a58: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2a5b:
	/* 0x2a5b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2a5d:
	/* 0x2a5d: mov    edx,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2a61:
	/* 0x2a61: jmp    2dcb <generic_usdt_filter_arg_2+0x2dcb> */
	return 11723ULL;
x86_l_2a66:
	/* 0x2a66: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a6b:
	/* 0x2a6b: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a6f:
	/* 0x2a6f: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a72:
	/* 0x2a72: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a76:
	/* 0x2a76: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2a7e:
	/* 0x2a7e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a83:
	/* 0x2a83: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_2a8a:
	/* 0x2a8a: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a8f:
	/* 0x2a8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a91:
	/* 0x2a91: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a94:
	/* 0x2a94: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2a9a:
	/* 0x2a9a: je     32ae <generic_usdt_filter_arg_2+0x32ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12974ULL;
	}
x86_l_2aa0:
	/* 0x2aa0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2aa3:
	/* 0x2aa3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2aa6:
	/* 0x2aa6: je     32ae <generic_usdt_filter_arg_2+0x32ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12974ULL;
	}
x86_l_2aac:
	/* 0x2aac: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ab1:
	/* 0x2ab1: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_2ab8:
	/* 0x2ab8: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2abd:
	/* 0x2abd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2abf:
	/* 0x2abf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ac2:
	/* 0x2ac2: je     32ab <generic_usdt_filter_arg_2+0x32ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12971ULL;
	}
x86_l_2ac8:
	/* 0x2ac8: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2acd:
	/* 0x2acd: cmp    ecx,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_2ad3:
	/* 0x2ad3: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_2ad8:
	/* 0x2ad8: cmovb  esi,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2adb:
	/* 0x2adb: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_2ae2:
	/* 0x2ae2: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ae4:
	/* 0x2ae4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2ae7:
	/* 0x2ae7: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2aeb:
	/* 0x2aeb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2af0:
	/* 0x2af0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2af5:
	/* 0x2af5: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2af8:
	/* 0x2af8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2afa:
	/* 0x2afa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2aff:
	/* 0x2aff: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2b02:
	/* 0x2b02: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2b05:
	/* 0x2b05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b07:
	/* 0x2b07: jmp    329f <generic_usdt_filter_arg_2+0x329f> */
	return 12959ULL;
x86_l_2b0c:
	/* 0x2b0c: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2b14:
	/* 0x2b14: cmp    edx,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_2b1a:
	/* 0x2b1a: ja     2d7b <generic_usdt_filter_arg_2+0x2d7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11643ULL;
	}
x86_l_2b20:
	/* 0x2b20: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b25:
	/* 0x2b25: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b29:
	/* 0x2b29: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2b2c:
	/* 0x2b2c: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2b32:
	/* 0x2b32: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_2b35:
	/* 0x2b35: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_2b38:
	/* 0x2b38: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2b3b:
	/* 0x2b3b: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2b3d:
	/* 0x2b3d: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2b3f:
	/* 0x2b3f: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_2b42:
	/* 0x2b42: je     2fa2 <generic_usdt_filter_arg_2+0x2fa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12194ULL;
	}
x86_l_2b48:
	/* 0x2b48: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2b4a:
	/* 0x2b4a: jne    2fa2 <generic_usdt_filter_arg_2+0x2fa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12194ULL;
	}
x86_l_2b50:
	/* 0x2b50: jmp    2fb9 <generic_usdt_filter_arg_2+0x2fb9> */
	return 12217ULL;
x86_l_2b55:
	/* 0x2b55: movzx  eax,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2b59:
	/* 0x2b59: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b5c:
	/* 0x2b5c: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_2b61:
	/* 0x2b61: setb   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_B);
x86_l_2b65:
	/* 0x2b65: jmp    32d0 <generic_usdt_filter_arg_2+0x32d0> */
	return 13008ULL;
x86_l_2b6a:
	/* 0x2b6a: movzx  eax,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
	return 11118ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11118ULL: goto x86_l_2b6e;
	case 11121ULL: goto x86_l_2b71;
	case 11126ULL: goto x86_l_2b76;
	case 11130ULL: goto x86_l_2b7a;
	case 11135ULL: goto x86_l_2b7f;
	case 11140ULL: goto x86_l_2b84;
	case 11144ULL: goto x86_l_2b88;
	case 11147ULL: goto x86_l_2b8b;
	case 11150ULL: goto x86_l_2b8e;
	case 11154ULL: goto x86_l_2b92;
	case 11159ULL: goto x86_l_2b97;
	case 11166ULL: goto x86_l_2b9e;
	case 11171ULL: goto x86_l_2ba3;
	case 11173ULL: goto x86_l_2ba5;
	case 11176ULL: goto x86_l_2ba8;
	case 11182ULL: goto x86_l_2bae;
	case 11190ULL: goto x86_l_2bb6;
	case 11194ULL: goto x86_l_2bba;
	case 11198ULL: goto x86_l_2bbe;
	case 11203ULL: goto x86_l_2bc3;
	case 11208ULL: goto x86_l_2bc8;
	case 11212ULL: goto x86_l_2bcc;
	case 11216ULL: goto x86_l_2bd0;
	case 11220ULL: goto x86_l_2bd4;
	case 11225ULL: goto x86_l_2bd9;
	case 11230ULL: goto x86_l_2bde;
	case 11233ULL: goto x86_l_2be1;
	case 11235ULL: goto x86_l_2be3;
	case 11239ULL: goto x86_l_2be7;
	case 11242ULL: goto x86_l_2bea;
	case 11245ULL: goto x86_l_2bed;
	case 11251ULL: goto x86_l_2bf3;
	case 11254ULL: goto x86_l_2bf6;
	case 11257ULL: goto x86_l_2bf9;
	case 11259ULL: goto x86_l_2bfb;
	case 11262ULL: goto x86_l_2bfe;
	case 11265ULL: goto x86_l_2c01;
	case 11269ULL: goto x86_l_2c05;
	case 11274ULL: goto x86_l_2c0a;
	case 11276ULL: goto x86_l_2c0c;
	case 11280ULL: goto x86_l_2c10;
	case 11285ULL: goto x86_l_2c15;
	case 11288ULL: goto x86_l_2c18;
	case 11293ULL: goto x86_l_2c1d;
	case 11297ULL: goto x86_l_2c21;
	case 11303ULL: goto x86_l_2c27;
	case 11306ULL: goto x86_l_2c2a;
	case 11309ULL: goto x86_l_2c2d;
	case 11312ULL: goto x86_l_2c30;
	case 11315ULL: goto x86_l_2c33;
	case 11317ULL: goto x86_l_2c35;
	case 11321ULL: goto x86_l_2c39;
	case 11327ULL: goto x86_l_2c3f;
	case 11329ULL: goto x86_l_2c41;
	case 11335ULL: goto x86_l_2c47;
	case 11338ULL: goto x86_l_2c4a;
	case 11343ULL: goto x86_l_2c4f;
	case 11346ULL: goto x86_l_2c52;
	case 11349ULL: goto x86_l_2c55;
	case 11351ULL: goto x86_l_2c57;
	case 11354ULL: goto x86_l_2c5a;
	case 11358ULL: goto x86_l_2c5e;
	case 11363ULL: goto x86_l_2c63;
	case 11367ULL: goto x86_l_2c67;
	case 11369ULL: goto x86_l_2c69;
	case 11373ULL: goto x86_l_2c6d;
	case 11379ULL: goto x86_l_2c73;
	case 11382ULL: goto x86_l_2c76;
	case 11384ULL: goto x86_l_2c78;
	case 11389ULL: goto x86_l_2c7d;
	case 11394ULL: goto x86_l_2c82;
	case 11399ULL: goto x86_l_2c87;
	case 11403ULL: goto x86_l_2c8b;
	case 11406ULL: goto x86_l_2c8e;
	case 11410ULL: goto x86_l_2c92;
	case 11414ULL: goto x86_l_2c96;
	case 11417ULL: goto x86_l_2c99;
	case 11423ULL: goto x86_l_2c9f;
	case 11427ULL: goto x86_l_2ca3;
	case 11432ULL: goto x86_l_2ca8;
	case 11439ULL: goto x86_l_2caf;
	case 11444ULL: goto x86_l_2cb4;
	case 11447ULL: goto x86_l_2cb7;
	case 11449ULL: goto x86_l_2cb9;
	case 11452ULL: goto x86_l_2cbc;
	case 11457ULL: goto x86_l_2cc1;
	case 11464ULL: goto x86_l_2cc8;
	case 11467ULL: goto x86_l_2ccb;
	case 11469ULL: goto x86_l_2ccd;
	case 11472ULL: goto x86_l_2cd0;
	case 11477ULL: goto x86_l_2cd5;
	case 11480ULL: goto x86_l_2cd8;
	case 11486ULL: goto x86_l_2cde;
	case 11489ULL: goto x86_l_2ce1;
	case 11493ULL: goto x86_l_2ce5;
	case 11499ULL: goto x86_l_2ceb;
	case 11502ULL: goto x86_l_2cee;
	case 11507ULL: goto x86_l_2cf3;
	case 11512ULL: goto x86_l_2cf8;
	case 11515ULL: goto x86_l_2cfb;
	case 11519ULL: goto x86_l_2cff;
	case 11524ULL: goto x86_l_2d04;
	case 11527ULL: goto x86_l_2d07;
	case 11532ULL: goto x86_l_2d0c;
	case 11534ULL: goto x86_l_2d0e;
	case 11539ULL: goto x86_l_2d13;
	case 11542ULL: goto x86_l_2d16;
	case 11544ULL: goto x86_l_2d18;
	case 11549ULL: goto x86_l_2d1d;
	case 11553ULL: goto x86_l_2d21;
	case 11556ULL: goto x86_l_2d24;
	case 11559ULL: goto x86_l_2d27;
	case 11565ULL: goto x86_l_2d2d;
	case 11570ULL: goto x86_l_2d32;
	case 11573ULL: goto x86_l_2d35;
	case 11575ULL: goto x86_l_2d37;
	case 11579ULL: goto x86_l_2d3b;
	case 11583ULL: goto x86_l_2d3f;
	case 11587ULL: goto x86_l_2d43;
	case 11590ULL: goto x86_l_2d46;
	case 11596ULL: goto x86_l_2d4c;
	case 11598ULL: goto x86_l_2d4e;
	case 11604ULL: goto x86_l_2d54;
	case 11609ULL: goto x86_l_2d59;
	case 11615ULL: goto x86_l_2d5f;
	case 11620ULL: goto x86_l_2d64;
	case 11626ULL: goto x86_l_2d6a;
	case 11631ULL: goto x86_l_2d6f;
	case 11638ULL: goto x86_l_2d76;
	case 11643ULL: goto x86_l_2d7b;
	case 11646ULL: goto x86_l_2d7e;
	case 11651ULL: goto x86_l_2d83;
	case 11656ULL: goto x86_l_2d88;
	case 11660ULL: goto x86_l_2d8c;
	case 11664ULL: goto x86_l_2d90;
	case 11669ULL: goto x86_l_2d95;
	case 11676ULL: goto x86_l_2d9c;
	case 11679ULL: goto x86_l_2d9f;
	case 11684ULL: goto x86_l_2da4;
	case 11686ULL: goto x86_l_2da6;
	case 11689ULL: goto x86_l_2da9;
	case 11695ULL: goto x86_l_2daf;
	case 11699ULL: goto x86_l_2db3;
	case 11704ULL: goto x86_l_2db8;
	case 11709ULL: goto x86_l_2dbd;
	case 11714ULL: goto x86_l_2dc2;
	case 11717ULL: goto x86_l_2dc5;
	case 11719ULL: goto x86_l_2dc7;
	case 11723ULL: goto x86_l_2dcb;
	case 11725ULL: goto x86_l_2dcd;
	case 11728ULL: goto x86_l_2dd0;
	case 11730ULL: goto x86_l_2dd2;
	case 11735ULL: goto x86_l_2dd7;
	case 11738ULL: goto x86_l_2dda;
	case 11740ULL: goto x86_l_2ddc;
	case 11743ULL: goto x86_l_2ddf;
	case 11746ULL: goto x86_l_2de2;
	case 11748ULL: goto x86_l_2de4;
	case 11753ULL: goto x86_l_2de9;
	case 11756ULL: goto x86_l_2dec;
	case 11758ULL: goto x86_l_2dee;
	case 11761ULL: goto x86_l_2df1;
	case 11764ULL: goto x86_l_2df4;
	case 11768ULL: goto x86_l_2df8;
	case 11773ULL: goto x86_l_2dfd;
	case 11777ULL: goto x86_l_2e01;
	case 11780ULL: goto x86_l_2e04;
	case 11783ULL: goto x86_l_2e07;
	case 11785ULL: goto x86_l_2e09;
	case 11788ULL: goto x86_l_2e0c;
	case 11791ULL: goto x86_l_2e0f;
	case 11795ULL: goto x86_l_2e13;
	case 11800ULL: goto x86_l_2e18;
	case 11803ULL: goto x86_l_2e1b;
	case 11806ULL: goto x86_l_2e1e;
	case 11808ULL: goto x86_l_2e20;
	case 11810ULL: goto x86_l_2e22;
	case 11813ULL: goto x86_l_2e25;
	case 11818ULL: goto x86_l_2e2a;
	case 11822ULL: goto x86_l_2e2e;
	case 11824ULL: goto x86_l_2e30;
	case 11827ULL: goto x86_l_2e33;
	case 11833ULL: goto x86_l_2e39;
	case 11836ULL: goto x86_l_2e3c;
	case 11838ULL: goto x86_l_2e3e;
	case 11842ULL: goto x86_l_2e42;
	case 11847ULL: goto x86_l_2e47;
	case 11852ULL: goto x86_l_2e4c;
	case 11856ULL: goto x86_l_2e50;
	case 11859ULL: goto x86_l_2e53;
	case 11863ULL: goto x86_l_2e57;
	case 11867ULL: goto x86_l_2e5b;
	case 11871ULL: goto x86_l_2e5f;
	case 11874ULL: goto x86_l_2e62;
	case 11880ULL: goto x86_l_2e68;
	case 11885ULL: goto x86_l_2e6d;
	case 11892ULL: goto x86_l_2e74;
	case 11897ULL: goto x86_l_2e79;
	case 11900ULL: goto x86_l_2e7c;
	case 11902ULL: goto x86_l_2e7e;
	case 11905ULL: goto x86_l_2e81;
	case 11910ULL: goto x86_l_2e86;
	case 11917ULL: goto x86_l_2e8d;
	case 11920ULL: goto x86_l_2e90;
	case 11922ULL: goto x86_l_2e92;
	case 11925ULL: goto x86_l_2e95;
	case 11930ULL: goto x86_l_2e9a;
	case 11933ULL: goto x86_l_2e9d;
	case 11939ULL: goto x86_l_2ea3;
	case 11942ULL: goto x86_l_2ea6;
	case 11946ULL: goto x86_l_2eaa;
	case 11952ULL: goto x86_l_2eb0;
	case 11955ULL: goto x86_l_2eb3;
	case 11960ULL: goto x86_l_2eb8;
	case 11964ULL: goto x86_l_2ebc;
	case 11969ULL: goto x86_l_2ec1;
	case 11974ULL: goto x86_l_2ec6;
	case 11977ULL: goto x86_l_2ec9;
	case 11981ULL: goto x86_l_2ecd;
	case 11986ULL: goto x86_l_2ed2;
	case 11989ULL: goto x86_l_2ed5;
	case 11991ULL: goto x86_l_2ed7;
	case 11996ULL: goto x86_l_2edc;
	case 11999ULL: goto x86_l_2edf;
	case 12001ULL: goto x86_l_2ee1;
	case 12006ULL: goto x86_l_2ee6;
	case 12011ULL: goto x86_l_2eeb;
	case 12015ULL: goto x86_l_2eef;
	case 12018ULL: goto x86_l_2ef2;
	case 12020ULL: goto x86_l_2ef4;
	case 12026ULL: goto x86_l_2efa;
	case 12031ULL: goto x86_l_2eff;
	case 12034ULL: goto x86_l_2f02;
	case 12036ULL: goto x86_l_2f04;
	case 12040ULL: goto x86_l_2f08;
	case 12044ULL: goto x86_l_2f0c;
	case 12049ULL: goto x86_l_2f11;
	case 12055ULL: goto x86_l_2f17;
	case 12060ULL: goto x86_l_2f1c;
	case 12066ULL: goto x86_l_2f22;
	case 12071ULL: goto x86_l_2f27;
	case 12077ULL: goto x86_l_2f2d;
	case 12082ULL: goto x86_l_2f32;
	case 12088ULL: goto x86_l_2f38;
	case 12093ULL: goto x86_l_2f3d;
	case 12100ULL: goto x86_l_2f44;
	case 12105ULL: goto x86_l_2f49;
	case 12108ULL: goto x86_l_2f4c;
	case 12111ULL: goto x86_l_2f4f;
	case 12113ULL: goto x86_l_2f51;
	case 12116ULL: goto x86_l_2f54;
	case 12118ULL: goto x86_l_2f56;
	case 12123ULL: goto x86_l_2f5b;
	case 12126ULL: goto x86_l_2f5e;
	case 12128ULL: goto x86_l_2f60;
	case 12131ULL: goto x86_l_2f63;
	case 12133ULL: goto x86_l_2f65;
	case 12136ULL: goto x86_l_2f68;
	case 12140ULL: goto x86_l_2f6c;
	case 12144ULL: goto x86_l_2f70;
	case 12149ULL: goto x86_l_2f75;
	case 12156ULL: goto x86_l_2f7c;
	case 12161ULL: goto x86_l_2f81;
	case 12163ULL: goto x86_l_2f83;
	case 12166ULL: goto x86_l_2f86;
	case 12168ULL: goto x86_l_2f88;
	case 12171ULL: goto x86_l_2f8b;
	case 12176ULL: goto x86_l_2f90;
	case 12181ULL: goto x86_l_2f95;
	case 12186ULL: goto x86_l_2f9a;
	case 12189ULL: goto x86_l_2f9d;
	case 12194ULL: goto x86_l_2fa2;
	case 12197ULL: goto x86_l_2fa5;
	case 12199ULL: goto x86_l_2fa7;
	case 12201ULL: goto x86_l_2fa9;
	case 12203ULL: goto x86_l_2fab;
	case 12206ULL: goto x86_l_2fae;
	case 12211ULL: goto x86_l_2fb3;
	case 12215ULL: goto x86_l_2fb7;
	case 12217ULL: goto x86_l_2fb9;
	case 12220ULL: goto x86_l_2fbc;
	case 12226ULL: goto x86_l_2fc2;
	case 12229ULL: goto x86_l_2fc5;
	case 12231ULL: goto x86_l_2fc7;
	case 12235ULL: goto x86_l_2fcb;
	case 12239ULL: goto x86_l_2fcf;
	case 12242ULL: goto x86_l_2fd2;
	case 12246ULL: goto x86_l_2fd6;
	case 12250ULL: goto x86_l_2fda;
	case 12254ULL: goto x86_l_2fde;
	case 12257ULL: goto x86_l_2fe1;
	case 12263ULL: goto x86_l_2fe7;
	case 12268ULL: goto x86_l_2fec;
	case 12275ULL: goto x86_l_2ff3;
	case 12280ULL: goto x86_l_2ff8;
	case 12283ULL: goto x86_l_2ffb;
	case 12285ULL: goto x86_l_2ffd;
	case 12288ULL: goto x86_l_3000;
	case 12293ULL: goto x86_l_3005;
	case 12300ULL: goto x86_l_300c;
	case 12303ULL: goto x86_l_300f;
	case 12305ULL: goto x86_l_3011;
	case 12313ULL: goto x86_l_3019;
	case 12316ULL: goto x86_l_301c;
	case 12321ULL: goto x86_l_3021;
	case 12324ULL: goto x86_l_3024;
	case 12330ULL: goto x86_l_302a;
	case 12339ULL: goto x86_l_3033;
	case 12343ULL: goto x86_l_3037;
	case 12349ULL: goto x86_l_303d;
	case 12354ULL: goto x86_l_3042;
	case 12359ULL: goto x86_l_3047;
	case 12362ULL: goto x86_l_304a;
	case 12366ULL: goto x86_l_304e;
	case 12371ULL: goto x86_l_3053;
	case 12374ULL: goto x86_l_3056;
	case 12379ULL: goto x86_l_305b;
	case 12381ULL: goto x86_l_305d;
	case 12386ULL: goto x86_l_3062;
	case 12389ULL: goto x86_l_3065;
	case 12391ULL: goto x86_l_3067;
	case 12396ULL: goto x86_l_306c;
	case 12401ULL: goto x86_l_3071;
	case 12405ULL: goto x86_l_3075;
	case 12408ULL: goto x86_l_3078;
	case 12410ULL: goto x86_l_307a;
	case 12416ULL: goto x86_l_3080;
	case 12421ULL: goto x86_l_3085;
	case 12429ULL: goto x86_l_308d;
	case 12431ULL: goto x86_l_308f;
	case 12435ULL: goto x86_l_3093;
	case 12439ULL: goto x86_l_3097;
	case 12444ULL: goto x86_l_309c;
	case 12450ULL: goto x86_l_30a2;
	case 12455ULL: goto x86_l_30a7;
	case 12461ULL: goto x86_l_30ad;
	case 12466ULL: goto x86_l_30b2;
	case 12472ULL: goto x86_l_30b8;
	case 12477ULL: goto x86_l_30bd;
	case 12483ULL: goto x86_l_30c3;
	case 12488ULL: goto x86_l_30c8;
	case 12495ULL: goto x86_l_30cf;
	case 12500ULL: goto x86_l_30d4;
	case 12503ULL: goto x86_l_30d7;
	case 12509ULL: goto x86_l_30dd;
	case 12514ULL: goto x86_l_30e2;
	case 12520ULL: goto x86_l_30e8;
	case 12525ULL: goto x86_l_30ed;
	case 12531ULL: goto x86_l_30f3;
	case 12536ULL: goto x86_l_30f8;
	case 12543ULL: goto x86_l_30ff;
	case 12548ULL: goto x86_l_3104;
	case 12551ULL: goto x86_l_3107;
	case 12554ULL: goto x86_l_310a;
	case 12559ULL: goto x86_l_310f;
	case 12564ULL: goto x86_l_3114;
	case 12570ULL: goto x86_l_311a;
	case 12575ULL: goto x86_l_311f;
	case 12581ULL: goto x86_l_3125;
	case 12586ULL: goto x86_l_312a;
	case 12592ULL: goto x86_l_3130;
	case 12597ULL: goto x86_l_3135;
	case 12604ULL: goto x86_l_313c;
	case 12609ULL: goto x86_l_3141;
	case 12614ULL: goto x86_l_3146;
	case 12620ULL: goto x86_l_314c;
	case 12625ULL: goto x86_l_3151;
	case 12631ULL: goto x86_l_3157;
	case 12636ULL: goto x86_l_315c;
	case 12642ULL: goto x86_l_3162;
	case 12647ULL: goto x86_l_3167;
	case 12654ULL: goto x86_l_316e;
	case 12659ULL: goto x86_l_3173;
	case 12664ULL: goto x86_l_3178;
	case 12671ULL: goto x86_l_317f;
	case 12673ULL: goto x86_l_3181;
	case 12678ULL: goto x86_l_3186;
	case 12685ULL: goto x86_l_318d;
	case 12687ULL: goto x86_l_318f;
	case 12692ULL: goto x86_l_3194;
	case 12699ULL: goto x86_l_319b;
	case 12701ULL: goto x86_l_319d;
	case 12706ULL: goto x86_l_31a2;
	case 12713ULL: goto x86_l_31a9;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2b6e:
	/* 0x2b6e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b71:
	/* 0x2b71: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_2b76:
	/* 0x2b76: setae  r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_AE);
x86_l_2b7a:
	/* 0x2b7a: jmp    32d0 <generic_usdt_filter_arg_2+0x32d0> */
	return 13008ULL;
x86_l_2b7f:
	/* 0x2b7f: mov    QWORD PTR [rsp+0x10],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b84:
	/* 0x2b84: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b88:
	/* 0x2b88: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_2b8b:
	/* 0x2b8b: mov    eax,DWORD PTR [rsi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2b8e:
	/* 0x2b8e: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2b92:
	/* 0x2b92: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b97:
	/* 0x2b97: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_2b9e:
	/* 0x2b9e: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2ba3:
	/* 0x2ba3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ba5:
	/* 0x2ba5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ba8:
	/* 0x2ba8: je     2dfd <generic_usdt_filter_arg_2+0x2dfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dfd;
	}
x86_l_2bae:
	/* 0x2bae: mov    DWORD PTR [rsp+0x20],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953600ULL);
x86_l_2bb6:
	/* 0x2bb6: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bba:
	/* 0x2bba: mov    DWORD PTR [rsp+0x24],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2bbe:
	/* 0x2bbe: mov    DWORD PTR [rsp+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2bc3:
	/* 0x2bc3: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bc8:
	/* 0x2bc8: mov    DWORD PTR [rsp+0x2c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2bcc:
	/* 0x2bcc: shr    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2bd0:
	/* 0x2bd0: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bd4:
	/* 0x2bd4: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2bd9:
	/* 0x2bd9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2bde:
	/* 0x2bde: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2be1:
	/* 0x2be1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2be3:
	/* 0x2be3: mov    ecx,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2be7:
	/* 0x2be7: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_2bea:
	/* 0x2bea: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2bed:
	/* 0x2bed: jb     2e09 <generic_usdt_filter_arg_2+0x2e09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2e09;
	}
x86_l_2bf3:
	/* 0x2bf3: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_2bf6:
	/* 0x2bf6: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2bf9:
	/* 0x2bf9: ja     2c0a <generic_usdt_filter_arg_2+0x2c0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2c0a;
	}
x86_l_2bfb:
	/* 0x2bfb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bfe:
	/* 0x2bfe: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_2c01:
	/* 0x2c01: movzx  r15d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2c05:
	/* 0x2c05: jmp    32d0 <generic_usdt_filter_arg_2+0x32d0> */
	return 13008ULL;
x86_l_2c0a:
	/* 0x2c0a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c0c:
	/* 0x2c0c: movzx  r15d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2c10:
	/* 0x2c10: jmp    32d0 <generic_usdt_filter_arg_2+0x32d0> */
	return 13008ULL;
x86_l_2c15:
	/* 0x2c15: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c18:
	/* 0x2c18: jmp    322a <generic_usdt_filter_arg_2+0x322a> */
	return 12842ULL;
x86_l_2c1d:
	/* 0x2c1d: movzx  eax,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2c21:
	/* 0x2c21: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2c27:
	/* 0x2c27: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_2c2a:
	/* 0x2c2a: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_2c2d:
	/* 0x2c2d: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2c30:
	/* 0x2c30: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_2c33:
	/* 0x2c33: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2c35:
	/* 0x2c35: test   r13w,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_16);
x86_l_2c39:
	/* 0x2c39: je     2e18 <generic_usdt_filter_arg_2+0x2e18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e18;
	}
x86_l_2c3f:
	/* 0x2c3f: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2c41:
	/* 0x2c41: jne    2e18 <generic_usdt_filter_arg_2+0x2e18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e18;
	}
x86_l_2c47:
	/* 0x2c47: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_2c4a:
	/* 0x2c4a: jmp    2e30 <generic_usdt_filter_arg_2+0x2e30> */
	goto x86_l_2e30;
x86_l_2c4f:
	/* 0x2c4f: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2c52:
	/* 0x2c52: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_2c55:
	/* 0x2c55: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c57:
	/* 0x2c57: mov    r8d,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2c5a:
	/* 0x2c5a: add    r8d,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2c5e:
	/* 0x2c5e: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2c63:
	/* 0x2c63: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2c67:
	/* 0x2c67: ja     2c78 <generic_usdt_filter_arg_2+0x2c78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2c78;
	}
x86_l_2c69:
	/* 0x2c69: movzx  eax,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2c6d:
	/* 0x2c6d: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2c73:
	/* 0x2c73: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2c76:
	/* 0x2c76: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2c78:
	/* 0x2c78: mov    DWORD PTR [rsp+0x4c],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2c7d:
	/* 0x2c7d: mov    QWORD PTR [rsp+0x38],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2c82:
	/* 0x2c82: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c87:
	/* 0x2c87: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c8b:
	/* 0x2c8b: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2c8e:
	/* 0x2c8e: mov    eax,DWORD PTR [rsi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2c92:
	/* 0x2c92: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2c96:
	/* 0x2c96: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2c99:
	/* 0x2c99: je     2d7b <generic_usdt_filter_arg_2+0x2d7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d7b;
	}
x86_l_2c9f:
	/* 0x2c9f: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ca3:
	/* 0x2ca3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ca8:
	/* 0x2ca8: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2caf:
	/* 0x2caf: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2cb4:
	/* 0x2cb4: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2cb7:
	/* 0x2cb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cb9:
	/* 0x2cb9: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2cbc:
	/* 0x2cbc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cc1:
	/* 0x2cc1: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2cc8:
	/* 0x2cc8: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2ccb:
	/* 0x2ccb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ccd:
	/* 0x2ccd: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cd0:
	/* 0x2cd0: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2cd5:
	/* 0x2cd5: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2cd8:
	/* 0x2cd8: je     32ae <generic_usdt_filter_arg_2+0x32ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12974ULL;
	}
x86_l_2cde:
	/* 0x2cde: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ce1:
	/* 0x2ce1: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ce5:
	/* 0x2ce5: je     32b2 <generic_usdt_filter_arg_2+0x32b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12978ULL;
	}
x86_l_2ceb:
	/* 0x2ceb: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2cee:
	/* 0x2cee: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2cf3:
	/* 0x2cf3: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2cf8:
	/* 0x2cf8: mov    BYTE PTR [rax],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cfb:
	/* 0x2cfb: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2cff:
	/* 0x2cff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d04:
	/* 0x2d04: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_2d07:
	/* 0x2d07: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d0c:
	/* 0x2d0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d0e:
	/* 0x2d0e: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_2d13:
	/* 0x2d13: cmp    esi,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_2d16:
	/* 0x2d16: jbe    2d37 <generic_usdt_filter_arg_2+0x2d37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2d37;
	}
x86_l_2d18:
	/* 0x2d18: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d1d:
	/* 0x2d1d: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2d21:
	/* 0x2d21: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2d24:
	/* 0x2d24: sub    esi,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d27:
	/* 0x2d27: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2d2d:
	/* 0x2d2d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d32:
	/* 0x2d32: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2d35:
	/* 0x2d35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d37:
	/* 0x2d37: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2d3b:
	/* 0x2d3b: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2d3f:
	/* 0x2d3f: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d43:
	/* 0x2d43: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d46:
	/* 0x2d46: jg     30d4 <generic_usdt_filter_arg_2+0x30d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_30d4;
	}
x86_l_2d4c:
	/* 0x2d4c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d4e:
	/* 0x2d4e: je     3173 <generic_usdt_filter_arg_2+0x3173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3173;
	}
x86_l_2d54:
	/* 0x2d54: cmp    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2d59:
	/* 0x2d59: je     318f <generic_usdt_filter_arg_2+0x318f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_318f;
	}
x86_l_2d5f:
	/* 0x2d5f: cmp    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_2d64:
	/* 0x2d64: jne    32ab <generic_usdt_filter_arg_2+0x32ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12971ULL;
	}
x86_l_2d6a:
	/* 0x2d6a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d6f:
	/* 0x2d6f: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2d76:
	/* 0x2d76: jmp    31a9 <generic_usdt_filter_arg_2+0x31a9> */
	goto x86_l_31a9;
x86_l_2d7b:
	/* 0x2d7b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d7e:
	/* 0x2d7e: jmp    32b2 <generic_usdt_filter_arg_2+0x32b2> */
	return 12978ULL;
x86_l_2d83:
	/* 0x2d83: movzx  r15d,WORD PTR [rdi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2d88:
	/* 0x2d88: movzx  eax,BYTE PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2d8c:
	/* 0x2d8c: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2d90:
	/* 0x2d90: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d95:
	/* 0x2d95: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2d9c:
	/* 0x2d9c: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_2d9f:
	/* 0x2d9f: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2da4:
	/* 0x2da4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2da6:
	/* 0x2da6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2da9:
	/* 0x2da9: je     2f9a <generic_usdt_filter_arg_2+0x2f9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f9a;
	}
x86_l_2daf:
	/* 0x2daf: movzx  ecx,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2db3:
	/* 0x2db3: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2db8:
	/* 0x2db8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2dbd:
	/* 0x2dbd: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2dc2:
	/* 0x2dc2: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2dc5:
	/* 0x2dc5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2dc7:
	/* 0x2dc7: mov    edx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2dcb:
	/* 0x2dcb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2dcd:
	/* 0x2dcd: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_2dd0:
	/* 0x2dd0: ja     2df4 <generic_usdt_filter_arg_2+0x2df4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2df4;
	}
x86_l_2dd2:
	/* 0x2dd2: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_2dd7:
	/* 0x2dd7: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2dda:
	/* 0x2dda: jae    2de4 <generic_usdt_filter_arg_2+0x2de4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2de4;
	}
x86_l_2ddc:
	/* 0x2ddc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ddf:
	/* 0x2ddf: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_2de2:
	/* 0x2de2: jmp    2df4 <generic_usdt_filter_arg_2+0x2df4> */
	goto x86_l_2df4;
x86_l_2de4:
	/* 0x2de4: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_2de9:
	/* 0x2de9: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2dec:
	/* 0x2dec: jae    2df4 <generic_usdt_filter_arg_2+0x2df4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2df4;
	}
x86_l_2dee:
	/* 0x2dee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2df1:
	/* 0x2df1: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_2df4:
	/* 0x2df4: movzx  r15d,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2df8:
	/* 0x2df8: jmp    32d0 <generic_usdt_filter_arg_2+0x32d0> */
	return 13008ULL;
x86_l_2dfd:
	/* 0x2dfd: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2e01:
	/* 0x2e01: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_2e04:
	/* 0x2e04: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_2e07:
	/* 0x2e07: jmp    2e0c <generic_usdt_filter_arg_2+0x2e0c> */
	goto x86_l_2e0c;
x86_l_2e09:
	/* 0x2e09: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e0c:
	/* 0x2e0c: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2e0f:
	/* 0x2e0f: movzx  r15d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e13:
	/* 0x2e13: jmp    32d0 <generic_usdt_filter_arg_2+0x32d0> */
	return 13008ULL;
x86_l_2e18:
	/* 0x2e18: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e1b:
	/* 0x2e1b: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_2e1e:
	/* 0x2e1e: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e20:
	/* 0x2e20: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2e22:
	/* 0x2e22: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2e25:
	/* 0x2e25: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2e2a:
	/* 0x2e2a: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2e2e:
	/* 0x2e2e: ja     2e3e <generic_usdt_filter_arg_2+0x2e3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2e3e;
	}
x86_l_2e30:
	/* 0x2e30: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e33:
	/* 0x2e33: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2e39:
	/* 0x2e39: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2e3c:
	/* 0x2e3c: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2e3e:
	/* 0x2e3e: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2e42:
	/* 0x2e42: mov    QWORD PTR [rsp+0x38],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e47:
	/* 0x2e47: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e4c:
	/* 0x2e4c: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e50:
	/* 0x2e50: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2e53:
	/* 0x2e53: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e57:
	/* 0x2e57: mov    eax,DWORD PTR [rsi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2e5b:
	/* 0x2e5b: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2e5f:
	/* 0x2e5f: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2e62:
	/* 0x2e62: je     3220 <generic_usdt_filter_arg_2+0x3220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12832ULL;
	}
x86_l_2e68:
	/* 0x2e68: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e6d:
	/* 0x2e6d: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2e74:
	/* 0x2e74: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e79:
	/* 0x2e79: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2e7c:
	/* 0x2e7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e7e:
	/* 0x2e7e: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2e81:
	/* 0x2e81: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e86:
	/* 0x2e86: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2e8d:
	/* 0x2e8d: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2e90:
	/* 0x2e90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e92:
	/* 0x2e92: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e95:
	/* 0x2e95: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e9a:
	/* 0x2e9a: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2e9d:
	/* 0x2e9d: je     3223 <generic_usdt_filter_arg_2+0x3223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12835ULL;
	}
x86_l_2ea3:
	/* 0x2ea3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ea6:
	/* 0x2ea6: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2eaa:
	/* 0x2eaa: je     3227 <generic_usdt_filter_arg_2+0x3227> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12839ULL;
	}
x86_l_2eb0:
	/* 0x2eb0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2eb3:
	/* 0x2eb3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eb8:
	/* 0x2eb8: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2ebc:
	/* 0x2ebc: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ec1:
	/* 0x2ec1: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ec6:
	/* 0x2ec6: mov    BYTE PTR [rax],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ec9:
	/* 0x2ec9: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2ecd:
	/* 0x2ecd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ed2:
	/* 0x2ed2: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_2ed5:
	/* 0x2ed5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ed7:
	/* 0x2ed7: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_2edc:
	/* 0x2edc: cmp    esi,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_2edf:
	/* 0x2edf: jbe    2f04 <generic_usdt_filter_arg_2+0x2f04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2f04;
	}
x86_l_2ee1:
	/* 0x2ee1: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ee6:
	/* 0x2ee6: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2eeb:
	/* 0x2eeb: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2eef:
	/* 0x2eef: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2ef2:
	/* 0x2ef2: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ef4:
	/* 0x2ef4: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2efa:
	/* 0x2efa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2eff:
	/* 0x2eff: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2f02:
	/* 0x2f02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f04:
	/* 0x2f04: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2f08:
	/* 0x2f08: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2f0c:
	/* 0x2f0c: cmp    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_2f11:
	/* 0x2f11: jg     310f <generic_usdt_filter_arg_2+0x310f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_310f;
	}
x86_l_2f17:
	/* 0x2f17: cmp    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2f1c:
	/* 0x2f1c: je     31c3 <generic_usdt_filter_arg_2+0x31c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12739ULL;
	}
x86_l_2f22:
	/* 0x2f22: cmp    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2f27:
	/* 0x2f27: je     31df <generic_usdt_filter_arg_2+0x31df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12767ULL;
	}
x86_l_2f2d:
	/* 0x2f2d: cmp    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_2f32:
	/* 0x2f32: jne    3220 <generic_usdt_filter_arg_2+0x3220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12832ULL;
	}
x86_l_2f38:
	/* 0x2f38: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f3d:
	/* 0x2f3d: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2f44:
	/* 0x2f44: jmp    31f9 <generic_usdt_filter_arg_2+0x31f9> */
	return 12793ULL;
x86_l_2f49:
	/* 0x2f49: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f4c:
	/* 0x2f4c: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2f4f:
	/* 0x2f4f: jne    2f5b <generic_usdt_filter_arg_2+0x2f5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f5b;
	}
x86_l_2f51:
	/* 0x2f51: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2f54:
	/* 0x2f54: je     2f5b <generic_usdt_filter_arg_2+0x2f5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f5b;
	}
x86_l_2f56:
	/* 0x2f56: movzx  r15d,BYTE PTR [rdx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_2f5b:
	/* 0x2f5b: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2f5e:
	/* 0x2f5e: je     2f65 <generic_usdt_filter_arg_2+0x2f65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f65;
	}
x86_l_2f60:
	/* 0x2f60: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2f63:
	/* 0x2f63: jne    2f9a <generic_usdt_filter_arg_2+0x2f9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f9a;
	}
x86_l_2f65:
	/* 0x2f65: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_2f68:
	/* 0x2f68: movzx  eax,BYTE PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2f6c:
	/* 0x2f6c: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2f70:
	/* 0x2f70: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f75:
	/* 0x2f75: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2f7c:
	/* 0x2f7c: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2f81:
	/* 0x2f81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f83:
	/* 0x2f83: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f86:
	/* 0x2f86: je     2f9a <generic_usdt_filter_arg_2+0x2f9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f9a;
	}
x86_l_2f88:
	/* 0x2f88: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_2f8b:
	/* 0x2f8b: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f90:
	/* 0x2f90: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2f95:
	/* 0x2f95: jmp    2dbd <generic_usdt_filter_arg_2+0x2dbd> */
	goto x86_l_2dbd;
x86_l_2f9a:
	/* 0x2f9a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f9d:
	/* 0x2f9d: jmp    32d0 <generic_usdt_filter_arg_2+0x32d0> */
	return 13008ULL;
x86_l_2fa2:
	/* 0x2fa2: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2fa5:
	/* 0x2fa5: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2fa7:
	/* 0x2fa7: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2fa9:
	/* 0x2fa9: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2fab:
	/* 0x2fab: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2fae:
	/* 0x2fae: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2fb3:
	/* 0x2fb3: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2fb7:
	/* 0x2fb7: ja     2fc7 <generic_usdt_filter_arg_2+0x2fc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2fc7;
	}
x86_l_2fb9:
	/* 0x2fb9: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2fbc:
	/* 0x2fbc: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2fc2:
	/* 0x2fc2: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2fc5:
	/* 0x2fc5: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2fc7:
	/* 0x2fc7: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2fcb:
	/* 0x2fcb: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2fcf:
	/* 0x2fcf: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2fd2:
	/* 0x2fd2: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fd6:
	/* 0x2fd6: mov    eax,DWORD PTR [rcx+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2fda:
	/* 0x2fda: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2fde:
	/* 0x2fde: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2fe1:
	/* 0x2fe1: je     32ab <generic_usdt_filter_arg_2+0x32ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12971ULL;
	}
x86_l_2fe7:
	/* 0x2fe7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fec:
	/* 0x2fec: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2ff3:
	/* 0x2ff3: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ff8:
	/* 0x2ff8: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2ffb:
	/* 0x2ffb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ffd:
	/* 0x2ffd: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3000:
	/* 0x3000: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3005:
	/* 0x3005: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_300c:
	/* 0x300c: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_300f:
	/* 0x300f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3011:
	/* 0x3011: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3019:
	/* 0x3019: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_301c:
	/* 0x301c: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3021:
	/* 0x3021: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_3024:
	/* 0x3024: je     32ae <generic_usdt_filter_arg_2+0x32ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12974ULL;
	}
x86_l_302a:
	/* 0x302a: cmp    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_3033:
	/* 0x3033: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3037:
	/* 0x3037: je     32b2 <generic_usdt_filter_arg_2+0x32b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12978ULL;
	}
x86_l_303d:
	/* 0x303d: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3042:
	/* 0x3042: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3047:
	/* 0x3047: mov    BYTE PTR [rax],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_304a:
	/* 0x304a: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_304e:
	/* 0x304e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3053:
	/* 0x3053: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_3056:
	/* 0x3056: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_305b:
	/* 0x305b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_305d:
	/* 0x305d: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_3062:
	/* 0x3062: cmp    esi,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_3065:
	/* 0x3065: jbe    308f <generic_usdt_filter_arg_2+0x308f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_308f;
	}
x86_l_3067:
	/* 0x3067: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_306c:
	/* 0x306c: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3071:
	/* 0x3071: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3075:
	/* 0x3075: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_3078:
	/* 0x3078: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_307a:
	/* 0x307a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3080:
	/* 0x3080: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3085:
	/* 0x3085: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_308d:
	/* 0x308d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_308f:
	/* 0x308f: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3093:
	/* 0x3093: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3097:
	/* 0x3097: cmp    DWORD PTR [rsp+0x38],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168578ULL);
x86_l_309c:
	/* 0x309c: jg     3141 <generic_usdt_filter_arg_2+0x3141> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3141;
	}
x86_l_30a2:
	/* 0x30a2: cmp    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_30a7:
	/* 0x30a7: je     324e <generic_usdt_filter_arg_2+0x324e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12878ULL;
	}
x86_l_30ad:
	/* 0x30ad: cmp    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_30b2:
	/* 0x30b2: je     326a <generic_usdt_filter_arg_2+0x326a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12906ULL;
	}
x86_l_30b8:
	/* 0x30b8: cmp    DWORD PTR [rsp+0x38],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168578ULL);
x86_l_30bd:
	/* 0x30bd: jne    32ab <generic_usdt_filter_arg_2+0x32ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12971ULL;
	}
x86_l_30c3:
	/* 0x30c3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30c8:
	/* 0x30c8: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_30cf:
	/* 0x30cf: jmp    3284 <generic_usdt_filter_arg_2+0x3284> */
	return 12932ULL;
x86_l_30d4:
	/* 0x30d4: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_30d7:
	/* 0x30d7: je     3181 <generic_usdt_filter_arg_2+0x3181> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3181;
	}
x86_l_30dd:
	/* 0x30dd: cmp    DWORD PTR [rsp+0x8],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738372ULL);
x86_l_30e2:
	/* 0x30e2: je     319d <generic_usdt_filter_arg_2+0x319d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_319d;
	}
x86_l_30e8:
	/* 0x30e8: cmp    DWORD PTR [rsp+0x8],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738373ULL);
x86_l_30ed:
	/* 0x30ed: jne    32ab <generic_usdt_filter_arg_2+0x32ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12971ULL;
	}
x86_l_30f3:
	/* 0x30f3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30f8:
	/* 0x30f8: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_30ff:
	/* 0x30ff: jmp    31a9 <generic_usdt_filter_arg_2+0x31a9> */
	goto x86_l_31a9;
x86_l_3104:
	/* 0x3104: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3107:
	/* 0x3107: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_310a:
	/* 0x310a: jmp    3227 <generic_usdt_filter_arg_2+0x3227> */
	return 12839ULL;
x86_l_310f:
	/* 0x310f: cmp    DWORD PTR [rsp+0x8],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738371ULL);
x86_l_3114:
	/* 0x3114: je     31d1 <generic_usdt_filter_arg_2+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12753ULL;
	}
x86_l_311a:
	/* 0x311a: cmp    DWORD PTR [rsp+0x8],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738372ULL);
x86_l_311f:
	/* 0x311f: je     31ed <generic_usdt_filter_arg_2+0x31ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12781ULL;
	}
x86_l_3125:
	/* 0x3125: cmp    DWORD PTR [rsp+0x8],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738373ULL);
x86_l_312a:
	/* 0x312a: jne    3220 <generic_usdt_filter_arg_2+0x3220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12832ULL;
	}
x86_l_3130:
	/* 0x3130: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3135:
	/* 0x3135: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_313c:
	/* 0x313c: jmp    31f9 <generic_usdt_filter_arg_2+0x31f9> */
	return 12793ULL;
x86_l_3141:
	/* 0x3141: cmp    DWORD PTR [rsp+0x38],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168579ULL);
x86_l_3146:
	/* 0x3146: je     325c <generic_usdt_filter_arg_2+0x325c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12892ULL;
	}
x86_l_314c:
	/* 0x314c: cmp    DWORD PTR [rsp+0x38],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168580ULL);
x86_l_3151:
	/* 0x3151: je     3278 <generic_usdt_filter_arg_2+0x3278> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12920ULL;
	}
x86_l_3157:
	/* 0x3157: cmp    DWORD PTR [rsp+0x38],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168581ULL);
x86_l_315c:
	/* 0x315c: jne    32ab <generic_usdt_filter_arg_2+0x32ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12971ULL;
	}
x86_l_3162:
	/* 0x3162: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3167:
	/* 0x3167: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_316e:
	/* 0x316e: jmp    3284 <generic_usdt_filter_arg_2+0x3284> */
	return 12932ULL;
x86_l_3173:
	/* 0x3173: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3178:
	/* 0x3178: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_317f:
	/* 0x317f: jmp    31a9 <generic_usdt_filter_arg_2+0x31a9> */
	goto x86_l_31a9;
x86_l_3181:
	/* 0x3181: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3186:
	/* 0x3186: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_318d:
	/* 0x318d: jmp    31a9 <generic_usdt_filter_arg_2+0x31a9> */
	goto x86_l_31a9;
x86_l_318f:
	/* 0x318f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3194:
	/* 0x3194: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_319b:
	/* 0x319b: jmp    31a9 <generic_usdt_filter_arg_2+0x31a9> */
	goto x86_l_31a9;
x86_l_319d:
	/* 0x319d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31a2:
	/* 0x31a2: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_31a9:
	/* 0x31a9: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
	return 12718ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12718ULL: goto x86_l_31ae;
	case 12720ULL: goto x86_l_31b0;
	case 12723ULL: goto x86_l_31b3;
	case 12729ULL: goto x86_l_31b9;
	case 12734ULL: goto x86_l_31be;
	case 12739ULL: goto x86_l_31c3;
	case 12744ULL: goto x86_l_31c8;
	case 12751ULL: goto x86_l_31cf;
	case 12753ULL: goto x86_l_31d1;
	case 12758ULL: goto x86_l_31d6;
	case 12765ULL: goto x86_l_31dd;
	case 12767ULL: goto x86_l_31df;
	case 12772ULL: goto x86_l_31e4;
	case 12779ULL: goto x86_l_31eb;
	case 12781ULL: goto x86_l_31ed;
	case 12786ULL: goto x86_l_31f2;
	case 12793ULL: goto x86_l_31f9;
	case 12798ULL: goto x86_l_31fe;
	case 12800ULL: goto x86_l_3200;
	case 12803ULL: goto x86_l_3203;
	case 12805ULL: goto x86_l_3205;
	case 12810ULL: goto x86_l_320a;
	case 12813ULL: goto x86_l_320d;
	case 12818ULL: goto x86_l_3212;
	case 12820ULL: goto x86_l_3214;
	case 12823ULL: goto x86_l_3217;
	case 12826ULL: goto x86_l_321a;
	case 12830ULL: goto x86_l_321e;
	case 12832ULL: goto x86_l_3220;
	case 12835ULL: goto x86_l_3223;
	case 12839ULL: goto x86_l_3227;
	case 12842ULL: goto x86_l_322a;
	case 12845ULL: goto x86_l_322d;
	case 12851ULL: goto x86_l_3233;
	case 12853ULL: goto x86_l_3235;
	case 12863ULL: goto x86_l_323f;
	case 12867ULL: goto x86_l_3243;
	case 12873ULL: goto x86_l_3249;
	case 12878ULL: goto x86_l_324e;
	case 12883ULL: goto x86_l_3253;
	case 12890ULL: goto x86_l_325a;
	case 12892ULL: goto x86_l_325c;
	case 12897ULL: goto x86_l_3261;
	case 12904ULL: goto x86_l_3268;
	case 12906ULL: goto x86_l_326a;
	case 12911ULL: goto x86_l_326f;
	case 12918ULL: goto x86_l_3276;
	case 12920ULL: goto x86_l_3278;
	case 12925ULL: goto x86_l_327d;
	case 12932ULL: goto x86_l_3284;
	case 12937ULL: goto x86_l_3289;
	case 12939ULL: goto x86_l_328b;
	case 12942ULL: goto x86_l_328e;
	case 12944ULL: goto x86_l_3290;
	case 12949ULL: goto x86_l_3295;
	case 12952ULL: goto x86_l_3298;
	case 12957ULL: goto x86_l_329d;
	case 12959ULL: goto x86_l_329f;
	case 12962ULL: goto x86_l_32a2;
	case 12965ULL: goto x86_l_32a5;
	case 12969ULL: goto x86_l_32a9;
	case 12971ULL: goto x86_l_32ab;
	case 12974ULL: goto x86_l_32ae;
	case 12978ULL: goto x86_l_32b2;
	case 12981ULL: goto x86_l_32b5;
	case 12984ULL: goto x86_l_32b8;
	case 12986ULL: goto x86_l_32ba;
	case 12988ULL: goto x86_l_32bc;
	case 12998ULL: goto x86_l_32c6;
	case 13002ULL: goto x86_l_32ca;
	case 13004ULL: goto x86_l_32cc;
	case 13008ULL: goto x86_l_32d0;
	case 13011ULL: goto x86_l_32d3;
	case 13013ULL: goto x86_l_32d5;
	case 13017ULL: goto x86_l_32d9;
	case 13019ULL: goto x86_l_32db;
	case 13021ULL: goto x86_l_32dd;
	case 13023ULL: goto x86_l_32df;
	case 13027ULL: goto x86_l_32e3;
	case 13029ULL: goto x86_l_32e5;
	case 13033ULL: goto x86_l_32e9;
	case 13039ULL: goto x86_l_32ef;
	case 13042ULL: goto x86_l_32f2;
	case 13048ULL: goto x86_l_32f8;
	case 13052ULL: goto x86_l_32fc;
	case 13058ULL: goto x86_l_3302;
	case 13060ULL: goto x86_l_3304;
	case 13064ULL: goto x86_l_3308;
	case 13070ULL: goto x86_l_330e;
	case 13074ULL: goto x86_l_3312;
	case 13080ULL: goto x86_l_3318;
	case 13084ULL: goto x86_l_331c;
	case 13090ULL: goto x86_l_3322;
	case 13094ULL: goto x86_l_3326;
	case 13100ULL: goto x86_l_332c;
	case 13103ULL: goto x86_l_332f;
	case 13108ULL: goto x86_l_3334;
	case 13115ULL: goto x86_l_333b;
	case 13120ULL: goto x86_l_3340;
	case 13127ULL: goto x86_l_3347;
	case 13130ULL: goto x86_l_334a;
	case 13135ULL: goto x86_l_334f;
	case 13137ULL: goto x86_l_3351;
	case 13142ULL: goto x86_l_3356;
	case 13149ULL: goto x86_l_335d;
	case 13152ULL: goto x86_l_3360;
	case 13157ULL: goto x86_l_3365;
	case 13159ULL: goto x86_l_3367;
	case 13161ULL: goto x86_l_3369;
	case 13168ULL: goto x86_l_3370;
	case 13170ULL: goto x86_l_3372;
	case 13171ULL: goto x86_l_3373;
	case 13176ULL: goto x86_l_3378;
	case 13179ULL: goto x86_l_337b;
	case 13187ULL: goto x86_l_3383;
	case 13189ULL: goto x86_l_3385;
	case 13195ULL: goto x86_l_338b;
	case 13203ULL: goto x86_l_3393;
	case 13205ULL: goto x86_l_3395;
	case 13211ULL: goto x86_l_339b;
	case 13219ULL: goto x86_l_33a3;
	case 13221ULL: goto x86_l_33a5;
	case 13227ULL: goto x86_l_33ab;
	case 13235ULL: goto x86_l_33b3;
	case 13237ULL: goto x86_l_33b5;
	case 13243ULL: goto x86_l_33bb;
	case 13251ULL: goto x86_l_33c3;
	case 13253ULL: goto x86_l_33c5;
	case 13259ULL: goto x86_l_33cb;
	case 13267ULL: goto x86_l_33d3;
	case 13269ULL: goto x86_l_33d5;
	case 13276ULL: goto x86_l_33dc;
	case 13281ULL: goto x86_l_33e1;
	case 13288ULL: goto x86_l_33e8;
	case 13291ULL: goto x86_l_33eb;
	case 13296ULL: goto x86_l_33f0;
	case 13298ULL: goto x86_l_33f2;
	case 13302ULL: goto x86_l_33f6;
	case 13307ULL: goto x86_l_33fb;
	case 13309ULL: goto x86_l_33fd;
	case 13314ULL: goto x86_l_3402;
	case 13319ULL: goto x86_l_3407;
	case 13324ULL: goto x86_l_340c;
	case 13331ULL: goto x86_l_3413;
	case 13336ULL: goto x86_l_3418;
	case 13338ULL: goto x86_l_341a;
	case 13341ULL: goto x86_l_341d;
	case 13347ULL: goto x86_l_3423;
	case 13352ULL: goto x86_l_3428;
	case 13359ULL: goto x86_l_342f;
	case 13364ULL: goto x86_l_3434;
	case 13366ULL: goto x86_l_3436;
	default: return 0xffffffffffffffffULL;
	}
x86_l_31ae:
	/* 0x31ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31b0:
	/* 0x31b0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31b3:
	/* 0x31b3: je     32ab <generic_usdt_filter_arg_2+0x32ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32ab;
	}
x86_l_31b9:
	/* 0x31b9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_31be:
	/* 0x31be: jmp    3295 <generic_usdt_filter_arg_2+0x3295> */
	goto x86_l_3295;
x86_l_31c3:
	/* 0x31c3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31c8:
	/* 0x31c8: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_31cf:
	/* 0x31cf: jmp    31f9 <generic_usdt_filter_arg_2+0x31f9> */
	goto x86_l_31f9;
x86_l_31d1:
	/* 0x31d1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31d6:
	/* 0x31d6: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_31dd:
	/* 0x31dd: jmp    31f9 <generic_usdt_filter_arg_2+0x31f9> */
	goto x86_l_31f9;
x86_l_31df:
	/* 0x31df: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31e4:
	/* 0x31e4: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_31eb:
	/* 0x31eb: jmp    31f9 <generic_usdt_filter_arg_2+0x31f9> */
	goto x86_l_31f9;
x86_l_31ed:
	/* 0x31ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31f2:
	/* 0x31f2: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_31f9:
	/* 0x31f9: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_31fe:
	/* 0x31fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3200:
	/* 0x3200: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3203:
	/* 0x3203: je     3220 <generic_usdt_filter_arg_2+0x3220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3220;
	}
x86_l_3205:
	/* 0x3205: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_320a:
	/* 0x320a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_320d:
	/* 0x320d: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3212:
	/* 0x3212: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3214:
	/* 0x3214: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3217:
	/* 0x3217: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_321a:
	/* 0x321a: setne  r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_NE);
x86_l_321e:
	/* 0x321e: jmp    3223 <generic_usdt_filter_arg_2+0x3223> */
	goto x86_l_3223;
x86_l_3220:
	/* 0x3220: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3223:
	/* 0x3223: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3227:
	/* 0x3227: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_322a:
	/* 0x322a: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_322d:
	/* 0x322d: ja     32d0 <generic_usdt_filter_arg_2+0x32d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_32d0;
	}
x86_l_3233:
	/* 0x3233: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3235:
	/* 0x3235: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_323f:
	/* 0x323f: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3243:
	/* 0x3243: jb     32cc <generic_usdt_filter_arg_2+0x32cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_32cc;
	}
x86_l_3249:
	/* 0x3249: jmp    32d0 <generic_usdt_filter_arg_2+0x32d0> */
	goto x86_l_32d0;
x86_l_324e:
	/* 0x324e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3253:
	/* 0x3253: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_325a:
	/* 0x325a: jmp    3284 <generic_usdt_filter_arg_2+0x3284> */
	goto x86_l_3284;
x86_l_325c:
	/* 0x325c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3261:
	/* 0x3261: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_3268:
	/* 0x3268: jmp    3284 <generic_usdt_filter_arg_2+0x3284> */
	goto x86_l_3284;
x86_l_326a:
	/* 0x326a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_326f:
	/* 0x326f: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_3276:
	/* 0x3276: jmp    3284 <generic_usdt_filter_arg_2+0x3284> */
	goto x86_l_3284;
x86_l_3278:
	/* 0x3278: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_327d:
	/* 0x327d: mov    rdi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_3284:
	/* 0x3284: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3289:
	/* 0x3289: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_328b:
	/* 0x328b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_328e:
	/* 0x328e: je     32ab <generic_usdt_filter_arg_2+0x32ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32ab;
	}
x86_l_3290:
	/* 0x3290: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3295:
	/* 0x3295: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3298:
	/* 0x3298: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_329d:
	/* 0x329d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_329f:
	/* 0x329f: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32a2:
	/* 0x32a2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32a5:
	/* 0x32a5: setne  r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_NE);
x86_l_32a9:
	/* 0x32a9: jmp    32ae <generic_usdt_filter_arg_2+0x32ae> */
	goto x86_l_32ae;
x86_l_32ab:
	/* 0x32ab: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32ae:
	/* 0x32ae: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32b2:
	/* 0x32b2: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_32b5:
	/* 0x32b5: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_32b8:
	/* 0x32b8: ja     32d0 <generic_usdt_filter_arg_2+0x32d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_32d0;
	}
x86_l_32ba:
	/* 0x32ba: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32bc:
	/* 0x32bc: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_32c6:
	/* 0x32c6: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_32ca:
	/* 0x32ca: jae    32d0 <generic_usdt_filter_arg_2+0x32d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_32d0;
	}
x86_l_32cc:
	/* 0x32cc: xor    r15,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_32d0:
	/* 0x32d0: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_32d3:
	/* 0x32d3: je     32df <generic_usdt_filter_arg_2+0x32df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32df;
	}
x86_l_32d5:
	/* 0x32d5: cmp    rbp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 1ULL);
x86_l_32d9:
	/* 0x32d9: je     3351 <generic_usdt_filter_arg_2+0x3351> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3351;
	}
x86_l_32db:
	/* 0x32db: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_32dd:
	/* 0x32dd: jne    3334 <generic_usdt_filter_arg_2+0x3334> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3334;
	}
x86_l_32df:
	/* 0x32df: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_32e3:
	/* 0x32e3: jg     3304 <generic_usdt_filter_arg_2+0x3304> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3304;
	}
x86_l_32e5:
	/* 0x32e5: cmp    r12d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_32e9:
	/* 0x32e9: je     3378 <generic_usdt_filter_arg_2+0x3378> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3378;
	}
x86_l_32ef:
	/* 0x32ef: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_32f2:
	/* 0x32f2: je     3385 <generic_usdt_filter_arg_2+0x3385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3385;
	}
x86_l_32f8:
	/* 0x32f8: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_32fc:
	/* 0x32fc: je     3395 <generic_usdt_filter_arg_2+0x3395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3395;
	}
x86_l_3302:
	/* 0x3302: jmp    3322 <generic_usdt_filter_arg_2+0x3322> */
	goto x86_l_3322;
x86_l_3304:
	/* 0x3304: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_3308:
	/* 0x3308: je     33a5 <generic_usdt_filter_arg_2+0x33a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33a5;
	}
x86_l_330e:
	/* 0x330e: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_3312:
	/* 0x3312: je     33b5 <generic_usdt_filter_arg_2+0x33b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33b5;
	}
x86_l_3318:
	/* 0x3318: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_331c:
	/* 0x331c: je     33c5 <generic_usdt_filter_arg_2+0x33c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33c5;
	}
x86_l_3322:
	/* 0x3322: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_3326:
	/* 0x3326: jg     33f2 <generic_usdt_filter_arg_2+0x33f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_33f2;
	}
x86_l_332c:
	/* 0x332c: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_332f:
	/* 0x332f: jmp    33d5 <generic_usdt_filter_arg_2+0x33d5> */
	goto x86_l_33d5;
x86_l_3334:
	/* 0x3334: mov    DWORD PTR [r14+0x5ef4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_333b:
	/* 0x333b: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3340:
	/* 0x3340: mov    rsi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_3347:
	/* 0x3347: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_334a:
	/* 0x334a: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_334f:
	/* 0x334f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3351:
	/* 0x3351: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3356:
	/* 0x3356: mov    rsi,QWORD PTR [rip+0xb1af] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_335d:
	/* 0x335d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3360:
	/* 0x3360: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3365:
	/* 0x3365: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3367:
	/* 0x3367: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3369:
	/* 0x3369: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_3370:
	/* 0x3370: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3372:
	/* 0x3372: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3373:
	/* 0x3373: jmp    343b <generic_usdt_filter_arg_2+0x343b> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3378:
	/* 0x3378: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_337b:
	/* 0x337b: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_3383:
	/* 0x3383: jne    33d5 <generic_usdt_filter_arg_2+0x33d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_33d5;
	}
x86_l_3385:
	/* 0x3385: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_338b:
	/* 0x338b: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_3393:
	/* 0x3393: jne    33d5 <generic_usdt_filter_arg_2+0x33d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_33d5;
	}
x86_l_3395:
	/* 0x3395: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_339b:
	/* 0x339b: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_33a3:
	/* 0x33a3: jne    33d5 <generic_usdt_filter_arg_2+0x33d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_33d5;
	}
x86_l_33a5:
	/* 0x33a5: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_33ab:
	/* 0x33ab: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_33b3:
	/* 0x33b3: jne    33d5 <generic_usdt_filter_arg_2+0x33d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_33d5;
	}
x86_l_33b5:
	/* 0x33b5: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_33bb:
	/* 0x33bb: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_33c3:
	/* 0x33c3: jne    33d5 <generic_usdt_filter_arg_2+0x33d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_33d5;
	}
x86_l_33c5:
	/* 0x33c5: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_33cb:
	/* 0x33cb: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_33d3:
	/* 0x33d3: je     33f2 <generic_usdt_filter_arg_2+0x33f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33f2;
	}
x86_l_33d5:
	/* 0x33d5: mov    DWORD PTR [r14+0x5ef0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_33dc:
	/* 0x33dc: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_33e1:
	/* 0x33e1: mov    rsi,QWORD PTR [rip+0xb1b2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_33e8:
	/* 0x33e8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_33eb:
	/* 0x33eb: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_33f0:
	/* 0x33f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33f2:
	/* 0x33f2: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_33f6:
	/* 0x33f6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_33fb:
	/* 0x33fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33fd:
	/* 0x33fd: mov    QWORD PTR [rsp+0x50],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3402:
	/* 0x3402: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3407:
	/* 0x3407: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_340c:
	/* 0x340c: mov    rdi,QWORD PTR [rip+0xb1b2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_3413:
	/* 0x3413: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3418:
	/* 0x3418: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_341a:
	/* 0x341a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_341d:
	/* 0x341d: je     3367 <generic_usdt_filter_arg_2+0x3367> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3367;
	}
x86_l_3423:
	/* 0x3423: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3428:
	/* 0x3428: mov    rdi,QWORD PTR [rip+0xb1b2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_342f:
	/* 0x342f: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3434:
	/* 0x3434: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3436:
	/* 0x3436: jmp    3367 <generic_usdt_filter_arg_2+0x3367> */
	goto x86_l_3367;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 11360U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1827ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1834ULL && __x86_pc <= 3689ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3694ULL && __x86_pc <= 5603ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5609ULL && __x86_pc <= 7466ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7469ULL && __x86_pc <= 9376ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9379ULL && __x86_pc <= 11114ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 11118ULL && __x86_pc <= 12713ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12718ULL && __x86_pc <= 13366ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

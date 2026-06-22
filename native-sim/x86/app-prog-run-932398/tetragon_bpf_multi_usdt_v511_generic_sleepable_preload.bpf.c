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
	case 34ULL: goto x86_l_22;
	case 41ULL: goto x86_l_29;
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
	case 237ULL: goto x86_l_ed;
	case 241ULL: goto x86_l_f1;
	case 246ULL: goto x86_l_f6;
	case 252ULL: goto x86_l_fc;
	case 260ULL: goto x86_l_104;
	case 264ULL: goto x86_l_108;
	case 267ULL: goto x86_l_10b;
	case 274ULL: goto x86_l_112;
	case 280ULL: goto x86_l_118;
	case 285ULL: goto x86_l_11d;
	case 287ULL: goto x86_l_11f;
	case 289ULL: goto x86_l_121;
	case 294ULL: goto x86_l_126;
	case 299ULL: goto x86_l_12b;
	case 304ULL: goto x86_l_130;
	case 308ULL: goto x86_l_134;
	case 312ULL: goto x86_l_138;
	case 316ULL: goto x86_l_13c;
	case 323ULL: goto x86_l_143;
	case 329ULL: goto x86_l_149;
	case 333ULL: goto x86_l_14d;
	case 338ULL: goto x86_l_152;
	case 340ULL: goto x86_l_154;
	case 342ULL: goto x86_l_156;
	case 344ULL: goto x86_l_158;
	case 348ULL: goto x86_l_15c;
	case 351ULL: goto x86_l_15f;
	case 357ULL: goto x86_l_165;
	case 360ULL: goto x86_l_168;
	case 366ULL: goto x86_l_16e;
	case 371ULL: goto x86_l_173;
	case 374ULL: goto x86_l_176;
	case 380ULL: goto x86_l_17c;
	case 383ULL: goto x86_l_17f;
	case 389ULL: goto x86_l_185;
	case 394ULL: goto x86_l_18a;
	case 399ULL: goto x86_l_18f;
	case 402ULL: goto x86_l_192;
	case 407ULL: goto x86_l_197;
	case 409ULL: goto x86_l_199;
	case 414ULL: goto x86_l_19e;
	case 416ULL: goto x86_l_1a0;
	case 422ULL: goto x86_l_1a6;
	case 424ULL: goto x86_l_1a8;
	case 429ULL: goto x86_l_1ad;
	case 437ULL: goto x86_l_1b5;
	case 445ULL: goto x86_l_1bd;
	case 451ULL: goto x86_l_1c3;
	case 454ULL: goto x86_l_1c6;
	case 460ULL: goto x86_l_1cc;
	case 463ULL: goto x86_l_1cf;
	case 469ULL: goto x86_l_1d5;
	case 472ULL: goto x86_l_1d8;
	case 478ULL: goto x86_l_1de;
	case 486ULL: goto x86_l_1e6;
	case 489ULL: goto x86_l_1e9;
	case 495ULL: goto x86_l_1ef;
	case 500ULL: goto x86_l_1f4;
	case 503ULL: goto x86_l_1f7;
	case 509ULL: goto x86_l_1fd;
	case 514ULL: goto x86_l_202;
	case 517ULL: goto x86_l_205;
	case 523ULL: goto x86_l_20b;
	case 528ULL: goto x86_l_210;
	case 533ULL: goto x86_l_215;
	case 536ULL: goto x86_l_218;
	case 542ULL: goto x86_l_21e;
	case 547ULL: goto x86_l_223;
	case 550ULL: goto x86_l_226;
	case 556ULL: goto x86_l_22c;
	case 559ULL: goto x86_l_22f;
	case 565ULL: goto x86_l_235;
	case 570ULL: goto x86_l_23a;
	case 573ULL: goto x86_l_23d;
	case 578ULL: goto x86_l_242;
	case 581ULL: goto x86_l_245;
	case 586ULL: goto x86_l_24a;
	case 588ULL: goto x86_l_24c;
	case 590ULL: goto x86_l_24e;
	case 596ULL: goto x86_l_254;
	case 599ULL: goto x86_l_257;
	case 605ULL: goto x86_l_25d;
	case 608ULL: goto x86_l_260;
	case 613ULL: goto x86_l_265;
	case 618ULL: goto x86_l_26a;
	case 623ULL: goto x86_l_26f;
	case 625ULL: goto x86_l_271;
	case 627ULL: goto x86_l_273;
	case 633ULL: goto x86_l_279;
	case 638ULL: goto x86_l_27e;
	case 641ULL: goto x86_l_281;
	case 648ULL: goto x86_l_288;
	case 652ULL: goto x86_l_28c;
	case 657ULL: goto x86_l_291;
	case 660ULL: goto x86_l_294;
	case 665ULL: goto x86_l_299;
	case 668ULL: goto x86_l_29c;
	case 670ULL: goto x86_l_29e;
	case 673ULL: goto x86_l_2a1;
	case 679ULL: goto x86_l_2a7;
	case 684ULL: goto x86_l_2ac;
	case 686ULL: goto x86_l_2ae;
	case 692ULL: goto x86_l_2b4;
	case 700ULL: goto x86_l_2bc;
	case 705ULL: goto x86_l_2c1;
	case 708ULL: goto x86_l_2c4;
	case 714ULL: goto x86_l_2ca;
	case 719ULL: goto x86_l_2cf;
	case 722ULL: goto x86_l_2d2;
	case 728ULL: goto x86_l_2d8;
	case 736ULL: goto x86_l_2e0;
	case 739ULL: goto x86_l_2e3;
	case 745ULL: goto x86_l_2e9;
	case 750ULL: goto x86_l_2ee;
	case 755ULL: goto x86_l_2f3;
	case 758ULL: goto x86_l_2f6;
	case 764ULL: goto x86_l_2fc;
	case 769ULL: goto x86_l_301;
	case 772ULL: goto x86_l_304;
	case 778ULL: goto x86_l_30a;
	case 786ULL: goto x86_l_312;
	case 789ULL: goto x86_l_315;
	case 795ULL: goto x86_l_31b;
	case 800ULL: goto x86_l_320;
	case 805ULL: goto x86_l_325;
	case 808ULL: goto x86_l_328;
	case 814ULL: goto x86_l_32e;
	case 819ULL: goto x86_l_333;
	case 823ULL: goto x86_l_337;
	case 828ULL: goto x86_l_33c;
	case 832ULL: goto x86_l_340;
	case 839ULL: goto x86_l_347;
	case 844ULL: goto x86_l_34c;
	case 848ULL: goto x86_l_350;
	case 853ULL: goto x86_l_355;
	case 858ULL: goto x86_l_35a;
	case 862ULL: goto x86_l_35e;
	case 864ULL: goto x86_l_360;
	case 867ULL: goto x86_l_363;
	case 873ULL: goto x86_l_369;
	case 878ULL: goto x86_l_36e;
	case 883ULL: goto x86_l_373;
	case 886ULL: goto x86_l_376;
	case 891ULL: goto x86_l_37b;
	case 893ULL: goto x86_l_37d;
	case 895ULL: goto x86_l_37f;
	case 901ULL: goto x86_l_385;
	case 903ULL: goto x86_l_387;
	case 908ULL: goto x86_l_38c;
	case 913ULL: goto x86_l_391;
	case 916ULL: goto x86_l_394;
	case 919ULL: goto x86_l_397;
	case 926ULL: goto x86_l_39e;
	case 932ULL: goto x86_l_3a4;
	case 939ULL: goto x86_l_3ab;
	case 942ULL: goto x86_l_3ae;
	case 947ULL: goto x86_l_3b3;
	case 950ULL: goto x86_l_3b6;
	case 955ULL: goto x86_l_3bb;
	case 961ULL: goto x86_l_3c1;
	case 963ULL: goto x86_l_3c3;
	case 969ULL: goto x86_l_3c9;
	case 972ULL: goto x86_l_3cc;
	case 974ULL: goto x86_l_3ce;
	case 979ULL: goto x86_l_3d3;
	case 984ULL: goto x86_l_3d8;
	case 989ULL: goto x86_l_3dd;
	case 994ULL: goto x86_l_3e2;
	case 996ULL: goto x86_l_3e4;
	case 1001ULL: goto x86_l_3e9;
	case 1003ULL: goto x86_l_3eb;
	case 1009ULL: goto x86_l_3f1;
	case 1016ULL: goto x86_l_3f8;
	case 1022ULL: goto x86_l_3fe;
	case 1027ULL: goto x86_l_403;
	case 1032ULL: goto x86_l_408;
	case 1039ULL: goto x86_l_40f;
	case 1041ULL: goto x86_l_411;
	case 1046ULL: goto x86_l_416;
	case 1051ULL: goto x86_l_41b;
	case 1056ULL: goto x86_l_420;
	case 1061ULL: goto x86_l_425;
	case 1063ULL: goto x86_l_427;
	case 1068ULL: goto x86_l_42c;
	case 1070ULL: goto x86_l_42e;
	case 1076ULL: goto x86_l_434;
	case 1083ULL: goto x86_l_43b;
	case 1089ULL: goto x86_l_441;
	case 1094ULL: goto x86_l_446;
	case 1099ULL: goto x86_l_44b;
	case 1106ULL: goto x86_l_452;
	case 1108ULL: goto x86_l_454;
	case 1113ULL: goto x86_l_459;
	case 1118ULL: goto x86_l_45e;
	case 1123ULL: goto x86_l_463;
	case 1128ULL: goto x86_l_468;
	case 1130ULL: goto x86_l_46a;
	case 1135ULL: goto x86_l_46f;
	case 1137ULL: goto x86_l_471;
	case 1143ULL: goto x86_l_477;
	case 1150ULL: goto x86_l_47e;
	case 1156ULL: goto x86_l_484;
	case 1161ULL: goto x86_l_489;
	case 1166ULL: goto x86_l_48e;
	case 1173ULL: goto x86_l_495;
	case 1175ULL: goto x86_l_497;
	case 1180ULL: goto x86_l_49c;
	case 1185ULL: goto x86_l_4a1;
	case 1190ULL: goto x86_l_4a6;
	case 1195ULL: goto x86_l_4ab;
	case 1197ULL: goto x86_l_4ad;
	case 1202ULL: goto x86_l_4b2;
	case 1204ULL: goto x86_l_4b4;
	case 1210ULL: goto x86_l_4ba;
	case 1217ULL: goto x86_l_4c1;
	case 1223ULL: goto x86_l_4c7;
	case 1228ULL: goto x86_l_4cc;
	case 1233ULL: goto x86_l_4d1;
	case 1240ULL: goto x86_l_4d8;
	case 1242ULL: goto x86_l_4da;
	case 1247ULL: goto x86_l_4df;
	case 1252ULL: goto x86_l_4e4;
	case 1257ULL: goto x86_l_4e9;
	case 1262ULL: goto x86_l_4ee;
	case 1264ULL: goto x86_l_4f0;
	case 1269ULL: goto x86_l_4f5;
	case 1271ULL: goto x86_l_4f7;
	case 1277ULL: goto x86_l_4fd;
	case 1284ULL: goto x86_l_504;
	case 1290ULL: goto x86_l_50a;
	case 1295ULL: goto x86_l_50f;
	case 1300ULL: goto x86_l_514;
	case 1307ULL: goto x86_l_51b;
	case 1309ULL: goto x86_l_51d;
	case 1314ULL: goto x86_l_522;
	case 1319ULL: goto x86_l_527;
	case 1324ULL: goto x86_l_52c;
	case 1329ULL: goto x86_l_531;
	case 1331ULL: goto x86_l_533;
	case 1336ULL: goto x86_l_538;
	case 1338ULL: goto x86_l_53a;
	case 1344ULL: goto x86_l_540;
	case 1351ULL: goto x86_l_547;
	case 1357ULL: goto x86_l_54d;
	case 1362ULL: goto x86_l_552;
	case 1367ULL: goto x86_l_557;
	case 1374ULL: goto x86_l_55e;
	case 1376ULL: goto x86_l_560;
	case 1381ULL: goto x86_l_565;
	case 1386ULL: goto x86_l_56a;
	case 1391ULL: goto x86_l_56f;
	case 1396ULL: goto x86_l_574;
	case 1398ULL: goto x86_l_576;
	case 1403ULL: goto x86_l_57b;
	case 1405ULL: goto x86_l_57d;
	case 1411ULL: goto x86_l_583;
	case 1418ULL: goto x86_l_58a;
	case 1424ULL: goto x86_l_590;
	case 1429ULL: goto x86_l_595;
	case 1434ULL: goto x86_l_59a;
	case 1441ULL: goto x86_l_5a1;
	case 1443ULL: goto x86_l_5a3;
	case 1448ULL: goto x86_l_5a8;
	case 1453ULL: goto x86_l_5ad;
	case 1458ULL: goto x86_l_5b2;
	case 1463ULL: goto x86_l_5b7;
	case 1465ULL: goto x86_l_5b9;
	case 1470ULL: goto x86_l_5be;
	case 1472ULL: goto x86_l_5c0;
	case 1478ULL: goto x86_l_5c6;
	case 1485ULL: goto x86_l_5cd;
	case 1491ULL: goto x86_l_5d3;
	case 1496ULL: goto x86_l_5d8;
	case 1501ULL: goto x86_l_5dd;
	case 1508ULL: goto x86_l_5e4;
	case 1510ULL: goto x86_l_5e6;
	case 1515ULL: goto x86_l_5eb;
	case 1520ULL: goto x86_l_5f0;
	case 1525ULL: goto x86_l_5f5;
	case 1530ULL: goto x86_l_5fa;
	case 1532ULL: goto x86_l_5fc;
	case 1537ULL: goto x86_l_601;
	case 1539ULL: goto x86_l_603;
	case 1545ULL: goto x86_l_609;
	case 1551ULL: goto x86_l_60f;
	case 1557ULL: goto x86_l_615;
	case 1562ULL: goto x86_l_61a;
	case 1567ULL: goto x86_l_61f;
	case 1574ULL: goto x86_l_626;
	case 1580ULL: goto x86_l_62c;
	case 1585ULL: goto x86_l_631;
	case 1590ULL: goto x86_l_636;
	case 1593ULL: goto x86_l_639;
	case 1595ULL: goto x86_l_63b;
	case 1600ULL: goto x86_l_640;
	case 1605ULL: goto x86_l_645;
	case 1610ULL: goto x86_l_64a;
	case 1615ULL: goto x86_l_64f;
	case 1617ULL: goto x86_l_651;
	case 1622ULL: goto x86_l_656;
	case 1624ULL: goto x86_l_658;
	case 1630ULL: goto x86_l_65e;
	case 1637ULL: goto x86_l_665;
	case 1643ULL: goto x86_l_66b;
	case 1648ULL: goto x86_l_670;
	case 1653ULL: goto x86_l_675;
	case 1660ULL: goto x86_l_67c;
	case 1662ULL: goto x86_l_67e;
	case 1667ULL: goto x86_l_683;
	case 1672ULL: goto x86_l_688;
	case 1677ULL: goto x86_l_68d;
	case 1682ULL: goto x86_l_692;
	case 1684ULL: goto x86_l_694;
	case 1689ULL: goto x86_l_699;
	case 1691ULL: goto x86_l_69b;
	case 1697ULL: goto x86_l_6a1;
	case 1704ULL: goto x86_l_6a8;
	case 1710ULL: goto x86_l_6ae;
	case 1715ULL: goto x86_l_6b3;
	case 1720ULL: goto x86_l_6b8;
	case 1727ULL: goto x86_l_6bf;
	case 1729ULL: goto x86_l_6c1;
	case 1734ULL: goto x86_l_6c6;
	case 1739ULL: goto x86_l_6cb;
	case 1744ULL: goto x86_l_6d0;
	case 1749ULL: goto x86_l_6d5;
	case 1751ULL: goto x86_l_6d7;
	case 1756ULL: goto x86_l_6dc;
	case 1758ULL: goto x86_l_6de;
	case 1764ULL: goto x86_l_6e4;
	case 1771ULL: goto x86_l_6eb;
	case 1777ULL: goto x86_l_6f1;
	case 1782ULL: goto x86_l_6f6;
	case 1787ULL: goto x86_l_6fb;
	case 1794ULL: goto x86_l_702;
	case 1796ULL: goto x86_l_704;
	case 1801ULL: goto x86_l_709;
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
	/* 0xf: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_14:
	/* 0x14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16:
	/* 0x16: mov    DWORD PTR [rsp+0xbc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1d:
	/* 0x1d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22:
	/* 0x22: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_29:
	/* 0x29: lea    rsi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_31:
	/* 0x31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33:
	/* 0x33: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36:
	/* 0x36: je     4ec5 <generic_sleepable_preload+0x4ec5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20165ULL;
	}
x86_l_3c:
	/* 0x3c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3f:
	/* 0x3f: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_46:
	/* 0x46: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4b:
	/* 0x4b: lea    rcx,[r15+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_52:
	/* 0x52: mov    QWORD PTR [rsp+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_57:
	/* 0x57: lea    rcx,[r15+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5e:
	/* 0x5e: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_63:
	/* 0x63: lea    rcx,[r15+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_67:
	/* 0x67: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_6f:
	/* 0x6f: lea    rcx,[r15+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_73:
	/* 0x73: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_78:
	/* 0x78: lea    rcx,[r15+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7c:
	/* 0x7c: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_84:
	/* 0x84: lea    rcx,[r15+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_88:
	/* 0x88: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8d:
	/* 0x8d: lea    rcx,[r15+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_91:
	/* 0x91: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_99:
	/* 0x99: lea    rcx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9d:
	/* 0x9d: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a2:
	/* 0xa2: lea    rcx,[r15+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a6:
	/* 0xa6: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_ae:
	/* 0xae: lea    rcx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b2:
	/* 0xb2: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b7:
	/* 0xb7: lea    rcx,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bb:
	/* 0xbb: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c3:
	/* 0xc3: lea    rcx,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c7:
	/* 0xc7: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_cc:
	/* 0xcc: lea    rcx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d0:
	/* 0xd0: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d8:
	/* 0xd8: lea    rcx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dc:
	/* 0xdc: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e1:
	/* 0xe1: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e4:
	/* 0xe4: lea    rax,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e8:
	/* 0xe8: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ed:
	/* 0xed: lea    r12,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f1:
	/* 0xf1: mov    QWORD PTR [rsp+0x18],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f6:
	/* 0xf6: je     110f <generic_sleepable_preload+0x110f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4367ULL;
	}
x86_l_fc:
	/* 0xfc: mov    QWORD PTR [rsp+0xc0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_104:
	/* 0x104: lea    r14,[rdi+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_108:
	/* 0x108: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_10b:
	/* 0x10b: add    rbx,0x213 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 531ULL);
x86_l_112:
	/* 0x112: mov    r12d,0xbe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 190ULL);
x86_l_118:
	/* 0x118: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11d:
	/* 0x11d: jmp    149 <generic_sleepable_preload+0x149> */
	goto x86_l_149;
x86_l_11f:
	/* 0x11f: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_121:
	/* 0x121: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_126:
	/* 0x126: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12b:
	/* 0x12b: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_130:
	/* 0x130: add    r14,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_134:
	/* 0x134: add    rbx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_138:
	/* 0x138: add    r12,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_13c:
	/* 0x13c: cmp    r12,0x24e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 590ULL);
x86_l_143:
	/* 0x143: je     4ec5 <generic_sleepable_preload+0x4ec5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20165ULL;
	}
x86_l_149:
	/* 0x149: mov    eax,DWORD PTR [r14+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_14d:
	/* 0x14d: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_152:
	/* 0x152: je     130 <generic_sleepable_preload+0x130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_130;
	}
x86_l_154:
	/* 0x154: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_156:
	/* 0x156: js     1ad <generic_sleepable_preload+0x1ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ad;
	}
x86_l_158:
	/* 0x158: movzx  ecx,BYTE PTR [rbx-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_15c:
	/* 0x15c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_15f:
	/* 0x15f: jg     215 <generic_sleepable_preload+0x215> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_215;
	}
x86_l_165:
	/* 0x165: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_168:
	/* 0x168: je     333 <generic_sleepable_preload+0x333> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_333;
	}
x86_l_16e:
	/* 0x16e: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_173:
	/* 0x173: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_176:
	/* 0x176: jne    38c <generic_sleepable_preload+0x38c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_38c;
	}
x86_l_17c:
	/* 0x17c: mov    edx,DWORD PTR [rbx-0xb] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551605ULL);
x86_l_17f:
	/* 0x17f: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_185:
	/* 0x185: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_18a:
	/* 0x18a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18f:
	/* 0x18f: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_192:
	/* 0x192: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_197:
	/* 0x197: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_199:
	/* 0x199: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19e:
	/* 0x19e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a0:
	/* 0x1a0: je     33c <generic_sleepable_preload+0x33c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33c;
	}
x86_l_1a6:
	/* 0x1a6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a8:
	/* 0x1a8: jmp    38c <generic_sleepable_preload+0x38c> */
	goto x86_l_38c;
x86_l_1ad:
	/* 0x1ad: movzx  eax,BYTE PTR [r14+0x2be] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 702ULL);
x86_l_1b5:
	/* 0x1b5: movzx  ecx,WORD PTR [r14+0x2bc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 700ULL);
x86_l_1bd:
	/* 0x1bd: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1c3:
	/* 0x1c3: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1c6:
	/* 0x1c6: jle    299 <generic_sleepable_preload+0x299> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_299;
	}
x86_l_1cc:
	/* 0x1cc: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_1cf:
	/* 0x1cf: jle    2cf <generic_sleepable_preload+0x2cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2cf;
	}
x86_l_1d5:
	/* 0x1d5: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1d8:
	/* 0x1d8: jle    924 <generic_sleepable_preload+0x924> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2340ULL;
	}
x86_l_1de:
	/* 0x1de: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1e6:
	/* 0x1e6: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_1e9:
	/* 0x1e9: je     940 <generic_sleepable_preload+0x940> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2368ULL;
	}
x86_l_1ef:
	/* 0x1ef: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1f4:
	/* 0x1f4: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1f7:
	/* 0x1f7: je     940 <generic_sleepable_preload+0x940> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2368ULL;
	}
x86_l_1fd:
	/* 0x1fd: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_202:
	/* 0x202: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_205:
	/* 0x205: jne    953 <generic_sleepable_preload+0x953> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2387ULL;
	}
x86_l_20b:
	/* 0x20b: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_210:
	/* 0x210: jmp    940 <generic_sleepable_preload+0x940> */
	return 2368ULL;
x86_l_215:
	/* 0x215: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_218:
	/* 0x218: je     360 <generic_sleepable_preload+0x360> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_360;
	}
x86_l_21e:
	/* 0x21e: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_223:
	/* 0x223: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_226:
	/* 0x226: jne    38c <generic_sleepable_preload+0x38c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_38c;
	}
x86_l_22c:
	/* 0x22c: mov    edx,DWORD PTR [rbx-0xb] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551605ULL);
x86_l_22f:
	/* 0x22f: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_235:
	/* 0x235: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_23a:
	/* 0x23a: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23d:
	/* 0x23d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_242:
	/* 0x242: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_245:
	/* 0x245: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24a:
	/* 0x24a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24c:
	/* 0x24c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24e:
	/* 0x24e: jne    385 <generic_sleepable_preload+0x385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_385;
	}
x86_l_254:
	/* 0x254: mov    edx,DWORD PTR [rbx-0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551609ULL);
x86_l_257:
	/* 0x257: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25d:
	/* 0x25d: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_260:
	/* 0x260: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_265:
	/* 0x265: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26a:
	/* 0x26a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26f:
	/* 0x26f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_271:
	/* 0x271: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_273:
	/* 0x273: jne    385 <generic_sleepable_preload+0x385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_385;
	}
x86_l_279:
	/* 0x279: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_27e:
	/* 0x27e: movzx  ecx,BYTE PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_281:
	/* 0x281: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_288:
	/* 0x288: mov    rdx,QWORD PTR [rbx-0x13] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551597ULL);
x86_l_28c:
	/* 0x28c: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_291:
	/* 0x291: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_294:
	/* 0x294: jmp    ec3 <generic_sleepable_preload+0xec3> */
	return 3779ULL;
x86_l_299:
	/* 0x299: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_29c:
	/* 0x29c: jg     301 <generic_sleepable_preload+0x301> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_301;
	}
x86_l_29e:
	/* 0x29e: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2a1:
	/* 0x2a1: jg     8eb <generic_sleepable_preload+0x8eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2283ULL;
	}
x86_l_2a7:
	/* 0x2a7: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ac:
	/* 0x2ac: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2ae:
	/* 0x2ae: je     940 <generic_sleepable_preload+0x940> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2368ULL;
	}
x86_l_2b4:
	/* 0x2b4: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2bc:
	/* 0x2bc: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_2c1:
	/* 0x2c1: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2c4:
	/* 0x2c4: je     940 <generic_sleepable_preload+0x940> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2368ULL;
	}
x86_l_2ca:
	/* 0x2ca: jmp    953 <generic_sleepable_preload+0x953> */
	return 2387ULL;
x86_l_2cf:
	/* 0x2cf: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_2d2:
	/* 0x2d2: jg     8cd <generic_sleepable_preload+0x8cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2253ULL;
	}
x86_l_2d8:
	/* 0x2d8: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2e0:
	/* 0x2e0: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e3:
	/* 0x2e3: je     940 <generic_sleepable_preload+0x940> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2368ULL;
	}
x86_l_2e9:
	/* 0x2e9: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2ee:
	/* 0x2ee: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_2f3:
	/* 0x2f3: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_2f6:
	/* 0x2f6: je     940 <generic_sleepable_preload+0x940> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2368ULL;
	}
x86_l_2fc:
	/* 0x2fc: jmp    953 <generic_sleepable_preload+0x953> */
	return 2387ULL;
x86_l_301:
	/* 0x301: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_304:
	/* 0x304: jg     906 <generic_sleepable_preload+0x906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2310ULL;
	}
x86_l_30a:
	/* 0x30a: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_312:
	/* 0x312: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_315:
	/* 0x315: je     940 <generic_sleepable_preload+0x940> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2368ULL;
	}
x86_l_31b:
	/* 0x31b: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_320:
	/* 0x320: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_325:
	/* 0x325: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_328:
	/* 0x328: je     940 <generic_sleepable_preload+0x940> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2368ULL;
	}
x86_l_32e:
	/* 0x32e: jmp    953 <generic_sleepable_preload+0x953> */
	return 2387ULL;
x86_l_333:
	/* 0x333: mov    rax,QWORD PTR [rbx-0x13] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551597ULL);
x86_l_337:
	/* 0x337: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33c:
	/* 0x33c: movzx  eax,BYTE PTR [rbx-0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551613ULL);
x86_l_340:
	/* 0x340: shlx   rcx,QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((32ULL << 32) | X86_ALU_SHL));
x86_l_347:
	/* 0x347: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34c:
	/* 0x34c: cmp    BYTE PTR [rbx-0x1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744069414584320ULL);
x86_l_350:
	/* 0x350: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_355:
	/* 0x355: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_35a:
	/* 0x35a: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_35e:
	/* 0x35e: jmp    38c <generic_sleepable_preload+0x38c> */
	goto x86_l_38c;
x86_l_360:
	/* 0x360: mov    edx,DWORD PTR [rbx-0xb] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551605ULL);
x86_l_363:
	/* 0x363: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_369:
	/* 0x369: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_36e:
	/* 0x36e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_373:
	/* 0x373: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_376:
	/* 0x376: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37b:
	/* 0x37b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37d:
	/* 0x37d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37f:
	/* 0x37f: je     eb5 <generic_sleepable_preload+0xeb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3765ULL;
	}
x86_l_385:
	/* 0x385: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_387:
	/* 0x387: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_38c:
	/* 0x38c: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_391:
	/* 0x391: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_394:
	/* 0x394: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_397:
	/* 0x397: cmp    WORD PTR [rdi+r12*1-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743764471906304ULL);
x86_l_39e:
	/* 0x39e: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_3a4:
	/* 0x3a4: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3ab:
	/* 0x3ab: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3ae:
	/* 0x3ae: mov    edx,DWORD PTR [rdi+r12*1-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551538ULL);
x86_l_3b3:
	/* 0x3b3: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3b6:
	/* 0x3b6: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bb:
	/* 0x3bb: movzx  eax,WORD PTR [rdi+r12*1-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R12, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_3c1:
	/* 0x3c1: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_3c3:
	/* 0x3c3: je     636 <generic_sleepable_preload+0x636> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_636;
	}
x86_l_3c9:
	/* 0x3c9: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3cc:
	/* 0x3cc: je     3f1 <generic_sleepable_preload+0x3f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f1;
	}
x86_l_3ce:
	/* 0x3ce: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3d3:
	/* 0x3d3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d8:
	/* 0x3d8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3dd:
	/* 0x3dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e2:
	/* 0x3e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e4:
	/* 0x3e4: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e9:
	/* 0x3e9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3eb:
	/* 0x3eb: js     8c2 <generic_sleepable_preload+0x8c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2242ULL;
	}
x86_l_3f1:
	/* 0x3f1: cmp    WORD PTR [rdi+r12*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743798831644672ULL);
x86_l_3f8:
	/* 0x3f8: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_3fe:
	/* 0x3fe: mov    eax,DWORD PTR [rdi+r12*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551546ULL);
x86_l_403:
	/* 0x403: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_408:
	/* 0x408: cmp    WORD PTR [rdi+r12*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743790241710080ULL);
x86_l_40f:
	/* 0x40f: je     434 <generic_sleepable_preload+0x434> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_434;
	}
x86_l_411:
	/* 0x411: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_416:
	/* 0x416: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41b:
	/* 0x41b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_420:
	/* 0x420: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_425:
	/* 0x425: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_427:
	/* 0x427: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_42c:
	/* 0x42c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42e:
	/* 0x42e: js     e9f <generic_sleepable_preload+0xe9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3743ULL;
	}
x86_l_434:
	/* 0x434: cmp    WORD PTR [rdi+r12*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743833191383040ULL);
x86_l_43b:
	/* 0x43b: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_441:
	/* 0x441: mov    eax,DWORD PTR [rdi+r12*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551554ULL);
x86_l_446:
	/* 0x446: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_44b:
	/* 0x44b: cmp    WORD PTR [rdi+r12*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743824601448448ULL);
x86_l_452:
	/* 0x452: je     477 <generic_sleepable_preload+0x477> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_477;
	}
x86_l_454:
	/* 0x454: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_459:
	/* 0x459: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45e:
	/* 0x45e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_463:
	/* 0x463: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_468:
	/* 0x468: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46a:
	/* 0x46a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_46f:
	/* 0x46f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_471:
	/* 0x471: js     ee1 <generic_sleepable_preload+0xee1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3809ULL;
	}
x86_l_477:
	/* 0x477: cmp    WORD PTR [rdi+r12*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743867551121408ULL);
x86_l_47e:
	/* 0x47e: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_484:
	/* 0x484: mov    eax,DWORD PTR [rdi+r12*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551562ULL);
x86_l_489:
	/* 0x489: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_48e:
	/* 0x48e: cmp    WORD PTR [rdi+r12*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743858961186816ULL);
x86_l_495:
	/* 0x495: je     4ba <generic_sleepable_preload+0x4ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ba;
	}
x86_l_497:
	/* 0x497: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_49c:
	/* 0x49c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a1:
	/* 0x4a1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a6:
	/* 0x4a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ab:
	/* 0x4ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ad:
	/* 0x4ad: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b2:
	/* 0x4b2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b4:
	/* 0x4b4: js     ef4 <generic_sleepable_preload+0xef4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3828ULL;
	}
x86_l_4ba:
	/* 0x4ba: cmp    WORD PTR [rdi+r12*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743901910859776ULL);
x86_l_4c1:
	/* 0x4c1: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_4c7:
	/* 0x4c7: mov    eax,DWORD PTR [rdi+r12*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551570ULL);
x86_l_4cc:
	/* 0x4cc: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4d1:
	/* 0x4d1: cmp    WORD PTR [rdi+r12*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743893320925184ULL);
x86_l_4d8:
	/* 0x4d8: je     4fd <generic_sleepable_preload+0x4fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fd;
	}
x86_l_4da:
	/* 0x4da: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4df:
	/* 0x4df: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e4:
	/* 0x4e4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e9:
	/* 0x4e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ee:
	/* 0x4ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f0:
	/* 0x4f0: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4f5:
	/* 0x4f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f7:
	/* 0x4f7: js     f07 <generic_sleepable_preload+0xf07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3847ULL;
	}
x86_l_4fd:
	/* 0x4fd: cmp    WORD PTR [rdi+r12*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743936270598144ULL);
x86_l_504:
	/* 0x504: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_50a:
	/* 0x50a: mov    eax,DWORD PTR [rdi+r12*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551578ULL);
x86_l_50f:
	/* 0x50f: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_514:
	/* 0x514: cmp    WORD PTR [rdi+r12*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743927680663552ULL);
x86_l_51b:
	/* 0x51b: je     540 <generic_sleepable_preload+0x540> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_540;
	}
x86_l_51d:
	/* 0x51d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_522:
	/* 0x522: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_527:
	/* 0x527: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52c:
	/* 0x52c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_531:
	/* 0x531: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_533:
	/* 0x533: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_538:
	/* 0x538: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_53a:
	/* 0x53a: js     f1a <generic_sleepable_preload+0xf1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3866ULL;
	}
x86_l_540:
	/* 0x540: cmp    WORD PTR [rdi+r12*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743970630336512ULL);
x86_l_547:
	/* 0x547: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_54d:
	/* 0x54d: mov    eax,DWORD PTR [rdi+r12*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551586ULL);
x86_l_552:
	/* 0x552: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_557:
	/* 0x557: cmp    WORD PTR [rdi+r12*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743962040401920ULL);
x86_l_55e:
	/* 0x55e: je     583 <generic_sleepable_preload+0x583> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_583;
	}
x86_l_560:
	/* 0x560: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_565:
	/* 0x565: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56a:
	/* 0x56a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56f:
	/* 0x56f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_574:
	/* 0x574: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_576:
	/* 0x576: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_57b:
	/* 0x57b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57d:
	/* 0x57d: js     f2d <generic_sleepable_preload+0xf2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3885ULL;
	}
x86_l_583:
	/* 0x583: cmp    WORD PTR [rdi+r12*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744004990074880ULL);
x86_l_58a:
	/* 0x58a: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_590:
	/* 0x590: mov    eax,DWORD PTR [rdi+r12*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551594ULL);
x86_l_595:
	/* 0x595: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_59a:
	/* 0x59a: cmp    WORD PTR [rdi+r12*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743996400140288ULL);
x86_l_5a1:
	/* 0x5a1: je     5c6 <generic_sleepable_preload+0x5c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c6;
	}
x86_l_5a3:
	/* 0x5a3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5a8:
	/* 0x5a8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ad:
	/* 0x5ad: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b2:
	/* 0x5b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b7:
	/* 0x5b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b9:
	/* 0x5b9: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5be:
	/* 0x5be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5c0:
	/* 0x5c0: js     10cf <generic_sleepable_preload+0x10cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4303ULL;
	}
x86_l_5c6:
	/* 0x5c6: cmp    WORD PTR [rdi+r12*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744039349813248ULL);
x86_l_5cd:
	/* 0x5cd: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_5d3:
	/* 0x5d3: mov    eax,DWORD PTR [rdi+r12*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551602ULL);
x86_l_5d8:
	/* 0x5d8: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5dd:
	/* 0x5dd: cmp    WORD PTR [rdi+r12*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744030759878656ULL);
x86_l_5e4:
	/* 0x5e4: je     609 <generic_sleepable_preload+0x609> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_609;
	}
x86_l_5e6:
	/* 0x5e6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5eb:
	/* 0x5eb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f0:
	/* 0x5f0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f5:
	/* 0x5f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5fa:
	/* 0x5fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fc:
	/* 0x5fc: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_601:
	/* 0x601: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_603:
	/* 0x603: js     10f9 <generic_sleepable_preload+0x10f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4345ULL;
	}
x86_l_609:
	/* 0x609: cmp    WORD PTR [rdi+r12*1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_60f:
	/* 0x60f: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_615:
	/* 0x615: mov    eax,DWORD PTR [rdi+r12*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551610ULL);
x86_l_61a:
	/* 0x61a: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_61f:
	/* 0x61f: cmp    WORD PTR [rdi+r12*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744065119617024ULL);
x86_l_626:
	/* 0x626: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_62c:
	/* 0x62c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_631:
	/* 0x631: jmp    89e <generic_sleepable_preload+0x89e> */
	return 2206ULL;
x86_l_636:
	/* 0x636: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_639:
	/* 0x639: je     65e <generic_sleepable_preload+0x65e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_65e;
	}
x86_l_63b:
	/* 0x63b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_640:
	/* 0x640: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_645:
	/* 0x645: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_64a:
	/* 0x64a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64f:
	/* 0x64f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_651:
	/* 0x651: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_656:
	/* 0x656: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_658:
	/* 0x658: js     8c2 <generic_sleepable_preload+0x8c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2242ULL;
	}
x86_l_65e:
	/* 0x65e: cmp    WORD PTR [rdi+r12*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743798831644672ULL);
x86_l_665:
	/* 0x665: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_66b:
	/* 0x66b: mov    eax,DWORD PTR [rdi+r12*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551546ULL);
x86_l_670:
	/* 0x670: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_675:
	/* 0x675: cmp    WORD PTR [rdi+r12*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743790241710080ULL);
x86_l_67c:
	/* 0x67c: je     6a1 <generic_sleepable_preload+0x6a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6a1;
	}
x86_l_67e:
	/* 0x67e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_683:
	/* 0x683: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_688:
	/* 0x688: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_68d:
	/* 0x68d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_692:
	/* 0x692: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_694:
	/* 0x694: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_699:
	/* 0x699: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_69b:
	/* 0x69b: js     e9f <generic_sleepable_preload+0xe9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3743ULL;
	}
x86_l_6a1:
	/* 0x6a1: cmp    WORD PTR [rdi+r12*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743833191383040ULL);
x86_l_6a8:
	/* 0x6a8: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_6ae:
	/* 0x6ae: mov    eax,DWORD PTR [rdi+r12*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551554ULL);
x86_l_6b3:
	/* 0x6b3: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6b8:
	/* 0x6b8: cmp    WORD PTR [rdi+r12*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743824601448448ULL);
x86_l_6bf:
	/* 0x6bf: je     6e4 <generic_sleepable_preload+0x6e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6e4;
	}
x86_l_6c1:
	/* 0x6c1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6c6:
	/* 0x6c6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6cb:
	/* 0x6cb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6d0:
	/* 0x6d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6d5:
	/* 0x6d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d7:
	/* 0x6d7: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6dc:
	/* 0x6dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6de:
	/* 0x6de: js     ee1 <generic_sleepable_preload+0xee1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3809ULL;
	}
x86_l_6e4:
	/* 0x6e4: cmp    WORD PTR [rdi+r12*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743867551121408ULL);
x86_l_6eb:
	/* 0x6eb: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_6f1:
	/* 0x6f1: mov    eax,DWORD PTR [rdi+r12*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551562ULL);
x86_l_6f6:
	/* 0x6f6: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6fb:
	/* 0x6fb: cmp    WORD PTR [rdi+r12*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743858961186816ULL);
x86_l_702:
	/* 0x702: je     727 <generic_sleepable_preload+0x727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1831ULL;
	}
x86_l_704:
	/* 0x704: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_709:
	/* 0x709: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 1806ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1806ULL: goto x86_l_70e;
	case 1811ULL: goto x86_l_713;
	case 1816ULL: goto x86_l_718;
	case 1818ULL: goto x86_l_71a;
	case 1823ULL: goto x86_l_71f;
	case 1825ULL: goto x86_l_721;
	case 1831ULL: goto x86_l_727;
	case 1838ULL: goto x86_l_72e;
	case 1844ULL: goto x86_l_734;
	case 1849ULL: goto x86_l_739;
	case 1854ULL: goto x86_l_73e;
	case 1861ULL: goto x86_l_745;
	case 1863ULL: goto x86_l_747;
	case 1868ULL: goto x86_l_74c;
	case 1873ULL: goto x86_l_751;
	case 1878ULL: goto x86_l_756;
	case 1883ULL: goto x86_l_75b;
	case 1885ULL: goto x86_l_75d;
	case 1890ULL: goto x86_l_762;
	case 1892ULL: goto x86_l_764;
	case 1898ULL: goto x86_l_76a;
	case 1905ULL: goto x86_l_771;
	case 1911ULL: goto x86_l_777;
	case 1916ULL: goto x86_l_77c;
	case 1921ULL: goto x86_l_781;
	case 1928ULL: goto x86_l_788;
	case 1930ULL: goto x86_l_78a;
	case 1935ULL: goto x86_l_78f;
	case 1940ULL: goto x86_l_794;
	case 1945ULL: goto x86_l_799;
	case 1950ULL: goto x86_l_79e;
	case 1952ULL: goto x86_l_7a0;
	case 1957ULL: goto x86_l_7a5;
	case 1959ULL: goto x86_l_7a7;
	case 1965ULL: goto x86_l_7ad;
	case 1972ULL: goto x86_l_7b4;
	case 1978ULL: goto x86_l_7ba;
	case 1983ULL: goto x86_l_7bf;
	case 1988ULL: goto x86_l_7c4;
	case 1995ULL: goto x86_l_7cb;
	case 1997ULL: goto x86_l_7cd;
	case 2002ULL: goto x86_l_7d2;
	case 2007ULL: goto x86_l_7d7;
	case 2012ULL: goto x86_l_7dc;
	case 2017ULL: goto x86_l_7e1;
	case 2019ULL: goto x86_l_7e3;
	case 2024ULL: goto x86_l_7e8;
	case 2026ULL: goto x86_l_7ea;
	case 2032ULL: goto x86_l_7f0;
	case 2039ULL: goto x86_l_7f7;
	case 2045ULL: goto x86_l_7fd;
	case 2050ULL: goto x86_l_802;
	case 2055ULL: goto x86_l_807;
	case 2062ULL: goto x86_l_80e;
	case 2064ULL: goto x86_l_810;
	case 2069ULL: goto x86_l_815;
	case 2074ULL: goto x86_l_81a;
	case 2079ULL: goto x86_l_81f;
	case 2084ULL: goto x86_l_824;
	case 2086ULL: goto x86_l_826;
	case 2091ULL: goto x86_l_82b;
	case 2093ULL: goto x86_l_82d;
	case 2099ULL: goto x86_l_833;
	case 2106ULL: goto x86_l_83a;
	case 2112ULL: goto x86_l_840;
	case 2117ULL: goto x86_l_845;
	case 2122ULL: goto x86_l_84a;
	case 2129ULL: goto x86_l_851;
	case 2131ULL: goto x86_l_853;
	case 2136ULL: goto x86_l_858;
	case 2141ULL: goto x86_l_85d;
	case 2146ULL: goto x86_l_862;
	case 2151ULL: goto x86_l_867;
	case 2153ULL: goto x86_l_869;
	case 2158ULL: goto x86_l_86e;
	case 2160ULL: goto x86_l_870;
	case 2166ULL: goto x86_l_876;
	case 2172ULL: goto x86_l_87c;
	case 2178ULL: goto x86_l_882;
	case 2183ULL: goto x86_l_887;
	case 2188ULL: goto x86_l_88c;
	case 2195ULL: goto x86_l_893;
	case 2201ULL: goto x86_l_899;
	case 2206ULL: goto x86_l_89e;
	case 2211ULL: goto x86_l_8a3;
	case 2216ULL: goto x86_l_8a8;
	case 2221ULL: goto x86_l_8ad;
	case 2223ULL: goto x86_l_8af;
	case 2225ULL: goto x86_l_8b1;
	case 2231ULL: goto x86_l_8b7;
	case 2237ULL: goto x86_l_8bd;
	case 2242ULL: goto x86_l_8c2;
	case 2248ULL: goto x86_l_8c8;
	case 2253ULL: goto x86_l_8cd;
	case 2261ULL: goto x86_l_8d5;
	case 2264ULL: goto x86_l_8d8;
	case 2266ULL: goto x86_l_8da;
	case 2271ULL: goto x86_l_8df;
	case 2276ULL: goto x86_l_8e4;
	case 2279ULL: goto x86_l_8e7;
	case 2281ULL: goto x86_l_8e9;
	case 2283ULL: goto x86_l_8eb;
	case 2288ULL: goto x86_l_8f0;
	case 2291ULL: goto x86_l_8f3;
	case 2293ULL: goto x86_l_8f5;
	case 2298ULL: goto x86_l_8fa;
	case 2303ULL: goto x86_l_8ff;
	case 2306ULL: goto x86_l_902;
	case 2308ULL: goto x86_l_904;
	case 2310ULL: goto x86_l_906;
	case 2318ULL: goto x86_l_90e;
	case 2321ULL: goto x86_l_911;
	case 2323ULL: goto x86_l_913;
	case 2328ULL: goto x86_l_918;
	case 2333ULL: goto x86_l_91d;
	case 2336ULL: goto x86_l_920;
	case 2338ULL: goto x86_l_922;
	case 2340ULL: goto x86_l_924;
	case 2348ULL: goto x86_l_92c;
	case 2351ULL: goto x86_l_92f;
	case 2353ULL: goto x86_l_931;
	case 2358ULL: goto x86_l_936;
	case 2363ULL: goto x86_l_93b;
	case 2366ULL: goto x86_l_93e;
	case 2368ULL: goto x86_l_940;
	case 2371ULL: goto x86_l_943;
	case 2373ULL: goto x86_l_945;
	case 2375ULL: goto x86_l_947;
	case 2380ULL: goto x86_l_94c;
	case 2382ULL: goto x86_l_94e;
	case 2387ULL: goto x86_l_953;
	case 2392ULL: goto x86_l_958;
	case 2395ULL: goto x86_l_95b;
	case 2398ULL: goto x86_l_95e;
	case 2400ULL: goto x86_l_960;
	case 2404ULL: goto x86_l_964;
	case 2411ULL: goto x86_l_96b;
	case 2417ULL: goto x86_l_971;
	case 2424ULL: goto x86_l_978;
	case 2427ULL: goto x86_l_97b;
	case 2432ULL: goto x86_l_980;
	case 2435ULL: goto x86_l_983;
	case 2440ULL: goto x86_l_988;
	case 2446ULL: goto x86_l_98e;
	case 2448ULL: goto x86_l_990;
	case 2454ULL: goto x86_l_996;
	case 2457ULL: goto x86_l_999;
	case 2459ULL: goto x86_l_99b;
	case 2464ULL: goto x86_l_9a0;
	case 2469ULL: goto x86_l_9a5;
	case 2474ULL: goto x86_l_9aa;
	case 2479ULL: goto x86_l_9af;
	case 2481ULL: goto x86_l_9b1;
	case 2486ULL: goto x86_l_9b6;
	case 2488ULL: goto x86_l_9b8;
	case 2494ULL: goto x86_l_9be;
	case 2501ULL: goto x86_l_9c5;
	case 2507ULL: goto x86_l_9cb;
	case 2512ULL: goto x86_l_9d0;
	case 2517ULL: goto x86_l_9d5;
	case 2524ULL: goto x86_l_9dc;
	case 2526ULL: goto x86_l_9de;
	case 2531ULL: goto x86_l_9e3;
	case 2536ULL: goto x86_l_9e8;
	case 2541ULL: goto x86_l_9ed;
	case 2546ULL: goto x86_l_9f2;
	case 2548ULL: goto x86_l_9f4;
	case 2553ULL: goto x86_l_9f9;
	case 2555ULL: goto x86_l_9fb;
	case 2561ULL: goto x86_l_a01;
	case 2568ULL: goto x86_l_a08;
	case 2574ULL: goto x86_l_a0e;
	case 2579ULL: goto x86_l_a13;
	case 2584ULL: goto x86_l_a18;
	case 2591ULL: goto x86_l_a1f;
	case 2593ULL: goto x86_l_a21;
	case 2598ULL: goto x86_l_a26;
	case 2603ULL: goto x86_l_a2b;
	case 2608ULL: goto x86_l_a30;
	case 2613ULL: goto x86_l_a35;
	case 2615ULL: goto x86_l_a37;
	case 2620ULL: goto x86_l_a3c;
	case 2622ULL: goto x86_l_a3e;
	case 2628ULL: goto x86_l_a44;
	case 2635ULL: goto x86_l_a4b;
	case 2641ULL: goto x86_l_a51;
	case 2646ULL: goto x86_l_a56;
	case 2651ULL: goto x86_l_a5b;
	case 2658ULL: goto x86_l_a62;
	case 2660ULL: goto x86_l_a64;
	case 2665ULL: goto x86_l_a69;
	case 2670ULL: goto x86_l_a6e;
	case 2675ULL: goto x86_l_a73;
	case 2680ULL: goto x86_l_a78;
	case 2682ULL: goto x86_l_a7a;
	case 2687ULL: goto x86_l_a7f;
	case 2689ULL: goto x86_l_a81;
	case 2695ULL: goto x86_l_a87;
	case 2702ULL: goto x86_l_a8e;
	case 2708ULL: goto x86_l_a94;
	case 2713ULL: goto x86_l_a99;
	case 2718ULL: goto x86_l_a9e;
	case 2725ULL: goto x86_l_aa5;
	case 2727ULL: goto x86_l_aa7;
	case 2732ULL: goto x86_l_aac;
	case 2737ULL: goto x86_l_ab1;
	case 2742ULL: goto x86_l_ab6;
	case 2747ULL: goto x86_l_abb;
	case 2749ULL: goto x86_l_abd;
	case 2754ULL: goto x86_l_ac2;
	case 2756ULL: goto x86_l_ac4;
	case 2762ULL: goto x86_l_aca;
	case 2769ULL: goto x86_l_ad1;
	case 2775ULL: goto x86_l_ad7;
	case 2780ULL: goto x86_l_adc;
	case 2785ULL: goto x86_l_ae1;
	case 2792ULL: goto x86_l_ae8;
	case 2794ULL: goto x86_l_aea;
	case 2799ULL: goto x86_l_aef;
	case 2804ULL: goto x86_l_af4;
	case 2809ULL: goto x86_l_af9;
	case 2814ULL: goto x86_l_afe;
	case 2816ULL: goto x86_l_b00;
	case 2821ULL: goto x86_l_b05;
	case 2823ULL: goto x86_l_b07;
	case 2829ULL: goto x86_l_b0d;
	case 2836ULL: goto x86_l_b14;
	case 2842ULL: goto x86_l_b1a;
	case 2847ULL: goto x86_l_b1f;
	case 2852ULL: goto x86_l_b24;
	case 2859ULL: goto x86_l_b2b;
	case 2861ULL: goto x86_l_b2d;
	case 2866ULL: goto x86_l_b32;
	case 2871ULL: goto x86_l_b37;
	case 2876ULL: goto x86_l_b3c;
	case 2881ULL: goto x86_l_b41;
	case 2883ULL: goto x86_l_b43;
	case 2888ULL: goto x86_l_b48;
	case 2890ULL: goto x86_l_b4a;
	case 2896ULL: goto x86_l_b50;
	case 2903ULL: goto x86_l_b57;
	case 2909ULL: goto x86_l_b5d;
	case 2914ULL: goto x86_l_b62;
	case 2919ULL: goto x86_l_b67;
	case 2926ULL: goto x86_l_b6e;
	case 2928ULL: goto x86_l_b70;
	case 2933ULL: goto x86_l_b75;
	case 2938ULL: goto x86_l_b7a;
	case 2943ULL: goto x86_l_b7f;
	case 2948ULL: goto x86_l_b84;
	case 2950ULL: goto x86_l_b86;
	case 2955ULL: goto x86_l_b8b;
	case 2957ULL: goto x86_l_b8d;
	case 2963ULL: goto x86_l_b93;
	case 2970ULL: goto x86_l_b9a;
	case 2976ULL: goto x86_l_ba0;
	case 2981ULL: goto x86_l_ba5;
	case 2986ULL: goto x86_l_baa;
	case 2993ULL: goto x86_l_bb1;
	case 2995ULL: goto x86_l_bb3;
	case 3000ULL: goto x86_l_bb8;
	case 3005ULL: goto x86_l_bbd;
	case 3010ULL: goto x86_l_bc2;
	case 3015ULL: goto x86_l_bc7;
	case 3017ULL: goto x86_l_bc9;
	case 3022ULL: goto x86_l_bce;
	case 3024ULL: goto x86_l_bd0;
	case 3030ULL: goto x86_l_bd6;
	case 3036ULL: goto x86_l_bdc;
	case 3042ULL: goto x86_l_be2;
	case 3047ULL: goto x86_l_be7;
	case 3052ULL: goto x86_l_bec;
	case 3059ULL: goto x86_l_bf3;
	case 3065ULL: goto x86_l_bf9;
	case 3070ULL: goto x86_l_bfe;
	case 3075ULL: goto x86_l_c03;
	case 3078ULL: goto x86_l_c06;
	case 3080ULL: goto x86_l_c08;
	case 3085ULL: goto x86_l_c0d;
	case 3090ULL: goto x86_l_c12;
	case 3095ULL: goto x86_l_c17;
	case 3100ULL: goto x86_l_c1c;
	case 3102ULL: goto x86_l_c1e;
	case 3107ULL: goto x86_l_c23;
	case 3109ULL: goto x86_l_c25;
	case 3115ULL: goto x86_l_c2b;
	case 3122ULL: goto x86_l_c32;
	case 3128ULL: goto x86_l_c38;
	case 3133ULL: goto x86_l_c3d;
	case 3138ULL: goto x86_l_c42;
	case 3145ULL: goto x86_l_c49;
	case 3147ULL: goto x86_l_c4b;
	case 3152ULL: goto x86_l_c50;
	case 3157ULL: goto x86_l_c55;
	case 3162ULL: goto x86_l_c5a;
	case 3167ULL: goto x86_l_c5f;
	case 3169ULL: goto x86_l_c61;
	case 3174ULL: goto x86_l_c66;
	case 3176ULL: goto x86_l_c68;
	case 3182ULL: goto x86_l_c6e;
	case 3189ULL: goto x86_l_c75;
	case 3195ULL: goto x86_l_c7b;
	case 3200ULL: goto x86_l_c80;
	case 3205ULL: goto x86_l_c85;
	case 3212ULL: goto x86_l_c8c;
	case 3214ULL: goto x86_l_c8e;
	case 3219ULL: goto x86_l_c93;
	case 3224ULL: goto x86_l_c98;
	case 3229ULL: goto x86_l_c9d;
	case 3234ULL: goto x86_l_ca2;
	case 3236ULL: goto x86_l_ca4;
	case 3241ULL: goto x86_l_ca9;
	case 3243ULL: goto x86_l_cab;
	case 3249ULL: goto x86_l_cb1;
	case 3256ULL: goto x86_l_cb8;
	case 3262ULL: goto x86_l_cbe;
	case 3267ULL: goto x86_l_cc3;
	case 3272ULL: goto x86_l_cc8;
	case 3279ULL: goto x86_l_ccf;
	case 3281ULL: goto x86_l_cd1;
	case 3286ULL: goto x86_l_cd6;
	case 3291ULL: goto x86_l_cdb;
	case 3296ULL: goto x86_l_ce0;
	case 3301ULL: goto x86_l_ce5;
	case 3303ULL: goto x86_l_ce7;
	case 3308ULL: goto x86_l_cec;
	case 3310ULL: goto x86_l_cee;
	case 3316ULL: goto x86_l_cf4;
	case 3323ULL: goto x86_l_cfb;
	case 3329ULL: goto x86_l_d01;
	case 3334ULL: goto x86_l_d06;
	case 3339ULL: goto x86_l_d0b;
	case 3346ULL: goto x86_l_d12;
	case 3348ULL: goto x86_l_d14;
	case 3353ULL: goto x86_l_d19;
	case 3358ULL: goto x86_l_d1e;
	case 3363ULL: goto x86_l_d23;
	case 3368ULL: goto x86_l_d28;
	case 3370ULL: goto x86_l_d2a;
	case 3375ULL: goto x86_l_d2f;
	case 3377ULL: goto x86_l_d31;
	case 3383ULL: goto x86_l_d37;
	case 3390ULL: goto x86_l_d3e;
	case 3396ULL: goto x86_l_d44;
	case 3401ULL: goto x86_l_d49;
	case 3406ULL: goto x86_l_d4e;
	case 3413ULL: goto x86_l_d55;
	case 3415ULL: goto x86_l_d57;
	case 3420ULL: goto x86_l_d5c;
	case 3425ULL: goto x86_l_d61;
	case 3430ULL: goto x86_l_d66;
	case 3435ULL: goto x86_l_d6b;
	case 3437ULL: goto x86_l_d6d;
	case 3442ULL: goto x86_l_d72;
	case 3444ULL: goto x86_l_d74;
	case 3450ULL: goto x86_l_d7a;
	case 3457ULL: goto x86_l_d81;
	case 3463ULL: goto x86_l_d87;
	case 3468ULL: goto x86_l_d8c;
	case 3473ULL: goto x86_l_d91;
	case 3480ULL: goto x86_l_d98;
	case 3482ULL: goto x86_l_d9a;
	case 3487ULL: goto x86_l_d9f;
	case 3492ULL: goto x86_l_da4;
	case 3497ULL: goto x86_l_da9;
	case 3502ULL: goto x86_l_dae;
	case 3504ULL: goto x86_l_db0;
	case 3509ULL: goto x86_l_db5;
	case 3511ULL: goto x86_l_db7;
	case 3517ULL: goto x86_l_dbd;
	case 3524ULL: goto x86_l_dc4;
	case 3530ULL: goto x86_l_dca;
	case 3535ULL: goto x86_l_dcf;
	case 3540ULL: goto x86_l_dd4;
	case 3547ULL: goto x86_l_ddb;
	case 3549ULL: goto x86_l_ddd;
	case 3554ULL: goto x86_l_de2;
	case 3559ULL: goto x86_l_de7;
	case 3564ULL: goto x86_l_dec;
	case 3569ULL: goto x86_l_df1;
	case 3571ULL: goto x86_l_df3;
	case 3576ULL: goto x86_l_df8;
	case 3578ULL: goto x86_l_dfa;
	case 3584ULL: goto x86_l_e00;
	default: return 0xffffffffffffffffULL;
	}
x86_l_70e:
	/* 0x70e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_713:
	/* 0x713: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_718:
	/* 0x718: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71a:
	/* 0x71a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_71f:
	/* 0x71f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_721:
	/* 0x721: js     ef4 <generic_sleepable_preload+0xef4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3828ULL;
	}
x86_l_727:
	/* 0x727: cmp    WORD PTR [rdi+r12*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743901910859776ULL);
x86_l_72e:
	/* 0x72e: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_734:
	/* 0x734: mov    eax,DWORD PTR [rdi+r12*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551570ULL);
x86_l_739:
	/* 0x739: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_73e:
	/* 0x73e: cmp    WORD PTR [rdi+r12*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743893320925184ULL);
x86_l_745:
	/* 0x745: je     76a <generic_sleepable_preload+0x76a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_76a;
	}
x86_l_747:
	/* 0x747: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_74c:
	/* 0x74c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_751:
	/* 0x751: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_756:
	/* 0x756: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_75b:
	/* 0x75b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_75d:
	/* 0x75d: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_762:
	/* 0x762: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_764:
	/* 0x764: js     f07 <generic_sleepable_preload+0xf07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3847ULL;
	}
x86_l_76a:
	/* 0x76a: cmp    WORD PTR [rdi+r12*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743936270598144ULL);
x86_l_771:
	/* 0x771: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_777:
	/* 0x777: mov    eax,DWORD PTR [rdi+r12*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551578ULL);
x86_l_77c:
	/* 0x77c: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_781:
	/* 0x781: cmp    WORD PTR [rdi+r12*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743927680663552ULL);
x86_l_788:
	/* 0x788: je     7ad <generic_sleepable_preload+0x7ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7ad;
	}
x86_l_78a:
	/* 0x78a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_78f:
	/* 0x78f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_794:
	/* 0x794: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_799:
	/* 0x799: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_79e:
	/* 0x79e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a0:
	/* 0x7a0: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7a5:
	/* 0x7a5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7a7:
	/* 0x7a7: js     f1a <generic_sleepable_preload+0xf1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3866ULL;
	}
x86_l_7ad:
	/* 0x7ad: cmp    WORD PTR [rdi+r12*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743970630336512ULL);
x86_l_7b4:
	/* 0x7b4: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_7ba:
	/* 0x7ba: mov    eax,DWORD PTR [rdi+r12*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551586ULL);
x86_l_7bf:
	/* 0x7bf: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_7c4:
	/* 0x7c4: cmp    WORD PTR [rdi+r12*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743962040401920ULL);
x86_l_7cb:
	/* 0x7cb: je     7f0 <generic_sleepable_preload+0x7f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7f0;
	}
x86_l_7cd:
	/* 0x7cd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_7d2:
	/* 0x7d2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7d7:
	/* 0x7d7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7dc:
	/* 0x7dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7e1:
	/* 0x7e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e3:
	/* 0x7e3: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7e8:
	/* 0x7e8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7ea:
	/* 0x7ea: js     f2d <generic_sleepable_preload+0xf2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3885ULL;
	}
x86_l_7f0:
	/* 0x7f0: cmp    WORD PTR [rdi+r12*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744004990074880ULL);
x86_l_7f7:
	/* 0x7f7: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_7fd:
	/* 0x7fd: mov    eax,DWORD PTR [rdi+r12*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551594ULL);
x86_l_802:
	/* 0x802: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_807:
	/* 0x807: cmp    WORD PTR [rdi+r12*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743996400140288ULL);
x86_l_80e:
	/* 0x80e: je     833 <generic_sleepable_preload+0x833> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_833;
	}
x86_l_810:
	/* 0x810: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_815:
	/* 0x815: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_81a:
	/* 0x81a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_81f:
	/* 0x81f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_824:
	/* 0x824: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_826:
	/* 0x826: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_82b:
	/* 0x82b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_82d:
	/* 0x82d: js     10cf <generic_sleepable_preload+0x10cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4303ULL;
	}
x86_l_833:
	/* 0x833: cmp    WORD PTR [rdi+r12*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744039349813248ULL);
x86_l_83a:
	/* 0x83a: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_840:
	/* 0x840: mov    eax,DWORD PTR [rdi+r12*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551602ULL);
x86_l_845:
	/* 0x845: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_84a:
	/* 0x84a: cmp    WORD PTR [rdi+r12*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744030759878656ULL);
x86_l_851:
	/* 0x851: je     876 <generic_sleepable_preload+0x876> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_876;
	}
x86_l_853:
	/* 0x853: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_858:
	/* 0x858: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_85d:
	/* 0x85d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_862:
	/* 0x862: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_867:
	/* 0x867: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_869:
	/* 0x869: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_86e:
	/* 0x86e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_870:
	/* 0x870: js     10f9 <generic_sleepable_preload+0x10f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4345ULL;
	}
x86_l_876:
	/* 0x876: cmp    WORD PTR [rdi+r12*1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_87c:
	/* 0x87c: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_882:
	/* 0x882: mov    eax,DWORD PTR [rdi+r12*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551610ULL);
x86_l_887:
	/* 0x887: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_88c:
	/* 0x88c: cmp    WORD PTR [rdi+r12*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744065119617024ULL);
x86_l_893:
	/* 0x893: je     f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3894ULL;
	}
x86_l_899:
	/* 0x899: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_89e:
	/* 0x89e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8a3:
	/* 0x8a3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8a8:
	/* 0x8a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8ad:
	/* 0x8ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8af:
	/* 0x8af: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8b1:
	/* 0x8b1: jns    f36 <generic_sleepable_preload+0xf36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 3894ULL;
	}
x86_l_8b7:
	/* 0x8b7: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_8bd:
	/* 0x8bd: jmp    f33 <generic_sleepable_preload+0xf33> */
	return 3891ULL;
x86_l_8c2:
	/* 0x8c2: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_8c8:
	/* 0x8c8: jmp    f33 <generic_sleepable_preload+0xf33> */
	return 3891ULL;
x86_l_8cd:
	/* 0x8cd: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_8d5:
	/* 0x8d5: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_8d8:
	/* 0x8d8: je     940 <generic_sleepable_preload+0x940> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_940;
	}
x86_l_8da:
	/* 0x8da: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8df:
	/* 0x8df: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_8e4:
	/* 0x8e4: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_8e7:
	/* 0x8e7: je     940 <generic_sleepable_preload+0x940> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_940;
	}
x86_l_8e9:
	/* 0x8e9: jmp    953 <generic_sleepable_preload+0x953> */
	goto x86_l_953;
x86_l_8eb:
	/* 0x8eb: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_8f0:
	/* 0x8f0: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_8f3:
	/* 0x8f3: je     940 <generic_sleepable_preload+0x940> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_940;
	}
x86_l_8f5:
	/* 0x8f5: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8fa:
	/* 0x8fa: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_8ff:
	/* 0x8ff: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_902:
	/* 0x902: je     940 <generic_sleepable_preload+0x940> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_940;
	}
x86_l_904:
	/* 0x904: jmp    953 <generic_sleepable_preload+0x953> */
	goto x86_l_953;
x86_l_906:
	/* 0x906: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_90e:
	/* 0x90e: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_911:
	/* 0x911: je     940 <generic_sleepable_preload+0x940> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_940;
	}
x86_l_913:
	/* 0x913: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_918:
	/* 0x918: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_91d:
	/* 0x91d: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_920:
	/* 0x920: je     940 <generic_sleepable_preload+0x940> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_940;
	}
x86_l_922:
	/* 0x922: jmp    953 <generic_sleepable_preload+0x953> */
	goto x86_l_953;
x86_l_924:
	/* 0x924: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_92c:
	/* 0x92c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_92f:
	/* 0x92f: je     940 <generic_sleepable_preload+0x940> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_940;
	}
x86_l_931:
	/* 0x931: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_936:
	/* 0x936: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_93b:
	/* 0x93b: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_93e:
	/* 0x93e: jne    953 <generic_sleepable_preload+0x953> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_953;
	}
x86_l_940:
	/* 0x940: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_943:
	/* 0x943: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_945:
	/* 0x945: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_947:
	/* 0x947: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_94c:
	/* 0x94c: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_94e:
	/* 0x94e: bzhi   rsi,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RSI, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_953:
	/* 0x953: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_958:
	/* 0x958: mov    ebp,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_95b:
	/* 0x95b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_95e:
	/* 0x95e: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_960:
	/* 0x960: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_964:
	/* 0x964: cmp    WORD PTR [rdi+r12*1-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743764471906304ULL);
x86_l_96b:
	/* 0x96b: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4124ULL;
	}
x86_l_971:
	/* 0x971: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_978:
	/* 0x978: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_97b:
	/* 0x97b: mov    eax,DWORD PTR [rdi+r12*1-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551538ULL);
x86_l_980:
	/* 0x980: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_983:
	/* 0x983: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_988:
	/* 0x988: movzx  eax,WORD PTR [rdi+r12*1-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R12, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_98e:
	/* 0x98e: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_990:
	/* 0x990: je     c03 <generic_sleepable_preload+0xc03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c03;
	}
x86_l_996:
	/* 0x996: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_999:
	/* 0x999: je     9be <generic_sleepable_preload+0x9be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9be;
	}
x86_l_99b:
	/* 0x99b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_9a0:
	/* 0x9a0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9a5:
	/* 0x9a5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9aa:
	/* 0x9aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9af:
	/* 0x9af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b1:
	/* 0x9b1: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9b6:
	/* 0x9b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9b8:
	/* 0x9b8: js     e94 <generic_sleepable_preload+0xe94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3732ULL;
	}
x86_l_9be:
	/* 0x9be: cmp    WORD PTR [rdi+r12*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743798831644672ULL);
x86_l_9c5:
	/* 0x9c5: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4124ULL;
	}
x86_l_9cb:
	/* 0x9cb: mov    eax,DWORD PTR [rdi+r12*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551546ULL);
x86_l_9d0:
	/* 0x9d0: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_9d5:
	/* 0x9d5: cmp    WORD PTR [rdi+r12*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743790241710080ULL);
x86_l_9dc:
	/* 0x9dc: je     a01 <generic_sleepable_preload+0xa01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a01;
	}
x86_l_9de:
	/* 0x9de: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_9e3:
	/* 0x9e3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9e8:
	/* 0x9e8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9ed:
	/* 0x9ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9f2:
	/* 0x9f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f4:
	/* 0x9f4: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9f9:
	/* 0x9f9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9fb:
	/* 0x9fb: js     eaa <generic_sleepable_preload+0xeaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3754ULL;
	}
x86_l_a01:
	/* 0xa01: cmp    WORD PTR [rdi+r12*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743833191383040ULL);
x86_l_a08:
	/* 0xa08: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4124ULL;
	}
x86_l_a0e:
	/* 0xa0e: mov    eax,DWORD PTR [rdi+r12*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551554ULL);
x86_l_a13:
	/* 0xa13: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a18:
	/* 0xa18: cmp    WORD PTR [rdi+r12*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743824601448448ULL);
x86_l_a1f:
	/* 0xa1f: je     a44 <generic_sleepable_preload+0xa44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a44;
	}
x86_l_a21:
	/* 0xa21: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a26:
	/* 0xa26: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a2b:
	/* 0xa2b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a30:
	/* 0xa30: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a35:
	/* 0xa35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a37:
	/* 0xa37: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a3c:
	/* 0xa3c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a3e:
	/* 0xa3e: js     ee9 <generic_sleepable_preload+0xee9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3817ULL;
	}
x86_l_a44:
	/* 0xa44: cmp    WORD PTR [rdi+r12*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743867551121408ULL);
x86_l_a4b:
	/* 0xa4b: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4124ULL;
	}
x86_l_a51:
	/* 0xa51: mov    eax,DWORD PTR [rdi+r12*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551562ULL);
x86_l_a56:
	/* 0xa56: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a5b:
	/* 0xa5b: cmp    WORD PTR [rdi+r12*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743858961186816ULL);
x86_l_a62:
	/* 0xa62: je     a87 <generic_sleepable_preload+0xa87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a87;
	}
x86_l_a64:
	/* 0xa64: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a69:
	/* 0xa69: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a6e:
	/* 0xa6e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a73:
	/* 0xa73: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a78:
	/* 0xa78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a7a:
	/* 0xa7a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a7f:
	/* 0xa7f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a81:
	/* 0xa81: js     efc <generic_sleepable_preload+0xefc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3836ULL;
	}
x86_l_a87:
	/* 0xa87: cmp    WORD PTR [rdi+r12*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743901910859776ULL);
x86_l_a8e:
	/* 0xa8e: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4124ULL;
	}
x86_l_a94:
	/* 0xa94: mov    eax,DWORD PTR [rdi+r12*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551570ULL);
x86_l_a99:
	/* 0xa99: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a9e:
	/* 0xa9e: cmp    WORD PTR [rdi+r12*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743893320925184ULL);
x86_l_aa5:
	/* 0xaa5: je     aca <generic_sleepable_preload+0xaca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_aca;
	}
x86_l_aa7:
	/* 0xaa7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_aac:
	/* 0xaac: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ab1:
	/* 0xab1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ab6:
	/* 0xab6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_abb:
	/* 0xabb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_abd:
	/* 0xabd: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ac2:
	/* 0xac2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ac4:
	/* 0xac4: js     f0f <generic_sleepable_preload+0xf0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3855ULL;
	}
x86_l_aca:
	/* 0xaca: cmp    WORD PTR [rdi+r12*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743936270598144ULL);
x86_l_ad1:
	/* 0xad1: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4124ULL;
	}
x86_l_ad7:
	/* 0xad7: mov    eax,DWORD PTR [rdi+r12*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551578ULL);
x86_l_adc:
	/* 0xadc: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ae1:
	/* 0xae1: cmp    WORD PTR [rdi+r12*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743927680663552ULL);
x86_l_ae8:
	/* 0xae8: je     b0d <generic_sleepable_preload+0xb0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b0d;
	}
x86_l_aea:
	/* 0xaea: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_aef:
	/* 0xaef: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_af4:
	/* 0xaf4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_af9:
	/* 0xaf9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_afe:
	/* 0xafe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b00:
	/* 0xb00: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b05:
	/* 0xb05: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b07:
	/* 0xb07: js     f22 <generic_sleepable_preload+0xf22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3874ULL;
	}
x86_l_b0d:
	/* 0xb0d: cmp    WORD PTR [rdi+r12*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743970630336512ULL);
x86_l_b14:
	/* 0xb14: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4124ULL;
	}
x86_l_b1a:
	/* 0xb1a: mov    eax,DWORD PTR [rdi+r12*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551586ULL);
x86_l_b1f:
	/* 0xb1f: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b24:
	/* 0xb24: cmp    WORD PTR [rdi+r12*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743962040401920ULL);
x86_l_b2b:
	/* 0xb2b: je     b50 <generic_sleepable_preload+0xb50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b50;
	}
x86_l_b2d:
	/* 0xb2d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b32:
	/* 0xb32: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b37:
	/* 0xb37: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b3c:
	/* 0xb3c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b41:
	/* 0xb41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b43:
	/* 0xb43: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b48:
	/* 0xb48: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b4a:
	/* 0xb4a: js     100e <generic_sleepable_preload+0x100e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4110ULL;
	}
x86_l_b50:
	/* 0xb50: cmp    WORD PTR [rdi+r12*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744004990074880ULL);
x86_l_b57:
	/* 0xb57: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4124ULL;
	}
x86_l_b5d:
	/* 0xb5d: mov    eax,DWORD PTR [rdi+r12*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551594ULL);
x86_l_b62:
	/* 0xb62: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b67:
	/* 0xb67: cmp    WORD PTR [rdi+r12*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743996400140288ULL);
x86_l_b6e:
	/* 0xb6e: je     b93 <generic_sleepable_preload+0xb93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b93;
	}
x86_l_b70:
	/* 0xb70: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b75:
	/* 0xb75: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b7a:
	/* 0xb7a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b7f:
	/* 0xb7f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b84:
	/* 0xb84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b86:
	/* 0xb86: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b8b:
	/* 0xb8b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b8d:
	/* 0xb8d: js     10dd <generic_sleepable_preload+0x10dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4317ULL;
	}
x86_l_b93:
	/* 0xb93: cmp    WORD PTR [rdi+r12*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744039349813248ULL);
x86_l_b9a:
	/* 0xb9a: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4124ULL;
	}
x86_l_ba0:
	/* 0xba0: mov    eax,DWORD PTR [rdi+r12*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551602ULL);
x86_l_ba5:
	/* 0xba5: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_baa:
	/* 0xbaa: cmp    WORD PTR [rdi+r12*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744030759878656ULL);
x86_l_bb1:
	/* 0xbb1: je     bd6 <generic_sleepable_preload+0xbd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bd6;
	}
x86_l_bb3:
	/* 0xbb3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_bb8:
	/* 0xbb8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bbd:
	/* 0xbbd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bc2:
	/* 0xbc2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bc7:
	/* 0xbc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bc9:
	/* 0xbc9: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bce:
	/* 0xbce: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bd0:
	/* 0xbd0: js     1104 <generic_sleepable_preload+0x1104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4356ULL;
	}
x86_l_bd6:
	/* 0xbd6: cmp    WORD PTR [rdi+r12*1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_bdc:
	/* 0xbdc: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4124ULL;
	}
x86_l_be2:
	/* 0xbe2: mov    eax,DWORD PTR [rdi+r12*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551610ULL);
x86_l_be7:
	/* 0xbe7: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_bec:
	/* 0xbec: cmp    WORD PTR [rdi+r12*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744065119617024ULL);
x86_l_bf3:
	/* 0xbf3: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4124ULL;
	}
x86_l_bf9:
	/* 0xbf9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_bfe:
	/* 0xbfe: jmp    e6b <generic_sleepable_preload+0xe6b> */
	return 3691ULL;
x86_l_c03:
	/* 0xc03: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_c06:
	/* 0xc06: je     c2b <generic_sleepable_preload+0xc2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c2b;
	}
x86_l_c08:
	/* 0xc08: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c0d:
	/* 0xc0d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c12:
	/* 0xc12: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c17:
	/* 0xc17: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c1c:
	/* 0xc1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c1e:
	/* 0xc1e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c23:
	/* 0xc23: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c25:
	/* 0xc25: js     e94 <generic_sleepable_preload+0xe94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3732ULL;
	}
x86_l_c2b:
	/* 0xc2b: cmp    WORD PTR [rdi+r12*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743798831644672ULL);
x86_l_c32:
	/* 0xc32: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4124ULL;
	}
x86_l_c38:
	/* 0xc38: mov    eax,DWORD PTR [rdi+r12*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551546ULL);
x86_l_c3d:
	/* 0xc3d: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c42:
	/* 0xc42: cmp    WORD PTR [rdi+r12*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743790241710080ULL);
x86_l_c49:
	/* 0xc49: je     c6e <generic_sleepable_preload+0xc6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c6e;
	}
x86_l_c4b:
	/* 0xc4b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c50:
	/* 0xc50: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c55:
	/* 0xc55: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c5a:
	/* 0xc5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c5f:
	/* 0xc5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c61:
	/* 0xc61: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c66:
	/* 0xc66: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c68:
	/* 0xc68: js     eaa <generic_sleepable_preload+0xeaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3754ULL;
	}
x86_l_c6e:
	/* 0xc6e: cmp    WORD PTR [rdi+r12*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743833191383040ULL);
x86_l_c75:
	/* 0xc75: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4124ULL;
	}
x86_l_c7b:
	/* 0xc7b: mov    eax,DWORD PTR [rdi+r12*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551554ULL);
x86_l_c80:
	/* 0xc80: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c85:
	/* 0xc85: cmp    WORD PTR [rdi+r12*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743824601448448ULL);
x86_l_c8c:
	/* 0xc8c: je     cb1 <generic_sleepable_preload+0xcb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cb1;
	}
x86_l_c8e:
	/* 0xc8e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c93:
	/* 0xc93: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c98:
	/* 0xc98: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c9d:
	/* 0xc9d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ca2:
	/* 0xca2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca4:
	/* 0xca4: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ca9:
	/* 0xca9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cab:
	/* 0xcab: js     ee9 <generic_sleepable_preload+0xee9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3817ULL;
	}
x86_l_cb1:
	/* 0xcb1: cmp    WORD PTR [rdi+r12*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743867551121408ULL);
x86_l_cb8:
	/* 0xcb8: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4124ULL;
	}
x86_l_cbe:
	/* 0xcbe: mov    eax,DWORD PTR [rdi+r12*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551562ULL);
x86_l_cc3:
	/* 0xcc3: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_cc8:
	/* 0xcc8: cmp    WORD PTR [rdi+r12*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743858961186816ULL);
x86_l_ccf:
	/* 0xccf: je     cf4 <generic_sleepable_preload+0xcf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cf4;
	}
x86_l_cd1:
	/* 0xcd1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_cd6:
	/* 0xcd6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cdb:
	/* 0xcdb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ce0:
	/* 0xce0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ce5:
	/* 0xce5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce7:
	/* 0xce7: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cec:
	/* 0xcec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cee:
	/* 0xcee: js     efc <generic_sleepable_preload+0xefc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3836ULL;
	}
x86_l_cf4:
	/* 0xcf4: cmp    WORD PTR [rdi+r12*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743901910859776ULL);
x86_l_cfb:
	/* 0xcfb: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4124ULL;
	}
x86_l_d01:
	/* 0xd01: mov    eax,DWORD PTR [rdi+r12*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551570ULL);
x86_l_d06:
	/* 0xd06: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d0b:
	/* 0xd0b: cmp    WORD PTR [rdi+r12*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743893320925184ULL);
x86_l_d12:
	/* 0xd12: je     d37 <generic_sleepable_preload+0xd37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d37;
	}
x86_l_d14:
	/* 0xd14: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d19:
	/* 0xd19: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d1e:
	/* 0xd1e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d23:
	/* 0xd23: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d28:
	/* 0xd28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d2a:
	/* 0xd2a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d2f:
	/* 0xd2f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d31:
	/* 0xd31: js     f0f <generic_sleepable_preload+0xf0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3855ULL;
	}
x86_l_d37:
	/* 0xd37: cmp    WORD PTR [rdi+r12*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743936270598144ULL);
x86_l_d3e:
	/* 0xd3e: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4124ULL;
	}
x86_l_d44:
	/* 0xd44: mov    eax,DWORD PTR [rdi+r12*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551578ULL);
x86_l_d49:
	/* 0xd49: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d4e:
	/* 0xd4e: cmp    WORD PTR [rdi+r12*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743927680663552ULL);
x86_l_d55:
	/* 0xd55: je     d7a <generic_sleepable_preload+0xd7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d7a;
	}
x86_l_d57:
	/* 0xd57: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d5c:
	/* 0xd5c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d61:
	/* 0xd61: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d66:
	/* 0xd66: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d6b:
	/* 0xd6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d6d:
	/* 0xd6d: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d72:
	/* 0xd72: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d74:
	/* 0xd74: js     f22 <generic_sleepable_preload+0xf22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3874ULL;
	}
x86_l_d7a:
	/* 0xd7a: cmp    WORD PTR [rdi+r12*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743970630336512ULL);
x86_l_d81:
	/* 0xd81: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4124ULL;
	}
x86_l_d87:
	/* 0xd87: mov    eax,DWORD PTR [rdi+r12*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551586ULL);
x86_l_d8c:
	/* 0xd8c: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d91:
	/* 0xd91: cmp    WORD PTR [rdi+r12*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743962040401920ULL);
x86_l_d98:
	/* 0xd98: je     dbd <generic_sleepable_preload+0xdbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dbd;
	}
x86_l_d9a:
	/* 0xd9a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d9f:
	/* 0xd9f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_da4:
	/* 0xda4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_da9:
	/* 0xda9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dae:
	/* 0xdae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db0:
	/* 0xdb0: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_db5:
	/* 0xdb5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_db7:
	/* 0xdb7: js     100e <generic_sleepable_preload+0x100e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4110ULL;
	}
x86_l_dbd:
	/* 0xdbd: cmp    WORD PTR [rdi+r12*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744004990074880ULL);
x86_l_dc4:
	/* 0xdc4: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4124ULL;
	}
x86_l_dca:
	/* 0xdca: mov    eax,DWORD PTR [rdi+r12*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551594ULL);
x86_l_dcf:
	/* 0xdcf: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_dd4:
	/* 0xdd4: cmp    WORD PTR [rdi+r12*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743996400140288ULL);
x86_l_ddb:
	/* 0xddb: je     e00 <generic_sleepable_preload+0xe00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e00;
	}
x86_l_ddd:
	/* 0xddd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_de2:
	/* 0xde2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_de7:
	/* 0xde7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dec:
	/* 0xdec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_df1:
	/* 0xdf1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_df3:
	/* 0xdf3: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_df8:
	/* 0xdf8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dfa:
	/* 0xdfa: js     10dd <generic_sleepable_preload+0x10dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4317ULL;
	}
x86_l_e00:
	/* 0xe00: cmp    WORD PTR [rdi+r12*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744039349813248ULL);
	return 3591ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3591ULL: goto x86_l_e07;
	case 3597ULL: goto x86_l_e0d;
	case 3602ULL: goto x86_l_e12;
	case 3607ULL: goto x86_l_e17;
	case 3614ULL: goto x86_l_e1e;
	case 3616ULL: goto x86_l_e20;
	case 3621ULL: goto x86_l_e25;
	case 3626ULL: goto x86_l_e2a;
	case 3631ULL: goto x86_l_e2f;
	case 3636ULL: goto x86_l_e34;
	case 3638ULL: goto x86_l_e36;
	case 3643ULL: goto x86_l_e3b;
	case 3645ULL: goto x86_l_e3d;
	case 3651ULL: goto x86_l_e43;
	case 3657ULL: goto x86_l_e49;
	case 3663ULL: goto x86_l_e4f;
	case 3668ULL: goto x86_l_e54;
	case 3673ULL: goto x86_l_e59;
	case 3680ULL: goto x86_l_e60;
	case 3686ULL: goto x86_l_e66;
	case 3691ULL: goto x86_l_e6b;
	case 3696ULL: goto x86_l_e70;
	case 3701ULL: goto x86_l_e75;
	case 3706ULL: goto x86_l_e7a;
	case 3708ULL: goto x86_l_e7c;
	case 3713ULL: goto x86_l_e81;
	case 3715ULL: goto x86_l_e83;
	case 3721ULL: goto x86_l_e89;
	case 3727ULL: goto x86_l_e8f;
	case 3732ULL: goto x86_l_e94;
	case 3738ULL: goto x86_l_e9a;
	case 3743ULL: goto x86_l_e9f;
	case 3749ULL: goto x86_l_ea5;
	case 3754ULL: goto x86_l_eaa;
	case 3760ULL: goto x86_l_eb0;
	case 3765ULL: goto x86_l_eb5;
	case 3770ULL: goto x86_l_eba;
	case 3775ULL: goto x86_l_ebf;
	case 3779ULL: goto x86_l_ec3;
	case 3782ULL: goto x86_l_ec6;
	case 3787ULL: goto x86_l_ecb;
	case 3789ULL: goto x86_l_ecd;
	case 3791ULL: goto x86_l_ecf;
	case 3796ULL: goto x86_l_ed4;
	case 3802ULL: goto x86_l_eda;
	case 3804ULL: goto x86_l_edc;
	case 3809ULL: goto x86_l_ee1;
	case 3815ULL: goto x86_l_ee7;
	case 3817ULL: goto x86_l_ee9;
	case 3823ULL: goto x86_l_eef;
	case 3828ULL: goto x86_l_ef4;
	case 3834ULL: goto x86_l_efa;
	case 3836ULL: goto x86_l_efc;
	case 3842ULL: goto x86_l_f02;
	case 3847ULL: goto x86_l_f07;
	case 3853ULL: goto x86_l_f0d;
	case 3855ULL: goto x86_l_f0f;
	case 3861ULL: goto x86_l_f15;
	case 3866ULL: goto x86_l_f1a;
	case 3872ULL: goto x86_l_f20;
	case 3874ULL: goto x86_l_f22;
	case 3880ULL: goto x86_l_f28;
	case 3885ULL: goto x86_l_f2d;
	case 3891ULL: goto x86_l_f33;
	case 3894ULL: goto x86_l_f36;
	case 3897ULL: goto x86_l_f39;
	case 3902ULL: goto x86_l_f3e;
	case 3907ULL: goto x86_l_f43;
	case 3912ULL: goto x86_l_f48;
	case 3915ULL: goto x86_l_f4b;
	case 3917ULL: goto x86_l_f4d;
	case 3920ULL: goto x86_l_f50;
	case 3926ULL: goto x86_l_f56;
	case 3931ULL: goto x86_l_f5b;
	case 3936ULL: goto x86_l_f60;
	case 3944ULL: goto x86_l_f68;
	case 3949ULL: goto x86_l_f6d;
	case 3951ULL: goto x86_l_f6f;
	case 3956ULL: goto x86_l_f74;
	case 3964ULL: goto x86_l_f7c;
	case 3969ULL: goto x86_l_f81;
	case 3976ULL: goto x86_l_f88;
	case 3981ULL: goto x86_l_f8d;
	case 3983ULL: goto x86_l_f8f;
	case 3986ULL: goto x86_l_f92;
	case 3992ULL: goto x86_l_f98;
	case 3998ULL: goto x86_l_f9e;
	case 4001ULL: goto x86_l_fa1;
	case 4008ULL: goto x86_l_fa8;
	case 4011ULL: goto x86_l_fab;
	case 4014ULL: goto x86_l_fae;
	case 4019ULL: goto x86_l_fb3;
	case 4022ULL: goto x86_l_fb6;
	case 4025ULL: goto x86_l_fb9;
	case 4027ULL: goto x86_l_fbb;
	case 4030ULL: goto x86_l_fbe;
	case 4035ULL: goto x86_l_fc3;
	case 4038ULL: goto x86_l_fc6;
	case 4041ULL: goto x86_l_fc9;
	case 4043ULL: goto x86_l_fcb;
	case 4046ULL: goto x86_l_fce;
	case 4052ULL: goto x86_l_fd4;
	case 4054ULL: goto x86_l_fd6;
	case 4060ULL: goto x86_l_fdc;
	case 4064ULL: goto x86_l_fe0;
	case 4069ULL: goto x86_l_fe5;
	case 4077ULL: goto x86_l_fed;
	case 4079ULL: goto x86_l_fef;
	case 4082ULL: goto x86_l_ff2;
	case 4087ULL: goto x86_l_ff7;
	case 4089ULL: goto x86_l_ff9;
	case 4092ULL: goto x86_l_ffc;
	case 4094ULL: goto x86_l_ffe;
	case 4100ULL: goto x86_l_1004;
	case 4105ULL: goto x86_l_1009;
	case 4110ULL: goto x86_l_100e;
	case 4116ULL: goto x86_l_1014;
	case 4124ULL: goto x86_l_101c;
	case 4127ULL: goto x86_l_101f;
	case 4133ULL: goto x86_l_1025;
	case 4138ULL: goto x86_l_102a;
	case 4146ULL: goto x86_l_1032;
	case 4151ULL: goto x86_l_1037;
	case 4153ULL: goto x86_l_1039;
	case 4158ULL: goto x86_l_103e;
	case 4166ULL: goto x86_l_1046;
	case 4171ULL: goto x86_l_104b;
	case 4178ULL: goto x86_l_1052;
	case 4183ULL: goto x86_l_1057;
	case 4185ULL: goto x86_l_1059;
	case 4188ULL: goto x86_l_105c;
	case 4194ULL: goto x86_l_1062;
	case 4200ULL: goto x86_l_1068;
	case 4203ULL: goto x86_l_106b;
	case 4210ULL: goto x86_l_1072;
	case 4213ULL: goto x86_l_1075;
	case 4218ULL: goto x86_l_107a;
	case 4221ULL: goto x86_l_107d;
	case 4224ULL: goto x86_l_1080;
	case 4226ULL: goto x86_l_1082;
	case 4229ULL: goto x86_l_1085;
	case 4234ULL: goto x86_l_108a;
	case 4237ULL: goto x86_l_108d;
	case 4240ULL: goto x86_l_1090;
	case 4242ULL: goto x86_l_1092;
	case 4245ULL: goto x86_l_1095;
	case 4251ULL: goto x86_l_109b;
	case 4254ULL: goto x86_l_109e;
	case 4259ULL: goto x86_l_10a3;
	case 4261ULL: goto x86_l_10a5;
	case 4265ULL: goto x86_l_10a9;
	case 4270ULL: goto x86_l_10ae;
	case 4278ULL: goto x86_l_10b6;
	case 4280ULL: goto x86_l_10b8;
	case 4285ULL: goto x86_l_10bd;
	case 4287ULL: goto x86_l_10bf;
	case 4289ULL: goto x86_l_10c1;
	case 4294ULL: goto x86_l_10c6;
	case 4298ULL: goto x86_l_10ca;
	case 4303ULL: goto x86_l_10cf;
	case 4306ULL: goto x86_l_10d2;
	case 4312ULL: goto x86_l_10d8;
	case 4317ULL: goto x86_l_10dd;
	case 4325ULL: goto x86_l_10e5;
	case 4331ULL: goto x86_l_10eb;
	case 4334ULL: goto x86_l_10ee;
	case 4340ULL: goto x86_l_10f4;
	case 4345ULL: goto x86_l_10f9;
	case 4351ULL: goto x86_l_10ff;
	case 4356ULL: goto x86_l_1104;
	case 4362ULL: goto x86_l_110a;
	case 4367ULL: goto x86_l_110f;
	case 4370ULL: goto x86_l_1112;
	case 4375ULL: goto x86_l_1117;
	case 4381ULL: goto x86_l_111d;
	case 4383ULL: goto x86_l_111f;
	case 4385ULL: goto x86_l_1121;
	case 4392ULL: goto x86_l_1128;
	case 4394ULL: goto x86_l_112a;
	case 4397ULL: goto x86_l_112d;
	case 4403ULL: goto x86_l_1133;
	case 4406ULL: goto x86_l_1136;
	case 4412ULL: goto x86_l_113c;
	case 4415ULL: goto x86_l_113f;
	case 4421ULL: goto x86_l_1145;
	case 4427ULL: goto x86_l_114b;
	case 4433ULL: goto x86_l_1151;
	case 4436ULL: goto x86_l_1154;
	case 4441ULL: goto x86_l_1159;
	case 4446ULL: goto x86_l_115e;
	case 4451ULL: goto x86_l_1163;
	case 4453ULL: goto x86_l_1165;
	case 4458ULL: goto x86_l_116a;
	case 4460ULL: goto x86_l_116c;
	case 4466ULL: goto x86_l_1172;
	case 4468ULL: goto x86_l_1174;
	case 4473ULL: goto x86_l_1179;
	case 4480ULL: goto x86_l_1180;
	case 4487ULL: goto x86_l_1187;
	case 4493ULL: goto x86_l_118d;
	case 4495ULL: goto x86_l_118f;
	case 4498ULL: goto x86_l_1192;
	case 4504ULL: goto x86_l_1198;
	case 4507ULL: goto x86_l_119b;
	case 4513ULL: goto x86_l_11a1;
	case 4516ULL: goto x86_l_11a4;
	case 4522ULL: goto x86_l_11aa;
	case 4530ULL: goto x86_l_11b2;
	case 4533ULL: goto x86_l_11b5;
	case 4539ULL: goto x86_l_11bb;
	case 4544ULL: goto x86_l_11c0;
	case 4547ULL: goto x86_l_11c3;
	case 4553ULL: goto x86_l_11c9;
	case 4556ULL: goto x86_l_11cc;
	case 4562ULL: goto x86_l_11d2;
	case 4567ULL: goto x86_l_11d7;
	case 4572ULL: goto x86_l_11dc;
	case 4575ULL: goto x86_l_11df;
	case 4581ULL: goto x86_l_11e5;
	case 4584ULL: goto x86_l_11e8;
	case 4590ULL: goto x86_l_11ee;
	case 4596ULL: goto x86_l_11f4;
	case 4602ULL: goto x86_l_11fa;
	case 4605ULL: goto x86_l_11fd;
	case 4610ULL: goto x86_l_1202;
	case 4613ULL: goto x86_l_1205;
	case 4618ULL: goto x86_l_120a;
	case 4623ULL: goto x86_l_120f;
	case 4625ULL: goto x86_l_1211;
	case 4627ULL: goto x86_l_1213;
	case 4633ULL: goto x86_l_1219;
	case 4639ULL: goto x86_l_121f;
	case 4645ULL: goto x86_l_1225;
	case 4648ULL: goto x86_l_1228;
	case 4653ULL: goto x86_l_122d;
	case 4658ULL: goto x86_l_1232;
	case 4663ULL: goto x86_l_1237;
	case 4665ULL: goto x86_l_1239;
	case 4667ULL: goto x86_l_123b;
	case 4673ULL: goto x86_l_1241;
	case 4678ULL: goto x86_l_1246;
	case 4685ULL: goto x86_l_124d;
	case 4692ULL: goto x86_l_1254;
	case 4699ULL: goto x86_l_125b;
	case 4704ULL: goto x86_l_1260;
	case 4707ULL: goto x86_l_1263;
	case 4712ULL: goto x86_l_1268;
	case 4715ULL: goto x86_l_126b;
	case 4717ULL: goto x86_l_126d;
	case 4720ULL: goto x86_l_1270;
	case 4726ULL: goto x86_l_1276;
	case 4729ULL: goto x86_l_1279;
	case 4731ULL: goto x86_l_127b;
	case 4737ULL: goto x86_l_1281;
	case 4740ULL: goto x86_l_1284;
	case 4743ULL: goto x86_l_1287;
	case 4749ULL: goto x86_l_128d;
	case 4754ULL: goto x86_l_1292;
	case 4757ULL: goto x86_l_1295;
	case 4763ULL: goto x86_l_129b;
	case 4771ULL: goto x86_l_12a3;
	case 4774ULL: goto x86_l_12a6;
	case 4780ULL: goto x86_l_12ac;
	case 4785ULL: goto x86_l_12b1;
	case 4788ULL: goto x86_l_12b4;
	case 4794ULL: goto x86_l_12ba;
	case 4799ULL: goto x86_l_12bf;
	case 4802ULL: goto x86_l_12c2;
	case 4808ULL: goto x86_l_12c8;
	case 4816ULL: goto x86_l_12d0;
	case 4819ULL: goto x86_l_12d3;
	case 4825ULL: goto x86_l_12d9;
	case 4830ULL: goto x86_l_12de;
	case 4833ULL: goto x86_l_12e1;
	case 4839ULL: goto x86_l_12e7;
	case 4844ULL: goto x86_l_12ec;
	case 4851ULL: goto x86_l_12f3;
	case 4856ULL: goto x86_l_12f8;
	case 4863ULL: goto x86_l_12ff;
	case 4870ULL: goto x86_l_1306;
	case 4875ULL: goto x86_l_130b;
	case 4882ULL: goto x86_l_1312;
	case 4887ULL: goto x86_l_1317;
	case 4892ULL: goto x86_l_131c;
	case 4896ULL: goto x86_l_1320;
	case 4898ULL: goto x86_l_1322;
	case 4904ULL: goto x86_l_1328;
	case 4910ULL: goto x86_l_132e;
	case 4913ULL: goto x86_l_1331;
	case 4918ULL: goto x86_l_1336;
	case 4921ULL: goto x86_l_1339;
	case 4926ULL: goto x86_l_133e;
	case 4931ULL: goto x86_l_1343;
	case 4933ULL: goto x86_l_1345;
	case 4935ULL: goto x86_l_1347;
	case 4941ULL: goto x86_l_134d;
	case 4943ULL: goto x86_l_134f;
	case 4946ULL: goto x86_l_1352;
	case 4951ULL: goto x86_l_1357;
	case 4953ULL: goto x86_l_1359;
	case 4956ULL: goto x86_l_135c;
	case 4961ULL: goto x86_l_1361;
	case 4967ULL: goto x86_l_1367;
	case 4974ULL: goto x86_l_136e;
	case 4977ULL: goto x86_l_1371;
	case 4980ULL: goto x86_l_1374;
	case 4983ULL: goto x86_l_1377;
	case 4988ULL: goto x86_l_137c;
	case 4992ULL: goto x86_l_1380;
	case 4994ULL: goto x86_l_1382;
	case 5000ULL: goto x86_l_1388;
	case 5003ULL: goto x86_l_138b;
	case 5005ULL: goto x86_l_138d;
	case 5010ULL: goto x86_l_1392;
	case 5015ULL: goto x86_l_1397;
	case 5020ULL: goto x86_l_139c;
	case 5025ULL: goto x86_l_13a1;
	case 5027ULL: goto x86_l_13a3;
	case 5032ULL: goto x86_l_13a8;
	case 5034ULL: goto x86_l_13aa;
	case 5040ULL: goto x86_l_13b0;
	case 5045ULL: goto x86_l_13b5;
	case 5051ULL: goto x86_l_13bb;
	case 5054ULL: goto x86_l_13be;
	case 5059ULL: goto x86_l_13c3;
	case 5064ULL: goto x86_l_13c8;
	case 5066ULL: goto x86_l_13ca;
	case 5071ULL: goto x86_l_13cf;
	case 5076ULL: goto x86_l_13d4;
	case 5081ULL: goto x86_l_13d9;
	case 5086ULL: goto x86_l_13de;
	case 5088ULL: goto x86_l_13e0;
	case 5093ULL: goto x86_l_13e5;
	case 5095ULL: goto x86_l_13e7;
	case 5101ULL: goto x86_l_13ed;
	case 5109ULL: goto x86_l_13f5;
	case 5115ULL: goto x86_l_13fb;
	case 5121ULL: goto x86_l_1401;
	case 5126ULL: goto x86_l_1406;
	case 5134ULL: goto x86_l_140e;
	case 5136ULL: goto x86_l_1410;
	case 5141ULL: goto x86_l_1415;
	case 5146ULL: goto x86_l_141a;
	case 5151ULL: goto x86_l_141f;
	case 5156ULL: goto x86_l_1424;
	case 5158ULL: goto x86_l_1426;
	case 5163ULL: goto x86_l_142b;
	case 5165ULL: goto x86_l_142d;
	case 5171ULL: goto x86_l_1433;
	case 5179ULL: goto x86_l_143b;
	case 5185ULL: goto x86_l_1441;
	case 5191ULL: goto x86_l_1447;
	case 5196ULL: goto x86_l_144c;
	case 5204ULL: goto x86_l_1454;
	case 5206ULL: goto x86_l_1456;
	case 5211ULL: goto x86_l_145b;
	case 5216ULL: goto x86_l_1460;
	case 5221ULL: goto x86_l_1465;
	case 5226ULL: goto x86_l_146a;
	case 5228ULL: goto x86_l_146c;
	case 5233ULL: goto x86_l_1471;
	case 5235ULL: goto x86_l_1473;
	case 5241ULL: goto x86_l_1479;
	case 5249ULL: goto x86_l_1481;
	case 5255ULL: goto x86_l_1487;
	case 5261ULL: goto x86_l_148d;
	case 5266ULL: goto x86_l_1492;
	case 5274ULL: goto x86_l_149a;
	case 5276ULL: goto x86_l_149c;
	case 5281ULL: goto x86_l_14a1;
	case 5286ULL: goto x86_l_14a6;
	case 5291ULL: goto x86_l_14ab;
	case 5296ULL: goto x86_l_14b0;
	case 5298ULL: goto x86_l_14b2;
	case 5303ULL: goto x86_l_14b7;
	case 5305ULL: goto x86_l_14b9;
	case 5311ULL: goto x86_l_14bf;
	case 5319ULL: goto x86_l_14c7;
	case 5325ULL: goto x86_l_14cd;
	case 5331ULL: goto x86_l_14d3;
	case 5336ULL: goto x86_l_14d8;
	case 5344ULL: goto x86_l_14e0;
	case 5346ULL: goto x86_l_14e2;
	case 5351ULL: goto x86_l_14e7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e07:
	/* 0xe07: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_101c;
	}
x86_l_e0d:
	/* 0xe0d: mov    eax,DWORD PTR [rdi+r12*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551602ULL);
x86_l_e12:
	/* 0xe12: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e17:
	/* 0xe17: cmp    WORD PTR [rdi+r12*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744030759878656ULL);
x86_l_e1e:
	/* 0xe1e: je     e43 <generic_sleepable_preload+0xe43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e43;
	}
x86_l_e20:
	/* 0xe20: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e25:
	/* 0xe25: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e2a:
	/* 0xe2a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e2f:
	/* 0xe2f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e34:
	/* 0xe34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e36:
	/* 0xe36: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e3b:
	/* 0xe3b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e3d:
	/* 0xe3d: js     1104 <generic_sleepable_preload+0x1104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1104;
	}
x86_l_e43:
	/* 0xe43: cmp    WORD PTR [rdi+r12*1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_e49:
	/* 0xe49: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_101c;
	}
x86_l_e4f:
	/* 0xe4f: mov    eax,DWORD PTR [rdi+r12*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551610ULL);
x86_l_e54:
	/* 0xe54: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e59:
	/* 0xe59: cmp    WORD PTR [rdi+r12*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744065119617024ULL);
x86_l_e60:
	/* 0xe60: je     101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_101c;
	}
x86_l_e66:
	/* 0xe66: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e6b:
	/* 0xe6b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e70:
	/* 0xe70: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e75:
	/* 0xe75: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e7a:
	/* 0xe7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e7c:
	/* 0xe7c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e81:
	/* 0xe81: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e83:
	/* 0xe83: jns    101c <generic_sleepable_preload+0x101c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_101c;
	}
x86_l_e89:
	/* 0xe89: mov    r15d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 10ULL);
x86_l_e8f:
	/* 0xe8f: jmp    1014 <generic_sleepable_preload+0x1014> */
	goto x86_l_1014;
x86_l_e94:
	/* 0xe94: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_e9a:
	/* 0xe9a: jmp    1014 <generic_sleepable_preload+0x1014> */
	goto x86_l_1014;
x86_l_e9f:
	/* 0xe9f: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_ea5:
	/* 0xea5: jmp    f33 <generic_sleepable_preload+0xf33> */
	goto x86_l_f33;
x86_l_eaa:
	/* 0xeaa: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_eb0:
	/* 0xeb0: jmp    1014 <generic_sleepable_preload+0x1014> */
	goto x86_l_1014;
x86_l_eb5:
	/* 0xeb5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_eba:
	/* 0xeba: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ebf:
	/* 0xebf: add    rdx,QWORD PTR [rbx-0x13] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 18446744073709551597ULL);
x86_l_ec3:
	/* 0xec3: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_ec6:
	/* 0xec6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ecb:
	/* 0xecb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ecd:
	/* 0xecd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ecf:
	/* 0xecf: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ed4:
	/* 0xed4: je     33c <generic_sleepable_preload+0x33c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 828ULL;
	}
x86_l_eda:
	/* 0xeda: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_edc:
	/* 0xedc: jmp    38c <generic_sleepable_preload+0x38c> */
	return 908ULL;
x86_l_ee1:
	/* 0xee1: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_ee7:
	/* 0xee7: jmp    f33 <generic_sleepable_preload+0xf33> */
	goto x86_l_f33;
x86_l_ee9:
	/* 0xee9: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_eef:
	/* 0xeef: jmp    1014 <generic_sleepable_preload+0x1014> */
	goto x86_l_1014;
x86_l_ef4:
	/* 0xef4: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_efa:
	/* 0xefa: jmp    f33 <generic_sleepable_preload+0xf33> */
	goto x86_l_f33;
x86_l_efc:
	/* 0xefc: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_f02:
	/* 0xf02: jmp    1014 <generic_sleepable_preload+0x1014> */
	goto x86_l_1014;
x86_l_f07:
	/* 0xf07: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_f0d:
	/* 0xf0d: jmp    f33 <generic_sleepable_preload+0xf33> */
	goto x86_l_f33;
x86_l_f0f:
	/* 0xf0f: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_f15:
	/* 0xf15: jmp    1014 <generic_sleepable_preload+0x1014> */
	goto x86_l_1014;
x86_l_f1a:
	/* 0xf1a: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_f20:
	/* 0xf20: jmp    f33 <generic_sleepable_preload+0xf33> */
	goto x86_l_f33;
x86_l_f22:
	/* 0xf22: mov    r15d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 6ULL);
x86_l_f28:
	/* 0xf28: jmp    1014 <generic_sleepable_preload+0x1014> */
	goto x86_l_1014;
x86_l_f2d:
	/* 0xf2d: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_f33:
	/* 0xf33: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f36:
	/* 0xf36: mov    ebp,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f39:
	/* 0xf39: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f3e:
	/* 0xf3e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f43:
	/* 0xf43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f48:
	/* 0xf48: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_f4b:
	/* 0xf4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f4d:
	/* 0xf4d: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_f50:
	/* 0xf50: jne    126 <generic_sleepable_preload+0x126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 294ULL;
	}
x86_l_f56:
	/* 0xf56: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f5b:
	/* 0xf5b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f60:
	/* 0xf60: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f68:
	/* 0xf68: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_f6d:
	/* 0xf6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f6f:
	/* 0xf6f: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f74:
	/* 0xf74: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_f7c:
	/* 0xf7c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f81:
	/* 0xf81: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_f88:
	/* 0xf88: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f8d:
	/* 0xf8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f8f:
	/* 0xf8f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f92:
	/* 0xf92: je     121 <generic_sleepable_preload+0x121> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 289ULL;
	}
x86_l_f98:
	/* 0xf98: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_f9e:
	/* 0xf9e: mov    ebx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_32);
x86_l_fa1:
	/* 0xfa1: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_fa8:
	/* 0xfa8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_fab:
	/* 0xfab: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_fae:
	/* 0xfae: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fb3:
	/* 0xfb3: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_fb6:
	/* 0xfb6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_fb9:
	/* 0xfb9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fbb:
	/* 0xfbb: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_fbe:
	/* 0xfbe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fc3:
	/* 0xfc3: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_fc6:
	/* 0xfc6: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_fc9:
	/* 0xfc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fcb:
	/* 0xfcb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fce:
	/* 0xfce: je     121 <generic_sleepable_preload+0x121> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 289ULL;
	}
x86_l_fd4:
	/* 0xfd4: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
x86_l_fd6:
	/* 0xfd6: je     11f <generic_sleepable_preload+0x11f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 287ULL;
	}
x86_l_fdc:
	/* 0xfdc: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_fe0:
	/* 0xfe0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_fe5:
	/* 0xfe5: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_fed:
	/* 0xfed: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fef:
	/* 0xfef: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_ff2:
	/* 0xff2: call   ff7 <generic_sleepable_preload+0xff7> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_ff7:
	/* 0xff7: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_ff9:
	/* 0xff9: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_ffc:
	/* 0xffc: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_ffe:
	/* 0xffe: jns    11f <generic_sleepable_preload+0x11f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 287ULL;
	}
x86_l_1004:
	/* 0x1004: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_1009:
	/* 0x1009: jmp    11f <generic_sleepable_preload+0x11f> */
	return 287ULL;
x86_l_100e:
	/* 0x100e: mov    r15d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 7ULL);
x86_l_1014:
	/* 0x1014: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_101c:
	/* 0x101c: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_101f:
	/* 0x101f: jne    130 <generic_sleepable_preload+0x130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 304ULL;
	}
x86_l_1025:
	/* 0x1025: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_102a:
	/* 0x102a: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1032:
	/* 0x1032: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1037:
	/* 0x1037: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1039:
	/* 0x1039: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_103e:
	/* 0x103e: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1046:
	/* 0x1046: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_104b:
	/* 0x104b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1052:
	/* 0x1052: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1057:
	/* 0x1057: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1059:
	/* 0x1059: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_105c:
	/* 0x105c: je     126 <generic_sleepable_preload+0x126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 294ULL;
	}
x86_l_1062:
	/* 0x1062: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_1068:
	/* 0x1068: mov    ebp,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_32);
x86_l_106b:
	/* 0x106b: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1072:
	/* 0x1072: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1075:
	/* 0x1075: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_107a:
	/* 0x107a: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_107d:
	/* 0x107d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1080:
	/* 0x1080: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1082:
	/* 0x1082: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1085:
	/* 0x1085: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_108a:
	/* 0x108a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_108d:
	/* 0x108d: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1090:
	/* 0x1090: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1092:
	/* 0x1092: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1095:
	/* 0x1095: je     126 <generic_sleepable_preload+0x126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 294ULL;
	}
x86_l_109b:
	/* 0x109b: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_109e:
	/* 0x109e: cmp    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_10a3:
	/* 0x10a3: je     10c6 <generic_sleepable_preload+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c6;
	}
x86_l_10a5:
	/* 0x10a5: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10a9:
	/* 0x10a9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_10ae:
	/* 0x10ae: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_10b6:
	/* 0x10b6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10b8:
	/* 0x10b8: call   10bd <generic_sleepable_preload+0x10bd> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_10bd:
	/* 0x10bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10bf:
	/* 0x10bf: jns    10c6 <generic_sleepable_preload+0x10c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_10c6;
	}
x86_l_10c1:
	/* 0x10c1: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_10c6:
	/* 0x10c6: mov    DWORD PTR [r13+0x0],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10ca:
	/* 0x10ca: jmp    126 <generic_sleepable_preload+0x126> */
	return 294ULL;
x86_l_10cf:
	/* 0x10cf: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10d2:
	/* 0x10d2: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_10d8:
	/* 0x10d8: jmp    f36 <generic_sleepable_preload+0xf36> */
	goto x86_l_f36;
x86_l_10dd:
	/* 0x10dd: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_10e5:
	/* 0x10e5: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_10eb:
	/* 0x10eb: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_10ee:
	/* 0x10ee: jne    130 <generic_sleepable_preload+0x130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 304ULL;
	}
x86_l_10f4:
	/* 0x10f4: jmp    1025 <generic_sleepable_preload+0x1025> */
	goto x86_l_1025;
x86_l_10f9:
	/* 0x10f9: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_10ff:
	/* 0x10ff: jmp    f33 <generic_sleepable_preload+0xf33> */
	goto x86_l_f33;
x86_l_1104:
	/* 0x1104: mov    r15d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 9ULL);
x86_l_110a:
	/* 0x110a: jmp    1014 <generic_sleepable_preload+0x1014> */
	goto x86_l_1014;
x86_l_110f:
	/* 0x110f: mov    eax,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1112:
	/* 0x1112: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_1117:
	/* 0x1117: je     2069 <generic_sleepable_preload+0x2069> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8297ULL;
	}
x86_l_111d:
	/* 0x111d: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_111f:
	/* 0x111f: js     1179 <generic_sleepable_preload+0x1179> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1179;
	}
x86_l_1121:
	/* 0x1121: movzx  ecx,BYTE PTR [rdi+0x211] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 529ULL);
x86_l_1128:
	/* 0x1128: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_112a:
	/* 0x112a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_112d:
	/* 0x112d: jg     11dc <generic_sleepable_preload+0x11dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_11dc;
	}
x86_l_1133:
	/* 0x1133: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1136:
	/* 0x1136: je     12ec <generic_sleepable_preload+0x12ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ec;
	}
x86_l_113c:
	/* 0x113c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_113f:
	/* 0x113f: jne    1352 <generic_sleepable_preload+0x1352> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1352;
	}
x86_l_1145:
	/* 0x1145: mov    edx,DWORD PTR [rdi+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_114b:
	/* 0x114b: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1151:
	/* 0x1151: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1154:
	/* 0x1154: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1159:
	/* 0x1159: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_115e:
	/* 0x115e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1163:
	/* 0x1163: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1165:
	/* 0x1165: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_116a:
	/* 0x116a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_116c:
	/* 0x116c: je     12f8 <generic_sleepable_preload+0x12f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12f8;
	}
x86_l_1172:
	/* 0x1172: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1174:
	/* 0x1174: jmp    1352 <generic_sleepable_preload+0x1352> */
	goto x86_l_1352;
x86_l_1179:
	/* 0x1179: movzx  ecx,BYTE PTR [rdi+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_1180:
	/* 0x1180: movzx  eax,WORD PTR [rdi+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_1187:
	/* 0x1187: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_118d:
	/* 0x118d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_118f:
	/* 0x118f: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1192:
	/* 0x1192: jle    1268 <generic_sleepable_preload+0x1268> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1268;
	}
x86_l_1198:
	/* 0x1198: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_119b:
	/* 0x119b: jle    1292 <generic_sleepable_preload+0x1292> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1292;
	}
x86_l_11a1:
	/* 0x11a1: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_11a4:
	/* 0x11a4: jle    1915 <generic_sleepable_preload+0x1915> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6421ULL;
	}
x86_l_11aa:
	/* 0x11aa: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_11b2:
	/* 0x11b2: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_11b5:
	/* 0x11b5: je     192c <generic_sleepable_preload+0x192c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6444ULL;
	}
x86_l_11bb:
	/* 0x11bb: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_11c0:
	/* 0x11c0: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_11c3:
	/* 0x11c3: je     192c <generic_sleepable_preload+0x192c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6444ULL;
	}
x86_l_11c9:
	/* 0x11c9: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_11cc:
	/* 0x11cc: jne    193f <generic_sleepable_preload+0x193f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6463ULL;
	}
x86_l_11d2:
	/* 0x11d2: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11d7:
	/* 0x11d7: jmp    192c <generic_sleepable_preload+0x192c> */
	return 6444ULL;
x86_l_11dc:
	/* 0x11dc: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_11df:
	/* 0x11df: je     1322 <generic_sleepable_preload+0x1322> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1322;
	}
x86_l_11e5:
	/* 0x11e5: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_11e8:
	/* 0x11e8: jne    1352 <generic_sleepable_preload+0x1352> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1352;
	}
x86_l_11ee:
	/* 0x11ee: mov    edx,DWORD PTR [rdi+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_11f4:
	/* 0x11f4: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11fa:
	/* 0x11fa: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_11fd:
	/* 0x11fd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1202:
	/* 0x1202: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_1205:
	/* 0x1205: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_120a:
	/* 0x120a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_120f:
	/* 0x120f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1211:
	/* 0x1211: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1213:
	/* 0x1213: jne    134d <generic_sleepable_preload+0x134d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_134d;
	}
x86_l_1219:
	/* 0x1219: mov    edx,DWORD PTR [rbx+0x20c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_121f:
	/* 0x121f: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1225:
	/* 0x1225: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1228:
	/* 0x1228: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_122d:
	/* 0x122d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1232:
	/* 0x1232: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1237:
	/* 0x1237: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1239:
	/* 0x1239: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_123b:
	/* 0x123b: jne    134d <generic_sleepable_preload+0x134d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_134d;
	}
x86_l_1241:
	/* 0x1241: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1246:
	/* 0x1246: movzx  ecx,BYTE PTR [rbx+0x213] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 531ULL);
x86_l_124d:
	/* 0x124d: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_1254:
	/* 0x1254: mov    rdx,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_125b:
	/* 0x125b: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1260:
	/* 0x1260: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1263:
	/* 0x1263: jmp    1edf <generic_sleepable_preload+0x1edf> */
	return 7903ULL;
x86_l_1268:
	/* 0x1268: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_126b:
	/* 0x126b: jg     12bf <generic_sleepable_preload+0x12bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_12bf;
	}
x86_l_126d:
	/* 0x126d: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1270:
	/* 0x1270: jg     18e6 <generic_sleepable_preload+0x18e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6374ULL;
	}
x86_l_1276:
	/* 0x1276: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1279:
	/* 0x1279: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_127b:
	/* 0x127b: je     192c <generic_sleepable_preload+0x192c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6444ULL;
	}
x86_l_1281:
	/* 0x1281: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1284:
	/* 0x1284: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1287:
	/* 0x1287: je     192c <generic_sleepable_preload+0x192c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6444ULL;
	}
x86_l_128d:
	/* 0x128d: jmp    193f <generic_sleepable_preload+0x193f> */
	return 6463ULL;
x86_l_1292:
	/* 0x1292: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1295:
	/* 0x1295: jg     18cd <generic_sleepable_preload+0x18cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6349ULL;
	}
x86_l_129b:
	/* 0x129b: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_12a3:
	/* 0x12a3: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_12a6:
	/* 0x12a6: je     192c <generic_sleepable_preload+0x192c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6444ULL;
	}
x86_l_12ac:
	/* 0x12ac: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_12b1:
	/* 0x12b1: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_12b4:
	/* 0x12b4: je     192c <generic_sleepable_preload+0x192c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6444ULL;
	}
x86_l_12ba:
	/* 0x12ba: jmp    193f <generic_sleepable_preload+0x193f> */
	return 6463ULL;
x86_l_12bf:
	/* 0x12bf: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_12c2:
	/* 0x12c2: jg     18fc <generic_sleepable_preload+0x18fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6396ULL;
	}
x86_l_12c8:
	/* 0x12c8: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_12d0:
	/* 0x12d0: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_12d3:
	/* 0x12d3: je     192c <generic_sleepable_preload+0x192c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6444ULL;
	}
x86_l_12d9:
	/* 0x12d9: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_12de:
	/* 0x12de: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_12e1:
	/* 0x12e1: je     192c <generic_sleepable_preload+0x192c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6444ULL;
	}
x86_l_12e7:
	/* 0x12e7: jmp    193f <generic_sleepable_preload+0x193f> */
	return 6463ULL;
x86_l_12ec:
	/* 0x12ec: mov    rax,QWORD PTR [rdi+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_12f3:
	/* 0x12f3: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12f8:
	/* 0x12f8: movzx  eax,BYTE PTR [rdi+0x210] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 528ULL);
x86_l_12ff:
	/* 0x12ff: shlx   rcx,QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((32ULL << 32) | X86_ALU_SHL));
x86_l_1306:
	/* 0x1306: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_130b:
	/* 0x130b: cmp    BYTE PTR [rdi+0x212],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2276332666880ULL);
x86_l_1312:
	/* 0x1312: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_1317:
	/* 0x1317: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_131c:
	/* 0x131c: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1320:
	/* 0x1320: jmp    1352 <generic_sleepable_preload+0x1352> */
	goto x86_l_1352;
x86_l_1322:
	/* 0x1322: mov    edx,DWORD PTR [rdi+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1328:
	/* 0x1328: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_132e:
	/* 0x132e: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1331:
	/* 0x1331: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1336:
	/* 0x1336: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_1339:
	/* 0x1339: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_133e:
	/* 0x133e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1343:
	/* 0x1343: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1345:
	/* 0x1345: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1347:
	/* 0x1347: je     1ece <generic_sleepable_preload+0x1ece> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7886ULL;
	}
x86_l_134d:
	/* 0x134d: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_134f:
	/* 0x134f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1352:
	/* 0x1352: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1357:
	/* 0x1357: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1359:
	/* 0x1359: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_135c:
	/* 0x135c: cmp    WORD PTR [rdi+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_1361:
	/* 0x1361: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_1367:
	/* 0x1367: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_136e:
	/* 0x136e: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1371:
	/* 0x1371: mov    edx,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1374:
	/* 0x1374: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1377:
	/* 0x1377: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_137c:
	/* 0x137c: movzx  eax,WORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_1380:
	/* 0x1380: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_1382:
	/* 0x1382: je     160d <generic_sleepable_preload+0x160d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5645ULL;
	}
x86_l_1388:
	/* 0x1388: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_138b:
	/* 0x138b: je     13b0 <generic_sleepable_preload+0x13b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13b0;
	}
x86_l_138d:
	/* 0x138d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1392:
	/* 0x1392: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1397:
	/* 0x1397: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_139c:
	/* 0x139c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13a1:
	/* 0x13a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a3:
	/* 0x13a3: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13a8:
	/* 0x13a8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13aa:
	/* 0x13aa: js     18c3 <generic_sleepable_preload+0x18c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6339ULL;
	}
x86_l_13b0:
	/* 0x13b0: cmp    WORD PTR [rdi+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_13b5:
	/* 0x13b5: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_13bb:
	/* 0x13bb: mov    eax,DWORD PTR [rdi+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_13be:
	/* 0x13be: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_13c3:
	/* 0x13c3: cmp    WORD PTR [rdi+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_13c8:
	/* 0x13c8: je     13ed <generic_sleepable_preload+0x13ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ed;
	}
x86_l_13ca:
	/* 0x13ca: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_13cf:
	/* 0x13cf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13d4:
	/* 0x13d4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13d9:
	/* 0x13d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13de:
	/* 0x13de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e0:
	/* 0x13e0: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13e5:
	/* 0x13e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13e7:
	/* 0x13e7: js     1ebd <generic_sleepable_preload+0x1ebd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7869ULL;
	}
x86_l_13ed:
	/* 0x13ed: cmp    WORD PTR [rdi+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_13f5:
	/* 0x13f5: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_13fb:
	/* 0x13fb: mov    eax,DWORD PTR [rdi+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1401:
	/* 0x1401: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1406:
	/* 0x1406: cmp    WORD PTR [rdi+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_140e:
	/* 0x140e: je     1433 <generic_sleepable_preload+0x1433> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1433;
	}
x86_l_1410:
	/* 0x1410: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1415:
	/* 0x1415: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_141a:
	/* 0x141a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_141f:
	/* 0x141f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1424:
	/* 0x1424: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1426:
	/* 0x1426: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_142b:
	/* 0x142b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_142d:
	/* 0x142d: js     1efd <generic_sleepable_preload+0x1efd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7933ULL;
	}
x86_l_1433:
	/* 0x1433: cmp    WORD PTR [rdi+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_143b:
	/* 0x143b: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_1441:
	/* 0x1441: mov    eax,DWORD PTR [rdi+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1447:
	/* 0x1447: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_144c:
	/* 0x144c: cmp    WORD PTR [rdi+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1454:
	/* 0x1454: je     1479 <generic_sleepable_preload+0x1479> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1479;
	}
x86_l_1456:
	/* 0x1456: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_145b:
	/* 0x145b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1460:
	/* 0x1460: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1465:
	/* 0x1465: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_146a:
	/* 0x146a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_146c:
	/* 0x146c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1471:
	/* 0x1471: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1473:
	/* 0x1473: js     1f0e <generic_sleepable_preload+0x1f0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7950ULL;
	}
x86_l_1479:
	/* 0x1479: cmp    WORD PTR [rdi+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1481:
	/* 0x1481: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_1487:
	/* 0x1487: mov    eax,DWORD PTR [rdi+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_148d:
	/* 0x148d: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1492:
	/* 0x1492: cmp    WORD PTR [rdi+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_149a:
	/* 0x149a: je     14bf <generic_sleepable_preload+0x14bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14bf;
	}
x86_l_149c:
	/* 0x149c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_14a1:
	/* 0x14a1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14a6:
	/* 0x14a6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14ab:
	/* 0x14ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14b0:
	/* 0x14b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14b2:
	/* 0x14b2: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14b7:
	/* 0x14b7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14b9:
	/* 0x14b9: js     1f1f <generic_sleepable_preload+0x1f1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7967ULL;
	}
x86_l_14bf:
	/* 0x14bf: cmp    WORD PTR [rdi+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_14c7:
	/* 0x14c7: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_14cd:
	/* 0x14cd: mov    eax,DWORD PTR [rdi+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_14d3:
	/* 0x14d3: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_14d8:
	/* 0x14d8: cmp    WORD PTR [rdi+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_14e0:
	/* 0x14e0: je     1505 <generic_sleepable_preload+0x1505> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5381ULL;
	}
x86_l_14e2:
	/* 0x14e2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_14e7:
	/* 0x14e7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 5356ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5356ULL: goto x86_l_14ec;
	case 5361ULL: goto x86_l_14f1;
	case 5366ULL: goto x86_l_14f6;
	case 5368ULL: goto x86_l_14f8;
	case 5373ULL: goto x86_l_14fd;
	case 5375ULL: goto x86_l_14ff;
	case 5381ULL: goto x86_l_1505;
	case 5389ULL: goto x86_l_150d;
	case 5395ULL: goto x86_l_1513;
	case 5401ULL: goto x86_l_1519;
	case 5406ULL: goto x86_l_151e;
	case 5414ULL: goto x86_l_1526;
	case 5416ULL: goto x86_l_1528;
	case 5421ULL: goto x86_l_152d;
	case 5426ULL: goto x86_l_1532;
	case 5431ULL: goto x86_l_1537;
	case 5436ULL: goto x86_l_153c;
	case 5438ULL: goto x86_l_153e;
	case 5440ULL: goto x86_l_1540;
	case 5446ULL: goto x86_l_1546;
	case 5451ULL: goto x86_l_154b;
	case 5459ULL: goto x86_l_1553;
	case 5465ULL: goto x86_l_1559;
	case 5471ULL: goto x86_l_155f;
	case 5476ULL: goto x86_l_1564;
	case 5484ULL: goto x86_l_156c;
	case 5486ULL: goto x86_l_156e;
	case 5491ULL: goto x86_l_1573;
	case 5496ULL: goto x86_l_1578;
	case 5501ULL: goto x86_l_157d;
	case 5506ULL: goto x86_l_1582;
	case 5508ULL: goto x86_l_1584;
	case 5510ULL: goto x86_l_1586;
	case 5516ULL: goto x86_l_158c;
	case 5521ULL: goto x86_l_1591;
	case 5529ULL: goto x86_l_1599;
	case 5535ULL: goto x86_l_159f;
	case 5541ULL: goto x86_l_15a5;
	case 5546ULL: goto x86_l_15aa;
	case 5554ULL: goto x86_l_15b2;
	case 5556ULL: goto x86_l_15b4;
	case 5561ULL: goto x86_l_15b9;
	case 5566ULL: goto x86_l_15be;
	case 5571ULL: goto x86_l_15c3;
	case 5576ULL: goto x86_l_15c8;
	case 5578ULL: goto x86_l_15ca;
	case 5580ULL: goto x86_l_15cc;
	case 5586ULL: goto x86_l_15d2;
	case 5591ULL: goto x86_l_15d7;
	case 5599ULL: goto x86_l_15df;
	case 5604ULL: goto x86_l_15e4;
	case 5610ULL: goto x86_l_15ea;
	case 5616ULL: goto x86_l_15f0;
	case 5621ULL: goto x86_l_15f5;
	case 5629ULL: goto x86_l_15fd;
	case 5635ULL: goto x86_l_1603;
	case 5640ULL: goto x86_l_1608;
	case 5645ULL: goto x86_l_160d;
	case 5648ULL: goto x86_l_1610;
	case 5650ULL: goto x86_l_1612;
	case 5655ULL: goto x86_l_1617;
	case 5660ULL: goto x86_l_161c;
	case 5665ULL: goto x86_l_1621;
	case 5670ULL: goto x86_l_1626;
	case 5672ULL: goto x86_l_1628;
	case 5677ULL: goto x86_l_162d;
	case 5679ULL: goto x86_l_162f;
	case 5685ULL: goto x86_l_1635;
	case 5690ULL: goto x86_l_163a;
	case 5696ULL: goto x86_l_1640;
	case 5699ULL: goto x86_l_1643;
	case 5704ULL: goto x86_l_1648;
	case 5709ULL: goto x86_l_164d;
	case 5711ULL: goto x86_l_164f;
	case 5716ULL: goto x86_l_1654;
	case 5721ULL: goto x86_l_1659;
	case 5726ULL: goto x86_l_165e;
	case 5731ULL: goto x86_l_1663;
	case 5733ULL: goto x86_l_1665;
	case 5738ULL: goto x86_l_166a;
	case 5740ULL: goto x86_l_166c;
	case 5746ULL: goto x86_l_1672;
	case 5754ULL: goto x86_l_167a;
	case 5760ULL: goto x86_l_1680;
	case 5766ULL: goto x86_l_1686;
	case 5771ULL: goto x86_l_168b;
	case 5779ULL: goto x86_l_1693;
	case 5781ULL: goto x86_l_1695;
	case 5786ULL: goto x86_l_169a;
	case 5791ULL: goto x86_l_169f;
	case 5796ULL: goto x86_l_16a4;
	case 5801ULL: goto x86_l_16a9;
	case 5803ULL: goto x86_l_16ab;
	case 5808ULL: goto x86_l_16b0;
	case 5810ULL: goto x86_l_16b2;
	case 5816ULL: goto x86_l_16b8;
	case 5824ULL: goto x86_l_16c0;
	case 5830ULL: goto x86_l_16c6;
	case 5836ULL: goto x86_l_16cc;
	case 5841ULL: goto x86_l_16d1;
	case 5849ULL: goto x86_l_16d9;
	case 5851ULL: goto x86_l_16db;
	case 5856ULL: goto x86_l_16e0;
	case 5861ULL: goto x86_l_16e5;
	case 5866ULL: goto x86_l_16ea;
	case 5871ULL: goto x86_l_16ef;
	case 5873ULL: goto x86_l_16f1;
	case 5878ULL: goto x86_l_16f6;
	case 5880ULL: goto x86_l_16f8;
	case 5886ULL: goto x86_l_16fe;
	case 5894ULL: goto x86_l_1706;
	case 5900ULL: goto x86_l_170c;
	case 5906ULL: goto x86_l_1712;
	case 5911ULL: goto x86_l_1717;
	case 5919ULL: goto x86_l_171f;
	case 5921ULL: goto x86_l_1721;
	case 5926ULL: goto x86_l_1726;
	case 5931ULL: goto x86_l_172b;
	case 5936ULL: goto x86_l_1730;
	case 5941ULL: goto x86_l_1735;
	case 5943ULL: goto x86_l_1737;
	case 5948ULL: goto x86_l_173c;
	case 5950ULL: goto x86_l_173e;
	case 5956ULL: goto x86_l_1744;
	case 5964ULL: goto x86_l_174c;
	case 5970ULL: goto x86_l_1752;
	case 5976ULL: goto x86_l_1758;
	case 5981ULL: goto x86_l_175d;
	case 5989ULL: goto x86_l_1765;
	case 5991ULL: goto x86_l_1767;
	case 5996ULL: goto x86_l_176c;
	case 6001ULL: goto x86_l_1771;
	case 6006ULL: goto x86_l_1776;
	case 6011ULL: goto x86_l_177b;
	case 6013ULL: goto x86_l_177d;
	case 6018ULL: goto x86_l_1782;
	case 6020ULL: goto x86_l_1784;
	case 6026ULL: goto x86_l_178a;
	case 6034ULL: goto x86_l_1792;
	case 6040ULL: goto x86_l_1798;
	case 6046ULL: goto x86_l_179e;
	case 6051ULL: goto x86_l_17a3;
	case 6059ULL: goto x86_l_17ab;
	case 6061ULL: goto x86_l_17ad;
	case 6066ULL: goto x86_l_17b2;
	case 6071ULL: goto x86_l_17b7;
	case 6076ULL: goto x86_l_17bc;
	case 6081ULL: goto x86_l_17c1;
	case 6083ULL: goto x86_l_17c3;
	case 6085ULL: goto x86_l_17c5;
	case 6091ULL: goto x86_l_17cb;
	case 6096ULL: goto x86_l_17d0;
	case 6104ULL: goto x86_l_17d8;
	case 6110ULL: goto x86_l_17de;
	case 6113ULL: goto x86_l_17e1;
	case 6119ULL: goto x86_l_17e7;
	case 6124ULL: goto x86_l_17ec;
	case 6132ULL: goto x86_l_17f4;
	case 6134ULL: goto x86_l_17f6;
	case 6139ULL: goto x86_l_17fb;
	case 6144ULL: goto x86_l_1800;
	case 6149ULL: goto x86_l_1805;
	case 6154ULL: goto x86_l_180a;
	case 6156ULL: goto x86_l_180c;
	case 6158ULL: goto x86_l_180e;
	case 6164ULL: goto x86_l_1814;
	case 6169ULL: goto x86_l_1819;
	case 6177ULL: goto x86_l_1821;
	case 6182ULL: goto x86_l_1826;
	case 6185ULL: goto x86_l_1829;
	case 6191ULL: goto x86_l_182f;
	case 6197ULL: goto x86_l_1835;
	case 6202ULL: goto x86_l_183a;
	case 6210ULL: goto x86_l_1842;
	case 6212ULL: goto x86_l_1844;
	case 6217ULL: goto x86_l_1849;
	case 6222ULL: goto x86_l_184e;
	case 6227ULL: goto x86_l_1853;
	case 6232ULL: goto x86_l_1858;
	case 6234ULL: goto x86_l_185a;
	case 6236ULL: goto x86_l_185c;
	case 6242ULL: goto x86_l_1862;
	case 6247ULL: goto x86_l_1867;
	case 6255ULL: goto x86_l_186f;
	case 6260ULL: goto x86_l_1874;
	case 6263ULL: goto x86_l_1877;
	case 6269ULL: goto x86_l_187d;
	case 6275ULL: goto x86_l_1883;
	case 6280ULL: goto x86_l_1888;
	case 6288ULL: goto x86_l_1890;
	case 6294ULL: goto x86_l_1896;
	case 6299ULL: goto x86_l_189b;
	case 6304ULL: goto x86_l_18a0;
	case 6309ULL: goto x86_l_18a5;
	case 6314ULL: goto x86_l_18aa;
	case 6316ULL: goto x86_l_18ac;
	case 6321ULL: goto x86_l_18b1;
	case 6323ULL: goto x86_l_18b3;
	case 6329ULL: goto x86_l_18b9;
	case 6334ULL: goto x86_l_18be;
	case 6339ULL: goto x86_l_18c3;
	case 6344ULL: goto x86_l_18c8;
	case 6349ULL: goto x86_l_18cd;
	case 6357ULL: goto x86_l_18d5;
	case 6360ULL: goto x86_l_18d8;
	case 6362ULL: goto x86_l_18da;
	case 6367ULL: goto x86_l_18df;
	case 6370ULL: goto x86_l_18e2;
	case 6372ULL: goto x86_l_18e4;
	case 6374ULL: goto x86_l_18e6;
	case 6379ULL: goto x86_l_18eb;
	case 6382ULL: goto x86_l_18ee;
	case 6384ULL: goto x86_l_18f0;
	case 6389ULL: goto x86_l_18f5;
	case 6392ULL: goto x86_l_18f8;
	case 6394ULL: goto x86_l_18fa;
	case 6396ULL: goto x86_l_18fc;
	case 6404ULL: goto x86_l_1904;
	case 6407ULL: goto x86_l_1907;
	case 6409ULL: goto x86_l_1909;
	case 6414ULL: goto x86_l_190e;
	case 6417ULL: goto x86_l_1911;
	case 6419ULL: goto x86_l_1913;
	case 6421ULL: goto x86_l_1915;
	case 6429ULL: goto x86_l_191d;
	case 6432ULL: goto x86_l_1920;
	case 6434ULL: goto x86_l_1922;
	case 6439ULL: goto x86_l_1927;
	case 6442ULL: goto x86_l_192a;
	case 6444ULL: goto x86_l_192c;
	case 6447ULL: goto x86_l_192f;
	case 6449ULL: goto x86_l_1931;
	case 6451ULL: goto x86_l_1933;
	case 6456ULL: goto x86_l_1938;
	case 6458ULL: goto x86_l_193a;
	case 6463ULL: goto x86_l_193f;
	case 6468ULL: goto x86_l_1944;
	case 6471ULL: goto x86_l_1947;
	case 6473ULL: goto x86_l_1949;
	case 6476ULL: goto x86_l_194c;
	case 6481ULL: goto x86_l_1951;
	case 6487ULL: goto x86_l_1957;
	case 6494ULL: goto x86_l_195e;
	case 6497ULL: goto x86_l_1961;
	case 6500ULL: goto x86_l_1964;
	case 6503ULL: goto x86_l_1967;
	case 6508ULL: goto x86_l_196c;
	case 6512ULL: goto x86_l_1970;
	case 6514ULL: goto x86_l_1972;
	case 6520ULL: goto x86_l_1978;
	case 6523ULL: goto x86_l_197b;
	case 6525ULL: goto x86_l_197d;
	case 6530ULL: goto x86_l_1982;
	case 6535ULL: goto x86_l_1987;
	case 6540ULL: goto x86_l_198c;
	case 6545ULL: goto x86_l_1991;
	case 6547ULL: goto x86_l_1993;
	case 6552ULL: goto x86_l_1998;
	case 6554ULL: goto x86_l_199a;
	case 6560ULL: goto x86_l_19a0;
	case 6565ULL: goto x86_l_19a5;
	case 6571ULL: goto x86_l_19ab;
	case 6574ULL: goto x86_l_19ae;
	case 6579ULL: goto x86_l_19b3;
	case 6584ULL: goto x86_l_19b8;
	case 6586ULL: goto x86_l_19ba;
	case 6591ULL: goto x86_l_19bf;
	case 6596ULL: goto x86_l_19c4;
	case 6601ULL: goto x86_l_19c9;
	case 6606ULL: goto x86_l_19ce;
	case 6608ULL: goto x86_l_19d0;
	case 6613ULL: goto x86_l_19d5;
	case 6615ULL: goto x86_l_19d7;
	case 6621ULL: goto x86_l_19dd;
	case 6629ULL: goto x86_l_19e5;
	case 6635ULL: goto x86_l_19eb;
	case 6641ULL: goto x86_l_19f1;
	case 6646ULL: goto x86_l_19f6;
	case 6654ULL: goto x86_l_19fe;
	case 6656ULL: goto x86_l_1a00;
	case 6661ULL: goto x86_l_1a05;
	case 6666ULL: goto x86_l_1a0a;
	case 6671ULL: goto x86_l_1a0f;
	case 6676ULL: goto x86_l_1a14;
	case 6678ULL: goto x86_l_1a16;
	case 6683ULL: goto x86_l_1a1b;
	case 6685ULL: goto x86_l_1a1d;
	case 6691ULL: goto x86_l_1a23;
	case 6699ULL: goto x86_l_1a2b;
	case 6705ULL: goto x86_l_1a31;
	case 6711ULL: goto x86_l_1a37;
	case 6716ULL: goto x86_l_1a3c;
	case 6724ULL: goto x86_l_1a44;
	case 6726ULL: goto x86_l_1a46;
	case 6731ULL: goto x86_l_1a4b;
	case 6736ULL: goto x86_l_1a50;
	case 6741ULL: goto x86_l_1a55;
	case 6746ULL: goto x86_l_1a5a;
	case 6748ULL: goto x86_l_1a5c;
	case 6753ULL: goto x86_l_1a61;
	case 6755ULL: goto x86_l_1a63;
	case 6761ULL: goto x86_l_1a69;
	case 6769ULL: goto x86_l_1a71;
	case 6775ULL: goto x86_l_1a77;
	case 6781ULL: goto x86_l_1a7d;
	case 6786ULL: goto x86_l_1a82;
	case 6794ULL: goto x86_l_1a8a;
	case 6796ULL: goto x86_l_1a8c;
	case 6801ULL: goto x86_l_1a91;
	case 6806ULL: goto x86_l_1a96;
	case 6811ULL: goto x86_l_1a9b;
	case 6816ULL: goto x86_l_1aa0;
	case 6818ULL: goto x86_l_1aa2;
	case 6823ULL: goto x86_l_1aa7;
	case 6825ULL: goto x86_l_1aa9;
	case 6831ULL: goto x86_l_1aaf;
	case 6839ULL: goto x86_l_1ab7;
	case 6845ULL: goto x86_l_1abd;
	case 6851ULL: goto x86_l_1ac3;
	case 6856ULL: goto x86_l_1ac8;
	case 6864ULL: goto x86_l_1ad0;
	case 6866ULL: goto x86_l_1ad2;
	case 6871ULL: goto x86_l_1ad7;
	case 6876ULL: goto x86_l_1adc;
	case 6881ULL: goto x86_l_1ae1;
	case 6886ULL: goto x86_l_1ae6;
	case 6888ULL: goto x86_l_1ae8;
	case 6893ULL: goto x86_l_1aed;
	case 6895ULL: goto x86_l_1aef;
	case 6901ULL: goto x86_l_1af5;
	case 6909ULL: goto x86_l_1afd;
	case 6915ULL: goto x86_l_1b03;
	case 6921ULL: goto x86_l_1b09;
	case 6926ULL: goto x86_l_1b0e;
	case 6934ULL: goto x86_l_1b16;
	case 6936ULL: goto x86_l_1b18;
	case 6941ULL: goto x86_l_1b1d;
	case 6946ULL: goto x86_l_1b22;
	case 6951ULL: goto x86_l_1b27;
	case 6956ULL: goto x86_l_1b2c;
	case 6958ULL: goto x86_l_1b2e;
	case 6960ULL: goto x86_l_1b30;
	case 6966ULL: goto x86_l_1b36;
	case 6971ULL: goto x86_l_1b3b;
	case 6979ULL: goto x86_l_1b43;
	case 6985ULL: goto x86_l_1b49;
	case 6991ULL: goto x86_l_1b4f;
	case 6996ULL: goto x86_l_1b54;
	case 7004ULL: goto x86_l_1b5c;
	case 7006ULL: goto x86_l_1b5e;
	case 7011ULL: goto x86_l_1b63;
	case 7016ULL: goto x86_l_1b68;
	case 7021ULL: goto x86_l_1b6d;
	case 7026ULL: goto x86_l_1b72;
	case 7028ULL: goto x86_l_1b74;
	case 7030ULL: goto x86_l_1b76;
	case 7036ULL: goto x86_l_1b7c;
	case 7041ULL: goto x86_l_1b81;
	case 7049ULL: goto x86_l_1b89;
	case 7055ULL: goto x86_l_1b8f;
	case 7061ULL: goto x86_l_1b95;
	case 7066ULL: goto x86_l_1b9a;
	case 7074ULL: goto x86_l_1ba2;
	case 7076ULL: goto x86_l_1ba4;
	case 7081ULL: goto x86_l_1ba9;
	case 7086ULL: goto x86_l_1bae;
	case 7091ULL: goto x86_l_1bb3;
	case 7096ULL: goto x86_l_1bb8;
	case 7098ULL: goto x86_l_1bba;
	case 7100ULL: goto x86_l_1bbc;
	case 7106ULL: goto x86_l_1bc2;
	case 7111ULL: goto x86_l_1bc7;
	case 7119ULL: goto x86_l_1bcf;
	case 7124ULL: goto x86_l_1bd4;
	case 7130ULL: goto x86_l_1bda;
	case 7136ULL: goto x86_l_1be0;
	case 7141ULL: goto x86_l_1be5;
	case 7149ULL: goto x86_l_1bed;
	case 7155ULL: goto x86_l_1bf3;
	case 7160ULL: goto x86_l_1bf8;
	case 7165ULL: goto x86_l_1bfd;
	case 7168ULL: goto x86_l_1c00;
	case 7170ULL: goto x86_l_1c02;
	case 7175ULL: goto x86_l_1c07;
	default: return 0xffffffffffffffffULL;
	}
x86_l_14ec:
	/* 0x14ec: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14f1:
	/* 0x14f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14f6:
	/* 0x14f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14f8:
	/* 0x14f8: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14fd:
	/* 0x14fd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14ff:
	/* 0x14ff: js     1f30 <generic_sleepable_preload+0x1f30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7984ULL;
	}
x86_l_1505:
	/* 0x1505: cmp    WORD PTR [rdi+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_150d:
	/* 0x150d: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_1513:
	/* 0x1513: mov    eax,DWORD PTR [rdi+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1519:
	/* 0x1519: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_151e:
	/* 0x151e: cmp    WORD PTR [rdi+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1526:
	/* 0x1526: je     1546 <generic_sleepable_preload+0x1546> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1546;
	}
x86_l_1528:
	/* 0x1528: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_152d:
	/* 0x152d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1532:
	/* 0x1532: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1537:
	/* 0x1537: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_153c:
	/* 0x153c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_153e:
	/* 0x153e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1540:
	/* 0x1540: js     5d86 <generic_sleepable_preload+0x5d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23942ULL;
	}
x86_l_1546:
	/* 0x1546: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_154b:
	/* 0x154b: cmp    WORD PTR [rdi+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1553:
	/* 0x1553: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_1559:
	/* 0x1559: mov    eax,DWORD PTR [rdi+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_155f:
	/* 0x155f: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1564:
	/* 0x1564: cmp    WORD PTR [rdi+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_156c:
	/* 0x156c: je     158c <generic_sleepable_preload+0x158c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_158c;
	}
x86_l_156e:
	/* 0x156e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1573:
	/* 0x1573: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1578:
	/* 0x1578: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_157d:
	/* 0x157d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1582:
	/* 0x1582: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1584:
	/* 0x1584: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1586:
	/* 0x1586: js     5f00 <generic_sleepable_preload+0x5f00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24320ULL;
	}
x86_l_158c:
	/* 0x158c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1591:
	/* 0x1591: cmp    WORD PTR [rdi+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1599:
	/* 0x1599: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_159f:
	/* 0x159f: mov    eax,DWORD PTR [rdi+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_15a5:
	/* 0x15a5: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_15aa:
	/* 0x15aa: cmp    WORD PTR [rdi+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_15b2:
	/* 0x15b2: je     15d2 <generic_sleepable_preload+0x15d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15d2;
	}
x86_l_15b4:
	/* 0x15b4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_15b9:
	/* 0x15b9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15be:
	/* 0x15be: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15c3:
	/* 0x15c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15c8:
	/* 0x15c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ca:
	/* 0x15ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15cc:
	/* 0x15cc: js     600c <generic_sleepable_preload+0x600c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24588ULL;
	}
x86_l_15d2:
	/* 0x15d2: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15d7:
	/* 0x15d7: cmp    WORD PTR [rdi+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_15df:
	/* 0x15df: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15e4:
	/* 0x15e4: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_15ea:
	/* 0x15ea: mov    eax,DWORD PTR [rdi+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_15f0:
	/* 0x15f0: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_15f5:
	/* 0x15f5: cmp    WORD PTR [rdi+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_15fd:
	/* 0x15fd: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_1603:
	/* 0x1603: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1608:
	/* 0x1608: jmp    189b <generic_sleepable_preload+0x189b> */
	goto x86_l_189b;
x86_l_160d:
	/* 0x160d: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1610:
	/* 0x1610: je     1635 <generic_sleepable_preload+0x1635> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1635;
	}
x86_l_1612:
	/* 0x1612: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1617:
	/* 0x1617: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_161c:
	/* 0x161c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1621:
	/* 0x1621: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1626:
	/* 0x1626: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1628:
	/* 0x1628: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_162d:
	/* 0x162d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_162f:
	/* 0x162f: js     18c3 <generic_sleepable_preload+0x18c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_18c3;
	}
x86_l_1635:
	/* 0x1635: cmp    WORD PTR [rdi+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_163a:
	/* 0x163a: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_1640:
	/* 0x1640: mov    eax,DWORD PTR [rdi+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1643:
	/* 0x1643: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1648:
	/* 0x1648: cmp    WORD PTR [rdi+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_164d:
	/* 0x164d: je     1672 <generic_sleepable_preload+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1672;
	}
x86_l_164f:
	/* 0x164f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1654:
	/* 0x1654: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1659:
	/* 0x1659: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_165e:
	/* 0x165e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1663:
	/* 0x1663: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1665:
	/* 0x1665: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_166a:
	/* 0x166a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_166c:
	/* 0x166c: js     1ebd <generic_sleepable_preload+0x1ebd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7869ULL;
	}
x86_l_1672:
	/* 0x1672: cmp    WORD PTR [rdi+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_167a:
	/* 0x167a: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_1680:
	/* 0x1680: mov    eax,DWORD PTR [rdi+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1686:
	/* 0x1686: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_168b:
	/* 0x168b: cmp    WORD PTR [rdi+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1693:
	/* 0x1693: je     16b8 <generic_sleepable_preload+0x16b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16b8;
	}
x86_l_1695:
	/* 0x1695: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_169a:
	/* 0x169a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_169f:
	/* 0x169f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16a4:
	/* 0x16a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16a9:
	/* 0x16a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ab:
	/* 0x16ab: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16b0:
	/* 0x16b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16b2:
	/* 0x16b2: js     1efd <generic_sleepable_preload+0x1efd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7933ULL;
	}
x86_l_16b8:
	/* 0x16b8: cmp    WORD PTR [rdi+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_16c0:
	/* 0x16c0: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_16c6:
	/* 0x16c6: mov    eax,DWORD PTR [rdi+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_16cc:
	/* 0x16cc: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_16d1:
	/* 0x16d1: cmp    WORD PTR [rdi+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_16d9:
	/* 0x16d9: je     16fe <generic_sleepable_preload+0x16fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16fe;
	}
x86_l_16db:
	/* 0x16db: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_16e0:
	/* 0x16e0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16e5:
	/* 0x16e5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16ea:
	/* 0x16ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16ef:
	/* 0x16ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16f1:
	/* 0x16f1: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16f6:
	/* 0x16f6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16f8:
	/* 0x16f8: js     1f0e <generic_sleepable_preload+0x1f0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7950ULL;
	}
x86_l_16fe:
	/* 0x16fe: cmp    WORD PTR [rdi+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1706:
	/* 0x1706: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_170c:
	/* 0x170c: mov    eax,DWORD PTR [rdi+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1712:
	/* 0x1712: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1717:
	/* 0x1717: cmp    WORD PTR [rdi+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_171f:
	/* 0x171f: je     1744 <generic_sleepable_preload+0x1744> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1744;
	}
x86_l_1721:
	/* 0x1721: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1726:
	/* 0x1726: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_172b:
	/* 0x172b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1730:
	/* 0x1730: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1735:
	/* 0x1735: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1737:
	/* 0x1737: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_173c:
	/* 0x173c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_173e:
	/* 0x173e: js     1f1f <generic_sleepable_preload+0x1f1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7967ULL;
	}
x86_l_1744:
	/* 0x1744: cmp    WORD PTR [rdi+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_174c:
	/* 0x174c: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_1752:
	/* 0x1752: mov    eax,DWORD PTR [rdi+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1758:
	/* 0x1758: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_175d:
	/* 0x175d: cmp    WORD PTR [rdi+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1765:
	/* 0x1765: je     178a <generic_sleepable_preload+0x178a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_178a;
	}
x86_l_1767:
	/* 0x1767: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_176c:
	/* 0x176c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1771:
	/* 0x1771: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1776:
	/* 0x1776: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_177b:
	/* 0x177b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_177d:
	/* 0x177d: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1782:
	/* 0x1782: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1784:
	/* 0x1784: js     1f30 <generic_sleepable_preload+0x1f30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7984ULL;
	}
x86_l_178a:
	/* 0x178a: cmp    WORD PTR [rdi+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1792:
	/* 0x1792: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_1798:
	/* 0x1798: mov    eax,DWORD PTR [rdi+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_179e:
	/* 0x179e: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_17a3:
	/* 0x17a3: cmp    WORD PTR [rdi+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_17ab:
	/* 0x17ab: je     17cb <generic_sleepable_preload+0x17cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17cb;
	}
x86_l_17ad:
	/* 0x17ad: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_17b2:
	/* 0x17b2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17b7:
	/* 0x17b7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17bc:
	/* 0x17bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17c1:
	/* 0x17c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c3:
	/* 0x17c3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17c5:
	/* 0x17c5: js     5d86 <generic_sleepable_preload+0x5d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23942ULL;
	}
x86_l_17cb:
	/* 0x17cb: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17d0:
	/* 0x17d0: cmp    WORD PTR [rdi+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_17d8:
	/* 0x17d8: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_17de:
	/* 0x17de: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_17e1:
	/* 0x17e1: mov    eax,DWORD PTR [rdi+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_17e7:
	/* 0x17e7: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_17ec:
	/* 0x17ec: cmp    WORD PTR [rdi+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_17f4:
	/* 0x17f4: je     1814 <generic_sleepable_preload+0x1814> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1814;
	}
x86_l_17f6:
	/* 0x17f6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_17fb:
	/* 0x17fb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1800:
	/* 0x1800: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1805:
	/* 0x1805: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_180a:
	/* 0x180a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_180c:
	/* 0x180c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_180e:
	/* 0x180e: js     5fa4 <generic_sleepable_preload+0x5fa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24484ULL;
	}
x86_l_1814:
	/* 0x1814: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1819:
	/* 0x1819: cmp    WORD PTR [rdi+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1821:
	/* 0x1821: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1826:
	/* 0x1826: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_1829:
	/* 0x1829: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_182f:
	/* 0x182f: mov    eax,DWORD PTR [rdi+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1835:
	/* 0x1835: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_183a:
	/* 0x183a: cmp    WORD PTR [rdi+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1842:
	/* 0x1842: je     1862 <generic_sleepable_preload+0x1862> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1862;
	}
x86_l_1844:
	/* 0x1844: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1849:
	/* 0x1849: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_184e:
	/* 0x184e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1853:
	/* 0x1853: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1858:
	/* 0x1858: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_185a:
	/* 0x185a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_185c:
	/* 0x185c: js     6076 <generic_sleepable_preload+0x6076> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24694ULL;
	}
x86_l_1862:
	/* 0x1862: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1867:
	/* 0x1867: cmp    WORD PTR [rdi+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_186f:
	/* 0x186f: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1874:
	/* 0x1874: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_1877:
	/* 0x1877: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_187d:
	/* 0x187d: mov    eax,DWORD PTR [rdi+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1883:
	/* 0x1883: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1888:
	/* 0x1888: cmp    WORD PTR [rdi+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1890:
	/* 0x1890: je     1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7992ULL;
	}
x86_l_1896:
	/* 0x1896: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_189b:
	/* 0x189b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18a0:
	/* 0x18a0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18a5:
	/* 0x18a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18aa:
	/* 0x18aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ac:
	/* 0x18ac: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18b1:
	/* 0x18b1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18b3:
	/* 0x18b3: jns    1f38 <generic_sleepable_preload+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 7992ULL;
	}
x86_l_18b9:
	/* 0x18b9: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_18be:
	/* 0x18be: jmp    1f35 <generic_sleepable_preload+0x1f35> */
	return 7989ULL;
x86_l_18c3:
	/* 0x18c3: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_18c8:
	/* 0x18c8: jmp    1f35 <generic_sleepable_preload+0x1f35> */
	return 7989ULL;
x86_l_18cd:
	/* 0x18cd: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_18d5:
	/* 0x18d5: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_18d8:
	/* 0x18d8: je     192c <generic_sleepable_preload+0x192c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_192c;
	}
x86_l_18da:
	/* 0x18da: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_18df:
	/* 0x18df: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_18e2:
	/* 0x18e2: je     192c <generic_sleepable_preload+0x192c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_192c;
	}
x86_l_18e4:
	/* 0x18e4: jmp    193f <generic_sleepable_preload+0x193f> */
	goto x86_l_193f;
x86_l_18e6:
	/* 0x18e6: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_18eb:
	/* 0x18eb: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_18ee:
	/* 0x18ee: je     192c <generic_sleepable_preload+0x192c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_192c;
	}
x86_l_18f0:
	/* 0x18f0: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18f5:
	/* 0x18f5: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_18f8:
	/* 0x18f8: je     192c <generic_sleepable_preload+0x192c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_192c;
	}
x86_l_18fa:
	/* 0x18fa: jmp    193f <generic_sleepable_preload+0x193f> */
	goto x86_l_193f;
x86_l_18fc:
	/* 0x18fc: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1904:
	/* 0x1904: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1907:
	/* 0x1907: je     192c <generic_sleepable_preload+0x192c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_192c;
	}
x86_l_1909:
	/* 0x1909: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_190e:
	/* 0x190e: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1911:
	/* 0x1911: je     192c <generic_sleepable_preload+0x192c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_192c;
	}
x86_l_1913:
	/* 0x1913: jmp    193f <generic_sleepable_preload+0x193f> */
	goto x86_l_193f;
x86_l_1915:
	/* 0x1915: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_191d:
	/* 0x191d: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_1920:
	/* 0x1920: je     192c <generic_sleepable_preload+0x192c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_192c;
	}
x86_l_1922:
	/* 0x1922: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1927:
	/* 0x1927: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_192a:
	/* 0x192a: jne    193f <generic_sleepable_preload+0x193f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_193f;
	}
x86_l_192c:
	/* 0x192c: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_192f:
	/* 0x192f: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_1931:
	/* 0x1931: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1933:
	/* 0x1933: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_1938:
	/* 0x1938: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_193a:
	/* 0x193a: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_193f:
	/* 0x193f: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1944:
	/* 0x1944: mov    ebx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1947:
	/* 0x1947: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1949:
	/* 0x1949: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_194c:
	/* 0x194c: cmp    WORD PTR [rdi+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_1951:
	/* 0x1951: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8127ULL;
	}
x86_l_1957:
	/* 0x1957: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_195e:
	/* 0x195e: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1961:
	/* 0x1961: mov    edx,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1964:
	/* 0x1964: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1967:
	/* 0x1967: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_196c:
	/* 0x196c: movzx  eax,WORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_1970:
	/* 0x1970: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_1972:
	/* 0x1972: je     1bfd <generic_sleepable_preload+0x1bfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bfd;
	}
x86_l_1978:
	/* 0x1978: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_197b:
	/* 0x197b: je     19a0 <generic_sleepable_preload+0x19a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19a0;
	}
x86_l_197d:
	/* 0x197d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1982:
	/* 0x1982: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1987:
	/* 0x1987: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_198c:
	/* 0x198c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1991:
	/* 0x1991: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1993:
	/* 0x1993: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1998:
	/* 0x1998: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_199a:
	/* 0x199a: js     1eb3 <generic_sleepable_preload+0x1eb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7859ULL;
	}
x86_l_19a0:
	/* 0x19a0: cmp    WORD PTR [rdi+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_19a5:
	/* 0x19a5: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8127ULL;
	}
x86_l_19ab:
	/* 0x19ab: mov    eax,DWORD PTR [rdi+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_19ae:
	/* 0x19ae: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_19b3:
	/* 0x19b3: cmp    WORD PTR [rdi+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_19b8:
	/* 0x19b8: je     19dd <generic_sleepable_preload+0x19dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19dd;
	}
x86_l_19ba:
	/* 0x19ba: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_19bf:
	/* 0x19bf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19c4:
	/* 0x19c4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19c9:
	/* 0x19c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19ce:
	/* 0x19ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d0:
	/* 0x19d0: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19d5:
	/* 0x19d5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19d7:
	/* 0x19d7: js     1ec4 <generic_sleepable_preload+0x1ec4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7876ULL;
	}
x86_l_19dd:
	/* 0x19dd: cmp    WORD PTR [rdi+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_19e5:
	/* 0x19e5: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8127ULL;
	}
x86_l_19eb:
	/* 0x19eb: mov    eax,DWORD PTR [rdi+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_19f1:
	/* 0x19f1: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_19f6:
	/* 0x19f6: cmp    WORD PTR [rdi+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_19fe:
	/* 0x19fe: je     1a23 <generic_sleepable_preload+0x1a23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a23;
	}
x86_l_1a00:
	/* 0x1a00: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a05:
	/* 0x1a05: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a0a:
	/* 0x1a0a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a0f:
	/* 0x1a0f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a14:
	/* 0x1a14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a16:
	/* 0x1a16: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a1b:
	/* 0x1a1b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a1d:
	/* 0x1a1d: js     1f04 <generic_sleepable_preload+0x1f04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7940ULL;
	}
x86_l_1a23:
	/* 0x1a23: cmp    WORD PTR [rdi+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1a2b:
	/* 0x1a2b: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8127ULL;
	}
x86_l_1a31:
	/* 0x1a31: mov    eax,DWORD PTR [rdi+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1a37:
	/* 0x1a37: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1a3c:
	/* 0x1a3c: cmp    WORD PTR [rdi+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1a44:
	/* 0x1a44: je     1a69 <generic_sleepable_preload+0x1a69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a69;
	}
x86_l_1a46:
	/* 0x1a46: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a4b:
	/* 0x1a4b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a50:
	/* 0x1a50: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a55:
	/* 0x1a55: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a5a:
	/* 0x1a5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a5c:
	/* 0x1a5c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a61:
	/* 0x1a61: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a63:
	/* 0x1a63: js     1f15 <generic_sleepable_preload+0x1f15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7957ULL;
	}
x86_l_1a69:
	/* 0x1a69: cmp    WORD PTR [rdi+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1a71:
	/* 0x1a71: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8127ULL;
	}
x86_l_1a77:
	/* 0x1a77: mov    eax,DWORD PTR [rdi+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1a7d:
	/* 0x1a7d: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1a82:
	/* 0x1a82: cmp    WORD PTR [rdi+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1a8a:
	/* 0x1a8a: je     1aaf <generic_sleepable_preload+0x1aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1aaf;
	}
x86_l_1a8c:
	/* 0x1a8c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a91:
	/* 0x1a91: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a96:
	/* 0x1a96: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a9b:
	/* 0x1a9b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aa0:
	/* 0x1aa0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa2:
	/* 0x1aa2: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1aa7:
	/* 0x1aa7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1aa9:
	/* 0x1aa9: js     1f26 <generic_sleepable_preload+0x1f26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7974ULL;
	}
x86_l_1aaf:
	/* 0x1aaf: cmp    WORD PTR [rdi+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1ab7:
	/* 0x1ab7: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8127ULL;
	}
x86_l_1abd:
	/* 0x1abd: mov    eax,DWORD PTR [rdi+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1ac3:
	/* 0x1ac3: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ac8:
	/* 0x1ac8: cmp    WORD PTR [rdi+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1ad0:
	/* 0x1ad0: je     1af5 <generic_sleepable_preload+0x1af5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1af5;
	}
x86_l_1ad2:
	/* 0x1ad2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1ad7:
	/* 0x1ad7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1adc:
	/* 0x1adc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ae1:
	/* 0x1ae1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ae6:
	/* 0x1ae6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae8:
	/* 0x1ae8: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1aed:
	/* 0x1aed: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1aef:
	/* 0x1aef: js     1fb7 <generic_sleepable_preload+0x1fb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8119ULL;
	}
x86_l_1af5:
	/* 0x1af5: cmp    WORD PTR [rdi+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1afd:
	/* 0x1afd: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8127ULL;
	}
x86_l_1b03:
	/* 0x1b03: mov    eax,DWORD PTR [rdi+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1b09:
	/* 0x1b09: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b0e:
	/* 0x1b0e: cmp    WORD PTR [rdi+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1b16:
	/* 0x1b16: je     1b36 <generic_sleepable_preload+0x1b36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b36;
	}
x86_l_1b18:
	/* 0x1b18: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b1d:
	/* 0x1b1d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b22:
	/* 0x1b22: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b27:
	/* 0x1b27: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b2c:
	/* 0x1b2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b2e:
	/* 0x1b2e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b30:
	/* 0x1b30: js     5d98 <generic_sleepable_preload+0x5d98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23960ULL;
	}
x86_l_1b36:
	/* 0x1b36: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b3b:
	/* 0x1b3b: cmp    WORD PTR [rdi+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1b43:
	/* 0x1b43: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8127ULL;
	}
x86_l_1b49:
	/* 0x1b49: mov    eax,DWORD PTR [rdi+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1b4f:
	/* 0x1b4f: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b54:
	/* 0x1b54: cmp    WORD PTR [rdi+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1b5c:
	/* 0x1b5c: je     1b7c <generic_sleepable_preload+0x1b7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b7c;
	}
x86_l_1b5e:
	/* 0x1b5e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b63:
	/* 0x1b63: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b68:
	/* 0x1b68: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b6d:
	/* 0x1b6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b72:
	/* 0x1b72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b74:
	/* 0x1b74: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b76:
	/* 0x1b76: js     5f12 <generic_sleepable_preload+0x5f12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24338ULL;
	}
x86_l_1b7c:
	/* 0x1b7c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b81:
	/* 0x1b81: cmp    WORD PTR [rdi+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1b89:
	/* 0x1b89: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8127ULL;
	}
x86_l_1b8f:
	/* 0x1b8f: mov    eax,DWORD PTR [rdi+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1b95:
	/* 0x1b95: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b9a:
	/* 0x1b9a: cmp    WORD PTR [rdi+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1ba2:
	/* 0x1ba2: je     1bc2 <generic_sleepable_preload+0x1bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bc2;
	}
x86_l_1ba4:
	/* 0x1ba4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1ba9:
	/* 0x1ba9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bae:
	/* 0x1bae: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bb3:
	/* 0x1bb3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bb8:
	/* 0x1bb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bba:
	/* 0x1bba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bbc:
	/* 0x1bbc: js     6023 <generic_sleepable_preload+0x6023> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24611ULL;
	}
x86_l_1bc2:
	/* 0x1bc2: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bc7:
	/* 0x1bc7: cmp    WORD PTR [rdi+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1bcf:
	/* 0x1bcf: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bd4:
	/* 0x1bd4: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8127ULL;
	}
x86_l_1bda:
	/* 0x1bda: mov    eax,DWORD PTR [rdi+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1be0:
	/* 0x1be0: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1be5:
	/* 0x1be5: cmp    WORD PTR [rdi+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1bed:
	/* 0x1bed: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8127ULL;
	}
x86_l_1bf3:
	/* 0x1bf3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1bf8:
	/* 0x1bf8: jmp    1e8b <generic_sleepable_preload+0x1e8b> */
	return 7819ULL;
x86_l_1bfd:
	/* 0x1bfd: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1c00:
	/* 0x1c00: je     1c25 <generic_sleepable_preload+0x1c25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7205ULL;
	}
x86_l_1c02:
	/* 0x1c02: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c07:
	/* 0x1c07: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 7180ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7180ULL: goto x86_l_1c0c;
	case 7185ULL: goto x86_l_1c11;
	case 7190ULL: goto x86_l_1c16;
	case 7192ULL: goto x86_l_1c18;
	case 7197ULL: goto x86_l_1c1d;
	case 7199ULL: goto x86_l_1c1f;
	case 7205ULL: goto x86_l_1c25;
	case 7210ULL: goto x86_l_1c2a;
	case 7216ULL: goto x86_l_1c30;
	case 7219ULL: goto x86_l_1c33;
	case 7224ULL: goto x86_l_1c38;
	case 7229ULL: goto x86_l_1c3d;
	case 7231ULL: goto x86_l_1c3f;
	case 7236ULL: goto x86_l_1c44;
	case 7241ULL: goto x86_l_1c49;
	case 7246ULL: goto x86_l_1c4e;
	case 7251ULL: goto x86_l_1c53;
	case 7253ULL: goto x86_l_1c55;
	case 7258ULL: goto x86_l_1c5a;
	case 7260ULL: goto x86_l_1c5c;
	case 7266ULL: goto x86_l_1c62;
	case 7274ULL: goto x86_l_1c6a;
	case 7280ULL: goto x86_l_1c70;
	case 7286ULL: goto x86_l_1c76;
	case 7291ULL: goto x86_l_1c7b;
	case 7299ULL: goto x86_l_1c83;
	case 7301ULL: goto x86_l_1c85;
	case 7306ULL: goto x86_l_1c8a;
	case 7311ULL: goto x86_l_1c8f;
	case 7316ULL: goto x86_l_1c94;
	case 7321ULL: goto x86_l_1c99;
	case 7323ULL: goto x86_l_1c9b;
	case 7328ULL: goto x86_l_1ca0;
	case 7330ULL: goto x86_l_1ca2;
	case 7336ULL: goto x86_l_1ca8;
	case 7344ULL: goto x86_l_1cb0;
	case 7350ULL: goto x86_l_1cb6;
	case 7356ULL: goto x86_l_1cbc;
	case 7361ULL: goto x86_l_1cc1;
	case 7369ULL: goto x86_l_1cc9;
	case 7371ULL: goto x86_l_1ccb;
	case 7376ULL: goto x86_l_1cd0;
	case 7381ULL: goto x86_l_1cd5;
	case 7386ULL: goto x86_l_1cda;
	case 7391ULL: goto x86_l_1cdf;
	case 7393ULL: goto x86_l_1ce1;
	case 7398ULL: goto x86_l_1ce6;
	case 7400ULL: goto x86_l_1ce8;
	case 7406ULL: goto x86_l_1cee;
	case 7414ULL: goto x86_l_1cf6;
	case 7420ULL: goto x86_l_1cfc;
	case 7426ULL: goto x86_l_1d02;
	case 7431ULL: goto x86_l_1d07;
	case 7439ULL: goto x86_l_1d0f;
	case 7441ULL: goto x86_l_1d11;
	case 7446ULL: goto x86_l_1d16;
	case 7451ULL: goto x86_l_1d1b;
	case 7456ULL: goto x86_l_1d20;
	case 7461ULL: goto x86_l_1d25;
	case 7463ULL: goto x86_l_1d27;
	case 7468ULL: goto x86_l_1d2c;
	case 7470ULL: goto x86_l_1d2e;
	case 7476ULL: goto x86_l_1d34;
	case 7484ULL: goto x86_l_1d3c;
	case 7490ULL: goto x86_l_1d42;
	case 7496ULL: goto x86_l_1d48;
	case 7501ULL: goto x86_l_1d4d;
	case 7509ULL: goto x86_l_1d55;
	case 7511ULL: goto x86_l_1d57;
	case 7516ULL: goto x86_l_1d5c;
	case 7521ULL: goto x86_l_1d61;
	case 7526ULL: goto x86_l_1d66;
	case 7531ULL: goto x86_l_1d6b;
	case 7533ULL: goto x86_l_1d6d;
	case 7538ULL: goto x86_l_1d72;
	case 7540ULL: goto x86_l_1d74;
	case 7546ULL: goto x86_l_1d7a;
	case 7554ULL: goto x86_l_1d82;
	case 7560ULL: goto x86_l_1d88;
	case 7566ULL: goto x86_l_1d8e;
	case 7571ULL: goto x86_l_1d93;
	case 7579ULL: goto x86_l_1d9b;
	case 7581ULL: goto x86_l_1d9d;
	case 7586ULL: goto x86_l_1da2;
	case 7591ULL: goto x86_l_1da7;
	case 7596ULL: goto x86_l_1dac;
	case 7601ULL: goto x86_l_1db1;
	case 7603ULL: goto x86_l_1db3;
	case 7605ULL: goto x86_l_1db5;
	case 7611ULL: goto x86_l_1dbb;
	case 7616ULL: goto x86_l_1dc0;
	case 7624ULL: goto x86_l_1dc8;
	case 7630ULL: goto x86_l_1dce;
	case 7633ULL: goto x86_l_1dd1;
	case 7639ULL: goto x86_l_1dd7;
	case 7644ULL: goto x86_l_1ddc;
	case 7652ULL: goto x86_l_1de4;
	case 7654ULL: goto x86_l_1de6;
	case 7659ULL: goto x86_l_1deb;
	case 7664ULL: goto x86_l_1df0;
	case 7669ULL: goto x86_l_1df5;
	case 7674ULL: goto x86_l_1dfa;
	case 7676ULL: goto x86_l_1dfc;
	case 7678ULL: goto x86_l_1dfe;
	case 7684ULL: goto x86_l_1e04;
	case 7689ULL: goto x86_l_1e09;
	case 7697ULL: goto x86_l_1e11;
	case 7702ULL: goto x86_l_1e16;
	case 7705ULL: goto x86_l_1e19;
	case 7711ULL: goto x86_l_1e1f;
	case 7717ULL: goto x86_l_1e25;
	case 7722ULL: goto x86_l_1e2a;
	case 7730ULL: goto x86_l_1e32;
	case 7732ULL: goto x86_l_1e34;
	case 7737ULL: goto x86_l_1e39;
	case 7742ULL: goto x86_l_1e3e;
	case 7747ULL: goto x86_l_1e43;
	case 7752ULL: goto x86_l_1e48;
	case 7754ULL: goto x86_l_1e4a;
	case 7756ULL: goto x86_l_1e4c;
	case 7762ULL: goto x86_l_1e52;
	case 7767ULL: goto x86_l_1e57;
	case 7775ULL: goto x86_l_1e5f;
	case 7780ULL: goto x86_l_1e64;
	case 7783ULL: goto x86_l_1e67;
	case 7789ULL: goto x86_l_1e6d;
	case 7795ULL: goto x86_l_1e73;
	case 7800ULL: goto x86_l_1e78;
	case 7808ULL: goto x86_l_1e80;
	case 7814ULL: goto x86_l_1e86;
	case 7819ULL: goto x86_l_1e8b;
	case 7824ULL: goto x86_l_1e90;
	case 7829ULL: goto x86_l_1e95;
	case 7834ULL: goto x86_l_1e9a;
	case 7836ULL: goto x86_l_1e9c;
	case 7841ULL: goto x86_l_1ea1;
	case 7843ULL: goto x86_l_1ea3;
	case 7849ULL: goto x86_l_1ea9;
	case 7854ULL: goto x86_l_1eae;
	case 7859ULL: goto x86_l_1eb3;
	case 7864ULL: goto x86_l_1eb8;
	case 7869ULL: goto x86_l_1ebd;
	case 7874ULL: goto x86_l_1ec2;
	case 7876ULL: goto x86_l_1ec4;
	case 7881ULL: goto x86_l_1ec9;
	case 7886ULL: goto x86_l_1ece;
	case 7891ULL: goto x86_l_1ed3;
	case 7896ULL: goto x86_l_1ed8;
	case 7903ULL: goto x86_l_1edf;
	case 7908ULL: goto x86_l_1ee4;
	case 7913ULL: goto x86_l_1ee9;
	case 7915ULL: goto x86_l_1eeb;
	case 7917ULL: goto x86_l_1eed;
	case 7920ULL: goto x86_l_1ef0;
	case 7926ULL: goto x86_l_1ef6;
	case 7928ULL: goto x86_l_1ef8;
	case 7933ULL: goto x86_l_1efd;
	case 7938ULL: goto x86_l_1f02;
	case 7940ULL: goto x86_l_1f04;
	case 7945ULL: goto x86_l_1f09;
	case 7950ULL: goto x86_l_1f0e;
	case 7955ULL: goto x86_l_1f13;
	case 7957ULL: goto x86_l_1f15;
	case 7962ULL: goto x86_l_1f1a;
	case 7967ULL: goto x86_l_1f1f;
	case 7972ULL: goto x86_l_1f24;
	case 7974ULL: goto x86_l_1f26;
	case 7979ULL: goto x86_l_1f2b;
	case 7984ULL: goto x86_l_1f30;
	case 7989ULL: goto x86_l_1f35;
	case 7992ULL: goto x86_l_1f38;
	case 7995ULL: goto x86_l_1f3b;
	case 8000ULL: goto x86_l_1f40;
	case 8005ULL: goto x86_l_1f45;
	case 8010ULL: goto x86_l_1f4a;
	case 8013ULL: goto x86_l_1f4d;
	case 8015ULL: goto x86_l_1f4f;
	case 8018ULL: goto x86_l_1f52;
	case 8024ULL: goto x86_l_1f58;
	case 8029ULL: goto x86_l_1f5d;
	case 8034ULL: goto x86_l_1f62;
	case 8036ULL: goto x86_l_1f64;
	case 8041ULL: goto x86_l_1f69;
	case 8049ULL: goto x86_l_1f71;
	case 8054ULL: goto x86_l_1f76;
	case 8061ULL: goto x86_l_1f7d;
	case 8066ULL: goto x86_l_1f82;
	case 8068ULL: goto x86_l_1f84;
	case 8071ULL: goto x86_l_1f87;
	case 8077ULL: goto x86_l_1f8d;
	case 8083ULL: goto x86_l_1f93;
	case 8086ULL: goto x86_l_1f96;
	case 8093ULL: goto x86_l_1f9d;
	case 8098ULL: goto x86_l_1fa2;
	case 8101ULL: goto x86_l_1fa5;
	case 8104ULL: goto x86_l_1fa8;
	case 8107ULL: goto x86_l_1fab;
	case 8109ULL: goto x86_l_1fad;
	case 8112ULL: goto x86_l_1fb0;
	case 8117ULL: goto x86_l_1fb5;
	case 8119ULL: goto x86_l_1fb7;
	case 8124ULL: goto x86_l_1fbc;
	case 8127ULL: goto x86_l_1fbf;
	case 8130ULL: goto x86_l_1fc2;
	case 8136ULL: goto x86_l_1fc8;
	case 8141ULL: goto x86_l_1fcd;
	case 8146ULL: goto x86_l_1fd2;
	case 8148ULL: goto x86_l_1fd4;
	case 8153ULL: goto x86_l_1fd9;
	case 8161ULL: goto x86_l_1fe1;
	case 8166ULL: goto x86_l_1fe6;
	case 8173ULL: goto x86_l_1fed;
	case 8178ULL: goto x86_l_1ff2;
	case 8180ULL: goto x86_l_1ff4;
	case 8183ULL: goto x86_l_1ff7;
	case 8185ULL: goto x86_l_1ff9;
	case 8191ULL: goto x86_l_1fff;
	case 8194ULL: goto x86_l_2002;
	case 8201ULL: goto x86_l_2009;
	case 8206ULL: goto x86_l_200e;
	case 8209ULL: goto x86_l_2011;
	case 8212ULL: goto x86_l_2014;
	case 8215ULL: goto x86_l_2017;
	case 8217ULL: goto x86_l_2019;
	case 8220ULL: goto x86_l_201c;
	case 8225ULL: goto x86_l_2021;
	case 8228ULL: goto x86_l_2024;
	case 8231ULL: goto x86_l_2027;
	case 8236ULL: goto x86_l_202c;
	case 8239ULL: goto x86_l_202f;
	case 8241ULL: goto x86_l_2031;
	case 8244ULL: goto x86_l_2034;
	case 8246ULL: goto x86_l_2036;
	case 8249ULL: goto x86_l_2039;
	case 8251ULL: goto x86_l_203b;
	case 8254ULL: goto x86_l_203e;
	case 8258ULL: goto x86_l_2042;
	case 8263ULL: goto x86_l_2047;
	case 8266ULL: goto x86_l_204a;
	case 8268ULL: goto x86_l_204c;
	case 8271ULL: goto x86_l_204f;
	case 8276ULL: goto x86_l_2054;
	case 8278ULL: goto x86_l_2056;
	case 8281ULL: goto x86_l_2059;
	case 8283ULL: goto x86_l_205b;
	case 8285ULL: goto x86_l_205d;
	case 8290ULL: goto x86_l_2062;
	case 8292ULL: goto x86_l_2064;
	case 8297ULL: goto x86_l_2069;
	case 8300ULL: goto x86_l_206c;
	case 8305ULL: goto x86_l_2071;
	case 8311ULL: goto x86_l_2077;
	case 8313ULL: goto x86_l_2079;
	case 8315ULL: goto x86_l_207b;
	case 8322ULL: goto x86_l_2082;
	case 8324ULL: goto x86_l_2084;
	case 8327ULL: goto x86_l_2087;
	case 8333ULL: goto x86_l_208d;
	case 8336ULL: goto x86_l_2090;
	case 8342ULL: goto x86_l_2096;
	case 8345ULL: goto x86_l_2099;
	case 8351ULL: goto x86_l_209f;
	case 8357ULL: goto x86_l_20a5;
	case 8363ULL: goto x86_l_20ab;
	case 8366ULL: goto x86_l_20ae;
	case 8371ULL: goto x86_l_20b3;
	case 8376ULL: goto x86_l_20b8;
	case 8381ULL: goto x86_l_20bd;
	case 8383ULL: goto x86_l_20bf;
	case 8388ULL: goto x86_l_20c4;
	case 8390ULL: goto x86_l_20c6;
	case 8396ULL: goto x86_l_20cc;
	case 8398ULL: goto x86_l_20ce;
	case 8403ULL: goto x86_l_20d3;
	case 8410ULL: goto x86_l_20da;
	case 8417ULL: goto x86_l_20e1;
	case 8423ULL: goto x86_l_20e7;
	case 8425ULL: goto x86_l_20e9;
	case 8428ULL: goto x86_l_20ec;
	case 8434ULL: goto x86_l_20f2;
	case 8437ULL: goto x86_l_20f5;
	case 8443ULL: goto x86_l_20fb;
	case 8446ULL: goto x86_l_20fe;
	case 8452ULL: goto x86_l_2104;
	case 8460ULL: goto x86_l_210c;
	case 8463ULL: goto x86_l_210f;
	case 8469ULL: goto x86_l_2115;
	case 8474ULL: goto x86_l_211a;
	case 8477ULL: goto x86_l_211d;
	case 8483ULL: goto x86_l_2123;
	case 8488ULL: goto x86_l_2128;
	case 8491ULL: goto x86_l_212b;
	case 8497ULL: goto x86_l_2131;
	case 8502ULL: goto x86_l_2136;
	case 8505ULL: goto x86_l_2139;
	case 8511ULL: goto x86_l_213f;
	case 8514ULL: goto x86_l_2142;
	case 8520ULL: goto x86_l_2148;
	case 8526ULL: goto x86_l_214e;
	case 8532ULL: goto x86_l_2154;
	case 8535ULL: goto x86_l_2157;
	case 8540ULL: goto x86_l_215c;
	case 8543ULL: goto x86_l_215f;
	case 8548ULL: goto x86_l_2164;
	case 8553ULL: goto x86_l_2169;
	case 8555ULL: goto x86_l_216b;
	case 8557ULL: goto x86_l_216d;
	case 8563ULL: goto x86_l_2173;
	case 8568ULL: goto x86_l_2178;
	case 8573ULL: goto x86_l_217d;
	case 8580ULL: goto x86_l_2184;
	case 8585ULL: goto x86_l_2189;
	case 8588ULL: goto x86_l_218c;
	case 8590ULL: goto x86_l_218e;
	case 8593ULL: goto x86_l_2191;
	case 8599ULL: goto x86_l_2197;
	case 8601ULL: goto x86_l_2199;
	case 8607ULL: goto x86_l_219f;
	case 8610ULL: goto x86_l_21a2;
	case 8613ULL: goto x86_l_21a5;
	case 8619ULL: goto x86_l_21ab;
	case 8624ULL: goto x86_l_21b0;
	case 8627ULL: goto x86_l_21b3;
	case 8633ULL: goto x86_l_21b9;
	case 8641ULL: goto x86_l_21c1;
	case 8644ULL: goto x86_l_21c4;
	case 8650ULL: goto x86_l_21ca;
	case 8655ULL: goto x86_l_21cf;
	case 8658ULL: goto x86_l_21d2;
	case 8664ULL: goto x86_l_21d8;
	case 8669ULL: goto x86_l_21dd;
	case 8672ULL: goto x86_l_21e0;
	case 8678ULL: goto x86_l_21e6;
	case 8686ULL: goto x86_l_21ee;
	case 8689ULL: goto x86_l_21f1;
	case 8695ULL: goto x86_l_21f7;
	case 8700ULL: goto x86_l_21fc;
	case 8703ULL: goto x86_l_21ff;
	case 8709ULL: goto x86_l_2205;
	case 8714ULL: goto x86_l_220a;
	case 8721ULL: goto x86_l_2211;
	case 8726ULL: goto x86_l_2216;
	case 8733ULL: goto x86_l_221d;
	case 8740ULL: goto x86_l_2224;
	case 8745ULL: goto x86_l_2229;
	case 8752ULL: goto x86_l_2230;
	case 8757ULL: goto x86_l_2235;
	case 8762ULL: goto x86_l_223a;
	case 8766ULL: goto x86_l_223e;
	case 8768ULL: goto x86_l_2240;
	case 8774ULL: goto x86_l_2246;
	case 8780ULL: goto x86_l_224c;
	case 8783ULL: goto x86_l_224f;
	case 8788ULL: goto x86_l_2254;
	case 8791ULL: goto x86_l_2257;
	case 8796ULL: goto x86_l_225c;
	case 8801ULL: goto x86_l_2261;
	case 8803ULL: goto x86_l_2263;
	case 8805ULL: goto x86_l_2265;
	case 8807ULL: goto x86_l_2267;
	case 8813ULL: goto x86_l_226d;
	case 8819ULL: goto x86_l_2273;
	case 8822ULL: goto x86_l_2276;
	case 8827ULL: goto x86_l_227b;
	case 8832ULL: goto x86_l_2280;
	case 8837ULL: goto x86_l_2285;
	case 8839ULL: goto x86_l_2287;
	case 8841ULL: goto x86_l_2289;
	case 8847ULL: goto x86_l_228f;
	case 8849ULL: goto x86_l_2291;
	case 8852ULL: goto x86_l_2294;
	case 8857ULL: goto x86_l_2299;
	case 8859ULL: goto x86_l_229b;
	case 8862ULL: goto x86_l_229e;
	case 8870ULL: goto x86_l_22a6;
	case 8876ULL: goto x86_l_22ac;
	case 8883ULL: goto x86_l_22b3;
	case 8886ULL: goto x86_l_22b6;
	case 8892ULL: goto x86_l_22bc;
	case 8895ULL: goto x86_l_22bf;
	case 8900ULL: goto x86_l_22c4;
	case 8907ULL: goto x86_l_22cb;
	case 8909ULL: goto x86_l_22cd;
	case 8915ULL: goto x86_l_22d3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c0c:
	/* 0x1c0c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c11:
	/* 0x1c11: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c16:
	/* 0x1c16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c18:
	/* 0x1c18: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c1d:
	/* 0x1c1d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c1f:
	/* 0x1c1f: js     1eb3 <generic_sleepable_preload+0x1eb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1eb3;
	}
x86_l_1c25:
	/* 0x1c25: cmp    WORD PTR [rdi+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_1c2a:
	/* 0x1c2a: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fbf;
	}
x86_l_1c30:
	/* 0x1c30: mov    eax,DWORD PTR [rdi+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1c33:
	/* 0x1c33: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1c38:
	/* 0x1c38: cmp    WORD PTR [rdi+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_1c3d:
	/* 0x1c3d: je     1c62 <generic_sleepable_preload+0x1c62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c62;
	}
x86_l_1c3f:
	/* 0x1c3f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c44:
	/* 0x1c44: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c49:
	/* 0x1c49: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c4e:
	/* 0x1c4e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c53:
	/* 0x1c53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c55:
	/* 0x1c55: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c5a:
	/* 0x1c5a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c5c:
	/* 0x1c5c: js     1ec4 <generic_sleepable_preload+0x1ec4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ec4;
	}
x86_l_1c62:
	/* 0x1c62: cmp    WORD PTR [rdi+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_1c6a:
	/* 0x1c6a: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fbf;
	}
x86_l_1c70:
	/* 0x1c70: mov    eax,DWORD PTR [rdi+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c76:
	/* 0x1c76: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1c7b:
	/* 0x1c7b: cmp    WORD PTR [rdi+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1c83:
	/* 0x1c83: je     1ca8 <generic_sleepable_preload+0x1ca8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ca8;
	}
x86_l_1c85:
	/* 0x1c85: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c8a:
	/* 0x1c8a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c8f:
	/* 0x1c8f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c94:
	/* 0x1c94: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c99:
	/* 0x1c99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c9b:
	/* 0x1c9b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ca0:
	/* 0x1ca0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ca2:
	/* 0x1ca2: js     1f04 <generic_sleepable_preload+0x1f04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1f04;
	}
x86_l_1ca8:
	/* 0x1ca8: cmp    WORD PTR [rdi+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1cb0:
	/* 0x1cb0: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fbf;
	}
x86_l_1cb6:
	/* 0x1cb6: mov    eax,DWORD PTR [rdi+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1cbc:
	/* 0x1cbc: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1cc1:
	/* 0x1cc1: cmp    WORD PTR [rdi+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1cc9:
	/* 0x1cc9: je     1cee <generic_sleepable_preload+0x1cee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cee;
	}
x86_l_1ccb:
	/* 0x1ccb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1cd0:
	/* 0x1cd0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cd5:
	/* 0x1cd5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cda:
	/* 0x1cda: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cdf:
	/* 0x1cdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ce1:
	/* 0x1ce1: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ce6:
	/* 0x1ce6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ce8:
	/* 0x1ce8: js     1f15 <generic_sleepable_preload+0x1f15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1f15;
	}
x86_l_1cee:
	/* 0x1cee: cmp    WORD PTR [rdi+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1cf6:
	/* 0x1cf6: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fbf;
	}
x86_l_1cfc:
	/* 0x1cfc: mov    eax,DWORD PTR [rdi+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1d02:
	/* 0x1d02: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1d07:
	/* 0x1d07: cmp    WORD PTR [rdi+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1d0f:
	/* 0x1d0f: je     1d34 <generic_sleepable_preload+0x1d34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d34;
	}
x86_l_1d11:
	/* 0x1d11: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d16:
	/* 0x1d16: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d1b:
	/* 0x1d1b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d20:
	/* 0x1d20: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d25:
	/* 0x1d25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d27:
	/* 0x1d27: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d2c:
	/* 0x1d2c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d2e:
	/* 0x1d2e: js     1f26 <generic_sleepable_preload+0x1f26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1f26;
	}
x86_l_1d34:
	/* 0x1d34: cmp    WORD PTR [rdi+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1d3c:
	/* 0x1d3c: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fbf;
	}
x86_l_1d42:
	/* 0x1d42: mov    eax,DWORD PTR [rdi+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1d48:
	/* 0x1d48: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1d4d:
	/* 0x1d4d: cmp    WORD PTR [rdi+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1d55:
	/* 0x1d55: je     1d7a <generic_sleepable_preload+0x1d7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d7a;
	}
x86_l_1d57:
	/* 0x1d57: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d5c:
	/* 0x1d5c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d61:
	/* 0x1d61: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d66:
	/* 0x1d66: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d6b:
	/* 0x1d6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d6d:
	/* 0x1d6d: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d72:
	/* 0x1d72: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d74:
	/* 0x1d74: js     1fb7 <generic_sleepable_preload+0x1fb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1fb7;
	}
x86_l_1d7a:
	/* 0x1d7a: cmp    WORD PTR [rdi+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1d82:
	/* 0x1d82: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fbf;
	}
x86_l_1d88:
	/* 0x1d88: mov    eax,DWORD PTR [rdi+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1d8e:
	/* 0x1d8e: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1d93:
	/* 0x1d93: cmp    WORD PTR [rdi+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1d9b:
	/* 0x1d9b: je     1dbb <generic_sleepable_preload+0x1dbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dbb;
	}
x86_l_1d9d:
	/* 0x1d9d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1da2:
	/* 0x1da2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1da7:
	/* 0x1da7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dac:
	/* 0x1dac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1db1:
	/* 0x1db1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1db3:
	/* 0x1db3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1db5:
	/* 0x1db5: js     5d98 <generic_sleepable_preload+0x5d98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23960ULL;
	}
x86_l_1dbb:
	/* 0x1dbb: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dc0:
	/* 0x1dc0: cmp    WORD PTR [rdi+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1dc8:
	/* 0x1dc8: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fbf;
	}
x86_l_1dce:
	/* 0x1dce: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_1dd1:
	/* 0x1dd1: mov    eax,DWORD PTR [rdi+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1dd7:
	/* 0x1dd7: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ddc:
	/* 0x1ddc: cmp    WORD PTR [rdi+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1de4:
	/* 0x1de4: je     1e04 <generic_sleepable_preload+0x1e04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e04;
	}
x86_l_1de6:
	/* 0x1de6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1deb:
	/* 0x1deb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1df0:
	/* 0x1df0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1df5:
	/* 0x1df5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dfa:
	/* 0x1dfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dfc:
	/* 0x1dfc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dfe:
	/* 0x1dfe: js     5fb1 <generic_sleepable_preload+0x5fb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24497ULL;
	}
x86_l_1e04:
	/* 0x1e04: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e09:
	/* 0x1e09: cmp    WORD PTR [rdi+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1e11:
	/* 0x1e11: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e16:
	/* 0x1e16: mov    r12,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_64);
x86_l_1e19:
	/* 0x1e19: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fbf;
	}
x86_l_1e1f:
	/* 0x1e1f: mov    eax,DWORD PTR [rdi+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1e25:
	/* 0x1e25: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1e2a:
	/* 0x1e2a: cmp    WORD PTR [rdi+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1e32:
	/* 0x1e32: je     1e52 <generic_sleepable_preload+0x1e52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e52;
	}
x86_l_1e34:
	/* 0x1e34: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e39:
	/* 0x1e39: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e3e:
	/* 0x1e3e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e43:
	/* 0x1e43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e48:
	/* 0x1e48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e4a:
	/* 0x1e4a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e4c:
	/* 0x1e4c: js     6090 <generic_sleepable_preload+0x6090> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24720ULL;
	}
x86_l_1e52:
	/* 0x1e52: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e57:
	/* 0x1e57: cmp    WORD PTR [rdi+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1e5f:
	/* 0x1e5f: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e64:
	/* 0x1e64: mov    r12,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_64);
x86_l_1e67:
	/* 0x1e67: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fbf;
	}
x86_l_1e6d:
	/* 0x1e6d: mov    eax,DWORD PTR [rdi+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1e73:
	/* 0x1e73: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1e78:
	/* 0x1e78: cmp    WORD PTR [rdi+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1e80:
	/* 0x1e80: je     1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fbf;
	}
x86_l_1e86:
	/* 0x1e86: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e8b:
	/* 0x1e8b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e90:
	/* 0x1e90: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e95:
	/* 0x1e95: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e9a:
	/* 0x1e9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e9c:
	/* 0x1e9c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ea1:
	/* 0x1ea1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ea3:
	/* 0x1ea3: jns    1fbf <generic_sleepable_preload+0x1fbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1fbf;
	}
x86_l_1ea9:
	/* 0x1ea9: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_1eae:
	/* 0x1eae: jmp    1fbc <generic_sleepable_preload+0x1fbc> */
	goto x86_l_1fbc;
x86_l_1eb3:
	/* 0x1eb3: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_1eb8:
	/* 0x1eb8: jmp    1fbc <generic_sleepable_preload+0x1fbc> */
	goto x86_l_1fbc;
x86_l_1ebd:
	/* 0x1ebd: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1ec2:
	/* 0x1ec2: jmp    1f35 <generic_sleepable_preload+0x1f35> */
	goto x86_l_1f35;
x86_l_1ec4:
	/* 0x1ec4: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1ec9:
	/* 0x1ec9: jmp    1fbc <generic_sleepable_preload+0x1fbc> */
	goto x86_l_1fbc;
x86_l_1ece:
	/* 0x1ece: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1ed3:
	/* 0x1ed3: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ed8:
	/* 0x1ed8: add    rdx,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_1edf:
	/* 0x1edf: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ee4:
	/* 0x1ee4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ee9:
	/* 0x1ee9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eeb:
	/* 0x1eeb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1eed:
	/* 0x1eed: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1ef0:
	/* 0x1ef0: je     12f8 <generic_sleepable_preload+0x12f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4856ULL;
	}
x86_l_1ef6:
	/* 0x1ef6: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_1ef8:
	/* 0x1ef8: jmp    1352 <generic_sleepable_preload+0x1352> */
	return 4946ULL;
x86_l_1efd:
	/* 0x1efd: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_1f02:
	/* 0x1f02: jmp    1f35 <generic_sleepable_preload+0x1f35> */
	goto x86_l_1f35;
x86_l_1f04:
	/* 0x1f04: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_1f09:
	/* 0x1f09: jmp    1fbc <generic_sleepable_preload+0x1fbc> */
	goto x86_l_1fbc;
x86_l_1f0e:
	/* 0x1f0e: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1f13:
	/* 0x1f13: jmp    1f35 <generic_sleepable_preload+0x1f35> */
	goto x86_l_1f35;
x86_l_1f15:
	/* 0x1f15: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1f1a:
	/* 0x1f1a: jmp    1fbc <generic_sleepable_preload+0x1fbc> */
	goto x86_l_1fbc;
x86_l_1f1f:
	/* 0x1f1f: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_1f24:
	/* 0x1f24: jmp    1f35 <generic_sleepable_preload+0x1f35> */
	goto x86_l_1f35;
x86_l_1f26:
	/* 0x1f26: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_1f2b:
	/* 0x1f2b: jmp    1fbc <generic_sleepable_preload+0x1fbc> */
	goto x86_l_1fbc;
x86_l_1f30:
	/* 0x1f30: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1f35:
	/* 0x1f35: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f38:
	/* 0x1f38: mov    ebx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f3b:
	/* 0x1f3b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f40:
	/* 0x1f40: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f45:
	/* 0x1f45: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f4a:
	/* 0x1f4a: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1f4d:
	/* 0x1f4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f4f:
	/* 0x1f4f: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_1f52:
	/* 0x1f52: jne    2064 <generic_sleepable_preload+0x2064> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2064;
	}
x86_l_1f58:
	/* 0x1f58: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f5d:
	/* 0x1f5d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1f62:
	/* 0x1f62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f64:
	/* 0x1f64: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f69:
	/* 0x1f69: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1f71:
	/* 0x1f71: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f76:
	/* 0x1f76: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1f7d:
	/* 0x1f7d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f82:
	/* 0x1f82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f84:
	/* 0x1f84: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f87:
	/* 0x1f87: je     2064 <generic_sleepable_preload+0x2064> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2064;
	}
x86_l_1f8d:
	/* 0x1f8d: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_1f93:
	/* 0x1f93: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_1f96:
	/* 0x1f96: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1f9d:
	/* 0x1f9d: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fa2:
	/* 0x1fa2: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1fa5:
	/* 0x1fa5: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1fa8:
	/* 0x1fa8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1fab:
	/* 0x1fab: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fad:
	/* 0x1fad: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1fb0:
	/* 0x1fb0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fb5:
	/* 0x1fb5: jmp    2021 <generic_sleepable_preload+0x2021> */
	goto x86_l_2021;
x86_l_1fb7:
	/* 0x1fb7: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1fbc:
	/* 0x1fbc: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fbf:
	/* 0x1fbf: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_1fc2:
	/* 0x1fc2: jne    2069 <generic_sleepable_preload+0x2069> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2069;
	}
x86_l_1fc8:
	/* 0x1fc8: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fcd:
	/* 0x1fcd: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1fd2:
	/* 0x1fd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd4:
	/* 0x1fd4: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fd9:
	/* 0x1fd9: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1fe1:
	/* 0x1fe1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fe6:
	/* 0x1fe6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1fed:
	/* 0x1fed: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ff2:
	/* 0x1ff2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ff4:
	/* 0x1ff4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ff7:
	/* 0x1ff7: je     2064 <generic_sleepable_preload+0x2064> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2064;
	}
x86_l_1ff9:
	/* 0x1ff9: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_1fff:
	/* 0x1fff: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_2002:
	/* 0x2002: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2009:
	/* 0x2009: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_200e:
	/* 0x200e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2011:
	/* 0x2011: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2014:
	/* 0x2014: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2017:
	/* 0x2017: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2019:
	/* 0x2019: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_201c:
	/* 0x201c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2021:
	/* 0x2021: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2024:
	/* 0x2024: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_2027:
	/* 0x2027: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_202c:
	/* 0x202c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_202f:
	/* 0x202f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2031:
	/* 0x2031: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2034:
	/* 0x2034: je     2064 <generic_sleepable_preload+0x2064> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2064;
	}
x86_l_2036:
	/* 0x2036: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_2039:
	/* 0x2039: je     2062 <generic_sleepable_preload+0x2062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2062;
	}
x86_l_203b:
	/* 0x203b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_203e:
	/* 0x203e: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2042:
	/* 0x2042: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2047:
	/* 0x2047: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_204a:
	/* 0x204a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_204c:
	/* 0x204c: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_204f:
	/* 0x204f: call   2054 <generic_sleepable_preload+0x2054> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_2054:
	/* 0x2054: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2056:
	/* 0x2056: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_2059:
	/* 0x2059: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_205b:
	/* 0x205b: jns    2062 <generic_sleepable_preload+0x2062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_2062;
	}
x86_l_205d:
	/* 0x205d: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_2062:
	/* 0x2062: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2064:
	/* 0x2064: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2069:
	/* 0x2069: mov    eax,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_206c:
	/* 0x206c: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_2071:
	/* 0x2071: je     2fd8 <generic_sleepable_preload+0x2fd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12248ULL;
	}
x86_l_2077:
	/* 0x2077: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2079:
	/* 0x2079: js     20d3 <generic_sleepable_preload+0x20d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_20d3;
	}
x86_l_207b:
	/* 0x207b: movzx  ecx,BYTE PTR [rdi+0x229] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 553ULL);
x86_l_2082:
	/* 0x2082: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2084:
	/* 0x2084: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2087:
	/* 0x2087: jg     2136 <generic_sleepable_preload+0x2136> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2136;
	}
x86_l_208d:
	/* 0x208d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2090:
	/* 0x2090: je     220a <generic_sleepable_preload+0x220a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_220a;
	}
x86_l_2096:
	/* 0x2096: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2099:
	/* 0x2099: jne    2294 <generic_sleepable_preload+0x2294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2294;
	}
x86_l_209f:
	/* 0x209f: mov    edx,DWORD PTR [rdi+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_20a5:
	/* 0x20a5: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20ab:
	/* 0x20ab: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_20ae:
	/* 0x20ae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20b3:
	/* 0x20b3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20b8:
	/* 0x20b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20bd:
	/* 0x20bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20bf:
	/* 0x20bf: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20c4:
	/* 0x20c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20c6:
	/* 0x20c6: je     2216 <generic_sleepable_preload+0x2216> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2216;
	}
x86_l_20cc:
	/* 0x20cc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20ce:
	/* 0x20ce: jmp    2294 <generic_sleepable_preload+0x2294> */
	goto x86_l_2294;
x86_l_20d3:
	/* 0x20d3: movzx  ecx,BYTE PTR [rdi+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_20da:
	/* 0x20da: movzx  eax,WORD PTR [rdi+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_20e1:
	/* 0x20e1: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_20e7:
	/* 0x20e7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20e9:
	/* 0x20e9: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_20ec:
	/* 0x20ec: jle    2189 <generic_sleepable_preload+0x2189> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2189;
	}
x86_l_20f2:
	/* 0x20f2: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_20f5:
	/* 0x20f5: jle    21b0 <generic_sleepable_preload+0x21b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_21b0;
	}
x86_l_20fb:
	/* 0x20fb: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_20fe:
	/* 0x20fe: jle    2863 <generic_sleepable_preload+0x2863> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 10339ULL;
	}
x86_l_2104:
	/* 0x2104: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_210c:
	/* 0x210c: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_210f:
	/* 0x210f: je     2889 <generic_sleepable_preload+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10377ULL;
	}
x86_l_2115:
	/* 0x2115: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_211a:
	/* 0x211a: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_211d:
	/* 0x211d: je     2889 <generic_sleepable_preload+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10377ULL;
	}
x86_l_2123:
	/* 0x2123: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2128:
	/* 0x2128: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_212b:
	/* 0x212b: je     2889 <generic_sleepable_preload+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10377ULL;
	}
x86_l_2131:
	/* 0x2131: jmp    289c <generic_sleepable_preload+0x289c> */
	return 10396ULL;
x86_l_2136:
	/* 0x2136: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2139:
	/* 0x2139: je     2240 <generic_sleepable_preload+0x2240> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2240;
	}
x86_l_213f:
	/* 0x213f: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_2142:
	/* 0x2142: jne    2294 <generic_sleepable_preload+0x2294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2294;
	}
x86_l_2148:
	/* 0x2148: mov    edx,DWORD PTR [rdi+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_214e:
	/* 0x214e: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2154:
	/* 0x2154: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2157:
	/* 0x2157: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_215c:
	/* 0x215c: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_215f:
	/* 0x215f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2164:
	/* 0x2164: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2169:
	/* 0x2169: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_216b:
	/* 0x216b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_216d:
	/* 0x216d: jne    228f <generic_sleepable_preload+0x228f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_228f;
	}
x86_l_2173:
	/* 0x2173: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2178:
	/* 0x2178: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_217d:
	/* 0x217d: add    rdx,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 536ULL);
x86_l_2184:
	/* 0x2184: jmp    2e63 <generic_sleepable_preload+0x2e63> */
	return 11875ULL;
x86_l_2189:
	/* 0x2189: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_218c:
	/* 0x218c: jg     21dd <generic_sleepable_preload+0x21dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_21dd;
	}
x86_l_218e:
	/* 0x218e: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2191:
	/* 0x2191: jg     2834 <generic_sleepable_preload+0x2834> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10292ULL;
	}
x86_l_2197:
	/* 0x2197: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2199:
	/* 0x2199: je     2886 <generic_sleepable_preload+0x2886> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10374ULL;
	}
x86_l_219f:
	/* 0x219f: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_21a2:
	/* 0x21a2: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_21a5:
	/* 0x21a5: je     2889 <generic_sleepable_preload+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10377ULL;
	}
x86_l_21ab:
	/* 0x21ab: jmp    289c <generic_sleepable_preload+0x289c> */
	return 10396ULL;
x86_l_21b0:
	/* 0x21b0: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_21b3:
	/* 0x21b3: jg     281b <generic_sleepable_preload+0x281b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10267ULL;
	}
x86_l_21b9:
	/* 0x21b9: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_21c1:
	/* 0x21c1: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_21c4:
	/* 0x21c4: je     2889 <generic_sleepable_preload+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10377ULL;
	}
x86_l_21ca:
	/* 0x21ca: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_21cf:
	/* 0x21cf: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_21d2:
	/* 0x21d2: je     2889 <generic_sleepable_preload+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10377ULL;
	}
x86_l_21d8:
	/* 0x21d8: jmp    289c <generic_sleepable_preload+0x289c> */
	return 10396ULL;
x86_l_21dd:
	/* 0x21dd: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_21e0:
	/* 0x21e0: jg     284a <generic_sleepable_preload+0x284a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10314ULL;
	}
x86_l_21e6:
	/* 0x21e6: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_21ee:
	/* 0x21ee: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_21f1:
	/* 0x21f1: je     2889 <generic_sleepable_preload+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10377ULL;
	}
x86_l_21f7:
	/* 0x21f7: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_21fc:
	/* 0x21fc: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_21ff:
	/* 0x21ff: je     2889 <generic_sleepable_preload+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10377ULL;
	}
x86_l_2205:
	/* 0x2205: jmp    289c <generic_sleepable_preload+0x289c> */
	return 10396ULL;
x86_l_220a:
	/* 0x220a: mov    rax,QWORD PTR [rdi+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_2211:
	/* 0x2211: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2216:
	/* 0x2216: movzx  eax,BYTE PTR [rdi+0x228] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 552ULL);
x86_l_221d:
	/* 0x221d: shlx   rcx,QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((32ULL << 32) | X86_ALU_SHL));
x86_l_2224:
	/* 0x2224: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2229:
	/* 0x2229: cmp    BYTE PTR [rdi+0x22a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2379411881984ULL);
x86_l_2230:
	/* 0x2230: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_2235:
	/* 0x2235: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_223a:
	/* 0x223a: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_223e:
	/* 0x223e: jmp    2294 <generic_sleepable_preload+0x2294> */
	goto x86_l_2294;
x86_l_2240:
	/* 0x2240: mov    edx,DWORD PTR [rdi+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_2246:
	/* 0x2246: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_224c:
	/* 0x224c: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_224f:
	/* 0x224f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2254:
	/* 0x2254: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_2257:
	/* 0x2257: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_225c:
	/* 0x225c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2261:
	/* 0x2261: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2263:
	/* 0x2263: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2265:
	/* 0x2265: jne    228f <generic_sleepable_preload+0x228f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_228f;
	}
x86_l_2267:
	/* 0x2267: mov    edx,DWORD PTR [rbx+0x224] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 548ULL);
x86_l_226d:
	/* 0x226d: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2273:
	/* 0x2273: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2276:
	/* 0x2276: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_227b:
	/* 0x227b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2280:
	/* 0x2280: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2285:
	/* 0x2285: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2287:
	/* 0x2287: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2289:
	/* 0x2289: je     2e41 <generic_sleepable_preload+0x2e41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11841ULL;
	}
x86_l_228f:
	/* 0x228f: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_2291:
	/* 0x2291: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2294:
	/* 0x2294: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2299:
	/* 0x2299: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_229b:
	/* 0x229b: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_229e:
	/* 0x229e: cmp    WORD PTR [rdi+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_22a6:
	/* 0x22a6: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_22ac:
	/* 0x22ac: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_22b3:
	/* 0x22b3: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_22b6:
	/* 0x22b6: mov    edx,DWORD PTR [rdi+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_22bc:
	/* 0x22bc: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_22bf:
	/* 0x22bf: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22c4:
	/* 0x22c4: movzx  eax,WORD PTR [rdi+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_22cb:
	/* 0x22cb: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_22cd:
	/* 0x22cd: je     255c <generic_sleepable_preload+0x255c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9564ULL;
	}
x86_l_22d3:
	/* 0x22d3: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
	return 8918ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8918ULL: goto x86_l_22d6;
	case 8920ULL: goto x86_l_22d8;
	case 8925ULL: goto x86_l_22dd;
	case 8930ULL: goto x86_l_22e2;
	case 8935ULL: goto x86_l_22e7;
	case 8940ULL: goto x86_l_22ec;
	case 8942ULL: goto x86_l_22ee;
	case 8947ULL: goto x86_l_22f3;
	case 8949ULL: goto x86_l_22f5;
	case 8955ULL: goto x86_l_22fb;
	case 8963ULL: goto x86_l_2303;
	case 8969ULL: goto x86_l_2309;
	case 8975ULL: goto x86_l_230f;
	case 8980ULL: goto x86_l_2314;
	case 8988ULL: goto x86_l_231c;
	case 8990ULL: goto x86_l_231e;
	case 8995ULL: goto x86_l_2323;
	case 9000ULL: goto x86_l_2328;
	case 9005ULL: goto x86_l_232d;
	case 9010ULL: goto x86_l_2332;
	case 9012ULL: goto x86_l_2334;
	case 9017ULL: goto x86_l_2339;
	case 9019ULL: goto x86_l_233b;
	case 9025ULL: goto x86_l_2341;
	case 9033ULL: goto x86_l_2349;
	case 9039ULL: goto x86_l_234f;
	case 9045ULL: goto x86_l_2355;
	case 9050ULL: goto x86_l_235a;
	case 9058ULL: goto x86_l_2362;
	case 9060ULL: goto x86_l_2364;
	case 9065ULL: goto x86_l_2369;
	case 9070ULL: goto x86_l_236e;
	case 9075ULL: goto x86_l_2373;
	case 9080ULL: goto x86_l_2378;
	case 9082ULL: goto x86_l_237a;
	case 9087ULL: goto x86_l_237f;
	case 9089ULL: goto x86_l_2381;
	case 9095ULL: goto x86_l_2387;
	case 9103ULL: goto x86_l_238f;
	case 9109ULL: goto x86_l_2395;
	case 9115ULL: goto x86_l_239b;
	case 9120ULL: goto x86_l_23a0;
	case 9128ULL: goto x86_l_23a8;
	case 9130ULL: goto x86_l_23aa;
	case 9135ULL: goto x86_l_23af;
	case 9140ULL: goto x86_l_23b4;
	case 9145ULL: goto x86_l_23b9;
	case 9150ULL: goto x86_l_23be;
	case 9152ULL: goto x86_l_23c0;
	case 9157ULL: goto x86_l_23c5;
	case 9159ULL: goto x86_l_23c7;
	case 9165ULL: goto x86_l_23cd;
	case 9173ULL: goto x86_l_23d5;
	case 9179ULL: goto x86_l_23db;
	case 9185ULL: goto x86_l_23e1;
	case 9190ULL: goto x86_l_23e6;
	case 9198ULL: goto x86_l_23ee;
	case 9200ULL: goto x86_l_23f0;
	case 9205ULL: goto x86_l_23f5;
	case 9210ULL: goto x86_l_23fa;
	case 9215ULL: goto x86_l_23ff;
	case 9220ULL: goto x86_l_2404;
	case 9222ULL: goto x86_l_2406;
	case 9227ULL: goto x86_l_240b;
	case 9229ULL: goto x86_l_240d;
	case 9235ULL: goto x86_l_2413;
	case 9243ULL: goto x86_l_241b;
	case 9249ULL: goto x86_l_2421;
	case 9255ULL: goto x86_l_2427;
	case 9260ULL: goto x86_l_242c;
	case 9268ULL: goto x86_l_2434;
	case 9270ULL: goto x86_l_2436;
	case 9275ULL: goto x86_l_243b;
	case 9280ULL: goto x86_l_2440;
	case 9285ULL: goto x86_l_2445;
	case 9290ULL: goto x86_l_244a;
	case 9292ULL: goto x86_l_244c;
	case 9297ULL: goto x86_l_2451;
	case 9299ULL: goto x86_l_2453;
	case 9305ULL: goto x86_l_2459;
	case 9313ULL: goto x86_l_2461;
	case 9319ULL: goto x86_l_2467;
	case 9325ULL: goto x86_l_246d;
	case 9330ULL: goto x86_l_2472;
	case 9338ULL: goto x86_l_247a;
	case 9340ULL: goto x86_l_247c;
	case 9345ULL: goto x86_l_2481;
	case 9350ULL: goto x86_l_2486;
	case 9355ULL: goto x86_l_248b;
	case 9360ULL: goto x86_l_2490;
	case 9362ULL: goto x86_l_2492;
	case 9364ULL: goto x86_l_2494;
	case 9370ULL: goto x86_l_249a;
	case 9375ULL: goto x86_l_249f;
	case 9383ULL: goto x86_l_24a7;
	case 9389ULL: goto x86_l_24ad;
	case 9395ULL: goto x86_l_24b3;
	case 9400ULL: goto x86_l_24b8;
	case 9408ULL: goto x86_l_24c0;
	case 9410ULL: goto x86_l_24c2;
	case 9415ULL: goto x86_l_24c7;
	case 9420ULL: goto x86_l_24cc;
	case 9425ULL: goto x86_l_24d1;
	case 9430ULL: goto x86_l_24d6;
	case 9432ULL: goto x86_l_24d8;
	case 9434ULL: goto x86_l_24da;
	case 9440ULL: goto x86_l_24e0;
	case 9445ULL: goto x86_l_24e5;
	case 9453ULL: goto x86_l_24ed;
	case 9459ULL: goto x86_l_24f3;
	case 9465ULL: goto x86_l_24f9;
	case 9470ULL: goto x86_l_24fe;
	case 9478ULL: goto x86_l_2506;
	case 9480ULL: goto x86_l_2508;
	case 9485ULL: goto x86_l_250d;
	case 9490ULL: goto x86_l_2512;
	case 9495ULL: goto x86_l_2517;
	case 9500ULL: goto x86_l_251c;
	case 9502ULL: goto x86_l_251e;
	case 9504ULL: goto x86_l_2520;
	case 9510ULL: goto x86_l_2526;
	case 9515ULL: goto x86_l_252b;
	case 9523ULL: goto x86_l_2533;
	case 9529ULL: goto x86_l_2539;
	case 9535ULL: goto x86_l_253f;
	case 9540ULL: goto x86_l_2544;
	case 9548ULL: goto x86_l_254c;
	case 9554ULL: goto x86_l_2552;
	case 9559ULL: goto x86_l_2557;
	case 9564ULL: goto x86_l_255c;
	case 9567ULL: goto x86_l_255f;
	case 9569ULL: goto x86_l_2561;
	case 9574ULL: goto x86_l_2566;
	case 9579ULL: goto x86_l_256b;
	case 9584ULL: goto x86_l_2570;
	case 9589ULL: goto x86_l_2575;
	case 9591ULL: goto x86_l_2577;
	case 9596ULL: goto x86_l_257c;
	case 9598ULL: goto x86_l_257e;
	case 9604ULL: goto x86_l_2584;
	case 9612ULL: goto x86_l_258c;
	case 9618ULL: goto x86_l_2592;
	case 9624ULL: goto x86_l_2598;
	case 9629ULL: goto x86_l_259d;
	case 9637ULL: goto x86_l_25a5;
	case 9639ULL: goto x86_l_25a7;
	case 9644ULL: goto x86_l_25ac;
	case 9649ULL: goto x86_l_25b1;
	case 9654ULL: goto x86_l_25b6;
	case 9659ULL: goto x86_l_25bb;
	case 9661ULL: goto x86_l_25bd;
	case 9666ULL: goto x86_l_25c2;
	case 9668ULL: goto x86_l_25c4;
	case 9674ULL: goto x86_l_25ca;
	case 9682ULL: goto x86_l_25d2;
	case 9688ULL: goto x86_l_25d8;
	case 9694ULL: goto x86_l_25de;
	case 9699ULL: goto x86_l_25e3;
	case 9707ULL: goto x86_l_25eb;
	case 9709ULL: goto x86_l_25ed;
	case 9714ULL: goto x86_l_25f2;
	case 9719ULL: goto x86_l_25f7;
	case 9724ULL: goto x86_l_25fc;
	case 9729ULL: goto x86_l_2601;
	case 9731ULL: goto x86_l_2603;
	case 9736ULL: goto x86_l_2608;
	case 9738ULL: goto x86_l_260a;
	case 9744ULL: goto x86_l_2610;
	case 9752ULL: goto x86_l_2618;
	case 9758ULL: goto x86_l_261e;
	case 9764ULL: goto x86_l_2624;
	case 9769ULL: goto x86_l_2629;
	case 9777ULL: goto x86_l_2631;
	case 9779ULL: goto x86_l_2633;
	case 9784ULL: goto x86_l_2638;
	case 9789ULL: goto x86_l_263d;
	case 9794ULL: goto x86_l_2642;
	case 9799ULL: goto x86_l_2647;
	case 9801ULL: goto x86_l_2649;
	case 9806ULL: goto x86_l_264e;
	case 9808ULL: goto x86_l_2650;
	case 9814ULL: goto x86_l_2656;
	case 9822ULL: goto x86_l_265e;
	case 9828ULL: goto x86_l_2664;
	case 9834ULL: goto x86_l_266a;
	case 9839ULL: goto x86_l_266f;
	case 9847ULL: goto x86_l_2677;
	case 9849ULL: goto x86_l_2679;
	case 9854ULL: goto x86_l_267e;
	case 9859ULL: goto x86_l_2683;
	case 9864ULL: goto x86_l_2688;
	case 9869ULL: goto x86_l_268d;
	case 9871ULL: goto x86_l_268f;
	case 9876ULL: goto x86_l_2694;
	case 9878ULL: goto x86_l_2696;
	case 9884ULL: goto x86_l_269c;
	case 9892ULL: goto x86_l_26a4;
	case 9898ULL: goto x86_l_26aa;
	case 9904ULL: goto x86_l_26b0;
	case 9909ULL: goto x86_l_26b5;
	case 9917ULL: goto x86_l_26bd;
	case 9919ULL: goto x86_l_26bf;
	case 9924ULL: goto x86_l_26c4;
	case 9929ULL: goto x86_l_26c9;
	case 9934ULL: goto x86_l_26ce;
	case 9939ULL: goto x86_l_26d3;
	case 9941ULL: goto x86_l_26d5;
	case 9946ULL: goto x86_l_26da;
	case 9948ULL: goto x86_l_26dc;
	case 9954ULL: goto x86_l_26e2;
	case 9962ULL: goto x86_l_26ea;
	case 9968ULL: goto x86_l_26f0;
	case 9974ULL: goto x86_l_26f6;
	case 9979ULL: goto x86_l_26fb;
	case 9987ULL: goto x86_l_2703;
	case 9989ULL: goto x86_l_2705;
	case 9994ULL: goto x86_l_270a;
	case 9999ULL: goto x86_l_270f;
	case 10004ULL: goto x86_l_2714;
	case 10009ULL: goto x86_l_2719;
	case 10011ULL: goto x86_l_271b;
	case 10013ULL: goto x86_l_271d;
	case 10019ULL: goto x86_l_2723;
	case 10024ULL: goto x86_l_2728;
	case 10032ULL: goto x86_l_2730;
	case 10038ULL: goto x86_l_2736;
	case 10041ULL: goto x86_l_2739;
	case 10047ULL: goto x86_l_273f;
	case 10052ULL: goto x86_l_2744;
	case 10060ULL: goto x86_l_274c;
	case 10062ULL: goto x86_l_274e;
	case 10067ULL: goto x86_l_2753;
	case 10072ULL: goto x86_l_2758;
	case 10077ULL: goto x86_l_275d;
	case 10082ULL: goto x86_l_2762;
	case 10084ULL: goto x86_l_2764;
	case 10086ULL: goto x86_l_2766;
	case 10092ULL: goto x86_l_276c;
	case 10097ULL: goto x86_l_2771;
	case 10105ULL: goto x86_l_2779;
	case 10108ULL: goto x86_l_277c;
	case 10114ULL: goto x86_l_2782;
	case 10120ULL: goto x86_l_2788;
	case 10125ULL: goto x86_l_278d;
	case 10133ULL: goto x86_l_2795;
	case 10135ULL: goto x86_l_2797;
	case 10140ULL: goto x86_l_279c;
	case 10145ULL: goto x86_l_27a1;
	case 10150ULL: goto x86_l_27a6;
	case 10155ULL: goto x86_l_27ab;
	case 10157ULL: goto x86_l_27ad;
	case 10159ULL: goto x86_l_27af;
	case 10165ULL: goto x86_l_27b5;
	case 10170ULL: goto x86_l_27ba;
	case 10178ULL: goto x86_l_27c2;
	case 10181ULL: goto x86_l_27c5;
	case 10187ULL: goto x86_l_27cb;
	case 10193ULL: goto x86_l_27d1;
	case 10198ULL: goto x86_l_27d6;
	case 10206ULL: goto x86_l_27de;
	case 10212ULL: goto x86_l_27e4;
	case 10217ULL: goto x86_l_27e9;
	case 10222ULL: goto x86_l_27ee;
	case 10227ULL: goto x86_l_27f3;
	case 10232ULL: goto x86_l_27f8;
	case 10234ULL: goto x86_l_27fa;
	case 10239ULL: goto x86_l_27ff;
	case 10241ULL: goto x86_l_2801;
	case 10247ULL: goto x86_l_2807;
	case 10252ULL: goto x86_l_280c;
	case 10257ULL: goto x86_l_2811;
	case 10262ULL: goto x86_l_2816;
	case 10267ULL: goto x86_l_281b;
	case 10275ULL: goto x86_l_2823;
	case 10278ULL: goto x86_l_2826;
	case 10280ULL: goto x86_l_2828;
	case 10285ULL: goto x86_l_282d;
	case 10288ULL: goto x86_l_2830;
	case 10290ULL: goto x86_l_2832;
	case 10292ULL: goto x86_l_2834;
	case 10297ULL: goto x86_l_2839;
	case 10300ULL: goto x86_l_283c;
	case 10302ULL: goto x86_l_283e;
	case 10307ULL: goto x86_l_2843;
	case 10310ULL: goto x86_l_2846;
	case 10312ULL: goto x86_l_2848;
	case 10314ULL: goto x86_l_284a;
	case 10322ULL: goto x86_l_2852;
	case 10325ULL: goto x86_l_2855;
	case 10327ULL: goto x86_l_2857;
	case 10332ULL: goto x86_l_285c;
	case 10335ULL: goto x86_l_285f;
	case 10337ULL: goto x86_l_2861;
	case 10339ULL: goto x86_l_2863;
	case 10347ULL: goto x86_l_286b;
	case 10350ULL: goto x86_l_286e;
	case 10352ULL: goto x86_l_2870;
	case 10357ULL: goto x86_l_2875;
	case 10360ULL: goto x86_l_2878;
	case 10362ULL: goto x86_l_287a;
	case 10364ULL: goto x86_l_287c;
	case 10369ULL: goto x86_l_2881;
	case 10374ULL: goto x86_l_2886;
	case 10377ULL: goto x86_l_2889;
	case 10380ULL: goto x86_l_288c;
	case 10382ULL: goto x86_l_288e;
	case 10384ULL: goto x86_l_2890;
	case 10389ULL: goto x86_l_2895;
	case 10391ULL: goto x86_l_2897;
	case 10396ULL: goto x86_l_289c;
	case 10401ULL: goto x86_l_28a1;
	case 10404ULL: goto x86_l_28a4;
	case 10406ULL: goto x86_l_28a6;
	case 10409ULL: goto x86_l_28a9;
	case 10417ULL: goto x86_l_28b1;
	case 10423ULL: goto x86_l_28b7;
	case 10430ULL: goto x86_l_28be;
	case 10433ULL: goto x86_l_28c1;
	case 10439ULL: goto x86_l_28c7;
	case 10442ULL: goto x86_l_28ca;
	case 10447ULL: goto x86_l_28cf;
	case 10454ULL: goto x86_l_28d6;
	case 10456ULL: goto x86_l_28d8;
	case 10462ULL: goto x86_l_28de;
	case 10465ULL: goto x86_l_28e1;
	case 10467ULL: goto x86_l_28e3;
	case 10472ULL: goto x86_l_28e8;
	case 10477ULL: goto x86_l_28ed;
	case 10482ULL: goto x86_l_28f2;
	case 10487ULL: goto x86_l_28f7;
	case 10489ULL: goto x86_l_28f9;
	case 10494ULL: goto x86_l_28fe;
	case 10496ULL: goto x86_l_2900;
	case 10502ULL: goto x86_l_2906;
	case 10510ULL: goto x86_l_290e;
	case 10516ULL: goto x86_l_2914;
	case 10522ULL: goto x86_l_291a;
	case 10527ULL: goto x86_l_291f;
	case 10535ULL: goto x86_l_2927;
	case 10537ULL: goto x86_l_2929;
	case 10542ULL: goto x86_l_292e;
	case 10547ULL: goto x86_l_2933;
	case 10552ULL: goto x86_l_2938;
	case 10557ULL: goto x86_l_293d;
	case 10559ULL: goto x86_l_293f;
	case 10564ULL: goto x86_l_2944;
	case 10566ULL: goto x86_l_2946;
	case 10572ULL: goto x86_l_294c;
	case 10580ULL: goto x86_l_2954;
	case 10586ULL: goto x86_l_295a;
	case 10592ULL: goto x86_l_2960;
	case 10597ULL: goto x86_l_2965;
	case 10605ULL: goto x86_l_296d;
	case 10607ULL: goto x86_l_296f;
	case 10612ULL: goto x86_l_2974;
	case 10617ULL: goto x86_l_2979;
	case 10622ULL: goto x86_l_297e;
	case 10627ULL: goto x86_l_2983;
	case 10629ULL: goto x86_l_2985;
	case 10634ULL: goto x86_l_298a;
	case 10636ULL: goto x86_l_298c;
	case 10642ULL: goto x86_l_2992;
	case 10650ULL: goto x86_l_299a;
	case 10656ULL: goto x86_l_29a0;
	case 10662ULL: goto x86_l_29a6;
	case 10667ULL: goto x86_l_29ab;
	case 10675ULL: goto x86_l_29b3;
	case 10677ULL: goto x86_l_29b5;
	case 10682ULL: goto x86_l_29ba;
	case 10687ULL: goto x86_l_29bf;
	case 10692ULL: goto x86_l_29c4;
	case 10697ULL: goto x86_l_29c9;
	case 10699ULL: goto x86_l_29cb;
	case 10704ULL: goto x86_l_29d0;
	case 10706ULL: goto x86_l_29d2;
	case 10712ULL: goto x86_l_29d8;
	case 10720ULL: goto x86_l_29e0;
	case 10726ULL: goto x86_l_29e6;
	case 10732ULL: goto x86_l_29ec;
	case 10737ULL: goto x86_l_29f1;
	case 10745ULL: goto x86_l_29f9;
	case 10747ULL: goto x86_l_29fb;
	case 10752ULL: goto x86_l_2a00;
	case 10757ULL: goto x86_l_2a05;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22d6:
	/* 0x22d6: je     22fb <generic_sleepable_preload+0x22fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22fb;
	}
x86_l_22d8:
	/* 0x22d8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_22dd:
	/* 0x22dd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22e2:
	/* 0x22e2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22e7:
	/* 0x22e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22ec:
	/* 0x22ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22ee:
	/* 0x22ee: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22f3:
	/* 0x22f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22f5:
	/* 0x22f5: js     2811 <generic_sleepable_preload+0x2811> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2811;
	}
x86_l_22fb:
	/* 0x22fb: cmp    WORD PTR [rdi+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_2303:
	/* 0x2303: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_2309:
	/* 0x2309: mov    eax,DWORD PTR [rdi+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_230f:
	/* 0x230f: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2314:
	/* 0x2314: cmp    WORD PTR [rdi+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_231c:
	/* 0x231c: je     2341 <generic_sleepable_preload+0x2341> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2341;
	}
x86_l_231e:
	/* 0x231e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2323:
	/* 0x2323: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2328:
	/* 0x2328: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_232d:
	/* 0x232d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2332:
	/* 0x2332: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2334:
	/* 0x2334: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2339:
	/* 0x2339: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_233b:
	/* 0x233b: js     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_287c;
	}
x86_l_2341:
	/* 0x2341: cmp    WORD PTR [rdi+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_2349:
	/* 0x2349: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_234f:
	/* 0x234f: mov    eax,DWORD PTR [rdi+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2355:
	/* 0x2355: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_235a:
	/* 0x235a: cmp    WORD PTR [rdi+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_2362:
	/* 0x2362: je     2387 <generic_sleepable_preload+0x2387> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2387;
	}
x86_l_2364:
	/* 0x2364: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2369:
	/* 0x2369: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_236e:
	/* 0x236e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2373:
	/* 0x2373: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2378:
	/* 0x2378: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_237a:
	/* 0x237a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_237f:
	/* 0x237f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2381:
	/* 0x2381: js     2e30 <generic_sleepable_preload+0x2e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11824ULL;
	}
x86_l_2387:
	/* 0x2387: cmp    WORD PTR [rdi+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_238f:
	/* 0x238f: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_2395:
	/* 0x2395: mov    eax,DWORD PTR [rdi+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_239b:
	/* 0x239b: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_23a0:
	/* 0x23a0: cmp    WORD PTR [rdi+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_23a8:
	/* 0x23a8: je     23cd <generic_sleepable_preload+0x23cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23cd;
	}
x86_l_23aa:
	/* 0x23aa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23af:
	/* 0x23af: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23b4:
	/* 0x23b4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23b9:
	/* 0x23b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23be:
	/* 0x23be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23c0:
	/* 0x23c0: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23c5:
	/* 0x23c5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23c7:
	/* 0x23c7: js     2e81 <generic_sleepable_preload+0x2e81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11905ULL;
	}
x86_l_23cd:
	/* 0x23cd: cmp    WORD PTR [rdi+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_23d5:
	/* 0x23d5: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_23db:
	/* 0x23db: mov    eax,DWORD PTR [rdi+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_23e1:
	/* 0x23e1: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_23e6:
	/* 0x23e6: cmp    WORD PTR [rdi+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_23ee:
	/* 0x23ee: je     2413 <generic_sleepable_preload+0x2413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2413;
	}
x86_l_23f0:
	/* 0x23f0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23f5:
	/* 0x23f5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23fa:
	/* 0x23fa: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23ff:
	/* 0x23ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2404:
	/* 0x2404: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2406:
	/* 0x2406: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_240b:
	/* 0x240b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_240d:
	/* 0x240d: js     2e92 <generic_sleepable_preload+0x2e92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11922ULL;
	}
x86_l_2413:
	/* 0x2413: cmp    WORD PTR [rdi+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_241b:
	/* 0x241b: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_2421:
	/* 0x2421: mov    eax,DWORD PTR [rdi+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2427:
	/* 0x2427: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_242c:
	/* 0x242c: cmp    WORD PTR [rdi+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2434:
	/* 0x2434: je     2459 <generic_sleepable_preload+0x2459> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2459;
	}
x86_l_2436:
	/* 0x2436: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_243b:
	/* 0x243b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2440:
	/* 0x2440: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2445:
	/* 0x2445: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_244a:
	/* 0x244a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_244c:
	/* 0x244c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2451:
	/* 0x2451: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2453:
	/* 0x2453: js     2ea3 <generic_sleepable_preload+0x2ea3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11939ULL;
	}
x86_l_2459:
	/* 0x2459: cmp    WORD PTR [rdi+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2461:
	/* 0x2461: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_2467:
	/* 0x2467: mov    eax,DWORD PTR [rdi+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_246d:
	/* 0x246d: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2472:
	/* 0x2472: cmp    WORD PTR [rdi+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_247a:
	/* 0x247a: je     249a <generic_sleepable_preload+0x249a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_249a;
	}
x86_l_247c:
	/* 0x247c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2481:
	/* 0x2481: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2486:
	/* 0x2486: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_248b:
	/* 0x248b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2490:
	/* 0x2490: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2492:
	/* 0x2492: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2494:
	/* 0x2494: js     5daa <generic_sleepable_preload+0x5daa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23978ULL;
	}
x86_l_249a:
	/* 0x249a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_249f:
	/* 0x249f: cmp    WORD PTR [rdi+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_24a7:
	/* 0x24a7: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_24ad:
	/* 0x24ad: mov    eax,DWORD PTR [rdi+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_24b3:
	/* 0x24b3: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_24b8:
	/* 0x24b8: cmp    WORD PTR [rdi+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_24c0:
	/* 0x24c0: je     24e0 <generic_sleepable_preload+0x24e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24e0;
	}
x86_l_24c2:
	/* 0x24c2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24c7:
	/* 0x24c7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24cc:
	/* 0x24cc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24d1:
	/* 0x24d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24d6:
	/* 0x24d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24d8:
	/* 0x24d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24da:
	/* 0x24da: js     5f24 <generic_sleepable_preload+0x5f24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24356ULL;
	}
x86_l_24e0:
	/* 0x24e0: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24e5:
	/* 0x24e5: cmp    WORD PTR [rdi+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_24ed:
	/* 0x24ed: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_24f3:
	/* 0x24f3: mov    eax,DWORD PTR [rdi+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_24f9:
	/* 0x24f9: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_24fe:
	/* 0x24fe: cmp    WORD PTR [rdi+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2506:
	/* 0x2506: je     2526 <generic_sleepable_preload+0x2526> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2526;
	}
x86_l_2508:
	/* 0x2508: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_250d:
	/* 0x250d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2512:
	/* 0x2512: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2517:
	/* 0x2517: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_251c:
	/* 0x251c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_251e:
	/* 0x251e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2520:
	/* 0x2520: js     603a <generic_sleepable_preload+0x603a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24634ULL;
	}
x86_l_2526:
	/* 0x2526: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_252b:
	/* 0x252b: cmp    WORD PTR [rdi+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2533:
	/* 0x2533: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_2539:
	/* 0x2539: mov    eax,DWORD PTR [rdi+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_253f:
	/* 0x253f: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2544:
	/* 0x2544: cmp    WORD PTR [rdi+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_254c:
	/* 0x254c: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_2552:
	/* 0x2552: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2557:
	/* 0x2557: jmp    27e9 <generic_sleepable_preload+0x27e9> */
	goto x86_l_27e9;
x86_l_255c:
	/* 0x255c: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_255f:
	/* 0x255f: je     2584 <generic_sleepable_preload+0x2584> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2584;
	}
x86_l_2561:
	/* 0x2561: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2566:
	/* 0x2566: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_256b:
	/* 0x256b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2570:
	/* 0x2570: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2575:
	/* 0x2575: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2577:
	/* 0x2577: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_257c:
	/* 0x257c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_257e:
	/* 0x257e: js     2811 <generic_sleepable_preload+0x2811> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2811;
	}
x86_l_2584:
	/* 0x2584: cmp    WORD PTR [rdi+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_258c:
	/* 0x258c: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_2592:
	/* 0x2592: mov    eax,DWORD PTR [rdi+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2598:
	/* 0x2598: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_259d:
	/* 0x259d: cmp    WORD PTR [rdi+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_25a5:
	/* 0x25a5: je     25ca <generic_sleepable_preload+0x25ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ca;
	}
x86_l_25a7:
	/* 0x25a7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_25ac:
	/* 0x25ac: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25b1:
	/* 0x25b1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25b6:
	/* 0x25b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25bb:
	/* 0x25bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25bd:
	/* 0x25bd: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25c2:
	/* 0x25c2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25c4:
	/* 0x25c4: js     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_287c;
	}
x86_l_25ca:
	/* 0x25ca: cmp    WORD PTR [rdi+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_25d2:
	/* 0x25d2: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_25d8:
	/* 0x25d8: mov    eax,DWORD PTR [rdi+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_25de:
	/* 0x25de: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_25e3:
	/* 0x25e3: cmp    WORD PTR [rdi+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_25eb:
	/* 0x25eb: je     2610 <generic_sleepable_preload+0x2610> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2610;
	}
x86_l_25ed:
	/* 0x25ed: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_25f2:
	/* 0x25f2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25f7:
	/* 0x25f7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25fc:
	/* 0x25fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2601:
	/* 0x2601: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2603:
	/* 0x2603: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2608:
	/* 0x2608: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_260a:
	/* 0x260a: js     2e30 <generic_sleepable_preload+0x2e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11824ULL;
	}
x86_l_2610:
	/* 0x2610: cmp    WORD PTR [rdi+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_2618:
	/* 0x2618: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_261e:
	/* 0x261e: mov    eax,DWORD PTR [rdi+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2624:
	/* 0x2624: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2629:
	/* 0x2629: cmp    WORD PTR [rdi+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_2631:
	/* 0x2631: je     2656 <generic_sleepable_preload+0x2656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2656;
	}
x86_l_2633:
	/* 0x2633: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2638:
	/* 0x2638: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_263d:
	/* 0x263d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2642:
	/* 0x2642: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2647:
	/* 0x2647: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2649:
	/* 0x2649: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_264e:
	/* 0x264e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2650:
	/* 0x2650: js     2e81 <generic_sleepable_preload+0x2e81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11905ULL;
	}
x86_l_2656:
	/* 0x2656: cmp    WORD PTR [rdi+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_265e:
	/* 0x265e: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_2664:
	/* 0x2664: mov    eax,DWORD PTR [rdi+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_266a:
	/* 0x266a: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_266f:
	/* 0x266f: cmp    WORD PTR [rdi+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_2677:
	/* 0x2677: je     269c <generic_sleepable_preload+0x269c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_269c;
	}
x86_l_2679:
	/* 0x2679: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_267e:
	/* 0x267e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2683:
	/* 0x2683: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2688:
	/* 0x2688: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_268d:
	/* 0x268d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268f:
	/* 0x268f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2694:
	/* 0x2694: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2696:
	/* 0x2696: js     2e92 <generic_sleepable_preload+0x2e92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11922ULL;
	}
x86_l_269c:
	/* 0x269c: cmp    WORD PTR [rdi+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_26a4:
	/* 0x26a4: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_26aa:
	/* 0x26aa: mov    eax,DWORD PTR [rdi+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_26b0:
	/* 0x26b0: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_26b5:
	/* 0x26b5: cmp    WORD PTR [rdi+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_26bd:
	/* 0x26bd: je     26e2 <generic_sleepable_preload+0x26e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26e2;
	}
x86_l_26bf:
	/* 0x26bf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26c4:
	/* 0x26c4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26c9:
	/* 0x26c9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26ce:
	/* 0x26ce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26d3:
	/* 0x26d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26d5:
	/* 0x26d5: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26da:
	/* 0x26da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26dc:
	/* 0x26dc: js     2ea3 <generic_sleepable_preload+0x2ea3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11939ULL;
	}
x86_l_26e2:
	/* 0x26e2: cmp    WORD PTR [rdi+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_26ea:
	/* 0x26ea: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_26f0:
	/* 0x26f0: mov    eax,DWORD PTR [rdi+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_26f6:
	/* 0x26f6: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_26fb:
	/* 0x26fb: cmp    WORD PTR [rdi+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2703:
	/* 0x2703: je     2723 <generic_sleepable_preload+0x2723> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2723;
	}
x86_l_2705:
	/* 0x2705: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_270a:
	/* 0x270a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_270f:
	/* 0x270f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2714:
	/* 0x2714: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2719:
	/* 0x2719: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_271b:
	/* 0x271b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_271d:
	/* 0x271d: js     5daa <generic_sleepable_preload+0x5daa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23978ULL;
	}
x86_l_2723:
	/* 0x2723: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2728:
	/* 0x2728: cmp    WORD PTR [rdi+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_2730:
	/* 0x2730: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_2736:
	/* 0x2736: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_2739:
	/* 0x2739: mov    eax,DWORD PTR [rdi+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_273f:
	/* 0x273f: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2744:
	/* 0x2744: cmp    WORD PTR [rdi+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_274c:
	/* 0x274c: je     276c <generic_sleepable_preload+0x276c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_276c;
	}
x86_l_274e:
	/* 0x274e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2753:
	/* 0x2753: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2758:
	/* 0x2758: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_275d:
	/* 0x275d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2762:
	/* 0x2762: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2764:
	/* 0x2764: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2766:
	/* 0x2766: js     5fbe <generic_sleepable_preload+0x5fbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24510ULL;
	}
x86_l_276c:
	/* 0x276c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2771:
	/* 0x2771: cmp    WORD PTR [rdi+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2779:
	/* 0x2779: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_277c:
	/* 0x277c: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_2782:
	/* 0x2782: mov    eax,DWORD PTR [rdi+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2788:
	/* 0x2788: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_278d:
	/* 0x278d: cmp    WORD PTR [rdi+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2795:
	/* 0x2795: je     27b5 <generic_sleepable_preload+0x27b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27b5;
	}
x86_l_2797:
	/* 0x2797: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_279c:
	/* 0x279c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27a1:
	/* 0x27a1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27a6:
	/* 0x27a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27ab:
	/* 0x27ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27ad:
	/* 0x27ad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27af:
	/* 0x27af: js     60aa <generic_sleepable_preload+0x60aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24746ULL;
	}
x86_l_27b5:
	/* 0x27b5: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27ba:
	/* 0x27ba: cmp    WORD PTR [rdi+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_27c2:
	/* 0x27c2: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_27c5:
	/* 0x27c5: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_27cb:
	/* 0x27cb: mov    eax,DWORD PTR [rdi+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_27d1:
	/* 0x27d1: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_27d6:
	/* 0x27d6: cmp    WORD PTR [rdi+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_27de:
	/* 0x27de: je     2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11947ULL;
	}
x86_l_27e4:
	/* 0x27e4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_27e9:
	/* 0x27e9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27ee:
	/* 0x27ee: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27f3:
	/* 0x27f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27f8:
	/* 0x27f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27fa:
	/* 0x27fa: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27ff:
	/* 0x27ff: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2801:
	/* 0x2801: jns    2eab <generic_sleepable_preload+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 11947ULL;
	}
x86_l_2807:
	/* 0x2807: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_280c:
	/* 0x280c: jmp    2ea8 <generic_sleepable_preload+0x2ea8> */
	return 11944ULL;
x86_l_2811:
	/* 0x2811: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2816:
	/* 0x2816: jmp    2ea8 <generic_sleepable_preload+0x2ea8> */
	return 11944ULL;
x86_l_281b:
	/* 0x281b: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2823:
	/* 0x2823: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_2826:
	/* 0x2826: je     2889 <generic_sleepable_preload+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2889;
	}
x86_l_2828:
	/* 0x2828: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_282d:
	/* 0x282d: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_2830:
	/* 0x2830: je     2889 <generic_sleepable_preload+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2889;
	}
x86_l_2832:
	/* 0x2832: jmp    289c <generic_sleepable_preload+0x289c> */
	goto x86_l_289c;
x86_l_2834:
	/* 0x2834: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2839:
	/* 0x2839: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_283c:
	/* 0x283c: je     2889 <generic_sleepable_preload+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2889;
	}
x86_l_283e:
	/* 0x283e: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2843:
	/* 0x2843: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2846:
	/* 0x2846: je     2889 <generic_sleepable_preload+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2889;
	}
x86_l_2848:
	/* 0x2848: jmp    289c <generic_sleepable_preload+0x289c> */
	goto x86_l_289c;
x86_l_284a:
	/* 0x284a: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2852:
	/* 0x2852: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_2855:
	/* 0x2855: je     2889 <generic_sleepable_preload+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2889;
	}
x86_l_2857:
	/* 0x2857: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_285c:
	/* 0x285c: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_285f:
	/* 0x285f: je     2889 <generic_sleepable_preload+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2889;
	}
x86_l_2861:
	/* 0x2861: jmp    289c <generic_sleepable_preload+0x289c> */
	goto x86_l_289c;
x86_l_2863:
	/* 0x2863: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_286b:
	/* 0x286b: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_286e:
	/* 0x286e: je     2889 <generic_sleepable_preload+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2889;
	}
x86_l_2870:
	/* 0x2870: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2875:
	/* 0x2875: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2878:
	/* 0x2878: je     2889 <generic_sleepable_preload+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2889;
	}
x86_l_287a:
	/* 0x287a: jmp    289c <generic_sleepable_preload+0x289c> */
	goto x86_l_289c;
x86_l_287c:
	/* 0x287c: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_2881:
	/* 0x2881: jmp    2ea8 <generic_sleepable_preload+0x2ea8> */
	return 11944ULL;
x86_l_2886:
	/* 0x2886: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2889:
	/* 0x2889: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_288c:
	/* 0x288c: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_288e:
	/* 0x288e: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2890:
	/* 0x2890: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_2895:
	/* 0x2895: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2897:
	/* 0x2897: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_289c:
	/* 0x289c: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28a1:
	/* 0x28a1: mov    ebx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28a4:
	/* 0x28a4: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28a6:
	/* 0x28a6: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_28a9:
	/* 0x28a9: cmp    WORD PTR [rdi+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_28b1:
	/* 0x28b1: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12082ULL;
	}
x86_l_28b7:
	/* 0x28b7: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_28be:
	/* 0x28be: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_28c1:
	/* 0x28c1: mov    edx,DWORD PTR [rdi+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_28c7:
	/* 0x28c7: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28ca:
	/* 0x28ca: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28cf:
	/* 0x28cf: movzx  eax,WORD PTR [rdi+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_28d6:
	/* 0x28d6: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_28d8:
	/* 0x28d8: je     2b67 <generic_sleepable_preload+0x2b67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11111ULL;
	}
x86_l_28de:
	/* 0x28de: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_28e1:
	/* 0x28e1: je     2906 <generic_sleepable_preload+0x2906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2906;
	}
x86_l_28e3:
	/* 0x28e3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28e8:
	/* 0x28e8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28ed:
	/* 0x28ed: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28f2:
	/* 0x28f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28f7:
	/* 0x28f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28f9:
	/* 0x28f9: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28fe:
	/* 0x28fe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2900:
	/* 0x2900: js     2e1c <generic_sleepable_preload+0x2e1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11804ULL;
	}
x86_l_2906:
	/* 0x2906: cmp    WORD PTR [rdi+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_290e:
	/* 0x290e: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12082ULL;
	}
x86_l_2914:
	/* 0x2914: mov    eax,DWORD PTR [rdi+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_291a:
	/* 0x291a: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_291f:
	/* 0x291f: cmp    WORD PTR [rdi+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_2927:
	/* 0x2927: je     294c <generic_sleepable_preload+0x294c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_294c;
	}
x86_l_2929:
	/* 0x2929: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_292e:
	/* 0x292e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2933:
	/* 0x2933: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2938:
	/* 0x2938: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_293d:
	/* 0x293d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_293f:
	/* 0x293f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2944:
	/* 0x2944: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2946:
	/* 0x2946: js     2e26 <generic_sleepable_preload+0x2e26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11814ULL;
	}
x86_l_294c:
	/* 0x294c: cmp    WORD PTR [rdi+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_2954:
	/* 0x2954: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12082ULL;
	}
x86_l_295a:
	/* 0x295a: mov    eax,DWORD PTR [rdi+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2960:
	/* 0x2960: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2965:
	/* 0x2965: cmp    WORD PTR [rdi+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_296d:
	/* 0x296d: je     2992 <generic_sleepable_preload+0x2992> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2992;
	}
x86_l_296f:
	/* 0x296f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2974:
	/* 0x2974: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2979:
	/* 0x2979: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_297e:
	/* 0x297e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2983:
	/* 0x2983: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2985:
	/* 0x2985: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_298a:
	/* 0x298a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_298c:
	/* 0x298c: js     2e37 <generic_sleepable_preload+0x2e37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11831ULL;
	}
x86_l_2992:
	/* 0x2992: cmp    WORD PTR [rdi+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_299a:
	/* 0x299a: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12082ULL;
	}
x86_l_29a0:
	/* 0x29a0: mov    eax,DWORD PTR [rdi+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_29a6:
	/* 0x29a6: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_29ab:
	/* 0x29ab: cmp    WORD PTR [rdi+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_29b3:
	/* 0x29b3: je     29d8 <generic_sleepable_preload+0x29d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29d8;
	}
x86_l_29b5:
	/* 0x29b5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_29ba:
	/* 0x29ba: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29bf:
	/* 0x29bf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29c4:
	/* 0x29c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29c9:
	/* 0x29c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29cb:
	/* 0x29cb: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29d0:
	/* 0x29d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29d2:
	/* 0x29d2: js     2e88 <generic_sleepable_preload+0x2e88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11912ULL;
	}
x86_l_29d8:
	/* 0x29d8: cmp    WORD PTR [rdi+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_29e0:
	/* 0x29e0: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12082ULL;
	}
x86_l_29e6:
	/* 0x29e6: mov    eax,DWORD PTR [rdi+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_29ec:
	/* 0x29ec: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_29f1:
	/* 0x29f1: cmp    WORD PTR [rdi+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_29f9:
	/* 0x29f9: je     2a1e <generic_sleepable_preload+0x2a1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10782ULL;
	}
x86_l_29fb:
	/* 0x29fb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a00:
	/* 0x2a00: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a05:
	/* 0x2a05: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 10762ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10762ULL: goto x86_l_2a0a;
	case 10767ULL: goto x86_l_2a0f;
	case 10769ULL: goto x86_l_2a11;
	case 10774ULL: goto x86_l_2a16;
	case 10776ULL: goto x86_l_2a18;
	case 10782ULL: goto x86_l_2a1e;
	case 10790ULL: goto x86_l_2a26;
	case 10796ULL: goto x86_l_2a2c;
	case 10802ULL: goto x86_l_2a32;
	case 10807ULL: goto x86_l_2a37;
	case 10815ULL: goto x86_l_2a3f;
	case 10817ULL: goto x86_l_2a41;
	case 10822ULL: goto x86_l_2a46;
	case 10827ULL: goto x86_l_2a4b;
	case 10832ULL: goto x86_l_2a50;
	case 10837ULL: goto x86_l_2a55;
	case 10839ULL: goto x86_l_2a57;
	case 10844ULL: goto x86_l_2a5c;
	case 10846ULL: goto x86_l_2a5e;
	case 10852ULL: goto x86_l_2a64;
	case 10860ULL: goto x86_l_2a6c;
	case 10866ULL: goto x86_l_2a72;
	case 10872ULL: goto x86_l_2a78;
	case 10877ULL: goto x86_l_2a7d;
	case 10885ULL: goto x86_l_2a85;
	case 10887ULL: goto x86_l_2a87;
	case 10892ULL: goto x86_l_2a8c;
	case 10897ULL: goto x86_l_2a91;
	case 10902ULL: goto x86_l_2a96;
	case 10907ULL: goto x86_l_2a9b;
	case 10909ULL: goto x86_l_2a9d;
	case 10911ULL: goto x86_l_2a9f;
	case 10917ULL: goto x86_l_2aa5;
	case 10922ULL: goto x86_l_2aaa;
	case 10930ULL: goto x86_l_2ab2;
	case 10936ULL: goto x86_l_2ab8;
	case 10942ULL: goto x86_l_2abe;
	case 10947ULL: goto x86_l_2ac3;
	case 10955ULL: goto x86_l_2acb;
	case 10957ULL: goto x86_l_2acd;
	case 10962ULL: goto x86_l_2ad2;
	case 10967ULL: goto x86_l_2ad7;
	case 10972ULL: goto x86_l_2adc;
	case 10977ULL: goto x86_l_2ae1;
	case 10979ULL: goto x86_l_2ae3;
	case 10981ULL: goto x86_l_2ae5;
	case 10987ULL: goto x86_l_2aeb;
	case 10992ULL: goto x86_l_2af0;
	case 11000ULL: goto x86_l_2af8;
	case 11006ULL: goto x86_l_2afe;
	case 11012ULL: goto x86_l_2b04;
	case 11017ULL: goto x86_l_2b09;
	case 11025ULL: goto x86_l_2b11;
	case 11027ULL: goto x86_l_2b13;
	case 11032ULL: goto x86_l_2b18;
	case 11037ULL: goto x86_l_2b1d;
	case 11042ULL: goto x86_l_2b22;
	case 11047ULL: goto x86_l_2b27;
	case 11049ULL: goto x86_l_2b29;
	case 11051ULL: goto x86_l_2b2b;
	case 11057ULL: goto x86_l_2b31;
	case 11062ULL: goto x86_l_2b36;
	case 11070ULL: goto x86_l_2b3e;
	case 11076ULL: goto x86_l_2b44;
	case 11082ULL: goto x86_l_2b4a;
	case 11087ULL: goto x86_l_2b4f;
	case 11095ULL: goto x86_l_2b57;
	case 11101ULL: goto x86_l_2b5d;
	case 11106ULL: goto x86_l_2b62;
	case 11111ULL: goto x86_l_2b67;
	case 11114ULL: goto x86_l_2b6a;
	case 11116ULL: goto x86_l_2b6c;
	case 11121ULL: goto x86_l_2b71;
	case 11126ULL: goto x86_l_2b76;
	case 11131ULL: goto x86_l_2b7b;
	case 11136ULL: goto x86_l_2b80;
	case 11138ULL: goto x86_l_2b82;
	case 11143ULL: goto x86_l_2b87;
	case 11145ULL: goto x86_l_2b89;
	case 11151ULL: goto x86_l_2b8f;
	case 11159ULL: goto x86_l_2b97;
	case 11165ULL: goto x86_l_2b9d;
	case 11171ULL: goto x86_l_2ba3;
	case 11176ULL: goto x86_l_2ba8;
	case 11184ULL: goto x86_l_2bb0;
	case 11186ULL: goto x86_l_2bb2;
	case 11191ULL: goto x86_l_2bb7;
	case 11196ULL: goto x86_l_2bbc;
	case 11201ULL: goto x86_l_2bc1;
	case 11206ULL: goto x86_l_2bc6;
	case 11208ULL: goto x86_l_2bc8;
	case 11213ULL: goto x86_l_2bcd;
	case 11215ULL: goto x86_l_2bcf;
	case 11221ULL: goto x86_l_2bd5;
	case 11229ULL: goto x86_l_2bdd;
	case 11235ULL: goto x86_l_2be3;
	case 11241ULL: goto x86_l_2be9;
	case 11246ULL: goto x86_l_2bee;
	case 11254ULL: goto x86_l_2bf6;
	case 11256ULL: goto x86_l_2bf8;
	case 11261ULL: goto x86_l_2bfd;
	case 11266ULL: goto x86_l_2c02;
	case 11271ULL: goto x86_l_2c07;
	case 11276ULL: goto x86_l_2c0c;
	case 11278ULL: goto x86_l_2c0e;
	case 11283ULL: goto x86_l_2c13;
	case 11285ULL: goto x86_l_2c15;
	case 11291ULL: goto x86_l_2c1b;
	case 11299ULL: goto x86_l_2c23;
	case 11305ULL: goto x86_l_2c29;
	case 11311ULL: goto x86_l_2c2f;
	case 11316ULL: goto x86_l_2c34;
	case 11324ULL: goto x86_l_2c3c;
	case 11326ULL: goto x86_l_2c3e;
	case 11331ULL: goto x86_l_2c43;
	case 11336ULL: goto x86_l_2c48;
	case 11341ULL: goto x86_l_2c4d;
	case 11346ULL: goto x86_l_2c52;
	case 11348ULL: goto x86_l_2c54;
	case 11353ULL: goto x86_l_2c59;
	case 11355ULL: goto x86_l_2c5b;
	case 11361ULL: goto x86_l_2c61;
	case 11369ULL: goto x86_l_2c69;
	case 11375ULL: goto x86_l_2c6f;
	case 11381ULL: goto x86_l_2c75;
	case 11386ULL: goto x86_l_2c7a;
	case 11394ULL: goto x86_l_2c82;
	case 11396ULL: goto x86_l_2c84;
	case 11401ULL: goto x86_l_2c89;
	case 11406ULL: goto x86_l_2c8e;
	case 11411ULL: goto x86_l_2c93;
	case 11416ULL: goto x86_l_2c98;
	case 11418ULL: goto x86_l_2c9a;
	case 11423ULL: goto x86_l_2c9f;
	case 11425ULL: goto x86_l_2ca1;
	case 11431ULL: goto x86_l_2ca7;
	case 11439ULL: goto x86_l_2caf;
	case 11445ULL: goto x86_l_2cb5;
	case 11451ULL: goto x86_l_2cbb;
	case 11456ULL: goto x86_l_2cc0;
	case 11464ULL: goto x86_l_2cc8;
	case 11466ULL: goto x86_l_2cca;
	case 11471ULL: goto x86_l_2ccf;
	case 11476ULL: goto x86_l_2cd4;
	case 11481ULL: goto x86_l_2cd9;
	case 11486ULL: goto x86_l_2cde;
	case 11488ULL: goto x86_l_2ce0;
	case 11493ULL: goto x86_l_2ce5;
	case 11495ULL: goto x86_l_2ce7;
	case 11501ULL: goto x86_l_2ced;
	case 11509ULL: goto x86_l_2cf5;
	case 11515ULL: goto x86_l_2cfb;
	case 11521ULL: goto x86_l_2d01;
	case 11526ULL: goto x86_l_2d06;
	case 11534ULL: goto x86_l_2d0e;
	case 11536ULL: goto x86_l_2d10;
	case 11541ULL: goto x86_l_2d15;
	case 11546ULL: goto x86_l_2d1a;
	case 11551ULL: goto x86_l_2d1f;
	case 11556ULL: goto x86_l_2d24;
	case 11558ULL: goto x86_l_2d26;
	case 11560ULL: goto x86_l_2d28;
	case 11566ULL: goto x86_l_2d2e;
	case 11571ULL: goto x86_l_2d33;
	case 11579ULL: goto x86_l_2d3b;
	case 11585ULL: goto x86_l_2d41;
	case 11588ULL: goto x86_l_2d44;
	case 11594ULL: goto x86_l_2d4a;
	case 11599ULL: goto x86_l_2d4f;
	case 11607ULL: goto x86_l_2d57;
	case 11609ULL: goto x86_l_2d59;
	case 11614ULL: goto x86_l_2d5e;
	case 11619ULL: goto x86_l_2d63;
	case 11624ULL: goto x86_l_2d68;
	case 11629ULL: goto x86_l_2d6d;
	case 11631ULL: goto x86_l_2d6f;
	case 11633ULL: goto x86_l_2d71;
	case 11639ULL: goto x86_l_2d77;
	case 11644ULL: goto x86_l_2d7c;
	case 11652ULL: goto x86_l_2d84;
	case 11655ULL: goto x86_l_2d87;
	case 11661ULL: goto x86_l_2d8d;
	case 11667ULL: goto x86_l_2d93;
	case 11672ULL: goto x86_l_2d98;
	case 11680ULL: goto x86_l_2da0;
	case 11682ULL: goto x86_l_2da2;
	case 11687ULL: goto x86_l_2da7;
	case 11692ULL: goto x86_l_2dac;
	case 11697ULL: goto x86_l_2db1;
	case 11702ULL: goto x86_l_2db6;
	case 11704ULL: goto x86_l_2db8;
	case 11706ULL: goto x86_l_2dba;
	case 11712ULL: goto x86_l_2dc0;
	case 11717ULL: goto x86_l_2dc5;
	case 11725ULL: goto x86_l_2dcd;
	case 11728ULL: goto x86_l_2dd0;
	case 11734ULL: goto x86_l_2dd6;
	case 11740ULL: goto x86_l_2ddc;
	case 11745ULL: goto x86_l_2de1;
	case 11753ULL: goto x86_l_2de9;
	case 11759ULL: goto x86_l_2def;
	case 11764ULL: goto x86_l_2df4;
	case 11769ULL: goto x86_l_2df9;
	case 11774ULL: goto x86_l_2dfe;
	case 11779ULL: goto x86_l_2e03;
	case 11781ULL: goto x86_l_2e05;
	case 11786ULL: goto x86_l_2e0a;
	case 11788ULL: goto x86_l_2e0c;
	case 11794ULL: goto x86_l_2e12;
	case 11799ULL: goto x86_l_2e17;
	case 11804ULL: goto x86_l_2e1c;
	case 11809ULL: goto x86_l_2e21;
	case 11814ULL: goto x86_l_2e26;
	case 11819ULL: goto x86_l_2e2b;
	case 11824ULL: goto x86_l_2e30;
	case 11829ULL: goto x86_l_2e35;
	case 11831ULL: goto x86_l_2e37;
	case 11836ULL: goto x86_l_2e3c;
	case 11841ULL: goto x86_l_2e41;
	case 11846ULL: goto x86_l_2e46;
	case 11853ULL: goto x86_l_2e4d;
	case 11860ULL: goto x86_l_2e54;
	case 11867ULL: goto x86_l_2e5b;
	case 11872ULL: goto x86_l_2e60;
	case 11875ULL: goto x86_l_2e63;
	case 11880ULL: goto x86_l_2e68;
	case 11885ULL: goto x86_l_2e6d;
	case 11887ULL: goto x86_l_2e6f;
	case 11889ULL: goto x86_l_2e71;
	case 11892ULL: goto x86_l_2e74;
	case 11898ULL: goto x86_l_2e7a;
	case 11900ULL: goto x86_l_2e7c;
	case 11905ULL: goto x86_l_2e81;
	case 11910ULL: goto x86_l_2e86;
	case 11912ULL: goto x86_l_2e88;
	case 11917ULL: goto x86_l_2e8d;
	case 11922ULL: goto x86_l_2e92;
	case 11927ULL: goto x86_l_2e97;
	case 11929ULL: goto x86_l_2e99;
	case 11934ULL: goto x86_l_2e9e;
	case 11939ULL: goto x86_l_2ea3;
	case 11944ULL: goto x86_l_2ea8;
	case 11947ULL: goto x86_l_2eab;
	case 11950ULL: goto x86_l_2eae;
	case 11955ULL: goto x86_l_2eb3;
	case 11960ULL: goto x86_l_2eb8;
	case 11965ULL: goto x86_l_2ebd;
	case 11968ULL: goto x86_l_2ec0;
	case 11970ULL: goto x86_l_2ec2;
	case 11973ULL: goto x86_l_2ec5;
	case 11979ULL: goto x86_l_2ecb;
	case 11984ULL: goto x86_l_2ed0;
	case 11989ULL: goto x86_l_2ed5;
	case 11991ULL: goto x86_l_2ed7;
	case 11996ULL: goto x86_l_2edc;
	case 12004ULL: goto x86_l_2ee4;
	case 12009ULL: goto x86_l_2ee9;
	case 12016ULL: goto x86_l_2ef0;
	case 12021ULL: goto x86_l_2ef5;
	case 12023ULL: goto x86_l_2ef7;
	case 12026ULL: goto x86_l_2efa;
	case 12032ULL: goto x86_l_2f00;
	case 12038ULL: goto x86_l_2f06;
	case 12041ULL: goto x86_l_2f09;
	case 12048ULL: goto x86_l_2f10;
	case 12053ULL: goto x86_l_2f15;
	case 12056ULL: goto x86_l_2f18;
	case 12059ULL: goto x86_l_2f1b;
	case 12062ULL: goto x86_l_2f1e;
	case 12064ULL: goto x86_l_2f20;
	case 12067ULL: goto x86_l_2f23;
	case 12072ULL: goto x86_l_2f28;
	case 12074ULL: goto x86_l_2f2a;
	case 12079ULL: goto x86_l_2f2f;
	case 12082ULL: goto x86_l_2f32;
	case 12085ULL: goto x86_l_2f35;
	case 12091ULL: goto x86_l_2f3b;
	case 12096ULL: goto x86_l_2f40;
	case 12101ULL: goto x86_l_2f45;
	case 12103ULL: goto x86_l_2f47;
	case 12108ULL: goto x86_l_2f4c;
	case 12116ULL: goto x86_l_2f54;
	case 12121ULL: goto x86_l_2f59;
	case 12128ULL: goto x86_l_2f60;
	case 12133ULL: goto x86_l_2f65;
	case 12135ULL: goto x86_l_2f67;
	case 12138ULL: goto x86_l_2f6a;
	case 12140ULL: goto x86_l_2f6c;
	case 12146ULL: goto x86_l_2f72;
	case 12149ULL: goto x86_l_2f75;
	case 12156ULL: goto x86_l_2f7c;
	case 12161ULL: goto x86_l_2f81;
	case 12164ULL: goto x86_l_2f84;
	case 12167ULL: goto x86_l_2f87;
	case 12170ULL: goto x86_l_2f8a;
	case 12172ULL: goto x86_l_2f8c;
	case 12175ULL: goto x86_l_2f8f;
	case 12180ULL: goto x86_l_2f94;
	case 12183ULL: goto x86_l_2f97;
	case 12186ULL: goto x86_l_2f9a;
	case 12189ULL: goto x86_l_2f9d;
	case 12191ULL: goto x86_l_2f9f;
	case 12194ULL: goto x86_l_2fa2;
	case 12196ULL: goto x86_l_2fa4;
	case 12199ULL: goto x86_l_2fa7;
	case 12201ULL: goto x86_l_2fa9;
	case 12204ULL: goto x86_l_2fac;
	case 12208ULL: goto x86_l_2fb0;
	case 12213ULL: goto x86_l_2fb5;
	case 12216ULL: goto x86_l_2fb8;
	case 12218ULL: goto x86_l_2fba;
	case 12221ULL: goto x86_l_2fbd;
	case 12226ULL: goto x86_l_2fc2;
	case 12228ULL: goto x86_l_2fc4;
	case 12231ULL: goto x86_l_2fc7;
	case 12233ULL: goto x86_l_2fc9;
	case 12238ULL: goto x86_l_2fce;
	case 12241ULL: goto x86_l_2fd1;
	case 12243ULL: goto x86_l_2fd3;
	case 12248ULL: goto x86_l_2fd8;
	case 12251ULL: goto x86_l_2fdb;
	case 12256ULL: goto x86_l_2fe0;
	case 12262ULL: goto x86_l_2fe6;
	case 12264ULL: goto x86_l_2fe8;
	case 12266ULL: goto x86_l_2fea;
	case 12273ULL: goto x86_l_2ff1;
	case 12275ULL: goto x86_l_2ff3;
	case 12278ULL: goto x86_l_2ff6;
	case 12284ULL: goto x86_l_2ffc;
	case 12287ULL: goto x86_l_2fff;
	case 12292ULL: goto x86_l_3004;
	case 12298ULL: goto x86_l_300a;
	case 12301ULL: goto x86_l_300d;
	case 12307ULL: goto x86_l_3013;
	case 12313ULL: goto x86_l_3019;
	case 12319ULL: goto x86_l_301f;
	case 12322ULL: goto x86_l_3022;
	case 12327ULL: goto x86_l_3027;
	case 12332ULL: goto x86_l_302c;
	case 12337ULL: goto x86_l_3031;
	case 12339ULL: goto x86_l_3033;
	case 12344ULL: goto x86_l_3038;
	case 12346ULL: goto x86_l_303a;
	case 12352ULL: goto x86_l_3040;
	case 12354ULL: goto x86_l_3042;
	case 12359ULL: goto x86_l_3047;
	case 12366ULL: goto x86_l_304e;
	case 12373ULL: goto x86_l_3055;
	case 12379ULL: goto x86_l_305b;
	case 12381ULL: goto x86_l_305d;
	case 12384ULL: goto x86_l_3060;
	case 12390ULL: goto x86_l_3066;
	case 12393ULL: goto x86_l_3069;
	case 12399ULL: goto x86_l_306f;
	case 12402ULL: goto x86_l_3072;
	case 12408ULL: goto x86_l_3078;
	case 12416ULL: goto x86_l_3080;
	case 12419ULL: goto x86_l_3083;
	case 12425ULL: goto x86_l_3089;
	case 12430ULL: goto x86_l_308e;
	case 12433ULL: goto x86_l_3091;
	case 12439ULL: goto x86_l_3097;
	case 12444ULL: goto x86_l_309c;
	case 12447ULL: goto x86_l_309f;
	case 12453ULL: goto x86_l_30a5;
	case 12458ULL: goto x86_l_30aa;
	case 12461ULL: goto x86_l_30ad;
	case 12466ULL: goto x86_l_30b2;
	case 12472ULL: goto x86_l_30b8;
	case 12475ULL: goto x86_l_30bb;
	case 12481ULL: goto x86_l_30c1;
	case 12487ULL: goto x86_l_30c7;
	case 12493ULL: goto x86_l_30cd;
	case 12496ULL: goto x86_l_30d0;
	case 12501ULL: goto x86_l_30d5;
	case 12504ULL: goto x86_l_30d8;
	case 12509ULL: goto x86_l_30dd;
	case 12514ULL: goto x86_l_30e2;
	case 12516ULL: goto x86_l_30e4;
	case 12518ULL: goto x86_l_30e6;
	case 12524ULL: goto x86_l_30ec;
	case 12529ULL: goto x86_l_30f1;
	case 12534ULL: goto x86_l_30f6;
	case 12541ULL: goto x86_l_30fd;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a0a:
	/* 0x2a0a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a0f:
	/* 0x2a0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a11:
	/* 0x2a11: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a16:
	/* 0x2a16: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a18:
	/* 0x2a18: js     2e99 <generic_sleepable_preload+0x2e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e99;
	}
x86_l_2a1e:
	/* 0x2a1e: cmp    WORD PTR [rdi+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2a26:
	/* 0x2a26: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f32;
	}
x86_l_2a2c:
	/* 0x2a2c: mov    eax,DWORD PTR [rdi+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2a32:
	/* 0x2a32: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2a37:
	/* 0x2a37: cmp    WORD PTR [rdi+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2a3f:
	/* 0x2a3f: je     2a64 <generic_sleepable_preload+0x2a64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a64;
	}
x86_l_2a41:
	/* 0x2a41: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a46:
	/* 0x2a46: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a4b:
	/* 0x2a4b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a50:
	/* 0x2a50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a55:
	/* 0x2a55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a57:
	/* 0x2a57: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a5c:
	/* 0x2a5c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a5e:
	/* 0x2a5e: js     2f2a <generic_sleepable_preload+0x2f2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2f2a;
	}
x86_l_2a64:
	/* 0x2a64: cmp    WORD PTR [rdi+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2a6c:
	/* 0x2a6c: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f32;
	}
x86_l_2a72:
	/* 0x2a72: mov    eax,DWORD PTR [rdi+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2a78:
	/* 0x2a78: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2a7d:
	/* 0x2a7d: cmp    WORD PTR [rdi+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2a85:
	/* 0x2a85: je     2aa5 <generic_sleepable_preload+0x2aa5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aa5;
	}
x86_l_2a87:
	/* 0x2a87: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a8c:
	/* 0x2a8c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a91:
	/* 0x2a91: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a96:
	/* 0x2a96: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a9b:
	/* 0x2a9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a9d:
	/* 0x2a9d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a9f:
	/* 0x2a9f: js     5dbc <generic_sleepable_preload+0x5dbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23996ULL;
	}
x86_l_2aa5:
	/* 0x2aa5: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2aaa:
	/* 0x2aaa: cmp    WORD PTR [rdi+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_2ab2:
	/* 0x2ab2: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f32;
	}
x86_l_2ab8:
	/* 0x2ab8: mov    eax,DWORD PTR [rdi+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2abe:
	/* 0x2abe: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2ac3:
	/* 0x2ac3: cmp    WORD PTR [rdi+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2acb:
	/* 0x2acb: je     2aeb <generic_sleepable_preload+0x2aeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aeb;
	}
x86_l_2acd:
	/* 0x2acd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ad2:
	/* 0x2ad2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ad7:
	/* 0x2ad7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2adc:
	/* 0x2adc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ae1:
	/* 0x2ae1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae3:
	/* 0x2ae3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ae5:
	/* 0x2ae5: js     5f36 <generic_sleepable_preload+0x5f36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24374ULL;
	}
x86_l_2aeb:
	/* 0x2aeb: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2af0:
	/* 0x2af0: cmp    WORD PTR [rdi+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2af8:
	/* 0x2af8: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f32;
	}
x86_l_2afe:
	/* 0x2afe: mov    eax,DWORD PTR [rdi+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2b04:
	/* 0x2b04: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2b09:
	/* 0x2b09: cmp    WORD PTR [rdi+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2b11:
	/* 0x2b11: je     2b31 <generic_sleepable_preload+0x2b31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b31;
	}
x86_l_2b13:
	/* 0x2b13: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b18:
	/* 0x2b18: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b1d:
	/* 0x2b1d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b22:
	/* 0x2b22: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b27:
	/* 0x2b27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b29:
	/* 0x2b29: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b2b:
	/* 0x2b2b: js     6044 <generic_sleepable_preload+0x6044> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24644ULL;
	}
x86_l_2b31:
	/* 0x2b31: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b36:
	/* 0x2b36: cmp    WORD PTR [rdi+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2b3e:
	/* 0x2b3e: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f32;
	}
x86_l_2b44:
	/* 0x2b44: mov    eax,DWORD PTR [rdi+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2b4a:
	/* 0x2b4a: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2b4f:
	/* 0x2b4f: cmp    WORD PTR [rdi+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_2b57:
	/* 0x2b57: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f32;
	}
x86_l_2b5d:
	/* 0x2b5d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b62:
	/* 0x2b62: jmp    2df4 <generic_sleepable_preload+0x2df4> */
	goto x86_l_2df4;
x86_l_2b67:
	/* 0x2b67: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2b6a:
	/* 0x2b6a: je     2b8f <generic_sleepable_preload+0x2b8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b8f;
	}
x86_l_2b6c:
	/* 0x2b6c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b71:
	/* 0x2b71: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b76:
	/* 0x2b76: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b7b:
	/* 0x2b7b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b80:
	/* 0x2b80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b82:
	/* 0x2b82: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b87:
	/* 0x2b87: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b89:
	/* 0x2b89: js     2e1c <generic_sleepable_preload+0x2e1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e1c;
	}
x86_l_2b8f:
	/* 0x2b8f: cmp    WORD PTR [rdi+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_2b97:
	/* 0x2b97: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f32;
	}
x86_l_2b9d:
	/* 0x2b9d: mov    eax,DWORD PTR [rdi+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2ba3:
	/* 0x2ba3: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2ba8:
	/* 0x2ba8: cmp    WORD PTR [rdi+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_2bb0:
	/* 0x2bb0: je     2bd5 <generic_sleepable_preload+0x2bd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bd5;
	}
x86_l_2bb2:
	/* 0x2bb2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2bb7:
	/* 0x2bb7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bbc:
	/* 0x2bbc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bc1:
	/* 0x2bc1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bc6:
	/* 0x2bc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bc8:
	/* 0x2bc8: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2bcd:
	/* 0x2bcd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bcf:
	/* 0x2bcf: js     2e26 <generic_sleepable_preload+0x2e26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e26;
	}
x86_l_2bd5:
	/* 0x2bd5: cmp    WORD PTR [rdi+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_2bdd:
	/* 0x2bdd: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f32;
	}
x86_l_2be3:
	/* 0x2be3: mov    eax,DWORD PTR [rdi+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2be9:
	/* 0x2be9: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2bee:
	/* 0x2bee: cmp    WORD PTR [rdi+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_2bf6:
	/* 0x2bf6: je     2c1b <generic_sleepable_preload+0x2c1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c1b;
	}
x86_l_2bf8:
	/* 0x2bf8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2bfd:
	/* 0x2bfd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c02:
	/* 0x2c02: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c07:
	/* 0x2c07: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c0c:
	/* 0x2c0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c0e:
	/* 0x2c0e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c13:
	/* 0x2c13: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c15:
	/* 0x2c15: js     2e37 <generic_sleepable_preload+0x2e37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e37;
	}
x86_l_2c1b:
	/* 0x2c1b: cmp    WORD PTR [rdi+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_2c23:
	/* 0x2c23: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f32;
	}
x86_l_2c29:
	/* 0x2c29: mov    eax,DWORD PTR [rdi+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2c2f:
	/* 0x2c2f: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2c34:
	/* 0x2c34: cmp    WORD PTR [rdi+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_2c3c:
	/* 0x2c3c: je     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c61;
	}
x86_l_2c3e:
	/* 0x2c3e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c43:
	/* 0x2c43: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c48:
	/* 0x2c48: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c4d:
	/* 0x2c4d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c52:
	/* 0x2c52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c54:
	/* 0x2c54: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c59:
	/* 0x2c59: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c5b:
	/* 0x2c5b: js     2e88 <generic_sleepable_preload+0x2e88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e88;
	}
x86_l_2c61:
	/* 0x2c61: cmp    WORD PTR [rdi+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_2c69:
	/* 0x2c69: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f32;
	}
x86_l_2c6f:
	/* 0x2c6f: mov    eax,DWORD PTR [rdi+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2c75:
	/* 0x2c75: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2c7a:
	/* 0x2c7a: cmp    WORD PTR [rdi+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_2c82:
	/* 0x2c82: je     2ca7 <generic_sleepable_preload+0x2ca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ca7;
	}
x86_l_2c84:
	/* 0x2c84: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c89:
	/* 0x2c89: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c8e:
	/* 0x2c8e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c93:
	/* 0x2c93: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c98:
	/* 0x2c98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c9a:
	/* 0x2c9a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c9f:
	/* 0x2c9f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ca1:
	/* 0x2ca1: js     2e99 <generic_sleepable_preload+0x2e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e99;
	}
x86_l_2ca7:
	/* 0x2ca7: cmp    WORD PTR [rdi+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2caf:
	/* 0x2caf: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f32;
	}
x86_l_2cb5:
	/* 0x2cb5: mov    eax,DWORD PTR [rdi+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2cbb:
	/* 0x2cbb: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2cc0:
	/* 0x2cc0: cmp    WORD PTR [rdi+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2cc8:
	/* 0x2cc8: je     2ced <generic_sleepable_preload+0x2ced> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ced;
	}
x86_l_2cca:
	/* 0x2cca: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ccf:
	/* 0x2ccf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cd4:
	/* 0x2cd4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cd9:
	/* 0x2cd9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cde:
	/* 0x2cde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ce0:
	/* 0x2ce0: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ce5:
	/* 0x2ce5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ce7:
	/* 0x2ce7: js     2f2a <generic_sleepable_preload+0x2f2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2f2a;
	}
x86_l_2ced:
	/* 0x2ced: cmp    WORD PTR [rdi+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2cf5:
	/* 0x2cf5: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f32;
	}
x86_l_2cfb:
	/* 0x2cfb: mov    eax,DWORD PTR [rdi+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2d01:
	/* 0x2d01: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2d06:
	/* 0x2d06: cmp    WORD PTR [rdi+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2d0e:
	/* 0x2d0e: je     2d2e <generic_sleepable_preload+0x2d2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d2e;
	}
x86_l_2d10:
	/* 0x2d10: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d15:
	/* 0x2d15: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d1a:
	/* 0x2d1a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d1f:
	/* 0x2d1f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d24:
	/* 0x2d24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d26:
	/* 0x2d26: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d28:
	/* 0x2d28: js     5dbc <generic_sleepable_preload+0x5dbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23996ULL;
	}
x86_l_2d2e:
	/* 0x2d2e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d33:
	/* 0x2d33: cmp    WORD PTR [rdi+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_2d3b:
	/* 0x2d3b: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f32;
	}
x86_l_2d41:
	/* 0x2d41: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_2d44:
	/* 0x2d44: mov    eax,DWORD PTR [rdi+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2d4a:
	/* 0x2d4a: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2d4f:
	/* 0x2d4f: cmp    WORD PTR [rdi+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2d57:
	/* 0x2d57: je     2d77 <generic_sleepable_preload+0x2d77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d77;
	}
x86_l_2d59:
	/* 0x2d59: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d5e:
	/* 0x2d5e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d63:
	/* 0x2d63: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d68:
	/* 0x2d68: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d6d:
	/* 0x2d6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d6f:
	/* 0x2d6f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d71:
	/* 0x2d71: js     5fcb <generic_sleepable_preload+0x5fcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24523ULL;
	}
x86_l_2d77:
	/* 0x2d77: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d7c:
	/* 0x2d7c: cmp    WORD PTR [rdi+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2d84:
	/* 0x2d84: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_2d87:
	/* 0x2d87: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f32;
	}
x86_l_2d8d:
	/* 0x2d8d: mov    eax,DWORD PTR [rdi+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2d93:
	/* 0x2d93: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2d98:
	/* 0x2d98: cmp    WORD PTR [rdi+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2da0:
	/* 0x2da0: je     2dc0 <generic_sleepable_preload+0x2dc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dc0;
	}
x86_l_2da2:
	/* 0x2da2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2da7:
	/* 0x2da7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dac:
	/* 0x2dac: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2db1:
	/* 0x2db1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2db6:
	/* 0x2db6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2db8:
	/* 0x2db8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2dba:
	/* 0x2dba: js     60bf <generic_sleepable_preload+0x60bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24767ULL;
	}
x86_l_2dc0:
	/* 0x2dc0: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2dc5:
	/* 0x2dc5: cmp    WORD PTR [rdi+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2dcd:
	/* 0x2dcd: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_2dd0:
	/* 0x2dd0: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f32;
	}
x86_l_2dd6:
	/* 0x2dd6: mov    eax,DWORD PTR [rdi+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2ddc:
	/* 0x2ddc: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2de1:
	/* 0x2de1: cmp    WORD PTR [rdi+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_2de9:
	/* 0x2de9: je     2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f32;
	}
x86_l_2def:
	/* 0x2def: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2df4:
	/* 0x2df4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2df9:
	/* 0x2df9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dfe:
	/* 0x2dfe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e03:
	/* 0x2e03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e05:
	/* 0x2e05: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e0a:
	/* 0x2e0a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e0c:
	/* 0x2e0c: jns    2f32 <generic_sleepable_preload+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_2f32;
	}
x86_l_2e12:
	/* 0x2e12: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_2e17:
	/* 0x2e17: jmp    2f2f <generic_sleepable_preload+0x2f2f> */
	goto x86_l_2f2f;
x86_l_2e1c:
	/* 0x2e1c: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2e21:
	/* 0x2e21: jmp    2f2f <generic_sleepable_preload+0x2f2f> */
	goto x86_l_2f2f;
x86_l_2e26:
	/* 0x2e26: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_2e2b:
	/* 0x2e2b: jmp    2f2f <generic_sleepable_preload+0x2f2f> */
	goto x86_l_2f2f;
x86_l_2e30:
	/* 0x2e30: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2e35:
	/* 0x2e35: jmp    2ea8 <generic_sleepable_preload+0x2ea8> */
	goto x86_l_2ea8;
x86_l_2e37:
	/* 0x2e37: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2e3c:
	/* 0x2e3c: jmp    2f2f <generic_sleepable_preload+0x2f2f> */
	goto x86_l_2f2f;
x86_l_2e41:
	/* 0x2e41: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2e46:
	/* 0x2e46: movzx  ecx,BYTE PTR [rbx+0x22b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 555ULL);
x86_l_2e4d:
	/* 0x2e4d: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_2e54:
	/* 0x2e54: mov    rdx,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_2e5b:
	/* 0x2e5b: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2e60:
	/* 0x2e60: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e63:
	/* 0x2e63: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e68:
	/* 0x2e68: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e6d:
	/* 0x2e6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e6f:
	/* 0x2e6f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e71:
	/* 0x2e71: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2e74:
	/* 0x2e74: je     2216 <generic_sleepable_preload+0x2216> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8726ULL;
	}
x86_l_2e7a:
	/* 0x2e7a: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_2e7c:
	/* 0x2e7c: jmp    2294 <generic_sleepable_preload+0x2294> */
	return 8852ULL;
x86_l_2e81:
	/* 0x2e81: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2e86:
	/* 0x2e86: jmp    2ea8 <generic_sleepable_preload+0x2ea8> */
	goto x86_l_2ea8;
x86_l_2e88:
	/* 0x2e88: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2e8d:
	/* 0x2e8d: jmp    2f2f <generic_sleepable_preload+0x2f2f> */
	goto x86_l_2f2f;
x86_l_2e92:
	/* 0x2e92: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_2e97:
	/* 0x2e97: jmp    2ea8 <generic_sleepable_preload+0x2ea8> */
	goto x86_l_2ea8;
x86_l_2e99:
	/* 0x2e99: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_2e9e:
	/* 0x2e9e: jmp    2f2f <generic_sleepable_preload+0x2f2f> */
	goto x86_l_2f2f;
x86_l_2ea3:
	/* 0x2ea3: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_2ea8:
	/* 0x2ea8: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2eab:
	/* 0x2eab: mov    ebx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2eae:
	/* 0x2eae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2eb3:
	/* 0x2eb3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eb8:
	/* 0x2eb8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ebd:
	/* 0x2ebd: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2ec0:
	/* 0x2ec0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ec2:
	/* 0x2ec2: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2ec5:
	/* 0x2ec5: jne    2fd3 <generic_sleepable_preload+0x2fd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2fd3;
	}
x86_l_2ecb:
	/* 0x2ecb: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ed0:
	/* 0x2ed0: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2ed5:
	/* 0x2ed5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ed7:
	/* 0x2ed7: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2edc:
	/* 0x2edc: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2ee4:
	/* 0x2ee4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ee9:
	/* 0x2ee9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2ef0:
	/* 0x2ef0: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ef5:
	/* 0x2ef5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ef7:
	/* 0x2ef7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2efa:
	/* 0x2efa: je     2fd3 <generic_sleepable_preload+0x2fd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fd3;
	}
x86_l_2f00:
	/* 0x2f00: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_2f06:
	/* 0x2f06: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_2f09:
	/* 0x2f09: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2f10:
	/* 0x2f10: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f15:
	/* 0x2f15: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2f18:
	/* 0x2f18: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2f1b:
	/* 0x2f1b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2f1e:
	/* 0x2f1e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f20:
	/* 0x2f20: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2f23:
	/* 0x2f23: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f28:
	/* 0x2f28: jmp    2f94 <generic_sleepable_preload+0x2f94> */
	goto x86_l_2f94;
x86_l_2f2a:
	/* 0x2f2a: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_2f2f:
	/* 0x2f2f: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f32:
	/* 0x2f32: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2f35:
	/* 0x2f35: jne    2fd8 <generic_sleepable_preload+0x2fd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2fd8;
	}
x86_l_2f3b:
	/* 0x2f3b: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f40:
	/* 0x2f40: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2f45:
	/* 0x2f45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f47:
	/* 0x2f47: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f4c:
	/* 0x2f4c: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2f54:
	/* 0x2f54: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f59:
	/* 0x2f59: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2f60:
	/* 0x2f60: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f65:
	/* 0x2f65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f67:
	/* 0x2f67: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f6a:
	/* 0x2f6a: je     2fd3 <generic_sleepable_preload+0x2fd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fd3;
	}
x86_l_2f6c:
	/* 0x2f6c: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_2f72:
	/* 0x2f72: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_2f75:
	/* 0x2f75: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2f7c:
	/* 0x2f7c: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f81:
	/* 0x2f81: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2f84:
	/* 0x2f84: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2f87:
	/* 0x2f87: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2f8a:
	/* 0x2f8a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f8c:
	/* 0x2f8c: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2f8f:
	/* 0x2f8f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f94:
	/* 0x2f94: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2f97:
	/* 0x2f97: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_2f9a:
	/* 0x2f9a: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2f9d:
	/* 0x2f9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f9f:
	/* 0x2f9f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2fa2:
	/* 0x2fa2: je     2fd3 <generic_sleepable_preload+0x2fd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fd3;
	}
x86_l_2fa4:
	/* 0x2fa4: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_2fa7:
	/* 0x2fa7: je     2fd1 <generic_sleepable_preload+0x2fd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fd1;
	}
x86_l_2fa9:
	/* 0x2fa9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2fac:
	/* 0x2fac: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2fb0:
	/* 0x2fb0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2fb5:
	/* 0x2fb5: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2fb8:
	/* 0x2fb8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fba:
	/* 0x2fba: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2fbd:
	/* 0x2fbd: call   2fc2 <generic_sleepable_preload+0x2fc2> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_2fc2:
	/* 0x2fc2: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2fc4:
	/* 0x2fc4: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_2fc7:
	/* 0x2fc7: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2fc9:
	/* 0x2fc9: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2fce:
	/* 0x2fce: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_2fd1:
	/* 0x2fd1: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fd3:
	/* 0x2fd3: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fd8:
	/* 0x2fd8: mov    eax,DWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fdb:
	/* 0x2fdb: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_2fe0:
	/* 0x2fe0: je     3f4c <generic_sleepable_preload+0x3f4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16204ULL;
	}
x86_l_2fe6:
	/* 0x2fe6: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2fe8:
	/* 0x2fe8: js     3047 <generic_sleepable_preload+0x3047> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3047;
	}
x86_l_2fea:
	/* 0x2fea: movzx  ecx,BYTE PTR [rdi+0x241] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 577ULL);
x86_l_2ff1:
	/* 0x2ff1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ff3:
	/* 0x2ff3: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2ff6:
	/* 0x2ff6: jg     30aa <generic_sleepable_preload+0x30aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_30aa;
	}
x86_l_2ffc:
	/* 0x2ffc: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2fff:
	/* 0x2fff: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3004:
	/* 0x3004: je     3188 <generic_sleepable_preload+0x3188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12680ULL;
	}
x86_l_300a:
	/* 0x300a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_300d:
	/* 0x300d: jne    320d <generic_sleepable_preload+0x320d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12813ULL;
	}
x86_l_3013:
	/* 0x3013: mov    edx,DWORD PTR [rdi+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_3019:
	/* 0x3019: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_301f:
	/* 0x301f: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3022:
	/* 0x3022: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3027:
	/* 0x3027: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_302c:
	/* 0x302c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3031:
	/* 0x3031: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3033:
	/* 0x3033: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3038:
	/* 0x3038: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_303a:
	/* 0x303a: je     3194 <generic_sleepable_preload+0x3194> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12692ULL;
	}
x86_l_3040:
	/* 0x3040: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3042:
	/* 0x3042: jmp    320d <generic_sleepable_preload+0x320d> */
	return 12813ULL;
x86_l_3047:
	/* 0x3047: movzx  ecx,BYTE PTR [rdi+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_304e:
	/* 0x304e: movzx  eax,WORD PTR [rdi+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_3055:
	/* 0x3055: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_305b:
	/* 0x305b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_305d:
	/* 0x305d: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_3060:
	/* 0x3060: jle    3102 <generic_sleepable_preload+0x3102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 12546ULL;
	}
x86_l_3066:
	/* 0x3066: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3069:
	/* 0x3069: jle    312e <generic_sleepable_preload+0x312e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 12590ULL;
	}
x86_l_306f:
	/* 0x306f: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_3072:
	/* 0x3072: jle    37dc <generic_sleepable_preload+0x37dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 14300ULL;
	}
x86_l_3078:
	/* 0x3078: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3080:
	/* 0x3080: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_3083:
	/* 0x3083: je     37f3 <generic_sleepable_preload+0x37f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14323ULL;
	}
x86_l_3089:
	/* 0x3089: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_308e:
	/* 0x308e: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_3091:
	/* 0x3091: je     37f3 <generic_sleepable_preload+0x37f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14323ULL;
	}
x86_l_3097:
	/* 0x3097: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_309c:
	/* 0x309c: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_309f:
	/* 0x309f: je     37f3 <generic_sleepable_preload+0x37f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14323ULL;
	}
x86_l_30a5:
	/* 0x30a5: jmp    3806 <generic_sleepable_preload+0x3806> */
	return 14342ULL;
x86_l_30aa:
	/* 0x30aa: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_30ad:
	/* 0x30ad: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_30b2:
	/* 0x30b2: je     31b9 <generic_sleepable_preload+0x31b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12729ULL;
	}
x86_l_30b8:
	/* 0x30b8: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_30bb:
	/* 0x30bb: jne    320d <generic_sleepable_preload+0x320d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12813ULL;
	}
x86_l_30c1:
	/* 0x30c1: mov    edx,DWORD PTR [rdi+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_30c7:
	/* 0x30c7: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_30cd:
	/* 0x30cd: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30d0:
	/* 0x30d0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30d5:
	/* 0x30d5: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_30d8:
	/* 0x30d8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_30dd:
	/* 0x30dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30e2:
	/* 0x30e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30e4:
	/* 0x30e4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30e6:
	/* 0x30e6: jne    3208 <generic_sleepable_preload+0x3208> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12808ULL;
	}
x86_l_30ec:
	/* 0x30ec: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_30f1:
	/* 0x30f1: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_30f6:
	/* 0x30f6: add    rdx,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 560ULL);
x86_l_30fd:
	/* 0x30fd: jmp    3dd7 <generic_sleepable_preload+0x3dd7> */
	return 15831ULL;
	return 12546ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12546ULL: goto x86_l_3102;
	case 12549ULL: goto x86_l_3105;
	case 12554ULL: goto x86_l_310a;
	case 12556ULL: goto x86_l_310c;
	case 12559ULL: goto x86_l_310f;
	case 12565ULL: goto x86_l_3115;
	case 12567ULL: goto x86_l_3117;
	case 12573ULL: goto x86_l_311d;
	case 12576ULL: goto x86_l_3120;
	case 12579ULL: goto x86_l_3123;
	case 12585ULL: goto x86_l_3129;
	case 12590ULL: goto x86_l_312e;
	case 12593ULL: goto x86_l_3131;
	case 12599ULL: goto x86_l_3137;
	case 12607ULL: goto x86_l_313f;
	case 12610ULL: goto x86_l_3142;
	case 12616ULL: goto x86_l_3148;
	case 12621ULL: goto x86_l_314d;
	case 12624ULL: goto x86_l_3150;
	case 12630ULL: goto x86_l_3156;
	case 12635ULL: goto x86_l_315b;
	case 12638ULL: goto x86_l_315e;
	case 12644ULL: goto x86_l_3164;
	case 12652ULL: goto x86_l_316c;
	case 12655ULL: goto x86_l_316f;
	case 12661ULL: goto x86_l_3175;
	case 12666ULL: goto x86_l_317a;
	case 12669ULL: goto x86_l_317d;
	case 12675ULL: goto x86_l_3183;
	case 12680ULL: goto x86_l_3188;
	case 12687ULL: goto x86_l_318f;
	case 12692ULL: goto x86_l_3194;
	case 12699ULL: goto x86_l_319b;
	case 12706ULL: goto x86_l_31a2;
	case 12713ULL: goto x86_l_31a9;
	case 12718ULL: goto x86_l_31ae;
	case 12723ULL: goto x86_l_31b3;
	case 12727ULL: goto x86_l_31b7;
	case 12729ULL: goto x86_l_31b9;
	case 12735ULL: goto x86_l_31bf;
	case 12741ULL: goto x86_l_31c5;
	case 12744ULL: goto x86_l_31c8;
	case 12749ULL: goto x86_l_31cd;
	case 12752ULL: goto x86_l_31d0;
	case 12757ULL: goto x86_l_31d5;
	case 12762ULL: goto x86_l_31da;
	case 12764ULL: goto x86_l_31dc;
	case 12766ULL: goto x86_l_31de;
	case 12768ULL: goto x86_l_31e0;
	case 12774ULL: goto x86_l_31e6;
	case 12780ULL: goto x86_l_31ec;
	case 12783ULL: goto x86_l_31ef;
	case 12788ULL: goto x86_l_31f4;
	case 12793ULL: goto x86_l_31f9;
	case 12798ULL: goto x86_l_31fe;
	case 12800ULL: goto x86_l_3200;
	case 12802ULL: goto x86_l_3202;
	case 12808ULL: goto x86_l_3208;
	case 12810ULL: goto x86_l_320a;
	case 12813ULL: goto x86_l_320d;
	case 12818ULL: goto x86_l_3212;
	case 12820ULL: goto x86_l_3214;
	case 12823ULL: goto x86_l_3217;
	case 12831ULL: goto x86_l_321f;
	case 12837ULL: goto x86_l_3225;
	case 12844ULL: goto x86_l_322c;
	case 12847ULL: goto x86_l_322f;
	case 12853ULL: goto x86_l_3235;
	case 12856ULL: goto x86_l_3238;
	case 12861ULL: goto x86_l_323d;
	case 12868ULL: goto x86_l_3244;
	case 12870ULL: goto x86_l_3246;
	case 12876ULL: goto x86_l_324c;
	case 12879ULL: goto x86_l_324f;
	case 12881ULL: goto x86_l_3251;
	case 12886ULL: goto x86_l_3256;
	case 12891ULL: goto x86_l_325b;
	case 12896ULL: goto x86_l_3260;
	case 12901ULL: goto x86_l_3265;
	case 12903ULL: goto x86_l_3267;
	case 12908ULL: goto x86_l_326c;
	case 12910ULL: goto x86_l_326e;
	case 12916ULL: goto x86_l_3274;
	case 12924ULL: goto x86_l_327c;
	case 12930ULL: goto x86_l_3282;
	case 12936ULL: goto x86_l_3288;
	case 12941ULL: goto x86_l_328d;
	case 12949ULL: goto x86_l_3295;
	case 12951ULL: goto x86_l_3297;
	case 12956ULL: goto x86_l_329c;
	case 12961ULL: goto x86_l_32a1;
	case 12966ULL: goto x86_l_32a6;
	case 12971ULL: goto x86_l_32ab;
	case 12973ULL: goto x86_l_32ad;
	case 12978ULL: goto x86_l_32b2;
	case 12980ULL: goto x86_l_32b4;
	case 12986ULL: goto x86_l_32ba;
	case 12994ULL: goto x86_l_32c2;
	case 13000ULL: goto x86_l_32c8;
	case 13006ULL: goto x86_l_32ce;
	case 13011ULL: goto x86_l_32d3;
	case 13019ULL: goto x86_l_32db;
	case 13021ULL: goto x86_l_32dd;
	case 13026ULL: goto x86_l_32e2;
	case 13031ULL: goto x86_l_32e7;
	case 13036ULL: goto x86_l_32ec;
	case 13041ULL: goto x86_l_32f1;
	case 13043ULL: goto x86_l_32f3;
	case 13048ULL: goto x86_l_32f8;
	case 13050ULL: goto x86_l_32fa;
	case 13056ULL: goto x86_l_3300;
	case 13064ULL: goto x86_l_3308;
	case 13070ULL: goto x86_l_330e;
	case 13076ULL: goto x86_l_3314;
	case 13081ULL: goto x86_l_3319;
	case 13089ULL: goto x86_l_3321;
	case 13091ULL: goto x86_l_3323;
	case 13096ULL: goto x86_l_3328;
	case 13101ULL: goto x86_l_332d;
	case 13106ULL: goto x86_l_3332;
	case 13111ULL: goto x86_l_3337;
	case 13113ULL: goto x86_l_3339;
	case 13118ULL: goto x86_l_333e;
	case 13120ULL: goto x86_l_3340;
	case 13126ULL: goto x86_l_3346;
	case 13134ULL: goto x86_l_334e;
	case 13140ULL: goto x86_l_3354;
	case 13146ULL: goto x86_l_335a;
	case 13151ULL: goto x86_l_335f;
	case 13159ULL: goto x86_l_3367;
	case 13161ULL: goto x86_l_3369;
	case 13166ULL: goto x86_l_336e;
	case 13171ULL: goto x86_l_3373;
	case 13176ULL: goto x86_l_3378;
	case 13181ULL: goto x86_l_337d;
	case 13183ULL: goto x86_l_337f;
	case 13188ULL: goto x86_l_3384;
	case 13190ULL: goto x86_l_3386;
	case 13196ULL: goto x86_l_338c;
	case 13204ULL: goto x86_l_3394;
	case 13210ULL: goto x86_l_339a;
	case 13216ULL: goto x86_l_33a0;
	case 13221ULL: goto x86_l_33a5;
	case 13229ULL: goto x86_l_33ad;
	case 13231ULL: goto x86_l_33af;
	case 13236ULL: goto x86_l_33b4;
	case 13241ULL: goto x86_l_33b9;
	case 13246ULL: goto x86_l_33be;
	case 13251ULL: goto x86_l_33c3;
	case 13253ULL: goto x86_l_33c5;
	case 13258ULL: goto x86_l_33ca;
	case 13260ULL: goto x86_l_33cc;
	case 13266ULL: goto x86_l_33d2;
	case 13274ULL: goto x86_l_33da;
	case 13280ULL: goto x86_l_33e0;
	case 13286ULL: goto x86_l_33e6;
	case 13291ULL: goto x86_l_33eb;
	case 13299ULL: goto x86_l_33f3;
	case 13301ULL: goto x86_l_33f5;
	case 13306ULL: goto x86_l_33fa;
	case 13311ULL: goto x86_l_33ff;
	case 13316ULL: goto x86_l_3404;
	case 13321ULL: goto x86_l_3409;
	case 13323ULL: goto x86_l_340b;
	case 13325ULL: goto x86_l_340d;
	case 13331ULL: goto x86_l_3413;
	case 13336ULL: goto x86_l_3418;
	case 13344ULL: goto x86_l_3420;
	case 13350ULL: goto x86_l_3426;
	case 13356ULL: goto x86_l_342c;
	case 13361ULL: goto x86_l_3431;
	case 13369ULL: goto x86_l_3439;
	case 13371ULL: goto x86_l_343b;
	case 13376ULL: goto x86_l_3440;
	case 13381ULL: goto x86_l_3445;
	case 13386ULL: goto x86_l_344a;
	case 13391ULL: goto x86_l_344f;
	case 13393ULL: goto x86_l_3451;
	case 13395ULL: goto x86_l_3453;
	case 13401ULL: goto x86_l_3459;
	case 13406ULL: goto x86_l_345e;
	case 13414ULL: goto x86_l_3466;
	case 13420ULL: goto x86_l_346c;
	case 13426ULL: goto x86_l_3472;
	case 13431ULL: goto x86_l_3477;
	case 13439ULL: goto x86_l_347f;
	case 13441ULL: goto x86_l_3481;
	case 13446ULL: goto x86_l_3486;
	case 13451ULL: goto x86_l_348b;
	case 13456ULL: goto x86_l_3490;
	case 13461ULL: goto x86_l_3495;
	case 13463ULL: goto x86_l_3497;
	case 13465ULL: goto x86_l_3499;
	case 13471ULL: goto x86_l_349f;
	case 13476ULL: goto x86_l_34a4;
	case 13484ULL: goto x86_l_34ac;
	case 13490ULL: goto x86_l_34b2;
	case 13496ULL: goto x86_l_34b8;
	case 13501ULL: goto x86_l_34bd;
	case 13509ULL: goto x86_l_34c5;
	case 13515ULL: goto x86_l_34cb;
	case 13520ULL: goto x86_l_34d0;
	case 13525ULL: goto x86_l_34d5;
	case 13528ULL: goto x86_l_34d8;
	case 13530ULL: goto x86_l_34da;
	case 13535ULL: goto x86_l_34df;
	case 13540ULL: goto x86_l_34e4;
	case 13545ULL: goto x86_l_34e9;
	case 13550ULL: goto x86_l_34ee;
	case 13552ULL: goto x86_l_34f0;
	case 13557ULL: goto x86_l_34f5;
	case 13559ULL: goto x86_l_34f7;
	case 13565ULL: goto x86_l_34fd;
	case 13573ULL: goto x86_l_3505;
	case 13579ULL: goto x86_l_350b;
	case 13585ULL: goto x86_l_3511;
	case 13590ULL: goto x86_l_3516;
	case 13598ULL: goto x86_l_351e;
	case 13600ULL: goto x86_l_3520;
	case 13605ULL: goto x86_l_3525;
	case 13610ULL: goto x86_l_352a;
	case 13615ULL: goto x86_l_352f;
	case 13620ULL: goto x86_l_3534;
	case 13622ULL: goto x86_l_3536;
	case 13627ULL: goto x86_l_353b;
	case 13629ULL: goto x86_l_353d;
	case 13635ULL: goto x86_l_3543;
	case 13643ULL: goto x86_l_354b;
	case 13649ULL: goto x86_l_3551;
	case 13655ULL: goto x86_l_3557;
	case 13660ULL: goto x86_l_355c;
	case 13668ULL: goto x86_l_3564;
	case 13670ULL: goto x86_l_3566;
	case 13675ULL: goto x86_l_356b;
	case 13680ULL: goto x86_l_3570;
	case 13685ULL: goto x86_l_3575;
	case 13690ULL: goto x86_l_357a;
	case 13692ULL: goto x86_l_357c;
	case 13697ULL: goto x86_l_3581;
	case 13699ULL: goto x86_l_3583;
	case 13705ULL: goto x86_l_3589;
	case 13713ULL: goto x86_l_3591;
	case 13719ULL: goto x86_l_3597;
	case 13725ULL: goto x86_l_359d;
	case 13730ULL: goto x86_l_35a2;
	case 13738ULL: goto x86_l_35aa;
	case 13740ULL: goto x86_l_35ac;
	case 13745ULL: goto x86_l_35b1;
	case 13750ULL: goto x86_l_35b6;
	case 13755ULL: goto x86_l_35bb;
	case 13760ULL: goto x86_l_35c0;
	case 13762ULL: goto x86_l_35c2;
	case 13767ULL: goto x86_l_35c7;
	case 13769ULL: goto x86_l_35c9;
	case 13775ULL: goto x86_l_35cf;
	case 13783ULL: goto x86_l_35d7;
	case 13789ULL: goto x86_l_35dd;
	case 13795ULL: goto x86_l_35e3;
	case 13800ULL: goto x86_l_35e8;
	case 13808ULL: goto x86_l_35f0;
	case 13810ULL: goto x86_l_35f2;
	case 13815ULL: goto x86_l_35f7;
	case 13820ULL: goto x86_l_35fc;
	case 13825ULL: goto x86_l_3601;
	case 13830ULL: goto x86_l_3606;
	case 13832ULL: goto x86_l_3608;
	case 13837ULL: goto x86_l_360d;
	case 13839ULL: goto x86_l_360f;
	case 13845ULL: goto x86_l_3615;
	case 13853ULL: goto x86_l_361d;
	case 13859ULL: goto x86_l_3623;
	case 13865ULL: goto x86_l_3629;
	case 13870ULL: goto x86_l_362e;
	case 13878ULL: goto x86_l_3636;
	case 13880ULL: goto x86_l_3638;
	case 13885ULL: goto x86_l_363d;
	case 13890ULL: goto x86_l_3642;
	case 13895ULL: goto x86_l_3647;
	case 13900ULL: goto x86_l_364c;
	case 13902ULL: goto x86_l_364e;
	case 13907ULL: goto x86_l_3653;
	case 13909ULL: goto x86_l_3655;
	case 13915ULL: goto x86_l_365b;
	case 13923ULL: goto x86_l_3663;
	case 13929ULL: goto x86_l_3669;
	case 13935ULL: goto x86_l_366f;
	case 13940ULL: goto x86_l_3674;
	case 13948ULL: goto x86_l_367c;
	case 13950ULL: goto x86_l_367e;
	case 13955ULL: goto x86_l_3683;
	case 13960ULL: goto x86_l_3688;
	case 13965ULL: goto x86_l_368d;
	case 13970ULL: goto x86_l_3692;
	case 13972ULL: goto x86_l_3694;
	case 13974ULL: goto x86_l_3696;
	case 13980ULL: goto x86_l_369c;
	case 13985ULL: goto x86_l_36a1;
	case 13993ULL: goto x86_l_36a9;
	case 13999ULL: goto x86_l_36af;
	case 14002ULL: goto x86_l_36b2;
	case 14008ULL: goto x86_l_36b8;
	case 14013ULL: goto x86_l_36bd;
	case 14021ULL: goto x86_l_36c5;
	case 14023ULL: goto x86_l_36c7;
	case 14028ULL: goto x86_l_36cc;
	case 14033ULL: goto x86_l_36d1;
	case 14038ULL: goto x86_l_36d6;
	case 14043ULL: goto x86_l_36db;
	case 14045ULL: goto x86_l_36dd;
	case 14047ULL: goto x86_l_36df;
	case 14053ULL: goto x86_l_36e5;
	case 14058ULL: goto x86_l_36ea;
	case 14066ULL: goto x86_l_36f2;
	case 14069ULL: goto x86_l_36f5;
	case 14075ULL: goto x86_l_36fb;
	case 14081ULL: goto x86_l_3701;
	case 14086ULL: goto x86_l_3706;
	case 14094ULL: goto x86_l_370e;
	case 14096ULL: goto x86_l_3710;
	case 14101ULL: goto x86_l_3715;
	case 14106ULL: goto x86_l_371a;
	case 14111ULL: goto x86_l_371f;
	case 14116ULL: goto x86_l_3724;
	case 14118ULL: goto x86_l_3726;
	case 14120ULL: goto x86_l_3728;
	case 14126ULL: goto x86_l_372e;
	case 14131ULL: goto x86_l_3733;
	case 14139ULL: goto x86_l_373b;
	case 14142ULL: goto x86_l_373e;
	case 14148ULL: goto x86_l_3744;
	case 14154ULL: goto x86_l_374a;
	case 14159ULL: goto x86_l_374f;
	case 14167ULL: goto x86_l_3757;
	case 14173ULL: goto x86_l_375d;
	case 14178ULL: goto x86_l_3762;
	case 14183ULL: goto x86_l_3767;
	case 14188ULL: goto x86_l_376c;
	case 14193ULL: goto x86_l_3771;
	case 14195ULL: goto x86_l_3773;
	case 14200ULL: goto x86_l_3778;
	case 14202ULL: goto x86_l_377a;
	case 14208ULL: goto x86_l_3780;
	case 14213ULL: goto x86_l_3785;
	case 14218ULL: goto x86_l_378a;
	case 14223ULL: goto x86_l_378f;
	case 14228ULL: goto x86_l_3794;
	case 14236ULL: goto x86_l_379c;
	case 14239ULL: goto x86_l_379f;
	case 14241ULL: goto x86_l_37a1;
	case 14246ULL: goto x86_l_37a6;
	case 14249ULL: goto x86_l_37a9;
	case 14251ULL: goto x86_l_37ab;
	case 14253ULL: goto x86_l_37ad;
	case 14258ULL: goto x86_l_37b2;
	case 14261ULL: goto x86_l_37b5;
	case 14263ULL: goto x86_l_37b7;
	case 14268ULL: goto x86_l_37bc;
	case 14271ULL: goto x86_l_37bf;
	case 14273ULL: goto x86_l_37c1;
	case 14275ULL: goto x86_l_37c3;
	case 14283ULL: goto x86_l_37cb;
	case 14286ULL: goto x86_l_37ce;
	case 14288ULL: goto x86_l_37d0;
	case 14293ULL: goto x86_l_37d5;
	case 14296ULL: goto x86_l_37d8;
	case 14298ULL: goto x86_l_37da;
	case 14300ULL: goto x86_l_37dc;
	case 14308ULL: goto x86_l_37e4;
	case 14311ULL: goto x86_l_37e7;
	case 14313ULL: goto x86_l_37e9;
	case 14318ULL: goto x86_l_37ee;
	case 14321ULL: goto x86_l_37f1;
	case 14323ULL: goto x86_l_37f3;
	case 14326ULL: goto x86_l_37f6;
	case 14328ULL: goto x86_l_37f8;
	case 14330ULL: goto x86_l_37fa;
	case 14335ULL: goto x86_l_37ff;
	case 14337ULL: goto x86_l_3801;
	case 14342ULL: goto x86_l_3806;
	case 14347ULL: goto x86_l_380b;
	case 14350ULL: goto x86_l_380e;
	case 14352ULL: goto x86_l_3810;
	case 14355ULL: goto x86_l_3813;
	case 14363ULL: goto x86_l_381b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3102:
	/* 0x3102: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3105:
	/* 0x3105: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_310a:
	/* 0x310a: jg     315b <generic_sleepable_preload+0x315b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_315b;
	}
x86_l_310c:
	/* 0x310c: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_310f:
	/* 0x310f: jg     37ad <generic_sleepable_preload+0x37ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_37ad;
	}
x86_l_3115:
	/* 0x3115: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_3117:
	/* 0x3117: je     37f3 <generic_sleepable_preload+0x37f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37f3;
	}
x86_l_311d:
	/* 0x311d: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_3120:
	/* 0x3120: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3123:
	/* 0x3123: je     37f3 <generic_sleepable_preload+0x37f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37f3;
	}
x86_l_3129:
	/* 0x3129: jmp    3806 <generic_sleepable_preload+0x3806> */
	goto x86_l_3806;
x86_l_312e:
	/* 0x312e: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3131:
	/* 0x3131: jg     3794 <generic_sleepable_preload+0x3794> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3794;
	}
x86_l_3137:
	/* 0x3137: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_313f:
	/* 0x313f: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3142:
	/* 0x3142: je     37f3 <generic_sleepable_preload+0x37f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37f3;
	}
x86_l_3148:
	/* 0x3148: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_314d:
	/* 0x314d: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3150:
	/* 0x3150: je     37f3 <generic_sleepable_preload+0x37f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37f3;
	}
x86_l_3156:
	/* 0x3156: jmp    3806 <generic_sleepable_preload+0x3806> */
	goto x86_l_3806;
x86_l_315b:
	/* 0x315b: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_315e:
	/* 0x315e: jg     37c3 <generic_sleepable_preload+0x37c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_37c3;
	}
x86_l_3164:
	/* 0x3164: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_316c:
	/* 0x316c: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_316f:
	/* 0x316f: je     37f3 <generic_sleepable_preload+0x37f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37f3;
	}
x86_l_3175:
	/* 0x3175: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_317a:
	/* 0x317a: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_317d:
	/* 0x317d: je     37f3 <generic_sleepable_preload+0x37f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37f3;
	}
x86_l_3183:
	/* 0x3183: jmp    3806 <generic_sleepable_preload+0x3806> */
	goto x86_l_3806;
x86_l_3188:
	/* 0x3188: mov    rax,QWORD PTR [rdi+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_318f:
	/* 0x318f: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3194:
	/* 0x3194: movzx  eax,BYTE PTR [rdi+0x240] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 576ULL);
x86_l_319b:
	/* 0x319b: shlx   rcx,QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((32ULL << 32) | X86_ALU_SHL));
x86_l_31a2:
	/* 0x31a2: cmp    BYTE PTR [rdi+0x242],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2482491097088ULL);
x86_l_31a9:
	/* 0x31a9: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_31ae:
	/* 0x31ae: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_31b3:
	/* 0x31b3: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_31b7:
	/* 0x31b7: jmp    320d <generic_sleepable_preload+0x320d> */
	goto x86_l_320d;
x86_l_31b9:
	/* 0x31b9: mov    edx,DWORD PTR [rdi+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_31bf:
	/* 0x31bf: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_31c5:
	/* 0x31c5: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_31c8:
	/* 0x31c8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31cd:
	/* 0x31cd: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_31d0:
	/* 0x31d0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31d5:
	/* 0x31d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31da:
	/* 0x31da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31dc:
	/* 0x31dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31de:
	/* 0x31de: jne    3208 <generic_sleepable_preload+0x3208> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3208;
	}
x86_l_31e0:
	/* 0x31e0: mov    edx,DWORD PTR [rbx+0x23c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_31e6:
	/* 0x31e6: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_31ec:
	/* 0x31ec: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_31ef:
	/* 0x31ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31f4:
	/* 0x31f4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31f9:
	/* 0x31f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31fe:
	/* 0x31fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3200:
	/* 0x3200: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3202:
	/* 0x3202: je     3db5 <generic_sleepable_preload+0x3db5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15797ULL;
	}
x86_l_3208:
	/* 0x3208: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_320a:
	/* 0x320a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_320d:
	/* 0x320d: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3212:
	/* 0x3212: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3214:
	/* 0x3214: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_3217:
	/* 0x3217: cmp    WORD PTR [rdi+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_321f:
	/* 0x321f: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_3225:
	/* 0x3225: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_322c:
	/* 0x322c: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_322f:
	/* 0x322f: mov    edx,DWORD PTR [rdi+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_3235:
	/* 0x3235: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3238:
	/* 0x3238: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_323d:
	/* 0x323d: movzx  eax,WORD PTR [rdi+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_3244:
	/* 0x3244: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_3246:
	/* 0x3246: je     34d5 <generic_sleepable_preload+0x34d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34d5;
	}
x86_l_324c:
	/* 0x324c: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_324f:
	/* 0x324f: je     3274 <generic_sleepable_preload+0x3274> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3274;
	}
x86_l_3251:
	/* 0x3251: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3256:
	/* 0x3256: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_325b:
	/* 0x325b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3260:
	/* 0x3260: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3265:
	/* 0x3265: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3267:
	/* 0x3267: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_326c:
	/* 0x326c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_326e:
	/* 0x326e: js     378a <generic_sleepable_preload+0x378a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_378a;
	}
x86_l_3274:
	/* 0x3274: cmp    WORD PTR [rdi+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_327c:
	/* 0x327c: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_3282:
	/* 0x3282: mov    eax,DWORD PTR [rdi+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_3288:
	/* 0x3288: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_328d:
	/* 0x328d: cmp    WORD PTR [rdi+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_3295:
	/* 0x3295: je     32ba <generic_sleepable_preload+0x32ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32ba;
	}
x86_l_3297:
	/* 0x3297: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_329c:
	/* 0x329c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32a1:
	/* 0x32a1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32a6:
	/* 0x32a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32ab:
	/* 0x32ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32ad:
	/* 0x32ad: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_32b2:
	/* 0x32b2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32b4:
	/* 0x32b4: js     3d90 <generic_sleepable_preload+0x3d90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15760ULL;
	}
x86_l_32ba:
	/* 0x32ba: cmp    WORD PTR [rdi+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_32c2:
	/* 0x32c2: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_32c8:
	/* 0x32c8: mov    eax,DWORD PTR [rdi+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_32ce:
	/* 0x32ce: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_32d3:
	/* 0x32d3: cmp    WORD PTR [rdi+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_32db:
	/* 0x32db: je     3300 <generic_sleepable_preload+0x3300> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3300;
	}
x86_l_32dd:
	/* 0x32dd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_32e2:
	/* 0x32e2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32e7:
	/* 0x32e7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32ec:
	/* 0x32ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32f1:
	/* 0x32f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32f3:
	/* 0x32f3: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_32f8:
	/* 0x32f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32fa:
	/* 0x32fa: js     3da4 <generic_sleepable_preload+0x3da4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15780ULL;
	}
x86_l_3300:
	/* 0x3300: cmp    WORD PTR [rdi+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_3308:
	/* 0x3308: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_330e:
	/* 0x330e: mov    eax,DWORD PTR [rdi+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_3314:
	/* 0x3314: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3319:
	/* 0x3319: cmp    WORD PTR [rdi+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_3321:
	/* 0x3321: je     3346 <generic_sleepable_preload+0x3346> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3346;
	}
x86_l_3323:
	/* 0x3323: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3328:
	/* 0x3328: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_332d:
	/* 0x332d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3332:
	/* 0x3332: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3337:
	/* 0x3337: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3339:
	/* 0x3339: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_333e:
	/* 0x333e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3340:
	/* 0x3340: js     3df5 <generic_sleepable_preload+0x3df5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15861ULL;
	}
x86_l_3346:
	/* 0x3346: cmp    WORD PTR [rdi+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_334e:
	/* 0x334e: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_3354:
	/* 0x3354: mov    eax,DWORD PTR [rdi+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_335a:
	/* 0x335a: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_335f:
	/* 0x335f: cmp    WORD PTR [rdi+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_3367:
	/* 0x3367: je     338c <generic_sleepable_preload+0x338c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_338c;
	}
x86_l_3369:
	/* 0x3369: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_336e:
	/* 0x336e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3373:
	/* 0x3373: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3378:
	/* 0x3378: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_337d:
	/* 0x337d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_337f:
	/* 0x337f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3384:
	/* 0x3384: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3386:
	/* 0x3386: js     3e06 <generic_sleepable_preload+0x3e06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15878ULL;
	}
x86_l_338c:
	/* 0x338c: cmp    WORD PTR [rdi+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_3394:
	/* 0x3394: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_339a:
	/* 0x339a: mov    eax,DWORD PTR [rdi+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_33a0:
	/* 0x33a0: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_33a5:
	/* 0x33a5: cmp    WORD PTR [rdi+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_33ad:
	/* 0x33ad: je     33d2 <generic_sleepable_preload+0x33d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33d2;
	}
x86_l_33af:
	/* 0x33af: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_33b4:
	/* 0x33b4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33b9:
	/* 0x33b9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33be:
	/* 0x33be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33c3:
	/* 0x33c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33c5:
	/* 0x33c5: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33ca:
	/* 0x33ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33cc:
	/* 0x33cc: js     3e17 <generic_sleepable_preload+0x3e17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15895ULL;
	}
x86_l_33d2:
	/* 0x33d2: cmp    WORD PTR [rdi+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_33da:
	/* 0x33da: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_33e0:
	/* 0x33e0: mov    eax,DWORD PTR [rdi+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_33e6:
	/* 0x33e6: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_33eb:
	/* 0x33eb: cmp    WORD PTR [rdi+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_33f3:
	/* 0x33f3: je     3413 <generic_sleepable_preload+0x3413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3413;
	}
x86_l_33f5:
	/* 0x33f5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_33fa:
	/* 0x33fa: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33ff:
	/* 0x33ff: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3404:
	/* 0x3404: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3409:
	/* 0x3409: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_340b:
	/* 0x340b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_340d:
	/* 0x340d: js     5dce <generic_sleepable_preload+0x5dce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24014ULL;
	}
x86_l_3413:
	/* 0x3413: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3418:
	/* 0x3418: cmp    WORD PTR [rdi+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_3420:
	/* 0x3420: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_3426:
	/* 0x3426: mov    eax,DWORD PTR [rdi+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_342c:
	/* 0x342c: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3431:
	/* 0x3431: cmp    WORD PTR [rdi+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_3439:
	/* 0x3439: je     3459 <generic_sleepable_preload+0x3459> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3459;
	}
x86_l_343b:
	/* 0x343b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3440:
	/* 0x3440: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3445:
	/* 0x3445: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_344a:
	/* 0x344a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_344f:
	/* 0x344f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3451:
	/* 0x3451: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3453:
	/* 0x3453: js     5f48 <generic_sleepable_preload+0x5f48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24392ULL;
	}
x86_l_3459:
	/* 0x3459: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_345e:
	/* 0x345e: cmp    WORD PTR [rdi+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3466:
	/* 0x3466: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_346c:
	/* 0x346c: mov    eax,DWORD PTR [rdi+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3472:
	/* 0x3472: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3477:
	/* 0x3477: cmp    WORD PTR [rdi+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_347f:
	/* 0x347f: je     349f <generic_sleepable_preload+0x349f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_349f;
	}
x86_l_3481:
	/* 0x3481: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3486:
	/* 0x3486: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_348b:
	/* 0x348b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3490:
	/* 0x3490: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3495:
	/* 0x3495: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3497:
	/* 0x3497: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3499:
	/* 0x3499: js     604e <generic_sleepable_preload+0x604e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24654ULL;
	}
x86_l_349f:
	/* 0x349f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_34a4:
	/* 0x34a4: cmp    WORD PTR [rdi+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_34ac:
	/* 0x34ac: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_34b2:
	/* 0x34b2: mov    eax,DWORD PTR [rdi+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_34b8:
	/* 0x34b8: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_34bd:
	/* 0x34bd: cmp    WORD PTR [rdi+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_34c5:
	/* 0x34c5: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_34cb:
	/* 0x34cb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_34d0:
	/* 0x34d0: jmp    3762 <generic_sleepable_preload+0x3762> */
	goto x86_l_3762;
x86_l_34d5:
	/* 0x34d5: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_34d8:
	/* 0x34d8: je     34fd <generic_sleepable_preload+0x34fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34fd;
	}
x86_l_34da:
	/* 0x34da: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_34df:
	/* 0x34df: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34e4:
	/* 0x34e4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34e9:
	/* 0x34e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34ee:
	/* 0x34ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34f0:
	/* 0x34f0: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_34f5:
	/* 0x34f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34f7:
	/* 0x34f7: js     378a <generic_sleepable_preload+0x378a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_378a;
	}
x86_l_34fd:
	/* 0x34fd: cmp    WORD PTR [rdi+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_3505:
	/* 0x3505: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_350b:
	/* 0x350b: mov    eax,DWORD PTR [rdi+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_3511:
	/* 0x3511: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3516:
	/* 0x3516: cmp    WORD PTR [rdi+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_351e:
	/* 0x351e: je     3543 <generic_sleepable_preload+0x3543> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3543;
	}
x86_l_3520:
	/* 0x3520: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3525:
	/* 0x3525: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_352a:
	/* 0x352a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_352f:
	/* 0x352f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3534:
	/* 0x3534: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3536:
	/* 0x3536: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_353b:
	/* 0x353b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_353d:
	/* 0x353d: js     3d90 <generic_sleepable_preload+0x3d90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15760ULL;
	}
x86_l_3543:
	/* 0x3543: cmp    WORD PTR [rdi+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_354b:
	/* 0x354b: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_3551:
	/* 0x3551: mov    eax,DWORD PTR [rdi+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3557:
	/* 0x3557: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_355c:
	/* 0x355c: cmp    WORD PTR [rdi+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_3564:
	/* 0x3564: je     3589 <generic_sleepable_preload+0x3589> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3589;
	}
x86_l_3566:
	/* 0x3566: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_356b:
	/* 0x356b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3570:
	/* 0x3570: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3575:
	/* 0x3575: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_357a:
	/* 0x357a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_357c:
	/* 0x357c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3581:
	/* 0x3581: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3583:
	/* 0x3583: js     3da4 <generic_sleepable_preload+0x3da4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15780ULL;
	}
x86_l_3589:
	/* 0x3589: cmp    WORD PTR [rdi+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_3591:
	/* 0x3591: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_3597:
	/* 0x3597: mov    eax,DWORD PTR [rdi+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_359d:
	/* 0x359d: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_35a2:
	/* 0x35a2: cmp    WORD PTR [rdi+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_35aa:
	/* 0x35aa: je     35cf <generic_sleepable_preload+0x35cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35cf;
	}
x86_l_35ac:
	/* 0x35ac: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_35b1:
	/* 0x35b1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35b6:
	/* 0x35b6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35bb:
	/* 0x35bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35c0:
	/* 0x35c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35c2:
	/* 0x35c2: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_35c7:
	/* 0x35c7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35c9:
	/* 0x35c9: js     3df5 <generic_sleepable_preload+0x3df5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15861ULL;
	}
x86_l_35cf:
	/* 0x35cf: cmp    WORD PTR [rdi+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_35d7:
	/* 0x35d7: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_35dd:
	/* 0x35dd: mov    eax,DWORD PTR [rdi+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_35e3:
	/* 0x35e3: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_35e8:
	/* 0x35e8: cmp    WORD PTR [rdi+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_35f0:
	/* 0x35f0: je     3615 <generic_sleepable_preload+0x3615> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3615;
	}
x86_l_35f2:
	/* 0x35f2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_35f7:
	/* 0x35f7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35fc:
	/* 0x35fc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3601:
	/* 0x3601: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3606:
	/* 0x3606: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3608:
	/* 0x3608: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_360d:
	/* 0x360d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_360f:
	/* 0x360f: js     3e06 <generic_sleepable_preload+0x3e06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15878ULL;
	}
x86_l_3615:
	/* 0x3615: cmp    WORD PTR [rdi+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_361d:
	/* 0x361d: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_3623:
	/* 0x3623: mov    eax,DWORD PTR [rdi+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_3629:
	/* 0x3629: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_362e:
	/* 0x362e: cmp    WORD PTR [rdi+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_3636:
	/* 0x3636: je     365b <generic_sleepable_preload+0x365b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_365b;
	}
x86_l_3638:
	/* 0x3638: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_363d:
	/* 0x363d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3642:
	/* 0x3642: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3647:
	/* 0x3647: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_364c:
	/* 0x364c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_364e:
	/* 0x364e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3653:
	/* 0x3653: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3655:
	/* 0x3655: js     3e17 <generic_sleepable_preload+0x3e17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15895ULL;
	}
x86_l_365b:
	/* 0x365b: cmp    WORD PTR [rdi+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_3663:
	/* 0x3663: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_3669:
	/* 0x3669: mov    eax,DWORD PTR [rdi+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_366f:
	/* 0x366f: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3674:
	/* 0x3674: cmp    WORD PTR [rdi+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_367c:
	/* 0x367c: je     369c <generic_sleepable_preload+0x369c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_369c;
	}
x86_l_367e:
	/* 0x367e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3683:
	/* 0x3683: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3688:
	/* 0x3688: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_368d:
	/* 0x368d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3692:
	/* 0x3692: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3694:
	/* 0x3694: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3696:
	/* 0x3696: js     5dce <generic_sleepable_preload+0x5dce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24014ULL;
	}
x86_l_369c:
	/* 0x369c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_36a1:
	/* 0x36a1: cmp    WORD PTR [rdi+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_36a9:
	/* 0x36a9: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_36af:
	/* 0x36af: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_36b2:
	/* 0x36b2: mov    eax,DWORD PTR [rdi+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_36b8:
	/* 0x36b8: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_36bd:
	/* 0x36bd: cmp    WORD PTR [rdi+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_36c5:
	/* 0x36c5: je     36e5 <generic_sleepable_preload+0x36e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36e5;
	}
x86_l_36c7:
	/* 0x36c7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_36cc:
	/* 0x36cc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36d1:
	/* 0x36d1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36d6:
	/* 0x36d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36db:
	/* 0x36db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36dd:
	/* 0x36dd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36df:
	/* 0x36df: js     5fd8 <generic_sleepable_preload+0x5fd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24536ULL;
	}
x86_l_36e5:
	/* 0x36e5: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_36ea:
	/* 0x36ea: cmp    WORD PTR [rdi+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_36f2:
	/* 0x36f2: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_36f5:
	/* 0x36f5: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_36fb:
	/* 0x36fb: mov    eax,DWORD PTR [rdi+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3701:
	/* 0x3701: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3706:
	/* 0x3706: cmp    WORD PTR [rdi+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_370e:
	/* 0x370e: je     372e <generic_sleepable_preload+0x372e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_372e;
	}
x86_l_3710:
	/* 0x3710: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3715:
	/* 0x3715: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_371a:
	/* 0x371a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_371f:
	/* 0x371f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3724:
	/* 0x3724: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3726:
	/* 0x3726: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3728:
	/* 0x3728: js     60d4 <generic_sleepable_preload+0x60d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24788ULL;
	}
x86_l_372e:
	/* 0x372e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3733:
	/* 0x3733: cmp    WORD PTR [rdi+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_373b:
	/* 0x373b: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_373e:
	/* 0x373e: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_3744:
	/* 0x3744: mov    eax,DWORD PTR [rdi+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_374a:
	/* 0x374a: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_374f:
	/* 0x374f: cmp    WORD PTR [rdi+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_3757:
	/* 0x3757: je     3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15903ULL;
	}
x86_l_375d:
	/* 0x375d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3762:
	/* 0x3762: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3767:
	/* 0x3767: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_376c:
	/* 0x376c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3771:
	/* 0x3771: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3773:
	/* 0x3773: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3778:
	/* 0x3778: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_377a:
	/* 0x377a: jns    3e1f <generic_sleepable_preload+0x3e1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 15903ULL;
	}
x86_l_3780:
	/* 0x3780: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_3785:
	/* 0x3785: jmp    3e1c <generic_sleepable_preload+0x3e1c> */
	return 15900ULL;
x86_l_378a:
	/* 0x378a: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_378f:
	/* 0x378f: jmp    3e1c <generic_sleepable_preload+0x3e1c> */
	return 15900ULL;
x86_l_3794:
	/* 0x3794: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_379c:
	/* 0x379c: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_379f:
	/* 0x379f: je     37f3 <generic_sleepable_preload+0x37f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37f3;
	}
x86_l_37a1:
	/* 0x37a1: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_37a6:
	/* 0x37a6: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_37a9:
	/* 0x37a9: je     37f3 <generic_sleepable_preload+0x37f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37f3;
	}
x86_l_37ab:
	/* 0x37ab: jmp    3806 <generic_sleepable_preload+0x3806> */
	goto x86_l_3806;
x86_l_37ad:
	/* 0x37ad: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_37b2:
	/* 0x37b2: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_37b5:
	/* 0x37b5: je     37f3 <generic_sleepable_preload+0x37f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37f3;
	}
x86_l_37b7:
	/* 0x37b7: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_37bc:
	/* 0x37bc: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_37bf:
	/* 0x37bf: je     37f3 <generic_sleepable_preload+0x37f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37f3;
	}
x86_l_37c1:
	/* 0x37c1: jmp    3806 <generic_sleepable_preload+0x3806> */
	goto x86_l_3806;
x86_l_37c3:
	/* 0x37c3: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_37cb:
	/* 0x37cb: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_37ce:
	/* 0x37ce: je     37f3 <generic_sleepable_preload+0x37f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37f3;
	}
x86_l_37d0:
	/* 0x37d0: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_37d5:
	/* 0x37d5: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_37d8:
	/* 0x37d8: je     37f3 <generic_sleepable_preload+0x37f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37f3;
	}
x86_l_37da:
	/* 0x37da: jmp    3806 <generic_sleepable_preload+0x3806> */
	goto x86_l_3806;
x86_l_37dc:
	/* 0x37dc: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_37e4:
	/* 0x37e4: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_37e7:
	/* 0x37e7: je     37f3 <generic_sleepable_preload+0x37f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37f3;
	}
x86_l_37e9:
	/* 0x37e9: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_37ee:
	/* 0x37ee: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_37f1:
	/* 0x37f1: jne    3806 <generic_sleepable_preload+0x3806> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3806;
	}
x86_l_37f3:
	/* 0x37f3: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_37f6:
	/* 0x37f6: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_37f8:
	/* 0x37f8: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_37fa:
	/* 0x37fa: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_37ff:
	/* 0x37ff: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3801:
	/* 0x3801: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_3806:
	/* 0x3806: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_380b:
	/* 0x380b: mov    ebx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_380e:
	/* 0x380e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3810:
	/* 0x3810: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_3813:
	/* 0x3813: cmp    WORD PTR [rdi+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_381b:
	/* 0x381b: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16038ULL;
	}
	return 14369ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14369ULL: goto x86_l_3821;
	case 14376ULL: goto x86_l_3828;
	case 14379ULL: goto x86_l_382b;
	case 14385ULL: goto x86_l_3831;
	case 14388ULL: goto x86_l_3834;
	case 14393ULL: goto x86_l_3839;
	case 14400ULL: goto x86_l_3840;
	case 14402ULL: goto x86_l_3842;
	case 14408ULL: goto x86_l_3848;
	case 14411ULL: goto x86_l_384b;
	case 14413ULL: goto x86_l_384d;
	case 14418ULL: goto x86_l_3852;
	case 14423ULL: goto x86_l_3857;
	case 14428ULL: goto x86_l_385c;
	case 14433ULL: goto x86_l_3861;
	case 14435ULL: goto x86_l_3863;
	case 14440ULL: goto x86_l_3868;
	case 14442ULL: goto x86_l_386a;
	case 14448ULL: goto x86_l_3870;
	case 14456ULL: goto x86_l_3878;
	case 14462ULL: goto x86_l_387e;
	case 14468ULL: goto x86_l_3884;
	case 14473ULL: goto x86_l_3889;
	case 14481ULL: goto x86_l_3891;
	case 14483ULL: goto x86_l_3893;
	case 14488ULL: goto x86_l_3898;
	case 14493ULL: goto x86_l_389d;
	case 14498ULL: goto x86_l_38a2;
	case 14503ULL: goto x86_l_38a7;
	case 14505ULL: goto x86_l_38a9;
	case 14510ULL: goto x86_l_38ae;
	case 14512ULL: goto x86_l_38b0;
	case 14518ULL: goto x86_l_38b6;
	case 14526ULL: goto x86_l_38be;
	case 14532ULL: goto x86_l_38c4;
	case 14538ULL: goto x86_l_38ca;
	case 14543ULL: goto x86_l_38cf;
	case 14551ULL: goto x86_l_38d7;
	case 14553ULL: goto x86_l_38d9;
	case 14558ULL: goto x86_l_38de;
	case 14563ULL: goto x86_l_38e3;
	case 14568ULL: goto x86_l_38e8;
	case 14573ULL: goto x86_l_38ed;
	case 14575ULL: goto x86_l_38ef;
	case 14580ULL: goto x86_l_38f4;
	case 14582ULL: goto x86_l_38f6;
	case 14588ULL: goto x86_l_38fc;
	case 14596ULL: goto x86_l_3904;
	case 14602ULL: goto x86_l_390a;
	case 14608ULL: goto x86_l_3910;
	case 14613ULL: goto x86_l_3915;
	case 14621ULL: goto x86_l_391d;
	case 14623ULL: goto x86_l_391f;
	case 14628ULL: goto x86_l_3924;
	case 14633ULL: goto x86_l_3929;
	case 14638ULL: goto x86_l_392e;
	case 14643ULL: goto x86_l_3933;
	case 14645ULL: goto x86_l_3935;
	case 14650ULL: goto x86_l_393a;
	case 14652ULL: goto x86_l_393c;
	case 14658ULL: goto x86_l_3942;
	case 14666ULL: goto x86_l_394a;
	case 14672ULL: goto x86_l_3950;
	case 14678ULL: goto x86_l_3956;
	case 14683ULL: goto x86_l_395b;
	case 14691ULL: goto x86_l_3963;
	case 14693ULL: goto x86_l_3965;
	case 14698ULL: goto x86_l_396a;
	case 14703ULL: goto x86_l_396f;
	case 14708ULL: goto x86_l_3974;
	case 14713ULL: goto x86_l_3979;
	case 14715ULL: goto x86_l_397b;
	case 14720ULL: goto x86_l_3980;
	case 14722ULL: goto x86_l_3982;
	case 14728ULL: goto x86_l_3988;
	case 14736ULL: goto x86_l_3990;
	case 14742ULL: goto x86_l_3996;
	case 14748ULL: goto x86_l_399c;
	case 14753ULL: goto x86_l_39a1;
	case 14761ULL: goto x86_l_39a9;
	case 14763ULL: goto x86_l_39ab;
	case 14768ULL: goto x86_l_39b0;
	case 14773ULL: goto x86_l_39b5;
	case 14778ULL: goto x86_l_39ba;
	case 14783ULL: goto x86_l_39bf;
	case 14785ULL: goto x86_l_39c1;
	case 14790ULL: goto x86_l_39c6;
	case 14792ULL: goto x86_l_39c8;
	case 14798ULL: goto x86_l_39ce;
	case 14806ULL: goto x86_l_39d6;
	case 14812ULL: goto x86_l_39dc;
	case 14818ULL: goto x86_l_39e2;
	case 14823ULL: goto x86_l_39e7;
	case 14831ULL: goto x86_l_39ef;
	case 14833ULL: goto x86_l_39f1;
	case 14838ULL: goto x86_l_39f6;
	case 14843ULL: goto x86_l_39fb;
	case 14848ULL: goto x86_l_3a00;
	case 14853ULL: goto x86_l_3a05;
	case 14855ULL: goto x86_l_3a07;
	case 14857ULL: goto x86_l_3a09;
	case 14863ULL: goto x86_l_3a0f;
	case 14868ULL: goto x86_l_3a14;
	case 14876ULL: goto x86_l_3a1c;
	case 14882ULL: goto x86_l_3a22;
	case 14888ULL: goto x86_l_3a28;
	case 14893ULL: goto x86_l_3a2d;
	case 14901ULL: goto x86_l_3a35;
	case 14903ULL: goto x86_l_3a37;
	case 14908ULL: goto x86_l_3a3c;
	case 14913ULL: goto x86_l_3a41;
	case 14918ULL: goto x86_l_3a46;
	case 14923ULL: goto x86_l_3a4b;
	case 14925ULL: goto x86_l_3a4d;
	case 14927ULL: goto x86_l_3a4f;
	case 14933ULL: goto x86_l_3a55;
	case 14938ULL: goto x86_l_3a5a;
	case 14946ULL: goto x86_l_3a62;
	case 14952ULL: goto x86_l_3a68;
	case 14958ULL: goto x86_l_3a6e;
	case 14963ULL: goto x86_l_3a73;
	case 14971ULL: goto x86_l_3a7b;
	case 14973ULL: goto x86_l_3a7d;
	case 14978ULL: goto x86_l_3a82;
	case 14983ULL: goto x86_l_3a87;
	case 14988ULL: goto x86_l_3a8c;
	case 14993ULL: goto x86_l_3a91;
	case 14995ULL: goto x86_l_3a93;
	case 14997ULL: goto x86_l_3a95;
	case 15003ULL: goto x86_l_3a9b;
	case 15008ULL: goto x86_l_3aa0;
	case 15016ULL: goto x86_l_3aa8;
	case 15022ULL: goto x86_l_3aae;
	case 15028ULL: goto x86_l_3ab4;
	case 15033ULL: goto x86_l_3ab9;
	case 15041ULL: goto x86_l_3ac1;
	case 15047ULL: goto x86_l_3ac7;
	case 15052ULL: goto x86_l_3acc;
	case 15057ULL: goto x86_l_3ad1;
	case 15060ULL: goto x86_l_3ad4;
	case 15062ULL: goto x86_l_3ad6;
	case 15067ULL: goto x86_l_3adb;
	case 15072ULL: goto x86_l_3ae0;
	case 15077ULL: goto x86_l_3ae5;
	case 15082ULL: goto x86_l_3aea;
	case 15084ULL: goto x86_l_3aec;
	case 15089ULL: goto x86_l_3af1;
	case 15091ULL: goto x86_l_3af3;
	case 15097ULL: goto x86_l_3af9;
	case 15105ULL: goto x86_l_3b01;
	case 15111ULL: goto x86_l_3b07;
	case 15117ULL: goto x86_l_3b0d;
	case 15122ULL: goto x86_l_3b12;
	case 15130ULL: goto x86_l_3b1a;
	case 15132ULL: goto x86_l_3b1c;
	case 15137ULL: goto x86_l_3b21;
	case 15142ULL: goto x86_l_3b26;
	case 15147ULL: goto x86_l_3b2b;
	case 15152ULL: goto x86_l_3b30;
	case 15154ULL: goto x86_l_3b32;
	case 15159ULL: goto x86_l_3b37;
	case 15161ULL: goto x86_l_3b39;
	case 15167ULL: goto x86_l_3b3f;
	case 15175ULL: goto x86_l_3b47;
	case 15181ULL: goto x86_l_3b4d;
	case 15187ULL: goto x86_l_3b53;
	case 15192ULL: goto x86_l_3b58;
	case 15200ULL: goto x86_l_3b60;
	case 15202ULL: goto x86_l_3b62;
	case 15207ULL: goto x86_l_3b67;
	case 15212ULL: goto x86_l_3b6c;
	case 15217ULL: goto x86_l_3b71;
	case 15222ULL: goto x86_l_3b76;
	case 15224ULL: goto x86_l_3b78;
	case 15229ULL: goto x86_l_3b7d;
	case 15231ULL: goto x86_l_3b7f;
	case 15237ULL: goto x86_l_3b85;
	case 15245ULL: goto x86_l_3b8d;
	case 15251ULL: goto x86_l_3b93;
	case 15257ULL: goto x86_l_3b99;
	case 15262ULL: goto x86_l_3b9e;
	case 15270ULL: goto x86_l_3ba6;
	case 15272ULL: goto x86_l_3ba8;
	case 15277ULL: goto x86_l_3bad;
	case 15282ULL: goto x86_l_3bb2;
	case 15287ULL: goto x86_l_3bb7;
	case 15292ULL: goto x86_l_3bbc;
	case 15294ULL: goto x86_l_3bbe;
	case 15299ULL: goto x86_l_3bc3;
	case 15301ULL: goto x86_l_3bc5;
	case 15307ULL: goto x86_l_3bcb;
	case 15315ULL: goto x86_l_3bd3;
	case 15321ULL: goto x86_l_3bd9;
	case 15327ULL: goto x86_l_3bdf;
	case 15332ULL: goto x86_l_3be4;
	case 15340ULL: goto x86_l_3bec;
	case 15342ULL: goto x86_l_3bee;
	case 15347ULL: goto x86_l_3bf3;
	case 15352ULL: goto x86_l_3bf8;
	case 15357ULL: goto x86_l_3bfd;
	case 15362ULL: goto x86_l_3c02;
	case 15364ULL: goto x86_l_3c04;
	case 15369ULL: goto x86_l_3c09;
	case 15371ULL: goto x86_l_3c0b;
	case 15377ULL: goto x86_l_3c11;
	case 15385ULL: goto x86_l_3c19;
	case 15391ULL: goto x86_l_3c1f;
	case 15397ULL: goto x86_l_3c25;
	case 15402ULL: goto x86_l_3c2a;
	case 15410ULL: goto x86_l_3c32;
	case 15412ULL: goto x86_l_3c34;
	case 15417ULL: goto x86_l_3c39;
	case 15422ULL: goto x86_l_3c3e;
	case 15427ULL: goto x86_l_3c43;
	case 15432ULL: goto x86_l_3c48;
	case 15434ULL: goto x86_l_3c4a;
	case 15439ULL: goto x86_l_3c4f;
	case 15441ULL: goto x86_l_3c51;
	case 15447ULL: goto x86_l_3c57;
	case 15455ULL: goto x86_l_3c5f;
	case 15461ULL: goto x86_l_3c65;
	case 15467ULL: goto x86_l_3c6b;
	case 15472ULL: goto x86_l_3c70;
	case 15480ULL: goto x86_l_3c78;
	case 15482ULL: goto x86_l_3c7a;
	case 15487ULL: goto x86_l_3c7f;
	case 15492ULL: goto x86_l_3c84;
	case 15497ULL: goto x86_l_3c89;
	case 15502ULL: goto x86_l_3c8e;
	case 15504ULL: goto x86_l_3c90;
	case 15506ULL: goto x86_l_3c92;
	case 15512ULL: goto x86_l_3c98;
	case 15517ULL: goto x86_l_3c9d;
	case 15525ULL: goto x86_l_3ca5;
	case 15531ULL: goto x86_l_3cab;
	case 15534ULL: goto x86_l_3cae;
	case 15540ULL: goto x86_l_3cb4;
	case 15545ULL: goto x86_l_3cb9;
	case 15553ULL: goto x86_l_3cc1;
	case 15555ULL: goto x86_l_3cc3;
	case 15560ULL: goto x86_l_3cc8;
	case 15565ULL: goto x86_l_3ccd;
	case 15570ULL: goto x86_l_3cd2;
	case 15575ULL: goto x86_l_3cd7;
	case 15577ULL: goto x86_l_3cd9;
	case 15579ULL: goto x86_l_3cdb;
	case 15585ULL: goto x86_l_3ce1;
	case 15590ULL: goto x86_l_3ce6;
	case 15598ULL: goto x86_l_3cee;
	case 15601ULL: goto x86_l_3cf1;
	case 15607ULL: goto x86_l_3cf7;
	case 15613ULL: goto x86_l_3cfd;
	case 15618ULL: goto x86_l_3d02;
	case 15626ULL: goto x86_l_3d0a;
	case 15628ULL: goto x86_l_3d0c;
	case 15633ULL: goto x86_l_3d11;
	case 15638ULL: goto x86_l_3d16;
	case 15643ULL: goto x86_l_3d1b;
	case 15648ULL: goto x86_l_3d20;
	case 15650ULL: goto x86_l_3d22;
	case 15652ULL: goto x86_l_3d24;
	case 15658ULL: goto x86_l_3d2a;
	case 15663ULL: goto x86_l_3d2f;
	case 15671ULL: goto x86_l_3d37;
	case 15674ULL: goto x86_l_3d3a;
	case 15680ULL: goto x86_l_3d40;
	case 15686ULL: goto x86_l_3d46;
	case 15691ULL: goto x86_l_3d4b;
	case 15699ULL: goto x86_l_3d53;
	case 15705ULL: goto x86_l_3d59;
	case 15710ULL: goto x86_l_3d5e;
	case 15715ULL: goto x86_l_3d63;
	case 15720ULL: goto x86_l_3d68;
	case 15725ULL: goto x86_l_3d6d;
	case 15727ULL: goto x86_l_3d6f;
	case 15732ULL: goto x86_l_3d74;
	case 15734ULL: goto x86_l_3d76;
	case 15740ULL: goto x86_l_3d7c;
	case 15745ULL: goto x86_l_3d81;
	case 15750ULL: goto x86_l_3d86;
	case 15755ULL: goto x86_l_3d8b;
	case 15760ULL: goto x86_l_3d90;
	case 15765ULL: goto x86_l_3d95;
	case 15770ULL: goto x86_l_3d9a;
	case 15775ULL: goto x86_l_3d9f;
	case 15780ULL: goto x86_l_3da4;
	case 15785ULL: goto x86_l_3da9;
	case 15787ULL: goto x86_l_3dab;
	case 15792ULL: goto x86_l_3db0;
	case 15797ULL: goto x86_l_3db5;
	case 15802ULL: goto x86_l_3dba;
	case 15809ULL: goto x86_l_3dc1;
	case 15816ULL: goto x86_l_3dc8;
	case 15823ULL: goto x86_l_3dcf;
	case 15828ULL: goto x86_l_3dd4;
	case 15831ULL: goto x86_l_3dd7;
	case 15836ULL: goto x86_l_3ddc;
	case 15841ULL: goto x86_l_3de1;
	case 15843ULL: goto x86_l_3de3;
	case 15845ULL: goto x86_l_3de5;
	case 15848ULL: goto x86_l_3de8;
	case 15854ULL: goto x86_l_3dee;
	case 15856ULL: goto x86_l_3df0;
	case 15861ULL: goto x86_l_3df5;
	case 15866ULL: goto x86_l_3dfa;
	case 15868ULL: goto x86_l_3dfc;
	case 15873ULL: goto x86_l_3e01;
	case 15878ULL: goto x86_l_3e06;
	case 15883ULL: goto x86_l_3e0b;
	case 15885ULL: goto x86_l_3e0d;
	case 15890ULL: goto x86_l_3e12;
	case 15895ULL: goto x86_l_3e17;
	case 15900ULL: goto x86_l_3e1c;
	case 15903ULL: goto x86_l_3e1f;
	case 15906ULL: goto x86_l_3e22;
	case 15911ULL: goto x86_l_3e27;
	case 15916ULL: goto x86_l_3e2c;
	case 15921ULL: goto x86_l_3e31;
	case 15924ULL: goto x86_l_3e34;
	case 15926ULL: goto x86_l_3e36;
	case 15929ULL: goto x86_l_3e39;
	case 15935ULL: goto x86_l_3e3f;
	case 15940ULL: goto x86_l_3e44;
	case 15945ULL: goto x86_l_3e49;
	case 15947ULL: goto x86_l_3e4b;
	case 15952ULL: goto x86_l_3e50;
	case 15960ULL: goto x86_l_3e58;
	case 15965ULL: goto x86_l_3e5d;
	case 15972ULL: goto x86_l_3e64;
	case 15977ULL: goto x86_l_3e69;
	case 15979ULL: goto x86_l_3e6b;
	case 15982ULL: goto x86_l_3e6e;
	case 15988ULL: goto x86_l_3e74;
	case 15994ULL: goto x86_l_3e7a;
	case 15997ULL: goto x86_l_3e7d;
	case 16004ULL: goto x86_l_3e84;
	case 16009ULL: goto x86_l_3e89;
	case 16012ULL: goto x86_l_3e8c;
	case 16015ULL: goto x86_l_3e8f;
	case 16018ULL: goto x86_l_3e92;
	case 16020ULL: goto x86_l_3e94;
	case 16023ULL: goto x86_l_3e97;
	case 16028ULL: goto x86_l_3e9c;
	case 16030ULL: goto x86_l_3e9e;
	case 16035ULL: goto x86_l_3ea3;
	case 16038ULL: goto x86_l_3ea6;
	case 16041ULL: goto x86_l_3ea9;
	case 16047ULL: goto x86_l_3eaf;
	case 16052ULL: goto x86_l_3eb4;
	case 16057ULL: goto x86_l_3eb9;
	case 16059ULL: goto x86_l_3ebb;
	case 16064ULL: goto x86_l_3ec0;
	case 16072ULL: goto x86_l_3ec8;
	case 16077ULL: goto x86_l_3ecd;
	case 16084ULL: goto x86_l_3ed4;
	case 16089ULL: goto x86_l_3ed9;
	case 16091ULL: goto x86_l_3edb;
	case 16094ULL: goto x86_l_3ede;
	case 16096ULL: goto x86_l_3ee0;
	case 16102ULL: goto x86_l_3ee6;
	case 16105ULL: goto x86_l_3ee9;
	case 16112ULL: goto x86_l_3ef0;
	case 16117ULL: goto x86_l_3ef5;
	case 16120ULL: goto x86_l_3ef8;
	case 16123ULL: goto x86_l_3efb;
	case 16126ULL: goto x86_l_3efe;
	case 16128ULL: goto x86_l_3f00;
	case 16131ULL: goto x86_l_3f03;
	case 16136ULL: goto x86_l_3f08;
	case 16139ULL: goto x86_l_3f0b;
	case 16142ULL: goto x86_l_3f0e;
	case 16145ULL: goto x86_l_3f11;
	case 16147ULL: goto x86_l_3f13;
	case 16150ULL: goto x86_l_3f16;
	case 16152ULL: goto x86_l_3f18;
	case 16155ULL: goto x86_l_3f1b;
	case 16157ULL: goto x86_l_3f1d;
	case 16160ULL: goto x86_l_3f20;
	case 16164ULL: goto x86_l_3f24;
	case 16169ULL: goto x86_l_3f29;
	case 16172ULL: goto x86_l_3f2c;
	case 16174ULL: goto x86_l_3f2e;
	case 16177ULL: goto x86_l_3f31;
	case 16182ULL: goto x86_l_3f36;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3821:
	/* 0x3821: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3828:
	/* 0x3828: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_382b:
	/* 0x382b: mov    edx,DWORD PTR [rdi+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_3831:
	/* 0x3831: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3834:
	/* 0x3834: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3839:
	/* 0x3839: movzx  eax,WORD PTR [rdi+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_3840:
	/* 0x3840: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_3842:
	/* 0x3842: je     3ad1 <generic_sleepable_preload+0x3ad1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ad1;
	}
x86_l_3848:
	/* 0x3848: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_384b:
	/* 0x384b: je     3870 <generic_sleepable_preload+0x3870> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3870;
	}
x86_l_384d:
	/* 0x384d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3852:
	/* 0x3852: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3857:
	/* 0x3857: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_385c:
	/* 0x385c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3861:
	/* 0x3861: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3863:
	/* 0x3863: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3868:
	/* 0x3868: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_386a:
	/* 0x386a: js     3d86 <generic_sleepable_preload+0x3d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3d86;
	}
x86_l_3870:
	/* 0x3870: cmp    WORD PTR [rdi+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_3878:
	/* 0x3878: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_387e:
	/* 0x387e: mov    eax,DWORD PTR [rdi+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_3884:
	/* 0x3884: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3889:
	/* 0x3889: cmp    WORD PTR [rdi+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_3891:
	/* 0x3891: je     38b6 <generic_sleepable_preload+0x38b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38b6;
	}
x86_l_3893:
	/* 0x3893: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3898:
	/* 0x3898: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_389d:
	/* 0x389d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38a2:
	/* 0x38a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38a7:
	/* 0x38a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38a9:
	/* 0x38a9: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_38ae:
	/* 0x38ae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38b0:
	/* 0x38b0: js     3d9a <generic_sleepable_preload+0x3d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3d9a;
	}
x86_l_38b6:
	/* 0x38b6: cmp    WORD PTR [rdi+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_38be:
	/* 0x38be: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_38c4:
	/* 0x38c4: mov    eax,DWORD PTR [rdi+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_38ca:
	/* 0x38ca: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_38cf:
	/* 0x38cf: cmp    WORD PTR [rdi+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_38d7:
	/* 0x38d7: je     38fc <generic_sleepable_preload+0x38fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38fc;
	}
x86_l_38d9:
	/* 0x38d9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_38de:
	/* 0x38de: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38e3:
	/* 0x38e3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38e8:
	/* 0x38e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38ed:
	/* 0x38ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38ef:
	/* 0x38ef: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_38f4:
	/* 0x38f4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38f6:
	/* 0x38f6: js     3dab <generic_sleepable_preload+0x3dab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3dab;
	}
x86_l_38fc:
	/* 0x38fc: cmp    WORD PTR [rdi+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_3904:
	/* 0x3904: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_390a:
	/* 0x390a: mov    eax,DWORD PTR [rdi+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_3910:
	/* 0x3910: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3915:
	/* 0x3915: cmp    WORD PTR [rdi+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_391d:
	/* 0x391d: je     3942 <generic_sleepable_preload+0x3942> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3942;
	}
x86_l_391f:
	/* 0x391f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3924:
	/* 0x3924: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3929:
	/* 0x3929: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_392e:
	/* 0x392e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3933:
	/* 0x3933: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3935:
	/* 0x3935: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_393a:
	/* 0x393a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_393c:
	/* 0x393c: js     3dfc <generic_sleepable_preload+0x3dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3dfc;
	}
x86_l_3942:
	/* 0x3942: cmp    WORD PTR [rdi+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_394a:
	/* 0x394a: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_3950:
	/* 0x3950: mov    eax,DWORD PTR [rdi+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_3956:
	/* 0x3956: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_395b:
	/* 0x395b: cmp    WORD PTR [rdi+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_3963:
	/* 0x3963: je     3988 <generic_sleepable_preload+0x3988> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3988;
	}
x86_l_3965:
	/* 0x3965: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_396a:
	/* 0x396a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_396f:
	/* 0x396f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3974:
	/* 0x3974: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3979:
	/* 0x3979: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_397b:
	/* 0x397b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3980:
	/* 0x3980: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3982:
	/* 0x3982: js     3e0d <generic_sleepable_preload+0x3e0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3e0d;
	}
x86_l_3988:
	/* 0x3988: cmp    WORD PTR [rdi+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_3990:
	/* 0x3990: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_3996:
	/* 0x3996: mov    eax,DWORD PTR [rdi+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_399c:
	/* 0x399c: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_39a1:
	/* 0x39a1: cmp    WORD PTR [rdi+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_39a9:
	/* 0x39a9: je     39ce <generic_sleepable_preload+0x39ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39ce;
	}
x86_l_39ab:
	/* 0x39ab: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_39b0:
	/* 0x39b0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39b5:
	/* 0x39b5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39ba:
	/* 0x39ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39bf:
	/* 0x39bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39c1:
	/* 0x39c1: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_39c6:
	/* 0x39c6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39c8:
	/* 0x39c8: js     3e9e <generic_sleepable_preload+0x3e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3e9e;
	}
x86_l_39ce:
	/* 0x39ce: cmp    WORD PTR [rdi+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_39d6:
	/* 0x39d6: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_39dc:
	/* 0x39dc: mov    eax,DWORD PTR [rdi+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_39e2:
	/* 0x39e2: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_39e7:
	/* 0x39e7: cmp    WORD PTR [rdi+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_39ef:
	/* 0x39ef: je     3a0f <generic_sleepable_preload+0x3a0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a0f;
	}
x86_l_39f1:
	/* 0x39f1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_39f6:
	/* 0x39f6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39fb:
	/* 0x39fb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a00:
	/* 0x3a00: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a05:
	/* 0x3a05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a07:
	/* 0x3a07: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a09:
	/* 0x3a09: js     5de0 <generic_sleepable_preload+0x5de0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24032ULL;
	}
x86_l_3a0f:
	/* 0x3a0f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a14:
	/* 0x3a14: cmp    WORD PTR [rdi+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_3a1c:
	/* 0x3a1c: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_3a22:
	/* 0x3a22: mov    eax,DWORD PTR [rdi+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_3a28:
	/* 0x3a28: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3a2d:
	/* 0x3a2d: cmp    WORD PTR [rdi+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_3a35:
	/* 0x3a35: je     3a55 <generic_sleepable_preload+0x3a55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a55;
	}
x86_l_3a37:
	/* 0x3a37: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a3c:
	/* 0x3a3c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a41:
	/* 0x3a41: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a46:
	/* 0x3a46: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a4b:
	/* 0x3a4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a4d:
	/* 0x3a4d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a4f:
	/* 0x3a4f: js     5f5a <generic_sleepable_preload+0x5f5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24410ULL;
	}
x86_l_3a55:
	/* 0x3a55: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a5a:
	/* 0x3a5a: cmp    WORD PTR [rdi+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3a62:
	/* 0x3a62: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_3a68:
	/* 0x3a68: mov    eax,DWORD PTR [rdi+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3a6e:
	/* 0x3a6e: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3a73:
	/* 0x3a73: cmp    WORD PTR [rdi+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3a7b:
	/* 0x3a7b: je     3a9b <generic_sleepable_preload+0x3a9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a9b;
	}
x86_l_3a7d:
	/* 0x3a7d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a82:
	/* 0x3a82: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a87:
	/* 0x3a87: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a8c:
	/* 0x3a8c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a91:
	/* 0x3a91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a93:
	/* 0x3a93: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a95:
	/* 0x3a95: js     6058 <generic_sleepable_preload+0x6058> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24664ULL;
	}
x86_l_3a9b:
	/* 0x3a9b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3aa0:
	/* 0x3aa0: cmp    WORD PTR [rdi+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_3aa8:
	/* 0x3aa8: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_3aae:
	/* 0x3aae: mov    eax,DWORD PTR [rdi+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_3ab4:
	/* 0x3ab4: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3ab9:
	/* 0x3ab9: cmp    WORD PTR [rdi+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_3ac1:
	/* 0x3ac1: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_3ac7:
	/* 0x3ac7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3acc:
	/* 0x3acc: jmp    3d5e <generic_sleepable_preload+0x3d5e> */
	goto x86_l_3d5e;
x86_l_3ad1:
	/* 0x3ad1: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3ad4:
	/* 0x3ad4: je     3af9 <generic_sleepable_preload+0x3af9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3af9;
	}
x86_l_3ad6:
	/* 0x3ad6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3adb:
	/* 0x3adb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ae0:
	/* 0x3ae0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ae5:
	/* 0x3ae5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3aea:
	/* 0x3aea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3aec:
	/* 0x3aec: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3af1:
	/* 0x3af1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3af3:
	/* 0x3af3: js     3d86 <generic_sleepable_preload+0x3d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3d86;
	}
x86_l_3af9:
	/* 0x3af9: cmp    WORD PTR [rdi+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_3b01:
	/* 0x3b01: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_3b07:
	/* 0x3b07: mov    eax,DWORD PTR [rdi+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_3b0d:
	/* 0x3b0d: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3b12:
	/* 0x3b12: cmp    WORD PTR [rdi+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_3b1a:
	/* 0x3b1a: je     3b3f <generic_sleepable_preload+0x3b3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b3f;
	}
x86_l_3b1c:
	/* 0x3b1c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b21:
	/* 0x3b21: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b26:
	/* 0x3b26: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b2b:
	/* 0x3b2b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b30:
	/* 0x3b30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b32:
	/* 0x3b32: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b37:
	/* 0x3b37: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b39:
	/* 0x3b39: js     3d9a <generic_sleepable_preload+0x3d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3d9a;
	}
x86_l_3b3f:
	/* 0x3b3f: cmp    WORD PTR [rdi+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_3b47:
	/* 0x3b47: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_3b4d:
	/* 0x3b4d: mov    eax,DWORD PTR [rdi+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3b53:
	/* 0x3b53: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3b58:
	/* 0x3b58: cmp    WORD PTR [rdi+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_3b60:
	/* 0x3b60: je     3b85 <generic_sleepable_preload+0x3b85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b85;
	}
x86_l_3b62:
	/* 0x3b62: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b67:
	/* 0x3b67: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b6c:
	/* 0x3b6c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b71:
	/* 0x3b71: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b76:
	/* 0x3b76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b78:
	/* 0x3b78: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b7d:
	/* 0x3b7d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b7f:
	/* 0x3b7f: js     3dab <generic_sleepable_preload+0x3dab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3dab;
	}
x86_l_3b85:
	/* 0x3b85: cmp    WORD PTR [rdi+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_3b8d:
	/* 0x3b8d: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_3b93:
	/* 0x3b93: mov    eax,DWORD PTR [rdi+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_3b99:
	/* 0x3b99: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3b9e:
	/* 0x3b9e: cmp    WORD PTR [rdi+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_3ba6:
	/* 0x3ba6: je     3bcb <generic_sleepable_preload+0x3bcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bcb;
	}
x86_l_3ba8:
	/* 0x3ba8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3bad:
	/* 0x3bad: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bb2:
	/* 0x3bb2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bb7:
	/* 0x3bb7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bbc:
	/* 0x3bbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bbe:
	/* 0x3bbe: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3bc3:
	/* 0x3bc3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3bc5:
	/* 0x3bc5: js     3dfc <generic_sleepable_preload+0x3dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3dfc;
	}
x86_l_3bcb:
	/* 0x3bcb: cmp    WORD PTR [rdi+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_3bd3:
	/* 0x3bd3: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_3bd9:
	/* 0x3bd9: mov    eax,DWORD PTR [rdi+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_3bdf:
	/* 0x3bdf: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3be4:
	/* 0x3be4: cmp    WORD PTR [rdi+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_3bec:
	/* 0x3bec: je     3c11 <generic_sleepable_preload+0x3c11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c11;
	}
x86_l_3bee:
	/* 0x3bee: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3bf3:
	/* 0x3bf3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bf8:
	/* 0x3bf8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bfd:
	/* 0x3bfd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c02:
	/* 0x3c02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c04:
	/* 0x3c04: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c09:
	/* 0x3c09: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c0b:
	/* 0x3c0b: js     3e0d <generic_sleepable_preload+0x3e0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3e0d;
	}
x86_l_3c11:
	/* 0x3c11: cmp    WORD PTR [rdi+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_3c19:
	/* 0x3c19: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_3c1f:
	/* 0x3c1f: mov    eax,DWORD PTR [rdi+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_3c25:
	/* 0x3c25: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3c2a:
	/* 0x3c2a: cmp    WORD PTR [rdi+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_3c32:
	/* 0x3c32: je     3c57 <generic_sleepable_preload+0x3c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c57;
	}
x86_l_3c34:
	/* 0x3c34: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c39:
	/* 0x3c39: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c3e:
	/* 0x3c3e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c43:
	/* 0x3c43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c48:
	/* 0x3c48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c4a:
	/* 0x3c4a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c4f:
	/* 0x3c4f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c51:
	/* 0x3c51: js     3e9e <generic_sleepable_preload+0x3e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3e9e;
	}
x86_l_3c57:
	/* 0x3c57: cmp    WORD PTR [rdi+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_3c5f:
	/* 0x3c5f: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_3c65:
	/* 0x3c65: mov    eax,DWORD PTR [rdi+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_3c6b:
	/* 0x3c6b: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3c70:
	/* 0x3c70: cmp    WORD PTR [rdi+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_3c78:
	/* 0x3c78: je     3c98 <generic_sleepable_preload+0x3c98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c98;
	}
x86_l_3c7a:
	/* 0x3c7a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c7f:
	/* 0x3c7f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c84:
	/* 0x3c84: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c89:
	/* 0x3c89: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c8e:
	/* 0x3c8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c90:
	/* 0x3c90: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c92:
	/* 0x3c92: js     5de0 <generic_sleepable_preload+0x5de0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24032ULL;
	}
x86_l_3c98:
	/* 0x3c98: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c9d:
	/* 0x3c9d: cmp    WORD PTR [rdi+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_3ca5:
	/* 0x3ca5: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_3cab:
	/* 0x3cab: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_3cae:
	/* 0x3cae: mov    eax,DWORD PTR [rdi+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_3cb4:
	/* 0x3cb4: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3cb9:
	/* 0x3cb9: cmp    WORD PTR [rdi+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_3cc1:
	/* 0x3cc1: je     3ce1 <generic_sleepable_preload+0x3ce1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ce1;
	}
x86_l_3cc3:
	/* 0x3cc3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3cc8:
	/* 0x3cc8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ccd:
	/* 0x3ccd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3cd2:
	/* 0x3cd2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cd7:
	/* 0x3cd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cd9:
	/* 0x3cd9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3cdb:
	/* 0x3cdb: js     5fe5 <generic_sleepable_preload+0x5fe5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24549ULL;
	}
x86_l_3ce1:
	/* 0x3ce1: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ce6:
	/* 0x3ce6: cmp    WORD PTR [rdi+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3cee:
	/* 0x3cee: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_3cf1:
	/* 0x3cf1: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_3cf7:
	/* 0x3cf7: mov    eax,DWORD PTR [rdi+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3cfd:
	/* 0x3cfd: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3d02:
	/* 0x3d02: cmp    WORD PTR [rdi+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3d0a:
	/* 0x3d0a: je     3d2a <generic_sleepable_preload+0x3d2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d2a;
	}
x86_l_3d0c:
	/* 0x3d0c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3d11:
	/* 0x3d11: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d16:
	/* 0x3d16: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d1b:
	/* 0x3d1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d20:
	/* 0x3d20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d22:
	/* 0x3d22: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d24:
	/* 0x3d24: js     60e9 <generic_sleepable_preload+0x60e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24809ULL;
	}
x86_l_3d2a:
	/* 0x3d2a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3d2f:
	/* 0x3d2f: cmp    WORD PTR [rdi+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_3d37:
	/* 0x3d37: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_3d3a:
	/* 0x3d3a: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_3d40:
	/* 0x3d40: mov    eax,DWORD PTR [rdi+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_3d46:
	/* 0x3d46: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3d4b:
	/* 0x3d4b: cmp    WORD PTR [rdi+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_3d53:
	/* 0x3d53: je     3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea6;
	}
x86_l_3d59:
	/* 0x3d59: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3d5e:
	/* 0x3d5e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d63:
	/* 0x3d63: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d68:
	/* 0x3d68: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d6d:
	/* 0x3d6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d6f:
	/* 0x3d6f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3d74:
	/* 0x3d74: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d76:
	/* 0x3d76: jns    3ea6 <generic_sleepable_preload+0x3ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_3ea6;
	}
x86_l_3d7c:
	/* 0x3d7c: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_3d81:
	/* 0x3d81: jmp    3ea3 <generic_sleepable_preload+0x3ea3> */
	goto x86_l_3ea3;
x86_l_3d86:
	/* 0x3d86: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_3d8b:
	/* 0x3d8b: jmp    3ea3 <generic_sleepable_preload+0x3ea3> */
	goto x86_l_3ea3;
x86_l_3d90:
	/* 0x3d90: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_3d95:
	/* 0x3d95: jmp    3e1c <generic_sleepable_preload+0x3e1c> */
	goto x86_l_3e1c;
x86_l_3d9a:
	/* 0x3d9a: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_3d9f:
	/* 0x3d9f: jmp    3ea3 <generic_sleepable_preload+0x3ea3> */
	goto x86_l_3ea3;
x86_l_3da4:
	/* 0x3da4: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_3da9:
	/* 0x3da9: jmp    3e1c <generic_sleepable_preload+0x3e1c> */
	goto x86_l_3e1c;
x86_l_3dab:
	/* 0x3dab: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_3db0:
	/* 0x3db0: jmp    3ea3 <generic_sleepable_preload+0x3ea3> */
	goto x86_l_3ea3;
x86_l_3db5:
	/* 0x3db5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3dba:
	/* 0x3dba: movzx  ecx,BYTE PTR [rbx+0x243] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 579ULL);
x86_l_3dc1:
	/* 0x3dc1: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_3dc8:
	/* 0x3dc8: mov    rdx,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_3dcf:
	/* 0x3dcf: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_3dd4:
	/* 0x3dd4: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3dd7:
	/* 0x3dd7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ddc:
	/* 0x3ddc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3de1:
	/* 0x3de1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3de3:
	/* 0x3de3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3de5:
	/* 0x3de5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3de8:
	/* 0x3de8: je     3194 <generic_sleepable_preload+0x3194> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12692ULL;
	}
x86_l_3dee:
	/* 0x3dee: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3df0:
	/* 0x3df0: jmp    320d <generic_sleepable_preload+0x320d> */
	return 12813ULL;
x86_l_3df5:
	/* 0x3df5: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_3dfa:
	/* 0x3dfa: jmp    3e1c <generic_sleepable_preload+0x3e1c> */
	goto x86_l_3e1c;
x86_l_3dfc:
	/* 0x3dfc: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_3e01:
	/* 0x3e01: jmp    3ea3 <generic_sleepable_preload+0x3ea3> */
	goto x86_l_3ea3;
x86_l_3e06:
	/* 0x3e06: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_3e0b:
	/* 0x3e0b: jmp    3e1c <generic_sleepable_preload+0x3e1c> */
	goto x86_l_3e1c;
x86_l_3e0d:
	/* 0x3e0d: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_3e12:
	/* 0x3e12: jmp    3ea3 <generic_sleepable_preload+0x3ea3> */
	goto x86_l_3ea3;
x86_l_3e17:
	/* 0x3e17: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_3e1c:
	/* 0x3e1c: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e1f:
	/* 0x3e1f: mov    ebx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3e22:
	/* 0x3e22: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e27:
	/* 0x3e27: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e2c:
	/* 0x3e2c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e31:
	/* 0x3e31: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_3e34:
	/* 0x3e34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e36:
	/* 0x3e36: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_3e39:
	/* 0x3e39: jne    3f47 <generic_sleepable_preload+0x3f47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 16199ULL;
	}
x86_l_3e3f:
	/* 0x3e3f: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e44:
	/* 0x3e44: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3e49:
	/* 0x3e49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e4b:
	/* 0x3e4b: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e50:
	/* 0x3e50: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3e58:
	/* 0x3e58: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e5d:
	/* 0x3e5d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3e64:
	/* 0x3e64: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e69:
	/* 0x3e69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e6b:
	/* 0x3e6b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e6e:
	/* 0x3e6e: je     3f47 <generic_sleepable_preload+0x3f47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16199ULL;
	}
x86_l_3e74:
	/* 0x3e74: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_3e7a:
	/* 0x3e7a: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_3e7d:
	/* 0x3e7d: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3e84:
	/* 0x3e84: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e89:
	/* 0x3e89: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3e8c:
	/* 0x3e8c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3e8f:
	/* 0x3e8f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3e92:
	/* 0x3e92: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e94:
	/* 0x3e94: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3e97:
	/* 0x3e97: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e9c:
	/* 0x3e9c: jmp    3f08 <generic_sleepable_preload+0x3f08> */
	goto x86_l_3f08;
x86_l_3e9e:
	/* 0x3e9e: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_3ea3:
	/* 0x3ea3: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ea6:
	/* 0x3ea6: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_3ea9:
	/* 0x3ea9: jne    3f4c <generic_sleepable_preload+0x3f4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 16204ULL;
	}
x86_l_3eaf:
	/* 0x3eaf: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3eb4:
	/* 0x3eb4: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3eb9:
	/* 0x3eb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ebb:
	/* 0x3ebb: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ec0:
	/* 0x3ec0: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3ec8:
	/* 0x3ec8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3ecd:
	/* 0x3ecd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3ed4:
	/* 0x3ed4: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ed9:
	/* 0x3ed9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3edb:
	/* 0x3edb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ede:
	/* 0x3ede: je     3f47 <generic_sleepable_preload+0x3f47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16199ULL;
	}
x86_l_3ee0:
	/* 0x3ee0: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_3ee6:
	/* 0x3ee6: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_3ee9:
	/* 0x3ee9: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3ef0:
	/* 0x3ef0: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ef5:
	/* 0x3ef5: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3ef8:
	/* 0x3ef8: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3efb:
	/* 0x3efb: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3efe:
	/* 0x3efe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f00:
	/* 0x3f00: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3f03:
	/* 0x3f03: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3f08:
	/* 0x3f08: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3f0b:
	/* 0x3f0b: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_3f0e:
	/* 0x3f0e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3f11:
	/* 0x3f11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f13:
	/* 0x3f13: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f16:
	/* 0x3f16: je     3f47 <generic_sleepable_preload+0x3f47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16199ULL;
	}
x86_l_3f18:
	/* 0x3f18: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_3f1b:
	/* 0x3f1b: je     3f45 <generic_sleepable_preload+0x3f45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16197ULL;
	}
x86_l_3f1d:
	/* 0x3f1d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3f20:
	/* 0x3f20: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3f24:
	/* 0x3f24: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3f29:
	/* 0x3f29: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3f2c:
	/* 0x3f2c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f2e:
	/* 0x3f2e: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3f31:
	/* 0x3f31: call   3f36 <generic_sleepable_preload+0x3f36> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_3f36:
	/* 0x3f36: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
	return 16184ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 16184ULL: goto x86_l_3f38;
	case 16187ULL: goto x86_l_3f3b;
	case 16189ULL: goto x86_l_3f3d;
	case 16194ULL: goto x86_l_3f42;
	case 16197ULL: goto x86_l_3f45;
	case 16199ULL: goto x86_l_3f47;
	case 16204ULL: goto x86_l_3f4c;
	case 16207ULL: goto x86_l_3f4f;
	case 16212ULL: goto x86_l_3f54;
	case 16218ULL: goto x86_l_3f5a;
	case 16220ULL: goto x86_l_3f5c;
	case 16222ULL: goto x86_l_3f5e;
	case 16229ULL: goto x86_l_3f65;
	case 16231ULL: goto x86_l_3f67;
	case 16234ULL: goto x86_l_3f6a;
	case 16239ULL: goto x86_l_3f6f;
	case 16245ULL: goto x86_l_3f75;
	case 16248ULL: goto x86_l_3f78;
	case 16254ULL: goto x86_l_3f7e;
	case 16257ULL: goto x86_l_3f81;
	case 16263ULL: goto x86_l_3f87;
	case 16269ULL: goto x86_l_3f8d;
	case 16275ULL: goto x86_l_3f93;
	case 16278ULL: goto x86_l_3f96;
	case 16283ULL: goto x86_l_3f9b;
	case 16288ULL: goto x86_l_3fa0;
	case 16293ULL: goto x86_l_3fa5;
	case 16295ULL: goto x86_l_3fa7;
	case 16300ULL: goto x86_l_3fac;
	case 16302ULL: goto x86_l_3fae;
	case 16308ULL: goto x86_l_3fb4;
	case 16310ULL: goto x86_l_3fb6;
	case 16315ULL: goto x86_l_3fbb;
	case 16322ULL: goto x86_l_3fc2;
	case 16329ULL: goto x86_l_3fc9;
	case 16335ULL: goto x86_l_3fcf;
	case 16337ULL: goto x86_l_3fd1;
	case 16340ULL: goto x86_l_3fd4;
	case 16346ULL: goto x86_l_3fda;
	case 16349ULL: goto x86_l_3fdd;
	case 16355ULL: goto x86_l_3fe3;
	case 16358ULL: goto x86_l_3fe6;
	case 16364ULL: goto x86_l_3fec;
	case 16372ULL: goto x86_l_3ff4;
	case 16375ULL: goto x86_l_3ff7;
	case 16381ULL: goto x86_l_3ffd;
	case 16386ULL: goto x86_l_4002;
	case 16389ULL: goto x86_l_4005;
	case 16395ULL: goto x86_l_400b;
	case 16400ULL: goto x86_l_4010;
	case 16403ULL: goto x86_l_4013;
	case 16409ULL: goto x86_l_4019;
	case 16414ULL: goto x86_l_401e;
	case 16417ULL: goto x86_l_4021;
	case 16423ULL: goto x86_l_4027;
	case 16426ULL: goto x86_l_402a;
	case 16432ULL: goto x86_l_4030;
	case 16438ULL: goto x86_l_4036;
	case 16444ULL: goto x86_l_403c;
	case 16447ULL: goto x86_l_403f;
	case 16452ULL: goto x86_l_4044;
	case 16455ULL: goto x86_l_4047;
	case 16460ULL: goto x86_l_404c;
	case 16465ULL: goto x86_l_4051;
	case 16467ULL: goto x86_l_4053;
	case 16469ULL: goto x86_l_4055;
	case 16475ULL: goto x86_l_405b;
	case 16480ULL: goto x86_l_4060;
	case 16485ULL: goto x86_l_4065;
	case 16492ULL: goto x86_l_406c;
	case 16497ULL: goto x86_l_4071;
	case 16500ULL: goto x86_l_4074;
	case 16505ULL: goto x86_l_4079;
	case 16507ULL: goto x86_l_407b;
	case 16510ULL: goto x86_l_407e;
	case 16516ULL: goto x86_l_4084;
	case 16518ULL: goto x86_l_4086;
	case 16524ULL: goto x86_l_408c;
	case 16527ULL: goto x86_l_408f;
	case 16530ULL: goto x86_l_4092;
	case 16536ULL: goto x86_l_4098;
	case 16541ULL: goto x86_l_409d;
	case 16544ULL: goto x86_l_40a0;
	case 16550ULL: goto x86_l_40a6;
	case 16558ULL: goto x86_l_40ae;
	case 16561ULL: goto x86_l_40b1;
	case 16567ULL: goto x86_l_40b7;
	case 16572ULL: goto x86_l_40bc;
	case 16575ULL: goto x86_l_40bf;
	case 16581ULL: goto x86_l_40c5;
	case 16586ULL: goto x86_l_40ca;
	case 16589ULL: goto x86_l_40cd;
	case 16595ULL: goto x86_l_40d3;
	case 16603ULL: goto x86_l_40db;
	case 16606ULL: goto x86_l_40de;
	case 16612ULL: goto x86_l_40e4;
	case 16617ULL: goto x86_l_40e9;
	case 16620ULL: goto x86_l_40ec;
	case 16626ULL: goto x86_l_40f2;
	case 16631ULL: goto x86_l_40f7;
	case 16638ULL: goto x86_l_40fe;
	case 16643ULL: goto x86_l_4103;
	case 16650ULL: goto x86_l_410a;
	case 16657ULL: goto x86_l_4111;
	case 16664ULL: goto x86_l_4118;
	case 16669ULL: goto x86_l_411d;
	case 16674ULL: goto x86_l_4122;
	case 16678ULL: goto x86_l_4126;
	case 16680ULL: goto x86_l_4128;
	case 16686ULL: goto x86_l_412e;
	case 16692ULL: goto x86_l_4134;
	case 16695ULL: goto x86_l_4137;
	case 16700ULL: goto x86_l_413c;
	case 16703ULL: goto x86_l_413f;
	case 16708ULL: goto x86_l_4144;
	case 16713ULL: goto x86_l_4149;
	case 16715ULL: goto x86_l_414b;
	case 16717ULL: goto x86_l_414d;
	case 16719ULL: goto x86_l_414f;
	case 16725ULL: goto x86_l_4155;
	case 16731ULL: goto x86_l_415b;
	case 16734ULL: goto x86_l_415e;
	case 16739ULL: goto x86_l_4163;
	case 16744ULL: goto x86_l_4168;
	case 16749ULL: goto x86_l_416d;
	case 16751ULL: goto x86_l_416f;
	case 16753ULL: goto x86_l_4171;
	case 16759ULL: goto x86_l_4177;
	case 16761ULL: goto x86_l_4179;
	case 16764ULL: goto x86_l_417c;
	case 16769ULL: goto x86_l_4181;
	case 16771ULL: goto x86_l_4183;
	case 16774ULL: goto x86_l_4186;
	case 16782ULL: goto x86_l_418e;
	case 16788ULL: goto x86_l_4194;
	case 16795ULL: goto x86_l_419b;
	case 16798ULL: goto x86_l_419e;
	case 16804ULL: goto x86_l_41a4;
	case 16807ULL: goto x86_l_41a7;
	case 16812ULL: goto x86_l_41ac;
	case 16819ULL: goto x86_l_41b3;
	case 16821ULL: goto x86_l_41b5;
	case 16827ULL: goto x86_l_41bb;
	case 16830ULL: goto x86_l_41be;
	case 16832ULL: goto x86_l_41c0;
	case 16837ULL: goto x86_l_41c5;
	case 16842ULL: goto x86_l_41ca;
	case 16847ULL: goto x86_l_41cf;
	case 16852ULL: goto x86_l_41d4;
	case 16854ULL: goto x86_l_41d6;
	case 16859ULL: goto x86_l_41db;
	case 16861ULL: goto x86_l_41dd;
	case 16867ULL: goto x86_l_41e3;
	case 16875ULL: goto x86_l_41eb;
	case 16881ULL: goto x86_l_41f1;
	case 16887ULL: goto x86_l_41f7;
	case 16892ULL: goto x86_l_41fc;
	case 16900ULL: goto x86_l_4204;
	case 16902ULL: goto x86_l_4206;
	case 16907ULL: goto x86_l_420b;
	case 16912ULL: goto x86_l_4210;
	case 16917ULL: goto x86_l_4215;
	case 16922ULL: goto x86_l_421a;
	case 16924ULL: goto x86_l_421c;
	case 16929ULL: goto x86_l_4221;
	case 16931ULL: goto x86_l_4223;
	case 16937ULL: goto x86_l_4229;
	case 16945ULL: goto x86_l_4231;
	case 16951ULL: goto x86_l_4237;
	case 16957ULL: goto x86_l_423d;
	case 16962ULL: goto x86_l_4242;
	case 16970ULL: goto x86_l_424a;
	case 16972ULL: goto x86_l_424c;
	case 16977ULL: goto x86_l_4251;
	case 16982ULL: goto x86_l_4256;
	case 16987ULL: goto x86_l_425b;
	case 16992ULL: goto x86_l_4260;
	case 16994ULL: goto x86_l_4262;
	case 16999ULL: goto x86_l_4267;
	case 17001ULL: goto x86_l_4269;
	case 17007ULL: goto x86_l_426f;
	case 17015ULL: goto x86_l_4277;
	case 17021ULL: goto x86_l_427d;
	case 17027ULL: goto x86_l_4283;
	case 17032ULL: goto x86_l_4288;
	case 17040ULL: goto x86_l_4290;
	case 17042ULL: goto x86_l_4292;
	case 17047ULL: goto x86_l_4297;
	case 17052ULL: goto x86_l_429c;
	case 17057ULL: goto x86_l_42a1;
	case 17062ULL: goto x86_l_42a6;
	case 17064ULL: goto x86_l_42a8;
	case 17069ULL: goto x86_l_42ad;
	case 17071ULL: goto x86_l_42af;
	case 17077ULL: goto x86_l_42b5;
	case 17085ULL: goto x86_l_42bd;
	case 17091ULL: goto x86_l_42c3;
	case 17097ULL: goto x86_l_42c9;
	case 17102ULL: goto x86_l_42ce;
	case 17110ULL: goto x86_l_42d6;
	case 17112ULL: goto x86_l_42d8;
	case 17117ULL: goto x86_l_42dd;
	case 17122ULL: goto x86_l_42e2;
	case 17127ULL: goto x86_l_42e7;
	case 17132ULL: goto x86_l_42ec;
	case 17134ULL: goto x86_l_42ee;
	case 17139ULL: goto x86_l_42f3;
	case 17141ULL: goto x86_l_42f5;
	case 17147ULL: goto x86_l_42fb;
	case 17155ULL: goto x86_l_4303;
	case 17161ULL: goto x86_l_4309;
	case 17167ULL: goto x86_l_430f;
	case 17172ULL: goto x86_l_4314;
	case 17180ULL: goto x86_l_431c;
	case 17182ULL: goto x86_l_431e;
	case 17187ULL: goto x86_l_4323;
	case 17192ULL: goto x86_l_4328;
	case 17197ULL: goto x86_l_432d;
	case 17202ULL: goto x86_l_4332;
	case 17204ULL: goto x86_l_4334;
	case 17209ULL: goto x86_l_4339;
	case 17211ULL: goto x86_l_433b;
	case 17217ULL: goto x86_l_4341;
	case 17225ULL: goto x86_l_4349;
	case 17231ULL: goto x86_l_434f;
	case 17237ULL: goto x86_l_4355;
	case 17242ULL: goto x86_l_435a;
	case 17250ULL: goto x86_l_4362;
	case 17252ULL: goto x86_l_4364;
	case 17257ULL: goto x86_l_4369;
	case 17262ULL: goto x86_l_436e;
	case 17267ULL: goto x86_l_4373;
	case 17272ULL: goto x86_l_4378;
	case 17274ULL: goto x86_l_437a;
	case 17276ULL: goto x86_l_437c;
	case 17282ULL: goto x86_l_4382;
	case 17287ULL: goto x86_l_4387;
	case 17295ULL: goto x86_l_438f;
	case 17301ULL: goto x86_l_4395;
	case 17307ULL: goto x86_l_439b;
	case 17312ULL: goto x86_l_43a0;
	case 17320ULL: goto x86_l_43a8;
	case 17322ULL: goto x86_l_43aa;
	case 17327ULL: goto x86_l_43af;
	case 17332ULL: goto x86_l_43b4;
	case 17337ULL: goto x86_l_43b9;
	case 17342ULL: goto x86_l_43be;
	case 17344ULL: goto x86_l_43c0;
	case 17346ULL: goto x86_l_43c2;
	case 17352ULL: goto x86_l_43c8;
	case 17357ULL: goto x86_l_43cd;
	case 17365ULL: goto x86_l_43d5;
	case 17371ULL: goto x86_l_43db;
	case 17377ULL: goto x86_l_43e1;
	case 17382ULL: goto x86_l_43e6;
	case 17390ULL: goto x86_l_43ee;
	case 17392ULL: goto x86_l_43f0;
	case 17397ULL: goto x86_l_43f5;
	case 17402ULL: goto x86_l_43fa;
	case 17407ULL: goto x86_l_43ff;
	case 17412ULL: goto x86_l_4404;
	case 17414ULL: goto x86_l_4406;
	case 17416ULL: goto x86_l_4408;
	case 17422ULL: goto x86_l_440e;
	case 17427ULL: goto x86_l_4413;
	case 17435ULL: goto x86_l_441b;
	case 17441ULL: goto x86_l_4421;
	case 17447ULL: goto x86_l_4427;
	case 17452ULL: goto x86_l_442c;
	case 17460ULL: goto x86_l_4434;
	case 17466ULL: goto x86_l_443a;
	case 17471ULL: goto x86_l_443f;
	case 17476ULL: goto x86_l_4444;
	case 17479ULL: goto x86_l_4447;
	case 17481ULL: goto x86_l_4449;
	case 17486ULL: goto x86_l_444e;
	case 17491ULL: goto x86_l_4453;
	case 17496ULL: goto x86_l_4458;
	case 17501ULL: goto x86_l_445d;
	case 17503ULL: goto x86_l_445f;
	case 17508ULL: goto x86_l_4464;
	case 17510ULL: goto x86_l_4466;
	case 17516ULL: goto x86_l_446c;
	case 17524ULL: goto x86_l_4474;
	case 17530ULL: goto x86_l_447a;
	case 17536ULL: goto x86_l_4480;
	case 17541ULL: goto x86_l_4485;
	case 17549ULL: goto x86_l_448d;
	case 17551ULL: goto x86_l_448f;
	case 17556ULL: goto x86_l_4494;
	case 17561ULL: goto x86_l_4499;
	case 17566ULL: goto x86_l_449e;
	case 17571ULL: goto x86_l_44a3;
	case 17573ULL: goto x86_l_44a5;
	case 17578ULL: goto x86_l_44aa;
	case 17580ULL: goto x86_l_44ac;
	case 17586ULL: goto x86_l_44b2;
	case 17594ULL: goto x86_l_44ba;
	case 17600ULL: goto x86_l_44c0;
	case 17606ULL: goto x86_l_44c6;
	case 17611ULL: goto x86_l_44cb;
	case 17619ULL: goto x86_l_44d3;
	case 17621ULL: goto x86_l_44d5;
	case 17626ULL: goto x86_l_44da;
	case 17631ULL: goto x86_l_44df;
	case 17636ULL: goto x86_l_44e4;
	case 17641ULL: goto x86_l_44e9;
	case 17643ULL: goto x86_l_44eb;
	case 17648ULL: goto x86_l_44f0;
	case 17650ULL: goto x86_l_44f2;
	case 17656ULL: goto x86_l_44f8;
	case 17664ULL: goto x86_l_4500;
	case 17670ULL: goto x86_l_4506;
	case 17676ULL: goto x86_l_450c;
	case 17681ULL: goto x86_l_4511;
	case 17689ULL: goto x86_l_4519;
	case 17691ULL: goto x86_l_451b;
	case 17696ULL: goto x86_l_4520;
	case 17701ULL: goto x86_l_4525;
	case 17706ULL: goto x86_l_452a;
	case 17711ULL: goto x86_l_452f;
	case 17713ULL: goto x86_l_4531;
	case 17718ULL: goto x86_l_4536;
	case 17720ULL: goto x86_l_4538;
	case 17726ULL: goto x86_l_453e;
	case 17734ULL: goto x86_l_4546;
	case 17740ULL: goto x86_l_454c;
	case 17746ULL: goto x86_l_4552;
	case 17751ULL: goto x86_l_4557;
	case 17759ULL: goto x86_l_455f;
	case 17761ULL: goto x86_l_4561;
	case 17766ULL: goto x86_l_4566;
	case 17771ULL: goto x86_l_456b;
	case 17776ULL: goto x86_l_4570;
	case 17781ULL: goto x86_l_4575;
	case 17783ULL: goto x86_l_4577;
	case 17788ULL: goto x86_l_457c;
	case 17790ULL: goto x86_l_457e;
	case 17796ULL: goto x86_l_4584;
	case 17804ULL: goto x86_l_458c;
	case 17810ULL: goto x86_l_4592;
	case 17816ULL: goto x86_l_4598;
	case 17821ULL: goto x86_l_459d;
	case 17829ULL: goto x86_l_45a5;
	case 17831ULL: goto x86_l_45a7;
	case 17836ULL: goto x86_l_45ac;
	case 17841ULL: goto x86_l_45b1;
	case 17846ULL: goto x86_l_45b6;
	case 17851ULL: goto x86_l_45bb;
	case 17853ULL: goto x86_l_45bd;
	case 17858ULL: goto x86_l_45c2;
	case 17860ULL: goto x86_l_45c4;
	case 17866ULL: goto x86_l_45ca;
	case 17874ULL: goto x86_l_45d2;
	case 17880ULL: goto x86_l_45d8;
	case 17886ULL: goto x86_l_45de;
	case 17891ULL: goto x86_l_45e3;
	case 17899ULL: goto x86_l_45eb;
	case 17901ULL: goto x86_l_45ed;
	case 17906ULL: goto x86_l_45f2;
	case 17911ULL: goto x86_l_45f7;
	case 17916ULL: goto x86_l_45fc;
	case 17921ULL: goto x86_l_4601;
	case 17923ULL: goto x86_l_4603;
	case 17925ULL: goto x86_l_4605;
	case 17931ULL: goto x86_l_460b;
	case 17936ULL: goto x86_l_4610;
	case 17944ULL: goto x86_l_4618;
	case 17950ULL: goto x86_l_461e;
	case 17953ULL: goto x86_l_4621;
	case 17959ULL: goto x86_l_4627;
	case 17964ULL: goto x86_l_462c;
	case 17972ULL: goto x86_l_4634;
	case 17974ULL: goto x86_l_4636;
	case 17979ULL: goto x86_l_463b;
	case 17984ULL: goto x86_l_4640;
	case 17989ULL: goto x86_l_4645;
	case 17994ULL: goto x86_l_464a;
	case 17996ULL: goto x86_l_464c;
	case 17998ULL: goto x86_l_464e;
	case 18004ULL: goto x86_l_4654;
	case 18009ULL: goto x86_l_4659;
	case 18017ULL: goto x86_l_4661;
	case 18020ULL: goto x86_l_4664;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3f38:
	/* 0x3f38: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_3f3b:
	/* 0x3f3b: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_3f3d:
	/* 0x3f3d: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_3f42:
	/* 0x3f42: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_3f45:
	/* 0x3f45: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f47:
	/* 0x3f47: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3f4c:
	/* 0x3f4c: mov    eax,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3f4f:
	/* 0x3f4f: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_3f54:
	/* 0x3f54: je     4ebb <generic_sleepable_preload+0x4ebb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20155ULL;
	}
x86_l_3f5a:
	/* 0x3f5a: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_3f5c:
	/* 0x3f5c: js     3fbb <generic_sleepable_preload+0x3fbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3fbb;
	}
x86_l_3f5e:
	/* 0x3f5e: movzx  ecx,BYTE PTR [rdi+0x259] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 601ULL);
x86_l_3f65:
	/* 0x3f65: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f67:
	/* 0x3f67: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3f6a:
	/* 0x3f6a: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3f6f:
	/* 0x3f6f: jg     401e <generic_sleepable_preload+0x401e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_401e;
	}
x86_l_3f75:
	/* 0x3f75: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3f78:
	/* 0x3f78: je     40f7 <generic_sleepable_preload+0x40f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40f7;
	}
x86_l_3f7e:
	/* 0x3f7e: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3f81:
	/* 0x3f81: jne    417c <generic_sleepable_preload+0x417c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_417c;
	}
x86_l_3f87:
	/* 0x3f87: mov    edx,DWORD PTR [rdi+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_3f8d:
	/* 0x3f8d: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3f93:
	/* 0x3f93: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3f96:
	/* 0x3f96: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f9b:
	/* 0x3f9b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3fa0:
	/* 0x3fa0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3fa5:
	/* 0x3fa5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fa7:
	/* 0x3fa7: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3fac:
	/* 0x3fac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3fae:
	/* 0x3fae: je     4103 <generic_sleepable_preload+0x4103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4103;
	}
x86_l_3fb4:
	/* 0x3fb4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3fb6:
	/* 0x3fb6: jmp    417c <generic_sleepable_preload+0x417c> */
	goto x86_l_417c;
x86_l_3fbb:
	/* 0x3fbb: movzx  ecx,BYTE PTR [rdi+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_3fc2:
	/* 0x3fc2: movzx  eax,WORD PTR [rdi+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_3fc9:
	/* 0x3fc9: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_3fcf:
	/* 0x3fcf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3fd1:
	/* 0x3fd1: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_3fd4:
	/* 0x3fd4: jle    4071 <generic_sleepable_preload+0x4071> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4071;
	}
x86_l_3fda:
	/* 0x3fda: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3fdd:
	/* 0x3fdd: jle    409d <generic_sleepable_preload+0x409d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_409d;
	}
x86_l_3fe3:
	/* 0x3fe3: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_3fe6:
	/* 0x3fe6: jle    474b <generic_sleepable_preload+0x474b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 18251ULL;
	}
x86_l_3fec:
	/* 0x3fec: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3ff4:
	/* 0x3ff4: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_3ff7:
	/* 0x3ff7: je     4762 <generic_sleepable_preload+0x4762> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18274ULL;
	}
x86_l_3ffd:
	/* 0x3ffd: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4002:
	/* 0x4002: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_4005:
	/* 0x4005: je     4762 <generic_sleepable_preload+0x4762> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18274ULL;
	}
x86_l_400b:
	/* 0x400b: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4010:
	/* 0x4010: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_4013:
	/* 0x4013: je     4762 <generic_sleepable_preload+0x4762> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18274ULL;
	}
x86_l_4019:
	/* 0x4019: jmp    4775 <generic_sleepable_preload+0x4775> */
	return 18293ULL;
x86_l_401e:
	/* 0x401e: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_4021:
	/* 0x4021: je     4128 <generic_sleepable_preload+0x4128> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4128;
	}
x86_l_4027:
	/* 0x4027: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_402a:
	/* 0x402a: jne    417c <generic_sleepable_preload+0x417c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_417c;
	}
x86_l_4030:
	/* 0x4030: mov    edx,DWORD PTR [rdi+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_4036:
	/* 0x4036: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_403c:
	/* 0x403c: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_403f:
	/* 0x403f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4044:
	/* 0x4044: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_4047:
	/* 0x4047: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_404c:
	/* 0x404c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4051:
	/* 0x4051: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4053:
	/* 0x4053: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4055:
	/* 0x4055: jne    4177 <generic_sleepable_preload+0x4177> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4177;
	}
x86_l_405b:
	/* 0x405b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4060:
	/* 0x4060: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4065:
	/* 0x4065: add    rdx,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 584ULL);
x86_l_406c:
	/* 0x406c: jmp    4d46 <generic_sleepable_preload+0x4d46> */
	return 19782ULL;
x86_l_4071:
	/* 0x4071: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4074:
	/* 0x4074: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4079:
	/* 0x4079: jg     40ca <generic_sleepable_preload+0x40ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_40ca;
	}
x86_l_407b:
	/* 0x407b: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_407e:
	/* 0x407e: jg     471c <generic_sleepable_preload+0x471c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 18204ULL;
	}
x86_l_4084:
	/* 0x4084: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4086:
	/* 0x4086: je     4762 <generic_sleepable_preload+0x4762> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18274ULL;
	}
x86_l_408c:
	/* 0x408c: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_408f:
	/* 0x408f: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4092:
	/* 0x4092: je     4762 <generic_sleepable_preload+0x4762> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18274ULL;
	}
x86_l_4098:
	/* 0x4098: jmp    4775 <generic_sleepable_preload+0x4775> */
	return 18293ULL;
x86_l_409d:
	/* 0x409d: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_40a0:
	/* 0x40a0: jg     4703 <generic_sleepable_preload+0x4703> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 18179ULL;
	}
x86_l_40a6:
	/* 0x40a6: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_40ae:
	/* 0x40ae: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_40b1:
	/* 0x40b1: je     4762 <generic_sleepable_preload+0x4762> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18274ULL;
	}
x86_l_40b7:
	/* 0x40b7: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_40bc:
	/* 0x40bc: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_40bf:
	/* 0x40bf: je     4762 <generic_sleepable_preload+0x4762> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18274ULL;
	}
x86_l_40c5:
	/* 0x40c5: jmp    4775 <generic_sleepable_preload+0x4775> */
	return 18293ULL;
x86_l_40ca:
	/* 0x40ca: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_40cd:
	/* 0x40cd: jg     4732 <generic_sleepable_preload+0x4732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 18226ULL;
	}
x86_l_40d3:
	/* 0x40d3: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_40db:
	/* 0x40db: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_40de:
	/* 0x40de: je     4762 <generic_sleepable_preload+0x4762> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18274ULL;
	}
x86_l_40e4:
	/* 0x40e4: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_40e9:
	/* 0x40e9: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_40ec:
	/* 0x40ec: je     4762 <generic_sleepable_preload+0x4762> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18274ULL;
	}
x86_l_40f2:
	/* 0x40f2: jmp    4775 <generic_sleepable_preload+0x4775> */
	return 18293ULL;
x86_l_40f7:
	/* 0x40f7: mov    rax,QWORD PTR [rdi+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_40fe:
	/* 0x40fe: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4103:
	/* 0x4103: movzx  eax,BYTE PTR [rdi+0x258] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 600ULL);
x86_l_410a:
	/* 0x410a: shlx   rcx,QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((32ULL << 32) | X86_ALU_SHL));
x86_l_4111:
	/* 0x4111: cmp    BYTE PTR [rdi+0x25a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2585570312192ULL);
x86_l_4118:
	/* 0x4118: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_411d:
	/* 0x411d: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_4122:
	/* 0x4122: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_4126:
	/* 0x4126: jmp    417c <generic_sleepable_preload+0x417c> */
	goto x86_l_417c;
x86_l_4128:
	/* 0x4128: mov    edx,DWORD PTR [rdi+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_412e:
	/* 0x412e: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4134:
	/* 0x4134: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4137:
	/* 0x4137: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_413c:
	/* 0x413c: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_413f:
	/* 0x413f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4144:
	/* 0x4144: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4149:
	/* 0x4149: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_414b:
	/* 0x414b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_414d:
	/* 0x414d: jne    4177 <generic_sleepable_preload+0x4177> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4177;
	}
x86_l_414f:
	/* 0x414f: mov    edx,DWORD PTR [rbx+0x254] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 596ULL);
x86_l_4155:
	/* 0x4155: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_415b:
	/* 0x415b: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_415e:
	/* 0x415e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4163:
	/* 0x4163: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4168:
	/* 0x4168: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_416d:
	/* 0x416d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_416f:
	/* 0x416f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4171:
	/* 0x4171: je     4d24 <generic_sleepable_preload+0x4d24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19748ULL;
	}
x86_l_4177:
	/* 0x4177: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_4179:
	/* 0x4179: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_417c:
	/* 0x417c: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4181:
	/* 0x4181: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4183:
	/* 0x4183: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_4186:
	/* 0x4186: cmp    WORD PTR [rdi+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_418e:
	/* 0x418e: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19854ULL;
	}
x86_l_4194:
	/* 0x4194: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_419b:
	/* 0x419b: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_419e:
	/* 0x419e: mov    edx,DWORD PTR [rdi+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_41a4:
	/* 0x41a4: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_41a7:
	/* 0x41a7: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41ac:
	/* 0x41ac: movzx  eax,WORD PTR [rdi+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_41b3:
	/* 0x41b3: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_41b5:
	/* 0x41b5: je     4444 <generic_sleepable_preload+0x4444> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4444;
	}
x86_l_41bb:
	/* 0x41bb: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_41be:
	/* 0x41be: je     41e3 <generic_sleepable_preload+0x41e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41e3;
	}
x86_l_41c0:
	/* 0x41c0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_41c5:
	/* 0x41c5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41ca:
	/* 0x41ca: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41cf:
	/* 0x41cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41d4:
	/* 0x41d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41d6:
	/* 0x41d6: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_41db:
	/* 0x41db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_41dd:
	/* 0x41dd: js     46f9 <generic_sleepable_preload+0x46f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 18169ULL;
	}
x86_l_41e3:
	/* 0x41e3: cmp    WORD PTR [rdi+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_41eb:
	/* 0x41eb: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19854ULL;
	}
x86_l_41f1:
	/* 0x41f1: mov    eax,DWORD PTR [rdi+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_41f7:
	/* 0x41f7: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_41fc:
	/* 0x41fc: cmp    WORD PTR [rdi+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_4204:
	/* 0x4204: je     4229 <generic_sleepable_preload+0x4229> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4229;
	}
x86_l_4206:
	/* 0x4206: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_420b:
	/* 0x420b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4210:
	/* 0x4210: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4215:
	/* 0x4215: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_421a:
	/* 0x421a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_421c:
	/* 0x421c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4221:
	/* 0x4221: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4223:
	/* 0x4223: js     4cff <generic_sleepable_preload+0x4cff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19711ULL;
	}
x86_l_4229:
	/* 0x4229: cmp    WORD PTR [rdi+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_4231:
	/* 0x4231: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19854ULL;
	}
x86_l_4237:
	/* 0x4237: mov    eax,DWORD PTR [rdi+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_423d:
	/* 0x423d: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4242:
	/* 0x4242: cmp    WORD PTR [rdi+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_424a:
	/* 0x424a: je     426f <generic_sleepable_preload+0x426f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_426f;
	}
x86_l_424c:
	/* 0x424c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4251:
	/* 0x4251: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4256:
	/* 0x4256: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_425b:
	/* 0x425b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4260:
	/* 0x4260: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4262:
	/* 0x4262: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4267:
	/* 0x4267: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4269:
	/* 0x4269: js     4d13 <generic_sleepable_preload+0x4d13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19731ULL;
	}
x86_l_426f:
	/* 0x426f: cmp    WORD PTR [rdi+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_4277:
	/* 0x4277: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19854ULL;
	}
x86_l_427d:
	/* 0x427d: mov    eax,DWORD PTR [rdi+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_4283:
	/* 0x4283: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4288:
	/* 0x4288: cmp    WORD PTR [rdi+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_4290:
	/* 0x4290: je     42b5 <generic_sleepable_preload+0x42b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42b5;
	}
x86_l_4292:
	/* 0x4292: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4297:
	/* 0x4297: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_429c:
	/* 0x429c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42a1:
	/* 0x42a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42a6:
	/* 0x42a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42a8:
	/* 0x42a8: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_42ad:
	/* 0x42ad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42af:
	/* 0x42af: js     4d64 <generic_sleepable_preload+0x4d64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19812ULL;
	}
x86_l_42b5:
	/* 0x42b5: cmp    WORD PTR [rdi+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_42bd:
	/* 0x42bd: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19854ULL;
	}
x86_l_42c3:
	/* 0x42c3: mov    eax,DWORD PTR [rdi+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_42c9:
	/* 0x42c9: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_42ce:
	/* 0x42ce: cmp    WORD PTR [rdi+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_42d6:
	/* 0x42d6: je     42fb <generic_sleepable_preload+0x42fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42fb;
	}
x86_l_42d8:
	/* 0x42d8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_42dd:
	/* 0x42dd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42e2:
	/* 0x42e2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42e7:
	/* 0x42e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42ec:
	/* 0x42ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42ee:
	/* 0x42ee: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_42f3:
	/* 0x42f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42f5:
	/* 0x42f5: js     4d75 <generic_sleepable_preload+0x4d75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19829ULL;
	}
x86_l_42fb:
	/* 0x42fb: cmp    WORD PTR [rdi+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_4303:
	/* 0x4303: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19854ULL;
	}
x86_l_4309:
	/* 0x4309: mov    eax,DWORD PTR [rdi+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_430f:
	/* 0x430f: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4314:
	/* 0x4314: cmp    WORD PTR [rdi+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_431c:
	/* 0x431c: je     4341 <generic_sleepable_preload+0x4341> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4341;
	}
x86_l_431e:
	/* 0x431e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4323:
	/* 0x4323: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4328:
	/* 0x4328: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_432d:
	/* 0x432d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4332:
	/* 0x4332: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4334:
	/* 0x4334: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4339:
	/* 0x4339: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_433b:
	/* 0x433b: js     4d86 <generic_sleepable_preload+0x4d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19846ULL;
	}
x86_l_4341:
	/* 0x4341: cmp    WORD PTR [rdi+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_4349:
	/* 0x4349: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19854ULL;
	}
x86_l_434f:
	/* 0x434f: mov    eax,DWORD PTR [rdi+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_4355:
	/* 0x4355: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_435a:
	/* 0x435a: cmp    WORD PTR [rdi+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_4362:
	/* 0x4362: je     4382 <generic_sleepable_preload+0x4382> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4382;
	}
x86_l_4364:
	/* 0x4364: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4369:
	/* 0x4369: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_436e:
	/* 0x436e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4373:
	/* 0x4373: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4378:
	/* 0x4378: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_437a:
	/* 0x437a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_437c:
	/* 0x437c: js     5df2 <generic_sleepable_preload+0x5df2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24050ULL;
	}
x86_l_4382:
	/* 0x4382: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4387:
	/* 0x4387: cmp    WORD PTR [rdi+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_438f:
	/* 0x438f: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19854ULL;
	}
x86_l_4395:
	/* 0x4395: mov    eax,DWORD PTR [rdi+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_439b:
	/* 0x439b: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_43a0:
	/* 0x43a0: cmp    WORD PTR [rdi+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_43a8:
	/* 0x43a8: je     43c8 <generic_sleepable_preload+0x43c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43c8;
	}
x86_l_43aa:
	/* 0x43aa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_43af:
	/* 0x43af: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43b4:
	/* 0x43b4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43b9:
	/* 0x43b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43be:
	/* 0x43be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43c0:
	/* 0x43c0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_43c2:
	/* 0x43c2: js     5f6c <generic_sleepable_preload+0x5f6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24428ULL;
	}
x86_l_43c8:
	/* 0x43c8: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_43cd:
	/* 0x43cd: cmp    WORD PTR [rdi+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_43d5:
	/* 0x43d5: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19854ULL;
	}
x86_l_43db:
	/* 0x43db: mov    eax,DWORD PTR [rdi+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_43e1:
	/* 0x43e1: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_43e6:
	/* 0x43e6: cmp    WORD PTR [rdi+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_43ee:
	/* 0x43ee: je     440e <generic_sleepable_preload+0x440e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_440e;
	}
x86_l_43f0:
	/* 0x43f0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_43f5:
	/* 0x43f5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43fa:
	/* 0x43fa: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43ff:
	/* 0x43ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4404:
	/* 0x4404: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4406:
	/* 0x4406: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4408:
	/* 0x4408: js     6062 <generic_sleepable_preload+0x6062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24674ULL;
	}
x86_l_440e:
	/* 0x440e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4413:
	/* 0x4413: cmp    WORD PTR [rdi+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_441b:
	/* 0x441b: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19854ULL;
	}
x86_l_4421:
	/* 0x4421: mov    eax,DWORD PTR [rdi+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_4427:
	/* 0x4427: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_442c:
	/* 0x442c: cmp    WORD PTR [rdi+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_4434:
	/* 0x4434: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19854ULL;
	}
x86_l_443a:
	/* 0x443a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_443f:
	/* 0x443f: jmp    46d1 <generic_sleepable_preload+0x46d1> */
	return 18129ULL;
x86_l_4444:
	/* 0x4444: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4447:
	/* 0x4447: je     446c <generic_sleepable_preload+0x446c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_446c;
	}
x86_l_4449:
	/* 0x4449: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_444e:
	/* 0x444e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4453:
	/* 0x4453: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4458:
	/* 0x4458: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_445d:
	/* 0x445d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_445f:
	/* 0x445f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4464:
	/* 0x4464: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4466:
	/* 0x4466: js     46f9 <generic_sleepable_preload+0x46f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 18169ULL;
	}
x86_l_446c:
	/* 0x446c: cmp    WORD PTR [rdi+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_4474:
	/* 0x4474: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19854ULL;
	}
x86_l_447a:
	/* 0x447a: mov    eax,DWORD PTR [rdi+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_4480:
	/* 0x4480: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4485:
	/* 0x4485: cmp    WORD PTR [rdi+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_448d:
	/* 0x448d: je     44b2 <generic_sleepable_preload+0x44b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44b2;
	}
x86_l_448f:
	/* 0x448f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4494:
	/* 0x4494: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4499:
	/* 0x4499: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_449e:
	/* 0x449e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44a3:
	/* 0x44a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44a5:
	/* 0x44a5: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_44aa:
	/* 0x44aa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_44ac:
	/* 0x44ac: js     4cff <generic_sleepable_preload+0x4cff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19711ULL;
	}
x86_l_44b2:
	/* 0x44b2: cmp    WORD PTR [rdi+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_44ba:
	/* 0x44ba: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19854ULL;
	}
x86_l_44c0:
	/* 0x44c0: mov    eax,DWORD PTR [rdi+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_44c6:
	/* 0x44c6: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_44cb:
	/* 0x44cb: cmp    WORD PTR [rdi+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_44d3:
	/* 0x44d3: je     44f8 <generic_sleepable_preload+0x44f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44f8;
	}
x86_l_44d5:
	/* 0x44d5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_44da:
	/* 0x44da: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44df:
	/* 0x44df: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44e4:
	/* 0x44e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44e9:
	/* 0x44e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44eb:
	/* 0x44eb: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_44f0:
	/* 0x44f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_44f2:
	/* 0x44f2: js     4d13 <generic_sleepable_preload+0x4d13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19731ULL;
	}
x86_l_44f8:
	/* 0x44f8: cmp    WORD PTR [rdi+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_4500:
	/* 0x4500: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19854ULL;
	}
x86_l_4506:
	/* 0x4506: mov    eax,DWORD PTR [rdi+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_450c:
	/* 0x450c: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4511:
	/* 0x4511: cmp    WORD PTR [rdi+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_4519:
	/* 0x4519: je     453e <generic_sleepable_preload+0x453e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_453e;
	}
x86_l_451b:
	/* 0x451b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4520:
	/* 0x4520: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4525:
	/* 0x4525: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_452a:
	/* 0x452a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_452f:
	/* 0x452f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4531:
	/* 0x4531: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4536:
	/* 0x4536: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4538:
	/* 0x4538: js     4d64 <generic_sleepable_preload+0x4d64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19812ULL;
	}
x86_l_453e:
	/* 0x453e: cmp    WORD PTR [rdi+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_4546:
	/* 0x4546: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19854ULL;
	}
x86_l_454c:
	/* 0x454c: mov    eax,DWORD PTR [rdi+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_4552:
	/* 0x4552: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4557:
	/* 0x4557: cmp    WORD PTR [rdi+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_455f:
	/* 0x455f: je     4584 <generic_sleepable_preload+0x4584> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4584;
	}
x86_l_4561:
	/* 0x4561: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4566:
	/* 0x4566: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_456b:
	/* 0x456b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4570:
	/* 0x4570: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4575:
	/* 0x4575: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4577:
	/* 0x4577: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_457c:
	/* 0x457c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_457e:
	/* 0x457e: js     4d75 <generic_sleepable_preload+0x4d75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19829ULL;
	}
x86_l_4584:
	/* 0x4584: cmp    WORD PTR [rdi+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_458c:
	/* 0x458c: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19854ULL;
	}
x86_l_4592:
	/* 0x4592: mov    eax,DWORD PTR [rdi+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_4598:
	/* 0x4598: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_459d:
	/* 0x459d: cmp    WORD PTR [rdi+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_45a5:
	/* 0x45a5: je     45ca <generic_sleepable_preload+0x45ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45ca;
	}
x86_l_45a7:
	/* 0x45a7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_45ac:
	/* 0x45ac: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45b1:
	/* 0x45b1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45b6:
	/* 0x45b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45bb:
	/* 0x45bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45bd:
	/* 0x45bd: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_45c2:
	/* 0x45c2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_45c4:
	/* 0x45c4: js     4d86 <generic_sleepable_preload+0x4d86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19846ULL;
	}
x86_l_45ca:
	/* 0x45ca: cmp    WORD PTR [rdi+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_45d2:
	/* 0x45d2: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19854ULL;
	}
x86_l_45d8:
	/* 0x45d8: mov    eax,DWORD PTR [rdi+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_45de:
	/* 0x45de: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_45e3:
	/* 0x45e3: cmp    WORD PTR [rdi+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_45eb:
	/* 0x45eb: je     460b <generic_sleepable_preload+0x460b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_460b;
	}
x86_l_45ed:
	/* 0x45ed: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_45f2:
	/* 0x45f2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45f7:
	/* 0x45f7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45fc:
	/* 0x45fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4601:
	/* 0x4601: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4603:
	/* 0x4603: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4605:
	/* 0x4605: js     5df2 <generic_sleepable_preload+0x5df2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24050ULL;
	}
x86_l_460b:
	/* 0x460b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4610:
	/* 0x4610: cmp    WORD PTR [rdi+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_4618:
	/* 0x4618: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19854ULL;
	}
x86_l_461e:
	/* 0x461e: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_4621:
	/* 0x4621: mov    eax,DWORD PTR [rdi+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_4627:
	/* 0x4627: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_462c:
	/* 0x462c: cmp    WORD PTR [rdi+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_4634:
	/* 0x4634: je     4654 <generic_sleepable_preload+0x4654> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4654;
	}
x86_l_4636:
	/* 0x4636: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_463b:
	/* 0x463b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4640:
	/* 0x4640: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4645:
	/* 0x4645: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_464a:
	/* 0x464a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_464c:
	/* 0x464c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_464e:
	/* 0x464e: js     5ff2 <generic_sleepable_preload+0x5ff2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24562ULL;
	}
x86_l_4654:
	/* 0x4654: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4659:
	/* 0x4659: cmp    WORD PTR [rdi+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_4661:
	/* 0x4661: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_4664:
	/* 0x4664: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19854ULL;
	}
	return 18026ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 18026ULL: goto x86_l_466a;
	case 18032ULL: goto x86_l_4670;
	case 18037ULL: goto x86_l_4675;
	case 18045ULL: goto x86_l_467d;
	case 18047ULL: goto x86_l_467f;
	case 18052ULL: goto x86_l_4684;
	case 18057ULL: goto x86_l_4689;
	case 18062ULL: goto x86_l_468e;
	case 18067ULL: goto x86_l_4693;
	case 18069ULL: goto x86_l_4695;
	case 18071ULL: goto x86_l_4697;
	case 18077ULL: goto x86_l_469d;
	case 18082ULL: goto x86_l_46a2;
	case 18090ULL: goto x86_l_46aa;
	case 18093ULL: goto x86_l_46ad;
	case 18099ULL: goto x86_l_46b3;
	case 18105ULL: goto x86_l_46b9;
	case 18110ULL: goto x86_l_46be;
	case 18118ULL: goto x86_l_46c6;
	case 18124ULL: goto x86_l_46cc;
	case 18129ULL: goto x86_l_46d1;
	case 18134ULL: goto x86_l_46d6;
	case 18139ULL: goto x86_l_46db;
	case 18144ULL: goto x86_l_46e0;
	case 18146ULL: goto x86_l_46e2;
	case 18151ULL: goto x86_l_46e7;
	case 18153ULL: goto x86_l_46e9;
	case 18159ULL: goto x86_l_46ef;
	case 18164ULL: goto x86_l_46f4;
	case 18169ULL: goto x86_l_46f9;
	case 18174ULL: goto x86_l_46fe;
	case 18179ULL: goto x86_l_4703;
	case 18187ULL: goto x86_l_470b;
	case 18190ULL: goto x86_l_470e;
	case 18192ULL: goto x86_l_4710;
	case 18197ULL: goto x86_l_4715;
	case 18200ULL: goto x86_l_4718;
	case 18202ULL: goto x86_l_471a;
	case 18204ULL: goto x86_l_471c;
	case 18209ULL: goto x86_l_4721;
	case 18212ULL: goto x86_l_4724;
	case 18214ULL: goto x86_l_4726;
	case 18219ULL: goto x86_l_472b;
	case 18222ULL: goto x86_l_472e;
	case 18224ULL: goto x86_l_4730;
	case 18226ULL: goto x86_l_4732;
	case 18234ULL: goto x86_l_473a;
	case 18237ULL: goto x86_l_473d;
	case 18239ULL: goto x86_l_473f;
	case 18244ULL: goto x86_l_4744;
	case 18247ULL: goto x86_l_4747;
	case 18249ULL: goto x86_l_4749;
	case 18251ULL: goto x86_l_474b;
	case 18259ULL: goto x86_l_4753;
	case 18262ULL: goto x86_l_4756;
	case 18264ULL: goto x86_l_4758;
	case 18269ULL: goto x86_l_475d;
	case 18272ULL: goto x86_l_4760;
	case 18274ULL: goto x86_l_4762;
	case 18277ULL: goto x86_l_4765;
	case 18279ULL: goto x86_l_4767;
	case 18281ULL: goto x86_l_4769;
	case 18286ULL: goto x86_l_476e;
	case 18288ULL: goto x86_l_4770;
	case 18293ULL: goto x86_l_4775;
	case 18298ULL: goto x86_l_477a;
	case 18301ULL: goto x86_l_477d;
	case 18303ULL: goto x86_l_477f;
	case 18306ULL: goto x86_l_4782;
	case 18314ULL: goto x86_l_478a;
	case 18320ULL: goto x86_l_4790;
	case 18327ULL: goto x86_l_4797;
	case 18330ULL: goto x86_l_479a;
	case 18336ULL: goto x86_l_47a0;
	case 18339ULL: goto x86_l_47a3;
	case 18344ULL: goto x86_l_47a8;
	case 18351ULL: goto x86_l_47af;
	case 18353ULL: goto x86_l_47b1;
	case 18359ULL: goto x86_l_47b7;
	case 18362ULL: goto x86_l_47ba;
	case 18364ULL: goto x86_l_47bc;
	case 18369ULL: goto x86_l_47c1;
	case 18374ULL: goto x86_l_47c6;
	case 18379ULL: goto x86_l_47cb;
	case 18384ULL: goto x86_l_47d0;
	case 18386ULL: goto x86_l_47d2;
	case 18391ULL: goto x86_l_47d7;
	case 18393ULL: goto x86_l_47d9;
	case 18399ULL: goto x86_l_47df;
	case 18407ULL: goto x86_l_47e7;
	case 18413ULL: goto x86_l_47ed;
	case 18419ULL: goto x86_l_47f3;
	case 18424ULL: goto x86_l_47f8;
	case 18432ULL: goto x86_l_4800;
	case 18434ULL: goto x86_l_4802;
	case 18439ULL: goto x86_l_4807;
	case 18444ULL: goto x86_l_480c;
	case 18449ULL: goto x86_l_4811;
	case 18454ULL: goto x86_l_4816;
	case 18456ULL: goto x86_l_4818;
	case 18461ULL: goto x86_l_481d;
	case 18463ULL: goto x86_l_481f;
	case 18469ULL: goto x86_l_4825;
	case 18477ULL: goto x86_l_482d;
	case 18483ULL: goto x86_l_4833;
	case 18489ULL: goto x86_l_4839;
	case 18494ULL: goto x86_l_483e;
	case 18502ULL: goto x86_l_4846;
	case 18504ULL: goto x86_l_4848;
	case 18509ULL: goto x86_l_484d;
	case 18514ULL: goto x86_l_4852;
	case 18519ULL: goto x86_l_4857;
	case 18524ULL: goto x86_l_485c;
	case 18526ULL: goto x86_l_485e;
	case 18531ULL: goto x86_l_4863;
	case 18533ULL: goto x86_l_4865;
	case 18539ULL: goto x86_l_486b;
	case 18547ULL: goto x86_l_4873;
	case 18553ULL: goto x86_l_4879;
	case 18559ULL: goto x86_l_487f;
	case 18564ULL: goto x86_l_4884;
	case 18572ULL: goto x86_l_488c;
	case 18574ULL: goto x86_l_488e;
	case 18579ULL: goto x86_l_4893;
	case 18584ULL: goto x86_l_4898;
	case 18589ULL: goto x86_l_489d;
	case 18594ULL: goto x86_l_48a2;
	case 18596ULL: goto x86_l_48a4;
	case 18601ULL: goto x86_l_48a9;
	case 18603ULL: goto x86_l_48ab;
	case 18609ULL: goto x86_l_48b1;
	case 18617ULL: goto x86_l_48b9;
	case 18623ULL: goto x86_l_48bf;
	case 18629ULL: goto x86_l_48c5;
	case 18634ULL: goto x86_l_48ca;
	case 18642ULL: goto x86_l_48d2;
	case 18644ULL: goto x86_l_48d4;
	case 18649ULL: goto x86_l_48d9;
	case 18654ULL: goto x86_l_48de;
	case 18659ULL: goto x86_l_48e3;
	case 18664ULL: goto x86_l_48e8;
	case 18666ULL: goto x86_l_48ea;
	case 18671ULL: goto x86_l_48ef;
	case 18673ULL: goto x86_l_48f1;
	case 18679ULL: goto x86_l_48f7;
	case 18687ULL: goto x86_l_48ff;
	case 18693ULL: goto x86_l_4905;
	case 18699ULL: goto x86_l_490b;
	case 18704ULL: goto x86_l_4910;
	case 18712ULL: goto x86_l_4918;
	case 18714ULL: goto x86_l_491a;
	case 18719ULL: goto x86_l_491f;
	case 18724ULL: goto x86_l_4924;
	case 18729ULL: goto x86_l_4929;
	case 18734ULL: goto x86_l_492e;
	case 18736ULL: goto x86_l_4930;
	case 18741ULL: goto x86_l_4935;
	case 18743ULL: goto x86_l_4937;
	case 18749ULL: goto x86_l_493d;
	case 18757ULL: goto x86_l_4945;
	case 18763ULL: goto x86_l_494b;
	case 18769ULL: goto x86_l_4951;
	case 18774ULL: goto x86_l_4956;
	case 18782ULL: goto x86_l_495e;
	case 18784ULL: goto x86_l_4960;
	case 18789ULL: goto x86_l_4965;
	case 18794ULL: goto x86_l_496a;
	case 18799ULL: goto x86_l_496f;
	case 18804ULL: goto x86_l_4974;
	case 18806ULL: goto x86_l_4976;
	case 18808ULL: goto x86_l_4978;
	case 18814ULL: goto x86_l_497e;
	case 18819ULL: goto x86_l_4983;
	case 18827ULL: goto x86_l_498b;
	case 18833ULL: goto x86_l_4991;
	case 18839ULL: goto x86_l_4997;
	case 18844ULL: goto x86_l_499c;
	case 18852ULL: goto x86_l_49a4;
	case 18854ULL: goto x86_l_49a6;
	case 18859ULL: goto x86_l_49ab;
	case 18864ULL: goto x86_l_49b0;
	case 18869ULL: goto x86_l_49b5;
	case 18874ULL: goto x86_l_49ba;
	case 18876ULL: goto x86_l_49bc;
	case 18878ULL: goto x86_l_49be;
	case 18884ULL: goto x86_l_49c4;
	case 18889ULL: goto x86_l_49c9;
	case 18897ULL: goto x86_l_49d1;
	case 18903ULL: goto x86_l_49d7;
	case 18909ULL: goto x86_l_49dd;
	case 18914ULL: goto x86_l_49e2;
	case 18922ULL: goto x86_l_49ea;
	case 18924ULL: goto x86_l_49ec;
	case 18929ULL: goto x86_l_49f1;
	case 18934ULL: goto x86_l_49f6;
	case 18939ULL: goto x86_l_49fb;
	case 18944ULL: goto x86_l_4a00;
	case 18946ULL: goto x86_l_4a02;
	case 18948ULL: goto x86_l_4a04;
	case 18954ULL: goto x86_l_4a0a;
	case 18959ULL: goto x86_l_4a0f;
	case 18967ULL: goto x86_l_4a17;
	case 18973ULL: goto x86_l_4a1d;
	case 18979ULL: goto x86_l_4a23;
	case 18984ULL: goto x86_l_4a28;
	case 18992ULL: goto x86_l_4a30;
	case 18998ULL: goto x86_l_4a36;
	case 19003ULL: goto x86_l_4a3b;
	case 19008ULL: goto x86_l_4a40;
	case 19011ULL: goto x86_l_4a43;
	case 19013ULL: goto x86_l_4a45;
	case 19018ULL: goto x86_l_4a4a;
	case 19023ULL: goto x86_l_4a4f;
	case 19028ULL: goto x86_l_4a54;
	case 19033ULL: goto x86_l_4a59;
	case 19035ULL: goto x86_l_4a5b;
	case 19040ULL: goto x86_l_4a60;
	case 19042ULL: goto x86_l_4a62;
	case 19048ULL: goto x86_l_4a68;
	case 19056ULL: goto x86_l_4a70;
	case 19062ULL: goto x86_l_4a76;
	case 19068ULL: goto x86_l_4a7c;
	case 19073ULL: goto x86_l_4a81;
	case 19081ULL: goto x86_l_4a89;
	case 19083ULL: goto x86_l_4a8b;
	case 19088ULL: goto x86_l_4a90;
	case 19093ULL: goto x86_l_4a95;
	case 19098ULL: goto x86_l_4a9a;
	case 19103ULL: goto x86_l_4a9f;
	case 19105ULL: goto x86_l_4aa1;
	case 19110ULL: goto x86_l_4aa6;
	case 19112ULL: goto x86_l_4aa8;
	case 19118ULL: goto x86_l_4aae;
	case 19126ULL: goto x86_l_4ab6;
	case 19132ULL: goto x86_l_4abc;
	case 19138ULL: goto x86_l_4ac2;
	case 19143ULL: goto x86_l_4ac7;
	case 19151ULL: goto x86_l_4acf;
	case 19153ULL: goto x86_l_4ad1;
	case 19158ULL: goto x86_l_4ad6;
	case 19163ULL: goto x86_l_4adb;
	case 19168ULL: goto x86_l_4ae0;
	case 19173ULL: goto x86_l_4ae5;
	case 19175ULL: goto x86_l_4ae7;
	case 19180ULL: goto x86_l_4aec;
	case 19182ULL: goto x86_l_4aee;
	case 19188ULL: goto x86_l_4af4;
	case 19196ULL: goto x86_l_4afc;
	case 19202ULL: goto x86_l_4b02;
	case 19208ULL: goto x86_l_4b08;
	case 19213ULL: goto x86_l_4b0d;
	case 19221ULL: goto x86_l_4b15;
	case 19223ULL: goto x86_l_4b17;
	case 19228ULL: goto x86_l_4b1c;
	case 19233ULL: goto x86_l_4b21;
	case 19238ULL: goto x86_l_4b26;
	case 19243ULL: goto x86_l_4b2b;
	case 19245ULL: goto x86_l_4b2d;
	case 19250ULL: goto x86_l_4b32;
	case 19252ULL: goto x86_l_4b34;
	case 19258ULL: goto x86_l_4b3a;
	case 19266ULL: goto x86_l_4b42;
	case 19272ULL: goto x86_l_4b48;
	case 19278ULL: goto x86_l_4b4e;
	case 19283ULL: goto x86_l_4b53;
	case 19291ULL: goto x86_l_4b5b;
	case 19293ULL: goto x86_l_4b5d;
	case 19298ULL: goto x86_l_4b62;
	case 19303ULL: goto x86_l_4b67;
	case 19308ULL: goto x86_l_4b6c;
	case 19313ULL: goto x86_l_4b71;
	case 19315ULL: goto x86_l_4b73;
	case 19320ULL: goto x86_l_4b78;
	case 19322ULL: goto x86_l_4b7a;
	case 19328ULL: goto x86_l_4b80;
	case 19336ULL: goto x86_l_4b88;
	case 19342ULL: goto x86_l_4b8e;
	case 19348ULL: goto x86_l_4b94;
	case 19353ULL: goto x86_l_4b99;
	case 19361ULL: goto x86_l_4ba1;
	case 19363ULL: goto x86_l_4ba3;
	case 19368ULL: goto x86_l_4ba8;
	case 19373ULL: goto x86_l_4bad;
	case 19378ULL: goto x86_l_4bb2;
	case 19383ULL: goto x86_l_4bb7;
	case 19385ULL: goto x86_l_4bb9;
	case 19390ULL: goto x86_l_4bbe;
	case 19392ULL: goto x86_l_4bc0;
	case 19398ULL: goto x86_l_4bc6;
	case 19406ULL: goto x86_l_4bce;
	case 19412ULL: goto x86_l_4bd4;
	case 19418ULL: goto x86_l_4bda;
	case 19423ULL: goto x86_l_4bdf;
	case 19431ULL: goto x86_l_4be7;
	case 19433ULL: goto x86_l_4be9;
	case 19438ULL: goto x86_l_4bee;
	case 19443ULL: goto x86_l_4bf3;
	case 19448ULL: goto x86_l_4bf8;
	case 19453ULL: goto x86_l_4bfd;
	case 19455ULL: goto x86_l_4bff;
	case 19457ULL: goto x86_l_4c01;
	case 19463ULL: goto x86_l_4c07;
	case 19468ULL: goto x86_l_4c0c;
	case 19476ULL: goto x86_l_4c14;
	case 19482ULL: goto x86_l_4c1a;
	case 19485ULL: goto x86_l_4c1d;
	case 19491ULL: goto x86_l_4c23;
	case 19496ULL: goto x86_l_4c28;
	case 19504ULL: goto x86_l_4c30;
	case 19506ULL: goto x86_l_4c32;
	case 19511ULL: goto x86_l_4c37;
	case 19516ULL: goto x86_l_4c3c;
	case 19521ULL: goto x86_l_4c41;
	case 19526ULL: goto x86_l_4c46;
	case 19528ULL: goto x86_l_4c48;
	case 19530ULL: goto x86_l_4c4a;
	case 19536ULL: goto x86_l_4c50;
	case 19541ULL: goto x86_l_4c55;
	case 19549ULL: goto x86_l_4c5d;
	case 19552ULL: goto x86_l_4c60;
	case 19558ULL: goto x86_l_4c66;
	case 19564ULL: goto x86_l_4c6c;
	case 19569ULL: goto x86_l_4c71;
	case 19577ULL: goto x86_l_4c79;
	case 19579ULL: goto x86_l_4c7b;
	case 19584ULL: goto x86_l_4c80;
	case 19589ULL: goto x86_l_4c85;
	case 19594ULL: goto x86_l_4c8a;
	case 19599ULL: goto x86_l_4c8f;
	case 19601ULL: goto x86_l_4c91;
	case 19603ULL: goto x86_l_4c93;
	case 19609ULL: goto x86_l_4c99;
	case 19614ULL: goto x86_l_4c9e;
	case 19622ULL: goto x86_l_4ca6;
	case 19625ULL: goto x86_l_4ca9;
	case 19631ULL: goto x86_l_4caf;
	case 19637ULL: goto x86_l_4cb5;
	case 19642ULL: goto x86_l_4cba;
	case 19650ULL: goto x86_l_4cc2;
	case 19656ULL: goto x86_l_4cc8;
	case 19661ULL: goto x86_l_4ccd;
	case 19666ULL: goto x86_l_4cd2;
	case 19671ULL: goto x86_l_4cd7;
	case 19676ULL: goto x86_l_4cdc;
	case 19678ULL: goto x86_l_4cde;
	case 19683ULL: goto x86_l_4ce3;
	case 19685ULL: goto x86_l_4ce5;
	case 19691ULL: goto x86_l_4ceb;
	case 19696ULL: goto x86_l_4cf0;
	case 19701ULL: goto x86_l_4cf5;
	case 19706ULL: goto x86_l_4cfa;
	case 19711ULL: goto x86_l_4cff;
	case 19716ULL: goto x86_l_4d04;
	case 19721ULL: goto x86_l_4d09;
	case 19726ULL: goto x86_l_4d0e;
	case 19731ULL: goto x86_l_4d13;
	case 19736ULL: goto x86_l_4d18;
	case 19738ULL: goto x86_l_4d1a;
	case 19743ULL: goto x86_l_4d1f;
	case 19748ULL: goto x86_l_4d24;
	case 19753ULL: goto x86_l_4d29;
	case 19760ULL: goto x86_l_4d30;
	case 19767ULL: goto x86_l_4d37;
	case 19774ULL: goto x86_l_4d3e;
	case 19779ULL: goto x86_l_4d43;
	case 19782ULL: goto x86_l_4d46;
	case 19787ULL: goto x86_l_4d4b;
	case 19792ULL: goto x86_l_4d50;
	case 19794ULL: goto x86_l_4d52;
	case 19796ULL: goto x86_l_4d54;
	case 19799ULL: goto x86_l_4d57;
	case 19805ULL: goto x86_l_4d5d;
	case 19807ULL: goto x86_l_4d5f;
	case 19812ULL: goto x86_l_4d64;
	case 19817ULL: goto x86_l_4d69;
	case 19819ULL: goto x86_l_4d6b;
	case 19824ULL: goto x86_l_4d70;
	case 19829ULL: goto x86_l_4d75;
	case 19834ULL: goto x86_l_4d7a;
	case 19836ULL: goto x86_l_4d7c;
	case 19841ULL: goto x86_l_4d81;
	case 19846ULL: goto x86_l_4d86;
	case 19851ULL: goto x86_l_4d8b;
	case 19854ULL: goto x86_l_4d8e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_466a:
	/* 0x466a: mov    eax,DWORD PTR [rdi+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_4670:
	/* 0x4670: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4675:
	/* 0x4675: cmp    WORD PTR [rdi+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_467d:
	/* 0x467d: je     469d <generic_sleepable_preload+0x469d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_469d;
	}
x86_l_467f:
	/* 0x467f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4684:
	/* 0x4684: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4689:
	/* 0x4689: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_468e:
	/* 0x468e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4693:
	/* 0x4693: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4695:
	/* 0x4695: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4697:
	/* 0x4697: js     60fe <generic_sleepable_preload+0x60fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24830ULL;
	}
x86_l_469d:
	/* 0x469d: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_46a2:
	/* 0x46a2: cmp    WORD PTR [rdi+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_46aa:
	/* 0x46aa: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_46ad:
	/* 0x46ad: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d8e;
	}
x86_l_46b3:
	/* 0x46b3: mov    eax,DWORD PTR [rdi+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_46b9:
	/* 0x46b9: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_46be:
	/* 0x46be: cmp    WORD PTR [rdi+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_46c6:
	/* 0x46c6: je     4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d8e;
	}
x86_l_46cc:
	/* 0x46cc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46d1:
	/* 0x46d1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46d6:
	/* 0x46d6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46db:
	/* 0x46db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46e0:
	/* 0x46e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46e2:
	/* 0x46e2: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_46e7:
	/* 0x46e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46e9:
	/* 0x46e9: jns    4d8e <generic_sleepable_preload+0x4d8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_4d8e;
	}
x86_l_46ef:
	/* 0x46ef: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_46f4:
	/* 0x46f4: jmp    4d8b <generic_sleepable_preload+0x4d8b> */
	goto x86_l_4d8b;
x86_l_46f9:
	/* 0x46f9: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_46fe:
	/* 0x46fe: jmp    4d8b <generic_sleepable_preload+0x4d8b> */
	goto x86_l_4d8b;
x86_l_4703:
	/* 0x4703: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_470b:
	/* 0x470b: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_470e:
	/* 0x470e: je     4762 <generic_sleepable_preload+0x4762> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4762;
	}
x86_l_4710:
	/* 0x4710: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4715:
	/* 0x4715: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_4718:
	/* 0x4718: je     4762 <generic_sleepable_preload+0x4762> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4762;
	}
x86_l_471a:
	/* 0x471a: jmp    4775 <generic_sleepable_preload+0x4775> */
	goto x86_l_4775;
x86_l_471c:
	/* 0x471c: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4721:
	/* 0x4721: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_4724:
	/* 0x4724: je     4762 <generic_sleepable_preload+0x4762> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4762;
	}
x86_l_4726:
	/* 0x4726: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_472b:
	/* 0x472b: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_472e:
	/* 0x472e: je     4762 <generic_sleepable_preload+0x4762> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4762;
	}
x86_l_4730:
	/* 0x4730: jmp    4775 <generic_sleepable_preload+0x4775> */
	goto x86_l_4775;
x86_l_4732:
	/* 0x4732: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_473a:
	/* 0x473a: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_473d:
	/* 0x473d: je     4762 <generic_sleepable_preload+0x4762> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4762;
	}
x86_l_473f:
	/* 0x473f: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4744:
	/* 0x4744: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4747:
	/* 0x4747: je     4762 <generic_sleepable_preload+0x4762> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4762;
	}
x86_l_4749:
	/* 0x4749: jmp    4775 <generic_sleepable_preload+0x4775> */
	goto x86_l_4775;
x86_l_474b:
	/* 0x474b: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4753:
	/* 0x4753: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_4756:
	/* 0x4756: je     4762 <generic_sleepable_preload+0x4762> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4762;
	}
x86_l_4758:
	/* 0x4758: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_475d:
	/* 0x475d: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4760:
	/* 0x4760: jne    4775 <generic_sleepable_preload+0x4775> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4775;
	}
x86_l_4762:
	/* 0x4762: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_4765:
	/* 0x4765: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_4767:
	/* 0x4767: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_4769:
	/* 0x4769: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_476e:
	/* 0x476e: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4770:
	/* 0x4770: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_4775:
	/* 0x4775: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_477a:
	/* 0x477a: mov    ebx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_477d:
	/* 0x477d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_477f:
	/* 0x477f: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_4782:
	/* 0x4782: cmp    WORD PTR [rdi+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_478a:
	/* 0x478a: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_4790:
	/* 0x4790: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_4797:
	/* 0x4797: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_479a:
	/* 0x479a: mov    edx,DWORD PTR [rdi+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_47a0:
	/* 0x47a0: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_47a3:
	/* 0x47a3: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47a8:
	/* 0x47a8: movzx  eax,WORD PTR [rdi+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_47af:
	/* 0x47af: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_47b1:
	/* 0x47b1: je     4a40 <generic_sleepable_preload+0x4a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a40;
	}
x86_l_47b7:
	/* 0x47b7: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_47ba:
	/* 0x47ba: je     47df <generic_sleepable_preload+0x47df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47df;
	}
x86_l_47bc:
	/* 0x47bc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47c1:
	/* 0x47c1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47c6:
	/* 0x47c6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47cb:
	/* 0x47cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47d0:
	/* 0x47d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47d2:
	/* 0x47d2: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_47d7:
	/* 0x47d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_47d9:
	/* 0x47d9: js     4cf5 <generic_sleepable_preload+0x4cf5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4cf5;
	}
x86_l_47df:
	/* 0x47df: cmp    WORD PTR [rdi+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_47e7:
	/* 0x47e7: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_47ed:
	/* 0x47ed: mov    eax,DWORD PTR [rdi+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_47f3:
	/* 0x47f3: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_47f8:
	/* 0x47f8: cmp    WORD PTR [rdi+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_4800:
	/* 0x4800: je     4825 <generic_sleepable_preload+0x4825> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4825;
	}
x86_l_4802:
	/* 0x4802: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4807:
	/* 0x4807: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_480c:
	/* 0x480c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4811:
	/* 0x4811: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4816:
	/* 0x4816: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4818:
	/* 0x4818: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_481d:
	/* 0x481d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_481f:
	/* 0x481f: js     4d09 <generic_sleepable_preload+0x4d09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4d09;
	}
x86_l_4825:
	/* 0x4825: cmp    WORD PTR [rdi+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_482d:
	/* 0x482d: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_4833:
	/* 0x4833: mov    eax,DWORD PTR [rdi+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_4839:
	/* 0x4839: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_483e:
	/* 0x483e: cmp    WORD PTR [rdi+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_4846:
	/* 0x4846: je     486b <generic_sleepable_preload+0x486b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_486b;
	}
x86_l_4848:
	/* 0x4848: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_484d:
	/* 0x484d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4852:
	/* 0x4852: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4857:
	/* 0x4857: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_485c:
	/* 0x485c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_485e:
	/* 0x485e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4863:
	/* 0x4863: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4865:
	/* 0x4865: js     4d1a <generic_sleepable_preload+0x4d1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4d1a;
	}
x86_l_486b:
	/* 0x486b: cmp    WORD PTR [rdi+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_4873:
	/* 0x4873: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_4879:
	/* 0x4879: mov    eax,DWORD PTR [rdi+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_487f:
	/* 0x487f: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4884:
	/* 0x4884: cmp    WORD PTR [rdi+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_488c:
	/* 0x488c: je     48b1 <generic_sleepable_preload+0x48b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48b1;
	}
x86_l_488e:
	/* 0x488e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4893:
	/* 0x4893: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4898:
	/* 0x4898: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_489d:
	/* 0x489d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48a2:
	/* 0x48a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48a4:
	/* 0x48a4: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_48a9:
	/* 0x48a9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48ab:
	/* 0x48ab: js     4d6b <generic_sleepable_preload+0x4d6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4d6b;
	}
x86_l_48b1:
	/* 0x48b1: cmp    WORD PTR [rdi+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_48b9:
	/* 0x48b9: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_48bf:
	/* 0x48bf: mov    eax,DWORD PTR [rdi+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_48c5:
	/* 0x48c5: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_48ca:
	/* 0x48ca: cmp    WORD PTR [rdi+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_48d2:
	/* 0x48d2: je     48f7 <generic_sleepable_preload+0x48f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48f7;
	}
x86_l_48d4:
	/* 0x48d4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_48d9:
	/* 0x48d9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48de:
	/* 0x48de: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48e3:
	/* 0x48e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48e8:
	/* 0x48e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48ea:
	/* 0x48ea: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_48ef:
	/* 0x48ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48f1:
	/* 0x48f1: js     4d7c <generic_sleepable_preload+0x4d7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4d7c;
	}
x86_l_48f7:
	/* 0x48f7: cmp    WORD PTR [rdi+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_48ff:
	/* 0x48ff: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_4905:
	/* 0x4905: mov    eax,DWORD PTR [rdi+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_490b:
	/* 0x490b: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4910:
	/* 0x4910: cmp    WORD PTR [rdi+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_4918:
	/* 0x4918: je     493d <generic_sleepable_preload+0x493d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_493d;
	}
x86_l_491a:
	/* 0x491a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_491f:
	/* 0x491f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4924:
	/* 0x4924: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4929:
	/* 0x4929: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_492e:
	/* 0x492e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4930:
	/* 0x4930: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4935:
	/* 0x4935: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4937:
	/* 0x4937: js     4e0d <generic_sleepable_preload+0x4e0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19981ULL;
	}
x86_l_493d:
	/* 0x493d: cmp    WORD PTR [rdi+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_4945:
	/* 0x4945: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_494b:
	/* 0x494b: mov    eax,DWORD PTR [rdi+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_4951:
	/* 0x4951: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4956:
	/* 0x4956: cmp    WORD PTR [rdi+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_495e:
	/* 0x495e: je     497e <generic_sleepable_preload+0x497e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_497e;
	}
x86_l_4960:
	/* 0x4960: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4965:
	/* 0x4965: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_496a:
	/* 0x496a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_496f:
	/* 0x496f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4974:
	/* 0x4974: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4976:
	/* 0x4976: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4978:
	/* 0x4978: js     5e04 <generic_sleepable_preload+0x5e04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24068ULL;
	}
x86_l_497e:
	/* 0x497e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4983:
	/* 0x4983: cmp    WORD PTR [rdi+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_498b:
	/* 0x498b: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_4991:
	/* 0x4991: mov    eax,DWORD PTR [rdi+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_4997:
	/* 0x4997: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_499c:
	/* 0x499c: cmp    WORD PTR [rdi+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_49a4:
	/* 0x49a4: je     49c4 <generic_sleepable_preload+0x49c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49c4;
	}
x86_l_49a6:
	/* 0x49a6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_49ab:
	/* 0x49ab: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49b0:
	/* 0x49b0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49b5:
	/* 0x49b5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49ba:
	/* 0x49ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49bc:
	/* 0x49bc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_49be:
	/* 0x49be: js     5f7e <generic_sleepable_preload+0x5f7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24446ULL;
	}
x86_l_49c4:
	/* 0x49c4: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_49c9:
	/* 0x49c9: cmp    WORD PTR [rdi+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_49d1:
	/* 0x49d1: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_49d7:
	/* 0x49d7: mov    eax,DWORD PTR [rdi+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_49dd:
	/* 0x49dd: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_49e2:
	/* 0x49e2: cmp    WORD PTR [rdi+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_49ea:
	/* 0x49ea: je     4a0a <generic_sleepable_preload+0x4a0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a0a;
	}
x86_l_49ec:
	/* 0x49ec: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_49f1:
	/* 0x49f1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49f6:
	/* 0x49f6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49fb:
	/* 0x49fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a00:
	/* 0x4a00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a02:
	/* 0x4a02: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a04:
	/* 0x4a04: js     606c <generic_sleepable_preload+0x606c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24684ULL;
	}
x86_l_4a0a:
	/* 0x4a0a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a0f:
	/* 0x4a0f: cmp    WORD PTR [rdi+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_4a17:
	/* 0x4a17: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_4a1d:
	/* 0x4a1d: mov    eax,DWORD PTR [rdi+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_4a23:
	/* 0x4a23: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4a28:
	/* 0x4a28: cmp    WORD PTR [rdi+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_4a30:
	/* 0x4a30: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_4a36:
	/* 0x4a36: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a3b:
	/* 0x4a3b: jmp    4ccd <generic_sleepable_preload+0x4ccd> */
	goto x86_l_4ccd;
x86_l_4a40:
	/* 0x4a40: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4a43:
	/* 0x4a43: je     4a68 <generic_sleepable_preload+0x4a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a68;
	}
x86_l_4a45:
	/* 0x4a45: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a4a:
	/* 0x4a4a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a4f:
	/* 0x4a4f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a54:
	/* 0x4a54: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a59:
	/* 0x4a59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a5b:
	/* 0x4a5b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a60:
	/* 0x4a60: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a62:
	/* 0x4a62: js     4cf5 <generic_sleepable_preload+0x4cf5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4cf5;
	}
x86_l_4a68:
	/* 0x4a68: cmp    WORD PTR [rdi+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_4a70:
	/* 0x4a70: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_4a76:
	/* 0x4a76: mov    eax,DWORD PTR [rdi+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_4a7c:
	/* 0x4a7c: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4a81:
	/* 0x4a81: cmp    WORD PTR [rdi+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_4a89:
	/* 0x4a89: je     4aae <generic_sleepable_preload+0x4aae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4aae;
	}
x86_l_4a8b:
	/* 0x4a8b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a90:
	/* 0x4a90: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a95:
	/* 0x4a95: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a9a:
	/* 0x4a9a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a9f:
	/* 0x4a9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4aa1:
	/* 0x4aa1: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4aa6:
	/* 0x4aa6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4aa8:
	/* 0x4aa8: js     4d09 <generic_sleepable_preload+0x4d09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4d09;
	}
x86_l_4aae:
	/* 0x4aae: cmp    WORD PTR [rdi+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_4ab6:
	/* 0x4ab6: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_4abc:
	/* 0x4abc: mov    eax,DWORD PTR [rdi+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_4ac2:
	/* 0x4ac2: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4ac7:
	/* 0x4ac7: cmp    WORD PTR [rdi+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_4acf:
	/* 0x4acf: je     4af4 <generic_sleepable_preload+0x4af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4af4;
	}
x86_l_4ad1:
	/* 0x4ad1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ad6:
	/* 0x4ad6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4adb:
	/* 0x4adb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ae0:
	/* 0x4ae0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ae5:
	/* 0x4ae5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ae7:
	/* 0x4ae7: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4aec:
	/* 0x4aec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4aee:
	/* 0x4aee: js     4d1a <generic_sleepable_preload+0x4d1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4d1a;
	}
x86_l_4af4:
	/* 0x4af4: cmp    WORD PTR [rdi+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_4afc:
	/* 0x4afc: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_4b02:
	/* 0x4b02: mov    eax,DWORD PTR [rdi+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_4b08:
	/* 0x4b08: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4b0d:
	/* 0x4b0d: cmp    WORD PTR [rdi+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_4b15:
	/* 0x4b15: je     4b3a <generic_sleepable_preload+0x4b3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b3a;
	}
x86_l_4b17:
	/* 0x4b17: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b1c:
	/* 0x4b1c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b21:
	/* 0x4b21: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b26:
	/* 0x4b26: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b2b:
	/* 0x4b2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b2d:
	/* 0x4b2d: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b32:
	/* 0x4b32: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b34:
	/* 0x4b34: js     4d6b <generic_sleepable_preload+0x4d6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4d6b;
	}
x86_l_4b3a:
	/* 0x4b3a: cmp    WORD PTR [rdi+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_4b42:
	/* 0x4b42: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_4b48:
	/* 0x4b48: mov    eax,DWORD PTR [rdi+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_4b4e:
	/* 0x4b4e: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4b53:
	/* 0x4b53: cmp    WORD PTR [rdi+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_4b5b:
	/* 0x4b5b: je     4b80 <generic_sleepable_preload+0x4b80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b80;
	}
x86_l_4b5d:
	/* 0x4b5d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b62:
	/* 0x4b62: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b67:
	/* 0x4b67: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b6c:
	/* 0x4b6c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b71:
	/* 0x4b71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b73:
	/* 0x4b73: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b78:
	/* 0x4b78: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b7a:
	/* 0x4b7a: js     4d7c <generic_sleepable_preload+0x4d7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4d7c;
	}
x86_l_4b80:
	/* 0x4b80: cmp    WORD PTR [rdi+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_4b88:
	/* 0x4b88: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_4b8e:
	/* 0x4b8e: mov    eax,DWORD PTR [rdi+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_4b94:
	/* 0x4b94: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4b99:
	/* 0x4b99: cmp    WORD PTR [rdi+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_4ba1:
	/* 0x4ba1: je     4bc6 <generic_sleepable_preload+0x4bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc6;
	}
x86_l_4ba3:
	/* 0x4ba3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ba8:
	/* 0x4ba8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bad:
	/* 0x4bad: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bb2:
	/* 0x4bb2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4bb7:
	/* 0x4bb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bb9:
	/* 0x4bb9: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4bbe:
	/* 0x4bbe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4bc0:
	/* 0x4bc0: js     4e0d <generic_sleepable_preload+0x4e0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19981ULL;
	}
x86_l_4bc6:
	/* 0x4bc6: cmp    WORD PTR [rdi+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_4bce:
	/* 0x4bce: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_4bd4:
	/* 0x4bd4: mov    eax,DWORD PTR [rdi+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_4bda:
	/* 0x4bda: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4bdf:
	/* 0x4bdf: cmp    WORD PTR [rdi+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_4be7:
	/* 0x4be7: je     4c07 <generic_sleepable_preload+0x4c07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c07;
	}
x86_l_4be9:
	/* 0x4be9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4bee:
	/* 0x4bee: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bf3:
	/* 0x4bf3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bf8:
	/* 0x4bf8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4bfd:
	/* 0x4bfd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bff:
	/* 0x4bff: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c01:
	/* 0x4c01: js     5e04 <generic_sleepable_preload+0x5e04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24068ULL;
	}
x86_l_4c07:
	/* 0x4c07: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4c0c:
	/* 0x4c0c: cmp    WORD PTR [rdi+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_4c14:
	/* 0x4c14: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_4c1a:
	/* 0x4c1a: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_4c1d:
	/* 0x4c1d: mov    eax,DWORD PTR [rdi+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_4c23:
	/* 0x4c23: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4c28:
	/* 0x4c28: cmp    WORD PTR [rdi+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_4c30:
	/* 0x4c30: je     4c50 <generic_sleepable_preload+0x4c50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c50;
	}
x86_l_4c32:
	/* 0x4c32: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c37:
	/* 0x4c37: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c3c:
	/* 0x4c3c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c41:
	/* 0x4c41: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c46:
	/* 0x4c46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c48:
	/* 0x4c48: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c4a:
	/* 0x4c4a: js     5fff <generic_sleepable_preload+0x5fff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24575ULL;
	}
x86_l_4c50:
	/* 0x4c50: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4c55:
	/* 0x4c55: cmp    WORD PTR [rdi+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_4c5d:
	/* 0x4c5d: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_4c60:
	/* 0x4c60: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_4c66:
	/* 0x4c66: mov    eax,DWORD PTR [rdi+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_4c6c:
	/* 0x4c6c: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4c71:
	/* 0x4c71: cmp    WORD PTR [rdi+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_4c79:
	/* 0x4c79: je     4c99 <generic_sleepable_preload+0x4c99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c99;
	}
x86_l_4c7b:
	/* 0x4c7b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c80:
	/* 0x4c80: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c85:
	/* 0x4c85: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c8a:
	/* 0x4c8a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c8f:
	/* 0x4c8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c91:
	/* 0x4c91: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c93:
	/* 0x4c93: js     6113 <generic_sleepable_preload+0x6113> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24851ULL;
	}
x86_l_4c99:
	/* 0x4c99: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4c9e:
	/* 0x4c9e: cmp    WORD PTR [rdi+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_4ca6:
	/* 0x4ca6: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_4ca9:
	/* 0x4ca9: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_4caf:
	/* 0x4caf: mov    eax,DWORD PTR [rdi+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_4cb5:
	/* 0x4cb5: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4cba:
	/* 0x4cba: cmp    WORD PTR [rdi+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_4cc2:
	/* 0x4cc2: je     4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19989ULL;
	}
x86_l_4cc8:
	/* 0x4cc8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ccd:
	/* 0x4ccd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cd2:
	/* 0x4cd2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cd7:
	/* 0x4cd7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cdc:
	/* 0x4cdc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cde:
	/* 0x4cde: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ce3:
	/* 0x4ce3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ce5:
	/* 0x4ce5: jns    4e15 <generic_sleepable_preload+0x4e15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 19989ULL;
	}
x86_l_4ceb:
	/* 0x4ceb: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_4cf0:
	/* 0x4cf0: jmp    4e12 <generic_sleepable_preload+0x4e12> */
	return 19986ULL;
x86_l_4cf5:
	/* 0x4cf5: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_4cfa:
	/* 0x4cfa: jmp    4e12 <generic_sleepable_preload+0x4e12> */
	return 19986ULL;
x86_l_4cff:
	/* 0x4cff: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_4d04:
	/* 0x4d04: jmp    4d8b <generic_sleepable_preload+0x4d8b> */
	goto x86_l_4d8b;
x86_l_4d09:
	/* 0x4d09: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_4d0e:
	/* 0x4d0e: jmp    4e12 <generic_sleepable_preload+0x4e12> */
	return 19986ULL;
x86_l_4d13:
	/* 0x4d13: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_4d18:
	/* 0x4d18: jmp    4d8b <generic_sleepable_preload+0x4d8b> */
	goto x86_l_4d8b;
x86_l_4d1a:
	/* 0x4d1a: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_4d1f:
	/* 0x4d1f: jmp    4e12 <generic_sleepable_preload+0x4e12> */
	return 19986ULL;
x86_l_4d24:
	/* 0x4d24: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4d29:
	/* 0x4d29: movzx  ecx,BYTE PTR [rbx+0x25b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 603ULL);
x86_l_4d30:
	/* 0x4d30: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_4d37:
	/* 0x4d37: mov    rdx,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_4d3e:
	/* 0x4d3e: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_4d43:
	/* 0x4d43: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4d46:
	/* 0x4d46: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4d4b:
	/* 0x4d4b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d50:
	/* 0x4d50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d52:
	/* 0x4d52: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d54:
	/* 0x4d54: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4d57:
	/* 0x4d57: je     4103 <generic_sleepable_preload+0x4103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16643ULL;
	}
x86_l_4d5d:
	/* 0x4d5d: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_4d5f:
	/* 0x4d5f: jmp    417c <generic_sleepable_preload+0x417c> */
	return 16764ULL;
x86_l_4d64:
	/* 0x4d64: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_4d69:
	/* 0x4d69: jmp    4d8b <generic_sleepable_preload+0x4d8b> */
	goto x86_l_4d8b;
x86_l_4d6b:
	/* 0x4d6b: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_4d70:
	/* 0x4d70: jmp    4e12 <generic_sleepable_preload+0x4e12> */
	return 19986ULL;
x86_l_4d75:
	/* 0x4d75: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_4d7a:
	/* 0x4d7a: jmp    4d8b <generic_sleepable_preload+0x4d8b> */
	goto x86_l_4d8b;
x86_l_4d7c:
	/* 0x4d7c: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_4d81:
	/* 0x4d81: jmp    4e12 <generic_sleepable_preload+0x4e12> */
	return 19986ULL;
x86_l_4d86:
	/* 0x4d86: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4d8b:
	/* 0x4d8b: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d8e:
	/* 0x4d8e: mov    ebx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 19857ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 19857ULL: goto x86_l_4d91;
	case 19862ULL: goto x86_l_4d96;
	case 19867ULL: goto x86_l_4d9b;
	case 19872ULL: goto x86_l_4da0;
	case 19875ULL: goto x86_l_4da3;
	case 19877ULL: goto x86_l_4da5;
	case 19880ULL: goto x86_l_4da8;
	case 19886ULL: goto x86_l_4dae;
	case 19891ULL: goto x86_l_4db3;
	case 19896ULL: goto x86_l_4db8;
	case 19898ULL: goto x86_l_4dba;
	case 19903ULL: goto x86_l_4dbf;
	case 19911ULL: goto x86_l_4dc7;
	case 19916ULL: goto x86_l_4dcc;
	case 19923ULL: goto x86_l_4dd3;
	case 19928ULL: goto x86_l_4dd8;
	case 19930ULL: goto x86_l_4dda;
	case 19933ULL: goto x86_l_4ddd;
	case 19939ULL: goto x86_l_4de3;
	case 19945ULL: goto x86_l_4de9;
	case 19948ULL: goto x86_l_4dec;
	case 19955ULL: goto x86_l_4df3;
	case 19960ULL: goto x86_l_4df8;
	case 19963ULL: goto x86_l_4dfb;
	case 19966ULL: goto x86_l_4dfe;
	case 19969ULL: goto x86_l_4e01;
	case 19971ULL: goto x86_l_4e03;
	case 19974ULL: goto x86_l_4e06;
	case 19979ULL: goto x86_l_4e0b;
	case 19981ULL: goto x86_l_4e0d;
	case 19986ULL: goto x86_l_4e12;
	case 19989ULL: goto x86_l_4e15;
	case 19992ULL: goto x86_l_4e18;
	case 19998ULL: goto x86_l_4e1e;
	case 20003ULL: goto x86_l_4e23;
	case 20008ULL: goto x86_l_4e28;
	case 20010ULL: goto x86_l_4e2a;
	case 20015ULL: goto x86_l_4e2f;
	case 20023ULL: goto x86_l_4e37;
	case 20028ULL: goto x86_l_4e3c;
	case 20035ULL: goto x86_l_4e43;
	case 20040ULL: goto x86_l_4e48;
	case 20042ULL: goto x86_l_4e4a;
	case 20045ULL: goto x86_l_4e4d;
	case 20047ULL: goto x86_l_4e4f;
	case 20053ULL: goto x86_l_4e55;
	case 20056ULL: goto x86_l_4e58;
	case 20063ULL: goto x86_l_4e5f;
	case 20068ULL: goto x86_l_4e64;
	case 20071ULL: goto x86_l_4e67;
	case 20074ULL: goto x86_l_4e6a;
	case 20077ULL: goto x86_l_4e6d;
	case 20079ULL: goto x86_l_4e6f;
	case 20082ULL: goto x86_l_4e72;
	case 20087ULL: goto x86_l_4e77;
	case 20090ULL: goto x86_l_4e7a;
	case 20093ULL: goto x86_l_4e7d;
	case 20096ULL: goto x86_l_4e80;
	case 20098ULL: goto x86_l_4e82;
	case 20101ULL: goto x86_l_4e85;
	case 20103ULL: goto x86_l_4e87;
	case 20106ULL: goto x86_l_4e8a;
	case 20108ULL: goto x86_l_4e8c;
	case 20111ULL: goto x86_l_4e8f;
	case 20115ULL: goto x86_l_4e93;
	case 20120ULL: goto x86_l_4e98;
	case 20123ULL: goto x86_l_4e9b;
	case 20125ULL: goto x86_l_4e9d;
	case 20128ULL: goto x86_l_4ea0;
	case 20133ULL: goto x86_l_4ea5;
	case 20135ULL: goto x86_l_4ea7;
	case 20138ULL: goto x86_l_4eaa;
	case 20140ULL: goto x86_l_4eac;
	case 20145ULL: goto x86_l_4eb1;
	case 20148ULL: goto x86_l_4eb4;
	case 20150ULL: goto x86_l_4eb6;
	case 20155ULL: goto x86_l_4ebb;
	case 20158ULL: goto x86_l_4ebe;
	case 20163ULL: goto x86_l_4ec3;
	case 20165ULL: goto x86_l_4ec5;
	case 20167ULL: goto x86_l_4ec7;
	case 20174ULL: goto x86_l_4ece;
	case 20176ULL: goto x86_l_4ed0;
	case 20177ULL: goto x86_l_4ed1;
	case 20182ULL: goto x86_l_4ed6;
	case 20184ULL: goto x86_l_4ed8;
	case 20186ULL: goto x86_l_4eda;
	case 20193ULL: goto x86_l_4ee1;
	case 20195ULL: goto x86_l_4ee3;
	case 20198ULL: goto x86_l_4ee6;
	case 20204ULL: goto x86_l_4eec;
	case 20207ULL: goto x86_l_4eef;
	case 20212ULL: goto x86_l_4ef4;
	case 20218ULL: goto x86_l_4efa;
	case 20221ULL: goto x86_l_4efd;
	case 20227ULL: goto x86_l_4f03;
	case 20233ULL: goto x86_l_4f09;
	case 20238ULL: goto x86_l_4f0e;
	case 20241ULL: goto x86_l_4f11;
	case 20246ULL: goto x86_l_4f16;
	case 20251ULL: goto x86_l_4f1b;
	case 20256ULL: goto x86_l_4f20;
	case 20258ULL: goto x86_l_4f22;
	case 20263ULL: goto x86_l_4f27;
	case 20265ULL: goto x86_l_4f29;
	case 20271ULL: goto x86_l_4f2f;
	case 20273ULL: goto x86_l_4f31;
	case 20278ULL: goto x86_l_4f36;
	case 20285ULL: goto x86_l_4f3d;
	case 20292ULL: goto x86_l_4f44;
	case 20298ULL: goto x86_l_4f4a;
	case 20300ULL: goto x86_l_4f4c;
	case 20303ULL: goto x86_l_4f4f;
	case 20309ULL: goto x86_l_4f55;
	case 20312ULL: goto x86_l_4f58;
	case 20318ULL: goto x86_l_4f5e;
	case 20321ULL: goto x86_l_4f61;
	case 20327ULL: goto x86_l_4f67;
	case 20335ULL: goto x86_l_4f6f;
	case 20338ULL: goto x86_l_4f72;
	case 20344ULL: goto x86_l_4f78;
	case 20349ULL: goto x86_l_4f7d;
	case 20352ULL: goto x86_l_4f80;
	case 20358ULL: goto x86_l_4f86;
	case 20363ULL: goto x86_l_4f8b;
	case 20366ULL: goto x86_l_4f8e;
	case 20372ULL: goto x86_l_4f94;
	case 20377ULL: goto x86_l_4f99;
	case 20380ULL: goto x86_l_4f9c;
	case 20385ULL: goto x86_l_4fa1;
	case 20391ULL: goto x86_l_4fa7;
	case 20394ULL: goto x86_l_4faa;
	case 20400ULL: goto x86_l_4fb0;
	case 20406ULL: goto x86_l_4fb6;
	case 20411ULL: goto x86_l_4fbb;
	case 20414ULL: goto x86_l_4fbe;
	case 20419ULL: goto x86_l_4fc3;
	case 20422ULL: goto x86_l_4fc6;
	case 20427ULL: goto x86_l_4fcb;
	case 20432ULL: goto x86_l_4fd0;
	case 20435ULL: goto x86_l_4fd3;
	case 20437ULL: goto x86_l_4fd5;
	case 20439ULL: goto x86_l_4fd7;
	case 20445ULL: goto x86_l_4fdd;
	case 20450ULL: goto x86_l_4fe2;
	case 20455ULL: goto x86_l_4fe7;
	case 20462ULL: goto x86_l_4fee;
	case 20467ULL: goto x86_l_4ff3;
	case 20470ULL: goto x86_l_4ff6;
	case 20472ULL: goto x86_l_4ff8;
	case 20475ULL: goto x86_l_4ffb;
	case 20481ULL: goto x86_l_5001;
	case 20483ULL: goto x86_l_5003;
	case 20489ULL: goto x86_l_5009;
	case 20492ULL: goto x86_l_500c;
	case 20495ULL: goto x86_l_500f;
	case 20501ULL: goto x86_l_5015;
	case 20506ULL: goto x86_l_501a;
	case 20509ULL: goto x86_l_501d;
	case 20515ULL: goto x86_l_5023;
	case 20523ULL: goto x86_l_502b;
	case 20526ULL: goto x86_l_502e;
	case 20532ULL: goto x86_l_5034;
	case 20537ULL: goto x86_l_5039;
	case 20540ULL: goto x86_l_503c;
	case 20546ULL: goto x86_l_5042;
	case 20551ULL: goto x86_l_5047;
	case 20554ULL: goto x86_l_504a;
	case 20560ULL: goto x86_l_5050;
	case 20568ULL: goto x86_l_5058;
	case 20571ULL: goto x86_l_505b;
	case 20577ULL: goto x86_l_5061;
	case 20582ULL: goto x86_l_5066;
	case 20585ULL: goto x86_l_5069;
	case 20591ULL: goto x86_l_506f;
	case 20596ULL: goto x86_l_5074;
	case 20603ULL: goto x86_l_507b;
	case 20608ULL: goto x86_l_5080;
	case 20615ULL: goto x86_l_5087;
	case 20622ULL: goto x86_l_508e;
	case 20629ULL: goto x86_l_5095;
	case 20634ULL: goto x86_l_509a;
	case 20639ULL: goto x86_l_509f;
	case 20643ULL: goto x86_l_50a3;
	case 20645ULL: goto x86_l_50a5;
	case 20651ULL: goto x86_l_50ab;
	case 20657ULL: goto x86_l_50b1;
	case 20660ULL: goto x86_l_50b4;
	case 20665ULL: goto x86_l_50b9;
	case 20668ULL: goto x86_l_50bc;
	case 20673ULL: goto x86_l_50c1;
	case 20678ULL: goto x86_l_50c6;
	case 20680ULL: goto x86_l_50c8;
	case 20682ULL: goto x86_l_50ca;
	case 20684ULL: goto x86_l_50cc;
	case 20690ULL: goto x86_l_50d2;
	case 20695ULL: goto x86_l_50d7;
	case 20698ULL: goto x86_l_50da;
	case 20703ULL: goto x86_l_50df;
	case 20708ULL: goto x86_l_50e4;
	case 20713ULL: goto x86_l_50e9;
	case 20716ULL: goto x86_l_50ec;
	case 20718ULL: goto x86_l_50ee;
	case 20720ULL: goto x86_l_50f0;
	case 20726ULL: goto x86_l_50f6;
	case 20728ULL: goto x86_l_50f8;
	case 20731ULL: goto x86_l_50fb;
	case 20736ULL: goto x86_l_5100;
	case 20738ULL: goto x86_l_5102;
	case 20741ULL: goto x86_l_5105;
	case 20749ULL: goto x86_l_510d;
	case 20755ULL: goto x86_l_5113;
	case 20762ULL: goto x86_l_511a;
	case 20765ULL: goto x86_l_511d;
	case 20771ULL: goto x86_l_5123;
	case 20774ULL: goto x86_l_5126;
	case 20779ULL: goto x86_l_512b;
	case 20786ULL: goto x86_l_5132;
	case 20788ULL: goto x86_l_5134;
	case 20794ULL: goto x86_l_513a;
	case 20797ULL: goto x86_l_513d;
	case 20799ULL: goto x86_l_513f;
	case 20804ULL: goto x86_l_5144;
	case 20809ULL: goto x86_l_5149;
	case 20814ULL: goto x86_l_514e;
	case 20819ULL: goto x86_l_5153;
	case 20821ULL: goto x86_l_5155;
	case 20826ULL: goto x86_l_515a;
	case 20828ULL: goto x86_l_515c;
	case 20834ULL: goto x86_l_5162;
	case 20842ULL: goto x86_l_516a;
	case 20848ULL: goto x86_l_5170;
	case 20854ULL: goto x86_l_5176;
	case 20859ULL: goto x86_l_517b;
	case 20867ULL: goto x86_l_5183;
	case 20869ULL: goto x86_l_5185;
	case 20874ULL: goto x86_l_518a;
	case 20879ULL: goto x86_l_518f;
	case 20884ULL: goto x86_l_5194;
	case 20889ULL: goto x86_l_5199;
	case 20891ULL: goto x86_l_519b;
	case 20896ULL: goto x86_l_51a0;
	case 20898ULL: goto x86_l_51a2;
	case 20904ULL: goto x86_l_51a8;
	case 20912ULL: goto x86_l_51b0;
	case 20918ULL: goto x86_l_51b6;
	case 20924ULL: goto x86_l_51bc;
	case 20929ULL: goto x86_l_51c1;
	case 20937ULL: goto x86_l_51c9;
	case 20939ULL: goto x86_l_51cb;
	case 20944ULL: goto x86_l_51d0;
	case 20949ULL: goto x86_l_51d5;
	case 20954ULL: goto x86_l_51da;
	case 20959ULL: goto x86_l_51df;
	case 20961ULL: goto x86_l_51e1;
	case 20966ULL: goto x86_l_51e6;
	case 20968ULL: goto x86_l_51e8;
	case 20974ULL: goto x86_l_51ee;
	case 20982ULL: goto x86_l_51f6;
	case 20988ULL: goto x86_l_51fc;
	case 20994ULL: goto x86_l_5202;
	case 20999ULL: goto x86_l_5207;
	case 21007ULL: goto x86_l_520f;
	case 21009ULL: goto x86_l_5211;
	case 21014ULL: goto x86_l_5216;
	case 21019ULL: goto x86_l_521b;
	case 21024ULL: goto x86_l_5220;
	case 21029ULL: goto x86_l_5225;
	case 21031ULL: goto x86_l_5227;
	case 21036ULL: goto x86_l_522c;
	case 21038ULL: goto x86_l_522e;
	case 21044ULL: goto x86_l_5234;
	case 21052ULL: goto x86_l_523c;
	case 21058ULL: goto x86_l_5242;
	case 21064ULL: goto x86_l_5248;
	case 21069ULL: goto x86_l_524d;
	case 21077ULL: goto x86_l_5255;
	case 21079ULL: goto x86_l_5257;
	case 21084ULL: goto x86_l_525c;
	case 21089ULL: goto x86_l_5261;
	case 21094ULL: goto x86_l_5266;
	case 21099ULL: goto x86_l_526b;
	case 21101ULL: goto x86_l_526d;
	case 21106ULL: goto x86_l_5272;
	case 21108ULL: goto x86_l_5274;
	case 21114ULL: goto x86_l_527a;
	case 21122ULL: goto x86_l_5282;
	case 21128ULL: goto x86_l_5288;
	case 21134ULL: goto x86_l_528e;
	case 21139ULL: goto x86_l_5293;
	case 21147ULL: goto x86_l_529b;
	case 21149ULL: goto x86_l_529d;
	case 21154ULL: goto x86_l_52a2;
	case 21159ULL: goto x86_l_52a7;
	case 21164ULL: goto x86_l_52ac;
	case 21169ULL: goto x86_l_52b1;
	case 21171ULL: goto x86_l_52b3;
	case 21176ULL: goto x86_l_52b8;
	case 21178ULL: goto x86_l_52ba;
	case 21184ULL: goto x86_l_52c0;
	case 21192ULL: goto x86_l_52c8;
	case 21198ULL: goto x86_l_52ce;
	case 21204ULL: goto x86_l_52d4;
	case 21209ULL: goto x86_l_52d9;
	case 21217ULL: goto x86_l_52e1;
	case 21219ULL: goto x86_l_52e3;
	case 21224ULL: goto x86_l_52e8;
	case 21229ULL: goto x86_l_52ed;
	case 21234ULL: goto x86_l_52f2;
	case 21239ULL: goto x86_l_52f7;
	case 21241ULL: goto x86_l_52f9;
	case 21243ULL: goto x86_l_52fb;
	case 21249ULL: goto x86_l_5301;
	case 21254ULL: goto x86_l_5306;
	case 21262ULL: goto x86_l_530e;
	case 21268ULL: goto x86_l_5314;
	case 21274ULL: goto x86_l_531a;
	case 21279ULL: goto x86_l_531f;
	case 21287ULL: goto x86_l_5327;
	case 21289ULL: goto x86_l_5329;
	case 21294ULL: goto x86_l_532e;
	case 21299ULL: goto x86_l_5333;
	case 21304ULL: goto x86_l_5338;
	case 21309ULL: goto x86_l_533d;
	case 21311ULL: goto x86_l_533f;
	case 21313ULL: goto x86_l_5341;
	case 21319ULL: goto x86_l_5347;
	case 21324ULL: goto x86_l_534c;
	case 21332ULL: goto x86_l_5354;
	case 21338ULL: goto x86_l_535a;
	case 21344ULL: goto x86_l_5360;
	case 21349ULL: goto x86_l_5365;
	case 21357ULL: goto x86_l_536d;
	case 21359ULL: goto x86_l_536f;
	case 21364ULL: goto x86_l_5374;
	case 21369ULL: goto x86_l_5379;
	case 21374ULL: goto x86_l_537e;
	case 21379ULL: goto x86_l_5383;
	case 21381ULL: goto x86_l_5385;
	case 21383ULL: goto x86_l_5387;
	case 21389ULL: goto x86_l_538d;
	case 21394ULL: goto x86_l_5392;
	case 21402ULL: goto x86_l_539a;
	case 21408ULL: goto x86_l_53a0;
	case 21414ULL: goto x86_l_53a6;
	case 21419ULL: goto x86_l_53ab;
	case 21427ULL: goto x86_l_53b3;
	case 21433ULL: goto x86_l_53b9;
	case 21438ULL: goto x86_l_53be;
	case 21443ULL: goto x86_l_53c3;
	case 21446ULL: goto x86_l_53c6;
	case 21448ULL: goto x86_l_53c8;
	case 21453ULL: goto x86_l_53cd;
	case 21458ULL: goto x86_l_53d2;
	case 21463ULL: goto x86_l_53d7;
	case 21468ULL: goto x86_l_53dc;
	case 21470ULL: goto x86_l_53de;
	case 21475ULL: goto x86_l_53e3;
	case 21477ULL: goto x86_l_53e5;
	case 21483ULL: goto x86_l_53eb;
	case 21491ULL: goto x86_l_53f3;
	case 21497ULL: goto x86_l_53f9;
	case 21503ULL: goto x86_l_53ff;
	case 21508ULL: goto x86_l_5404;
	case 21516ULL: goto x86_l_540c;
	case 21518ULL: goto x86_l_540e;
	case 21523ULL: goto x86_l_5413;
	case 21528ULL: goto x86_l_5418;
	case 21533ULL: goto x86_l_541d;
	case 21538ULL: goto x86_l_5422;
	case 21540ULL: goto x86_l_5424;
	case 21545ULL: goto x86_l_5429;
	case 21547ULL: goto x86_l_542b;
	case 21553ULL: goto x86_l_5431;
	case 21561ULL: goto x86_l_5439;
	case 21567ULL: goto x86_l_543f;
	case 21573ULL: goto x86_l_5445;
	case 21578ULL: goto x86_l_544a;
	case 21586ULL: goto x86_l_5452;
	case 21588ULL: goto x86_l_5454;
	case 21593ULL: goto x86_l_5459;
	case 21598ULL: goto x86_l_545e;
	case 21603ULL: goto x86_l_5463;
	case 21608ULL: goto x86_l_5468;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4d91:
	/* 0x4d91: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4d96:
	/* 0x4d96: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d9b:
	/* 0x4d9b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4da0:
	/* 0x4da0: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_4da3:
	/* 0x4da3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4da5:
	/* 0x4da5: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_4da8:
	/* 0x4da8: jne    4eb6 <generic_sleepable_preload+0x4eb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4eb6;
	}
x86_l_4dae:
	/* 0x4dae: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4db3:
	/* 0x4db3: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4db8:
	/* 0x4db8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dba:
	/* 0x4dba: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4dbf:
	/* 0x4dbf: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_4dc7:
	/* 0x4dc7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4dcc:
	/* 0x4dcc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_4dd3:
	/* 0x4dd3: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4dd8:
	/* 0x4dd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dda:
	/* 0x4dda: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4ddd:
	/* 0x4ddd: je     4eb6 <generic_sleepable_preload+0x4eb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4eb6;
	}
x86_l_4de3:
	/* 0x4de3: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_4de9:
	/* 0x4de9: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_4dec:
	/* 0x4dec: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_4df3:
	/* 0x4df3: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4df8:
	/* 0x4df8: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_4dfb:
	/* 0x4dfb: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_4dfe:
	/* 0x4dfe: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4e01:
	/* 0x4e01: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e03:
	/* 0x4e03: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4e06:
	/* 0x4e06: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e0b:
	/* 0x4e0b: jmp    4e77 <generic_sleepable_preload+0x4e77> */
	goto x86_l_4e77;
x86_l_4e0d:
	/* 0x4e0d: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4e12:
	/* 0x4e12: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e15:
	/* 0x4e15: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_4e18:
	/* 0x4e18: jne    4ebb <generic_sleepable_preload+0x4ebb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4ebb;
	}
x86_l_4e1e:
	/* 0x4e1e: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e23:
	/* 0x4e23: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4e28:
	/* 0x4e28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e2a:
	/* 0x4e2a: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e2f:
	/* 0x4e2f: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4e37:
	/* 0x4e37: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e3c:
	/* 0x4e3c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_4e43:
	/* 0x4e43: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e48:
	/* 0x4e48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e4a:
	/* 0x4e4a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e4d:
	/* 0x4e4d: je     4eb6 <generic_sleepable_preload+0x4eb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4eb6;
	}
x86_l_4e4f:
	/* 0x4e4f: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_4e55:
	/* 0x4e55: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_4e58:
	/* 0x4e58: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_4e5f:
	/* 0x4e5f: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e64:
	/* 0x4e64: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_4e67:
	/* 0x4e67: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_4e6a:
	/* 0x4e6a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4e6d:
	/* 0x4e6d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e6f:
	/* 0x4e6f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4e72:
	/* 0x4e72: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e77:
	/* 0x4e77: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_4e7a:
	/* 0x4e7a: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_4e7d:
	/* 0x4e7d: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_4e80:
	/* 0x4e80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e82:
	/* 0x4e82: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e85:
	/* 0x4e85: je     4eb6 <generic_sleepable_preload+0x4eb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4eb6;
	}
x86_l_4e87:
	/* 0x4e87: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_4e8a:
	/* 0x4e8a: je     4eb4 <generic_sleepable_preload+0x4eb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4eb4;
	}
x86_l_4e8c:
	/* 0x4e8c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4e8f:
	/* 0x4e8f: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4e93:
	/* 0x4e93: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4e98:
	/* 0x4e98: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_4e9b:
	/* 0x4e9b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e9d:
	/* 0x4e9d: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_4ea0:
	/* 0x4ea0: call   4ea5 <generic_sleepable_preload+0x4ea5> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_4ea5:
	/* 0x4ea5: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_4ea7:
	/* 0x4ea7: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_4eaa:
	/* 0x4eaa: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4eac:
	/* 0x4eac: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_4eb1:
	/* 0x4eb1: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_4eb4:
	/* 0x4eb4: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4eb6:
	/* 0x4eb6: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ebb:
	/* 0x4ebb: mov    eax,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4ebe:
	/* 0x4ebe: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_4ec3:
	/* 0x4ec3: jne    4ed6 <generic_sleepable_preload+0x4ed6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4ed6;
	}
x86_l_4ec5:
	/* 0x4ec5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ec7:
	/* 0x4ec7: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_4ece:
	/* 0x4ece: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_4ed0:
	/* 0x4ed0: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_4ed1:
	/* 0x4ed1: jmp    6128 <generic_sleepable_preload+0x6128> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_4ed6:
	/* 0x4ed6: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_4ed8:
	/* 0x4ed8: js     4f36 <generic_sleepable_preload+0x4f36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4f36;
	}
x86_l_4eda:
	/* 0x4eda: movzx  ecx,BYTE PTR [rdi+0x271] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 625ULL);
x86_l_4ee1:
	/* 0x4ee1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ee3:
	/* 0x4ee3: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_4ee6:
	/* 0x4ee6: jg     4f99 <generic_sleepable_preload+0x4f99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4f99;
	}
x86_l_4eec:
	/* 0x4eec: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4eef:
	/* 0x4eef: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4ef4:
	/* 0x4ef4: je     5074 <generic_sleepable_preload+0x5074> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5074;
	}
x86_l_4efa:
	/* 0x4efa: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_4efd:
	/* 0x4efd: jne    50fb <generic_sleepable_preload+0x50fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_50fb;
	}
x86_l_4f03:
	/* 0x4f03: mov    eax,DWORD PTR [rdi+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_4f09:
	/* 0x4f09: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4f0e:
	/* 0x4f0e: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4f11:
	/* 0x4f11: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f16:
	/* 0x4f16: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4f1b:
	/* 0x4f1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f20:
	/* 0x4f20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f22:
	/* 0x4f22: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4f27:
	/* 0x4f27: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f29:
	/* 0x4f29: je     5080 <generic_sleepable_preload+0x5080> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5080;
	}
x86_l_4f2f:
	/* 0x4f2f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f31:
	/* 0x4f31: jmp    50fb <generic_sleepable_preload+0x50fb> */
	goto x86_l_50fb;
x86_l_4f36:
	/* 0x4f36: movzx  ecx,BYTE PTR [rdi+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_4f3d:
	/* 0x4f3d: movzx  eax,WORD PTR [rdi+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_4f44:
	/* 0x4f44: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_4f4a:
	/* 0x4f4a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f4c:
	/* 0x4f4c: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4f4f:
	/* 0x4f4f: jle    4ff3 <generic_sleepable_preload+0x4ff3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4ff3;
	}
x86_l_4f55:
	/* 0x4f55: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_4f58:
	/* 0x4f58: jle    501a <generic_sleepable_preload+0x501a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_501a;
	}
x86_l_4f5e:
	/* 0x4f5e: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4f61:
	/* 0x4f61: jle    56c1 <generic_sleepable_preload+0x56c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 22209ULL;
	}
x86_l_4f67:
	/* 0x4f67: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4f6f:
	/* 0x4f6f: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_4f72:
	/* 0x4f72: je     56e9 <generic_sleepable_preload+0x56e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22249ULL;
	}
x86_l_4f78:
	/* 0x4f78: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4f7d:
	/* 0x4f7d: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_4f80:
	/* 0x4f80: je     56e9 <generic_sleepable_preload+0x56e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22249ULL;
	}
x86_l_4f86:
	/* 0x4f86: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4f8b:
	/* 0x4f8b: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_4f8e:
	/* 0x4f8e: je     56e9 <generic_sleepable_preload+0x56e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22249ULL;
	}
x86_l_4f94:
	/* 0x4f94: jmp    56fc <generic_sleepable_preload+0x56fc> */
	return 22268ULL;
x86_l_4f99:
	/* 0x4f99: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_4f9c:
	/* 0x4f9c: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4fa1:
	/* 0x4fa1: je     50a5 <generic_sleepable_preload+0x50a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_50a5;
	}
x86_l_4fa7:
	/* 0x4fa7: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_4faa:
	/* 0x4faa: jne    50fb <generic_sleepable_preload+0x50fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_50fb;
	}
x86_l_4fb0:
	/* 0x4fb0: mov    eax,DWORD PTR [rdi+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_4fb6:
	/* 0x4fb6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4fbb:
	/* 0x4fbb: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4fbe:
	/* 0x4fbe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4fc3:
	/* 0x4fc3: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_4fc6:
	/* 0x4fc6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4fcb:
	/* 0x4fcb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fd0:
	/* 0x4fd0: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4fd3:
	/* 0x4fd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fd5:
	/* 0x4fd5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4fd7:
	/* 0x4fd7: jne    50f6 <generic_sleepable_preload+0x50f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_50f6;
	}
x86_l_4fdd:
	/* 0x4fdd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4fe2:
	/* 0x4fe2: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4fe7:
	/* 0x4fe7: add    rdx,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 608ULL);
x86_l_4fee:
	/* 0x4fee: jmp    5cb5 <generic_sleepable_preload+0x5cb5> */
	return 23733ULL;
x86_l_4ff3:
	/* 0x4ff3: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4ff6:
	/* 0x4ff6: jg     5047 <generic_sleepable_preload+0x5047> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_5047;
	}
x86_l_4ff8:
	/* 0x4ff8: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4ffb:
	/* 0x4ffb: jg     5692 <generic_sleepable_preload+0x5692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 22162ULL;
	}
x86_l_5001:
	/* 0x5001: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_5003:
	/* 0x5003: je     56e4 <generic_sleepable_preload+0x56e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22244ULL;
	}
x86_l_5009:
	/* 0x5009: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_500c:
	/* 0x500c: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_500f:
	/* 0x500f: je     56e9 <generic_sleepable_preload+0x56e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22249ULL;
	}
x86_l_5015:
	/* 0x5015: jmp    56fc <generic_sleepable_preload+0x56fc> */
	return 22268ULL;
x86_l_501a:
	/* 0x501a: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_501d:
	/* 0x501d: jg     5679 <generic_sleepable_preload+0x5679> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 22137ULL;
	}
x86_l_5023:
	/* 0x5023: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_502b:
	/* 0x502b: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_502e:
	/* 0x502e: je     56e9 <generic_sleepable_preload+0x56e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22249ULL;
	}
x86_l_5034:
	/* 0x5034: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5039:
	/* 0x5039: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_503c:
	/* 0x503c: je     56e9 <generic_sleepable_preload+0x56e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22249ULL;
	}
x86_l_5042:
	/* 0x5042: jmp    56fc <generic_sleepable_preload+0x56fc> */
	return 22268ULL;
x86_l_5047:
	/* 0x5047: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_504a:
	/* 0x504a: jg     56a8 <generic_sleepable_preload+0x56a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 22184ULL;
	}
x86_l_5050:
	/* 0x5050: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5058:
	/* 0x5058: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_505b:
	/* 0x505b: je     56e9 <generic_sleepable_preload+0x56e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22249ULL;
	}
x86_l_5061:
	/* 0x5061: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5066:
	/* 0x5066: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_5069:
	/* 0x5069: je     56e9 <generic_sleepable_preload+0x56e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22249ULL;
	}
x86_l_506f:
	/* 0x506f: jmp    56fc <generic_sleepable_preload+0x56fc> */
	return 22268ULL;
x86_l_5074:
	/* 0x5074: mov    rax,QWORD PTR [rdi+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_507b:
	/* 0x507b: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5080:
	/* 0x5080: movzx  eax,BYTE PTR [rdi+0x270] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 624ULL);
x86_l_5087:
	/* 0x5087: shlx   rcx,QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((32ULL << 32) | X86_ALU_SHL));
x86_l_508e:
	/* 0x508e: cmp    BYTE PTR [rdi+0x272],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2688649527296ULL);
x86_l_5095:
	/* 0x5095: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_509a:
	/* 0x509a: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_509f:
	/* 0x509f: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_50a3:
	/* 0x50a3: jmp    50fb <generic_sleepable_preload+0x50fb> */
	goto x86_l_50fb;
x86_l_50a5:
	/* 0x50a5: mov    edx,DWORD PTR [rdi+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_50ab:
	/* 0x50ab: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_50b1:
	/* 0x50b1: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_50b4:
	/* 0x50b4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_50b9:
	/* 0x50b9: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_50bc:
	/* 0x50bc: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_50c1:
	/* 0x50c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50c6:
	/* 0x50c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50c8:
	/* 0x50c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_50ca:
	/* 0x50ca: jne    50f6 <generic_sleepable_preload+0x50f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_50f6;
	}
x86_l_50cc:
	/* 0x50cc: mov    eax,DWORD PTR [rbx+0x26c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 620ULL);
x86_l_50d2:
	/* 0x50d2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_50d7:
	/* 0x50d7: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_50da:
	/* 0x50da: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_50df:
	/* 0x50df: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50e4:
	/* 0x50e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50e9:
	/* 0x50e9: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_50ec:
	/* 0x50ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50ee:
	/* 0x50ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_50f0:
	/* 0x50f0: je     5c93 <generic_sleepable_preload+0x5c93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23699ULL;
	}
x86_l_50f6:
	/* 0x50f6: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_50f8:
	/* 0x50f8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_50fb:
	/* 0x50fb: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5100:
	/* 0x5100: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5102:
	/* 0x5102: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_5105:
	/* 0x5105: cmp    WORD PTR [rdi+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_510d:
	/* 0x510d: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_5113:
	/* 0x5113: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_511a:
	/* 0x511a: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_511d:
	/* 0x511d: mov    edx,DWORD PTR [rdi+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_5123:
	/* 0x5123: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5126:
	/* 0x5126: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_512b:
	/* 0x512b: movzx  eax,WORD PTR [rdi+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_5132:
	/* 0x5132: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_5134:
	/* 0x5134: je     53c3 <generic_sleepable_preload+0x53c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_53c3;
	}
x86_l_513a:
	/* 0x513a: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_513d:
	/* 0x513d: je     5162 <generic_sleepable_preload+0x5162> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5162;
	}
x86_l_513f:
	/* 0x513f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5144:
	/* 0x5144: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5149:
	/* 0x5149: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_514e:
	/* 0x514e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5153:
	/* 0x5153: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5155:
	/* 0x5155: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_515a:
	/* 0x515a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_515c:
	/* 0x515c: js     566f <generic_sleepable_preload+0x566f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 22127ULL;
	}
x86_l_5162:
	/* 0x5162: cmp    WORD PTR [rdi+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_516a:
	/* 0x516a: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_5170:
	/* 0x5170: mov    eax,DWORD PTR [rdi+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_5176:
	/* 0x5176: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_517b:
	/* 0x517b: cmp    WORD PTR [rdi+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_5183:
	/* 0x5183: je     51a8 <generic_sleepable_preload+0x51a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_51a8;
	}
x86_l_5185:
	/* 0x5185: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_518a:
	/* 0x518a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_518f:
	/* 0x518f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5194:
	/* 0x5194: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5199:
	/* 0x5199: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_519b:
	/* 0x519b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_51a0:
	/* 0x51a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_51a2:
	/* 0x51a2: js     56da <generic_sleepable_preload+0x56da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 22234ULL;
	}
x86_l_51a8:
	/* 0x51a8: cmp    WORD PTR [rdi+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_51b0:
	/* 0x51b0: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_51b6:
	/* 0x51b6: mov    eax,DWORD PTR [rdi+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_51bc:
	/* 0x51bc: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_51c1:
	/* 0x51c1: cmp    WORD PTR [rdi+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_51c9:
	/* 0x51c9: je     51ee <generic_sleepable_preload+0x51ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_51ee;
	}
x86_l_51cb:
	/* 0x51cb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_51d0:
	/* 0x51d0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51d5:
	/* 0x51d5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51da:
	/* 0x51da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51df:
	/* 0x51df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51e1:
	/* 0x51e1: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_51e6:
	/* 0x51e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_51e8:
	/* 0x51e8: js     5c82 <generic_sleepable_preload+0x5c82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23682ULL;
	}
x86_l_51ee:
	/* 0x51ee: cmp    WORD PTR [rdi+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_51f6:
	/* 0x51f6: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_51fc:
	/* 0x51fc: mov    eax,DWORD PTR [rdi+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_5202:
	/* 0x5202: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5207:
	/* 0x5207: cmp    WORD PTR [rdi+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_520f:
	/* 0x520f: je     5234 <generic_sleepable_preload+0x5234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5234;
	}
x86_l_5211:
	/* 0x5211: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5216:
	/* 0x5216: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_521b:
	/* 0x521b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5220:
	/* 0x5220: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5225:
	/* 0x5225: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5227:
	/* 0x5227: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_522c:
	/* 0x522c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_522e:
	/* 0x522e: js     5cd3 <generic_sleepable_preload+0x5cd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23763ULL;
	}
x86_l_5234:
	/* 0x5234: cmp    WORD PTR [rdi+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_523c:
	/* 0x523c: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_5242:
	/* 0x5242: mov    eax,DWORD PTR [rdi+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_5248:
	/* 0x5248: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_524d:
	/* 0x524d: cmp    WORD PTR [rdi+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_5255:
	/* 0x5255: je     527a <generic_sleepable_preload+0x527a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_527a;
	}
x86_l_5257:
	/* 0x5257: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_525c:
	/* 0x525c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5261:
	/* 0x5261: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5266:
	/* 0x5266: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_526b:
	/* 0x526b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_526d:
	/* 0x526d: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5272:
	/* 0x5272: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5274:
	/* 0x5274: js     5ce4 <generic_sleepable_preload+0x5ce4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23780ULL;
	}
x86_l_527a:
	/* 0x527a: cmp    WORD PTR [rdi+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_5282:
	/* 0x5282: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_5288:
	/* 0x5288: mov    eax,DWORD PTR [rdi+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_528e:
	/* 0x528e: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5293:
	/* 0x5293: cmp    WORD PTR [rdi+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_529b:
	/* 0x529b: je     52c0 <generic_sleepable_preload+0x52c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_52c0;
	}
x86_l_529d:
	/* 0x529d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_52a2:
	/* 0x52a2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52a7:
	/* 0x52a7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52ac:
	/* 0x52ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52b1:
	/* 0x52b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52b3:
	/* 0x52b3: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_52b8:
	/* 0x52b8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52ba:
	/* 0x52ba: js     5cf5 <generic_sleepable_preload+0x5cf5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23797ULL;
	}
x86_l_52c0:
	/* 0x52c0: cmp    WORD PTR [rdi+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_52c8:
	/* 0x52c8: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_52ce:
	/* 0x52ce: mov    eax,DWORD PTR [rdi+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_52d4:
	/* 0x52d4: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_52d9:
	/* 0x52d9: cmp    WORD PTR [rdi+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_52e1:
	/* 0x52e1: je     5301 <generic_sleepable_preload+0x5301> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5301;
	}
x86_l_52e3:
	/* 0x52e3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_52e8:
	/* 0x52e8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52ed:
	/* 0x52ed: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52f2:
	/* 0x52f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52f7:
	/* 0x52f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52f9:
	/* 0x52f9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52fb:
	/* 0x52fb: js     5e16 <generic_sleepable_preload+0x5e16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24086ULL;
	}
x86_l_5301:
	/* 0x5301: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5306:
	/* 0x5306: cmp    WORD PTR [rdi+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_530e:
	/* 0x530e: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_5314:
	/* 0x5314: mov    eax,DWORD PTR [rdi+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_531a:
	/* 0x531a: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_531f:
	/* 0x531f: cmp    WORD PTR [rdi+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_5327:
	/* 0x5327: je     5347 <generic_sleepable_preload+0x5347> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5347;
	}
x86_l_5329:
	/* 0x5329: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_532e:
	/* 0x532e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5333:
	/* 0x5333: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5338:
	/* 0x5338: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_533d:
	/* 0x533d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_533f:
	/* 0x533f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5341:
	/* 0x5341: js     5ed8 <generic_sleepable_preload+0x5ed8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24280ULL;
	}
x86_l_5347:
	/* 0x5347: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_534c:
	/* 0x534c: cmp    WORD PTR [rdi+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_5354:
	/* 0x5354: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_535a:
	/* 0x535a: mov    eax,DWORD PTR [rdi+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_5360:
	/* 0x5360: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5365:
	/* 0x5365: cmp    WORD PTR [rdi+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_536d:
	/* 0x536d: je     538d <generic_sleepable_preload+0x538d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_538d;
	}
x86_l_536f:
	/* 0x536f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5374:
	/* 0x5374: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5379:
	/* 0x5379: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_537e:
	/* 0x537e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5383:
	/* 0x5383: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5385:
	/* 0x5385: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5387:
	/* 0x5387: js     5f90 <generic_sleepable_preload+0x5f90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24464ULL;
	}
x86_l_538d:
	/* 0x538d: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5392:
	/* 0x5392: cmp    WORD PTR [rdi+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_539a:
	/* 0x539a: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_53a0:
	/* 0x53a0: mov    eax,DWORD PTR [rdi+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_53a6:
	/* 0x53a6: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_53ab:
	/* 0x53ab: cmp    WORD PTR [rdi+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_53b3:
	/* 0x53b3: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_53b9:
	/* 0x53b9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_53be:
	/* 0x53be: jmp    5647 <generic_sleepable_preload+0x5647> */
	return 22087ULL;
x86_l_53c3:
	/* 0x53c3: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_53c6:
	/* 0x53c6: je     53eb <generic_sleepable_preload+0x53eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_53eb;
	}
x86_l_53c8:
	/* 0x53c8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_53cd:
	/* 0x53cd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53d2:
	/* 0x53d2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53d7:
	/* 0x53d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53dc:
	/* 0x53dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53de:
	/* 0x53de: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_53e3:
	/* 0x53e3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_53e5:
	/* 0x53e5: js     566f <generic_sleepable_preload+0x566f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 22127ULL;
	}
x86_l_53eb:
	/* 0x53eb: cmp    WORD PTR [rdi+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_53f3:
	/* 0x53f3: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_53f9:
	/* 0x53f9: mov    eax,DWORD PTR [rdi+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_53ff:
	/* 0x53ff: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5404:
	/* 0x5404: cmp    WORD PTR [rdi+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_540c:
	/* 0x540c: je     5431 <generic_sleepable_preload+0x5431> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5431;
	}
x86_l_540e:
	/* 0x540e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5413:
	/* 0x5413: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5418:
	/* 0x5418: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_541d:
	/* 0x541d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5422:
	/* 0x5422: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5424:
	/* 0x5424: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5429:
	/* 0x5429: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_542b:
	/* 0x542b: js     56da <generic_sleepable_preload+0x56da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 22234ULL;
	}
x86_l_5431:
	/* 0x5431: cmp    WORD PTR [rdi+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_5439:
	/* 0x5439: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_543f:
	/* 0x543f: mov    eax,DWORD PTR [rdi+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_5445:
	/* 0x5445: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_544a:
	/* 0x544a: cmp    WORD PTR [rdi+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_5452:
	/* 0x5452: je     5477 <generic_sleepable_preload+0x5477> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21623ULL;
	}
x86_l_5454:
	/* 0x5454: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5459:
	/* 0x5459: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_545e:
	/* 0x545e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5463:
	/* 0x5463: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5468:
	/* 0x5468: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 21610ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 21610ULL: goto x86_l_546a;
	case 21615ULL: goto x86_l_546f;
	case 21617ULL: goto x86_l_5471;
	case 21623ULL: goto x86_l_5477;
	case 21631ULL: goto x86_l_547f;
	case 21637ULL: goto x86_l_5485;
	case 21643ULL: goto x86_l_548b;
	case 21648ULL: goto x86_l_5490;
	case 21656ULL: goto x86_l_5498;
	case 21658ULL: goto x86_l_549a;
	case 21663ULL: goto x86_l_549f;
	case 21668ULL: goto x86_l_54a4;
	case 21673ULL: goto x86_l_54a9;
	case 21678ULL: goto x86_l_54ae;
	case 21680ULL: goto x86_l_54b0;
	case 21685ULL: goto x86_l_54b5;
	case 21687ULL: goto x86_l_54b7;
	case 21693ULL: goto x86_l_54bd;
	case 21701ULL: goto x86_l_54c5;
	case 21707ULL: goto x86_l_54cb;
	case 21713ULL: goto x86_l_54d1;
	case 21718ULL: goto x86_l_54d6;
	case 21726ULL: goto x86_l_54de;
	case 21728ULL: goto x86_l_54e0;
	case 21733ULL: goto x86_l_54e5;
	case 21738ULL: goto x86_l_54ea;
	case 21743ULL: goto x86_l_54ef;
	case 21748ULL: goto x86_l_54f4;
	case 21750ULL: goto x86_l_54f6;
	case 21755ULL: goto x86_l_54fb;
	case 21757ULL: goto x86_l_54fd;
	case 21763ULL: goto x86_l_5503;
	case 21771ULL: goto x86_l_550b;
	case 21777ULL: goto x86_l_5511;
	case 21783ULL: goto x86_l_5517;
	case 21788ULL: goto x86_l_551c;
	case 21796ULL: goto x86_l_5524;
	case 21798ULL: goto x86_l_5526;
	case 21803ULL: goto x86_l_552b;
	case 21808ULL: goto x86_l_5530;
	case 21813ULL: goto x86_l_5535;
	case 21818ULL: goto x86_l_553a;
	case 21820ULL: goto x86_l_553c;
	case 21825ULL: goto x86_l_5541;
	case 21827ULL: goto x86_l_5543;
	case 21833ULL: goto x86_l_5549;
	case 21841ULL: goto x86_l_5551;
	case 21847ULL: goto x86_l_5557;
	case 21853ULL: goto x86_l_555d;
	case 21858ULL: goto x86_l_5562;
	case 21866ULL: goto x86_l_556a;
	case 21868ULL: goto x86_l_556c;
	case 21873ULL: goto x86_l_5571;
	case 21878ULL: goto x86_l_5576;
	case 21883ULL: goto x86_l_557b;
	case 21888ULL: goto x86_l_5580;
	case 21890ULL: goto x86_l_5582;
	case 21892ULL: goto x86_l_5584;
	case 21898ULL: goto x86_l_558a;
	case 21903ULL: goto x86_l_558f;
	case 21911ULL: goto x86_l_5597;
	case 21917ULL: goto x86_l_559d;
	case 21923ULL: goto x86_l_55a3;
	case 21928ULL: goto x86_l_55a8;
	case 21936ULL: goto x86_l_55b0;
	case 21938ULL: goto x86_l_55b2;
	case 21943ULL: goto x86_l_55b7;
	case 21948ULL: goto x86_l_55bc;
	case 21953ULL: goto x86_l_55c1;
	case 21958ULL: goto x86_l_55c6;
	case 21960ULL: goto x86_l_55c8;
	case 21962ULL: goto x86_l_55ca;
	case 21968ULL: goto x86_l_55d0;
	case 21973ULL: goto x86_l_55d5;
	case 21981ULL: goto x86_l_55dd;
	case 21987ULL: goto x86_l_55e3;
	case 21993ULL: goto x86_l_55e9;
	case 21998ULL: goto x86_l_55ee;
	case 22006ULL: goto x86_l_55f6;
	case 22008ULL: goto x86_l_55f8;
	case 22013ULL: goto x86_l_55fd;
	case 22018ULL: goto x86_l_5602;
	case 22023ULL: goto x86_l_5607;
	case 22028ULL: goto x86_l_560c;
	case 22030ULL: goto x86_l_560e;
	case 22032ULL: goto x86_l_5610;
	case 22038ULL: goto x86_l_5616;
	case 22043ULL: goto x86_l_561b;
	case 22051ULL: goto x86_l_5623;
	case 22057ULL: goto x86_l_5629;
	case 22063ULL: goto x86_l_562f;
	case 22068ULL: goto x86_l_5634;
	case 22076ULL: goto x86_l_563c;
	case 22082ULL: goto x86_l_5642;
	case 22087ULL: goto x86_l_5647;
	case 22092ULL: goto x86_l_564c;
	case 22097ULL: goto x86_l_5651;
	case 22102ULL: goto x86_l_5656;
	case 22104ULL: goto x86_l_5658;
	case 22109ULL: goto x86_l_565d;
	case 22111ULL: goto x86_l_565f;
	case 22117ULL: goto x86_l_5665;
	case 22122ULL: goto x86_l_566a;
	case 22127ULL: goto x86_l_566f;
	case 22132ULL: goto x86_l_5674;
	case 22137ULL: goto x86_l_5679;
	case 22145ULL: goto x86_l_5681;
	case 22148ULL: goto x86_l_5684;
	case 22150ULL: goto x86_l_5686;
	case 22155ULL: goto x86_l_568b;
	case 22158ULL: goto x86_l_568e;
	case 22160ULL: goto x86_l_5690;
	case 22162ULL: goto x86_l_5692;
	case 22167ULL: goto x86_l_5697;
	case 22170ULL: goto x86_l_569a;
	case 22172ULL: goto x86_l_569c;
	case 22177ULL: goto x86_l_56a1;
	case 22180ULL: goto x86_l_56a4;
	case 22182ULL: goto x86_l_56a6;
	case 22184ULL: goto x86_l_56a8;
	case 22192ULL: goto x86_l_56b0;
	case 22195ULL: goto x86_l_56b3;
	case 22197ULL: goto x86_l_56b5;
	case 22202ULL: goto x86_l_56ba;
	case 22205ULL: goto x86_l_56bd;
	case 22207ULL: goto x86_l_56bf;
	case 22209ULL: goto x86_l_56c1;
	case 22217ULL: goto x86_l_56c9;
	case 22220ULL: goto x86_l_56cc;
	case 22222ULL: goto x86_l_56ce;
	case 22227ULL: goto x86_l_56d3;
	case 22230ULL: goto x86_l_56d6;
	case 22232ULL: goto x86_l_56d8;
	case 22234ULL: goto x86_l_56da;
	case 22239ULL: goto x86_l_56df;
	case 22244ULL: goto x86_l_56e4;
	case 22249ULL: goto x86_l_56e9;
	case 22252ULL: goto x86_l_56ec;
	case 22254ULL: goto x86_l_56ee;
	case 22256ULL: goto x86_l_56f0;
	case 22261ULL: goto x86_l_56f5;
	case 22263ULL: goto x86_l_56f7;
	case 22268ULL: goto x86_l_56fc;
	case 22273ULL: goto x86_l_5701;
	case 22276ULL: goto x86_l_5704;
	case 22278ULL: goto x86_l_5706;
	case 22281ULL: goto x86_l_5709;
	case 22289ULL: goto x86_l_5711;
	case 22295ULL: goto x86_l_5717;
	case 22302ULL: goto x86_l_571e;
	case 22305ULL: goto x86_l_5721;
	case 22311ULL: goto x86_l_5727;
	case 22314ULL: goto x86_l_572a;
	case 22319ULL: goto x86_l_572f;
	case 22326ULL: goto x86_l_5736;
	case 22328ULL: goto x86_l_5738;
	case 22334ULL: goto x86_l_573e;
	case 22337ULL: goto x86_l_5741;
	case 22339ULL: goto x86_l_5743;
	case 22344ULL: goto x86_l_5748;
	case 22349ULL: goto x86_l_574d;
	case 22354ULL: goto x86_l_5752;
	case 22359ULL: goto x86_l_5757;
	case 22361ULL: goto x86_l_5759;
	case 22366ULL: goto x86_l_575e;
	case 22368ULL: goto x86_l_5760;
	case 22374ULL: goto x86_l_5766;
	case 22382ULL: goto x86_l_576e;
	case 22388ULL: goto x86_l_5774;
	case 22394ULL: goto x86_l_577a;
	case 22399ULL: goto x86_l_577f;
	case 22407ULL: goto x86_l_5787;
	case 22409ULL: goto x86_l_5789;
	case 22414ULL: goto x86_l_578e;
	case 22419ULL: goto x86_l_5793;
	case 22424ULL: goto x86_l_5798;
	case 22429ULL: goto x86_l_579d;
	case 22431ULL: goto x86_l_579f;
	case 22436ULL: goto x86_l_57a4;
	case 22438ULL: goto x86_l_57a6;
	case 22444ULL: goto x86_l_57ac;
	case 22452ULL: goto x86_l_57b4;
	case 22458ULL: goto x86_l_57ba;
	case 22464ULL: goto x86_l_57c0;
	case 22469ULL: goto x86_l_57c5;
	case 22477ULL: goto x86_l_57cd;
	case 22479ULL: goto x86_l_57cf;
	case 22484ULL: goto x86_l_57d4;
	case 22489ULL: goto x86_l_57d9;
	case 22494ULL: goto x86_l_57de;
	case 22499ULL: goto x86_l_57e3;
	case 22501ULL: goto x86_l_57e5;
	case 22506ULL: goto x86_l_57ea;
	case 22508ULL: goto x86_l_57ec;
	case 22514ULL: goto x86_l_57f2;
	case 22522ULL: goto x86_l_57fa;
	case 22528ULL: goto x86_l_5800;
	case 22534ULL: goto x86_l_5806;
	case 22539ULL: goto x86_l_580b;
	case 22547ULL: goto x86_l_5813;
	case 22549ULL: goto x86_l_5815;
	case 22554ULL: goto x86_l_581a;
	case 22559ULL: goto x86_l_581f;
	case 22564ULL: goto x86_l_5824;
	case 22569ULL: goto x86_l_5829;
	case 22571ULL: goto x86_l_582b;
	case 22576ULL: goto x86_l_5830;
	case 22578ULL: goto x86_l_5832;
	case 22584ULL: goto x86_l_5838;
	case 22592ULL: goto x86_l_5840;
	case 22598ULL: goto x86_l_5846;
	case 22604ULL: goto x86_l_584c;
	case 22609ULL: goto x86_l_5851;
	case 22617ULL: goto x86_l_5859;
	case 22619ULL: goto x86_l_585b;
	case 22624ULL: goto x86_l_5860;
	case 22629ULL: goto x86_l_5865;
	case 22634ULL: goto x86_l_586a;
	case 22639ULL: goto x86_l_586f;
	case 22641ULL: goto x86_l_5871;
	case 22646ULL: goto x86_l_5876;
	case 22648ULL: goto x86_l_5878;
	case 22654ULL: goto x86_l_587e;
	case 22662ULL: goto x86_l_5886;
	case 22668ULL: goto x86_l_588c;
	case 22674ULL: goto x86_l_5892;
	case 22679ULL: goto x86_l_5897;
	case 22687ULL: goto x86_l_589f;
	case 22689ULL: goto x86_l_58a1;
	case 22694ULL: goto x86_l_58a6;
	case 22699ULL: goto x86_l_58ab;
	case 22704ULL: goto x86_l_58b0;
	case 22709ULL: goto x86_l_58b5;
	case 22711ULL: goto x86_l_58b7;
	case 22716ULL: goto x86_l_58bc;
	case 22718ULL: goto x86_l_58be;
	case 22724ULL: goto x86_l_58c4;
	case 22732ULL: goto x86_l_58cc;
	case 22738ULL: goto x86_l_58d2;
	case 22744ULL: goto x86_l_58d8;
	case 22749ULL: goto x86_l_58dd;
	case 22757ULL: goto x86_l_58e5;
	case 22759ULL: goto x86_l_58e7;
	case 22764ULL: goto x86_l_58ec;
	case 22769ULL: goto x86_l_58f1;
	case 22774ULL: goto x86_l_58f6;
	case 22779ULL: goto x86_l_58fb;
	case 22781ULL: goto x86_l_58fd;
	case 22783ULL: goto x86_l_58ff;
	case 22789ULL: goto x86_l_5905;
	case 22794ULL: goto x86_l_590a;
	case 22802ULL: goto x86_l_5912;
	case 22808ULL: goto x86_l_5918;
	case 22814ULL: goto x86_l_591e;
	case 22819ULL: goto x86_l_5923;
	case 22827ULL: goto x86_l_592b;
	case 22829ULL: goto x86_l_592d;
	case 22834ULL: goto x86_l_5932;
	case 22839ULL: goto x86_l_5937;
	case 22844ULL: goto x86_l_593c;
	case 22849ULL: goto x86_l_5941;
	case 22851ULL: goto x86_l_5943;
	case 22853ULL: goto x86_l_5945;
	case 22859ULL: goto x86_l_594b;
	case 22864ULL: goto x86_l_5950;
	case 22872ULL: goto x86_l_5958;
	case 22878ULL: goto x86_l_595e;
	case 22884ULL: goto x86_l_5964;
	case 22889ULL: goto x86_l_5969;
	case 22897ULL: goto x86_l_5971;
	case 22899ULL: goto x86_l_5973;
	case 22904ULL: goto x86_l_5978;
	case 22909ULL: goto x86_l_597d;
	case 22914ULL: goto x86_l_5982;
	case 22919ULL: goto x86_l_5987;
	case 22921ULL: goto x86_l_5989;
	case 22923ULL: goto x86_l_598b;
	case 22929ULL: goto x86_l_5991;
	case 22934ULL: goto x86_l_5996;
	case 22942ULL: goto x86_l_599e;
	case 22948ULL: goto x86_l_59a4;
	case 22954ULL: goto x86_l_59aa;
	case 22959ULL: goto x86_l_59af;
	case 22967ULL: goto x86_l_59b7;
	case 22973ULL: goto x86_l_59bd;
	case 22978ULL: goto x86_l_59c2;
	case 22983ULL: goto x86_l_59c7;
	case 22986ULL: goto x86_l_59ca;
	case 22988ULL: goto x86_l_59cc;
	case 22993ULL: goto x86_l_59d1;
	case 22998ULL: goto x86_l_59d6;
	case 23003ULL: goto x86_l_59db;
	case 23008ULL: goto x86_l_59e0;
	case 23010ULL: goto x86_l_59e2;
	case 23015ULL: goto x86_l_59e7;
	case 23017ULL: goto x86_l_59e9;
	case 23023ULL: goto x86_l_59ef;
	case 23031ULL: goto x86_l_59f7;
	case 23037ULL: goto x86_l_59fd;
	case 23043ULL: goto x86_l_5a03;
	case 23048ULL: goto x86_l_5a08;
	case 23056ULL: goto x86_l_5a10;
	case 23058ULL: goto x86_l_5a12;
	case 23063ULL: goto x86_l_5a17;
	case 23068ULL: goto x86_l_5a1c;
	case 23073ULL: goto x86_l_5a21;
	case 23078ULL: goto x86_l_5a26;
	case 23080ULL: goto x86_l_5a28;
	case 23085ULL: goto x86_l_5a2d;
	case 23087ULL: goto x86_l_5a2f;
	case 23093ULL: goto x86_l_5a35;
	case 23101ULL: goto x86_l_5a3d;
	case 23107ULL: goto x86_l_5a43;
	case 23113ULL: goto x86_l_5a49;
	case 23118ULL: goto x86_l_5a4e;
	case 23126ULL: goto x86_l_5a56;
	case 23128ULL: goto x86_l_5a58;
	case 23133ULL: goto x86_l_5a5d;
	case 23138ULL: goto x86_l_5a62;
	case 23143ULL: goto x86_l_5a67;
	case 23148ULL: goto x86_l_5a6c;
	case 23150ULL: goto x86_l_5a6e;
	case 23155ULL: goto x86_l_5a73;
	case 23157ULL: goto x86_l_5a75;
	case 23163ULL: goto x86_l_5a7b;
	case 23171ULL: goto x86_l_5a83;
	case 23177ULL: goto x86_l_5a89;
	case 23183ULL: goto x86_l_5a8f;
	case 23188ULL: goto x86_l_5a94;
	case 23196ULL: goto x86_l_5a9c;
	case 23198ULL: goto x86_l_5a9e;
	case 23203ULL: goto x86_l_5aa3;
	case 23208ULL: goto x86_l_5aa8;
	case 23213ULL: goto x86_l_5aad;
	case 23218ULL: goto x86_l_5ab2;
	case 23220ULL: goto x86_l_5ab4;
	case 23225ULL: goto x86_l_5ab9;
	case 23227ULL: goto x86_l_5abb;
	case 23233ULL: goto x86_l_5ac1;
	case 23241ULL: goto x86_l_5ac9;
	case 23247ULL: goto x86_l_5acf;
	case 23253ULL: goto x86_l_5ad5;
	case 23258ULL: goto x86_l_5ada;
	case 23266ULL: goto x86_l_5ae2;
	case 23268ULL: goto x86_l_5ae4;
	case 23273ULL: goto x86_l_5ae9;
	case 23278ULL: goto x86_l_5aee;
	case 23283ULL: goto x86_l_5af3;
	case 23288ULL: goto x86_l_5af8;
	case 23290ULL: goto x86_l_5afa;
	case 23295ULL: goto x86_l_5aff;
	case 23297ULL: goto x86_l_5b01;
	case 23303ULL: goto x86_l_5b07;
	case 23311ULL: goto x86_l_5b0f;
	case 23317ULL: goto x86_l_5b15;
	case 23323ULL: goto x86_l_5b1b;
	case 23328ULL: goto x86_l_5b20;
	case 23336ULL: goto x86_l_5b28;
	case 23338ULL: goto x86_l_5b2a;
	case 23343ULL: goto x86_l_5b2f;
	case 23348ULL: goto x86_l_5b34;
	case 23353ULL: goto x86_l_5b39;
	case 23358ULL: goto x86_l_5b3e;
	case 23360ULL: goto x86_l_5b40;
	case 23362ULL: goto x86_l_5b42;
	case 23368ULL: goto x86_l_5b48;
	case 23373ULL: goto x86_l_5b4d;
	case 23381ULL: goto x86_l_5b55;
	case 23387ULL: goto x86_l_5b5b;
	case 23393ULL: goto x86_l_5b61;
	case 23398ULL: goto x86_l_5b66;
	case 23406ULL: goto x86_l_5b6e;
	case 23408ULL: goto x86_l_5b70;
	case 23413ULL: goto x86_l_5b75;
	case 23418ULL: goto x86_l_5b7a;
	case 23423ULL: goto x86_l_5b7f;
	case 23428ULL: goto x86_l_5b84;
	case 23430ULL: goto x86_l_5b86;
	case 23432ULL: goto x86_l_5b88;
	case 23438ULL: goto x86_l_5b8e;
	case 23443ULL: goto x86_l_5b93;
	case 23451ULL: goto x86_l_5b9b;
	case 23457ULL: goto x86_l_5ba1;
	case 23463ULL: goto x86_l_5ba7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_546a:
	/* 0x546a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_546f:
	/* 0x546f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5471:
	/* 0x5471: js     5c82 <generic_sleepable_preload+0x5c82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23682ULL;
	}
x86_l_5477:
	/* 0x5477: cmp    WORD PTR [rdi+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_547f:
	/* 0x547f: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_5485:
	/* 0x5485: mov    eax,DWORD PTR [rdi+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_548b:
	/* 0x548b: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5490:
	/* 0x5490: cmp    WORD PTR [rdi+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_5498:
	/* 0x5498: je     54bd <generic_sleepable_preload+0x54bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54bd;
	}
x86_l_549a:
	/* 0x549a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_549f:
	/* 0x549f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54a4:
	/* 0x54a4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54a9:
	/* 0x54a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54ae:
	/* 0x54ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54b0:
	/* 0x54b0: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_54b5:
	/* 0x54b5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_54b7:
	/* 0x54b7: js     5cd3 <generic_sleepable_preload+0x5cd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23763ULL;
	}
x86_l_54bd:
	/* 0x54bd: cmp    WORD PTR [rdi+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_54c5:
	/* 0x54c5: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_54cb:
	/* 0x54cb: mov    eax,DWORD PTR [rdi+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_54d1:
	/* 0x54d1: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_54d6:
	/* 0x54d6: cmp    WORD PTR [rdi+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_54de:
	/* 0x54de: je     5503 <generic_sleepable_preload+0x5503> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5503;
	}
x86_l_54e0:
	/* 0x54e0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_54e5:
	/* 0x54e5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54ea:
	/* 0x54ea: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54ef:
	/* 0x54ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54f4:
	/* 0x54f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54f6:
	/* 0x54f6: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_54fb:
	/* 0x54fb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_54fd:
	/* 0x54fd: js     5ce4 <generic_sleepable_preload+0x5ce4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23780ULL;
	}
x86_l_5503:
	/* 0x5503: cmp    WORD PTR [rdi+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_550b:
	/* 0x550b: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_5511:
	/* 0x5511: mov    eax,DWORD PTR [rdi+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_5517:
	/* 0x5517: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_551c:
	/* 0x551c: cmp    WORD PTR [rdi+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_5524:
	/* 0x5524: je     5549 <generic_sleepable_preload+0x5549> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5549;
	}
x86_l_5526:
	/* 0x5526: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_552b:
	/* 0x552b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5530:
	/* 0x5530: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5535:
	/* 0x5535: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_553a:
	/* 0x553a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_553c:
	/* 0x553c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5541:
	/* 0x5541: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5543:
	/* 0x5543: js     5cf5 <generic_sleepable_preload+0x5cf5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23797ULL;
	}
x86_l_5549:
	/* 0x5549: cmp    WORD PTR [rdi+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_5551:
	/* 0x5551: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_5557:
	/* 0x5557: mov    eax,DWORD PTR [rdi+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_555d:
	/* 0x555d: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5562:
	/* 0x5562: cmp    WORD PTR [rdi+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_556a:
	/* 0x556a: je     558a <generic_sleepable_preload+0x558a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_558a;
	}
x86_l_556c:
	/* 0x556c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5571:
	/* 0x5571: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5576:
	/* 0x5576: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_557b:
	/* 0x557b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5580:
	/* 0x5580: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5582:
	/* 0x5582: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5584:
	/* 0x5584: js     5e16 <generic_sleepable_preload+0x5e16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24086ULL;
	}
x86_l_558a:
	/* 0x558a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_558f:
	/* 0x558f: cmp    WORD PTR [rdi+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5597:
	/* 0x5597: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_559d:
	/* 0x559d: mov    eax,DWORD PTR [rdi+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_55a3:
	/* 0x55a3: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_55a8:
	/* 0x55a8: cmp    WORD PTR [rdi+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_55b0:
	/* 0x55b0: je     55d0 <generic_sleepable_preload+0x55d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55d0;
	}
x86_l_55b2:
	/* 0x55b2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55b7:
	/* 0x55b7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55bc:
	/* 0x55bc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55c1:
	/* 0x55c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55c6:
	/* 0x55c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55c8:
	/* 0x55c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_55ca:
	/* 0x55ca: js     5ed8 <generic_sleepable_preload+0x5ed8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24280ULL;
	}
x86_l_55d0:
	/* 0x55d0: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_55d5:
	/* 0x55d5: cmp    WORD PTR [rdi+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_55dd:
	/* 0x55dd: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_55e3:
	/* 0x55e3: mov    eax,DWORD PTR [rdi+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_55e9:
	/* 0x55e9: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_55ee:
	/* 0x55ee: cmp    WORD PTR [rdi+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_55f6:
	/* 0x55f6: je     5616 <generic_sleepable_preload+0x5616> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5616;
	}
x86_l_55f8:
	/* 0x55f8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55fd:
	/* 0x55fd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5602:
	/* 0x5602: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5607:
	/* 0x5607: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_560c:
	/* 0x560c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_560e:
	/* 0x560e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5610:
	/* 0x5610: js     5f90 <generic_sleepable_preload+0x5f90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24464ULL;
	}
x86_l_5616:
	/* 0x5616: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_561b:
	/* 0x561b: cmp    WORD PTR [rdi+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_5623:
	/* 0x5623: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_5629:
	/* 0x5629: mov    eax,DWORD PTR [rdi+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_562f:
	/* 0x562f: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5634:
	/* 0x5634: cmp    WORD PTR [rdi+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_563c:
	/* 0x563c: je     5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23805ULL;
	}
x86_l_5642:
	/* 0x5642: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5647:
	/* 0x5647: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_564c:
	/* 0x564c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5651:
	/* 0x5651: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5656:
	/* 0x5656: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5658:
	/* 0x5658: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_565d:
	/* 0x565d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_565f:
	/* 0x565f: jns    5cfd <generic_sleepable_preload+0x5cfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 23805ULL;
	}
x86_l_5665:
	/* 0x5665: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_566a:
	/* 0x566a: jmp    5cfa <generic_sleepable_preload+0x5cfa> */
	return 23802ULL;
x86_l_566f:
	/* 0x566f: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_5674:
	/* 0x5674: jmp    5cfa <generic_sleepable_preload+0x5cfa> */
	return 23802ULL;
x86_l_5679:
	/* 0x5679: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_5681:
	/* 0x5681: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_5684:
	/* 0x5684: je     56e9 <generic_sleepable_preload+0x56e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56e9;
	}
x86_l_5686:
	/* 0x5686: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_568b:
	/* 0x568b: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_568e:
	/* 0x568e: je     56e9 <generic_sleepable_preload+0x56e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56e9;
	}
x86_l_5690:
	/* 0x5690: jmp    56fc <generic_sleepable_preload+0x56fc> */
	goto x86_l_56fc;
x86_l_5692:
	/* 0x5692: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5697:
	/* 0x5697: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_569a:
	/* 0x569a: je     56e9 <generic_sleepable_preload+0x56e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56e9;
	}
x86_l_569c:
	/* 0x569c: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_56a1:
	/* 0x56a1: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_56a4:
	/* 0x56a4: je     56e9 <generic_sleepable_preload+0x56e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56e9;
	}
x86_l_56a6:
	/* 0x56a6: jmp    56fc <generic_sleepable_preload+0x56fc> */
	goto x86_l_56fc;
x86_l_56a8:
	/* 0x56a8: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_56b0:
	/* 0x56b0: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_56b3:
	/* 0x56b3: je     56e9 <generic_sleepable_preload+0x56e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56e9;
	}
x86_l_56b5:
	/* 0x56b5: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_56ba:
	/* 0x56ba: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_56bd:
	/* 0x56bd: je     56e9 <generic_sleepable_preload+0x56e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56e9;
	}
x86_l_56bf:
	/* 0x56bf: jmp    56fc <generic_sleepable_preload+0x56fc> */
	goto x86_l_56fc;
x86_l_56c1:
	/* 0x56c1: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_56c9:
	/* 0x56c9: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_56cc:
	/* 0x56cc: je     56e9 <generic_sleepable_preload+0x56e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56e9;
	}
x86_l_56ce:
	/* 0x56ce: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_56d3:
	/* 0x56d3: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_56d6:
	/* 0x56d6: je     56e9 <generic_sleepable_preload+0x56e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56e9;
	}
x86_l_56d8:
	/* 0x56d8: jmp    56fc <generic_sleepable_preload+0x56fc> */
	goto x86_l_56fc;
x86_l_56da:
	/* 0x56da: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_56df:
	/* 0x56df: jmp    5cfa <generic_sleepable_preload+0x5cfa> */
	return 23802ULL;
x86_l_56e4:
	/* 0x56e4: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_56e9:
	/* 0x56e9: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_56ec:
	/* 0x56ec: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_56ee:
	/* 0x56ee: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_56f0:
	/* 0x56f0: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_56f5:
	/* 0x56f5: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_56f7:
	/* 0x56f7: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_56fc:
	/* 0x56fc: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5701:
	/* 0x5701: mov    ebx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5704:
	/* 0x5704: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5706:
	/* 0x5706: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_5709:
	/* 0x5709: cmp    WORD PTR [rdi+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_5711:
	/* 0x5711: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24112ULL;
	}
x86_l_5717:
	/* 0x5717: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_571e:
	/* 0x571e: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_5721:
	/* 0x5721: mov    edx,DWORD PTR [rdi+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_5727:
	/* 0x5727: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_572a:
	/* 0x572a: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_572f:
	/* 0x572f: movzx  eax,WORD PTR [rdi+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_5736:
	/* 0x5736: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_5738:
	/* 0x5738: je     59c7 <generic_sleepable_preload+0x59c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59c7;
	}
x86_l_573e:
	/* 0x573e: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5741:
	/* 0x5741: je     5766 <generic_sleepable_preload+0x5766> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5766;
	}
x86_l_5743:
	/* 0x5743: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5748:
	/* 0x5748: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_574d:
	/* 0x574d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5752:
	/* 0x5752: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5757:
	/* 0x5757: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5759:
	/* 0x5759: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_575e:
	/* 0x575e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5760:
	/* 0x5760: js     5c6e <generic_sleepable_preload+0x5c6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23662ULL;
	}
x86_l_5766:
	/* 0x5766: cmp    WORD PTR [rdi+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_576e:
	/* 0x576e: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24112ULL;
	}
x86_l_5774:
	/* 0x5774: mov    eax,DWORD PTR [rdi+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_577a:
	/* 0x577a: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_577f:
	/* 0x577f: cmp    WORD PTR [rdi+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_5787:
	/* 0x5787: je     57ac <generic_sleepable_preload+0x57ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57ac;
	}
x86_l_5789:
	/* 0x5789: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_578e:
	/* 0x578e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5793:
	/* 0x5793: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5798:
	/* 0x5798: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_579d:
	/* 0x579d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_579f:
	/* 0x579f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_57a4:
	/* 0x57a4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57a6:
	/* 0x57a6: js     5c78 <generic_sleepable_preload+0x5c78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23672ULL;
	}
x86_l_57ac:
	/* 0x57ac: cmp    WORD PTR [rdi+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_57b4:
	/* 0x57b4: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24112ULL;
	}
x86_l_57ba:
	/* 0x57ba: mov    eax,DWORD PTR [rdi+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_57c0:
	/* 0x57c0: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_57c5:
	/* 0x57c5: cmp    WORD PTR [rdi+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_57cd:
	/* 0x57cd: je     57f2 <generic_sleepable_preload+0x57f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57f2;
	}
x86_l_57cf:
	/* 0x57cf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_57d4:
	/* 0x57d4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57d9:
	/* 0x57d9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57de:
	/* 0x57de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57e3:
	/* 0x57e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57e5:
	/* 0x57e5: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_57ea:
	/* 0x57ea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57ec:
	/* 0x57ec: js     5c89 <generic_sleepable_preload+0x5c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23689ULL;
	}
x86_l_57f2:
	/* 0x57f2: cmp    WORD PTR [rdi+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_57fa:
	/* 0x57fa: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24112ULL;
	}
x86_l_5800:
	/* 0x5800: mov    eax,DWORD PTR [rdi+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_5806:
	/* 0x5806: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_580b:
	/* 0x580b: cmp    WORD PTR [rdi+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_5813:
	/* 0x5813: je     5838 <generic_sleepable_preload+0x5838> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5838;
	}
x86_l_5815:
	/* 0x5815: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_581a:
	/* 0x581a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_581f:
	/* 0x581f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5824:
	/* 0x5824: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5829:
	/* 0x5829: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_582b:
	/* 0x582b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5830:
	/* 0x5830: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5832:
	/* 0x5832: js     5cda <generic_sleepable_preload+0x5cda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23770ULL;
	}
x86_l_5838:
	/* 0x5838: cmp    WORD PTR [rdi+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_5840:
	/* 0x5840: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24112ULL;
	}
x86_l_5846:
	/* 0x5846: mov    eax,DWORD PTR [rdi+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_584c:
	/* 0x584c: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5851:
	/* 0x5851: cmp    WORD PTR [rdi+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_5859:
	/* 0x5859: je     587e <generic_sleepable_preload+0x587e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_587e;
	}
x86_l_585b:
	/* 0x585b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5860:
	/* 0x5860: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5865:
	/* 0x5865: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_586a:
	/* 0x586a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_586f:
	/* 0x586f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5871:
	/* 0x5871: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5876:
	/* 0x5876: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5878:
	/* 0x5878: js     5ceb <generic_sleepable_preload+0x5ceb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23787ULL;
	}
x86_l_587e:
	/* 0x587e: cmp    WORD PTR [rdi+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_5886:
	/* 0x5886: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24112ULL;
	}
x86_l_588c:
	/* 0x588c: mov    eax,DWORD PTR [rdi+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_5892:
	/* 0x5892: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5897:
	/* 0x5897: cmp    WORD PTR [rdi+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_589f:
	/* 0x589f: je     58c4 <generic_sleepable_preload+0x58c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58c4;
	}
x86_l_58a1:
	/* 0x58a1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_58a6:
	/* 0x58a6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58ab:
	/* 0x58ab: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58b0:
	/* 0x58b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58b5:
	/* 0x58b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58b7:
	/* 0x58b7: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_58bc:
	/* 0x58bc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_58be:
	/* 0x58be: js     5d7c <generic_sleepable_preload+0x5d7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23932ULL;
	}
x86_l_58c4:
	/* 0x58c4: cmp    WORD PTR [rdi+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_58cc:
	/* 0x58cc: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24112ULL;
	}
x86_l_58d2:
	/* 0x58d2: mov    eax,DWORD PTR [rdi+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_58d8:
	/* 0x58d8: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_58dd:
	/* 0x58dd: cmp    WORD PTR [rdi+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_58e5:
	/* 0x58e5: je     5905 <generic_sleepable_preload+0x5905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5905;
	}
x86_l_58e7:
	/* 0x58e7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_58ec:
	/* 0x58ec: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58f1:
	/* 0x58f1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58f6:
	/* 0x58f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58fb:
	/* 0x58fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58fd:
	/* 0x58fd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_58ff:
	/* 0x58ff: js     5e28 <generic_sleepable_preload+0x5e28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24104ULL;
	}
x86_l_5905:
	/* 0x5905: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_590a:
	/* 0x590a: cmp    WORD PTR [rcx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5912:
	/* 0x5912: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24112ULL;
	}
x86_l_5918:
	/* 0x5918: mov    eax,DWORD PTR [rcx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_591e:
	/* 0x591e: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5923:
	/* 0x5923: cmp    WORD PTR [rcx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_592b:
	/* 0x592b: je     594b <generic_sleepable_preload+0x594b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_594b;
	}
x86_l_592d:
	/* 0x592d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5932:
	/* 0x5932: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5937:
	/* 0x5937: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_593c:
	/* 0x593c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5941:
	/* 0x5941: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5943:
	/* 0x5943: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5945:
	/* 0x5945: js     5eea <generic_sleepable_preload+0x5eea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24298ULL;
	}
x86_l_594b:
	/* 0x594b: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5950:
	/* 0x5950: cmp    WORD PTR [rcx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_5958:
	/* 0x5958: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24112ULL;
	}
x86_l_595e:
	/* 0x595e: mov    eax,DWORD PTR [rcx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_5964:
	/* 0x5964: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5969:
	/* 0x5969: cmp    WORD PTR [rcx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_5971:
	/* 0x5971: je     5991 <generic_sleepable_preload+0x5991> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5991;
	}
x86_l_5973:
	/* 0x5973: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5978:
	/* 0x5978: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_597d:
	/* 0x597d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5982:
	/* 0x5982: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5987:
	/* 0x5987: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5989:
	/* 0x5989: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_598b:
	/* 0x598b: js     5f9a <generic_sleepable_preload+0x5f9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24474ULL;
	}
x86_l_5991:
	/* 0x5991: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5996:
	/* 0x5996: cmp    WORD PTR [rcx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_599e:
	/* 0x599e: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24112ULL;
	}
x86_l_59a4:
	/* 0x59a4: mov    eax,DWORD PTR [rcx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_59aa:
	/* 0x59aa: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_59af:
	/* 0x59af: cmp    WORD PTR [rcx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_59b7:
	/* 0x59b7: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24112ULL;
	}
x86_l_59bd:
	/* 0x59bd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_59c2:
	/* 0x59c2: jmp    5c4b <generic_sleepable_preload+0x5c4b> */
	return 23627ULL;
x86_l_59c7:
	/* 0x59c7: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_59ca:
	/* 0x59ca: je     59ef <generic_sleepable_preload+0x59ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59ef;
	}
x86_l_59cc:
	/* 0x59cc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_59d1:
	/* 0x59d1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59d6:
	/* 0x59d6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59db:
	/* 0x59db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59e0:
	/* 0x59e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59e2:
	/* 0x59e2: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_59e7:
	/* 0x59e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_59e9:
	/* 0x59e9: js     5c6e <generic_sleepable_preload+0x5c6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23662ULL;
	}
x86_l_59ef:
	/* 0x59ef: cmp    WORD PTR [rdi+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_59f7:
	/* 0x59f7: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24112ULL;
	}
x86_l_59fd:
	/* 0x59fd: mov    eax,DWORD PTR [rdi+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_5a03:
	/* 0x5a03: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5a08:
	/* 0x5a08: cmp    WORD PTR [rdi+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_5a10:
	/* 0x5a10: je     5a35 <generic_sleepable_preload+0x5a35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a35;
	}
x86_l_5a12:
	/* 0x5a12: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5a17:
	/* 0x5a17: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a1c:
	/* 0x5a1c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a21:
	/* 0x5a21: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a26:
	/* 0x5a26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a28:
	/* 0x5a28: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5a2d:
	/* 0x5a2d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5a2f:
	/* 0x5a2f: js     5c78 <generic_sleepable_preload+0x5c78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23672ULL;
	}
x86_l_5a35:
	/* 0x5a35: cmp    WORD PTR [rdi+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_5a3d:
	/* 0x5a3d: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24112ULL;
	}
x86_l_5a43:
	/* 0x5a43: mov    eax,DWORD PTR [rdi+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_5a49:
	/* 0x5a49: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5a4e:
	/* 0x5a4e: cmp    WORD PTR [rdi+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_5a56:
	/* 0x5a56: je     5a7b <generic_sleepable_preload+0x5a7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a7b;
	}
x86_l_5a58:
	/* 0x5a58: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5a5d:
	/* 0x5a5d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a62:
	/* 0x5a62: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a67:
	/* 0x5a67: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a6c:
	/* 0x5a6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a6e:
	/* 0x5a6e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5a73:
	/* 0x5a73: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5a75:
	/* 0x5a75: js     5c89 <generic_sleepable_preload+0x5c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23689ULL;
	}
x86_l_5a7b:
	/* 0x5a7b: cmp    WORD PTR [rdi+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_5a83:
	/* 0x5a83: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24112ULL;
	}
x86_l_5a89:
	/* 0x5a89: mov    eax,DWORD PTR [rdi+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_5a8f:
	/* 0x5a8f: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5a94:
	/* 0x5a94: cmp    WORD PTR [rdi+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_5a9c:
	/* 0x5a9c: je     5ac1 <generic_sleepable_preload+0x5ac1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ac1;
	}
x86_l_5a9e:
	/* 0x5a9e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5aa3:
	/* 0x5aa3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5aa8:
	/* 0x5aa8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5aad:
	/* 0x5aad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ab2:
	/* 0x5ab2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ab4:
	/* 0x5ab4: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ab9:
	/* 0x5ab9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5abb:
	/* 0x5abb: js     5cda <generic_sleepable_preload+0x5cda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23770ULL;
	}
x86_l_5ac1:
	/* 0x5ac1: cmp    WORD PTR [rdi+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_5ac9:
	/* 0x5ac9: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24112ULL;
	}
x86_l_5acf:
	/* 0x5acf: mov    eax,DWORD PTR [rdi+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_5ad5:
	/* 0x5ad5: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5ada:
	/* 0x5ada: cmp    WORD PTR [rdi+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_5ae2:
	/* 0x5ae2: je     5b07 <generic_sleepable_preload+0x5b07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b07;
	}
x86_l_5ae4:
	/* 0x5ae4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5ae9:
	/* 0x5ae9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5aee:
	/* 0x5aee: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5af3:
	/* 0x5af3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5af8:
	/* 0x5af8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5afa:
	/* 0x5afa: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5aff:
	/* 0x5aff: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b01:
	/* 0x5b01: js     5ceb <generic_sleepable_preload+0x5ceb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23787ULL;
	}
x86_l_5b07:
	/* 0x5b07: cmp    WORD PTR [rdi+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_5b0f:
	/* 0x5b0f: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24112ULL;
	}
x86_l_5b15:
	/* 0x5b15: mov    eax,DWORD PTR [rdi+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_5b1b:
	/* 0x5b1b: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5b20:
	/* 0x5b20: cmp    WORD PTR [rdi+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_5b28:
	/* 0x5b28: je     5b48 <generic_sleepable_preload+0x5b48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b48;
	}
x86_l_5b2a:
	/* 0x5b2a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5b2f:
	/* 0x5b2f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b34:
	/* 0x5b34: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b39:
	/* 0x5b39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b3e:
	/* 0x5b3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b40:
	/* 0x5b40: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b42:
	/* 0x5b42: js     5d7c <generic_sleepable_preload+0x5d7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23932ULL;
	}
x86_l_5b48:
	/* 0x5b48: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b4d:
	/* 0x5b4d: cmp    WORD PTR [rcx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_5b55:
	/* 0x5b55: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24112ULL;
	}
x86_l_5b5b:
	/* 0x5b5b: mov    eax,DWORD PTR [rcx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_5b61:
	/* 0x5b61: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5b66:
	/* 0x5b66: cmp    WORD PTR [rcx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_5b6e:
	/* 0x5b6e: je     5b8e <generic_sleepable_preload+0x5b8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b8e;
	}
x86_l_5b70:
	/* 0x5b70: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5b75:
	/* 0x5b75: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b7a:
	/* 0x5b7a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b7f:
	/* 0x5b7f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b84:
	/* 0x5b84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b86:
	/* 0x5b86: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b88:
	/* 0x5b88: js     5e28 <generic_sleepable_preload+0x5e28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24104ULL;
	}
x86_l_5b8e:
	/* 0x5b8e: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b93:
	/* 0x5b93: cmp    WORD PTR [rcx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5b9b:
	/* 0x5b9b: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24112ULL;
	}
x86_l_5ba1:
	/* 0x5ba1: mov    eax,DWORD PTR [rcx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5ba7:
	/* 0x5ba7: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
	return 23468ULL;
}

static __noinline __u64 tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 23468ULL: goto x86_l_5bac;
	case 23476ULL: goto x86_l_5bb4;
	case 23478ULL: goto x86_l_5bb6;
	case 23483ULL: goto x86_l_5bbb;
	case 23488ULL: goto x86_l_5bc0;
	case 23493ULL: goto x86_l_5bc5;
	case 23498ULL: goto x86_l_5bca;
	case 23500ULL: goto x86_l_5bcc;
	case 23502ULL: goto x86_l_5bce;
	case 23508ULL: goto x86_l_5bd4;
	case 23513ULL: goto x86_l_5bd9;
	case 23521ULL: goto x86_l_5be1;
	case 23527ULL: goto x86_l_5be7;
	case 23533ULL: goto x86_l_5bed;
	case 23538ULL: goto x86_l_5bf2;
	case 23546ULL: goto x86_l_5bfa;
	case 23548ULL: goto x86_l_5bfc;
	case 23553ULL: goto x86_l_5c01;
	case 23558ULL: goto x86_l_5c06;
	case 23563ULL: goto x86_l_5c0b;
	case 23568ULL: goto x86_l_5c10;
	case 23570ULL: goto x86_l_5c12;
	case 23572ULL: goto x86_l_5c14;
	case 23578ULL: goto x86_l_5c1a;
	case 23583ULL: goto x86_l_5c1f;
	case 23591ULL: goto x86_l_5c27;
	case 23597ULL: goto x86_l_5c2d;
	case 23603ULL: goto x86_l_5c33;
	case 23608ULL: goto x86_l_5c38;
	case 23616ULL: goto x86_l_5c40;
	case 23622ULL: goto x86_l_5c46;
	case 23627ULL: goto x86_l_5c4b;
	case 23632ULL: goto x86_l_5c50;
	case 23637ULL: goto x86_l_5c55;
	case 23642ULL: goto x86_l_5c5a;
	case 23644ULL: goto x86_l_5c5c;
	case 23646ULL: goto x86_l_5c5e;
	case 23652ULL: goto x86_l_5c64;
	case 23657ULL: goto x86_l_5c69;
	case 23662ULL: goto x86_l_5c6e;
	case 23667ULL: goto x86_l_5c73;
	case 23672ULL: goto x86_l_5c78;
	case 23677ULL: goto x86_l_5c7d;
	case 23682ULL: goto x86_l_5c82;
	case 23687ULL: goto x86_l_5c87;
	case 23689ULL: goto x86_l_5c89;
	case 23694ULL: goto x86_l_5c8e;
	case 23699ULL: goto x86_l_5c93;
	case 23704ULL: goto x86_l_5c98;
	case 23711ULL: goto x86_l_5c9f;
	case 23718ULL: goto x86_l_5ca6;
	case 23725ULL: goto x86_l_5cad;
	case 23730ULL: goto x86_l_5cb2;
	case 23733ULL: goto x86_l_5cb5;
	case 23738ULL: goto x86_l_5cba;
	case 23743ULL: goto x86_l_5cbf;
	case 23745ULL: goto x86_l_5cc1;
	case 23747ULL: goto x86_l_5cc3;
	case 23750ULL: goto x86_l_5cc6;
	case 23756ULL: goto x86_l_5ccc;
	case 23758ULL: goto x86_l_5cce;
	case 23763ULL: goto x86_l_5cd3;
	case 23768ULL: goto x86_l_5cd8;
	case 23770ULL: goto x86_l_5cda;
	case 23775ULL: goto x86_l_5cdf;
	case 23780ULL: goto x86_l_5ce4;
	case 23785ULL: goto x86_l_5ce9;
	case 23787ULL: goto x86_l_5ceb;
	case 23792ULL: goto x86_l_5cf0;
	case 23797ULL: goto x86_l_5cf5;
	case 23802ULL: goto x86_l_5cfa;
	case 23805ULL: goto x86_l_5cfd;
	case 23808ULL: goto x86_l_5d00;
	case 23813ULL: goto x86_l_5d05;
	case 23818ULL: goto x86_l_5d0a;
	case 23823ULL: goto x86_l_5d0f;
	case 23826ULL: goto x86_l_5d12;
	case 23828ULL: goto x86_l_5d14;
	case 23831ULL: goto x86_l_5d17;
	case 23837ULL: goto x86_l_5d1d;
	case 23842ULL: goto x86_l_5d22;
	case 23847ULL: goto x86_l_5d27;
	case 23849ULL: goto x86_l_5d29;
	case 23854ULL: goto x86_l_5d2e;
	case 23862ULL: goto x86_l_5d36;
	case 23867ULL: goto x86_l_5d3b;
	case 23874ULL: goto x86_l_5d42;
	case 23879ULL: goto x86_l_5d47;
	case 23881ULL: goto x86_l_5d49;
	case 23884ULL: goto x86_l_5d4c;
	case 23890ULL: goto x86_l_5d52;
	case 23896ULL: goto x86_l_5d58;
	case 23903ULL: goto x86_l_5d5f;
	case 23908ULL: goto x86_l_5d64;
	case 23911ULL: goto x86_l_5d67;
	case 23914ULL: goto x86_l_5d6a;
	case 23917ULL: goto x86_l_5d6d;
	case 23919ULL: goto x86_l_5d6f;
	case 23922ULL: goto x86_l_5d72;
	case 23927ULL: goto x86_l_5d77;
	case 23932ULL: goto x86_l_5d7c;
	case 23937ULL: goto x86_l_5d81;
	case 23942ULL: goto x86_l_5d86;
	case 23947ULL: goto x86_l_5d8b;
	case 23950ULL: goto x86_l_5d8e;
	case 23955ULL: goto x86_l_5d93;
	case 23960ULL: goto x86_l_5d98;
	case 23965ULL: goto x86_l_5d9d;
	case 23968ULL: goto x86_l_5da0;
	case 23973ULL: goto x86_l_5da5;
	case 23978ULL: goto x86_l_5daa;
	case 23983ULL: goto x86_l_5daf;
	case 23986ULL: goto x86_l_5db2;
	case 23991ULL: goto x86_l_5db7;
	case 23996ULL: goto x86_l_5dbc;
	case 24001ULL: goto x86_l_5dc1;
	case 24004ULL: goto x86_l_5dc4;
	case 24009ULL: goto x86_l_5dc9;
	case 24014ULL: goto x86_l_5dce;
	case 24019ULL: goto x86_l_5dd3;
	case 24022ULL: goto x86_l_5dd6;
	case 24027ULL: goto x86_l_5ddb;
	case 24032ULL: goto x86_l_5de0;
	case 24037ULL: goto x86_l_5de5;
	case 24040ULL: goto x86_l_5de8;
	case 24045ULL: goto x86_l_5ded;
	case 24050ULL: goto x86_l_5df2;
	case 24055ULL: goto x86_l_5df7;
	case 24058ULL: goto x86_l_5dfa;
	case 24063ULL: goto x86_l_5dff;
	case 24068ULL: goto x86_l_5e04;
	case 24073ULL: goto x86_l_5e09;
	case 24076ULL: goto x86_l_5e0c;
	case 24081ULL: goto x86_l_5e11;
	case 24086ULL: goto x86_l_5e16;
	case 24091ULL: goto x86_l_5e1b;
	case 24094ULL: goto x86_l_5e1e;
	case 24099ULL: goto x86_l_5e23;
	case 24104ULL: goto x86_l_5e28;
	case 24109ULL: goto x86_l_5e2d;
	case 24112ULL: goto x86_l_5e30;
	case 24115ULL: goto x86_l_5e33;
	case 24121ULL: goto x86_l_5e39;
	case 24126ULL: goto x86_l_5e3e;
	case 24131ULL: goto x86_l_5e43;
	case 24133ULL: goto x86_l_5e45;
	case 24138ULL: goto x86_l_5e4a;
	case 24146ULL: goto x86_l_5e52;
	case 24151ULL: goto x86_l_5e57;
	case 24158ULL: goto x86_l_5e5e;
	case 24163ULL: goto x86_l_5e63;
	case 24165ULL: goto x86_l_5e65;
	case 24168ULL: goto x86_l_5e68;
	case 24174ULL: goto x86_l_5e6e;
	case 24180ULL: goto x86_l_5e74;
	case 24187ULL: goto x86_l_5e7b;
	case 24192ULL: goto x86_l_5e80;
	case 24195ULL: goto x86_l_5e83;
	case 24198ULL: goto x86_l_5e86;
	case 24201ULL: goto x86_l_5e89;
	case 24203ULL: goto x86_l_5e8b;
	case 24206ULL: goto x86_l_5e8e;
	case 24211ULL: goto x86_l_5e93;
	case 24214ULL: goto x86_l_5e96;
	case 24217ULL: goto x86_l_5e99;
	case 24219ULL: goto x86_l_5e9b;
	case 24222ULL: goto x86_l_5e9e;
	case 24228ULL: goto x86_l_5ea4;
	case 24231ULL: goto x86_l_5ea7;
	case 24233ULL: goto x86_l_5ea9;
	case 24236ULL: goto x86_l_5eac;
	case 24240ULL: goto x86_l_5eb0;
	case 24245ULL: goto x86_l_5eb5;
	case 24248ULL: goto x86_l_5eb8;
	case 24250ULL: goto x86_l_5eba;
	case 24253ULL: goto x86_l_5ebd;
	case 24258ULL: goto x86_l_5ec2;
	case 24260ULL: goto x86_l_5ec4;
	case 24263ULL: goto x86_l_5ec7;
	case 24265ULL: goto x86_l_5ec9;
	case 24270ULL: goto x86_l_5ece;
	case 24273ULL: goto x86_l_5ed1;
	case 24275ULL: goto x86_l_5ed3;
	case 24280ULL: goto x86_l_5ed8;
	case 24283ULL: goto x86_l_5edb;
	case 24288ULL: goto x86_l_5ee0;
	case 24293ULL: goto x86_l_5ee5;
	case 24298ULL: goto x86_l_5eea;
	case 24301ULL: goto x86_l_5eed;
	case 24306ULL: goto x86_l_5ef2;
	case 24309ULL: goto x86_l_5ef5;
	case 24315ULL: goto x86_l_5efb;
	case 24320ULL: goto x86_l_5f00;
	case 24323ULL: goto x86_l_5f03;
	case 24328ULL: goto x86_l_5f08;
	case 24333ULL: goto x86_l_5f0d;
	case 24338ULL: goto x86_l_5f12;
	case 24341ULL: goto x86_l_5f15;
	case 24346ULL: goto x86_l_5f1a;
	case 24351ULL: goto x86_l_5f1f;
	case 24356ULL: goto x86_l_5f24;
	case 24359ULL: goto x86_l_5f27;
	case 24364ULL: goto x86_l_5f2c;
	case 24369ULL: goto x86_l_5f31;
	case 24374ULL: goto x86_l_5f36;
	case 24377ULL: goto x86_l_5f39;
	case 24382ULL: goto x86_l_5f3e;
	case 24387ULL: goto x86_l_5f43;
	case 24392ULL: goto x86_l_5f48;
	case 24395ULL: goto x86_l_5f4b;
	case 24400ULL: goto x86_l_5f50;
	case 24405ULL: goto x86_l_5f55;
	case 24410ULL: goto x86_l_5f5a;
	case 24413ULL: goto x86_l_5f5d;
	case 24418ULL: goto x86_l_5f62;
	case 24423ULL: goto x86_l_5f67;
	case 24428ULL: goto x86_l_5f6c;
	case 24431ULL: goto x86_l_5f6f;
	case 24436ULL: goto x86_l_5f74;
	case 24441ULL: goto x86_l_5f79;
	case 24446ULL: goto x86_l_5f7e;
	case 24449ULL: goto x86_l_5f81;
	case 24454ULL: goto x86_l_5f86;
	case 24459ULL: goto x86_l_5f8b;
	case 24464ULL: goto x86_l_5f90;
	case 24469ULL: goto x86_l_5f95;
	case 24474ULL: goto x86_l_5f9a;
	case 24479ULL: goto x86_l_5f9f;
	case 24484ULL: goto x86_l_5fa4;
	case 24487ULL: goto x86_l_5fa7;
	case 24492ULL: goto x86_l_5fac;
	case 24497ULL: goto x86_l_5fb1;
	case 24500ULL: goto x86_l_5fb4;
	case 24505ULL: goto x86_l_5fb9;
	case 24510ULL: goto x86_l_5fbe;
	case 24513ULL: goto x86_l_5fc1;
	case 24518ULL: goto x86_l_5fc6;
	case 24523ULL: goto x86_l_5fcb;
	case 24526ULL: goto x86_l_5fce;
	case 24531ULL: goto x86_l_5fd3;
	case 24536ULL: goto x86_l_5fd8;
	case 24539ULL: goto x86_l_5fdb;
	case 24544ULL: goto x86_l_5fe0;
	case 24549ULL: goto x86_l_5fe5;
	case 24552ULL: goto x86_l_5fe8;
	case 24557ULL: goto x86_l_5fed;
	case 24562ULL: goto x86_l_5ff2;
	case 24565ULL: goto x86_l_5ff5;
	case 24570ULL: goto x86_l_5ffa;
	case 24575ULL: goto x86_l_5fff;
	case 24578ULL: goto x86_l_6002;
	case 24583ULL: goto x86_l_6007;
	case 24588ULL: goto x86_l_600c;
	case 24593ULL: goto x86_l_6011;
	case 24596ULL: goto x86_l_6014;
	case 24601ULL: goto x86_l_6019;
	case 24606ULL: goto x86_l_601e;
	case 24611ULL: goto x86_l_6023;
	case 24616ULL: goto x86_l_6028;
	case 24619ULL: goto x86_l_602b;
	case 24624ULL: goto x86_l_6030;
	case 24629ULL: goto x86_l_6035;
	case 24634ULL: goto x86_l_603a;
	case 24639ULL: goto x86_l_603f;
	case 24644ULL: goto x86_l_6044;
	case 24649ULL: goto x86_l_6049;
	case 24654ULL: goto x86_l_604e;
	case 24659ULL: goto x86_l_6053;
	case 24664ULL: goto x86_l_6058;
	case 24669ULL: goto x86_l_605d;
	case 24674ULL: goto x86_l_6062;
	case 24679ULL: goto x86_l_6067;
	case 24684ULL: goto x86_l_606c;
	case 24689ULL: goto x86_l_6071;
	case 24694ULL: goto x86_l_6076;
	case 24699ULL: goto x86_l_607b;
	case 24702ULL: goto x86_l_607e;
	case 24707ULL: goto x86_l_6083;
	case 24712ULL: goto x86_l_6088;
	case 24715ULL: goto x86_l_608b;
	case 24720ULL: goto x86_l_6090;
	case 24725ULL: goto x86_l_6095;
	case 24728ULL: goto x86_l_6098;
	case 24733ULL: goto x86_l_609d;
	case 24738ULL: goto x86_l_60a2;
	case 24741ULL: goto x86_l_60a5;
	case 24746ULL: goto x86_l_60aa;
	case 24751ULL: goto x86_l_60af;
	case 24754ULL: goto x86_l_60b2;
	case 24759ULL: goto x86_l_60b7;
	case 24762ULL: goto x86_l_60ba;
	case 24767ULL: goto x86_l_60bf;
	case 24772ULL: goto x86_l_60c4;
	case 24775ULL: goto x86_l_60c7;
	case 24780ULL: goto x86_l_60cc;
	case 24783ULL: goto x86_l_60cf;
	case 24788ULL: goto x86_l_60d4;
	case 24793ULL: goto x86_l_60d9;
	case 24796ULL: goto x86_l_60dc;
	case 24801ULL: goto x86_l_60e1;
	case 24804ULL: goto x86_l_60e4;
	case 24809ULL: goto x86_l_60e9;
	case 24814ULL: goto x86_l_60ee;
	case 24817ULL: goto x86_l_60f1;
	case 24822ULL: goto x86_l_60f6;
	case 24825ULL: goto x86_l_60f9;
	case 24830ULL: goto x86_l_60fe;
	case 24835ULL: goto x86_l_6103;
	case 24838ULL: goto x86_l_6106;
	case 24843ULL: goto x86_l_610b;
	case 24846ULL: goto x86_l_610e;
	case 24851ULL: goto x86_l_6113;
	case 24856ULL: goto x86_l_6118;
	case 24859ULL: goto x86_l_611b;
	case 24864ULL: goto x86_l_6120;
	case 24867ULL: goto x86_l_6123;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5bac:
	/* 0x5bac: cmp    WORD PTR [rcx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_5bb4:
	/* 0x5bb4: je     5bd4 <generic_sleepable_preload+0x5bd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5bd4;
	}
x86_l_5bb6:
	/* 0x5bb6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5bbb:
	/* 0x5bbb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bc0:
	/* 0x5bc0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bc5:
	/* 0x5bc5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5bca:
	/* 0x5bca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bcc:
	/* 0x5bcc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5bce:
	/* 0x5bce: js     5eea <generic_sleepable_preload+0x5eea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_5eea;
	}
x86_l_5bd4:
	/* 0x5bd4: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5bd9:
	/* 0x5bd9: cmp    WORD PTR [rcx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_5be1:
	/* 0x5be1: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e30;
	}
x86_l_5be7:
	/* 0x5be7: mov    eax,DWORD PTR [rcx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_5bed:
	/* 0x5bed: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5bf2:
	/* 0x5bf2: cmp    WORD PTR [rcx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_5bfa:
	/* 0x5bfa: je     5c1a <generic_sleepable_preload+0x5c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c1a;
	}
x86_l_5bfc:
	/* 0x5bfc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5c01:
	/* 0x5c01: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c06:
	/* 0x5c06: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c0b:
	/* 0x5c0b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c10:
	/* 0x5c10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c12:
	/* 0x5c12: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5c14:
	/* 0x5c14: js     5f9a <generic_sleepable_preload+0x5f9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_5f9a;
	}
x86_l_5c1a:
	/* 0x5c1a: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5c1f:
	/* 0x5c1f: cmp    WORD PTR [rcx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_5c27:
	/* 0x5c27: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e30;
	}
x86_l_5c2d:
	/* 0x5c2d: mov    eax,DWORD PTR [rcx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_5c33:
	/* 0x5c33: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5c38:
	/* 0x5c38: cmp    WORD PTR [rcx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_5c40:
	/* 0x5c40: je     5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e30;
	}
x86_l_5c46:
	/* 0x5c46: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5c4b:
	/* 0x5c4b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c50:
	/* 0x5c50: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c55:
	/* 0x5c55: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c5a:
	/* 0x5c5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c5c:
	/* 0x5c5c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5c5e:
	/* 0x5c5e: jns    5e30 <generic_sleepable_preload+0x5e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_5e30;
	}
x86_l_5c64:
	/* 0x5c64: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_5c69:
	/* 0x5c69: jmp    5e2d <generic_sleepable_preload+0x5e2d> */
	goto x86_l_5e2d;
x86_l_5c6e:
	/* 0x5c6e: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_5c73:
	/* 0x5c73: jmp    5e2d <generic_sleepable_preload+0x5e2d> */
	goto x86_l_5e2d;
x86_l_5c78:
	/* 0x5c78: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_5c7d:
	/* 0x5c7d: jmp    5e2d <generic_sleepable_preload+0x5e2d> */
	goto x86_l_5e2d;
x86_l_5c82:
	/* 0x5c82: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_5c87:
	/* 0x5c87: jmp    5cfa <generic_sleepable_preload+0x5cfa> */
	goto x86_l_5cfa;
x86_l_5c89:
	/* 0x5c89: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_5c8e:
	/* 0x5c8e: jmp    5e2d <generic_sleepable_preload+0x5e2d> */
	goto x86_l_5e2d;
x86_l_5c93:
	/* 0x5c93: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5c98:
	/* 0x5c98: movzx  ecx,BYTE PTR [rbx+0x273] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 627ULL);
x86_l_5c9f:
	/* 0x5c9f: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_5ca6:
	/* 0x5ca6: mov    rdx,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_5cad:
	/* 0x5cad: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_5cb2:
	/* 0x5cb2: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5cb5:
	/* 0x5cb5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5cba:
	/* 0x5cba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5cbf:
	/* 0x5cbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cc1:
	/* 0x5cc1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5cc3:
	/* 0x5cc3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5cc6:
	/* 0x5cc6: je     5080 <generic_sleepable_preload+0x5080> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20608ULL;
	}
x86_l_5ccc:
	/* 0x5ccc: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_5cce:
	/* 0x5cce: jmp    50fb <generic_sleepable_preload+0x50fb> */
	return 20731ULL;
x86_l_5cd3:
	/* 0x5cd3: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_5cd8:
	/* 0x5cd8: jmp    5cfa <generic_sleepable_preload+0x5cfa> */
	goto x86_l_5cfa;
x86_l_5cda:
	/* 0x5cda: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_5cdf:
	/* 0x5cdf: jmp    5e2d <generic_sleepable_preload+0x5e2d> */
	goto x86_l_5e2d;
x86_l_5ce4:
	/* 0x5ce4: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_5ce9:
	/* 0x5ce9: jmp    5cfa <generic_sleepable_preload+0x5cfa> */
	goto x86_l_5cfa;
x86_l_5ceb:
	/* 0x5ceb: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_5cf0:
	/* 0x5cf0: jmp    5e2d <generic_sleepable_preload+0x5e2d> */
	goto x86_l_5e2d;
x86_l_5cf5:
	/* 0x5cf5: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_5cfa:
	/* 0x5cfa: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cfd:
	/* 0x5cfd: mov    ebx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5d00:
	/* 0x5d00: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5d05:
	/* 0x5d05: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d0a:
	/* 0x5d0a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d0f:
	/* 0x5d0f: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_5d12:
	/* 0x5d12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d14:
	/* 0x5d14: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5d17:
	/* 0x5d17: jne    4ec5 <generic_sleepable_preload+0x4ec5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 20165ULL;
	}
x86_l_5d1d:
	/* 0x5d1d: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d22:
	/* 0x5d22: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5d27:
	/* 0x5d27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d29:
	/* 0x5d29: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5d2e:
	/* 0x5d2e: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_5d36:
	/* 0x5d36: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5d3b:
	/* 0x5d3b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5d42:
	/* 0x5d42: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d47:
	/* 0x5d47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d49:
	/* 0x5d49: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5d4c:
	/* 0x5d4c: je     4ec5 <generic_sleepable_preload+0x4ec5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20165ULL;
	}
x86_l_5d52:
	/* 0x5d52: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_5d58:
	/* 0x5d58: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_5d5f:
	/* 0x5d5f: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5d64:
	/* 0x5d64: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5d67:
	/* 0x5d67: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5d6a:
	/* 0x5d6a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5d6d:
	/* 0x5d6d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d6f:
	/* 0x5d6f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5d72:
	/* 0x5d72: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5d77:
	/* 0x5d77: jmp    5e93 <generic_sleepable_preload+0x5e93> */
	goto x86_l_5e93;
x86_l_5d7c:
	/* 0x5d7c: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_5d81:
	/* 0x5d81: jmp    5e2d <generic_sleepable_preload+0x5e2d> */
	goto x86_l_5e2d;
x86_l_5d86:
	/* 0x5d86: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5d8b:
	/* 0x5d8b: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d8e:
	/* 0x5d8e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d93:
	/* 0x5d93: jmp    1f38 <generic_sleepable_preload+0x1f38> */
	return 7992ULL;
x86_l_5d98:
	/* 0x5d98: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5d9d:
	/* 0x5d9d: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5da0:
	/* 0x5da0: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5da5:
	/* 0x5da5: jmp    1fbf <generic_sleepable_preload+0x1fbf> */
	return 8127ULL;
x86_l_5daa:
	/* 0x5daa: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5daf:
	/* 0x5daf: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5db2:
	/* 0x5db2: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5db7:
	/* 0x5db7: jmp    2eab <generic_sleepable_preload+0x2eab> */
	return 11947ULL;
x86_l_5dbc:
	/* 0x5dbc: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5dc1:
	/* 0x5dc1: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5dc4:
	/* 0x5dc4: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5dc9:
	/* 0x5dc9: jmp    2f32 <generic_sleepable_preload+0x2f32> */
	return 12082ULL;
x86_l_5dce:
	/* 0x5dce: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5dd3:
	/* 0x5dd3: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5dd6:
	/* 0x5dd6: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ddb:
	/* 0x5ddb: jmp    3e1f <generic_sleepable_preload+0x3e1f> */
	return 15903ULL;
x86_l_5de0:
	/* 0x5de0: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5de5:
	/* 0x5de5: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5de8:
	/* 0x5de8: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ded:
	/* 0x5ded: jmp    3ea6 <generic_sleepable_preload+0x3ea6> */
	return 16038ULL;
x86_l_5df2:
	/* 0x5df2: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5df7:
	/* 0x5df7: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5dfa:
	/* 0x5dfa: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5dff:
	/* 0x5dff: jmp    4d8e <generic_sleepable_preload+0x4d8e> */
	return 19854ULL;
x86_l_5e04:
	/* 0x5e04: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5e09:
	/* 0x5e09: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5e0c:
	/* 0x5e0c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e11:
	/* 0x5e11: jmp    4e15 <generic_sleepable_preload+0x4e15> */
	return 19989ULL;
x86_l_5e16:
	/* 0x5e16: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5e1b:
	/* 0x5e1b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5e1e:
	/* 0x5e1e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e23:
	/* 0x5e23: jmp    5cfd <generic_sleepable_preload+0x5cfd> */
	goto x86_l_5cfd;
x86_l_5e28:
	/* 0x5e28: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5e2d:
	/* 0x5e2d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5e30:
	/* 0x5e30: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5e33:
	/* 0x5e33: jne    4ec5 <generic_sleepable_preload+0x4ec5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 20165ULL;
	}
x86_l_5e39:
	/* 0x5e39: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e3e:
	/* 0x5e3e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5e43:
	/* 0x5e43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e45:
	/* 0x5e45: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e4a:
	/* 0x5e4a: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5e52:
	/* 0x5e52: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5e57:
	/* 0x5e57: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5e5e:
	/* 0x5e5e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e63:
	/* 0x5e63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e65:
	/* 0x5e65: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5e68:
	/* 0x5e68: je     4ec5 <generic_sleepable_preload+0x4ec5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20165ULL;
	}
x86_l_5e6e:
	/* 0x5e6e: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_5e74:
	/* 0x5e74: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_5e7b:
	/* 0x5e7b: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e80:
	/* 0x5e80: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5e83:
	/* 0x5e83: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5e86:
	/* 0x5e86: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5e89:
	/* 0x5e89: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5e8b:
	/* 0x5e8b: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5e8e:
	/* 0x5e8e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5e93:
	/* 0x5e93: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5e96:
	/* 0x5e96: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5e99:
	/* 0x5e99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e9b:
	/* 0x5e9b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5e9e:
	/* 0x5e9e: je     4ec5 <generic_sleepable_preload+0x4ec5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20165ULL;
	}
x86_l_5ea4:
	/* 0x5ea4: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_5ea7:
	/* 0x5ea7: je     5ed1 <generic_sleepable_preload+0x5ed1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ed1;
	}
x86_l_5ea9:
	/* 0x5ea9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_5eac:
	/* 0x5eac: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_5eb0:
	/* 0x5eb0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5eb5:
	/* 0x5eb5: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_5eb8:
	/* 0x5eb8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5eba:
	/* 0x5eba: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_5ebd:
	/* 0x5ebd: call   5ec2 <generic_sleepable_preload+0x5ec2> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_5ec2:
	/* 0x5ec2: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_5ec4:
	/* 0x5ec4: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_5ec7:
	/* 0x5ec7: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_5ec9:
	/* 0x5ec9: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_5ece:
	/* 0x5ece: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_5ed1:
	/* 0x5ed1: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ed3:
	/* 0x5ed3: jmp    4ec5 <generic_sleepable_preload+0x4ec5> */
	return 20165ULL;
x86_l_5ed8:
	/* 0x5ed8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5edb:
	/* 0x5edb: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5ee0:
	/* 0x5ee0: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ee5:
	/* 0x5ee5: jmp    5cfd <generic_sleepable_preload+0x5cfd> */
	goto x86_l_5cfd;
x86_l_5eea:
	/* 0x5eea: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5eed:
	/* 0x5eed: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5ef2:
	/* 0x5ef2: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5ef5:
	/* 0x5ef5: je     5e39 <generic_sleepable_preload+0x5e39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e39;
	}
x86_l_5efb:
	/* 0x5efb: jmp    4ec5 <generic_sleepable_preload+0x4ec5> */
	return 20165ULL;
x86_l_5f00:
	/* 0x5f00: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f03:
	/* 0x5f03: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5f08:
	/* 0x5f08: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f0d:
	/* 0x5f0d: jmp    1f38 <generic_sleepable_preload+0x1f38> */
	return 7992ULL;
x86_l_5f12:
	/* 0x5f12: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f15:
	/* 0x5f15: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5f1a:
	/* 0x5f1a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f1f:
	/* 0x5f1f: jmp    1fbf <generic_sleepable_preload+0x1fbf> */
	return 8127ULL;
x86_l_5f24:
	/* 0x5f24: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f27:
	/* 0x5f27: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5f2c:
	/* 0x5f2c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f31:
	/* 0x5f31: jmp    2eab <generic_sleepable_preload+0x2eab> */
	return 11947ULL;
x86_l_5f36:
	/* 0x5f36: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f39:
	/* 0x5f39: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5f3e:
	/* 0x5f3e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f43:
	/* 0x5f43: jmp    2f32 <generic_sleepable_preload+0x2f32> */
	return 12082ULL;
x86_l_5f48:
	/* 0x5f48: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f4b:
	/* 0x5f4b: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5f50:
	/* 0x5f50: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f55:
	/* 0x5f55: jmp    3e1f <generic_sleepable_preload+0x3e1f> */
	return 15903ULL;
x86_l_5f5a:
	/* 0x5f5a: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f5d:
	/* 0x5f5d: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5f62:
	/* 0x5f62: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f67:
	/* 0x5f67: jmp    3ea6 <generic_sleepable_preload+0x3ea6> */
	return 16038ULL;
x86_l_5f6c:
	/* 0x5f6c: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f6f:
	/* 0x5f6f: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5f74:
	/* 0x5f74: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f79:
	/* 0x5f79: jmp    4d8e <generic_sleepable_preload+0x4d8e> */
	return 19854ULL;
x86_l_5f7e:
	/* 0x5f7e: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f81:
	/* 0x5f81: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5f86:
	/* 0x5f86: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f8b:
	/* 0x5f8b: jmp    4e15 <generic_sleepable_preload+0x4e15> */
	return 19989ULL;
x86_l_5f90:
	/* 0x5f90: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_5f95:
	/* 0x5f95: jmp    5e1b <generic_sleepable_preload+0x5e1b> */
	goto x86_l_5e1b;
x86_l_5f9a:
	/* 0x5f9a: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_5f9f:
	/* 0x5f9f: jmp    5e2d <generic_sleepable_preload+0x5e2d> */
	goto x86_l_5e2d;
x86_l_5fa4:
	/* 0x5fa4: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fa7:
	/* 0x5fa7: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5fac:
	/* 0x5fac: jmp    607e <generic_sleepable_preload+0x607e> */
	goto x86_l_607e;
x86_l_5fb1:
	/* 0x5fb1: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fb4:
	/* 0x5fb4: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5fb9:
	/* 0x5fb9: jmp    6098 <generic_sleepable_preload+0x6098> */
	goto x86_l_6098;
x86_l_5fbe:
	/* 0x5fbe: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fc1:
	/* 0x5fc1: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5fc6:
	/* 0x5fc6: jmp    60b2 <generic_sleepable_preload+0x60b2> */
	goto x86_l_60b2;
x86_l_5fcb:
	/* 0x5fcb: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fce:
	/* 0x5fce: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5fd3:
	/* 0x5fd3: jmp    60c7 <generic_sleepable_preload+0x60c7> */
	goto x86_l_60c7;
x86_l_5fd8:
	/* 0x5fd8: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fdb:
	/* 0x5fdb: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5fe0:
	/* 0x5fe0: jmp    60dc <generic_sleepable_preload+0x60dc> */
	goto x86_l_60dc;
x86_l_5fe5:
	/* 0x5fe5: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fe8:
	/* 0x5fe8: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5fed:
	/* 0x5fed: jmp    60f1 <generic_sleepable_preload+0x60f1> */
	goto x86_l_60f1;
x86_l_5ff2:
	/* 0x5ff2: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ff5:
	/* 0x5ff5: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5ffa:
	/* 0x5ffa: jmp    6106 <generic_sleepable_preload+0x6106> */
	goto x86_l_6106;
x86_l_5fff:
	/* 0x5fff: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6002:
	/* 0x6002: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_6007:
	/* 0x6007: jmp    611b <generic_sleepable_preload+0x611b> */
	goto x86_l_611b;
x86_l_600c:
	/* 0x600c: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_6011:
	/* 0x6011: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6014:
	/* 0x6014: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6019:
	/* 0x6019: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_601e:
	/* 0x601e: jmp    1f38 <generic_sleepable_preload+0x1f38> */
	return 7992ULL;
x86_l_6023:
	/* 0x6023: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_6028:
	/* 0x6028: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_602b:
	/* 0x602b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6030:
	/* 0x6030: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6035:
	/* 0x6035: jmp    1fbf <generic_sleepable_preload+0x1fbf> */
	return 8127ULL;
x86_l_603a:
	/* 0x603a: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_603f:
	/* 0x603f: jmp    5daf <generic_sleepable_preload+0x5daf> */
	goto x86_l_5daf;
x86_l_6044:
	/* 0x6044: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_6049:
	/* 0x6049: jmp    5dc1 <generic_sleepable_preload+0x5dc1> */
	goto x86_l_5dc1;
x86_l_604e:
	/* 0x604e: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_6053:
	/* 0x6053: jmp    5dd3 <generic_sleepable_preload+0x5dd3> */
	goto x86_l_5dd3;
x86_l_6058:
	/* 0x6058: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_605d:
	/* 0x605d: jmp    5de5 <generic_sleepable_preload+0x5de5> */
	goto x86_l_5de5;
x86_l_6062:
	/* 0x6062: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_6067:
	/* 0x6067: jmp    5df7 <generic_sleepable_preload+0x5df7> */
	goto x86_l_5df7;
x86_l_606c:
	/* 0x606c: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_6071:
	/* 0x6071: jmp    5e09 <generic_sleepable_preload+0x5e09> */
	goto x86_l_5e09;
x86_l_6076:
	/* 0x6076: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_607b:
	/* 0x607b: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_607e:
	/* 0x607e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6083:
	/* 0x6083: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6088:
	/* 0x6088: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_608b:
	/* 0x608b: jmp    1f38 <generic_sleepable_preload+0x1f38> */
	return 7992ULL;
x86_l_6090:
	/* 0x6090: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_6095:
	/* 0x6095: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6098:
	/* 0x6098: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_609d:
	/* 0x609d: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_60a2:
	/* 0x60a2: mov    r12,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_64);
x86_l_60a5:
	/* 0x60a5: jmp    1fbf <generic_sleepable_preload+0x1fbf> */
	return 8127ULL;
x86_l_60aa:
	/* 0x60aa: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_60af:
	/* 0x60af: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_60b2:
	/* 0x60b2: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_60b7:
	/* 0x60b7: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_60ba:
	/* 0x60ba: jmp    2eab <generic_sleepable_preload+0x2eab> */
	return 11947ULL;
x86_l_60bf:
	/* 0x60bf: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_60c4:
	/* 0x60c4: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_60c7:
	/* 0x60c7: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_60cc:
	/* 0x60cc: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_60cf:
	/* 0x60cf: jmp    2f32 <generic_sleepable_preload+0x2f32> */
	return 12082ULL;
x86_l_60d4:
	/* 0x60d4: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_60d9:
	/* 0x60d9: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_60dc:
	/* 0x60dc: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_60e1:
	/* 0x60e1: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_60e4:
	/* 0x60e4: jmp    3e1f <generic_sleepable_preload+0x3e1f> */
	return 15903ULL;
x86_l_60e9:
	/* 0x60e9: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_60ee:
	/* 0x60ee: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_60f1:
	/* 0x60f1: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_60f6:
	/* 0x60f6: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_60f9:
	/* 0x60f9: jmp    3ea6 <generic_sleepable_preload+0x3ea6> */
	return 16038ULL;
x86_l_60fe:
	/* 0x60fe: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_6103:
	/* 0x6103: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6106:
	/* 0x6106: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_610b:
	/* 0x610b: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_610e:
	/* 0x610e: jmp    4d8e <generic_sleepable_preload+0x4d8e> */
	return 19854ULL;
x86_l_6113:
	/* 0x6113: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_6118:
	/* 0x6118: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_611b:
	/* 0x611b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6120:
	/* 0x6120: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_6123:
	/* 0x6123: jmp    4e15 <generic_sleepable_preload+0x4e15> */
	return 19989ULL;
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
	for (__u32 __x86_iter = 0; __x86_iter < 21232U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1801ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1806ULL && __x86_pc <= 3584ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3591ULL && __x86_pc <= 5351ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5356ULL && __x86_pc <= 7175ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7180ULL && __x86_pc <= 8915ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8918ULL && __x86_pc <= 10757ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10762ULL && __x86_pc <= 12541ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12546ULL && __x86_pc <= 14363ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14369ULL && __x86_pc <= 16182ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 16184ULL && __x86_pc <= 18020ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 18026ULL && __x86_pc <= 19854ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 19857ULL && __x86_pc <= 21608ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 21610ULL && __x86_pc <= 23463ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 23468ULL && __x86_pc <= 24867ULL)
			__x86_pc = tetragon_bpf_multi_usdt_v511_generic_sleepable_preload_x86_chunk_13(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

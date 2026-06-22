extern char CONFIG_ITER_NUM;
extern char buffer_heap_map;
extern char config_map;
extern char fdinstall_map;
extern char process_call_heap;
extern char retprobe_map;
extern char socktrack_map;
extern char tg_errmetrics_map;
extern char tg_ipv6_ext_heap;
extern char tp_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_process_event_x86_chunk_0(
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
	case 68ULL: goto x86_l_44;
	case 75ULL: goto x86_l_4b;
	case 81ULL: goto x86_l_51;
	case 92ULL: goto x86_l_5c;
	case 97ULL: goto x86_l_61;
	case 104ULL: goto x86_l_68;
	case 112ULL: goto x86_l_70;
	case 114ULL: goto x86_l_72;
	case 117ULL: goto x86_l_75;
	case 123ULL: goto x86_l_7b;
	case 126ULL: goto x86_l_7e;
	case 133ULL: goto x86_l_85;
	case 138ULL: goto x86_l_8a;
	case 145ULL: goto x86_l_91;
	case 147ULL: goto x86_l_93;
	case 151ULL: goto x86_l_97;
	case 157ULL: goto x86_l_9d;
	case 160ULL: goto x86_l_a0;
	case 166ULL: goto x86_l_a6;
	case 174ULL: goto x86_l_ae;
	case 182ULL: goto x86_l_b6;
	case 185ULL: goto x86_l_b9;
	case 188ULL: goto x86_l_bc;
	case 190ULL: goto x86_l_be;
	case 195ULL: goto x86_l_c3;
	case 200ULL: goto x86_l_c8;
	case 212ULL: goto x86_l_d4;
	case 220ULL: goto x86_l_dc;
	case 228ULL: goto x86_l_e4;
	case 234ULL: goto x86_l_ea;
	case 236ULL: goto x86_l_ec;
	case 239ULL: goto x86_l_ef;
	case 241ULL: goto x86_l_f1;
	case 244ULL: goto x86_l_f4;
	case 249ULL: goto x86_l_f9;
	case 252ULL: goto x86_l_fc;
	case 264ULL: goto x86_l_108;
	case 266ULL: goto x86_l_10a;
	case 271ULL: goto x86_l_10f;
	case 274ULL: goto x86_l_112;
	case 278ULL: goto x86_l_116;
	case 281ULL: goto x86_l_119;
	case 287ULL: goto x86_l_11f;
	case 293ULL: goto x86_l_125;
	case 296ULL: goto x86_l_128;
	case 300ULL: goto x86_l_12c;
	case 305ULL: goto x86_l_131;
	case 313ULL: goto x86_l_139;
	case 318ULL: goto x86_l_13e;
	case 323ULL: goto x86_l_143;
	case 327ULL: goto x86_l_147;
	case 333ULL: goto x86_l_14d;
	case 338ULL: goto x86_l_152;
	case 345ULL: goto x86_l_159;
	case 348ULL: goto x86_l_15c;
	case 350ULL: goto x86_l_15e;
	case 353ULL: goto x86_l_161;
	case 355ULL: goto x86_l_163;
	case 360ULL: goto x86_l_168;
	case 365ULL: goto x86_l_16d;
	case 368ULL: goto x86_l_170;
	case 373ULL: goto x86_l_175;
	case 375ULL: goto x86_l_177;
	case 377ULL: goto x86_l_179;
	case 379ULL: goto x86_l_17b;
	case 382ULL: goto x86_l_17e;
	case 386ULL: goto x86_l_182;
	case 388ULL: goto x86_l_184;
	case 393ULL: goto x86_l_189;
	case 400ULL: goto x86_l_190;
	case 402ULL: goto x86_l_192;
	case 407ULL: goto x86_l_197;
	case 411ULL: goto x86_l_19b;
	case 414ULL: goto x86_l_19e;
	case 421ULL: goto x86_l_1a5;
	case 423ULL: goto x86_l_1a7;
	case 428ULL: goto x86_l_1ac;
	case 430ULL: goto x86_l_1ae;
	case 435ULL: goto x86_l_1b3;
	case 437ULL: goto x86_l_1b5;
	case 442ULL: goto x86_l_1ba;
	case 449ULL: goto x86_l_1c1;
	case 454ULL: goto x86_l_1c6;
	case 459ULL: goto x86_l_1cb;
	case 461ULL: goto x86_l_1cd;
	case 463ULL: goto x86_l_1cf;
	case 465ULL: goto x86_l_1d1;
	case 468ULL: goto x86_l_1d4;
	case 473ULL: goto x86_l_1d9;
	case 476ULL: goto x86_l_1dc;
	case 484ULL: goto x86_l_1e4;
	case 490ULL: goto x86_l_1ea;
	case 494ULL: goto x86_l_1ee;
	case 496ULL: goto x86_l_1f0;
	case 500ULL: goto x86_l_1f4;
	case 502ULL: goto x86_l_1f6;
	case 506ULL: goto x86_l_1fa;
	case 512ULL: goto x86_l_200;
	case 516ULL: goto x86_l_204;
	case 522ULL: goto x86_l_20a;
	case 526ULL: goto x86_l_20e;
	case 529ULL: goto x86_l_211;
	case 535ULL: goto x86_l_217;
	case 539ULL: goto x86_l_21b;
	case 545ULL: goto x86_l_221;
	case 550ULL: goto x86_l_226;
	case 554ULL: goto x86_l_22a;
	case 556ULL: goto x86_l_22c;
	case 560ULL: goto x86_l_230;
	case 566ULL: goto x86_l_236;
	case 570ULL: goto x86_l_23a;
	case 573ULL: goto x86_l_23d;
	case 579ULL: goto x86_l_243;
	case 583ULL: goto x86_l_247;
	case 589ULL: goto x86_l_24d;
	case 593ULL: goto x86_l_251;
	case 599ULL: goto x86_l_257;
	case 604ULL: goto x86_l_25c;
	case 608ULL: goto x86_l_260;
	case 614ULL: goto x86_l_266;
	case 618ULL: goto x86_l_26a;
	case 621ULL: goto x86_l_26d;
	case 627ULL: goto x86_l_273;
	case 631ULL: goto x86_l_277;
	case 634ULL: goto x86_l_27a;
	case 640ULL: goto x86_l_280;
	case 645ULL: goto x86_l_285;
	case 649ULL: goto x86_l_289;
	case 655ULL: goto x86_l_28f;
	case 659ULL: goto x86_l_293;
	case 665ULL: goto x86_l_299;
	case 669ULL: goto x86_l_29d;
	case 675ULL: goto x86_l_2a3;
	case 679ULL: goto x86_l_2a7;
	case 685ULL: goto x86_l_2ad;
	case 690ULL: goto x86_l_2b2;
	case 694ULL: goto x86_l_2b6;
	case 700ULL: goto x86_l_2bc;
	case 704ULL: goto x86_l_2c0;
	case 710ULL: goto x86_l_2c6;
	case 714ULL: goto x86_l_2ca;
	case 720ULL: goto x86_l_2d0;
	case 724ULL: goto x86_l_2d4;
	case 730ULL: goto x86_l_2da;
	case 736ULL: goto x86_l_2e0;
	case 741ULL: goto x86_l_2e5;
	case 745ULL: goto x86_l_2e9;
	case 751ULL: goto x86_l_2ef;
	case 755ULL: goto x86_l_2f3;
	case 761ULL: goto x86_l_2f9;
	case 765ULL: goto x86_l_2fd;
	case 767ULL: goto x86_l_2ff;
	case 771ULL: goto x86_l_303;
	case 777ULL: goto x86_l_309;
	case 782ULL: goto x86_l_30e;
	case 786ULL: goto x86_l_312;
	case 788ULL: goto x86_l_314;
	case 791ULL: goto x86_l_317;
	case 795ULL: goto x86_l_31b;
	case 801ULL: goto x86_l_321;
	case 805ULL: goto x86_l_325;
	case 807ULL: goto x86_l_327;
	case 809ULL: goto x86_l_329;
	case 813ULL: goto x86_l_32d;
	case 816ULL: goto x86_l_330;
	case 818ULL: goto x86_l_332;
	case 824ULL: goto x86_l_338;
	case 826ULL: goto x86_l_33a;
	case 832ULL: goto x86_l_340;
	case 834ULL: goto x86_l_342;
	case 838ULL: goto x86_l_346;
	case 840ULL: goto x86_l_348;
	case 844ULL: goto x86_l_34c;
	case 846ULL: goto x86_l_34e;
	case 852ULL: goto x86_l_354;
	case 854ULL: goto x86_l_356;
	case 858ULL: goto x86_l_35a;
	case 860ULL: goto x86_l_35c;
	case 864ULL: goto x86_l_360;
	case 866ULL: goto x86_l_362;
	case 868ULL: goto x86_l_364;
	case 874ULL: goto x86_l_36a;
	case 876ULL: goto x86_l_36c;
	case 880ULL: goto x86_l_370;
	case 882ULL: goto x86_l_372;
	case 886ULL: goto x86_l_376;
	case 888ULL: goto x86_l_378;
	case 894ULL: goto x86_l_37e;
	case 896ULL: goto x86_l_380;
	case 902ULL: goto x86_l_386;
	case 904ULL: goto x86_l_388;
	case 910ULL: goto x86_l_38e;
	case 912ULL: goto x86_l_390;
	case 916ULL: goto x86_l_394;
	case 918ULL: goto x86_l_396;
	case 924ULL: goto x86_l_39c;
	case 926ULL: goto x86_l_39e;
	case 929ULL: goto x86_l_3a1;
	case 934ULL: goto x86_l_3a6;
	case 945ULL: goto x86_l_3b1;
	case 950ULL: goto x86_l_3b6;
	case 957ULL: goto x86_l_3bd;
	case 965ULL: goto x86_l_3c5;
	case 967ULL: goto x86_l_3c7;
	case 970ULL: goto x86_l_3ca;
	case 972ULL: goto x86_l_3cc;
	case 977ULL: goto x86_l_3d1;
	case 980ULL: goto x86_l_3d4;
	case 983ULL: goto x86_l_3d7;
	case 985ULL: goto x86_l_3d9;
	case 993ULL: goto x86_l_3e1;
	case 1000ULL: goto x86_l_3e8;
	case 1004ULL: goto x86_l_3ec;
	case 1012ULL: goto x86_l_3f4;
	case 1017ULL: goto x86_l_3f9;
	case 1019ULL: goto x86_l_3fb;
	case 1025ULL: goto x86_l_401;
	case 1033ULL: goto x86_l_409;
	case 1041ULL: goto x86_l_411;
	case 1046ULL: goto x86_l_416;
	case 1054ULL: goto x86_l_41e;
	case 1062ULL: goto x86_l_426;
	case 1066ULL: goto x86_l_42a;
	case 1070ULL: goto x86_l_42e;
	case 1076ULL: goto x86_l_434;
	case 1084ULL: goto x86_l_43c;
	case 1089ULL: goto x86_l_441;
	case 1096ULL: goto x86_l_448;
	case 1101ULL: goto x86_l_44d;
	case 1103ULL: goto x86_l_44f;
	case 1106ULL: goto x86_l_452;
	case 1112ULL: goto x86_l_458;
	case 1118ULL: goto x86_l_45e;
	case 1123ULL: goto x86_l_463;
	case 1130ULL: goto x86_l_46a;
	case 1133ULL: goto x86_l_46d;
	case 1135ULL: goto x86_l_46f;
	case 1138ULL: goto x86_l_472;
	case 1144ULL: goto x86_l_478;
	case 1147ULL: goto x86_l_47b;
	case 1150ULL: goto x86_l_47e;
	case 1153ULL: goto x86_l_481;
	case 1158ULL: goto x86_l_486;
	case 1164ULL: goto x86_l_48c;
	case 1171ULL: goto x86_l_493;
	case 1176ULL: goto x86_l_498;
	case 1183ULL: goto x86_l_49f;
	case 1186ULL: goto x86_l_4a2;
	case 1191ULL: goto x86_l_4a7;
	case 1193ULL: goto x86_l_4a9;
	case 1198ULL: goto x86_l_4ae;
	case 1201ULL: goto x86_l_4b1;
	case 1208ULL: goto x86_l_4b8;
	case 1214ULL: goto x86_l_4be;
	case 1217ULL: goto x86_l_4c1;
	case 1222ULL: goto x86_l_4c6;
	case 1227ULL: goto x86_l_4cb;
	case 1239ULL: goto x86_l_4d7;
	case 1243ULL: goto x86_l_4db;
	case 1248ULL: goto x86_l_4e0;
	case 1253ULL: goto x86_l_4e5;
	case 1255ULL: goto x86_l_4e7;
	case 1259ULL: goto x86_l_4eb;
	case 1261ULL: goto x86_l_4ed;
	case 1265ULL: goto x86_l_4f1;
	case 1267ULL: goto x86_l_4f3;
	case 1271ULL: goto x86_l_4f7;
	case 1277ULL: goto x86_l_4fd;
	case 1282ULL: goto x86_l_502;
	case 1287ULL: goto x86_l_507;
	case 1292ULL: goto x86_l_50c;
	case 1297ULL: goto x86_l_511;
	case 1299ULL: goto x86_l_513;
	case 1304ULL: goto x86_l_518;
	case 1309ULL: goto x86_l_51d;
	case 1311ULL: goto x86_l_51f;
	case 1315ULL: goto x86_l_523;
	case 1321ULL: goto x86_l_529;
	case 1325ULL: goto x86_l_52d;
	case 1331ULL: goto x86_l_533;
	case 1336ULL: goto x86_l_538;
	case 1341ULL: goto x86_l_53d;
	case 1346ULL: goto x86_l_542;
	case 1348ULL: goto x86_l_544;
	case 1360ULL: goto x86_l_550;
	case 1368ULL: goto x86_l_558;
	case 1376ULL: goto x86_l_560;
	case 1378ULL: goto x86_l_562;
	case 1382ULL: goto x86_l_566;
	case 1387ULL: goto x86_l_56b;
	case 1392ULL: goto x86_l_570;
	case 1397ULL: goto x86_l_575;
	case 1402ULL: goto x86_l_57a;
	case 1407ULL: goto x86_l_57f;
	case 1409ULL: goto x86_l_581;
	case 1414ULL: goto x86_l_586;
	case 1418ULL: goto x86_l_58a;
	case 1423ULL: goto x86_l_58f;
	case 1434ULL: goto x86_l_59a;
	case 1439ULL: goto x86_l_59f;
	case 1446ULL: goto x86_l_5a6;
	case 1454ULL: goto x86_l_5ae;
	case 1456ULL: goto x86_l_5b0;
	case 1459ULL: goto x86_l_5b3;
	case 1465ULL: goto x86_l_5b9;
	case 1468ULL: goto x86_l_5bc;
	case 1472ULL: goto x86_l_5c0;
	case 1478ULL: goto x86_l_5c6;
	case 1483ULL: goto x86_l_5cb;
	case 1488ULL: goto x86_l_5d0;
	case 1490ULL: goto x86_l_5d2;
	case 1497ULL: goto x86_l_5d9;
	case 1502ULL: goto x86_l_5de;
	case 1510ULL: goto x86_l_5e6;
	case 1515ULL: goto x86_l_5eb;
	case 1517ULL: goto x86_l_5ed;
	case 1525ULL: goto x86_l_5f5;
	case 1529ULL: goto x86_l_5f9;
	case 1537ULL: goto x86_l_601;
	case 1542ULL: goto x86_l_606;
	case 1546ULL: goto x86_l_60a;
	case 1551ULL: goto x86_l_60f;
	case 1559ULL: goto x86_l_617;
	case 1564ULL: goto x86_l_61c;
	case 1572ULL: goto x86_l_624;
	case 1574ULL: goto x86_l_626;
	case 1582ULL: goto x86_l_62e;
	case 1586ULL: goto x86_l_632;
	case 1591ULL: goto x86_l_637;
	case 1596ULL: goto x86_l_63c;
	case 1601ULL: goto x86_l_641;
	case 1603ULL: goto x86_l_643;
	case 1609ULL: goto x86_l_649;
	case 1615ULL: goto x86_l_64f;
	case 1617ULL: goto x86_l_651;
	case 1622ULL: goto x86_l_656;
	case 1624ULL: goto x86_l_658;
	case 1628ULL: goto x86_l_65c;
	case 1633ULL: goto x86_l_661;
	case 1638ULL: goto x86_l_666;
	case 1643ULL: goto x86_l_66b;
	case 1645ULL: goto x86_l_66d;
	case 1650ULL: goto x86_l_672;
	case 1655ULL: goto x86_l_677;
	case 1657ULL: goto x86_l_679;
	case 1660ULL: goto x86_l_67c;
	case 1667ULL: goto x86_l_683;
	case 1677ULL: goto x86_l_68d;
	case 1684ULL: goto x86_l_694;
	case 1694ULL: goto x86_l_69e;
	case 1700ULL: goto x86_l_6a4;
	case 1709ULL: goto x86_l_6ad;
	case 1718ULL: goto x86_l_6b6;
	case 1723ULL: goto x86_l_6bb;
	case 1728ULL: goto x86_l_6c0;
	case 1733ULL: goto x86_l_6c5;
	case 1742ULL: goto x86_l_6ce;
	case 1751ULL: goto x86_l_6d7;
	case 1760ULL: goto x86_l_6e0;
	case 1765ULL: goto x86_l_6e5;
	case 1770ULL: goto x86_l_6ea;
	case 1775ULL: goto x86_l_6ef;
	case 1780ULL: goto x86_l_6f4;
	case 1785ULL: goto x86_l_6f9;
	case 1789ULL: goto x86_l_6fd;
	case 1794ULL: goto x86_l_702;
	case 1799ULL: goto x86_l_707;
	case 1804ULL: goto x86_l_70c;
	case 1807ULL: goto x86_l_70f;
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
	/* 0x3: sub    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 264ULL);
x86_l_a:
	/* 0xa: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0xec],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_18:
	/* 0x18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_24:
	/* 0x24: lea    rsi,[rsp+0xec] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 236ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: je     bf5 <generic_tracepoint_process_event+0xbf5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3061ULL;
	}
x86_l_37:
	/* 0x37: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    r13d,DWORD PTR [rax+0x5efc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24316ULL);
x86_l_41:
	/* 0x41: mov    ebx,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_44:
	/* 0x44: cmp    rbx,0x2327 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 8999ULL);
x86_l_4b:
	/* 0x4b: ja     426 <generic_tracepoint_process_event+0x426> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_426;
	}
x86_l_51:
	/* 0x51: mov    DWORD PTR [rsp+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_5c:
	/* 0x5c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_61:
	/* 0x61: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_68:
	/* 0x68: lea    rsi,[rsp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_70:
	/* 0x70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72:
	/* 0x72: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_75:
	/* 0x75: je     426 <generic_tracepoint_process_event+0x426> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_426;
	}
x86_l_7b:
	/* 0x7b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_7e:
	/* 0x7e: lea    rsi,[rax+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_85:
	/* 0x85: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8a:
	/* 0x8a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_91:
	/* 0x91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_93:
	/* 0x93: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_97:
	/* 0x97: jg     426 <generic_tracepoint_process_event+0x426> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_426;
	}
x86_l_9d:
	/* 0x9d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a0:
	/* 0xa0: je     426 <generic_tracepoint_process_event+0x426> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_426;
	}
x86_l_a6:
	/* 0xa6: mov    QWORD PTR [rsp+0xa8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_ae:
	/* 0xae: mov    QWORD PTR [rsp+0xd0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_b6:
	/* 0xb6: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_b9:
	/* 0xb9: and    edx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_bc:
	/* 0xbc: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_be:
	/* 0xbe: mov    r13d,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_c3:
	/* 0xc3: movsxd rbp,DWORD PTR [rax+rcx*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RCX, 2, X86_WIDTH_32), 24ULL);
x86_l_c8:
	/* 0xc8: mov    DWORD PTR [r15+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_d4:
	/* 0xd4: mov    rsi,QWORD PTR [r15+rcx*8+0x5e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24144ULL);
x86_l_dc:
	/* 0xdc: mov    QWORD PTR [rsp+0xe0],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_e4:
	/* 0xe4: test   ebp,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 256ULL);
x86_l_ea:
	/* 0xea: jne    f9 <generic_tracepoint_process_event+0xf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f9;
	}
x86_l_ec:
	/* 0xec: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_ef:
	/* 0xef: jbe    10f <generic_tracepoint_process_event+0x10f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_10f;
	}
x86_l_f1:
	/* 0xf1: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_f4:
	/* 0xf4: jmp    1e4 <generic_tracepoint_process_event+0x1e4> */
	goto x86_l_1e4;
x86_l_f9:
	/* 0xf9: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_fc:
	/* 0xfc: mov    QWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_108:
	/* 0x108: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10a:
	/* 0x10a: jmp    1e4 <generic_tracepoint_process_event+0x1e4> */
	goto x86_l_1e4;
x86_l_10f:
	/* 0x10f: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_112:
	/* 0x112: lea    rdx,[rdx+rdx*4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 2), 0ULL);
x86_l_116:
	/* 0x116: shl    edx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_119:
	/* 0x119: cmp    WORD PTR [rax+rdx*1+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RDX, 0), 506806140928ULL);
x86_l_11f:
	/* 0x11f: je     1e4 <generic_tracepoint_process_event+0x1e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e4;
	}
x86_l_125:
	/* 0x125: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_128:
	/* 0x128: add    rax,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_12c:
	/* 0x12c: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_131:
	/* 0x131: lea    rax,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_139:
	/* 0x139: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_13e:
	/* 0x13e: mov    BYTE PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_143:
	/* 0x143: lea    rax,[r15+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_147:
	/* 0x147: add    rax,0x5ea0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24224ULL);
x86_l_14d:
	/* 0x14d: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_152:
	/* 0x152: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_159:
	/* 0x159: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15c:
	/* 0x15c: je     1b5 <generic_tracepoint_process_event+0x1b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b5;
	}
x86_l_15e:
	/* 0x15e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_161:
	/* 0x161: jmp    184 <generic_tracepoint_process_event+0x184> */
	goto x86_l_184;
x86_l_163:
	/* 0x163: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_168:
	/* 0x168: mov    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_16d:
	/* 0x16d: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_170:
	/* 0x170: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_175:
	/* 0x175: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_177:
	/* 0x177: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_179:
	/* 0x179: js     1d1 <generic_tracepoint_process_event+0x1d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1d1;
	}
x86_l_17b:
	/* 0x17b: inc    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_17e:
	/* 0x17e: cmp    r15,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 10ULL);
x86_l_182:
	/* 0x182: je     1dc <generic_tracepoint_process_event+0x1dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dc;
	}
x86_l_184:
	/* 0x184: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_189:
	/* 0x189: cmp    WORD PTR [rax+r15*8+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 3), 25769803776ULL);
x86_l_190:
	/* 0x190: je     1dc <generic_tracepoint_process_event+0x1dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dc;
	}
x86_l_192:
	/* 0x192: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_197:
	/* 0x197: mov    edx,DWORD PTR [rax+r15*8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 3), 0ULL);
x86_l_19b:
	/* 0x19b: add    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RCX, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_19e:
	/* 0x19e: cmp    WORD PTR [rax+r15*8+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 3), 17179869184ULL);
x86_l_1a5:
	/* 0x1a5: je     17b <generic_tracepoint_process_event+0x17b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17b;
	}
x86_l_1a7:
	/* 0x1a7: cmp    BYTE PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1ac:
	/* 0x1ac: je     163 <generic_tracepoint_process_event+0x163> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_163;
	}
x86_l_1ae:
	/* 0x1ae: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b3:
	/* 0x1b3: jmp    168 <generic_tracepoint_process_event+0x168> */
	goto x86_l_168;
x86_l_1b5:
	/* 0x1b5: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_1ba:
	/* 0x1ba: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_1c1:
	/* 0x1c1: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c6:
	/* 0x1c6: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_1cb:
	/* 0x1cb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cd:
	/* 0x1cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cf:
	/* 0x1cf: jmp    1dc <generic_tracepoint_process_event+0x1dc> */
	goto x86_l_1dc;
x86_l_1d1:
	/* 0x1d1: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1d4:
	/* 0x1d4: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1d9:
	/* 0x1d9: mov    DWORD PTR [rax],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dc:
	/* 0x1dc: mov    rsi,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1e4:
	/* 0x1e4: mov    r15d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4096ULL);
x86_l_1ea:
	/* 0x1ea: cmp    r13d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 21ULL);
x86_l_1ee:
	/* 0x1ee: jg     226 <generic_tracepoint_process_event+0x226> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_226;
	}
x86_l_1f0:
	/* 0x1f0: cmp    r13d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 11ULL);
x86_l_1f4:
	/* 0x1f4: jg     25c <generic_tracepoint_process_event+0x25c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_25c;
	}
x86_l_1f6:
	/* 0x1f6: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_1fa:
	/* 0x1fa: jg     2e5 <generic_tracepoint_process_event+0x2e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2e5;
	}
x86_l_200:
	/* 0x200: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_204:
	/* 0x204: jg     36c <generic_tracepoint_process_event+0x36c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_36c;
	}
x86_l_20a:
	/* 0x20a: lea    eax,[r13-0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_20e:
	/* 0x20e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_211:
	/* 0x211: jb     332 <generic_tracepoint_process_event+0x332> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_332;
	}
x86_l_217:
	/* 0x217: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_21b:
	/* 0x21b: je     332 <generic_tracepoint_process_event+0x332> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_332;
	}
x86_l_221:
	/* 0x221: jmp    39e <generic_tracepoint_process_event+0x39e> */
	goto x86_l_39e;
x86_l_226:
	/* 0x226: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_22a:
	/* 0x22a: jle    285 <generic_tracepoint_process_event+0x285> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_285;
	}
x86_l_22c:
	/* 0x22c: cmp    r13d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 39ULL);
x86_l_230:
	/* 0x230: jg     2b2 <generic_tracepoint_process_event+0x2b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2b2;
	}
x86_l_236:
	/* 0x236: lea    eax,[r13-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_23a:
	/* 0x23a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23d:
	/* 0x23d: jb     380 <generic_tracepoint_process_event+0x380> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_380;
	}
x86_l_243:
	/* 0x243: cmp    r13d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 37ULL);
x86_l_247:
	/* 0x247: je     3a1 <generic_tracepoint_process_event+0x3a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a1;
	}
x86_l_24d:
	/* 0x24d: cmp    r13d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 39ULL);
x86_l_251:
	/* 0x251: je     33a <generic_tracepoint_process_event+0x33a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33a;
	}
x86_l_257:
	/* 0x257: jmp    39e <generic_tracepoint_process_event+0x39e> */
	goto x86_l_39e;
x86_l_25c:
	/* 0x25c: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_260:
	/* 0x260: jg     30e <generic_tracepoint_process_event+0x30e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_30e;
	}
x86_l_266:
	/* 0x266: lea    eax,[r13-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_26a:
	/* 0x26a: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_26d:
	/* 0x26d: jb     3a1 <generic_tracepoint_process_event+0x3a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3a1;
	}
x86_l_273:
	/* 0x273: lea    eax,[r13-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_277:
	/* 0x277: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_27a:
	/* 0x27a: jb     332 <generic_tracepoint_process_event+0x332> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_332;
	}
x86_l_280:
	/* 0x280: jmp    39e <generic_tracepoint_process_event+0x39e> */
	goto x86_l_39e;
x86_l_285:
	/* 0x285: cmp    r13d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 26ULL);
x86_l_289:
	/* 0x289: jg     329 <generic_tracepoint_process_event+0x329> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_329;
	}
x86_l_28f:
	/* 0x28f: cmp    r13d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 22ULL);
x86_l_293:
	/* 0x293: je     33a <generic_tracepoint_process_event+0x33a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33a;
	}
x86_l_299:
	/* 0x299: cmp    r13d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 23ULL);
x86_l_29d:
	/* 0x29d: je     380 <generic_tracepoint_process_event+0x380> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_380;
	}
x86_l_2a3:
	/* 0x2a3: cmp    r13d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 26ULL);
x86_l_2a7:
	/* 0x2a7: je     396 <generic_tracepoint_process_event+0x396> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_396;
	}
x86_l_2ad:
	/* 0x2ad: jmp    39e <generic_tracepoint_process_event+0x39e> */
	goto x86_l_39e;
x86_l_2b2:
	/* 0x2b2: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_2b6:
	/* 0x2b6: jle    356 <generic_tracepoint_process_event+0x356> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_356;
	}
x86_l_2bc:
	/* 0x2bc: cmp    r13d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 42ULL);
x86_l_2c0:
	/* 0x2c0: je     3a1 <generic_tracepoint_process_event+0x3a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a1;
	}
x86_l_2c6:
	/* 0x2c6: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_2ca:
	/* 0x2ca: je     364 <generic_tracepoint_process_event+0x364> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_364;
	}
x86_l_2d0:
	/* 0x2d0: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_2d4:
	/* 0x2d4: jne    39e <generic_tracepoint_process_event+0x39e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_39e;
	}
x86_l_2da:
	/* 0x2da: mov    r15d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 112ULL);
x86_l_2e0:
	/* 0x2e0: jmp    3a1 <generic_tracepoint_process_event+0x3a1> */
	goto x86_l_3a1;
x86_l_2e5:
	/* 0x2e5: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
x86_l_2e9:
	/* 0x2e9: jg     380 <generic_tracepoint_process_event+0x380> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_380;
	}
x86_l_2ef:
	/* 0x2ef: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_2f3:
	/* 0x2f3: je     3a1 <generic_tracepoint_process_event+0x3a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a1;
	}
x86_l_2f9:
	/* 0x2f9: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_2fd:
	/* 0x2fd: je     378 <generic_tracepoint_process_event+0x378> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_378;
	}
x86_l_2ff:
	/* 0x2ff: cmp    r13d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 8ULL);
x86_l_303:
	/* 0x303: je     396 <generic_tracepoint_process_event+0x396> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_396;
	}
x86_l_309:
	/* 0x309: jmp    39e <generic_tracepoint_process_event+0x39e> */
	goto x86_l_39e;
x86_l_30e:
	/* 0x30e: cmp    r13d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 19ULL);
x86_l_312:
	/* 0x312: jg     342 <generic_tracepoint_process_event+0x342> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_342;
	}
x86_l_314:
	/* 0x314: mov    r15,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_64);
x86_l_317:
	/* 0x317: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_31b:
	/* 0x31b: je     3a1 <generic_tracepoint_process_event+0x3a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a1;
	}
x86_l_321:
	/* 0x321: cmp    r13d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 19ULL);
x86_l_325:
	/* 0x325: je     364 <generic_tracepoint_process_event+0x364> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_364;
	}
x86_l_327:
	/* 0x327: jmp    39e <generic_tracepoint_process_event+0x39e> */
	goto x86_l_39e;
x86_l_329:
	/* 0x329: lea    eax,[r13-0x1d] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_32d:
	/* 0x32d: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_330:
	/* 0x330: jae    390 <generic_tracepoint_process_event+0x390> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_390;
	}
x86_l_332:
	/* 0x332: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_338:
	/* 0x338: jmp    3a1 <generic_tracepoint_process_event+0x3a1> */
	goto x86_l_3a1;
x86_l_33a:
	/* 0x33a: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_340:
	/* 0x340: jmp    3a1 <generic_tracepoint_process_event+0x3a1> */
	goto x86_l_3a1;
x86_l_342:
	/* 0x342: cmp    r13d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 20ULL);
x86_l_346:
	/* 0x346: je     388 <generic_tracepoint_process_event+0x388> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_388;
	}
x86_l_348:
	/* 0x348: cmp    r13d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 21ULL);
x86_l_34c:
	/* 0x34c: jne    39e <generic_tracepoint_process_event+0x39e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_39e;
	}
x86_l_34e:
	/* 0x34e: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_354:
	/* 0x354: jmp    3a1 <generic_tracepoint_process_event+0x3a1> */
	goto x86_l_3a1;
x86_l_356:
	/* 0x356: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_35a:
	/* 0x35a: je     364 <generic_tracepoint_process_event+0x364> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_364;
	}
x86_l_35c:
	/* 0x35c: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_360:
	/* 0x360: je     378 <generic_tracepoint_process_event+0x378> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_378;
	}
x86_l_362:
	/* 0x362: jmp    39e <generic_tracepoint_process_event+0x39e> */
	goto x86_l_39e;
x86_l_364:
	/* 0x364: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_36a:
	/* 0x36a: jmp    3a1 <generic_tracepoint_process_event+0x3a1> */
	goto x86_l_3a1;
x86_l_36c:
	/* 0x36c: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_370:
	/* 0x370: je     380 <generic_tracepoint_process_event+0x380> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_380;
	}
x86_l_372:
	/* 0x372: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_376:
	/* 0x376: jne    39e <generic_tracepoint_process_event+0x39e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_39e;
	}
x86_l_378:
	/* 0x378: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_37e:
	/* 0x37e: jmp    3a1 <generic_tracepoint_process_event+0x3a1> */
	goto x86_l_3a1;
x86_l_380:
	/* 0x380: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_386:
	/* 0x386: jmp    3a1 <generic_tracepoint_process_event+0x3a1> */
	goto x86_l_3a1;
x86_l_388:
	/* 0x388: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_38e:
	/* 0x38e: jmp    3a1 <generic_tracepoint_process_event+0x3a1> */
	goto x86_l_3a1;
x86_l_390:
	/* 0x390: cmp    r13d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 27ULL);
x86_l_394:
	/* 0x394: jne    39e <generic_tracepoint_process_event+0x39e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_39e;
	}
x86_l_396:
	/* 0x396: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_39c:
	/* 0x39c: jmp    3a1 <generic_tracepoint_process_event+0x3a1> */
	goto x86_l_3a1;
x86_l_39e:
	/* 0x39e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3a1:
	/* 0x3a1: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a6:
	/* 0x3a6: mov    DWORD PTR [rsp+0xf4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_3b1:
	/* 0x3b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3b6:
	/* 0x3b6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_3bd:
	/* 0x3bd: lea    rsi,[rsp+0xf4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 244ULL);
x86_l_3c5:
	/* 0x3c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c7:
	/* 0x3c7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ca:
	/* 0x3ca: je     416 <generic_tracepoint_process_event+0x416> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_416;
	}
x86_l_3cc:
	/* 0x3cc: mov    ecx,0x3ffb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16379ULL);
x86_l_3d1:
	/* 0x3d1: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3d4:
	/* 0x3d4: cmp    rcx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3d7:
	/* 0x3d7: jbe    416 <generic_tracepoint_process_event+0x416> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_416;
	}
x86_l_3d9:
	/* 0x3d9: mov    ecx,DWORD PTR [rax+r12*4+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 24224ULL);
x86_l_3e1:
	/* 0x3e1: mov    DWORD PTR [rax+rbx*1+0x90],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 144ULL);
x86_l_3e8:
	/* 0x3e8: lea    rsi,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3ec:
	/* 0x3ec: mov    QWORD PTR [rax+r12*8+0x5e78],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 24184ULL);
x86_l_3f4:
	/* 0x3f4: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3f9:
	/* 0x3f9: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_3fb:
	/* 0x3fb: je     4ae <generic_tracepoint_process_event+0x4ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ae;
	}
x86_l_401:
	/* 0x401: mov    r12,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_409:
	/* 0x409: mov    r13,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_411:
	/* 0x411: jmp    bc2 <generic_tracepoint_process_event+0xbc2> */
	return 3010ULL;
x86_l_416:
	/* 0x416: mov    r12,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_41e:
	/* 0x41e: mov    r13,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_426:
	/* 0x426: mov    DWORD PTR [r14+0x4],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_42a:
	/* 0x42a: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_42e:
	/* 0x42e: jg     bd4 <generic_tracepoint_process_event+0xbd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3028ULL;
	}
x86_l_434:
	/* 0x434: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_43c:
	/* 0x43c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_441:
	/* 0x441: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_448:
	/* 0x448: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_44d:
	/* 0x44d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44f:
	/* 0x44f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_452:
	/* 0x452: je     bd4 <generic_tracepoint_process_event+0xbd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3028ULL;
	}
x86_l_458:
	/* 0x458: add    rax,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_45e:
	/* 0x45e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_463:
	/* 0x463: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_46a:
	/* 0x46a: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_46d:
	/* 0x46d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_46f:
	/* 0x46f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_472:
	/* 0x472: je     bd4 <generic_tracepoint_process_event+0xbd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3028ULL;
	}
x86_l_478:
	/* 0x478: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_47b:
	/* 0x47b: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_47e:
	/* 0x47e: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_481:
	/* 0x481: cmp    DWORD PTR [rax+rcx*4+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 279172874239ULL);
x86_l_486:
	/* 0x486: je     bd4 <generic_tracepoint_process_event+0xbd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3028ULL;
	}
x86_l_48c:
	/* 0x48c: mov    DWORD PTR [r14+0x5efc],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24316ULL);
x86_l_493:
	/* 0x493: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_498:
	/* 0x498: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_49f:
	/* 0x49f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_4a2:
	/* 0x4a2: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4a7:
	/* 0x4a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a9:
	/* 0x4a9: jmp    bd4 <generic_tracepoint_process_event+0xbd4> */
	return 3028ULL;
x86_l_4ae:
	/* 0x4ae: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_4b1:
	/* 0x4b1: add    r15,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_4b8:
	/* 0x4b8: and    esi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4be:
	/* 0x4be: add    r15,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4c1:
	/* 0x4c1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c6:
	/* 0x4c6: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4cb:
	/* 0x4cb: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_4d7:
	/* 0x4d7: cmp    r13d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 23ULL);
x86_l_4db:
	/* 0x4db: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4e0:
	/* 0x4e0: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e5:
	/* 0x4e5: jle    51f <generic_tracepoint_process_event+0x51f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_51f;
	}
x86_l_4e7:
	/* 0x4e7: cmp    r13d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 42ULL);
x86_l_4eb:
	/* 0x4eb: je     544 <generic_tracepoint_process_event+0x544> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_544;
	}
x86_l_4ed:
	/* 0x4ed: cmp    r13d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 37ULL);
x86_l_4f1:
	/* 0x4f1: je     562 <generic_tracepoint_process_event+0x562> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_562;
	}
x86_l_4f3:
	/* 0x4f3: cmp    r13d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 24ULL);
x86_l_4f7:
	/* 0x4f7: jne    9ec <generic_tracepoint_process_event+0x9ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2540ULL;
	}
x86_l_4fd:
	/* 0x4fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_502:
	/* 0x502: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_507:
	/* 0x507: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_50c:
	/* 0x50c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_511:
	/* 0x511: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_513:
	/* 0x513: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_518:
	/* 0x518: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_51d:
	/* 0x51d: jmp    533 <generic_tracepoint_process_event+0x533> */
	goto x86_l_533;
x86_l_51f:
	/* 0x51f: cmp    r13d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 15ULL);
x86_l_523:
	/* 0x523: je     926 <generic_tracepoint_process_event+0x926> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2342ULL;
	}
x86_l_529:
	/* 0x529: cmp    r13d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 16ULL);
x86_l_52d:
	/* 0x52d: jne    9ec <generic_tracepoint_process_event+0x9ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2540ULL;
	}
x86_l_533:
	/* 0x533: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_538:
	/* 0x538: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_53d:
	/* 0x53d: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_542:
	/* 0x542: jmp    57a <generic_tracepoint_process_event+0x57a> */
	goto x86_l_57a;
x86_l_544:
	/* 0x544: mov    QWORD PTR [rsp+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_550:
	/* 0x550: mov    QWORD PTR [rsp+0x100],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_558:
	/* 0x558: lea    rax,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_560:
	/* 0x560: jmp    58a <generic_tracepoint_process_event+0x58a> */
	goto x86_l_58a;
x86_l_562:
	/* 0x562: add    rdx,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_566:
	/* 0x566: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_56b:
	/* 0x56b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_570:
	/* 0x570: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_575:
	/* 0x575: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_57a:
	/* 0x57a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57f:
	/* 0x57f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_581:
	/* 0x581: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_586:
	/* 0x586: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_58a:
	/* 0x58a: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_58f:
	/* 0x58f: mov    DWORD PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_59a:
	/* 0x59a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_59f:
	/* 0x59f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_5a6:
	/* 0x5a6: lea    rsi,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_5ae:
	/* 0x5ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b0:
	/* 0x5b0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b3:
	/* 0x5b3: je     adc <generic_tracepoint_process_event+0xadc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2780ULL;
	}
x86_l_5b9:
	/* 0x5b9: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_5bc:
	/* 0x5bc: mov    QWORD PTR [rsp],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c0:
	/* 0x5c0: add    rax,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_5c6:
	/* 0x5c6: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cb:
	/* 0x5cb: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_5d0:
	/* 0x5d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d2:
	/* 0x5d2: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_5d9:
	/* 0x5d9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5de:
	/* 0x5de: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_5e6:
	/* 0x5e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5eb:
	/* 0x5eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ed:
	/* 0x5ed: mov    rbp,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_5f5:
	/* 0x5f5: lea    rax,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f9:
	/* 0x5f9: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_601:
	/* 0x601: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_606:
	/* 0x606: lea    rdx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60a:
	/* 0x60a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_60f:
	/* 0x60f: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_617:
	/* 0x617: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_61c:
	/* 0x61c: mov    QWORD PTR [rsp+0x98],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_624:
	/* 0x624: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_626:
	/* 0x626: mov    r15,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_62e:
	/* 0x62e: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_632:
	/* 0x632: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_637:
	/* 0x637: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_63c:
	/* 0x63c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_641:
	/* 0x641: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_643:
	/* 0x643: cmp    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_649:
	/* 0x649: mov    r12d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4096ULL);
x86_l_64f:
	/* 0x64f: je     658 <generic_tracepoint_process_event+0x658> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_658;
	}
x86_l_651:
	/* 0x651: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_656:
	/* 0x656: jmp    6a4 <generic_tracepoint_process_event+0x6a4> */
	goto x86_l_6a4;
x86_l_658:
	/* 0x658: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_65c:
	/* 0x65c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_661:
	/* 0x661: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_666:
	/* 0x666: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_66b:
	/* 0x66b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66d:
	/* 0x66d: cmp    QWORD PTR [rsp+0x40],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_672:
	/* 0x672: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_677:
	/* 0x677: je     6a4 <generic_tracepoint_process_event+0x6a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6a4;
	}
x86_l_679:
	/* 0x679: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_67c:
	/* 0x67c: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_683:
	/* 0x683: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_68d:
	/* 0x68d: mov    QWORD PTR [r13+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_694:
	/* 0x694: mov    WORD PTR [r13+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_69e:
	/* 0x69e: mov    r12d,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4086ULL);
x86_l_6a4:
	/* 0x6a4: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_6ad:
	/* 0x6ad: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_6b6:
	/* 0x6b6: mov    QWORD PTR [rsp+0x50],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6bb:
	/* 0x6bb: lea    r13,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6c0:
	/* 0x6c0: lea    r15,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6c5:
	/* 0x6c5: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_6ce:
	/* 0x6ce: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_6d7:
	/* 0x6d7: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_6e0:
	/* 0x6e0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6e5:
	/* 0x6e5: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6ea:
	/* 0x6ea: mov    DWORD PTR [rsp+0x78],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6ef:
	/* 0x6ef: lea    r12,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6f4:
	/* 0x6f4: mov    BYTE PTR [rsp+0x7c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_6f9:
	/* 0x6f9: add    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_6fd:
	/* 0x6fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_702:
	/* 0x702: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_707:
	/* 0x707: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_70c:
	/* 0x70c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_70f:
	/* 0x70f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_711:
	/* 0x711: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 1814ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_process_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1814ULL: goto x86_l_716;
	case 1817ULL: goto x86_l_719;
	case 1822ULL: goto x86_l_71e;
	case 1830ULL: goto x86_l_726;
	case 1832ULL: goto x86_l_728;
	case 1837ULL: goto x86_l_72d;
	case 1840ULL: goto x86_l_730;
	case 1845ULL: goto x86_l_735;
	case 1853ULL: goto x86_l_73d;
	case 1855ULL: goto x86_l_73f;
	case 1860ULL: goto x86_l_744;
	case 1863ULL: goto x86_l_747;
	case 1868ULL: goto x86_l_74c;
	case 1873ULL: goto x86_l_751;
	case 1875ULL: goto x86_l_753;
	case 1880ULL: goto x86_l_758;
	case 1884ULL: goto x86_l_75c;
	case 1889ULL: goto x86_l_761;
	case 1896ULL: goto x86_l_768;
	case 1899ULL: goto x86_l_76b;
	case 1905ULL: goto x86_l_771;
	case 1911ULL: goto x86_l_777;
	case 1916ULL: goto x86_l_77c;
	case 1921ULL: goto x86_l_781;
	case 1926ULL: goto x86_l_786;
	case 1931ULL: goto x86_l_78b;
	case 1933ULL: goto x86_l_78d;
	case 1938ULL: goto x86_l_792;
	case 1944ULL: goto x86_l_798;
	case 1949ULL: goto x86_l_79d;
	case 1957ULL: goto x86_l_7a5;
	case 1962ULL: goto x86_l_7aa;
	case 1964ULL: goto x86_l_7ac;
	case 1972ULL: goto x86_l_7b4;
	case 1978ULL: goto x86_l_7ba;
	case 1982ULL: goto x86_l_7be;
	case 1987ULL: goto x86_l_7c3;
	case 1992ULL: goto x86_l_7c8;
	case 1997ULL: goto x86_l_7cd;
	case 2000ULL: goto x86_l_7d0;
	case 2002ULL: goto x86_l_7d2;
	case 2007ULL: goto x86_l_7d7;
	case 2013ULL: goto x86_l_7dd;
	case 2018ULL: goto x86_l_7e2;
	case 2023ULL: goto x86_l_7e7;
	case 2028ULL: goto x86_l_7ec;
	case 2031ULL: goto x86_l_7ef;
	case 2033ULL: goto x86_l_7f1;
	case 2037ULL: goto x86_l_7f5;
	case 2042ULL: goto x86_l_7fa;
	case 2050ULL: goto x86_l_802;
	case 2055ULL: goto x86_l_807;
	case 2058ULL: goto x86_l_80a;
	case 2060ULL: goto x86_l_80c;
	case 2065ULL: goto x86_l_811;
	case 2070ULL: goto x86_l_816;
	case 2077ULL: goto x86_l_81d;
	case 2080ULL: goto x86_l_820;
	case 2084ULL: goto x86_l_824;
	case 2086ULL: goto x86_l_826;
	case 2088ULL: goto x86_l_828;
	case 2093ULL: goto x86_l_82d;
	case 2096ULL: goto x86_l_830;
	case 2104ULL: goto x86_l_838;
	case 2107ULL: goto x86_l_83b;
	case 2109ULL: goto x86_l_83d;
	case 2113ULL: goto x86_l_841;
	case 2115ULL: goto x86_l_843;
	case 2118ULL: goto x86_l_846;
	case 2121ULL: goto x86_l_849;
	case 2124ULL: goto x86_l_84c;
	case 2127ULL: goto x86_l_84f;
	case 2132ULL: goto x86_l_854;
	case 2135ULL: goto x86_l_857;
	case 2141ULL: goto x86_l_85d;
	case 2147ULL: goto x86_l_863;
	case 2153ULL: goto x86_l_869;
	case 2155ULL: goto x86_l_86b;
	case 2161ULL: goto x86_l_871;
	case 2165ULL: goto x86_l_875;
	case 2170ULL: goto x86_l_87a;
	case 2174ULL: goto x86_l_87e;
	case 2178ULL: goto x86_l_882;
	case 2181ULL: goto x86_l_885;
	case 2186ULL: goto x86_l_88a;
	case 2188ULL: goto x86_l_88c;
	case 2193ULL: goto x86_l_891;
	case 2198ULL: goto x86_l_896;
	case 2203ULL: goto x86_l_89b;
	case 2206ULL: goto x86_l_89e;
	case 2212ULL: goto x86_l_8a4;
	case 2217ULL: goto x86_l_8a9;
	case 2221ULL: goto x86_l_8ad;
	case 2226ULL: goto x86_l_8b2;
	case 2231ULL: goto x86_l_8b7;
	case 2236ULL: goto x86_l_8bc;
	case 2238ULL: goto x86_l_8be;
	case 2243ULL: goto x86_l_8c3;
	case 2248ULL: goto x86_l_8c8;
	case 2254ULL: goto x86_l_8ce;
	case 2258ULL: goto x86_l_8d2;
	case 2263ULL: goto x86_l_8d7;
	case 2268ULL: goto x86_l_8dc;
	case 2273ULL: goto x86_l_8e1;
	case 2276ULL: goto x86_l_8e4;
	case 2278ULL: goto x86_l_8e6;
	case 2283ULL: goto x86_l_8eb;
	case 2288ULL: goto x86_l_8f0;
	case 2292ULL: goto x86_l_8f4;
	case 2297ULL: goto x86_l_8f9;
	case 2300ULL: goto x86_l_8fc;
	case 2306ULL: goto x86_l_902;
	case 2311ULL: goto x86_l_907;
	case 2316ULL: goto x86_l_90c;
	case 2323ULL: goto x86_l_913;
	case 2328ULL: goto x86_l_918;
	case 2333ULL: goto x86_l_91d;
	case 2335ULL: goto x86_l_91f;
	case 2337ULL: goto x86_l_921;
	case 2342ULL: goto x86_l_926;
	case 2345ULL: goto x86_l_929;
	case 2350ULL: goto x86_l_92e;
	case 2358ULL: goto x86_l_936;
	case 2363ULL: goto x86_l_93b;
	case 2368ULL: goto x86_l_940;
	case 2370ULL: goto x86_l_942;
	case 2378ULL: goto x86_l_94a;
	case 2383ULL: goto x86_l_94f;
	case 2386ULL: goto x86_l_952;
	case 2392ULL: goto x86_l_958;
	case 2403ULL: goto x86_l_963;
	case 2408ULL: goto x86_l_968;
	case 2415ULL: goto x86_l_96f;
	case 2423ULL: goto x86_l_977;
	case 2425ULL: goto x86_l_979;
	case 2428ULL: goto x86_l_97c;
	case 2434ULL: goto x86_l_982;
	case 2438ULL: goto x86_l_986;
	case 2441ULL: goto x86_l_989;
	case 2445ULL: goto x86_l_98d;
	case 2451ULL: goto x86_l_993;
	case 2455ULL: goto x86_l_997;
	case 2461ULL: goto x86_l_99d;
	case 2465ULL: goto x86_l_9a1;
	case 2471ULL: goto x86_l_9a7;
	case 2475ULL: goto x86_l_9ab;
	case 2481ULL: goto x86_l_9b1;
	case 2485ULL: goto x86_l_9b5;
	case 2491ULL: goto x86_l_9bb;
	case 2495ULL: goto x86_l_9bf;
	case 2500ULL: goto x86_l_9c4;
	case 2505ULL: goto x86_l_9c9;
	case 2511ULL: goto x86_l_9cf;
	case 2515ULL: goto x86_l_9d3;
	case 2522ULL: goto x86_l_9da;
	case 2527ULL: goto x86_l_9df;
	case 2529ULL: goto x86_l_9e1;
	case 2535ULL: goto x86_l_9e7;
	case 2540ULL: goto x86_l_9ec;
	case 2543ULL: goto x86_l_9ef;
	case 2547ULL: goto x86_l_9f3;
	case 2553ULL: goto x86_l_9f9;
	case 2556ULL: goto x86_l_9fc;
	case 2566ULL: goto x86_l_a06;
	case 2570ULL: goto x86_l_a0a;
	case 2576ULL: goto x86_l_a10;
	case 2581ULL: goto x86_l_a15;
	case 2592ULL: goto x86_l_a20;
	case 2597ULL: goto x86_l_a25;
	case 2604ULL: goto x86_l_a2c;
	case 2612ULL: goto x86_l_a34;
	case 2614ULL: goto x86_l_a36;
	case 2617ULL: goto x86_l_a39;
	case 2623ULL: goto x86_l_a3f;
	case 2627ULL: goto x86_l_a43;
	case 2630ULL: goto x86_l_a46;
	case 2634ULL: goto x86_l_a4a;
	case 2639ULL: goto x86_l_a4f;
	case 2644ULL: goto x86_l_a54;
	case 2650ULL: goto x86_l_a5a;
	case 2654ULL: goto x86_l_a5e;
	case 2660ULL: goto x86_l_a64;
	case 2664ULL: goto x86_l_a68;
	case 2670ULL: goto x86_l_a6e;
	case 2674ULL: goto x86_l_a72;
	case 2677ULL: goto x86_l_a75;
	case 2683ULL: goto x86_l_a7b;
	case 2689ULL: goto x86_l_a81;
	case 2694ULL: goto x86_l_a86;
	case 2697ULL: goto x86_l_a89;
	case 2702ULL: goto x86_l_a8e;
	case 2706ULL: goto x86_l_a92;
	case 2711ULL: goto x86_l_a97;
	case 2716ULL: goto x86_l_a9c;
	case 2721ULL: goto x86_l_aa1;
	case 2726ULL: goto x86_l_aa6;
	case 2731ULL: goto x86_l_aab;
	case 2733ULL: goto x86_l_aad;
	case 2736ULL: goto x86_l_ab0;
	case 2738ULL: goto x86_l_ab2;
	case 2743ULL: goto x86_l_ab7;
	case 2746ULL: goto x86_l_aba;
	case 2750ULL: goto x86_l_abe;
	case 2756ULL: goto x86_l_ac4;
	case 2759ULL: goto x86_l_ac7;
	case 2761ULL: goto x86_l_ac9;
	case 2765ULL: goto x86_l_acd;
	case 2768ULL: goto x86_l_ad0;
	case 2770ULL: goto x86_l_ad2;
	case 2773ULL: goto x86_l_ad5;
	case 2775ULL: goto x86_l_ad7;
	case 2778ULL: goto x86_l_ada;
	case 2780ULL: goto x86_l_adc;
	case 2783ULL: goto x86_l_adf;
	case 2791ULL: goto x86_l_ae7;
	case 2799ULL: goto x86_l_aef;
	case 2804ULL: goto x86_l_af4;
	case 2807ULL: goto x86_l_af7;
	case 2811ULL: goto x86_l_afb;
	case 2816ULL: goto x86_l_b00;
	case 2823ULL: goto x86_l_b07;
	case 2828ULL: goto x86_l_b0c;
	case 2831ULL: goto x86_l_b0f;
	case 2833ULL: goto x86_l_b11;
	case 2837ULL: goto x86_l_b15;
	case 2842ULL: goto x86_l_b1a;
	case 2847ULL: goto x86_l_b1f;
	case 2852ULL: goto x86_l_b24;
	case 2860ULL: goto x86_l_b2c;
	case 2862ULL: goto x86_l_b2e;
	case 2867ULL: goto x86_l_b33;
	case 2872ULL: goto x86_l_b38;
	case 2876ULL: goto x86_l_b3c;
	case 2884ULL: goto x86_l_b44;
	case 2889ULL: goto x86_l_b49;
	case 2891ULL: goto x86_l_b4b;
	case 2896ULL: goto x86_l_b50;
	case 2904ULL: goto x86_l_b58;
	case 2909ULL: goto x86_l_b5d;
	case 2914ULL: goto x86_l_b62;
	case 2916ULL: goto x86_l_b64;
	case 2921ULL: goto x86_l_b69;
	case 2926ULL: goto x86_l_b6e;
	case 2932ULL: goto x86_l_b74;
	case 2936ULL: goto x86_l_b78;
	case 2941ULL: goto x86_l_b7d;
	case 2946ULL: goto x86_l_b82;
	case 2949ULL: goto x86_l_b85;
	case 2957ULL: goto x86_l_b8d;
	case 2965ULL: goto x86_l_b95;
	case 2967ULL: goto x86_l_b97;
	case 2974ULL: goto x86_l_b9e;
	case 2978ULL: goto x86_l_ba2;
	case 2981ULL: goto x86_l_ba5;
	case 2983ULL: goto x86_l_ba7;
	case 2994ULL: goto x86_l_bb2;
	case 3005ULL: goto x86_l_bbd;
	case 3010ULL: goto x86_l_bc2;
	case 3012ULL: goto x86_l_bc4;
	case 3014ULL: goto x86_l_bc6;
	case 3018ULL: goto x86_l_bca;
	case 3022ULL: goto x86_l_bce;
	case 3028ULL: goto x86_l_bd4;
	case 3039ULL: goto x86_l_bdf;
	case 3044ULL: goto x86_l_be4;
	case 3051ULL: goto x86_l_beb;
	case 3054ULL: goto x86_l_bee;
	case 3059ULL: goto x86_l_bf3;
	case 3061ULL: goto x86_l_bf5;
	case 3063ULL: goto x86_l_bf7;
	case 3070ULL: goto x86_l_bfe;
	case 3072ULL: goto x86_l_c00;
	case 3073ULL: goto x86_l_c01;
	case 3078ULL: goto x86_l_c06;
	case 3082ULL: goto x86_l_c0a;
	case 3088ULL: goto x86_l_c10;
	case 3092ULL: goto x86_l_c14;
	case 3098ULL: goto x86_l_c1a;
	case 3102ULL: goto x86_l_c1e;
	case 3108ULL: goto x86_l_c24;
	case 3112ULL: goto x86_l_c28;
	case 3118ULL: goto x86_l_c2e;
	case 3123ULL: goto x86_l_c33;
	case 3127ULL: goto x86_l_c37;
	case 3132ULL: goto x86_l_c3c;
	case 3137ULL: goto x86_l_c41;
	case 3143ULL: goto x86_l_c47;
	case 3148ULL: goto x86_l_c4c;
	case 3152ULL: goto x86_l_c50;
	case 3156ULL: goto x86_l_c54;
	case 3160ULL: goto x86_l_c58;
	case 3164ULL: goto x86_l_c5c;
	case 3169ULL: goto x86_l_c61;
	case 3174ULL: goto x86_l_c66;
	case 3176ULL: goto x86_l_c68;
	case 3180ULL: goto x86_l_c6c;
	case 3184ULL: goto x86_l_c70;
	case 3189ULL: goto x86_l_c75;
	case 3194ULL: goto x86_l_c7a;
	case 3196ULL: goto x86_l_c7c;
	case 3200ULL: goto x86_l_c80;
	case 3207ULL: goto x86_l_c87;
	case 3212ULL: goto x86_l_c8c;
	case 3217ULL: goto x86_l_c91;
	case 3219ULL: goto x86_l_c93;
	case 3223ULL: goto x86_l_c97;
	case 3230ULL: goto x86_l_c9e;
	case 3235ULL: goto x86_l_ca3;
	case 3240ULL: goto x86_l_ca8;
	case 3242ULL: goto x86_l_caa;
	case 3246ULL: goto x86_l_cae;
	case 3253ULL: goto x86_l_cb5;
	case 3258ULL: goto x86_l_cba;
	case 3263ULL: goto x86_l_cbf;
	case 3265ULL: goto x86_l_cc1;
	case 3269ULL: goto x86_l_cc5;
	case 3276ULL: goto x86_l_ccc;
	case 3281ULL: goto x86_l_cd1;
	case 3286ULL: goto x86_l_cd6;
	case 3288ULL: goto x86_l_cd8;
	case 3292ULL: goto x86_l_cdc;
	case 3300ULL: goto x86_l_ce4;
	case 3308ULL: goto x86_l_cec;
	case 3316ULL: goto x86_l_cf4;
	case 3324ULL: goto x86_l_cfc;
	case 3329ULL: goto x86_l_d01;
	case 3332ULL: goto x86_l_d04;
	case 3338ULL: goto x86_l_d0a;
	case 3341ULL: goto x86_l_d0d;
	case 3347ULL: goto x86_l_d13;
	case 3351ULL: goto x86_l_d17;
	case 3356ULL: goto x86_l_d1c;
	case 3360ULL: goto x86_l_d20;
	case 3365ULL: goto x86_l_d25;
	case 3367ULL: goto x86_l_d27;
	case 3372ULL: goto x86_l_d2c;
	case 3375ULL: goto x86_l_d2f;
	case 3380ULL: goto x86_l_d34;
	case 3383ULL: goto x86_l_d37;
	case 3388ULL: goto x86_l_d3c;
	case 3392ULL: goto x86_l_d40;
	case 3395ULL: goto x86_l_d43;
	case 3400ULL: goto x86_l_d48;
	case 3403ULL: goto x86_l_d4b;
	case 3405ULL: goto x86_l_d4d;
	case 3410ULL: goto x86_l_d52;
	case 3415ULL: goto x86_l_d57;
	case 3419ULL: goto x86_l_d5b;
	case 3425ULL: goto x86_l_d61;
	case 3429ULL: goto x86_l_d65;
	case 3435ULL: goto x86_l_d6b;
	case 3440ULL: goto x86_l_d70;
	case 3444ULL: goto x86_l_d74;
	case 3450ULL: goto x86_l_d7a;
	case 3454ULL: goto x86_l_d7e;
	case 3460ULL: goto x86_l_d84;
	case 3465ULL: goto x86_l_d89;
	case 3469ULL: goto x86_l_d8d;
	case 3472ULL: goto x86_l_d90;
	case 3478ULL: goto x86_l_d96;
	case 3482ULL: goto x86_l_d9a;
	case 3485ULL: goto x86_l_d9d;
	case 3491ULL: goto x86_l_da3;
	case 3495ULL: goto x86_l_da7;
	case 3501ULL: goto x86_l_dad;
	case 3506ULL: goto x86_l_db2;
	case 3511ULL: goto x86_l_db7;
	case 3516ULL: goto x86_l_dbc;
	case 3521ULL: goto x86_l_dc1;
	case 3524ULL: goto x86_l_dc4;
	case 3526ULL: goto x86_l_dc6;
	case 3531ULL: goto x86_l_dcb;
	case 3536ULL: goto x86_l_dd0;
	case 3539ULL: goto x86_l_dd3;
	case 3544ULL: goto x86_l_dd8;
	case 3546ULL: goto x86_l_dda;
	case 3551ULL: goto x86_l_ddf;
	case 3555ULL: goto x86_l_de3;
	case 3560ULL: goto x86_l_de8;
	case 3565ULL: goto x86_l_ded;
	case 3570ULL: goto x86_l_df2;
	case 3572ULL: goto x86_l_df4;
	case 3575ULL: goto x86_l_df7;
	case 3578ULL: goto x86_l_dfa;
	default: return 0xffffffffffffffffULL;
	}
x86_l_716:
	/* 0x716: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_719:
	/* 0x719: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_71e:
	/* 0x71e: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_726:
	/* 0x726: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_728:
	/* 0x728: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_72d:
	/* 0x72d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_730:
	/* 0x730: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_735:
	/* 0x735: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_73d:
	/* 0x73d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_73f:
	/* 0x73f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_744:
	/* 0x744: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_747:
	/* 0x747: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_74c:
	/* 0x74c: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_751:
	/* 0x751: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_753:
	/* 0x753: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_758:
	/* 0x758: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_75c:
	/* 0x75c: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_761:
	/* 0x761: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_768:
	/* 0x768: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_76b:
	/* 0x76b: je     907 <generic_tracepoint_process_event+0x907> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_907;
	}
x86_l_771:
	/* 0x771: mov    r12d,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2048ULL);
x86_l_777:
	/* 0x777: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_77c:
	/* 0x77c: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_781:
	/* 0x781: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_786:
	/* 0x786: cmp    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_78b:
	/* 0x78b: jne    798 <generic_tracepoint_process_event+0x798> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_798;
	}
x86_l_78d:
	/* 0x78d: cmp    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_792:
	/* 0x792: je     a9c <generic_tracepoint_process_event+0xa9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a9c;
	}
x86_l_798:
	/* 0x798: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_79d:
	/* 0x79d: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_7a5:
	/* 0x7a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7aa:
	/* 0x7aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ac:
	/* 0x7ac: cmp    r13,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 200ULL);
x86_l_7b4:
	/* 0x7b4: je     8a9 <generic_tracepoint_process_event+0x8a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8a9;
	}
x86_l_7ba:
	/* 0x7ba: lea    r15,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7be:
	/* 0x7be: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7c3:
	/* 0x7c3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7c8:
	/* 0x7c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7cd:
	/* 0x7cd: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_7d0:
	/* 0x7d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d2:
	/* 0x7d2: cmp    QWORD PTR [rsp+0x30],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7d7:
	/* 0x7d7: je     8a9 <generic_tracepoint_process_event+0x8a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8a9;
	}
x86_l_7dd:
	/* 0x7dd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7e2:
	/* 0x7e2: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7e7:
	/* 0x7e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7ec:
	/* 0x7ec: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_7ef:
	/* 0x7ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f1:
	/* 0x7f1: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_7f5:
	/* 0x7f5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7fa:
	/* 0x7fa: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_802:
	/* 0x802: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_807:
	/* 0x807: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_80a:
	/* 0x80a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80c:
	/* 0x80c: mov    rbp,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_811:
	/* 0x811: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_816:
	/* 0x816: mov    ecx,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_81d:
	/* 0x81d: sub    rax,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_820:
	/* 0x820: mov    esi,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_824:
	/* 0x824: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_826:
	/* 0x826: sub    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_828:
	/* 0x828: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_82d:
	/* 0x82d: cmovb  edx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_830:
	/* 0x830: add    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 144ULL);
x86_l_838:
	/* 0x838: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_83b:
	/* 0x83b: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_83d:
	/* 0x83d: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_841:
	/* 0x841: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_843:
	/* 0x843: cmovb  edi,esi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_32, X86_CC_B);
x86_l_846:
	/* 0x846: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_849:
	/* 0x849: mov    r9d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RSI, X86_WIDTH_32);
x86_l_84c:
	/* 0x84c: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_84f:
	/* 0x84f: mov    DWORD PTR [rsp+0x78],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_854:
	/* 0x854: sub    rax,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_857:
	/* 0x857: jb     aa1 <generic_tracepoint_process_event+0xaa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_aa1;
	}
x86_l_85d:
	/* 0x85d: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_863:
	/* 0x863: ja     aa1 <generic_tracepoint_process_event+0xaa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_aa1;
	}
x86_l_869:
	/* 0x869: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_86b:
	/* 0x86b: jbe    d3c <generic_tracepoint_process_event+0xd3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_d3c;
	}
x86_l_871:
	/* 0x871: lea    r15,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_875:
	/* 0x875: mov    BYTE PTR [rbp+rax*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_87a:
	/* 0x87a: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_87e:
	/* 0x87e: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_882:
	/* 0x882: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_885:
	/* 0x885: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_88a:
	/* 0x88a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_88c:
	/* 0x88c: mov    QWORD PTR [rsp+0x70],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_891:
	/* 0x891: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_896:
	/* 0x896: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_89b:
	/* 0x89b: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_89e:
	/* 0x89e: jne    777 <generic_tracepoint_process_event+0x777> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_777;
	}
x86_l_8a4:
	/* 0x8a4: jmp    aa1 <generic_tracepoint_process_event+0xaa1> */
	goto x86_l_aa1;
x86_l_8a9:
	/* 0x8a9: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8ad:
	/* 0x8ad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8b2:
	/* 0x8b2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8b7:
	/* 0x8b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8bc:
	/* 0x8bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8be:
	/* 0x8be: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_8c3:
	/* 0x8c3: cmp    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_8c8:
	/* 0x8c8: je     a9c <generic_tracepoint_process_event+0xa9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a9c;
	}
x86_l_8ce:
	/* 0x8ce: add    rbp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_8d2:
	/* 0x8d2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8d7:
	/* 0x8d7: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_8dc:
	/* 0x8dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8e1:
	/* 0x8e1: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_8e4:
	/* 0x8e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e6:
	/* 0x8e6: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8eb:
	/* 0x8eb: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_8f0:
	/* 0x8f0: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_8f4:
	/* 0x8f4: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8f9:
	/* 0x8f9: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_8fc:
	/* 0x8fc: jne    777 <generic_tracepoint_process_event+0x777> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_777;
	}
x86_l_902:
	/* 0x902: jmp    aa1 <generic_tracepoint_process_event+0xaa1> */
	goto x86_l_aa1;
x86_l_907:
	/* 0x907: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_90c:
	/* 0x90c: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_913:
	/* 0x913: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_918:
	/* 0x918: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_91d:
	/* 0x91d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_91f:
	/* 0x91f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_921:
	/* 0x921: jmp    aa1 <generic_tracepoint_process_event+0xaa1> */
	goto x86_l_aa1;
x86_l_926:
	/* 0x926: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_929:
	/* 0x929: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_92e:
	/* 0x92e: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_936:
	/* 0x936: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_93b:
	/* 0x93b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_940:
	/* 0x940: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_942:
	/* 0x942: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_94a:
	/* 0x94a: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_94f:
	/* 0x94f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_952:
	/* 0x952: jne    58f <generic_tracepoint_process_event+0x58f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1423ULL;
	}
x86_l_958:
	/* 0x958: mov    DWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_963:
	/* 0x963: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_968:
	/* 0x968: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_96f:
	/* 0x96f: lea    rsi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_977:
	/* 0x977: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_979:
	/* 0x979: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_97c:
	/* 0x97c: je     1b8f <generic_tracepoint_process_event+0x1b8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7055ULL;
	}
x86_l_982:
	/* 0x982: mov    QWORD PTR [rsp],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_986:
	/* 0x986: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_989:
	/* 0x989: cmp    r13d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 25ULL);
x86_l_98d:
	/* 0x98d: jg     e11 <generic_tracepoint_process_event+0xe11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3601ULL;
	}
x86_l_993:
	/* 0x993: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_997:
	/* 0x997: jle    f54 <generic_tracepoint_process_event+0xf54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3924ULL;
	}
x86_l_99d:
	/* 0x99d: cmp    r13d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 20ULL);
x86_l_9a1:
	/* 0x9a1: jle    12a1 <generic_tracepoint_process_event+0x12a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4769ULL;
	}
x86_l_9a7:
	/* 0x9a7: cmp    r13d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 21ULL);
x86_l_9ab:
	/* 0x9ab: je     19cf <generic_tracepoint_process_event+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6607ULL;
	}
x86_l_9b1:
	/* 0x9b1: cmp    r13d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 22ULL);
x86_l_9b5:
	/* 0x9b5: je     1958 <generic_tracepoint_process_event+0x1958> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6488ULL;
	}
x86_l_9bb:
	/* 0x9bb: cmp    r13d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 23ULL);
x86_l_9bf:
	/* 0x9bf: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9c4:
	/* 0x9c4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9c9:
	/* 0x9c9: jne    b82 <generic_tracepoint_process_event+0xb82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b82;
	}
x86_l_9cf:
	/* 0x9cf: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9d3:
	/* 0x9d3: mov    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_9da:
	/* 0x9da: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9df:
	/* 0x9df: mov    DWORD PTR [rax],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9e1:
	/* 0x9e1: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_9e7:
	/* 0x9e7: jmp    b82 <generic_tracepoint_process_event+0xb82> */
	goto x86_l_b82;
x86_l_9ec:
	/* 0x9ec: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_9ef:
	/* 0x9ef: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_9f3:
	/* 0x9f3: ja     958 <generic_tracepoint_process_event+0x958> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_958;
	}
x86_l_9f9:
	/* 0x9f9: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_9fc:
	/* 0x9fc: movabs rcx,0x11c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19524686609650ULL);
x86_l_a06:
	/* 0xa06: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_a0a:
	/* 0xa0a: jae    958 <generic_tracepoint_process_event+0x958> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_958;
	}
x86_l_a10:
	/* 0xa10: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a15:
	/* 0xa15: mov    DWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_a20:
	/* 0xa20: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a25:
	/* 0xa25: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_a2c:
	/* 0xa2c: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_a34:
	/* 0xa34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a36:
	/* 0xa36: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a39:
	/* 0xa39: je     1b8f <generic_tracepoint_process_event+0x1b8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7055ULL;
	}
x86_l_a3f:
	/* 0xa3f: mov    QWORD PTR [rsp],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a43:
	/* 0xa43: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a46:
	/* 0xa46: cmp    r13d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 16ULL);
x86_l_a4a:
	/* 0xa4a: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a4f:
	/* 0xa4f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a54:
	/* 0xa54: jle    c06 <generic_tracepoint_process_event+0xc06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_c06;
	}
x86_l_a5a:
	/* 0xa5a: cmp    r13d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 30ULL);
x86_l_a5e:
	/* 0xa5e: jle    d57 <generic_tracepoint_process_event+0xd57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_d57;
	}
x86_l_a64:
	/* 0xa64: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_a68:
	/* 0xa68: jg     e48 <generic_tracepoint_process_event+0xe48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3656ULL;
	}
x86_l_a6e:
	/* 0xa6e: lea    eax,[r13-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_a72:
	/* 0xa72: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a75:
	/* 0xa75: jae    136c <generic_tracepoint_process_event+0x136c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4972ULL;
	}
x86_l_a7b:
	/* 0xa7b: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_a81:
	/* 0xa81: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a86:
	/* 0xa86: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_a89:
	/* 0xa89: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a8e:
	/* 0xa8e: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a92:
	/* 0xa92: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_a97:
	/* 0xa97: jmp    1039 <generic_tracepoint_process_event+0x1039> */
	return 4153ULL;
x86_l_a9c:
	/* 0xa9c: mov    BYTE PTR [rsp+0x7c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 532575944705ULL);
x86_l_aa1:
	/* 0xaa1: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_aa6:
	/* 0xaa6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aab:
	/* 0xaab: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aad:
	/* 0xaad: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_ab0:
	/* 0xab0: je     af4 <generic_tracepoint_process_event+0xaf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_af4;
	}
x86_l_ab2:
	/* 0xab2: cmp    BYTE PTR [rsp+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_ab7:
	/* 0xab7: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_aba:
	/* 0xaba: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_abe:
	/* 0xabe: mov    r15d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4096ULL);
x86_l_ac4:
	/* 0xac4: sub    r15d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_ac7:
	/* 0xac7: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_ac9:
	/* 0xac9: cmovle r15d,edx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_acd:
	/* 0xacd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ad0:
	/* 0xad0: je     adc <generic_tracepoint_process_event+0xadc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_adc;
	}
x86_l_ad2:
	/* 0xad2: mov    bpl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_8);
x86_l_ad5:
	/* 0xad5: add    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ad7:
	/* 0xad7: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_ada:
	/* 0xada: jmp    af7 <generic_tracepoint_process_event+0xaf7> */
	goto x86_l_af7;
x86_l_adc:
	/* 0xadc: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_adf:
	/* 0xadf: mov    r12,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_ae7:
	/* 0xae7: mov    r13,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_aef:
	/* 0xaef: jmp    b97 <generic_tracepoint_process_event+0xb97> */
	goto x86_l_b97;
x86_l_af4:
	/* 0xaf4: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_af7:
	/* 0xaf7: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_afb:
	/* 0xafb: lea    rdi,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b00:
	/* 0xb00: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b07:
	/* 0xb07: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b0c:
	/* 0xb0c: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_b0f:
	/* 0xb0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b11:
	/* 0xb11: mov    DWORD PTR [r12],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b15:
	/* 0xb15: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b1a:
	/* 0xb1a: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b1f:
	/* 0xb1f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b24:
	/* 0xb24: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_b2c:
	/* 0xb2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b2e:
	/* 0xb2e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b33:
	/* 0xb33: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b38:
	/* 0xb38: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_b3c:
	/* 0xb3c: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b44:
	/* 0xb44: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b49:
	/* 0xb49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b4b:
	/* 0xb4b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b50:
	/* 0xb50: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b58:
	/* 0xb58: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b5d:
	/* 0xb5d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_b62:
	/* 0xb62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b64:
	/* 0xb64: mov    DWORD PTR [r12+r15*1+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 4ULL);
x86_l_b69:
	/* 0xb69: movzx  eax,WORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_b6e:
	/* 0xb6e: mov    WORD PTR [r12+r15*1+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 8ULL);
x86_l_b74:
	/* 0xb74: add    r15d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_b78:
	/* 0xb78: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b7d:
	/* 0xb7d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b82:
	/* 0xb82: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_b85:
	/* 0xb85: mov    r12,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_b8d:
	/* 0xb8d: mov    r13,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_b95:
	/* 0xb95: js     ba7 <generic_tracepoint_process_event+0xba7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_ba7;
	}
x86_l_b97:
	/* 0xb97: and    r15d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_b9e:
	/* 0xb9e: add    r15d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_ba2:
	/* 0xba2: mov    edx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_32);
x86_l_ba5:
	/* 0xba5: jmp    bc2 <generic_tracepoint_process_event+0xbc2> */
	goto x86_l_bc2;
x86_l_ba7:
	/* 0xba7: mov    DWORD PTR [rcx+rdx*4+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104045582745599ULL);
x86_l_bb2:
	/* 0xbb2: mov    DWORD PTR [rcx+rbx*1+0x90],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 622770257919ULL);
x86_l_bbd:
	/* 0xbbd: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_bc2:
	/* 0xbc2: add    edx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bc4:
	/* 0xbc4: mov    ebx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_32);
x86_l_bc6:
	/* 0xbc6: mov    DWORD PTR [r14+0x4],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bca:
	/* 0xbca: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_bce:
	/* 0xbce: jle    434 <generic_tracepoint_process_event+0x434> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 1076ULL;
	}
x86_l_bd4:
	/* 0xbd4: mov    DWORD PTR [r14+0x5efc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104436424769536ULL);
x86_l_bdf:
	/* 0xbdf: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_be4:
	/* 0xbe4: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_beb:
	/* 0xbeb: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_bee:
	/* 0xbee: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_bf3:
	/* 0xbf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf5:
	/* 0xbf5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bf7:
	/* 0xbf7: add    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 264ULL);
x86_l_bfe:
	/* 0xbfe: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_c00:
	/* 0xc00: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_c01:
	/* 0xc01: jmp    2f83 <cwd_read_v61+0x19b> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_c06:
	/* 0xc06: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
x86_l_c0a:
	/* 0xc0a: jg     d89 <generic_tracepoint_process_event+0xd89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d89;
	}
x86_l_c10:
	/* 0xc10: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_c14:
	/* 0xc14: jle    fe1 <generic_tracepoint_process_event+0xfe1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4065ULL;
	}
x86_l_c1a:
	/* 0xc1a: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_c1e:
	/* 0xc1e: je     1533 <generic_tracepoint_process_event+0x1533> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5427ULL;
	}
x86_l_c24:
	/* 0xc24: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_c28:
	/* 0xc28: je     dda <generic_tracepoint_process_event+0xdda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dda;
	}
x86_l_c2e:
	/* 0xc2e: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c33:
	/* 0xc33: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_c37:
	/* 0xc37: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c3c:
	/* 0xc3c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c41:
	/* 0xc41: jne    b82 <generic_tracepoint_process_event+0xb82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b82;
	}
x86_l_c47:
	/* 0xc47: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c4c:
	/* 0xc4c: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c50:
	/* 0xc50: mov    QWORD PTR [r13+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c54:
	/* 0xc54: lea    rdi,[r13+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_c58:
	/* 0xc58: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c5c:
	/* 0xc5c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c61:
	/* 0xc61: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c66:
	/* 0xc66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c68:
	/* 0xc68: lea    rdi,[r13+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_c6c:
	/* 0xc6c: lea    rdx,[r15+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_c70:
	/* 0xc70: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c75:
	/* 0xc75: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_c7a:
	/* 0xc7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c7c:
	/* 0xc7c: lea    rdi,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c80:
	/* 0xc80: lea    rdx,[r15+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_c87:
	/* 0xc87: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c8c:
	/* 0xc8c: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c91:
	/* 0xc91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c93:
	/* 0xc93: lea    rdi,[r13+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_c97:
	/* 0xc97: lea    rdx,[r15+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_c9e:
	/* 0xc9e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ca3:
	/* 0xca3: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_ca8:
	/* 0xca8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_caa:
	/* 0xcaa: lea    rdi,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cae:
	/* 0xcae: lea    rdx,[r15+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_cb5:
	/* 0xcb5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cba:
	/* 0xcba: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cbf:
	/* 0xcbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc1:
	/* 0xcc1: lea    rdi,[r13+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_cc5:
	/* 0xcc5: lea    rdx,[r15+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_ccc:
	/* 0xccc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cd1:
	/* 0xcd1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cd6:
	/* 0xcd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd8:
	/* 0xcd8: lea    r12,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cdc:
	/* 0xcdc: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce4:
	/* 0xce4: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_cec:
	/* 0xcec: mov    QWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_cf4:
	/* 0xcf4: mov    QWORD PTR [r13+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_cfc:
	/* 0xcfc: movzx  eax,WORD PTR [r13+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_d01:
	/* 0xd01: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_d04:
	/* 0xd04: je     1cf3 <generic_tracepoint_process_event+0x1cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7411ULL;
	}
x86_l_d0a:
	/* 0xd0a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d0d:
	/* 0xd0d: jne    1d1a <generic_tracepoint_process_event+0x1d1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7450ULL;
	}
x86_l_d13:
	/* 0xd13: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d17:
	/* 0xd17: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d1c:
	/* 0xd1c: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d20:
	/* 0xd20: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d25:
	/* 0xd25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d27:
	/* 0xd27: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d2c:
	/* 0xd2c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_d2f:
	/* 0xd2f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d34:
	/* 0xd34: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_d37:
	/* 0xd37: jmp    1d18 <generic_tracepoint_process_event+0x1d18> */
	return 7448ULL;
x86_l_d3c:
	/* 0xd3c: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_d40:
	/* 0xd40: add    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d43:
	/* 0xd43: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d48:
	/* 0xd48: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_d4b:
	/* 0xd4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d4d:
	/* 0xd4d: mov    QWORD PTR [rsp+0x70],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d52:
	/* 0xd52: jmp    aa1 <generic_tracepoint_process_event+0xaa1> */
	goto x86_l_aa1;
x86_l_d57:
	/* 0xd57: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_d5b:
	/* 0xd5b: jg     fc3 <generic_tracepoint_process_event+0xfc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4035ULL;
	}
x86_l_d61:
	/* 0xd61: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_d65:
	/* 0xd65: je     13a9 <generic_tracepoint_process_event+0x13a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5033ULL;
	}
x86_l_d6b:
	/* 0xd6b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d70:
	/* 0xd70: cmp    r13d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 25ULL);
x86_l_d74:
	/* 0xd74: je     1467 <generic_tracepoint_process_event+0x1467> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5223ULL;
	}
x86_l_d7a:
	/* 0xd7a: cmp    r13d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 28ULL);
x86_l_d7e:
	/* 0xd7e: je     ff1 <generic_tracepoint_process_event+0xff1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4081ULL;
	}
x86_l_d84:
	/* 0xd84: jmp    b82 <generic_tracepoint_process_event+0xb82> */
	goto x86_l_b82;
x86_l_d89:
	/* 0xd89: lea    eax,[r13-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_d8d:
	/* 0xd8d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d90:
	/* 0xd90: jb     ff1 <generic_tracepoint_process_event+0xff1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4081ULL;
	}
x86_l_d96:
	/* 0xd96: lea    eax,[r13-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_d9a:
	/* 0xd9a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d9d:
	/* 0xd9d: jb     101d <generic_tracepoint_process_event+0x101d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4125ULL;
	}
x86_l_da3:
	/* 0xda3: cmp    r13d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 14ULL);
x86_l_da7:
	/* 0xda7: jne    b82 <generic_tracepoint_process_event+0xb82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b82;
	}
x86_l_dad:
	/* 0xdad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_db2:
	/* 0xdb2: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_db7:
	/* 0xdb7: lea    r15,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_dbc:
	/* 0xdbc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dc1:
	/* 0xdc1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_dc4:
	/* 0xdc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc6:
	/* 0xdc6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_dcb:
	/* 0xdcb: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_dd0:
	/* 0xdd0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_dd3:
	/* 0xdd3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dd8:
	/* 0xdd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dda:
	/* 0xdda: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ddf:
	/* 0xddf: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_de3:
	/* 0xde3: lea    rdi,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_de8:
	/* 0xde8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_ded:
	/* 0xded: mov    esi,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4097ULL);
x86_l_df2:
	/* 0xdf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_df4:
	/* 0xdf4: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_df7:
	/* 0xdf7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dfa:
	/* 0xdfa: js     b78 <generic_tracepoint_process_event+0xb78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b78;
	}
	return 3584ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_process_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3584ULL: goto x86_l_e00;
	case 3588ULL: goto x86_l_e04;
	case 3592ULL: goto x86_l_e08;
	case 3596ULL: goto x86_l_e0c;
	case 3601ULL: goto x86_l_e11;
	case 3605ULL: goto x86_l_e15;
	case 3611ULL: goto x86_l_e1b;
	case 3615ULL: goto x86_l_e1f;
	case 3618ULL: goto x86_l_e22;
	case 3624ULL: goto x86_l_e28;
	case 3629ULL: goto x86_l_e2d;
	case 3633ULL: goto x86_l_e31;
	case 3638ULL: goto x86_l_e36;
	case 3643ULL: goto x86_l_e3b;
	case 3645ULL: goto x86_l_e3d;
	case 3651ULL: goto x86_l_e43;
	case 3656ULL: goto x86_l_e48;
	case 3660ULL: goto x86_l_e4c;
	case 3666ULL: goto x86_l_e52;
	case 3670ULL: goto x86_l_e56;
	case 3676ULL: goto x86_l_e5c;
	case 3680ULL: goto x86_l_e60;
	case 3686ULL: goto x86_l_e66;
	case 3689ULL: goto x86_l_e69;
	case 3694ULL: goto x86_l_e6e;
	case 3699ULL: goto x86_l_e73;
	case 3703ULL: goto x86_l_e77;
	case 3711ULL: goto x86_l_e7f;
	case 3719ULL: goto x86_l_e87;
	case 3727ULL: goto x86_l_e8f;
	case 3735ULL: goto x86_l_e97;
	case 3743ULL: goto x86_l_e9f;
	case 3751ULL: goto x86_l_ea7;
	case 3759ULL: goto x86_l_eaf;
	case 3767ULL: goto x86_l_eb7;
	case 3775ULL: goto x86_l_ebf;
	case 3783ULL: goto x86_l_ec7;
	case 3791ULL: goto x86_l_ecf;
	case 3799ULL: goto x86_l_ed7;
	case 3807ULL: goto x86_l_edf;
	case 3814ULL: goto x86_l_ee6;
	case 3819ULL: goto x86_l_eeb;
	case 3824ULL: goto x86_l_ef0;
	case 3827ULL: goto x86_l_ef3;
	case 3829ULL: goto x86_l_ef5;
	case 3832ULL: goto x86_l_ef8;
	case 3838ULL: goto x86_l_efe;
	case 3842ULL: goto x86_l_f02;
	case 3847ULL: goto x86_l_f07;
	case 3852ULL: goto x86_l_f0c;
	case 3857ULL: goto x86_l_f11;
	case 3860ULL: goto x86_l_f14;
	case 3862ULL: goto x86_l_f16;
	case 3865ULL: goto x86_l_f19;
	case 3871ULL: goto x86_l_f1f;
	case 3875ULL: goto x86_l_f23;
	case 3879ULL: goto x86_l_f27;
	case 3884ULL: goto x86_l_f2c;
	case 3888ULL: goto x86_l_f30;
	case 3894ULL: goto x86_l_f36;
	case 3899ULL: goto x86_l_f3b;
	case 3904ULL: goto x86_l_f40;
	case 3907ULL: goto x86_l_f43;
	case 3909ULL: goto x86_l_f45;
	case 3911ULL: goto x86_l_f47;
	case 3917ULL: goto x86_l_f4d;
	case 3919ULL: goto x86_l_f4f;
	case 3924ULL: goto x86_l_f54;
	case 3926ULL: goto x86_l_f56;
	case 3930ULL: goto x86_l_f5a;
	case 3936ULL: goto x86_l_f60;
	case 3940ULL: goto x86_l_f64;
	case 3946ULL: goto x86_l_f6a;
	case 3950ULL: goto x86_l_f6e;
	case 3955ULL: goto x86_l_f73;
	case 3960ULL: goto x86_l_f78;
	case 3966ULL: goto x86_l_f7e;
	case 3969ULL: goto x86_l_f81;
	case 3975ULL: goto x86_l_f87;
	case 3980ULL: goto x86_l_f8c;
	case 3982ULL: goto x86_l_f8e;
	case 3985ULL: goto x86_l_f91;
	case 3988ULL: goto x86_l_f94;
	case 3994ULL: goto x86_l_f9a;
	case 3997ULL: goto x86_l_f9d;
	case 4003ULL: goto x86_l_fa3;
	case 4006ULL: goto x86_l_fa6;
	case 4012ULL: goto x86_l_fac;
	case 4015ULL: goto x86_l_faf;
	case 4021ULL: goto x86_l_fb5;
	case 4024ULL: goto x86_l_fb8;
	case 4030ULL: goto x86_l_fbe;
	case 4035ULL: goto x86_l_fc3;
	case 4041ULL: goto x86_l_fc9;
	case 4046ULL: goto x86_l_fce;
	case 4049ULL: goto x86_l_fd1;
	case 4054ULL: goto x86_l_fd6;
	case 4058ULL: goto x86_l_fda;
	case 4063ULL: goto x86_l_fdf;
	case 4065ULL: goto x86_l_fe1;
	case 4069ULL: goto x86_l_fe5;
	case 4071ULL: goto x86_l_fe7;
	case 4075ULL: goto x86_l_feb;
	case 4081ULL: goto x86_l_ff1;
	case 4086ULL: goto x86_l_ff6;
	case 4089ULL: goto x86_l_ff9;
	case 4094ULL: goto x86_l_ffe;
	case 4098ULL: goto x86_l_1002;
	case 4103ULL: goto x86_l_1007;
	case 4106ULL: goto x86_l_100a;
	case 4108ULL: goto x86_l_100c;
	case 4111ULL: goto x86_l_100f;
	case 4114ULL: goto x86_l_1012;
	case 4120ULL: goto x86_l_1018;
	case 4125ULL: goto x86_l_101d;
	case 4131ULL: goto x86_l_1023;
	case 4136ULL: goto x86_l_1028;
	case 4139ULL: goto x86_l_102b;
	case 4144ULL: goto x86_l_1030;
	case 4148ULL: goto x86_l_1034;
	case 4153ULL: goto x86_l_1039;
	case 4156ULL: goto x86_l_103c;
	case 4158ULL: goto x86_l_103e;
	case 4161ULL: goto x86_l_1041;
	case 4164ULL: goto x86_l_1044;
	case 4169ULL: goto x86_l_1049;
	case 4173ULL: goto x86_l_104d;
	case 4179ULL: goto x86_l_1053;
	case 4183ULL: goto x86_l_1057;
	case 4188ULL: goto x86_l_105c;
	case 4193ULL: goto x86_l_1061;
	case 4199ULL: goto x86_l_1067;
	case 4202ULL: goto x86_l_106a;
	case 4207ULL: goto x86_l_106f;
	case 4211ULL: goto x86_l_1073;
	case 4216ULL: goto x86_l_1078;
	case 4221ULL: goto x86_l_107d;
	case 4226ULL: goto x86_l_1082;
	case 4228ULL: goto x86_l_1084;
	case 4233ULL: goto x86_l_1089;
	case 4236ULL: goto x86_l_108c;
	case 4242ULL: goto x86_l_1092;
	case 4246ULL: goto x86_l_1096;
	case 4251ULL: goto x86_l_109b;
	case 4256ULL: goto x86_l_10a0;
	case 4260ULL: goto x86_l_10a4;
	case 4265ULL: goto x86_l_10a9;
	case 4270ULL: goto x86_l_10ae;
	case 4272ULL: goto x86_l_10b0;
	case 4277ULL: goto x86_l_10b5;
	case 4281ULL: goto x86_l_10b9;
	case 4286ULL: goto x86_l_10be;
	case 4291ULL: goto x86_l_10c3;
	case 4293ULL: goto x86_l_10c5;
	case 4298ULL: goto x86_l_10ca;
	case 4305ULL: goto x86_l_10d1;
	case 4310ULL: goto x86_l_10d6;
	case 4315ULL: goto x86_l_10db;
	case 4317ULL: goto x86_l_10dd;
	case 4322ULL: goto x86_l_10e2;
	case 4329ULL: goto x86_l_10e9;
	case 4334ULL: goto x86_l_10ee;
	case 4339ULL: goto x86_l_10f3;
	case 4341ULL: goto x86_l_10f5;
	case 4346ULL: goto x86_l_10fa;
	case 4353ULL: goto x86_l_1101;
	case 4358ULL: goto x86_l_1106;
	case 4363ULL: goto x86_l_110b;
	case 4365ULL: goto x86_l_110d;
	case 4370ULL: goto x86_l_1112;
	case 4377ULL: goto x86_l_1119;
	case 4382ULL: goto x86_l_111e;
	case 4387ULL: goto x86_l_1123;
	case 4389ULL: goto x86_l_1125;
	case 4394ULL: goto x86_l_112a;
	case 4402ULL: goto x86_l_1132;
	case 4411ULL: goto x86_l_113b;
	case 4420ULL: goto x86_l_1144;
	case 4429ULL: goto x86_l_114d;
	case 4435ULL: goto x86_l_1153;
	case 4438ULL: goto x86_l_1156;
	case 4444ULL: goto x86_l_115c;
	case 4447ULL: goto x86_l_115f;
	case 4453ULL: goto x86_l_1165;
	case 4457ULL: goto x86_l_1169;
	case 4462ULL: goto x86_l_116e;
	case 4466ULL: goto x86_l_1172;
	case 4471ULL: goto x86_l_1177;
	case 4473ULL: goto x86_l_1179;
	case 4478ULL: goto x86_l_117e;
	case 4481ULL: goto x86_l_1181;
	case 4486ULL: goto x86_l_1186;
	case 4489ULL: goto x86_l_1189;
	case 4494ULL: goto x86_l_118e;
	case 4498ULL: goto x86_l_1192;
	case 4504ULL: goto x86_l_1198;
	case 4508ULL: goto x86_l_119c;
	case 4513ULL: goto x86_l_11a1;
	case 4518ULL: goto x86_l_11a6;
	case 4524ULL: goto x86_l_11ac;
	case 4527ULL: goto x86_l_11af;
	case 4530ULL: goto x86_l_11b2;
	case 4534ULL: goto x86_l_11b6;
	case 4542ULL: goto x86_l_11be;
	case 4550ULL: goto x86_l_11c6;
	case 4558ULL: goto x86_l_11ce;
	case 4566ULL: goto x86_l_11d6;
	case 4574ULL: goto x86_l_11de;
	case 4582ULL: goto x86_l_11e6;
	case 4590ULL: goto x86_l_11ee;
	case 4598ULL: goto x86_l_11f6;
	case 4606ULL: goto x86_l_11fe;
	case 4613ULL: goto x86_l_1205;
	case 4617ULL: goto x86_l_1209;
	case 4622ULL: goto x86_l_120e;
	case 4626ULL: goto x86_l_1212;
	case 4631ULL: goto x86_l_1217;
	case 4636ULL: goto x86_l_121c;
	case 4638ULL: goto x86_l_121e;
	case 4641ULL: goto x86_l_1221;
	case 4647ULL: goto x86_l_1227;
	case 4651ULL: goto x86_l_122b;
	case 4655ULL: goto x86_l_122f;
	case 4660ULL: goto x86_l_1234;
	case 4667ULL: goto x86_l_123b;
	case 4672ULL: goto x86_l_1240;
	case 4677ULL: goto x86_l_1245;
	case 4679ULL: goto x86_l_1247;
	case 4685ULL: goto x86_l_124d;
	case 4690ULL: goto x86_l_1252;
	case 4694ULL: goto x86_l_1256;
	case 4700ULL: goto x86_l_125c;
	case 4704ULL: goto x86_l_1260;
	case 4709ULL: goto x86_l_1265;
	case 4714ULL: goto x86_l_126a;
	case 4720ULL: goto x86_l_1270;
	case 4723ULL: goto x86_l_1273;
	case 4730ULL: goto x86_l_127a;
	case 4735ULL: goto x86_l_127f;
	case 4739ULL: goto x86_l_1283;
	case 4742ULL: goto x86_l_1286;
	case 4745ULL: goto x86_l_1289;
	case 4750ULL: goto x86_l_128e;
	case 4753ULL: goto x86_l_1291;
	case 4755ULL: goto x86_l_1293;
	case 4758ULL: goto x86_l_1296;
	case 4761ULL: goto x86_l_1299;
	case 4764ULL: goto x86_l_129c;
	case 4769ULL: goto x86_l_12a1;
	case 4773ULL: goto x86_l_12a5;
	case 4779ULL: goto x86_l_12ab;
	case 4783ULL: goto x86_l_12af;
	case 4788ULL: goto x86_l_12b4;
	case 4793ULL: goto x86_l_12b9;
	case 4799ULL: goto x86_l_12bf;
	case 4808ULL: goto x86_l_12c8;
	case 4813ULL: goto x86_l_12cd;
	case 4820ULL: goto x86_l_12d4;
	case 4827ULL: goto x86_l_12db;
	case 4832ULL: goto x86_l_12e0;
	case 4837ULL: goto x86_l_12e5;
	case 4842ULL: goto x86_l_12ea;
	case 4845ULL: goto x86_l_12ed;
	case 4847ULL: goto x86_l_12ef;
	case 4852ULL: goto x86_l_12f4;
	case 4857ULL: goto x86_l_12f9;
	case 4861ULL: goto x86_l_12fd;
	case 4864ULL: goto x86_l_1300;
	case 4869ULL: goto x86_l_1305;
	case 4871ULL: goto x86_l_1307;
	case 4879ULL: goto x86_l_130f;
	case 4884ULL: goto x86_l_1314;
	case 4889ULL: goto x86_l_1319;
	case 4892ULL: goto x86_l_131c;
	case 4894ULL: goto x86_l_131e;
	case 4902ULL: goto x86_l_1326;
	case 4909ULL: goto x86_l_132d;
	case 4914ULL: goto x86_l_1332;
	case 4919ULL: goto x86_l_1337;
	case 4921ULL: goto x86_l_1339;
	case 4928ULL: goto x86_l_1340;
	case 4935ULL: goto x86_l_1347;
	case 4940ULL: goto x86_l_134c;
	case 4943ULL: goto x86_l_134f;
	case 4948ULL: goto x86_l_1354;
	case 4951ULL: goto x86_l_1357;
	case 4953ULL: goto x86_l_1359;
	case 4958ULL: goto x86_l_135e;
	case 4961ULL: goto x86_l_1361;
	case 4967ULL: goto x86_l_1367;
	case 4972ULL: goto x86_l_136c;
	case 4976ULL: goto x86_l_1370;
	case 4982ULL: goto x86_l_1376;
	case 4985ULL: goto x86_l_1379;
	case 4988ULL: goto x86_l_137c;
	case 4993ULL: goto x86_l_1381;
	case 4996ULL: goto x86_l_1384;
	case 5004ULL: goto x86_l_138c;
	case 5007ULL: goto x86_l_138f;
	case 5013ULL: goto x86_l_1395;
	case 5017ULL: goto x86_l_1399;
	case 5021ULL: goto x86_l_139d;
	case 5023ULL: goto x86_l_139f;
	case 5028ULL: goto x86_l_13a4;
	case 5033ULL: goto x86_l_13a9;
	case 5036ULL: goto x86_l_13ac;
	case 5045ULL: goto x86_l_13b5;
	case 5050ULL: goto x86_l_13ba;
	case 5052ULL: goto x86_l_13bc;
	case 5056ULL: goto x86_l_13c0;
	case 5061ULL: goto x86_l_13c5;
	case 5066ULL: goto x86_l_13ca;
	case 5074ULL: goto x86_l_13d2;
	case 5079ULL: goto x86_l_13d7;
	case 5084ULL: goto x86_l_13dc;
	case 5086ULL: goto x86_l_13de;
	case 5093ULL: goto x86_l_13e5;
	case 5097ULL: goto x86_l_13e9;
	case 5102ULL: goto x86_l_13ee;
	case 5109ULL: goto x86_l_13f5;
	case 5114ULL: goto x86_l_13fa;
	case 5116ULL: goto x86_l_13fc;
	case 5119ULL: goto x86_l_13ff;
	case 5125ULL: goto x86_l_1405;
	case 5128ULL: goto x86_l_1408;
	case 5133ULL: goto x86_l_140d;
	case 5141ULL: goto x86_l_1415;
	case 5145ULL: goto x86_l_1419;
	case 5148ULL: goto x86_l_141c;
	case 5153ULL: goto x86_l_1421;
	case 5156ULL: goto x86_l_1424;
	case 5158ULL: goto x86_l_1426;
	case 5165ULL: goto x86_l_142d;
	case 5169ULL: goto x86_l_1431;
	case 5173ULL: goto x86_l_1435;
	case 5178ULL: goto x86_l_143a;
	case 5181ULL: goto x86_l_143d;
	case 5183ULL: goto x86_l_143f;
	case 5187ULL: goto x86_l_1443;
	case 5191ULL: goto x86_l_1447;
	case 5195ULL: goto x86_l_144b;
	case 5199ULL: goto x86_l_144f;
	case 5204ULL: goto x86_l_1454;
	case 5209ULL: goto x86_l_1459;
	case 5211ULL: goto x86_l_145b;
	case 5215ULL: goto x86_l_145f;
	case 5218ULL: goto x86_l_1462;
	case 5223ULL: goto x86_l_1467;
	case 5228ULL: goto x86_l_146c;
	case 5233ULL: goto x86_l_1471;
	case 5241ULL: goto x86_l_1479;
	case 5246ULL: goto x86_l_147e;
	case 5249ULL: goto x86_l_1481;
	case 5251ULL: goto x86_l_1483;
	case 5259ULL: goto x86_l_148b;
	case 5261ULL: goto x86_l_148d;
	case 5267ULL: goto x86_l_1493;
	case 5270ULL: goto x86_l_1496;
	case 5276ULL: goto x86_l_149c;
	case 5280ULL: goto x86_l_14a0;
	case 5286ULL: goto x86_l_14a6;
	case 5291ULL: goto x86_l_14ab;
	case 5296ULL: goto x86_l_14b0;
	case 5301ULL: goto x86_l_14b5;
	case 5304ULL: goto x86_l_14b8;
	case 5306ULL: goto x86_l_14ba;
	case 5311ULL: goto x86_l_14bf;
	case 5316ULL: goto x86_l_14c4;
	case 5324ULL: goto x86_l_14cc;
	case 5329ULL: goto x86_l_14d1;
	case 5331ULL: goto x86_l_14d3;
	case 5336ULL: goto x86_l_14d8;
	case 5340ULL: goto x86_l_14dc;
	case 5345ULL: goto x86_l_14e1;
	case 5350ULL: goto x86_l_14e6;
	case 5355ULL: goto x86_l_14eb;
	case 5357ULL: goto x86_l_14ed;
	case 5365ULL: goto x86_l_14f5;
	case 5370ULL: goto x86_l_14fa;
	case 5375ULL: goto x86_l_14ff;
	case 5378ULL: goto x86_l_1502;
	case 5382ULL: goto x86_l_1506;
	case 5389ULL: goto x86_l_150d;
	case 5396ULL: goto x86_l_1514;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e00:
	/* 0xe00: lea    eax,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_e04:
	/* 0xe04: mov    DWORD PTR [r12],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e08:
	/* 0xe08: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_e0c:
	/* 0xe0c: jmp    b78 <generic_tracepoint_process_event+0xb78> */
	return 2936ULL;
x86_l_e11:
	/* 0xe11: cmp    r13d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 32ULL);
x86_l_e15:
	/* 0xe15: jle    118e <generic_tracepoint_process_event+0x118e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_118e;
	}
x86_l_e1b:
	/* 0xe1b: lea    ecx,[r13-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_e1f:
	/* 0xe1f: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e22:
	/* 0xe22: jae    1049 <generic_tracepoint_process_event+0x1049> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1049;
	}
x86_l_e28:
	/* 0xe28: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e2d:
	/* 0xe2d: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e31:
	/* 0xe31: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e36:
	/* 0xe36: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e3b:
	/* 0xe3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e3d:
	/* 0xe3d: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_e43:
	/* 0xe43: jmp    b78 <generic_tracepoint_process_event+0xb78> */
	return 2936ULL;
x86_l_e48:
	/* 0xe48: cmp    r13d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 39ULL);
x86_l_e4c:
	/* 0xe4c: je     16ba <generic_tracepoint_process_event+0x16ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5818ULL;
	}
x86_l_e52:
	/* 0xe52: cmp    r13d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 40ULL);
x86_l_e56:
	/* 0xe56: je     16fa <generic_tracepoint_process_event+0x16fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5882ULL;
	}
x86_l_e5c:
	/* 0xe5c: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_e60:
	/* 0xe60: jne    b82 <generic_tracepoint_process_event+0xb82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2946ULL;
	}
x86_l_e66:
	/* 0xe66: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_e69:
	/* 0xe69: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e6e:
	/* 0xe6e: mov    BYTE PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_e73:
	/* 0xe73: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e77:
	/* 0xe77: mov    QWORD PTR [rdi+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_e7f:
	/* 0xe7f: mov    QWORD PTR [rdi+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_e87:
	/* 0xe87: mov    QWORD PTR [rdi+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_e8f:
	/* 0xe8f: mov    QWORD PTR [rdi+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_e97:
	/* 0xe97: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_e9f:
	/* 0xe9f: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_ea7:
	/* 0xea7: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_eaf:
	/* 0xeaf: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_eb7:
	/* 0xeb7: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_ebf:
	/* 0xebf: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_ec7:
	/* 0xec7: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_ecf:
	/* 0xecf: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_ed7:
	/* 0xed7: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_edf:
	/* 0xedf: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ee6:
	/* 0xee6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_eeb:
	/* 0xeeb: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_ef0:
	/* 0xef0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_ef3:
	/* 0xef3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef5:
	/* 0xef5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ef8:
	/* 0xef8: js     1fa7 <generic_tracepoint_process_event+0x1fa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8103ULL;
	}
x86_l_efe:
	/* 0xefe: lea    r12,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_f02:
	/* 0xf02: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f07:
	/* 0xf07: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f0c:
	/* 0xf0c: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_f11:
	/* 0xf11: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_f14:
	/* 0xf14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f16:
	/* 0xf16: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f19:
	/* 0xf19: js     1fa7 <generic_tracepoint_process_event+0x1fa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8103ULL;
	}
x86_l_f1f:
	/* 0xf1f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f23:
	/* 0xf23: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f27:
	/* 0xf27: cmp    BYTE PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_f2c:
	/* 0xf2c: sete   BYTE PTR [rax+0x2] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RAX, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 2ULL);
x86_l_f30:
	/* 0xf30: je     1f84 <generic_tracepoint_process_event+0x1f84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8068ULL;
	}
x86_l_f36:
	/* 0xf36: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_f3b:
	/* 0xf3b: mov    esi,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 108ULL);
x86_l_f40:
	/* 0xf40: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_f43:
	/* 0xf43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f45:
	/* 0xf45: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f47:
	/* 0xf47: js     1fa7 <generic_tracepoint_process_event+0x1fa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8103ULL;
	}
x86_l_f4d:
	/* 0xf4d: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_f4f:
	/* 0xf4f: jmp    1fa0 <generic_tracepoint_process_event+0x1fa0> */
	return 8096ULL;
x86_l_f54:
	/* 0xf54: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_f56:
	/* 0xf56: cmp    r13d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 7ULL);
x86_l_f5a:
	/* 0xf5a: jg     1252 <generic_tracepoint_process_event+0x1252> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1252;
	}
x86_l_f60:
	/* 0xf60: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_f64:
	/* 0xf64: je     1785 <generic_tracepoint_process_event+0x1785> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6021ULL;
	}
x86_l_f6a:
	/* 0xf6a: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_f6e:
	/* 0xf6e: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f73:
	/* 0xf73: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f78:
	/* 0xf78: jne    b82 <generic_tracepoint_process_event+0xb82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2946ULL;
	}
x86_l_f7e:
	/* 0xf7e: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_f81:
	/* 0xf81: add    rax,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_f87:
	/* 0xf87: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f8c:
	/* 0xf8c: mov    eax,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_f8e:
	/* 0xf8e: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_f91:
	/* 0xf91: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f94:
	/* 0xf94: jle    1e66 <generic_tracepoint_process_event+0x1e66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 7782ULL;
	}
x86_l_f9a:
	/* 0xf9a: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_f9d:
	/* 0xf9d: je     207d <generic_tracepoint_process_event+0x207d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8317ULL;
	}
x86_l_fa3:
	/* 0xfa3: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fa6:
	/* 0xfa6: je     2088 <generic_tracepoint_process_event+0x2088> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8328ULL;
	}
x86_l_fac:
	/* 0xfac: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_faf:
	/* 0xfaf: jne    24b3 <generic_tracepoint_process_event+0x24b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9395ULL;
	}
x86_l_fb5:
	/* 0xfb5: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_fb8:
	/* 0xfb8: add    rax,0x5e70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24176ULL);
x86_l_fbe:
	/* 0xfbe: jmp    209c <generic_tracepoint_process_event+0x209c> */
	return 8348ULL;
x86_l_fc3:
	/* 0xfc3: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_fc9:
	/* 0xfc9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fce:
	/* 0xfce: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_fd1:
	/* 0xfd1: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fd6:
	/* 0xfd6: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fda:
	/* 0xfda: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_fdf:
	/* 0xfdf: jmp    1039 <generic_tracepoint_process_event+0x1039> */
	goto x86_l_1039;
x86_l_fe1:
	/* 0xfe1: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_fe5:
	/* 0xfe5: je     101d <generic_tracepoint_process_event+0x101d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_101d;
	}
x86_l_fe7:
	/* 0xfe7: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_feb:
	/* 0xfeb: jne    b82 <generic_tracepoint_process_event+0xb82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2946ULL;
	}
x86_l_ff1:
	/* 0xff1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ff6:
	/* 0xff6: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_ff9:
	/* 0xff9: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ffe:
	/* 0xffe: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1002:
	/* 0x1002: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1007:
	/* 0x1007: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_100a:
	/* 0x100a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_100c:
	/* 0x100c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_100f:
	/* 0x100f: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_1012:
	/* 0x1012: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_1018:
	/* 0x1018: jmp    b82 <generic_tracepoint_process_event+0xb82> */
	return 2946ULL;
x86_l_101d:
	/* 0x101d: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_1023:
	/* 0x1023: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1028:
	/* 0x1028: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_102b:
	/* 0x102b: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1030:
	/* 0x1030: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1034:
	/* 0x1034: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1039:
	/* 0x1039: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_103c:
	/* 0x103c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_103e:
	/* 0x103e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1041:
	/* 0x1041: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_1044:
	/* 0x1044: jmp    b82 <generic_tracepoint_process_event+0xb82> */
	return 2946ULL;
x86_l_1049:
	/* 0x1049: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_104d:
	/* 0x104d: je     1a99 <generic_tracepoint_process_event+0x1a99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6809ULL;
	}
x86_l_1053:
	/* 0x1053: cmp    r13d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 41ULL);
x86_l_1057:
	/* 0x1057: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_105c:
	/* 0x105c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1061:
	/* 0x1061: jne    b82 <generic_tracepoint_process_event+0xb82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2946ULL;
	}
x86_l_1067:
	/* 0x1067: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_106a:
	/* 0x106a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_106f:
	/* 0x106f: add    rdx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1073:
	/* 0x1073: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1078:
	/* 0x1078: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_107d:
	/* 0x107d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1082:
	/* 0x1082: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1084:
	/* 0x1084: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1089:
	/* 0x1089: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_108c:
	/* 0x108c: je     203c <generic_tracepoint_process_event+0x203c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8252ULL;
	}
x86_l_1092:
	/* 0x1092: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1096:
	/* 0x1096: mov    QWORD PTR [r12+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_109b:
	/* 0x109b: lea    rdi,[r12+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_10a0:
	/* 0x10a0: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10a4:
	/* 0x10a4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10a9:
	/* 0x10a9: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_10ae:
	/* 0x10ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b0:
	/* 0x10b0: lea    rdi,[r12+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_10b5:
	/* 0x10b5: lea    rdx,[r15+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_10b9:
	/* 0x10b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10be:
	/* 0x10be: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_10c3:
	/* 0x10c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10c5:
	/* 0x10c5: lea    rdi,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_10ca:
	/* 0x10ca: lea    rdx,[r15+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_10d1:
	/* 0x10d1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10d6:
	/* 0x10d6: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_10db:
	/* 0x10db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10dd:
	/* 0x10dd: lea    rdi,[r12+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_10e2:
	/* 0x10e2: lea    rdx,[r15+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_10e9:
	/* 0x10e9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10ee:
	/* 0x10ee: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_10f3:
	/* 0x10f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10f5:
	/* 0x10f5: lea    rdi,[r12+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10fa:
	/* 0x10fa: lea    rdx,[r15+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_1101:
	/* 0x1101: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1106:
	/* 0x1106: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_110b:
	/* 0x110b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_110d:
	/* 0x110d: lea    rdi,[r12+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1112:
	/* 0x1112: lea    rdx,[r15+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1119:
	/* 0x1119: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_111e:
	/* 0x111e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1123:
	/* 0x1123: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1125:
	/* 0x1125: lea    r13,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_112a:
	/* 0x112a: mov    QWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1132:
	/* 0x1132: mov    QWORD PTR [r12+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_113b:
	/* 0x113b: mov    QWORD PTR [r12+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1144:
	/* 0x1144: mov    QWORD PTR [r12+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_114d:
	/* 0x114d: movzx  eax,WORD PTR [r12+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1153:
	/* 0x1153: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1156:
	/* 0x1156: je     1fd3 <generic_tracepoint_process_event+0x1fd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8147ULL;
	}
x86_l_115c:
	/* 0x115c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_115f:
	/* 0x115f: jne    1ffa <generic_tracepoint_process_event+0x1ffa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8186ULL;
	}
x86_l_1165:
	/* 0x1165: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1169:
	/* 0x1169: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_116e:
	/* 0x116e: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1172:
	/* 0x1172: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1177:
	/* 0x1177: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1179:
	/* 0x1179: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_117e:
	/* 0x117e: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1181:
	/* 0x1181: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1186:
	/* 0x1186: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1189:
	/* 0x1189: jmp    1ff8 <generic_tracepoint_process_event+0x1ff8> */
	return 8184ULL;
x86_l_118e:
	/* 0x118e: cmp    r13d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 26ULL);
x86_l_1192:
	/* 0x1192: je     1b1d <generic_tracepoint_process_event+0x1b1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6941ULL;
	}
x86_l_1198:
	/* 0x1198: cmp    r13d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 27ULL);
x86_l_119c:
	/* 0x119c: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11a1:
	/* 0x11a1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11a6:
	/* 0x11a6: jne    b82 <generic_tracepoint_process_event+0xb82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2946ULL;
	}
x86_l_11ac:
	/* 0x11ac: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_11af:
	/* 0x11af: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_11b2:
	/* 0x11b2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11b6:
	/* 0x11b6: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_11be:
	/* 0x11be: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_11c6:
	/* 0x11c6: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_11ce:
	/* 0x11ce: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_11d6:
	/* 0x11d6: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_11de:
	/* 0x11de: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_11e6:
	/* 0x11e6: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_11ee:
	/* 0x11ee: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_11f6:
	/* 0x11f6: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_11fe:
	/* 0x11fe: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1205:
	/* 0x1205: lea    rdi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1209:
	/* 0x1209: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_120e:
	/* 0x120e: lea    rdx,[rax+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1212:
	/* 0x1212: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1217:
	/* 0x1217: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_121c:
	/* 0x121c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_121e:
	/* 0x121e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1221:
	/* 0x1221: js     1f76 <generic_tracepoint_process_event+0x1f76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8054ULL;
	}
x86_l_1227:
	/* 0x1227: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_122b:
	/* 0x122b: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_122f:
	/* 0x122f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1234:
	/* 0x1234: add    rdx,0x348 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 840ULL);
x86_l_123b:
	/* 0x123b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1240:
	/* 0x1240: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1245:
	/* 0x1245: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1247:
	/* 0x1247: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_124d:
	/* 0x124d: jmp    1f79 <generic_tracepoint_process_event+0x1f79> */
	return 8057ULL;
x86_l_1252:
	/* 0x1252: cmp    r13d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 8ULL);
x86_l_1256:
	/* 0x1256: je     17dd <generic_tracepoint_process_event+0x17dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6109ULL;
	}
x86_l_125c:
	/* 0x125c: cmp    r13d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 18ULL);
x86_l_1260:
	/* 0x1260: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1265:
	/* 0x1265: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_126a:
	/* 0x126a: jne    b82 <generic_tracepoint_process_event+0xb82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2946ULL;
	}
x86_l_1270:
	/* 0x1270: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_1273:
	/* 0x1273: and    r13d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_127a:
	/* 0x127a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_127f:
	/* 0x127f: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1283:
	/* 0x1283: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_1286:
	/* 0x1286: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_1289:
	/* 0x1289: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_128e:
	/* 0x128e: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_1291:
	/* 0x1291: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1293:
	/* 0x1293: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1296:
	/* 0x1296: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_1299:
	/* 0x1299: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_129c:
	/* 0x129c: jmp    b82 <generic_tracepoint_process_event+0xb82> */
	return 2946ULL;
x86_l_12a1:
	/* 0x12a1: cmp    r13d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 19ULL);
x86_l_12a5:
	/* 0x12a5: je     1a4f <generic_tracepoint_process_event+0x1a4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6735ULL;
	}
x86_l_12ab:
	/* 0x12ab: cmp    r13d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 20ULL);
x86_l_12af:
	/* 0x12af: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12b4:
	/* 0x12b4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12b9:
	/* 0x12b9: jne    b82 <generic_tracepoint_process_event+0xb82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2946ULL;
	}
x86_l_12bf:
	/* 0x12bf: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_12c8:
	/* 0x12c8: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12cd:
	/* 0x12cd: lea    r15,[rbp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_12d4:
	/* 0x12d4: lea    rdx,[rbp+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_12db:
	/* 0x12db: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12e0:
	/* 0x12e0: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12e5:
	/* 0x12e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12ea:
	/* 0x12ea: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_12ed:
	/* 0x12ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12ef:
	/* 0x12ef: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_12f4:
	/* 0x12f4: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12f9:
	/* 0x12f9: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12fd:
	/* 0x12fd: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1300:
	/* 0x1300: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_1305:
	/* 0x1305: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1307:
	/* 0x1307: lea    rdi,[r12+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_130f:
	/* 0x130f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1314:
	/* 0x1314: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1319:
	/* 0x1319: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_131c:
	/* 0x131c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_131e:
	/* 0x131e: lea    rdi,[r12+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1326:
	/* 0x1326: lea    rdx,[rbp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_132d:
	/* 0x132d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1332:
	/* 0x1332: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1337:
	/* 0x1337: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1339:
	/* 0x1339: add    r12,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_1340:
	/* 0x1340: add    rbp,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_1347:
	/* 0x1347: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_134c:
	/* 0x134c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_134f:
	/* 0x134f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1354:
	/* 0x1354: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1357:
	/* 0x1357: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1359:
	/* 0x1359: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_135e:
	/* 0x135e: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1361:
	/* 0x1361: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_1367:
	/* 0x1367: jmp    b82 <generic_tracepoint_process_event+0xb82> */
	return 2946ULL;
x86_l_136c:
	/* 0x136c: cmp    r13d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 38ULL);
x86_l_1370:
	/* 0x1370: jne    b82 <generic_tracepoint_process_event+0xb82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2946ULL;
	}
x86_l_1376:
	/* 0x1376: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_1379:
	/* 0x1379: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_137c:
	/* 0x137c: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1381:
	/* 0x1381: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1384:
	/* 0x1384: add    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 168ULL);
x86_l_138c:
	/* 0x138c: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_138f:
	/* 0x138f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1395:
	/* 0x1395: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1399:
	/* 0x1399: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_139d:
	/* 0x139d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_139f:
	/* 0x139f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_13a4:
	/* 0x13a4: jmp    16dc <generic_tracepoint_process_event+0x16dc> */
	return 5852ULL;
x86_l_13a9:
	/* 0x13a9: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_13ac:
	/* 0x13ac: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_13b5:
	/* 0x13b5: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_13ba:
	/* 0x13ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13bc:
	/* 0x13bc: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_13c0:
	/* 0x13c0: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13c5:
	/* 0x13c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13ca:
	/* 0x13ca: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_13d2:
	/* 0x13d2: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13d7:
	/* 0x13d7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13dc:
	/* 0x13dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13de:
	/* 0x13de: mov    eax,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_13e5:
	/* 0x13e5: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_13e9:
	/* 0x13e9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13ee:
	/* 0x13ee: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_13f5:
	/* 0x13f5: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13fa:
	/* 0x13fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13fc:
	/* 0x13fc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13ff:
	/* 0x13ff: je     1b97 <generic_tracepoint_process_event+0x1b97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7063ULL;
	}
x86_l_1405:
	/* 0x1405: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1408:
	/* 0x1408: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_140d:
	/* 0x140d: lea    rdx,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1415:
	/* 0x1415: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1419:
	/* 0x1419: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_141c:
	/* 0x141c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1421:
	/* 0x1421: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1424:
	/* 0x1424: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1426:
	/* 0x1426: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_142d:
	/* 0x142d: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1431:
	/* 0x1431: lea    esi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1435:
	/* 0x1435: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_143a:
	/* 0x143a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_143d:
	/* 0x143d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_143f:
	/* 0x143f: lea    rdi,[r15+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1443:
	/* 0x1443: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1447:
	/* 0x1447: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_144b:
	/* 0x144b: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_144f:
	/* 0x144f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1454:
	/* 0x1454: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1459:
	/* 0x1459: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_145b:
	/* 0x145b: add    r15,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_145f:
	/* 0x145f: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1462:
	/* 0x1462: jmp    b7d <generic_tracepoint_process_event+0xb7d> */
	return 2941ULL;
x86_l_1467:
	/* 0x1467: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_146c:
	/* 0x146c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1471:
	/* 0x1471: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1479:
	/* 0x1479: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_147e:
	/* 0x147e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1481:
	/* 0x1481: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1483:
	/* 0x1483: movzx  eax,BYTE PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 176ULL);
x86_l_148b:
	/* 0x148b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_148d:
	/* 0x148d: je     1ba6 <generic_tracepoint_process_event+0x1ba6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7078ULL;
	}
x86_l_1493:
	/* 0x1493: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1496:
	/* 0x1496: jne    1da1 <generic_tracepoint_process_event+0x1da1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7585ULL;
	}
x86_l_149c:
	/* 0x149c: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_14a0:
	/* 0x14a0: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_14a6:
	/* 0x14a6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14ab:
	/* 0x14ab: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14b0:
	/* 0x14b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14b5:
	/* 0x14b5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_14b8:
	/* 0x14b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14ba:
	/* 0x14ba: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14bf:
	/* 0x14bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14c4:
	/* 0x14c4: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_14cc:
	/* 0x14cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14d1:
	/* 0x14d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d3:
	/* 0x14d3: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14d8:
	/* 0x14d8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_14dc:
	/* 0x14dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14e1:
	/* 0x14e1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14e6:
	/* 0x14e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14eb:
	/* 0x14eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14ed:
	/* 0x14ed: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_14f5:
	/* 0x14f5: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14fa:
	/* 0x14fa: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14ff:
	/* 0x14ff: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_1502:
	/* 0x1502: lea    rbp,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1506:
	/* 0x1506: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_150d:
	/* 0x150d: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_1514:
	/* 0x1514: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
	return 5402ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_process_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5402ULL: goto x86_l_151a;
	case 5406ULL: goto x86_l_151e;
	case 5410ULL: goto x86_l_1522;
	case 5417ULL: goto x86_l_1529;
	case 5422ULL: goto x86_l_152e;
	case 5427ULL: goto x86_l_1533;
	case 5432ULL: goto x86_l_1538;
	case 5436ULL: goto x86_l_153c;
	case 5440ULL: goto x86_l_1540;
	case 5448ULL: goto x86_l_1548;
	case 5453ULL: goto x86_l_154d;
	case 5458ULL: goto x86_l_1552;
	case 5460ULL: goto x86_l_1554;
	case 5464ULL: goto x86_l_1558;
	case 5469ULL: goto x86_l_155d;
	case 5474ULL: goto x86_l_1562;
	case 5479ULL: goto x86_l_1567;
	case 5481ULL: goto x86_l_1569;
	case 5485ULL: goto x86_l_156d;
	case 5493ULL: goto x86_l_1575;
	case 5498ULL: goto x86_l_157a;
	case 5503ULL: goto x86_l_157f;
	case 5505ULL: goto x86_l_1581;
	case 5509ULL: goto x86_l_1585;
	case 5517ULL: goto x86_l_158d;
	case 5522ULL: goto x86_l_1592;
	case 5527ULL: goto x86_l_1597;
	case 5529ULL: goto x86_l_1599;
	case 5538ULL: goto x86_l_15a2;
	case 5546ULL: goto x86_l_15aa;
	case 5551ULL: goto x86_l_15af;
	case 5556ULL: goto x86_l_15b4;
	case 5561ULL: goto x86_l_15b9;
	case 5563ULL: goto x86_l_15bb;
	case 5571ULL: goto x86_l_15c3;
	case 5576ULL: goto x86_l_15c8;
	case 5584ULL: goto x86_l_15d0;
	case 5589ULL: goto x86_l_15d5;
	case 5591ULL: goto x86_l_15d7;
	case 5600ULL: goto x86_l_15e0;
	case 5605ULL: goto x86_l_15e5;
	case 5610ULL: goto x86_l_15ea;
	case 5618ULL: goto x86_l_15f2;
	case 5623ULL: goto x86_l_15f7;
	case 5626ULL: goto x86_l_15fa;
	case 5628ULL: goto x86_l_15fc;
	case 5636ULL: goto x86_l_1604;
	case 5639ULL: goto x86_l_1607;
	case 5642ULL: goto x86_l_160a;
	case 5648ULL: goto x86_l_1610;
	case 5651ULL: goto x86_l_1613;
	case 5657ULL: goto x86_l_1619;
	case 5661ULL: goto x86_l_161d;
	case 5666ULL: goto x86_l_1622;
	case 5674ULL: goto x86_l_162a;
	case 5679ULL: goto x86_l_162f;
	case 5681ULL: goto x86_l_1631;
	case 5689ULL: goto x86_l_1639;
	case 5693ULL: goto x86_l_163d;
	case 5697ULL: goto x86_l_1641;
	case 5703ULL: goto x86_l_1647;
	case 5707ULL: goto x86_l_164b;
	case 5711ULL: goto x86_l_164f;
	case 5718ULL: goto x86_l_1656;
	case 5726ULL: goto x86_l_165e;
	case 5734ULL: goto x86_l_1666;
	case 5742ULL: goto x86_l_166e;
	case 5747ULL: goto x86_l_1673;
	case 5752ULL: goto x86_l_1678;
	case 5754ULL: goto x86_l_167a;
	case 5758ULL: goto x86_l_167e;
	case 5763ULL: goto x86_l_1683;
	case 5766ULL: goto x86_l_1686;
	case 5771ULL: goto x86_l_168b;
	case 5774ULL: goto x86_l_168e;
	case 5776ULL: goto x86_l_1690;
	case 5784ULL: goto x86_l_1698;
	case 5789ULL: goto x86_l_169d;
	case 5797ULL: goto x86_l_16a5;
	case 5802ULL: goto x86_l_16aa;
	case 5804ULL: goto x86_l_16ac;
	case 5813ULL: goto x86_l_16b5;
	case 5818ULL: goto x86_l_16ba;
	case 5821ULL: goto x86_l_16bd;
	case 5824ULL: goto x86_l_16c0;
	case 5829ULL: goto x86_l_16c5;
	case 5834ULL: goto x86_l_16ca;
	case 5838ULL: goto x86_l_16ce;
	case 5842ULL: goto x86_l_16d2;
	case 5847ULL: goto x86_l_16d7;
	case 5852ULL: goto x86_l_16dc;
	case 5854ULL: goto x86_l_16de;
	case 5857ULL: goto x86_l_16e1;
	case 5860ULL: goto x86_l_16e4;
	case 5866ULL: goto x86_l_16ea;
	case 5870ULL: goto x86_l_16ee;
	case 5873ULL: goto x86_l_16f1;
	case 5877ULL: goto x86_l_16f5;
	case 5882ULL: goto x86_l_16fa;
	case 5885ULL: goto x86_l_16fd;
	case 5888ULL: goto x86_l_1700;
	case 5893ULL: goto x86_l_1705;
	case 5897ULL: goto x86_l_1709;
	case 5905ULL: goto x86_l_1711;
	case 5913ULL: goto x86_l_1719;
	case 5921ULL: goto x86_l_1721;
	case 5926ULL: goto x86_l_1726;
	case 5929ULL: goto x86_l_1729;
	case 5934ULL: goto x86_l_172e;
	case 5937ULL: goto x86_l_1731;
	case 5939ULL: goto x86_l_1733;
	case 5942ULL: goto x86_l_1736;
	case 5948ULL: goto x86_l_173c;
	case 5952ULL: goto x86_l_1740;
	case 5955ULL: goto x86_l_1743;
	case 5961ULL: goto x86_l_1749;
	case 5964ULL: goto x86_l_174c;
	case 5970ULL: goto x86_l_1752;
	case 5974ULL: goto x86_l_1756;
	case 5979ULL: goto x86_l_175b;
	case 5984ULL: goto x86_l_1760;
	case 5989ULL: goto x86_l_1765;
	case 5991ULL: goto x86_l_1767;
	case 5995ULL: goto x86_l_176b;
	case 5999ULL: goto x86_l_176f;
	case 6003ULL: goto x86_l_1773;
	case 6007ULL: goto x86_l_1777;
	case 6011ULL: goto x86_l_177b;
	case 6016ULL: goto x86_l_1780;
	case 6021ULL: goto x86_l_1785;
	case 6024ULL: goto x86_l_1788;
	case 6027ULL: goto x86_l_178b;
	case 6034ULL: goto x86_l_1792;
	case 6046ULL: goto x86_l_179e;
	case 6050ULL: goto x86_l_17a2;
	case 6056ULL: goto x86_l_17a8;
	case 6059ULL: goto x86_l_17ab;
	case 6061ULL: goto x86_l_17ad;
	case 6064ULL: goto x86_l_17b0;
	case 6070ULL: goto x86_l_17b6;
	case 6073ULL: goto x86_l_17b9;
	case 6079ULL: goto x86_l_17bf;
	case 6082ULL: goto x86_l_17c2;
	case 6088ULL: goto x86_l_17c8;
	case 6091ULL: goto x86_l_17cb;
	case 6097ULL: goto x86_l_17d1;
	case 6104ULL: goto x86_l_17d8;
	case 6109ULL: goto x86_l_17dd;
	case 6113ULL: goto x86_l_17e1;
	case 6117ULL: goto x86_l_17e5;
	case 6122ULL: goto x86_l_17ea;
	case 6127ULL: goto x86_l_17ef;
	case 6132ULL: goto x86_l_17f4;
	case 6135ULL: goto x86_l_17f7;
	case 6140ULL: goto x86_l_17fc;
	case 6142ULL: goto x86_l_17fe;
	case 6146ULL: goto x86_l_1802;
	case 6151ULL: goto x86_l_1807;
	case 6156ULL: goto x86_l_180c;
	case 6161ULL: goto x86_l_1811;
	case 6163ULL: goto x86_l_1813;
	case 6167ULL: goto x86_l_1817;
	case 6172ULL: goto x86_l_181c;
	case 6177ULL: goto x86_l_1821;
	case 6182ULL: goto x86_l_1826;
	case 6184ULL: goto x86_l_1828;
	case 6188ULL: goto x86_l_182c;
	case 6193ULL: goto x86_l_1831;
	case 6198ULL: goto x86_l_1836;
	case 6203ULL: goto x86_l_183b;
	case 6205ULL: goto x86_l_183d;
	case 6209ULL: goto x86_l_1841;
	case 6214ULL: goto x86_l_1846;
	case 6219ULL: goto x86_l_184b;
	case 6224ULL: goto x86_l_1850;
	case 6226ULL: goto x86_l_1852;
	case 6230ULL: goto x86_l_1856;
	case 6235ULL: goto x86_l_185b;
	case 6240ULL: goto x86_l_1860;
	case 6245ULL: goto x86_l_1865;
	case 6247ULL: goto x86_l_1867;
	case 6251ULL: goto x86_l_186b;
	case 6256ULL: goto x86_l_1870;
	case 6261ULL: goto x86_l_1875;
	case 6266ULL: goto x86_l_187a;
	case 6268ULL: goto x86_l_187c;
	case 6272ULL: goto x86_l_1880;
	case 6277ULL: goto x86_l_1885;
	case 6282ULL: goto x86_l_188a;
	case 6287ULL: goto x86_l_188f;
	case 6289ULL: goto x86_l_1891;
	case 6297ULL: goto x86_l_1899;
	case 6301ULL: goto x86_l_189d;
	case 6306ULL: goto x86_l_18a2;
	case 6311ULL: goto x86_l_18a7;
	case 6316ULL: goto x86_l_18ac;
	case 6318ULL: goto x86_l_18ae;
	case 6323ULL: goto x86_l_18b3;
	case 6327ULL: goto x86_l_18b7;
	case 6332ULL: goto x86_l_18bc;
	case 6336ULL: goto x86_l_18c0;
	case 6341ULL: goto x86_l_18c5;
	case 6345ULL: goto x86_l_18c9;
	case 6352ULL: goto x86_l_18d0;
	case 6357ULL: goto x86_l_18d5;
	case 6362ULL: goto x86_l_18da;
	case 6367ULL: goto x86_l_18df;
	case 6370ULL: goto x86_l_18e2;
	case 6372ULL: goto x86_l_18e4;
	case 6377ULL: goto x86_l_18e9;
	case 6385ULL: goto x86_l_18f1;
	case 6390ULL: goto x86_l_18f6;
	case 6393ULL: goto x86_l_18f9;
	case 6398ULL: goto x86_l_18fe;
	case 6400ULL: goto x86_l_1900;
	case 6404ULL: goto x86_l_1904;
	case 6412ULL: goto x86_l_190c;
	case 6417ULL: goto x86_l_1911;
	case 6422ULL: goto x86_l_1916;
	case 6424ULL: goto x86_l_1918;
	case 6428ULL: goto x86_l_191c;
	case 6436ULL: goto x86_l_1924;
	case 6441ULL: goto x86_l_1929;
	case 6446ULL: goto x86_l_192e;
	case 6448ULL: goto x86_l_1930;
	case 6452ULL: goto x86_l_1934;
	case 6459ULL: goto x86_l_193b;
	case 6464ULL: goto x86_l_1940;
	case 6467ULL: goto x86_l_1943;
	case 6472ULL: goto x86_l_1948;
	case 6475ULL: goto x86_l_194b;
	case 6477ULL: goto x86_l_194d;
	case 6483ULL: goto x86_l_1953;
	case 6488ULL: goto x86_l_1958;
	case 6493ULL: goto x86_l_195d;
	case 6500ULL: goto x86_l_1964;
	case 6505ULL: goto x86_l_1969;
	case 6509ULL: goto x86_l_196d;
	case 6512ULL: goto x86_l_1970;
	case 6517ULL: goto x86_l_1975;
	case 6519ULL: goto x86_l_1977;
	case 6524ULL: goto x86_l_197c;
	case 6531ULL: goto x86_l_1983;
	case 6536ULL: goto x86_l_1988;
	case 6541ULL: goto x86_l_198d;
	case 6543ULL: goto x86_l_198f;
	case 6548ULL: goto x86_l_1994;
	case 6555ULL: goto x86_l_199b;
	case 6560ULL: goto x86_l_19a0;
	case 6565ULL: goto x86_l_19a5;
	case 6567ULL: goto x86_l_19a7;
	case 6571ULL: goto x86_l_19ab;
	case 6578ULL: goto x86_l_19b2;
	case 6583ULL: goto x86_l_19b7;
	case 6586ULL: goto x86_l_19ba;
	case 6591ULL: goto x86_l_19bf;
	case 6594ULL: goto x86_l_19c2;
	case 6596ULL: goto x86_l_19c4;
	case 6602ULL: goto x86_l_19ca;
	case 6607ULL: goto x86_l_19cf;
	case 6612ULL: goto x86_l_19d4;
	case 6616ULL: goto x86_l_19d8;
	case 6621ULL: goto x86_l_19dd;
	case 6625ULL: goto x86_l_19e1;
	case 6628ULL: goto x86_l_19e4;
	case 6633ULL: goto x86_l_19e9;
	case 6635ULL: goto x86_l_19eb;
	case 6640ULL: goto x86_l_19f0;
	case 6644ULL: goto x86_l_19f4;
	case 6649ULL: goto x86_l_19f9;
	case 6654ULL: goto x86_l_19fe;
	case 6656ULL: goto x86_l_1a00;
	case 6661ULL: goto x86_l_1a05;
	case 6665ULL: goto x86_l_1a09;
	case 6670ULL: goto x86_l_1a0e;
	case 6675ULL: goto x86_l_1a13;
	case 6677ULL: goto x86_l_1a15;
	case 6682ULL: goto x86_l_1a1a;
	case 6686ULL: goto x86_l_1a1e;
	case 6691ULL: goto x86_l_1a23;
	case 6696ULL: goto x86_l_1a28;
	case 6698ULL: goto x86_l_1a2a;
	case 6702ULL: goto x86_l_1a2e;
	case 6706ULL: goto x86_l_1a32;
	case 6711ULL: goto x86_l_1a37;
	case 6714ULL: goto x86_l_1a3a;
	case 6719ULL: goto x86_l_1a3f;
	case 6722ULL: goto x86_l_1a42;
	case 6724ULL: goto x86_l_1a44;
	case 6730ULL: goto x86_l_1a4a;
	case 6735ULL: goto x86_l_1a4f;
	case 6740ULL: goto x86_l_1a54;
	case 6744ULL: goto x86_l_1a58;
	case 6747ULL: goto x86_l_1a5b;
	case 6752ULL: goto x86_l_1a60;
	case 6757ULL: goto x86_l_1a65;
	case 6760ULL: goto x86_l_1a68;
	case 6762ULL: goto x86_l_1a6a;
	case 6767ULL: goto x86_l_1a6f;
	case 6771ULL: goto x86_l_1a73;
	case 6776ULL: goto x86_l_1a78;
	case 6781ULL: goto x86_l_1a7d;
	case 6783ULL: goto x86_l_1a7f;
	case 6787ULL: goto x86_l_1a83;
	case 6791ULL: goto x86_l_1a87;
	case 6796ULL: goto x86_l_1a8c;
	case 6799ULL: goto x86_l_1a8f;
	case 6804ULL: goto x86_l_1a94;
	case 6807ULL: goto x86_l_1a97;
	case 6809ULL: goto x86_l_1a99;
	case 6814ULL: goto x86_l_1a9e;
	case 6818ULL: goto x86_l_1aa2;
	case 6823ULL: goto x86_l_1aa7;
	case 6828ULL: goto x86_l_1aac;
	case 6833ULL: goto x86_l_1ab1;
	case 6835ULL: goto x86_l_1ab3;
	case 6839ULL: goto x86_l_1ab7;
	case 6843ULL: goto x86_l_1abb;
	case 6847ULL: goto x86_l_1abf;
	case 6851ULL: goto x86_l_1ac3;
	case 6856ULL: goto x86_l_1ac8;
	case 6861ULL: goto x86_l_1acd;
	case 6866ULL: goto x86_l_1ad2;
	case 6868ULL: goto x86_l_1ad4;
	case 6872ULL: goto x86_l_1ad8;
	case 6877ULL: goto x86_l_1add;
	case 6881ULL: goto x86_l_1ae1;
	case 6886ULL: goto x86_l_1ae6;
	case 6891ULL: goto x86_l_1aeb;
	case 6896ULL: goto x86_l_1af0;
	case 6899ULL: goto x86_l_1af3;
	case 6901ULL: goto x86_l_1af5;
	case 6905ULL: goto x86_l_1af9;
	case 6910ULL: goto x86_l_1afe;
	case 6915ULL: goto x86_l_1b03;
	case 6920ULL: goto x86_l_1b08;
	case 6923ULL: goto x86_l_1b0b;
	case 6928ULL: goto x86_l_1b10;
	case 6930ULL: goto x86_l_1b12;
	case 6936ULL: goto x86_l_1b18;
	case 6941ULL: goto x86_l_1b1d;
	case 6945ULL: goto x86_l_1b21;
	case 6953ULL: goto x86_l_1b29;
	case 6961ULL: goto x86_l_1b31;
	case 6969ULL: goto x86_l_1b39;
	case 6977ULL: goto x86_l_1b41;
	case 6985ULL: goto x86_l_1b49;
	case 6993ULL: goto x86_l_1b51;
	case 7001ULL: goto x86_l_1b59;
	case 7009ULL: goto x86_l_1b61;
	case 7017ULL: goto x86_l_1b69;
	case 7024ULL: goto x86_l_1b70;
	case 7029ULL: goto x86_l_1b75;
	case 7034ULL: goto x86_l_1b7a;
	case 7039ULL: goto x86_l_1b7f;
	case 7044ULL: goto x86_l_1b84;
	case 7046ULL: goto x86_l_1b86;
	case 7049ULL: goto x86_l_1b89;
	case 7055ULL: goto x86_l_1b8f;
	case 7058ULL: goto x86_l_1b92;
	case 7063ULL: goto x86_l_1b97;
	case 7070ULL: goto x86_l_1b9e;
	case 7073ULL: goto x86_l_1ba1;
	case 7078ULL: goto x86_l_1ba6;
	case 7082ULL: goto x86_l_1baa;
	case 7088ULL: goto x86_l_1bb0;
	case 7093ULL: goto x86_l_1bb5;
	case 7101ULL: goto x86_l_1bbd;
	case 7106ULL: goto x86_l_1bc2;
	case 7108ULL: goto x86_l_1bc4;
	case 7112ULL: goto x86_l_1bc8;
	case 7117ULL: goto x86_l_1bcd;
	case 7122ULL: goto x86_l_1bd2;
	case 7127ULL: goto x86_l_1bd7;
	case 7130ULL: goto x86_l_1bda;
	case 7132ULL: goto x86_l_1bdc;
	case 7140ULL: goto x86_l_1be4;
	case 7145ULL: goto x86_l_1be9;
	case 7150ULL: goto x86_l_1bee;
	case 7153ULL: goto x86_l_1bf1;
	case 7157ULL: goto x86_l_1bf5;
	case 7164ULL: goto x86_l_1bfc;
	case 7171ULL: goto x86_l_1c03;
	case 7177ULL: goto x86_l_1c09;
	default: return 0xffffffffffffffffULL;
	}
x86_l_151a:
	/* 0x151a: cmovb  r12,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_151e:
	/* 0x151e: lea    rdi,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1522:
	/* 0x1522: add    rdi,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_1529:
	/* 0x1529: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_152e:
	/* 0x152e: jmp    1c1d <generic_tracepoint_process_event+0x1c1d> */
	return 7197ULL;
x86_l_1533:
	/* 0x1533: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1538:
	/* 0x1538: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_153c:
	/* 0x153c: lea    rdi,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1540:
	/* 0x1540: lea    rdx,[r12+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1548:
	/* 0x1548: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_154d:
	/* 0x154d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1552:
	/* 0x1552: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1554:
	/* 0x1554: lea    rdi,[r15+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1558:
	/* 0x1558: lea    rdx,[r12+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_155d:
	/* 0x155d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1562:
	/* 0x1562: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1567:
	/* 0x1567: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1569:
	/* 0x1569: lea    rdi,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_156d:
	/* 0x156d: lea    rdx,[r12+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1575:
	/* 0x1575: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_157a:
	/* 0x157a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_157f:
	/* 0x157f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1581:
	/* 0x1581: lea    rdi,[r15+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1585:
	/* 0x1585: lea    rdx,[r12+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_158d:
	/* 0x158d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1592:
	/* 0x1592: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1597:
	/* 0x1597: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1599:
	/* 0x1599: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_15a2:
	/* 0x15a2: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_15aa:
	/* 0x15aa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15af:
	/* 0x15af: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15b4:
	/* 0x15b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15b9:
	/* 0x15b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15bb:
	/* 0x15bb: lea    rdx,[r12+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_15c3:
	/* 0x15c3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15c8:
	/* 0x15c8: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_15d0:
	/* 0x15d0: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_15d5:
	/* 0x15d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d7:
	/* 0x15d7: movzx  r15d,WORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 176ULL);
x86_l_15e0:
	/* 0x15e0: add    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_15e5:
	/* 0x15e5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15ea:
	/* 0x15ea: lea    rdi,[rsp+0x87] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 135ULL);
x86_l_15f2:
	/* 0x15f2: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_15f7:
	/* 0x15f7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_15fa:
	/* 0x15fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15fc:
	/* 0x15fc: movzx  eax,BYTE PTR [rsp+0x87] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 135ULL);
x86_l_1604:
	/* 0x1604: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_1607:
	/* 0x1607: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_160a:
	/* 0x160a: je     1c46 <generic_tracepoint_process_event+0x1c46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7238ULL;
	}
x86_l_1610:
	/* 0x1610: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1613:
	/* 0x1613: jne    2d5d <generic_tracepoint_process_event+0x2d5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11613ULL;
	}
x86_l_1619:
	/* 0x1619: lea    rdx,[r15+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_161d:
	/* 0x161d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1622:
	/* 0x1622: lea    rdi,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_162a:
	/* 0x162a: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_162f:
	/* 0x162f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1631:
	/* 0x1631: movzx  eax,BYTE PTR [rsp+0xa4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 164ULL);
x86_l_1639:
	/* 0x1639: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_163d:
	/* 0x163d: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1641:
	/* 0x1641: mov    WORD PTR [rdi+0x26],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757250ULL);
x86_l_1647:
	/* 0x1647: lea    r13,[rdi+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_164b:
	/* 0x164b: lea    rdx,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_164f:
	/* 0x164f: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1656:
	/* 0x1656: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_165e:
	/* 0x165e: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1666:
	/* 0x1666: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_166e:
	/* 0x166e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1673:
	/* 0x1673: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1678:
	/* 0x1678: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_167a:
	/* 0x167a: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_167e:
	/* 0x167e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1683:
	/* 0x1683: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1686:
	/* 0x1686: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_168b:
	/* 0x168b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_168e:
	/* 0x168e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1690:
	/* 0x1690: lea    rdx,[r12+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_1698:
	/* 0x1698: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_169d:
	/* 0x169d: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_16a5:
	/* 0x16a5: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_16aa:
	/* 0x16aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ac:
	/* 0x16ac: movzx  r15d,BYTE PTR [rsp+0xa4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 164ULL);
x86_l_16b5:
	/* 0x16b5: jmp    2c2c <generic_tracepoint_process_event+0x2c2c> */
	return 11308ULL;
x86_l_16ba:
	/* 0x16ba: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_16bd:
	/* 0x16bd: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_16c0:
	/* 0x16c0: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_16c5:
	/* 0x16c5: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_16ca:
	/* 0x16ca: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16ce:
	/* 0x16ce: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16d2:
	/* 0x16d2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_16d7:
	/* 0x16d7: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_16dc:
	/* 0x16dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16de:
	/* 0x16de: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_16e1:
	/* 0x16e1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16e4:
	/* 0x16e4: js     1ec9 <generic_tracepoint_process_event+0x1ec9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7881ULL;
	}
x86_l_16ea:
	/* 0x16ea: lea    eax,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_16ee:
	/* 0x16ee: mov    DWORD PTR [rbp+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16f1:
	/* 0x16f1: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_16f5:
	/* 0x16f5: jmp    1ec9 <generic_tracepoint_process_event+0x1ec9> */
	return 7881ULL;
x86_l_16fa:
	/* 0x16fa: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_16fd:
	/* 0x16fd: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1700:
	/* 0x1700: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1705:
	/* 0x1705: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1709:
	/* 0x1709: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1711:
	/* 0x1711: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1719:
	/* 0x1719: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1721:
	/* 0x1721: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1726:
	/* 0x1726: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1729:
	/* 0x1729: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_172e:
	/* 0x172e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1731:
	/* 0x1731: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1733:
	/* 0x1733: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1736:
	/* 0x1736: js     1ec3 <generic_tracepoint_process_event+0x1ec3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7875ULL;
	}
x86_l_173c:
	/* 0x173c: movzx  eax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1740:
	/* 0x1740: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1743:
	/* 0x1743: je     1e86 <generic_tracepoint_process_event+0x1e86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7814ULL;
	}
x86_l_1749:
	/* 0x1749: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_174c:
	/* 0x174c: jne    1eb5 <generic_tracepoint_process_event+0x1eb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7861ULL;
	}
x86_l_1752:
	/* 0x1752: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1756:
	/* 0x1756: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_175b:
	/* 0x175b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1760:
	/* 0x1760: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1765:
	/* 0x1765: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1767:
	/* 0x1767: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_176b:
	/* 0x176b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_176f:
	/* 0x176f: mov    QWORD PTR [rcx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1773:
	/* 0x1773: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1777:
	/* 0x1777: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_177b:
	/* 0x177b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1780:
	/* 0x1780: jmp    1eab <generic_tracepoint_process_event+0x1eab> */
	return 7851ULL;
x86_l_1785:
	/* 0x1785: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1788:
	/* 0x1788: add    r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_178b:
	/* 0x178b: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1792:
	/* 0x1792: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_179e:
	/* 0x179e: test   bpl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_8, 16ULL);
x86_l_17a2:
	/* 0x17a2: jne    1db7 <generic_tracepoint_process_event+0x1db7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7607ULL;
	}
x86_l_17a8:
	/* 0x17a8: and    ebp,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_17ab:
	/* 0x17ab: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17ad:
	/* 0x17ad: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_17b0:
	/* 0x17b0: jle    1fb5 <generic_tracepoint_process_event+0x1fb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8117ULL;
	}
x86_l_17b6:
	/* 0x17b6: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_17b9:
	/* 0x17b9: je     2654 <generic_tracepoint_process_event+0x2654> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9812ULL;
	}
x86_l_17bf:
	/* 0x17bf: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_17c2:
	/* 0x17c2: je     265d <generic_tracepoint_process_event+0x265d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9821ULL;
	}
x86_l_17c8:
	/* 0x17c8: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_17cb:
	/* 0x17cb: jne    2670 <generic_tracepoint_process_event+0x2670> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9840ULL;
	}
x86_l_17d1:
	/* 0x17d1: add    r15,0x5e70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24176ULL);
x86_l_17d8:
	/* 0x17d8: jmp    266d <generic_tracepoint_process_event+0x266d> */
	return 9837ULL;
x86_l_17dd:
	/* 0x17dd: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17e1:
	/* 0x17e1: lea    r15,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_17e5:
	/* 0x17e5: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17ea:
	/* 0x17ea: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17ef:
	/* 0x17ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17f4:
	/* 0x17f4: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_17f7:
	/* 0x17f7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17fc:
	/* 0x17fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17fe:
	/* 0x17fe: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1802:
	/* 0x1802: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1807:
	/* 0x1807: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_180c:
	/* 0x180c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1811:
	/* 0x1811: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1813:
	/* 0x1813: lea    rdi,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1817:
	/* 0x1817: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_181c:
	/* 0x181c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1821:
	/* 0x1821: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1826:
	/* 0x1826: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1828:
	/* 0x1828: lea    rdi,[r13+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_182c:
	/* 0x182c: lea    rdx,[r12+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1831:
	/* 0x1831: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1836:
	/* 0x1836: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_183b:
	/* 0x183b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_183d:
	/* 0x183d: lea    rdi,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1841:
	/* 0x1841: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1846:
	/* 0x1846: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_184b:
	/* 0x184b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1850:
	/* 0x1850: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1852:
	/* 0x1852: lea    rdi,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1856:
	/* 0x1856: lea    rdx,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_185b:
	/* 0x185b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1860:
	/* 0x1860: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1865:
	/* 0x1865: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1867:
	/* 0x1867: lea    rdi,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_186b:
	/* 0x186b: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1870:
	/* 0x1870: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1875:
	/* 0x1875: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_187a:
	/* 0x187a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_187c:
	/* 0x187c: lea    rdi,[r13+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1880:
	/* 0x1880: lea    rdx,[r12+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1885:
	/* 0x1885: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_188a:
	/* 0x188a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_188f:
	/* 0x188f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1891:
	/* 0x1891: mov    DWORD PTR [r13+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1899:
	/* 0x1899: lea    rdi,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_189d:
	/* 0x189d: lea    rdx,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18a2:
	/* 0x18a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18a7:
	/* 0x18a7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18ac:
	/* 0x18ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ae:
	/* 0x18ae: mov    rax,QWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18b3:
	/* 0x18b3: mov    QWORD PTR [r13+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18b7:
	/* 0x18b7: mov    rax,QWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18bc:
	/* 0x18bc: mov    QWORD PTR [r13+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18c0:
	/* 0x18c0: mov    rax,QWORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18c5:
	/* 0x18c5: mov    QWORD PTR [r13+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18c9:
	/* 0x18c9: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_18d0:
	/* 0x18d0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18d5:
	/* 0x18d5: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18da:
	/* 0x18da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18df:
	/* 0x18df: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_18e2:
	/* 0x18e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e4:
	/* 0x18e4: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18e9:
	/* 0x18e9: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_18f1:
	/* 0x18f1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18f6:
	/* 0x18f6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_18f9:
	/* 0x18f9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18fe:
	/* 0x18fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1900:
	/* 0x1900: lea    rdi,[r13+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1904:
	/* 0x1904: lea    rdx,[r12+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_190c:
	/* 0x190c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1911:
	/* 0x1911: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1916:
	/* 0x1916: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1918:
	/* 0x1918: lea    rdi,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_191c:
	/* 0x191c: lea    rdx,[r12+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1924:
	/* 0x1924: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1929:
	/* 0x1929: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_192e:
	/* 0x192e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1930:
	/* 0x1930: add    r13,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_1934:
	/* 0x1934: add    r12,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_193b:
	/* 0x193b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1940:
	/* 0x1940: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1943:
	/* 0x1943: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1948:
	/* 0x1948: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_194b:
	/* 0x194b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_194d:
	/* 0x194d: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_1953:
	/* 0x1953: jmp    b78 <generic_tracepoint_process_event+0xb78> */
	return 2936ULL;
x86_l_1958:
	/* 0x1958: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_195d:
	/* 0x195d: lea    rdx,[r15+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1964:
	/* 0x1964: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1969:
	/* 0x1969: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_196d:
	/* 0x196d: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1970:
	/* 0x1970: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1975:
	/* 0x1975: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1977:
	/* 0x1977: lea    rdi,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_197c:
	/* 0x197c: lea    rdx,[r15+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1983:
	/* 0x1983: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1988:
	/* 0x1988: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_198d:
	/* 0x198d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_198f:
	/* 0x198f: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1994:
	/* 0x1994: lea    rdx,[r15+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_199b:
	/* 0x199b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19a0:
	/* 0x19a0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19a5:
	/* 0x19a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19a7:
	/* 0x19a7: add    r12,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_19ab:
	/* 0x19ab: add    r15,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_19b2:
	/* 0x19b2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19b7:
	/* 0x19b7: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_19ba:
	/* 0x19ba: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19bf:
	/* 0x19bf: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_19c2:
	/* 0x19c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19c4:
	/* 0x19c4: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_19ca:
	/* 0x19ca: jmp    b78 <generic_tracepoint_process_event+0xb78> */
	return 2936ULL;
x86_l_19cf:
	/* 0x19cf: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19d4:
	/* 0x19d4: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19d8:
	/* 0x19d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19dd:
	/* 0x19dd: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19e1:
	/* 0x19e1: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_19e4:
	/* 0x19e4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19e9:
	/* 0x19e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19eb:
	/* 0x19eb: lea    rdi,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19f0:
	/* 0x19f0: lea    rdx,[r15+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_19f4:
	/* 0x19f4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19f9:
	/* 0x19f9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19fe:
	/* 0x19fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a00:
	/* 0x1a00: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a05:
	/* 0x1a05: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a09:
	/* 0x1a09: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a0e:
	/* 0x1a0e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a13:
	/* 0x1a13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a15:
	/* 0x1a15: lea    rdi,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1a1a:
	/* 0x1a1a: lea    rdx,[r15+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a1e:
	/* 0x1a1e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a23:
	/* 0x1a23: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a28:
	/* 0x1a28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a2a:
	/* 0x1a2a: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a2e:
	/* 0x1a2e: add    r15,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1a32:
	/* 0x1a32: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a37:
	/* 0x1a37: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1a3a:
	/* 0x1a3a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1a3f:
	/* 0x1a3f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1a42:
	/* 0x1a42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a44:
	/* 0x1a44: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_1a4a:
	/* 0x1a4a: jmp    b78 <generic_tracepoint_process_event+0xb78> */
	return 2936ULL;
x86_l_1a4f:
	/* 0x1a4f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a54:
	/* 0x1a54: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a58:
	/* 0x1a58: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1a5b:
	/* 0x1a5b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a60:
	/* 0x1a60: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a65:
	/* 0x1a65: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1a68:
	/* 0x1a68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a6a:
	/* 0x1a6a: lea    rdi,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a6f:
	/* 0x1a6f: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a73:
	/* 0x1a73: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a78:
	/* 0x1a78: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a7d:
	/* 0x1a7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a7f:
	/* 0x1a7f: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1a83:
	/* 0x1a83: add    r15,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_1a87:
	/* 0x1a87: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a8c:
	/* 0x1a8c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1a8f:
	/* 0x1a8f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1a94:
	/* 0x1a94: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1a97:
	/* 0x1a97: jmp    1b10 <generic_tracepoint_process_event+0x1b10> */
	goto x86_l_1b10;
x86_l_1a99:
	/* 0x1a99: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a9e:
	/* 0x1a9e: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1aa2:
	/* 0x1aa2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1aa7:
	/* 0x1aa7: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1aac:
	/* 0x1aac: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ab1:
	/* 0x1ab1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ab3:
	/* 0x1ab3: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ab7:
	/* 0x1ab7: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1abb:
	/* 0x1abb: mov    DWORD PTR [r12],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1abf:
	/* 0x1abf: lea    rdx,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ac3:
	/* 0x1ac3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ac8:
	/* 0x1ac8: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1acd:
	/* 0x1acd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ad2:
	/* 0x1ad2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad4:
	/* 0x1ad4: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ad8:
	/* 0x1ad8: mov    DWORD PTR [r12+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1add:
	/* 0x1add: add    r15,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1ae1:
	/* 0x1ae1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ae6:
	/* 0x1ae6: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1aeb:
	/* 0x1aeb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1af0:
	/* 0x1af0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1af3:
	/* 0x1af3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af5:
	/* 0x1af5: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1af9:
	/* 0x1af9: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1afe:
	/* 0x1afe: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_1b03:
	/* 0x1b03: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_1b08:
	/* 0x1b08: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1b0b:
	/* 0x1b0b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b10:
	/* 0x1b10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b12:
	/* 0x1b12: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_1b18:
	/* 0x1b18: jmp    b78 <generic_tracepoint_process_event+0xb78> */
	return 2936ULL;
x86_l_1b1d:
	/* 0x1b1d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b21:
	/* 0x1b21: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1b29:
	/* 0x1b29: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1b31:
	/* 0x1b31: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1b39:
	/* 0x1b39: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1b41:
	/* 0x1b41: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1b49:
	/* 0x1b49: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1b51:
	/* 0x1b51: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1b59:
	/* 0x1b59: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1b61:
	/* 0x1b61: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1b69:
	/* 0x1b69: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b70:
	/* 0x1b70: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b75:
	/* 0x1b75: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b7a:
	/* 0x1b7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b7f:
	/* 0x1b7f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b84:
	/* 0x1b84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b86:
	/* 0x1b86: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b89:
	/* 0x1b89: je     1ed4 <generic_tracepoint_process_event+0x1ed4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7892ULL;
	}
x86_l_1b8f:
	/* 0x1b8f: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b92:
	/* 0x1b92: jmp    b78 <generic_tracepoint_process_event+0xb78> */
	return 2936ULL;
x86_l_1b97:
	/* 0x1b97: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1b9e:
	/* 0x1b9e: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1ba1:
	/* 0x1ba1: jmp    b7d <generic_tracepoint_process_event+0xb7d> */
	return 2941ULL;
x86_l_1ba6:
	/* 0x1ba6: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1baa:
	/* 0x1baa: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_1bb0:
	/* 0x1bb0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bb5:
	/* 0x1bb5: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1bbd:
	/* 0x1bbd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bc2:
	/* 0x1bc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bc4:
	/* 0x1bc4: add    r13,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1bc8:
	/* 0x1bc8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bcd:
	/* 0x1bcd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bd2:
	/* 0x1bd2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bd7:
	/* 0x1bd7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1bda:
	/* 0x1bda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bdc:
	/* 0x1bdc: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1be4:
	/* 0x1be4: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1be9:
	/* 0x1be9: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bee:
	/* 0x1bee: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_1bf1:
	/* 0x1bf1: lea    rbp,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1bf5:
	/* 0x1bf5: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1bfc:
	/* 0x1bfc: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_1c03:
	/* 0x1c03: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_1c09:
	/* 0x1c09: cmovb  r12,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B);
	return 7181ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_process_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7181ULL: goto x86_l_1c0d;
	case 7185ULL: goto x86_l_1c11;
	case 7192ULL: goto x86_l_1c18;
	case 7197ULL: goto x86_l_1c1d;
	case 7200ULL: goto x86_l_1c20;
	case 7202ULL: goto x86_l_1c22;
	case 7204ULL: goto x86_l_1c24;
	case 7206ULL: goto x86_l_1c26;
	case 7210ULL: goto x86_l_1c2a;
	case 7214ULL: goto x86_l_1c2e;
	case 7218ULL: goto x86_l_1c32;
	case 7221ULL: goto x86_l_1c35;
	case 7226ULL: goto x86_l_1c3a;
	case 7233ULL: goto x86_l_1c41;
	case 7238ULL: goto x86_l_1c46;
	case 7243ULL: goto x86_l_1c4b;
	case 7252ULL: goto x86_l_1c54;
	case 7257ULL: goto x86_l_1c59;
	case 7261ULL: goto x86_l_1c5d;
	case 7272ULL: goto x86_l_1c68;
	case 7277ULL: goto x86_l_1c6d;
	case 7284ULL: goto x86_l_1c74;
	case 7292ULL: goto x86_l_1c7c;
	case 7294ULL: goto x86_l_1c7e;
	case 7297ULL: goto x86_l_1c81;
	case 7303ULL: goto x86_l_1c87;
	case 7306ULL: goto x86_l_1c8a;
	case 7310ULL: goto x86_l_1c8e;
	case 7314ULL: goto x86_l_1c92;
	case 7318ULL: goto x86_l_1c96;
	case 7321ULL: goto x86_l_1c99;
	case 7325ULL: goto x86_l_1c9d;
	case 7329ULL: goto x86_l_1ca1;
	case 7334ULL: goto x86_l_1ca6;
	case 7339ULL: goto x86_l_1cab;
	case 7344ULL: goto x86_l_1cb0;
	case 7346ULL: goto x86_l_1cb2;
	case 7349ULL: goto x86_l_1cb5;
	case 7355ULL: goto x86_l_1cbb;
	case 7360ULL: goto x86_l_1cc0;
	case 7363ULL: goto x86_l_1cc3;
	case 7369ULL: goto x86_l_1cc9;
	case 7371ULL: goto x86_l_1ccb;
	case 7377ULL: goto x86_l_1cd1;
	case 7380ULL: goto x86_l_1cd4;
	case 7386ULL: goto x86_l_1cda;
	case 7389ULL: goto x86_l_1cdd;
	case 7395ULL: goto x86_l_1ce3;
	case 7402ULL: goto x86_l_1cea;
	case 7406ULL: goto x86_l_1cee;
	case 7411ULL: goto x86_l_1cf3;
	case 7415ULL: goto x86_l_1cf7;
	case 7420ULL: goto x86_l_1cfc;
	case 7424ULL: goto x86_l_1d00;
	case 7429ULL: goto x86_l_1d05;
	case 7431ULL: goto x86_l_1d07;
	case 7435ULL: goto x86_l_1d0b;
	case 7440ULL: goto x86_l_1d10;
	case 7443ULL: goto x86_l_1d13;
	case 7448ULL: goto x86_l_1d18;
	case 7450ULL: goto x86_l_1d1a;
	case 7454ULL: goto x86_l_1d1e;
	case 7458ULL: goto x86_l_1d22;
	case 7462ULL: goto x86_l_1d26;
	case 7466ULL: goto x86_l_1d2a;
	case 7471ULL: goto x86_l_1d2f;
	case 7476ULL: goto x86_l_1d34;
	case 7479ULL: goto x86_l_1d37;
	case 7481ULL: goto x86_l_1d39;
	case 7485ULL: goto x86_l_1d3d;
	case 7490ULL: goto x86_l_1d42;
	case 7495ULL: goto x86_l_1d47;
	case 7498ULL: goto x86_l_1d4a;
	case 7500ULL: goto x86_l_1d4c;
	case 7505ULL: goto x86_l_1d51;
	case 7512ULL: goto x86_l_1d58;
	case 7517ULL: goto x86_l_1d5d;
	case 7522ULL: goto x86_l_1d62;
	case 7527ULL: goto x86_l_1d67;
	case 7534ULL: goto x86_l_1d6e;
	case 7539ULL: goto x86_l_1d73;
	case 7541ULL: goto x86_l_1d75;
	case 7544ULL: goto x86_l_1d78;
	case 7550ULL: goto x86_l_1d7e;
	case 7552ULL: goto x86_l_1d80;
	case 7557ULL: goto x86_l_1d85;
	case 7560ULL: goto x86_l_1d88;
	case 7564ULL: goto x86_l_1d8c;
	case 7568ULL: goto x86_l_1d90;
	case 7571ULL: goto x86_l_1d93;
	case 7574ULL: goto x86_l_1d96;
	case 7580ULL: goto x86_l_1d9c;
	case 7585ULL: goto x86_l_1da1;
	case 7590ULL: goto x86_l_1da6;
	case 7602ULL: goto x86_l_1db2;
	case 7607ULL: goto x86_l_1db7;
	case 7612ULL: goto x86_l_1dbc;
	case 7614ULL: goto x86_l_1dbe;
	case 7618ULL: goto x86_l_1dc2;
	case 7620ULL: goto x86_l_1dc4;
	case 7628ULL: goto x86_l_1dcc;
	case 7632ULL: goto x86_l_1dd0;
	case 7636ULL: goto x86_l_1dd4;
	case 7640ULL: goto x86_l_1dd8;
	case 7645ULL: goto x86_l_1ddd;
	case 7650ULL: goto x86_l_1de2;
	case 7655ULL: goto x86_l_1de7;
	case 7664ULL: goto x86_l_1df0;
	case 7672ULL: goto x86_l_1df8;
	case 7680ULL: goto x86_l_1e00;
	case 7685ULL: goto x86_l_1e05;
	case 7692ULL: goto x86_l_1e0c;
	case 7700ULL: goto x86_l_1e14;
	case 7705ULL: goto x86_l_1e19;
	case 7707ULL: goto x86_l_1e1b;
	case 7709ULL: goto x86_l_1e1d;
	case 7712ULL: goto x86_l_1e20;
	case 7718ULL: goto x86_l_1e26;
	case 7720ULL: goto x86_l_1e28;
	case 7725ULL: goto x86_l_1e2d;
	case 7732ULL: goto x86_l_1e34;
	case 7742ULL: goto x86_l_1e3e;
	case 7747ULL: goto x86_l_1e43;
	case 7752ULL: goto x86_l_1e48;
	case 7759ULL: goto x86_l_1e4f;
	case 7764ULL: goto x86_l_1e54;
	case 7766ULL: goto x86_l_1e56;
	case 7769ULL: goto x86_l_1e59;
	case 7775ULL: goto x86_l_1e5f;
	case 7777ULL: goto x86_l_1e61;
	case 7782ULL: goto x86_l_1e66;
	case 7785ULL: goto x86_l_1e69;
	case 7791ULL: goto x86_l_1e6f;
	case 7794ULL: goto x86_l_1e72;
	case 7800ULL: goto x86_l_1e78;
	case 7803ULL: goto x86_l_1e7b;
	case 7809ULL: goto x86_l_1e81;
	case 7814ULL: goto x86_l_1e86;
	case 7818ULL: goto x86_l_1e8a;
	case 7822ULL: goto x86_l_1e8e;
	case 7826ULL: goto x86_l_1e92;
	case 7831ULL: goto x86_l_1e97;
	case 7836ULL: goto x86_l_1e9c;
	case 7838ULL: goto x86_l_1e9e;
	case 7842ULL: goto x86_l_1ea2;
	case 7846ULL: goto x86_l_1ea6;
	case 7851ULL: goto x86_l_1eab;
	case 7856ULL: goto x86_l_1eb0;
	case 7859ULL: goto x86_l_1eb3;
	case 7861ULL: goto x86_l_1eb5;
	case 7865ULL: goto x86_l_1eb9;
	case 7869ULL: goto x86_l_1ebd;
	case 7875ULL: goto x86_l_1ec3;
	case 7881ULL: goto x86_l_1ec9;
	case 7884ULL: goto x86_l_1ecc;
	case 7887ULL: goto x86_l_1ecf;
	case 7892ULL: goto x86_l_1ed4;
	case 7896ULL: goto x86_l_1ed8;
	case 7900ULL: goto x86_l_1edc;
	case 7905ULL: goto x86_l_1ee1;
	case 7910ULL: goto x86_l_1ee6;
	case 7915ULL: goto x86_l_1eeb;
	case 7917ULL: goto x86_l_1eed;
	case 7920ULL: goto x86_l_1ef0;
	case 7926ULL: goto x86_l_1ef6;
	case 7931ULL: goto x86_l_1efb;
	case 7935ULL: goto x86_l_1eff;
	case 7940ULL: goto x86_l_1f04;
	case 7948ULL: goto x86_l_1f0c;
	case 7953ULL: goto x86_l_1f11;
	case 7955ULL: goto x86_l_1f13;
	case 7959ULL: goto x86_l_1f17;
	case 7963ULL: goto x86_l_1f1b;
	case 7968ULL: goto x86_l_1f20;
	case 7973ULL: goto x86_l_1f25;
	case 7981ULL: goto x86_l_1f2d;
	case 7986ULL: goto x86_l_1f32;
	case 7988ULL: goto x86_l_1f34;
	case 7992ULL: goto x86_l_1f38;
	case 7997ULL: goto x86_l_1f3d;
	case 8005ULL: goto x86_l_1f45;
	case 8010ULL: goto x86_l_1f4a;
	case 8013ULL: goto x86_l_1f4d;
	case 8015ULL: goto x86_l_1f4f;
	case 8021ULL: goto x86_l_1f55;
	case 8024ULL: goto x86_l_1f58;
	case 8030ULL: goto x86_l_1f5e;
	case 8032ULL: goto x86_l_1f60;
	case 8040ULL: goto x86_l_1f68;
	case 8043ULL: goto x86_l_1f6b;
	case 8047ULL: goto x86_l_1f6f;
	case 8049ULL: goto x86_l_1f71;
	case 8054ULL: goto x86_l_1f76;
	case 8057ULL: goto x86_l_1f79;
	case 8060ULL: goto x86_l_1f7c;
	case 8063ULL: goto x86_l_1f7f;
	case 8068ULL: goto x86_l_1f84;
	case 8072ULL: goto x86_l_1f88;
	case 8077ULL: goto x86_l_1f8d;
	case 8082ULL: goto x86_l_1f92;
	case 8085ULL: goto x86_l_1f95;
	case 8087ULL: goto x86_l_1f97;
	case 8090ULL: goto x86_l_1f9a;
	case 8092ULL: goto x86_l_1f9c;
	case 8094ULL: goto x86_l_1f9e;
	case 8096ULL: goto x86_l_1fa0;
	case 8100ULL: goto x86_l_1fa4;
	case 8103ULL: goto x86_l_1fa7;
	case 8109ULL: goto x86_l_1fad;
	case 8112ULL: goto x86_l_1fb0;
	case 8117ULL: goto x86_l_1fb5;
	case 8120ULL: goto x86_l_1fb8;
	case 8126ULL: goto x86_l_1fbe;
	case 8129ULL: goto x86_l_1fc1;
	case 8135ULL: goto x86_l_1fc7;
	case 8142ULL: goto x86_l_1fce;
	case 8147ULL: goto x86_l_1fd3;
	case 8151ULL: goto x86_l_1fd7;
	case 8156ULL: goto x86_l_1fdc;
	case 8160ULL: goto x86_l_1fe0;
	case 8165ULL: goto x86_l_1fe5;
	case 8167ULL: goto x86_l_1fe7;
	case 8171ULL: goto x86_l_1feb;
	case 8176ULL: goto x86_l_1ff0;
	case 8179ULL: goto x86_l_1ff3;
	case 8184ULL: goto x86_l_1ff8;
	case 8186ULL: goto x86_l_1ffa;
	case 8190ULL: goto x86_l_1ffe;
	case 8195ULL: goto x86_l_2003;
	case 8199ULL: goto x86_l_2007;
	case 8203ULL: goto x86_l_200b;
	case 8208ULL: goto x86_l_2010;
	case 8213ULL: goto x86_l_2015;
	case 8216ULL: goto x86_l_2018;
	case 8218ULL: goto x86_l_201a;
	case 8223ULL: goto x86_l_201f;
	case 8228ULL: goto x86_l_2024;
	case 8233ULL: goto x86_l_2029;
	case 8236ULL: goto x86_l_202c;
	case 8238ULL: goto x86_l_202e;
	case 8244ULL: goto x86_l_2034;
	case 8252ULL: goto x86_l_203c;
	case 8256ULL: goto x86_l_2040;
	case 8260ULL: goto x86_l_2044;
	case 8265ULL: goto x86_l_2049;
	case 8270ULL: goto x86_l_204e;
	case 8277ULL: goto x86_l_2055;
	case 8282ULL: goto x86_l_205a;
	case 8284ULL: goto x86_l_205c;
	case 8287ULL: goto x86_l_205f;
	case 8293ULL: goto x86_l_2065;
	case 8295ULL: goto x86_l_2067;
	case 8298ULL: goto x86_l_206a;
	case 8302ULL: goto x86_l_206e;
	case 8306ULL: goto x86_l_2072;
	case 8309ULL: goto x86_l_2075;
	case 8312ULL: goto x86_l_2078;
	case 8317ULL: goto x86_l_207d;
	case 8320ULL: goto x86_l_2080;
	case 8326ULL: goto x86_l_2086;
	case 8328ULL: goto x86_l_2088;
	case 8331ULL: goto x86_l_208b;
	case 8337ULL: goto x86_l_2091;
	case 8339ULL: goto x86_l_2093;
	case 8342ULL: goto x86_l_2096;
	case 8348ULL: goto x86_l_209c;
	case 8351ULL: goto x86_l_209f;
	case 8355ULL: goto x86_l_20a3;
	case 8361ULL: goto x86_l_20a9;
	case 8364ULL: goto x86_l_20ac;
	case 8370ULL: goto x86_l_20b2;
	case 8376ULL: goto x86_l_20b8;
	case 8381ULL: goto x86_l_20bd;
	case 8386ULL: goto x86_l_20c2;
	case 8391ULL: goto x86_l_20c7;
	case 8396ULL: goto x86_l_20cc;
	case 8398ULL: goto x86_l_20ce;
	case 8403ULL: goto x86_l_20d3;
	case 8405ULL: goto x86_l_20d5;
	case 8411ULL: goto x86_l_20db;
	case 8416ULL: goto x86_l_20e0;
	case 8421ULL: goto x86_l_20e5;
	case 8424ULL: goto x86_l_20e8;
	case 8432ULL: goto x86_l_20f0;
	case 8439ULL: goto x86_l_20f7;
	case 8445ULL: goto x86_l_20fd;
	case 8449ULL: goto x86_l_2101;
	case 8452ULL: goto x86_l_2104;
	case 8458ULL: goto x86_l_210a;
	case 8463ULL: goto x86_l_210f;
	case 8468ULL: goto x86_l_2114;
	case 8473ULL: goto x86_l_2119;
	case 8481ULL: goto x86_l_2121;
	case 8483ULL: goto x86_l_2123;
	case 8488ULL: goto x86_l_2128;
	case 8490ULL: goto x86_l_212a;
	case 8496ULL: goto x86_l_2130;
	case 8500ULL: goto x86_l_2134;
	case 8506ULL: goto x86_l_213a;
	case 8511ULL: goto x86_l_213f;
	case 8515ULL: goto x86_l_2143;
	case 8521ULL: goto x86_l_2149;
	case 8526ULL: goto x86_l_214e;
	case 8531ULL: goto x86_l_2153;
	case 8536ULL: goto x86_l_2158;
	case 8538ULL: goto x86_l_215a;
	case 8543ULL: goto x86_l_215f;
	case 8545ULL: goto x86_l_2161;
	case 8551ULL: goto x86_l_2167;
	case 8556ULL: goto x86_l_216c;
	case 8561ULL: goto x86_l_2171;
	case 8565ULL: goto x86_l_2175;
	case 8571ULL: goto x86_l_217b;
	case 8577ULL: goto x86_l_2181;
	case 8585ULL: goto x86_l_2189;
	case 8593ULL: goto x86_l_2191;
	case 8595ULL: goto x86_l_2193;
	case 8601ULL: goto x86_l_2199;
	case 8606ULL: goto x86_l_219e;
	case 8611ULL: goto x86_l_21a3;
	case 8616ULL: goto x86_l_21a8;
	case 8620ULL: goto x86_l_21ac;
	case 8622ULL: goto x86_l_21ae;
	case 8627ULL: goto x86_l_21b3;
	case 8629ULL: goto x86_l_21b5;
	case 8635ULL: goto x86_l_21bb;
	case 8639ULL: goto x86_l_21bf;
	case 8647ULL: goto x86_l_21c7;
	case 8651ULL: goto x86_l_21cb;
	case 8657ULL: goto x86_l_21d1;
	case 8662ULL: goto x86_l_21d6;
	case 8666ULL: goto x86_l_21da;
	case 8672ULL: goto x86_l_21e0;
	case 8677ULL: goto x86_l_21e5;
	case 8682ULL: goto x86_l_21ea;
	case 8687ULL: goto x86_l_21ef;
	case 8689ULL: goto x86_l_21f1;
	case 8694ULL: goto x86_l_21f6;
	case 8696ULL: goto x86_l_21f8;
	case 8702ULL: goto x86_l_21fe;
	case 8707ULL: goto x86_l_2203;
	case 8712ULL: goto x86_l_2208;
	case 8720ULL: goto x86_l_2210;
	case 8726ULL: goto x86_l_2216;
	case 8732ULL: goto x86_l_221c;
	case 8736ULL: goto x86_l_2220;
	case 8744ULL: goto x86_l_2228;
	case 8747ULL: goto x86_l_222b;
	case 8753ULL: goto x86_l_2231;
	case 8758ULL: goto x86_l_2236;
	case 8763ULL: goto x86_l_223b;
	case 8768ULL: goto x86_l_2240;
	case 8776ULL: goto x86_l_2248;
	case 8778ULL: goto x86_l_224a;
	case 8783ULL: goto x86_l_224f;
	case 8785ULL: goto x86_l_2251;
	case 8791ULL: goto x86_l_2257;
	case 8799ULL: goto x86_l_225f;
	case 8807ULL: goto x86_l_2267;
	case 8811ULL: goto x86_l_226b;
	case 8817ULL: goto x86_l_2271;
	case 8822ULL: goto x86_l_2276;
	case 8826ULL: goto x86_l_227a;
	case 8832ULL: goto x86_l_2280;
	case 8837ULL: goto x86_l_2285;
	case 8842ULL: goto x86_l_228a;
	case 8847ULL: goto x86_l_228f;
	case 8849ULL: goto x86_l_2291;
	case 8854ULL: goto x86_l_2296;
	case 8856ULL: goto x86_l_2298;
	case 8862ULL: goto x86_l_229e;
	case 8867ULL: goto x86_l_22a3;
	case 8872ULL: goto x86_l_22a8;
	case 8876ULL: goto x86_l_22ac;
	case 8882ULL: goto x86_l_22b2;
	case 8888ULL: goto x86_l_22b8;
	case 8896ULL: goto x86_l_22c0;
	case 8899ULL: goto x86_l_22c3;
	case 8902ULL: goto x86_l_22c6;
	case 8908ULL: goto x86_l_22cc;
	case 8913ULL: goto x86_l_22d1;
	case 8918ULL: goto x86_l_22d6;
	case 8923ULL: goto x86_l_22db;
	case 8927ULL: goto x86_l_22df;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c0d:
	/* 0x1c0d: lea    rdi,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1c11:
	/* 0x1c11: add    rdi,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_1c18:
	/* 0x1c18: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c1d:
	/* 0x1c1d: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_1c20:
	/* 0x1c20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c22:
	/* 0x1c22: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c24:
	/* 0x1c24: js     1c3a <generic_tracepoint_process_event+0x1c3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1c3a;
	}
x86_l_1c26:
	/* 0x1c26: mov    DWORD PTR [rbp+0x0],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c2a:
	/* 0x1c2a: mov    DWORD PTR [rbp+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c2e:
	/* 0x1c2e: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1c32:
	/* 0x1c32: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_1c35:
	/* 0x1c35: jmp    b78 <generic_tracepoint_process_event+0xb78> */
	return 2936ULL;
x86_l_1c3a:
	/* 0x1c3a: mov    DWORD PTR [rbp+0x0],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_1c41:
	/* 0x1c41: jmp    b78 <generic_tracepoint_process_event+0xb78> */
	return 2936ULL;
x86_l_1c46:
	/* 0x1c46: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c4b:
	/* 0x1c4b: movzx  r15d,WORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 176ULL);
x86_l_1c54:
	/* 0x1c54: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c59:
	/* 0x1c59: lea    rbp,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1c5d:
	/* 0x1c5d: mov    DWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_1c68:
	/* 0x1c68: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c6d:
	/* 0x1c6d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_1c74:
	/* 0x1c74: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1c7c:
	/* 0x1c7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c7e:
	/* 0x1c7e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c81:
	/* 0x1c81: je     2be3 <generic_tracepoint_process_event+0x2be3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11235ULL;
	}
x86_l_1c87:
	/* 0x1c87: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1c8a:
	/* 0x1c8a: mov    WORD PTR [rax],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c8e:
	/* 0x1c8e: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_1c92:
	/* 0x1c92: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_1c96:
	/* 0x1c96: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1c99:
	/* 0x1c99: add    rdi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1c9d:
	/* 0x1c9d: lea    rdx,[rbp+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1ca1:
	/* 0x1ca1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ca6:
	/* 0x1ca6: mov    QWORD PTR [rsp+0x20],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cab:
	/* 0x1cab: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1cb0:
	/* 0x1cb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb2:
	/* 0x1cb2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cb5:
	/* 0x1cb5: js     2be3 <generic_tracepoint_process_event+0x2be3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11235ULL;
	}
x86_l_1cbb:
	/* 0x1cbb: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_1cc0:
	/* 0x1cc0: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_1cc3:
	/* 0x1cc3: jg     25a1 <generic_tracepoint_process_event+0x25a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9633ULL;
	}
x86_l_1cc9:
	/* 0x1cc9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ccb:
	/* 0x1ccb: je     2643 <generic_tracepoint_process_event+0x2643> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9795ULL;
	}
x86_l_1cd1:
	/* 0x1cd1: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1cd4:
	/* 0x1cd4: je     2643 <generic_tracepoint_process_event+0x2643> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9795ULL;
	}
x86_l_1cda:
	/* 0x1cda: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1cdd:
	/* 0x1cdd: jne    27a3 <generic_tracepoint_process_event+0x27a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10147ULL;
	}
x86_l_1ce3:
	/* 0x1ce3: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_1cea:
	/* 0x1cea: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_1cee:
	/* 0x1cee: jmp    26f8 <generic_tracepoint_process_event+0x26f8> */
	return 9976ULL;
x86_l_1cf3:
	/* 0x1cf3: lea    rdx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1cf7:
	/* 0x1cf7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cfc:
	/* 0x1cfc: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d00:
	/* 0x1d00: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d05:
	/* 0x1d05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d07:
	/* 0x1d07: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d0b:
	/* 0x1d0b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d10:
	/* 0x1d10: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1d13:
	/* 0x1d13: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d18:
	/* 0x1d18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d1a:
	/* 0x1d1a: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d1e:
	/* 0x1d1e: lea    rdi,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d22:
	/* 0x1d22: lea    r12,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d26:
	/* 0x1d26: add    r15,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_1d2a:
	/* 0x1d2a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d2f:
	/* 0x1d2f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1d34:
	/* 0x1d34: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1d37:
	/* 0x1d37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d39:
	/* 0x1d39: lea    rdi,[r13+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_1d3d:
	/* 0x1d3d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d42:
	/* 0x1d42: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1d47:
	/* 0x1d47: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d4a:
	/* 0x1d4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d4c:
	/* 0x1d4c: movzx  eax,WORD PTR [r13+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_1d51:
	/* 0x1d51: movbe  WORD PTR [r13+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_1d58:
	/* 0x1d58: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d5d:
	/* 0x1d5d: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d62:
	/* 0x1d62: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d67:
	/* 0x1d67: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_1d6e:
	/* 0x1d6e: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d73:
	/* 0x1d73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d75:
	/* 0x1d75: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d78:
	/* 0x1d78: je     2d5d <generic_tracepoint_process_event+0x2d5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11613ULL;
	}
x86_l_1d7e:
	/* 0x1d7e: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d80:
	/* 0x1d80: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d85:
	/* 0x1d85: mov    DWORD PTR [rdx+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d88:
	/* 0x1d88: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d8c:
	/* 0x1d8c: mov    QWORD PTR [rdx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d90:
	/* 0x1d90: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d93:
	/* 0x1d93: mov    DWORD PTR [rdx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1d96:
	/* 0x1d96: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_1d9c:
	/* 0x1d9c: jmp    b78 <generic_tracepoint_process_event+0xb78> */
	return 2936ULL;
x86_l_1da1:
	/* 0x1da1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1da6:
	/* 0x1da6: mov    QWORD PTR [rax+r12*1+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 618475290624ULL);
x86_l_1db2:
	/* 0x1db2: jmp    e3d <generic_tracepoint_process_event+0xe3d> */
	return 3645ULL;
x86_l_1db7:
	/* 0x1db7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1dbc:
	/* 0x1dbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dbe:
	/* 0x1dbe: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_1dc2:
	/* 0x1dc2: jne    1dd0 <generic_tracepoint_process_event+0x1dd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1dd0;
	}
x86_l_1dc4:
	/* 0x1dc4: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1dcc:
	/* 0x1dcc: mov    rax,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dd0:
	/* 0x1dd0: mov    rcx,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dd4:
	/* 0x1dd4: mov    rdx,QWORD PTR [r15+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1dd8:
	/* 0x1dd8: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ddd:
	/* 0x1ddd: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1de2:
	/* 0x1de2: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1de7:
	/* 0x1de7: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1df0:
	/* 0x1df0: mov    QWORD PTR [rsp+0x88],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1df8:
	/* 0x1df8: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1e00:
	/* 0x1e00: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e05:
	/* 0x1e05: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_1e0c:
	/* 0x1e0c: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1e14:
	/* 0x1e14: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e19:
	/* 0x1e19: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e1b:
	/* 0x1e1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e1d:
	/* 0x1e1d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e20:
	/* 0x1e20: je     25f6 <generic_tracepoint_process_event+0x25f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9718ULL;
	}
x86_l_1e26:
	/* 0x1e26: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1e28:
	/* 0x1e28: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e2d:
	/* 0x1e2d: mov    WORD PTR [rsp+0x32],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 214748364805ULL);
x86_l_1e34:
	/* 0x1e34: movabs rax,0x200000046 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934662ULL);
x86_l_1e3e:
	/* 0x1e3e: mov    QWORD PTR [rsp+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1e43:
	/* 0x1e43: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e48:
	/* 0x1e48: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1e4f:
	/* 0x1e4f: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e54:
	/* 0x1e54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e56:
	/* 0x1e56: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e59:
	/* 0x1e59: je     25ce <generic_tracepoint_process_event+0x25ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9678ULL;
	}
x86_l_1e5f:
	/* 0x1e5f: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1e61:
	/* 0x1e61: jmp    25f6 <generic_tracepoint_process_event+0x25f6> */
	return 9718ULL;
x86_l_1e66:
	/* 0x1e66: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e69:
	/* 0x1e69: je     2093 <generic_tracepoint_process_event+0x2093> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2093;
	}
x86_l_1e6f:
	/* 0x1e6f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e72:
	/* 0x1e72: jne    24b3 <generic_tracepoint_process_event+0x24b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9395ULL;
	}
x86_l_1e78:
	/* 0x1e78: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_1e7b:
	/* 0x1e7b: add    rax,0x5e58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24152ULL);
x86_l_1e81:
	/* 0x1e81: jmp    209c <generic_tracepoint_process_event+0x209c> */
	goto x86_l_209c;
x86_l_1e86:
	/* 0x1e86: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e8a:
	/* 0x1e8a: lea    rdi,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e8e:
	/* 0x1e8e: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e92:
	/* 0x1e92: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e97:
	/* 0x1e97: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e9c:
	/* 0x1e9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e9e:
	/* 0x1e9e: lea    rdi,[rbp+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1ea2:
	/* 0x1ea2: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1ea6:
	/* 0x1ea6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1eab:
	/* 0x1eab: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1eb0:
	/* 0x1eb0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1eb3:
	/* 0x1eb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eb5:
	/* 0x1eb5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eb9:
	/* 0x1eb9: movzx  eax,WORD PTR [rcx+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1ebd:
	/* 0x1ebd: movbe  WORD PTR [rcx+0x2],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1ec3:
	/* 0x1ec3: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_1ec9:
	/* 0x1ec9: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_1ecc:
	/* 0x1ecc: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1ecf:
	/* 0x1ecf: jmp    b82 <generic_tracepoint_process_event+0xb82> */
	return 2946ULL;
x86_l_1ed4:
	/* 0x1ed4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ed8:
	/* 0x1ed8: lea    rdi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1edc:
	/* 0x1edc: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1ee1:
	/* 0x1ee1: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ee6:
	/* 0x1ee6: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_1eeb:
	/* 0x1eeb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eed:
	/* 0x1eed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ef0:
	/* 0x1ef0: js     1b8f <generic_tracepoint_process_event+0x1b8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7055ULL;
	}
x86_l_1ef6:
	/* 0x1ef6: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1efb:
	/* 0x1efb: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1eff:
	/* 0x1eff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f04:
	/* 0x1f04: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1f0c:
	/* 0x1f0c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f11:
	/* 0x1f11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f13:
	/* 0x1f13: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f17:
	/* 0x1f17: lea    rdi,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f1b:
	/* 0x1f1b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f20:
	/* 0x1f20: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_1f25:
	/* 0x1f25: add    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 136ULL);
x86_l_1f2d:
	/* 0x1f2d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f32:
	/* 0x1f32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f34:
	/* 0x1f34: add    r15,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_1f38:
	/* 0x1f38: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f3d:
	/* 0x1f3d: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1f45:
	/* 0x1f45: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f4a:
	/* 0x1f4a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1f4d:
	/* 0x1f4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f4f:
	/* 0x1f4f: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_1f55:
	/* 0x1f55: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f58:
	/* 0x1f58: jne    b78 <generic_tracepoint_process_event+0xb78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2936ULL;
	}
x86_l_1f5e:
	/* 0x1f5e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f60:
	/* 0x1f60: cmp    DWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_1f68:
	/* 0x1f68: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1f6b:
	/* 0x1f6b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f6f:
	/* 0x1f6f: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f71:
	/* 0x1f71: jmp    b78 <generic_tracepoint_process_event+0xb78> */
	return 2936ULL;
x86_l_1f76:
	/* 0x1f76: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f79:
	/* 0x1f79: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1f7c:
	/* 0x1f7c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1f7f:
	/* 0x1f7f: jmp    b82 <generic_tracepoint_process_event+0xb82> */
	return 2946ULL;
x86_l_1f84:
	/* 0x1f84: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_1f88:
	/* 0x1f88: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f8d:
	/* 0x1f8d: mov    esi,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 107ULL);
x86_l_1f92:
	/* 0x1f92: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1f95:
	/* 0x1f95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f97:
	/* 0x1f97: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1f9a:
	/* 0x1f9a: mov    al,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 107ULL);
x86_l_1f9c:
	/* 0x1f9c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1f9e:
	/* 0x1f9e: js     1fa7 <generic_tracepoint_process_event+0x1fa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1fa7;
	}
x86_l_1fa0:
	/* 0x1fa0: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fa4:
	/* 0x1fa4: mov    BYTE PTR [rcx+0x3],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_1fa7:
	/* 0x1fa7: mov    r15d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 112ULL);
x86_l_1fad:
	/* 0x1fad: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1fb0:
	/* 0x1fb0: jmp    b7d <generic_tracepoint_process_event+0xb7d> */
	return 2941ULL;
x86_l_1fb5:
	/* 0x1fb5: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_1fb8:
	/* 0x1fb8: je     2666 <generic_tracepoint_process_event+0x2666> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9830ULL;
	}
x86_l_1fbe:
	/* 0x1fbe: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1fc1:
	/* 0x1fc1: jne    2670 <generic_tracepoint_process_event+0x2670> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9840ULL;
	}
x86_l_1fc7:
	/* 0x1fc7: add    r15,0x5e58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24152ULL);
x86_l_1fce:
	/* 0x1fce: jmp    266d <generic_tracepoint_process_event+0x266d> */
	return 9837ULL;
x86_l_1fd3:
	/* 0x1fd3: lea    rdx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1fd7:
	/* 0x1fd7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fdc:
	/* 0x1fdc: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fe0:
	/* 0x1fe0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1fe5:
	/* 0x1fe5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fe7:
	/* 0x1fe7: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1feb:
	/* 0x1feb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ff0:
	/* 0x1ff0: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1ff3:
	/* 0x1ff3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1ff8:
	/* 0x1ff8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ffa:
	/* 0x1ffa: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ffe:
	/* 0x1ffe: lea    rdi,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2003:
	/* 0x2003: lea    r13,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2007:
	/* 0x2007: add    r15,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_200b:
	/* 0x200b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2010:
	/* 0x2010: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2015:
	/* 0x2015: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2018:
	/* 0x2018: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_201a:
	/* 0x201a: lea    rdi,[r12+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_201f:
	/* 0x201f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2024:
	/* 0x2024: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2029:
	/* 0x2029: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_202c:
	/* 0x202c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_202e:
	/* 0x202e: movzx  eax,WORD PTR [r12+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2034:
	/* 0x2034: movbe  WORD PTR [r12+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_203c:
	/* 0x203c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2040:
	/* 0x2040: mov    rax,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2044:
	/* 0x2044: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2049:
	/* 0x2049: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_204e:
	/* 0x204e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_2055:
	/* 0x2055: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_205a:
	/* 0x205a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_205c:
	/* 0x205c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_205f:
	/* 0x205f: je     2d5d <generic_tracepoint_process_event+0x2d5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11613ULL;
	}
x86_l_2065:
	/* 0x2065: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2067:
	/* 0x2067: mov    DWORD PTR [rbp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_206a:
	/* 0x206a: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_206e:
	/* 0x206e: mov    QWORD PTR [rbp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2072:
	/* 0x2072: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2075:
	/* 0x2075: mov    DWORD PTR [rbp+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2078:
	/* 0x2078: jmp    2d5d <generic_tracepoint_process_event+0x2d5d> */
	return 11613ULL;
x86_l_207d:
	/* 0x207d: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_2080:
	/* 0x2080: add    rax,0x5e60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24160ULL);
x86_l_2086:
	/* 0x2086: jmp    209c <generic_tracepoint_process_event+0x209c> */
	goto x86_l_209c;
x86_l_2088:
	/* 0x2088: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_208b:
	/* 0x208b: add    rax,0x5e68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24168ULL);
x86_l_2091:
	/* 0x2091: jmp    209c <generic_tracepoint_process_event+0x209c> */
	goto x86_l_209c;
x86_l_2093:
	/* 0x2093: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_2096:
	/* 0x2096: add    rax,0x5e50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24144ULL);
x86_l_209c:
	/* 0x209c: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_209f:
	/* 0x209f: test   sil,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_8, 16ULL);
x86_l_20a3:
	/* 0x20a3: jne    24cd <generic_tracepoint_process_event+0x24cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9421ULL;
	}
x86_l_20a9:
	/* 0x20a9: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_20ac:
	/* 0x20ac: je     2578 <generic_tracepoint_process_event+0x2578> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9592ULL;
	}
x86_l_20b2:
	/* 0x20b2: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_20b8:
	/* 0x20b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20bd:
	/* 0x20bd: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_20c2:
	/* 0x20c2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_20c7:
	/* 0x20c7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20cc:
	/* 0x20cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ce:
	/* 0x20ce: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_20d3:
	/* 0x20d3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20d5:
	/* 0x20d5: js     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9381ULL;
	}
x86_l_20db:
	/* 0x20db: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_20e0:
	/* 0x20e0: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_20e5:
	/* 0x20e5: mov    rax,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_20e8:
	/* 0x20e8: mov    QWORD PTR [rsp+0x98],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_20f0:
	/* 0x20f0: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_20f7:
	/* 0x20f7: ja     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9381ULL;
	}
x86_l_20fd:
	/* 0x20fd: lea    rdi,[rbx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2101:
	/* 0x2101: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_2104:
	/* 0x2104: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_210a:
	/* 0x210a: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_210f:
	/* 0x210f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2114:
	/* 0x2114: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2119:
	/* 0x2119: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2121:
	/* 0x2121: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2123:
	/* 0x2123: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2128:
	/* 0x2128: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_212a:
	/* 0x212a: js     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9381ULL;
	}
x86_l_2130:
	/* 0x2130: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_2134:
	/* 0x2134: je     2582 <generic_tracepoint_process_event+0x2582> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9602ULL;
	}
x86_l_213a:
	/* 0x213a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_213f:
	/* 0x213f: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2143:
	/* 0x2143: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2149:
	/* 0x2149: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_214e:
	/* 0x214e: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2153:
	/* 0x2153: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2158:
	/* 0x2158: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_215a:
	/* 0x215a: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_215f:
	/* 0x215f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2161:
	/* 0x2161: js     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9381ULL;
	}
x86_l_2167:
	/* 0x2167: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_216c:
	/* 0x216c: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2171:
	/* 0x2171: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2175:
	/* 0x2175: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_217b:
	/* 0x217b: ja     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9381ULL;
	}
x86_l_2181:
	/* 0x2181: add    rbp,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 152ULL);
x86_l_2189:
	/* 0x2189: mov    QWORD PTR [rsp+0xb8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2191:
	/* 0x2191: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_2193:
	/* 0x2193: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2199:
	/* 0x2199: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_219e:
	/* 0x219e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21a3:
	/* 0x21a3: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_21a8:
	/* 0x21a8: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21ac:
	/* 0x21ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21ae:
	/* 0x21ae: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_21b3:
	/* 0x21b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21b5:
	/* 0x21b5: js     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9381ULL;
	}
x86_l_21bb:
	/* 0x21bb: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21bf:
	/* 0x21bf: add    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 152ULL);
x86_l_21c7:
	/* 0x21c7: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_21cb:
	/* 0x21cb: jb     2582 <generic_tracepoint_process_event+0x2582> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9602ULL;
	}
x86_l_21d1:
	/* 0x21d1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21d6:
	/* 0x21d6: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21da:
	/* 0x21da: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_21e0:
	/* 0x21e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21e5:
	/* 0x21e5: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_21ea:
	/* 0x21ea: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_21ef:
	/* 0x21ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21f1:
	/* 0x21f1: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_21f6:
	/* 0x21f6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21f8:
	/* 0x21f8: js     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9381ULL;
	}
x86_l_21fe:
	/* 0x21fe: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2203:
	/* 0x2203: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2208:
	/* 0x2208: mov    QWORD PTR [rsp+0xd8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2210:
	/* 0x2210: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_2216:
	/* 0x2216: ja     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9381ULL;
	}
x86_l_221c:
	/* 0x221c: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2220:
	/* 0x2220: add    rdi,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 184ULL);
x86_l_2228:
	/* 0x2228: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_222b:
	/* 0x222b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2231:
	/* 0x2231: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2236:
	/* 0x2236: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_223b:
	/* 0x223b: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2240:
	/* 0x2240: mov    rsi,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2248:
	/* 0x2248: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_224a:
	/* 0x224a: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_224f:
	/* 0x224f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2251:
	/* 0x2251: js     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9381ULL;
	}
x86_l_2257:
	/* 0x2257: mov    rax,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_225f:
	/* 0x225f: add    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 152ULL);
x86_l_2267:
	/* 0x2267: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_226b:
	/* 0x226b: je     2582 <generic_tracepoint_process_event+0x2582> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9602ULL;
	}
x86_l_2271:
	/* 0x2271: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2276:
	/* 0x2276: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_227a:
	/* 0x227a: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2280:
	/* 0x2280: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2285:
	/* 0x2285: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_228a:
	/* 0x228a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_228f:
	/* 0x228f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2291:
	/* 0x2291: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2296:
	/* 0x2296: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2298:
	/* 0x2298: js     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9381ULL;
	}
x86_l_229e:
	/* 0x229e: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_22a3:
	/* 0x22a3: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_22a8:
	/* 0x22a8: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22ac:
	/* 0x22ac: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_22b2:
	/* 0x22b2: ja     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9381ULL;
	}
x86_l_22b8:
	/* 0x22b8: mov    rdi,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_22c0:
	/* 0x22c0: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_22c3:
	/* 0x22c3: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_22c6:
	/* 0x22c6: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_22cc:
	/* 0x22cc: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_22d1:
	/* 0x22d1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22d6:
	/* 0x22d6: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_22db:
	/* 0x22db: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22df:
	/* 0x22df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 8929ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_process_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8929ULL: goto x86_l_22e1;
	case 8934ULL: goto x86_l_22e6;
	case 8936ULL: goto x86_l_22e8;
	case 8942ULL: goto x86_l_22ee;
	case 8946ULL: goto x86_l_22f2;
	case 8954ULL: goto x86_l_22fa;
	case 8958ULL: goto x86_l_22fe;
	case 8964ULL: goto x86_l_2304;
	case 8969ULL: goto x86_l_2309;
	case 8973ULL: goto x86_l_230d;
	case 8979ULL: goto x86_l_2313;
	case 8984ULL: goto x86_l_2318;
	case 8989ULL: goto x86_l_231d;
	case 8994ULL: goto x86_l_2322;
	case 8996ULL: goto x86_l_2324;
	case 9001ULL: goto x86_l_2329;
	case 9003ULL: goto x86_l_232b;
	case 9009ULL: goto x86_l_2331;
	case 9014ULL: goto x86_l_2336;
	case 9019ULL: goto x86_l_233b;
	case 9027ULL: goto x86_l_2343;
	case 9033ULL: goto x86_l_2349;
	case 9039ULL: goto x86_l_234f;
	case 9043ULL: goto x86_l_2353;
	case 9046ULL: goto x86_l_2356;
	case 9049ULL: goto x86_l_2359;
	case 9055ULL: goto x86_l_235f;
	case 9060ULL: goto x86_l_2364;
	case 9065ULL: goto x86_l_2369;
	case 9070ULL: goto x86_l_236e;
	case 9078ULL: goto x86_l_2376;
	case 9080ULL: goto x86_l_2378;
	case 9085ULL: goto x86_l_237d;
	case 9087ULL: goto x86_l_237f;
	case 9093ULL: goto x86_l_2385;
	case 9101ULL: goto x86_l_238d;
	case 9109ULL: goto x86_l_2395;
	case 9113ULL: goto x86_l_2399;
	case 9119ULL: goto x86_l_239f;
	case 9124ULL: goto x86_l_23a4;
	case 9128ULL: goto x86_l_23a8;
	case 9134ULL: goto x86_l_23ae;
	case 9139ULL: goto x86_l_23b3;
	case 9144ULL: goto x86_l_23b8;
	case 9149ULL: goto x86_l_23bd;
	case 9151ULL: goto x86_l_23bf;
	case 9156ULL: goto x86_l_23c4;
	case 9158ULL: goto x86_l_23c6;
	case 9164ULL: goto x86_l_23cc;
	case 9169ULL: goto x86_l_23d1;
	case 9174ULL: goto x86_l_23d6;
	case 9178ULL: goto x86_l_23da;
	case 9184ULL: goto x86_l_23e0;
	case 9190ULL: goto x86_l_23e6;
	case 9198ULL: goto x86_l_23ee;
	case 9201ULL: goto x86_l_23f1;
	case 9204ULL: goto x86_l_23f4;
	case 9210ULL: goto x86_l_23fa;
	case 9215ULL: goto x86_l_23ff;
	case 9220ULL: goto x86_l_2404;
	case 9225ULL: goto x86_l_2409;
	case 9229ULL: goto x86_l_240d;
	case 9231ULL: goto x86_l_240f;
	case 9236ULL: goto x86_l_2414;
	case 9238ULL: goto x86_l_2416;
	case 9244ULL: goto x86_l_241c;
	case 9248ULL: goto x86_l_2420;
	case 9256ULL: goto x86_l_2428;
	case 9260ULL: goto x86_l_242c;
	case 9266ULL: goto x86_l_2432;
	case 9271ULL: goto x86_l_2437;
	case 9275ULL: goto x86_l_243b;
	case 9281ULL: goto x86_l_2441;
	case 9286ULL: goto x86_l_2446;
	case 9291ULL: goto x86_l_244b;
	case 9296ULL: goto x86_l_2450;
	case 9298ULL: goto x86_l_2452;
	case 9303ULL: goto x86_l_2457;
	case 9305ULL: goto x86_l_2459;
	case 9307ULL: goto x86_l_245b;
	case 9312ULL: goto x86_l_2460;
	case 9317ULL: goto x86_l_2465;
	case 9324ULL: goto x86_l_246c;
	case 9326ULL: goto x86_l_246e;
	case 9330ULL: goto x86_l_2472;
	case 9333ULL: goto x86_l_2475;
	case 9339ULL: goto x86_l_247b;
	case 9344ULL: goto x86_l_2480;
	case 9349ULL: goto x86_l_2485;
	case 9354ULL: goto x86_l_248a;
	case 9357ULL: goto x86_l_248d;
	case 9359ULL: goto x86_l_248f;
	case 9364ULL: goto x86_l_2494;
	case 9366ULL: goto x86_l_2496;
	case 9368ULL: goto x86_l_2498;
	case 9376ULL: goto x86_l_24a0;
	case 9381ULL: goto x86_l_24a5;
	case 9386ULL: goto x86_l_24aa;
	case 9390ULL: goto x86_l_24ae;
	case 9395ULL: goto x86_l_24b3;
	case 9398ULL: goto x86_l_24b6;
	case 9403ULL: goto x86_l_24bb;
	case 9411ULL: goto x86_l_24c3;
	case 9415ULL: goto x86_l_24c7;
	case 9421ULL: goto x86_l_24cd;
	case 9426ULL: goto x86_l_24d2;
	case 9428ULL: goto x86_l_24d4;
	case 9432ULL: goto x86_l_24d8;
	case 9434ULL: goto x86_l_24da;
	case 9442ULL: goto x86_l_24e2;
	case 9446ULL: goto x86_l_24e6;
	case 9450ULL: goto x86_l_24ea;
	case 9454ULL: goto x86_l_24ee;
	case 9459ULL: goto x86_l_24f3;
	case 9464ULL: goto x86_l_24f8;
	case 9469ULL: goto x86_l_24fd;
	case 9474ULL: goto x86_l_2502;
	case 9482ULL: goto x86_l_250a;
	case 9490ULL: goto x86_l_2512;
	case 9495ULL: goto x86_l_2517;
	case 9502ULL: goto x86_l_251e;
	case 9510ULL: goto x86_l_2526;
	case 9515ULL: goto x86_l_252b;
	case 9517ULL: goto x86_l_252d;
	case 9519ULL: goto x86_l_252f;
	case 9522ULL: goto x86_l_2532;
	case 9528ULL: goto x86_l_2538;
	case 9530ULL: goto x86_l_253a;
	case 9535ULL: goto x86_l_253f;
	case 9542ULL: goto x86_l_2546;
	case 9552ULL: goto x86_l_2550;
	case 9557ULL: goto x86_l_2555;
	case 9562ULL: goto x86_l_255a;
	case 9569ULL: goto x86_l_2561;
	case 9574ULL: goto x86_l_2566;
	case 9576ULL: goto x86_l_2568;
	case 9579ULL: goto x86_l_256b;
	case 9585ULL: goto x86_l_2571;
	case 9587ULL: goto x86_l_2573;
	case 9592ULL: goto x86_l_2578;
	case 9594ULL: goto x86_l_257a;
	case 9602ULL: goto x86_l_2582;
	case 9607ULL: goto x86_l_2587;
	case 9615ULL: goto x86_l_258f;
	case 9619ULL: goto x86_l_2593;
	case 9624ULL: goto x86_l_2598;
	case 9628ULL: goto x86_l_259c;
	case 9633ULL: goto x86_l_25a1;
	case 9636ULL: goto x86_l_25a4;
	case 9642ULL: goto x86_l_25aa;
	case 9645ULL: goto x86_l_25ad;
	case 9651ULL: goto x86_l_25b3;
	case 9656ULL: goto x86_l_25b8;
	case 9662ULL: goto x86_l_25be;
	case 9669ULL: goto x86_l_25c5;
	case 9673ULL: goto x86_l_25c9;
	case 9678ULL: goto x86_l_25ce;
	case 9689ULL: goto x86_l_25d9;
	case 9694ULL: goto x86_l_25de;
	case 9701ULL: goto x86_l_25e5;
	case 9706ULL: goto x86_l_25ea;
	case 9714ULL: goto x86_l_25f2;
	case 9716ULL: goto x86_l_25f4;
	case 9718ULL: goto x86_l_25f6;
	case 9726ULL: goto x86_l_25fe;
	case 9732ULL: goto x86_l_2604;
	case 9737ULL: goto x86_l_2609;
	case 9745ULL: goto x86_l_2611;
	case 9750ULL: goto x86_l_2616;
	case 9757ULL: goto x86_l_261d;
	case 9762ULL: goto x86_l_2622;
	case 9767ULL: goto x86_l_2627;
	case 9769ULL: goto x86_l_2629;
	case 9771ULL: goto x86_l_262b;
	case 9776ULL: goto x86_l_2630;
	case 9784ULL: goto x86_l_2638;
	case 9790ULL: goto x86_l_263e;
	case 9795ULL: goto x86_l_2643;
	case 9800ULL: goto x86_l_2648;
	case 9807ULL: goto x86_l_264f;
	case 9812ULL: goto x86_l_2654;
	case 9819ULL: goto x86_l_265b;
	case 9821ULL: goto x86_l_265d;
	case 9828ULL: goto x86_l_2664;
	case 9830ULL: goto x86_l_2666;
	case 9837ULL: goto x86_l_266d;
	case 9840ULL: goto x86_l_2670;
	case 9845ULL: goto x86_l_2675;
	case 9851ULL: goto x86_l_267b;
	case 9856ULL: goto x86_l_2680;
	case 9864ULL: goto x86_l_2688;
	case 9869ULL: goto x86_l_268d;
	case 9874ULL: goto x86_l_2692;
	case 9876ULL: goto x86_l_2694;
	case 9884ULL: goto x86_l_269c;
	case 9891ULL: goto x86_l_26a3;
	case 9897ULL: goto x86_l_26a9;
	case 9901ULL: goto x86_l_26ad;
	case 9906ULL: goto x86_l_26b2;
	case 9911ULL: goto x86_l_26b7;
	case 9914ULL: goto x86_l_26ba;
	case 9919ULL: goto x86_l_26bf;
	case 9921ULL: goto x86_l_26c1;
	case 9923ULL: goto x86_l_26c3;
	case 9925ULL: goto x86_l_26c5;
	case 9929ULL: goto x86_l_26c9;
	case 9934ULL: goto x86_l_26ce;
	case 9938ULL: goto x86_l_26d2;
	case 9941ULL: goto x86_l_26d5;
	case 9946ULL: goto x86_l_26da;
	case 9954ULL: goto x86_l_26e2;
	case 9959ULL: goto x86_l_26e7;
	case 9964ULL: goto x86_l_26ec;
	case 9971ULL: goto x86_l_26f3;
	case 9976ULL: goto x86_l_26f8;
	case 9981ULL: goto x86_l_26fd;
	case 9986ULL: goto x86_l_2702;
	case 9991ULL: goto x86_l_2707;
	case 9995ULL: goto x86_l_270b;
	case 10001ULL: goto x86_l_2711;
	case 10011ULL: goto x86_l_271b;
	case 10015ULL: goto x86_l_271f;
	case 10021ULL: goto x86_l_2725;
	case 10025ULL: goto x86_l_2729;
	case 10030ULL: goto x86_l_272e;
	case 10035ULL: goto x86_l_2733;
	case 10040ULL: goto x86_l_2738;
	case 10045ULL: goto x86_l_273d;
	case 10050ULL: goto x86_l_2742;
	case 10052ULL: goto x86_l_2744;
	case 10055ULL: goto x86_l_2747;
	case 10061ULL: goto x86_l_274d;
	case 10066ULL: goto x86_l_2752;
	case 10069ULL: goto x86_l_2755;
	case 10071ULL: goto x86_l_2757;
	case 10073ULL: goto x86_l_2759;
	case 10075ULL: goto x86_l_275b;
	case 10078ULL: goto x86_l_275e;
	case 10080ULL: goto x86_l_2760;
	case 10083ULL: goto x86_l_2763;
	case 10085ULL: goto x86_l_2765;
	case 10092ULL: goto x86_l_276c;
	case 10096ULL: goto x86_l_2770;
	case 10098ULL: goto x86_l_2772;
	case 10101ULL: goto x86_l_2775;
	case 10103ULL: goto x86_l_2777;
	case 10106ULL: goto x86_l_277a;
	case 10108ULL: goto x86_l_277c;
	case 10113ULL: goto x86_l_2781;
	case 10115ULL: goto x86_l_2783;
	case 10122ULL: goto x86_l_278a;
	case 10126ULL: goto x86_l_278e;
	case 10128ULL: goto x86_l_2790;
	case 10133ULL: goto x86_l_2795;
	case 10140ULL: goto x86_l_279c;
	case 10145ULL: goto x86_l_27a1;
	case 10147ULL: goto x86_l_27a3;
	case 10152ULL: goto x86_l_27a8;
	case 10157ULL: goto x86_l_27ad;
	case 10162ULL: goto x86_l_27b2;
	case 10169ULL: goto x86_l_27b9;
	case 10174ULL: goto x86_l_27be;
	case 10176ULL: goto x86_l_27c0;
	case 10181ULL: goto x86_l_27c5;
	case 10186ULL: goto x86_l_27ca;
	case 10191ULL: goto x86_l_27cf;
	case 10196ULL: goto x86_l_27d4;
	case 10200ULL: goto x86_l_27d8;
	case 10206ULL: goto x86_l_27de;
	case 10216ULL: goto x86_l_27e8;
	case 10220ULL: goto x86_l_27ec;
	case 10226ULL: goto x86_l_27f2;
	case 10230ULL: goto x86_l_27f6;
	case 10235ULL: goto x86_l_27fb;
	case 10240ULL: goto x86_l_2800;
	case 10245ULL: goto x86_l_2805;
	case 10250ULL: goto x86_l_280a;
	case 10255ULL: goto x86_l_280f;
	case 10257ULL: goto x86_l_2811;
	case 10260ULL: goto x86_l_2814;
	case 10266ULL: goto x86_l_281a;
	case 10271ULL: goto x86_l_281f;
	case 10274ULL: goto x86_l_2822;
	case 10276ULL: goto x86_l_2824;
	case 10278ULL: goto x86_l_2826;
	case 10280ULL: goto x86_l_2828;
	case 10283ULL: goto x86_l_282b;
	case 10285ULL: goto x86_l_282d;
	case 10288ULL: goto x86_l_2830;
	case 10290ULL: goto x86_l_2832;
	case 10297ULL: goto x86_l_2839;
	case 10301ULL: goto x86_l_283d;
	case 10303ULL: goto x86_l_283f;
	case 10306ULL: goto x86_l_2842;
	case 10308ULL: goto x86_l_2844;
	case 10311ULL: goto x86_l_2847;
	case 10313ULL: goto x86_l_2849;
	case 10318ULL: goto x86_l_284e;
	case 10320ULL: goto x86_l_2850;
	case 10327ULL: goto x86_l_2857;
	case 10331ULL: goto x86_l_285b;
	case 10333ULL: goto x86_l_285d;
	case 10338ULL: goto x86_l_2862;
	case 10345ULL: goto x86_l_2869;
	case 10350ULL: goto x86_l_286e;
	case 10352ULL: goto x86_l_2870;
	case 10357ULL: goto x86_l_2875;
	case 10364ULL: goto x86_l_287c;
	case 10369ULL: goto x86_l_2881;
	case 10371ULL: goto x86_l_2883;
	case 10376ULL: goto x86_l_2888;
	case 10381ULL: goto x86_l_288d;
	case 10386ULL: goto x86_l_2892;
	case 10391ULL: goto x86_l_2897;
	case 10395ULL: goto x86_l_289b;
	case 10401ULL: goto x86_l_28a1;
	case 10411ULL: goto x86_l_28ab;
	case 10415ULL: goto x86_l_28af;
	case 10421ULL: goto x86_l_28b5;
	case 10425ULL: goto x86_l_28b9;
	case 10430ULL: goto x86_l_28be;
	case 10435ULL: goto x86_l_28c3;
	case 10440ULL: goto x86_l_28c8;
	case 10445ULL: goto x86_l_28cd;
	case 10450ULL: goto x86_l_28d2;
	case 10452ULL: goto x86_l_28d4;
	case 10455ULL: goto x86_l_28d7;
	case 10461ULL: goto x86_l_28dd;
	case 10466ULL: goto x86_l_28e2;
	case 10469ULL: goto x86_l_28e5;
	case 10471ULL: goto x86_l_28e7;
	case 10473ULL: goto x86_l_28e9;
	case 10475ULL: goto x86_l_28eb;
	case 10478ULL: goto x86_l_28ee;
	case 10480ULL: goto x86_l_28f0;
	case 10483ULL: goto x86_l_28f3;
	case 10485ULL: goto x86_l_28f5;
	case 10492ULL: goto x86_l_28fc;
	case 10496ULL: goto x86_l_2900;
	case 10498ULL: goto x86_l_2902;
	case 10501ULL: goto x86_l_2905;
	case 10503ULL: goto x86_l_2907;
	case 10506ULL: goto x86_l_290a;
	case 10508ULL: goto x86_l_290c;
	case 10513ULL: goto x86_l_2911;
	case 10515ULL: goto x86_l_2913;
	case 10522ULL: goto x86_l_291a;
	case 10526ULL: goto x86_l_291e;
	case 10528ULL: goto x86_l_2920;
	case 10533ULL: goto x86_l_2925;
	case 10540ULL: goto x86_l_292c;
	case 10545ULL: goto x86_l_2931;
	case 10547ULL: goto x86_l_2933;
	case 10552ULL: goto x86_l_2938;
	case 10559ULL: goto x86_l_293f;
	case 10564ULL: goto x86_l_2944;
	case 10566ULL: goto x86_l_2946;
	case 10571ULL: goto x86_l_294b;
	case 10576ULL: goto x86_l_2950;
	case 10581ULL: goto x86_l_2955;
	case 10586ULL: goto x86_l_295a;
	case 10590ULL: goto x86_l_295e;
	case 10596ULL: goto x86_l_2964;
	case 10606ULL: goto x86_l_296e;
	case 10610ULL: goto x86_l_2972;
	case 10616ULL: goto x86_l_2978;
	case 10620ULL: goto x86_l_297c;
	case 10625ULL: goto x86_l_2981;
	case 10630ULL: goto x86_l_2986;
	case 10635ULL: goto x86_l_298b;
	case 10640ULL: goto x86_l_2990;
	case 10645ULL: goto x86_l_2995;
	case 10647ULL: goto x86_l_2997;
	case 10650ULL: goto x86_l_299a;
	case 10656ULL: goto x86_l_29a0;
	case 10661ULL: goto x86_l_29a5;
	case 10664ULL: goto x86_l_29a8;
	case 10666ULL: goto x86_l_29aa;
	case 10668ULL: goto x86_l_29ac;
	case 10670ULL: goto x86_l_29ae;
	case 10673ULL: goto x86_l_29b1;
	case 10675ULL: goto x86_l_29b3;
	case 10678ULL: goto x86_l_29b6;
	case 10680ULL: goto x86_l_29b8;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22e1:
	/* 0x22e1: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_22e6:
	/* 0x22e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22e8:
	/* 0x22e8: js     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_24a5;
	}
x86_l_22ee:
	/* 0x22ee: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22f2:
	/* 0x22f2: add    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 152ULL);
x86_l_22fa:
	/* 0x22fa: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_22fe:
	/* 0x22fe: jb     2582 <generic_tracepoint_process_event+0x2582> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2582;
	}
x86_l_2304:
	/* 0x2304: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2309:
	/* 0x2309: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_230d:
	/* 0x230d: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2313:
	/* 0x2313: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2318:
	/* 0x2318: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_231d:
	/* 0x231d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2322:
	/* 0x2322: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2324:
	/* 0x2324: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2329:
	/* 0x2329: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_232b:
	/* 0x232b: js     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_24a5;
	}
x86_l_2331:
	/* 0x2331: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2336:
	/* 0x2336: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_233b:
	/* 0x233b: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2343:
	/* 0x2343: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_2349:
	/* 0x2349: ja     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_24a5;
	}
x86_l_234f:
	/* 0x234f: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2353:
	/* 0x2353: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2356:
	/* 0x2356: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_2359:
	/* 0x2359: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_235f:
	/* 0x235f: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2364:
	/* 0x2364: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2369:
	/* 0x2369: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_236e:
	/* 0x236e: mov    rsi,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2376:
	/* 0x2376: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2378:
	/* 0x2378: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_237d:
	/* 0x237d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_237f:
	/* 0x237f: js     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_24a5;
	}
x86_l_2385:
	/* 0x2385: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_238d:
	/* 0x238d: add    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 152ULL);
x86_l_2395:
	/* 0x2395: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_2399:
	/* 0x2399: je     2582 <generic_tracepoint_process_event+0x2582> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2582;
	}
x86_l_239f:
	/* 0x239f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23a4:
	/* 0x23a4: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_23a8:
	/* 0x23a8: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_23ae:
	/* 0x23ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23b3:
	/* 0x23b3: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_23b8:
	/* 0x23b8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_23bd:
	/* 0x23bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23bf:
	/* 0x23bf: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_23c4:
	/* 0x23c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23c6:
	/* 0x23c6: js     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_24a5;
	}
x86_l_23cc:
	/* 0x23cc: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_23d1:
	/* 0x23d1: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_23d6:
	/* 0x23d6: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23da:
	/* 0x23da: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_23e0:
	/* 0x23e0: ja     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_24a5;
	}
x86_l_23e6:
	/* 0x23e6: mov    rdi,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_23ee:
	/* 0x23ee: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23f1:
	/* 0x23f1: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_23f4:
	/* 0x23f4: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_23fa:
	/* 0x23fa: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_23ff:
	/* 0x23ff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2404:
	/* 0x2404: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2409:
	/* 0x2409: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_240d:
	/* 0x240d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_240f:
	/* 0x240f: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2414:
	/* 0x2414: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2416:
	/* 0x2416: js     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_24a5;
	}
x86_l_241c:
	/* 0x241c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2420:
	/* 0x2420: add    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 152ULL);
x86_l_2428:
	/* 0x2428: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_242c:
	/* 0x242c: jb     2582 <generic_tracepoint_process_event+0x2582> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2582;
	}
x86_l_2432:
	/* 0x2432: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2437:
	/* 0x2437: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_243b:
	/* 0x243b: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2441:
	/* 0x2441: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2446:
	/* 0x2446: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_244b:
	/* 0x244b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2450:
	/* 0x2450: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2452:
	/* 0x2452: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2457:
	/* 0x2457: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2459:
	/* 0x2459: js     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_24a5;
	}
x86_l_245b:
	/* 0x245b: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2460:
	/* 0x2460: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2465:
	/* 0x2465: cmp    r13,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4094ULL);
x86_l_246c:
	/* 0x246c: ja     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_24a5;
	}
x86_l_246e:
	/* 0x246e: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2472:
	/* 0x2472: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2475:
	/* 0x2475: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_247b:
	/* 0x247b: add    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2480:
	/* 0x2480: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2485:
	/* 0x2485: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_248a:
	/* 0x248a: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_248d:
	/* 0x248d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_248f:
	/* 0x248f: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2494:
	/* 0x2494: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2496:
	/* 0x2496: js     24a5 <generic_tracepoint_process_event+0x24a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_24a5;
	}
x86_l_2498:
	/* 0x2498: add    QWORD PTR [rsp+0x98],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 152ULL);
x86_l_24a0:
	/* 0x24a0: jmp    2582 <generic_tracepoint_process_event+0x2582> */
	goto x86_l_2582;
x86_l_24a5:
	/* 0x24a5: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24aa:
	/* 0x24aa: mov    DWORD PTR [rax+r12*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_24ae:
	/* 0x24ae: jmp    b78 <generic_tracepoint_process_event+0xb78> */
	return 2936ULL;
x86_l_24b3:
	/* 0x24b3: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24b6:
	/* 0x24b6: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_24bb:
	/* 0x24bb: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_24c3:
	/* 0x24c3: test   sil,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_8, 16ULL);
x86_l_24c7:
	/* 0x24c7: je     2582 <generic_tracepoint_process_event+0x2582> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2582;
	}
x86_l_24cd:
	/* 0x24cd: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_24d2:
	/* 0x24d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24d4:
	/* 0x24d4: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_24d8:
	/* 0x24d8: jne    24e6 <generic_tracepoint_process_event+0x24e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24e6;
	}
x86_l_24da:
	/* 0x24da: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_24e2:
	/* 0x24e2: mov    rax,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24e6:
	/* 0x24e6: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24ea:
	/* 0x24ea: mov    rdx,QWORD PTR [rbp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_24ee:
	/* 0x24ee: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_24f3:
	/* 0x24f3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24f8:
	/* 0x24f8: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_24fd:
	/* 0x24fd: mov    QWORD PTR [rsp+0x50],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2502:
	/* 0x2502: mov    QWORD PTR [rsp+0x88],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_250a:
	/* 0x250a: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2512:
	/* 0x2512: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2517:
	/* 0x2517: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_251e:
	/* 0x251e: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2526:
	/* 0x2526: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_252b:
	/* 0x252b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_252d:
	/* 0x252d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_252f:
	/* 0x252f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2532:
	/* 0x2532: je     262b <generic_tracepoint_process_event+0x262b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_262b;
	}
x86_l_2538:
	/* 0x2538: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_253a:
	/* 0x253a: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_253f:
	/* 0x253f: mov    WORD PTR [rsp+0x32],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 214748364805ULL);
x86_l_2546:
	/* 0x2546: movabs rax,0x200000057 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934679ULL);
x86_l_2550:
	/* 0x2550: mov    QWORD PTR [rsp+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2555:
	/* 0x2555: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_255a:
	/* 0x255a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2561:
	/* 0x2561: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2566:
	/* 0x2566: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2568:
	/* 0x2568: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_256b:
	/* 0x256b: je     2609 <generic_tracepoint_process_event+0x2609> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2609;
	}
x86_l_2571:
	/* 0x2571: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2573:
	/* 0x2573: jmp    262b <generic_tracepoint_process_event+0x262b> */
	goto x86_l_262b;
x86_l_2578:
	/* 0x2578: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_257a:
	/* 0x257a: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2582:
	/* 0x2582: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2587:
	/* 0x2587: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_258f:
	/* 0x258f: mov    DWORD PTR [rax+r12*1],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2593:
	/* 0x2593: mov    DWORD PTR [rax+r12*1+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 4ULL);
x86_l_2598:
	/* 0x2598: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_259c:
	/* 0x259c: jmp    b78 <generic_tracepoint_process_event+0xb78> */
	return 2936ULL;
x86_l_25a1:
	/* 0x25a1: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_25a4:
	/* 0x25a4: je     26e7 <generic_tracepoint_process_event+0x26e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26e7;
	}
x86_l_25aa:
	/* 0x25aa: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_25ad:
	/* 0x25ad: je     2643 <generic_tracepoint_process_event+0x2643> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2643;
	}
x86_l_25b3:
	/* 0x25b3: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_25b8:
	/* 0x25b8: jne    27a3 <generic_tracepoint_process_event+0x27a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_27a3;
	}
x86_l_25be:
	/* 0x25be: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_25c5:
	/* 0x25c5: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_25c9:
	/* 0x25c9: jmp    26f8 <generic_tracepoint_process_event+0x26f8> */
	goto x86_l_26f8;
x86_l_25ce:
	/* 0x25ce: mov    DWORD PTR [rsp+0xb0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244097ULL);
x86_l_25d9:
	/* 0x25d9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_25de:
	/* 0x25de: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_25e5:
	/* 0x25e5: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25ea:
	/* 0x25ea: lea    rdx,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_25f2:
	/* 0x25f2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25f4:
	/* 0x25f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25f6:
	/* 0x25f6: mov    DWORD PTR [r12],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967292ULL);
x86_l_25fe:
	/* 0x25fe: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2604:
	/* 0x2604: jmp    b78 <generic_tracepoint_process_event+0xb78> */
	return 2936ULL;
x86_l_2609:
	/* 0x2609: mov    DWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_2611:
	/* 0x2611: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2616:
	/* 0x2616: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_261d:
	/* 0x261d: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2622:
	/* 0x2622: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2627:
	/* 0x2627: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2629:
	/* 0x2629: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_262b:
	/* 0x262b: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2630:
	/* 0x2630: mov    DWORD PTR [rax+r12*1],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 4294967292ULL);
x86_l_2638:
	/* 0x2638: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_263e:
	/* 0x263e: jmp    b78 <generic_tracepoint_process_event+0xb78> */
	return 2936ULL;
x86_l_2643:
	/* 0x2643: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2648:
	/* 0x2648: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_264f:
	/* 0x264f: jmp    26f3 <generic_tracepoint_process_event+0x26f3> */
	goto x86_l_26f3;
x86_l_2654:
	/* 0x2654: add    r15,0x5e60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24160ULL);
x86_l_265b:
	/* 0x265b: jmp    266d <generic_tracepoint_process_event+0x266d> */
	goto x86_l_266d;
x86_l_265d:
	/* 0x265d: add    r15,0x5e68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24168ULL);
x86_l_2664:
	/* 0x2664: jmp    266d <generic_tracepoint_process_event+0x266d> */
	goto x86_l_266d;
x86_l_2666:
	/* 0x2666: add    r15,0x5e50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24144ULL);
x86_l_266d:
	/* 0x266d: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2670:
	/* 0x2670: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2675:
	/* 0x2675: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_267b:
	/* 0x267b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2680:
	/* 0x2680: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2688:
	/* 0x2688: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_268d:
	/* 0x268d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2692:
	/* 0x2692: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2694:
	/* 0x2694: mov    rbp,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_269c:
	/* 0x269c: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_26a3:
	/* 0x26a3: mov    r13d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4095ULL);
x86_l_26a9:
	/* 0x26a9: cmovb  r13,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_64, X86_CC_B);
x86_l_26ad:
	/* 0x26ad: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26b2:
	/* 0x26b2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26b7:
	/* 0x26b7: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_26ba:
	/* 0x26ba: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26bf:
	/* 0x26bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26c1:
	/* 0x26c1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26c3:
	/* 0x26c3: js     26da <generic_tracepoint_process_event+0x26da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_26da;
	}
x86_l_26c5:
	/* 0x26c5: mov    DWORD PTR [r12],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26c9:
	/* 0x26c9: mov    DWORD PTR [r12+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_26ce:
	/* 0x26ce: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_26d2:
	/* 0x26d2: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_26d5:
	/* 0x26d5: jmp    b78 <generic_tracepoint_process_event+0xb78> */
	return 2936ULL;
x86_l_26da:
	/* 0x26da: mov    DWORD PTR [r12],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_26e2:
	/* 0x26e2: jmp    b78 <generic_tracepoint_process_event+0xb78> */
	return 2936ULL;
x86_l_26e7:
	/* 0x26e7: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_26ec:
	/* 0x26ec: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_26f3:
	/* 0x26f3: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_26f8:
	/* 0x26f8: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_26fd:
	/* 0x26fd: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2702:
	/* 0x2702: movzx  r15d,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2707:
	/* 0x2707: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_270b:
	/* 0x270b: ja     2d68 <generic_tracepoint_process_event+0x2d68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11624ULL;
	}
x86_l_2711:
	/* 0x2711: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_271b:
	/* 0x271b: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_271f:
	/* 0x271f: jae    2d68 <generic_tracepoint_process_event+0x2d68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11624ULL;
	}
x86_l_2725:
	/* 0x2725: mov    BYTE PTR [r13+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2729:
	/* 0x2729: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_272e:
	/* 0x272e: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2733:
	/* 0x2733: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2738:
	/* 0x2738: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_273d:
	/* 0x273d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2742:
	/* 0x2742: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2744:
	/* 0x2744: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2747:
	/* 0x2747: js     2be3 <generic_tracepoint_process_event+0x2be3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11235ULL;
	}
x86_l_274d:
	/* 0x274d: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2752:
	/* 0x2752: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2755:
	/* 0x2755: jg     2772 <generic_tracepoint_process_event+0x2772> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2772;
	}
x86_l_2757:
	/* 0x2757: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2759:
	/* 0x2759: je     2790 <generic_tracepoint_process_event+0x2790> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2790;
	}
x86_l_275b:
	/* 0x275b: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_275e:
	/* 0x275e: je     2790 <generic_tracepoint_process_event+0x2790> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2790;
	}
x86_l_2760:
	/* 0x2760: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2763:
	/* 0x2763: jne    27c0 <generic_tracepoint_process_event+0x27c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_27c0;
	}
x86_l_2765:
	/* 0x2765: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_276c:
	/* 0x276c: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2770:
	/* 0x2770: jmp    27c5 <generic_tracepoint_process_event+0x27c5> */
	goto x86_l_27c5;
x86_l_2772:
	/* 0x2772: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2775:
	/* 0x2775: je     27ad <generic_tracepoint_process_event+0x27ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27ad;
	}
x86_l_2777:
	/* 0x2777: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_277a:
	/* 0x277a: je     2790 <generic_tracepoint_process_event+0x2790> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2790;
	}
x86_l_277c:
	/* 0x277c: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2781:
	/* 0x2781: jne    27c0 <generic_tracepoint_process_event+0x27c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_27c0;
	}
x86_l_2783:
	/* 0x2783: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_278a:
	/* 0x278a: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_278e:
	/* 0x278e: jmp    27c5 <generic_tracepoint_process_event+0x27c5> */
	goto x86_l_27c5;
x86_l_2790:
	/* 0x2790: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2795:
	/* 0x2795: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_279c:
	/* 0x279c: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_27a1:
	/* 0x27a1: jmp    27c5 <generic_tracepoint_process_event+0x27c5> */
	goto x86_l_27c5;
x86_l_27a3:
	/* 0x27a3: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_27a8:
	/* 0x27a8: jmp    26f8 <generic_tracepoint_process_event+0x26f8> */
	goto x86_l_26f8;
x86_l_27ad:
	/* 0x27ad: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_27b2:
	/* 0x27b2: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_27b9:
	/* 0x27b9: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_27be:
	/* 0x27be: jmp    27c5 <generic_tracepoint_process_event+0x27c5> */
	goto x86_l_27c5;
x86_l_27c0:
	/* 0x27c0: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_27c5:
	/* 0x27c5: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_27ca:
	/* 0x27ca: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27cf:
	/* 0x27cf: movzx  r15d,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_27d4:
	/* 0x27d4: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_27d8:
	/* 0x27d8: ja     2d68 <generic_tracepoint_process_event+0x2d68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11624ULL;
	}
x86_l_27de:
	/* 0x27de: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_27e8:
	/* 0x27e8: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_27ec:
	/* 0x27ec: jae    2d68 <generic_tracepoint_process_event+0x2d68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11624ULL;
	}
x86_l_27f2:
	/* 0x27f2: mov    BYTE PTR [r13+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_27f6:
	/* 0x27f6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27fb:
	/* 0x27fb: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2800:
	/* 0x2800: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2805:
	/* 0x2805: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_280a:
	/* 0x280a: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_280f:
	/* 0x280f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2811:
	/* 0x2811: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2814:
	/* 0x2814: js     2be3 <generic_tracepoint_process_event+0x2be3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11235ULL;
	}
x86_l_281a:
	/* 0x281a: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_281f:
	/* 0x281f: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2822:
	/* 0x2822: jg     283f <generic_tracepoint_process_event+0x283f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_283f;
	}
x86_l_2824:
	/* 0x2824: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2826:
	/* 0x2826: je     285d <generic_tracepoint_process_event+0x285d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_285d;
	}
x86_l_2828:
	/* 0x2828: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_282b:
	/* 0x282b: je     285d <generic_tracepoint_process_event+0x285d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_285d;
	}
x86_l_282d:
	/* 0x282d: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2830:
	/* 0x2830: jne    2883 <generic_tracepoint_process_event+0x2883> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2883;
	}
x86_l_2832:
	/* 0x2832: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2839:
	/* 0x2839: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_283d:
	/* 0x283d: jmp    2888 <generic_tracepoint_process_event+0x2888> */
	goto x86_l_2888;
x86_l_283f:
	/* 0x283f: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2842:
	/* 0x2842: je     2870 <generic_tracepoint_process_event+0x2870> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2870;
	}
x86_l_2844:
	/* 0x2844: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2847:
	/* 0x2847: je     285d <generic_tracepoint_process_event+0x285d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_285d;
	}
x86_l_2849:
	/* 0x2849: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_284e:
	/* 0x284e: jne    2883 <generic_tracepoint_process_event+0x2883> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2883;
	}
x86_l_2850:
	/* 0x2850: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2857:
	/* 0x2857: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_285b:
	/* 0x285b: jmp    2888 <generic_tracepoint_process_event+0x2888> */
	goto x86_l_2888;
x86_l_285d:
	/* 0x285d: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2862:
	/* 0x2862: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2869:
	/* 0x2869: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_286e:
	/* 0x286e: jmp    2888 <generic_tracepoint_process_event+0x2888> */
	goto x86_l_2888;
x86_l_2870:
	/* 0x2870: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2875:
	/* 0x2875: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_287c:
	/* 0x287c: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2881:
	/* 0x2881: jmp    2888 <generic_tracepoint_process_event+0x2888> */
	goto x86_l_2888;
x86_l_2883:
	/* 0x2883: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2888:
	/* 0x2888: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_288d:
	/* 0x288d: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2892:
	/* 0x2892: movzx  r15d,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2897:
	/* 0x2897: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_289b:
	/* 0x289b: ja     2d68 <generic_tracepoint_process_event+0x2d68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11624ULL;
	}
x86_l_28a1:
	/* 0x28a1: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_28ab:
	/* 0x28ab: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_28af:
	/* 0x28af: jae    2d68 <generic_tracepoint_process_event+0x2d68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11624ULL;
	}
x86_l_28b5:
	/* 0x28b5: mov    BYTE PTR [r13+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_28b9:
	/* 0x28b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28be:
	/* 0x28be: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_28c3:
	/* 0x28c3: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_28c8:
	/* 0x28c8: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28cd:
	/* 0x28cd: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_28d2:
	/* 0x28d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28d4:
	/* 0x28d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28d7:
	/* 0x28d7: js     2be3 <generic_tracepoint_process_event+0x2be3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11235ULL;
	}
x86_l_28dd:
	/* 0x28dd: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_28e2:
	/* 0x28e2: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_28e5:
	/* 0x28e5: jg     2902 <generic_tracepoint_process_event+0x2902> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2902;
	}
x86_l_28e7:
	/* 0x28e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28e9:
	/* 0x28e9: je     2920 <generic_tracepoint_process_event+0x2920> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2920;
	}
x86_l_28eb:
	/* 0x28eb: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_28ee:
	/* 0x28ee: je     2920 <generic_tracepoint_process_event+0x2920> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2920;
	}
x86_l_28f0:
	/* 0x28f0: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_28f3:
	/* 0x28f3: jne    2946 <generic_tracepoint_process_event+0x2946> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2946;
	}
x86_l_28f5:
	/* 0x28f5: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_28fc:
	/* 0x28fc: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2900:
	/* 0x2900: jmp    294b <generic_tracepoint_process_event+0x294b> */
	goto x86_l_294b;
x86_l_2902:
	/* 0x2902: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2905:
	/* 0x2905: je     2933 <generic_tracepoint_process_event+0x2933> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2933;
	}
x86_l_2907:
	/* 0x2907: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_290a:
	/* 0x290a: je     2920 <generic_tracepoint_process_event+0x2920> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2920;
	}
x86_l_290c:
	/* 0x290c: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2911:
	/* 0x2911: jne    2946 <generic_tracepoint_process_event+0x2946> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2946;
	}
x86_l_2913:
	/* 0x2913: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_291a:
	/* 0x291a: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_291e:
	/* 0x291e: jmp    294b <generic_tracepoint_process_event+0x294b> */
	goto x86_l_294b;
x86_l_2920:
	/* 0x2920: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2925:
	/* 0x2925: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_292c:
	/* 0x292c: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2931:
	/* 0x2931: jmp    294b <generic_tracepoint_process_event+0x294b> */
	goto x86_l_294b;
x86_l_2933:
	/* 0x2933: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2938:
	/* 0x2938: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_293f:
	/* 0x293f: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2944:
	/* 0x2944: jmp    294b <generic_tracepoint_process_event+0x294b> */
	goto x86_l_294b;
x86_l_2946:
	/* 0x2946: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_294b:
	/* 0x294b: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2950:
	/* 0x2950: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2955:
	/* 0x2955: movzx  r15d,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_295a:
	/* 0x295a: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_295e:
	/* 0x295e: ja     2d68 <generic_tracepoint_process_event+0x2d68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11624ULL;
	}
x86_l_2964:
	/* 0x2964: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_296e:
	/* 0x296e: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_2972:
	/* 0x2972: jae    2d68 <generic_tracepoint_process_event+0x2d68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11624ULL;
	}
x86_l_2978:
	/* 0x2978: mov    BYTE PTR [r13+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_297c:
	/* 0x297c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2981:
	/* 0x2981: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2986:
	/* 0x2986: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_298b:
	/* 0x298b: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2990:
	/* 0x2990: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2995:
	/* 0x2995: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2997:
	/* 0x2997: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_299a:
	/* 0x299a: js     2be3 <generic_tracepoint_process_event+0x2be3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11235ULL;
	}
x86_l_29a0:
	/* 0x29a0: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_29a5:
	/* 0x29a5: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_29a8:
	/* 0x29a8: jg     29c5 <generic_tracepoint_process_event+0x29c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10693ULL;
	}
x86_l_29aa:
	/* 0x29aa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29ac:
	/* 0x29ac: je     29e3 <generic_tracepoint_process_event+0x29e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10723ULL;
	}
x86_l_29ae:
	/* 0x29ae: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_29b1:
	/* 0x29b1: je     29e3 <generic_tracepoint_process_event+0x29e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10723ULL;
	}
x86_l_29b3:
	/* 0x29b3: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_29b6:
	/* 0x29b6: jne    2a09 <generic_tracepoint_process_event+0x2a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10761ULL;
	}
x86_l_29b8:
	/* 0x29b8: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
	return 10687ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_process_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10687ULL: goto x86_l_29bf;
	case 10691ULL: goto x86_l_29c3;
	case 10693ULL: goto x86_l_29c5;
	case 10696ULL: goto x86_l_29c8;
	case 10698ULL: goto x86_l_29ca;
	case 10701ULL: goto x86_l_29cd;
	case 10703ULL: goto x86_l_29cf;
	case 10708ULL: goto x86_l_29d4;
	case 10710ULL: goto x86_l_29d6;
	case 10717ULL: goto x86_l_29dd;
	case 10721ULL: goto x86_l_29e1;
	case 10723ULL: goto x86_l_29e3;
	case 10728ULL: goto x86_l_29e8;
	case 10735ULL: goto x86_l_29ef;
	case 10740ULL: goto x86_l_29f4;
	case 10742ULL: goto x86_l_29f6;
	case 10747ULL: goto x86_l_29fb;
	case 10754ULL: goto x86_l_2a02;
	case 10759ULL: goto x86_l_2a07;
	case 10761ULL: goto x86_l_2a09;
	case 10766ULL: goto x86_l_2a0e;
	case 10771ULL: goto x86_l_2a13;
	case 10776ULL: goto x86_l_2a18;
	case 10781ULL: goto x86_l_2a1d;
	case 10785ULL: goto x86_l_2a21;
	case 10791ULL: goto x86_l_2a27;
	case 10801ULL: goto x86_l_2a31;
	case 10805ULL: goto x86_l_2a35;
	case 10811ULL: goto x86_l_2a3b;
	case 10815ULL: goto x86_l_2a3f;
	case 10820ULL: goto x86_l_2a44;
	case 10825ULL: goto x86_l_2a49;
	case 10830ULL: goto x86_l_2a4e;
	case 10835ULL: goto x86_l_2a53;
	case 10840ULL: goto x86_l_2a58;
	case 10842ULL: goto x86_l_2a5a;
	case 10845ULL: goto x86_l_2a5d;
	case 10851ULL: goto x86_l_2a63;
	case 10856ULL: goto x86_l_2a68;
	case 10859ULL: goto x86_l_2a6b;
	case 10861ULL: goto x86_l_2a6d;
	case 10863ULL: goto x86_l_2a6f;
	case 10865ULL: goto x86_l_2a71;
	case 10868ULL: goto x86_l_2a74;
	case 10870ULL: goto x86_l_2a76;
	case 10873ULL: goto x86_l_2a79;
	case 10875ULL: goto x86_l_2a7b;
	case 10882ULL: goto x86_l_2a82;
	case 10886ULL: goto x86_l_2a86;
	case 10888ULL: goto x86_l_2a88;
	case 10891ULL: goto x86_l_2a8b;
	case 10893ULL: goto x86_l_2a8d;
	case 10896ULL: goto x86_l_2a90;
	case 10898ULL: goto x86_l_2a92;
	case 10903ULL: goto x86_l_2a97;
	case 10905ULL: goto x86_l_2a99;
	case 10912ULL: goto x86_l_2aa0;
	case 10916ULL: goto x86_l_2aa4;
	case 10918ULL: goto x86_l_2aa6;
	case 10923ULL: goto x86_l_2aab;
	case 10930ULL: goto x86_l_2ab2;
	case 10935ULL: goto x86_l_2ab7;
	case 10937ULL: goto x86_l_2ab9;
	case 10942ULL: goto x86_l_2abe;
	case 10949ULL: goto x86_l_2ac5;
	case 10954ULL: goto x86_l_2aca;
	case 10956ULL: goto x86_l_2acc;
	case 10961ULL: goto x86_l_2ad1;
	case 10966ULL: goto x86_l_2ad6;
	case 10971ULL: goto x86_l_2adb;
	case 10976ULL: goto x86_l_2ae0;
	case 10980ULL: goto x86_l_2ae4;
	case 10986ULL: goto x86_l_2aea;
	case 10996ULL: goto x86_l_2af4;
	case 11000ULL: goto x86_l_2af8;
	case 11006ULL: goto x86_l_2afe;
	case 11010ULL: goto x86_l_2b02;
	case 11015ULL: goto x86_l_2b07;
	case 11020ULL: goto x86_l_2b0c;
	case 11025ULL: goto x86_l_2b11;
	case 11030ULL: goto x86_l_2b16;
	case 11035ULL: goto x86_l_2b1b;
	case 11037ULL: goto x86_l_2b1d;
	case 11040ULL: goto x86_l_2b20;
	case 11046ULL: goto x86_l_2b26;
	case 11051ULL: goto x86_l_2b2b;
	case 11054ULL: goto x86_l_2b2e;
	case 11056ULL: goto x86_l_2b30;
	case 11058ULL: goto x86_l_2b32;
	case 11060ULL: goto x86_l_2b34;
	case 11063ULL: goto x86_l_2b37;
	case 11065ULL: goto x86_l_2b39;
	case 11068ULL: goto x86_l_2b3c;
	case 11070ULL: goto x86_l_2b3e;
	case 11077ULL: goto x86_l_2b45;
	case 11081ULL: goto x86_l_2b49;
	case 11083ULL: goto x86_l_2b4b;
	case 11086ULL: goto x86_l_2b4e;
	case 11088ULL: goto x86_l_2b50;
	case 11091ULL: goto x86_l_2b53;
	case 11093ULL: goto x86_l_2b55;
	case 11098ULL: goto x86_l_2b5a;
	case 11100ULL: goto x86_l_2b5c;
	case 11107ULL: goto x86_l_2b63;
	case 11111ULL: goto x86_l_2b67;
	case 11113ULL: goto x86_l_2b69;
	case 11118ULL: goto x86_l_2b6e;
	case 11125ULL: goto x86_l_2b75;
	case 11130ULL: goto x86_l_2b7a;
	case 11132ULL: goto x86_l_2b7c;
	case 11137ULL: goto x86_l_2b81;
	case 11144ULL: goto x86_l_2b88;
	case 11149ULL: goto x86_l_2b8d;
	case 11151ULL: goto x86_l_2b8f;
	case 11156ULL: goto x86_l_2b94;
	case 11161ULL: goto x86_l_2b99;
	case 11166ULL: goto x86_l_2b9e;
	case 11171ULL: goto x86_l_2ba3;
	case 11175ULL: goto x86_l_2ba7;
	case 11181ULL: goto x86_l_2bad;
	case 11191ULL: goto x86_l_2bb7;
	case 11195ULL: goto x86_l_2bbb;
	case 11201ULL: goto x86_l_2bc1;
	case 11205ULL: goto x86_l_2bc5;
	case 11210ULL: goto x86_l_2bca;
	case 11215ULL: goto x86_l_2bcf;
	case 11220ULL: goto x86_l_2bd4;
	case 11223ULL: goto x86_l_2bd7;
	case 11228ULL: goto x86_l_2bdc;
	case 11233ULL: goto x86_l_2be1;
	case 11235ULL: goto x86_l_2be3;
	case 11238ULL: goto x86_l_2be6;
	case 11246ULL: goto x86_l_2bee;
	case 11250ULL: goto x86_l_2bf2;
	case 11254ULL: goto x86_l_2bf6;
	case 11259ULL: goto x86_l_2bfb;
	case 11266ULL: goto x86_l_2c02;
	case 11270ULL: goto x86_l_2c06;
	case 11275ULL: goto x86_l_2c0b;
	case 11278ULL: goto x86_l_2c0e;
	case 11283ULL: goto x86_l_2c13;
	case 11285ULL: goto x86_l_2c15;
	case 11289ULL: goto x86_l_2c19;
	case 11293ULL: goto x86_l_2c1d;
	case 11298ULL: goto x86_l_2c22;
	case 11303ULL: goto x86_l_2c27;
	case 11306ULL: goto x86_l_2c2a;
	case 11308ULL: goto x86_l_2c2c;
	case 11312ULL: goto x86_l_2c30;
	case 11314ULL: goto x86_l_2c32;
	case 11318ULL: goto x86_l_2c36;
	case 11321ULL: goto x86_l_2c39;
	case 11323ULL: goto x86_l_2c3b;
	case 11328ULL: goto x86_l_2c40;
	case 11337ULL: goto x86_l_2c49;
	case 11341ULL: goto x86_l_2c4d;
	case 11345ULL: goto x86_l_2c51;
	case 11349ULL: goto x86_l_2c55;
	case 11354ULL: goto x86_l_2c5a;
	case 11359ULL: goto x86_l_2c5f;
	case 11361ULL: goto x86_l_2c61;
	case 11365ULL: goto x86_l_2c65;
	case 11369ULL: goto x86_l_2c69;
	case 11373ULL: goto x86_l_2c6d;
	case 11378ULL: goto x86_l_2c72;
	case 11380ULL: goto x86_l_2c74;
	case 11385ULL: goto x86_l_2c79;
	case 11394ULL: goto x86_l_2c82;
	case 11398ULL: goto x86_l_2c86;
	case 11402ULL: goto x86_l_2c8a;
	case 11406ULL: goto x86_l_2c8e;
	case 11411ULL: goto x86_l_2c93;
	case 11416ULL: goto x86_l_2c98;
	case 11418ULL: goto x86_l_2c9a;
	case 11422ULL: goto x86_l_2c9e;
	case 11426ULL: goto x86_l_2ca2;
	case 11430ULL: goto x86_l_2ca6;
	case 11435ULL: goto x86_l_2cab;
	case 11440ULL: goto x86_l_2cb0;
	case 11442ULL: goto x86_l_2cb2;
	case 11444ULL: goto x86_l_2cb4;
	case 11448ULL: goto x86_l_2cb8;
	case 11455ULL: goto x86_l_2cbf;
	case 11459ULL: goto x86_l_2cc3;
	case 11463ULL: goto x86_l_2cc7;
	case 11467ULL: goto x86_l_2ccb;
	case 11473ULL: goto x86_l_2cd1;
	case 11479ULL: goto x86_l_2cd7;
	case 11486ULL: goto x86_l_2cde;
	case 11491ULL: goto x86_l_2ce3;
	case 11499ULL: goto x86_l_2ceb;
	case 11504ULL: goto x86_l_2cf0;
	case 11507ULL: goto x86_l_2cf3;
	case 11509ULL: goto x86_l_2cf5;
	case 11518ULL: goto x86_l_2cfe;
	case 11520ULL: goto x86_l_2d00;
	case 11525ULL: goto x86_l_2d05;
	case 11533ULL: goto x86_l_2d0d;
	case 11537ULL: goto x86_l_2d11;
	case 11542ULL: goto x86_l_2d16;
	case 11547ULL: goto x86_l_2d1b;
	case 11549ULL: goto x86_l_2d1d;
	case 11557ULL: goto x86_l_2d25;
	case 11562ULL: goto x86_l_2d2a;
	case 11566ULL: goto x86_l_2d2e;
	case 11570ULL: goto x86_l_2d32;
	case 11574ULL: goto x86_l_2d36;
	case 11579ULL: goto x86_l_2d3b;
	case 11584ULL: goto x86_l_2d40;
	case 11586ULL: goto x86_l_2d42;
	case 11590ULL: goto x86_l_2d46;
	case 11594ULL: goto x86_l_2d4a;
	case 11598ULL: goto x86_l_2d4e;
	case 11603ULL: goto x86_l_2d53;
	case 11606ULL: goto x86_l_2d56;
	case 11611ULL: goto x86_l_2d5b;
	case 11613ULL: goto x86_l_2d5d;
	case 11619ULL: goto x86_l_2d63;
	case 11624ULL: goto x86_l_2d68;
	case 11632ULL: goto x86_l_2d70;
	case 11637ULL: goto x86_l_2d75;
	case 11642ULL: goto x86_l_2d7a;
	case 11645ULL: goto x86_l_2d7d;
	case 11647ULL: goto x86_l_2d7f;
	case 11649ULL: goto x86_l_2d81;
	case 11650ULL: goto x86_l_2d82;
	case 11651ULL: goto x86_l_2d83;
	case 11654ULL: goto x86_l_2d86;
	case 11656ULL: goto x86_l_2d88;
	case 11662ULL: goto x86_l_2d8e;
	case 11664ULL: goto x86_l_2d90;
	case 11668ULL: goto x86_l_2d94;
	case 11672ULL: goto x86_l_2d98;
	case 11675ULL: goto x86_l_2d9b;
	case 11677ULL: goto x86_l_2d9d;
	case 11683ULL: goto x86_l_2da3;
	case 11685ULL: goto x86_l_2da5;
	case 11687ULL: goto x86_l_2da7;
	case 11691ULL: goto x86_l_2dab;
	case 11693ULL: goto x86_l_2dad;
	case 11698ULL: goto x86_l_2db2;
	case 11700ULL: goto x86_l_2db4;
	case 11705ULL: goto x86_l_2db9;
	case 11708ULL: goto x86_l_2dbc;
	case 11712ULL: goto x86_l_2dc0;
	case 11715ULL: goto x86_l_2dc3;
	case 11720ULL: goto x86_l_2dc8;
	case 11722ULL: goto x86_l_2dca;
	case 11724ULL: goto x86_l_2dcc;
	case 11729ULL: goto x86_l_2dd1;
	case 11731ULL: goto x86_l_2dd3;
	case 11733ULL: goto x86_l_2dd5;
	case 11737ULL: goto x86_l_2dd9;
	case 11739ULL: goto x86_l_2ddb;
	case 11744ULL: goto x86_l_2de0;
	case 11748ULL: goto x86_l_2de4;
	case 11749ULL: goto x86_l_2de5;
	case 11751ULL: goto x86_l_2de7;
	case 11752ULL: goto x86_l_2de8;
	case 11754ULL: goto x86_l_2dea;
	case 11756ULL: goto x86_l_2dec;
	case 11758ULL: goto x86_l_2dee;
	case 11759ULL: goto x86_l_2def;
	case 11763ULL: goto x86_l_2df3;
	case 11766ULL: goto x86_l_2df6;
	case 11770ULL: goto x86_l_2dfa;
	case 11774ULL: goto x86_l_2dfe;
	case 11778ULL: goto x86_l_2e02;
	case 11781ULL: goto x86_l_2e05;
	case 11783ULL: goto x86_l_2e07;
	case 11787ULL: goto x86_l_2e0b;
	case 11793ULL: goto x86_l_2e11;
	case 11798ULL: goto x86_l_2e16;
	case 11803ULL: goto x86_l_2e1b;
	case 11808ULL: goto x86_l_2e20;
	case 11810ULL: goto x86_l_2e22;
	case 11815ULL: goto x86_l_2e27;
	case 11821ULL: goto x86_l_2e2d;
	case 11825ULL: goto x86_l_2e31;
	case 11830ULL: goto x86_l_2e36;
	case 11835ULL: goto x86_l_2e3b;
	case 11840ULL: goto x86_l_2e40;
	case 11843ULL: goto x86_l_2e43;
	case 11845ULL: goto x86_l_2e45;
	case 11850ULL: goto x86_l_2e4a;
	case 11856ULL: goto x86_l_2e50;
	case 11861ULL: goto x86_l_2e55;
	case 11866ULL: goto x86_l_2e5a;
	case 11871ULL: goto x86_l_2e5f;
	case 11874ULL: goto x86_l_2e62;
	case 11876ULL: goto x86_l_2e64;
	case 11880ULL: goto x86_l_2e68;
	case 11885ULL: goto x86_l_2e6d;
	case 11890ULL: goto x86_l_2e72;
	case 11895ULL: goto x86_l_2e77;
	case 11898ULL: goto x86_l_2e7a;
	case 11900ULL: goto x86_l_2e7c;
	case 11904ULL: goto x86_l_2e80;
	case 11908ULL: goto x86_l_2e84;
	case 11912ULL: goto x86_l_2e88;
	case 11915ULL: goto x86_l_2e8b;
	case 11918ULL: goto x86_l_2e8e;
	case 11920ULL: goto x86_l_2e90;
	case 11922ULL: goto x86_l_2e92;
	case 11924ULL: goto x86_l_2e94;
	case 11927ULL: goto x86_l_2e97;
	case 11932ULL: goto x86_l_2e9c;
	case 11935ULL: goto x86_l_2e9f;
	case 11937ULL: goto x86_l_2ea1;
	case 11941ULL: goto x86_l_2ea5;
	case 11944ULL: goto x86_l_2ea8;
	case 11948ULL: goto x86_l_2eac;
	case 11951ULL: goto x86_l_2eaf;
	case 11953ULL: goto x86_l_2eb1;
	case 11956ULL: goto x86_l_2eb4;
	case 11959ULL: goto x86_l_2eb7;
	case 11964ULL: goto x86_l_2ebc;
	case 11967ULL: goto x86_l_2ebf;
	case 11973ULL: goto x86_l_2ec5;
	case 11980ULL: goto x86_l_2ecc;
	case 11986ULL: goto x86_l_2ed2;
	case 11988ULL: goto x86_l_2ed4;
	case 11994ULL: goto x86_l_2eda;
	case 11998ULL: goto x86_l_2ede;
	case 12003ULL: goto x86_l_2ee3;
	case 12007ULL: goto x86_l_2ee7;
	case 12011ULL: goto x86_l_2eeb;
	case 12014ULL: goto x86_l_2eee;
	case 12019ULL: goto x86_l_2ef3;
	case 12021ULL: goto x86_l_2ef5;
	case 12025ULL: goto x86_l_2ef9;
	case 12030ULL: goto x86_l_2efe;
	case 12034ULL: goto x86_l_2f02;
	case 12036ULL: goto x86_l_2f04;
	case 12038ULL: goto x86_l_2f06;
	case 12042ULL: goto x86_l_2f0a;
	case 12047ULL: goto x86_l_2f0f;
	case 12052ULL: goto x86_l_2f14;
	case 12057ULL: goto x86_l_2f19;
	case 12059ULL: goto x86_l_2f1b;
	case 12063ULL: goto x86_l_2f1f;
	case 12068ULL: goto x86_l_2f24;
	case 12070ULL: goto x86_l_2f26;
	case 12074ULL: goto x86_l_2f2a;
	case 12078ULL: goto x86_l_2f2e;
	case 12083ULL: goto x86_l_2f33;
	case 12088ULL: goto x86_l_2f38;
	case 12091ULL: goto x86_l_2f3b;
	case 12093ULL: goto x86_l_2f3d;
	case 12098ULL: goto x86_l_2f42;
	case 12102ULL: goto x86_l_2f46;
	case 12106ULL: goto x86_l_2f4a;
	case 12110ULL: goto x86_l_2f4e;
	case 12112ULL: goto x86_l_2f50;
	case 12114ULL: goto x86_l_2f52;
	case 12118ULL: goto x86_l_2f56;
	case 12123ULL: goto x86_l_2f5b;
	case 12127ULL: goto x86_l_2f5f;
	case 12128ULL: goto x86_l_2f60;
	case 12130ULL: goto x86_l_2f62;
	case 12132ULL: goto x86_l_2f64;
	case 12134ULL: goto x86_l_2f66;
	case 12135ULL: goto x86_l_2f67;
	case 12139ULL: goto x86_l_2f6b;
	case 12142ULL: goto x86_l_2f6e;
	case 12147ULL: goto x86_l_2f73;
	case 12150ULL: goto x86_l_2f76;
	case 12152ULL: goto x86_l_2f78;
	case 12157ULL: goto x86_l_2f7d;
	case 12161ULL: goto x86_l_2f81;
	default: return 0xffffffffffffffffULL;
	}
x86_l_29bf:
	/* 0x29bf: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_29c3:
	/* 0x29c3: jmp    2a0e <generic_tracepoint_process_event+0x2a0e> */
	goto x86_l_2a0e;
x86_l_29c5:
	/* 0x29c5: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_29c8:
	/* 0x29c8: je     29f6 <generic_tracepoint_process_event+0x29f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29f6;
	}
x86_l_29ca:
	/* 0x29ca: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_29cd:
	/* 0x29cd: je     29e3 <generic_tracepoint_process_event+0x29e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29e3;
	}
x86_l_29cf:
	/* 0x29cf: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_29d4:
	/* 0x29d4: jne    2a09 <generic_tracepoint_process_event+0x2a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a09;
	}
x86_l_29d6:
	/* 0x29d6: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_29dd:
	/* 0x29dd: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_29e1:
	/* 0x29e1: jmp    2a0e <generic_tracepoint_process_event+0x2a0e> */
	goto x86_l_2a0e;
x86_l_29e3:
	/* 0x29e3: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_29e8:
	/* 0x29e8: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_29ef:
	/* 0x29ef: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_29f4:
	/* 0x29f4: jmp    2a0e <generic_tracepoint_process_event+0x2a0e> */
	goto x86_l_2a0e;
x86_l_29f6:
	/* 0x29f6: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_29fb:
	/* 0x29fb: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2a02:
	/* 0x2a02: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2a07:
	/* 0x2a07: jmp    2a0e <generic_tracepoint_process_event+0x2a0e> */
	goto x86_l_2a0e;
x86_l_2a09:
	/* 0x2a09: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2a0e:
	/* 0x2a0e: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a13:
	/* 0x2a13: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a18:
	/* 0x2a18: movzx  r15d,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2a1d:
	/* 0x2a1d: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_2a21:
	/* 0x2a21: ja     2d68 <generic_tracepoint_process_event+0x2d68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2d68;
	}
x86_l_2a27:
	/* 0x2a27: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2a31:
	/* 0x2a31: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_2a35:
	/* 0x2a35: jae    2d68 <generic_tracepoint_process_event+0x2d68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2d68;
	}
x86_l_2a3b:
	/* 0x2a3b: mov    BYTE PTR [r13+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2a3f:
	/* 0x2a3f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a44:
	/* 0x2a44: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a49:
	/* 0x2a49: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2a4e:
	/* 0x2a4e: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a53:
	/* 0x2a53: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2a58:
	/* 0x2a58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a5a:
	/* 0x2a5a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a5d:
	/* 0x2a5d: js     2be3 <generic_tracepoint_process_event+0x2be3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2be3;
	}
x86_l_2a63:
	/* 0x2a63: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2a68:
	/* 0x2a68: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2a6b:
	/* 0x2a6b: jg     2a88 <generic_tracepoint_process_event+0x2a88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2a88;
	}
x86_l_2a6d:
	/* 0x2a6d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a6f:
	/* 0x2a6f: je     2aa6 <generic_tracepoint_process_event+0x2aa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aa6;
	}
x86_l_2a71:
	/* 0x2a71: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2a74:
	/* 0x2a74: je     2aa6 <generic_tracepoint_process_event+0x2aa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aa6;
	}
x86_l_2a76:
	/* 0x2a76: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2a79:
	/* 0x2a79: jne    2acc <generic_tracepoint_process_event+0x2acc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2acc;
	}
x86_l_2a7b:
	/* 0x2a7b: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2a82:
	/* 0x2a82: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2a86:
	/* 0x2a86: jmp    2ad1 <generic_tracepoint_process_event+0x2ad1> */
	goto x86_l_2ad1;
x86_l_2a88:
	/* 0x2a88: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2a8b:
	/* 0x2a8b: je     2ab9 <generic_tracepoint_process_event+0x2ab9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ab9;
	}
x86_l_2a8d:
	/* 0x2a8d: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2a90:
	/* 0x2a90: je     2aa6 <generic_tracepoint_process_event+0x2aa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aa6;
	}
x86_l_2a92:
	/* 0x2a92: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2a97:
	/* 0x2a97: jne    2acc <generic_tracepoint_process_event+0x2acc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2acc;
	}
x86_l_2a99:
	/* 0x2a99: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2aa0:
	/* 0x2aa0: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2aa4:
	/* 0x2aa4: jmp    2ad1 <generic_tracepoint_process_event+0x2ad1> */
	goto x86_l_2ad1;
x86_l_2aa6:
	/* 0x2aa6: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2aab:
	/* 0x2aab: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2ab2:
	/* 0x2ab2: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2ab7:
	/* 0x2ab7: jmp    2ad1 <generic_tracepoint_process_event+0x2ad1> */
	goto x86_l_2ad1;
x86_l_2ab9:
	/* 0x2ab9: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2abe:
	/* 0x2abe: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2ac5:
	/* 0x2ac5: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2aca:
	/* 0x2aca: jmp    2ad1 <generic_tracepoint_process_event+0x2ad1> */
	goto x86_l_2ad1;
x86_l_2acc:
	/* 0x2acc: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2ad1:
	/* 0x2ad1: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2ad6:
	/* 0x2ad6: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2adb:
	/* 0x2adb: movzx  r15d,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2ae0:
	/* 0x2ae0: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_2ae4:
	/* 0x2ae4: ja     2d68 <generic_tracepoint_process_event+0x2d68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2d68;
	}
x86_l_2aea:
	/* 0x2aea: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2af4:
	/* 0x2af4: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_2af8:
	/* 0x2af8: jae    2d68 <generic_tracepoint_process_event+0x2d68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2d68;
	}
x86_l_2afe:
	/* 0x2afe: mov    BYTE PTR [r13+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2b02:
	/* 0x2b02: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b07:
	/* 0x2b07: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b0c:
	/* 0x2b0c: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2b11:
	/* 0x2b11: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b16:
	/* 0x2b16: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2b1b:
	/* 0x2b1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b1d:
	/* 0x2b1d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b20:
	/* 0x2b20: js     2be3 <generic_tracepoint_process_event+0x2be3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2be3;
	}
x86_l_2b26:
	/* 0x2b26: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2b2b:
	/* 0x2b2b: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2b2e:
	/* 0x2b2e: jg     2b4b <generic_tracepoint_process_event+0x2b4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2b4b;
	}
x86_l_2b30:
	/* 0x2b30: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b32:
	/* 0x2b32: je     2b69 <generic_tracepoint_process_event+0x2b69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b69;
	}
x86_l_2b34:
	/* 0x2b34: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2b37:
	/* 0x2b37: je     2b69 <generic_tracepoint_process_event+0x2b69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b69;
	}
x86_l_2b39:
	/* 0x2b39: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2b3c:
	/* 0x2b3c: jne    2b8f <generic_tracepoint_process_event+0x2b8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b8f;
	}
x86_l_2b3e:
	/* 0x2b3e: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2b45:
	/* 0x2b45: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2b49:
	/* 0x2b49: jmp    2b94 <generic_tracepoint_process_event+0x2b94> */
	goto x86_l_2b94;
x86_l_2b4b:
	/* 0x2b4b: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2b4e:
	/* 0x2b4e: je     2b7c <generic_tracepoint_process_event+0x2b7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b7c;
	}
x86_l_2b50:
	/* 0x2b50: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2b53:
	/* 0x2b53: je     2b69 <generic_tracepoint_process_event+0x2b69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b69;
	}
x86_l_2b55:
	/* 0x2b55: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2b5a:
	/* 0x2b5a: jne    2b8f <generic_tracepoint_process_event+0x2b8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b8f;
	}
x86_l_2b5c:
	/* 0x2b5c: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2b63:
	/* 0x2b63: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2b67:
	/* 0x2b67: jmp    2b94 <generic_tracepoint_process_event+0x2b94> */
	goto x86_l_2b94;
x86_l_2b69:
	/* 0x2b69: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2b6e:
	/* 0x2b6e: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2b75:
	/* 0x2b75: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2b7a:
	/* 0x2b7a: jmp    2b94 <generic_tracepoint_process_event+0x2b94> */
	goto x86_l_2b94;
x86_l_2b7c:
	/* 0x2b7c: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2b81:
	/* 0x2b81: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2b88:
	/* 0x2b88: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2b8d:
	/* 0x2b8d: jmp    2b94 <generic_tracepoint_process_event+0x2b94> */
	goto x86_l_2b94;
x86_l_2b8f:
	/* 0x2b8f: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2b94:
	/* 0x2b94: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b99:
	/* 0x2b99: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b9e:
	/* 0x2b9e: movzx  r15d,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2ba3:
	/* 0x2ba3: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_2ba7:
	/* 0x2ba7: ja     2d68 <generic_tracepoint_process_event+0x2d68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2d68;
	}
x86_l_2bad:
	/* 0x2bad: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2bb7:
	/* 0x2bb7: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_2bbb:
	/* 0x2bbb: jae    2d68 <generic_tracepoint_process_event+0x2d68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2d68;
	}
x86_l_2bc1:
	/* 0x2bc1: mov    BYTE PTR [r13+0x5],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2bc5:
	/* 0x2bc5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bca:
	/* 0x2bca: movzx  ecx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2bcf:
	/* 0x2bcf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bd4:
	/* 0x2bd4: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2bd7:
	/* 0x2bd7: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2bdc:
	/* 0x2bdc: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2be1:
	/* 0x2be1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2be3:
	/* 0x2be3: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2be6:
	/* 0x2be6: mov    BYTE PTR [rsp+0xa4],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_2bee:
	/* 0x2bee: movzx  eax,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2bf2:
	/* 0x2bf2: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bf6:
	/* 0x2bf6: mov    WORD PTR [r13+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2bfb:
	/* 0x2bfb: mov    WORD PTR [r13+0x26],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757258ULL);
x86_l_2c02:
	/* 0x2c02: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c06:
	/* 0x2c06: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c0b:
	/* 0x2c0b: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2c0e:
	/* 0x2c0e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2c13:
	/* 0x2c13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c15:
	/* 0x2c15: lea    rdi,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c19:
	/* 0x2c19: add    rbp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2c1d:
	/* 0x2c1d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c22:
	/* 0x2c22: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2c27:
	/* 0x2c27: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2c2a:
	/* 0x2c2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c2c:
	/* 0x2c2c: cmp    r15b,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 17ULL);
x86_l_2c30:
	/* 0x2c30: je     2c74 <generic_tracepoint_process_event+0x2c74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c74;
	}
x86_l_2c32:
	/* 0x2c32: movzx  eax,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2c36:
	/* 0x2c36: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2c39:
	/* 0x2c39: jne    2cb4 <generic_tracepoint_process_event+0x2cb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cb4;
	}
x86_l_2c3b:
	/* 0x2c3b: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c40:
	/* 0x2c40: movzx  r13d,WORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 192ULL);
x86_l_2c49:
	/* 0x2c49: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2c4d:
	/* 0x2c4d: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c51:
	/* 0x2c51: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c55:
	/* 0x2c55: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c5a:
	/* 0x2c5a: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2c5f:
	/* 0x2c5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c61:
	/* 0x2c61: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2c65:
	/* 0x2c65: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2c69:
	/* 0x2c69: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2c6d:
	/* 0x2c6d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c72:
	/* 0x2c72: jmp    2cab <generic_tracepoint_process_event+0x2cab> */
	goto x86_l_2cab;
x86_l_2c74:
	/* 0x2c74: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c79:
	/* 0x2c79: movzx  r13d,WORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 192ULL);
x86_l_2c82:
	/* 0x2c82: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2c86:
	/* 0x2c86: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c8a:
	/* 0x2c8a: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c8e:
	/* 0x2c8e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c93:
	/* 0x2c93: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2c98:
	/* 0x2c98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c9a:
	/* 0x2c9a: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2c9e:
	/* 0x2c9e: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2ca2:
	/* 0x2ca2: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2ca6:
	/* 0x2ca6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cab:
	/* 0x2cab: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2cb0:
	/* 0x2cb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cb2:
	/* 0x2cb2: jmp    2cbf <generic_tracepoint_process_event+0x2cbf> */
	goto x86_l_2cbf;
x86_l_2cb4:
	/* 0x2cb4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cb8:
	/* 0x2cb8: mov    DWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2cbf:
	/* 0x2cbf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cc3:
	/* 0x2cc3: movzx  eax,WORD PTR [rdx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_2cc7:
	/* 0x2cc7: movzx  ecx,WORD PTR [rdx+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2ccb:
	/* 0x2ccb: movbe  WORD PTR [rdx+0x20],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_2cd1:
	/* 0x2cd1: movbe  WORD PTR [rdx+0x22],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2cd7:
	/* 0x2cd7: add    r12,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_2cde:
	/* 0x2cde: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ce3:
	/* 0x2ce3: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2ceb:
	/* 0x2ceb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cf0:
	/* 0x2cf0: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2cf3:
	/* 0x2cf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cf5:
	/* 0x2cf5: cmp    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_2cfe:
	/* 0x2cfe: je     2d5d <generic_tracepoint_process_event+0x2d5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d5d;
	}
x86_l_2d00:
	/* 0x2d00: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d05:
	/* 0x2d05: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2d0d:
	/* 0x2d0d: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_2d11:
	/* 0x2d11: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d16:
	/* 0x2d16: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d1b:
	/* 0x2d1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d1d:
	/* 0x2d1d: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2d25:
	/* 0x2d25: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d2a:
	/* 0x2d2a: lea    rdx,[r15+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_2d2e:
	/* 0x2d2e: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d32:
	/* 0x2d32: lea    rdi,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d36:
	/* 0x2d36: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d3b:
	/* 0x2d3b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d40:
	/* 0x2d40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d42:
	/* 0x2d42: add    r13,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 60ULL);
x86_l_2d46:
	/* 0x2d46: lea    rdx,[r15+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_2d4a:
	/* 0x2d4a: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2d4e:
	/* 0x2d4e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d53:
	/* 0x2d53: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2d56:
	/* 0x2d56: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d5b:
	/* 0x2d5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d5d:
	/* 0x2d5d: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_2d63:
	/* 0x2d63: jmp    b78 <generic_tracepoint_process_event+0xb78> */
	return 2936ULL;
x86_l_2d68:
	/* 0x2d68: mov    WORD PTR [rsp+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2d70:
	/* 0x2d70: jmp    2be6 <generic_tracepoint_process_event+0x2be6> */
	goto x86_l_2be6;
x86_l_2d75:
	/* 0x2d75: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d7a:
	/* 0x2d7a: cmp    edi,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 9ULL);
x86_l_2d7d:
	/* 0x2d7d: ja     2de7 <extract_arg_depth+0x72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2de7;
	}
x86_l_2d7f:
	/* 0x2d7f: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2d81:
	/* 0x2d81: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2d82:
	/* 0x2d82: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_2d83:
	/* 0x2d83: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d86:
	/* 0x2d86: mov    edx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_2d88:
	/* 0x2d88: cmp    WORD PTR [rcx+rdx*8+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RDX, 3), 25769803776ULL);
x86_l_2d8e:
	/* 0x2d8e: je     2de0 <extract_arg_depth+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2de0;
	}
x86_l_2d90:
	/* 0x2d90: mov    rax,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d94:
	/* 0x2d94: mov    r8d,DWORD PTR [rcx+rdx*8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_2d98:
	/* 0x2d98: add    QWORD PTR [rax],r8 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R8, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2d9b:
	/* 0x2d9b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d9d:
	/* 0x2d9d: cmp    WORD PTR [rcx+rdx*8+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RDX, 3), 17179869184ULL);
x86_l_2da3:
	/* 0x2da3: je     2de0 <extract_arg_depth+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2de0;
	}
x86_l_2da5:
	/* 0x2da5: mov    ebx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_32);
x86_l_2da7:
	/* 0x2da7: cmp    BYTE PTR [rsi+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2dab:
	/* 0x2dab: je     2db4 <extract_arg_depth+0x3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2db4;
	}
x86_l_2dad:
	/* 0x2dad: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2db2:
	/* 0x2db2: jmp    2db9 <extract_arg_depth+0x44> */
	goto x86_l_2db9;
x86_l_2db4:
	/* 0x2db4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2db9:
	/* 0x2db9: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_2dbc:
	/* 0x2dbc: mov    rdi,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dc0:
	/* 0x2dc0: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dc3:
	/* 0x2dc3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dc8:
	/* 0x2dc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dca:
	/* 0x2dca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2dcc:
	/* 0x2dcc: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_2dd1:
	/* 0x2dd1: jns    2de0 <extract_arg_depth+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_2de0;
	}
x86_l_2dd3:
	/* 0x2dd3: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2dd5:
	/* 0x2dd5: mov    rax,QWORD PTR [r14+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2dd9:
	/* 0x2dd9: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ddb:
	/* 0x2ddb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2de0:
	/* 0x2de0: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2de4:
	/* 0x2de4: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2de5:
	/* 0x2de5: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2de7:
	/* 0x2de7: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2de8:
	/* 0x2de8: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2dea:
	/* 0x2dea: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2dec:
	/* 0x2dec: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2dee:
	/* 0x2dee: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2def:
	/* 0x2def: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_2df3:
	/* 0x2df3: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_2df6:
	/* 0x2df6: mov    r15,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2dfa:
	/* 0x2dfa: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2dfe:
	/* 0x2dfe: mov    r14,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e02:
	/* 0x2e02: cmp    r15,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2e05:
	/* 0x2e05: jne    2e11 <cwd_read_v61+0x29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e11;
	}
x86_l_2e07:
	/* 0x2e07: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2e0b:
	/* 0x2e0b: je     2f52 <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f52;
	}
x86_l_2e11:
	/* 0x2e11: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e16:
	/* 0x2e16: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e1b:
	/* 0x2e1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e20:
	/* 0x2e20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e22:
	/* 0x2e22: cmp    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2e27:
	/* 0x2e27: je     2f06 <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f06;
	}
x86_l_2e2d:
	/* 0x2e2d: lea    r12,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e31:
	/* 0x2e31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e36:
	/* 0x2e36: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e3b:
	/* 0x2e3b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e40:
	/* 0x2e40: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2e43:
	/* 0x2e43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e45:
	/* 0x2e45: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e4a:
	/* 0x2e4a: je     2f06 <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f06;
	}
x86_l_2e50:
	/* 0x2e50: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e55:
	/* 0x2e55: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e5a:
	/* 0x2e5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e5f:
	/* 0x2e5f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2e62:
	/* 0x2e62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e64:
	/* 0x2e64: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2e68:
	/* 0x2e68: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e6d:
	/* 0x2e6d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e72:
	/* 0x2e72: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2e77:
	/* 0x2e77: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2e7a:
	/* 0x2e7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e7c:
	/* 0x2e7c: mov    r14,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e80:
	/* 0x2e80: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e84:
	/* 0x2e84: mov    esi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2e88:
	/* 0x2e88: sub    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2e8b:
	/* 0x2e8b: mov    edi,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e8e:
	/* 0x2e8e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e90:
	/* 0x2e90: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2e92:
	/* 0x2e92: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e94:
	/* 0x2e94: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2e97:
	/* 0x2e97: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2e9c:
	/* 0x2e9c: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e9f:
	/* 0x2e9f: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2ea1:
	/* 0x2ea1: seta   r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_A);
x86_l_2ea5:
	/* 0x2ea5: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_2ea8:
	/* 0x2ea8: cmovb  r8d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_2eac:
	/* 0x2eac: add    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2eaf:
	/* 0x2eaf: mov    eax,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_32);
x86_l_2eb1:
	/* 0x2eb1: sub    eax,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R9, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2eb4:
	/* 0x2eb4: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2eb7:
	/* 0x2eb7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ebc:
	/* 0x2ebc: sub    rcx,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R9, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2ebf:
	/* 0x2ebf: jb     2f5b <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2f5b;
	}
x86_l_2ec5:
	/* 0x2ec5: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_2ecc:
	/* 0x2ecc: ja     2f5b <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2f5b;
	}
x86_l_2ed2:
	/* 0x2ed2: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2ed4:
	/* 0x2ed4: jbe    2f67 <cwd_read_v61+0x17f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2f67;
	}
x86_l_2eda:
	/* 0x2eda: lea    r15,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2ede:
	/* 0x2ede: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2ee3:
	/* 0x2ee3: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2ee7:
	/* 0x2ee7: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2eeb:
	/* 0x2eeb: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2eee:
	/* 0x2eee: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ef3:
	/* 0x2ef3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ef5:
	/* 0x2ef5: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ef9:
	/* 0x2ef9: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2efe:
	/* 0x2efe: mov    QWORD PTR [rbx+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f02:
	/* 0x2f02: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f04:
	/* 0x2f04: jmp    2f5b <cwd_read_v61+0x173> */
	goto x86_l_2f5b;
x86_l_2f06:
	/* 0x2f06: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f0a:
	/* 0x2f0a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f0f:
	/* 0x2f0f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f14:
	/* 0x2f14: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f19:
	/* 0x2f19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f1b:
	/* 0x2f1b: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f1f:
	/* 0x2f1f: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2f24:
	/* 0x2f24: je     2f52 <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f52;
	}
x86_l_2f26:
	/* 0x2f26: lea    rdi,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f2a:
	/* 0x2f2a: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2f2e:
	/* 0x2f2e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f33:
	/* 0x2f33: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f38:
	/* 0x2f38: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2f3b:
	/* 0x2f3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f3d:
	/* 0x2f3d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f42:
	/* 0x2f42: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f46:
	/* 0x2f46: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2f4a:
	/* 0x2f4a: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f4e:
	/* 0x2f4e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f50:
	/* 0x2f50: jmp    2f5b <cwd_read_v61+0x173> */
	goto x86_l_2f5b;
x86_l_2f52:
	/* 0x2f52: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_2f56:
	/* 0x2f56: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f5b:
	/* 0x2f5b: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_2f5f:
	/* 0x2f5f: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2f60:
	/* 0x2f60: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2f62:
	/* 0x2f62: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2f64:
	/* 0x2f64: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2f66:
	/* 0x2f66: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2f67:
	/* 0x2f67: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2f6b:
	/* 0x2f6b: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f6e:
	/* 0x2f6e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f73:
	/* 0x2f73: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2f76:
	/* 0x2f76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f78:
	/* 0x2f78: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f7d:
	/* 0x2f7d: mov    QWORD PTR [rbx+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f81:
	/* 0x2f81: jmp    2f5b <cwd_read_v61+0x173> */
	goto x86_l_2f5b;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_process_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 10696U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1809ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_process_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1814ULL && __x86_pc <= 3578ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_process_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3584ULL && __x86_pc <= 5396ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_process_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5402ULL && __x86_pc <= 7177ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_process_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7181ULL && __x86_pc <= 8927ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_process_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8929ULL && __x86_pc <= 10680ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_process_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10687ULL && __x86_pc <= 12161ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_v61_generic_tracepoint_process_event_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

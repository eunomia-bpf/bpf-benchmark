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
extern char string_maps_6;
extern char string_maps_7;
extern char string_maps_heap;
extern char string_postfix_maps;
extern char string_postfix_maps_heap;
extern char string_prefix_maps;
extern char string_prefix_maps_heap;
extern char substring_map;
extern char usdt_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_usdt_filter_arg_x86_chunk_0(
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
	case 31ULL: goto x86_l_1f;
	case 38ULL: goto x86_l_26;
	case 46ULL: goto x86_l_2e;
	case 51ULL: goto x86_l_33;
	case 53ULL: goto x86_l_35;
	case 56ULL: goto x86_l_38;
	case 62ULL: goto x86_l_3e;
	case 65ULL: goto x86_l_41;
	case 71ULL: goto x86_l_47;
	case 78ULL: goto x86_l_4e;
	case 85ULL: goto x86_l_55;
	case 90ULL: goto x86_l_5a;
	case 92ULL: goto x86_l_5c;
	case 95ULL: goto x86_l_5f;
	case 101ULL: goto x86_l_65;
	case 109ULL: goto x86_l_6d;
	case 115ULL: goto x86_l_73;
	case 118ULL: goto x86_l_76;
	case 120ULL: goto x86_l_78;
	case 123ULL: goto x86_l_7b;
	case 132ULL: goto x86_l_84;
	case 138ULL: goto x86_l_8a;
	case 140ULL: goto x86_l_8c;
	case 145ULL: goto x86_l_91;
	case 149ULL: goto x86_l_95;
	case 153ULL: goto x86_l_99;
	case 157ULL: goto x86_l_9d;
	case 161ULL: goto x86_l_a1;
	case 166ULL: goto x86_l_a6;
	case 170ULL: goto x86_l_aa;
	case 173ULL: goto x86_l_ad;
	case 177ULL: goto x86_l_b1;
	case 179ULL: goto x86_l_b3;
	case 185ULL: goto x86_l_b9;
	case 189ULL: goto x86_l_bd;
	case 192ULL: goto x86_l_c0;
	case 194ULL: goto x86_l_c2;
	case 199ULL: goto x86_l_c7;
	case 203ULL: goto x86_l_cb;
	case 206ULL: goto x86_l_ce;
	case 208ULL: goto x86_l_d0;
	case 214ULL: goto x86_l_d6;
	case 218ULL: goto x86_l_da;
	case 221ULL: goto x86_l_dd;
	case 223ULL: goto x86_l_df;
	case 228ULL: goto x86_l_e4;
	case 232ULL: goto x86_l_e8;
	case 235ULL: goto x86_l_eb;
	case 238ULL: goto x86_l_ee;
	case 244ULL: goto x86_l_f4;
	case 249ULL: goto x86_l_f9;
	case 251ULL: goto x86_l_fb;
	case 255ULL: goto x86_l_ff;
	case 261ULL: goto x86_l_105;
	case 263ULL: goto x86_l_107;
	case 269ULL: goto x86_l_10d;
	case 272ULL: goto x86_l_110;
	case 274ULL: goto x86_l_112;
	case 277ULL: goto x86_l_115;
	case 283ULL: goto x86_l_11b;
	case 285ULL: goto x86_l_11d;
	case 291ULL: goto x86_l_123;
	case 294ULL: goto x86_l_126;
	case 300ULL: goto x86_l_12c;
	case 302ULL: goto x86_l_12e;
	case 305ULL: goto x86_l_131;
	case 311ULL: goto x86_l_137;
	case 314ULL: goto x86_l_13a;
	case 320ULL: goto x86_l_140;
	case 323ULL: goto x86_l_143;
	case 329ULL: goto x86_l_149;
	case 332ULL: goto x86_l_14c;
	case 338ULL: goto x86_l_152;
	case 340ULL: goto x86_l_154;
	case 345ULL: goto x86_l_159;
	case 349ULL: goto x86_l_15d;
	case 357ULL: goto x86_l_165;
	case 360ULL: goto x86_l_168;
	case 368ULL: goto x86_l_170;
	case 373ULL: goto x86_l_175;
	case 381ULL: goto x86_l_17d;
	case 386ULL: goto x86_l_182;
	case 391ULL: goto x86_l_187;
	case 396ULL: goto x86_l_18c;
	case 401ULL: goto x86_l_191;
	case 406ULL: goto x86_l_196;
	case 413ULL: goto x86_l_19d;
	case 420ULL: goto x86_l_1a4;
	case 425ULL: goto x86_l_1a9;
	case 430ULL: goto x86_l_1ae;
	case 433ULL: goto x86_l_1b1;
	case 438ULL: goto x86_l_1b6;
	case 440ULL: goto x86_l_1b8;
	case 447ULL: goto x86_l_1bf;
	case 452ULL: goto x86_l_1c4;
	case 457ULL: goto x86_l_1c9;
	case 460ULL: goto x86_l_1cc;
	case 465ULL: goto x86_l_1d1;
	case 467ULL: goto x86_l_1d3;
	case 469ULL: goto x86_l_1d5;
	case 476ULL: goto x86_l_1dc;
	case 477ULL: goto x86_l_1dd;
	case 479ULL: goto x86_l_1df;
	case 481ULL: goto x86_l_1e1;
	case 483ULL: goto x86_l_1e3;
	case 485ULL: goto x86_l_1e5;
	case 486ULL: goto x86_l_1e6;
	case 491ULL: goto x86_l_1eb;
	case 493ULL: goto x86_l_1ed;
	case 501ULL: goto x86_l_1f5;
	case 503ULL: goto x86_l_1f7;
	case 508ULL: goto x86_l_1fc;
	case 516ULL: goto x86_l_204;
	case 518ULL: goto x86_l_206;
	case 523ULL: goto x86_l_20b;
	case 531ULL: goto x86_l_213;
	case 533ULL: goto x86_l_215;
	case 538ULL: goto x86_l_21a;
	case 546ULL: goto x86_l_222;
	case 548ULL: goto x86_l_224;
	case 553ULL: goto x86_l_229;
	case 561ULL: goto x86_l_231;
	case 563ULL: goto x86_l_233;
	case 568ULL: goto x86_l_238;
	case 576ULL: goto x86_l_240;
	case 578ULL: goto x86_l_242;
	case 585ULL: goto x86_l_249;
	case 592ULL: goto x86_l_250;
	case 597ULL: goto x86_l_255;
	case 602ULL: goto x86_l_25a;
	case 605ULL: goto x86_l_25d;
	case 610ULL: goto x86_l_262;
	case 612ULL: goto x86_l_264;
	case 616ULL: goto x86_l_268;
	case 621ULL: goto x86_l_26d;
	case 623ULL: goto x86_l_26f;
	case 628ULL: goto x86_l_274;
	case 633ULL: goto x86_l_279;
	case 640ULL: goto x86_l_280;
	case 645ULL: goto x86_l_285;
	case 650ULL: goto x86_l_28a;
	case 652ULL: goto x86_l_28c;
	case 655ULL: goto x86_l_28f;
	case 661ULL: goto x86_l_295;
	case 668ULL: goto x86_l_29c;
	case 673ULL: goto x86_l_2a1;
	case 678ULL: goto x86_l_2a6;
	case 680ULL: goto x86_l_2a8;
	case 685ULL: goto x86_l_2ad;
	case 688ULL: goto x86_l_2b0;
	case 691ULL: goto x86_l_2b3;
	case 694ULL: goto x86_l_2b6;
	case 699ULL: goto x86_l_2bb;
	case 702ULL: goto x86_l_2be;
	case 710ULL: goto x86_l_2c6;
	case 716ULL: goto x86_l_2cc;
	case 719ULL: goto x86_l_2cf;
	case 723ULL: goto x86_l_2d3;
	case 729ULL: goto x86_l_2d9;
	case 737ULL: goto x86_l_2e1;
	case 742ULL: goto x86_l_2e6;
	case 749ULL: goto x86_l_2ed;
	case 755ULL: goto x86_l_2f3;
	case 758ULL: goto x86_l_2f6;
	case 765ULL: goto x86_l_2fd;
	case 770ULL: goto x86_l_302;
	case 773ULL: goto x86_l_305;
	case 779ULL: goto x86_l_30b;
	case 782ULL: goto x86_l_30e;
	case 786ULL: goto x86_l_312;
	case 790ULL: goto x86_l_316;
	case 796ULL: goto x86_l_31c;
	case 805ULL: goto x86_l_325;
	case 811ULL: goto x86_l_32b;
	case 819ULL: goto x86_l_333;
	case 825ULL: goto x86_l_339;
	case 829ULL: goto x86_l_33d;
	case 836ULL: goto x86_l_344;
	case 841ULL: goto x86_l_349;
	case 844ULL: goto x86_l_34c;
	case 846ULL: goto x86_l_34e;
	case 849ULL: goto x86_l_351;
	case 852ULL: goto x86_l_354;
	case 858ULL: goto x86_l_35a;
	case 861ULL: goto x86_l_35d;
	case 864ULL: goto x86_l_360;
	case 870ULL: goto x86_l_366;
	case 872ULL: goto x86_l_368;
	case 882ULL: goto x86_l_372;
	case 886ULL: goto x86_l_376;
	case 888ULL: goto x86_l_378;
	case 898ULL: goto x86_l_382;
	case 902ULL: goto x86_l_386;
	case 908ULL: goto x86_l_38c;
	case 918ULL: goto x86_l_396;
	case 922ULL: goto x86_l_39a;
	case 928ULL: goto x86_l_3a0;
	case 931ULL: goto x86_l_3a3;
	case 936ULL: goto x86_l_3a8;
	case 939ULL: goto x86_l_3ab;
	case 941ULL: goto x86_l_3ad;
	case 944ULL: goto x86_l_3b0;
	case 950ULL: goto x86_l_3b6;
	case 953ULL: goto x86_l_3b9;
	case 959ULL: goto x86_l_3bf;
	case 962ULL: goto x86_l_3c2;
	case 965ULL: goto x86_l_3c5;
	case 967ULL: goto x86_l_3c7;
	case 970ULL: goto x86_l_3ca;
	case 976ULL: goto x86_l_3d0;
	case 979ULL: goto x86_l_3d3;
	case 982ULL: goto x86_l_3d6;
	case 986ULL: goto x86_l_3da;
	case 989ULL: goto x86_l_3dd;
	case 995ULL: goto x86_l_3e3;
	case 998ULL: goto x86_l_3e6;
	case 1001ULL: goto x86_l_3e9;
	case 1007ULL: goto x86_l_3ef;
	case 1010ULL: goto x86_l_3f2;
	case 1016ULL: goto x86_l_3f8;
	case 1021ULL: goto x86_l_3fd;
	case 1024ULL: goto x86_l_400;
	case 1030ULL: goto x86_l_406;
	case 1035ULL: goto x86_l_40b;
	case 1038ULL: goto x86_l_40e;
	case 1041ULL: goto x86_l_411;
	case 1047ULL: goto x86_l_417;
	case 1050ULL: goto x86_l_41a;
	case 1053ULL: goto x86_l_41d;
	case 1059ULL: goto x86_l_423;
	case 1062ULL: goto x86_l_426;
	case 1065ULL: goto x86_l_429;
	case 1071ULL: goto x86_l_42f;
	case 1080ULL: goto x86_l_438;
	case 1089ULL: goto x86_l_441;
	case 1098ULL: goto x86_l_44a;
	case 1107ULL: goto x86_l_453;
	case 1116ULL: goto x86_l_45c;
	case 1119ULL: goto x86_l_45f;
	case 1125ULL: goto x86_l_465;
	case 1128ULL: goto x86_l_468;
	case 1131ULL: goto x86_l_46b;
	case 1137ULL: goto x86_l_471;
	case 1140ULL: goto x86_l_474;
	case 1145ULL: goto x86_l_479;
	case 1148ULL: goto x86_l_47c;
	case 1154ULL: goto x86_l_482;
	case 1159ULL: goto x86_l_487;
	case 1162ULL: goto x86_l_48a;
	case 1164ULL: goto x86_l_48c;
	case 1167ULL: goto x86_l_48f;
	case 1173ULL: goto x86_l_495;
	case 1176ULL: goto x86_l_498;
	case 1179ULL: goto x86_l_49b;
	case 1183ULL: goto x86_l_49f;
	case 1186ULL: goto x86_l_4a2;
	case 1192ULL: goto x86_l_4a8;
	case 1195ULL: goto x86_l_4ab;
	case 1198ULL: goto x86_l_4ae;
	case 1204ULL: goto x86_l_4b4;
	case 1208ULL: goto x86_l_4b8;
	case 1211ULL: goto x86_l_4bb;
	case 1217ULL: goto x86_l_4c1;
	case 1222ULL: goto x86_l_4c6;
	case 1225ULL: goto x86_l_4c9;
	case 1231ULL: goto x86_l_4cf;
	case 1236ULL: goto x86_l_4d4;
	case 1240ULL: goto x86_l_4d8;
	case 1243ULL: goto x86_l_4db;
	case 1249ULL: goto x86_l_4e1;
	case 1252ULL: goto x86_l_4e4;
	case 1258ULL: goto x86_l_4ea;
	case 1260ULL: goto x86_l_4ec;
	case 1270ULL: goto x86_l_4f6;
	case 1274ULL: goto x86_l_4fa;
	case 1280ULL: goto x86_l_500;
	case 1285ULL: goto x86_l_505;
	case 1289ULL: goto x86_l_509;
	case 1295ULL: goto x86_l_50f;
	case 1305ULL: goto x86_l_519;
	case 1309ULL: goto x86_l_51d;
	case 1315ULL: goto x86_l_523;
	case 1318ULL: goto x86_l_526;
	case 1324ULL: goto x86_l_52c;
	case 1326ULL: goto x86_l_52e;
	case 1331ULL: goto x86_l_533;
	case 1335ULL: goto x86_l_537;
	case 1341ULL: goto x86_l_53d;
	case 1346ULL: goto x86_l_542;
	case 1349ULL: goto x86_l_545;
	case 1355ULL: goto x86_l_54b;
	case 1358ULL: goto x86_l_54e;
	case 1361ULL: goto x86_l_551;
	case 1365ULL: goto x86_l_555;
	case 1371ULL: goto x86_l_55b;
	case 1374ULL: goto x86_l_55e;
	case 1376ULL: goto x86_l_560;
	case 1382ULL: goto x86_l_566;
	case 1387ULL: goto x86_l_56b;
	case 1390ULL: goto x86_l_56e;
	case 1393ULL: goto x86_l_571;
	case 1399ULL: goto x86_l_577;
	case 1402ULL: goto x86_l_57a;
	case 1404ULL: goto x86_l_57c;
	case 1407ULL: goto x86_l_57f;
	case 1409ULL: goto x86_l_581;
	case 1414ULL: goto x86_l_586;
	case 1417ULL: goto x86_l_589;
	case 1423ULL: goto x86_l_58f;
	case 1426ULL: goto x86_l_592;
	case 1432ULL: goto x86_l_598;
	case 1435ULL: goto x86_l_59b;
	case 1438ULL: goto x86_l_59e;
	case 1444ULL: goto x86_l_5a4;
	case 1447ULL: goto x86_l_5a7;
	case 1453ULL: goto x86_l_5ad;
	case 1458ULL: goto x86_l_5b2;
	case 1461ULL: goto x86_l_5b5;
	case 1464ULL: goto x86_l_5b8;
	case 1470ULL: goto x86_l_5be;
	case 1473ULL: goto x86_l_5c1;
	case 1479ULL: goto x86_l_5c7;
	case 1481ULL: goto x86_l_5c9;
	case 1486ULL: goto x86_l_5ce;
	case 1490ULL: goto x86_l_5d2;
	case 1492ULL: goto x86_l_5d4;
	case 1497ULL: goto x86_l_5d9;
	case 1500ULL: goto x86_l_5dc;
	case 1506ULL: goto x86_l_5e2;
	case 1509ULL: goto x86_l_5e5;
	case 1512ULL: goto x86_l_5e8;
	case 1518ULL: goto x86_l_5ee;
	case 1522ULL: goto x86_l_5f2;
	case 1524ULL: goto x86_l_5f4;
	case 1530ULL: goto x86_l_5fa;
	case 1535ULL: goto x86_l_5ff;
	case 1538ULL: goto x86_l_602;
	case 1541ULL: goto x86_l_605;
	case 1547ULL: goto x86_l_60b;
	case 1550ULL: goto x86_l_60e;
	case 1555ULL: goto x86_l_613;
	case 1558ULL: goto x86_l_616;
	case 1564ULL: goto x86_l_61c;
	case 1569ULL: goto x86_l_621;
	case 1574ULL: goto x86_l_626;
	case 1578ULL: goto x86_l_62a;
	case 1584ULL: goto x86_l_630;
	case 1594ULL: goto x86_l_63a;
	case 1598ULL: goto x86_l_63e;
	case 1604ULL: goto x86_l_644;
	case 1607ULL: goto x86_l_647;
	case 1613ULL: goto x86_l_64d;
	case 1618ULL: goto x86_l_652;
	case 1623ULL: goto x86_l_657;
	case 1626ULL: goto x86_l_65a;
	case 1632ULL: goto x86_l_660;
	case 1637ULL: goto x86_l_665;
	case 1640ULL: goto x86_l_668;
	case 1646ULL: goto x86_l_66e;
	case 1650ULL: goto x86_l_672;
	case 1652ULL: goto x86_l_674;
	case 1654ULL: goto x86_l_676;
	case 1660ULL: goto x86_l_67c;
	case 1662ULL: goto x86_l_67e;
	case 1668ULL: goto x86_l_684;
	case 1673ULL: goto x86_l_689;
	case 1676ULL: goto x86_l_68c;
	case 1682ULL: goto x86_l_692;
	case 1685ULL: goto x86_l_695;
	case 1691ULL: goto x86_l_69b;
	case 1696ULL: goto x86_l_6a0;
	case 1699ULL: goto x86_l_6a3;
	case 1705ULL: goto x86_l_6a9;
	case 1709ULL: goto x86_l_6ad;
	case 1714ULL: goto x86_l_6b2;
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
	/* 0xa: sub    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 184ULL);
x86_l_11:
	/* 0x11: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    DWORD PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1f:
	/* 0x1f: mov    rdi,QWORD PTR [rip+0x1eac0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_26:
	/* 0x26: lea    rsi,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_2e:
	/* 0x2e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33:
	/* 0x33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35:
	/* 0x35: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38:
	/* 0x38: je     1d3 <generic_usdt_filter_arg+0x1d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d3;
	}
x86_l_3e:
	/* 0x3e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_41:
	/* 0x41: mov    ebx,DWORD PTR [rax+0x5f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_47:
	/* 0x47: lea    rsi,[rax+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_4e:
	/* 0x4e: mov    rdi,QWORD PTR [rip+0x1eac0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_55:
	/* 0x55: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5a:
	/* 0x5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c:
	/* 0x5c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5f:
	/* 0x5f: je     1b8 <generic_usdt_filter_arg+0x1b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b8;
	}
x86_l_65:
	/* 0x65: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_6d:
	/* 0x6d: je     1b8 <generic_usdt_filter_arg+0x1b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b8;
	}
x86_l_73:
	/* 0x73: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_76:
	/* 0x76: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_78:
	/* 0x78: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_7b:
	/* 0x7b: cmp    BYTE PTR [r14+rax*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 104183021699072ULL);
x86_l_84:
	/* 0x84: je     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10d;
	}
x86_l_8a:
	/* 0x8a: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8c:
	/* 0x8c: mov    ecx,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_91:
	/* 0x91: lea    rdx,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_95:
	/* 0x95: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_99:
	/* 0x99: lea    rax,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_9d:
	/* 0x9d: add    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_a1:
	/* 0xa1: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_a6:
	/* 0xa6: mov    eax,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_aa:
	/* 0xaa: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ad:
	/* 0xad: add    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_b1:
	/* 0xb1: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_b3:
	/* 0xb3: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_b9:
	/* 0xb9: mov    ecx,DWORD PTR [rcx+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_bd:
	/* 0xbd: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c0:
	/* 0xc0: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_c2:
	/* 0xc2: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_c7:
	/* 0xc7: mov    eax,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_cb:
	/* 0xcb: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ce:
	/* 0xce: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_d0:
	/* 0xd0: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_d6:
	/* 0xd6: mov    ecx,DWORD PTR [rcx+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_da:
	/* 0xda: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_dd:
	/* 0xdd: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_df:
	/* 0xdf: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_e4:
	/* 0xe4: mov    r9d,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_e8:
	/* 0xe8: add    r9,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_eb:
	/* 0xeb: mov    edi,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R9, X86_WIDTH_32);
x86_l_ee:
	/* 0xee: and    edi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_f4:
	/* 0xf4: cmp    DWORD PTR [r15+rdi*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 25ULL);
x86_l_f9:
	/* 0xf9: jae    159 <generic_usdt_filter_arg+0x159> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_159;
	}
x86_l_fb:
	/* 0xfb: cmp    rdi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_64, 1ULL);
x86_l_ff:
	/* 0xff: je     1b8 <generic_usdt_filter_arg+0x1b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b8;
	}
x86_l_105:
	/* 0x105: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_107:
	/* 0x107: jne    196 <generic_usdt_filter_arg+0x196> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_196;
	}
x86_l_10d:
	/* 0x10d: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_110:
	/* 0x110: jg     12e <generic_usdt_filter_arg+0x12e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_12e;
	}
x86_l_112:
	/* 0x112: cmp    ebx,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4294967295ULL);
x86_l_115:
	/* 0x115: je     1eb <generic_usdt_filter_arg+0x1eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1eb;
	}
x86_l_11b:
	/* 0x11b: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_11d:
	/* 0x11d: je     1f7 <generic_usdt_filter_arg+0x1f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f7;
	}
x86_l_123:
	/* 0x123: cmp    ebx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_126:
	/* 0x126: je     206 <generic_usdt_filter_arg+0x206> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_206;
	}
x86_l_12c:
	/* 0x12c: jmp    149 <generic_usdt_filter_arg+0x149> */
	goto x86_l_149;
x86_l_12e:
	/* 0x12e: cmp    ebx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_131:
	/* 0x131: je     215 <generic_usdt_filter_arg+0x215> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_215;
	}
x86_l_137:
	/* 0x137: cmp    ebx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_13a:
	/* 0x13a: je     224 <generic_usdt_filter_arg+0x224> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_224;
	}
x86_l_140:
	/* 0x140: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_143:
	/* 0x143: je     233 <generic_usdt_filter_arg+0x233> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_233;
	}
x86_l_149:
	/* 0x149: cmp    ebx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_14c:
	/* 0x14c: jg     264 <generic_usdt_filter_arg+0x264> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_264;
	}
x86_l_152:
	/* 0x152: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_154:
	/* 0x154: jmp    242 <generic_usdt_filter_arg+0x242> */
	goto x86_l_242;
x86_l_159:
	/* 0x159: lea    rax,[r15+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_15d:
	/* 0x15d: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_165:
	/* 0x165: xor    r11d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_168:
	/* 0x168: lea    rax,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_170:
	/* 0x170: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_175:
	/* 0x175: mov    QWORD PTR [rsp+0xa8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_17d:
	/* 0x17d: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_182:
	/* 0x182: mov    QWORD PTR [rsp+0x10],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_187:
	/* 0x187: mov    QWORD PTR [rsp+0x70],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18c:
	/* 0x18c: mov    QWORD PTR [rsp+0x68],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_191:
	/* 0x191: jmp    2d9 <generic_usdt_filter_arg+0x2d9> */
	goto x86_l_2d9;
x86_l_196:
	/* 0x196: mov    DWORD PTR [r14+0x5f04],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_19d:
	/* 0x19d: mov    rsi,QWORD PTR [rip+0x1eac0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_1a4:
	/* 0x1a4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a9:
	/* 0x1a9: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1ae:
	/* 0x1ae: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1b1:
	/* 0x1b1: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1b6:
	/* 0x1b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b8:
	/* 0x1b8: mov    rsi,QWORD PTR [rip+0x1eac0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_1bf:
	/* 0x1bf: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1c4:
	/* 0x1c4: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1c9:
	/* 0x1c9: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1cc:
	/* 0x1cc: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_1d1:
	/* 0x1d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d3:
	/* 0x1d3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d5:
	/* 0x1d5: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_1dc:
	/* 0x1dc: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1dd:
	/* 0x1dd: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1df:
	/* 0x1df: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1e1:
	/* 0x1e1: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1e3:
	/* 0x1e3: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1e5:
	/* 0x1e5: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1e6:
	/* 0x1e6: jmp    333a <native_bpf_strncasestr+0x72> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1eb:
	/* 0x1eb: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ed:
	/* 0x1ed: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_1f5:
	/* 0x1f5: jne    242 <generic_usdt_filter_arg+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_242;
	}
x86_l_1f7:
	/* 0x1f7: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_1fc:
	/* 0x1fc: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_204:
	/* 0x204: jne    242 <generic_usdt_filter_arg+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_242;
	}
x86_l_206:
	/* 0x206: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_20b:
	/* 0x20b: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_213:
	/* 0x213: jne    242 <generic_usdt_filter_arg+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_242;
	}
x86_l_215:
	/* 0x215: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_21a:
	/* 0x21a: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_222:
	/* 0x222: jne    242 <generic_usdt_filter_arg+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_242;
	}
x86_l_224:
	/* 0x224: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_229:
	/* 0x229: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_231:
	/* 0x231: jne    242 <generic_usdt_filter_arg+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_242;
	}
x86_l_233:
	/* 0x233: mov    ebx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 5ULL);
x86_l_238:
	/* 0x238: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_240:
	/* 0x240: je     264 <generic_usdt_filter_arg+0x264> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_264;
	}
x86_l_242:
	/* 0x242: mov    DWORD PTR [r14+0x5f00],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_249:
	/* 0x249: mov    rsi,QWORD PTR [rip+0x1eabc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_250:
	/* 0x250: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_255:
	/* 0x255: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_25a:
	/* 0x25a: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_25d:
	/* 0x25d: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_262:
	/* 0x262: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_264:
	/* 0x264: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_268:
	/* 0x268: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_26d:
	/* 0x26d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f:
	/* 0x26f: mov    QWORD PTR [rsp+0x38],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_274:
	/* 0x274: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_279:
	/* 0x279: mov    rdi,QWORD PTR [rip+0x1eabc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_280:
	/* 0x280: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_285:
	/* 0x285: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28a:
	/* 0x28a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28c:
	/* 0x28c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28f:
	/* 0x28f: je     1d3 <generic_usdt_filter_arg+0x1d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d3;
	}
x86_l_295:
	/* 0x295: mov    rdi,QWORD PTR [rip+0x1eabc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_29c:
	/* 0x29c: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a1:
	/* 0x2a1: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2a6:
	/* 0x2a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a8:
	/* 0x2a8: jmp    1d3 <generic_usdt_filter_arg+0x1d3> */
	goto x86_l_1d3;
x86_l_2ad:
	/* 0x2ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b0:
	/* 0x2b0: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_2b3:
	/* 0x2b3: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2b6:
	/* 0x2b6: mov    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2bb:
	/* 0x2bb: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2be:
	/* 0x2be: mov    rbx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2c6:
	/* 0x2c6: je     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10d;
	}
x86_l_2cc:
	/* 0x2cc: inc    r11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2cf:
	/* 0x2cf: cmp    r11,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_64, 5ULL);
x86_l_2d3:
	/* 0x2d3: je     fb <generic_usdt_filter_arg+0xfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fb;
	}
x86_l_2d9:
	/* 0x2d9: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2e1:
	/* 0x2e1: mov    r12d,DWORD PTR [rax+r11*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 2), 4ULL);
x86_l_2e6:
	/* 0x2e6: test   r12d,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_32, 1023ULL);
x86_l_2ed:
	/* 0x2ed: je     fb <generic_usdt_filter_arg+0xfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fb;
	}
x86_l_2f3:
	/* 0x2f3: add    r12d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2f6:
	/* 0x2f6: and    r12d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_2fd:
	/* 0x2fd: mov    eax,DWORD PTR [r15+r12*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 4ULL);
x86_l_302:
	/* 0x302: cmp    eax,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_305:
	/* 0x305: je     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10d;
	}
x86_l_30b:
	/* 0x30b: add    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30e:
	/* 0x30e: mov    ecx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_312:
	/* 0x312: cmp    rcx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4ULL);
x86_l_316:
	/* 0x316: ja     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_10d;
	}
x86_l_31c:
	/* 0x31c: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_325:
	/* 0x325: jne    10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10d;
	}
x86_l_32b:
	/* 0x32b: mov    rcx,QWORD PTR [r14+rcx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_333:
	/* 0x333: and    ecx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_339:
	/* 0x339: lea    rsi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_33d:
	/* 0x33d: add    rsi,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_344:
	/* 0x344: mov    ecx,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_349:
	/* 0x349: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_34c:
	/* 0x34c: jle    3a8 <generic_usdt_filter_arg+0x3a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3a8;
	}
x86_l_34e:
	/* 0x34e: lea    edx,[rcx-0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551588ULL);
x86_l_351:
	/* 0x351: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_354:
	/* 0x354: jb     4d4 <generic_usdt_filter_arg+0x4d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4d4;
	}
x86_l_35a:
	/* 0x35a: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_35d:
	/* 0x35d: cmp    ecx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 42ULL);
x86_l_360:
	/* 0x360: ja     7ee <generic_usdt_filter_arg+0x7ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2030ULL;
	}
x86_l_366:
	/* 0x366: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_368:
	/* 0x368: movabs rsi,0xc000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 824633720832ULL);
x86_l_372:
	/* 0x372: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_376:
	/* 0x376: jb     3d0 <generic_usdt_filter_arg+0x3d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3d0;
	}
x86_l_378:
	/* 0x378: movabs rsi,0x30000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 3298534883328ULL);
x86_l_382:
	/* 0x382: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_386:
	/* 0x386: jb     42f <generic_usdt_filter_arg+0x42f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_42f;
	}
x86_l_38c:
	/* 0x38c: movabs rsi,0x42000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 4535485464576ULL);
x86_l_396:
	/* 0x396: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_39a:
	/* 0x39a: jae    7ee <generic_usdt_filter_arg+0x7ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2030ULL;
	}
x86_l_3a0:
	/* 0x3a0: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_3a3:
	/* 0x3a3: jmp    7fe <generic_usdt_filter_arg+0x7fe> */
	return 2046ULL;
x86_l_3a8:
	/* 0x3a8: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3ab:
	/* 0x3ab: jg     40b <generic_usdt_filter_arg+0x40b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_40b;
	}
x86_l_3ad:
	/* 0x3ad: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_3b0:
	/* 0x3b0: jle    487 <generic_usdt_filter_arg+0x487> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_487;
	}
x86_l_3b6:
	/* 0x3b6: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3b9:
	/* 0x3b9: je     4d4 <generic_usdt_filter_arg+0x4d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d4;
	}
x86_l_3bf:
	/* 0x3bf: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_3c2:
	/* 0x3c2: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_3c5:
	/* 0x3c5: je     42f <generic_usdt_filter_arg+0x42f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42f;
	}
x86_l_3c7:
	/* 0x3c7: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3ca:
	/* 0x3ca: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cc;
	}
x86_l_3d0:
	/* 0x3d0: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_3d3:
	/* 0x3d3: mov    ebp,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d6:
	/* 0x3d6: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3da:
	/* 0x3da: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_3dd:
	/* 0x3dd: jg     689 <generic_usdt_filter_arg+0x689> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_689;
	}
x86_l_3e3:
	/* 0x3e3: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_3e6:
	/* 0x3e6: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3e9:
	/* 0x3e9: jb     100c <generic_usdt_filter_arg+0x100c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4108ULL;
	}
x86_l_3ef:
	/* 0x3ef: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3f2:
	/* 0x3f2: je     f64 <generic_usdt_filter_arg+0xf64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3940ULL;
	}
x86_l_3f8:
	/* 0x3f8: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_3fd:
	/* 0x3fd: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_400:
	/* 0x400: je     6a9 <generic_usdt_filter_arg+0x6a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6a9;
	}
x86_l_406:
	/* 0x406: jmp    2f58 <generic_usdt_filter_arg+0x2f58> */
	return 12120ULL;
x86_l_40b:
	/* 0x40b: lea    edx,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_40e:
	/* 0x40e: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_411:
	/* 0x411: jb     4d4 <generic_usdt_filter_arg+0x4d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4d4;
	}
x86_l_417:
	/* 0x417: lea    edx,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_41a:
	/* 0x41a: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_41d:
	/* 0x41d: jb     7fe <generic_usdt_filter_arg+0x7fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2046ULL;
	}
x86_l_423:
	/* 0x423: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_426:
	/* 0x426: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_429:
	/* 0x429: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cc;
	}
x86_l_42f:
	/* 0x42f: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_438:
	/* 0x438: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_441:
	/* 0x441: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_44a:
	/* 0x44a: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_453:
	/* 0x453: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_45c:
	/* 0x45c: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_45f:
	/* 0x45f: jg     5ff <generic_usdt_filter_arg+0x5ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_5ff;
	}
x86_l_465:
	/* 0x465: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_468:
	/* 0x468: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_46b:
	/* 0x46b: je     db3 <generic_usdt_filter_arg+0xdb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3507ULL;
	}
x86_l_471:
	/* 0x471: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_474:
	/* 0x474: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_479:
	/* 0x479: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_47c:
	/* 0x47c: je     db5 <generic_usdt_filter_arg+0xdb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3509ULL;
	}
x86_l_482:
	/* 0x482: jmp    2b6 <generic_usdt_filter_arg+0x2b6> */
	goto x86_l_2b6;
x86_l_487:
	/* 0x487: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_48a:
	/* 0x48a: je     4d4 <generic_usdt_filter_arg+0x4d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d4;
	}
x86_l_48c:
	/* 0x48c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_48f:
	/* 0x48f: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cc;
	}
x86_l_495:
	/* 0x495: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_498:
	/* 0x498: mov    ebp,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_49b:
	/* 0x49b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_49f:
	/* 0x49f: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_4a2:
	/* 0x4a2: jg     108f <generic_usdt_filter_arg+0x108f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4239ULL;
	}
x86_l_4a8:
	/* 0x4a8: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_4ab:
	/* 0x4ab: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_4ae:
	/* 0x4ae: jb     1904 <generic_usdt_filter_arg+0x1904> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6404ULL;
	}
x86_l_4b4:
	/* 0x4b4: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b8:
	/* 0x4b8: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_4bb:
	/* 0x4bb: je     1866 <generic_usdt_filter_arg+0x1866> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6246ULL;
	}
x86_l_4c1:
	/* 0x4c1: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_4c6:
	/* 0x4c6: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_4c9:
	/* 0x4c9: je     10b3 <generic_usdt_filter_arg+0x10b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4275ULL;
	}
x86_l_4cf:
	/* 0x4cf: jmp    3216 <generic_usdt_filter_arg+0x3216> */
	return 12822ULL;
x86_l_4d4:
	/* 0x4d4: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d8:
	/* 0x4d8: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_4db:
	/* 0x4db: jle    56b <generic_usdt_filter_arg+0x56b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_56b;
	}
x86_l_4e1:
	/* 0x4e1: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_4e4:
	/* 0x4e4: ja     5b2 <generic_usdt_filter_arg+0x5b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_5b2;
	}
x86_l_4ea:
	/* 0x4ea: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_4ec:
	/* 0x4ec: movabs rsi,0x1e00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 128849018880ULL);
x86_l_4f6:
	/* 0x4f6: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_4fa:
	/* 0x4fa: jb     586 <generic_usdt_filter_arg+0x586> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_586;
	}
x86_l_500:
	/* 0x500: mov    esi,0x60000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1610612736ULL);
x86_l_505:
	/* 0x505: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_509:
	/* 0x509: jb     958 <generic_usdt_filter_arg+0x958> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2392ULL;
	}
x86_l_50f:
	/* 0x50f: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_519:
	/* 0x519: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_51d:
	/* 0x51d: jae    5b2 <generic_usdt_filter_arg+0x5b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5b2;
	}
x86_l_523:
	/* 0x523: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_526:
	/* 0x526: ja     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_10d;
	}
x86_l_52c:
	/* 0x52c: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_52e:
	/* 0x52e: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_533:
	/* 0x533: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_537:
	/* 0x537: jae    1202 <generic_usdt_filter_arg+0x1202> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4610ULL;
	}
x86_l_53d:
	/* 0x53d: mov    ecx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_542:
	/* 0x542: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_545:
	/* 0x545: jle    170a <generic_usdt_filter_arg+0x170a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5898ULL;
	}
x86_l_54b:
	/* 0x54b: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_54e:
	/* 0x54e: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_551:
	/* 0x551: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_555:
	/* 0x555: jae    1d1f <generic_usdt_filter_arg+0x1d1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7455ULL;
	}
x86_l_55b:
	/* 0x55b: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_55e:
	/* 0x55e: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_560:
	/* 0x560: jne    202c <generic_usdt_filter_arg+0x202c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8236ULL;
	}
x86_l_566:
	/* 0x566: jmp    31a4 <generic_usdt_filter_arg+0x31a4> */
	return 12708ULL;
x86_l_56b:
	/* 0x56b: lea    edx,[rcx-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_56e:
	/* 0x56e: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_571:
	/* 0x571: jb     9f7 <generic_usdt_filter_arg+0x9f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2551ULL;
	}
x86_l_577:
	/* 0x577: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_57a:
	/* 0x57a: je     5be <generic_usdt_filter_arg+0x5be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5be;
	}
x86_l_57c:
	/* 0x57c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_57f:
	/* 0x57f: je     5be <generic_usdt_filter_arg+0x5be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5be;
	}
x86_l_581:
	/* 0x581: jmp    2cc <generic_usdt_filter_arg+0x2cc> */
	goto x86_l_2cc;
x86_l_586:
	/* 0x586: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_589:
	/* 0x589: jle    9a7 <generic_usdt_filter_arg+0x9a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2471ULL;
	}
x86_l_58f:
	/* 0x58f: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_592:
	/* 0x592: jg     e38 <generic_usdt_filter_arg+0xe38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3640ULL;
	}
x86_l_598:
	/* 0x598: lea    edx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_59b:
	/* 0x59b: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_59e:
	/* 0x59e: jb     a8b <generic_usdt_filter_arg+0xa8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2699ULL;
	}
x86_l_5a4:
	/* 0x5a4: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_5a7:
	/* 0x5a7: je     a0d <generic_usdt_filter_arg+0xa0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2573ULL;
	}
x86_l_5ad:
	/* 0x5ad: jmp    10d <generic_usdt_filter_arg+0x10d> */
	goto x86_l_10d;
x86_l_5b2:
	/* 0x5b2: lea    edx,[rcx-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_5b5:
	/* 0x5b5: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_5b8:
	/* 0x5b8: jae    9ee <generic_usdt_filter_arg+0x9ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2542ULL;
	}
x86_l_5be:
	/* 0x5be: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_5c1:
	/* 0x5c1: ja     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_10d;
	}
x86_l_5c7:
	/* 0x5c7: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_5c9:
	/* 0x5c9: mov    esi,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4126ULL);
x86_l_5ce:
	/* 0x5ce: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_5d2:
	/* 0x5d2: jae    621 <generic_usdt_filter_arg+0x621> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_621;
	}
x86_l_5d4:
	/* 0x5d4: mov    edx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d9:
	/* 0x5d9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5dc:
	/* 0x5dc: jle    9b4 <generic_usdt_filter_arg+0x9b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2484ULL;
	}
x86_l_5e2:
	/* 0x5e2: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_5e5:
	/* 0x5e5: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_5e8:
	/* 0x5e8: jae    11e8 <generic_usdt_filter_arg+0x11e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4584ULL;
	}
x86_l_5ee:
	/* 0x5ee: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f2:
	/* 0x5f2: cmp    DWORD PTR [rsi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f4:
	/* 0x5f4: jne    22a9 <generic_usdt_filter_arg+0x22a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8873ULL;
	}
x86_l_5fa:
	/* 0x5fa: jmp    31a4 <generic_usdt_filter_arg+0x31a4> */
	return 12708ULL;
x86_l_5ff:
	/* 0x5ff: cmp    ecx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_602:
	/* 0x602: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_605:
	/* 0x605: je     d8b <generic_usdt_filter_arg+0xd8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3467ULL;
	}
x86_l_60b:
	/* 0x60b: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_60e:
	/* 0x60e: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_613:
	/* 0x613: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_616:
	/* 0x616: je     db5 <generic_usdt_filter_arg+0xdb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3509ULL;
	}
x86_l_61c:
	/* 0x61c: jmp    2b6 <generic_usdt_filter_arg+0x2b6> */
	goto x86_l_2b6;
x86_l_621:
	/* 0x621: mov    esi,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 3072ULL);
x86_l_626:
	/* 0x626: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_62a:
	/* 0x62a: jb     d27 <generic_usdt_filter_arg+0xd27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3367ULL;
	}
x86_l_630:
	/* 0x630: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_63a:
	/* 0x63a: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_63e:
	/* 0x63e: jae    10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_10d;
	}
x86_l_644:
	/* 0x644: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_647:
	/* 0x647: jne    1359 <generic_usdt_filter_arg+0x1359> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4953ULL;
	}
x86_l_64d:
	/* 0x64d: mov    esi,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_652:
	/* 0x652: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_657:
	/* 0x657: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_65a:
	/* 0x65a: ja     20d0 <generic_usdt_filter_arg+0x20d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8400ULL;
	}
x86_l_660:
	/* 0x660: mov    eax,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5122ULL);
x86_l_665:
	/* 0x665: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_668:
	/* 0x668: jae    20d0 <generic_usdt_filter_arg+0x20d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8400ULL;
	}
x86_l_66e:
	/* 0x66e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_672:
	/* 0x672: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_674:
	/* 0x674: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_676:
	/* 0x676: jg     20e2 <generic_usdt_filter_arg+0x20e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8418ULL;
	}
x86_l_67c:
	/* 0x67c: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_67e:
	/* 0x67e: jle    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2cc;
	}
x86_l_684:
	/* 0x684: jmp    20e2 <generic_usdt_filter_arg+0x20e2> */
	return 8418ULL;
x86_l_689:
	/* 0x689: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_68c:
	/* 0x68c: jg     e83 <generic_usdt_filter_arg+0xe83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3715ULL;
	}
x86_l_692:
	/* 0x692: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_695:
	/* 0x695: je     f64 <generic_usdt_filter_arg+0xf64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3940ULL;
	}
x86_l_69b:
	/* 0x69b: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_6a0:
	/* 0x6a0: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_6a3:
	/* 0x6a3: jne    2f58 <generic_usdt_filter_arg+0x2f58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12120ULL;
	}
x86_l_6a9:
	/* 0x6a9: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ad:
	/* 0x6ad: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6b2:
	/* 0x6b2: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 1719ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_usdt_filter_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1719ULL: goto x86_l_6b7;
	case 1723ULL: goto x86_l_6bb;
	case 1734ULL: goto x86_l_6c6;
	case 1739ULL: goto x86_l_6cb;
	case 1744ULL: goto x86_l_6d0;
	case 1751ULL: goto x86_l_6d7;
	case 1753ULL: goto x86_l_6d9;
	case 1756ULL: goto x86_l_6dc;
	case 1762ULL: goto x86_l_6e2;
	case 1767ULL: goto x86_l_6e7;
	case 1770ULL: goto x86_l_6ea;
	case 1776ULL: goto x86_l_6f0;
	case 1781ULL: goto x86_l_6f5;
	case 1786ULL: goto x86_l_6fa;
	case 1791ULL: goto x86_l_6ff;
	case 1798ULL: goto x86_l_706;
	case 1800ULL: goto x86_l_708;
	case 1803ULL: goto x86_l_70b;
	case 1809ULL: goto x86_l_711;
	case 1812ULL: goto x86_l_714;
	case 1815ULL: goto x86_l_717;
	case 1820ULL: goto x86_l_71c;
	case 1823ULL: goto x86_l_71f;
	case 1826ULL: goto x86_l_722;
	case 1828ULL: goto x86_l_724;
	case 1831ULL: goto x86_l_727;
	case 1834ULL: goto x86_l_72a;
	case 1839ULL: goto x86_l_72f;
	case 1842ULL: goto x86_l_732;
	case 1845ULL: goto x86_l_735;
	case 1850ULL: goto x86_l_73a;
	case 1854ULL: goto x86_l_73e;
	case 1860ULL: goto x86_l_744;
	case 1863ULL: goto x86_l_747;
	case 1867ULL: goto x86_l_74b;
	case 1873ULL: goto x86_l_751;
	case 1876ULL: goto x86_l_754;
	case 1880ULL: goto x86_l_758;
	case 1883ULL: goto x86_l_75b;
	case 1886ULL: goto x86_l_75e;
	case 1890ULL: goto x86_l_762;
	case 1894ULL: goto x86_l_766;
	case 1900ULL: goto x86_l_76c;
	case 1904ULL: goto x86_l_770;
	case 1908ULL: goto x86_l_774;
	case 1911ULL: goto x86_l_777;
	case 1913ULL: goto x86_l_779;
	case 1917ULL: goto x86_l_77d;
	case 1923ULL: goto x86_l_783;
	case 1927ULL: goto x86_l_787;
	case 1931ULL: goto x86_l_78b;
	case 1934ULL: goto x86_l_78e;
	case 1936ULL: goto x86_l_790;
	case 1940ULL: goto x86_l_794;
	case 1946ULL: goto x86_l_79a;
	case 1950ULL: goto x86_l_79e;
	case 1954ULL: goto x86_l_7a2;
	case 1957ULL: goto x86_l_7a5;
	case 1959ULL: goto x86_l_7a7;
	case 1963ULL: goto x86_l_7ab;
	case 1965ULL: goto x86_l_7ad;
	case 1969ULL: goto x86_l_7b1;
	case 1975ULL: goto x86_l_7b7;
	case 1979ULL: goto x86_l_7bb;
	case 1982ULL: goto x86_l_7be;
	case 1986ULL: goto x86_l_7c2;
	case 1990ULL: goto x86_l_7c6;
	case 1993ULL: goto x86_l_7c9;
	case 1995ULL: goto x86_l_7cb;
	case 2000ULL: goto x86_l_7d0;
	case 2005ULL: goto x86_l_7d5;
	case 2010ULL: goto x86_l_7da;
	case 2012ULL: goto x86_l_7dc;
	case 2014ULL: goto x86_l_7de;
	case 2017ULL: goto x86_l_7e1;
	case 2020ULL: goto x86_l_7e4;
	case 2025ULL: goto x86_l_7e9;
	case 2030ULL: goto x86_l_7ee;
	case 2033ULL: goto x86_l_7f1;
	case 2039ULL: goto x86_l_7f7;
	case 2042ULL: goto x86_l_7fa;
	case 2046ULL: goto x86_l_7fe;
	case 2050ULL: goto x86_l_802;
	case 2052ULL: goto x86_l_804;
	case 2054ULL: goto x86_l_806;
	case 2057ULL: goto x86_l_809;
	case 2060ULL: goto x86_l_80c;
	case 2062ULL: goto x86_l_80e;
	case 2064ULL: goto x86_l_810;
	case 2070ULL: goto x86_l_816;
	case 2073ULL: goto x86_l_819;
	case 2077ULL: goto x86_l_81d;
	case 2083ULL: goto x86_l_823;
	case 2085ULL: goto x86_l_825;
	case 2090ULL: goto x86_l_82a;
	case 2094ULL: goto x86_l_82e;
	case 2100ULL: goto x86_l_834;
	case 2105ULL: goto x86_l_839;
	case 2109ULL: goto x86_l_83d;
	case 2115ULL: goto x86_l_843;
	case 2125ULL: goto x86_l_84d;
	case 2129ULL: goto x86_l_851;
	case 2135ULL: goto x86_l_857;
	case 2142ULL: goto x86_l_85e;
	case 2148ULL: goto x86_l_864;
	case 2154ULL: goto x86_l_86a;
	case 2159ULL: goto x86_l_86f;
	case 2163ULL: goto x86_l_873;
	case 2167ULL: goto x86_l_877;
	case 2172ULL: goto x86_l_87c;
	case 2177ULL: goto x86_l_881;
	case 2182ULL: goto x86_l_886;
	case 2184ULL: goto x86_l_888;
	case 2188ULL: goto x86_l_88c;
	case 2192ULL: goto x86_l_890;
	case 2197ULL: goto x86_l_895;
	case 2199ULL: goto x86_l_897;
	case 2204ULL: goto x86_l_89c;
	case 2206ULL: goto x86_l_89e;
	case 2212ULL: goto x86_l_8a4;
	case 2217ULL: goto x86_l_8a9;
	case 2222ULL: goto x86_l_8ae;
	case 2227ULL: goto x86_l_8b3;
	case 2229ULL: goto x86_l_8b5;
	case 2235ULL: goto x86_l_8bb;
	case 2240ULL: goto x86_l_8c0;
	case 2243ULL: goto x86_l_8c3;
	case 2248ULL: goto x86_l_8c8;
	case 2253ULL: goto x86_l_8cd;
	case 2258ULL: goto x86_l_8d2;
	case 2264ULL: goto x86_l_8d8;
	case 2269ULL: goto x86_l_8dd;
	case 2271ULL: goto x86_l_8df;
	case 2277ULL: goto x86_l_8e5;
	case 2279ULL: goto x86_l_8e7;
	case 2285ULL: goto x86_l_8ed;
	case 2288ULL: goto x86_l_8f0;
	case 2294ULL: goto x86_l_8f6;
	case 2299ULL: goto x86_l_8fb;
	case 2301ULL: goto x86_l_8fd;
	case 2307ULL: goto x86_l_903;
	case 2309ULL: goto x86_l_905;
	case 2315ULL: goto x86_l_90b;
	case 2318ULL: goto x86_l_90e;
	case 2324ULL: goto x86_l_914;
	case 2329ULL: goto x86_l_919;
	case 2331ULL: goto x86_l_91b;
	case 2337ULL: goto x86_l_921;
	case 2339ULL: goto x86_l_923;
	case 2341ULL: goto x86_l_925;
	case 2344ULL: goto x86_l_928;
	case 2349ULL: goto x86_l_92d;
	case 2352ULL: goto x86_l_930;
	case 2355ULL: goto x86_l_933;
	case 2357ULL: goto x86_l_935;
	case 2368ULL: goto x86_l_940;
	case 2374ULL: goto x86_l_946;
	case 2380ULL: goto x86_l_94c;
	case 2382ULL: goto x86_l_94e;
	case 2387ULL: goto x86_l_953;
	case 2392ULL: goto x86_l_958;
	case 2395ULL: goto x86_l_95b;
	case 2401ULL: goto x86_l_961;
	case 2403ULL: goto x86_l_963;
	case 2408ULL: goto x86_l_968;
	case 2412ULL: goto x86_l_96c;
	case 2418ULL: goto x86_l_972;
	case 2423ULL: goto x86_l_977;
	case 2426ULL: goto x86_l_97a;
	case 2432ULL: goto x86_l_980;
	case 2435ULL: goto x86_l_983;
	case 2438ULL: goto x86_l_986;
	case 2442ULL: goto x86_l_98a;
	case 2448ULL: goto x86_l_990;
	case 2451ULL: goto x86_l_993;
	case 2453ULL: goto x86_l_995;
	case 2459ULL: goto x86_l_99b;
	case 2464ULL: goto x86_l_9a0;
	case 2466ULL: goto x86_l_9a2;
	case 2471ULL: goto x86_l_9a7;
	case 2474ULL: goto x86_l_9aa;
	case 2477ULL: goto x86_l_9ad;
	case 2479ULL: goto x86_l_9af;
	case 2484ULL: goto x86_l_9b4;
	case 2487ULL: goto x86_l_9b7;
	case 2493ULL: goto x86_l_9bd;
	case 2496ULL: goto x86_l_9c0;
	case 2502ULL: goto x86_l_9c6;
	case 2505ULL: goto x86_l_9c9;
	case 2511ULL: goto x86_l_9cf;
	case 2516ULL: goto x86_l_9d4;
	case 2519ULL: goto x86_l_9d7;
	case 2525ULL: goto x86_l_9dd;
	case 2529ULL: goto x86_l_9e1;
	case 2531ULL: goto x86_l_9e3;
	case 2537ULL: goto x86_l_9e9;
	case 2542ULL: goto x86_l_9ee;
	case 2545ULL: goto x86_l_9f1;
	case 2551ULL: goto x86_l_9f7;
	case 2554ULL: goto x86_l_9fa;
	case 2560ULL: goto x86_l_a00;
	case 2562ULL: goto x86_l_a02;
	case 2567ULL: goto x86_l_a07;
	case 2571ULL: goto x86_l_a0b;
	case 2573ULL: goto x86_l_a0d;
	case 2578ULL: goto x86_l_a12;
	case 2581ULL: goto x86_l_a15;
	case 2583ULL: goto x86_l_a17;
	case 2586ULL: goto x86_l_a1a;
	case 2589ULL: goto x86_l_a1d;
	case 2595ULL: goto x86_l_a23;
	case 2599ULL: goto x86_l_a27;
	case 2602ULL: goto x86_l_a2a;
	case 2608ULL: goto x86_l_a30;
	case 2613ULL: goto x86_l_a35;
	case 2618ULL: goto x86_l_a3a;
	case 2622ULL: goto x86_l_a3e;
	case 2624ULL: goto x86_l_a40;
	case 2634ULL: goto x86_l_a4a;
	case 2638ULL: goto x86_l_a4e;
	case 2644ULL: goto x86_l_a54;
	case 2649ULL: goto x86_l_a59;
	case 2652ULL: goto x86_l_a5c;
	case 2658ULL: goto x86_l_a62;
	case 2661ULL: goto x86_l_a65;
	case 2667ULL: goto x86_l_a6b;
	case 2670ULL: goto x86_l_a6e;
	case 2672ULL: goto x86_l_a70;
	case 2675ULL: goto x86_l_a73;
	case 2681ULL: goto x86_l_a79;
	case 2685ULL: goto x86_l_a7d;
	case 2688ULL: goto x86_l_a80;
	case 2694ULL: goto x86_l_a86;
	case 2699ULL: goto x86_l_a8b;
	case 2702ULL: goto x86_l_a8e;
	case 2708ULL: goto x86_l_a94;
	case 2715ULL: goto x86_l_a9b;
	case 2720ULL: goto x86_l_aa0;
	case 2725ULL: goto x86_l_aa5;
	case 2732ULL: goto x86_l_aac;
	case 2734ULL: goto x86_l_aae;
	case 2737ULL: goto x86_l_ab1;
	case 2743ULL: goto x86_l_ab7;
	case 2746ULL: goto x86_l_aba;
	case 2750ULL: goto x86_l_abe;
	case 2753ULL: goto x86_l_ac1;
	case 2758ULL: goto x86_l_ac6;
	case 2763ULL: goto x86_l_acb;
	case 2768ULL: goto x86_l_ad0;
	case 2770ULL: goto x86_l_ad2;
	case 2775ULL: goto x86_l_ad7;
	case 2778ULL: goto x86_l_ada;
	case 2784ULL: goto x86_l_ae0;
	case 2787ULL: goto x86_l_ae3;
	case 2792ULL: goto x86_l_ae8;
	case 2797ULL: goto x86_l_aed;
	case 2800ULL: goto x86_l_af0;
	case 2806ULL: goto x86_l_af6;
	case 2809ULL: goto x86_l_af9;
	case 2812ULL: goto x86_l_afc;
	case 2815ULL: goto x86_l_aff;
	case 2820ULL: goto x86_l_b04;
	case 2825ULL: goto x86_l_b09;
	case 2830ULL: goto x86_l_b0e;
	case 2834ULL: goto x86_l_b12;
	case 2845ULL: goto x86_l_b1d;
	case 2850ULL: goto x86_l_b22;
	case 2855ULL: goto x86_l_b27;
	case 2862ULL: goto x86_l_b2e;
	case 2864ULL: goto x86_l_b30;
	case 2867ULL: goto x86_l_b33;
	case 2873ULL: goto x86_l_b39;
	case 2878ULL: goto x86_l_b3e;
	case 2881ULL: goto x86_l_b41;
	case 2887ULL: goto x86_l_b47;
	case 2892ULL: goto x86_l_b4c;
	case 2897ULL: goto x86_l_b51;
	case 2902ULL: goto x86_l_b56;
	case 2909ULL: goto x86_l_b5d;
	case 2911ULL: goto x86_l_b5f;
	case 2914ULL: goto x86_l_b62;
	case 2920ULL: goto x86_l_b68;
	case 2923ULL: goto x86_l_b6b;
	case 2926ULL: goto x86_l_b6e;
	case 2931ULL: goto x86_l_b73;
	case 2934ULL: goto x86_l_b76;
	case 2937ULL: goto x86_l_b79;
	case 2939ULL: goto x86_l_b7b;
	case 2942ULL: goto x86_l_b7e;
	case 2945ULL: goto x86_l_b81;
	case 2950ULL: goto x86_l_b86;
	case 2953ULL: goto x86_l_b89;
	case 2956ULL: goto x86_l_b8c;
	case 2961ULL: goto x86_l_b91;
	case 2965ULL: goto x86_l_b95;
	case 2971ULL: goto x86_l_b9b;
	case 2974ULL: goto x86_l_b9e;
	case 2978ULL: goto x86_l_ba2;
	case 2984ULL: goto x86_l_ba8;
	case 2987ULL: goto x86_l_bab;
	case 2991ULL: goto x86_l_baf;
	case 2994ULL: goto x86_l_bb2;
	case 2997ULL: goto x86_l_bb5;
	case 3001ULL: goto x86_l_bb9;
	case 3005ULL: goto x86_l_bbd;
	case 3011ULL: goto x86_l_bc3;
	case 3016ULL: goto x86_l_bc8;
	case 3020ULL: goto x86_l_bcc;
	case 3023ULL: goto x86_l_bcf;
	case 3025ULL: goto x86_l_bd1;
	case 3029ULL: goto x86_l_bd5;
	case 3035ULL: goto x86_l_bdb;
	case 3040ULL: goto x86_l_be0;
	case 3044ULL: goto x86_l_be4;
	case 3047ULL: goto x86_l_be7;
	case 3049ULL: goto x86_l_be9;
	case 3053ULL: goto x86_l_bed;
	case 3059ULL: goto x86_l_bf3;
	case 3064ULL: goto x86_l_bf8;
	case 3068ULL: goto x86_l_bfc;
	case 3071ULL: goto x86_l_bff;
	case 3073ULL: goto x86_l_c01;
	case 3077ULL: goto x86_l_c05;
	case 3079ULL: goto x86_l_c07;
	case 3083ULL: goto x86_l_c0b;
	case 3089ULL: goto x86_l_c11;
	case 3094ULL: goto x86_l_c16;
	case 3097ULL: goto x86_l_c19;
	case 3101ULL: goto x86_l_c1d;
	case 3105ULL: goto x86_l_c21;
	case 3108ULL: goto x86_l_c24;
	case 3110ULL: goto x86_l_c26;
	case 3115ULL: goto x86_l_c2b;
	case 3120ULL: goto x86_l_c30;
	case 3125ULL: goto x86_l_c35;
	case 3127ULL: goto x86_l_c37;
	case 3129ULL: goto x86_l_c39;
	case 3132ULL: goto x86_l_c3c;
	case 3135ULL: goto x86_l_c3f;
	case 3140ULL: goto x86_l_c44;
	case 3145ULL: goto x86_l_c49;
	case 3150ULL: goto x86_l_c4e;
	case 3155ULL: goto x86_l_c53;
	case 3159ULL: goto x86_l_c57;
	case 3170ULL: goto x86_l_c62;
	case 3175ULL: goto x86_l_c67;
	case 3180ULL: goto x86_l_c6c;
	case 3187ULL: goto x86_l_c73;
	case 3189ULL: goto x86_l_c75;
	case 3192ULL: goto x86_l_c78;
	case 3194ULL: goto x86_l_c7a;
	case 3199ULL: goto x86_l_c7f;
	case 3202ULL: goto x86_l_c82;
	case 3204ULL: goto x86_l_c84;
	case 3209ULL: goto x86_l_c89;
	case 3214ULL: goto x86_l_c8e;
	case 3219ULL: goto x86_l_c93;
	case 3226ULL: goto x86_l_c9a;
	case 3228ULL: goto x86_l_c9c;
	case 3231ULL: goto x86_l_c9f;
	case 3233ULL: goto x86_l_ca1;
	case 3236ULL: goto x86_l_ca4;
	case 3240ULL: goto x86_l_ca8;
	case 3244ULL: goto x86_l_cac;
	case 3250ULL: goto x86_l_cb2;
	case 3255ULL: goto x86_l_cb7;
	case 3258ULL: goto x86_l_cba;
	case 3265ULL: goto x86_l_cc1;
	case 3267ULL: goto x86_l_cc3;
	case 3270ULL: goto x86_l_cc6;
	case 3274ULL: goto x86_l_cca;
	case 3279ULL: goto x86_l_ccf;
	case 3281ULL: goto x86_l_cd1;
	case 3286ULL: goto x86_l_cd6;
	case 3291ULL: goto x86_l_cdb;
	case 3294ULL: goto x86_l_cde;
	case 3296ULL: goto x86_l_ce0;
	case 3298ULL: goto x86_l_ce2;
	case 3301ULL: goto x86_l_ce5;
	case 3304ULL: goto x86_l_ce8;
	case 3306ULL: goto x86_l_cea;
	case 3308ULL: goto x86_l_cec;
	case 3313ULL: goto x86_l_cf1;
	case 3318ULL: goto x86_l_cf6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6b7:
	/* 0x6b7: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6bb:
	/* 0x6bb: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_6c6:
	/* 0x6c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6cb:
	/* 0x6cb: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6d0:
	/* 0x6d0: mov    rdi,QWORD PTR [rip+0x1eabc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_6d7:
	/* 0x6d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d9:
	/* 0x6d9: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_6dc:
	/* 0x6dc: je     2f47 <generic_usdt_filter_arg+0x2f47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12103ULL;
	}
x86_l_6e2:
	/* 0x6e2: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_6e7:
	/* 0x6e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6ea:
	/* 0x6ea: je     2f49 <generic_usdt_filter_arg+0x2f49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12105ULL;
	}
x86_l_6f0:
	/* 0x6f0: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6f5:
	/* 0x6f5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6fa:
	/* 0x6fa: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6ff:
	/* 0x6ff: mov    rdi,QWORD PTR [rip+0x1eabc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_706:
	/* 0x706: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_708:
	/* 0x708: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_70b:
	/* 0x70b: je     2f47 <generic_usdt_filter_arg+0x2f47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12103ULL;
	}
x86_l_711:
	/* 0x711: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_714:
	/* 0x714: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_717:
	/* 0x717: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_71c:
	/* 0x71c: cmovb  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_71f:
	/* 0x71f: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_722:
	/* 0x722: mov    DWORD PTR [rdi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_724:
	/* 0x724: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_727:
	/* 0x727: neg    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_72a:
	/* 0x72a: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_72f:
	/* 0x72f: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_732:
	/* 0x732: lea    edx,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_735:
	/* 0x735: mov    QWORD PTR [rsp+0x60],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_73a:
	/* 0x73a: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_73e:
	/* 0x73e: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_744:
	/* 0x744: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_747:
	/* 0x747: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_74b:
	/* 0x74b: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_751:
	/* 0x751: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_754:
	/* 0x754: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_758:
	/* 0x758: lea    ebx,[rbp-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_75b:
	/* 0x75b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_75e:
	/* 0x75e: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_762:
	/* 0x762: lea    ebp,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_766:
	/* 0x766: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_76c:
	/* 0x76c: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_770:
	/* 0x770: mov    BYTE PTR [rdi-0x3],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_774:
	/* 0x774: cmp    r10,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_R13, X86_WIDTH_64);
x86_l_777:
	/* 0x777: je     7cb <generic_usdt_filter_arg+0x7cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7cb;
	}
x86_l_779:
	/* 0x779: lea    ebp,[r11+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_77d:
	/* 0x77d: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_783:
	/* 0x783: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_787:
	/* 0x787: mov    BYTE PTR [rdi-0x2],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_78b:
	/* 0x78b: cmp    r8,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R13, X86_WIDTH_64);
x86_l_78e:
	/* 0x78e: je     7cb <generic_usdt_filter_arg+0x7cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7cb;
	}
x86_l_790:
	/* 0x790: lea    ebp,[r9+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_794:
	/* 0x794: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_79a:
	/* 0x79a: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_79e:
	/* 0x79e: mov    BYTE PTR [rdi-0x1],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_7a2:
	/* 0x7a2: cmp    rcx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_7a5:
	/* 0x7a5: je     7cb <generic_usdt_filter_arg+0x7cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7cb;
	}
x86_l_7a7:
	/* 0x7a7: cmp    r13,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_7ab:
	/* 0x7ab: je     7cb <generic_usdt_filter_arg+0x7cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7cb;
	}
x86_l_7ad:
	/* 0x7ad: lea    ebp,[rdx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_7b1:
	/* 0x7b1: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7b7:
	/* 0x7b7: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_7bb:
	/* 0x7bb: mov    BYTE PTR [rdi],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7be:
	/* 0x7be: add    r13,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_7c2:
	/* 0x7c2: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_7c6:
	/* 0x7c6: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_7c9:
	/* 0x7c9: jne    762 <generic_usdt_filter_arg+0x762> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_762;
	}
x86_l_7cb:
	/* 0x7cb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7d0:
	/* 0x7d0: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7d5:
	/* 0x7d5: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7da:
	/* 0x7da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7dc:
	/* 0x7dc: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7de:
	/* 0x7de: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7e1:
	/* 0x7e1: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_7e4:
	/* 0x7e4: mov    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_7e9:
	/* 0x7e9: jmp    2f49 <generic_usdt_filter_arg+0x2f49> */
	return 12105ULL;
x86_l_7ee:
	/* 0x7ee: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_7f1:
	/* 0x7f1: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_7f7:
	/* 0x7f7: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_7fa:
	/* 0x7fa: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_7fe:
	/* 0x7fe: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_802:
	/* 0x802: mov    ebp,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_804:
	/* 0x804: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_806:
	/* 0x806: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_809:
	/* 0x809: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_80c:
	/* 0x80c: je     816 <generic_usdt_filter_arg+0x816> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_816;
	}
x86_l_80e:
	/* 0x80e: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_810:
	/* 0x810: je     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 269ULL;
	}
x86_l_816:
	/* 0x816: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_819:
	/* 0x819: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_81d:
	/* 0x81d: ja     92d <generic_usdt_filter_arg+0x92d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_92d;
	}
x86_l_823:
	/* 0x823: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_825:
	/* 0x825: mov    edx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 67109120ULL);
x86_l_82a:
	/* 0x82a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_82e:
	/* 0x82e: jb     c49 <generic_usdt_filter_arg+0xc49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c49;
	}
x86_l_834:
	/* 0x834: mov    edx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 134218240ULL);
x86_l_839:
	/* 0x839: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_83d:
	/* 0x83d: jb     b04 <generic_usdt_filter_arg+0xb04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b04;
	}
x86_l_843:
	/* 0x843: movabs rdx,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 206158430208ULL);
x86_l_84d:
	/* 0x84d: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_851:
	/* 0x851: jae    92d <generic_usdt_filter_arg+0x92d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_92d;
	}
x86_l_857:
	/* 0x857: mov    WORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_85e:
	/* 0x85e: cmp    ebp,0x1fe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 510ULL);
x86_l_864:
	/* 0x864: ja     9a0 <generic_usdt_filter_arg+0x9a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_9a0;
	}
x86_l_86a:
	/* 0x86a: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_86f:
	/* 0x86f: lea    rcx,[rsi+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_873:
	/* 0x873: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_877:
	/* 0x877: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_87c:
	/* 0x87c: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_881:
	/* 0x881: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_886:
	/* 0x886: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_888:
	/* 0x888: lea    rdx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_88c:
	/* 0x88c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_890:
	/* 0x890: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_895:
	/* 0x895: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_897:
	/* 0x897: mov    ecx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_89c:
	/* 0x89c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_89e:
	/* 0x89e: je     cea <generic_usdt_filter_arg+0xcea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cea;
	}
x86_l_8a4:
	/* 0x8a4: movzx  eax,WORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_8a9:
	/* 0x8a9: and    eax,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_8ae:
	/* 0x8ae: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_8b3:
	/* 0x8b3: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_8b5:
	/* 0x8b5: je     cec <generic_usdt_filter_arg+0xcec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cec;
	}
x86_l_8bb:
	/* 0x8bb: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8c0:
	/* 0x8c0: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_8c3:
	/* 0x8c3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8c8:
	/* 0x8c8: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8cd:
	/* 0x8cd: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8d2:
	/* 0x8d2: jb     9a0 <generic_usdt_filter_arg+0x9a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_9a0;
	}
x86_l_8d8:
	/* 0x8d8: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_8dd:
	/* 0x8dd: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_8df:
	/* 0x8df: je     9a0 <generic_usdt_filter_arg+0x9a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9a0;
	}
x86_l_8e5:
	/* 0x8e5: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_8e7:
	/* 0x8e7: je     cfb <generic_usdt_filter_arg+0xcfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3323ULL;
	}
x86_l_8ed:
	/* 0x8ed: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_8f0:
	/* 0x8f0: jb     9a0 <generic_usdt_filter_arg+0x9a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_9a0;
	}
x86_l_8f6:
	/* 0x8f6: mov    edx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8fb:
	/* 0x8fb: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_8fd:
	/* 0x8fd: je     9a0 <generic_usdt_filter_arg+0x9a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9a0;
	}
x86_l_903:
	/* 0x903: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_905:
	/* 0x905: je     cfb <generic_usdt_filter_arg+0xcfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3323ULL;
	}
x86_l_90b:
	/* 0x90b: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_90e:
	/* 0x90e: jb     3282 <generic_usdt_filter_arg+0x3282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12930ULL;
	}
x86_l_914:
	/* 0x914: mov    ecx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_919:
	/* 0x919: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_91b:
	/* 0x91b: je     3282 <generic_usdt_filter_arg+0x3282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12930ULL;
	}
x86_l_921:
	/* 0x921: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_923:
	/* 0x923: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_925:
	/* 0x925: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_928:
	/* 0x928: jmp    3284 <generic_usdt_filter_arg+0x3284> */
	return 12932ULL;
x86_l_92d:
	/* 0x92d: add    eax,0xfffffffd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967293ULL);
x86_l_930:
	/* 0x930: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_933:
	/* 0x933: jae    9a0 <generic_usdt_filter_arg+0x9a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9a0;
	}
x86_l_935:
	/* 0x935: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_940:
	/* 0x940: cmp    ebp,0x1fe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 510ULL);
x86_l_946:
	/* 0x946: jbe    12fb <generic_usdt_filter_arg+0x12fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 4859ULL;
	}
x86_l_94c:
	/* 0x94c: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_94e:
	/* 0x94e: mov    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_953:
	/* 0x953: jmp    cfb <generic_usdt_filter_arg+0xcfb> */
	return 3323ULL;
x86_l_958:
	/* 0x958: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_95b:
	/* 0x95b: ja     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 269ULL;
	}
x86_l_961:
	/* 0x961: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_963:
	/* 0x963: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_968:
	/* 0x968: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_96c:
	/* 0x96c: jae    1237 <generic_usdt_filter_arg+0x1237> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4663ULL;
	}
x86_l_972:
	/* 0x972: mov    ecx,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_977:
	/* 0x977: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_97a:
	/* 0x97a: jle    1730 <generic_usdt_filter_arg+0x1730> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5936ULL;
	}
x86_l_980:
	/* 0x980: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_983:
	/* 0x983: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_986:
	/* 0x986: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_98a:
	/* 0x98a: jae    1d3c <generic_usdt_filter_arg+0x1d3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7484ULL;
	}
x86_l_990:
	/* 0x990: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_993:
	/* 0x993: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_995:
	/* 0x995: jne    2077 <generic_usdt_filter_arg+0x2077> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8311ULL;
	}
x86_l_99b:
	/* 0x99b: jmp    31a4 <generic_usdt_filter_arg+0x31a4> */
	return 12708ULL;
x86_l_9a0:
	/* 0x9a0: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9a2:
	/* 0x9a2: jmp    cfb <generic_usdt_filter_arg+0xcfb> */
	return 3323ULL;
x86_l_9a7:
	/* 0x9a7: lea    edx,[rax-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_9aa:
	/* 0x9aa: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_9ad:
	/* 0x9ad: jb     a0d <generic_usdt_filter_arg+0xa0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_a0d;
	}
x86_l_9af:
	/* 0x9af: jmp    10d <generic_usdt_filter_arg+0x10d> */
	return 269ULL;
x86_l_9b4:
	/* 0x9b4: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9b7:
	/* 0x9b7: je     14c6 <generic_usdt_filter_arg+0x14c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5318ULL;
	}
x86_l_9bd:
	/* 0x9bd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9c0:
	/* 0x9c0: jne    22a9 <generic_usdt_filter_arg+0x22a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8873ULL;
	}
x86_l_9c6:
	/* 0x9c6: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_9c9:
	/* 0x9c9: ja     229d <generic_usdt_filter_arg+0x229d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8861ULL;
	}
x86_l_9cf:
	/* 0x9cf: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_9d4:
	/* 0x9d4: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_9d7:
	/* 0x9d7: jae    229d <generic_usdt_filter_arg+0x229d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8861ULL;
	}
x86_l_9dd:
	/* 0x9dd: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9e1:
	/* 0x9e1: cmp    DWORD PTR [rsi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9e3:
	/* 0x9e3: jl     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 716ULL;
	}
x86_l_9e9:
	/* 0x9e9: jmp    22a9 <generic_usdt_filter_arg+0x22a9> */
	return 8873ULL;
x86_l_9ee:
	/* 0x9ee: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_9f1:
	/* 0x9f1: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_9f7:
	/* 0x9f7: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_9fa:
	/* 0x9fa: ja     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 269ULL;
	}
x86_l_a00:
	/* 0xa00: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_a02:
	/* 0xa02: mov    esi,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4126ULL);
x86_l_a07:
	/* 0xa07: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_a0b:
	/* 0xa0b: jae    a35 <generic_usdt_filter_arg+0xa35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_a35;
	}
x86_l_a0d:
	/* 0xa0d: mov    rdx,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a12:
	/* 0xa12: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a15:
	/* 0xa15: jle    a59 <generic_usdt_filter_arg+0xa59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_a59;
	}
x86_l_a17:
	/* 0xa17: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_a1a:
	/* 0xa1a: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_a1d:
	/* 0xa1d: jae    d70 <generic_usdt_filter_arg+0xd70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3440ULL;
	}
x86_l_a23:
	/* 0xa23: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a27:
	/* 0xa27: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a2a:
	/* 0xa2a: jne    1c96 <generic_usdt_filter_arg+0x1c96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7318ULL;
	}
x86_l_a30:
	/* 0xa30: jmp    31a4 <generic_usdt_filter_arg+0x31a4> */
	return 12708ULL;
x86_l_a35:
	/* 0xa35: mov    esi,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 3072ULL);
x86_l_a3a:
	/* 0xa3a: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_a3e:
	/* 0xa3e: jb     a8b <generic_usdt_filter_arg+0xa8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_a8b;
	}
x86_l_a40:
	/* 0xa40: movabs rsi,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 6442450944ULL);
x86_l_a4a:
	/* 0xa4a: bt     rsi,rdx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_a4e:
	/* 0xa4e: jb     e44 <generic_usdt_filter_arg+0xe44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3652ULL;
	}
x86_l_a54:
	/* 0xa54: jmp    10d <generic_usdt_filter_arg+0x10d> */
	return 269ULL;
x86_l_a59:
	/* 0xa59: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a5c:
	/* 0xa5c: je     12db <generic_usdt_filter_arg+0x12db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4827ULL;
	}
x86_l_a62:
	/* 0xa62: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a65:
	/* 0xa65: jne    1c96 <generic_usdt_filter_arg+0x1c96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7318ULL;
	}
x86_l_a6b:
	/* 0xa6b: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_a6e:
	/* 0xa6e: je     a79 <generic_usdt_filter_arg+0xa79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a79;
	}
x86_l_a70:
	/* 0xa70: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_a73:
	/* 0xa73: jne    1c89 <generic_usdt_filter_arg+0x1c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7305ULL;
	}
x86_l_a79:
	/* 0xa79: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a7d:
	/* 0xa7d: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a80:
	/* 0xa80: jl     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 716ULL;
	}
x86_l_a86:
	/* 0xa86: jmp    1c96 <generic_usdt_filter_arg+0x1c96> */
	return 7318ULL;
x86_l_a8b:
	/* 0xa8b: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_a8e:
	/* 0xa8e: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_a94:
	/* 0xa94: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a9b:
	/* 0xa9b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_aa0:
	/* 0xaa0: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_aa5:
	/* 0xaa5: mov    rdi,QWORD PTR [rip+0x1eabc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_aac:
	/* 0xaac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aae:
	/* 0xaae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ab1:
	/* 0xab1: je     1815 <generic_usdt_filter_arg+0x1815> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6165ULL;
	}
x86_l_ab7:
	/* 0xab7: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_aba:
	/* 0xaba: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_abe:
	/* 0xabe: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ac1:
	/* 0xac1: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ac6:
	/* 0xac6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_acb:
	/* 0xacb: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ad0:
	/* 0xad0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad2:
	/* 0xad2: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ad7:
	/* 0xad7: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_ada:
	/* 0xada: je     1841 <generic_usdt_filter_arg+0x1841> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6209ULL;
	}
x86_l_ae0:
	/* 0xae0: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_ae3:
	/* 0xae3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ae8:
	/* 0xae8: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_aed:
	/* 0xaed: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_af0:
	/* 0xaf0: jne    185c <generic_usdt_filter_arg+0x185c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6236ULL;
	}
x86_l_af6:
	/* 0xaf6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_af9:
	/* 0xaf9: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_afc:
	/* 0xafc: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_aff:
	/* 0xaff: jmp    2bb <generic_usdt_filter_arg+0x2bb> */
	return 699ULL;
x86_l_b04:
	/* 0xb04: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b09:
	/* 0xb09: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b0e:
	/* 0xb0e: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b12:
	/* 0xb12: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_b1d:
	/* 0xb1d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b22:
	/* 0xb22: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b27:
	/* 0xb27: mov    rdi,QWORD PTR [rip+0x1eabc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_b2e:
	/* 0xb2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b30:
	/* 0xb30: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_b33:
	/* 0xb33: je     cea <generic_usdt_filter_arg+0xcea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cea;
	}
x86_l_b39:
	/* 0xb39: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_b3e:
	/* 0xb3e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b41:
	/* 0xb41: je     cec <generic_usdt_filter_arg+0xcec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cec;
	}
x86_l_b47:
	/* 0xb47: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b4c:
	/* 0xb4c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b51:
	/* 0xb51: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b56:
	/* 0xb56: mov    rdi,QWORD PTR [rip+0x1eabc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_b5d:
	/* 0xb5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b5f:
	/* 0xb5f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b62:
	/* 0xb62: je     cea <generic_usdt_filter_arg+0xcea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cea;
	}
x86_l_b68:
	/* 0xb68: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_b6b:
	/* 0xb6b: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_b6e:
	/* 0xb6e: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_b73:
	/* 0xb73: cmovb  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_b76:
	/* 0xb76: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_b79:
	/* 0xb79: mov    DWORD PTR [rdi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b7b:
	/* 0xb7b: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_b7e:
	/* 0xb7e: neg    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_b81:
	/* 0xb81: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b86:
	/* 0xb86: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b89:
	/* 0xb89: lea    edx,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_b8c:
	/* 0xb8c: mov    QWORD PTR [rsp+0x60],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b91:
	/* 0xb91: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_b95:
	/* 0xb95: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_b9b:
	/* 0xb9b: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b9e:
	/* 0xb9e: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_ba2:
	/* 0xba2: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_ba8:
	/* 0xba8: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_bab:
	/* 0xbab: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_baf:
	/* 0xbaf: lea    ebx,[rbp-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_bb2:
	/* 0xbb2: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bb5:
	/* 0xbb5: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bb9:
	/* 0xbb9: lea    ebp,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_bbd:
	/* 0xbbd: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bc3:
	/* 0xbc3: movzx  ebp,BYTE PTR [rsi+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 4ULL);
x86_l_bc8:
	/* 0xbc8: mov    BYTE PTR [rdi-0x3],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_bcc:
	/* 0xbcc: cmp    r10,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_R13, X86_WIDTH_64);
x86_l_bcf:
	/* 0xbcf: je     c26 <generic_usdt_filter_arg+0xc26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c26;
	}
x86_l_bd1:
	/* 0xbd1: lea    ebp,[r11+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_bd5:
	/* 0xbd5: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bdb:
	/* 0xbdb: movzx  ebp,BYTE PTR [rsi+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 4ULL);
x86_l_be0:
	/* 0xbe0: mov    BYTE PTR [rdi-0x2],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_be4:
	/* 0xbe4: cmp    r8,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R13, X86_WIDTH_64);
x86_l_be7:
	/* 0xbe7: je     c26 <generic_usdt_filter_arg+0xc26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c26;
	}
x86_l_be9:
	/* 0xbe9: lea    ebp,[r9+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_bed:
	/* 0xbed: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bf3:
	/* 0xbf3: movzx  ebp,BYTE PTR [rsi+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 4ULL);
x86_l_bf8:
	/* 0xbf8: mov    BYTE PTR [rdi-0x1],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_bfc:
	/* 0xbfc: cmp    rcx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_bff:
	/* 0xbff: je     c26 <generic_usdt_filter_arg+0xc26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c26;
	}
x86_l_c01:
	/* 0xc01: cmp    r13,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_c05:
	/* 0xc05: je     c26 <generic_usdt_filter_arg+0xc26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c26;
	}
x86_l_c07:
	/* 0xc07: lea    ebp,[rdx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_c0b:
	/* 0xc0b: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c11:
	/* 0xc11: movzx  ebp,BYTE PTR [rsi+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 4ULL);
x86_l_c16:
	/* 0xc16: mov    BYTE PTR [rdi],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c19:
	/* 0xc19: add    r13,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_c1d:
	/* 0xc1d: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_c21:
	/* 0xc21: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_c24:
	/* 0xc24: jne    bb9 <generic_usdt_filter_arg+0xbb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bb9;
	}
x86_l_c26:
	/* 0xc26: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c2b:
	/* 0xc2b: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c30:
	/* 0xc30: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c35:
	/* 0xc35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c37:
	/* 0xc37: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c39:
	/* 0xc39: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c3c:
	/* 0xc3c: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_c3f:
	/* 0xc3f: mov    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c44:
	/* 0xc44: jmp    cec <generic_usdt_filter_arg+0xcec> */
	goto x86_l_cec;
x86_l_c49:
	/* 0xc49: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c4e:
	/* 0xc4e: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c53:
	/* 0xc53: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c57:
	/* 0xc57: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_c62:
	/* 0xc62: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c67:
	/* 0xc67: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c6c:
	/* 0xc6c: mov    rdi,QWORD PTR [rip+0x1eabc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_c73:
	/* 0xc73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c75:
	/* 0xc75: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_c78:
	/* 0xc78: je     cea <generic_usdt_filter_arg+0xcea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cea;
	}
x86_l_c7a:
	/* 0xc7a: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_c7f:
	/* 0xc7f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c82:
	/* 0xc82: je     cec <generic_usdt_filter_arg+0xcec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cec;
	}
x86_l_c84:
	/* 0xc84: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c89:
	/* 0xc89: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c8e:
	/* 0xc8e: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c93:
	/* 0xc93: mov    rdi,QWORD PTR [rip+0x1eabc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_c9a:
	/* 0xc9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c9c:
	/* 0xc9c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c9f:
	/* 0xc9f: je     cea <generic_usdt_filter_arg+0xcea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cea;
	}
x86_l_ca1:
	/* 0xca1: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_ca4:
	/* 0xca4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ca8:
	/* 0xca8: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_cac:
	/* 0xcac: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_cb2:
	/* 0xcb2: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_cb7:
	/* 0xcb7: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_cba:
	/* 0xcba: lea    eax,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_cc1:
	/* 0xcc1: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cc3:
	/* 0xcc3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_cc6:
	/* 0xcc6: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_cca:
	/* 0xcca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ccf:
	/* 0xccf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd1:
	/* 0xcd1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cd6:
	/* 0xcd6: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cdb:
	/* 0xcdb: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_cde:
	/* 0xcde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce0:
	/* 0xce0: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ce2:
	/* 0xce2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ce5:
	/* 0xce5: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_ce8:
	/* 0xce8: jmp    cec <generic_usdt_filter_arg+0xcec> */
	goto x86_l_cec;
x86_l_cea:
	/* 0xcea: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cec:
	/* 0xcec: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cf1:
	/* 0xcf1: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cf6:
	/* 0xcf6: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
	return 3323ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_usdt_filter_arg_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3323ULL: goto x86_l_cfb;
	case 3328ULL: goto x86_l_d00;
	case 3332ULL: goto x86_l_d04;
	case 3338ULL: goto x86_l_d0a;
	case 3348ULL: goto x86_l_d14;
	case 3352ULL: goto x86_l_d18;
	case 3358ULL: goto x86_l_d1e;
	case 3362ULL: goto x86_l_d22;
	case 3367ULL: goto x86_l_d27;
	case 3370ULL: goto x86_l_d2a;
	case 3376ULL: goto x86_l_d30;
	case 3383ULL: goto x86_l_d37;
	case 3388ULL: goto x86_l_d3c;
	case 3393ULL: goto x86_l_d41;
	case 3400ULL: goto x86_l_d48;
	case 3402ULL: goto x86_l_d4a;
	case 3405ULL: goto x86_l_d4d;
	case 3411ULL: goto x86_l_d53;
	case 3414ULL: goto x86_l_d56;
	case 3418ULL: goto x86_l_d5a;
	case 3420ULL: goto x86_l_d5c;
	case 3425ULL: goto x86_l_d61;
	case 3430ULL: goto x86_l_d66;
	case 3435ULL: goto x86_l_d6b;
	case 3440ULL: goto x86_l_d70;
	case 3443ULL: goto x86_l_d73;
	case 3449ULL: goto x86_l_d79;
	case 3453ULL: goto x86_l_d7d;
	case 3456ULL: goto x86_l_d80;
	case 3462ULL: goto x86_l_d86;
	case 3467ULL: goto x86_l_d8b;
	case 3470ULL: goto x86_l_d8e;
	case 3475ULL: goto x86_l_d93;
	case 3479ULL: goto x86_l_d97;
	case 3484ULL: goto x86_l_d9c;
	case 3488ULL: goto x86_l_da0;
	case 3493ULL: goto x86_l_da5;
	case 3497ULL: goto x86_l_da9;
	case 3502ULL: goto x86_l_dae;
	case 3507ULL: goto x86_l_db3;
	case 3509ULL: goto x86_l_db5;
	case 3512ULL: goto x86_l_db8;
	case 3514ULL: goto x86_l_dba;
	case 3517ULL: goto x86_l_dbd;
	case 3519ULL: goto x86_l_dbf;
	case 3522ULL: goto x86_l_dc2;
	case 3525ULL: goto x86_l_dc5;
	case 3531ULL: goto x86_l_dcb;
	case 3534ULL: goto x86_l_dce;
	case 3539ULL: goto x86_l_dd3;
	case 3542ULL: goto x86_l_dd6;
	case 3548ULL: goto x86_l_ddc;
	case 3553ULL: goto x86_l_de1;
	case 3556ULL: goto x86_l_de4;
	case 3562ULL: goto x86_l_dea;
	case 3565ULL: goto x86_l_ded;
	case 3571ULL: goto x86_l_df3;
	case 3574ULL: goto x86_l_df6;
	case 3580ULL: goto x86_l_dfc;
	case 3585ULL: goto x86_l_e01;
	case 3588ULL: goto x86_l_e04;
	case 3594ULL: goto x86_l_e0a;
	case 3598ULL: goto x86_l_e0e;
	case 3603ULL: goto x86_l_e13;
	case 3606ULL: goto x86_l_e16;
	case 3612ULL: goto x86_l_e1c;
	case 3615ULL: goto x86_l_e1f;
	case 3621ULL: goto x86_l_e25;
	case 3626ULL: goto x86_l_e2a;
	case 3629ULL: goto x86_l_e2d;
	case 3635ULL: goto x86_l_e33;
	case 3640ULL: goto x86_l_e38;
	case 3643ULL: goto x86_l_e3b;
	case 3646ULL: goto x86_l_e3e;
	case 3652ULL: goto x86_l_e44;
	case 3655ULL: goto x86_l_e47;
	case 3661ULL: goto x86_l_e4d;
	case 3666ULL: goto x86_l_e52;
	case 3671ULL: goto x86_l_e57;
	case 3674ULL: goto x86_l_e5a;
	case 3676ULL: goto x86_l_e5c;
	case 3679ULL: goto x86_l_e5f;
	case 3685ULL: goto x86_l_e65;
	case 3689ULL: goto x86_l_e69;
	case 3692ULL: goto x86_l_e6c;
	case 3695ULL: goto x86_l_e6f;
	case 3701ULL: goto x86_l_e75;
	case 3704ULL: goto x86_l_e78;
	case 3710ULL: goto x86_l_e7e;
	case 3715ULL: goto x86_l_e83;
	case 3718ULL: goto x86_l_e86;
	case 3724ULL: goto x86_l_e8c;
	case 3729ULL: goto x86_l_e91;
	case 3732ULL: goto x86_l_e94;
	case 3738ULL: goto x86_l_e9a;
	case 3742ULL: goto x86_l_e9e;
	case 3744ULL: goto x86_l_ea0;
	case 3747ULL: goto x86_l_ea3;
	case 3750ULL: goto x86_l_ea6;
	case 3755ULL: goto x86_l_eab;
	case 3759ULL: goto x86_l_eaf;
	case 3764ULL: goto x86_l_eb4;
	case 3769ULL: goto x86_l_eb9;
	case 3776ULL: goto x86_l_ec0;
	case 3778ULL: goto x86_l_ec2;
	case 3781ULL: goto x86_l_ec5;
	case 3787ULL: goto x86_l_ecb;
	case 3790ULL: goto x86_l_ece;
	case 3793ULL: goto x86_l_ed1;
	case 3798ULL: goto x86_l_ed6;
	case 3800ULL: goto x86_l_ed8;
	case 3804ULL: goto x86_l_edc;
	case 3806ULL: goto x86_l_ede;
	case 3808ULL: goto x86_l_ee0;
	case 3811ULL: goto x86_l_ee3;
	case 3814ULL: goto x86_l_ee6;
	case 3817ULL: goto x86_l_ee9;
	case 3819ULL: goto x86_l_eeb;
	case 3821ULL: goto x86_l_eed;
	case 3825ULL: goto x86_l_ef1;
	case 3828ULL: goto x86_l_ef4;
	case 3830ULL: goto x86_l_ef6;
	case 3834ULL: goto x86_l_efa;
	case 3836ULL: goto x86_l_efc;
	case 3838ULL: goto x86_l_efe;
	case 3843ULL: goto x86_l_f03;
	case 3847ULL: goto x86_l_f07;
	case 3850ULL: goto x86_l_f0a;
	case 3854ULL: goto x86_l_f0e;
	case 3858ULL: goto x86_l_f12;
	case 3862ULL: goto x86_l_f16;
	case 3866ULL: goto x86_l_f1a;
	case 3869ULL: goto x86_l_f1d;
	case 3873ULL: goto x86_l_f21;
	case 3877ULL: goto x86_l_f25;
	case 3881ULL: goto x86_l_f29;
	case 3885ULL: goto x86_l_f2d;
	case 3887ULL: goto x86_l_f2f;
	case 3890ULL: goto x86_l_f32;
	case 3893ULL: goto x86_l_f35;
	case 3895ULL: goto x86_l_f37;
	case 3897ULL: goto x86_l_f39;
	case 3899ULL: goto x86_l_f3b;
	case 3905ULL: goto x86_l_f41;
	case 3909ULL: goto x86_l_f45;
	case 3914ULL: goto x86_l_f4a;
	case 3916ULL: goto x86_l_f4c;
	case 3920ULL: goto x86_l_f50;
	case 3923ULL: goto x86_l_f53;
	case 3927ULL: goto x86_l_f57;
	case 3933ULL: goto x86_l_f5d;
	case 3935ULL: goto x86_l_f5f;
	case 3940ULL: goto x86_l_f64;
	case 3944ULL: goto x86_l_f68;
	case 3949ULL: goto x86_l_f6d;
	case 3954ULL: goto x86_l_f72;
	case 3958ULL: goto x86_l_f76;
	case 3969ULL: goto x86_l_f81;
	case 3974ULL: goto x86_l_f86;
	case 3979ULL: goto x86_l_f8b;
	case 3986ULL: goto x86_l_f92;
	case 3988ULL: goto x86_l_f94;
	case 3991ULL: goto x86_l_f97;
	case 3997ULL: goto x86_l_f9d;
	case 4002ULL: goto x86_l_fa2;
	case 4005ULL: goto x86_l_fa5;
	case 4011ULL: goto x86_l_fab;
	case 4016ULL: goto x86_l_fb0;
	case 4021ULL: goto x86_l_fb5;
	case 4026ULL: goto x86_l_fba;
	case 4033ULL: goto x86_l_fc1;
	case 4035ULL: goto x86_l_fc3;
	case 4038ULL: goto x86_l_fc6;
	case 4044ULL: goto x86_l_fcc;
	case 4050ULL: goto x86_l_fd2;
	case 4055ULL: goto x86_l_fd7;
	case 4058ULL: goto x86_l_fda;
	case 4065ULL: goto x86_l_fe1;
	case 4067ULL: goto x86_l_fe3;
	case 4070ULL: goto x86_l_fe6;
	case 4074ULL: goto x86_l_fea;
	case 4077ULL: goto x86_l_fed;
	case 4082ULL: goto x86_l_ff2;
	case 4086ULL: goto x86_l_ff6;
	case 4088ULL: goto x86_l_ff8;
	case 4090ULL: goto x86_l_ffa;
	case 4095ULL: goto x86_l_fff;
	case 4100ULL: goto x86_l_1004;
	case 4103ULL: goto x86_l_1007;
	case 4108ULL: goto x86_l_100c;
	case 4119ULL: goto x86_l_1017;
	case 4125ULL: goto x86_l_101d;
	case 4131ULL: goto x86_l_1023;
	case 4133ULL: goto x86_l_1025;
	case 4138ULL: goto x86_l_102a;
	case 4142ULL: goto x86_l_102e;
	case 4148ULL: goto x86_l_1034;
	case 4153ULL: goto x86_l_1039;
	case 4158ULL: goto x86_l_103e;
	case 4163ULL: goto x86_l_1043;
	case 4166ULL: goto x86_l_1046;
	case 4168ULL: goto x86_l_1048;
	case 4171ULL: goto x86_l_104b;
	case 4177ULL: goto x86_l_1051;
	case 4181ULL: goto x86_l_1055;
	case 4184ULL: goto x86_l_1058;
	case 4187ULL: goto x86_l_105b;
	case 4191ULL: goto x86_l_105f;
	case 4194ULL: goto x86_l_1062;
	case 4197ULL: goto x86_l_1065;
	case 4202ULL: goto x86_l_106a;
	case 4205ULL: goto x86_l_106d;
	case 4211ULL: goto x86_l_1073;
	case 4214ULL: goto x86_l_1076;
	case 4220ULL: goto x86_l_107c;
	case 4225ULL: goto x86_l_1081;
	case 4228ULL: goto x86_l_1084;
	case 4234ULL: goto x86_l_108a;
	case 4239ULL: goto x86_l_108f;
	case 4242ULL: goto x86_l_1092;
	case 4246ULL: goto x86_l_1096;
	case 4252ULL: goto x86_l_109c;
	case 4255ULL: goto x86_l_109f;
	case 4261ULL: goto x86_l_10a5;
	case 4266ULL: goto x86_l_10aa;
	case 4269ULL: goto x86_l_10ad;
	case 4275ULL: goto x86_l_10b3;
	case 4280ULL: goto x86_l_10b8;
	case 4285ULL: goto x86_l_10bd;
	case 4289ULL: goto x86_l_10c1;
	case 4300ULL: goto x86_l_10cc;
	case 4305ULL: goto x86_l_10d1;
	case 4310ULL: goto x86_l_10d6;
	case 4317ULL: goto x86_l_10dd;
	case 4319ULL: goto x86_l_10df;
	case 4322ULL: goto x86_l_10e2;
	case 4328ULL: goto x86_l_10e8;
	case 4331ULL: goto x86_l_10eb;
	case 4336ULL: goto x86_l_10f0;
	case 4339ULL: goto x86_l_10f3;
	case 4345ULL: goto x86_l_10f9;
	case 4350ULL: goto x86_l_10fe;
	case 4355ULL: goto x86_l_1103;
	case 4362ULL: goto x86_l_110a;
	case 4364ULL: goto x86_l_110c;
	case 4367ULL: goto x86_l_110f;
	case 4373ULL: goto x86_l_1115;
	case 4376ULL: goto x86_l_1118;
	case 4381ULL: goto x86_l_111d;
	case 4384ULL: goto x86_l_1120;
	case 4389ULL: goto x86_l_1125;
	case 4392ULL: goto x86_l_1128;
	case 4395ULL: goto x86_l_112b;
	case 4397ULL: goto x86_l_112d;
	case 4400ULL: goto x86_l_1130;
	case 4403ULL: goto x86_l_1133;
	case 4408ULL: goto x86_l_1138;
	case 4411ULL: goto x86_l_113b;
	case 4414ULL: goto x86_l_113e;
	case 4419ULL: goto x86_l_1143;
	case 4423ULL: goto x86_l_1147;
	case 4429ULL: goto x86_l_114d;
	case 4432ULL: goto x86_l_1150;
	case 4436ULL: goto x86_l_1154;
	case 4442ULL: goto x86_l_115a;
	case 4445ULL: goto x86_l_115d;
	case 4449ULL: goto x86_l_1161;
	case 4452ULL: goto x86_l_1164;
	case 4455ULL: goto x86_l_1167;
	case 4459ULL: goto x86_l_116b;
	case 4463ULL: goto x86_l_116f;
	case 4469ULL: goto x86_l_1175;
	case 4473ULL: goto x86_l_1179;
	case 4477ULL: goto x86_l_117d;
	case 4480ULL: goto x86_l_1180;
	case 4482ULL: goto x86_l_1182;
	case 4486ULL: goto x86_l_1186;
	case 4492ULL: goto x86_l_118c;
	case 4496ULL: goto x86_l_1190;
	case 4500ULL: goto x86_l_1194;
	case 4503ULL: goto x86_l_1197;
	case 4505ULL: goto x86_l_1199;
	case 4509ULL: goto x86_l_119d;
	case 4515ULL: goto x86_l_11a3;
	case 4519ULL: goto x86_l_11a7;
	case 4523ULL: goto x86_l_11ab;
	case 4526ULL: goto x86_l_11ae;
	case 4528ULL: goto x86_l_11b0;
	case 4532ULL: goto x86_l_11b4;
	case 4534ULL: goto x86_l_11b6;
	case 4538ULL: goto x86_l_11ba;
	case 4544ULL: goto x86_l_11c0;
	case 4548ULL: goto x86_l_11c4;
	case 4551ULL: goto x86_l_11c7;
	case 4555ULL: goto x86_l_11cb;
	case 4559ULL: goto x86_l_11cf;
	case 4562ULL: goto x86_l_11d2;
	case 4564ULL: goto x86_l_11d4;
	case 4569ULL: goto x86_l_11d9;
	case 4574ULL: goto x86_l_11de;
	case 4579ULL: goto x86_l_11e3;
	case 4584ULL: goto x86_l_11e8;
	case 4587ULL: goto x86_l_11eb;
	case 4593ULL: goto x86_l_11f1;
	case 4597ULL: goto x86_l_11f5;
	case 4599ULL: goto x86_l_11f7;
	case 4605ULL: goto x86_l_11fd;
	case 4610ULL: goto x86_l_1202;
	case 4615ULL: goto x86_l_1207;
	case 4619ULL: goto x86_l_120b;
	case 4625ULL: goto x86_l_1211;
	case 4635ULL: goto x86_l_121b;
	case 4639ULL: goto x86_l_121f;
	case 4645ULL: goto x86_l_1225;
	case 4648ULL: goto x86_l_1228;
	case 4654ULL: goto x86_l_122e;
	case 4658ULL: goto x86_l_1232;
	case 4661ULL: goto x86_l_1235;
	case 4663ULL: goto x86_l_1237;
	case 4668ULL: goto x86_l_123c;
	case 4672ULL: goto x86_l_1240;
	case 4678ULL: goto x86_l_1246;
	case 4688ULL: goto x86_l_1250;
	case 4692ULL: goto x86_l_1254;
	case 4698ULL: goto x86_l_125a;
	case 4701ULL: goto x86_l_125d;
	case 4707ULL: goto x86_l_1263;
	case 4711ULL: goto x86_l_1267;
	case 4714ULL: goto x86_l_126a;
	case 4719ULL: goto x86_l_126f;
	case 4721ULL: goto x86_l_1271;
	case 4726ULL: goto x86_l_1276;
	case 4732ULL: goto x86_l_127c;
	case 4737ULL: goto x86_l_1281;
	case 4740ULL: goto x86_l_1284;
	case 4746ULL: goto x86_l_128a;
	case 4751ULL: goto x86_l_128f;
	case 4753ULL: goto x86_l_1291;
	case 4758ULL: goto x86_l_1296;
	case 4764ULL: goto x86_l_129c;
	case 4767ULL: goto x86_l_129f;
	case 4773ULL: goto x86_l_12a5;
	case 4778ULL: goto x86_l_12aa;
	case 4780ULL: goto x86_l_12ac;
	case 4785ULL: goto x86_l_12b1;
	case 4791ULL: goto x86_l_12b7;
	case 4794ULL: goto x86_l_12ba;
	case 4800ULL: goto x86_l_12c0;
	case 4805ULL: goto x86_l_12c5;
	case 4811ULL: goto x86_l_12cb;
	case 4816ULL: goto x86_l_12d0;
	case 4822ULL: goto x86_l_12d6;
	case 4827ULL: goto x86_l_12db;
	case 4830ULL: goto x86_l_12de;
	case 4832ULL: goto x86_l_12e0;
	case 4835ULL: goto x86_l_12e3;
	case 4841ULL: goto x86_l_12e9;
	case 4845ULL: goto x86_l_12ed;
	case 4848ULL: goto x86_l_12f0;
	case 4854ULL: goto x86_l_12f6;
	case 4859ULL: goto x86_l_12fb;
	case 4862ULL: goto x86_l_12fe;
	case 4867ULL: goto x86_l_1303;
	case 4872ULL: goto x86_l_1308;
	case 4878ULL: goto x86_l_130e;
	case 4882ULL: goto x86_l_1312;
	case 4888ULL: goto x86_l_1318;
	case 4891ULL: goto x86_l_131b;
	case 4894ULL: goto x86_l_131e;
	case 4897ULL: goto x86_l_1321;
	case 4899ULL: goto x86_l_1323;
	case 4901ULL: goto x86_l_1325;
	case 4904ULL: goto x86_l_1328;
	case 4906ULL: goto x86_l_132a;
	case 4908ULL: goto x86_l_132c;
	case 4910ULL: goto x86_l_132e;
	case 4912ULL: goto x86_l_1330;
	case 4915ULL: goto x86_l_1333;
	case 4917ULL: goto x86_l_1335;
	case 4919ULL: goto x86_l_1337;
	case 4921ULL: goto x86_l_1339;
	case 4924ULL: goto x86_l_133c;
	case 4928ULL: goto x86_l_1340;
	case 4934ULL: goto x86_l_1346;
	default: return 0xffffffffffffffffULL;
	}
x86_l_cfb:
	/* 0xcfb: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d00:
	/* 0xd00: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_d04:
	/* 0xd04: ja     2bb <generic_usdt_filter_arg+0x2bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 699ULL;
	}
x86_l_d0a:
	/* 0xd0a: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_d14:
	/* 0xd14: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_d18:
	/* 0xd18: jae    2bb <generic_usdt_filter_arg+0x2bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 699ULL;
	}
x86_l_d1e:
	/* 0xd1e: xor    rbx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_d22:
	/* 0xd22: jmp    2bb <generic_usdt_filter_arg+0x2bb> */
	return 699ULL;
x86_l_d27:
	/* 0xd27: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_d2a:
	/* 0xd2a: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_d30:
	/* 0xd30: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d37:
	/* 0xd37: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d3c:
	/* 0xd3c: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d41:
	/* 0xd41: mov    rdi,QWORD PTR [rip+0x1eabc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_d48:
	/* 0xd48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d4a:
	/* 0xd4a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d4d:
	/* 0xd4d: je     1815 <generic_usdt_filter_arg+0x1815> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6165ULL;
	}
x86_l_d53:
	/* 0xd53: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_d56:
	/* 0xd56: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d5a:
	/* 0xd5a: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d5c:
	/* 0xd5c: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d61:
	/* 0xd61: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d66:
	/* 0xd66: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d6b:
	/* 0xd6b: jmp    17de <generic_usdt_filter_arg+0x17de> */
	return 6110ULL;
x86_l_d70:
	/* 0xd70: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_d73:
	/* 0xd73: jne    1c96 <generic_usdt_filter_arg+0x1c96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7318ULL;
	}
x86_l_d79:
	/* 0xd79: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d7d:
	/* 0xd7d: test   QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d80:
	/* 0xd80: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_d86:
	/* 0xd86: jmp    1c96 <generic_usdt_filter_arg+0x1c96> */
	return 7318ULL;
x86_l_d8b:
	/* 0xd8b: movzx  edx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_d8e:
	/* 0xd8e: mov    WORD PTR [rsp+0x5e],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_d93:
	/* 0xd93: movzx  edx,WORD PTR [rsi+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_d97:
	/* 0xd97: mov    WORD PTR [rsp+0x58],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d9c:
	/* 0xd9c: mov    rdx,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_da0:
	/* 0xda0: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_da5:
	/* 0xda5: mov    rdx,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_da9:
	/* 0xda9: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_dae:
	/* 0xdae: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_db3:
	/* 0xdb3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_db5:
	/* 0xdb5: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_db8:
	/* 0xdb8: jle    de1 <generic_usdt_filter_arg+0xde1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_de1;
	}
x86_l_dba:
	/* 0xdba: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_dbd:
	/* 0xdbd: jg     e13 <generic_usdt_filter_arg+0xe13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_e13;
	}
x86_l_dbf:
	/* 0xdbf: lea    ecx,[rax-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_dc2:
	/* 0xdc2: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_dc5:
	/* 0xdc5: jb     13aa <generic_usdt_filter_arg+0x13aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5034ULL;
	}
x86_l_dcb:
	/* 0xdcb: lea    ecx,[rax-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_dce:
	/* 0xdce: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_dd3:
	/* 0xdd3: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_dd6:
	/* 0xdd6: jb     13a3 <generic_usdt_filter_arg+0x13a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5027ULL;
	}
x86_l_ddc:
	/* 0xddc: jmp    2b6 <generic_usdt_filter_arg+0x2b6> */
	return 694ULL;
x86_l_de1:
	/* 0xde1: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_de4:
	/* 0xde4: jle    106a <generic_usdt_filter_arg+0x106a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_106a;
	}
x86_l_dea:
	/* 0xdea: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_ded:
	/* 0xded: jg     1390 <generic_usdt_filter_arg+0x1390> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5008ULL;
	}
x86_l_df3:
	/* 0xdf3: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_df6:
	/* 0xdf6: je     13a3 <generic_usdt_filter_arg+0x13a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5027ULL;
	}
x86_l_dfc:
	/* 0xdfc: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_e01:
	/* 0xe01: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_e04:
	/* 0xe04: jne    2b6 <generic_usdt_filter_arg+0x2b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 694ULL;
	}
x86_l_e0a:
	/* 0xe0a: movzx  ebx,WORD PTR [rsi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_e0e:
	/* 0xe0e: jmp    1bf3 <generic_usdt_filter_arg+0x1bf3> */
	return 7155ULL;
x86_l_e13:
	/* 0xe13: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_e16:
	/* 0xe16: jg     13e3 <generic_usdt_filter_arg+0x13e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5091ULL;
	}
x86_l_e1c:
	/* 0xe1c: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_e1f:
	/* 0xe1f: je     141d <generic_usdt_filter_arg+0x141d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5149ULL;
	}
x86_l_e25:
	/* 0xe25: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_e2a:
	/* 0xe2a: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_e2d:
	/* 0xe2d: je     1413 <generic_usdt_filter_arg+0x1413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5139ULL;
	}
x86_l_e33:
	/* 0xe33: jmp    2b6 <generic_usdt_filter_arg+0x2b6> */
	return 694ULL;
x86_l_e38:
	/* 0xe38: lea    edx,[rax-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_e3b:
	/* 0xe3b: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_e3e:
	/* 0xe3e: jae    1936 <generic_usdt_filter_arg+0x1936> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 6454ULL;
	}
x86_l_e44:
	/* 0xe44: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_e47:
	/* 0xe47: jne    1039 <generic_usdt_filter_arg+0x1039> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1039;
	}
x86_l_e4d:
	/* 0xe4d: mov    rsi,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e52:
	/* 0xe52: mov    rdx,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e57:
	/* 0xe57: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_e5a:
	/* 0xe5a: je     e65 <generic_usdt_filter_arg+0xe65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e65;
	}
x86_l_e5c:
	/* 0xe5c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_e5f:
	/* 0xe5f: jne    1b48 <generic_usdt_filter_arg+0x1b48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6984ULL;
	}
x86_l_e65:
	/* 0xe65: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e69:
	/* 0xe69: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e6c:
	/* 0xe6c: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_e6f:
	/* 0xe6f: jg     1b5d <generic_usdt_filter_arg+0x1b5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7005ULL;
	}
x86_l_e75:
	/* 0xe75: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_e78:
	/* 0xe78: jle    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 716ULL;
	}
x86_l_e7e:
	/* 0xe7e: jmp    1b5d <generic_usdt_filter_arg+0x1b5d> */
	return 7005ULL;
x86_l_e83:
	/* 0xe83: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_e86:
	/* 0xe86: je     14ee <generic_usdt_filter_arg+0x14ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5358ULL;
	}
x86_l_e8c:
	/* 0xe8c: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_e91:
	/* 0xe91: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_e94:
	/* 0xe94: jne    2f58 <generic_usdt_filter_arg+0x2f58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12120ULL;
	}
x86_l_e9a:
	/* 0xe9a: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e9e:
	/* 0xe9e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ea0:
	/* 0xea0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ea3:
	/* 0xea3: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_ea6:
	/* 0xea6: mov    eax,DWORD PTR [r12+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_eab:
	/* 0xeab: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_eaf:
	/* 0xeaf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_eb4:
	/* 0xeb4: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_eb9:
	/* 0xeb9: mov    rdi,QWORD PTR [rip+0x1eabc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_ec0:
	/* 0xec0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec2:
	/* 0xec2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ec5:
	/* 0xec5: je     2377 <generic_usdt_filter_arg+0x2377> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9079ULL;
	}
x86_l_ecb:
	/* 0xecb: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_ece:
	/* 0xece: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_ed1:
	/* 0xed1: mov    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_ed6:
	/* 0xed6: je     f41 <generic_usdt_filter_arg+0xf41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f41;
	}
x86_l_ed8:
	/* 0xed8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_edc:
	/* 0xedc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ede:
	/* 0xede: jmp    eeb <generic_usdt_filter_arg+0xeeb> */
	goto x86_l_eeb;
x86_l_ee0:
	/* 0xee0: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_ee3:
	/* 0xee3: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_ee6:
	/* 0xee6: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_ee9:
	/* 0xee9: je     f41 <generic_usdt_filter_arg+0xf41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f41;
	}
x86_l_eeb:
	/* 0xeeb: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_eed:
	/* 0xeed: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_ef1:
	/* 0xef1: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_ef4:
	/* 0xef4: jae    ee0 <generic_usdt_filter_arg+0xee0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_ee0;
	}
x86_l_ef6:
	/* 0xef6: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_efa:
	/* 0xefa: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_efc:
	/* 0xefc: je     f39 <generic_usdt_filter_arg+0xf39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f39;
	}
x86_l_efe:
	/* 0xefe: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_f03:
	/* 0xf03: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_f07:
	/* 0xf07: mov    r8d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_32);
x86_l_f0a:
	/* 0xf0a: or     r8d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_f0e:
	/* 0xf0e: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_f12:
	/* 0xf12: cmovae r8d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_f16:
	/* 0xf16: lea    r10d,[rdi-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_f1a:
	/* 0xf1a: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_f1d:
	/* 0xf1d: or     r9d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_f21:
	/* 0xf21: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_f25:
	/* 0xf25: cmovae r9d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE);
x86_l_f29:
	/* 0xf29: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_f2d:
	/* 0xf2d: ja     ee0 <generic_usdt_filter_arg+0xee0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ee0;
	}
x86_l_f2f:
	/* 0xf2f: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_f32:
	/* 0xf32: cmp    r8d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32);
x86_l_f35:
	/* 0xf35: je     eed <generic_usdt_filter_arg+0xeed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eed;
	}
x86_l_f37:
	/* 0xf37: jmp    ee0 <generic_usdt_filter_arg+0xee0> */
	goto x86_l_ee0;
x86_l_f39:
	/* 0xf39: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_f3b:
	/* 0xf3b: jns    265f <generic_usdt_filter_arg+0x265f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 9823ULL;
	}
x86_l_f41:
	/* 0xf41: lea    eax,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f45:
	/* 0xf45: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_f4a:
	/* 0xf4a: jae    f5d <generic_usdt_filter_arg+0xf5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_f5d;
	}
x86_l_f4c:
	/* 0xf4c: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_f50:
	/* 0xf50: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_f53:
	/* 0xf53: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_f57:
	/* 0xf57: jne    ea3 <generic_usdt_filter_arg+0xea3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ea3;
	}
x86_l_f5d:
	/* 0xf5d: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f5f:
	/* 0xf5f: jmp    2664 <generic_usdt_filter_arg+0x2664> */
	return 9828ULL;
x86_l_f64:
	/* 0xf64: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f68:
	/* 0xf68: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f6d:
	/* 0xf6d: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f72:
	/* 0xf72: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f76:
	/* 0xf76: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_f81:
	/* 0xf81: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f86:
	/* 0xf86: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f8b:
	/* 0xf8b: mov    rdi,QWORD PTR [rip+0x1eac3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_f92:
	/* 0xf92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f94:
	/* 0xf94: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_f97:
	/* 0xf97: je     2f47 <generic_usdt_filter_arg+0x2f47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12103ULL;
	}
x86_l_f9d:
	/* 0xf9d: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_fa2:
	/* 0xfa2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fa5:
	/* 0xfa5: je     2f49 <generic_usdt_filter_arg+0x2f49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12105ULL;
	}
x86_l_fab:
	/* 0xfab: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fb0:
	/* 0xfb0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fb5:
	/* 0xfb5: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fba:
	/* 0xfba: mov    rdi,QWORD PTR [rip+0x1eac3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_fc1:
	/* 0xfc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fc3:
	/* 0xfc3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fc6:
	/* 0xfc6: je     2f47 <generic_usdt_filter_arg+0x2f47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12103ULL;
	}
x86_l_fcc:
	/* 0xfcc: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_fd2:
	/* 0xfd2: mov    ecx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_fd7:
	/* 0xfd7: cmovae ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_fda:
	/* 0xfda: lea    ecx,[rbp*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 3), 0ULL);
x86_l_fe1:
	/* 0xfe1: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fe3:
	/* 0xfe3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_fe6:
	/* 0xfe6: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_fea:
	/* 0xfea: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_fed:
	/* 0xfed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ff2:
	/* 0xff2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ff6:
	/* 0xff6: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_ff8:
	/* 0xff8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ffa:
	/* 0xffa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fff:
	/* 0xfff: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1004:
	/* 0x1004: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1007:
	/* 0x1007: jmp    2f3b <generic_usdt_filter_arg+0x2f3b> */
	return 12091ULL;
x86_l_100c:
	/* 0x100c: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1017:
	/* 0x1017: cmp    ebp,0x1fe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 510ULL);
x86_l_101d:
	/* 0x101d: jbe    1598 <generic_usdt_filter_arg+0x1598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 5528ULL;
	}
x86_l_1023:
	/* 0x1023: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1025:
	/* 0x1025: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_102a:
	/* 0x102a: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_102e:
	/* 0x102e: jbe    2f67 <generic_usdt_filter_arg+0x2f67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 12135ULL;
	}
x86_l_1034:
	/* 0x1034: jmp    2bb <generic_usdt_filter_arg+0x2bb> */
	return 699ULL;
x86_l_1039:
	/* 0x1039: mov    rsi,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_103e:
	/* 0x103e: mov    rax,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1043:
	/* 0x1043: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1046:
	/* 0x1046: je     1051 <generic_usdt_filter_arg+0x1051> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1051;
	}
x86_l_1048:
	/* 0x1048: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_104b:
	/* 0x104b: jne    1b9f <generic_usdt_filter_arg+0x1b9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7071ULL;
	}
x86_l_1051:
	/* 0x1051: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1055:
	/* 0x1055: mov    rdx,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1058:
	/* 0x1058: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_105b:
	/* 0x105b: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_105f:
	/* 0x105f: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1062:
	/* 0x1062: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_1065:
	/* 0x1065: jmp    1bb3 <generic_usdt_filter_arg+0x1bb3> */
	return 7091ULL;
x86_l_106a:
	/* 0x106a: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_106d:
	/* 0x106d: je     141d <generic_usdt_filter_arg+0x141d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5149ULL;
	}
x86_l_1073:
	/* 0x1073: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1076:
	/* 0x1076: je     1413 <generic_usdt_filter_arg+0x1413> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5139ULL;
	}
x86_l_107c:
	/* 0x107c: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1081:
	/* 0x1081: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1084:
	/* 0x1084: je     13aa <generic_usdt_filter_arg+0x13aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5034ULL;
	}
x86_l_108a:
	/* 0x108a: jmp    2b6 <generic_usdt_filter_arg+0x2b6> */
	return 694ULL;
x86_l_108f:
	/* 0x108f: cmp    eax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_1092:
	/* 0x1092: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1096:
	/* 0x1096: jg     1677 <generic_usdt_filter_arg+0x1677> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5751ULL;
	}
x86_l_109c:
	/* 0x109c: cmp    eax,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_109f:
	/* 0x109f: je     1866 <generic_usdt_filter_arg+0x1866> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6246ULL;
	}
x86_l_10a5:
	/* 0x10a5: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_10aa:
	/* 0x10aa: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_10ad:
	/* 0x10ad: jne    3216 <generic_usdt_filter_arg+0x3216> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12822ULL;
	}
x86_l_10b3:
	/* 0x10b3: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10b8:
	/* 0x10b8: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10bd:
	/* 0x10bd: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_10c1:
	/* 0x10c1: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_10cc:
	/* 0x10cc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10d1:
	/* 0x10d1: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_10d6:
	/* 0x10d6: mov    rdi,QWORD PTR [rip+0x1eac3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_10dd:
	/* 0x10dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10df:
	/* 0x10df: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_10e2:
	/* 0x10e2: je     3205 <generic_usdt_filter_arg+0x3205> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12805ULL;
	}
x86_l_10e8:
	/* 0x10e8: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_10eb:
	/* 0x10eb: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_10f0:
	/* 0x10f0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10f3:
	/* 0x10f3: je     3207 <generic_usdt_filter_arg+0x3207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12807ULL;
	}
x86_l_10f9:
	/* 0x10f9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10fe:
	/* 0x10fe: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1103:
	/* 0x1103: mov    rdi,QWORD PTR [rip+0x1eac3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_110a:
	/* 0x110a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_110c:
	/* 0x110c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_110f:
	/* 0x110f: je     3205 <generic_usdt_filter_arg+0x3205> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12805ULL;
	}
x86_l_1115:
	/* 0x1115: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1118:
	/* 0x1118: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_111d:
	/* 0x111d: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_1120:
	/* 0x1120: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_1125:
	/* 0x1125: cmovb  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_1128:
	/* 0x1128: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_112b:
	/* 0x112b: mov    DWORD PTR [rdi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_112d:
	/* 0x112d: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_1130:
	/* 0x1130: neg    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1133:
	/* 0x1133: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1138:
	/* 0x1138: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_113b:
	/* 0x113b: lea    edx,[rbp-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_113e:
	/* 0x113e: mov    QWORD PTR [rsp+0x60],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1143:
	/* 0x1143: add    rdi,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_1147:
	/* 0x1147: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_114d:
	/* 0x114d: sub    r8,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1150:
	/* 0x1150: lea    r9d,[rbp-0x3] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1154:
	/* 0x1154: mov    r10d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 1ULL);
x86_l_115a:
	/* 0x115a: sub    r10,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_115d:
	/* 0x115d: lea    r11d,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_1161:
	/* 0x1161: lea    ebx,[rbp-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1164:
	/* 0x1164: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1167:
	/* 0x1167: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_116b:
	/* 0x116b: lea    ebp,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_116f:
	/* 0x116f: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1175:
	/* 0x1175: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_1179:
	/* 0x1179: mov    BYTE PTR [rdi-0x3],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_117d:
	/* 0x117d: cmp    r10,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_R13, X86_WIDTH_64);
x86_l_1180:
	/* 0x1180: je     11d4 <generic_usdt_filter_arg+0x11d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d4;
	}
x86_l_1182:
	/* 0x1182: lea    ebp,[r11+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1186:
	/* 0x1186: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_118c:
	/* 0x118c: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_1190:
	/* 0x1190: mov    BYTE PTR [rdi-0x2],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_1194:
	/* 0x1194: cmp    r8,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R13, X86_WIDTH_64);
x86_l_1197:
	/* 0x1197: je     11d4 <generic_usdt_filter_arg+0x11d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d4;
	}
x86_l_1199:
	/* 0x1199: lea    ebp,[r9+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_119d:
	/* 0x119d: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11a3:
	/* 0x11a3: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_11a7:
	/* 0x11a7: mov    BYTE PTR [rdi-0x1],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_11ab:
	/* 0x11ab: cmp    rcx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_11ae:
	/* 0x11ae: je     11d4 <generic_usdt_filter_arg+0x11d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d4;
	}
x86_l_11b0:
	/* 0x11b0: cmp    r13,0xffffffffffffff84 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551492ULL);
x86_l_11b4:
	/* 0x11b4: je     11d4 <generic_usdt_filter_arg+0x11d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11d4;
	}
x86_l_11b6:
	/* 0x11b6: lea    ebp,[rdx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_11ba:
	/* 0x11ba: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11c0:
	/* 0x11c0: movzx  ebp,BYTE PTR [rsi+rbp*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RBP, 0, X86_WIDTH_8), 0ULL);
x86_l_11c4:
	/* 0x11c4: mov    BYTE PTR [rdi],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11c7:
	/* 0x11c7: add    r13,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_11cb:
	/* 0x11cb: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_11cf:
	/* 0x11cf: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_11d2:
	/* 0x11d2: jne    116b <generic_usdt_filter_arg+0x116b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_116b;
	}
x86_l_11d4:
	/* 0x11d4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11d9:
	/* 0x11d9: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11de:
	/* 0x11de: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_11e3:
	/* 0x11e3: jmp    31f9 <generic_usdt_filter_arg+0x31f9> */
	return 12793ULL;
x86_l_11e8:
	/* 0x11e8: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_11eb:
	/* 0x11eb: jne    22a9 <generic_usdt_filter_arg+0x22a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8873ULL;
	}
x86_l_11f1:
	/* 0x11f1: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11f5:
	/* 0x11f5: test   DWORD PTR [rsi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11f7:
	/* 0x11f7: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_11fd:
	/* 0x11fd: jmp    22a9 <generic_usdt_filter_arg+0x22a9> */
	return 8873ULL;
x86_l_1202:
	/* 0x1202: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_1207:
	/* 0x1207: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_120b:
	/* 0x120b: jb     1756 <generic_usdt_filter_arg+0x1756> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5974ULL;
	}
x86_l_1211:
	/* 0x1211: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_121b:
	/* 0x121b: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_121f:
	/* 0x121f: jae    10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 269ULL;
	}
x86_l_1225:
	/* 0x1225: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_1228:
	/* 0x1228: jne    1e81 <generic_usdt_filter_arg+0x1e81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7809ULL;
	}
x86_l_122e:
	/* 0x122e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1232:
	/* 0x1232: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1235:
	/* 0x1235: jmp    126a <generic_usdt_filter_arg+0x126a> */
	goto x86_l_126a;
x86_l_1237:
	/* 0x1237: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_123c:
	/* 0x123c: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1240:
	/* 0x1240: jb     179d <generic_usdt_filter_arg+0x179d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6045ULL;
	}
x86_l_1246:
	/* 0x1246: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_1250:
	/* 0x1250: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1254:
	/* 0x1254: jae    10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 269ULL;
	}
x86_l_125a:
	/* 0x125a: cmp    eax,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31ULL);
x86_l_125d:
	/* 0x125d: jne    1e8f <generic_usdt_filter_arg+0x1e8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7823ULL;
	}
x86_l_1263:
	/* 0x1263: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1267:
	/* 0x1267: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_126a:
	/* 0x126a: cmp    DWORD PTR [r12+0x10],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_126f:
	/* 0x126f: ja     127c <generic_usdt_filter_arg+0x127c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_127c;
	}
x86_l_1271:
	/* 0x1271: cmp    DWORD PTR [r12+0x14],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1276:
	/* 0x1276: jae    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 716ULL;
	}
x86_l_127c:
	/* 0x127c: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1281:
	/* 0x1281: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_1284:
	/* 0x1284: jb     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 269ULL;
	}
x86_l_128a:
	/* 0x128a: cmp    DWORD PTR [r12+0x18],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_128f:
	/* 0x128f: ja     129c <generic_usdt_filter_arg+0x129c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_129c;
	}
x86_l_1291:
	/* 0x1291: cmp    DWORD PTR [r12+0x1c],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1296:
	/* 0x1296: jae    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 716ULL;
	}
x86_l_129c:
	/* 0x129c: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_129f:
	/* 0x129f: jb     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 269ULL;
	}
x86_l_12a5:
	/* 0x12a5: cmp    DWORD PTR [r12+0x20],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12aa:
	/* 0x12aa: ja     12b7 <generic_usdt_filter_arg+0x12b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_12b7;
	}
x86_l_12ac:
	/* 0x12ac: cmp    DWORD PTR [r12+0x24],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_12b1:
	/* 0x12b1: jae    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 716ULL;
	}
x86_l_12b7:
	/* 0x12b7: cmp    ecx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33ULL);
x86_l_12ba:
	/* 0x12ba: jb     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 269ULL;
	}
x86_l_12c0:
	/* 0x12c0: cmp    DWORD PTR [r12+0x28],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12c5:
	/* 0x12c5: ja     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 269ULL;
	}
x86_l_12cb:
	/* 0x12cb: cmp    DWORD PTR [r12+0x2c],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_12d0:
	/* 0x12d0: jae    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 716ULL;
	}
x86_l_12d6:
	/* 0x12d6: jmp    10d <generic_usdt_filter_arg+0x10d> */
	return 269ULL;
x86_l_12db:
	/* 0x12db: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_12de:
	/* 0x12de: je     12e9 <generic_usdt_filter_arg+0x12e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12e9;
	}
x86_l_12e0:
	/* 0x12e0: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_12e3:
	/* 0x12e3: jne    1c7a <generic_usdt_filter_arg+0x1c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7290ULL;
	}
x86_l_12e9:
	/* 0x12e9: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12ed:
	/* 0x12ed: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12f0:
	/* 0x12f0: jg     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 716ULL;
	}
x86_l_12f6:
	/* 0x12f6: jmp    1c96 <generic_usdt_filter_arg+0x1c96> */
	return 7318ULL;
x86_l_12fb:
	/* 0x12fb: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_12fe:
	/* 0x12fe: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_1303:
	/* 0x1303: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1308:
	/* 0x1308: ja     19a6 <generic_usdt_filter_arg+0x19a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6566ULL;
	}
x86_l_130e:
	/* 0x130e: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1312:
	/* 0x1312: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1318:
	/* 0x1318: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_131b:
	/* 0x131b: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_131e:
	/* 0x131e: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1321:
	/* 0x1321: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1323:
	/* 0x1323: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1325:
	/* 0x1325: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_1328:
	/* 0x1328: je     1330 <generic_usdt_filter_arg+0x1330> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1330;
	}
x86_l_132a:
	/* 0x132a: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_132c:
	/* 0x132c: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_132e:
	/* 0x132e: je     1346 <generic_usdt_filter_arg+0x1346> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1346;
	}
x86_l_1330:
	/* 0x1330: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1333:
	/* 0x1333: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1335:
	/* 0x1335: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1337:
	/* 0x1337: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1339:
	/* 0x1339: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_133c:
	/* 0x133c: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_1340:
	/* 0x1340: ja     19bb <generic_usdt_filter_arg+0x19bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6587ULL;
	}
x86_l_1346:
	/* 0x1346: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
	return 4937ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_usdt_filter_arg_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4937ULL: goto x86_l_1349;
	case 4943ULL: goto x86_l_134f;
	case 4946ULL: goto x86_l_1352;
	case 4948ULL: goto x86_l_1354;
	case 4953ULL: goto x86_l_1359;
	case 4958ULL: goto x86_l_135e;
	case 4963ULL: goto x86_l_1363;
	case 4966ULL: goto x86_l_1366;
	case 4972ULL: goto x86_l_136c;
	case 4977ULL: goto x86_l_1371;
	case 4980ULL: goto x86_l_1374;
	case 4986ULL: goto x86_l_137a;
	case 4990ULL: goto x86_l_137e;
	case 4992ULL: goto x86_l_1380;
	case 4994ULL: goto x86_l_1382;
	case 4998ULL: goto x86_l_1386;
	case 5000ULL: goto x86_l_1388;
	case 5003ULL: goto x86_l_138b;
	case 5008ULL: goto x86_l_1390;
	case 5011ULL: goto x86_l_1393;
	case 5013ULL: goto x86_l_1395;
	case 5018ULL: goto x86_l_139a;
	case 5021ULL: goto x86_l_139d;
	case 5027ULL: goto x86_l_13a3;
	case 5032ULL: goto x86_l_13a8;
	case 5034ULL: goto x86_l_13aa;
	case 5039ULL: goto x86_l_13af;
	case 5041ULL: goto x86_l_13b1;
	case 5043ULL: goto x86_l_13b3;
	case 5046ULL: goto x86_l_13b6;
	case 5048ULL: goto x86_l_13b8;
	case 5051ULL: goto x86_l_13bb;
	case 5053ULL: goto x86_l_13bd;
	case 5056ULL: goto x86_l_13c0;
	case 5059ULL: goto x86_l_13c3;
	case 5065ULL: goto x86_l_13c9;
	case 5068ULL: goto x86_l_13cc;
	case 5071ULL: goto x86_l_13cf;
	case 5077ULL: goto x86_l_13d5;
	case 5080ULL: goto x86_l_13d8;
	case 5086ULL: goto x86_l_13de;
	case 5091ULL: goto x86_l_13e3;
	case 5094ULL: goto x86_l_13e6;
	case 5100ULL: goto x86_l_13ec;
	case 5105ULL: goto x86_l_13f1;
	case 5108ULL: goto x86_l_13f4;
	case 5114ULL: goto x86_l_13fa;
	case 5117ULL: goto x86_l_13fd;
	case 5123ULL: goto x86_l_1403;
	case 5126ULL: goto x86_l_1406;
	case 5132ULL: goto x86_l_140c;
	case 5134ULL: goto x86_l_140e;
	case 5139ULL: goto x86_l_1413;
	case 5143ULL: goto x86_l_1417;
	case 5147ULL: goto x86_l_141b;
	case 5149ULL: goto x86_l_141d;
	case 5152ULL: goto x86_l_1420;
	case 5156ULL: goto x86_l_1424;
	case 5159ULL: goto x86_l_1427;
	case 5163ULL: goto x86_l_142b;
	case 5166ULL: goto x86_l_142e;
	case 5168ULL: goto x86_l_1430;
	case 5171ULL: goto x86_l_1433;
	case 5173ULL: goto x86_l_1435;
	case 5176ULL: goto x86_l_1438;
	case 5182ULL: goto x86_l_143e;
	case 5187ULL: goto x86_l_1443;
	case 5190ULL: goto x86_l_1446;
	case 5196ULL: goto x86_l_144c;
	case 5201ULL: goto x86_l_1451;
	case 5204ULL: goto x86_l_1454;
	case 5210ULL: goto x86_l_145a;
	case 5215ULL: goto x86_l_145f;
	case 5218ULL: goto x86_l_1462;
	case 5224ULL: goto x86_l_1468;
	case 5228ULL: goto x86_l_146c;
	case 5231ULL: goto x86_l_146f;
	case 5237ULL: goto x86_l_1475;
	case 5240ULL: goto x86_l_1478;
	case 5246ULL: goto x86_l_147e;
	case 5249ULL: goto x86_l_1481;
	case 5254ULL: goto x86_l_1486;
	case 5259ULL: goto x86_l_148b;
	case 5263ULL: goto x86_l_148f;
	case 5268ULL: goto x86_l_1494;
	case 5273ULL: goto x86_l_1499;
	case 5280ULL: goto x86_l_14a0;
	case 5282ULL: goto x86_l_14a2;
	case 5285ULL: goto x86_l_14a5;
	case 5291ULL: goto x86_l_14ab;
	case 5294ULL: goto x86_l_14ae;
	case 5305ULL: goto x86_l_14b9;
	case 5313ULL: goto x86_l_14c1;
	case 5318ULL: goto x86_l_14c6;
	case 5321ULL: goto x86_l_14c9;
	case 5327ULL: goto x86_l_14cf;
	case 5332ULL: goto x86_l_14d4;
	case 5335ULL: goto x86_l_14d7;
	case 5341ULL: goto x86_l_14dd;
	case 5345ULL: goto x86_l_14e1;
	case 5347ULL: goto x86_l_14e3;
	case 5353ULL: goto x86_l_14e9;
	case 5358ULL: goto x86_l_14ee;
	case 5362ULL: goto x86_l_14f2;
	case 5364ULL: goto x86_l_14f4;
	case 5367ULL: goto x86_l_14f7;
	case 5370ULL: goto x86_l_14fa;
	case 5375ULL: goto x86_l_14ff;
	case 5379ULL: goto x86_l_1503;
	case 5384ULL: goto x86_l_1508;
	case 5389ULL: goto x86_l_150d;
	case 5396ULL: goto x86_l_1514;
	case 5398ULL: goto x86_l_1516;
	case 5401ULL: goto x86_l_1519;
	case 5407ULL: goto x86_l_151f;
	case 5410ULL: goto x86_l_1522;
	case 5415ULL: goto x86_l_1527;
	case 5418ULL: goto x86_l_152a;
	case 5423ULL: goto x86_l_152f;
	case 5425ULL: goto x86_l_1531;
	case 5429ULL: goto x86_l_1535;
	case 5431ULL: goto x86_l_1537;
	case 5433ULL: goto x86_l_1539;
	case 5436ULL: goto x86_l_153c;
	case 5439ULL: goto x86_l_153f;
	case 5442ULL: goto x86_l_1542;
	case 5444ULL: goto x86_l_1544;
	case 5446ULL: goto x86_l_1546;
	case 5450ULL: goto x86_l_154a;
	case 5453ULL: goto x86_l_154d;
	case 5455ULL: goto x86_l_154f;
	case 5459ULL: goto x86_l_1553;
	case 5462ULL: goto x86_l_1556;
	case 5464ULL: goto x86_l_1558;
	case 5468ULL: goto x86_l_155c;
	case 5470ULL: goto x86_l_155e;
	case 5474ULL: goto x86_l_1562;
	case 5478ULL: goto x86_l_1566;
	case 5481ULL: goto x86_l_1569;
	case 5483ULL: goto x86_l_156b;
	case 5485ULL: goto x86_l_156d;
	case 5487ULL: goto x86_l_156f;
	case 5493ULL: goto x86_l_1575;
	case 5497ULL: goto x86_l_1579;
	case 5502ULL: goto x86_l_157e;
	case 5504ULL: goto x86_l_1580;
	case 5508ULL: goto x86_l_1584;
	case 5511ULL: goto x86_l_1587;
	case 5515ULL: goto x86_l_158b;
	case 5521ULL: goto x86_l_1591;
	case 5523ULL: goto x86_l_1593;
	case 5528ULL: goto x86_l_1598;
	case 5531ULL: goto x86_l_159b;
	case 5536ULL: goto x86_l_15a0;
	case 5541ULL: goto x86_l_15a5;
	case 5547ULL: goto x86_l_15ab;
	case 5551ULL: goto x86_l_15af;
	case 5557ULL: goto x86_l_15b5;
	case 5560ULL: goto x86_l_15b8;
	case 5563ULL: goto x86_l_15bb;
	case 5566ULL: goto x86_l_15be;
	case 5568ULL: goto x86_l_15c0;
	case 5570ULL: goto x86_l_15c2;
	case 5573ULL: goto x86_l_15c5;
	case 5575ULL: goto x86_l_15c7;
	case 5577ULL: goto x86_l_15c9;
	case 5579ULL: goto x86_l_15cb;
	case 5581ULL: goto x86_l_15cd;
	case 5584ULL: goto x86_l_15d0;
	case 5586ULL: goto x86_l_15d2;
	case 5588ULL: goto x86_l_15d4;
	case 5590ULL: goto x86_l_15d6;
	case 5593ULL: goto x86_l_15d9;
	case 5597ULL: goto x86_l_15dd;
	case 5603ULL: goto x86_l_15e3;
	case 5607ULL: goto x86_l_15e7;
	case 5613ULL: goto x86_l_15ed;
	case 5616ULL: goto x86_l_15f0;
	case 5618ULL: goto x86_l_15f2;
	case 5623ULL: goto x86_l_15f7;
	case 5626ULL: goto x86_l_15fa;
	case 5629ULL: goto x86_l_15fd;
	case 5635ULL: goto x86_l_1603;
	case 5638ULL: goto x86_l_1606;
	case 5644ULL: goto x86_l_160c;
	case 5648ULL: goto x86_l_1610;
	case 5653ULL: goto x86_l_1615;
	case 5660ULL: goto x86_l_161c;
	case 5665ULL: goto x86_l_1621;
	case 5667ULL: goto x86_l_1623;
	case 5670ULL: goto x86_l_1626;
	case 5676ULL: goto x86_l_162c;
	case 5679ULL: goto x86_l_162f;
	case 5683ULL: goto x86_l_1633;
	case 5691ULL: goto x86_l_163b;
	case 5696ULL: goto x86_l_1640;
	case 5701ULL: goto x86_l_1645;
	case 5703ULL: goto x86_l_1647;
	case 5708ULL: goto x86_l_164c;
	case 5710ULL: goto x86_l_164e;
	case 5713ULL: goto x86_l_1651;
	case 5719ULL: goto x86_l_1657;
	case 5724ULL: goto x86_l_165c;
	case 5727ULL: goto x86_l_165f;
	case 5732ULL: goto x86_l_1664;
	case 5737ULL: goto x86_l_1669;
	case 5740ULL: goto x86_l_166c;
	case 5746ULL: goto x86_l_1672;
	case 5751ULL: goto x86_l_1677;
	case 5754ULL: goto x86_l_167a;
	case 5760ULL: goto x86_l_1680;
	case 5765ULL: goto x86_l_1685;
	case 5768ULL: goto x86_l_1688;
	case 5774ULL: goto x86_l_168e;
	case 5780ULL: goto x86_l_1694;
	case 5783ULL: goto x86_l_1697;
	case 5787ULL: goto x86_l_169b;
	case 5791ULL: goto x86_l_169f;
	case 5796ULL: goto x86_l_16a4;
	case 5801ULL: goto x86_l_16a9;
	case 5808ULL: goto x86_l_16b0;
	case 5810ULL: goto x86_l_16b2;
	case 5813ULL: goto x86_l_16b5;
	case 5819ULL: goto x86_l_16bb;
	case 5823ULL: goto x86_l_16bf;
	case 5826ULL: goto x86_l_16c2;
	case 5829ULL: goto x86_l_16c5;
	case 5834ULL: goto x86_l_16ca;
	case 5836ULL: goto x86_l_16cc;
	case 5842ULL: goto x86_l_16d2;
	case 5846ULL: goto x86_l_16d6;
	case 5850ULL: goto x86_l_16da;
	case 5855ULL: goto x86_l_16df;
	case 5860ULL: goto x86_l_16e4;
	case 5865ULL: goto x86_l_16e9;
	case 5868ULL: goto x86_l_16ec;
	case 5874ULL: goto x86_l_16f2;
	case 5879ULL: goto x86_l_16f7;
	case 5886ULL: goto x86_l_16fe;
	case 5891ULL: goto x86_l_1703;
	case 5893ULL: goto x86_l_1705;
	case 5898ULL: goto x86_l_170a;
	case 5901ULL: goto x86_l_170d;
	case 5907ULL: goto x86_l_1713;
	case 5910ULL: goto x86_l_1716;
	case 5916ULL: goto x86_l_171c;
	case 5920ULL: goto x86_l_1720;
	case 5923ULL: goto x86_l_1723;
	case 5925ULL: goto x86_l_1725;
	case 5931ULL: goto x86_l_172b;
	case 5936ULL: goto x86_l_1730;
	case 5939ULL: goto x86_l_1733;
	case 5945ULL: goto x86_l_1739;
	case 5948ULL: goto x86_l_173c;
	case 5954ULL: goto x86_l_1742;
	case 5958ULL: goto x86_l_1746;
	case 5961ULL: goto x86_l_1749;
	case 5963ULL: goto x86_l_174b;
	case 5969ULL: goto x86_l_1751;
	case 5974ULL: goto x86_l_1756;
	case 5977ULL: goto x86_l_1759;
	case 5983ULL: goto x86_l_175f;
	case 5990ULL: goto x86_l_1766;
	case 5995ULL: goto x86_l_176b;
	case 6000ULL: goto x86_l_1770;
	case 6007ULL: goto x86_l_1777;
	case 6009ULL: goto x86_l_1779;
	case 6012ULL: goto x86_l_177c;
	case 6018ULL: goto x86_l_1782;
	case 6021ULL: goto x86_l_1785;
	case 6025ULL: goto x86_l_1789;
	case 6028ULL: goto x86_l_178c;
	case 6033ULL: goto x86_l_1791;
	case 6038ULL: goto x86_l_1796;
	case 6043ULL: goto x86_l_179b;
	case 6045ULL: goto x86_l_179d;
	case 6048ULL: goto x86_l_17a0;
	case 6054ULL: goto x86_l_17a6;
	case 6061ULL: goto x86_l_17ad;
	case 6066ULL: goto x86_l_17b2;
	case 6071ULL: goto x86_l_17b7;
	case 6078ULL: goto x86_l_17be;
	case 6080ULL: goto x86_l_17c0;
	case 6083ULL: goto x86_l_17c3;
	case 6085ULL: goto x86_l_17c5;
	case 6088ULL: goto x86_l_17c8;
	case 6092ULL: goto x86_l_17cc;
	case 6095ULL: goto x86_l_17cf;
	case 6100ULL: goto x86_l_17d4;
	case 6105ULL: goto x86_l_17d9;
	case 6110ULL: goto x86_l_17de;
	case 6112ULL: goto x86_l_17e0;
	case 6117ULL: goto x86_l_17e5;
	case 6119ULL: goto x86_l_17e7;
	case 6122ULL: goto x86_l_17ea;
	case 6128ULL: goto x86_l_17f0;
	case 6133ULL: goto x86_l_17f5;
	case 6136ULL: goto x86_l_17f8;
	case 6141ULL: goto x86_l_17fd;
	case 6146ULL: goto x86_l_1802;
	case 6149ULL: goto x86_l_1805;
	case 6151ULL: goto x86_l_1807;
	case 6154ULL: goto x86_l_180a;
	case 6157ULL: goto x86_l_180d;
	case 6160ULL: goto x86_l_1810;
	case 6165ULL: goto x86_l_1815;
	case 6167ULL: goto x86_l_1817;
	case 6172ULL: goto x86_l_181c;
	case 6177ULL: goto x86_l_1821;
	case 6180ULL: goto x86_l_1824;
	case 6185ULL: goto x86_l_1829;
	case 6190ULL: goto x86_l_182e;
	case 6193ULL: goto x86_l_1831;
	case 6195ULL: goto x86_l_1833;
	case 6198ULL: goto x86_l_1836;
	case 6201ULL: goto x86_l_1839;
	case 6204ULL: goto x86_l_183c;
	case 6209ULL: goto x86_l_1841;
	case 6212ULL: goto x86_l_1844;
	case 6215ULL: goto x86_l_1847;
	case 6220ULL: goto x86_l_184c;
	case 6225ULL: goto x86_l_1851;
	case 6228ULL: goto x86_l_1854;
	case 6231ULL: goto x86_l_1857;
	case 6236ULL: goto x86_l_185c;
	case 6238ULL: goto x86_l_185e;
	case 6241ULL: goto x86_l_1861;
	case 6246ULL: goto x86_l_1866;
	case 6251ULL: goto x86_l_186b;
	case 6256ULL: goto x86_l_1870;
	case 6260ULL: goto x86_l_1874;
	case 6271ULL: goto x86_l_187f;
	case 6276ULL: goto x86_l_1884;
	case 6281ULL: goto x86_l_1889;
	case 6288ULL: goto x86_l_1890;
	case 6290ULL: goto x86_l_1892;
	case 6293ULL: goto x86_l_1895;
	case 6299ULL: goto x86_l_189b;
	case 6302ULL: goto x86_l_189e;
	case 6307ULL: goto x86_l_18a3;
	case 6310ULL: goto x86_l_18a6;
	case 6316ULL: goto x86_l_18ac;
	case 6321ULL: goto x86_l_18b1;
	case 6326ULL: goto x86_l_18b6;
	case 6333ULL: goto x86_l_18bd;
	case 6335ULL: goto x86_l_18bf;
	case 6338ULL: goto x86_l_18c2;
	case 6344ULL: goto x86_l_18c8;
	case 6350ULL: goto x86_l_18ce;
	case 6355ULL: goto x86_l_18d3;
	case 6358ULL: goto x86_l_18d6;
	case 6365ULL: goto x86_l_18dd;
	case 6367ULL: goto x86_l_18df;
	case 6370ULL: goto x86_l_18e2;
	case 6374ULL: goto x86_l_18e6;
	case 6377ULL: goto x86_l_18e9;
	case 6382ULL: goto x86_l_18ee;
	case 6386ULL: goto x86_l_18f2;
	case 6388ULL: goto x86_l_18f4;
	case 6393ULL: goto x86_l_18f9;
	case 6396ULL: goto x86_l_18fc;
	case 6399ULL: goto x86_l_18ff;
	case 6404ULL: goto x86_l_1904;
	case 6415ULL: goto x86_l_190f;
	case 6421ULL: goto x86_l_1915;
	case 6427ULL: goto x86_l_191b;
	case 6429ULL: goto x86_l_191d;
	case 6434ULL: goto x86_l_1922;
	case 6436ULL: goto x86_l_1924;
	case 6441ULL: goto x86_l_1929;
	case 6446ULL: goto x86_l_192e;
	case 6449ULL: goto x86_l_1931;
	case 6454ULL: goto x86_l_1936;
	case 6457ULL: goto x86_l_1939;
	case 6463ULL: goto x86_l_193f;
	case 6468ULL: goto x86_l_1944;
	case 6471ULL: goto x86_l_1947;
	case 6473ULL: goto x86_l_1949;
	case 6482ULL: goto x86_l_1952;
	case 6488ULL: goto x86_l_1958;
	case 6492ULL: goto x86_l_195c;
	case 6495ULL: goto x86_l_195f;
	case 6503ULL: goto x86_l_1967;
	case 6508ULL: goto x86_l_196c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1349:
	/* 0x1349: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_134f:
	/* 0x134f: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_1352:
	/* 0x1352: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1354:
	/* 0x1354: jmp    19cb <generic_usdt_filter_arg+0x19cb> */
	return 6603ULL;
x86_l_1359:
	/* 0x1359: mov    esi,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_135e:
	/* 0x135e: mov    eax,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1363:
	/* 0x1363: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1366:
	/* 0x1366: ja     212d <generic_usdt_filter_arg+0x212d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8493ULL;
	}
x86_l_136c:
	/* 0x136c: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1371:
	/* 0x1371: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1374:
	/* 0x1374: jae    212d <generic_usdt_filter_arg+0x212d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8493ULL;
	}
x86_l_137a:
	/* 0x137a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_137e:
	/* 0x137e: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1380:
	/* 0x1380: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1382:
	/* 0x1382: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_1386:
	/* 0x1386: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_1388:
	/* 0x1388: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_138b:
	/* 0x138b: jmp    213e <generic_usdt_filter_arg+0x213e> */
	return 8510ULL;
x86_l_1390:
	/* 0x1390: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_1393:
	/* 0x1393: je     13aa <generic_usdt_filter_arg+0x13aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13aa;
	}
x86_l_1395:
	/* 0x1395: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_139a:
	/* 0x139a: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_139d:
	/* 0x139d: jne    2b6 <generic_usdt_filter_arg+0x2b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 694ULL;
	}
x86_l_13a3:
	/* 0x13a3: movzx  r13d,WORD PTR [rsi+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_13a8:
	/* 0x13a8: jmp    13af <generic_usdt_filter_arg+0x13af> */
	goto x86_l_13af;
x86_l_13aa:
	/* 0x13aa: movzx  r13d,WORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_13af:
	/* 0x13af: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13b1:
	/* 0x13b1: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13b3:
	/* 0x13b3: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13b6:
	/* 0x13b6: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13b8:
	/* 0x13b8: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_13bb:
	/* 0x13bb: jg     1435 <generic_usdt_filter_arg+0x1435> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1435;
	}
x86_l_13bd:
	/* 0x13bd: lea    ecx,[rax-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_13c0:
	/* 0x13c0: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_13c3:
	/* 0x13c3: jb     1468 <generic_usdt_filter_arg+0x1468> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1468;
	}
x86_l_13c9:
	/* 0x13c9: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_13cc:
	/* 0x13cc: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_13cf:
	/* 0x13cf: jb     1603 <generic_usdt_filter_arg+0x1603> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1603;
	}
x86_l_13d5:
	/* 0x13d5: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_13d8:
	/* 0x13d8: je     1bf3 <generic_usdt_filter_arg+0x1bf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7155ULL;
	}
x86_l_13de:
	/* 0x13de: jmp    2b6 <generic_usdt_filter_arg+0x2b6> */
	return 694ULL;
x86_l_13e3:
	/* 0x13e3: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_13e6:
	/* 0x13e6: je     1bef <generic_usdt_filter_arg+0x1bef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7151ULL;
	}
x86_l_13ec:
	/* 0x13ec: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_13f1:
	/* 0x13f1: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_13f4:
	/* 0x13f4: jne    2b6 <generic_usdt_filter_arg+0x2b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 694ULL;
	}
x86_l_13fa:
	/* 0x13fa: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_13fd:
	/* 0x13fd: jne    221c <generic_usdt_filter_arg+0x221c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8732ULL;
	}
x86_l_1403:
	/* 0x1403: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1406:
	/* 0x1406: jne    2228 <generic_usdt_filter_arg+0x2228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8744ULL;
	}
x86_l_140c:
	/* 0x140c: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_140e:
	/* 0x140e: jmp    223a <generic_usdt_filter_arg+0x223a> */
	return 8762ULL;
x86_l_1413:
	/* 0x1413: mov    rdx,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1417:
	/* 0x1417: mov    r8,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_141b:
	/* 0x141b: jmp    1424 <generic_usdt_filter_arg+0x1424> */
	goto x86_l_1424;
x86_l_141d:
	/* 0x141d: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1420:
	/* 0x1420: mov    r8,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1424:
	/* 0x1424: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_1427:
	/* 0x1427: shr    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_142b:
	/* 0x142b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_142e:
	/* 0x142e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1430:
	/* 0x1430: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1433:
	/* 0x1433: jle    13bd <generic_usdt_filter_arg+0x13bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_13bd;
	}
x86_l_1435:
	/* 0x1435: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1438:
	/* 0x1438: ja     15f7 <generic_usdt_filter_arg+0x15f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_15f7;
	}
x86_l_143e:
	/* 0x143e: mov    ecx,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5242880ULL);
x86_l_1443:
	/* 0x1443: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1446:
	/* 0x1446: jb     1980 <generic_usdt_filter_arg+0x1980> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6528ULL;
	}
x86_l_144c:
	/* 0x144c: mov    ecx,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10485760ULL);
x86_l_1451:
	/* 0x1451: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1454:
	/* 0x1454: jb     1993 <generic_usdt_filter_arg+0x1993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6547ULL;
	}
x86_l_145a:
	/* 0x145a: mov    ecx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 50331648ULL);
x86_l_145f:
	/* 0x145f: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1462:
	/* 0x1462: jae    15f7 <generic_usdt_filter_arg+0x15f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_15f7;
	}
x86_l_1468:
	/* 0x1468: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_146c:
	/* 0x146c: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_146f:
	/* 0x146f: je     1a9d <generic_usdt_filter_arg+0x1a9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6813ULL;
	}
x86_l_1475:
	/* 0x1475: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1478:
	/* 0x1478: jne    1b3e <generic_usdt_filter_arg+0x1b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6974ULL;
	}
x86_l_147e:
	/* 0x147e: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_1481:
	/* 0x1481: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1486:
	/* 0x1486: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_148b:
	/* 0x148b: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_148f:
	/* 0x148f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1494:
	/* 0x1494: lea    rsi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1499:
	/* 0x1499: mov    rdi,QWORD PTR [rip+0x1eac3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_14a0:
	/* 0x14a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a2:
	/* 0x14a2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14a5:
	/* 0x14a5: je     1d59 <generic_usdt_filter_arg+0x1d59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7513ULL;
	}
x86_l_14ab:
	/* 0x14ab: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_14ae:
	/* 0x14ae: mov    DWORD PTR [rsp+0x80],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813920ULL);
x86_l_14b9:
	/* 0x14b9: mov    DWORD PTR [rsp+0x84],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_14c1:
	/* 0x14c1: jmp    1afc <generic_usdt_filter_arg+0x1afc> */
	return 6908ULL;
x86_l_14c6:
	/* 0x14c6: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_14c9:
	/* 0x14c9: ja     228f <generic_usdt_filter_arg+0x228f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8847ULL;
	}
x86_l_14cf:
	/* 0x14cf: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_14d4:
	/* 0x14d4: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_14d7:
	/* 0x14d7: jae    228f <generic_usdt_filter_arg+0x228f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8847ULL;
	}
x86_l_14dd:
	/* 0x14dd: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14e1:
	/* 0x14e1: cmp    DWORD PTR [rsi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14e3:
	/* 0x14e3: jg     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 716ULL;
	}
x86_l_14e9:
	/* 0x14e9: jmp    22a9 <generic_usdt_filter_arg+0x22a9> */
	return 8873ULL;
x86_l_14ee:
	/* 0x14ee: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14f2:
	/* 0x14f2: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14f4:
	/* 0x14f4: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14f7:
	/* 0x14f7: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_14fa:
	/* 0x14fa: mov    eax,DWORD PTR [r12+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_14ff:
	/* 0x14ff: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1503:
	/* 0x1503: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1508:
	/* 0x1508: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_150d:
	/* 0x150d: mov    rdi,QWORD PTR [rip+0x1eac3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1514:
	/* 0x1514: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1516:
	/* 0x1516: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1519:
	/* 0x1519: je     2363 <generic_usdt_filter_arg+0x2363> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9059ULL;
	}
x86_l_151f:
	/* 0x151f: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_1522:
	/* 0x1522: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1527:
	/* 0x1527: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_152a:
	/* 0x152a: mov    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_152f:
	/* 0x152f: je     1575 <generic_usdt_filter_arg+0x1575> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1575;
	}
x86_l_1531:
	/* 0x1531: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1535:
	/* 0x1535: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1537:
	/* 0x1537: jmp    1544 <generic_usdt_filter_arg+0x1544> */
	goto x86_l_1544;
x86_l_1539:
	/* 0x1539: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_153c:
	/* 0x153c: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_153f:
	/* 0x153f: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1542:
	/* 0x1542: je     1575 <generic_usdt_filter_arg+0x1575> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1575;
	}
x86_l_1544:
	/* 0x1544: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1546:
	/* 0x1546: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_154a:
	/* 0x154a: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_154d:
	/* 0x154d: jae    1539 <generic_usdt_filter_arg+0x1539> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1539;
	}
x86_l_154f:
	/* 0x154f: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_1553:
	/* 0x1553: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_1556:
	/* 0x1556: je     156d <generic_usdt_filter_arg+0x156d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_156d;
	}
x86_l_1558:
	/* 0x1558: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_155c:
	/* 0x155c: ja     1539 <generic_usdt_filter_arg+0x1539> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1539;
	}
x86_l_155e:
	/* 0x155e: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1562:
	/* 0x1562: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1566:
	/* 0x1566: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_1569:
	/* 0x1569: je     1546 <generic_usdt_filter_arg+0x1546> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1546;
	}
x86_l_156b:
	/* 0x156b: jmp    1539 <generic_usdt_filter_arg+0x1539> */
	goto x86_l_1539;
x86_l_156d:
	/* 0x156d: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_156f:
	/* 0x156f: jns    263c <generic_usdt_filter_arg+0x263c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 9788ULL;
	}
x86_l_1575:
	/* 0x1575: lea    eax,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1579:
	/* 0x1579: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_157e:
	/* 0x157e: jae    1591 <generic_usdt_filter_arg+0x1591> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1591;
	}
x86_l_1580:
	/* 0x1580: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1584:
	/* 0x1584: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1587:
	/* 0x1587: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_158b:
	/* 0x158b: jne    14f7 <generic_usdt_filter_arg+0x14f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14f7;
	}
x86_l_1591:
	/* 0x1591: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1593:
	/* 0x1593: jmp    2641 <generic_usdt_filter_arg+0x2641> */
	return 9793ULL;
x86_l_1598:
	/* 0x1598: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_159b:
	/* 0x159b: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_15a0:
	/* 0x15a0: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15a5:
	/* 0x15a5: ja     1d69 <generic_usdt_filter_arg+0x1d69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7529ULL;
	}
x86_l_15ab:
	/* 0x15ab: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_15af:
	/* 0x15af: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_15b5:
	/* 0x15b5: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_15b8:
	/* 0x15b8: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_15bb:
	/* 0x15bb: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_15be:
	/* 0x15be: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_15c0:
	/* 0x15c0: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_15c2:
	/* 0x15c2: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_15c5:
	/* 0x15c5: je     15cd <generic_usdt_filter_arg+0x15cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15cd;
	}
x86_l_15c7:
	/* 0x15c7: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_15c9:
	/* 0x15c9: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_15cb:
	/* 0x15cb: je     15e3 <generic_usdt_filter_arg+0x15e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15e3;
	}
x86_l_15cd:
	/* 0x15cd: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_15d0:
	/* 0x15d0: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_15d2:
	/* 0x15d2: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_15d4:
	/* 0x15d4: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_15d6:
	/* 0x15d6: add    esi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_15d9:
	/* 0x15d9: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_15dd:
	/* 0x15dd: ja     1d7e <generic_usdt_filter_arg+0x1d7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7550ULL;
	}
x86_l_15e3:
	/* 0x15e3: movzx  eax,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_15e7:
	/* 0x15e7: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_15ed:
	/* 0x15ed: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_15f0:
	/* 0x15f0: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_15f2:
	/* 0x15f2: jmp    1d8e <generic_usdt_filter_arg+0x1d8e> */
	return 7566ULL;
x86_l_15f7:
	/* 0x15f7: add    eax,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_15fa:
	/* 0x15fa: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15fd:
	/* 0x15fd: jae    2b6 <generic_usdt_filter_arg+0x2b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 694ULL;
	}
x86_l_1603:
	/* 0x1603: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_1606:
	/* 0x1606: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_160c:
	/* 0x160c: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1610:
	/* 0x1610: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1615:
	/* 0x1615: mov    rdi,QWORD PTR [rip+0x1eaca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_161c:
	/* 0x161c: lea    rsi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1621:
	/* 0x1621: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1623:
	/* 0x1623: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1626:
	/* 0x1626: je     1922 <generic_usdt_filter_arg+0x1922> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1922;
	}
x86_l_162c:
	/* 0x162c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_162f:
	/* 0x162f: movzx  eax,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1633:
	/* 0x1633: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_163b:
	/* 0x163b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1640:
	/* 0x1640: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1645:
	/* 0x1645: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1647:
	/* 0x1647: mov    edx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_164c:
	/* 0x164c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_164e:
	/* 0x164e: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1651:
	/* 0x1651: ja     2c69 <generic_usdt_filter_arg+0x2c69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11369ULL;
	}
x86_l_1657:
	/* 0x1657: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_165c:
	/* 0x165c: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_165f:
	/* 0x165f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1664:
	/* 0x1664: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1669:
	/* 0x1669: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_166c:
	/* 0x166c: jb     2ad <generic_usdt_filter_arg+0x2ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 685ULL;
	}
x86_l_1672:
	/* 0x1672: jmp    1c61 <generic_usdt_filter_arg+0x1c61> */
	return 7265ULL;
x86_l_1677:
	/* 0x1677: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_167a:
	/* 0x167a: je     1f13 <generic_usdt_filter_arg+0x1f13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7955ULL;
	}
x86_l_1680:
	/* 0x1680: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1685:
	/* 0x1685: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_1688:
	/* 0x1688: jne    3216 <generic_usdt_filter_arg+0x3216> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12822ULL;
	}
x86_l_168e:
	/* 0x168e: mov    r13d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 16ULL);
x86_l_1694:
	/* 0x1694: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_1697:
	/* 0x1697: mov    eax,DWORD PTR [r12+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_169b:
	/* 0x169b: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_169f:
	/* 0x169f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16a4:
	/* 0x16a4: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_16a9:
	/* 0x16a9: mov    rdi,QWORD PTR [rip+0x1eaca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_16b0:
	/* 0x16b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16b2:
	/* 0x16b2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16b5:
	/* 0x16b5: je     295e <generic_usdt_filter_arg+0x295e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10590ULL;
	}
x86_l_16bb:
	/* 0x16bb: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16bf:
	/* 0x16bf: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_16c2:
	/* 0x16c2: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_16c5:
	/* 0x16c5: call   0 <generic_usdt_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 5834ULL);
	__x86_sim_call_depth++;
	return 13000ULL;
x86_l_16ca:
	/* 0x16ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16cc:
	/* 0x16cc: jns    2962 <generic_usdt_filter_arg+0x2962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 10594ULL;
	}
x86_l_16d2:
	/* 0x16d2: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_16d6:
	/* 0x16d6: lea    eax,[r13-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_16da:
	/* 0x16da: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_16df:
	/* 0x16df: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16e4:
	/* 0x16e4: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16e9:
	/* 0x16e9: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_16ec:
	/* 0x16ec: jae    2a0a <generic_usdt_filter_arg+0x2a0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10762ULL;
	}
x86_l_16f2:
	/* 0x16f2: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_16f7:
	/* 0x16f7: cmp    r13,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 416ULL);
x86_l_16fe:
	/* 0x16fe: mov    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1703:
	/* 0x1703: jne    1694 <generic_usdt_filter_arg+0x1694> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1694;
	}
x86_l_1705:
	/* 0x1705: jmp    3216 <generic_usdt_filter_arg+0x3216> */
	return 12822ULL;
x86_l_170a:
	/* 0x170a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_170d:
	/* 0x170d: je     201d <generic_usdt_filter_arg+0x201d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8221ULL;
	}
x86_l_1713:
	/* 0x1713: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1716:
	/* 0x1716: jne    202c <generic_usdt_filter_arg+0x202c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8236ULL;
	}
x86_l_171c:
	/* 0x171c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1720:
	/* 0x1720: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1723:
	/* 0x1723: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1725:
	/* 0x1725: ja     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_172b:
	/* 0x172b: jmp    202c <generic_usdt_filter_arg+0x202c> */
	return 8236ULL;
x86_l_1730:
	/* 0x1730: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1733:
	/* 0x1733: je     2068 <generic_usdt_filter_arg+0x2068> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8296ULL;
	}
x86_l_1739:
	/* 0x1739: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_173c:
	/* 0x173c: jne    2077 <generic_usdt_filter_arg+0x2077> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8311ULL;
	}
x86_l_1742:
	/* 0x1742: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1746:
	/* 0x1746: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1749:
	/* 0x1749: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_174b:
	/* 0x174b: ja     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_1751:
	/* 0x1751: jmp    2077 <generic_usdt_filter_arg+0x2077> */
	return 8311ULL;
x86_l_1756:
	/* 0x1756: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_1759:
	/* 0x1759: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_175f:
	/* 0x175f: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1766:
	/* 0x1766: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_176b:
	/* 0x176b: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1770:
	/* 0x1770: mov    rdi,QWORD PTR [rip+0x1eaca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1777:
	/* 0x1777: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1779:
	/* 0x1779: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_177c:
	/* 0x177c: je     1815 <generic_usdt_filter_arg+0x1815> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1815;
	}
x86_l_1782:
	/* 0x1782: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1785:
	/* 0x1785: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1789:
	/* 0x1789: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_178c:
	/* 0x178c: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1791:
	/* 0x1791: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1796:
	/* 0x1796: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_179b:
	/* 0x179b: jmp    17de <generic_usdt_filter_arg+0x17de> */
	goto x86_l_17de;
x86_l_179d:
	/* 0x179d: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_17a0:
	/* 0x17a0: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_17a6:
	/* 0x17a6: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_17ad:
	/* 0x17ad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17b2:
	/* 0x17b2: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17b7:
	/* 0x17b7: mov    rdi,QWORD PTR [rip+0x1eaca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_17be:
	/* 0x17be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c0:
	/* 0x17c0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17c3:
	/* 0x17c3: je     1815 <generic_usdt_filter_arg+0x1815> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1815;
	}
x86_l_17c5:
	/* 0x17c5: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_17c8:
	/* 0x17c8: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17cc:
	/* 0x17cc: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_17cf:
	/* 0x17cf: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17d4:
	/* 0x17d4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17d9:
	/* 0x17d9: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17de:
	/* 0x17de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17e0:
	/* 0x17e0: mov    edx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_17e5:
	/* 0x17e5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17e7:
	/* 0x17e7: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_17ea:
	/* 0x17ea: ja     28c0 <generic_usdt_filter_arg+0x28c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10432ULL;
	}
x86_l_17f0:
	/* 0x17f0: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_17f5:
	/* 0x17f5: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_17f8:
	/* 0x17f8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17fd:
	/* 0x17fd: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1802:
	/* 0x1802: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_1805:
	/* 0x1805: jae    1829 <generic_usdt_filter_arg+0x1829> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1829;
	}
x86_l_1807:
	/* 0x1807: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_180a:
	/* 0x180a: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_180d:
	/* 0x180d: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1810:
	/* 0x1810: jmp    2bb <generic_usdt_filter_arg+0x2bb> */
	return 699ULL;
x86_l_1815:
	/* 0x1815: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1817:
	/* 0x1817: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_181c:
	/* 0x181c: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1821:
	/* 0x1821: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_1824:
	/* 0x1824: jmp    2bb <generic_usdt_filter_arg+0x2bb> */
	return 699ULL;
x86_l_1829:
	/* 0x1829: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_182e:
	/* 0x182e: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1831:
	/* 0x1831: jae    1839 <generic_usdt_filter_arg+0x1839> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1839;
	}
x86_l_1833:
	/* 0x1833: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1836:
	/* 0x1836: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1839:
	/* 0x1839: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_183c:
	/* 0x183c: jmp    2bb <generic_usdt_filter_arg+0x2bb> */
	return 699ULL;
x86_l_1841:
	/* 0x1841: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1844:
	/* 0x1844: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1847:
	/* 0x1847: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_184c:
	/* 0x184c: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1851:
	/* 0x1851: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_1854:
	/* 0x1854: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1857:
	/* 0x1857: jmp    2bb <generic_usdt_filter_arg+0x2bb> */
	return 699ULL;
x86_l_185c:
	/* 0x185c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_185e:
	/* 0x185e: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1861:
	/* 0x1861: jmp    2bb <generic_usdt_filter_arg+0x2bb> */
	return 699ULL;
x86_l_1866:
	/* 0x1866: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_186b:
	/* 0x186b: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1870:
	/* 0x1870: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1874:
	/* 0x1874: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_187f:
	/* 0x187f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1884:
	/* 0x1884: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1889:
	/* 0x1889: mov    rdi,QWORD PTR [rip+0x1eaca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1890:
	/* 0x1890: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1892:
	/* 0x1892: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_1895:
	/* 0x1895: je     3205 <generic_usdt_filter_arg+0x3205> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12805ULL;
	}
x86_l_189b:
	/* 0x189b: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_189e:
	/* 0x189e: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_18a3:
	/* 0x18a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18a6:
	/* 0x18a6: je     3207 <generic_usdt_filter_arg+0x3207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12807ULL;
	}
x86_l_18ac:
	/* 0x18ac: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18b1:
	/* 0x18b1: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18b6:
	/* 0x18b6: mov    rdi,QWORD PTR [rip+0x1eaca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_18bd:
	/* 0x18bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18bf:
	/* 0x18bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18c2:
	/* 0x18c2: je     3205 <generic_usdt_filter_arg+0x3205> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12805ULL;
	}
x86_l_18c8:
	/* 0x18c8: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_18ce:
	/* 0x18ce: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_18d3:
	/* 0x18d3: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_18d6:
	/* 0x18d6: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_18dd:
	/* 0x18dd: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18df:
	/* 0x18df: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_18e2:
	/* 0x18e2: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_18e6:
	/* 0x18e6: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_18e9:
	/* 0x18e9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18ee:
	/* 0x18ee: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18f2:
	/* 0x18f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18f4:
	/* 0x18f4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18f9:
	/* 0x18f9: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_18fc:
	/* 0x18fc: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_18ff:
	/* 0x18ff: jmp    31f9 <generic_usdt_filter_arg+0x31f9> */
	return 12793ULL;
x86_l_1904:
	/* 0x1904: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_190f:
	/* 0x190f: cmp    ebp,0x1fe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 510ULL);
x86_l_1915:
	/* 0x1915: jbe    1fbe <generic_usdt_filter_arg+0x1fbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 8126ULL;
	}
x86_l_191b:
	/* 0x191b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_191d:
	/* 0x191d: jmp    3216 <generic_usdt_filter_arg+0x3216> */
	return 12822ULL;
x86_l_1922:
	/* 0x1922: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1924:
	/* 0x1924: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1929:
	/* 0x1929: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_192e:
	/* 0x192e: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_1931:
	/* 0x1931: jmp    2b6 <generic_usdt_filter_arg+0x2b6> */
	return 694ULL;
x86_l_1936:
	/* 0x1936: cmp    eax,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 30ULL);
x86_l_1939:
	/* 0x1939: jne    10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 269ULL;
	}
x86_l_193f:
	/* 0x193f: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1944:
	/* 0x1944: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_1947:
	/* 0x1947: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1949:
	/* 0x1949: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_1952:
	/* 0x1952: jne    10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 269ULL;
	}
x86_l_1958:
	/* 0x1958: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_195c:
	/* 0x195c: mov    rcx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_195f:
	/* 0x195f: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_1967:
	/* 0x1967: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_196c:
	/* 0x196c: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
	return 6510ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_usdt_filter_arg_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6510ULL: goto x86_l_196e;
	case 6520ULL: goto x86_l_1978;
	case 6523ULL: goto x86_l_197b;
	case 6528ULL: goto x86_l_1980;
	case 6532ULL: goto x86_l_1984;
	case 6534ULL: goto x86_l_1986;
	case 6539ULL: goto x86_l_198b;
	case 6542ULL: goto x86_l_198e;
	case 6547ULL: goto x86_l_1993;
	case 6551ULL: goto x86_l_1997;
	case 6553ULL: goto x86_l_1999;
	case 6558ULL: goto x86_l_199e;
	case 6561ULL: goto x86_l_19a1;
	case 6566ULL: goto x86_l_19a6;
	case 6569ULL: goto x86_l_19a9;
	case 6574ULL: goto x86_l_19ae;
	case 6579ULL: goto x86_l_19b3;
	case 6584ULL: goto x86_l_19b8;
	case 6587ULL: goto x86_l_19bb;
	case 6590ULL: goto x86_l_19be;
	case 6592ULL: goto x86_l_19c0;
	case 6597ULL: goto x86_l_19c5;
	case 6600ULL: goto x86_l_19c8;
	case 6603ULL: goto x86_l_19cb;
	case 6605ULL: goto x86_l_19cd;
	case 6608ULL: goto x86_l_19d0;
	case 6613ULL: goto x86_l_19d5;
	case 6616ULL: goto x86_l_19d8;
	case 6622ULL: goto x86_l_19de;
	case 6626ULL: goto x86_l_19e2;
	case 6630ULL: goto x86_l_19e6;
	case 6634ULL: goto x86_l_19ea;
	case 6639ULL: goto x86_l_19ef;
	case 6646ULL: goto x86_l_19f6;
	case 6651ULL: goto x86_l_19fb;
	case 6654ULL: goto x86_l_19fe;
	case 6656ULL: goto x86_l_1a00;
	case 6659ULL: goto x86_l_1a03;
	case 6664ULL: goto x86_l_1a08;
	case 6671ULL: goto x86_l_1a0f;
	case 6674ULL: goto x86_l_1a12;
	case 6676ULL: goto x86_l_1a14;
	case 6679ULL: goto x86_l_1a17;
	case 6685ULL: goto x86_l_1a1d;
	case 6690ULL: goto x86_l_1a22;
	case 6693ULL: goto x86_l_1a25;
	case 6698ULL: goto x86_l_1a2a;
	case 6703ULL: goto x86_l_1a2f;
	case 6708ULL: goto x86_l_1a34;
	case 6714ULL: goto x86_l_1a3a;
	case 6717ULL: goto x86_l_1a3d;
	case 6725ULL: goto x86_l_1a45;
	case 6729ULL: goto x86_l_1a49;
	case 6733ULL: goto x86_l_1a4d;
	case 6738ULL: goto x86_l_1a52;
	case 6743ULL: goto x86_l_1a57;
	case 6749ULL: goto x86_l_1a5d;
	case 6752ULL: goto x86_l_1a60;
	case 6755ULL: goto x86_l_1a63;
	case 6759ULL: goto x86_l_1a67;
	case 6764ULL: goto x86_l_1a6c;
	case 6766ULL: goto x86_l_1a6e;
	case 6768ULL: goto x86_l_1a70;
	case 6770ULL: goto x86_l_1a72;
	case 6776ULL: goto x86_l_1a78;
	case 6784ULL: goto x86_l_1a80;
	case 6787ULL: goto x86_l_1a83;
	case 6789ULL: goto x86_l_1a85;
	case 6795ULL: goto x86_l_1a8b;
	case 6800ULL: goto x86_l_1a90;
	case 6808ULL: goto x86_l_1a98;
	case 6813ULL: goto x86_l_1a9d;
	case 6816ULL: goto x86_l_1aa0;
	case 6819ULL: goto x86_l_1aa3;
	case 6824ULL: goto x86_l_1aa8;
	case 6829ULL: goto x86_l_1aad;
	case 6833ULL: goto x86_l_1ab1;
	case 6838ULL: goto x86_l_1ab6;
	case 6845ULL: goto x86_l_1abd;
	case 6850ULL: goto x86_l_1ac2;
	case 6852ULL: goto x86_l_1ac4;
	case 6855ULL: goto x86_l_1ac7;
	case 6861ULL: goto x86_l_1acd;
	case 6864ULL: goto x86_l_1ad0;
	case 6875ULL: goto x86_l_1adb;
	case 6883ULL: goto x86_l_1ae3;
	case 6890ULL: goto x86_l_1aea;
	case 6897ULL: goto x86_l_1af1;
	case 6901ULL: goto x86_l_1af5;
	case 6908ULL: goto x86_l_1afc;
	case 6913ULL: goto x86_l_1b01;
	case 6918ULL: goto x86_l_1b06;
	case 6920ULL: goto x86_l_1b08;
	case 6925ULL: goto x86_l_1b0d;
	case 6928ULL: goto x86_l_1b10;
	case 6931ULL: goto x86_l_1b13;
	case 6937ULL: goto x86_l_1b19;
	case 6940ULL: goto x86_l_1b1c;
	case 6943ULL: goto x86_l_1b1f;
	case 6948ULL: goto x86_l_1b24;
	case 6953ULL: goto x86_l_1b29;
	case 6958ULL: goto x86_l_1b2e;
	case 6960ULL: goto x86_l_1b30;
	case 6963ULL: goto x86_l_1b33;
	case 6966ULL: goto x86_l_1b36;
	case 6969ULL: goto x86_l_1b39;
	case 6974ULL: goto x86_l_1b3e;
	case 6976ULL: goto x86_l_1b40;
	case 6979ULL: goto x86_l_1b43;
	case 6984ULL: goto x86_l_1b48;
	case 6988ULL: goto x86_l_1b4c;
	case 6991ULL: goto x86_l_1b4f;
	case 6994ULL: goto x86_l_1b52;
	case 6996ULL: goto x86_l_1b54;
	case 6999ULL: goto x86_l_1b57;
	case 7005ULL: goto x86_l_1b5d;
	case 7010ULL: goto x86_l_1b62;
	case 7013ULL: goto x86_l_1b65;
	case 7019ULL: goto x86_l_1b6b;
	case 7024ULL: goto x86_l_1b70;
	case 7029ULL: goto x86_l_1b75;
	case 7032ULL: goto x86_l_1b78;
	case 7034ULL: goto x86_l_1b7a;
	case 7037ULL: goto x86_l_1b7d;
	case 7043ULL: goto x86_l_1b83;
	case 7046ULL: goto x86_l_1b86;
	case 7051ULL: goto x86_l_1b8b;
	case 7057ULL: goto x86_l_1b91;
	case 7060ULL: goto x86_l_1b94;
	case 7066ULL: goto x86_l_1b9a;
	case 7071ULL: goto x86_l_1b9f;
	case 7075ULL: goto x86_l_1ba3;
	case 7078ULL: goto x86_l_1ba6;
	case 7081ULL: goto x86_l_1ba9;
	case 7085ULL: goto x86_l_1bad;
	case 7088ULL: goto x86_l_1bb0;
	case 7091ULL: goto x86_l_1bb3;
	case 7094ULL: goto x86_l_1bb6;
	case 7099ULL: goto x86_l_1bbb;
	case 7102ULL: goto x86_l_1bbe;
	case 7108ULL: goto x86_l_1bc4;
	case 7113ULL: goto x86_l_1bc9;
	case 7118ULL: goto x86_l_1bce;
	case 7121ULL: goto x86_l_1bd1;
	case 7123ULL: goto x86_l_1bd3;
	case 7126ULL: goto x86_l_1bd6;
	case 7132ULL: goto x86_l_1bdc;
	case 7135ULL: goto x86_l_1bdf;
	case 7139ULL: goto x86_l_1be3;
	case 7142ULL: goto x86_l_1be6;
	case 7146ULL: goto x86_l_1bea;
	case 7151ULL: goto x86_l_1bef;
	case 7155ULL: goto x86_l_1bf3;
	case 7158ULL: goto x86_l_1bf6;
	case 7164ULL: goto x86_l_1bfc;
	case 7168ULL: goto x86_l_1c00;
	case 7173ULL: goto x86_l_1c05;
	case 7180ULL: goto x86_l_1c0c;
	case 7185ULL: goto x86_l_1c11;
	case 7187ULL: goto x86_l_1c13;
	case 7190ULL: goto x86_l_1c16;
	case 7196ULL: goto x86_l_1c1c;
	case 7199ULL: goto x86_l_1c1f;
	case 7202ULL: goto x86_l_1c22;
	case 7210ULL: goto x86_l_1c2a;
	case 7215ULL: goto x86_l_1c2f;
	case 7220ULL: goto x86_l_1c34;
	case 7222ULL: goto x86_l_1c36;
	case 7227ULL: goto x86_l_1c3b;
	case 7229ULL: goto x86_l_1c3d;
	case 7232ULL: goto x86_l_1c40;
	case 7238ULL: goto x86_l_1c46;
	case 7243ULL: goto x86_l_1c4b;
	case 7246ULL: goto x86_l_1c4e;
	case 7251ULL: goto x86_l_1c53;
	case 7256ULL: goto x86_l_1c58;
	case 7259ULL: goto x86_l_1c5b;
	case 7265ULL: goto x86_l_1c61;
	case 7270ULL: goto x86_l_1c66;
	case 7273ULL: goto x86_l_1c69;
	case 7279ULL: goto x86_l_1c6f;
	case 7282ULL: goto x86_l_1c72;
	case 7285ULL: goto x86_l_1c75;
	case 7290ULL: goto x86_l_1c7a;
	case 7294ULL: goto x86_l_1c7e;
	case 7297ULL: goto x86_l_1c81;
	case 7303ULL: goto x86_l_1c87;
	case 7305ULL: goto x86_l_1c89;
	case 7309ULL: goto x86_l_1c8d;
	case 7312ULL: goto x86_l_1c90;
	case 7318ULL: goto x86_l_1c96;
	case 7323ULL: goto x86_l_1c9b;
	case 7326ULL: goto x86_l_1c9e;
	case 7332ULL: goto x86_l_1ca4;
	case 7337ULL: goto x86_l_1ca9;
	case 7340ULL: goto x86_l_1cac;
	case 7342ULL: goto x86_l_1cae;
	case 7345ULL: goto x86_l_1cb1;
	case 7348ULL: goto x86_l_1cb4;
	case 7350ULL: goto x86_l_1cb6;
	case 7354ULL: goto x86_l_1cba;
	case 7357ULL: goto x86_l_1cbd;
	case 7362ULL: goto x86_l_1cc2;
	case 7368ULL: goto x86_l_1cc8;
	case 7373ULL: goto x86_l_1ccd;
	case 7376ULL: goto x86_l_1cd0;
	case 7382ULL: goto x86_l_1cd6;
	case 7385ULL: goto x86_l_1cd9;
	case 7391ULL: goto x86_l_1cdf;
	case 7394ULL: goto x86_l_1ce2;
	case 7396ULL: goto x86_l_1ce4;
	case 7399ULL: goto x86_l_1ce7;
	case 7405ULL: goto x86_l_1ced;
	case 7409ULL: goto x86_l_1cf1;
	case 7412ULL: goto x86_l_1cf4;
	case 7418ULL: goto x86_l_1cfa;
	case 7423ULL: goto x86_l_1cff;
	case 7426ULL: goto x86_l_1d02;
	case 7431ULL: goto x86_l_1d07;
	case 7437ULL: goto x86_l_1d0d;
	case 7441ULL: goto x86_l_1d11;
	case 7444ULL: goto x86_l_1d14;
	case 7450ULL: goto x86_l_1d1a;
	case 7455ULL: goto x86_l_1d1f;
	case 7458ULL: goto x86_l_1d22;
	case 7464ULL: goto x86_l_1d28;
	case 7468ULL: goto x86_l_1d2c;
	case 7471ULL: goto x86_l_1d2f;
	case 7473ULL: goto x86_l_1d31;
	case 7479ULL: goto x86_l_1d37;
	case 7484ULL: goto x86_l_1d3c;
	case 7487ULL: goto x86_l_1d3f;
	case 7493ULL: goto x86_l_1d45;
	case 7497ULL: goto x86_l_1d49;
	case 7500ULL: goto x86_l_1d4c;
	case 7502ULL: goto x86_l_1d4e;
	case 7508ULL: goto x86_l_1d54;
	case 7513ULL: goto x86_l_1d59;
	case 7518ULL: goto x86_l_1d5e;
	case 7521ULL: goto x86_l_1d61;
	case 7524ULL: goto x86_l_1d64;
	case 7529ULL: goto x86_l_1d69;
	case 7532ULL: goto x86_l_1d6c;
	case 7537ULL: goto x86_l_1d71;
	case 7542ULL: goto x86_l_1d76;
	case 7547ULL: goto x86_l_1d7b;
	case 7550ULL: goto x86_l_1d7e;
	case 7553ULL: goto x86_l_1d81;
	case 7555ULL: goto x86_l_1d83;
	case 7560ULL: goto x86_l_1d88;
	case 7563ULL: goto x86_l_1d8b;
	case 7566ULL: goto x86_l_1d8e;
	case 7568ULL: goto x86_l_1d90;
	case 7571ULL: goto x86_l_1d93;
	case 7576ULL: goto x86_l_1d98;
	case 7579ULL: goto x86_l_1d9b;
	case 7585ULL: goto x86_l_1da1;
	case 7592ULL: goto x86_l_1da8;
	case 7596ULL: goto x86_l_1dac;
	case 7600ULL: goto x86_l_1db0;
	case 7604ULL: goto x86_l_1db4;
	case 7609ULL: goto x86_l_1db9;
	case 7616ULL: goto x86_l_1dc0;
	case 7621ULL: goto x86_l_1dc5;
	case 7624ULL: goto x86_l_1dc8;
	case 7626ULL: goto x86_l_1dca;
	case 7631ULL: goto x86_l_1dcf;
	case 7636ULL: goto x86_l_1dd4;
	case 7643ULL: goto x86_l_1ddb;
	case 7646ULL: goto x86_l_1dde;
	case 7648ULL: goto x86_l_1de0;
	case 7654ULL: goto x86_l_1de6;
	case 7660ULL: goto x86_l_1dec;
	case 7665ULL: goto x86_l_1df1;
	case 7668ULL: goto x86_l_1df4;
	case 7673ULL: goto x86_l_1df9;
	case 7678ULL: goto x86_l_1dfe;
	case 7683ULL: goto x86_l_1e03;
	case 7689ULL: goto x86_l_1e09;
	case 7692ULL: goto x86_l_1e0c;
	case 7697ULL: goto x86_l_1e11;
	case 7703ULL: goto x86_l_1e17;
	case 7708ULL: goto x86_l_1e1c;
	case 7711ULL: goto x86_l_1e1f;
	case 7715ULL: goto x86_l_1e23;
	case 7720ULL: goto x86_l_1e28;
	case 7724ULL: goto x86_l_1e2c;
	case 7726ULL: goto x86_l_1e2e;
	case 7728ULL: goto x86_l_1e30;
	case 7736ULL: goto x86_l_1e38;
	case 7738ULL: goto x86_l_1e3a;
	case 7744ULL: goto x86_l_1e40;
	case 7749ULL: goto x86_l_1e45;
	case 7753ULL: goto x86_l_1e49;
	case 7756ULL: goto x86_l_1e4c;
	case 7758ULL: goto x86_l_1e4e;
	case 7764ULL: goto x86_l_1e54;
	case 7769ULL: goto x86_l_1e59;
	case 7772ULL: goto x86_l_1e5c;
	case 7777ULL: goto x86_l_1e61;
	case 7780ULL: goto x86_l_1e64;
	case 7782ULL: goto x86_l_1e66;
	case 7785ULL: goto x86_l_1e69;
	case 7791ULL: goto x86_l_1e6f;
	case 7795ULL: goto x86_l_1e73;
	case 7798ULL: goto x86_l_1e76;
	case 7804ULL: goto x86_l_1e7c;
	case 7809ULL: goto x86_l_1e81;
	case 7814ULL: goto x86_l_1e86;
	case 7818ULL: goto x86_l_1e8a;
	case 7821ULL: goto x86_l_1e8d;
	case 7823ULL: goto x86_l_1e8f;
	case 7828ULL: goto x86_l_1e94;
	case 7832ULL: goto x86_l_1e98;
	case 7835ULL: goto x86_l_1e9b;
	case 7840ULL: goto x86_l_1ea0;
	case 7844ULL: goto x86_l_1ea4;
	case 7849ULL: goto x86_l_1ea9;
	case 7852ULL: goto x86_l_1eac;
	case 7855ULL: goto x86_l_1eaf;
	case 7858ULL: goto x86_l_1eb2;
	case 7864ULL: goto x86_l_1eb8;
	case 7869ULL: goto x86_l_1ebd;
	case 7873ULL: goto x86_l_1ec1;
	case 7878ULL: goto x86_l_1ec6;
	case 7882ULL: goto x86_l_1eca;
	case 7885ULL: goto x86_l_1ecd;
	case 7888ULL: goto x86_l_1ed0;
	case 7891ULL: goto x86_l_1ed3;
	case 7897ULL: goto x86_l_1ed9;
	case 7902ULL: goto x86_l_1ede;
	case 7906ULL: goto x86_l_1ee2;
	case 7911ULL: goto x86_l_1ee7;
	case 7915ULL: goto x86_l_1eeb;
	case 7918ULL: goto x86_l_1eee;
	case 7921ULL: goto x86_l_1ef1;
	case 7924ULL: goto x86_l_1ef4;
	case 7930ULL: goto x86_l_1efa;
	case 7935ULL: goto x86_l_1eff;
	case 7938ULL: goto x86_l_1f02;
	case 7943ULL: goto x86_l_1f07;
	case 7946ULL: goto x86_l_1f0a;
	case 7948ULL: goto x86_l_1f0c;
	case 7950ULL: goto x86_l_1f0e;
	case 7955ULL: goto x86_l_1f13;
	case 7957ULL: goto x86_l_1f15;
	case 7960ULL: goto x86_l_1f18;
	case 7963ULL: goto x86_l_1f1b;
	case 7968ULL: goto x86_l_1f20;
	case 7972ULL: goto x86_l_1f24;
	case 7977ULL: goto x86_l_1f29;
	case 7982ULL: goto x86_l_1f2e;
	case 7989ULL: goto x86_l_1f35;
	case 7991ULL: goto x86_l_1f37;
	case 7994ULL: goto x86_l_1f3a;
	case 8000ULL: goto x86_l_1f40;
	case 8003ULL: goto x86_l_1f43;
	case 8008ULL: goto x86_l_1f48;
	case 8011ULL: goto x86_l_1f4b;
	case 8016ULL: goto x86_l_1f50;
	case 8018ULL: goto x86_l_1f52;
	case 8022ULL: goto x86_l_1f56;
	case 8024ULL: goto x86_l_1f58;
	case 8026ULL: goto x86_l_1f5a;
	case 8029ULL: goto x86_l_1f5d;
	case 8032ULL: goto x86_l_1f60;
	case 8035ULL: goto x86_l_1f63;
	case 8037ULL: goto x86_l_1f65;
	case 8039ULL: goto x86_l_1f67;
	case 8043ULL: goto x86_l_1f6b;
	case 8046ULL: goto x86_l_1f6e;
	case 8048ULL: goto x86_l_1f70;
	case 8052ULL: goto x86_l_1f74;
	case 8055ULL: goto x86_l_1f77;
	case 8057ULL: goto x86_l_1f79;
	case 8061ULL: goto x86_l_1f7d;
	case 8063ULL: goto x86_l_1f7f;
	case 8067ULL: goto x86_l_1f83;
	case 8071ULL: goto x86_l_1f87;
	case 8074ULL: goto x86_l_1f8a;
	case 8076ULL: goto x86_l_1f8c;
	case 8078ULL: goto x86_l_1f8e;
	case 8080ULL: goto x86_l_1f90;
	case 8086ULL: goto x86_l_1f96;
	default: return 0xffffffffffffffffULL;
	}
x86_l_196e:
	/* 0x196e: andn   rax,rcx,QWORD PTR [r14+rax*1+0x90] */
	X86_SIM_L_EXEC_ANDN_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_R14)), 144ULL);
x86_l_1978:
	/* 0x1978: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_197b:
	/* 0x197b: jmp    2bb <generic_usdt_filter_arg+0x2bb> */
	return 699ULL;
x86_l_1980:
	/* 0x1980: movzx  eax,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1984:
	/* 0x1984: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1986:
	/* 0x1986: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_198b:
	/* 0x198b: setb   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_B);
x86_l_198e:
	/* 0x198e: jmp    2b6 <generic_usdt_filter_arg+0x2b6> */
	return 694ULL;
x86_l_1993:
	/* 0x1993: movzx  eax,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1997:
	/* 0x1997: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1999:
	/* 0x1999: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_199e:
	/* 0x199e: setae  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_AE);
x86_l_19a1:
	/* 0x19a1: jmp    2b6 <generic_usdt_filter_arg+0x2b6> */
	return 694ULL;
x86_l_19a6:
	/* 0x19a6: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_19a9:
	/* 0x19a9: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_19ae:
	/* 0x19ae: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_19b3:
	/* 0x19b3: mov    eax,0x1fe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 510ULL);
x86_l_19b8:
	/* 0x19b8: cmovae edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_19bb:
	/* 0x19bb: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_19be:
	/* 0x19be: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19c0:
	/* 0x19c0: cmp    eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_19c5:
	/* 0x19c5: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_19c8:
	/* 0x19c8: xor    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 7ULL);
x86_l_19cb:
	/* 0x19cb: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_19cd:
	/* 0x19cd: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_19d0:
	/* 0x19d0: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_19d5:
	/* 0x19d5: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_19d8:
	/* 0x19d8: je     2d94 <generic_usdt_filter_arg+0x2d94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11668ULL;
	}
x86_l_19de:
	/* 0x19de: mov    DWORD PTR [rsp+0x7c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_19e2:
	/* 0x19e2: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_19e6:
	/* 0x19e6: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19ea:
	/* 0x19ea: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19ef:
	/* 0x19ef: mov    rdi,QWORD PTR [rip+0x1eaca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_19f6:
	/* 0x19f6: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19fb:
	/* 0x19fb: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_19fe:
	/* 0x19fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a00:
	/* 0x1a00: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1a03:
	/* 0x1a03: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a08:
	/* 0x1a08: mov    rdi,QWORD PTR [rip+0x1eaca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1a0f:
	/* 0x1a0f: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1a12:
	/* 0x1a12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a14:
	/* 0x1a14: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1a17:
	/* 0x1a17: je     2d94 <generic_usdt_filter_arg+0x2d94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11668ULL;
	}
x86_l_1a1d:
	/* 0x1a1d: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1a22:
	/* 0x1a22: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a25:
	/* 0x1a25: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a2a:
	/* 0x1a2a: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a2f:
	/* 0x1a2f: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a34:
	/* 0x1a34: je     2da5 <generic_usdt_filter_arg+0x2da5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11685ULL;
	}
x86_l_1a3a:
	/* 0x1a3a: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1a3d:
	/* 0x1a3d: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a45:
	/* 0x1a45: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a49:
	/* 0x1a49: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1a4d:
	/* 0x1a4d: movzx  ebx,WORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 124ULL);
x86_l_1a52:
	/* 0x1a52: cmp    DWORD PTR [rsp+0x20],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953477ULL);
x86_l_1a57:
	/* 0x1a57: jg     23d2 <generic_usdt_filter_arg+0x23d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9170ULL;
	}
x86_l_1a5d:
	/* 0x1a5d: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_1a60:
	/* 0x1a60: mov    BYTE PTR [rcx],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a63:
	/* 0x1a63: lea    rdi,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1a67:
	/* 0x1a67: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a6c:
	/* 0x1a6c: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1a6e:
	/* 0x1a6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a70:
	/* 0x1a70: cmp    ebx,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RBP, X86_WIDTH_32);
x86_l_1a72:
	/* 0x1a72: jbe    240d <generic_usdt_filter_arg+0x240d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 9229ULL;
	}
x86_l_1a78:
	/* 0x1a78: lea    rdi,[rbp*1+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 1ULL);
x86_l_1a80:
	/* 0x1a80: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a83:
	/* 0x1a83: sub    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1a85:
	/* 0x1a85: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a8b:
	/* 0x1a8b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a90:
	/* 0x1a90: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a98:
	/* 0x1a98: jmp    2409 <generic_usdt_filter_arg+0x2409> */
	return 9225ULL;
x86_l_1a9d:
	/* 0x1a9d: mov    rbx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R8, X86_WIDTH_64);
x86_l_1aa0:
	/* 0x1aa0: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_1aa3:
	/* 0x1aa3: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1aa8:
	/* 0x1aa8: mov    eax,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1aad:
	/* 0x1aad: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1ab1:
	/* 0x1ab1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ab6:
	/* 0x1ab6: mov    rdi,QWORD PTR [rip+0x1eaca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_1abd:
	/* 0x1abd: lea    rsi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1ac2:
	/* 0x1ac2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ac4:
	/* 0x1ac4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ac7:
	/* 0x1ac7: je     1d59 <generic_usdt_filter_arg+0x1d59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d59;
	}
x86_l_1acd:
	/* 0x1acd: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1ad0:
	/* 0x1ad0: mov    DWORD PTR [rsp+0x80],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755814016ULL);
x86_l_1adb:
	/* 0x1adb: mov    DWORD PTR [rsp+0x84],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_1ae3:
	/* 0x1ae3: mov    DWORD PTR [rsp+0x88],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1aea:
	/* 0x1aea: mov    DWORD PTR [rsp+0x8c],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_1af1:
	/* 0x1af1: shr    rbx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1af5:
	/* 0x1af5: mov    DWORD PTR [rsp+0x90],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1afc:
	/* 0x1afc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b01:
	/* 0x1b01: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b06:
	/* 0x1b06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b08:
	/* 0x1b08: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b0d:
	/* 0x1b0d: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_1b10:
	/* 0x1b10: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1b13:
	/* 0x1b13: jb     20b3 <generic_usdt_filter_arg+0x20b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8371ULL;
	}
x86_l_1b19:
	/* 0x1b19: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_1b1c:
	/* 0x1b1c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1b1f:
	/* 0x1b1f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b24:
	/* 0x1b24: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b29:
	/* 0x1b29: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b2e:
	/* 0x1b2e: ja     1b3e <generic_usdt_filter_arg+0x1b3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b3e;
	}
x86_l_1b30:
	/* 0x1b30: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b33:
	/* 0x1b33: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1b36:
	/* 0x1b36: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b39:
	/* 0x1b39: jmp    2b6 <generic_usdt_filter_arg+0x2b6> */
	return 694ULL;
x86_l_1b3e:
	/* 0x1b3e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b40:
	/* 0x1b40: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b43:
	/* 0x1b43: jmp    2b6 <generic_usdt_filter_arg+0x2b6> */
	return 694ULL;
x86_l_1b48:
	/* 0x1b48: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b4c:
	/* 0x1b4c: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b4f:
	/* 0x1b4f: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1b52:
	/* 0x1b52: ja     1b5d <generic_usdt_filter_arg+0x1b5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b5d;
	}
x86_l_1b54:
	/* 0x1b54: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1b57:
	/* 0x1b57: jbe    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 716ULL;
	}
x86_l_1b5d:
	/* 0x1b5d: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b62:
	/* 0x1b62: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1b65:
	/* 0x1b65: jb     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 269ULL;
	}
x86_l_1b6b:
	/* 0x1b6b: mov    rdi,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b70:
	/* 0x1b70: mov    rsi,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b75:
	/* 0x1b75: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1b78:
	/* 0x1b78: je     1b83 <generic_usdt_filter_arg+0x1b83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b83;
	}
x86_l_1b7a:
	/* 0x1b7a: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1b7d:
	/* 0x1b7d: jne    21cc <generic_usdt_filter_arg+0x21cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8652ULL;
	}
x86_l_1b83:
	/* 0x1b83: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1b86:
	/* 0x1b86: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b8b:
	/* 0x1b8b: jg     21df <generic_usdt_filter_arg+0x21df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8671ULL;
	}
x86_l_1b91:
	/* 0x1b91: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_1b94:
	/* 0x1b94: jle    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 716ULL;
	}
x86_l_1b9a:
	/* 0x1b9a: jmp    21df <generic_usdt_filter_arg+0x21df> */
	return 8671ULL;
x86_l_1b9f:
	/* 0x1b9f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ba3:
	/* 0x1ba3: mov    rdx,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ba6:
	/* 0x1ba6: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1ba9:
	/* 0x1ba9: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1bad:
	/* 0x1bad: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1bb0:
	/* 0x1bb0: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1bb3:
	/* 0x1bb3: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1bb6:
	/* 0x1bb6: mov    esi,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bbb:
	/* 0x1bbb: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_1bbe:
	/* 0x1bbe: jb     2dc2 <generic_usdt_filter_arg+0x2dc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11714ULL;
	}
x86_l_1bc4:
	/* 0x1bc4: mov    r8,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bc9:
	/* 0x1bc9: mov    rdi,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bce:
	/* 0x1bce: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1bd1:
	/* 0x1bd1: je     1bdc <generic_usdt_filter_arg+0x1bdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bdc;
	}
x86_l_1bd3:
	/* 0x1bd3: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1bd6:
	/* 0x1bd6: jne    2184 <generic_usdt_filter_arg+0x2184> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8580ULL;
	}
x86_l_1bdc:
	/* 0x1bdc: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_1bdf:
	/* 0x1bdf: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1be3:
	/* 0x1be3: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1be6:
	/* 0x1be6: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_1bea:
	/* 0x1bea: jmp    2192 <generic_usdt_filter_arg+0x2192> */
	return 8594ULL;
x86_l_1bef:
	/* 0x1bef: movzx  ebx,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1bf3:
	/* 0x1bf3: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_1bf6:
	/* 0x1bf6: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1bfc:
	/* 0x1bfc: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1c00:
	/* 0x1c00: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c05:
	/* 0x1c05: mov    rdi,QWORD PTR [rip+0x1eaca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1c0c:
	/* 0x1c0c: lea    rsi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1c11:
	/* 0x1c11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c13:
	/* 0x1c13: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c16:
	/* 0x1c16: je     227b <generic_usdt_filter_arg+0x227b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8827ULL;
	}
x86_l_1c1c:
	/* 0x1c1c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1c1f:
	/* 0x1c1f: movzx  eax,bx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1c22:
	/* 0x1c22: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c2a:
	/* 0x1c2a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c2f:
	/* 0x1c2f: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c34:
	/* 0x1c34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c36:
	/* 0x1c36: mov    edx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c3b:
	/* 0x1c3b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c3d:
	/* 0x1c3d: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1c40:
	/* 0x1c40: ja     2bfc <generic_usdt_filter_arg+0x2bfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11260ULL;
	}
x86_l_1c46:
	/* 0x1c46: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1c4b:
	/* 0x1c4b: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1c4e:
	/* 0x1c4e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c53:
	/* 0x1c53: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c58:
	/* 0x1c58: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_1c5b:
	/* 0x1c5b: jb     2ad <generic_usdt_filter_arg+0x2ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 685ULL;
	}
x86_l_1c61:
	/* 0x1c61: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_1c66:
	/* 0x1c66: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1c69:
	/* 0x1c69: jae    2b3 <generic_usdt_filter_arg+0x2b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 691ULL;
	}
x86_l_1c6f:
	/* 0x1c6f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c72:
	/* 0x1c72: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1c75:
	/* 0x1c75: jmp    2b3 <generic_usdt_filter_arg+0x2b3> */
	return 691ULL;
x86_l_1c7a:
	/* 0x1c7a: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c7e:
	/* 0x1c7e: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c81:
	/* 0x1c81: ja     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_1c87:
	/* 0x1c87: jmp    1c96 <generic_usdt_filter_arg+0x1c96> */
	goto x86_l_1c96;
x86_l_1c89:
	/* 0x1c89: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c8d:
	/* 0x1c8d: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c90:
	/* 0x1c90: jb     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_1c96:
	/* 0x1c96: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c9b:
	/* 0x1c9b: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1c9e:
	/* 0x1c9e: jb     32b7 <generic_usdt_filter_arg+0x32b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12983ULL;
	}
x86_l_1ca4:
	/* 0x1ca4: mov    rsi,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ca9:
	/* 0x1ca9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1cac:
	/* 0x1cac: jle    1ccd <generic_usdt_filter_arg+0x1ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ccd;
	}
x86_l_1cae:
	/* 0x1cae: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1cb1:
	/* 0x1cb1: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_1cb4:
	/* 0x1cb4: jae    1cff <generic_usdt_filter_arg+0x1cff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1cff;
	}
x86_l_1cb6:
	/* 0x1cb6: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cba:
	/* 0x1cba: cmp    QWORD PTR [rdi],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cbd:
	/* 0x1cbd: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cc2:
	/* 0x1cc2: jne    2802 <generic_usdt_filter_arg+0x2802> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10242ULL;
	}
x86_l_1cc8:
	/* 0x1cc8: jmp    31a4 <generic_usdt_filter_arg+0x31a4> */
	return 12708ULL;
x86_l_1ccd:
	/* 0x1ccd: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cd0:
	/* 0x1cd0: je     1e61 <generic_usdt_filter_arg+0x1e61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e61;
	}
x86_l_1cd6:
	/* 0x1cd6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1cd9:
	/* 0x1cd9: jne    2802 <generic_usdt_filter_arg+0x2802> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10242ULL;
	}
x86_l_1cdf:
	/* 0x1cdf: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1ce2:
	/* 0x1ce2: je     1ced <generic_usdt_filter_arg+0x1ced> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ced;
	}
x86_l_1ce4:
	/* 0x1ce4: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1ce7:
	/* 0x1ce7: jne    27f5 <generic_usdt_filter_arg+0x27f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10229ULL;
	}
x86_l_1ced:
	/* 0x1ced: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cf1:
	/* 0x1cf1: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cf4:
	/* 0x1cf4: jl     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 716ULL;
	}
x86_l_1cfa:
	/* 0x1cfa: jmp    2802 <generic_usdt_filter_arg+0x2802> */
	return 10242ULL;
x86_l_1cff:
	/* 0x1cff: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1d02:
	/* 0x1d02: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d07:
	/* 0x1d07: jne    2802 <generic_usdt_filter_arg+0x2802> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10242ULL;
	}
x86_l_1d0d:
	/* 0x1d0d: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d11:
	/* 0x1d11: test   QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d14:
	/* 0x1d14: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_1d1a:
	/* 0x1d1a: jmp    2802 <generic_usdt_filter_arg+0x2802> */
	return 10242ULL;
x86_l_1d1f:
	/* 0x1d1f: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1d22:
	/* 0x1d22: jne    202c <generic_usdt_filter_arg+0x202c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8236ULL;
	}
x86_l_1d28:
	/* 0x1d28: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d2c:
	/* 0x1d2c: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1d2f:
	/* 0x1d2f: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1d31:
	/* 0x1d31: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_1d37:
	/* 0x1d37: jmp    202c <generic_usdt_filter_arg+0x202c> */
	return 8236ULL;
x86_l_1d3c:
	/* 0x1d3c: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1d3f:
	/* 0x1d3f: jne    2077 <generic_usdt_filter_arg+0x2077> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8311ULL;
	}
x86_l_1d45:
	/* 0x1d45: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d49:
	/* 0x1d49: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d4c:
	/* 0x1d4c: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1d4e:
	/* 0x1d4e: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_1d54:
	/* 0x1d54: jmp    2077 <generic_usdt_filter_arg+0x2077> */
	return 8311ULL;
x86_l_1d59:
	/* 0x1d59: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d5e:
	/* 0x1d5e: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_1d61:
	/* 0x1d61: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_1d64:
	/* 0x1d64: jmp    20b6 <generic_usdt_filter_arg+0x20b6> */
	return 8374ULL;
x86_l_1d69:
	/* 0x1d69: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1d6c:
	/* 0x1d6c: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1d71:
	/* 0x1d71: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_1d76:
	/* 0x1d76: mov    eax,0x1fe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 510ULL);
x86_l_1d7b:
	/* 0x1d7b: cmovae esi,eax */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_1d7e:
	/* 0x1d7e: movzx  eax,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1d81:
	/* 0x1d81: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d83:
	/* 0x1d83: cmp    eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_1d88:
	/* 0x1d88: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1d8b:
	/* 0x1d8b: xor    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 7ULL);
x86_l_1d8e:
	/* 0x1d8e: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1d90:
	/* 0x1d90: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1d93:
	/* 0x1d93: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_1d98:
	/* 0x1d98: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_1d9b:
	/* 0x1d9b: je     2f47 <generic_usdt_filter_arg+0x2f47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12103ULL;
	}
x86_l_1da1:
	/* 0x1da1: mov    DWORD PTR [rsp+0x98],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1da8:
	/* 0x1da8: mov    DWORD PTR [rsp+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1dac:
	/* 0x1dac: mov    DWORD PTR [rsp+0x60],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1db0:
	/* 0x1db0: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1db4:
	/* 0x1db4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1db9:
	/* 0x1db9: mov    rdi,QWORD PTR [rip+0x1eaca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_1dc0:
	/* 0x1dc0: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1dc5:
	/* 0x1dc5: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1dc8:
	/* 0x1dc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dca:
	/* 0x1dca: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dcf:
	/* 0x1dcf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dd4:
	/* 0x1dd4: mov    rdi,QWORD PTR [rip+0x1eaca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1ddb:
	/* 0x1ddb: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1dde:
	/* 0x1dde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de0:
	/* 0x1de0: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1de6:
	/* 0x1de6: je     2f47 <generic_usdt_filter_arg+0x2f47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12103ULL;
	}
x86_l_1dec:
	/* 0x1dec: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_1df1:
	/* 0x1df1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1df4:
	/* 0x1df4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1df9:
	/* 0x1df9: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dfe:
	/* 0x1dfe: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e03:
	/* 0x1e03: je     2f58 <generic_usdt_filter_arg+0x2f58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12120ULL;
	}
x86_l_1e09:
	/* 0x1e09: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1e0c:
	/* 0x1e0c: cmp    DWORD PTR [rsp+0x60],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860421ULL);
x86_l_1e11:
	/* 0x1e11: jg     26d1 <generic_usdt_filter_arg+0x26d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9937ULL;
	}
x86_l_1e17:
	/* 0x1e17: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e1c:
	/* 0x1e1c: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e1f:
	/* 0x1e1f: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1e23:
	/* 0x1e23: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e28:
	/* 0x1e28: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e2c:
	/* 0x1e2c: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1e2e:
	/* 0x1e2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e30:
	/* 0x1e30: movzx  esi,WORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 152ULL);
x86_l_1e38:
	/* 0x1e38: cmp    esi,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1e3a:
	/* 0x1e3a: jbe    2715 <generic_usdt_filter_arg+0x2715> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 10005ULL;
	}
x86_l_1e40:
	/* 0x1e40: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e45:
	/* 0x1e45: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1e49:
	/* 0x1e49: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1e4c:
	/* 0x1e4c: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1e4e:
	/* 0x1e4e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e54:
	/* 0x1e54: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e59:
	/* 0x1e59: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1e5c:
	/* 0x1e5c: jmp    2713 <generic_usdt_filter_arg+0x2713> */
	return 10003ULL;
x86_l_1e61:
	/* 0x1e61: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1e64:
	/* 0x1e64: je     1e6f <generic_usdt_filter_arg+0x1e6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e6f;
	}
x86_l_1e66:
	/* 0x1e66: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1e69:
	/* 0x1e69: jne    27e6 <generic_usdt_filter_arg+0x27e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10214ULL;
	}
x86_l_1e6f:
	/* 0x1e6f: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e73:
	/* 0x1e73: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e76:
	/* 0x1e76: jg     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 716ULL;
	}
x86_l_1e7c:
	/* 0x1e7c: jmp    2802 <generic_usdt_filter_arg+0x2802> */
	return 10242ULL;
x86_l_1e81:
	/* 0x1e81: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e86:
	/* 0x1e86: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e8a:
	/* 0x1e8a: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1e8d:
	/* 0x1e8d: jmp    1e9b <generic_usdt_filter_arg+0x1e9b> */
	goto x86_l_1e9b;
x86_l_1e8f:
	/* 0x1e8f: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e94:
	/* 0x1e94: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e98:
	/* 0x1e98: movzx  ecx,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e9b:
	/* 0x1e9b: cmp    DWORD PTR [r12+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ea0:
	/* 0x1ea0: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1ea4:
	/* 0x1ea4: cmp    DWORD PTR [r12+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1ea9:
	/* 0x1ea9: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_1eac:
	/* 0x1eac: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1eaf:
	/* 0x1eaf: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1eb2:
	/* 0x1eb2: jb     2dc2 <generic_usdt_filter_arg+0x2dc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11714ULL;
	}
x86_l_1eb8:
	/* 0x1eb8: cmp    DWORD PTR [r12+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ebd:
	/* 0x1ebd: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1ec1:
	/* 0x1ec1: cmp    DWORD PTR [r12+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1ec6:
	/* 0x1ec6: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_1eca:
	/* 0x1eca: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1ecd:
	/* 0x1ecd: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1ed0:
	/* 0x1ed0: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1ed3:
	/* 0x1ed3: jb     2dbd <generic_usdt_filter_arg+0x2dbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11709ULL;
	}
x86_l_1ed9:
	/* 0x1ed9: cmp    DWORD PTR [r12+0x20],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ede:
	/* 0x1ede: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1ee2:
	/* 0x1ee2: cmp    DWORD PTR [r12+0x24],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1ee7:
	/* 0x1ee7: setae  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_AE);
x86_l_1eeb:
	/* 0x1eeb: and    dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_1eee:
	/* 0x1eee: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1ef1:
	/* 0x1ef1: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1ef4:
	/* 0x1ef4: jb     2dbd <generic_usdt_filter_arg+0x2dbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11709ULL;
	}
x86_l_1efa:
	/* 0x1efa: cmp    DWORD PTR [r12+0x28],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1eff:
	/* 0x1eff: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_1f02:
	/* 0x1f02: cmp    DWORD PTR [r12+0x2c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1f07:
	/* 0x1f07: setae  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_AE);
x86_l_1f0a:
	/* 0x1f0a: and    cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1f0c:
	/* 0x1f0c: or     al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1f0e:
	/* 0x1f0e: jmp    2dbd <generic_usdt_filter_arg+0x2dbd> */
	return 11709ULL;
x86_l_1f13:
	/* 0x1f13: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f15:
	/* 0x1f15: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f18:
	/* 0x1f18: mov    r15,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R11, X86_WIDTH_64);
x86_l_1f1b:
	/* 0x1f1b: mov    eax,DWORD PTR [r12+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_1f20:
	/* 0x1f20: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f24:
	/* 0x1f24: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f29:
	/* 0x1f29: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f2e:
	/* 0x1f2e: mov    rdi,QWORD PTR [rip+0x1eaca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_1f35:
	/* 0x1f35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f37:
	/* 0x1f37: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f3a:
	/* 0x1f3a: je     28f5 <generic_usdt_filter_arg+0x28f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10485ULL;
	}
x86_l_1f40:
	/* 0x1f40: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_1f43:
	/* 0x1f43: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f48:
	/* 0x1f48: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_1f4b:
	/* 0x1f4b: mov    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1f50:
	/* 0x1f50: je     1f96 <generic_usdt_filter_arg+0x1f96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f96;
	}
x86_l_1f52:
	/* 0x1f52: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f56:
	/* 0x1f56: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f58:
	/* 0x1f58: jmp    1f65 <generic_usdt_filter_arg+0x1f65> */
	goto x86_l_1f65;
x86_l_1f5a:
	/* 0x1f5a: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1f5d:
	/* 0x1f5d: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1f60:
	/* 0x1f60: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_1f63:
	/* 0x1f63: je     1f96 <generic_usdt_filter_arg+0x1f96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f96;
	}
x86_l_1f65:
	/* 0x1f65: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f67:
	/* 0x1f67: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1f6b:
	/* 0x1f6b: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1f6e:
	/* 0x1f6e: jae    1f5a <generic_usdt_filter_arg+0x1f5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f5a;
	}
x86_l_1f70:
	/* 0x1f70: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_1f74:
	/* 0x1f74: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_1f77:
	/* 0x1f77: je     1f8e <generic_usdt_filter_arg+0x1f8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f8e;
	}
x86_l_1f79:
	/* 0x1f79: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_1f7d:
	/* 0x1f7d: ja     1f5a <generic_usdt_filter_arg+0x1f5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f5a;
	}
x86_l_1f7f:
	/* 0x1f7f: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1f83:
	/* 0x1f83: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1f87:
	/* 0x1f87: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_1f8a:
	/* 0x1f8a: je     1f67 <generic_usdt_filter_arg+0x1f67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f67;
	}
x86_l_1f8c:
	/* 0x1f8c: jmp    1f5a <generic_usdt_filter_arg+0x1f5a> */
	goto x86_l_1f5a;
x86_l_1f8e:
	/* 0x1f8e: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1f90:
	/* 0x1f90: jns    2c5a <generic_usdt_filter_arg+0x2c5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 11354ULL;
	}
x86_l_1f96:
	/* 0x1f96: lea    eax,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
	return 8090ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_usdt_filter_arg_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8090ULL: goto x86_l_1f9a;
	case 8095ULL: goto x86_l_1f9f;
	case 8097ULL: goto x86_l_1fa1;
	case 8101ULL: goto x86_l_1fa5;
	case 8104ULL: goto x86_l_1fa8;
	case 8108ULL: goto x86_l_1fac;
	case 8114ULL: goto x86_l_1fb2;
	case 8116ULL: goto x86_l_1fb4;
	case 8121ULL: goto x86_l_1fb9;
	case 8126ULL: goto x86_l_1fbe;
	case 8129ULL: goto x86_l_1fc1;
	case 8134ULL: goto x86_l_1fc6;
	case 8139ULL: goto x86_l_1fcb;
	case 8145ULL: goto x86_l_1fd1;
	case 8149ULL: goto x86_l_1fd5;
	case 8155ULL: goto x86_l_1fdb;
	case 8158ULL: goto x86_l_1fde;
	case 8161ULL: goto x86_l_1fe1;
	case 8164ULL: goto x86_l_1fe4;
	case 8166ULL: goto x86_l_1fe6;
	case 8168ULL: goto x86_l_1fe8;
	case 8171ULL: goto x86_l_1feb;
	case 8173ULL: goto x86_l_1fed;
	case 8175ULL: goto x86_l_1fef;
	case 8177ULL: goto x86_l_1ff1;
	case 8179ULL: goto x86_l_1ff3;
	case 8182ULL: goto x86_l_1ff6;
	case 8184ULL: goto x86_l_1ff8;
	case 8186ULL: goto x86_l_1ffa;
	case 8188ULL: goto x86_l_1ffc;
	case 8191ULL: goto x86_l_1fff;
	case 8195ULL: goto x86_l_2003;
	case 8201ULL: goto x86_l_2009;
	case 8205ULL: goto x86_l_200d;
	case 8211ULL: goto x86_l_2013;
	case 8214ULL: goto x86_l_2016;
	case 8216ULL: goto x86_l_2018;
	case 8221ULL: goto x86_l_201d;
	case 8225ULL: goto x86_l_2021;
	case 8228ULL: goto x86_l_2024;
	case 8230ULL: goto x86_l_2026;
	case 8236ULL: goto x86_l_202c;
	case 8241ULL: goto x86_l_2031;
	case 8244ULL: goto x86_l_2034;
	case 8250ULL: goto x86_l_203a;
	case 8255ULL: goto x86_l_203f;
	case 8258ULL: goto x86_l_2042;
	case 8264ULL: goto x86_l_2048;
	case 8267ULL: goto x86_l_204b;
	case 8270ULL: goto x86_l_204e;
	case 8276ULL: goto x86_l_2054;
	case 8280ULL: goto x86_l_2058;
	case 8283ULL: goto x86_l_205b;
	case 8285ULL: goto x86_l_205d;
	case 8291ULL: goto x86_l_2063;
	case 8296ULL: goto x86_l_2068;
	case 8300ULL: goto x86_l_206c;
	case 8303ULL: goto x86_l_206f;
	case 8305ULL: goto x86_l_2071;
	case 8311ULL: goto x86_l_2077;
	case 8316ULL: goto x86_l_207c;
	case 8319ULL: goto x86_l_207f;
	case 8325ULL: goto x86_l_2085;
	case 8330ULL: goto x86_l_208a;
	case 8333ULL: goto x86_l_208d;
	case 8339ULL: goto x86_l_2093;
	case 8342ULL: goto x86_l_2096;
	case 8345ULL: goto x86_l_2099;
	case 8351ULL: goto x86_l_209f;
	case 8355ULL: goto x86_l_20a3;
	case 8358ULL: goto x86_l_20a6;
	case 8360ULL: goto x86_l_20a8;
	case 8366ULL: goto x86_l_20ae;
	case 8371ULL: goto x86_l_20b3;
	case 8374ULL: goto x86_l_20b6;
	case 8377ULL: goto x86_l_20b9;
	case 8382ULL: goto x86_l_20be;
	case 8387ULL: goto x86_l_20c3;
	case 8392ULL: goto x86_l_20c8;
	case 8395ULL: goto x86_l_20cb;
	case 8400ULL: goto x86_l_20d0;
	case 8404ULL: goto x86_l_20d4;
	case 8406ULL: goto x86_l_20d6;
	case 8408ULL: goto x86_l_20d8;
	case 8410ULL: goto x86_l_20da;
	case 8412ULL: goto x86_l_20dc;
	case 8418ULL: goto x86_l_20e2;
	case 8423ULL: goto x86_l_20e7;
	case 8426ULL: goto x86_l_20ea;
	case 8432ULL: goto x86_l_20f0;
	case 8437ULL: goto x86_l_20f5;
	case 8442ULL: goto x86_l_20fa;
	case 8445ULL: goto x86_l_20fd;
	case 8451ULL: goto x86_l_2103;
	case 8457ULL: goto x86_l_2109;
	case 8461ULL: goto x86_l_210d;
	case 8467ULL: goto x86_l_2113;
	case 8469ULL: goto x86_l_2115;
	case 8474ULL: goto x86_l_211a;
	case 8480ULL: goto x86_l_2120;
	case 8482ULL: goto x86_l_2122;
	case 8488ULL: goto x86_l_2128;
	case 8493ULL: goto x86_l_212d;
	case 8497ULL: goto x86_l_2131;
	case 8499ULL: goto x86_l_2133;
	case 8501ULL: goto x86_l_2135;
	case 8505ULL: goto x86_l_2139;
	case 8507ULL: goto x86_l_213b;
	case 8510ULL: goto x86_l_213e;
	case 8513ULL: goto x86_l_2141;
	case 8518ULL: goto x86_l_2146;
	case 8521ULL: goto x86_l_2149;
	case 8527ULL: goto x86_l_214f;
	case 8532ULL: goto x86_l_2154;
	case 8537ULL: goto x86_l_2159;
	case 8540ULL: goto x86_l_215c;
	case 8546ULL: goto x86_l_2162;
	case 8552ULL: goto x86_l_2168;
	case 8556ULL: goto x86_l_216c;
	case 8562ULL: goto x86_l_2172;
	case 8565ULL: goto x86_l_2175;
	case 8569ULL: goto x86_l_2179;
	case 8571ULL: goto x86_l_217b;
	case 8575ULL: goto x86_l_217f;
	case 8580ULL: goto x86_l_2184;
	case 8583ULL: goto x86_l_2187;
	case 8587ULL: goto x86_l_218b;
	case 8590ULL: goto x86_l_218e;
	case 8594ULL: goto x86_l_2192;
	case 8597ULL: goto x86_l_2195;
	case 8600ULL: goto x86_l_2198;
	case 8603ULL: goto x86_l_219b;
	case 8609ULL: goto x86_l_21a1;
	case 8614ULL: goto x86_l_21a6;
	case 8619ULL: goto x86_l_21ab;
	case 8622ULL: goto x86_l_21ae;
	case 8624ULL: goto x86_l_21b0;
	case 8627ULL: goto x86_l_21b3;
	case 8633ULL: goto x86_l_21b9;
	case 8636ULL: goto x86_l_21bc;
	case 8640ULL: goto x86_l_21c0;
	case 8643ULL: goto x86_l_21c3;
	case 8647ULL: goto x86_l_21c7;
	case 8652ULL: goto x86_l_21cc;
	case 8655ULL: goto x86_l_21cf;
	case 8660ULL: goto x86_l_21d4;
	case 8662ULL: goto x86_l_21d6;
	case 8665ULL: goto x86_l_21d9;
	case 8671ULL: goto x86_l_21df;
	case 8674ULL: goto x86_l_21e2;
	case 8680ULL: goto x86_l_21e8;
	case 8685ULL: goto x86_l_21ed;
	case 8690ULL: goto x86_l_21f2;
	case 8693ULL: goto x86_l_21f5;
	case 8695ULL: goto x86_l_21f7;
	case 8698ULL: goto x86_l_21fa;
	case 8704ULL: goto x86_l_2200;
	case 8707ULL: goto x86_l_2203;
	case 8712ULL: goto x86_l_2208;
	case 8718ULL: goto x86_l_220e;
	case 8721ULL: goto x86_l_2211;
	case 8727ULL: goto x86_l_2217;
	case 8732ULL: goto x86_l_221c;
	case 8734ULL: goto x86_l_221e;
	case 8737ULL: goto x86_l_2221;
	case 8739ULL: goto x86_l_2223;
	case 8742ULL: goto x86_l_2226;
	case 8744ULL: goto x86_l_2228;
	case 8748ULL: goto x86_l_222c;
	case 8751ULL: goto x86_l_222f;
	case 8753ULL: goto x86_l_2231;
	case 8756ULL: goto x86_l_2234;
	case 8762ULL: goto x86_l_223a;
	case 8765ULL: goto x86_l_223d;
	case 8771ULL: goto x86_l_2243;
	case 8775ULL: goto x86_l_2247;
	case 8780ULL: goto x86_l_224c;
	case 8787ULL: goto x86_l_2253;
	case 8792ULL: goto x86_l_2258;
	case 8794ULL: goto x86_l_225a;
	case 8797ULL: goto x86_l_225d;
	case 8799ULL: goto x86_l_225f;
	case 8802ULL: goto x86_l_2262;
	case 8804ULL: goto x86_l_2264;
	case 8812ULL: goto x86_l_226c;
	case 8817ULL: goto x86_l_2271;
	case 8822ULL: goto x86_l_2276;
	case 8827ULL: goto x86_l_227b;
	case 8829ULL: goto x86_l_227d;
	case 8834ULL: goto x86_l_2282;
	case 8839ULL: goto x86_l_2287;
	case 8842ULL: goto x86_l_228a;
	case 8847ULL: goto x86_l_228f;
	case 8851ULL: goto x86_l_2293;
	case 8853ULL: goto x86_l_2295;
	case 8859ULL: goto x86_l_229b;
	case 8861ULL: goto x86_l_229d;
	case 8865ULL: goto x86_l_22a1;
	case 8867ULL: goto x86_l_22a3;
	case 8873ULL: goto x86_l_22a9;
	case 8878ULL: goto x86_l_22ae;
	case 8881ULL: goto x86_l_22b1;
	case 8887ULL: goto x86_l_22b7;
	case 8892ULL: goto x86_l_22bc;
	case 8895ULL: goto x86_l_22bf;
	case 8897ULL: goto x86_l_22c1;
	case 8900ULL: goto x86_l_22c4;
	case 8903ULL: goto x86_l_22c7;
	case 8905ULL: goto x86_l_22c9;
	case 8909ULL: goto x86_l_22cd;
	case 8911ULL: goto x86_l_22cf;
	case 8916ULL: goto x86_l_22d4;
	case 8922ULL: goto x86_l_22da;
	case 8927ULL: goto x86_l_22df;
	case 8930ULL: goto x86_l_22e2;
	case 8932ULL: goto x86_l_22e4;
	case 8935ULL: goto x86_l_22e7;
	case 8941ULL: goto x86_l_22ed;
	case 8944ULL: goto x86_l_22f0;
	case 8950ULL: goto x86_l_22f6;
	case 8956ULL: goto x86_l_22fc;
	case 8960ULL: goto x86_l_2300;
	case 8966ULL: goto x86_l_2306;
	case 8970ULL: goto x86_l_230a;
	case 8973ULL: goto x86_l_230d;
	case 8979ULL: goto x86_l_2313;
	case 8984ULL: goto x86_l_2318;
	case 8987ULL: goto x86_l_231b;
	case 8992ULL: goto x86_l_2320;
	case 8998ULL: goto x86_l_2326;
	case 9002ULL: goto x86_l_232a;
	case 9005ULL: goto x86_l_232d;
	case 9011ULL: goto x86_l_2333;
	case 9016ULL: goto x86_l_2338;
	case 9019ULL: goto x86_l_233b;
	case 9025ULL: goto x86_l_2341;
	case 9031ULL: goto x86_l_2347;
	case 9035ULL: goto x86_l_234b;
	case 9041ULL: goto x86_l_2351;
	case 9045ULL: goto x86_l_2355;
	case 9048ULL: goto x86_l_2358;
	case 9054ULL: goto x86_l_235e;
	case 9059ULL: goto x86_l_2363;
	case 9061ULL: goto x86_l_2365;
	case 9066ULL: goto x86_l_236a;
	case 9069ULL: goto x86_l_236d;
	case 9074ULL: goto x86_l_2372;
	case 9079ULL: goto x86_l_2377;
	case 9081ULL: goto x86_l_2379;
	case 9084ULL: goto x86_l_237c;
	case 9089ULL: goto x86_l_2381;
	case 9094ULL: goto x86_l_2386;
	case 9097ULL: goto x86_l_2389;
	case 9103ULL: goto x86_l_238f;
	case 9106ULL: goto x86_l_2392;
	case 9112ULL: goto x86_l_2398;
	case 9116ULL: goto x86_l_239c;
	case 9119ULL: goto x86_l_239f;
	case 9121ULL: goto x86_l_23a1;
	case 9127ULL: goto x86_l_23a7;
	case 9132ULL: goto x86_l_23ac;
	case 9135ULL: goto x86_l_23af;
	case 9141ULL: goto x86_l_23b5;
	case 9144ULL: goto x86_l_23b8;
	case 9150ULL: goto x86_l_23be;
	case 9154ULL: goto x86_l_23c2;
	case 9157ULL: goto x86_l_23c5;
	case 9159ULL: goto x86_l_23c7;
	case 9165ULL: goto x86_l_23cd;
	case 9170ULL: goto x86_l_23d2;
	case 9173ULL: goto x86_l_23d5;
	case 9176ULL: goto x86_l_23d8;
	case 9180ULL: goto x86_l_23dc;
	case 9185ULL: goto x86_l_23e1;
	case 9187ULL: goto x86_l_23e3;
	case 9189ULL: goto x86_l_23e5;
	case 9191ULL: goto x86_l_23e7;
	case 9193ULL: goto x86_l_23e9;
	case 9201ULL: goto x86_l_23f1;
	case 9204ULL: goto x86_l_23f4;
	case 9206ULL: goto x86_l_23f6;
	case 9212ULL: goto x86_l_23fc;
	case 9217ULL: goto x86_l_2401;
	case 9225ULL: goto x86_l_2409;
	case 9227ULL: goto x86_l_240b;
	case 9229ULL: goto x86_l_240d;
	case 9233ULL: goto x86_l_2411;
	case 9237ULL: goto x86_l_2415;
	case 9241ULL: goto x86_l_2419;
	case 9244ULL: goto x86_l_241c;
	case 9246ULL: goto x86_l_241e;
	case 9249ULL: goto x86_l_2421;
	case 9254ULL: goto x86_l_2426;
	case 9259ULL: goto x86_l_242b;
	case 9264ULL: goto x86_l_2430;
	case 9270ULL: goto x86_l_2436;
	case 9272ULL: goto x86_l_2438;
	case 9278ULL: goto x86_l_243e;
	case 9281ULL: goto x86_l_2441;
	case 9287ULL: goto x86_l_2447;
	case 9292ULL: goto x86_l_244c;
	case 9297ULL: goto x86_l_2451;
	case 9304ULL: goto x86_l_2458;
	case 9309ULL: goto x86_l_245d;
	case 9312ULL: goto x86_l_2460;
	case 9317ULL: goto x86_l_2465;
	case 9322ULL: goto x86_l_246a;
	case 9327ULL: goto x86_l_246f;
	case 9333ULL: goto x86_l_2475;
	case 9336ULL: goto x86_l_2478;
	case 9342ULL: goto x86_l_247e;
	case 9345ULL: goto x86_l_2481;
	case 9351ULL: goto x86_l_2487;
	case 9356ULL: goto x86_l_248c;
	case 9361ULL: goto x86_l_2491;
	case 9368ULL: goto x86_l_2498;
	case 9373ULL: goto x86_l_249d;
	case 9376ULL: goto x86_l_24a0;
	case 9381ULL: goto x86_l_24a5;
	case 9386ULL: goto x86_l_24aa;
	case 9391ULL: goto x86_l_24af;
	case 9394ULL: goto x86_l_24b2;
	case 9397ULL: goto x86_l_24b5;
	case 9399ULL: goto x86_l_24b7;
	case 9404ULL: goto x86_l_24bc;
	case 9407ULL: goto x86_l_24bf;
	case 9410ULL: goto x86_l_24c2;
	case 9412ULL: goto x86_l_24c4;
	case 9415ULL: goto x86_l_24c7;
	case 9420ULL: goto x86_l_24cc;
	case 9423ULL: goto x86_l_24cf;
	case 9429ULL: goto x86_l_24d5;
	case 9433ULL: goto x86_l_24d9;
	case 9437ULL: goto x86_l_24dd;
	case 9441ULL: goto x86_l_24e1;
	case 9445ULL: goto x86_l_24e5;
	case 9450ULL: goto x86_l_24ea;
	case 9457ULL: goto x86_l_24f1;
	case 9462ULL: goto x86_l_24f6;
	case 9465ULL: goto x86_l_24f9;
	case 9467ULL: goto x86_l_24fb;
	case 9470ULL: goto x86_l_24fe;
	case 9475ULL: goto x86_l_2503;
	case 9482ULL: goto x86_l_250a;
	case 9485ULL: goto x86_l_250d;
	case 9487ULL: goto x86_l_250f;
	case 9490ULL: goto x86_l_2512;
	case 9496ULL: goto x86_l_2518;
	case 9501ULL: goto x86_l_251d;
	case 9504ULL: goto x86_l_2520;
	case 9509ULL: goto x86_l_2525;
	case 9514ULL: goto x86_l_252a;
	case 9519ULL: goto x86_l_252f;
	case 9525ULL: goto x86_l_2535;
	case 9528ULL: goto x86_l_2538;
	case 9536ULL: goto x86_l_2540;
	case 9541ULL: goto x86_l_2545;
	case 9546ULL: goto x86_l_254a;
	case 9552ULL: goto x86_l_2550;
	case 9555ULL: goto x86_l_2553;
	case 9558ULL: goto x86_l_2556;
	case 9562ULL: goto x86_l_255a;
	case 9567ULL: goto x86_l_255f;
	case 9571ULL: goto x86_l_2563;
	case 9573ULL: goto x86_l_2565;
	case 9575ULL: goto x86_l_2567;
	case 9577ULL: goto x86_l_2569;
	case 9583ULL: goto x86_l_256f;
	case 9591ULL: goto x86_l_2577;
	case 9594ULL: goto x86_l_257a;
	case 9596ULL: goto x86_l_257c;
	case 9602ULL: goto x86_l_2582;
	case 9607ULL: goto x86_l_2587;
	case 9615ULL: goto x86_l_258f;
	case 9620ULL: goto x86_l_2594;
	case 9623ULL: goto x86_l_2597;
	case 9627ULL: goto x86_l_259b;
	case 9629ULL: goto x86_l_259d;
	case 9633ULL: goto x86_l_25a1;
	case 9636ULL: goto x86_l_25a4;
	case 9639ULL: goto x86_l_25a7;
	case 9642ULL: goto x86_l_25aa;
	case 9648ULL: goto x86_l_25b0;
	case 9653ULL: goto x86_l_25b5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1f9a:
	/* 0x1f9a: cmp    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1f9f:
	/* 0x1f9f: jae    1fb2 <generic_usdt_filter_arg+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1fb2;
	}
x86_l_1fa1:
	/* 0x1fa1: add    r13d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1fa5:
	/* 0x1fa5: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1fa8:
	/* 0x1fa8: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_1fac:
	/* 0x1fac: jne    1f18 <generic_usdt_filter_arg+0x1f18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7960ULL;
	}
x86_l_1fb2:
	/* 0x1fb2: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fb4:
	/* 0x1fb4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fb9:
	/* 0x1fb9: jmp    3216 <generic_usdt_filter_arg+0x3216> */
	return 12822ULL;
x86_l_1fbe:
	/* 0x1fbe: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1fc1:
	/* 0x1fc1: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_1fc6:
	/* 0x1fc6: mov    QWORD PTR [rsp+0x18],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fcb:
	/* 0x1fcb: ja     249d <generic_usdt_filter_arg+0x249d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_249d;
	}
x86_l_1fd1:
	/* 0x1fd1: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1fd5:
	/* 0x1fd5: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1fdb:
	/* 0x1fdb: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1fde:
	/* 0x1fde: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1fe1:
	/* 0x1fe1: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1fe4:
	/* 0x1fe4: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1fe6:
	/* 0x1fe6: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1fe8:
	/* 0x1fe8: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_1feb:
	/* 0x1feb: je     1ff3 <generic_usdt_filter_arg+0x1ff3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ff3;
	}
x86_l_1fed:
	/* 0x1fed: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1fef:
	/* 0x1fef: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1ff1:
	/* 0x1ff1: je     2009 <generic_usdt_filter_arg+0x2009> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2009;
	}
x86_l_1ff3:
	/* 0x1ff3: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1ff6:
	/* 0x1ff6: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1ff8:
	/* 0x1ff8: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1ffa:
	/* 0x1ffa: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_1ffc:
	/* 0x1ffc: add    esi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_1fff:
	/* 0x1fff: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2003:
	/* 0x2003: ja     24b2 <generic_usdt_filter_arg+0x24b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_24b2;
	}
x86_l_2009:
	/* 0x2009: movzx  eax,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_200d:
	/* 0x200d: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2013:
	/* 0x2013: shr    ecx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2016:
	/* 0x2016: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2018:
	/* 0x2018: jmp    24c2 <generic_usdt_filter_arg+0x24c2> */
	goto x86_l_24c2;
x86_l_201d:
	/* 0x201d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2021:
	/* 0x2021: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2024:
	/* 0x2024: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2026:
	/* 0x2026: jb     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_202c:
	/* 0x202c: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2031:
	/* 0x2031: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_2034:
	/* 0x2034: jb     32b7 <generic_usdt_filter_arg+0x32b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12983ULL;
	}
x86_l_203a:
	/* 0x203a: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_203f:
	/* 0x203f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2042:
	/* 0x2042: jle    2386 <generic_usdt_filter_arg+0x2386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2386;
	}
x86_l_2048:
	/* 0x2048: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_204b:
	/* 0x204b: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_204e:
	/* 0x204e: jae    2886 <generic_usdt_filter_arg+0x2886> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10374ULL;
	}
x86_l_2054:
	/* 0x2054: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2058:
	/* 0x2058: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_205b:
	/* 0x205b: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_205d:
	/* 0x205d: jne    298d <generic_usdt_filter_arg+0x298d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10637ULL;
	}
x86_l_2063:
	/* 0x2063: jmp    31a4 <generic_usdt_filter_arg+0x31a4> */
	return 12708ULL;
x86_l_2068:
	/* 0x2068: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_206c:
	/* 0x206c: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_206f:
	/* 0x206f: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2071:
	/* 0x2071: jb     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_2077:
	/* 0x2077: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_207c:
	/* 0x207c: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_207f:
	/* 0x207f: jb     32b7 <generic_usdt_filter_arg+0x32b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12983ULL;
	}
x86_l_2085:
	/* 0x2085: mov    edx,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_208a:
	/* 0x208a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_208d:
	/* 0x208d: jle    23ac <generic_usdt_filter_arg+0x23ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_23ac;
	}
x86_l_2093:
	/* 0x2093: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2096:
	/* 0x2096: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2099:
	/* 0x2099: jae    28a3 <generic_usdt_filter_arg+0x28a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10403ULL;
	}
x86_l_209f:
	/* 0x209f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20a3:
	/* 0x20a3: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_20a6:
	/* 0x20a6: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_20a8:
	/* 0x20a8: jne    29d3 <generic_usdt_filter_arg+0x29d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10707ULL;
	}
x86_l_20ae:
	/* 0x20ae: jmp    31a4 <generic_usdt_filter_arg+0x31a4> */
	return 12708ULL;
x86_l_20b3:
	/* 0x20b3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20b6:
	/* 0x20b6: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_20b9:
	/* 0x20b9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20be:
	/* 0x20be: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20c3:
	/* 0x20c3: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20c8:
	/* 0x20c8: movzx  ebx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_20cb:
	/* 0x20cb: jmp    2b6 <generic_usdt_filter_arg+0x2b6> */
	return 694ULL;
x86_l_20d0:
	/* 0x20d0: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d4:
	/* 0x20d4: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d6:
	/* 0x20d6: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_20d8:
	/* 0x20d8: ja     20e2 <generic_usdt_filter_arg+0x20e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_20e2;
	}
x86_l_20da:
	/* 0x20da: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_20dc:
	/* 0x20dc: jbe    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 716ULL;
	}
x86_l_20e2:
	/* 0x20e2: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20e7:
	/* 0x20e7: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_20ea:
	/* 0x20ea: jb     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 269ULL;
	}
x86_l_20f0:
	/* 0x20f0: mov    edi,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20f5:
	/* 0x20f5: mov    esi,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_20fa:
	/* 0x20fa: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_20fd:
	/* 0x20fd: ja     25e5 <generic_usdt_filter_arg+0x25e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9701ULL;
	}
x86_l_2103:
	/* 0x2103: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2109:
	/* 0x2109: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_210d:
	/* 0x210d: jae    25e5 <generic_usdt_filter_arg+0x25e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9701ULL;
	}
x86_l_2113:
	/* 0x2113: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_2115:
	/* 0x2115: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_211a:
	/* 0x211a: jg     25f6 <generic_usdt_filter_arg+0x25f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 9718ULL;
	}
x86_l_2120:
	/* 0x2120: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_2122:
	/* 0x2122: jle    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 716ULL;
	}
x86_l_2128:
	/* 0x2128: jmp    25f6 <generic_usdt_filter_arg+0x25f6> */
	return 9718ULL;
x86_l_212d:
	/* 0x212d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2131:
	/* 0x2131: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2133:
	/* 0x2133: cmp    esi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2135:
	/* 0x2135: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_2139:
	/* 0x2139: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_213b:
	/* 0x213b: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_213e:
	/* 0x213e: and    al,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_8, X86_ALU_AND);
x86_l_2141:
	/* 0x2141: mov    esi,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2146:
	/* 0x2146: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_2149:
	/* 0x2149: jb     2dc2 <generic_usdt_filter_arg+0x2dc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11714ULL;
	}
x86_l_214f:
	/* 0x214f: mov    r8d,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2154:
	/* 0x2154: mov    edi,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2159:
	/* 0x2159: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_215c:
	/* 0x215c: ja     2594 <generic_usdt_filter_arg+0x2594> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2594;
	}
x86_l_2162:
	/* 0x2162: mov    r10d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 5122ULL);
x86_l_2168:
	/* 0x2168: bt     r10d,ecx */
	X86_SIM_L_EXEC_BT(X86_R10, X86_RCX, X86_WIDTH_32);
x86_l_216c:
	/* 0x216c: jae    2594 <generic_usdt_filter_arg+0x2594> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2594;
	}
x86_l_2172:
	/* 0x2172: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_2175:
	/* 0x2175: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2179:
	/* 0x2179: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_217b:
	/* 0x217b: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_217f:
	/* 0x217f: jmp    25a1 <generic_usdt_filter_arg+0x25a1> */
	goto x86_l_25a1;
x86_l_2184:
	/* 0x2184: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_2187:
	/* 0x2187: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_218b:
	/* 0x218b: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_218e:
	/* 0x218e: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_2192:
	/* 0x2192: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2195:
	/* 0x2195: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_2198:
	/* 0x2198: cmp    esi,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 41ULL);
x86_l_219b:
	/* 0x219b: jb     2dbd <generic_usdt_filter_arg+0x2dbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11709ULL;
	}
x86_l_21a1:
	/* 0x21a1: mov    r8,QWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21a6:
	/* 0x21a6: mov    rdi,QWORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21ab:
	/* 0x21ab: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_21ae:
	/* 0x21ae: je     21b9 <generic_usdt_filter_arg+0x21b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21b9;
	}
x86_l_21b0:
	/* 0x21b0: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_21b3:
	/* 0x21b3: jne    2687 <generic_usdt_filter_arg+0x2687> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9863ULL;
	}
x86_l_21b9:
	/* 0x21b9: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_21bc:
	/* 0x21bc: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_21c0:
	/* 0x21c0: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_21c3:
	/* 0x21c3: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_21c7:
	/* 0x21c7: jmp    2695 <generic_usdt_filter_arg+0x2695> */
	return 9877ULL;
x86_l_21cc:
	/* 0x21cc: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_21cf:
	/* 0x21cf: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21d4:
	/* 0x21d4: ja     21df <generic_usdt_filter_arg+0x21df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_21df;
	}
x86_l_21d6:
	/* 0x21d6: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_21d9:
	/* 0x21d9: jbe    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 716ULL;
	}
x86_l_21df:
	/* 0x21df: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_21e2:
	/* 0x21e2: jb     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 269ULL;
	}
x86_l_21e8:
	/* 0x21e8: mov    rdi,QWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21ed:
	/* 0x21ed: mov    rsi,QWORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21f2:
	/* 0x21f2: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_21f5:
	/* 0x21f5: je     2200 <generic_usdt_filter_arg+0x2200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2200;
	}
x86_l_21f7:
	/* 0x21f7: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_21fa:
	/* 0x21fa: jne    279b <generic_usdt_filter_arg+0x279b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10139ULL;
	}
x86_l_2200:
	/* 0x2200: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2203:
	/* 0x2203: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2208:
	/* 0x2208: jg     27ae <generic_usdt_filter_arg+0x27ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10158ULL;
	}
x86_l_220e:
	/* 0x220e: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_2211:
	/* 0x2211: jle    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 716ULL;
	}
x86_l_2217:
	/* 0x2217: jmp    27ae <generic_usdt_filter_arg+0x27ae> */
	return 10158ULL;
x86_l_221c:
	/* 0x221c: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_221e:
	/* 0x221e: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2221:
	/* 0x2221: jne    222c <generic_usdt_filter_arg+0x222c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_222c;
	}
x86_l_2223:
	/* 0x2223: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2226:
	/* 0x2226: je     222c <generic_usdt_filter_arg+0x222c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_222c;
	}
x86_l_2228:
	/* 0x2228: movzx  ebx,BYTE PTR [rdx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_222c:
	/* 0x222c: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_222f:
	/* 0x222f: je     223a <generic_usdt_filter_arg+0x223a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_223a;
	}
x86_l_2231:
	/* 0x2231: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2234:
	/* 0x2234: jne    26ca <generic_usdt_filter_arg+0x26ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9930ULL;
	}
x86_l_223a:
	/* 0x223a: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_223d:
	/* 0x223d: movzx  eax,BYTE PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2243:
	/* 0x2243: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2247:
	/* 0x2247: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_224c:
	/* 0x224c: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2253:
	/* 0x2253: lea    rsi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2258:
	/* 0x2258: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_225a:
	/* 0x225a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_225d:
	/* 0x225d: je     227b <generic_usdt_filter_arg+0x227b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_227b;
	}
x86_l_225f:
	/* 0x225f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2262:
	/* 0x2262: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_2264:
	/* 0x2264: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_226c:
	/* 0x226c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2271:
	/* 0x2271: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2276:
	/* 0x2276: jmp    1c34 <generic_usdt_filter_arg+0x1c34> */
	return 7220ULL;
x86_l_227b:
	/* 0x227b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_227d:
	/* 0x227d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2282:
	/* 0x2282: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2287:
	/* 0x2287: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_228a:
	/* 0x228a: jmp    2b6 <generic_usdt_filter_arg+0x2b6> */
	return 694ULL;
x86_l_228f:
	/* 0x228f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2293:
	/* 0x2293: cmp    DWORD PTR [rsi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2295:
	/* 0x2295: ja     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_229b:
	/* 0x229b: jmp    22a9 <generic_usdt_filter_arg+0x22a9> */
	goto x86_l_22a9;
x86_l_229d:
	/* 0x229d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22a1:
	/* 0x22a1: cmp    DWORD PTR [rsi],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22a3:
	/* 0x22a3: jb     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_22a9:
	/* 0x22a9: mov    edx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22ae:
	/* 0x22ae: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_22b1:
	/* 0x22b1: jb     32b7 <generic_usdt_filter_arg+0x32b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12983ULL;
	}
x86_l_22b7:
	/* 0x22b7: mov    esi,DWORD PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_22bc:
	/* 0x22bc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_22bf:
	/* 0x22bf: jle    22df <generic_usdt_filter_arg+0x22df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_22df;
	}
x86_l_22c1:
	/* 0x22c1: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_22c4:
	/* 0x22c4: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_22c7:
	/* 0x22c7: jae    2318 <generic_usdt_filter_arg+0x2318> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2318;
	}
x86_l_22c9:
	/* 0x22c9: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22cd:
	/* 0x22cd: cmp    DWORD PTR [rdi],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22cf:
	/* 0x22cf: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22d4:
	/* 0x22d4: jne    2ad2 <generic_usdt_filter_arg+0x2ad2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10962ULL;
	}
x86_l_22da:
	/* 0x22da: jmp    31a4 <generic_usdt_filter_arg+0x31a4> */
	return 12708ULL;
x86_l_22df:
	/* 0x22df: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22e2:
	/* 0x22e2: je     2338 <generic_usdt_filter_arg+0x2338> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2338;
	}
x86_l_22e4:
	/* 0x22e4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_22e7:
	/* 0x22e7: jne    2ad2 <generic_usdt_filter_arg+0x2ad2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10962ULL;
	}
x86_l_22ed:
	/* 0x22ed: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_22f0:
	/* 0x22f0: ja     2ac5 <generic_usdt_filter_arg+0x2ac5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10949ULL;
	}
x86_l_22f6:
	/* 0x22f6: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_22fc:
	/* 0x22fc: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2300:
	/* 0x2300: jae    2ac5 <generic_usdt_filter_arg+0x2ac5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10949ULL;
	}
x86_l_2306:
	/* 0x2306: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_230a:
	/* 0x230a: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_230d:
	/* 0x230d: jl     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 716ULL;
	}
x86_l_2313:
	/* 0x2313: jmp    2ad2 <generic_usdt_filter_arg+0x2ad2> */
	return 10962ULL;
x86_l_2318:
	/* 0x2318: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_231b:
	/* 0x231b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2320:
	/* 0x2320: jne    2ad2 <generic_usdt_filter_arg+0x2ad2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10962ULL;
	}
x86_l_2326:
	/* 0x2326: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_232a:
	/* 0x232a: test   DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_232d:
	/* 0x232d: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_2333:
	/* 0x2333: jmp    2ad2 <generic_usdt_filter_arg+0x2ad2> */
	return 10962ULL;
x86_l_2338:
	/* 0x2338: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_233b:
	/* 0x233b: ja     2ab6 <generic_usdt_filter_arg+0x2ab6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10934ULL;
	}
x86_l_2341:
	/* 0x2341: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2347:
	/* 0x2347: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_234b:
	/* 0x234b: jae    2ab6 <generic_usdt_filter_arg+0x2ab6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10934ULL;
	}
x86_l_2351:
	/* 0x2351: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2355:
	/* 0x2355: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2358:
	/* 0x2358: jg     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 716ULL;
	}
x86_l_235e:
	/* 0x235e: jmp    2ad2 <generic_usdt_filter_arg+0x2ad2> */
	return 10962ULL;
x86_l_2363:
	/* 0x2363: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2365:
	/* 0x2365: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_236a:
	/* 0x236a: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_236d:
	/* 0x236d: mov    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2372:
	/* 0x2372: jmp    2641 <generic_usdt_filter_arg+0x2641> */
	return 9793ULL;
x86_l_2377:
	/* 0x2377: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2379:
	/* 0x2379: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_237c:
	/* 0x237c: mov    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2381:
	/* 0x2381: jmp    2664 <generic_usdt_filter_arg+0x2664> */
	return 9828ULL;
x86_l_2386:
	/* 0x2386: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2389:
	/* 0x2389: je     297e <generic_usdt_filter_arg+0x297e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10622ULL;
	}
x86_l_238f:
	/* 0x238f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2392:
	/* 0x2392: jne    298d <generic_usdt_filter_arg+0x298d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10637ULL;
	}
x86_l_2398:
	/* 0x2398: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_239c:
	/* 0x239c: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_239f:
	/* 0x239f: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_23a1:
	/* 0x23a1: ja     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_23a7:
	/* 0x23a7: jmp    298d <generic_usdt_filter_arg+0x298d> */
	return 10637ULL;
x86_l_23ac:
	/* 0x23ac: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23af:
	/* 0x23af: je     29c4 <generic_usdt_filter_arg+0x29c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10692ULL;
	}
x86_l_23b5:
	/* 0x23b5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_23b8:
	/* 0x23b8: jne    29d3 <generic_usdt_filter_arg+0x29d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10707ULL;
	}
x86_l_23be:
	/* 0x23be: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23c2:
	/* 0x23c2: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_23c5:
	/* 0x23c5: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_23c7:
	/* 0x23c7: ja     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_23cd:
	/* 0x23cd: jmp    29d3 <generic_usdt_filter_arg+0x29d3> */
	return 10707ULL;
x86_l_23d2:
	/* 0x23d2: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_23d5:
	/* 0x23d5: mov    WORD PTR [rcx],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23d8:
	/* 0x23d8: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_23dc:
	/* 0x23dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23e1:
	/* 0x23e1: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_23e3:
	/* 0x23e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23e5:
	/* 0x23e5: cmp    ebx,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RBP, X86_WIDTH_32);
x86_l_23e7:
	/* 0x23e7: jbe    240d <generic_usdt_filter_arg+0x240d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_240d;
	}
x86_l_23e9:
	/* 0x23e9: lea    rdi,[rbp*1+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 2ULL);
x86_l_23f1:
	/* 0x23f1: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23f4:
	/* 0x23f4: sub    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_23f6:
	/* 0x23f6: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23fc:
	/* 0x23fc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2401:
	/* 0x2401: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2409:
	/* 0x2409: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_240b:
	/* 0x240b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_240d:
	/* 0x240d: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2411:
	/* 0x2411: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2415:
	/* 0x2415: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2419:
	/* 0x2419: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_241c:
	/* 0x241c: jg     245d <generic_usdt_filter_arg+0x245d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_245d;
	}
x86_l_241e:
	/* 0x241e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2421:
	/* 0x2421: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2426:
	/* 0x2426: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_242b:
	/* 0x242b: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2430:
	/* 0x2430: jg     290e <generic_usdt_filter_arg+0x290e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10510ULL;
	}
x86_l_2436:
	/* 0x2436: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2438:
	/* 0x2438: je     2d2c <generic_usdt_filter_arg+0x2d2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11564ULL;
	}
x86_l_243e:
	/* 0x243e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2441:
	/* 0x2441: jne    94c <generic_usdt_filter_arg+0x94c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2380ULL;
	}
x86_l_2447:
	/* 0x2447: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_244c:
	/* 0x244c: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2451:
	/* 0x2451: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2458:
	/* 0x2458: jmp    2d76 <generic_usdt_filter_arg+0x2d76> */
	return 11638ULL;
x86_l_245d:
	/* 0x245d: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2460:
	/* 0x2460: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2465:
	/* 0x2465: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_246a:
	/* 0x246a: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_246f:
	/* 0x246f: jg     2936 <generic_usdt_filter_arg+0x2936> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10550ULL;
	}
x86_l_2475:
	/* 0x2475: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2478:
	/* 0x2478: je     2d3f <generic_usdt_filter_arg+0x2d3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11583ULL;
	}
x86_l_247e:
	/* 0x247e: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2481:
	/* 0x2481: jne    94c <generic_usdt_filter_arg+0x94c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2380ULL;
	}
x86_l_2487:
	/* 0x2487: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_248c:
	/* 0x248c: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2491:
	/* 0x2491: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_2498:
	/* 0x2498: jmp    2d76 <generic_usdt_filter_arg+0x2d76> */
	return 11638ULL;
x86_l_249d:
	/* 0x249d: movzx  eax,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_24a0:
	/* 0x24a0: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_24a5:
	/* 0x24a5: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_24aa:
	/* 0x24aa: mov    eax,0x1fe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 510ULL);
x86_l_24af:
	/* 0x24af: cmovae esi,eax */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_24b2:
	/* 0x24b2: movzx  eax,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_24b5:
	/* 0x24b5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24b7:
	/* 0x24b7: cmp    eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_24bc:
	/* 0x24bc: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_24bf:
	/* 0x24bf: xor    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 7ULL);
x86_l_24c2:
	/* 0x24c2: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_24c4:
	/* 0x24c4: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_24c7:
	/* 0x24c7: mov    eax,DWORD PTR [r12+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_24cc:
	/* 0x24cc: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_24cf:
	/* 0x24cf: je     3205 <generic_usdt_filter_arg+0x3205> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12805ULL;
	}
x86_l_24d5:
	/* 0x24d5: mov    DWORD PTR [rsp+0x7c],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_24d9:
	/* 0x24d9: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_24dd:
	/* 0x24dd: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24e1:
	/* 0x24e1: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24e5:
	/* 0x24e5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24ea:
	/* 0x24ea: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_24f1:
	/* 0x24f1: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24f6:
	/* 0x24f6: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_24f9:
	/* 0x24f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24fb:
	/* 0x24fb: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_24fe:
	/* 0x24fe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2503:
	/* 0x2503: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_250a:
	/* 0x250a: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_250d:
	/* 0x250d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_250f:
	/* 0x250f: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2512:
	/* 0x2512: je     3205 <generic_usdt_filter_arg+0x3205> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12805ULL;
	}
x86_l_2518:
	/* 0x2518: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_251d:
	/* 0x251d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2520:
	/* 0x2520: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2525:
	/* 0x2525: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_252a:
	/* 0x252a: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_252f:
	/* 0x252f: je     3216 <generic_usdt_filter_arg+0x3216> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12822ULL;
	}
x86_l_2535:
	/* 0x2535: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2538:
	/* 0x2538: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2540:
	/* 0x2540: movzx  ebx,WORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 124ULL);
x86_l_2545:
	/* 0x2545: cmp    DWORD PTR [rsp+0x20],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953477ULL);
x86_l_254a:
	/* 0x254a: jg     2c7b <generic_usdt_filter_arg+0x2c7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 11387ULL;
	}
x86_l_2550:
	/* 0x2550: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_2553:
	/* 0x2553: mov    BYTE PTR [rcx],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2556:
	/* 0x2556: lea    rdi,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_255a:
	/* 0x255a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_255f:
	/* 0x255f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2563:
	/* 0x2563: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2565:
	/* 0x2565: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2567:
	/* 0x2567: cmp    ebx,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RBP, X86_WIDTH_32);
x86_l_2569:
	/* 0x2569: jbe    2cba <generic_usdt_filter_arg+0x2cba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11450ULL;
	}
x86_l_256f:
	/* 0x256f: lea    rdi,[rbp*1+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 1ULL);
x86_l_2577:
	/* 0x2577: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_257a:
	/* 0x257a: sub    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_257c:
	/* 0x257c: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2582:
	/* 0x2582: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2587:
	/* 0x2587: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_258f:
	/* 0x258f: jmp    2cb6 <generic_usdt_filter_arg+0x2cb6> */
	return 11446ULL;
x86_l_2594:
	/* 0x2594: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_2597:
	/* 0x2597: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_259b:
	/* 0x259b: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_259d:
	/* 0x259d: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_25a1:
	/* 0x25a1: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_25a4:
	/* 0x25a4: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_25a7:
	/* 0x25a7: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_25aa:
	/* 0x25aa: jb     2dbd <generic_usdt_filter_arg+0x2dbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11709ULL;
	}
x86_l_25b0:
	/* 0x25b0: mov    r8d,DWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25b5:
	/* 0x25b5: mov    edi,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
	return 9658ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_usdt_filter_arg_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9658ULL: goto x86_l_25ba;
	case 9661ULL: goto x86_l_25bd;
	case 9667ULL: goto x86_l_25c3;
	case 9673ULL: goto x86_l_25c9;
	case 9677ULL: goto x86_l_25cd;
	case 9683ULL: goto x86_l_25d3;
	case 9686ULL: goto x86_l_25d6;
	case 9690ULL: goto x86_l_25da;
	case 9692ULL: goto x86_l_25dc;
	case 9696ULL: goto x86_l_25e0;
	case 9701ULL: goto x86_l_25e5;
	case 9703ULL: goto x86_l_25e7;
	case 9708ULL: goto x86_l_25ec;
	case 9710ULL: goto x86_l_25ee;
	case 9712ULL: goto x86_l_25f0;
	case 9718ULL: goto x86_l_25f6;
	case 9721ULL: goto x86_l_25f9;
	case 9727ULL: goto x86_l_25ff;
	case 9732ULL: goto x86_l_2604;
	case 9737ULL: goto x86_l_2609;
	case 9740ULL: goto x86_l_260c;
	case 9746ULL: goto x86_l_2612;
	case 9752ULL: goto x86_l_2618;
	case 9756ULL: goto x86_l_261c;
	case 9762ULL: goto x86_l_2622;
	case 9764ULL: goto x86_l_2624;
	case 9769ULL: goto x86_l_2629;
	case 9775ULL: goto x86_l_262f;
	case 9777ULL: goto x86_l_2631;
	case 9783ULL: goto x86_l_2637;
	case 9788ULL: goto x86_l_263c;
	case 9793ULL: goto x86_l_2641;
	case 9798ULL: goto x86_l_2646;
	case 9803ULL: goto x86_l_264b;
	case 9808ULL: goto x86_l_2650;
	case 9812ULL: goto x86_l_2654;
	case 9818ULL: goto x86_l_265a;
	case 9823ULL: goto x86_l_265f;
	case 9828ULL: goto x86_l_2664;
	case 9833ULL: goto x86_l_2669;
	case 9838ULL: goto x86_l_266e;
	case 9843ULL: goto x86_l_2673;
	case 9848ULL: goto x86_l_2678;
	case 9852ULL: goto x86_l_267c;
	case 9858ULL: goto x86_l_2682;
	case 9863ULL: goto x86_l_2687;
	case 9866ULL: goto x86_l_268a;
	case 9870ULL: goto x86_l_268e;
	case 9873ULL: goto x86_l_2691;
	case 9877ULL: goto x86_l_2695;
	case 9880ULL: goto x86_l_2698;
	case 9883ULL: goto x86_l_269b;
	case 9886ULL: goto x86_l_269e;
	case 9892ULL: goto x86_l_26a4;
	case 9897ULL: goto x86_l_26a9;
	case 9902ULL: goto x86_l_26ae;
	case 9905ULL: goto x86_l_26b1;
	case 9907ULL: goto x86_l_26b3;
	case 9910ULL: goto x86_l_26b6;
	case 9916ULL: goto x86_l_26bc;
	case 9919ULL: goto x86_l_26bf;
	case 9922ULL: goto x86_l_26c2;
	case 9925ULL: goto x86_l_26c5;
	case 9930ULL: goto x86_l_26ca;
	case 9932ULL: goto x86_l_26cc;
	case 9937ULL: goto x86_l_26d1;
	case 9942ULL: goto x86_l_26d6;
	case 9945ULL: goto x86_l_26d9;
	case 9949ULL: goto x86_l_26dd;
	case 9954ULL: goto x86_l_26e2;
	case 9958ULL: goto x86_l_26e6;
	case 9960ULL: goto x86_l_26e8;
	case 9962ULL: goto x86_l_26ea;
	case 9970ULL: goto x86_l_26f2;
	case 9972ULL: goto x86_l_26f4;
	case 9974ULL: goto x86_l_26f6;
	case 9979ULL: goto x86_l_26fb;
	case 9983ULL: goto x86_l_26ff;
	case 9987ULL: goto x86_l_2703;
	case 9989ULL: goto x86_l_2705;
	case 9995ULL: goto x86_l_270b;
	case 10000ULL: goto x86_l_2710;
	case 10003ULL: goto x86_l_2713;
	case 10005ULL: goto x86_l_2715;
	case 10009ULL: goto x86_l_2719;
	case 10013ULL: goto x86_l_271d;
	case 10017ULL: goto x86_l_2721;
	case 10020ULL: goto x86_l_2724;
	case 10022ULL: goto x86_l_2726;
	case 10025ULL: goto x86_l_2729;
	case 10030ULL: goto x86_l_272e;
	case 10035ULL: goto x86_l_2733;
	case 10041ULL: goto x86_l_2739;
	case 10043ULL: goto x86_l_273b;
	case 10049ULL: goto x86_l_2741;
	case 10052ULL: goto x86_l_2744;
	case 10058ULL: goto x86_l_274a;
	case 10063ULL: goto x86_l_274f;
	case 10068ULL: goto x86_l_2754;
	case 10075ULL: goto x86_l_275b;
	case 10080ULL: goto x86_l_2760;
	case 10083ULL: goto x86_l_2763;
	case 10088ULL: goto x86_l_2768;
	case 10093ULL: goto x86_l_276d;
	case 10099ULL: goto x86_l_2773;
	case 10102ULL: goto x86_l_2776;
	case 10108ULL: goto x86_l_277c;
	case 10111ULL: goto x86_l_277f;
	case 10117ULL: goto x86_l_2785;
	case 10122ULL: goto x86_l_278a;
	case 10127ULL: goto x86_l_278f;
	case 10134ULL: goto x86_l_2796;
	case 10139ULL: goto x86_l_279b;
	case 10142ULL: goto x86_l_279e;
	case 10147ULL: goto x86_l_27a3;
	case 10149ULL: goto x86_l_27a5;
	case 10152ULL: goto x86_l_27a8;
	case 10158ULL: goto x86_l_27ae;
	case 10161ULL: goto x86_l_27b1;
	case 10167ULL: goto x86_l_27b7;
	case 10172ULL: goto x86_l_27bc;
	case 10177ULL: goto x86_l_27c1;
	case 10180ULL: goto x86_l_27c4;
	case 10182ULL: goto x86_l_27c6;
	case 10185ULL: goto x86_l_27c9;
	case 10191ULL: goto x86_l_27cf;
	case 10194ULL: goto x86_l_27d2;
	case 10200ULL: goto x86_l_27d8;
	case 10203ULL: goto x86_l_27db;
	case 10209ULL: goto x86_l_27e1;
	case 10214ULL: goto x86_l_27e6;
	case 10218ULL: goto x86_l_27ea;
	case 10221ULL: goto x86_l_27ed;
	case 10227ULL: goto x86_l_27f3;
	case 10229ULL: goto x86_l_27f5;
	case 10233ULL: goto x86_l_27f9;
	case 10236ULL: goto x86_l_27fc;
	case 10242ULL: goto x86_l_2802;
	case 10245ULL: goto x86_l_2805;
	case 10251ULL: goto x86_l_280b;
	case 10256ULL: goto x86_l_2810;
	case 10259ULL: goto x86_l_2813;
	case 10261ULL: goto x86_l_2815;
	case 10264ULL: goto x86_l_2818;
	case 10267ULL: goto x86_l_281b;
	case 10269ULL: goto x86_l_281d;
	case 10273ULL: goto x86_l_2821;
	case 10276ULL: goto x86_l_2824;
	case 10281ULL: goto x86_l_2829;
	case 10287ULL: goto x86_l_282f;
	case 10292ULL: goto x86_l_2834;
	case 10295ULL: goto x86_l_2837;
	case 10301ULL: goto x86_l_283d;
	case 10304ULL: goto x86_l_2840;
	case 10310ULL: goto x86_l_2846;
	case 10313ULL: goto x86_l_2849;
	case 10315ULL: goto x86_l_284b;
	case 10318ULL: goto x86_l_284e;
	case 10324ULL: goto x86_l_2854;
	case 10328ULL: goto x86_l_2858;
	case 10331ULL: goto x86_l_285b;
	case 10337ULL: goto x86_l_2861;
	case 10342ULL: goto x86_l_2866;
	case 10345ULL: goto x86_l_2869;
	case 10350ULL: goto x86_l_286e;
	case 10356ULL: goto x86_l_2874;
	case 10360ULL: goto x86_l_2878;
	case 10363ULL: goto x86_l_287b;
	case 10369ULL: goto x86_l_2881;
	case 10374ULL: goto x86_l_2886;
	case 10377ULL: goto x86_l_2889;
	case 10383ULL: goto x86_l_288f;
	case 10387ULL: goto x86_l_2893;
	case 10390ULL: goto x86_l_2896;
	case 10392ULL: goto x86_l_2898;
	case 10398ULL: goto x86_l_289e;
	case 10403ULL: goto x86_l_28a3;
	case 10406ULL: goto x86_l_28a6;
	case 10412ULL: goto x86_l_28ac;
	case 10416ULL: goto x86_l_28b0;
	case 10419ULL: goto x86_l_28b3;
	case 10421ULL: goto x86_l_28b5;
	case 10427ULL: goto x86_l_28bb;
	case 10432ULL: goto x86_l_28c0;
	case 10437ULL: goto x86_l_28c5;
	case 10442ULL: goto x86_l_28ca;
	case 10445ULL: goto x86_l_28cd;
	case 10448ULL: goto x86_l_28d0;
	case 10453ULL: goto x86_l_28d5;
	case 10456ULL: goto x86_l_28d8;
	case 10458ULL: goto x86_l_28da;
	case 10461ULL: goto x86_l_28dd;
	case 10467ULL: goto x86_l_28e3;
	case 10471ULL: goto x86_l_28e7;
	case 10474ULL: goto x86_l_28ea;
	case 10480ULL: goto x86_l_28f0;
	case 10485ULL: goto x86_l_28f5;
	case 10487ULL: goto x86_l_28f7;
	case 10492ULL: goto x86_l_28fc;
	case 10495ULL: goto x86_l_28ff;
	case 10500ULL: goto x86_l_2904;
	case 10505ULL: goto x86_l_2909;
	case 10510ULL: goto x86_l_290e;
	case 10513ULL: goto x86_l_2911;
	case 10519ULL: goto x86_l_2917;
	case 10522ULL: goto x86_l_291a;
	case 10528ULL: goto x86_l_2920;
	case 10533ULL: goto x86_l_2925;
	case 10538ULL: goto x86_l_292a;
	case 10545ULL: goto x86_l_2931;
	case 10550ULL: goto x86_l_2936;
	case 10553ULL: goto x86_l_2939;
	case 10559ULL: goto x86_l_293f;
	case 10562ULL: goto x86_l_2942;
	case 10568ULL: goto x86_l_2948;
	case 10573ULL: goto x86_l_294d;
	case 10578ULL: goto x86_l_2952;
	case 10585ULL: goto x86_l_2959;
	case 10590ULL: goto x86_l_295e;
	case 10592ULL: goto x86_l_2960;
	case 10594ULL: goto x86_l_2962;
	case 10599ULL: goto x86_l_2967;
	case 10604ULL: goto x86_l_296c;
	case 10609ULL: goto x86_l_2971;
	case 10612ULL: goto x86_l_2974;
	case 10617ULL: goto x86_l_2979;
	case 10622ULL: goto x86_l_297e;
	case 10626ULL: goto x86_l_2982;
	case 10629ULL: goto x86_l_2985;
	case 10631ULL: goto x86_l_2987;
	case 10637ULL: goto x86_l_298d;
	case 10640ULL: goto x86_l_2990;
	case 10646ULL: goto x86_l_2996;
	case 10651ULL: goto x86_l_299b;
	case 10654ULL: goto x86_l_299e;
	case 10660ULL: goto x86_l_29a4;
	case 10663ULL: goto x86_l_29a7;
	case 10666ULL: goto x86_l_29aa;
	case 10672ULL: goto x86_l_29b0;
	case 10676ULL: goto x86_l_29b4;
	case 10679ULL: goto x86_l_29b7;
	case 10681ULL: goto x86_l_29b9;
	case 10687ULL: goto x86_l_29bf;
	case 10692ULL: goto x86_l_29c4;
	case 10696ULL: goto x86_l_29c8;
	case 10699ULL: goto x86_l_29cb;
	case 10701ULL: goto x86_l_29cd;
	case 10707ULL: goto x86_l_29d3;
	case 10710ULL: goto x86_l_29d6;
	case 10716ULL: goto x86_l_29dc;
	case 10721ULL: goto x86_l_29e1;
	case 10724ULL: goto x86_l_29e4;
	case 10730ULL: goto x86_l_29ea;
	case 10733ULL: goto x86_l_29ed;
	case 10736ULL: goto x86_l_29f0;
	case 10742ULL: goto x86_l_29f6;
	case 10746ULL: goto x86_l_29fa;
	case 10749ULL: goto x86_l_29fd;
	case 10751ULL: goto x86_l_29ff;
	case 10757ULL: goto x86_l_2a05;
	case 10762ULL: goto x86_l_2a0a;
	case 10764ULL: goto x86_l_2a0c;
	case 10769ULL: goto x86_l_2a11;
	case 10774ULL: goto x86_l_2a16;
	case 10777ULL: goto x86_l_2a19;
	case 10781ULL: goto x86_l_2a1d;
	case 10783ULL: goto x86_l_2a1f;
	case 10787ULL: goto x86_l_2a23;
	case 10790ULL: goto x86_l_2a26;
	case 10793ULL: goto x86_l_2a29;
	case 10796ULL: goto x86_l_2a2c;
	case 10802ULL: goto x86_l_2a32;
	case 10807ULL: goto x86_l_2a37;
	case 10812ULL: goto x86_l_2a3c;
	case 10815ULL: goto x86_l_2a3f;
	case 10821ULL: goto x86_l_2a45;
	case 10827ULL: goto x86_l_2a4b;
	case 10831ULL: goto x86_l_2a4f;
	case 10837ULL: goto x86_l_2a55;
	case 10839ULL: goto x86_l_2a57;
	case 10842ULL: goto x86_l_2a5a;
	case 10844ULL: goto x86_l_2a5c;
	case 10847ULL: goto x86_l_2a5f;
	case 10852ULL: goto x86_l_2a64;
	case 10854ULL: goto x86_l_2a66;
	case 10859ULL: goto x86_l_2a6b;
	case 10861ULL: goto x86_l_2a6d;
	case 10863ULL: goto x86_l_2a6f;
	case 10869ULL: goto x86_l_2a75;
	case 10872ULL: goto x86_l_2a78;
	case 10878ULL: goto x86_l_2a7e;
	case 10883ULL: goto x86_l_2a83;
	case 10888ULL: goto x86_l_2a88;
	case 10891ULL: goto x86_l_2a8b;
	case 10897ULL: goto x86_l_2a91;
	case 10903ULL: goto x86_l_2a97;
	case 10907ULL: goto x86_l_2a9b;
	case 10913ULL: goto x86_l_2aa1;
	case 10915ULL: goto x86_l_2aa3;
	case 10921ULL: goto x86_l_2aa9;
	case 10923ULL: goto x86_l_2aab;
	case 10929ULL: goto x86_l_2ab1;
	case 10934ULL: goto x86_l_2ab6;
	case 10938ULL: goto x86_l_2aba;
	case 10941ULL: goto x86_l_2abd;
	case 10947ULL: goto x86_l_2ac3;
	case 10949ULL: goto x86_l_2ac5;
	case 10953ULL: goto x86_l_2ac9;
	case 10956ULL: goto x86_l_2acc;
	case 10962ULL: goto x86_l_2ad2;
	case 10965ULL: goto x86_l_2ad5;
	case 10971ULL: goto x86_l_2adb;
	case 10976ULL: goto x86_l_2ae0;
	case 10979ULL: goto x86_l_2ae3;
	case 10981ULL: goto x86_l_2ae5;
	case 10984ULL: goto x86_l_2ae8;
	case 10987ULL: goto x86_l_2aeb;
	case 10989ULL: goto x86_l_2aed;
	case 10993ULL: goto x86_l_2af1;
	case 10995ULL: goto x86_l_2af3;
	case 11000ULL: goto x86_l_2af8;
	case 11006ULL: goto x86_l_2afe;
	case 11011ULL: goto x86_l_2b03;
	case 11014ULL: goto x86_l_2b06;
	case 11016ULL: goto x86_l_2b08;
	case 11019ULL: goto x86_l_2b0b;
	case 11025ULL: goto x86_l_2b11;
	case 11028ULL: goto x86_l_2b14;
	case 11034ULL: goto x86_l_2b1a;
	case 11040ULL: goto x86_l_2b20;
	case 11044ULL: goto x86_l_2b24;
	case 11050ULL: goto x86_l_2b2a;
	case 11054ULL: goto x86_l_2b2e;
	case 11057ULL: goto x86_l_2b31;
	case 11063ULL: goto x86_l_2b37;
	case 11068ULL: goto x86_l_2b3c;
	case 11071ULL: goto x86_l_2b3f;
	case 11076ULL: goto x86_l_2b44;
	case 11082ULL: goto x86_l_2b4a;
	case 11086ULL: goto x86_l_2b4e;
	case 11089ULL: goto x86_l_2b51;
	case 11095ULL: goto x86_l_2b57;
	case 11100ULL: goto x86_l_2b5c;
	case 11103ULL: goto x86_l_2b5f;
	case 11109ULL: goto x86_l_2b65;
	case 11115ULL: goto x86_l_2b6b;
	case 11119ULL: goto x86_l_2b6f;
	case 11125ULL: goto x86_l_2b75;
	case 11129ULL: goto x86_l_2b79;
	case 11132ULL: goto x86_l_2b7c;
	case 11138ULL: goto x86_l_2b82;
	case 11143ULL: goto x86_l_2b87;
	case 11146ULL: goto x86_l_2b8a;
	case 11149ULL: goto x86_l_2b8d;
	case 11152ULL: goto x86_l_2b90;
	case 11157ULL: goto x86_l_2b95;
	case 11160ULL: goto x86_l_2b98;
	case 11166ULL: goto x86_l_2b9e;
	case 11169ULL: goto x86_l_2ba1;
	case 11175ULL: goto x86_l_2ba7;
	case 11180ULL: goto x86_l_2bac;
	case 11185ULL: goto x86_l_2bb1;
	case 11192ULL: goto x86_l_2bb8;
	case 11197ULL: goto x86_l_2bbd;
	case 11200ULL: goto x86_l_2bc0;
	case 11206ULL: goto x86_l_2bc6;
	case 11209ULL: goto x86_l_2bc9;
	case 11215ULL: goto x86_l_2bcf;
	case 11220ULL: goto x86_l_2bd4;
	case 11225ULL: goto x86_l_2bd9;
	case 11232ULL: goto x86_l_2be0;
	case 11237ULL: goto x86_l_2be5;
	case 11240ULL: goto x86_l_2be8;
	case 11246ULL: goto x86_l_2bee;
	case 11249ULL: goto x86_l_2bf1;
	case 11255ULL: goto x86_l_2bf7;
	case 11260ULL: goto x86_l_2bfc;
	case 11265ULL: goto x86_l_2c01;
	case 11270ULL: goto x86_l_2c06;
	case 11273ULL: goto x86_l_2c09;
	case 11278ULL: goto x86_l_2c0e;
	case 11281ULL: goto x86_l_2c11;
	case 11287ULL: goto x86_l_2c17;
	case 11290ULL: goto x86_l_2c1a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_25ba:
	/* 0x25ba: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_25bd:
	/* 0x25bd: ja     2a16 <generic_usdt_filter_arg+0x2a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2a16;
	}
x86_l_25c3:
	/* 0x25c3: mov    r10d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 5122ULL);
x86_l_25c9:
	/* 0x25c9: bt     r10d,ecx */
	X86_SIM_L_EXEC_BT(X86_R10, X86_RCX, X86_WIDTH_32);
x86_l_25cd:
	/* 0x25cd: jae    2a16 <generic_usdt_filter_arg+0x2a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2a16;
	}
x86_l_25d3:
	/* 0x25d3: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_25d6:
	/* 0x25d6: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_25da:
	/* 0x25da: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_25dc:
	/* 0x25dc: setle  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_LE);
x86_l_25e0:
	/* 0x25e0: jmp    2a23 <generic_usdt_filter_arg+0x2a23> */
	goto x86_l_2a23;
x86_l_25e5:
	/* 0x25e5: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_25e7:
	/* 0x25e7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25ec:
	/* 0x25ec: ja     25f6 <generic_usdt_filter_arg+0x25f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_25f6;
	}
x86_l_25ee:
	/* 0x25ee: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_25f0:
	/* 0x25f0: jbe    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 716ULL;
	}
x86_l_25f6:
	/* 0x25f6: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_25f9:
	/* 0x25f9: jb     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 269ULL;
	}
x86_l_25ff:
	/* 0x25ff: mov    edi,DWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2604:
	/* 0x2604: mov    esi,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2609:
	/* 0x2609: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_260c:
	/* 0x260c: ja     2a64 <generic_usdt_filter_arg+0x2a64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2a64;
	}
x86_l_2612:
	/* 0x2612: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2618:
	/* 0x2618: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_261c:
	/* 0x261c: jae    2a64 <generic_usdt_filter_arg+0x2a64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2a64;
	}
x86_l_2622:
	/* 0x2622: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_2624:
	/* 0x2624: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2629:
	/* 0x2629: jg     2a75 <generic_usdt_filter_arg+0x2a75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2a75;
	}
x86_l_262f:
	/* 0x262f: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_2631:
	/* 0x2631: jle    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 716ULL;
	}
x86_l_2637:
	/* 0x2637: jmp    2a75 <generic_usdt_filter_arg+0x2a75> */
	goto x86_l_2a75;
x86_l_263c:
	/* 0x263c: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2641:
	/* 0x2641: mov    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2646:
	/* 0x2646: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_264b:
	/* 0x264b: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2650:
	/* 0x2650: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_2654:
	/* 0x2654: jbe    2f67 <generic_usdt_filter_arg+0x2f67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 12135ULL;
	}
x86_l_265a:
	/* 0x265a: jmp    2bb <generic_usdt_filter_arg+0x2bb> */
	return 699ULL;
x86_l_265f:
	/* 0x265f: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2664:
	/* 0x2664: mov    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2669:
	/* 0x2669: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_266e:
	/* 0x266e: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2673:
	/* 0x2673: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2678:
	/* 0x2678: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_267c:
	/* 0x267c: jbe    2f67 <generic_usdt_filter_arg+0x2f67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 12135ULL;
	}
x86_l_2682:
	/* 0x2682: jmp    2bb <generic_usdt_filter_arg+0x2bb> */
	return 699ULL;
x86_l_2687:
	/* 0x2687: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_268a:
	/* 0x268a: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_268e:
	/* 0x268e: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2691:
	/* 0x2691: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_2695:
	/* 0x2695: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2698:
	/* 0x2698: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_269b:
	/* 0x269b: cmp    esi,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 57ULL);
x86_l_269e:
	/* 0x269e: jb     2dbd <generic_usdt_filter_arg+0x2dbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11709ULL;
	}
x86_l_26a4:
	/* 0x26a4: mov    rdi,QWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_26a9:
	/* 0x26a9: mov    rsi,QWORD PTR [r12+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_26ae:
	/* 0x26ae: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_26b1:
	/* 0x26b1: je     26bc <generic_usdt_filter_arg+0x26bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26bc;
	}
x86_l_26b3:
	/* 0x26b3: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_26b6:
	/* 0x26b6: jne    2b87 <generic_usdt_filter_arg+0x2b87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b87;
	}
x86_l_26bc:
	/* 0x26bc: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_26bf:
	/* 0x26bf: setle  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_LE);
x86_l_26c2:
	/* 0x26c2: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_26c5:
	/* 0x26c5: jmp    2a5c <generic_usdt_filter_arg+0x2a5c> */
	goto x86_l_2a5c;
x86_l_26ca:
	/* 0x26ca: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26cc:
	/* 0x26cc: jmp    2b6 <generic_usdt_filter_arg+0x2b6> */
	return 694ULL;
x86_l_26d1:
	/* 0x26d1: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26d6:
	/* 0x26d6: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26d9:
	/* 0x26d9: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_26dd:
	/* 0x26dd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26e2:
	/* 0x26e2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26e6:
	/* 0x26e6: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_26e8:
	/* 0x26e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26ea:
	/* 0x26ea: movzx  esi,WORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 152ULL);
x86_l_26f2:
	/* 0x26f2: cmp    esi,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_26f4:
	/* 0x26f4: jbe    2715 <generic_usdt_filter_arg+0x2715> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2715;
	}
x86_l_26f6:
	/* 0x26f6: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26fb:
	/* 0x26fb: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_26ff:
	/* 0x26ff: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2703:
	/* 0x2703: sub    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2705:
	/* 0x2705: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_270b:
	/* 0x270b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2710:
	/* 0x2710: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2713:
	/* 0x2713: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2715:
	/* 0x2715: mov    eax,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2719:
	/* 0x2719: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_271d:
	/* 0x271d: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2721:
	/* 0x2721: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2724:
	/* 0x2724: jg     2760 <generic_usdt_filter_arg+0x2760> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2760;
	}
x86_l_2726:
	/* 0x2726: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2729:
	/* 0x2729: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_272e:
	/* 0x272e: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2733:
	/* 0x2733: jg     2b95 <generic_usdt_filter_arg+0x2b95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2b95;
	}
x86_l_2739:
	/* 0x2739: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_273b:
	/* 0x273b: je     2edd <generic_usdt_filter_arg+0x2edd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11997ULL;
	}
x86_l_2741:
	/* 0x2741: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2744:
	/* 0x2744: jne    2f80 <generic_usdt_filter_arg+0x2f80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12160ULL;
	}
x86_l_274a:
	/* 0x274a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_274f:
	/* 0x274f: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2754:
	/* 0x2754: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_275b:
	/* 0x275b: jmp    2f27 <generic_usdt_filter_arg+0x2f27> */
	return 12071ULL;
x86_l_2760:
	/* 0x2760: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2763:
	/* 0x2763: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2768:
	/* 0x2768: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_276d:
	/* 0x276d: jg     2bbd <generic_usdt_filter_arg+0x2bbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2bbd;
	}
x86_l_2773:
	/* 0x2773: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2776:
	/* 0x2776: je     2ef0 <generic_usdt_filter_arg+0x2ef0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12016ULL;
	}
x86_l_277c:
	/* 0x277c: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_277f:
	/* 0x277f: jne    2f80 <generic_usdt_filter_arg+0x2f80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12160ULL;
	}
x86_l_2785:
	/* 0x2785: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_278a:
	/* 0x278a: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_278f:
	/* 0x278f: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_2796:
	/* 0x2796: jmp    2f27 <generic_usdt_filter_arg+0x2f27> */
	return 12071ULL;
x86_l_279b:
	/* 0x279b: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_279e:
	/* 0x279e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27a3:
	/* 0x27a3: ja     27ae <generic_usdt_filter_arg+0x27ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_27ae;
	}
x86_l_27a5:
	/* 0x27a5: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_27a8:
	/* 0x27a8: jbe    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 716ULL;
	}
x86_l_27ae:
	/* 0x27ae: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_27b1:
	/* 0x27b1: jb     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 269ULL;
	}
x86_l_27b7:
	/* 0x27b7: mov    rsi,QWORD PTR [r12+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_27bc:
	/* 0x27bc: mov    rdx,QWORD PTR [r12+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_27c1:
	/* 0x27c1: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_27c4:
	/* 0x27c4: je     27cf <generic_usdt_filter_arg+0x27cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27cf;
	}
x86_l_27c6:
	/* 0x27c6: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_27c9:
	/* 0x27c9: jne    2be5 <generic_usdt_filter_arg+0x2be5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2be5;
	}
x86_l_27cf:
	/* 0x27cf: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_27d2:
	/* 0x27d2: jg     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 269ULL;
	}
x86_l_27d8:
	/* 0x27d8: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_27db:
	/* 0x27db: jle    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 716ULL;
	}
x86_l_27e1:
	/* 0x27e1: jmp    10d <generic_usdt_filter_arg+0x10d> */
	return 269ULL;
x86_l_27e6:
	/* 0x27e6: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27ea:
	/* 0x27ea: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27ed:
	/* 0x27ed: ja     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_27f3:
	/* 0x27f3: jmp    2802 <generic_usdt_filter_arg+0x2802> */
	goto x86_l_2802;
x86_l_27f5:
	/* 0x27f5: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27f9:
	/* 0x27f9: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27fc:
	/* 0x27fc: jb     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_2802:
	/* 0x2802: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_2805:
	/* 0x2805: jb     32b7 <generic_usdt_filter_arg+0x32b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12983ULL;
	}
x86_l_280b:
	/* 0x280b: mov    rsi,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2810:
	/* 0x2810: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2813:
	/* 0x2813: jle    2834 <generic_usdt_filter_arg+0x2834> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2834;
	}
x86_l_2815:
	/* 0x2815: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2818:
	/* 0x2818: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_281b:
	/* 0x281b: jae    2866 <generic_usdt_filter_arg+0x2866> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2866;
	}
x86_l_281d:
	/* 0x281d: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2821:
	/* 0x2821: cmp    QWORD PTR [rdi],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2824:
	/* 0x2824: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2829:
	/* 0x2829: jne    2deb <generic_usdt_filter_arg+0x2deb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11755ULL;
	}
x86_l_282f:
	/* 0x282f: jmp    31a4 <generic_usdt_filter_arg+0x31a4> */
	return 12708ULL;
x86_l_2834:
	/* 0x2834: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2837:
	/* 0x2837: je     28d5 <generic_usdt_filter_arg+0x28d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28d5;
	}
x86_l_283d:
	/* 0x283d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2840:
	/* 0x2840: jne    2deb <generic_usdt_filter_arg+0x2deb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11755ULL;
	}
x86_l_2846:
	/* 0x2846: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2849:
	/* 0x2849: je     2854 <generic_usdt_filter_arg+0x2854> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2854;
	}
x86_l_284b:
	/* 0x284b: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_284e:
	/* 0x284e: jne    2dde <generic_usdt_filter_arg+0x2dde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11742ULL;
	}
x86_l_2854:
	/* 0x2854: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2858:
	/* 0x2858: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_285b:
	/* 0x285b: jl     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 716ULL;
	}
x86_l_2861:
	/* 0x2861: jmp    2deb <generic_usdt_filter_arg+0x2deb> */
	return 11755ULL;
x86_l_2866:
	/* 0x2866: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2869:
	/* 0x2869: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_286e:
	/* 0x286e: jne    2deb <generic_usdt_filter_arg+0x2deb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11755ULL;
	}
x86_l_2874:
	/* 0x2874: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2878:
	/* 0x2878: test   QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_287b:
	/* 0x287b: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_2881:
	/* 0x2881: jmp    2deb <generic_usdt_filter_arg+0x2deb> */
	return 11755ULL;
x86_l_2886:
	/* 0x2886: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2889:
	/* 0x2889: jne    298d <generic_usdt_filter_arg+0x298d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_298d;
	}
x86_l_288f:
	/* 0x288f: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2893:
	/* 0x2893: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2896:
	/* 0x2896: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2898:
	/* 0x2898: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_289e:
	/* 0x289e: jmp    298d <generic_usdt_filter_arg+0x298d> */
	goto x86_l_298d;
x86_l_28a3:
	/* 0x28a3: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_28a6:
	/* 0x28a6: jne    29d3 <generic_usdt_filter_arg+0x29d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29d3;
	}
x86_l_28ac:
	/* 0x28ac: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28b0:
	/* 0x28b0: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_28b3:
	/* 0x28b3: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_28b5:
	/* 0x28b5: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_28bb:
	/* 0x28bb: jmp    29d3 <generic_usdt_filter_arg+0x29d3> */
	goto x86_l_29d3;
x86_l_28c0:
	/* 0x28c0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28c5:
	/* 0x28c5: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28ca:
	/* 0x28ca: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_28cd:
	/* 0x28cd: movzx  ebx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_28d0:
	/* 0x28d0: jmp    2bb <generic_usdt_filter_arg+0x2bb> */
	return 699ULL;
x86_l_28d5:
	/* 0x28d5: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_28d8:
	/* 0x28d8: je     28e3 <generic_usdt_filter_arg+0x28e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28e3;
	}
x86_l_28da:
	/* 0x28da: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_28dd:
	/* 0x28dd: jne    2dcf <generic_usdt_filter_arg+0x2dcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11727ULL;
	}
x86_l_28e3:
	/* 0x28e3: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28e7:
	/* 0x28e7: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28ea:
	/* 0x28ea: jg     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 716ULL;
	}
x86_l_28f0:
	/* 0x28f0: jmp    2deb <generic_usdt_filter_arg+0x2deb> */
	return 11755ULL;
x86_l_28f5:
	/* 0x28f5: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28f7:
	/* 0x28f7: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28fc:
	/* 0x28fc: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_28ff:
	/* 0x28ff: mov    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2904:
	/* 0x2904: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2909:
	/* 0x2909: jmp    3216 <generic_usdt_filter_arg+0x3216> */
	return 12822ULL;
x86_l_290e:
	/* 0x290e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2911:
	/* 0x2911: je     2d52 <generic_usdt_filter_arg+0x2d52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11602ULL;
	}
x86_l_2917:
	/* 0x2917: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_291a:
	/* 0x291a: jne    94c <generic_usdt_filter_arg+0x94c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2380ULL;
	}
x86_l_2920:
	/* 0x2920: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2925:
	/* 0x2925: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_292a:
	/* 0x292a: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_2931:
	/* 0x2931: jmp    2d76 <generic_usdt_filter_arg+0x2d76> */
	return 11638ULL;
x86_l_2936:
	/* 0x2936: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2939:
	/* 0x2939: je     2d65 <generic_usdt_filter_arg+0x2d65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11621ULL;
	}
x86_l_293f:
	/* 0x293f: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2942:
	/* 0x2942: jne    94c <generic_usdt_filter_arg+0x94c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2380ULL;
	}
x86_l_2948:
	/* 0x2948: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_294d:
	/* 0x294d: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2952:
	/* 0x2952: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2959:
	/* 0x2959: jmp    2d76 <generic_usdt_filter_arg+0x2d76> */
	return 11638ULL;
x86_l_295e:
	/* 0x295e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2960:
	/* 0x2960: jmp    2967 <generic_usdt_filter_arg+0x2967> */
	goto x86_l_2967;
x86_l_2962:
	/* 0x2962: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2967:
	/* 0x2967: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_296c:
	/* 0x296c: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2971:
	/* 0x2971: mov    r11,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_64);
x86_l_2974:
	/* 0x2974: mov    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2979:
	/* 0x2979: jmp    3216 <generic_usdt_filter_arg+0x3216> */
	return 12822ULL;
x86_l_297e:
	/* 0x297e: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2982:
	/* 0x2982: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2985:
	/* 0x2985: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2987:
	/* 0x2987: jb     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_298d:
	/* 0x298d: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2990:
	/* 0x2990: jb     32b7 <generic_usdt_filter_arg+0x32b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12983ULL;
	}
x86_l_2996:
	/* 0x2996: mov    edx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_299b:
	/* 0x299b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_299e:
	/* 0x299e: jle    2c0e <generic_usdt_filter_arg+0x2c0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2c0e;
	}
x86_l_29a4:
	/* 0x29a4: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_29a7:
	/* 0x29a7: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_29aa:
	/* 0x29aa: jae    2e6e <generic_usdt_filter_arg+0x2e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11886ULL;
	}
x86_l_29b0:
	/* 0x29b0: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29b4:
	/* 0x29b4: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_29b7:
	/* 0x29b7: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_29b9:
	/* 0x29b9: jne    2fec <generic_usdt_filter_arg+0x2fec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12268ULL;
	}
x86_l_29bf:
	/* 0x29bf: jmp    31a4 <generic_usdt_filter_arg+0x31a4> */
	return 12708ULL;
x86_l_29c4:
	/* 0x29c4: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29c8:
	/* 0x29c8: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_29cb:
	/* 0x29cb: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_29cd:
	/* 0x29cd: jb     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_29d3:
	/* 0x29d3: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_29d6:
	/* 0x29d6: jb     32b7 <generic_usdt_filter_arg+0x32b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12983ULL;
	}
x86_l_29dc:
	/* 0x29dc: mov    edx,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29e1:
	/* 0x29e1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_29e4:
	/* 0x29e4: jle    2c34 <generic_usdt_filter_arg+0x2c34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 11316ULL;
	}
x86_l_29ea:
	/* 0x29ea: lea    esi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_29ed:
	/* 0x29ed: cmp    esi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_29f0:
	/* 0x29f0: jae    2e8b <generic_usdt_filter_arg+0x2e8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11915ULL;
	}
x86_l_29f6:
	/* 0x29f6: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29fa:
	/* 0x29fa: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_29fd:
	/* 0x29fd: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_29ff:
	/* 0x29ff: jne    3039 <generic_usdt_filter_arg+0x3039> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12345ULL;
	}
x86_l_2a05:
	/* 0x2a05: jmp    31a4 <generic_usdt_filter_arg+0x31a4> */
	return 12708ULL;
x86_l_2a0a:
	/* 0x2a0a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a0c:
	/* 0x2a0c: mov    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2a11:
	/* 0x2a11: jmp    3216 <generic_usdt_filter_arg+0x3216> */
	return 12822ULL;
x86_l_2a16:
	/* 0x2a16: cmp    r8d,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_2a19:
	/* 0x2a19: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_2a1d:
	/* 0x2a1d: cmp    edx,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_2a1f:
	/* 0x2a1f: setbe  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_BE);
x86_l_2a23:
	/* 0x2a23: and    dil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2a26:
	/* 0x2a26: or     al,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_8, X86_ALU_OR);
x86_l_2a29:
	/* 0x2a29: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_2a2c:
	/* 0x2a2c: jb     2dbd <generic_usdt_filter_arg+0x2dbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11709ULL;
	}
x86_l_2a32:
	/* 0x2a32: mov    edi,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a37:
	/* 0x2a37: mov    esi,DWORD PTR [r12+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2a3c:
	/* 0x2a3c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2a3f:
	/* 0x2a3f: ja     2daf <generic_usdt_filter_arg+0x2daf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11695ULL;
	}
x86_l_2a45:
	/* 0x2a45: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2a4b:
	/* 0x2a4b: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2a4f:
	/* 0x2a4f: jae    2daf <generic_usdt_filter_arg+0x2daf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11695ULL;
	}
x86_l_2a55:
	/* 0x2a55: cmp    edi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_2a57:
	/* 0x2a57: setle  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_LE);
x86_l_2a5a:
	/* 0x2a5a: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2a5c:
	/* 0x2a5c: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_2a5f:
	/* 0x2a5f: jmp    2db9 <generic_usdt_filter_arg+0x2db9> */
	return 11705ULL;
x86_l_2a64:
	/* 0x2a64: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_2a66:
	/* 0x2a66: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a6b:
	/* 0x2a6b: ja     2a75 <generic_usdt_filter_arg+0x2a75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2a75;
	}
x86_l_2a6d:
	/* 0x2a6d: cmp    eax,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_2a6f:
	/* 0x2a6f: jbe    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 716ULL;
	}
x86_l_2a75:
	/* 0x2a75: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2a78:
	/* 0x2a78: jb     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 269ULL;
	}
x86_l_2a7e:
	/* 0x2a7e: mov    esi,DWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a83:
	/* 0x2a83: mov    edx,DWORD PTR [r12+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2a88:
	/* 0x2a88: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2a8b:
	/* 0x2a8b: ja     2ea8 <generic_usdt_filter_arg+0x2ea8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11944ULL;
	}
x86_l_2a91:
	/* 0x2a91: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2a97:
	/* 0x2a97: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2a9b:
	/* 0x2a9b: jae    2ea8 <generic_usdt_filter_arg+0x2ea8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11944ULL;
	}
x86_l_2aa1:
	/* 0x2aa1: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2aa3:
	/* 0x2aa3: jg     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 269ULL;
	}
x86_l_2aa9:
	/* 0x2aa9: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2aab:
	/* 0x2aab: jle    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 716ULL;
	}
x86_l_2ab1:
	/* 0x2ab1: jmp    10d <generic_usdt_filter_arg+0x10d> */
	return 269ULL;
x86_l_2ab6:
	/* 0x2ab6: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aba:
	/* 0x2aba: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2abd:
	/* 0x2abd: ja     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_2ac3:
	/* 0x2ac3: jmp    2ad2 <generic_usdt_filter_arg+0x2ad2> */
	goto x86_l_2ad2;
x86_l_2ac5:
	/* 0x2ac5: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ac9:
	/* 0x2ac9: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2acc:
	/* 0x2acc: jb     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_2ad2:
	/* 0x2ad2: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2ad5:
	/* 0x2ad5: jb     32b7 <generic_usdt_filter_arg+0x32b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12983ULL;
	}
x86_l_2adb:
	/* 0x2adb: mov    esi,DWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ae0:
	/* 0x2ae0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ae3:
	/* 0x2ae3: jle    2b03 <generic_usdt_filter_arg+0x2b03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2b03;
	}
x86_l_2ae5:
	/* 0x2ae5: lea    edi,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2ae8:
	/* 0x2ae8: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_2aeb:
	/* 0x2aeb: jae    2b3c <generic_usdt_filter_arg+0x2b3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2b3c;
	}
x86_l_2aed:
	/* 0x2aed: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2af1:
	/* 0x2af1: cmp    DWORD PTR [rdi],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2af3:
	/* 0x2af3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2af8:
	/* 0x2af8: jne    309e <generic_usdt_filter_arg+0x309e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12446ULL;
	}
x86_l_2afe:
	/* 0x2afe: jmp    31a4 <generic_usdt_filter_arg+0x31a4> */
	return 12708ULL;
x86_l_2b03:
	/* 0x2b03: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b06:
	/* 0x2b06: je     2b5c <generic_usdt_filter_arg+0x2b5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b5c;
	}
x86_l_2b08:
	/* 0x2b08: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2b0b:
	/* 0x2b0b: jne    309e <generic_usdt_filter_arg+0x309e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12446ULL;
	}
x86_l_2b11:
	/* 0x2b11: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2b14:
	/* 0x2b14: ja     3091 <generic_usdt_filter_arg+0x3091> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12433ULL;
	}
x86_l_2b1a:
	/* 0x2b1a: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2b20:
	/* 0x2b20: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2b24:
	/* 0x2b24: jae    3091 <generic_usdt_filter_arg+0x3091> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12433ULL;
	}
x86_l_2b2a:
	/* 0x2b2a: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b2e:
	/* 0x2b2e: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b31:
	/* 0x2b31: jl     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 716ULL;
	}
x86_l_2b37:
	/* 0x2b37: jmp    309e <generic_usdt_filter_arg+0x309e> */
	return 12446ULL;
x86_l_2b3c:
	/* 0x2b3c: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2b3f:
	/* 0x2b3f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b44:
	/* 0x2b44: jne    309e <generic_usdt_filter_arg+0x309e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12446ULL;
	}
x86_l_2b4a:
	/* 0x2b4a: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b4e:
	/* 0x2b4e: test   DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b51:
	/* 0x2b51: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_2b57:
	/* 0x2b57: jmp    309e <generic_usdt_filter_arg+0x309e> */
	return 12446ULL;
x86_l_2b5c:
	/* 0x2b5c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2b5f:
	/* 0x2b5f: ja     3082 <generic_usdt_filter_arg+0x3082> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12418ULL;
	}
x86_l_2b65:
	/* 0x2b65: mov    r8d,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5122ULL);
x86_l_2b6b:
	/* 0x2b6b: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_2b6f:
	/* 0x2b6f: jae    3082 <generic_usdt_filter_arg+0x3082> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12418ULL;
	}
x86_l_2b75:
	/* 0x2b75: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b79:
	/* 0x2b79: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b7c:
	/* 0x2b7c: jg     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 716ULL;
	}
x86_l_2b82:
	/* 0x2b82: jmp    309e <generic_usdt_filter_arg+0x309e> */
	return 12446ULL;
x86_l_2b87:
	/* 0x2b87: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2b8a:
	/* 0x2b8a: setbe  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_BE);
x86_l_2b8d:
	/* 0x2b8d: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_2b90:
	/* 0x2b90: jmp    2db6 <generic_usdt_filter_arg+0x2db6> */
	return 11702ULL;
x86_l_2b95:
	/* 0x2b95: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2b98:
	/* 0x2b98: je     2f03 <generic_usdt_filter_arg+0x2f03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12035ULL;
	}
x86_l_2b9e:
	/* 0x2b9e: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2ba1:
	/* 0x2ba1: jne    2f80 <generic_usdt_filter_arg+0x2f80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12160ULL;
	}
x86_l_2ba7:
	/* 0x2ba7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bac:
	/* 0x2bac: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2bb1:
	/* 0x2bb1: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_2bb8:
	/* 0x2bb8: jmp    2f27 <generic_usdt_filter_arg+0x2f27> */
	return 12071ULL;
x86_l_2bbd:
	/* 0x2bbd: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2bc0:
	/* 0x2bc0: je     2f16 <generic_usdt_filter_arg+0x2f16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12054ULL;
	}
x86_l_2bc6:
	/* 0x2bc6: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2bc9:
	/* 0x2bc9: jne    2f80 <generic_usdt_filter_arg+0x2f80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12160ULL;
	}
x86_l_2bcf:
	/* 0x2bcf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bd4:
	/* 0x2bd4: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2bd9:
	/* 0x2bd9: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2be0:
	/* 0x2be0: jmp    2f27 <generic_usdt_filter_arg+0x2f27> */
	return 12071ULL;
x86_l_2be5:
	/* 0x2be5: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_2be8:
	/* 0x2be8: ja     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 269ULL;
	}
x86_l_2bee:
	/* 0x2bee: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_2bf1:
	/* 0x2bf1: jbe    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 716ULL;
	}
x86_l_2bf7:
	/* 0x2bf7: jmp    10d <generic_usdt_filter_arg+0x10d> */
	return 269ULL;
x86_l_2bfc:
	/* 0x2bfc: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c01:
	/* 0x2c01: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c06:
	/* 0x2c06: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_2c09:
	/* 0x2c09: jmp    2b3 <generic_usdt_filter_arg+0x2b3> */
	return 691ULL;
x86_l_2c0e:
	/* 0x2c0e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c11:
	/* 0x2c11: je     2fdd <generic_usdt_filter_arg+0x2fdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12253ULL;
	}
x86_l_2c17:
	/* 0x2c17: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c1a:
	/* 0x2c1a: jne    2fec <generic_usdt_filter_arg+0x2fec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12268ULL;
	}
	return 11296ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_usdt_filter_arg_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11296ULL: goto x86_l_2c20;
	case 11300ULL: goto x86_l_2c24;
	case 11303ULL: goto x86_l_2c27;
	case 11305ULL: goto x86_l_2c29;
	case 11311ULL: goto x86_l_2c2f;
	case 11316ULL: goto x86_l_2c34;
	case 11319ULL: goto x86_l_2c37;
	case 11325ULL: goto x86_l_2c3d;
	case 11328ULL: goto x86_l_2c40;
	case 11334ULL: goto x86_l_2c46;
	case 11338ULL: goto x86_l_2c4a;
	case 11341ULL: goto x86_l_2c4d;
	case 11343ULL: goto x86_l_2c4f;
	case 11349ULL: goto x86_l_2c55;
	case 11354ULL: goto x86_l_2c5a;
	case 11359ULL: goto x86_l_2c5f;
	case 11364ULL: goto x86_l_2c64;
	case 11369ULL: goto x86_l_2c69;
	case 11374ULL: goto x86_l_2c6e;
	case 11379ULL: goto x86_l_2c73;
	case 11382ULL: goto x86_l_2c76;
	case 11387ULL: goto x86_l_2c7b;
	case 11390ULL: goto x86_l_2c7e;
	case 11393ULL: goto x86_l_2c81;
	case 11397ULL: goto x86_l_2c85;
	case 11402ULL: goto x86_l_2c8a;
	case 11406ULL: goto x86_l_2c8e;
	case 11408ULL: goto x86_l_2c90;
	case 11410ULL: goto x86_l_2c92;
	case 11412ULL: goto x86_l_2c94;
	case 11414ULL: goto x86_l_2c96;
	case 11422ULL: goto x86_l_2c9e;
	case 11425ULL: goto x86_l_2ca1;
	case 11427ULL: goto x86_l_2ca3;
	case 11433ULL: goto x86_l_2ca9;
	case 11438ULL: goto x86_l_2cae;
	case 11446ULL: goto x86_l_2cb6;
	case 11448ULL: goto x86_l_2cb8;
	case 11450ULL: goto x86_l_2cba;
	case 11454ULL: goto x86_l_2cbe;
	case 11458ULL: goto x86_l_2cc2;
	case 11462ULL: goto x86_l_2cc6;
	case 11465ULL: goto x86_l_2cc9;
	case 11467ULL: goto x86_l_2ccb;
	case 11470ULL: goto x86_l_2cce;
	case 11475ULL: goto x86_l_2cd3;
	case 11481ULL: goto x86_l_2cd9;
	case 11483ULL: goto x86_l_2cdb;
	case 11489ULL: goto x86_l_2ce1;
	case 11492ULL: goto x86_l_2ce4;
	case 11498ULL: goto x86_l_2cea;
	case 11503ULL: goto x86_l_2cef;
	case 11510ULL: goto x86_l_2cf6;
	case 11515ULL: goto x86_l_2cfb;
	case 11518ULL: goto x86_l_2cfe;
	case 11523ULL: goto x86_l_2d03;
	case 11529ULL: goto x86_l_2d09;
	case 11532ULL: goto x86_l_2d0c;
	case 11538ULL: goto x86_l_2d12;
	case 11541ULL: goto x86_l_2d15;
	case 11547ULL: goto x86_l_2d1b;
	case 11552ULL: goto x86_l_2d20;
	case 11559ULL: goto x86_l_2d27;
	case 11564ULL: goto x86_l_2d2c;
	case 11569ULL: goto x86_l_2d31;
	case 11576ULL: goto x86_l_2d38;
	case 11581ULL: goto x86_l_2d3d;
	case 11583ULL: goto x86_l_2d3f;
	case 11588ULL: goto x86_l_2d44;
	case 11593ULL: goto x86_l_2d49;
	case 11600ULL: goto x86_l_2d50;
	case 11602ULL: goto x86_l_2d52;
	case 11607ULL: goto x86_l_2d57;
	case 11612ULL: goto x86_l_2d5c;
	case 11619ULL: goto x86_l_2d63;
	case 11621ULL: goto x86_l_2d65;
	case 11626ULL: goto x86_l_2d6a;
	case 11631ULL: goto x86_l_2d6f;
	case 11638ULL: goto x86_l_2d76;
	case 11640ULL: goto x86_l_2d78;
	case 11643ULL: goto x86_l_2d7b;
	case 11645ULL: goto x86_l_2d7d;
	case 11648ULL: goto x86_l_2d80;
	case 11653ULL: goto x86_l_2d85;
	case 11656ULL: goto x86_l_2d88;
	case 11658ULL: goto x86_l_2d8a;
	case 11660ULL: goto x86_l_2d8c;
	case 11663ULL: goto x86_l_2d8f;
	case 11666ULL: goto x86_l_2d92;
	case 11668ULL: goto x86_l_2d94;
	case 11670ULL: goto x86_l_2d96;
	case 11675ULL: goto x86_l_2d9b;
	case 11680ULL: goto x86_l_2da0;
	case 11685ULL: goto x86_l_2da5;
	case 11690ULL: goto x86_l_2daa;
	case 11695ULL: goto x86_l_2daf;
	case 11697ULL: goto x86_l_2db1;
	case 11700ULL: goto x86_l_2db4;
	case 11702ULL: goto x86_l_2db6;
	case 11705ULL: goto x86_l_2db9;
	case 11707ULL: goto x86_l_2dbb;
	case 11709ULL: goto x86_l_2dbd;
	case 11714ULL: goto x86_l_2dc2;
	case 11716ULL: goto x86_l_2dc4;
	case 11722ULL: goto x86_l_2dca;
	case 11727ULL: goto x86_l_2dcf;
	case 11731ULL: goto x86_l_2dd3;
	case 11734ULL: goto x86_l_2dd6;
	case 11740ULL: goto x86_l_2ddc;
	case 11742ULL: goto x86_l_2dde;
	case 11746ULL: goto x86_l_2de2;
	case 11749ULL: goto x86_l_2de5;
	case 11755ULL: goto x86_l_2deb;
	case 11758ULL: goto x86_l_2dee;
	case 11764ULL: goto x86_l_2df4;
	case 11769ULL: goto x86_l_2df9;
	case 11772ULL: goto x86_l_2dfc;
	case 11774ULL: goto x86_l_2dfe;
	case 11777ULL: goto x86_l_2e01;
	case 11780ULL: goto x86_l_2e04;
	case 11782ULL: goto x86_l_2e06;
	case 11785ULL: goto x86_l_2e09;
	case 11791ULL: goto x86_l_2e0f;
	case 11794ULL: goto x86_l_2e12;
	case 11800ULL: goto x86_l_2e18;
	case 11804ULL: goto x86_l_2e1c;
	case 11807ULL: goto x86_l_2e1f;
	case 11813ULL: goto x86_l_2e25;
	case 11818ULL: goto x86_l_2e2a;
	case 11821ULL: goto x86_l_2e2d;
	case 11827ULL: goto x86_l_2e33;
	case 11830ULL: goto x86_l_2e36;
	case 11836ULL: goto x86_l_2e3c;
	case 11839ULL: goto x86_l_2e3f;
	case 11841ULL: goto x86_l_2e41;
	case 11844ULL: goto x86_l_2e44;
	case 11850ULL: goto x86_l_2e4a;
	case 11854ULL: goto x86_l_2e4e;
	case 11857ULL: goto x86_l_2e51;
	case 11863ULL: goto x86_l_2e57;
	case 11868ULL: goto x86_l_2e5c;
	case 11872ULL: goto x86_l_2e60;
	case 11875ULL: goto x86_l_2e63;
	case 11881ULL: goto x86_l_2e69;
	case 11886ULL: goto x86_l_2e6e;
	case 11889ULL: goto x86_l_2e71;
	case 11895ULL: goto x86_l_2e77;
	case 11899ULL: goto x86_l_2e7b;
	case 11902ULL: goto x86_l_2e7e;
	case 11904ULL: goto x86_l_2e80;
	case 11910ULL: goto x86_l_2e86;
	case 11915ULL: goto x86_l_2e8b;
	case 11918ULL: goto x86_l_2e8e;
	case 11924ULL: goto x86_l_2e94;
	case 11928ULL: goto x86_l_2e98;
	case 11931ULL: goto x86_l_2e9b;
	case 11933ULL: goto x86_l_2e9d;
	case 11939ULL: goto x86_l_2ea3;
	case 11944ULL: goto x86_l_2ea8;
	case 11946ULL: goto x86_l_2eaa;
	case 11952ULL: goto x86_l_2eb0;
	case 11954ULL: goto x86_l_2eb2;
	case 11960ULL: goto x86_l_2eb8;
	case 11965ULL: goto x86_l_2ebd;
	case 11968ULL: goto x86_l_2ec0;
	case 11972ULL: goto x86_l_2ec4;
	case 11974ULL: goto x86_l_2ec6;
	case 11977ULL: goto x86_l_2ec9;
	case 11983ULL: goto x86_l_2ecf;
	case 11986ULL: goto x86_l_2ed2;
	case 11992ULL: goto x86_l_2ed8;
	case 11997ULL: goto x86_l_2edd;
	case 12002ULL: goto x86_l_2ee2;
	case 12009ULL: goto x86_l_2ee9;
	case 12014ULL: goto x86_l_2eee;
	case 12016ULL: goto x86_l_2ef0;
	case 12021ULL: goto x86_l_2ef5;
	case 12026ULL: goto x86_l_2efa;
	case 12033ULL: goto x86_l_2f01;
	case 12035ULL: goto x86_l_2f03;
	case 12040ULL: goto x86_l_2f08;
	case 12045ULL: goto x86_l_2f0d;
	case 12052ULL: goto x86_l_2f14;
	case 12054ULL: goto x86_l_2f16;
	case 12059ULL: goto x86_l_2f1b;
	case 12064ULL: goto x86_l_2f20;
	case 12071ULL: goto x86_l_2f27;
	case 12073ULL: goto x86_l_2f29;
	case 12076ULL: goto x86_l_2f2c;
	case 12078ULL: goto x86_l_2f2e;
	case 12081ULL: goto x86_l_2f31;
	case 12086ULL: goto x86_l_2f36;
	case 12091ULL: goto x86_l_2f3b;
	case 12093ULL: goto x86_l_2f3d;
	case 12095ULL: goto x86_l_2f3f;
	case 12098ULL: goto x86_l_2f42;
	case 12101ULL: goto x86_l_2f45;
	case 12103ULL: goto x86_l_2f47;
	case 12105ULL: goto x86_l_2f49;
	case 12110ULL: goto x86_l_2f4e;
	case 12115ULL: goto x86_l_2f53;
	case 12120ULL: goto x86_l_2f58;
	case 12125ULL: goto x86_l_2f5d;
	case 12129ULL: goto x86_l_2f61;
	case 12135ULL: goto x86_l_2f67;
	case 12145ULL: goto x86_l_2f71;
	case 12149ULL: goto x86_l_2f75;
	case 12155ULL: goto x86_l_2f7b;
	case 12160ULL: goto x86_l_2f80;
	case 12162ULL: goto x86_l_2f82;
	case 12167ULL: goto x86_l_2f87;
	case 12172ULL: goto x86_l_2f8c;
	case 12176ULL: goto x86_l_2f90;
	case 12178ULL: goto x86_l_2f92;
	case 12183ULL: goto x86_l_2f97;
	case 12186ULL: goto x86_l_2f9a;
	case 12192ULL: goto x86_l_2fa0;
	case 12195ULL: goto x86_l_2fa3;
	case 12201ULL: goto x86_l_2fa9;
	case 12206ULL: goto x86_l_2fae;
	case 12213ULL: goto x86_l_2fb5;
	case 12218ULL: goto x86_l_2fba;
	case 12221ULL: goto x86_l_2fbd;
	case 12227ULL: goto x86_l_2fc3;
	case 12230ULL: goto x86_l_2fc6;
	case 12236ULL: goto x86_l_2fcc;
	case 12241ULL: goto x86_l_2fd1;
	case 12248ULL: goto x86_l_2fd8;
	case 12253ULL: goto x86_l_2fdd;
	case 12257ULL: goto x86_l_2fe1;
	case 12260ULL: goto x86_l_2fe4;
	case 12262ULL: goto x86_l_2fe6;
	case 12268ULL: goto x86_l_2fec;
	case 12271ULL: goto x86_l_2fef;
	case 12277ULL: goto x86_l_2ff5;
	case 12282ULL: goto x86_l_2ffa;
	case 12285ULL: goto x86_l_2ffd;
	case 12291ULL: goto x86_l_3003;
	case 12294ULL: goto x86_l_3006;
	case 12297ULL: goto x86_l_3009;
	case 12303ULL: goto x86_l_300f;
	case 12306ULL: goto x86_l_3012;
	case 12312ULL: goto x86_l_3018;
	case 12315ULL: goto x86_l_301b;
	case 12321ULL: goto x86_l_3021;
	case 12325ULL: goto x86_l_3025;
	case 12328ULL: goto x86_l_3028;
	case 12330ULL: goto x86_l_302a;
	case 12334ULL: goto x86_l_302e;
	case 12337ULL: goto x86_l_3031;
	case 12339ULL: goto x86_l_3033;
	case 12345ULL: goto x86_l_3039;
	case 12348ULL: goto x86_l_303c;
	case 12354ULL: goto x86_l_3042;
	case 12359ULL: goto x86_l_3047;
	case 12362ULL: goto x86_l_304a;
	case 12368ULL: goto x86_l_3050;
	case 12371ULL: goto x86_l_3053;
	case 12374ULL: goto x86_l_3056;
	case 12380ULL: goto x86_l_305c;
	case 12383ULL: goto x86_l_305f;
	case 12389ULL: goto x86_l_3065;
	case 12392ULL: goto x86_l_3068;
	case 12398ULL: goto x86_l_306e;
	case 12402ULL: goto x86_l_3072;
	case 12405ULL: goto x86_l_3075;
	case 12407ULL: goto x86_l_3077;
	case 12413ULL: goto x86_l_307d;
	case 12418ULL: goto x86_l_3082;
	case 12422ULL: goto x86_l_3086;
	case 12425ULL: goto x86_l_3089;
	case 12431ULL: goto x86_l_308f;
	case 12433ULL: goto x86_l_3091;
	case 12437ULL: goto x86_l_3095;
	case 12440ULL: goto x86_l_3098;
	case 12446ULL: goto x86_l_309e;
	case 12449ULL: goto x86_l_30a1;
	case 12455ULL: goto x86_l_30a7;
	case 12460ULL: goto x86_l_30ac;
	case 12463ULL: goto x86_l_30af;
	case 12465ULL: goto x86_l_30b1;
	case 12468ULL: goto x86_l_30b4;
	case 12471ULL: goto x86_l_30b7;
	case 12473ULL: goto x86_l_30b9;
	case 12476ULL: goto x86_l_30bc;
	case 12482ULL: goto x86_l_30c2;
	case 12485ULL: goto x86_l_30c5;
	case 12491ULL: goto x86_l_30cb;
	case 12495ULL: goto x86_l_30cf;
	case 12497ULL: goto x86_l_30d1;
	case 12503ULL: goto x86_l_30d7;
	case 12508ULL: goto x86_l_30dc;
	case 12511ULL: goto x86_l_30df;
	case 12513ULL: goto x86_l_30e1;
	case 12516ULL: goto x86_l_30e4;
	case 12522ULL: goto x86_l_30ea;
	case 12525ULL: goto x86_l_30ed;
	case 12531ULL: goto x86_l_30f3;
	case 12536ULL: goto x86_l_30f8;
	case 12539ULL: goto x86_l_30fb;
	case 12545ULL: goto x86_l_3101;
	case 12549ULL: goto x86_l_3105;
	case 12551ULL: goto x86_l_3107;
	case 12557ULL: goto x86_l_310d;
	case 12562ULL: goto x86_l_3112;
	case 12566ULL: goto x86_l_3116;
	case 12568ULL: goto x86_l_3118;
	case 12574ULL: goto x86_l_311e;
	case 12579ULL: goto x86_l_3123;
	case 12582ULL: goto x86_l_3126;
	case 12588ULL: goto x86_l_312c;
	case 12593ULL: goto x86_l_3131;
	case 12596ULL: goto x86_l_3134;
	case 12602ULL: goto x86_l_313a;
	case 12606ULL: goto x86_l_313e;
	case 12608ULL: goto x86_l_3140;
	case 12614ULL: goto x86_l_3146;
	case 12619ULL: goto x86_l_314b;
	case 12622ULL: goto x86_l_314e;
	case 12628ULL: goto x86_l_3154;
	case 12631ULL: goto x86_l_3157;
	case 12637ULL: goto x86_l_315d;
	case 12641ULL: goto x86_l_3161;
	case 12644ULL: goto x86_l_3164;
	case 12646ULL: goto x86_l_3166;
	case 12649ULL: goto x86_l_3169;
	case 12655ULL: goto x86_l_316f;
	case 12658ULL: goto x86_l_3172;
	case 12664ULL: goto x86_l_3178;
	case 12668ULL: goto x86_l_317c;
	case 12671ULL: goto x86_l_317f;
	case 12673ULL: goto x86_l_3181;
	case 12679ULL: goto x86_l_3187;
	case 12684ULL: goto x86_l_318c;
	case 12688ULL: goto x86_l_3190;
	case 12691ULL: goto x86_l_3193;
	case 12693ULL: goto x86_l_3195;
	case 12697ULL: goto x86_l_3199;
	case 12700ULL: goto x86_l_319c;
	case 12702ULL: goto x86_l_319e;
	case 12708ULL: goto x86_l_31a4;
	case 12710ULL: goto x86_l_31a6;
	case 12713ULL: goto x86_l_31a9;
	case 12716ULL: goto x86_l_31ac;
	case 12721ULL: goto x86_l_31b1;
	case 12726ULL: goto x86_l_31b6;
	case 12733ULL: goto x86_l_31bd;
	case 12735ULL: goto x86_l_31bf;
	case 12740ULL: goto x86_l_31c4;
	case 12747ULL: goto x86_l_31cb;
	case 12749ULL: goto x86_l_31cd;
	case 12754ULL: goto x86_l_31d2;
	case 12761ULL: goto x86_l_31d9;
	case 12763ULL: goto x86_l_31db;
	case 12768ULL: goto x86_l_31e0;
	case 12775ULL: goto x86_l_31e7;
	case 12777ULL: goto x86_l_31e9;
	case 12780ULL: goto x86_l_31ec;
	case 12782ULL: goto x86_l_31ee;
	case 12785ULL: goto x86_l_31f1;
	case 12790ULL: goto x86_l_31f6;
	case 12793ULL: goto x86_l_31f9;
	case 12795ULL: goto x86_l_31fb;
	case 12797ULL: goto x86_l_31fd;
	case 12800ULL: goto x86_l_3200;
	case 12803ULL: goto x86_l_3203;
	case 12805ULL: goto x86_l_3205;
	case 12807ULL: goto x86_l_3207;
	case 12812ULL: goto x86_l_320c;
	case 12817ULL: goto x86_l_3211;
	case 12822ULL: goto x86_l_3216;
	case 12827ULL: goto x86_l_321b;
	case 12831ULL: goto x86_l_321f;
	case 12837ULL: goto x86_l_3225;
	case 12847ULL: goto x86_l_322f;
	case 12851ULL: goto x86_l_3233;
	case 12856ULL: goto x86_l_3238;
	case 12862ULL: goto x86_l_323e;
	case 12864ULL: goto x86_l_3240;
	case 12867ULL: goto x86_l_3243;
	case 12870ULL: goto x86_l_3246;
	case 12873ULL: goto x86_l_3249;
	case 12878ULL: goto x86_l_324e;
	case 12882ULL: goto x86_l_3252;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2c20:
	/* 0x2c20: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c24:
	/* 0x2c24: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2c27:
	/* 0x2c27: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2c29:
	/* 0x2c29: ja     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_2c2f:
	/* 0x2c2f: jmp    2fec <generic_usdt_filter_arg+0x2fec> */
	goto x86_l_2fec;
x86_l_2c34:
	/* 0x2c34: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c37:
	/* 0x2c37: je     302a <generic_usdt_filter_arg+0x302a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_302a;
	}
x86_l_2c3d:
	/* 0x2c3d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c40:
	/* 0x2c40: jne    3039 <generic_usdt_filter_arg+0x3039> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3039;
	}
x86_l_2c46:
	/* 0x2c46: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c4a:
	/* 0x2c4a: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c4d:
	/* 0x2c4d: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2c4f:
	/* 0x2c4f: ja     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_2c55:
	/* 0x2c55: jmp    3039 <generic_usdt_filter_arg+0x3039> */
	goto x86_l_3039;
x86_l_2c5a:
	/* 0x2c5a: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_2c5f:
	/* 0x2c5f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c64:
	/* 0x2c64: jmp    3216 <generic_usdt_filter_arg+0x3216> */
	goto x86_l_3216;
x86_l_2c69:
	/* 0x2c69: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c6e:
	/* 0x2c6e: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c73:
	/* 0x2c73: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_2c76:
	/* 0x2c76: jmp    2b3 <generic_usdt_filter_arg+0x2b3> */
	return 691ULL;
x86_l_2c7b:
	/* 0x2c7b: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_2c7e:
	/* 0x2c7e: mov    WORD PTR [rcx],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c81:
	/* 0x2c81: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2c85:
	/* 0x2c85: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c8a:
	/* 0x2c8a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c8e:
	/* 0x2c8e: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2c90:
	/* 0x2c90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c92:
	/* 0x2c92: cmp    ebx,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RBP, X86_WIDTH_32);
x86_l_2c94:
	/* 0x2c94: jbe    2cba <generic_usdt_filter_arg+0x2cba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2cba;
	}
x86_l_2c96:
	/* 0x2c96: lea    rdi,[rbp*1+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 2ULL);
x86_l_2c9e:
	/* 0x2c9e: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ca1:
	/* 0x2ca1: sub    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ca3:
	/* 0x2ca3: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2ca9:
	/* 0x2ca9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cae:
	/* 0x2cae: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2cb6:
	/* 0x2cb6: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_2cb8:
	/* 0x2cb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cba:
	/* 0x2cba: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2cbe:
	/* 0x2cbe: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2cc2:
	/* 0x2cc2: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2cc6:
	/* 0x2cc6: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2cc9:
	/* 0x2cc9: jg     2cfb <generic_usdt_filter_arg+0x2cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2cfb;
	}
x86_l_2ccb:
	/* 0x2ccb: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cce:
	/* 0x2cce: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2cd3:
	/* 0x2cd3: jg     2f97 <generic_usdt_filter_arg+0x2f97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2f97;
	}
x86_l_2cd9:
	/* 0x2cd9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2cdb:
	/* 0x2cdb: je     31b1 <generic_usdt_filter_arg+0x31b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31b1;
	}
x86_l_2ce1:
	/* 0x2ce1: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ce4:
	/* 0x2ce4: jne    3205 <generic_usdt_filter_arg+0x3205> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3205;
	}
x86_l_2cea:
	/* 0x2cea: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cef:
	/* 0x2cef: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_2cf6:
	/* 0x2cf6: jmp    31e7 <generic_usdt_filter_arg+0x31e7> */
	goto x86_l_31e7;
x86_l_2cfb:
	/* 0x2cfb: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2cfe:
	/* 0x2cfe: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d03:
	/* 0x2d03: jg     2fba <generic_usdt_filter_arg+0x2fba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2fba;
	}
x86_l_2d09:
	/* 0x2d09: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d0c:
	/* 0x2d0c: je     31bf <generic_usdt_filter_arg+0x31bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31bf;
	}
x86_l_2d12:
	/* 0x2d12: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2d15:
	/* 0x2d15: jne    3205 <generic_usdt_filter_arg+0x3205> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3205;
	}
x86_l_2d1b:
	/* 0x2d1b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d20:
	/* 0x2d20: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_2d27:
	/* 0x2d27: jmp    31e7 <generic_usdt_filter_arg+0x31e7> */
	goto x86_l_31e7;
x86_l_2d2c:
	/* 0x2d2c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d31:
	/* 0x2d31: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_2d38:
	/* 0x2d38: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d3d:
	/* 0x2d3d: jmp    2d76 <generic_usdt_filter_arg+0x2d76> */
	goto x86_l_2d76;
x86_l_2d3f:
	/* 0x2d3f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d44:
	/* 0x2d44: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d49:
	/* 0x2d49: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_2d50:
	/* 0x2d50: jmp    2d76 <generic_usdt_filter_arg+0x2d76> */
	goto x86_l_2d76;
x86_l_2d52:
	/* 0x2d52: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d57:
	/* 0x2d57: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d5c:
	/* 0x2d5c: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2d63:
	/* 0x2d63: jmp    2d76 <generic_usdt_filter_arg+0x2d76> */
	goto x86_l_2d76;
x86_l_2d65:
	/* 0x2d65: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d6a:
	/* 0x2d6a: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d6f:
	/* 0x2d6f: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_2d76:
	/* 0x2d76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d78:
	/* 0x2d78: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d7b:
	/* 0x2d7b: je     2d94 <generic_usdt_filter_arg+0x2d94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d94;
	}
x86_l_2d7d:
	/* 0x2d7d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2d80:
	/* 0x2d80: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d85:
	/* 0x2d85: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2d88:
	/* 0x2d88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d8a:
	/* 0x2d8a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d8c:
	/* 0x2d8c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d8f:
	/* 0x2d8f: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_2d92:
	/* 0x2d92: jmp    2d96 <generic_usdt_filter_arg+0x2d96> */
	goto x86_l_2d96;
x86_l_2d94:
	/* 0x2d94: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d96:
	/* 0x2d96: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d9b:
	/* 0x2d9b: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2da0:
	/* 0x2da0: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2da5:
	/* 0x2da5: mov    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2daa:
	/* 0x2daa: jmp    cfb <generic_usdt_filter_arg+0xcfb> */
	return 3323ULL;
x86_l_2daf:
	/* 0x2daf: cmp    edi,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_2db1:
	/* 0x2db1: setbe  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_BE);
x86_l_2db4:
	/* 0x2db4: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2db6:
	/* 0x2db6: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_2db9:
	/* 0x2db9: and    dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_AND);
x86_l_2dbb:
	/* 0x2dbb: or     al,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2dbd:
	/* 0x2dbd: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dc2:
	/* 0x2dc2: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2dc4:
	/* 0x2dc4: je     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 716ULL;
	}
x86_l_2dca:
	/* 0x2dca: jmp    10d <generic_usdt_filter_arg+0x10d> */
	return 269ULL;
x86_l_2dcf:
	/* 0x2dcf: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dd3:
	/* 0x2dd3: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dd6:
	/* 0x2dd6: ja     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_2ddc:
	/* 0x2ddc: jmp    2deb <generic_usdt_filter_arg+0x2deb> */
	goto x86_l_2deb;
x86_l_2dde:
	/* 0x2dde: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2de2:
	/* 0x2de2: cmp    QWORD PTR [r8],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2de5:
	/* 0x2de5: jb     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_2deb:
	/* 0x2deb: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2dee:
	/* 0x2dee: jb     32b7 <generic_usdt_filter_arg+0x32b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12983ULL;
	}
x86_l_2df4:
	/* 0x2df4: mov    rdx,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2df9:
	/* 0x2df9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2dfc:
	/* 0x2dfc: jle    2e2a <generic_usdt_filter_arg+0x2e2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2e2a;
	}
x86_l_2dfe:
	/* 0x2dfe: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2e01:
	/* 0x2e01: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2e04:
	/* 0x2e04: jb     2e5c <generic_usdt_filter_arg+0x2e5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2e5c;
	}
x86_l_2e06:
	/* 0x2e06: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2e09:
	/* 0x2e09: je     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 716ULL;
	}
x86_l_2e0f:
	/* 0x2e0f: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2e12:
	/* 0x2e12: jne    10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 269ULL;
	}
x86_l_2e18:
	/* 0x2e18: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e1c:
	/* 0x2e1c: test   QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e1f:
	/* 0x2e1f: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_2e25:
	/* 0x2e25: jmp    32b7 <generic_usdt_filter_arg+0x32b7> */
	return 12983ULL;
x86_l_2e2a:
	/* 0x2e2a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e2d:
	/* 0x2e2d: je     2ebd <generic_usdt_filter_arg+0x2ebd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ebd;
	}
x86_l_2e33:
	/* 0x2e33: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e36:
	/* 0x2e36: jne    10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 269ULL;
	}
x86_l_2e3c:
	/* 0x2e3c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2e3f:
	/* 0x2e3f: je     2e4a <generic_usdt_filter_arg+0x2e4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e4a;
	}
x86_l_2e41:
	/* 0x2e41: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2e44:
	/* 0x2e44: jne    324e <generic_usdt_filter_arg+0x324e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_324e;
	}
x86_l_2e4a:
	/* 0x2e4a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e4e:
	/* 0x2e4e: cmp    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e51:
	/* 0x2e51: jl     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 716ULL;
	}
x86_l_2e57:
	/* 0x2e57: jmp    32b7 <generic_usdt_filter_arg+0x32b7> */
	return 12983ULL;
x86_l_2e5c:
	/* 0x2e5c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e60:
	/* 0x2e60: cmp    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e63:
	/* 0x2e63: je     31a4 <generic_usdt_filter_arg+0x31a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31a4;
	}
x86_l_2e69:
	/* 0x2e69: jmp    32b7 <generic_usdt_filter_arg+0x32b7> */
	return 12983ULL;
x86_l_2e6e:
	/* 0x2e6e: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2e71:
	/* 0x2e71: jne    2fec <generic_usdt_filter_arg+0x2fec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2fec;
	}
x86_l_2e77:
	/* 0x2e77: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e7b:
	/* 0x2e7b: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2e7e:
	/* 0x2e7e: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2e80:
	/* 0x2e80: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_2e86:
	/* 0x2e86: jmp    2fec <generic_usdt_filter_arg+0x2fec> */
	goto x86_l_2fec;
x86_l_2e8b:
	/* 0x2e8b: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2e8e:
	/* 0x2e8e: jne    3039 <generic_usdt_filter_arg+0x3039> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3039;
	}
x86_l_2e94:
	/* 0x2e94: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e98:
	/* 0x2e98: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e9b:
	/* 0x2e9b: test   edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2e9d:
	/* 0x2e9d: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_2ea3:
	/* 0x2ea3: jmp    3039 <generic_usdt_filter_arg+0x3039> */
	goto x86_l_3039;
x86_l_2ea8:
	/* 0x2ea8: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2eaa:
	/* 0x2eaa: ja     10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 269ULL;
	}
x86_l_2eb0:
	/* 0x2eb0: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2eb2:
	/* 0x2eb2: jbe    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 716ULL;
	}
x86_l_2eb8:
	/* 0x2eb8: jmp    10d <generic_usdt_filter_arg+0x10d> */
	return 269ULL;
x86_l_2ebd:
	/* 0x2ebd: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_2ec0:
	/* 0x2ec0: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ec4:
	/* 0x2ec4: je     2ecf <generic_usdt_filter_arg+0x2ecf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ecf;
	}
x86_l_2ec6:
	/* 0x2ec6: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_2ec9:
	/* 0x2ec9: jne    325d <generic_usdt_filter_arg+0x325d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12893ULL;
	}
x86_l_2ecf:
	/* 0x2ecf: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ed2:
	/* 0x2ed2: jg     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 716ULL;
	}
x86_l_2ed8:
	/* 0x2ed8: jmp    32b7 <generic_usdt_filter_arg+0x32b7> */
	return 12983ULL;
x86_l_2edd:
	/* 0x2edd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ee2:
	/* 0x2ee2: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_2ee9:
	/* 0x2ee9: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2eee:
	/* 0x2eee: jmp    2f27 <generic_usdt_filter_arg+0x2f27> */
	goto x86_l_2f27;
x86_l_2ef0:
	/* 0x2ef0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ef5:
	/* 0x2ef5: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2efa:
	/* 0x2efa: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_2f01:
	/* 0x2f01: jmp    2f27 <generic_usdt_filter_arg+0x2f27> */
	goto x86_l_2f27;
x86_l_2f03:
	/* 0x2f03: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f08:
	/* 0x2f08: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f0d:
	/* 0x2f0d: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2f14:
	/* 0x2f14: jmp    2f27 <generic_usdt_filter_arg+0x2f27> */
	goto x86_l_2f27;
x86_l_2f16:
	/* 0x2f16: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f1b:
	/* 0x2f1b: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f20:
	/* 0x2f20: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_2f27:
	/* 0x2f27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f29:
	/* 0x2f29: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f2c:
	/* 0x2f2c: je     2f47 <generic_usdt_filter_arg+0x2f47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f47;
	}
x86_l_2f2e:
	/* 0x2f2e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2f31:
	/* 0x2f31: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f36:
	/* 0x2f36: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f3b:
	/* 0x2f3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f3d:
	/* 0x2f3d: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f3f:
	/* 0x2f3f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f42:
	/* 0x2f42: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_2f45:
	/* 0x2f45: jmp    2f49 <generic_usdt_filter_arg+0x2f49> */
	goto x86_l_2f49;
x86_l_2f47:
	/* 0x2f47: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f49:
	/* 0x2f49: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f4e:
	/* 0x2f4e: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f53:
	/* 0x2f53: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f58:
	/* 0x2f58: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f5d:
	/* 0x2f5d: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_2f61:
	/* 0x2f61: ja     2bb <generic_usdt_filter_arg+0x2bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 699ULL;
	}
x86_l_2f67:
	/* 0x2f67: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_2f71:
	/* 0x2f71: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2f75:
	/* 0x2f75: jb     323e <generic_usdt_filter_arg+0x323e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_323e;
	}
x86_l_2f7b:
	/* 0x2f7b: jmp    2bb <generic_usdt_filter_arg+0x2bb> */
	return 699ULL;
x86_l_2f80:
	/* 0x2f80: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f82:
	/* 0x2f82: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f87:
	/* 0x2f87: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f8c:
	/* 0x2f8c: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_2f90:
	/* 0x2f90: jbe    2f67 <generic_usdt_filter_arg+0x2f67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2f67;
	}
x86_l_2f92:
	/* 0x2f92: jmp    2bb <generic_usdt_filter_arg+0x2bb> */
	return 699ULL;
x86_l_2f97:
	/* 0x2f97: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f9a:
	/* 0x2f9a: je     31cd <generic_usdt_filter_arg+0x31cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31cd;
	}
x86_l_2fa0:
	/* 0x2fa0: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2fa3:
	/* 0x2fa3: jne    3205 <generic_usdt_filter_arg+0x3205> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3205;
	}
x86_l_2fa9:
	/* 0x2fa9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fae:
	/* 0x2fae: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_2fb5:
	/* 0x2fb5: jmp    31e7 <generic_usdt_filter_arg+0x31e7> */
	goto x86_l_31e7;
x86_l_2fba:
	/* 0x2fba: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2fbd:
	/* 0x2fbd: je     31db <generic_usdt_filter_arg+0x31db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31db;
	}
x86_l_2fc3:
	/* 0x2fc3: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2fc6:
	/* 0x2fc6: jne    3205 <generic_usdt_filter_arg+0x3205> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3205;
	}
x86_l_2fcc:
	/* 0x2fcc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fd1:
	/* 0x2fd1: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_2fd8:
	/* 0x2fd8: jmp    31e7 <generic_usdt_filter_arg+0x31e7> */
	goto x86_l_31e7;
x86_l_2fdd:
	/* 0x2fdd: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fe1:
	/* 0x2fe1: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2fe4:
	/* 0x2fe4: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2fe6:
	/* 0x2fe6: jb     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_2fec:
	/* 0x2fec: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_2fef:
	/* 0x2fef: jb     32b7 <generic_usdt_filter_arg+0x32b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12983ULL;
	}
x86_l_2ff5:
	/* 0x2ff5: mov    ecx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2ffa:
	/* 0x2ffa: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ffd:
	/* 0x2ffd: jle    314b <generic_usdt_filter_arg+0x314b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_314b;
	}
x86_l_3003:
	/* 0x3003: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_3006:
	/* 0x3006: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3009:
	/* 0x3009: jb     318c <generic_usdt_filter_arg+0x318c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_318c;
	}
x86_l_300f:
	/* 0x300f: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_3012:
	/* 0x3012: je     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 716ULL;
	}
x86_l_3018:
	/* 0x3018: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_301b:
	/* 0x301b: jne    10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 269ULL;
	}
x86_l_3021:
	/* 0x3021: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3025:
	/* 0x3025: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3028:
	/* 0x3028: jmp    3075 <generic_usdt_filter_arg+0x3075> */
	goto x86_l_3075;
x86_l_302a:
	/* 0x302a: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_302e:
	/* 0x302e: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3031:
	/* 0x3031: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_3033:
	/* 0x3033: jb     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_3039:
	/* 0x3039: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_303c:
	/* 0x303c: jb     32b7 <generic_usdt_filter_arg+0x32b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12983ULL;
	}
x86_l_3042:
	/* 0x3042: mov    ecx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3047:
	/* 0x3047: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_304a:
	/* 0x304a: jle    3166 <generic_usdt_filter_arg+0x3166> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3166;
	}
x86_l_3050:
	/* 0x3050: lea    edx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_3053:
	/* 0x3053: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3056:
	/* 0x3056: jb     3195 <generic_usdt_filter_arg+0x3195> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3195;
	}
x86_l_305c:
	/* 0x305c: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_305f:
	/* 0x305f: je     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 716ULL;
	}
x86_l_3065:
	/* 0x3065: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3068:
	/* 0x3068: jne    10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 269ULL;
	}
x86_l_306e:
	/* 0x306e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3072:
	/* 0x3072: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3075:
	/* 0x3075: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_3077:
	/* 0x3077: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_307d:
	/* 0x307d: jmp    32b7 <generic_usdt_filter_arg+0x32b7> */
	return 12983ULL;
x86_l_3082:
	/* 0x3082: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3086:
	/* 0x3086: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3089:
	/* 0x3089: ja     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_308f:
	/* 0x308f: jmp    309e <generic_usdt_filter_arg+0x309e> */
	goto x86_l_309e;
x86_l_3091:
	/* 0x3091: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3095:
	/* 0x3095: cmp    DWORD PTR [r8],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3098:
	/* 0x3098: jb     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_309e:
	/* 0x309e: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_30a1:
	/* 0x30a1: jb     32b7 <generic_usdt_filter_arg+0x32b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12983ULL;
	}
x86_l_30a7:
	/* 0x30a7: mov    edx,DWORD PTR [r12+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_30ac:
	/* 0x30ac: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_30af:
	/* 0x30af: jle    30dc <generic_usdt_filter_arg+0x30dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_30dc;
	}
x86_l_30b1:
	/* 0x30b1: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_30b4:
	/* 0x30b4: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_30b7:
	/* 0x30b7: jb     3112 <generic_usdt_filter_arg+0x3112> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3112;
	}
x86_l_30b9:
	/* 0x30b9: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_30bc:
	/* 0x30bc: je     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 716ULL;
	}
x86_l_30c2:
	/* 0x30c2: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_30c5:
	/* 0x30c5: jne    10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 269ULL;
	}
x86_l_30cb:
	/* 0x30cb: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30cf:
	/* 0x30cf: test   DWORD PTR [rcx],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30d1:
	/* 0x30d1: jne    2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 716ULL;
	}
x86_l_30d7:
	/* 0x30d7: jmp    32b7 <generic_usdt_filter_arg+0x32b7> */
	return 12983ULL;
x86_l_30dc:
	/* 0x30dc: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30df:
	/* 0x30df: je     3123 <generic_usdt_filter_arg+0x3123> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3123;
	}
x86_l_30e1:
	/* 0x30e1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_30e4:
	/* 0x30e4: jne    10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 269ULL;
	}
x86_l_30ea:
	/* 0x30ea: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_30ed:
	/* 0x30ed: ja     329d <generic_usdt_filter_arg+0x329d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12957ULL;
	}
x86_l_30f3:
	/* 0x30f3: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_30f8:
	/* 0x30f8: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_30fb:
	/* 0x30fb: jae    329d <generic_usdt_filter_arg+0x329d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12957ULL;
	}
x86_l_3101:
	/* 0x3101: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3105:
	/* 0x3105: cmp    DWORD PTR [rcx],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3107:
	/* 0x3107: jl     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 716ULL;
	}
x86_l_310d:
	/* 0x310d: jmp    32b7 <generic_usdt_filter_arg+0x32b7> */
	return 12983ULL;
x86_l_3112:
	/* 0x3112: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3116:
	/* 0x3116: cmp    DWORD PTR [rcx],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3118:
	/* 0x3118: je     31a4 <generic_usdt_filter_arg+0x31a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31a4;
	}
x86_l_311e:
	/* 0x311e: jmp    32b7 <generic_usdt_filter_arg+0x32b7> */
	return 12983ULL;
x86_l_3123:
	/* 0x3123: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_3126:
	/* 0x3126: ja     32ab <generic_usdt_filter_arg+0x32ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12971ULL;
	}
x86_l_312c:
	/* 0x312c: mov    esi,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5122ULL);
x86_l_3131:
	/* 0x3131: bt     esi,ecx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_3134:
	/* 0x3134: jae    32ab <generic_usdt_filter_arg+0x32ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12971ULL;
	}
x86_l_313a:
	/* 0x313a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_313e:
	/* 0x313e: cmp    DWORD PTR [rcx],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3140:
	/* 0x3140: jg     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 716ULL;
	}
x86_l_3146:
	/* 0x3146: jmp    32b7 <generic_usdt_filter_arg+0x32b7> */
	return 12983ULL;
x86_l_314b:
	/* 0x314b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_314e:
	/* 0x314e: je     3268 <generic_usdt_filter_arg+0x3268> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12904ULL;
	}
x86_l_3154:
	/* 0x3154: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3157:
	/* 0x3157: jne    10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 269ULL;
	}
x86_l_315d:
	/* 0x315d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3161:
	/* 0x3161: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3164:
	/* 0x3164: jmp    317f <generic_usdt_filter_arg+0x317f> */
	goto x86_l_317f;
x86_l_3166:
	/* 0x3166: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3169:
	/* 0x3169: je     3271 <generic_usdt_filter_arg+0x3271> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12913ULL;
	}
x86_l_316f:
	/* 0x316f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3172:
	/* 0x3172: jne    10d <generic_usdt_filter_arg+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 269ULL;
	}
x86_l_3178:
	/* 0x3178: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_317c:
	/* 0x317c: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_317f:
	/* 0x317f: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_3181:
	/* 0x3181: ja     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_3187:
	/* 0x3187: jmp    32b7 <generic_usdt_filter_arg+0x32b7> */
	return 12983ULL;
x86_l_318c:
	/* 0x318c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3190:
	/* 0x3190: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3193:
	/* 0x3193: jmp    319c <generic_usdt_filter_arg+0x319c> */
	goto x86_l_319c;
x86_l_3195:
	/* 0x3195: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3199:
	/* 0x3199: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_319c:
	/* 0x319c: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_319e:
	/* 0x319e: jne    32b7 <generic_usdt_filter_arg+0x32b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12983ULL;
	}
x86_l_31a4:
	/* 0x31a4: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31a6:
	/* 0x31a6: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_31a9:
	/* 0x31a9: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_31ac:
	/* 0x31ac: jmp    2bb <generic_usdt_filter_arg+0x2bb> */
	return 699ULL;
x86_l_31b1:
	/* 0x31b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31b6:
	/* 0x31b6: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_31bd:
	/* 0x31bd: jmp    31e7 <generic_usdt_filter_arg+0x31e7> */
	goto x86_l_31e7;
x86_l_31bf:
	/* 0x31bf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31c4:
	/* 0x31c4: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_31cb:
	/* 0x31cb: jmp    31e7 <generic_usdt_filter_arg+0x31e7> */
	goto x86_l_31e7;
x86_l_31cd:
	/* 0x31cd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31d2:
	/* 0x31d2: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_31d9:
	/* 0x31d9: jmp    31e7 <generic_usdt_filter_arg+0x31e7> */
	goto x86_l_31e7;
x86_l_31db:
	/* 0x31db: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31e0:
	/* 0x31e0: mov    rdi,QWORD PTR [rip+0x1ead9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_31e7:
	/* 0x31e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31e9:
	/* 0x31e9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31ec:
	/* 0x31ec: je     3205 <generic_usdt_filter_arg+0x3205> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3205;
	}
x86_l_31ee:
	/* 0x31ee: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_31f1:
	/* 0x31f1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31f6:
	/* 0x31f6: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_31f9:
	/* 0x31f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31fb:
	/* 0x31fb: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31fd:
	/* 0x31fd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3200:
	/* 0x3200: setne  bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_NE);
x86_l_3203:
	/* 0x3203: jmp    3207 <generic_usdt_filter_arg+0x3207> */
	goto x86_l_3207;
x86_l_3205:
	/* 0x3205: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3207:
	/* 0x3207: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_320c:
	/* 0x320c: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3211:
	/* 0x3211: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3216:
	/* 0x3216: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_321b:
	/* 0x321b: cmp    rax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 37ULL);
x86_l_321f:
	/* 0x321f: ja     2b6 <generic_usdt_filter_arg+0x2b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 694ULL;
	}
x86_l_3225:
	/* 0x3225: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_322f:
	/* 0x322f: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3233:
	/* 0x3233: mov    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3238:
	/* 0x3238: jae    2bb <generic_usdt_filter_arg+0x2bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 699ULL;
	}
x86_l_323e:
	/* 0x323e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3240:
	/* 0x3240: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_3243:
	/* 0x3243: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_3246:
	/* 0x3246: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3249:
	/* 0x3249: jmp    2bb <generic_usdt_filter_arg+0x2bb> */
	return 699ULL;
x86_l_324e:
	/* 0x324e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3252:
	/* 0x3252: cmp    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 12885ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_usdt_filter_arg_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12885ULL: goto x86_l_3255;
	case 12891ULL: goto x86_l_325b;
	case 12893ULL: goto x86_l_325d;
	case 12896ULL: goto x86_l_3260;
	case 12902ULL: goto x86_l_3266;
	case 12904ULL: goto x86_l_3268;
	case 12908ULL: goto x86_l_326c;
	case 12911ULL: goto x86_l_326f;
	case 12913ULL: goto x86_l_3271;
	case 12917ULL: goto x86_l_3275;
	case 12920ULL: goto x86_l_3278;
	case 12922ULL: goto x86_l_327a;
	case 12928ULL: goto x86_l_3280;
	case 12930ULL: goto x86_l_3282;
	case 12932ULL: goto x86_l_3284;
	case 12937ULL: goto x86_l_3289;
	case 12942ULL: goto x86_l_328e;
	case 12947ULL: goto x86_l_3293;
	case 12952ULL: goto x86_l_3298;
	case 12957ULL: goto x86_l_329d;
	case 12961ULL: goto x86_l_32a1;
	case 12963ULL: goto x86_l_32a3;
	case 12969ULL: goto x86_l_32a9;
	case 12971ULL: goto x86_l_32ab;
	case 12975ULL: goto x86_l_32af;
	case 12977ULL: goto x86_l_32b1;
	case 12983ULL: goto x86_l_32b7;
	case 12986ULL: goto x86_l_32ba;
	case 12989ULL: goto x86_l_32bd;
	case 12995ULL: goto x86_l_32c3;
	case 13000ULL: goto x86_l_32c8;
	case 13005ULL: goto x86_l_32cd;
	case 13008ULL: goto x86_l_32d0;
	case 13010ULL: goto x86_l_32d2;
	case 13011ULL: goto x86_l_32d3;
	case 13013ULL: goto x86_l_32d5;
	case 13015ULL: goto x86_l_32d7;
	case 13018ULL: goto x86_l_32da;
	case 13021ULL: goto x86_l_32dd;
	case 13024ULL: goto x86_l_32e0;
	case 13026ULL: goto x86_l_32e2;
	case 13029ULL: goto x86_l_32e5;
	case 13033ULL: goto x86_l_32e9;
	case 13036ULL: goto x86_l_32ec;
	case 13038ULL: goto x86_l_32ee;
	case 13043ULL: goto x86_l_32f3;
	case 13046ULL: goto x86_l_32f6;
	case 13048ULL: goto x86_l_32f8;
	case 13053ULL: goto x86_l_32fd;
	case 13057ULL: goto x86_l_3301;
	case 13060ULL: goto x86_l_3304;
	case 13063ULL: goto x86_l_3307;
	case 13067ULL: goto x86_l_330b;
	case 13071ULL: goto x86_l_330f;
	case 13075ULL: goto x86_l_3313;
	case 13078ULL: goto x86_l_3316;
	case 13082ULL: goto x86_l_331a;
	case 13086ULL: goto x86_l_331e;
	case 13090ULL: goto x86_l_3322;
	case 13093ULL: goto x86_l_3325;
	case 13095ULL: goto x86_l_3327;
	case 13099ULL: goto x86_l_332b;
	case 13103ULL: goto x86_l_332f;
	case 13106ULL: goto x86_l_3332;
	case 13108ULL: goto x86_l_3334;
	case 13110ULL: goto x86_l_3336;
	case 13112ULL: goto x86_l_3338;
	case 13113ULL: goto x86_l_3339;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3255:
	/* 0x3255: jb     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_325b:
	/* 0x325b: jmp    32b7 <generic_usdt_filter_arg+0x32b7> */
	goto x86_l_32b7;
x86_l_325d:
	/* 0x325d: cmp    QWORD PTR [rsi],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3260:
	/* 0x3260: ja     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_3266:
	/* 0x3266: jmp    32b7 <generic_usdt_filter_arg+0x32b7> */
	goto x86_l_32b7;
x86_l_3268:
	/* 0x3268: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_326c:
	/* 0x326c: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_326f:
	/* 0x326f: jmp    3278 <generic_usdt_filter_arg+0x3278> */
	goto x86_l_3278;
x86_l_3271:
	/* 0x3271: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3275:
	/* 0x3275: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3278:
	/* 0x3278: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_327a:
	/* 0x327a: jb     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_3280:
	/* 0x3280: jmp    32b7 <generic_usdt_filter_arg+0x32b7> */
	goto x86_l_32b7;
x86_l_3282:
	/* 0x3282: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3284:
	/* 0x3284: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3289:
	/* 0x3289: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_328e:
	/* 0x328e: mov    r11,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3293:
	/* 0x3293: mov    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3298:
	/* 0x3298: jmp    cfb <generic_usdt_filter_arg+0xcfb> */
	return 3323ULL;
x86_l_329d:
	/* 0x329d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32a1:
	/* 0x32a1: cmp    DWORD PTR [rcx],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32a3:
	/* 0x32a3: jb     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 716ULL;
	}
x86_l_32a9:
	/* 0x32a9: jmp    32b7 <generic_usdt_filter_arg+0x32b7> */
	goto x86_l_32b7;
x86_l_32ab:
	/* 0x32ab: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32af:
	/* 0x32af: cmp    DWORD PTR [rcx],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32b1:
	/* 0x32b1: ja     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 716ULL;
	}
x86_l_32b7:
	/* 0x32b7: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_32ba:
	/* 0x32ba: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_32bd:
	/* 0x32bd: je     2cc <generic_usdt_filter_arg+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 716ULL;
	}
x86_l_32c3:
	/* 0x32c3: jmp    10d <generic_usdt_filter_arg+0x10d> */
	return 269ULL;
x86_l_32c8:
	/* 0x32c8: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_32cd:
	/* 0x32cd: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_32d0:
	/* 0x32d0: je     3339 <native_bpf_strncasestr+0x71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3339;
	}
x86_l_32d2:
	/* 0x32d2: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_32d3:
	/* 0x32d3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32d5:
	/* 0x32d5: jmp    32e2 <native_bpf_strncasestr+0x1a> */
	goto x86_l_32e2;
x86_l_32d7:
	/* 0x32d7: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_32da:
	/* 0x32da: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_32dd:
	/* 0x32dd: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_32e0:
	/* 0x32e0: je     3338 <native_bpf_strncasestr+0x70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3338;
	}
x86_l_32e2:
	/* 0x32e2: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32e5:
	/* 0x32e5: lea    r9,[rcx+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_32e9:
	/* 0x32e9: cmp    r9,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RDX, X86_WIDTH_64);
x86_l_32ec:
	/* 0x32ec: jae    32d7 <native_bpf_strncasestr+0xf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_32d7;
	}
x86_l_32ee:
	/* 0x32ee: movsx  r9d,BYTE PTR [rsi+r8*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 0ULL);
x86_l_32f3:
	/* 0x32f3: test   r9d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_32);
x86_l_32f6:
	/* 0x32f6: je     3336 <native_bpf_strncasestr+0x6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3336;
	}
x86_l_32f8:
	/* 0x32f8: movsx  r10d,BYTE PTR [rdi+r8*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 0, X86_WIDTH_8), 0ULL);
x86_l_32fd:
	/* 0x32fd: lea    r11d,[r10-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_3301:
	/* 0x3301: mov    ebx,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R10, X86_WIDTH_32);
x86_l_3304:
	/* 0x3304: or     ebx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_3307:
	/* 0x3307: cmp    r11d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 26ULL);
x86_l_330b:
	/* 0x330b: cmovae ebx,r10d */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_R10, X86_WIDTH_32, X86_CC_AE);
x86_l_330f:
	/* 0x330f: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_3313:
	/* 0x3313: mov    r11d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R9, X86_WIDTH_32);
x86_l_3316:
	/* 0x3316: or     r11d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_331a:
	/* 0x331a: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_331e:
	/* 0x331e: cmovae r11d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R11, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_3322:
	/* 0x3322: cmp    ebx,r11d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_R11, X86_WIDTH_32);
x86_l_3325:
	/* 0x3325: jne    32d7 <native_bpf_strncasestr+0xf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_32d7;
	}
x86_l_3327:
	/* 0x3327: lea    r9,[r8+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_332b:
	/* 0x332b: cmp    r8,0x63 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 99ULL);
x86_l_332f:
	/* 0x332f: mov    r8,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_64);
x86_l_3332:
	/* 0x3332: jb     32e5 <native_bpf_strncasestr+0x1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_32e5;
	}
x86_l_3334:
	/* 0x3334: jmp    32d7 <native_bpf_strncasestr+0xf> */
	goto x86_l_32d7;
x86_l_3336:
	/* 0x3336: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_3338:
	/* 0x3338: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3339:
	/* 0x3339: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_usdt_v53_generic_usdt_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 12560U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1714ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_usdt_filter_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1719ULL && __x86_pc <= 3318ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_usdt_filter_arg_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3323ULL && __x86_pc <= 4934ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_usdt_filter_arg_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4937ULL && __x86_pc <= 6508ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_usdt_filter_arg_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6510ULL && __x86_pc <= 8086ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_usdt_filter_arg_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8090ULL && __x86_pc <= 9653ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_usdt_filter_arg_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 9658ULL && __x86_pc <= 11290ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_usdt_filter_arg_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 11296ULL && __x86_pc <= 12882ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_usdt_filter_arg_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 12885ULL && __x86_pc <= 13113ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_usdt_filter_arg_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

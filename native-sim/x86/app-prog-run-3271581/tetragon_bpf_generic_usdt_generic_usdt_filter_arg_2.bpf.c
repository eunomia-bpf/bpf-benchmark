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
	case 66ULL: goto x86_l_42;
	case 73ULL: goto x86_l_49;
	case 80ULL: goto x86_l_50;
	case 85ULL: goto x86_l_55;
	case 87ULL: goto x86_l_57;
	case 90ULL: goto x86_l_5a;
	case 96ULL: goto x86_l_60;
	case 104ULL: goto x86_l_68;
	case 110ULL: goto x86_l_6e;
	case 113ULL: goto x86_l_71;
	case 116ULL: goto x86_l_74;
	case 125ULL: goto x86_l_7d;
	case 131ULL: goto x86_l_83;
	case 133ULL: goto x86_l_85;
	case 137ULL: goto x86_l_89;
	case 141ULL: goto x86_l_8d;
	case 145ULL: goto x86_l_91;
	case 149ULL: goto x86_l_95;
	case 153ULL: goto x86_l_99;
	case 159ULL: goto x86_l_9f;
	case 162ULL: goto x86_l_a2;
	case 165ULL: goto x86_l_a5;
	case 169ULL: goto x86_l_a9;
	case 171ULL: goto x86_l_ab;
	case 177ULL: goto x86_l_b1;
	case 180ULL: goto x86_l_b4;
	case 183ULL: goto x86_l_b7;
	case 185ULL: goto x86_l_b9;
	case 191ULL: goto x86_l_bf;
	case 194ULL: goto x86_l_c2;
	case 197ULL: goto x86_l_c5;
	case 199ULL: goto x86_l_c7;
	case 205ULL: goto x86_l_cd;
	case 208ULL: goto x86_l_d0;
	case 211ULL: goto x86_l_d3;
	case 213ULL: goto x86_l_d5;
	case 219ULL: goto x86_l_db;
	case 222ULL: goto x86_l_de;
	case 225ULL: goto x86_l_e1;
	case 227ULL: goto x86_l_e3;
	case 233ULL: goto x86_l_e9;
	case 237ULL: goto x86_l_ed;
	case 243ULL: goto x86_l_f3;
	case 247ULL: goto x86_l_f7;
	case 253ULL: goto x86_l_fd;
	case 259ULL: goto x86_l_103;
	case 261ULL: goto x86_l_105;
	case 267ULL: goto x86_l_10b;
	case 270ULL: goto x86_l_10e;
	case 274ULL: goto x86_l_112;
	case 280ULL: goto x86_l_118;
	case 289ULL: goto x86_l_121;
	case 295ULL: goto x86_l_127;
	case 298ULL: goto x86_l_12a;
	case 301ULL: goto x86_l_12d;
	case 305ULL: goto x86_l_131;
	case 313ULL: goto x86_l_139;
	case 318ULL: goto x86_l_13e;
	case 322ULL: goto x86_l_142;
	case 329ULL: goto x86_l_149;
	case 332ULL: goto x86_l_14c;
	case 334ULL: goto x86_l_14e;
	case 337ULL: goto x86_l_151;
	case 343ULL: goto x86_l_157;
	case 346ULL: goto x86_l_15a;
	case 352ULL: goto x86_l_160;
	case 355ULL: goto x86_l_163;
	case 361ULL: goto x86_l_169;
	case 364ULL: goto x86_l_16c;
	case 366ULL: goto x86_l_16e;
	case 371ULL: goto x86_l_173;
	case 374ULL: goto x86_l_176;
	case 380ULL: goto x86_l_17c;
	case 383ULL: goto x86_l_17f;
	case 386ULL: goto x86_l_182;
	case 392ULL: goto x86_l_188;
	case 395ULL: goto x86_l_18b;
	case 398ULL: goto x86_l_18e;
	case 401ULL: goto x86_l_191;
	case 407ULL: goto x86_l_197;
	case 410ULL: goto x86_l_19a;
	case 414ULL: goto x86_l_19e;
	case 419ULL: goto x86_l_1a3;
	case 422ULL: goto x86_l_1a6;
	case 428ULL: goto x86_l_1ac;
	case 433ULL: goto x86_l_1b1;
	case 436ULL: goto x86_l_1b4;
	case 442ULL: goto x86_l_1ba;
	case 447ULL: goto x86_l_1bf;
	case 450ULL: goto x86_l_1c2;
	case 456ULL: goto x86_l_1c8;
	case 461ULL: goto x86_l_1cd;
	case 465ULL: goto x86_l_1d1;
	case 468ULL: goto x86_l_1d4;
	case 472ULL: goto x86_l_1d8;
	case 480ULL: goto x86_l_1e0;
	case 487ULL: goto x86_l_1e7;
	case 492ULL: goto x86_l_1ec;
	case 497ULL: goto x86_l_1f1;
	case 499ULL: goto x86_l_1f3;
	case 502ULL: goto x86_l_1f6;
	case 505ULL: goto x86_l_1f9;
	case 508ULL: goto x86_l_1fc;
	case 514ULL: goto x86_l_202;
	case 517ULL: goto x86_l_205;
	case 523ULL: goto x86_l_20b;
	case 526ULL: goto x86_l_20e;
	case 533ULL: goto x86_l_215;
	case 538ULL: goto x86_l_21a;
	case 543ULL: goto x86_l_21f;
	case 545ULL: goto x86_l_221;
	case 548ULL: goto x86_l_224;
	case 554ULL: goto x86_l_22a;
	case 557ULL: goto x86_l_22d;
	case 561ULL: goto x86_l_231;
	case 566ULL: goto x86_l_236;
	case 570ULL: goto x86_l_23a;
	case 573ULL: goto x86_l_23d;
	case 575ULL: goto x86_l_23f;
	case 579ULL: goto x86_l_243;
	case 584ULL: goto x86_l_248;
	case 589ULL: goto x86_l_24d;
	case 593ULL: goto x86_l_251;
	case 596ULL: goto x86_l_254;
	case 600ULL: goto x86_l_258;
	case 606ULL: goto x86_l_25e;
	case 613ULL: goto x86_l_265;
	case 618ULL: goto x86_l_26a;
	case 622ULL: goto x86_l_26e;
	case 625ULL: goto x86_l_271;
	case 629ULL: goto x86_l_275;
	case 635ULL: goto x86_l_27b;
	case 642ULL: goto x86_l_282;
	case 647ULL: goto x86_l_287;
	case 651ULL: goto x86_l_28b;
	case 654ULL: goto x86_l_28e;
	case 658ULL: goto x86_l_292;
	case 664ULL: goto x86_l_298;
	case 671ULL: goto x86_l_29f;
	case 676ULL: goto x86_l_2a4;
	case 680ULL: goto x86_l_2a8;
	case 683ULL: goto x86_l_2ab;
	case 687ULL: goto x86_l_2af;
	case 693ULL: goto x86_l_2b5;
	case 700ULL: goto x86_l_2bc;
	case 705ULL: goto x86_l_2c1;
	case 709ULL: goto x86_l_2c5;
	case 712ULL: goto x86_l_2c8;
	case 716ULL: goto x86_l_2cc;
	case 722ULL: goto x86_l_2d2;
	case 729ULL: goto x86_l_2d9;
	case 734ULL: goto x86_l_2de;
	case 738ULL: goto x86_l_2e2;
	case 741ULL: goto x86_l_2e5;
	case 745ULL: goto x86_l_2e9;
	case 751ULL: goto x86_l_2ef;
	case 758ULL: goto x86_l_2f6;
	case 763ULL: goto x86_l_2fb;
	case 767ULL: goto x86_l_2ff;
	case 770ULL: goto x86_l_302;
	case 774ULL: goto x86_l_306;
	case 780ULL: goto x86_l_30c;
	case 787ULL: goto x86_l_313;
	case 792ULL: goto x86_l_318;
	case 796ULL: goto x86_l_31c;
	case 799ULL: goto x86_l_31f;
	case 803ULL: goto x86_l_323;
	case 809ULL: goto x86_l_329;
	case 816ULL: goto x86_l_330;
	case 821ULL: goto x86_l_335;
	case 825ULL: goto x86_l_339;
	case 828ULL: goto x86_l_33c;
	case 832ULL: goto x86_l_340;
	case 838ULL: goto x86_l_346;
	case 845ULL: goto x86_l_34d;
	case 850ULL: goto x86_l_352;
	case 854ULL: goto x86_l_356;
	case 857ULL: goto x86_l_359;
	case 861ULL: goto x86_l_35d;
	case 867ULL: goto x86_l_363;
	case 874ULL: goto x86_l_36a;
	case 879ULL: goto x86_l_36f;
	case 883ULL: goto x86_l_373;
	case 886ULL: goto x86_l_376;
	case 890ULL: goto x86_l_37a;
	case 896ULL: goto x86_l_380;
	case 903ULL: goto x86_l_387;
	case 908ULL: goto x86_l_38c;
	case 912ULL: goto x86_l_390;
	case 915ULL: goto x86_l_393;
	case 919ULL: goto x86_l_397;
	case 925ULL: goto x86_l_39d;
	case 932ULL: goto x86_l_3a4;
	case 937ULL: goto x86_l_3a9;
	case 941ULL: goto x86_l_3ad;
	case 944ULL: goto x86_l_3b0;
	case 948ULL: goto x86_l_3b4;
	case 954ULL: goto x86_l_3ba;
	case 961ULL: goto x86_l_3c1;
	case 966ULL: goto x86_l_3c6;
	case 970ULL: goto x86_l_3ca;
	case 973ULL: goto x86_l_3cd;
	case 977ULL: goto x86_l_3d1;
	case 983ULL: goto x86_l_3d7;
	case 990ULL: goto x86_l_3de;
	case 995ULL: goto x86_l_3e3;
	case 999ULL: goto x86_l_3e7;
	case 1002ULL: goto x86_l_3ea;
	case 1006ULL: goto x86_l_3ee;
	case 1012ULL: goto x86_l_3f4;
	case 1019ULL: goto x86_l_3fb;
	case 1024ULL: goto x86_l_400;
	case 1028ULL: goto x86_l_404;
	case 1031ULL: goto x86_l_407;
	case 1035ULL: goto x86_l_40b;
	case 1041ULL: goto x86_l_411;
	case 1048ULL: goto x86_l_418;
	case 1053ULL: goto x86_l_41d;
	case 1057ULL: goto x86_l_421;
	case 1060ULL: goto x86_l_424;
	case 1064ULL: goto x86_l_428;
	case 1070ULL: goto x86_l_42e;
	case 1077ULL: goto x86_l_435;
	case 1082ULL: goto x86_l_43a;
	case 1086ULL: goto x86_l_43e;
	case 1089ULL: goto x86_l_441;
	case 1093ULL: goto x86_l_445;
	case 1099ULL: goto x86_l_44b;
	case 1106ULL: goto x86_l_452;
	case 1111ULL: goto x86_l_457;
	case 1115ULL: goto x86_l_45b;
	case 1118ULL: goto x86_l_45e;
	case 1122ULL: goto x86_l_462;
	case 1128ULL: goto x86_l_468;
	case 1135ULL: goto x86_l_46f;
	case 1140ULL: goto x86_l_474;
	case 1144ULL: goto x86_l_478;
	case 1147ULL: goto x86_l_47b;
	case 1151ULL: goto x86_l_47f;
	case 1157ULL: goto x86_l_485;
	case 1164ULL: goto x86_l_48c;
	case 1169ULL: goto x86_l_491;
	case 1173ULL: goto x86_l_495;
	case 1176ULL: goto x86_l_498;
	case 1180ULL: goto x86_l_49c;
	case 1186ULL: goto x86_l_4a2;
	case 1193ULL: goto x86_l_4a9;
	case 1198ULL: goto x86_l_4ae;
	case 1202ULL: goto x86_l_4b2;
	case 1205ULL: goto x86_l_4b5;
	case 1209ULL: goto x86_l_4b9;
	case 1215ULL: goto x86_l_4bf;
	case 1222ULL: goto x86_l_4c6;
	case 1227ULL: goto x86_l_4cb;
	case 1231ULL: goto x86_l_4cf;
	case 1234ULL: goto x86_l_4d2;
	case 1238ULL: goto x86_l_4d6;
	case 1244ULL: goto x86_l_4dc;
	case 1251ULL: goto x86_l_4e3;
	case 1256ULL: goto x86_l_4e8;
	case 1260ULL: goto x86_l_4ec;
	case 1263ULL: goto x86_l_4ef;
	case 1267ULL: goto x86_l_4f3;
	case 1273ULL: goto x86_l_4f9;
	case 1280ULL: goto x86_l_500;
	case 1285ULL: goto x86_l_505;
	case 1289ULL: goto x86_l_509;
	case 1292ULL: goto x86_l_50c;
	case 1296ULL: goto x86_l_510;
	case 1302ULL: goto x86_l_516;
	case 1309ULL: goto x86_l_51d;
	case 1314ULL: goto x86_l_522;
	case 1318ULL: goto x86_l_526;
	case 1321ULL: goto x86_l_529;
	case 1325ULL: goto x86_l_52d;
	case 1331ULL: goto x86_l_533;
	case 1338ULL: goto x86_l_53a;
	case 1343ULL: goto x86_l_53f;
	case 1347ULL: goto x86_l_543;
	case 1350ULL: goto x86_l_546;
	case 1354ULL: goto x86_l_54a;
	case 1360ULL: goto x86_l_550;
	case 1367ULL: goto x86_l_557;
	case 1372ULL: goto x86_l_55c;
	case 1376ULL: goto x86_l_560;
	case 1379ULL: goto x86_l_563;
	case 1383ULL: goto x86_l_567;
	case 1389ULL: goto x86_l_56d;
	case 1396ULL: goto x86_l_574;
	case 1401ULL: goto x86_l_579;
	case 1405ULL: goto x86_l_57d;
	case 1408ULL: goto x86_l_580;
	case 1412ULL: goto x86_l_584;
	case 1418ULL: goto x86_l_58a;
	case 1425ULL: goto x86_l_591;
	case 1430ULL: goto x86_l_596;
	case 1434ULL: goto x86_l_59a;
	case 1437ULL: goto x86_l_59d;
	case 1441ULL: goto x86_l_5a1;
	case 1447ULL: goto x86_l_5a7;
	case 1454ULL: goto x86_l_5ae;
	case 1459ULL: goto x86_l_5b3;
	case 1463ULL: goto x86_l_5b7;
	case 1466ULL: goto x86_l_5ba;
	case 1470ULL: goto x86_l_5be;
	case 1476ULL: goto x86_l_5c4;
	case 1483ULL: goto x86_l_5cb;
	case 1488ULL: goto x86_l_5d0;
	case 1492ULL: goto x86_l_5d4;
	case 1495ULL: goto x86_l_5d7;
	case 1499ULL: goto x86_l_5db;
	case 1505ULL: goto x86_l_5e1;
	case 1512ULL: goto x86_l_5e8;
	case 1517ULL: goto x86_l_5ed;
	case 1521ULL: goto x86_l_5f1;
	case 1524ULL: goto x86_l_5f4;
	case 1528ULL: goto x86_l_5f8;
	case 1534ULL: goto x86_l_5fe;
	case 1541ULL: goto x86_l_605;
	case 1546ULL: goto x86_l_60a;
	case 1550ULL: goto x86_l_60e;
	case 1553ULL: goto x86_l_611;
	case 1557ULL: goto x86_l_615;
	case 1563ULL: goto x86_l_61b;
	case 1570ULL: goto x86_l_622;
	case 1575ULL: goto x86_l_627;
	case 1579ULL: goto x86_l_62b;
	case 1582ULL: goto x86_l_62e;
	case 1586ULL: goto x86_l_632;
	case 1592ULL: goto x86_l_638;
	case 1599ULL: goto x86_l_63f;
	case 1604ULL: goto x86_l_644;
	case 1608ULL: goto x86_l_648;
	case 1611ULL: goto x86_l_64b;
	case 1615ULL: goto x86_l_64f;
	case 1621ULL: goto x86_l_655;
	case 1628ULL: goto x86_l_65c;
	case 1633ULL: goto x86_l_661;
	case 1637ULL: goto x86_l_665;
	case 1640ULL: goto x86_l_668;
	case 1644ULL: goto x86_l_66c;
	case 1650ULL: goto x86_l_672;
	case 1657ULL: goto x86_l_679;
	case 1662ULL: goto x86_l_67e;
	case 1666ULL: goto x86_l_682;
	case 1669ULL: goto x86_l_685;
	case 1673ULL: goto x86_l_689;
	case 1679ULL: goto x86_l_68f;
	case 1686ULL: goto x86_l_696;
	case 1691ULL: goto x86_l_69b;
	case 1695ULL: goto x86_l_69f;
	case 1698ULL: goto x86_l_6a2;
	case 1702ULL: goto x86_l_6a6;
	case 1708ULL: goto x86_l_6ac;
	case 1715ULL: goto x86_l_6b3;
	case 1720ULL: goto x86_l_6b8;
	case 1724ULL: goto x86_l_6bc;
	case 1727ULL: goto x86_l_6bf;
	case 1731ULL: goto x86_l_6c3;
	case 1737ULL: goto x86_l_6c9;
	case 1744ULL: goto x86_l_6d0;
	case 1749ULL: goto x86_l_6d5;
	case 1753ULL: goto x86_l_6d9;
	case 1756ULL: goto x86_l_6dc;
	case 1760ULL: goto x86_l_6e0;
	case 1766ULL: goto x86_l_6e6;
	case 1773ULL: goto x86_l_6ed;
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
	/* 0xa: sub    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 136ULL);
x86_l_11:
	/* 0x11: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    DWORD PTR [rsp+0x7c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_1c:
	/* 0x1c: mov    rdi,QWORD PTR [rip+0xbe70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_23:
	/* 0x23: lea    rsi,[rsp+0x7c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
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
	/* 0x32: je     32c3 <generic_usdt_filter_arg_2+0x32c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12995ULL;
	}
x86_l_38:
	/* 0x38: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3b:
	/* 0x3b: mov    r15d,DWORD PTR [rax+0x5ef0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_42:
	/* 0x42: lea    rsi,[rax+0x5ee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24296ULL);
x86_l_49:
	/* 0x49: mov    rdi,QWORD PTR [rip+0xbe70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_50:
	/* 0x50: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_55:
	/* 0x55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57:
	/* 0x57: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5a:
	/* 0x5a: je     32a8 <generic_usdt_filter_arg_2+0x32a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12968ULL;
	}
x86_l_60:
	/* 0x60: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_68:
	/* 0x68: je     32a8 <generic_usdt_filter_arg_2+0x32a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12968ULL;
	}
x86_l_6e:
	/* 0x6e: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_71:
	/* 0x71: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_74:
	/* 0x74: cmp    BYTE PTR [r14+rcx*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 104183021699072ULL);
x86_l_7d:
	/* 0x7d: je     3231 <generic_usdt_filter_arg_2+0x3231> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12849ULL;
	}
x86_l_83:
	/* 0x83: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_85:
	/* 0x85: mov    edx,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_89:
	/* 0x89: lea    rsi,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_8d:
	/* 0x8d: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_91:
	/* 0x91: lea    rcx,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_95:
	/* 0x95: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_99:
	/* 0x99: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_9f:
	/* 0x9f: mov    ecx,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_a2:
	/* 0xa2: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a5:
	/* 0xa5: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a9:
	/* 0xa9: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_ab:
	/* 0xab: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_b1:
	/* 0xb1: mov    edx,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_b4:
	/* 0xb4: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b7:
	/* 0xb7: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_b9:
	/* 0xb9: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_bf:
	/* 0xbf: mov    ecx,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_c2:
	/* 0xc2: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c5:
	/* 0xc5: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_c7:
	/* 0xc7: and    edx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_cd:
	/* 0xcd: mov    edx,DWORD PTR [rdx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_d0:
	/* 0xd0: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d3:
	/* 0xd3: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_d5:
	/* 0xd5: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_db:
	/* 0xdb: mov    ecx,DWORD PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_de:
	/* 0xde: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e1:
	/* 0xe1: mov    ebp,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_32);
x86_l_e3:
	/* 0xe3: and    ebp,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_e9:
	/* 0xe9: cmp    DWORD PTR [rax+rbp*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 25ULL);
x86_l_ed:
	/* 0xed: jb     3227 <generic_usdt_filter_arg_2+0x3227> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12839ULL;
	}
x86_l_f3:
	/* 0xf3: mov    edx,DWORD PTR [rax+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 4ULL);
x86_l_f7:
	/* 0xf7: test   edx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 1023ULL);
x86_l_fd:
	/* 0xfd: je     3227 <generic_usdt_filter_arg_2+0x3227> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12839ULL;
	}
x86_l_103:
	/* 0x103: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_105:
	/* 0x105: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_10b:
	/* 0x10b: mov    edx,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_10e:
	/* 0x10e: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_112:
	/* 0x112: ja     3231 <generic_usdt_filter_arg_2+0x3231> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12849ULL;
	}
x86_l_118:
	/* 0x118: cmp    DWORD PTR [r14+rdx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104041287778304ULL);
x86_l_121:
	/* 0x121: jne    3231 <generic_usdt_filter_arg_2+0x3231> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12849ULL;
	}
x86_l_127:
	/* 0x127: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_12a:
	/* 0x12a: add    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_12d:
	/* 0x12d: mov    ecx,DWORD PTR [rax+rcx*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 12ULL);
x86_l_131:
	/* 0x131: mov    rax,QWORD PTR [r14+rdx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_139:
	/* 0x139: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_13e:
	/* 0x13e: lea    r8,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_142:
	/* 0x142: add    r8,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_149:
	/* 0x149: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_14c:
	/* 0x14c: jg     173 <generic_usdt_filter_arg_2+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_173;
	}
x86_l_14e:
	/* 0x14e: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_151:
	/* 0x151: jg     cd9 <generic_usdt_filter_arg_2+0xcd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3289ULL;
	}
x86_l_157:
	/* 0x157: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_15a:
	/* 0x15a: je     e98 <generic_usdt_filter_arg_2+0xe98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3736ULL;
	}
x86_l_160:
	/* 0x160: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_163:
	/* 0x163: je     cf7 <generic_usdt_filter_arg_2+0xcf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3319ULL;
	}
x86_l_169:
	/* 0x169: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_16c:
	/* 0x16c: je     188 <generic_usdt_filter_arg_2+0x188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_188;
	}
x86_l_16e:
	/* 0x16e: jmp    3227 <generic_usdt_filter_arg_2+0x3227> */
	return 12839ULL;
x86_l_173:
	/* 0x173: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_176:
	/* 0x176: jg     cef <generic_usdt_filter_arg_2+0xcef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3311ULL;
	}
x86_l_17c:
	/* 0x17c: lea    eax,[rcx-0x26] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_17f:
	/* 0x17f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_182:
	/* 0x182: jae    d60 <generic_usdt_filter_arg_2+0xd60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3424ULL;
	}
x86_l_188:
	/* 0x188: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18b:
	/* 0x18b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18e:
	/* 0x18e: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_191:
	/* 0x191: ja     3207 <generic_usdt_filter_arg_2+0x3207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12807ULL;
	}
x86_l_197:
	/* 0x197: mov    r13d,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19a:
	/* 0x19a: add    r8,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_19e:
	/* 0x19e: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_1a3:
	/* 0x1a3: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1a6:
	/* 0x1a6: jb     1af4 <generic_usdt_filter_arg_2+0x1af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6900ULL;
	}
x86_l_1ac:
	/* 0x1ac: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_1b1:
	/* 0x1b1: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1b4:
	/* 0x1b4: jb     1a4f <generic_usdt_filter_arg_2+0x1a4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6735ULL;
	}
x86_l_1ba:
	/* 0x1ba: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_1bf:
	/* 0x1bf: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1c2:
	/* 0x1c2: jae    3207 <generic_usdt_filter_arg_2+0x3207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12807ULL;
	}
x86_l_1c8:
	/* 0x1c8: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cd:
	/* 0x1cd: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d1:
	/* 0x1d1: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d4:
	/* 0x1d4: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d8:
	/* 0x1d8: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1e0:
	/* 0x1e0: mov    rdi,QWORD PTR [rip+0xbe70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_1e7:
	/* 0x1e7: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ec:
	/* 0x1ec: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f1:
	/* 0x1f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f3:
	/* 0x1f3: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1f6:
	/* 0x1f6: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f9:
	/* 0x1f9: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1fc:
	/* 0x1fc: je     3200 <generic_usdt_filter_arg_2+0x3200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12800ULL;
	}
x86_l_202:
	/* 0x202: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_205:
	/* 0x205: je     3200 <generic_usdt_filter_arg_2+0x3200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12800ULL;
	}
x86_l_20b:
	/* 0x20b: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_20e:
	/* 0x20e: mov    rdi,QWORD PTR [rip+0xbe70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_215:
	/* 0x215: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21a:
	/* 0x21a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21f:
	/* 0x21f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_221:
	/* 0x221: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_224:
	/* 0x224: je     31fd <generic_usdt_filter_arg_2+0x31fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12797ULL;
	}
x86_l_22a:
	/* 0x22a: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_22d:
	/* 0x22d: cmp    r13d,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 94ULL);
x86_l_231:
	/* 0x231: mov    eax,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 94ULL);
x86_l_236:
	/* 0x236: cmovb  eax,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_23a:
	/* 0x23a: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_23d:
	/* 0x23d: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23f:
	/* 0x23f: lea    eax,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_243:
	/* 0x243: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_248:
	/* 0x248: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24d:
	/* 0x24d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_251:
	/* 0x251: mov    BYTE PTR [rsi+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_254:
	/* 0x254: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_258:
	/* 0x258: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_25e:
	/* 0x25e: lea    eax,[r13+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_265:
	/* 0x265: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26a:
	/* 0x26a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_26e:
	/* 0x26e: mov    BYTE PTR [rsi+0x5],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_271:
	/* 0x271: cmp    r13,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 2ULL);
x86_l_275:
	/* 0x275: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_27b:
	/* 0x27b: lea    eax,[r13+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_282:
	/* 0x282: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_287:
	/* 0x287: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_28b:
	/* 0x28b: mov    BYTE PTR [rsi+0x6],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_28e:
	/* 0x28e: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_292:
	/* 0x292: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_298:
	/* 0x298: lea    eax,[r13+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_29f:
	/* 0x29f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a4:
	/* 0x2a4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a8:
	/* 0x2a8: mov    BYTE PTR [rsi+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_2ab:
	/* 0x2ab: cmp    r13,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4ULL);
x86_l_2af:
	/* 0x2af: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_2b5:
	/* 0x2b5: lea    eax,[r13+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_2bc:
	/* 0x2bc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c1:
	/* 0x2c1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2c5:
	/* 0x2c5: mov    BYTE PTR [rsi+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c8:
	/* 0x2c8: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_2cc:
	/* 0x2cc: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_2d2:
	/* 0x2d2: lea    eax,[r13+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_2d9:
	/* 0x2d9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2de:
	/* 0x2de: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2e2:
	/* 0x2e2: mov    BYTE PTR [rsi+0x9],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_2e5:
	/* 0x2e5: cmp    r13,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 6ULL);
x86_l_2e9:
	/* 0x2e9: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_2ef:
	/* 0x2ef: lea    eax,[r13+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_2f6:
	/* 0x2f6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2fb:
	/* 0x2fb: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2ff:
	/* 0x2ff: mov    BYTE PTR [rsi+0xa],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_302:
	/* 0x302: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_306:
	/* 0x306: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_30c:
	/* 0x30c: lea    eax,[r13+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_313:
	/* 0x313: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_318:
	/* 0x318: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_31c:
	/* 0x31c: mov    BYTE PTR [rsi+0xb],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_31f:
	/* 0x31f: cmp    r13,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 8ULL);
x86_l_323:
	/* 0x323: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_329:
	/* 0x329: lea    eax,[r13+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_330:
	/* 0x330: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_335:
	/* 0x335: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_339:
	/* 0x339: mov    BYTE PTR [rsi+0xc],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_33c:
	/* 0x33c: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_340:
	/* 0x340: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_346:
	/* 0x346: lea    eax,[r13+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_34d:
	/* 0x34d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_352:
	/* 0x352: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_356:
	/* 0x356: mov    BYTE PTR [rsi+0xd],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_359:
	/* 0x359: cmp    r13,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 10ULL);
x86_l_35d:
	/* 0x35d: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_363:
	/* 0x363: lea    eax,[r13+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_36a:
	/* 0x36a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_36f:
	/* 0x36f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_373:
	/* 0x373: mov    BYTE PTR [rsi+0xe],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_376:
	/* 0x376: cmp    r13,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 11ULL);
x86_l_37a:
	/* 0x37a: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_380:
	/* 0x380: lea    eax,[r13+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_387:
	/* 0x387: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_38c:
	/* 0x38c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_390:
	/* 0x390: mov    BYTE PTR [rsi+0xf],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_393:
	/* 0x393: cmp    r13,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 12ULL);
x86_l_397:
	/* 0x397: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_39d:
	/* 0x39d: lea    eax,[r13+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_3a4:
	/* 0x3a4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3a9:
	/* 0x3a9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3ad:
	/* 0x3ad: mov    BYTE PTR [rsi+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b0:
	/* 0x3b0: cmp    r13,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 13ULL);
x86_l_3b4:
	/* 0x3b4: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_3ba:
	/* 0x3ba: lea    eax,[r13+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_3c1:
	/* 0x3c1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3c6:
	/* 0x3c6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3ca:
	/* 0x3ca: mov    BYTE PTR [rsi+0x11],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_3cd:
	/* 0x3cd: cmp    r13,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 14ULL);
x86_l_3d1:
	/* 0x3d1: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_3d7:
	/* 0x3d7: lea    eax,[r13+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_3de:
	/* 0x3de: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3e3:
	/* 0x3e3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3e7:
	/* 0x3e7: mov    BYTE PTR [rsi+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_3ea:
	/* 0x3ea: cmp    r13,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 15ULL);
x86_l_3ee:
	/* 0x3ee: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_3f4:
	/* 0x3f4: lea    eax,[r13+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_3fb:
	/* 0x3fb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_400:
	/* 0x400: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_404:
	/* 0x404: mov    BYTE PTR [rsi+0x13],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_407:
	/* 0x407: cmp    r13,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 16ULL);
x86_l_40b:
	/* 0x40b: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_411:
	/* 0x411: lea    eax,[r13+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_418:
	/* 0x418: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_41d:
	/* 0x41d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_421:
	/* 0x421: mov    BYTE PTR [rsi+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_424:
	/* 0x424: cmp    r13,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 17ULL);
x86_l_428:
	/* 0x428: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_42e:
	/* 0x42e: lea    eax,[r13+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_435:
	/* 0x435: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_43a:
	/* 0x43a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_43e:
	/* 0x43e: mov    BYTE PTR [rsi+0x15],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_441:
	/* 0x441: cmp    r13,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18ULL);
x86_l_445:
	/* 0x445: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_44b:
	/* 0x44b: lea    eax,[r13+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_452:
	/* 0x452: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_457:
	/* 0x457: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_45b:
	/* 0x45b: mov    BYTE PTR [rsi+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_45e:
	/* 0x45e: cmp    r13,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 19ULL);
x86_l_462:
	/* 0x462: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_468:
	/* 0x468: lea    eax,[r13+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_46f:
	/* 0x46f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_474:
	/* 0x474: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_478:
	/* 0x478: mov    BYTE PTR [rsi+0x17],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_47b:
	/* 0x47b: cmp    r13,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 20ULL);
x86_l_47f:
	/* 0x47f: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_485:
	/* 0x485: lea    eax,[r13+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_48c:
	/* 0x48c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_491:
	/* 0x491: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_495:
	/* 0x495: mov    BYTE PTR [rsi+0x18],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_498:
	/* 0x498: cmp    r13,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 21ULL);
x86_l_49c:
	/* 0x49c: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_4a2:
	/* 0x4a2: lea    eax,[r13+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_4a9:
	/* 0x4a9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4ae:
	/* 0x4ae: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4b2:
	/* 0x4b2: mov    BYTE PTR [rsi+0x19],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_4b5:
	/* 0x4b5: cmp    r13,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 22ULL);
x86_l_4b9:
	/* 0x4b9: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_4bf:
	/* 0x4bf: lea    eax,[r13+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_4c6:
	/* 0x4c6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4cb:
	/* 0x4cb: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4cf:
	/* 0x4cf: mov    BYTE PTR [rsi+0x1a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_4d2:
	/* 0x4d2: cmp    r13,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 23ULL);
x86_l_4d6:
	/* 0x4d6: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_4dc:
	/* 0x4dc: lea    eax,[r13+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_4e3:
	/* 0x4e3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4e8:
	/* 0x4e8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4ec:
	/* 0x4ec: mov    BYTE PTR [rsi+0x1b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_4ef:
	/* 0x4ef: cmp    r13,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 24ULL);
x86_l_4f3:
	/* 0x4f3: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_4f9:
	/* 0x4f9: lea    eax,[r13+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_500:
	/* 0x500: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_505:
	/* 0x505: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_509:
	/* 0x509: mov    BYTE PTR [rsi+0x1c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_50c:
	/* 0x50c: cmp    r13,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 25ULL);
x86_l_510:
	/* 0x510: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_516:
	/* 0x516: lea    eax,[r13+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_51d:
	/* 0x51d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_522:
	/* 0x522: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_526:
	/* 0x526: mov    BYTE PTR [rsi+0x1d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_529:
	/* 0x529: cmp    r13,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 26ULL);
x86_l_52d:
	/* 0x52d: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_533:
	/* 0x533: lea    eax,[r13+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_53a:
	/* 0x53a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_53f:
	/* 0x53f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_543:
	/* 0x543: mov    BYTE PTR [rsi+0x1e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_546:
	/* 0x546: cmp    r13,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 27ULL);
x86_l_54a:
	/* 0x54a: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_550:
	/* 0x550: lea    eax,[r13+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_557:
	/* 0x557: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_55c:
	/* 0x55c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_560:
	/* 0x560: mov    BYTE PTR [rsi+0x1f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_563:
	/* 0x563: cmp    r13,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 28ULL);
x86_l_567:
	/* 0x567: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_56d:
	/* 0x56d: lea    eax,[r13+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_574:
	/* 0x574: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_579:
	/* 0x579: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_57d:
	/* 0x57d: mov    BYTE PTR [rsi+0x20],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_580:
	/* 0x580: cmp    r13,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 29ULL);
x86_l_584:
	/* 0x584: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_58a:
	/* 0x58a: lea    eax,[r13+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_591:
	/* 0x591: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_596:
	/* 0x596: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_59a:
	/* 0x59a: mov    BYTE PTR [rsi+0x21],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_59d:
	/* 0x59d: cmp    r13,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 30ULL);
x86_l_5a1:
	/* 0x5a1: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_5a7:
	/* 0x5a7: lea    eax,[r13+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_5ae:
	/* 0x5ae: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5b3:
	/* 0x5b3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_5b7:
	/* 0x5b7: mov    BYTE PTR [rsi+0x22],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_5ba:
	/* 0x5ba: cmp    r13,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 31ULL);
x86_l_5be:
	/* 0x5be: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_5c4:
	/* 0x5c4: lea    eax,[r13+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_5cb:
	/* 0x5cb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5d0:
	/* 0x5d0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_5d4:
	/* 0x5d4: mov    BYTE PTR [rsi+0x23],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_5d7:
	/* 0x5d7: cmp    r13,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 32ULL);
x86_l_5db:
	/* 0x5db: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_5e1:
	/* 0x5e1: lea    eax,[r13+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_5e8:
	/* 0x5e8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5ed:
	/* 0x5ed: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_5f1:
	/* 0x5f1: mov    BYTE PTR [rsi+0x24],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5f4:
	/* 0x5f4: cmp    r13,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 33ULL);
x86_l_5f8:
	/* 0x5f8: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_5fe:
	/* 0x5fe: lea    eax,[r13+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_605:
	/* 0x605: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_60a:
	/* 0x60a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_60e:
	/* 0x60e: mov    BYTE PTR [rsi+0x25],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_611:
	/* 0x611: cmp    r13,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 34ULL);
x86_l_615:
	/* 0x615: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_61b:
	/* 0x61b: lea    eax,[r13+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_622:
	/* 0x622: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_627:
	/* 0x627: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_62b:
	/* 0x62b: mov    BYTE PTR [rsi+0x26],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_62e:
	/* 0x62e: cmp    r13,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 35ULL);
x86_l_632:
	/* 0x632: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_638:
	/* 0x638: lea    eax,[r13+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_63f:
	/* 0x63f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_644:
	/* 0x644: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_648:
	/* 0x648: mov    BYTE PTR [rsi+0x27],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_64b:
	/* 0x64b: cmp    r13,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 36ULL);
x86_l_64f:
	/* 0x64f: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_655:
	/* 0x655: lea    eax,[r13+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_65c:
	/* 0x65c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_661:
	/* 0x661: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_665:
	/* 0x665: mov    BYTE PTR [rsi+0x28],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_668:
	/* 0x668: cmp    r13,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 37ULL);
x86_l_66c:
	/* 0x66c: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_672:
	/* 0x672: lea    eax,[r13+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_679:
	/* 0x679: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_67e:
	/* 0x67e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_682:
	/* 0x682: mov    BYTE PTR [rsi+0x29],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_685:
	/* 0x685: cmp    r13,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 38ULL);
x86_l_689:
	/* 0x689: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_68f:
	/* 0x68f: lea    eax,[r13+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_696:
	/* 0x696: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_69b:
	/* 0x69b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_69f:
	/* 0x69f: mov    BYTE PTR [rsi+0x2a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_6a2:
	/* 0x6a2: cmp    r13,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 39ULL);
x86_l_6a6:
	/* 0x6a6: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_6ac:
	/* 0x6ac: lea    eax,[r13+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_6b3:
	/* 0x6b3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6b8:
	/* 0x6b8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_6bc:
	/* 0x6bc: mov    BYTE PTR [rsi+0x2b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_6bf:
	/* 0x6bf: cmp    r13,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 40ULL);
x86_l_6c3:
	/* 0x6c3: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_6c9:
	/* 0x6c9: lea    eax,[r13+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_6d0:
	/* 0x6d0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6d5:
	/* 0x6d5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_6d9:
	/* 0x6d9: mov    BYTE PTR [rsi+0x2c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6dc:
	/* 0x6dc: cmp    r13,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 41ULL);
x86_l_6e0:
	/* 0x6e0: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3276ULL;
	}
x86_l_6e6:
	/* 0x6e6: lea    eax,[r13+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_6ed:
	/* 0x6ed: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
	return 1778ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1778ULL: goto x86_l_6f2;
	case 1782ULL: goto x86_l_6f6;
	case 1785ULL: goto x86_l_6f9;
	case 1789ULL: goto x86_l_6fd;
	case 1795ULL: goto x86_l_703;
	case 1802ULL: goto x86_l_70a;
	case 1807ULL: goto x86_l_70f;
	case 1811ULL: goto x86_l_713;
	case 1814ULL: goto x86_l_716;
	case 1818ULL: goto x86_l_71a;
	case 1824ULL: goto x86_l_720;
	case 1831ULL: goto x86_l_727;
	case 1836ULL: goto x86_l_72c;
	case 1840ULL: goto x86_l_730;
	case 1843ULL: goto x86_l_733;
	case 1847ULL: goto x86_l_737;
	case 1853ULL: goto x86_l_73d;
	case 1860ULL: goto x86_l_744;
	case 1865ULL: goto x86_l_749;
	case 1869ULL: goto x86_l_74d;
	case 1872ULL: goto x86_l_750;
	case 1876ULL: goto x86_l_754;
	case 1882ULL: goto x86_l_75a;
	case 1889ULL: goto x86_l_761;
	case 1894ULL: goto x86_l_766;
	case 1898ULL: goto x86_l_76a;
	case 1901ULL: goto x86_l_76d;
	case 1905ULL: goto x86_l_771;
	case 1911ULL: goto x86_l_777;
	case 1918ULL: goto x86_l_77e;
	case 1923ULL: goto x86_l_783;
	case 1927ULL: goto x86_l_787;
	case 1930ULL: goto x86_l_78a;
	case 1934ULL: goto x86_l_78e;
	case 1940ULL: goto x86_l_794;
	case 1947ULL: goto x86_l_79b;
	case 1952ULL: goto x86_l_7a0;
	case 1956ULL: goto x86_l_7a4;
	case 1959ULL: goto x86_l_7a7;
	case 1963ULL: goto x86_l_7ab;
	case 1969ULL: goto x86_l_7b1;
	case 1976ULL: goto x86_l_7b8;
	case 1981ULL: goto x86_l_7bd;
	case 1985ULL: goto x86_l_7c1;
	case 1988ULL: goto x86_l_7c4;
	case 1992ULL: goto x86_l_7c8;
	case 1998ULL: goto x86_l_7ce;
	case 2005ULL: goto x86_l_7d5;
	case 2010ULL: goto x86_l_7da;
	case 2014ULL: goto x86_l_7de;
	case 2017ULL: goto x86_l_7e1;
	case 2021ULL: goto x86_l_7e5;
	case 2027ULL: goto x86_l_7eb;
	case 2034ULL: goto x86_l_7f2;
	case 2039ULL: goto x86_l_7f7;
	case 2043ULL: goto x86_l_7fb;
	case 2046ULL: goto x86_l_7fe;
	case 2050ULL: goto x86_l_802;
	case 2056ULL: goto x86_l_808;
	case 2063ULL: goto x86_l_80f;
	case 2068ULL: goto x86_l_814;
	case 2072ULL: goto x86_l_818;
	case 2075ULL: goto x86_l_81b;
	case 2079ULL: goto x86_l_81f;
	case 2085ULL: goto x86_l_825;
	case 2092ULL: goto x86_l_82c;
	case 2097ULL: goto x86_l_831;
	case 2101ULL: goto x86_l_835;
	case 2104ULL: goto x86_l_838;
	case 2108ULL: goto x86_l_83c;
	case 2114ULL: goto x86_l_842;
	case 2121ULL: goto x86_l_849;
	case 2126ULL: goto x86_l_84e;
	case 2130ULL: goto x86_l_852;
	case 2133ULL: goto x86_l_855;
	case 2137ULL: goto x86_l_859;
	case 2143ULL: goto x86_l_85f;
	case 2150ULL: goto x86_l_866;
	case 2155ULL: goto x86_l_86b;
	case 2159ULL: goto x86_l_86f;
	case 2162ULL: goto x86_l_872;
	case 2166ULL: goto x86_l_876;
	case 2172ULL: goto x86_l_87c;
	case 2179ULL: goto x86_l_883;
	case 2184ULL: goto x86_l_888;
	case 2188ULL: goto x86_l_88c;
	case 2191ULL: goto x86_l_88f;
	case 2195ULL: goto x86_l_893;
	case 2201ULL: goto x86_l_899;
	case 2208ULL: goto x86_l_8a0;
	case 2213ULL: goto x86_l_8a5;
	case 2217ULL: goto x86_l_8a9;
	case 2220ULL: goto x86_l_8ac;
	case 2224ULL: goto x86_l_8b0;
	case 2230ULL: goto x86_l_8b6;
	case 2237ULL: goto x86_l_8bd;
	case 2242ULL: goto x86_l_8c2;
	case 2246ULL: goto x86_l_8c6;
	case 2249ULL: goto x86_l_8c9;
	case 2253ULL: goto x86_l_8cd;
	case 2259ULL: goto x86_l_8d3;
	case 2266ULL: goto x86_l_8da;
	case 2271ULL: goto x86_l_8df;
	case 2275ULL: goto x86_l_8e3;
	case 2278ULL: goto x86_l_8e6;
	case 2282ULL: goto x86_l_8ea;
	case 2288ULL: goto x86_l_8f0;
	case 2295ULL: goto x86_l_8f7;
	case 2300ULL: goto x86_l_8fc;
	case 2304ULL: goto x86_l_900;
	case 2307ULL: goto x86_l_903;
	case 2311ULL: goto x86_l_907;
	case 2317ULL: goto x86_l_90d;
	case 2324ULL: goto x86_l_914;
	case 2329ULL: goto x86_l_919;
	case 2333ULL: goto x86_l_91d;
	case 2336ULL: goto x86_l_920;
	case 2340ULL: goto x86_l_924;
	case 2346ULL: goto x86_l_92a;
	case 2353ULL: goto x86_l_931;
	case 2358ULL: goto x86_l_936;
	case 2362ULL: goto x86_l_93a;
	case 2365ULL: goto x86_l_93d;
	case 2369ULL: goto x86_l_941;
	case 2375ULL: goto x86_l_947;
	case 2382ULL: goto x86_l_94e;
	case 2387ULL: goto x86_l_953;
	case 2391ULL: goto x86_l_957;
	case 2394ULL: goto x86_l_95a;
	case 2398ULL: goto x86_l_95e;
	case 2404ULL: goto x86_l_964;
	case 2411ULL: goto x86_l_96b;
	case 2416ULL: goto x86_l_970;
	case 2420ULL: goto x86_l_974;
	case 2423ULL: goto x86_l_977;
	case 2427ULL: goto x86_l_97b;
	case 2433ULL: goto x86_l_981;
	case 2440ULL: goto x86_l_988;
	case 2445ULL: goto x86_l_98d;
	case 2449ULL: goto x86_l_991;
	case 2452ULL: goto x86_l_994;
	case 2456ULL: goto x86_l_998;
	case 2462ULL: goto x86_l_99e;
	case 2469ULL: goto x86_l_9a5;
	case 2474ULL: goto x86_l_9aa;
	case 2478ULL: goto x86_l_9ae;
	case 2481ULL: goto x86_l_9b1;
	case 2485ULL: goto x86_l_9b5;
	case 2491ULL: goto x86_l_9bb;
	case 2498ULL: goto x86_l_9c2;
	case 2503ULL: goto x86_l_9c7;
	case 2507ULL: goto x86_l_9cb;
	case 2510ULL: goto x86_l_9ce;
	case 2514ULL: goto x86_l_9d2;
	case 2520ULL: goto x86_l_9d8;
	case 2527ULL: goto x86_l_9df;
	case 2532ULL: goto x86_l_9e4;
	case 2536ULL: goto x86_l_9e8;
	case 2539ULL: goto x86_l_9eb;
	case 2543ULL: goto x86_l_9ef;
	case 2549ULL: goto x86_l_9f5;
	case 2556ULL: goto x86_l_9fc;
	case 2561ULL: goto x86_l_a01;
	case 2565ULL: goto x86_l_a05;
	case 2568ULL: goto x86_l_a08;
	case 2572ULL: goto x86_l_a0c;
	case 2578ULL: goto x86_l_a12;
	case 2585ULL: goto x86_l_a19;
	case 2590ULL: goto x86_l_a1e;
	case 2594ULL: goto x86_l_a22;
	case 2597ULL: goto x86_l_a25;
	case 2601ULL: goto x86_l_a29;
	case 2607ULL: goto x86_l_a2f;
	case 2614ULL: goto x86_l_a36;
	case 2619ULL: goto x86_l_a3b;
	case 2623ULL: goto x86_l_a3f;
	case 2626ULL: goto x86_l_a42;
	case 2630ULL: goto x86_l_a46;
	case 2636ULL: goto x86_l_a4c;
	case 2643ULL: goto x86_l_a53;
	case 2648ULL: goto x86_l_a58;
	case 2652ULL: goto x86_l_a5c;
	case 2655ULL: goto x86_l_a5f;
	case 2659ULL: goto x86_l_a63;
	case 2665ULL: goto x86_l_a69;
	case 2672ULL: goto x86_l_a70;
	case 2677ULL: goto x86_l_a75;
	case 2681ULL: goto x86_l_a79;
	case 2684ULL: goto x86_l_a7c;
	case 2688ULL: goto x86_l_a80;
	case 2694ULL: goto x86_l_a86;
	case 2701ULL: goto x86_l_a8d;
	case 2706ULL: goto x86_l_a92;
	case 2710ULL: goto x86_l_a96;
	case 2713ULL: goto x86_l_a99;
	case 2717ULL: goto x86_l_a9d;
	case 2723ULL: goto x86_l_aa3;
	case 2730ULL: goto x86_l_aaa;
	case 2735ULL: goto x86_l_aaf;
	case 2739ULL: goto x86_l_ab3;
	case 2742ULL: goto x86_l_ab6;
	case 2746ULL: goto x86_l_aba;
	case 2752ULL: goto x86_l_ac0;
	case 2759ULL: goto x86_l_ac7;
	case 2764ULL: goto x86_l_acc;
	case 2768ULL: goto x86_l_ad0;
	case 2771ULL: goto x86_l_ad3;
	case 2775ULL: goto x86_l_ad7;
	case 2781ULL: goto x86_l_add;
	case 2788ULL: goto x86_l_ae4;
	case 2793ULL: goto x86_l_ae9;
	case 2797ULL: goto x86_l_aed;
	case 2800ULL: goto x86_l_af0;
	case 2804ULL: goto x86_l_af4;
	case 2810ULL: goto x86_l_afa;
	case 2817ULL: goto x86_l_b01;
	case 2822ULL: goto x86_l_b06;
	case 2826ULL: goto x86_l_b0a;
	case 2829ULL: goto x86_l_b0d;
	case 2833ULL: goto x86_l_b11;
	case 2839ULL: goto x86_l_b17;
	case 2846ULL: goto x86_l_b1e;
	case 2851ULL: goto x86_l_b23;
	case 2855ULL: goto x86_l_b27;
	case 2858ULL: goto x86_l_b2a;
	case 2862ULL: goto x86_l_b2e;
	case 2868ULL: goto x86_l_b34;
	case 2875ULL: goto x86_l_b3b;
	case 2880ULL: goto x86_l_b40;
	case 2884ULL: goto x86_l_b44;
	case 2887ULL: goto x86_l_b47;
	case 2891ULL: goto x86_l_b4b;
	case 2897ULL: goto x86_l_b51;
	case 2904ULL: goto x86_l_b58;
	case 2909ULL: goto x86_l_b5d;
	case 2913ULL: goto x86_l_b61;
	case 2916ULL: goto x86_l_b64;
	case 2920ULL: goto x86_l_b68;
	case 2926ULL: goto x86_l_b6e;
	case 2933ULL: goto x86_l_b75;
	case 2938ULL: goto x86_l_b7a;
	case 2942ULL: goto x86_l_b7e;
	case 2945ULL: goto x86_l_b81;
	case 2949ULL: goto x86_l_b85;
	case 2955ULL: goto x86_l_b8b;
	case 2962ULL: goto x86_l_b92;
	case 2967ULL: goto x86_l_b97;
	case 2971ULL: goto x86_l_b9b;
	case 2974ULL: goto x86_l_b9e;
	case 2978ULL: goto x86_l_ba2;
	case 2984ULL: goto x86_l_ba8;
	case 2991ULL: goto x86_l_baf;
	case 2996ULL: goto x86_l_bb4;
	case 3000ULL: goto x86_l_bb8;
	case 3003ULL: goto x86_l_bbb;
	case 3007ULL: goto x86_l_bbf;
	case 3013ULL: goto x86_l_bc5;
	case 3020ULL: goto x86_l_bcc;
	case 3025ULL: goto x86_l_bd1;
	case 3029ULL: goto x86_l_bd5;
	case 3032ULL: goto x86_l_bd8;
	case 3036ULL: goto x86_l_bdc;
	case 3042ULL: goto x86_l_be2;
	case 3049ULL: goto x86_l_be9;
	case 3054ULL: goto x86_l_bee;
	case 3058ULL: goto x86_l_bf2;
	case 3061ULL: goto x86_l_bf5;
	case 3065ULL: goto x86_l_bf9;
	case 3071ULL: goto x86_l_bff;
	case 3078ULL: goto x86_l_c06;
	case 3083ULL: goto x86_l_c0b;
	case 3087ULL: goto x86_l_c0f;
	case 3090ULL: goto x86_l_c12;
	case 3094ULL: goto x86_l_c16;
	case 3100ULL: goto x86_l_c1c;
	case 3107ULL: goto x86_l_c23;
	case 3112ULL: goto x86_l_c28;
	case 3116ULL: goto x86_l_c2c;
	case 3119ULL: goto x86_l_c2f;
	case 3123ULL: goto x86_l_c33;
	case 3129ULL: goto x86_l_c39;
	case 3136ULL: goto x86_l_c40;
	case 3141ULL: goto x86_l_c45;
	case 3145ULL: goto x86_l_c49;
	case 3148ULL: goto x86_l_c4c;
	case 3152ULL: goto x86_l_c50;
	case 3154ULL: goto x86_l_c52;
	case 3161ULL: goto x86_l_c59;
	case 3166ULL: goto x86_l_c5e;
	case 3170ULL: goto x86_l_c62;
	case 3173ULL: goto x86_l_c65;
	case 3177ULL: goto x86_l_c69;
	case 3179ULL: goto x86_l_c6b;
	case 3186ULL: goto x86_l_c72;
	case 3191ULL: goto x86_l_c77;
	case 3195ULL: goto x86_l_c7b;
	case 3198ULL: goto x86_l_c7e;
	case 3202ULL: goto x86_l_c82;
	case 3204ULL: goto x86_l_c84;
	case 3211ULL: goto x86_l_c8b;
	case 3216ULL: goto x86_l_c90;
	case 3220ULL: goto x86_l_c94;
	case 3223ULL: goto x86_l_c97;
	case 3227ULL: goto x86_l_c9b;
	case 3229ULL: goto x86_l_c9d;
	case 3236ULL: goto x86_l_ca4;
	case 3241ULL: goto x86_l_ca9;
	case 3245ULL: goto x86_l_cad;
	case 3248ULL: goto x86_l_cb0;
	case 3252ULL: goto x86_l_cb4;
	case 3254ULL: goto x86_l_cb6;
	case 3261ULL: goto x86_l_cbd;
	case 3268ULL: goto x86_l_cc4;
	case 3273ULL: goto x86_l_cc9;
	case 3276ULL: goto x86_l_ccc;
	case 3281ULL: goto x86_l_cd1;
	case 3284ULL: goto x86_l_cd4;
	case 3289ULL: goto x86_l_cd9;
	case 3292ULL: goto x86_l_cdc;
	case 3295ULL: goto x86_l_cdf;
	case 3301ULL: goto x86_l_ce5;
	case 3304ULL: goto x86_l_ce8;
	case 3306ULL: goto x86_l_cea;
	case 3311ULL: goto x86_l_cef;
	case 3314ULL: goto x86_l_cf2;
	case 3317ULL: goto x86_l_cf5;
	case 3319ULL: goto x86_l_cf7;
	case 3328ULL: goto x86_l_d00;
	case 3337ULL: goto x86_l_d09;
	case 3346ULL: goto x86_l_d12;
	case 3355ULL: goto x86_l_d1b;
	case 3364ULL: goto x86_l_d24;
	case 3367ULL: goto x86_l_d27;
	case 3370ULL: goto x86_l_d2a;
	case 3372ULL: goto x86_l_d2c;
	case 3375ULL: goto x86_l_d2f;
	case 3381ULL: goto x86_l_d35;
	case 3384ULL: goto x86_l_d38;
	case 3387ULL: goto x86_l_d3b;
	case 3393ULL: goto x86_l_d41;
	case 3398ULL: goto x86_l_d46;
	case 3401ULL: goto x86_l_d49;
	case 3407ULL: goto x86_l_d4f;
	case 3410ULL: goto x86_l_d52;
	case 3413ULL: goto x86_l_d55;
	case 3419ULL: goto x86_l_d5b;
	case 3424ULL: goto x86_l_d60;
	case 3427ULL: goto x86_l_d63;
	case 3433ULL: goto x86_l_d69;
	case 3437ULL: goto x86_l_d6d;
	case 3439ULL: goto x86_l_d6f;
	case 3442ULL: goto x86_l_d72;
	case 3448ULL: goto x86_l_d78;
	case 3451ULL: goto x86_l_d7b;
	case 3454ULL: goto x86_l_d7e;
	case 3457ULL: goto x86_l_d81;
	case 3459ULL: goto x86_l_d83;
	case 3461ULL: goto x86_l_d85;
	case 3464ULL: goto x86_l_d88;
	case 3467ULL: goto x86_l_d8b;
	case 3473ULL: goto x86_l_d91;
	case 3476ULL: goto x86_l_d94;
	case 3482ULL: goto x86_l_d9a;
	case 3484ULL: goto x86_l_d9c;
	case 3489ULL: goto x86_l_da1;
	case 3493ULL: goto x86_l_da5;
	case 3499ULL: goto x86_l_dab;
	case 3504ULL: goto x86_l_db0;
	case 3508ULL: goto x86_l_db4;
	case 3514ULL: goto x86_l_dba;
	case 3524ULL: goto x86_l_dc4;
	case 3528ULL: goto x86_l_dc8;
	case 3534ULL: goto x86_l_dce;
	case 3541ULL: goto x86_l_dd5;
	case 3548ULL: goto x86_l_ddc;
	case 3554ULL: goto x86_l_de2;
	case 3558ULL: goto x86_l_de6;
	case 3562ULL: goto x86_l_dea;
	case 3567ULL: goto x86_l_def;
	case 3572ULL: goto x86_l_df4;
	case 3577ULL: goto x86_l_df9;
	case 3580ULL: goto x86_l_dfc;
	case 3584ULL: goto x86_l_e00;
	case 3588ULL: goto x86_l_e04;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6f2:
	/* 0x6f2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_6f6:
	/* 0x6f6: mov    BYTE PTR [rsi+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_6f9:
	/* 0x6f9: cmp    r13,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 42ULL);
x86_l_6fd:
	/* 0x6fd: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_703:
	/* 0x703: lea    eax,[r13+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_70a:
	/* 0x70a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_70f:
	/* 0x70f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_713:
	/* 0x713: mov    BYTE PTR [rsi+0x2e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_716:
	/* 0x716: cmp    r13,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 43ULL);
x86_l_71a:
	/* 0x71a: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_720:
	/* 0x720: lea    eax,[r13+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_727:
	/* 0x727: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_72c:
	/* 0x72c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_730:
	/* 0x730: mov    BYTE PTR [rsi+0x2f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_733:
	/* 0x733: cmp    r13,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 44ULL);
x86_l_737:
	/* 0x737: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_73d:
	/* 0x73d: lea    eax,[r13+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_744:
	/* 0x744: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_749:
	/* 0x749: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_74d:
	/* 0x74d: mov    BYTE PTR [rsi+0x30],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_750:
	/* 0x750: cmp    r13,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 45ULL);
x86_l_754:
	/* 0x754: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_75a:
	/* 0x75a: lea    eax,[r13+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_761:
	/* 0x761: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_766:
	/* 0x766: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_76a:
	/* 0x76a: mov    BYTE PTR [rsi+0x31],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_76d:
	/* 0x76d: cmp    r13,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 46ULL);
x86_l_771:
	/* 0x771: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_777:
	/* 0x777: lea    eax,[r13+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_77e:
	/* 0x77e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_783:
	/* 0x783: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_787:
	/* 0x787: mov    BYTE PTR [rsi+0x32],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_78a:
	/* 0x78a: cmp    r13,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 47ULL);
x86_l_78e:
	/* 0x78e: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_794:
	/* 0x794: lea    eax,[r13+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_79b:
	/* 0x79b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7a0:
	/* 0x7a0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_7a4:
	/* 0x7a4: mov    BYTE PTR [rsi+0x33],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_7a7:
	/* 0x7a7: cmp    r13,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 48ULL);
x86_l_7ab:
	/* 0x7ab: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_7b1:
	/* 0x7b1: lea    eax,[r13+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_7b8:
	/* 0x7b8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7bd:
	/* 0x7bd: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_7c1:
	/* 0x7c1: mov    BYTE PTR [rsi+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_7c4:
	/* 0x7c4: cmp    r13,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 49ULL);
x86_l_7c8:
	/* 0x7c8: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_7ce:
	/* 0x7ce: lea    eax,[r13+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_7d5:
	/* 0x7d5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7da:
	/* 0x7da: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_7de:
	/* 0x7de: mov    BYTE PTR [rsi+0x35],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_7e1:
	/* 0x7e1: cmp    r13,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 50ULL);
x86_l_7e5:
	/* 0x7e5: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_7eb:
	/* 0x7eb: lea    eax,[r13+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_7f2:
	/* 0x7f2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7f7:
	/* 0x7f7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_7fb:
	/* 0x7fb: mov    BYTE PTR [rsi+0x36],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_7fe:
	/* 0x7fe: cmp    r13,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 51ULL);
x86_l_802:
	/* 0x802: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_808:
	/* 0x808: lea    eax,[r13+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_80f:
	/* 0x80f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_814:
	/* 0x814: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_818:
	/* 0x818: mov    BYTE PTR [rsi+0x37],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_81b:
	/* 0x81b: cmp    r13,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 52ULL);
x86_l_81f:
	/* 0x81f: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_825:
	/* 0x825: lea    eax,[r13+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_82c:
	/* 0x82c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_831:
	/* 0x831: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_835:
	/* 0x835: mov    BYTE PTR [rsi+0x38],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_838:
	/* 0x838: cmp    r13,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 53ULL);
x86_l_83c:
	/* 0x83c: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_842:
	/* 0x842: lea    eax,[r13+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_849:
	/* 0x849: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_84e:
	/* 0x84e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_852:
	/* 0x852: mov    BYTE PTR [rsi+0x39],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_855:
	/* 0x855: cmp    r13,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 54ULL);
x86_l_859:
	/* 0x859: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_85f:
	/* 0x85f: lea    eax,[r13+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_866:
	/* 0x866: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_86b:
	/* 0x86b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_86f:
	/* 0x86f: mov    BYTE PTR [rsi+0x3a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_872:
	/* 0x872: cmp    r13,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 55ULL);
x86_l_876:
	/* 0x876: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_87c:
	/* 0x87c: lea    eax,[r13+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_883:
	/* 0x883: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_888:
	/* 0x888: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_88c:
	/* 0x88c: mov    BYTE PTR [rsi+0x3b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_88f:
	/* 0x88f: cmp    r13,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 56ULL);
x86_l_893:
	/* 0x893: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_899:
	/* 0x899: lea    eax,[r13+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_8a0:
	/* 0x8a0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8a5:
	/* 0x8a5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_8a9:
	/* 0x8a9: mov    BYTE PTR [rsi+0x3c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_8ac:
	/* 0x8ac: cmp    r13,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 57ULL);
x86_l_8b0:
	/* 0x8b0: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_8b6:
	/* 0x8b6: lea    eax,[r13+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_8bd:
	/* 0x8bd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8c2:
	/* 0x8c2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_8c6:
	/* 0x8c6: mov    BYTE PTR [rsi+0x3d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_8c9:
	/* 0x8c9: cmp    r13,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 58ULL);
x86_l_8cd:
	/* 0x8cd: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_8d3:
	/* 0x8d3: lea    eax,[r13+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_8da:
	/* 0x8da: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8df:
	/* 0x8df: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_8e3:
	/* 0x8e3: mov    BYTE PTR [rsi+0x3e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_8e6:
	/* 0x8e6: cmp    r13,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 59ULL);
x86_l_8ea:
	/* 0x8ea: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_8f0:
	/* 0x8f0: lea    eax,[r13+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_8f7:
	/* 0x8f7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8fc:
	/* 0x8fc: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_900:
	/* 0x900: mov    BYTE PTR [rsi+0x3f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_903:
	/* 0x903: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_907:
	/* 0x907: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_90d:
	/* 0x90d: lea    eax,[r13+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_914:
	/* 0x914: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_919:
	/* 0x919: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_91d:
	/* 0x91d: mov    BYTE PTR [rsi+0x40],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_920:
	/* 0x920: cmp    r13,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 61ULL);
x86_l_924:
	/* 0x924: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_92a:
	/* 0x92a: lea    eax,[r13+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_931:
	/* 0x931: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_936:
	/* 0x936: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_93a:
	/* 0x93a: mov    BYTE PTR [rsi+0x41],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_93d:
	/* 0x93d: cmp    r13,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 62ULL);
x86_l_941:
	/* 0x941: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_947:
	/* 0x947: lea    eax,[r13+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_94e:
	/* 0x94e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_953:
	/* 0x953: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_957:
	/* 0x957: mov    BYTE PTR [rsi+0x42],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_95a:
	/* 0x95a: cmp    r13,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 63ULL);
x86_l_95e:
	/* 0x95e: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_964:
	/* 0x964: lea    eax,[r13+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_96b:
	/* 0x96b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_970:
	/* 0x970: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_974:
	/* 0x974: mov    BYTE PTR [rsi+0x43],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_977:
	/* 0x977: cmp    r13,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 64ULL);
x86_l_97b:
	/* 0x97b: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_981:
	/* 0x981: lea    eax,[r13+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_988:
	/* 0x988: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_98d:
	/* 0x98d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_991:
	/* 0x991: mov    BYTE PTR [rsi+0x44],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_994:
	/* 0x994: cmp    r13,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 65ULL);
x86_l_998:
	/* 0x998: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_99e:
	/* 0x99e: lea    eax,[r13+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_9a5:
	/* 0x9a5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9aa:
	/* 0x9aa: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_9ae:
	/* 0x9ae: mov    BYTE PTR [rsi+0x45],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_9b1:
	/* 0x9b1: cmp    r13,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 66ULL);
x86_l_9b5:
	/* 0x9b5: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_9bb:
	/* 0x9bb: lea    eax,[r13+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_9c2:
	/* 0x9c2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9c7:
	/* 0x9c7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_9cb:
	/* 0x9cb: mov    BYTE PTR [rsi+0x46],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_9ce:
	/* 0x9ce: cmp    r13,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 67ULL);
x86_l_9d2:
	/* 0x9d2: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_9d8:
	/* 0x9d8: lea    eax,[r13+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_9df:
	/* 0x9df: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9e4:
	/* 0x9e4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_9e8:
	/* 0x9e8: mov    BYTE PTR [rsi+0x47],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_9eb:
	/* 0x9eb: cmp    r13,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 68ULL);
x86_l_9ef:
	/* 0x9ef: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_9f5:
	/* 0x9f5: lea    eax,[r13+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_9fc:
	/* 0x9fc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a01:
	/* 0xa01: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a05:
	/* 0xa05: mov    BYTE PTR [rsi+0x48],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a08:
	/* 0xa08: cmp    r13,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 69ULL);
x86_l_a0c:
	/* 0xa0c: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_a12:
	/* 0xa12: lea    eax,[r13+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_a19:
	/* 0xa19: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a1e:
	/* 0xa1e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a22:
	/* 0xa22: mov    BYTE PTR [rsi+0x49],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_a25:
	/* 0xa25: cmp    r13,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 70ULL);
x86_l_a29:
	/* 0xa29: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_a2f:
	/* 0xa2f: lea    eax,[r13+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_a36:
	/* 0xa36: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a3b:
	/* 0xa3b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a3f:
	/* 0xa3f: mov    BYTE PTR [rsi+0x4a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_a42:
	/* 0xa42: cmp    r13,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 71ULL);
x86_l_a46:
	/* 0xa46: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_a4c:
	/* 0xa4c: lea    eax,[r13+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_a53:
	/* 0xa53: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a58:
	/* 0xa58: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a5c:
	/* 0xa5c: mov    BYTE PTR [rsi+0x4b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_a5f:
	/* 0xa5f: cmp    r13,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 72ULL);
x86_l_a63:
	/* 0xa63: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_a69:
	/* 0xa69: lea    eax,[r13+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_a70:
	/* 0xa70: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a75:
	/* 0xa75: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a79:
	/* 0xa79: mov    BYTE PTR [rsi+0x4c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_a7c:
	/* 0xa7c: cmp    r13,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 73ULL);
x86_l_a80:
	/* 0xa80: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_a86:
	/* 0xa86: lea    eax,[r13+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_a8d:
	/* 0xa8d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a92:
	/* 0xa92: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a96:
	/* 0xa96: mov    BYTE PTR [rsi+0x4d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_a99:
	/* 0xa99: cmp    r13,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 74ULL);
x86_l_a9d:
	/* 0xa9d: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_aa3:
	/* 0xaa3: lea    eax,[r13+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_aaa:
	/* 0xaaa: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_aaf:
	/* 0xaaf: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_ab3:
	/* 0xab3: mov    BYTE PTR [rsi+0x4e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_ab6:
	/* 0xab6: cmp    r13,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 75ULL);
x86_l_aba:
	/* 0xaba: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_ac0:
	/* 0xac0: lea    eax,[r13+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_ac7:
	/* 0xac7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_acc:
	/* 0xacc: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_ad0:
	/* 0xad0: mov    BYTE PTR [rsi+0x4f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_ad3:
	/* 0xad3: cmp    r13,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 76ULL);
x86_l_ad7:
	/* 0xad7: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_add:
	/* 0xadd: lea    eax,[r13+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_ae4:
	/* 0xae4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ae9:
	/* 0xae9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_aed:
	/* 0xaed: mov    BYTE PTR [rsi+0x50],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_af0:
	/* 0xaf0: cmp    r13,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 77ULL);
x86_l_af4:
	/* 0xaf4: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_afa:
	/* 0xafa: lea    eax,[r13+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_b01:
	/* 0xb01: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b06:
	/* 0xb06: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b0a:
	/* 0xb0a: mov    BYTE PTR [rsi+0x51],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_b0d:
	/* 0xb0d: cmp    r13,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 78ULL);
x86_l_b11:
	/* 0xb11: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_b17:
	/* 0xb17: lea    eax,[r13+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_b1e:
	/* 0xb1e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b23:
	/* 0xb23: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b27:
	/* 0xb27: mov    BYTE PTR [rsi+0x52],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_b2a:
	/* 0xb2a: cmp    r13,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 79ULL);
x86_l_b2e:
	/* 0xb2e: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_b34:
	/* 0xb34: lea    eax,[r13+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_b3b:
	/* 0xb3b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b40:
	/* 0xb40: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b44:
	/* 0xb44: mov    BYTE PTR [rsi+0x53],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_b47:
	/* 0xb47: cmp    r13,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 80ULL);
x86_l_b4b:
	/* 0xb4b: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_b51:
	/* 0xb51: lea    eax,[r13+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_b58:
	/* 0xb58: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b5d:
	/* 0xb5d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b61:
	/* 0xb61: mov    BYTE PTR [rsi+0x54],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_b64:
	/* 0xb64: cmp    r13,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 81ULL);
x86_l_b68:
	/* 0xb68: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_b6e:
	/* 0xb6e: lea    eax,[r13+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_b75:
	/* 0xb75: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b7a:
	/* 0xb7a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b7e:
	/* 0xb7e: mov    BYTE PTR [rsi+0x55],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_b81:
	/* 0xb81: cmp    r13,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 82ULL);
x86_l_b85:
	/* 0xb85: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_b8b:
	/* 0xb8b: lea    eax,[r13+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_b92:
	/* 0xb92: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b97:
	/* 0xb97: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b9b:
	/* 0xb9b: mov    BYTE PTR [rsi+0x56],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_b9e:
	/* 0xb9e: cmp    r13,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 83ULL);
x86_l_ba2:
	/* 0xba2: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_ba8:
	/* 0xba8: lea    eax,[r13+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_baf:
	/* 0xbaf: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bb4:
	/* 0xbb4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_bb8:
	/* 0xbb8: mov    BYTE PTR [rsi+0x57],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_bbb:
	/* 0xbbb: cmp    r13,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 84ULL);
x86_l_bbf:
	/* 0xbbf: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_bc5:
	/* 0xbc5: lea    eax,[r13+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_bcc:
	/* 0xbcc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bd1:
	/* 0xbd1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_bd5:
	/* 0xbd5: mov    BYTE PTR [rsi+0x58],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_bd8:
	/* 0xbd8: cmp    r13,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 85ULL);
x86_l_bdc:
	/* 0xbdc: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_be2:
	/* 0xbe2: lea    eax,[r13+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_be9:
	/* 0xbe9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bee:
	/* 0xbee: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_bf2:
	/* 0xbf2: mov    BYTE PTR [rsi+0x59],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_bf5:
	/* 0xbf5: cmp    r13,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 86ULL);
x86_l_bf9:
	/* 0xbf9: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_bff:
	/* 0xbff: lea    eax,[r13+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_c06:
	/* 0xc06: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c0b:
	/* 0xc0b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c0f:
	/* 0xc0f: mov    BYTE PTR [rsi+0x5a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_c12:
	/* 0xc12: cmp    r13,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 87ULL);
x86_l_c16:
	/* 0xc16: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_c1c:
	/* 0xc1c: lea    eax,[r13+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_c23:
	/* 0xc23: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c28:
	/* 0xc28: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c2c:
	/* 0xc2c: mov    BYTE PTR [rsi+0x5b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_c2f:
	/* 0xc2f: cmp    r13,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 88ULL);
x86_l_c33:
	/* 0xc33: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_c39:
	/* 0xc39: lea    eax,[r13+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_c40:
	/* 0xc40: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c45:
	/* 0xc45: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c49:
	/* 0xc49: mov    BYTE PTR [rsi+0x5c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_c4c:
	/* 0xc4c: cmp    r13,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 89ULL);
x86_l_c50:
	/* 0xc50: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_c52:
	/* 0xc52: lea    eax,[r13+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_c59:
	/* 0xc59: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c5e:
	/* 0xc5e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c62:
	/* 0xc62: mov    BYTE PTR [rsi+0x5d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_c65:
	/* 0xc65: cmp    r13,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 90ULL);
x86_l_c69:
	/* 0xc69: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_c6b:
	/* 0xc6b: lea    eax,[r13+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_c72:
	/* 0xc72: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c77:
	/* 0xc77: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c7b:
	/* 0xc7b: mov    BYTE PTR [rsi+0x5e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_c7e:
	/* 0xc7e: cmp    r13,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 91ULL);
x86_l_c82:
	/* 0xc82: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_c84:
	/* 0xc84: lea    eax,[r13+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_c8b:
	/* 0xc8b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c90:
	/* 0xc90: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c94:
	/* 0xc94: mov    BYTE PTR [rsi+0x5f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_c97:
	/* 0xc97: cmp    r13,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 92ULL);
x86_l_c9b:
	/* 0xc9b: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_c9d:
	/* 0xc9d: lea    eax,[r13+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_ca4:
	/* 0xca4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ca9:
	/* 0xca9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_cad:
	/* 0xcad: mov    BYTE PTR [rsi+0x60],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_cb0:
	/* 0xcb0: cmp    r13,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 93ULL);
x86_l_cb4:
	/* 0xcb4: je     ccc <generic_usdt_filter_arg_2+0xccc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccc;
	}
x86_l_cb6:
	/* 0xcb6: add    r13d,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_cbd:
	/* 0xcbd: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_cc4:
	/* 0xcc4: movzx  eax,BYTE PTR [rcx+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_cc9:
	/* 0xcc9: mov    BYTE PTR [rsi+0x61],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_ccc:
	/* 0xccc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cd1:
	/* 0xcd1: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_cd4:
	/* 0xcd4: jmp    31ef <generic_usdt_filter_arg_2+0x31ef> */
	return 12783ULL;
x86_l_cd9:
	/* 0xcd9: lea    eax,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_cdc:
	/* 0xcdc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cdf:
	/* 0xcdf: jb     d78 <generic_usdt_filter_arg_2+0xd78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d78;
	}
x86_l_ce5:
	/* 0xce5: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_ce8:
	/* 0xce8: je     cf7 <generic_usdt_filter_arg_2+0xcf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cf7;
	}
x86_l_cea:
	/* 0xcea: jmp    3227 <generic_usdt_filter_arg_2+0x3227> */
	return 12839ULL;
x86_l_cef:
	/* 0xcef: lea    eax,[rcx-0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551576ULL);
x86_l_cf2:
	/* 0xcf2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cf5:
	/* 0xcf5: jae    d6f <generic_usdt_filter_arg_2+0xd6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_d6f;
	}
x86_l_cf7:
	/* 0xcf7: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_d00:
	/* 0xd00: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_d09:
	/* 0xd09: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_d12:
	/* 0xd12: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_d1b:
	/* 0xd1b: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_d24:
	/* 0xd24: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d27:
	/* 0xd27: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_d2a:
	/* 0xd2a: jg     d46 <generic_usdt_filter_arg_2+0xd46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d46;
	}
x86_l_d2c:
	/* 0xd2c: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_d2f:
	/* 0xd2f: je     1b65 <generic_usdt_filter_arg_2+0x1b65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7013ULL;
	}
x86_l_d35:
	/* 0xd35: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_d38:
	/* 0xd38: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_d3b:
	/* 0xd3b: je     1b67 <generic_usdt_filter_arg_2+0x1b67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7015ULL;
	}
x86_l_d41:
	/* 0xd41: jmp    3222 <generic_usdt_filter_arg_2+0x3222> */
	return 12834ULL;
x86_l_d46:
	/* 0xd46: cmp    ecx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_d49:
	/* 0xd49: je     1b3b <generic_usdt_filter_arg_2+0x1b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6971ULL;
	}
x86_l_d4f:
	/* 0xd4f: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_d52:
	/* 0xd52: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_d55:
	/* 0xd55: je     1b67 <generic_usdt_filter_arg_2+0x1b67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7015ULL;
	}
x86_l_d5b:
	/* 0xd5b: jmp    3222 <generic_usdt_filter_arg_2+0x3222> */
	return 12834ULL;
x86_l_d60:
	/* 0xd60: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_d63:
	/* 0xd63: jne    3227 <generic_usdt_filter_arg_2+0x3227> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12839ULL;
	}
x86_l_d69:
	/* 0xd69: add    r8,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_d6d:
	/* 0xd6d: jmp    d78 <generic_usdt_filter_arg_2+0xd78> */
	goto x86_l_d78;
x86_l_d6f:
	/* 0xd6f: cmp    ecx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 42ULL);
x86_l_d72:
	/* 0xd72: jne    3227 <generic_usdt_filter_arg_2+0x3227> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12839ULL;
	}
x86_l_d78:
	/* 0xd78: mov    r13d,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d7b:
	/* 0xd7b: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d7e:
	/* 0xd7e: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_d81:
	/* 0xd81: jne    d91 <generic_usdt_filter_arg_2+0xd91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d91;
	}
x86_l_d83:
	/* 0xd83: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_d85:
	/* 0xd85: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_d88:
	/* 0xd88: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_d8b:
	/* 0xd8b: jne    3231 <generic_usdt_filter_arg_2+0x3231> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12849ULL;
	}
x86_l_d91:
	/* 0xd91: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_d94:
	/* 0xd94: ja     1bde <generic_usdt_filter_arg_2+0x1bde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7134ULL;
	}
x86_l_d9a:
	/* 0xd9a: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_d9c:
	/* 0xd9c: mov    edx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 67109120ULL);
x86_l_da1:
	/* 0xda1: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_da5:
	/* 0xda5: jb     273e <generic_usdt_filter_arg_2+0x273e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10046ULL;
	}
x86_l_dab:
	/* 0xdab: mov    edx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 134218240ULL);
x86_l_db0:
	/* 0xdb0: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_db4:
	/* 0xdb4: jb     1c27 <generic_usdt_filter_arg_2+0x1c27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7207ULL;
	}
x86_l_dba:
	/* 0xdba: movabs rdx,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 206158430208ULL);
x86_l_dc4:
	/* 0xdc4: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_dc8:
	/* 0xdc8: jae    1bde <generic_usdt_filter_arg_2+0x1bde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7134ULL;
	}
x86_l_dce:
	/* 0xdce: mov    WORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_dd5:
	/* 0xdd5: cmp    r13d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 144ULL);
x86_l_ddc:
	/* 0xddc: ja     1bff <generic_usdt_filter_arg_2+0x1bff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7167ULL;
	}
x86_l_de2:
	/* 0xde2: lea    rcx,[r8+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_de6:
	/* 0xde6: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_dea:
	/* 0xdea: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_def:
	/* 0xdef: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_df4:
	/* 0xdf4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_df9:
	/* 0xdf9: mov    ecx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dfc:
	/* 0xdfc: lea    rdx,[r8+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_e00:
	/* 0xe00: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_e04:
	/* 0xe04: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
	return 3591ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3591ULL: goto x86_l_e07;
	case 3596ULL: goto x86_l_e0c;
	case 3598ULL: goto x86_l_e0e;
	case 3601ULL: goto x86_l_e11;
	case 3605ULL: goto x86_l_e15;
	case 3607ULL: goto x86_l_e17;
	case 3613ULL: goto x86_l_e1d;
	case 3618ULL: goto x86_l_e22;
	case 3623ULL: goto x86_l_e27;
	case 3629ULL: goto x86_l_e2d;
	case 3631ULL: goto x86_l_e2f;
	case 3637ULL: goto x86_l_e35;
	case 3640ULL: goto x86_l_e38;
	case 3643ULL: goto x86_l_e3b;
	case 3649ULL: goto x86_l_e41;
	case 3653ULL: goto x86_l_e45;
	case 3655ULL: goto x86_l_e47;
	case 3661ULL: goto x86_l_e4d;
	case 3663ULL: goto x86_l_e4f;
	case 3669ULL: goto x86_l_e55;
	case 3672ULL: goto x86_l_e58;
	case 3678ULL: goto x86_l_e5e;
	case 3682ULL: goto x86_l_e62;
	case 3684ULL: goto x86_l_e64;
	case 3690ULL: goto x86_l_e6a;
	case 3692ULL: goto x86_l_e6c;
	case 3695ULL: goto x86_l_e6f;
	case 3701ULL: goto x86_l_e75;
	case 3704ULL: goto x86_l_e78;
	case 3710ULL: goto x86_l_e7e;
	case 3714ULL: goto x86_l_e82;
	case 3716ULL: goto x86_l_e84;
	case 3722ULL: goto x86_l_e8a;
	case 3725ULL: goto x86_l_e8d;
	case 3727ULL: goto x86_l_e8f;
	case 3731ULL: goto x86_l_e93;
	case 3736ULL: goto x86_l_e98;
	case 3739ULL: goto x86_l_e9b;
	case 3742ULL: goto x86_l_e9e;
	case 3745ULL: goto x86_l_ea1;
	case 3751ULL: goto x86_l_ea7;
	case 3755ULL: goto x86_l_eab;
	case 3759ULL: goto x86_l_eaf;
	case 3764ULL: goto x86_l_eb4;
	case 3767ULL: goto x86_l_eb7;
	case 3772ULL: goto x86_l_ebc;
	case 3778ULL: goto x86_l_ec2;
	case 3783ULL: goto x86_l_ec7;
	case 3786ULL: goto x86_l_eca;
	case 3792ULL: goto x86_l_ed0;
	case 3797ULL: goto x86_l_ed5;
	case 3800ULL: goto x86_l_ed8;
	case 3806ULL: goto x86_l_ede;
	case 3809ULL: goto x86_l_ee1;
	case 3813ULL: goto x86_l_ee5;
	case 3816ULL: goto x86_l_ee8;
	case 3820ULL: goto x86_l_eec;
	case 3828ULL: goto x86_l_ef4;
	case 3835ULL: goto x86_l_efb;
	case 3840ULL: goto x86_l_f00;
	case 3845ULL: goto x86_l_f05;
	case 3847ULL: goto x86_l_f07;
	case 3850ULL: goto x86_l_f0a;
	case 3856ULL: goto x86_l_f10;
	case 3862ULL: goto x86_l_f16;
	case 3867ULL: goto x86_l_f1b;
	case 3870ULL: goto x86_l_f1e;
	case 3876ULL: goto x86_l_f24;
	case 3883ULL: goto x86_l_f2b;
	case 3888ULL: goto x86_l_f30;
	case 3893ULL: goto x86_l_f35;
	case 3895ULL: goto x86_l_f37;
	case 3898ULL: goto x86_l_f3a;
	case 3904ULL: goto x86_l_f40;
	case 3907ULL: goto x86_l_f43;
	case 3912ULL: goto x86_l_f48;
	case 3915ULL: goto x86_l_f4b;
	case 3920ULL: goto x86_l_f50;
	case 3923ULL: goto x86_l_f53;
	case 3926ULL: goto x86_l_f56;
	case 3928ULL: goto x86_l_f58;
	case 3931ULL: goto x86_l_f5b;
	case 3936ULL: goto x86_l_f60;
	case 3942ULL: goto x86_l_f66;
	case 3945ULL: goto x86_l_f69;
	case 3949ULL: goto x86_l_f6d;
	case 3955ULL: goto x86_l_f73;
	case 3961ULL: goto x86_l_f79;
	case 3966ULL: goto x86_l_f7e;
	case 3972ULL: goto x86_l_f84;
	case 3975ULL: goto x86_l_f87;
	case 3979ULL: goto x86_l_f8b;
	case 3985ULL: goto x86_l_f91;
	case 3991ULL: goto x86_l_f97;
	case 3996ULL: goto x86_l_f9c;
	case 4002ULL: goto x86_l_fa2;
	case 4005ULL: goto x86_l_fa5;
	case 4009ULL: goto x86_l_fa9;
	case 4015ULL: goto x86_l_faf;
	case 4021ULL: goto x86_l_fb5;
	case 4026ULL: goto x86_l_fba;
	case 4032ULL: goto x86_l_fc0;
	case 4035ULL: goto x86_l_fc3;
	case 4039ULL: goto x86_l_fc7;
	case 4045ULL: goto x86_l_fcd;
	case 4051ULL: goto x86_l_fd3;
	case 4056ULL: goto x86_l_fd8;
	case 4062ULL: goto x86_l_fde;
	case 4065ULL: goto x86_l_fe1;
	case 4069ULL: goto x86_l_fe5;
	case 4075ULL: goto x86_l_feb;
	case 4081ULL: goto x86_l_ff1;
	case 4086ULL: goto x86_l_ff6;
	case 4092ULL: goto x86_l_ffc;
	case 4095ULL: goto x86_l_fff;
	case 4099ULL: goto x86_l_1003;
	case 4105ULL: goto x86_l_1009;
	case 4111ULL: goto x86_l_100f;
	case 4116ULL: goto x86_l_1014;
	case 4122ULL: goto x86_l_101a;
	case 4125ULL: goto x86_l_101d;
	case 4129ULL: goto x86_l_1021;
	case 4135ULL: goto x86_l_1027;
	case 4141ULL: goto x86_l_102d;
	case 4146ULL: goto x86_l_1032;
	case 4152ULL: goto x86_l_1038;
	case 4155ULL: goto x86_l_103b;
	case 4159ULL: goto x86_l_103f;
	case 4165ULL: goto x86_l_1045;
	case 4171ULL: goto x86_l_104b;
	case 4176ULL: goto x86_l_1050;
	case 4182ULL: goto x86_l_1056;
	case 4185ULL: goto x86_l_1059;
	case 4189ULL: goto x86_l_105d;
	case 4195ULL: goto x86_l_1063;
	case 4201ULL: goto x86_l_1069;
	case 4206ULL: goto x86_l_106e;
	case 4212ULL: goto x86_l_1074;
	case 4215ULL: goto x86_l_1077;
	case 4219ULL: goto x86_l_107b;
	case 4225ULL: goto x86_l_1081;
	case 4231ULL: goto x86_l_1087;
	case 4236ULL: goto x86_l_108c;
	case 4242ULL: goto x86_l_1092;
	case 4245ULL: goto x86_l_1095;
	case 4249ULL: goto x86_l_1099;
	case 4255ULL: goto x86_l_109f;
	case 4261ULL: goto x86_l_10a5;
	case 4266ULL: goto x86_l_10aa;
	case 4272ULL: goto x86_l_10b0;
	case 4275ULL: goto x86_l_10b3;
	case 4279ULL: goto x86_l_10b7;
	case 4285ULL: goto x86_l_10bd;
	case 4291ULL: goto x86_l_10c3;
	case 4296ULL: goto x86_l_10c8;
	case 4302ULL: goto x86_l_10ce;
	case 4305ULL: goto x86_l_10d1;
	case 4309ULL: goto x86_l_10d5;
	case 4315ULL: goto x86_l_10db;
	case 4321ULL: goto x86_l_10e1;
	case 4326ULL: goto x86_l_10e6;
	case 4332ULL: goto x86_l_10ec;
	case 4335ULL: goto x86_l_10ef;
	case 4339ULL: goto x86_l_10f3;
	case 4345ULL: goto x86_l_10f9;
	case 4351ULL: goto x86_l_10ff;
	case 4356ULL: goto x86_l_1104;
	case 4362ULL: goto x86_l_110a;
	case 4365ULL: goto x86_l_110d;
	case 4369ULL: goto x86_l_1111;
	case 4375ULL: goto x86_l_1117;
	case 4381ULL: goto x86_l_111d;
	case 4386ULL: goto x86_l_1122;
	case 4392ULL: goto x86_l_1128;
	case 4395ULL: goto x86_l_112b;
	case 4399ULL: goto x86_l_112f;
	case 4405ULL: goto x86_l_1135;
	case 4411ULL: goto x86_l_113b;
	case 4416ULL: goto x86_l_1140;
	case 4422ULL: goto x86_l_1146;
	case 4425ULL: goto x86_l_1149;
	case 4429ULL: goto x86_l_114d;
	case 4435ULL: goto x86_l_1153;
	case 4441ULL: goto x86_l_1159;
	case 4446ULL: goto x86_l_115e;
	case 4452ULL: goto x86_l_1164;
	case 4455ULL: goto x86_l_1167;
	case 4459ULL: goto x86_l_116b;
	case 4465ULL: goto x86_l_1171;
	case 4471ULL: goto x86_l_1177;
	case 4476ULL: goto x86_l_117c;
	case 4482ULL: goto x86_l_1182;
	case 4485ULL: goto x86_l_1185;
	case 4489ULL: goto x86_l_1189;
	case 4495ULL: goto x86_l_118f;
	case 4501ULL: goto x86_l_1195;
	case 4506ULL: goto x86_l_119a;
	case 4512ULL: goto x86_l_11a0;
	case 4515ULL: goto x86_l_11a3;
	case 4519ULL: goto x86_l_11a7;
	case 4525ULL: goto x86_l_11ad;
	case 4531ULL: goto x86_l_11b3;
	case 4536ULL: goto x86_l_11b8;
	case 4542ULL: goto x86_l_11be;
	case 4545ULL: goto x86_l_11c1;
	case 4549ULL: goto x86_l_11c5;
	case 4555ULL: goto x86_l_11cb;
	case 4561ULL: goto x86_l_11d1;
	case 4566ULL: goto x86_l_11d6;
	case 4572ULL: goto x86_l_11dc;
	case 4575ULL: goto x86_l_11df;
	case 4579ULL: goto x86_l_11e3;
	case 4585ULL: goto x86_l_11e9;
	case 4591ULL: goto x86_l_11ef;
	case 4596ULL: goto x86_l_11f4;
	case 4602ULL: goto x86_l_11fa;
	case 4605ULL: goto x86_l_11fd;
	case 4609ULL: goto x86_l_1201;
	case 4615ULL: goto x86_l_1207;
	case 4621ULL: goto x86_l_120d;
	case 4626ULL: goto x86_l_1212;
	case 4632ULL: goto x86_l_1218;
	case 4635ULL: goto x86_l_121b;
	case 4639ULL: goto x86_l_121f;
	case 4645ULL: goto x86_l_1225;
	case 4651ULL: goto x86_l_122b;
	case 4656ULL: goto x86_l_1230;
	case 4662ULL: goto x86_l_1236;
	case 4665ULL: goto x86_l_1239;
	case 4669ULL: goto x86_l_123d;
	case 4675ULL: goto x86_l_1243;
	case 4681ULL: goto x86_l_1249;
	case 4686ULL: goto x86_l_124e;
	case 4692ULL: goto x86_l_1254;
	case 4695ULL: goto x86_l_1257;
	case 4699ULL: goto x86_l_125b;
	case 4705ULL: goto x86_l_1261;
	case 4711ULL: goto x86_l_1267;
	case 4716ULL: goto x86_l_126c;
	case 4722ULL: goto x86_l_1272;
	case 4725ULL: goto x86_l_1275;
	case 4729ULL: goto x86_l_1279;
	case 4735ULL: goto x86_l_127f;
	case 4741ULL: goto x86_l_1285;
	case 4746ULL: goto x86_l_128a;
	case 4752ULL: goto x86_l_1290;
	case 4755ULL: goto x86_l_1293;
	case 4759ULL: goto x86_l_1297;
	case 4765ULL: goto x86_l_129d;
	case 4771ULL: goto x86_l_12a3;
	case 4776ULL: goto x86_l_12a8;
	case 4782ULL: goto x86_l_12ae;
	case 4785ULL: goto x86_l_12b1;
	case 4789ULL: goto x86_l_12b5;
	case 4795ULL: goto x86_l_12bb;
	case 4801ULL: goto x86_l_12c1;
	case 4806ULL: goto x86_l_12c6;
	case 4812ULL: goto x86_l_12cc;
	case 4815ULL: goto x86_l_12cf;
	case 4819ULL: goto x86_l_12d3;
	case 4825ULL: goto x86_l_12d9;
	case 4831ULL: goto x86_l_12df;
	case 4836ULL: goto x86_l_12e4;
	case 4842ULL: goto x86_l_12ea;
	case 4845ULL: goto x86_l_12ed;
	case 4849ULL: goto x86_l_12f1;
	case 4855ULL: goto x86_l_12f7;
	case 4861ULL: goto x86_l_12fd;
	case 4866ULL: goto x86_l_1302;
	case 4872ULL: goto x86_l_1308;
	case 4875ULL: goto x86_l_130b;
	case 4879ULL: goto x86_l_130f;
	case 4885ULL: goto x86_l_1315;
	case 4891ULL: goto x86_l_131b;
	case 4896ULL: goto x86_l_1320;
	case 4902ULL: goto x86_l_1326;
	case 4905ULL: goto x86_l_1329;
	case 4909ULL: goto x86_l_132d;
	case 4915ULL: goto x86_l_1333;
	case 4921ULL: goto x86_l_1339;
	case 4926ULL: goto x86_l_133e;
	case 4932ULL: goto x86_l_1344;
	case 4935ULL: goto x86_l_1347;
	case 4939ULL: goto x86_l_134b;
	case 4945ULL: goto x86_l_1351;
	case 4951ULL: goto x86_l_1357;
	case 4956ULL: goto x86_l_135c;
	case 4962ULL: goto x86_l_1362;
	case 4965ULL: goto x86_l_1365;
	case 4969ULL: goto x86_l_1369;
	case 4975ULL: goto x86_l_136f;
	case 4981ULL: goto x86_l_1375;
	case 4986ULL: goto x86_l_137a;
	case 4992ULL: goto x86_l_1380;
	case 4995ULL: goto x86_l_1383;
	case 4999ULL: goto x86_l_1387;
	case 5005ULL: goto x86_l_138d;
	case 5011ULL: goto x86_l_1393;
	case 5016ULL: goto x86_l_1398;
	case 5022ULL: goto x86_l_139e;
	case 5025ULL: goto x86_l_13a1;
	case 5029ULL: goto x86_l_13a5;
	case 5035ULL: goto x86_l_13ab;
	case 5041ULL: goto x86_l_13b1;
	case 5046ULL: goto x86_l_13b6;
	case 5052ULL: goto x86_l_13bc;
	case 5055ULL: goto x86_l_13bf;
	case 5059ULL: goto x86_l_13c3;
	case 5065ULL: goto x86_l_13c9;
	case 5071ULL: goto x86_l_13cf;
	case 5076ULL: goto x86_l_13d4;
	case 5082ULL: goto x86_l_13da;
	case 5085ULL: goto x86_l_13dd;
	case 5089ULL: goto x86_l_13e1;
	case 5095ULL: goto x86_l_13e7;
	case 5101ULL: goto x86_l_13ed;
	case 5106ULL: goto x86_l_13f2;
	case 5112ULL: goto x86_l_13f8;
	case 5115ULL: goto x86_l_13fb;
	case 5119ULL: goto x86_l_13ff;
	case 5125ULL: goto x86_l_1405;
	case 5131ULL: goto x86_l_140b;
	case 5136ULL: goto x86_l_1410;
	case 5142ULL: goto x86_l_1416;
	case 5145ULL: goto x86_l_1419;
	case 5149ULL: goto x86_l_141d;
	case 5155ULL: goto x86_l_1423;
	case 5161ULL: goto x86_l_1429;
	case 5166ULL: goto x86_l_142e;
	case 5172ULL: goto x86_l_1434;
	case 5175ULL: goto x86_l_1437;
	case 5179ULL: goto x86_l_143b;
	case 5185ULL: goto x86_l_1441;
	case 5191ULL: goto x86_l_1447;
	case 5196ULL: goto x86_l_144c;
	case 5202ULL: goto x86_l_1452;
	case 5205ULL: goto x86_l_1455;
	case 5209ULL: goto x86_l_1459;
	case 5215ULL: goto x86_l_145f;
	case 5221ULL: goto x86_l_1465;
	case 5226ULL: goto x86_l_146a;
	case 5232ULL: goto x86_l_1470;
	case 5235ULL: goto x86_l_1473;
	case 5239ULL: goto x86_l_1477;
	case 5245ULL: goto x86_l_147d;
	case 5251ULL: goto x86_l_1483;
	case 5256ULL: goto x86_l_1488;
	case 5262ULL: goto x86_l_148e;
	case 5265ULL: goto x86_l_1491;
	case 5269ULL: goto x86_l_1495;
	case 5275ULL: goto x86_l_149b;
	case 5281ULL: goto x86_l_14a1;
	case 5286ULL: goto x86_l_14a6;
	case 5292ULL: goto x86_l_14ac;
	case 5295ULL: goto x86_l_14af;
	case 5299ULL: goto x86_l_14b3;
	case 5305ULL: goto x86_l_14b9;
	case 5311ULL: goto x86_l_14bf;
	case 5316ULL: goto x86_l_14c4;
	case 5322ULL: goto x86_l_14ca;
	case 5325ULL: goto x86_l_14cd;
	case 5329ULL: goto x86_l_14d1;
	case 5335ULL: goto x86_l_14d7;
	case 5341ULL: goto x86_l_14dd;
	case 5346ULL: goto x86_l_14e2;
	case 5352ULL: goto x86_l_14e8;
	case 5355ULL: goto x86_l_14eb;
	case 5359ULL: goto x86_l_14ef;
	case 5365ULL: goto x86_l_14f5;
	case 5371ULL: goto x86_l_14fb;
	case 5376ULL: goto x86_l_1500;
	case 5382ULL: goto x86_l_1506;
	case 5385ULL: goto x86_l_1509;
	case 5389ULL: goto x86_l_150d;
	case 5395ULL: goto x86_l_1513;
	case 5401ULL: goto x86_l_1519;
	case 5406ULL: goto x86_l_151e;
	case 5412ULL: goto x86_l_1524;
	case 5415ULL: goto x86_l_1527;
	case 5419ULL: goto x86_l_152b;
	case 5425ULL: goto x86_l_1531;
	case 5431ULL: goto x86_l_1537;
	case 5436ULL: goto x86_l_153c;
	case 5442ULL: goto x86_l_1542;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e07:
	/* 0xe07: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e0c:
	/* 0xe0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e0e:
	/* 0xe0e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_e11:
	/* 0xe11: mov    ecx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e15:
	/* 0xe15: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_e17:
	/* 0xe17: je     1bff <generic_usdt_filter_arg_2+0x1bff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7167ULL;
	}
x86_l_e1d:
	/* 0xe1d: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_e22:
	/* 0xe22: and    eax,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_e27:
	/* 0xe27: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_e2d:
	/* 0xe2d: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_e2f:
	/* 0xe2f: je     3165 <generic_usdt_filter_arg_2+0x3165> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12645ULL;
	}
x86_l_e35:
	/* 0xe35: mov    ecx,DWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e38:
	/* 0xe38: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_e3b:
	/* 0xe3b: jbe    3008 <generic_usdt_filter_arg_2+0x3008> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 12296ULL;
	}
x86_l_e41:
	/* 0xe41: mov    edx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_e45:
	/* 0xe45: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_e47:
	/* 0xe47: je     3008 <generic_usdt_filter_arg_2+0x3008> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12296ULL;
	}
x86_l_e4d:
	/* 0xe4d: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_e4f:
	/* 0xe4f: je     300b <generic_usdt_filter_arg_2+0x300b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12299ULL;
	}
x86_l_e55:
	/* 0xe55: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_e58:
	/* 0xe58: jb     3008 <generic_usdt_filter_arg_2+0x3008> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12296ULL;
	}
x86_l_e5e:
	/* 0xe5e: mov    edx,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e62:
	/* 0xe62: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_e64:
	/* 0xe64: je     3008 <generic_usdt_filter_arg_2+0x3008> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12296ULL;
	}
x86_l_e6a:
	/* 0xe6a: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_e6c:
	/* 0xe6c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_e6f:
	/* 0xe6f: je     3165 <generic_usdt_filter_arg_2+0x3165> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12645ULL;
	}
x86_l_e75:
	/* 0xe75: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_e78:
	/* 0xe78: jb     3008 <generic_usdt_filter_arg_2+0x3008> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12296ULL;
	}
x86_l_e7e:
	/* 0xe7e: mov    ecx,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_e82:
	/* 0xe82: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_e84:
	/* 0xe84: je     3008 <generic_usdt_filter_arg_2+0x3008> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12296ULL;
	}
x86_l_e8a:
	/* 0xe8a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e8d:
	/* 0xe8d: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_e8f:
	/* 0xe8f: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_e93:
	/* 0xe93: jmp    300b <generic_usdt_filter_arg_2+0x300b> */
	return 12299ULL;
x86_l_e98:
	/* 0xe98: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e9b:
	/* 0xe9b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e9e:
	/* 0xe9e: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_ea1:
	/* 0xea1: ja     3207 <generic_usdt_filter_arg_2+0x3207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12807ULL;
	}
x86_l_ea7:
	/* 0xea7: mov    edx,DWORD PTR [r8+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_eab:
	/* 0xeab: add    r8,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_eaf:
	/* 0xeaf: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_eb4:
	/* 0xeb4: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_eb7:
	/* 0xeb7: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ebc:
	/* 0xebc: jb     29f7 <generic_usdt_filter_arg_2+0x29f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10743ULL;
	}
x86_l_ec2:
	/* 0xec2: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_ec7:
	/* 0xec7: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_eca:
	/* 0xeca: jb     2953 <generic_usdt_filter_arg_2+0x2953> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10579ULL;
	}
x86_l_ed0:
	/* 0xed0: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_ed5:
	/* 0xed5: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_ed8:
	/* 0xed8: jae    3207 <generic_usdt_filter_arg_2+0x3207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12807ULL;
	}
x86_l_ede:
	/* 0xede: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_ee1:
	/* 0xee1: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ee5:
	/* 0xee5: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ee8:
	/* 0xee8: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_eec:
	/* 0xeec: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_ef4:
	/* 0xef4: mov    rdi,QWORD PTR [rip+0xbe70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_efb:
	/* 0xefb: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f00:
	/* 0xf00: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f05:
	/* 0xf05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f07:
	/* 0xf07: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f0a:
	/* 0xf0a: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_f10:
	/* 0xf10: je     3200 <generic_usdt_filter_arg_2+0x3200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12800ULL;
	}
x86_l_f16:
	/* 0xf16: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f1b:
	/* 0xf1b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f1e:
	/* 0xf1e: je     3200 <generic_usdt_filter_arg_2+0x3200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12800ULL;
	}
x86_l_f24:
	/* 0xf24: mov    rdi,QWORD PTR [rip+0xbe70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_f2b:
	/* 0xf2b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f30:
	/* 0xf30: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f35:
	/* 0xf35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f37:
	/* 0xf37: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f3a:
	/* 0xf3a: je     31fd <generic_usdt_filter_arg_2+0x31fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12797ULL;
	}
x86_l_f40:
	/* 0xf40: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f43:
	/* 0xf43: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f48:
	/* 0xf48: cmp    edx,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 94ULL);
x86_l_f4b:
	/* 0xf4b: mov    eax,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 94ULL);
x86_l_f50:
	/* 0xf50: cmovb  eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_B);
x86_l_f53:
	/* 0xf53: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_f56:
	/* 0xf56: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f58:
	/* 0xf58: lea    eax,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_f5b:
	/* 0xf5b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f60:
	/* 0xf60: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f66:
	/* 0xf66: mov    BYTE PTR [rsi+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f69:
	/* 0xf69: cmp    rdx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 1ULL);
x86_l_f6d:
	/* 0xf6d: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_f73:
	/* 0xf73: lea    eax,[rdx+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_f79:
	/* 0xf79: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f7e:
	/* 0xf7e: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f84:
	/* 0xf84: mov    BYTE PTR [rsi+0x5],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_f87:
	/* 0xf87: cmp    rdx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 2ULL);
x86_l_f8b:
	/* 0xf8b: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_f91:
	/* 0xf91: lea    eax,[rdx+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_f97:
	/* 0xf97: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f9c:
	/* 0xf9c: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_fa2:
	/* 0xfa2: mov    BYTE PTR [rsi+0x6],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_fa5:
	/* 0xfa5: cmp    rdx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 3ULL);
x86_l_fa9:
	/* 0xfa9: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_faf:
	/* 0xfaf: lea    eax,[rdx+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_fb5:
	/* 0xfb5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fba:
	/* 0xfba: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_fc0:
	/* 0xfc0: mov    BYTE PTR [rsi+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_fc3:
	/* 0xfc3: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_fc7:
	/* 0xfc7: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_fcd:
	/* 0xfcd: lea    eax,[rdx+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_fd3:
	/* 0xfd3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fd8:
	/* 0xfd8: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_fde:
	/* 0xfde: mov    BYTE PTR [rsi+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fe1:
	/* 0xfe1: cmp    rdx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 5ULL);
x86_l_fe5:
	/* 0xfe5: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_feb:
	/* 0xfeb: lea    eax,[rdx+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_ff1:
	/* 0xff1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ff6:
	/* 0xff6: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_ffc:
	/* 0xffc: mov    BYTE PTR [rsi+0x9],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_fff:
	/* 0xfff: cmp    rdx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 6ULL);
x86_l_1003:
	/* 0x1003: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1009:
	/* 0x1009: lea    eax,[rdx+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_100f:
	/* 0x100f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1014:
	/* 0x1014: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_101a:
	/* 0x101a: mov    BYTE PTR [rsi+0xa],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_101d:
	/* 0x101d: cmp    rdx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 7ULL);
x86_l_1021:
	/* 0x1021: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1027:
	/* 0x1027: lea    eax,[rdx+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_102d:
	/* 0x102d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1032:
	/* 0x1032: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1038:
	/* 0x1038: mov    BYTE PTR [rsi+0xb],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_103b:
	/* 0x103b: cmp    rdx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 8ULL);
x86_l_103f:
	/* 0x103f: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1045:
	/* 0x1045: lea    eax,[rdx+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_104b:
	/* 0x104b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1050:
	/* 0x1050: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1056:
	/* 0x1056: mov    BYTE PTR [rsi+0xc],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1059:
	/* 0x1059: cmp    rdx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 9ULL);
x86_l_105d:
	/* 0x105d: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1063:
	/* 0x1063: lea    eax,[rdx+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_1069:
	/* 0x1069: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_106e:
	/* 0x106e: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1074:
	/* 0x1074: mov    BYTE PTR [rsi+0xd],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_1077:
	/* 0x1077: cmp    rdx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 10ULL);
x86_l_107b:
	/* 0x107b: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1081:
	/* 0x1081: lea    eax,[rdx+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_1087:
	/* 0x1087: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_108c:
	/* 0x108c: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1092:
	/* 0x1092: mov    BYTE PTR [rsi+0xe],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_1095:
	/* 0x1095: cmp    rdx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 11ULL);
x86_l_1099:
	/* 0x1099: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_109f:
	/* 0x109f: lea    eax,[rdx+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_10a5:
	/* 0x10a5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10aa:
	/* 0x10aa: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_10b0:
	/* 0x10b0: mov    BYTE PTR [rsi+0xf],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_10b3:
	/* 0x10b3: cmp    rdx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 12ULL);
x86_l_10b7:
	/* 0x10b7: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_10bd:
	/* 0x10bd: lea    eax,[rdx+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_10c3:
	/* 0x10c3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10c8:
	/* 0x10c8: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_10ce:
	/* 0x10ce: mov    BYTE PTR [rsi+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10d1:
	/* 0x10d1: cmp    rdx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 13ULL);
x86_l_10d5:
	/* 0x10d5: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_10db:
	/* 0x10db: lea    eax,[rdx+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_10e1:
	/* 0x10e1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10e6:
	/* 0x10e6: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_10ec:
	/* 0x10ec: mov    BYTE PTR [rsi+0x11],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_10ef:
	/* 0x10ef: cmp    rdx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 14ULL);
x86_l_10f3:
	/* 0x10f3: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_10f9:
	/* 0x10f9: lea    eax,[rdx+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_10ff:
	/* 0x10ff: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1104:
	/* 0x1104: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_110a:
	/* 0x110a: mov    BYTE PTR [rsi+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_110d:
	/* 0x110d: cmp    rdx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 15ULL);
x86_l_1111:
	/* 0x1111: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1117:
	/* 0x1117: lea    eax,[rdx+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_111d:
	/* 0x111d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1122:
	/* 0x1122: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1128:
	/* 0x1128: mov    BYTE PTR [rsi+0x13],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_112b:
	/* 0x112b: cmp    rdx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 16ULL);
x86_l_112f:
	/* 0x112f: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1135:
	/* 0x1135: lea    eax,[rdx+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_113b:
	/* 0x113b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1140:
	/* 0x1140: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1146:
	/* 0x1146: mov    BYTE PTR [rsi+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1149:
	/* 0x1149: cmp    rdx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 17ULL);
x86_l_114d:
	/* 0x114d: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1153:
	/* 0x1153: lea    eax,[rdx+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_1159:
	/* 0x1159: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_115e:
	/* 0x115e: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1164:
	/* 0x1164: mov    BYTE PTR [rsi+0x15],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_1167:
	/* 0x1167: cmp    rdx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18ULL);
x86_l_116b:
	/* 0x116b: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1171:
	/* 0x1171: lea    eax,[rdx+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_1177:
	/* 0x1177: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_117c:
	/* 0x117c: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1182:
	/* 0x1182: mov    BYTE PTR [rsi+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_1185:
	/* 0x1185: cmp    rdx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 19ULL);
x86_l_1189:
	/* 0x1189: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_118f:
	/* 0x118f: lea    eax,[rdx+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_1195:
	/* 0x1195: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_119a:
	/* 0x119a: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_11a0:
	/* 0x11a0: mov    BYTE PTR [rsi+0x17],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_11a3:
	/* 0x11a3: cmp    rdx,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 20ULL);
x86_l_11a7:
	/* 0x11a7: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_11ad:
	/* 0x11ad: lea    eax,[rdx+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_11b3:
	/* 0x11b3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11b8:
	/* 0x11b8: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_11be:
	/* 0x11be: mov    BYTE PTR [rsi+0x18],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11c1:
	/* 0x11c1: cmp    rdx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 21ULL);
x86_l_11c5:
	/* 0x11c5: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_11cb:
	/* 0x11cb: lea    eax,[rdx+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_11d1:
	/* 0x11d1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11d6:
	/* 0x11d6: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_11dc:
	/* 0x11dc: mov    BYTE PTR [rsi+0x19],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_11df:
	/* 0x11df: cmp    rdx,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 22ULL);
x86_l_11e3:
	/* 0x11e3: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_11e9:
	/* 0x11e9: lea    eax,[rdx+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_11ef:
	/* 0x11ef: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11f4:
	/* 0x11f4: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_11fa:
	/* 0x11fa: mov    BYTE PTR [rsi+0x1a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_11fd:
	/* 0x11fd: cmp    rdx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 23ULL);
x86_l_1201:
	/* 0x1201: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1207:
	/* 0x1207: lea    eax,[rdx+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_120d:
	/* 0x120d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1212:
	/* 0x1212: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1218:
	/* 0x1218: mov    BYTE PTR [rsi+0x1b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_121b:
	/* 0x121b: cmp    rdx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 24ULL);
x86_l_121f:
	/* 0x121f: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1225:
	/* 0x1225: lea    eax,[rdx+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_122b:
	/* 0x122b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1230:
	/* 0x1230: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1236:
	/* 0x1236: mov    BYTE PTR [rsi+0x1c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1239:
	/* 0x1239: cmp    rdx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 25ULL);
x86_l_123d:
	/* 0x123d: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1243:
	/* 0x1243: lea    eax,[rdx+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_1249:
	/* 0x1249: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_124e:
	/* 0x124e: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1254:
	/* 0x1254: mov    BYTE PTR [rsi+0x1d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_1257:
	/* 0x1257: cmp    rdx,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 26ULL);
x86_l_125b:
	/* 0x125b: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1261:
	/* 0x1261: lea    eax,[rdx+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_1267:
	/* 0x1267: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_126c:
	/* 0x126c: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1272:
	/* 0x1272: mov    BYTE PTR [rsi+0x1e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_1275:
	/* 0x1275: cmp    rdx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 27ULL);
x86_l_1279:
	/* 0x1279: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_127f:
	/* 0x127f: lea    eax,[rdx+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_1285:
	/* 0x1285: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_128a:
	/* 0x128a: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1290:
	/* 0x1290: mov    BYTE PTR [rsi+0x1f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_1293:
	/* 0x1293: cmp    rdx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 28ULL);
x86_l_1297:
	/* 0x1297: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_129d:
	/* 0x129d: lea    eax,[rdx+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_12a3:
	/* 0x12a3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12a8:
	/* 0x12a8: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_12ae:
	/* 0x12ae: mov    BYTE PTR [rsi+0x20],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12b1:
	/* 0x12b1: cmp    rdx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 29ULL);
x86_l_12b5:
	/* 0x12b5: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_12bb:
	/* 0x12bb: lea    eax,[rdx+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_12c1:
	/* 0x12c1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12c6:
	/* 0x12c6: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_12cc:
	/* 0x12cc: mov    BYTE PTR [rsi+0x21],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_12cf:
	/* 0x12cf: cmp    rdx,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 30ULL);
x86_l_12d3:
	/* 0x12d3: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_12d9:
	/* 0x12d9: lea    eax,[rdx+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_12df:
	/* 0x12df: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12e4:
	/* 0x12e4: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_12ea:
	/* 0x12ea: mov    BYTE PTR [rsi+0x22],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_12ed:
	/* 0x12ed: cmp    rdx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 31ULL);
x86_l_12f1:
	/* 0x12f1: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_12f7:
	/* 0x12f7: lea    eax,[rdx+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_12fd:
	/* 0x12fd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1302:
	/* 0x1302: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1308:
	/* 0x1308: mov    BYTE PTR [rsi+0x23],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_130b:
	/* 0x130b: cmp    rdx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 32ULL);
x86_l_130f:
	/* 0x130f: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1315:
	/* 0x1315: lea    eax,[rdx+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_131b:
	/* 0x131b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1320:
	/* 0x1320: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1326:
	/* 0x1326: mov    BYTE PTR [rsi+0x24],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1329:
	/* 0x1329: cmp    rdx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 33ULL);
x86_l_132d:
	/* 0x132d: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1333:
	/* 0x1333: lea    eax,[rdx+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_1339:
	/* 0x1339: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_133e:
	/* 0x133e: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1344:
	/* 0x1344: mov    BYTE PTR [rsi+0x25],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_1347:
	/* 0x1347: cmp    rdx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 34ULL);
x86_l_134b:
	/* 0x134b: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1351:
	/* 0x1351: lea    eax,[rdx+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_1357:
	/* 0x1357: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_135c:
	/* 0x135c: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1362:
	/* 0x1362: mov    BYTE PTR [rsi+0x26],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_1365:
	/* 0x1365: cmp    rdx,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 35ULL);
x86_l_1369:
	/* 0x1369: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_136f:
	/* 0x136f: lea    eax,[rdx+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_1375:
	/* 0x1375: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_137a:
	/* 0x137a: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1380:
	/* 0x1380: mov    BYTE PTR [rsi+0x27],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_1383:
	/* 0x1383: cmp    rdx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 36ULL);
x86_l_1387:
	/* 0x1387: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_138d:
	/* 0x138d: lea    eax,[rdx+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_1393:
	/* 0x1393: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1398:
	/* 0x1398: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_139e:
	/* 0x139e: mov    BYTE PTR [rsi+0x28],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13a1:
	/* 0x13a1: cmp    rdx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 37ULL);
x86_l_13a5:
	/* 0x13a5: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_13ab:
	/* 0x13ab: lea    eax,[rdx+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_13b1:
	/* 0x13b1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13b6:
	/* 0x13b6: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_13bc:
	/* 0x13bc: mov    BYTE PTR [rsi+0x29],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_13bf:
	/* 0x13bf: cmp    rdx,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 38ULL);
x86_l_13c3:
	/* 0x13c3: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_13c9:
	/* 0x13c9: lea    eax,[rdx+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_13cf:
	/* 0x13cf: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13d4:
	/* 0x13d4: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_13da:
	/* 0x13da: mov    BYTE PTR [rsi+0x2a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_13dd:
	/* 0x13dd: cmp    rdx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 39ULL);
x86_l_13e1:
	/* 0x13e1: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_13e7:
	/* 0x13e7: lea    eax,[rdx+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_13ed:
	/* 0x13ed: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13f2:
	/* 0x13f2: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_13f8:
	/* 0x13f8: mov    BYTE PTR [rsi+0x2b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_13fb:
	/* 0x13fb: cmp    rdx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 40ULL);
x86_l_13ff:
	/* 0x13ff: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1405:
	/* 0x1405: lea    eax,[rdx+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_140b:
	/* 0x140b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1410:
	/* 0x1410: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1416:
	/* 0x1416: mov    BYTE PTR [rsi+0x2c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1419:
	/* 0x1419: cmp    rdx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 41ULL);
x86_l_141d:
	/* 0x141d: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1423:
	/* 0x1423: lea    eax,[rdx+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_1429:
	/* 0x1429: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_142e:
	/* 0x142e: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1434:
	/* 0x1434: mov    BYTE PTR [rsi+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_1437:
	/* 0x1437: cmp    rdx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 42ULL);
x86_l_143b:
	/* 0x143b: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1441:
	/* 0x1441: lea    eax,[rdx+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_1447:
	/* 0x1447: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_144c:
	/* 0x144c: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1452:
	/* 0x1452: mov    BYTE PTR [rsi+0x2e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_1455:
	/* 0x1455: cmp    rdx,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 43ULL);
x86_l_1459:
	/* 0x1459: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_145f:
	/* 0x145f: lea    eax,[rdx+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_1465:
	/* 0x1465: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_146a:
	/* 0x146a: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1470:
	/* 0x1470: mov    BYTE PTR [rsi+0x2f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_1473:
	/* 0x1473: cmp    rdx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 44ULL);
x86_l_1477:
	/* 0x1477: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_147d:
	/* 0x147d: lea    eax,[rdx+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_1483:
	/* 0x1483: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1488:
	/* 0x1488: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_148e:
	/* 0x148e: mov    BYTE PTR [rsi+0x30],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1491:
	/* 0x1491: cmp    rdx,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 45ULL);
x86_l_1495:
	/* 0x1495: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_149b:
	/* 0x149b: lea    eax,[rdx+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_14a1:
	/* 0x14a1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14a6:
	/* 0x14a6: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_14ac:
	/* 0x14ac: mov    BYTE PTR [rsi+0x31],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_14af:
	/* 0x14af: cmp    rdx,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 46ULL);
x86_l_14b3:
	/* 0x14b3: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_14b9:
	/* 0x14b9: lea    eax,[rdx+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_14bf:
	/* 0x14bf: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14c4:
	/* 0x14c4: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_14ca:
	/* 0x14ca: mov    BYTE PTR [rsi+0x32],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_14cd:
	/* 0x14cd: cmp    rdx,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 47ULL);
x86_l_14d1:
	/* 0x14d1: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_14d7:
	/* 0x14d7: lea    eax,[rdx+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_14dd:
	/* 0x14dd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14e2:
	/* 0x14e2: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_14e8:
	/* 0x14e8: mov    BYTE PTR [rsi+0x33],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_14eb:
	/* 0x14eb: cmp    rdx,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 48ULL);
x86_l_14ef:
	/* 0x14ef: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_14f5:
	/* 0x14f5: lea    eax,[rdx+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_14fb:
	/* 0x14fb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1500:
	/* 0x1500: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1506:
	/* 0x1506: mov    BYTE PTR [rsi+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1509:
	/* 0x1509: cmp    rdx,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 49ULL);
x86_l_150d:
	/* 0x150d: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1513:
	/* 0x1513: lea    eax,[rdx+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_1519:
	/* 0x1519: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_151e:
	/* 0x151e: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1524:
	/* 0x1524: mov    BYTE PTR [rsi+0x35],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_1527:
	/* 0x1527: cmp    rdx,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 50ULL);
x86_l_152b:
	/* 0x152b: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_1531:
	/* 0x1531: lea    eax,[rdx+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_1537:
	/* 0x1537: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_153c:
	/* 0x153c: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1542:
	/* 0x1542: mov    BYTE PTR [rsi+0x36],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
	return 5445ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5445ULL: goto x86_l_1545;
	case 5449ULL: goto x86_l_1549;
	case 5455ULL: goto x86_l_154f;
	case 5461ULL: goto x86_l_1555;
	case 5466ULL: goto x86_l_155a;
	case 5472ULL: goto x86_l_1560;
	case 5475ULL: goto x86_l_1563;
	case 5479ULL: goto x86_l_1567;
	case 5485ULL: goto x86_l_156d;
	case 5491ULL: goto x86_l_1573;
	case 5496ULL: goto x86_l_1578;
	case 5502ULL: goto x86_l_157e;
	case 5505ULL: goto x86_l_1581;
	case 5509ULL: goto x86_l_1585;
	case 5515ULL: goto x86_l_158b;
	case 5521ULL: goto x86_l_1591;
	case 5526ULL: goto x86_l_1596;
	case 5532ULL: goto x86_l_159c;
	case 5535ULL: goto x86_l_159f;
	case 5539ULL: goto x86_l_15a3;
	case 5545ULL: goto x86_l_15a9;
	case 5551ULL: goto x86_l_15af;
	case 5556ULL: goto x86_l_15b4;
	case 5562ULL: goto x86_l_15ba;
	case 5565ULL: goto x86_l_15bd;
	case 5569ULL: goto x86_l_15c1;
	case 5575ULL: goto x86_l_15c7;
	case 5581ULL: goto x86_l_15cd;
	case 5586ULL: goto x86_l_15d2;
	case 5592ULL: goto x86_l_15d8;
	case 5595ULL: goto x86_l_15db;
	case 5599ULL: goto x86_l_15df;
	case 5605ULL: goto x86_l_15e5;
	case 5611ULL: goto x86_l_15eb;
	case 5616ULL: goto x86_l_15f0;
	case 5622ULL: goto x86_l_15f6;
	case 5625ULL: goto x86_l_15f9;
	case 5629ULL: goto x86_l_15fd;
	case 5635ULL: goto x86_l_1603;
	case 5641ULL: goto x86_l_1609;
	case 5646ULL: goto x86_l_160e;
	case 5652ULL: goto x86_l_1614;
	case 5655ULL: goto x86_l_1617;
	case 5659ULL: goto x86_l_161b;
	case 5665ULL: goto x86_l_1621;
	case 5671ULL: goto x86_l_1627;
	case 5676ULL: goto x86_l_162c;
	case 5682ULL: goto x86_l_1632;
	case 5685ULL: goto x86_l_1635;
	case 5689ULL: goto x86_l_1639;
	case 5695ULL: goto x86_l_163f;
	case 5701ULL: goto x86_l_1645;
	case 5706ULL: goto x86_l_164a;
	case 5712ULL: goto x86_l_1650;
	case 5715ULL: goto x86_l_1653;
	case 5719ULL: goto x86_l_1657;
	case 5725ULL: goto x86_l_165d;
	case 5731ULL: goto x86_l_1663;
	case 5736ULL: goto x86_l_1668;
	case 5742ULL: goto x86_l_166e;
	case 5745ULL: goto x86_l_1671;
	case 5749ULL: goto x86_l_1675;
	case 5755ULL: goto x86_l_167b;
	case 5761ULL: goto x86_l_1681;
	case 5766ULL: goto x86_l_1686;
	case 5772ULL: goto x86_l_168c;
	case 5775ULL: goto x86_l_168f;
	case 5779ULL: goto x86_l_1693;
	case 5785ULL: goto x86_l_1699;
	case 5791ULL: goto x86_l_169f;
	case 5796ULL: goto x86_l_16a4;
	case 5802ULL: goto x86_l_16aa;
	case 5805ULL: goto x86_l_16ad;
	case 5809ULL: goto x86_l_16b1;
	case 5815ULL: goto x86_l_16b7;
	case 5821ULL: goto x86_l_16bd;
	case 5826ULL: goto x86_l_16c2;
	case 5832ULL: goto x86_l_16c8;
	case 5835ULL: goto x86_l_16cb;
	case 5839ULL: goto x86_l_16cf;
	case 5845ULL: goto x86_l_16d5;
	case 5851ULL: goto x86_l_16db;
	case 5856ULL: goto x86_l_16e0;
	case 5862ULL: goto x86_l_16e6;
	case 5865ULL: goto x86_l_16e9;
	case 5869ULL: goto x86_l_16ed;
	case 5875ULL: goto x86_l_16f3;
	case 5881ULL: goto x86_l_16f9;
	case 5886ULL: goto x86_l_16fe;
	case 5892ULL: goto x86_l_1704;
	case 5895ULL: goto x86_l_1707;
	case 5899ULL: goto x86_l_170b;
	case 5905ULL: goto x86_l_1711;
	case 5911ULL: goto x86_l_1717;
	case 5916ULL: goto x86_l_171c;
	case 5922ULL: goto x86_l_1722;
	case 5925ULL: goto x86_l_1725;
	case 5929ULL: goto x86_l_1729;
	case 5935ULL: goto x86_l_172f;
	case 5941ULL: goto x86_l_1735;
	case 5946ULL: goto x86_l_173a;
	case 5952ULL: goto x86_l_1740;
	case 5955ULL: goto x86_l_1743;
	case 5959ULL: goto x86_l_1747;
	case 5965ULL: goto x86_l_174d;
	case 5971ULL: goto x86_l_1753;
	case 5976ULL: goto x86_l_1758;
	case 5982ULL: goto x86_l_175e;
	case 5985ULL: goto x86_l_1761;
	case 5989ULL: goto x86_l_1765;
	case 5995ULL: goto x86_l_176b;
	case 6001ULL: goto x86_l_1771;
	case 6006ULL: goto x86_l_1776;
	case 6012ULL: goto x86_l_177c;
	case 6015ULL: goto x86_l_177f;
	case 6019ULL: goto x86_l_1783;
	case 6025ULL: goto x86_l_1789;
	case 6031ULL: goto x86_l_178f;
	case 6036ULL: goto x86_l_1794;
	case 6042ULL: goto x86_l_179a;
	case 6045ULL: goto x86_l_179d;
	case 6049ULL: goto x86_l_17a1;
	case 6055ULL: goto x86_l_17a7;
	case 6061ULL: goto x86_l_17ad;
	case 6066ULL: goto x86_l_17b2;
	case 6072ULL: goto x86_l_17b8;
	case 6075ULL: goto x86_l_17bb;
	case 6079ULL: goto x86_l_17bf;
	case 6085ULL: goto x86_l_17c5;
	case 6091ULL: goto x86_l_17cb;
	case 6096ULL: goto x86_l_17d0;
	case 6102ULL: goto x86_l_17d6;
	case 6105ULL: goto x86_l_17d9;
	case 6109ULL: goto x86_l_17dd;
	case 6115ULL: goto x86_l_17e3;
	case 6121ULL: goto x86_l_17e9;
	case 6126ULL: goto x86_l_17ee;
	case 6132ULL: goto x86_l_17f4;
	case 6135ULL: goto x86_l_17f7;
	case 6139ULL: goto x86_l_17fb;
	case 6145ULL: goto x86_l_1801;
	case 6151ULL: goto x86_l_1807;
	case 6156ULL: goto x86_l_180c;
	case 6162ULL: goto x86_l_1812;
	case 6165ULL: goto x86_l_1815;
	case 6169ULL: goto x86_l_1819;
	case 6175ULL: goto x86_l_181f;
	case 6181ULL: goto x86_l_1825;
	case 6186ULL: goto x86_l_182a;
	case 6192ULL: goto x86_l_1830;
	case 6195ULL: goto x86_l_1833;
	case 6199ULL: goto x86_l_1837;
	case 6205ULL: goto x86_l_183d;
	case 6211ULL: goto x86_l_1843;
	case 6216ULL: goto x86_l_1848;
	case 6222ULL: goto x86_l_184e;
	case 6225ULL: goto x86_l_1851;
	case 6229ULL: goto x86_l_1855;
	case 6235ULL: goto x86_l_185b;
	case 6241ULL: goto x86_l_1861;
	case 6246ULL: goto x86_l_1866;
	case 6252ULL: goto x86_l_186c;
	case 6255ULL: goto x86_l_186f;
	case 6259ULL: goto x86_l_1873;
	case 6265ULL: goto x86_l_1879;
	case 6271ULL: goto x86_l_187f;
	case 6276ULL: goto x86_l_1884;
	case 6282ULL: goto x86_l_188a;
	case 6285ULL: goto x86_l_188d;
	case 6289ULL: goto x86_l_1891;
	case 6295ULL: goto x86_l_1897;
	case 6301ULL: goto x86_l_189d;
	case 6306ULL: goto x86_l_18a2;
	case 6312ULL: goto x86_l_18a8;
	case 6315ULL: goto x86_l_18ab;
	case 6319ULL: goto x86_l_18af;
	case 6325ULL: goto x86_l_18b5;
	case 6331ULL: goto x86_l_18bb;
	case 6336ULL: goto x86_l_18c0;
	case 6342ULL: goto x86_l_18c6;
	case 6345ULL: goto x86_l_18c9;
	case 6349ULL: goto x86_l_18cd;
	case 6355ULL: goto x86_l_18d3;
	case 6361ULL: goto x86_l_18d9;
	case 6366ULL: goto x86_l_18de;
	case 6372ULL: goto x86_l_18e4;
	case 6375ULL: goto x86_l_18e7;
	case 6379ULL: goto x86_l_18eb;
	case 6385ULL: goto x86_l_18f1;
	case 6391ULL: goto x86_l_18f7;
	case 6396ULL: goto x86_l_18fc;
	case 6402ULL: goto x86_l_1902;
	case 6405ULL: goto x86_l_1905;
	case 6409ULL: goto x86_l_1909;
	case 6415ULL: goto x86_l_190f;
	case 6421ULL: goto x86_l_1915;
	case 6426ULL: goto x86_l_191a;
	case 6432ULL: goto x86_l_1920;
	case 6435ULL: goto x86_l_1923;
	case 6439ULL: goto x86_l_1927;
	case 6445ULL: goto x86_l_192d;
	case 6451ULL: goto x86_l_1933;
	case 6456ULL: goto x86_l_1938;
	case 6462ULL: goto x86_l_193e;
	case 6465ULL: goto x86_l_1941;
	case 6469ULL: goto x86_l_1945;
	case 6475ULL: goto x86_l_194b;
	case 6481ULL: goto x86_l_1951;
	case 6486ULL: goto x86_l_1956;
	case 6492ULL: goto x86_l_195c;
	case 6495ULL: goto x86_l_195f;
	case 6499ULL: goto x86_l_1963;
	case 6505ULL: goto x86_l_1969;
	case 6511ULL: goto x86_l_196f;
	case 6516ULL: goto x86_l_1974;
	case 6522ULL: goto x86_l_197a;
	case 6525ULL: goto x86_l_197d;
	case 6529ULL: goto x86_l_1981;
	case 6535ULL: goto x86_l_1987;
	case 6541ULL: goto x86_l_198d;
	case 6546ULL: goto x86_l_1992;
	case 6552ULL: goto x86_l_1998;
	case 6555ULL: goto x86_l_199b;
	case 6559ULL: goto x86_l_199f;
	case 6565ULL: goto x86_l_19a5;
	case 6571ULL: goto x86_l_19ab;
	case 6576ULL: goto x86_l_19b0;
	case 6582ULL: goto x86_l_19b6;
	case 6585ULL: goto x86_l_19b9;
	case 6589ULL: goto x86_l_19bd;
	case 6595ULL: goto x86_l_19c3;
	case 6601ULL: goto x86_l_19c9;
	case 6606ULL: goto x86_l_19ce;
	case 6612ULL: goto x86_l_19d4;
	case 6615ULL: goto x86_l_19d7;
	case 6619ULL: goto x86_l_19db;
	case 6621ULL: goto x86_l_19dd;
	case 6627ULL: goto x86_l_19e3;
	case 6632ULL: goto x86_l_19e8;
	case 6638ULL: goto x86_l_19ee;
	case 6641ULL: goto x86_l_19f1;
	case 6645ULL: goto x86_l_19f5;
	case 6647ULL: goto x86_l_19f7;
	case 6653ULL: goto x86_l_19fd;
	case 6658ULL: goto x86_l_1a02;
	case 6664ULL: goto x86_l_1a08;
	case 6667ULL: goto x86_l_1a0b;
	case 6671ULL: goto x86_l_1a0f;
	case 6673ULL: goto x86_l_1a11;
	case 6679ULL: goto x86_l_1a17;
	case 6684ULL: goto x86_l_1a1c;
	case 6690ULL: goto x86_l_1a22;
	case 6693ULL: goto x86_l_1a25;
	case 6697ULL: goto x86_l_1a29;
	case 6699ULL: goto x86_l_1a2b;
	case 6705ULL: goto x86_l_1a31;
	case 6711ULL: goto x86_l_1a37;
	case 6717ULL: goto x86_l_1a3d;
	case 6720ULL: goto x86_l_1a40;
	case 6725ULL: goto x86_l_1a45;
	case 6730ULL: goto x86_l_1a4a;
	case 6735ULL: goto x86_l_1a4f;
	case 6740ULL: goto x86_l_1a54;
	case 6744ULL: goto x86_l_1a58;
	case 6747ULL: goto x86_l_1a5b;
	case 6751ULL: goto x86_l_1a5f;
	case 6759ULL: goto x86_l_1a67;
	case 6766ULL: goto x86_l_1a6e;
	case 6771ULL: goto x86_l_1a73;
	case 6776ULL: goto x86_l_1a78;
	case 6778ULL: goto x86_l_1a7a;
	case 6781ULL: goto x86_l_1a7d;
	case 6784ULL: goto x86_l_1a80;
	case 6787ULL: goto x86_l_1a83;
	case 6793ULL: goto x86_l_1a89;
	case 6796ULL: goto x86_l_1a8c;
	case 6802ULL: goto x86_l_1a92;
	case 6807ULL: goto x86_l_1a97;
	case 6814ULL: goto x86_l_1a9e;
	case 6819ULL: goto x86_l_1aa3;
	case 6824ULL: goto x86_l_1aa8;
	case 6826ULL: goto x86_l_1aaa;
	case 6829ULL: goto x86_l_1aad;
	case 6835ULL: goto x86_l_1ab3;
	case 6842ULL: goto x86_l_1aba;
	case 6847ULL: goto x86_l_1abf;
	case 6851ULL: goto x86_l_1ac3;
	case 6858ULL: goto x86_l_1aca;
	case 6860ULL: goto x86_l_1acc;
	case 6863ULL: goto x86_l_1acf;
	case 6867ULL: goto x86_l_1ad3;
	case 6870ULL: goto x86_l_1ad6;
	case 6875ULL: goto x86_l_1adb;
	case 6880ULL: goto x86_l_1ae0;
	case 6882ULL: goto x86_l_1ae2;
	case 6887ULL: goto x86_l_1ae7;
	case 6892ULL: goto x86_l_1aec;
	case 6895ULL: goto x86_l_1aef;
	case 6900ULL: goto x86_l_1af4;
	case 6908ULL: goto x86_l_1afc;
	case 6915ULL: goto x86_l_1b03;
	case 6921ULL: goto x86_l_1b09;
	case 6925ULL: goto x86_l_1b0d;
	case 6931ULL: goto x86_l_1b13;
	case 6934ULL: goto x86_l_1b16;
	case 6937ULL: goto x86_l_1b19;
	case 6940ULL: goto x86_l_1b1c;
	case 6943ULL: goto x86_l_1b1f;
	case 6945ULL: goto x86_l_1b21;
	case 6949ULL: goto x86_l_1b25;
	case 6955ULL: goto x86_l_1b2b;
	case 6957ULL: goto x86_l_1b2d;
	case 6963ULL: goto x86_l_1b33;
	case 6966ULL: goto x86_l_1b36;
	case 6971ULL: goto x86_l_1b3b;
	case 6975ULL: goto x86_l_1b3f;
	case 6980ULL: goto x86_l_1b44;
	case 6985ULL: goto x86_l_1b49;
	case 6990ULL: goto x86_l_1b4e;
	case 6994ULL: goto x86_l_1b52;
	case 6999ULL: goto x86_l_1b57;
	case 7003ULL: goto x86_l_1b5b;
	case 7008ULL: goto x86_l_1b60;
	case 7013ULL: goto x86_l_1b65;
	case 7015ULL: goto x86_l_1b67;
	case 7018ULL: goto x86_l_1b6a;
	case 7021ULL: goto x86_l_1b6d;
	case 7024ULL: goto x86_l_1b70;
	case 7026ULL: goto x86_l_1b72;
	case 7029ULL: goto x86_l_1b75;
	case 7031ULL: goto x86_l_1b77;
	case 7034ULL: goto x86_l_1b7a;
	case 7037ULL: goto x86_l_1b7d;
	case 7043ULL: goto x86_l_1b83;
	case 7046ULL: goto x86_l_1b86;
	case 7049ULL: goto x86_l_1b89;
	case 7055ULL: goto x86_l_1b8f;
	case 7060ULL: goto x86_l_1b94;
	case 7063ULL: goto x86_l_1b97;
	case 7065ULL: goto x86_l_1b99;
	case 7068ULL: goto x86_l_1b9c;
	case 7074ULL: goto x86_l_1ba2;
	case 7077ULL: goto x86_l_1ba5;
	case 7083ULL: goto x86_l_1bab;
	case 7086ULL: goto x86_l_1bae;
	case 7092ULL: goto x86_l_1bb4;
	case 7097ULL: goto x86_l_1bb9;
	case 7102ULL: goto x86_l_1bbe;
	case 7105ULL: goto x86_l_1bc1;
	case 7111ULL: goto x86_l_1bc7;
	case 7114ULL: goto x86_l_1bca;
	case 7120ULL: goto x86_l_1bd0;
	case 7123ULL: goto x86_l_1bd3;
	case 7129ULL: goto x86_l_1bd9;
	case 7134ULL: goto x86_l_1bde;
	case 7137ULL: goto x86_l_1be1;
	case 7140ULL: goto x86_l_1be4;
	case 7146ULL: goto x86_l_1bea;
	case 7154ULL: goto x86_l_1bf2;
	case 7161ULL: goto x86_l_1bf9;
	case 7167ULL: goto x86_l_1bff;
	case 7170ULL: goto x86_l_1c02;
	case 7175ULL: goto x86_l_1c07;
	case 7178ULL: goto x86_l_1c0a;
	case 7184ULL: goto x86_l_1c10;
	case 7187ULL: goto x86_l_1c13;
	case 7193ULL: goto x86_l_1c19;
	case 7196ULL: goto x86_l_1c1c;
	case 7202ULL: goto x86_l_1c22;
	case 7207ULL: goto x86_l_1c27;
	case 7212ULL: goto x86_l_1c2c;
	case 7216ULL: goto x86_l_1c30;
	case 7219ULL: goto x86_l_1c33;
	case 7223ULL: goto x86_l_1c37;
	case 7231ULL: goto x86_l_1c3f;
	case 7238ULL: goto x86_l_1c46;
	case 7243ULL: goto x86_l_1c4b;
	case 7248ULL: goto x86_l_1c50;
	case 7250ULL: goto x86_l_1c52;
	case 7253ULL: goto x86_l_1c55;
	case 7256ULL: goto x86_l_1c58;
	case 7259ULL: goto x86_l_1c5b;
	case 7265ULL: goto x86_l_1c61;
	case 7270ULL: goto x86_l_1c66;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1545:
	/* 0x1545: cmp    rdx,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 51ULL);
x86_l_1549:
	/* 0x1549: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_154f:
	/* 0x154f: lea    eax,[rdx+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_1555:
	/* 0x1555: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_155a:
	/* 0x155a: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1560:
	/* 0x1560: mov    BYTE PTR [rsi+0x37],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_1563:
	/* 0x1563: cmp    rdx,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 52ULL);
x86_l_1567:
	/* 0x1567: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_156d:
	/* 0x156d: lea    eax,[rdx+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_1573:
	/* 0x1573: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1578:
	/* 0x1578: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_157e:
	/* 0x157e: mov    BYTE PTR [rsi+0x38],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1581:
	/* 0x1581: cmp    rdx,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 53ULL);
x86_l_1585:
	/* 0x1585: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_158b:
	/* 0x158b: lea    eax,[rdx+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_1591:
	/* 0x1591: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1596:
	/* 0x1596: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_159c:
	/* 0x159c: mov    BYTE PTR [rsi+0x39],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_159f:
	/* 0x159f: cmp    rdx,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 54ULL);
x86_l_15a3:
	/* 0x15a3: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_15a9:
	/* 0x15a9: lea    eax,[rdx+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_15af:
	/* 0x15af: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15b4:
	/* 0x15b4: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_15ba:
	/* 0x15ba: mov    BYTE PTR [rsi+0x3a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_15bd:
	/* 0x15bd: cmp    rdx,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 55ULL);
x86_l_15c1:
	/* 0x15c1: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_15c7:
	/* 0x15c7: lea    eax,[rdx+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_15cd:
	/* 0x15cd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15d2:
	/* 0x15d2: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_15d8:
	/* 0x15d8: mov    BYTE PTR [rsi+0x3b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_15db:
	/* 0x15db: cmp    rdx,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 56ULL);
x86_l_15df:
	/* 0x15df: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_15e5:
	/* 0x15e5: lea    eax,[rdx+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_15eb:
	/* 0x15eb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15f0:
	/* 0x15f0: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_15f6:
	/* 0x15f6: mov    BYTE PTR [rsi+0x3c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_15f9:
	/* 0x15f9: cmp    rdx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 57ULL);
x86_l_15fd:
	/* 0x15fd: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_1603:
	/* 0x1603: lea    eax,[rdx+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_1609:
	/* 0x1609: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_160e:
	/* 0x160e: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1614:
	/* 0x1614: mov    BYTE PTR [rsi+0x3d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_1617:
	/* 0x1617: cmp    rdx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 58ULL);
x86_l_161b:
	/* 0x161b: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_1621:
	/* 0x1621: lea    eax,[rdx+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_1627:
	/* 0x1627: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_162c:
	/* 0x162c: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1632:
	/* 0x1632: mov    BYTE PTR [rsi+0x3e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_1635:
	/* 0x1635: cmp    rdx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 59ULL);
x86_l_1639:
	/* 0x1639: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_163f:
	/* 0x163f: lea    eax,[rdx+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_1645:
	/* 0x1645: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_164a:
	/* 0x164a: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1650:
	/* 0x1650: mov    BYTE PTR [rsi+0x3f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_1653:
	/* 0x1653: cmp    rdx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 60ULL);
x86_l_1657:
	/* 0x1657: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_165d:
	/* 0x165d: lea    eax,[rdx+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_1663:
	/* 0x1663: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1668:
	/* 0x1668: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_166e:
	/* 0x166e: mov    BYTE PTR [rsi+0x40],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1671:
	/* 0x1671: cmp    rdx,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 61ULL);
x86_l_1675:
	/* 0x1675: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_167b:
	/* 0x167b: lea    eax,[rdx+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_1681:
	/* 0x1681: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1686:
	/* 0x1686: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_168c:
	/* 0x168c: mov    BYTE PTR [rsi+0x41],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_168f:
	/* 0x168f: cmp    rdx,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 62ULL);
x86_l_1693:
	/* 0x1693: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_1699:
	/* 0x1699: lea    eax,[rdx+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_169f:
	/* 0x169f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16a4:
	/* 0x16a4: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_16aa:
	/* 0x16aa: mov    BYTE PTR [rsi+0x42],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_16ad:
	/* 0x16ad: cmp    rdx,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 63ULL);
x86_l_16b1:
	/* 0x16b1: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_16b7:
	/* 0x16b7: lea    eax,[rdx+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_16bd:
	/* 0x16bd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16c2:
	/* 0x16c2: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_16c8:
	/* 0x16c8: mov    BYTE PTR [rsi+0x43],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_16cb:
	/* 0x16cb: cmp    rdx,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 64ULL);
x86_l_16cf:
	/* 0x16cf: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_16d5:
	/* 0x16d5: lea    eax,[rdx+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_16db:
	/* 0x16db: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16e0:
	/* 0x16e0: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_16e6:
	/* 0x16e6: mov    BYTE PTR [rsi+0x44],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_16e9:
	/* 0x16e9: cmp    rdx,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 65ULL);
x86_l_16ed:
	/* 0x16ed: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_16f3:
	/* 0x16f3: lea    eax,[rdx+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_16f9:
	/* 0x16f9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16fe:
	/* 0x16fe: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1704:
	/* 0x1704: mov    BYTE PTR [rsi+0x45],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_1707:
	/* 0x1707: cmp    rdx,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 66ULL);
x86_l_170b:
	/* 0x170b: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_1711:
	/* 0x1711: lea    eax,[rdx+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_1717:
	/* 0x1717: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_171c:
	/* 0x171c: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1722:
	/* 0x1722: mov    BYTE PTR [rsi+0x46],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_1725:
	/* 0x1725: cmp    rdx,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 67ULL);
x86_l_1729:
	/* 0x1729: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_172f:
	/* 0x172f: lea    eax,[rdx+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_1735:
	/* 0x1735: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_173a:
	/* 0x173a: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1740:
	/* 0x1740: mov    BYTE PTR [rsi+0x47],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_1743:
	/* 0x1743: cmp    rdx,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 68ULL);
x86_l_1747:
	/* 0x1747: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_174d:
	/* 0x174d: lea    eax,[rdx+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_1753:
	/* 0x1753: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1758:
	/* 0x1758: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_175e:
	/* 0x175e: mov    BYTE PTR [rsi+0x48],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1761:
	/* 0x1761: cmp    rdx,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 69ULL);
x86_l_1765:
	/* 0x1765: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_176b:
	/* 0x176b: lea    eax,[rdx+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_1771:
	/* 0x1771: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1776:
	/* 0x1776: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_177c:
	/* 0x177c: mov    BYTE PTR [rsi+0x49],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_177f:
	/* 0x177f: cmp    rdx,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 70ULL);
x86_l_1783:
	/* 0x1783: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_1789:
	/* 0x1789: lea    eax,[rdx+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_178f:
	/* 0x178f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1794:
	/* 0x1794: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_179a:
	/* 0x179a: mov    BYTE PTR [rsi+0x4a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_179d:
	/* 0x179d: cmp    rdx,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 71ULL);
x86_l_17a1:
	/* 0x17a1: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_17a7:
	/* 0x17a7: lea    eax,[rdx+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_17ad:
	/* 0x17ad: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17b2:
	/* 0x17b2: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_17b8:
	/* 0x17b8: mov    BYTE PTR [rsi+0x4b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_17bb:
	/* 0x17bb: cmp    rdx,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 72ULL);
x86_l_17bf:
	/* 0x17bf: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_17c5:
	/* 0x17c5: lea    eax,[rdx+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_17cb:
	/* 0x17cb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17d0:
	/* 0x17d0: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_17d6:
	/* 0x17d6: mov    BYTE PTR [rsi+0x4c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_17d9:
	/* 0x17d9: cmp    rdx,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 73ULL);
x86_l_17dd:
	/* 0x17dd: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_17e3:
	/* 0x17e3: lea    eax,[rdx+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_17e9:
	/* 0x17e9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17ee:
	/* 0x17ee: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_17f4:
	/* 0x17f4: mov    BYTE PTR [rsi+0x4d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_17f7:
	/* 0x17f7: cmp    rdx,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 74ULL);
x86_l_17fb:
	/* 0x17fb: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_1801:
	/* 0x1801: lea    eax,[rdx+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_1807:
	/* 0x1807: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_180c:
	/* 0x180c: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1812:
	/* 0x1812: mov    BYTE PTR [rsi+0x4e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_1815:
	/* 0x1815: cmp    rdx,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 75ULL);
x86_l_1819:
	/* 0x1819: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_181f:
	/* 0x181f: lea    eax,[rdx+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_1825:
	/* 0x1825: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_182a:
	/* 0x182a: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1830:
	/* 0x1830: mov    BYTE PTR [rsi+0x4f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_1833:
	/* 0x1833: cmp    rdx,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 76ULL);
x86_l_1837:
	/* 0x1837: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_183d:
	/* 0x183d: lea    eax,[rdx+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_1843:
	/* 0x1843: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1848:
	/* 0x1848: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_184e:
	/* 0x184e: mov    BYTE PTR [rsi+0x50],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1851:
	/* 0x1851: cmp    rdx,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 77ULL);
x86_l_1855:
	/* 0x1855: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_185b:
	/* 0x185b: lea    eax,[rdx+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_1861:
	/* 0x1861: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1866:
	/* 0x1866: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_186c:
	/* 0x186c: mov    BYTE PTR [rsi+0x51],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_186f:
	/* 0x186f: cmp    rdx,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 78ULL);
x86_l_1873:
	/* 0x1873: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_1879:
	/* 0x1879: lea    eax,[rdx+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_187f:
	/* 0x187f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1884:
	/* 0x1884: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_188a:
	/* 0x188a: mov    BYTE PTR [rsi+0x52],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_188d:
	/* 0x188d: cmp    rdx,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 79ULL);
x86_l_1891:
	/* 0x1891: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_1897:
	/* 0x1897: lea    eax,[rdx+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_189d:
	/* 0x189d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18a2:
	/* 0x18a2: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_18a8:
	/* 0x18a8: mov    BYTE PTR [rsi+0x53],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_18ab:
	/* 0x18ab: cmp    rdx,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 80ULL);
x86_l_18af:
	/* 0x18af: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_18b5:
	/* 0x18b5: lea    eax,[rdx+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_18bb:
	/* 0x18bb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18c0:
	/* 0x18c0: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_18c6:
	/* 0x18c6: mov    BYTE PTR [rsi+0x54],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_18c9:
	/* 0x18c9: cmp    rdx,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 81ULL);
x86_l_18cd:
	/* 0x18cd: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_18d3:
	/* 0x18d3: lea    eax,[rdx+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_18d9:
	/* 0x18d9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18de:
	/* 0x18de: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_18e4:
	/* 0x18e4: mov    BYTE PTR [rsi+0x55],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_18e7:
	/* 0x18e7: cmp    rdx,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 82ULL);
x86_l_18eb:
	/* 0x18eb: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_18f1:
	/* 0x18f1: lea    eax,[rdx+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_18f7:
	/* 0x18f7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18fc:
	/* 0x18fc: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1902:
	/* 0x1902: mov    BYTE PTR [rsi+0x56],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1905:
	/* 0x1905: cmp    rdx,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 83ULL);
x86_l_1909:
	/* 0x1909: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_190f:
	/* 0x190f: lea    eax,[rdx+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_1915:
	/* 0x1915: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_191a:
	/* 0x191a: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1920:
	/* 0x1920: mov    BYTE PTR [rsi+0x57],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_1923:
	/* 0x1923: cmp    rdx,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 84ULL);
x86_l_1927:
	/* 0x1927: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_192d:
	/* 0x192d: lea    eax,[rdx+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_1933:
	/* 0x1933: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1938:
	/* 0x1938: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_193e:
	/* 0x193e: mov    BYTE PTR [rsi+0x58],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1941:
	/* 0x1941: cmp    rdx,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 85ULL);
x86_l_1945:
	/* 0x1945: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_194b:
	/* 0x194b: lea    eax,[rdx+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_1951:
	/* 0x1951: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1956:
	/* 0x1956: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_195c:
	/* 0x195c: mov    BYTE PTR [rsi+0x59],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_195f:
	/* 0x195f: cmp    rdx,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 86ULL);
x86_l_1963:
	/* 0x1963: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_1969:
	/* 0x1969: lea    eax,[rdx+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_196f:
	/* 0x196f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1974:
	/* 0x1974: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_197a:
	/* 0x197a: mov    BYTE PTR [rsi+0x5a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_197d:
	/* 0x197d: cmp    rdx,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 87ULL);
x86_l_1981:
	/* 0x1981: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_1987:
	/* 0x1987: lea    eax,[rdx+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_198d:
	/* 0x198d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1992:
	/* 0x1992: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1998:
	/* 0x1998: mov    BYTE PTR [rsi+0x5b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_199b:
	/* 0x199b: cmp    rdx,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 88ULL);
x86_l_199f:
	/* 0x199f: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_19a5:
	/* 0x19a5: lea    eax,[rdx+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_19ab:
	/* 0x19ab: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19b0:
	/* 0x19b0: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_19b6:
	/* 0x19b6: mov    BYTE PTR [rsi+0x5c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_19b9:
	/* 0x19b9: cmp    rdx,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 89ULL);
x86_l_19bd:
	/* 0x19bd: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_19c3:
	/* 0x19c3: lea    eax,[rdx+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_19c9:
	/* 0x19c9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19ce:
	/* 0x19ce: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_19d4:
	/* 0x19d4: mov    BYTE PTR [rsi+0x5d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_19d7:
	/* 0x19d7: cmp    rdx,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 90ULL);
x86_l_19db:
	/* 0x19db: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_19dd:
	/* 0x19dd: lea    eax,[rdx+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_19e3:
	/* 0x19e3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19e8:
	/* 0x19e8: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_19ee:
	/* 0x19ee: mov    BYTE PTR [rsi+0x5e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_19f1:
	/* 0x19f1: cmp    rdx,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 91ULL);
x86_l_19f5:
	/* 0x19f5: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_19f7:
	/* 0x19f7: lea    eax,[rdx+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_19fd:
	/* 0x19fd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a02:
	/* 0x1a02: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a08:
	/* 0x1a08: mov    BYTE PTR [rsi+0x5f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_1a0b:
	/* 0x1a0b: cmp    rdx,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 92ULL);
x86_l_1a0f:
	/* 0x1a0f: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_1a11:
	/* 0x1a11: lea    eax,[rdx+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_1a17:
	/* 0x1a17: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a1c:
	/* 0x1a1c: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a22:
	/* 0x1a22: mov    BYTE PTR [rsi+0x60],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a25:
	/* 0x1a25: cmp    rdx,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 93ULL);
x86_l_1a29:
	/* 0x1a29: je     1a40 <generic_usdt_filter_arg_2+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a40;
	}
x86_l_1a2b:
	/* 0x1a2b: add    edx,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_1a31:
	/* 0x1a31: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a37:
	/* 0x1a37: movzx  eax,BYTE PTR [r13+rdx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_8), 0ULL);
x86_l_1a3d:
	/* 0x1a3d: mov    BYTE PTR [rsi+0x61],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_1a40:
	/* 0x1a40: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a45:
	/* 0x1a45: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a4a:
	/* 0x1a4a: jmp    31ef <generic_usdt_filter_arg_2+0x31ef> */
	return 12783ULL;
x86_l_1a4f:
	/* 0x1a4f: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a54:
	/* 0x1a54: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a58:
	/* 0x1a58: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a5b:
	/* 0x1a5b: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a5f:
	/* 0x1a5f: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1a67:
	/* 0x1a67: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1a6e:
	/* 0x1a6e: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a73:
	/* 0x1a73: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a78:
	/* 0x1a78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a7a:
	/* 0x1a7a: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1a7d:
	/* 0x1a7d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a80:
	/* 0x1a80: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1a83:
	/* 0x1a83: je     3200 <generic_usdt_filter_arg_2+0x3200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12800ULL;
	}
x86_l_1a89:
	/* 0x1a89: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a8c:
	/* 0x1a8c: je     3200 <generic_usdt_filter_arg_2+0x3200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12800ULL;
	}
x86_l_1a92:
	/* 0x1a92: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a97:
	/* 0x1a97: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_1a9e:
	/* 0x1a9e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1aa3:
	/* 0x1aa3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1aa8:
	/* 0x1aa8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aaa:
	/* 0x1aaa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1aad:
	/* 0x1aad: je     31fd <generic_usdt_filter_arg_2+0x31fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12797ULL;
	}
x86_l_1ab3:
	/* 0x1ab3: cmp    r13d,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 255ULL);
x86_l_1aba:
	/* 0x1aba: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_1abf:
	/* 0x1abf: cmovb  esi,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_1ac3:
	/* 0x1ac3: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_1aca:
	/* 0x1aca: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1acc:
	/* 0x1acc: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1acf:
	/* 0x1acf: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1ad3:
	/* 0x1ad3: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1ad6:
	/* 0x1ad6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1adb:
	/* 0x1adb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ae0:
	/* 0x1ae0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae2:
	/* 0x1ae2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ae7:
	/* 0x1ae7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aec:
	/* 0x1aec: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1aef:
	/* 0x1aef: jmp    31ef <generic_usdt_filter_arg_2+0x31ef> */
	return 12783ULL;
x86_l_1af4:
	/* 0x1af4: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1afc:
	/* 0x1afc: cmp    r13d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 144ULL);
x86_l_1b03:
	/* 0x1b03: ja     2c67 <generic_usdt_filter_arg_2+0x2c67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11367ULL;
	}
x86_l_1b09:
	/* 0x1b09: movzx  eax,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b0d:
	/* 0x1b0d: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1b13:
	/* 0x1b13: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1b16:
	/* 0x1b16: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1b19:
	/* 0x1b19: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1b1c:
	/* 0x1b1c: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_1b1f:
	/* 0x1b1f: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1b21:
	/* 0x1b21: test   r13w,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_16);
x86_l_1b25:
	/* 0x1b25: je     2b39 <generic_usdt_filter_arg_2+0x2b39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11065ULL;
	}
x86_l_1b2b:
	/* 0x1b2b: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1b2d:
	/* 0x1b2d: jne    2b39 <generic_usdt_filter_arg_2+0x2b39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11065ULL;
	}
x86_l_1b33:
	/* 0x1b33: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_1b36:
	/* 0x1b36: jmp    2b51 <generic_usdt_filter_arg_2+0x2b51> */
	return 11089ULL;
x86_l_1b3b:
	/* 0x1b3b: movzx  eax,WORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b3f:
	/* 0x1b3f: mov    WORD PTR [rsp+0x76],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 118ULL);
x86_l_1b44:
	/* 0x1b44: movzx  eax,WORD PTR [r8+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1b49:
	/* 0x1b49: mov    WORD PTR [rsp+0x70],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1b4e:
	/* 0x1b4e: mov    rax,QWORD PTR [r8+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b52:
	/* 0x1b52: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b57:
	/* 0x1b57: mov    rax,QWORD PTR [r8+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b5b:
	/* 0x1b5b: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b60:
	/* 0x1b60: lea    r8,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b65:
	/* 0x1b65: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b67:
	/* 0x1b67: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b6a:
	/* 0x1b6a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b6d:
	/* 0x1b6d: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_1b70:
	/* 0x1b70: jle    1b94 <generic_usdt_filter_arg_2+0x1b94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1b94;
	}
x86_l_1b72:
	/* 0x1b72: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_1b75:
	/* 0x1b75: jg     1bbe <generic_usdt_filter_arg_2+0x1bbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1bbe;
	}
x86_l_1b77:
	/* 0x1b77: lea    ecx,[rax-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_1b7a:
	/* 0x1b7a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b7d:
	/* 0x1b7d: jb     27fc <generic_usdt_filter_arg_2+0x27fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10236ULL;
	}
x86_l_1b83:
	/* 0x1b83: lea    ecx,[rax-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_1b86:
	/* 0x1b86: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b89:
	/* 0x1b89: jb     27f5 <generic_usdt_filter_arg_2+0x27f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10229ULL;
	}
x86_l_1b8f:
	/* 0x1b8f: jmp    3222 <generic_usdt_filter_arg_2+0x3222> */
	return 12834ULL;
x86_l_1b94:
	/* 0x1b94: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1b97:
	/* 0x1b97: jle    1c07 <generic_usdt_filter_arg_2+0x1c07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1c07;
	}
x86_l_1b99:
	/* 0x1b99: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1b9c:
	/* 0x1b9c: jg     27e7 <generic_usdt_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10215ULL;
	}
x86_l_1ba2:
	/* 0x1ba2: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1ba5:
	/* 0x1ba5: je     27f5 <generic_usdt_filter_arg_2+0x27f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10229ULL;
	}
x86_l_1bab:
	/* 0x1bab: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1bae:
	/* 0x1bae: jne    3222 <generic_usdt_filter_arg_2+0x3222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12834ULL;
	}
x86_l_1bb4:
	/* 0x1bb4: movzx  r12d,WORD PTR [r8+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1bb9:
	/* 0x1bb9: jmp    2c74 <generic_usdt_filter_arg_2+0x2c74> */
	return 11380ULL;
x86_l_1bbe:
	/* 0x1bbe: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1bc1:
	/* 0x1bc1: jg     280b <generic_usdt_filter_arg_2+0x280b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10251ULL;
	}
x86_l_1bc7:
	/* 0x1bc7: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_1bca:
	/* 0x1bca: je     2841 <generic_usdt_filter_arg_2+0x2841> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10305ULL;
	}
x86_l_1bd0:
	/* 0x1bd0: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1bd3:
	/* 0x1bd3: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1bd9:
	/* 0x1bd9: jmp    3222 <generic_usdt_filter_arg_2+0x3222> */
	return 12834ULL;
x86_l_1bde:
	/* 0x1bde: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1be1:
	/* 0x1be1: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1be4:
	/* 0x1be4: jae    2aff <generic_usdt_filter_arg_2+0x2aff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11007ULL;
	}
x86_l_1bea:
	/* 0x1bea: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1bf2:
	/* 0x1bf2: cmp    r13d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 144ULL);
x86_l_1bf9:
	/* 0x1bf9: jbe    2b07 <generic_usdt_filter_arg_2+0x2b07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11015ULL;
	}
x86_l_1bff:
	/* 0x1bff: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c02:
	/* 0x1c02: jmp    3165 <generic_usdt_filter_arg_2+0x3165> */
	return 12645ULL;
x86_l_1c07:
	/* 0x1c07: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1c0a:
	/* 0x1c0a: je     2841 <generic_usdt_filter_arg_2+0x2841> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10305ULL;
	}
x86_l_1c10:
	/* 0x1c10: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1c13:
	/* 0x1c13: je     2837 <generic_usdt_filter_arg_2+0x2837> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10295ULL;
	}
x86_l_1c19:
	/* 0x1c19: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1c1c:
	/* 0x1c1c: je     27fc <generic_usdt_filter_arg_2+0x27fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10236ULL;
	}
x86_l_1c22:
	/* 0x1c22: jmp    3222 <generic_usdt_filter_arg_2+0x3222> */
	return 12834ULL;
x86_l_1c27:
	/* 0x1c27: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c2c:
	/* 0x1c2c: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c30:
	/* 0x1c30: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c33:
	/* 0x1c33: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1c37:
	/* 0x1c37: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1c3f:
	/* 0x1c3f: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_1c46:
	/* 0x1c46: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1c4b:
	/* 0x1c4b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c50:
	/* 0x1c50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c52:
	/* 0x1c52: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1c55:
	/* 0x1c55: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c58:
	/* 0x1c58: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1c5b:
	/* 0x1c5b: je     3161 <generic_usdt_filter_arg_2+0x3161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12641ULL;
	}
x86_l_1c61:
	/* 0x1c61: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c66:
	/* 0x1c66: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 7273ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7273ULL: goto x86_l_1c69;
	case 7279ULL: goto x86_l_1c6f;
	case 7286ULL: goto x86_l_1c76;
	case 7291ULL: goto x86_l_1c7b;
	case 7296ULL: goto x86_l_1c80;
	case 7298ULL: goto x86_l_1c82;
	case 7301ULL: goto x86_l_1c85;
	case 7307ULL: goto x86_l_1c8b;
	case 7310ULL: goto x86_l_1c8e;
	case 7315ULL: goto x86_l_1c93;
	case 7319ULL: goto x86_l_1c97;
	case 7323ULL: goto x86_l_1c9b;
	case 7328ULL: goto x86_l_1ca0;
	case 7332ULL: goto x86_l_1ca4;
	case 7335ULL: goto x86_l_1ca7;
	case 7337ULL: goto x86_l_1ca9;
	case 7341ULL: goto x86_l_1cad;
	case 7346ULL: goto x86_l_1cb2;
	case 7350ULL: goto x86_l_1cb6;
	case 7353ULL: goto x86_l_1cb9;
	case 7357ULL: goto x86_l_1cbd;
	case 7363ULL: goto x86_l_1cc3;
	case 7370ULL: goto x86_l_1cca;
	case 7375ULL: goto x86_l_1ccf;
	case 7379ULL: goto x86_l_1cd3;
	case 7382ULL: goto x86_l_1cd6;
	case 7386ULL: goto x86_l_1cda;
	case 7392ULL: goto x86_l_1ce0;
	case 7399ULL: goto x86_l_1ce7;
	case 7404ULL: goto x86_l_1cec;
	case 7408ULL: goto x86_l_1cf0;
	case 7411ULL: goto x86_l_1cf3;
	case 7415ULL: goto x86_l_1cf7;
	case 7421ULL: goto x86_l_1cfd;
	case 7428ULL: goto x86_l_1d04;
	case 7433ULL: goto x86_l_1d09;
	case 7437ULL: goto x86_l_1d0d;
	case 7440ULL: goto x86_l_1d10;
	case 7444ULL: goto x86_l_1d14;
	case 7450ULL: goto x86_l_1d1a;
	case 7457ULL: goto x86_l_1d21;
	case 7462ULL: goto x86_l_1d26;
	case 7466ULL: goto x86_l_1d2a;
	case 7469ULL: goto x86_l_1d2d;
	case 7473ULL: goto x86_l_1d31;
	case 7479ULL: goto x86_l_1d37;
	case 7486ULL: goto x86_l_1d3e;
	case 7491ULL: goto x86_l_1d43;
	case 7495ULL: goto x86_l_1d47;
	case 7498ULL: goto x86_l_1d4a;
	case 7502ULL: goto x86_l_1d4e;
	case 7508ULL: goto x86_l_1d54;
	case 7515ULL: goto x86_l_1d5b;
	case 7520ULL: goto x86_l_1d60;
	case 7524ULL: goto x86_l_1d64;
	case 7527ULL: goto x86_l_1d67;
	case 7531ULL: goto x86_l_1d6b;
	case 7537ULL: goto x86_l_1d71;
	case 7544ULL: goto x86_l_1d78;
	case 7549ULL: goto x86_l_1d7d;
	case 7553ULL: goto x86_l_1d81;
	case 7556ULL: goto x86_l_1d84;
	case 7560ULL: goto x86_l_1d88;
	case 7566ULL: goto x86_l_1d8e;
	case 7573ULL: goto x86_l_1d95;
	case 7578ULL: goto x86_l_1d9a;
	case 7582ULL: goto x86_l_1d9e;
	case 7585ULL: goto x86_l_1da1;
	case 7589ULL: goto x86_l_1da5;
	case 7595ULL: goto x86_l_1dab;
	case 7602ULL: goto x86_l_1db2;
	case 7607ULL: goto x86_l_1db7;
	case 7611ULL: goto x86_l_1dbb;
	case 7614ULL: goto x86_l_1dbe;
	case 7618ULL: goto x86_l_1dc2;
	case 7624ULL: goto x86_l_1dc8;
	case 7631ULL: goto x86_l_1dcf;
	case 7636ULL: goto x86_l_1dd4;
	case 7640ULL: goto x86_l_1dd8;
	case 7643ULL: goto x86_l_1ddb;
	case 7647ULL: goto x86_l_1ddf;
	case 7653ULL: goto x86_l_1de5;
	case 7660ULL: goto x86_l_1dec;
	case 7665ULL: goto x86_l_1df1;
	case 7669ULL: goto x86_l_1df5;
	case 7672ULL: goto x86_l_1df8;
	case 7676ULL: goto x86_l_1dfc;
	case 7682ULL: goto x86_l_1e02;
	case 7689ULL: goto x86_l_1e09;
	case 7694ULL: goto x86_l_1e0e;
	case 7698ULL: goto x86_l_1e12;
	case 7701ULL: goto x86_l_1e15;
	case 7705ULL: goto x86_l_1e19;
	case 7711ULL: goto x86_l_1e1f;
	case 7718ULL: goto x86_l_1e26;
	case 7723ULL: goto x86_l_1e2b;
	case 7727ULL: goto x86_l_1e2f;
	case 7730ULL: goto x86_l_1e32;
	case 7734ULL: goto x86_l_1e36;
	case 7740ULL: goto x86_l_1e3c;
	case 7747ULL: goto x86_l_1e43;
	case 7752ULL: goto x86_l_1e48;
	case 7756ULL: goto x86_l_1e4c;
	case 7759ULL: goto x86_l_1e4f;
	case 7763ULL: goto x86_l_1e53;
	case 7769ULL: goto x86_l_1e59;
	case 7776ULL: goto x86_l_1e60;
	case 7781ULL: goto x86_l_1e65;
	case 7785ULL: goto x86_l_1e69;
	case 7788ULL: goto x86_l_1e6c;
	case 7792ULL: goto x86_l_1e70;
	case 7798ULL: goto x86_l_1e76;
	case 7805ULL: goto x86_l_1e7d;
	case 7810ULL: goto x86_l_1e82;
	case 7814ULL: goto x86_l_1e86;
	case 7817ULL: goto x86_l_1e89;
	case 7821ULL: goto x86_l_1e8d;
	case 7827ULL: goto x86_l_1e93;
	case 7834ULL: goto x86_l_1e9a;
	case 7839ULL: goto x86_l_1e9f;
	case 7843ULL: goto x86_l_1ea3;
	case 7846ULL: goto x86_l_1ea6;
	case 7850ULL: goto x86_l_1eaa;
	case 7856ULL: goto x86_l_1eb0;
	case 7863ULL: goto x86_l_1eb7;
	case 7868ULL: goto x86_l_1ebc;
	case 7872ULL: goto x86_l_1ec0;
	case 7875ULL: goto x86_l_1ec3;
	case 7879ULL: goto x86_l_1ec7;
	case 7885ULL: goto x86_l_1ecd;
	case 7892ULL: goto x86_l_1ed4;
	case 7897ULL: goto x86_l_1ed9;
	case 7901ULL: goto x86_l_1edd;
	case 7904ULL: goto x86_l_1ee0;
	case 7908ULL: goto x86_l_1ee4;
	case 7914ULL: goto x86_l_1eea;
	case 7921ULL: goto x86_l_1ef1;
	case 7926ULL: goto x86_l_1ef6;
	case 7930ULL: goto x86_l_1efa;
	case 7933ULL: goto x86_l_1efd;
	case 7937ULL: goto x86_l_1f01;
	case 7943ULL: goto x86_l_1f07;
	case 7950ULL: goto x86_l_1f0e;
	case 7955ULL: goto x86_l_1f13;
	case 7959ULL: goto x86_l_1f17;
	case 7962ULL: goto x86_l_1f1a;
	case 7966ULL: goto x86_l_1f1e;
	case 7972ULL: goto x86_l_1f24;
	case 7979ULL: goto x86_l_1f2b;
	case 7984ULL: goto x86_l_1f30;
	case 7988ULL: goto x86_l_1f34;
	case 7991ULL: goto x86_l_1f37;
	case 7995ULL: goto x86_l_1f3b;
	case 8001ULL: goto x86_l_1f41;
	case 8008ULL: goto x86_l_1f48;
	case 8013ULL: goto x86_l_1f4d;
	case 8017ULL: goto x86_l_1f51;
	case 8020ULL: goto x86_l_1f54;
	case 8024ULL: goto x86_l_1f58;
	case 8030ULL: goto x86_l_1f5e;
	case 8037ULL: goto x86_l_1f65;
	case 8042ULL: goto x86_l_1f6a;
	case 8046ULL: goto x86_l_1f6e;
	case 8049ULL: goto x86_l_1f71;
	case 8053ULL: goto x86_l_1f75;
	case 8059ULL: goto x86_l_1f7b;
	case 8066ULL: goto x86_l_1f82;
	case 8071ULL: goto x86_l_1f87;
	case 8075ULL: goto x86_l_1f8b;
	case 8078ULL: goto x86_l_1f8e;
	case 8082ULL: goto x86_l_1f92;
	case 8088ULL: goto x86_l_1f98;
	case 8095ULL: goto x86_l_1f9f;
	case 8100ULL: goto x86_l_1fa4;
	case 8104ULL: goto x86_l_1fa8;
	case 8107ULL: goto x86_l_1fab;
	case 8111ULL: goto x86_l_1faf;
	case 8117ULL: goto x86_l_1fb5;
	case 8124ULL: goto x86_l_1fbc;
	case 8129ULL: goto x86_l_1fc1;
	case 8133ULL: goto x86_l_1fc5;
	case 8136ULL: goto x86_l_1fc8;
	case 8140ULL: goto x86_l_1fcc;
	case 8146ULL: goto x86_l_1fd2;
	case 8153ULL: goto x86_l_1fd9;
	case 8158ULL: goto x86_l_1fde;
	case 8162ULL: goto x86_l_1fe2;
	case 8165ULL: goto x86_l_1fe5;
	case 8169ULL: goto x86_l_1fe9;
	case 8175ULL: goto x86_l_1fef;
	case 8182ULL: goto x86_l_1ff6;
	case 8187ULL: goto x86_l_1ffb;
	case 8191ULL: goto x86_l_1fff;
	case 8194ULL: goto x86_l_2002;
	case 8198ULL: goto x86_l_2006;
	case 8204ULL: goto x86_l_200c;
	case 8211ULL: goto x86_l_2013;
	case 8216ULL: goto x86_l_2018;
	case 8220ULL: goto x86_l_201c;
	case 8223ULL: goto x86_l_201f;
	case 8227ULL: goto x86_l_2023;
	case 8233ULL: goto x86_l_2029;
	case 8240ULL: goto x86_l_2030;
	case 8245ULL: goto x86_l_2035;
	case 8249ULL: goto x86_l_2039;
	case 8252ULL: goto x86_l_203c;
	case 8256ULL: goto x86_l_2040;
	case 8262ULL: goto x86_l_2046;
	case 8269ULL: goto x86_l_204d;
	case 8274ULL: goto x86_l_2052;
	case 8278ULL: goto x86_l_2056;
	case 8281ULL: goto x86_l_2059;
	case 8285ULL: goto x86_l_205d;
	case 8291ULL: goto x86_l_2063;
	case 8298ULL: goto x86_l_206a;
	case 8303ULL: goto x86_l_206f;
	case 8307ULL: goto x86_l_2073;
	case 8310ULL: goto x86_l_2076;
	case 8314ULL: goto x86_l_207a;
	case 8320ULL: goto x86_l_2080;
	case 8327ULL: goto x86_l_2087;
	case 8332ULL: goto x86_l_208c;
	case 8336ULL: goto x86_l_2090;
	case 8339ULL: goto x86_l_2093;
	case 8343ULL: goto x86_l_2097;
	case 8349ULL: goto x86_l_209d;
	case 8356ULL: goto x86_l_20a4;
	case 8361ULL: goto x86_l_20a9;
	case 8365ULL: goto x86_l_20ad;
	case 8368ULL: goto x86_l_20b0;
	case 8372ULL: goto x86_l_20b4;
	case 8378ULL: goto x86_l_20ba;
	case 8385ULL: goto x86_l_20c1;
	case 8390ULL: goto x86_l_20c6;
	case 8394ULL: goto x86_l_20ca;
	case 8397ULL: goto x86_l_20cd;
	case 8401ULL: goto x86_l_20d1;
	case 8407ULL: goto x86_l_20d7;
	case 8414ULL: goto x86_l_20de;
	case 8419ULL: goto x86_l_20e3;
	case 8423ULL: goto x86_l_20e7;
	case 8426ULL: goto x86_l_20ea;
	case 8430ULL: goto x86_l_20ee;
	case 8436ULL: goto x86_l_20f4;
	case 8443ULL: goto x86_l_20fb;
	case 8448ULL: goto x86_l_2100;
	case 8452ULL: goto x86_l_2104;
	case 8455ULL: goto x86_l_2107;
	case 8459ULL: goto x86_l_210b;
	case 8465ULL: goto x86_l_2111;
	case 8472ULL: goto x86_l_2118;
	case 8477ULL: goto x86_l_211d;
	case 8481ULL: goto x86_l_2121;
	case 8484ULL: goto x86_l_2124;
	case 8488ULL: goto x86_l_2128;
	case 8494ULL: goto x86_l_212e;
	case 8501ULL: goto x86_l_2135;
	case 8506ULL: goto x86_l_213a;
	case 8510ULL: goto x86_l_213e;
	case 8513ULL: goto x86_l_2141;
	case 8517ULL: goto x86_l_2145;
	case 8523ULL: goto x86_l_214b;
	case 8530ULL: goto x86_l_2152;
	case 8535ULL: goto x86_l_2157;
	case 8539ULL: goto x86_l_215b;
	case 8542ULL: goto x86_l_215e;
	case 8546ULL: goto x86_l_2162;
	case 8552ULL: goto x86_l_2168;
	case 8559ULL: goto x86_l_216f;
	case 8564ULL: goto x86_l_2174;
	case 8568ULL: goto x86_l_2178;
	case 8571ULL: goto x86_l_217b;
	case 8575ULL: goto x86_l_217f;
	case 8581ULL: goto x86_l_2185;
	case 8588ULL: goto x86_l_218c;
	case 8593ULL: goto x86_l_2191;
	case 8597ULL: goto x86_l_2195;
	case 8600ULL: goto x86_l_2198;
	case 8604ULL: goto x86_l_219c;
	case 8610ULL: goto x86_l_21a2;
	case 8617ULL: goto x86_l_21a9;
	case 8622ULL: goto x86_l_21ae;
	case 8626ULL: goto x86_l_21b2;
	case 8629ULL: goto x86_l_21b5;
	case 8633ULL: goto x86_l_21b9;
	case 8639ULL: goto x86_l_21bf;
	case 8646ULL: goto x86_l_21c6;
	case 8651ULL: goto x86_l_21cb;
	case 8655ULL: goto x86_l_21cf;
	case 8658ULL: goto x86_l_21d2;
	case 8662ULL: goto x86_l_21d6;
	case 8668ULL: goto x86_l_21dc;
	case 8675ULL: goto x86_l_21e3;
	case 8680ULL: goto x86_l_21e8;
	case 8684ULL: goto x86_l_21ec;
	case 8687ULL: goto x86_l_21ef;
	case 8691ULL: goto x86_l_21f3;
	case 8697ULL: goto x86_l_21f9;
	case 8704ULL: goto x86_l_2200;
	case 8709ULL: goto x86_l_2205;
	case 8713ULL: goto x86_l_2209;
	case 8716ULL: goto x86_l_220c;
	case 8720ULL: goto x86_l_2210;
	case 8726ULL: goto x86_l_2216;
	case 8733ULL: goto x86_l_221d;
	case 8738ULL: goto x86_l_2222;
	case 8742ULL: goto x86_l_2226;
	case 8745ULL: goto x86_l_2229;
	case 8749ULL: goto x86_l_222d;
	case 8755ULL: goto x86_l_2233;
	case 8762ULL: goto x86_l_223a;
	case 8767ULL: goto x86_l_223f;
	case 8771ULL: goto x86_l_2243;
	case 8774ULL: goto x86_l_2246;
	case 8778ULL: goto x86_l_224a;
	case 8784ULL: goto x86_l_2250;
	case 8791ULL: goto x86_l_2257;
	case 8796ULL: goto x86_l_225c;
	case 8800ULL: goto x86_l_2260;
	case 8803ULL: goto x86_l_2263;
	case 8807ULL: goto x86_l_2267;
	case 8813ULL: goto x86_l_226d;
	case 8820ULL: goto x86_l_2274;
	case 8825ULL: goto x86_l_2279;
	case 8829ULL: goto x86_l_227d;
	case 8832ULL: goto x86_l_2280;
	case 8836ULL: goto x86_l_2284;
	case 8842ULL: goto x86_l_228a;
	case 8849ULL: goto x86_l_2291;
	case 8854ULL: goto x86_l_2296;
	case 8858ULL: goto x86_l_229a;
	case 8861ULL: goto x86_l_229d;
	case 8865ULL: goto x86_l_22a1;
	case 8871ULL: goto x86_l_22a7;
	case 8878ULL: goto x86_l_22ae;
	case 8883ULL: goto x86_l_22b3;
	case 8887ULL: goto x86_l_22b7;
	case 8890ULL: goto x86_l_22ba;
	case 8894ULL: goto x86_l_22be;
	case 8900ULL: goto x86_l_22c4;
	case 8907ULL: goto x86_l_22cb;
	case 8912ULL: goto x86_l_22d0;
	case 8916ULL: goto x86_l_22d4;
	case 8919ULL: goto x86_l_22d7;
	case 8923ULL: goto x86_l_22db;
	case 8929ULL: goto x86_l_22e1;
	case 8936ULL: goto x86_l_22e8;
	case 8941ULL: goto x86_l_22ed;
	case 8945ULL: goto x86_l_22f1;
	case 8948ULL: goto x86_l_22f4;
	case 8952ULL: goto x86_l_22f8;
	case 8958ULL: goto x86_l_22fe;
	case 8965ULL: goto x86_l_2305;
	case 8970ULL: goto x86_l_230a;
	case 8974ULL: goto x86_l_230e;
	case 8977ULL: goto x86_l_2311;
	case 8981ULL: goto x86_l_2315;
	case 8987ULL: goto x86_l_231b;
	case 8994ULL: goto x86_l_2322;
	case 8999ULL: goto x86_l_2327;
	case 9003ULL: goto x86_l_232b;
	case 9006ULL: goto x86_l_232e;
	case 9010ULL: goto x86_l_2332;
	case 9016ULL: goto x86_l_2338;
	case 9023ULL: goto x86_l_233f;
	case 9028ULL: goto x86_l_2344;
	case 9032ULL: goto x86_l_2348;
	case 9035ULL: goto x86_l_234b;
	case 9039ULL: goto x86_l_234f;
	case 9045ULL: goto x86_l_2355;
	case 9052ULL: goto x86_l_235c;
	case 9057ULL: goto x86_l_2361;
	case 9061ULL: goto x86_l_2365;
	case 9064ULL: goto x86_l_2368;
	case 9068ULL: goto x86_l_236c;
	case 9074ULL: goto x86_l_2372;
	case 9081ULL: goto x86_l_2379;
	case 9086ULL: goto x86_l_237e;
	case 9090ULL: goto x86_l_2382;
	case 9093ULL: goto x86_l_2385;
	case 9097ULL: goto x86_l_2389;
	case 9103ULL: goto x86_l_238f;
	case 9110ULL: goto x86_l_2396;
	case 9115ULL: goto x86_l_239b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c69:
	/* 0x1c69: je     3161 <generic_usdt_filter_arg_2+0x3161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12641ULL;
	}
x86_l_1c6f:
	/* 0x1c6f: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_1c76:
	/* 0x1c76: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c7b:
	/* 0x1c7b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c80:
	/* 0x1c80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c82:
	/* 0x1c82: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c85:
	/* 0x1c85: je     315e <generic_usdt_filter_arg_2+0x315e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12638ULL;
	}
x86_l_1c8b:
	/* 0x1c8b: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1c8e:
	/* 0x1c8e: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c93:
	/* 0x1c93: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1c97:
	/* 0x1c97: cmp    r13d,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 94ULL);
x86_l_1c9b:
	/* 0x1c9b: mov    eax,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 94ULL);
x86_l_1ca0:
	/* 0x1ca0: cmovb  eax,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_1ca4:
	/* 0x1ca4: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1ca7:
	/* 0x1ca7: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ca9:
	/* 0x1ca9: lea    eax,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1cad:
	/* 0x1cad: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1cb2:
	/* 0x1cb2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1cb6:
	/* 0x1cb6: mov    BYTE PTR [rsi+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1cb9:
	/* 0x1cb9: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_1cbd:
	/* 0x1cbd: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1cc3:
	/* 0x1cc3: lea    eax,[r13+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_1cca:
	/* 0x1cca: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ccf:
	/* 0x1ccf: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1cd3:
	/* 0x1cd3: mov    BYTE PTR [rsi+0x5],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_1cd6:
	/* 0x1cd6: cmp    r13,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 2ULL);
x86_l_1cda:
	/* 0x1cda: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1ce0:
	/* 0x1ce0: lea    eax,[r13+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_1ce7:
	/* 0x1ce7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1cec:
	/* 0x1cec: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1cf0:
	/* 0x1cf0: mov    BYTE PTR [rsi+0x6],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1cf3:
	/* 0x1cf3: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_1cf7:
	/* 0x1cf7: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1cfd:
	/* 0x1cfd: lea    eax,[r13+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_1d04:
	/* 0x1d04: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d09:
	/* 0x1d09: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d0d:
	/* 0x1d0d: mov    BYTE PTR [rsi+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_1d10:
	/* 0x1d10: cmp    r13,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4ULL);
x86_l_1d14:
	/* 0x1d14: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1d1a:
	/* 0x1d1a: lea    eax,[r13+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_1d21:
	/* 0x1d21: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d26:
	/* 0x1d26: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d2a:
	/* 0x1d2a: mov    BYTE PTR [rsi+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d2d:
	/* 0x1d2d: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_1d31:
	/* 0x1d31: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1d37:
	/* 0x1d37: lea    eax,[r13+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_1d3e:
	/* 0x1d3e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d43:
	/* 0x1d43: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d47:
	/* 0x1d47: mov    BYTE PTR [rsi+0x9],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_1d4a:
	/* 0x1d4a: cmp    r13,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 6ULL);
x86_l_1d4e:
	/* 0x1d4e: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1d54:
	/* 0x1d54: lea    eax,[r13+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_1d5b:
	/* 0x1d5b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d60:
	/* 0x1d60: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d64:
	/* 0x1d64: mov    BYTE PTR [rsi+0xa],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_1d67:
	/* 0x1d67: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_1d6b:
	/* 0x1d6b: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1d71:
	/* 0x1d71: lea    eax,[r13+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_1d78:
	/* 0x1d78: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d7d:
	/* 0x1d7d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d81:
	/* 0x1d81: mov    BYTE PTR [rsi+0xb],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_1d84:
	/* 0x1d84: cmp    r13,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 8ULL);
x86_l_1d88:
	/* 0x1d88: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1d8e:
	/* 0x1d8e: lea    eax,[r13+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_1d95:
	/* 0x1d95: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d9a:
	/* 0x1d9a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d9e:
	/* 0x1d9e: mov    BYTE PTR [rsi+0xc],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1da1:
	/* 0x1da1: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_1da5:
	/* 0x1da5: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1dab:
	/* 0x1dab: lea    eax,[r13+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_1db2:
	/* 0x1db2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1db7:
	/* 0x1db7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1dbb:
	/* 0x1dbb: mov    BYTE PTR [rsi+0xd],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_1dbe:
	/* 0x1dbe: cmp    r13,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 10ULL);
x86_l_1dc2:
	/* 0x1dc2: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1dc8:
	/* 0x1dc8: lea    eax,[r13+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_1dcf:
	/* 0x1dcf: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1dd4:
	/* 0x1dd4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1dd8:
	/* 0x1dd8: mov    BYTE PTR [rsi+0xe],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_1ddb:
	/* 0x1ddb: cmp    r13,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 11ULL);
x86_l_1ddf:
	/* 0x1ddf: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1de5:
	/* 0x1de5: lea    eax,[r13+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_1dec:
	/* 0x1dec: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1df1:
	/* 0x1df1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1df5:
	/* 0x1df5: mov    BYTE PTR [rsi+0xf],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_1df8:
	/* 0x1df8: cmp    r13,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 12ULL);
x86_l_1dfc:
	/* 0x1dfc: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1e02:
	/* 0x1e02: lea    eax,[r13+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_1e09:
	/* 0x1e09: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e0e:
	/* 0x1e0e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e12:
	/* 0x1e12: mov    BYTE PTR [rsi+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e15:
	/* 0x1e15: cmp    r13,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 13ULL);
x86_l_1e19:
	/* 0x1e19: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1e1f:
	/* 0x1e1f: lea    eax,[r13+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_1e26:
	/* 0x1e26: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e2b:
	/* 0x1e2b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e2f:
	/* 0x1e2f: mov    BYTE PTR [rsi+0x11],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_1e32:
	/* 0x1e32: cmp    r13,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 14ULL);
x86_l_1e36:
	/* 0x1e36: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1e3c:
	/* 0x1e3c: lea    eax,[r13+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_1e43:
	/* 0x1e43: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e48:
	/* 0x1e48: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e4c:
	/* 0x1e4c: mov    BYTE PTR [rsi+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1e4f:
	/* 0x1e4f: cmp    r13,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 15ULL);
x86_l_1e53:
	/* 0x1e53: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1e59:
	/* 0x1e59: lea    eax,[r13+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_1e60:
	/* 0x1e60: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e65:
	/* 0x1e65: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e69:
	/* 0x1e69: mov    BYTE PTR [rsi+0x13],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_1e6c:
	/* 0x1e6c: cmp    r13,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 16ULL);
x86_l_1e70:
	/* 0x1e70: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1e76:
	/* 0x1e76: lea    eax,[r13+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_1e7d:
	/* 0x1e7d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e82:
	/* 0x1e82: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e86:
	/* 0x1e86: mov    BYTE PTR [rsi+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1e89:
	/* 0x1e89: cmp    r13,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 17ULL);
x86_l_1e8d:
	/* 0x1e8d: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1e93:
	/* 0x1e93: lea    eax,[r13+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_1e9a:
	/* 0x1e9a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e9f:
	/* 0x1e9f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ea3:
	/* 0x1ea3: mov    BYTE PTR [rsi+0x15],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_1ea6:
	/* 0x1ea6: cmp    r13,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18ULL);
x86_l_1eaa:
	/* 0x1eaa: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1eb0:
	/* 0x1eb0: lea    eax,[r13+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_1eb7:
	/* 0x1eb7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ebc:
	/* 0x1ebc: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ec0:
	/* 0x1ec0: mov    BYTE PTR [rsi+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_1ec3:
	/* 0x1ec3: cmp    r13,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 19ULL);
x86_l_1ec7:
	/* 0x1ec7: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1ecd:
	/* 0x1ecd: lea    eax,[r13+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_1ed4:
	/* 0x1ed4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ed9:
	/* 0x1ed9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1edd:
	/* 0x1edd: mov    BYTE PTR [rsi+0x17],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_1ee0:
	/* 0x1ee0: cmp    r13,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 20ULL);
x86_l_1ee4:
	/* 0x1ee4: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1eea:
	/* 0x1eea: lea    eax,[r13+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_1ef1:
	/* 0x1ef1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ef6:
	/* 0x1ef6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1efa:
	/* 0x1efa: mov    BYTE PTR [rsi+0x18],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1efd:
	/* 0x1efd: cmp    r13,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 21ULL);
x86_l_1f01:
	/* 0x1f01: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1f07:
	/* 0x1f07: lea    eax,[r13+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_1f0e:
	/* 0x1f0e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f13:
	/* 0x1f13: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f17:
	/* 0x1f17: mov    BYTE PTR [rsi+0x19],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_1f1a:
	/* 0x1f1a: cmp    r13,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 22ULL);
x86_l_1f1e:
	/* 0x1f1e: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1f24:
	/* 0x1f24: lea    eax,[r13+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_1f2b:
	/* 0x1f2b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f30:
	/* 0x1f30: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f34:
	/* 0x1f34: mov    BYTE PTR [rsi+0x1a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_1f37:
	/* 0x1f37: cmp    r13,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 23ULL);
x86_l_1f3b:
	/* 0x1f3b: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1f41:
	/* 0x1f41: lea    eax,[r13+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_1f48:
	/* 0x1f48: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f4d:
	/* 0x1f4d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f51:
	/* 0x1f51: mov    BYTE PTR [rsi+0x1b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_1f54:
	/* 0x1f54: cmp    r13,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 24ULL);
x86_l_1f58:
	/* 0x1f58: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1f5e:
	/* 0x1f5e: lea    eax,[r13+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_1f65:
	/* 0x1f65: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f6a:
	/* 0x1f6a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f6e:
	/* 0x1f6e: mov    BYTE PTR [rsi+0x1c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1f71:
	/* 0x1f71: cmp    r13,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 25ULL);
x86_l_1f75:
	/* 0x1f75: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1f7b:
	/* 0x1f7b: lea    eax,[r13+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_1f82:
	/* 0x1f82: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f87:
	/* 0x1f87: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f8b:
	/* 0x1f8b: mov    BYTE PTR [rsi+0x1d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_1f8e:
	/* 0x1f8e: cmp    r13,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 26ULL);
x86_l_1f92:
	/* 0x1f92: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1f98:
	/* 0x1f98: lea    eax,[r13+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_1f9f:
	/* 0x1f9f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1fa4:
	/* 0x1fa4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1fa8:
	/* 0x1fa8: mov    BYTE PTR [rsi+0x1e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_1fab:
	/* 0x1fab: cmp    r13,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 27ULL);
x86_l_1faf:
	/* 0x1faf: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1fb5:
	/* 0x1fb5: lea    eax,[r13+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_1fbc:
	/* 0x1fbc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1fc1:
	/* 0x1fc1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1fc5:
	/* 0x1fc5: mov    BYTE PTR [rsi+0x1f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_1fc8:
	/* 0x1fc8: cmp    r13,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 28ULL);
x86_l_1fcc:
	/* 0x1fcc: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1fd2:
	/* 0x1fd2: lea    eax,[r13+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_1fd9:
	/* 0x1fd9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1fde:
	/* 0x1fde: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1fe2:
	/* 0x1fe2: mov    BYTE PTR [rsi+0x20],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fe5:
	/* 0x1fe5: cmp    r13,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 29ULL);
x86_l_1fe9:
	/* 0x1fe9: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_1fef:
	/* 0x1fef: lea    eax,[r13+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_1ff6:
	/* 0x1ff6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ffb:
	/* 0x1ffb: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1fff:
	/* 0x1fff: mov    BYTE PTR [rsi+0x21],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_2002:
	/* 0x2002: cmp    r13,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 30ULL);
x86_l_2006:
	/* 0x2006: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_200c:
	/* 0x200c: lea    eax,[r13+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_2013:
	/* 0x2013: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2018:
	/* 0x2018: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_201c:
	/* 0x201c: mov    BYTE PTR [rsi+0x22],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_201f:
	/* 0x201f: cmp    r13,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 31ULL);
x86_l_2023:
	/* 0x2023: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_2029:
	/* 0x2029: lea    eax,[r13+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_2030:
	/* 0x2030: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2035:
	/* 0x2035: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2039:
	/* 0x2039: mov    BYTE PTR [rsi+0x23],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_203c:
	/* 0x203c: cmp    r13,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 32ULL);
x86_l_2040:
	/* 0x2040: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_2046:
	/* 0x2046: lea    eax,[r13+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_204d:
	/* 0x204d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2052:
	/* 0x2052: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2056:
	/* 0x2056: mov    BYTE PTR [rsi+0x24],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2059:
	/* 0x2059: cmp    r13,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 33ULL);
x86_l_205d:
	/* 0x205d: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_2063:
	/* 0x2063: lea    eax,[r13+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_206a:
	/* 0x206a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_206f:
	/* 0x206f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2073:
	/* 0x2073: mov    BYTE PTR [rsi+0x25],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_2076:
	/* 0x2076: cmp    r13,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 34ULL);
x86_l_207a:
	/* 0x207a: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_2080:
	/* 0x2080: lea    eax,[r13+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_2087:
	/* 0x2087: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_208c:
	/* 0x208c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2090:
	/* 0x2090: mov    BYTE PTR [rsi+0x26],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_2093:
	/* 0x2093: cmp    r13,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 35ULL);
x86_l_2097:
	/* 0x2097: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_209d:
	/* 0x209d: lea    eax,[r13+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_20a4:
	/* 0x20a4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20a9:
	/* 0x20a9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_20ad:
	/* 0x20ad: mov    BYTE PTR [rsi+0x27],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_20b0:
	/* 0x20b0: cmp    r13,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 36ULL);
x86_l_20b4:
	/* 0x20b4: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_20ba:
	/* 0x20ba: lea    eax,[r13+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_20c1:
	/* 0x20c1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20c6:
	/* 0x20c6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_20ca:
	/* 0x20ca: mov    BYTE PTR [rsi+0x28],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20cd:
	/* 0x20cd: cmp    r13,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 37ULL);
x86_l_20d1:
	/* 0x20d1: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_20d7:
	/* 0x20d7: lea    eax,[r13+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_20de:
	/* 0x20de: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20e3:
	/* 0x20e3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_20e7:
	/* 0x20e7: mov    BYTE PTR [rsi+0x29],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_20ea:
	/* 0x20ea: cmp    r13,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 38ULL);
x86_l_20ee:
	/* 0x20ee: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_20f4:
	/* 0x20f4: lea    eax,[r13+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_20fb:
	/* 0x20fb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2100:
	/* 0x2100: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2104:
	/* 0x2104: mov    BYTE PTR [rsi+0x2a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_2107:
	/* 0x2107: cmp    r13,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 39ULL);
x86_l_210b:
	/* 0x210b: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_2111:
	/* 0x2111: lea    eax,[r13+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_2118:
	/* 0x2118: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_211d:
	/* 0x211d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2121:
	/* 0x2121: mov    BYTE PTR [rsi+0x2b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_2124:
	/* 0x2124: cmp    r13,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 40ULL);
x86_l_2128:
	/* 0x2128: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_212e:
	/* 0x212e: lea    eax,[r13+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_2135:
	/* 0x2135: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_213a:
	/* 0x213a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_213e:
	/* 0x213e: mov    BYTE PTR [rsi+0x2c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2141:
	/* 0x2141: cmp    r13,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 41ULL);
x86_l_2145:
	/* 0x2145: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_214b:
	/* 0x214b: lea    eax,[r13+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_2152:
	/* 0x2152: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2157:
	/* 0x2157: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_215b:
	/* 0x215b: mov    BYTE PTR [rsi+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_215e:
	/* 0x215e: cmp    r13,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 42ULL);
x86_l_2162:
	/* 0x2162: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_2168:
	/* 0x2168: lea    eax,[r13+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_216f:
	/* 0x216f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2174:
	/* 0x2174: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2178:
	/* 0x2178: mov    BYTE PTR [rsi+0x2e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_217b:
	/* 0x217b: cmp    r13,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 43ULL);
x86_l_217f:
	/* 0x217f: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_2185:
	/* 0x2185: lea    eax,[r13+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_218c:
	/* 0x218c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2191:
	/* 0x2191: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2195:
	/* 0x2195: mov    BYTE PTR [rsi+0x2f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_2198:
	/* 0x2198: cmp    r13,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 44ULL);
x86_l_219c:
	/* 0x219c: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_21a2:
	/* 0x21a2: lea    eax,[r13+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_21a9:
	/* 0x21a9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21ae:
	/* 0x21ae: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_21b2:
	/* 0x21b2: mov    BYTE PTR [rsi+0x30],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21b5:
	/* 0x21b5: cmp    r13,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 45ULL);
x86_l_21b9:
	/* 0x21b9: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_21bf:
	/* 0x21bf: lea    eax,[r13+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_21c6:
	/* 0x21c6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21cb:
	/* 0x21cb: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_21cf:
	/* 0x21cf: mov    BYTE PTR [rsi+0x31],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_21d2:
	/* 0x21d2: cmp    r13,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 46ULL);
x86_l_21d6:
	/* 0x21d6: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_21dc:
	/* 0x21dc: lea    eax,[r13+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_21e3:
	/* 0x21e3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21e8:
	/* 0x21e8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_21ec:
	/* 0x21ec: mov    BYTE PTR [rsi+0x32],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_21ef:
	/* 0x21ef: cmp    r13,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 47ULL);
x86_l_21f3:
	/* 0x21f3: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_21f9:
	/* 0x21f9: lea    eax,[r13+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_2200:
	/* 0x2200: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2205:
	/* 0x2205: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2209:
	/* 0x2209: mov    BYTE PTR [rsi+0x33],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_220c:
	/* 0x220c: cmp    r13,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 48ULL);
x86_l_2210:
	/* 0x2210: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_2216:
	/* 0x2216: lea    eax,[r13+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_221d:
	/* 0x221d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2222:
	/* 0x2222: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2226:
	/* 0x2226: mov    BYTE PTR [rsi+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2229:
	/* 0x2229: cmp    r13,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 49ULL);
x86_l_222d:
	/* 0x222d: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_2233:
	/* 0x2233: lea    eax,[r13+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_223a:
	/* 0x223a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_223f:
	/* 0x223f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2243:
	/* 0x2243: mov    BYTE PTR [rsi+0x35],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_2246:
	/* 0x2246: cmp    r13,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 50ULL);
x86_l_224a:
	/* 0x224a: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_2250:
	/* 0x2250: lea    eax,[r13+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_2257:
	/* 0x2257: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_225c:
	/* 0x225c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2260:
	/* 0x2260: mov    BYTE PTR [rsi+0x36],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_2263:
	/* 0x2263: cmp    r13,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 51ULL);
x86_l_2267:
	/* 0x2267: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_226d:
	/* 0x226d: lea    eax,[r13+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_2274:
	/* 0x2274: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2279:
	/* 0x2279: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_227d:
	/* 0x227d: mov    BYTE PTR [rsi+0x37],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_2280:
	/* 0x2280: cmp    r13,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 52ULL);
x86_l_2284:
	/* 0x2284: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_228a:
	/* 0x228a: lea    eax,[r13+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_2291:
	/* 0x2291: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2296:
	/* 0x2296: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_229a:
	/* 0x229a: mov    BYTE PTR [rsi+0x38],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_229d:
	/* 0x229d: cmp    r13,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 53ULL);
x86_l_22a1:
	/* 0x22a1: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_22a7:
	/* 0x22a7: lea    eax,[r13+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_22ae:
	/* 0x22ae: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22b3:
	/* 0x22b3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_22b7:
	/* 0x22b7: mov    BYTE PTR [rsi+0x39],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_22ba:
	/* 0x22ba: cmp    r13,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 54ULL);
x86_l_22be:
	/* 0x22be: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_22c4:
	/* 0x22c4: lea    eax,[r13+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_22cb:
	/* 0x22cb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22d0:
	/* 0x22d0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_22d4:
	/* 0x22d4: mov    BYTE PTR [rsi+0x3a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_22d7:
	/* 0x22d7: cmp    r13,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 55ULL);
x86_l_22db:
	/* 0x22db: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_22e1:
	/* 0x22e1: lea    eax,[r13+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_22e8:
	/* 0x22e8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22ed:
	/* 0x22ed: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_22f1:
	/* 0x22f1: mov    BYTE PTR [rsi+0x3b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_22f4:
	/* 0x22f4: cmp    r13,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 56ULL);
x86_l_22f8:
	/* 0x22f8: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_22fe:
	/* 0x22fe: lea    eax,[r13+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_2305:
	/* 0x2305: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_230a:
	/* 0x230a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_230e:
	/* 0x230e: mov    BYTE PTR [rsi+0x3c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2311:
	/* 0x2311: cmp    r13,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 57ULL);
x86_l_2315:
	/* 0x2315: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_231b:
	/* 0x231b: lea    eax,[r13+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_2322:
	/* 0x2322: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2327:
	/* 0x2327: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_232b:
	/* 0x232b: mov    BYTE PTR [rsi+0x3d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_232e:
	/* 0x232e: cmp    r13,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 58ULL);
x86_l_2332:
	/* 0x2332: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_2338:
	/* 0x2338: lea    eax,[r13+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_233f:
	/* 0x233f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2344:
	/* 0x2344: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2348:
	/* 0x2348: mov    BYTE PTR [rsi+0x3e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_234b:
	/* 0x234b: cmp    r13,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 59ULL);
x86_l_234f:
	/* 0x234f: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_2355:
	/* 0x2355: lea    eax,[r13+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_235c:
	/* 0x235c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2361:
	/* 0x2361: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2365:
	/* 0x2365: mov    BYTE PTR [rsi+0x3f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_2368:
	/* 0x2368: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_236c:
	/* 0x236c: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_2372:
	/* 0x2372: lea    eax,[r13+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_2379:
	/* 0x2379: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_237e:
	/* 0x237e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2382:
	/* 0x2382: mov    BYTE PTR [rsi+0x40],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2385:
	/* 0x2385: cmp    r13,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 61ULL);
x86_l_2389:
	/* 0x2389: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10031ULL;
	}
x86_l_238f:
	/* 0x238f: lea    eax,[r13+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_2396:
	/* 0x2396: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_239b:
	/* 0x239b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
	return 9119ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9119ULL: goto x86_l_239f;
	case 9122ULL: goto x86_l_23a2;
	case 9126ULL: goto x86_l_23a6;
	case 9132ULL: goto x86_l_23ac;
	case 9139ULL: goto x86_l_23b3;
	case 9144ULL: goto x86_l_23b8;
	case 9148ULL: goto x86_l_23bc;
	case 9151ULL: goto x86_l_23bf;
	case 9155ULL: goto x86_l_23c3;
	case 9161ULL: goto x86_l_23c9;
	case 9168ULL: goto x86_l_23d0;
	case 9173ULL: goto x86_l_23d5;
	case 9177ULL: goto x86_l_23d9;
	case 9180ULL: goto x86_l_23dc;
	case 9184ULL: goto x86_l_23e0;
	case 9190ULL: goto x86_l_23e6;
	case 9197ULL: goto x86_l_23ed;
	case 9202ULL: goto x86_l_23f2;
	case 9206ULL: goto x86_l_23f6;
	case 9209ULL: goto x86_l_23f9;
	case 9213ULL: goto x86_l_23fd;
	case 9219ULL: goto x86_l_2403;
	case 9226ULL: goto x86_l_240a;
	case 9231ULL: goto x86_l_240f;
	case 9235ULL: goto x86_l_2413;
	case 9238ULL: goto x86_l_2416;
	case 9242ULL: goto x86_l_241a;
	case 9248ULL: goto x86_l_2420;
	case 9255ULL: goto x86_l_2427;
	case 9260ULL: goto x86_l_242c;
	case 9264ULL: goto x86_l_2430;
	case 9267ULL: goto x86_l_2433;
	case 9271ULL: goto x86_l_2437;
	case 9277ULL: goto x86_l_243d;
	case 9284ULL: goto x86_l_2444;
	case 9289ULL: goto x86_l_2449;
	case 9293ULL: goto x86_l_244d;
	case 9296ULL: goto x86_l_2450;
	case 9300ULL: goto x86_l_2454;
	case 9306ULL: goto x86_l_245a;
	case 9313ULL: goto x86_l_2461;
	case 9318ULL: goto x86_l_2466;
	case 9322ULL: goto x86_l_246a;
	case 9325ULL: goto x86_l_246d;
	case 9329ULL: goto x86_l_2471;
	case 9335ULL: goto x86_l_2477;
	case 9342ULL: goto x86_l_247e;
	case 9347ULL: goto x86_l_2483;
	case 9351ULL: goto x86_l_2487;
	case 9354ULL: goto x86_l_248a;
	case 9358ULL: goto x86_l_248e;
	case 9364ULL: goto x86_l_2494;
	case 9371ULL: goto x86_l_249b;
	case 9376ULL: goto x86_l_24a0;
	case 9380ULL: goto x86_l_24a4;
	case 9383ULL: goto x86_l_24a7;
	case 9387ULL: goto x86_l_24ab;
	case 9393ULL: goto x86_l_24b1;
	case 9400ULL: goto x86_l_24b8;
	case 9405ULL: goto x86_l_24bd;
	case 9409ULL: goto x86_l_24c1;
	case 9412ULL: goto x86_l_24c4;
	case 9416ULL: goto x86_l_24c8;
	case 9422ULL: goto x86_l_24ce;
	case 9429ULL: goto x86_l_24d5;
	case 9434ULL: goto x86_l_24da;
	case 9438ULL: goto x86_l_24de;
	case 9441ULL: goto x86_l_24e1;
	case 9445ULL: goto x86_l_24e5;
	case 9451ULL: goto x86_l_24eb;
	case 9458ULL: goto x86_l_24f2;
	case 9463ULL: goto x86_l_24f7;
	case 9467ULL: goto x86_l_24fb;
	case 9470ULL: goto x86_l_24fe;
	case 9474ULL: goto x86_l_2502;
	case 9480ULL: goto x86_l_2508;
	case 9487ULL: goto x86_l_250f;
	case 9492ULL: goto x86_l_2514;
	case 9496ULL: goto x86_l_2518;
	case 9499ULL: goto x86_l_251b;
	case 9503ULL: goto x86_l_251f;
	case 9509ULL: goto x86_l_2525;
	case 9516ULL: goto x86_l_252c;
	case 9521ULL: goto x86_l_2531;
	case 9525ULL: goto x86_l_2535;
	case 9528ULL: goto x86_l_2538;
	case 9532ULL: goto x86_l_253c;
	case 9538ULL: goto x86_l_2542;
	case 9545ULL: goto x86_l_2549;
	case 9550ULL: goto x86_l_254e;
	case 9554ULL: goto x86_l_2552;
	case 9557ULL: goto x86_l_2555;
	case 9561ULL: goto x86_l_2559;
	case 9567ULL: goto x86_l_255f;
	case 9574ULL: goto x86_l_2566;
	case 9579ULL: goto x86_l_256b;
	case 9583ULL: goto x86_l_256f;
	case 9586ULL: goto x86_l_2572;
	case 9590ULL: goto x86_l_2576;
	case 9596ULL: goto x86_l_257c;
	case 9603ULL: goto x86_l_2583;
	case 9608ULL: goto x86_l_2588;
	case 9612ULL: goto x86_l_258c;
	case 9615ULL: goto x86_l_258f;
	case 9619ULL: goto x86_l_2593;
	case 9625ULL: goto x86_l_2599;
	case 9632ULL: goto x86_l_25a0;
	case 9637ULL: goto x86_l_25a5;
	case 9641ULL: goto x86_l_25a9;
	case 9644ULL: goto x86_l_25ac;
	case 9648ULL: goto x86_l_25b0;
	case 9654ULL: goto x86_l_25b6;
	case 9661ULL: goto x86_l_25bd;
	case 9666ULL: goto x86_l_25c2;
	case 9670ULL: goto x86_l_25c6;
	case 9673ULL: goto x86_l_25c9;
	case 9677ULL: goto x86_l_25cd;
	case 9683ULL: goto x86_l_25d3;
	case 9690ULL: goto x86_l_25da;
	case 9695ULL: goto x86_l_25df;
	case 9699ULL: goto x86_l_25e3;
	case 9702ULL: goto x86_l_25e6;
	case 9706ULL: goto x86_l_25ea;
	case 9712ULL: goto x86_l_25f0;
	case 9719ULL: goto x86_l_25f7;
	case 9724ULL: goto x86_l_25fc;
	case 9728ULL: goto x86_l_2600;
	case 9731ULL: goto x86_l_2603;
	case 9735ULL: goto x86_l_2607;
	case 9741ULL: goto x86_l_260d;
	case 9748ULL: goto x86_l_2614;
	case 9753ULL: goto x86_l_2619;
	case 9757ULL: goto x86_l_261d;
	case 9760ULL: goto x86_l_2620;
	case 9764ULL: goto x86_l_2624;
	case 9770ULL: goto x86_l_262a;
	case 9777ULL: goto x86_l_2631;
	case 9782ULL: goto x86_l_2636;
	case 9786ULL: goto x86_l_263a;
	case 9789ULL: goto x86_l_263d;
	case 9793ULL: goto x86_l_2641;
	case 9799ULL: goto x86_l_2647;
	case 9806ULL: goto x86_l_264e;
	case 9811ULL: goto x86_l_2653;
	case 9815ULL: goto x86_l_2657;
	case 9818ULL: goto x86_l_265a;
	case 9822ULL: goto x86_l_265e;
	case 9828ULL: goto x86_l_2664;
	case 9835ULL: goto x86_l_266b;
	case 9840ULL: goto x86_l_2670;
	case 9844ULL: goto x86_l_2674;
	case 9847ULL: goto x86_l_2677;
	case 9851ULL: goto x86_l_267b;
	case 9857ULL: goto x86_l_2681;
	case 9864ULL: goto x86_l_2688;
	case 9869ULL: goto x86_l_268d;
	case 9873ULL: goto x86_l_2691;
	case 9876ULL: goto x86_l_2694;
	case 9880ULL: goto x86_l_2698;
	case 9886ULL: goto x86_l_269e;
	case 9893ULL: goto x86_l_26a5;
	case 9898ULL: goto x86_l_26aa;
	case 9902ULL: goto x86_l_26ae;
	case 9905ULL: goto x86_l_26b1;
	case 9909ULL: goto x86_l_26b5;
	case 9911ULL: goto x86_l_26b7;
	case 9918ULL: goto x86_l_26be;
	case 9923ULL: goto x86_l_26c3;
	case 9927ULL: goto x86_l_26c7;
	case 9930ULL: goto x86_l_26ca;
	case 9934ULL: goto x86_l_26ce;
	case 9936ULL: goto x86_l_26d0;
	case 9943ULL: goto x86_l_26d7;
	case 9948ULL: goto x86_l_26dc;
	case 9952ULL: goto x86_l_26e0;
	case 9955ULL: goto x86_l_26e3;
	case 9959ULL: goto x86_l_26e7;
	case 9961ULL: goto x86_l_26e9;
	case 9968ULL: goto x86_l_26f0;
	case 9973ULL: goto x86_l_26f5;
	case 9977ULL: goto x86_l_26f9;
	case 9980ULL: goto x86_l_26fc;
	case 9984ULL: goto x86_l_2700;
	case 9986ULL: goto x86_l_2702;
	case 9989ULL: goto x86_l_2705;
	case 9994ULL: goto x86_l_270a;
	case 9999ULL: goto x86_l_270f;
	case 10003ULL: goto x86_l_2713;
	case 10006ULL: goto x86_l_2716;
	case 10010ULL: goto x86_l_271a;
	case 10012ULL: goto x86_l_271c;
	case 10019ULL: goto x86_l_2723;
	case 10024ULL: goto x86_l_2728;
	case 10028ULL: goto x86_l_272c;
	case 10031ULL: goto x86_l_272f;
	case 10036ULL: goto x86_l_2734;
	case 10041ULL: goto x86_l_2739;
	case 10046ULL: goto x86_l_273e;
	case 10051ULL: goto x86_l_2743;
	case 10055ULL: goto x86_l_2747;
	case 10058ULL: goto x86_l_274a;
	case 10062ULL: goto x86_l_274e;
	case 10070ULL: goto x86_l_2756;
	case 10077ULL: goto x86_l_275d;
	case 10082ULL: goto x86_l_2762;
	case 10087ULL: goto x86_l_2767;
	case 10089ULL: goto x86_l_2769;
	case 10092ULL: goto x86_l_276c;
	case 10095ULL: goto x86_l_276f;
	case 10098ULL: goto x86_l_2772;
	case 10104ULL: goto x86_l_2778;
	case 10109ULL: goto x86_l_277d;
	case 10112ULL: goto x86_l_2780;
	case 10118ULL: goto x86_l_2786;
	case 10125ULL: goto x86_l_278d;
	case 10130ULL: goto x86_l_2792;
	case 10135ULL: goto x86_l_2797;
	case 10137ULL: goto x86_l_2799;
	case 10140ULL: goto x86_l_279c;
	case 10146ULL: goto x86_l_27a2;
	case 10151ULL: goto x86_l_27a7;
	case 10155ULL: goto x86_l_27ab;
	case 10162ULL: goto x86_l_27b2;
	case 10167ULL: goto x86_l_27b7;
	case 10171ULL: goto x86_l_27bb;
	case 10178ULL: goto x86_l_27c2;
	case 10180ULL: goto x86_l_27c4;
	case 10183ULL: goto x86_l_27c7;
	case 10187ULL: goto x86_l_27cb;
	case 10190ULL: goto x86_l_27ce;
	case 10195ULL: goto x86_l_27d3;
	case 10197ULL: goto x86_l_27d5;
	case 10202ULL: goto x86_l_27da;
	case 10207ULL: goto x86_l_27df;
	case 10210ULL: goto x86_l_27e2;
	case 10215ULL: goto x86_l_27e7;
	case 10218ULL: goto x86_l_27ea;
	case 10220ULL: goto x86_l_27ec;
	case 10223ULL: goto x86_l_27ef;
	case 10229ULL: goto x86_l_27f5;
	case 10234ULL: goto x86_l_27fa;
	case 10236ULL: goto x86_l_27fc;
	case 10241ULL: goto x86_l_2801;
	case 10243ULL: goto x86_l_2803;
	case 10246ULL: goto x86_l_2806;
	case 10249ULL: goto x86_l_2809;
	case 10251ULL: goto x86_l_280b;
	case 10254ULL: goto x86_l_280e;
	case 10260ULL: goto x86_l_2814;
	case 10263ULL: goto x86_l_2817;
	case 10269ULL: goto x86_l_281d;
	case 10272ULL: goto x86_l_2820;
	case 10278ULL: goto x86_l_2826;
	case 10281ULL: goto x86_l_2829;
	case 10287ULL: goto x86_l_282f;
	case 10290ULL: goto x86_l_2832;
	case 10295ULL: goto x86_l_2837;
	case 10299ULL: goto x86_l_283b;
	case 10303ULL: goto x86_l_283f;
	case 10305ULL: goto x86_l_2841;
	case 10308ULL: goto x86_l_2844;
	case 10312ULL: goto x86_l_2848;
	case 10315ULL: goto x86_l_284b;
	case 10319ULL: goto x86_l_284f;
	case 10321ULL: goto x86_l_2851;
	case 10324ULL: goto x86_l_2854;
	case 10327ULL: goto x86_l_2857;
	case 10329ULL: goto x86_l_2859;
	case 10332ULL: goto x86_l_285c;
	case 10335ULL: goto x86_l_285f;
	case 10337ULL: goto x86_l_2861;
	case 10340ULL: goto x86_l_2864;
	case 10343ULL: goto x86_l_2867;
	case 10349ULL: goto x86_l_286d;
	case 10352ULL: goto x86_l_2870;
	case 10358ULL: goto x86_l_2876;
	case 10363ULL: goto x86_l_287b;
	case 10366ULL: goto x86_l_287e;
	case 10368ULL: goto x86_l_2880;
	case 10373ULL: goto x86_l_2885;
	case 10376ULL: goto x86_l_2888;
	case 10382ULL: goto x86_l_288e;
	case 10387ULL: goto x86_l_2893;
	case 10390ULL: goto x86_l_2896;
	case 10396ULL: goto x86_l_289c;
	case 10401ULL: goto x86_l_28a1;
	case 10404ULL: goto x86_l_28a4;
	case 10406ULL: goto x86_l_28a6;
	case 10411ULL: goto x86_l_28ab;
	case 10414ULL: goto x86_l_28ae;
	case 10420ULL: goto x86_l_28b4;
	case 10423ULL: goto x86_l_28b7;
	case 10429ULL: goto x86_l_28bd;
	case 10432ULL: goto x86_l_28c0;
	case 10435ULL: goto x86_l_28c3;
	case 10438ULL: goto x86_l_28c6;
	case 10442ULL: goto x86_l_28ca;
	case 10449ULL: goto x86_l_28d1;
	case 10454ULL: goto x86_l_28d6;
	case 10459ULL: goto x86_l_28db;
	case 10461ULL: goto x86_l_28dd;
	case 10464ULL: goto x86_l_28e0;
	case 10470ULL: goto x86_l_28e6;
	case 10473ULL: goto x86_l_28e9;
	case 10481ULL: goto x86_l_28f1;
	case 10486ULL: goto x86_l_28f6;
	case 10491ULL: goto x86_l_28fb;
	case 10494ULL: goto x86_l_28fe;
	case 10497ULL: goto x86_l_2901;
	case 10503ULL: goto x86_l_2907;
	case 10506ULL: goto x86_l_290a;
	case 10510ULL: goto x86_l_290e;
	case 10514ULL: goto x86_l_2912;
	case 10521ULL: goto x86_l_2919;
	case 10524ULL: goto x86_l_291c;
	case 10529ULL: goto x86_l_2921;
	case 10534ULL: goto x86_l_2926;
	case 10536ULL: goto x86_l_2928;
	case 10539ULL: goto x86_l_292b;
	case 10545ULL: goto x86_l_2931;
	case 10548ULL: goto x86_l_2934;
	case 10552ULL: goto x86_l_2938;
	case 10557ULL: goto x86_l_293d;
	case 10562ULL: goto x86_l_2942;
	case 10567ULL: goto x86_l_2947;
	case 10569ULL: goto x86_l_2949;
	case 10574ULL: goto x86_l_294e;
	case 10579ULL: goto x86_l_2953;
	case 10584ULL: goto x86_l_2958;
	case 10588ULL: goto x86_l_295c;
	case 10591ULL: goto x86_l_295f;
	case 10595ULL: goto x86_l_2963;
	case 10603ULL: goto x86_l_296b;
	case 10610ULL: goto x86_l_2972;
	case 10615ULL: goto x86_l_2977;
	case 10620ULL: goto x86_l_297c;
	case 10622ULL: goto x86_l_297e;
	case 10625ULL: goto x86_l_2981;
	case 10631ULL: goto x86_l_2987;
	case 10637ULL: goto x86_l_298d;
	case 10640ULL: goto x86_l_2990;
	case 10643ULL: goto x86_l_2993;
	case 10649ULL: goto x86_l_2999;
	case 10656ULL: goto x86_l_29a0;
	case 10661ULL: goto x86_l_29a5;
	case 10666ULL: goto x86_l_29aa;
	case 10668ULL: goto x86_l_29ac;
	case 10671ULL: goto x86_l_29af;
	case 10677ULL: goto x86_l_29b5;
	case 10682ULL: goto x86_l_29ba;
	case 10688ULL: goto x86_l_29c0;
	case 10693ULL: goto x86_l_29c5;
	case 10696ULL: goto x86_l_29c8;
	case 10703ULL: goto x86_l_29cf;
	case 10705ULL: goto x86_l_29d1;
	case 10708ULL: goto x86_l_29d4;
	case 10712ULL: goto x86_l_29d8;
	case 10715ULL: goto x86_l_29db;
	case 10720ULL: goto x86_l_29e0;
	case 10725ULL: goto x86_l_29e5;
	case 10727ULL: goto x86_l_29e7;
	case 10732ULL: goto x86_l_29ec;
	case 10735ULL: goto x86_l_29ef;
	case 10738ULL: goto x86_l_29f2;
	case 10743ULL: goto x86_l_29f7;
	case 10751ULL: goto x86_l_29ff;
	case 10757ULL: goto x86_l_2a05;
	case 10763ULL: goto x86_l_2a0b;
	case 10768ULL: goto x86_l_2a10;
	case 10772ULL: goto x86_l_2a14;
	case 10775ULL: goto x86_l_2a17;
	case 10781ULL: goto x86_l_2a1d;
	case 10784ULL: goto x86_l_2a20;
	case 10787ULL: goto x86_l_2a23;
	case 10790ULL: goto x86_l_2a26;
	case 10792ULL: goto x86_l_2a28;
	case 10794ULL: goto x86_l_2a2a;
	case 10797ULL: goto x86_l_2a2d;
	case 10803ULL: goto x86_l_2a33;
	case 10805ULL: goto x86_l_2a35;
	case 10811ULL: goto x86_l_2a3b;
	case 10816ULL: goto x86_l_2a40;
	case 10819ULL: goto x86_l_2a43;
	case 10822ULL: goto x86_l_2a46;
	default: return 0xffffffffffffffffULL;
	}
x86_l_239f:
	/* 0x239f: mov    BYTE PTR [rsi+0x41],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_23a2:
	/* 0x23a2: cmp    r13,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 62ULL);
x86_l_23a6:
	/* 0x23a6: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_23ac:
	/* 0x23ac: lea    eax,[r13+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_23b3:
	/* 0x23b3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23b8:
	/* 0x23b8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_23bc:
	/* 0x23bc: mov    BYTE PTR [rsi+0x42],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_23bf:
	/* 0x23bf: cmp    r13,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 63ULL);
x86_l_23c3:
	/* 0x23c3: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_23c9:
	/* 0x23c9: lea    eax,[r13+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_23d0:
	/* 0x23d0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23d5:
	/* 0x23d5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_23d9:
	/* 0x23d9: mov    BYTE PTR [rsi+0x43],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_23dc:
	/* 0x23dc: cmp    r13,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 64ULL);
x86_l_23e0:
	/* 0x23e0: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_23e6:
	/* 0x23e6: lea    eax,[r13+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_23ed:
	/* 0x23ed: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23f2:
	/* 0x23f2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_23f6:
	/* 0x23f6: mov    BYTE PTR [rsi+0x44],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_23f9:
	/* 0x23f9: cmp    r13,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 65ULL);
x86_l_23fd:
	/* 0x23fd: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_2403:
	/* 0x2403: lea    eax,[r13+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_240a:
	/* 0x240a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_240f:
	/* 0x240f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2413:
	/* 0x2413: mov    BYTE PTR [rsi+0x45],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_2416:
	/* 0x2416: cmp    r13,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 66ULL);
x86_l_241a:
	/* 0x241a: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_2420:
	/* 0x2420: lea    eax,[r13+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_2427:
	/* 0x2427: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_242c:
	/* 0x242c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2430:
	/* 0x2430: mov    BYTE PTR [rsi+0x46],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_2433:
	/* 0x2433: cmp    r13,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 67ULL);
x86_l_2437:
	/* 0x2437: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_243d:
	/* 0x243d: lea    eax,[r13+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_2444:
	/* 0x2444: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2449:
	/* 0x2449: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_244d:
	/* 0x244d: mov    BYTE PTR [rsi+0x47],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_2450:
	/* 0x2450: cmp    r13,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 68ULL);
x86_l_2454:
	/* 0x2454: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_245a:
	/* 0x245a: lea    eax,[r13+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_2461:
	/* 0x2461: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2466:
	/* 0x2466: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_246a:
	/* 0x246a: mov    BYTE PTR [rsi+0x48],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_246d:
	/* 0x246d: cmp    r13,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 69ULL);
x86_l_2471:
	/* 0x2471: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_2477:
	/* 0x2477: lea    eax,[r13+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_247e:
	/* 0x247e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2483:
	/* 0x2483: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2487:
	/* 0x2487: mov    BYTE PTR [rsi+0x49],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_248a:
	/* 0x248a: cmp    r13,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 70ULL);
x86_l_248e:
	/* 0x248e: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_2494:
	/* 0x2494: lea    eax,[r13+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_249b:
	/* 0x249b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24a0:
	/* 0x24a0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_24a4:
	/* 0x24a4: mov    BYTE PTR [rsi+0x4a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_24a7:
	/* 0x24a7: cmp    r13,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 71ULL);
x86_l_24ab:
	/* 0x24ab: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_24b1:
	/* 0x24b1: lea    eax,[r13+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_24b8:
	/* 0x24b8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24bd:
	/* 0x24bd: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_24c1:
	/* 0x24c1: mov    BYTE PTR [rsi+0x4b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_24c4:
	/* 0x24c4: cmp    r13,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 72ULL);
x86_l_24c8:
	/* 0x24c8: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_24ce:
	/* 0x24ce: lea    eax,[r13+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_24d5:
	/* 0x24d5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24da:
	/* 0x24da: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_24de:
	/* 0x24de: mov    BYTE PTR [rsi+0x4c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_24e1:
	/* 0x24e1: cmp    r13,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 73ULL);
x86_l_24e5:
	/* 0x24e5: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_24eb:
	/* 0x24eb: lea    eax,[r13+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_24f2:
	/* 0x24f2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24f7:
	/* 0x24f7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_24fb:
	/* 0x24fb: mov    BYTE PTR [rsi+0x4d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_24fe:
	/* 0x24fe: cmp    r13,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 74ULL);
x86_l_2502:
	/* 0x2502: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_2508:
	/* 0x2508: lea    eax,[r13+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_250f:
	/* 0x250f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2514:
	/* 0x2514: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2518:
	/* 0x2518: mov    BYTE PTR [rsi+0x4e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_251b:
	/* 0x251b: cmp    r13,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 75ULL);
x86_l_251f:
	/* 0x251f: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_2525:
	/* 0x2525: lea    eax,[r13+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_252c:
	/* 0x252c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2531:
	/* 0x2531: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2535:
	/* 0x2535: mov    BYTE PTR [rsi+0x4f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_2538:
	/* 0x2538: cmp    r13,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 76ULL);
x86_l_253c:
	/* 0x253c: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_2542:
	/* 0x2542: lea    eax,[r13+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_2549:
	/* 0x2549: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_254e:
	/* 0x254e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2552:
	/* 0x2552: mov    BYTE PTR [rsi+0x50],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2555:
	/* 0x2555: cmp    r13,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 77ULL);
x86_l_2559:
	/* 0x2559: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_255f:
	/* 0x255f: lea    eax,[r13+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_2566:
	/* 0x2566: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_256b:
	/* 0x256b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_256f:
	/* 0x256f: mov    BYTE PTR [rsi+0x51],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_2572:
	/* 0x2572: cmp    r13,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 78ULL);
x86_l_2576:
	/* 0x2576: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_257c:
	/* 0x257c: lea    eax,[r13+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_2583:
	/* 0x2583: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2588:
	/* 0x2588: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_258c:
	/* 0x258c: mov    BYTE PTR [rsi+0x52],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_258f:
	/* 0x258f: cmp    r13,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 79ULL);
x86_l_2593:
	/* 0x2593: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_2599:
	/* 0x2599: lea    eax,[r13+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_25a0:
	/* 0x25a0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25a5:
	/* 0x25a5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_25a9:
	/* 0x25a9: mov    BYTE PTR [rsi+0x53],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_25ac:
	/* 0x25ac: cmp    r13,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 80ULL);
x86_l_25b0:
	/* 0x25b0: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_25b6:
	/* 0x25b6: lea    eax,[r13+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_25bd:
	/* 0x25bd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25c2:
	/* 0x25c2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_25c6:
	/* 0x25c6: mov    BYTE PTR [rsi+0x54],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_25c9:
	/* 0x25c9: cmp    r13,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 81ULL);
x86_l_25cd:
	/* 0x25cd: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_25d3:
	/* 0x25d3: lea    eax,[r13+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_25da:
	/* 0x25da: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25df:
	/* 0x25df: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_25e3:
	/* 0x25e3: mov    BYTE PTR [rsi+0x55],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_25e6:
	/* 0x25e6: cmp    r13,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 82ULL);
x86_l_25ea:
	/* 0x25ea: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_25f0:
	/* 0x25f0: lea    eax,[r13+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_25f7:
	/* 0x25f7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25fc:
	/* 0x25fc: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2600:
	/* 0x2600: mov    BYTE PTR [rsi+0x56],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2603:
	/* 0x2603: cmp    r13,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 83ULL);
x86_l_2607:
	/* 0x2607: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_260d:
	/* 0x260d: lea    eax,[r13+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_2614:
	/* 0x2614: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2619:
	/* 0x2619: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_261d:
	/* 0x261d: mov    BYTE PTR [rsi+0x57],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_2620:
	/* 0x2620: cmp    r13,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 84ULL);
x86_l_2624:
	/* 0x2624: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_262a:
	/* 0x262a: lea    eax,[r13+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_2631:
	/* 0x2631: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2636:
	/* 0x2636: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_263a:
	/* 0x263a: mov    BYTE PTR [rsi+0x58],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_263d:
	/* 0x263d: cmp    r13,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 85ULL);
x86_l_2641:
	/* 0x2641: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_2647:
	/* 0x2647: lea    eax,[r13+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_264e:
	/* 0x264e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2653:
	/* 0x2653: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2657:
	/* 0x2657: mov    BYTE PTR [rsi+0x59],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_265a:
	/* 0x265a: cmp    r13,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 86ULL);
x86_l_265e:
	/* 0x265e: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_2664:
	/* 0x2664: lea    eax,[r13+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_266b:
	/* 0x266b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2670:
	/* 0x2670: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2674:
	/* 0x2674: mov    BYTE PTR [rsi+0x5a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_2677:
	/* 0x2677: cmp    r13,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 87ULL);
x86_l_267b:
	/* 0x267b: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_2681:
	/* 0x2681: lea    eax,[r13+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_2688:
	/* 0x2688: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_268d:
	/* 0x268d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2691:
	/* 0x2691: mov    BYTE PTR [rsi+0x5b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_2694:
	/* 0x2694: cmp    r13,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 88ULL);
x86_l_2698:
	/* 0x2698: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_269e:
	/* 0x269e: lea    eax,[r13+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_26a5:
	/* 0x26a5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26aa:
	/* 0x26aa: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_26ae:
	/* 0x26ae: mov    BYTE PTR [rsi+0x5c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_26b1:
	/* 0x26b1: cmp    r13,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 89ULL);
x86_l_26b5:
	/* 0x26b5: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_26b7:
	/* 0x26b7: lea    eax,[r13+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_26be:
	/* 0x26be: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26c3:
	/* 0x26c3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_26c7:
	/* 0x26c7: mov    BYTE PTR [rsi+0x5d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_26ca:
	/* 0x26ca: cmp    r13,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 90ULL);
x86_l_26ce:
	/* 0x26ce: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_26d0:
	/* 0x26d0: lea    eax,[r13+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_26d7:
	/* 0x26d7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26dc:
	/* 0x26dc: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_26e0:
	/* 0x26e0: mov    BYTE PTR [rsi+0x5e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_26e3:
	/* 0x26e3: cmp    r13,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 91ULL);
x86_l_26e7:
	/* 0x26e7: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_26e9:
	/* 0x26e9: lea    eax,[r13+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_26f0:
	/* 0x26f0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26f5:
	/* 0x26f5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_26f9:
	/* 0x26f9: mov    BYTE PTR [rsi+0x5f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_26fc:
	/* 0x26fc: cmp    r13d,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 92ULL);
x86_l_2700:
	/* 0x2700: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_2702:
	/* 0x2702: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_2705:
	/* 0x2705: add    eax,0xfa3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4003ULL);
x86_l_270a:
	/* 0x270a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_270f:
	/* 0x270f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2713:
	/* 0x2713: mov    BYTE PTR [rsi+0x60],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2716:
	/* 0x2716: cmp    r13d,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 93ULL);
x86_l_271a:
	/* 0x271a: je     272f <generic_usdt_filter_arg_2+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_271c:
	/* 0x271c: lea    eax,[r13+0xfa2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4002ULL);
x86_l_2723:
	/* 0x2723: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2728:
	/* 0x2728: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_272c:
	/* 0x272c: mov    BYTE PTR [rsi+0x61],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_272f:
	/* 0x272f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2734:
	/* 0x2734: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2739:
	/* 0x2739: jmp    3150 <generic_usdt_filter_arg_2+0x3150> */
	return 12624ULL;
x86_l_273e:
	/* 0x273e: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2743:
	/* 0x2743: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2747:
	/* 0x2747: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_274a:
	/* 0x274a: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_274e:
	/* 0x274e: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2756:
	/* 0x2756: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_275d:
	/* 0x275d: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2762:
	/* 0x2762: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2767:
	/* 0x2767: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2769:
	/* 0x2769: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_276c:
	/* 0x276c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_276f:
	/* 0x276f: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2772:
	/* 0x2772: je     3161 <generic_usdt_filter_arg_2+0x3161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12641ULL;
	}
x86_l_2778:
	/* 0x2778: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_277d:
	/* 0x277d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2780:
	/* 0x2780: je     3161 <generic_usdt_filter_arg_2+0x3161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12641ULL;
	}
x86_l_2786:
	/* 0x2786: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_278d:
	/* 0x278d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2792:
	/* 0x2792: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2797:
	/* 0x2797: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2799:
	/* 0x2799: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_279c:
	/* 0x279c: je     315e <generic_usdt_filter_arg_2+0x315e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12638ULL;
	}
x86_l_27a2:
	/* 0x27a2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27a7:
	/* 0x27a7: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_27ab:
	/* 0x27ab: cmp    r13d,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 255ULL);
x86_l_27b2:
	/* 0x27b2: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_27b7:
	/* 0x27b7: cmovb  esi,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_27bb:
	/* 0x27bb: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_27c2:
	/* 0x27c2: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27c4:
	/* 0x27c4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_27c7:
	/* 0x27c7: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_27cb:
	/* 0x27cb: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_27ce:
	/* 0x27ce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27d3:
	/* 0x27d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27d5:
	/* 0x27d5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27da:
	/* 0x27da: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27df:
	/* 0x27df: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_27e2:
	/* 0x27e2: jmp    3150 <generic_usdt_filter_arg_2+0x3150> */
	return 12624ULL;
x86_l_27e7:
	/* 0x27e7: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_27ea:
	/* 0x27ea: je     27fc <generic_usdt_filter_arg_2+0x27fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27fc;
	}
x86_l_27ec:
	/* 0x27ec: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_27ef:
	/* 0x27ef: jne    3222 <generic_usdt_filter_arg_2+0x3222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12834ULL;
	}
x86_l_27f5:
	/* 0x27f5: movzx  edi,WORD PTR [r8+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_27fa:
	/* 0x27fa: jmp    2801 <generic_usdt_filter_arg_2+0x2801> */
	goto x86_l_2801;
x86_l_27fc:
	/* 0x27fc: movzx  edi,WORD PTR [r8+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_2801:
	/* 0x2801: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2803:
	/* 0x2803: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2806:
	/* 0x2806: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2809:
	/* 0x2809: jmp    2851 <generic_usdt_filter_arg_2+0x2851> */
	goto x86_l_2851;
x86_l_280b:
	/* 0x280b: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_280e:
	/* 0x280e: je     2c6f <generic_usdt_filter_arg_2+0x2c6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11375ULL;
	}
x86_l_2814:
	/* 0x2814: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_2817:
	/* 0x2817: jne    3222 <generic_usdt_filter_arg_2+0x3222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12834ULL;
	}
x86_l_281d:
	/* 0x281d: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2820:
	/* 0x2820: jne    2e3b <generic_usdt_filter_arg_2+0x2e3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11835ULL;
	}
x86_l_2826:
	/* 0x2826: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2829:
	/* 0x2829: jne    2e48 <generic_usdt_filter_arg_2+0x2e48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11848ULL;
	}
x86_l_282f:
	/* 0x282f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2832:
	/* 0x2832: jmp    2e57 <generic_usdt_filter_arg_2+0x2e57> */
	return 11863ULL;
x86_l_2837:
	/* 0x2837: mov    rdx,QWORD PTR [r8+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_283b:
	/* 0x283b: mov    r9,QWORD PTR [r8+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_283f:
	/* 0x283f: jmp    2848 <generic_usdt_filter_arg_2+0x2848> */
	goto x86_l_2848;
x86_l_2841:
	/* 0x2841: mov    rdx,QWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2844:
	/* 0x2844: mov    r9,QWORD PTR [r8+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2848:
	/* 0x2848: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_284b:
	/* 0x284b: shr    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_284f:
	/* 0x284f: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2851:
	/* 0x2851: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2854:
	/* 0x2854: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2857:
	/* 0x2857: jg     287b <generic_usdt_filter_arg_2+0x287b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_287b;
	}
x86_l_2859:
	/* 0x2859: lea    ecx,[rax-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_285c:
	/* 0x285c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_285f:
	/* 0x285f: jb     28a6 <generic_usdt_filter_arg_2+0x28a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_28a6;
	}
x86_l_2861:
	/* 0x2861: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_2864:
	/* 0x2864: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2867:
	/* 0x2867: jb     2907 <generic_usdt_filter_arg_2+0x2907> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2907;
	}
x86_l_286d:
	/* 0x286d: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2870:
	/* 0x2870: je     2c74 <generic_usdt_filter_arg_2+0x2c74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11380ULL;
	}
x86_l_2876:
	/* 0x2876: jmp    3222 <generic_usdt_filter_arg_2+0x3222> */
	return 12834ULL;
x86_l_287b:
	/* 0x287b: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_287e:
	/* 0x287e: ja     28fb <generic_usdt_filter_arg_2+0x28fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28fb;
	}
x86_l_2880:
	/* 0x2880: mov    ecx,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5242880ULL);
x86_l_2885:
	/* 0x2885: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2888:
	/* 0x2888: jb     2a40 <generic_usdt_filter_arg_2+0x2a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2a40;
	}
x86_l_288e:
	/* 0x288e: mov    ecx,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10485760ULL);
x86_l_2893:
	/* 0x2893: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2896:
	/* 0x2896: jb     2a54 <generic_usdt_filter_arg_2+0x2a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10836ULL;
	}
x86_l_289c:
	/* 0x289c: mov    ecx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 50331648ULL);
x86_l_28a1:
	/* 0x28a1: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_28a4:
	/* 0x28a4: jae    28fb <generic_usdt_filter_arg_2+0x28fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_28fb;
	}
x86_l_28a6:
	/* 0x28a6: movzx  eax,WORD PTR [r8+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_28ab:
	/* 0x28ab: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_28ae:
	/* 0x28ae: je     2a68 <generic_usdt_filter_arg_2+0x2a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10856ULL;
	}
x86_l_28b4:
	/* 0x28b4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_28b7:
	/* 0x28b7: jne    2af4 <generic_usdt_filter_arg_2+0x2af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10996ULL;
	}
x86_l_28bd:
	/* 0x28bd: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_28c0:
	/* 0x28c0: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_28c3:
	/* 0x28c3: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28c6:
	/* 0x28c6: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_28ca:
	/* 0x28ca: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_28d1:
	/* 0x28d1: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_28d6:
	/* 0x28d6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28db:
	/* 0x28db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28dd:
	/* 0x28dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28e0:
	/* 0x28e0: je     2ce9 <generic_usdt_filter_arg_2+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11497ULL;
	}
x86_l_28e6:
	/* 0x28e6: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_28e9:
	/* 0x28e9: mov    DWORD PTR [rsp+0x20],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953504ULL);
x86_l_28f1:
	/* 0x28f1: mov    DWORD PTR [rsp+0x24],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_28f6:
	/* 0x28f6: jmp    2ac0 <generic_usdt_filter_arg_2+0x2ac0> */
	return 10944ULL;
x86_l_28fb:
	/* 0x28fb: add    eax,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_28fe:
	/* 0x28fe: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2901:
	/* 0x2901: jae    3222 <generic_usdt_filter_arg_2+0x3222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12834ULL;
	}
x86_l_2907:
	/* 0x2907: mov    r13d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_32);
x86_l_290a:
	/* 0x290a: movzx  eax,BYTE PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_290e:
	/* 0x290e: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2912:
	/* 0x2912: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2919:
	/* 0x2919: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_291c:
	/* 0x291c: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2921:
	/* 0x2921: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2926:
	/* 0x2926: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2928:
	/* 0x2928: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_292b:
	/* 0x292b: je     2e94 <generic_usdt_filter_arg_2+0x2e94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11924ULL;
	}
x86_l_2931:
	/* 0x2931: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2934:
	/* 0x2934: movzx  eax,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2938:
	/* 0x2938: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_293d:
	/* 0x293d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2942:
	/* 0x2942: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2947:
	/* 0x2947: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2949:
	/* 0x2949: mov    edx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_294e:
	/* 0x294e: jmp    2cb7 <generic_usdt_filter_arg_2+0x2cb7> */
	return 11447ULL;
x86_l_2953:
	/* 0x2953: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2958:
	/* 0x2958: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_295c:
	/* 0x295c: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_295f:
	/* 0x295f: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2963:
	/* 0x2963: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_296b:
	/* 0x296b: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_2972:
	/* 0x2972: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2977:
	/* 0x2977: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_297c:
	/* 0x297c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_297e:
	/* 0x297e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2981:
	/* 0x2981: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2987:
	/* 0x2987: je     3200 <generic_usdt_filter_arg_2+0x3200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12800ULL;
	}
x86_l_298d:
	/* 0x298d: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2990:
	/* 0x2990: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2993:
	/* 0x2993: je     3200 <generic_usdt_filter_arg_2+0x3200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12800ULL;
	}
x86_l_2999:
	/* 0x2999: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_29a0:
	/* 0x29a0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29a5:
	/* 0x29a5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29aa:
	/* 0x29aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29ac:
	/* 0x29ac: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29af:
	/* 0x29af: je     31fd <generic_usdt_filter_arg_2+0x31fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12797ULL;
	}
x86_l_29b5:
	/* 0x29b5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29ba:
	/* 0x29ba: cmp    ecx,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_29c0:
	/* 0x29c0: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_29c5:
	/* 0x29c5: cmovb  esi,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_29c8:
	/* 0x29c8: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_29cf:
	/* 0x29cf: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29d1:
	/* 0x29d1: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_29d4:
	/* 0x29d4: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_29d8:
	/* 0x29d8: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_29db:
	/* 0x29db: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29e0:
	/* 0x29e0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29e5:
	/* 0x29e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29e7:
	/* 0x29e7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29ec:
	/* 0x29ec: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_29ef:
	/* 0x29ef: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_29f2:
	/* 0x29f2: jmp    31ef <generic_usdt_filter_arg_2+0x31ef> */
	return 12783ULL;
x86_l_29f7:
	/* 0x29f7: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_29ff:
	/* 0x29ff: cmp    edx,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_2a05:
	/* 0x2a05: ja     2c67 <generic_usdt_filter_arg_2+0x2c67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11367ULL;
	}
x86_l_2a0b:
	/* 0x2a0b: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a10:
	/* 0x2a10: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a14:
	/* 0x2a14: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2a17:
	/* 0x2a17: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2a1d:
	/* 0x2a1d: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_2a20:
	/* 0x2a20: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_2a23:
	/* 0x2a23: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2a26:
	/* 0x2a26: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2a28:
	/* 0x2a28: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2a2a:
	/* 0x2a2a: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_2a2d:
	/* 0x2a2d: je     2e9c <generic_usdt_filter_arg_2+0x2e9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11932ULL;
	}
x86_l_2a33:
	/* 0x2a33: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2a35:
	/* 0x2a35: jne    2e9c <generic_usdt_filter_arg_2+0x2e9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11932ULL;
	}
x86_l_2a3b:
	/* 0x2a3b: jmp    2eb3 <generic_usdt_filter_arg_2+0x2eb3> */
	return 11955ULL;
x86_l_2a40:
	/* 0x2a40: movzx  eax,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2a43:
	/* 0x2a43: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a46:
	/* 0x2a46: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
	return 10827ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10827ULL: goto x86_l_2a4b;
	case 10831ULL: goto x86_l_2a4f;
	case 10836ULL: goto x86_l_2a54;
	case 10839ULL: goto x86_l_2a57;
	case 10842ULL: goto x86_l_2a5a;
	case 10847ULL: goto x86_l_2a5f;
	case 10851ULL: goto x86_l_2a63;
	case 10856ULL: goto x86_l_2a68;
	case 10861ULL: goto x86_l_2a6d;
	case 10865ULL: goto x86_l_2a71;
	case 10868ULL: goto x86_l_2a74;
	case 10871ULL: goto x86_l_2a77;
	case 10875ULL: goto x86_l_2a7b;
	case 10882ULL: goto x86_l_2a82;
	case 10887ULL: goto x86_l_2a87;
	case 10892ULL: goto x86_l_2a8c;
	case 10894ULL: goto x86_l_2a8e;
	case 10897ULL: goto x86_l_2a91;
	case 10903ULL: goto x86_l_2a97;
	case 10906ULL: goto x86_l_2a9a;
	case 10914ULL: goto x86_l_2aa2;
	case 10918ULL: goto x86_l_2aa6;
	case 10922ULL: goto x86_l_2aaa;
	case 10927ULL: goto x86_l_2aaf;
	case 10932ULL: goto x86_l_2ab4;
	case 10936ULL: goto x86_l_2ab8;
	case 10940ULL: goto x86_l_2abc;
	case 10944ULL: goto x86_l_2ac0;
	case 10949ULL: goto x86_l_2ac5;
	case 10954ULL: goto x86_l_2aca;
	case 10956ULL: goto x86_l_2acc;
	case 10961ULL: goto x86_l_2ad1;
	case 10964ULL: goto x86_l_2ad4;
	case 10967ULL: goto x86_l_2ad7;
	case 10973ULL: goto x86_l_2add;
	case 10976ULL: goto x86_l_2ae0;
	case 10979ULL: goto x86_l_2ae3;
	case 10981ULL: goto x86_l_2ae5;
	case 10984ULL: goto x86_l_2ae8;
	case 10987ULL: goto x86_l_2aeb;
	case 10991ULL: goto x86_l_2aef;
	case 10996ULL: goto x86_l_2af4;
	case 10998ULL: goto x86_l_2af6;
	case 11002ULL: goto x86_l_2afa;
	case 11007ULL: goto x86_l_2aff;
	case 11010ULL: goto x86_l_2b02;
	case 11015ULL: goto x86_l_2b07;
	case 11019ULL: goto x86_l_2b0b;
	case 11025ULL: goto x86_l_2b11;
	case 11028ULL: goto x86_l_2b14;
	case 11031ULL: goto x86_l_2b17;
	case 11034ULL: goto x86_l_2b1a;
	case 11037ULL: goto x86_l_2b1d;
	case 11039ULL: goto x86_l_2b1f;
	case 11043ULL: goto x86_l_2b23;
	case 11049ULL: goto x86_l_2b29;
	case 11051ULL: goto x86_l_2b2b;
	case 11057ULL: goto x86_l_2b31;
	case 11060ULL: goto x86_l_2b34;
	case 11065ULL: goto x86_l_2b39;
	case 11068ULL: goto x86_l_2b3c;
	case 11071ULL: goto x86_l_2b3f;
	case 11073ULL: goto x86_l_2b41;
	case 11075ULL: goto x86_l_2b43;
	case 11078ULL: goto x86_l_2b46;
	case 11083ULL: goto x86_l_2b4b;
	case 11087ULL: goto x86_l_2b4f;
	case 11089ULL: goto x86_l_2b51;
	case 11093ULL: goto x86_l_2b55;
	case 11099ULL: goto x86_l_2b5b;
	case 11102ULL: goto x86_l_2b5e;
	case 11104ULL: goto x86_l_2b60;
	case 11108ULL: goto x86_l_2b64;
	case 11113ULL: goto x86_l_2b69;
	case 11118ULL: goto x86_l_2b6e;
	case 11122ULL: goto x86_l_2b72;
	case 11125ULL: goto x86_l_2b75;
	case 11129ULL: goto x86_l_2b79;
	case 11133ULL: goto x86_l_2b7d;
	case 11136ULL: goto x86_l_2b80;
	case 11142ULL: goto x86_l_2b86;
	case 11146ULL: goto x86_l_2b8a;
	case 11153ULL: goto x86_l_2b91;
	case 11158ULL: goto x86_l_2b96;
	case 11163ULL: goto x86_l_2b9b;
	case 11166ULL: goto x86_l_2b9e;
	case 11168ULL: goto x86_l_2ba0;
	case 11171ULL: goto x86_l_2ba3;
	case 11178ULL: goto x86_l_2baa;
	case 11183ULL: goto x86_l_2baf;
	case 11186ULL: goto x86_l_2bb2;
	case 11188ULL: goto x86_l_2bb4;
	case 11191ULL: goto x86_l_2bb7;
	case 11196ULL: goto x86_l_2bbc;
	case 11199ULL: goto x86_l_2bbf;
	case 11205ULL: goto x86_l_2bc5;
	case 11208ULL: goto x86_l_2bc8;
	case 11212ULL: goto x86_l_2bcc;
	case 11218ULL: goto x86_l_2bd2;
	case 11221ULL: goto x86_l_2bd5;
	case 11226ULL: goto x86_l_2bda;
	case 11231ULL: goto x86_l_2bdf;
	case 11234ULL: goto x86_l_2be2;
	case 11238ULL: goto x86_l_2be6;
	case 11243ULL: goto x86_l_2beb;
	case 11248ULL: goto x86_l_2bf0;
	case 11251ULL: goto x86_l_2bf3;
	case 11253ULL: goto x86_l_2bf5;
	case 11258ULL: goto x86_l_2bfa;
	case 11261ULL: goto x86_l_2bfd;
	case 11263ULL: goto x86_l_2bff;
	case 11268ULL: goto x86_l_2c04;
	case 11272ULL: goto x86_l_2c08;
	case 11275ULL: goto x86_l_2c0b;
	case 11278ULL: goto x86_l_2c0e;
	case 11284ULL: goto x86_l_2c14;
	case 11289ULL: goto x86_l_2c19;
	case 11292ULL: goto x86_l_2c1c;
	case 11294ULL: goto x86_l_2c1e;
	case 11298ULL: goto x86_l_2c22;
	case 11302ULL: goto x86_l_2c26;
	case 11306ULL: goto x86_l_2c2a;
	case 11309ULL: goto x86_l_2c2d;
	case 11315ULL: goto x86_l_2c33;
	case 11317ULL: goto x86_l_2c35;
	case 11323ULL: goto x86_l_2c3b;
	case 11328ULL: goto x86_l_2c40;
	case 11334ULL: goto x86_l_2c46;
	case 11339ULL: goto x86_l_2c4b;
	case 11345ULL: goto x86_l_2c51;
	case 11352ULL: goto x86_l_2c58;
	case 11357ULL: goto x86_l_2c5d;
	case 11362ULL: goto x86_l_2c62;
	case 11367ULL: goto x86_l_2c67;
	case 11370ULL: goto x86_l_2c6a;
	case 11375ULL: goto x86_l_2c6f;
	case 11380ULL: goto x86_l_2c74;
	case 11384ULL: goto x86_l_2c78;
	case 11388ULL: goto x86_l_2c7c;
	case 11395ULL: goto x86_l_2c83;
	case 11398ULL: goto x86_l_2c86;
	case 11403ULL: goto x86_l_2c8b;
	case 11408ULL: goto x86_l_2c90;
	case 11410ULL: goto x86_l_2c92;
	case 11413ULL: goto x86_l_2c95;
	case 11419ULL: goto x86_l_2c9b;
	case 11422ULL: goto x86_l_2c9e;
	case 11426ULL: goto x86_l_2ca2;
	case 11431ULL: goto x86_l_2ca7;
	case 11436ULL: goto x86_l_2cac;
	case 11441ULL: goto x86_l_2cb1;
	case 11443ULL: goto x86_l_2cb3;
	case 11447ULL: goto x86_l_2cb7;
	case 11449ULL: goto x86_l_2cb9;
	case 11452ULL: goto x86_l_2cbc;
	case 11454ULL: goto x86_l_2cbe;
	case 11459ULL: goto x86_l_2cc3;
	case 11462ULL: goto x86_l_2cc6;
	case 11464ULL: goto x86_l_2cc8;
	case 11467ULL: goto x86_l_2ccb;
	case 11470ULL: goto x86_l_2cce;
	case 11472ULL: goto x86_l_2cd0;
	case 11477ULL: goto x86_l_2cd5;
	case 11480ULL: goto x86_l_2cd8;
	case 11482ULL: goto x86_l_2cda;
	case 11485ULL: goto x86_l_2cdd;
	case 11488ULL: goto x86_l_2ce0;
	case 11492ULL: goto x86_l_2ce4;
	case 11497ULL: goto x86_l_2ce9;
	case 11502ULL: goto x86_l_2cee;
	case 11505ULL: goto x86_l_2cf1;
	case 11508ULL: goto x86_l_2cf4;
	case 11510ULL: goto x86_l_2cf6;
	case 11513ULL: goto x86_l_2cf9;
	case 11516ULL: goto x86_l_2cfc;
	case 11520ULL: goto x86_l_2d00;
	case 11525ULL: goto x86_l_2d05;
	case 11528ULL: goto x86_l_2d08;
	case 11531ULL: goto x86_l_2d0b;
	case 11533ULL: goto x86_l_2d0d;
	case 11535ULL: goto x86_l_2d0f;
	case 11538ULL: goto x86_l_2d12;
	case 11543ULL: goto x86_l_2d17;
	case 11547ULL: goto x86_l_2d1b;
	case 11549ULL: goto x86_l_2d1d;
	case 11552ULL: goto x86_l_2d20;
	case 11558ULL: goto x86_l_2d26;
	case 11561ULL: goto x86_l_2d29;
	case 11563ULL: goto x86_l_2d2b;
	case 11567ULL: goto x86_l_2d2f;
	case 11572ULL: goto x86_l_2d34;
	case 11577ULL: goto x86_l_2d39;
	case 11581ULL: goto x86_l_2d3d;
	case 11584ULL: goto x86_l_2d40;
	case 11588ULL: goto x86_l_2d44;
	case 11592ULL: goto x86_l_2d48;
	case 11596ULL: goto x86_l_2d4c;
	case 11599ULL: goto x86_l_2d4f;
	case 11605ULL: goto x86_l_2d55;
	case 11612ULL: goto x86_l_2d5c;
	case 11617ULL: goto x86_l_2d61;
	case 11622ULL: goto x86_l_2d66;
	case 11625ULL: goto x86_l_2d69;
	case 11627ULL: goto x86_l_2d6b;
	case 11630ULL: goto x86_l_2d6e;
	case 11637ULL: goto x86_l_2d75;
	case 11642ULL: goto x86_l_2d7a;
	case 11645ULL: goto x86_l_2d7d;
	case 11647ULL: goto x86_l_2d7f;
	case 11650ULL: goto x86_l_2d82;
	case 11655ULL: goto x86_l_2d87;
	case 11658ULL: goto x86_l_2d8a;
	case 11664ULL: goto x86_l_2d90;
	case 11667ULL: goto x86_l_2d93;
	case 11671ULL: goto x86_l_2d97;
	case 11677ULL: goto x86_l_2d9d;
	case 11680ULL: goto x86_l_2da0;
	case 11685ULL: goto x86_l_2da5;
	case 11689ULL: goto x86_l_2da9;
	case 11694ULL: goto x86_l_2dae;
	case 11699ULL: goto x86_l_2db3;
	case 11702ULL: goto x86_l_2db6;
	case 11706ULL: goto x86_l_2dba;
	case 11711ULL: goto x86_l_2dbf;
	case 11714ULL: goto x86_l_2dc2;
	case 11716ULL: goto x86_l_2dc4;
	case 11721ULL: goto x86_l_2dc9;
	case 11724ULL: goto x86_l_2dcc;
	case 11726ULL: goto x86_l_2dce;
	case 11731ULL: goto x86_l_2dd3;
	case 11736ULL: goto x86_l_2dd8;
	case 11740ULL: goto x86_l_2ddc;
	case 11743ULL: goto x86_l_2ddf;
	case 11745ULL: goto x86_l_2de1;
	case 11751ULL: goto x86_l_2de7;
	case 11756ULL: goto x86_l_2dec;
	case 11759ULL: goto x86_l_2def;
	case 11761ULL: goto x86_l_2df1;
	case 11765ULL: goto x86_l_2df5;
	case 11769ULL: goto x86_l_2df9;
	case 11774ULL: goto x86_l_2dfe;
	case 11780ULL: goto x86_l_2e04;
	case 11785ULL: goto x86_l_2e09;
	case 11791ULL: goto x86_l_2e0f;
	case 11796ULL: goto x86_l_2e14;
	case 11802ULL: goto x86_l_2e1a;
	case 11807ULL: goto x86_l_2e1f;
	case 11813ULL: goto x86_l_2e25;
	case 11820ULL: goto x86_l_2e2c;
	case 11825ULL: goto x86_l_2e31;
	case 11830ULL: goto x86_l_2e36;
	case 11835ULL: goto x86_l_2e3b;
	case 11838ULL: goto x86_l_2e3e;
	case 11841ULL: goto x86_l_2e41;
	case 11843ULL: goto x86_l_2e43;
	case 11846ULL: goto x86_l_2e46;
	case 11848ULL: goto x86_l_2e48;
	case 11853ULL: goto x86_l_2e4d;
	case 11856ULL: goto x86_l_2e50;
	case 11858ULL: goto x86_l_2e52;
	case 11861ULL: goto x86_l_2e55;
	case 11863ULL: goto x86_l_2e57;
	case 11866ULL: goto x86_l_2e5a;
	case 11870ULL: goto x86_l_2e5e;
	case 11874ULL: goto x86_l_2e62;
	case 11881ULL: goto x86_l_2e69;
	case 11886ULL: goto x86_l_2e6e;
	case 11891ULL: goto x86_l_2e73;
	case 11893ULL: goto x86_l_2e75;
	case 11896ULL: goto x86_l_2e78;
	case 11898ULL: goto x86_l_2e7a;
	case 11901ULL: goto x86_l_2e7d;
	case 11904ULL: goto x86_l_2e80;
	case 11909ULL: goto x86_l_2e85;
	case 11914ULL: goto x86_l_2e8a;
	case 11919ULL: goto x86_l_2e8f;
	case 11924ULL: goto x86_l_2e94;
	case 11927ULL: goto x86_l_2e97;
	case 11932ULL: goto x86_l_2e9c;
	case 11935ULL: goto x86_l_2e9f;
	case 11937ULL: goto x86_l_2ea1;
	case 11939ULL: goto x86_l_2ea3;
	case 11941ULL: goto x86_l_2ea5;
	case 11944ULL: goto x86_l_2ea8;
	case 11949ULL: goto x86_l_2ead;
	case 11953ULL: goto x86_l_2eb1;
	case 11955ULL: goto x86_l_2eb3;
	case 11958ULL: goto x86_l_2eb6;
	case 11964ULL: goto x86_l_2ebc;
	case 11967ULL: goto x86_l_2ebf;
	case 11969ULL: goto x86_l_2ec1;
	case 11973ULL: goto x86_l_2ec5;
	case 11977ULL: goto x86_l_2ec9;
	case 11980ULL: goto x86_l_2ecc;
	case 11984ULL: goto x86_l_2ed0;
	case 11988ULL: goto x86_l_2ed4;
	case 11992ULL: goto x86_l_2ed8;
	case 11995ULL: goto x86_l_2edb;
	case 12001ULL: goto x86_l_2ee1;
	case 12008ULL: goto x86_l_2ee8;
	case 12013ULL: goto x86_l_2eed;
	case 12018ULL: goto x86_l_2ef2;
	case 12021ULL: goto x86_l_2ef5;
	case 12023ULL: goto x86_l_2ef7;
	case 12026ULL: goto x86_l_2efa;
	case 12033ULL: goto x86_l_2f01;
	case 12038ULL: goto x86_l_2f06;
	case 12041ULL: goto x86_l_2f09;
	case 12043ULL: goto x86_l_2f0b;
	case 12051ULL: goto x86_l_2f13;
	case 12054ULL: goto x86_l_2f16;
	case 12059ULL: goto x86_l_2f1b;
	case 12062ULL: goto x86_l_2f1e;
	case 12068ULL: goto x86_l_2f24;
	case 12077ULL: goto x86_l_2f2d;
	case 12081ULL: goto x86_l_2f31;
	case 12087ULL: goto x86_l_2f37;
	case 12092ULL: goto x86_l_2f3c;
	case 12097ULL: goto x86_l_2f41;
	case 12100ULL: goto x86_l_2f44;
	case 12104ULL: goto x86_l_2f48;
	case 12109ULL: goto x86_l_2f4d;
	case 12114ULL: goto x86_l_2f52;
	case 12117ULL: goto x86_l_2f55;
	case 12119ULL: goto x86_l_2f57;
	case 12124ULL: goto x86_l_2f5c;
	case 12127ULL: goto x86_l_2f5f;
	case 12129ULL: goto x86_l_2f61;
	case 12134ULL: goto x86_l_2f66;
	case 12139ULL: goto x86_l_2f6b;
	case 12143ULL: goto x86_l_2f6f;
	case 12146ULL: goto x86_l_2f72;
	case 12148ULL: goto x86_l_2f74;
	case 12154ULL: goto x86_l_2f7a;
	case 12159ULL: goto x86_l_2f7f;
	case 12167ULL: goto x86_l_2f87;
	case 12169ULL: goto x86_l_2f89;
	case 12173ULL: goto x86_l_2f8d;
	case 12177ULL: goto x86_l_2f91;
	case 12182ULL: goto x86_l_2f96;
	case 12188ULL: goto x86_l_2f9c;
	case 12193ULL: goto x86_l_2fa1;
	case 12199ULL: goto x86_l_2fa7;
	case 12204ULL: goto x86_l_2fac;
	case 12210ULL: goto x86_l_2fb2;
	case 12215ULL: goto x86_l_2fb7;
	case 12221ULL: goto x86_l_2fbd;
	case 12228ULL: goto x86_l_2fc4;
	case 12233ULL: goto x86_l_2fc9;
	case 12238ULL: goto x86_l_2fce;
	case 12243ULL: goto x86_l_2fd3;
	case 12246ULL: goto x86_l_2fd6;
	case 12252ULL: goto x86_l_2fdc;
	case 12257ULL: goto x86_l_2fe1;
	case 12263ULL: goto x86_l_2fe7;
	case 12268ULL: goto x86_l_2fec;
	case 12274ULL: goto x86_l_2ff2;
	case 12281ULL: goto x86_l_2ff9;
	case 12286ULL: goto x86_l_2ffe;
	case 12291ULL: goto x86_l_3003;
	case 12296ULL: goto x86_l_3008;
	case 12299ULL: goto x86_l_300b;
	case 12302ULL: goto x86_l_300e;
	case 12307ULL: goto x86_l_3013;
	case 12312ULL: goto x86_l_3018;
	case 12318ULL: goto x86_l_301e;
	case 12323ULL: goto x86_l_3023;
	case 12329ULL: goto x86_l_3029;
	case 12334ULL: goto x86_l_302e;
	case 12340ULL: goto x86_l_3034;
	case 12347ULL: goto x86_l_303b;
	case 12352ULL: goto x86_l_3040;
	case 12357ULL: goto x86_l_3045;
	case 12362ULL: goto x86_l_304a;
	case 12367ULL: goto x86_l_304f;
	case 12373ULL: goto x86_l_3055;
	case 12378ULL: goto x86_l_305a;
	case 12384ULL: goto x86_l_3060;
	case 12389ULL: goto x86_l_3065;
	case 12395ULL: goto x86_l_306b;
	case 12402ULL: goto x86_l_3072;
	case 12407ULL: goto x86_l_3077;
	case 12412ULL: goto x86_l_307c;
	case 12417ULL: goto x86_l_3081;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a4b:
	/* 0x2a4b: setb   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_B);
x86_l_2a4f:
	/* 0x2a4f: jmp    3222 <generic_usdt_filter_arg_2+0x3222> */
	return 12834ULL;
x86_l_2a54:
	/* 0x2a54: movzx  eax,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2a57:
	/* 0x2a57: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a5a:
	/* 0x2a5a: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_2a5f:
	/* 0x2a5f: setae  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_AE);
x86_l_2a63:
	/* 0x2a63: jmp    3222 <generic_usdt_filter_arg_2+0x3222> */
	return 12834ULL;
x86_l_2a68:
	/* 0x2a68: mov    QWORD PTR [rsp+0x10],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a6d:
	/* 0x2a6d: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a71:
	/* 0x2a71: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_2a74:
	/* 0x2a74: mov    eax,DWORD PTR [rsi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2a77:
	/* 0x2a77: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2a7b:
	/* 0x2a7b: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_2a82:
	/* 0x2a82: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2a87:
	/* 0x2a87: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a8c:
	/* 0x2a8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a8e:
	/* 0x2a8e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a91:
	/* 0x2a91: je     2ce9 <generic_usdt_filter_arg_2+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ce9;
	}
x86_l_2a97:
	/* 0x2a97: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2a9a:
	/* 0x2a9a: mov    DWORD PTR [rsp+0x20],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953600ULL);
x86_l_2aa2:
	/* 0x2aa2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aa6:
	/* 0x2aa6: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2aaa:
	/* 0x2aaa: mov    DWORD PTR [rsp+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2aaf:
	/* 0x2aaf: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ab4:
	/* 0x2ab4: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2ab8:
	/* 0x2ab8: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2abc:
	/* 0x2abc: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ac0:
	/* 0x2ac0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ac5:
	/* 0x2ac5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2aca:
	/* 0x2aca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2acc:
	/* 0x2acc: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ad1:
	/* 0x2ad1: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_2ad4:
	/* 0x2ad4: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2ad7:
	/* 0x2ad7: jb     2cf6 <generic_usdt_filter_arg_2+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2cf6;
	}
x86_l_2add:
	/* 0x2add: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_2ae0:
	/* 0x2ae0: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2ae3:
	/* 0x2ae3: ja     2af4 <generic_usdt_filter_arg_2+0x2af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2af4;
	}
x86_l_2ae5:
	/* 0x2ae5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ae8:
	/* 0x2ae8: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_2aeb:
	/* 0x2aeb: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2aef:
	/* 0x2aef: jmp    3222 <generic_usdt_filter_arg_2+0x3222> */
	return 12834ULL;
x86_l_2af4:
	/* 0x2af4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2af6:
	/* 0x2af6: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2afa:
	/* 0x2afa: jmp    3222 <generic_usdt_filter_arg_2+0x3222> */
	return 12834ULL;
x86_l_2aff:
	/* 0x2aff: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b02:
	/* 0x2b02: jmp    3168 <generic_usdt_filter_arg_2+0x3168> */
	return 12648ULL;
x86_l_2b07:
	/* 0x2b07: movzx  eax,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2b0b:
	/* 0x2b0b: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2b11:
	/* 0x2b11: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_2b14:
	/* 0x2b14: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_2b17:
	/* 0x2b17: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2b1a:
	/* 0x2b1a: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_2b1d:
	/* 0x2b1d: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2b1f:
	/* 0x2b1f: test   r13w,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_16);
x86_l_2b23:
	/* 0x2b23: je     2d05 <generic_usdt_filter_arg_2+0x2d05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d05;
	}
x86_l_2b29:
	/* 0x2b29: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2b2b:
	/* 0x2b2b: jne    2d05 <generic_usdt_filter_arg_2+0x2d05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d05;
	}
x86_l_2b31:
	/* 0x2b31: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_2b34:
	/* 0x2b34: jmp    2d1d <generic_usdt_filter_arg_2+0x2d1d> */
	goto x86_l_2d1d;
x86_l_2b39:
	/* 0x2b39: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2b3c:
	/* 0x2b3c: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_2b3f:
	/* 0x2b3f: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b41:
	/* 0x2b41: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_2b43:
	/* 0x2b43: add    edi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2b46:
	/* 0x2b46: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2b4b:
	/* 0x2b4b: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2b4f:
	/* 0x2b4f: ja     2b60 <generic_usdt_filter_arg_2+0x2b60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b60;
	}
x86_l_2b51:
	/* 0x2b51: movzx  eax,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2b55:
	/* 0x2b55: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2b5b:
	/* 0x2b5b: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2b5e:
	/* 0x2b5e: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2b60:
	/* 0x2b60: mov    DWORD PTR [rsp+0x4c],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2b64:
	/* 0x2b64: mov    QWORD PTR [rsp+0x38],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b69:
	/* 0x2b69: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b6e:
	/* 0x2b6e: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b72:
	/* 0x2b72: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2b75:
	/* 0x2b75: mov    eax,DWORD PTR [rsi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2b79:
	/* 0x2b79: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b7d:
	/* 0x2b7d: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2b80:
	/* 0x2b80: je     2c67 <generic_usdt_filter_arg_2+0x2c67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c67;
	}
x86_l_2b86:
	/* 0x2b86: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b8a:
	/* 0x2b8a: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2b91:
	/* 0x2b91: lea    r12,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b96:
	/* 0x2b96: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b9b:
	/* 0x2b9b: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2b9e:
	/* 0x2b9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ba0:
	/* 0x2ba0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2ba3:
	/* 0x2ba3: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2baa:
	/* 0x2baa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2baf:
	/* 0x2baf: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2bb2:
	/* 0x2bb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bb4:
	/* 0x2bb4: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bb7:
	/* 0x2bb7: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bbc:
	/* 0x2bbc: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2bbf:
	/* 0x2bbf: je     3200 <generic_usdt_filter_arg_2+0x3200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12800ULL;
	}
x86_l_2bc5:
	/* 0x2bc5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bc8:
	/* 0x2bc8: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bcc:
	/* 0x2bcc: je     3204 <generic_usdt_filter_arg_2+0x3204> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12804ULL;
	}
x86_l_2bd2:
	/* 0x2bd2: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2bd5:
	/* 0x2bd5: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2bda:
	/* 0x2bda: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bdf:
	/* 0x2bdf: mov    BYTE PTR [rax],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2be2:
	/* 0x2be2: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2be6:
	/* 0x2be6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2beb:
	/* 0x2beb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bf0:
	/* 0x2bf0: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2bf3:
	/* 0x2bf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf5:
	/* 0x2bf5: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_2bfa:
	/* 0x2bfa: cmp    esi,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2bfd:
	/* 0x2bfd: jbe    2c1e <generic_usdt_filter_arg_2+0x2c1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2c1e;
	}
x86_l_2bff:
	/* 0x2bff: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c04:
	/* 0x2c04: lea    rdi,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2c08:
	/* 0x2c08: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2c0b:
	/* 0x2c0b: sub    esi,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c0e:
	/* 0x2c0e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c14:
	/* 0x2c14: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c19:
	/* 0x2c19: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2c1c:
	/* 0x2c1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c1e:
	/* 0x2c1e: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2c22:
	/* 0x2c22: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c26:
	/* 0x2c26: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c2a:
	/* 0x2c2a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c2d:
	/* 0x2c2d: jg     2fd3 <generic_usdt_filter_arg_2+0x2fd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2fd3;
	}
x86_l_2c33:
	/* 0x2c33: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c35:
	/* 0x2c35: je     3081 <generic_usdt_filter_arg_2+0x3081> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3081;
	}
x86_l_2c3b:
	/* 0x2c3b: cmp    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2c40:
	/* 0x2c40: je     30a7 <generic_usdt_filter_arg_2+0x30a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12455ULL;
	}
x86_l_2c46:
	/* 0x2c46: cmp    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_2c4b:
	/* 0x2c4b: jne    31fd <generic_usdt_filter_arg_2+0x31fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12797ULL;
	}
x86_l_2c51:
	/* 0x2c51: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2c58:
	/* 0x2c58: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c5d:
	/* 0x2c5d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c62:
	/* 0x2c62: jmp    30cb <generic_usdt_filter_arg_2+0x30cb> */
	return 12491ULL;
x86_l_2c67:
	/* 0x2c67: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c6a:
	/* 0x2c6a: jmp    3204 <generic_usdt_filter_arg_2+0x3204> */
	return 12804ULL;
x86_l_2c6f:
	/* 0x2c6f: movzx  r12d,WORD PTR [r8+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2c74:
	/* 0x2c74: movzx  eax,BYTE PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2c78:
	/* 0x2c78: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2c7c:
	/* 0x2c7c: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2c83:
	/* 0x2c83: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_2c86:
	/* 0x2c86: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2c8b:
	/* 0x2c8b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c90:
	/* 0x2c90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c92:
	/* 0x2c92: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c95:
	/* 0x2c95: je     2e94 <generic_usdt_filter_arg_2+0x2e94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e94;
	}
x86_l_2c9b:
	/* 0x2c9b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2c9e:
	/* 0x2c9e: movzx  eax,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2ca2:
	/* 0x2ca2: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ca7:
	/* 0x2ca7: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2cac:
	/* 0x2cac: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cb1:
	/* 0x2cb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cb3:
	/* 0x2cb3: mov    edx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2cb7:
	/* 0x2cb7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cb9:
	/* 0x2cb9: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_2cbc:
	/* 0x2cbc: ja     2ce0 <generic_usdt_filter_arg_2+0x2ce0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2ce0;
	}
x86_l_2cbe:
	/* 0x2cbe: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_2cc3:
	/* 0x2cc3: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2cc6:
	/* 0x2cc6: jae    2cd0 <generic_usdt_filter_arg_2+0x2cd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2cd0;
	}
x86_l_2cc8:
	/* 0x2cc8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ccb:
	/* 0x2ccb: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_2cce:
	/* 0x2cce: jmp    2ce0 <generic_usdt_filter_arg_2+0x2ce0> */
	goto x86_l_2ce0;
x86_l_2cd0:
	/* 0x2cd0: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_2cd5:
	/* 0x2cd5: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2cd8:
	/* 0x2cd8: jae    2ce0 <generic_usdt_filter_arg_2+0x2ce0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2ce0;
	}
x86_l_2cda:
	/* 0x2cda: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cdd:
	/* 0x2cdd: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_2ce0:
	/* 0x2ce0: movzx  r12d,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2ce4:
	/* 0x2ce4: jmp    3222 <generic_usdt_filter_arg_2+0x3222> */
	return 12834ULL;
x86_l_2ce9:
	/* 0x2ce9: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2cee:
	/* 0x2cee: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_2cf1:
	/* 0x2cf1: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_2cf4:
	/* 0x2cf4: jmp    2cf9 <generic_usdt_filter_arg_2+0x2cf9> */
	goto x86_l_2cf9;
x86_l_2cf6:
	/* 0x2cf6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cf9:
	/* 0x2cf9: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2cfc:
	/* 0x2cfc: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2d00:
	/* 0x2d00: jmp    3222 <generic_usdt_filter_arg_2+0x3222> */
	return 12834ULL;
x86_l_2d05:
	/* 0x2d05: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2d08:
	/* 0x2d08: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_2d0b:
	/* 0x2d0b: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d0d:
	/* 0x2d0d: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2d0f:
	/* 0x2d0f: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2d12:
	/* 0x2d12: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2d17:
	/* 0x2d17: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2d1b:
	/* 0x2d1b: ja     2d2b <generic_usdt_filter_arg_2+0x2d2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2d2b;
	}
x86_l_2d1d:
	/* 0x2d1d: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2d20:
	/* 0x2d20: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2d26:
	/* 0x2d26: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2d29:
	/* 0x2d29: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2d2b:
	/* 0x2d2b: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2d2f:
	/* 0x2d2f: mov    QWORD PTR [rsp+0x38],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d34:
	/* 0x2d34: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d39:
	/* 0x2d39: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d3d:
	/* 0x2d3d: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2d40:
	/* 0x2d40: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d44:
	/* 0x2d44: mov    eax,DWORD PTR [rsi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2d48:
	/* 0x2d48: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2d4c:
	/* 0x2d4c: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2d4f:
	/* 0x2d4f: je     315e <generic_usdt_filter_arg_2+0x315e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12638ULL;
	}
x86_l_2d55:
	/* 0x2d55: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2d5c:
	/* 0x2d5c: lea    r12,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d61:
	/* 0x2d61: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d66:
	/* 0x2d66: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2d69:
	/* 0x2d69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d6b:
	/* 0x2d6b: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2d6e:
	/* 0x2d6e: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2d75:
	/* 0x2d75: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d7a:
	/* 0x2d7a: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2d7d:
	/* 0x2d7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d7f:
	/* 0x2d7f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d82:
	/* 0x2d82: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d87:
	/* 0x2d87: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2d8a:
	/* 0x2d8a: je     3161 <generic_usdt_filter_arg_2+0x3161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12641ULL;
	}
x86_l_2d90:
	/* 0x2d90: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d93:
	/* 0x2d93: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d97:
	/* 0x2d97: je     3165 <generic_usdt_filter_arg_2+0x3165> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12645ULL;
	}
x86_l_2d9d:
	/* 0x2d9d: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2da0:
	/* 0x2da0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2da5:
	/* 0x2da5: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2da9:
	/* 0x2da9: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2dae:
	/* 0x2dae: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2db3:
	/* 0x2db3: mov    BYTE PTR [rax],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2db6:
	/* 0x2db6: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2dba:
	/* 0x2dba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2dbf:
	/* 0x2dbf: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2dc2:
	/* 0x2dc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dc4:
	/* 0x2dc4: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_2dc9:
	/* 0x2dc9: cmp    esi,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2dcc:
	/* 0x2dcc: jbe    2df1 <generic_usdt_filter_arg_2+0x2df1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2df1;
	}
x86_l_2dce:
	/* 0x2dce: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2dd3:
	/* 0x2dd3: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2dd8:
	/* 0x2dd8: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2ddc:
	/* 0x2ddc: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2ddf:
	/* 0x2ddf: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2de1:
	/* 0x2de1: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2de7:
	/* 0x2de7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2dec:
	/* 0x2dec: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2def:
	/* 0x2def: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2df1:
	/* 0x2df1: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2df5:
	/* 0x2df5: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2df9:
	/* 0x2df9: cmp    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_2dfe:
	/* 0x2dfe: jg     3013 <generic_usdt_filter_arg_2+0x3013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3013;
	}
x86_l_2e04:
	/* 0x2e04: cmp    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2e09:
	/* 0x2e09: je     30ed <generic_usdt_filter_arg_2+0x30ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12525ULL;
	}
x86_l_2e0f:
	/* 0x2e0f: cmp    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2e14:
	/* 0x2e14: je     3113 <generic_usdt_filter_arg_2+0x3113> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12563ULL;
	}
x86_l_2e1a:
	/* 0x2e1a: cmp    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_2e1f:
	/* 0x2e1f: jne    315e <generic_usdt_filter_arg_2+0x315e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12638ULL;
	}
x86_l_2e25:
	/* 0x2e25: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2e2c:
	/* 0x2e2c: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e31:
	/* 0x2e31: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e36:
	/* 0x2e36: jmp    3137 <generic_usdt_filter_arg_2+0x3137> */
	return 12599ULL;
x86_l_2e3b:
	/* 0x2e3b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e3e:
	/* 0x2e3e: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2e41:
	/* 0x2e41: jne    2e4d <generic_usdt_filter_arg_2+0x2e4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e4d;
	}
x86_l_2e43:
	/* 0x2e43: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2e46:
	/* 0x2e46: je     2e4d <generic_usdt_filter_arg_2+0x2e4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e4d;
	}
x86_l_2e48:
	/* 0x2e48: movzx  r12d,BYTE PTR [rdx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_2e4d:
	/* 0x2e4d: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2e50:
	/* 0x2e50: je     2e57 <generic_usdt_filter_arg_2+0x2e57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e57;
	}
x86_l_2e52:
	/* 0x2e52: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2e55:
	/* 0x2e55: jne    2e94 <generic_usdt_filter_arg_2+0x2e94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e94;
	}
x86_l_2e57:
	/* 0x2e57: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_2e5a:
	/* 0x2e5a: movzx  eax,BYTE PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2e5e:
	/* 0x2e5e: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2e62:
	/* 0x2e62: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2e69:
	/* 0x2e69: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2e6e:
	/* 0x2e6e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e73:
	/* 0x2e73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e75:
	/* 0x2e75: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e78:
	/* 0x2e78: je     2e94 <generic_usdt_filter_arg_2+0x2e94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e94;
	}
x86_l_2e7a:
	/* 0x2e7a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2e7d:
	/* 0x2e7d: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_2e80:
	/* 0x2e80: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e85:
	/* 0x2e85: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e8a:
	/* 0x2e8a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e8f:
	/* 0x2e8f: jmp    2cb1 <generic_usdt_filter_arg_2+0x2cb1> */
	goto x86_l_2cb1;
x86_l_2e94:
	/* 0x2e94: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e97:
	/* 0x2e97: jmp    3222 <generic_usdt_filter_arg_2+0x3222> */
	return 12834ULL;
x86_l_2e9c:
	/* 0x2e9c: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e9f:
	/* 0x2e9f: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2ea1:
	/* 0x2ea1: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ea3:
	/* 0x2ea3: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2ea5:
	/* 0x2ea5: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2ea8:
	/* 0x2ea8: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2ead:
	/* 0x2ead: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2eb1:
	/* 0x2eb1: ja     2ec1 <generic_usdt_filter_arg_2+0x2ec1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2ec1;
	}
x86_l_2eb3:
	/* 0x2eb3: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2eb6:
	/* 0x2eb6: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2ebc:
	/* 0x2ebc: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2ebf:
	/* 0x2ebf: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2ec1:
	/* 0x2ec1: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2ec5:
	/* 0x2ec5: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ec9:
	/* 0x2ec9: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2ecc:
	/* 0x2ecc: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ed0:
	/* 0x2ed0: mov    eax,DWORD PTR [rcx+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2ed4:
	/* 0x2ed4: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2ed8:
	/* 0x2ed8: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2edb:
	/* 0x2edb: je     31fd <generic_usdt_filter_arg_2+0x31fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12797ULL;
	}
x86_l_2ee1:
	/* 0x2ee1: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2ee8:
	/* 0x2ee8: lea    r12,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2eed:
	/* 0x2eed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ef2:
	/* 0x2ef2: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2ef5:
	/* 0x2ef5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ef7:
	/* 0x2ef7: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2efa:
	/* 0x2efa: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2f01:
	/* 0x2f01: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f06:
	/* 0x2f06: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2f09:
	/* 0x2f09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f0b:
	/* 0x2f0b: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2f13:
	/* 0x2f13: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f16:
	/* 0x2f16: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f1b:
	/* 0x2f1b: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2f1e:
	/* 0x2f1e: je     3200 <generic_usdt_filter_arg_2+0x3200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12800ULL;
	}
x86_l_2f24:
	/* 0x2f24: cmp    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_2f2d:
	/* 0x2f2d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f31:
	/* 0x2f31: je     3204 <generic_usdt_filter_arg_2+0x3204> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12804ULL;
	}
x86_l_2f37:
	/* 0x2f37: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f3c:
	/* 0x2f3c: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f41:
	/* 0x2f41: mov    BYTE PTR [rax],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f44:
	/* 0x2f44: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2f48:
	/* 0x2f48: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f4d:
	/* 0x2f4d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f52:
	/* 0x2f52: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2f55:
	/* 0x2f55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f57:
	/* 0x2f57: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_2f5c:
	/* 0x2f5c: cmp    esi,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2f5f:
	/* 0x2f5f: jbe    2f89 <generic_usdt_filter_arg_2+0x2f89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2f89;
	}
x86_l_2f61:
	/* 0x2f61: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f66:
	/* 0x2f66: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f6b:
	/* 0x2f6b: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2f6f:
	/* 0x2f6f: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2f72:
	/* 0x2f72: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f74:
	/* 0x2f74: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2f7a:
	/* 0x2f7a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f7f:
	/* 0x2f7f: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2f87:
	/* 0x2f87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f89:
	/* 0x2f89: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2f8d:
	/* 0x2f8d: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2f91:
	/* 0x2f91: cmp    DWORD PTR [rsp+0x38],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168578ULL);
x86_l_2f96:
	/* 0x2f96: jg     304a <generic_usdt_filter_arg_2+0x304a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_304a;
	}
x86_l_2f9c:
	/* 0x2f9c: cmp    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2fa1:
	/* 0x2fa1: je     318c <generic_usdt_filter_arg_2+0x318c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12684ULL;
	}
x86_l_2fa7:
	/* 0x2fa7: cmp    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_2fac:
	/* 0x2fac: je     31b2 <generic_usdt_filter_arg_2+0x31b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12722ULL;
	}
x86_l_2fb2:
	/* 0x2fb2: cmp    DWORD PTR [rsp+0x38],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168578ULL);
x86_l_2fb7:
	/* 0x2fb7: jne    31fd <generic_usdt_filter_arg_2+0x31fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12797ULL;
	}
x86_l_2fbd:
	/* 0x2fbd: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2fc4:
	/* 0x2fc4: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2fc9:
	/* 0x2fc9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fce:
	/* 0x2fce: jmp    31d6 <generic_usdt_filter_arg_2+0x31d6> */
	return 12758ULL;
x86_l_2fd3:
	/* 0x2fd3: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2fd6:
	/* 0x2fd6: je     3094 <generic_usdt_filter_arg_2+0x3094> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12436ULL;
	}
x86_l_2fdc:
	/* 0x2fdc: cmp    DWORD PTR [rsp+0x8],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738372ULL);
x86_l_2fe1:
	/* 0x2fe1: je     30ba <generic_usdt_filter_arg_2+0x30ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12474ULL;
	}
x86_l_2fe7:
	/* 0x2fe7: cmp    DWORD PTR [rsp+0x8],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738373ULL);
x86_l_2fec:
	/* 0x2fec: jne    31fd <generic_usdt_filter_arg_2+0x31fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12797ULL;
	}
x86_l_2ff2:
	/* 0x2ff2: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_2ff9:
	/* 0x2ff9: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2ffe:
	/* 0x2ffe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3003:
	/* 0x3003: jmp    30cb <generic_usdt_filter_arg_2+0x30cb> */
	return 12491ULL;
x86_l_3008:
	/* 0x3008: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_300b:
	/* 0x300b: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_300e:
	/* 0x300e: jmp    3165 <generic_usdt_filter_arg_2+0x3165> */
	return 12645ULL;
x86_l_3013:
	/* 0x3013: cmp    DWORD PTR [rsp+0x8],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738371ULL);
x86_l_3018:
	/* 0x3018: je     3100 <generic_usdt_filter_arg_2+0x3100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12544ULL;
	}
x86_l_301e:
	/* 0x301e: cmp    DWORD PTR [rsp+0x8],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738372ULL);
x86_l_3023:
	/* 0x3023: je     3126 <generic_usdt_filter_arg_2+0x3126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12582ULL;
	}
x86_l_3029:
	/* 0x3029: cmp    DWORD PTR [rsp+0x8],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738373ULL);
x86_l_302e:
	/* 0x302e: jne    315e <generic_usdt_filter_arg_2+0x315e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12638ULL;
	}
x86_l_3034:
	/* 0x3034: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_303b:
	/* 0x303b: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3040:
	/* 0x3040: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3045:
	/* 0x3045: jmp    3137 <generic_usdt_filter_arg_2+0x3137> */
	return 12599ULL;
x86_l_304a:
	/* 0x304a: cmp    DWORD PTR [rsp+0x38],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168579ULL);
x86_l_304f:
	/* 0x304f: je     319f <generic_usdt_filter_arg_2+0x319f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12703ULL;
	}
x86_l_3055:
	/* 0x3055: cmp    DWORD PTR [rsp+0x38],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168580ULL);
x86_l_305a:
	/* 0x305a: je     31c5 <generic_usdt_filter_arg_2+0x31c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12741ULL;
	}
x86_l_3060:
	/* 0x3060: cmp    DWORD PTR [rsp+0x38],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168581ULL);
x86_l_3065:
	/* 0x3065: jne    31fd <generic_usdt_filter_arg_2+0x31fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12797ULL;
	}
x86_l_306b:
	/* 0x306b: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_3072:
	/* 0x3072: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3077:
	/* 0x3077: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_307c:
	/* 0x307c: jmp    31d6 <generic_usdt_filter_arg_2+0x31d6> */
	return 12758ULL;
x86_l_3081:
	/* 0x3081: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
	return 12424ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12424ULL: goto x86_l_3088;
	case 12429ULL: goto x86_l_308d;
	case 12434ULL: goto x86_l_3092;
	case 12436ULL: goto x86_l_3094;
	case 12443ULL: goto x86_l_309b;
	case 12448ULL: goto x86_l_30a0;
	case 12453ULL: goto x86_l_30a5;
	case 12455ULL: goto x86_l_30a7;
	case 12462ULL: goto x86_l_30ae;
	case 12467ULL: goto x86_l_30b3;
	case 12472ULL: goto x86_l_30b8;
	case 12474ULL: goto x86_l_30ba;
	case 12481ULL: goto x86_l_30c1;
	case 12486ULL: goto x86_l_30c6;
	case 12491ULL: goto x86_l_30cb;
	case 12496ULL: goto x86_l_30d0;
	case 12498ULL: goto x86_l_30d2;
	case 12501ULL: goto x86_l_30d5;
	case 12507ULL: goto x86_l_30db;
	case 12510ULL: goto x86_l_30de;
	case 12515ULL: goto x86_l_30e3;
	case 12520ULL: goto x86_l_30e8;
	case 12525ULL: goto x86_l_30ed;
	case 12532ULL: goto x86_l_30f4;
	case 12537ULL: goto x86_l_30f9;
	case 12542ULL: goto x86_l_30fe;
	case 12544ULL: goto x86_l_3100;
	case 12551ULL: goto x86_l_3107;
	case 12556ULL: goto x86_l_310c;
	case 12561ULL: goto x86_l_3111;
	case 12563ULL: goto x86_l_3113;
	case 12570ULL: goto x86_l_311a;
	case 12575ULL: goto x86_l_311f;
	case 12580ULL: goto x86_l_3124;
	case 12582ULL: goto x86_l_3126;
	case 12589ULL: goto x86_l_312d;
	case 12594ULL: goto x86_l_3132;
	case 12599ULL: goto x86_l_3137;
	case 12604ULL: goto x86_l_313c;
	case 12606ULL: goto x86_l_313e;
	case 12609ULL: goto x86_l_3141;
	case 12611ULL: goto x86_l_3143;
	case 12614ULL: goto x86_l_3146;
	case 12619ULL: goto x86_l_314b;
	case 12624ULL: goto x86_l_3150;
	case 12626ULL: goto x86_l_3152;
	case 12629ULL: goto x86_l_3155;
	case 12632ULL: goto x86_l_3158;
	case 12636ULL: goto x86_l_315c;
	case 12638ULL: goto x86_l_315e;
	case 12641ULL: goto x86_l_3161;
	case 12645ULL: goto x86_l_3165;
	case 12648ULL: goto x86_l_3168;
	case 12651ULL: goto x86_l_316b;
	case 12657ULL: goto x86_l_3171;
	case 12659ULL: goto x86_l_3173;
	case 12669ULL: goto x86_l_317d;
	case 12673ULL: goto x86_l_3181;
	case 12679ULL: goto x86_l_3187;
	case 12684ULL: goto x86_l_318c;
	case 12691ULL: goto x86_l_3193;
	case 12696ULL: goto x86_l_3198;
	case 12701ULL: goto x86_l_319d;
	case 12703ULL: goto x86_l_319f;
	case 12710ULL: goto x86_l_31a6;
	case 12715ULL: goto x86_l_31ab;
	case 12720ULL: goto x86_l_31b0;
	case 12722ULL: goto x86_l_31b2;
	case 12729ULL: goto x86_l_31b9;
	case 12734ULL: goto x86_l_31be;
	case 12739ULL: goto x86_l_31c3;
	case 12741ULL: goto x86_l_31c5;
	case 12748ULL: goto x86_l_31cc;
	case 12753ULL: goto x86_l_31d1;
	case 12758ULL: goto x86_l_31d6;
	case 12763ULL: goto x86_l_31db;
	case 12765ULL: goto x86_l_31dd;
	case 12768ULL: goto x86_l_31e0;
	case 12770ULL: goto x86_l_31e2;
	case 12773ULL: goto x86_l_31e5;
	case 12778ULL: goto x86_l_31ea;
	case 12783ULL: goto x86_l_31ef;
	case 12785ULL: goto x86_l_31f1;
	case 12788ULL: goto x86_l_31f4;
	case 12791ULL: goto x86_l_31f7;
	case 12795ULL: goto x86_l_31fb;
	case 12797ULL: goto x86_l_31fd;
	case 12800ULL: goto x86_l_3200;
	case 12804ULL: goto x86_l_3204;
	case 12807ULL: goto x86_l_3207;
	case 12810ULL: goto x86_l_320a;
	case 12812ULL: goto x86_l_320c;
	case 12814ULL: goto x86_l_320e;
	case 12824ULL: goto x86_l_3218;
	case 12828ULL: goto x86_l_321c;
	case 12830ULL: goto x86_l_321e;
	case 12834ULL: goto x86_l_3222;
	case 12837ULL: goto x86_l_3225;
	case 12839ULL: goto x86_l_3227;
	case 12843ULL: goto x86_l_322b;
	case 12845ULL: goto x86_l_322d;
	case 12847ULL: goto x86_l_322f;
	case 12849ULL: goto x86_l_3231;
	case 12853ULL: goto x86_l_3235;
	case 12855ULL: goto x86_l_3237;
	case 12859ULL: goto x86_l_323b;
	case 12865ULL: goto x86_l_3241;
	case 12868ULL: goto x86_l_3244;
	case 12874ULL: goto x86_l_324a;
	case 12878ULL: goto x86_l_324e;
	case 12884ULL: goto x86_l_3254;
	case 12886ULL: goto x86_l_3256;
	case 12890ULL: goto x86_l_325a;
	case 12896ULL: goto x86_l_3260;
	case 12900ULL: goto x86_l_3264;
	case 12906ULL: goto x86_l_326a;
	case 12910ULL: goto x86_l_326e;
	case 12916ULL: goto x86_l_3274;
	case 12920ULL: goto x86_l_3278;
	case 12926ULL: goto x86_l_327e;
	case 12929ULL: goto x86_l_3281;
	case 12934ULL: goto x86_l_3286;
	case 12941ULL: goto x86_l_328d;
	case 12948ULL: goto x86_l_3294;
	case 12953ULL: goto x86_l_3299;
	case 12958ULL: goto x86_l_329e;
	case 12961ULL: goto x86_l_32a1;
	case 12966ULL: goto x86_l_32a6;
	case 12968ULL: goto x86_l_32a8;
	case 12975ULL: goto x86_l_32af;
	case 12980ULL: goto x86_l_32b4;
	case 12985ULL: goto x86_l_32b9;
	case 12988ULL: goto x86_l_32bc;
	case 12993ULL: goto x86_l_32c1;
	case 12995ULL: goto x86_l_32c3;
	case 12997ULL: goto x86_l_32c5;
	case 13004ULL: goto x86_l_32cc;
	case 13005ULL: goto x86_l_32cd;
	case 13007ULL: goto x86_l_32cf;
	case 13009ULL: goto x86_l_32d1;
	case 13011ULL: goto x86_l_32d3;
	case 13013ULL: goto x86_l_32d5;
	case 13014ULL: goto x86_l_32d6;
	case 13019ULL: goto x86_l_32db;
	case 13022ULL: goto x86_l_32de;
	case 13030ULL: goto x86_l_32e6;
	case 13032ULL: goto x86_l_32e8;
	case 13038ULL: goto x86_l_32ee;
	case 13046ULL: goto x86_l_32f6;
	case 13048ULL: goto x86_l_32f8;
	case 13054ULL: goto x86_l_32fe;
	case 13062ULL: goto x86_l_3306;
	case 13064ULL: goto x86_l_3308;
	case 13070ULL: goto x86_l_330e;
	case 13078ULL: goto x86_l_3316;
	case 13080ULL: goto x86_l_3318;
	case 13086ULL: goto x86_l_331e;
	case 13094ULL: goto x86_l_3326;
	case 13096ULL: goto x86_l_3328;
	case 13102ULL: goto x86_l_332e;
	case 13110ULL: goto x86_l_3336;
	case 13112ULL: goto x86_l_3338;
	case 13119ULL: goto x86_l_333f;
	case 13126ULL: goto x86_l_3346;
	case 13131ULL: goto x86_l_334b;
	case 13136ULL: goto x86_l_3350;
	case 13139ULL: goto x86_l_3353;
	case 13144ULL: goto x86_l_3358;
	case 13146ULL: goto x86_l_335a;
	case 13150ULL: goto x86_l_335e;
	case 13155ULL: goto x86_l_3363;
	case 13157ULL: goto x86_l_3365;
	case 13162ULL: goto x86_l_336a;
	case 13167ULL: goto x86_l_336f;
	case 13174ULL: goto x86_l_3376;
	case 13179ULL: goto x86_l_337b;
	case 13184ULL: goto x86_l_3380;
	case 13186ULL: goto x86_l_3382;
	case 13189ULL: goto x86_l_3385;
	case 13195ULL: goto x86_l_338b;
	case 13202ULL: goto x86_l_3392;
	case 13207ULL: goto x86_l_3397;
	case 13212ULL: goto x86_l_339c;
	case 13214ULL: goto x86_l_339e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3088:
	/* 0x3088: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_308d:
	/* 0x308d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3092:
	/* 0x3092: jmp    30cb <generic_usdt_filter_arg_2+0x30cb> */
	goto x86_l_30cb;
x86_l_3094:
	/* 0x3094: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_309b:
	/* 0x309b: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30a0:
	/* 0x30a0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30a5:
	/* 0x30a5: jmp    30cb <generic_usdt_filter_arg_2+0x30cb> */
	goto x86_l_30cb;
x86_l_30a7:
	/* 0x30a7: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_30ae:
	/* 0x30ae: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30b3:
	/* 0x30b3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30b8:
	/* 0x30b8: jmp    30cb <generic_usdt_filter_arg_2+0x30cb> */
	goto x86_l_30cb;
x86_l_30ba:
	/* 0x30ba: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_30c1:
	/* 0x30c1: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30c6:
	/* 0x30c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30cb:
	/* 0x30cb: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30d0:
	/* 0x30d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30d2:
	/* 0x30d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30d5:
	/* 0x30d5: je     31fd <generic_usdt_filter_arg_2+0x31fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31fd;
	}
x86_l_30db:
	/* 0x30db: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_30de:
	/* 0x30de: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30e3:
	/* 0x30e3: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30e8:
	/* 0x30e8: jmp    31ef <generic_usdt_filter_arg_2+0x31ef> */
	goto x86_l_31ef;
x86_l_30ed:
	/* 0x30ed: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_30f4:
	/* 0x30f4: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30f9:
	/* 0x30f9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30fe:
	/* 0x30fe: jmp    3137 <generic_usdt_filter_arg_2+0x3137> */
	goto x86_l_3137;
x86_l_3100:
	/* 0x3100: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_3107:
	/* 0x3107: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_310c:
	/* 0x310c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3111:
	/* 0x3111: jmp    3137 <generic_usdt_filter_arg_2+0x3137> */
	goto x86_l_3137;
x86_l_3113:
	/* 0x3113: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_311a:
	/* 0x311a: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_311f:
	/* 0x311f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3124:
	/* 0x3124: jmp    3137 <generic_usdt_filter_arg_2+0x3137> */
	goto x86_l_3137;
x86_l_3126:
	/* 0x3126: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_312d:
	/* 0x312d: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3132:
	/* 0x3132: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3137:
	/* 0x3137: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_313c:
	/* 0x313c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_313e:
	/* 0x313e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3141:
	/* 0x3141: je     315e <generic_usdt_filter_arg_2+0x315e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_315e;
	}
x86_l_3143:
	/* 0x3143: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3146:
	/* 0x3146: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_314b:
	/* 0x314b: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3150:
	/* 0x3150: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3152:
	/* 0x3152: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3155:
	/* 0x3155: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3158:
	/* 0x3158: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_315c:
	/* 0x315c: jmp    3161 <generic_usdt_filter_arg_2+0x3161> */
	goto x86_l_3161;
x86_l_315e:
	/* 0x315e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3161:
	/* 0x3161: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3165:
	/* 0x3165: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3168:
	/* 0x3168: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_316b:
	/* 0x316b: ja     3222 <generic_usdt_filter_arg_2+0x3222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3222;
	}
x86_l_3171:
	/* 0x3171: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3173:
	/* 0x3173: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_317d:
	/* 0x317d: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3181:
	/* 0x3181: jb     321e <generic_usdt_filter_arg_2+0x321e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_321e;
	}
x86_l_3187:
	/* 0x3187: jmp    3222 <generic_usdt_filter_arg_2+0x3222> */
	goto x86_l_3222;
x86_l_318c:
	/* 0x318c: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_3193:
	/* 0x3193: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3198:
	/* 0x3198: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_319d:
	/* 0x319d: jmp    31d6 <generic_usdt_filter_arg_2+0x31d6> */
	goto x86_l_31d6;
x86_l_319f:
	/* 0x319f: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_31a6:
	/* 0x31a6: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_31ab:
	/* 0x31ab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31b0:
	/* 0x31b0: jmp    31d6 <generic_usdt_filter_arg_2+0x31d6> */
	goto x86_l_31d6;
x86_l_31b2:
	/* 0x31b2: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_31b9:
	/* 0x31b9: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_31be:
	/* 0x31be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31c3:
	/* 0x31c3: jmp    31d6 <generic_usdt_filter_arg_2+0x31d6> */
	goto x86_l_31d6;
x86_l_31c5:
	/* 0x31c5: mov    rdi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_31cc:
	/* 0x31cc: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_31d1:
	/* 0x31d1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31d6:
	/* 0x31d6: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_31db:
	/* 0x31db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31dd:
	/* 0x31dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31e0:
	/* 0x31e0: je     31fd <generic_usdt_filter_arg_2+0x31fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31fd;
	}
x86_l_31e2:
	/* 0x31e2: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_31e5:
	/* 0x31e5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31ea:
	/* 0x31ea: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_31ef:
	/* 0x31ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31f1:
	/* 0x31f1: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31f4:
	/* 0x31f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31f7:
	/* 0x31f7: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_31fb:
	/* 0x31fb: jmp    3200 <generic_usdt_filter_arg_2+0x3200> */
	goto x86_l_3200;
x86_l_31fd:
	/* 0x31fd: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3200:
	/* 0x3200: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3204:
	/* 0x3204: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3207:
	/* 0x3207: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_320a:
	/* 0x320a: ja     3222 <generic_usdt_filter_arg_2+0x3222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3222;
	}
x86_l_320c:
	/* 0x320c: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_320e:
	/* 0x320e: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_3218:
	/* 0x3218: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_321c:
	/* 0x321c: jae    3222 <generic_usdt_filter_arg_2+0x3222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3222;
	}
x86_l_321e:
	/* 0x321e: xor    r12,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_3222:
	/* 0x3222: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_3225:
	/* 0x3225: je     3231 <generic_usdt_filter_arg_2+0x3231> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3231;
	}
x86_l_3227:
	/* 0x3227: cmp    rbp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 1ULL);
x86_l_322b:
	/* 0x322b: je     32a8 <generic_usdt_filter_arg_2+0x32a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32a8;
	}
x86_l_322d:
	/* 0x322d: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_322f:
	/* 0x322f: jne    3286 <generic_usdt_filter_arg_2+0x3286> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3286;
	}
x86_l_3231:
	/* 0x3231: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_3235:
	/* 0x3235: jg     3256 <generic_usdt_filter_arg_2+0x3256> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3256;
	}
x86_l_3237:
	/* 0x3237: cmp    r15d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4294967295ULL);
x86_l_323b:
	/* 0x323b: je     32db <generic_usdt_filter_arg_2+0x32db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32db;
	}
x86_l_3241:
	/* 0x3241: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_3244:
	/* 0x3244: je     32e8 <generic_usdt_filter_arg_2+0x32e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32e8;
	}
x86_l_324a:
	/* 0x324a: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_324e:
	/* 0x324e: je     32f8 <generic_usdt_filter_arg_2+0x32f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32f8;
	}
x86_l_3254:
	/* 0x3254: jmp    3274 <generic_usdt_filter_arg_2+0x3274> */
	goto x86_l_3274;
x86_l_3256:
	/* 0x3256: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_325a:
	/* 0x325a: je     3308 <generic_usdt_filter_arg_2+0x3308> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3308;
	}
x86_l_3260:
	/* 0x3260: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_3264:
	/* 0x3264: je     3318 <generic_usdt_filter_arg_2+0x3318> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3318;
	}
x86_l_326a:
	/* 0x326a: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_326e:
	/* 0x326e: je     3328 <generic_usdt_filter_arg_2+0x3328> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3328;
	}
x86_l_3274:
	/* 0x3274: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_3278:
	/* 0x3278: jg     335a <generic_usdt_filter_arg_2+0x335a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_335a;
	}
x86_l_327e:
	/* 0x327e: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3281:
	/* 0x3281: jmp    3338 <generic_usdt_filter_arg_2+0x3338> */
	goto x86_l_3338;
x86_l_3286:
	/* 0x3286: mov    DWORD PTR [r14+0x5ef4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_328d:
	/* 0x328d: mov    rsi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_3294:
	/* 0x3294: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3299:
	/* 0x3299: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_329e:
	/* 0x329e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_32a1:
	/* 0x32a1: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_32a6:
	/* 0x32a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32a8:
	/* 0x32a8: mov    rsi,QWORD PTR [rip+0xbe6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_32af:
	/* 0x32af: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_32b4:
	/* 0x32b4: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_32b9:
	/* 0x32b9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_32bc:
	/* 0x32bc: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_32c1:
	/* 0x32c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32c3:
	/* 0x32c3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32c5:
	/* 0x32c5: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_32cc:
	/* 0x32cc: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_32cd:
	/* 0x32cd: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_32cf:
	/* 0x32cf: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_32d1:
	/* 0x32d1: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_32d3:
	/* 0x32d3: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_32d5:
	/* 0x32d5: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_32d6:
	/* 0x32d6: jmp    33a3 <generic_usdt_filter_arg_2+0x33a3> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_32db:
	/* 0x32db: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32de:
	/* 0x32de: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_32e6:
	/* 0x32e6: jne    3338 <generic_usdt_filter_arg_2+0x3338> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3338;
	}
x86_l_32e8:
	/* 0x32e8: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_32ee:
	/* 0x32ee: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_32f6:
	/* 0x32f6: jne    3338 <generic_usdt_filter_arg_2+0x3338> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3338;
	}
x86_l_32f8:
	/* 0x32f8: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_32fe:
	/* 0x32fe: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_3306:
	/* 0x3306: jne    3338 <generic_usdt_filter_arg_2+0x3338> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3338;
	}
x86_l_3308:
	/* 0x3308: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_330e:
	/* 0x330e: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_3316:
	/* 0x3316: jne    3338 <generic_usdt_filter_arg_2+0x3338> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3338;
	}
x86_l_3318:
	/* 0x3318: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_331e:
	/* 0x331e: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_3326:
	/* 0x3326: jne    3338 <generic_usdt_filter_arg_2+0x3338> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3338;
	}
x86_l_3328:
	/* 0x3328: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_332e:
	/* 0x332e: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_3336:
	/* 0x3336: je     335a <generic_usdt_filter_arg_2+0x335a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_335a;
	}
x86_l_3338:
	/* 0x3338: mov    DWORD PTR [r14+0x5ef0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_333f:
	/* 0x333f: mov    rsi,QWORD PTR [rip+0xbe68] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_3346:
	/* 0x3346: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_334b:
	/* 0x334b: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3350:
	/* 0x3350: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3353:
	/* 0x3353: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3358:
	/* 0x3358: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_335a:
	/* 0x335a: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_335e:
	/* 0x335e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3363:
	/* 0x3363: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3365:
	/* 0x3365: mov    QWORD PTR [rsp+0x50],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_336a:
	/* 0x336a: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_336f:
	/* 0x336f: mov    rdi,QWORD PTR [rip+0xbe68] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_3376:
	/* 0x3376: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_337b:
	/* 0x337b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3380:
	/* 0x3380: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3382:
	/* 0x3382: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3385:
	/* 0x3385: je     32c3 <generic_usdt_filter_arg_2+0x32c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32c3;
	}
x86_l_338b:
	/* 0x338b: mov    rdi,QWORD PTR [rip+0xbe68] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_3392:
	/* 0x3392: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3397:
	/* 0x3397: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_339c:
	/* 0x339c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_339e:
	/* 0x339e: jmp    32c3 <generic_usdt_filter_arg_2+0x32c3> */
	goto x86_l_32c3;
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
	for (__u32 __x86_iter = 0; __x86_iter < 11488U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1773ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1778ULL && __x86_pc <= 3588ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3591ULL && __x86_pc <= 5442ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5445ULL && __x86_pc <= 7270ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7273ULL && __x86_pc <= 9115ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9119ULL && __x86_pc <= 10822ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10827ULL && __x86_pc <= 12417ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12424ULL && __x86_pc <= 13214ULL)
			__x86_pc = tetragon_bpf_generic_usdt_generic_usdt_filter_arg_2_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

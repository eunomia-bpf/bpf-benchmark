extern char addr4lpm_maps;
extern char addr6lpm_maps;
extern char argfilter_maps;
extern char filter_map;
extern char heap_ro_zero;
extern char process_call_heap;
extern char retkprobe_calls;
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

static __noinline __u64 tetragon_bpf_generic_retkprobe_generic_retkprobe_filter_arg_2_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 21ULL: goto x86_l_15;
	case 28ULL: goto x86_l_1c;
	case 33ULL: goto x86_l_21;
	case 38ULL: goto x86_l_26;
	case 40ULL: goto x86_l_28;
	case 43ULL: goto x86_l_2b;
	case 49ULL: goto x86_l_31;
	case 52ULL: goto x86_l_34;
	case 59ULL: goto x86_l_3b;
	case 66ULL: goto x86_l_42;
	case 73ULL: goto x86_l_49;
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
	case 140ULL: goto x86_l_8c;
	case 146ULL: goto x86_l_92;
	case 150ULL: goto x86_l_96;
	case 156ULL: goto x86_l_9c;
	case 160ULL: goto x86_l_a0;
	case 166ULL: goto x86_l_a6;
	case 172ULL: goto x86_l_ac;
	case 174ULL: goto x86_l_ae;
	case 180ULL: goto x86_l_b4;
	case 183ULL: goto x86_l_b7;
	case 187ULL: goto x86_l_bb;
	case 193ULL: goto x86_l_c1;
	case 202ULL: goto x86_l_ca;
	case 208ULL: goto x86_l_d0;
	case 211ULL: goto x86_l_d3;
	case 214ULL: goto x86_l_d6;
	case 218ULL: goto x86_l_da;
	case 226ULL: goto x86_l_e2;
	case 231ULL: goto x86_l_e7;
	case 235ULL: goto x86_l_eb;
	case 242ULL: goto x86_l_f2;
	case 245ULL: goto x86_l_f5;
	case 247ULL: goto x86_l_f7;
	case 250ULL: goto x86_l_fa;
	case 256ULL: goto x86_l_100;
	case 259ULL: goto x86_l_103;
	case 265ULL: goto x86_l_109;
	case 268ULL: goto x86_l_10c;
	case 274ULL: goto x86_l_112;
	case 277ULL: goto x86_l_115;
	case 279ULL: goto x86_l_117;
	case 284ULL: goto x86_l_11c;
	case 287ULL: goto x86_l_11f;
	case 293ULL: goto x86_l_125;
	case 296ULL: goto x86_l_128;
	case 299ULL: goto x86_l_12b;
	case 305ULL: goto x86_l_131;
	case 308ULL: goto x86_l_134;
	case 311ULL: goto x86_l_137;
	case 314ULL: goto x86_l_13a;
	case 320ULL: goto x86_l_140;
	case 323ULL: goto x86_l_143;
	case 327ULL: goto x86_l_147;
	case 332ULL: goto x86_l_14c;
	case 335ULL: goto x86_l_14f;
	case 341ULL: goto x86_l_155;
	case 346ULL: goto x86_l_15a;
	case 349ULL: goto x86_l_15d;
	case 355ULL: goto x86_l_163;
	case 360ULL: goto x86_l_168;
	case 363ULL: goto x86_l_16b;
	case 369ULL: goto x86_l_171;
	case 374ULL: goto x86_l_176;
	case 378ULL: goto x86_l_17a;
	case 381ULL: goto x86_l_17d;
	case 385ULL: goto x86_l_181;
	case 393ULL: goto x86_l_189;
	case 400ULL: goto x86_l_190;
	case 405ULL: goto x86_l_195;
	case 410ULL: goto x86_l_19a;
	case 412ULL: goto x86_l_19c;
	case 415ULL: goto x86_l_19f;
	case 418ULL: goto x86_l_1a2;
	case 421ULL: goto x86_l_1a5;
	case 427ULL: goto x86_l_1ab;
	case 430ULL: goto x86_l_1ae;
	case 436ULL: goto x86_l_1b4;
	case 439ULL: goto x86_l_1b7;
	case 446ULL: goto x86_l_1be;
	case 451ULL: goto x86_l_1c3;
	case 456ULL: goto x86_l_1c8;
	case 458ULL: goto x86_l_1ca;
	case 461ULL: goto x86_l_1cd;
	case 467ULL: goto x86_l_1d3;
	case 470ULL: goto x86_l_1d6;
	case 474ULL: goto x86_l_1da;
	case 479ULL: goto x86_l_1df;
	case 483ULL: goto x86_l_1e3;
	case 486ULL: goto x86_l_1e6;
	case 488ULL: goto x86_l_1e8;
	case 492ULL: goto x86_l_1ec;
	case 497ULL: goto x86_l_1f1;
	case 502ULL: goto x86_l_1f6;
	case 506ULL: goto x86_l_1fa;
	case 509ULL: goto x86_l_1fd;
	case 513ULL: goto x86_l_201;
	case 519ULL: goto x86_l_207;
	case 526ULL: goto x86_l_20e;
	case 531ULL: goto x86_l_213;
	case 535ULL: goto x86_l_217;
	case 538ULL: goto x86_l_21a;
	case 542ULL: goto x86_l_21e;
	case 548ULL: goto x86_l_224;
	case 555ULL: goto x86_l_22b;
	case 560ULL: goto x86_l_230;
	case 564ULL: goto x86_l_234;
	case 567ULL: goto x86_l_237;
	case 571ULL: goto x86_l_23b;
	case 577ULL: goto x86_l_241;
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
	case 1778ULL: goto x86_l_6f2;
	case 1782ULL: goto x86_l_6f6;
	case 1785ULL: goto x86_l_6f9;
	case 1789ULL: goto x86_l_6fd;
	case 1795ULL: goto x86_l_703;
	case 1802ULL: goto x86_l_70a;
	case 1807ULL: goto x86_l_70f;
	case 1811ULL: goto x86_l_713;
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
	/* 0x15: mov    rdi,QWORD PTR [rip+0x17e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1c:
	/* 0x1c: lea    rsi,[rsp+0x7c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_21:
	/* 0x21: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26:
	/* 0x26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28:
	/* 0x28: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b:
	/* 0x2b: je     326c <generic_retkprobe_filter_arg_2+0x326c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12908ULL;
	}
x86_l_31:
	/* 0x31: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_34:
	/* 0x34: mov    r15d,DWORD PTR [rax+0x5ef0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_3b:
	/* 0x3b: lea    rsi,[rax+0x5ee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24296ULL);
x86_l_42:
	/* 0x42: mov    rdi,QWORD PTR [rip+0x17e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_49:
	/* 0x49: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e:
	/* 0x4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50:
	/* 0x50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_53:
	/* 0x53: je     3251 <generic_retkprobe_filter_arg_2+0x3251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12881ULL;
	}
x86_l_59:
	/* 0x59: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_61:
	/* 0x61: je     3251 <generic_retkprobe_filter_arg_2+0x3251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12881ULL;
	}
x86_l_67:
	/* 0x67: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_6a:
	/* 0x6a: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_6d:
	/* 0x6d: cmp    BYTE PTR [r14+rcx*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 104183021699072ULL);
x86_l_76:
	/* 0x76: je     31da <generic_retkprobe_filter_arg_2+0x31da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12762ULL;
	}
x86_l_7c:
	/* 0x7c: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_7e:
	/* 0x7e: mov    edx,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_82:
	/* 0x82: lea    rcx,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_86:
	/* 0x86: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_8a:
	/* 0x8a: mov    ebp,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_32);
x86_l_8c:
	/* 0x8c: and    ebp,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_92:
	/* 0x92: cmp    DWORD PTR [rax+rbp*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 25ULL);
x86_l_96:
	/* 0x96: jb     31d0 <generic_retkprobe_filter_arg_2+0x31d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12752ULL;
	}
x86_l_9c:
	/* 0x9c: mov    edx,DWORD PTR [rax+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 4ULL);
x86_l_a0:
	/* 0xa0: test   edx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 1023ULL);
x86_l_a6:
	/* 0xa6: je     31d0 <generic_retkprobe_filter_arg_2+0x31d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12752ULL;
	}
x86_l_ac:
	/* 0xac: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ae:
	/* 0xae: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_b4:
	/* 0xb4: mov    edx,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_b7:
	/* 0xb7: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_bb:
	/* 0xbb: ja     31da <generic_retkprobe_filter_arg_2+0x31da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12762ULL;
	}
x86_l_c1:
	/* 0xc1: cmp    DWORD PTR [r14+rdx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104041287778304ULL);
x86_l_ca:
	/* 0xca: jne    31da <generic_retkprobe_filter_arg_2+0x31da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12762ULL;
	}
x86_l_d0:
	/* 0xd0: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d3:
	/* 0xd3: add    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d6:
	/* 0xd6: mov    ecx,DWORD PTR [rax+rcx*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 12ULL);
x86_l_da:
	/* 0xda: mov    rax,QWORD PTR [r14+rdx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_e2:
	/* 0xe2: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_e7:
	/* 0xe7: lea    r8,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_eb:
	/* 0xeb: add    r8,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_f2:
	/* 0xf2: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_f5:
	/* 0xf5: jg     11c <generic_retkprobe_filter_arg_2+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_11c;
	}
x86_l_f7:
	/* 0xf7: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_fa:
	/* 0xfa: jg     c82 <generic_retkprobe_filter_arg_2+0xc82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3202ULL;
	}
x86_l_100:
	/* 0x100: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_103:
	/* 0x103: je     e41 <generic_retkprobe_filter_arg_2+0xe41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3649ULL;
	}
x86_l_109:
	/* 0x109: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_10c:
	/* 0x10c: je     ca0 <generic_retkprobe_filter_arg_2+0xca0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3232ULL;
	}
x86_l_112:
	/* 0x112: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_115:
	/* 0x115: je     131 <generic_retkprobe_filter_arg_2+0x131> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_131;
	}
x86_l_117:
	/* 0x117: jmp    31d0 <generic_retkprobe_filter_arg_2+0x31d0> */
	return 12752ULL;
x86_l_11c:
	/* 0x11c: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_11f:
	/* 0x11f: jg     c98 <generic_retkprobe_filter_arg_2+0xc98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3224ULL;
	}
x86_l_125:
	/* 0x125: lea    eax,[rcx-0x26] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_128:
	/* 0x128: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12b:
	/* 0x12b: jae    d09 <generic_retkprobe_filter_arg_2+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3337ULL;
	}
x86_l_131:
	/* 0x131: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_134:
	/* 0x134: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_137:
	/* 0x137: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_13a:
	/* 0x13a: ja     31b0 <generic_retkprobe_filter_arg_2+0x31b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12720ULL;
	}
x86_l_140:
	/* 0x140: mov    r13d,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_143:
	/* 0x143: add    r8,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_147:
	/* 0x147: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_14c:
	/* 0x14c: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_14f:
	/* 0x14f: jb     1a9d <generic_retkprobe_filter_arg_2+0x1a9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6813ULL;
	}
x86_l_155:
	/* 0x155: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_15a:
	/* 0x15a: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_15d:
	/* 0x15d: jb     19f8 <generic_retkprobe_filter_arg_2+0x19f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6648ULL;
	}
x86_l_163:
	/* 0x163: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_168:
	/* 0x168: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_16b:
	/* 0x16b: jae    31b0 <generic_retkprobe_filter_arg_2+0x31b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12720ULL;
	}
x86_l_171:
	/* 0x171: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_176:
	/* 0x176: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17a:
	/* 0x17a: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17d:
	/* 0x17d: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_181:
	/* 0x181: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_189:
	/* 0x189: mov    rdi,QWORD PTR [rip+0x17e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_190:
	/* 0x190: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_195:
	/* 0x195: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19a:
	/* 0x19a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19c:
	/* 0x19c: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_19f:
	/* 0x19f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a2:
	/* 0x1a2: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1a5:
	/* 0x1a5: je     31a9 <generic_retkprobe_filter_arg_2+0x31a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12713ULL;
	}
x86_l_1ab:
	/* 0x1ab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ae:
	/* 0x1ae: je     31a9 <generic_retkprobe_filter_arg_2+0x31a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12713ULL;
	}
x86_l_1b4:
	/* 0x1b4: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1b7:
	/* 0x1b7: mov    rdi,QWORD PTR [rip+0x17e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_1be:
	/* 0x1be: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c3:
	/* 0x1c3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c8:
	/* 0x1c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca:
	/* 0x1ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cd:
	/* 0x1cd: je     31a6 <generic_retkprobe_filter_arg_2+0x31a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12710ULL;
	}
x86_l_1d3:
	/* 0x1d3: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1d6:
	/* 0x1d6: cmp    r13d,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 94ULL);
x86_l_1da:
	/* 0x1da: mov    eax,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 94ULL);
x86_l_1df:
	/* 0x1df: cmovb  eax,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_1e3:
	/* 0x1e3: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1e6:
	/* 0x1e6: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e8:
	/* 0x1e8: lea    eax,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1ec:
	/* 0x1ec: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f1:
	/* 0x1f1: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f6:
	/* 0x1f6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1fa:
	/* 0x1fa: mov    BYTE PTR [rsi+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1fd:
	/* 0x1fd: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_201:
	/* 0x201: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_207:
	/* 0x207: lea    eax,[r13+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_20e:
	/* 0x20e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_213:
	/* 0x213: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_217:
	/* 0x217: mov    BYTE PTR [rsi+0x5],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_21a:
	/* 0x21a: cmp    r13,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 2ULL);
x86_l_21e:
	/* 0x21e: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_224:
	/* 0x224: lea    eax,[r13+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_22b:
	/* 0x22b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_230:
	/* 0x230: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_234:
	/* 0x234: mov    BYTE PTR [rsi+0x6],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_237:
	/* 0x237: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_23b:
	/* 0x23b: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_241:
	/* 0x241: lea    eax,[r13+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_248:
	/* 0x248: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24d:
	/* 0x24d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_251:
	/* 0x251: mov    BYTE PTR [rsi+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_254:
	/* 0x254: cmp    r13,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4ULL);
x86_l_258:
	/* 0x258: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_25e:
	/* 0x25e: lea    eax,[r13+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_265:
	/* 0x265: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26a:
	/* 0x26a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_26e:
	/* 0x26e: mov    BYTE PTR [rsi+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_271:
	/* 0x271: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_275:
	/* 0x275: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_27b:
	/* 0x27b: lea    eax,[r13+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_282:
	/* 0x282: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_287:
	/* 0x287: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_28b:
	/* 0x28b: mov    BYTE PTR [rsi+0x9],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_28e:
	/* 0x28e: cmp    r13,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 6ULL);
x86_l_292:
	/* 0x292: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_298:
	/* 0x298: lea    eax,[r13+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_29f:
	/* 0x29f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a4:
	/* 0x2a4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2a8:
	/* 0x2a8: mov    BYTE PTR [rsi+0xa],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_2ab:
	/* 0x2ab: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_2af:
	/* 0x2af: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_2b5:
	/* 0x2b5: lea    eax,[r13+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_2bc:
	/* 0x2bc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c1:
	/* 0x2c1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2c5:
	/* 0x2c5: mov    BYTE PTR [rsi+0xb],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_2c8:
	/* 0x2c8: cmp    r13,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 8ULL);
x86_l_2cc:
	/* 0x2cc: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_2d2:
	/* 0x2d2: lea    eax,[r13+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_2d9:
	/* 0x2d9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2de:
	/* 0x2de: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2e2:
	/* 0x2e2: mov    BYTE PTR [rsi+0xc],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2e5:
	/* 0x2e5: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_2e9:
	/* 0x2e9: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_2ef:
	/* 0x2ef: lea    eax,[r13+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_2f6:
	/* 0x2f6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2fb:
	/* 0x2fb: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2ff:
	/* 0x2ff: mov    BYTE PTR [rsi+0xd],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_302:
	/* 0x302: cmp    r13,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 10ULL);
x86_l_306:
	/* 0x306: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_30c:
	/* 0x30c: lea    eax,[r13+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_313:
	/* 0x313: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_318:
	/* 0x318: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_31c:
	/* 0x31c: mov    BYTE PTR [rsi+0xe],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_31f:
	/* 0x31f: cmp    r13,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 11ULL);
x86_l_323:
	/* 0x323: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_329:
	/* 0x329: lea    eax,[r13+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_330:
	/* 0x330: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_335:
	/* 0x335: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_339:
	/* 0x339: mov    BYTE PTR [rsi+0xf],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_33c:
	/* 0x33c: cmp    r13,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 12ULL);
x86_l_340:
	/* 0x340: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_346:
	/* 0x346: lea    eax,[r13+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_34d:
	/* 0x34d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_352:
	/* 0x352: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_356:
	/* 0x356: mov    BYTE PTR [rsi+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_359:
	/* 0x359: cmp    r13,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 13ULL);
x86_l_35d:
	/* 0x35d: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_363:
	/* 0x363: lea    eax,[r13+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_36a:
	/* 0x36a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_36f:
	/* 0x36f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_373:
	/* 0x373: mov    BYTE PTR [rsi+0x11],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_376:
	/* 0x376: cmp    r13,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 14ULL);
x86_l_37a:
	/* 0x37a: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_380:
	/* 0x380: lea    eax,[r13+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_387:
	/* 0x387: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_38c:
	/* 0x38c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_390:
	/* 0x390: mov    BYTE PTR [rsi+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_393:
	/* 0x393: cmp    r13,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 15ULL);
x86_l_397:
	/* 0x397: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_39d:
	/* 0x39d: lea    eax,[r13+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_3a4:
	/* 0x3a4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3a9:
	/* 0x3a9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3ad:
	/* 0x3ad: mov    BYTE PTR [rsi+0x13],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_3b0:
	/* 0x3b0: cmp    r13,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 16ULL);
x86_l_3b4:
	/* 0x3b4: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_3ba:
	/* 0x3ba: lea    eax,[r13+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_3c1:
	/* 0x3c1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3c6:
	/* 0x3c6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3ca:
	/* 0x3ca: mov    BYTE PTR [rsi+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3cd:
	/* 0x3cd: cmp    r13,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 17ULL);
x86_l_3d1:
	/* 0x3d1: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_3d7:
	/* 0x3d7: lea    eax,[r13+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_3de:
	/* 0x3de: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3e3:
	/* 0x3e3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3e7:
	/* 0x3e7: mov    BYTE PTR [rsi+0x15],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_3ea:
	/* 0x3ea: cmp    r13,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18ULL);
x86_l_3ee:
	/* 0x3ee: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_3f4:
	/* 0x3f4: lea    eax,[r13+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_3fb:
	/* 0x3fb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_400:
	/* 0x400: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_404:
	/* 0x404: mov    BYTE PTR [rsi+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_407:
	/* 0x407: cmp    r13,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 19ULL);
x86_l_40b:
	/* 0x40b: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_411:
	/* 0x411: lea    eax,[r13+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_418:
	/* 0x418: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_41d:
	/* 0x41d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_421:
	/* 0x421: mov    BYTE PTR [rsi+0x17],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_424:
	/* 0x424: cmp    r13,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 20ULL);
x86_l_428:
	/* 0x428: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_42e:
	/* 0x42e: lea    eax,[r13+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_435:
	/* 0x435: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_43a:
	/* 0x43a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_43e:
	/* 0x43e: mov    BYTE PTR [rsi+0x18],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_441:
	/* 0x441: cmp    r13,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 21ULL);
x86_l_445:
	/* 0x445: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_44b:
	/* 0x44b: lea    eax,[r13+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_452:
	/* 0x452: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_457:
	/* 0x457: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_45b:
	/* 0x45b: mov    BYTE PTR [rsi+0x19],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_45e:
	/* 0x45e: cmp    r13,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 22ULL);
x86_l_462:
	/* 0x462: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_468:
	/* 0x468: lea    eax,[r13+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_46f:
	/* 0x46f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_474:
	/* 0x474: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_478:
	/* 0x478: mov    BYTE PTR [rsi+0x1a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_47b:
	/* 0x47b: cmp    r13,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 23ULL);
x86_l_47f:
	/* 0x47f: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_485:
	/* 0x485: lea    eax,[r13+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_48c:
	/* 0x48c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_491:
	/* 0x491: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_495:
	/* 0x495: mov    BYTE PTR [rsi+0x1b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_498:
	/* 0x498: cmp    r13,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 24ULL);
x86_l_49c:
	/* 0x49c: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_4a2:
	/* 0x4a2: lea    eax,[r13+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_4a9:
	/* 0x4a9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4ae:
	/* 0x4ae: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4b2:
	/* 0x4b2: mov    BYTE PTR [rsi+0x1c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4b5:
	/* 0x4b5: cmp    r13,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 25ULL);
x86_l_4b9:
	/* 0x4b9: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_4bf:
	/* 0x4bf: lea    eax,[r13+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_4c6:
	/* 0x4c6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4cb:
	/* 0x4cb: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4cf:
	/* 0x4cf: mov    BYTE PTR [rsi+0x1d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_4d2:
	/* 0x4d2: cmp    r13,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 26ULL);
x86_l_4d6:
	/* 0x4d6: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_4dc:
	/* 0x4dc: lea    eax,[r13+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_4e3:
	/* 0x4e3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4e8:
	/* 0x4e8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4ec:
	/* 0x4ec: mov    BYTE PTR [rsi+0x1e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_4ef:
	/* 0x4ef: cmp    r13,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 27ULL);
x86_l_4f3:
	/* 0x4f3: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_4f9:
	/* 0x4f9: lea    eax,[r13+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_500:
	/* 0x500: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_505:
	/* 0x505: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_509:
	/* 0x509: mov    BYTE PTR [rsi+0x1f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_50c:
	/* 0x50c: cmp    r13,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 28ULL);
x86_l_510:
	/* 0x510: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_516:
	/* 0x516: lea    eax,[r13+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_51d:
	/* 0x51d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_522:
	/* 0x522: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_526:
	/* 0x526: mov    BYTE PTR [rsi+0x20],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_529:
	/* 0x529: cmp    r13,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 29ULL);
x86_l_52d:
	/* 0x52d: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_533:
	/* 0x533: lea    eax,[r13+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_53a:
	/* 0x53a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_53f:
	/* 0x53f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_543:
	/* 0x543: mov    BYTE PTR [rsi+0x21],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_546:
	/* 0x546: cmp    r13,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 30ULL);
x86_l_54a:
	/* 0x54a: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_550:
	/* 0x550: lea    eax,[r13+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_557:
	/* 0x557: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_55c:
	/* 0x55c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_560:
	/* 0x560: mov    BYTE PTR [rsi+0x22],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_563:
	/* 0x563: cmp    r13,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 31ULL);
x86_l_567:
	/* 0x567: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_56d:
	/* 0x56d: lea    eax,[r13+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_574:
	/* 0x574: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_579:
	/* 0x579: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_57d:
	/* 0x57d: mov    BYTE PTR [rsi+0x23],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_580:
	/* 0x580: cmp    r13,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 32ULL);
x86_l_584:
	/* 0x584: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_58a:
	/* 0x58a: lea    eax,[r13+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_591:
	/* 0x591: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_596:
	/* 0x596: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_59a:
	/* 0x59a: mov    BYTE PTR [rsi+0x24],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_59d:
	/* 0x59d: cmp    r13,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 33ULL);
x86_l_5a1:
	/* 0x5a1: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_5a7:
	/* 0x5a7: lea    eax,[r13+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_5ae:
	/* 0x5ae: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5b3:
	/* 0x5b3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_5b7:
	/* 0x5b7: mov    BYTE PTR [rsi+0x25],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_5ba:
	/* 0x5ba: cmp    r13,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 34ULL);
x86_l_5be:
	/* 0x5be: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_5c4:
	/* 0x5c4: lea    eax,[r13+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_5cb:
	/* 0x5cb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5d0:
	/* 0x5d0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_5d4:
	/* 0x5d4: mov    BYTE PTR [rsi+0x26],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_5d7:
	/* 0x5d7: cmp    r13,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 35ULL);
x86_l_5db:
	/* 0x5db: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_5e1:
	/* 0x5e1: lea    eax,[r13+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_5e8:
	/* 0x5e8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5ed:
	/* 0x5ed: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_5f1:
	/* 0x5f1: mov    BYTE PTR [rsi+0x27],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_5f4:
	/* 0x5f4: cmp    r13,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 36ULL);
x86_l_5f8:
	/* 0x5f8: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_5fe:
	/* 0x5fe: lea    eax,[r13+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_605:
	/* 0x605: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_60a:
	/* 0x60a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_60e:
	/* 0x60e: mov    BYTE PTR [rsi+0x28],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_611:
	/* 0x611: cmp    r13,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 37ULL);
x86_l_615:
	/* 0x615: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_61b:
	/* 0x61b: lea    eax,[r13+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_622:
	/* 0x622: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_627:
	/* 0x627: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_62b:
	/* 0x62b: mov    BYTE PTR [rsi+0x29],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_62e:
	/* 0x62e: cmp    r13,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 38ULL);
x86_l_632:
	/* 0x632: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_638:
	/* 0x638: lea    eax,[r13+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_63f:
	/* 0x63f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_644:
	/* 0x644: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_648:
	/* 0x648: mov    BYTE PTR [rsi+0x2a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_64b:
	/* 0x64b: cmp    r13,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 39ULL);
x86_l_64f:
	/* 0x64f: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_655:
	/* 0x655: lea    eax,[r13+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_65c:
	/* 0x65c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_661:
	/* 0x661: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_665:
	/* 0x665: mov    BYTE PTR [rsi+0x2b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_668:
	/* 0x668: cmp    r13,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 40ULL);
x86_l_66c:
	/* 0x66c: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_672:
	/* 0x672: lea    eax,[r13+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_679:
	/* 0x679: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_67e:
	/* 0x67e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_682:
	/* 0x682: mov    BYTE PTR [rsi+0x2c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_685:
	/* 0x685: cmp    r13,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 41ULL);
x86_l_689:
	/* 0x689: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_68f:
	/* 0x68f: lea    eax,[r13+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_696:
	/* 0x696: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_69b:
	/* 0x69b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_69f:
	/* 0x69f: mov    BYTE PTR [rsi+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_6a2:
	/* 0x6a2: cmp    r13,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 42ULL);
x86_l_6a6:
	/* 0x6a6: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_6ac:
	/* 0x6ac: lea    eax,[r13+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_6b3:
	/* 0x6b3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6b8:
	/* 0x6b8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_6bc:
	/* 0x6bc: mov    BYTE PTR [rsi+0x2e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_6bf:
	/* 0x6bf: cmp    r13,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 43ULL);
x86_l_6c3:
	/* 0x6c3: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_6c9:
	/* 0x6c9: lea    eax,[r13+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_6d0:
	/* 0x6d0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6d5:
	/* 0x6d5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_6d9:
	/* 0x6d9: mov    BYTE PTR [rsi+0x2f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_6dc:
	/* 0x6dc: cmp    r13,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 44ULL);
x86_l_6e0:
	/* 0x6e0: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_6e6:
	/* 0x6e6: lea    eax,[r13+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_6ed:
	/* 0x6ed: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6f2:
	/* 0x6f2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_6f6:
	/* 0x6f6: mov    BYTE PTR [rsi+0x30],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6f9:
	/* 0x6f9: cmp    r13,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 45ULL);
x86_l_6fd:
	/* 0x6fd: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3189ULL;
	}
x86_l_703:
	/* 0x703: lea    eax,[r13+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_70a:
	/* 0x70a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_70f:
	/* 0x70f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_713:
	/* 0x713: mov    BYTE PTR [rsi+0x31],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
	return 1814ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_generic_retkprobe_filter_arg_2_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
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
	case 3067ULL: goto x86_l_bfb;
	case 3074ULL: goto x86_l_c02;
	case 3079ULL: goto x86_l_c07;
	case 3083ULL: goto x86_l_c0b;
	case 3086ULL: goto x86_l_c0e;
	case 3090ULL: goto x86_l_c12;
	case 3092ULL: goto x86_l_c14;
	case 3099ULL: goto x86_l_c1b;
	case 3104ULL: goto x86_l_c20;
	case 3108ULL: goto x86_l_c24;
	case 3111ULL: goto x86_l_c27;
	case 3115ULL: goto x86_l_c2b;
	case 3117ULL: goto x86_l_c2d;
	case 3124ULL: goto x86_l_c34;
	case 3129ULL: goto x86_l_c39;
	case 3133ULL: goto x86_l_c3d;
	case 3136ULL: goto x86_l_c40;
	case 3140ULL: goto x86_l_c44;
	case 3142ULL: goto x86_l_c46;
	case 3149ULL: goto x86_l_c4d;
	case 3154ULL: goto x86_l_c52;
	case 3158ULL: goto x86_l_c56;
	case 3161ULL: goto x86_l_c59;
	case 3165ULL: goto x86_l_c5d;
	case 3167ULL: goto x86_l_c5f;
	case 3174ULL: goto x86_l_c66;
	case 3181ULL: goto x86_l_c6d;
	case 3186ULL: goto x86_l_c72;
	case 3189ULL: goto x86_l_c75;
	case 3194ULL: goto x86_l_c7a;
	case 3197ULL: goto x86_l_c7d;
	case 3202ULL: goto x86_l_c82;
	case 3205ULL: goto x86_l_c85;
	case 3208ULL: goto x86_l_c88;
	case 3214ULL: goto x86_l_c8e;
	case 3217ULL: goto x86_l_c91;
	case 3219ULL: goto x86_l_c93;
	case 3224ULL: goto x86_l_c98;
	case 3227ULL: goto x86_l_c9b;
	case 3230ULL: goto x86_l_c9e;
	case 3232ULL: goto x86_l_ca0;
	case 3241ULL: goto x86_l_ca9;
	case 3250ULL: goto x86_l_cb2;
	case 3259ULL: goto x86_l_cbb;
	case 3268ULL: goto x86_l_cc4;
	case 3277ULL: goto x86_l_ccd;
	case 3280ULL: goto x86_l_cd0;
	case 3283ULL: goto x86_l_cd3;
	case 3285ULL: goto x86_l_cd5;
	case 3288ULL: goto x86_l_cd8;
	case 3294ULL: goto x86_l_cde;
	case 3297ULL: goto x86_l_ce1;
	case 3300ULL: goto x86_l_ce4;
	case 3306ULL: goto x86_l_cea;
	case 3311ULL: goto x86_l_cef;
	case 3314ULL: goto x86_l_cf2;
	case 3320ULL: goto x86_l_cf8;
	case 3323ULL: goto x86_l_cfb;
	case 3326ULL: goto x86_l_cfe;
	case 3332ULL: goto x86_l_d04;
	case 3337ULL: goto x86_l_d09;
	case 3340ULL: goto x86_l_d0c;
	case 3346ULL: goto x86_l_d12;
	case 3350ULL: goto x86_l_d16;
	case 3352ULL: goto x86_l_d18;
	case 3355ULL: goto x86_l_d1b;
	case 3361ULL: goto x86_l_d21;
	case 3364ULL: goto x86_l_d24;
	case 3367ULL: goto x86_l_d27;
	case 3370ULL: goto x86_l_d2a;
	case 3372ULL: goto x86_l_d2c;
	case 3374ULL: goto x86_l_d2e;
	case 3377ULL: goto x86_l_d31;
	case 3380ULL: goto x86_l_d34;
	case 3386ULL: goto x86_l_d3a;
	case 3389ULL: goto x86_l_d3d;
	case 3395ULL: goto x86_l_d43;
	case 3397ULL: goto x86_l_d45;
	case 3402ULL: goto x86_l_d4a;
	case 3406ULL: goto x86_l_d4e;
	case 3412ULL: goto x86_l_d54;
	case 3417ULL: goto x86_l_d59;
	case 3421ULL: goto x86_l_d5d;
	case 3427ULL: goto x86_l_d63;
	case 3437ULL: goto x86_l_d6d;
	case 3441ULL: goto x86_l_d71;
	case 3447ULL: goto x86_l_d77;
	case 3454ULL: goto x86_l_d7e;
	case 3461ULL: goto x86_l_d85;
	case 3467ULL: goto x86_l_d8b;
	case 3471ULL: goto x86_l_d8f;
	case 3475ULL: goto x86_l_d93;
	case 3480ULL: goto x86_l_d98;
	case 3485ULL: goto x86_l_d9d;
	case 3490ULL: goto x86_l_da2;
	case 3493ULL: goto x86_l_da5;
	case 3497ULL: goto x86_l_da9;
	case 3501ULL: goto x86_l_dad;
	case 3504ULL: goto x86_l_db0;
	case 3509ULL: goto x86_l_db5;
	case 3511ULL: goto x86_l_db7;
	case 3514ULL: goto x86_l_dba;
	case 3518ULL: goto x86_l_dbe;
	case 3520ULL: goto x86_l_dc0;
	case 3526ULL: goto x86_l_dc6;
	case 3531ULL: goto x86_l_dcb;
	case 3536ULL: goto x86_l_dd0;
	case 3542ULL: goto x86_l_dd6;
	case 3544ULL: goto x86_l_dd8;
	case 3550ULL: goto x86_l_dde;
	case 3553ULL: goto x86_l_de1;
	case 3556ULL: goto x86_l_de4;
	case 3562ULL: goto x86_l_dea;
	case 3566ULL: goto x86_l_dee;
	case 3568ULL: goto x86_l_df0;
	case 3574ULL: goto x86_l_df6;
	case 3576ULL: goto x86_l_df8;
	case 3582ULL: goto x86_l_dfe;
	case 3585ULL: goto x86_l_e01;
	case 3591ULL: goto x86_l_e07;
	case 3595ULL: goto x86_l_e0b;
	case 3597ULL: goto x86_l_e0d;
	case 3603ULL: goto x86_l_e13;
	case 3605ULL: goto x86_l_e15;
	default: return 0xffffffffffffffffULL;
	}
x86_l_716:
	/* 0x716: cmp    r13,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 46ULL);
x86_l_71a:
	/* 0x71a: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_720:
	/* 0x720: lea    eax,[r13+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_727:
	/* 0x727: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_72c:
	/* 0x72c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_730:
	/* 0x730: mov    BYTE PTR [rsi+0x32],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_733:
	/* 0x733: cmp    r13,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 47ULL);
x86_l_737:
	/* 0x737: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_73d:
	/* 0x73d: lea    eax,[r13+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_744:
	/* 0x744: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_749:
	/* 0x749: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_74d:
	/* 0x74d: mov    BYTE PTR [rsi+0x33],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_750:
	/* 0x750: cmp    r13,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 48ULL);
x86_l_754:
	/* 0x754: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_75a:
	/* 0x75a: lea    eax,[r13+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_761:
	/* 0x761: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_766:
	/* 0x766: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_76a:
	/* 0x76a: mov    BYTE PTR [rsi+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_76d:
	/* 0x76d: cmp    r13,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 49ULL);
x86_l_771:
	/* 0x771: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_777:
	/* 0x777: lea    eax,[r13+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_77e:
	/* 0x77e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_783:
	/* 0x783: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_787:
	/* 0x787: mov    BYTE PTR [rsi+0x35],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_78a:
	/* 0x78a: cmp    r13,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 50ULL);
x86_l_78e:
	/* 0x78e: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_794:
	/* 0x794: lea    eax,[r13+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_79b:
	/* 0x79b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7a0:
	/* 0x7a0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_7a4:
	/* 0x7a4: mov    BYTE PTR [rsi+0x36],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_7a7:
	/* 0x7a7: cmp    r13,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 51ULL);
x86_l_7ab:
	/* 0x7ab: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_7b1:
	/* 0x7b1: lea    eax,[r13+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_7b8:
	/* 0x7b8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7bd:
	/* 0x7bd: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_7c1:
	/* 0x7c1: mov    BYTE PTR [rsi+0x37],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_7c4:
	/* 0x7c4: cmp    r13,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 52ULL);
x86_l_7c8:
	/* 0x7c8: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_7ce:
	/* 0x7ce: lea    eax,[r13+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_7d5:
	/* 0x7d5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7da:
	/* 0x7da: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_7de:
	/* 0x7de: mov    BYTE PTR [rsi+0x38],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7e1:
	/* 0x7e1: cmp    r13,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 53ULL);
x86_l_7e5:
	/* 0x7e5: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_7eb:
	/* 0x7eb: lea    eax,[r13+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_7f2:
	/* 0x7f2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7f7:
	/* 0x7f7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_7fb:
	/* 0x7fb: mov    BYTE PTR [rsi+0x39],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_7fe:
	/* 0x7fe: cmp    r13,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 54ULL);
x86_l_802:
	/* 0x802: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_808:
	/* 0x808: lea    eax,[r13+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_80f:
	/* 0x80f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_814:
	/* 0x814: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_818:
	/* 0x818: mov    BYTE PTR [rsi+0x3a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_81b:
	/* 0x81b: cmp    r13,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 55ULL);
x86_l_81f:
	/* 0x81f: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_825:
	/* 0x825: lea    eax,[r13+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_82c:
	/* 0x82c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_831:
	/* 0x831: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_835:
	/* 0x835: mov    BYTE PTR [rsi+0x3b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_838:
	/* 0x838: cmp    r13,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 56ULL);
x86_l_83c:
	/* 0x83c: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_842:
	/* 0x842: lea    eax,[r13+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_849:
	/* 0x849: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_84e:
	/* 0x84e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_852:
	/* 0x852: mov    BYTE PTR [rsi+0x3c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_855:
	/* 0x855: cmp    r13,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 57ULL);
x86_l_859:
	/* 0x859: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_85f:
	/* 0x85f: lea    eax,[r13+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_866:
	/* 0x866: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_86b:
	/* 0x86b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_86f:
	/* 0x86f: mov    BYTE PTR [rsi+0x3d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_872:
	/* 0x872: cmp    r13,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 58ULL);
x86_l_876:
	/* 0x876: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_87c:
	/* 0x87c: lea    eax,[r13+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_883:
	/* 0x883: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_888:
	/* 0x888: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_88c:
	/* 0x88c: mov    BYTE PTR [rsi+0x3e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_88f:
	/* 0x88f: cmp    r13,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 59ULL);
x86_l_893:
	/* 0x893: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_899:
	/* 0x899: lea    eax,[r13+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_8a0:
	/* 0x8a0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8a5:
	/* 0x8a5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_8a9:
	/* 0x8a9: mov    BYTE PTR [rsi+0x3f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_8ac:
	/* 0x8ac: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_8b0:
	/* 0x8b0: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_8b6:
	/* 0x8b6: lea    eax,[r13+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_8bd:
	/* 0x8bd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8c2:
	/* 0x8c2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_8c6:
	/* 0x8c6: mov    BYTE PTR [rsi+0x40],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8c9:
	/* 0x8c9: cmp    r13,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 61ULL);
x86_l_8cd:
	/* 0x8cd: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_8d3:
	/* 0x8d3: lea    eax,[r13+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_8da:
	/* 0x8da: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8df:
	/* 0x8df: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_8e3:
	/* 0x8e3: mov    BYTE PTR [rsi+0x41],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_8e6:
	/* 0x8e6: cmp    r13,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 62ULL);
x86_l_8ea:
	/* 0x8ea: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_8f0:
	/* 0x8f0: lea    eax,[r13+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_8f7:
	/* 0x8f7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8fc:
	/* 0x8fc: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_900:
	/* 0x900: mov    BYTE PTR [rsi+0x42],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_903:
	/* 0x903: cmp    r13,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 63ULL);
x86_l_907:
	/* 0x907: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_90d:
	/* 0x90d: lea    eax,[r13+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_914:
	/* 0x914: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_919:
	/* 0x919: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_91d:
	/* 0x91d: mov    BYTE PTR [rsi+0x43],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_920:
	/* 0x920: cmp    r13,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 64ULL);
x86_l_924:
	/* 0x924: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_92a:
	/* 0x92a: lea    eax,[r13+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_931:
	/* 0x931: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_936:
	/* 0x936: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_93a:
	/* 0x93a: mov    BYTE PTR [rsi+0x44],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_93d:
	/* 0x93d: cmp    r13,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 65ULL);
x86_l_941:
	/* 0x941: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_947:
	/* 0x947: lea    eax,[r13+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_94e:
	/* 0x94e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_953:
	/* 0x953: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_957:
	/* 0x957: mov    BYTE PTR [rsi+0x45],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_95a:
	/* 0x95a: cmp    r13,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 66ULL);
x86_l_95e:
	/* 0x95e: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_964:
	/* 0x964: lea    eax,[r13+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_96b:
	/* 0x96b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_970:
	/* 0x970: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_974:
	/* 0x974: mov    BYTE PTR [rsi+0x46],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_977:
	/* 0x977: cmp    r13,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 67ULL);
x86_l_97b:
	/* 0x97b: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_981:
	/* 0x981: lea    eax,[r13+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_988:
	/* 0x988: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_98d:
	/* 0x98d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_991:
	/* 0x991: mov    BYTE PTR [rsi+0x47],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_994:
	/* 0x994: cmp    r13,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 68ULL);
x86_l_998:
	/* 0x998: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_99e:
	/* 0x99e: lea    eax,[r13+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_9a5:
	/* 0x9a5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9aa:
	/* 0x9aa: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_9ae:
	/* 0x9ae: mov    BYTE PTR [rsi+0x48],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9b1:
	/* 0x9b1: cmp    r13,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 69ULL);
x86_l_9b5:
	/* 0x9b5: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_9bb:
	/* 0x9bb: lea    eax,[r13+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_9c2:
	/* 0x9c2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9c7:
	/* 0x9c7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_9cb:
	/* 0x9cb: mov    BYTE PTR [rsi+0x49],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_9ce:
	/* 0x9ce: cmp    r13,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 70ULL);
x86_l_9d2:
	/* 0x9d2: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_9d8:
	/* 0x9d8: lea    eax,[r13+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_9df:
	/* 0x9df: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9e4:
	/* 0x9e4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_9e8:
	/* 0x9e8: mov    BYTE PTR [rsi+0x4a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_9eb:
	/* 0x9eb: cmp    r13,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 71ULL);
x86_l_9ef:
	/* 0x9ef: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_9f5:
	/* 0x9f5: lea    eax,[r13+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_9fc:
	/* 0x9fc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a01:
	/* 0xa01: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a05:
	/* 0xa05: mov    BYTE PTR [rsi+0x4b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_a08:
	/* 0xa08: cmp    r13,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 72ULL);
x86_l_a0c:
	/* 0xa0c: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_a12:
	/* 0xa12: lea    eax,[r13+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_a19:
	/* 0xa19: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a1e:
	/* 0xa1e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a22:
	/* 0xa22: mov    BYTE PTR [rsi+0x4c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_a25:
	/* 0xa25: cmp    r13,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 73ULL);
x86_l_a29:
	/* 0xa29: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_a2f:
	/* 0xa2f: lea    eax,[r13+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_a36:
	/* 0xa36: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a3b:
	/* 0xa3b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a3f:
	/* 0xa3f: mov    BYTE PTR [rsi+0x4d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_a42:
	/* 0xa42: cmp    r13,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 74ULL);
x86_l_a46:
	/* 0xa46: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_a4c:
	/* 0xa4c: lea    eax,[r13+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_a53:
	/* 0xa53: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a58:
	/* 0xa58: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a5c:
	/* 0xa5c: mov    BYTE PTR [rsi+0x4e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_a5f:
	/* 0xa5f: cmp    r13,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 75ULL);
x86_l_a63:
	/* 0xa63: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_a69:
	/* 0xa69: lea    eax,[r13+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_a70:
	/* 0xa70: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a75:
	/* 0xa75: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a79:
	/* 0xa79: mov    BYTE PTR [rsi+0x4f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_a7c:
	/* 0xa7c: cmp    r13,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 76ULL);
x86_l_a80:
	/* 0xa80: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_a86:
	/* 0xa86: lea    eax,[r13+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_a8d:
	/* 0xa8d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a92:
	/* 0xa92: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a96:
	/* 0xa96: mov    BYTE PTR [rsi+0x50],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a99:
	/* 0xa99: cmp    r13,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 77ULL);
x86_l_a9d:
	/* 0xa9d: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_aa3:
	/* 0xaa3: lea    eax,[r13+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_aaa:
	/* 0xaaa: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_aaf:
	/* 0xaaf: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_ab3:
	/* 0xab3: mov    BYTE PTR [rsi+0x51],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_ab6:
	/* 0xab6: cmp    r13,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 78ULL);
x86_l_aba:
	/* 0xaba: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_ac0:
	/* 0xac0: lea    eax,[r13+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_ac7:
	/* 0xac7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_acc:
	/* 0xacc: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_ad0:
	/* 0xad0: mov    BYTE PTR [rsi+0x52],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_ad3:
	/* 0xad3: cmp    r13,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 79ULL);
x86_l_ad7:
	/* 0xad7: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_add:
	/* 0xadd: lea    eax,[r13+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_ae4:
	/* 0xae4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ae9:
	/* 0xae9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_aed:
	/* 0xaed: mov    BYTE PTR [rsi+0x53],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_af0:
	/* 0xaf0: cmp    r13,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 80ULL);
x86_l_af4:
	/* 0xaf4: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_afa:
	/* 0xafa: lea    eax,[r13+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_b01:
	/* 0xb01: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b06:
	/* 0xb06: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b0a:
	/* 0xb0a: mov    BYTE PTR [rsi+0x54],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_b0d:
	/* 0xb0d: cmp    r13,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 81ULL);
x86_l_b11:
	/* 0xb11: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_b17:
	/* 0xb17: lea    eax,[r13+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_b1e:
	/* 0xb1e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b23:
	/* 0xb23: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b27:
	/* 0xb27: mov    BYTE PTR [rsi+0x55],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_b2a:
	/* 0xb2a: cmp    r13,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 82ULL);
x86_l_b2e:
	/* 0xb2e: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_b34:
	/* 0xb34: lea    eax,[r13+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_b3b:
	/* 0xb3b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b40:
	/* 0xb40: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b44:
	/* 0xb44: mov    BYTE PTR [rsi+0x56],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_b47:
	/* 0xb47: cmp    r13,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 83ULL);
x86_l_b4b:
	/* 0xb4b: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_b51:
	/* 0xb51: lea    eax,[r13+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_b58:
	/* 0xb58: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b5d:
	/* 0xb5d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b61:
	/* 0xb61: mov    BYTE PTR [rsi+0x57],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_b64:
	/* 0xb64: cmp    r13,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 84ULL);
x86_l_b68:
	/* 0xb68: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_b6e:
	/* 0xb6e: lea    eax,[r13+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_b75:
	/* 0xb75: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b7a:
	/* 0xb7a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b7e:
	/* 0xb7e: mov    BYTE PTR [rsi+0x58],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b81:
	/* 0xb81: cmp    r13,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 85ULL);
x86_l_b85:
	/* 0xb85: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_b8b:
	/* 0xb8b: lea    eax,[r13+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_b92:
	/* 0xb92: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b97:
	/* 0xb97: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b9b:
	/* 0xb9b: mov    BYTE PTR [rsi+0x59],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_b9e:
	/* 0xb9e: cmp    r13,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 86ULL);
x86_l_ba2:
	/* 0xba2: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_ba8:
	/* 0xba8: lea    eax,[r13+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_baf:
	/* 0xbaf: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bb4:
	/* 0xbb4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_bb8:
	/* 0xbb8: mov    BYTE PTR [rsi+0x5a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_bbb:
	/* 0xbbb: cmp    r13,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 87ULL);
x86_l_bbf:
	/* 0xbbf: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_bc5:
	/* 0xbc5: lea    eax,[r13+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_bcc:
	/* 0xbcc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bd1:
	/* 0xbd1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_bd5:
	/* 0xbd5: mov    BYTE PTR [rsi+0x5b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_bd8:
	/* 0xbd8: cmp    r13,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 88ULL);
x86_l_bdc:
	/* 0xbdc: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_be2:
	/* 0xbe2: lea    eax,[r13+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_be9:
	/* 0xbe9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bee:
	/* 0xbee: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_bf2:
	/* 0xbf2: mov    BYTE PTR [rsi+0x5c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_bf5:
	/* 0xbf5: cmp    r13,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 89ULL);
x86_l_bf9:
	/* 0xbf9: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_bfb:
	/* 0xbfb: lea    eax,[r13+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_c02:
	/* 0xc02: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c07:
	/* 0xc07: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c0b:
	/* 0xc0b: mov    BYTE PTR [rsi+0x5d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_c0e:
	/* 0xc0e: cmp    r13,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 90ULL);
x86_l_c12:
	/* 0xc12: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_c14:
	/* 0xc14: lea    eax,[r13+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_c1b:
	/* 0xc1b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c20:
	/* 0xc20: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c24:
	/* 0xc24: mov    BYTE PTR [rsi+0x5e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_c27:
	/* 0xc27: cmp    r13,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 91ULL);
x86_l_c2b:
	/* 0xc2b: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_c2d:
	/* 0xc2d: lea    eax,[r13+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_c34:
	/* 0xc34: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c39:
	/* 0xc39: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c3d:
	/* 0xc3d: mov    BYTE PTR [rsi+0x5f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_c40:
	/* 0xc40: cmp    r13,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 92ULL);
x86_l_c44:
	/* 0xc44: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_c46:
	/* 0xc46: lea    eax,[r13+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_c4d:
	/* 0xc4d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c52:
	/* 0xc52: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c56:
	/* 0xc56: mov    BYTE PTR [rsi+0x60],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c59:
	/* 0xc59: cmp    r13,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 93ULL);
x86_l_c5d:
	/* 0xc5d: je     c75 <generic_retkprobe_filter_arg_2+0xc75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c75;
	}
x86_l_c5f:
	/* 0xc5f: add    r13d,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_c66:
	/* 0xc66: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c6d:
	/* 0xc6d: movzx  eax,BYTE PTR [rcx+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_c72:
	/* 0xc72: mov    BYTE PTR [rsi+0x61],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_c75:
	/* 0xc75: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c7a:
	/* 0xc7a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_c7d:
	/* 0xc7d: jmp    3198 <generic_retkprobe_filter_arg_2+0x3198> */
	return 12696ULL;
x86_l_c82:
	/* 0xc82: lea    eax,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_c85:
	/* 0xc85: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c88:
	/* 0xc88: jb     d21 <generic_retkprobe_filter_arg_2+0xd21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d21;
	}
x86_l_c8e:
	/* 0xc8e: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c91:
	/* 0xc91: je     ca0 <generic_retkprobe_filter_arg_2+0xca0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ca0;
	}
x86_l_c93:
	/* 0xc93: jmp    31d0 <generic_retkprobe_filter_arg_2+0x31d0> */
	return 12752ULL;
x86_l_c98:
	/* 0xc98: lea    eax,[rcx-0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551576ULL);
x86_l_c9b:
	/* 0xc9b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c9e:
	/* 0xc9e: jae    d18 <generic_retkprobe_filter_arg_2+0xd18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_d18;
	}
x86_l_ca0:
	/* 0xca0: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_ca9:
	/* 0xca9: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_cb2:
	/* 0xcb2: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_cbb:
	/* 0xcbb: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_cc4:
	/* 0xcc4: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_ccd:
	/* 0xccd: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cd0:
	/* 0xcd0: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_cd3:
	/* 0xcd3: jg     cef <generic_retkprobe_filter_arg_2+0xcef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_cef;
	}
x86_l_cd5:
	/* 0xcd5: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_cd8:
	/* 0xcd8: je     1b0e <generic_retkprobe_filter_arg_2+0x1b0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6926ULL;
	}
x86_l_cde:
	/* 0xcde: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_ce1:
	/* 0xce1: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_ce4:
	/* 0xce4: je     1b10 <generic_retkprobe_filter_arg_2+0x1b10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6928ULL;
	}
x86_l_cea:
	/* 0xcea: jmp    31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	return 12747ULL;
x86_l_cef:
	/* 0xcef: cmp    ecx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_cf2:
	/* 0xcf2: je     1ae4 <generic_retkprobe_filter_arg_2+0x1ae4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6884ULL;
	}
x86_l_cf8:
	/* 0xcf8: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_cfb:
	/* 0xcfb: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_cfe:
	/* 0xcfe: je     1b10 <generic_retkprobe_filter_arg_2+0x1b10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6928ULL;
	}
x86_l_d04:
	/* 0xd04: jmp    31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	return 12747ULL;
x86_l_d09:
	/* 0xd09: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_d0c:
	/* 0xd0c: jne    31d0 <generic_retkprobe_filter_arg_2+0x31d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12752ULL;
	}
x86_l_d12:
	/* 0xd12: add    r8,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_d16:
	/* 0xd16: jmp    d21 <generic_retkprobe_filter_arg_2+0xd21> */
	goto x86_l_d21;
x86_l_d18:
	/* 0xd18: cmp    ecx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 42ULL);
x86_l_d1b:
	/* 0xd1b: jne    31d0 <generic_retkprobe_filter_arg_2+0x31d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12752ULL;
	}
x86_l_d21:
	/* 0xd21: mov    r13d,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d24:
	/* 0xd24: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d27:
	/* 0xd27: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_d2a:
	/* 0xd2a: jne    d3a <generic_retkprobe_filter_arg_2+0xd3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d3a;
	}
x86_l_d2c:
	/* 0xd2c: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_d2e:
	/* 0xd2e: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_d31:
	/* 0xd31: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_d34:
	/* 0xd34: jne    31da <generic_retkprobe_filter_arg_2+0x31da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12762ULL;
	}
x86_l_d3a:
	/* 0xd3a: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_d3d:
	/* 0xd3d: ja     1b87 <generic_retkprobe_filter_arg_2+0x1b87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7047ULL;
	}
x86_l_d43:
	/* 0xd43: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_d45:
	/* 0xd45: mov    edx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 67109120ULL);
x86_l_d4a:
	/* 0xd4a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_d4e:
	/* 0xd4e: jb     26e7 <generic_retkprobe_filter_arg_2+0x26e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9959ULL;
	}
x86_l_d54:
	/* 0xd54: mov    edx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 134218240ULL);
x86_l_d59:
	/* 0xd59: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_d5d:
	/* 0xd5d: jb     1bd0 <generic_retkprobe_filter_arg_2+0x1bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7120ULL;
	}
x86_l_d63:
	/* 0xd63: movabs rdx,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 206158430208ULL);
x86_l_d6d:
	/* 0xd6d: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_d71:
	/* 0xd71: jae    1b87 <generic_retkprobe_filter_arg_2+0x1b87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7047ULL;
	}
x86_l_d77:
	/* 0xd77: mov    WORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_d7e:
	/* 0xd7e: cmp    r13d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 144ULL);
x86_l_d85:
	/* 0xd85: ja     1ba8 <generic_retkprobe_filter_arg_2+0x1ba8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7080ULL;
	}
x86_l_d8b:
	/* 0xd8b: lea    rcx,[r8+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_d8f:
	/* 0xd8f: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_d93:
	/* 0xd93: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d98:
	/* 0xd98: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_d9d:
	/* 0xd9d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_da2:
	/* 0xda2: mov    ecx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_da5:
	/* 0xda5: lea    rdx,[r8+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_da9:
	/* 0xda9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_dad:
	/* 0xdad: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_db0:
	/* 0xdb0: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_db5:
	/* 0xdb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db7:
	/* 0xdb7: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_dba:
	/* 0xdba: mov    ecx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dbe:
	/* 0xdbe: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_dc0:
	/* 0xdc0: je     1ba8 <generic_retkprobe_filter_arg_2+0x1ba8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7080ULL;
	}
x86_l_dc6:
	/* 0xdc6: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_dcb:
	/* 0xdcb: and    eax,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_dd0:
	/* 0xdd0: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_dd6:
	/* 0xdd6: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_dd8:
	/* 0xdd8: je     310e <generic_retkprobe_filter_arg_2+0x310e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12558ULL;
	}
x86_l_dde:
	/* 0xdde: mov    ecx,DWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_de1:
	/* 0xde1: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_de4:
	/* 0xde4: jbe    2fb1 <generic_retkprobe_filter_arg_2+0x2fb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 12209ULL;
	}
x86_l_dea:
	/* 0xdea: mov    edx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_dee:
	/* 0xdee: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_df0:
	/* 0xdf0: je     2fb1 <generic_retkprobe_filter_arg_2+0x2fb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12209ULL;
	}
x86_l_df6:
	/* 0xdf6: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_df8:
	/* 0xdf8: je     2fb4 <generic_retkprobe_filter_arg_2+0x2fb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12212ULL;
	}
x86_l_dfe:
	/* 0xdfe: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_e01:
	/* 0xe01: jb     2fb1 <generic_retkprobe_filter_arg_2+0x2fb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12209ULL;
	}
x86_l_e07:
	/* 0xe07: mov    edx,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e0b:
	/* 0xe0b: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_e0d:
	/* 0xe0d: je     2fb1 <generic_retkprobe_filter_arg_2+0x2fb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12209ULL;
	}
x86_l_e13:
	/* 0xe13: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_e15:
	/* 0xe15: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
	return 3608ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_generic_retkprobe_filter_arg_2_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3608ULL: goto x86_l_e18;
	case 3614ULL: goto x86_l_e1e;
	case 3617ULL: goto x86_l_e21;
	case 3623ULL: goto x86_l_e27;
	case 3627ULL: goto x86_l_e2b;
	case 3629ULL: goto x86_l_e2d;
	case 3635ULL: goto x86_l_e33;
	case 3638ULL: goto x86_l_e36;
	case 3640ULL: goto x86_l_e38;
	case 3644ULL: goto x86_l_e3c;
	case 3649ULL: goto x86_l_e41;
	case 3652ULL: goto x86_l_e44;
	case 3655ULL: goto x86_l_e47;
	case 3658ULL: goto x86_l_e4a;
	case 3664ULL: goto x86_l_e50;
	case 3668ULL: goto x86_l_e54;
	case 3672ULL: goto x86_l_e58;
	case 3677ULL: goto x86_l_e5d;
	case 3680ULL: goto x86_l_e60;
	case 3685ULL: goto x86_l_e65;
	case 3691ULL: goto x86_l_e6b;
	case 3696ULL: goto x86_l_e70;
	case 3699ULL: goto x86_l_e73;
	case 3705ULL: goto x86_l_e79;
	case 3710ULL: goto x86_l_e7e;
	case 3713ULL: goto x86_l_e81;
	case 3719ULL: goto x86_l_e87;
	case 3722ULL: goto x86_l_e8a;
	case 3726ULL: goto x86_l_e8e;
	case 3729ULL: goto x86_l_e91;
	case 3733ULL: goto x86_l_e95;
	case 3741ULL: goto x86_l_e9d;
	case 3748ULL: goto x86_l_ea4;
	case 3753ULL: goto x86_l_ea9;
	case 3758ULL: goto x86_l_eae;
	case 3760ULL: goto x86_l_eb0;
	case 3763ULL: goto x86_l_eb3;
	case 3769ULL: goto x86_l_eb9;
	case 3775ULL: goto x86_l_ebf;
	case 3780ULL: goto x86_l_ec4;
	case 3783ULL: goto x86_l_ec7;
	case 3789ULL: goto x86_l_ecd;
	case 3796ULL: goto x86_l_ed4;
	case 3801ULL: goto x86_l_ed9;
	case 3806ULL: goto x86_l_ede;
	case 3808ULL: goto x86_l_ee0;
	case 3811ULL: goto x86_l_ee3;
	case 3817ULL: goto x86_l_ee9;
	case 3820ULL: goto x86_l_eec;
	case 3825ULL: goto x86_l_ef1;
	case 3828ULL: goto x86_l_ef4;
	case 3833ULL: goto x86_l_ef9;
	case 3836ULL: goto x86_l_efc;
	case 3839ULL: goto x86_l_eff;
	case 3841ULL: goto x86_l_f01;
	case 3844ULL: goto x86_l_f04;
	case 3849ULL: goto x86_l_f09;
	case 3855ULL: goto x86_l_f0f;
	case 3858ULL: goto x86_l_f12;
	case 3862ULL: goto x86_l_f16;
	case 3868ULL: goto x86_l_f1c;
	case 3874ULL: goto x86_l_f22;
	case 3879ULL: goto x86_l_f27;
	case 3885ULL: goto x86_l_f2d;
	case 3888ULL: goto x86_l_f30;
	case 3892ULL: goto x86_l_f34;
	case 3898ULL: goto x86_l_f3a;
	case 3904ULL: goto x86_l_f40;
	case 3909ULL: goto x86_l_f45;
	case 3915ULL: goto x86_l_f4b;
	case 3918ULL: goto x86_l_f4e;
	case 3922ULL: goto x86_l_f52;
	case 3928ULL: goto x86_l_f58;
	case 3934ULL: goto x86_l_f5e;
	case 3939ULL: goto x86_l_f63;
	case 3945ULL: goto x86_l_f69;
	case 3948ULL: goto x86_l_f6c;
	case 3952ULL: goto x86_l_f70;
	case 3958ULL: goto x86_l_f76;
	case 3964ULL: goto x86_l_f7c;
	case 3969ULL: goto x86_l_f81;
	case 3975ULL: goto x86_l_f87;
	case 3978ULL: goto x86_l_f8a;
	case 3982ULL: goto x86_l_f8e;
	case 3988ULL: goto x86_l_f94;
	case 3994ULL: goto x86_l_f9a;
	case 3999ULL: goto x86_l_f9f;
	case 4005ULL: goto x86_l_fa5;
	case 4008ULL: goto x86_l_fa8;
	case 4012ULL: goto x86_l_fac;
	case 4018ULL: goto x86_l_fb2;
	case 4024ULL: goto x86_l_fb8;
	case 4029ULL: goto x86_l_fbd;
	case 4035ULL: goto x86_l_fc3;
	case 4038ULL: goto x86_l_fc6;
	case 4042ULL: goto x86_l_fca;
	case 4048ULL: goto x86_l_fd0;
	case 4054ULL: goto x86_l_fd6;
	case 4059ULL: goto x86_l_fdb;
	case 4065ULL: goto x86_l_fe1;
	case 4068ULL: goto x86_l_fe4;
	case 4072ULL: goto x86_l_fe8;
	case 4078ULL: goto x86_l_fee;
	case 4084ULL: goto x86_l_ff4;
	case 4089ULL: goto x86_l_ff9;
	case 4095ULL: goto x86_l_fff;
	case 4098ULL: goto x86_l_1002;
	case 4102ULL: goto x86_l_1006;
	case 4108ULL: goto x86_l_100c;
	case 4114ULL: goto x86_l_1012;
	case 4119ULL: goto x86_l_1017;
	case 4125ULL: goto x86_l_101d;
	case 4128ULL: goto x86_l_1020;
	case 4132ULL: goto x86_l_1024;
	case 4138ULL: goto x86_l_102a;
	case 4144ULL: goto x86_l_1030;
	case 4149ULL: goto x86_l_1035;
	case 4155ULL: goto x86_l_103b;
	case 4158ULL: goto x86_l_103e;
	case 4162ULL: goto x86_l_1042;
	case 4168ULL: goto x86_l_1048;
	case 4174ULL: goto x86_l_104e;
	case 4179ULL: goto x86_l_1053;
	case 4185ULL: goto x86_l_1059;
	case 4188ULL: goto x86_l_105c;
	case 4192ULL: goto x86_l_1060;
	case 4198ULL: goto x86_l_1066;
	case 4204ULL: goto x86_l_106c;
	case 4209ULL: goto x86_l_1071;
	case 4215ULL: goto x86_l_1077;
	case 4218ULL: goto x86_l_107a;
	case 4222ULL: goto x86_l_107e;
	case 4228ULL: goto x86_l_1084;
	case 4234ULL: goto x86_l_108a;
	case 4239ULL: goto x86_l_108f;
	case 4245ULL: goto x86_l_1095;
	case 4248ULL: goto x86_l_1098;
	case 4252ULL: goto x86_l_109c;
	case 4258ULL: goto x86_l_10a2;
	case 4264ULL: goto x86_l_10a8;
	case 4269ULL: goto x86_l_10ad;
	case 4275ULL: goto x86_l_10b3;
	case 4278ULL: goto x86_l_10b6;
	case 4282ULL: goto x86_l_10ba;
	case 4288ULL: goto x86_l_10c0;
	case 4294ULL: goto x86_l_10c6;
	case 4299ULL: goto x86_l_10cb;
	case 4305ULL: goto x86_l_10d1;
	case 4308ULL: goto x86_l_10d4;
	case 4312ULL: goto x86_l_10d8;
	case 4318ULL: goto x86_l_10de;
	case 4324ULL: goto x86_l_10e4;
	case 4329ULL: goto x86_l_10e9;
	case 4335ULL: goto x86_l_10ef;
	case 4338ULL: goto x86_l_10f2;
	case 4342ULL: goto x86_l_10f6;
	case 4348ULL: goto x86_l_10fc;
	case 4354ULL: goto x86_l_1102;
	case 4359ULL: goto x86_l_1107;
	case 4365ULL: goto x86_l_110d;
	case 4368ULL: goto x86_l_1110;
	case 4372ULL: goto x86_l_1114;
	case 4378ULL: goto x86_l_111a;
	case 4384ULL: goto x86_l_1120;
	case 4389ULL: goto x86_l_1125;
	case 4395ULL: goto x86_l_112b;
	case 4398ULL: goto x86_l_112e;
	case 4402ULL: goto x86_l_1132;
	case 4408ULL: goto x86_l_1138;
	case 4414ULL: goto x86_l_113e;
	case 4419ULL: goto x86_l_1143;
	case 4425ULL: goto x86_l_1149;
	case 4428ULL: goto x86_l_114c;
	case 4432ULL: goto x86_l_1150;
	case 4438ULL: goto x86_l_1156;
	case 4444ULL: goto x86_l_115c;
	case 4449ULL: goto x86_l_1161;
	case 4455ULL: goto x86_l_1167;
	case 4458ULL: goto x86_l_116a;
	case 4462ULL: goto x86_l_116e;
	case 4468ULL: goto x86_l_1174;
	case 4474ULL: goto x86_l_117a;
	case 4479ULL: goto x86_l_117f;
	case 4485ULL: goto x86_l_1185;
	case 4488ULL: goto x86_l_1188;
	case 4492ULL: goto x86_l_118c;
	case 4498ULL: goto x86_l_1192;
	case 4504ULL: goto x86_l_1198;
	case 4509ULL: goto x86_l_119d;
	case 4515ULL: goto x86_l_11a3;
	case 4518ULL: goto x86_l_11a6;
	case 4522ULL: goto x86_l_11aa;
	case 4528ULL: goto x86_l_11b0;
	case 4534ULL: goto x86_l_11b6;
	case 4539ULL: goto x86_l_11bb;
	case 4545ULL: goto x86_l_11c1;
	case 4548ULL: goto x86_l_11c4;
	case 4552ULL: goto x86_l_11c8;
	case 4558ULL: goto x86_l_11ce;
	case 4564ULL: goto x86_l_11d4;
	case 4569ULL: goto x86_l_11d9;
	case 4575ULL: goto x86_l_11df;
	case 4578ULL: goto x86_l_11e2;
	case 4582ULL: goto x86_l_11e6;
	case 4588ULL: goto x86_l_11ec;
	case 4594ULL: goto x86_l_11f2;
	case 4599ULL: goto x86_l_11f7;
	case 4605ULL: goto x86_l_11fd;
	case 4608ULL: goto x86_l_1200;
	case 4612ULL: goto x86_l_1204;
	case 4618ULL: goto x86_l_120a;
	case 4624ULL: goto x86_l_1210;
	case 4629ULL: goto x86_l_1215;
	case 4635ULL: goto x86_l_121b;
	case 4638ULL: goto x86_l_121e;
	case 4642ULL: goto x86_l_1222;
	case 4648ULL: goto x86_l_1228;
	case 4654ULL: goto x86_l_122e;
	case 4659ULL: goto x86_l_1233;
	case 4665ULL: goto x86_l_1239;
	case 4668ULL: goto x86_l_123c;
	case 4672ULL: goto x86_l_1240;
	case 4678ULL: goto x86_l_1246;
	case 4684ULL: goto x86_l_124c;
	case 4689ULL: goto x86_l_1251;
	case 4695ULL: goto x86_l_1257;
	case 4698ULL: goto x86_l_125a;
	case 4702ULL: goto x86_l_125e;
	case 4708ULL: goto x86_l_1264;
	case 4714ULL: goto x86_l_126a;
	case 4719ULL: goto x86_l_126f;
	case 4725ULL: goto x86_l_1275;
	case 4728ULL: goto x86_l_1278;
	case 4732ULL: goto x86_l_127c;
	case 4738ULL: goto x86_l_1282;
	case 4744ULL: goto x86_l_1288;
	case 4749ULL: goto x86_l_128d;
	case 4755ULL: goto x86_l_1293;
	case 4758ULL: goto x86_l_1296;
	case 4762ULL: goto x86_l_129a;
	case 4768ULL: goto x86_l_12a0;
	case 4774ULL: goto x86_l_12a6;
	case 4779ULL: goto x86_l_12ab;
	case 4785ULL: goto x86_l_12b1;
	case 4788ULL: goto x86_l_12b4;
	case 4792ULL: goto x86_l_12b8;
	case 4798ULL: goto x86_l_12be;
	case 4804ULL: goto x86_l_12c4;
	case 4809ULL: goto x86_l_12c9;
	case 4815ULL: goto x86_l_12cf;
	case 4818ULL: goto x86_l_12d2;
	case 4822ULL: goto x86_l_12d6;
	case 4828ULL: goto x86_l_12dc;
	case 4834ULL: goto x86_l_12e2;
	case 4839ULL: goto x86_l_12e7;
	case 4845ULL: goto x86_l_12ed;
	case 4848ULL: goto x86_l_12f0;
	case 4852ULL: goto x86_l_12f4;
	case 4858ULL: goto x86_l_12fa;
	case 4864ULL: goto x86_l_1300;
	case 4869ULL: goto x86_l_1305;
	case 4875ULL: goto x86_l_130b;
	case 4878ULL: goto x86_l_130e;
	case 4882ULL: goto x86_l_1312;
	case 4888ULL: goto x86_l_1318;
	case 4894ULL: goto x86_l_131e;
	case 4899ULL: goto x86_l_1323;
	case 4905ULL: goto x86_l_1329;
	case 4908ULL: goto x86_l_132c;
	case 4912ULL: goto x86_l_1330;
	case 4918ULL: goto x86_l_1336;
	case 4924ULL: goto x86_l_133c;
	case 4929ULL: goto x86_l_1341;
	case 4935ULL: goto x86_l_1347;
	case 4938ULL: goto x86_l_134a;
	case 4942ULL: goto x86_l_134e;
	case 4948ULL: goto x86_l_1354;
	case 4954ULL: goto x86_l_135a;
	case 4959ULL: goto x86_l_135f;
	case 4965ULL: goto x86_l_1365;
	case 4968ULL: goto x86_l_1368;
	case 4972ULL: goto x86_l_136c;
	case 4978ULL: goto x86_l_1372;
	case 4984ULL: goto x86_l_1378;
	case 4989ULL: goto x86_l_137d;
	case 4995ULL: goto x86_l_1383;
	case 4998ULL: goto x86_l_1386;
	case 5002ULL: goto x86_l_138a;
	case 5008ULL: goto x86_l_1390;
	case 5014ULL: goto x86_l_1396;
	case 5019ULL: goto x86_l_139b;
	case 5025ULL: goto x86_l_13a1;
	case 5028ULL: goto x86_l_13a4;
	case 5032ULL: goto x86_l_13a8;
	case 5038ULL: goto x86_l_13ae;
	case 5044ULL: goto x86_l_13b4;
	case 5049ULL: goto x86_l_13b9;
	case 5055ULL: goto x86_l_13bf;
	case 5058ULL: goto x86_l_13c2;
	case 5062ULL: goto x86_l_13c6;
	case 5068ULL: goto x86_l_13cc;
	case 5074ULL: goto x86_l_13d2;
	case 5079ULL: goto x86_l_13d7;
	case 5085ULL: goto x86_l_13dd;
	case 5088ULL: goto x86_l_13e0;
	case 5092ULL: goto x86_l_13e4;
	case 5098ULL: goto x86_l_13ea;
	case 5104ULL: goto x86_l_13f0;
	case 5109ULL: goto x86_l_13f5;
	case 5115ULL: goto x86_l_13fb;
	case 5118ULL: goto x86_l_13fe;
	case 5122ULL: goto x86_l_1402;
	case 5128ULL: goto x86_l_1408;
	case 5134ULL: goto x86_l_140e;
	case 5139ULL: goto x86_l_1413;
	case 5145ULL: goto x86_l_1419;
	case 5148ULL: goto x86_l_141c;
	case 5152ULL: goto x86_l_1420;
	case 5158ULL: goto x86_l_1426;
	case 5164ULL: goto x86_l_142c;
	case 5169ULL: goto x86_l_1431;
	case 5175ULL: goto x86_l_1437;
	case 5178ULL: goto x86_l_143a;
	case 5182ULL: goto x86_l_143e;
	case 5188ULL: goto x86_l_1444;
	case 5194ULL: goto x86_l_144a;
	case 5199ULL: goto x86_l_144f;
	case 5205ULL: goto x86_l_1455;
	case 5208ULL: goto x86_l_1458;
	case 5212ULL: goto x86_l_145c;
	case 5218ULL: goto x86_l_1462;
	case 5224ULL: goto x86_l_1468;
	case 5229ULL: goto x86_l_146d;
	case 5235ULL: goto x86_l_1473;
	case 5238ULL: goto x86_l_1476;
	case 5242ULL: goto x86_l_147a;
	case 5248ULL: goto x86_l_1480;
	case 5254ULL: goto x86_l_1486;
	case 5259ULL: goto x86_l_148b;
	case 5265ULL: goto x86_l_1491;
	case 5268ULL: goto x86_l_1494;
	case 5272ULL: goto x86_l_1498;
	case 5278ULL: goto x86_l_149e;
	case 5284ULL: goto x86_l_14a4;
	case 5289ULL: goto x86_l_14a9;
	case 5295ULL: goto x86_l_14af;
	case 5298ULL: goto x86_l_14b2;
	case 5302ULL: goto x86_l_14b6;
	case 5308ULL: goto x86_l_14bc;
	case 5314ULL: goto x86_l_14c2;
	case 5319ULL: goto x86_l_14c7;
	case 5325ULL: goto x86_l_14cd;
	case 5328ULL: goto x86_l_14d0;
	case 5332ULL: goto x86_l_14d4;
	case 5338ULL: goto x86_l_14da;
	case 5344ULL: goto x86_l_14e0;
	case 5349ULL: goto x86_l_14e5;
	case 5355ULL: goto x86_l_14eb;
	case 5358ULL: goto x86_l_14ee;
	case 5362ULL: goto x86_l_14f2;
	case 5368ULL: goto x86_l_14f8;
	case 5374ULL: goto x86_l_14fe;
	case 5379ULL: goto x86_l_1503;
	case 5385ULL: goto x86_l_1509;
	case 5388ULL: goto x86_l_150c;
	case 5392ULL: goto x86_l_1510;
	case 5398ULL: goto x86_l_1516;
	case 5404ULL: goto x86_l_151c;
	case 5409ULL: goto x86_l_1521;
	case 5415ULL: goto x86_l_1527;
	case 5418ULL: goto x86_l_152a;
	case 5422ULL: goto x86_l_152e;
	case 5428ULL: goto x86_l_1534;
	case 5434ULL: goto x86_l_153a;
	case 5439ULL: goto x86_l_153f;
	case 5445ULL: goto x86_l_1545;
	case 5448ULL: goto x86_l_1548;
	case 5452ULL: goto x86_l_154c;
	case 5458ULL: goto x86_l_1552;
	case 5464ULL: goto x86_l_1558;
	case 5469ULL: goto x86_l_155d;
	case 5475ULL: goto x86_l_1563;
	case 5478ULL: goto x86_l_1566;
	case 5482ULL: goto x86_l_156a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e18:
	/* 0xe18: je     310e <generic_retkprobe_filter_arg_2+0x310e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12558ULL;
	}
x86_l_e1e:
	/* 0xe1e: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_e21:
	/* 0xe21: jb     2fb1 <generic_retkprobe_filter_arg_2+0x2fb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12209ULL;
	}
x86_l_e27:
	/* 0xe27: mov    ecx,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_e2b:
	/* 0xe2b: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_e2d:
	/* 0xe2d: je     2fb1 <generic_retkprobe_filter_arg_2+0x2fb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12209ULL;
	}
x86_l_e33:
	/* 0xe33: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e36:
	/* 0xe36: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_e38:
	/* 0xe38: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_e3c:
	/* 0xe3c: jmp    2fb4 <generic_retkprobe_filter_arg_2+0x2fb4> */
	return 12212ULL;
x86_l_e41:
	/* 0xe41: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e44:
	/* 0xe44: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e47:
	/* 0xe47: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_e4a:
	/* 0xe4a: ja     31b0 <generic_retkprobe_filter_arg_2+0x31b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12720ULL;
	}
x86_l_e50:
	/* 0xe50: mov    edx,DWORD PTR [r8+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e54:
	/* 0xe54: add    r8,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_e58:
	/* 0xe58: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_e5d:
	/* 0xe5d: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_e60:
	/* 0xe60: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e65:
	/* 0xe65: jb     29a0 <generic_retkprobe_filter_arg_2+0x29a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10656ULL;
	}
x86_l_e6b:
	/* 0xe6b: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_e70:
	/* 0xe70: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_e73:
	/* 0xe73: jb     28fc <generic_retkprobe_filter_arg_2+0x28fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10492ULL;
	}
x86_l_e79:
	/* 0xe79: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_e7e:
	/* 0xe7e: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_e81:
	/* 0xe81: jae    31b0 <generic_retkprobe_filter_arg_2+0x31b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12720ULL;
	}
x86_l_e87:
	/* 0xe87: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_e8a:
	/* 0xe8a: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e8e:
	/* 0xe8e: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e91:
	/* 0xe91: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e95:
	/* 0xe95: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_e9d:
	/* 0xe9d: mov    rdi,QWORD PTR [rip+0x17e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_ea4:
	/* 0xea4: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ea9:
	/* 0xea9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_eae:
	/* 0xeae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eb0:
	/* 0xeb0: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_eb3:
	/* 0xeb3: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_eb9:
	/* 0xeb9: je     31a9 <generic_retkprobe_filter_arg_2+0x31a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12713ULL;
	}
x86_l_ebf:
	/* 0xebf: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ec4:
	/* 0xec4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ec7:
	/* 0xec7: je     31a9 <generic_retkprobe_filter_arg_2+0x31a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12713ULL;
	}
x86_l_ecd:
	/* 0xecd: mov    rdi,QWORD PTR [rip+0x17e4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_ed4:
	/* 0xed4: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ed9:
	/* 0xed9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ede:
	/* 0xede: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee0:
	/* 0xee0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ee3:
	/* 0xee3: je     31a6 <generic_retkprobe_filter_arg_2+0x31a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12710ULL;
	}
x86_l_ee9:
	/* 0xee9: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_eec:
	/* 0xeec: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ef1:
	/* 0xef1: cmp    edx,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 94ULL);
x86_l_ef4:
	/* 0xef4: mov    eax,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 94ULL);
x86_l_ef9:
	/* 0xef9: cmovb  eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_B);
x86_l_efc:
	/* 0xefc: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_eff:
	/* 0xeff: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f01:
	/* 0xf01: lea    eax,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_f04:
	/* 0xf04: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f09:
	/* 0xf09: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f0f:
	/* 0xf0f: mov    BYTE PTR [rsi+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f12:
	/* 0xf12: cmp    rdx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 1ULL);
x86_l_f16:
	/* 0xf16: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_f1c:
	/* 0xf1c: lea    eax,[rdx+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_f22:
	/* 0xf22: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f27:
	/* 0xf27: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f2d:
	/* 0xf2d: mov    BYTE PTR [rsi+0x5],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_f30:
	/* 0xf30: cmp    rdx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 2ULL);
x86_l_f34:
	/* 0xf34: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_f3a:
	/* 0xf3a: lea    eax,[rdx+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_f40:
	/* 0xf40: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f45:
	/* 0xf45: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f4b:
	/* 0xf4b: mov    BYTE PTR [rsi+0x6],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_f4e:
	/* 0xf4e: cmp    rdx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 3ULL);
x86_l_f52:
	/* 0xf52: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_f58:
	/* 0xf58: lea    eax,[rdx+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_f5e:
	/* 0xf5e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f63:
	/* 0xf63: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f69:
	/* 0xf69: mov    BYTE PTR [rsi+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_f6c:
	/* 0xf6c: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_f70:
	/* 0xf70: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_f76:
	/* 0xf76: lea    eax,[rdx+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_f7c:
	/* 0xf7c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f81:
	/* 0xf81: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f87:
	/* 0xf87: mov    BYTE PTR [rsi+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f8a:
	/* 0xf8a: cmp    rdx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 5ULL);
x86_l_f8e:
	/* 0xf8e: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_f94:
	/* 0xf94: lea    eax,[rdx+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_f9a:
	/* 0xf9a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f9f:
	/* 0xf9f: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_fa5:
	/* 0xfa5: mov    BYTE PTR [rsi+0x9],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_fa8:
	/* 0xfa8: cmp    rdx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 6ULL);
x86_l_fac:
	/* 0xfac: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_fb2:
	/* 0xfb2: lea    eax,[rdx+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_fb8:
	/* 0xfb8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fbd:
	/* 0xfbd: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_fc3:
	/* 0xfc3: mov    BYTE PTR [rsi+0xa],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_fc6:
	/* 0xfc6: cmp    rdx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 7ULL);
x86_l_fca:
	/* 0xfca: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_fd0:
	/* 0xfd0: lea    eax,[rdx+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_fd6:
	/* 0xfd6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fdb:
	/* 0xfdb: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_fe1:
	/* 0xfe1: mov    BYTE PTR [rsi+0xb],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_fe4:
	/* 0xfe4: cmp    rdx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 8ULL);
x86_l_fe8:
	/* 0xfe8: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_fee:
	/* 0xfee: lea    eax,[rdx+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_ff4:
	/* 0xff4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ff9:
	/* 0xff9: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_fff:
	/* 0xfff: mov    BYTE PTR [rsi+0xc],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1002:
	/* 0x1002: cmp    rdx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 9ULL);
x86_l_1006:
	/* 0x1006: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_100c:
	/* 0x100c: lea    eax,[rdx+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_1012:
	/* 0x1012: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1017:
	/* 0x1017: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_101d:
	/* 0x101d: mov    BYTE PTR [rsi+0xd],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_1020:
	/* 0x1020: cmp    rdx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 10ULL);
x86_l_1024:
	/* 0x1024: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_102a:
	/* 0x102a: lea    eax,[rdx+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_1030:
	/* 0x1030: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1035:
	/* 0x1035: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_103b:
	/* 0x103b: mov    BYTE PTR [rsi+0xe],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_103e:
	/* 0x103e: cmp    rdx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 11ULL);
x86_l_1042:
	/* 0x1042: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1048:
	/* 0x1048: lea    eax,[rdx+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_104e:
	/* 0x104e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1053:
	/* 0x1053: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1059:
	/* 0x1059: mov    BYTE PTR [rsi+0xf],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_105c:
	/* 0x105c: cmp    rdx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 12ULL);
x86_l_1060:
	/* 0x1060: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1066:
	/* 0x1066: lea    eax,[rdx+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_106c:
	/* 0x106c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1071:
	/* 0x1071: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1077:
	/* 0x1077: mov    BYTE PTR [rsi+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_107a:
	/* 0x107a: cmp    rdx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 13ULL);
x86_l_107e:
	/* 0x107e: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1084:
	/* 0x1084: lea    eax,[rdx+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_108a:
	/* 0x108a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_108f:
	/* 0x108f: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1095:
	/* 0x1095: mov    BYTE PTR [rsi+0x11],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_1098:
	/* 0x1098: cmp    rdx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 14ULL);
x86_l_109c:
	/* 0x109c: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_10a2:
	/* 0x10a2: lea    eax,[rdx+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_10a8:
	/* 0x10a8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10ad:
	/* 0x10ad: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_10b3:
	/* 0x10b3: mov    BYTE PTR [rsi+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_10b6:
	/* 0x10b6: cmp    rdx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 15ULL);
x86_l_10ba:
	/* 0x10ba: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_10c0:
	/* 0x10c0: lea    eax,[rdx+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_10c6:
	/* 0x10c6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10cb:
	/* 0x10cb: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_10d1:
	/* 0x10d1: mov    BYTE PTR [rsi+0x13],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_10d4:
	/* 0x10d4: cmp    rdx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 16ULL);
x86_l_10d8:
	/* 0x10d8: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_10de:
	/* 0x10de: lea    eax,[rdx+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_10e4:
	/* 0x10e4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10e9:
	/* 0x10e9: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_10ef:
	/* 0x10ef: mov    BYTE PTR [rsi+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_10f2:
	/* 0x10f2: cmp    rdx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 17ULL);
x86_l_10f6:
	/* 0x10f6: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_10fc:
	/* 0x10fc: lea    eax,[rdx+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_1102:
	/* 0x1102: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1107:
	/* 0x1107: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_110d:
	/* 0x110d: mov    BYTE PTR [rsi+0x15],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_1110:
	/* 0x1110: cmp    rdx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18ULL);
x86_l_1114:
	/* 0x1114: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_111a:
	/* 0x111a: lea    eax,[rdx+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_1120:
	/* 0x1120: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1125:
	/* 0x1125: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_112b:
	/* 0x112b: mov    BYTE PTR [rsi+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_112e:
	/* 0x112e: cmp    rdx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 19ULL);
x86_l_1132:
	/* 0x1132: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1138:
	/* 0x1138: lea    eax,[rdx+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_113e:
	/* 0x113e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1143:
	/* 0x1143: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1149:
	/* 0x1149: mov    BYTE PTR [rsi+0x17],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_114c:
	/* 0x114c: cmp    rdx,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 20ULL);
x86_l_1150:
	/* 0x1150: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1156:
	/* 0x1156: lea    eax,[rdx+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_115c:
	/* 0x115c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1161:
	/* 0x1161: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1167:
	/* 0x1167: mov    BYTE PTR [rsi+0x18],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_116a:
	/* 0x116a: cmp    rdx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 21ULL);
x86_l_116e:
	/* 0x116e: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1174:
	/* 0x1174: lea    eax,[rdx+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_117a:
	/* 0x117a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_117f:
	/* 0x117f: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1185:
	/* 0x1185: mov    BYTE PTR [rsi+0x19],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_1188:
	/* 0x1188: cmp    rdx,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 22ULL);
x86_l_118c:
	/* 0x118c: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1192:
	/* 0x1192: lea    eax,[rdx+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_1198:
	/* 0x1198: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_119d:
	/* 0x119d: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_11a3:
	/* 0x11a3: mov    BYTE PTR [rsi+0x1a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_11a6:
	/* 0x11a6: cmp    rdx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 23ULL);
x86_l_11aa:
	/* 0x11aa: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_11b0:
	/* 0x11b0: lea    eax,[rdx+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_11b6:
	/* 0x11b6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11bb:
	/* 0x11bb: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_11c1:
	/* 0x11c1: mov    BYTE PTR [rsi+0x1b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_11c4:
	/* 0x11c4: cmp    rdx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 24ULL);
x86_l_11c8:
	/* 0x11c8: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_11ce:
	/* 0x11ce: lea    eax,[rdx+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_11d4:
	/* 0x11d4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11d9:
	/* 0x11d9: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_11df:
	/* 0x11df: mov    BYTE PTR [rsi+0x1c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_11e2:
	/* 0x11e2: cmp    rdx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 25ULL);
x86_l_11e6:
	/* 0x11e6: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_11ec:
	/* 0x11ec: lea    eax,[rdx+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_11f2:
	/* 0x11f2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11f7:
	/* 0x11f7: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_11fd:
	/* 0x11fd: mov    BYTE PTR [rsi+0x1d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_1200:
	/* 0x1200: cmp    rdx,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 26ULL);
x86_l_1204:
	/* 0x1204: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_120a:
	/* 0x120a: lea    eax,[rdx+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_1210:
	/* 0x1210: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1215:
	/* 0x1215: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_121b:
	/* 0x121b: mov    BYTE PTR [rsi+0x1e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_121e:
	/* 0x121e: cmp    rdx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 27ULL);
x86_l_1222:
	/* 0x1222: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1228:
	/* 0x1228: lea    eax,[rdx+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_122e:
	/* 0x122e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1233:
	/* 0x1233: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1239:
	/* 0x1239: mov    BYTE PTR [rsi+0x1f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_123c:
	/* 0x123c: cmp    rdx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 28ULL);
x86_l_1240:
	/* 0x1240: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1246:
	/* 0x1246: lea    eax,[rdx+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_124c:
	/* 0x124c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1251:
	/* 0x1251: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1257:
	/* 0x1257: mov    BYTE PTR [rsi+0x20],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_125a:
	/* 0x125a: cmp    rdx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 29ULL);
x86_l_125e:
	/* 0x125e: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1264:
	/* 0x1264: lea    eax,[rdx+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_126a:
	/* 0x126a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_126f:
	/* 0x126f: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1275:
	/* 0x1275: mov    BYTE PTR [rsi+0x21],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_1278:
	/* 0x1278: cmp    rdx,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 30ULL);
x86_l_127c:
	/* 0x127c: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1282:
	/* 0x1282: lea    eax,[rdx+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_1288:
	/* 0x1288: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_128d:
	/* 0x128d: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1293:
	/* 0x1293: mov    BYTE PTR [rsi+0x22],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_1296:
	/* 0x1296: cmp    rdx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 31ULL);
x86_l_129a:
	/* 0x129a: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_12a0:
	/* 0x12a0: lea    eax,[rdx+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_12a6:
	/* 0x12a6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12ab:
	/* 0x12ab: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_12b1:
	/* 0x12b1: mov    BYTE PTR [rsi+0x23],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_12b4:
	/* 0x12b4: cmp    rdx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 32ULL);
x86_l_12b8:
	/* 0x12b8: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_12be:
	/* 0x12be: lea    eax,[rdx+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_12c4:
	/* 0x12c4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12c9:
	/* 0x12c9: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_12cf:
	/* 0x12cf: mov    BYTE PTR [rsi+0x24],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_12d2:
	/* 0x12d2: cmp    rdx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 33ULL);
x86_l_12d6:
	/* 0x12d6: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_12dc:
	/* 0x12dc: lea    eax,[rdx+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_12e2:
	/* 0x12e2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12e7:
	/* 0x12e7: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_12ed:
	/* 0x12ed: mov    BYTE PTR [rsi+0x25],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_12f0:
	/* 0x12f0: cmp    rdx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 34ULL);
x86_l_12f4:
	/* 0x12f4: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_12fa:
	/* 0x12fa: lea    eax,[rdx+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_1300:
	/* 0x1300: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1305:
	/* 0x1305: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_130b:
	/* 0x130b: mov    BYTE PTR [rsi+0x26],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_130e:
	/* 0x130e: cmp    rdx,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 35ULL);
x86_l_1312:
	/* 0x1312: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1318:
	/* 0x1318: lea    eax,[rdx+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_131e:
	/* 0x131e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1323:
	/* 0x1323: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1329:
	/* 0x1329: mov    BYTE PTR [rsi+0x27],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_132c:
	/* 0x132c: cmp    rdx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 36ULL);
x86_l_1330:
	/* 0x1330: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1336:
	/* 0x1336: lea    eax,[rdx+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_133c:
	/* 0x133c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1341:
	/* 0x1341: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1347:
	/* 0x1347: mov    BYTE PTR [rsi+0x28],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_134a:
	/* 0x134a: cmp    rdx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 37ULL);
x86_l_134e:
	/* 0x134e: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1354:
	/* 0x1354: lea    eax,[rdx+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_135a:
	/* 0x135a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_135f:
	/* 0x135f: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1365:
	/* 0x1365: mov    BYTE PTR [rsi+0x29],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_1368:
	/* 0x1368: cmp    rdx,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 38ULL);
x86_l_136c:
	/* 0x136c: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1372:
	/* 0x1372: lea    eax,[rdx+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_1378:
	/* 0x1378: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_137d:
	/* 0x137d: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1383:
	/* 0x1383: mov    BYTE PTR [rsi+0x2a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1386:
	/* 0x1386: cmp    rdx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 39ULL);
x86_l_138a:
	/* 0x138a: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1390:
	/* 0x1390: lea    eax,[rdx+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_1396:
	/* 0x1396: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_139b:
	/* 0x139b: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_13a1:
	/* 0x13a1: mov    BYTE PTR [rsi+0x2b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_13a4:
	/* 0x13a4: cmp    rdx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 40ULL);
x86_l_13a8:
	/* 0x13a8: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_13ae:
	/* 0x13ae: lea    eax,[rdx+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_13b4:
	/* 0x13b4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13b9:
	/* 0x13b9: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_13bf:
	/* 0x13bf: mov    BYTE PTR [rsi+0x2c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_13c2:
	/* 0x13c2: cmp    rdx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 41ULL);
x86_l_13c6:
	/* 0x13c6: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_13cc:
	/* 0x13cc: lea    eax,[rdx+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_13d2:
	/* 0x13d2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13d7:
	/* 0x13d7: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_13dd:
	/* 0x13dd: mov    BYTE PTR [rsi+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_13e0:
	/* 0x13e0: cmp    rdx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 42ULL);
x86_l_13e4:
	/* 0x13e4: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_13ea:
	/* 0x13ea: lea    eax,[rdx+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_13f0:
	/* 0x13f0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13f5:
	/* 0x13f5: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_13fb:
	/* 0x13fb: mov    BYTE PTR [rsi+0x2e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_13fe:
	/* 0x13fe: cmp    rdx,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 43ULL);
x86_l_1402:
	/* 0x1402: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1408:
	/* 0x1408: lea    eax,[rdx+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_140e:
	/* 0x140e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1413:
	/* 0x1413: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1419:
	/* 0x1419: mov    BYTE PTR [rsi+0x2f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_141c:
	/* 0x141c: cmp    rdx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 44ULL);
x86_l_1420:
	/* 0x1420: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1426:
	/* 0x1426: lea    eax,[rdx+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_142c:
	/* 0x142c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1431:
	/* 0x1431: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1437:
	/* 0x1437: mov    BYTE PTR [rsi+0x30],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_143a:
	/* 0x143a: cmp    rdx,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 45ULL);
x86_l_143e:
	/* 0x143e: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1444:
	/* 0x1444: lea    eax,[rdx+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_144a:
	/* 0x144a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_144f:
	/* 0x144f: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1455:
	/* 0x1455: mov    BYTE PTR [rsi+0x31],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_1458:
	/* 0x1458: cmp    rdx,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 46ULL);
x86_l_145c:
	/* 0x145c: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1462:
	/* 0x1462: lea    eax,[rdx+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_1468:
	/* 0x1468: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_146d:
	/* 0x146d: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1473:
	/* 0x1473: mov    BYTE PTR [rsi+0x32],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_1476:
	/* 0x1476: cmp    rdx,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 47ULL);
x86_l_147a:
	/* 0x147a: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1480:
	/* 0x1480: lea    eax,[rdx+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_1486:
	/* 0x1486: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_148b:
	/* 0x148b: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1491:
	/* 0x1491: mov    BYTE PTR [rsi+0x33],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_1494:
	/* 0x1494: cmp    rdx,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 48ULL);
x86_l_1498:
	/* 0x1498: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_149e:
	/* 0x149e: lea    eax,[rdx+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_14a4:
	/* 0x14a4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14a9:
	/* 0x14a9: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_14af:
	/* 0x14af: mov    BYTE PTR [rsi+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_14b2:
	/* 0x14b2: cmp    rdx,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 49ULL);
x86_l_14b6:
	/* 0x14b6: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_14bc:
	/* 0x14bc: lea    eax,[rdx+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_14c2:
	/* 0x14c2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14c7:
	/* 0x14c7: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_14cd:
	/* 0x14cd: mov    BYTE PTR [rsi+0x35],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_14d0:
	/* 0x14d0: cmp    rdx,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 50ULL);
x86_l_14d4:
	/* 0x14d4: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_14da:
	/* 0x14da: lea    eax,[rdx+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_14e0:
	/* 0x14e0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14e5:
	/* 0x14e5: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_14eb:
	/* 0x14eb: mov    BYTE PTR [rsi+0x36],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_14ee:
	/* 0x14ee: cmp    rdx,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 51ULL);
x86_l_14f2:
	/* 0x14f2: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_14f8:
	/* 0x14f8: lea    eax,[rdx+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_14fe:
	/* 0x14fe: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1503:
	/* 0x1503: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1509:
	/* 0x1509: mov    BYTE PTR [rsi+0x37],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_150c:
	/* 0x150c: cmp    rdx,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 52ULL);
x86_l_1510:
	/* 0x1510: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1516:
	/* 0x1516: lea    eax,[rdx+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_151c:
	/* 0x151c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1521:
	/* 0x1521: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1527:
	/* 0x1527: mov    BYTE PTR [rsi+0x38],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_152a:
	/* 0x152a: cmp    rdx,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 53ULL);
x86_l_152e:
	/* 0x152e: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1534:
	/* 0x1534: lea    eax,[rdx+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_153a:
	/* 0x153a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_153f:
	/* 0x153f: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1545:
	/* 0x1545: mov    BYTE PTR [rsi+0x39],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_1548:
	/* 0x1548: cmp    rdx,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 54ULL);
x86_l_154c:
	/* 0x154c: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
x86_l_1552:
	/* 0x1552: lea    eax,[rdx+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_1558:
	/* 0x1558: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_155d:
	/* 0x155d: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1563:
	/* 0x1563: mov    BYTE PTR [rsi+0x3a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_1566:
	/* 0x1566: cmp    rdx,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 55ULL);
x86_l_156a:
	/* 0x156a: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6633ULL;
	}
	return 5488ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_generic_retkprobe_filter_arg_2_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5488ULL: goto x86_l_1570;
	case 5494ULL: goto x86_l_1576;
	case 5499ULL: goto x86_l_157b;
	case 5505ULL: goto x86_l_1581;
	case 5508ULL: goto x86_l_1584;
	case 5512ULL: goto x86_l_1588;
	case 5518ULL: goto x86_l_158e;
	case 5524ULL: goto x86_l_1594;
	case 5529ULL: goto x86_l_1599;
	case 5535ULL: goto x86_l_159f;
	case 5538ULL: goto x86_l_15a2;
	case 5542ULL: goto x86_l_15a6;
	case 5548ULL: goto x86_l_15ac;
	case 5554ULL: goto x86_l_15b2;
	case 5559ULL: goto x86_l_15b7;
	case 5565ULL: goto x86_l_15bd;
	case 5568ULL: goto x86_l_15c0;
	case 5572ULL: goto x86_l_15c4;
	case 5578ULL: goto x86_l_15ca;
	case 5584ULL: goto x86_l_15d0;
	case 5589ULL: goto x86_l_15d5;
	case 5595ULL: goto x86_l_15db;
	case 5598ULL: goto x86_l_15de;
	case 5602ULL: goto x86_l_15e2;
	case 5608ULL: goto x86_l_15e8;
	case 5614ULL: goto x86_l_15ee;
	case 5619ULL: goto x86_l_15f3;
	case 5625ULL: goto x86_l_15f9;
	case 5628ULL: goto x86_l_15fc;
	case 5632ULL: goto x86_l_1600;
	case 5638ULL: goto x86_l_1606;
	case 5644ULL: goto x86_l_160c;
	case 5649ULL: goto x86_l_1611;
	case 5655ULL: goto x86_l_1617;
	case 5658ULL: goto x86_l_161a;
	case 5662ULL: goto x86_l_161e;
	case 5668ULL: goto x86_l_1624;
	case 5674ULL: goto x86_l_162a;
	case 5679ULL: goto x86_l_162f;
	case 5685ULL: goto x86_l_1635;
	case 5688ULL: goto x86_l_1638;
	case 5692ULL: goto x86_l_163c;
	case 5698ULL: goto x86_l_1642;
	case 5704ULL: goto x86_l_1648;
	case 5709ULL: goto x86_l_164d;
	case 5715ULL: goto x86_l_1653;
	case 5718ULL: goto x86_l_1656;
	case 5722ULL: goto x86_l_165a;
	case 5728ULL: goto x86_l_1660;
	case 5734ULL: goto x86_l_1666;
	case 5739ULL: goto x86_l_166b;
	case 5745ULL: goto x86_l_1671;
	case 5748ULL: goto x86_l_1674;
	case 5752ULL: goto x86_l_1678;
	case 5758ULL: goto x86_l_167e;
	case 5764ULL: goto x86_l_1684;
	case 5769ULL: goto x86_l_1689;
	case 5775ULL: goto x86_l_168f;
	case 5778ULL: goto x86_l_1692;
	case 5782ULL: goto x86_l_1696;
	case 5788ULL: goto x86_l_169c;
	case 5794ULL: goto x86_l_16a2;
	case 5799ULL: goto x86_l_16a7;
	case 5805ULL: goto x86_l_16ad;
	case 5808ULL: goto x86_l_16b0;
	case 5812ULL: goto x86_l_16b4;
	case 5818ULL: goto x86_l_16ba;
	case 5824ULL: goto x86_l_16c0;
	case 5829ULL: goto x86_l_16c5;
	case 5835ULL: goto x86_l_16cb;
	case 5838ULL: goto x86_l_16ce;
	case 5842ULL: goto x86_l_16d2;
	case 5848ULL: goto x86_l_16d8;
	case 5854ULL: goto x86_l_16de;
	case 5859ULL: goto x86_l_16e3;
	case 5865ULL: goto x86_l_16e9;
	case 5868ULL: goto x86_l_16ec;
	case 5872ULL: goto x86_l_16f0;
	case 5878ULL: goto x86_l_16f6;
	case 5884ULL: goto x86_l_16fc;
	case 5889ULL: goto x86_l_1701;
	case 5895ULL: goto x86_l_1707;
	case 5898ULL: goto x86_l_170a;
	case 5902ULL: goto x86_l_170e;
	case 5908ULL: goto x86_l_1714;
	case 5914ULL: goto x86_l_171a;
	case 5919ULL: goto x86_l_171f;
	case 5925ULL: goto x86_l_1725;
	case 5928ULL: goto x86_l_1728;
	case 5932ULL: goto x86_l_172c;
	case 5938ULL: goto x86_l_1732;
	case 5944ULL: goto x86_l_1738;
	case 5949ULL: goto x86_l_173d;
	case 5955ULL: goto x86_l_1743;
	case 5958ULL: goto x86_l_1746;
	case 5962ULL: goto x86_l_174a;
	case 5968ULL: goto x86_l_1750;
	case 5974ULL: goto x86_l_1756;
	case 5979ULL: goto x86_l_175b;
	case 5985ULL: goto x86_l_1761;
	case 5988ULL: goto x86_l_1764;
	case 5992ULL: goto x86_l_1768;
	case 5998ULL: goto x86_l_176e;
	case 6004ULL: goto x86_l_1774;
	case 6009ULL: goto x86_l_1779;
	case 6015ULL: goto x86_l_177f;
	case 6018ULL: goto x86_l_1782;
	case 6022ULL: goto x86_l_1786;
	case 6028ULL: goto x86_l_178c;
	case 6034ULL: goto x86_l_1792;
	case 6039ULL: goto x86_l_1797;
	case 6045ULL: goto x86_l_179d;
	case 6048ULL: goto x86_l_17a0;
	case 6052ULL: goto x86_l_17a4;
	case 6058ULL: goto x86_l_17aa;
	case 6064ULL: goto x86_l_17b0;
	case 6069ULL: goto x86_l_17b5;
	case 6075ULL: goto x86_l_17bb;
	case 6078ULL: goto x86_l_17be;
	case 6082ULL: goto x86_l_17c2;
	case 6088ULL: goto x86_l_17c8;
	case 6094ULL: goto x86_l_17ce;
	case 6099ULL: goto x86_l_17d3;
	case 6105ULL: goto x86_l_17d9;
	case 6108ULL: goto x86_l_17dc;
	case 6112ULL: goto x86_l_17e0;
	case 6118ULL: goto x86_l_17e6;
	case 6124ULL: goto x86_l_17ec;
	case 6129ULL: goto x86_l_17f1;
	case 6135ULL: goto x86_l_17f7;
	case 6138ULL: goto x86_l_17fa;
	case 6142ULL: goto x86_l_17fe;
	case 6148ULL: goto x86_l_1804;
	case 6154ULL: goto x86_l_180a;
	case 6159ULL: goto x86_l_180f;
	case 6165ULL: goto x86_l_1815;
	case 6168ULL: goto x86_l_1818;
	case 6172ULL: goto x86_l_181c;
	case 6178ULL: goto x86_l_1822;
	case 6184ULL: goto x86_l_1828;
	case 6189ULL: goto x86_l_182d;
	case 6195ULL: goto x86_l_1833;
	case 6198ULL: goto x86_l_1836;
	case 6202ULL: goto x86_l_183a;
	case 6208ULL: goto x86_l_1840;
	case 6214ULL: goto x86_l_1846;
	case 6219ULL: goto x86_l_184b;
	case 6225ULL: goto x86_l_1851;
	case 6228ULL: goto x86_l_1854;
	case 6232ULL: goto x86_l_1858;
	case 6238ULL: goto x86_l_185e;
	case 6244ULL: goto x86_l_1864;
	case 6249ULL: goto x86_l_1869;
	case 6255ULL: goto x86_l_186f;
	case 6258ULL: goto x86_l_1872;
	case 6262ULL: goto x86_l_1876;
	case 6268ULL: goto x86_l_187c;
	case 6274ULL: goto x86_l_1882;
	case 6279ULL: goto x86_l_1887;
	case 6285ULL: goto x86_l_188d;
	case 6288ULL: goto x86_l_1890;
	case 6292ULL: goto x86_l_1894;
	case 6298ULL: goto x86_l_189a;
	case 6304ULL: goto x86_l_18a0;
	case 6309ULL: goto x86_l_18a5;
	case 6315ULL: goto x86_l_18ab;
	case 6318ULL: goto x86_l_18ae;
	case 6322ULL: goto x86_l_18b2;
	case 6328ULL: goto x86_l_18b8;
	case 6334ULL: goto x86_l_18be;
	case 6339ULL: goto x86_l_18c3;
	case 6345ULL: goto x86_l_18c9;
	case 6348ULL: goto x86_l_18cc;
	case 6352ULL: goto x86_l_18d0;
	case 6358ULL: goto x86_l_18d6;
	case 6364ULL: goto x86_l_18dc;
	case 6369ULL: goto x86_l_18e1;
	case 6375ULL: goto x86_l_18e7;
	case 6378ULL: goto x86_l_18ea;
	case 6382ULL: goto x86_l_18ee;
	case 6388ULL: goto x86_l_18f4;
	case 6394ULL: goto x86_l_18fa;
	case 6399ULL: goto x86_l_18ff;
	case 6405ULL: goto x86_l_1905;
	case 6408ULL: goto x86_l_1908;
	case 6412ULL: goto x86_l_190c;
	case 6418ULL: goto x86_l_1912;
	case 6424ULL: goto x86_l_1918;
	case 6429ULL: goto x86_l_191d;
	case 6435ULL: goto x86_l_1923;
	case 6438ULL: goto x86_l_1926;
	case 6442ULL: goto x86_l_192a;
	case 6448ULL: goto x86_l_1930;
	case 6454ULL: goto x86_l_1936;
	case 6459ULL: goto x86_l_193b;
	case 6465ULL: goto x86_l_1941;
	case 6468ULL: goto x86_l_1944;
	case 6472ULL: goto x86_l_1948;
	case 6478ULL: goto x86_l_194e;
	case 6484ULL: goto x86_l_1954;
	case 6489ULL: goto x86_l_1959;
	case 6495ULL: goto x86_l_195f;
	case 6498ULL: goto x86_l_1962;
	case 6502ULL: goto x86_l_1966;
	case 6508ULL: goto x86_l_196c;
	case 6514ULL: goto x86_l_1972;
	case 6519ULL: goto x86_l_1977;
	case 6525ULL: goto x86_l_197d;
	case 6528ULL: goto x86_l_1980;
	case 6532ULL: goto x86_l_1984;
	case 6534ULL: goto x86_l_1986;
	case 6540ULL: goto x86_l_198c;
	case 6545ULL: goto x86_l_1991;
	case 6551ULL: goto x86_l_1997;
	case 6554ULL: goto x86_l_199a;
	case 6558ULL: goto x86_l_199e;
	case 6560ULL: goto x86_l_19a0;
	case 6566ULL: goto x86_l_19a6;
	case 6571ULL: goto x86_l_19ab;
	case 6577ULL: goto x86_l_19b1;
	case 6580ULL: goto x86_l_19b4;
	case 6584ULL: goto x86_l_19b8;
	case 6586ULL: goto x86_l_19ba;
	case 6592ULL: goto x86_l_19c0;
	case 6597ULL: goto x86_l_19c5;
	case 6603ULL: goto x86_l_19cb;
	case 6606ULL: goto x86_l_19ce;
	case 6610ULL: goto x86_l_19d2;
	case 6612ULL: goto x86_l_19d4;
	case 6618ULL: goto x86_l_19da;
	case 6624ULL: goto x86_l_19e0;
	case 6630ULL: goto x86_l_19e6;
	case 6633ULL: goto x86_l_19e9;
	case 6638ULL: goto x86_l_19ee;
	case 6643ULL: goto x86_l_19f3;
	case 6648ULL: goto x86_l_19f8;
	case 6653ULL: goto x86_l_19fd;
	case 6657ULL: goto x86_l_1a01;
	case 6660ULL: goto x86_l_1a04;
	case 6664ULL: goto x86_l_1a08;
	case 6672ULL: goto x86_l_1a10;
	case 6679ULL: goto x86_l_1a17;
	case 6684ULL: goto x86_l_1a1c;
	case 6689ULL: goto x86_l_1a21;
	case 6691ULL: goto x86_l_1a23;
	case 6694ULL: goto x86_l_1a26;
	case 6697ULL: goto x86_l_1a29;
	case 6700ULL: goto x86_l_1a2c;
	case 6706ULL: goto x86_l_1a32;
	case 6709ULL: goto x86_l_1a35;
	case 6715ULL: goto x86_l_1a3b;
	case 6720ULL: goto x86_l_1a40;
	case 6727ULL: goto x86_l_1a47;
	case 6732ULL: goto x86_l_1a4c;
	case 6737ULL: goto x86_l_1a51;
	case 6739ULL: goto x86_l_1a53;
	case 6742ULL: goto x86_l_1a56;
	case 6748ULL: goto x86_l_1a5c;
	case 6755ULL: goto x86_l_1a63;
	case 6760ULL: goto x86_l_1a68;
	case 6764ULL: goto x86_l_1a6c;
	case 6771ULL: goto x86_l_1a73;
	case 6773ULL: goto x86_l_1a75;
	case 6776ULL: goto x86_l_1a78;
	case 6780ULL: goto x86_l_1a7c;
	case 6783ULL: goto x86_l_1a7f;
	case 6788ULL: goto x86_l_1a84;
	case 6793ULL: goto x86_l_1a89;
	case 6795ULL: goto x86_l_1a8b;
	case 6800ULL: goto x86_l_1a90;
	case 6805ULL: goto x86_l_1a95;
	case 6808ULL: goto x86_l_1a98;
	case 6813ULL: goto x86_l_1a9d;
	case 6821ULL: goto x86_l_1aa5;
	case 6828ULL: goto x86_l_1aac;
	case 6834ULL: goto x86_l_1ab2;
	case 6838ULL: goto x86_l_1ab6;
	case 6844ULL: goto x86_l_1abc;
	case 6847ULL: goto x86_l_1abf;
	case 6850ULL: goto x86_l_1ac2;
	case 6853ULL: goto x86_l_1ac5;
	case 6856ULL: goto x86_l_1ac8;
	case 6858ULL: goto x86_l_1aca;
	case 6862ULL: goto x86_l_1ace;
	case 6868ULL: goto x86_l_1ad4;
	case 6870ULL: goto x86_l_1ad6;
	case 6876ULL: goto x86_l_1adc;
	case 6879ULL: goto x86_l_1adf;
	case 6884ULL: goto x86_l_1ae4;
	case 6888ULL: goto x86_l_1ae8;
	case 6893ULL: goto x86_l_1aed;
	case 6898ULL: goto x86_l_1af2;
	case 6903ULL: goto x86_l_1af7;
	case 6907ULL: goto x86_l_1afb;
	case 6912ULL: goto x86_l_1b00;
	case 6916ULL: goto x86_l_1b04;
	case 6921ULL: goto x86_l_1b09;
	case 6926ULL: goto x86_l_1b0e;
	case 6928ULL: goto x86_l_1b10;
	case 6931ULL: goto x86_l_1b13;
	case 6934ULL: goto x86_l_1b16;
	case 6937ULL: goto x86_l_1b19;
	case 6939ULL: goto x86_l_1b1b;
	case 6942ULL: goto x86_l_1b1e;
	case 6944ULL: goto x86_l_1b20;
	case 6947ULL: goto x86_l_1b23;
	case 6950ULL: goto x86_l_1b26;
	case 6956ULL: goto x86_l_1b2c;
	case 6959ULL: goto x86_l_1b2f;
	case 6962ULL: goto x86_l_1b32;
	case 6968ULL: goto x86_l_1b38;
	case 6973ULL: goto x86_l_1b3d;
	case 6976ULL: goto x86_l_1b40;
	case 6978ULL: goto x86_l_1b42;
	case 6981ULL: goto x86_l_1b45;
	case 6987ULL: goto x86_l_1b4b;
	case 6990ULL: goto x86_l_1b4e;
	case 6996ULL: goto x86_l_1b54;
	case 6999ULL: goto x86_l_1b57;
	case 7005ULL: goto x86_l_1b5d;
	case 7010ULL: goto x86_l_1b62;
	case 7015ULL: goto x86_l_1b67;
	case 7018ULL: goto x86_l_1b6a;
	case 7024ULL: goto x86_l_1b70;
	case 7027ULL: goto x86_l_1b73;
	case 7033ULL: goto x86_l_1b79;
	case 7036ULL: goto x86_l_1b7c;
	case 7042ULL: goto x86_l_1b82;
	case 7047ULL: goto x86_l_1b87;
	case 7050ULL: goto x86_l_1b8a;
	case 7053ULL: goto x86_l_1b8d;
	case 7059ULL: goto x86_l_1b93;
	case 7067ULL: goto x86_l_1b9b;
	case 7074ULL: goto x86_l_1ba2;
	case 7080ULL: goto x86_l_1ba8;
	case 7083ULL: goto x86_l_1bab;
	case 7088ULL: goto x86_l_1bb0;
	case 7091ULL: goto x86_l_1bb3;
	case 7097ULL: goto x86_l_1bb9;
	case 7100ULL: goto x86_l_1bbc;
	case 7106ULL: goto x86_l_1bc2;
	case 7109ULL: goto x86_l_1bc5;
	case 7115ULL: goto x86_l_1bcb;
	case 7120ULL: goto x86_l_1bd0;
	case 7125ULL: goto x86_l_1bd5;
	case 7129ULL: goto x86_l_1bd9;
	case 7132ULL: goto x86_l_1bdc;
	case 7136ULL: goto x86_l_1be0;
	case 7144ULL: goto x86_l_1be8;
	case 7151ULL: goto x86_l_1bef;
	case 7156ULL: goto x86_l_1bf4;
	case 7161ULL: goto x86_l_1bf9;
	case 7163ULL: goto x86_l_1bfb;
	case 7166ULL: goto x86_l_1bfe;
	case 7169ULL: goto x86_l_1c01;
	case 7172ULL: goto x86_l_1c04;
	case 7178ULL: goto x86_l_1c0a;
	case 7183ULL: goto x86_l_1c0f;
	case 7186ULL: goto x86_l_1c12;
	case 7192ULL: goto x86_l_1c18;
	case 7199ULL: goto x86_l_1c1f;
	case 7204ULL: goto x86_l_1c24;
	case 7209ULL: goto x86_l_1c29;
	case 7211ULL: goto x86_l_1c2b;
	case 7214ULL: goto x86_l_1c2e;
	case 7220ULL: goto x86_l_1c34;
	case 7223ULL: goto x86_l_1c37;
	case 7228ULL: goto x86_l_1c3c;
	case 7232ULL: goto x86_l_1c40;
	case 7236ULL: goto x86_l_1c44;
	case 7241ULL: goto x86_l_1c49;
	case 7245ULL: goto x86_l_1c4d;
	case 7248ULL: goto x86_l_1c50;
	case 7250ULL: goto x86_l_1c52;
	case 7254ULL: goto x86_l_1c56;
	case 7259ULL: goto x86_l_1c5b;
	case 7263ULL: goto x86_l_1c5f;
	case 7266ULL: goto x86_l_1c62;
	case 7270ULL: goto x86_l_1c66;
	case 7276ULL: goto x86_l_1c6c;
	case 7283ULL: goto x86_l_1c73;
	case 7288ULL: goto x86_l_1c78;
	case 7292ULL: goto x86_l_1c7c;
	case 7295ULL: goto x86_l_1c7f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1570:
	/* 0x1570: lea    eax,[rdx+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_1576:
	/* 0x1576: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_157b:
	/* 0x157b: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1581:
	/* 0x1581: mov    BYTE PTR [rsi+0x3b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_1584:
	/* 0x1584: cmp    rdx,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 56ULL);
x86_l_1588:
	/* 0x1588: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_158e:
	/* 0x158e: lea    eax,[rdx+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_1594:
	/* 0x1594: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1599:
	/* 0x1599: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_159f:
	/* 0x159f: mov    BYTE PTR [rsi+0x3c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_15a2:
	/* 0x15a2: cmp    rdx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 57ULL);
x86_l_15a6:
	/* 0x15a6: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_15ac:
	/* 0x15ac: lea    eax,[rdx+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_15b2:
	/* 0x15b2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15b7:
	/* 0x15b7: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_15bd:
	/* 0x15bd: mov    BYTE PTR [rsi+0x3d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_15c0:
	/* 0x15c0: cmp    rdx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 58ULL);
x86_l_15c4:
	/* 0x15c4: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_15ca:
	/* 0x15ca: lea    eax,[rdx+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_15d0:
	/* 0x15d0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15d5:
	/* 0x15d5: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_15db:
	/* 0x15db: mov    BYTE PTR [rsi+0x3e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_15de:
	/* 0x15de: cmp    rdx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 59ULL);
x86_l_15e2:
	/* 0x15e2: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_15e8:
	/* 0x15e8: lea    eax,[rdx+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_15ee:
	/* 0x15ee: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15f3:
	/* 0x15f3: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_15f9:
	/* 0x15f9: mov    BYTE PTR [rsi+0x3f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_15fc:
	/* 0x15fc: cmp    rdx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 60ULL);
x86_l_1600:
	/* 0x1600: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_1606:
	/* 0x1606: lea    eax,[rdx+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_160c:
	/* 0x160c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1611:
	/* 0x1611: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1617:
	/* 0x1617: mov    BYTE PTR [rsi+0x40],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_161a:
	/* 0x161a: cmp    rdx,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 61ULL);
x86_l_161e:
	/* 0x161e: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_1624:
	/* 0x1624: lea    eax,[rdx+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_162a:
	/* 0x162a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_162f:
	/* 0x162f: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1635:
	/* 0x1635: mov    BYTE PTR [rsi+0x41],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_1638:
	/* 0x1638: cmp    rdx,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 62ULL);
x86_l_163c:
	/* 0x163c: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_1642:
	/* 0x1642: lea    eax,[rdx+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_1648:
	/* 0x1648: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_164d:
	/* 0x164d: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1653:
	/* 0x1653: mov    BYTE PTR [rsi+0x42],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_1656:
	/* 0x1656: cmp    rdx,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 63ULL);
x86_l_165a:
	/* 0x165a: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_1660:
	/* 0x1660: lea    eax,[rdx+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_1666:
	/* 0x1666: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_166b:
	/* 0x166b: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1671:
	/* 0x1671: mov    BYTE PTR [rsi+0x43],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_1674:
	/* 0x1674: cmp    rdx,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 64ULL);
x86_l_1678:
	/* 0x1678: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_167e:
	/* 0x167e: lea    eax,[rdx+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_1684:
	/* 0x1684: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1689:
	/* 0x1689: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_168f:
	/* 0x168f: mov    BYTE PTR [rsi+0x44],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1692:
	/* 0x1692: cmp    rdx,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 65ULL);
x86_l_1696:
	/* 0x1696: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_169c:
	/* 0x169c: lea    eax,[rdx+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_16a2:
	/* 0x16a2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16a7:
	/* 0x16a7: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_16ad:
	/* 0x16ad: mov    BYTE PTR [rsi+0x45],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_16b0:
	/* 0x16b0: cmp    rdx,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 66ULL);
x86_l_16b4:
	/* 0x16b4: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_16ba:
	/* 0x16ba: lea    eax,[rdx+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_16c0:
	/* 0x16c0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16c5:
	/* 0x16c5: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_16cb:
	/* 0x16cb: mov    BYTE PTR [rsi+0x46],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_16ce:
	/* 0x16ce: cmp    rdx,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 67ULL);
x86_l_16d2:
	/* 0x16d2: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_16d8:
	/* 0x16d8: lea    eax,[rdx+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_16de:
	/* 0x16de: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16e3:
	/* 0x16e3: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_16e9:
	/* 0x16e9: mov    BYTE PTR [rsi+0x47],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_16ec:
	/* 0x16ec: cmp    rdx,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 68ULL);
x86_l_16f0:
	/* 0x16f0: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_16f6:
	/* 0x16f6: lea    eax,[rdx+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_16fc:
	/* 0x16fc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1701:
	/* 0x1701: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1707:
	/* 0x1707: mov    BYTE PTR [rsi+0x48],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_170a:
	/* 0x170a: cmp    rdx,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 69ULL);
x86_l_170e:
	/* 0x170e: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_1714:
	/* 0x1714: lea    eax,[rdx+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_171a:
	/* 0x171a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_171f:
	/* 0x171f: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1725:
	/* 0x1725: mov    BYTE PTR [rsi+0x49],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_1728:
	/* 0x1728: cmp    rdx,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 70ULL);
x86_l_172c:
	/* 0x172c: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_1732:
	/* 0x1732: lea    eax,[rdx+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_1738:
	/* 0x1738: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_173d:
	/* 0x173d: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1743:
	/* 0x1743: mov    BYTE PTR [rsi+0x4a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_1746:
	/* 0x1746: cmp    rdx,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 71ULL);
x86_l_174a:
	/* 0x174a: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_1750:
	/* 0x1750: lea    eax,[rdx+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_1756:
	/* 0x1756: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_175b:
	/* 0x175b: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1761:
	/* 0x1761: mov    BYTE PTR [rsi+0x4b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_1764:
	/* 0x1764: cmp    rdx,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 72ULL);
x86_l_1768:
	/* 0x1768: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_176e:
	/* 0x176e: lea    eax,[rdx+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_1774:
	/* 0x1774: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1779:
	/* 0x1779: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_177f:
	/* 0x177f: mov    BYTE PTR [rsi+0x4c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1782:
	/* 0x1782: cmp    rdx,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 73ULL);
x86_l_1786:
	/* 0x1786: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_178c:
	/* 0x178c: lea    eax,[rdx+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_1792:
	/* 0x1792: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1797:
	/* 0x1797: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_179d:
	/* 0x179d: mov    BYTE PTR [rsi+0x4d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_17a0:
	/* 0x17a0: cmp    rdx,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 74ULL);
x86_l_17a4:
	/* 0x17a4: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_17aa:
	/* 0x17aa: lea    eax,[rdx+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_17b0:
	/* 0x17b0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17b5:
	/* 0x17b5: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_17bb:
	/* 0x17bb: mov    BYTE PTR [rsi+0x4e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_17be:
	/* 0x17be: cmp    rdx,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 75ULL);
x86_l_17c2:
	/* 0x17c2: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_17c8:
	/* 0x17c8: lea    eax,[rdx+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_17ce:
	/* 0x17ce: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17d3:
	/* 0x17d3: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_17d9:
	/* 0x17d9: mov    BYTE PTR [rsi+0x4f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_17dc:
	/* 0x17dc: cmp    rdx,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 76ULL);
x86_l_17e0:
	/* 0x17e0: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_17e6:
	/* 0x17e6: lea    eax,[rdx+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_17ec:
	/* 0x17ec: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17f1:
	/* 0x17f1: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_17f7:
	/* 0x17f7: mov    BYTE PTR [rsi+0x50],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_17fa:
	/* 0x17fa: cmp    rdx,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 77ULL);
x86_l_17fe:
	/* 0x17fe: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_1804:
	/* 0x1804: lea    eax,[rdx+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_180a:
	/* 0x180a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_180f:
	/* 0x180f: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1815:
	/* 0x1815: mov    BYTE PTR [rsi+0x51],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_1818:
	/* 0x1818: cmp    rdx,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 78ULL);
x86_l_181c:
	/* 0x181c: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_1822:
	/* 0x1822: lea    eax,[rdx+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_1828:
	/* 0x1828: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_182d:
	/* 0x182d: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1833:
	/* 0x1833: mov    BYTE PTR [rsi+0x52],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_1836:
	/* 0x1836: cmp    rdx,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 79ULL);
x86_l_183a:
	/* 0x183a: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_1840:
	/* 0x1840: lea    eax,[rdx+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_1846:
	/* 0x1846: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_184b:
	/* 0x184b: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1851:
	/* 0x1851: mov    BYTE PTR [rsi+0x53],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_1854:
	/* 0x1854: cmp    rdx,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 80ULL);
x86_l_1858:
	/* 0x1858: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_185e:
	/* 0x185e: lea    eax,[rdx+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_1864:
	/* 0x1864: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1869:
	/* 0x1869: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_186f:
	/* 0x186f: mov    BYTE PTR [rsi+0x54],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_1872:
	/* 0x1872: cmp    rdx,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 81ULL);
x86_l_1876:
	/* 0x1876: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_187c:
	/* 0x187c: lea    eax,[rdx+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_1882:
	/* 0x1882: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1887:
	/* 0x1887: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_188d:
	/* 0x188d: mov    BYTE PTR [rsi+0x55],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_1890:
	/* 0x1890: cmp    rdx,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 82ULL);
x86_l_1894:
	/* 0x1894: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_189a:
	/* 0x189a: lea    eax,[rdx+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_18a0:
	/* 0x18a0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18a5:
	/* 0x18a5: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_18ab:
	/* 0x18ab: mov    BYTE PTR [rsi+0x56],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_18ae:
	/* 0x18ae: cmp    rdx,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 83ULL);
x86_l_18b2:
	/* 0x18b2: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_18b8:
	/* 0x18b8: lea    eax,[rdx+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_18be:
	/* 0x18be: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18c3:
	/* 0x18c3: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_18c9:
	/* 0x18c9: mov    BYTE PTR [rsi+0x57],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_18cc:
	/* 0x18cc: cmp    rdx,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 84ULL);
x86_l_18d0:
	/* 0x18d0: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_18d6:
	/* 0x18d6: lea    eax,[rdx+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_18dc:
	/* 0x18dc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18e1:
	/* 0x18e1: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_18e7:
	/* 0x18e7: mov    BYTE PTR [rsi+0x58],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_18ea:
	/* 0x18ea: cmp    rdx,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 85ULL);
x86_l_18ee:
	/* 0x18ee: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_18f4:
	/* 0x18f4: lea    eax,[rdx+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_18fa:
	/* 0x18fa: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18ff:
	/* 0x18ff: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1905:
	/* 0x1905: mov    BYTE PTR [rsi+0x59],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_1908:
	/* 0x1908: cmp    rdx,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 86ULL);
x86_l_190c:
	/* 0x190c: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_1912:
	/* 0x1912: lea    eax,[rdx+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_1918:
	/* 0x1918: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_191d:
	/* 0x191d: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1923:
	/* 0x1923: mov    BYTE PTR [rsi+0x5a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_1926:
	/* 0x1926: cmp    rdx,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 87ULL);
x86_l_192a:
	/* 0x192a: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_1930:
	/* 0x1930: lea    eax,[rdx+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_1936:
	/* 0x1936: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_193b:
	/* 0x193b: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1941:
	/* 0x1941: mov    BYTE PTR [rsi+0x5b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_1944:
	/* 0x1944: cmp    rdx,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 88ULL);
x86_l_1948:
	/* 0x1948: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_194e:
	/* 0x194e: lea    eax,[rdx+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_1954:
	/* 0x1954: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1959:
	/* 0x1959: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_195f:
	/* 0x195f: mov    BYTE PTR [rsi+0x5c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_1962:
	/* 0x1962: cmp    rdx,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 89ULL);
x86_l_1966:
	/* 0x1966: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_196c:
	/* 0x196c: lea    eax,[rdx+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_1972:
	/* 0x1972: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1977:
	/* 0x1977: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_197d:
	/* 0x197d: mov    BYTE PTR [rsi+0x5d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_1980:
	/* 0x1980: cmp    rdx,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 90ULL);
x86_l_1984:
	/* 0x1984: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_1986:
	/* 0x1986: lea    eax,[rdx+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_198c:
	/* 0x198c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1991:
	/* 0x1991: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1997:
	/* 0x1997: mov    BYTE PTR [rsi+0x5e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_199a:
	/* 0x199a: cmp    rdx,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 91ULL);
x86_l_199e:
	/* 0x199e: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_19a0:
	/* 0x19a0: lea    eax,[rdx+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_19a6:
	/* 0x19a6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19ab:
	/* 0x19ab: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_19b1:
	/* 0x19b1: mov    BYTE PTR [rsi+0x5f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_19b4:
	/* 0x19b4: cmp    rdx,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 92ULL);
x86_l_19b8:
	/* 0x19b8: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_19ba:
	/* 0x19ba: lea    eax,[rdx+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_19c0:
	/* 0x19c0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19c5:
	/* 0x19c5: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_19cb:
	/* 0x19cb: mov    BYTE PTR [rsi+0x60],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_19ce:
	/* 0x19ce: cmp    rdx,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 93ULL);
x86_l_19d2:
	/* 0x19d2: je     19e9 <generic_retkprobe_filter_arg_2+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_19d4:
	/* 0x19d4: add    edx,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_19da:
	/* 0x19da: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19e0:
	/* 0x19e0: movzx  eax,BYTE PTR [r13+rdx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_8), 0ULL);
x86_l_19e6:
	/* 0x19e6: mov    BYTE PTR [rsi+0x61],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_19e9:
	/* 0x19e9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19ee:
	/* 0x19ee: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19f3:
	/* 0x19f3: jmp    3198 <generic_retkprobe_filter_arg_2+0x3198> */
	return 12696ULL;
x86_l_19f8:
	/* 0x19f8: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19fd:
	/* 0x19fd: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a01:
	/* 0x1a01: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a04:
	/* 0x1a04: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a08:
	/* 0x1a08: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1a10:
	/* 0x1a10: mov    rdi,QWORD PTR [rip+0x17e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1a17:
	/* 0x1a17: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a1c:
	/* 0x1a1c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a21:
	/* 0x1a21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a23:
	/* 0x1a23: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1a26:
	/* 0x1a26: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a29:
	/* 0x1a29: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1a2c:
	/* 0x1a2c: je     31a9 <generic_retkprobe_filter_arg_2+0x31a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12713ULL;
	}
x86_l_1a32:
	/* 0x1a32: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a35:
	/* 0x1a35: je     31a9 <generic_retkprobe_filter_arg_2+0x31a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12713ULL;
	}
x86_l_1a3b:
	/* 0x1a3b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a40:
	/* 0x1a40: mov    rdi,QWORD PTR [rip+0x17e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_1a47:
	/* 0x1a47: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a4c:
	/* 0x1a4c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a51:
	/* 0x1a51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a53:
	/* 0x1a53: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a56:
	/* 0x1a56: je     31a6 <generic_retkprobe_filter_arg_2+0x31a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12710ULL;
	}
x86_l_1a5c:
	/* 0x1a5c: cmp    r13d,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 255ULL);
x86_l_1a63:
	/* 0x1a63: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_1a68:
	/* 0x1a68: cmovb  esi,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_1a6c:
	/* 0x1a6c: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_1a73:
	/* 0x1a73: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a75:
	/* 0x1a75: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1a78:
	/* 0x1a78: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1a7c:
	/* 0x1a7c: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1a7f:
	/* 0x1a7f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a84:
	/* 0x1a84: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a89:
	/* 0x1a89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a8b:
	/* 0x1a8b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a90:
	/* 0x1a90: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a95:
	/* 0x1a95: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1a98:
	/* 0x1a98: jmp    3198 <generic_retkprobe_filter_arg_2+0x3198> */
	return 12696ULL;
x86_l_1a9d:
	/* 0x1a9d: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1aa5:
	/* 0x1aa5: cmp    r13d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 144ULL);
x86_l_1aac:
	/* 0x1aac: ja     2c10 <generic_retkprobe_filter_arg_2+0x2c10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11280ULL;
	}
x86_l_1ab2:
	/* 0x1ab2: movzx  eax,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1ab6:
	/* 0x1ab6: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1abc:
	/* 0x1abc: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1abf:
	/* 0x1abf: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1ac2:
	/* 0x1ac2: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1ac5:
	/* 0x1ac5: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_1ac8:
	/* 0x1ac8: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1aca:
	/* 0x1aca: test   r13w,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_16);
x86_l_1ace:
	/* 0x1ace: je     2ae2 <generic_retkprobe_filter_arg_2+0x2ae2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10978ULL;
	}
x86_l_1ad4:
	/* 0x1ad4: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1ad6:
	/* 0x1ad6: jne    2ae2 <generic_retkprobe_filter_arg_2+0x2ae2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10978ULL;
	}
x86_l_1adc:
	/* 0x1adc: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_1adf:
	/* 0x1adf: jmp    2afa <generic_retkprobe_filter_arg_2+0x2afa> */
	return 11002ULL;
x86_l_1ae4:
	/* 0x1ae4: movzx  eax,WORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ae8:
	/* 0x1ae8: mov    WORD PTR [rsp+0x76],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 118ULL);
x86_l_1aed:
	/* 0x1aed: movzx  eax,WORD PTR [r8+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1af2:
	/* 0x1af2: mov    WORD PTR [rsp+0x70],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1af7:
	/* 0x1af7: mov    rax,QWORD PTR [r8+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1afb:
	/* 0x1afb: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b00:
	/* 0x1b00: mov    rax,QWORD PTR [r8+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b04:
	/* 0x1b04: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b09:
	/* 0x1b09: lea    r8,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b0e:
	/* 0x1b0e: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b10:
	/* 0x1b10: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b13:
	/* 0x1b13: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b16:
	/* 0x1b16: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_1b19:
	/* 0x1b19: jle    1b3d <generic_retkprobe_filter_arg_2+0x1b3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1b3d;
	}
x86_l_1b1b:
	/* 0x1b1b: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_1b1e:
	/* 0x1b1e: jg     1b67 <generic_retkprobe_filter_arg_2+0x1b67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1b67;
	}
x86_l_1b20:
	/* 0x1b20: lea    ecx,[rax-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_1b23:
	/* 0x1b23: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b26:
	/* 0x1b26: jb     27a5 <generic_retkprobe_filter_arg_2+0x27a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10149ULL;
	}
x86_l_1b2c:
	/* 0x1b2c: lea    ecx,[rax-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_1b2f:
	/* 0x1b2f: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b32:
	/* 0x1b32: jb     279e <generic_retkprobe_filter_arg_2+0x279e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10142ULL;
	}
x86_l_1b38:
	/* 0x1b38: jmp    31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	return 12747ULL;
x86_l_1b3d:
	/* 0x1b3d: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1b40:
	/* 0x1b40: jle    1bb0 <generic_retkprobe_filter_arg_2+0x1bb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1bb0;
	}
x86_l_1b42:
	/* 0x1b42: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1b45:
	/* 0x1b45: jg     2790 <generic_retkprobe_filter_arg_2+0x2790> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10128ULL;
	}
x86_l_1b4b:
	/* 0x1b4b: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1b4e:
	/* 0x1b4e: je     279e <generic_retkprobe_filter_arg_2+0x279e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10142ULL;
	}
x86_l_1b54:
	/* 0x1b54: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1b57:
	/* 0x1b57: jne    31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12747ULL;
	}
x86_l_1b5d:
	/* 0x1b5d: movzx  r12d,WORD PTR [r8+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1b62:
	/* 0x1b62: jmp    2c1d <generic_retkprobe_filter_arg_2+0x2c1d> */
	return 11293ULL;
x86_l_1b67:
	/* 0x1b67: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1b6a:
	/* 0x1b6a: jg     27b4 <generic_retkprobe_filter_arg_2+0x27b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10164ULL;
	}
x86_l_1b70:
	/* 0x1b70: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_1b73:
	/* 0x1b73: je     27ea <generic_retkprobe_filter_arg_2+0x27ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10218ULL;
	}
x86_l_1b79:
	/* 0x1b79: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1b7c:
	/* 0x1b7c: je     27e0 <generic_retkprobe_filter_arg_2+0x27e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10208ULL;
	}
x86_l_1b82:
	/* 0x1b82: jmp    31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	return 12747ULL;
x86_l_1b87:
	/* 0x1b87: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1b8a:
	/* 0x1b8a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b8d:
	/* 0x1b8d: jae    2aa8 <generic_retkprobe_filter_arg_2+0x2aa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10920ULL;
	}
x86_l_1b93:
	/* 0x1b93: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1b9b:
	/* 0x1b9b: cmp    r13d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 144ULL);
x86_l_1ba2:
	/* 0x1ba2: jbe    2ab0 <generic_retkprobe_filter_arg_2+0x2ab0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 10928ULL;
	}
x86_l_1ba8:
	/* 0x1ba8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bab:
	/* 0x1bab: jmp    310e <generic_retkprobe_filter_arg_2+0x310e> */
	return 12558ULL;
x86_l_1bb0:
	/* 0x1bb0: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1bb3:
	/* 0x1bb3: je     27ea <generic_retkprobe_filter_arg_2+0x27ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10218ULL;
	}
x86_l_1bb9:
	/* 0x1bb9: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1bbc:
	/* 0x1bbc: je     27e0 <generic_retkprobe_filter_arg_2+0x27e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10208ULL;
	}
x86_l_1bc2:
	/* 0x1bc2: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1bc5:
	/* 0x1bc5: je     27a5 <generic_retkprobe_filter_arg_2+0x27a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10149ULL;
	}
x86_l_1bcb:
	/* 0x1bcb: jmp    31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	return 12747ULL;
x86_l_1bd0:
	/* 0x1bd0: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bd5:
	/* 0x1bd5: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bd9:
	/* 0x1bd9: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bdc:
	/* 0x1bdc: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1be0:
	/* 0x1be0: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1be8:
	/* 0x1be8: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_1bef:
	/* 0x1bef: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1bf4:
	/* 0x1bf4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bf9:
	/* 0x1bf9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bfb:
	/* 0x1bfb: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1bfe:
	/* 0x1bfe: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c01:
	/* 0x1c01: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1c04:
	/* 0x1c04: je     310a <generic_retkprobe_filter_arg_2+0x310a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12554ULL;
	}
x86_l_1c0a:
	/* 0x1c0a: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c0f:
	/* 0x1c0f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c12:
	/* 0x1c12: je     310a <generic_retkprobe_filter_arg_2+0x310a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12554ULL;
	}
x86_l_1c18:
	/* 0x1c18: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_1c1f:
	/* 0x1c1f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c24:
	/* 0x1c24: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c29:
	/* 0x1c29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c2b:
	/* 0x1c2b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c2e:
	/* 0x1c2e: je     3107 <generic_retkprobe_filter_arg_2+0x3107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12551ULL;
	}
x86_l_1c34:
	/* 0x1c34: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1c37:
	/* 0x1c37: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c3c:
	/* 0x1c3c: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1c40:
	/* 0x1c40: cmp    r13d,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 94ULL);
x86_l_1c44:
	/* 0x1c44: mov    eax,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 94ULL);
x86_l_1c49:
	/* 0x1c49: cmovb  eax,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_1c4d:
	/* 0x1c4d: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1c50:
	/* 0x1c50: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c52:
	/* 0x1c52: lea    eax,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1c56:
	/* 0x1c56: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1c5b:
	/* 0x1c5b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1c5f:
	/* 0x1c5f: mov    BYTE PTR [rsi+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c62:
	/* 0x1c62: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_1c66:
	/* 0x1c66: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1c6c:
	/* 0x1c6c: lea    eax,[r13+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_1c73:
	/* 0x1c73: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1c78:
	/* 0x1c78: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1c7c:
	/* 0x1c7c: mov    BYTE PTR [rsi+0x5],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_1c7f:
	/* 0x1c7f: cmp    r13,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 2ULL);
	return 7299ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_generic_retkprobe_filter_arg_2_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7299ULL: goto x86_l_1c83;
	case 7305ULL: goto x86_l_1c89;
	case 7312ULL: goto x86_l_1c90;
	case 7317ULL: goto x86_l_1c95;
	case 7321ULL: goto x86_l_1c99;
	case 7324ULL: goto x86_l_1c9c;
	case 7328ULL: goto x86_l_1ca0;
	case 7334ULL: goto x86_l_1ca6;
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
	case 9119ULL: goto x86_l_239f;
	case 9122ULL: goto x86_l_23a2;
	case 9126ULL: goto x86_l_23a6;
	case 9132ULL: goto x86_l_23ac;
	case 9139ULL: goto x86_l_23b3;
	case 9144ULL: goto x86_l_23b8;
	case 9148ULL: goto x86_l_23bc;
	case 9151ULL: goto x86_l_23bf;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c83:
	/* 0x1c83: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1c89:
	/* 0x1c89: lea    eax,[r13+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_1c90:
	/* 0x1c90: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1c95:
	/* 0x1c95: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1c99:
	/* 0x1c99: mov    BYTE PTR [rsi+0x6],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1c9c:
	/* 0x1c9c: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_1ca0:
	/* 0x1ca0: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1ca6:
	/* 0x1ca6: lea    eax,[r13+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_1cad:
	/* 0x1cad: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1cb2:
	/* 0x1cb2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1cb6:
	/* 0x1cb6: mov    BYTE PTR [rsi+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_1cb9:
	/* 0x1cb9: cmp    r13,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4ULL);
x86_l_1cbd:
	/* 0x1cbd: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1cc3:
	/* 0x1cc3: lea    eax,[r13+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_1cca:
	/* 0x1cca: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ccf:
	/* 0x1ccf: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1cd3:
	/* 0x1cd3: mov    BYTE PTR [rsi+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cd6:
	/* 0x1cd6: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_1cda:
	/* 0x1cda: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1ce0:
	/* 0x1ce0: lea    eax,[r13+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_1ce7:
	/* 0x1ce7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1cec:
	/* 0x1cec: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1cf0:
	/* 0x1cf0: mov    BYTE PTR [rsi+0x9],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_1cf3:
	/* 0x1cf3: cmp    r13,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 6ULL);
x86_l_1cf7:
	/* 0x1cf7: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1cfd:
	/* 0x1cfd: lea    eax,[r13+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_1d04:
	/* 0x1d04: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d09:
	/* 0x1d09: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d0d:
	/* 0x1d0d: mov    BYTE PTR [rsi+0xa],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_1d10:
	/* 0x1d10: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_1d14:
	/* 0x1d14: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1d1a:
	/* 0x1d1a: lea    eax,[r13+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_1d21:
	/* 0x1d21: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d26:
	/* 0x1d26: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d2a:
	/* 0x1d2a: mov    BYTE PTR [rsi+0xb],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_1d2d:
	/* 0x1d2d: cmp    r13,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 8ULL);
x86_l_1d31:
	/* 0x1d31: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1d37:
	/* 0x1d37: lea    eax,[r13+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_1d3e:
	/* 0x1d3e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d43:
	/* 0x1d43: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d47:
	/* 0x1d47: mov    BYTE PTR [rsi+0xc],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d4a:
	/* 0x1d4a: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_1d4e:
	/* 0x1d4e: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1d54:
	/* 0x1d54: lea    eax,[r13+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_1d5b:
	/* 0x1d5b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d60:
	/* 0x1d60: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d64:
	/* 0x1d64: mov    BYTE PTR [rsi+0xd],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_1d67:
	/* 0x1d67: cmp    r13,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 10ULL);
x86_l_1d6b:
	/* 0x1d6b: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1d71:
	/* 0x1d71: lea    eax,[r13+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_1d78:
	/* 0x1d78: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d7d:
	/* 0x1d7d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d81:
	/* 0x1d81: mov    BYTE PTR [rsi+0xe],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_1d84:
	/* 0x1d84: cmp    r13,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 11ULL);
x86_l_1d88:
	/* 0x1d88: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1d8e:
	/* 0x1d8e: lea    eax,[r13+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_1d95:
	/* 0x1d95: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d9a:
	/* 0x1d9a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d9e:
	/* 0x1d9e: mov    BYTE PTR [rsi+0xf],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_1da1:
	/* 0x1da1: cmp    r13,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 12ULL);
x86_l_1da5:
	/* 0x1da5: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1dab:
	/* 0x1dab: lea    eax,[r13+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_1db2:
	/* 0x1db2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1db7:
	/* 0x1db7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1dbb:
	/* 0x1dbb: mov    BYTE PTR [rsi+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dbe:
	/* 0x1dbe: cmp    r13,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 13ULL);
x86_l_1dc2:
	/* 0x1dc2: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1dc8:
	/* 0x1dc8: lea    eax,[r13+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_1dcf:
	/* 0x1dcf: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1dd4:
	/* 0x1dd4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1dd8:
	/* 0x1dd8: mov    BYTE PTR [rsi+0x11],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_1ddb:
	/* 0x1ddb: cmp    r13,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 14ULL);
x86_l_1ddf:
	/* 0x1ddf: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1de5:
	/* 0x1de5: lea    eax,[r13+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_1dec:
	/* 0x1dec: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1df1:
	/* 0x1df1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1df5:
	/* 0x1df5: mov    BYTE PTR [rsi+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1df8:
	/* 0x1df8: cmp    r13,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 15ULL);
x86_l_1dfc:
	/* 0x1dfc: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1e02:
	/* 0x1e02: lea    eax,[r13+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_1e09:
	/* 0x1e09: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e0e:
	/* 0x1e0e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e12:
	/* 0x1e12: mov    BYTE PTR [rsi+0x13],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_1e15:
	/* 0x1e15: cmp    r13,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 16ULL);
x86_l_1e19:
	/* 0x1e19: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1e1f:
	/* 0x1e1f: lea    eax,[r13+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_1e26:
	/* 0x1e26: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e2b:
	/* 0x1e2b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e2f:
	/* 0x1e2f: mov    BYTE PTR [rsi+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1e32:
	/* 0x1e32: cmp    r13,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 17ULL);
x86_l_1e36:
	/* 0x1e36: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1e3c:
	/* 0x1e3c: lea    eax,[r13+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_1e43:
	/* 0x1e43: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e48:
	/* 0x1e48: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e4c:
	/* 0x1e4c: mov    BYTE PTR [rsi+0x15],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_1e4f:
	/* 0x1e4f: cmp    r13,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18ULL);
x86_l_1e53:
	/* 0x1e53: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1e59:
	/* 0x1e59: lea    eax,[r13+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_1e60:
	/* 0x1e60: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e65:
	/* 0x1e65: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e69:
	/* 0x1e69: mov    BYTE PTR [rsi+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_1e6c:
	/* 0x1e6c: cmp    r13,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 19ULL);
x86_l_1e70:
	/* 0x1e70: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1e76:
	/* 0x1e76: lea    eax,[r13+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_1e7d:
	/* 0x1e7d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e82:
	/* 0x1e82: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e86:
	/* 0x1e86: mov    BYTE PTR [rsi+0x17],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_1e89:
	/* 0x1e89: cmp    r13,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 20ULL);
x86_l_1e8d:
	/* 0x1e8d: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1e93:
	/* 0x1e93: lea    eax,[r13+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_1e9a:
	/* 0x1e9a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e9f:
	/* 0x1e9f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ea3:
	/* 0x1ea3: mov    BYTE PTR [rsi+0x18],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ea6:
	/* 0x1ea6: cmp    r13,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 21ULL);
x86_l_1eaa:
	/* 0x1eaa: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1eb0:
	/* 0x1eb0: lea    eax,[r13+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_1eb7:
	/* 0x1eb7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ebc:
	/* 0x1ebc: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ec0:
	/* 0x1ec0: mov    BYTE PTR [rsi+0x19],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_1ec3:
	/* 0x1ec3: cmp    r13,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 22ULL);
x86_l_1ec7:
	/* 0x1ec7: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1ecd:
	/* 0x1ecd: lea    eax,[r13+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_1ed4:
	/* 0x1ed4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ed9:
	/* 0x1ed9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1edd:
	/* 0x1edd: mov    BYTE PTR [rsi+0x1a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_1ee0:
	/* 0x1ee0: cmp    r13,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 23ULL);
x86_l_1ee4:
	/* 0x1ee4: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1eea:
	/* 0x1eea: lea    eax,[r13+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_1ef1:
	/* 0x1ef1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ef6:
	/* 0x1ef6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1efa:
	/* 0x1efa: mov    BYTE PTR [rsi+0x1b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_1efd:
	/* 0x1efd: cmp    r13,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 24ULL);
x86_l_1f01:
	/* 0x1f01: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1f07:
	/* 0x1f07: lea    eax,[r13+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_1f0e:
	/* 0x1f0e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f13:
	/* 0x1f13: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f17:
	/* 0x1f17: mov    BYTE PTR [rsi+0x1c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1f1a:
	/* 0x1f1a: cmp    r13,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 25ULL);
x86_l_1f1e:
	/* 0x1f1e: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1f24:
	/* 0x1f24: lea    eax,[r13+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_1f2b:
	/* 0x1f2b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f30:
	/* 0x1f30: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f34:
	/* 0x1f34: mov    BYTE PTR [rsi+0x1d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_1f37:
	/* 0x1f37: cmp    r13,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 26ULL);
x86_l_1f3b:
	/* 0x1f3b: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1f41:
	/* 0x1f41: lea    eax,[r13+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_1f48:
	/* 0x1f48: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f4d:
	/* 0x1f4d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f51:
	/* 0x1f51: mov    BYTE PTR [rsi+0x1e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_1f54:
	/* 0x1f54: cmp    r13,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 27ULL);
x86_l_1f58:
	/* 0x1f58: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1f5e:
	/* 0x1f5e: lea    eax,[r13+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_1f65:
	/* 0x1f65: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f6a:
	/* 0x1f6a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f6e:
	/* 0x1f6e: mov    BYTE PTR [rsi+0x1f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_1f71:
	/* 0x1f71: cmp    r13,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 28ULL);
x86_l_1f75:
	/* 0x1f75: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1f7b:
	/* 0x1f7b: lea    eax,[r13+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_1f82:
	/* 0x1f82: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f87:
	/* 0x1f87: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f8b:
	/* 0x1f8b: mov    BYTE PTR [rsi+0x20],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f8e:
	/* 0x1f8e: cmp    r13,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 29ULL);
x86_l_1f92:
	/* 0x1f92: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1f98:
	/* 0x1f98: lea    eax,[r13+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_1f9f:
	/* 0x1f9f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1fa4:
	/* 0x1fa4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1fa8:
	/* 0x1fa8: mov    BYTE PTR [rsi+0x21],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_1fab:
	/* 0x1fab: cmp    r13,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 30ULL);
x86_l_1faf:
	/* 0x1faf: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1fb5:
	/* 0x1fb5: lea    eax,[r13+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_1fbc:
	/* 0x1fbc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1fc1:
	/* 0x1fc1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1fc5:
	/* 0x1fc5: mov    BYTE PTR [rsi+0x22],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_1fc8:
	/* 0x1fc8: cmp    r13,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 31ULL);
x86_l_1fcc:
	/* 0x1fcc: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1fd2:
	/* 0x1fd2: lea    eax,[r13+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_1fd9:
	/* 0x1fd9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1fde:
	/* 0x1fde: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1fe2:
	/* 0x1fe2: mov    BYTE PTR [rsi+0x23],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_1fe5:
	/* 0x1fe5: cmp    r13,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 32ULL);
x86_l_1fe9:
	/* 0x1fe9: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_1fef:
	/* 0x1fef: lea    eax,[r13+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_1ff6:
	/* 0x1ff6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ffb:
	/* 0x1ffb: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1fff:
	/* 0x1fff: mov    BYTE PTR [rsi+0x24],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2002:
	/* 0x2002: cmp    r13,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 33ULL);
x86_l_2006:
	/* 0x2006: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_200c:
	/* 0x200c: lea    eax,[r13+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_2013:
	/* 0x2013: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2018:
	/* 0x2018: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_201c:
	/* 0x201c: mov    BYTE PTR [rsi+0x25],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_201f:
	/* 0x201f: cmp    r13,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 34ULL);
x86_l_2023:
	/* 0x2023: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_2029:
	/* 0x2029: lea    eax,[r13+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_2030:
	/* 0x2030: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2035:
	/* 0x2035: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2039:
	/* 0x2039: mov    BYTE PTR [rsi+0x26],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_203c:
	/* 0x203c: cmp    r13,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 35ULL);
x86_l_2040:
	/* 0x2040: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_2046:
	/* 0x2046: lea    eax,[r13+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_204d:
	/* 0x204d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2052:
	/* 0x2052: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2056:
	/* 0x2056: mov    BYTE PTR [rsi+0x27],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_2059:
	/* 0x2059: cmp    r13,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 36ULL);
x86_l_205d:
	/* 0x205d: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_2063:
	/* 0x2063: lea    eax,[r13+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_206a:
	/* 0x206a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_206f:
	/* 0x206f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2073:
	/* 0x2073: mov    BYTE PTR [rsi+0x28],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2076:
	/* 0x2076: cmp    r13,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 37ULL);
x86_l_207a:
	/* 0x207a: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_2080:
	/* 0x2080: lea    eax,[r13+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_2087:
	/* 0x2087: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_208c:
	/* 0x208c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2090:
	/* 0x2090: mov    BYTE PTR [rsi+0x29],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_2093:
	/* 0x2093: cmp    r13,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 38ULL);
x86_l_2097:
	/* 0x2097: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_209d:
	/* 0x209d: lea    eax,[r13+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_20a4:
	/* 0x20a4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20a9:
	/* 0x20a9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_20ad:
	/* 0x20ad: mov    BYTE PTR [rsi+0x2a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_20b0:
	/* 0x20b0: cmp    r13,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 39ULL);
x86_l_20b4:
	/* 0x20b4: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_20ba:
	/* 0x20ba: lea    eax,[r13+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_20c1:
	/* 0x20c1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20c6:
	/* 0x20c6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_20ca:
	/* 0x20ca: mov    BYTE PTR [rsi+0x2b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_20cd:
	/* 0x20cd: cmp    r13,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 40ULL);
x86_l_20d1:
	/* 0x20d1: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_20d7:
	/* 0x20d7: lea    eax,[r13+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_20de:
	/* 0x20de: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20e3:
	/* 0x20e3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_20e7:
	/* 0x20e7: mov    BYTE PTR [rsi+0x2c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_20ea:
	/* 0x20ea: cmp    r13,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 41ULL);
x86_l_20ee:
	/* 0x20ee: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_20f4:
	/* 0x20f4: lea    eax,[r13+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_20fb:
	/* 0x20fb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2100:
	/* 0x2100: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2104:
	/* 0x2104: mov    BYTE PTR [rsi+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_2107:
	/* 0x2107: cmp    r13,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 42ULL);
x86_l_210b:
	/* 0x210b: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_2111:
	/* 0x2111: lea    eax,[r13+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_2118:
	/* 0x2118: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_211d:
	/* 0x211d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2121:
	/* 0x2121: mov    BYTE PTR [rsi+0x2e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_2124:
	/* 0x2124: cmp    r13,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 43ULL);
x86_l_2128:
	/* 0x2128: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_212e:
	/* 0x212e: lea    eax,[r13+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_2135:
	/* 0x2135: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_213a:
	/* 0x213a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_213e:
	/* 0x213e: mov    BYTE PTR [rsi+0x2f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_2141:
	/* 0x2141: cmp    r13,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 44ULL);
x86_l_2145:
	/* 0x2145: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_214b:
	/* 0x214b: lea    eax,[r13+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_2152:
	/* 0x2152: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2157:
	/* 0x2157: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_215b:
	/* 0x215b: mov    BYTE PTR [rsi+0x30],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_215e:
	/* 0x215e: cmp    r13,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 45ULL);
x86_l_2162:
	/* 0x2162: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_2168:
	/* 0x2168: lea    eax,[r13+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_216f:
	/* 0x216f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2174:
	/* 0x2174: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2178:
	/* 0x2178: mov    BYTE PTR [rsi+0x31],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_217b:
	/* 0x217b: cmp    r13,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 46ULL);
x86_l_217f:
	/* 0x217f: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_2185:
	/* 0x2185: lea    eax,[r13+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_218c:
	/* 0x218c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2191:
	/* 0x2191: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2195:
	/* 0x2195: mov    BYTE PTR [rsi+0x32],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_2198:
	/* 0x2198: cmp    r13,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 47ULL);
x86_l_219c:
	/* 0x219c: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_21a2:
	/* 0x21a2: lea    eax,[r13+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_21a9:
	/* 0x21a9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21ae:
	/* 0x21ae: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_21b2:
	/* 0x21b2: mov    BYTE PTR [rsi+0x33],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_21b5:
	/* 0x21b5: cmp    r13,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 48ULL);
x86_l_21b9:
	/* 0x21b9: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_21bf:
	/* 0x21bf: lea    eax,[r13+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_21c6:
	/* 0x21c6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21cb:
	/* 0x21cb: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_21cf:
	/* 0x21cf: mov    BYTE PTR [rsi+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_21d2:
	/* 0x21d2: cmp    r13,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 49ULL);
x86_l_21d6:
	/* 0x21d6: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_21dc:
	/* 0x21dc: lea    eax,[r13+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_21e3:
	/* 0x21e3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21e8:
	/* 0x21e8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_21ec:
	/* 0x21ec: mov    BYTE PTR [rsi+0x35],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_21ef:
	/* 0x21ef: cmp    r13,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 50ULL);
x86_l_21f3:
	/* 0x21f3: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_21f9:
	/* 0x21f9: lea    eax,[r13+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_2200:
	/* 0x2200: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2205:
	/* 0x2205: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2209:
	/* 0x2209: mov    BYTE PTR [rsi+0x36],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_220c:
	/* 0x220c: cmp    r13,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 51ULL);
x86_l_2210:
	/* 0x2210: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_2216:
	/* 0x2216: lea    eax,[r13+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_221d:
	/* 0x221d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2222:
	/* 0x2222: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2226:
	/* 0x2226: mov    BYTE PTR [rsi+0x37],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_2229:
	/* 0x2229: cmp    r13,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 52ULL);
x86_l_222d:
	/* 0x222d: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_2233:
	/* 0x2233: lea    eax,[r13+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_223a:
	/* 0x223a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_223f:
	/* 0x223f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2243:
	/* 0x2243: mov    BYTE PTR [rsi+0x38],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2246:
	/* 0x2246: cmp    r13,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 53ULL);
x86_l_224a:
	/* 0x224a: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_2250:
	/* 0x2250: lea    eax,[r13+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_2257:
	/* 0x2257: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_225c:
	/* 0x225c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2260:
	/* 0x2260: mov    BYTE PTR [rsi+0x39],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_2263:
	/* 0x2263: cmp    r13,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 54ULL);
x86_l_2267:
	/* 0x2267: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_226d:
	/* 0x226d: lea    eax,[r13+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_2274:
	/* 0x2274: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2279:
	/* 0x2279: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_227d:
	/* 0x227d: mov    BYTE PTR [rsi+0x3a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_2280:
	/* 0x2280: cmp    r13,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 55ULL);
x86_l_2284:
	/* 0x2284: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_228a:
	/* 0x228a: lea    eax,[r13+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_2291:
	/* 0x2291: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2296:
	/* 0x2296: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_229a:
	/* 0x229a: mov    BYTE PTR [rsi+0x3b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_229d:
	/* 0x229d: cmp    r13,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 56ULL);
x86_l_22a1:
	/* 0x22a1: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_22a7:
	/* 0x22a7: lea    eax,[r13+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_22ae:
	/* 0x22ae: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22b3:
	/* 0x22b3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_22b7:
	/* 0x22b7: mov    BYTE PTR [rsi+0x3c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_22ba:
	/* 0x22ba: cmp    r13,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 57ULL);
x86_l_22be:
	/* 0x22be: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_22c4:
	/* 0x22c4: lea    eax,[r13+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_22cb:
	/* 0x22cb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22d0:
	/* 0x22d0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_22d4:
	/* 0x22d4: mov    BYTE PTR [rsi+0x3d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_22d7:
	/* 0x22d7: cmp    r13,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 58ULL);
x86_l_22db:
	/* 0x22db: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_22e1:
	/* 0x22e1: lea    eax,[r13+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_22e8:
	/* 0x22e8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22ed:
	/* 0x22ed: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_22f1:
	/* 0x22f1: mov    BYTE PTR [rsi+0x3e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_22f4:
	/* 0x22f4: cmp    r13,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 59ULL);
x86_l_22f8:
	/* 0x22f8: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_22fe:
	/* 0x22fe: lea    eax,[r13+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_2305:
	/* 0x2305: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_230a:
	/* 0x230a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_230e:
	/* 0x230e: mov    BYTE PTR [rsi+0x3f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_2311:
	/* 0x2311: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_2315:
	/* 0x2315: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_231b:
	/* 0x231b: lea    eax,[r13+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_2322:
	/* 0x2322: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2327:
	/* 0x2327: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_232b:
	/* 0x232b: mov    BYTE PTR [rsi+0x40],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_232e:
	/* 0x232e: cmp    r13,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 61ULL);
x86_l_2332:
	/* 0x2332: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_2338:
	/* 0x2338: lea    eax,[r13+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_233f:
	/* 0x233f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2344:
	/* 0x2344: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2348:
	/* 0x2348: mov    BYTE PTR [rsi+0x41],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_234b:
	/* 0x234b: cmp    r13,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 62ULL);
x86_l_234f:
	/* 0x234f: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_2355:
	/* 0x2355: lea    eax,[r13+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_235c:
	/* 0x235c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2361:
	/* 0x2361: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2365:
	/* 0x2365: mov    BYTE PTR [rsi+0x42],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_2368:
	/* 0x2368: cmp    r13,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 63ULL);
x86_l_236c:
	/* 0x236c: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_2372:
	/* 0x2372: lea    eax,[r13+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_2379:
	/* 0x2379: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_237e:
	/* 0x237e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2382:
	/* 0x2382: mov    BYTE PTR [rsi+0x43],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_2385:
	/* 0x2385: cmp    r13,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 64ULL);
x86_l_2389:
	/* 0x2389: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_238f:
	/* 0x238f: lea    eax,[r13+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_2396:
	/* 0x2396: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_239b:
	/* 0x239b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_239f:
	/* 0x239f: mov    BYTE PTR [rsi+0x44],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_23a2:
	/* 0x23a2: cmp    r13,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 65ULL);
x86_l_23a6:
	/* 0x23a6: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9944ULL;
	}
x86_l_23ac:
	/* 0x23ac: lea    eax,[r13+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_23b3:
	/* 0x23b3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23b8:
	/* 0x23b8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_23bc:
	/* 0x23bc: mov    BYTE PTR [rsi+0x45],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_23bf:
	/* 0x23bf: cmp    r13,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 66ULL);
	return 9155ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_generic_retkprobe_filter_arg_2_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
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
	case 9824ULL: goto x86_l_2660;
	case 9831ULL: goto x86_l_2667;
	case 9836ULL: goto x86_l_266c;
	case 9840ULL: goto x86_l_2670;
	case 9843ULL: goto x86_l_2673;
	case 9847ULL: goto x86_l_2677;
	case 9849ULL: goto x86_l_2679;
	case 9856ULL: goto x86_l_2680;
	case 9861ULL: goto x86_l_2685;
	case 9865ULL: goto x86_l_2689;
	case 9868ULL: goto x86_l_268c;
	case 9872ULL: goto x86_l_2690;
	case 9874ULL: goto x86_l_2692;
	case 9881ULL: goto x86_l_2699;
	case 9886ULL: goto x86_l_269e;
	case 9890ULL: goto x86_l_26a2;
	case 9893ULL: goto x86_l_26a5;
	case 9897ULL: goto x86_l_26a9;
	case 9899ULL: goto x86_l_26ab;
	case 9902ULL: goto x86_l_26ae;
	case 9907ULL: goto x86_l_26b3;
	case 9912ULL: goto x86_l_26b8;
	case 9916ULL: goto x86_l_26bc;
	case 9919ULL: goto x86_l_26bf;
	case 9923ULL: goto x86_l_26c3;
	case 9925ULL: goto x86_l_26c5;
	case 9932ULL: goto x86_l_26cc;
	case 9937ULL: goto x86_l_26d1;
	case 9941ULL: goto x86_l_26d5;
	case 9944ULL: goto x86_l_26d8;
	case 9949ULL: goto x86_l_26dd;
	case 9954ULL: goto x86_l_26e2;
	case 9959ULL: goto x86_l_26e7;
	case 9964ULL: goto x86_l_26ec;
	case 9968ULL: goto x86_l_26f0;
	case 9971ULL: goto x86_l_26f3;
	case 9975ULL: goto x86_l_26f7;
	case 9983ULL: goto x86_l_26ff;
	case 9990ULL: goto x86_l_2706;
	case 9995ULL: goto x86_l_270b;
	case 10000ULL: goto x86_l_2710;
	case 10002ULL: goto x86_l_2712;
	case 10005ULL: goto x86_l_2715;
	case 10008ULL: goto x86_l_2718;
	case 10011ULL: goto x86_l_271b;
	case 10017ULL: goto x86_l_2721;
	case 10022ULL: goto x86_l_2726;
	case 10025ULL: goto x86_l_2729;
	case 10031ULL: goto x86_l_272f;
	case 10038ULL: goto x86_l_2736;
	case 10043ULL: goto x86_l_273b;
	case 10048ULL: goto x86_l_2740;
	case 10050ULL: goto x86_l_2742;
	case 10053ULL: goto x86_l_2745;
	case 10059ULL: goto x86_l_274b;
	case 10064ULL: goto x86_l_2750;
	case 10068ULL: goto x86_l_2754;
	case 10075ULL: goto x86_l_275b;
	case 10080ULL: goto x86_l_2760;
	case 10084ULL: goto x86_l_2764;
	case 10091ULL: goto x86_l_276b;
	case 10093ULL: goto x86_l_276d;
	case 10096ULL: goto x86_l_2770;
	case 10100ULL: goto x86_l_2774;
	case 10103ULL: goto x86_l_2777;
	case 10108ULL: goto x86_l_277c;
	case 10110ULL: goto x86_l_277e;
	case 10115ULL: goto x86_l_2783;
	case 10120ULL: goto x86_l_2788;
	case 10123ULL: goto x86_l_278b;
	case 10128ULL: goto x86_l_2790;
	case 10131ULL: goto x86_l_2793;
	case 10133ULL: goto x86_l_2795;
	case 10136ULL: goto x86_l_2798;
	case 10142ULL: goto x86_l_279e;
	case 10147ULL: goto x86_l_27a3;
	case 10149ULL: goto x86_l_27a5;
	case 10154ULL: goto x86_l_27aa;
	case 10156ULL: goto x86_l_27ac;
	case 10159ULL: goto x86_l_27af;
	case 10162ULL: goto x86_l_27b2;
	case 10164ULL: goto x86_l_27b4;
	case 10167ULL: goto x86_l_27b7;
	case 10173ULL: goto x86_l_27bd;
	case 10176ULL: goto x86_l_27c0;
	case 10182ULL: goto x86_l_27c6;
	case 10185ULL: goto x86_l_27c9;
	case 10191ULL: goto x86_l_27cf;
	case 10194ULL: goto x86_l_27d2;
	case 10200ULL: goto x86_l_27d8;
	case 10203ULL: goto x86_l_27db;
	case 10208ULL: goto x86_l_27e0;
	case 10212ULL: goto x86_l_27e4;
	case 10216ULL: goto x86_l_27e8;
	case 10218ULL: goto x86_l_27ea;
	case 10221ULL: goto x86_l_27ed;
	case 10225ULL: goto x86_l_27f1;
	case 10228ULL: goto x86_l_27f4;
	case 10232ULL: goto x86_l_27f8;
	case 10234ULL: goto x86_l_27fa;
	case 10237ULL: goto x86_l_27fd;
	case 10240ULL: goto x86_l_2800;
	case 10242ULL: goto x86_l_2802;
	case 10245ULL: goto x86_l_2805;
	case 10248ULL: goto x86_l_2808;
	case 10250ULL: goto x86_l_280a;
	case 10253ULL: goto x86_l_280d;
	case 10256ULL: goto x86_l_2810;
	case 10262ULL: goto x86_l_2816;
	case 10265ULL: goto x86_l_2819;
	case 10271ULL: goto x86_l_281f;
	case 10276ULL: goto x86_l_2824;
	case 10279ULL: goto x86_l_2827;
	case 10281ULL: goto x86_l_2829;
	case 10286ULL: goto x86_l_282e;
	case 10289ULL: goto x86_l_2831;
	case 10295ULL: goto x86_l_2837;
	case 10300ULL: goto x86_l_283c;
	case 10303ULL: goto x86_l_283f;
	case 10309ULL: goto x86_l_2845;
	case 10314ULL: goto x86_l_284a;
	case 10317ULL: goto x86_l_284d;
	case 10319ULL: goto x86_l_284f;
	case 10324ULL: goto x86_l_2854;
	case 10327ULL: goto x86_l_2857;
	case 10333ULL: goto x86_l_285d;
	case 10336ULL: goto x86_l_2860;
	case 10342ULL: goto x86_l_2866;
	case 10345ULL: goto x86_l_2869;
	case 10348ULL: goto x86_l_286c;
	case 10351ULL: goto x86_l_286f;
	case 10355ULL: goto x86_l_2873;
	case 10362ULL: goto x86_l_287a;
	case 10367ULL: goto x86_l_287f;
	case 10372ULL: goto x86_l_2884;
	case 10374ULL: goto x86_l_2886;
	case 10377ULL: goto x86_l_2889;
	case 10383ULL: goto x86_l_288f;
	case 10386ULL: goto x86_l_2892;
	case 10394ULL: goto x86_l_289a;
	case 10399ULL: goto x86_l_289f;
	case 10404ULL: goto x86_l_28a4;
	case 10407ULL: goto x86_l_28a7;
	case 10410ULL: goto x86_l_28aa;
	case 10416ULL: goto x86_l_28b0;
	case 10419ULL: goto x86_l_28b3;
	case 10423ULL: goto x86_l_28b7;
	case 10427ULL: goto x86_l_28bb;
	case 10434ULL: goto x86_l_28c2;
	case 10437ULL: goto x86_l_28c5;
	case 10442ULL: goto x86_l_28ca;
	case 10447ULL: goto x86_l_28cf;
	case 10449ULL: goto x86_l_28d1;
	case 10452ULL: goto x86_l_28d4;
	case 10458ULL: goto x86_l_28da;
	case 10461ULL: goto x86_l_28dd;
	case 10465ULL: goto x86_l_28e1;
	case 10470ULL: goto x86_l_28e6;
	case 10475ULL: goto x86_l_28eb;
	case 10480ULL: goto x86_l_28f0;
	case 10482ULL: goto x86_l_28f2;
	case 10487ULL: goto x86_l_28f7;
	case 10492ULL: goto x86_l_28fc;
	case 10497ULL: goto x86_l_2901;
	case 10501ULL: goto x86_l_2905;
	case 10504ULL: goto x86_l_2908;
	case 10508ULL: goto x86_l_290c;
	case 10516ULL: goto x86_l_2914;
	case 10523ULL: goto x86_l_291b;
	case 10528ULL: goto x86_l_2920;
	case 10533ULL: goto x86_l_2925;
	case 10535ULL: goto x86_l_2927;
	case 10538ULL: goto x86_l_292a;
	case 10544ULL: goto x86_l_2930;
	case 10550ULL: goto x86_l_2936;
	case 10553ULL: goto x86_l_2939;
	case 10556ULL: goto x86_l_293c;
	case 10562ULL: goto x86_l_2942;
	case 10569ULL: goto x86_l_2949;
	case 10574ULL: goto x86_l_294e;
	case 10579ULL: goto x86_l_2953;
	case 10581ULL: goto x86_l_2955;
	case 10584ULL: goto x86_l_2958;
	case 10590ULL: goto x86_l_295e;
	case 10595ULL: goto x86_l_2963;
	case 10601ULL: goto x86_l_2969;
	case 10606ULL: goto x86_l_296e;
	case 10609ULL: goto x86_l_2971;
	case 10616ULL: goto x86_l_2978;
	case 10618ULL: goto x86_l_297a;
	case 10621ULL: goto x86_l_297d;
	case 10625ULL: goto x86_l_2981;
	case 10628ULL: goto x86_l_2984;
	case 10633ULL: goto x86_l_2989;
	case 10638ULL: goto x86_l_298e;
	case 10640ULL: goto x86_l_2990;
	case 10645ULL: goto x86_l_2995;
	case 10648ULL: goto x86_l_2998;
	case 10651ULL: goto x86_l_299b;
	case 10656ULL: goto x86_l_29a0;
	case 10664ULL: goto x86_l_29a8;
	case 10670ULL: goto x86_l_29ae;
	case 10676ULL: goto x86_l_29b4;
	case 10681ULL: goto x86_l_29b9;
	case 10685ULL: goto x86_l_29bd;
	case 10688ULL: goto x86_l_29c0;
	case 10694ULL: goto x86_l_29c6;
	case 10697ULL: goto x86_l_29c9;
	case 10700ULL: goto x86_l_29cc;
	case 10703ULL: goto x86_l_29cf;
	case 10705ULL: goto x86_l_29d1;
	case 10707ULL: goto x86_l_29d3;
	case 10710ULL: goto x86_l_29d6;
	case 10716ULL: goto x86_l_29dc;
	case 10718ULL: goto x86_l_29de;
	case 10724ULL: goto x86_l_29e4;
	case 10729ULL: goto x86_l_29e9;
	case 10732ULL: goto x86_l_29ec;
	case 10735ULL: goto x86_l_29ef;
	case 10740ULL: goto x86_l_29f4;
	case 10744ULL: goto x86_l_29f8;
	case 10749ULL: goto x86_l_29fd;
	case 10752ULL: goto x86_l_2a00;
	case 10755ULL: goto x86_l_2a03;
	case 10760ULL: goto x86_l_2a08;
	case 10764ULL: goto x86_l_2a0c;
	case 10769ULL: goto x86_l_2a11;
	case 10774ULL: goto x86_l_2a16;
	case 10778ULL: goto x86_l_2a1a;
	case 10781ULL: goto x86_l_2a1d;
	case 10784ULL: goto x86_l_2a20;
	case 10788ULL: goto x86_l_2a24;
	case 10795ULL: goto x86_l_2a2b;
	case 10800ULL: goto x86_l_2a30;
	case 10805ULL: goto x86_l_2a35;
	case 10807ULL: goto x86_l_2a37;
	case 10810ULL: goto x86_l_2a3a;
	case 10816ULL: goto x86_l_2a40;
	case 10819ULL: goto x86_l_2a43;
	case 10827ULL: goto x86_l_2a4b;
	case 10831ULL: goto x86_l_2a4f;
	case 10835ULL: goto x86_l_2a53;
	case 10840ULL: goto x86_l_2a58;
	case 10845ULL: goto x86_l_2a5d;
	case 10849ULL: goto x86_l_2a61;
	default: return 0xffffffffffffffffULL;
	}
x86_l_23c3:
	/* 0x23c3: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_23c9:
	/* 0x23c9: lea    eax,[r13+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_23d0:
	/* 0x23d0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23d5:
	/* 0x23d5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_23d9:
	/* 0x23d9: mov    BYTE PTR [rsi+0x46],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_23dc:
	/* 0x23dc: cmp    r13,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 67ULL);
x86_l_23e0:
	/* 0x23e0: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_23e6:
	/* 0x23e6: lea    eax,[r13+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_23ed:
	/* 0x23ed: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23f2:
	/* 0x23f2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_23f6:
	/* 0x23f6: mov    BYTE PTR [rsi+0x47],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_23f9:
	/* 0x23f9: cmp    r13,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 68ULL);
x86_l_23fd:
	/* 0x23fd: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_2403:
	/* 0x2403: lea    eax,[r13+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_240a:
	/* 0x240a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_240f:
	/* 0x240f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2413:
	/* 0x2413: mov    BYTE PTR [rsi+0x48],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2416:
	/* 0x2416: cmp    r13,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 69ULL);
x86_l_241a:
	/* 0x241a: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_2420:
	/* 0x2420: lea    eax,[r13+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_2427:
	/* 0x2427: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_242c:
	/* 0x242c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2430:
	/* 0x2430: mov    BYTE PTR [rsi+0x49],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_2433:
	/* 0x2433: cmp    r13,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 70ULL);
x86_l_2437:
	/* 0x2437: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_243d:
	/* 0x243d: lea    eax,[r13+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_2444:
	/* 0x2444: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2449:
	/* 0x2449: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_244d:
	/* 0x244d: mov    BYTE PTR [rsi+0x4a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_2450:
	/* 0x2450: cmp    r13,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 71ULL);
x86_l_2454:
	/* 0x2454: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_245a:
	/* 0x245a: lea    eax,[r13+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_2461:
	/* 0x2461: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2466:
	/* 0x2466: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_246a:
	/* 0x246a: mov    BYTE PTR [rsi+0x4b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_246d:
	/* 0x246d: cmp    r13,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 72ULL);
x86_l_2471:
	/* 0x2471: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_2477:
	/* 0x2477: lea    eax,[r13+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_247e:
	/* 0x247e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2483:
	/* 0x2483: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2487:
	/* 0x2487: mov    BYTE PTR [rsi+0x4c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_248a:
	/* 0x248a: cmp    r13,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 73ULL);
x86_l_248e:
	/* 0x248e: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_2494:
	/* 0x2494: lea    eax,[r13+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_249b:
	/* 0x249b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24a0:
	/* 0x24a0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_24a4:
	/* 0x24a4: mov    BYTE PTR [rsi+0x4d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_24a7:
	/* 0x24a7: cmp    r13,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 74ULL);
x86_l_24ab:
	/* 0x24ab: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_24b1:
	/* 0x24b1: lea    eax,[r13+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_24b8:
	/* 0x24b8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24bd:
	/* 0x24bd: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_24c1:
	/* 0x24c1: mov    BYTE PTR [rsi+0x4e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_24c4:
	/* 0x24c4: cmp    r13,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 75ULL);
x86_l_24c8:
	/* 0x24c8: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_24ce:
	/* 0x24ce: lea    eax,[r13+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_24d5:
	/* 0x24d5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24da:
	/* 0x24da: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_24de:
	/* 0x24de: mov    BYTE PTR [rsi+0x4f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_24e1:
	/* 0x24e1: cmp    r13,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 76ULL);
x86_l_24e5:
	/* 0x24e5: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_24eb:
	/* 0x24eb: lea    eax,[r13+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_24f2:
	/* 0x24f2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24f7:
	/* 0x24f7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_24fb:
	/* 0x24fb: mov    BYTE PTR [rsi+0x50],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_24fe:
	/* 0x24fe: cmp    r13,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 77ULL);
x86_l_2502:
	/* 0x2502: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_2508:
	/* 0x2508: lea    eax,[r13+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_250f:
	/* 0x250f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2514:
	/* 0x2514: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2518:
	/* 0x2518: mov    BYTE PTR [rsi+0x51],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_251b:
	/* 0x251b: cmp    r13,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 78ULL);
x86_l_251f:
	/* 0x251f: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_2525:
	/* 0x2525: lea    eax,[r13+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_252c:
	/* 0x252c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2531:
	/* 0x2531: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2535:
	/* 0x2535: mov    BYTE PTR [rsi+0x52],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_2538:
	/* 0x2538: cmp    r13,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 79ULL);
x86_l_253c:
	/* 0x253c: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_2542:
	/* 0x2542: lea    eax,[r13+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_2549:
	/* 0x2549: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_254e:
	/* 0x254e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2552:
	/* 0x2552: mov    BYTE PTR [rsi+0x53],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_2555:
	/* 0x2555: cmp    r13,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 80ULL);
x86_l_2559:
	/* 0x2559: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_255f:
	/* 0x255f: lea    eax,[r13+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_2566:
	/* 0x2566: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_256b:
	/* 0x256b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_256f:
	/* 0x256f: mov    BYTE PTR [rsi+0x54],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_2572:
	/* 0x2572: cmp    r13,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 81ULL);
x86_l_2576:
	/* 0x2576: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_257c:
	/* 0x257c: lea    eax,[r13+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_2583:
	/* 0x2583: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2588:
	/* 0x2588: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_258c:
	/* 0x258c: mov    BYTE PTR [rsi+0x55],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_258f:
	/* 0x258f: cmp    r13,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 82ULL);
x86_l_2593:
	/* 0x2593: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_2599:
	/* 0x2599: lea    eax,[r13+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_25a0:
	/* 0x25a0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25a5:
	/* 0x25a5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_25a9:
	/* 0x25a9: mov    BYTE PTR [rsi+0x56],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_25ac:
	/* 0x25ac: cmp    r13,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 83ULL);
x86_l_25b0:
	/* 0x25b0: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_25b6:
	/* 0x25b6: lea    eax,[r13+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_25bd:
	/* 0x25bd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25c2:
	/* 0x25c2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_25c6:
	/* 0x25c6: mov    BYTE PTR [rsi+0x57],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_25c9:
	/* 0x25c9: cmp    r13,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 84ULL);
x86_l_25cd:
	/* 0x25cd: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_25d3:
	/* 0x25d3: lea    eax,[r13+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_25da:
	/* 0x25da: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25df:
	/* 0x25df: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_25e3:
	/* 0x25e3: mov    BYTE PTR [rsi+0x58],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_25e6:
	/* 0x25e6: cmp    r13,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 85ULL);
x86_l_25ea:
	/* 0x25ea: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_25f0:
	/* 0x25f0: lea    eax,[r13+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_25f7:
	/* 0x25f7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25fc:
	/* 0x25fc: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2600:
	/* 0x2600: mov    BYTE PTR [rsi+0x59],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_2603:
	/* 0x2603: cmp    r13,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 86ULL);
x86_l_2607:
	/* 0x2607: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_260d:
	/* 0x260d: lea    eax,[r13+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_2614:
	/* 0x2614: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2619:
	/* 0x2619: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_261d:
	/* 0x261d: mov    BYTE PTR [rsi+0x5a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_2620:
	/* 0x2620: cmp    r13,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 87ULL);
x86_l_2624:
	/* 0x2624: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_262a:
	/* 0x262a: lea    eax,[r13+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_2631:
	/* 0x2631: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2636:
	/* 0x2636: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_263a:
	/* 0x263a: mov    BYTE PTR [rsi+0x5b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_263d:
	/* 0x263d: cmp    r13,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 88ULL);
x86_l_2641:
	/* 0x2641: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_2647:
	/* 0x2647: lea    eax,[r13+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_264e:
	/* 0x264e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2653:
	/* 0x2653: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2657:
	/* 0x2657: mov    BYTE PTR [rsi+0x5c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_265a:
	/* 0x265a: cmp    r13,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 89ULL);
x86_l_265e:
	/* 0x265e: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_2660:
	/* 0x2660: lea    eax,[r13+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_2667:
	/* 0x2667: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_266c:
	/* 0x266c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2670:
	/* 0x2670: mov    BYTE PTR [rsi+0x5d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_2673:
	/* 0x2673: cmp    r13,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 90ULL);
x86_l_2677:
	/* 0x2677: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_2679:
	/* 0x2679: lea    eax,[r13+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_2680:
	/* 0x2680: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2685:
	/* 0x2685: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2689:
	/* 0x2689: mov    BYTE PTR [rsi+0x5e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_268c:
	/* 0x268c: cmp    r13,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 91ULL);
x86_l_2690:
	/* 0x2690: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_2692:
	/* 0x2692: lea    eax,[r13+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_2699:
	/* 0x2699: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_269e:
	/* 0x269e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_26a2:
	/* 0x26a2: mov    BYTE PTR [rsi+0x5f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_26a5:
	/* 0x26a5: cmp    r13d,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 92ULL);
x86_l_26a9:
	/* 0x26a9: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_26ab:
	/* 0x26ab: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_26ae:
	/* 0x26ae: add    eax,0xfa3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4003ULL);
x86_l_26b3:
	/* 0x26b3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26b8:
	/* 0x26b8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_26bc:
	/* 0x26bc: mov    BYTE PTR [rsi+0x60],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_26bf:
	/* 0x26bf: cmp    r13d,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 93ULL);
x86_l_26c3:
	/* 0x26c3: je     26d8 <generic_retkprobe_filter_arg_2+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_26c5:
	/* 0x26c5: lea    eax,[r13+0xfa2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4002ULL);
x86_l_26cc:
	/* 0x26cc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26d1:
	/* 0x26d1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_26d5:
	/* 0x26d5: mov    BYTE PTR [rsi+0x61],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_26d8:
	/* 0x26d8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26dd:
	/* 0x26dd: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26e2:
	/* 0x26e2: jmp    30f9 <generic_retkprobe_filter_arg_2+0x30f9> */
	return 12537ULL;
x86_l_26e7:
	/* 0x26e7: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26ec:
	/* 0x26ec: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26f0:
	/* 0x26f0: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26f3:
	/* 0x26f3: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_26f7:
	/* 0x26f7: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_26ff:
	/* 0x26ff: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_2706:
	/* 0x2706: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_270b:
	/* 0x270b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2710:
	/* 0x2710: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2712:
	/* 0x2712: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_2715:
	/* 0x2715: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2718:
	/* 0x2718: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_271b:
	/* 0x271b: je     310a <generic_retkprobe_filter_arg_2+0x310a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12554ULL;
	}
x86_l_2721:
	/* 0x2721: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2726:
	/* 0x2726: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2729:
	/* 0x2729: je     310a <generic_retkprobe_filter_arg_2+0x310a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12554ULL;
	}
x86_l_272f:
	/* 0x272f: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_2736:
	/* 0x2736: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_273b:
	/* 0x273b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2740:
	/* 0x2740: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2742:
	/* 0x2742: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2745:
	/* 0x2745: je     3107 <generic_retkprobe_filter_arg_2+0x3107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12551ULL;
	}
x86_l_274b:
	/* 0x274b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2750:
	/* 0x2750: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2754:
	/* 0x2754: cmp    r13d,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 255ULL);
x86_l_275b:
	/* 0x275b: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_2760:
	/* 0x2760: cmovb  esi,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_2764:
	/* 0x2764: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_276b:
	/* 0x276b: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_276d:
	/* 0x276d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2770:
	/* 0x2770: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2774:
	/* 0x2774: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2777:
	/* 0x2777: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_277c:
	/* 0x277c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_277e:
	/* 0x277e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2783:
	/* 0x2783: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2788:
	/* 0x2788: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_278b:
	/* 0x278b: jmp    30f9 <generic_retkprobe_filter_arg_2+0x30f9> */
	return 12537ULL;
x86_l_2790:
	/* 0x2790: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_2793:
	/* 0x2793: je     27a5 <generic_retkprobe_filter_arg_2+0x27a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27a5;
	}
x86_l_2795:
	/* 0x2795: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_2798:
	/* 0x2798: jne    31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12747ULL;
	}
x86_l_279e:
	/* 0x279e: movzx  edi,WORD PTR [r8+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_27a3:
	/* 0x27a3: jmp    27aa <generic_retkprobe_filter_arg_2+0x27aa> */
	goto x86_l_27aa;
x86_l_27a5:
	/* 0x27a5: movzx  edi,WORD PTR [r8+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_27aa:
	/* 0x27aa: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27ac:
	/* 0x27ac: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27af:
	/* 0x27af: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27b2:
	/* 0x27b2: jmp    27fa <generic_retkprobe_filter_arg_2+0x27fa> */
	goto x86_l_27fa;
x86_l_27b4:
	/* 0x27b4: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_27b7:
	/* 0x27b7: je     2c18 <generic_retkprobe_filter_arg_2+0x2c18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11288ULL;
	}
x86_l_27bd:
	/* 0x27bd: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_27c0:
	/* 0x27c0: jne    31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12747ULL;
	}
x86_l_27c6:
	/* 0x27c6: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_27c9:
	/* 0x27c9: jne    2de4 <generic_retkprobe_filter_arg_2+0x2de4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11748ULL;
	}
x86_l_27cf:
	/* 0x27cf: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_27d2:
	/* 0x27d2: jne    2df1 <generic_retkprobe_filter_arg_2+0x2df1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11761ULL;
	}
x86_l_27d8:
	/* 0x27d8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27db:
	/* 0x27db: jmp    2e00 <generic_retkprobe_filter_arg_2+0x2e00> */
	return 11776ULL;
x86_l_27e0:
	/* 0x27e0: mov    rdx,QWORD PTR [r8+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27e4:
	/* 0x27e4: mov    r9,QWORD PTR [r8+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27e8:
	/* 0x27e8: jmp    27f1 <generic_retkprobe_filter_arg_2+0x27f1> */
	goto x86_l_27f1;
x86_l_27ea:
	/* 0x27ea: mov    rdx,QWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27ed:
	/* 0x27ed: mov    r9,QWORD PTR [r8+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27f1:
	/* 0x27f1: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_27f4:
	/* 0x27f4: shr    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_27f8:
	/* 0x27f8: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27fa:
	/* 0x27fa: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27fd:
	/* 0x27fd: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2800:
	/* 0x2800: jg     2824 <generic_retkprobe_filter_arg_2+0x2824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2824;
	}
x86_l_2802:
	/* 0x2802: lea    ecx,[rax-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_2805:
	/* 0x2805: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2808:
	/* 0x2808: jb     284f <generic_retkprobe_filter_arg_2+0x284f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_284f;
	}
x86_l_280a:
	/* 0x280a: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_280d:
	/* 0x280d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2810:
	/* 0x2810: jb     28b0 <generic_retkprobe_filter_arg_2+0x28b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_28b0;
	}
x86_l_2816:
	/* 0x2816: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2819:
	/* 0x2819: je     2c1d <generic_retkprobe_filter_arg_2+0x2c1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11293ULL;
	}
x86_l_281f:
	/* 0x281f: jmp    31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	return 12747ULL;
x86_l_2824:
	/* 0x2824: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2827:
	/* 0x2827: ja     28a4 <generic_retkprobe_filter_arg_2+0x28a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28a4;
	}
x86_l_2829:
	/* 0x2829: mov    ecx,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5242880ULL);
x86_l_282e:
	/* 0x282e: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2831:
	/* 0x2831: jb     29e9 <generic_retkprobe_filter_arg_2+0x29e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_29e9;
	}
x86_l_2837:
	/* 0x2837: mov    ecx,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10485760ULL);
x86_l_283c:
	/* 0x283c: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_283f:
	/* 0x283f: jb     29fd <generic_retkprobe_filter_arg_2+0x29fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_29fd;
	}
x86_l_2845:
	/* 0x2845: mov    ecx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 50331648ULL);
x86_l_284a:
	/* 0x284a: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_284d:
	/* 0x284d: jae    28a4 <generic_retkprobe_filter_arg_2+0x28a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_28a4;
	}
x86_l_284f:
	/* 0x284f: movzx  eax,WORD PTR [r8+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2854:
	/* 0x2854: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_2857:
	/* 0x2857: je     2a11 <generic_retkprobe_filter_arg_2+0x2a11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a11;
	}
x86_l_285d:
	/* 0x285d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2860:
	/* 0x2860: jne    2a9d <generic_retkprobe_filter_arg_2+0x2a9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10909ULL;
	}
x86_l_2866:
	/* 0x2866: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_2869:
	/* 0x2869: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_286c:
	/* 0x286c: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_286f:
	/* 0x286f: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2873:
	/* 0x2873: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_287a:
	/* 0x287a: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_287f:
	/* 0x287f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2884:
	/* 0x2884: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2886:
	/* 0x2886: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2889:
	/* 0x2889: je     2c92 <generic_retkprobe_filter_arg_2+0x2c92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11410ULL;
	}
x86_l_288f:
	/* 0x288f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2892:
	/* 0x2892: mov    DWORD PTR [rsp+0x20],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953504ULL);
x86_l_289a:
	/* 0x289a: mov    DWORD PTR [rsp+0x24],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_289f:
	/* 0x289f: jmp    2a69 <generic_retkprobe_filter_arg_2+0x2a69> */
	return 10857ULL;
x86_l_28a4:
	/* 0x28a4: add    eax,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_28a7:
	/* 0x28a7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_28aa:
	/* 0x28aa: jae    31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12747ULL;
	}
x86_l_28b0:
	/* 0x28b0: mov    r13d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_32);
x86_l_28b3:
	/* 0x28b3: movzx  eax,BYTE PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_28b7:
	/* 0x28b7: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_28bb:
	/* 0x28bb: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_28c2:
	/* 0x28c2: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_28c5:
	/* 0x28c5: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_28ca:
	/* 0x28ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28cf:
	/* 0x28cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28d1:
	/* 0x28d1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28d4:
	/* 0x28d4: je     2e3d <generic_retkprobe_filter_arg_2+0x2e3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11837ULL;
	}
x86_l_28da:
	/* 0x28da: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_28dd:
	/* 0x28dd: movzx  eax,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_28e1:
	/* 0x28e1: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28e6:
	/* 0x28e6: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28eb:
	/* 0x28eb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28f0:
	/* 0x28f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28f2:
	/* 0x28f2: mov    edx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_28f7:
	/* 0x28f7: jmp    2c60 <generic_retkprobe_filter_arg_2+0x2c60> */
	return 11360ULL;
x86_l_28fc:
	/* 0x28fc: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2901:
	/* 0x2901: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2905:
	/* 0x2905: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2908:
	/* 0x2908: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_290c:
	/* 0x290c: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2914:
	/* 0x2914: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_291b:
	/* 0x291b: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2920:
	/* 0x2920: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2925:
	/* 0x2925: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2927:
	/* 0x2927: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_292a:
	/* 0x292a: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2930:
	/* 0x2930: je     31a9 <generic_retkprobe_filter_arg_2+0x31a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12713ULL;
	}
x86_l_2936:
	/* 0x2936: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2939:
	/* 0x2939: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_293c:
	/* 0x293c: je     31a9 <generic_retkprobe_filter_arg_2+0x31a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12713ULL;
	}
x86_l_2942:
	/* 0x2942: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_2949:
	/* 0x2949: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_294e:
	/* 0x294e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2953:
	/* 0x2953: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2955:
	/* 0x2955: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2958:
	/* 0x2958: je     31a6 <generic_retkprobe_filter_arg_2+0x31a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12710ULL;
	}
x86_l_295e:
	/* 0x295e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2963:
	/* 0x2963: cmp    ecx,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_2969:
	/* 0x2969: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_296e:
	/* 0x296e: cmovb  esi,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2971:
	/* 0x2971: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_2978:
	/* 0x2978: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_297a:
	/* 0x297a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_297d:
	/* 0x297d: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2981:
	/* 0x2981: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2984:
	/* 0x2984: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2989:
	/* 0x2989: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_298e:
	/* 0x298e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2990:
	/* 0x2990: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2995:
	/* 0x2995: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2998:
	/* 0x2998: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_299b:
	/* 0x299b: jmp    3198 <generic_retkprobe_filter_arg_2+0x3198> */
	return 12696ULL;
x86_l_29a0:
	/* 0x29a0: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_29a8:
	/* 0x29a8: cmp    edx,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_29ae:
	/* 0x29ae: ja     2c10 <generic_retkprobe_filter_arg_2+0x2c10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11280ULL;
	}
x86_l_29b4:
	/* 0x29b4: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29b9:
	/* 0x29b9: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29bd:
	/* 0x29bd: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_29c0:
	/* 0x29c0: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_29c6:
	/* 0x29c6: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_29c9:
	/* 0x29c9: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_29cc:
	/* 0x29cc: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_29cf:
	/* 0x29cf: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_29d1:
	/* 0x29d1: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_29d3:
	/* 0x29d3: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_29d6:
	/* 0x29d6: je     2e45 <generic_retkprobe_filter_arg_2+0x2e45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11845ULL;
	}
x86_l_29dc:
	/* 0x29dc: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_29de:
	/* 0x29de: jne    2e45 <generic_retkprobe_filter_arg_2+0x2e45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11845ULL;
	}
x86_l_29e4:
	/* 0x29e4: jmp    2e5c <generic_retkprobe_filter_arg_2+0x2e5c> */
	return 11868ULL;
x86_l_29e9:
	/* 0x29e9: movzx  eax,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_29ec:
	/* 0x29ec: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29ef:
	/* 0x29ef: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_29f4:
	/* 0x29f4: setb   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_B);
x86_l_29f8:
	/* 0x29f8: jmp    31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	return 12747ULL;
x86_l_29fd:
	/* 0x29fd: movzx  eax,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2a00:
	/* 0x2a00: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a03:
	/* 0x2a03: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_2a08:
	/* 0x2a08: setae  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_AE);
x86_l_2a0c:
	/* 0x2a0c: jmp    31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	return 12747ULL;
x86_l_2a11:
	/* 0x2a11: mov    QWORD PTR [rsp+0x10],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a16:
	/* 0x2a16: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a1a:
	/* 0x2a1a: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_2a1d:
	/* 0x2a1d: mov    eax,DWORD PTR [rsi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2a20:
	/* 0x2a20: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2a24:
	/* 0x2a24: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_2a2b:
	/* 0x2a2b: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2a30:
	/* 0x2a30: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a35:
	/* 0x2a35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a37:
	/* 0x2a37: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a3a:
	/* 0x2a3a: je     2c92 <generic_retkprobe_filter_arg_2+0x2c92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11410ULL;
	}
x86_l_2a40:
	/* 0x2a40: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2a43:
	/* 0x2a43: mov    DWORD PTR [rsp+0x20],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953600ULL);
x86_l_2a4b:
	/* 0x2a4b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a4f:
	/* 0x2a4f: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2a53:
	/* 0x2a53: mov    DWORD PTR [rsp+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a58:
	/* 0x2a58: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a5d:
	/* 0x2a5d: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2a61:
	/* 0x2a61: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
	return 10853ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_generic_retkprobe_filter_arg_2_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10853ULL: goto x86_l_2a65;
	case 10857ULL: goto x86_l_2a69;
	case 10862ULL: goto x86_l_2a6e;
	case 10867ULL: goto x86_l_2a73;
	case 10869ULL: goto x86_l_2a75;
	case 10874ULL: goto x86_l_2a7a;
	case 10877ULL: goto x86_l_2a7d;
	case 10880ULL: goto x86_l_2a80;
	case 10886ULL: goto x86_l_2a86;
	case 10889ULL: goto x86_l_2a89;
	case 10892ULL: goto x86_l_2a8c;
	case 10894ULL: goto x86_l_2a8e;
	case 10897ULL: goto x86_l_2a91;
	case 10900ULL: goto x86_l_2a94;
	case 10904ULL: goto x86_l_2a98;
	case 10909ULL: goto x86_l_2a9d;
	case 10911ULL: goto x86_l_2a9f;
	case 10915ULL: goto x86_l_2aa3;
	case 10920ULL: goto x86_l_2aa8;
	case 10923ULL: goto x86_l_2aab;
	case 10928ULL: goto x86_l_2ab0;
	case 10932ULL: goto x86_l_2ab4;
	case 10938ULL: goto x86_l_2aba;
	case 10941ULL: goto x86_l_2abd;
	case 10944ULL: goto x86_l_2ac0;
	case 10947ULL: goto x86_l_2ac3;
	case 10950ULL: goto x86_l_2ac6;
	case 10952ULL: goto x86_l_2ac8;
	case 10956ULL: goto x86_l_2acc;
	case 10962ULL: goto x86_l_2ad2;
	case 10964ULL: goto x86_l_2ad4;
	case 10970ULL: goto x86_l_2ada;
	case 10973ULL: goto x86_l_2add;
	case 10978ULL: goto x86_l_2ae2;
	case 10981ULL: goto x86_l_2ae5;
	case 10984ULL: goto x86_l_2ae8;
	case 10986ULL: goto x86_l_2aea;
	case 10988ULL: goto x86_l_2aec;
	case 10991ULL: goto x86_l_2aef;
	case 10996ULL: goto x86_l_2af4;
	case 11000ULL: goto x86_l_2af8;
	case 11002ULL: goto x86_l_2afa;
	case 11006ULL: goto x86_l_2afe;
	case 11012ULL: goto x86_l_2b04;
	case 11015ULL: goto x86_l_2b07;
	case 11017ULL: goto x86_l_2b09;
	case 11021ULL: goto x86_l_2b0d;
	case 11026ULL: goto x86_l_2b12;
	case 11031ULL: goto x86_l_2b17;
	case 11035ULL: goto x86_l_2b1b;
	case 11038ULL: goto x86_l_2b1e;
	case 11042ULL: goto x86_l_2b22;
	case 11046ULL: goto x86_l_2b26;
	case 11049ULL: goto x86_l_2b29;
	case 11055ULL: goto x86_l_2b2f;
	case 11059ULL: goto x86_l_2b33;
	case 11066ULL: goto x86_l_2b3a;
	case 11071ULL: goto x86_l_2b3f;
	case 11076ULL: goto x86_l_2b44;
	case 11079ULL: goto x86_l_2b47;
	case 11081ULL: goto x86_l_2b49;
	case 11084ULL: goto x86_l_2b4c;
	case 11091ULL: goto x86_l_2b53;
	case 11096ULL: goto x86_l_2b58;
	case 11099ULL: goto x86_l_2b5b;
	case 11101ULL: goto x86_l_2b5d;
	case 11104ULL: goto x86_l_2b60;
	case 11109ULL: goto x86_l_2b65;
	case 11112ULL: goto x86_l_2b68;
	case 11118ULL: goto x86_l_2b6e;
	case 11121ULL: goto x86_l_2b71;
	case 11125ULL: goto x86_l_2b75;
	case 11131ULL: goto x86_l_2b7b;
	case 11134ULL: goto x86_l_2b7e;
	case 11139ULL: goto x86_l_2b83;
	case 11144ULL: goto x86_l_2b88;
	case 11147ULL: goto x86_l_2b8b;
	case 11151ULL: goto x86_l_2b8f;
	case 11156ULL: goto x86_l_2b94;
	case 11161ULL: goto x86_l_2b99;
	case 11164ULL: goto x86_l_2b9c;
	case 11166ULL: goto x86_l_2b9e;
	case 11171ULL: goto x86_l_2ba3;
	case 11174ULL: goto x86_l_2ba6;
	case 11176ULL: goto x86_l_2ba8;
	case 11181ULL: goto x86_l_2bad;
	case 11185ULL: goto x86_l_2bb1;
	case 11188ULL: goto x86_l_2bb4;
	case 11191ULL: goto x86_l_2bb7;
	case 11197ULL: goto x86_l_2bbd;
	case 11202ULL: goto x86_l_2bc2;
	case 11205ULL: goto x86_l_2bc5;
	case 11207ULL: goto x86_l_2bc7;
	case 11211ULL: goto x86_l_2bcb;
	case 11215ULL: goto x86_l_2bcf;
	case 11219ULL: goto x86_l_2bd3;
	case 11222ULL: goto x86_l_2bd6;
	case 11228ULL: goto x86_l_2bdc;
	case 11230ULL: goto x86_l_2bde;
	case 11236ULL: goto x86_l_2be4;
	case 11241ULL: goto x86_l_2be9;
	case 11247ULL: goto x86_l_2bef;
	case 11252ULL: goto x86_l_2bf4;
	case 11258ULL: goto x86_l_2bfa;
	case 11265ULL: goto x86_l_2c01;
	case 11270ULL: goto x86_l_2c06;
	case 11275ULL: goto x86_l_2c0b;
	case 11280ULL: goto x86_l_2c10;
	case 11283ULL: goto x86_l_2c13;
	case 11288ULL: goto x86_l_2c18;
	case 11293ULL: goto x86_l_2c1d;
	case 11297ULL: goto x86_l_2c21;
	case 11301ULL: goto x86_l_2c25;
	case 11308ULL: goto x86_l_2c2c;
	case 11311ULL: goto x86_l_2c2f;
	case 11316ULL: goto x86_l_2c34;
	case 11321ULL: goto x86_l_2c39;
	case 11323ULL: goto x86_l_2c3b;
	case 11326ULL: goto x86_l_2c3e;
	case 11332ULL: goto x86_l_2c44;
	case 11335ULL: goto x86_l_2c47;
	case 11339ULL: goto x86_l_2c4b;
	case 11344ULL: goto x86_l_2c50;
	case 11349ULL: goto x86_l_2c55;
	case 11354ULL: goto x86_l_2c5a;
	case 11356ULL: goto x86_l_2c5c;
	case 11360ULL: goto x86_l_2c60;
	case 11362ULL: goto x86_l_2c62;
	case 11365ULL: goto x86_l_2c65;
	case 11367ULL: goto x86_l_2c67;
	case 11372ULL: goto x86_l_2c6c;
	case 11375ULL: goto x86_l_2c6f;
	case 11377ULL: goto x86_l_2c71;
	case 11380ULL: goto x86_l_2c74;
	case 11383ULL: goto x86_l_2c77;
	case 11385ULL: goto x86_l_2c79;
	case 11390ULL: goto x86_l_2c7e;
	case 11393ULL: goto x86_l_2c81;
	case 11395ULL: goto x86_l_2c83;
	case 11398ULL: goto x86_l_2c86;
	case 11401ULL: goto x86_l_2c89;
	case 11405ULL: goto x86_l_2c8d;
	case 11410ULL: goto x86_l_2c92;
	case 11415ULL: goto x86_l_2c97;
	case 11418ULL: goto x86_l_2c9a;
	case 11421ULL: goto x86_l_2c9d;
	case 11423ULL: goto x86_l_2c9f;
	case 11426ULL: goto x86_l_2ca2;
	case 11429ULL: goto x86_l_2ca5;
	case 11433ULL: goto x86_l_2ca9;
	case 11438ULL: goto x86_l_2cae;
	case 11441ULL: goto x86_l_2cb1;
	case 11444ULL: goto x86_l_2cb4;
	case 11446ULL: goto x86_l_2cb6;
	case 11448ULL: goto x86_l_2cb8;
	case 11451ULL: goto x86_l_2cbb;
	case 11456ULL: goto x86_l_2cc0;
	case 11460ULL: goto x86_l_2cc4;
	case 11462ULL: goto x86_l_2cc6;
	case 11465ULL: goto x86_l_2cc9;
	case 11471ULL: goto x86_l_2ccf;
	case 11474ULL: goto x86_l_2cd2;
	case 11476ULL: goto x86_l_2cd4;
	case 11480ULL: goto x86_l_2cd8;
	case 11485ULL: goto x86_l_2cdd;
	case 11490ULL: goto x86_l_2ce2;
	case 11494ULL: goto x86_l_2ce6;
	case 11497ULL: goto x86_l_2ce9;
	case 11501ULL: goto x86_l_2ced;
	case 11505ULL: goto x86_l_2cf1;
	case 11509ULL: goto x86_l_2cf5;
	case 11512ULL: goto x86_l_2cf8;
	case 11518ULL: goto x86_l_2cfe;
	case 11525ULL: goto x86_l_2d05;
	case 11530ULL: goto x86_l_2d0a;
	case 11535ULL: goto x86_l_2d0f;
	case 11538ULL: goto x86_l_2d12;
	case 11540ULL: goto x86_l_2d14;
	case 11543ULL: goto x86_l_2d17;
	case 11550ULL: goto x86_l_2d1e;
	case 11555ULL: goto x86_l_2d23;
	case 11558ULL: goto x86_l_2d26;
	case 11560ULL: goto x86_l_2d28;
	case 11563ULL: goto x86_l_2d2b;
	case 11568ULL: goto x86_l_2d30;
	case 11571ULL: goto x86_l_2d33;
	case 11577ULL: goto x86_l_2d39;
	case 11580ULL: goto x86_l_2d3c;
	case 11584ULL: goto x86_l_2d40;
	case 11590ULL: goto x86_l_2d46;
	case 11593ULL: goto x86_l_2d49;
	case 11598ULL: goto x86_l_2d4e;
	case 11602ULL: goto x86_l_2d52;
	case 11607ULL: goto x86_l_2d57;
	case 11612ULL: goto x86_l_2d5c;
	case 11615ULL: goto x86_l_2d5f;
	case 11619ULL: goto x86_l_2d63;
	case 11624ULL: goto x86_l_2d68;
	case 11627ULL: goto x86_l_2d6b;
	case 11629ULL: goto x86_l_2d6d;
	case 11634ULL: goto x86_l_2d72;
	case 11637ULL: goto x86_l_2d75;
	case 11639ULL: goto x86_l_2d77;
	case 11644ULL: goto x86_l_2d7c;
	case 11649ULL: goto x86_l_2d81;
	case 11653ULL: goto x86_l_2d85;
	case 11656ULL: goto x86_l_2d88;
	case 11658ULL: goto x86_l_2d8a;
	case 11664ULL: goto x86_l_2d90;
	case 11669ULL: goto x86_l_2d95;
	case 11672ULL: goto x86_l_2d98;
	case 11674ULL: goto x86_l_2d9a;
	case 11678ULL: goto x86_l_2d9e;
	case 11682ULL: goto x86_l_2da2;
	case 11687ULL: goto x86_l_2da7;
	case 11693ULL: goto x86_l_2dad;
	case 11698ULL: goto x86_l_2db2;
	case 11704ULL: goto x86_l_2db8;
	case 11709ULL: goto x86_l_2dbd;
	case 11715ULL: goto x86_l_2dc3;
	case 11720ULL: goto x86_l_2dc8;
	case 11726ULL: goto x86_l_2dce;
	case 11733ULL: goto x86_l_2dd5;
	case 11738ULL: goto x86_l_2dda;
	case 11743ULL: goto x86_l_2ddf;
	case 11748ULL: goto x86_l_2de4;
	case 11751ULL: goto x86_l_2de7;
	case 11754ULL: goto x86_l_2dea;
	case 11756ULL: goto x86_l_2dec;
	case 11759ULL: goto x86_l_2def;
	case 11761ULL: goto x86_l_2df1;
	case 11766ULL: goto x86_l_2df6;
	case 11769ULL: goto x86_l_2df9;
	case 11771ULL: goto x86_l_2dfb;
	case 11774ULL: goto x86_l_2dfe;
	case 11776ULL: goto x86_l_2e00;
	case 11779ULL: goto x86_l_2e03;
	case 11783ULL: goto x86_l_2e07;
	case 11787ULL: goto x86_l_2e0b;
	case 11794ULL: goto x86_l_2e12;
	case 11799ULL: goto x86_l_2e17;
	case 11804ULL: goto x86_l_2e1c;
	case 11806ULL: goto x86_l_2e1e;
	case 11809ULL: goto x86_l_2e21;
	case 11811ULL: goto x86_l_2e23;
	case 11814ULL: goto x86_l_2e26;
	case 11817ULL: goto x86_l_2e29;
	case 11822ULL: goto x86_l_2e2e;
	case 11827ULL: goto x86_l_2e33;
	case 11832ULL: goto x86_l_2e38;
	case 11837ULL: goto x86_l_2e3d;
	case 11840ULL: goto x86_l_2e40;
	case 11845ULL: goto x86_l_2e45;
	case 11848ULL: goto x86_l_2e48;
	case 11850ULL: goto x86_l_2e4a;
	case 11852ULL: goto x86_l_2e4c;
	case 11854ULL: goto x86_l_2e4e;
	case 11857ULL: goto x86_l_2e51;
	case 11862ULL: goto x86_l_2e56;
	case 11866ULL: goto x86_l_2e5a;
	case 11868ULL: goto x86_l_2e5c;
	case 11871ULL: goto x86_l_2e5f;
	case 11877ULL: goto x86_l_2e65;
	case 11880ULL: goto x86_l_2e68;
	case 11882ULL: goto x86_l_2e6a;
	case 11886ULL: goto x86_l_2e6e;
	case 11890ULL: goto x86_l_2e72;
	case 11893ULL: goto x86_l_2e75;
	case 11897ULL: goto x86_l_2e79;
	case 11901ULL: goto x86_l_2e7d;
	case 11905ULL: goto x86_l_2e81;
	case 11908ULL: goto x86_l_2e84;
	case 11914ULL: goto x86_l_2e8a;
	case 11921ULL: goto x86_l_2e91;
	case 11926ULL: goto x86_l_2e96;
	case 11931ULL: goto x86_l_2e9b;
	case 11934ULL: goto x86_l_2e9e;
	case 11936ULL: goto x86_l_2ea0;
	case 11939ULL: goto x86_l_2ea3;
	case 11946ULL: goto x86_l_2eaa;
	case 11951ULL: goto x86_l_2eaf;
	case 11954ULL: goto x86_l_2eb2;
	case 11956ULL: goto x86_l_2eb4;
	case 11964ULL: goto x86_l_2ebc;
	case 11967ULL: goto x86_l_2ebf;
	case 11972ULL: goto x86_l_2ec4;
	case 11975ULL: goto x86_l_2ec7;
	case 11981ULL: goto x86_l_2ecd;
	case 11990ULL: goto x86_l_2ed6;
	case 11994ULL: goto x86_l_2eda;
	case 12000ULL: goto x86_l_2ee0;
	case 12005ULL: goto x86_l_2ee5;
	case 12010ULL: goto x86_l_2eea;
	case 12013ULL: goto x86_l_2eed;
	case 12017ULL: goto x86_l_2ef1;
	case 12022ULL: goto x86_l_2ef6;
	case 12027ULL: goto x86_l_2efb;
	case 12030ULL: goto x86_l_2efe;
	case 12032ULL: goto x86_l_2f00;
	case 12037ULL: goto x86_l_2f05;
	case 12040ULL: goto x86_l_2f08;
	case 12042ULL: goto x86_l_2f0a;
	case 12047ULL: goto x86_l_2f0f;
	case 12052ULL: goto x86_l_2f14;
	case 12056ULL: goto x86_l_2f18;
	case 12059ULL: goto x86_l_2f1b;
	case 12061ULL: goto x86_l_2f1d;
	case 12067ULL: goto x86_l_2f23;
	case 12072ULL: goto x86_l_2f28;
	case 12080ULL: goto x86_l_2f30;
	case 12082ULL: goto x86_l_2f32;
	case 12086ULL: goto x86_l_2f36;
	case 12090ULL: goto x86_l_2f3a;
	case 12095ULL: goto x86_l_2f3f;
	case 12101ULL: goto x86_l_2f45;
	case 12106ULL: goto x86_l_2f4a;
	case 12112ULL: goto x86_l_2f50;
	case 12117ULL: goto x86_l_2f55;
	case 12123ULL: goto x86_l_2f5b;
	case 12128ULL: goto x86_l_2f60;
	case 12134ULL: goto x86_l_2f66;
	case 12141ULL: goto x86_l_2f6d;
	case 12146ULL: goto x86_l_2f72;
	case 12151ULL: goto x86_l_2f77;
	case 12156ULL: goto x86_l_2f7c;
	case 12159ULL: goto x86_l_2f7f;
	case 12165ULL: goto x86_l_2f85;
	case 12170ULL: goto x86_l_2f8a;
	case 12176ULL: goto x86_l_2f90;
	case 12181ULL: goto x86_l_2f95;
	case 12187ULL: goto x86_l_2f9b;
	case 12194ULL: goto x86_l_2fa2;
	case 12199ULL: goto x86_l_2fa7;
	case 12204ULL: goto x86_l_2fac;
	case 12209ULL: goto x86_l_2fb1;
	case 12212ULL: goto x86_l_2fb4;
	case 12215ULL: goto x86_l_2fb7;
	case 12220ULL: goto x86_l_2fbc;
	case 12225ULL: goto x86_l_2fc1;
	case 12231ULL: goto x86_l_2fc7;
	case 12236ULL: goto x86_l_2fcc;
	case 12242ULL: goto x86_l_2fd2;
	case 12247ULL: goto x86_l_2fd7;
	case 12253ULL: goto x86_l_2fdd;
	case 12260ULL: goto x86_l_2fe4;
	case 12265ULL: goto x86_l_2fe9;
	case 12270ULL: goto x86_l_2fee;
	case 12275ULL: goto x86_l_2ff3;
	case 12280ULL: goto x86_l_2ff8;
	case 12286ULL: goto x86_l_2ffe;
	case 12291ULL: goto x86_l_3003;
	case 12297ULL: goto x86_l_3009;
	case 12302ULL: goto x86_l_300e;
	case 12308ULL: goto x86_l_3014;
	case 12315ULL: goto x86_l_301b;
	case 12320ULL: goto x86_l_3020;
	case 12325ULL: goto x86_l_3025;
	case 12330ULL: goto x86_l_302a;
	case 12337ULL: goto x86_l_3031;
	case 12342ULL: goto x86_l_3036;
	case 12347ULL: goto x86_l_303b;
	case 12349ULL: goto x86_l_303d;
	case 12356ULL: goto x86_l_3044;
	case 12361ULL: goto x86_l_3049;
	case 12366ULL: goto x86_l_304e;
	case 12368ULL: goto x86_l_3050;
	case 12375ULL: goto x86_l_3057;
	case 12380ULL: goto x86_l_305c;
	case 12385ULL: goto x86_l_3061;
	case 12387ULL: goto x86_l_3063;
	case 12394ULL: goto x86_l_306a;
	case 12399ULL: goto x86_l_306f;
	case 12404ULL: goto x86_l_3074;
	case 12409ULL: goto x86_l_3079;
	case 12411ULL: goto x86_l_307b;
	case 12414ULL: goto x86_l_307e;
	case 12420ULL: goto x86_l_3084;
	case 12423ULL: goto x86_l_3087;
	case 12428ULL: goto x86_l_308c;
	case 12433ULL: goto x86_l_3091;
	case 12438ULL: goto x86_l_3096;
	case 12445ULL: goto x86_l_309d;
	case 12450ULL: goto x86_l_30a2;
	case 12455ULL: goto x86_l_30a7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a65:
	/* 0x2a65: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a69:
	/* 0x2a69: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a6e:
	/* 0x2a6e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a73:
	/* 0x2a73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a75:
	/* 0x2a75: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2a7a:
	/* 0x2a7a: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_2a7d:
	/* 0x2a7d: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2a80:
	/* 0x2a80: jb     2c9f <generic_retkprobe_filter_arg_2+0x2c9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2c9f;
	}
x86_l_2a86:
	/* 0x2a86: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_2a89:
	/* 0x2a89: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2a8c:
	/* 0x2a8c: ja     2a9d <generic_retkprobe_filter_arg_2+0x2a9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2a9d;
	}
x86_l_2a8e:
	/* 0x2a8e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a91:
	/* 0x2a91: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_2a94:
	/* 0x2a94: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2a98:
	/* 0x2a98: jmp    31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	return 12747ULL;
x86_l_2a9d:
	/* 0x2a9d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a9f:
	/* 0x2a9f: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2aa3:
	/* 0x2aa3: jmp    31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	return 12747ULL;
x86_l_2aa8:
	/* 0x2aa8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2aab:
	/* 0x2aab: jmp    3111 <generic_retkprobe_filter_arg_2+0x3111> */
	return 12561ULL;
x86_l_2ab0:
	/* 0x2ab0: movzx  eax,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2ab4:
	/* 0x2ab4: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2aba:
	/* 0x2aba: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_2abd:
	/* 0x2abd: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_2ac0:
	/* 0x2ac0: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2ac3:
	/* 0x2ac3: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_2ac6:
	/* 0x2ac6: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2ac8:
	/* 0x2ac8: test   r13w,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_16);
x86_l_2acc:
	/* 0x2acc: je     2cae <generic_retkprobe_filter_arg_2+0x2cae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cae;
	}
x86_l_2ad2:
	/* 0x2ad2: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2ad4:
	/* 0x2ad4: jne    2cae <generic_retkprobe_filter_arg_2+0x2cae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cae;
	}
x86_l_2ada:
	/* 0x2ada: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_2add:
	/* 0x2add: jmp    2cc6 <generic_retkprobe_filter_arg_2+0x2cc6> */
	goto x86_l_2cc6;
x86_l_2ae2:
	/* 0x2ae2: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2ae5:
	/* 0x2ae5: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_2ae8:
	/* 0x2ae8: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2aea:
	/* 0x2aea: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_2aec:
	/* 0x2aec: add    edi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2aef:
	/* 0x2aef: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2af4:
	/* 0x2af4: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2af8:
	/* 0x2af8: ja     2b09 <generic_retkprobe_filter_arg_2+0x2b09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b09;
	}
x86_l_2afa:
	/* 0x2afa: movzx  eax,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2afe:
	/* 0x2afe: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2b04:
	/* 0x2b04: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2b07:
	/* 0x2b07: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2b09:
	/* 0x2b09: mov    DWORD PTR [rsp+0x4c],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2b0d:
	/* 0x2b0d: mov    QWORD PTR [rsp+0x38],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b12:
	/* 0x2b12: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b17:
	/* 0x2b17: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b1b:
	/* 0x2b1b: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2b1e:
	/* 0x2b1e: mov    eax,DWORD PTR [rsi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2b22:
	/* 0x2b22: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b26:
	/* 0x2b26: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2b29:
	/* 0x2b29: je     2c10 <generic_retkprobe_filter_arg_2+0x2c10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c10;
	}
x86_l_2b2f:
	/* 0x2b2f: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b33:
	/* 0x2b33: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2b3a:
	/* 0x2b3a: lea    r12,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b3f:
	/* 0x2b3f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b44:
	/* 0x2b44: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2b47:
	/* 0x2b47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b49:
	/* 0x2b49: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2b4c:
	/* 0x2b4c: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2b53:
	/* 0x2b53: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b58:
	/* 0x2b58: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2b5b:
	/* 0x2b5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b5d:
	/* 0x2b5d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b60:
	/* 0x2b60: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b65:
	/* 0x2b65: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2b68:
	/* 0x2b68: je     31a9 <generic_retkprobe_filter_arg_2+0x31a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12713ULL;
	}
x86_l_2b6e:
	/* 0x2b6e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b71:
	/* 0x2b71: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b75:
	/* 0x2b75: je     31ad <generic_retkprobe_filter_arg_2+0x31ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12717ULL;
	}
x86_l_2b7b:
	/* 0x2b7b: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2b7e:
	/* 0x2b7e: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b83:
	/* 0x2b83: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b88:
	/* 0x2b88: mov    BYTE PTR [rax],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b8b:
	/* 0x2b8b: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2b8f:
	/* 0x2b8f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b94:
	/* 0x2b94: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b99:
	/* 0x2b99: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2b9c:
	/* 0x2b9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b9e:
	/* 0x2b9e: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_2ba3:
	/* 0x2ba3: cmp    esi,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2ba6:
	/* 0x2ba6: jbe    2bc7 <generic_retkprobe_filter_arg_2+0x2bc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2bc7;
	}
x86_l_2ba8:
	/* 0x2ba8: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bad:
	/* 0x2bad: lea    rdi,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2bb1:
	/* 0x2bb1: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2bb4:
	/* 0x2bb4: sub    esi,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2bb7:
	/* 0x2bb7: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2bbd:
	/* 0x2bbd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bc2:
	/* 0x2bc2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2bc5:
	/* 0x2bc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bc7:
	/* 0x2bc7: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2bcb:
	/* 0x2bcb: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2bcf:
	/* 0x2bcf: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bd3:
	/* 0x2bd3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2bd6:
	/* 0x2bd6: jg     2f7c <generic_retkprobe_filter_arg_2+0x2f7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2f7c;
	}
x86_l_2bdc:
	/* 0x2bdc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bde:
	/* 0x2bde: je     302a <generic_retkprobe_filter_arg_2+0x302a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_302a;
	}
x86_l_2be4:
	/* 0x2be4: cmp    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2be9:
	/* 0x2be9: je     3050 <generic_retkprobe_filter_arg_2+0x3050> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3050;
	}
x86_l_2bef:
	/* 0x2bef: cmp    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_2bf4:
	/* 0x2bf4: jne    31a6 <generic_retkprobe_filter_arg_2+0x31a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12710ULL;
	}
x86_l_2bfa:
	/* 0x2bfa: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2c01:
	/* 0x2c01: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c06:
	/* 0x2c06: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c0b:
	/* 0x2c0b: jmp    3074 <generic_retkprobe_filter_arg_2+0x3074> */
	goto x86_l_3074;
x86_l_2c10:
	/* 0x2c10: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c13:
	/* 0x2c13: jmp    31ad <generic_retkprobe_filter_arg_2+0x31ad> */
	return 12717ULL;
x86_l_2c18:
	/* 0x2c18: movzx  r12d,WORD PTR [r8+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2c1d:
	/* 0x2c1d: movzx  eax,BYTE PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2c21:
	/* 0x2c21: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2c25:
	/* 0x2c25: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2c2c:
	/* 0x2c2c: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_2c2f:
	/* 0x2c2f: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2c34:
	/* 0x2c34: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c39:
	/* 0x2c39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c3b:
	/* 0x2c3b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c3e:
	/* 0x2c3e: je     2e3d <generic_retkprobe_filter_arg_2+0x2e3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e3d;
	}
x86_l_2c44:
	/* 0x2c44: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2c47:
	/* 0x2c47: movzx  eax,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2c4b:
	/* 0x2c4b: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c50:
	/* 0x2c50: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c55:
	/* 0x2c55: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c5a:
	/* 0x2c5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c5c:
	/* 0x2c5c: mov    edx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c60:
	/* 0x2c60: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c62:
	/* 0x2c62: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_2c65:
	/* 0x2c65: ja     2c89 <generic_retkprobe_filter_arg_2+0x2c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2c89;
	}
x86_l_2c67:
	/* 0x2c67: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_2c6c:
	/* 0x2c6c: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2c6f:
	/* 0x2c6f: jae    2c79 <generic_retkprobe_filter_arg_2+0x2c79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2c79;
	}
x86_l_2c71:
	/* 0x2c71: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c74:
	/* 0x2c74: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_2c77:
	/* 0x2c77: jmp    2c89 <generic_retkprobe_filter_arg_2+0x2c89> */
	goto x86_l_2c89;
x86_l_2c79:
	/* 0x2c79: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_2c7e:
	/* 0x2c7e: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2c81:
	/* 0x2c81: jae    2c89 <generic_retkprobe_filter_arg_2+0x2c89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2c89;
	}
x86_l_2c83:
	/* 0x2c83: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c86:
	/* 0x2c86: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_2c89:
	/* 0x2c89: movzx  r12d,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2c8d:
	/* 0x2c8d: jmp    31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	return 12747ULL;
x86_l_2c92:
	/* 0x2c92: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c97:
	/* 0x2c97: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_2c9a:
	/* 0x2c9a: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_2c9d:
	/* 0x2c9d: jmp    2ca2 <generic_retkprobe_filter_arg_2+0x2ca2> */
	goto x86_l_2ca2;
x86_l_2c9f:
	/* 0x2c9f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ca2:
	/* 0x2ca2: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2ca5:
	/* 0x2ca5: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2ca9:
	/* 0x2ca9: jmp    31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	return 12747ULL;
x86_l_2cae:
	/* 0x2cae: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2cb1:
	/* 0x2cb1: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_2cb4:
	/* 0x2cb4: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2cb6:
	/* 0x2cb6: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2cb8:
	/* 0x2cb8: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2cbb:
	/* 0x2cbb: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2cc0:
	/* 0x2cc0: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2cc4:
	/* 0x2cc4: ja     2cd4 <generic_retkprobe_filter_arg_2+0x2cd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2cd4;
	}
x86_l_2cc6:
	/* 0x2cc6: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2cc9:
	/* 0x2cc9: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2ccf:
	/* 0x2ccf: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2cd2:
	/* 0x2cd2: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2cd4:
	/* 0x2cd4: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2cd8:
	/* 0x2cd8: mov    QWORD PTR [rsp+0x38],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2cdd:
	/* 0x2cdd: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ce2:
	/* 0x2ce2: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ce6:
	/* 0x2ce6: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2ce9:
	/* 0x2ce9: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ced:
	/* 0x2ced: mov    eax,DWORD PTR [rsi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2cf1:
	/* 0x2cf1: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2cf5:
	/* 0x2cf5: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2cf8:
	/* 0x2cf8: je     3107 <generic_retkprobe_filter_arg_2+0x3107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12551ULL;
	}
x86_l_2cfe:
	/* 0x2cfe: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2d05:
	/* 0x2d05: lea    r12,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d0a:
	/* 0x2d0a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d0f:
	/* 0x2d0f: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2d12:
	/* 0x2d12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d14:
	/* 0x2d14: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2d17:
	/* 0x2d17: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2d1e:
	/* 0x2d1e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d23:
	/* 0x2d23: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2d26:
	/* 0x2d26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d28:
	/* 0x2d28: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d2b:
	/* 0x2d2b: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d30:
	/* 0x2d30: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2d33:
	/* 0x2d33: je     310a <generic_retkprobe_filter_arg_2+0x310a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12554ULL;
	}
x86_l_2d39:
	/* 0x2d39: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d3c:
	/* 0x2d3c: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d40:
	/* 0x2d40: je     310e <generic_retkprobe_filter_arg_2+0x310e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12558ULL;
	}
x86_l_2d46:
	/* 0x2d46: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2d49:
	/* 0x2d49: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d4e:
	/* 0x2d4e: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2d52:
	/* 0x2d52: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d57:
	/* 0x2d57: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d5c:
	/* 0x2d5c: mov    BYTE PTR [rax],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d5f:
	/* 0x2d5f: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2d63:
	/* 0x2d63: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d68:
	/* 0x2d68: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2d6b:
	/* 0x2d6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d6d:
	/* 0x2d6d: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_2d72:
	/* 0x2d72: cmp    esi,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2d75:
	/* 0x2d75: jbe    2d9a <generic_retkprobe_filter_arg_2+0x2d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2d9a;
	}
x86_l_2d77:
	/* 0x2d77: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d7c:
	/* 0x2d7c: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d81:
	/* 0x2d81: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2d85:
	/* 0x2d85: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2d88:
	/* 0x2d88: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d8a:
	/* 0x2d8a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2d90:
	/* 0x2d90: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d95:
	/* 0x2d95: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2d98:
	/* 0x2d98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d9a:
	/* 0x2d9a: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2d9e:
	/* 0x2d9e: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2da2:
	/* 0x2da2: cmp    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_2da7:
	/* 0x2da7: jg     2fbc <generic_retkprobe_filter_arg_2+0x2fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2fbc;
	}
x86_l_2dad:
	/* 0x2dad: cmp    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2db2:
	/* 0x2db2: je     3096 <generic_retkprobe_filter_arg_2+0x3096> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3096;
	}
x86_l_2db8:
	/* 0x2db8: cmp    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2dbd:
	/* 0x2dbd: je     30bc <generic_retkprobe_filter_arg_2+0x30bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12476ULL;
	}
x86_l_2dc3:
	/* 0x2dc3: cmp    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_2dc8:
	/* 0x2dc8: jne    3107 <generic_retkprobe_filter_arg_2+0x3107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12551ULL;
	}
x86_l_2dce:
	/* 0x2dce: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2dd5:
	/* 0x2dd5: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2dda:
	/* 0x2dda: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ddf:
	/* 0x2ddf: jmp    30e0 <generic_retkprobe_filter_arg_2+0x30e0> */
	return 12512ULL;
x86_l_2de4:
	/* 0x2de4: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2de7:
	/* 0x2de7: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2dea:
	/* 0x2dea: jne    2df6 <generic_retkprobe_filter_arg_2+0x2df6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2df6;
	}
x86_l_2dec:
	/* 0x2dec: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2def:
	/* 0x2def: je     2df6 <generic_retkprobe_filter_arg_2+0x2df6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2df6;
	}
x86_l_2df1:
	/* 0x2df1: movzx  r12d,BYTE PTR [rdx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_2df6:
	/* 0x2df6: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2df9:
	/* 0x2df9: je     2e00 <generic_retkprobe_filter_arg_2+0x2e00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e00;
	}
x86_l_2dfb:
	/* 0x2dfb: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2dfe:
	/* 0x2dfe: jne    2e3d <generic_retkprobe_filter_arg_2+0x2e3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e3d;
	}
x86_l_2e00:
	/* 0x2e00: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_2e03:
	/* 0x2e03: movzx  eax,BYTE PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2e07:
	/* 0x2e07: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2e0b:
	/* 0x2e0b: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2e12:
	/* 0x2e12: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2e17:
	/* 0x2e17: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e1c:
	/* 0x2e1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e1e:
	/* 0x2e1e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e21:
	/* 0x2e21: je     2e3d <generic_retkprobe_filter_arg_2+0x2e3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e3d;
	}
x86_l_2e23:
	/* 0x2e23: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2e26:
	/* 0x2e26: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_2e29:
	/* 0x2e29: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e2e:
	/* 0x2e2e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e33:
	/* 0x2e33: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e38:
	/* 0x2e38: jmp    2c5a <generic_retkprobe_filter_arg_2+0x2c5a> */
	goto x86_l_2c5a;
x86_l_2e3d:
	/* 0x2e3d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e40:
	/* 0x2e40: jmp    31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	return 12747ULL;
x86_l_2e45:
	/* 0x2e45: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e48:
	/* 0x2e48: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2e4a:
	/* 0x2e4a: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e4c:
	/* 0x2e4c: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2e4e:
	/* 0x2e4e: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2e51:
	/* 0x2e51: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2e56:
	/* 0x2e56: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2e5a:
	/* 0x2e5a: ja     2e6a <generic_retkprobe_filter_arg_2+0x2e6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2e6a;
	}
x86_l_2e5c:
	/* 0x2e5c: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e5f:
	/* 0x2e5f: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2e65:
	/* 0x2e65: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2e68:
	/* 0x2e68: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2e6a:
	/* 0x2e6a: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2e6e:
	/* 0x2e6e: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e72:
	/* 0x2e72: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2e75:
	/* 0x2e75: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e79:
	/* 0x2e79: mov    eax,DWORD PTR [rcx+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2e7d:
	/* 0x2e7d: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2e81:
	/* 0x2e81: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2e84:
	/* 0x2e84: je     31a6 <generic_retkprobe_filter_arg_2+0x31a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12710ULL;
	}
x86_l_2e8a:
	/* 0x2e8a: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2e91:
	/* 0x2e91: lea    r12,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e96:
	/* 0x2e96: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e9b:
	/* 0x2e9b: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2e9e:
	/* 0x2e9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ea0:
	/* 0x2ea0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2ea3:
	/* 0x2ea3: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2eaa:
	/* 0x2eaa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2eaf:
	/* 0x2eaf: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2eb2:
	/* 0x2eb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eb4:
	/* 0x2eb4: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2ebc:
	/* 0x2ebc: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ebf:
	/* 0x2ebf: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ec4:
	/* 0x2ec4: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2ec7:
	/* 0x2ec7: je     31a9 <generic_retkprobe_filter_arg_2+0x31a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12713ULL;
	}
x86_l_2ecd:
	/* 0x2ecd: cmp    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_2ed6:
	/* 0x2ed6: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2eda:
	/* 0x2eda: je     31ad <generic_retkprobe_filter_arg_2+0x31ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12717ULL;
	}
x86_l_2ee0:
	/* 0x2ee0: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ee5:
	/* 0x2ee5: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2eea:
	/* 0x2eea: mov    BYTE PTR [rax],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2eed:
	/* 0x2eed: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2ef1:
	/* 0x2ef1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ef6:
	/* 0x2ef6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2efb:
	/* 0x2efb: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2efe:
	/* 0x2efe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f00:
	/* 0x2f00: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_2f05:
	/* 0x2f05: cmp    esi,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2f08:
	/* 0x2f08: jbe    2f32 <generic_retkprobe_filter_arg_2+0x2f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2f32;
	}
x86_l_2f0a:
	/* 0x2f0a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f0f:
	/* 0x2f0f: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f14:
	/* 0x2f14: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2f18:
	/* 0x2f18: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2f1b:
	/* 0x2f1b: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f1d:
	/* 0x2f1d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2f23:
	/* 0x2f23: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f28:
	/* 0x2f28: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2f30:
	/* 0x2f30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f32:
	/* 0x2f32: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2f36:
	/* 0x2f36: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2f3a:
	/* 0x2f3a: cmp    DWORD PTR [rsp+0x38],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168578ULL);
x86_l_2f3f:
	/* 0x2f3f: jg     2ff3 <generic_retkprobe_filter_arg_2+0x2ff3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2ff3;
	}
x86_l_2f45:
	/* 0x2f45: cmp    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2f4a:
	/* 0x2f4a: je     3135 <generic_retkprobe_filter_arg_2+0x3135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12597ULL;
	}
x86_l_2f50:
	/* 0x2f50: cmp    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_2f55:
	/* 0x2f55: je     315b <generic_retkprobe_filter_arg_2+0x315b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12635ULL;
	}
x86_l_2f5b:
	/* 0x2f5b: cmp    DWORD PTR [rsp+0x38],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168578ULL);
x86_l_2f60:
	/* 0x2f60: jne    31a6 <generic_retkprobe_filter_arg_2+0x31a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12710ULL;
	}
x86_l_2f66:
	/* 0x2f66: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2f6d:
	/* 0x2f6d: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2f72:
	/* 0x2f72: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f77:
	/* 0x2f77: jmp    317f <generic_retkprobe_filter_arg_2+0x317f> */
	return 12671ULL;
x86_l_2f7c:
	/* 0x2f7c: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2f7f:
	/* 0x2f7f: je     303d <generic_retkprobe_filter_arg_2+0x303d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_303d;
	}
x86_l_2f85:
	/* 0x2f85: cmp    DWORD PTR [rsp+0x8],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738372ULL);
x86_l_2f8a:
	/* 0x2f8a: je     3063 <generic_retkprobe_filter_arg_2+0x3063> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3063;
	}
x86_l_2f90:
	/* 0x2f90: cmp    DWORD PTR [rsp+0x8],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738373ULL);
x86_l_2f95:
	/* 0x2f95: jne    31a6 <generic_retkprobe_filter_arg_2+0x31a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12710ULL;
	}
x86_l_2f9b:
	/* 0x2f9b: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_2fa2:
	/* 0x2fa2: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2fa7:
	/* 0x2fa7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fac:
	/* 0x2fac: jmp    3074 <generic_retkprobe_filter_arg_2+0x3074> */
	goto x86_l_3074;
x86_l_2fb1:
	/* 0x2fb1: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fb4:
	/* 0x2fb4: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2fb7:
	/* 0x2fb7: jmp    310e <generic_retkprobe_filter_arg_2+0x310e> */
	return 12558ULL;
x86_l_2fbc:
	/* 0x2fbc: cmp    DWORD PTR [rsp+0x8],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738371ULL);
x86_l_2fc1:
	/* 0x2fc1: je     30a9 <generic_retkprobe_filter_arg_2+0x30a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12457ULL;
	}
x86_l_2fc7:
	/* 0x2fc7: cmp    DWORD PTR [rsp+0x8],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738372ULL);
x86_l_2fcc:
	/* 0x2fcc: je     30cf <generic_retkprobe_filter_arg_2+0x30cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12495ULL;
	}
x86_l_2fd2:
	/* 0x2fd2: cmp    DWORD PTR [rsp+0x8],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738373ULL);
x86_l_2fd7:
	/* 0x2fd7: jne    3107 <generic_retkprobe_filter_arg_2+0x3107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12551ULL;
	}
x86_l_2fdd:
	/* 0x2fdd: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_2fe4:
	/* 0x2fe4: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2fe9:
	/* 0x2fe9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fee:
	/* 0x2fee: jmp    30e0 <generic_retkprobe_filter_arg_2+0x30e0> */
	return 12512ULL;
x86_l_2ff3:
	/* 0x2ff3: cmp    DWORD PTR [rsp+0x38],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168579ULL);
x86_l_2ff8:
	/* 0x2ff8: je     3148 <generic_retkprobe_filter_arg_2+0x3148> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12616ULL;
	}
x86_l_2ffe:
	/* 0x2ffe: cmp    DWORD PTR [rsp+0x38],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168580ULL);
x86_l_3003:
	/* 0x3003: je     316e <generic_retkprobe_filter_arg_2+0x316e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12654ULL;
	}
x86_l_3009:
	/* 0x3009: cmp    DWORD PTR [rsp+0x38],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168581ULL);
x86_l_300e:
	/* 0x300e: jne    31a6 <generic_retkprobe_filter_arg_2+0x31a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12710ULL;
	}
x86_l_3014:
	/* 0x3014: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_301b:
	/* 0x301b: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3020:
	/* 0x3020: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3025:
	/* 0x3025: jmp    317f <generic_retkprobe_filter_arg_2+0x317f> */
	return 12671ULL;
x86_l_302a:
	/* 0x302a: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_3031:
	/* 0x3031: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3036:
	/* 0x3036: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_303b:
	/* 0x303b: jmp    3074 <generic_retkprobe_filter_arg_2+0x3074> */
	goto x86_l_3074;
x86_l_303d:
	/* 0x303d: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_3044:
	/* 0x3044: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3049:
	/* 0x3049: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_304e:
	/* 0x304e: jmp    3074 <generic_retkprobe_filter_arg_2+0x3074> */
	goto x86_l_3074;
x86_l_3050:
	/* 0x3050: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_3057:
	/* 0x3057: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_305c:
	/* 0x305c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3061:
	/* 0x3061: jmp    3074 <generic_retkprobe_filter_arg_2+0x3074> */
	goto x86_l_3074;
x86_l_3063:
	/* 0x3063: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_306a:
	/* 0x306a: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_306f:
	/* 0x306f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3074:
	/* 0x3074: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3079:
	/* 0x3079: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_307b:
	/* 0x307b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_307e:
	/* 0x307e: je     31a6 <generic_retkprobe_filter_arg_2+0x31a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12710ULL;
	}
x86_l_3084:
	/* 0x3084: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3087:
	/* 0x3087: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_308c:
	/* 0x308c: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3091:
	/* 0x3091: jmp    3198 <generic_retkprobe_filter_arg_2+0x3198> */
	return 12696ULL;
x86_l_3096:
	/* 0x3096: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_309d:
	/* 0x309d: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30a2:
	/* 0x30a2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30a7:
	/* 0x30a7: jmp    30e0 <generic_retkprobe_filter_arg_2+0x30e0> */
	return 12512ULL;
	return 12457ULL;
}

static __noinline __u64 tetragon_bpf_generic_retkprobe_generic_retkprobe_filter_arg_2_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12457ULL: goto x86_l_30a9;
	case 12464ULL: goto x86_l_30b0;
	case 12469ULL: goto x86_l_30b5;
	case 12474ULL: goto x86_l_30ba;
	case 12476ULL: goto x86_l_30bc;
	case 12483ULL: goto x86_l_30c3;
	case 12488ULL: goto x86_l_30c8;
	case 12493ULL: goto x86_l_30cd;
	case 12495ULL: goto x86_l_30cf;
	case 12502ULL: goto x86_l_30d6;
	case 12507ULL: goto x86_l_30db;
	case 12512ULL: goto x86_l_30e0;
	case 12517ULL: goto x86_l_30e5;
	case 12519ULL: goto x86_l_30e7;
	case 12522ULL: goto x86_l_30ea;
	case 12524ULL: goto x86_l_30ec;
	case 12527ULL: goto x86_l_30ef;
	case 12532ULL: goto x86_l_30f4;
	case 12537ULL: goto x86_l_30f9;
	case 12539ULL: goto x86_l_30fb;
	case 12542ULL: goto x86_l_30fe;
	case 12545ULL: goto x86_l_3101;
	case 12549ULL: goto x86_l_3105;
	case 12551ULL: goto x86_l_3107;
	case 12554ULL: goto x86_l_310a;
	case 12558ULL: goto x86_l_310e;
	case 12561ULL: goto x86_l_3111;
	case 12564ULL: goto x86_l_3114;
	case 12570ULL: goto x86_l_311a;
	case 12572ULL: goto x86_l_311c;
	case 12582ULL: goto x86_l_3126;
	case 12586ULL: goto x86_l_312a;
	case 12592ULL: goto x86_l_3130;
	case 12597ULL: goto x86_l_3135;
	case 12604ULL: goto x86_l_313c;
	case 12609ULL: goto x86_l_3141;
	case 12614ULL: goto x86_l_3146;
	case 12616ULL: goto x86_l_3148;
	case 12623ULL: goto x86_l_314f;
	case 12628ULL: goto x86_l_3154;
	case 12633ULL: goto x86_l_3159;
	case 12635ULL: goto x86_l_315b;
	case 12642ULL: goto x86_l_3162;
	case 12647ULL: goto x86_l_3167;
	case 12652ULL: goto x86_l_316c;
	case 12654ULL: goto x86_l_316e;
	case 12661ULL: goto x86_l_3175;
	case 12666ULL: goto x86_l_317a;
	case 12671ULL: goto x86_l_317f;
	case 12676ULL: goto x86_l_3184;
	case 12678ULL: goto x86_l_3186;
	case 12681ULL: goto x86_l_3189;
	case 12683ULL: goto x86_l_318b;
	case 12686ULL: goto x86_l_318e;
	case 12691ULL: goto x86_l_3193;
	case 12696ULL: goto x86_l_3198;
	case 12698ULL: goto x86_l_319a;
	case 12701ULL: goto x86_l_319d;
	case 12704ULL: goto x86_l_31a0;
	case 12708ULL: goto x86_l_31a4;
	case 12710ULL: goto x86_l_31a6;
	case 12713ULL: goto x86_l_31a9;
	case 12717ULL: goto x86_l_31ad;
	case 12720ULL: goto x86_l_31b0;
	case 12723ULL: goto x86_l_31b3;
	case 12725ULL: goto x86_l_31b5;
	case 12727ULL: goto x86_l_31b7;
	case 12737ULL: goto x86_l_31c1;
	case 12741ULL: goto x86_l_31c5;
	case 12743ULL: goto x86_l_31c7;
	case 12747ULL: goto x86_l_31cb;
	case 12750ULL: goto x86_l_31ce;
	case 12752ULL: goto x86_l_31d0;
	case 12756ULL: goto x86_l_31d4;
	case 12758ULL: goto x86_l_31d6;
	case 12760ULL: goto x86_l_31d8;
	case 12762ULL: goto x86_l_31da;
	case 12766ULL: goto x86_l_31de;
	case 12768ULL: goto x86_l_31e0;
	case 12772ULL: goto x86_l_31e4;
	case 12778ULL: goto x86_l_31ea;
	case 12781ULL: goto x86_l_31ed;
	case 12787ULL: goto x86_l_31f3;
	case 12791ULL: goto x86_l_31f7;
	case 12797ULL: goto x86_l_31fd;
	case 12799ULL: goto x86_l_31ff;
	case 12803ULL: goto x86_l_3203;
	case 12809ULL: goto x86_l_3209;
	case 12813ULL: goto x86_l_320d;
	case 12819ULL: goto x86_l_3213;
	case 12823ULL: goto x86_l_3217;
	case 12829ULL: goto x86_l_321d;
	case 12833ULL: goto x86_l_3221;
	case 12839ULL: goto x86_l_3227;
	case 12842ULL: goto x86_l_322a;
	case 12847ULL: goto x86_l_322f;
	case 12854ULL: goto x86_l_3236;
	case 12861ULL: goto x86_l_323d;
	case 12866ULL: goto x86_l_3242;
	case 12871ULL: goto x86_l_3247;
	case 12874ULL: goto x86_l_324a;
	case 12879ULL: goto x86_l_324f;
	case 12881ULL: goto x86_l_3251;
	case 12888ULL: goto x86_l_3258;
	case 12893ULL: goto x86_l_325d;
	case 12898ULL: goto x86_l_3262;
	case 12901ULL: goto x86_l_3265;
	case 12906ULL: goto x86_l_326a;
	case 12908ULL: goto x86_l_326c;
	case 12910ULL: goto x86_l_326e;
	case 12917ULL: goto x86_l_3275;
	case 12919ULL: goto x86_l_3277;
	case 12920ULL: goto x86_l_3278;
	case 12925ULL: goto x86_l_327d;
	case 12928ULL: goto x86_l_3280;
	case 12936ULL: goto x86_l_3288;
	case 12938ULL: goto x86_l_328a;
	case 12944ULL: goto x86_l_3290;
	case 12952ULL: goto x86_l_3298;
	case 12954ULL: goto x86_l_329a;
	case 12960ULL: goto x86_l_32a0;
	case 12968ULL: goto x86_l_32a8;
	case 12970ULL: goto x86_l_32aa;
	case 12976ULL: goto x86_l_32b0;
	case 12984ULL: goto x86_l_32b8;
	case 12986ULL: goto x86_l_32ba;
	case 12992ULL: goto x86_l_32c0;
	case 13000ULL: goto x86_l_32c8;
	case 13002ULL: goto x86_l_32ca;
	case 13008ULL: goto x86_l_32d0;
	case 13016ULL: goto x86_l_32d8;
	case 13018ULL: goto x86_l_32da;
	case 13025ULL: goto x86_l_32e1;
	case 13032ULL: goto x86_l_32e8;
	case 13037ULL: goto x86_l_32ed;
	case 13042ULL: goto x86_l_32f2;
	case 13045ULL: goto x86_l_32f5;
	case 13050ULL: goto x86_l_32fa;
	case 13052ULL: goto x86_l_32fc;
	case 13056ULL: goto x86_l_3300;
	case 13061ULL: goto x86_l_3305;
	case 13063ULL: goto x86_l_3307;
	case 13068ULL: goto x86_l_330c;
	case 13073ULL: goto x86_l_3311;
	case 13080ULL: goto x86_l_3318;
	case 13085ULL: goto x86_l_331d;
	case 13090ULL: goto x86_l_3322;
	case 13092ULL: goto x86_l_3324;
	case 13095ULL: goto x86_l_3327;
	case 13101ULL: goto x86_l_332d;
	case 13108ULL: goto x86_l_3334;
	case 13113ULL: goto x86_l_3339;
	case 13118ULL: goto x86_l_333e;
	case 13120ULL: goto x86_l_3340;
	default: return 0xffffffffffffffffULL;
	}
x86_l_30a9:
	/* 0x30a9: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_30b0:
	/* 0x30b0: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30b5:
	/* 0x30b5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30ba:
	/* 0x30ba: jmp    30e0 <generic_retkprobe_filter_arg_2+0x30e0> */
	goto x86_l_30e0;
x86_l_30bc:
	/* 0x30bc: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_30c3:
	/* 0x30c3: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30c8:
	/* 0x30c8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30cd:
	/* 0x30cd: jmp    30e0 <generic_retkprobe_filter_arg_2+0x30e0> */
	goto x86_l_30e0;
x86_l_30cf:
	/* 0x30cf: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_30d6:
	/* 0x30d6: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30db:
	/* 0x30db: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30e0:
	/* 0x30e0: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30e5:
	/* 0x30e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30e7:
	/* 0x30e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30ea:
	/* 0x30ea: je     3107 <generic_retkprobe_filter_arg_2+0x3107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3107;
	}
x86_l_30ec:
	/* 0x30ec: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_30ef:
	/* 0x30ef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30f4:
	/* 0x30f4: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30f9:
	/* 0x30f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30fb:
	/* 0x30fb: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30fe:
	/* 0x30fe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3101:
	/* 0x3101: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_3105:
	/* 0x3105: jmp    310a <generic_retkprobe_filter_arg_2+0x310a> */
	goto x86_l_310a;
x86_l_3107:
	/* 0x3107: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_310a:
	/* 0x310a: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_310e:
	/* 0x310e: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3111:
	/* 0x3111: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_3114:
	/* 0x3114: ja     31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_31cb;
	}
x86_l_311a:
	/* 0x311a: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_311c:
	/* 0x311c: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_3126:
	/* 0x3126: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_312a:
	/* 0x312a: jb     31c7 <generic_retkprobe_filter_arg_2+0x31c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_31c7;
	}
x86_l_3130:
	/* 0x3130: jmp    31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	goto x86_l_31cb;
x86_l_3135:
	/* 0x3135: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_313c:
	/* 0x313c: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3141:
	/* 0x3141: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3146:
	/* 0x3146: jmp    317f <generic_retkprobe_filter_arg_2+0x317f> */
	goto x86_l_317f;
x86_l_3148:
	/* 0x3148: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_314f:
	/* 0x314f: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3154:
	/* 0x3154: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3159:
	/* 0x3159: jmp    317f <generic_retkprobe_filter_arg_2+0x317f> */
	goto x86_l_317f;
x86_l_315b:
	/* 0x315b: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_3162:
	/* 0x3162: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3167:
	/* 0x3167: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_316c:
	/* 0x316c: jmp    317f <generic_retkprobe_filter_arg_2+0x317f> */
	goto x86_l_317f;
x86_l_316e:
	/* 0x316e: mov    rdi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_3175:
	/* 0x3175: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_317a:
	/* 0x317a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_317f:
	/* 0x317f: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3184:
	/* 0x3184: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3186:
	/* 0x3186: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3189:
	/* 0x3189: je     31a6 <generic_retkprobe_filter_arg_2+0x31a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31a6;
	}
x86_l_318b:
	/* 0x318b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_318e:
	/* 0x318e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3193:
	/* 0x3193: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3198:
	/* 0x3198: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_319a:
	/* 0x319a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_319d:
	/* 0x319d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31a0:
	/* 0x31a0: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_31a4:
	/* 0x31a4: jmp    31a9 <generic_retkprobe_filter_arg_2+0x31a9> */
	goto x86_l_31a9;
x86_l_31a6:
	/* 0x31a6: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31a9:
	/* 0x31a9: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31ad:
	/* 0x31ad: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_31b0:
	/* 0x31b0: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_31b3:
	/* 0x31b3: ja     31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_31cb;
	}
x86_l_31b5:
	/* 0x31b5: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31b7:
	/* 0x31b7: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_31c1:
	/* 0x31c1: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_31c5:
	/* 0x31c5: jae    31cb <generic_retkprobe_filter_arg_2+0x31cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_31cb;
	}
x86_l_31c7:
	/* 0x31c7: xor    r12,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_31cb:
	/* 0x31cb: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_31ce:
	/* 0x31ce: je     31da <generic_retkprobe_filter_arg_2+0x31da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31da;
	}
x86_l_31d0:
	/* 0x31d0: cmp    rbp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 1ULL);
x86_l_31d4:
	/* 0x31d4: je     3251 <generic_retkprobe_filter_arg_2+0x3251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3251;
	}
x86_l_31d6:
	/* 0x31d6: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_31d8:
	/* 0x31d8: jne    322f <generic_retkprobe_filter_arg_2+0x322f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_322f;
	}
x86_l_31da:
	/* 0x31da: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_31de:
	/* 0x31de: jg     31ff <generic_retkprobe_filter_arg_2+0x31ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_31ff;
	}
x86_l_31e0:
	/* 0x31e0: cmp    r15d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4294967295ULL);
x86_l_31e4:
	/* 0x31e4: je     327d <generic_retkprobe_filter_arg_2+0x327d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_327d;
	}
x86_l_31ea:
	/* 0x31ea: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_31ed:
	/* 0x31ed: je     328a <generic_retkprobe_filter_arg_2+0x328a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_328a;
	}
x86_l_31f3:
	/* 0x31f3: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_31f7:
	/* 0x31f7: je     329a <generic_retkprobe_filter_arg_2+0x329a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_329a;
	}
x86_l_31fd:
	/* 0x31fd: jmp    321d <generic_retkprobe_filter_arg_2+0x321d> */
	goto x86_l_321d;
x86_l_31ff:
	/* 0x31ff: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_3203:
	/* 0x3203: je     32aa <generic_retkprobe_filter_arg_2+0x32aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32aa;
	}
x86_l_3209:
	/* 0x3209: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_320d:
	/* 0x320d: je     32ba <generic_retkprobe_filter_arg_2+0x32ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32ba;
	}
x86_l_3213:
	/* 0x3213: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_3217:
	/* 0x3217: je     32ca <generic_retkprobe_filter_arg_2+0x32ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32ca;
	}
x86_l_321d:
	/* 0x321d: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_3221:
	/* 0x3221: jg     32fc <generic_retkprobe_filter_arg_2+0x32fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_32fc;
	}
x86_l_3227:
	/* 0x3227: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_322a:
	/* 0x322a: jmp    32da <generic_retkprobe_filter_arg_2+0x32da> */
	goto x86_l_32da;
x86_l_322f:
	/* 0x322f: mov    DWORD PTR [r14+0x5ef4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_3236:
	/* 0x3236: mov    rsi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_323d:
	/* 0x323d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3242:
	/* 0x3242: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3247:
	/* 0x3247: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_324a:
	/* 0x324a: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_324f:
	/* 0x324f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3251:
	/* 0x3251: mov    rsi,QWORD PTR [rip+0x17e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_3258:
	/* 0x3258: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_325d:
	/* 0x325d: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3262:
	/* 0x3262: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3265:
	/* 0x3265: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_326a:
	/* 0x326a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_326c:
	/* 0x326c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_326e:
	/* 0x326e: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_3275:
	/* 0x3275: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3277:
	/* 0x3277: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3278:
	/* 0x3278: jmp    3345 <generic_retkprobe_filter_arg_2+0x3345> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_327d:
	/* 0x327d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3280:
	/* 0x3280: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_3288:
	/* 0x3288: jne    32da <generic_retkprobe_filter_arg_2+0x32da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_32da;
	}
x86_l_328a:
	/* 0x328a: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_3290:
	/* 0x3290: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_3298:
	/* 0x3298: jne    32da <generic_retkprobe_filter_arg_2+0x32da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_32da;
	}
x86_l_329a:
	/* 0x329a: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_32a0:
	/* 0x32a0: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_32a8:
	/* 0x32a8: jne    32da <generic_retkprobe_filter_arg_2+0x32da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_32da;
	}
x86_l_32aa:
	/* 0x32aa: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_32b0:
	/* 0x32b0: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_32b8:
	/* 0x32b8: jne    32da <generic_retkprobe_filter_arg_2+0x32da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_32da;
	}
x86_l_32ba:
	/* 0x32ba: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_32c0:
	/* 0x32c0: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_32c8:
	/* 0x32c8: jne    32da <generic_retkprobe_filter_arg_2+0x32da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_32da;
	}
x86_l_32ca:
	/* 0x32ca: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_32d0:
	/* 0x32d0: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_32d8:
	/* 0x32d8: je     32fc <generic_retkprobe_filter_arg_2+0x32fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32fc;
	}
x86_l_32da:
	/* 0x32da: mov    DWORD PTR [r14+0x5ef0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_32e1:
	/* 0x32e1: mov    rsi,QWORD PTR [rip+0x17e6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_32e8:
	/* 0x32e8: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_32ed:
	/* 0x32ed: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_32f2:
	/* 0x32f2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_32f5:
	/* 0x32f5: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_32fa:
	/* 0x32fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32fc:
	/* 0x32fc: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3300:
	/* 0x3300: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3305:
	/* 0x3305: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3307:
	/* 0x3307: mov    QWORD PTR [rsp+0x50],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_330c:
	/* 0x330c: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3311:
	/* 0x3311: mov    rdi,QWORD PTR [rip+0x17e6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_3318:
	/* 0x3318: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_331d:
	/* 0x331d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3322:
	/* 0x3322: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3324:
	/* 0x3324: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3327:
	/* 0x3327: je     326c <generic_retkprobe_filter_arg_2+0x326c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_326c;
	}
x86_l_332d:
	/* 0x332d: mov    rdi,QWORD PTR [rip+0x17e6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_3334:
	/* 0x3334: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3339:
	/* 0x3339: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_333e:
	/* 0x333e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3340:
	/* 0x3340: jmp    326c <generic_retkprobe_filter_arg_2+0x326c> */
	goto x86_l_326c;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_retkprobe_generic_retkprobe_filter_arg_2_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 11368U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1811ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_generic_retkprobe_filter_arg_2_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1814ULL && __x86_pc <= 3605ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_generic_retkprobe_filter_arg_2_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3608ULL && __x86_pc <= 5482ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_generic_retkprobe_filter_arg_2_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5488ULL && __x86_pc <= 7295ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_generic_retkprobe_filter_arg_2_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7299ULL && __x86_pc <= 9151ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_generic_retkprobe_filter_arg_2_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9155ULL && __x86_pc <= 10849ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_generic_retkprobe_filter_arg_2_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10853ULL && __x86_pc <= 12455ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_generic_retkprobe_filter_arg_2_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12457ULL && __x86_pc <= 13120ULL)
			__x86_pc = tetragon_bpf_generic_retkprobe_generic_retkprobe_filter_arg_2_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

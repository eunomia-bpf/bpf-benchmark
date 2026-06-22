extern char addr4lpm_maps;
extern char addr6lpm_maps;
extern char argfilter_maps;
extern char filter_map;
extern char heap_ro_zero;
extern char process_call_heap;
extern char retprobe_map;
extern char retuprobe_calls;
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

static __noinline __u64 tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_0(
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
	case 147ULL: goto x86_l_93;
	case 153ULL: goto x86_l_99;
	case 157ULL: goto x86_l_9d;
	case 163ULL: goto x86_l_a3;
	case 167ULL: goto x86_l_a7;
	case 173ULL: goto x86_l_ad;
	case 179ULL: goto x86_l_b3;
	case 181ULL: goto x86_l_b5;
	case 187ULL: goto x86_l_bb;
	case 190ULL: goto x86_l_be;
	case 194ULL: goto x86_l_c2;
	case 200ULL: goto x86_l_c8;
	case 209ULL: goto x86_l_d1;
	case 215ULL: goto x86_l_d7;
	case 218ULL: goto x86_l_da;
	case 221ULL: goto x86_l_dd;
	case 225ULL: goto x86_l_e1;
	case 233ULL: goto x86_l_e9;
	case 238ULL: goto x86_l_ee;
	case 242ULL: goto x86_l_f2;
	case 249ULL: goto x86_l_f9;
	case 252ULL: goto x86_l_fc;
	case 254ULL: goto x86_l_fe;
	case 257ULL: goto x86_l_101;
	case 263ULL: goto x86_l_107;
	case 266ULL: goto x86_l_10a;
	case 272ULL: goto x86_l_110;
	case 275ULL: goto x86_l_113;
	case 281ULL: goto x86_l_119;
	case 284ULL: goto x86_l_11c;
	case 286ULL: goto x86_l_11e;
	case 291ULL: goto x86_l_123;
	case 294ULL: goto x86_l_126;
	case 300ULL: goto x86_l_12c;
	case 303ULL: goto x86_l_12f;
	case 306ULL: goto x86_l_132;
	case 312ULL: goto x86_l_138;
	case 315ULL: goto x86_l_13b;
	case 318ULL: goto x86_l_13e;
	case 321ULL: goto x86_l_141;
	case 327ULL: goto x86_l_147;
	case 330ULL: goto x86_l_14a;
	case 334ULL: goto x86_l_14e;
	case 339ULL: goto x86_l_153;
	case 342ULL: goto x86_l_156;
	case 348ULL: goto x86_l_15c;
	case 353ULL: goto x86_l_161;
	case 356ULL: goto x86_l_164;
	case 362ULL: goto x86_l_16a;
	case 367ULL: goto x86_l_16f;
	case 370ULL: goto x86_l_172;
	case 376ULL: goto x86_l_178;
	case 381ULL: goto x86_l_17d;
	case 385ULL: goto x86_l_181;
	case 388ULL: goto x86_l_184;
	case 392ULL: goto x86_l_188;
	case 400ULL: goto x86_l_190;
	case 407ULL: goto x86_l_197;
	case 412ULL: goto x86_l_19c;
	case 417ULL: goto x86_l_1a1;
	case 419ULL: goto x86_l_1a3;
	case 422ULL: goto x86_l_1a6;
	case 425ULL: goto x86_l_1a9;
	case 428ULL: goto x86_l_1ac;
	case 434ULL: goto x86_l_1b2;
	case 437ULL: goto x86_l_1b5;
	case 443ULL: goto x86_l_1bb;
	case 446ULL: goto x86_l_1be;
	case 453ULL: goto x86_l_1c5;
	case 458ULL: goto x86_l_1ca;
	case 463ULL: goto x86_l_1cf;
	case 465ULL: goto x86_l_1d1;
	case 468ULL: goto x86_l_1d4;
	case 474ULL: goto x86_l_1da;
	case 477ULL: goto x86_l_1dd;
	case 481ULL: goto x86_l_1e1;
	case 486ULL: goto x86_l_1e6;
	case 490ULL: goto x86_l_1ea;
	case 493ULL: goto x86_l_1ed;
	case 495ULL: goto x86_l_1ef;
	case 499ULL: goto x86_l_1f3;
	case 504ULL: goto x86_l_1f8;
	case 509ULL: goto x86_l_1fd;
	case 513ULL: goto x86_l_201;
	case 516ULL: goto x86_l_204;
	case 520ULL: goto x86_l_208;
	case 526ULL: goto x86_l_20e;
	case 533ULL: goto x86_l_215;
	case 538ULL: goto x86_l_21a;
	case 542ULL: goto x86_l_21e;
	case 545ULL: goto x86_l_221;
	case 549ULL: goto x86_l_225;
	case 555ULL: goto x86_l_22b;
	case 562ULL: goto x86_l_232;
	case 567ULL: goto x86_l_237;
	case 571ULL: goto x86_l_23b;
	case 574ULL: goto x86_l_23e;
	case 578ULL: goto x86_l_242;
	case 584ULL: goto x86_l_248;
	case 591ULL: goto x86_l_24f;
	case 596ULL: goto x86_l_254;
	case 600ULL: goto x86_l_258;
	case 603ULL: goto x86_l_25b;
	case 607ULL: goto x86_l_25f;
	case 613ULL: goto x86_l_265;
	case 620ULL: goto x86_l_26c;
	case 625ULL: goto x86_l_271;
	case 629ULL: goto x86_l_275;
	case 632ULL: goto x86_l_278;
	case 636ULL: goto x86_l_27c;
	case 642ULL: goto x86_l_282;
	case 649ULL: goto x86_l_289;
	case 654ULL: goto x86_l_28e;
	case 658ULL: goto x86_l_292;
	case 661ULL: goto x86_l_295;
	case 665ULL: goto x86_l_299;
	case 671ULL: goto x86_l_29f;
	case 678ULL: goto x86_l_2a6;
	case 683ULL: goto x86_l_2ab;
	case 687ULL: goto x86_l_2af;
	case 690ULL: goto x86_l_2b2;
	case 694ULL: goto x86_l_2b6;
	case 700ULL: goto x86_l_2bc;
	case 707ULL: goto x86_l_2c3;
	case 712ULL: goto x86_l_2c8;
	case 716ULL: goto x86_l_2cc;
	case 719ULL: goto x86_l_2cf;
	case 723ULL: goto x86_l_2d3;
	case 729ULL: goto x86_l_2d9;
	case 736ULL: goto x86_l_2e0;
	case 741ULL: goto x86_l_2e5;
	case 745ULL: goto x86_l_2e9;
	case 748ULL: goto x86_l_2ec;
	case 752ULL: goto x86_l_2f0;
	case 758ULL: goto x86_l_2f6;
	case 765ULL: goto x86_l_2fd;
	case 770ULL: goto x86_l_302;
	case 774ULL: goto x86_l_306;
	case 777ULL: goto x86_l_309;
	case 781ULL: goto x86_l_30d;
	case 787ULL: goto x86_l_313;
	case 794ULL: goto x86_l_31a;
	case 799ULL: goto x86_l_31f;
	case 803ULL: goto x86_l_323;
	case 806ULL: goto x86_l_326;
	case 810ULL: goto x86_l_32a;
	case 816ULL: goto x86_l_330;
	case 823ULL: goto x86_l_337;
	case 828ULL: goto x86_l_33c;
	case 832ULL: goto x86_l_340;
	case 835ULL: goto x86_l_343;
	case 839ULL: goto x86_l_347;
	case 845ULL: goto x86_l_34d;
	case 852ULL: goto x86_l_354;
	case 857ULL: goto x86_l_359;
	case 861ULL: goto x86_l_35d;
	case 864ULL: goto x86_l_360;
	case 868ULL: goto x86_l_364;
	case 874ULL: goto x86_l_36a;
	case 881ULL: goto x86_l_371;
	case 886ULL: goto x86_l_376;
	case 890ULL: goto x86_l_37a;
	case 893ULL: goto x86_l_37d;
	case 897ULL: goto x86_l_381;
	case 903ULL: goto x86_l_387;
	case 910ULL: goto x86_l_38e;
	case 915ULL: goto x86_l_393;
	case 919ULL: goto x86_l_397;
	case 922ULL: goto x86_l_39a;
	case 926ULL: goto x86_l_39e;
	case 932ULL: goto x86_l_3a4;
	case 939ULL: goto x86_l_3ab;
	case 944ULL: goto x86_l_3b0;
	case 948ULL: goto x86_l_3b4;
	case 951ULL: goto x86_l_3b7;
	case 955ULL: goto x86_l_3bb;
	case 961ULL: goto x86_l_3c1;
	case 968ULL: goto x86_l_3c8;
	case 973ULL: goto x86_l_3cd;
	case 977ULL: goto x86_l_3d1;
	case 980ULL: goto x86_l_3d4;
	case 984ULL: goto x86_l_3d8;
	case 990ULL: goto x86_l_3de;
	case 997ULL: goto x86_l_3e5;
	case 1002ULL: goto x86_l_3ea;
	case 1006ULL: goto x86_l_3ee;
	case 1009ULL: goto x86_l_3f1;
	case 1013ULL: goto x86_l_3f5;
	case 1019ULL: goto x86_l_3fb;
	case 1026ULL: goto x86_l_402;
	case 1031ULL: goto x86_l_407;
	case 1035ULL: goto x86_l_40b;
	case 1038ULL: goto x86_l_40e;
	case 1042ULL: goto x86_l_412;
	case 1048ULL: goto x86_l_418;
	case 1055ULL: goto x86_l_41f;
	case 1060ULL: goto x86_l_424;
	case 1064ULL: goto x86_l_428;
	case 1067ULL: goto x86_l_42b;
	case 1071ULL: goto x86_l_42f;
	case 1077ULL: goto x86_l_435;
	case 1084ULL: goto x86_l_43c;
	case 1089ULL: goto x86_l_441;
	case 1093ULL: goto x86_l_445;
	case 1096ULL: goto x86_l_448;
	case 1100ULL: goto x86_l_44c;
	case 1106ULL: goto x86_l_452;
	case 1113ULL: goto x86_l_459;
	case 1118ULL: goto x86_l_45e;
	case 1122ULL: goto x86_l_462;
	case 1125ULL: goto x86_l_465;
	case 1129ULL: goto x86_l_469;
	case 1135ULL: goto x86_l_46f;
	case 1142ULL: goto x86_l_476;
	case 1147ULL: goto x86_l_47b;
	case 1151ULL: goto x86_l_47f;
	case 1154ULL: goto x86_l_482;
	case 1158ULL: goto x86_l_486;
	case 1164ULL: goto x86_l_48c;
	case 1171ULL: goto x86_l_493;
	case 1176ULL: goto x86_l_498;
	case 1180ULL: goto x86_l_49c;
	case 1183ULL: goto x86_l_49f;
	case 1187ULL: goto x86_l_4a3;
	case 1193ULL: goto x86_l_4a9;
	case 1200ULL: goto x86_l_4b0;
	case 1205ULL: goto x86_l_4b5;
	case 1209ULL: goto x86_l_4b9;
	case 1212ULL: goto x86_l_4bc;
	case 1216ULL: goto x86_l_4c0;
	case 1222ULL: goto x86_l_4c6;
	case 1229ULL: goto x86_l_4cd;
	case 1234ULL: goto x86_l_4d2;
	case 1238ULL: goto x86_l_4d6;
	case 1241ULL: goto x86_l_4d9;
	case 1245ULL: goto x86_l_4dd;
	case 1251ULL: goto x86_l_4e3;
	case 1258ULL: goto x86_l_4ea;
	case 1263ULL: goto x86_l_4ef;
	case 1267ULL: goto x86_l_4f3;
	case 1270ULL: goto x86_l_4f6;
	case 1274ULL: goto x86_l_4fa;
	case 1280ULL: goto x86_l_500;
	case 1287ULL: goto x86_l_507;
	case 1292ULL: goto x86_l_50c;
	case 1296ULL: goto x86_l_510;
	case 1299ULL: goto x86_l_513;
	case 1303ULL: goto x86_l_517;
	case 1309ULL: goto x86_l_51d;
	case 1316ULL: goto x86_l_524;
	case 1321ULL: goto x86_l_529;
	case 1325ULL: goto x86_l_52d;
	case 1328ULL: goto x86_l_530;
	case 1332ULL: goto x86_l_534;
	case 1338ULL: goto x86_l_53a;
	case 1345ULL: goto x86_l_541;
	case 1350ULL: goto x86_l_546;
	case 1354ULL: goto x86_l_54a;
	case 1357ULL: goto x86_l_54d;
	case 1361ULL: goto x86_l_551;
	case 1367ULL: goto x86_l_557;
	case 1374ULL: goto x86_l_55e;
	case 1379ULL: goto x86_l_563;
	case 1383ULL: goto x86_l_567;
	case 1386ULL: goto x86_l_56a;
	case 1390ULL: goto x86_l_56e;
	case 1396ULL: goto x86_l_574;
	case 1403ULL: goto x86_l_57b;
	case 1408ULL: goto x86_l_580;
	case 1412ULL: goto x86_l_584;
	case 1415ULL: goto x86_l_587;
	case 1419ULL: goto x86_l_58b;
	case 1425ULL: goto x86_l_591;
	case 1432ULL: goto x86_l_598;
	case 1437ULL: goto x86_l_59d;
	case 1441ULL: goto x86_l_5a1;
	case 1444ULL: goto x86_l_5a4;
	case 1448ULL: goto x86_l_5a8;
	case 1454ULL: goto x86_l_5ae;
	case 1461ULL: goto x86_l_5b5;
	case 1466ULL: goto x86_l_5ba;
	case 1470ULL: goto x86_l_5be;
	case 1473ULL: goto x86_l_5c1;
	case 1477ULL: goto x86_l_5c5;
	case 1483ULL: goto x86_l_5cb;
	case 1490ULL: goto x86_l_5d2;
	case 1495ULL: goto x86_l_5d7;
	case 1499ULL: goto x86_l_5db;
	case 1502ULL: goto x86_l_5de;
	case 1506ULL: goto x86_l_5e2;
	case 1512ULL: goto x86_l_5e8;
	case 1519ULL: goto x86_l_5ef;
	case 1524ULL: goto x86_l_5f4;
	case 1528ULL: goto x86_l_5f8;
	case 1531ULL: goto x86_l_5fb;
	case 1535ULL: goto x86_l_5ff;
	case 1541ULL: goto x86_l_605;
	case 1548ULL: goto x86_l_60c;
	case 1553ULL: goto x86_l_611;
	case 1557ULL: goto x86_l_615;
	case 1560ULL: goto x86_l_618;
	case 1564ULL: goto x86_l_61c;
	case 1570ULL: goto x86_l_622;
	case 1577ULL: goto x86_l_629;
	case 1582ULL: goto x86_l_62e;
	case 1586ULL: goto x86_l_632;
	case 1589ULL: goto x86_l_635;
	case 1593ULL: goto x86_l_639;
	case 1599ULL: goto x86_l_63f;
	case 1606ULL: goto x86_l_646;
	case 1611ULL: goto x86_l_64b;
	case 1615ULL: goto x86_l_64f;
	case 1618ULL: goto x86_l_652;
	case 1622ULL: goto x86_l_656;
	case 1628ULL: goto x86_l_65c;
	case 1635ULL: goto x86_l_663;
	case 1640ULL: goto x86_l_668;
	case 1644ULL: goto x86_l_66c;
	case 1647ULL: goto x86_l_66f;
	case 1651ULL: goto x86_l_673;
	case 1657ULL: goto x86_l_679;
	case 1664ULL: goto x86_l_680;
	case 1669ULL: goto x86_l_685;
	case 1673ULL: goto x86_l_689;
	case 1676ULL: goto x86_l_68c;
	case 1680ULL: goto x86_l_690;
	case 1686ULL: goto x86_l_696;
	case 1693ULL: goto x86_l_69d;
	case 1698ULL: goto x86_l_6a2;
	case 1702ULL: goto x86_l_6a6;
	case 1705ULL: goto x86_l_6a9;
	case 1709ULL: goto x86_l_6ad;
	case 1715ULL: goto x86_l_6b3;
	case 1722ULL: goto x86_l_6ba;
	case 1727ULL: goto x86_l_6bf;
	case 1731ULL: goto x86_l_6c3;
	case 1734ULL: goto x86_l_6c6;
	case 1738ULL: goto x86_l_6ca;
	case 1744ULL: goto x86_l_6d0;
	case 1751ULL: goto x86_l_6d7;
	case 1756ULL: goto x86_l_6dc;
	case 1760ULL: goto x86_l_6e0;
	case 1763ULL: goto x86_l_6e3;
	case 1767ULL: goto x86_l_6e7;
	case 1773ULL: goto x86_l_6ed;
	case 1780ULL: goto x86_l_6f4;
	case 1785ULL: goto x86_l_6f9;
	case 1789ULL: goto x86_l_6fd;
	case 1792ULL: goto x86_l_700;
	case 1796ULL: goto x86_l_704;
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
	/* 0x1c: mov    rdi,QWORD PTR [rip+0x17e0] */
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
	/* 0x32: je     3273 <generic_retuprobe_filter_arg_2+0x3273> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12915ULL;
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
	/* 0x49: mov    rdi,QWORD PTR [rip+0x17e0] */
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
	/* 0x5a: je     3258 <generic_retuprobe_filter_arg_2+0x3258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12888ULL;
	}
x86_l_60:
	/* 0x60: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_68:
	/* 0x68: je     3258 <generic_retuprobe_filter_arg_2+0x3258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12888ULL;
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
	/* 0x7d: je     31e1 <generic_retuprobe_filter_arg_2+0x31e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12769ULL;
	}
x86_l_83:
	/* 0x83: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_85:
	/* 0x85: mov    edx,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_89:
	/* 0x89: lea    rcx,[rdx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_8d:
	/* 0x8d: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_91:
	/* 0x91: mov    ebp,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_32);
x86_l_93:
	/* 0x93: and    ebp,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_99:
	/* 0x99: cmp    DWORD PTR [rax+rbp*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 25ULL);
x86_l_9d:
	/* 0x9d: jb     31d7 <generic_retuprobe_filter_arg_2+0x31d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12759ULL;
	}
x86_l_a3:
	/* 0xa3: mov    edx,DWORD PTR [rax+rbp*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 4ULL);
x86_l_a7:
	/* 0xa7: test   edx,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 1023ULL);
x86_l_ad:
	/* 0xad: je     31d7 <generic_retuprobe_filter_arg_2+0x31d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12759ULL;
	}
x86_l_b3:
	/* 0xb3: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b5:
	/* 0xb5: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_bb:
	/* 0xbb: mov    edx,DWORD PTR [rax+rcx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_be:
	/* 0xbe: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_c2:
	/* 0xc2: ja     31e1 <generic_retuprobe_filter_arg_2+0x31e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12769ULL;
	}
x86_l_c8:
	/* 0xc8: cmp    DWORD PTR [r14+rdx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 104041287778304ULL);
x86_l_d1:
	/* 0xd1: jne    31e1 <generic_retuprobe_filter_arg_2+0x31e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12769ULL;
	}
x86_l_d7:
	/* 0xd7: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_da:
	/* 0xda: add    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_dd:
	/* 0xdd: mov    ecx,DWORD PTR [rax+rcx*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 12ULL);
x86_l_e1:
	/* 0xe1: mov    rax,QWORD PTR [r14+rdx*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 24184ULL);
x86_l_e9:
	/* 0xe9: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_ee:
	/* 0xee: lea    r8,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_f2:
	/* 0xf2: add    r8,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_f9:
	/* 0xf9: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_fc:
	/* 0xfc: jg     123 <generic_retuprobe_filter_arg_2+0x123> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_123;
	}
x86_l_fe:
	/* 0xfe: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_101:
	/* 0x101: jg     c89 <generic_retuprobe_filter_arg_2+0xc89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3209ULL;
	}
x86_l_107:
	/* 0x107: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_10a:
	/* 0x10a: je     e48 <generic_retuprobe_filter_arg_2+0xe48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3656ULL;
	}
x86_l_110:
	/* 0x110: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_113:
	/* 0x113: je     ca7 <generic_retuprobe_filter_arg_2+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_119:
	/* 0x119: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_11c:
	/* 0x11c: je     138 <generic_retuprobe_filter_arg_2+0x138> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_138;
	}
x86_l_11e:
	/* 0x11e: jmp    31d7 <generic_retuprobe_filter_arg_2+0x31d7> */
	return 12759ULL;
x86_l_123:
	/* 0x123: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_126:
	/* 0x126: jg     c9f <generic_retuprobe_filter_arg_2+0xc9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3231ULL;
	}
x86_l_12c:
	/* 0x12c: lea    eax,[rcx-0x26] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_12f:
	/* 0x12f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_132:
	/* 0x132: jae    d10 <generic_retuprobe_filter_arg_2+0xd10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3344ULL;
	}
x86_l_138:
	/* 0x138: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13b:
	/* 0x13b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13e:
	/* 0x13e: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_141:
	/* 0x141: ja     31b7 <generic_retuprobe_filter_arg_2+0x31b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12727ULL;
	}
x86_l_147:
	/* 0x147: mov    r13d,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14a:
	/* 0x14a: add    r8,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_14e:
	/* 0x14e: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_153:
	/* 0x153: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_156:
	/* 0x156: jb     1aa4 <generic_retuprobe_filter_arg_2+0x1aa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6820ULL;
	}
x86_l_15c:
	/* 0x15c: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_161:
	/* 0x161: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_164:
	/* 0x164: jb     19ff <generic_retuprobe_filter_arg_2+0x19ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6655ULL;
	}
x86_l_16a:
	/* 0x16a: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_16f:
	/* 0x16f: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_172:
	/* 0x172: jae    31b7 <generic_retuprobe_filter_arg_2+0x31b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12727ULL;
	}
x86_l_178:
	/* 0x178: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17d:
	/* 0x17d: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_181:
	/* 0x181: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_184:
	/* 0x184: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_188:
	/* 0x188: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_190:
	/* 0x190: mov    rdi,QWORD PTR [rip+0x17e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_197:
	/* 0x197: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_19c:
	/* 0x19c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a1:
	/* 0x1a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a3:
	/* 0x1a3: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1a6:
	/* 0x1a6: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a9:
	/* 0x1a9: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1ac:
	/* 0x1ac: je     31b0 <generic_retuprobe_filter_arg_2+0x31b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12720ULL;
	}
x86_l_1b2:
	/* 0x1b2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b5:
	/* 0x1b5: je     31b0 <generic_retuprobe_filter_arg_2+0x31b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12720ULL;
	}
x86_l_1bb:
	/* 0x1bb: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1be:
	/* 0x1be: mov    rdi,QWORD PTR [rip+0x17e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_1c5:
	/* 0x1c5: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ca:
	/* 0x1ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cf:
	/* 0x1cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d1:
	/* 0x1d1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d4:
	/* 0x1d4: je     31ad <generic_retuprobe_filter_arg_2+0x31ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12717ULL;
	}
x86_l_1da:
	/* 0x1da: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1dd:
	/* 0x1dd: cmp    r13d,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 94ULL);
x86_l_1e1:
	/* 0x1e1: mov    eax,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 94ULL);
x86_l_1e6:
	/* 0x1e6: cmovb  eax,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_1ea:
	/* 0x1ea: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1ed:
	/* 0x1ed: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ef:
	/* 0x1ef: lea    eax,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1f3:
	/* 0x1f3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f8:
	/* 0x1f8: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fd:
	/* 0x1fd: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_201:
	/* 0x201: mov    BYTE PTR [rsi+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_204:
	/* 0x204: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_208:
	/* 0x208: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_20e:
	/* 0x20e: lea    eax,[r13+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_215:
	/* 0x215: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21a:
	/* 0x21a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_21e:
	/* 0x21e: mov    BYTE PTR [rsi+0x5],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_221:
	/* 0x221: cmp    r13,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 2ULL);
x86_l_225:
	/* 0x225: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_22b:
	/* 0x22b: lea    eax,[r13+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_232:
	/* 0x232: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_237:
	/* 0x237: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_23b:
	/* 0x23b: mov    BYTE PTR [rsi+0x6],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_23e:
	/* 0x23e: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_242:
	/* 0x242: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_248:
	/* 0x248: lea    eax,[r13+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_24f:
	/* 0x24f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_254:
	/* 0x254: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_258:
	/* 0x258: mov    BYTE PTR [rsi+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_25b:
	/* 0x25b: cmp    r13,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4ULL);
x86_l_25f:
	/* 0x25f: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_265:
	/* 0x265: lea    eax,[r13+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_26c:
	/* 0x26c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_271:
	/* 0x271: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_275:
	/* 0x275: mov    BYTE PTR [rsi+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_278:
	/* 0x278: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_27c:
	/* 0x27c: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_282:
	/* 0x282: lea    eax,[r13+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_289:
	/* 0x289: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_28e:
	/* 0x28e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_292:
	/* 0x292: mov    BYTE PTR [rsi+0x9],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_295:
	/* 0x295: cmp    r13,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 6ULL);
x86_l_299:
	/* 0x299: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_29f:
	/* 0x29f: lea    eax,[r13+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_2a6:
	/* 0x2a6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2ab:
	/* 0x2ab: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2af:
	/* 0x2af: mov    BYTE PTR [rsi+0xa],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_2b2:
	/* 0x2b2: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_2b6:
	/* 0x2b6: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_2bc:
	/* 0x2bc: lea    eax,[r13+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_2c3:
	/* 0x2c3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c8:
	/* 0x2c8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2cc:
	/* 0x2cc: mov    BYTE PTR [rsi+0xb],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_2cf:
	/* 0x2cf: cmp    r13,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 8ULL);
x86_l_2d3:
	/* 0x2d3: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_2d9:
	/* 0x2d9: lea    eax,[r13+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_2e0:
	/* 0x2e0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2e5:
	/* 0x2e5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2e9:
	/* 0x2e9: mov    BYTE PTR [rsi+0xc],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2ec:
	/* 0x2ec: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_2f0:
	/* 0x2f0: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_2f6:
	/* 0x2f6: lea    eax,[r13+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_2fd:
	/* 0x2fd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_302:
	/* 0x302: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_306:
	/* 0x306: mov    BYTE PTR [rsi+0xd],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_309:
	/* 0x309: cmp    r13,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 10ULL);
x86_l_30d:
	/* 0x30d: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_313:
	/* 0x313: lea    eax,[r13+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_31a:
	/* 0x31a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_31f:
	/* 0x31f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_323:
	/* 0x323: mov    BYTE PTR [rsi+0xe],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_326:
	/* 0x326: cmp    r13,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 11ULL);
x86_l_32a:
	/* 0x32a: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_330:
	/* 0x330: lea    eax,[r13+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_337:
	/* 0x337: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_33c:
	/* 0x33c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_340:
	/* 0x340: mov    BYTE PTR [rsi+0xf],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_343:
	/* 0x343: cmp    r13,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 12ULL);
x86_l_347:
	/* 0x347: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_34d:
	/* 0x34d: lea    eax,[r13+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_354:
	/* 0x354: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_359:
	/* 0x359: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_35d:
	/* 0x35d: mov    BYTE PTR [rsi+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_360:
	/* 0x360: cmp    r13,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 13ULL);
x86_l_364:
	/* 0x364: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_36a:
	/* 0x36a: lea    eax,[r13+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_371:
	/* 0x371: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_376:
	/* 0x376: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_37a:
	/* 0x37a: mov    BYTE PTR [rsi+0x11],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_37d:
	/* 0x37d: cmp    r13,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 14ULL);
x86_l_381:
	/* 0x381: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_387:
	/* 0x387: lea    eax,[r13+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_38e:
	/* 0x38e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_393:
	/* 0x393: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_397:
	/* 0x397: mov    BYTE PTR [rsi+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_39a:
	/* 0x39a: cmp    r13,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 15ULL);
x86_l_39e:
	/* 0x39e: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_3a4:
	/* 0x3a4: lea    eax,[r13+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_3ab:
	/* 0x3ab: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3b0:
	/* 0x3b0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3b4:
	/* 0x3b4: mov    BYTE PTR [rsi+0x13],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_3b7:
	/* 0x3b7: cmp    r13,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 16ULL);
x86_l_3bb:
	/* 0x3bb: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_3c1:
	/* 0x3c1: lea    eax,[r13+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_3c8:
	/* 0x3c8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3cd:
	/* 0x3cd: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3d1:
	/* 0x3d1: mov    BYTE PTR [rsi+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3d4:
	/* 0x3d4: cmp    r13,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 17ULL);
x86_l_3d8:
	/* 0x3d8: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_3de:
	/* 0x3de: lea    eax,[r13+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_3e5:
	/* 0x3e5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3ea:
	/* 0x3ea: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_3ee:
	/* 0x3ee: mov    BYTE PTR [rsi+0x15],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_3f1:
	/* 0x3f1: cmp    r13,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18ULL);
x86_l_3f5:
	/* 0x3f5: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_3fb:
	/* 0x3fb: lea    eax,[r13+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_402:
	/* 0x402: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_407:
	/* 0x407: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_40b:
	/* 0x40b: mov    BYTE PTR [rsi+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_40e:
	/* 0x40e: cmp    r13,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 19ULL);
x86_l_412:
	/* 0x412: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_418:
	/* 0x418: lea    eax,[r13+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_41f:
	/* 0x41f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_424:
	/* 0x424: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_428:
	/* 0x428: mov    BYTE PTR [rsi+0x17],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_42b:
	/* 0x42b: cmp    r13,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 20ULL);
x86_l_42f:
	/* 0x42f: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_435:
	/* 0x435: lea    eax,[r13+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_43c:
	/* 0x43c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_441:
	/* 0x441: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_445:
	/* 0x445: mov    BYTE PTR [rsi+0x18],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_448:
	/* 0x448: cmp    r13,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 21ULL);
x86_l_44c:
	/* 0x44c: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_452:
	/* 0x452: lea    eax,[r13+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_459:
	/* 0x459: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_45e:
	/* 0x45e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_462:
	/* 0x462: mov    BYTE PTR [rsi+0x19],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_465:
	/* 0x465: cmp    r13,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 22ULL);
x86_l_469:
	/* 0x469: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_46f:
	/* 0x46f: lea    eax,[r13+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_476:
	/* 0x476: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_47b:
	/* 0x47b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_47f:
	/* 0x47f: mov    BYTE PTR [rsi+0x1a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_482:
	/* 0x482: cmp    r13,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 23ULL);
x86_l_486:
	/* 0x486: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_48c:
	/* 0x48c: lea    eax,[r13+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_493:
	/* 0x493: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_498:
	/* 0x498: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_49c:
	/* 0x49c: mov    BYTE PTR [rsi+0x1b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_49f:
	/* 0x49f: cmp    r13,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 24ULL);
x86_l_4a3:
	/* 0x4a3: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_4a9:
	/* 0x4a9: lea    eax,[r13+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_4b0:
	/* 0x4b0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4b5:
	/* 0x4b5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4b9:
	/* 0x4b9: mov    BYTE PTR [rsi+0x1c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4bc:
	/* 0x4bc: cmp    r13,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 25ULL);
x86_l_4c0:
	/* 0x4c0: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_4c6:
	/* 0x4c6: lea    eax,[r13+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_4cd:
	/* 0x4cd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4d2:
	/* 0x4d2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4d6:
	/* 0x4d6: mov    BYTE PTR [rsi+0x1d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_4d9:
	/* 0x4d9: cmp    r13,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 26ULL);
x86_l_4dd:
	/* 0x4dd: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_4e3:
	/* 0x4e3: lea    eax,[r13+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_4ea:
	/* 0x4ea: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4ef:
	/* 0x4ef: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_4f3:
	/* 0x4f3: mov    BYTE PTR [rsi+0x1e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_4f6:
	/* 0x4f6: cmp    r13,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 27ULL);
x86_l_4fa:
	/* 0x4fa: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_500:
	/* 0x500: lea    eax,[r13+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_507:
	/* 0x507: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_50c:
	/* 0x50c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_510:
	/* 0x510: mov    BYTE PTR [rsi+0x1f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_513:
	/* 0x513: cmp    r13,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 28ULL);
x86_l_517:
	/* 0x517: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_51d:
	/* 0x51d: lea    eax,[r13+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_524:
	/* 0x524: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_529:
	/* 0x529: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_52d:
	/* 0x52d: mov    BYTE PTR [rsi+0x20],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_530:
	/* 0x530: cmp    r13,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 29ULL);
x86_l_534:
	/* 0x534: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_53a:
	/* 0x53a: lea    eax,[r13+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_541:
	/* 0x541: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_546:
	/* 0x546: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_54a:
	/* 0x54a: mov    BYTE PTR [rsi+0x21],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_54d:
	/* 0x54d: cmp    r13,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 30ULL);
x86_l_551:
	/* 0x551: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_557:
	/* 0x557: lea    eax,[r13+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_55e:
	/* 0x55e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_563:
	/* 0x563: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_567:
	/* 0x567: mov    BYTE PTR [rsi+0x22],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_56a:
	/* 0x56a: cmp    r13,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 31ULL);
x86_l_56e:
	/* 0x56e: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_574:
	/* 0x574: lea    eax,[r13+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_57b:
	/* 0x57b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_580:
	/* 0x580: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_584:
	/* 0x584: mov    BYTE PTR [rsi+0x23],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_587:
	/* 0x587: cmp    r13,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 32ULL);
x86_l_58b:
	/* 0x58b: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_591:
	/* 0x591: lea    eax,[r13+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_598:
	/* 0x598: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_59d:
	/* 0x59d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_5a1:
	/* 0x5a1: mov    BYTE PTR [rsi+0x24],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5a4:
	/* 0x5a4: cmp    r13,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 33ULL);
x86_l_5a8:
	/* 0x5a8: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_5ae:
	/* 0x5ae: lea    eax,[r13+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_5b5:
	/* 0x5b5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5ba:
	/* 0x5ba: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_5be:
	/* 0x5be: mov    BYTE PTR [rsi+0x25],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_5c1:
	/* 0x5c1: cmp    r13,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 34ULL);
x86_l_5c5:
	/* 0x5c5: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_5cb:
	/* 0x5cb: lea    eax,[r13+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_5d2:
	/* 0x5d2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5d7:
	/* 0x5d7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_5db:
	/* 0x5db: mov    BYTE PTR [rsi+0x26],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_5de:
	/* 0x5de: cmp    r13,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 35ULL);
x86_l_5e2:
	/* 0x5e2: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_5e8:
	/* 0x5e8: lea    eax,[r13+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_5ef:
	/* 0x5ef: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5f4:
	/* 0x5f4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_5f8:
	/* 0x5f8: mov    BYTE PTR [rsi+0x27],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_5fb:
	/* 0x5fb: cmp    r13,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 36ULL);
x86_l_5ff:
	/* 0x5ff: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_605:
	/* 0x605: lea    eax,[r13+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_60c:
	/* 0x60c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_611:
	/* 0x611: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_615:
	/* 0x615: mov    BYTE PTR [rsi+0x28],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_618:
	/* 0x618: cmp    r13,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 37ULL);
x86_l_61c:
	/* 0x61c: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_622:
	/* 0x622: lea    eax,[r13+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_629:
	/* 0x629: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_62e:
	/* 0x62e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_632:
	/* 0x632: mov    BYTE PTR [rsi+0x29],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_635:
	/* 0x635: cmp    r13,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 38ULL);
x86_l_639:
	/* 0x639: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_63f:
	/* 0x63f: lea    eax,[r13+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_646:
	/* 0x646: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_64b:
	/* 0x64b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_64f:
	/* 0x64f: mov    BYTE PTR [rsi+0x2a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_652:
	/* 0x652: cmp    r13,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 39ULL);
x86_l_656:
	/* 0x656: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_65c:
	/* 0x65c: lea    eax,[r13+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_663:
	/* 0x663: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_668:
	/* 0x668: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_66c:
	/* 0x66c: mov    BYTE PTR [rsi+0x2b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_66f:
	/* 0x66f: cmp    r13,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 40ULL);
x86_l_673:
	/* 0x673: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_679:
	/* 0x679: lea    eax,[r13+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_680:
	/* 0x680: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_685:
	/* 0x685: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_689:
	/* 0x689: mov    BYTE PTR [rsi+0x2c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_68c:
	/* 0x68c: cmp    r13,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 41ULL);
x86_l_690:
	/* 0x690: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_696:
	/* 0x696: lea    eax,[r13+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_69d:
	/* 0x69d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6a2:
	/* 0x6a2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_6a6:
	/* 0x6a6: mov    BYTE PTR [rsi+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_6a9:
	/* 0x6a9: cmp    r13,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 42ULL);
x86_l_6ad:
	/* 0x6ad: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_6b3:
	/* 0x6b3: lea    eax,[r13+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_6ba:
	/* 0x6ba: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6bf:
	/* 0x6bf: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_6c3:
	/* 0x6c3: mov    BYTE PTR [rsi+0x2e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_6c6:
	/* 0x6c6: cmp    r13,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 43ULL);
x86_l_6ca:
	/* 0x6ca: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_6d0:
	/* 0x6d0: lea    eax,[r13+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_6d7:
	/* 0x6d7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6dc:
	/* 0x6dc: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_6e0:
	/* 0x6e0: mov    BYTE PTR [rsi+0x2f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_6e3:
	/* 0x6e3: cmp    r13,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 44ULL);
x86_l_6e7:
	/* 0x6e7: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
x86_l_6ed:
	/* 0x6ed: lea    eax,[r13+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_6f4:
	/* 0x6f4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6f9:
	/* 0x6f9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_6fd:
	/* 0x6fd: mov    BYTE PTR [rsi+0x30],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_700:
	/* 0x700: cmp    r13,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 45ULL);
x86_l_704:
	/* 0x704: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3196ULL;
	}
	return 1802ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1802ULL: goto x86_l_70a;
	case 1809ULL: goto x86_l_711;
	case 1814ULL: goto x86_l_716;
	case 1818ULL: goto x86_l_71a;
	case 1821ULL: goto x86_l_71d;
	case 1825ULL: goto x86_l_721;
	case 1831ULL: goto x86_l_727;
	case 1838ULL: goto x86_l_72e;
	case 1843ULL: goto x86_l_733;
	case 1847ULL: goto x86_l_737;
	case 1850ULL: goto x86_l_73a;
	case 1854ULL: goto x86_l_73e;
	case 1860ULL: goto x86_l_744;
	case 1867ULL: goto x86_l_74b;
	case 1872ULL: goto x86_l_750;
	case 1876ULL: goto x86_l_754;
	case 1879ULL: goto x86_l_757;
	case 1883ULL: goto x86_l_75b;
	case 1889ULL: goto x86_l_761;
	case 1896ULL: goto x86_l_768;
	case 1901ULL: goto x86_l_76d;
	case 1905ULL: goto x86_l_771;
	case 1908ULL: goto x86_l_774;
	case 1912ULL: goto x86_l_778;
	case 1918ULL: goto x86_l_77e;
	case 1925ULL: goto x86_l_785;
	case 1930ULL: goto x86_l_78a;
	case 1934ULL: goto x86_l_78e;
	case 1937ULL: goto x86_l_791;
	case 1941ULL: goto x86_l_795;
	case 1947ULL: goto x86_l_79b;
	case 1954ULL: goto x86_l_7a2;
	case 1959ULL: goto x86_l_7a7;
	case 1963ULL: goto x86_l_7ab;
	case 1966ULL: goto x86_l_7ae;
	case 1970ULL: goto x86_l_7b2;
	case 1976ULL: goto x86_l_7b8;
	case 1983ULL: goto x86_l_7bf;
	case 1988ULL: goto x86_l_7c4;
	case 1992ULL: goto x86_l_7c8;
	case 1995ULL: goto x86_l_7cb;
	case 1999ULL: goto x86_l_7cf;
	case 2005ULL: goto x86_l_7d5;
	case 2012ULL: goto x86_l_7dc;
	case 2017ULL: goto x86_l_7e1;
	case 2021ULL: goto x86_l_7e5;
	case 2024ULL: goto x86_l_7e8;
	case 2028ULL: goto x86_l_7ec;
	case 2034ULL: goto x86_l_7f2;
	case 2041ULL: goto x86_l_7f9;
	case 2046ULL: goto x86_l_7fe;
	case 2050ULL: goto x86_l_802;
	case 2053ULL: goto x86_l_805;
	case 2057ULL: goto x86_l_809;
	case 2063ULL: goto x86_l_80f;
	case 2070ULL: goto x86_l_816;
	case 2075ULL: goto x86_l_81b;
	case 2079ULL: goto x86_l_81f;
	case 2082ULL: goto x86_l_822;
	case 2086ULL: goto x86_l_826;
	case 2092ULL: goto x86_l_82c;
	case 2099ULL: goto x86_l_833;
	case 2104ULL: goto x86_l_838;
	case 2108ULL: goto x86_l_83c;
	case 2111ULL: goto x86_l_83f;
	case 2115ULL: goto x86_l_843;
	case 2121ULL: goto x86_l_849;
	case 2128ULL: goto x86_l_850;
	case 2133ULL: goto x86_l_855;
	case 2137ULL: goto x86_l_859;
	case 2140ULL: goto x86_l_85c;
	case 2144ULL: goto x86_l_860;
	case 2150ULL: goto x86_l_866;
	case 2157ULL: goto x86_l_86d;
	case 2162ULL: goto x86_l_872;
	case 2166ULL: goto x86_l_876;
	case 2169ULL: goto x86_l_879;
	case 2173ULL: goto x86_l_87d;
	case 2179ULL: goto x86_l_883;
	case 2186ULL: goto x86_l_88a;
	case 2191ULL: goto x86_l_88f;
	case 2195ULL: goto x86_l_893;
	case 2198ULL: goto x86_l_896;
	case 2202ULL: goto x86_l_89a;
	case 2208ULL: goto x86_l_8a0;
	case 2215ULL: goto x86_l_8a7;
	case 2220ULL: goto x86_l_8ac;
	case 2224ULL: goto x86_l_8b0;
	case 2227ULL: goto x86_l_8b3;
	case 2231ULL: goto x86_l_8b7;
	case 2237ULL: goto x86_l_8bd;
	case 2244ULL: goto x86_l_8c4;
	case 2249ULL: goto x86_l_8c9;
	case 2253ULL: goto x86_l_8cd;
	case 2256ULL: goto x86_l_8d0;
	case 2260ULL: goto x86_l_8d4;
	case 2266ULL: goto x86_l_8da;
	case 2273ULL: goto x86_l_8e1;
	case 2278ULL: goto x86_l_8e6;
	case 2282ULL: goto x86_l_8ea;
	case 2285ULL: goto x86_l_8ed;
	case 2289ULL: goto x86_l_8f1;
	case 2295ULL: goto x86_l_8f7;
	case 2302ULL: goto x86_l_8fe;
	case 2307ULL: goto x86_l_903;
	case 2311ULL: goto x86_l_907;
	case 2314ULL: goto x86_l_90a;
	case 2318ULL: goto x86_l_90e;
	case 2324ULL: goto x86_l_914;
	case 2331ULL: goto x86_l_91b;
	case 2336ULL: goto x86_l_920;
	case 2340ULL: goto x86_l_924;
	case 2343ULL: goto x86_l_927;
	case 2347ULL: goto x86_l_92b;
	case 2353ULL: goto x86_l_931;
	case 2360ULL: goto x86_l_938;
	case 2365ULL: goto x86_l_93d;
	case 2369ULL: goto x86_l_941;
	case 2372ULL: goto x86_l_944;
	case 2376ULL: goto x86_l_948;
	case 2382ULL: goto x86_l_94e;
	case 2389ULL: goto x86_l_955;
	case 2394ULL: goto x86_l_95a;
	case 2398ULL: goto x86_l_95e;
	case 2401ULL: goto x86_l_961;
	case 2405ULL: goto x86_l_965;
	case 2411ULL: goto x86_l_96b;
	case 2418ULL: goto x86_l_972;
	case 2423ULL: goto x86_l_977;
	case 2427ULL: goto x86_l_97b;
	case 2430ULL: goto x86_l_97e;
	case 2434ULL: goto x86_l_982;
	case 2440ULL: goto x86_l_988;
	case 2447ULL: goto x86_l_98f;
	case 2452ULL: goto x86_l_994;
	case 2456ULL: goto x86_l_998;
	case 2459ULL: goto x86_l_99b;
	case 2463ULL: goto x86_l_99f;
	case 2469ULL: goto x86_l_9a5;
	case 2476ULL: goto x86_l_9ac;
	case 2481ULL: goto x86_l_9b1;
	case 2485ULL: goto x86_l_9b5;
	case 2488ULL: goto x86_l_9b8;
	case 2492ULL: goto x86_l_9bc;
	case 2498ULL: goto x86_l_9c2;
	case 2505ULL: goto x86_l_9c9;
	case 2510ULL: goto x86_l_9ce;
	case 2514ULL: goto x86_l_9d2;
	case 2517ULL: goto x86_l_9d5;
	case 2521ULL: goto x86_l_9d9;
	case 2527ULL: goto x86_l_9df;
	case 2534ULL: goto x86_l_9e6;
	case 2539ULL: goto x86_l_9eb;
	case 2543ULL: goto x86_l_9ef;
	case 2546ULL: goto x86_l_9f2;
	case 2550ULL: goto x86_l_9f6;
	case 2556ULL: goto x86_l_9fc;
	case 2563ULL: goto x86_l_a03;
	case 2568ULL: goto x86_l_a08;
	case 2572ULL: goto x86_l_a0c;
	case 2575ULL: goto x86_l_a0f;
	case 2579ULL: goto x86_l_a13;
	case 2585ULL: goto x86_l_a19;
	case 2592ULL: goto x86_l_a20;
	case 2597ULL: goto x86_l_a25;
	case 2601ULL: goto x86_l_a29;
	case 2604ULL: goto x86_l_a2c;
	case 2608ULL: goto x86_l_a30;
	case 2614ULL: goto x86_l_a36;
	case 2621ULL: goto x86_l_a3d;
	case 2626ULL: goto x86_l_a42;
	case 2630ULL: goto x86_l_a46;
	case 2633ULL: goto x86_l_a49;
	case 2637ULL: goto x86_l_a4d;
	case 2643ULL: goto x86_l_a53;
	case 2650ULL: goto x86_l_a5a;
	case 2655ULL: goto x86_l_a5f;
	case 2659ULL: goto x86_l_a63;
	case 2662ULL: goto x86_l_a66;
	case 2666ULL: goto x86_l_a6a;
	case 2672ULL: goto x86_l_a70;
	case 2679ULL: goto x86_l_a77;
	case 2684ULL: goto x86_l_a7c;
	case 2688ULL: goto x86_l_a80;
	case 2691ULL: goto x86_l_a83;
	case 2695ULL: goto x86_l_a87;
	case 2701ULL: goto x86_l_a8d;
	case 2708ULL: goto x86_l_a94;
	case 2713ULL: goto x86_l_a99;
	case 2717ULL: goto x86_l_a9d;
	case 2720ULL: goto x86_l_aa0;
	case 2724ULL: goto x86_l_aa4;
	case 2730ULL: goto x86_l_aaa;
	case 2737ULL: goto x86_l_ab1;
	case 2742ULL: goto x86_l_ab6;
	case 2746ULL: goto x86_l_aba;
	case 2749ULL: goto x86_l_abd;
	case 2753ULL: goto x86_l_ac1;
	case 2759ULL: goto x86_l_ac7;
	case 2766ULL: goto x86_l_ace;
	case 2771ULL: goto x86_l_ad3;
	case 2775ULL: goto x86_l_ad7;
	case 2778ULL: goto x86_l_ada;
	case 2782ULL: goto x86_l_ade;
	case 2788ULL: goto x86_l_ae4;
	case 2795ULL: goto x86_l_aeb;
	case 2800ULL: goto x86_l_af0;
	case 2804ULL: goto x86_l_af4;
	case 2807ULL: goto x86_l_af7;
	case 2811ULL: goto x86_l_afb;
	case 2817ULL: goto x86_l_b01;
	case 2824ULL: goto x86_l_b08;
	case 2829ULL: goto x86_l_b0d;
	case 2833ULL: goto x86_l_b11;
	case 2836ULL: goto x86_l_b14;
	case 2840ULL: goto x86_l_b18;
	case 2846ULL: goto x86_l_b1e;
	case 2853ULL: goto x86_l_b25;
	case 2858ULL: goto x86_l_b2a;
	case 2862ULL: goto x86_l_b2e;
	case 2865ULL: goto x86_l_b31;
	case 2869ULL: goto x86_l_b35;
	case 2875ULL: goto x86_l_b3b;
	case 2882ULL: goto x86_l_b42;
	case 2887ULL: goto x86_l_b47;
	case 2891ULL: goto x86_l_b4b;
	case 2894ULL: goto x86_l_b4e;
	case 2898ULL: goto x86_l_b52;
	case 2904ULL: goto x86_l_b58;
	case 2911ULL: goto x86_l_b5f;
	case 2916ULL: goto x86_l_b64;
	case 2920ULL: goto x86_l_b68;
	case 2923ULL: goto x86_l_b6b;
	case 2927ULL: goto x86_l_b6f;
	case 2933ULL: goto x86_l_b75;
	case 2940ULL: goto x86_l_b7c;
	case 2945ULL: goto x86_l_b81;
	case 2949ULL: goto x86_l_b85;
	case 2952ULL: goto x86_l_b88;
	case 2956ULL: goto x86_l_b8c;
	case 2962ULL: goto x86_l_b92;
	case 2969ULL: goto x86_l_b99;
	case 2974ULL: goto x86_l_b9e;
	case 2978ULL: goto x86_l_ba2;
	case 2981ULL: goto x86_l_ba5;
	case 2985ULL: goto x86_l_ba9;
	case 2991ULL: goto x86_l_baf;
	case 2998ULL: goto x86_l_bb6;
	case 3003ULL: goto x86_l_bbb;
	case 3007ULL: goto x86_l_bbf;
	case 3010ULL: goto x86_l_bc2;
	case 3014ULL: goto x86_l_bc6;
	case 3020ULL: goto x86_l_bcc;
	case 3027ULL: goto x86_l_bd3;
	case 3032ULL: goto x86_l_bd8;
	case 3036ULL: goto x86_l_bdc;
	case 3039ULL: goto x86_l_bdf;
	case 3043ULL: goto x86_l_be3;
	case 3049ULL: goto x86_l_be9;
	case 3056ULL: goto x86_l_bf0;
	case 3061ULL: goto x86_l_bf5;
	case 3065ULL: goto x86_l_bf9;
	case 3068ULL: goto x86_l_bfc;
	case 3072ULL: goto x86_l_c00;
	case 3074ULL: goto x86_l_c02;
	case 3081ULL: goto x86_l_c09;
	case 3086ULL: goto x86_l_c0e;
	case 3090ULL: goto x86_l_c12;
	case 3093ULL: goto x86_l_c15;
	case 3097ULL: goto x86_l_c19;
	case 3099ULL: goto x86_l_c1b;
	case 3106ULL: goto x86_l_c22;
	case 3111ULL: goto x86_l_c27;
	case 3115ULL: goto x86_l_c2b;
	case 3118ULL: goto x86_l_c2e;
	case 3122ULL: goto x86_l_c32;
	case 3124ULL: goto x86_l_c34;
	case 3131ULL: goto x86_l_c3b;
	case 3136ULL: goto x86_l_c40;
	case 3140ULL: goto x86_l_c44;
	case 3143ULL: goto x86_l_c47;
	case 3147ULL: goto x86_l_c4b;
	case 3149ULL: goto x86_l_c4d;
	case 3156ULL: goto x86_l_c54;
	case 3161ULL: goto x86_l_c59;
	case 3165ULL: goto x86_l_c5d;
	case 3168ULL: goto x86_l_c60;
	case 3172ULL: goto x86_l_c64;
	case 3174ULL: goto x86_l_c66;
	case 3181ULL: goto x86_l_c6d;
	case 3188ULL: goto x86_l_c74;
	case 3193ULL: goto x86_l_c79;
	case 3196ULL: goto x86_l_c7c;
	case 3201ULL: goto x86_l_c81;
	case 3204ULL: goto x86_l_c84;
	case 3209ULL: goto x86_l_c89;
	case 3212ULL: goto x86_l_c8c;
	case 3215ULL: goto x86_l_c8f;
	case 3221ULL: goto x86_l_c95;
	case 3224ULL: goto x86_l_c98;
	case 3226ULL: goto x86_l_c9a;
	case 3231ULL: goto x86_l_c9f;
	case 3234ULL: goto x86_l_ca2;
	case 3237ULL: goto x86_l_ca5;
	case 3239ULL: goto x86_l_ca7;
	case 3248ULL: goto x86_l_cb0;
	case 3257ULL: goto x86_l_cb9;
	case 3266ULL: goto x86_l_cc2;
	case 3275ULL: goto x86_l_ccb;
	case 3284ULL: goto x86_l_cd4;
	case 3287ULL: goto x86_l_cd7;
	case 3290ULL: goto x86_l_cda;
	case 3292ULL: goto x86_l_cdc;
	case 3295ULL: goto x86_l_cdf;
	case 3301ULL: goto x86_l_ce5;
	case 3304ULL: goto x86_l_ce8;
	case 3307ULL: goto x86_l_ceb;
	case 3313ULL: goto x86_l_cf1;
	case 3318ULL: goto x86_l_cf6;
	case 3321ULL: goto x86_l_cf9;
	case 3327ULL: goto x86_l_cff;
	case 3330ULL: goto x86_l_d02;
	case 3333ULL: goto x86_l_d05;
	case 3339ULL: goto x86_l_d0b;
	case 3344ULL: goto x86_l_d10;
	case 3347ULL: goto x86_l_d13;
	case 3353ULL: goto x86_l_d19;
	case 3357ULL: goto x86_l_d1d;
	case 3359ULL: goto x86_l_d1f;
	case 3362ULL: goto x86_l_d22;
	case 3368ULL: goto x86_l_d28;
	case 3371ULL: goto x86_l_d2b;
	case 3374ULL: goto x86_l_d2e;
	case 3377ULL: goto x86_l_d31;
	case 3379ULL: goto x86_l_d33;
	case 3381ULL: goto x86_l_d35;
	case 3384ULL: goto x86_l_d38;
	case 3387ULL: goto x86_l_d3b;
	case 3393ULL: goto x86_l_d41;
	case 3396ULL: goto x86_l_d44;
	case 3402ULL: goto x86_l_d4a;
	case 3404ULL: goto x86_l_d4c;
	case 3409ULL: goto x86_l_d51;
	case 3413ULL: goto x86_l_d55;
	case 3419ULL: goto x86_l_d5b;
	case 3424ULL: goto x86_l_d60;
	case 3428ULL: goto x86_l_d64;
	case 3434ULL: goto x86_l_d6a;
	case 3444ULL: goto x86_l_d74;
	case 3448ULL: goto x86_l_d78;
	case 3454ULL: goto x86_l_d7e;
	case 3461ULL: goto x86_l_d85;
	case 3468ULL: goto x86_l_d8c;
	case 3474ULL: goto x86_l_d92;
	case 3478ULL: goto x86_l_d96;
	case 3482ULL: goto x86_l_d9a;
	case 3487ULL: goto x86_l_d9f;
	case 3492ULL: goto x86_l_da4;
	case 3497ULL: goto x86_l_da9;
	case 3500ULL: goto x86_l_dac;
	case 3504ULL: goto x86_l_db0;
	case 3508ULL: goto x86_l_db4;
	case 3511ULL: goto x86_l_db7;
	case 3516ULL: goto x86_l_dbc;
	case 3518ULL: goto x86_l_dbe;
	case 3521ULL: goto x86_l_dc1;
	case 3525ULL: goto x86_l_dc5;
	case 3527ULL: goto x86_l_dc7;
	case 3533ULL: goto x86_l_dcd;
	case 3538ULL: goto x86_l_dd2;
	case 3543ULL: goto x86_l_dd7;
	case 3549ULL: goto x86_l_ddd;
	case 3551ULL: goto x86_l_ddf;
	case 3557ULL: goto x86_l_de5;
	case 3560ULL: goto x86_l_de8;
	case 3563ULL: goto x86_l_deb;
	case 3569ULL: goto x86_l_df1;
	case 3573ULL: goto x86_l_df5;
	case 3575ULL: goto x86_l_df7;
	case 3581ULL: goto x86_l_dfd;
	case 3583ULL: goto x86_l_dff;
	case 3589ULL: goto x86_l_e05;
	case 3592ULL: goto x86_l_e08;
	case 3598ULL: goto x86_l_e0e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_70a:
	/* 0x70a: lea    eax,[r13+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_711:
	/* 0x711: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_716:
	/* 0x716: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_71a:
	/* 0x71a: mov    BYTE PTR [rsi+0x31],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_71d:
	/* 0x71d: cmp    r13,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 46ULL);
x86_l_721:
	/* 0x721: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_727:
	/* 0x727: lea    eax,[r13+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_72e:
	/* 0x72e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_733:
	/* 0x733: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_737:
	/* 0x737: mov    BYTE PTR [rsi+0x32],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_73a:
	/* 0x73a: cmp    r13,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 47ULL);
x86_l_73e:
	/* 0x73e: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_744:
	/* 0x744: lea    eax,[r13+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_74b:
	/* 0x74b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_750:
	/* 0x750: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_754:
	/* 0x754: mov    BYTE PTR [rsi+0x33],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_757:
	/* 0x757: cmp    r13,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 48ULL);
x86_l_75b:
	/* 0x75b: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_761:
	/* 0x761: lea    eax,[r13+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_768:
	/* 0x768: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_76d:
	/* 0x76d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_771:
	/* 0x771: mov    BYTE PTR [rsi+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_774:
	/* 0x774: cmp    r13,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 49ULL);
x86_l_778:
	/* 0x778: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_77e:
	/* 0x77e: lea    eax,[r13+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_785:
	/* 0x785: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_78a:
	/* 0x78a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_78e:
	/* 0x78e: mov    BYTE PTR [rsi+0x35],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_791:
	/* 0x791: cmp    r13,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 50ULL);
x86_l_795:
	/* 0x795: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_79b:
	/* 0x79b: lea    eax,[r13+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_7a2:
	/* 0x7a2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7a7:
	/* 0x7a7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_7ab:
	/* 0x7ab: mov    BYTE PTR [rsi+0x36],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_7ae:
	/* 0x7ae: cmp    r13,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 51ULL);
x86_l_7b2:
	/* 0x7b2: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_7b8:
	/* 0x7b8: lea    eax,[r13+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_7bf:
	/* 0x7bf: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7c4:
	/* 0x7c4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_7c8:
	/* 0x7c8: mov    BYTE PTR [rsi+0x37],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_7cb:
	/* 0x7cb: cmp    r13,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 52ULL);
x86_l_7cf:
	/* 0x7cf: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_7d5:
	/* 0x7d5: lea    eax,[r13+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_7dc:
	/* 0x7dc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7e1:
	/* 0x7e1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_7e5:
	/* 0x7e5: mov    BYTE PTR [rsi+0x38],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7e8:
	/* 0x7e8: cmp    r13,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 53ULL);
x86_l_7ec:
	/* 0x7ec: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_7f2:
	/* 0x7f2: lea    eax,[r13+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_7f9:
	/* 0x7f9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_7fe:
	/* 0x7fe: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_802:
	/* 0x802: mov    BYTE PTR [rsi+0x39],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_805:
	/* 0x805: cmp    r13,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 54ULL);
x86_l_809:
	/* 0x809: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_80f:
	/* 0x80f: lea    eax,[r13+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_816:
	/* 0x816: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_81b:
	/* 0x81b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_81f:
	/* 0x81f: mov    BYTE PTR [rsi+0x3a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_822:
	/* 0x822: cmp    r13,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 55ULL);
x86_l_826:
	/* 0x826: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_82c:
	/* 0x82c: lea    eax,[r13+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_833:
	/* 0x833: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_838:
	/* 0x838: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_83c:
	/* 0x83c: mov    BYTE PTR [rsi+0x3b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_83f:
	/* 0x83f: cmp    r13,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 56ULL);
x86_l_843:
	/* 0x843: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_849:
	/* 0x849: lea    eax,[r13+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_850:
	/* 0x850: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_855:
	/* 0x855: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_859:
	/* 0x859: mov    BYTE PTR [rsi+0x3c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_85c:
	/* 0x85c: cmp    r13,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 57ULL);
x86_l_860:
	/* 0x860: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_866:
	/* 0x866: lea    eax,[r13+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_86d:
	/* 0x86d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_872:
	/* 0x872: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_876:
	/* 0x876: mov    BYTE PTR [rsi+0x3d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_879:
	/* 0x879: cmp    r13,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 58ULL);
x86_l_87d:
	/* 0x87d: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_883:
	/* 0x883: lea    eax,[r13+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_88a:
	/* 0x88a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_88f:
	/* 0x88f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_893:
	/* 0x893: mov    BYTE PTR [rsi+0x3e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_896:
	/* 0x896: cmp    r13,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 59ULL);
x86_l_89a:
	/* 0x89a: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_8a0:
	/* 0x8a0: lea    eax,[r13+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_8a7:
	/* 0x8a7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8ac:
	/* 0x8ac: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_8b0:
	/* 0x8b0: mov    BYTE PTR [rsi+0x3f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_8b3:
	/* 0x8b3: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_8b7:
	/* 0x8b7: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_8bd:
	/* 0x8bd: lea    eax,[r13+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_8c4:
	/* 0x8c4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8c9:
	/* 0x8c9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_8cd:
	/* 0x8cd: mov    BYTE PTR [rsi+0x40],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8d0:
	/* 0x8d0: cmp    r13,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 61ULL);
x86_l_8d4:
	/* 0x8d4: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_8da:
	/* 0x8da: lea    eax,[r13+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_8e1:
	/* 0x8e1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_8e6:
	/* 0x8e6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_8ea:
	/* 0x8ea: mov    BYTE PTR [rsi+0x41],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_8ed:
	/* 0x8ed: cmp    r13,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 62ULL);
x86_l_8f1:
	/* 0x8f1: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_8f7:
	/* 0x8f7: lea    eax,[r13+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_8fe:
	/* 0x8fe: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_903:
	/* 0x903: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_907:
	/* 0x907: mov    BYTE PTR [rsi+0x42],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_90a:
	/* 0x90a: cmp    r13,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 63ULL);
x86_l_90e:
	/* 0x90e: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_914:
	/* 0x914: lea    eax,[r13+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_91b:
	/* 0x91b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_920:
	/* 0x920: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_924:
	/* 0x924: mov    BYTE PTR [rsi+0x43],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_927:
	/* 0x927: cmp    r13,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 64ULL);
x86_l_92b:
	/* 0x92b: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_931:
	/* 0x931: lea    eax,[r13+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_938:
	/* 0x938: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_93d:
	/* 0x93d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_941:
	/* 0x941: mov    BYTE PTR [rsi+0x44],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_944:
	/* 0x944: cmp    r13,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 65ULL);
x86_l_948:
	/* 0x948: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_94e:
	/* 0x94e: lea    eax,[r13+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_955:
	/* 0x955: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_95a:
	/* 0x95a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_95e:
	/* 0x95e: mov    BYTE PTR [rsi+0x45],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_961:
	/* 0x961: cmp    r13,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 66ULL);
x86_l_965:
	/* 0x965: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_96b:
	/* 0x96b: lea    eax,[r13+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_972:
	/* 0x972: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_977:
	/* 0x977: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_97b:
	/* 0x97b: mov    BYTE PTR [rsi+0x46],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_97e:
	/* 0x97e: cmp    r13,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 67ULL);
x86_l_982:
	/* 0x982: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_988:
	/* 0x988: lea    eax,[r13+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_98f:
	/* 0x98f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_994:
	/* 0x994: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_998:
	/* 0x998: mov    BYTE PTR [rsi+0x47],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_99b:
	/* 0x99b: cmp    r13,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 68ULL);
x86_l_99f:
	/* 0x99f: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_9a5:
	/* 0x9a5: lea    eax,[r13+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_9ac:
	/* 0x9ac: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9b1:
	/* 0x9b1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_9b5:
	/* 0x9b5: mov    BYTE PTR [rsi+0x48],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9b8:
	/* 0x9b8: cmp    r13,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 69ULL);
x86_l_9bc:
	/* 0x9bc: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_9c2:
	/* 0x9c2: lea    eax,[r13+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_9c9:
	/* 0x9c9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9ce:
	/* 0x9ce: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_9d2:
	/* 0x9d2: mov    BYTE PTR [rsi+0x49],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_9d5:
	/* 0x9d5: cmp    r13,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 70ULL);
x86_l_9d9:
	/* 0x9d9: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_9df:
	/* 0x9df: lea    eax,[r13+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_9e6:
	/* 0x9e6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9eb:
	/* 0x9eb: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_9ef:
	/* 0x9ef: mov    BYTE PTR [rsi+0x4a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_9f2:
	/* 0x9f2: cmp    r13,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 71ULL);
x86_l_9f6:
	/* 0x9f6: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_9fc:
	/* 0x9fc: lea    eax,[r13+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_a03:
	/* 0xa03: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a08:
	/* 0xa08: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a0c:
	/* 0xa0c: mov    BYTE PTR [rsi+0x4b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_a0f:
	/* 0xa0f: cmp    r13,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 72ULL);
x86_l_a13:
	/* 0xa13: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_a19:
	/* 0xa19: lea    eax,[r13+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_a20:
	/* 0xa20: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a25:
	/* 0xa25: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a29:
	/* 0xa29: mov    BYTE PTR [rsi+0x4c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_a2c:
	/* 0xa2c: cmp    r13,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 73ULL);
x86_l_a30:
	/* 0xa30: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_a36:
	/* 0xa36: lea    eax,[r13+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_a3d:
	/* 0xa3d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a42:
	/* 0xa42: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a46:
	/* 0xa46: mov    BYTE PTR [rsi+0x4d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_a49:
	/* 0xa49: cmp    r13,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 74ULL);
x86_l_a4d:
	/* 0xa4d: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_a53:
	/* 0xa53: lea    eax,[r13+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_a5a:
	/* 0xa5a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a5f:
	/* 0xa5f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a63:
	/* 0xa63: mov    BYTE PTR [rsi+0x4e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_a66:
	/* 0xa66: cmp    r13,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 75ULL);
x86_l_a6a:
	/* 0xa6a: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_a70:
	/* 0xa70: lea    eax,[r13+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_a77:
	/* 0xa77: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a7c:
	/* 0xa7c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a80:
	/* 0xa80: mov    BYTE PTR [rsi+0x4f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_a83:
	/* 0xa83: cmp    r13,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 76ULL);
x86_l_a87:
	/* 0xa87: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_a8d:
	/* 0xa8d: lea    eax,[r13+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_a94:
	/* 0xa94: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a99:
	/* 0xa99: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_a9d:
	/* 0xa9d: mov    BYTE PTR [rsi+0x50],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_aa0:
	/* 0xaa0: cmp    r13,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 77ULL);
x86_l_aa4:
	/* 0xaa4: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_aaa:
	/* 0xaaa: lea    eax,[r13+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_ab1:
	/* 0xab1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ab6:
	/* 0xab6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_aba:
	/* 0xaba: mov    BYTE PTR [rsi+0x51],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_abd:
	/* 0xabd: cmp    r13,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 78ULL);
x86_l_ac1:
	/* 0xac1: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_ac7:
	/* 0xac7: lea    eax,[r13+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_ace:
	/* 0xace: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ad3:
	/* 0xad3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_ad7:
	/* 0xad7: mov    BYTE PTR [rsi+0x52],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_ada:
	/* 0xada: cmp    r13,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 79ULL);
x86_l_ade:
	/* 0xade: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_ae4:
	/* 0xae4: lea    eax,[r13+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_aeb:
	/* 0xaeb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_af0:
	/* 0xaf0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_af4:
	/* 0xaf4: mov    BYTE PTR [rsi+0x53],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_af7:
	/* 0xaf7: cmp    r13,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 80ULL);
x86_l_afb:
	/* 0xafb: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_b01:
	/* 0xb01: lea    eax,[r13+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_b08:
	/* 0xb08: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b0d:
	/* 0xb0d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b11:
	/* 0xb11: mov    BYTE PTR [rsi+0x54],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_b14:
	/* 0xb14: cmp    r13,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 81ULL);
x86_l_b18:
	/* 0xb18: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_b1e:
	/* 0xb1e: lea    eax,[r13+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_b25:
	/* 0xb25: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b2a:
	/* 0xb2a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b2e:
	/* 0xb2e: mov    BYTE PTR [rsi+0x55],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_b31:
	/* 0xb31: cmp    r13,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 82ULL);
x86_l_b35:
	/* 0xb35: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_b3b:
	/* 0xb3b: lea    eax,[r13+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_b42:
	/* 0xb42: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b47:
	/* 0xb47: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b4b:
	/* 0xb4b: mov    BYTE PTR [rsi+0x56],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_b4e:
	/* 0xb4e: cmp    r13,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 83ULL);
x86_l_b52:
	/* 0xb52: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_b58:
	/* 0xb58: lea    eax,[r13+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_b5f:
	/* 0xb5f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b64:
	/* 0xb64: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b68:
	/* 0xb68: mov    BYTE PTR [rsi+0x57],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_b6b:
	/* 0xb6b: cmp    r13,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 84ULL);
x86_l_b6f:
	/* 0xb6f: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_b75:
	/* 0xb75: lea    eax,[r13+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_b7c:
	/* 0xb7c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b81:
	/* 0xb81: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_b85:
	/* 0xb85: mov    BYTE PTR [rsi+0x58],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b88:
	/* 0xb88: cmp    r13,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 85ULL);
x86_l_b8c:
	/* 0xb8c: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_b92:
	/* 0xb92: lea    eax,[r13+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_b99:
	/* 0xb99: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b9e:
	/* 0xb9e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_ba2:
	/* 0xba2: mov    BYTE PTR [rsi+0x59],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_ba5:
	/* 0xba5: cmp    r13,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 86ULL);
x86_l_ba9:
	/* 0xba9: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_baf:
	/* 0xbaf: lea    eax,[r13+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_bb6:
	/* 0xbb6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bbb:
	/* 0xbbb: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_bbf:
	/* 0xbbf: mov    BYTE PTR [rsi+0x5a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_bc2:
	/* 0xbc2: cmp    r13,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 87ULL);
x86_l_bc6:
	/* 0xbc6: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_bcc:
	/* 0xbcc: lea    eax,[r13+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_bd3:
	/* 0xbd3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bd8:
	/* 0xbd8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_bdc:
	/* 0xbdc: mov    BYTE PTR [rsi+0x5b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_bdf:
	/* 0xbdf: cmp    r13,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 88ULL);
x86_l_be3:
	/* 0xbe3: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_be9:
	/* 0xbe9: lea    eax,[r13+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_bf0:
	/* 0xbf0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_bf5:
	/* 0xbf5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_bf9:
	/* 0xbf9: mov    BYTE PTR [rsi+0x5c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_bfc:
	/* 0xbfc: cmp    r13,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 89ULL);
x86_l_c00:
	/* 0xc00: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_c02:
	/* 0xc02: lea    eax,[r13+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_c09:
	/* 0xc09: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c0e:
	/* 0xc0e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c12:
	/* 0xc12: mov    BYTE PTR [rsi+0x5d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_c15:
	/* 0xc15: cmp    r13,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 90ULL);
x86_l_c19:
	/* 0xc19: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_c1b:
	/* 0xc1b: lea    eax,[r13+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_c22:
	/* 0xc22: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c27:
	/* 0xc27: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c2b:
	/* 0xc2b: mov    BYTE PTR [rsi+0x5e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_c2e:
	/* 0xc2e: cmp    r13,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 91ULL);
x86_l_c32:
	/* 0xc32: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_c34:
	/* 0xc34: lea    eax,[r13+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_c3b:
	/* 0xc3b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c40:
	/* 0xc40: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c44:
	/* 0xc44: mov    BYTE PTR [rsi+0x5f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_c47:
	/* 0xc47: cmp    r13,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 92ULL);
x86_l_c4b:
	/* 0xc4b: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_c4d:
	/* 0xc4d: lea    eax,[r13+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_c54:
	/* 0xc54: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c59:
	/* 0xc59: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_c5d:
	/* 0xc5d: mov    BYTE PTR [rsi+0x60],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c60:
	/* 0xc60: cmp    r13,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 93ULL);
x86_l_c64:
	/* 0xc64: je     c7c <generic_retuprobe_filter_arg_2+0xc7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7c;
	}
x86_l_c66:
	/* 0xc66: add    r13d,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_c6d:
	/* 0xc6d: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c74:
	/* 0xc74: movzx  eax,BYTE PTR [rcx+r13*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R13, 0, X86_WIDTH_8), 0ULL);
x86_l_c79:
	/* 0xc79: mov    BYTE PTR [rsi+0x61],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_c7c:
	/* 0xc7c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c81:
	/* 0xc81: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_c84:
	/* 0xc84: jmp    319f <generic_retuprobe_filter_arg_2+0x319f> */
	return 12703ULL;
x86_l_c89:
	/* 0xc89: lea    eax,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_c8c:
	/* 0xc8c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c8f:
	/* 0xc8f: jb     d28 <generic_retuprobe_filter_arg_2+0xd28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d28;
	}
x86_l_c95:
	/* 0xc95: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c98:
	/* 0xc98: je     ca7 <generic_retuprobe_filter_arg_2+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ca7;
	}
x86_l_c9a:
	/* 0xc9a: jmp    31d7 <generic_retuprobe_filter_arg_2+0x31d7> */
	return 12759ULL;
x86_l_c9f:
	/* 0xc9f: lea    eax,[rcx-0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551576ULL);
x86_l_ca2:
	/* 0xca2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ca5:
	/* 0xca5: jae    d1f <generic_retuprobe_filter_arg_2+0xd1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_d1f;
	}
x86_l_ca7:
	/* 0xca7: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_cb0:
	/* 0xcb0: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_cb9:
	/* 0xcb9: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_cc2:
	/* 0xcc2: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_ccb:
	/* 0xccb: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_cd4:
	/* 0xcd4: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cd7:
	/* 0xcd7: cmp    ecx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 39ULL);
x86_l_cda:
	/* 0xcda: jg     cf6 <generic_retuprobe_filter_arg_2+0xcf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_cf6;
	}
x86_l_cdc:
	/* 0xcdc: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_cdf:
	/* 0xcdf: je     1b15 <generic_retuprobe_filter_arg_2+0x1b15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6933ULL;
	}
x86_l_ce5:
	/* 0xce5: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_ce8:
	/* 0xce8: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_ceb:
	/* 0xceb: je     1b17 <generic_retuprobe_filter_arg_2+0x1b17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6935ULL;
	}
x86_l_cf1:
	/* 0xcf1: jmp    31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	return 12754ULL;
x86_l_cf6:
	/* 0xcf6: cmp    ecx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_cf9:
	/* 0xcf9: je     1aeb <generic_retuprobe_filter_arg_2+0x1aeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6891ULL;
	}
x86_l_cff:
	/* 0xcff: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_d02:
	/* 0xd02: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_d05:
	/* 0xd05: je     1b17 <generic_retuprobe_filter_arg_2+0x1b17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6935ULL;
	}
x86_l_d0b:
	/* 0xd0b: jmp    31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	return 12754ULL;
x86_l_d10:
	/* 0xd10: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_d13:
	/* 0xd13: jne    31d7 <generic_retuprobe_filter_arg_2+0x31d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12759ULL;
	}
x86_l_d19:
	/* 0xd19: add    r8,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_d1d:
	/* 0xd1d: jmp    d28 <generic_retuprobe_filter_arg_2+0xd28> */
	goto x86_l_d28;
x86_l_d1f:
	/* 0xd1f: cmp    ecx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 42ULL);
x86_l_d22:
	/* 0xd22: jne    31d7 <generic_retuprobe_filter_arg_2+0x31d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12759ULL;
	}
x86_l_d28:
	/* 0xd28: mov    r13d,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d2b:
	/* 0xd2b: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d2e:
	/* 0xd2e: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_d31:
	/* 0xd31: jne    d41 <generic_retuprobe_filter_arg_2+0xd41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d41;
	}
x86_l_d33:
	/* 0xd33: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_d35:
	/* 0xd35: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_d38:
	/* 0xd38: cmp    ecx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 36ULL);
x86_l_d3b:
	/* 0xd3b: jne    31e1 <generic_retuprobe_filter_arg_2+0x31e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12769ULL;
	}
x86_l_d41:
	/* 0xd41: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_d44:
	/* 0xd44: ja     1b8e <generic_retuprobe_filter_arg_2+0x1b8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7054ULL;
	}
x86_l_d4a:
	/* 0xd4a: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_d4c:
	/* 0xd4c: mov    edx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 67109120ULL);
x86_l_d51:
	/* 0xd51: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_d55:
	/* 0xd55: jb     26ee <generic_retuprobe_filter_arg_2+0x26ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9966ULL;
	}
x86_l_d5b:
	/* 0xd5b: mov    edx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 134218240ULL);
x86_l_d60:
	/* 0xd60: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_d64:
	/* 0xd64: jb     1bd7 <generic_retuprobe_filter_arg_2+0x1bd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7127ULL;
	}
x86_l_d6a:
	/* 0xd6a: movabs rdx,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 206158430208ULL);
x86_l_d74:
	/* 0xd74: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_d78:
	/* 0xd78: jae    1b8e <generic_retuprobe_filter_arg_2+0x1b8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7054ULL;
	}
x86_l_d7e:
	/* 0xd7e: mov    WORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_d85:
	/* 0xd85: cmp    r13d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 144ULL);
x86_l_d8c:
	/* 0xd8c: ja     1baf <generic_retuprobe_filter_arg_2+0x1baf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7087ULL;
	}
x86_l_d92:
	/* 0xd92: lea    rcx,[r8+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_d96:
	/* 0xd96: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_d9a:
	/* 0xd9a: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d9f:
	/* 0xd9f: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_da4:
	/* 0xda4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_da9:
	/* 0xda9: mov    ecx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dac:
	/* 0xdac: lea    rdx,[r8+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_db0:
	/* 0xdb0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_db4:
	/* 0xdb4: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_db7:
	/* 0xdb7: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_dbc:
	/* 0xdbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dbe:
	/* 0xdbe: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_dc1:
	/* 0xdc1: mov    ecx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dc5:
	/* 0xdc5: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_dc7:
	/* 0xdc7: je     1baf <generic_retuprobe_filter_arg_2+0x1baf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7087ULL;
	}
x86_l_dcd:
	/* 0xdcd: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_dd2:
	/* 0xdd2: and    eax,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_dd7:
	/* 0xdd7: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_ddd:
	/* 0xddd: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_ddf:
	/* 0xddf: je     3115 <generic_retuprobe_filter_arg_2+0x3115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12565ULL;
	}
x86_l_de5:
	/* 0xde5: mov    ecx,DWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_de8:
	/* 0xde8: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_deb:
	/* 0xdeb: jbe    2fb8 <generic_retuprobe_filter_arg_2+0x2fb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 12216ULL;
	}
x86_l_df1:
	/* 0xdf1: mov    edx,DWORD PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_df5:
	/* 0xdf5: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_df7:
	/* 0xdf7: je     2fb8 <generic_retuprobe_filter_arg_2+0x2fb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12216ULL;
	}
x86_l_dfd:
	/* 0xdfd: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_dff:
	/* 0xdff: je     2fbb <generic_retuprobe_filter_arg_2+0x2fbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12219ULL;
	}
x86_l_e05:
	/* 0xe05: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_e08:
	/* 0xe08: jb     2fb8 <generic_retuprobe_filter_arg_2+0x2fb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12216ULL;
	}
x86_l_e0e:
	/* 0xe0e: mov    edx,DWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
	return 3602ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3602ULL: goto x86_l_e12;
	case 3604ULL: goto x86_l_e14;
	case 3610ULL: goto x86_l_e1a;
	case 3612ULL: goto x86_l_e1c;
	case 3615ULL: goto x86_l_e1f;
	case 3621ULL: goto x86_l_e25;
	case 3624ULL: goto x86_l_e28;
	case 3630ULL: goto x86_l_e2e;
	case 3634ULL: goto x86_l_e32;
	case 3636ULL: goto x86_l_e34;
	case 3642ULL: goto x86_l_e3a;
	case 3645ULL: goto x86_l_e3d;
	case 3647ULL: goto x86_l_e3f;
	case 3651ULL: goto x86_l_e43;
	case 3656ULL: goto x86_l_e48;
	case 3659ULL: goto x86_l_e4b;
	case 3662ULL: goto x86_l_e4e;
	case 3665ULL: goto x86_l_e51;
	case 3671ULL: goto x86_l_e57;
	case 3675ULL: goto x86_l_e5b;
	case 3679ULL: goto x86_l_e5f;
	case 3684ULL: goto x86_l_e64;
	case 3687ULL: goto x86_l_e67;
	case 3692ULL: goto x86_l_e6c;
	case 3698ULL: goto x86_l_e72;
	case 3703ULL: goto x86_l_e77;
	case 3706ULL: goto x86_l_e7a;
	case 3712ULL: goto x86_l_e80;
	case 3717ULL: goto x86_l_e85;
	case 3720ULL: goto x86_l_e88;
	case 3726ULL: goto x86_l_e8e;
	case 3729ULL: goto x86_l_e91;
	case 3733ULL: goto x86_l_e95;
	case 3736ULL: goto x86_l_e98;
	case 3740ULL: goto x86_l_e9c;
	case 3748ULL: goto x86_l_ea4;
	case 3755ULL: goto x86_l_eab;
	case 3760ULL: goto x86_l_eb0;
	case 3765ULL: goto x86_l_eb5;
	case 3767ULL: goto x86_l_eb7;
	case 3770ULL: goto x86_l_eba;
	case 3776ULL: goto x86_l_ec0;
	case 3782ULL: goto x86_l_ec6;
	case 3787ULL: goto x86_l_ecb;
	case 3790ULL: goto x86_l_ece;
	case 3796ULL: goto x86_l_ed4;
	case 3803ULL: goto x86_l_edb;
	case 3808ULL: goto x86_l_ee0;
	case 3813ULL: goto x86_l_ee5;
	case 3815ULL: goto x86_l_ee7;
	case 3818ULL: goto x86_l_eea;
	case 3824ULL: goto x86_l_ef0;
	case 3827ULL: goto x86_l_ef3;
	case 3832ULL: goto x86_l_ef8;
	case 3835ULL: goto x86_l_efb;
	case 3840ULL: goto x86_l_f00;
	case 3843ULL: goto x86_l_f03;
	case 3846ULL: goto x86_l_f06;
	case 3848ULL: goto x86_l_f08;
	case 3851ULL: goto x86_l_f0b;
	case 3856ULL: goto x86_l_f10;
	case 3862ULL: goto x86_l_f16;
	case 3865ULL: goto x86_l_f19;
	case 3869ULL: goto x86_l_f1d;
	case 3875ULL: goto x86_l_f23;
	case 3881ULL: goto x86_l_f29;
	case 3886ULL: goto x86_l_f2e;
	case 3892ULL: goto x86_l_f34;
	case 3895ULL: goto x86_l_f37;
	case 3899ULL: goto x86_l_f3b;
	case 3905ULL: goto x86_l_f41;
	case 3911ULL: goto x86_l_f47;
	case 3916ULL: goto x86_l_f4c;
	case 3922ULL: goto x86_l_f52;
	case 3925ULL: goto x86_l_f55;
	case 3929ULL: goto x86_l_f59;
	case 3935ULL: goto x86_l_f5f;
	case 3941ULL: goto x86_l_f65;
	case 3946ULL: goto x86_l_f6a;
	case 3952ULL: goto x86_l_f70;
	case 3955ULL: goto x86_l_f73;
	case 3959ULL: goto x86_l_f77;
	case 3965ULL: goto x86_l_f7d;
	case 3971ULL: goto x86_l_f83;
	case 3976ULL: goto x86_l_f88;
	case 3982ULL: goto x86_l_f8e;
	case 3985ULL: goto x86_l_f91;
	case 3989ULL: goto x86_l_f95;
	case 3995ULL: goto x86_l_f9b;
	case 4001ULL: goto x86_l_fa1;
	case 4006ULL: goto x86_l_fa6;
	case 4012ULL: goto x86_l_fac;
	case 4015ULL: goto x86_l_faf;
	case 4019ULL: goto x86_l_fb3;
	case 4025ULL: goto x86_l_fb9;
	case 4031ULL: goto x86_l_fbf;
	case 4036ULL: goto x86_l_fc4;
	case 4042ULL: goto x86_l_fca;
	case 4045ULL: goto x86_l_fcd;
	case 4049ULL: goto x86_l_fd1;
	case 4055ULL: goto x86_l_fd7;
	case 4061ULL: goto x86_l_fdd;
	case 4066ULL: goto x86_l_fe2;
	case 4072ULL: goto x86_l_fe8;
	case 4075ULL: goto x86_l_feb;
	case 4079ULL: goto x86_l_fef;
	case 4085ULL: goto x86_l_ff5;
	case 4091ULL: goto x86_l_ffb;
	case 4096ULL: goto x86_l_1000;
	case 4102ULL: goto x86_l_1006;
	case 4105ULL: goto x86_l_1009;
	case 4109ULL: goto x86_l_100d;
	case 4115ULL: goto x86_l_1013;
	case 4121ULL: goto x86_l_1019;
	case 4126ULL: goto x86_l_101e;
	case 4132ULL: goto x86_l_1024;
	case 4135ULL: goto x86_l_1027;
	case 4139ULL: goto x86_l_102b;
	case 4145ULL: goto x86_l_1031;
	case 4151ULL: goto x86_l_1037;
	case 4156ULL: goto x86_l_103c;
	case 4162ULL: goto x86_l_1042;
	case 4165ULL: goto x86_l_1045;
	case 4169ULL: goto x86_l_1049;
	case 4175ULL: goto x86_l_104f;
	case 4181ULL: goto x86_l_1055;
	case 4186ULL: goto x86_l_105a;
	case 4192ULL: goto x86_l_1060;
	case 4195ULL: goto x86_l_1063;
	case 4199ULL: goto x86_l_1067;
	case 4205ULL: goto x86_l_106d;
	case 4211ULL: goto x86_l_1073;
	case 4216ULL: goto x86_l_1078;
	case 4222ULL: goto x86_l_107e;
	case 4225ULL: goto x86_l_1081;
	case 4229ULL: goto x86_l_1085;
	case 4235ULL: goto x86_l_108b;
	case 4241ULL: goto x86_l_1091;
	case 4246ULL: goto x86_l_1096;
	case 4252ULL: goto x86_l_109c;
	case 4255ULL: goto x86_l_109f;
	case 4259ULL: goto x86_l_10a3;
	case 4265ULL: goto x86_l_10a9;
	case 4271ULL: goto x86_l_10af;
	case 4276ULL: goto x86_l_10b4;
	case 4282ULL: goto x86_l_10ba;
	case 4285ULL: goto x86_l_10bd;
	case 4289ULL: goto x86_l_10c1;
	case 4295ULL: goto x86_l_10c7;
	case 4301ULL: goto x86_l_10cd;
	case 4306ULL: goto x86_l_10d2;
	case 4312ULL: goto x86_l_10d8;
	case 4315ULL: goto x86_l_10db;
	case 4319ULL: goto x86_l_10df;
	case 4325ULL: goto x86_l_10e5;
	case 4331ULL: goto x86_l_10eb;
	case 4336ULL: goto x86_l_10f0;
	case 4342ULL: goto x86_l_10f6;
	case 4345ULL: goto x86_l_10f9;
	case 4349ULL: goto x86_l_10fd;
	case 4355ULL: goto x86_l_1103;
	case 4361ULL: goto x86_l_1109;
	case 4366ULL: goto x86_l_110e;
	case 4372ULL: goto x86_l_1114;
	case 4375ULL: goto x86_l_1117;
	case 4379ULL: goto x86_l_111b;
	case 4385ULL: goto x86_l_1121;
	case 4391ULL: goto x86_l_1127;
	case 4396ULL: goto x86_l_112c;
	case 4402ULL: goto x86_l_1132;
	case 4405ULL: goto x86_l_1135;
	case 4409ULL: goto x86_l_1139;
	case 4415ULL: goto x86_l_113f;
	case 4421ULL: goto x86_l_1145;
	case 4426ULL: goto x86_l_114a;
	case 4432ULL: goto x86_l_1150;
	case 4435ULL: goto x86_l_1153;
	case 4439ULL: goto x86_l_1157;
	case 4445ULL: goto x86_l_115d;
	case 4451ULL: goto x86_l_1163;
	case 4456ULL: goto x86_l_1168;
	case 4462ULL: goto x86_l_116e;
	case 4465ULL: goto x86_l_1171;
	case 4469ULL: goto x86_l_1175;
	case 4475ULL: goto x86_l_117b;
	case 4481ULL: goto x86_l_1181;
	case 4486ULL: goto x86_l_1186;
	case 4492ULL: goto x86_l_118c;
	case 4495ULL: goto x86_l_118f;
	case 4499ULL: goto x86_l_1193;
	case 4505ULL: goto x86_l_1199;
	case 4511ULL: goto x86_l_119f;
	case 4516ULL: goto x86_l_11a4;
	case 4522ULL: goto x86_l_11aa;
	case 4525ULL: goto x86_l_11ad;
	case 4529ULL: goto x86_l_11b1;
	case 4535ULL: goto x86_l_11b7;
	case 4541ULL: goto x86_l_11bd;
	case 4546ULL: goto x86_l_11c2;
	case 4552ULL: goto x86_l_11c8;
	case 4555ULL: goto x86_l_11cb;
	case 4559ULL: goto x86_l_11cf;
	case 4565ULL: goto x86_l_11d5;
	case 4571ULL: goto x86_l_11db;
	case 4576ULL: goto x86_l_11e0;
	case 4582ULL: goto x86_l_11e6;
	case 4585ULL: goto x86_l_11e9;
	case 4589ULL: goto x86_l_11ed;
	case 4595ULL: goto x86_l_11f3;
	case 4601ULL: goto x86_l_11f9;
	case 4606ULL: goto x86_l_11fe;
	case 4612ULL: goto x86_l_1204;
	case 4615ULL: goto x86_l_1207;
	case 4619ULL: goto x86_l_120b;
	case 4625ULL: goto x86_l_1211;
	case 4631ULL: goto x86_l_1217;
	case 4636ULL: goto x86_l_121c;
	case 4642ULL: goto x86_l_1222;
	case 4645ULL: goto x86_l_1225;
	case 4649ULL: goto x86_l_1229;
	case 4655ULL: goto x86_l_122f;
	case 4661ULL: goto x86_l_1235;
	case 4666ULL: goto x86_l_123a;
	case 4672ULL: goto x86_l_1240;
	case 4675ULL: goto x86_l_1243;
	case 4679ULL: goto x86_l_1247;
	case 4685ULL: goto x86_l_124d;
	case 4691ULL: goto x86_l_1253;
	case 4696ULL: goto x86_l_1258;
	case 4702ULL: goto x86_l_125e;
	case 4705ULL: goto x86_l_1261;
	case 4709ULL: goto x86_l_1265;
	case 4715ULL: goto x86_l_126b;
	case 4721ULL: goto x86_l_1271;
	case 4726ULL: goto x86_l_1276;
	case 4732ULL: goto x86_l_127c;
	case 4735ULL: goto x86_l_127f;
	case 4739ULL: goto x86_l_1283;
	case 4745ULL: goto x86_l_1289;
	case 4751ULL: goto x86_l_128f;
	case 4756ULL: goto x86_l_1294;
	case 4762ULL: goto x86_l_129a;
	case 4765ULL: goto x86_l_129d;
	case 4769ULL: goto x86_l_12a1;
	case 4775ULL: goto x86_l_12a7;
	case 4781ULL: goto x86_l_12ad;
	case 4786ULL: goto x86_l_12b2;
	case 4792ULL: goto x86_l_12b8;
	case 4795ULL: goto x86_l_12bb;
	case 4799ULL: goto x86_l_12bf;
	case 4805ULL: goto x86_l_12c5;
	case 4811ULL: goto x86_l_12cb;
	case 4816ULL: goto x86_l_12d0;
	case 4822ULL: goto x86_l_12d6;
	case 4825ULL: goto x86_l_12d9;
	case 4829ULL: goto x86_l_12dd;
	case 4835ULL: goto x86_l_12e3;
	case 4841ULL: goto x86_l_12e9;
	case 4846ULL: goto x86_l_12ee;
	case 4852ULL: goto x86_l_12f4;
	case 4855ULL: goto x86_l_12f7;
	case 4859ULL: goto x86_l_12fb;
	case 4865ULL: goto x86_l_1301;
	case 4871ULL: goto x86_l_1307;
	case 4876ULL: goto x86_l_130c;
	case 4882ULL: goto x86_l_1312;
	case 4885ULL: goto x86_l_1315;
	case 4889ULL: goto x86_l_1319;
	case 4895ULL: goto x86_l_131f;
	case 4901ULL: goto x86_l_1325;
	case 4906ULL: goto x86_l_132a;
	case 4912ULL: goto x86_l_1330;
	case 4915ULL: goto x86_l_1333;
	case 4919ULL: goto x86_l_1337;
	case 4925ULL: goto x86_l_133d;
	case 4931ULL: goto x86_l_1343;
	case 4936ULL: goto x86_l_1348;
	case 4942ULL: goto x86_l_134e;
	case 4945ULL: goto x86_l_1351;
	case 4949ULL: goto x86_l_1355;
	case 4955ULL: goto x86_l_135b;
	case 4961ULL: goto x86_l_1361;
	case 4966ULL: goto x86_l_1366;
	case 4972ULL: goto x86_l_136c;
	case 4975ULL: goto x86_l_136f;
	case 4979ULL: goto x86_l_1373;
	case 4985ULL: goto x86_l_1379;
	case 4991ULL: goto x86_l_137f;
	case 4996ULL: goto x86_l_1384;
	case 5002ULL: goto x86_l_138a;
	case 5005ULL: goto x86_l_138d;
	case 5009ULL: goto x86_l_1391;
	case 5015ULL: goto x86_l_1397;
	case 5021ULL: goto x86_l_139d;
	case 5026ULL: goto x86_l_13a2;
	case 5032ULL: goto x86_l_13a8;
	case 5035ULL: goto x86_l_13ab;
	case 5039ULL: goto x86_l_13af;
	case 5045ULL: goto x86_l_13b5;
	case 5051ULL: goto x86_l_13bb;
	case 5056ULL: goto x86_l_13c0;
	case 5062ULL: goto x86_l_13c6;
	case 5065ULL: goto x86_l_13c9;
	case 5069ULL: goto x86_l_13cd;
	case 5075ULL: goto x86_l_13d3;
	case 5081ULL: goto x86_l_13d9;
	case 5086ULL: goto x86_l_13de;
	case 5092ULL: goto x86_l_13e4;
	case 5095ULL: goto x86_l_13e7;
	case 5099ULL: goto x86_l_13eb;
	case 5105ULL: goto x86_l_13f1;
	case 5111ULL: goto x86_l_13f7;
	case 5116ULL: goto x86_l_13fc;
	case 5122ULL: goto x86_l_1402;
	case 5125ULL: goto x86_l_1405;
	case 5129ULL: goto x86_l_1409;
	case 5135ULL: goto x86_l_140f;
	case 5141ULL: goto x86_l_1415;
	case 5146ULL: goto x86_l_141a;
	case 5152ULL: goto x86_l_1420;
	case 5155ULL: goto x86_l_1423;
	case 5159ULL: goto x86_l_1427;
	case 5165ULL: goto x86_l_142d;
	case 5171ULL: goto x86_l_1433;
	case 5176ULL: goto x86_l_1438;
	case 5182ULL: goto x86_l_143e;
	case 5185ULL: goto x86_l_1441;
	case 5189ULL: goto x86_l_1445;
	case 5195ULL: goto x86_l_144b;
	case 5201ULL: goto x86_l_1451;
	case 5206ULL: goto x86_l_1456;
	case 5212ULL: goto x86_l_145c;
	case 5215ULL: goto x86_l_145f;
	case 5219ULL: goto x86_l_1463;
	case 5225ULL: goto x86_l_1469;
	case 5231ULL: goto x86_l_146f;
	case 5236ULL: goto x86_l_1474;
	case 5242ULL: goto x86_l_147a;
	case 5245ULL: goto x86_l_147d;
	case 5249ULL: goto x86_l_1481;
	case 5255ULL: goto x86_l_1487;
	case 5261ULL: goto x86_l_148d;
	case 5266ULL: goto x86_l_1492;
	case 5272ULL: goto x86_l_1498;
	case 5275ULL: goto x86_l_149b;
	case 5279ULL: goto x86_l_149f;
	case 5285ULL: goto x86_l_14a5;
	case 5291ULL: goto x86_l_14ab;
	case 5296ULL: goto x86_l_14b0;
	case 5302ULL: goto x86_l_14b6;
	case 5305ULL: goto x86_l_14b9;
	case 5309ULL: goto x86_l_14bd;
	case 5315ULL: goto x86_l_14c3;
	case 5321ULL: goto x86_l_14c9;
	case 5326ULL: goto x86_l_14ce;
	case 5332ULL: goto x86_l_14d4;
	case 5335ULL: goto x86_l_14d7;
	case 5339ULL: goto x86_l_14db;
	case 5345ULL: goto x86_l_14e1;
	case 5351ULL: goto x86_l_14e7;
	case 5356ULL: goto x86_l_14ec;
	case 5362ULL: goto x86_l_14f2;
	case 5365ULL: goto x86_l_14f5;
	case 5369ULL: goto x86_l_14f9;
	case 5375ULL: goto x86_l_14ff;
	case 5381ULL: goto x86_l_1505;
	case 5386ULL: goto x86_l_150a;
	case 5392ULL: goto x86_l_1510;
	case 5395ULL: goto x86_l_1513;
	case 5399ULL: goto x86_l_1517;
	case 5405ULL: goto x86_l_151d;
	case 5411ULL: goto x86_l_1523;
	case 5416ULL: goto x86_l_1528;
	case 5422ULL: goto x86_l_152e;
	case 5425ULL: goto x86_l_1531;
	case 5429ULL: goto x86_l_1535;
	case 5435ULL: goto x86_l_153b;
	case 5441ULL: goto x86_l_1541;
	case 5446ULL: goto x86_l_1546;
	case 5452ULL: goto x86_l_154c;
	case 5455ULL: goto x86_l_154f;
	case 5459ULL: goto x86_l_1553;
	case 5465ULL: goto x86_l_1559;
	case 5471ULL: goto x86_l_155f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e12:
	/* 0xe12: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_e14:
	/* 0xe14: je     2fb8 <generic_retuprobe_filter_arg_2+0x2fb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12216ULL;
	}
x86_l_e1a:
	/* 0xe1a: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_e1c:
	/* 0xe1c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_e1f:
	/* 0xe1f: je     3115 <generic_retuprobe_filter_arg_2+0x3115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12565ULL;
	}
x86_l_e25:
	/* 0xe25: cmp    ecx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 21ULL);
x86_l_e28:
	/* 0xe28: jb     2fb8 <generic_retuprobe_filter_arg_2+0x2fb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12216ULL;
	}
x86_l_e2e:
	/* 0xe2e: mov    ecx,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_e32:
	/* 0xe32: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_e34:
	/* 0xe34: je     2fb8 <generic_retuprobe_filter_arg_2+0x2fb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12216ULL;
	}
x86_l_e3a:
	/* 0xe3a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e3d:
	/* 0xe3d: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_e3f:
	/* 0xe3f: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_e43:
	/* 0xe43: jmp    2fbb <generic_retuprobe_filter_arg_2+0x2fbb> */
	return 12219ULL;
x86_l_e48:
	/* 0xe48: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e4b:
	/* 0xe4b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e4e:
	/* 0xe4e: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_e51:
	/* 0xe51: ja     31b7 <generic_retuprobe_filter_arg_2+0x31b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12727ULL;
	}
x86_l_e57:
	/* 0xe57: mov    edx,DWORD PTR [r8+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e5b:
	/* 0xe5b: add    r8,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_e5f:
	/* 0xe5f: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_e64:
	/* 0xe64: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_e67:
	/* 0xe67: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e6c:
	/* 0xe6c: jb     29a7 <generic_retuprobe_filter_arg_2+0x29a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10663ULL;
	}
x86_l_e72:
	/* 0xe72: mov    ecx,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 67109120ULL);
x86_l_e77:
	/* 0xe77: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_e7a:
	/* 0xe7a: jb     2903 <generic_retuprobe_filter_arg_2+0x2903> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10499ULL;
	}
x86_l_e80:
	/* 0xe80: mov    ecx,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134218240ULL);
x86_l_e85:
	/* 0xe85: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_e88:
	/* 0xe88: jae    31b7 <generic_retuprobe_filter_arg_2+0x31b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12727ULL;
	}
x86_l_e8e:
	/* 0xe8e: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_e91:
	/* 0xe91: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e95:
	/* 0xe95: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e98:
	/* 0xe98: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e9c:
	/* 0xe9c: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_ea4:
	/* 0xea4: mov    rdi,QWORD PTR [rip+0x17e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_eab:
	/* 0xeab: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_eb0:
	/* 0xeb0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_eb5:
	/* 0xeb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eb7:
	/* 0xeb7: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_eba:
	/* 0xeba: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_ec0:
	/* 0xec0: je     31b0 <generic_retuprobe_filter_arg_2+0x31b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12720ULL;
	}
x86_l_ec6:
	/* 0xec6: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ecb:
	/* 0xecb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ece:
	/* 0xece: je     31b0 <generic_retuprobe_filter_arg_2+0x31b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12720ULL;
	}
x86_l_ed4:
	/* 0xed4: mov    rdi,QWORD PTR [rip+0x17e4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_edb:
	/* 0xedb: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ee0:
	/* 0xee0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ee5:
	/* 0xee5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee7:
	/* 0xee7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_eea:
	/* 0xeea: je     31ad <generic_retuprobe_filter_arg_2+0x31ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12717ULL;
	}
x86_l_ef0:
	/* 0xef0: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_ef3:
	/* 0xef3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ef8:
	/* 0xef8: cmp    edx,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 94ULL);
x86_l_efb:
	/* 0xefb: mov    eax,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 94ULL);
x86_l_f00:
	/* 0xf00: cmovb  eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_B);
x86_l_f03:
	/* 0xf03: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_f06:
	/* 0xf06: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f08:
	/* 0xf08: lea    eax,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_f0b:
	/* 0xf0b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f10:
	/* 0xf10: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f16:
	/* 0xf16: mov    BYTE PTR [rsi+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f19:
	/* 0xf19: cmp    rdx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 1ULL);
x86_l_f1d:
	/* 0xf1d: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_f23:
	/* 0xf23: lea    eax,[rdx+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
x86_l_f29:
	/* 0xf29: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f2e:
	/* 0xf2e: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f34:
	/* 0xf34: mov    BYTE PTR [rsi+0x5],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_f37:
	/* 0xf37: cmp    rdx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 2ULL);
x86_l_f3b:
	/* 0xf3b: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_f41:
	/* 0xf41: lea    eax,[rdx+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_f47:
	/* 0xf47: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f4c:
	/* 0xf4c: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f52:
	/* 0xf52: mov    BYTE PTR [rsi+0x6],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_f55:
	/* 0xf55: cmp    rdx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 3ULL);
x86_l_f59:
	/* 0xf59: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_f5f:
	/* 0xf5f: lea    eax,[rdx+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_f65:
	/* 0xf65: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f6a:
	/* 0xf6a: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f70:
	/* 0xf70: mov    BYTE PTR [rsi+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_f73:
	/* 0xf73: cmp    rdx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4ULL);
x86_l_f77:
	/* 0xf77: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_f7d:
	/* 0xf7d: lea    eax,[rdx+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_f83:
	/* 0xf83: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f88:
	/* 0xf88: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_f8e:
	/* 0xf8e: mov    BYTE PTR [rsi+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f91:
	/* 0xf91: cmp    rdx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 5ULL);
x86_l_f95:
	/* 0xf95: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_f9b:
	/* 0xf9b: lea    eax,[rdx+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_fa1:
	/* 0xfa1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fa6:
	/* 0xfa6: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_fac:
	/* 0xfac: mov    BYTE PTR [rsi+0x9],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_faf:
	/* 0xfaf: cmp    rdx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 6ULL);
x86_l_fb3:
	/* 0xfb3: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_fb9:
	/* 0xfb9: lea    eax,[rdx+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_fbf:
	/* 0xfbf: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fc4:
	/* 0xfc4: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_fca:
	/* 0xfca: mov    BYTE PTR [rsi+0xa],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_fcd:
	/* 0xfcd: cmp    rdx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 7ULL);
x86_l_fd1:
	/* 0xfd1: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_fd7:
	/* 0xfd7: lea    eax,[rdx+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_fdd:
	/* 0xfdd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fe2:
	/* 0xfe2: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_fe8:
	/* 0xfe8: mov    BYTE PTR [rsi+0xb],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_feb:
	/* 0xfeb: cmp    rdx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 8ULL);
x86_l_fef:
	/* 0xfef: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_ff5:
	/* 0xff5: lea    eax,[rdx+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_ffb:
	/* 0xffb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1000:
	/* 0x1000: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1006:
	/* 0x1006: mov    BYTE PTR [rsi+0xc],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1009:
	/* 0x1009: cmp    rdx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 9ULL);
x86_l_100d:
	/* 0x100d: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_1013:
	/* 0x1013: lea    eax,[rdx+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_1019:
	/* 0x1019: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_101e:
	/* 0x101e: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1024:
	/* 0x1024: mov    BYTE PTR [rsi+0xd],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_1027:
	/* 0x1027: cmp    rdx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 10ULL);
x86_l_102b:
	/* 0x102b: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_1031:
	/* 0x1031: lea    eax,[rdx+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_1037:
	/* 0x1037: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_103c:
	/* 0x103c: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1042:
	/* 0x1042: mov    BYTE PTR [rsi+0xe],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_1045:
	/* 0x1045: cmp    rdx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 11ULL);
x86_l_1049:
	/* 0x1049: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_104f:
	/* 0x104f: lea    eax,[rdx+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_1055:
	/* 0x1055: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_105a:
	/* 0x105a: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1060:
	/* 0x1060: mov    BYTE PTR [rsi+0xf],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_1063:
	/* 0x1063: cmp    rdx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 12ULL);
x86_l_1067:
	/* 0x1067: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_106d:
	/* 0x106d: lea    eax,[rdx+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_1073:
	/* 0x1073: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1078:
	/* 0x1078: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_107e:
	/* 0x107e: mov    BYTE PTR [rsi+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1081:
	/* 0x1081: cmp    rdx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 13ULL);
x86_l_1085:
	/* 0x1085: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_108b:
	/* 0x108b: lea    eax,[rdx+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_1091:
	/* 0x1091: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1096:
	/* 0x1096: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_109c:
	/* 0x109c: mov    BYTE PTR [rsi+0x11],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_109f:
	/* 0x109f: cmp    rdx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 14ULL);
x86_l_10a3:
	/* 0x10a3: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_10a9:
	/* 0x10a9: lea    eax,[rdx+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_10af:
	/* 0x10af: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10b4:
	/* 0x10b4: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_10ba:
	/* 0x10ba: mov    BYTE PTR [rsi+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_10bd:
	/* 0x10bd: cmp    rdx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 15ULL);
x86_l_10c1:
	/* 0x10c1: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_10c7:
	/* 0x10c7: lea    eax,[rdx+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_10cd:
	/* 0x10cd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10d2:
	/* 0x10d2: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_10d8:
	/* 0x10d8: mov    BYTE PTR [rsi+0x13],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_10db:
	/* 0x10db: cmp    rdx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 16ULL);
x86_l_10df:
	/* 0x10df: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_10e5:
	/* 0x10e5: lea    eax,[rdx+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_10eb:
	/* 0x10eb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10f0:
	/* 0x10f0: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_10f6:
	/* 0x10f6: mov    BYTE PTR [rsi+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_10f9:
	/* 0x10f9: cmp    rdx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 17ULL);
x86_l_10fd:
	/* 0x10fd: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_1103:
	/* 0x1103: lea    eax,[rdx+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_1109:
	/* 0x1109: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_110e:
	/* 0x110e: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1114:
	/* 0x1114: mov    BYTE PTR [rsi+0x15],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_1117:
	/* 0x1117: cmp    rdx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18ULL);
x86_l_111b:
	/* 0x111b: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_1121:
	/* 0x1121: lea    eax,[rdx+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_1127:
	/* 0x1127: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_112c:
	/* 0x112c: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1132:
	/* 0x1132: mov    BYTE PTR [rsi+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_1135:
	/* 0x1135: cmp    rdx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 19ULL);
x86_l_1139:
	/* 0x1139: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_113f:
	/* 0x113f: lea    eax,[rdx+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_1145:
	/* 0x1145: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_114a:
	/* 0x114a: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1150:
	/* 0x1150: mov    BYTE PTR [rsi+0x17],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_1153:
	/* 0x1153: cmp    rdx,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 20ULL);
x86_l_1157:
	/* 0x1157: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_115d:
	/* 0x115d: lea    eax,[rdx+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_1163:
	/* 0x1163: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1168:
	/* 0x1168: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_116e:
	/* 0x116e: mov    BYTE PTR [rsi+0x18],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1171:
	/* 0x1171: cmp    rdx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 21ULL);
x86_l_1175:
	/* 0x1175: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_117b:
	/* 0x117b: lea    eax,[rdx+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_1181:
	/* 0x1181: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1186:
	/* 0x1186: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_118c:
	/* 0x118c: mov    BYTE PTR [rsi+0x19],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_118f:
	/* 0x118f: cmp    rdx,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 22ULL);
x86_l_1193:
	/* 0x1193: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_1199:
	/* 0x1199: lea    eax,[rdx+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_119f:
	/* 0x119f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11a4:
	/* 0x11a4: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_11aa:
	/* 0x11aa: mov    BYTE PTR [rsi+0x1a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_11ad:
	/* 0x11ad: cmp    rdx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 23ULL);
x86_l_11b1:
	/* 0x11b1: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_11b7:
	/* 0x11b7: lea    eax,[rdx+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_11bd:
	/* 0x11bd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11c2:
	/* 0x11c2: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_11c8:
	/* 0x11c8: mov    BYTE PTR [rsi+0x1b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_11cb:
	/* 0x11cb: cmp    rdx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 24ULL);
x86_l_11cf:
	/* 0x11cf: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_11d5:
	/* 0x11d5: lea    eax,[rdx+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_11db:
	/* 0x11db: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11e0:
	/* 0x11e0: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_11e6:
	/* 0x11e6: mov    BYTE PTR [rsi+0x1c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_11e9:
	/* 0x11e9: cmp    rdx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 25ULL);
x86_l_11ed:
	/* 0x11ed: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_11f3:
	/* 0x11f3: lea    eax,[rdx+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_11f9:
	/* 0x11f9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11fe:
	/* 0x11fe: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1204:
	/* 0x1204: mov    BYTE PTR [rsi+0x1d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_1207:
	/* 0x1207: cmp    rdx,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 26ULL);
x86_l_120b:
	/* 0x120b: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_1211:
	/* 0x1211: lea    eax,[rdx+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_1217:
	/* 0x1217: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_121c:
	/* 0x121c: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1222:
	/* 0x1222: mov    BYTE PTR [rsi+0x1e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_1225:
	/* 0x1225: cmp    rdx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 27ULL);
x86_l_1229:
	/* 0x1229: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_122f:
	/* 0x122f: lea    eax,[rdx+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_1235:
	/* 0x1235: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_123a:
	/* 0x123a: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1240:
	/* 0x1240: mov    BYTE PTR [rsi+0x1f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_1243:
	/* 0x1243: cmp    rdx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 28ULL);
x86_l_1247:
	/* 0x1247: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_124d:
	/* 0x124d: lea    eax,[rdx+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_1253:
	/* 0x1253: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1258:
	/* 0x1258: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_125e:
	/* 0x125e: mov    BYTE PTR [rsi+0x20],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1261:
	/* 0x1261: cmp    rdx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 29ULL);
x86_l_1265:
	/* 0x1265: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_126b:
	/* 0x126b: lea    eax,[rdx+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_1271:
	/* 0x1271: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1276:
	/* 0x1276: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_127c:
	/* 0x127c: mov    BYTE PTR [rsi+0x21],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_127f:
	/* 0x127f: cmp    rdx,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 30ULL);
x86_l_1283:
	/* 0x1283: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_1289:
	/* 0x1289: lea    eax,[rdx+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_128f:
	/* 0x128f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1294:
	/* 0x1294: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_129a:
	/* 0x129a: mov    BYTE PTR [rsi+0x22],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_129d:
	/* 0x129d: cmp    rdx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 31ULL);
x86_l_12a1:
	/* 0x12a1: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_12a7:
	/* 0x12a7: lea    eax,[rdx+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_12ad:
	/* 0x12ad: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12b2:
	/* 0x12b2: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_12b8:
	/* 0x12b8: mov    BYTE PTR [rsi+0x23],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_12bb:
	/* 0x12bb: cmp    rdx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 32ULL);
x86_l_12bf:
	/* 0x12bf: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_12c5:
	/* 0x12c5: lea    eax,[rdx+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_12cb:
	/* 0x12cb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12d0:
	/* 0x12d0: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_12d6:
	/* 0x12d6: mov    BYTE PTR [rsi+0x24],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_12d9:
	/* 0x12d9: cmp    rdx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 33ULL);
x86_l_12dd:
	/* 0x12dd: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_12e3:
	/* 0x12e3: lea    eax,[rdx+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_12e9:
	/* 0x12e9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_12ee:
	/* 0x12ee: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_12f4:
	/* 0x12f4: mov    BYTE PTR [rsi+0x25],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_12f7:
	/* 0x12f7: cmp    rdx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 34ULL);
x86_l_12fb:
	/* 0x12fb: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_1301:
	/* 0x1301: lea    eax,[rdx+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_1307:
	/* 0x1307: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_130c:
	/* 0x130c: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1312:
	/* 0x1312: mov    BYTE PTR [rsi+0x26],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_1315:
	/* 0x1315: cmp    rdx,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 35ULL);
x86_l_1319:
	/* 0x1319: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_131f:
	/* 0x131f: lea    eax,[rdx+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_1325:
	/* 0x1325: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_132a:
	/* 0x132a: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1330:
	/* 0x1330: mov    BYTE PTR [rsi+0x27],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_1333:
	/* 0x1333: cmp    rdx,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 36ULL);
x86_l_1337:
	/* 0x1337: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_133d:
	/* 0x133d: lea    eax,[rdx+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_1343:
	/* 0x1343: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1348:
	/* 0x1348: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_134e:
	/* 0x134e: mov    BYTE PTR [rsi+0x28],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1351:
	/* 0x1351: cmp    rdx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 37ULL);
x86_l_1355:
	/* 0x1355: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_135b:
	/* 0x135b: lea    eax,[rdx+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_1361:
	/* 0x1361: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1366:
	/* 0x1366: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_136c:
	/* 0x136c: mov    BYTE PTR [rsi+0x29],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_136f:
	/* 0x136f: cmp    rdx,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 38ULL);
x86_l_1373:
	/* 0x1373: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_1379:
	/* 0x1379: lea    eax,[rdx+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_137f:
	/* 0x137f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1384:
	/* 0x1384: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_138a:
	/* 0x138a: mov    BYTE PTR [rsi+0x2a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_138d:
	/* 0x138d: cmp    rdx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 39ULL);
x86_l_1391:
	/* 0x1391: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_1397:
	/* 0x1397: lea    eax,[rdx+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_139d:
	/* 0x139d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13a2:
	/* 0x13a2: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_13a8:
	/* 0x13a8: mov    BYTE PTR [rsi+0x2b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_13ab:
	/* 0x13ab: cmp    rdx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 40ULL);
x86_l_13af:
	/* 0x13af: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_13b5:
	/* 0x13b5: lea    eax,[rdx+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_13bb:
	/* 0x13bb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13c0:
	/* 0x13c0: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_13c6:
	/* 0x13c6: mov    BYTE PTR [rsi+0x2c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_13c9:
	/* 0x13c9: cmp    rdx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 41ULL);
x86_l_13cd:
	/* 0x13cd: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_13d3:
	/* 0x13d3: lea    eax,[rdx+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_13d9:
	/* 0x13d9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13de:
	/* 0x13de: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_13e4:
	/* 0x13e4: mov    BYTE PTR [rsi+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_13e7:
	/* 0x13e7: cmp    rdx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 42ULL);
x86_l_13eb:
	/* 0x13eb: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_13f1:
	/* 0x13f1: lea    eax,[rdx+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_13f7:
	/* 0x13f7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13fc:
	/* 0x13fc: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1402:
	/* 0x1402: mov    BYTE PTR [rsi+0x2e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_1405:
	/* 0x1405: cmp    rdx,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 43ULL);
x86_l_1409:
	/* 0x1409: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_140f:
	/* 0x140f: lea    eax,[rdx+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_1415:
	/* 0x1415: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_141a:
	/* 0x141a: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1420:
	/* 0x1420: mov    BYTE PTR [rsi+0x2f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_1423:
	/* 0x1423: cmp    rdx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 44ULL);
x86_l_1427:
	/* 0x1427: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_142d:
	/* 0x142d: lea    eax,[rdx+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_1433:
	/* 0x1433: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1438:
	/* 0x1438: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_143e:
	/* 0x143e: mov    BYTE PTR [rsi+0x30],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1441:
	/* 0x1441: cmp    rdx,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 45ULL);
x86_l_1445:
	/* 0x1445: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_144b:
	/* 0x144b: lea    eax,[rdx+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_1451:
	/* 0x1451: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1456:
	/* 0x1456: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_145c:
	/* 0x145c: mov    BYTE PTR [rsi+0x31],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_145f:
	/* 0x145f: cmp    rdx,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 46ULL);
x86_l_1463:
	/* 0x1463: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_1469:
	/* 0x1469: lea    eax,[rdx+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_146f:
	/* 0x146f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1474:
	/* 0x1474: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_147a:
	/* 0x147a: mov    BYTE PTR [rsi+0x32],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_147d:
	/* 0x147d: cmp    rdx,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 47ULL);
x86_l_1481:
	/* 0x1481: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_1487:
	/* 0x1487: lea    eax,[rdx+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_148d:
	/* 0x148d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1492:
	/* 0x1492: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1498:
	/* 0x1498: mov    BYTE PTR [rsi+0x33],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_149b:
	/* 0x149b: cmp    rdx,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 48ULL);
x86_l_149f:
	/* 0x149f: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_14a5:
	/* 0x14a5: lea    eax,[rdx+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_14ab:
	/* 0x14ab: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14b0:
	/* 0x14b0: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_14b6:
	/* 0x14b6: mov    BYTE PTR [rsi+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_14b9:
	/* 0x14b9: cmp    rdx,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 49ULL);
x86_l_14bd:
	/* 0x14bd: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_14c3:
	/* 0x14c3: lea    eax,[rdx+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_14c9:
	/* 0x14c9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14ce:
	/* 0x14ce: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_14d4:
	/* 0x14d4: mov    BYTE PTR [rsi+0x35],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_14d7:
	/* 0x14d7: cmp    rdx,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 50ULL);
x86_l_14db:
	/* 0x14db: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_14e1:
	/* 0x14e1: lea    eax,[rdx+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_14e7:
	/* 0x14e7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14ec:
	/* 0x14ec: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_14f2:
	/* 0x14f2: mov    BYTE PTR [rsi+0x36],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_14f5:
	/* 0x14f5: cmp    rdx,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 51ULL);
x86_l_14f9:
	/* 0x14f9: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_14ff:
	/* 0x14ff: lea    eax,[rdx+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_1505:
	/* 0x1505: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_150a:
	/* 0x150a: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1510:
	/* 0x1510: mov    BYTE PTR [rsi+0x37],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_1513:
	/* 0x1513: cmp    rdx,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 52ULL);
x86_l_1517:
	/* 0x1517: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_151d:
	/* 0x151d: lea    eax,[rdx+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_1523:
	/* 0x1523: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1528:
	/* 0x1528: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_152e:
	/* 0x152e: mov    BYTE PTR [rsi+0x38],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1531:
	/* 0x1531: cmp    rdx,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 53ULL);
x86_l_1535:
	/* 0x1535: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_153b:
	/* 0x153b: lea    eax,[rdx+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_1541:
	/* 0x1541: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1546:
	/* 0x1546: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_154c:
	/* 0x154c: mov    BYTE PTR [rsi+0x39],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_154f:
	/* 0x154f: cmp    rdx,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 54ULL);
x86_l_1553:
	/* 0x1553: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6640ULL;
	}
x86_l_1559:
	/* 0x1559: lea    eax,[rdx+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_155f:
	/* 0x155f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
	return 5476ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5476ULL: goto x86_l_1564;
	case 5482ULL: goto x86_l_156a;
	case 5485ULL: goto x86_l_156d;
	case 5489ULL: goto x86_l_1571;
	case 5495ULL: goto x86_l_1577;
	case 5501ULL: goto x86_l_157d;
	case 5506ULL: goto x86_l_1582;
	case 5512ULL: goto x86_l_1588;
	case 5515ULL: goto x86_l_158b;
	case 5519ULL: goto x86_l_158f;
	case 5525ULL: goto x86_l_1595;
	case 5531ULL: goto x86_l_159b;
	case 5536ULL: goto x86_l_15a0;
	case 5542ULL: goto x86_l_15a6;
	case 5545ULL: goto x86_l_15a9;
	case 5549ULL: goto x86_l_15ad;
	case 5555ULL: goto x86_l_15b3;
	case 5561ULL: goto x86_l_15b9;
	case 5566ULL: goto x86_l_15be;
	case 5572ULL: goto x86_l_15c4;
	case 5575ULL: goto x86_l_15c7;
	case 5579ULL: goto x86_l_15cb;
	case 5585ULL: goto x86_l_15d1;
	case 5591ULL: goto x86_l_15d7;
	case 5596ULL: goto x86_l_15dc;
	case 5602ULL: goto x86_l_15e2;
	case 5605ULL: goto x86_l_15e5;
	case 5609ULL: goto x86_l_15e9;
	case 5615ULL: goto x86_l_15ef;
	case 5621ULL: goto x86_l_15f5;
	case 5626ULL: goto x86_l_15fa;
	case 5632ULL: goto x86_l_1600;
	case 5635ULL: goto x86_l_1603;
	case 5639ULL: goto x86_l_1607;
	case 5645ULL: goto x86_l_160d;
	case 5651ULL: goto x86_l_1613;
	case 5656ULL: goto x86_l_1618;
	case 5662ULL: goto x86_l_161e;
	case 5665ULL: goto x86_l_1621;
	case 5669ULL: goto x86_l_1625;
	case 5675ULL: goto x86_l_162b;
	case 5681ULL: goto x86_l_1631;
	case 5686ULL: goto x86_l_1636;
	case 5692ULL: goto x86_l_163c;
	case 5695ULL: goto x86_l_163f;
	case 5699ULL: goto x86_l_1643;
	case 5705ULL: goto x86_l_1649;
	case 5711ULL: goto x86_l_164f;
	case 5716ULL: goto x86_l_1654;
	case 5722ULL: goto x86_l_165a;
	case 5725ULL: goto x86_l_165d;
	case 5729ULL: goto x86_l_1661;
	case 5735ULL: goto x86_l_1667;
	case 5741ULL: goto x86_l_166d;
	case 5746ULL: goto x86_l_1672;
	case 5752ULL: goto x86_l_1678;
	case 5755ULL: goto x86_l_167b;
	case 5759ULL: goto x86_l_167f;
	case 5765ULL: goto x86_l_1685;
	case 5771ULL: goto x86_l_168b;
	case 5776ULL: goto x86_l_1690;
	case 5782ULL: goto x86_l_1696;
	case 5785ULL: goto x86_l_1699;
	case 5789ULL: goto x86_l_169d;
	case 5795ULL: goto x86_l_16a3;
	case 5801ULL: goto x86_l_16a9;
	case 5806ULL: goto x86_l_16ae;
	case 5812ULL: goto x86_l_16b4;
	case 5815ULL: goto x86_l_16b7;
	case 5819ULL: goto x86_l_16bb;
	case 5825ULL: goto x86_l_16c1;
	case 5831ULL: goto x86_l_16c7;
	case 5836ULL: goto x86_l_16cc;
	case 5842ULL: goto x86_l_16d2;
	case 5845ULL: goto x86_l_16d5;
	case 5849ULL: goto x86_l_16d9;
	case 5855ULL: goto x86_l_16df;
	case 5861ULL: goto x86_l_16e5;
	case 5866ULL: goto x86_l_16ea;
	case 5872ULL: goto x86_l_16f0;
	case 5875ULL: goto x86_l_16f3;
	case 5879ULL: goto x86_l_16f7;
	case 5885ULL: goto x86_l_16fd;
	case 5891ULL: goto x86_l_1703;
	case 5896ULL: goto x86_l_1708;
	case 5902ULL: goto x86_l_170e;
	case 5905ULL: goto x86_l_1711;
	case 5909ULL: goto x86_l_1715;
	case 5915ULL: goto x86_l_171b;
	case 5921ULL: goto x86_l_1721;
	case 5926ULL: goto x86_l_1726;
	case 5932ULL: goto x86_l_172c;
	case 5935ULL: goto x86_l_172f;
	case 5939ULL: goto x86_l_1733;
	case 5945ULL: goto x86_l_1739;
	case 5951ULL: goto x86_l_173f;
	case 5956ULL: goto x86_l_1744;
	case 5962ULL: goto x86_l_174a;
	case 5965ULL: goto x86_l_174d;
	case 5969ULL: goto x86_l_1751;
	case 5975ULL: goto x86_l_1757;
	case 5981ULL: goto x86_l_175d;
	case 5986ULL: goto x86_l_1762;
	case 5992ULL: goto x86_l_1768;
	case 5995ULL: goto x86_l_176b;
	case 5999ULL: goto x86_l_176f;
	case 6005ULL: goto x86_l_1775;
	case 6011ULL: goto x86_l_177b;
	case 6016ULL: goto x86_l_1780;
	case 6022ULL: goto x86_l_1786;
	case 6025ULL: goto x86_l_1789;
	case 6029ULL: goto x86_l_178d;
	case 6035ULL: goto x86_l_1793;
	case 6041ULL: goto x86_l_1799;
	case 6046ULL: goto x86_l_179e;
	case 6052ULL: goto x86_l_17a4;
	case 6055ULL: goto x86_l_17a7;
	case 6059ULL: goto x86_l_17ab;
	case 6065ULL: goto x86_l_17b1;
	case 6071ULL: goto x86_l_17b7;
	case 6076ULL: goto x86_l_17bc;
	case 6082ULL: goto x86_l_17c2;
	case 6085ULL: goto x86_l_17c5;
	case 6089ULL: goto x86_l_17c9;
	case 6095ULL: goto x86_l_17cf;
	case 6101ULL: goto x86_l_17d5;
	case 6106ULL: goto x86_l_17da;
	case 6112ULL: goto x86_l_17e0;
	case 6115ULL: goto x86_l_17e3;
	case 6119ULL: goto x86_l_17e7;
	case 6125ULL: goto x86_l_17ed;
	case 6131ULL: goto x86_l_17f3;
	case 6136ULL: goto x86_l_17f8;
	case 6142ULL: goto x86_l_17fe;
	case 6145ULL: goto x86_l_1801;
	case 6149ULL: goto x86_l_1805;
	case 6155ULL: goto x86_l_180b;
	case 6161ULL: goto x86_l_1811;
	case 6166ULL: goto x86_l_1816;
	case 6172ULL: goto x86_l_181c;
	case 6175ULL: goto x86_l_181f;
	case 6179ULL: goto x86_l_1823;
	case 6185ULL: goto x86_l_1829;
	case 6191ULL: goto x86_l_182f;
	case 6196ULL: goto x86_l_1834;
	case 6202ULL: goto x86_l_183a;
	case 6205ULL: goto x86_l_183d;
	case 6209ULL: goto x86_l_1841;
	case 6215ULL: goto x86_l_1847;
	case 6221ULL: goto x86_l_184d;
	case 6226ULL: goto x86_l_1852;
	case 6232ULL: goto x86_l_1858;
	case 6235ULL: goto x86_l_185b;
	case 6239ULL: goto x86_l_185f;
	case 6245ULL: goto x86_l_1865;
	case 6251ULL: goto x86_l_186b;
	case 6256ULL: goto x86_l_1870;
	case 6262ULL: goto x86_l_1876;
	case 6265ULL: goto x86_l_1879;
	case 6269ULL: goto x86_l_187d;
	case 6275ULL: goto x86_l_1883;
	case 6281ULL: goto x86_l_1889;
	case 6286ULL: goto x86_l_188e;
	case 6292ULL: goto x86_l_1894;
	case 6295ULL: goto x86_l_1897;
	case 6299ULL: goto x86_l_189b;
	case 6305ULL: goto x86_l_18a1;
	case 6311ULL: goto x86_l_18a7;
	case 6316ULL: goto x86_l_18ac;
	case 6322ULL: goto x86_l_18b2;
	case 6325ULL: goto x86_l_18b5;
	case 6329ULL: goto x86_l_18b9;
	case 6335ULL: goto x86_l_18bf;
	case 6341ULL: goto x86_l_18c5;
	case 6346ULL: goto x86_l_18ca;
	case 6352ULL: goto x86_l_18d0;
	case 6355ULL: goto x86_l_18d3;
	case 6359ULL: goto x86_l_18d7;
	case 6365ULL: goto x86_l_18dd;
	case 6371ULL: goto x86_l_18e3;
	case 6376ULL: goto x86_l_18e8;
	case 6382ULL: goto x86_l_18ee;
	case 6385ULL: goto x86_l_18f1;
	case 6389ULL: goto x86_l_18f5;
	case 6395ULL: goto x86_l_18fb;
	case 6401ULL: goto x86_l_1901;
	case 6406ULL: goto x86_l_1906;
	case 6412ULL: goto x86_l_190c;
	case 6415ULL: goto x86_l_190f;
	case 6419ULL: goto x86_l_1913;
	case 6425ULL: goto x86_l_1919;
	case 6431ULL: goto x86_l_191f;
	case 6436ULL: goto x86_l_1924;
	case 6442ULL: goto x86_l_192a;
	case 6445ULL: goto x86_l_192d;
	case 6449ULL: goto x86_l_1931;
	case 6455ULL: goto x86_l_1937;
	case 6461ULL: goto x86_l_193d;
	case 6466ULL: goto x86_l_1942;
	case 6472ULL: goto x86_l_1948;
	case 6475ULL: goto x86_l_194b;
	case 6479ULL: goto x86_l_194f;
	case 6485ULL: goto x86_l_1955;
	case 6491ULL: goto x86_l_195b;
	case 6496ULL: goto x86_l_1960;
	case 6502ULL: goto x86_l_1966;
	case 6505ULL: goto x86_l_1969;
	case 6509ULL: goto x86_l_196d;
	case 6515ULL: goto x86_l_1973;
	case 6521ULL: goto x86_l_1979;
	case 6526ULL: goto x86_l_197e;
	case 6532ULL: goto x86_l_1984;
	case 6535ULL: goto x86_l_1987;
	case 6539ULL: goto x86_l_198b;
	case 6541ULL: goto x86_l_198d;
	case 6547ULL: goto x86_l_1993;
	case 6552ULL: goto x86_l_1998;
	case 6558ULL: goto x86_l_199e;
	case 6561ULL: goto x86_l_19a1;
	case 6565ULL: goto x86_l_19a5;
	case 6567ULL: goto x86_l_19a7;
	case 6573ULL: goto x86_l_19ad;
	case 6578ULL: goto x86_l_19b2;
	case 6584ULL: goto x86_l_19b8;
	case 6587ULL: goto x86_l_19bb;
	case 6591ULL: goto x86_l_19bf;
	case 6593ULL: goto x86_l_19c1;
	case 6599ULL: goto x86_l_19c7;
	case 6604ULL: goto x86_l_19cc;
	case 6610ULL: goto x86_l_19d2;
	case 6613ULL: goto x86_l_19d5;
	case 6617ULL: goto x86_l_19d9;
	case 6619ULL: goto x86_l_19db;
	case 6625ULL: goto x86_l_19e1;
	case 6631ULL: goto x86_l_19e7;
	case 6637ULL: goto x86_l_19ed;
	case 6640ULL: goto x86_l_19f0;
	case 6645ULL: goto x86_l_19f5;
	case 6650ULL: goto x86_l_19fa;
	case 6655ULL: goto x86_l_19ff;
	case 6660ULL: goto x86_l_1a04;
	case 6664ULL: goto x86_l_1a08;
	case 6667ULL: goto x86_l_1a0b;
	case 6671ULL: goto x86_l_1a0f;
	case 6679ULL: goto x86_l_1a17;
	case 6686ULL: goto x86_l_1a1e;
	case 6691ULL: goto x86_l_1a23;
	case 6696ULL: goto x86_l_1a28;
	case 6698ULL: goto x86_l_1a2a;
	case 6701ULL: goto x86_l_1a2d;
	case 6704ULL: goto x86_l_1a30;
	case 6707ULL: goto x86_l_1a33;
	case 6713ULL: goto x86_l_1a39;
	case 6716ULL: goto x86_l_1a3c;
	case 6722ULL: goto x86_l_1a42;
	case 6727ULL: goto x86_l_1a47;
	case 6734ULL: goto x86_l_1a4e;
	case 6739ULL: goto x86_l_1a53;
	case 6744ULL: goto x86_l_1a58;
	case 6746ULL: goto x86_l_1a5a;
	case 6749ULL: goto x86_l_1a5d;
	case 6755ULL: goto x86_l_1a63;
	case 6762ULL: goto x86_l_1a6a;
	case 6767ULL: goto x86_l_1a6f;
	case 6771ULL: goto x86_l_1a73;
	case 6778ULL: goto x86_l_1a7a;
	case 6780ULL: goto x86_l_1a7c;
	case 6783ULL: goto x86_l_1a7f;
	case 6787ULL: goto x86_l_1a83;
	case 6790ULL: goto x86_l_1a86;
	case 6795ULL: goto x86_l_1a8b;
	case 6800ULL: goto x86_l_1a90;
	case 6802ULL: goto x86_l_1a92;
	case 6807ULL: goto x86_l_1a97;
	case 6812ULL: goto x86_l_1a9c;
	case 6815ULL: goto x86_l_1a9f;
	case 6820ULL: goto x86_l_1aa4;
	case 6828ULL: goto x86_l_1aac;
	case 6835ULL: goto x86_l_1ab3;
	case 6841ULL: goto x86_l_1ab9;
	case 6845ULL: goto x86_l_1abd;
	case 6851ULL: goto x86_l_1ac3;
	case 6854ULL: goto x86_l_1ac6;
	case 6857ULL: goto x86_l_1ac9;
	case 6860ULL: goto x86_l_1acc;
	case 6863ULL: goto x86_l_1acf;
	case 6865ULL: goto x86_l_1ad1;
	case 6869ULL: goto x86_l_1ad5;
	case 6875ULL: goto x86_l_1adb;
	case 6877ULL: goto x86_l_1add;
	case 6883ULL: goto x86_l_1ae3;
	case 6886ULL: goto x86_l_1ae6;
	case 6891ULL: goto x86_l_1aeb;
	case 6895ULL: goto x86_l_1aef;
	case 6900ULL: goto x86_l_1af4;
	case 6905ULL: goto x86_l_1af9;
	case 6910ULL: goto x86_l_1afe;
	case 6914ULL: goto x86_l_1b02;
	case 6919ULL: goto x86_l_1b07;
	case 6923ULL: goto x86_l_1b0b;
	case 6928ULL: goto x86_l_1b10;
	case 6933ULL: goto x86_l_1b15;
	case 6935ULL: goto x86_l_1b17;
	case 6938ULL: goto x86_l_1b1a;
	case 6941ULL: goto x86_l_1b1d;
	case 6944ULL: goto x86_l_1b20;
	case 6946ULL: goto x86_l_1b22;
	case 6949ULL: goto x86_l_1b25;
	case 6951ULL: goto x86_l_1b27;
	case 6954ULL: goto x86_l_1b2a;
	case 6957ULL: goto x86_l_1b2d;
	case 6963ULL: goto x86_l_1b33;
	case 6966ULL: goto x86_l_1b36;
	case 6969ULL: goto x86_l_1b39;
	case 6975ULL: goto x86_l_1b3f;
	case 6980ULL: goto x86_l_1b44;
	case 6983ULL: goto x86_l_1b47;
	case 6985ULL: goto x86_l_1b49;
	case 6988ULL: goto x86_l_1b4c;
	case 6994ULL: goto x86_l_1b52;
	case 6997ULL: goto x86_l_1b55;
	case 7003ULL: goto x86_l_1b5b;
	case 7006ULL: goto x86_l_1b5e;
	case 7012ULL: goto x86_l_1b64;
	case 7017ULL: goto x86_l_1b69;
	case 7022ULL: goto x86_l_1b6e;
	case 7025ULL: goto x86_l_1b71;
	case 7031ULL: goto x86_l_1b77;
	case 7034ULL: goto x86_l_1b7a;
	case 7040ULL: goto x86_l_1b80;
	case 7043ULL: goto x86_l_1b83;
	case 7049ULL: goto x86_l_1b89;
	case 7054ULL: goto x86_l_1b8e;
	case 7057ULL: goto x86_l_1b91;
	case 7060ULL: goto x86_l_1b94;
	case 7066ULL: goto x86_l_1b9a;
	case 7074ULL: goto x86_l_1ba2;
	case 7081ULL: goto x86_l_1ba9;
	case 7087ULL: goto x86_l_1baf;
	case 7090ULL: goto x86_l_1bb2;
	case 7095ULL: goto x86_l_1bb7;
	case 7098ULL: goto x86_l_1bba;
	case 7104ULL: goto x86_l_1bc0;
	case 7107ULL: goto x86_l_1bc3;
	case 7113ULL: goto x86_l_1bc9;
	case 7116ULL: goto x86_l_1bcc;
	case 7122ULL: goto x86_l_1bd2;
	case 7127ULL: goto x86_l_1bd7;
	case 7132ULL: goto x86_l_1bdc;
	case 7136ULL: goto x86_l_1be0;
	case 7139ULL: goto x86_l_1be3;
	case 7143ULL: goto x86_l_1be7;
	case 7151ULL: goto x86_l_1bef;
	case 7158ULL: goto x86_l_1bf6;
	case 7163ULL: goto x86_l_1bfb;
	case 7168ULL: goto x86_l_1c00;
	case 7170ULL: goto x86_l_1c02;
	case 7173ULL: goto x86_l_1c05;
	case 7176ULL: goto x86_l_1c08;
	case 7179ULL: goto x86_l_1c0b;
	case 7185ULL: goto x86_l_1c11;
	case 7190ULL: goto x86_l_1c16;
	case 7193ULL: goto x86_l_1c19;
	case 7199ULL: goto x86_l_1c1f;
	case 7206ULL: goto x86_l_1c26;
	case 7211ULL: goto x86_l_1c2b;
	case 7216ULL: goto x86_l_1c30;
	case 7218ULL: goto x86_l_1c32;
	case 7221ULL: goto x86_l_1c35;
	case 7227ULL: goto x86_l_1c3b;
	case 7230ULL: goto x86_l_1c3e;
	case 7235ULL: goto x86_l_1c43;
	case 7239ULL: goto x86_l_1c47;
	case 7243ULL: goto x86_l_1c4b;
	case 7248ULL: goto x86_l_1c50;
	case 7252ULL: goto x86_l_1c54;
	case 7255ULL: goto x86_l_1c57;
	case 7257ULL: goto x86_l_1c59;
	case 7261ULL: goto x86_l_1c5d;
	case 7266ULL: goto x86_l_1c62;
	case 7270ULL: goto x86_l_1c66;
	case 7273ULL: goto x86_l_1c69;
	case 7277ULL: goto x86_l_1c6d;
	case 7283ULL: goto x86_l_1c73;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1564:
	/* 0x1564: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_156a:
	/* 0x156a: mov    BYTE PTR [rsi+0x3a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_156d:
	/* 0x156d: cmp    rdx,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 55ULL);
x86_l_1571:
	/* 0x1571: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_1577:
	/* 0x1577: lea    eax,[rdx+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_157d:
	/* 0x157d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1582:
	/* 0x1582: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1588:
	/* 0x1588: mov    BYTE PTR [rsi+0x3b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_158b:
	/* 0x158b: cmp    rdx,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 56ULL);
x86_l_158f:
	/* 0x158f: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_1595:
	/* 0x1595: lea    eax,[rdx+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_159b:
	/* 0x159b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15a0:
	/* 0x15a0: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_15a6:
	/* 0x15a6: mov    BYTE PTR [rsi+0x3c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_15a9:
	/* 0x15a9: cmp    rdx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 57ULL);
x86_l_15ad:
	/* 0x15ad: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_15b3:
	/* 0x15b3: lea    eax,[rdx+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_15b9:
	/* 0x15b9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15be:
	/* 0x15be: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_15c4:
	/* 0x15c4: mov    BYTE PTR [rsi+0x3d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_15c7:
	/* 0x15c7: cmp    rdx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 58ULL);
x86_l_15cb:
	/* 0x15cb: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_15d1:
	/* 0x15d1: lea    eax,[rdx+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_15d7:
	/* 0x15d7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15dc:
	/* 0x15dc: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_15e2:
	/* 0x15e2: mov    BYTE PTR [rsi+0x3e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_15e5:
	/* 0x15e5: cmp    rdx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 59ULL);
x86_l_15e9:
	/* 0x15e9: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_15ef:
	/* 0x15ef: lea    eax,[rdx+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_15f5:
	/* 0x15f5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15fa:
	/* 0x15fa: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1600:
	/* 0x1600: mov    BYTE PTR [rsi+0x3f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_1603:
	/* 0x1603: cmp    rdx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 60ULL);
x86_l_1607:
	/* 0x1607: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_160d:
	/* 0x160d: lea    eax,[rdx+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_1613:
	/* 0x1613: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1618:
	/* 0x1618: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_161e:
	/* 0x161e: mov    BYTE PTR [rsi+0x40],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1621:
	/* 0x1621: cmp    rdx,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 61ULL);
x86_l_1625:
	/* 0x1625: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_162b:
	/* 0x162b: lea    eax,[rdx+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_1631:
	/* 0x1631: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1636:
	/* 0x1636: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_163c:
	/* 0x163c: mov    BYTE PTR [rsi+0x41],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_163f:
	/* 0x163f: cmp    rdx,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 62ULL);
x86_l_1643:
	/* 0x1643: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_1649:
	/* 0x1649: lea    eax,[rdx+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_164f:
	/* 0x164f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1654:
	/* 0x1654: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_165a:
	/* 0x165a: mov    BYTE PTR [rsi+0x42],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_165d:
	/* 0x165d: cmp    rdx,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 63ULL);
x86_l_1661:
	/* 0x1661: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_1667:
	/* 0x1667: lea    eax,[rdx+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_166d:
	/* 0x166d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1672:
	/* 0x1672: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1678:
	/* 0x1678: mov    BYTE PTR [rsi+0x43],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_167b:
	/* 0x167b: cmp    rdx,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 64ULL);
x86_l_167f:
	/* 0x167f: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_1685:
	/* 0x1685: lea    eax,[rdx+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_168b:
	/* 0x168b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1690:
	/* 0x1690: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1696:
	/* 0x1696: mov    BYTE PTR [rsi+0x44],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1699:
	/* 0x1699: cmp    rdx,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 65ULL);
x86_l_169d:
	/* 0x169d: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_16a3:
	/* 0x16a3: lea    eax,[rdx+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
x86_l_16a9:
	/* 0x16a9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16ae:
	/* 0x16ae: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_16b4:
	/* 0x16b4: mov    BYTE PTR [rsi+0x45],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_16b7:
	/* 0x16b7: cmp    rdx,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 66ULL);
x86_l_16bb:
	/* 0x16bb: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_16c1:
	/* 0x16c1: lea    eax,[rdx+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_16c7:
	/* 0x16c7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16cc:
	/* 0x16cc: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_16d2:
	/* 0x16d2: mov    BYTE PTR [rsi+0x46],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_16d5:
	/* 0x16d5: cmp    rdx,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 67ULL);
x86_l_16d9:
	/* 0x16d9: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_16df:
	/* 0x16df: lea    eax,[rdx+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_16e5:
	/* 0x16e5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16ea:
	/* 0x16ea: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_16f0:
	/* 0x16f0: mov    BYTE PTR [rsi+0x47],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_16f3:
	/* 0x16f3: cmp    rdx,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 68ULL);
x86_l_16f7:
	/* 0x16f7: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_16fd:
	/* 0x16fd: lea    eax,[rdx+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_1703:
	/* 0x1703: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1708:
	/* 0x1708: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_170e:
	/* 0x170e: mov    BYTE PTR [rsi+0x48],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1711:
	/* 0x1711: cmp    rdx,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 69ULL);
x86_l_1715:
	/* 0x1715: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_171b:
	/* 0x171b: lea    eax,[rdx+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_1721:
	/* 0x1721: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1726:
	/* 0x1726: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_172c:
	/* 0x172c: mov    BYTE PTR [rsi+0x49],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_172f:
	/* 0x172f: cmp    rdx,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 70ULL);
x86_l_1733:
	/* 0x1733: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_1739:
	/* 0x1739: lea    eax,[rdx+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_173f:
	/* 0x173f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1744:
	/* 0x1744: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_174a:
	/* 0x174a: mov    BYTE PTR [rsi+0x4a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_174d:
	/* 0x174d: cmp    rdx,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 71ULL);
x86_l_1751:
	/* 0x1751: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_1757:
	/* 0x1757: lea    eax,[rdx+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_175d:
	/* 0x175d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1762:
	/* 0x1762: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1768:
	/* 0x1768: mov    BYTE PTR [rsi+0x4b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_176b:
	/* 0x176b: cmp    rdx,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 72ULL);
x86_l_176f:
	/* 0x176f: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_1775:
	/* 0x1775: lea    eax,[rdx+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_177b:
	/* 0x177b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1780:
	/* 0x1780: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1786:
	/* 0x1786: mov    BYTE PTR [rsi+0x4c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1789:
	/* 0x1789: cmp    rdx,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 73ULL);
x86_l_178d:
	/* 0x178d: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_1793:
	/* 0x1793: lea    eax,[rdx+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_1799:
	/* 0x1799: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_179e:
	/* 0x179e: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_17a4:
	/* 0x17a4: mov    BYTE PTR [rsi+0x4d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_17a7:
	/* 0x17a7: cmp    rdx,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 74ULL);
x86_l_17ab:
	/* 0x17ab: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_17b1:
	/* 0x17b1: lea    eax,[rdx+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_17b7:
	/* 0x17b7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17bc:
	/* 0x17bc: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_17c2:
	/* 0x17c2: mov    BYTE PTR [rsi+0x4e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_17c5:
	/* 0x17c5: cmp    rdx,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 75ULL);
x86_l_17c9:
	/* 0x17c9: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_17cf:
	/* 0x17cf: lea    eax,[rdx+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_17d5:
	/* 0x17d5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17da:
	/* 0x17da: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_17e0:
	/* 0x17e0: mov    BYTE PTR [rsi+0x4f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_17e3:
	/* 0x17e3: cmp    rdx,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 76ULL);
x86_l_17e7:
	/* 0x17e7: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_17ed:
	/* 0x17ed: lea    eax,[rdx+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_17f3:
	/* 0x17f3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17f8:
	/* 0x17f8: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_17fe:
	/* 0x17fe: mov    BYTE PTR [rsi+0x50],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1801:
	/* 0x1801: cmp    rdx,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 77ULL);
x86_l_1805:
	/* 0x1805: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_180b:
	/* 0x180b: lea    eax,[rdx+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_1811:
	/* 0x1811: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1816:
	/* 0x1816: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_181c:
	/* 0x181c: mov    BYTE PTR [rsi+0x51],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_181f:
	/* 0x181f: cmp    rdx,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 78ULL);
x86_l_1823:
	/* 0x1823: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_1829:
	/* 0x1829: lea    eax,[rdx+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_182f:
	/* 0x182f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1834:
	/* 0x1834: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_183a:
	/* 0x183a: mov    BYTE PTR [rsi+0x52],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_183d:
	/* 0x183d: cmp    rdx,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 79ULL);
x86_l_1841:
	/* 0x1841: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_1847:
	/* 0x1847: lea    eax,[rdx+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_184d:
	/* 0x184d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1852:
	/* 0x1852: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1858:
	/* 0x1858: mov    BYTE PTR [rsi+0x53],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_185b:
	/* 0x185b: cmp    rdx,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 80ULL);
x86_l_185f:
	/* 0x185f: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_1865:
	/* 0x1865: lea    eax,[rdx+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_186b:
	/* 0x186b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1870:
	/* 0x1870: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1876:
	/* 0x1876: mov    BYTE PTR [rsi+0x54],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_1879:
	/* 0x1879: cmp    rdx,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 81ULL);
x86_l_187d:
	/* 0x187d: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_1883:
	/* 0x1883: lea    eax,[rdx+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_1889:
	/* 0x1889: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_188e:
	/* 0x188e: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1894:
	/* 0x1894: mov    BYTE PTR [rsi+0x55],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_1897:
	/* 0x1897: cmp    rdx,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 82ULL);
x86_l_189b:
	/* 0x189b: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_18a1:
	/* 0x18a1: lea    eax,[rdx+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_18a7:
	/* 0x18a7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18ac:
	/* 0x18ac: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_18b2:
	/* 0x18b2: mov    BYTE PTR [rsi+0x56],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_18b5:
	/* 0x18b5: cmp    rdx,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 83ULL);
x86_l_18b9:
	/* 0x18b9: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_18bf:
	/* 0x18bf: lea    eax,[rdx+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_18c5:
	/* 0x18c5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18ca:
	/* 0x18ca: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_18d0:
	/* 0x18d0: mov    BYTE PTR [rsi+0x57],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_18d3:
	/* 0x18d3: cmp    rdx,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 84ULL);
x86_l_18d7:
	/* 0x18d7: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_18dd:
	/* 0x18dd: lea    eax,[rdx+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_18e3:
	/* 0x18e3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18e8:
	/* 0x18e8: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_18ee:
	/* 0x18ee: mov    BYTE PTR [rsi+0x58],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_18f1:
	/* 0x18f1: cmp    rdx,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 85ULL);
x86_l_18f5:
	/* 0x18f5: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_18fb:
	/* 0x18fb: lea    eax,[rdx+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_1901:
	/* 0x1901: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1906:
	/* 0x1906: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_190c:
	/* 0x190c: mov    BYTE PTR [rsi+0x59],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_190f:
	/* 0x190f: cmp    rdx,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 86ULL);
x86_l_1913:
	/* 0x1913: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_1919:
	/* 0x1919: lea    eax,[rdx+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_191f:
	/* 0x191f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1924:
	/* 0x1924: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_192a:
	/* 0x192a: mov    BYTE PTR [rsi+0x5a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_192d:
	/* 0x192d: cmp    rdx,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 87ULL);
x86_l_1931:
	/* 0x1931: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_1937:
	/* 0x1937: lea    eax,[rdx+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_193d:
	/* 0x193d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1942:
	/* 0x1942: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1948:
	/* 0x1948: mov    BYTE PTR [rsi+0x5b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_194b:
	/* 0x194b: cmp    rdx,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 88ULL);
x86_l_194f:
	/* 0x194f: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_1955:
	/* 0x1955: lea    eax,[rdx+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_195b:
	/* 0x195b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1960:
	/* 0x1960: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1966:
	/* 0x1966: mov    BYTE PTR [rsi+0x5c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_1969:
	/* 0x1969: cmp    rdx,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 89ULL);
x86_l_196d:
	/* 0x196d: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_1973:
	/* 0x1973: lea    eax,[rdx+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_1979:
	/* 0x1979: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_197e:
	/* 0x197e: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1984:
	/* 0x1984: mov    BYTE PTR [rsi+0x5d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_1987:
	/* 0x1987: cmp    rdx,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 90ULL);
x86_l_198b:
	/* 0x198b: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_198d:
	/* 0x198d: lea    eax,[rdx+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_1993:
	/* 0x1993: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1998:
	/* 0x1998: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_199e:
	/* 0x199e: mov    BYTE PTR [rsi+0x5e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_19a1:
	/* 0x19a1: cmp    rdx,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 91ULL);
x86_l_19a5:
	/* 0x19a5: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_19a7:
	/* 0x19a7: lea    eax,[rdx+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_19ad:
	/* 0x19ad: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19b2:
	/* 0x19b2: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_19b8:
	/* 0x19b8: mov    BYTE PTR [rsi+0x5f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_19bb:
	/* 0x19bb: cmp    rdx,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 92ULL);
x86_l_19bf:
	/* 0x19bf: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_19c1:
	/* 0x19c1: lea    eax,[rdx+0xfa3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4003ULL);
x86_l_19c7:
	/* 0x19c7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19cc:
	/* 0x19cc: movzx  eax,BYTE PTR [r13+rax*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_19d2:
	/* 0x19d2: mov    BYTE PTR [rsi+0x60],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_19d5:
	/* 0x19d5: cmp    rdx,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 93ULL);
x86_l_19d9:
	/* 0x19d9: je     19f0 <generic_retuprobe_filter_arg_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19f0;
	}
x86_l_19db:
	/* 0x19db: add    edx,0xfa2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 4002ULL);
x86_l_19e1:
	/* 0x19e1: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19e7:
	/* 0x19e7: movzx  eax,BYTE PTR [r13+rdx*1+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_8), 0ULL);
x86_l_19ed:
	/* 0x19ed: mov    BYTE PTR [rsi+0x61],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_19f0:
	/* 0x19f0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19f5:
	/* 0x19f5: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19fa:
	/* 0x19fa: jmp    319f <generic_retuprobe_filter_arg_2+0x319f> */
	return 12703ULL;
x86_l_19ff:
	/* 0x19ff: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a04:
	/* 0x1a04: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a08:
	/* 0x1a08: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a0b:
	/* 0x1a0b: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a0f:
	/* 0x1a0f: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1a17:
	/* 0x1a17: mov    rdi,QWORD PTR [rip+0x17e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_1a1e:
	/* 0x1a1e: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a23:
	/* 0x1a23: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a28:
	/* 0x1a28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a2a:
	/* 0x1a2a: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1a2d:
	/* 0x1a2d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a30:
	/* 0x1a30: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1a33:
	/* 0x1a33: je     31b0 <generic_retuprobe_filter_arg_2+0x31b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12720ULL;
	}
x86_l_1a39:
	/* 0x1a39: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a3c:
	/* 0x1a3c: je     31b0 <generic_retuprobe_filter_arg_2+0x31b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12720ULL;
	}
x86_l_1a42:
	/* 0x1a42: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a47:
	/* 0x1a47: mov    rdi,QWORD PTR [rip+0x17e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_1a4e:
	/* 0x1a4e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a53:
	/* 0x1a53: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a58:
	/* 0x1a58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a5a:
	/* 0x1a5a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a5d:
	/* 0x1a5d: je     31ad <generic_retuprobe_filter_arg_2+0x31ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12717ULL;
	}
x86_l_1a63:
	/* 0x1a63: cmp    r13d,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 255ULL);
x86_l_1a6a:
	/* 0x1a6a: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_1a6f:
	/* 0x1a6f: cmovb  esi,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_1a73:
	/* 0x1a73: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_1a7a:
	/* 0x1a7a: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a7c:
	/* 0x1a7c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1a7f:
	/* 0x1a7f: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1a83:
	/* 0x1a83: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1a86:
	/* 0x1a86: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a8b:
	/* 0x1a8b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a90:
	/* 0x1a90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a92:
	/* 0x1a92: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a97:
	/* 0x1a97: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a9c:
	/* 0x1a9c: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1a9f:
	/* 0x1a9f: jmp    319f <generic_retuprobe_filter_arg_2+0x319f> */
	return 12703ULL;
x86_l_1aa4:
	/* 0x1aa4: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1aac:
	/* 0x1aac: cmp    r13d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 144ULL);
x86_l_1ab3:
	/* 0x1ab3: ja     2c17 <generic_retuprobe_filter_arg_2+0x2c17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11287ULL;
	}
x86_l_1ab9:
	/* 0x1ab9: movzx  eax,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1abd:
	/* 0x1abd: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_1ac3:
	/* 0x1ac3: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1ac6:
	/* 0x1ac6: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1ac9:
	/* 0x1ac9: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1acc:
	/* 0x1acc: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_1acf:
	/* 0x1acf: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1ad1:
	/* 0x1ad1: test   r13w,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_16);
x86_l_1ad5:
	/* 0x1ad5: je     2ae9 <generic_retuprobe_filter_arg_2+0x2ae9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10985ULL;
	}
x86_l_1adb:
	/* 0x1adb: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1add:
	/* 0x1add: jne    2ae9 <generic_retuprobe_filter_arg_2+0x2ae9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10985ULL;
	}
x86_l_1ae3:
	/* 0x1ae3: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_1ae6:
	/* 0x1ae6: jmp    2b01 <generic_retuprobe_filter_arg_2+0x2b01> */
	return 11009ULL;
x86_l_1aeb:
	/* 0x1aeb: movzx  eax,WORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1aef:
	/* 0x1aef: mov    WORD PTR [rsp+0x76],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 118ULL);
x86_l_1af4:
	/* 0x1af4: movzx  eax,WORD PTR [r8+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1af9:
	/* 0x1af9: mov    WORD PTR [rsp+0x70],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1afe:
	/* 0x1afe: mov    rax,QWORD PTR [r8+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b02:
	/* 0x1b02: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b07:
	/* 0x1b07: mov    rax,QWORD PTR [r8+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b0b:
	/* 0x1b0b: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b10:
	/* 0x1b10: lea    r8,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b15:
	/* 0x1b15: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b17:
	/* 0x1b17: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b1a:
	/* 0x1b1a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b1d:
	/* 0x1b1d: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_1b20:
	/* 0x1b20: jle    1b44 <generic_retuprobe_filter_arg_2+0x1b44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1b44;
	}
x86_l_1b22:
	/* 0x1b22: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_1b25:
	/* 0x1b25: jg     1b6e <generic_retuprobe_filter_arg_2+0x1b6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1b6e;
	}
x86_l_1b27:
	/* 0x1b27: lea    ecx,[rax-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_1b2a:
	/* 0x1b2a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b2d:
	/* 0x1b2d: jb     27ac <generic_retuprobe_filter_arg_2+0x27ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10156ULL;
	}
x86_l_1b33:
	/* 0x1b33: lea    ecx,[rax-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_1b36:
	/* 0x1b36: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b39:
	/* 0x1b39: jb     27a5 <generic_retuprobe_filter_arg_2+0x27a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10149ULL;
	}
x86_l_1b3f:
	/* 0x1b3f: jmp    31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	return 12754ULL;
x86_l_1b44:
	/* 0x1b44: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1b47:
	/* 0x1b47: jle    1bb7 <generic_retuprobe_filter_arg_2+0x1bb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1bb7;
	}
x86_l_1b49:
	/* 0x1b49: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1b4c:
	/* 0x1b4c: jg     2797 <generic_retuprobe_filter_arg_2+0x2797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10135ULL;
	}
x86_l_1b52:
	/* 0x1b52: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1b55:
	/* 0x1b55: je     27a5 <generic_retuprobe_filter_arg_2+0x27a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10149ULL;
	}
x86_l_1b5b:
	/* 0x1b5b: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1b5e:
	/* 0x1b5e: jne    31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12754ULL;
	}
x86_l_1b64:
	/* 0x1b64: movzx  r12d,WORD PTR [r8+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1b69:
	/* 0x1b69: jmp    2c24 <generic_retuprobe_filter_arg_2+0x2c24> */
	return 11300ULL;
x86_l_1b6e:
	/* 0x1b6e: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1b71:
	/* 0x1b71: jg     27bb <generic_retuprobe_filter_arg_2+0x27bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10171ULL;
	}
x86_l_1b77:
	/* 0x1b77: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_1b7a:
	/* 0x1b7a: je     27f1 <generic_retuprobe_filter_arg_2+0x27f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10225ULL;
	}
x86_l_1b80:
	/* 0x1b80: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1b83:
	/* 0x1b83: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1b89:
	/* 0x1b89: jmp    31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	return 12754ULL;
x86_l_1b8e:
	/* 0x1b8e: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1b91:
	/* 0x1b91: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b94:
	/* 0x1b94: jae    2aaf <generic_retuprobe_filter_arg_2+0x2aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10927ULL;
	}
x86_l_1b9a:
	/* 0x1b9a: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1ba2:
	/* 0x1ba2: cmp    r13d,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 144ULL);
x86_l_1ba9:
	/* 0x1ba9: jbe    2ab7 <generic_retuprobe_filter_arg_2+0x2ab7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 10935ULL;
	}
x86_l_1baf:
	/* 0x1baf: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bb2:
	/* 0x1bb2: jmp    3115 <generic_retuprobe_filter_arg_2+0x3115> */
	return 12565ULL;
x86_l_1bb7:
	/* 0x1bb7: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1bba:
	/* 0x1bba: je     27f1 <generic_retuprobe_filter_arg_2+0x27f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10225ULL;
	}
x86_l_1bc0:
	/* 0x1bc0: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1bc3:
	/* 0x1bc3: je     27e7 <generic_retuprobe_filter_arg_2+0x27e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10215ULL;
	}
x86_l_1bc9:
	/* 0x1bc9: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1bcc:
	/* 0x1bcc: je     27ac <generic_retuprobe_filter_arg_2+0x27ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10156ULL;
	}
x86_l_1bd2:
	/* 0x1bd2: jmp    31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	return 12754ULL;
x86_l_1bd7:
	/* 0x1bd7: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bdc:
	/* 0x1bdc: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1be0:
	/* 0x1be0: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1be3:
	/* 0x1be3: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1be7:
	/* 0x1be7: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1bef:
	/* 0x1bef: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_1bf6:
	/* 0x1bf6: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1bfb:
	/* 0x1bfb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c00:
	/* 0x1c00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c02:
	/* 0x1c02: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1c05:
	/* 0x1c05: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c08:
	/* 0x1c08: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1c0b:
	/* 0x1c0b: je     3111 <generic_retuprobe_filter_arg_2+0x3111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12561ULL;
	}
x86_l_1c11:
	/* 0x1c11: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c16:
	/* 0x1c16: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c19:
	/* 0x1c19: je     3111 <generic_retuprobe_filter_arg_2+0x3111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12561ULL;
	}
x86_l_1c1f:
	/* 0x1c1f: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_1c26:
	/* 0x1c26: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c2b:
	/* 0x1c2b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c30:
	/* 0x1c30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c32:
	/* 0x1c32: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c35:
	/* 0x1c35: je     310e <generic_retuprobe_filter_arg_2+0x310e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12558ULL;
	}
x86_l_1c3b:
	/* 0x1c3b: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1c3e:
	/* 0x1c3e: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c43:
	/* 0x1c43: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1c47:
	/* 0x1c47: cmp    r13d,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 94ULL);
x86_l_1c4b:
	/* 0x1c4b: mov    eax,0x5e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 94ULL);
x86_l_1c50:
	/* 0x1c50: cmovb  eax,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_1c54:
	/* 0x1c54: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1c57:
	/* 0x1c57: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c59:
	/* 0x1c59: lea    eax,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1c5d:
	/* 0x1c5d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1c62:
	/* 0x1c62: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1c66:
	/* 0x1c66: mov    BYTE PTR [rsi+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c69:
	/* 0x1c69: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_1c6d:
	/* 0x1c6d: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1c73:
	/* 0x1c73: lea    eax,[r13+0xffe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4094ULL);
	return 7290ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7290ULL: goto x86_l_1c7a;
	case 7295ULL: goto x86_l_1c7f;
	case 7299ULL: goto x86_l_1c83;
	case 7302ULL: goto x86_l_1c86;
	case 7306ULL: goto x86_l_1c8a;
	case 7312ULL: goto x86_l_1c90;
	case 7319ULL: goto x86_l_1c97;
	case 7324ULL: goto x86_l_1c9c;
	case 7328ULL: goto x86_l_1ca0;
	case 7331ULL: goto x86_l_1ca3;
	case 7335ULL: goto x86_l_1ca7;
	case 7341ULL: goto x86_l_1cad;
	case 7348ULL: goto x86_l_1cb4;
	case 7353ULL: goto x86_l_1cb9;
	case 7357ULL: goto x86_l_1cbd;
	case 7360ULL: goto x86_l_1cc0;
	case 7364ULL: goto x86_l_1cc4;
	case 7370ULL: goto x86_l_1cca;
	case 7377ULL: goto x86_l_1cd1;
	case 7382ULL: goto x86_l_1cd6;
	case 7386ULL: goto x86_l_1cda;
	case 7389ULL: goto x86_l_1cdd;
	case 7393ULL: goto x86_l_1ce1;
	case 7399ULL: goto x86_l_1ce7;
	case 7406ULL: goto x86_l_1cee;
	case 7411ULL: goto x86_l_1cf3;
	case 7415ULL: goto x86_l_1cf7;
	case 7418ULL: goto x86_l_1cfa;
	case 7422ULL: goto x86_l_1cfe;
	case 7428ULL: goto x86_l_1d04;
	case 7435ULL: goto x86_l_1d0b;
	case 7440ULL: goto x86_l_1d10;
	case 7444ULL: goto x86_l_1d14;
	case 7447ULL: goto x86_l_1d17;
	case 7451ULL: goto x86_l_1d1b;
	case 7457ULL: goto x86_l_1d21;
	case 7464ULL: goto x86_l_1d28;
	case 7469ULL: goto x86_l_1d2d;
	case 7473ULL: goto x86_l_1d31;
	case 7476ULL: goto x86_l_1d34;
	case 7480ULL: goto x86_l_1d38;
	case 7486ULL: goto x86_l_1d3e;
	case 7493ULL: goto x86_l_1d45;
	case 7498ULL: goto x86_l_1d4a;
	case 7502ULL: goto x86_l_1d4e;
	case 7505ULL: goto x86_l_1d51;
	case 7509ULL: goto x86_l_1d55;
	case 7515ULL: goto x86_l_1d5b;
	case 7522ULL: goto x86_l_1d62;
	case 7527ULL: goto x86_l_1d67;
	case 7531ULL: goto x86_l_1d6b;
	case 7534ULL: goto x86_l_1d6e;
	case 7538ULL: goto x86_l_1d72;
	case 7544ULL: goto x86_l_1d78;
	case 7551ULL: goto x86_l_1d7f;
	case 7556ULL: goto x86_l_1d84;
	case 7560ULL: goto x86_l_1d88;
	case 7563ULL: goto x86_l_1d8b;
	case 7567ULL: goto x86_l_1d8f;
	case 7573ULL: goto x86_l_1d95;
	case 7580ULL: goto x86_l_1d9c;
	case 7585ULL: goto x86_l_1da1;
	case 7589ULL: goto x86_l_1da5;
	case 7592ULL: goto x86_l_1da8;
	case 7596ULL: goto x86_l_1dac;
	case 7602ULL: goto x86_l_1db2;
	case 7609ULL: goto x86_l_1db9;
	case 7614ULL: goto x86_l_1dbe;
	case 7618ULL: goto x86_l_1dc2;
	case 7621ULL: goto x86_l_1dc5;
	case 7625ULL: goto x86_l_1dc9;
	case 7631ULL: goto x86_l_1dcf;
	case 7638ULL: goto x86_l_1dd6;
	case 7643ULL: goto x86_l_1ddb;
	case 7647ULL: goto x86_l_1ddf;
	case 7650ULL: goto x86_l_1de2;
	case 7654ULL: goto x86_l_1de6;
	case 7660ULL: goto x86_l_1dec;
	case 7667ULL: goto x86_l_1df3;
	case 7672ULL: goto x86_l_1df8;
	case 7676ULL: goto x86_l_1dfc;
	case 7679ULL: goto x86_l_1dff;
	case 7683ULL: goto x86_l_1e03;
	case 7689ULL: goto x86_l_1e09;
	case 7696ULL: goto x86_l_1e10;
	case 7701ULL: goto x86_l_1e15;
	case 7705ULL: goto x86_l_1e19;
	case 7708ULL: goto x86_l_1e1c;
	case 7712ULL: goto x86_l_1e20;
	case 7718ULL: goto x86_l_1e26;
	case 7725ULL: goto x86_l_1e2d;
	case 7730ULL: goto x86_l_1e32;
	case 7734ULL: goto x86_l_1e36;
	case 7737ULL: goto x86_l_1e39;
	case 7741ULL: goto x86_l_1e3d;
	case 7747ULL: goto x86_l_1e43;
	case 7754ULL: goto x86_l_1e4a;
	case 7759ULL: goto x86_l_1e4f;
	case 7763ULL: goto x86_l_1e53;
	case 7766ULL: goto x86_l_1e56;
	case 7770ULL: goto x86_l_1e5a;
	case 7776ULL: goto x86_l_1e60;
	case 7783ULL: goto x86_l_1e67;
	case 7788ULL: goto x86_l_1e6c;
	case 7792ULL: goto x86_l_1e70;
	case 7795ULL: goto x86_l_1e73;
	case 7799ULL: goto x86_l_1e77;
	case 7805ULL: goto x86_l_1e7d;
	case 7812ULL: goto x86_l_1e84;
	case 7817ULL: goto x86_l_1e89;
	case 7821ULL: goto x86_l_1e8d;
	case 7824ULL: goto x86_l_1e90;
	case 7828ULL: goto x86_l_1e94;
	case 7834ULL: goto x86_l_1e9a;
	case 7841ULL: goto x86_l_1ea1;
	case 7846ULL: goto x86_l_1ea6;
	case 7850ULL: goto x86_l_1eaa;
	case 7853ULL: goto x86_l_1ead;
	case 7857ULL: goto x86_l_1eb1;
	case 7863ULL: goto x86_l_1eb7;
	case 7870ULL: goto x86_l_1ebe;
	case 7875ULL: goto x86_l_1ec3;
	case 7879ULL: goto x86_l_1ec7;
	case 7882ULL: goto x86_l_1eca;
	case 7886ULL: goto x86_l_1ece;
	case 7892ULL: goto x86_l_1ed4;
	case 7899ULL: goto x86_l_1edb;
	case 7904ULL: goto x86_l_1ee0;
	case 7908ULL: goto x86_l_1ee4;
	case 7911ULL: goto x86_l_1ee7;
	case 7915ULL: goto x86_l_1eeb;
	case 7921ULL: goto x86_l_1ef1;
	case 7928ULL: goto x86_l_1ef8;
	case 7933ULL: goto x86_l_1efd;
	case 7937ULL: goto x86_l_1f01;
	case 7940ULL: goto x86_l_1f04;
	case 7944ULL: goto x86_l_1f08;
	case 7950ULL: goto x86_l_1f0e;
	case 7957ULL: goto x86_l_1f15;
	case 7962ULL: goto x86_l_1f1a;
	case 7966ULL: goto x86_l_1f1e;
	case 7969ULL: goto x86_l_1f21;
	case 7973ULL: goto x86_l_1f25;
	case 7979ULL: goto x86_l_1f2b;
	case 7986ULL: goto x86_l_1f32;
	case 7991ULL: goto x86_l_1f37;
	case 7995ULL: goto x86_l_1f3b;
	case 7998ULL: goto x86_l_1f3e;
	case 8002ULL: goto x86_l_1f42;
	case 8008ULL: goto x86_l_1f48;
	case 8015ULL: goto x86_l_1f4f;
	case 8020ULL: goto x86_l_1f54;
	case 8024ULL: goto x86_l_1f58;
	case 8027ULL: goto x86_l_1f5b;
	case 8031ULL: goto x86_l_1f5f;
	case 8037ULL: goto x86_l_1f65;
	case 8044ULL: goto x86_l_1f6c;
	case 8049ULL: goto x86_l_1f71;
	case 8053ULL: goto x86_l_1f75;
	case 8056ULL: goto x86_l_1f78;
	case 8060ULL: goto x86_l_1f7c;
	case 8066ULL: goto x86_l_1f82;
	case 8073ULL: goto x86_l_1f89;
	case 8078ULL: goto x86_l_1f8e;
	case 8082ULL: goto x86_l_1f92;
	case 8085ULL: goto x86_l_1f95;
	case 8089ULL: goto x86_l_1f99;
	case 8095ULL: goto x86_l_1f9f;
	case 8102ULL: goto x86_l_1fa6;
	case 8107ULL: goto x86_l_1fab;
	case 8111ULL: goto x86_l_1faf;
	case 8114ULL: goto x86_l_1fb2;
	case 8118ULL: goto x86_l_1fb6;
	case 8124ULL: goto x86_l_1fbc;
	case 8131ULL: goto x86_l_1fc3;
	case 8136ULL: goto x86_l_1fc8;
	case 8140ULL: goto x86_l_1fcc;
	case 8143ULL: goto x86_l_1fcf;
	case 8147ULL: goto x86_l_1fd3;
	case 8153ULL: goto x86_l_1fd9;
	case 8160ULL: goto x86_l_1fe0;
	case 8165ULL: goto x86_l_1fe5;
	case 8169ULL: goto x86_l_1fe9;
	case 8172ULL: goto x86_l_1fec;
	case 8176ULL: goto x86_l_1ff0;
	case 8182ULL: goto x86_l_1ff6;
	case 8189ULL: goto x86_l_1ffd;
	case 8194ULL: goto x86_l_2002;
	case 8198ULL: goto x86_l_2006;
	case 8201ULL: goto x86_l_2009;
	case 8205ULL: goto x86_l_200d;
	case 8211ULL: goto x86_l_2013;
	case 8218ULL: goto x86_l_201a;
	case 8223ULL: goto x86_l_201f;
	case 8227ULL: goto x86_l_2023;
	case 8230ULL: goto x86_l_2026;
	case 8234ULL: goto x86_l_202a;
	case 8240ULL: goto x86_l_2030;
	case 8247ULL: goto x86_l_2037;
	case 8252ULL: goto x86_l_203c;
	case 8256ULL: goto x86_l_2040;
	case 8259ULL: goto x86_l_2043;
	case 8263ULL: goto x86_l_2047;
	case 8269ULL: goto x86_l_204d;
	case 8276ULL: goto x86_l_2054;
	case 8281ULL: goto x86_l_2059;
	case 8285ULL: goto x86_l_205d;
	case 8288ULL: goto x86_l_2060;
	case 8292ULL: goto x86_l_2064;
	case 8298ULL: goto x86_l_206a;
	case 8305ULL: goto x86_l_2071;
	case 8310ULL: goto x86_l_2076;
	case 8314ULL: goto x86_l_207a;
	case 8317ULL: goto x86_l_207d;
	case 8321ULL: goto x86_l_2081;
	case 8327ULL: goto x86_l_2087;
	case 8334ULL: goto x86_l_208e;
	case 8339ULL: goto x86_l_2093;
	case 8343ULL: goto x86_l_2097;
	case 8346ULL: goto x86_l_209a;
	case 8350ULL: goto x86_l_209e;
	case 8356ULL: goto x86_l_20a4;
	case 8363ULL: goto x86_l_20ab;
	case 8368ULL: goto x86_l_20b0;
	case 8372ULL: goto x86_l_20b4;
	case 8375ULL: goto x86_l_20b7;
	case 8379ULL: goto x86_l_20bb;
	case 8385ULL: goto x86_l_20c1;
	case 8392ULL: goto x86_l_20c8;
	case 8397ULL: goto x86_l_20cd;
	case 8401ULL: goto x86_l_20d1;
	case 8404ULL: goto x86_l_20d4;
	case 8408ULL: goto x86_l_20d8;
	case 8414ULL: goto x86_l_20de;
	case 8421ULL: goto x86_l_20e5;
	case 8426ULL: goto x86_l_20ea;
	case 8430ULL: goto x86_l_20ee;
	case 8433ULL: goto x86_l_20f1;
	case 8437ULL: goto x86_l_20f5;
	case 8443ULL: goto x86_l_20fb;
	case 8450ULL: goto x86_l_2102;
	case 8455ULL: goto x86_l_2107;
	case 8459ULL: goto x86_l_210b;
	case 8462ULL: goto x86_l_210e;
	case 8466ULL: goto x86_l_2112;
	case 8472ULL: goto x86_l_2118;
	case 8479ULL: goto x86_l_211f;
	case 8484ULL: goto x86_l_2124;
	case 8488ULL: goto x86_l_2128;
	case 8491ULL: goto x86_l_212b;
	case 8495ULL: goto x86_l_212f;
	case 8501ULL: goto x86_l_2135;
	case 8508ULL: goto x86_l_213c;
	case 8513ULL: goto x86_l_2141;
	case 8517ULL: goto x86_l_2145;
	case 8520ULL: goto x86_l_2148;
	case 8524ULL: goto x86_l_214c;
	case 8530ULL: goto x86_l_2152;
	case 8537ULL: goto x86_l_2159;
	case 8542ULL: goto x86_l_215e;
	case 8546ULL: goto x86_l_2162;
	case 8549ULL: goto x86_l_2165;
	case 8553ULL: goto x86_l_2169;
	case 8559ULL: goto x86_l_216f;
	case 8566ULL: goto x86_l_2176;
	case 8571ULL: goto x86_l_217b;
	case 8575ULL: goto x86_l_217f;
	case 8578ULL: goto x86_l_2182;
	case 8582ULL: goto x86_l_2186;
	case 8588ULL: goto x86_l_218c;
	case 8595ULL: goto x86_l_2193;
	case 8600ULL: goto x86_l_2198;
	case 8604ULL: goto x86_l_219c;
	case 8607ULL: goto x86_l_219f;
	case 8611ULL: goto x86_l_21a3;
	case 8617ULL: goto x86_l_21a9;
	case 8624ULL: goto x86_l_21b0;
	case 8629ULL: goto x86_l_21b5;
	case 8633ULL: goto x86_l_21b9;
	case 8636ULL: goto x86_l_21bc;
	case 8640ULL: goto x86_l_21c0;
	case 8646ULL: goto x86_l_21c6;
	case 8653ULL: goto x86_l_21cd;
	case 8658ULL: goto x86_l_21d2;
	case 8662ULL: goto x86_l_21d6;
	case 8665ULL: goto x86_l_21d9;
	case 8669ULL: goto x86_l_21dd;
	case 8675ULL: goto x86_l_21e3;
	case 8682ULL: goto x86_l_21ea;
	case 8687ULL: goto x86_l_21ef;
	case 8691ULL: goto x86_l_21f3;
	case 8694ULL: goto x86_l_21f6;
	case 8698ULL: goto x86_l_21fa;
	case 8704ULL: goto x86_l_2200;
	case 8711ULL: goto x86_l_2207;
	case 8716ULL: goto x86_l_220c;
	case 8720ULL: goto x86_l_2210;
	case 8723ULL: goto x86_l_2213;
	case 8727ULL: goto x86_l_2217;
	case 8733ULL: goto x86_l_221d;
	case 8740ULL: goto x86_l_2224;
	case 8745ULL: goto x86_l_2229;
	case 8749ULL: goto x86_l_222d;
	case 8752ULL: goto x86_l_2230;
	case 8756ULL: goto x86_l_2234;
	case 8762ULL: goto x86_l_223a;
	case 8769ULL: goto x86_l_2241;
	case 8774ULL: goto x86_l_2246;
	case 8778ULL: goto x86_l_224a;
	case 8781ULL: goto x86_l_224d;
	case 8785ULL: goto x86_l_2251;
	case 8791ULL: goto x86_l_2257;
	case 8798ULL: goto x86_l_225e;
	case 8803ULL: goto x86_l_2263;
	case 8807ULL: goto x86_l_2267;
	case 8810ULL: goto x86_l_226a;
	case 8814ULL: goto x86_l_226e;
	case 8820ULL: goto x86_l_2274;
	case 8827ULL: goto x86_l_227b;
	case 8832ULL: goto x86_l_2280;
	case 8836ULL: goto x86_l_2284;
	case 8839ULL: goto x86_l_2287;
	case 8843ULL: goto x86_l_228b;
	case 8849ULL: goto x86_l_2291;
	case 8856ULL: goto x86_l_2298;
	case 8861ULL: goto x86_l_229d;
	case 8865ULL: goto x86_l_22a1;
	case 8868ULL: goto x86_l_22a4;
	case 8872ULL: goto x86_l_22a8;
	case 8878ULL: goto x86_l_22ae;
	case 8885ULL: goto x86_l_22b5;
	case 8890ULL: goto x86_l_22ba;
	case 8894ULL: goto x86_l_22be;
	case 8897ULL: goto x86_l_22c1;
	case 8901ULL: goto x86_l_22c5;
	case 8907ULL: goto x86_l_22cb;
	case 8914ULL: goto x86_l_22d2;
	case 8919ULL: goto x86_l_22d7;
	case 8923ULL: goto x86_l_22db;
	case 8926ULL: goto x86_l_22de;
	case 8930ULL: goto x86_l_22e2;
	case 8936ULL: goto x86_l_22e8;
	case 8943ULL: goto x86_l_22ef;
	case 8948ULL: goto x86_l_22f4;
	case 8952ULL: goto x86_l_22f8;
	case 8955ULL: goto x86_l_22fb;
	case 8959ULL: goto x86_l_22ff;
	case 8965ULL: goto x86_l_2305;
	case 8972ULL: goto x86_l_230c;
	case 8977ULL: goto x86_l_2311;
	case 8981ULL: goto x86_l_2315;
	case 8984ULL: goto x86_l_2318;
	case 8988ULL: goto x86_l_231c;
	case 8994ULL: goto x86_l_2322;
	case 9001ULL: goto x86_l_2329;
	case 9006ULL: goto x86_l_232e;
	case 9010ULL: goto x86_l_2332;
	case 9013ULL: goto x86_l_2335;
	case 9017ULL: goto x86_l_2339;
	case 9023ULL: goto x86_l_233f;
	case 9030ULL: goto x86_l_2346;
	case 9035ULL: goto x86_l_234b;
	case 9039ULL: goto x86_l_234f;
	case 9042ULL: goto x86_l_2352;
	case 9046ULL: goto x86_l_2356;
	case 9052ULL: goto x86_l_235c;
	case 9059ULL: goto x86_l_2363;
	case 9064ULL: goto x86_l_2368;
	case 9068ULL: goto x86_l_236c;
	case 9071ULL: goto x86_l_236f;
	case 9075ULL: goto x86_l_2373;
	case 9081ULL: goto x86_l_2379;
	case 9088ULL: goto x86_l_2380;
	case 9093ULL: goto x86_l_2385;
	case 9097ULL: goto x86_l_2389;
	case 9100ULL: goto x86_l_238c;
	case 9104ULL: goto x86_l_2390;
	case 9110ULL: goto x86_l_2396;
	case 9117ULL: goto x86_l_239d;
	case 9122ULL: goto x86_l_23a2;
	case 9126ULL: goto x86_l_23a6;
	case 9129ULL: goto x86_l_23a9;
	case 9133ULL: goto x86_l_23ad;
	case 9139ULL: goto x86_l_23b3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c7a:
	/* 0x1c7a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1c7f:
	/* 0x1c7f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1c83:
	/* 0x1c83: mov    BYTE PTR [rsi+0x5],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_1c86:
	/* 0x1c86: cmp    r13,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 2ULL);
x86_l_1c8a:
	/* 0x1c8a: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1c90:
	/* 0x1c90: lea    eax,[r13+0xffd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4093ULL);
x86_l_1c97:
	/* 0x1c97: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1c9c:
	/* 0x1c9c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ca0:
	/* 0x1ca0: mov    BYTE PTR [rsi+0x6],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1ca3:
	/* 0x1ca3: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_1ca7:
	/* 0x1ca7: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1cad:
	/* 0x1cad: lea    eax,[r13+0xffc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4092ULL);
x86_l_1cb4:
	/* 0x1cb4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1cb9:
	/* 0x1cb9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1cbd:
	/* 0x1cbd: mov    BYTE PTR [rsi+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_1cc0:
	/* 0x1cc0: cmp    r13,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4ULL);
x86_l_1cc4:
	/* 0x1cc4: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1cca:
	/* 0x1cca: lea    eax,[r13+0xffb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4091ULL);
x86_l_1cd1:
	/* 0x1cd1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1cd6:
	/* 0x1cd6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1cda:
	/* 0x1cda: mov    BYTE PTR [rsi+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cdd:
	/* 0x1cdd: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_1ce1:
	/* 0x1ce1: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1ce7:
	/* 0x1ce7: lea    eax,[r13+0xffa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4090ULL);
x86_l_1cee:
	/* 0x1cee: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1cf3:
	/* 0x1cf3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1cf7:
	/* 0x1cf7: mov    BYTE PTR [rsi+0x9],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_1cfa:
	/* 0x1cfa: cmp    r13,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 6ULL);
x86_l_1cfe:
	/* 0x1cfe: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1d04:
	/* 0x1d04: lea    eax,[r13+0xff9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4089ULL);
x86_l_1d0b:
	/* 0x1d0b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d10:
	/* 0x1d10: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d14:
	/* 0x1d14: mov    BYTE PTR [rsi+0xa],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_1d17:
	/* 0x1d17: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_1d1b:
	/* 0x1d1b: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1d21:
	/* 0x1d21: lea    eax,[r13+0xff8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4088ULL);
x86_l_1d28:
	/* 0x1d28: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d2d:
	/* 0x1d2d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d31:
	/* 0x1d31: mov    BYTE PTR [rsi+0xb],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_1d34:
	/* 0x1d34: cmp    r13,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 8ULL);
x86_l_1d38:
	/* 0x1d38: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1d3e:
	/* 0x1d3e: lea    eax,[r13+0xff7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4087ULL);
x86_l_1d45:
	/* 0x1d45: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d4a:
	/* 0x1d4a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d4e:
	/* 0x1d4e: mov    BYTE PTR [rsi+0xc],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d51:
	/* 0x1d51: cmp    r13,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 9ULL);
x86_l_1d55:
	/* 0x1d55: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1d5b:
	/* 0x1d5b: lea    eax,[r13+0xff6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_1d62:
	/* 0x1d62: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d67:
	/* 0x1d67: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d6b:
	/* 0x1d6b: mov    BYTE PTR [rsi+0xd],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_1d6e:
	/* 0x1d6e: cmp    r13,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 10ULL);
x86_l_1d72:
	/* 0x1d72: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1d78:
	/* 0x1d78: lea    eax,[r13+0xff5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4085ULL);
x86_l_1d7f:
	/* 0x1d7f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d84:
	/* 0x1d84: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1d88:
	/* 0x1d88: mov    BYTE PTR [rsi+0xe],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_1d8b:
	/* 0x1d8b: cmp    r13,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 11ULL);
x86_l_1d8f:
	/* 0x1d8f: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1d95:
	/* 0x1d95: lea    eax,[r13+0xff4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4084ULL);
x86_l_1d9c:
	/* 0x1d9c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1da1:
	/* 0x1da1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1da5:
	/* 0x1da5: mov    BYTE PTR [rsi+0xf],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_1da8:
	/* 0x1da8: cmp    r13,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 12ULL);
x86_l_1dac:
	/* 0x1dac: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1db2:
	/* 0x1db2: lea    eax,[r13+0xff3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4083ULL);
x86_l_1db9:
	/* 0x1db9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1dbe:
	/* 0x1dbe: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1dc2:
	/* 0x1dc2: mov    BYTE PTR [rsi+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dc5:
	/* 0x1dc5: cmp    r13,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 13ULL);
x86_l_1dc9:
	/* 0x1dc9: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1dcf:
	/* 0x1dcf: lea    eax,[r13+0xff2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4082ULL);
x86_l_1dd6:
	/* 0x1dd6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ddb:
	/* 0x1ddb: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ddf:
	/* 0x1ddf: mov    BYTE PTR [rsi+0x11],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_1de2:
	/* 0x1de2: cmp    r13,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 14ULL);
x86_l_1de6:
	/* 0x1de6: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1dec:
	/* 0x1dec: lea    eax,[r13+0xff1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4081ULL);
x86_l_1df3:
	/* 0x1df3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1df8:
	/* 0x1df8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1dfc:
	/* 0x1dfc: mov    BYTE PTR [rsi+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1dff:
	/* 0x1dff: cmp    r13,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 15ULL);
x86_l_1e03:
	/* 0x1e03: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1e09:
	/* 0x1e09: lea    eax,[r13+0xff0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4080ULL);
x86_l_1e10:
	/* 0x1e10: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e15:
	/* 0x1e15: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e19:
	/* 0x1e19: mov    BYTE PTR [rsi+0x13],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 19ULL);
x86_l_1e1c:
	/* 0x1e1c: cmp    r13,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 16ULL);
x86_l_1e20:
	/* 0x1e20: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1e26:
	/* 0x1e26: lea    eax,[r13+0xfef] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4079ULL);
x86_l_1e2d:
	/* 0x1e2d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e32:
	/* 0x1e32: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e36:
	/* 0x1e36: mov    BYTE PTR [rsi+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1e39:
	/* 0x1e39: cmp    r13,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 17ULL);
x86_l_1e3d:
	/* 0x1e3d: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1e43:
	/* 0x1e43: lea    eax,[r13+0xfee] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4078ULL);
x86_l_1e4a:
	/* 0x1e4a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e4f:
	/* 0x1e4f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e53:
	/* 0x1e53: mov    BYTE PTR [rsi+0x15],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_1e56:
	/* 0x1e56: cmp    r13,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18ULL);
x86_l_1e5a:
	/* 0x1e5a: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1e60:
	/* 0x1e60: lea    eax,[r13+0xfed] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4077ULL);
x86_l_1e67:
	/* 0x1e67: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e6c:
	/* 0x1e6c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e70:
	/* 0x1e70: mov    BYTE PTR [rsi+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_1e73:
	/* 0x1e73: cmp    r13,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 19ULL);
x86_l_1e77:
	/* 0x1e77: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1e7d:
	/* 0x1e7d: lea    eax,[r13+0xfec] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4076ULL);
x86_l_1e84:
	/* 0x1e84: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1e89:
	/* 0x1e89: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1e8d:
	/* 0x1e8d: mov    BYTE PTR [rsi+0x17],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_1e90:
	/* 0x1e90: cmp    r13,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 20ULL);
x86_l_1e94:
	/* 0x1e94: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1e9a:
	/* 0x1e9a: lea    eax,[r13+0xfeb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4075ULL);
x86_l_1ea1:
	/* 0x1ea1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ea6:
	/* 0x1ea6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1eaa:
	/* 0x1eaa: mov    BYTE PTR [rsi+0x18],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ead:
	/* 0x1ead: cmp    r13,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 21ULL);
x86_l_1eb1:
	/* 0x1eb1: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1eb7:
	/* 0x1eb7: lea    eax,[r13+0xfea] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4074ULL);
x86_l_1ebe:
	/* 0x1ebe: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ec3:
	/* 0x1ec3: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ec7:
	/* 0x1ec7: mov    BYTE PTR [rsi+0x19],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_1eca:
	/* 0x1eca: cmp    r13,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 22ULL);
x86_l_1ece:
	/* 0x1ece: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1ed4:
	/* 0x1ed4: lea    eax,[r13+0xfe9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4073ULL);
x86_l_1edb:
	/* 0x1edb: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ee0:
	/* 0x1ee0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1ee4:
	/* 0x1ee4: mov    BYTE PTR [rsi+0x1a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_1ee7:
	/* 0x1ee7: cmp    r13,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 23ULL);
x86_l_1eeb:
	/* 0x1eeb: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1ef1:
	/* 0x1ef1: lea    eax,[r13+0xfe8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4072ULL);
x86_l_1ef8:
	/* 0x1ef8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1efd:
	/* 0x1efd: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f01:
	/* 0x1f01: mov    BYTE PTR [rsi+0x1b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 27ULL);
x86_l_1f04:
	/* 0x1f04: cmp    r13,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 24ULL);
x86_l_1f08:
	/* 0x1f08: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1f0e:
	/* 0x1f0e: lea    eax,[r13+0xfe7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4071ULL);
x86_l_1f15:
	/* 0x1f15: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f1a:
	/* 0x1f1a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f1e:
	/* 0x1f1e: mov    BYTE PTR [rsi+0x1c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1f21:
	/* 0x1f21: cmp    r13,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 25ULL);
x86_l_1f25:
	/* 0x1f25: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1f2b:
	/* 0x1f2b: lea    eax,[r13+0xfe6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4070ULL);
x86_l_1f32:
	/* 0x1f32: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f37:
	/* 0x1f37: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f3b:
	/* 0x1f3b: mov    BYTE PTR [rsi+0x1d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_1f3e:
	/* 0x1f3e: cmp    r13,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 26ULL);
x86_l_1f42:
	/* 0x1f42: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1f48:
	/* 0x1f48: lea    eax,[r13+0xfe5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4069ULL);
x86_l_1f4f:
	/* 0x1f4f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f54:
	/* 0x1f54: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f58:
	/* 0x1f58: mov    BYTE PTR [rsi+0x1e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_1f5b:
	/* 0x1f5b: cmp    r13,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 27ULL);
x86_l_1f5f:
	/* 0x1f5f: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1f65:
	/* 0x1f65: lea    eax,[r13+0xfe4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4068ULL);
x86_l_1f6c:
	/* 0x1f6c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f71:
	/* 0x1f71: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f75:
	/* 0x1f75: mov    BYTE PTR [rsi+0x1f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_1f78:
	/* 0x1f78: cmp    r13,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 28ULL);
x86_l_1f7c:
	/* 0x1f7c: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1f82:
	/* 0x1f82: lea    eax,[r13+0xfe3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4067ULL);
x86_l_1f89:
	/* 0x1f89: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f8e:
	/* 0x1f8e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1f92:
	/* 0x1f92: mov    BYTE PTR [rsi+0x20],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f95:
	/* 0x1f95: cmp    r13,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 29ULL);
x86_l_1f99:
	/* 0x1f99: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1f9f:
	/* 0x1f9f: lea    eax,[r13+0xfe2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4066ULL);
x86_l_1fa6:
	/* 0x1fa6: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1fab:
	/* 0x1fab: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1faf:
	/* 0x1faf: mov    BYTE PTR [rsi+0x21],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 33ULL);
x86_l_1fb2:
	/* 0x1fb2: cmp    r13,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 30ULL);
x86_l_1fb6:
	/* 0x1fb6: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1fbc:
	/* 0x1fbc: lea    eax,[r13+0xfe1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4065ULL);
x86_l_1fc3:
	/* 0x1fc3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1fc8:
	/* 0x1fc8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1fcc:
	/* 0x1fcc: mov    BYTE PTR [rsi+0x22],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_1fcf:
	/* 0x1fcf: cmp    r13,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 31ULL);
x86_l_1fd3:
	/* 0x1fd3: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1fd9:
	/* 0x1fd9: lea    eax,[r13+0xfe0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4064ULL);
x86_l_1fe0:
	/* 0x1fe0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1fe5:
	/* 0x1fe5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_1fe9:
	/* 0x1fe9: mov    BYTE PTR [rsi+0x23],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_1fec:
	/* 0x1fec: cmp    r13,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 32ULL);
x86_l_1ff0:
	/* 0x1ff0: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_1ff6:
	/* 0x1ff6: lea    eax,[r13+0xfdf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4063ULL);
x86_l_1ffd:
	/* 0x1ffd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2002:
	/* 0x2002: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2006:
	/* 0x2006: mov    BYTE PTR [rsi+0x24],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2009:
	/* 0x2009: cmp    r13,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 33ULL);
x86_l_200d:
	/* 0x200d: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_2013:
	/* 0x2013: lea    eax,[r13+0xfde] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4062ULL);
x86_l_201a:
	/* 0x201a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_201f:
	/* 0x201f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2023:
	/* 0x2023: mov    BYTE PTR [rsi+0x25],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_2026:
	/* 0x2026: cmp    r13,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 34ULL);
x86_l_202a:
	/* 0x202a: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_2030:
	/* 0x2030: lea    eax,[r13+0xfdd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4061ULL);
x86_l_2037:
	/* 0x2037: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_203c:
	/* 0x203c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2040:
	/* 0x2040: mov    BYTE PTR [rsi+0x26],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_2043:
	/* 0x2043: cmp    r13,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 35ULL);
x86_l_2047:
	/* 0x2047: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_204d:
	/* 0x204d: lea    eax,[r13+0xfdc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4060ULL);
x86_l_2054:
	/* 0x2054: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2059:
	/* 0x2059: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_205d:
	/* 0x205d: mov    BYTE PTR [rsi+0x27],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_2060:
	/* 0x2060: cmp    r13,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 36ULL);
x86_l_2064:
	/* 0x2064: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_206a:
	/* 0x206a: lea    eax,[r13+0xfdb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4059ULL);
x86_l_2071:
	/* 0x2071: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2076:
	/* 0x2076: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_207a:
	/* 0x207a: mov    BYTE PTR [rsi+0x28],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_207d:
	/* 0x207d: cmp    r13,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 37ULL);
x86_l_2081:
	/* 0x2081: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_2087:
	/* 0x2087: lea    eax,[r13+0xfda] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4058ULL);
x86_l_208e:
	/* 0x208e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2093:
	/* 0x2093: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2097:
	/* 0x2097: mov    BYTE PTR [rsi+0x29],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_209a:
	/* 0x209a: cmp    r13,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 38ULL);
x86_l_209e:
	/* 0x209e: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_20a4:
	/* 0x20a4: lea    eax,[r13+0xfd9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4057ULL);
x86_l_20ab:
	/* 0x20ab: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20b0:
	/* 0x20b0: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_20b4:
	/* 0x20b4: mov    BYTE PTR [rsi+0x2a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_20b7:
	/* 0x20b7: cmp    r13,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 39ULL);
x86_l_20bb:
	/* 0x20bb: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_20c1:
	/* 0x20c1: lea    eax,[r13+0xfd8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4056ULL);
x86_l_20c8:
	/* 0x20c8: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20cd:
	/* 0x20cd: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_20d1:
	/* 0x20d1: mov    BYTE PTR [rsi+0x2b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_20d4:
	/* 0x20d4: cmp    r13,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 40ULL);
x86_l_20d8:
	/* 0x20d8: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_20de:
	/* 0x20de: lea    eax,[r13+0xfd7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4055ULL);
x86_l_20e5:
	/* 0x20e5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20ea:
	/* 0x20ea: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_20ee:
	/* 0x20ee: mov    BYTE PTR [rsi+0x2c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_20f1:
	/* 0x20f1: cmp    r13,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 41ULL);
x86_l_20f5:
	/* 0x20f5: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_20fb:
	/* 0x20fb: lea    eax,[r13+0xfd6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4054ULL);
x86_l_2102:
	/* 0x2102: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2107:
	/* 0x2107: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_210b:
	/* 0x210b: mov    BYTE PTR [rsi+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_210e:
	/* 0x210e: cmp    r13,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 42ULL);
x86_l_2112:
	/* 0x2112: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_2118:
	/* 0x2118: lea    eax,[r13+0xfd5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4053ULL);
x86_l_211f:
	/* 0x211f: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2124:
	/* 0x2124: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2128:
	/* 0x2128: mov    BYTE PTR [rsi+0x2e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_212b:
	/* 0x212b: cmp    r13,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 43ULL);
x86_l_212f:
	/* 0x212f: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_2135:
	/* 0x2135: lea    eax,[r13+0xfd4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4052ULL);
x86_l_213c:
	/* 0x213c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2141:
	/* 0x2141: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2145:
	/* 0x2145: mov    BYTE PTR [rsi+0x2f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_2148:
	/* 0x2148: cmp    r13,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 44ULL);
x86_l_214c:
	/* 0x214c: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_2152:
	/* 0x2152: lea    eax,[r13+0xfd3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4051ULL);
x86_l_2159:
	/* 0x2159: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_215e:
	/* 0x215e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2162:
	/* 0x2162: mov    BYTE PTR [rsi+0x30],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2165:
	/* 0x2165: cmp    r13,0x2d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 45ULL);
x86_l_2169:
	/* 0x2169: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_216f:
	/* 0x216f: lea    eax,[r13+0xfd2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4050ULL);
x86_l_2176:
	/* 0x2176: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_217b:
	/* 0x217b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_217f:
	/* 0x217f: mov    BYTE PTR [rsi+0x31],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 49ULL);
x86_l_2182:
	/* 0x2182: cmp    r13,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 46ULL);
x86_l_2186:
	/* 0x2186: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_218c:
	/* 0x218c: lea    eax,[r13+0xfd1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4049ULL);
x86_l_2193:
	/* 0x2193: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2198:
	/* 0x2198: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_219c:
	/* 0x219c: mov    BYTE PTR [rsi+0x32],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_219f:
	/* 0x219f: cmp    r13,0x2f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 47ULL);
x86_l_21a3:
	/* 0x21a3: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_21a9:
	/* 0x21a9: lea    eax,[r13+0xfd0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4048ULL);
x86_l_21b0:
	/* 0x21b0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21b5:
	/* 0x21b5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_21b9:
	/* 0x21b9: mov    BYTE PTR [rsi+0x33],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_21bc:
	/* 0x21bc: cmp    r13,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 48ULL);
x86_l_21c0:
	/* 0x21c0: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_21c6:
	/* 0x21c6: lea    eax,[r13+0xfcf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4047ULL);
x86_l_21cd:
	/* 0x21cd: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21d2:
	/* 0x21d2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_21d6:
	/* 0x21d6: mov    BYTE PTR [rsi+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_21d9:
	/* 0x21d9: cmp    r13,0x31 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 49ULL);
x86_l_21dd:
	/* 0x21dd: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_21e3:
	/* 0x21e3: lea    eax,[r13+0xfce] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4046ULL);
x86_l_21ea:
	/* 0x21ea: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_21ef:
	/* 0x21ef: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_21f3:
	/* 0x21f3: mov    BYTE PTR [rsi+0x35],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_21f6:
	/* 0x21f6: cmp    r13,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 50ULL);
x86_l_21fa:
	/* 0x21fa: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_2200:
	/* 0x2200: lea    eax,[r13+0xfcd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4045ULL);
x86_l_2207:
	/* 0x2207: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_220c:
	/* 0x220c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2210:
	/* 0x2210: mov    BYTE PTR [rsi+0x36],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_2213:
	/* 0x2213: cmp    r13,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 51ULL);
x86_l_2217:
	/* 0x2217: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_221d:
	/* 0x221d: lea    eax,[r13+0xfcc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4044ULL);
x86_l_2224:
	/* 0x2224: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2229:
	/* 0x2229: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_222d:
	/* 0x222d: mov    BYTE PTR [rsi+0x37],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_2230:
	/* 0x2230: cmp    r13,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 52ULL);
x86_l_2234:
	/* 0x2234: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_223a:
	/* 0x223a: lea    eax,[r13+0xfcb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4043ULL);
x86_l_2241:
	/* 0x2241: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2246:
	/* 0x2246: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_224a:
	/* 0x224a: mov    BYTE PTR [rsi+0x38],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_224d:
	/* 0x224d: cmp    r13,0x35 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 53ULL);
x86_l_2251:
	/* 0x2251: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_2257:
	/* 0x2257: lea    eax,[r13+0xfca] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4042ULL);
x86_l_225e:
	/* 0x225e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2263:
	/* 0x2263: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2267:
	/* 0x2267: mov    BYTE PTR [rsi+0x39],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 57ULL);
x86_l_226a:
	/* 0x226a: cmp    r13,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 54ULL);
x86_l_226e:
	/* 0x226e: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_2274:
	/* 0x2274: lea    eax,[r13+0xfc9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4041ULL);
x86_l_227b:
	/* 0x227b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2280:
	/* 0x2280: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2284:
	/* 0x2284: mov    BYTE PTR [rsi+0x3a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_2287:
	/* 0x2287: cmp    r13,0x37 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 55ULL);
x86_l_228b:
	/* 0x228b: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_2291:
	/* 0x2291: lea    eax,[r13+0xfc8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4040ULL);
x86_l_2298:
	/* 0x2298: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_229d:
	/* 0x229d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_22a1:
	/* 0x22a1: mov    BYTE PTR [rsi+0x3b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_22a4:
	/* 0x22a4: cmp    r13,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 56ULL);
x86_l_22a8:
	/* 0x22a8: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_22ae:
	/* 0x22ae: lea    eax,[r13+0xfc7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4039ULL);
x86_l_22b5:
	/* 0x22b5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22ba:
	/* 0x22ba: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_22be:
	/* 0x22be: mov    BYTE PTR [rsi+0x3c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_22c1:
	/* 0x22c1: cmp    r13,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 57ULL);
x86_l_22c5:
	/* 0x22c5: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_22cb:
	/* 0x22cb: lea    eax,[r13+0xfc6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4038ULL);
x86_l_22d2:
	/* 0x22d2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22d7:
	/* 0x22d7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_22db:
	/* 0x22db: mov    BYTE PTR [rsi+0x3d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_22de:
	/* 0x22de: cmp    r13,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 58ULL);
x86_l_22e2:
	/* 0x22e2: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_22e8:
	/* 0x22e8: lea    eax,[r13+0xfc5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4037ULL);
x86_l_22ef:
	/* 0x22ef: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22f4:
	/* 0x22f4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_22f8:
	/* 0x22f8: mov    BYTE PTR [rsi+0x3e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_22fb:
	/* 0x22fb: cmp    r13,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 59ULL);
x86_l_22ff:
	/* 0x22ff: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_2305:
	/* 0x2305: lea    eax,[r13+0xfc4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4036ULL);
x86_l_230c:
	/* 0x230c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2311:
	/* 0x2311: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2315:
	/* 0x2315: mov    BYTE PTR [rsi+0x3f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 63ULL);
x86_l_2318:
	/* 0x2318: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_231c:
	/* 0x231c: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_2322:
	/* 0x2322: lea    eax,[r13+0xfc3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4035ULL);
x86_l_2329:
	/* 0x2329: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_232e:
	/* 0x232e: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2332:
	/* 0x2332: mov    BYTE PTR [rsi+0x40],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2335:
	/* 0x2335: cmp    r13,0x3d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 61ULL);
x86_l_2339:
	/* 0x2339: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_233f:
	/* 0x233f: lea    eax,[r13+0xfc2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4034ULL);
x86_l_2346:
	/* 0x2346: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_234b:
	/* 0x234b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_234f:
	/* 0x234f: mov    BYTE PTR [rsi+0x41],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_2352:
	/* 0x2352: cmp    r13,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 62ULL);
x86_l_2356:
	/* 0x2356: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_235c:
	/* 0x235c: lea    eax,[r13+0xfc1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4033ULL);
x86_l_2363:
	/* 0x2363: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2368:
	/* 0x2368: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_236c:
	/* 0x236c: mov    BYTE PTR [rsi+0x42],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_236f:
	/* 0x236f: cmp    r13,0x3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 63ULL);
x86_l_2373:
	/* 0x2373: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_2379:
	/* 0x2379: lea    eax,[r13+0xfc0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4032ULL);
x86_l_2380:
	/* 0x2380: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2385:
	/* 0x2385: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2389:
	/* 0x2389: mov    BYTE PTR [rsi+0x43],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 67ULL);
x86_l_238c:
	/* 0x238c: cmp    r13,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 64ULL);
x86_l_2390:
	/* 0x2390: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_2396:
	/* 0x2396: lea    eax,[r13+0xfbf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4031ULL);
x86_l_239d:
	/* 0x239d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23a2:
	/* 0x23a2: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_23a6:
	/* 0x23a6: mov    BYTE PTR [rsi+0x44],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_23a9:
	/* 0x23a9: cmp    r13,0x41 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 65ULL);
x86_l_23ad:
	/* 0x23ad: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9951ULL;
	}
x86_l_23b3:
	/* 0x23b3: lea    eax,[r13+0xfbe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4030ULL);
	return 9146ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9146ULL: goto x86_l_23ba;
	case 9151ULL: goto x86_l_23bf;
	case 9155ULL: goto x86_l_23c3;
	case 9158ULL: goto x86_l_23c6;
	case 9162ULL: goto x86_l_23ca;
	case 9168ULL: goto x86_l_23d0;
	case 9175ULL: goto x86_l_23d7;
	case 9180ULL: goto x86_l_23dc;
	case 9184ULL: goto x86_l_23e0;
	case 9187ULL: goto x86_l_23e3;
	case 9191ULL: goto x86_l_23e7;
	case 9197ULL: goto x86_l_23ed;
	case 9204ULL: goto x86_l_23f4;
	case 9209ULL: goto x86_l_23f9;
	case 9213ULL: goto x86_l_23fd;
	case 9216ULL: goto x86_l_2400;
	case 9220ULL: goto x86_l_2404;
	case 9226ULL: goto x86_l_240a;
	case 9233ULL: goto x86_l_2411;
	case 9238ULL: goto x86_l_2416;
	case 9242ULL: goto x86_l_241a;
	case 9245ULL: goto x86_l_241d;
	case 9249ULL: goto x86_l_2421;
	case 9255ULL: goto x86_l_2427;
	case 9262ULL: goto x86_l_242e;
	case 9267ULL: goto x86_l_2433;
	case 9271ULL: goto x86_l_2437;
	case 9274ULL: goto x86_l_243a;
	case 9278ULL: goto x86_l_243e;
	case 9284ULL: goto x86_l_2444;
	case 9291ULL: goto x86_l_244b;
	case 9296ULL: goto x86_l_2450;
	case 9300ULL: goto x86_l_2454;
	case 9303ULL: goto x86_l_2457;
	case 9307ULL: goto x86_l_245b;
	case 9313ULL: goto x86_l_2461;
	case 9320ULL: goto x86_l_2468;
	case 9325ULL: goto x86_l_246d;
	case 9329ULL: goto x86_l_2471;
	case 9332ULL: goto x86_l_2474;
	case 9336ULL: goto x86_l_2478;
	case 9342ULL: goto x86_l_247e;
	case 9349ULL: goto x86_l_2485;
	case 9354ULL: goto x86_l_248a;
	case 9358ULL: goto x86_l_248e;
	case 9361ULL: goto x86_l_2491;
	case 9365ULL: goto x86_l_2495;
	case 9371ULL: goto x86_l_249b;
	case 9378ULL: goto x86_l_24a2;
	case 9383ULL: goto x86_l_24a7;
	case 9387ULL: goto x86_l_24ab;
	case 9390ULL: goto x86_l_24ae;
	case 9394ULL: goto x86_l_24b2;
	case 9400ULL: goto x86_l_24b8;
	case 9407ULL: goto x86_l_24bf;
	case 9412ULL: goto x86_l_24c4;
	case 9416ULL: goto x86_l_24c8;
	case 9419ULL: goto x86_l_24cb;
	case 9423ULL: goto x86_l_24cf;
	case 9429ULL: goto x86_l_24d5;
	case 9436ULL: goto x86_l_24dc;
	case 9441ULL: goto x86_l_24e1;
	case 9445ULL: goto x86_l_24e5;
	case 9448ULL: goto x86_l_24e8;
	case 9452ULL: goto x86_l_24ec;
	case 9458ULL: goto x86_l_24f2;
	case 9465ULL: goto x86_l_24f9;
	case 9470ULL: goto x86_l_24fe;
	case 9474ULL: goto x86_l_2502;
	case 9477ULL: goto x86_l_2505;
	case 9481ULL: goto x86_l_2509;
	case 9487ULL: goto x86_l_250f;
	case 9494ULL: goto x86_l_2516;
	case 9499ULL: goto x86_l_251b;
	case 9503ULL: goto x86_l_251f;
	case 9506ULL: goto x86_l_2522;
	case 9510ULL: goto x86_l_2526;
	case 9516ULL: goto x86_l_252c;
	case 9523ULL: goto x86_l_2533;
	case 9528ULL: goto x86_l_2538;
	case 9532ULL: goto x86_l_253c;
	case 9535ULL: goto x86_l_253f;
	case 9539ULL: goto x86_l_2543;
	case 9545ULL: goto x86_l_2549;
	case 9552ULL: goto x86_l_2550;
	case 9557ULL: goto x86_l_2555;
	case 9561ULL: goto x86_l_2559;
	case 9564ULL: goto x86_l_255c;
	case 9568ULL: goto x86_l_2560;
	case 9574ULL: goto x86_l_2566;
	case 9581ULL: goto x86_l_256d;
	case 9586ULL: goto x86_l_2572;
	case 9590ULL: goto x86_l_2576;
	case 9593ULL: goto x86_l_2579;
	case 9597ULL: goto x86_l_257d;
	case 9603ULL: goto x86_l_2583;
	case 9610ULL: goto x86_l_258a;
	case 9615ULL: goto x86_l_258f;
	case 9619ULL: goto x86_l_2593;
	case 9622ULL: goto x86_l_2596;
	case 9626ULL: goto x86_l_259a;
	case 9632ULL: goto x86_l_25a0;
	case 9639ULL: goto x86_l_25a7;
	case 9644ULL: goto x86_l_25ac;
	case 9648ULL: goto x86_l_25b0;
	case 9651ULL: goto x86_l_25b3;
	case 9655ULL: goto x86_l_25b7;
	case 9661ULL: goto x86_l_25bd;
	case 9668ULL: goto x86_l_25c4;
	case 9673ULL: goto x86_l_25c9;
	case 9677ULL: goto x86_l_25cd;
	case 9680ULL: goto x86_l_25d0;
	case 9684ULL: goto x86_l_25d4;
	case 9690ULL: goto x86_l_25da;
	case 9697ULL: goto x86_l_25e1;
	case 9702ULL: goto x86_l_25e6;
	case 9706ULL: goto x86_l_25ea;
	case 9709ULL: goto x86_l_25ed;
	case 9713ULL: goto x86_l_25f1;
	case 9719ULL: goto x86_l_25f7;
	case 9726ULL: goto x86_l_25fe;
	case 9731ULL: goto x86_l_2603;
	case 9735ULL: goto x86_l_2607;
	case 9738ULL: goto x86_l_260a;
	case 9742ULL: goto x86_l_260e;
	case 9748ULL: goto x86_l_2614;
	case 9755ULL: goto x86_l_261b;
	case 9760ULL: goto x86_l_2620;
	case 9764ULL: goto x86_l_2624;
	case 9767ULL: goto x86_l_2627;
	case 9771ULL: goto x86_l_262b;
	case 9777ULL: goto x86_l_2631;
	case 9784ULL: goto x86_l_2638;
	case 9789ULL: goto x86_l_263d;
	case 9793ULL: goto x86_l_2641;
	case 9796ULL: goto x86_l_2644;
	case 9800ULL: goto x86_l_2648;
	case 9806ULL: goto x86_l_264e;
	case 9813ULL: goto x86_l_2655;
	case 9818ULL: goto x86_l_265a;
	case 9822ULL: goto x86_l_265e;
	case 9825ULL: goto x86_l_2661;
	case 9829ULL: goto x86_l_2665;
	case 9831ULL: goto x86_l_2667;
	case 9838ULL: goto x86_l_266e;
	case 9843ULL: goto x86_l_2673;
	case 9847ULL: goto x86_l_2677;
	case 9850ULL: goto x86_l_267a;
	case 9854ULL: goto x86_l_267e;
	case 9856ULL: goto x86_l_2680;
	case 9863ULL: goto x86_l_2687;
	case 9868ULL: goto x86_l_268c;
	case 9872ULL: goto x86_l_2690;
	case 9875ULL: goto x86_l_2693;
	case 9879ULL: goto x86_l_2697;
	case 9881ULL: goto x86_l_2699;
	case 9888ULL: goto x86_l_26a0;
	case 9893ULL: goto x86_l_26a5;
	case 9897ULL: goto x86_l_26a9;
	case 9900ULL: goto x86_l_26ac;
	case 9904ULL: goto x86_l_26b0;
	case 9906ULL: goto x86_l_26b2;
	case 9909ULL: goto x86_l_26b5;
	case 9914ULL: goto x86_l_26ba;
	case 9919ULL: goto x86_l_26bf;
	case 9923ULL: goto x86_l_26c3;
	case 9926ULL: goto x86_l_26c6;
	case 9930ULL: goto x86_l_26ca;
	case 9932ULL: goto x86_l_26cc;
	case 9939ULL: goto x86_l_26d3;
	case 9944ULL: goto x86_l_26d8;
	case 9948ULL: goto x86_l_26dc;
	case 9951ULL: goto x86_l_26df;
	case 9956ULL: goto x86_l_26e4;
	case 9961ULL: goto x86_l_26e9;
	case 9966ULL: goto x86_l_26ee;
	case 9971ULL: goto x86_l_26f3;
	case 9975ULL: goto x86_l_26f7;
	case 9978ULL: goto x86_l_26fa;
	case 9982ULL: goto x86_l_26fe;
	case 9990ULL: goto x86_l_2706;
	case 9997ULL: goto x86_l_270d;
	case 10002ULL: goto x86_l_2712;
	case 10007ULL: goto x86_l_2717;
	case 10009ULL: goto x86_l_2719;
	case 10012ULL: goto x86_l_271c;
	case 10015ULL: goto x86_l_271f;
	case 10018ULL: goto x86_l_2722;
	case 10024ULL: goto x86_l_2728;
	case 10029ULL: goto x86_l_272d;
	case 10032ULL: goto x86_l_2730;
	case 10038ULL: goto x86_l_2736;
	case 10045ULL: goto x86_l_273d;
	case 10050ULL: goto x86_l_2742;
	case 10055ULL: goto x86_l_2747;
	case 10057ULL: goto x86_l_2749;
	case 10060ULL: goto x86_l_274c;
	case 10066ULL: goto x86_l_2752;
	case 10071ULL: goto x86_l_2757;
	case 10075ULL: goto x86_l_275b;
	case 10082ULL: goto x86_l_2762;
	case 10087ULL: goto x86_l_2767;
	case 10091ULL: goto x86_l_276b;
	case 10098ULL: goto x86_l_2772;
	case 10100ULL: goto x86_l_2774;
	case 10103ULL: goto x86_l_2777;
	case 10107ULL: goto x86_l_277b;
	case 10110ULL: goto x86_l_277e;
	case 10115ULL: goto x86_l_2783;
	case 10117ULL: goto x86_l_2785;
	case 10122ULL: goto x86_l_278a;
	case 10127ULL: goto x86_l_278f;
	case 10130ULL: goto x86_l_2792;
	case 10135ULL: goto x86_l_2797;
	case 10138ULL: goto x86_l_279a;
	case 10140ULL: goto x86_l_279c;
	case 10143ULL: goto x86_l_279f;
	case 10149ULL: goto x86_l_27a5;
	case 10154ULL: goto x86_l_27aa;
	case 10156ULL: goto x86_l_27ac;
	case 10161ULL: goto x86_l_27b1;
	case 10163ULL: goto x86_l_27b3;
	case 10166ULL: goto x86_l_27b6;
	case 10169ULL: goto x86_l_27b9;
	case 10171ULL: goto x86_l_27bb;
	case 10174ULL: goto x86_l_27be;
	case 10180ULL: goto x86_l_27c4;
	case 10183ULL: goto x86_l_27c7;
	case 10189ULL: goto x86_l_27cd;
	case 10192ULL: goto x86_l_27d0;
	case 10198ULL: goto x86_l_27d6;
	case 10201ULL: goto x86_l_27d9;
	case 10207ULL: goto x86_l_27df;
	case 10210ULL: goto x86_l_27e2;
	case 10215ULL: goto x86_l_27e7;
	case 10219ULL: goto x86_l_27eb;
	case 10223ULL: goto x86_l_27ef;
	case 10225ULL: goto x86_l_27f1;
	case 10228ULL: goto x86_l_27f4;
	case 10232ULL: goto x86_l_27f8;
	case 10235ULL: goto x86_l_27fb;
	case 10239ULL: goto x86_l_27ff;
	case 10241ULL: goto x86_l_2801;
	case 10244ULL: goto x86_l_2804;
	case 10247ULL: goto x86_l_2807;
	case 10249ULL: goto x86_l_2809;
	case 10252ULL: goto x86_l_280c;
	case 10255ULL: goto x86_l_280f;
	case 10257ULL: goto x86_l_2811;
	case 10260ULL: goto x86_l_2814;
	case 10263ULL: goto x86_l_2817;
	case 10269ULL: goto x86_l_281d;
	case 10272ULL: goto x86_l_2820;
	case 10278ULL: goto x86_l_2826;
	case 10283ULL: goto x86_l_282b;
	case 10286ULL: goto x86_l_282e;
	case 10288ULL: goto x86_l_2830;
	case 10293ULL: goto x86_l_2835;
	case 10296ULL: goto x86_l_2838;
	case 10302ULL: goto x86_l_283e;
	case 10307ULL: goto x86_l_2843;
	case 10310ULL: goto x86_l_2846;
	case 10316ULL: goto x86_l_284c;
	case 10321ULL: goto x86_l_2851;
	case 10324ULL: goto x86_l_2854;
	case 10326ULL: goto x86_l_2856;
	case 10331ULL: goto x86_l_285b;
	case 10334ULL: goto x86_l_285e;
	case 10340ULL: goto x86_l_2864;
	case 10343ULL: goto x86_l_2867;
	case 10349ULL: goto x86_l_286d;
	case 10352ULL: goto x86_l_2870;
	case 10355ULL: goto x86_l_2873;
	case 10358ULL: goto x86_l_2876;
	case 10362ULL: goto x86_l_287a;
	case 10369ULL: goto x86_l_2881;
	case 10374ULL: goto x86_l_2886;
	case 10379ULL: goto x86_l_288b;
	case 10381ULL: goto x86_l_288d;
	case 10384ULL: goto x86_l_2890;
	case 10390ULL: goto x86_l_2896;
	case 10393ULL: goto x86_l_2899;
	case 10401ULL: goto x86_l_28a1;
	case 10406ULL: goto x86_l_28a6;
	case 10411ULL: goto x86_l_28ab;
	case 10414ULL: goto x86_l_28ae;
	case 10417ULL: goto x86_l_28b1;
	case 10423ULL: goto x86_l_28b7;
	case 10426ULL: goto x86_l_28ba;
	case 10430ULL: goto x86_l_28be;
	case 10434ULL: goto x86_l_28c2;
	case 10441ULL: goto x86_l_28c9;
	case 10444ULL: goto x86_l_28cc;
	case 10449ULL: goto x86_l_28d1;
	case 10454ULL: goto x86_l_28d6;
	case 10456ULL: goto x86_l_28d8;
	case 10459ULL: goto x86_l_28db;
	case 10465ULL: goto x86_l_28e1;
	case 10468ULL: goto x86_l_28e4;
	case 10472ULL: goto x86_l_28e8;
	case 10477ULL: goto x86_l_28ed;
	case 10482ULL: goto x86_l_28f2;
	case 10487ULL: goto x86_l_28f7;
	case 10489ULL: goto x86_l_28f9;
	case 10494ULL: goto x86_l_28fe;
	case 10499ULL: goto x86_l_2903;
	case 10504ULL: goto x86_l_2908;
	case 10508ULL: goto x86_l_290c;
	case 10511ULL: goto x86_l_290f;
	case 10515ULL: goto x86_l_2913;
	case 10523ULL: goto x86_l_291b;
	case 10530ULL: goto x86_l_2922;
	case 10535ULL: goto x86_l_2927;
	case 10540ULL: goto x86_l_292c;
	case 10542ULL: goto x86_l_292e;
	case 10545ULL: goto x86_l_2931;
	case 10551ULL: goto x86_l_2937;
	case 10557ULL: goto x86_l_293d;
	case 10560ULL: goto x86_l_2940;
	case 10563ULL: goto x86_l_2943;
	case 10569ULL: goto x86_l_2949;
	case 10576ULL: goto x86_l_2950;
	case 10581ULL: goto x86_l_2955;
	case 10586ULL: goto x86_l_295a;
	case 10588ULL: goto x86_l_295c;
	case 10591ULL: goto x86_l_295f;
	case 10597ULL: goto x86_l_2965;
	case 10602ULL: goto x86_l_296a;
	case 10608ULL: goto x86_l_2970;
	case 10613ULL: goto x86_l_2975;
	case 10616ULL: goto x86_l_2978;
	case 10623ULL: goto x86_l_297f;
	case 10625ULL: goto x86_l_2981;
	case 10628ULL: goto x86_l_2984;
	case 10632ULL: goto x86_l_2988;
	case 10635ULL: goto x86_l_298b;
	case 10640ULL: goto x86_l_2990;
	case 10645ULL: goto x86_l_2995;
	case 10647ULL: goto x86_l_2997;
	case 10652ULL: goto x86_l_299c;
	case 10655ULL: goto x86_l_299f;
	case 10658ULL: goto x86_l_29a2;
	case 10663ULL: goto x86_l_29a7;
	case 10671ULL: goto x86_l_29af;
	case 10677ULL: goto x86_l_29b5;
	case 10683ULL: goto x86_l_29bb;
	case 10688ULL: goto x86_l_29c0;
	case 10692ULL: goto x86_l_29c4;
	case 10695ULL: goto x86_l_29c7;
	case 10701ULL: goto x86_l_29cd;
	case 10704ULL: goto x86_l_29d0;
	case 10707ULL: goto x86_l_29d3;
	case 10710ULL: goto x86_l_29d6;
	case 10712ULL: goto x86_l_29d8;
	case 10714ULL: goto x86_l_29da;
	case 10717ULL: goto x86_l_29dd;
	case 10723ULL: goto x86_l_29e3;
	case 10725ULL: goto x86_l_29e5;
	case 10731ULL: goto x86_l_29eb;
	case 10736ULL: goto x86_l_29f0;
	case 10739ULL: goto x86_l_29f3;
	case 10742ULL: goto x86_l_29f6;
	case 10747ULL: goto x86_l_29fb;
	case 10751ULL: goto x86_l_29ff;
	case 10756ULL: goto x86_l_2a04;
	case 10759ULL: goto x86_l_2a07;
	case 10762ULL: goto x86_l_2a0a;
	case 10767ULL: goto x86_l_2a0f;
	case 10771ULL: goto x86_l_2a13;
	case 10776ULL: goto x86_l_2a18;
	case 10781ULL: goto x86_l_2a1d;
	case 10785ULL: goto x86_l_2a21;
	case 10788ULL: goto x86_l_2a24;
	case 10791ULL: goto x86_l_2a27;
	case 10795ULL: goto x86_l_2a2b;
	case 10802ULL: goto x86_l_2a32;
	case 10807ULL: goto x86_l_2a37;
	case 10812ULL: goto x86_l_2a3c;
	case 10814ULL: goto x86_l_2a3e;
	case 10817ULL: goto x86_l_2a41;
	case 10823ULL: goto x86_l_2a47;
	case 10826ULL: goto x86_l_2a4a;
	case 10834ULL: goto x86_l_2a52;
	case 10838ULL: goto x86_l_2a56;
	default: return 0xffffffffffffffffULL;
	}
x86_l_23ba:
	/* 0x23ba: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23bf:
	/* 0x23bf: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_23c3:
	/* 0x23c3: mov    BYTE PTR [rsi+0x45],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 69ULL);
x86_l_23c6:
	/* 0x23c6: cmp    r13,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 66ULL);
x86_l_23ca:
	/* 0x23ca: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_23d0:
	/* 0x23d0: lea    eax,[r13+0xfbd] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4029ULL);
x86_l_23d7:
	/* 0x23d7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23dc:
	/* 0x23dc: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_23e0:
	/* 0x23e0: mov    BYTE PTR [rsi+0x46],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_23e3:
	/* 0x23e3: cmp    r13,0x43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 67ULL);
x86_l_23e7:
	/* 0x23e7: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_23ed:
	/* 0x23ed: lea    eax,[r13+0xfbc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4028ULL);
x86_l_23f4:
	/* 0x23f4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23f9:
	/* 0x23f9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_23fd:
	/* 0x23fd: mov    BYTE PTR [rsi+0x47],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_2400:
	/* 0x2400: cmp    r13,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 68ULL);
x86_l_2404:
	/* 0x2404: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_240a:
	/* 0x240a: lea    eax,[r13+0xfbb] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4027ULL);
x86_l_2411:
	/* 0x2411: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2416:
	/* 0x2416: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_241a:
	/* 0x241a: mov    BYTE PTR [rsi+0x48],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_241d:
	/* 0x241d: cmp    r13,0x45 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 69ULL);
x86_l_2421:
	/* 0x2421: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_2427:
	/* 0x2427: lea    eax,[r13+0xfba] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4026ULL);
x86_l_242e:
	/* 0x242e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2433:
	/* 0x2433: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2437:
	/* 0x2437: mov    BYTE PTR [rsi+0x49],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 73ULL);
x86_l_243a:
	/* 0x243a: cmp    r13,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 70ULL);
x86_l_243e:
	/* 0x243e: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_2444:
	/* 0x2444: lea    eax,[r13+0xfb9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4025ULL);
x86_l_244b:
	/* 0x244b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2450:
	/* 0x2450: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2454:
	/* 0x2454: mov    BYTE PTR [rsi+0x4a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_2457:
	/* 0x2457: cmp    r13,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 71ULL);
x86_l_245b:
	/* 0x245b: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_2461:
	/* 0x2461: lea    eax,[r13+0xfb8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4024ULL);
x86_l_2468:
	/* 0x2468: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_246d:
	/* 0x246d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2471:
	/* 0x2471: mov    BYTE PTR [rsi+0x4b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_2474:
	/* 0x2474: cmp    r13,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 72ULL);
x86_l_2478:
	/* 0x2478: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_247e:
	/* 0x247e: lea    eax,[r13+0xfb7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4023ULL);
x86_l_2485:
	/* 0x2485: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_248a:
	/* 0x248a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_248e:
	/* 0x248e: mov    BYTE PTR [rsi+0x4c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2491:
	/* 0x2491: cmp    r13,0x49 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 73ULL);
x86_l_2495:
	/* 0x2495: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_249b:
	/* 0x249b: lea    eax,[r13+0xfb6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4022ULL);
x86_l_24a2:
	/* 0x24a2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24a7:
	/* 0x24a7: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_24ab:
	/* 0x24ab: mov    BYTE PTR [rsi+0x4d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_24ae:
	/* 0x24ae: cmp    r13,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 74ULL);
x86_l_24b2:
	/* 0x24b2: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_24b8:
	/* 0x24b8: lea    eax,[r13+0xfb5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4021ULL);
x86_l_24bf:
	/* 0x24bf: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24c4:
	/* 0x24c4: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_24c8:
	/* 0x24c8: mov    BYTE PTR [rsi+0x4e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_24cb:
	/* 0x24cb: cmp    r13,0x4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 75ULL);
x86_l_24cf:
	/* 0x24cf: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_24d5:
	/* 0x24d5: lea    eax,[r13+0xfb4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4020ULL);
x86_l_24dc:
	/* 0x24dc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24e1:
	/* 0x24e1: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_24e5:
	/* 0x24e5: mov    BYTE PTR [rsi+0x4f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_24e8:
	/* 0x24e8: cmp    r13,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 76ULL);
x86_l_24ec:
	/* 0x24ec: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_24f2:
	/* 0x24f2: lea    eax,[r13+0xfb3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4019ULL);
x86_l_24f9:
	/* 0x24f9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24fe:
	/* 0x24fe: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2502:
	/* 0x2502: mov    BYTE PTR [rsi+0x50],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2505:
	/* 0x2505: cmp    r13,0x4d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 77ULL);
x86_l_2509:
	/* 0x2509: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_250f:
	/* 0x250f: lea    eax,[r13+0xfb2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4018ULL);
x86_l_2516:
	/* 0x2516: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_251b:
	/* 0x251b: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_251f:
	/* 0x251f: mov    BYTE PTR [rsi+0x51],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81ULL);
x86_l_2522:
	/* 0x2522: cmp    r13,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 78ULL);
x86_l_2526:
	/* 0x2526: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_252c:
	/* 0x252c: lea    eax,[r13+0xfb1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4017ULL);
x86_l_2533:
	/* 0x2533: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2538:
	/* 0x2538: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_253c:
	/* 0x253c: mov    BYTE PTR [rsi+0x52],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_253f:
	/* 0x253f: cmp    r13,0x4f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 79ULL);
x86_l_2543:
	/* 0x2543: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_2549:
	/* 0x2549: lea    eax,[r13+0xfb0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4016ULL);
x86_l_2550:
	/* 0x2550: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2555:
	/* 0x2555: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2559:
	/* 0x2559: mov    BYTE PTR [rsi+0x53],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_255c:
	/* 0x255c: cmp    r13,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 80ULL);
x86_l_2560:
	/* 0x2560: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_2566:
	/* 0x2566: lea    eax,[r13+0xfaf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4015ULL);
x86_l_256d:
	/* 0x256d: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2572:
	/* 0x2572: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2576:
	/* 0x2576: mov    BYTE PTR [rsi+0x54],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_2579:
	/* 0x2579: cmp    r13,0x51 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 81ULL);
x86_l_257d:
	/* 0x257d: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_2583:
	/* 0x2583: lea    eax,[r13+0xfae] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4014ULL);
x86_l_258a:
	/* 0x258a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_258f:
	/* 0x258f: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2593:
	/* 0x2593: mov    BYTE PTR [rsi+0x55],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85ULL);
x86_l_2596:
	/* 0x2596: cmp    r13,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 82ULL);
x86_l_259a:
	/* 0x259a: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_25a0:
	/* 0x25a0: lea    eax,[r13+0xfad] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4013ULL);
x86_l_25a7:
	/* 0x25a7: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25ac:
	/* 0x25ac: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_25b0:
	/* 0x25b0: mov    BYTE PTR [rsi+0x56],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_25b3:
	/* 0x25b3: cmp    r13,0x53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 83ULL);
x86_l_25b7:
	/* 0x25b7: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_25bd:
	/* 0x25bd: lea    eax,[r13+0xfac] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4012ULL);
x86_l_25c4:
	/* 0x25c4: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25c9:
	/* 0x25c9: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_25cd:
	/* 0x25cd: mov    BYTE PTR [rsi+0x57],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_25d0:
	/* 0x25d0: cmp    r13,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 84ULL);
x86_l_25d4:
	/* 0x25d4: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_25da:
	/* 0x25da: lea    eax,[r13+0xfab] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4011ULL);
x86_l_25e1:
	/* 0x25e1: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25e6:
	/* 0x25e6: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_25ea:
	/* 0x25ea: mov    BYTE PTR [rsi+0x58],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_25ed:
	/* 0x25ed: cmp    r13,0x55 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 85ULL);
x86_l_25f1:
	/* 0x25f1: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_25f7:
	/* 0x25f7: lea    eax,[r13+0xfaa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4010ULL);
x86_l_25fe:
	/* 0x25fe: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2603:
	/* 0x2603: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2607:
	/* 0x2607: mov    BYTE PTR [rsi+0x59],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 89ULL);
x86_l_260a:
	/* 0x260a: cmp    r13,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 86ULL);
x86_l_260e:
	/* 0x260e: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_2614:
	/* 0x2614: lea    eax,[r13+0xfa9] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4009ULL);
x86_l_261b:
	/* 0x261b: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2620:
	/* 0x2620: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2624:
	/* 0x2624: mov    BYTE PTR [rsi+0x5a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_2627:
	/* 0x2627: cmp    r13,0x57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 87ULL);
x86_l_262b:
	/* 0x262b: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_2631:
	/* 0x2631: lea    eax,[r13+0xfa8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4008ULL);
x86_l_2638:
	/* 0x2638: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_263d:
	/* 0x263d: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2641:
	/* 0x2641: mov    BYTE PTR [rsi+0x5b],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_2644:
	/* 0x2644: cmp    r13,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 88ULL);
x86_l_2648:
	/* 0x2648: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_264e:
	/* 0x264e: lea    eax,[r13+0xfa7] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4007ULL);
x86_l_2655:
	/* 0x2655: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_265a:
	/* 0x265a: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_265e:
	/* 0x265e: mov    BYTE PTR [rsi+0x5c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_2661:
	/* 0x2661: cmp    r13,0x59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 89ULL);
x86_l_2665:
	/* 0x2665: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_2667:
	/* 0x2667: lea    eax,[r13+0xfa6] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4006ULL);
x86_l_266e:
	/* 0x266e: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2673:
	/* 0x2673: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2677:
	/* 0x2677: mov    BYTE PTR [rsi+0x5d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 93ULL);
x86_l_267a:
	/* 0x267a: cmp    r13,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 90ULL);
x86_l_267e:
	/* 0x267e: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_2680:
	/* 0x2680: lea    eax,[r13+0xfa5] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4005ULL);
x86_l_2687:
	/* 0x2687: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_268c:
	/* 0x268c: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_2690:
	/* 0x2690: mov    BYTE PTR [rsi+0x5e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_2693:
	/* 0x2693: cmp    r13,0x5b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 91ULL);
x86_l_2697:
	/* 0x2697: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_2699:
	/* 0x2699: lea    eax,[r13+0xfa4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4004ULL);
x86_l_26a0:
	/* 0x26a0: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26a5:
	/* 0x26a5: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_26a9:
	/* 0x26a9: mov    BYTE PTR [rsi+0x5f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_26ac:
	/* 0x26ac: cmp    r13d,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 92ULL);
x86_l_26b0:
	/* 0x26b0: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_26b2:
	/* 0x26b2: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_26b5:
	/* 0x26b5: add    eax,0xfa3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4003ULL);
x86_l_26ba:
	/* 0x26ba: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26bf:
	/* 0x26bf: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_26c3:
	/* 0x26c3: mov    BYTE PTR [rsi+0x60],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_26c6:
	/* 0x26c6: cmp    r13d,0x5d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 93ULL);
x86_l_26ca:
	/* 0x26ca: je     26df <generic_retuprobe_filter_arg_2+0x26df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26df;
	}
x86_l_26cc:
	/* 0x26cc: lea    eax,[r13+0xfa2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4002ULL);
x86_l_26d3:
	/* 0x26d3: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_26d8:
	/* 0x26d8: movzx  eax,BYTE PTR [rcx+rax*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RAX, 0, X86_WIDTH_8), 0ULL);
x86_l_26dc:
	/* 0x26dc: mov    BYTE PTR [rsi+0x61],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_26df:
	/* 0x26df: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26e4:
	/* 0x26e4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26e9:
	/* 0x26e9: jmp    3100 <generic_retuprobe_filter_arg_2+0x3100> */
	return 12544ULL;
x86_l_26ee:
	/* 0x26ee: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26f3:
	/* 0x26f3: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26f7:
	/* 0x26f7: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26fa:
	/* 0x26fa: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_26fe:
	/* 0x26fe: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2706:
	/* 0x2706: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_270d:
	/* 0x270d: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2712:
	/* 0x2712: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2717:
	/* 0x2717: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2719:
	/* 0x2719: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_271c:
	/* 0x271c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_271f:
	/* 0x271f: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2722:
	/* 0x2722: je     3111 <generic_retuprobe_filter_arg_2+0x3111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12561ULL;
	}
x86_l_2728:
	/* 0x2728: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_272d:
	/* 0x272d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2730:
	/* 0x2730: je     3111 <generic_retuprobe_filter_arg_2+0x3111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12561ULL;
	}
x86_l_2736:
	/* 0x2736: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_273d:
	/* 0x273d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2742:
	/* 0x2742: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2747:
	/* 0x2747: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2749:
	/* 0x2749: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_274c:
	/* 0x274c: je     310e <generic_retuprobe_filter_arg_2+0x310e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12558ULL;
	}
x86_l_2752:
	/* 0x2752: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2757:
	/* 0x2757: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_275b:
	/* 0x275b: cmp    r13d,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 255ULL);
x86_l_2762:
	/* 0x2762: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_2767:
	/* 0x2767: cmovb  esi,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_276b:
	/* 0x276b: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_2772:
	/* 0x2772: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2774:
	/* 0x2774: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2777:
	/* 0x2777: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_277b:
	/* 0x277b: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_277e:
	/* 0x277e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2783:
	/* 0x2783: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2785:
	/* 0x2785: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_278a:
	/* 0x278a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_278f:
	/* 0x278f: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2792:
	/* 0x2792: jmp    3100 <generic_retuprobe_filter_arg_2+0x3100> */
	return 12544ULL;
x86_l_2797:
	/* 0x2797: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_279a:
	/* 0x279a: je     27ac <generic_retuprobe_filter_arg_2+0x27ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27ac;
	}
x86_l_279c:
	/* 0x279c: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_279f:
	/* 0x279f: jne    31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12754ULL;
	}
x86_l_27a5:
	/* 0x27a5: movzx  edi,WORD PTR [r8+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_27aa:
	/* 0x27aa: jmp    27b1 <generic_retuprobe_filter_arg_2+0x27b1> */
	goto x86_l_27b1;
x86_l_27ac:
	/* 0x27ac: movzx  edi,WORD PTR [r8+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_27b1:
	/* 0x27b1: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27b3:
	/* 0x27b3: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27b6:
	/* 0x27b6: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27b9:
	/* 0x27b9: jmp    2801 <generic_retuprobe_filter_arg_2+0x2801> */
	goto x86_l_2801;
x86_l_27bb:
	/* 0x27bb: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_27be:
	/* 0x27be: je     2c1f <generic_retuprobe_filter_arg_2+0x2c1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11295ULL;
	}
x86_l_27c4:
	/* 0x27c4: cmp    eax,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_27c7:
	/* 0x27c7: jne    31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12754ULL;
	}
x86_l_27cd:
	/* 0x27cd: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_27d0:
	/* 0x27d0: jne    2deb <generic_retuprobe_filter_arg_2+0x2deb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11755ULL;
	}
x86_l_27d6:
	/* 0x27d6: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_27d9:
	/* 0x27d9: jne    2df8 <generic_retuprobe_filter_arg_2+0x2df8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11768ULL;
	}
x86_l_27df:
	/* 0x27df: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27e2:
	/* 0x27e2: jmp    2e07 <generic_retuprobe_filter_arg_2+0x2e07> */
	return 11783ULL;
x86_l_27e7:
	/* 0x27e7: mov    rdx,QWORD PTR [r8+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27eb:
	/* 0x27eb: mov    r9,QWORD PTR [r8+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27ef:
	/* 0x27ef: jmp    27f8 <generic_retuprobe_filter_arg_2+0x27f8> */
	goto x86_l_27f8;
x86_l_27f1:
	/* 0x27f1: mov    rdx,QWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27f4:
	/* 0x27f4: mov    r9,QWORD PTR [r8+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27f8:
	/* 0x27f8: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_27fb:
	/* 0x27fb: shr    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_27ff:
	/* 0x27ff: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2801:
	/* 0x2801: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2804:
	/* 0x2804: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2807:
	/* 0x2807: jg     282b <generic_retuprobe_filter_arg_2+0x282b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_282b;
	}
x86_l_2809:
	/* 0x2809: lea    ecx,[rax-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_280c:
	/* 0x280c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_280f:
	/* 0x280f: jb     2856 <generic_retuprobe_filter_arg_2+0x2856> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2856;
	}
x86_l_2811:
	/* 0x2811: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_2814:
	/* 0x2814: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2817:
	/* 0x2817: jb     28b7 <generic_retuprobe_filter_arg_2+0x28b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_28b7;
	}
x86_l_281d:
	/* 0x281d: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2820:
	/* 0x2820: je     2c24 <generic_retuprobe_filter_arg_2+0x2c24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11300ULL;
	}
x86_l_2826:
	/* 0x2826: jmp    31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	return 12754ULL;
x86_l_282b:
	/* 0x282b: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_282e:
	/* 0x282e: ja     28ab <generic_retuprobe_filter_arg_2+0x28ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_28ab;
	}
x86_l_2830:
	/* 0x2830: mov    ecx,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5242880ULL);
x86_l_2835:
	/* 0x2835: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2838:
	/* 0x2838: jb     29f0 <generic_retuprobe_filter_arg_2+0x29f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_29f0;
	}
x86_l_283e:
	/* 0x283e: mov    ecx,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 10485760ULL);
x86_l_2843:
	/* 0x2843: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2846:
	/* 0x2846: jb     2a04 <generic_retuprobe_filter_arg_2+0x2a04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2a04;
	}
x86_l_284c:
	/* 0x284c: mov    ecx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 50331648ULL);
x86_l_2851:
	/* 0x2851: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2854:
	/* 0x2854: jae    28ab <generic_retuprobe_filter_arg_2+0x28ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_28ab;
	}
x86_l_2856:
	/* 0x2856: movzx  eax,WORD PTR [r8+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_285b:
	/* 0x285b: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_285e:
	/* 0x285e: je     2a18 <generic_retuprobe_filter_arg_2+0x2a18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a18;
	}
x86_l_2864:
	/* 0x2864: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2867:
	/* 0x2867: jne    2aa4 <generic_retuprobe_filter_arg_2+0x2aa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10916ULL;
	}
x86_l_286d:
	/* 0x286d: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_2870:
	/* 0x2870: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_2873:
	/* 0x2873: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2876:
	/* 0x2876: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_287a:
	/* 0x287a: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_2881:
	/* 0x2881: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2886:
	/* 0x2886: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_288b:
	/* 0x288b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_288d:
	/* 0x288d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2890:
	/* 0x2890: je     2c99 <generic_retuprobe_filter_arg_2+0x2c99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11417ULL;
	}
x86_l_2896:
	/* 0x2896: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2899:
	/* 0x2899: mov    DWORD PTR [rsp+0x20],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953504ULL);
x86_l_28a1:
	/* 0x28a1: mov    DWORD PTR [rsp+0x24],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_28a6:
	/* 0x28a6: jmp    2a70 <generic_retuprobe_filter_arg_2+0x2a70> */
	return 10864ULL;
x86_l_28ab:
	/* 0x28ab: add    eax,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_28ae:
	/* 0x28ae: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_28b1:
	/* 0x28b1: jae    31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12754ULL;
	}
x86_l_28b7:
	/* 0x28b7: mov    r13d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_32);
x86_l_28ba:
	/* 0x28ba: movzx  eax,BYTE PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_28be:
	/* 0x28be: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_28c2:
	/* 0x28c2: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_28c9:
	/* 0x28c9: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_28cc:
	/* 0x28cc: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_28d1:
	/* 0x28d1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28d6:
	/* 0x28d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28d8:
	/* 0x28d8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28db:
	/* 0x28db: je     2e44 <generic_retuprobe_filter_arg_2+0x2e44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11844ULL;
	}
x86_l_28e1:
	/* 0x28e1: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_28e4:
	/* 0x28e4: movzx  eax,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_28e8:
	/* 0x28e8: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28ed:
	/* 0x28ed: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28f2:
	/* 0x28f2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28f7:
	/* 0x28f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28f9:
	/* 0x28f9: mov    edx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_28fe:
	/* 0x28fe: jmp    2c67 <generic_retuprobe_filter_arg_2+0x2c67> */
	return 11367ULL;
x86_l_2903:
	/* 0x2903: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2908:
	/* 0x2908: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_290c:
	/* 0x290c: mov    eax,DWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_290f:
	/* 0x290f: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2913:
	/* 0x2913: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_291b:
	/* 0x291b: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_2922:
	/* 0x2922: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2927:
	/* 0x2927: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_292c:
	/* 0x292c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_292e:
	/* 0x292e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2931:
	/* 0x2931: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2937:
	/* 0x2937: je     31b0 <generic_retuprobe_filter_arg_2+0x31b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12720ULL;
	}
x86_l_293d:
	/* 0x293d: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2940:
	/* 0x2940: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2943:
	/* 0x2943: je     31b0 <generic_retuprobe_filter_arg_2+0x31b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12720ULL;
	}
x86_l_2949:
	/* 0x2949: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_2950:
	/* 0x2950: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2955:
	/* 0x2955: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_295a:
	/* 0x295a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_295c:
	/* 0x295c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_295f:
	/* 0x295f: je     31ad <generic_retuprobe_filter_arg_2+0x31ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12717ULL;
	}
x86_l_2965:
	/* 0x2965: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_296a:
	/* 0x296a: cmp    ecx,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 255ULL);
x86_l_2970:
	/* 0x2970: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_2975:
	/* 0x2975: cmovb  esi,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2978:
	/* 0x2978: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_297f:
	/* 0x297f: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2981:
	/* 0x2981: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2984:
	/* 0x2984: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2988:
	/* 0x2988: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_298b:
	/* 0x298b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2990:
	/* 0x2990: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2995:
	/* 0x2995: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2997:
	/* 0x2997: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_299c:
	/* 0x299c: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_299f:
	/* 0x299f: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_29a2:
	/* 0x29a2: jmp    319f <generic_retuprobe_filter_arg_2+0x319f> */
	return 12703ULL;
x86_l_29a7:
	/* 0x29a7: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_29af:
	/* 0x29af: cmp    edx,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_29b5:
	/* 0x29b5: ja     2c17 <generic_retuprobe_filter_arg_2+0x2c17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11287ULL;
	}
x86_l_29bb:
	/* 0x29bb: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29c0:
	/* 0x29c0: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29c4:
	/* 0x29c4: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_29c7:
	/* 0x29c7: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_29cd:
	/* 0x29cd: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_29d0:
	/* 0x29d0: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_29d3:
	/* 0x29d3: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_29d6:
	/* 0x29d6: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_29d8:
	/* 0x29d8: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_29da:
	/* 0x29da: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_29dd:
	/* 0x29dd: je     2e4c <generic_retuprobe_filter_arg_2+0x2e4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11852ULL;
	}
x86_l_29e3:
	/* 0x29e3: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_29e5:
	/* 0x29e5: jne    2e4c <generic_retuprobe_filter_arg_2+0x2e4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11852ULL;
	}
x86_l_29eb:
	/* 0x29eb: jmp    2e63 <generic_retuprobe_filter_arg_2+0x2e63> */
	return 11875ULL;
x86_l_29f0:
	/* 0x29f0: movzx  eax,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_29f3:
	/* 0x29f3: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29f6:
	/* 0x29f6: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_29fb:
	/* 0x29fb: setb   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_B);
x86_l_29ff:
	/* 0x29ff: jmp    31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	return 12754ULL;
x86_l_2a04:
	/* 0x2a04: movzx  eax,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2a07:
	/* 0x2a07: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a0a:
	/* 0x2a0a: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_2a0f:
	/* 0x2a0f: setae  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_AE);
x86_l_2a13:
	/* 0x2a13: jmp    31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	return 12754ULL;
x86_l_2a18:
	/* 0x2a18: mov    QWORD PTR [rsp+0x10],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a1d:
	/* 0x2a1d: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a21:
	/* 0x2a21: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_2a24:
	/* 0x2a24: mov    eax,DWORD PTR [rsi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2a27:
	/* 0x2a27: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2a2b:
	/* 0x2a2b: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_2a32:
	/* 0x2a32: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2a37:
	/* 0x2a37: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a3c:
	/* 0x2a3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a3e:
	/* 0x2a3e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a41:
	/* 0x2a41: je     2c99 <generic_retuprobe_filter_arg_2+0x2c99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11417ULL;
	}
x86_l_2a47:
	/* 0x2a47: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2a4a:
	/* 0x2a4a: mov    DWORD PTR [rsp+0x20],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953600ULL);
x86_l_2a52:
	/* 0x2a52: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a56:
	/* 0x2a56: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
	return 10842ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10842ULL: goto x86_l_2a5a;
	case 10847ULL: goto x86_l_2a5f;
	case 10852ULL: goto x86_l_2a64;
	case 10856ULL: goto x86_l_2a68;
	case 10860ULL: goto x86_l_2a6c;
	case 10864ULL: goto x86_l_2a70;
	case 10869ULL: goto x86_l_2a75;
	case 10874ULL: goto x86_l_2a7a;
	case 10876ULL: goto x86_l_2a7c;
	case 10881ULL: goto x86_l_2a81;
	case 10884ULL: goto x86_l_2a84;
	case 10887ULL: goto x86_l_2a87;
	case 10893ULL: goto x86_l_2a8d;
	case 10896ULL: goto x86_l_2a90;
	case 10899ULL: goto x86_l_2a93;
	case 10901ULL: goto x86_l_2a95;
	case 10904ULL: goto x86_l_2a98;
	case 10907ULL: goto x86_l_2a9b;
	case 10911ULL: goto x86_l_2a9f;
	case 10916ULL: goto x86_l_2aa4;
	case 10918ULL: goto x86_l_2aa6;
	case 10922ULL: goto x86_l_2aaa;
	case 10927ULL: goto x86_l_2aaf;
	case 10930ULL: goto x86_l_2ab2;
	case 10935ULL: goto x86_l_2ab7;
	case 10939ULL: goto x86_l_2abb;
	case 10945ULL: goto x86_l_2ac1;
	case 10948ULL: goto x86_l_2ac4;
	case 10951ULL: goto x86_l_2ac7;
	case 10954ULL: goto x86_l_2aca;
	case 10957ULL: goto x86_l_2acd;
	case 10959ULL: goto x86_l_2acf;
	case 10963ULL: goto x86_l_2ad3;
	case 10969ULL: goto x86_l_2ad9;
	case 10971ULL: goto x86_l_2adb;
	case 10977ULL: goto x86_l_2ae1;
	case 10980ULL: goto x86_l_2ae4;
	case 10985ULL: goto x86_l_2ae9;
	case 10988ULL: goto x86_l_2aec;
	case 10991ULL: goto x86_l_2aef;
	case 10993ULL: goto x86_l_2af1;
	case 10995ULL: goto x86_l_2af3;
	case 10998ULL: goto x86_l_2af6;
	case 11003ULL: goto x86_l_2afb;
	case 11007ULL: goto x86_l_2aff;
	case 11009ULL: goto x86_l_2b01;
	case 11013ULL: goto x86_l_2b05;
	case 11019ULL: goto x86_l_2b0b;
	case 11022ULL: goto x86_l_2b0e;
	case 11024ULL: goto x86_l_2b10;
	case 11028ULL: goto x86_l_2b14;
	case 11033ULL: goto x86_l_2b19;
	case 11038ULL: goto x86_l_2b1e;
	case 11042ULL: goto x86_l_2b22;
	case 11045ULL: goto x86_l_2b25;
	case 11049ULL: goto x86_l_2b29;
	case 11053ULL: goto x86_l_2b2d;
	case 11056ULL: goto x86_l_2b30;
	case 11062ULL: goto x86_l_2b36;
	case 11066ULL: goto x86_l_2b3a;
	case 11073ULL: goto x86_l_2b41;
	case 11078ULL: goto x86_l_2b46;
	case 11083ULL: goto x86_l_2b4b;
	case 11086ULL: goto x86_l_2b4e;
	case 11088ULL: goto x86_l_2b50;
	case 11091ULL: goto x86_l_2b53;
	case 11098ULL: goto x86_l_2b5a;
	case 11103ULL: goto x86_l_2b5f;
	case 11106ULL: goto x86_l_2b62;
	case 11108ULL: goto x86_l_2b64;
	case 11111ULL: goto x86_l_2b67;
	case 11116ULL: goto x86_l_2b6c;
	case 11119ULL: goto x86_l_2b6f;
	case 11125ULL: goto x86_l_2b75;
	case 11128ULL: goto x86_l_2b78;
	case 11132ULL: goto x86_l_2b7c;
	case 11138ULL: goto x86_l_2b82;
	case 11141ULL: goto x86_l_2b85;
	case 11146ULL: goto x86_l_2b8a;
	case 11151ULL: goto x86_l_2b8f;
	case 11154ULL: goto x86_l_2b92;
	case 11158ULL: goto x86_l_2b96;
	case 11163ULL: goto x86_l_2b9b;
	case 11168ULL: goto x86_l_2ba0;
	case 11171ULL: goto x86_l_2ba3;
	case 11173ULL: goto x86_l_2ba5;
	case 11178ULL: goto x86_l_2baa;
	case 11181ULL: goto x86_l_2bad;
	case 11183ULL: goto x86_l_2baf;
	case 11188ULL: goto x86_l_2bb4;
	case 11192ULL: goto x86_l_2bb8;
	case 11195ULL: goto x86_l_2bbb;
	case 11198ULL: goto x86_l_2bbe;
	case 11204ULL: goto x86_l_2bc4;
	case 11209ULL: goto x86_l_2bc9;
	case 11212ULL: goto x86_l_2bcc;
	case 11214ULL: goto x86_l_2bce;
	case 11218ULL: goto x86_l_2bd2;
	case 11222ULL: goto x86_l_2bd6;
	case 11226ULL: goto x86_l_2bda;
	case 11229ULL: goto x86_l_2bdd;
	case 11235ULL: goto x86_l_2be3;
	case 11237ULL: goto x86_l_2be5;
	case 11243ULL: goto x86_l_2beb;
	case 11248ULL: goto x86_l_2bf0;
	case 11254ULL: goto x86_l_2bf6;
	case 11259ULL: goto x86_l_2bfb;
	case 11265ULL: goto x86_l_2c01;
	case 11272ULL: goto x86_l_2c08;
	case 11277ULL: goto x86_l_2c0d;
	case 11282ULL: goto x86_l_2c12;
	case 11287ULL: goto x86_l_2c17;
	case 11290ULL: goto x86_l_2c1a;
	case 11295ULL: goto x86_l_2c1f;
	case 11300ULL: goto x86_l_2c24;
	case 11304ULL: goto x86_l_2c28;
	case 11308ULL: goto x86_l_2c2c;
	case 11315ULL: goto x86_l_2c33;
	case 11318ULL: goto x86_l_2c36;
	case 11323ULL: goto x86_l_2c3b;
	case 11328ULL: goto x86_l_2c40;
	case 11330ULL: goto x86_l_2c42;
	case 11333ULL: goto x86_l_2c45;
	case 11339ULL: goto x86_l_2c4b;
	case 11342ULL: goto x86_l_2c4e;
	case 11346ULL: goto x86_l_2c52;
	case 11351ULL: goto x86_l_2c57;
	case 11356ULL: goto x86_l_2c5c;
	case 11361ULL: goto x86_l_2c61;
	case 11363ULL: goto x86_l_2c63;
	case 11367ULL: goto x86_l_2c67;
	case 11369ULL: goto x86_l_2c69;
	case 11372ULL: goto x86_l_2c6c;
	case 11374ULL: goto x86_l_2c6e;
	case 11379ULL: goto x86_l_2c73;
	case 11382ULL: goto x86_l_2c76;
	case 11384ULL: goto x86_l_2c78;
	case 11387ULL: goto x86_l_2c7b;
	case 11390ULL: goto x86_l_2c7e;
	case 11392ULL: goto x86_l_2c80;
	case 11397ULL: goto x86_l_2c85;
	case 11400ULL: goto x86_l_2c88;
	case 11402ULL: goto x86_l_2c8a;
	case 11405ULL: goto x86_l_2c8d;
	case 11408ULL: goto x86_l_2c90;
	case 11412ULL: goto x86_l_2c94;
	case 11417ULL: goto x86_l_2c99;
	case 11422ULL: goto x86_l_2c9e;
	case 11425ULL: goto x86_l_2ca1;
	case 11428ULL: goto x86_l_2ca4;
	case 11430ULL: goto x86_l_2ca6;
	case 11433ULL: goto x86_l_2ca9;
	case 11436ULL: goto x86_l_2cac;
	case 11440ULL: goto x86_l_2cb0;
	case 11445ULL: goto x86_l_2cb5;
	case 11448ULL: goto x86_l_2cb8;
	case 11451ULL: goto x86_l_2cbb;
	case 11453ULL: goto x86_l_2cbd;
	case 11455ULL: goto x86_l_2cbf;
	case 11458ULL: goto x86_l_2cc2;
	case 11463ULL: goto x86_l_2cc7;
	case 11467ULL: goto x86_l_2ccb;
	case 11469ULL: goto x86_l_2ccd;
	case 11472ULL: goto x86_l_2cd0;
	case 11478ULL: goto x86_l_2cd6;
	case 11481ULL: goto x86_l_2cd9;
	case 11483ULL: goto x86_l_2cdb;
	case 11487ULL: goto x86_l_2cdf;
	case 11492ULL: goto x86_l_2ce4;
	case 11497ULL: goto x86_l_2ce9;
	case 11501ULL: goto x86_l_2ced;
	case 11504ULL: goto x86_l_2cf0;
	case 11508ULL: goto x86_l_2cf4;
	case 11512ULL: goto x86_l_2cf8;
	case 11516ULL: goto x86_l_2cfc;
	case 11519ULL: goto x86_l_2cff;
	case 11525ULL: goto x86_l_2d05;
	case 11532ULL: goto x86_l_2d0c;
	case 11537ULL: goto x86_l_2d11;
	case 11542ULL: goto x86_l_2d16;
	case 11545ULL: goto x86_l_2d19;
	case 11547ULL: goto x86_l_2d1b;
	case 11550ULL: goto x86_l_2d1e;
	case 11557ULL: goto x86_l_2d25;
	case 11562ULL: goto x86_l_2d2a;
	case 11565ULL: goto x86_l_2d2d;
	case 11567ULL: goto x86_l_2d2f;
	case 11570ULL: goto x86_l_2d32;
	case 11575ULL: goto x86_l_2d37;
	case 11578ULL: goto x86_l_2d3a;
	case 11584ULL: goto x86_l_2d40;
	case 11587ULL: goto x86_l_2d43;
	case 11591ULL: goto x86_l_2d47;
	case 11597ULL: goto x86_l_2d4d;
	case 11600ULL: goto x86_l_2d50;
	case 11605ULL: goto x86_l_2d55;
	case 11609ULL: goto x86_l_2d59;
	case 11614ULL: goto x86_l_2d5e;
	case 11619ULL: goto x86_l_2d63;
	case 11622ULL: goto x86_l_2d66;
	case 11626ULL: goto x86_l_2d6a;
	case 11631ULL: goto x86_l_2d6f;
	case 11634ULL: goto x86_l_2d72;
	case 11636ULL: goto x86_l_2d74;
	case 11641ULL: goto x86_l_2d79;
	case 11644ULL: goto x86_l_2d7c;
	case 11646ULL: goto x86_l_2d7e;
	case 11651ULL: goto x86_l_2d83;
	case 11656ULL: goto x86_l_2d88;
	case 11660ULL: goto x86_l_2d8c;
	case 11663ULL: goto x86_l_2d8f;
	case 11665ULL: goto x86_l_2d91;
	case 11671ULL: goto x86_l_2d97;
	case 11676ULL: goto x86_l_2d9c;
	case 11679ULL: goto x86_l_2d9f;
	case 11681ULL: goto x86_l_2da1;
	case 11685ULL: goto x86_l_2da5;
	case 11689ULL: goto x86_l_2da9;
	case 11694ULL: goto x86_l_2dae;
	case 11700ULL: goto x86_l_2db4;
	case 11705ULL: goto x86_l_2db9;
	case 11711ULL: goto x86_l_2dbf;
	case 11716ULL: goto x86_l_2dc4;
	case 11722ULL: goto x86_l_2dca;
	case 11727ULL: goto x86_l_2dcf;
	case 11733ULL: goto x86_l_2dd5;
	case 11740ULL: goto x86_l_2ddc;
	case 11745ULL: goto x86_l_2de1;
	case 11750ULL: goto x86_l_2de6;
	case 11755ULL: goto x86_l_2deb;
	case 11758ULL: goto x86_l_2dee;
	case 11761ULL: goto x86_l_2df1;
	case 11763ULL: goto x86_l_2df3;
	case 11766ULL: goto x86_l_2df6;
	case 11768ULL: goto x86_l_2df8;
	case 11773ULL: goto x86_l_2dfd;
	case 11776ULL: goto x86_l_2e00;
	case 11778ULL: goto x86_l_2e02;
	case 11781ULL: goto x86_l_2e05;
	case 11783ULL: goto x86_l_2e07;
	case 11786ULL: goto x86_l_2e0a;
	case 11790ULL: goto x86_l_2e0e;
	case 11794ULL: goto x86_l_2e12;
	case 11801ULL: goto x86_l_2e19;
	case 11806ULL: goto x86_l_2e1e;
	case 11811ULL: goto x86_l_2e23;
	case 11813ULL: goto x86_l_2e25;
	case 11816ULL: goto x86_l_2e28;
	case 11818ULL: goto x86_l_2e2a;
	case 11821ULL: goto x86_l_2e2d;
	case 11824ULL: goto x86_l_2e30;
	case 11829ULL: goto x86_l_2e35;
	case 11834ULL: goto x86_l_2e3a;
	case 11839ULL: goto x86_l_2e3f;
	case 11844ULL: goto x86_l_2e44;
	case 11847ULL: goto x86_l_2e47;
	case 11852ULL: goto x86_l_2e4c;
	case 11855ULL: goto x86_l_2e4f;
	case 11857ULL: goto x86_l_2e51;
	case 11859ULL: goto x86_l_2e53;
	case 11861ULL: goto x86_l_2e55;
	case 11864ULL: goto x86_l_2e58;
	case 11869ULL: goto x86_l_2e5d;
	case 11873ULL: goto x86_l_2e61;
	case 11875ULL: goto x86_l_2e63;
	case 11878ULL: goto x86_l_2e66;
	case 11884ULL: goto x86_l_2e6c;
	case 11887ULL: goto x86_l_2e6f;
	case 11889ULL: goto x86_l_2e71;
	case 11893ULL: goto x86_l_2e75;
	case 11897ULL: goto x86_l_2e79;
	case 11900ULL: goto x86_l_2e7c;
	case 11904ULL: goto x86_l_2e80;
	case 11908ULL: goto x86_l_2e84;
	case 11912ULL: goto x86_l_2e88;
	case 11915ULL: goto x86_l_2e8b;
	case 11921ULL: goto x86_l_2e91;
	case 11928ULL: goto x86_l_2e98;
	case 11933ULL: goto x86_l_2e9d;
	case 11938ULL: goto x86_l_2ea2;
	case 11941ULL: goto x86_l_2ea5;
	case 11943ULL: goto x86_l_2ea7;
	case 11946ULL: goto x86_l_2eaa;
	case 11953ULL: goto x86_l_2eb1;
	case 11958ULL: goto x86_l_2eb6;
	case 11961ULL: goto x86_l_2eb9;
	case 11963ULL: goto x86_l_2ebb;
	case 11971ULL: goto x86_l_2ec3;
	case 11974ULL: goto x86_l_2ec6;
	case 11979ULL: goto x86_l_2ecb;
	case 11982ULL: goto x86_l_2ece;
	case 11988ULL: goto x86_l_2ed4;
	case 11997ULL: goto x86_l_2edd;
	case 12001ULL: goto x86_l_2ee1;
	case 12007ULL: goto x86_l_2ee7;
	case 12012ULL: goto x86_l_2eec;
	case 12017ULL: goto x86_l_2ef1;
	case 12020ULL: goto x86_l_2ef4;
	case 12024ULL: goto x86_l_2ef8;
	case 12029ULL: goto x86_l_2efd;
	case 12034ULL: goto x86_l_2f02;
	case 12037ULL: goto x86_l_2f05;
	case 12039ULL: goto x86_l_2f07;
	case 12044ULL: goto x86_l_2f0c;
	case 12047ULL: goto x86_l_2f0f;
	case 12049ULL: goto x86_l_2f11;
	case 12054ULL: goto x86_l_2f16;
	case 12059ULL: goto x86_l_2f1b;
	case 12063ULL: goto x86_l_2f1f;
	case 12066ULL: goto x86_l_2f22;
	case 12068ULL: goto x86_l_2f24;
	case 12074ULL: goto x86_l_2f2a;
	case 12079ULL: goto x86_l_2f2f;
	case 12087ULL: goto x86_l_2f37;
	case 12089ULL: goto x86_l_2f39;
	case 12093ULL: goto x86_l_2f3d;
	case 12097ULL: goto x86_l_2f41;
	case 12102ULL: goto x86_l_2f46;
	case 12108ULL: goto x86_l_2f4c;
	case 12113ULL: goto x86_l_2f51;
	case 12119ULL: goto x86_l_2f57;
	case 12124ULL: goto x86_l_2f5c;
	case 12130ULL: goto x86_l_2f62;
	case 12135ULL: goto x86_l_2f67;
	case 12141ULL: goto x86_l_2f6d;
	case 12148ULL: goto x86_l_2f74;
	case 12153ULL: goto x86_l_2f79;
	case 12158ULL: goto x86_l_2f7e;
	case 12163ULL: goto x86_l_2f83;
	case 12166ULL: goto x86_l_2f86;
	case 12172ULL: goto x86_l_2f8c;
	case 12177ULL: goto x86_l_2f91;
	case 12183ULL: goto x86_l_2f97;
	case 12188ULL: goto x86_l_2f9c;
	case 12194ULL: goto x86_l_2fa2;
	case 12201ULL: goto x86_l_2fa9;
	case 12206ULL: goto x86_l_2fae;
	case 12211ULL: goto x86_l_2fb3;
	case 12216ULL: goto x86_l_2fb8;
	case 12219ULL: goto x86_l_2fbb;
	case 12222ULL: goto x86_l_2fbe;
	case 12227ULL: goto x86_l_2fc3;
	case 12232ULL: goto x86_l_2fc8;
	case 12238ULL: goto x86_l_2fce;
	case 12243ULL: goto x86_l_2fd3;
	case 12249ULL: goto x86_l_2fd9;
	case 12254ULL: goto x86_l_2fde;
	case 12260ULL: goto x86_l_2fe4;
	case 12267ULL: goto x86_l_2feb;
	case 12272ULL: goto x86_l_2ff0;
	case 12277ULL: goto x86_l_2ff5;
	case 12282ULL: goto x86_l_2ffa;
	case 12287ULL: goto x86_l_2fff;
	case 12293ULL: goto x86_l_3005;
	case 12298ULL: goto x86_l_300a;
	case 12304ULL: goto x86_l_3010;
	case 12309ULL: goto x86_l_3015;
	case 12315ULL: goto x86_l_301b;
	case 12322ULL: goto x86_l_3022;
	case 12327ULL: goto x86_l_3027;
	case 12332ULL: goto x86_l_302c;
	case 12337ULL: goto x86_l_3031;
	case 12344ULL: goto x86_l_3038;
	case 12349ULL: goto x86_l_303d;
	case 12354ULL: goto x86_l_3042;
	case 12356ULL: goto x86_l_3044;
	case 12363ULL: goto x86_l_304b;
	case 12368ULL: goto x86_l_3050;
	case 12373ULL: goto x86_l_3055;
	case 12375ULL: goto x86_l_3057;
	case 12382ULL: goto x86_l_305e;
	case 12387ULL: goto x86_l_3063;
	case 12392ULL: goto x86_l_3068;
	case 12394ULL: goto x86_l_306a;
	case 12401ULL: goto x86_l_3071;
	case 12406ULL: goto x86_l_3076;
	case 12411ULL: goto x86_l_307b;
	case 12416ULL: goto x86_l_3080;
	case 12418ULL: goto x86_l_3082;
	case 12421ULL: goto x86_l_3085;
	case 12427ULL: goto x86_l_308b;
	case 12430ULL: goto x86_l_308e;
	case 12435ULL: goto x86_l_3093;
	case 12440ULL: goto x86_l_3098;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a5a:
	/* 0x2a5a: mov    DWORD PTR [rsp+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a5f:
	/* 0x2a5f: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a64:
	/* 0x2a64: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2a68:
	/* 0x2a68: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2a6c:
	/* 0x2a6c: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a70:
	/* 0x2a70: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a75:
	/* 0x2a75: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a7a:
	/* 0x2a7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a7c:
	/* 0x2a7c: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2a81:
	/* 0x2a81: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_2a84:
	/* 0x2a84: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2a87:
	/* 0x2a87: jb     2ca6 <generic_retuprobe_filter_arg_2+0x2ca6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2ca6;
	}
x86_l_2a8d:
	/* 0x2a8d: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_2a90:
	/* 0x2a90: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2a93:
	/* 0x2a93: ja     2aa4 <generic_retuprobe_filter_arg_2+0x2aa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2aa4;
	}
x86_l_2a95:
	/* 0x2a95: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a98:
	/* 0x2a98: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_2a9b:
	/* 0x2a9b: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2a9f:
	/* 0x2a9f: jmp    31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	return 12754ULL;
x86_l_2aa4:
	/* 0x2aa4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2aa6:
	/* 0x2aa6: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2aaa:
	/* 0x2aaa: jmp    31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	return 12754ULL;
x86_l_2aaf:
	/* 0x2aaf: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ab2:
	/* 0x2ab2: jmp    3118 <generic_retuprobe_filter_arg_2+0x3118> */
	return 12568ULL;
x86_l_2ab7:
	/* 0x2ab7: movzx  eax,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2abb:
	/* 0x2abb: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2ac1:
	/* 0x2ac1: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_2ac4:
	/* 0x2ac4: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_2ac7:
	/* 0x2ac7: lea    ecx,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_2aca:
	/* 0x2aca: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_2acd:
	/* 0x2acd: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2acf:
	/* 0x2acf: test   r13w,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_16);
x86_l_2ad3:
	/* 0x2ad3: je     2cb5 <generic_retuprobe_filter_arg_2+0x2cb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cb5;
	}
x86_l_2ad9:
	/* 0x2ad9: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2adb:
	/* 0x2adb: jne    2cb5 <generic_retuprobe_filter_arg_2+0x2cb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cb5;
	}
x86_l_2ae1:
	/* 0x2ae1: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_2ae4:
	/* 0x2ae4: jmp    2ccd <generic_retuprobe_filter_arg_2+0x2ccd> */
	goto x86_l_2ccd;
x86_l_2ae9:
	/* 0x2ae9: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2aec:
	/* 0x2aec: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_2aef:
	/* 0x2aef: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2af1:
	/* 0x2af1: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_2af3:
	/* 0x2af3: add    edi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2af6:
	/* 0x2af6: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2afb:
	/* 0x2afb: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2aff:
	/* 0x2aff: ja     2b10 <generic_retuprobe_filter_arg_2+0x2b10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b10;
	}
x86_l_2b01:
	/* 0x2b01: movzx  eax,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2b05:
	/* 0x2b05: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2b0b:
	/* 0x2b0b: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2b0e:
	/* 0x2b0e: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2b10:
	/* 0x2b10: mov    DWORD PTR [rsp+0x4c],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2b14:
	/* 0x2b14: mov    QWORD PTR [rsp+0x38],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b19:
	/* 0x2b19: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b1e:
	/* 0x2b1e: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b22:
	/* 0x2b22: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2b25:
	/* 0x2b25: mov    eax,DWORD PTR [rsi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2b29:
	/* 0x2b29: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b2d:
	/* 0x2b2d: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2b30:
	/* 0x2b30: je     2c17 <generic_retuprobe_filter_arg_2+0x2c17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c17;
	}
x86_l_2b36:
	/* 0x2b36: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b3a:
	/* 0x2b3a: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2b41:
	/* 0x2b41: lea    r12,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b46:
	/* 0x2b46: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b4b:
	/* 0x2b4b: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2b4e:
	/* 0x2b4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b50:
	/* 0x2b50: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2b53:
	/* 0x2b53: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2b5a:
	/* 0x2b5a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b5f:
	/* 0x2b5f: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2b62:
	/* 0x2b62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b64:
	/* 0x2b64: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b67:
	/* 0x2b67: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b6c:
	/* 0x2b6c: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2b6f:
	/* 0x2b6f: je     31b0 <generic_retuprobe_filter_arg_2+0x31b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12720ULL;
	}
x86_l_2b75:
	/* 0x2b75: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b78:
	/* 0x2b78: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b7c:
	/* 0x2b7c: je     31b4 <generic_retuprobe_filter_arg_2+0x31b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12724ULL;
	}
x86_l_2b82:
	/* 0x2b82: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2b85:
	/* 0x2b85: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b8a:
	/* 0x2b8a: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b8f:
	/* 0x2b8f: mov    BYTE PTR [rax],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b92:
	/* 0x2b92: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2b96:
	/* 0x2b96: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b9b:
	/* 0x2b9b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ba0:
	/* 0x2ba0: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2ba3:
	/* 0x2ba3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ba5:
	/* 0x2ba5: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_2baa:
	/* 0x2baa: cmp    esi,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2bad:
	/* 0x2bad: jbe    2bce <generic_retuprobe_filter_arg_2+0x2bce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2bce;
	}
x86_l_2baf:
	/* 0x2baf: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bb4:
	/* 0x2bb4: lea    rdi,[rax+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2bb8:
	/* 0x2bb8: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2bbb:
	/* 0x2bbb: sub    esi,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2bbe:
	/* 0x2bbe: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2bc4:
	/* 0x2bc4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bc9:
	/* 0x2bc9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2bcc:
	/* 0x2bcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bce:
	/* 0x2bce: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2bd2:
	/* 0x2bd2: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2bd6:
	/* 0x2bd6: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bda:
	/* 0x2bda: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2bdd:
	/* 0x2bdd: jg     2f83 <generic_retuprobe_filter_arg_2+0x2f83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2f83;
	}
x86_l_2be3:
	/* 0x2be3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2be5:
	/* 0x2be5: je     3031 <generic_retuprobe_filter_arg_2+0x3031> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3031;
	}
x86_l_2beb:
	/* 0x2beb: cmp    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2bf0:
	/* 0x2bf0: je     3057 <generic_retuprobe_filter_arg_2+0x3057> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3057;
	}
x86_l_2bf6:
	/* 0x2bf6: cmp    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_2bfb:
	/* 0x2bfb: jne    31ad <generic_retuprobe_filter_arg_2+0x31ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12717ULL;
	}
x86_l_2c01:
	/* 0x2c01: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2c08:
	/* 0x2c08: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c0d:
	/* 0x2c0d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c12:
	/* 0x2c12: jmp    307b <generic_retuprobe_filter_arg_2+0x307b> */
	goto x86_l_307b;
x86_l_2c17:
	/* 0x2c17: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c1a:
	/* 0x2c1a: jmp    31b4 <generic_retuprobe_filter_arg_2+0x31b4> */
	return 12724ULL;
x86_l_2c1f:
	/* 0x2c1f: movzx  r12d,WORD PTR [r8+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2c24:
	/* 0x2c24: movzx  eax,BYTE PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2c28:
	/* 0x2c28: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2c2c:
	/* 0x2c2c: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2c33:
	/* 0x2c33: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_2c36:
	/* 0x2c36: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2c3b:
	/* 0x2c3b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c40:
	/* 0x2c40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c42:
	/* 0x2c42: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c45:
	/* 0x2c45: je     2e44 <generic_retuprobe_filter_arg_2+0x2e44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e44;
	}
x86_l_2c4b:
	/* 0x2c4b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2c4e:
	/* 0x2c4e: movzx  eax,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2c52:
	/* 0x2c52: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c57:
	/* 0x2c57: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c5c:
	/* 0x2c5c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c61:
	/* 0x2c61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c63:
	/* 0x2c63: mov    edx,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c67:
	/* 0x2c67: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c69:
	/* 0x2c69: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_2c6c:
	/* 0x2c6c: ja     2c90 <generic_retuprobe_filter_arg_2+0x2c90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2c90;
	}
x86_l_2c6e:
	/* 0x2c6e: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_2c73:
	/* 0x2c73: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2c76:
	/* 0x2c76: jae    2c80 <generic_retuprobe_filter_arg_2+0x2c80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2c80;
	}
x86_l_2c78:
	/* 0x2c78: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c7b:
	/* 0x2c7b: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_2c7e:
	/* 0x2c7e: jmp    2c90 <generic_retuprobe_filter_arg_2+0x2c90> */
	goto x86_l_2c90;
x86_l_2c80:
	/* 0x2c80: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_2c85:
	/* 0x2c85: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2c88:
	/* 0x2c88: jae    2c90 <generic_retuprobe_filter_arg_2+0x2c90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2c90;
	}
x86_l_2c8a:
	/* 0x2c8a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c8d:
	/* 0x2c8d: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_2c90:
	/* 0x2c90: movzx  r12d,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2c94:
	/* 0x2c94: jmp    31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	return 12754ULL;
x86_l_2c99:
	/* 0x2c99: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c9e:
	/* 0x2c9e: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_2ca1:
	/* 0x2ca1: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_2ca4:
	/* 0x2ca4: jmp    2ca9 <generic_retuprobe_filter_arg_2+0x2ca9> */
	goto x86_l_2ca9;
x86_l_2ca6:
	/* 0x2ca6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ca9:
	/* 0x2ca9: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2cac:
	/* 0x2cac: movzx  r12d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2cb0:
	/* 0x2cb0: jmp    31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	return 12754ULL;
x86_l_2cb5:
	/* 0x2cb5: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2cb8:
	/* 0x2cb8: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_2cbb:
	/* 0x2cbb: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2cbd:
	/* 0x2cbd: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2cbf:
	/* 0x2cbf: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2cc2:
	/* 0x2cc2: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2cc7:
	/* 0x2cc7: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2ccb:
	/* 0x2ccb: ja     2cdb <generic_retuprobe_filter_arg_2+0x2cdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2cdb;
	}
x86_l_2ccd:
	/* 0x2ccd: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2cd0:
	/* 0x2cd0: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2cd6:
	/* 0x2cd6: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2cd9:
	/* 0x2cd9: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2cdb:
	/* 0x2cdb: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2cdf:
	/* 0x2cdf: mov    QWORD PTR [rsp+0x38],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ce4:
	/* 0x2ce4: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ce9:
	/* 0x2ce9: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ced:
	/* 0x2ced: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2cf0:
	/* 0x2cf0: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cf4:
	/* 0x2cf4: mov    eax,DWORD PTR [rsi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2cf8:
	/* 0x2cf8: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2cfc:
	/* 0x2cfc: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2cff:
	/* 0x2cff: je     310e <generic_retuprobe_filter_arg_2+0x310e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12558ULL;
	}
x86_l_2d05:
	/* 0x2d05: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2d0c:
	/* 0x2d0c: lea    r12,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d11:
	/* 0x2d11: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d16:
	/* 0x2d16: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2d19:
	/* 0x2d19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d1b:
	/* 0x2d1b: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2d1e:
	/* 0x2d1e: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2d25:
	/* 0x2d25: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d2a:
	/* 0x2d2a: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2d2d:
	/* 0x2d2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d2f:
	/* 0x2d2f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d32:
	/* 0x2d32: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d37:
	/* 0x2d37: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2d3a:
	/* 0x2d3a: je     3111 <generic_retuprobe_filter_arg_2+0x3111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12561ULL;
	}
x86_l_2d40:
	/* 0x2d40: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d43:
	/* 0x2d43: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d47:
	/* 0x2d47: je     3115 <generic_retuprobe_filter_arg_2+0x3115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12565ULL;
	}
x86_l_2d4d:
	/* 0x2d4d: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2d50:
	/* 0x2d50: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d55:
	/* 0x2d55: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2d59:
	/* 0x2d59: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d5e:
	/* 0x2d5e: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d63:
	/* 0x2d63: mov    BYTE PTR [rax],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d66:
	/* 0x2d66: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2d6a:
	/* 0x2d6a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d6f:
	/* 0x2d6f: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2d72:
	/* 0x2d72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d74:
	/* 0x2d74: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_2d79:
	/* 0x2d79: cmp    esi,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2d7c:
	/* 0x2d7c: jbe    2da1 <generic_retuprobe_filter_arg_2+0x2da1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2da1;
	}
x86_l_2d7e:
	/* 0x2d7e: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d83:
	/* 0x2d83: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d88:
	/* 0x2d88: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2d8c:
	/* 0x2d8c: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2d8f:
	/* 0x2d8f: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d91:
	/* 0x2d91: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2d97:
	/* 0x2d97: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d9c:
	/* 0x2d9c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2d9f:
	/* 0x2d9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2da1:
	/* 0x2da1: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2da5:
	/* 0x2da5: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2da9:
	/* 0x2da9: cmp    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_2dae:
	/* 0x2dae: jg     2fc3 <generic_retuprobe_filter_arg_2+0x2fc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2fc3;
	}
x86_l_2db4:
	/* 0x2db4: cmp    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2db9:
	/* 0x2db9: je     309d <generic_retuprobe_filter_arg_2+0x309d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12445ULL;
	}
x86_l_2dbf:
	/* 0x2dbf: cmp    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2dc4:
	/* 0x2dc4: je     30c3 <generic_retuprobe_filter_arg_2+0x30c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12483ULL;
	}
x86_l_2dca:
	/* 0x2dca: cmp    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_2dcf:
	/* 0x2dcf: jne    310e <generic_retuprobe_filter_arg_2+0x310e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12558ULL;
	}
x86_l_2dd5:
	/* 0x2dd5: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2ddc:
	/* 0x2ddc: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2de1:
	/* 0x2de1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2de6:
	/* 0x2de6: jmp    30e7 <generic_retuprobe_filter_arg_2+0x30e7> */
	return 12519ULL;
x86_l_2deb:
	/* 0x2deb: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2dee:
	/* 0x2dee: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2df1:
	/* 0x2df1: jne    2dfd <generic_retuprobe_filter_arg_2+0x2dfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2dfd;
	}
x86_l_2df3:
	/* 0x2df3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2df6:
	/* 0x2df6: je     2dfd <generic_retuprobe_filter_arg_2+0x2dfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dfd;
	}
x86_l_2df8:
	/* 0x2df8: movzx  r12d,BYTE PTR [rdx+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_2dfd:
	/* 0x2dfd: cmp    ecx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 41ULL);
x86_l_2e00:
	/* 0x2e00: je     2e07 <generic_retuprobe_filter_arg_2+0x2e07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e07;
	}
x86_l_2e02:
	/* 0x2e02: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2e05:
	/* 0x2e05: jne    2e44 <generic_retuprobe_filter_arg_2+0x2e44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e44;
	}
x86_l_2e07:
	/* 0x2e07: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_2e0a:
	/* 0x2e0a: movzx  eax,BYTE PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2e0e:
	/* 0x2e0e: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2e12:
	/* 0x2e12: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_2e19:
	/* 0x2e19: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2e1e:
	/* 0x2e1e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e23:
	/* 0x2e23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e25:
	/* 0x2e25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e28:
	/* 0x2e28: je     2e44 <generic_retuprobe_filter_arg_2+0x2e44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e44;
	}
x86_l_2e2a:
	/* 0x2e2a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2e2d:
	/* 0x2e2d: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_2e30:
	/* 0x2e30: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e35:
	/* 0x2e35: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e3a:
	/* 0x2e3a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e3f:
	/* 0x2e3f: jmp    2c61 <generic_retuprobe_filter_arg_2+0x2c61> */
	goto x86_l_2c61;
x86_l_2e44:
	/* 0x2e44: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e47:
	/* 0x2e47: jmp    31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	return 12754ULL;
x86_l_2e4c:
	/* 0x2e4c: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e4f:
	/* 0x2e4f: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2e51:
	/* 0x2e51: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e53:
	/* 0x2e53: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2e55:
	/* 0x2e55: add    edx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_2e58:
	/* 0x2e58: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2e5d:
	/* 0x2e5d: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_2e61:
	/* 0x2e61: ja     2e71 <generic_retuprobe_filter_arg_2+0x2e71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2e71;
	}
x86_l_2e63:
	/* 0x2e63: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e66:
	/* 0x2e66: imul   eax,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_2e6c:
	/* 0x2e6c: shr    eax,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_2e6f:
	/* 0x2e6f: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2e71:
	/* 0x2e71: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2e75:
	/* 0x2e75: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e79:
	/* 0x2e79: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2e7c:
	/* 0x2e7c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e80:
	/* 0x2e80: mov    eax,DWORD PTR [rcx+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_2e84:
	/* 0x2e84: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2e88:
	/* 0x2e88: cmp    eax,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_2e8b:
	/* 0x2e8b: je     31ad <generic_retuprobe_filter_arg_2+0x31ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12717ULL;
	}
x86_l_2e91:
	/* 0x2e91: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_2e98:
	/* 0x2e98: lea    r12,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e9d:
	/* 0x2e9d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ea2:
	/* 0x2ea2: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2ea5:
	/* 0x2ea5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ea7:
	/* 0x2ea7: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2eaa:
	/* 0x2eaa: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2eb1:
	/* 0x2eb1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2eb6:
	/* 0x2eb6: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2eb9:
	/* 0x2eb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ebb:
	/* 0x2ebb: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2ec3:
	/* 0x2ec3: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ec6:
	/* 0x2ec6: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ecb:
	/* 0x2ecb: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2ece:
	/* 0x2ece: je     31b0 <generic_retuprobe_filter_arg_2+0x31b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12720ULL;
	}
x86_l_2ed4:
	/* 0x2ed4: cmp    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_2edd:
	/* 0x2edd: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ee1:
	/* 0x2ee1: je     31b4 <generic_retuprobe_filter_arg_2+0x31b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12724ULL;
	}
x86_l_2ee7:
	/* 0x2ee7: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2eec:
	/* 0x2eec: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ef1:
	/* 0x2ef1: mov    BYTE PTR [rax],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ef4:
	/* 0x2ef4: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2ef8:
	/* 0x2ef8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2efd:
	/* 0x2efd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f02:
	/* 0x2f02: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2f05:
	/* 0x2f05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f07:
	/* 0x2f07: movzx  esi,WORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 76ULL);
x86_l_2f0c:
	/* 0x2f0c: cmp    esi,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2f0f:
	/* 0x2f0f: jbe    2f39 <generic_retuprobe_filter_arg_2+0x2f39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2f39;
	}
x86_l_2f11:
	/* 0x2f11: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f16:
	/* 0x2f16: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f1b:
	/* 0x2f1b: lea    rdi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2f1f:
	/* 0x2f1f: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2f22:
	/* 0x2f22: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f24:
	/* 0x2f24: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2f2a:
	/* 0x2f2a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f2f:
	/* 0x2f2f: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2f37:
	/* 0x2f37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f39:
	/* 0x2f39: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2f3d:
	/* 0x2f3d: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2f41:
	/* 0x2f41: cmp    DWORD PTR [rsp+0x38],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168578ULL);
x86_l_2f46:
	/* 0x2f46: jg     2ffa <generic_retuprobe_filter_arg_2+0x2ffa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2ffa;
	}
x86_l_2f4c:
	/* 0x2f4c: cmp    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2f51:
	/* 0x2f51: je     313c <generic_retuprobe_filter_arg_2+0x313c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12604ULL;
	}
x86_l_2f57:
	/* 0x2f57: cmp    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_2f5c:
	/* 0x2f5c: je     3162 <generic_retuprobe_filter_arg_2+0x3162> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12642ULL;
	}
x86_l_2f62:
	/* 0x2f62: cmp    DWORD PTR [rsp+0x38],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168578ULL);
x86_l_2f67:
	/* 0x2f67: jne    31ad <generic_retuprobe_filter_arg_2+0x31ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12717ULL;
	}
x86_l_2f6d:
	/* 0x2f6d: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_2f74:
	/* 0x2f74: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2f79:
	/* 0x2f79: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f7e:
	/* 0x2f7e: jmp    3186 <generic_retuprobe_filter_arg_2+0x3186> */
	return 12678ULL;
x86_l_2f83:
	/* 0x2f83: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2f86:
	/* 0x2f86: je     3044 <generic_retuprobe_filter_arg_2+0x3044> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3044;
	}
x86_l_2f8c:
	/* 0x2f8c: cmp    DWORD PTR [rsp+0x8],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738372ULL);
x86_l_2f91:
	/* 0x2f91: je     306a <generic_retuprobe_filter_arg_2+0x306a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_306a;
	}
x86_l_2f97:
	/* 0x2f97: cmp    DWORD PTR [rsp+0x8],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738373ULL);
x86_l_2f9c:
	/* 0x2f9c: jne    31ad <generic_retuprobe_filter_arg_2+0x31ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12717ULL;
	}
x86_l_2fa2:
	/* 0x2fa2: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_2fa9:
	/* 0x2fa9: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2fae:
	/* 0x2fae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2fb3:
	/* 0x2fb3: jmp    307b <generic_retuprobe_filter_arg_2+0x307b> */
	goto x86_l_307b;
x86_l_2fb8:
	/* 0x2fb8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fbb:
	/* 0x2fbb: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2fbe:
	/* 0x2fbe: jmp    3115 <generic_retuprobe_filter_arg_2+0x3115> */
	return 12565ULL;
x86_l_2fc3:
	/* 0x2fc3: cmp    DWORD PTR [rsp+0x8],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738371ULL);
x86_l_2fc8:
	/* 0x2fc8: je     30b0 <generic_retuprobe_filter_arg_2+0x30b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12464ULL;
	}
x86_l_2fce:
	/* 0x2fce: cmp    DWORD PTR [rsp+0x8],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738372ULL);
x86_l_2fd3:
	/* 0x2fd3: je     30d6 <generic_retuprobe_filter_arg_2+0x30d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12502ULL;
	}
x86_l_2fd9:
	/* 0x2fd9: cmp    DWORD PTR [rsp+0x8],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738373ULL);
x86_l_2fde:
	/* 0x2fde: jne    310e <generic_retuprobe_filter_arg_2+0x310e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12558ULL;
	}
x86_l_2fe4:
	/* 0x2fe4: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_2feb:
	/* 0x2feb: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2ff0:
	/* 0x2ff0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ff5:
	/* 0x2ff5: jmp    30e7 <generic_retuprobe_filter_arg_2+0x30e7> */
	return 12519ULL;
x86_l_2ffa:
	/* 0x2ffa: cmp    DWORD PTR [rsp+0x38],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168579ULL);
x86_l_2fff:
	/* 0x2fff: je     314f <generic_retuprobe_filter_arg_2+0x314f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12623ULL;
	}
x86_l_3005:
	/* 0x3005: cmp    DWORD PTR [rsp+0x38],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168580ULL);
x86_l_300a:
	/* 0x300a: je     3175 <generic_retuprobe_filter_arg_2+0x3175> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12661ULL;
	}
x86_l_3010:
	/* 0x3010: cmp    DWORD PTR [rsp+0x38],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168581ULL);
x86_l_3015:
	/* 0x3015: jne    31ad <generic_retuprobe_filter_arg_2+0x31ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12717ULL;
	}
x86_l_301b:
	/* 0x301b: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_3022:
	/* 0x3022: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3027:
	/* 0x3027: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_302c:
	/* 0x302c: jmp    3186 <generic_retuprobe_filter_arg_2+0x3186> */
	return 12678ULL;
x86_l_3031:
	/* 0x3031: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_3038:
	/* 0x3038: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_303d:
	/* 0x303d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3042:
	/* 0x3042: jmp    307b <generic_retuprobe_filter_arg_2+0x307b> */
	goto x86_l_307b;
x86_l_3044:
	/* 0x3044: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_304b:
	/* 0x304b: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3050:
	/* 0x3050: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3055:
	/* 0x3055: jmp    307b <generic_retuprobe_filter_arg_2+0x307b> */
	goto x86_l_307b;
x86_l_3057:
	/* 0x3057: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_305e:
	/* 0x305e: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3063:
	/* 0x3063: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3068:
	/* 0x3068: jmp    307b <generic_retuprobe_filter_arg_2+0x307b> */
	goto x86_l_307b;
x86_l_306a:
	/* 0x306a: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_3071:
	/* 0x3071: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3076:
	/* 0x3076: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_307b:
	/* 0x307b: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3080:
	/* 0x3080: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3082:
	/* 0x3082: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3085:
	/* 0x3085: je     31ad <generic_retuprobe_filter_arg_2+0x31ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12717ULL;
	}
x86_l_308b:
	/* 0x308b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_308e:
	/* 0x308e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3093:
	/* 0x3093: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3098:
	/* 0x3098: jmp    319f <generic_retuprobe_filter_arg_2+0x319f> */
	return 12703ULL;
	return 12445ULL;
}

static __noinline __u64 tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12445ULL: goto x86_l_309d;
	case 12452ULL: goto x86_l_30a4;
	case 12457ULL: goto x86_l_30a9;
	case 12462ULL: goto x86_l_30ae;
	case 12464ULL: goto x86_l_30b0;
	case 12471ULL: goto x86_l_30b7;
	case 12476ULL: goto x86_l_30bc;
	case 12481ULL: goto x86_l_30c1;
	case 12483ULL: goto x86_l_30c3;
	case 12490ULL: goto x86_l_30ca;
	case 12495ULL: goto x86_l_30cf;
	case 12500ULL: goto x86_l_30d4;
	case 12502ULL: goto x86_l_30d6;
	case 12509ULL: goto x86_l_30dd;
	case 12514ULL: goto x86_l_30e2;
	case 12519ULL: goto x86_l_30e7;
	case 12524ULL: goto x86_l_30ec;
	case 12526ULL: goto x86_l_30ee;
	case 12529ULL: goto x86_l_30f1;
	case 12531ULL: goto x86_l_30f3;
	case 12534ULL: goto x86_l_30f6;
	case 12539ULL: goto x86_l_30fb;
	case 12544ULL: goto x86_l_3100;
	case 12546ULL: goto x86_l_3102;
	case 12549ULL: goto x86_l_3105;
	case 12552ULL: goto x86_l_3108;
	case 12556ULL: goto x86_l_310c;
	case 12558ULL: goto x86_l_310e;
	case 12561ULL: goto x86_l_3111;
	case 12565ULL: goto x86_l_3115;
	case 12568ULL: goto x86_l_3118;
	case 12571ULL: goto x86_l_311b;
	case 12577ULL: goto x86_l_3121;
	case 12579ULL: goto x86_l_3123;
	case 12589ULL: goto x86_l_312d;
	case 12593ULL: goto x86_l_3131;
	case 12599ULL: goto x86_l_3137;
	case 12604ULL: goto x86_l_313c;
	case 12611ULL: goto x86_l_3143;
	case 12616ULL: goto x86_l_3148;
	case 12621ULL: goto x86_l_314d;
	case 12623ULL: goto x86_l_314f;
	case 12630ULL: goto x86_l_3156;
	case 12635ULL: goto x86_l_315b;
	case 12640ULL: goto x86_l_3160;
	case 12642ULL: goto x86_l_3162;
	case 12649ULL: goto x86_l_3169;
	case 12654ULL: goto x86_l_316e;
	case 12659ULL: goto x86_l_3173;
	case 12661ULL: goto x86_l_3175;
	case 12668ULL: goto x86_l_317c;
	case 12673ULL: goto x86_l_3181;
	case 12678ULL: goto x86_l_3186;
	case 12683ULL: goto x86_l_318b;
	case 12685ULL: goto x86_l_318d;
	case 12688ULL: goto x86_l_3190;
	case 12690ULL: goto x86_l_3192;
	case 12693ULL: goto x86_l_3195;
	case 12698ULL: goto x86_l_319a;
	case 12703ULL: goto x86_l_319f;
	case 12705ULL: goto x86_l_31a1;
	case 12708ULL: goto x86_l_31a4;
	case 12711ULL: goto x86_l_31a7;
	case 12715ULL: goto x86_l_31ab;
	case 12717ULL: goto x86_l_31ad;
	case 12720ULL: goto x86_l_31b0;
	case 12724ULL: goto x86_l_31b4;
	case 12727ULL: goto x86_l_31b7;
	case 12730ULL: goto x86_l_31ba;
	case 12732ULL: goto x86_l_31bc;
	case 12734ULL: goto x86_l_31be;
	case 12744ULL: goto x86_l_31c8;
	case 12748ULL: goto x86_l_31cc;
	case 12750ULL: goto x86_l_31ce;
	case 12754ULL: goto x86_l_31d2;
	case 12757ULL: goto x86_l_31d5;
	case 12759ULL: goto x86_l_31d7;
	case 12763ULL: goto x86_l_31db;
	case 12765ULL: goto x86_l_31dd;
	case 12767ULL: goto x86_l_31df;
	case 12769ULL: goto x86_l_31e1;
	case 12773ULL: goto x86_l_31e5;
	case 12775ULL: goto x86_l_31e7;
	case 12779ULL: goto x86_l_31eb;
	case 12785ULL: goto x86_l_31f1;
	case 12788ULL: goto x86_l_31f4;
	case 12794ULL: goto x86_l_31fa;
	case 12798ULL: goto x86_l_31fe;
	case 12804ULL: goto x86_l_3204;
	case 12806ULL: goto x86_l_3206;
	case 12810ULL: goto x86_l_320a;
	case 12816ULL: goto x86_l_3210;
	case 12820ULL: goto x86_l_3214;
	case 12826ULL: goto x86_l_321a;
	case 12830ULL: goto x86_l_321e;
	case 12836ULL: goto x86_l_3224;
	case 12840ULL: goto x86_l_3228;
	case 12846ULL: goto x86_l_322e;
	case 12849ULL: goto x86_l_3231;
	case 12854ULL: goto x86_l_3236;
	case 12861ULL: goto x86_l_323d;
	case 12868ULL: goto x86_l_3244;
	case 12873ULL: goto x86_l_3249;
	case 12878ULL: goto x86_l_324e;
	case 12881ULL: goto x86_l_3251;
	case 12886ULL: goto x86_l_3256;
	case 12888ULL: goto x86_l_3258;
	case 12895ULL: goto x86_l_325f;
	case 12900ULL: goto x86_l_3264;
	case 12905ULL: goto x86_l_3269;
	case 12908ULL: goto x86_l_326c;
	case 12913ULL: goto x86_l_3271;
	case 12915ULL: goto x86_l_3273;
	case 12917ULL: goto x86_l_3275;
	case 12924ULL: goto x86_l_327c;
	case 12925ULL: goto x86_l_327d;
	case 12927ULL: goto x86_l_327f;
	case 12929ULL: goto x86_l_3281;
	case 12931ULL: goto x86_l_3283;
	case 12933ULL: goto x86_l_3285;
	case 12934ULL: goto x86_l_3286;
	case 12939ULL: goto x86_l_328b;
	case 12942ULL: goto x86_l_328e;
	case 12950ULL: goto x86_l_3296;
	case 12952ULL: goto x86_l_3298;
	case 12958ULL: goto x86_l_329e;
	case 12966ULL: goto x86_l_32a6;
	case 12968ULL: goto x86_l_32a8;
	case 12974ULL: goto x86_l_32ae;
	case 12982ULL: goto x86_l_32b6;
	case 12984ULL: goto x86_l_32b8;
	case 12990ULL: goto x86_l_32be;
	case 12998ULL: goto x86_l_32c6;
	case 13000ULL: goto x86_l_32c8;
	case 13006ULL: goto x86_l_32ce;
	case 13014ULL: goto x86_l_32d6;
	case 13016ULL: goto x86_l_32d8;
	case 13022ULL: goto x86_l_32de;
	case 13030ULL: goto x86_l_32e6;
	case 13032ULL: goto x86_l_32e8;
	case 13039ULL: goto x86_l_32ef;
	case 13046ULL: goto x86_l_32f6;
	case 13051ULL: goto x86_l_32fb;
	case 13056ULL: goto x86_l_3300;
	case 13059ULL: goto x86_l_3303;
	case 13064ULL: goto x86_l_3308;
	case 13066ULL: goto x86_l_330a;
	case 13070ULL: goto x86_l_330e;
	case 13075ULL: goto x86_l_3313;
	case 13077ULL: goto x86_l_3315;
	case 13082ULL: goto x86_l_331a;
	case 13087ULL: goto x86_l_331f;
	case 13094ULL: goto x86_l_3326;
	case 13099ULL: goto x86_l_332b;
	case 13104ULL: goto x86_l_3330;
	case 13106ULL: goto x86_l_3332;
	case 13109ULL: goto x86_l_3335;
	case 13115ULL: goto x86_l_333b;
	case 13122ULL: goto x86_l_3342;
	case 13127ULL: goto x86_l_3347;
	case 13132ULL: goto x86_l_334c;
	case 13134ULL: goto x86_l_334e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_309d:
	/* 0x309d: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_30a4:
	/* 0x30a4: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30a9:
	/* 0x30a9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30ae:
	/* 0x30ae: jmp    30e7 <generic_retuprobe_filter_arg_2+0x30e7> */
	goto x86_l_30e7;
x86_l_30b0:
	/* 0x30b0: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_30b7:
	/* 0x30b7: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30bc:
	/* 0x30bc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30c1:
	/* 0x30c1: jmp    30e7 <generic_retuprobe_filter_arg_2+0x30e7> */
	goto x86_l_30e7;
x86_l_30c3:
	/* 0x30c3: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_30ca:
	/* 0x30ca: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30cf:
	/* 0x30cf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30d4:
	/* 0x30d4: jmp    30e7 <generic_retuprobe_filter_arg_2+0x30e7> */
	goto x86_l_30e7;
x86_l_30d6:
	/* 0x30d6: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_30dd:
	/* 0x30dd: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30e2:
	/* 0x30e2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30e7:
	/* 0x30e7: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30ec:
	/* 0x30ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30ee:
	/* 0x30ee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30f1:
	/* 0x30f1: je     310e <generic_retuprobe_filter_arg_2+0x310e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_310e;
	}
x86_l_30f3:
	/* 0x30f3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_30f6:
	/* 0x30f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30fb:
	/* 0x30fb: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3100:
	/* 0x3100: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3102:
	/* 0x3102: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3105:
	/* 0x3105: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3108:
	/* 0x3108: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_310c:
	/* 0x310c: jmp    3111 <generic_retuprobe_filter_arg_2+0x3111> */
	goto x86_l_3111;
x86_l_310e:
	/* 0x310e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3111:
	/* 0x3111: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3115:
	/* 0x3115: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3118:
	/* 0x3118: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_311b:
	/* 0x311b: ja     31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_31d2;
	}
x86_l_3121:
	/* 0x3121: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3123:
	/* 0x3123: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_312d:
	/* 0x312d: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3131:
	/* 0x3131: jb     31ce <generic_retuprobe_filter_arg_2+0x31ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_31ce;
	}
x86_l_3137:
	/* 0x3137: jmp    31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	goto x86_l_31d2;
x86_l_313c:
	/* 0x313c: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_3143:
	/* 0x3143: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3148:
	/* 0x3148: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_314d:
	/* 0x314d: jmp    3186 <generic_retuprobe_filter_arg_2+0x3186> */
	goto x86_l_3186;
x86_l_314f:
	/* 0x314f: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_3156:
	/* 0x3156: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_315b:
	/* 0x315b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3160:
	/* 0x3160: jmp    3186 <generic_retuprobe_filter_arg_2+0x3186> */
	goto x86_l_3186;
x86_l_3162:
	/* 0x3162: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_3169:
	/* 0x3169: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_316e:
	/* 0x316e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3173:
	/* 0x3173: jmp    3186 <generic_retuprobe_filter_arg_2+0x3186> */
	goto x86_l_3186;
x86_l_3175:
	/* 0x3175: mov    rdi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_317c:
	/* 0x317c: lea    rcx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3181:
	/* 0x3181: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3186:
	/* 0x3186: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_318b:
	/* 0x318b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_318d:
	/* 0x318d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3190:
	/* 0x3190: je     31ad <generic_retuprobe_filter_arg_2+0x31ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31ad;
	}
x86_l_3192:
	/* 0x3192: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3195:
	/* 0x3195: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_319a:
	/* 0x319a: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_319f:
	/* 0x319f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31a1:
	/* 0x31a1: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31a4:
	/* 0x31a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31a7:
	/* 0x31a7: setne  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_NE);
x86_l_31ab:
	/* 0x31ab: jmp    31b0 <generic_retuprobe_filter_arg_2+0x31b0> */
	goto x86_l_31b0;
x86_l_31ad:
	/* 0x31ad: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31b0:
	/* 0x31b0: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31b4:
	/* 0x31b4: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_31b7:
	/* 0x31b7: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_31ba:
	/* 0x31ba: ja     31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_31d2;
	}
x86_l_31bc:
	/* 0x31bc: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31be:
	/* 0x31be: movabs rcx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 137640280144ULL);
x86_l_31c8:
	/* 0x31c8: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_31cc:
	/* 0x31cc: jae    31d2 <generic_retuprobe_filter_arg_2+0x31d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_31d2;
	}
x86_l_31ce:
	/* 0x31ce: xor    r12,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_31d2:
	/* 0x31d2: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_31d5:
	/* 0x31d5: je     31e1 <generic_retuprobe_filter_arg_2+0x31e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31e1;
	}
x86_l_31d7:
	/* 0x31d7: cmp    rbp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 1ULL);
x86_l_31db:
	/* 0x31db: je     3258 <generic_retuprobe_filter_arg_2+0x3258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3258;
	}
x86_l_31dd:
	/* 0x31dd: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_31df:
	/* 0x31df: jne    3236 <generic_retuprobe_filter_arg_2+0x3236> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3236;
	}
x86_l_31e1:
	/* 0x31e1: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_31e5:
	/* 0x31e5: jg     3206 <generic_retuprobe_filter_arg_2+0x3206> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3206;
	}
x86_l_31e7:
	/* 0x31e7: cmp    r15d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4294967295ULL);
x86_l_31eb:
	/* 0x31eb: je     328b <generic_retuprobe_filter_arg_2+0x328b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_328b;
	}
x86_l_31f1:
	/* 0x31f1: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_31f4:
	/* 0x31f4: je     3298 <generic_retuprobe_filter_arg_2+0x3298> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3298;
	}
x86_l_31fa:
	/* 0x31fa: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_31fe:
	/* 0x31fe: je     32a8 <generic_retuprobe_filter_arg_2+0x32a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32a8;
	}
x86_l_3204:
	/* 0x3204: jmp    3224 <generic_retuprobe_filter_arg_2+0x3224> */
	goto x86_l_3224;
x86_l_3206:
	/* 0x3206: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_320a:
	/* 0x320a: je     32b8 <generic_retuprobe_filter_arg_2+0x32b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32b8;
	}
x86_l_3210:
	/* 0x3210: cmp    r15d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3ULL);
x86_l_3214:
	/* 0x3214: je     32c8 <generic_retuprobe_filter_arg_2+0x32c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32c8;
	}
x86_l_321a:
	/* 0x321a: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_321e:
	/* 0x321e: je     32d8 <generic_retuprobe_filter_arg_2+0x32d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32d8;
	}
x86_l_3224:
	/* 0x3224: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_3228:
	/* 0x3228: jg     330a <generic_retuprobe_filter_arg_2+0x330a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_330a;
	}
x86_l_322e:
	/* 0x322e: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3231:
	/* 0x3231: jmp    32e8 <generic_retuprobe_filter_arg_2+0x32e8> */
	goto x86_l_32e8;
x86_l_3236:
	/* 0x3236: mov    DWORD PTR [r14+0x5ef4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24308ULL);
x86_l_323d:
	/* 0x323d: mov    rsi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retuprobe_calls)));
x86_l_3244:
	/* 0x3244: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3249:
	/* 0x3249: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_324e:
	/* 0x324e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3251:
	/* 0x3251: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3256:
	/* 0x3256: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3258:
	/* 0x3258: mov    rsi,QWORD PTR [rip+0x17dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retuprobe_calls)));
x86_l_325f:
	/* 0x325f: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_3264:
	/* 0x3264: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3269:
	/* 0x3269: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_326c:
	/* 0x326c: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3271:
	/* 0x3271: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3273:
	/* 0x3273: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3275:
	/* 0x3275: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_327c:
	/* 0x327c: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_327d:
	/* 0x327d: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_327f:
	/* 0x327f: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_3281:
	/* 0x3281: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3283:
	/* 0x3283: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3285:
	/* 0x3285: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3286:
	/* 0x3286: jmp    3353 <generic_retuprobe_filter_arg_2+0x3353> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_328b:
	/* 0x328b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_328e:
	/* 0x328e: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_3296:
	/* 0x3296: jne    32e8 <generic_retuprobe_filter_arg_2+0x32e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_32e8;
	}
x86_l_3298:
	/* 0x3298: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_329e:
	/* 0x329e: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_32a6:
	/* 0x32a6: jne    32e8 <generic_retuprobe_filter_arg_2+0x32e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_32e8;
	}
x86_l_32a8:
	/* 0x32a8: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_32ae:
	/* 0x32ae: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_32b6:
	/* 0x32b6: jne    32e8 <generic_retuprobe_filter_arg_2+0x32e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_32e8;
	}
x86_l_32b8:
	/* 0x32b8: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_32be:
	/* 0x32be: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_32c6:
	/* 0x32c6: jne    32e8 <generic_retuprobe_filter_arg_2+0x32e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_32e8;
	}
x86_l_32c8:
	/* 0x32c8: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_32ce:
	/* 0x32ce: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_32d6:
	/* 0x32d6: jne    32e8 <generic_retuprobe_filter_arg_2+0x32e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_32e8;
	}
x86_l_32d8:
	/* 0x32d8: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_32de:
	/* 0x32de: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_32e6:
	/* 0x32e6: je     330a <generic_retuprobe_filter_arg_2+0x330a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_330a;
	}
x86_l_32e8:
	/* 0x32e8: mov    DWORD PTR [r14+0x5ef0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24304ULL);
x86_l_32ef:
	/* 0x32ef: mov    rsi,QWORD PTR [rip+0x17d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retuprobe_calls)));
x86_l_32f6:
	/* 0x32f6: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_32fb:
	/* 0x32fb: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3300:
	/* 0x3300: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3303:
	/* 0x3303: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3308:
	/* 0x3308: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_330a:
	/* 0x330a: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_330e:
	/* 0x330e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3313:
	/* 0x3313: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3315:
	/* 0x3315: mov    QWORD PTR [rsp+0x50],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_331a:
	/* 0x331a: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_331f:
	/* 0x331f: mov    rdi,QWORD PTR [rip+0x17d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_3326:
	/* 0x3326: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_332b:
	/* 0x332b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3330:
	/* 0x3330: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3332:
	/* 0x3332: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3335:
	/* 0x3335: je     3273 <generic_retuprobe_filter_arg_2+0x3273> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3273;
	}
x86_l_333b:
	/* 0x333b: mov    rdi,QWORD PTR [rip+0x17d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_3342:
	/* 0x3342: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3347:
	/* 0x3347: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_334c:
	/* 0x334c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_334e:
	/* 0x334e: jmp    3273 <generic_retuprobe_filter_arg_2+0x3273> */
	goto x86_l_3273;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 11400U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1796ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1802ULL && __x86_pc <= 3598ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3602ULL && __x86_pc <= 5471ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5476ULL && __x86_pc <= 7283ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7290ULL && __x86_pc <= 9139ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9146ULL && __x86_pc <= 10838ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10842ULL && __x86_pc <= 12440ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12445ULL && __x86_pc <= 13134ULL)
			__x86_pc = tetragon_bpf_generic_retuprobe_generic_retuprobe_filter_arg_2_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
